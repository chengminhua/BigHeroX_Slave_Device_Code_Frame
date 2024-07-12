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
**  FILENAME     : Gpt_PBcfg.c                                                **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Gpt Driver Configuration Generated File                    **
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
/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/
#define FTM_GLOBAL
#define GPT_FTM_GLOBAL
#include "Gpt.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GPT_PBCFG_VENDOR_ID_C                         1541
#define GPT_PBCFG_MODULE_ID_C                         100
#define GPT_PBCFG_AR_RELEASE_MAJOR_VERSION_C          4
#define GPT_PBCFG_AR_RELEASE_MINOR_VERSION_C          4
#define GPT_PBCFG_AR_RELEASE_PATCH_VERSION_C          0
#define GPT_PBCFG_SW_MAJOR_VERSION_C                  1
#define GPT_PBCFG_SW_MINOR_VERSION_C                  1
#define GPT_PBCFG_SW_PATCH_VERSION_C                  0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gpt_PBcfg.c Gpt.h file version check */
#if (GPT_PBCFG_VENDOR_ID_C != GPT_VENDOR_ID_H)
    #error "Gpt_PBcfg.c and Gpt.h have different vendor id"
#endif

#if (GPT_PBCFG_MODULE_ID_C != GPT_MODULE_ID_H)
    #error "Gpt_PBcfg.c and Gpt.h have different module id"
#endif

#if ((GPT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_PBCFG_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_PBCFG_AR_RELEASE_PATCH_VERSION_C != GPT_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif

#if ((GPT_PBCFG_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION_H) || \
     (GPT_PBCFG_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION_H) || \
     (GPT_PBCFG_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif

/******************************************************************************
*                            Private Variables
*******************************************************************************/
#define GPT_START_SEC_CONFIG_DATA_8
#include "Gpt_MemMap.h"

static TT_CONST uint8 GptFtmHardwareChannelMap[FTM_MODULE_NUMBER] = 
{
    255, 0, 255, 255, 255, 255
};

#define GPT_STOP_SEC_CONFIG_DATA_8
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

static TT_CONST Gpt_FtmChannelConfigType GptFtmChannelConfig[GPT_CHANNEL_CONFIG_NUMBER] =
{
    /* GptChannel_0 */
    {
        .GptFtmHardwareChannel  = FTM1_CHx
    },
};

static TT_CONST Gpt_ChannelConfigType GptChannelConfig[GPT_CHANNEL_CONFIG_NUMBER] =
{
    /* GptChannel_0 */
    {
        .GptChannelMode             = GPT_CH_MODE_CONTINUOUS,
        .GptChannelTickValueMax     = 65535,
        .GptChannelTickFrequency    = 120000000,  
        .GptChannelNotification     = &Gpt_Notification_0
    }
};

static TT_CONST Gpt_FtmModuleConfigType GptFtmModuleConfig[GPT_FTM_MODULE_CONFIG_NUMBER] = 
{
    /* FtmSpecificConfiguration_0 */
    {    
        .GptFtmModule       = FTM1,
        .GptFtmConfRegValue = (uint32)3 << TT_FTM_CONF_BDMMODE_Pos,
        .GptFtmScRegValue   = ((uint32)1 << TT_FTM_SC_CLKS_Pos) | ((uint32)0 << TT_FTM_SC_PS_Pos),
        .GptScuClkControl   = TT_SCU_CLK_CONTROL_FTM1,
        .GptScuLocalRst     = TT_SCU_LOCAL_RST_FTM1
    }
};

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"


/******************************************************************************
*                            Public Variables
*******************************************************************************/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

TT_CONST Gpt_ConfigType GptConfigData =
{
    .GptFtmHardwareChannelMap   = GptFtmHardwareChannelMap,
    .GptChannelConfig           = GptChannelConfig,
    .GptFtmPredefTimerConfig    = NULL_PTR,
    .GptFtmChannelConfig        = GptFtmChannelConfig,
    .GptFtmModuleConfig         = GptFtmModuleConfig,
    .GptCrc                     = 44566U
};

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
