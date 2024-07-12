#include <stdio.h>
#include <string.h>
#include "Mcu.h"
#include "Mcu_Drv.h"
#include "Base_Drv.h"
#include "Port_Drv.h"
#include "Uart_Drv.h"
#include "Platform_Drv.h"
#include "Can_Cfg.h"
#include "Can_Hw_Cfg.h"
#include "Can_Irq.h"
#include "Can_Types.h"
#include "motoheader.h"
#include "pid.h"
#include "Adc_Drv.h"
#include "kinematics.h"
#include "Gtm_Hw_Tom.h"
#include "Gtm_Drv_Tom_Cfg.h"
#include "Gtm_Drv.h"
#include "Dio_Drv.h"
#include "Gpt.h"

//#define UART2 2
#define UART1 1
#define UART0 0
#define UART1_BUFF_SIZE 19
#define UART0_BUFF_SIZE 18

#define IO_ADC  0
#define ENC     1

#define SHOOT_COM_LEN 		9
#define SIX_MOTOR_COM_LEN 	19
#define IOADC_INT_TIME_LEN 	9
#define ENC_INT_TIME_LEN 	9
#define IOADC_STATUS_LEN 	19
#define ENC_CUR_STATUS_LEN 	26
#define IDLE_COM_LEN		15

#define SECTION_DTCM_DATA  __attribute__ ((section (".mcal_data_dtcm")))
SECTION_DTCM_DATA uint8_t uart0_buff[UART0_BUFF_SIZE]={0};
SECTION_DTCM_DATA uint16_t AD_data[5] = {0};//AD采样数据
uint16_t adc_offset[5] = {0};//AD补偿数据
uint32_t offset_temp[5] = {0};
uint8_t offset_cnt = 0;
uint32_t count = 0;
uint32_t shoot_count = 0;

uint8_t uart1_buff[UART1_BUFF_SIZE]={0};//串口1接收数组

struct velocity target_velocity;

kinematics_t c_kinematics;
extern int16_t  res_rpm[4];//动力学输出
extern moto_measure_t moto_chassis[3];//获得回传数据
extern  volatile boolean CanIf_bTxFlag;

uint8_t ad_io_data[19] = {0x55,0xAA,0x38,0x0B,0x07,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};//返回AD信息
uint8_t motor_enc_data [27] = {0x55,0xAA,0x38,0x12,0x08,0x60,0x00};//返回码盘信息
uint8_t idle_data [15] = {0x55,0xAA,0x38,0x07,0xFF,0xFF,0x00,0x11,0x45,0x14,0x19,0x19,0x81,0x0A,0x63};//空闲状态

extern int16_t set_spd[6];//设置电机速度
uint16_t short_pwr = 0;
uint16_t set_interval_time[2] = {13,1500};//设置返回信息时间间隔单位毫秒
RC_ctrl_t CtrlData;

void  shoot_task(uint32_t *shoot_count, uint16_t *short_pwr);

void Uart1_callback(uint32_t event)//回调函数
{
    if (event & TT_USART_EVENT_RECEIVE_COMPLETE)
    {
    	Uart_Drv_AsyncReceive(UART1,uart1_buff,UART1_BUFF_SIZE);//接收函数
    }
	if (event & TT_USART_EVENT_SEND_COMPLETE)
	{

	}
}
void Uart0_callback(uint32_t event)//回调函数
{
    if (event & TT_USART_EVENT_RECEIVE_COMPLETE)
    {
    	Uart_Drv_AsyncReceive(UART0,uart0_buff,UART0_BUFF_SIZE);//接收函数
    }
	if (event & TT_USART_EVENT_SEND_COMPLETE)
	{

	}
}

void Gpt_Notification_0(void)
{
	shoot_count++;
	shoot_task(&shoot_count,&short_pwr);
}
void CB1(void)//ADC0回调函数
{
    Adc_Drv_SetDmaTransCount(Adc1Channel_2,1);//设置DMA搬运
    Adc_Drv_SetDmaTransCount(Adc1Channel_3,1);
    Adc_Drv_SetDmaTransCount(Adc1Channel_4,1);
}

void CB2(void)//ADC1回调函数
{
    Adc_Drv_SetDmaTransCount(Adc2Channel_0,1);//设置DMA搬运
    Adc_Drv_SetDmaTransCount(Adc2Channel_1,1);
}


