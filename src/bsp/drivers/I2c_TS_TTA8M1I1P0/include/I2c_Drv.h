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
**  FILENAME     : I2c_Drv.h                                                        **
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
*                           History                                                 **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifndef I2C_DRV_H
#define I2C_DRV_H
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "I2c_Drv_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define I2C_DRV_VENDOR_ID_H                    1541
#define I2C_DRV_MODULE_ID_H                    222
#define I2C_DRV_AR_RELEASE_MAJOR_VERSION_H     4
#define I2C_DRV_AR_RELEASE_MINOR_VERSION_H     4
#define I2C_DRV_AR_RELEASE_PATCH_VERSION_H     0
#define I2C_DRV_SW_MAJOR_VERSION_H             1
#define I2C_DRV_SW_MINOR_VERSION_H             1
#define I2C_DRV_SW_PATCH_VERSION_H             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* I2c_Drv_Types.h I2c_Drv.h file version check */
#if (I2C_DRV_TYPES_VENDOR_ID_H != I2C_DRV_VENDOR_ID_H)
#error "I2c_Drv_Types.h and I2c_Drv.h have different vendor id"
#endif
#if (I2C_DRV_TYPES_MODULE_ID_H != I2C_DRV_MODULE_ID_H)
#error "I2c_Drv_Types.h and I2c_Drv.h have different module id"
#endif
#if ((I2C_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != I2C_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
    (I2C_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != I2C_DRV_AR_RELEASE_MINOR_VERSION_H) || \
    (I2C_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != I2C_DRV_AR_RELEASE_PATCH_VERSION_H))
#error "AutoSar Version Numbers of I2c_Drv_Types.h and I2c_Drv.h are different"
#endif
#if ((I2C_DRV_TYPES_SW_MAJOR_VERSION_H != I2C_DRV_SW_MAJOR_VERSION_H) || \
    (I2C_DRV_TYPES_SW_MINOR_VERSION_H != I2C_DRV_SW_MINOR_VERSION_H) || \
    (I2C_DRV_TYPES_SW_PATCH_VERSION_H != I2C_DRV_SW_PATCH_VERSION_H))
#error "Software Version Numbers of I2c_Drv_Types.h and I2c_Drv.h are different"
#endif
/******************************************************************************
*                            Public Function Declaration
******************************************************************************/
/******************************************************************************
*  Service name      : I2c_Drv_Init
*  Syntax            : TT_RetType I2c_Drv_Init(TT_CONST I2c_Hw_ConfigType* CfgPtr)
*  Service ID[hex]   : 100
*  Sync/Async        : Synchronous
*  Reentrancy        : Non reentrant
*  Parameters (in)   : CfgPtr - Pointer to configtype structure
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: The initialization is complete
*                    : Other: Initialization is not complete
*  Description       : Service for initialization of I2c
******************************************************************************/
TT_RetType I2c_Drv_Init(TT_CONST I2c_ConfigType *CfgPtr);
/******************************************************************************
*  Service name    : I2c_Drv_DeInit
*  Syntax          : TT_RetType I2c_Drv_DeInit(void)
*  Service ID      : 101
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameter (in)  : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS - De-initialization command accepted
*                    E_NOT_OK - De-initialization command has not been accepted
*  Description     : Service for De-initialization of I2C
******************************************************************************/
TT_RetType I2c_Drv_DeInit(void);
/******************************************************************************
*  Service name       : I2c_Drv_SyncTransmit
*  Syntax             : TT_RetType I2c_Drv_SyncTransmit(TT_CONST uint8 HwUnit,
*                                                       TT_CONST uint8 *TxBuf,
*                                                       uint16 Length)
*  Service ID         : 102
*  Sync/Async         : Synchronous
*  Reentrancy         : Non reentrant
*  Parameter (in)     : HwUnit - Select an I2C module
*                       TxBuf  - Pointer to the data to be transmitted
*                       Length - Number of bytes to be transmitted. Range: 0 - 65535
*  Parameters (out)   : None
*  Return value       : TT_RET_SUCCESS - Transmit command accepted
*                       Other - Transmit command not accepted
*  Description        : Service for I2c Transmission
*******************************************************************************************/
TT_RetType I2c_Drv_SyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf , uint16 Length);

