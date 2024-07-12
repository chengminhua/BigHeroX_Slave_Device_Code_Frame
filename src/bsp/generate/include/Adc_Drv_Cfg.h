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
**  FILENAME     : Adc_Drv_Cfg.h                                              **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef ADC_DRV_CFG_H
#define ADC_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_ADC.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/

#define ADC_DRV_CFG_VENDOR_ID_H                       1541
#define ADC_DRV_CFG_MODULE_ID_H                       123
#define ADC_DRV_CFG_INSTANCE_ID_H                     0
#define ADC_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H        4
#define ADC_DRV_CFG_AR_RELEASE_MINOR_VERSION_H        4
#define ADC_DRV_CFG_AR_RELEASE_PATCH_VERSION_H        0
#define ADC_DRV_CFG_SW_MAJOR_VERSION_H                1
#define ADC_DRV_CFG_SW_MINOR_VERSION_H                1
#define ADC_DRV_CFG_SW_PATCH_VERSION_H                0

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/* Check if header file and A8V2E_ADC header file are of the same vendor */
#if (ADC_DRV_CFG_VENDOR_ID_H != A8V2E_ADC_VENDOR_ID_H)
    #error "Adc_Drv_Cfg.h and A8V2E_ADC.h have different vendor ids"
#endif

/* Check if header file and A8V2E_ADC header file are of the same Autosar version */
#if ((ADC_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_ADC_AR_RELEASE_MAJOR_VERSION_H) || \
    (ADC_DRV_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_ADC_AR_RELEASE_MINOR_VERSION_H) || \
    (ADC_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_ADC_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Drv_Cfg.h and A8V2E_ADC.h are different"
#endif

/* Check if header file and A8V2E_ADC header file are of the same Software version */
#if ((ADC_DRV_CFG_SW_MAJOR_VERSION_H != A8V2E_ADC_SW_MAJOR_VERSION_H) || \
    (ADC_DRV_CFG_SW_MINOR_VERSION_H != A8V2E_ADC_SW_MINOR_VERSION_H) || \
    (ADC_DRV_CFG_SW_PATCH_VERSION_H != A8V2E_ADC_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Drv_Cfg.h and A8V2E_ADC.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

#define Adc1Channel_2 (0U)
#define Adc1Channel_3 (1U)
#define Adc1Channel_4 (2U)
#define Adc2Channel_0 (3U)
#define Adc2Channel_1 (4U)

#define ADC_UNIT_1_ISR_USED

#define ADC_UNIT_2_ISR_USED

#define ADC_HWUNIT_INSTANCE 6U

#define ADC_CHANNEL_NUM 9U

#define ADC_CHANNEL_MAX 5U

#define ADC_MAX_UNITS 2U

#define ADC_DEV_ERROR_DETECT  STD_ON 

#define ADC_PRECOMPILE_SUPPORT
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

#ifndef Adc1Channel_2
    #error "Adc1Channel_2 error"
#else
#if ((Adc1Channel_2 != 0))
    #error "Adc1Channel_2 error"
#endif
#endif

#ifndef Adc1Channel_3
    #error "Adc1Channel_3 error"
#else
#if ((Adc1Channel_3 != 1))
    #error "Adc1Channel_3 error"
#endif
#endif

#ifndef Adc1Channel_4
    #error "Adc1Channel_4 error"
#else
#if ((Adc1Channel_4 != 2))
    #error "Adc1Channel_4 error"
#endif
#endif

#ifndef Adc2Channel_0
    #error "Adc2Channel_0 error"
#else
#if ((Adc2Channel_0 != 3))
    #error "Adc2Channel_0 error"
#endif
#endif

#ifndef Adc2Channel_1
    #error "Adc2Channel_1 error"
#else
#if ((Adc2Channel_1 != 4))
    #error "Adc2Channel_1 error"
#endif
#endif

#ifndef ADC_HWUNIT_INSTANCE
    #error "ADC_HWUNIT_INSTANCE error"
#else
#if ((ADC_HWUNIT_INSTANCE != 6))
    #error "ADC_HWUNIT_INSTANCE error"
#endif
#endif

#ifndef ADC_CHANNEL_NUM
    #error "ADC_CHANNEL_NUM error"
#else
#if ((ADC_CHANNEL_NUM != 9))
    #error "ADC_CHANNEL_NUM error"
#endif
#endif

#ifndef ADC_CHANNEL_MAX
    #error "ADC_CHANNEL_MAX error"
#else
#if ((ADC_CHANNEL_MAX != 5)||((ADC_CHANNEL_MAX < 1)||(ADC_CHANNEL_MAX > 49)))
    #error "ADC_CHANNEL_MAX error"
#endif
#endif

#ifndef ADC_MAX_UNITS
    #error "ADC_MAX_UNITS error"
#else
#if ((ADC_MAX_UNITS != 2))||((ADC_MAX_UNITS < 1)||(ADC_MAX_UNITS > ADC_HWUNIT_INSTANCE))
    #error "ADC_MAX_UNITS error"
#endif
#endif

#ifndef ADC_DEV_ERROR_DETECT
    #error "ADC_DEV_ERROR_DETECT error"
#else
#if ((ADC_DEV_ERROR_DETECT != STD_ON) && (ADC_DEV_ERROR_DETECT != STD_OFF))
    #error "ADC_DEV_ERROR_DETECT error"
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* ADC_DRV_CFG_H */

/** @} */