/* 发送回调函数 */
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    CanIf_bTxFlag = TRUE;
    (void)CanTxPduId;
}

/* 接收回调函数 */
void CanIf_RxIndication( const Can_HwType * Mailbox, const PduInfoType * PduInfoPtr)
{
    (void)Mailbox;
    (void)PduInfoPtr;

    switch(Mailbox->CanId)
    {
		case DJMoto1_ID:
		{
			Get_Measure(&moto_chassis[0],PduInfoPtr);//获得电机数据
    		break;
		}
		case DJMoto2_ID:
		{
			Get_Measure(&moto_chassis[1],PduInfoPtr);//获得电机数据
    		break;
		}
		case DJMoto3_ID:
		{
			Get_Measure(&moto_chassis[2],PduInfoPtr);//获得电机数据
    		break;
		}
		case TodeMoto1_ID://拓达电机581
		{
			if(PduInfoPtr->SduDataPtr[0] == 0x43 && PduInfoPtr->SduDataPtr[1] == 0x64 &&
					PduInfoPtr->SduDataPtr[2] == 0x60 && PduInfoPtr->SduDataPtr[3] == 0x00)//电机控制指令
			{
				motor_enc_data[10]= PduInfoPtr->SduDataPtr[4];
				motor_enc_data[9] = PduInfoPtr->SduDataPtr[5];
				motor_enc_data[8] = PduInfoPtr->SduDataPtr[6];
				motor_enc_data[7] = PduInfoPtr->SduDataPtr[7];
			}
			else if(PduInfoPtr->SduDataPtr[0] == 0x4B && PduInfoPtr->SduDataPtr[1] == 0x78 &&
					PduInfoPtr->SduDataPtr[2] == 0x60 && PduInfoPtr->SduDataPtr[3] == 0x00)
			{
				motor_enc_data[12]= PduInfoPtr->SduDataPtr[4];
				motor_enc_data[11] = PduInfoPtr->SduDataPtr[5];
			}
			break;
		}
		case TodeMoto2_ID://拓达电机582
		{
			if(PduInfoPtr->SduDataPtr[0] == 0x43 && PduInfoPtr->SduDataPtr[1] == 0x64 &&
					PduInfoPtr->SduDataPtr[2] == 0x60 && PduInfoPtr->SduDataPtr[3] == 0x00)//电机控制指令
			{
				motor_enc_data[16] = PduInfoPtr->SduDataPtr[4];
				motor_enc_data[15] = PduInfoPtr->SduDataPtr[5];
				motor_enc_data[14] = PduInfoPtr->SduDataPtr[6];
				motor_enc_data[13] = PduInfoPtr->SduDataPtr[7];
			}
			else if(PduInfoPtr->SduDataPtr[0] == 0x4B && PduInfoPtr->SduDataPtr[1] == 0x78 &&
					PduInfoPtr->SduDataPtr[2] == 0x60 && PduInfoPtr->SduDataPtr[3] == 0x00)
			{
				motor_enc_data[18]= PduInfoPtr->SduDataPtr[4];
				motor_enc_data[17] = PduInfoPtr->SduDataPtr[5];
			}
			break;
		}
		case TodeMoto3_ID://电机583
		{
			if(PduInfoPtr->SduDataPtr[0] == 0x43 && PduInfoPtr->SduDataPtr[1] == 0x64 &&
					PduInfoPtr->SduDataPtr[2] == 0x60 && PduInfoPtr->SduDataPtr[3] == 0x00)//电机控制指令
			{
				motor_enc_data[22] = PduInfoPtr->SduDataPtr[4];
				motor_enc_data[21] = PduInfoPtr->SduDataPtr[5];
				motor_enc_data[20] = PduInfoPtr->SduDataPtr[6];
				motor_enc_data[19] = PduInfoPtr->SduDataPtr[7];
			}
			else if(PduInfoPtr->SduDataPtr[0] == 0x4B && PduInfoPtr->SduDataPtr[1] == 0x78 &&
					PduInfoPtr->SduDataPtr[2] == 0x60 && PduInfoPtr->SduDataPtr[3] == 0x00)
			{
				motor_enc_data[24]= PduInfoPtr->SduDataPtr[4];
				motor_enc_data[23] = PduInfoPtr->SduDataPtr[5];
			}
			break;
		}
			break;
    }
}

