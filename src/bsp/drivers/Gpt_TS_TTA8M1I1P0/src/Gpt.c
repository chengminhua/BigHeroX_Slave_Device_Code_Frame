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
**  FILENAME     : Gpt.c                                                      **
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
#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gpt.h"
#include "Gpt_Hw.h"

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#include "Base_Tools.h"
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GPT_VENDOR_ID_C                         1541
#define GPT_MODULE_ID_C                         100
#define GPT_AR_RELEASE_MAJOR_VERSION_C          4
#define GPT_AR_RELEASE_MINOR_VERSION_C          4
#define GPT_AR_RELEASE_PATCH_VERSION_C          0
#define GPT_SW_MAJOR_VERSION_C                  1
#define GPT_SW_MINOR_VERSION_C                  1
#define GPT_SW_PATCH_VERSION_C                  0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gpt.h Gpt.c file version check */
#if (GPT_VENDOR_ID_C != GPT_VENDOR_ID_H)
    #error "Gpt.h and Gpt.c have different vendor id"
#endif

#if (GPT_MODULE_ID_C != GPT_MODULE_ID_H)
    #error "Gpt.h and Gpt.c have different module id"
#endif

#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_AR_RELEASE_PATCH_VERSION_C != GPT_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt.h and Gpt.c are different"
#endif

