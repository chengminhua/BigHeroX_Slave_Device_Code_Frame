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
**  FILENAME     : Adc_Hw.c                                                   **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Alioth Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Adc_Hw.h"
#include "Base_Drv.h"
#include <math.h>
#ifdef USING_OS_AUTOSAROS
#include "SchM_Adc.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define ADC_HW_VENDOR_ID_C                    1541
#define ADC_HW_MODULE_ID_C                    123
#define ADC_HW_INSTANCE_ID_C                  0
#define ADC_HW_AR_RELEASE_MAJOR_VERSION_C     4
#define ADC_HW_AR_RELEASE_MINOR_VERSION_C     4
#define ADC_HW_AR_RELEASE_PATCH_VERSION_C     0
#define ADC_HW_SW_MAJOR_VERSION_C             1
#define ADC_HW_SW_MINOR_VERSION_C             1
#define ADC_HW_SW_PATCH_VERSION_C             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Adc_Hw.c Adc_Hw.h file version check */
#if (ADC_HW_VENDOR_ID_C != ADC_HW_VENDOR_ID_H)
    #error "Adc_Hw.c and Adc_Hw.h have different vendor ids"
#endif

#if (ADC_HW_MODULE_ID_C != ADC_HW_MODULE_ID_H)
    #error "Adc_Hw.c and Adc_Hw.h have different module ids"
#endif

#if (ADC_HW_INSTANCE_ID_C != ADC_HW_INSTANCE_ID_H)
    #error "Adc_Hw.c and Adc_Hw.h have different Instance ids"
#endif

#if ((ADC_HW_AR_RELEASE_MAJOR_VERSION_C != ADC_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_HW_AR_RELEASE_MINOR_VERSION_C != ADC_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_HW_AR_RELEASE_PATCH_VERSION_C != ADC_HW_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Hw.c and Adc_Hw.h are different"
#endif

