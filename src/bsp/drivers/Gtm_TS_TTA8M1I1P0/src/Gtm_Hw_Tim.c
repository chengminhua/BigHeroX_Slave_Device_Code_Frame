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
**  FILENAME     : Gtm_Hw_Tim.c                                               **
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
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                              Include Files
 ******************************************************************************/
#include "Gtm_Hw_Tim.h"
#include "Gtm_Hw_Cmu.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Gtm.h"
#endif

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define GTM_HW_TIM_VENDOR_ID_C                      1541
#define GTM_HW_TIM_MODULE_ID_C                      221
#define GTM_HW_TIM_AR_RELEASE_MAJOR_VERSION_C       4
#define GTM_HW_TIM_AR_RELEASE_MINOR_VERSION_C       4
#define GTM_HW_TIM_AR_RELEASE_PATCH_VERSION_C       0
#define GTM_HW_TIM_SW_MAJOR_VERSION_C               1
#define GTM_HW_TIM_SW_MINOR_VERSION_C               1
#define GTM_HW_TIM_SW_PATCH_VERSION_C               0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Gtm_Hw_Tim.h Gtm_Hw_Tim.c file version check */
#if (GTM_HW_TIM_VENDOR_ID_H != GTM_HW_TIM_VENDOR_ID_C)
    #error "Gtm_Hw_Tim.h and Gtm_Hw_Tim.c have different vendor ids"
#endif
#if (GTM_HW_TIM_MODULE_ID_H != GTM_HW_TIM_MODULE_ID_C)
    #error "Gtm_Hw_Tim.h and Gtm_Hw_Tim.c have different module ids"
