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
**  FILENAME     : Gtm_Hw_Tom.c                                               **
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
#include "Gtm_Hw_Tom.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Gtm.h"
#endif

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define GTM_HW_TOM_VENDOR_ID_C                      1541
#define GTM_HW_TOM_MODULE_ID_C                      221
#define GTM_HW_TOM_AR_RELEASE_MAJOR_VERSION_C       4
#define GTM_HW_TOM_AR_RELEASE_MINOR_VERSION_C       4
#define GTM_HW_TOM_AR_RELEASE_PATCH_VERSION_C       0
#define GTM_HW_TOM_SW_MAJOR_VERSION_C               1
#define GTM_HW_TOM_SW_MINOR_VERSION_C               1
#define GTM_HW_TOM_SW_PATCH_VERSION_C               0
/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Gtm_Hw_Tom.h Gtm_Hw_Tom.c file version check */
#if (GTM_HW_TOM_VENDOR_ID_H != GTM_HW_TOM_VENDOR_ID_C)
    #error "Gtm_Hw_Tom.h and Gtm_Hw_Tom.c have different vendor ids"
#endif
#if (GTM_HW_TOM_MODULE_ID_H != GTM_HW_TOM_MODULE_ID_C)
    #error "Gtm_Hw_Tom.h and Gtm_Hw_Tom.c have different module ids"
