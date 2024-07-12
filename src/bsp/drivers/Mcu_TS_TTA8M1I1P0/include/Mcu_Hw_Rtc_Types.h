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
**  FILENAME     : Mcu_Hw_Rtc_Types.h                                         **
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
#ifndef MCU_HW_RTC_TYPES_H
#define MCU_HW_RTC_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcu_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_RTC_TYPES_VENDOR_ID_H                     1541
#define MCU_HW_RTC_TYPES_MODULE_ID_H                     101
#define MCU_HW_RTC_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_RTC_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_RTC_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_RTC_TYPES_SW_MAJOR_VERSION_H              1
#define MCU_HW_RTC_TYPES_SW_MINOR_VERSION_H              1
#define MCU_HW_RTC_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifndef MCU_HW_RTC_TYPES_H
/* Mcu_Hw_Rtc_Types.h and Mcu_Cfg.h file version check */
#if (MCU_HW_RTC_TYPES_VENDOR_ID_H != MCU_CFG_VENDOR_ID_H)
    #error "Mcu_Hw_Rtc_Types.h and Mcu_Cfg.h have different vendor id"
#endif
#if (MCU_HW_RTC_TYPES_MODULE_ID_H != MCU_CFG_MODULE_ID_H)
    #error "Mcu_Hw_Rtc_Types.h and Mcu_Cfg.h have different module id"
#endif
#if ((MCU_HW_RTC_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_RTC_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_RTC_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Rtc_Types.h and Mcu_Cfg.h are different"
#endif
#if ((MCU_HW_RTC_TYPES_SW_MAJOR_VERSION_H != MCU_CFG_SW_MAJOR_VERSION_H) || \
     (MCU_HW_RTC_TYPES_SW_MINOR_VERSION_H != MCU_CFG_SW_MINOR_VERSION_H) || \
     (MCU_HW_RTC_TYPES_SW_PATCH_VERSION_H != MCU_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Rtc_Types.h and Mcu_Cfg.h are different"
#endif
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define MCU_RTC_RTCS_ROVRF_CLEAR    (0x400UL)                 /*!< TT_RTC RTCS: ROVRF */
#define MCU_RTC_RTCS_APIF_CLEAR     (0x2000UL)                /*!< TT_RTC RTCS: APIF */
#define MCU_RTC_RTCS_RTCF_CLEAR     (0x20000000UL)            /*!< TT_RTC RTCS: RTCF */
/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* Rtc config */
typedef struct
{
    boolean RtcWakeupModeEnable;                             /* Rtc wakeup enable */
    boolean Rtc32FrequencyDivision;                          /* Rtc 32 Frequency Division */
    boolean RtcApiEnable;                                    /* Rtc api enable */
    boolean RtcApiInterruptEnable;                           /* Rtc api interrupt enable */
    boolean RtcOverFlowEnable;                               /* Rtc over flow enable */
    boolean RtcOverFlowInterruptEnable;                      /* Rtc over flow interrupt enable */
    boolean RtcMatchInterruptEnable;                         /* Rtc match interrupt enable */
} Rtc_ConfigType;
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

#endif /* MCU_HW_RTC_TYPES_H */
