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
**  FILENAME     : Gtm_Hw_Tim_Types.h                                         **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
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

#ifndef GTM_HW_TIM_TYPES_H
#define GTM_HW_TIM_TYPES_H

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
#define GTM_HW_TIM_TYPES_VENDOR_ID_H                      1541
#define GTM_HW_TIM_TYPES_MODULE_ID_H                      221
#define GTM_HW_TIM_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_TIM_TYPES_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_TIM_TYPES_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_TIM_TYPES_SW_MAJOR_VERSION_H               1
#define GTM_HW_TIM_TYPES_SW_MINOR_VERSION_H               1
#define GTM_HW_TIM_TYPES_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Base.h Gtm_Hw_Tim_Types.h file version check */
#if (GTM_HW_BASE_VENDOR_ID_H != GTM_HW_TIM_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Tim_Types.h have different vendor ids"
#endif
#if (GTM_HW_BASE_MODULE_ID_H != GTM_HW_TIM_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Tim_Types.h have different module ids"
#endif
#if ((GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Tim_Types.h are different"
#endif
#if ((GTM_HW_BASE_SW_MAJOR_VERSION_H != GTM_HW_TIM_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_SW_MINOR_VERSION_H != GTM_HW_TIM_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_BASE_SW_PATCH_VERSION_H != GTM_HW_TIM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Tim_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* TIM instance number */
#define TIM_INSTANCE_0      (0U)
#define TIM_INSTANCE_1      (1U)
#define TIM_INSTANCE_2      (2U)

/* TIM channel number */
#define TIM_0_CH_0          (0U)
#define TIM_0_CH_1          (1U)
#define TIM_0_CH_2          (2U)
#define TIM_0_CH_3          (3U)
#define TIM_0_CH_4          (4U)
#define TIM_0_CH_5          (5U)
#define TIM_0_CH_6          (6U)
#define TIM_0_CH_7          (7U)

#define TIM_1_CH_0          ((TIM_0_CH_7) + (1U))
#define TIM_1_CH_1          ((TIM_0_CH_7) + (2U))
#define TIM_1_CH_2          ((TIM_0_CH_7) + (3U))
#define TIM_1_CH_3          ((TIM_0_CH_7) + (4U))
#define TIM_1_CH_4          ((TIM_0_CH_7) + (5U))
#define TIM_1_CH_5          ((TIM_0_CH_7) + (6U))
#define TIM_1_CH_6          ((TIM_0_CH_7) + (7U))
#define TIM_1_CH_7          ((TIM_0_CH_7) + (8U))

#define TIM_2_CH_0          ((TIM_1_CH_7) + (1U))
#define TIM_2_CH_1          ((TIM_1_CH_7) + (2U))
#define TIM_2_CH_2          ((TIM_1_CH_7) + (3U))
#define TIM_2_CH_3          ((TIM_1_CH_7) + (4U))
#define TIM_2_CH_4          ((TIM_1_CH_7) + (5U))
#define TIM_2_CH_5          ((TIM_1_CH_7) + (6U))
#define TIM_2_CH_6          ((TIM_1_CH_7) + (7U))
#define TIM_2_CH_7          ((TIM_1_CH_7) + (8U))

/* Tim maximum channel number */
#define TIM_CH_MAX          TIM_2_CH_7

/*TIM AUX_IN config mask */
#define TIM_CCM_AUXIN_CONFIG_MSK   (0x10001U)

/*TIM AUX_IN config macro */
#define TIM_SET_AUX_IN(reg, channel, input) \
    ((reg) & ~(TIM_CCM_AUXIN_CONFIG_MSK << ((channel) & 0x7U))) \
  | (((input) & TIM_CCM_AUXIN_CONFIG_MSK) << ((channel) & 0x7));

/*TIM IRQ_Enable bit number*/
#define TIM_INTERRUPT_IRQ_BIT_NUM     (6U)

/*When filtering is configured, the data defined by the enumeration type
 * is replaced with the significant bit of the required data*/
#define TIM_FILTERMODE_FLT_MODE       (1U)
#define TIM_FILTERMODE_EFLT_CTR       (2U)
#define TIM_FILTERMODE_FLT_CTR        (3U)

