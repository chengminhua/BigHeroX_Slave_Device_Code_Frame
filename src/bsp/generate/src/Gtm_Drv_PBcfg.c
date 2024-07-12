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
**  FILENAME     : Gtm_Drv_PBcfg.c                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Dio Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Drv.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_DRV_PBCFG_VENDOR_ID_C                       1541
#define GTM_DRV_PBCFG_MODULE_ID_C                       221

#define GTM_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define GTM_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C        4
#define GTM_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C        0

#define GTM_DRV_PBCFG_SW_MAJOR_VERSION_C                1
#define GTM_DRV_PBCFG_SW_MINOR_VERSION_C                1
#define GTM_DRV_PBCFG_SW_PATCH_VERSION_C                0


/******************************************************************************
*                       File Version Checks
******************************************************************************/
 /* Gtm_Drv.h Gtm_Drv_PBcfg.c file version check */
#if (GTM_DRV_PBCFG_VENDOR_ID_C != GTM_DRV_VENDOR_ID_H)
    #error "Gtm_Drv.h and Gtm_Drv_PBcfg.c have different vendor ids"
#endif

#if (GTM_DRV_PBCFG_MODULE_ID_C != GTM_DRV_MODULE_ID_H)
    #error "Gtm_Drv.h and Gtm_Drv_PBcfg.c have different module ids"
#endif

#if ((GTM_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C != GTM_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
      (GTM_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C != GTM_DRV_AR_RELEASE_MINOR_VERSION_H) || \
      (GTM_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C != GTM_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.h and Gtm_Drv_PBcfg.c are different"
#endif

#if ((GTM_DRV_PBCFG_SW_MAJOR_VERSION_C != GTM_DRV_SW_MAJOR_VERSION_H) || \
      (GTM_DRV_PBCFG_SW_MINOR_VERSION_C != GTM_DRV_SW_MINOR_VERSION_H) || \
      (GTM_DRV_PBCFG_SW_PATCH_VERSION_C != GTM_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.h and Gtm_Drv_PBcfg.c are different"
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

#define GTM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"




static TT_CONST Tom_ChannelConfigType TomChannelConfig[2] =
{
    {
        .TomHwUnit                        = TOM_0_CH_0,
        .TomChannelOutputSignalLevel      = TOM_LOW,
        .TomChannelCounterValCn0          = 0,
        .TomChannelPeriodCompareValCm0    = 3000,
        .TomChannelDutyCycleCompareValCm1 = 1500,
        .TomChPeriodCompareShadowValSr0   = 3000,
        .TomChDCycCompareShadowValSr1     = 1500,
        .TomChUpdateEnableOnCn0Reset      = TRUE,
        .TomChEnableForceUpdate           = FALSE,
        .TomChResetCn0OnForceUpdate       = TRUE,
        .TomChannelClockSelect            = TOM_FIXED_CLOCK_0,
        .TomChannelCounterCn0Reset        = TOM_ON_COMPARE_MATCH_ON_CH,
        .TomChannelExtCounterCn0Reset     = TOM_TRG_ON_PREV_COMPARE_MATCH,
        .TomChannelTriggerOutput          = TOM_TRIG_FROM_PREVIOUS_CH,
        .TomChannelExtTriggerOutput       = TOM_EXT_TRIG_FROM_PREVIOUS_CH,
        .TomUpdownMode                    = TOM_UPDOWN_BY_CN0_RESET,
        .TomChannelOneShotMode            = FALSE,
        .TomChannelTrigOneShotMode        = FALSE,
        .TomChannelSr0Trigger             = FALSE,
        .TomChannelBitReversalMode        = FALSE,
    },
    {
        .TomHwUnit                        = TOM_0_CH_1,
        .TomChannelOutputSignalLevel      = TOM_LOW,
        .TomChannelCounterValCn0          = 0,
        .TomChannelPeriodCompareValCm0    = 3000,
        .TomChannelDutyCycleCompareValCm1 = 1500,
        .TomChPeriodCompareShadowValSr0   = 3000,
        .TomChDCycCompareShadowValSr1     = 1500,
        .TomChUpdateEnableOnCn0Reset      = TRUE,
        .TomChEnableForceUpdate           = FALSE,
        .TomChResetCn0OnForceUpdate       = TRUE,
        .TomChannelClockSelect            = TOM_FIXED_CLOCK_0,
        .TomChannelCounterCn0Reset        = TOM_ON_COMPARE_MATCH_ON_CH,
        .TomChannelExtCounterCn0Reset     = TOM_TRG_ON_PREV_COMPARE_MATCH,
        .TomChannelTriggerOutput          = TOM_TRIG_FROM_PREVIOUS_CH,
        .TomChannelExtTriggerOutput       = TOM_EXT_TRIG_FROM_PREVIOUS_CH,
        .TomUpdownMode                    = TOM_UPDOWN_BY_CN0_RESET,
        .TomChannelOneShotMode            = FALSE,
        .TomChannelTrigOneShotMode        = FALSE,
        .TomChannelSr0Trigger             = FALSE,
        .TomChannelBitReversalMode        = FALSE,
    }

};


static TT_CONST Tom_TriggersForTgcType TomTriggersForTgc[4] =
{
    {
        .TomTgcTimeBaseTriggerEnable  = FALSE,
        .TomTgcIntTriggerFromChannel0 = FALSE,
        .TomTgcIntTriggerFromChannel1 = FALSE,
        .TomTgcIntTriggerFromChannel2 = FALSE,
        .TomTgcIntTriggerFromChannel3 = FALSE,
        .TomTgcIntTriggerFromChannel4 = FALSE,
        .TomTgcIntTriggerFromChannel5 = FALSE,
        .TomTgcIntTriggerFromChannel6 = FALSE,
        .TomTgcIntTriggerFromChannel7 = FALSE,
        .TomTgcTbuTimebaseSelect      = TOM_TBU_TS0_TIMEBASE,
        .TomTgcTimebaseMatchValue     = 0
    },
    {
        .TomTgcTimeBaseTriggerEnable  = FALSE,
        .TomTgcIntTriggerFromChannel0 = FALSE,
        .TomTgcIntTriggerFromChannel1 = FALSE,
        .TomTgcIntTriggerFromChannel2 = FALSE,
        .TomTgcIntTriggerFromChannel3 = FALSE,
        .TomTgcIntTriggerFromChannel4 = FALSE,
        .TomTgcIntTriggerFromChannel5 = FALSE,
        .TomTgcIntTriggerFromChannel6 = FALSE,
        .TomTgcIntTriggerFromChannel7 = FALSE,
        .TomTgcTbuTimebaseSelect      = TOM_TBU_TS0_TIMEBASE,
        .TomTgcTimebaseMatchValue     = 0
    },
    {
        .TomTgcTimeBaseTriggerEnable  = FALSE,
        .TomTgcIntTriggerFromChannel0 = FALSE,
        .TomTgcIntTriggerFromChannel1 = FALSE,
        .TomTgcIntTriggerFromChannel2 = FALSE,
        .TomTgcIntTriggerFromChannel3 = FALSE,
        .TomTgcIntTriggerFromChannel4 = FALSE,
        .TomTgcIntTriggerFromChannel5 = FALSE,
        .TomTgcIntTriggerFromChannel6 = FALSE,
        .TomTgcIntTriggerFromChannel7 = FALSE,
        .TomTgcTbuTimebaseSelect      = TOM_TBU_TS0_TIMEBASE,
        .TomTgcTimebaseMatchValue     = 0
    },
    {
        .TomTgcTimeBaseTriggerEnable  = FALSE,
        .TomTgcIntTriggerFromChannel0 = FALSE,
        .TomTgcIntTriggerFromChannel1 = FALSE,
        .TomTgcIntTriggerFromChannel2 = FALSE,
        .TomTgcIntTriggerFromChannel3 = FALSE,
        .TomTgcIntTriggerFromChannel4 = FALSE,
        .TomTgcIntTriggerFromChannel5 = FALSE,
        .TomTgcIntTriggerFromChannel6 = FALSE,
        .TomTgcIntTriggerFromChannel7 = FALSE,
        .TomTgcTbuTimebaseSelect      = TOM_TBU_TS0_TIMEBASE,
        .TomTgcTimebaseMatchValue     = 0
    }

};

static TT_CONST Tom_ConfigType TomConfig =
{

    .TomTriggersForTgc =  TomTriggersForTgc,
    .TomChannelConfig  =  TomChannelConfig
};



/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/
/* Tom register information */
volatile GTM_TOM_bf_type *Tom_PubReg[2] = {&TT_GTM->TOM0, &TT_GTM->TOM1};
/* Tim register information */
volatile GTM_TIM_bf_type* Tim_PubReg[3] = {&TT_GTM->TIM0, &TT_GTM->TIM1, &TT_GTM->TIM2};
/* Tim register information */
volatile GTM_CDTM_bf_type *Cdtm_PubReg[4] = {&TT_GTM->CDTM0, &TT_GTM->CDTM1, &TT_GTM->CDTM2, &TT_GTM->CDTM3};




TT_CONST Gtm_ConfigType GtmConfigData =
{
    .TbuConfig            = NULL_PTR,
    .TomConfig            = NULL_PTR,
    .TimConfig            = NULL_PTR,
    .GtmConnectionsConfig = NULL_PTR,
    .Crc                  = 8218U
};

#define GTM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"

#ifdef __cplusplus
}
#endif


/** @} */