#if ((ADC_HW_SW_MAJOR_VERSION_C != ADC_HW_SW_MAJOR_VERSION_H) || \
     (ADC_HW_SW_MINOR_VERSION_C != ADC_HW_SW_MINOR_VERSION_H) || \
     (ADC_HW_SW_PATCH_VERSION_C != ADC_HW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Hw.c and Adc_Hw.h are different"
#endif

/* Adc_Hw.c Base_Drv.h file version check */
#if (ADC_HW_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
    #error "Adc_Hw.c and Base_Drv.h have different vendor ids"
#endif

#if ((ADC_HW_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_HW_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_HW_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Hw.c and Base_Drv.h are different"
#endif

#if ((ADC_HW_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (ADC_HW_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
     (ADC_HW_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Hw.c and Base_Drv.h are different"
#endif

#ifdef USING_OS_AUTOSAROS
/* Adc_Hw.c SchM_Adc.h file version check */
#if (ADC_HW_VENDOR_ID_C != SCHM_ADC_VENDOR_ID_H)
    #error "Adc_Hw.c and SchM_Adc.h have different vendor ids"
#endif

#if ((ADC_HW_AR_RELEASE_MAJOR_VERSION_C != SCHM_ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_HW_AR_RELEASE_MINOR_VERSION_C != SCHM_ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_HW_AR_RELEASE_PATCH_VERSION_C != SCHM_ADC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Hw.c and SchM_Adc.h are different"
#endif

#if ((ADC_HW_SW_MAJOR_VERSION_C != SCHM_ADC_SW_MAJOR_VERSION) || \
     (ADC_HW_SW_MINOR_VERSION_C != SCHM_ADC_SW_MINOR_VERSION) || \
     (ADC_HW_SW_PATCH_VERSION_C != SCHM_ADC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_Hw.c and SchM_Adc.h are different"
#endif

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

/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/
#ifndef A8V2E
static uint8 CH_STATE[ADC_MAX_UNITS] = {0};
#endif

#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
/*ADC hardware unit register*/
static TT_CONST Adc_Hw_Resources AdcHw_PubResource[ADC_HWUNIT_INSTANCE] =
{
    { .Reg = &TT_ADC->AXCHREGT[0] },
    { .Reg = &TT_ADC->AXCHREGT[1] },
    { .Reg = &TT_ADC->AXCHREGT[2] },
    { .Reg = &TT_ADC->AXCHREGT[3] },
    { .Reg = &TT_ADC->AXCHREGT[4] },
    { .Reg = &TT_ADC->AXCHREGT[5] }
};

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

#ifndef USING_OS_AUTOSAROS
/**
 *@brief          ADC IRQ handler
 *
 *@param[in]      HwUnit - Adc unit Id
 *@return         void
 *@retval         NON
 *@retval         NON
 */
static void Adc_Hw_PriHandlerFunction (Adc_Hw_HwUnitType HwUnit);
#endif

/**
 *@brief          The linear equation is fitted according to the input data
 *
 *@param[in]      fVolt - volt input
 *@param[in]      nAdcCap - adc code
 *@param[in]      nElement - n Element
 *@param[out]     pLE - Calculate the y = kx + b
 *@return         void
 */
static void Adc_Hw_PriCalLineEquation(float64* fVolt,
                                      float64* nAdcCap,
                                      uint8 nElement,
                                      Adc_Hw_LineEquation* pLE);

static TT_RetType Adc_Hw_PriSampValue(TT_CONST Adc_Hw_HwUnitType HwUnit,
                                      float64 *Data_y,
                                      uint32 chop_value,
                                      uint32 i);

static TT_RetType Adc_Hw_PriFir (TT_CONST Adc_Hw_CommonConfigType *Config);
LOCAL_INLINE void Adc_Hw_PriRegReadBack (uint32 ActualValue, uint32 TargetValue, TT_RetType *Ret);
/******************************************************************************
 *                            Public Functions
 ******************************************************************************/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/**
 *@brief          Adc common config
 *
 *@param[in]      config - Adc Common Config
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_CommonInit (TT_CONST Adc_Hw_CommonConfigType *Config)
{

    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Clk = 0;

    TT_ParaCheck ((Config == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && (Config->FirShift > ADC_FIRSHIFT_MAX), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->Div > ADC_DIV_MAX) || (Config->FTSamp > ADC_FTSAMP_MAX)),
                    TT_RET_PARAM_LEN_ERR, &Ret);
#ifdef A8V2E
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->Clk_Stop != TRUE) && (Config->Clk_Stop != FALSE)),
                    TT_RET_PARAM_ENUM_ERR, &Ret);
#endif
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->Acg0_Wp != TRUE) && (Config->Acg0_Wp != FALSE)),
                    TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->Filter->Fir_Wp != TRUE) && (Config->Filter->Fir_Wp != FALSE)),
                    TT_RET_PARAM_ENUM_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_SYSTEM, &Clk);

        TT_ParaCheck(((Clk / (uint32)(Config->Div + (uint32)1U) > (uint32)ADC_FREQUENCY_MAX)),
                     TT_RET_PARAM_LEN_ERR, &Ret);

        if (Ret == TT_RET_SUCCESS)
        {
            if (TT_FLD2BOOL(TT_ADC_AGC0_AGC0_WP,TT_ADC->AGC0) == FALSE)
            {
#ifdef A8V2E
                TT_ADC->AGC0 = ((uint32) Config->FirShift << TT_ADC_AGC0_FIR_SHIFT_Pos) |\
                               ((uint32) Config->STSamp << TT_ADC_AGC0_STSAMP_Pos) |\
                               ((uint32) Config->FTSamp << TT_ADC_AGC0_FTSAMP_Pos)|\
                               ((uint32) Config->Div << TT_ADC_AGC0_DIV_Pos) |\
                               ((uint32) Config->Clk_Stop << TT_ADC_AGC0_CLK_STOP_Pos) |\
                               ((uint32) Config->Acg0_Wp << TT_ADC_AGC0_AGC0_WP_Pos);
#else
                TT_ADC->AGC0 = ((uint32) Config->FirShift << TT_ADC_AGC0_FIR_SHIFT_Pos) |\
                               ((uint32) Config->STSamp << TT_ADC_AGC0_STSAMP_Pos) |\
                               ((uint32) Config->FTSamp << TT_ADC_AGC0_FTSAMP_Pos)|\
                               ((uint32) Config->Div << TT_ADC_AGC0_DIV_Pos) |\
                               ((uint32) Config->Acg0_Wp << TT_ADC_AGC0_AGC0_WP_Pos);
#endif
                Ret = Adc_Hw_PriFir(Config);
            }
            else
            {
                Ret = TT_RET_STATUS_LOCKED_ERR;
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
    return Ret;
}

/**
 *@brief          ADC hardware unit configuration
 *
 *@param[in]      Config - Adc HwUnit Config Channel
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_AdcxConfig (TT_CONST Adc_Hw_HwUnitConfigType *Config)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 AxCFR = 0;
#ifdef A8V2E
    TT_CONST uint32 Queue_Max = 0x88888888U;
#else
    TT_CONST uint32 Queue_Max = 0xDDDDDDDDU;
#endif
    TT_ParaCheck((Config == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Config != NULL_PTR) && ((Config->CompenData > ADC_POSITIVE_COMPENDATA_MAX) || \
                 (Config->CompenData < ADC_NEGATIVE_COMPENDATA_MAX)), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->Enable != TRUE) && (Config->Enable != FALSE)),
                  TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->CompenEn != TRUE) && (Config->CompenEn != FALSE)),
                  TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->DmaEn != TRUE) && (Config->DmaEn != FALSE)),
                  TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->DmaIntEn != TRUE) && (Config->DmaIntEn != FALSE)),
                  TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->WaitRead != TRUE) && (Config->WaitRead != FALSE)),
                  TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && (Config->CMode > ADC_HW_CANCEL_INJECT_REPEAT),
                  TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && (Config->DmaMode > ADC_DMA_MODE_SEQUENCES),
                  TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Config != NULL_PTR) && (Config->Queue > Queue_Max),
                 TT_RET_PARAM_LEN_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        AxCFR = ((uint32)Config->Enable << TT_ADC_CFR_EN_Pos) |\
                ((uint32)Config->CMode << TT_ADC_CFR_CMCODE_Pos) |\
                ((uint32)Config->CompenEn << TT_ADC_CFR_COMPUEN_Pos) |\
                ((uint32)Config->WaitRead << TT_ADC_CFR_WAIT_TO_READ_Pos) |\
                ((uint32)Config->DmaEn << TT_ADC_CFR_DMA_EN_Pos) |\
                ((uint32)Config->DmaIntEn << TT_ADC_CFR_DMA_INT_EN_Pos) |\
                ((uint32)Config->DmaMode << TT_ADC_CFR_DMA_MODE_Pos);

        if (Config->CompenEn)
        {
            if (Config->CompenData < 0)
            {
                AxCFR |= ((uint32) (-Config->CompenData) << TT_ADC_CFR_COMP_DATA_Pos) |\
                         TT_ADC_AXCFR_COMPU_POLARITY_Msk;
            }
            else
            {
                AxCFR |= ((uint32) Config->CompenData << TT_ADC_CFR_COMP_DATA_Pos);
            }
        }
        else
        {
            /* do nothing */
        }

        TT_ADC->CFR[Config->AdcHwUnitId] &= ~(TT_ADC_CFR_EN_Msk |\
                                               TT_ADC_CFR_COMPUEN_Msk |\
                                               TT_ADC_CFR_CMCODE_Msk |\
                                               TT_ADC_CFR_DMA_MODE_Msk |\
                                               TT_ADC_CFR_DMA_EN_Msk |\
                                               TT_ADC_CFR_DMA_INT_EN_Msk |\
                                               TT_ADC_CFR_COMP_DATA_Msk |\
                                               TT_ADC_CFR_WAIT_TO_READ_Msk);

        TT_ADC->CFR[Config->AdcHwUnitId] |= AxCFR;
        TT_ADC->REQSEQ[Config->AdcHwUnitId] = Config->Queue;
        Adc_Hw_PriRegReadBack(Config->Queue, TT_ADC->REQSEQ[Config->AdcHwUnitId], &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          ADC disable hardware unit
 *
 *@param[in]      UintId - Adc HwUnit ID
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_AdcxDisable (TT_CONST Adc_Hw_HwUnitType UnitId)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Reg_temp = 0;
    uint8 i = 0;

    TT_ADC->CFR[UnitId] &= ~(uint32)0x1;
    MCAL_DATA_SYNC_BARRIER();

    if (TT_FLD2BOOL(TT_ADC_CFR_EN,TT_ADC->CFR[UnitId]) == FALSE)
    {
        for(i = 0; i <= ADC_MAX; i++)
        {
            Reg_temp |= TT_ADC->CFR[i];
        }

        if ((boolean)(Reg_temp & TT_ADC_CFR_EN_Msk))
        {
            /* do nothing */
        }
        else
        {
            Ret = Mcu_Drv_Misc_LocalResetModules (TT_SCU_LOCAL_RST_ADC);
            if(Ret == TT_RET_SUCCESS)
            {
                Ret = Mcu_Drv_Clk_StopModules (TT_SCU_CLK_CONTROL_ADC);
                if(Ret == TT_RET_SUCCESS)
                {
                    /* do nothing */
                }
                else
                {
                    Ret = TT_RET_STATUS_UNINIT_ERR;
                }
            }
            else
            {
                Ret = TT_RET_STATUS_UNINIT_ERR;
            }
        }
    }
    else
    {
        Ret = TT_RET_STATUS_UNINIT_ERR;
    }

    return Ret;
}

/**
 *@brief          ADC Channel configuration
 *
 *@param[in]      Config - Adc Channel Configuration information
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_ChannelConfig (TT_CONST Adc_Hw_ChannelConfigType *Config)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 CFR_Temp = 0;
    uint32 CTRLR_Temp = 0;
    uint32 Threshold_Temp = 0;
    uint8 Instance = 0;
    uint8 Channel = 0;
    TT_CONST Adc_Hw_Resources *Adc_Ch_Resources = NULL_PTR;

    TT_ParaCheck ((Config == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->Shift > ADC_SHIFT_MAX) || \
                  (Config->SampNum > ADC_SAMPNUM_MAX)), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->SampNum == ADC_SAMPNUM_MAX) && \
                  (Config->Shift < ADC_SHIFT_MIN)), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && (Config->DmaConfig.DmaTranCount > ADC_DMATRANCOUNT_MAX),
                  TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->ReadyIntEn != TRUE) && \
                  (Config->ReadyIntEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->FSampEn != TRUE) && \
                  (Config->FSampEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->FirEn != TRUE) && \
                  (Config->FirEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->TrgDmaIntEn != TRUE) && \
                  (Config->TrgDmaIntEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->TrgIntEn != TRUE) && \
                  (Config->TrgIntEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->DmaConfig.DmaErrorEn != TRUE) && \
                  (Config->DmaConfig.DmaErrorEn != FALSE)),TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->HCompEn != TRUE) && \
                  (Config->HCompEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->LCompEn != TRUE) && \
                  (Config->LCompEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->LCompIntEn != TRUE) && \
                  (Config->LCompIntEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->HCompIntEn != TRUE) && \
                  (Config->HCompIntEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
#ifdef A8V2E
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->TimeoutIntEn != TRUE) && \
                  (Config->TimeoutIntEn != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && ((Config->CompIntEn != TRUE) && (Config->CompIntEn != FALSE)),
                  TT_RET_PARAM_ENUM_ERR, &Ret);
#endif
    TT_ParaCheck ((Config != NULL_PTR) && (Config->TrigSrc > ADC_TRIG_SRC_HW),TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && (Config->TrigEdge > ADC_HW_TRIG_BOTH_EDGES),TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && (Config->Priority > ADC_PRIORITY_BEST_LOW), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck ((Config != NULL_PTR) && (Config->ChId > ADC_CH_MAX), TT_RET_PARAM_LEN_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (Config->ChId);
        Channel = Adc_Hw_GetChannel (Config->ChId);
#ifdef A8V2E
        if(Instance == (uint8)ADC0)
        {
            TT_ParaCheck ((Config->CTrig > CTRIG_CHANNEL8), TT_RET_PARAM_CHANNEL_ERR, &Ret);
        }
        else
        {
            TT_ParaCheck ((Config->CTrig > CTRIG_CHANNEL7), TT_RET_PARAM_CHANNEL_ERR, &Ret);
        }
#else
    TT_ParaCheck ((Config->CTrig > CTRIG_CHANNEL13), TT_RET_PARAM_LEN_ERR, &Ret);
#endif
        if (Ret == TT_RET_SUCCESS)
        {
            Adc_Ch_Resources = &AdcHw_PubResource[Instance];

            CFR_Temp |= ((uint32)Config->Shift << TT_ADC_AxCyCFR_SHIFT_Pos) |\
                        ((uint32)Config->SampNum << TT_ADC_AxCyCFR_SAMPNUM_Pos) |\
                        ((uint32)Config->ReadyIntEn << TT_ADC_AxCyCFR_READYINTEN_Pos) |\
                        ((uint32)Config->FSampEn << TT_ADC_AxCyCFR_FSAMPEN_Pos) |\
                        ((uint32)Config->FirEn << TT_ADC_AxCyCFR_FIREN_Pos) |\
                        ((uint32)Config->TrgDmaIntEn << TT_ADC_AxCyCFR_TRGDMAINTEN_Pos) |\
                        ((uint32)Config->TrgIntEn << TT_ADC_AxCyCFR_TRGINTIN_Pos) |\
                        ((uint32)Config->DmaConfig.DmaTranCount << TT_ADC_AxCyCFR_TRANSIZE_Pos) |\
                        ((uint32)Config->DmaConfig.DmaErrorEn << TT_ADC_AxCyCFR_DMA_ERR_Pos)|\
                        ((uint32)Config->HCompEn << TT_ADC_AxCyCFR_HCOMPEN_Pos)|\
                        ((uint32)Config->LCompEn << TT_ADC_AxCyCFR_LCOMPEN_Pos)|\
                        ((uint32)Config->LCompIntEn << TT_ADC_AxCyCFR_LCOMPINTEN_Pos)|\
                        ((uint32)Config->HCompIntEn << TT_ADC_AxCyCFR_HCOMPINTEN_Pos);
#ifdef A8V2E
            CFR_Temp |= ((uint32)Config->TimeoutIntEn << TT_ADC_AxCyCFR_TIMEOUTINTEN_Pos) |\
                        ((uint32)Config->CompIntEn << TT_ADC_AxCyCFR_COMPINTEN_Pos);
 #endif
            CTRLR_Temp |= ((uint32) Config->TrigSrc << TT_ADC_AxCyCTRLR_EXTTRGEN_Pos) |\
                          ((uint32) Config->TrigEdge << TT_ADC_AxCyCTRLR_PLUSECTRL_Pos) |\
                          ((uint32) Config->CTrig << TT_ADC_AxCyCTRLR_CTRIGGLE_Pos) |\
                          ((uint32) Config->Priority << TT_ADC_AxCyCTRLR_CPRIO_Pos);

            Threshold_Temp |= ((uint32) Config->ThresholdH << TT_ADC_AxCyTVR_THHOLDVALUEH_Pos) |\
                              ((uint32) Config->ThresholdL << TT_ADC_AxCyTVR_THHOLDVALUEL_Pos);

#ifdef A8V2E
            if(Config->SampNum != 0)
            {
                TT_ADC->DAC_CHOP = 1U;
            }
            else
            {
            /*do nothing*/
            }
#endif
            Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR = CFR_Temp;
            Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR = CTRLR_Temp;
            Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyTVR = Threshold_Temp;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            Adc_Hw_PriRegReadBack(CFR_Temp, Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR, &Ret);
            Adc_Hw_PriRegReadBack(CTRLR_Temp, Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR, &Ret);
            Adc_Hw_PriRegReadBack(Threshold_Temp, Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyTVR, &Ret);
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

    return Ret;
}