/* TIM Maximum clock monitoring index*/
#define TIM_MON_INDEX_MAX               7U
/* TIM clock monitoring configuration bit width*/
#define TIM_MON_BIT_WIDTH               4U
/* TIM Enter the maximum selection value*/
#define TIM_MON_SEL_MAX                 4U

/* TIM Operational requirement*/
#define TIM_THOUSAND                    1000.0f
#define TIM_HUNDRED                     100.0f

/******************************************************************************
*                            Enums
*******************************************************************************/
/* Tim Channel Usage Type*/
typedef enum
{
    TIM_USED_BY_OTHER = 0,
    TIM_USED_BY_GTM_DRIVER,
    TIM_INTERRUPT_PULSE_NOTIFY_MODE,
    TIM_INTERRUPT_SINGLE_PULSE_MODE
}Tim_ChannelUsageType;

/* Tim Channel Input Select Type */
typedef enum
{
    TIM_INPUT_OF_CURRENT_CHANNEL = 0x05U,
    TIM_INPUT_OF_PREVIOUS_CHANNEL = 0x15U,
    TIM_INPUT_OF_AUX_IN_TOM = 0x06U,
    TIM_INPUT_OF_VAL = 0x08U
}Tim_ChannelInputSelectType;

/* Tim Channel Init Signal Type */
typedef enum
{
    TIM_VAL_LOW = 0x1,
    TIM_VAL_HIGH = 0x2
}Tim_ChannelValInitSignalType;

/* Tim Channel Signal Edge Select Type */
typedef enum
{
    TIM_FALLING_EDGE = 0,
    TIM_RISING_EDGE,
    TIM_BOTH_EDGES
}Tim_ChannelSignalEdgeSelectType;

/* Tim Channel Clock Select Type */
typedef enum
{
    TIM_CONFIGURABLE_CLOCK_0 = 0,
    TIM_CONFIGURABLE_CLOCK_1,
    TIM_CONFIGURABLE_CLOCK_2,
    TIM_CONFIGURABLE_CLOCK_3,
    TIM_CONFIGURABLE_CLOCK_4,
    TIM_CONFIGURABLE_CLOCK_5,
    TIM_CONFIGURABLE_CLOCK_6,
    TIM_CONFIGURABLE_CLOCK_7
}Tim_ChannelClockSelectType;

/* Tim Channel Gpr0 Input Select Type*/
typedef enum
{
    TIM_GPR0_FROM_TIMEBASE_TBU_TS0 = 0,
    TIM_GPR0_FROM_TIMEBASE_TBU_TS1,
    TIM_GPR0_FROM_TIMEBASE_TBU_TS2,
    TIM_GPR0_FROM_CNTS_VALUE,
    TIM_GPR0_FROM_ECNT_VALUE,
    TIM_GPR0_FROM_INP_VAL
}Tim_ChannelGpr0InputSelectType;

/* Tim Channel Gpr1 Input Select Type*/
typedef enum
{
    TIM_GPR1_FROM_TIMEBASE_TBU_TS0 = 0,
    TIM_GPR1_FROM_TIMEBASE_TBU_TS1,
    TIM_GPR1_FROM_TIMEBASE_TBU_TS2,
    TIM_GPR1_FROM_CNT_VALUE,
    TIM_GPR1_FROM_ECNT_VALUE,
    TIM_GPR1_FROM_INP_VAL
}Tim_ChannelGpr1InputSelectType;

/* Tim Channel Cnts Input Select Type*/
typedef enum
{
    TIM_CNT_VALUE = 0,
    TIM_TIMEBASE_TIM_TBU_TS0
}Tim_ChannelCntsInputSelectType;

/* Tim Channel Mode Select Type */
typedef enum
{
    TIM_TPWM_MODE = 0,
    TIM_TPIM_MODE,
    TIM_TIEM_MODE,
    TIM_TIPM_MODE,
    TIM_TBCM_MODE,
    TIM_TGPS_MODE,
    TIM_TSSM_MODE
}Tim_ChannelModeSelectType;

