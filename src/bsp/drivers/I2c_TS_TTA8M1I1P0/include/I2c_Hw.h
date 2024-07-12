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
**  FILENAME     : I2c_Hw.h                                                         **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : I2C Driver Source File                                           **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                     **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                               History                                             **
*[V1.1.0]:                                                                          **
*************************************************************************************/

#ifndef I2C_HW_H
#define I2C_HW_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "I2c_Hw_Types.h"
/*******************************************************************************
*                                 Source File Version Information
*******************************************************************************/
#define I2C_HW_VENDOR_ID_H                    1541
#define I2C_HW_MODULE_ID_H                    222
#define I2C_HW_AR_RELEASE_MAJOR_VERSION_H     4
#define I2C_HW_AR_RELEASE_MINOR_VERSION_H     4
#define I2C_HW_AR_RELEASE_PATCH_VERSION_H     0
#define I2C_HW_SW_MAJOR_VERSION_H             1
#define I2C_HW_SW_MINOR_VERSION_H             1
#define I2C_HW_SW_PATCH_VERSION_H             0

/*******************************************************************************
**                      File Version Checks
*******************************************************************************/

/* I2c_Hw_Types.h I2c_Hw.h file version check */
#if (I2C_HW_VENDOR_ID_H != I2C_HW_TYPES_VENDOR_ID_H)
    #error "I2c_Hw_Types.h and I2c_Hw.h have different vendor ids"
#endif

#if (I2C_HW_MODULE_ID_H != I2C_HW_TYPES_MODULE_ID_H)
    #error "I2c_Hw_Types.h and I2c_Hw.h have different module ids"
#endif

#if ((I2C_HW_AR_RELEASE_MAJOR_VERSION_H != I2C_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (I2C_HW_AR_RELEASE_MINOR_VERSION_H != I2C_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (I2C_HW_AR_RELEASE_PATCH_VERSION_H != I2C_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of I2c_Hw_Types.h and I2c_Hw.h are different"
#endif

#if ((I2C_HW_SW_MAJOR_VERSION_H != I2C_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (I2C_HW_SW_MINOR_VERSION_H != I2C_HW_TYPES_SW_MINOR_VERSION_H) || \
     (I2C_HW_SW_PATCH_VERSION_H != I2C_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of I2c_Hw_Types.h and I2c_Hw.h are different"
#endif

/******************************************************************************
*                            Public Function Declaration
******************************************************************************/
/**
* @brief      :  Initializes the I2c Driver module.
* @details    :  Initializing I2C includes: speed, master/slave mode, address, and so on
* @param[in]  :  CfgPtr :Pointer to configuration set
* @param[out] :  None
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
TT_RetType I2c_Hw_Init(TT_CONST I2c_ConfigType *CfgPtr);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
 * @brief      :  Serves initial security checks
 * @details    :  Serves initial security checks
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: The initialization is complete
 *             :  Other: Initialization is error
 *
 **/
TT_RetType I2c_Hw_InitCheck(TT_CONST I2c_ConfigType *CfgPtr);
#endif
/**
* @brief      :  Service for Deinitialization of I2C.
* @details    :  Check whether I2c is initialized
* @param[in]  :  None
* @param[out] :  None
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
TT_RetType I2c_Hw_DeInit(void);

/**
* @brief      :  Set Master Target adder.
* @details    :  Set the target address of the host.
*                This parameter is available only to the host
* @param[in]  :  HwUnit :Select an I2C module
*             :  Adder  :Set address
* @param[out] :  None
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Complete set master adder successfully
*             :  Other: Failed to set master adder successfully
**/
TT_RetType I2c_Hw_SetTargetAdderss(uint8 HwUnit, uint16 Adder);
/**
* @brief      :  Service for I2C Status .
* @details    :  Gets the status of the current I2C
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  Status ：Store the status of I2c
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Get status command accepted
*             :  Other: Transmit command not accepted
*
**/
TT_RetType I2c_Hw_GetStatus(TT_CONST uint8 HwUnit, I2c_StatusType* Status);

/**
* @brief      :  Service for I2c POLL Transmission.
* @details    :  Select which I2C to send a fixed length of data
* @param[in]  :  HwUnit :Select an I2C module
*                Length :Number of bytes which will be read
*                TxBuf : Buffer to store transmit data
* @param[out] :  None
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
TT_RetType I2c_Hw_SyncTransmit(TT_CONST uint8 HwUnit,uint8* TxBuf, uint16 Length);
/**
* @brief      :  Service for I2c Transmission.
* @details    :  Select which I2C to send a fixed length of data
* @param[in]  :  HwUnit :Select an I2C module
*                Length :Number of bytes which will be read
*                TxBuf : Buffer to store transmit data
* @param[out] :  None
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
TT_RetType I2c_Hw_AsyncTransmit(TT_CONST uint8  HwUnit,uint8* TxBuf, uint16 Length);
/**
* @brief      :  Service for I2C asynchronous Reception.
* @details    :  Service for I2C asynchronous Reception.
* @param[in]  :  HwUnit :Select an I2C module
*                Length :Number of bytes which will be read
* @param[out] :  RxBuf : Buffer to store receive data
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: Complete data received successfully
*             :  Other: Failed to receive completion data
*
**/
TT_RetType  I2c_Hw_AsyncReceive(TT_CONST uint8  HwUnit, uint8* RxBuf, uint16 Length);

/**
* @brief      :  Service for I2C Synchronous receiving.
* @details    :  Service for I2C Synchronous receiving
*
* @param[in]  :  HwUnit :Select an I2C module
*                Length :Number of bytes which will be read
* @param[out] :  RxBuf : Buffer to store receive data
*
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: Complete data received successfully
*             :  Other: Failed to receive completion data
*
**/
TT_RetType  I2c_Hw_SyncReceive(TT_CONST uint8 HwUnit, uint8* RxBuf, uint16 Length);

#ifdef __cplusplus
}
#endif

#endif
