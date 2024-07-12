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
**  FILENAME     : Uart_Hw.h                                                        **
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
#ifndef UART_HW_H
#define UART_HW_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                            Includes
 ******************************************************************************/
#include "Uart_Hw_Types.h"
/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define UART_HW_VENDOR_ID_H                     1541
#define UART_HW_MODULE_ID_H                     227
#define UART_HW_AR_RELEASE_MAJOR_VERSION_H      4
#define UART_HW_AR_RELEASE_MINOR_VERSION_H      4
#define UART_HW_AR_RELEASE_PATCH_VERSION_H      0
#define UART_HW_SW_MAJOR_VERSION_H              1
#define UART_HW_SW_MINOR_VERSION_H              1
#define UART_HW_SW_PATCH_VERSION_H              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Uart_Hw.h and Uart_Hw_Types.h file version check */
#if (UART_HW_VENDOR_ID_H != UART_HW_TYPES_VENDOR_ID_H)
    #error "Uart_Hw.h and Uart_Hw_Types.h have different vendor ids"
#endif
#if (UART_HW_MODULE_ID_H != UART_HW_TYPES_MODULE_ID_H)
    #error "Uart_Hw.h and Uart_Hw_Types.h have different module ids"
#endif
#if ((UART_HW_AR_RELEASE_MAJOR_VERSION_H != UART_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HW_AR_RELEASE_MINOR_VERSION_H != UART_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HW_AR_RELEASE_PATCH_VERSION_H != UART_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hw.h and Uart_Hw_Types.h are different"
#endif
#if ((UART_HW_SW_MAJOR_VERSION_H != UART_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (UART_HW_SW_MINOR_VERSION_H != UART_HW_TYPES_SW_MINOR_VERSION_H) || \
     (UART_HW_SW_PATCH_VERSION_H != UART_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hw.h and Uart_Hw_Types.h are different"
#endif

/******************************************************************************
 *                            Global Variable Declarations
 *******************************************************************************/
/**
 * @brief      :  Service for initialization of UART
 * @details    :  Select serial uart initialization mode
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: The initialization is complete
 *             :  Other: Initialization is not complete
 *
 **/
TT_RetType Uart_Hw_Init(TT_CONST Uart_ConfigType *CfgPtr);
/**
 * @brief      :  Serves initial security checks
 * @details    :  Serves initial security checks
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: The initialization is complete
 *             :  Other: Initialization is not complete
 *
 **/
#if (TT_SAFETY == STD_ON)
TT_RetType Uart_Hw_InitCheck(TT_CONST Uart_ConfigType *CfgPtr);
#endif
/**
 * @brief      :  Service for Deinitialization of UART
 * @details    :  Select serial uart De-initialization mode
 *
 * @param[in]  :  None
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: De-initialization command accepted
 *             :  Other: De-initialization command has not been accepted
 *
 **/
TT_RetType Uart_Hw_DeInit(void);
/**
 * @brief      :  Service for UART SyncTransmission
 * @details    :  Service for UART SyncTransmission
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  Other: Transmit command not accepted
 *
 **/
TT_RetType Uart_Hw_SyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf, uint16 Length);
/**
 * @brief      :  Service for UART AsyncTransmission
 * @details    :  Service for UART AsyncTransmission
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  Other: Transmit command not accepted
 *
 **/
TT_RetType Uart_Hw_AsyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf, uint16 Length);
/**
 * @brief      :  Service for UART SyncReception
 * @details    :  Service for UART SyncReception
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  Other: Receive command not accepted
 *
 **/
TT_RetType Uart_Hw_SyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length);
/**
 * @brief      :  Service for UART AsyncReception
 * @details    :  Service for UART AsyncReception
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  Other: Receive command not accepted
 *
 **/
TT_RetType Uart_Hw_AsyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length);
/**
 * @brief      :  Service to get status of the UART
 * @details    :  Service to get status of the UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  UartStatus  - The current status of the uart is
 *                             uninitialized, idle and Busy.
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get status command accepted
 *             :  Other: Get status not accepted
 *
 **/
TT_RetType Uart_Hw_GetStatus(TT_CONST uint8 HwUnit, Uart_StatusType *status);
/**
 * @brief      :  Service to indicate type of error in module operation
 * @details    :  Service to indicate type of error in module operation
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  ErrorInfo  - The current Error information of the uart is
 *                             uninitialized, idle and Busy.
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get Error information command accepted
 *             :  Other: Get Error information command not accepted
 *
 **/
TT_RetType Uart_Hw_GetErrorStatus(TT_CONST uint8 HwUnit, uint32 *ErrorInfo);
/**
 * @brief      :  This service shall set the baud rate for UART
 * @details    :  This service shall set the baud rate for UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Baudrate - Set baud rate
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set Baudrate command accepted
 *             :  Other: Set Baudrate command not accepted
 *
 **/
TT_RetType Uart_Hw_SetBaudrate(TT_CONST uint8 HwUnit, Uart_BaudrateType Baudrate);

#ifdef __cplusplus
}
#endif

#endif
