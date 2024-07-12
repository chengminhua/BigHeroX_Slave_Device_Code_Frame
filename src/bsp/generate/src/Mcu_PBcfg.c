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
**  FILENAME     : Mcu_PBcfg.c                                                **
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

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_PBCFG_VENDOR_ID_C                     (1541U)
#define MCU_PBCFG_MODULE_ID_C                     (101U)
#define MCU_PBCFG_INSTANCE_ID_C                   (0U)
#define MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C      (4U)
#define MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C      (4U)
#define MCU_PBCFG_AR_RELEASE_PATCH_VERSION_C      (0U)
#define MCU_PBCFG_SW_MAJOR_VERSION_C              (1U)
#define MCU_PBCFG_SW_MINOR_VERSION_C              (1U)
#define MCU_PBCFG_SW_PATCH_VERSION_C              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_PBCfg.c and Mcu.h file version check */
#if (MCU_PBCFG_VENDOR_ID_C != MCU_VENDOR_ID_H)
    #error "Mcu_PBCfg.c and Mcu.h have different vendor id"
#endif
#if (MCU_PBCFG_MODULE_ID_C != MCU_MODULE_ID_H)
    #error "Mcu_PBCfg.c and Mcu.h have different module id"
#endif
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_PBCFG_AR_RELEASE_PATCH_VERSION_C != MCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_PBCfg.c and Mcu.h are different"
#endif
#if ((MCU_PBCFG_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION_H) || \
     (MCU_PBCFG_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION_H) || \
     (MCU_PBCFG_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_PBCfg.c and Mcu.h are different"
#endif


/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

/******************************************************************************
*                            Private Constants
*******************************************************************************/
/******************************************************************************
*                            Private Variables
*******************************************************************************/

/******************************************************************************
*                            Public Constants
*******************************************************************************/
#ifdef A8V2E  
#endif 

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


static TT_CONST Mcu_Hw_ClockSettingConfigType McuClockSettingConfigData[] =
{
    {
        .CoreClk  = 240000000,
        .IhoClk   = 48000000,
        .EcoClk   = 40000000,
        .EcoDivLP = 1,
        .BusClkHalfCoreEnable = TRUE,
        .APB0ClkHalfBusEnable = FALSE,
        .APB1ClkHalfBusEnable = FALSE,
        .APB2ClkHalfBusEnable = FALSE,
        .APB3ClkHalfBusEnable = FALSE,
        .CanPEUserPLLEnable   = FALSE,
        .CanPeClk         = (40000000 / 1),
        .Sm4ClkDiv        = 2,
        .Sm4ClkRandEn     = FALSE,     
        .SkaClkDiv        = 2,
        .SkaClkRandEn     = FALSE,     
        .HashClkDiv       = 2,
        .HashClkRandEn    = FALSE,     
        .I3c0ClkDiv       = 8,
        .I2s0SClkIntDiv   = 1,
        .I2s0SClkFracDiv  = 1,
        .I2s0MClkIntDiv   = 1,
        .I2s0MClkFracDiv  = 1,
        .EpllClockConfig = NULL_PTR
     }
};

/* Mcu Ram Setting Configuration */
static TT_CONST Mcu_RamSectionSettingConfigType McuRamSectionConfigData[] =
{
    {
        .McuRamDefaultValue         = (uint64)0x0,
        .McuRamSectionBaseAddr      = 0x20100000,
        .McuRamSectionSize          = 0x40000,
        .McuRamSectionWriteSize     = 0x1
    }
};


/* Mcu Ppu Setting Configuration */
static TT_CONST Mcu_Hw_PpuSettingConfigType McuPpuSettingConfigData_McuPPUSettingConf0 =    
{
    .McuPpuAPB1 = 0xFFFFU,
    .McuPpuAPB2 = 0xFFFFU,
    .McuPpuAPB3 = 0xFFFFU,
    .McuPpuAPB4 = 0xFFFFU,
    .McuPpuAPB5 = 0xFFFFU,
    .McuPpuAHB0 = 0xFFFFU,
    .McuPpuAHB1 = 0xFFFFU,
    .McuPpuAHB4 = 0x1U,
    .McuPpuAPB1ConfigLock = FALSE,
    .McuPpuAPB2ConfigLock = FALSE,
    .McuPpuAPB3ConfigLock = FALSE,
    .McuPpuAPB4ConfigLock = FALSE,
    .McuPpuAPB5ConfigLock = FALSE,
    .McuPpuAHB0ConfigLock = FALSE,
    .McuPpuAHB1ConfigLock = FALSE,
    .McuPpuAHB4ConfigLock = FALSE,
    .McuPpuSUAPB1 = (uint32)~0x0U,
    .McuPpuSUAPB2 = (uint32)~0x0U,
    .McuPpuSUAPB3 = (uint32)~0x0U,
    .McuPpuSUAPB4 = (uint32)~0x0U,
    .McuPpuSUAPB5 = (uint32)~0x0U,
    .McuPpuSUAHB0 = (uint32)~0x0U,    
    .McuPpuSUAHB1 = (uint32)~0x0U,    
    .McuPpuSUAHB4 = (uint32)~0x0U    
};

/* Pmu config */

/* Mcu Mode Setting Configuration */
static TT_CONST Mcu_Hw_ModeSettingConfigType McuModeSettingConfigData[] =
{
    {
        .McuOperaMode              = MCU_OP_RUN_MODE,
#ifdef A8V2E  
        .CipherPowerDownEn         = FALSE,    
        .HSMPowerDownEn            = FALSE,    
#endif 
        .McuPpuSettingConfig       = &McuPpuSettingConfigData_McuPPUSettingConf0,    
        .PmuGpioConfigCount        = 0,
        .PmuNmiConfigCount         = 0,
        .PmuGpioConfig             = NULL_PTR,
        .PmuNmiConfig              = NULL_PTR,
        .McuModeID                 = 0
    }    
};

/* Mcu CMU Setting Configuration */
static TT_CONST Mcu_Hw_CmuConfigType McuCmuSettingConfigData[] =
{
    {
        .CmuIndex = 0,
        .CmuTimeoutAlarmEn   = FALSE,
        .CmuLthdAlarmEn      = FALSE,
        .CmuHthdAlarmEn      = FALSE

    },     
    {
        .CmuIndex = 1,
        .CmuTimeoutAlarmEn   = FALSE,
        .CmuLthdAlarmEn      = FALSE,
        .CmuHthdAlarmEn      = FALSE

    },     
    {
        .CmuIndex = 2,
        .CmuTimeoutAlarmEn   = FALSE,
        .CmuLthdAlarmEn      = FALSE,
        .CmuHthdAlarmEn      = FALSE

    },     
    {
        .CmuIndex = 3,
        .CmuTimeoutAlarmEn   = FALSE,
        .CmuLthdAlarmEn      = FALSE,
        .CmuHthdAlarmEn      = FALSE

    },     
    {
        .CmuIndex = 4,
        .CmuTimeoutAlarmEn   = FALSE,
        .CmuLthdAlarmEn      = FALSE,
        .CmuHthdAlarmEn      = FALSE

    }     
};

TT_CONST Mcu_ConfigType McuConfigData =
{
    .McuRamSector            = 1,
    .NumOfClockSetting       = 1,
    .McuRamSettingConfig     = McuRamSectionConfigData,
    .McuPmuCallBack          = NULL_PTR,    
    .McuClockSettingConfig   = McuClockSettingConfigData,
    .McuDefaultRUNModeEnable = TRUE,
    .McuDefaultRUNModeNum    = 0,
    .McuModeSettingConfig    = McuModeSettingConfigData,
#if defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    .DemErrorConfig          =
    {
        {STD_OFF,0}
    },
#endif
    .McuCmuSettingConfig     = McuCmuSettingConfigData,
    .Crc = 29054
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h" 

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus 
}
#endif /* __cplusplus */ 
