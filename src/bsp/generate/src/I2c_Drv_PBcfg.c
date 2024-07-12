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
**  FILENAME     : I2c_Drv_PBcfg.c                                                  **
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
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/
/* Include module header file */
#include "I2c_Drv.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define I2C_DRV_PBCFG_VENDOR_ID_C                         (1541U)
#define I2C_DRV_PBCFG_MODULE_ID_C                         (222U)

#define I2C_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C          (4U)
#define I2C_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C          (4U)
#define I2C_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C          (0U)

#define I2C_DRV_PBCFG_SW_MAJOR_VERSION_C                  (1U)
#define I2C_DRV_PBCFG_SW_MINOR_VERSION_C                  (1U)
#define I2C_DRV_PBCFG_SW_PATCH_VERSION_C                  (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* I2c_Hw_Types.h I2c_Drv_PBcfg.c file version check */
#if (I2C_DRV_VENDOR_ID_H != I2C_DRV_PBCFG_VENDOR_ID_C)
    #error "I2c_Drv.h and I2c_Drv_PBcfg.c have different vendor ids"
#endif

#if (I2C_DRV_MODULE_ID_H != I2C_DRV_PBCFG_MODULE_ID_C)
    #error "I2c_Drv.h and I2c_Drv_PBcfg.c have different module ids"
#endif

#if ((I2C_DRV_AR_RELEASE_MAJOR_VERSION_H != I2C_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C) || \
           (I2C_DRV_AR_RELEASE_MINOR_VERSION_H != I2C_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C) || \
           (I2C_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != I2C_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of I2c_Drv.h and I2c_Drv_PBcfg.c are different"
#endif

#if ((I2C_DRV_TYPES_SW_MAJOR_VERSION_H != I2C_DRV_PBCFG_SW_MAJOR_VERSION_C) || \
           (I2C_DRV_TYPES_SW_MINOR_VERSION_H != I2C_DRV_PBCFG_SW_MINOR_VERSION_C) || \
           (I2C_DRV_TYPES_SW_PATCH_VERSION_H != I2C_DRV_PBCFG_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of I2c_Drv.h and I2c_Drv_PBcfg.c are different"
#endif

extern void I2C0_CallBack(uint32 event);

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h" 

static TT_CONST I2c_CtrlConfigType I2cCtrlCfg[]=
{
    {
        .HwUnit          = 0,
        .I2C_WorkChannel = WORK_MODE_MASTER,
        .I2C_WorkMode    = TT_I2C_WORK_IRQ,
        .I2C_Speed       = I2C_BUS_SPEED_STANDARD,
        .Address         = 0x1D,
        .cb_event        = I2C0_CallBack
    }
};

TT_CONST I2c_ConfigType I2C_CfgData =
{
    .CtrlCfgPtr = I2cCtrlCfg 
};


#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h" 

#ifdef __cplusplus
}
#endif