#if ((GPT_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION_H) || \
     (GPT_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION_H) || \
     (GPT_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt.h and Gpt.c are different"
#endif

/* Gpt_Hw.h Gpt.c file version check */
#if (GPT_VENDOR_ID_C != GPT_HW_VENDOR_ID_H)
    #error "Gpt_Hw.h and Gpt.c have different vendor id"
#endif

#if (GPT_MODULE_ID_C != GPT_HW_MODULE_ID_H)
    #error "Gpt_Hw.h and Gpt.c have different module id"
#endif

#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_AR_RELEASE_PATCH_VERSION_C != GPT_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_Hw.h and Gpt.c are different"
#endif

#if ((GPT_SW_MAJOR_VERSION_C != GPT_HW_SW_MAJOR_VERSION_H) || \
     (GPT_SW_MINOR_VERSION_C != GPT_HW_SW_MINOR_VERSION_H) || \
     (GPT_SW_PATCH_VERSION_C != GPT_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_Hw.h and Gpt.c are different"
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/* Base_Tools.h Gpt.c file version check */
#if (GPT_VENDOR_ID_C != BASE_TOOLS_VENDOR_ID_H)
    #error "Base_Tools.h and Gpt.c have different vendor id"
#endif

#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_AR_RELEASE_PATCH_VERSION_C != BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Tools.h and Gpt.c are different"
#endif

#if ((GPT_SW_MAJOR_VERSION_C != BASE_TOOLS_SW_MAJOR_VERSION_H) || \
     (GPT_SW_MINOR_VERSION_C != BASE_TOOLS_SW_MINOR_VERSION_H) || \
     (GPT_SW_PATCH_VERSION_C != BASE_TOOLS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Tools.h and Gpt.c are different"
#endif
#endif

/******************************************************************************
*                            Private Variables
*******************************************************************************/
#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

/* Global status of the GPT driver */
static Gpt_GlobalStateType Gpt_PubGlobalState;

/* Modes of the GPT driver. */
static Gpt_ModeType Gpt_PubMode;

#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_CLEARED_PTR
#include "Gpt_MemMap.h"

/* All configurations for the GPT driver. */
static TT_CONST Gpt_ConfigType* Gpt_PubConfig;

/* All channel configurations for the GPT driver. */
static TT_CONST Gpt_ChannelConfigType* Gpt_PubChannelConfig;

#define GPT_STOP_SEC_VAR_CLEARED_PTR
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

/* GPT drives the global state of all channels */
static Gpt_GlobalType Gpt_PubGlobal;

/* GPT drives values of the predef timer type */
static Gpt_PredefTimeValueType Gpt_PubPredefTimeValue;

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

/******************************************************************************
*                    Private Function Declaration
******************************************************************************/
#if (defined(GPT_PREDEF_TIMER_1US_16BIT_ENABLE) && (GPT_PREDEF_TIMER_1US_16BIT_ENABLE == STD_ON))
/**
* @brief         Gpt_PriProcessData1Us16Bit
* @details       The function is to handle interrupt transactions.
* @param[in]     None
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessData1Us16Bit(void);
#endif

#if (defined(GPT_PREDEF_TIMER_1US_24BIT_ENABLE) && (GPT_PREDEF_TIMER_1US_24BIT_ENABLE == STD_ON))
/**
* @brief         Gpt_PriProcessData1Us24Bit
* @details       The function is to handle interrupt transactions.
* @param[in]     None
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessData1Us24Bit(void);
#endif

#if (defined(GPT_PREDEF_TIMER_1US_32BIT_ENABLE) && (GPT_PREDEF_TIMER_1US_32BIT_ENABLE == STD_ON))
/**
* @brief         Gpt_PriProcessData1Us32Bit
* @details       The function is to handle interrupt transactions.
* @param[in]     None
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessData1Us32Bit(void);
#endif

#if (defined(GPT_PREDEF_TIMER_100US_32BIT_ENABLE) && (GPT_PREDEF_TIMER_100US_32BIT_ENABLE == STD_ON))
/**
* @brief         Gpt_PriProcessData100Us32Bit
* @details       The function is to handle interrupt transactions.
* @param[in]     None
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessData100Us32Bit(void);
#endif

#if (defined(GPT_CHANNEL_TIMER_FTM0) || defined(GPT_CHANNEL_TIMER_FTM1) || defined(GPT_CHANNEL_TIMER_FTM2) || \
    defined(GPT_CHANNEL_TIMER_FTM3) || defined(GPT_CHANNEL_TIMER_FTM4) || defined(GPT_CHANNEL_TIMER_FTM5))
/**
* @brief         Gpt_PriProcessInterrupt
* @details       The function is to handle interrupt transactions.
* @param[in]     FtmModule - FTM module
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessInterrupt(uint8 FtmModule);
#endif

/**
* @brief         Gpt_PriParamCheck
* @details       Reports Det error if GPT_DEV_ERROR_DETECT == STD_ON.(ModuleDet_ReportError).
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        void
* @retval        None
* @pre
*/
LOCAL_INLINE void Gpt_PriParamCheck(boolean Expr, uint8 ApiId, uint8 ErrId, Std_ReturnType *RetVal);

/**
* @brief         Gpt_PriParamRuntimeCheck
* @details       Reports Det error if GPT_DEV_ERROR_DETECT == STD_ON.(ModuleDet_ReportRuntimeError).
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        void
* @retval        None
* @pre
*/
LOCAL_INLINE void Gpt_PriParamRuntimeCheck(boolean Expr, uint8 ApiId, uint8 ErrId, Std_ReturnType *RetVal);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gpt_PriInitParaCrcCheck
* @details      This function performs a Crc check on the module default configuration data.
* @param[in]    RetVal : E_OK - Crc check success.
*                        E_NOT_OK - Crc check failed
* @param[out]   None
* @return       Std_ReturnType
* @retval       E_OK - Crc check success.
*               E_NOT_OK - Crc check failed
* @pre
*/
LOCAL_INLINE Std_ReturnType Gpt_PriInitParaCrcCheck(Std_ReturnType RetVal);
#endif

/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define GPT_START_SEC_CODE_SLOW
#include "Gpt_MemMap.h"
#if (defined(GPT_VERSION_INFO_API) && (GPT_VERSION_INFO_API == STD_ON))
/******************************************************************************
*  Service name    : Gpt_GetVersionInfo
*  Syntax          : Gpt_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
*  Service ID      : 0x00
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): VersionInfoPtr:Pointer to where to store the version
                     information of this module
*  Return value    : None
*  Description     : Returns the version information of this module.
******************************************************************************/
void Gpt_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
    Std_ReturnType RetVal = E_OK;

    /* SWS_Gpt_00338 */
    Gpt_PriParamCheck(NULL_PTR == VersionInfoPtr, GPT_GETVERSIONINFO_ID, GPT_E_PARAM_POINTER, &RetVal);

    if(E_OK == RetVal)
    {
        VersionInfoPtr->vendorID = GPT_VENDOR_ID_C;
        VersionInfoPtr->moduleID = GPT_MODULE_ID_C;
        VersionInfoPtr->sw_major_version = GPT_SW_MAJOR_VERSION_C;
        VersionInfoPtr->sw_minor_version = GPT_SW_MINOR_VERSION_C;
        VersionInfoPtr->sw_patch_version = GPT_SW_PATCH_VERSION_C;
    }
    else
    {
        /* do nothing */
    }
}
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
void Gpt_Init(TT_CONST Gpt_ConfigType* ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Std_ReturnType RetVal = E_OK;
    Gpt_ChannelType Channel = 0;

#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
    Gpt_PubConfig = (TT_CONST Gpt_ConfigType *)&GptConfigData;
    (void)ConfigPtr;
    Gpt_PriParamCheck(NULL_PTR != ConfigPtr, GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
#else
    TT_CONST Gpt_ConfigType *Config = ConfigPtr;
    Gpt_PubConfig = Config;
    Gpt_PriParamCheck(NULL_PTR == ConfigPtr, GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
#endif

    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptChannelConfig), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#if (GPT_ONLY == STD_ON)
    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptFtmChannelConfig), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptFtmHardwareChannelMap), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptFtmModuleConfig), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
#elif (GPT_PREDEF_TIMER_ONLY == STD_ON)
    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptFtmPredefTimerConfig), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
