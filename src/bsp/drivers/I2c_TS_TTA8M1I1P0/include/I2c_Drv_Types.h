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
**  FILENAME     : I2c_Drv_Types.h                                                  **
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

#ifndef I2C_DRV_TYPES_H
#define I2C_DRV_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "I2c_Hw_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define I2C_DRV_TYPES_VENDOR_ID_H                    1541
#define I2C_DRV_TYPES_MODULE_ID_H                    222
#define I2C_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define I2C_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H     4
#define I2C_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H     0
#define I2C_DRV_TYPES_SW_MAJOR_VERSION_H             1
#define I2C_DRV_TYPES_SW_MINOR_VERSION_H             1
#define I2C_DRV_TYPES_SW_PATCH_VERSION_H             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* I2c_Drv_Types.h I2c_Hw_Types.h file version check */
#if (I2C_DRV_TYPES_VENDOR_ID_H != I2C_HW_TYPES_VENDOR_ID_H)
#error "I2c_Drv_Types.h and I2c_Hw_Types.h have different vendor id"
#endif
#if (I2C_DRV_TYPES_MODULE_ID_H != I2C_HW_TYPES_MODULE_ID_H)
#error "I2c_Drv_Types.h and I2c_Hw_Types.h have different module id"
#endif
#if ((I2C_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != I2C_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
    (I2C_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != I2C_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
    (I2C_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != I2C_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
#error "AutoSar Version Numbers of I2c_Drv_Types.h and I2c_Hw_Types.h are different"
#endif
#if ((I2C_DRV_TYPES_SW_MAJOR_VERSION_H != I2C_HW_TYPES_SW_MAJOR_VERSION_H) || \
    (I2C_DRV_TYPES_SW_MINOR_VERSION_H != I2C_HW_TYPES_SW_MINOR_VERSION_H) || \
    (I2C_DRV_TYPES_SW_PATCH_VERSION_H != I2C_HW_TYPES_SW_PATCH_VERSION_H))
#error "Software Version Numbers of I2c_Drv_Types.h and I2c_Hw_Types.h are different"
#endif

/******************************************************************************
*                            Public Macros
*******************************************************************************/
/* ID definition for the APIs */
#define I2C_SI_INIT                      (uint8)100u
#define I2C_SI_DEINIT                    (uint8)101u
#define I2C_SI_SYNCTRANSMIT              (uint8)102u
#define I2C_SI_ASYNCTRANSMIT             (uint8)103u
#define I2C_SI_ASYNCRECEIVE              (uint8)104u
#define I2C_SI_SYNCRECEIVE               (uint8)105u
#define I2C_SI_GETSTATUS                 (uint8)106u
#define I2C_SI_SETTARGETADDERSS          (uint8)107U
#define I2C_SI_GETVERSIONINFO            (uint8)109u


#ifdef __cplusplus
}
#endif

#endif
