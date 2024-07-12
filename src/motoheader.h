/*
 * myheader.h
 *
 *  Created on: 2023年12月4日
 *      Author: Administrator
 */
#include "kinematics.h"
#include <string.h>

#ifndef MOTOHEADER_H_
#define MOTOHEADER_H_


//extern __attribute__ ((section (".mcal_data_dtcm"))) uint8_t uart0_buff[UART0_BUFF_SIZE];

typedef enum
{
	DJMoto1_ID = 0x201,
	DJMoto2_ID = 0x202,
	DJMoto3_ID = 0x203,
	TodeMoto1_ID = 0x581,
	TodeMoto2_ID = 0x582,
	TodeMoto3_ID = 0x583
}Mailbox_ID;

typedef struct
{
  uint32_t StdId;    /*!< Specifies the standard identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF */

  uint32_t ExtId;    /*!< Specifies the extended identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFFU */

  uint32_t IDE;      /*!< Specifies the type of identifier for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_Identifier_Type */

  uint32_t RTR;      /*!< Specifies the type of frame for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_remote_transmission_request */

  uint32_t DLC;      /*!< Specifies the length of the frame that will be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 8 */

  uint8_t Data[8];   /*!< Contains the data to be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0xFF */

}CanTxMsgTypeDef;

/**
  * @brief  CAN Rx message structure definition
  */
typedef struct
{
  uint32_t StdId;       /*!< Specifies the standard identifier.
                             This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF */

  uint32_t ExtId;       /*!< Specifies the extended identifier.
                             This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFFU */

  uint32_t IDE;         /*!< Specifies the type of identifier for the message that will be received.
                             This parameter can be a value of @ref CAN_Identifier_Type */

  uint32_t RTR;         /*!< Specifies the type of frame for the received message.
                             This parameter can be a value of @ref CAN_remote_transmission_request */

  uint32_t DLC;         /*!< Specifies the length of the frame that will be received.
                             This parameter must be a number between Min_Data = 0 and Max_Data = 8 */

  uint8_t Data[8];      /*!< Contains the data to be received.
                             This parameter must be a number between Min_Data = 0 and Max_Data = 0xFF */

  uint32_t FMI;         /*!< Specifies the index of the filter the message stored in the mailbox passes through.
                             This parameter must be a number between Min_Data = 0 and Max_Data = 0xFF */

  uint32_t FIFONumber;  /*!< Specifies the receive FIFO number.
                             This parameter can be CAN_FIFO0 or CAN_FIFO1 */

}CanRxMsgTypeDef;

typedef struct
{
  CanRxMsgTypeDef*            pRxMsg;     /*!< Pointer to reception structure */

  CanTxMsgTypeDef*            pTxMsg;     /*!< Pointer to transmit structure  */

  uint32_t               ErrorCode;  /*!< CAN Error code                 */

}CAN_HandleTypeDef;

#define FILTER_BUF_LEN		5
/*接收到的云台电机的参数结构体*/
typedef struct{
	int16_t	 	speed_rpm;
    int16_t  	real_current;
    int16_t  	given_current;
    uint8_t  	hall;
	uint16_t 	angle;				//abs angle range:[0,8191]
	uint16_t 	last_angle;	//abs angle range:[0,8191]
	uint16_t	offset_angle;
	int32_t		round_cnt;
	int32_t		total_angle;
	uint8_t			buf_idx;
	uint16_t			angle_buf[FILTER_BUF_LEN];
	uint16_t			fited_angle;
	uint32_t			msg_cnt;
}moto_measure_t;

typedef  struct
{

    uint16_t ch0;
    uint16_t ch1;
    uint16_t ch2;
    uint16_t ch3;
    uint16_t ch4;
    uint8_t s1;
    uint8_t s2;

    int16_t x;
    int16_t y;
    int16_t z;
    uint8_t press_l;
    uint8_t press_r;

    uint16_t v;
} RC_ctrl_t;

void Disable_Tode_Motor(void);
void Enable_Tode_Motor(void);
void Clear_Error_Tode_Motor(void);
void Set_Moto_Spd(void);
void tode_moto_init(void);
void tode_moto_init_re(void);
void send_motor_data(void);
//void Mimoto_Init(void);
void Get_Measure(moto_measure_t *ptr, const PduInfoType * PduInfoPtr);
Can_PduType Can_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu, boolean IdType, boolean FdEnable);

#endif /* MOTOHEADER_H_ */