#endif
#if ((GTM_HW_TIM_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TIM_AR_RELEASE_MAJOR_VERSION_C) || \
     (GTM_HW_TIM_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TIM_AR_RELEASE_MINOR_VERSION_C) || \
     (GTM_HW_TIM_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TIM_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of Gtm_Hw_Tim.h and Gtm_Hw_Tim.c are different"
#endif
#if ((GTM_HW_TIM_SW_MAJOR_VERSION_H != GTM_HW_TIM_SW_MAJOR_VERSION_C) || \
     (GTM_HW_TIM_SW_MINOR_VERSION_H != GTM_HW_TIM_SW_MINOR_VERSION_C) || \
     (GTM_HW_TIM_SW_PATCH_VERSION_H != GTM_HW_TIM_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Gtm_Hw_Tim.h and Gtm_Hw_Tim.c are different"
#endif

/* Gtm_Hw_Cmu.h Gtm_Hw_Tim.c file version check */
#if (GTM_HW_CMU_VENDOR_ID_H != GTM_HW_TIM_VENDOR_ID_C)
    #error "Gtm_Hw_Cmu.h and Gtm_Hw_Tim.c have different vendor ids"
#endif
#if (GTM_HW_CMU_MODULE_ID_H != GTM_HW_TIM_MODULE_ID_C)
    #error "Gtm_Hw_Cmu.h and Gtm_Hw_Tim.c have different module ids"
#endif
#if ((GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TIM_AR_RELEASE_MAJOR_VERSION_C) || \
     (GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TIM_AR_RELEASE_MINOR_VERSION_C) || \
     (GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TIM_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of Gtm_Hw_Cmu.h and Gtm_Hw_Tim.c are different"
#endif
#if ((GTM_HW_CMU_SW_MAJOR_VERSION_H != GTM_HW_TIM_SW_MAJOR_VERSION_C) || \
     (GTM_HW_CMU_SW_MINOR_VERSION_H != GTM_HW_TIM_SW_MINOR_VERSION_C) || \
     (GTM_HW_CMU_SW_PATCH_VERSION_H != GTM_HW_TIM_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Gtm_Hw_Cmu.h and Gtm_Hw_Tim.c are different"
#endif

#ifdef USING_OS_AUTOSAROS
/* Gtm_Hw_Tim.c SchM_Gtm.h file version check */
#if (GTM_HW_TIM_VENDOR_ID_C != SCHM_GTM_VENDOR_ID_H)
    #error "Gtm_Hw_Tim.c and SchM_Gtm.h have different vendor ids"
#endif
#if ((GTM_HW_TIM_AR_RELEASE_MAJOR_VERSION_C != SCHM_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_TIM_AR_RELEASE_MINOR_VERSION_C != SCHM_GTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_TIM_AR_RELEASE_PATCH_VERSION_C != SCHM_GTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tim.c and SchM_Gtm.h are different"
#endif
#if ((GTM_HW_TIM_SW_MAJOR_VERSION_C != SCHM_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_HW_TIM_SW_MINOR_VERSION_C != SCHM_GTM_SW_MINOR_VERSION_H) || \
     (GTM_HW_TIM_SW_PATCH_VERSION_C != SCHM_GTM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tim.c and SchM_Gtm.h are different"
#endif
#endif
#if defined(TIM_MAX) && (TIM_MAX != 0)

/******************************************************************************
 *                       Global Variables Declaration
 ******************************************************************************/

/******************************************************************************
 *                       Private Variables
 ******************************************************************************/
#define GTM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"

/*Tim global information*/
static Tim_ParamInfoType Tim_ParamInfo = {0};

/* Tim interrupt flag back up */
GTM_TIM_CH_IRQ_NOTIFY_bf_type Tim_PubNotifyFlag = {0};

#define GTM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"

/******************************************************************************
 *                       Private Function Declarations
 ******************************************************************************/

/**
* @brief        Gtm_Hw_Tim_PriSelectGpr0Input
* @details      Configure GPR0 input source .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSelectGpr0Input(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriSelectGpr1Input
* @details      Configure GPR1 input source .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSelectGpr1Input(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriSetSignalEdgeInit
* @details      Configure signal edge .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSetSignalEdgeInit(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriSetCntsInit
* @details      Configure cnts .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSetCntsInit(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriSetTbuTs0Bits
* @details      Configure Tbu channel 0 timebase resolution .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSetTbuTs0Bits(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriValxConfig
* @details      Configure level while channel input is TIM_INPUT_OF_VAL.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriValxConfig(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriChannelConfig
* @details      Configure channel paremeters.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriChannelConfig(uint8 ModuleNo,
                                        uint8 ChannelNo,
                                        TT_CONST Tim_ConfigType *TimConfig,
                                        TT_RetType *Ret
                                        );

/**
* @brief        Gtm_Hw_Tim_PriFilterConfig
* @details      Configure channel filter paremeters.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriFilterConfig(uint8 ModuleNo,
                                       uint8 ChannelNo,
                                       TT_CONST Tim_ConfigType *TimConfig,
                                       TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriTimeOutConfig
* @details      Configure channel timeout paremeters.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriTimeOutConfig(uint8 ModuleNo,
                                        uint8 ChannelNo,
                                        TT_CONST Tim_ConfigType *TimConfig,
                                        TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriAuxInSet
* @details      Configure aux input source.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriAuxInSet(uint8 ModuleNo,
                                   uint8 ChannelNo,
                                   TT_CONST Tim_ConfigType *TimConfig,
                                   TT_RetType *Ret);

/**
* @brief        Gtm_Hw_Tim_PriInputSelect
* @details      Configure tim input source.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriInputSelect(uint8 ModuleNo,
                                      uint8 ChannelNo,
                                      TT_CONST Tim_ConfigType *TimConfig,
                                      TT_RetType *Ret);
/**
* @brief        Gtm_Hw_PriCfgRangeJudge
* @details      Determine the validity range of gtm configuration data.
* @param[in]    TimConfig:   Configuration caontions
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Tim_PriCfgRangeJudge(TT_CONST Tim_ConfigType *TimConfig);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Hw_Tim_InitCheck
* @details      Tim Init Check.
* @param[in]    TimConfig:    Tim config data
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
static TT_RetType Gtm_Hw_Tim_PriInitCheck(TT_CONST Tim_ConfigType *TimConfig);
#endif

#endif
/******************************************************************************
 *                       Public Functions
 ******************************************************************************/
#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

/**
* @brief        Gtm_Hw_Tim_Configure
* @details      Configure channel.
* @param[in]    TimConfig:    Configuration contions pointer
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_Configure(TT_CONST Tim_ConfigType *TimConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    uint8 channelIndex = 0;
    uint8 timInstance = 0;
    uint8 timCh = 0;

    /*Check config point*/
    TT_ParaCheck((TimConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Gtm_Hw_Tim_PriCfgRangeJudge(TimConfig) != TT_RET_SUCCESS), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Tim_ParamInfo.TimConfig = TimConfig;

        /* Input source selection for signal Tim_PubReg[i]_AUX_IN */
        TT_GTM->CFG.B.SRC_IN_MUX = TIM_SET_AUX_IN_MUX;

        for(channelIndex = 0; channelIndex < TIM_MAX; channelIndex++)
        {
            timInstance = Gtm_Hw_Tim_PriGetInstance(Tim_ParamInfo.TimConfig[channelIndex].TimHwUnit);
            timCh = Gtm_Hw_Tim_PriGetChannel(Tim_ParamInfo.TimConfig[channelIndex].TimHwUnit);

            /*channel config*/
            Gtm_Hw_Tim_PriChannelConfig(timInstance, timCh, &Tim_ParamInfo.TimConfig[channelIndex], &Ret);

            /*Select input source*/
            Gtm_Hw_Tim_PriInputSelect(timInstance, timCh, &Tim_ParamInfo.TimConfig[channelIndex], &Ret);

            /*Filter config*/
            if(TRUE == Tim_ParamInfo.TimConfig[channelIndex].TimChannelFilterEnable)
            {
                Gtm_Hw_Tim_PriFilterConfig(timInstance, timCh, &Tim_ParamInfo.TimConfig[channelIndex], &Ret);
            }
            else
            {
                /* do nothing */
            }

            /*Timeout config*/
            if(TIM_TIMOUT_DISABLED != Tim_ParamInfo.TimConfig[channelIndex].TimChTimeoutDetectionEnable)
            {
                Gtm_Hw_Tim_PriTimeOutConfig(timInstance, timCh, &Tim_ParamInfo.TimConfig[channelIndex], &Ret);
            }
            else
            {
                /* do nothing */
            }

            if(TIM_INPUT_OF_AUX_IN_TOM == Tim_ParamInfo.TimConfig[channelIndex].TimChannelInputSelect)
            {
                Gtm_Hw_Tim_PriAuxInSet(timInstance, timCh, &Tim_ParamInfo.TimConfig[channelIndex], &Ret);
            }
            else
            {
                /* do nothing */
            }
        }
    }
    else
    {
        /* do nothing */
    }

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    Ret = Gtm_Hw_Tim_PriInitCheck(TimConfig);
#else
    (void)Ret;
#endif

#else
    (void)TimConfig;
    Ret = TT_RET_PARAM_ERR;
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_DeInit
* @details      Reset specified channel
* @param[in]    TimChannel: Tim channel
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_DeInit(TT_CONST Tim_ChnnelType TimChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        instance = Gtm_Hw_Tim_PriGetInstance(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);
        channel = Gtm_Hw_Tim_PriGetChannel(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);

        /* TT_SAFETY:This bit is cleared automatically after write by CPU. */
        Tim_PubReg[instance]->GC.RST.R = (uint32)0x1 << channel;
    }
    else
    {
        /* do nothing */
    }

#else
    (void)TimChannel;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_StartMeasure
* @details      Start pwm measure.
* @param[in]    TimChannel:    Tim channel id
* @param[in]    immediate:     at or wait for vaild edge
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_StartMeasure(Tim_ChnnelType TimChannel,
                                   uint8 immediate)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    uint8 timInstance = 0;
    uint8 timCh = 0;
    Tim_ChannelModeSelectType timMode = TIM_TPWM_MODE;

    /*Check the correctness of parameters*/
    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((immediate > 1), TT_RET_PARAM_VALUE_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get hardware information*/
        timInstance = Gtm_Hw_Tim_PriGetInstance(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);
        timCh = Gtm_Hw_Tim_PriGetChannel(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);
        timMode = Tim_ParamInfo.TimConfig[TimChannel].TimChannelModeSelect;

        if((immediate == 1) && ((timMode == TIM_TPWM_MODE) || (timMode == TIM_TPIM_MODE)))
        {
            Tim_PubReg[timInstance]->CH[timCh].ECTRL.B.IMM_START = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].ECTRL.B.IMM_START, 1);
#endif
        }
        else
        {
            Tim_PubReg[timInstance]->CH[timCh].ECTRL.B.IMM_START = 0U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].ECTRL.B.IMM_START, 0);
#endif
        }

        /*Timeout config*/
        if(TIM_TIMOUT_DISABLED != Tim_ParamInfo.TimConfig[TimChannel].TimChTimeoutDetectionEnable)
        {
            Tim_PubReg[timInstance]->CH[timCh].CTRL.B.TOCTRL = (uint8)Tim_ParamInfo.TimConfig[TimChannel].TimChTimeoutDetectionEnable;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].CTRL.B.TOCTRL, Tim_ParamInfo.TimConfig[TimChannel].TimChTimeoutDetectionEnable);
#endif
        }
        else
        {
            /* do nothing */
        }

        Tim_PubReg[timInstance]->CH[timCh].CTRL.B.TIM_EN = 1U;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].CTRL.B.TIM_EN, 1);
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)TimChannel;
    (void)immediate;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_StopMeasure
