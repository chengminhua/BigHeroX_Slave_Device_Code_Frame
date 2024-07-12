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
**  FILENAME     : I2c_Drv_Cfg.h                                                    **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : I2C Driver Configuration Generated File                          **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                     **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                           History                                                 **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifndef I2C_DRV_CFG_H
#define I2C_DRV_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_I2C.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define I2C_DRV_CFG_VENDOR_ID_H                       (1541U)
#define I2C_DRV_CFG_MODULE_ID_H                       (222U)

#define I2C_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H        (4U)
#define I2C_DRV_CFG_AR_RELEASE_MINOR_VERSION_H        (4U)
#define I2C_DRV_CFG_AR_RELEASE_PATCH_VERSION_H        (0U)

#define I2C_DRV_CFG_SW_MAJOR_VERSION_H                (1U)
#define I2C_DRV_CFG_SW_MINOR_VERSION_H                (1U)
#define I2C_DRV_CFG_SW_PATCH_VERSION_H                (0U)

#define I2C_INSTANCE_ID                              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#if (A8V2E_I2C_VENDOR_ID_H != I2C_DRV_CFG_VENDOR_ID_H)
    #error "A8V2E_I2C.h and I2c_Drv_Cfg.h have different vendor ids"
#endif

#if ((A8V2E_I2C_AR_RELEASE_MAJOR_VERSION_H != I2C_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
           (A8V2E_I2C_AR_RELEASE_MINOR_VERSION_H != I2C_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
           (A8V2E_I2C_AR_RELEASE_PATCH_VERSION_H != I2C_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_I2C.h and I2c_Drv_Cfg.h are different"
#endif

#if((A8V2E_I2C_SW_MAJOR_VERSION_H != I2C_DRV_CFG_SW_MAJOR_VERSION_H) || \
          (A8V2E_I2C_SW_MINOR_VERSION_H != I2C_DRV_CFG_SW_MINOR_VERSION_H) || \
          (A8V2E_I2C_SW_PATCH_VERSION_H != I2C_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_I2C.h and I2c_Drv_Cfg.h are different"
#endif

#define I2C_PRECOMPILE_SUPPORT
/* This this will set the timer source for osif that will be used for timeout */
#define I2C_TIMEOUT_SUPERVISION_ENABLE          (STD_OFF)

#define I2C_DEV_ERROR_DETECT                  (STD_OFF)

#define I2C_VERSION_INFO_API                  (STD_OFF)

/* I2C Config Set */
#define I2C_CONTROLLER_COUNT                  (2U)

#define I2C_CONFIGED_COUNT                    (1U)


#define I2C0_CONFIGED
#define I2C0_IRQ_ENABLE


#define I2C_DMA_ENABLE                          (STD_OFF)

/******************************************************************************
*                            Defines checks
*******************************************************************************/
#ifndef I2C_TIMEOUT_SUPERVISION_ENABLE
    #error"I2C_TIMEOUT_SUPERVISION_ENABLE error"
#else
#if ((I2C_TIMEOUT_SUPERVISION_ENABLE != STD_ON) && (I2C_TIMEOUT_SUPERVISION_ENABLE != STD_OFF))
    #error"I2C_TIMEOUT_SUPERVISION_ENABLE error"
#endif
#endif

#if (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
#if (I2C_TIMEOUT_DURATION <= 0)
    #error"I2C_TIMEOUT_DURATION error"
#endif
#endif

#ifndef I2C_VERSION_INFO_API
    #error"I2C_VERSION_INFO_API error"
#else
#if ((I2C_VERSION_INFO_API != STD_ON) && (I2C_VERSION_INFO_API != STD_OFF))
    #error"I2C_VERSION_INFO_API error"
#endif
#endif

#ifndef I2C_CONTROLLER_COUNT
    #error"I2C_CONTROLLER_COUNT error"
#else
#if (I2C_CONTROLLER_COUNT != 2U)
    #error"I2C_CONTROLLER_COUNT error"
#endif
#endif

#ifndef I2C_CONFIGED_COUNT
    #error"I2C_CONFIGED_COUNT error"
#else
#if ((I2C_CONFIGED_COUNT  <= 0) || (I2C_CONFIGED_COUNT > I2C_CONTROLLER_COUNT))
    #error"I2C_CONFIGED_COUNT error"
#endif
#endif

#ifndef I2C_DMA_ENABLE
    #error"I2C_DMA_ENABLE error"
#else
#if ((I2C_DMA_ENABLE != STD_ON) && (I2C_DMA_ENABLE != STD_OFF))
    #error"I2C_DMA_ENABLE error"
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