/* Tim Channel External Capture source Type*/
typedef enum
{
    TIM_SEL0_NEW_VAL_IRQ = 0,
    TIM_SEL1_AUX_IN,
    TIM_SEL2_CNTOFL_IRQ,
    TIM_SEL3_CICTRL_VALUE,
    TIM_SEL4_ECNTOFL_IRQ,
    TIM_SEL5_TODET_IRQ,
    TIM_SEL6_GLITCHDET_IRQ,
    TIM_SEL7_GPROFL_IRQ,
    TIM_SEL8_CCM_CLK_RES,
    TIM_SEL9_REDGE_DET,
    TIM_SEL10_FEDGE_DET,
    TIM_SEL11_FEDGE_REDGE_DET,
    TIM_SEL12_TDU_SAMPLE_EVT,
    TIM_SEL13_TDU_WORD_EVT,
    TIM_SEL14_TDU_FRAME_EVT
}Tim_ChannelExtCaptureSrcType;

/* Tim Channel Ecnt Reset Setting Type */
typedef enum
{
    TIM_SEL0_IN_WRAP_AROUND_MODE = 0,
    TIM_SEL1_PERIODIC_SAMPLING_MODE
}Tim_ChannelEcntResetSettingType;

/* Tim Channel Ecnt Ovflw Setting Type */
typedef enum
{
    TIM_SEL0_OFL_SIG_ON_BITWIDTH_8 = 0,
    TIM_SEL1_OFL_SIG_ON_BITWIDTH
}Tim_ChannelEcntOvflwSettingType;

/* Tim CH Filter Counter Freq Select Type */
typedef enum
{
    TIM_FIR_CONFIGURABLE_CLOCK_0 = 0,
    TIM_FIR_CONFIGURABLE_CLOCK_1,
    TIM_FIR_CONFIGURABLE_CLOCK_6,
    TIM_FIR_CONFIGURABLE_CLOCK_7
}Tim_ChFirCounterFreqSelectType;

/* Tim CH Filter Mode For Edge Type */
typedef enum
{
    TIM_IMMEDIATE_EDGE_PROPAGATION = 0,
    TIM_DEGLITCH_WITH_UPDOWN_CNT = 4,
    TIM_DEGLITCH_WITH_HOLD_CNT = 5,
    TIM_DEGLITCH_WITH_RESET_CNT = 6
}Tim_ChFilterModeForEdgeType;

/* Tim CH Timeout Detection Enable Type */
typedef enum
{
    TIM_TIMOUT_DISABLED = 0,
    TIM_TIMOUT_EN_ON_RISING_EDGES,
    TIM_TIMOUT_EN_ON_FALLING_EDGES,
    TIM_TIMOUT_EN_ON_BOTH_EDGES,
}Tim_ChTimeoutDetectionEnType;

/* Tim CH Timeout Clock Select Type */
typedef enum
{
    TIM_TIMEOUT_CONFIGURABLE_CLOCK0 = 0,
    TIM_TIMEOUT_CONFIGURABLE_CLOCK1,
    TIM_TIMEOUT_CONFIGURABLE_CLOCK2,
    TIM_TIMEOUT_CONFIGURABLE_CLOCK3,
    TIM_TIMEOUT_CONFIGURABLE_CLOCK4,
    TIM_TIMEOUT_CONFIGURABLE_CLOCK5,
    TIM_TIMEOUT_CONFIGURABLE_CLOCK6,
    TIM_TIMEOUT_CONFIGURABLE_CLOCK7
}Tim_ChTimeoutClockSelectType;

/* Aux_In Input Type*/
typedef enum
{
    TIM_AUXIN_TOM_OUT    = 0x0U,
    TIM_AUXIN_ATOM_OUT   = 0x1U,
    TIM_AUXIN_TOM_OUT_N  = 0x10000U,
    TIM_AUXIN_ATOM_OUT_N = 0x10001U
}Tim_AuxInInputType;

/* TIM interrupt notify flag*/
typedef enum
{
    TIM_NEWVALUE_FLAG = 0,
    TIM_ECNT_OVERFLOW_FLAG,
    TIM_CNT_OVERFLOW_FLAG,
    TIM_GPR_GPROFL_FLAG,
    TIM_TDU_GPROFL_FLAG,
    TIM_GLITCHDET_FLAG
}Tim_StatusFlagType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/*TIM channel type */
typedef uint8 Tim_ChnnelType;