void Can0_ErrorNotify(void)
{
//	printf("Can0_ErrorNotify\r\n");
}

void Can1_ErrorNotify(void)
{
//	printf("Can5_ErrorNotify\r\n");
}

void Can6_ErrorNotify(void)
{
//	printf("Can6_ErrorNotify\r\n");
}

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode)
{
    (void)ControllerId;
    (void)ControllerMode;
}

/* 设置报文格式： IdType等于TRUE表示Extened ID，反之为standard ID；FdEnable为TRUE表示CAN FD frame，反之为CAN frame*/
Can_PduType Can_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu, boolean IdType, boolean FdEnable)
{
    Can_PduType PduInfo;

	PduInfo.id = id;
	if(IdType == TRUE)
	{
		PduInfo.id |= (1U << 31U);  // Extened ID
	}
	else
	{
		PduInfo.id &= ~(1U << 31U); // standard ID
	}
	if(FdEnable == TRUE)
	{
		PduInfo.id |= (1U << 30U);  // CAN FD frame
	}
	else
	{
		PduInfo.id &= ~(1U << 30U); // CAN frame
	}
    PduInfo.swPduHandle = swPduHandle;
    PduInfo.length = length;
    PduInfo.sdu = sdu;

    return PduInfo;
}


void RemoteDataProcess(void)//处理遥控器发送过来的数据
{
	CtrlData.ch0 = (uart0_buff[0] | (uart0_buff[1] << 8)) & 0x07ff;        //!< Channel 0
	CtrlData.ch1 = ((uart0_buff[1] >> 3) | (uart0_buff[2] << 5)) & 0x07ff; //!< Channel 1
	CtrlData.ch2 = ((uart0_buff[2] >> 6) | (uart0_buff[3] << 2) |          //!< Channel 2
                         (uart0_buff[4] << 10)) &0x07ff;
	CtrlData.ch3 = ((uart0_buff[4] >> 1) | (uart0_buff[5] << 7)) & 0x07ff; //!< Channel 3
	CtrlData.s1 = ((uart0_buff[5] >> 4) & 0x0003);                  //!< Switch left
	CtrlData.s2 = ((uart0_buff[5] >> 4) & 0x000C) >> 2;                       //!< Switch right
	CtrlData.x = uart0_buff[6] | (uart0_buff[7] << 8);                    //!< Mouse X axis
	CtrlData.y = uart0_buff[8] | (uart0_buff[9] << 8);                    //!< Mouse Y axis
	CtrlData.z = uart0_buff[10] | (uart0_buff[11] << 8);                  //!< Mouse Z axis
	CtrlData.press_l = uart0_buff[12];                                  //!< Mouse Left Is Press ?
	CtrlData.press_r = uart0_buff[13];                                  //!< Mouse Right Is Press ?
	CtrlData.v = uart0_buff[14] | (uart0_buff[15] << 8);                    //!< KeyBoard value
	CtrlData.ch4 = uart0_buff[16] | (uart0_buff[17] << 8);                 //NULL
//	printf("CtrlData.ch4 = %d\r\n",CtrlData.ch4);
//	printf("CtrlData.ch0 = %d,CtrlData.ch1 = %d,CtrlData.ch2 = %d,CtrlData.s1 = %d,CtrlData.s2 = %d \r\n",CtrlData.ch0,CtrlData.ch1,CtrlData.ch2,CtrlData.s1,CtrlData.s2);
}