* @details      Stop pwm measure.
* @param[in]    TimChannel : Tim channel id
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_StopMeasure(Tim_ChnnelType TimChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    uint8 timInstance = 0;
    uint8 timCh = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get hardware information*/
        timInstance = Gtm_Hw_Tim_PriGetInstance(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);
        timCh = Gtm_Hw_Tim_PriGetChannel(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);

        Tim_PubReg[timInstance]->CH[timCh].CTRL.B.TIM_EN = 0U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].CTRL.B.TIM_EN, 0);
#endif

        /*Timeout config*/
        if(TIM_TIMOUT_DISABLED != Tim_ParamInfo.TimConfig[TimChannel].TimChTimeoutDetectionEnable)
        {
            Tim_PubReg[timInstance]->CH[timCh].CTRL.B.TOCTRL = (uint8)TIM_TIMOUT_DISABLED;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].CTRL.B.TOCTRL, TIM_TIMOUT_DISABLED);
#endif
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
    (void)TimChannel;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_GetStatusFlags
* @details      get channel status.
* @param[in]    TimChannel  : Tim channel id
* @param[out]   statusFlags : channel status
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_GetStatusFlags(Tim_ChnnelType TimChannel,
                                     uint8 *statusFlags)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    uint8 timInstance = 0;
    uint8 timCh = 0;
    uint8 i = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((statusFlags == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get hardware information*/
        timInstance = Gtm_Hw_Tim_PriGetInstance(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);
        timCh = Gtm_Hw_Tim_PriGetChannel(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);

        for(i = 0; i < 6; i++)
        {
            if((Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.R & ((uint32)0x1U << (uint32)i)) != 0x0U)
            {
                *statusFlags |= (0x1U << i);
            }
            else
            {
                /* do nothing */
            }
        }
    }
    else
    {
        /* do nothing */
    }

#else
    (void)TimChannel;
    (void)statusFlags;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_ClearStatusFlags
* @details      clear channel status.
* @param[in]    TimChannel       : Tim channel id
* @param[in]    flag_ClearStatus : status flag
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_ClearStatusFlag(Tim_ChnnelType TimChannel,
                                      Tim_StatusFlagType flag_ClearStatus)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    uint8 timInstance = 0;
    uint8 timCh = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((flag_ClearStatus > TIM_GLITCHDET_FLAG), TT_RET_PARAM_ENUM_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get hardware information*/
        timInstance = Gtm_Hw_Tim_PriGetInstance(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);
        timCh = Gtm_Hw_Tim_PriGetChannel(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);

#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_18();
#endif
        switch(flag_ClearStatus)
        {
            case TIM_NEWVALUE_FLAG:
                Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.NEWVAL = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.NEWVAL, 0);
#endif
                break;
            case TIM_ECNT_OVERFLOW_FLAG:
                Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.ECNTOFL = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.ECNTOFL, 0);
#endif
                break;
            case TIM_CNT_OVERFLOW_FLAG:
                Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.CNTOFL = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.CNTOFL, 0);
#endif
                break;
            case TIM_GPR_GPROFL_FLAG:
                Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.GPROFL = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.GPROFL, 0);
#endif
                break;
            case TIM_TDU_GPROFL_FLAG:
                Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.TODET = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.TODET, 0);
#endif
                break;
            case TIM_GLITCHDET_FLAG:
                Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.GLITCHDET = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.GLITCHDET, 0);
#endif
                break;
            default :
                Ret = TT_RET_PARAM_VALUE_ERR;
                break;
        }
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_18();
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)TimChannel;
    (void)flag_ClearStatus;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_SetTimValx
* @details      Set input level.
* @param[in]    timCh : Tim channel id
* @param[in]    val   : input level
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_SetTimValx(Tim_ChnnelType TimChannel,
                                 Tim_ChannelValInitSignalType val)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    uint8 timInstance = 0;
    uint8 timCh = 0;

    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck(((val != TIM_VAL_LOW) && (val != TIM_VAL_HIGH)), TT_RET_PARAM_VALUE_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        timInstance = Gtm_Hw_Tim_PriGetInstance(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);
        timCh = Gtm_Hw_Tim_PriGetChannel(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);

#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_19();
#endif
        /* Set Valx */
        GTM_REG_READ_2_WRITE(Tim_PubReg[timInstance]->GC.IN_SRC.R, val, 0x3U, (timCh << 2U));

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tim_PubReg[timInstance]->GC.IN_SRC.R & (0x3U << (timCh << 2U)),
                      GTM_GET_EN_READ_VAL(val) << (timCh << 2U));
#endif
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_19();
#endif
    }
#else
    (void)TimChannel;
    (void)val;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_SetInput
