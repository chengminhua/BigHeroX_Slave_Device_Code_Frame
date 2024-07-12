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
**  FILENAME     : Gpt_Hw.c                                                   **
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
#include "Gpt_Hw.h"
#include "Mcu_Drv.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GPT_HW_VENDOR_ID_C                      1541
#define GPT_HW_MODULE_ID_C                      100
#define GPT_HW_AR_RELEASE_MAJOR_VERSION_C       4
#define GPT_HW_AR_RELEASE_MINOR_VERSION_C       4
#define GPT_HW_AR_RELEASE_PATCH_VERSION_C       0
#define GPT_HW_SW_MAJOR_VERSION_C               1
#define GPT_HW_SW_MINOR_VERSION_C               1
#define GPT_HW_SW_PATCH_VERSION_C               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gpt_Hw.h Gpt_Hw.c file version check */
#if (GPT_HW_VENDOR_ID_C != GPT_HW_VENDOR_ID_H)
    #error "Gpt_Hw.h and Gpt_Hw.c have different vendor id"
#endif

#if (GPT_HW_MODULE_ID_C != GPT_HW_MODULE_ID_H)
    #error "Gpt_Hw.h and Gpt_Hw.c have different module id"
#endif

#if ((GPT_HW_AR_RELEASE_MAJOR_VERSION_C != GPT_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_HW_AR_RELEASE_MINOR_VERSION_C != GPT_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_HW_AR_RELEASE_PATCH_VERSION_C != GPT_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_Hw.h and Gpt_Hw.c are different"
#endif

#if ((GPT_HW_SW_MAJOR_VERSION_C != GPT_HW_SW_MAJOR_VERSION_H) || \
     (GPT_HW_SW_MINOR_VERSION_C != GPT_HW_SW_MINOR_VERSION_H) || \
     (GPT_HW_SW_PATCH_VERSION_C != GPT_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_Hw.h and Gpt_Hw.c are different"
#endif

/* Mcu_Drv.h Gpt_Hw.c file version check */
#if (GPT_HW_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Mcu_Drv.h and Gpt_Hw.c have different vendor id"
#endif

#if ((GPT_HW_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_HW_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_HW_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.h and Gpt_Hw.c are different"
#endif

#if ((GPT_HW_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (GPT_HW_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (GPT_HW_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.h and Gpt_Hw.c are different"
#endif

/******************************************************************************
*                            Private Variables
*******************************************************************************/
#define GPT_START_SEC_VAR_CLEARED_PTR
#include "Gpt_MemMap.h"

/* GPT predef timer configuration of the FTM module */
static TT_CONST Gpt_Hw_FtmPredefTimerConfigType* Gpt_PubFtmPredefTimerConfig;

/* Channel configuration of the FTM module */
static TT_CONST Gpt_Hw_FtmChannelConfigType* Gpt_PubFtmChannelConfig;

/* Module configuration of the FTM module */
static TT_CONST Gpt_Hw_FtmModuleConfigType* Gpt_PubFtmModuleConfig;

#define GPT_STOP_SEC_VAR_CLEARED_PTR
#include "Gpt_MemMap.h"

/******************************************************************************
*                    Private Function Declaration
******************************************************************************/
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gpt_Hw_PriChannelTimerInitCheck
* @details      TThe function is to check the GPT driver initialization configuration.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - error code
* @pre
*/
static TT_RetType Gpt_Hw_PriChannelTimerInitCheck(void);

/**
* @brief        Gpt_Hw_PriPredefTimerInitCheck
* @details      The function is to check the GPT predef timer driver initialization configuration.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - error code
* @pre
*/
static TT_RetType Gpt_Hw_PriPredefTimerInitCheck(void);

/**
* @brief        Gpt_Hw_PriRegReadBack
* @details      The function is to determine whether the register read back is correct.
* @param[in]    ActualValue - Actual value
* @param[in]    TargetValue - Target value
* @param[out]   Ret - error code
* @return       void
* @retval       None
* @pre
*/
LOCAL_INLINE void Gpt_Hw_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret);
#endif