/* Tim Pwm Information */
typedef struct
{
    float64 pwmPeriod;
    float64 fallingEdgeDuration;
    float64 risingEdgeDuration;
    float64 pwmDutyCycle;
} Tim_PwmInfor;

/* Tim Measure Information */
typedef struct
{
    uint32 tiemCnt;
    union
    {
        uint32 R;
        struct
        {
            uint32 Cnts :24;
            uint32 Ecnt :8;
        }B;
    }tiemCnts;
    union
    {
        uint32 R;
        struct
        {
            uint32 Gpr0 :24;
            uint32 Ecnt :8;
        }B;
    }tiemGpr0;
    union
    {
        uint32 R;
        struct
        {
            uint32 Gpr1 :24;
            uint32 Ecnt :8;
        }B;
    }tiemGpr1;
} Tim_MeasureInfor;



/**************************** Type for tim configuration ****************************/

/**
* @brief   This container contains the TIM Channel Configuration.
*
* @implements Gtm_TimChannelConfigTye_struct
*/
typedef struct
{
    /* unit */
    uint8 TimHwUnit;
    /* Aux_In Input Type*/
    Tim_AuxInInputType TimAuxInInput;
    /* Tim Channel Input Select Type */
    Tim_ChannelInputSelectType TimChannelInputSelect;
    /* Tim Channel Init Signal Type */
    Tim_ChannelValInitSignalType TimChannelValInitSignal;
    /* Tim Channel Signal Edge Select Type */
    Tim_ChannelSignalEdgeSelectType TimChannelSignalEdgeSelect;
    /* Tim Channel Clock Select Type */
    Tim_ChannelClockSelectType TimChannelClockSelect;
    /* Tim Channel Gpr0 Input Select Type*/
    Tim_ChannelGpr0InputSelectType TimChannelGpr0InputSelect;
    /* Tim Channel Gpr1 Input Select Type*/
    Tim_ChannelGpr1InputSelectType TimChannelGpr1InputSelect;
    /* Tim Channel Cnts Input Select Type*/
    Tim_ChannelCntsInputSelectType TimChannelCntsInputSelect;
    /* CNTS */
    uint32 TimChannelCntsValue;
    /*This decides the resolution of TBU_TS0 that will be captured in GPR0 and GPR1 register of TIM Channel.*/
    uint8 TimChannelTbu0Ts0BitsSelect;
    /* Tim Channel Mode Select Type */
    Tim_ChannelModeSelectType TimChannelModeSelect;
    /* One-shot mode */
    boolean TimChannelOneShotMode;
    /* External Capture Mode Enable */
    boolean TimChannelExtCaptureModeEnable;
    /* Tim Channel External Capture source Type*/
    Tim_ChannelExtCaptureSrcType TimChannelExtCaptureSrc;
    /* Tim Channel Ecnt Reset Setting Type */
    Tim_ChannelEcntResetSettingType TimChannelEcntResetSetting;
    /* Tim Channel Ecnt Ovflw Setting Type */
    Tim_ChannelEcntOvflwSettingType TimChannelEcntOvflwSetting;
    /* FIR Enable */
    boolean TimChannelFilterEnable;
    /* Tim CH Filter Counter Freq Select Type */
    Tim_ChFirCounterFreqSelectType TimChFilterCounterFreqSelect;
    /* Tim CH Filter Mode For Edge Type */
    Tim_ChFilterModeForEdgeType TimChFilterModeForRisingEdge;
    /* Tim CH Filter Mode For Edge Type */
    Tim_ChFilterModeForEdgeType TimChFilterModeForFallingEdge;
    /* Filter Time For Rising Edge */
    uint32 TimChFilterTimeForRisingEdge;
    /* Filter Time For Falling Edge */
    uint32 TimChFilterTimeForFallingEdge;
    /* Tim CH Timeout Detection Enable Type */
    Tim_ChTimeoutDetectionEnType TimChTimeoutDetectionEnable;
    /* Tim CH Timeout Clock Select Type */
    Tim_ChTimeoutClockSelectType TimChTimeoutClockSelect;
    /* Timeout Duration */
    uint32 TimChTimeoutDuration;
}Tim_ConfigType;

/* Contains register information, configuration information, and status information */
typedef struct
{
    TT_CONST Tim_ConfigType* TimConfig;
} Tim_ParamInfoType;

#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */
