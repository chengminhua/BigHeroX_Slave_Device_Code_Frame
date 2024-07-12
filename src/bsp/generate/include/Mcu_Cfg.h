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
**  FILENAME     : Mcu_Cfg.h                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Mcu Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_SCB.h"
#include "A8V2E_SCU.h"
#include "A8V2E_DFCU.h"
#include "A8V2E_PFCU.h"
#include "A8V2E_PPU.h"
#include "A8V2E_PMU.h"
#include "A8V2E_RTC.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_CFG_VENDOR_ID_H                     (1541U)
#define MCU_CFG_MODULE_ID_H                     (101U)
#define MCU_CFG_INSTANCE_ID_H                   (0U)
#define MCU_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define MCU_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define MCU_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define MCU_CFG_SW_MAJOR_VERSION_H              (1U)
#define MCU_CFG_SW_MINOR_VERSION_H              (1U)
#define MCU_CFG_SW_PATCH_VERSION_H              (0U)

#define MCU_INSTANCE_ID                         MCU_CFG_INSTANCE_ID_H

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Cfg.h and A8V2E_SCU.h file version check */
#if (MCU_CFG_VENDOR_ID_H != A8V2E_SCU_VENDOR_ID_H)
    #error "Mcu_Cfg.h and A8V2E_SCU.h have different vendor id"