#endif
#if ((GTM_HW_TOM_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TOM_AR_RELEASE_MAJOR_VERSION_C) || \
     (GTM_HW_TOM_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TOM_AR_RELEASE_MINOR_VERSION_C) || \
     (GTM_HW_TOM_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TOM_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of Gtm_Hw_Tom.h and Gtm_Hw_Tom.c are different"
#endif
#if ((GTM_HW_TOM_SW_MAJOR_VERSION_H != GTM_HW_TOM_SW_MAJOR_VERSION_C) || \
     (GTM_HW_TOM_SW_MINOR_VERSION_H != GTM_HW_TOM_SW_MINOR_VERSION_C) || \
     (GTM_HW_TOM_SW_PATCH_VERSION_H != GTM_HW_TOM_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Gtm_Hw_Tom.h and Gtm_Hw_Tom.c are different"
#endif

#ifdef USING_OS_AUTOSAROS
/* Gtm_Hw_Tom.c SchM_Gtm.h file version check */
#if (GTM_HW_TOM_VENDOR_ID_C != SCHM_GTM_VENDOR_ID_H)
    #error "Gtm_Hw_Tom.c and SchM_Gtm.h have different vendor ids"
#endif
#if ((GTM_HW_TOM_AR_RELEASE_MAJOR_VERSION_C != SCHM_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_TOM_AR_RELEASE_MINOR_VERSION_C != SCHM_GTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_TOM_AR_RELEASE_PATCH_VERSION_C != SCHM_GTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tom.c and SchM_Gtm.h are different"
#endif
#if ((GTM_HW_TOM_SW_MAJOR_VERSION_C != SCHM_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_HW_TOM_SW_MINOR_VERSION_C != SCHM_GTM_SW_MINOR_VERSION_H) || \
     (GTM_HW_TOM_SW_PATCH_VERSION_C != SCHM_GTM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tom.c and SchM_Gtm.h are different"
#endif
#endif

#if defined(TOM_MAX) && (TOM_MAX != 0)

/******************************************************************************
 *                       Global Variables Declaration
 ******************************************************************************/

/******************************************************************************
 *                       Private Variables
 ******************************************************************************/
#define GTM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"

/* Tom unit information */
static Tom_ParamInfoType Tom_PubParamInfo = {0};

#define GTM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"
/******************************************************************************
 *                       Private Function Declaration
 ******************************************************************************/
/**
* @brief        Gtm_Hw_Tom_PriSetIntTrig
* @details      Initialize tom TGC unit.
* @param[in]    TomConfig : Tom configuration container
* @param[in]    tgcIndex  : Tom TGC Index
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetIntTrig(TT_CONST Tom_ConfigType *TomConfig,TT_CONST uint8 tgcIndex);

/**
* @brief        Gtm_Hw_Tom_PriGetInstance
* @details      Get tom instance.
* @param[in]    Tom : hardware unit
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Tom_PriGetInstance(Tom_ChannelType tomChannel);

/**
* @brief        Gtm_Hw_Tom_PriGetChannel
* @details      Get tom channel id.
* @param[in]    tomChannel : Tom channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Tom_PriGetChannel(Tom_ChannelType tomChannel);

/**
* @brief        Gtm_Hw_Tom_PriCfgRangeJudge
* @details      Configuring data validity judgment.
* @param[in]    TomConfig : Configuration caontions poniter
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Tom_PriCfgRangeJudge(TT_CONST Tom_ConfigType *TomConfig);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Hw_Tom_PriInitCheck
* @details      Tom Init Check.
* @param[in]    TomConfig: Tom config data
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
static TT_RetType Gtm_Hw_Tom_PriInitCheck(TT_CONST Tom_ConfigType *TomConfig);
#endif

/******************************************************************************
 *                       Public Functions
 ******************************************************************************/
#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

/**
* @brief        Gtm_Hw_Tom_Configure
* @details      Initialize tom unit.
* @param[in]    TomConfig:    Tom configuration container
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_Configure(TT_CONST Tom_ConfigType *TomConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    TT_CONST Tom_ChannelConfigType *channelConfig = NULL_PTR;
    uint8 instance = 0;
    uint8 channel = 0;
    uint8 channelIndex = 0;
    uint8 tgcIndex = 0;

    /*Check config point*/
    TT_ParaCheck((TomConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Gtm_Hw_Tom_PriCfgRangeJudge(TomConfig) != TT_RET_SUCCESS), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Tom_PubParamInfo.TomChannelConfig = TomConfig->TomChannelConfig;
        Tom_PubParamInfo.TomTriggersForTgc = TomConfig->TomTriggersForTgc;

        /*Config act*/
        for(tgcIndex = 0; tgcIndex < TOM_TCG_MAX; tgcIndex++)
        {
            if(TRUE == TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTimeBaseTriggerEnable)
            {
                /*Set act configuration*/
                Tom_PubReg[tgcIndex >> 1U]->TGC[tgcIndex & 0x1U].ACT_TB.B.ACT_TB = TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTimebaseMatchValue;
                Tom_PubReg[tgcIndex >> 1U]->TGC[tgcIndex & 0x1U].ACT_TB.B.TBU_SEL = (uint8)TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTbuTimebaseSelect;
                Tom_PubReg[tgcIndex >> 1U]->TGC[tgcIndex & 0x1U].ACT_TB.B.TB_TRIG = 0x1U;

                Gtm_Hw_Tom_PriSetIntTrig(TomConfig,tgcIndex);
            }
            else
            {
                /* do nothing */
            }
        }

        /*Config channel*/
        for(channelIndex = 0; channelIndex < TOM_MAX; channelIndex++)
        {
            /*Get channnel information*/
            channelConfig = &TomConfig->TomChannelConfig[channelIndex];
            channel = Gtm_Hw_Tom_PriGetChannel(channelIndex);
            instance = Gtm_Hw_Tom_PriGetInstance(channelIndex);

            /*set update mechanisms*/
            Gtm_Hw_Tom_PriSetTgcUpdateEnable(instance, channel, channelConfig->TomChUpdateEnableOnCn0Reset);
            Gtm_Hw_Tom_PriSetForceUPEnable(instance, channel, channelConfig->TomChEnableForceUpdate);
            Gtm_Hw_Tom_PriRstCn0ForceUP(instance, channel, channelConfig->TomChResetCn0OnForceUpdate);
            /*set signal value*/
            Tom_PubReg[instance]->CH[channel].CTRL.B.SL = (uint8)channelConfig->TomChannelOutputSignalLevel;
            Tom_PubReg[instance]->CH[channel].CTRL_SR.B.SL = (uint8)channelConfig->TomChannelOutputSignalLevel;

            /*set base config*/
            if(FALSE == channelConfig->TomChannelOneShotMode)
            {
                Tom_PubReg[instance]->CH[channel].CN0.R = (uint16)channelConfig->TomChannelCounterValCn0;
            }
            else
            {
                /*set oneshot mode*/
                Tom_PubReg[instance]->CH[channel].CTRL.B.OSM = (uint8)channelConfig->TomChannelOneShotMode;
                Tom_PubReg[instance]->CH[channel].CTRL.B.OSM_TRIG = (uint8)channelConfig->TomChannelTrigOneShotMode;
            }

            /*set cm0 period,cm1 duty cycle*/
            Tom_PubReg[instance]->CH[channel].CM0.R = (uint16)channelConfig->TomChannelPeriodCompareValCm0;
            Tom_PubReg[instance]->CH[channel].CM1.R = (uint16)channelConfig->TomChannelDutyCycleCompareValCm1;

            /*update according to shadow register after one cycle*/
            Tom_PubReg[instance]->CH[channel].SR0.R = (uint16)channelConfig->TomChPeriodCompareShadowValSr0;
            Tom_PubReg[instance]->CH[channel].SR1.R = (uint16)channelConfig->TomChDCycCompareShadowValSr1;

            /*set reset mode*/
            Tom_PubReg[instance]->CH[channel].CTRL.B.TRIGOUT = (uint8)channelConfig->TomChannelTriggerOutput;
            Tom_PubReg[instance]->CH[channel].CTRL.B.RST_CCU0 = (uint8)channelConfig->TomChannelCounterCn0Reset;

            /*external trigger pwm generate*/
            Tom_PubReg[instance]->CH[channel].CTRL.B.EXT_TRIG = (uint8)channelConfig->TomChannelExtCounterCn0Reset;
            Tom_PubReg[instance]->CH[channel].CTRL.B.EXTTRIGOUT = (uint8)channelConfig->TomChannelExtTriggerOutput;

            /*set updown mode*/
            Tom_PubReg[instance]->CH[channel].CTRL.B.UDMODE = channelConfig->TomUpdownMode;

            /*select source clock*/
            Tom_PubReg[instance]->CH[channel].CTRL.B.CLK_SRC_SR = (uint8)channelConfig->TomChannelClockSelect;
            Tom_PubReg[instance]->CH[channel].CTRL_SR.B.CLK_SRC_SR = (uint8)channelConfig->TomChannelClockSelect;

            /*set sr0 trigger*/
            Tom_PubReg[instance]->CH[channel].CTRL.B.SR0_TRIG = (uint8)channelConfig->TomChannelSr0Trigger;

            /*set bit reversal*/
            if(TOM_CH_15 == channel)
            {
                Tom_PubReg[instance]->CH[channel].CTRL.B.BITREV = (uint8)channelConfig->TomChannelBitReversalMode;
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
    Ret = Gtm_Hw_Tom_PriInitCheck(TomConfig);
#else
    (void)Ret;
#endif

#else
    (void)TomConfig;
    Ret = TT_RET_PARAM_ERR;
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_DeInit
* @details      Reset specified channel
* @param[in]    tomChannel: Tom channel
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_DeInit(TT_CONST Tom_ChannelType tomChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#if defined(TOM_MAX) && (TOM_MAX != 0)
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    uint8 instance = 0;
    uint8 channel = 0;
    uint8 tgcx = 0;

    if(Ret == TT_RET_SUCCESS)
    {
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        tgcx = channel / 8;

        /* TT_SAFETY:This bit is cleared automatically after write over the configuration interface. */
        Tom_PubReg[instance]->TGC[tgcx].GLB_CTRL.R = ((uint32)0x1U << ((uint32)channel + (uint32)8));
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_ChanelEnable
* @details      Enable tom channel.
* @param[in]    tomChannel       : Tom channel
* @param[in]    enableMode       : at or wait host trigger
* @param[in]    outputEnableMode : at or wait host trigger
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_ChanelEnable(Tom_ChannelType tomChannel,
                                   Tom_ChannelEnableType enableMode,
                                   Tom_ChannelOutputControlType outputEnableMode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    uint32 tempReg = 0;
    uint32 tempRegBits = 0;
#endif

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck(((enableMode > TOM_ON_GLOBAL_TRIGGER)),
                 TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck((outputEnableMode > TOM_EN_OUTPUT_ON_GLOBAL_TRIGGER),
                 TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

        /*Set channel enable*/
        Gtm_Hw_Tom_PriSetChannelEnable(instance, channel, (enableMode == TOM_AT_START) ? (boolean)TRUE : (boolean)FALSE);
        Gtm_Hw_Tom_PriSetOutputEnable(instance, channel, (outputEnableMode ==  TOM_EN_OUTPUT_AT_START) ? (boolean)TRUE : (boolean)FALSE);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        tempRegBits = (((uint32)channel & 0x7U) << 1U);
        tempReg = (Tom_PubReg[instance]->TGC[channel >> 3].ENDIS_CTRL.R & ((uint32)0x3 << tempRegBits)) >> tempRegBits;
        GTM_REG_CHECK(tempReg, 0x2);
        if(enableMode == TOM_AT_START)
        {
            tempReg = (Tom_PubReg[instance]->TGC[channel >> 3].ENDIS_STAT.R & ((uint32)0x3 << tempRegBits)) >> tempRegBits;
            GTM_REG_CHECK(tempReg, 0x3);
        }else
        {
            /* do nothing */
        }

        tempReg = (Tom_PubReg[instance]->TGC[channel >> 3].OUTEN_CTRL.R & ((uint32)0x3 << tempRegBits)) >> tempRegBits;
        GTM_REG_CHECK(tempReg, 0x2);
        if(outputEnableMode ==  TOM_EN_OUTPUT_AT_START)
        {
            tempReg = (Tom_PubReg[instance]->TGC[channel >> 3].OUTEN_STAT.R & ((uint32)0x3 << tempRegBits)) >> tempRegBits;
            GTM_REG_CHECK(tempReg, 0x3);
        }else
        {
            /* do nothing */
        }
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)enableMode;
    (void)outputEnableMode;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_ChanelDisable
* @details      Disable tom channel.
* @param[in]    tomChannel:        Tom channel
* @param[in]    disableMode:       at or wait host trigger
* @param[in]    outputDisableMode: at or wait host trigger
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_ChanelDisable(Tom_ChannelType tomChannel,
                                    Tom_ChannelEnableType disableMode,
                                    Tom_ChannelOutputControlType outputDisableMode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    uint32 tempReg = 0;
    uint32 tempRegBits = 0;
#endif    /* TT_SAFETY */

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((disableMode > TOM_ON_GLOBAL_TRIGGER),
                 TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck((outputDisableMode > TOM_EN_OUTPUT_ON_GLOBAL_TRIGGER),
                 TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

        /*Disable channel*/
        Gtm_Hw_Tom_PriSetChannelDisable(instance, channel, (disableMode == TOM_AT_START) ? (boolean)TRUE : (boolean)FALSE);
        Gtm_Hw_Tom_PriSetOutputDisable(instance, channel, (outputDisableMode == TOM_EN_OUTPUT_AT_START ) ? (boolean)TRUE : (boolean)FALSE);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        tempRegBits = (((uint32)channel & 0x7U) << 1U);
        tempReg = ((uint32)Tom_PubReg[instance]->TGC[channel >> 3].ENDIS_CTRL.R & ((uint32)0x3U << tempRegBits)) >> tempRegBits;
        GTM_REG_CHECK(tempReg, 0x1);
        if(disableMode == TOM_AT_START)
        {
            tempReg = ((uint32)Tom_PubReg[instance]->TGC[channel >> 3].ENDIS_STAT.R & ((uint32)0x3U << tempRegBits)) >> tempRegBits;
            GTM_REG_CHECK(tempReg, 0x0);
        }else
        {
            /* do nothing */
        }

        tempReg = ((uint32)Tom_PubReg[instance]->TGC[channel >> 3].OUTEN_CTRL.R & ((uint32)0x3U << tempRegBits)) >> tempRegBits;
        GTM_REG_CHECK(tempReg, 0x1);
        if(outputDisableMode == TOM_EN_OUTPUT_AT_START)
        {
            tempReg = ((uint32)Tom_PubReg[instance]->TGC[channel >> 3].OUTEN_STAT.R & ((uint32)0x3U << tempRegBits)) >> tempRegBits;
            GTM_REG_CHECK(tempReg, 0x0);
        }else
        {
            /* do nothing */
        }
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)disableMode;
    (void)outputDisableMode;
    Ret = TT_RET_PARAM_ERR;
#endif /* TOM_MAX */

    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetHostTrigger
* @details      Generate hosttrig signal.
* @param[in]    tomInstance: Tom instance
* @param[in]    tgcIndex:    tgc number
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetHostTrigger(uint8 tomInstance, uint8 tgcIndex)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomInstance > TOM_INSTANCE_1), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((tgcIndex > TOM_TGCNUMBER_1), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_08();
#endif
        /*Generate a host trigger*/
        /* TT_SAFETY:This flag is reset automatically after triggering the update */
        Tom_PubReg[tomInstance]->TGC[tgcIndex].GLB_CTRL.B.HOST_TRIG = 1U;
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_08();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetUpdateCtrl
* @details      Generate update signal.
* @param[in]    tomInstance: Tom instance
* @param[in]    tgcIndex:    tgc number
* @param[in]    mask:        Data mask, 1 indicates that the corresponding channel is enabled
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetUpdateCtrl(uint8 tomInstance,
                                    uint8 tgcIndex,
                                    uint8 mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 i = 0;
    uint32 update = 0;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    uint32 updateMask = 0;
#endif

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomInstance > TOM_INSTANCE_1), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((tgcIndex > TOM_TGCNUMBER_1), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Generate update enable mask*/
        for(i = 0; i < 8; i++)
        {
            if((mask & (0x1U << i)) != 0x0U)
            {
                update |= (uint32)TOM_W_ENABLE << (i << 1U);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                updateMask |= (uint32)TOM_R_ENABLE << (i << 1U);
#endif
            }
            else
            {
                update |= (uint32)TOM_W_DISABLE << (i << 1U);
            }
        }

#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_09();
#endif
        /*Set update register*/
        GTM_REG_READ_2_WRITE(Tom_PubReg[tomInstance]->TGC[tgcIndex].GLB_CTRL.R, update, 0xFFFF, 16);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tom_PubReg[tomInstance]->TGC[tgcIndex].GLB_CTRL.R, updateMask);
#endif
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_09();
#endif

    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetCounterCn0
* @details      Set tom counter cn0.
* @param[in]    tomChannel:    Tom channel
* @param[in]    Cn0Value:    Cn0 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterCn0(Tom_ChannelType tomChannel,
                                    uint16 Cn0Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

        /*Set cn0, mainly used in one shot mode*/
        /* TT_SAFETY: Since the counter increments after modification, there is no point in reading back */
        Tom_PubReg[instance]->CH[channel].CN0.R = Cn0Value;
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Cn0Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_GetCounterCn0
* @details      Get tom counter cn0.
* @param[in]    tomChannel:    Tom channel
* @param[out]   Cn0Value:    Cn0 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterCn0(Tom_ChannelType tomChannel,
                                    uint16 *Cn0Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((Cn0Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

        *Cn0Value = (uint16)Tom_PubReg[instance]->CH[channel].CN0.R;
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Cn0Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetCounterCm0
* @details      Set tom counter cm0.
* @param[in]    tomChannel: Tom channel
* @param[in]    Cn0Value:   Cm0 counter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterCm0(Tom_ChannelType tomChannel,
                                    uint16 Cm0Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_10();
#endif
#endif
        Tom_PubReg[instance]->CH[channel].CM0.R = Cm0Value;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CM0.R, Cm0Value);
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_10();
#endif
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Cm0Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_GetCounterCm0
* @details      Get tom counter cm0.
* @param[in]    tomChannel:    Tom channel
* @param[out]   Value:        Cm0 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterCm0(Tom_ChannelType tomChannel,
                                    uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);
        *Value = (uint16)Tom_PubReg[instance]->CH[channel].CM0.R;
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetCounterCm1
* @details      Set tom counter cm1.
* @param[in]    tomChannel:    Tom channel
* @param[in]    Cn0Value:    Cm1 counter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterCm1(Tom_ChannelType tomChannel,
                                    uint16 Cm1Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_11();
#endif
#endif
        Tom_PubReg[instance]->CH[channel].CM1.R = Cm1Value;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CM1.R, Cm1Value);
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_11();
#endif
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Cm1Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_GetCounterCm1
* @details      Get tom counter cm1.
* @param[in]    tomChannel:    Tom channel
* @param[out]   Value:        Cm1 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterCm1(Tom_ChannelType tomChannel,
                                    uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

        *Value = (uint16)Tom_PubReg[instance]->CH[channel].CM1.R;
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetCounterSr0
* @details      Set tom counter sr0.
* @param[in]    tomChannel:  Tom channel
* @param[in]    Cn0Value:    Sr0 counter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterSr0(Tom_ChannelType tomChannel,
                                    uint16 Sr0Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_12();
#endif
#endif
        Tom_PubReg[instance]->CH[channel].SR0.R = Sr0Value;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].SR0.R, Sr0Value);
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_12();
#endif
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Sr0Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_GetCounterSr0
* @details      Get tom counter sr0.
* @param[in]    tomChannel:    Tom channel
* @param[out]   Value:        Sr0 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterSr0(Tom_ChannelType tomChannel,
                                    uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

        *Value = (uint16)Tom_PubReg[instance]->CH[channel].SR0.R;
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetCounterSr1
* @details      Set tom counter sr1.
* @param[in]    tomChannel:    Tom channel
* @param[in]    Cn0Value:      sr1 counter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterSr1(Tom_ChannelType tomChannel,
                                    uint16 Sr1Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_13();
#endif
#endif
        Tom_PubReg[instance]->CH[channel].SR1.R = Sr1Value;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].SR1.R, Sr1Value);
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_13();
#endif
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Sr1Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_GetCounterSr1
* @details      Get tom counter sr1.
* @param[in]    tomChannel:   Tom channel
* @param[out]   Value:        sr1 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterSr1(Tom_ChannelType tomChannel, uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    uint8 instance = 0;
    uint8 channel = 0;

    /*Check the correctness of parameters*/
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((Value == NULL_PTR), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get channnel information*/
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);

        *Value = (uint16)Tom_PubReg[instance]->CH[channel].SR1.R;
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetAllTrigerIn
* @details      This service set trigger_mux connectSource.
* @param[in]    GtmConnectCfg:    Connections Config
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetAllTrigerIn(TT_CONST Gtm_ConnectionsConfigType *GtmConnectCfg)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (GTM_CONNECTION == TRUE)
    TT_ParaCheck((GtmConnectCfg == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_14();
#endif
#endif
        GTM_WRAPPER->ADCTRIG[0].R = ((uint32)GtmConnectCfg->GtmTrigger0[0] |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[1] << 4) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[2] << 8) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[3] << 12) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[4] << 16) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[5] << 20) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[6] << 24) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[7] << 28));

        GTM_WRAPPER->ADCTRIG[1].R = ((uint32)GtmConnectCfg->GtmTrigger0[8] |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[9]  << 4) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[10] << 8) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger0[11] << 12));

        GTM_WRAPPER->ADCTRIG[2].R = (((uint32)GtmConnectCfg->GtmTrigger1[0]) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[1] << 4) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[2] << 8) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[3] << 12) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[4] << 16) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[5] << 20) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[6] << 24) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[7] << 28));

        GTM_WRAPPER->ADCTRIG[3].R = (((uint32)GtmConnectCfg->GtmTrigger1[8]) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[9]  << 4) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[10] << 8) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger1[11] << 12));

        GTM_WRAPPER->ADCTRIG[4].R = (((uint32)GtmConnectCfg->GtmTrigger2[0]) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[1] << 4) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[2] << 8) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[3] << 12) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[4] << 16) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[5] << 20) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[6] << 24) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[7] << 28));

        GTM_WRAPPER->ADCTRIG[5].R = (((uint32)GtmConnectCfg->GtmTrigger2[8]) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[9]  << 4) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[10] << 8) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger2[11] << 12));

        GTM_WRAPPER->ADCTRIG[6].R = (((uint32)GtmConnectCfg->GtmTrigger3[0]) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[1] << 4) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[2] << 8) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[3] << 12) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[4] << 16) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[5] << 20) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[6] << 24) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[7] << 28));

        GTM_WRAPPER->ADCTRIG[7].R = (((uint32)GtmConnectCfg->GtmTrigger3[8]) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[9]  << 4) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[10] << 8) |\
                                    ((uint32)GtmConnectCfg->GtmTrigger3[11] << 12));

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(GTM_WRAPPER->ADCTRIG[0].R ,
                      ((uint32)GtmConnectCfg->GtmTrigger0[0] |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[1] << 4) |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[2] << 8) |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[3] << 12) |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[4] << 16) |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[5] << 20) |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[6] << 24) |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[7] << 28)));

        GTM_REG_CHECK(GTM_WRAPPER->ADCTRIG[1].R ,
                      ((uint32)GtmConnectCfg->GtmTrigger0[8] |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[9]  << 4) |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[10] << 8) |\
                      ((uint32)GtmConnectCfg->GtmTrigger0[11] << 12)));

        GTM_REG_CHECK(GTM_WRAPPER->ADCTRIG[2].R ,
                      ((uint32)GtmConnectCfg->GtmTrigger1[0] |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[1] << 4) |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[2] << 8) |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[3] << 12) |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[4] << 16) |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[5] << 20) |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[6] << 24) |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[7] << 28)));

        GTM_REG_CHECK(GTM_WRAPPER->ADCTRIG[3].R ,
                      ((uint32)GtmConnectCfg->GtmTrigger1[8] |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[9]  << 4) |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[10] << 8) |\
                      ((uint32)GtmConnectCfg->GtmTrigger1[11] << 12)));

        GTM_REG_CHECK(GTM_WRAPPER->ADCTRIG[4].R ,
                      ((uint32)GtmConnectCfg->GtmTrigger2[0] |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[1] << 4) |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[2] << 8) |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[3] << 12) |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[4] << 16) |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[5] << 20) |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[6] << 24) |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[7] << 28)));

        GTM_REG_CHECK(GTM_WRAPPER->ADCTRIG[5].R ,
                      ((uint32)GtmConnectCfg->GtmTrigger2[8] |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[9]  << 4) |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[10] << 8) |\
                      ((uint32)GtmConnectCfg->GtmTrigger2[11] << 12)));

        GTM_REG_CHECK(GTM_WRAPPER->ADCTRIG[6].R ,
                      ((uint32)GtmConnectCfg->GtmTrigger3[0] |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[1] << 4) |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[2] << 8) |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[3] << 12) |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[4] << 16) |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[5] << 20) |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[6] << 24) |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[7] << 28)));

        GTM_REG_CHECK(GTM_WRAPPER->ADCTRIG[7].R ,
                      ((uint32)GtmConnectCfg->GtmTrigger3[8] |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[9]  << 4) |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[10] << 8) |\
                      ((uint32)GtmConnectCfg->GtmTrigger3[11] << 12)));
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_14();
#endif
#endif
    }
    else
    {
        /* do nothing */
    }
#else
    (void)GtmConnectCfg;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/**
* @brief        Gtm_Hw_Tom_SetTomInt
* @details      Enable or disable a specified interrupt
* @param[in]    tomChannel: Tom channel
* @param[in]    Irq_Mask: bit0:CCU0_IRQ enable/disable,bit1:CCU1_IRQ enable/disable
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetTomInt(TT_CONST Tom_ChannelType tomChannel,
                                TT_CONST uint8 Irq_Mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#if defined(TOM_MAX) && (TOM_MAX != 0)
    TT_ParaCheck((tomChannel >= TOM_MAX), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck(((Irq_Mask >> TOM_INTERRUPT_IRQ_BIT_NUM) != 0),
                 TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    uint8 instance = 0;
    uint8 channel = 0;

    if(Ret == TT_RET_SUCCESS)
    {
        instance = Gtm_Hw_Tom_PriGetInstance(tomChannel);
        channel = Gtm_Hw_Tom_PriGetChannel(tomChannel);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_15();
#endif
#endif
        Tom_PubReg[instance]->CH[channel].IRQ_EN.R = Irq_Mask;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].IRQ_EN.R, Irq_Mask);
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_15();
#endif
#endif
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Irq_Mask;
    Ret = TT_RET_PARAM_ERR;
#endif
    return Ret;
}

/******************************************************************************
 *                       Private Function
 ******************************************************************************/
