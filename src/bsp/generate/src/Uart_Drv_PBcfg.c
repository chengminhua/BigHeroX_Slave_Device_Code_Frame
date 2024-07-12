/*************************************************************************************
**                                                                                  **
** Copyright (c) ThinkTech Technologies (2023)                                      **
**                                                                                  **
** All rights reserved.                                                             **
**                                                                                  **
** This document contains proprietary information beloging to ThinkTech             **
** Technologies. Passing on and copying of this document, and communication         **
** of its contents is not permitted without prior written authorization.            **
**                                                                                  **
**************************************************************************************
**                                                                                  **
**  FILENAME     : Uart_Drv_PBcfg.c                                                 **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : Uart Driver Configuration Generated File                         **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                     **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                                 History                                           **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Uart_Drv.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define UART_DRV_PBCFG_VENDOR_ID_C                     (1541U)
#define UART_DRV_PBCFG_MODULE_ID_C                     (227U)
#define UART_DRV_PBCFG_INSTANCE_ID_C                   (0U)
#define UART_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C      (4U)
#define UART_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C      (4U)
#define UART_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C      (0U)
#define UART_DRV_PBCFG_SW_MAJOR_VERSION_C              (1U)
#define UART_DRV_PBCFG_SW_MINOR_VERSION_C              (1U)
#define UART_DRV_PBCFG_SW_PATCH_VERSION_C              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Uart_Drv_PBCfg.c and Uart_Drv.h file version check */
#if (UART_DRV_PBCFG_VENDOR_ID_C != UART_DRV_VENDOR_ID_H)
    #error "Uart_Drv_PBCfg.c and Uart_Drv.h have different vendor ids"
#endif
#if (UART_DRV_PBCFG_MODULE_ID_C != UART_DRV_MODULE_ID_H)
    #error "Uart_Drv_PBCfg.c and Uart_Drv.h have different module ids"
#endif
#if ((UART_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C != UART_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C != UART_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C != UART_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Drv_PBCfg.c and Uart_Drv.h are different"
#endif
#if ((UART_DRV_PBCFG_SW_MAJOR_VERSION_C != UART_DRV_SW_MAJOR_VERSION_H) || \
     (UART_DRV_PBCFG_SW_MINOR_VERSION_C != UART_DRV_SW_MINOR_VERSION_H) || \
     (UART_DRV_PBCFG_SW_PATCH_VERSION_C != UART_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Drv_PBCfg.c and Uart_Drv.h are different"
#endif

extern void Uart1_callback(uint32 event);
extern void Uart0_callback(uint32 event);
/******************************************************************************
*                            Public Constants
*******************************************************************************/
#define UART_START_SEC_CONST_UNSPECIFIED
#include "Uart_MemMap.h"
static TT_CONST Uart_CtrlConfigType UartCtrlCfg[] =
{
    {
        .HwUnit         = UART_1,
        .ChannelMode    = UART_CHANNEL,
        .WorkMode       = TT_USART_WORK_IRQ,
        .NumCharFrame   = (uint8)UART_DATA_BITS_8,
        .NumStopBits    = (uint8)UART_STOP_BITS_1,
        .ParityType     = (uint8)UART_PARITY_NO,
        .RtsCtsFlowCtrl = FALSE,
        .TxTrigger      = FALSE,
        .RxTrigger      = FALSE,
        .TxFifoLevel    = UART_FIFO_ON_ONE_EIGHT_LEVEL,
        .RxFifoLevel    = UART_FIFO_ON_ONE_EIGHT_LEVEL,
        .Baudrate       = 2000000,
        .cb_event         = Uart1_callback
    },
    {
        .HwUnit         = UART_0,
        .ChannelMode    = UART_CHANNEL,
        .WorkMode       = TT_USART_WORK_DMA,
        .NumCharFrame   = (uint8)UART_DATA_BITS_8,
        .NumStopBits    = (uint8)UART_STOP_BITS_1,
        .ParityType     = (uint8)UART_PARITY_NO,
        .RtsCtsFlowCtrl = FALSE,
        .TxTrigger      = FALSE,
        .RxTrigger      = FALSE,
        .TxFifoLevel    = UART_FIFO_ON_ONE_EIGHT_LEVEL,
        .RxFifoLevel    = UART_FIFO_ON_ONE_EIGHT_LEVEL,
        .Baudrate       = 100000,
        .UartRxDmaConfigId =  0,
        .UartTxDmaConfigId =  1,
        .cb_event         = Uart0_callback
    }
};

TT_CONST Uart_ConfigType UartConfigData =
{
    .CtrlCfgPtr = UartCtrlCfg 
};
#define UART_STOP_SEC_CONST_UNSPECIFIED
#include "Uart_MemMap.h" 
/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/
 
#ifdef __cplusplus
}
#endif /* __cplusplus */ 
