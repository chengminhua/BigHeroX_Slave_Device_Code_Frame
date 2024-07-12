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
**  FILENAME     : Gtm_Drv.h                                                  **
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
#ifndef GTM_DRV_H
#define GTM_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Drv_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_DRV_VENDOR_ID_H                      1541
#define GTM_DRV_MODULE_ID_H                      221
#define GTM_DRV_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_DRV_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_DRV_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_DRV_SW_MAJOR_VERSION_H               1
#define GTM_DRV_SW_MINOR_VERSION_H               1
#define GTM_DRV_SW_PATCH_VERSION_H               0


/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Drv.h Gtm_Drv_Types.h file version check */
#if (GTM_DRV_TYPES_VENDOR_ID_H != GTM_DRV_VENDOR_ID_H)
    #error "Gtm_Drv.h and Gtm_Drv_Types.h have different vendor ids"
#endif

#if (GTM_DRV_TYPES_MODULE_ID_H != GTM_DRV_MODULE_ID_H)
    #error "Gtm_Drv.h and Gtm_Drv_Types.h have different module ids"
#endif

#if ((GTM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.h and Gtm_Drv_Types.h are different"
#endif

#if ((GTM_DRV_TYPES_SW_MAJOR_VERSION_H != GTM_DRV_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_MINOR_VERSION_H != GTM_DRV_SW_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_PATCH_VERSION_H != GTM_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.h and Gtm_Drv_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
extern TT_CONST Gtm_ConfigType GtmConfigData;

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
/******************************************************************************
*  Service name     : Gtm_Drv_Init
*  Syntax           : TT_RetType Gtm_Drv_Init(TT_CONST Gtm_ConfigType *ConfigPtr)
*  Service ID       : 100
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : ConfigPtr : Configuration data pointer
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : This service is used to initialize the GTM module.
******************************************************************************/
TT_RetType Gtm_Drv_Init(TT_CONST Gtm_ConfigType *ConfigPtr);

/******************************************************************************
 *  Service name     : Gtm_Drv_DeInit
 *  Syntax           : TT_RetType Gtm_Drv_DeInit(void)
 *  Service ID       : 101
 *  Sync/Async       : Synchronous
 *  Reentrancy       : Non reentrant
 *  Parameters (in)  : ConfigPtr : Configuration data pointer
 *  Parameters (out) : None
 *  Return value     : TT_RET_SUCCESS: accepted
 *                     Other         : not been accepted
 *  Description      : This service shall de-initialize GTM hardware peripheral and global variables
 ******************************************************************************/
TT_RetType Gtm_Drv_DeInit(void);

/******************************************************************************
*  service name     : Gtm_Drv_CmuStart
*  Syntax           : TT_RetType Gtm_Drv_CmuStart(void)
*  Service ID       : 102
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Start the Cmu clock.
******************************************************************************/
TT_RetType Gtm_Drv_CmuStart(void);

/******************************************************************************
*  service name     : Gtm_Drv_CmuStop
*  Syntax           : TT_RetType Gtm_Drv_CmuStop(void)
*  Service ID       : 103
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Stop the Cmu clock.
******************************************************************************/
TT_RetType Gtm_Drv_CmuStop(void);

/******************************************************************************
*  service name     : Gtm_Drv_CmuGetClock
*  Syntax           : TT_RetType Gtm_Drv_CmuGetClock( Gtm_CmuClkSourceType ClockSource, uint8 ClockIndex, float64 *Clk)
*  Service ID       : 104
*  Reentrancy       : Reentrant
*  Parameters (in)  : clock_source : GTM CMU clock source type (cluster cfgu, fixed and external clock subunit)
*  Parameters (in)  : clock_index  : GTM CMU clock index (index of the subunit clock)
*  Parameters (out) : Clk          : Save the read clock frequency
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the clock frequency of the specified clock source.
******************************************************************************/
TT_RetType Gtm_Drv_CmuGetClock(CmuClkSourceType ClockSource, uint8 ClockIndex, float64 *Clk);