/**
* @brief        Gtm_Hw_Tom_PriSetIntTrig
* @details      Initialize tom TGC unit.
* @param[in]    TomConfig : Tom configuration container
* @param[in]    tgcIndex  : Tom TGC Index
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetIntTrig(TT_CONST Tom_ConfigType *TomConfig,TT_CONST uint8 tgcIndex)
{
    uint32 u32RegInttrig = 0;

    u32RegInttrig =    (uint32)(TOM_GET_EN_CFG_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel0))
                    | ((uint32)(TOM_GET_EN_CFG_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel1)) << 2U) \
                    | ((uint32)(TOM_GET_EN_CFG_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel2)) << 4U) \
                    | ((uint32)(TOM_GET_EN_CFG_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel3)) << 6U) \
                    | ((uint32)(TOM_GET_EN_CFG_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel4)) << 8U) \
                    | ((uint32)(TOM_GET_EN_CFG_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel5)) << 10U) \
                    | ((uint32)(TOM_GET_EN_CFG_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel6)) << 12U) \
                    | ((uint32)(TOM_GET_EN_CFG_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel7)) << 14U);

    /*Write INT_TRIG register*/
    Tom_PubReg[tgcIndex >> 1U]->TGC[tgcIndex & 0x1U].INT_TRIG.R = u32RegInttrig;
}

/**
* @brief        Gtm_Hw_Tom_PriGetInstance
* @details      Get tom instance.
* @param[in]    Tom : hardware unit
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Tom_PriGetInstance(Tom_ChannelType tomChannel)
{
    return (Tom_PubParamInfo.TomChannelConfig[tomChannel].TomHwUnit >> (uint8)4);
}

/**
* @brief        Gtm_Hw_Tom_PriGetChannel
* @details      Get tom channel id.
* @param[in]    tomChannel : Tom channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Tom_PriGetChannel(Tom_ChannelType tomChannel)
{
    return (Tom_PubParamInfo.TomChannelConfig[tomChannel].TomHwUnit & (uint8)0xF);
}

/**
* @brief        Gtm_Hw_Tom_PriCfgRangeJudge
* @details      Configuring data validity judgment.
* @param[in]    TomConfig : Configuration caontions poniter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
static TT_RetType Gtm_Hw_Tom_PriCfgRangeJudge(TT_CONST Tom_ConfigType *TomConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 channelIndex = 0;
    uint8 tgcIndex = 0;

    for(tgcIndex = 0; tgcIndex < TOM_TCG_MAX; tgcIndex++)
    {
        /* TGC check */
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTimeBaseTriggerEnable != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTimeBaseTriggerEnable != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel0 != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel0 != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel1 != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel1 != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel2 != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel2 != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel3 != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel3 != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel4 != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel4 != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel5 != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel5 != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel6 != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel6 != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel7 != TRUE) &&
                (TomConfig->TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel7 != FALSE));
        GTM_DATA_RANGE_CHECK((uint32)TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTbuTimebaseSelect > TOM_TBU_TS2_TIMEBASE);
        GTM_DATA_RANGE_CHECK((TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTimebaseMatchValue >> 24) > 0);
    }
    /* Channel config check */
    for(channelIndex = 0; channelIndex < TOM_MAX; channelIndex++)
    {
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomChannelConfig[channelIndex].TomChannelOutputSignalLevel != TOM_LOW) &&
                (TomConfig->TomChannelConfig[channelIndex].TomChannelOutputSignalLevel != TOM_HIGH));

        GTM_DATA_RANGE_CHECK((TomConfig->TomChannelConfig[channelIndex].TomChannelCounterValCn0 >> 16) > 0);
        GTM_DATA_RANGE_CHECK((TomConfig->TomChannelConfig[channelIndex].TomChannelPeriodCompareValCm0 >> 16) > 0);
        GTM_DATA_RANGE_CHECK((TomConfig->TomChannelConfig[channelIndex].TomChannelDutyCycleCompareValCm1 >> 16) > 0);
        GTM_DATA_RANGE_CHECK((TomConfig->TomChannelConfig[channelIndex].TomChPeriodCompareShadowValSr0 >> 16) > 0);
        GTM_DATA_RANGE_CHECK((TomConfig->TomChannelConfig[channelIndex].TomChDCycCompareShadowValSr1 >> 16) > 0);
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomChannelConfig[channelIndex].TomChUpdateEnableOnCn0Reset != TRUE) &&
                (TomConfig->TomChannelConfig[channelIndex].TomChUpdateEnableOnCn0Reset != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomChannelConfig[channelIndex].TomChEnableForceUpdate != TRUE) &&
                (TomConfig->TomChannelConfig[channelIndex].TomChEnableForceUpdate != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomChannelConfig[channelIndex].TomChResetCn0OnForceUpdate != TRUE) &&
                (TomConfig->TomChannelConfig[channelIndex].TomChResetCn0OnForceUpdate != FALSE));
        GTM_DATA_RANGE_CHECK((uint32)TomConfig->TomChannelConfig[channelIndex].TomChannelClockSelect > TOM_FIXED_CLOCK_4);
        GTM_DATA_RANGE_CHECK((uint32)TomConfig->TomChannelConfig[channelIndex].TomChannelCounterCn0Reset > TOM_ON_TRIGGER_FROM_PREV_CH);
        GTM_DATA_RANGE_CHECK((uint32)TomConfig->TomChannelConfig[channelIndex].TomChannelExtCounterCn0Reset > TOM_TRG_TIM_EXT_CAPTURE);
        GTM_DATA_RANGE_CHECK((uint32)TomConfig->TomChannelConfig[channelIndex].TomChannelTriggerOutput > TOM_CCU0_TRIG_OF_CH);
        GTM_DATA_RANGE_CHECK((uint32)TomConfig->TomChannelConfig[channelIndex].TomChannelExtTriggerOutput > TOM_EXT_TRIG_TIM);
        GTM_DATA_RANGE_CHECK(TomConfig->TomChannelConfig[channelIndex].TomUpdownMode > 3);
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomChannelConfig[channelIndex].TomChannelOneShotMode != TRUE) &&
                (TomConfig->TomChannelConfig[channelIndex].TomChannelOneShotMode != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomChannelConfig[channelIndex].TomChannelTrigOneShotMode != TRUE) &&
                (TomConfig->TomChannelConfig[channelIndex].TomChannelTrigOneShotMode != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomChannelConfig[channelIndex].TomChannelSr0Trigger != TRUE) &&
                (TomConfig->TomChannelConfig[channelIndex].TomChannelSr0Trigger != FALSE));
        GTM_DATA_RANGE_CHECK(
                (TomConfig->TomChannelConfig[channelIndex].TomChannelBitReversalMode != TRUE) &&
                (TomConfig->TomChannelConfig[channelIndex].TomChannelBitReversalMode != FALSE));
    }

    return Ret;
}

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Hw_Tom_PriInitCheck
* @details      Tom Init Check.
* @param[in]    TomConfig: Tom config data
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
static TT_RetType Gtm_Hw_Tom_PriInitCheck(TT_CONST Tom_ConfigType *TomConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#if defined(TOM_MAX) && (TOM_MAX != 0)
    TT_CONST Tom_ChannelConfigType *channelConfig = NULL_PTR;
    uint8 channelIndex = 0;
    uint8 instance = 0;
    uint8 channel = 0;
    uint8 tgcIndex = 0;
    uint32 tempReg = 0;
    uint32 tempRegBits = 0;
    uint32 tempVal = 0;

    TT_ParaCheck((TomConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Config act*/
        for(tgcIndex = 0; tgcIndex < TOM_TCG_MAX; tgcIndex++)
        {
            if(TRUE == TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTimeBaseTriggerEnable)
            {
                /*Set act configuration*/
                GTM_REG_CHECK(Tom_PubReg[tgcIndex >> 1U]->TGC[tgcIndex & 0x1U].ACT_TB.B.ACT_TB, TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTimebaseMatchValue);
                GTM_REG_CHECK(Tom_PubReg[tgcIndex >> 1U]->TGC[tgcIndex & 0x1U].ACT_TB.B.TBU_SEL, TomConfig->TomTriggersForTgc[tgcIndex].TomTgcTbuTimebaseSelect);

                tempReg =  (uint32)(TOM_GET_EN_READ_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel0))
                        | ((uint32)(TOM_GET_EN_READ_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel1)) << 2U) \
                        | ((uint32)(TOM_GET_EN_READ_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel2)) << 4U) \
                        | ((uint32)(TOM_GET_EN_READ_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel3)) << 6U) \
                        | ((uint32)(TOM_GET_EN_READ_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel4)) << 8U) \
                        | ((uint32)(TOM_GET_EN_READ_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel5)) << 10U) \
                        | ((uint32)(TOM_GET_EN_READ_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel6)) << 12U) \
                        | ((uint32)(TOM_GET_EN_READ_VAL(TomConfig[0].TomTriggersForTgc[tgcIndex].TomTgcIntTriggerFromChannel7)) << 14U);
                GTM_REG_CHECK(Tom_PubReg[tgcIndex >> 1U]->TGC[tgcIndex & 0x1U].INT_TRIG.R, tempReg);
            }
            else
            {
                /* do nothing */
            }
        }

        /*Config channel*/
        for(channelIndex = 0; channelIndex < TOM_MAX; channelIndex++)
        {
            /*Get channnel information*/
            channelConfig = &TomConfig->TomChannelConfig[channelIndex];
            channel = Gtm_Hw_Tom_PriGetChannel(channelIndex);
            instance = Gtm_Hw_Tom_PriGetInstance(channelIndex);

            /*check update mechanisms*/
            tempRegBits = (((uint32)channel & (uint32)0x7U) << (uint32)1U);
            tempVal = TOM_GET_EN_READ_VAL(channelConfig->TomChUpdateEnableOnCn0Reset);
            tempReg = (Tom_PubReg[instance]->TGC[channel >> 3U].GLB_CTRL.R & ((uint32)0x3U << (tempRegBits + 16))) >> (tempRegBits + 16U);
            GTM_REG_CHECK(tempReg, tempVal);

            tempVal = TOM_GET_EN_READ_VAL(channelConfig->TomChEnableForceUpdate);
            tempReg = (Tom_PubReg[instance]->TGC[channel >> 3U].FUPD_CTRL.R & ((uint32)0x3U << tempRegBits)) >> tempRegBits;
            GTM_REG_CHECK(tempReg, tempVal);

            tempVal = TOM_GET_EN_READ_VAL(channelConfig->TomChResetCn0OnForceUpdate);
            tempReg = (Tom_PubReg[instance]->TGC[channel >> 3U].FUPD_CTRL.R & ((uint32)0x3U << (tempRegBits + 16U))) >> (tempRegBits + 16U);
            GTM_REG_CHECK(tempReg, tempVal);

            /*check signal value*/
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.SL, channelConfig->TomChannelOutputSignalLevel);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL_SR.B.SL, channelConfig->TomChannelOutputSignalLevel);

            /*check base config*/
            if(FALSE == channelConfig->TomChannelOneShotMode)
            {
                GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CN0.R, channelConfig->TomChannelCounterValCn0);
            }
            else
            {
                /*check oneshot mode*/
                GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.OSM, channelConfig->TomChannelOneShotMode);
                GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.OSM_TRIG, channelConfig->TomChannelTrigOneShotMode);
            }

            /*check counter*/
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CM0.R, channelConfig->TomChannelPeriodCompareValCm0);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CM1.R, channelConfig->TomChannelDutyCycleCompareValCm1);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].SR0.R, channelConfig->TomChPeriodCompareShadowValSr0);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].SR1.R, channelConfig->TomChDCycCompareShadowValSr1);

            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.TRIGOUT, channelConfig->TomChannelTriggerOutput);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.RST_CCU0, channelConfig->TomChannelCounterCn0Reset);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.EXT_TRIG, channelConfig->TomChannelExtCounterCn0Reset);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.EXTTRIGOUT, channelConfig->TomChannelExtTriggerOutput);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.UDMODE, channelConfig->TomUpdownMode);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.CLK_SRC_SR, channelConfig->TomChannelClockSelect);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL_SR.B.CLK_SRC_SR, channelConfig->TomChannelClockSelect);
            GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.SR0_TRIG, channelConfig->TomChannelSr0Trigger);

            /*check bit reversal*/
            if(TOM_CH_15 == channel)
            {
                GTM_REG_CHECK(Tom_PubReg[instance]->CH[channel].CTRL.B.BITREV, channelConfig->TomChannelBitReversalMode);
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
    (void)TomConfig;
    Ret = TT_RET_PARAM_ERR;
#endif

    return Ret;
}
#endif

#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

#endif

#ifdef __cplusplus
}
#endif
