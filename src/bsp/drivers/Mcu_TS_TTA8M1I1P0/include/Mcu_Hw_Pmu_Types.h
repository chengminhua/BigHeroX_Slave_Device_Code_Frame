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
**  FILENAME     : Mcu_Hw_Pmu_Types.h                                         **
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
#ifndef MCU_HW_PMU_TYPES_H
#define MCU_HW_PMU_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Hw_Ppu_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_PMU_TYPES_VENDOR_ID_H                     1541
#define MCU_HW_PMU_TYPES_MODULE_ID_H                     101
#define MCU_HW_PMU_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_PMU_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_PMU_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_PMU_TYPES_SW_MAJOR_VERSION_H              1
#define MCU_HW_PMU_TYPES_SW_MINOR_VERSION_H              1
#define MCU_HW_PMU_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Pmu_Types.h and Mcu_Hw_Ppu_Types.h file version check */
#if (MCU_HW_PMU_TYPES_VENDOR_ID_H != MCU_HW_PPU_TYPES_VENDOR_ID_H)
    #error "Mcu_Hw_Pmu_Types.h and Mcu_Hw_Ppu_Types.h have different vendor id"
#endif
#if (MCU_HW_PMU_TYPES_MODULE_ID_H != MCU_HW_PPU_TYPES_MODULE_ID_H)
    #error "Mcu_Hw_Pmu_Types.h and Mcu_Hw_Ppu_Types.h have different module id"
#endif
#if ((MCU_HW_PMU_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PMU_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Pmu_Types.h and Mcu_Hw_Ppu_Types.h are different"
#endif
#if ((MCU_HW_PMU_TYPES_SW_MAJOR_VERSION_H != MCU_HW_PPU_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_TYPES_SW_MINOR_VERSION_H != MCU_HW_PPU_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_HW_PMU_TYPES_SW_PATCH_VERSION_H != MCU_HW_PPU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Pmu_Types.h and Mcu_Hw_Ppu_Types.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define MCU_PMU_USER_MAX                (1U)                             /* Pmu User maximun index  */
#define MCU_PMU_OSC_DIV_MIN             (1U)                             /* Osc minimum division  */
#define MCU_PMU_OSC_DIV_MAX             (16U)                            /* Osc maximun division  */
/******************************************************************************
*                            Enums
*******************************************************************************/
/* Mcu Lower Power Mode */
typedef enum
{
    MCU_OP_RUN_MODE,
    MCU_OP_SLEEP_MODE,
    MCU_OP_STANDBY_MODE
}Mcu_Hw_OperatingModeType;

/* Mcu Power Down Type */
typedef enum
{
    MCU_OP_HSM,
    MCU_OP_CIPHER
}Mcu_Hw_PowerDownType;
/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* SWS_Mcu_00254 */
typedef uint8 Mcu_ModeType;

/* Pmu Gpio Config */
typedef struct
{
    uint32 Number           : 8;                                        /* gpio number 0~31 */
    uint32 InputEn          : 1;                                        /* gpio input enable */
    uint32 InputFilterEn    : 1;                                        /* gpio input filter enable */
    uint32 InputPullUpEn    : 1;                                        /* gpio output pullup enable */
    uint32 InputPullDownEn  : 1;                                        /* gpio output pulldown enable */
    uint32 InputEdgeRiseEn  : 1;                                        /* gpio input edge rising enable */
    uint32 InputEdgeFallEn  : 1;                                        /* gpio input edge falling enable */
    uint32 InputIntReqEn    : 1;                                        /* gpio input interrupt request enable */
    uint32 InputWakeReqEn   : 1;                                        /* gpio input wakeup request enable */
    uint32 OutEn            : 1;                                        /* gpio output enable */
    uint32 OutData          : 1;                                        /* gpio output data value (low or high) */
    uint32 Reserve          : 14;
}Mcu_Hw_PmuGpioConfigType;

/* Nmi Gpio Config */
typedef struct
{
    uint32 NmiEn             : 1;
    uint32 InputFilterEn     : 1;                                        /* NMI input filter enable */
    uint32 InputEdgeRiseEn   : 1;                                        /* NMI input edge rising enable */
    uint32 InputEdgeFallEn   : 1;                                        /* NMI input edge falling enable */
    uint32 InputWakeReqEn    : 1;                                        /* NMI input wakeup request enable */
#ifdef A8V2E
    uint32 InputFastFilterEn : 1;                                        /* NMI input Fast filter enable */
    uint32 FastFilterCount   : 8;                                        /* NMI input Fast process filter count */
    uint32 Reserve           : 18;
#else
    uint32 Reserve           : 27;
#endif
}Mcu_Hw_PmuNmiConfigType;

/* Peripheral sleep clock config */
typedef struct
{
    uint32 McuPeriphtClockSleepConfig0;                                  /* Peripheral Sleep Clock */
    uint32 McuPeriphtClockSleepConfig1;                                  /* Peripheral Sleep Clock */
    uint32 McuPeriphtClockSleepConfig2;                                  /* Peripheral Sleep Clock */
    uint32 McuCanClockSleep;                                             /* Can Sleep Clock */
    uint32 McuLinClockSleep;                                             /* Lin Sleep Clock */
}Mcu_Hw_PeriphClockConfigType;

/* Mcu Mode Setting config */
typedef struct
{
    boolean                                CipherPowerDownEn;            /* Cipher power down enable */
    boolean                                HSMPowerDownEn;               /* Hsm power down enable */
    boolean                                FlashPowerDownEn;             /* Flash power down enable */
    boolean                                IHOPowerDownEn;               /* Iho power down enable */
    boolean                                ECOPowerDownEn;               /* Eco power down enable */
#ifdef A8V2E
    boolean                                RstbWakupEn;                  /* Rstb wakup enable */
#endif
    Mcu_ModeType                           McuModeID;                    /* Mcu mode id */
    Mcu_Hw_OperatingModeType               McuOperaMode;                 /* Mcu opera mode */
    uint32                                 OSCDiv;                       /* Osc division */
    uint32                                 PmuGpioConfigCount;           /* Gpio config Count */
    uint32                                 PmuNmiConfigCount;            /* Nmi config Count */
    TT_CONST Mcu_Hw_PmuGpioConfigType      *PmuGpioConfig;               /* Gpio config */
    TT_CONST Mcu_Hw_PmuNmiConfigType       *PmuNmiConfig;                /* Nmi config */
    TT_CONST Mcu_Hw_PpuSettingConfigType   *McuPpuSettingConfig;         /* Ppu config */
    TT_CONST Mcu_Hw_PeriphClockConfigType  *McuPeriphSleepClockConfig;   /* Peripheral sleep clock config */
}Mcu_Hw_ModeSettingConfigType;
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

#endif /* MCU_HW_PMU_TYPES_H */
