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
**  FILENAME     : Mcu_Hw_Pmu.c                                               **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Mcu Driver Source File                                     **
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
#include "Mcu_Hw_Pmu.h"
#include "Mcu_Hw_Ppu.h"
#include "Mcu_Hw_Clk.h"
#include "Mcu_Hw_Misc.h"
#include "Mcu_Hw_Cmu.h"
#include "Base_Drv.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Mcu.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_PMU_VENDOR_ID_C                     1541
#define MCU_HW_PMU_MODULE_ID_C                     101
#define MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_C      4
#define MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_C      0
#define MCU_HW_PMU_SW_MAJOR_VERSION_C              1
#define MCU_HW_PMU_SW_MINOR_VERSION_C              1
#define MCU_HW_PMU_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Pmu.c and Mcu_Hw_Pmu.h file version check */
#if (MCU_HW_PMU_VENDOR_ID_C != MCU_HW_PMU_VENDOR_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Pmu.h have different vendor id"
#endif
#if (MCU_HW_PMU_MODULE_ID_C != MCU_HW_PMU_MODULE_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Pmu.h have different module id"
#endif
#if ((MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_C != MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_C != MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Pmu.h are different"
#endif
#if ((MCU_HW_PMU_SW_MAJOR_VERSION_C != MCU_HW_PMU_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_SW_MINOR_VERSION_C != MCU_HW_PMU_SW_MINOR_VERSION_H) || \
     (MCU_HW_PMU_SW_PATCH_VERSION_C != MCU_HW_PMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Pmu.h are different"
#endif

/* Mcu_Hw_Pmu.c and Mcu_Hw_Ppu.h file version check */
#if (MCU_HW_PMU_VENDOR_ID_C != MCU_HW_PPU_VENDOR_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Ppu.h have different vendor id"
#endif
#if (MCU_HW_PMU_MODULE_ID_C != MCU_HW_PPU_MODULE_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Ppu.h have different module id"
#endif
#if ((MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_PPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_C != MCU_HW_PPU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_C != MCU_HW_PPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Ppu.h are different"
#endif
#if ((MCU_HW_PMU_SW_MAJOR_VERSION_C != MCU_HW_PPU_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_SW_MINOR_VERSION_C != MCU_HW_PPU_SW_MINOR_VERSION_H) || \
     (MCU_HW_PMU_SW_PATCH_VERSION_C != MCU_HW_PPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Ppu.h are different"
#endif

/* Mcu_Hw_Pmu.c and Mcu_Hw_Clk.h file version check */
#if (MCU_HW_PMU_VENDOR_ID_C != MCU_HW_CLK_VENDOR_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Clk.h have different vendor id"
#endif
#if (MCU_HW_PMU_MODULE_ID_C != MCU_HW_CLK_MODULE_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Clk.h have different module id"
#endif
#if ((MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_C != MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_C != MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Clk.h are different"
#endif
#if ((MCU_HW_PMU_SW_MAJOR_VERSION_C != MCU_HW_CLK_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_SW_MINOR_VERSION_C != MCU_HW_CLK_SW_MINOR_VERSION_H) || \
     (MCU_HW_PMU_SW_PATCH_VERSION_C != MCU_HW_CLK_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Clk.h are different"
#endif

/* Mcu_Hw_Pmu.c and Mcu_Hw_Misc.h file version check */
#if (MCU_HW_PMU_VENDOR_ID_C != MCU_HW_MISC_VENDOR_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Misc.h have different vendor id"
#endif
#if (MCU_HW_PMU_MODULE_ID_C != MCU_HW_MISC_MODULE_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Misc.h have different module id"
#endif
#if ((MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_C != MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_C != MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Misc.h are different"
#endif
#if ((MCU_HW_PMU_SW_MAJOR_VERSION_C != MCU_HW_MISC_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_SW_MINOR_VERSION_C != MCU_HW_MISC_SW_MINOR_VERSION_H) || \
     (MCU_HW_PMU_SW_PATCH_VERSION_C != MCU_HW_MISC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Misc.h are different"
#endif

/* Mcu_Hw_Pmu.c and Mcu_Hw_Cmu.h file version check */
#if (MCU_HW_PMU_VENDOR_ID_C != MCU_HW_CMU_VENDOR_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Cmu.h have different vendor id"
#endif
#if (MCU_HW_PMU_MODULE_ID_C != MCU_HW_CMU_MODULE_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Cmu.h have different module id"
#endif
#if ((MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_CMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_C != MCU_HW_CMU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_C != MCU_HW_CMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Cmu.h are different"
#endif
#if ((MCU_HW_PMU_SW_MAJOR_VERSION_C != MCU_HW_CMU_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_SW_MINOR_VERSION_C != MCU_HW_CMU_SW_MINOR_VERSION_H) || \
     (MCU_HW_PMU_SW_PATCH_VERSION_C != MCU_HW_CMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Cmu.h are different"
#endif

#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
#if (MCU_HW_PMU_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
    #error "Mcu_Hw_Pmu.c and Mcu_Hw_Misc.h have different vendor id"
#endif
#if ((MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Misc.h are different"
#endif
#if ((MCU_HW_PMU_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
     (MCU_HW_PMU_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Pmu.c and Mcu_Hw_Misc.h are different"
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
******************************************************************************/
#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

static TT_Notification Pmu_PubCallBackPtr[1] = {NULL_PTR};

#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#define MCU_START_SEC_CODE_FAST
#include "Mcu_MemMap.h"
ISR(PMU_IRQHandler);
#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_Hw_Pmu_PriMpllStandby
* @details      Use to Standby Mpll
* @param[in]    mpll_standby - current mpll mode
* @param[out]    BusClk - current bus clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriMpllStandby(boolean mpll_standby, uint32 *BusClk);

/**
* @brief        Mcu_Hw_Pmu_PriMpllActive
* @details      Use to active Mpll
* @param[in]    mpll_standby - current mpll mode
* @param[in]    BusClk - current bus clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriMpllActive(boolean mpll_standby, uint32 BusClk);

/**
* @brief        Mcu_Hw_Pmu_PriEpllStandby
* @details      Use to Standby Mpll
* @param[in]    mpll_standby - current epll mode
* @return
* @pre
*/
static void Mcu_Hw_Pmu_PriEpllStandby(boolean mpll_standby);

/**
* @brief        Mcu_Hw_Pmu_PriEpllActive
* @details      Use to active Mpll
* @param[in]    mpll_standby - current epll mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriEpllActive(boolean mpll_standby);

/**
* @brief        Mcu_Hw_Pmu_PriConfigGpioInput
* @details      Gpio Input configuration.
* @param[in]    Num - Gpio number
* @param[in]    PmuGpioConfig - Gpio configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriConfigGpioInput(TT_CONST uint32 Num, TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig);

/**
* @brief        Mcu_Hw_Pmu_PriConfigGpioOut
* @details      Gpio Output configuration.
* @param[in]    Num - Gpio number
* @param[in]    PmuGpioConfig - Gpio configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriConfigGpioOut(TT_CONST uint32 Num, TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig);

/**
* @brief        Mcu_Hw_Pmu_PriConfigHsmDown
* @details      Service to Set MCU Lowe Power Mode
* @param[in]    McuModeSettingConfig - Mcu mode setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriConfigHsmDown(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig);

/**
* @brief        Mcu_Hw_Pmu_PriConfigHsmUp
* @details      Service to Set MCU Lowe Power Mode
* @param[in]    McuModeSettingConfig - Mcu mode setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriConfigHsmUp(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig);

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Pmu_PriRegReadBack
* @details       Ppu Register Read Back
* @param[in]     ActualValue - Actual Value
* @param[in]     TargetValue - Target Value
* @param[out]    Ret - TT_RET_SUCCESS - success
                 Others - fail
* @return        void
* @retval
* @pre
*/
LOCAL_INLINE void Mcu_Hw_Pmu_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret);
#endif
/******************************************************************************
*                            Public Functions
*******************************************************************************/
/**
* @brief         Mcu_Hw_Pmu_GetUserValue
* @details       Get user's register value
* @param[in]     Index - Register hardware unit
* @param[out]    Value - The value of the user register
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_GetUserValue(TT_CONST uint32 Index, uint32 *Value)
{
    TT_RetType Ret = 0U;

    TT_ParaCheck((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        switch (Index)
        {
            case 0U:
                *Value = TT_PMU->USER0;
                break;
            case 1U:
                *Value = TT_PMU->USER1;
                break;
            default:
                /* default */
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

/**
* @brief        Mcu_Hw_Pmu_SetUserValue
* @details      Set The value of the user register.
* @param[in]    Value - The value of the user register
* @param[in]    Index - Register hardware unit
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_SetUserValue(TT_CONST uint32 Value, TT_CONST uint32 Index)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    switch (Index)
    {
        case 0:
            TT_PMU->USER0 = Value;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack(TT_PMU->USER0, Value, &Ret);
        #endif
            break;
        case 1:
            TT_PMU->USER1 = Value;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack(TT_PMU->USER1, Value, &Ret);
        #endif
            break;
        default:
            /* default */
            Ret = TT_RET_PARAM_INDEX_ERR;
            break;
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_LocalReset
* @details      Pmu local reset.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_LocalReset(void)
{
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;

    TT_PMU->LOCAL_RST |= (uint32)1U;

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_ConfigNmi
* @details      Nmi configuration.
* @param[in]    PmuNmiConfig - Nmi configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_ConfigNmi(TT_CONST Mcu_Hw_PmuNmiConfigType *PmuNmiConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Value = 0U;

    TT_ParaCheck((PmuNmiConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if ((PmuNmiConfig->NmiEn == 1U))
        {
        #ifdef A8V2
            Value = ((uint32)PmuNmiConfig->NmiEn << TT_PMU_NCR_NMIEN_Pos)             | \
                      ((uint32)PmuNmiConfig->InputEdgeFallEn << TT_PMU_NCR_NFE0_Pos)    | \
                      ((uint32)PmuNmiConfig->InputEdgeRiseEn << TT_PMU_NCR_NREE0_Pos)   | \
                      ((uint32)PmuNmiConfig->InputWakeReqEn << TT_PMU_NCR_NWRE0_Pos)    | \
                      ((uint32)PmuNmiConfig->InputFilterEn << TT_PMU_NCR_NFE0_Msk);
        #elif defined A8V2E
            Value = ((uint32)PmuNmiConfig->NmiEn << TT_PMU_NCR_NMIEN_Pos)             | \
                      ((uint32)PmuNmiConfig->InputEdgeFallEn << TT_PMU_NCR_NFE0_Pos)    | \
                      ((uint32)PmuNmiConfig->InputEdgeRiseEn << TT_PMU_NCR_NREE0_Pos)   | \
                      ((uint32)PmuNmiConfig->InputWakeReqEn << TT_PMU_NCR_NWRE0_Pos)    | \
                      ((uint32)PmuNmiConfig->InputFastFilterEn << TT_PMU_NCR_NMIFP0_Pos)| \
                      ((uint32)PmuNmiConfig->FastFilterCount << TT_PMU_NCR_NFCNT_Pos)| \
                      ((uint32)PmuNmiConfig->InputFilterEn << TT_PMU_NCR_NFE0_Msk);

        #endif
            TT_PMU->NCR = Value;
            TT_PMU->CR |= TT_PMU_CR_WKUP_EN_Msk;

        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack(TT_PMU->NCR, Value, &Ret);
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->CR & TT_PMU_CR_WKUP_EN_Msk), TT_PMU_CR_WKUP_EN_Msk, &Ret);
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
* @brief        Mcu_Hw_Pmu_ConfigGpio
* @details      Gpio configuration.
* @param[in]    PmuGpioConfig - Gpio configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_ConfigGpio(TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig)
{
    uint32 Num = 0U;
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_SAFETY == STD_ON)
    TT_RetType Ret1 = TT_RET_SUCCESS;
    TT_RetType Ret2 = TT_RET_SUCCESS;
#endif

    TT_ParaCheck((PmuGpioConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Num = (uint32)((uint32)1U << PmuGpioConfig->Number);

    #if (TT_SAFETY == STD_OFF)
        (void)Mcu_Hw_Pmu_PriConfigGpioInput(Num, PmuGpioConfig);
        (void)Mcu_Hw_Pmu_PriConfigGpioOut(Num, PmuGpioConfig);
    #else
        Ret1 = Mcu_Hw_Pmu_PriConfigGpioInput(Num, PmuGpioConfig);
        Ret2 = Mcu_Hw_Pmu_PriConfigGpioOut(Num, PmuGpioConfig);
        if((TT_RET_SUCCESS == Ret1)&&(TT_RET_SUCCESS == Ret2))
        {
            TT_PMU->CR |= TT_PMU_CR_WKUP_EN_Msk;
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->CR & TT_PMU_CR_WKUP_EN_Msk), TT_PMU_CR_WKUP_EN_Msk, &Ret);

        }
        else if(TT_RET_SUCCESS != Ret1)
        {
            Ret = Ret1;
        }
        else
        {
            Ret = Ret2;
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
* @brief        Mcu_Hw_Pmu_GetResetRawValue
* @details      Get reset raw value
* @param[out]   Value - Reset raw value
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_GetResetRawValue(uint32 *Value)
{
    TT_RetType Ret = 0;

    TT_ParaCheck((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        *Value = TT_SCU->RESET_SOURCE;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_GetResetReason
* @details      Get reset reason
* @param[out]   Value - Reset reason
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_GetResetReason(uint32 *Value)
{
    uint32      i = 0U;
    TT_RetType  Ret = TT_RET_SUCCESS;

    TT_ParaCheck((Value == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        for (i = 0; i < TT_U32_BITS; i++)
        {
            if ((TT_SCU->RESET_SOURCE & ((uint32)1U<<i)) > 0U)
            {
                *Value = i;
                break;
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

    /* get none reset reson */
    if (TT_U32_BITS == i)
    {
        Ret = TT_RET_STATUS_ERR;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_EnterStandby
* @details      cpu enter standby mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_EnterStandby(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_PMU->CR |= TT_PMU_CR_WKUP_EN_Msk;
#if (TT_SAFETY == STD_ON)
    Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->CR & TT_PMU_CR_WKUP_EN_Msk), TT_PMU_CR_WKUP_EN_Msk, &Ret);
#endif
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    TT_SCB->SCR |= (1U << 2U);
    MCAL_WFI();
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_EnterSleep
* @details      cpu enter sleep mode
* @param[in]    OscDiv:  cpu run in osc clock by div
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_EnterSleep(TT_CONST uint32 OscDiv)
{
    boolean mpll_standby = FALSE;
    boolean epll_standby = FALSE;
    TT_RetType Ret = TT_RET_SUCCESS;
#if (defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)) || (TT_SAFETY == STD_ON)
    TT_RetType Ret1 = TT_RET_SUCCESS;
#endif
    uint32 CmuFlag = 0;
    uint32 BusClk = 0;

    TT_ParaCheck(((OscDiv < MCU_PMU_OSC_DIV_MIN) || (OscDiv > MCU_PMU_OSC_DIV_MAX)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    TT_PMU->CR |= TT_PMU_CR_WKUP_EN_Msk;
#if (TT_SAFETY == STD_ON)
    Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->CR & TT_PMU_CR_WKUP_EN_Msk), TT_PMU_CR_WKUP_EN_Msk, &Ret);
#endif

    if (TT_RET_SUCCESS == Ret)
    {
        if ((((TT_SCU->MPLL_CTL & TT_SCU_MPLL_CTL_STANDBY_Msk) >> TT_SCU_MPLL_CTL_STANDBY_Pos) & 0x1U) > 0U)
        {
            mpll_standby = TRUE;
        }
        else
        {
            mpll_standby = FALSE;
        }

        if ((((TT_SCU->EPLL_CTL & TT_SCU_EPLL_CTL_STANDBY_Msk) >> TT_SCU_EPLL_CTL_STANDBY_Pos) & 0x1U) > 0U)
        {
            epll_standby = TRUE;
        }
        else
        {
            epll_standby = FALSE;
        }

        /* Stop all CMU */
        (void)Mcu_Hw_Cmu_StoreStop(&CmuFlag);
        Mcu_Hw_Pmu_PriEpllStandby(epll_standby);
        Ret = Mcu_Hw_Pmu_PriMpllStandby(mpll_standby, &BusClk);

        if (Ret == TT_RET_SUCCESS)
        {
            TT_REG32_CLR_SET(TT_SCU->CLKDIV_CTL0, TT_SCU_CLKDIV_CTL0_DIV_ECO_CFG, (OscDiv - 1));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack(TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL0, TT_SCU_CLKDIV_CTL0_DIV_ECO_CFG), (OscDiv - 1), &Ret);
        #endif
            (void)Mcu_Hw_Clk_AwakenModules(TT_SCU_CLK_SLEEP_PMU_APB);
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();
            /* WFI */
            MCAL_WFI();
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_15();
        #endif
            (void)Base_Drv_UnlockProtReg();
            TT_SCU->CLKDIV_CTL0 &= ~TT_SCU_CLKDIV_CTL0_DIV_ECO_CFG_Msk;
            (void)Base_Drv_LockProtReg();
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_15();
        #endif
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack(TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL0, TT_SCU_CLKDIV_CTL0_DIV_ECO_CFG), 0, &Ret);
        #endif

        #if (defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)) || (TT_SAFETY == STD_ON)
            Ret = Mcu_Hw_Pmu_PriMpllActive(mpll_standby, BusClk);
            Ret1 = Mcu_Hw_Pmu_PriEpllActive(epll_standby);

            if ((Ret == TT_RET_SUCCESS) && (Ret1 == TT_RET_SUCCESS))
            {
                /* Restore all CMU */
                (void)Mcu_Hw_Cmu_LoadStart(&CmuFlag);
            }
            else if (Ret1 != TT_RET_SUCCESS)
            {
                Ret = Ret1;
            }
            else
            {
                /* do nothing */
            }
        #else
            (void)Mcu_Hw_Pmu_PriMpllActive(mpll_standby, BusClk);
            (void)Mcu_Hw_Pmu_PriEpllActive(epll_standby);
            /* Restore all CMU */
            (void)Mcu_Hw_Cmu_LoadStart(&CmuFlag);
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
* @brief        Mcu_Hw_Pmu_ConfigMode
* @details      Service to Set MCU Lowe Power Mode
* @param[in]    McuModeSettingConfig - Mcu mode setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_ConfigMode(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((McuModeSettingConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    TT_ParaCheck(((McuModeSettingConfig != NULL_PTR)&&(McuModeSettingConfig->FlashPowerDownEn != TRUE) && \
                            (McuModeSettingConfig->FlashPowerDownEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuModeSettingConfig != NULL_PTR)&&(McuModeSettingConfig->ECOPowerDownEn != TRUE) && \
                            (McuModeSettingConfig->ECOPowerDownEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuModeSettingConfig != NULL_PTR)&&(McuModeSettingConfig->IHOPowerDownEn != TRUE) && \
                            (McuModeSettingConfig->IHOPowerDownEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuModeSettingConfig != NULL_PTR)&&(McuModeSettingConfig->CipherPowerDownEn != TRUE) && \
                            (McuModeSettingConfig->CipherPowerDownEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuModeSettingConfig != NULL_PTR)&&(McuModeSettingConfig->HSMPowerDownEn != TRUE) && \
                            (McuModeSettingConfig->HSMPowerDownEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
#ifdef A8V2E
    TT_ParaCheck(((McuModeSettingConfig != NULL_PTR)&&(McuModeSettingConfig->RstbWakupEn != TRUE) && \
                            (McuModeSettingConfig->RstbWakupEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
#endif

    if (TT_RET_SUCCESS == Ret)
    {
        switch(McuModeSettingConfig->McuOperaMode)
        {
            case MCU_OP_RUN_MODE:
                if ((McuModeSettingConfig->McuPpuSettingConfig != NULL_PTR))
                {
                    Ret = Mcu_Hw_Ppu_Config(McuModeSettingConfig->McuPpuSettingConfig);
                }
                else
                {
                    /* do nothing */
                }
#ifdef A8V2E
                (void)Mcu_Hw_Pmu_PriConfigHsmDown(McuModeSettingConfig);
#endif
                break;
            case MCU_OP_SLEEP_MODE :
                if (McuModeSettingConfig->McuPeriphSleepClockConfig != NULL_PTR)
                {
                #ifdef USING_OS_AUTOSAROS
                    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_16();
                #endif
                    (void)Base_Drv_UnlockProtReg();
                    TT_SCU->PERI_STOP = (McuModeSettingConfig->McuPeriphSleepClockConfig->McuLinClockSleep & 0xFFFFU)   | \
                                    ((uint32)(McuModeSettingConfig->McuPeriphSleepClockConfig->McuCanClockSleep & 0xFFU) << 16U);
                    TT_SCU->CLK_SLEEP0 = McuModeSettingConfig->McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig0;
                    TT_SCU->CLK_SLEEP1 = McuModeSettingConfig->McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig1;
                    TT_SCU->CLK_SLEEP2 = McuModeSettingConfig->McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig2;
                    (void)Base_Drv_LockProtReg();
                #ifdef USING_OS_AUTOSAROS
                    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_16();
                #endif

                #if (TT_SAFETY == STD_ON)
                    Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->PERI_STOP & 0xFFFFU), (McuModeSettingConfig->McuPeriphSleepClockConfig->McuLinClockSleep & 0xFFFFU), &Ret);
                    Mcu_Hw_Pmu_PriRegReadBack(((TT_SCU->PERI_STOP & 0xFF0000U) >> 16U), McuModeSettingConfig->McuPeriphSleepClockConfig->McuCanClockSleep, &Ret);
                    Mcu_Hw_Pmu_PriRegReadBack(TT_SCU->CLK_SLEEP0, McuModeSettingConfig->McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig0, &Ret);
                    Mcu_Hw_Pmu_PriRegReadBack(TT_SCU->CLK_SLEEP1, McuModeSettingConfig->McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig1, &Ret);
                    Mcu_Hw_Pmu_PriRegReadBack(TT_SCU->CLK_SLEEP2, McuModeSettingConfig->McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig2, &Ret);
                #endif
                }
                else
                {
                    /* do nothing */
                }
            #ifdef USING_OS_AUTOSAROS
                SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_17();
            #endif
                (void)Base_Drv_UnlockProtReg();
                TT_SCU->LP_CTL |= (((uint32)McuModeSettingConfig->FlashPowerDownEn << 0U) | \
                                    ((uint32)McuModeSettingConfig->ECOPowerDownEn << TT_SCU_LP_CTL_ECO_DISABLE_Pos) |
                                    ((uint32)McuModeSettingConfig->IHOPowerDownEn << TT_SCU_LP_CTL_OSC_DISABLE_Pos));
                (void)Base_Drv_LockProtReg();
            #ifdef USING_OS_AUTOSAROS
                SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_17();
            #endif

            #if (TT_SAFETY == STD_ON)
                Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->LP_CTL & TT_SCU_LP_CTL_FLASH_PD_Msk), ((uint32)McuModeSettingConfig->FlashPowerDownEn << 0U), &Ret);
                Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->LP_CTL & TT_SCU_LP_CTL_ECO_DISABLE_Msk), ((uint32)McuModeSettingConfig->ECOPowerDownEn << TT_SCU_LP_CTL_ECO_DISABLE_Pos), &Ret);
                Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->LP_CTL & TT_SCU_LP_CTL_OSC_DISABLE_Msk), ((uint32)McuModeSettingConfig->IHOPowerDownEn << TT_SCU_LP_CTL_OSC_DISABLE_Pos), &Ret);
            #endif

                (void)Mcu_Hw_Pmu_PriConfigHsmDown(McuModeSettingConfig);

                Ret = Mcu_Hw_Pmu_EnterSleep(McuModeSettingConfig->OSCDiv);

                (void)Mcu_Hw_Pmu_PriConfigHsmUp(McuModeSettingConfig);
                break;
            case MCU_OP_STANDBY_MODE:
#ifdef A8V2E
                TT_PMU->CR |=  ((uint32)McuModeSettingConfig->RstbWakupEn << TT_PMU_CR_RSTB_WKUP_EN_Pos);

            #if (TT_SAFETY == STD_ON)
                Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->CR & TT_PMU_CR_RSTB_WKUP_EN_Pos), ((uint32)McuModeSettingConfig->RstbWakupEn << TT_PMU_CR_RSTB_WKUP_EN_Pos), &Ret);
            #endif
#endif
                Ret = Mcu_Hw_Pmu_EnterStandby();
                break;
            default:
                Ret = TT_RET_PARAM_CONFIG_ERR;
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
* @brief        Mcu_Hw_Pmu_SetCallBack
* @details      Set Callback function
* @param[in]    callback function name
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_SetCallBack(TT_Notification callback)
{
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;

    Pmu_PubCallBackPtr[0] = callback;

    return Ret;
}

#ifdef A8V2E
/**
* @brief        Mcu_Hw_Pmu_SetHsmCipPowerDown
* @details      Service to Set Hsm and Cipher Power Mode
* @param[in]    Type - Hsm or Cipher
* @param[in]    Enable - TRUE  :Power Down
*                        - FALSE :Power up
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_SetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,TT_CONST boolean Enable)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_ParaCheck((Enable != TRUE)&&(Enable != FALSE), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        switch (Type)
        {
           case MCU_OP_CIPHER:
                /* need sync hsm with mailbox by user */
               if (Enable == TRUE)
               {
                #ifdef USING_OS_AUTOSAROS
                    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_18();
                #endif
                    (void)Base_Drv_UnlockProtReg();
                    TT_SCU->LP_CTL |= TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk;
                    (void)Base_Drv_LockProtReg();
                #ifdef USING_OS_AUTOSAROS
                    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_18();
                #endif
                #if (TT_SAFETY == STD_ON)
                    Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->LP_CTL & (TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk)), (TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk), &Ret);
                #endif
               }
               else
               {
                #ifdef USING_OS_AUTOSAROS
                    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_19();
                #endif
                    (void)Base_Drv_UnlockProtReg();
                    TT_SCU->LP_CTL &= ~(TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk);
                    (void)Base_Drv_LockProtReg();
                #ifdef USING_OS_AUTOSAROS
                    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_19();
                #endif
                #if (TT_SAFETY == STD_ON)
                    Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->LP_CTL & (TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk)), 0, &Ret);
                #endif
               }
               break;
           case MCU_OP_HSM:
               if (Enable == TRUE)
               {
                #ifdef USING_OS_AUTOSAROS
                    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_20();
                #endif
                    (void)Base_Drv_UnlockProtReg();
                   TT_SCU->LP_CTL |= TT_SCU_LP_CTL_HSM_PD_Msk;
                   (void)Base_Drv_LockProtReg();
                #ifdef USING_OS_AUTOSAROS
                    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_20();
                #endif
                #if (TT_SAFETY == STD_ON)
                    Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->LP_CTL & (TT_SCU_LP_CTL_HSM_PD_Msk)), (TT_SCU_LP_CTL_HSM_PD_Msk), &Ret);
                #endif
               }
               else
               {
                #ifdef USING_OS_AUTOSAROS
                    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_21();
                #endif
                   (void)Base_Drv_UnlockProtReg();
                   TT_SCU->LP_CTL &= ~(TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk);
                   (void)Base_Drv_LockProtReg();
                #ifdef USING_OS_AUTOSAROS
                    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_21();
                #endif
                #if (TT_SAFETY == STD_ON)
                    Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->LP_CTL & (TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk)), 0, &Ret);
                #endif
               }
                break;
           default:
               Ret = TT_RET_PARAM_ENUM_ERR;
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
* @brief        Mcu_Hw_Pmu_GetHsmCipPowerDown
* @details      Service to Get Hsm and Cipher Power Down Status
* @param[in]    Type - Hsm or Cipher
* @param[out]    Enable - TRUE  :Power Down
*                        - FALSE :Power up
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Pmu_GetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,uint32* Enable)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_ParaCheck((Enable == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        switch (Type)
        {
           case MCU_OP_CIPHER:
               if ((TT_SCU->LP_CTL & TT_SCU_LP_CTL_CIP_PD_STATUS_Msk) > 0)
               {
                   *Enable = TRUE;
               }
               else
               {
                   *Enable = FALSE;
               }
               break;
           case MCU_OP_HSM:
               if ((TT_SCU->LP_CTL & TT_SCU_LP_CTL_HSM_PD_STATUS_Msk) > 0)
               {
                   *Enable = TRUE;
               }
               else
               {
                   *Enable = FALSE;
               }
            break;
           default:
               Ret = TT_RET_PARAM_ENUM_ERR;
               break;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#endif

/******************************************************************************
*                            Private Functions
******************************************************************************/
/**
* @brief        Mcu_Hw_Pmu_PriConfigGpioInput
* @details      Gpio configuration.
* @param[in]    Num - Gpio number
* @param[in]    PmuGpioConfig - Gpio configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriConfigGpioInput(TT_CONST uint32 Num, TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (PmuGpioConfig->InputEn > 0U)
    {
        TT_PMU->IER |= Num;
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->IER & Num), Num, &Ret);
    #endif
        if ((PmuGpioConfig->InputFilterEn == 1U))
        {
            TT_PMU->WIFER |= Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->WIFER & Num), Num, &Ret);
        #endif
        }
        else
        {
            TT_PMU->WIFER &= ~Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->WIFER & Num), 0, &Ret);
        #endif
        }

        if ((PmuGpioConfig->InputEdgeRiseEn == 1U))
        {
            TT_PMU->WIREER |= Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->WIREER & Num), Num, &Ret);
        #endif
        }
        else
        {
            TT_PMU->WIREER &= ~Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->WIREER & Num), 0, &Ret);
        #endif
        }

        if ((PmuGpioConfig->InputEdgeFallEn == 1U))
        {
            TT_PMU->WIFEER |= Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->WIFEER & Num), Num, &Ret);
        #endif
        }
        else
        {
            TT_PMU->WIFEER &= ~Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->WIFEER & Num), 0, &Ret);
        #endif
        }

        if ((PmuGpioConfig->InputIntReqEn == 1U))
        {
            TT_PMU->IRER |= Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->IRER & Num), Num, &Ret);
        #endif
        }
        else
        {
            TT_PMU->IRER &= ~Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->IRER & Num), 0, &Ret);
        #endif
        }

        if ((PmuGpioConfig->InputWakeReqEn == 1U))
        {
            TT_PMU->WRER |= Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->WRER & Num), Num, &Ret);
        #endif
        }
        else
        {
            TT_PMU->WRER &= ~Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->WRER & Num), 0, &Ret);
        #endif
        }

        if ((PmuGpioConfig->InputPullDownEn == 1U))
        {
            TT_PMU->PDR |= Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->PDR & Num), Num, &Ret);
        #endif
        }
        else
        {
            TT_PMU->PDR &= ~Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->PDR & Num), 0, &Ret);
        #endif
        }

        if ((PmuGpioConfig->InputPullUpEn == 1U))
        {
            TT_PMU->PUR |= Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->PUR & Num), Num, &Ret);
        #endif
        }
        else
        {
            TT_PMU->PUR &= ~Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->PUR & Num), 0, &Ret);
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
* @brief        Mcu_Hw_Pmu_PriConfigGpioOut
* @details      Gpio configuration.
* @param[in]    Num - Gpio number
* @param[in]    PmuGpioConfig - Gpio configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriConfigGpioOut(TT_CONST uint32 Num, TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if ((PmuGpioConfig->OutEn == 1U))
    {
        TT_PMU->OER |= Num;
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->OER & Num), Num, &Ret);
    #endif
        if ((PmuGpioConfig->OutData == 1U))
        {
            TT_PMU->DOR |= Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->DOR & Num), Num, &Ret);
        #endif
        }
        else
        {
            TT_PMU->DOR &= ~Num;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->DOR & Num), 0, &Ret);
        #endif
        }
    }
    else
    {
        TT_PMU->OER &= ~Num;
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Pmu_PriRegReadBack((TT_PMU->OER & Num), 0, &Ret);
    #endif
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_PriConfigHsmDown
* @details      Service to Set MCU Lowe Power Mode
* @param[in]    McuModeSettingConfig - Mcu mode setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriConfigHsmDown(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (McuModeSettingConfig->CipherPowerDownEn == TRUE)
    {
        // need sync hsm with mailbox by user
    #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_22();
    #endif
        (void)Base_Drv_UnlockProtReg();
        TT_SCU->LP_CTL |= TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk;
        (void)Base_Drv_LockProtReg();
    #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_22();
    #endif
    }
    else if (McuModeSettingConfig->HSMPowerDownEn == TRUE)
    {
    #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_23();
    #endif
        (void)Base_Drv_UnlockProtReg();
        TT_SCU->LP_CTL |= TT_SCU_LP_CTL_HSM_PD_Msk;
        (void)Base_Drv_LockProtReg();
    #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_23();
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_PriConfigHsmUp
* @details      Service to Set MCU Lowe Power Mode
* @param[in]    McuModeSettingConfig - Mcu mode setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriConfigHsmUp(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (McuModeSettingConfig->CipherPowerDownEn == TRUE)
    {
    #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_24();
    #endif
        (void)Base_Drv_UnlockProtReg();
        TT_SCU->LP_CTL &= ~(TT_SCU_LP_CTL_HSM_PD_Msk | TT_SCU_LP_CTL_CIP_PD_Msk);
        (void)Base_Drv_LockProtReg();
    #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_24();
    #endif

    }
    else if (McuModeSettingConfig->HSMPowerDownEn == TRUE)
    {
    #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_25();
    #endif
        (void)Base_Drv_UnlockProtReg();
        TT_SCU->LP_CTL &= ~TT_SCU_LP_CTL_CIP_PD_Msk;
        (void)Base_Drv_LockProtReg();
    #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_25();
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_PriMpllStandby
* @details      Use to Standby Mpll
* @param[in]    mpll_standby - current mpll mode
* @param[in]    BusClk - current bus clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriMpllStandby(boolean mpll_standby, uint32 *BusClk)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* pll mode */
    if (mpll_standby == FALSE)
    {
        Ret = Mcu_Hw_Clk_GetBus(BusClk);
        MCAL_INSTRUCTION_SYNC_BARRIER();

        /* MPLL Bypass */
        TT_SCU->MPLL_CTL |= TT_SCU_MPLL_CTL_BYPASS_Msk;

        /* MPLL Stand by */
        TT_SCU->MPLL_CTL |= TT_SCU_MPLL_CTL_STANDBY_Msk;

    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->MPLL_CTL & (TT_SCU_MPLL_CTL_BYPASS_Msk | TT_SCU_MPLL_CTL_STANDBY_Msk)), (TT_SCU_MPLL_CTL_BYPASS_Msk | TT_SCU_MPLL_CTL_STANDBY_Msk), &Ret);
    #endif
        /* config fcu read timer */
        if ((TT_SCU->CGU_CLK_SEL & TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Msk) > 0)
        {
            (void)Mcu_Hw_Misc_FcuTimingConfig(Mcu_PubClkInfo.IHOClk);
        }
        else
        {
            (void)Mcu_Hw_Misc_FcuTimingConfig(Mcu_PubClkInfo.ECOClk);
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Pmu_PriMpllActive
* @details      Use to active Mpll
* @param[in]    mpll_standby - current mpll mode
* @param[in]    BusClk - current bus clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriMpllActive(boolean mpll_standby, uint32 BusClk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
    uint32 TimeoutTicks = 0;
    uint32 CurrentTicks = 0;
    uint32 ElapsedTicks = 0;
    uint32 TempTicks = 0;
#else
    uint32 TimeoutCount = 0;
#endif

    if (mpll_standby == FALSE)
    {
        /* config fcu read timer */
        (void)Mcu_Hw_Misc_FcuTimingConfig(BusClk);

        TT_SCU->MPLL_CTL  |= TT_SCU_MPLL_CTL_BYPASS_Msk;
        TT_SCU->MPLL_CTL &= ~TT_SCU_MPLL_CTL_STANDBY_Msk;
        /* Wait PLL to be locked or stable */
#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
        (void)Base_Drv_Timer_MicrosToTicks(MCU_MAX_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
#endif
        while ((TT_SCU->MPLL_CTL & (TT_SCU_MPLL_CTL_LOCK_Msk)) == 0)
        {
        #if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
            (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&TempTicks);
            ElapsedTicks += TempTicks;
            if (ElapsedTicks >= TimeoutTicks)
            {
                Ret = TT_RET_STATUS_TIMEOUT_ERR;
                break;
            }
        #else
            if(TimeoutCount++ > MCU_MAX_TIMEOUT_DURATION)
            {
                Ret = TT_RET_STATUS_TIMEOUT_ERR;
                break;
            }
        #endif
            else
            {
                /* nothing */
            }
        }
#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
        if(Ret == TT_RET_SUCCESS)
#endif
        {
            /* Clear PLL Stand by */
            TT_SCU->MPLL_CTL &= ~TT_SCU_MPLL_CTL_BYPASS_Msk;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->MPLL_CTL & TT_SCU_MPLL_CTL_BYPASS_Msk), 0, &Ret);
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
* @brief        Mcu_Hw_Pmu_PriEpllStandby
* @details      Use to Standby Mpll
* @param[in]    mpll_standby - current epll mode
* @return
* @pre
*/
static void Mcu_Hw_Pmu_PriEpllStandby(boolean mpll_standby)
{
    /* pll mode */
    if (mpll_standby == FALSE)
    {
        MCAL_INSTRUCTION_SYNC_BARRIER();
       /* EPLL Bypass */
        TT_SCU->EPLL_CTL |= TT_SCU_EPLL_CTL_BYPASS_Msk;

        /* EPLL Stand by */
        TT_SCU->EPLL_CTL |= TT_SCU_EPLL_CTL_STANDBY_Msk;
    }
    else
    {
        /* do nothing */
    }
}

/**
* @brief        Mcu_Hw_Pmu_PriEpllActive
* @details      Use to active Mpll
* @param[in]    mpll_standby - current epll mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Pmu_PriEpllActive(boolean mpll_standby)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
    uint32 TimeoutTicks = 0;
    uint32 CurrentTicks = 0;
    uint32 ElapsedTicks = 0;
    uint32 TempTicks = 0;
#else
    uint32 TimeoutCount = 0;
#endif

    if (mpll_standby == FALSE)
    {
        TT_SCU->EPLL_CTL  |= TT_SCU_EPLL_CTL_BYPASS_Msk;
        TT_SCU->EPLL_CTL &= ~TT_SCU_EPLL_CTL_STANDBY_Msk;
        /* Wait PLL to be locked or stable */
    #if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
        (void)Base_Drv_Timer_MicrosToTicks(MCU_MAX_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
    #endif
        while ((TT_SCU->EPLL_CTL & (TT_SCU_EPLL_CTL_LOCK_Msk)) == 0)
        {
        #if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
            (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&TempTicks);
            ElapsedTicks += TempTicks;
            if (ElapsedTicks >= TimeoutTicks)
            {
                Ret = TT_RET_STATUS_TIMEOUT_ERR;
                break;
            }
        #else
            if(TimeoutCount++ > MCU_MAX_TIMEOUT_DURATION)
            {
               Ret = TT_RET_STATUS_TIMEOUT_ERR;
                break;
            }
        #endif
            else
            {
                /* nothing */
            }
        }
#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
        if(Ret == TT_RET_SUCCESS)
#endif
        {
            /* Clear PLL Stand by */
            TT_SCU->EPLL_CTL &= ~TT_SCU_EPLL_CTL_BYPASS_Msk;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Pmu_PriRegReadBack((TT_SCU->EPLL_CTL & TT_SCU_EPLL_CTL_BYPASS_Msk), 0, &Ret);
        #endif
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Pmu_PriRegReadBack
* @details       Ppu Register Read Back
* @param[in]     ActualValue - Actual Value
* @param[in]     TargetValue - Target Value
* @param[out]    Ret - TT_RET_SUCCESS - success
                 Others - fail
* @return        void
* @retval
* @pre
*/
LOCAL_INLINE void Mcu_Hw_Pmu_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret)
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
#endif
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE_FAST
#include "Mcu_MemMap.h"
ISR(PMU_IRQHandler)
{
    uint32 IrqFlag = 0;
    uint32 IrqRtcflag = 0;

    IrqFlag = TT_PMU->WISR;
    IrqRtcflag = IP_RTC->RTCS;

    if (IrqFlag > 0)
    {
        TT_PMU->WISR = IrqFlag;
    }
    else
    {
        /* do nothing */
    }

    if (IrqRtcflag > 0)
    {
        IP_RTC->RTCS = IrqRtcflag;
    }
    else
    {
        /* do nothing */
    }

    if (NULL_PTR != Pmu_PubCallBackPtr[0])
    {
        Pmu_PubCallBackPtr[0]();
    }
}
#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif
