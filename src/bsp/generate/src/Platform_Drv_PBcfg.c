/*******************************************************************************
**                                                                            **
** Copyright (C) ThinkTech Technologies (2023)                                **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to ThinkTech      **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Platform_Drv_PBcfg.c                                       **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Configuration Generated File               **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Drv.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_DRV_PBCFG_VENDOR_ID_C                     (1541U)
#define PLATFORM_DRV_PBCFG_MODULE_ID_C                     (219U)
#define PLATFORM_DRV_PBCFG_INSTANCE_ID_C                   (0U)
#define PLATFORM_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C      (4U)
#define PLATFORM_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C      (4U)
#define PLATFORM_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C      (0U)
#define PLATFORM_DRV_PBCFG_SW_MAJOR_VERSION_C              (1U)
#define PLATFORM_DRV_PBCFG_SW_MINOR_VERSION_C              (1U)
#define PLATFORM_DRV_PBCFG_SW_PATCH_VERSION_C              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Drv_PBcfg.c and Platform_Drv file version check */
#if (PLATFORM_DRV_PBCFG_VENDOR_ID_C != PLATFORM_DRV_VENDOR_ID_H)
    #error "Platform_Drv_PBcfg.c and Platform_Drv.h have different vendor id"
#endif
#if (PLATFORM_DRV_PBCFG_MODULE_ID_C != PLATFORM_DRV_MODULE_ID_H)
    #error "Platform_Drv_PBcfg.c and Platform_Drv.h have different module id"
#endif
#if ((PLATFORM_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C != PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C != PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv_PBcfg.c and Platform_Drv.h are different"
#endif
#if ((PLATFORM_DRV_PBCFG_SW_MAJOR_VERSION_C != PLATFORM_DRV_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_PBCFG_SW_MINOR_VERSION_C != PLATFORM_DRV_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_PBCFG_SW_PATCH_VERSION_C != PLATFORM_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv_PBcfg.c and Platform_Drv.h are different"
#endif


/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/

/******************************************************************************
*                            Public Constants
*******************************************************************************/
/* List of configurations for interrupts */

#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 

TT_CONST Platform_Drv_ConfigType Platform_ConfigData = {
    .IntCtrlConfig = &PlatformIntCtrl_ConfigData,
    .MpuConfig     = NULL_PTR,
    .Crc           = 50392
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 

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

#ifdef __cplusplus /* __cplusplus */ 
}
#endif