#endif
#if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_SCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_SCU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_SCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Cfg.h and A8V2E_SCU.h are different"
#endif
#if ((MCU_CFG_SW_MAJOR_VERSION_H != A8V2E_SCU_SW_MAJOR_VERSION_H) || \
     (MCU_CFG_SW_MINOR_VERSION_H != A8V2E_SCU_SW_MINOR_VERSION_H) || \
     (MCU_CFG_SW_PATCH_VERSION_H != A8V2E_SCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Cfg.h and A8V2E_SCU.h are different"
#endif

/* Mcu_Cfg.h and A8V2E_DFCU.h file version check */
#if (MCU_CFG_VENDOR_ID_H != A8V2E_DFCU_VENDOR_ID_H)
    #error "Mcu_Cfg.h and A8V2E_DFCU.h have different vendor id"
#endif
#if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_DFCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_DFCU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_DFCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Cfg.h and A8V2E_DFCU.h are different"
#endif
#if ((MCU_CFG_SW_MAJOR_VERSION_H != A8V2E_DFCU_SW_MAJOR_VERSION_H) || \
     (MCU_CFG_SW_MINOR_VERSION_H != A8V2E_DFCU_SW_MINOR_VERSION_H) || \
     (MCU_CFG_SW_PATCH_VERSION_H != A8V2E_DFCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Cfg.h and A8V2E_DFCU.h are different"
#endif

/* Mcu_Cfg.h and A8V2E_PFCU.h file version check */
#if (MCU_CFG_VENDOR_ID_H != A8V2E_PFCU_VENDOR_ID_H)
    #error "Mcu_Cfg.h and A8V2E_PFCU.h have different vendor id"
#endif
#if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_PFCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_PFCU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_PFCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Cfg.h and A8V2E_PFCU.h are different"
#endif
#if ((MCU_CFG_SW_MAJOR_VERSION_H != A8V2E_PFCU_SW_MAJOR_VERSION_H) || \
     (MCU_CFG_SW_MINOR_VERSION_H != A8V2E_PFCU_SW_MINOR_VERSION_H) || \
     (MCU_CFG_SW_PATCH_VERSION_H != A8V2E_PFCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Cfg.h and A8V2E_PFCU.h are different"
#endif

/* Mcu_Cfg.h and A8V2E_PPU.h file version check */
#if (MCU_CFG_VENDOR_ID_H != A8V2E_PPU_VENDOR_ID_H)
    #error "Mcu_Cfg.h and A8V2E_PPU.h have different vendor id"
#endif
#if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_PPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_PPU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_PPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Cfg.h and A8V2E_PPU.h are different"
#endif
#if ((MCU_CFG_SW_MAJOR_VERSION_H != A8V2E_PPU_SW_MAJOR_VERSION_H) || \
     (MCU_CFG_SW_MINOR_VERSION_H != A8V2E_PPU_SW_MINOR_VERSION_H) || \
     (MCU_CFG_SW_PATCH_VERSION_H != A8V2E_PPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Cfg.h and A8V2E_PPU.h are different"
#endif

/* Mcu_Cfg.h and A8V2E_PMU.h file version check */
#if (MCU_CFG_VENDOR_ID_H != A8V2E_PMU_VENDOR_ID_H)
    #error "Mcu_Cfg.h and A8V2E_PMU.h have different vendor id"
#endif
#if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_PMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_PMU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_PMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Cfg.h and A8V2E_PMU.h are different"
#endif
#if ((MCU_CFG_SW_MAJOR_VERSION_H != A8V2E_PMU_SW_MAJOR_VERSION_H) || \
     (MCU_CFG_SW_MINOR_VERSION_H != A8V2E_PMU_SW_MINOR_VERSION_H) || \
     (MCU_CFG_SW_PATCH_VERSION_H != A8V2E_PMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Cfg.h and A8V2E_PMU.h are different"
#endif

/* Mcu_Cfg.h and A8V2E_RTC.h file version check */
#if (MCU_CFG_VENDOR_ID_H != A8V2E_RTC_VENDOR_ID_H)
    #error "Mcu_Cfg.h and A8V2E_RTC.h have different vendor id"
#endif
#if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_RTC_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_RTC_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_RTC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Cfg.h and A8V2E_RTC.h are different"
#endif
#if ((MCU_CFG_SW_MAJOR_VERSION_H != A8V2E_RTC_SW_MAJOR_VERSION_H) || \
     (MCU_CFG_SW_MINOR_VERSION_H != A8V2E_RTC_SW_MINOR_VERSION_H) || \
     (MCU_CFG_SW_PATCH_VERSION_H != A8V2E_RTC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Cfg.h and A8V2E_RTC.h are different"
#endif


/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define MCU_MODULE_ID                         (MCU_CFG_MODULE_ID_H)

#define MCU_CONFIG_VARIANT                    (MODULE_VARIANT_PRECOMPILE)

#define MCU_DEV_ERROR_DETECT                  (STD_OFF)

#define MCU_GET_RAM_STATE_API                 (STD_OFF)

#define MCU_INIT_CLOCK                        (STD_ON)

#define MCU_NO_PLL                            (STD_OFF)

#define MCU_PERFORM_RESET_API                 (STD_ON)

#define MCU_VERSION_INFO_API                  (STD_OFF)

/* Time out value in uS */
#define MCU_MAX_TIMEOUT_DURATION              (10000U)

/* This this will set the timer source for osif that will be used for timeout */
#define MCU_TIMEOUT_ENABLED                   (STD_OFF)

/* Total number of Clock Setting configured */
#define MCU_NUM_CLOCK_SETTING                 (1)

/* Total number of RAM sector configured */
#define MCU_NUM_RAM_SECTORS                   (1)

/* Total number of Mode Setting configured */
#define MCU_NUM_MODE_SETTING                  (1)

#define MCU_DISABLE_DEM_REPORT_ERROR_STATUS   (STD_ON)
/* cmu config */
#define MCU_CMU5_USED                         (STD_OFF)
#define MCU_CMU6_USED                         (STD_OFF)
#define MCU_CMU7_USED                         (STD_OFF)
#define MCU_CMU8_USED                         (STD_OFF)
#define MCU_CMU9_USED                         (STD_OFF)
#define MCU_CMU_NUMS                          (10)
#define MCU_CMU_ITEM_COUNTS                   (5)

#ifdef FPGA
#define MCU_FPGA_CLK                          (22000000UL)
#define MCU_PLL_CLK                           (MCU_FPGA_CLK)
#define MCU_CORE_CLK                          (MCU_FPGA_CLK)
#define MCU_EPLL_CLK                          (MCU_FPGA_CLK)
#else
/* Clock */
#define MCU_PLL_CLK                           (240000000UL)
#define MCU_CORE_CLK                          (MCU_PLL_CLK)
#define MCU_EPLL_CLK                          (250000000UL)
#endif

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
*                            Defines Checks
******************************************************************************/
#ifndef MCU_MODULE_ID
    #error "MCU_MODULE_ID Defines error"
#if (MCU_MODULE_ID != MCU_CFG_MODULE_ID_H)
    #error "MCU_MODULE_ID Defines error"
#endif
#endif

#ifndef MCU_CONFIG_VARIANT
    #error "MCU_CONFIG_VARIANT Defines error"
#if (MCU_CONFIG_VARIANT > MODULE_VARIANT_POSTBUILD)
    #error "MCU_CONFIG_VARIANT Defines error"
#endif
#endif

#ifndef MCU_DEV_ERROR_DETECT
    #error "MCU_DEV_ERROR_DETECT Defines error"
#if ((MCU_DEV_ERROR_DETECT != STD_OFF) && (MCU_DEV_ERROR_DETECT != STD_ON))
    #error "MCU_DEV_ERROR_DETECT Defines error"
#endif
#endif

#ifndef MCU_GET_RAM_STATE_API
    #error "MCU_GET_RAM_STATE_API Defines error"
#if ((MCU_GET_RAM_STATE_API != STD_OFF) && (MCU_GET_RAM_STATE_API != STD_ON))
    #error "MCU_GET_RAM_STATE_API Defines error"
#endif
#endif

#ifndef MCU_INIT_CLOCK
    #error "MCU_INIT_CLOCK Defines error"
#if ((MCU_INIT_CLOCK != STD_OFF) && (MCU_INIT_CLOCK != STD_ON))
    #error "MCU_INIT_CLOCK Defines error"
#endif
#endif

#ifndef MCU_NO_PLL
    #error "MCU_NO_PLL Defines error"
#if ((MCU_NO_PLL != STD_OFF) && (MCU_NO_PLL != STD_ON))
    #error "MCU_NO_PLL Defines error"
#endif
#endif

#ifndef MCU_PERFORM_RESET_API
    #error "MCU_PERFORM_RESET_API Defines error"
#if ((MCU_PERFORM_RESET_API != STD_OFF) && (MCU_PERFORM_RESET_API != STD_ON))
    #error "MCU_PERFORM_RESET_API Defines error"
#endif
#endif

#ifndef MCU_VERSION_INFO_API
    #error "MCU_VERSION_INFO_API Defines error"
#if ((MCU_VERSION_INFO_API != STD_OFF) && (MCU_VERSION_INFO_API != STD_ON))
    #error "MCU_VERSION_INFO_API Defines error"
#endif
#endif

#ifndef MCU_TIMEOUT_ENABLED
    #error "MCU_TIMEOUT_ENABLED Defines error"
#if ((MCU_TIMEOUT_ENABLED != STD_OFF) && (MCU_TIMEOUT_ENABLED != STD_ON))
    #error "MCU_TIMEOUT_ENABLED Defines error"
#endif
#endif

#ifndef MCU_DISABLE_DEM_REPORT_ERROR_STATUS
    #error "MCU_DISABLE_DEM_REPORT_ERROR_STATUS Defines error"
#if ((MCU_DISABLE_DEM_REPORT_ERROR_STATUS != STD_OFF) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS != STD_ON))
    #error "MCU_DISABLE_DEM_REPORT_ERROR_STATUS Defines error"
#endif
#endif

/* cmu config */
#ifndef MCU_CMU5_USED
    #error "MCU_CMU5_USED Defines error"
#if ((MCU_CMU5_USED != STD_OFF) && (MCU_CMU5_USED != STD_ON))
    #error "MCU_CMU5_USED Defines error"
#endif
#endif

#ifndef MCU_CMU6_USED
    #error "MCU_CMU6_USED Defines error"
#if ((MCU_CMU6_USED != STD_OFF) && (MCU_CMU6_USED != STD_ON))
    #error "MCU_CMU6_USED Defines error"
#endif
#endif

#ifndef MCU_CMU7_USED
    #error "MCU_CMU7_USED Defines error"
#if ((MCU_CMU7_USED != STD_OFF) && (MCU_CMU7_USED != STD_ON))
    #error "MCU_CMU7_USED Defines error"
#endif
#endif

#ifndef MCU_CMU8_USED
    #error "MCU_CMU8_USED Defines error"
#if ((MCU_CMU8_USED != STD_OFF) && (MCU_CMU8_USED != STD_ON))
    #error "MCU_CMU8_USED Defines error"
#endif
#endif

#ifndef MCU_CMU9_USED
    #error "MCU_CMU9_USED Defines error"
#if ((MCU_CMU9_USED != STD_OFF) && (MCU_CMU9_USED != STD_ON))
    #error "MCU_CMU9_USED Defines error"
#endif
#endif

#ifndef MCU_CMU_NUMS
    #error "MCU_CMU_NUMS Defines error"
#if (MCU_CMU_NUMS > 10) || (MCU_CMU_NUMS != 10)
    #error "MCU_CMU_NUMS Defines error"
#endif
#endif

#ifndef MCU_CMU_ITEM_COUNTS
    #error "MCU_CMU_ITEM_COUNTS Defines error"
#if (MCU_CMU_ITEM_COUNTS > 5) || (MCU_CMU_ITEM_COUNTS != 5)
    #error "MCU_CMU_ITEM_COUNTS Defines error"
#endif
#endif

#ifndef FPGA
/* Clock */
#ifndef MCU_PLL_CLK
    #error "MCU_PLL_CLK Defines error"
#if (MCU_PLL_CLK > 240000000UL)
    #error "MCU_PLL_CLK Defines error"
#endif
#endif

#ifndef MCU_CORE_CLK
    #error "MCU_CORE_CLK Defines error"
#if (MCU_CORE_CLK > 240000000UL)
    #error "MCU_CORE_CLK Defines error"
#endif
#endif

#ifndef MCU_EPLL_CLK
    #error "MCU_EPLL_CLK Defines error"
#if (MCU_EPLL_CLK != 250000000UL)
    #error "MCU_EPLL_CLK Defines error"
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */  

#endif /* MCU_CFG_H */