/******************************************************************************
*  service name     : Gtm_Drv_CmuSetClock
*  Syntax           : TT_RetType Gtm_Drv_CmuSetClock(Gtm_CmuClkSourceType ClockSource,uint8 ClockIndex, uint32 ClockFreqOrDiv)
*  Service ID       : 105
*  Reentrancy       : Reentrant
*  Parameters (in)  : ClockSource    : GTM CMU clock source type (cluster cfgu, fixed and external clock subunit)
*  Parameters (in)  : ClockIndex     : GTM CMU clock index (index of the subunit clock)
*  Parameters (in)  : ClockFreqOrDiv : Clock frequency of the clock source to be set
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the clock frequency of the specified clock source.
******************************************************************************/
TT_RetType Gtm_Drv_CmuSetClock(CmuClkSourceType ClockSource,uint8 ClockIndex, uint32 ClockFreqOrDiv);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuStart
*  Syntax           : TT_RetType Gtm_Drv_TbuStart(void)
*  Service ID       : 106
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Start all configured channels of the TBU.
******************************************************************************/
TT_RetType Gtm_Drv_TbuStart(void);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuStop
*  Syntax           : TT_RetType Gtm_Drv_TbuStop(void)
*  Service ID       : 107
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Stop all channels of the TBU.
******************************************************************************/
TT_RetType Gtm_Drv_TbuStop(void);

/******************************************************************************
 *  Service name     : Gtm_Drv_TbuStartChannel
 *  Syntax           : TT_RetType Gtm_Drv_TbuStartChannel(uint8 channel)
 *  Service ID       : 108
 *  Sync/Async       : Synchronous
 *  Reentrancy       : Reentrant (but not for the same channel).
 *  Parameters (in)  : channel : Specifies the number of the Tbu channel to be started
 *  Parameters (out) : None
 *  Return value     : TT_RET_SUCCESS: accepted
 *                     Other         : not been accepted
 *  Description      : Start TBU specified channel
 ******************************************************************************/
TT_RetType Gtm_Drv_TbuStartChannel(uint8 channel);

/******************************************************************************
 *  Service name     : Gtm_Drv_TbuStopChannel
 *  Syntax           : TT_RetType Gtm_Drv_TbuStopChannel(uint8 channel)
 *  Service ID       : 109
 *  Sync/Async       : Synchronous
 *  Reentrancy       : Reentrant (but not for the same channel).
 *  Parameters (in)  : channel : Specifies the number of the Tbu channel to be started
 *  Parameters (out) : None
 *  Return value     : TT_RET_SUCCESS: accepted
 *                     Other         : not been accepted
 *  Description      : Stop TBU specified channel
 ******************************************************************************/
TT_RetType Gtm_Drv_TbuStopChannel(uint8 channel);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuSetClockChannel
*  Syntax           : TT_RetType Gtm_Drv_TbuSetClockChannel(uint8 channel, uint8 clock_source)
*  Service ID       : 110
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel      : Specifies the number of the Tbu channel to be started
*  Parameters (in)  : clock_source : Tbu clock source type to be set
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the clock source type of the channel specified by the Tbu
******************************************************************************/
TT_RetType Gtm_Drv_TbuSetClockChannel(uint8 channel, uint8 clock_source);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuGetClockChannel
*  Syntax           : TT_RetType Gtm_Drv_TbuGetClockChannel(uint8 channel,uint32* clock_source)
*  Service ID       : 111
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel      : Specifies the number of the Tbu channel to be started
*  Parameters (out) : clock_source : Save the read Tbu clock source type
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the clock source type of the channel specified by the Tbu.
******************************************************************************/
TT_RetType Gtm_Drv_TbuGetClockChannel(uint8 channel,uint8* clock_source);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuSetTimeBaseChannel
*  Syntax           : TT_RetType Gtm_Drv_TbuSetTimeBaseChannel(uint8 channel, uint32 time_base)
*  Service ID       : 112
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel       Specifies the number of the Tbu channel to be started
*  Parameters (in)  : time_base     Time base value of the Tbu channel
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the time base of the channel specified by the Tbu
******************************************************************************/
TT_RetType Gtm_Drv_TbuSetTimeBaseChannel( uint8 channel, uint32 time_base);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuGetTimeBaseChannel
*  Syntax           : TT_RetType Gtm_Drv_TbuGetTimeBaseChannel(uint8 channel,uint32 *time_base)
*  Service ID       : 113
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel       Specifies the number of the Tbu channel to be started
*  Parameters (out) : time_base     Save the time base value of the Tbu channel
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the time base of the channel specified by the Tbu
******************************************************************************/
TT_RetType Gtm_Drv_TbuGetTimeBaseChannel(uint8 channel,uint32 *time_base);