* @details      Set input level.
* @param[in]    TimIndex : Tim Index (0:TIMch0,...,7:TIMch7)
* @param[in]    InputSel : input Sel (0:pad,1:osc,2:eclk0,3:eclk1,4:eclk)
* @param[in]    Osc_Div  : OSC frequency division value
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_SetInput(uint8 TimIndex, uint8 InputSel, uint8 Osc_Div)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((TimIndex > TIM_MON_INDEX_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((InputSel > TIM_MON_SEL_MAX), TT_RET_PARAM_VALUE_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_20();
#endif
        GTM_REG_READ_2_WRITE(GTM_WRAPPER->TIMSEL.R, InputSel, 0xF, (TimIndex * TIM_MON_BIT_WIDTH));

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.R & (0xF << (TimIndex * TIM_MON_BIT_WIDTH)),
                      InputSel << (TimIndex * TIM_MON_BIT_WIDTH));
#endif
        if(InputSel == 1)
        {
            GTM_WRAPPER->OSCDIV.R = (uint32)Osc_Div;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK(GTM_WRAPPER->OSCDIV.R, Osc_Div);
#endif
        }
        else
        {
            /* do nothing */
        }
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_20();
#endif

    }
    else
    {
        /* do nothing */
    }

    return Ret;
}



/**
* @brief        Gtm_Hw_Interrupt_SetTimInt
* @details      Enable or disable a specified interrupt
* @param[in]    TimChannel: Tim channel
* @param[in]    Irq_Mask: bit0:NEWVAL_IRQ enable/disable,bit1:ECNTOFL_IRQ enable/disable
*                         bit2:CNTOFL_IRQ enable/disable,bit3:GPROFL_IRQ enable/disable
*                         bit4:TODET_IRQ enable/disable,bit5:GLITCHDET_IRQ enable/disable
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_SetTimInt(TT_CONST Tim_ChnnelType TimChannel,TT_CONST uint8 Irq_Mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck(((Irq_Mask >> TIM_INTERRUPT_IRQ_BIT_NUM) != 0), TT_RET_PARAM_LEN_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        instance = Gtm_Hw_Tim_PriGetInstance(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);
        channel = Gtm_Hw_Tim_PriGetChannel(Tim_ParamInfo.TimConfig[TimChannel].TimHwUnit);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_21();
#endif
#endif
        Tim_PubReg[instance]->CH[channel].IRQ_EN.R = Irq_Mask;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tim_PubReg[instance]->CH[channel].IRQ_EN.R, Irq_Mask);
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_21();
#endif
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)TimChannel;
    (void)Irq_Mask;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

#define GTM_START_SEC_CODE_FAST
#include "Gtm_MemMap.h"

/**
* @brief        Gtm_Hw_Tim_GetPwmInformation
* @details      Get pwm Information data.
* @param[in]    TimChannel:  Tim channel id
* @param[out]   pwmInfor:    pwm information data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_GetPwmInformation(Tim_ChnnelType TimChannel,
                                        Tim_PwmInfor *TT_CONST pwmInfor)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    TT_CONST Tim_ConfigType* pTimChCfg = &Tim_ParamInfo.TimConfig[TimChannel];
    float64 freq = 0.0f;
    float64 gpr0 = 0.0f;
    float64 gpr1 = 0.0f;
    uint8 timInstance = 0;
    uint8 timCh = 0;
    boolean newValueFlag = FALSE;
    boolean overflowFlag = FALSE;

    /*Check the correctness of parameters*/
    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((NULL_PTR == pwmInfor), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get hardware information*/
        timInstance = Gtm_Hw_Tim_PriGetInstance(pTimChCfg->TimHwUnit);
        timCh = Gtm_Hw_Tim_PriGetChannel(pTimChCfg->TimHwUnit);

        /*Get fequency*/
        Ret = Gtm_Hw_Cmu_GetClock(CMU_CFGU_CLK, (uint8)pTimChCfg->TimChannelClockSelect, &freq);
        freq = freq / TIM_THOUSAND ;    /* KHz - ms */

        /* If interrupt is not enabled, back up the notify register first.
         * Otherwise, the backup is completed in interrupt */
        if(Tim_PubReg[timInstance]->CH[timCh].IRQ_EN.R == 0)
        {
            /* Back up the Tim notify flag */
            Tim_PubNotifyFlag.R = Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.R;
        }
        else
        {
            /* do nothing */
        }

        /* Check flag bit */
        newValueFlag = (Tim_PubNotifyFlag.B.NEWVAL == 1? (boolean)1: (boolean)0);
        overflowFlag = (Tim_PubNotifyFlag.B.CNTOFL == 1? (boolean)1: (boolean)0);

        if((newValueFlag != (boolean)0) && (overflowFlag == (boolean)0) && \
           (freq > 0.0000001) && (Ret == TT_RET_SUCCESS))
        {
            gpr1 = (float64)Tim_PubReg[timInstance]->CH[timCh].GPR1.B.GPR1;
            gpr0 = (float64)Tim_PubReg[timInstance]->CH[timCh].GPR0.B.GPR0;

            pwmInfor->pwmPeriod = gpr1 / freq;    /* ms */

            /*Calculation period and duty cycle*/
            if(TIM_FALLING_EDGE == pTimChCfg->TimChannelSignalEdgeSelect)
            {
                pwmInfor->pwmDutyCycle = ((gpr1 - gpr0) * TIM_HUNDRED) / gpr1;    /* percentage */
                pwmInfor->fallingEdgeDuration = gpr0 / freq;
                pwmInfor->risingEdgeDuration = (gpr1 - gpr0) / freq;
            }
            else
            {
                pwmInfor->pwmDutyCycle = (gpr0 * TIM_HUNDRED) / gpr1;
                pwmInfor->fallingEdgeDuration = (gpr1 - gpr0) / freq;
                pwmInfor->risingEdgeDuration = gpr0 / freq;
            }
        }
        else
        {
            /* Check whether interrupt is enabled */
            if(Tim_PubReg[timInstance]->CH[timCh].IRQ_EN.R == 0)
            {
#ifdef USING_OS_AUTOSAROS
                SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_16();
#endif
                /*Clear the CNTOFL flag*/
                Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.CNTOFL = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.CNTOFL, 0);
#endif
#ifdef USING_OS_AUTOSAROS
                SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_16();
#endif
            }
            else
            {
                /* do nothing */
            }
        }
        /* Check whether interrupt is enabled */
        if(Tim_PubReg[timInstance]->CH[timCh].IRQ_EN.R == 0)
        {
#ifdef USING_OS_AUTOSAROS
            SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_17();
#endif
        /*Clear the NEWVAL flag*/
            Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.NEWVAL = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK(Tim_PubReg[timInstance]->CH[timCh].IRQ_NOTIFY.B.NEWVAL, 0);
#endif
#ifdef USING_OS_AUTOSAROS
            SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_17();
#endif
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
    (void)TimChannel;
    (void)pwmInfor;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_GetMeasureInformation
* @details      get measure information.
* @param[in]    TimChannel:   Tim channel id
* @param[out]   infor:        Tom channel id
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_GetMeasureInformation(Tim_ChnnelType TimChannel,
                                            Tim_MeasureInfor *TT_CONST infor)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    TT_CONST Tim_ConfigType* pTimChCfg = &Tim_ParamInfo.TimConfig[TimChannel];
    uint8 timInstance = 0;
    uint8 timCh = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((NULL_PTR == infor), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get hardware information*/
        timInstance = Gtm_Hw_Tim_PriGetInstance(pTimChCfg->TimHwUnit);
        timCh = Gtm_Hw_Tim_PriGetChannel(pTimChCfg->TimHwUnit);

        infor->tiemCnt = Tim_PubReg[timInstance]->CH[timCh].CNT.B.CNT;
        infor->tiemCnts.R = Tim_PubReg[timInstance]->CH[timCh].CNTS.R;
        infor->tiemGpr1.R = Tim_PubReg[timInstance]->CH[timCh].GPR1.R;
        infor->tiemGpr0.R = Tim_PubReg[timInstance]->CH[timCh].GPR0.R;;
    }
    else
    {
        /* do nothing */
    }

#else
    (void)TimChannel;
    (void)infor;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tim_GetPulseTime
* @details      get pulse time.
* @param[in]    TimChannel:    Tim channel id
* @param[out]   sumTime   :    Time data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_GetPulseTime(Tim_ChnnelType TimChannel,
                                   float64 *sumTime)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    TT_CONST Tim_ConfigType* pTimChCfg = &Tim_ParamInfo.TimConfig[TimChannel];
    float64 freq = 0.0f;
    uint8 timInstance = 0;
    uint8 timCh = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((TimChannel >= TIM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((NULL_PTR == sumTime), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get hardware information*/
        timInstance = Gtm_Hw_Tim_PriGetInstance(pTimChCfg->TimHwUnit);
        timCh = Gtm_Hw_Tim_PriGetChannel(pTimChCfg->TimHwUnit);
        /*Get fequency*/
        Ret = Gtm_Hw_Cmu_GetClock(CMU_CFGU_CLK, (uint8)pTimChCfg->TimChannelClockSelect, &freq);
        if((freq > 0.0000001) && (Ret == TT_RET_SUCCESS))
        {
            *sumTime = (float64)Tim_PubReg[timInstance]->CH[timCh].CNT.B.CNT / (freq / TIM_THOUSAND);
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
    (void)TimChannel;
    (void)sumTime;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}



/******************************************************************************
 *                       Private Function
 ******************************************************************************/
#if defined(TIM_MAX) && (TIM_MAX != 0)
/**
* @brief        Gtm_Hw_Tim_PriSelectGpr0Input
* @details      Configure GPR0 input source .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSelectGpr0Input(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret)
{
     if(TIM_GPR0_FROM_ECNT_VALUE <= TimConfig->TimChannelGpr0InputSelect)
    {
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EGPR0_SEL = 1;
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.GPR0_SEL = ((uint8)TimConfig->TimChannelGpr0InputSelect - (uint8)TIM_GPR0_FROM_ECNT_VALUE);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EGPR0_SEL, 1);
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.GPR0_SEL, TimConfig->TimChannelGpr0InputSelect - (uint8)TIM_GPR0_FROM_ECNT_VALUE);
#else
        (void)Ret;
#endif
    }
    else
    {
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EGPR0_SEL = 0;
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.GPR0_SEL = (uint8)TimConfig->TimChannelGpr0InputSelect;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EGPR0_SEL, 0);
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.GPR0_SEL, TimConfig->TimChannelGpr0InputSelect);
#endif
    }
}

/**
* @brief        Gtm_Hw_Tim_PriSelectGpr1Input
* @details      Configure GPR1 input source .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSelectGpr1Input(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret)
{
    if(TIM_GPR1_FROM_ECNT_VALUE <= TimConfig->TimChannelGpr1InputSelect)
    {
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EGPR1_SEL = 1;
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.GPR1_SEL = ((uint8)TimConfig->TimChannelGpr1InputSelect - (uint8)TIM_GPR1_FROM_ECNT_VALUE);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EGPR1_SEL, 1);
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.GPR1_SEL, TimConfig->TimChannelGpr1InputSelect - (uint8)TIM_GPR1_FROM_ECNT_VALUE);
#else
        (void)Ret;
#endif
    }
    else
    {
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EGPR1_SEL = 0;
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.GPR1_SEL = (uint8)TimConfig->TimChannelGpr1InputSelect;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EGPR1_SEL, 0);
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.GPR1_SEL, TimConfig->TimChannelGpr1InputSelect);
#endif
    }
}

/**
* @brief        Gtm_Hw_Tim_PriSetSignalEdgeInit
* @details      Configure signal edge .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSetSignalEdgeInit(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret)
{
    if(TIM_BOTH_EDGES == TimConfig->TimChannelSignalEdgeSelect)
    {
        if((TIM_TIEM_MODE == TimConfig->TimChannelModeSelect) \
        || (TIM_TSSM_MODE == TimConfig->TimChannelModeSelect))
        {
            Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.ISL = 1U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.ISL, 1);
#else
            (void)Ret;
#endif
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.ISL = 0U;
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.DSL = (uint8)TimConfig->TimChannelSignalEdgeSelect;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.ISL, 0);
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.DSL, TimConfig->TimChannelSignalEdgeSelect);
#endif
    }
}

/**
* @brief        Gtm_Hw_Tim_PriSetCntsInit
* @details      Configure cnts .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSetCntsInit(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret)
{
    if(    (TIM_TIPM_MODE == TimConfig->TimChannelModeSelect) \
        || (TIM_TGPS_MODE == TimConfig->TimChannelModeSelect) \
        || (TIM_TBCM_MODE == TimConfig->TimChannelModeSelect) \
        || (TIM_TSSM_MODE == TimConfig->TimChannelModeSelect))
    {
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CNTS.R = TimConfig->TimChannelCntsValue;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CNTS.R, TimConfig->TimChannelCntsValue);
#else
        (void)Ret;
#endif
    }
    else
    {
        /* do nothing */
    }
}

/**
* @brief        Gtm_Hw_Tim_PriSetTbuTs0Bits
* @details      Configure Tbu channel 0 timebase resolution .
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriSetTbuTs0Bits(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret)
{
    if((TIM_TBCM_MODE != TimConfig->TimChannelModeSelect) \
        && (ModuleNo == TIM_INSTANCE_0) \
        && ((TIM_GPR0_FROM_TIMEBASE_TBU_TS0 == TimConfig->TimChannelGpr0InputSelect) \
        || (TIM_GPR1_FROM_TIMEBASE_TBU_TS0 == TimConfig->TimChannelGpr1InputSelect)))
    {
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.TBU0_SEL = TimConfig->TimChannelTbu0Ts0BitsSelect;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.TBU0_SEL, TimConfig->TimChannelTbu0Ts0BitsSelect);
#else
        (void)Ret;
#endif
    }
    else
    {
        /* do nothing */
    }
}

