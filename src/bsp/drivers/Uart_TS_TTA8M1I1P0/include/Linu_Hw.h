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
**  FILENAME     : Linu_Hw.h                                                        **
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
*                           History                                                 **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifndef LINU_HW_H
#define LINU_HW_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                            Includes
 ******************************************************************************/
#include "Linu_Hw_Types.h"
/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define LINU_HW_VENDOR_ID_H                     1541
#define LINU_HW_MODULE_ID_H                     227
#define LINU_HW_AR_RELEASE_MAJOR_VERSION_H      4
#define LINU_HW_AR_RELEASE_MINOR_VERSION_H      4
#define LINU_HW_AR_RELEASE_PATCH_VERSION_H      0
#define LINU_HW_SW_MAJOR_VERSION_H              1
#define LINU_HW_SW_MINOR_VERSION_H              1
#define LINU_HW_SW_PATCH_VERSION_H              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Linu_Hw.h and Linu_Hw_Types.h file version check */
#if (LINU_HW_VENDOR_ID_H != LINU_HW_TYPES_VENDOR_ID_H)
    #error "Linu_Hw.h and Linu_Hw_Types.h have different vendor ids"
#endif
#if (LINU_HW_MODULE_ID_H != LINU_HW_TYPES_MODULE_ID_H)
    #error "Linu_Hw.h and Linu_Hw_Types.h have different module ids"
#endif
#if ((LINU_HW_AR_RELEASE_MAJOR_VERSION_H != LINU_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (LINU_HW_AR_RELEASE_MINOR_VERSION_H != LINU_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (LINU_HW_AR_RELEASE_PATCH_VERSION_H != LINU_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Linu_Hw.h and Linu_Hw_Types.h are different"
#endif
#if ((LINU_HW_SW_MAJOR_VERSION_H != LINU_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (LINU_HW_SW_MINOR_VERSION_H != LINU_HW_TYPES_SW_MINOR_VERSION_H) || \
     (LINU_HW_SW_PATCH_VERSION_H != LINU_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Linu_Hw.h and Linu_Hw_Types.h are different"
#endif
/******************************************************************************
 *                            Defines And Macros
 *******************************************************************************/

/******************************************************************************
 *                            Enums
 *******************************************************************************/

/******************************************************************************
 *                         Structures And Typedefs
 *******************************************************************************/

/******************************************************************************
 *                            Global Variable Declarations
 *******************************************************************************/
#if (TT_SAFETY == STD_ON)
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
TT_RetType Linu_Hw_InitCheck(TT_CONST Uart_ConfigType *CfgPtr);
#endif
/**
 * @brief      :  Service for initialization of UART
 * @details    :  Select serial uart initialization mode
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: The initialization is complete
 *             :  E_NOT_OK: Initialization is not complete
 *
 **/
TT_RetType Linu_Hw_Init(TT_CONST Uart_ConfigType *CfgPtr);

/**
 * @brief      :  Service for Deinitialization of UART
 * @details    :  Select serial uart De-initialization mode
 *
 * @param[in]  :  None
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: De-initialization command accepted
 *             :  E_NOT_OK: De-initialization command has not been accepted
 *
 **/
TT_RetType Linu_Hw_DeInit(void);

/**
 * @brief      :  Service for UART SyncTransmit
 * @details    :  Service for UART SyncTransmit
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  E_NOT_OK: Transmit command not accepted
 *
 **/
TT_RetType Linu_Hw_SyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf, uint16 Length);

/**
 * @brief      :  Service for UART AsyncTransmit
 * @details    :  Service for UART AsyncTransmit
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  E_NOT_OK: Transmit command not accepted
 *
 **/
TT_RetType Linu_Hw_AsyncTransmit(TT_CONST uint8 HwUnit,uint8* TxBuf,uint16 Length);

/**
 * @brief      :  Service for UART SyncReceive
 * @details    :  Service for UART SyncReceive
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  E_NOT_OK: Receive command not accepted
 *
 **/
TT_RetType  Linu_Hw_SyncReceive(TT_CONST uint8 HwUnit,uint8* RxBuf,uint16 Length);


/**
 * @brief      :  Service for UART AsyncReceive
 * @details    :  Service for UART AsyncReceive
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  E_NOT_OK: Receive command not accepted
 *
 **/
TT_RetType Linu_Hw_AsyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length);

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
 *             :  E_NOT_OK: Get status not accepted
 *
 **/
TT_RetType Linu_Hw_GetStatus(TT_CONST uint8 HwUnit, Uart_StatusType* Status);

/**
 * @brief      :  Get the receiving error message
 * @details    :  Get the receiving error message
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  ErrorInfo  - Get the receiving error message
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get status command accepted
 *             :  E_NOT_OK: Get status not accepted
 *
 **/
TT_RetType Linu_Hw_GetErrorStatus(TT_CONST uint8 HwUnit, uint32* ErrorInfo);

/**
 * @brief      :  This service shall set the baud rate for UART
 * @details    :  This service shall set the baud rate for UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                baudrate - Set baud rate
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set Baudrate command accepted
 *             :  Other: Set Baudrate command not accepted
 *
 **/
TT_RetType Linu_Hw_SetBaudrate(TT_CONST uint8 HwUnit, uint32 baudrate);
void LIN_UartIrqHandler(uint8 HwUnit);
#endif