/******************************************************************************
*  Service name     : Gtm_Drv_TbuSetLowResChannel_0
*  Syntax           : TT_RetType Gtm_Drv_TbuSetLowResChannel_0( uint32 low_res)
*  Service ID       : 114
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : low_res : Resolution of the Tbu channel.
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the count resolution of Tbu channel 0.
******************************************************************************/
TT_RetType Gtm_Drv_TbuSetLowResChannel_0(uint8 low_res);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuGetLowResChannel_0
*  Syntax           : TT_RetType Gtm_Drv_TbuGetLowResChannel_0(uint8 *low_res)
*  Service ID       : 115
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : None
*  Parameters (out) : low_res: Save the resolution of the Tbu channel.
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the count resolution of Tbu channel 0.
******************************************************************************/
TT_RetType Gtm_Drv_TbuGetLowResChannel_0(uint8 *low_res);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuSetRunningModeChannel_12
*  Syntax           : TT_RetType Gtm_Drv_TbuSetRunningModeChannel_12(uint8 channel, Tbu_ChannelModeSelectType running_mode)
*  Service ID       : 116
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel      : Specifies the number of the Tbu channel to be started
*  Parameters (in)  : running_mode : Counting mode of the Tbu channel.
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counting mode of Tbu channel 0 and 1.
******************************************************************************/
TT_RetType Gtm_Drv_TbuSetRunningModeChannel_12(uint8 channel, Tbu_ChannelModeSelectType running_mode);

/******************************************************************************
*  Service name     : Gtm_Drv_TbuGetRunningModeChannel_12
*  Syntax           : TT_RetType Gtm_Drv_TbuGetRunningModeChannel_12(uint8 channel, Tbu_ChannelModeSelectType *mode)
*  Service ID       : 117
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel : Specifies the number of the Tbu channel to be started
*  Parameters (out) : mode    : Save the counting mode of the Tbu channel.
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counting mode of Tbu channel 0 and 1.
******************************************************************************/
TT_RetType Gtm_Drv_TbuGetRunningModeChannel_12(uint8 channel,Tbu_ChannelModeSelectType *mode);

/******************************************************************************
*  Service name     : Gtm_Drv_TomChanelEnable
*  Syntax           : TT_RetType Gtm_Drv_TomChanelEnable(Tom_ChannelType tomChannel,
                                                         Tom_ChannelEnableType enableMode,
                                                         Tom_ChannelOutputControlType outputEnableMode)
*  Service ID       : 118
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : tomChannel       : Tom channel
*  Parameters (in)  : enableMode       : Channel enable mode (Enable it immediately or wait for the trigger signal)
*  Parameters (in)  : outputEnableMode : Channel output enable mode (Enable it immediately or wait for the trigger signal)
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Enable the specified Tom channel output.
******************************************************************************/
TT_RetType Gtm_Drv_TomChanelEnable(Tom_ChannelType tomChannel,
                                   Tom_ChannelEnableType enableMode,
                                   Tom_ChannelOutputControlType outputEnableMode);


/******************************************************************************
*  Service name     : Gtm_Drv_TomChanelDisable
*  Syntax           : TT_RetType Gtm_Drv_TomChanelDisable(Tom_ChannelType tomChannel,
                                                          Tom_ChannelEnableType disableMode,
                                                          Tom_ChannelOutputControlType outputDisableMode)
*  Service ID       : 119
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : tomChannel        : Tom channel
*  Parameters (in)  : disableMode       : Channel disable mode (Disable it immediately or wait for the trigger signal)
*  Parameters (in)  : outputDisableMode : Channel output disable mode (Disable it immediately or wait for the trigger signal)
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Disable the specified Tom channel output.
******************************************************************************/
TT_RetType Gtm_Drv_TomChanelDisable(Tom_ChannelType tomChannel,
                                    Tom_ChannelEnableType disableMode,
                                    Tom_ChannelOutputControlType outputDisableMode);

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetHostTrigger
*  Syntax           : TT_RetType Gtm_Drv_TomSetHostTrigger(uint8 tomInstance, uint8 tgcIndex)
*  Service ID       : 120
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomInstance : Tom instance
*  Parameters (in)  : tgcIndex    : Tgc number
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Generates a host trig signal for the specified TGC of the specified Tom instance
******************************************************************************/
TT_RetType Gtm_Drv_TomSetHostTrigger(uint8 tomInstance, uint8 tgcIndex);

