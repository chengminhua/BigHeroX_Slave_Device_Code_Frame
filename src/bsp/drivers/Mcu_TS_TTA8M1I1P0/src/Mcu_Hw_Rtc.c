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
**  FILENAME     : Mcu_Hw_Rtc.c                                               **
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
extern "C" {
#endif

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcu_Hw_Rtc.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_RTC_VENDOR_ID_C                     1541
#define MCU_HW_RTC_MODULE_ID_C                     101
#define MCU_HW_RTC_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_HW_RTC_AR_RELEASE_MINOR_VERSION_C      4
#define MCU_HW_RTC_AR_RELEASE_PATCH_VERSION_C      0
#define MCU_HW_RTC_SW_MAJOR_VERSION_C              1
#define MCU_HW_RTC_SW_MINOR_VERSION_C              1
#define MCU_HW_RTC_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Rtc.c and Mcu_Hw_Rtc.h file version check */
#if (MCU_HW_RTC_VENDOR_ID_C != MCU_HW_RTC_VENDOR_ID_H)
    #error "Mcu_Hw_Rtc.c and Mcu_Hw_Rtc.h have different vendor id"
#endif
#if (MCU_HW_RTC_MODULE_ID_C != MCU_HW_RTC_MODULE_ID_H)
    #error "Mcu_Hw_Rtc.c and Mcu_Hw_Rtc.h have different module id"
#endif
#if ((MCU_HW_RTC_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_RTC_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_RTC_AR_RELEASE_MINOR_VERSION_C != MCU_HW_RTC_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_RTC_AR_RELEASE_PATCH_VERSION_C != MCU_HW_RTC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Rtc.c and Mcu_Hw_Rtc.h are different"
#endif
#if ((MCU_HW_RTC_SW_MAJOR_VERSION_C != MCU_HW_RTC_SW_MAJOR_VERSION_H) || \
     (MCU_HW_RTC_SW_MINOR_VERSION_C != MCU_HW_RTC_SW_MINOR_VERSION_H) || \
     (MCU_HW_RTC_SW_PATCH_VERSION_C != MCU_HW_RTC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Rtc.c and Mcu_Hw_Rtc.h are different"
#endif

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Function                                      **
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define MCU_START_SEC_CODE_SLOW
#include "Mcu_MemMap.h"
/**
* @brief         Mcu_Hw_Rtc_Init
* @details       Initialize Rtc
* @param[in]     RtcConfig - Rtc configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Rtc_Init(TT_CONST Rtc_ConfigType * TT_CONST RtcConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 u32RtcReg = 0;

    TT_ParaCheck((RtcConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    TT_ParaCheck((RtcConfig != NULL_PTR)&&(RtcConfig->Rtc32FrequencyDivision != TRUE)&&(RtcConfig->Rtc32FrequencyDivision != FALSE), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((RtcConfig != NULL_PTR)&&(RtcConfig->RtcApiEnable != TRUE)&&(RtcConfig->RtcApiEnable != FALSE), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((RtcConfig != NULL_PTR)&&(RtcConfig->RtcApiInterruptEnable != TRUE)&&(RtcConfig->RtcApiInterruptEnable != FALSE), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((RtcConfig != NULL_PTR)&&(RtcConfig->RtcOverFlowEnable != TRUE)&&(RtcConfig->RtcOverFlowEnable != FALSE), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((RtcConfig != NULL_PTR)&&(RtcConfig->RtcOverFlowInterruptEnable != TRUE)&&(RtcConfig->RtcOverFlowInterruptEnable != FALSE), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((RtcConfig != NULL_PTR)&&(RtcConfig->RtcMatchInterruptEnable != TRUE)&&(RtcConfig->RtcMatchInterruptEnable != FALSE), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((RtcConfig != NULL_PTR)&&(RtcConfig->RtcWakeupModeEnable != TRUE)&&(RtcConfig->RtcWakeupModeEnable != FALSE), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        u32RtcReg = ((uint32)RtcConfig->Rtc32FrequencyDivision << TT_RTC_RTCC_DIV32EN_Pos) | \
                ((uint32)RtcConfig->RtcApiEnable  << TT_RTC_RTCC_APIEN_Pos) | \
                ((uint32)RtcConfig->RtcApiInterruptEnable << TT_RTC_RTCC_APIIE_Pos) | \
                ((uint32)RtcConfig->RtcOverFlowEnable << TT_RTC_RTCC_ROVREN_Pos) | \
                ((uint32)RtcConfig->RtcOverFlowInterruptEnable << TT_RTC_RTCC_ROVRIE_Pos) | \
                ((uint32)RtcConfig->RtcMatchInterruptEnable << TT_RTC_RTCC_RTCIE_Pos) | \
                ((uint32)RtcConfig->RtcWakeupModeEnable << TT_RTC_RTCC_WAKEUP_EN_Pos);

        IP_RTC->RTCC = u32RtcReg;
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((IP_RTC->RTCC != u32RtcReg), TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_Hw_Rtc_Start
* @details      Start Rtc.
* @param[in]    RtcValue - Rtc comparison values
* @param[in]    ApiValue - The period value of the Rtc interval
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Rtc_Start(TT_CONST uint32 RtcValue, TT_CONST uint32 ApiValue)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((RtcValue < 4), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck((ApiValue < 4), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        IP_RTC->APIVAL = ApiValue;
        IP_RTC->RTCVAL = RtcValue;
        IP_RTC->RTCC |= TT_RTC_RTCC_CNTEN_Msk;
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((IP_RTC->APIVAL != ApiValue), TT_RET_OPT_REG_ERR, &Ret);
        TT_ParaCheck((IP_RTC->RTCVAL != RtcValue), TT_RET_OPT_REG_ERR, &Ret);
        TT_ParaCheck(((IP_RTC->RTCC&TT_RTC_RTCC_CNTEN_Msk) != TT_RTC_RTCC_CNTEN_Msk), TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Rtc_GetStatue
* @details      Get Rtc status.
* @param[out]   Status - Status of Rtc
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Rtc_GetState(uint32 *Statue)
{
    TT_RetType Ret = 0;

    TT_ParaCheck((Statue == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        *Statue = IP_RTC->RTCS;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Rtc_Clear
* @details      Clear Rtc register.
* @param[in]    flag - Reset value of the register
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Rtc_Clear(TT_CONST uint32 flag)
{
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;

    IP_RTC->RTCS = flag;

    return Ret;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