#else
    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptFtmChannelConfig), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptFtmHardwareChannelMap), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptFtmModuleConfig), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
    Gpt_PriParamCheck((E_OK != RetVal) || (NULL_PTR == Gpt_PubConfig->GptFtmPredefTimerConfig), GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
#endif
    Gpt_PriParamCheck((E_OK != Gpt_PriInitParaCrcCheck(RetVal)),GPT_INIT_ID, GPT_E_PARAM_CONFIG, &RetVal);
#endif
    /* SWS_Gpt_00307 */
    Gpt_PriParamCheck(GPT_STATE_IDLE == Gpt_PubGlobalState, GPT_INIT_ID, GPT_E_ALREADY_INITIALIZED, &RetVal);

    if(E_OK == RetVal)
    {
#if (GPT_ONLY == STD_ON)
        Ret = Gpt_Hw_Init(Gpt_PubConfig->GptFtmChannelConfig,Gpt_PubConfig->GptFtmModuleConfig);
#elif (GPT_PREDEF_TIMER_ONLY == STD_ON)
        Ret = Gpt_Hw_PredefTimerInit(Gpt_PubConfig->GptFtmPredefTimerConfig);
#else
        Ret = Gpt_Hw_Init(Gpt_PubConfig->GptFtmChannelConfig,Gpt_PubConfig->GptFtmModuleConfig);
        if(TT_RET_SUCCESS == Ret)
        {
            Ret = Gpt_Hw_PredefTimerInit(Gpt_PubConfig->GptFtmPredefTimerConfig);
        }
        else
        {
            /* do nothing */
        }
#endif
        if(TT_RET_SUCCESS == Ret)
        {
            for(Channel = 0; Channel < GPT_CHANNEL_CONFIG_NUMBER; Channel++)
            {
                Gpt_PubGlobal.GptChannelNotificationStatus[Channel] = FALSE;
                Gpt_PubGlobal.GptChannelStatus[Channel] = GPT_CH_STATUS_INITIALIZED;
            }
            Gpt_PubMode = GPT_MODE_NORMAL;
            Gpt_PubPredefTimeValue.Gpt1us16bitNumber = 0;
            Gpt_PubPredefTimeValue.Gpt1us24bitNumber = 0;
            Gpt_PubPredefTimeValue.Gpt1us32bitNumber = 0;
            Gpt_PubPredefTimeValue.Gpt100us32bitNumber = 0;
            Gpt_PubPredefTimeValue.Gpt1usNumber = 0;
            Gpt_PubChannelConfig = Gpt_PubConfig->GptChannelConfig;
            Gpt_PubGlobalState = GPT_STATE_IDLE;
        }
        else
        {
            Gpt_PriParamCheck(TRUE, GPT_INIT_ID, GPT_E_INIT_FAILED, &RetVal);
        }
    }
    else
    {
        /* do nothing */
    }
}

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
void Gpt_DeInit(void)
{
    Std_ReturnType RetVal = E_OK;
    TT_RetType Ret = TT_RET_SUCCESS;
    Gpt_ChannelType Channel = 0;

    /* SWS_Gpt_00220 */
    Gpt_PriParamCheck(GPT_STATE_UNINIT == Gpt_PubGlobalState, GPT_DEINIT_ID, GPT_E_UNINIT, &RetVal);
    /* SWS_Gpt_00234 */
    for(Channel = 0;Channel < GPT_CHANNEL_CONFIG_NUMBER;Channel++)
    {
        Gpt_PriParamRuntimeCheck(GPT_CH_STATUS_RUNNING == Gpt_PubGlobal.GptChannelStatus[Channel], GPT_DEINIT_ID, GPT_E_BUSY, &RetVal);
    }

    if(E_OK == RetVal)
    {
#if (GPT_ONLY == STD_ON)
        Ret = Gpt_Hw_DeInit();
#elif (GPT_PREDEF_TIMER_ONLY == STD_ON)
        Ret = Gpt_Hw_PredefTimerDeInit();
#else
        Ret = Gpt_Hw_DeInit();
        if(TT_RET_SUCCESS == Ret)
        {
            Ret = Gpt_Hw_PredefTimerDeInit();
        }
        else
        {
            /* do nothing */
        }
#endif

        if(TT_RET_SUCCESS == Ret)
        {
            for(Channel = 0; Channel < GPT_CHANNEL_CONFIG_NUMBER; Channel++)
            {
                Gpt_PubGlobal.GptChannelNotificationStatus[Channel] = FALSE;
                Gpt_PubGlobal.GptChannelStatus[Channel] = GPT_CH_STATUS_UNINITIALIZED;
            }
            Gpt_PubGlobalState = GPT_STATE_UNINIT;
        }
        else
        {
            Gpt_PriParamCheck(TRUE, GPT_DEINIT_ID, GPT_E_SYSTEM, &RetVal);
        }
    }
    else
    {
        /* do nothing */
    }
}
#endif

#define GPT_STOP_SEC_CODE_SLOW
#include "Gpt_MemMap.h"

#if (GPT_PREDEF_TIMER_ONLY == STD_OFF)
#if (defined(GPT_TIME_ELAPSED_API) && (GPT_TIME_ELAPSED_API == STD_ON))
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

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
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Std_ReturnType RetVal = E_OK;
    TT_RetType Ret = TT_RET_SUCCESS;
    Gpt_ValueType TimeElapsed = 0;

    /* SWS_Gpt_00222 */
    Gpt_PriParamCheck(GPT_STATE_UNINIT == Gpt_PubGlobalState, GPT_GETTIMEELAPSED_ID, GPT_E_UNINIT, &RetVal);
    /* SWS_Gpt_00210 */
    Gpt_PriParamCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, GPT_GETTIMEELAPSED_ID, GPT_E_PARAM_CHANNEL, &RetVal);

    if(E_OK == RetVal)
    {
        if((Gpt_PubGlobal.GptChannelStatus[Channel] == GPT_CH_STATUS_STOPPED) || \
           (Gpt_PubGlobal.GptChannelStatus[Channel] == GPT_CH_STATUS_RUNNING))
        {
            Ret = Gpt_Hw_GetCounter(Channel,&TimeElapsed);
            Gpt_PriParamCheck(TT_RET_SUCCESS != Ret, GPT_GETTIMEELAPSED_ID, GPT_E_PARAM_CHANNEL, &RetVal);
        }
        else if((Gpt_PubChannelConfig[Channel].GptChannelMode == GPT_CH_MODE_ONESHOT) && \
                (Gpt_PubGlobal.GptChannelStatus[Channel] == GPT_CH_STATUS_EXPIRED))
        {
            TimeElapsed = Gpt_PubGlobal.GptTargetValue[Channel];
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    return TimeElapsed;
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#if (defined(GPT_TIME_REMAINING_API) && (GPT_TIME_REMAINING_API == STD_ON))
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

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
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    Std_ReturnType RetVal = E_OK;
    TT_RetType Ret = TT_RET_SUCCESS;
    Gpt_ValueType TimeElapsed = 0;
    Gpt_ValueType RemainingVal = 0;

    /* SWS_Gpt_00223 */
    Gpt_PriParamCheck(GPT_STATE_UNINIT == Gpt_PubGlobalState, GPT_GETTIMEREMAINING_ID, GPT_E_UNINIT, &RetVal);
    /* SWS_Gpt_00211 */
    Gpt_PriParamCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, GPT_GETTIMEREMAINING_ID, GPT_E_PARAM_CHANNEL, &RetVal);

    if(E_OK == RetVal)
    {
        if((Gpt_PubGlobal.GptChannelStatus[Channel] == GPT_CH_STATUS_STOPPED) || \
           (Gpt_PubGlobal.GptChannelStatus[Channel] == GPT_CH_STATUS_RUNNING))
        {
            Ret = Gpt_Hw_GetCounter(Channel,&TimeElapsed);
            if(TT_RET_SUCCESS == Ret)
            {
                RemainingVal = Gpt_PubGlobal.GptTargetValue[Channel] - TimeElapsed;
            }
            else
            {
                Gpt_PriParamCheck(TRUE, GPT_GETTIMEREMAINING_ID, GPT_E_PARAM_CHANNEL, &RetVal);
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    return RemainingVal;
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

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
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    Std_ReturnType RetVal = E_OK;
    TT_RetType Ret = TT_RET_SUCCESS;

    /* SWS_Gpt_00224 */
    Gpt_PriParamCheck(GPT_STATE_UNINIT == Gpt_PubGlobalState, GPT_STARTTIMER_ID, GPT_E_UNINIT, &RetVal);
    /* SWS_Gpt_00212 */
    Gpt_PriParamCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, GPT_STARTTIMER_ID, GPT_E_PARAM_CHANNEL, &RetVal);

    if(E_OK == RetVal)
    {
        /* SWS_Gpt_00084 */
        Gpt_PriParamRuntimeCheck(Gpt_PubGlobal.GptChannelStatus[Channel] == GPT_CH_STATUS_RUNNING, GPT_STARTTIMER_ID, GPT_E_BUSY, &RetVal);
        /* SWS_Gpt_00218 */
        Gpt_PriParamCheck((0 == Value) || (Value > Gpt_PubChannelConfig[Channel].GptChannelTickValueMax), GPT_STARTTIMER_ID, GPT_E_PARAM_VALUE, &RetVal);

        if(E_OK == RetVal)
        {
            Ret = Gpt_Hw_StartTimer(Channel,Value);
            if(TT_RET_SUCCESS == Ret)
            {
                Gpt_PubGlobal.GptTargetValue[Channel] = Value;
                Gpt_PubGlobal.GptChannelStatus[Channel] = GPT_CH_STATUS_RUNNING;
            }
            else
            {
                Gpt_PriParamCheck(TRUE, GPT_STARTTIMER_ID, GPT_E_SYSTEM, &RetVal);
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
}

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
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    Std_ReturnType RetVal = E_OK;
    TT_RetType Ret = TT_RET_SUCCESS;

    /* SWS_Gpt_00225 */
    Gpt_PriParamCheck(GPT_STATE_UNINIT == Gpt_PubGlobalState, GPT_STOPTIMER_ID, GPT_E_UNINIT, &RetVal);
    /* SWS_Gpt_00213 */
    Gpt_PriParamCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, GPT_STOPTIMER_ID, GPT_E_PARAM_CHANNEL, &RetVal);

    if(E_OK == RetVal)
    {
        Ret = Gpt_Hw_StopTimer(Channel);
        if(TT_RET_SUCCESS == Ret)
        {
            Gpt_PubGlobal.GptChannelStatus[Channel] = GPT_CH_STATUS_STOPPED;
        }
        else
        {
            Gpt_PriParamCheck(TRUE, GPT_STOPTIMER_ID, GPT_E_SYSTEM, &RetVal);
        }
    }
    else
    {
        /* do nothing */
    }
}

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
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    Std_ReturnType RetVal = E_OK;

    /* SWS_Gpt_00226 */
    Gpt_PriParamCheck(GPT_STATE_UNINIT == Gpt_PubGlobalState, GPT_ENABLENOTIFICATION_ID, GPT_E_UNINIT, &RetVal);
    /* SWS_Gpt_00214 */
    Gpt_PriParamCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, GPT_ENABLENOTIFICATION_ID, GPT_E_PARAM_CHANNEL, &RetVal);

    if(E_OK == RetVal)
    {
        /* SWS_Gpt_00377 */
        Gpt_PriParamCheck((NULL_PTR == Gpt_PubChannelConfig[Channel].GptChannelNotification), GPT_ENABLENOTIFICATION_ID, GPT_E_PARAM_CHANNEL, &RetVal);

        if(E_OK == RetVal)
        {
            Gpt_PubGlobal.GptChannelNotificationStatus[Channel] = TRUE;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
}

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
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    Std_ReturnType RetVal = E_OK;

    /* SWS_Gpt_00227 */
    Gpt_PriParamCheck(GPT_STATE_UNINIT == Gpt_PubGlobalState, GPT_DISABLENOTIFICATION_ID, GPT_E_UNINIT, &RetVal);
    /* SWS_Gpt_00217 */
    Gpt_PriParamCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, GPT_DISABLENOTIFICATION_ID, GPT_E_PARAM_CHANNEL, &RetVal);

    if(E_OK == RetVal)
    {
        /* SWS_Gpt_00379 */
        Gpt_PriParamCheck((NULL_PTR == Gpt_PubChannelConfig[Channel].GptChannelNotification), GPT_DISABLENOTIFICATION_ID, GPT_E_PARAM_CHANNEL, &RetVal);

        if(E_OK == RetVal)
        {
            Gpt_PubGlobal.GptChannelNotificationStatus[Channel] = FALSE;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
#endif

#if (defined(GPT_WAKEUP_FUNCTIONALITY_API) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
#define GPT_START_SEC_CODE_SLOW
#include "Gpt_MemMap.h"

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
void Gpt_SetMode(Gpt_ModeType Mode)
{
    /* no support */
}

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
void Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
    /* no support */
}

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
void Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
    /* no support */
}

#ifdef USING_OS_AUTOSAROS
/******************************************************************************
*  Service name    : Gpt_CheckWakeup
*  Syntax          : void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
*  Service ID      : 0x0c
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : WakeupSource:Information on wakeup source to be checked.
*                                 The associated GPT channel can be determined from configuration data.
*  Parameters (out): None
*  Return value    : None
*  Description     : Checks if a wakeup capable GPT channel is the source for a wakeup event and calls
*                    the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
******************************************************************************/
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    /* no support */
}
#endif

#define GPT_STOP_SEC_CODE_LOW
#include "Gpt_MemMap.h"
#endif

#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

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
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)
{
    Std_ReturnType RetVal = E_OK;

    /* SWS_Gpt_00398 */
    Gpt_PriParamCheck(GPT_STATE_UNINIT == Gpt_PubGlobalState, GPT_GETPREDEFTIMERVALUE_ID, GPT_E_UNINIT, &RetVal);
    /* SWS_Gpt_00399 */
    Gpt_PriParamCheck((GPT_PREDEF_TIMER_1US_16BIT != PredefTimer) && \
                      (GPT_PREDEF_TIMER_1US_24BIT != PredefTimer) && \
                      (GPT_PREDEF_TIMER_1US_32BIT != PredefTimer) && \
                      (GPT_PREDEF_TIMER_100US_32BIT != PredefTimer), GPT_GETPREDEFTIMERVALUE_ID, GPT_E_PARAM_PREDEF_TIMER, &RetVal);
    /* SWS_Gpt_00400 */
#if (GPT_PREDEF_TIMER_1US_16BIT_ENABLE != STD_ON)
    Gpt_PriParamCheck(GPT_PREDEF_TIMER_1US_16BIT == PredefTimer, GPT_GETPREDEFTIMERVALUE_ID, GPT_E_PARAM_PREDEF_TIMER, &RetVal);
#endif
#if (GPT_PREDEF_TIMER_1US_24BIT_ENABLE != STD_ON)
    Gpt_PriParamCheck(GPT_PREDEF_TIMER_1US_24BIT == PredefTimer, GPT_GETPREDEFTIMERVALUE_ID, GPT_E_PARAM_PREDEF_TIMER, &RetVal);
#endif
#if (GPT_PREDEF_TIMER_1US_32BIT_ENABLE != STD_ON)
    Gpt_PriParamCheck(GPT_PREDEF_TIMER_1US_32BIT == PredefTimer, GPT_GETPREDEFTIMERVALUE_ID, GPT_E_PARAM_PREDEF_TIMER, &RetVal);
#endif
#if (GPT_PREDEF_TIMER_100US_32BIT_ENABLE != STD_ON)
    Gpt_PriParamCheck(GPT_PREDEF_TIMER_100US_32BIT == PredefTimer, GPT_GETPREDEFTIMERVALUE_ID, GPT_E_PARAM_PREDEF_TIMER, &RetVal);
#endif

    /* SWS_Gpt_00401 */
    Gpt_PriParamCheck(GPT_MODE_SLEEP == Gpt_PubMode, GPT_GETPREDEFTIMERVALUE_ID, GPT_E_MODE, &RetVal);
    /* SWS_Gpt_00403 */
    Gpt_PriParamCheck(NULL_PTR == TimeValuePtr, GPT_GETPREDEFTIMERVALUE_ID, GPT_E_PARAM_POINTER, &RetVal);

    if(E_OK == RetVal)
    {
        switch(PredefTimer)
        {
            case GPT_PREDEF_TIMER_1US_16BIT:
                *TimeValuePtr = Gpt_PubPredefTimeValue.Gpt1us16bitNumber;
                break;
            case GPT_PREDEF_TIMER_1US_24BIT:
                *TimeValuePtr = Gpt_PubPredefTimeValue.Gpt1us24bitNumber;
                break;
            case GPT_PREDEF_TIMER_1US_32BIT:
                *TimeValuePtr = Gpt_PubPredefTimeValue.Gpt1us32bitNumber;
                break;
            case GPT_PREDEF_TIMER_100US_32BIT:
                *TimeValuePtr = Gpt_PubPredefTimeValue.Gpt100us32bitNumber;
                break;
            default:
                /* do nothing */
                break;
        }
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"

#ifdef GPT_FTM0
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief        ISR(FTM0_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM0_IRQHandler)
{
    Gpt_Hw_ClearOverflowIrqFlag(FTM0);

#ifdef GPT_PREDEF_TIMER_1US_16BIT_ENABLE_FTM0
    Gpt_PriProcessData1Us16Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_24BIT_ENABLE_FTM0
    Gpt_PriProcessData1Us24Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_32BIT_ENABLE_FTM0
    Gpt_PriProcessData1Us32Bit();
#endif

#ifdef GPT_PREDEF_TIMER_100US_32BIT_ENABLE_FTM0
    Gpt_PriProcessData100Us32Bit();
#endif

#ifdef GPT_CHANNEL_TIMER_FTM0
    Gpt_PriProcessInterrupt(FTM0);
#endif
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#ifdef GPT_FTM1
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief        ISR(FTM1_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM1_IRQHandler)
{
    Gpt_Hw_ClearOverflowIrqFlag(FTM1);

#ifdef GPT_PREDEF_TIMER_1US_16BIT_ENABLE_FTM1
    Gpt_PriProcessData1Us16Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_24BIT_ENABLE_FTM1
    Gpt_PriProcessData1Us24Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_32BIT_ENABLE_FTM1
    Gpt_PriProcessData1Us32Bit();
#endif

#ifdef GPT_PREDEF_TIMER_100US_32BIT_ENABLE_FTM1
    Gpt_PriProcessData100Us32Bit();
#endif

#ifdef GPT_CHANNEL_TIMER_FTM1
    Gpt_PriProcessInterrupt(FTM1);
#endif
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#ifdef GPT_FTM2
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief        ISR(FTM2_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM2_IRQHandler)
{
    Gpt_Hw_ClearOverflowIrqFlag(FTM2);

#ifdef GPT_PREDEF_TIMER_1US_16BIT_ENABLE_FTM2
    Gpt_PriProcessData1Us16Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_24BIT_ENABLE_FTM2
    Gpt_PriProcessData1Us24Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_32BIT_ENABLE_FTM2
    Gpt_PriProcessData1Us32Bit();
#endif

#ifdef GPT_PREDEF_TIMER_100US_32BIT_ENABLE_FTM2
    Gpt_PriProcessData100Us32Bit();
#endif

#ifdef GPT_CHANNEL_TIMER_FTM2
    Gpt_PriProcessInterrupt(FTM2);
#endif
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#ifdef GPT_FTM3
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief        ISR(FTM3_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM3_IRQHandler)
{
    Gpt_Hw_ClearOverflowIrqFlag(FTM3);

#ifdef GPT_PREDEF_TIMER_1US_16BIT_ENABLE_FTM3
    Gpt_PriProcessData1Us16Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_24BIT_ENABLE_FTM3
    Gpt_PriProcessData1Us24Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_32BIT_ENABLE_FTM3
    Gpt_PriProcessData1Us32Bit();
#endif

#ifdef GPT_PREDEF_TIMER_100US_32BIT_ENABLE_FTM3
    Gpt_PriProcessData100Us32Bit();
#endif

#ifdef GPT_CHANNEL_TIMER_FTM3
    Gpt_PriProcessInterrupt(FTM3);
#endif
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#ifdef GPT_FTM4
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief        ISR(FTM4_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM4_IRQHandler)
{
    Gpt_Hw_ClearOverflowIrqFlag(FTM4);

#ifdef GPT_PREDEF_TIMER_1US_16BIT_ENABLE_FTM4
    Gpt_PriProcessData1Us16Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_24BIT_ENABLE_FTM4
    Gpt_PriProcessData1Us24Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_32BIT_ENABLE_FTM4
    Gpt_PriProcessData1Us32Bit();
#endif

#ifdef GPT_PREDEF_TIMER_100US_32BIT_ENABLE_FTM4
    Gpt_PriProcessData100Us32Bit();
#endif

#ifdef GPT_CHANNEL_TIMER_FTM4
    Gpt_PriProcessInterrupt(FTM4);
#endif
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#ifdef GPT_FTM5
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief        ISR(FTM5_IRQHandler)
* @details      Interrupt service function.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
ISR(FTM5_IRQHandler)
{
    Gpt_Hw_ClearOverflowIrqFlag(FTM5);

#ifdef GPT_PREDEF_TIMER_1US_16BIT_ENABLE_FTM5
    Gpt_PriProcessData1Us16Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_24BIT_ENABLE_FTM5
    Gpt_PriProcessData1Us24Bit();
#endif

#ifdef GPT_PREDEF_TIMER_1US_32BIT_ENABLE_FTM5
    Gpt_PriProcessData1Us32Bit();
#endif

#ifdef GPT_PREDEF_TIMER_100US_32BIT_ENABLE_FTM5
    Gpt_PriProcessData100Us32Bit();
#endif

#ifdef GPT_CHANNEL_TIMER_FTM5
    Gpt_PriProcessInterrupt(FTM5);
#endif
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

/******************************************************************************
*                            Private Functions
******************************************************************************/
#if (defined(GPT_CHANNEL_TIMER_FTM0) || defined(GPT_CHANNEL_TIMER_FTM1) || defined(GPT_CHANNEL_TIMER_FTM2) || \
    defined(GPT_CHANNEL_TIMER_FTM3) || defined(GPT_CHANNEL_TIMER_FTM4) || defined(GPT_CHANNEL_TIMER_FTM5))
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief         Gpt_PriProcessInterrupt
* @details       The function is to handle interrupt transactions.
* @param[in]     FtmModule - FTM module
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessInterrupt(uint8 FtmModule)
{
    Gpt_ChannelType Channel = 0;

    Channel = Gpt_PubConfig->GptFtmHardwareChannelMap[FtmModule];
    if(Gpt_PubChannelConfig[Channel].GptChannelMode == GPT_CH_MODE_ONESHOT)
    {
        Gpt_PubGlobal.GptChannelStatus[Channel] = GPT_CH_STATUS_EXPIRED;
        Gpt_Hw_StopFtmModuleTimer(FtmModule);
    }
    else
    {
        /* do nothing */
    }
    if (Gpt_PubGlobal.GptChannelNotificationStatus[Channel] == TRUE)
    {
        Gpt_PubChannelConfig[Channel].GptChannelNotification();
    }
    else
    {
        /* do nothing */
    }

}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#if (defined(GPT_PREDEF_TIMER_1US_16BIT_ENABLE) && (GPT_PREDEF_TIMER_1US_16BIT_ENABLE == STD_ON))
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief         Gpt_PriProcessData1Us16Bit
* @details       The function is to handle interrupt transactions.
* @param[in]     None
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessData1Us16Bit(void)
{
    Gpt_PubPredefTimeValue.Gpt1us16bitNumber++;
    if(Gpt_PubPredefTimeValue.Gpt1us16bitNumber == GPT_COUNTER_MAX_16BIT)
    {
        Gpt_PubPredefTimeValue.Gpt1us16bitNumber = 0;
    }
    else
    {
        /* do nothing */
    }
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#if (defined(GPT_PREDEF_TIMER_1US_24BIT_ENABLE) && (GPT_PREDEF_TIMER_1US_24BIT_ENABLE == STD_ON))
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief         Gpt_PriProcessData1Us24Bit
* @details       The function is to handle interrupt transactions.
* @param[in]     None
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessData1Us24Bit(void)
{
    Gpt_PubPredefTimeValue.Gpt1us24bitNumber++;
    if(Gpt_PubPredefTimeValue.Gpt1us24bitNumber == GPT_COUNTER_MAX_24BIT)
    {
        Gpt_PubPredefTimeValue.Gpt1us24bitNumber = 0;
    }
    else
    {
        /* do nothing */
    }
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#if (defined(GPT_PREDEF_TIMER_1US_32BIT_ENABLE) && (GPT_PREDEF_TIMER_1US_32BIT_ENABLE == STD_ON))
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief         Gpt_PriProcessData1Us32Bit
* @details       The function is to handle interrupt transactions.
* @param[in]     None
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessData1Us32Bit(void)
{
    Gpt_PubPredefTimeValue.Gpt1us32bitNumber++;
    if(Gpt_PubPredefTimeValue.Gpt1us32bitNumber == GPT_COUNTER_MAX_32BIT)
    {
        Gpt_PubPredefTimeValue.Gpt1us32bitNumber = 0;
    }
    else
    {
        /* do nothing */
    }
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#if (defined(GPT_PREDEF_TIMER_100US_32BIT_ENABLE) && (GPT_PREDEF_TIMER_100US_32BIT_ENABLE == STD_ON))
#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief         Gpt_PriProcessData100Us32Bit
* @details       The function is to handle interrupt transactions.
* @param[in]     None
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
static void Gpt_PriProcessData100Us32Bit(void)
{
    Gpt_PubPredefTimeValue.Gpt1usNumber++;
    if(Gpt_PubPredefTimeValue.Gpt1usNumber == GPT_COUTER_100US)
    {
        Gpt_PubPredefTimeValue.Gpt1usNumber = 0;
        Gpt_PubPredefTimeValue.Gpt100us32bitNumber++;
        if(Gpt_PubPredefTimeValue.Gpt100us32bitNumber == GPT_COUNTER_MAX_32BIT)
        {
            Gpt_PubPredefTimeValue.Gpt100us32bitNumber = 0;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"
#endif

#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"

/**
* @brief         Gpt_PriParamCheck
* @details       Reports Det error if GPT_DEV_ERROR_DETECT == STD_ON.(ModuleDet_ReportError).
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        void
* @retval        None
* @pre
*/
LOCAL_INLINE void Gpt_PriParamCheck(boolean Expr, uint8 ApiId, uint8 ErrId, Std_ReturnType *RetVal)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == E_OK) && (TRUE == Expr))
        {
#if (defined(GPT_DEV_ERROR_DETECT) && (GPT_DEV_ERROR_DETECT == STD_ON))
            TT_DET_REPORT_ERR(GPT_MODULE_ID_C, GPT_INSTANCE_ID, ApiId, ErrId);
#else
            (void)ApiId;
            (void)ErrId;
#endif
            *RetVal = E_NOT_OK;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    *RetVal = (RetVal >= (Std_ReturnType *)1) ? E_OK : E_NOT_OK;
#endif
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
* @brief         Gpt_PriParamRuntimeCheck
* @details       Reports Det error if GPT_DEV_ERROR_DETECT == STD_ON.(ModuleDet_ReportRuntimeError).
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        void
* @retval        None
* @pre
*/
LOCAL_INLINE void Gpt_PriParamRuntimeCheck(boolean Expr, uint8 ApiId, uint8 ErrId, Std_ReturnType *RetVal)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == E_OK) && (TRUE == Expr))
        {
#if (defined(GPT_DEV_ERROR_DETECT) && (GPT_DEV_ERROR_DETECT == STD_ON))
            TT_DET_REPORT_RUNTIME_ERR(GPT_MODULE_ID_C, GPT_INSTANCE_ID, ApiId, ErrId);
#else
            (void)ApiId;
            (void)ErrId;
#endif
            *RetVal = E_NOT_OK;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    *RetVal = (RetVal >= (Std_ReturnType *)1) ? E_OK : E_NOT_OK;
#endif
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#define GPT_START_SEC_CODE_SLOW
#include "Gpt_MemMap.h"

/**
* @brief        Gpt_PriInitParaCrcCheck
* @details      This function performs a Crc check on the module default configuration data.
* @param[in]    RetVal : E_OK - Crc check success.
*                        E_NOT_OK - Crc check failed
* @param[out]   None
* @return       Std_ReturnType
* @retval       E_OK - Crc check success.
*               E_NOT_OK - Crc check failed
* @pre
*/
LOCAL_INLINE Std_ReturnType Gpt_PriInitParaCrcCheck(Std_ReturnType RetVal)
{
    uint32 GptCrc = 0U;

#if (GPT_PREDEF_TIMER_ONLY != STD_ON)
    uint8 Channel = 0;
    uint8 FtmChannel = 0;
#endif

    uint8 FtmModule = 0;

    if(E_OK == RetVal)
    {
#if (GPT_PREDEF_TIMER_ONLY != STD_ON)
        for(FtmModule = 0; FtmModule < FTM_MODULE_NUMBER; FtmModule++)
        {
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmHardwareChannelMap[FtmModule],&GptCrc);
        }
        for(Channel = 0; Channel < GPT_CHANNEL_CONFIG_NUMBER; Channel++)
        {
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptChannelConfig[Channel].GptChannelMode,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptChannelConfig[Channel].GptChannelTickValueMax,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptChannelConfig[Channel].GptChannelTickFrequency,&GptCrc);
        }
        for(FtmChannel = 0; FtmChannel < GPT_CHANNEL_CONFIG_NUMBER; FtmChannel++)
        {
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmChannelConfig[FtmChannel].GptFtmHardwareChannel,&GptCrc);
        }
        for(FtmModule = 0; FtmModule < GPT_FTM_MODULE_CONFIG_NUMBER; FtmModule++)
        {
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmModuleConfig[FtmModule].GptFtmModule,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmModuleConfig[FtmModule].GptFtmConfRegValue,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmModuleConfig[FtmModule].GptFtmScRegValue,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmModuleConfig[FtmModule].GptScuClkControl,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmModuleConfig[FtmModule].GptScuLocalRst,&GptCrc);
        }
#endif

#if (GPT_ONLY != STD_ON)
        for(FtmModule = 0; FtmModule < GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER; FtmModule++)
        {
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmPredefTimerConfig[FtmModule].GptFtmModule,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmPredefTimerConfig[FtmModule].GptFtmModRegValue,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmPredefTimerConfig[FtmModule].GptScuClkControl,&GptCrc);
            Base_AccumulateCRC((uint32)Gpt_PubConfig->GptFtmPredefTimerConfig[FtmModule].GptScuLocalRst,&GptCrc);
        }
#endif

        if(Gpt_PubConfig->GptCrc != Base_FinalizeCRC(&GptCrc))
        {
            RetVal = E_NOT_OK;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

#define GPT_STOP_SEC_CODE_SLOW
#include "Gpt_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif
