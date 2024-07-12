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
**  FILENAME     : Uart_Drv.h                                                       **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : Uart Driver Source File                                          **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                     **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                               History                                             **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifndef UART_DRV_H
#define UART_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                            Includes
 ******************************************************************************/
#include "Uart_Drv_Types.h"

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define UART_DRV_VENDOR_ID_H                     1541
#define UART_DRV_MODULE_ID_H                     227
#define UART_DRV_AR_RELEASE_MAJOR_VERSION_H      4
#define UART_DRV_AR_RELEASE_MINOR_VERSION_H      4
#define UART_DRV_AR_RELEASE_PATCH_VERSION_H      0
#define UART_DRV_SW_MAJOR_VERSION_H              1
#define UART_DRV_SW_MINOR_VERSION_H              1
#define UART_DRV_SW_PATCH_VERSION_H              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Uart_Drv.h and Uart_Drv_Types.h file version check */
#if (UART_DRV_VENDOR_ID_H != UART_DRV_TYPES_VENDOR_ID_H)
    #error "Uart_Drv.h and Uart_Drv_Types.h have different vendor ids"
#endif
#if (UART_DRV_MODULE_ID_H != UART_DRV_TYPES_MODULE_ID_H)
    #error "Uart_Drv.h and Uart_Drv_Types.h have different module ids"
#endif
#if ((UART_DRV_AR_RELEASE_MAJOR_VERSION_H != UART_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_DRV_AR_RELEASE_MINOR_VERSION_H != UART_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_DRV_AR_RELEASE_PATCH_VERSION_H != UART_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Drv.h and Uart_Drv_Types.h are different"
#endif
#if ((UART_DRV_SW_MAJOR_VERSION_H != UART_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (UART_DRV_SW_MINOR_VERSION_H != UART_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (UART_DRV_SW_PATCH_VERSION_H != UART_DRV_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Drv.h and Uart_Drv_Types.h are different"
#endif
/******************************************************************************
 *                            Public Prototypes
 *******************************************************************************/

/******************************************************************************
*  Service name      : Uart_Drv_Init
*  Syntax            : TT_RetType Uart_Drv_Init(TT_CONST Uart_ConfigType *CfgPtr)
*  Service ID        : 100
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : CfgPtr - Pointer to configtype structure
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: The initialization is complete
*                      Other: Initialization is not complete
*  Description       : Service for initialization of UART
******************************************************************************/
TT_RetType Uart_Drv_Init(TT_CONST Uart_ConfigType *ConfigPtr);
/******************************************************************************
*  Service name      : Uart_Drv_DeInit
*  Syntax            : TT_RetType Uart_Drv_DeInit(void)
*  Service ID        : 101
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : None
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: De-initialization command accepted
*                      Other: De-initialization command has not been accepted
*  Description       : Service for De-initialization of UART
******************************************************************************/
TT_RetType Uart_Drv_DeInit(void);
/******************************************************************************
*  Service name      : Uart_Drv_SyncTransmit
*  Syntax            : TT_RetType Uart_Drv_SyncTransmit(TT_CONST Uart_LinuHardType HwUnit,
*                                                       uint8 *TxBuf,
*                                                       uint16 Length)
*  Service ID        : 102
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit - Module ID of the Hardware unit to transmit
*                      TxBuf  - Pointer to the data to be transmitted
*                      Length - Number of bytes to be transmitted. Range: 0 - 65535
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: Synctransmit command accepted
*                      Other: Synctransmit command not accepted
*  Description       : Service for UART SyncTransmit
******************************************************************************/
TT_RetType Uart_Drv_SyncTransmit(TT_CONST Uart_LinuHardType HwUnit,uint8 *TxBuf, uint16 Length);

/******************************************************************************
*  Service name      : Uart_Drv_AsyncTransmit
*  Syntax            : TT_RetType Uart_Drv_AsyncTransmit(TT_CONST Uart_LinuHardType HwUnit,
*                                                        uint8 *TxBuf,
*                                                        uint16 Length)
*  Service ID        : 103
*  Sync/Async        : Asynchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit - Module ID of the Hardware unit to transmit
*                      TxBuf  - Pointer to the data to be transmitted
*                      Length - Number of bytes to be transmitted. Range: 0 - 65535
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: Asynctransmit command accepted
*                      Other: Asynctransmit command not accepted
*  Description       : Service for UART Transmission
******************************************************************************/
TT_RetType Uart_Drv_AsyncTransmit(TT_CONST Uart_LinuHardType HwUnit,uint8 *TxBuf, uint16 Length);
/******************************************************************************
*  Service name      : Uart_Drv_SyncReceive
*  Syntax            : TT_RetType Uart_Drv_SyncReceive(TT_CONST Uart_LinuHardType HwUnit,
*                                                  uint8 *RxBuf,
*                                                  uint16 Length)
*  Service ID        : 104
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit - Module ID of the Hardware unit to transmit
*                      Length - Number of bytes which were read
*
*  Parameters (out)  :  RxBuf  - Buffer to store received data
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: Syncreceive command accepted
*                      Other: Syncreceive command not accepted
*  Description       : Service for UART Reception
******************************************************************************/
TT_RetType Uart_Drv_SyncReceive(TT_CONST Uart_LinuHardType HwUnit,uint8 *RxBuf, uint16 Length);

