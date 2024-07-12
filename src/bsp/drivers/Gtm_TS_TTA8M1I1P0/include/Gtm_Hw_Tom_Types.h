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
**  FILENAME     : Gtm_Hw_Tom_Types.h                                         **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Gtm Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef GTM_HW_TOM_TYPES_H
#define GTM_HW_TOM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Base.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_TOM_TYPES_VENDOR_ID_H                      1541
#define GTM_HW_TOM_TYPES_MODULE_ID_H                      221
#define GTM_HW_TOM_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_TOM_TYPES_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_TOM_TYPES_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_TOM_TYPES_SW_MAJOR_VERSION_H               1
#define GTM_HW_TOM_TYPES_SW_MINOR_VERSION_H               1
#define GTM_HW_TOM_TYPES_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Base.h Gtm_Hw_Tom_Types.h file version check */
#if (GTM_HW_BASE_VENDOR_ID_H != GTM_HW_TOM_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Tom_Types.h have different vendor ids"
#endif

#if (GTM_HW_BASE_MODULE_ID_H != GTM_HW_TOM_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Tom_Types.h have different module ids"
#endif

#if ((GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Tom_Types.h are different"
#endif

#if ((GTM_HW_BASE_SW_MAJOR_VERSION_H != GTM_HW_TOM_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_SW_MINOR_VERSION_H != GTM_HW_TOM_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_BASE_SW_PATCH_VERSION_H != GTM_HW_TOM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Tom_Types.h are different"
#endif



/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* TOM instance number */
#define TOM_INSTANCE_0          (0U)
#define TOM_INSTANCE_1          (1U)

/* TOM TGC number */
#define TOM_TGCNUMBER_0       (0U)
#define TOM_TGCNUMBER_1       (1U)

/* TOM channel number */
#define TOM_CH_0            (0U)
#define TOM_CH_1            (1U)
#define TOM_CH_2            (2U)
#define TOM_CH_3            (3U)
#define TOM_CH_4            (4U)
#define TOM_CH_5            (5U)
#define TOM_CH_6            (6U)
#define TOM_CH_7            (7U)
#define TOM_CH_8            (8U)
#define TOM_CH_9            (9U)
#define TOM_CH_10           (10U)
#define TOM_CH_11           (11U)
#define TOM_CH_12           (12U)
#define TOM_CH_13           (13U)
#define TOM_CH_14           (14U)
#define TOM_CH_15           (15U)

#define TOM_0_CH_0            (0U)
#define TOM_0_CH_1            (1U)
#define TOM_0_CH_2            (2U)
#define TOM_0_CH_3            (3U)
#define TOM_0_CH_4            (4U)
#define TOM_0_CH_5            (5U)
#define TOM_0_CH_6            (6U)
#define TOM_0_CH_7            (7U)
#define TOM_0_CH_8            (8U)
#define TOM_0_CH_9            (9U)
#define TOM_0_CH_10           (10U)
#define TOM_0_CH_11           (11U)
#define TOM_0_CH_12           (12U)
#define TOM_0_CH_13           (13U)
#define TOM_0_CH_14           (14U)
#define TOM_0_CH_15           (15U)

#define TOM_1_CH_0            ((TOM_0_CH_15) + (1U))
#define TOM_1_CH_1            ((TOM_0_CH_15) + (2U))
#define TOM_1_CH_2            ((TOM_0_CH_15) + (3U))
#define TOM_1_CH_3            ((TOM_0_CH_15) + (4U))
#define TOM_1_CH_4            ((TOM_0_CH_15) + (5U))
#define TOM_1_CH_5            ((TOM_0_CH_15) + (6U))
#define TOM_1_CH_6            ((TOM_0_CH_15) + (7U))
#define TOM_1_CH_7            ((TOM_0_CH_15) + (8U))
#define TOM_1_CH_8            ((TOM_0_CH_15) + (9U))
#define TOM_1_CH_9            ((TOM_0_CH_15) + (10U))
#define TOM_1_CH_10           ((TOM_0_CH_15) + (11U))
#define TOM_1_CH_11           ((TOM_0_CH_15) + (12U))
#define TOM_1_CH_12           ((TOM_0_CH_15) + (13U))
#define TOM_1_CH_13           ((TOM_0_CH_15) + (14U))
#define TOM_1_CH_14           ((TOM_0_CH_15) + (15U))
#define TOM_1_CH_15           ((TOM_0_CH_15) + (16U))

/* TOM up_down mode */
#define TOM_UPDOWN_DISABLE                          (0x0U)
#define TOM_UPDOWN_BY_CN0_RESET                     (0x1U)
#define TOM_UPDOWN_BY_CN0_REACH_TRG                 (0x2U)
#define TOM_UPDOWN_BY_ALL                           (0x3U)

/*TOM IRQ_Enable bit number*/
#define TOM_INTERRUPT_IRQ_BIT_NUM                   (2U)

/* GTM clock enable/disable*/
#define TOM_W_ENABLE                                (2U)
#define TOM_W_DISABLE                               (1U)
#define TOM_R_ENABLE                                (3U)
#define TOM_R_DISABLE                               (0U)

/* Gets the channel enable/disable write value */
#define TOM_GET_EN_CFG_VAL(enbale)          (((boolean)(enbale) == (boolean)TRUE) ? 2U : 1U)
/* Gets the channel enable/disable readback value */
#define TOM_GET_EN_READ_VAL(enbale)         (((boolean)(enbale) == (boolean)TRUE) ? 3U : 0U)

/* Type of connection between GTM and TRIGGER_MUX*/
#define Gtm_ConnectionsType uint8
/******************************************************************************
*                            Enums
*******************************************************************************/
/* Tbu Time base Select Type */
typedef enum
{
    TOM_TBU_TS0_TIMEBASE = 0,
    TOM_TBU_TS1_TIMEBASE,
    TOM_TBU_TS2_TIMEBASE
}Tom_TgcTbuTimebaseSelectType;

/* Tom Channel Usage Type */
typedef enum
{
    TOM_USED_BY_OTHER = 0,
    TOM_USED_BY_GTM_DRIVER
}Tom_ChannelUsageType;

/* Tom Channel Enable Type */
typedef enum
{
    TOM_AT_START = 0,
    TOM_ON_GLOBAL_TRIGGER
}Tom_ChannelEnableType;

/* Tom Channel Output Control Type */
typedef enum
{
    TOM_EN_OUTPUT_AT_START = 0,
    TOM_EN_OUTPUT_ON_GLOBAL_TRIGGER
}Tom_ChannelOutputControlType;

/* Tom Channel Output Signal Level Type */
typedef enum
{
    TOM_LOW = 0,
    TOM_HIGH
}Tom_ChannelOutputSignalLevelType;

/* Tom Channel Clock Select Type */
typedef enum
{
    TOM_FIXED_CLOCK_0 = 0,
    TOM_FIXED_CLOCK_1,
    TOM_FIXED_CLOCK_2,
    TOM_FIXED_CLOCK_3,
    TOM_FIXED_CLOCK_4
}Tom_ChannelClockSelectType;

/* Tom Channel Counter Cn0 Reset Type */
typedef enum
{
    TOM_ON_COMPARE_MATCH_ON_CH = 0,
    TOM_ON_TRIGGER_FROM_PREV_CH
}Tom_ChannelCounterCn0ResetType;

/* Tom Channel External Counter Cn0 Reset Type */
typedef enum
{
    TOM_TRG_ON_PREV_COMPARE_MATCH = 0,
    TOM_TRG_TIM_EXT_CAPTURE
}Tom_ChExtCounterCn0ResetType;

/* Tom Channel Trigger Output Type */
typedef enum
{
    TOM_TRIG_FROM_PREVIOUS_CH = 0,
    TOM_CCU0_TRIG_OF_CH
}Tom_ChannelTriggerOutputType;

/* Tom Channel External Trigger Output Type */
typedef enum
{
    TOM_EXT_TRIG_FROM_PREVIOUS_CH = 0,
    TOM_EXT_TRIG_TIM
}Tom_ChannelExtTriggerOutputType;

/* Tom Interrupt Mode Type */
typedef enum
{
    TOM_INTERRUPT_LEVEL_MODE = 0,
    TOM_INTERRUPT_PULSE_MODE,
    TOM_INTERRUPT_PULSE_NOTIFY_MODE,
    TOM_INTERRUPT_SINGLE_PULSE_MODE
}Tom_InterruptModeType;

/* Tom Channel Output Level Type */
typedef enum
{
    TOM_LOW_LEVEL = 0,
    TOM_HIGH_LEVEL
} Tom_OutputLevelType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* TOM channel type */
typedef uint8 Tom_ChannelType;

