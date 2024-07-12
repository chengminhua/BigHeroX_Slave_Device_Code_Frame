/*
 * motor.c
 *
 *  Created on: 2024年2月20日
 *      Author: Administrator
 */
#include "Can_Cfg.h"
#include "Can_Hw_Cfg.h"
#include "Can_Irq.h"
#include "Can_Types.h"
#include "motoheader.h"
#include "pid.h"
#include "Base_Drv.h"
#include "Mcu_Hw_Misc.h"
#include "Gtm_Hw_Tom.h"
#include "Gtm_Drv_Tom_Cfg.h"
#include "Gtm_Drv.h"

volatile boolean CanIf_bTxFlag = FALSE;
uint8_t Tode_Cln_Moto[8] = {0x2B,0x40,0x60,0x00,0x08,0x00,0x00,0x00};//清除错误
uint8_t Tode_Disable_Moto[8] = {0x2B,0x40,0x60,0x00,0x06,0x00,0x00,0x00};
uint8_t Tode_Enter_Spd_mode[8] = {0x2F,0x60,0x60,0x00,0x03,0x00,0x00,0x00}; //进入速度模式
uint8_t Tode_Ctl_Spd[8] = {0x23,0xFF,0x60,0x00,0x00,0x00,0x00,0x00}; //控制速度0
uint8_t Tode_Ctr_Acc[8] = {0x23,0x83,0x60,0x00,0xEB,0xE3,0xDC,0x19}; //加速度200000 0xEB,0xE3,0xDC,0x19
uint8_t Tode_Ctr_Dece[8] = {0x23,0x84,0x60,0x00,0xEB,0xE3,0xDC,0x19}; //减速度200000
uint8_t Tode_Max_Ctr_Spd[8] = {0x23,0x7F,0x60,0x00,0x55,0x55,0x85,0x00}; //最大速度3000
uint8_t Tode_Enable_Moto[8] = {0x2B,0x40,0x60,0x00,0x0F,0x00,0x00,0x00};
uint8_t Tode_Query_current[8] = {0x40,0x78,0x60,0x00,0x00,0x00,0x00,0x00};//查询电流
uint8_t Tode_Query_Location[8] = {0x40,0x64,0x60,0x00,0x00,0x00,0x00,0x00};//查询位置

moto_measure_t moto_chassis[3] = {0};//大疆电机回传信息

CAN_HandleTypeDef can1;
Can_PduType Can_PduInfo3;
Can_PduType Can_PduInfo4;

int16_t res_rpm[4]= {0};

int16_t set_spd[6]={0,0,0,0,0,0};//设置电机速度，0/1/2为拓达电机，3-4为杰美康,5为大疆电机

extern kinematics_t c_kinematics;
extern RC_ctrl_t CtrlData;
extern struct velocity target_velocity;

void Disable_Tode_Motor(void)
{
	int32_t timeout = 0xFFFFF;

	for(int j = 1; j<4; j++) //失能拓达电机
	{
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Disable_Moto, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Disable Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
	}
}