/**
* @brief        Gtm_Hw_Tim_PriValxConfig
* @details      Configure level while channel input is TIM_INPUT_OF_VAL.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriValxConfig(uint8 ModuleNo, uint8 ChannelNo, TT_CONST Tim_ConfigType *TimConfig, TT_RetType *Ret)
{
    if(TIM_INPUT_OF_VAL == TimConfig->TimChannelInputSelect)
    {
        /* Set Valx */
        GTM_REG_READ_2_WRITE(Tim_PubReg[ModuleNo]->GC.IN_SRC.R, TimConfig->TimChannelValInitSignal, 0x3, (ChannelNo << 2U));

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR((Tim_PubReg[ModuleNo]->GC.IN_SRC.R & (0x3U << (ChannelNo << 2U))) >> (ChannelNo << 2U),
                               GTM_GET_EN_READ_VAL(TimConfig->TimChannelValInitSignal));
#else
        (void)Ret;
#endif
    }
    else
    {
        /* do nothing */
    }
}

/**
* @brief        Gtm_Hw_Tim_PriChannelConfig
* @details      Configure channel paremeters.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriChannelConfig( uint8 ModuleNo,
                                         uint8 ChannelNo,
                                         TT_CONST Tim_ConfigType *TimConfig,
                                         TT_RetType *Ret)
{
    /*Select clock source*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.CLK_SEL = (uint8)TimConfig->TimChannelClockSelect;

    /*set channelx level val*/
    Gtm_Hw_Tim_PriValxConfig(ModuleNo, ChannelNo, TimConfig, Ret);

    /*Set gpr0 and gpr1 input source*/
    Gtm_Hw_Tim_PriSelectGpr0Input(ModuleNo, ChannelNo, TimConfig, Ret);
    Gtm_Hw_Tim_PriSelectGpr1Input(ModuleNo, ChannelNo, TimConfig, Ret);

    /*set cnts input source*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.CNTS_SEL = (uint8)TimConfig->TimChannelCntsInputSelect;

    /*set select mode*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.TIM_MODE = (uint8)TimConfig->TimChannelModeSelect;

    /*set signal edge mode*/
    Gtm_Hw_Tim_PriSetSignalEdgeInit(ModuleNo, ChannelNo, TimConfig, Ret);

    /*set cnts*/
    Gtm_Hw_Tim_PriSetCntsInit(ModuleNo, ChannelNo, TimConfig, Ret);

    /*set tbu0 bit*/
    Gtm_Hw_Tim_PriSetTbuTs0Bits(ModuleNo, ChannelNo, TimConfig, Ret);

    /*enable one shot mode*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.OSM = (uint8)TimConfig->TimChannelOneShotMode;

    /*enable external capture*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EXT_CAP_EN = (uint8)TimConfig->TimChannelExtCaptureModeEnable;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].ECTRL.B.EXT_CAP_SRC = (uint8)TimConfig->TimChannelExtCaptureSrc;

    /*Set ecnt reset*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.ECNT_RESET = (uint8)TimConfig->TimChannelEcntResetSetting;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FR_ECNT_OFL = (uint8)TimConfig->TimChannelEcntOvflwSetting;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.CLK_SEL, TimConfig->TimChannelClockSelect);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.CNTS_SEL, TimConfig->TimChannelCntsInputSelect);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.TIM_MODE, TimConfig->TimChannelModeSelect);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.OSM, TimConfig->TimChannelOneShotMode);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.EXT_CAP_EN, TimConfig->TimChannelExtCaptureModeEnable);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].ECTRL.B.EXT_CAP_SRC, TimConfig->TimChannelExtCaptureSrc);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.ECNT_RESET, TimConfig->TimChannelEcntResetSetting);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FR_ECNT_OFL, TimConfig->TimChannelEcntOvflwSetting);
#endif
}

/**
* @brief        Gtm_Hw_Tim_PriFilterConfig
* @details      Configure channel filter paremeters.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriFilterConfig(uint8 ModuleNo,
                                       uint8 ChannelNo,
                                       TT_CONST Tim_ConfigType *TimConfig,
                                       TT_RetType *Ret)
{
    /*Select freq for filter*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_CNT_FRQ = (uint8)TimConfig->TimChFilterCounterFreqSelect;

    /*Set filter time*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].FLT_RE.B.FLT_RE = TimConfig->TimChFilterTimeForRisingEdge;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].FLT_FE.B.FLT_FE = TimConfig->TimChFilterTimeForFallingEdge;

    /* Filter mode raising edge set */
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_MODE_RE = (uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_FLT_MODE;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].ECTRL.B.EFLT_CTR_RE = ((uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_EFLT_CTR) >> TIM_FILTERMODE_EFLT_CTR;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_CTR_RE = ((uint8)TimConfig->TimChFilterModeForRisingEdge & 4U) >> 3;

    /* Filter mode falling edge set */
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_MODE_FE = (uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_FLT_MODE;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].ECTRL.B.EFLT_CTR_FE = ((uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_EFLT_CTR) >> TIM_FILTERMODE_EFLT_CTR;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_CTR_FE = ((uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_FLT_CTR) >> TIM_FILTERMODE_FLT_CTR;

    /* Enable filtering */
    Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_EN = 1;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_CNT_FRQ, TimConfig->TimChFilterCounterFreqSelect);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].FLT_RE.B.FLT_RE, TimConfig->TimChFilterTimeForRisingEdge);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].FLT_FE.B.FLT_FE, TimConfig->TimChFilterTimeForFallingEdge);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_MODE_RE, (uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_FLT_MODE);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].ECTRL.B.EFLT_CTR_RE, ((uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_EFLT_CTR) >> TIM_FILTERMODE_EFLT_CTR);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_CTR_RE, ((uint8)TimConfig->TimChFilterModeForRisingEdge & 4U) >> 3);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_MODE_FE, (uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_FLT_MODE);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].ECTRL.B.EFLT_CTR_FE, ((uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_EFLT_CTR) >> TIM_FILTERMODE_EFLT_CTR);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_CTR_FE, ((uint8)TimConfig->TimChFilterModeForRisingEdge & TIM_FILTERMODE_FLT_CTR) >> TIM_FILTERMODE_FLT_CTR);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.FLT_EN, 1);
