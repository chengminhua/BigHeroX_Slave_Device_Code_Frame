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
**  FILENAME     : Gtm_Hw_Cmu.c                                               **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Gtm Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                              **
**                                                                            **
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                              Include Files
 ******************************************************************************/
#include "Gtm_Hw_Cmu.h"
#include "Mcu_Drv.h"
#include "math.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Gtm.h"
#endif

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define GTM_HW_CMU_VENDOR_ID_C                      1541
#define GTM_HW_CMU_MODULE_ID_C                      221
#define GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_C       4
#define GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_C       4
#define GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_C       0
#define GTM_HW_CMU_SW_MAJOR_VERSION_C               1
#define GTM_HW_CMU_SW_MINOR_VERSION_C               1
#define GTM_HW_CMU_SW_PATCH_VERSION_C               0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Gtm_Hw_Cmu.c Gtm_Hw_Cmu.h file version check */
#if (GTM_HW_CMU_VENDOR_ID_C != GTM_HW_CMU_VENDOR_ID_H)
    #error "Gtm_Hw_Cmu.c and Gtm_Hw_Cmu.h have different vendor ids"
#endif
#if (GTM_HW_CMU_MODULE_ID_C != GTM_HW_CMU_MODULE_ID_H)
    #error "Gtm_Hw_Cmu.c and Gtm_Hw_Cmu.h have different module ids"
