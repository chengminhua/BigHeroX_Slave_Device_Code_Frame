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
**  FILENAME     : Platform_Drv_Cfg.h                                        **
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
#ifndef PLATFORM_DRV_CFG_H_
#define PLATFORM_DRV_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_PFCU.h"
#include "A8V2E_DFCU.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_DRV_CFG_VENDOR_ID_H                     (1541U)
#define PLATFORM_DRV_CFG_MODULE_ID_H                     (219U)
#define PLATFORM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define PLATFORM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define PLATFORM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define PLATFORM_DRV_CFG_SW_MAJOR_VERSION_H              (1U)
#define PLATFORM_DRV_CFG_SW_MINOR_VERSION_H              (1U)
#define PLATFORM_DRV_CFG_SW_PATCH_VERSION_H              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Drv_Cfg.h and A8V2E_DFCU.h file version check */
#if (PLATFORM_DRV_CFG_VENDOR_ID_H != A8V2E_DFCU_VENDOR_ID_H)
    #error "Platform_Drv_Cfg.h and A8V2E_DFCU.h have different vendor id"
#endif
#if ((PLATFORM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_DFCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_DFCU_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_DFCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv_Cfg.h and A8V2E_DFCU.h are different"
#endif
#if ((PLATFORM_DRV_CFG_SW_MAJOR_VERSION_H != A8V2E_DFCU_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_CFG_SW_MINOR_VERSION_H != A8V2E_DFCU_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_CFG_SW_PATCH_VERSION_H != A8V2E_DFCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv_Cfg.h and A8V2E_DFCU.h are different"
#endif
/* Platform_Drv_Cfg.h and A8V2E_PFCU.h file version check */
#if (PLATFORM_DRV_CFG_VENDOR_ID_H != A8V2E_PFCU_VENDOR_ID_H)
    #error "Platform_Drv_Cfg.h and A8V2E_PFCU.h have different vendor id"
#endif
#if ((PLATFORM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_PFCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_PFCU_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_PFCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv_Cfg.h and A8V2E_PFCU.h are different"
#endif
#if ((PLATFORM_DRV_CFG_SW_MAJOR_VERSION_H != A8V2E_PFCU_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_CFG_SW_MINOR_VERSION_H != A8V2E_PFCU_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_CFG_SW_PATCH_VERSION_H != A8V2E_PFCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv_Cfg.h and A8V2E_PFCU.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define PLATFORM_PRECOMPILE_SUPPORT    

/* Development error checking */
#define PLATFORM_DEV_ERROR_DETECT             (STD_OFF)

#define PLATFORM_INSTANCE_ID                  (0U)

#define PLATFORM_VERSION_INFO_API             (STD_OFF)

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/

/******************************************************************************
*                       Defines Checks
******************************************************************************/
#ifndef PLATFORM_DEV_ERROR_DETECT
    #error "PLATFORM_DEV_ERROR_DETECT Defines error"
#if ((PLATFORM_DEV_ERROR_DETECT != STD_OFF) && (PLATFORM_DEV_ERROR_DETECT != STD_ON))
    #error "PLATFORM_DEV_ERROR_DETECT Defines error"
#endif
#endif

#ifndef PLATFORM_INSTANCE_ID
    #error "PLATFORM_INSTANCE_ID Defines error"
#if (PLATFORM_INSTANCE_ID != (0U)) || (PLATFORM_INSTANCE_ID > 255) || (PLATFORM_INSTANCE_ID < 0)
    #error "PLATFORM_INSTANCE_ID Defines error"
#endif
#endif

#ifndef PLATFORM_VERSION_INFO_API
    #error "PLATFORM_VERSION_INFO_API Defines error"
#if ((PLATFORM_VERSION_INFO_API != STD_OFF) && (PLATFORM_VERSION_INFO_API != STD_ON))
    #error "PLATFORM_VERSION_INFO_API Defines error"
#endif
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#endif /* PLATFORM_CFG_H_ */