/******************************************************************************
*  Service name      : Uart_Drv_AsyncReceive
*  Syntax            : TT_RetType Uart_Drv_AsyncReceive(TT_CONST Uart_LinuHardType HwUnit,
*                                                       uint8 *RxBuf,
*                                                       uint16 Length)
*  Service ID        : 105
*  Sync/Async        : Asynchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit - Module ID of the Hardware unit to transmit
*                      Length - Number of bytes which were read
*
*  Parameters (out)  :  RxBuf  - Buffer to store received data
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: Asyncreceive command accepted
*                      Other: Asyncreceive command not accepted
*  Description       : Service for UART Reception
******************************************************************************/
TT_RetType Uart_Drv_AsyncReceive(TT_CONST Uart_LinuHardType HwUnit,uint8 *RxBuf, uint16 Length);
/******************************************************************************
*  Service name      : Uart_Drv_GetStatus
*  Syntax            : TT_RetType Uart_Drv_GetStatus(TT_CONST Uart_LinuHardType HwUnit,
*                                                    Uart_StatusType* UartStatus)
*  Service ID        : 106
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : HwUnit -  Module ID of the Hardware unit to get status
*
*  Parameters (out)  : UartStatus - Get module status
*  Return value      : TT_RET_SUCCESS - Get status command accepted
*                      Other - Get status not accepted
*  Description       : Service to get status of the UART
******************************************************************************/
TT_RetType Uart_Drv_GetStatus(TT_CONST Uart_LinuHardType HwUnit, Uart_StatusType *UartStatus);
/******************************************************************************
*  Service name      : Uart_Drv_GetErrorStatus
*  Syntax            : TT_RetType Uart_Drv_GetErrorStatus(TT_CONST Uart_LinuHardType HwUnit,
*                                                         uint8 *ErrorInfo)
*  Service ID        : 107
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : HwUnit -  Module ID of the Hardware unit to get status
*
*  Parameters (out)  : ErrorInfo - bit encoded as follows
*                      For details about the error, see the information
*                      in the Uart_CallBackEvent enumeration
*  Return value      : TT_RET_SUCCESS - Get error status command accepted
*                      Other - Get error status not accepted
*  Description       : Service to indicate type of error in module operation
******************************************************************************/
TT_RetType Uart_Drv_GetErrorStatus(TT_CONST Uart_LinuHardType HwUnit, uint32 *ErrorInfo);

/******************************************************************************
*  Service name      : Uart_SetBaudrate
*  Syntax            : TT_RetType Uart_SetBaudrate(TT_CONST Uart_LinuHardType HwUnit,
*                                                  Uart_BaudrateType Baudrate)
*  Service ID        : 108
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit -  Module ID of the Hardware unit to get status
*                      Baudrate - Baud rate needs to be set
*  Parameters (out)  : None
*  Return value      : TT_RET_SUCCESS - Set baudrate command accepted.
*                      Other - Set baudrate command not accepted.
*  Description       : This service shall set the baud rate for UART
******************************************************************************/
TT_RetType Uart_Drv_SetBaudrate(TT_CONST Uart_LinuHardType HwUnit, Uart_BaudrateType Baudrate);

#if (UART_VERSION_INFO_API == STD_ON)
/******************************************************************************
*  Service name      : Uart_Drv_GetVersionInfo
*  Syntax            : TT_RetType Uart_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo)
*  Service ID        : 107
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : VersionInfo: Pointer to where to store the version
*                      information of this module
*  Parameters (out)  : None
*  Return value      : TT_RET_SUCCESS - Set baudrate command accepted.
*                      Other - Set baudrate command not accepted.
*  Description       : Returns the version information of this module.
******************************************************************************/
TT_RetType Uart_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif

#ifdef __cplusplus
}
#endif

#endif