#endif
#if ((GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_C != GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_H) || \
      (GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_C != GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_H) || \
      (GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_C != GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Cmu.c and Gtm_Hw_Cmu.h are different"
#endif
#if ((GTM_HW_CMU_SW_MAJOR_VERSION_C != GTM_HW_CMU_SW_MAJOR_VERSION_H) || \
      (GTM_HW_CMU_SW_MINOR_VERSION_C != GTM_HW_CMU_SW_MINOR_VERSION_H) || \
      (GTM_HW_CMU_SW_PATCH_VERSION_C != GTM_HW_CMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Cmu.c and Gtm_Hw_Cmu.h are different"
#endif

/* Gtm_Hw_Cmu.c Mcu_Drv.h file version check */
#if (GTM_HW_CMU_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Gtm_Hw_Cmu.c and Mcu_Drv.h have different vendor ids"
#endif
#if ((GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Cmu.c and Mcu_Drv.h are different"
#endif
#if ((GTM_HW_CMU_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (GTM_HW_CMU_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (GTM_HW_CMU_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Cmu.c and Mcu_Drv.h are different"
#endif

#ifdef USING_OS_AUTOSAROS
/* Gtm_Hw_Cmu.c SchM_Gtm.h file version check */
#if (GTM_HW_CMU_VENDOR_ID_C != SCHM_GTM_VENDOR_ID_H)
    #error "Gtm_Hw_Cmu.c and SchM_Gtm.h have different vendor ids"
#endif
#if ((GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_C != SCHM_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_C != SCHM_GTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_C != SCHM_GTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Cmu.c and SchM_Gtm.h are different"
#endif
#if ((GTM_HW_CMU_SW_MAJOR_VERSION_C != SCHM_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_HW_CMU_SW_MINOR_VERSION_C != SCHM_GTM_SW_MINOR_VERSION_H) || \
     (GTM_HW_CMU_SW_PATCH_VERSION_C != SCHM_GTM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Cmu.c and SchM_Gtm.h are different"
#endif
#endif
/******************************************************************************
 *                       Global Variables Declaration
 ******************************************************************************/

/******************************************************************************
 *                       Private Variables
 ******************************************************************************/

/******************************************************************************
 *                       Private Function Declaration
 ******************************************************************************/
/**
* @brief        Gtm_Hw_Cmu_PriGetClusterClk
* @details      Get cluster clock.
* @param[in]    ClusterIndex : Index of the cluster instance
* @param[out]   Freq         : Gets parameters for clock data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetClusterClk(ClusterClockType ClusterIndex, float64 *Freq);

/**
* @brief        Gtm_Hw_Cmu_PriGetClk
* @details      This function use to get cmu global clock.
* @param[in]    None
* @param[out]   Clk  : Gets parameters for clock data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetClk(float64 *Clk);

/**
* @brief        Gtm_Hw_Cmu_PriGetExternalClock
* @details      Get cmu external clock.
* @param[in]    ExIndex : Index of the cluster instance.
* @param[out]   Clk     : Gets parameters for clock data.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetExternalClock(uint8 ExIndex,
                                                 float64 *Clk);

/**
* @brief        Gtm_Hw_Cmu_PriGetCfguClock
* @details      This function use to get cmu cfgu clock.
* @param[in]    CmuClk : Cmu clock type.
* @param[out]   Clk    : Gets parameters for clock data.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetCfguClock(CmuClkType CmuClk,
                                             float64 *Clk);

/**
* @brief        Gtm_Hw_Cmu_PriGetFixedClock
* @details      This function use to get cmu fixed clock.
* @param[in]    FxClk : Fix clock type.
* @param[out]   Clk   : Gets parameters for clock data.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetFixedClock(uint8 FxClk,
                                              float64 *Clk);

/**
* @brief        Gtm_Hw_Cmu_PriSetClusterClk
* @details      This function use to set cluster clock.
* @param[in]    ClockFreqOrDiv : Frequency division coefficient
* @param[in]    ClusterIndex   : Cluster clock type.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriSetClusterClk(uint32 ClockFreqOrDiv,
                                              uint8 ClusterIndex);

/**
* @brief        Gtm_Hw_Cmu_PriSetGclk
* @details      This function use to set global clock.
* @param[in]    frequency:     Target frequency.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriSetGclk(uint32 frequency);

/**
* @brief        Gtm_Hw_Cmu_PriSetExternalClock
* @details      This function use to set external clock.
* @param[in]    ex_index  : External clock index.
* @param[in]    frequency : Target frequency.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriSetExternalClock(uint8 ex_index,
                                                 uint32 frequency);

/**
* @brief        Gtm_Hw_Cmu_PriSetCfguClock
* @details      This function use to set cfgu clock.
* @param[in]    clkIndex  : Clock index
* @param[in]    frequency : Target frequency.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriSetCfguClock(CmuClkType clkIndex,
                                             uint32 frequency);

/**
* @brief        Gtm_Hw_Cmu_PriCalcCfguClkDiv
* @details      Calculate the frequency division value of the cfg clock according to the frequency to be set.
* @param[in]    frequency : Target frequency.
* @param[out]   cnt       : Save the division
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriCalcCfguClkDiv(uint32 frequency,
                                               uint32 *cnt);

/**
* @brief        Gtm_Hw_Cmu_PriSetCfguClock
* @details      Calculate the best numerator and denominator coefficients.
* @param[in]    source : clock source.
* @param[in]    aim    : Target clock.
* @param[out]   nBest  : Optimum molecular coefficient.
* @param[out]   zBest  : Best denominator coefficient.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Cmu_PriCalcBestNZ(float64 source,
                                           float64 aim,
                                           uint32 *nBest,
                                           uint32 *zBest);

/**
* @brief        Gtm_Hw_PriArchInit
* @details      GTM Arch initialization.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_PriArchInit(void);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Hw_Cmu_PriInitCheck
* @details      Cmu initialization check.
* @param[in]    CmuConfig:  Cmu Configuration pointer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriInitCheck(TT_CONST Cmu_ConfigType *CmuConfig);
#endif
/******************************************************************************
 *                       Public Functions
 ******************************************************************************/
#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

/**
* @brief        Gtm_Hw_Arch_Cmu_Init
* @details      Initialize the GTM architecture and CMU submodules.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Arch_Cmu_Init(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Initialize the Gtm architecture */
    Gtm_Hw_PriArchInit();

    /* Disable all Clock - all internal clock counters will be reset */
    TT_GTM->CMU.CLK_EN.R = 0x00555555;

    /* config cluster clk div */
    TT_GTM->CTRL.B.RF_PROT = 0;
    TT_GTM->CLS_CLK_CFG.B.CLS0_CLK_DIV = GTM_CLS0_CLK_DIV;
    TT_GTM->CLS_CLK_CFG.B.CLS1_CLK_DIV = GTM_CLS1_CLK_DIV;
    TT_GTM->CLS_CLK_CFG.B.CLS2_CLK_DIV = GTM_CLS2_CLK_DIV;
    TT_GTM->CLS_CLK_CFG.B.CLS3_CLK_DIV = GTM_CLS3_CLK_DIV;
    TT_GTM->CTRL.B.RF_PROT = 1;

#if (GTM_CLS0_CLK_DIV != 0)
    TT_GTM->CMU.GCLK_NUM.B.GCLK_NUM = CMU_GCLK_NUM;
    TT_GTM->CMU.GCLK_NUM.B.GCLK_NUM = CMU_GCLK_NUM;
    TT_GTM->CMU.GCLK_DEN.B.GCLK_DEN = CMU_GCLK_DEN;
    /*  Configure EGU subunit (External Clock Generation Unit) */
#if(CMU_EGU_EN_ECLK0 == TRUE)
    TT_GTM->CMU.ECLK_0_NUM.B.ECLK_NUM = CMU_EGU_ECLK0_NUM;
    TT_GTM->CMU.ECLK_0_DEN.B.ECLK_DEN = CMU_EGU_ECLK0_DEN;
#endif

#if(CMU_EGU_EN_ECLK1 == TRUE)
    TT_GTM->CMU.ECLK_1_NUM.B.ECLK_NUM = CMU_EGU_ECLK1_NUM;
    TT_GTM->CMU.ECLK_1_DEN.B.ECLK_DEN = CMU_EGU_ECLK1_DEN;
#endif

#if(CMU_EGU_EN_ECLK2 == TRUE)
    TT_GTM->CMU.ECLK_2_NUM.B.ECLK_NUM = CMU_EGU_ECLK2_NUM;
    TT_GTM->CMU.ECLK_2_DEN.B.ECLK_DEN = CMU_EGU_ECLK2_DEN;
#endif

    /*Configure the FXU (Fixed Clock  Generation) subunit */
#if(CMU_FXCLK_ENABLE == TRUE)
    TT_GTM->CMU.FXCLK_CTRL.B.FXCLK_SEL = (uint8)(CMU_FXCLK_SEL);
#endif

    /* Configure the CFGU (Configurable Clock  Generation) subunit */
#if(CMU_CFGU_EN_CLK0 == TRUE) && (CMU_CFGU_CLK_DIV0 > 0)
    TT_GTM->CMU.CLK_0_CTRL.R = (CMU_CFGU_CLK_DIV0 - 1U);
#endif

#if(CMU_CFGU_EN_CLK1 == TRUE) && (CMU_CFGU_CLK_DIV1 > 0)
    TT_GTM->CMU.CLK_1_CTRL.R = (CMU_CFGU_CLK_DIV1 - 1U);
#endif

#if(CMU_CFGU_EN_CLK2 == TRUE) && (CMU_CFGU_CLK_DIV2 > 0)
    TT_GTM->CMU.CLK_2_CTRL.R = (CMU_CFGU_CLK_DIV2 - 1U);
#endif

#if(CMU_CFGU_EN_CLK3 == TRUE) && (CMU_CFGU_CLK_DIV3 > 0)
    TT_GTM->CMU.CLK_3_CTRL.R = (CMU_CFGU_CLK_DIV3 - 1U);
#endif

#if(CMU_CFGU_EN_CLK4 == TRUE) && (CMU_CFGU_CLK_DIV4 > 0)
    TT_GTM->CMU.CLK_4_CTRL.R = (CMU_CFGU_CLK_DIV4 - 1U);
#endif

#if(CMU_CFGU_EN_CLK5 == TRUE) && (CMU_CFGU_CLK_DIV5 > 0)
    TT_GTM->CMU.CLK_5_CTRL.R = (CMU_CFGU_CLK_DIV5 - 1U);
#endif

#if((CMU_CFGU_EN_CLK6 == TRUE) && (CMU_CFGU_CLK_DIV6 > 0) || \
(CMU_CFGU_EN_CLK7 == TRUE) && (CMU_CFGU_CLK_DIV7 > 0))
    uint32 TmpValue = 0;
#endif

#if(CMU_CFGU_EN_CLK6 == TRUE) && (CMU_CFGU_CLK_DIV6 > 0)
    TmpValue = CMU_CFGU_CLK_DIV6 - 1U;
    TmpValue |= ((uint32)CMU_CFGU_CLK6_SEL) << 24;
    TT_GTM->CMU.CLK_6_CTRL.R = TmpValue;
#endif

#if(CMU_CFGU_EN_CLK7 == TRUE) && (CMU_CFGU_CLK_DIV7 > 0)
    TmpValue = CMU_CFGU_CLK_DIV7 - 1U;
    TmpValue |= ((uint32)CMU_CFGU_CLK7_SEL) << 24;
    TT_GTM->CMU.CLK_7_CTRL.R = TmpValue;
#endif
#endif

    /* Set the monitoring clock and clock frequency division */
#if(GTM_MONITOR_CLS0_EN == STD_ON)
    GTM_WRAPPER->CMU[0].R = 0x10UL | GTM_MONITOR_CLS0_DIV;
#endif
#if(GTM_MONITOR_CLS1_EN == STD_ON)
    GTM_WRAPPER->CMU[1].R = 0x10UL | GTM_MONITOR_CLS1_DIV;
#endif
#if(GTM_MONITOR_CLS2_EN == STD_ON)
    GTM_WRAPPER->CMU[2].R = 0x10UL | GTM_MONITOR_CLS2_DIV;
#endif
#if(GTM_MONITOR_CLS3_EN == STD_ON)
    GTM_WRAPPER->CMU[3].R = 0x10UL | GTM_MONITOR_CLS3_DIV;
#endif

    /* Set the TIM channel input source */
    GTM_WRAPPER->TIMSEL.B.TIM0_SEL = GTM_TIM0CH0_INPUT_SEL;
    GTM_WRAPPER->TIMSEL.B.TIM1_SEL = GTM_TIM0CH1_INPUT_SEL;
    GTM_WRAPPER->TIMSEL.B.TIM2_SEL = GTM_TIM0CH2_INPUT_SEL;
    GTM_WRAPPER->TIMSEL.B.TIM3_SEL = GTM_TIM0CH3_INPUT_SEL;
    GTM_WRAPPER->TIMSEL.B.TIM4_SEL = GTM_TIM0CH4_INPUT_SEL;
    GTM_WRAPPER->TIMSEL.B.TIM5_SEL = GTM_TIM0CH5_INPUT_SEL;
    GTM_WRAPPER->TIMSEL.B.TIM6_SEL = GTM_TIM0CH6_INPUT_SEL;
    GTM_WRAPPER->TIMSEL.B.TIM7_SEL = GTM_TIM0CH7_INPUT_SEL;

    /* Set the OSC clock input frequency division */
    GTM_WRAPPER->OSCDIV.B.DIV = (uint8)GTM_MONITOR_OSC_DIV;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    Ret = Gtm_Hw_Cmu_PriInitCheck(NULL_PTR);
#else
    (void)Ret;
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_DeInit
* @details      Deinitialization the Cmu sub module.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_DeInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    GTM.CTRL.B.RF_PROT = 0;
    GTM.RST.B.RST = 1;
    MCAL_DATA_SYNC_BARRIER();

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    /* An IP reset resets all CMU clocks */
    GTM_REG_CHECK(TT_GTM->CMU.CLK_EN.R, 0);
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_Start
* @details      Start all configured clocks.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_Start(void)
{
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    uint32 i = 0;
    uint32 ClkEnRead = 0;
#endif
    TT_RetType Ret = TT_RET_SUCCESS;

#if (GTM_CLS0_CLK_DIV != 0)
    /* Enable All selected Clocks */
    TT_GTM->CMU.CLK_EN.R = CMU_CLK_EN;
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    for(i = 0; i < 32; i += 2)
    {
        if(!!((((uint32)CMU_CLK_EN & ((uint32)0x3U << i )) >> i) == (uint32)0x2U))
        {
            ClkEnRead |= ((uint32)0x3 << i);
        }
    }
    GTM_REG_CHECK(TT_GTM->CMU.CLK_EN.R, ClkEnRead);
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_Stop
* @details      Stop all cmu clocks.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_Stop(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* disable All selected Clocks */
    TT_GTM->CMU.CLK_EN.R = 0x00555555;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    GTM_REG_CHECK(TT_GTM->CMU.CLK_EN.R, 0);
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_GetClock
* @details      Return a Clock Frequency
* @param[in]    ClockSource : GTM CMU clock source type (cluster cfgu, fixed and external clock subunit)
* @param[in]    ClockIndex  : GTM CMU clock index (index of the subunit clock)
* @param[out]   Value       : Save the read clock frequency
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_GetClock(CmuClkSourceType ClockSource,
                               uint8 ClockIndex,
                               float64 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    float64 clockValue = 0.0f;

    /*Judge whether the parameter is legal*/
    TT_ParaCheck(Gtm_Hw_Cmu_PriIsIndexValid(ClockSource, ClockIndex) != TRUE, TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /*Get different types of clocks according to subscripts*/
        switch(ClockSource)
        {
            case GTM_CLUSTER_CLK: /*Get cluster clock*/
                Ret = Gtm_Hw_Cmu_PriGetClusterClk((ClusterClockType)ClockIndex, &clockValue);
                break;
            case CMU_GLOBAL_CLK: /*Get global clock*/
                Ret = Gtm_Hw_Cmu_PriGetClk(&clockValue);
                break;
            case CMU_CFGU_CLK: /*Get cfgu clock*/
                Ret = Gtm_Hw_Cmu_PriGetCfguClock((CmuClkType)ClockIndex, &clockValue);
                break;
            case CMU_FXU_CLK: /*Get fixed clock*/
                Ret = Gtm_Hw_Cmu_PriGetFixedClock(ClockIndex, &clockValue);
                break;
            case CMU_EGU_CLK: /*Get external clock*/
                Ret = Gtm_Hw_Cmu_PriGetExternalClock(ClockIndex, &clockValue);
                break;
            default:
                clockValue = 0.0f;
                break;
        }
    }
    else
    {
        /* do nothing */
    }

    *Value = clockValue;

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_SetClock
* @details      Set the clock frequency of the specified clock source
* @param[in]    ClockSource    : GTM CMU clock source type (cluster cfgu, fixed and external clock subunit)
* @param[in]    ClockIndex     : GTM CMU clock index (index of the subunit clock)
* @param[in]    ClockFreqOrDiv : Clock frequency of the clock source to be set
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_SetClock(CmuClkSourceType ClockSource,
                               uint8 ClockIndex,
                               uint32 ClockFreqOrDiv)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    
    TT_ParaCheck(((ClockFreqOrDiv > CMU_CLS_CLK_MAX_FRQ)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck(Gtm_Hw_Cmu_PriIsIndexValid(ClockSource, ClockIndex) != TRUE, TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        /* Set different types of clocks according to subscripts */
        switch(ClockSource)
        {
            case GTM_CLUSTER_CLK: /*Set cluster clock*/
                Ret = Gtm_Hw_Cmu_PriSetClusterClk(ClockFreqOrDiv, ClockIndex);
                break;
            case CMU_GLOBAL_CLK: /*Set global clock*/
                Ret = Gtm_Hw_Cmu_PriSetGclk(ClockFreqOrDiv);
                break;
            case CMU_CFGU_CLK: /*Set cfgu clock*/
                Ret = Gtm_Hw_Cmu_PriSetCfguClock((CmuClkType)ClockIndex, ClockFreqOrDiv);
                break;
            case CMU_EGU_CLK: /*Set external clock*/
                Ret = Gtm_Hw_Cmu_PriSetExternalClock(ClockIndex, ClockFreqOrDiv);
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

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_SetClockMonitor
* @details      Set a Clock Monitor.
* @param[in]    ClsIndex : GTM monitor cluster clock source type (0-3)
* @param[in]    ClockDiv : GTM monitor cluster clock Div
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_SetClsClockMonitor(ClusterClockType ClsIndex, uint8 ClockDiv)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((ClockDiv > CMU_CLS_CLK_MAX_DIV), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck((ClsIndex > GTM_CLUSTER_CLK_3), TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        switch(ClsIndex)
        {
            case GTM_CLUSTER_CLK_0:
                GTM_WRAPPER->CMU[0].R = 0x10UL | ClockDiv;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(GTM_WRAPPER->CMU[0].R, 0x10UL | ClockDiv);
#endif
                break;
            case GTM_CLUSTER_CLK_1:
                GTM_WRAPPER->CMU[1].R = 0x10UL | ClockDiv;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(GTM_WRAPPER->CMU[1].R, 0x10UL | ClockDiv);
#endif
                break;
            case GTM_CLUSTER_CLK_2:
                GTM_WRAPPER->CMU[2].R = 0x10UL | ClockDiv;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(GTM_WRAPPER->CMU[2].R, 0x10UL | ClockDiv);
#endif
                break;
            case GTM_CLUSTER_CLK_3:
                GTM_WRAPPER->CMU[3].R = 0x10UL | ClockDiv;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(GTM_WRAPPER->CMU[3].R, 0x10UL | ClockDiv);
#endif
                break;
            default:
                Ret = TT_RET_PARAM_INDEX_ERR;
                break;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *                       Private Function
 ******************************************************************************/
/**
* @brief        Gtm_Hw_Cmu_PriGetClusterClk
* @details      Get cluster clock.
* @param[in]    ClusterIndex : Index of the cluster instance
* @param[out]   Freq         : Gets parameters for clock data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetClusterClk(ClusterClockType ClusterIndex, float64 *Freq)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 temp = 0;
    uint32 ClsDiv = 0;

    ClsDiv = ((TT_GTM->CLS_CLK_CFG.R) >> ((uint8)ClusterIndex * TT_GTM_CLS_CLK_CFG_CLS0_CLK_DIV_LEN)) \
              & TT_GTM_CLS_CLK_CFG_CLS0_CLK_DIV_MSK;
    if(ClsDiv == 0)
    {
        *Freq = 0.0f; /* cluster is disabled - return 0 */
    }
    else if(ClsDiv < TT_GTM_CLS_CLK_CFG_CLS0_CLK_DIV_MSK)
    {
        Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_BUS, &temp);
        if(Ret == TT_RET_SUCCESS)
        {
            *Freq = (float64)temp / (float64)ClsDiv; /*Calculation clock*/
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        Ret = TT_RET_STATUS_ERR;
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_PriGetClk
* @details      This function use to get cmu global clock.
* @param[in]    None
* @param[out]   Clk  : Gets parameters for clock data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetClk(float64 *Clk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Num = 0;
    uint32 Den = 0;
    float64 SysClk = 0.0f;

    /*Get cmu clock information*/
    Num = TT_GTM->CMU.GCLK_NUM.B.GCLK_NUM;
    Den = TT_GTM->CMU.GCLK_DEN.B.GCLK_DEN;

    if((Num == 0) || (Den == 0))
    {
        *Clk = 0.0f;
    }
    else
    {
        /* it should get Cluster0Clk here */
        Ret = Gtm_Hw_Cmu_PriGetClusterClk(GTM_CLUSTER_CLK_0, &SysClk);
        if(Ret == TT_RET_SUCCESS)
        {
            *Clk = ((float64)Den * SysClk) / (float64)Num;
        }
        else
        {
            /* do nothing */
        }
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_PriGetExternalClock
* @details      Get cmu external clock.
* @param[in]    ExIndex : Index of the cluster instance.
* @param[out]   Clk     : Gets parameters for clock data.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetExternalClock(uint8 ExIndex,
                                                 float64 *Clk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    float64 SysClk = 0.0f;
    uint32 Num = 0;
    uint32 Den = 0;

    /* it should get Cluster0Clk here */
    Ret = Gtm_Hw_Cmu_PriGetClusterClk(GTM_CLUSTER_CLK_0, &SysClk);

    if(Ret == TT_RET_SUCCESS)
    {
        if((ExIndex == 0) && (TT_GTM->CMU.CLK_EN.B.EN_ECLK0 == CMU_CLK_R_ENABLE))
        {
            Num = TT_GTM->CMU.ECLK_0_NUM.B.ECLK_NUM;
            Den = TT_GTM->CMU.ECLK_0_DEN.B.ECLK_DEN;
        }
        else if((ExIndex == 1) && (TT_GTM->CMU.CLK_EN.B.EN_ECLK1 == CMU_CLK_R_ENABLE))
        {
            Num = TT_GTM->CMU.ECLK_1_NUM.B.ECLK_NUM;
            Den = TT_GTM->CMU.ECLK_1_DEN.B.ECLK_DEN;
        }
        else if((ExIndex == 2) && (TT_GTM->CMU.CLK_EN.B.EN_ECLK2 == CMU_CLK_R_ENABLE))
        {
            Num = TT_GTM->CMU.ECLK_2_NUM.B.ECLK_NUM;
            Den = TT_GTM->CMU.ECLK_2_DEN.B.ECLK_DEN;
        }
        else
        {
            /* do nothing */
        }

        if((Num == 0) || (Den == 0))
        {
            *Clk = 0.0f;
        }
        else
        {
            *Clk = ((float64)Den * SysClk) / ((float64)Num * 2.0f);
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_PriGetCfguClock
* @details      This function use to get cmu cfgu clock.
* @param[in]    CmuClk : Cmu clock type.
* @param[out]   Clk    : Gets parameters for clock data.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetCfguClock(CmuClkType CmuClk,
                                             float64 *Clk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    float64 SysClk = 0.0f;
    uint32 Count = 0;
    uint8 ClkEn = 0;
    volatile GTM_CMU_CLK_0_CTRL_bf_type *pCtrl = NULL_PTR;
    volatile GTM_CMU_CLK_6_CTRL_bf_type *pCtrl6 = NULL_PTR;

    /*Get cmu clock*/
    Ret = Gtm_Hw_Cmu_PriGetClk(&SysClk);

    if((Ret == TT_RET_SUCCESS) && (SysClk > (float64)0.000001))
    {
        if((uint8)CmuClk < (uint8)CMU_CLK_6)
        {
            ClkEn = (uint8)(((TT_GTM->CMU.CLK_EN.R >> ((uint8)CmuClk << 1U))) & CMU_CLK_R_ENABLE);
            if(ClkEn == 3U)
            {
                pCtrl = &(TT_GTM->CMU.CLK_0_CTRL);
                Count = pCtrl[CmuClk].B.CLK_CNT + 1;
                *Clk = SysClk / (float64)Count;
            }
            else
            {
                *Clk = 0.0f;
            }
        }
        else if((uint8)CmuClk <= (uint8)CMU_CLK_7)
        {
            ClkEn = (uint8)(((TT_GTM->CMU.CLK_EN.R >> ((uint8)CmuClk << 1U))) & CMU_CLK_R_ENABLE);
            if(ClkEn == 3U)
            {
                pCtrl6 = &(TT_GTM->CMU.CLK_6_CTRL);
                Count = pCtrl6[(uint8)CmuClk - (uint8)CMU_CLK_6].B.CLK_CNT + 1;
                *Clk = SysClk / (float64)Count;
            }else
            {
                *Clk = 0.0f;
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
* @brief        Gtm_Hw_Cmu_PriGetFixedClock
* @details      This function use to get cmu fixed clock.
* @param[in]    FxClk : Fix clock type.
* @param[out]   Clk   : Gets parameters for clock data.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriGetFixedClock(uint8 FxClk,
                                              float64 *Clk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    float64 ClkSource = 0.0f;
    uint8 FxclkSel = 0;
    uint8 i = 0;

    /*Get select fixed clock*/
    FxclkSel = TT_GTM->CMU.FXCLK_CTRL.B.FXCLK_SEL;
    /*Get the source according to fix clock.*/

    if(FxclkSel == 0)
    {
        Ret = Gtm_Hw_Cmu_PriGetClk(&ClkSource);
    }
    else if(FxclkSel < CMU_FXCLK_SEL_MAX)
    {
        FxclkSel--;
        Ret = Gtm_Hw_Cmu_PriGetCfguClock((CmuClkType)(sint8)FxclkSel,
                                      &ClkSource);
    }
    else
    {
        ClkSource = 0.0f;
    }

    if(ClkSource > 0.0f)
    {
        for(i = 0; i < FxClk; ++i)
        {
            ClkSource = ClkSource / CMU_FXCLK_DIV_LSB;
        }

        *Clk = ClkSource;
    }
    else
    {
        *Clk = 0.0f;
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_PriSetClusterClk
* @details      This function use to set cluster clock.
* @param[in]    ClockFreqOrDiv : Frequency division coefficient
* @param[in]    ClusterIndex   : Cluster clock type.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriSetClusterClk(uint32 ClockFreqOrDiv,
                                              uint8 ClusterIndex)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Cfg_R = 0;

#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_00();
#endif
    Cfg_R = TT_GTM->CLS_CLK_CFG.R;
    /* clean first */
    Cfg_R &= ~((uint32)TT_GTM_CLS_CLK_CFG_CLS0_CLK_DIV_MSK << (ClusterIndex * TT_GTM_CLS_CLK_CFG_CLS0_CLK_DIV_LEN));
    /* set div */
    Cfg_R |= ((uint32)ClockFreqOrDiv << (ClusterIndex * TT_GTM_CLS_CLK_CFG_CLS0_CLK_DIV_LEN));

    TT_GTM->CTRL.B.RF_PROT = 0;
    TT_GTM->CLS_CLK_CFG.R = Cfg_R;
    TT_GTM->CTRL.B.RF_PROT = 1;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    GTM_REG_CHECK(TT_GTM->CLS_CLK_CFG.R, Cfg_R);
#endif
#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_00();
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_PriSetCfguClock
* @details      Calculate the best numerator and denominator coefficients.
* @param[in]    source : clock source.
* @param[in]    aim    : Target clock.
* @param[out]   nBest  : Optimum molecular coefficient.
* @param[out]   zBest  : Best denominator coefficient.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Cmu_PriCalcBestNZ(float64 source,
                                           float64 aim,
                                           uint32 *nBest,
                                           uint32 *zBest)
{
    float64 f = 0.0f;
    uint32 z = 0;
    uint32 n = 0;
    float64 t = 0.0f;
    float64 bestDistance = aim;
    float64 distance = 0.0f;
    TT_CONST uint32 Frq_max = 0xFFFFFF;

    if(aim < (source / (float64)Frq_max))
    {
        *nBest = 1;
        *zBest = 0xFFFFFF;
    }
    else
    {
        /*Calculate frequency coefficient according to rules*/
        for(z = 1; z < Frq_max; z++)
        {
            boolean endLoop = FALSE;
            t = source / (float64)z;
            /*Calculate the frequency coefficient n according to the rules*/
            for(n = z; n > 0; n--)
            {
                f = t * (float64)n;
                distance = fabsf((float32)(aim - f));
                /*Assign if it meets*/
                if(distance < bestDistance)
                {
                    bestDistance = distance;
                    *nBest = n;
                    *zBest = z;
                }
                else
                {
                    /* do nothing */
                }
                /*Judge whether the rules are met*/
                if(bestDistance < 0.000001)
                {
                    endLoop = TRUE;
                    break;
                }
                else
                {
                    /* do nothing */
                }
            }

            if(endLoop == TRUE)
            {
                break;
            }
            else
            {
                /* do nothing */
            }
        }
    }
}

/**
* @brief        Gtm_Hw_Cmu_PriSetGclk
* @details      This function use to set global clock.
* @param[in]    frequency:     Target frequency.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriSetGclk(uint32 frequency)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST float64 bestDistance = (float64)frequency;
    uint32 nBest = 1;
    uint32 zBest = 1;
    float64 fIn = 0.0f;

    Ret = Gtm_Hw_Cmu_PriGetClusterClk(GTM_CLUSTER_CLK_0, &fIn);
    if(Ret == 0)
    {
        TT_ParaCheck(((float64)frequency > fIn) || (frequency == 0),
                     TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if(Ret == TT_RET_SUCCESS)
    {
        /*Calculate frequency coefficient according to rules*/
        Gtm_Hw_Cmu_PriCalcBestNZ(fIn, bestDistance, &nBest, &zBest);

#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_01();
#endif
        /*Write multiple times ensure write */
        TT_GTM->CMU.GCLK_NUM.B.GCLK_NUM = zBest;
        TT_GTM->CMU.GCLK_NUM.B.GCLK_NUM = zBest;
        TT_GTM->CMU.GCLK_DEN.B.GCLK_DEN = nBest  ;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(TT_GTM->CMU.GCLK_NUM.B.GCLK_NUM, zBest);
        GTM_REG_CHECK(TT_GTM->CMU.GCLK_DEN.B.GCLK_DEN, nBest);
#endif
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_01();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_PriSetExternalClock
* @details      This function use to set external clock.
* @param[in]    ex_index  : External clock index.
* @param[in]    frequency : Target frequency.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriSetExternalClock(uint8 ex_index,
                                                 uint32 frequency)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 nBest = 1;
    uint32 zBest = 1;
    float64 fIn = 0.0f;

    Ret = Gtm_Hw_Cmu_PriGetClusterClk(GTM_CLUSTER_CLK_0, &fIn);
    if(Ret == TT_RET_SUCCESS)
    {
        TT_ParaCheck((((float64)frequency * 2.0) > fIn) || (frequency == 0),
                     TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if(Ret == TT_RET_SUCCESS)
    {
        fIn = fIn / 2.0f;
        /*Calculate frequency coefficient according to rules*/
        Gtm_Hw_Cmu_PriCalcBestNZ(fIn, (float64)frequency, &nBest, &zBest);

#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_03();
#endif
        /*Which external clock is set*/
        switch(ex_index)
        {
            case 0:
            {
                /* write twice to be sure */
                TT_GTM->CMU.ECLK_0_NUM.B.ECLK_NUM = zBest;
                TT_GTM->CMU.ECLK_0_NUM.B.ECLK_NUM = zBest;
                TT_GTM->CMU.ECLK_0_DEN.B.ECLK_DEN = nBest;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->CMU.ECLK_0_NUM.B.ECLK_NUM, zBest);
                GTM_REG_CHECK(TT_GTM->CMU.ECLK_0_DEN.B.ECLK_DEN, nBest);
#endif
            }
                break;
            case 1:
            {
                /* write twice to be sure */
                TT_GTM->CMU.ECLK_1_NUM.B.ECLK_NUM = zBest;
                TT_GTM->CMU.ECLK_1_NUM.B.ECLK_NUM = zBest;
                TT_GTM->CMU.ECLK_1_DEN.B.ECLK_DEN = nBest;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->CMU.ECLK_1_NUM.B.ECLK_NUM, zBest);
                GTM_REG_CHECK(TT_GTM->CMU.ECLK_1_DEN.B.ECLK_DEN, nBest);
#endif
            }
                break;
            case 2:
            {
                /* write twice to be sure */
                TT_GTM->CMU.ECLK_2_NUM.B.ECLK_NUM = zBest;
                TT_GTM->CMU.ECLK_2_NUM.B.ECLK_NUM = zBest;
                TT_GTM->CMU.ECLK_2_DEN.B.ECLK_DEN = nBest;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->CMU.ECLK_2_NUM.B.ECLK_NUM, zBest);
                GTM_REG_CHECK(TT_GTM->CMU.ECLK_2_DEN.B.ECLK_DEN, nBest);
#endif
            }
                break;
            default:
                /* do nothing */
                break;
        }
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_03();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_PriCalcCfguClkDiv
* @details      Calculate the frequency division value of the cfg clock according to the frequency to be set.
* @param[in]    frequency : Target frequency.
* @param[out]   cnt       : Save the division
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriCalcCfguClkDiv(uint32 frequency,
                                               uint32 *cnt)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    float64 clk = 0.0f;
    uint32 divCnt = 0;

    Ret = Gtm_Hw_Cmu_PriGetClk(&clk);
    if(Ret == TT_RET_SUCCESS)
    {
        if((float64)frequency < (clk / (float64)0xFFFFFF))
        {
            *cnt = 0xFFFFFF;
        }
        else
        {
            clk = (clk / (float64)frequency) - 1.0f;
            divCnt = (uint32)clk;

            /* Round to nearest */
            if((clk - (float64)divCnt) > 0.5f)
            {
                divCnt++;
            }
            else
            {
                /* do nothing */
            }

            *cnt = divCnt;
        }
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Cmu_PriSetCfguClock
* @details      This function use to set cfgu clock.
* @param[in]    clkIndex  : Clock index
* @param[in]    frequency : Target frequency.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriSetCfguClock(CmuClkType clkIndex,
                                             uint32 frequency)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    /*Get base clock*/
    uint32 cnt = 0;
    float64 SysClk = 0.0f;
    volatile GTM_CMU_CLK_0_CTRL_bf_type *pCtrl = NULL_PTR;

    Ret = Gtm_Hw_Cmu_PriGetClusterClk(GTM_CLUSTER_CLK_0, &SysClk);
    if(Ret == TT_RET_SUCCESS)
    {
        TT_ParaCheck(((float64)frequency > SysClk), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Cmu_PriCalcCfguClkDiv(frequency, &cnt);
    }
    else
    {
        /* do nothing */
    }

    if(Ret == TT_RET_SUCCESS)
    {
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_02();
#endif
        pCtrl = &(TT_GTM->CMU.CLK_0_CTRL);
        pCtrl[clkIndex].B.CLK_CNT = cnt;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(pCtrl[clkIndex].B.CLK_CNT, cnt);
#endif
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_02();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_PriArchInit
* @details      GTM Arch initialization.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Hw_PriArchInit(void)
{
#if (GTM_EN_RST_AND_FORCE_INT_FUNCTIONAL == FALSE)
    uint32 Value = 1;
#else
    uint32 Value = 0;
#endif

    Value |= (GTM_AEI_TO_MODE << TT_GTM_CTRL_TO_MODE_OFF) | (GTM_AEI_TO_VALUE << TT_GTM_CTRL_TO_VAL_OFF);
    TT_GTM->CTRL.R = Value;
    /* config Irq */
    TT_GTM->IRQ_EN.B.AEI_TO_XPT_IRQ_EN = GTM_AEI_TIMEOUT_EXCEPTIONINT_EN;
    TT_GTM->IRQ_EN.B.AEI_USP_ADDR_IRQ_EN = GTM_AEI_UNSUPPORTED_ADDRESS_INT_EN;
    TT_GTM->IRQ_EN.B.AEI_IM_ADDR_IRQ_EN = GTM_AEI_ILLEGAL_MODULE_ADD_INT_EN;
    TT_GTM->IRQ_EN.B.AEI_USP_BE_IRQ_EN = GTM_AEI_UNSUPPORTED_BYTE_EN_INT_EN;
    TT_GTM->IRQ_EN.B.AEIM_USP_ADDR_IRQ_EN = GTM_AEIM_UNSUPPORTED_ADDRESS_INT_EN;
    TT_GTM->IRQ_EN.B.AEIM_IM_ADDR_IRQ_EN = GTM_AEIM_ILLEGAL_MODULEADD_INT_EN;
    TT_GTM->IRQ_EN.B.AEIM_USP_BE_IRQ_EN = GTM_AEIM_UNSUPPORTED_BYTE_EN_INT_EN;
    TT_GTM->IRQ_EN.B.CLK_EN_ERR_IRQ_EN = GTM_CLK_ENABLE_ERR_INT_EN;
    TT_GTM->IRQ_EN.B.CLK_PER_ERR_IRQ_EN = GTM_CLK_PERIOD_ERR_INT_EN;

    TT_GTM->EIRQ_EN.B.AEI_TO_XPT_EIRQ_EN = GTM_AEI_TIMEOUT_EXCEPTION_ERR_INT_EN;
    TT_GTM->EIRQ_EN.B.AEI_USP_ADDR_EIRQ_EN = GTM_AEI_UNSUPPORTED_ADDRESS_ERR_INT_EN;
    TT_GTM->EIRQ_EN.B.AEI_IM_ADDR_EIRQ_EN = GTM_AEI_ILLEGAL_MODULEADD_ERR_INT_EN;
    TT_GTM->EIRQ_EN.B.AEI_USP_BE_EIRQ_EN = GTM_AEI_UNSUPPORTED_BYTE_EN_ERR_INT_EN;
    TT_GTM->EIRQ_EN.B.AEIM_USP_ADDR_EIRQ_EN = GTM_AEIM_UNSUPPORTED_ADDRESS_ERR_INT_EN;
    TT_GTM->EIRQ_EN.B.AEIM_IM_ADDR_EIRQ_EN = GTM_AEIM_ILLEGAL_MODULEADD_ERR_INT_EN;
    TT_GTM->EIRQ_EN.B.AEIM_USP_BE_EIRQ_EN = GTM_AEIM_UNSUPPORTED_BYTE_EN_EINT_EN;
    TT_GTM->EIRQ_EN.B.CLK_EN_ERR_EIRQ_EN = GTM_CLK_ENABLE_ERR_EINT_EN;
    TT_GTM->EIRQ_EN.B.CLK_PER_ERR_EIRQ_EN = GTM_CLK_PERIOD_ERR_EINT_EN;

    TT_GTM->IRQ_MODE.B.IRQ_MODE = GTM_INTERRUPT_MODE;

    /* config AEI Interface */
#if (GTM_AEI_SYNC_BRIDGE_MODE_EN == TRUE)
    TT_GTM->BRIDGE_MODE.B.BRG_MODE = 0;
#endif
#if (GTM_AEI_MASK_WRITE_RESPONSE_EN == TRUE)
    TT_GTM->BRIDGE_MODE.B.MSK_WR_RSP = 1;
#endif
#if (GTM_AEI_BYPASS_SYNC_EN == TRUE)
    TT_GTM->BRIDGE_MODE.B.BYPASS_SYNC = 1;
#endif

#if (GTM_MCS_AEIM_ACCESS_CLS0_DIS == TRUE)
    TT_GTM->MCS_AEM_DIS.B.DIS_CLS0 = 0x2;
#endif
#if (GTM_MCS_AEIM_ACCESS_CLS1_DIS == TRUE)
    TT_GTM->MCS_AEM_DIS.B.DIS_CLS0 = 0x2;
#endif
#if (GTM_MCS_AEIM_ACCESS_CLS2_DIS == TRUE)
    TT_GTM->MCS_AEM_DIS.B.DIS_CLS0 = 0x2;
#endif
#if (GTM_MCS_AEIM_ACCESS_CLS3_DIS == TRUE)
    TT_GTM->MCS_AEM_DIS.B.DIS_CLS0 = 0x2;
#endif
}

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Hw_Cmu_PriInitCheck
* @details      Cmu initialization check.
* @param[in]    CmuConfig:  Cmu Configuration pointer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Cmu_PriInitCheck(TT_CONST Cmu_ConfigType *CmuConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* The configuration structure is generated on the subsequent update interface */
    (void)CmuConfig;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    /* Arch initialization check */
    GTM_REG_CHECK(TT_GTM->CTRL.R, (GTM_AEI_TO_MODE << TT_GTM_CTRL_TO_MODE_OFF) | (GTM_AEI_TO_VALUE << TT_GTM_CTRL_TO_VAL_OFF) | TT_GTM->CTRL.B.RF_PROT);

    /* config Irq */
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.AEI_TO_XPT_IRQ_EN, GTM_AEI_TIMEOUT_EXCEPTIONINT_EN);
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.AEI_USP_ADDR_IRQ_EN, GTM_AEI_UNSUPPORTED_ADDRESS_INT_EN);
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.AEI_IM_ADDR_IRQ_EN, GTM_AEI_ILLEGAL_MODULE_ADD_INT_EN);
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.AEI_USP_BE_IRQ_EN, GTM_AEI_UNSUPPORTED_BYTE_EN_INT_EN);
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.AEIM_USP_ADDR_IRQ_EN, GTM_AEIM_UNSUPPORTED_ADDRESS_INT_EN);
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.AEIM_IM_ADDR_IRQ_EN, GTM_AEIM_ILLEGAL_MODULEADD_INT_EN);
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.AEIM_USP_BE_IRQ_EN, GTM_AEIM_UNSUPPORTED_BYTE_EN_INT_EN);
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.CLK_EN_ERR_IRQ_EN, GTM_CLK_ENABLE_ERR_INT_EN);
    GTM_REG_CHECK(TT_GTM->IRQ_EN.B.CLK_PER_ERR_IRQ_EN, GTM_CLK_PERIOD_ERR_INT_EN);

    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.AEI_TO_XPT_EIRQ_EN, GTM_AEI_TIMEOUT_EXCEPTION_ERR_INT_EN);
    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.AEI_USP_ADDR_EIRQ_EN, GTM_AEI_UNSUPPORTED_ADDRESS_ERR_INT_EN);
    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.AEI_IM_ADDR_EIRQ_EN, GTM_AEI_ILLEGAL_MODULEADD_ERR_INT_EN);
    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.AEI_USP_BE_EIRQ_EN, GTM_AEI_UNSUPPORTED_BYTE_EN_ERR_INT_EN);
    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.AEIM_USP_ADDR_EIRQ_EN, GTM_AEIM_UNSUPPORTED_ADDRESS_ERR_INT_EN);
    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.AEIM_IM_ADDR_EIRQ_EN, GTM_AEIM_ILLEGAL_MODULEADD_ERR_INT_EN);
    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.AEIM_USP_BE_EIRQ_EN, GTM_AEIM_UNSUPPORTED_BYTE_EN_EINT_EN);
    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.CLK_EN_ERR_EIRQ_EN, GTM_CLK_ENABLE_ERR_EINT_EN);
    GTM_REG_CHECK(TT_GTM->EIRQ_EN.B.CLK_PER_ERR_EIRQ_EN, GTM_CLK_PERIOD_ERR_EINT_EN);

    GTM_REG_CHECK(TT_GTM->IRQ_MODE.B.IRQ_MODE, GTM_INTERRUPT_MODE);

    /* config AEI Interface */
#if (GTM_AEI_SYNC_BRIDGE_MODE_EN == TRUE)
    GTM_REG_CHECK(TT_GTM->BRIDGE_MODE.B.BRG_MODE, 0);
#endif
#if (GTM_AEI_MASK_WRITE_RESPONSE_EN == TRUE)
    GTM_REG_CHECK(TT_GTM->BRIDGE_MODE.B.MSK_WR_RSP, 1);
#endif
#if (GTM_AEI_BYPASS_SYNC_EN == TRUE)
    GTM_REG_CHECK(TT_GTM->BRIDGE_MODE.B.BYPASS_SYNC, 1);
#endif

#if (GTM_MCS_AEIM_ACCESS_CLS0_DIS == TRUE)
    GTM_REG_CHECK(TT_GTM->MCS_AEM_DIS.B.DIS_CLS0, 0x3);    /* Write 0x2 disabled, read corresponding to 0x3 disabled */
#endif
#if (GTM_MCS_AEIM_ACCESS_CLS1_DIS == TRUE)
    GTM_REG_CHECK(TT_GTM->MCS_AEM_DIS.B.DIS_CLS0, 0x3);
#endif
#if (GTM_MCS_AEIM_ACCESS_CLS2_DIS == TRUE)
    GTM_REG_CHECK(TT_GTM->MCS_AEM_DIS.B.DIS_CLS0, 0x3);
#endif
#if (GTM_MCS_AEIM_ACCESS_CLS3_DIS == TRUE)
    GTM_REG_CHECK(TT_GTM->MCS_AEM_DIS.B.DIS_CLS0, 0x3);
#endif

    /* Cmu initialization check */
    GTM_REG_CHECK(TT_GTM->CLS_CLK_CFG.B.CLS0_CLK_DIV, GTM_CLS0_CLK_DIV);
    GTM_REG_CHECK(TT_GTM->CLS_CLK_CFG.B.CLS1_CLK_DIV, GTM_CLS1_CLK_DIV);
    GTM_REG_CHECK(TT_GTM->CLS_CLK_CFG.B.CLS2_CLK_DIV, GTM_CLS2_CLK_DIV);
    GTM_REG_CHECK(TT_GTM->CLS_CLK_CFG.B.CLS3_CLK_DIV, GTM_CLS3_CLK_DIV);

#if (GTM_CLS0_CLK_DIV != 0)
    GTM_REG_CHECK(TT_GTM->CMU.GCLK_NUM.B.GCLK_NUM, CMU_GCLK_NUM);
    GTM_REG_CHECK(TT_GTM->CMU.GCLK_DEN.B.GCLK_DEN, CMU_GCLK_DEN);
#if(CMU_EGU_EN_ECLK0 == TRUE)
    GTM_REG_CHECK(TT_GTM->CMU.ECLK_0_NUM.B.ECLK_NUM, CMU_EGU_ECLK0_NUM);
    GTM_REG_CHECK(TT_GTM->CMU.ECLK_0_DEN.B.ECLK_DEN, CMU_EGU_ECLK0_DEN);
#endif

#if(CMU_EGU_EN_ECLK1 == TRUE)
    GTM_REG_CHECK(TT_GTM->CMU.ECLK_1_NUM.B.ECLK_NUM, CMU_EGU_ECLK1_NUM);
    GTM_REG_CHECK(TT_GTM->CMU.ECLK_1_DEN.B.ECLK_DEN, CMU_EGU_ECLK1_DEN);
#endif

#if(CMU_EGU_EN_ECLK2 == TRUE)
    GTM_REG_CHECK(TT_GTM->CMU.ECLK_2_NUM.B.ECLK_NUM, CMU_EGU_ECLK2_NUM);
    GTM_REG_CHECK(TT_GTM->CMU.ECLK_2_DEN.B.ECLK_DEN, CMU_EGU_ECLK2_DEN);
#endif

#if(CMU_FXCLK_ENABLE == TRUE)
    GTM_REG_CHECK(TT_GTM->CMU.FXCLK_CTRL.B.FXCLK_SEL, (uint8)(CMU_FXCLK_SEL));
#endif

#if(CMU_CFGU_EN_CLK0 == TRUE) && (CMU_CFGU_CLK_DIV0 > 0)
    GTM_REG_CHECK(TT_GTM->CMU.CLK_0_CTRL.R, (CMU_CFGU_CLK_DIV0 - 1U));
#endif

#if(CMU_CFGU_EN_CLK1 == TRUE) && (CMU_CFGU_CLK_DIV1 > 0)
    GTM_REG_CHECK(TT_GTM->CMU.CLK_1_CTRL.R, (CMU_CFGU_CLK_DIV1 - 1U));
#endif

#if(CMU_CFGU_EN_CLK2 == TRUE) && (CMU_CFGU_CLK_DIV2 > 0)
    GTM_REG_CHECK(TT_GTM->CMU.CLK_2_CTRL.R, (CMU_CFGU_CLK_DIV2 - 1U));
#endif

#if(CMU_CFGU_EN_CLK3 == TRUE) && (CMU_CFGU_CLK_DIV3 > 0)
    GTM_REG_CHECK(TT_GTM->CMU.CLK_3_CTRL.R, (CMU_CFGU_CLK_DIV3 - 1U));
#endif

#if(CMU_CFGU_EN_CLK4 == TRUE) && (CMU_CFGU_CLK_DIV4 > 0)
    GTM_REG_CHECK(TT_GTM->CMU.CLK_4_CTRL.R, (CMU_CFGU_CLK_DIV4 - 1U));
#endif

#if(CMU_CFGU_EN_CLK5 == TRUE) && (CMU_CFGU_CLK_DIV5 > 0)
    GTM_REG_CHECK(TT_GTM->CMU.CLK_5_CTRL.R, (CMU_CFGU_CLK_DIV5 - 1U));
#endif

#if(CMU_CFGU_EN_CLK6 == TRUE) && (CMU_CFGU_CLK_DIV6 > 0)
    GTM_REG_CHECK(TT_GTM->CMU.CLK_6_CTRL.R, (CMU_CFGU_CLK_DIV6 - 1U) | ((uint32)CMU_CFGU_CLK6_SEL) << 24);
#endif

#if(CMU_CFGU_EN_CLK7 == TRUE) && (CMU_CFGU_CLK_DIV7 > 0)
    GTM_REG_CHECK(TT_GTM->CMU.CLK_7_CTRL.R, (CMU_CFGU_CLK_DIV7 - 1U) | ((uint32)CMU_CFGU_CLK7_SEL) << 24);
#endif
#endif

    /* Set the monitoring clock and clock frequency division */
#if(GTM_MONITOR_CLS0_EN == STD_ON)
    GTM_REG_CHECK(GTM_WRAPPER->CMU[0].R, 0x10UL | GTM_MONITOR_CLS0_DIV);
#endif
#if(GTM_MONITOR_CLS1_EN == STD_ON)
    GTM_REG_CHECK(GTM_WRAPPER->CMU[1].R, 0x10UL | GTM_MONITOR_CLS1_DIV);
#endif
#if(GTM_MONITOR_CLS2_EN == STD_ON)
    GTM_REG_CHECK(GTM_WRAPPER->CMU[2].R, 0x10UL | GTM_MONITOR_CLS2_DIV);
#endif
#if(GTM_MONITOR_CLS3_EN == STD_ON)
    GTM_REG_CHECK(GTM_WRAPPER->CMU[3].R, 0x10UL | GTM_MONITOR_CLS3_DIV);
#endif

    /* Set the TIM channel input source */
    GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.B.TIM0_SEL, GTM_TIM0CH0_INPUT_SEL);
    GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.B.TIM1_SEL, GTM_TIM0CH1_INPUT_SEL);
    GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.B.TIM2_SEL, GTM_TIM0CH2_INPUT_SEL);
    GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.B.TIM3_SEL, GTM_TIM0CH3_INPUT_SEL);
    GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.B.TIM4_SEL, GTM_TIM0CH4_INPUT_SEL);
    GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.B.TIM5_SEL, GTM_TIM0CH5_INPUT_SEL);
    GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.B.TIM6_SEL, GTM_TIM0CH6_INPUT_SEL);
    GTM_REG_CHECK(GTM_WRAPPER->TIMSEL.B.TIM7_SEL, GTM_TIM0CH7_INPUT_SEL);

    /* Set the OSC clock input frequency division */
    GTM_REG_CHECK(GTM_WRAPPER->OSCDIV.B.DIV, (uint8)GTM_MONITOR_OSC_DIV);
#endif
    return Ret;
}
#endif

#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

#ifdef __cplusplus
}
#endif