/******************************************************************************
*  Service name       : I2c_Drv_AsyncTransmit
*  Syntax             : TT_RetType I2c_Drv_AsyncTransmit(TT_CONST uint8 HwUnit,
*                                                       TT_CONST uint8 *TxBuf,
*                                                       uint16 Length)
*  Service ID         : 103
*  Sync/Async          : Asynchronous
*  Reentrancy         : Non reentrant
*  Parameter (in)     : HwUnit - Select an I2C module
*                       TxBuf  - Pointer to the data to be transmitted
*                       Length - Number of bytes to be transmitted. Range: 0 - 65535
*  Parameters (out)   : None
*  Return value       : TT_RET_SUCCESS - Transmit command accepted
*                       Other - Transmit command not accepted
*  Description        : Service for I2c Transmission
*******************************************************************************************/
TT_RetType I2c_Drv_AsyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf , uint16 Length);

/******************************************************************************
*  Service name       : I2c_Drv_AsyncReceive
*  Syntax             : TT_RetType I2c_Drv_AsyncReceive(TT_CONST uint8 HwUnit,
*                                                       uint8 *RxBuf,
*                                                       uint16 *Length)
*  Service ID         : 104
*  Sync/Async          : Asynchronous
*  Reentrancy         : Non reentrant
*  Parameter (in)     : HwUnit - Select an I2C module
*                       Length - Number of bytes which will be read
*  Parameters (out)   : RxBuf  - Buffer to store received data
*  Return value       : TT_RET_SUCCESS - Receive command accepted
*                       Other - Receive command not accepted
*  Description        : Service for I2C Reception
*******************************************************************************************/
TT_RetType I2c_Drv_AsyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length);

/******************************************************************************
*  Service name       : I2c_Drv_SyncReceive
*  Syntax             : TT_RetType I2c_Drv_SyncReceive(TT_CONST uint8 HwUnit,
*                                                      uint8 *RxBuf,
*                                                      uint16 *Length)
*  Service ID         : 105
*  Sync/Async         : Synchronous
*  Reentrancy         : Non reentrant
*  Parameter (in)     : HwUnit - Select an I2C module
*                       Length - Number of bytes which will be read
*  Parameters (out)   : RxBuf  - Buffer to store received data
*  Return value       : TT_RET_SUCCESS - Receive command accepted
*                       Other - Receive command not accepted
*  Description        : Service for I2C Reception
*******************************************************************************************/
TT_RetType I2c_Drv_SyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length);

/******************************************************************************
*  Service name     : I2c_Drv_GetStatus
*  Syntax           : TT_RetType I2c_Drv_GetStatus(TT_CONST uint8 HwUnit,
*                                                  I2c_StatusType* I2cStatus)
*  Service ID       : 106
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : HwUnit - Select an I2C module
*  Parameters (out) : I2cStatus - Gets the status of I2c
*  Return value     : TT_RetType
*                     TT_RET_SUCCESS - Get status command accepted
*                     Other - Get status command not accepted
*  Description      : The service gets the status of the I2c.
******************************************************************************/
TT_RetType I2c_Drv_GetStatus(TT_CONST uint8 HwUnit,I2c_StatusType* I2cStatus);

/******************************************************************************
*  Service name     : I2c_Drv_SetTargetAdderss
*  Syntax           : TT_RetType I2c_Hw_SetMasteradder(TT_CONST uint8 HwUnit,
*                                                      uint16 Adder)
*  Service ID       : 107
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : HwUnit - Select an I2C module
*                     Adder - Set address The correct address is there:
*                     [0x9,0xb]、[0xd,0x60][0x62,0x77]、[0x7d,0x7F]
*  Parameters (out) : I2cStatus - Gets the status of I2c
*  Return value     : TT_RetType
*                     TT_RET_SUCCESS - Set adder command accepted
*                     Other - Set adder command not accepted
*  Description      : The service set adder of the I2c.
******************************************************************************/
TT_RetType I2c_Drv_SetTargetAdderss(TT_CONST uint8 HwUnit, uint16 Adder);

/******************************************************************************
*  Service name     : I2c_GetVersionInfo
*  Syntax           : void I2c_GetVersionInfo(Std_VersionInfoType* VersionInfo)
*  Service ID       : 109
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : None
*  Parameters (out) : VersionInfo: Pointer to where to store the version
*                     information of this module
*  Return value     : TT_RetType
*                     TT_RET_SUCCESS - Get version information command accepted
*                     E_NOT_OK - Get version information command not accepted
*  Description      : Returns the version information of this module.
******************************************************************************/
TT_RetType I2c_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo);


#ifdef __cplusplus
}
#endif

#endif
