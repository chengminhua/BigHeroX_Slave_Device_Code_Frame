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
**  FILENAME     : Gpt_Cfg.h                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Gpt Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/
#include "A8V2E_FTM.h"
#include "A8V2E_SCU.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GPT_CFG_VENDOR_ID_H                      1541
#define GPT_CFG_MODULE_ID_H                      100
#define GPT_CFG_AR_RELEASE_MAJOR_VERSION_H       4
#define GPT_CFG_AR_RELEASE_MINOR_VERSION_H       4
#define GPT_CFG_AR_RELEASE_PATCH_VERSION_H       0
#define GPT_CFG_SW_MAJOR_VERSION_H               1
#define GPT_CFG_SW_MINOR_VERSION_H               1
#define GPT_CFG_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gpt_Cfg.h A8V2E_FTM.h file version check */
#if (GPT_CFG_VENDOR_ID_H != A8V2E_FTM_VENDOR_ID_H)
      #error "Gpt_Drv_PBCfg.h and A8V2E_FTM.h have different vendor id"
#endif

#if ((GPT_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_FTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_FTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_FTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_Cfg.h and A8V2E_FTM.h are different"
#endif

#if ((GPT_CFG_SW_MAJOR_VERSION_H != A8V2E_FTM_SW_MAJOR_VERSION_H) || \
     (GPT_CFG_SW_MINOR_VERSION_H != A8V2E_FTM_SW_MINOR_VERSION_H) || \
     (GPT_CFG_SW_PATCH_VERSION_H != A8V2E_FTM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_Cfg.h and A8V2E_FTM.h are different"
#endif

/* Gpt_Cfg.h A8V2E_SCU.h file version check */
#if (GPT_CFG_VENDOR_ID_H != A8V2E_SCU_VENDOR_ID_H)
      #error "Gpt_Drv_PBCfg.h and A8V2E_SCU.h have different vendor id"
#endif

#if ((GPT_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_SCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_SCU_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_SCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_Cfg.h and A8V2E_SCU.h are different"
#endif

#if ((GPT_CFG_SW_MAJOR_VERSION_H != A8V2E_SCU_SW_MAJOR_VERSION_H) || \
     (GPT_CFG_SW_MINOR_VERSION_H != A8V2E_SCU_SW_MINOR_VERSION_H) || \
     (GPT_CFG_SW_PATCH_VERSION_H != A8V2E_SCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_Cfg.h and A8V2E_SCU.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Service ID for GPT module */
#define GPT_MODULE_ID                         (100U)

/* The instantiation ID of the GPT module */
#define GPT_INSTANCE_ID                       (0U)

/* The number of hardware resources of FTM */
#define GPT_CHANNEL_CONFIG_NUMBER             (1U)

/* The number of hardware resources of FTM */
#define GPT_FTM_MODULE_CONFIG_NUMBER          (1U)

#define GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER    (1U)

#define GPT_ONLY                              (STD_ON)

#define GPT_PREDEF_TIMER_ONLY                 (STD_OFF)

#define GPT_PREDEF_TIMER_1US_16BIT_ENABLE     (STD_OFF)

#define GPT_PREDEF_TIMER_1US_24BIT_ENABLE     (STD_OFF)

#define GPT_PREDEF_TIMER_1US_32BIT_ENABLE     (STD_OFF)

#define GPT_PREDEF_TIMER_100US_32BIT_ENABLE   (STD_OFF)

/* Config Variant selects VariantPreCompile */
#define GPT_PRECOMPILE_SUPPORT                (STD_ON)

/* Error detection is enabled */
#define GPT_DEV_ERROR_DETECT                  (STD_ON)

/* Open the deinitializer function */
#define GPT_DEINIT_API                        (STD_ON)

/* Open the get elapsed Time function */
#define GPT_TIME_ELAPSED_API                  (STD_ON)

/* Open the get time remaining to destination function */
#define GPT_TIME_REMAINING_API                (STD_ON)

/* Open the enable/disable interrupt notification function */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API   (STD_ON)

/* Open the enable/disable interrupt notification function */
#define GPT_VERSION_INFO_API                  (STD_ON)

#define GPT_FTM1

#define GPT_CHANNEL_TIMER_FTM1

/******************************************************************************
*                       Defines Checks
******************************************************************************/
#ifndef GPT_MODULE_ID
    #error "GPT_MODULE_ID Defines Error"
#else
#if (GPT_MODULE_ID != 100)
    #error "GPT_MODULE_ID Defines Error"
#endif
#endif

#ifndef GPT_INSTANCE_ID
    #error "GPT_INSTANCE_ID Defines Error"
#else
#if (GPT_INSTANCE_ID >= 255)
    #error "GPT_INSTANCE_ID Defines Error"
#endif
#endif

#ifndef GPT_CHANNEL_CONFIG_NUMBER
    #error "GPT_CHANNEL_CONFIG_NUMBER Defines Error"
#else
#if ((GPT_CHANNEL_CONFIG_NUMBER > 6) || (GPT_CHANNEL_CONFIG_NUMBER == 0))
    #error "GPT_CHANNEL_CONFIG_NUMBER Defines Error"
#endif
#endif

#ifndef GPT_FTM_MODULE_CONFIG_NUMBER
    #error "GPT_FTM_MODULE_CONFIG_NUMBER Defines Error"
#else
#if ((GPT_FTM_MODULE_CONFIG_NUMBER > 6) || (GPT_FTM_MODULE_CONFIG_NUMBER == 0))
    #error "GPT_FTM_MODULE_CONFIG_NUMBER Defines Error"
#endif
#endif

#ifndef GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER
    #error "GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER Defines Error"
#else
#if ((GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER > 3) || (GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER == 0))
    #error "GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER Defines Error"
#endif
#endif

#ifndef GPT_ONLY
    #error "GPT_ONLY Defines Error"
#else
#if ((GPT_ONLY != STD_OFF) && (GPT_ONLY != STD_ON))
    #error "GPT_ONLY Defines Error"
#endif
#endif

#ifndef GPT_PREDEF_TIMER_ONLY
    #error "GPT_PREDEF_TIMER_ONLY Defines Error"
#else
#if ((GPT_PREDEF_TIMER_ONLY != STD_OFF) && (GPT_PREDEF_TIMER_ONLY != STD_ON))
    #error "GPT_PREDEF_TIMER_ONLY Defines Error"
#endif
#endif

#ifndef GPT_PREDEF_TIMER_1US_16BIT_ENABLE
    #error "GPT_PREDEF_TIMER_1US_16BIT_ENABLE Defines Error"
#else
#if ((GPT_PREDEF_TIMER_1US_16BIT_ENABLE != STD_OFF) && (GPT_PREDEF_TIMER_1US_16BIT_ENABLE != STD_ON))
    #error "GPT_PREDEF_TIMER_1US_16BIT_ENABLE Defines Error"
#endif
#endif

#ifndef GPT_PREDEF_TIMER_1US_24BIT_ENABLE
    #error "GPT_PREDEF_TIMER_1US_24BIT_ENABLE Defines Error"
#else
#if ((GPT_PREDEF_TIMER_1US_24BIT_ENABLE != STD_OFF) && (GPT_PREDEF_TIMER_1US_24BIT_ENABLE != STD_ON))
    #error "GPT_PREDEF_TIMER_1US_24BIT_ENABLE Defines Error"
#endif
#endif

#ifndef GPT_PREDEF_TIMER_1US_32BIT_ENABLE
    #error "GPT_PREDEF_TIMER_1US_32BIT_ENABLE Defines Error"
#else
#if ((GPT_PREDEF_TIMER_1US_32BIT_ENABLE != STD_OFF) && (GPT_PREDEF_TIMER_1US_32BIT_ENABLE != STD_ON))
    #error "GPT_PREDEF_TIMER_1US_32BIT_ENABLE Defines Error"
#endif
#endif

#ifndef GPT_PREDEF_TIMER_100US_32BIT_ENABLE
    #error "GPT_PREDEF_TIMER_100US_32BIT_ENABLE Defines Error"
#else
#if ((GPT_PREDEF_TIMER_100US_32BIT_ENABLE != STD_OFF) && (GPT_PREDEF_TIMER_100US_32BIT_ENABLE != STD_ON))
    #error "GPT_PREDEF_TIMER_100US_32BIT_ENABLE Defines Error"
#endif
#endif

#ifndef GPT_PRECOMPILE_SUPPORT
    #error "GPT_PRECOMPILE_SUPPORT Defines Error"
#else
#if ((GPT_PRECOMPILE_SUPPORT != STD_OFF) && (GPT_PRECOMPILE_SUPPORT != STD_ON))
    #error "GPT_PRECOMPILE_SUPPORT Defines Error"
#endif
#endif

#ifndef GPT_DEV_ERROR_DETECT
    #error "GPT_DEV_ERROR_DETECT Defines Error"
#else
#if ((GPT_DEV_ERROR_DETECT != STD_OFF) && (GPT_DEV_ERROR_DETECT != STD_ON))
    #error "ERROR DETECT Defines Error"
#endif
#endif

#ifndef GPT_DEINIT_API
    #error "GPT_DEINIT_API Defines Error"
#else
#if ((GPT_DEINIT_API != STD_OFF) && (GPT_DEINIT_API != STD_ON))
    #error "GPT_DEINIT_API Defines Error"
#endif
#endif

#ifndef GPT_TIME_ELAPSED_API
    #error "GPT_TIME_ELAPSED_API Defines Error"
#else
#if ((GPT_TIME_ELAPSED_API != STD_OFF) && (GPT_TIME_ELAPSED_API != STD_ON))
    #error "GPT_TIME_ELAPSED_API Defines Error"
#endif
#endif

#ifndef GPT_TIME_REMAINING_API
    #error "GPT_TIME_REMAINING_API Defines Error"
#else
#if ((GPT_TIME_REMAINING_API != STD_OFF) && (GPT_TIME_REMAINING_API != STD_ON))
    #error "GPT_TIME_REMAINING_API Defines Error"
#endif
#endif

#ifndef GPT_ENABLE_DISABLE_NOTIFICATION_API
    #error "GPT_ENABLE_DISABLE_NOTIFICATION_API Defines Error"
#else
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API != STD_OFF) && (GPT_ENABLE_DISABLE_NOTIFICATION_API != STD_ON))
    #error "GPT_ENABLE_DISABLE_NOTIFICATION_API Defines Error"
#endif
#endif

#ifndef GPT_VERSION_INFO_API
    #error "GPT_VERSION_INFO_API Defines Error"
#else
#if ((GPT_VERSION_INFO_API != STD_OFF) && (GPT_VERSION_INFO_API != STD_ON))
    #error "GPT_VERSION_INFO_API Defines Error"
#endif
#endif

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
extern void Gpt_Notification_0(void);


#ifdef __cplusplus
}
#endif

#endif