/**
 *@brief          ADC start conversion
 *
 *@param[in]      ChannelI - Adc Channel Id
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_StartConvert (TT_CONST Adc_Hw_ChannelType ChannelId)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

#ifdef USING_OS_AUTOSAROS
        /* Enter exclusive area: implementation depends on integrator */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05();
#endif
        TT_ADC->AXCHREGT[Instance].AXCYREGT[Channel].AxCyCTRLR |= TT_ADC_AxCyCTRLR_REQ_Msk;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((TT_ADC->AXCHREGT[Instance].AXCYREGT[Channel].AxCyCTRLR & TT_ADC_AxCyCTRLR_REQ_Msk) != TT_ADC_AxCyCTRLR_REQ_Msk)
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
#ifdef USING_OS_AUTOSAROS
        /* Exit exclusive area: implementation depends on integrator */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          This function stops the current conversion of a group.
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      Stop - Stop mode
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_StopConversion (TT_CONST Adc_Hw_HwUnitType HwUnit,
                                  TT_CONST Adc_Hw_StopModeType Stop)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck ((Stop > ADC_FORCE_STOP), TT_RET_PARAM_LEN_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        if (TT_FLD2BOOL(TT_ADC_CFR_EN, TT_ADC->CFR[HwUnit]) == FALSE)
        {
            Ret = TT_RET_STATUS_ERR;
        }
        else
        {
#ifdef USING_OS_AUTOSAROS
            /* Enter exclusive area: implementation depends on integrator */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();
#endif
            TT_ADC->CFR[HwUnit] &= ~TT_ADC_CFR_ADCSTOP_Msk;
            TT_ADC->CFR[HwUnit] |= (uint32) Stop << TT_ADC_CFR_ADCSTOP_Pos;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            if(Stop == ADC_DYNAMIC_STOP)
            {
                if((TT_ADC->CFR[HwUnit] & TT_ADC_CFR_ADCSTOP_Msk)!= \
                        (uint32) ADC_DYNAMIC_STOP << TT_ADC_CFR_ADCSTOP_Pos)
                {
                    Ret = TT_RET_OPT_REG_ERR;
                }
                else
                {
                    Ret = TT_RET_SUCCESS;
                }
            }
            else
            {
                if((TT_ADC->STR[HwUnit] & TT_ADC_STR_BUSY_Msk) == TT_ADC_STR_BUSY_Msk)
                {
                    Ret = TT_RET_OPT_REG_ERR;
                }
                else
                {
                    Ret = TT_RET_SUCCESS;
                }
            }
#endif
#ifdef USING_OS_AUTOSAROS
            /* Exit exclusive area: implementation depends on integrator */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
#endif
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          ADC DMA Buffer configuration
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      result - Result buffer
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetDmaBuff (TT_CONST Adc_Hw_ChannelType ChannelId,
                              TT_CONST uint16 *result)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck ((result == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxDMAADDR = (uint32)((uint32) result & TT_ADC_AxCyDMAADDR_DST_Msk);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if(Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxDMAADDR != (uint32)((uint32) result & TT_ADC_AxCyDMAADDR_DST_Msk))
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          Configure the number of dma transfers
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      Count - Number of dma transfers
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetDmaTransCount (TT_CONST Adc_Hw_ChannelType ChannelId,
                                    TT_CONST uint32 Count)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Instance = 0;
    uint8 Channel = 0;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck ((Count > ADC_DMATRANCOUNT_MAX), TT_RET_PARAM_COUNT_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];

#ifdef USING_OS_AUTOSAROS
        /* Enter exclusive area: implementation depends on integrator */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_07();
#endif
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR &= ~TT_ADC_AxCyCFR_TRANSIZE_Msk;
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR |= (Count << TT_ADC_AxCyCFR_TRANSIZE_Pos);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR & TT_ADC_AxCyCFR_TRANSIZE_Msk) != (Count << TT_ADC_AxCyCFR_TRANSIZE_Pos) )
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
#ifdef USING_OS_AUTOSAROS
        /* Exit exclusive area: implementation depends on integrator */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          Adc_Hw_SetTrigger
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      TrigSrc - Trigger source
 *@param[in]      TrigSig - Trigger Edge
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetTrigger (TT_CONST Adc_Hw_ChannelType ChannelId,
                              TT_CONST Adc_Hw_TrigSrcType TrigSrc,
                              TT_CONST Adc_Hw_HwTrigSigType TrigSig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Instance = 0;
    uint8 Channel = 0;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;

    TT_ParaCheck((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((TrigSrc > ADC_TRIG_SRC_HW), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((TrigSig > ADC_HW_TRIG_BOTH_EDGES), TT_RET_PARAM_LEN_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR &= ~(TT_ADC_AxCyCTRLR_EXTTRGEN_Msk | TT_ADC_AxCyCTRLR_PLUSECTRL_Msk);
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR |= ((uint32) TrigSrc << TT_ADC_AxCyCTRLR_EXTTRGEN_Pos) | \
                                                              ((uint32) TrigSig << TT_ADC_AxCyCTRLR_PLUSECTRL_Pos);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR & ((TT_ADC_AxCyCTRLR_EXTTRGEN_Msk | TT_ADC_AxCyCTRLR_PLUSECTRL_Msk)))\
                != (((uint32) TrigSrc << TT_ADC_AxCyCTRLR_EXTTRGEN_Pos) | ((uint32) TrigSig << TT_ADC_AxCyCTRLR_PLUSECTRL_Pos)))
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          Adc_Hw_SetReadyIntEn
 *
 *@param[in]      ChannelId - Channel Id
 *@param[in]      Enable - Ready interrupt enable
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetReadyIntEn (TT_CONST Adc_Hw_ChannelType ChannelId,
                                 TT_CONST uint8 Enable)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck (((Enable != TRUE) && (Enable != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
#ifdef USING_OS_AUTOSAROS
        /* Enter exclusive area: implementation depends on integrator */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08();
#endif
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR &= ~TT_ADC_AxCyCFR_READYINTEN_Msk;
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR |= (uint32)Enable << TT_ADC_AxCyCFR_READYINTEN_Pos;
#ifdef USING_OS_AUTOSAROS
        /* Exit exclusive area: implementation depends on integrator */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR & TT_ADC_AxCyCFR_READYINTEN_Msk) != (uint32)Enable << TT_ADC_AxCyCFR_READYINTEN_Pos)
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          Configure the dma incremental address
 *
 *@param[in]      AdcChannel - Adc Channel Id
 *@param[in]      Incraddr - Address accumulation value
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_Set_DmaIncraddr (TT_CONST Adc_Hw_ChannelType ChannelId,
                                   TT_CONST uint32 Incraddr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck ((Incraddr > ADC_DMAINCRADDR_MAX), TT_RET_PARAM_VALUE_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxDMAINCRADDR &=  ~TT_ADC_AxCyDMAADDR_INC_Msk;
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxDMAINCRADDR |= (Incraddr << TT_ADC_AxCyDMAADDR_INC_Pos);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxDMAINCRADDR & TT_ADC_AxCyDMAADDR_INC_Msk) != Incraddr )
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          Get ADC Global status
 *
 *@param[in]      HwUnit - Adc Unit Id
 *@param[out]     Value -  ADC Global status
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_GetGlobalState (TT_CONST Adc_Hw_HwUnitType HwUnit, uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck ((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *Value = TT_ADC->GSTR[HwUnit];
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          Get ADC Current state
 *
 *@param[in]      HwUnit - Adc Unit Id
 *@param[out]     Value - ADC Current status
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_GetCurrentState (TT_CONST Adc_Hw_HwUnitType HwUnit,
                                   uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck ((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *Value = TT_ADC->STR[HwUnit];
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          Get ADC Channel status
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[out]     Value - channel state
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_GetChannelState (TT_CONST Adc_Hw_ChannelType ChannelId,
                                   uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck ((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
        *Value = Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCySTR;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
@brief          Clear ADC Global status
@param[in]      ChannelId: Adc Channel Id
                DmaClear : clear the DMA flag
@return         TT_RetType
@retval         E_OK            Succeed
@retval         E_NOT_OK        failure
*/
TT_RetType Adc_Hw_ClearGlobalState(TT_CONST Adc_Hw_ChannelType ChannelId,TT_CONST boolean DmaClear)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck (((DmaClear != TRUE) && (DmaClear != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance(ChannelId);
        Channel = Adc_Hw_GetChannel(ChannelId);

        if((boolean)DmaClear)
        {
#ifdef USING_OS_AUTOSAROS
        /* Enter exclusive area: implementation depends on integrator */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11();
#endif
            TT_ADC->GSTR[Instance] = 0xFFFFFFFFU;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            if((boolean)(TT_ADC->GSTR[Instance] & 0xFFFFFFFFU))
            {
                Ret = TT_RET_STATUS_ERR;
            }
            else
            {
                Ret = TT_RET_SUCCESS;
            }
#endif
#ifdef USING_OS_AUTOSAROS
        /* Exit exclusive area: implementation depends on integrator */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11();
#endif
        }
        else
        {
#ifdef USING_OS_AUTOSAROS
        /* Enter exclusive area: implementation depends on integrator */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12();
#endif
            TT_ADC->GSTR[Instance] = (uint32)0x10001 << Channel;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            if((boolean)(TT_ADC->GSTR[Instance] & ((uint32)0x10001 << Channel)))
            {
                Ret = TT_RET_STATUS_ERR;
            }
            else
            {
                Ret = TT_RET_SUCCESS;
            }
#endif
#ifdef USING_OS_AUTOSAROS
        /* Exit exclusive area: implementation depends on integrator */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12();
#endif
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}


/**
 *@brief          Get ADC conversion data
 *
 *@param[in]      AdcChannel - Adc Channel Id
 *@param[out]     Value -  ADC Value
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_GetValue (TT_CONST Adc_Hw_ChannelType ChannelId, uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck ((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
#ifndef A8V2E
        /* attention */
        if( ((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCySTR & A0CYREGT_A0CYSTR_COMPU_ER_Msk)  == A0CYREGT_A0CYSTR_COMPU_ER_Msk)\
                || (CH_STATE[Instance] << Channel == TRUE))
        {
            if(Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyRESULT < ADC_UNDERFLOW_CHECK_DATA)
            {
                *Value = ADC_POSITIVE_COMPENDATA_MAX;
            }
            else if(Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyRESULT > ADC_OVERLOW_CHECK_DATA)
            {
                *Value = 0;
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
            }
            TT_ADC->GSTR[Instance] = TT_ADC_GSTR_ERROR0_Msk << Channel;
            if(CH_STATE[Instance] << Channel == TRUE)
            {
                CH_STATE[Instance] &= ~(1U<<Channel);
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
#endif
            *Value = (uint16)(Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyRESULT);
#ifndef A8V2E
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          ADC Enable Hw Trig
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_EnableHwTrig (TT_CONST Adc_Hw_ChannelType ChannelId)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {

        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
        TT_OR_EQUAL_ATOMIC_OPT(&Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR,TT_ADC_AxCyCTRLR_EXTTRGEN_Msk);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR & TT_ADC_AxCyCTRLR_EXTTRGEN_Msk) != TT_ADC_AxCyCTRLR_EXTTRGEN_Msk )
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          ADC Disable Hw Trig
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_DisableHwTrig (TT_CONST Adc_Hw_ChannelType ChannelId)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources * Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
        TT_AND_EQUAL_ATOMIC_OPT(&Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR,(~TT_ADC_AxCyCTRLR_EXTTRGEN_Msk));

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR & TT_ADC_AxCyCTRLR_EXTTRGEN_Msk) != 0 )
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {

    }

    return Ret;
}

/**
 *@brief          ADC set Squence
 *
 *@param[in]      HwUnit - Adc unit Id
 *@param[in]      Queue - Queue data, four bits representing a channel, low transmission first
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetSquence (TT_CONST Adc_Hw_HwUnitType HwUnit,
                              TT_CONST uint32 Queue)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#ifdef A8V2E
    TT_CONST uint32 Queue_Max = 0x88888888U;
#else
    TT_CONST uint32 Queue_Max = 0xDDDDDDDDU;
#endif
    TT_ParaCheck((Queue > Queue_Max),TT_RET_PARAM_LEN_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        TT_ADC->REQSEQ[HwUnit] = Queue;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if(TT_ADC->REQSEQ[HwUnit] != Queue )
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          ADC set cascade trigger
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      NextChannel - Cascade triggered channels
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetCTrigger (TT_CONST Adc_Hw_ChannelType ChannelId,
                               TT_CONST Adc_Hw_CTrigType NextChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources *Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
#ifdef A8V2E
        if(Instance == (uint8)ADC0)
        {
            TT_ParaCheck ((NextChannel > CTRIG_CHANNEL8), TT_RET_PARAM_CHANNEL_ERR, &Ret);
        }
        else
        {
            TT_ParaCheck ((NextChannel > CTRIG_CHANNEL7), TT_RET_PARAM_CHANNEL_ERR, &Ret);
        }
#else
        TT_ParaCheck ((NextChannel > CTRIG_CHANNEL13), TT_RET_PARAM_CHANNEL_ERR, &Ret);
#endif
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR &= ~TT_ADC_AxCyCTRLR_CTRIGGLE_Msk;
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR |= (uint32) NextChannel << TT_ADC_AxCyCTRLR_CTRIGGLE_Pos;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR & TT_ADC_AxCyCTRLR_CTRIGGLE_Msk) \
           != (uint32) NextChannel << TT_ADC_AxCyCTRLR_CTRIGGLE_Pos )
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          ADC set channel priority
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      Pri - channel priority
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetCPriority (TT_CONST Adc_Hw_ChannelType ChannelId,
                                TT_CONST Adc_Hw_PriorityType Pri)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Adc_Hw_Resources *Adc_Ch_Resources = NULL_PTR;
    uint8 Instance = 0;
    uint8 Channel = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck ((Pri > ADC_PRIORITY_BEST_LOW), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
        Channel = Adc_Hw_GetChannel (ChannelId);

        Adc_Ch_Resources = &AdcHw_PubResource[Instance];
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR &= ~TT_ADC_AxCyCTRLR_CPRIO_Msk;
        Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR |= (uint32) Pri << TT_ADC_AxCyCTRLR_CPRIO_Pos;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCTRLR & TT_ADC_AxCyCTRLR_CPRIO_Msk) \
           != (uint32) Pri << TT_ADC_AxCyCTRLR_CPRIO_Pos )
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 *@brief          ADC set DMA enable
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      Enable - DMA enable
 *@param[in]      IntEnable DMA Int enable
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetDmaEn (TT_CONST Adc_Hw_ChannelType ChannelId,
                            TT_CONST boolean Enable,
                            TT_CONST boolean IntEnable)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Instance = 0;

    TT_ParaCheck ((ChannelId > ADC_CH_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck (((Enable != TRUE) && (Enable != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck (((IntEnable != TRUE) && (IntEnable != FALSE)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Instance = Adc_Hw_GetInstance (ChannelId);
#ifdef USING_OS_AUTOSAROS
        /* Enter exclusive area: implementation depends on integrator */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();
#endif
        TT_ADC->CFR[Instance] &= ~(TT_ADC_CFR_DMA_EN_Msk | TT_ADC_CFR_DMA_INT_EN_Msk);
        TT_ADC->CFR[Instance] |= (((uint32)Enable << TT_ADC_CFR_DMA_EN_Pos) | ((uint32)IntEnable << TT_ADC_CFR_DMA_INT_EN_Pos));
#ifdef USING_OS_AUTOSAROS
        /* Exit exclusive area: implementation depends on integrator */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if((TT_ADC->CFR[Instance] & (TT_ADC_CFR_DMA_EN_Msk | TT_ADC_CFR_DMA_INT_EN_Msk)) \
            != (((uint32)Enable << TT_ADC_CFR_DMA_EN_Pos) | ((uint32)IntEnable << TT_ADC_CFR_DMA_INT_EN_Pos)) )
        {
            Ret = TT_RET_OPT_REG_ERR;
        }
        else
        {
            Ret = TT_RET_SUCCESS;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE_SLOW
#include "Adc_MemMap.h"
/**
* @brief        Adc_Hw_InitCheck
* @details      InitCheck For Adc After McuInit
* @param[in]    HwUnit      Adc unit Id
* @param[in]    AGC0_Mask   AGC data
* @param[in]    AxCfr       AxCFR data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Adc_Hw_InitCheck(TT_CONST Adc_Hw_HwUnitType HwUnit,
                            TT_CONST uint32 AGC0_Mask,
                            TT_CONST uint32 AxCfr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if((AGC0_Mask & TT_ADC->AGC0) != AGC0_Mask)
    {
        Ret = TT_RET_OPT_REG_ERR;
    }
    else
    {
        /* do nothing */
    }

    if(Ret == TT_RET_SUCCESS)
    {

        if((AxCfr & TT_ADC->CFR[HwUnit]) != AxCfr)
        {
            Ret = TT_RET_OPT_REG_ERR;
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

    return Ret;
}

/**
* @brief        Adc_Hw_SelfCorrecting
* @details      Software calibrates adc parameters
* @param[in]    HwUnit      Adc unit Id
* @param[in]    PowerMode   Adc VREF power mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/

TT_RetType Adc_Hw_SelfCorrecting(TT_CONST Adc_Hw_HwUnitType HwUnit,
                                 TT_CONST Adc_Hw_PowerModeType PowerMode)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck (((uint8)HwUnit > ADC_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck ((PowerMode > ADC_3V3_MODE), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        uint32 i = 0;
        uint32 chop_value = 0;
        float64 Data_x[7] = {0};
        float64 Data_y[7] = {0};
        TT_CONST uint8 Data_num = 7;
        TT_CONST uint32 SelfTest_Sel = 256;
        uint32 offset = 0;
        uint32 fullvolt = 0;
        float64 Vref_Adc = 0.0f;
        float64 AdcDataCode = 0.0f;
        float64 AdcTemp = 0.0f;
        Adc_Hw_LineEquation Adc_K_B = {0};

        if(PowerMode == ADC_5V_MODE)
        {
            Vref_Adc = 5.0f;
        }
        else
        {
            Vref_Adc = 3.3f;
        }
        AdcDataCode = (float64)ADC_Data_MAX / Vref_Adc;

        for(i = 0; i < Data_num; i++)
        {
            Data_x[i] = ((((float64)i + (float64)1) * (float64)32) * Vref_Adc) / (float64)SelfTest_Sel;
            TT_ADC->ADC_TEST = ((uint32)0x100 | ((i+1) * 32U));
#ifdef A8V2E
            TT_ADC->DAC_CHOP |= TT_ADC_DAC_CHOP_DAC_CHOP_Msk;
#endif
            (void)Base_Drv_Usdelay(5);

            TT_ADC->AGC0 = (uint32)9U << TT_ADC_AGC0_DIV_Pos |\
                            TT_ADC_AGC0_FTSAMP_Msk |\
                            TT_ADC_AGC0_STSAMP_Msk;

            TT_ADC->CFR[HwUnit] |= (uint32)TT_ADC_CFR_EN_Msk;

            TT_ADC->AXCHREGT[HwUnit].AXCYREGT[2].AxCyCFR |= ((0x5UL << A0CYREGT_A0CYCFR_SAMPNUM_Pos) | \
                                                             (0x5UL << A0CYREGT_A0CYCFR_SHIFT_Pos));
#ifdef A8V2E
            for(chop_value = 0; chop_value < 2; chop_value++)
            {
                if(chop_value != 0)
                {
                    TT_ADC->DAC_CHOP = 0;
                    (void)Base_Drv_Usdelay(2);
                }
                else
                {
                    /* do nothing */
                }
#endif
                TT_ADC->ADCTEST[HwUnit] = (uint32)((0x2UL << TT_ADC_ADCTEST_TESTCHSEL_Pos) | TT_ADC_ADCTEST_TESTREQ_Msk);

                Ret = Adc_Hw_PriSampValue( HwUnit, Data_y, chop_value, i);

                if((TT_ADC->GSTR[HwUnit] & TT_ADC_GSTR_ERROR2_Msk) == TT_ADC_GSTR_ERROR2_Msk)
                {
                    Ret = TT_RET_STATUS_ERR;
                    break;
                }
                else
                {
                    /* do nothing */
                }
#ifdef A8V2E
            }
#endif
        }

        TT_ADC->ADCTEST[HwUnit] = 0;
        TT_ADC->ADC_TEST = 0;
        TT_ADC->AXCHREGT[HwUnit].AXCYREGT[2].AxCyCFR = 0;
        TT_ADC->ADC_TEST = 0;
        TT_ADC->AGC0 = 0;

        if(Ret == TT_RET_SUCCESS)
        {
            Adc_Hw_PriCalLineEquation(Data_x,Data_y,Data_num,&Adc_K_B);
            AdcTemp = ((float64)AdcDataCode / Adc_K_B.fk) * (float64)ADC_TRIM_MULTIPLE;
            fullvolt = (uint32)round(AdcTemp) | TT_ADC_FULLVOLT_FULL_VOLT_LOCK_Msk;
            TT_ADC->FULLVOLT[HwUnit] = fullvolt;
            if(Adc_K_B.fB < 0.0)
            {
                offset = (uint32)((uint32)round(-Adc_K_B.fB) \
                                           | TT_ADC_OFFSET_OFFSET_LOCK_Msk);
            }
            else
            {
                offset = (uint32)round(Adc_K_B.fB) | 1UL << ADC_OFFSET_POS \
                                   | TT_ADC_OFFSET_OFFSET_LOCK_Msk;
            }
            AXOFFSET[HwUnit] = offset;

            Adc_Hw_PriRegReadBack(AXOFFSET[HwUnit], offset, &Ret);
            Adc_Hw_PriRegReadBack(TT_ADC->FULLVOLT[HwUnit], fullvolt, &Ret);
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
    return Ret;
}

#define ADC_STOP_SEC_CODE_SLOW
#include "Adc_MemMap.h"
/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/**
 *@brief          The linear equation is fitted according to the input data
 *
 *@param[in]      fVolt - volt input
 *@param[in]      nAdcCap - adc code
 *@param[in]      nElement - n Element
 *@param[out]     pLE - Calculate the y = kx + b
 *@return         void
 */
static void Adc_Hw_PriCalLineEquation(float64* fVolt,
                                      float64* nAdcCap,
                                      uint8 nElement,
                                      Adc_Hw_LineEquation* pLE)
{
    float64 fAvgVolt = 0.0f;
    float64 fAvgAdcCap = 0.0f;
    float64 fSumVolt = 0.0f;
    float64 fSumAdcCap = 0.0f;
    uint8 i = 0;

    for (i = 0; i < nElement; i++)
    {
        fAvgVolt += fVolt[i];
        fAvgAdcCap += nAdcCap[i];
    }

    fAvgVolt = fAvgVolt / (float64)nElement;
    fAvgAdcCap = fAvgAdcCap / (float64)nElement;

    for (i = 0; i < nElement; i++)
    {
        fSumVolt += (fVolt[i] - fAvgVolt) * (nAdcCap[i] - fAvgAdcCap);
        fSumAdcCap += (fVolt[i] - fAvgVolt) * (fVolt[i] - fAvgVolt);
    }

    pLE->fk = fSumVolt / fSumAdcCap;
    pLE->fB = fAvgAdcCap - pLE->fk * fAvgVolt;

}

static TT_RetType Adc_Hw_PriSampValue(TT_CONST Adc_Hw_HwUnitType HwUnit,
                                            float64* Data_y,
                                            uint32 chop_value,
                                            uint32 i)
{
    TT_RetType Ret = TT_RET_STATUS_TIMEOUT_ERR;
    uint32 Time_Out = 0;
    TT_CONST uint32 TimeOut_Data = 40960;
#ifdef A8V2E
    float64 Data_z = 0.0;
#endif
    for(Time_Out = 0; Time_Out < TimeOut_Data; Time_Out++)
    {
        if((TT_ADC->GSTR[HwUnit] & TT_ADC_GSTR_READY2_Msk)  == TT_ADC_GSTR_READY2_Msk)
        {
#ifdef A8V2E
            Data_z = (float64)(TT_ADC->AXCHREGT[HwUnit].AXCYREGT[2].AxCyRESULT);
            if(chop_value == 0)
            {
                Data_y[i] = Data_z;
            }
            else
            {
                Data_y[i] = (Data_y[i] + Data_z)/(float64)2;
            }
#else
            Data_y[i] = (float64)(TT_ADC->AXCHREGT[HwUnit].AXCYREGT[2].AxCyRESULT);
            (void)chop_value;
#endif
            Ret = TT_RET_SUCCESS;
            break;
        }
        else
        {
            /* do nothing */
        }
    }
    return Ret;
}
static TT_RetType Adc_Hw_PriFir (TT_CONST Adc_Hw_CommonConfigType *Config)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST uint8 Filter_data = 25;
    uint32 ADCFIR_data = 0;
    uint8 i = 0;

    if (TT_FLD2BOOL(TT_ADC_ADCFIR_FIR_WP,TT_ADC->ADCFIR[0]) == FALSE)
    {
        for (i = 0; i < Filter_data; i++)
        {
            if (Config->Filter->filters[i] < 0)
            {
                ADCFIR_data |= (uint32) (-Config->Filter->filters[i]) | 0x10000UL;
            }
            else
            {
                ADCFIR_data |= (uint32) Config->Filter->filters[i];
            }
            TT_ADC->ADCFIR[i] = ADCFIR_data;
            Adc_Hw_PriRegReadBack(TT_ADC->ADCFIR[i], ADCFIR_data, &Ret);
        }

        TT_ADC->ADCFIR[0] |= (Config->Filter->Fir_Wp ? TT_ADC_ADCFIR_FIR_WP_Msk : 0);
    }
    else
    {
        Ret = TT_RET_STATUS_LOCKED_ERR;
    }
    return Ret;
}

LOCAL_INLINE void Adc_Hw_PriRegReadBack (uint32 ActualValue, uint32 TargetValue, TT_RetType *Ret)
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
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifndef USING_OS_AUTOSAROS

#define ADC_START_SEC_CODE_FAST
#include "Adc_MemMap.h"
/**
*@brief          ADC IRQ handler
*
*@param[in]      HwUnit - Adc unit Id
*@return         void
*@retval         NON
*@retval         NON
*/
static void Adc_Hw_PriHandlerFunction(Adc_Hw_HwUnitType HwUnit)
{
    TT_CONST Adc_Hw_Resources* TT_CONST Adc_Ch_Resources = &AdcHw_PubResource[HwUnit];
    uint32 Clear_State = 0;
    uint32 Ch_State = 0;
    uint32 CFR_State = 0;
    uint32 GSTR_State = 0;
    uint8 Channel = 0;
    uint8 LogicalHwUnit = 0;
    uint32 event = 0;

    for(LogicalHwUnit = 0; LogicalHwUnit < ADC_MAX_UNITS; LogicalHwUnit++)
    {
        if(HwUnit == AdcHw_PubConfigSet[LogicalHwUnit].AdcHwUnitId)
        {
            break;
        }
        else
        {
            /* do nothing */
        }
    }

    GSTR_State = TT_ADC->GSTR[HwUnit];

    if ((GSTR_State & TT_ADC_GSTR_DMA_READY_Msk) != 0U)
    {
        Clear_State |= 0xFFFFFFFFU;
        Adc_Hw_IrqAdcxClearState((uint32)HwUnit,Clear_State);
        if(AdcHw_PubConfigSet[LogicalHwUnit].Event != NULL_PTR)
        {
            AdcHw_PubConfigSet[LogicalHwUnit].Event(ADC_CHANNEL_NUM,TT_ADC_CB_EVENT_DMA_READAY);
        }
    }
    else if ((GSTR_State & ~TT_ADC_GSTR_DMA_READY_Msk) != 0U)
    {
        for (Channel = 0; Channel < ADC_CHANNEL_NUM; Channel++)
        {
            CFR_State = Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCyCFR;
            Ch_State = Adc_Ch_Resources->Reg->AXCYREGT[Channel].AxCySTR;
 #ifdef A8V2E
            if((((GSTR_State & ((ADC_FLAG_READY_CHANNEL_0 << Channel) | (ADC_FLAG_ERROR_CHANNEL_0 << Channel))) != 0) \
                && ((boolean)((CFR_State & TT_ADC_AxCyCFR_READYINTEN_Msk)>>TT_ADC_AxCyCFR_READYINTEN_Pos))) \
                || ((boolean)((CFR_State & TT_ADC_AxCyCFR_HCOMPINTEN_Msk)>>TT_ADC_AxCyCFR_HCOMPINTEN_Pos) && (boolean)((Ch_State & TT_ADC_AxCySTR_DATAH_Msk)>>TT_ADC_AxCySTR_DATAH_Pos))\
                || ((boolean)((CFR_State & TT_ADC_AxCyCFR_LCOMPINTEN_Msk)>>TT_ADC_AxCyCFR_LCOMPINTEN_Pos) && (boolean)((Ch_State & TT_ADC_AxCySTR_DATAL_Msk)>>TT_ADC_AxCySTR_DATAL_Pos))\
                || ((boolean)((CFR_State & TT_ADC_AxCyCFR_TIMEOUTINTEN_Msk)>>TT_ADC_AxCyCFR_TIMEOUTINTEN_Pos) && (boolean)((Ch_State & TT_ADC_AxCySTR_TIMEOUT_ER_Msk)>>TT_ADC_AxCySTR_TIMEOUT_ER_Pos))\
                || ((boolean)((CFR_State & TT_ADC_AxCyCFR_COMPINTEN_Msk)>>TT_ADC_AxCyCFR_COMPINTEN_Pos) && (boolean)((Ch_State & TT_ADC_AxCySTR_COMPU_ER_Msk)>>TT_ADC_AxCySTR_COMPU_ER_Pos)))
#else
            if((Ch_State & A0CYREGT_A0CYSTR_COMPU_ER_Msk) == A0CYREGT_A0CYSTR_COMPU_ER_Msk)
            {
                CH_STATE[HwUnit] |= 1 << Channel;
            }
            else
            {
                /* do nothing */
            }
            if((((boolean)(GSTR_State & ((ADC_FLAG_READY_CHANNEL_0 << Channel) | (ADC_FLAG_ERROR_CHANNEL_0 << Channel)))) \
                && ((boolean)(CFR_State & TT_ADC_AxCyCFR_READYINTEN_Msk))) \
                || ((boolean)(CFR_State & TT_ADC_AxCyCFR_HCOMPINTEN_Msk) && (boolean)(Ch_State & TT_ADC_AxCySTR_DATAH_Msk))\
                || ((boolean)(CFR_State & TT_ADC_AxCyCFR_LCOMPINTEN_Msk) && (boolean)(Ch_State & TT_ADC_AxCySTR_DATAL_Msk)))
#endif
            {
                Clear_State |= (uint32)(ADC_FLAG_READY_CHANNEL_0 | ADC_FLAG_ERROR_CHANNEL_0) << Channel;
                event = 0;

                if((Ch_State & TT_ADC_AxCySTR_READY_Msk) != 0U)
                {
                    event |= TT_ADC_CB_EVENT_DATA_REDAY;
                }
                else
                {
                    /* do nothing */
                }

                if((Ch_State & TT_ADC_AxCySTR_DATAH_Msk) != 0U)
                {
                    event |= TT_ADC_CB_EVENT_THHOLD_HIGHT;
                }
                else
                {
                    /* do nothing */
                }

                if((Ch_State & TT_ADC_AxCySTR_DATAL_Msk) != 0U)
                {
                    event |= TT_ADC_CB_EVENT_THHOLD_LOW;
                }
                else
                {
                    /* do nothing */
                }

                if((Ch_State & TT_ADC_AxCySTR_DMA_RESPER_Msk) != 0U)
                {
                    event |= TT_ADC_CB_EVENT_DMA_RESPER;
                }
                else
                {
                    /* do nothing */
                }

                if((Ch_State & TT_ADC_AxCySTR_COMPU_ER_Msk) != 0U)
                {
                    event |= TT_ADC_CB_EVENT_COMP_ERROR;
                }
                else
                {
                    /* do nothing */
                }
#ifdef A8V2E
                if((Ch_State & TT_ADC_AxCySTR_TIMEOUT_ER_Msk) != 0U)
                {
                    event |= TT_ADC_CB_EVENT_TIMEOUT_ERROR;
                }
                else
                {
                    /* do nothing */
                }
#endif
                TT_ADC->GSTR[HwUnit] = ADC_FLAG_READY_CHANNEL_0 << Channel;

                if((0 != event) && (AdcHw_PubConfigSet[LogicalHwUnit].Event != NULL_PTR))
                {
                    AdcHw_PubConfigSet[LogicalHwUnit].Event(Channel, event);
                }
            }

            if((GSTR_State & (ADC_FLAG_ERROR_CHANNEL_0 << Channel)) != 0)
            {
                Clear_State |= (uint32)(ADC_FLAG_READY_CHANNEL_0 | ADC_FLAG_ERROR_CHANNEL_0) << Channel;
            }
        }
    }
    else
    {
        /* do nothing */
    }

    Adc_Hw_IrqAdcxClearState((uint32)HwUnit,Clear_State);

}

/**
*@brief          ADC0 IRQ handler
*
*@param[in]      HwUnit - Adc unit Id
*@return         void
*@retval         NON
*@retval         NON
*/
ISR(ADC0_IRQHandler)
{
    Adc_Hw_PriHandlerFunction(ADC0);
}

/**
*@brief          ADC1 IRQ handler
*
*@param[in]      HwUnit - Adc unit Id
*@return         void
*@retval         NON
*@retval         NON
*/
ISR(ADC1_IRQHandler)
{
    Adc_Hw_PriHandlerFunction(ADC1);
}

/**
*@brief          ADC2 IRQ handler
*
*@param[in]      HwUnit - Adc unit Id
*@return         void
*@retval         NON
*@retval         NON
*/
ISR(ADC2_IRQHandler)
{
    Adc_Hw_PriHandlerFunction(ADC2);
}

/**
*@brief          ADC3 IRQ handler
*
*@param[in]      HwUnit - Adc unit Id
*@return         void
*@retval         NON
*@retval         NON
*/
ISR(ADC3_IRQHandler)
{
    Adc_Hw_PriHandlerFunction(ADC3);
}

/**
*@brief          ADC4 IRQ handler
*
*@param[in]      HwUnit - Adc unit Id
*@return         void
*@retval         NON
*@retval         NON
*/
ISR(ADC4_IRQHandler)
{
    Adc_Hw_PriHandlerFunction(ADC4);
}

/**
*@brief          ADC5 IRQ handler
*
*@param[in]      HwUnit - Adc unit Id
*@return         void
*@retval         NON
*@retval         NON
*/
ISR(ADC5_IRQHandler)
{
    Adc_Hw_PriHandlerFunction(ADC5);
}

#define ADC_STOP_SEC_CODE_FAST
#include "Adc_MemMap.h"

#endif

#ifdef __cplusplus
}
#endif
