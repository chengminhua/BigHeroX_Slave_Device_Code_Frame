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
**  FILENAME     : Mcu_Types.h                                                **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Mcu Types Source File                                      **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef MCU_TYPES_H
#define MCU_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Drv_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_TYPES_VENDOR_ID_H                     1541
#define MCU_TYPES_MODULE_ID_H                     101
#define MCU_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_TYPES_SW_MAJOR_VERSION_H              1
#define MCU_TYPES_SW_MINOR_VERSION_H              1
#define MCU_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Types.h and Mcu_Drv_Types.h file version check */
#if (MCU_TYPES_VENDOR_ID_H != MCU_DRV_TYPES_VENDOR_ID_H)
    #error "Mcu_Types.h and Mcu_Drv_Types.h have different vendor id"
#endif
#if (MCU_TYPES_MODULE_ID_H != MCU_DRV_TYPES_MODULE_ID_H)
    #error "Mcu_Types.h and Mcu_Drv_Types.h have different module id"
#endif
#if ((MCU_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Typesv.h and Mcu_Drv_Types.h are different"
#endif
#if ((MCU_TYPES_SW_MAJOR_VERSION_H != MCU_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_TYPES_SW_MINOR_VERSION_H != MCU_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_TYPES_SW_PATCH_VERSION_H != MCU_DRV_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Types.h and Mcu_Drv_Types.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Macro definitions for API Service ID */
#define MCU_SI_INIT                         0x00U /* Service ID for MCU_Init API */
#define MCU_SI_INITRAMSECTION               0x01U /* Service ID for MCU_InitRamSection API */
#define MCU_SI_INITCLOCK                    0x02U /* Service ID for MCU_InitClock API */
#define MCU_SI_DISTRIBUTEPLLCLK             0x03U /* Service ID for MCU_DistributePllClock API */
#define MCU_SI_GETPLLSTATUS                 0x04U /* Service ID for MCU_GetPllStatus API */
#define MCU_SI_GETRESETREASON               0x05U /* Service ID for MCU_GetResetReason API */
#define MCU_SI_GETRESETRAWVAL               0x06U /* Service ID for MCU_GetResetRawValue API */
#define MCU_SI_PERFORMRESET                 0x07U /* Service ID for MCU_PerformReset API */
#define MCU_SI_SETMODE                      0x08U /* Service ID for MCU_SetMode API */
#define MCU_SI_GETVERSIONINFO               0x09U /* Service ID for MCU_GetVersionInfo API */
#define MCU_SI_GETRAMSTATE                  0x0AU /* Service ID for MCU_GetRamState API */
#define MCU_SI_GETPERIPHERALCLKFREQ         0x0BU /* Service ID for MCU_GetPeripheralClkFreq API */

/* Macro definitions for Error Codes specified by AUTOSAR */
#define MCU_E_PARAM_CONFIG                  0x0AU /* API service called with wrong parameter */
#define MCU_E_PARAM_CLOCK                   0x0BU /* API service called with wrong parameter */
#define MCU_E_PARAM_MODE                    0x0CU /* API service called with wrong parameter */
#define MCU_E_PARAM_RAMSECTION              0x0DU /* API service called with wrong parameter */
#define MCU_E_PLL_NOT_LOCKED                0x0EU /* API service called when PLL status is not locked */
#define MCU_E_UNINIT                        0x0FU /* API service used without module initialisation */
#define MCU_E_PARAM_POINTER                 0x10U /* APIs called with a Null Pointer */
#define MCU_E_INIT_FAILED                   0x11U /* API service used when initalisation failed */

/******************************************************************************
*                            Enums
*******************************************************************************/
/* SWS_Mcu_00250 */
/* Pll status type */
typedef enum
{
    MCU_PLL_LOCKED,
    MCU_PLL_UNLOCKED,
    MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

/* SWS_Mcu_00252 */
/* reset type */
typedef enum
{
    MCU_POWER_ON_RESET,
    MCU_LOWER_POWER_RESET,
    MCU_RSTB_PIN_RESET,
    MCU_BIST_FAIL_RESET,
    MCU_BIST_SUCCESS_RESET,
    MCU_SMU_ALARM_RESET,
    MCU_SOFT_RESET,
    MCU_RESET_UNDEFINED,

    MCU_SYSTEM_STABLE = 30,
    MCU_SYSTEM_ACTIVE
} Mcu_ResetType;

/* SWS_Mcu_00256 */
/* Ram status type */
#if defined(MCU_GET_RAM_STATE_API) && (MCU_GET_RAM_STATE_API == STD_ON)
typedef enum
{
    MCU_RAMSTATE_INVALID,
    MCU_RAMSTATE_VALID
} Mcu_RamStateType;
#endif
/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* SWS_Mcu_00251 */
/* Mcu Clock type */
typedef uint8 Mcu_ClockType;

/* SWS_Mcu_00253 */
/* Raw Reset type */
typedef uint32 Mcu_RawResetType;

/* SWS_Mcu_00255 */
/* Ram Section type */
typedef uint8 Mcu_RamSectionType;

/* Ram Section Structure Definitions */
typedef struct
{
    uint64 McuRamDefaultValue;         /* Ram Default Value */
    uint32 McuRamSectionBaseAddr;      /* Ram Section Base Address */
    uint32 McuRamSectionSize;          /* Ram Section Size */
    uint32 McuRamSectionWriteSize;     /* Ram Section Write Size */
} Mcu_RamSectionSettingConfigType;

/* Dem Error type */
#if defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
typedef struct
{
    Mcal_DemErrorType ErrorClockFailureCfg;
}Mcu_DemConfigType;
#endif

/* SWS_Mcu_00249 */
/* Mcu Config */
typedef struct
{
    uint8                                   McuRamSector;              /* Ram Section  */
    uint8                                   NumOfClockSetting;         /* Clock Setting Number */
    uint8                                   McuDefaultRUNModeNum;      /* Default Rum Mode Number */
    boolean                                 McuDefaultRUNModeEnable;   /* Default Rum Mode Enable */
    TT_Notification                         McuPmuCallBack;            /* Pmu CallBack Function Pointer */

    TT_CONST Mcu_RamSectionSettingConfigType   *McuRamSettingConfig;   /* Ram Setting Config */
    TT_CONST Mcu_Hw_ClockSettingConfigType     *McuClockSettingConfig; /* Clock Setting Config */
    TT_CONST Mcu_Hw_ModeSettingConfigType      *McuModeSettingConfig;  /* Mode Setting Config */
    TT_CONST Mcu_Hw_CmuConfigType              *McuCmuSettingConfig;   /* Cmu Setting Config */

#if defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    TT_CONST Mcu_DemConfigType DemErrorConfig;                         /* Dem Error Config */
#endif
    TT_CONST uint32  Crc;                                              /* Crc */
} Mcu_ConfigType;

/* Mcu Status Type */
typedef struct
{
    boolean                 initialized;                               /* Init Flag */
    boolean                 Clkinitialized;                            /* Clock Init Flag */
    Mcu_ClockType           ClockSetting;                              /* Clock Setting Number */
    TT_CONST Mcu_ConfigType *ConfigPtr;                                /* Mcu Config */
    uint32                  EcoClk;                                    /* Eco Clock Default 40M */
    uint32                  IhoClk;                                    /* Eco Clock Default 48M */
} Mcu_StatusType;

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Mcu Config Data */
extern TT_CONST Mcu_ConfigType McuConfigData;

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MCU_TYPES_H */
