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
**  FILENAME     : Adc_Hw_Types.h                                             **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Alioth Types Source File                               **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef ADC_Hw_Types_H
#define ADC_Hw_Types_H

#ifdef USING_OS_AUTOSAROS
#include "Adc_Cfg.h"
#else
#include "Adc_Drv_Cfg.h"
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define ADC_HW_TYPES_VENDOR_ID_H                    1541
#define ADC_HW_TYPES_MODULE_ID_H                    123
#define ADC_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define ADC_HW_TYPES_AR_RELEASE_MINOR_VERSION_H     4
#define ADC_HW_TYPES_AR_RELEASE_PATCH_VERSION_H     0
#define ADC_HW_TYPES_SW_MAJOR_VERSION_H             1
#define ADC_HW_TYPES_SW_MINOR_VERSION_H             1
#define ADC_HW_TYPES_SW_PATCH_VERSION_H             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifdef USING_OS_AUTOSAROS
/* Adc_Hw_Types.h Adc_Cfg.h file version check */
#if (ADC_HW_TYPES_VENDOR_ID_H != ADC_CFG_VENDOR_ID_H)
    #error "Adc_Hw_Types.h and Adc_Cfg.h have different vendor ids"
#endif

#if ((ADC_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != ADC_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != ADC_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != ADC_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Adc_Cfg.h and Base_Chips_Cfg.h are different"
#endif

#if ((ADC_HW_TYPES_SW_MAJOR_VERSION_H != ADC_CFG_SW_MAJOR_VERSION_H) || \
     (ADC_HW_TYPES_SW_MINOR_VERSION_H != ADC_CFG_SW_MINOR_VERSION_H) || \
     (ADC_HW_TYPES_SW_PATCH_VERSION_H != ADC_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Adc_Cfg.h and Base_Chips_Cfg.h are different"
#endif

#else

/* Adc_Hw_Types.h Adc_Drv_Cfg.h file version check */
#if (ADC_HW_TYPES_VENDOR_ID_H != ADC_DRV_CFG_VENDOR_ID_H)
    #error "Adc_Hw_Types.h and Adc_Drv_Cfg.h have different vendor ids"
#endif

#if ((ADC_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != ADC_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != ADC_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != ADC_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Adc_Drv_Cfg.h and Base_Chips_Cfg.h are different"
#endif

#if ((ADC_HW_TYPES_SW_MAJOR_VERSION_H != ADC_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (ADC_HW_TYPES_SW_MINOR_VERSION_H != ADC_DRV_CFG_SW_MINOR_VERSION_H) || \
     (ADC_HW_TYPES_SW_PATCH_VERSION_H != ADC_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Adc_Drv_Cfg.h and Base_Chips_Cfg.h are different"
#endif

#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/*Max number of ADC Hw units*/
#define ADC_MAX_HW_UNITS       (6U)

/*ADC channel ID for struct calls*/
#define ADC0_CH_0    (0x0U)
#define ADC0_CH_1    (0x1U)
#define ADC0_CH_2    (0x2U)
#define ADC0_CH_3    (0x3U)
#define ADC0_CH_4    (0x4U)
#define ADC0_CH_5    (0x5U)
#define ADC0_CH_6    (0x6U)
#define ADC0_CH_7    (0x7U)
#define ADC0_CH_8    (0x8U)
#define ADC0_CH_9    (0x9U)
#define ADC0_CH_10   (0xAU)
#define ADC0_CH_11   (0xBU)
#define ADC0_CH_12   (0xCU)
#define ADC0_CH_13   (0XDU)

#define ADC1_CH_0    (0x10U)
#define ADC1_CH_1    (0x11U)
#define ADC1_CH_2    (0x12U)
#define ADC1_CH_3    (0x13U)
#define ADC1_CH_4    (0x14U)
#define ADC1_CH_5    (0x15U)
#define ADC1_CH_6    (0x16U)
#define ADC1_CH_7    (0x17U)
#define ADC1_CH_8    (0x18U)
#define ADC1_CH_9    (0x19U)
#define ADC1_CH_10   (0x1AU)
#define ADC1_CH_11   (0x1BU)
#define ADC1_CH_12   (0x1CU)
#define ADC1_CH_13   (0X1DU)

#define ADC2_CH_0    (0x20U)
#define ADC2_CH_1    (0x21U)
#define ADC2_CH_2    (0x22U)
#define ADC2_CH_3    (0x23U)
#define ADC2_CH_4    (0x24U)
#define ADC2_CH_5    (0x25U)
#define ADC2_CH_6    (0x26U)
#define ADC2_CH_7    (0x27U)
#define ADC2_CH_8    (0x28U)
#define ADC2_CH_9    (0x29U)
#define ADC2_CH_10   (0x2AU)
#define ADC2_CH_11   (0x2BU)
#define ADC2_CH_12   (0x2CU)
#define ADC2_CH_13   (0x2DU)

#define ADC3_CH_0    (0x30U)
#define ADC3_CH_1    (0x31U)
#define ADC3_CH_2    (0x32U)
#define ADC3_CH_3    (0x33U)
#define ADC3_CH_4    (0x34U)
#define ADC3_CH_5    (0x35U)
#define ADC3_CH_6    (0x36U)
#define ADC3_CH_7    (0x37U)
#define ADC3_CH_8    (0x38U)
#define ADC3_CH_9    (0x39U)
#define ADC3_CH_10   (0x3AU)
#define ADC3_CH_11   (0x3BU)
#define ADC3_CH_12   (0x3CU)
#define ADC3_CH_13   (0x3DU)

#define ADC4_CH_0    (0x40U)
#define ADC4_CH_1    (0x41U)
#define ADC4_CH_2    (0x42U)
#define ADC4_CH_3    (0x43U)
#define ADC4_CH_4    (0x44U)
#define ADC4_CH_5    (0x45U)
#define ADC4_CH_6    (0x46U)
#define ADC4_CH_7    (0x47U)
#define ADC4_CH_8    (0x48U)
#define ADC4_CH_9    (0x49U)
#define ADC4_CH_10   (0x4AU)
#define ADC4_CH_11   (0x4BU)
#define ADC4_CH_12   (0x4CU)
#define ADC4_CH_13   (0x4DU)

#define ADC5_CH_0    (0x50U)
#define ADC5_CH_1    (0x51U)
#define ADC5_CH_2    (0x52U)
#define ADC5_CH_3    (0x53U)
#define ADC5_CH_4    (0x54U)
#define ADC5_CH_5    (0x55U)
#define ADC5_CH_6    (0x56U)
#define ADC5_CH_7    (0x57U)
#define ADC5_CH_8    (0x58U)
#define ADC5_CH_9    (0x59U)
#define ADC5_CH_10   (0x5AU)
#define ADC5_CH_11   (0x5BU)
#define ADC5_CH_12   (0x5CU)
#define ADC5_CH_13   (0x5DU)

/*Adc channel max*/
#ifdef A8V2E
    #define ADC_CH_MAX  ADC5_CH_7
#else
    #define ADC_CH_MAX  ADC5_CH_13
#endif

/*priority type*/
#define	ADC_PRIORITY_BEST_HIGH  (0U)
#define	ADC_PRIORITY_HIGH       (1U)
#define	ADC_PRIORITY_LOW        (2U)
#define	ADC_PRIORITY_BEST_LOW   (3U)

/*Cascade trigger channel type*/
#define   CTRIG_CHANNEL0   (1U)
#define   CTRIG_CHANNEL1   (2U)
#define   CTRIG_CHANNEL2   (3U)
#define   CTRIG_CHANNEL3   (4U)
#define   CTRIG_CHANNEL4   (5U)
#define   CTRIG_CHANNEL5   (6U)
#define   CTRIG_CHANNEL6   (7U)
#define   CTRIG_CHANNEL7   (8U)
#define   CTRIG_CHANNEL8   (9U)
#define   CTRIG_CHANNEL9   (10U)
#define   CTRIG_CHANNEL10  (11U)
#define   CTRIG_CHANNEL11  (12U)
#define   CTRIG_CHANNEL12  (13U)
#define   CTRIG_CHANNEL13  (14U)

/*Filter maximum offset*/
#define ADC_FIRSHIFT_MAX                 (31U)
/*Maximum frequency division*/
#define ADC_DIV_MAX                      (15U)
/*Maximum fast sampling time*/
#define ADC_FTSAMP_MAX                   (31U)
/*ADC maximum frequency*/
#define ADC_FREQUENCY_MAX                (60000000U)
/*compensation data range*/
#define ADC_POSITIVE_COMPENDATA_MAX      (4095)
#define ADC_NEGATIVE_COMPENDATA_MAX      (-4095)
/*The maximum oversampling offset*/
#define ADC_SHIFT_MAX                    (5U)
#define ADC_SHIFT_MIN                    (1U)
/*Range of oversampling times*/
#define ADC_SAMPNUM_MAX                  (5U)
/*DMA transfer count*/
#define ADC_DMATRANCOUNT_MAX             (63U)
/*Maximum increment of DMA transfers*/
#define ADC_DMAINCRADDR_MAX              (31U)
/*ADC unit max*/
#define ADC_MAX                          (5U)
/*ADC Data max*/
#define ADC_Data_MAX                     (4095U)
/*TRIM Indicates the data reduced during hardware operations*/
#define ADC_TRIM_MULTIPLE                (4096.0)
/*offset register symbol bit*/
#define ADC_OFFSET_POS                   (12U)
/*Underflow detection value*/
#define ADC_UNDERFLOW_CHECK_DATA         (1000U)
/*Overflow detection value*/
#define ADC_OVERLOW_CHECK_DATA           (3000U)
/******************************************************************************
*                            Enums
*******************************************************************************/
/*ADC unit*/
typedef enum
{
    ADC0 = 0U,
    ADC1 = 1U,
    ADC2 = 2U,
    ADC3 = 3U,
    ADC4 = 4U,
    ADC5 = 5U,
    ADC255 = 255
} Adc_Hw_HwUnitType;

/*ADC power supply*/
typedef enum
{
    /* VREF = 5V */
    ADC_5V_MODE = 0U,
    /* VREF = 3.3V */
    ADC_3V3_MODE
} Adc_Hw_PowerModeType;

typedef enum
{
    /*wait-ready-start. */
    ADC_HW_WAIT_READY_START = 0U,
    /*cancel-inject-repeat. */
    ADC_HW_CANCEL_INJECT_REPEAT
} Adc_Hw_CModeType;

typedef enum
{
    /*software trigger*/
    ADC_TRIG_SRC_SW = 0U,
    /*hardware trigger*/
    ADC_TRIG_SRC_HW
} Adc_Hw_TrigSrcType;

typedef enum
{
    /* Rising edge */
    ADC_HW_TRIG_RISING_EDGE = 0U,
    /*Falling edge */
    ADC_HW_TRIG_FALLING_EDGE,
    /*falling and rising edge */
    ADC_HW_TRIG_BOTH_EDGES
} Adc_Hw_HwTrigSigType;

typedef enum
{
    /*The DMA normal mode */
    ADC_DMA_MODE_NOMAL = 0U,
    /*The DMA sequences mode */
    ADC_DMA_MODE_SEQUENCES = 1U,
} Adc_Hw_DmaModeType;

typedef enum
{
    /*dynamic stop*/
    ADC_DYNAMIC_STOP = 1U,
    /*force stop*/
    ADC_FORCE_STOP
} Adc_Hw_StopModeType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/*channel type*/
typedef uint8 Adc_Hw_ChannelType;

/*cascade trigger type*/
typedef uint8 Adc_Hw_CTrigType;

/*priority type*/
typedef uint8 Adc_Hw_PriorityType;

/*DMA Sequence type*/
typedef uint32 Adc_Hw_SequenceType;

/*callback function type*/
typedef void (*ADC_Hw_Event) (TT_CONST Adc_Hw_ChannelType AdcChannel,
                              TT_CONST uint32 Event);

typedef struct
{
    /*After this set, enable WRITE PROTECT flag of the ADCFIR register or not.*/
    boolean Fir_Wp;
    /*filters the pointer of the filter coefficient data table.*/
    int32_t filters[25];
} Adc_Hw_FilterInfo;

typedef struct
{
    /*The analog clock freq divide (Fadc=fadc_ctrl/(Div+1)).
     This parameter can be a value in range 0 to 15 */
    TT_CONST uint8 Div;
#ifdef A8V2E
    /* The clock_stop will close the ADC clk when ADC is stopped*/
    TT_CONST boolean Clk_Stop;
#endif
    /*The speed of the low sampling mode.
     This parameter can be a value in range Div+1(Must great than Div) to 255 */
    TT_CONST uint8 STSamp;
    /*The speed of the fast sampling mode.
     This parameter can be a value in range Div+1(Must great than Div) to 31 */
    TT_CONST uint8 FTSamp;
    /*The power supply scheme used by the ADC */
    TT_CONST Adc_Hw_PowerModeType PowerMode;
    /*Right shift after the FIR filter value.
     This parameter can be a value in range 0 to 31 */
    TT_CONST uint8 FirShift;
    /*The AGC0 WP(write protect) bit set, if this bit has been set,
     it cannot be clear and the register AGC0 cannot be modification	*/
    TT_CONST boolean Acg0_Wp;
    /*Fir configuration*/
    TT_CONST Adc_Hw_FilterInfo *Filter;
} Adc_Hw_CommonConfigType;

typedef struct
{
    /*DMA error enable*/
    boolean DmaErrorEn;
    /*DMA transmission count*/
    uint16 DmaTranCount;
} Adc_Hw_DmaConfig;

typedef struct
{
    /*ADC unit*/
    TT_CONST Adc_Hw_HwUnitType AdcHwUnitId;
    /*ADC unit enable*/
    TT_CONST boolean Enable;
    /*wait read enable*/
    TT_CONST boolean WaitRead;
    /*compensation enable*/
    TT_CONST boolean CompenEn;
    /*offset data*/
    TT_CONST int16_t CompenData;
    /*DMA enable*/
    TT_CONST boolean DmaEn;
    /*DMA Irq enable*/
    TT_CONST boolean DmaIntEn;
    /*DMA mode*/
    TT_CONST Adc_Hw_DmaModeType DmaMode;
    /*Sequential sampling queue*/
    TT_CONST uint32 Queue;
    /*conversion of mode*/
    TT_CONST Adc_Hw_CModeType CMode;
    /*callback function*/
    TT_CONST ADC_Hw_Event Event;
} Adc_Hw_HwUnitConfigType;

typedef struct
{
    /*channle id*/
    TT_CONST Adc_Hw_ChannelType ChId;
#ifdef USING_OS_AUTOSAROS
    /*Logical sequence of threshold detection configurations*/
    TT_CONST uint8 LimitLogicId;
#endif
    /*The number of bits to be shifted after oversampling*/
    TT_CONST uint8 Shift;
    /*Oversampling number*/
    TT_CONST uint8 SampNum;
    /*ready interrupt enable*/
    TT_CONST boolean ReadyIntEn;
    /*fast sampling enable*/
    TT_CONST boolean FSampEn;
    /*FIR Enable*/
    TT_CONST boolean FirEn;
    /*high threshold data*/
    TT_CONST uint16 ThresholdH;
    /*low threshold data*/
    TT_CONST uint16 ThresholdL;
    /*The high threshold comparison function was enabled*/
    TT_CONST boolean HCompEn;
    /*The low threshold comparison function was enabled*/
    TT_CONST boolean LCompEn;
    /*The low threshold comparison interrupt was enabled*/
    TT_CONST boolean LCompIntEn;
    /*The high threshold comparison interrupt was enabled*/
    TT_CONST boolean HCompIntEn;
    /*The DMA interrupt trigger signal was enabled*/
    TT_CONST boolean TrgDmaIntEn;
#ifdef A8V2E
    /*The Timeout error interrupt was enabled*/
    TT_CONST boolean TimeoutIntEn;
    /*The comparison error interrupt was enabled*/
    TT_CONST boolean CompIntEn;
#endif
    /*The interrupt trigger signal was enabled*/
    TT_CONST boolean TrgIntEn;
    /*Channel trigger source selection*/
    TT_CONST Adc_Hw_TrigSrcType TrigSrc;
    /*Hardware trigger mode*/
    TT_CONST Adc_Hw_HwTrigSigType TrigEdge;
    /*Cascade trigger selection*/
    TT_CONST Adc_Hw_CTrigType CTrig;
    /*Priority type*/
    TT_CONST Adc_Hw_PriorityType Priority;
    /*DMA configuration*/
    TT_CONST Adc_Hw_DmaConfig DmaConfig;
} Adc_Hw_ChannelConfigType;

/*ADC channel register*/
typedef struct
{
    volatile TT_ADC_AxCHREG_Type *Reg;
} Adc_Hw_Resources;

/*ADC channel register*/
typedef struct
{
    float64 fk;
    float64 fB;
}Adc_Hw_LineEquation;

#endif
