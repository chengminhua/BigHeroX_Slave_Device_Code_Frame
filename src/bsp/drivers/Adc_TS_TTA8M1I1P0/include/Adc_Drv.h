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
**  FILENAME     : Adc_Drv.h                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef ADC_Drv_H
#define ADC_Drv_H

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Adc_Drv_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define ADC_DRV_VENDOR_ID_H                    1541
#define ADC_DRV_MODULE_ID_H                    123
#define ADC_DRV_INSTANCE_ID_H                  0
#define ADC_DRV_AR_RELEASE_MAJOR_VERSION_H     4
#define ADC_DRV_AR_RELEASE_MINOR_VERSION_H     4
#define ADC_DRV_AR_RELEASE_PATCH_VERSION_H     0
#define ADC_DRV_SW_MAJOR_VERSION_H             1
#define ADC_DRV_SW_MINOR_VERSION_H             1
#define ADC_DRV_SW_PATCH_VERSION_H             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Adc_Drv.c Adc_Drv_Types.h file version check */
#if (ADC_DRV_VENDOR_ID_H != ADC_DRV_TYPES_VENDOR_ID_H)
    #error "Adc_Drv.c and Adc_Drv_Types.h have different vendor ids"
#endif

#if (ADC_DRV_MODULE_ID_H != ADC_DRV_TYPES_MODULE_ID_H)
    #error "Adc_Drv.c and Adc_Drv_Types.h have different module ids"
#endif

#if (ADC_DRV_INSTANCE_ID_H != ADC_DRV_TYPES_INSTANCE_ID_H)
    #error "Adc_Drv.c and Adc_Drv_Types.h have different Instance ids"
#endif

#if ((ADC_DRV_AR_RELEASE_MAJOR_VERSION_H != ADC_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_DRV_AR_RELEASE_MINOR_VERSION_H != ADC_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_DRV_AR_RELEASE_PATCH_VERSION_H != ADC_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Drv.c and Adc_Drv_Types.h are different"
#endif

#if ((ADC_DRV_SW_MAJOR_VERSION_H != ADC_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (ADC_DRV_SW_MINOR_VERSION_H != ADC_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (ADC_DRV_SW_PATCH_VERSION_H != ADC_DRV_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Drv.c and Adc_Drv_Types.h are different"
#endif

/******************************************************************************
*                            Public Variables
*******************************************************************************/
/*Global variable declaration of configuration information*/
extern TT_CONST Adc_Drv_ConfigType *AdcDrv_PubConfigSet;
extern TT_CONST Adc_Hw_HwUnitConfigType *AdcHw_PubConfigSet;

#ifdef ADC_PRECOMPILE_SUPPORT
extern TT_CONST Adc_Drv_ConfigType AdcDrvConfigData;
#endif

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
 *  Service name    : Adc_Drv_Init
 *  Syntax          : TT_RetType Adc_Drv_Init(TT_CONST Adc_Drv_ConfigType *ConfigPtr)
 *  Service ID      : 100
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : ConfigPtr : Configuration information
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to initialize the ADC.
 ********************************************************************************/
TT_RetType Adc_Drv_Init (TT_CONST Adc_Drv_ConfigType *ConfigPtr);

/******************************************************************************
 *  Service name    : Adc_Drv_DeInit
 *  Syntax          : TT_RetType Adc_Drv_DeInit(TT_CONST Adc_Drv_HwUnitType HwUnit)
 *  Service ID      : 101
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : HwUnit : Hardware unit ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to deinitializes the ADC.
 ********************************************************************************/
TT_RetType Adc_Drv_DeInit (TT_CONST Adc_Drv_HwUnitType HwUnit);

/******************************************************************************
 *  Service name    : Adc_Drv_ChannelConfig
 *  Syntax          : TT_RetType Adc_Drv_ChannelConfig(TT_CONST Adc_Drv_ChannelType AdcChannel)
 *  Service ID      : 102
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to configure channels.
 ********************************************************************************/
TT_RetType Adc_Drv_ChannelConfig (TT_CONST Adc_Drv_ChannelType AdcChannel);

/******************************************************************************
 *  Service name    : Adc_Drv_StartConversion
 *  Syntax          : TT_RetType Adc_Drv_StartConversion(TT_CONST Adc_Drv_ChannelType AdcChannel)
 *  Service ID      : 103
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to start conversion.
 ********************************************************************************/
TT_RetType Adc_Drv_StartConversion (TT_CONST Adc_Drv_ChannelType AdcChannel);

/******************************************************************************
 *  Service name    : Adc_Drv_GetGlobalState
 *  Syntax          : TT_RetType Adc_Drv_GetGlobalState(TT_CONST Adc_Drv_HwUnitType HwUnit,uint32 *Value)
 *  Service ID      : 104
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : HwUnit: Adc Unit Id
 *  Parameters (out): Value : Gets a pointer to the state
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to get ADC unit global state.
 ********************************************************************************/