/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define GPT_START_SEC_CODE_SLOW
#include "Gpt_MemMap.h"
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
TT_RetType Gpt_Hw_Init(TT_CONST Gpt_Hw_FtmChannelConfigType* FtmChannelConfigPtr, TT_CONST Gpt_Hw_FtmModuleConfigType* FtmModuleConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Module = 0;
    uint8 FtmModule = 0;
    TT_CONST Gpt_Hw_FtmChannelConfigType *ChannelConfig = NULL_PTR;
    TT_CONST Gpt_Hw_FtmModuleConfigType *ModuleConfig = NULL_PTR;

    TT_ParaCheck(NULL_PTR == FtmChannelConfigPtr, TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck(NULL_PTR == FtmModuleConfigPtr, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        ChannelConfig = FtmChannelConfigPtr;
        ModuleConfig = FtmModuleConfigPtr;
        Gpt_PubFtmChannelConfig = ChannelConfig;
        Gpt_PubFtmModuleConfig = ModuleConfig;
        for(Module = 0; Module < GPT_FTM_MODULE_CONFIG_NUMBER; Module++)
        {
            if((TT_RET_SUCCESS == Mcu_Drv_Clk_StartModules(Gpt_PubFtmModuleConfig[Module].GptScuClkControl)))
            {
                FtmModule = Gpt_PubFtmModuleConfig[Module].GptFtmModule;
                Ftm_PubReg[FtmModule]->MOD = (uint32)65535;
                Ftm_PubReg[FtmModule]->CNTIN = (uint32)1;
                Ftm_PubReg[FtmModule]->CNT = (uint32)1;
                Ftm_PubReg[FtmModule]->MODE |= (uint32)1;
                Ftm_PubReg[FtmModule]->CONF = Gpt_PubFtmModuleConfig[Module].GptFtmConfRegValue;
                Ftm_PubReg[FtmModule]->SC |= Gpt_PubFtmModuleConfig[Module].GptFtmScRegValue & TT_FTM_SC_PS_Msk;
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
                break;
            }
        }
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if(TT_RET_SUCCESS == Ret)
        {
            Ret = Gpt_Hw_PriChannelTimerInitCheck();
        }
        else
        {
            /* do nothing */
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE_SLOW
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE_SLOW
#include "Gpt_MemMap.h"
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
TT_RetType Gpt_Hw_PredefTimerInit(TT_CONST Gpt_Hw_FtmPredefTimerConfigType* FtmPredefTimerConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Module = 0;
    uint8 FtmModule = 0;
    TT_CONST Gpt_Hw_FtmPredefTimerConfigType* PredefTimerConfig = NULL_PTR;

    TT_ParaCheck(NULL_PTR == FtmPredefTimerConfigPtr, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        PredefTimerConfig = FtmPredefTimerConfigPtr;
        Gpt_PubFtmPredefTimerConfig = PredefTimerConfig;
        for(Module = 0; Module < GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER; Module++)
        {
            if((TT_RET_SUCCESS == Mcu_Drv_Clk_StartModules(Gpt_PubFtmPredefTimerConfig[Module].GptScuClkControl)))
            {
                FtmModule = Gpt_PubFtmPredefTimerConfig[Module].GptFtmModule;
                Ftm_PubReg[FtmModule]->MOD = (uint32)Gpt_PubFtmPredefTimerConfig[Module].GptFtmModRegValue;
                Ftm_PubReg[FtmModule]->MODE |= (uint32)1;
                Ftm_PubReg[FtmModule]->SC |= ((uint32)1 << TT_FTM_SC_TOIE_Pos) | ((uint32)1 << TT_FTM_SC_CLKS_Pos);
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
                break;
            }
        }
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if(TT_RET_SUCCESS == Ret)
        {
            Ret = Gpt_Hw_PriPredefTimerInitCheck();
        }
        else
        {
            /* do nothing */
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE_SLOW
#include "Gpt_MemMap.h"

#if (GPT_DEINIT_API == STD_ON)
#define GPT_START_SEC_CODE_SLOW
#include "Gpt_MemMap.h"
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
TT_RetType Gpt_Hw_DeInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Module = 0;

    for(Module = 0; Module < GPT_FTM_MODULE_CONFIG_NUMBER; Module++)
    {
        if((TT_RET_SUCCESS != Mcu_Drv_Clk_StopModules(Gpt_PubFtmModuleConfig[Module].GptScuClkControl)) || \
           (TT_RET_SUCCESS != Mcu_Drv_Misc_LocalResetModules(Gpt_PubFtmModuleConfig[Module].GptScuLocalRst)))
        {
            Ret = TT_RET_STATUS_ERR;
            break;
        }
        else
        {
            /* do nothing */
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE_SLOW
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE_SLOW
#include "Gpt_MemMap.h"
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
TT_RetType Gpt_Hw_PredefTimerDeInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Module = 0;

    for(Module = 0; Module < GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER; Module++)
    {
        if((TT_RET_SUCCESS != Mcu_Drv_Clk_StopModules(Gpt_PubFtmPredefTimerConfig[Module].GptScuClkControl)) || \
           (TT_RET_SUCCESS != Mcu_Drv_Misc_LocalResetModules(Gpt_PubFtmPredefTimerConfig[Module].GptScuLocalRst)))
        {
            Ret = TT_RET_STATUS_ERR;
            break;
        }
        else
        {
            /* do nothing */
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE_SLOW
#include "Gpt_MemMap.h"
#endif

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
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
TT_RetType Gpt_Hw_StartTimer(Gpt_Hw_ChannelType Channel, Gpt_Hw_ValueType Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 FtmModule = 0;

    TT_ParaCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck(Value == 0, TT_RET_PARAM_VALUE_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        FtmModule = GET_FTM_MODULE(Gpt_PubFtmChannelConfig[Channel].GptFtmHardwareChannel);
        Ftm_PubReg[FtmModule]->CNT = 1;
        Ftm_PubReg[FtmModule]->CNTIN = 1;
        Ftm_PubReg[FtmModule]->MOD = (uint32)Value;
        Ftm_PubReg[FtmModule]->SC |= ((uint32)1 << TT_FTM_SC_TOIE_Pos) | (Gpt_PubFtmModuleConfig[Channel].GptFtmScRegValue & TT_FTM_SC_CLKS_Msk);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        Gpt_Hw_PriRegReadBack(Ftm_PubReg[FtmModule]->MOD,(uint32)Value,&Ret);
        Gpt_Hw_PriRegReadBack(Ftm_PubReg[FtmModule]->SC & TT_FTM_SC_TOIE_Msk,(uint32)1 << TT_FTM_SC_TOIE_Pos,&Ret);
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
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
TT_RetType Gpt_Hw_StopTimer(Gpt_Hw_ChannelType Channel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 FtmModule = 0;

    TT_ParaCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        FtmModule = GET_FTM_MODULE(Gpt_PubFtmChannelConfig[Channel].GptFtmHardwareChannel);
        Ftm_PubReg[FtmModule]->CNTIN = 0;
        Ftm_PubReg[FtmModule]->SC &= ~(TT_FTM_SC_CLKS_Msk | TT_FTM_SC_TOIE_Msk | TT_FTM_SC_TOF_Msk);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        Gpt_Hw_PriRegReadBack(Ftm_PubReg[FtmModule]->CNTIN,0,&Ret);
        Gpt_Hw_PriRegReadBack(Ftm_PubReg[FtmModule]->SC & TT_FTM_SC_TOIE_Msk,0,&Ret);
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"
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
TT_RetType Gpt_Hw_GetCounter(Gpt_Hw_ChannelType Channel,Gpt_Hw_ValueType *CounterValue)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 FtmModule = 0;

    TT_ParaCheck(Channel >= GPT_CHANNEL_CONFIG_NUMBER, TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck(NULL_PTR == CounterValue, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        FtmModule = GET_FTM_MODULE(Gpt_PubFtmChannelConfig[Channel].GptFtmHardwareChannel);
        *CounterValue = (Gpt_Hw_ValueType)Ftm_PubReg[FtmModule]->CNT;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_MemMap.h"

#if (defined(GPT_CHANNEL_TIMER_FTM0) || defined(GPT_CHANNEL_TIMER_FTM1) || defined(GPT_CHANNEL_TIMER_FTM2) || \
    defined(GPT_CHANNEL_TIMER_FTM3) || defined(GPT_CHANNEL_TIMER_FTM4) || defined(GPT_CHANNEL_TIMER_FTM5))
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/**
* @brief         Gpt_Hw_StopFtmModuleTimer
* @details       Stop the FTM module timer.
* @param[in]     FtmModule - FTM module
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
void Gpt_Hw_StopFtmModuleTimer(uint8 FtmModule)
{
    Ftm_PubReg[FtmModule]->CNTIN = 0;
    Ftm_PubReg[FtmModule]->SC &= ~(TT_FTM_SC_CLKS_Msk | TT_FTM_SC_TOIE_Msk | TT_FTM_SC_TOF_Msk);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/**
* @brief         Gpt_Hw_ClearOverflowIrqFlag
* @details       Clear the overflow interrupt flag.
* @param[in]     FtmModule - FTM module
* @param[out]    None
* @return        void
* @retval        None
* @pre
*/
void Gpt_Hw_ClearOverflowIrqFlag(uint8 FtmModule)
{
    Ftm_PubReg[FtmModule]->SC &= ~TT_FTM_SC_TOF_Msk;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
#endif

/******************************************************************************
*                            Private Functions
******************************************************************************/
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#define GPT_START_SEC_CODE_SLOW
#include "Gpt_MemMap.h"
/**
* @brief        Gpt_Hw_PriChannelTimerInitCheck
* @details      TThe function is to check the GPT driver initialization configuration.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - error code
* @pre
*/
static TT_RetType Gpt_Hw_PriChannelTimerInitCheck(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Module = 0;
    uint8 FtmModule = 0;
    uint32 FtmScValue = 0;
    uint32 FtmConfValue = 0;

    for(Module = 0; Module < GPT_FTM_MODULE_CONFIG_NUMBER; Module++)
    {
        FtmModule = Gpt_PubFtmModuleConfig[Module].GptFtmModule;
        FtmScValue = Gpt_PubFtmModuleConfig[Module].GptFtmScRegValue & TT_FTM_SC_PS_Msk;
        FtmConfValue = Gpt_PubFtmModuleConfig[Module].GptFtmConfRegValue;
        Gpt_Hw_PriRegReadBack(FtmScValue,Ftm_PubReg[FtmModule]->SC & (uint32)0x07,&Ret);
        Gpt_Hw_PriRegReadBack(FtmConfValue,Ftm_PubReg[FtmModule]->CONF,&Ret);
    }

    return Ret;
}

/**
* @brief        Gpt_Hw_PriPredefTimerInitCheck
* @details      The function is to check the GPT predef timer driver initialization configuration.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - error code
* @pre
*/
static TT_RetType Gpt_Hw_PriPredefTimerInitCheck(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Module = 0;
    uint8 FtmModule = 0;
    uint32 FtmModValue = 0;

    for(Module = 0; Module < GPT_FTM_PERDEF_TIMER_CONFIG_NUMBER; Module++)
    {
        FtmModule = Gpt_PubFtmPredefTimerConfig[Module].GptFtmModule;
        FtmModValue = Gpt_PubFtmPredefTimerConfig[Module].GptFtmModRegValue;
        Gpt_Hw_PriRegReadBack(FtmModValue,Ftm_PubReg[FtmModule]->MOD,&Ret);
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE_SLOW
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE_FAST
#include "Gpt_MemMap.h"
/**
* @brief        Gpt_Hw_PriRegReadBack
* @details      The function is to determine whether the register read back is correct.
* @param[in]    ActualValue - Actual value
* @param[in]    TargetValue - Target value
* @param[out]   Ret - error code
* @return       void
* @retval       None
* @pre
*/
LOCAL_INLINE void Gpt_Hw_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret)
{
    if(TT_RET_SUCCESS == *Ret)
    {
        if(ActualValue != TargetValue)
        {
            *Ret = TT_RET_OPT_REG_ERR;
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

#ifdef __cplusplus
}
#endif
