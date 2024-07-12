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
**  FILENAME     : Mcu_Drv_Types.h                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Mcu Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef MCU_DRV_TYPES_H
#define MCU_DRV_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Hw_Clk_Types.h"
#include "Mcu_Hw_Cmu_Types.h"
#include "Mcu_Hw_Rtc_Types.h"
#include "Mcu_Hw_Ppu_Types.h"
#include "Mcu_Hw_Pmu_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_DRV_TYPES_VENDOR_ID_H                     1541
#define MCU_DRV_TYPES_MODULE_ID_H                     101
#define MCU_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_DRV_TYPES_SW_MAJOR_VERSION_H              1
#define MCU_DRV_TYPES_SW_MINOR_VERSION_H              1
#define MCU_DRV_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Drv_Types.h and Mcu_Hw_Clk_Types.h file version check */
#if (MCU_DRV_TYPES_VENDOR_ID_H != MCU_HW_CLK_TYPES_VENDOR_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Clk_Types.h have different vendor id"
#endif
#if (MCU_DRV_TYPES_MODULE_ID_H != MCU_HW_CLK_TYPES_MODULE_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Clk_Types.h have different module id"
#endif
#if ((MCU_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Clk_Types.h are different"
#endif
#if ((MCU_DRV_TYPES_SW_MAJOR_VERSION_H != MCU_HW_CLK_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_MINOR_VERSION_H != MCU_HW_CLK_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_PATCH_VERSION_H != MCU_HW_CLK_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Clk_Types.h are different"
#endif

/* Mcu_Drv_Types.h and Mcu_Hw_Cmu_Types.h file version check */
#if (MCU_DRV_TYPES_VENDOR_ID_H != MCU_HW_CMU_TYPES_VENDOR_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Cmu_Types.h have different vendor id"
#endif
#if (MCU_DRV_TYPES_MODULE_ID_H != MCU_HW_CMU_TYPES_MODULE_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Cmu_Types.h have different module id"
#endif
#if ((MCU_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_CMU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_HW_CMU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_HW_CMU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Cmu_Types.h are different"
#endif
#if ((MCU_DRV_TYPES_SW_MAJOR_VERSION_H != MCU_HW_CMU_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_MINOR_VERSION_H != MCU_HW_CMU_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_PATCH_VERSION_H != MCU_HW_CMU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Cmu_Types.h are different"
#endif

/* Mcu_Drv_Types.h and Mcu_Hw_Rtc_Types.h file version check */
#if (MCU_DRV_TYPES_VENDOR_ID_H != MCU_HW_RTC_TYPES_VENDOR_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Rtc_Types.h have different vendor id"
#endif
#if (MCU_DRV_TYPES_MODULE_ID_H != MCU_HW_RTC_TYPES_MODULE_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Rtc_Types.h have different module id"
#endif
#if ((MCU_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_RTC_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_HW_RTC_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_HW_RTC_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Rtc_Types.h are different"
#endif
#if ((MCU_DRV_TYPES_SW_MAJOR_VERSION_H != MCU_HW_RTC_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_MINOR_VERSION_H != MCU_HW_RTC_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_PATCH_VERSION_H != MCU_HW_RTC_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Rtc_Types.h are different"
#endif

/* Mcu_Drv_Types.h and Mcu_Hw_Ppu_Types.h file version check */
#if (MCU_DRV_TYPES_VENDOR_ID_H != MCU_HW_PPU_TYPES_VENDOR_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Ppu_Types.h have different vendor id"
#endif
#if (MCU_DRV_TYPES_MODULE_ID_H != MCU_HW_PPU_TYPES_MODULE_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Ppu_Types.h have different module id"
#endif
#if ((MCU_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Ppu_Types.h are different"
#endif
#if ((MCU_DRV_TYPES_SW_MAJOR_VERSION_H != MCU_HW_PPU_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_MINOR_VERSION_H != MCU_HW_PPU_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_PATCH_VERSION_H != MCU_HW_PPU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Ppu_Types.h are different"
#endif

/* Mcu_Drv_Types.h and Mcu_Hw_Pmu_Types.h file version check */
#if (MCU_DRV_TYPES_VENDOR_ID_H != MCU_HW_PMU_TYPES_VENDOR_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Pmu_Types.h have different vendor id"
#endif
#if (MCU_DRV_TYPES_MODULE_ID_H != MCU_HW_PMU_TYPES_MODULE_ID_H)
    #error "Mcu_Drv_Types.h and Mcu_Hw_Pmu_Types.h have different module id"
#endif
#if ((MCU_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_PMU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_HW_PMU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_HW_PMU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Pmu_Types.h are different"
#endif
#if ((MCU_DRV_TYPES_SW_MAJOR_VERSION_H != MCU_HW_PMU_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_MINOR_VERSION_H != MCU_HW_PMU_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_DRV_TYPES_SW_PATCH_VERSION_H != MCU_HW_PMU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv_Types.h and Mcu_Hw_Pmu_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define MCU_DRV_SI_CLK_INIT                     (100U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_GET_PERIPH               (101U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_PLL_CONFIG               (102U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_PLL_LOCKED_CONFIG        (103U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_STOP_MODULES             (104U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_START_MODULES            (105U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_STATUS_MODULES           (106U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_SLEEP_MODULES            (107U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_PERI_STOP_MODULES        (108U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLK_AWAKEN_MODULES           (109U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLk_GET_PLL_STATUS           (110U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CLk_GET_PLL_LOCK_STATUS      (111U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CMU_INIT                     (112U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CMU_START                    (113U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_CMU_STOP                     (114U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PPU_CONTROL                  (115U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_RTC_INIT                     (116U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_RTC_START                    (117U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_RTC_GET_STATUE               (118U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_RTC_CLEAR                    (119U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_MISC_LOCAL_RESET_MODUlES     (120U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_MISC_PERFORM_RESET           (121U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_GET_USER_VALUE           (122U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_SET_USER_VALUE           (123U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_LOCAL_RESET              (124U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_CONFIG_NMI               (125U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_CONFIG_GPIO              (126U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_GET_RESET_RAW_VALUe      (127U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_GET_RESET_REASON         (128U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_ENTER_STANDBY            (129U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_ENTER_SLEEP              (130U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_CONFIG_MODE              (131U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_CONFIG_CB                (132U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PPU_GETERRSTATUS             (133U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PPU_CLEARERRSTATUS           (134U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_SETHSMCIPPOWERDOWN       (135U)     /* Service ID For Mcu Drv API */
#define MCU_DRV_SI_PMU_GETHSMCIPPOWERDOWN       (136U)     /* Service ID For Mcu Drv API */

/* Default Status For Mcu Driver */
#define MCU_DRV_TT_STATUS_DEFAULT(ApiID)       (TT_RetType)(((uint32)TT_RET_SUCCESS << TT_STATUSID_OFFSET)       | \
                                                        ((uint32)(ApiID) << TT_APIID_OFFSET) | \
                                                        ((uint32)MCU_MODULE_ID << TT_MODULEID_OFFSET))
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
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