TT_RetType Adc_Drv_GetGlobalState (TT_CONST Adc_Drv_HwUnitType HwUnit,
                                   uint32 *Value);

/******************************************************************************
 *  Service name    : Adc_Drv_GetCurrentState
 *  Syntax          : TT_RetType Adc_Drv_GetCurrentState(TT_CONST Adc_Drv_HwUnitType HwUnit,uint32 *Value)
 *  Service ID      : 105
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : HwUnit: Adc Unit Id
 *  Parameters (out): Value : Gets a pointer to the state
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to obtain the current state of the ADC hardware.
 ********************************************************************************/
TT_RetType Adc_Drv_GetCurrentState (TT_CONST Adc_Drv_HwUnitType HwUnit,
                                    uint32 *Value);

/******************************************************************************
 *  Service name    : Adc_Drv_GetChannelState
 *  Syntax          : TT_RetType Adc_Drv_GetChannelState(TT_CONST Adc_Drv_ChannelType AdcChannel,uint32 *Value)
 *  Service ID      : 106
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): Value : Gets a pointer to the state
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to get channel state.
 ********************************************************************************/
TT_RetType Adc_Drv_GetChannelState (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                    uint32 *Value);

/******************************************************************************
 *  Service name    : Adc_Drv_GetValue
 *  Syntax          : TT_RetType Adc_Drv_GetValue(TT_CONST Adc_Drv_ChannelType AdcChannel,uint16 *Value)
 *  Service ID      : 107
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): Value      : sample data
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to get channel sample data.
 ********************************************************************************/
TT_RetType Adc_Drv_GetValue (TT_CONST Adc_Drv_ChannelType AdcChannel,
                             uint16 *Value);

/******************************************************************************
 *  Service name    : Adc_Drv_SetDmaBUffer
 *  Syntax          : TT_RetType Adc_Drv_SetDmaBUffer(TT_CONST Adc_Drv_ChannelType AdcChannel,uint32 *Result)
 *  Service ID      : 108
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Result     : DMA result address
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to set channel DMA result buffer.
 ********************************************************************************/
TT_RetType Adc_Drv_SetDmaBuffer (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                 TT_CONST uint16 *Result);

/******************************************************************************
 *  Service name    : Adc_Drv_SetDmaIncraddr
 *  Syntax          : TT_RetType Adc_Drv_SetDmaIncraddr(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST uint32 Incraddr)
 *  Service ID      : 109
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Result     : DMA result address
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to set channel Address increment.
 ********************************************************************************/
TT_RetType Adc_Drv_SetDmaIncraddr (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                   TT_CONST uint32 Incraddr);

/******************************************************************************
 *  Service name    : Adc_Drv_StopConversion
 *  Syntax          : TT_RetType Adc_Drv_StopConversion(TT_CONST Adc_Drv_HwUnitType HwUnit,TT_CONST Adc_Drv_StopModeType StopMode)
 *  Service ID      : 110
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : HwUnit     : Hardware ID
 *                    StopMode   : ADC Hardware stop mode
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to stop ADC hardware sampling.
 ********************************************************************************/
TT_RetType Adc_Drv_StopConversion (TT_CONST Adc_Drv_HwUnitType HwUnit,
                                   TT_CONST Adc_Drv_StopModeType StopMode);

/******************************************************************************
 *  Service name    : Adc_Drv_ClearGlobalState
 *  Syntax          : TT_RetType Adc_Drv_ClearGlobalState(TT_CONST Adc_Drv_ChannelType AdcChannel,boolean DmaClear)
 *  Service ID      : 111
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
*  Parameters (in) : AdcChannel : Hardware channel ID
*                    DmaClear   : clear DMA flag
 *  Parameters (out): NON
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to clear the ADC unit state.
 ********************************************************************************/
TT_RetType Adc_Drv_ClearGlobalState(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST boolean DmaClear);

/******************************************************************************
 *  Service name    : Adc_Drv_EnableHwTrig
 *  Syntax          : TT_RetType Adc_Drv_EnableHwTrig(TT_CONST Adc_Drv_ChannelType AdcChannel)
 *  Service ID      : 112
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to enable Hw trigger.
 ********************************************************************************/
TT_RetType Adc_Drv_EnableHwTrig (TT_CONST Adc_Drv_ChannelType AdcChannel);

/******************************************************************************
 *  Service name    : Adc_Drv_DisableHwTrig
 *  Syntax          : TT_RetType Adc_Drv_DisableHwTrig(TT_CONST Adc_Drv_ChannelType AdcChannel)
 *  Service ID      : 113
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): NON
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to enable Hw trigger.
 ********************************************************************************/
TT_RetType Adc_Drv_DisableHwTrig (TT_CONST Adc_Drv_ChannelType AdcChannel);

/******************************************************************************
 *  Service name    : Adc_Drv_SetSequence
 *  Syntax          : TT_RetType Adc_Drv_SetSequence(TT_CONST Adc_Drv_HwUnitType HwUnit,TT_CONST uint32 Queue)
 *  Service ID      : 114
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : HwUnit : ADC Hardware ID
 *  					 Queue  : Queue data,four bits representing a channel, low transmission first
 *  Parameters (out): NON
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to set the sequence sampling sequence.
 ********************************************************************************/
TT_RetType Adc_Drv_SetSequence (TT_CONST Adc_Drv_HwUnitType HwUnit,
                                TT_CONST uint32 Queue);

/******************************************************************************
 *  Service name    : Adc_Drv_SetCTrigger
 *  Syntax          : TT_RetType Adc_Drv_SetCTrigger(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST Adc_Drv_CTrigType NextChannel)
 *  Service ID      : 115
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  					 NextChannel: ID of the next channel triggered by cascade
 *  Parameters (out): NON
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to set cascade trigger.
 ********************************************************************************/
TT_RetType Adc_Drv_SetCTrigger (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                TT_CONST Adc_Drv_CTrigType NextChannel);

/******************************************************************************
 *  Service name    : Adc_Drv_SetDmaTransCount
 *  Syntax          : TT_RetType Adc_Drv_SetDmaTransCount(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST uint8 Cnt)
 *  Service ID      : 116
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Cnt     : DMA Transmission count
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to set DMA Transmission count.
 ********************************************************************************/
TT_RetType Adc_Drv_SetDmaTransCount (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                     TT_CONST uint8 Cnt);

/******************************************************************************
 *  Service name    : Adc_Drv_SetTrigger
 *  Syntax          : TT_RetType Adc_Drv_SetTrigger(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST Adc_Drv_TrigSrcType TrigSrc,TT_CONST Adc_Drv_HwTrigSigType TrigSig)
 *  Service ID      : 117
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    TrigSrc    : Trigger source
 *                    TrigSig    : Trigger Edge
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to set Trigger.
 ********************************************************************************/
TT_RetType Adc_Drv_SetTrigger (TT_CONST Adc_Drv_ChannelType AdcChannel,
                               TT_CONST Adc_Drv_TrigSrcType TrigSrc,
                               TT_CONST Adc_Drv_HwTrigSigType TrigSig);

/******************************************************************************
 *  Service name    : Adc_Drv_SetReadyIntEn
 *  Syntax          : TT_RetType Adc_Drv_SetDmaTransCount(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST uint8 Enable)
 *  Service ID      : 118
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Enable     : Ready interrupt enable
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other:           Failure
 *  Description     : This service is used to set Ready interrupt enable.
 ********************************************************************************/
TT_RetType Adc_Drv_SetReadyIntEn (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                  TT_CONST uint8 Enable);

/******************************************************************************
 *  Service name    : Adc_Hw_PriorityType Pri
 *  Syntax          : TT_RetType Adc_Drv_SetPriority(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST Adc_Hw_PriorityType Pri)
 *  Service ID      : 119
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Pri    	: Channel priority
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set Ready interrupt enable.
 ********************************************************************************/
TT_RetType Adc_Drv_SetPriority (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                TT_CONST Adc_Drv_PriorityType Pri);

/******************************************************************************
 *  Service name    : Adc_Drv_SetDmaEn
 *  Syntax          : TT_RetType Adc_Drv_SetDmaEn(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST boolean Enable,TT_CONST boolean IntEnable)
 *  Service ID      : 120
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Enable     : DMA enable
 *                    IntEnable  : DMA Int enable
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set Ready interrupt enable.
 ********************************************************************************/
TT_RetType Adc_Drv_SetDmaEn (TT_CONST Adc_Drv_ChannelType AdcChannel,
                             TT_CONST boolean Enable, TT_CONST boolean IntEnable);

/******************************************************************************
 *  Service name    : Adc_Drv_ClearGlobalStateInMask
 *  Syntax          : TT_RetType Adc_Drv_ClearGlobalStateInMask(TT_CONST Adc_Drv_HwUnitType HwUnit, TT_CONST uint32 Cl_Mask)
 *  Service ID      : 122
 *  Sync/Async      : Synchronous
 *  Reentrancy      : None
 *  Parameters (in) : HwUnit : ADC Hardware ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : Use the write mask to clear the flag.
 ********************************************************************************/
TT_RetType Adc_Drv_ClearGlobalStateInMask(TT_CONST Adc_Drv_HwUnitType HwUnit, TT_CONST uint32 Cl_Mask);

/******************************************************************************
 *  Service name    : Adc_GetVersionInfo
 *  Syntax          : void Adc_Drv_GetVersionInfo (Std_VersionInfoType* version info)
 *  Service ID      : 121
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : None
 *  Parameters (out): versioninfo - Pointer to where to store the version information of this module.
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : Returns the version information of this module.
 ******************************************************************************/
TT_RetType Adc_Drv_GetVersionInfo (Std_VersionInfoType *versioninfo);

#endif