/******************************************************************************
*  Service name     : Gtm_Drv_Tom_SetUpdateCtrl
*  Syntax           : TT_RetType Gtm_Drv_TomSetUpdateCtrl(uint8 tomInstance, uint8 tgcIndex, uint8 mask)
*  Service ID       : 121
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomInstance : Tom instance
*  Parameters (in)  : tgcIndex    : tgc number
*  Parameters (in)  : mask        : Data mask, 1 indicates that the corresponding channel is enabled
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Generates an update signal for the specified TGC of the specified Tom based on the mask
******************************************************************************/
TT_RetType Gtm_Drv_TomSetUpdateCtrl(uint8 tomInstance, uint8 tgcIndex, uint8 mask);

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterCn0
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterCn0(Tom_ChannelType tomChannel, uint16 Cn0Value)
*  Service ID       : 122
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : Cn0 counter
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter cn0 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterCn0(Tom_ChannelType tomChannel, uint16 Cn0Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterCn0
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterCn0(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 123
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (out) : Value      : Cn0 counter
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counter cn0 for the channel specified by Tom..
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterCn0(Tom_ChannelType tomChannel,uint16* Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterCm0
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterCm0(Tom_ChannelType tomChannel, uint16 Cm0Value)
*  Service ID       : 124
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : Cm0 counter
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter cm0 for the channel specified by Tom..
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterCm0(Tom_ChannelType tomChannel, uint16 Cm0Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterCm0
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterCm0(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 125
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (out) : Value      : Cm0 counter
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counter cm0 for the channel specified by Tom..
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterCm0(Tom_ChannelType tomChannel,uint16* Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterCm1
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterCm1(Tom_ChannelType tomChannel, uint16 Cm1Value)
*  Service ID       : 126
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : Cm1 counter
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter cm1 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterCm1(Tom_ChannelType tomChannel, uint16 Cm1Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterCm1
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterCm1(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 127
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel:Tom channel
*  Parameters (out) : Value:Cm1 counter
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counter cm1 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterCm1(Tom_ChannelType tomChannel,uint16* Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterSr0
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterSr0(Tom_ChannelType tomChannel, uint16 Sr0Value)
*  Service ID       : 128
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : Sr0 counter
*  Parameters (out) : None 
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter SR0 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterSr0(Tom_ChannelType tomChannel, uint16 Sr0Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterSr0
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterSr0(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 129
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (out) : Value      : Sr0 counter
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counter SR0 for the channel specified by Tom..
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterSr0(Tom_ChannelType tomChannel,uint16* Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterSr1
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterSr1(Tom_ChannelType tomChannel, uint16 Sr1Value)
*  Service ID       : 130
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : sr1 counter
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter SR1 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterSr1(Tom_ChannelType tomChannel, uint16 Sr1Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterSr1
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterSr1(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 131
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (out) : Value      : Sr1 counter
*  Return value     : TT_RET_SUCCESS : accepted
*                     Other          : not been accepted
*  Description      : Get the counter SR1 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterSr1(Tom_ChannelType tomChannel,uint16* Value);

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetInt
*  Syntax           : TT_RetType Gtm_Drv_TomSetInt(TT_CONST Tom_ChannelType tomChannel,TT_CONST uint8 Irq_Mask)
*  Service ID       : 132
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel: Tom channel
*                     Irq_Mask: bit0:CCU0_IRQ enable/disable,bit1:CCU1_IRQ enable/disable
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCRESS : accepted
*                     Other           : not been accepted
*  Description      : Set the channel interrupt specified by Tom according to Irq_Mask
******************************************************************************/
TT_RetType Gtm_Drv_TomSetInt(TT_CONST Tom_ChannelType tomChannel,TT_CONST uint8 Irq_Mask);

/******************************************************************************
*  Service name     : Gtm_Drv_TimStartMeasure
*  Syntax           : TT_RetType Gtm_Drv_TimStartMeasure(Tim_ChnnelType TimChannel, boolean immediate)
*  Service ID       : 133
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (in)  : immediate  : at or wait for vaild edge
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Start measuring the specified Tim channel
******************************************************************************/
TT_RetType Gtm_Drv_TimStartMeasure(Tim_ChnnelType TimChannel, uint8 immediate);

/******************************************************************************
*  Service name     : Gtm_Drv_TimStopMeasure
*  Syntax           : TT_RetType Gtm_Drv_TimStopMeasure(Tim_ChnnelType TimChannel)
*  Service ID       : 134
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Stop measuring the specified Tim channel
******************************************************************************/
TT_RetType Gtm_Drv_TimStopMeasure(Tim_ChnnelType TimChannel);

/******************************************************************************
*  Service name     : Gtm_Drv_TimGetPwmInformation
*  Syntax           : TT_RetType Gtm_Drv_TimGetPwmInformation(Tim_ChnnelType TimChannel, Tim_PwmInfor * TT_CONST pwmInfor)
*  Service ID       : 135
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (out) : pwmInfor   : Save PWM data 
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get PWM data for a specified Tim channel measurement.
******************************************************************************/
TT_RetType Gtm_Drv_TimGetPwmInformation(Tim_ChnnelType TimChannel, Tim_PwmInfor * TT_CONST pwmInfor);

/******************************************************************************
*  Service name     : Gtm_Drv_TimGetMeasureInformation
*  Syntax           : TT_RetType Gtm_Drv_TimGetMeasureInformation(Tim_ChnnelType TimChannel, Tim_MeasureInfor * TT_CONST infor)
*  Service ID       : 136
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (out) : infor      : Save measurement  data
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get measurement data for a specified Tim channel measurement.
******************************************************************************/
TT_RetType Gtm_Drv_TimGetMeasureInformation(Tim_ChnnelType TimChannel, Tim_MeasureInfor * TT_CONST infor);

/******************************************************************************
*  Service name     : Gtm_Drv_TimGetPulseTime
*  Syntax           : TT_RetType Gtm_Drv_TimGetPulseTime(Tim_ChnnelType TimChannel,float *sumTime)
*  Service ID       : 137
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get pulse data for a specified Tim channel measurement.
******************************************************************************/
TT_RetType Gtm_Drv_TimGetPulseTime(Tim_ChnnelType TimChannel,float64 *sumTime);

/******************************************************************************
*  Service name     : Gtm_Drv_TimGetStatusFlags
*  Syntax           : TT_RetType_t Gtm_Drv_TimGetStatusFlags(Tim_ChnnelType TimChannel,uint8* statusFlags)
*  Service ID       : 138
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel  : Tim channel id
*  Parameters (out) : statusFlags : Save channel status
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Gets the status flag for the specified Tim channel
******************************************************************************/
TT_RetType Gtm_Drv_TimGetStatusFlags(Tim_ChnnelType TimChannel,uint8* statusFlags);

/******************************************************************************
*  Service name     : Gtm_Drv_TimClearStatusFlag
*  Syntax           : TT_RetType Gtm_Drv_TimClearStatusFlag(Tim_ChnnelType TimChannel, uint8 flag_DrvCS)
*  Service ID       : 139
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (in)  : flag_DrvCS : status flag
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                       Other         : not been accepted
*  Description      : Clears the flag specified by the Tim channel
******************************************************************************/
TT_RetType Gtm_Drv_TimClearStatusFlag(Tim_ChnnelType TimChannel, Tim_StatusFlagType flag_DrvCS);

/******************************************************************************
*  Service name     : Gtm_Drv_TimSetValue
*  Syntax           : TT_RetType Gtm_Drv_TimSetValue(Tim_ChnnelType TimChannel, Gtm_TimChannelValInitSignalType val)
*  Service ID       : 140
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (in)  : val        : Level value
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the Tim channel input level value
******************************************************************************/
TT_RetType Gtm_Drv_TimSetValue(Tim_ChnnelType TimChannel, Tim_ChannelValInitSignalType val);

/******************************************************************************
*  Service name     : Gtm_Drv_TimSetInt
*  Syntax           : TT_RetType Gtm_Drv_TimSetInt(TT_CONST Tim_ChnnelType TimChannel,TT_CONST uint8 Irq_Mask)
*  Service ID       : 141
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel: Tim channel
*  Parameters (in)  : Irq_Mask: bit0:NEWVAL_IRQ enable/disable,bit1:ECNTOFL_IRQ enable/disable
*                               bit2:CNTOFL_IRQ enable/disable,bit3:GPROFL_IRQ enable/disable
*                               bit4:TODET_IRQ enable/disable,bit5:GLITCHDET_IRQ enable/disable
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the interrupt of Tim channel according to Irq_Mask
******************************************************************************/
TT_RetType Gtm_Drv_TimSetInt(TT_CONST Tim_ChnnelType TimChannel,TT_CONST uint8 Irq_Mask);

/******************************************************************************
*  Service name     : Gtm_Drv_DtmStart
*  Syntax           : TT_RetType Gtm_Drv_DtmStart(Cdtm_DtmChannelIndexType CdtmDtmChIndex)
*  Service ID       : 142
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : CdtmDtmIndex : GTM DTM Index
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Start all channel outputs of Cdtm's Dtm.
******************************************************************************/
TT_RetType Gtm_Drv_DtmStart(Cdtm_DtmIndexType CdtmDtmIndex);

/******************************************************************************
*  Service name     : Gtm_Drv_DtmStop
*  Syntax           : TT_RetType Gtm_Drv_DtmStop(Cdtm_DtmChannelIndexType CdtmDtmChIndex)
*  Service ID       : 143
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : CdtmDtmIndex  : GTM DTM Index
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Stop all channel outputs of Cdtm's Dtm
******************************************************************************/
TT_RetType Gtm_Drv_DtmStop(Cdtm_DtmIndexType CdtmDtmIndex);

/******************************************************************************
*  Service name     : Gtm_Drv_DtmSetDeadTime
*  Syntax           : TT_RetType Gtm_Drv_DtmSetDeadTime(Cdtm_DtmChannelIndexType CdtmDtmChIndex,
                                                        TT_CONST uint16 riseEdgeTime, 
                                                        TT_CONST uint16 fallEdgeTime)
*  Service ID       : 147
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : CdtmDtmChIndex : GTM DTM channel Index
*  Parameters (in)  : riseEdgeTime   : Rise Edge dead time
*  Parameters (in)  : fallEdgeTime   : fall Edge dead time
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS : accepted
*                     Other          : not been accepted
*  Description      : Set the specified channel dead zone time of the Dtm of Cdtm
******************************************************************************/
TT_RetType Gtm_Drv_DtmSetDeadTime(Cdtm_DtmChannelIndexType CdtmDtmChIndex,
                                              uint16 RiseEdgeTime, uint16 FallEdgeTime);

/******************************************************************************
*  service name     : Gtm_Drv_SetMonitorClsClock
*  Syntax           : TT_RetType Gtm_Drv_SetMonitorClsClock(TT_CONST uint8 ClsIndex,TT_CONST uint8 ClockDiv)
*  Service ID       : 144
*  Reentrancy       : Reentrant
*  Parameters (in)  : ClsIndex : GTM monitor cluster clock source type (0-3)
*  Parameters (in)  : ClockDiv : GTM monitor cluster clock Div
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : The clock monitoring function of a specified cluster was enabled and clock frequency division was set.
******************************************************************************/
TT_RetType Gtm_Drv_SetMonitorClsClock(TT_CONST ClusterClockType ClsIndex,TT_CONST uint8 ClockDiv);

/******************************************************************************
*  Service name     : Gtm_Drv_SetMonitorTimInput
*  Syntax           : TT_RetType Gtm_Drv_SetMonitorTimInput(uint8 TimIndex,uint8 InputSel,uint8 Osc_Div)
*  Service ID       : 145
*  Sync/Async       : Synchronous
*  Reentrancy       : No reentrant
*  Parameters (in)  : TimIndex: Tim Index (0:TIMch0,...,7:TIMch7)
*                     InputSel: input Sel (0:pad,1:osc,2:eclk0,3:eclk1,4:eclk)
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS       set command has been accepted
*                     E_NOT_OK   set command has not been accepted
*  Description      : Set input level
******************************************************************************/
TT_RetType Gtm_Drv_SetMonitorTimInput(uint8 TimIndex,uint8 InputSel,uint8 Osc_Div);

/*****************************************************************************
*  Service name    : Gtm_Drv_GetVersionInfo
*  Syntax          : Gtm_Drv_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
*  Service ID      : 146
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): VersionInfoPtr :Pointer to where to store the version
                     information of this module
*  Return value    : None
*  Description     : Returns the version information of this module.
******************************************************************************/
void Gtm_Drv_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);

#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */
