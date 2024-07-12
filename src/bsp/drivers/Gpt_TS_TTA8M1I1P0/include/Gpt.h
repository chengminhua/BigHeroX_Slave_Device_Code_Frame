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
**  FILENAME     : Gpt.h                                                      **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : GPT Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef GPT_H
#define GPT_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gpt_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GPT_VENDOR_ID_H                       1541
#define GPT_MODULE_ID_H                       100
#define GPT_AR_RELEASE_MAJOR_VERSION_H        4
#define GPT_AR_RELEASE_MINOR_VERSION_H        4
#define GPT_AR_RELEASE_PATCH_VERSION_H        0
#define GPT_SW_MAJOR_VERSION_H                1
#define GPT_SW_MINOR_VERSION_H                1
#define GPT_SW_PATCH_VERSION_H                0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gpt_Types.h Gpt.H file version check */
#if (GPT_VENDOR_ID_H != GPT_TYPES_VENDOR_ID_H)
    #error "Gpt_Types.h and Gpt.h have different vendor id"
#endif

#if (GPT_MODULE_ID_H != GPT_TYPES_MODULE_ID_H)
    #error "Gpt_Types.h and Gpt.h have different module id"
#endif

#if ((GPT_AR_RELEASE_MAJOR_VERSION_H != GPT_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_AR_RELEASE_MINOR_VERSION_H != GPT_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_AR_RELEASE_PATCH_VERSION_H != GPT_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_Types.h and Gpt.h are different"
#endif

#if ((GPT_SW_MAJOR_VERSION_H != GPT_TYPES_SW_MAJOR_VERSION_H) || \
     (GPT_SW_MINOR_VERSION_H != GPT_TYPES_SW_MINOR_VERSION_H) || \
     (GPT_SW_PATCH_VERSION_H != GPT_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_Types.h and Gpt.h are different"
#endif

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
#if (defined(GPT_VERSION_INFO_API) && (GPT_VERSION_INFO_API == STD_ON))
/******************************************************************************
*  Service name    : Gpt_GetVersionInfo
*  Syntax          : Gpt_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
*  Service ID      : 0x00
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : VersionInfoPtr :Pointer to where to store the version
                     information of this module
*  Description     : Returns the version information of this module.
******************************************************************************/
void Gpt_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);
#endif

/******************************************************************************
*  Service name    : Gpt_Init
*  Syntax          : Gpt_Init(TT_CONST Gpt_ConfigType* ConfigPtr)
*  Service ID      : 0x01
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : ConfigPtr:Pointer to a selected configuration structure
*  Parameters (out): None
*  Return value    : None
*  Description     : Initializes the GPT driver.
******************************************************************************/
void Gpt_Init(TT_CONST Gpt_ConfigType* ConfigPtr);

#if (defined(GPT_DEINIT_API) && (GPT_DEINIT_API == STD_ON))
/******************************************************************************
*  Service name    : Gpt_DeInit
*  Syntax          : Gpt_DeInit(void)
*  Service ID      : 0x02
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : None
*  Description     : Deinitializes the GPT driver.
******************************************************************************/
void Gpt_DeInit(void);
#endif

#if (GPT_PREDEF_TIMER_ONLY == STD_OFF)
#if (defined(GPT_TIME_ELAPSED_API) && (GPT_TIME_ELAPSED_API == STD_ON))
/******************************************************************************
*  Service name    : Gpt_GetTimeElapsed
*  Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
*  Service ID      : 0x03
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Channel:Numeric identifier of the GPT channel
*  Parameters (out): None
*  Return value    : Gpt_ValueType:Elapsed timer value (in number of ticks)
*  Description     : Returns the time already elapsed.
******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
#endif

#if (defined(GPT_TIME_REMAINING_API) && (GPT_TIME_REMAINING_API == STD_ON))
/******************************************************************************
*  Service name    : Gpt_GetTimeRemaining
*  Syntax          : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
*  Service ID      : 0x04
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Channel:Numeric identifier of the GPT channel
*  Parameters (out): None
*  Return value    : Gpt_ValueType:Remaining timer value (in number of ticks)
*  Description     : Returns the time remaining until the target time is reached.
******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
#endif

/******************************************************************************
*  Service name    : Gpt_StartTimer
*  Syntax          : void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
*  Service ID      : 0x05
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant (but not for the same timer channel)
*  Parameters (in) : Channel:Numeric identifier of the GPT channel
*  Parameters (in) : Value:Target time in number of ticks
*  Parameters (out): None
*  Return value    : None
*  Description     : Starts a timer channel.
******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/******************************************************************************
*  Service name    : Gpt_StopTimer
*  Syntax          : void Gpt_StopTimer(Gpt_ChannelType Channel)
*  Service ID      : 0x06
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant (but not for the same timer channel)
*  Parameters (in) : Channel:Numeric identifier of the GPT channel
*  Parameters (out): None
*  Return value    : None
*  Description     : Stops a timer channel.
******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel);

#if (defined(GPT_ENABLE_DISABLE_NOTIFICATION_API) && (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON))
/******************************************************************************
*  Service name    : Gpt_EnableNotification
*  Syntax          : void Gpt_EnableNotification(Gpt_ChannelType Channel)
*  Service ID      : 0x07
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant (but not for the same timer channel)
*  Parameters (in) : Channel:Numeric identifier of the GPT channel
*  Parameters (out): None
*  Return value    : None
*  Description     : Enables the interrupt notification for a channel (relevant in normal mode).
******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel);

/******************************************************************************
*  Service name    : Gpt_DisableNotification
*  Syntax          : void Gpt_DisableNotification(Gpt_ChannelType Channel)
*  Service ID      : 0x08
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant (but not for the same timer channel)
*  Parameters (in) : Channel:Numeric identifier of the GPT channel
*  Parameters (out): None
*  Return value    : None
*  Description     : Disables the interrupt notification for a channel (relevant in normal mode).
******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel);
#endif
#endif

#if (defined(GPT_WAKEUP_FUNCTIONALITY_API) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/******************************************************************************
*  Service name    : Gpt_SetMode
*  Syntax          : void Gpt_SetMode(Gpt_ModeType Mode)
*  Service ID      : 0x09
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : Mode:GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
*                         GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
*  Parameters (out): None
*  Return value    : None
*  Description     : Sets the operation mode of the GPT.
******************************************************************************/
void Gpt_SetMode(Gpt_ModeType Mode);

/******************************************************************************
*  Service name    : Gpt_DisableWakeup
*  Syntax          : void Gpt_DisableWakeup(Gpt_ChannelType Channel)
*  Service ID      : 0x0a
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant (but not for the same timer channel)
*  Parameters (in) : Channel:Numeric identifier of the GPT channel
*  Parameters (out): None
*  Return value    : None
*  Description     : Disables the wakeup interrupt of a channel (relevant in sleep mode).
******************************************************************************/
void Gpt_DisableWakeup(Gpt_ChannelType Channel);

/******************************************************************************
*  Service name    : Gpt_EnableWakeup
*  Syntax          : void Gpt_EnableWakeup(Gpt_ChannelType Channel)
*  Service ID      : 0x0b
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant (but not for the same timer channel)
*  Parameters (in) : Channel:Numeric identifier of the GPT channel
*  Parameters (out): None
*  Return value    : None
*  Description     : Enables the wakeup interrupt of a channel (relevant in sleep mode).
******************************************************************************/
void Gpt_EnableWakeup(Gpt_ChannelType Channel);

#if defined(USING_OS_AUTOSAROS)
/******************************************************************************
*  Service name    : Gpt_CheckWakeup
*  Syntax          : void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
*  Service ID      : 0x0c
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : WakeupSource:GInformation on wakeup source to be checked.
*                                 The associated GPT channel can be determined from configuration data.
*  Parameters (out): None
*  Return value    : None
*  Description     : Checks if a wakeup capable GPT channel is the source for a wakeup event and calls
*                    the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
******************************************************************************/
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif
#endif

/******************************************************************************
*  Service name    : Gpt_GetPredefTimerValue
*  Syntax          : Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)
*  Service ID      : 0x0d
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : PredefTimer:GPT Predef Timer
*  Parameters (out): TimeValuePtr:Pointer to time value destination data in RAM
*  Return value    : Std_ReturnType:E_OK: no error has been detected
*                                   E_NOT_OK: aborted due to errors
*  Description     : Delivers the current value of the desired GPT Predef Timer.
******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr);

#ifdef GPT_FTM0
/**
* @brief        ISR(FTM0_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM0_IRQHandler);
#endif

#ifdef GPT_FTM1
/**
* @brief        ISR(FTM1_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM1_IRQHandler);
#endif

#ifdef GPT_FTM2
/**
* @brief        ISR(FTM2_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM2_IRQHandler);
#endif

#ifdef GPT_FTM3
/**
* @brief        ISR(FTM3_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM3_IRQHandler);
#endif

#ifdef GPT_FTM4
/**
* @brief        ISR(FTM4_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM4_IRQHandler);
#endif

#ifdef GPT_FTM5
/**
* @brief        ISR(FTM5_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM5_IRQHandler);
#endif

#ifdef __cplusplus
}
#endif

#endif