/* This container contains the Trigger configuration for the TGC's. */
typedef struct
{
    /* Tgc time base trigger enabel */
    boolean TomTgcTimeBaseTriggerEnable;
    /* Enables/disables the Internal Trigger from TOM Channel 01 */
    boolean TomTgcIntTriggerFromChannel0;
    /* Enables/disables the Internal Trigger from TOM Channel 1 */
    boolean TomTgcIntTriggerFromChannel1;
    /* Enables/disables the Internal Trigger from TOM Channel 2 */
    boolean TomTgcIntTriggerFromChannel2;
    /* Enables/disables the Internal Trigger from TOM Channel 3 */
    boolean TomTgcIntTriggerFromChannel3;
    /* Enables/disables the Internal Trigger from TOM Channel 4 */
    boolean TomTgcIntTriggerFromChannel4;
    /* Enables/disables the Internal Trigger from TOM Channel 5 */
    boolean TomTgcIntTriggerFromChannel5;
    /* Enables/disables the Internal Trigger from TOM Channel 6 */
    boolean TomTgcIntTriggerFromChannel6;
    /* Enables/disables the Internal Trigger from TOM Channel 7 */
    boolean TomTgcIntTriggerFromChannel7;
    /* This parameter selects the timebase which generates the Trigger for TGC. */
    Tom_TgcTbuTimebaseSelectType TomTgcTbuTimebaseSelect;
    /* This parameter specifies the match value for the Timebase Trigger. */
    uint32 TomTgcTimebaseMatchValue;
}Tom_TriggersForTgcType;

/* This container contains the TOM Channel configuration. */
typedef struct
{
    /* Unit */
    uint8 TomHwUnit;
    /* Tom Channel Output Signal Level Type */
    Tom_ChannelOutputSignalLevelType TomChannelOutputSignalLevel;
    /* CN0 */
    uint16 TomChannelCounterValCn0;
    /* CM0 */
    uint16 TomChannelPeriodCompareValCm0;
    /* CM1 */
    uint16 TomChannelDutyCycleCompareValCm1;
    /* SR0 */
    uint16 TomChPeriodCompareShadowValSr0;
    /* SR1 */
    uint16 TomChDCycCompareShadowValSr1;
    /* Whether to enable update when CN0 is reset */
    boolean TomChUpdateEnableOnCn0Reset;
    /* Whether to enable forcible update */
    boolean TomChEnableForceUpdate;
    /* Whether to reset CN0 during forced update */
    boolean TomChResetCn0OnForceUpdate;
    /* Tom Channel Clock Select Type */
    Tom_ChannelClockSelectType TomChannelClockSelect;
    /* Tom Channel Counter Cn0 Reset Type */
    Tom_ChannelCounterCn0ResetType TomChannelCounterCn0Reset;
    /* Tom Channel External Counter Cn0 Reset Type */
    Tom_ChExtCounterCn0ResetType TomChannelExtCounterCn0Reset;
    /* Tom Channel Trigger Output Type */
    Tom_ChannelTriggerOutputType TomChannelTriggerOutput;
    /* Tom Channel External Trigger Output Type */
    Tom_ChannelExtTriggerOutputType TomChannelExtTriggerOutput;
    /* updown mode */
    uint8 TomUpdownMode;
    /* one-shot mode */
    boolean TomChannelOneShotMode;
    /* Enables One Shot Mode trigger for the Channel */
    boolean TomChannelTrigOneShotMode;
    /* Enable Sr0 trigger*/
    boolean TomChannelSr0Trigger;
    /* Enables Bit Reversal Mode for the Channel.*/
    boolean TomChannelBitReversalMode;
}Tom_ChannelConfigType;

/* This container contains the Tom configuration. */
typedef struct
{
    /* Tgc configuration pointer */
    TT_CONST Tom_TriggersForTgcType* TomTriggersForTgc;
    /* Tom's channel configuration pointer */
    TT_CONST Tom_ChannelConfigType*  TomChannelConfig;
}Tom_ConfigType;

/* This container Contains configuration information, register information, and status information. */
typedef struct
{
    /* Tgc configuration pointer */
    volatile TT_CONST Tom_TriggersForTgcType* TomTriggersForTgc;
    /* Tom's channel configuration pointer */
    volatile TT_CONST Tom_ChannelConfigType*  TomChannelConfig;
} Tom_ParamInfoType;

/* Tom output and Trigmux connection types */
typedef struct
{
    Gtm_ConnectionsType GtmTrigger0[12];
    Gtm_ConnectionsType GtmTrigger1[12];
    Gtm_ConnectionsType GtmTrigger2[12];
    Gtm_ConnectionsType GtmTrigger3[12];
}Gtm_ConnectionsConfigType;


#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */
