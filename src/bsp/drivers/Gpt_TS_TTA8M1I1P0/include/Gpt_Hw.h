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
**  FILENAME     : Gpt_Hw.h                                                   **
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
#ifndef GPT_HW_H
#define GPT_HW_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gpt_Hw_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GPT_HW_VENDOR_ID_H                          1541
#define GPT_HW_MODULE_ID_H                          100
#define GPT_HW_AR_RELEASE_MAJOR_VERSION_H           4
#define GPT_HW_AR_RELEASE_MINOR_VERSION_H           4
#define GPT_HW_AR_RELEASE_PATCH_VERSION_H           0
#define GPT_HW_SW_MAJOR_VERSION_H                   1
#define GPT_HW_SW_MINOR_VERSION_H                   1
#define GPT_HW_SW_PATCH_VERSION_H                   0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gpt_Hw_Types.h Gpt_Hw.H file version check */
#if (GPT_HW_VENDOR_ID_H != GPT_HW_TYPES_VENDOR_ID_H)
    #error "Gpt_Hw_Types.h and Gpt_Hw.h have different vendor id"
#endif

#if (GPT_HW_MODULE_ID_H != GPT_HW_TYPES_MODULE_ID_H)
    #error "Gpt_Hw_Types.h and Gpt_Hw.h have different module id"
#endif

#if ((GPT_HW_AR_RELEASE_MAJOR_VERSION_H != GPT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_HW_AR_RELEASE_MINOR_VERSION_H != GPT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_HW_AR_RELEASE_PATCH_VERSION_H != GPT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_Hw_Types.h and Gpt_Hw.h are different"
#endif

#if ((GPT_HW_SW_MAJOR_VERSION_H != GPT_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (GPT_HW_SW_MINOR_VERSION_H != GPT_HW_TYPES_SW_MINOR_VERSION_H) || \
     (GPT_HW_SW_PATCH_VERSION_H != GPT_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_Hw_Types.h and Gpt_Hw.h are different"
#endif

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
/**
* @brief         Gpt_Hw_Init
* @details       Initialize the channel timer.
* @param[in]     FtmChannelConfigPtr - FTM channel configuration
* @param[in]     FtmModuleConfigPtr - FTM module configuration
* @param[out]    None
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Others - error code
* @pre
*/
TT_RetType Gpt_Hw_Init(TT_CONST Gpt_Hw_FtmChannelConfigType* FtmChannelConfigPtr, TT_CONST Gpt_Hw_FtmModuleConfigType* FtmModuleConfigPtr);

/**
* @brief         Gpt_Hw_PredefTimerInit
* @details       Initialize the Predef timer.
* @param[in]     FtmPredefTimerConfigPtr - FTM predef timer configuration
* @param[out]    None
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Others - error code
* @pre
*/
TT_RetType Gpt_Hw_PredefTimerInit(TT_CONST Gpt_Hw_FtmPredefTimerConfigType* FtmPredefTimerConfigPtr);

#if (GPT_DEINIT_API == STD_ON)
/**
* @brief         Gpt_Hw_DeInit
* @details       Channel timer deinitialization.
* @param[in]     None
* @param[out]    None
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Others - error code
* @pre
*/
TT_RetType Gpt_Hw_DeInit(void);

/**
* @brief        Gpt_Hw_PredefTimerDeInit
* @details      Predef timer deinitialization.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - error code
* @pre
*/
TT_RetType Gpt_Hw_PredefTimerDeInit(void);
#endif

#if (GPT_PREDEF_TIMER_ONLY == STD_OFF)
/**
* @brief         Gpt_Hw_StartTimer
* @details       The function is to start a timer channel by Target time in number of ticks.
* @param[in]     Channel - Numeric identifier of the GPT channel
* @param[in]     Value - Target time in number of ticks
* @param[out]    None
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Others - error code
* @pre
*/
TT_RetType Gpt_Hw_StartTimer(Gpt_Hw_ChannelType Channel, Gpt_Hw_ValueType Value);

/**
* @brief         Gpt_Hw_StopTimer
* @details       The function is to stop a specified timer channel.
* @param[in]     Channel - Numeric identifier of the GPT channel
* @param[out]    None
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Others - error code
* @pre
*/
TT_RetType Gpt_Hw_StopTimer(Gpt_Hw_ChannelType Channel);
#endif

/**
* @brief         Gpt_Hw_GetCounter
* @details       Gets the counter value.
* @param[in]     Channel - Numeric identifier of the GPT channel
* @param[out]    None
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Others - error code
* @pre
*/
TT_RetType Gpt_Hw_GetCounter(Gpt_Hw_ChannelType Channel,Gpt_Hw_ValueType *CounterValue);

/**
* @brief         Gpt_Hw_StopFtmModuleTimer
* @details       Stop the FTM module timer.
* @param[in]     FtmModule - FTM module
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
void Gpt_Hw_StopFtmModuleTimer(uint8 FtmModule);

/**
* @brief         Gpt_Hw_ClearOverflowIrqFlag
* @details       Clear the overflow interrupt flag.
* @param[in]     FtmModule - FTM module
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
void Gpt_Hw_ClearOverflowIrqFlag(uint8 FtmModule);

#ifdef __cplusplus
}
#endif

#endif