#else
    (void)Ret;
#endif
}

/**
* @brief        Gtm_Hw_Tim_PriTimeOutConfig
* @details      Configure channel timeout paremeters.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriTimeOutConfig(uint8 ModuleNo,
                                        uint8 ChannelNo,
                                        TT_CONST Tim_ConfigType *TimConfig,
                                        TT_RetType *Ret)
{
    Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.SLICING = 0;

    /*set tdu work clock*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TCS = (uint8)TimConfig->TimChTimeoutClockSelect;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TCS_USE_SAMPLE_EVT = FALSE;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TDU_SAME_CNT_CLK = TRUE;

    /*set timeout value*/
    Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TOV = (uint8)TimConfig->TimChTimeoutDuration;
    Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TOV1 = (uint8)(TimConfig->TimChTimeoutDuration >> 8U);
    Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TOV2 = (uint8)(TimConfig->TimChTimeoutDuration >> 16U);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.SLICING, 0);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TCS, TimConfig->TimChTimeoutClockSelect);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TCS_USE_SAMPLE_EVT, FALSE);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TDU_SAME_CNT_CLK, TRUE);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TOV, (uint8)TimConfig->TimChTimeoutDuration);
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TOV1, (uint8)(TimConfig->TimChTimeoutDuration >> 8U));
    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].TDUV.B.TOV2, (uint8)(TimConfig->TimChTimeoutDuration >> 16U));
