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
**  FILENAME     : Adc_Drv_Type.h                                             **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Driver Types Source File                               **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef ADC_Drv_Types_H
#define ADC_Drv_Types_H

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Adc_Hw_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/

#define ADC_DRV_TYPES_VENDOR_ID_H                       1541
#define ADC_DRV_TYPES_MODULE_ID_H                       123
#define ADC_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H        4
#define ADC_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H        4
#define ADC_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H        0
#define ADC_DRV_TYPES_SW_MAJOR_VERSION_H                1
#define ADC_DRV_TYPES_SW_MINOR_VERSION_H                1
#define ADC_DRV_TYPES_SW_PATCH_VERSION_H                0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Adc_Drv_Types.h Adc_Hw_Types.h file version check */
#if (ADC_DRV_TYPES_VENDOR_ID_H != ADC_HW_TYPES_VENDOR_ID_H)
    #error "Adc_Drv_Types.h and Adc_Hw_Types.h have different vendor ids"
#endif

#if (ADC_DRV_TYPES_MODULE_ID_H != ADC_HW_TYPES_MODULE_ID_H)
    #error "Adc_Drv_Types.h and Adc_Hw_Types.h have different module ids"
#endif

#if ((ADC_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != ADC_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != ADC_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != ADC_HW_TYPES_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Drv_Types.h and Adc_Hw_Types.h are different"
#endif

#if ((ADC_DRV_TYPES_SW_MAJOR_VERSION_H != ADC_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (ADC_DRV_TYPES_SW_MINOR_VERSION_H != ADC_HW_TYPES_SW_MINOR_VERSION_H) || \
     (ADC_DRV_TYPES_SW_PATCH_VERSION_H != ADC_HW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Drv_Types.h and Adc_Hw_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/*Universal ADC configuration*/
#define Adc_Drv_CommonConfigType    Adc_Hw_CommonConfigType
/*ADC unit configuration type*/
#define Adc_Drv_HwUnitConfigType    Adc_Hw_HwUnitConfigType
/*ADC channel configuration type*/
#define Adc_Drv_ChannelConfigType   Adc_Hw_ChannelConfigType
/*DMA configuration*/
#define Adc_Drv_DmaConfig           Adc_Hw_DmaConfig
/*FIR configuration type*/
#define Adc_Drv_FilterInfoType      Adc_Hw_FilterInfo
/*unit id*/
#define Adc_Drv_HwUnitType          Adc_Hw_HwUnitType
/*channel id*/
#define Adc_Drv_ChannelType         uint8
/*stop mode*/
#define Adc_Drv_StopModeType        Adc_Hw_StopModeType
/*Cascade trigger type*/
#define Adc_Drv_CTrigType           Adc_Hw_CTrigType
/*Trigger source type*/
#define Adc_Drv_TrigSrcType         Adc_Hw_TrigSrcType
/*Hardware trigger type*/
#define Adc_Drv_HwTrigSigType       Adc_Hw_HwTrigSigType
/*priority type*/
#define Adc_Drv_PriorityType        Adc_Hw_PriorityType

/* Service ID For INIT API */
#define ADC_DRV_SI_INIT                     (100U)
/* Service ID For DEINIT API */
#define ADC_DRV_SI_DEINIT                   (101U)
/* Service ID For CHANNEL_CONFIG API */
#define ADC_DRV_SI_CHANNEL_CONFIG           (102U)
/* Service ID For START_CONVERSION API */
#define ADC_DRV_SI_START_CONVERSION         (103U)
/* Service ID For GET_GLOBAL_STATE API */
#define ADC_DRV_SI_GET_GLOBAL_STATE         (104U)
/* Service ID For GET_CURRENT_STATE API */
#define ADC_DRV_SI_GET_CURRENT_STATE        (105U)
/* Service ID For GET_CHANNEL_STATE API */
#define ADC_DRV_SI_GET_CHANNEL_STATE        (106U)
/* Service ID For GET_VALUE API */
#define ADC_DRV_SI_GET_VALUE                (107U)
/* Service ID For SET_DMA_BUFFER API */
#define ADC_DRV_SI_SET_DMA_BUFFER           (108U)
/* Service ID For SET_DMA_INCRADDR API */
#define ADC_DRV_SI_SET_DMA_INCRADDR         (109U)
/* Service ID For STOP_CONVERSION  API */
#define ADC_DRV_SI_STOP_CONVERSION          (110U)
/* Service ID For CLEAR_GLOBAL_STATE API */
#define ADC_DRV_SI_CLEAR_GLOBAL_STATE       (111U)
/* Service ID For ENABLE_HWTRIG API */
#define ADC_DRV_SI_ENABLE_HWTRIG            (112U)
/* Service ID For DISABLE_HWTRIG API */
#define ADC_DRV_SI_DISABLE_HWTRIG           (113U)
/* Service ID For SET_SEQUENCE API */
#define ADC_DRV_SI_SET_SEQUENCE             (114U)
/* Service ID For SET_CTRIGGER API */
#define ADC_DRV_SI_SET_CTRIGGER             (115U)
/* Service ID For SET_DMATRANS_COUNT API */
#define ADC_DRV_SI_SET_DMATRANS_COUNT       (116U)
/* Service ID For SET_TRIGGER API */
#define ADC_DRV_SI_SET_TRIGGER              (117U)
/* Service ID For SET_READY_INTEN API */
#define ADC_DRV_SI_SET_READY_INTEN          (118U)
/* Service ID For SET_PRIORITY API */
#define ADC_DRV_SI_SET_PRIORITY             (119U)
/* Service ID For SET_DMAEN API */
#define ADC_DRV_SI_SET_DMAEN                (120U)
/* Service ID For GETVER INFO API */
#define ADC_DRV_SI_GETVER_INFO       (121U)
/* Service ID For CLGLOBALST IN MASK API */
#define ADC_DRV_SI_CLGLOBALST_IN_MASK       (122U)


/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
typedef struct
{
    /*Universal ADC configuration*/
    TT_CONST Adc_Drv_CommonConfigType *AdcCom;
    /*ADC unit configuration type*/
    TT_CONST Adc_Drv_HwUnitConfigType *AdcHwUinitConfig;
    /*ADC channel configuration type*/
    TT_CONST Adc_Drv_ChannelConfigType *ChannelConfig;
#ifndef USING_OS_AUTOSAROS
    TT_CONST uint32 Crc;
#endif
} Adc_Drv_ConfigType;

/*Status error message*/
#define ADC_DRV_TT_STATUS_DEFAULT(ApiID)       (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET)       | \
                                                           ((ApiID) << TT_APIID_OFFSET) | \
                                                           (ADC_DRV_MODULE_ID_C  << TT_MODULEID_OFFSET))

#endif