void Receive_buff_verify(void)
{
	uint8_t checksum = 0;//接收到的数据校验和
	RemoteDataProcess();//遥控器数据处理


	if(CtrlData.s2 ==1)	//如果是遥控器控制
	{

		set_spd[0] = res_rpm[0];
		set_spd[1] = res_rpm[1];
		set_spd[2] = res_rpm[2];
		set_spd[3] = 3000;
		set_spd[4] = 3000;
		if((CtrlData.ch1 - 1024)>1)
		{
			set_spd[5]+=10;
		}
		else if((CtrlData.ch1 - 1024)<-1)
		{
			set_spd[5]-=10;
		}
		if((CtrlData.ch4 - 1024)==660)
		{
			short_pwr = 3000;
		}

		memset(uart1_buff, 0,sizeof(uart1_buff));

	}
	/* 电机控制指令 */
	else if(uart1_buff[0] == 0x55 && uart1_buff[1] == 0xAA && uart1_buff[2] == 0x38 && uart1_buff[3] == 0x0C
				&& uart1_buff[4] == 0x08 && uart1_buff[5] == 0x70)//电机控制指令
		{
			for (uint8_t rxIndex = 0;rxIndex < SIX_MOTOR_COM_LEN-1;rxIndex++)
			{
				checksum += uart1_buff[rxIndex];//计算校验和
			}
			if(uart1_buff[SIX_MOTOR_COM_LEN-1] == checksum)
			{

				set_spd[0] = uart1_buff[10]<<8 | uart1_buff[11];//电机3 TODE3
				set_spd[0] /=2;
				set_spd[1] = uart1_buff[8]<<8 | uart1_buff[9];	//电机2 TODE2
				set_spd[1] /=2;
				set_spd[2] = uart1_buff[6]<<8 | uart1_buff[7];	//电机1 TODE1
				set_spd[2] /=2;
				set_spd[3] = uart1_buff[14]<<8 | uart1_buff[15];//电机5 带球右
				set_spd[4] = -(uart1_buff[12]<<8 | uart1_buff[13]);//电机4 带球左
				set_spd[5] = uart1_buff[16]<<8 | uart1_buff[17];//电机6 击杆高度


				for(int i = 0;i <3;i++)
				{
					if((set_spd[i])>4000)
					{
						set_spd[i] = 4000;
					}
					else if((set_spd[i])<-4000)
					{
						set_spd[i] = -4000;
					}
				}
				for(int i = 3;i < 5;i++)
				{
					if((set_spd[i])>6000)
					{
						set_spd[i] = 6000;
					}
					else if((set_spd[i])<-6000)
					{
						set_spd[i] = -6000;
					}
				}
				checksum = 0;
				memset(uart1_buff, 0,sizeof(uart1_buff));
			}

		}
	/* 射门指令 */
	else if(uart1_buff[0] == 0x55 && uart1_buff[1] == 0xAA && uart1_buff[2] == 0x38 && uart1_buff[3] == 0x02
			&& uart1_buff[4] == 0x09 && uart1_buff[5] == 0x70)
	{
		for (uint8_t rxIndex = 0;rxIndex < SHOOT_COM_LEN-1;rxIndex++)
		{
			checksum += uart1_buff[rxIndex];//计算校验和
		}
		if(uart1_buff[SHOOT_COM_LEN-1] == checksum)
		{
			short_pwr  = uart1_buff[6]<<8 | uart1_buff[7];
			checksum = 0;
			memset(uart1_buff, 0,sizeof(uart1_buff));

		}

	}
	/* Encoder回传读取时间间隔设置 */
	else if(uart1_buff[0] == 0x55 && uart1_buff[1] == 0xAA && uart1_buff[2] == 0x38 && uart1_buff[3] == 0x02
			&& uart1_buff[4] == 0x08 && uart1_buff[5] == 0x60 && uart1_buff[6] == 0x00)//电机码盘读取
	{
		for (uint8_t rxIndex = 0;rxIndex < ENC_INT_TIME_LEN-1;rxIndex++)
		{
			checksum += uart1_buff[rxIndex];//计算校验和
		}
		if(uart1_buff[ENC_INT_TIME_LEN-1] == checksum)
		{
			set_interval_time[ENC]  = uart1_buff[6]<<8 | uart1_buff[7];//将收到的数据还原成时间间隔
			checksum = 0;
			memset(uart1_buff, 0,UART1_BUFF_SIZE);
		}

	}
	/* IO/ADC回传时间间隔设置 */
	else if(uart1_buff[0] == 0x55 && uart1_buff[1] == 0xAA && uart1_buff[2] == 0x38 && uart1_buff[3] == 0x02
			&& uart1_buff[4] == 0x07 && uart1_buff[5] == 0x60)//AD/IO读取命令
	{
		for (uint8_t rxIndex = 0;rxIndex < IOADC_INT_TIME_LEN-1;rxIndex++)//0-8
		{
			checksum += uart1_buff[rxIndex];//计算校验和
		}
		if(uart1_buff[IOADC_INT_TIME_LEN-1] == checksum)
		{
			set_interval_time[IO_ADC]  = uart1_buff[6]<<8 | uart1_buff[7];//将收到的数据还原成时间间隔
			checksum = 0;
			memset(uart1_buff, 0,UART1_BUFF_SIZE);
		}

	}
	else//没有收到定义信号
	{
//			Uart_Drv_SyncTransmit(UART1,idle_data,IDLE_COM_LEN);
	}

}