void Enable_Tode_Motor(void)
{
	int32_t timeout = 0xFFFFF;

	for(int j = 1; j<4; j++)//使能拓达电机
	{
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Enable_Moto, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("AN Set Enable Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
	}
}

void Clear_Error_Tode_Motor(void)
{
	int32_t timeout = 0xFFFFF;

	for(int j = 1; j<4; j++)//清除拓达电机错误
	{
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Cln_Moto, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("AN Set Enable Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
	}
}

void tode_moto_init_re(void)//初始化拓达电机一共发送8条指令
{
	int32_t timeout = 0xFFFFF;


	for(int j = 1 ;j<4 ;j++)
	{
		//清除拓达电机报错
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Cln_Moto, FALSE, FALSE);//创建消息

		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Clear Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
//		Base_Drv_Msdelay(100);

		//失能拓达电机
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Disable_Moto, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Disable Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
//		Base_Drv_Msdelay(100);

		//拓达电机进入速度模式
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Enter_Spd_mode, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("Into SpdMode Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
//		Base_Drv_Msdelay(100);

		//拓达电机设置目标速度
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Ctl_Spd, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Set Target Speed Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
//		Base_Drv_Msdelay(100);

		/*uint8_t Tode_Ctr_Acc[8] = {0x23,0x83,0x60,0x00,0x55,0x55,0x21,0x00}; //加速度1000
uint8_t Tode_Ctr_Dece[8] = {0x23,0x84,0x60,0x00,0x55,0x55,0x21,0x00}; //减速度1000*/

		//拓达电机设置轮廓加速度
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Ctr_Acc, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Set Target Acc Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
//		Base_Drv_Msdelay(100);

		//拓达电机设置轮廓减速度
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j,0U, 8U, Tode_Ctr_Dece, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Set Target Dec Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
//		Base_Drv_Msdelay(100);

		//拓达电机设置最大轮廓速度
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Max_Ctr_Spd, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Set MaxSpd Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
//		Base_Drv_Msdelay(100);

		//拓达电机使能
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Enable_Moto, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("AN Set Enable Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
//		Base_Drv_Msdelay(100);
	}
}

void tode_moto_init(void)//初始化拓达电机一共发送8条指令
{
	int32_t timeout = 0xFFFFF;


	for(int j = 1 ;j<4 ;j++)
	{
		//清除拓达电机报错
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Cln_Moto, FALSE, FALSE);//创建消息

		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Clear Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Base_Drv_Msdelay(100);

		//失能拓达电机
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Disable_Moto, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Disable Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Base_Drv_Msdelay(100);

		//拓达电机进入速度模式
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Enter_Spd_mode, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("Into SpdMode Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Base_Drv_Msdelay(100);

		//拓达电机设置目标速度
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Ctl_Spd, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Set Target Speed Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Base_Drv_Msdelay(100);

		//拓达电机设置轮廓加速度
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Ctr_Acc, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Set Target Acc Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Base_Drv_Msdelay(100);

		//拓达电机设置轮廓减速度
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j,0U, 8U, Tode_Ctr_Dece, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Set Target Dec Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Base_Drv_Msdelay(100);

		//拓达电机设置最大轮廓速度
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Max_Ctr_Spd, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("CAN Set MaxSpd Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Base_Drv_Msdelay(100);

		//拓达电机使能
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Enable_Moto, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("AN Set Enable Fail\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Base_Drv_Msdelay(100);
	}
}

void Set_TodeMotor_Spd(void)
{
	uint16_t timeout = 0xFFFF;
	int32_t spd_Data = 0 ;
	int32_t DT7_LX, DT7_LY, DT7_RX, DT7_RY;
	int32_t RC_Velocity = 1500; //设置遥控的速度和位置值
	int32_t thresholdValue = 3; //DT7控制防抖阈值

	kinematics_get_rpm(*c_kinematics,target_velocity,res_rpm);
//	memset(uart0_buff, 0,UART0_BUFF_SIZE);
	DT7_LX= CtrlData.ch2 - 1024;//获取偏差
	DT7_LY= CtrlData.ch3 - 1024;//获取偏差
	DT7_RX= CtrlData.ch0 - 1024;//获取偏差
//	DT7_RY= CtrlData.ch1 - 1024;


	(void)DT7_RY;

	if(DT7_LX>-thresholdValue&&DT7_LX<thresholdValue)DT7_LX=0; //设置小角度的死区
	if(DT7_LY>-thresholdValue&&DT7_LY<thresholdValue)DT7_LY=0; //设置小角度的死区
	if(DT7_RX>-thresholdValue&&DT7_RX<thresholdValue)DT7_RX=0; //设置小角度的死区

	target_velocity.linear_x	=  (float)DT7_LX*RC_Velocity/2400;
	target_velocity.linear_y	=  (float)DT7_LY*RC_Velocity/2400;
	target_velocity.angular_z	=	-(float)DT7_RX*RC_Velocity/800;

//	if((set_spd[0]==0)&&(set_spd[1]==0)&&(set_spd[2]==0))
//	{
//
//		for(int j = 1; j<4; j++)
//		{
//			//失能拓达电机
//			Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Disable_Moto, FALSE, FALSE);//创建消息
//			if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
//			{
//				printf("CAN Disable Fail\r\n");
//				Mcu_Hw_Misc_PerformReset();
//				return ;
//			}
//			while(!CanIf_bTxFlag)	//等待发送完成
//			{
//				Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
//				timeout--;
//				if(timeout<0)
//				{
//					break;
//				}
//			}
//			CanIf_bTxFlag = 0;
//		}
//
//	}
//	else
//	{
//		for(int j = 1; j<4; j++)
//		{
//		//拓达电机使能
//			Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Enable_Moto, FALSE, FALSE);//创建消息
//			if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
//			{
//				printf("CAN Enable Fail\r\n");
//				Mcu_Hw_Misc_PerformReset();
//				return ;
//			}
//			while(!CanIf_bTxFlag)	//等待发送完成
//			{
//				Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
//				timeout--;
//				if(timeout<0)
//				{
//					break;
//				}
//			}
//			CanIf_bTxFlag = 0;
//		}
//	}

	for(int i = 1; i<4; i++)//如果改了顺序不要动
	{

		spd_Data = set_spd [i-1]*0x20000/0x3c;//将速度换算成需要真实填入的值
		Tode_Ctl_Spd[7] = spd_Data >> 24;
		Tode_Ctl_Spd[6] = spd_Data >> 16;
		Tode_Ctl_Spd[5] = (spd_Data >> 8) & 0xff;
		Tode_Ctl_Spd[4] = spd_Data & 0xff;
//		printf("Tode_Ctl_Spd[4] = %d,Tode_Ctl_Spd[5] = %d,Tode_Ctl_Spd[6] = %d,Tode_Ctl_Spd[6] = %d \r\n",Tode_Ctl_Spd[4],Tode_Ctl_Spd[5],Tode_Ctl_Spd[6],Tode_Ctl_Spd[7]);

		Can_PduInfo3 = Can_CreatePduInfo(0x600+i, 0U, 8U, Tode_Ctl_Spd, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("SSF\r\n");
			Mcu_Hw_Misc_PerformReset();
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
	}

}


void Set_DJmoto_Spd(CAN_HandleTypeDef* CanConfig, sint16 iq1, sint16 iq2,sint16 iq3)
{
	uint16_t timeout = 0xFFFF;
	CanConfig->pTxMsg->Data[0] = iq1 >> 8;
	CanConfig->pTxMsg->Data[1] = iq1;
	CanConfig->pTxMsg->Data[2] = iq2 >> 8;
	CanConfig->pTxMsg->Data[3] = iq2;
	CanConfig->pTxMsg->Data[4] = iq3 >> 8;
	CanConfig->pTxMsg->Data[5] = iq3;
	CanConfig->pTxMsg->Data[6] = 0;
	CanConfig->pTxMsg->Data[7] = 0;

	Can_PduInfo4 = Can_CreatePduInfo(0x200, 0U, 8U, CanConfig->pTxMsg->Data, FALSE, FALSE);//创建消息

	if (E_OK != Can_Drv_Write(CanHardwareObject4, &Can_PduInfo4))	//发送消息，CanHardwareObject1指发送消息的邮箱
	{
		printf("Fail Can_Drv_Write1\r\n");
		return ;
	}

	while(!CanIf_bTxFlag)	//等待发送完成
	{
		timeout--;
		if(timeout<0)
		{
			break;
		}
	}
	CanIf_bTxFlag = 0;

}

void set_pwmch1_frequency(uint32 frequency)
{
	/* default frequency is 120M÷3000+3000=20KHz */
	uint32 period;
	if(frequency)
	{
		period =  120000000ul / frequency /2;
	}
	else
	{
		period = 0;
	}
	Gtm_Hw_Tom_SetCounterSr0(TOM_0_CHANNEL_0, period);
	Gtm_Hw_Tom_SetCounterSr1(TOM_0_CHANNEL_0, (period/2));
}
void set_pwmch2_frequency(uint32 frequency)
{
	/* default frequency is 120M÷3000+3000=20KHz */
	uint32 period;
	if(frequency)
	{
		period =  120000000ul / frequency /2;
	}
	else
	{
		period = 0;
	}
	Gtm_Hw_Tom_SetCounterSr0(TOM_0_CHANNEL_1, period);
	Gtm_Hw_Tom_SetCounterSr1(TOM_0_CHANNEL_1, (period/2));
}

void Set_justmotion_Spd(int16_t left,int16_t right)
{
	uint32_t real_claw[2]= {0};
	if(left>3000)
	{
		left=3000;
	}
	else if(left<3000)
	{
		left = 0;
	}

	if(right>3000)
	{
		right=3000;
	}
	else if(right<3000)
	{
		right = 0;
	}
	real_claw[0] = 150000*left /3000;
	real_claw[1] = 150000*right/3000;

	set_pwmch1_frequency(real_claw[0]);
	set_pwmch2_frequency(real_claw[1]);
}

void Set_Moto_Spd(void)//设置电机速度
{
	int16_t ref_agle0;
	for(int k=0; k<1; k++)
	{
		ref_agle0 = set_spd[5];
		pid_calc(&pid_pos[k],moto_chassis[k].total_angle/100,ref_agle0);
		pid_calc(&pid_spd[k], moto_chassis[k].speed_rpm, pid_pos[k].pos_out);//PID算法，根据电机当前状态调整输出
	}

//	printf("agle = %d\r\n",moto_chassis[0].total_angle/100);

	for(int k=1; k<3; k++)
	{
		pid_calc(&pid_spd[k], moto_chassis[k].speed_rpm, set_spd[k+2]);
//		printf("spd = %d ,rl_spd = %d \r\n",moto_chassis[k].speed_rpm,set_spd[k+2]);
		set_spd[4] = set_spd[4]*-1;//左
	}


	Set_DJmoto_Spd(&can1,pid_spd[0].pos_out,pid_spd[1].pos_out,pid_spd[2].pos_out);//设置电机速度
	Set_TodeMotor_Spd();//设置速度

//	memset(set_spd, 0,sizeof(set_spd));
}

void Get_Measure(moto_measure_t *ptr, const PduInfoType * PduInfoPtr)//处理收到上传的电机信息
{

	ptr->last_angle = ptr->angle;
	ptr->angle = (uint16_t)(PduInfoPtr->SduDataPtr[0]<<8 | PduInfoPtr->SduDataPtr[1]) ;
	ptr->real_current  = (int16_t)(PduInfoPtr->SduDataPtr[2]<<8 | PduInfoPtr->SduDataPtr[3]);
	ptr->speed_rpm = ptr->real_current;	//转速
	ptr->given_current = (int16_t)(PduInfoPtr->SduDataPtr[4]<<8 | PduInfoPtr->SduDataPtr[5]);//电流
	ptr->hall = PduInfoPtr->SduDataPtr[6];
	if(ptr->angle - ptr->last_angle > 4096)
		ptr->round_cnt --;
	else if (ptr->angle - ptr->last_angle < -4096)
		ptr->round_cnt ++;
	ptr->total_angle = ptr->round_cnt * 8192 + ptr->angle - ptr->offset_angle;

}

void send_motor_data(void)//返回拓达电机码盘和电流数据
{
	uint16_t timeout = 0xFFFF;
	for(int j = 1 ;j<4 ;j++)
	{
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Query_Location, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("Fail Can_Drv_Write22\r\n");
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));//查询CAN发送完成标志，如果标志被置起则进入回调
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
		Can_PduInfo3 = Can_CreatePduInfo(0x600+j, 0U, 8U, Tode_Query_current, FALSE, FALSE);//创建消息
		if (E_OK != Can_Drv_Write(CanHardwareObject3, &Can_PduInfo3))	//发送消息，CanHardwareObject1指发送消息的邮箱
		{
			printf("Fail Can_Drv_Write23\r\n");
			return ;
		}
		while(!CanIf_bTxFlag)	//等待发送完成
		{
			Can_Drv_MainFunction_Write(Can_Config.Can_ppController[0],&(Can_apxConfig->Can_pHwObjectConfig[3]));
			timeout--;
			if(timeout<0)
			{
				break;
			}
		}
		CanIf_bTxFlag = 0;
	}
}