#else
    (void)Ret;
#endif
}

/**
* @brief        Gtm_Hw_Tim_PriAuxInSet
* @details      Configure aux input source.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriAuxInSet(uint8 ModuleNo,
                                   uint8 ChannelNo,
                                   TT_CONST Tim_ConfigType *TimConfig,
                                   TT_RetType *Ret)
{
    volatile GTM_CCM_bf_type *Gtm_CCMxPtr[3] = {&TT_GTM->CCM0, &TT_GTM->CCM1, &TT_GTM->CCM2};

    Gtm_CCMxPtr[ModuleNo]->TIM_AUX_IN_SRC.R = TIM_SET_AUX_IN(Gtm_CCMxPtr[ModuleNo]->TIM_AUX_IN_SRC.R, ChannelNo, TimConfig->TimAuxInInput);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    GTM_REG_CHECK_RET_PTR(Gtm_CCMxPtr[ModuleNo]->TIM_AUX_IN_SRC.R & (TIM_CCM_AUXIN_CONFIG_MSK << (ChannelNo & 0x7U)),
                          TimConfig->TimAuxInInput << (ChannelNo & 0x7));
#else
    (void)Ret;
#endif
}

/**
* @brief        Gtm_Hw_Tim_PriInputSelect
* @details      Configure tim input source.
* @param[in]    ModuleNo  : Tim instance
* @param[in]    ChannelNo : channel number
* @param[in]    TimConfig : Configuration caontions pointer
* @param[out]   Ret       : Save the register read back result
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_Tim_PriInputSelect(uint8 ModuleNo,
                                         uint8 ChannelNo,
                                      TT_CONST Tim_ConfigType *TimConfig,
                                      TT_RetType *Ret)
{
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    uint32 regRead = 0;
#else
    (void)Ret;
#endif
    /*Write IN_SRC register to select input*/
    GTM_REG_READ_2_WRITE(Tim_PubReg[ModuleNo]->GC.IN_SRC.R, TimConfig->TimChannelInputSelect,
                         0xF, (ChannelNo << 2U));

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    switch(TimConfig->TimChannelInputSelect)
    {
        case TIM_INPUT_OF_CURRENT_CHANNEL: regRead = 0x0; break;
        case TIM_INPUT_OF_PREVIOUS_CHANNEL: regRead = 0x0; break;
        case TIM_INPUT_OF_AUX_IN_TOM: regRead = 0x3; break;
        case TIM_INPUT_OF_VAL:
            regRead =((uint32)TimConfig->TimChannelValInitSignal == 0x1U)? 0xCU: 0xFU;
            break;
        default: /* do nothing */break;
    }

    GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->GC.IN_SRC.R & (0xF << (ChannelNo << 2U)),
                         (regRead & 0xF) << ((ChannelNo << 2U)));
#endif

    if((TIM_INPUT_OF_CURRENT_CHANNEL == TimConfig->TimChannelInputSelect) || \
       (TIM_INPUT_OF_PREVIOUS_CHANNEL == TimConfig->TimChannelInputSelect))
    {
        Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.CICTRL = ((uint8)TimConfig->TimChannelInputSelect & 0x10U) >> 4U;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK_RET_PTR(Tim_PubReg[ModuleNo]->CH[ChannelNo].CTRL.B.CICTRL,
                             ((uint8)TimConfig->TimChannelInputSelect & 0x10U) >> 4U);
#endif
    }
    else
    {
        /* do nothing */
    }
}

/**
* @brief        Gtm_Hw_PriCfgRangeJudge
* @details      Determine the validity range of gtm configuration data.
* @param[in]    TimConfig:   Configuration caontions
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Tim_PriCfgRangeJudge(TT_CONST Tim_ConfigType *TimConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 channelIndex = 0;

    for(channelIndex = 0; channelIndex < TIM_MAX; channelIndex++)
    {
        GTM_DATA_RANGE_CHECK((TimConfig->TimHwUnit >> 3) > TIM_INSTANCE);
        GTM_DATA_RANGE_CHECK(
                    (TimConfig->TimAuxInInput != TIM_AUXIN_TOM_OUT) &&
                    (TimConfig->TimAuxInInput != TIM_AUXIN_ATOM_OUT) &&
                    (TimConfig->TimAuxInInput != TIM_AUXIN_TOM_OUT_N) &&
                    (TimConfig->TimAuxInInput != TIM_AUXIN_ATOM_OUT_N) );
        GTM_DATA_RANGE_CHECK(
                    (TimConfig->TimChannelInputSelect != TIM_INPUT_OF_CURRENT_CHANNEL) &&
                    (TimConfig->TimChannelInputSelect != TIM_INPUT_OF_PREVIOUS_CHANNEL) &&
                    (TimConfig->TimChannelInputSelect != TIM_INPUT_OF_AUX_IN_TOM) &&
                    (TimConfig->TimChannelInputSelect != TIM_INPUT_OF_VAL) );
        GTM_DATA_RANGE_CHECK(
                    (TimConfig->TimChannelValInitSignal != TIM_VAL_LOW) &&
                    (TimConfig->TimChannelValInitSignal != TIM_VAL_HIGH));
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelSignalEdgeSelect > TIM_BOTH_EDGES);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelClockSelect > TIM_CONFIGURABLE_CLOCK_7);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelGpr0InputSelect > TIM_GPR0_FROM_INP_VAL);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelGpr1InputSelect > TIM_GPR1_FROM_INP_VAL);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelCntsInputSelect > TIM_TIMEBASE_TIM_TBU_TS0);
        GTM_DATA_RANGE_CHECK((TimConfig->TimChannelCntsValue >> 24) > 0);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelTbu0Ts0BitsSelect >  1);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelModeSelect > TIM_TSSM_MODE);
        GTM_DATA_RANGE_CHECK((TimConfig->TimChannelOneShotMode != TRUE) && (TimConfig->TimChannelOneShotMode != FALSE));
        GTM_DATA_RANGE_CHECK((TimConfig->TimChannelExtCaptureModeEnable != TRUE) && (TimConfig->TimChannelExtCaptureModeEnable != FALSE));
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelExtCaptureSrc > TIM_SEL14_TDU_FRAME_EVT);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelEcntResetSetting > TIM_SEL1_PERIODIC_SAMPLING_MODE);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChannelEcntOvflwSetting > TIM_SEL1_OFL_SIG_ON_BITWIDTH);
        GTM_DATA_RANGE_CHECK((TimConfig->TimChannelFilterEnable != TRUE) && (TimConfig->TimChannelFilterEnable != FALSE));
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChFilterCounterFreqSelect > TIM_FIR_CONFIGURABLE_CLOCK_7);
        GTM_DATA_RANGE_CHECK(
                    (TimConfig->TimChFilterModeForRisingEdge != TIM_IMMEDIATE_EDGE_PROPAGATION) &&
                    (TimConfig->TimChFilterModeForRisingEdge != TIM_DEGLITCH_WITH_UPDOWN_CNT) &&
                    (TimConfig->TimChFilterModeForRisingEdge != TIM_DEGLITCH_WITH_HOLD_CNT) &&
                    (TimConfig->TimChFilterModeForRisingEdge != TIM_DEGLITCH_WITH_RESET_CNT) );
        GTM_DATA_RANGE_CHECK(
                    (TimConfig->TimChFilterModeForFallingEdge != TIM_IMMEDIATE_EDGE_PROPAGATION) &&
                    (TimConfig->TimChFilterModeForFallingEdge != TIM_DEGLITCH_WITH_UPDOWN_CNT) &&
                    (TimConfig->TimChFilterModeForFallingEdge != TIM_DEGLITCH_WITH_HOLD_CNT) &&
                    (TimConfig->TimChFilterModeForFallingEdge != TIM_DEGLITCH_WITH_RESET_CNT) );
        GTM_DATA_RANGE_CHECK((TimConfig->TimChFilterTimeForRisingEdge >> 24) > 0);
        GTM_DATA_RANGE_CHECK((TimConfig->TimChFilterTimeForFallingEdge >> 24) > 0);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChTimeoutDetectionEnable > TIM_TIMOUT_EN_ON_BOTH_EDGES);
        GTM_DATA_RANGE_CHECK((uint32)TimConfig->TimChTimeoutClockSelect > TIM_TIMEOUT_CONFIGURABLE_CLOCK7);
        GTM_DATA_RANGE_CHECK((TimConfig->TimChTimeoutDuration >> 24) > 0);
    }

    return Ret;
}

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Hw_Tim_InitCheck
* @details      Tim Init Check.
* @param[in]    TimConfig:    Tim config data
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
static TT_RetType Gtm_Hw_Tim_PriInitCheck(TT_CONST Tim_ConfigType *TimConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#if defined(TIM_MAX) && (TIM_MAX != 0)

    TT_ParaCheck((TimConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /* Check Input  selection */
        GTM_REG_CHECK(TT_GTM->CFG.B.SRC_IN_MUX, TIM_SET_AUX_IN_MUX);

        /* TT_SAFETY: The other register read back has been done in the execution of function Gtm_Hw_Tim_Configure*/
    }
    else
    {
        /* do nothing */
    }

#else
    (void)TimConfig;
    Ret = TT_RET_PARAM_ERR;
#endif

    return Ret;
}
#endif

#endif /* TIM_MAX */

#define GTM_STOP_SEC_CODE_FAST
#include "Gtm_MemMap.h"

#ifdef __cplusplus
}
#endif