void dj_motor_init(void)
{
	for (int k = 0; k < 1; k++)
	{
		PID_struct_init(&pid_pos[k], POSITION_PID, 1000, 10, 20, 0.01, 0);
	}

	for (int k = 0; k < 1; k++)
	{
		PID_struct_init(&pid_spd[k], POSITION_PID, 10000, 0, 7.5f, 0, 0);
	}

	for(int i=1; i<3; i++)
	{
		PID_struct_init(&pid_spd[i], POSITION_PID, 20000, 20000,
									1.5f,	0.1f,	0.0f	);  //4 motos angular rate closeloop.
	}
}

void dj_remote_init(void)
{
	target_velocity.linear_x  = 0;      //m/s
	target_velocity.linear_y  = 0;      //m/s
	target_velocity.angular_z = 0;      //rad/s
}

void sensor_ch_init(void)
{
	Adc_Drv_ChannelConfig(Adc1Channel_2);//初始化通道
	Adc_Drv_ChannelConfig(Adc1Channel_3);
	Adc_Drv_ChannelConfig(Adc1Channel_4);
	Adc_Drv_ChannelConfig(Adc2Channel_0);
	Adc_Drv_ChannelConfig(Adc2Channel_1);

	//为DMA搬运的ADC数据设置存放地址
	Adc_Drv_SetDmaBuffer(Adc1Channel_2, &AD_data[0]);//AD1
	Adc_Drv_SetDmaBuffer(Adc1Channel_3, &AD_data[1]);
	Adc_Drv_SetDmaBuffer(Adc1Channel_4, &AD_data[2]);
	Adc_Drv_SetDmaBuffer(Adc2Channel_0, &AD_data[3]);//AD2
	Adc_Drv_SetDmaBuffer(Adc2Channel_1, &AD_data[4]);

	Adc_Drv_SetDmaTransCount(Adc1Channel_3,1);

	Adc_Drv_StartConversion(Adc1Channel_2);//ADC开启转换
	Adc_Drv_StartConversion(Adc2Channel_0);
}

void claw_shoot_init(void)
{
    Gtm_Drv_TomChanelEnable(TOM_0_CHANNEL_0,TOM_ON_GLOBAL_TRIGGER,TOM_EN_OUTPUT_ON_GLOBAL_TRIGGER);//使能PWM
    Gtm_Drv_TomChanelEnable(TOM_0_CHANNEL_1,TOM_ON_GLOBAL_TRIGGER,TOM_EN_OUTPUT_ON_GLOBAL_TRIGGER);//使能PWM
//    Gtm_Drv_TomChanelEnable(TOM_0_CHANNEL_2,TOM_ON_GLOBAL_TRIGGER,TOM_EN_OUTPUT_ON_GLOBAL_TRIGGER);//使能PWM
    Gtm_Drv_TomSetHostTrigger(TOM_INSTANCE_0,TOM_TGCNUMBER_0);
}


void shoot_task(uint32_t *shoot_count, uint16_t *short_pwr)
{
    static bool triac_state = false;  // 用于存储三极管当前的状态
    static uint16_t last_short_pwr = 0;  // 用于记录上一次的short_pwr值

    // 检查short_pwr是否发生变化
    if (*short_pwr != last_short_pwr)
    {
        *shoot_count = 0;  // 重置shoot_count
        last_short_pwr = *short_pwr;  // 更新记录的short_pwr值
    }
    if (*short_pwr == 0)
    {
        // 如果short_pwr为0，确保三极管关闭
        if (triac_state)
        {
        	Dio_Drv_WriteChannel(DioMode0_DioChannel4, STD_HIGH);
            triac_state = false;
        }
    }
    else
    {
        // 如果short_pwr不为0，控制三极管导通和关闭
        if (*shoot_count <= *short_pwr)
        {
            // 在达到short_pwr之前，保持三极管导通
            if (!triac_state)
            {
            	Dio_Drv_WriteChannel(DioMode0_DioChannel4, STD_LOW);
                triac_state = true;
            }
        }
        else
        {
            // 超过short_pwr时间后，关闭三极管
            if (triac_state)
            {
            	Dio_Drv_WriteChannel(DioMode0_DioChannel4, STD_HIGH);
                triac_state = false;
                *short_pwr = 0;  // 导通完成后，将short_pwr归零
            }
        }
    }
}

void adc_get_offset(uint8_t *offset_ok_flag, uint16_t *sensor_adc, uint16_t *adc_offset_par)
{
  if (*offset_ok_flag == 0)
  {
    if (offset_cnt == 0)
    {
      offset_temp[0] = (uint32_t)sensor_adc[0];
      offset_temp[1] = (uint32_t)sensor_adc[1];
      offset_temp[2] = (uint32_t)sensor_adc[2];
      offset_temp[3] = (uint32_t)sensor_adc[3];
      offset_temp[4] = (uint32_t)sensor_adc[4];
    }
    else if (offset_cnt == 127)
    {
      offset_temp[0] += (uint32_t)sensor_adc[0];
      offset_temp[1] += (uint32_t)sensor_adc[1];
      offset_temp[2] += (uint32_t)sensor_adc[2];
      offset_temp[3] += (uint32_t)sensor_adc[3];
      offset_temp[4] += (uint32_t)sensor_adc[4];

      adc_offset_par[0] = offset_temp[0] >> 7;
      adc_offset_par[1] = offset_temp[1] >> 7;
      adc_offset_par[2] = offset_temp[2] >> 7;
      adc_offset_par[3] = offset_temp[3] >> 7;
      adc_offset_par[4] = offset_temp[4] >> 7;

      offset_cnt = 0;
      memset(offset_temp, 0,sizeof(offset_temp));
      *offset_ok_flag = 1;
    }
    else
    {
      offset_temp[0] += (uint32_t)sensor_adc[0];
      offset_temp[1] += (uint32_t)sensor_adc[1];
      offset_temp[2] += (uint32_t)sensor_adc[2];
      offset_temp[3] += (uint32_t)sensor_adc[3];
      offset_temp[4] += (uint32_t)sensor_adc[4];
    }
    offset_cnt++;
  }
}


int main(void)
{
	uint8_t checksum = 0;
	uint8_t have_disabled = 0;
	uint8_t Disable_switch = 0;
	uint32_t io_status = 0;
	uint32_t count = 0;
	uint32_t shoot_count = 0;
	uint8_t key_flag = 1;
	int16_t real_adc[5] = {0};


	Mcu_Init(NULL_PTR);
#if (MCU_INIT_CLOCK == STD_ON)
	Mcu_InitClock(0);
#endif
#if (MCU_NO_PLL == STD_OFF)
	Mcu_DistributePllClock();
#endif
	Base_Drv_Init();
	Uart_Drv_Init(NULL_PTR);
	Port_Drv_Init(&Port_ConfigData);
	Platform_Drv_Init(NULL_PTR);
	Gtm_Drv_Init(NULL_PTR);
	Adc_Drv_Init(NULL_PTR);
    Can_Drv_Init(NULL_PTR);
    Uart_Drv_AsyncReceive(1,uart1_buff,UART1_BUFF_SIZE);//配置UART1接收
	Uart_Drv_AsyncReceive(0,uart0_buff,UART0_BUFF_SIZE);//配置UART0接收
	Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_SYSTEM, &count);
	Dio_Drv_WriteChannel(DioMode0_DioChannel4, STD_HIGH);

    Gpt_Init(NULL_PTR);
    Gpt_EnableNotification(0);
    /* Open Gpt timer FTM5, Set timer cycle 7200->60us*/
    Gpt_StartTimer(0,120);

	sensor_ch_init();
	dj_motor_init();	//M3508-CAN1-J14
	dj_remote_init();
	tode_moto_init();	//TODE-CAN2-J15
	tode_moto_init_re();
	claw_shoot_init();
	memset(uart1_buff, 0,UART1_BUFF_SIZE);
	memset(uart0_buff, 0,UART0_BUFF_SIZE);
//	Iinialize Kinematics
	kinematics_create(c_kinematics,THREE, WHEEL_DIST_X, WHEEL_DIST_Y, WHEEL_RADIUS);
	printf("Launch complete Frequency of processor %dMHZ\r\n", count / 1000 / 1000);
	count=0;

	while(1)
	{
		count++;
		int32_t timeout = 0xFFFFF;
		Base_Drv_Msdelay(1);

		Dio_Drv_ReadChannelGroup(&Dio_GlobalData.Config->DioChannelGroupConfigData[0],&io_status);
		if((io_status & 0x0F) > 0 )
		{
			if(count%80 == 0 && (io_status == 0x08) )//KEY3 消抖GPIOC47
			{
				key_flag = 0;
			}
		}

		Dio_Drv_ReadChannel(DioMode0_DioChannel5,&Disable_switch);
		if((Disable_switch & 0x0F) > 0 )
		{
			if(count%80 == 0 && (Disable_switch == 0x01) && have_disabled == 1)//KEY5 消抖GPIOC57
			{
				key_flag = 0;
				Clear_Error_Tode_Motor();
				Enable_Tode_Motor();
				have_disabled = 0;
				(void)Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_UART0);
				(void)Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_UART1);

			}
		}
		else
		{
			have_disabled = 1;
			Disable_Tode_Motor();
			set_spd[3] = 0;
			set_spd[4] = 0;
			(void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_UART0);
			(void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_UART1);
		}

		if(count%10 == 0)//每隔10ms处理一次接收数据并设置电机速度
		{
	    	Receive_buff_verify();
			Set_Moto_Spd();
		}
		if(count%15 == 0)//每隔15ms开启一次ADC采样
		{
		    Adc_Drv_StartConversion(Adc1Channel_2);//ADC1开启转换
		    Adc_Drv_StartConversion(Adc2Channel_0);//ADC2开启转换
		   // send_motor_data();//发送指令要求电机返回位置和电流信息
		}
		if(count%set_interval_time[IO_ADC] == 0)//当时间到达设定发送信息时间
		{
			real_adc[0] = (int16_t)AD_data[0];
			real_adc[1] = (int16_t)AD_data[1];
			real_adc[2] = (int16_t)AD_data[2];
			real_adc[3] = (int16_t)AD_data[3];
			real_adc[4] = (int16_t)AD_data[4];

			ad_io_data[7]  = (real_adc[0]&0xFF00)>>8;
			ad_io_data[8]  = real_adc[0]&0x00FF;

			ad_io_data[9]  = (real_adc[1]&0xFF00)>>8;
			ad_io_data[10] = real_adc[1]&0x00FF;

			ad_io_data[11] = (real_adc[2]&0xFF00)>>8;
			ad_io_data[12] = real_adc[2]&0x00FF;

			ad_io_data[13] = (real_adc[3]&0xFF00)>>8;
			ad_io_data[14] = real_adc[3]&0x00FF;

			ad_io_data[15] = (real_adc[4]&0xFF00)>>8;
			ad_io_data[16] = real_adc[4]&0x00FF;

			ad_io_data[17] = io_status;

			for(int i=0;i<IOADC_STATUS_LEN-1;i++)
			{
				checksum=ad_io_data[i]+checksum;//计算校验和
			}

			ad_io_data[IOADC_STATUS_LEN-1] = checksum;//将校验和输入到对应数组位置
			checksum=0;
//			printf("ADC    =%d %d  \r\n", real_adc[0],real_adc[3]);//real_adc[0]为AD1，real_adc[3]为AD2
//			printf("OFSTADC=%d %d %d %d %d \r\n", real_adc[0],real_adc[1],real_adc[2],real_adc[3],real_adc[4]);
			Uart_Drv_SyncTransmit(UART1,ad_io_data,IOADC_STATUS_LEN);//发送AD采样信息
		}

//		if(count%set_interval_time[ENC] == 0)
//		{
//			for(int i=0;i<ENC_CUR_STATUS_LEN-1;i++)
//			{
//				checksum=motor_enc_data[i]+checksum;//计算校验和
//			}
//			motor_enc_data[ENC_CUR_STATUS_LEN-1] = checksum;//将校验和输到对应数组位置
//			checksum=0;
//			Uart_Drv_SyncTransmit(UART1,motor_enc_data,ENC_CUR_STATUS_LEN);//发送码盘信息
//		}

	}

}

