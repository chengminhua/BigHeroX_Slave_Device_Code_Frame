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
**  FILENAME     : Mcu_Hw_Clk.c                                               **
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
#define MCU_HW_CLK_VENDOR_ID_C                     1541
#define MCU_HW_CLK_MODULE_ID_C                     101
#define MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_C      4
#define MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_C      0
#define MCU_HW_CLK_SW_MAJOR_VERSION_C              1
#define MCU_HW_CLK_SW_MINOR_VERSION_C              1
#define MCU_HW_CLK_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Clk.c and Mcu_Hw_Clk.h file version check */
#if (MCU_HW_CLK_VENDOR_ID_C != MCU_HW_CLK_VENDOR_ID_H)
    #error "Mcu_Hw_Clk.c and Mcu_Hw_Clk.h have different vendor id"
#endif
#if (MCU_HW_CLK_MODULE_ID_C != MCU_HW_CLK_MODULE_ID_H)
    #error "Mcu_Hw_Clk.c and Mcu_Hw_Clk.h have different module id"
#endif
#if ((MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_C != MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_C != MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Clk.c and Mcu_Hw_Clk.h are different"
#endif
#if ((MCU_HW_CLK_SW_MAJOR_VERSION_C != MCU_HW_CLK_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_SW_MINOR_VERSION_C != MCU_HW_CLK_SW_MINOR_VERSION_H) || \
     (MCU_HW_CLK_SW_PATCH_VERSION_C != MCU_HW_CLK_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Clk.c and Mcu_Hw_Clk.h are different"
#endif

/* Mcu_Hw_Clk.c and Mcu_Hw_Misc.h file version check */
#if (MCU_HW_CLK_VENDOR_ID_C != MCU_HW_MISC_VENDOR_ID_H)
    #error "Mcu_Hw_Clk.c and Mcu_Hw_Misc.h have different vendor id"
#endif
#if (MCU_HW_CLK_MODULE_ID_C != MCU_HW_MISC_MODULE_ID_H)
    #error "Mcu_Hw_Clk.c and Mcu_Hw_Misc.h have different module id"
#endif
#if ((MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_C != MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_C != MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Clk.c and Mcu_Hw_Misc.h are different"
#endif
#if ((MCU_HW_CLK_SW_MAJOR_VERSION_C != MCU_HW_MISC_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_SW_MINOR_VERSION_C != MCU_HW_MISC_SW_MINOR_VERSION_H) || \
     (MCU_HW_CLK_SW_PATCH_VERSION_C != MCU_HW_MISC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Clk.c and Mcu_Hw_Misc.h are different"
#endif

/* Mcu_Hw_Clk.c and Mcu_Hw_Cmu.h file version check */
#if (MCU_HW_CLK_VENDOR_ID_C != MCU_HW_CMU_VENDOR_ID_H)
    #error "Mcu_Hw_Clk.c and Mcu_Hw_Cmu.h have different vendor id"
#endif
#if (MCU_HW_CLK_MODULE_ID_C != MCU_HW_CMU_MODULE_ID_H)
    #error "Mcu_Hw_Clk.c and Mcu_Hw_Cmu.h have different module id"
#endif
#if ((MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_CMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_C != MCU_HW_CMU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_C != MCU_HW_CMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Clk.c and Mcu_Hw_Cmu.h are different"
#endif
#if ((MCU_HW_CLK_SW_MAJOR_VERSION_C != MCU_HW_CMU_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_SW_MINOR_VERSION_C != MCU_HW_CMU_SW_MINOR_VERSION_H) || \
     (MCU_HW_CLK_SW_PATCH_VERSION_C != MCU_HW_CMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Clk.c and Mcu_Hw_Cmu.h are different"
#endif

#if (MCU_HW_CLK_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
    #error "Mcu_Hw_Clk.c and Mcu_Hw_Misc.h have different vendor id"
#endif
#if ((MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Clk.c and Mcu_Hw_Misc.h are different"
#endif
#if ((MCU_HW_CLK_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
     (MCU_HW_CLK_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Clk.c and Mcu_Hw_Misc.h are different"
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

#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock config information */
Mcu_Hw_ClkInfoType Mcu_PubClkInfo = {0};

#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                         Private Function Declaration
******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
* @brief        Mcu_Hw_Clk_PriGetPByClk
* @details      Get PTmp By Clk in pll
* @param[in]    PllClock: the dest pll clock
* @param[in]    PTmp: Pll P Param
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Clk_PriGetPByClk(uint32 PllClock, uint32 *PTmp);
/**
* @brief        Mcu_Hw_Clk_PriCovertPTmp
* @details      Covert PTmp to P
* @param[in]    PTmp:
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static uint32 Mcu_Hw_Clk_PriCovertPTmp(uint32 PTmp);

/**
* @brief        Mcu_Hw_Clk_PriMpllFindNMP
* @details      find the dest N M P paras in pll config
* @param[in]    PllClock: the dest pll clock
* @param[in]    OscClk: the dest Osc clock
* @param[in]    PPtr: the dest P
* @param[in]    MsPtr: the dest Ms
* @param[in]    Nsptr: the dest Ns
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Clk_PriMpllFindNMP(uint32 PllClock, uint32 OscClk, uint32 *PPtr, uint32 *MsPtr, uint32 *Nsptr);

/**
* @brief        Mcu_Hw_Clk_PriEPllConfig
* @details      Epll configuration
* @param[in]    PllClock: the dest pll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Clk_PriEPllConfig (TT_CONST uint32 PllClock);

/**
* @brief        Mcu_Hw_Clk_PriMpllSwitch
* @details      Mcu Main Pll Switch
* @param[in]    PllClock - the dest pll clock (E:240000000)
* @param[in]    SysClk - system clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          USE_CMU_MODULE, if Cmu was used, need close all cmu before switch PLL
*/
static TT_RetType Mcu_Hw_Clk_PriMpllSwitch(TT_CONST uint32 PllClock,TT_CONST uint32 SysClk);

#if defined(USE_CAN_MODULE) && (USE_CAN_MODULE == STD_ON)
/**
* @brief        Mcu_Hw_Clk_PriCanPllConfig
* @details      Can pll configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Clk_PriCanPllConfig (void);
#endif

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Clk_PriRegReadBack
* @details       Ppu Register Read Back
* @param[in]     ActualValue - Actual Value
* @param[in]     TargetValue - Target Value
* @param[out]    Ret - TT_RET_SUCCESS - success
                 Others - fail
* @return        void
* @retval
* @pre
*/
LOCAL_INLINE void Mcu_Hw_Clk_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret);
#endif
/******************************************************************************
*                         Public Functions
******************************************************************************/

/**
* @brief        Mcu_Hw_Clk_StopModules
* @details      Mcu control module clk stop
* @param[in]    Type - The Module will be clock stop
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_StopModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32  offSet = 0U, pos = 0U;
#if (TT_SAFETY == STD_ON)
    uint32 offSetBak = 0U, posBak = 0U;
#endif

    TT_ParaCheck(!MCU_CLK_CONTROL_TYPE_ASSERT(Type), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        offSet = TT_SCU_CLK_STOP_OFFSET + (((uint32)Type / 32U) * 0x4);
        pos = (uint32)Type - (((uint32)Type / 32U) * 32U);
    #if (TT_SAFETY == STD_ON)
        offSetBak = TT_SCU_CLK_STOP_OFFSET + (((uint32)Type / 32U) * 0x4);
        posBak = (uint32)Type - (((uint32)Type / 32U) * 32U);
        if ((offSet == offSetBak) && (pos == posBak))
        {
    #endif
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01();
        #endif
            MCAL_DATA_SYNC_BARRIER();

            (void)Base_Drv_UnlockProtReg();
            (*(volatile uint32 *)(TT_SCU_BASE+offSet)) |= (uint32)((uint32)1U << pos);
            (void)Base_Drv_LockProtReg();

            MCAL_DATA_SYNC_BARRIER();

    #if (TT_SAFETY == STD_ON)
            if (((*(volatile uint32 *)(TT_SCU_BASE+offSet)) & ((uint32)((uint32)1U << pos))) > 0U)
            {
                Ret = TT_RET_SUCCESS;
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
            }
        }
        else
        {
            Ret = TT_RET_STATUS_ERR;
        }
    #endif
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01();
        #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_StartModules
* @details      Mcu control module clk start
* @param[in]    Type - The Module will be clock start
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_StartModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 offSet = 0, pos = 0;
#if (TT_SAFETY == STD_ON)
    uint32 offSetBak = 0U, posBak = 0U;
#endif
    TT_ParaCheck((!MCU_CLK_CONTROL_TYPE_ASSERT(Type)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        offSet = TT_SCU_CLK_STOP_OFFSET + (((uint32)Type / 32U) * 0x4);
        pos = (uint32)Type - (((uint32)Type / 32U) * 32U);
    #if (TT_SAFETY == STD_ON)
        offSetBak = TT_SCU_CLK_STOP_OFFSET + (((uint32)Type / 32U) * 0x4);
        posBak = (uint32)Type - (((uint32)Type / 32U) * 32U);
        if ((offSet == offSetBak) && (pos == posBak))
        {
    #endif
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_02();
        #endif
            MCAL_DATA_SYNC_BARRIER();

            (void)Base_Drv_UnlockProtReg();
            (*(volatile uint32 *)(TT_SCU_BASE+offSet)) &= ~(uint32)((uint32)1U<<pos);
            (void)Base_Drv_LockProtReg();

            MCAL_DATA_SYNC_BARRIER();

    #if (TT_SAFETY == STD_ON)
            if (((*(volatile uint32 *)(TT_SCU_BASE+offSet)) & ((uint32)((uint32)1U << pos))) == 0U)
            {
                Ret = TT_RET_SUCCESS;
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
            }
        }
        else
        {
            Ret = TT_RET_STATUS_ERR;
        }
    #endif
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_02();
        #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_StatusModules
* @details      Mcu get module clk status
* @param[in]    Type - The Module will be get the status
* @param[out]   Status - the clock status of this module
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_StatusModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type, boolean *Status)
{
    uint32 offSet = 0U, pos = 0U;
    TT_RetType Ret = 0U;
    uint32 Tmp = 0U;

//    TT_ParaCheck(((!MCU_CLK_CONTROL_TYPE_ASSERT(Type))), TT_RET_PARAM_ENUM_ERR, &Ret);
//    TT_ParaCheck(Status == NULL_PTR, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        offSet = TT_SCU_CLK_STOP_OFFSET + (((uint32)Type / 32U) * 0x4);
        pos = (uint32)((uint32)Type - (((uint32)Type / 32U) * 32U));
        Tmp = (uint32)((uint32)1U << pos);
        if (((*(volatile uint32 *)(TT_SCU_BASE+offSet)) & Tmp) > 0)
        {
            *Status =  FALSE;
        }
        else
        {
            *Status =  TRUE;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_SleepModules
* @details      Mcu control module clk sleep
* @param[in]    Type - The Module will be clock sleep
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_SleepModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 offSet = 0, pos = 0;
#if (TT_SAFETY == STD_ON)
    uint32 offSetBak = 0U, posBak = 0U;
#endif
    TT_ParaCheck(((!MCU_CLK_SLEEP_TYPE_ASSERT(Type))), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        offSet = TT_SCU_CLK_SLEEP_OFFSET + (((uint32)Type / 32U) * 0x4U);
        pos = (uint32)Type - (((uint32)Type / 32U) * 32U);
    #if (TT_SAFETY == STD_ON)
        offSetBak = TT_SCU_CLK_SLEEP_OFFSET + (((uint32)Type / 32U) * 0x4U);
        posBak = (uint32)Type - (((uint32)Type / 32U) * 32U);
        if ((offSet == offSetBak) && (pos == posBak))
        {
    #endif
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_03();
        #endif
            MCAL_DATA_SYNC_BARRIER();

            (void)Base_Drv_UnlockProtReg();
            (*(volatile uint32 *)(TT_SCU_BASE+offSet)) |= (uint32)((uint32)1U<<pos);
            (void)Base_Drv_LockProtReg();

            MCAL_DATA_SYNC_BARRIER();

    #if (TT_SAFETY == STD_ON)
            if (((*(volatile uint32 *)(TT_SCU_BASE+offSet)) & ((uint32)((uint32)1U << pos))) > 0U)
            {
                Ret = TT_RET_SUCCESS;
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
            }
        }
        else
        {
            Ret = TT_RET_STATUS_ERR;
        }
    #endif
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_03();
        #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_AwakenModules
* @details      Mcu control module clk awaken
* @param[in]    Type - The Module will be clock sleep
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_AwakenModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 offSet = 0, pos = 0;
#if (TT_SAFETY == STD_ON)
    uint32 offSetBak = 0U, posBak = 0U;
#endif
    TT_ParaCheck(((!MCU_CLK_SLEEP_TYPE_ASSERT(Type))), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        offSet = TT_SCU_CLK_SLEEP_OFFSET + (((uint32)Type / 32U) * 0x4U);
        pos = (uint32)Type - (((uint32)Type / 32U) * 32U);
    #if (TT_SAFETY == STD_ON)
        offSetBak = TT_SCU_CLK_SLEEP_OFFSET + (((uint32)Type / 32U) * 0x4U);
        posBak = (uint32)Type - (((uint32)Type / 32U) * 32U);
        if ((offSet == offSetBak) && (pos == posBak))
        {
    #endif
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_04();
        #endif
            MCAL_DATA_SYNC_BARRIER();

            (void)Base_Drv_UnlockProtReg();
            (*(volatile uint32 *)(TT_SCU_BASE+offSet)) &= ~((uint32)((uint32)1U<<pos));
            (void)Base_Drv_LockProtReg();

            MCAL_DATA_SYNC_BARRIER();

    #if (TT_SAFETY == STD_ON)
            if (((*(volatile uint32 *)(TT_SCU_BASE+offSet)) & ((uint32)((uint32)1U << pos))) == 0U)
            {
                Ret = TT_RET_SUCCESS;
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
            }
        }
        else
        {
            Ret = TT_RET_STATUS_ERR;
        }
    #endif
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_04();
        #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_PeriStopModules
* @details      mcu Stop Peril module(can/lin)
* @param[in]    Type - The Module will be clock stop
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_PeriStopModules(TT_CONST TT_SCU_PERI_STOP_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((!MCU_CLK_PERISTOP_TYPE_ASSERT(Type))), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
    #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00();
    #endif
        MCAL_DATA_SYNC_BARRIER();

        (void)Base_Drv_UnlockProtReg();
        (*(volatile uint32 *)(TT_SCU_BASE+TT_SCU_PERI_STOP_OFFSET)) |= (uint32)((uint32)1U << (uint32)Type);
        (void)Base_Drv_LockProtReg();

        MCAL_DATA_SYNC_BARRIER();

    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Clk_PriRegReadBack(((*(volatile uint32 *)(TT_SCU_BASE+TT_SCU_PERI_STOP_OFFSET)) & (uint32)((uint32)1U << (uint32)Type)), (uint32)((uint32)1U << (uint32)Type), &Ret);
    #endif
    #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00();
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_GetMPllStatus
* @details      This service provides the lock status of the MPLL.
* @param[out]   Status - Status of MPll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_GetMPllStatus(uint8 *Status)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((Status == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if(TT_REG32_GET_FLD(TT_SCU->MPLL_CTL, TT_SCU_MPLL_CTL_BYPASS) == 0U)
        {
            if((TT_SCU->MPLL_CTL & TT_SCU_MPLL_CTL_LOCK_Msk) > 0U)
            {
                *Status = (uint8)MCU_CLK_PLL_LOCKED;
            }
            else
            {
                *Status = (uint8)MCU_CLK_PLL_UNLOCKED;
            }
        }
        else
        {
            *Status = (uint8)MCU_CLK_PLL_LOCKED;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_GetEPllStatus
* @details      This service provides the lock status of the EPLL.
* @param[out]   Status - Status of EPll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_GetEPllStatus(uint8 *Status)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((Status == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if(TT_REG32_GET_FLD(TT_SCU->EPLL_CTL, TT_SCU_EPLL_CTL_BYPASS) == 0U)
        {
            if((TT_SCU->EPLL_CTL & TT_SCU_EPLL_CTL_LOCK_Msk) > 0U)
            {
                *Status = (uint8)MCU_CLK_PLL_LOCKED;
            }
            else
            {
                *Status = (uint8)MCU_CLK_PLL_UNLOCKED;
            }
        }
        else
        {
            *Status = (uint8)MCU_CLK_PLL_LOCKED;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_MpllConfig
* @details      Mcu Main Pll Config
* @param[in]    PllClock - the dest pll clock (E:240000000)
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          USE_CMU_MODULE, if Cmu was used, need close all cmu before switch PLL
*/
TT_RetType Mcu_Hw_Clk_MpllConfig (TT_CONST uint32 PllClock)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 SysClk = 0;
#if (TT_SAFETY == STD_ON)
    uint32 TmpClk = 0U;
    TT_RetType RetBak = TT_RET_SUCCESS;
#endif
    TT_ParaCheck(((PllClock > MCU_PLL_CLK)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Hw_Clk_GetSystem(&SysClk);

        if (TT_RET_SUCCESS == Ret)
        {
            if (SysClk == PllClock)
            {
                Ret = TT_RET_SUCCESS;
            }
            /* using IHO 48M */
            else if (PllClock == Mcu_PubClkInfo.IHOClk)
            {
                TT_SCU->MPLL_CTL    |= TT_SCU_MPLL_CTL_BYPASS_Msk;
                TT_SCU->MPLL_CTL    |= TT_SCU_MPLL_CTL_STANDBY_Msk;
            #ifdef USING_OS_AUTOSAROS
                SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_05();
            #endif
                (void)Base_Drv_UnlockProtReg();
                TT_SCU->CLKDIV_CTL0 = Mcu_PubClkInfo.ClkDiv0;
                TT_SCU->CLKDIV_CTL1 = Mcu_PubClkInfo.ClkDiv1;
                TT_SCU->CLKDIV_CTL2 = Mcu_PubClkInfo.ClkDiv2;
                TT_SCU->CGU_CLK_SEL &= ~TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Msk;
                (void)Base_Drv_LockProtReg();
            #ifdef USING_OS_AUTOSAROS
                SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_05();
            #endif
            #if (TT_SAFETY == STD_ON)
                Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL0, Mcu_PubClkInfo.ClkDiv0, &Ret);
                Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL1, Mcu_PubClkInfo.ClkDiv1, &Ret);
                Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL2, Mcu_PubClkInfo.ClkDiv2, &Ret);
                Mcu_Hw_Clk_PriRegReadBack((TT_SCU->MPLL_CTL & (TT_SCU_MPLL_CTL_BYPASS_Msk|TT_SCU_MPLL_CTL_STANDBY_Msk)), (TT_SCU_MPLL_CTL_BYPASS_Msk|TT_SCU_MPLL_CTL_STANDBY_Msk), &Ret);
                Mcu_Hw_Clk_PriRegReadBack((TT_SCU->CGU_CLK_SEL & (TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Msk)), 0, &Ret);
            #endif
            }
            /* using ECO 40M */
            else if (PllClock == Mcu_PubClkInfo.ECOClk)
            {
                TT_SCU->MPLL_CTL    |= TT_SCU_MPLL_CTL_BYPASS_Msk;
                TT_SCU->MPLL_CTL    |= TT_SCU_MPLL_CTL_STANDBY_Msk;
            #ifdef USING_OS_AUTOSAROS
                SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_06();
            #endif
                (void)Base_Drv_UnlockProtReg();
                TT_SCU->CLKDIV_CTL0 = Mcu_PubClkInfo.ClkDiv0;
                TT_SCU->CLKDIV_CTL1 = Mcu_PubClkInfo.ClkDiv1;
                TT_SCU->CLKDIV_CTL2 = Mcu_PubClkInfo.ClkDiv2;
                TT_SCU->CGU_CLK_SEL |= TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Msk;
                (void)Base_Drv_LockProtReg();
            #ifdef USING_OS_AUTOSAROS
                SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_06();
            #endif
            #if (TT_SAFETY == STD_ON)
                Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL0, Mcu_PubClkInfo.ClkDiv0, &Ret);
                Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL1, Mcu_PubClkInfo.ClkDiv1, &Ret);
                Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL2, Mcu_PubClkInfo.ClkDiv2, &Ret);
                Mcu_Hw_Clk_PriRegReadBack((TT_SCU->MPLL_CTL & (TT_SCU_MPLL_CTL_BYPASS_Msk|TT_SCU_MPLL_CTL_STANDBY_Msk)), (TT_SCU_MPLL_CTL_BYPASS_Msk|TT_SCU_MPLL_CTL_STANDBY_Msk), &Ret);
                Mcu_Hw_Clk_PriRegReadBack((TT_SCU->CGU_CLK_SEL & (TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Msk)), TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Msk, &Ret);
            #endif
            }
            else
            {
                Ret = Mcu_Hw_Clk_PriMpllSwitch(PllClock,SysClk);

            #if (TT_SAFETY == STD_ON)
                RetBak = Mcu_Hw_Clk_GetMpll(&TmpClk);
                if ((Ret == TT_RET_SUCCESS) && (RetBak == TT_RET_SUCCESS) && (PllClock == TmpClk))
                {
                    Ret = TT_RET_SUCCESS;
                }
                else
                {
                    Ret = TT_RET_STATUS_CLK_ERR;
                }
            #endif
            }
        #if defined(USE_CAN_MODULE) && (USE_CAN_MODULE == STD_ON)
            if (Ret == TT_RET_SUCCESS)
            {
                Ret = Mcu_Hw_Clk_PriCanPllConfig();
            }
        #endif
            /* resetting timer clk */
            (void)Base_Drv_Uninit();
            (void)Base_Drv_Init();
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
* @brief        Mcu_Hw_Clk_EpllConfig
* @details      Mcu Eth Pll Config
* @param[in]    PllClock - the dest pll clock (E:250000000),0 means Max
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          USE_CMU_MODULE, if Cmu was used, need close all cmu before switch PLL
*/
TT_RetType Mcu_Hw_Clk_EpllConfig (TT_CONST uint32 PllClock)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 EpllClk = 0;

    TT_ParaCheck(((PllClock > MCU_EPLL_CLK)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Hw_Clk_GetEpll(&EpllClk);
        if (TT_RET_SUCCESS == Ret)
        {
            if (EpllClk == PllClock)
            {
                Ret = TT_RET_SUCCESS;
            }
            else if (PllClock == Mcu_PubClkInfo.IHOClk) /* pllout = 48M, use default IHO,do not use EPLL */
            {
                TT_SCU->EPLL_CTL |= TT_SCU_EPLL_CTL_BYPASS_Msk;
                TT_SCU->EPLL_CTL |= TT_SCU_EPLL_CTL_STANDBY_Msk;
            #if (TT_SAFETY == STD_ON)
                Mcu_Hw_Clk_PriRegReadBack((TT_SCU->EPLL_CTL & (TT_SCU_EPLL_CTL_BYPASS_Msk|TT_SCU_EPLL_CTL_STANDBY_Msk)), (TT_SCU_EPLL_CTL_BYPASS_Msk|TT_SCU_EPLL_CTL_STANDBY_Msk), &Ret);
            #endif
            }
            else
            {
                Ret = Mcu_Hw_Clk_PriEPllConfig(PllClock);
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
* @brief        Mcu_Hw_Clk_GetMpll
* @details      Get Mpll clock
* @param[out]   Clk - Mpll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_GetMpll (uint32 *Clk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#ifndef MCU_FPGA_CLK
    uint32 Ns = 0;
    uint32 Ms = 0;
    uint32 Ps = 0;
    uint32 OscClk = 0;
    uint32 EcoClk = 0;
    uint32 ClkTmp = 0;
#endif
#if (TT_SAFETY == STD_ON)
    uint32 NsBak = 0;
    uint32 MsBak = 0;
    uint32 PsBak = 0;
    uint32 ClkTmpBak = 0;
#endif
    TT_ParaCheck(((Clk == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
    #ifdef MCU_FPGA_CLK
        *Clk = MCU_FPGA_CLK;
    #else
        EcoClk = (Mcu_PubClkInfo.ECOClk > 0U) ? Mcu_PubClkInfo.ECOClk : MCU_OSC_ECO_DEFAULT ;
        if (TT_REG32_GET_FLD(TT_SCU->MPLL_CTL, TT_SCU_MPLL_CTL_BYPASS) > 0U) /* mpll osc mode */
        {
            /* ECO clk */
            if ((TT_SCU->CGU_CLK_SEL & TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Msk) > 0U)
            {
                OscClk = EcoClk;
            }
            /* IHO clk */
            else
            {
                OscClk = (Mcu_PubClkInfo.IHOClk > 0U) ? Mcu_PubClkInfo.IHOClk :  MCU_OSC_IHO_DEFAULT;
            }
            *Clk = OscClk;
        }
        else
        {
            Ns = ((TT_SCU->MPLL_CTL >> TT_SCU_MPLL_CTL_NS_Pos) & 0x1FFU);
            Ms = ((TT_SCU->MPLL_CTL >> TT_SCU_MPLL_CTL_MS_Pos) & 0xfU);
            Ps = (uint32)((uint32)1U << (uint32)((TT_SCU->MPLL_CTL >> TT_SCU_MPLL_CTL_FR_Pos) & 0x7U));
            if (Ms != 0U)
            {
                ClkTmp = (Ns * EcoClk) / (Ms * Ps);
            }
            else
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }

            #if (TT_SAFETY == STD_ON)
            NsBak = ((TT_SCU->MPLL_CTL >> TT_SCU_MPLL_CTL_NS_Pos) & 0x1FFU);
            MsBak = ((TT_SCU->MPLL_CTL >> TT_SCU_MPLL_CTL_MS_Pos) & 0xfU);
            PsBak = (uint32)((uint32)1U << (uint32)((TT_SCU->MPLL_CTL >> TT_SCU_MPLL_CTL_FR_Pos) & 0x7U));
            if (MsBak != 0U)
            {
                ClkTmpBak = (NsBak * EcoClk) / (MsBak * PsBak);
            }
            else
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }

            if ((Ret == TT_RET_SUCCESS) && (ClkTmp == ClkTmpBak))
            {
        #endif
                *Clk = ClkTmp;
        #if (TT_SAFETY == STD_ON)
            }
            else
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }
        #endif
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
* @brief        Mcu_Hw_Clk_GetEpll
* @details      Get Epll clock
* @param[out]   Clk - Epll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_GetEpll (uint32 *Clk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#ifndef MCU_FPGA_CLK
    uint32 Ns = 0;
    uint32 Ms = 0;
    uint32 Ps = 0;
    uint32 EcoClk = 0;
    uint32 ClkTmp = 0;
#endif
#if (TT_SAFETY == STD_ON)
    uint32 NsBak = 0;
    uint32 MsBak = 0;
    uint32 PsBak = 0;
    uint32 ClkTmpBak = 0;
#endif
    TT_ParaCheck(((Clk == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
    #ifdef MCU_FPGA_CLK
        *Clk = MCU_FPGA_CLK;
    #else
        EcoClk = (Mcu_PubClkInfo.ECOClk > 0U) ? Mcu_PubClkInfo.ECOClk : MCU_OSC_ECO_DEFAULT ;
    
        if (TT_REG32_GET_FLD(TT_SCU->EPLL_CTL,TT_SCU_EPLL_CTL_STANDBY) > 0U)
        {
            *Clk = MCU_OSC_IHO_DEFAULT;
        }
        else
        {
            Ns = ((TT_SCU->EPLL_CTL >> TT_SCU_EPLL_CTL_NS_Pos) & 0x1FFU);
            Ms = ((TT_SCU->EPLL_CTL >> TT_SCU_EPLL_CTL_MS_Pos) & 0xfU);
            Ps = (uint32)((uint32)1U << (uint32)((TT_SCU->EPLL_CTL >> TT_SCU_EPLL_CTL_FR_Pos) & 0x7U));
            if (Ms != 0U)
            {
                ClkTmp = (Ns * EcoClk) / (Ms * Ps);
            }
            else
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }

        #if (TT_SAFETY == STD_ON)
            NsBak = ((TT_SCU->EPLL_CTL >> TT_SCU_EPLL_CTL_NS_Pos) & 0x1FFU);
            MsBak = ((TT_SCU->EPLL_CTL >> TT_SCU_EPLL_CTL_MS_Pos) & 0xfU);
            PsBak = (uint32)((uint32)1U << (uint32)((TT_SCU->EPLL_CTL >> TT_SCU_EPLL_CTL_FR_Pos) & 0x7U));
            if (MsBak != 0U)
            {
                ClkTmpBak = (NsBak * EcoClk) / (MsBak * PsBak);
            }
            else
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }

            if ((Ret == TT_RET_SUCCESS) && (ClkTmp == ClkTmpBak))
            {
        #endif
                *Clk = ClkTmp;
        #if (TT_SAFETY == STD_ON)
            }
            else
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }
        #endif
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
* @brief        Mcu_Hw_Clk_GetSystem
* @details      Get system clock
* @param[out]   Clk - system clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_GetSystem (uint32 * Clk)
{
    TT_RetType Ret = 0U;

    TT_ParaCheck(((NULL_PTR == Clk)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
    #ifdef MCU_FPGA_CLK
        *Clk = MCU_FPGA_CLK;
    #else
        Ret = Mcu_Hw_Clk_GetMpll(Clk);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_GetBus
* @details      Get bus clock
* @param[out]   Clk - Bus clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          MCU_FPGA_CLK: only for test
*/
TT_RetType Mcu_Hw_Clk_GetBus (uint32 *Clk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#ifndef MCU_FPGA_CLK
    uint32 SystemClk = 0U;
#endif
    TT_ParaCheck(((Clk == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
    #ifdef MCU_FPGA_CLK
        *Clk = MCU_FPGA_CLK;
    #else
        Ret = Mcu_Hw_Clk_GetSystem(&SystemClk);
        if (Ret == TT_RET_SUCCESS)
        {
            *Clk = SystemClk / (TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL0, TT_SCU_CLKDIV_CTL0_DIV_BUS_CFG) + 1);
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

/**
* @brief        Mcu_Hw_Clk_GetPeriph
* @details      Get the dest Peripheral clock
* @param[in]    PeripheralName - the dest Peripheral in Mcu_PeriphNameType
* @param[out]   Result - the dest Peripheral clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          MCU_FPGA_CLK: only for test
*/
TT_RetType Mcu_Hw_Clk_GetPeriph(TT_CONST Mcu_Hw_PeriphNameType PeripheralName, Mcu_PeripheralClockValType *Result)
{
    TT_RetType Ret = 0U;
    TT_RetType Ret1 = 0U;
#ifndef MCU_FPGA_CLK
    uint32 BusClk = 0U;
    uint32 SystemClk = 0U;
#endif
    TT_ParaCheck(((!MCU_CLK_PERIPHNAME_TYPE_ASSERT(PeripheralName))), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck(((Result == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
    #ifdef MCU_FPGA_CLK
        (void)PeripheralName;
        *Result = MCU_FPGA_CLK;
    #else
        Ret = Mcu_Hw_Clk_GetBus(&BusClk);
        Ret1 = Mcu_Hw_Clk_GetSystem(&SystemClk);

        if ((Ret == TT_RET_SUCCESS) && (Ret1 == TT_RET_SUCCESS))
        {
            switch (PeripheralName)
            {
                /* APB0 */
                case MCU_CLOCK_APB0      :  
                case MCU_CLOCK_SCU       :
                case MCU_CLOCK_DBG       :
                case MCU_CLOCK_PPU       :
                    *Result = BusClk / (TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL0, TT_SCU_CLKDIV_CTL0_DIV_PERI0) + 1);
                    break;
                    /* APB1 */
                case MCU_CLOCK_APB1      :
                case MCU_CLOCK_PMU       :
                case MCU_CLOCK_SMPU      :
                case MCU_CLOCK_TIMER     :
                case MCU_CLOCK_WDG       :
                case MCU_CLOCK_CRC       :
                case MCU_CLOCK_UART0     :
                case MCU_CLOCK_UART1     :
                case MCU_CLOCK_I2C0      :
                case MCU_CLOCK_I2C1      :
                case MCU_CLOCK_SENT4     :
                case MCU_CLOCK_SENT5     :
                case MCU_CLOCK_FTM4      :
                case MCU_CLOCK_FTM5      :
                case MCU_CLOCK_IOM       :
                case MCU_CLOCK_SENT2     :
                case MCU_CLOCK_SENT3     :
                    *Result = BusClk / (TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL0,TT_SCU_CLKDIV_CTL0_DIV_PERI1) + 1);
                    break;
                    /* APB2 */
                case MCU_CLOCK_APB2      :
                case MCU_CLOCK_CAN0      :
                case MCU_CLOCK_CAN1      :
                case MCU_CLOCK_CAN2      :
                case MCU_CLOCK_CAN3      :
                case MCU_CLOCK_I3C0      :
                case MCU_CLOCK_GPIO0     :
                case MCU_CLOCK_GPIO1     :
                case MCU_CLOCK_GPIO2     :
                case MCU_CLOCK_FTM2      :
                case MCU_CLOCK_FTM3      :
                case MCU_CLOCK_ADCSENSOR :
                case MCU_CLOCK_UART2     :
                case MCU_CLOCK_UART3     :
                case MCU_CLOCK_SMU       :
                case MCU_CLOCK_GTMREG    :
                case MCU_CLOCK_INTM      :
                    *Result = BusClk / (TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL0,TT_SCU_CLKDIV_CTL0_DIV_PERI2) + 1);
                    break;
                    /* APB3 */
                case MCU_CLOCK_APB3      :
                case MCU_CLOCK_CAN4      :
                case MCU_CLOCK_CAN5      :
                case MCU_CLOCK_CAN6      :
                case MCU_CLOCK_CAN7      :
                case MCU_CLOCK_FTM0      :
                case MCU_CLOCK_FTM1      :
                case MCU_CLOCK_GPIO3     :
                case MCU_CLOCK_GPIO4     :
                case MCU_CLOCK_SENT0     :
                case MCU_CLOCK_SENT1     :
                case MCU_CLOCK_TRIGMUX   :
                case MCU_CLOCK_I2S0      :
                case MCU_CLOCK_SENT6     :
                case MCU_CLOCK_SENT7     :
                case MCU_CLOCK_STCU      :
                    *Result = BusClk / (TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL0, TT_SCU_CLKDIV_CTL0_DIV_PERI3) + 1);
                    break;
                 /* APB4 */
                case MCU_CLOCK_APB4      :
                case MCU_CLOCK_LIN0      :
                case MCU_CLOCK_LIN1      :
                case MCU_CLOCK_LIN2      :
                case MCU_CLOCK_LIN3      :
                case MCU_CLOCK_LIN4      :
                case MCU_CLOCK_LIN5      :
                case MCU_CLOCK_LIN6      :
                case MCU_CLOCK_LIN7      :
                case MCU_CLOCK_EIM       :
                 /* APB5 */
                case MCU_CLOCK_APB5      :
                case MCU_CLOCK_LIN8      :
                case MCU_CLOCK_LIN9      :
                case MCU_CLOCK_LIN10     :
                case MCU_CLOCK_LIN11     :
                case MCU_CLOCK_LIN12     :
                case MCU_CLOCK_LIN13     :
                case MCU_CLOCK_LIN14     :
                case MCU_CLOCK_LIN15     :
                    *Result = BusClk / (TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL0, TT_SCU_CLKDIV_CTL0_DIV_BUS_CFG) + 1);
                    break;
                case MCU_CLOCK_CAN_PE   :
                    if ((TT_SCU->CGU_CLK_SEL & TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Msk) > 0U)
                    {
                        *Result = SystemClk / (TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL1, TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG) + 1);
                    }
                    else
                    {
                        *Result = Mcu_PubClkInfo.ECOClk / (TT_REG32_GET_FLD(TT_SCU->CLKDIV_CTL1, TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG) + 1);
                    }
                    break;
                default   :
                    *Result = 0x00;
                    break;
            }
        }
        else
        {
            Ret = TT_RET_STATUS_CLK_ERR;
        }
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE_SLOW
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_Hw_Clk_Init
* @details      Service to initalize the PLL & other MCU clock options
* @param[in]    ClockCfgPtr - Clock setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Clk_Init(TT_CONST Mcu_Hw_ClockSettingConfigType * TT_CONST ClockCfgPtr)
{
    uint32 ClkDivTmp = 0U;

    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((ClockCfgPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->CoreClk > MCU_CORE_CLK_MAX/2) && (ClockCfgPtr->BusClkHalfCoreEnable == FALSE), \
                 TT_RET_STATUS_CLK_ERR, &Ret);

    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->BusClkHalfCoreEnable != TRUE) && (ClockCfgPtr->BusClkHalfCoreEnable != FALSE),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->APB0ClkHalfBusEnable != TRUE) && (ClockCfgPtr->APB0ClkHalfBusEnable != FALSE),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->APB1ClkHalfBusEnable != TRUE) && (ClockCfgPtr->APB1ClkHalfBusEnable != FALSE),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->APB2ClkHalfBusEnable != TRUE) && (ClockCfgPtr->APB2ClkHalfBusEnable != FALSE),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->APB3ClkHalfBusEnable != TRUE) && (ClockCfgPtr->APB3ClkHalfBusEnable != FALSE),TT_RET_PARAM_CONFIG_ERR, &Ret);

    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->Sm4ClkDiv > TT_SCU_CLK_CIPHER_DIV_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->SkaClkDiv > TT_SCU_CLK_CIPHER_DIV_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->HashClkDiv > TT_SCU_CLK_CIPHER_DIV_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->Sm4ClkRandEn != TRUE) && (ClockCfgPtr->Sm4ClkRandEn != FALSE),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->SkaClkRandEn != TRUE) && (ClockCfgPtr->SkaClkRandEn != FALSE),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->HashClkRandEn != TRUE) && (ClockCfgPtr->HashClkRandEn != FALSE),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->EcoDivLP > TT_SCU_CLK_CIPHER_DIV_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);

    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->Sm4ClkRand > MCU_CRYPTO_CLK_RAND_32_1),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->SkaClkRand > MCU_CRYPTO_CLK_RAND_32_1),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->HashClkRand > MCU_CRYPTO_CLK_RAND_32_1),TT_RET_PARAM_CONFIG_ERR, &Ret);

    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->IhoClk != MCU_OSC_IHO_DEFAULT),TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((ClockCfgPtr != NULL_PTR) && (ClockCfgPtr->EcoClk != MCU_OSC_ECO_DEFAULT),TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        ClkDivTmp = (uint32)((uint32)(ClockCfgPtr->BusClkHalfCoreEnable) << TT_SCU_CLKDIV_CTL0_DIV_BUS_CFG_Pos) | \
                    ((uint32)(ClockCfgPtr->APB0ClkHalfBusEnable) << TT_SCU_CLKDIV_CTL0_DIV_PERI0_Pos)   | \
                    ((uint32)(ClockCfgPtr->APB1ClkHalfBusEnable) << TT_SCU_CLKDIV_CTL0_DIV_PERI1_Pos)   | \
                    ((uint32)(ClockCfgPtr->APB2ClkHalfBusEnable) << TT_SCU_CLKDIV_CTL0_DIV_PERI2_Pos)   | \
                    ((uint32)(ClockCfgPtr->APB3ClkHalfBusEnable) << TT_SCU_CLKDIV_CTL0_DIV_PERI3_Pos)   | \
                    ((uint32)(ClockCfgPtr->Sm4ClkDiv - 1) <<  TT_SCU_CLKDIV_CTL0_DIV_SM4_CFG_Pos)       | \
                    ((uint32)(ClockCfgPtr->SkaClkDiv - 1) << TT_SCU_CLKDIV_CTL0_DIV_SKA_CFG_Pos)        | \
                    ((uint32)(ClockCfgPtr->HashClkDiv - 1) << TT_SCU_CLKDIV_CTL0_DIV_HASH_CFG_Pos)      | \
                    ((uint32)(ClockCfgPtr->EcoDivLP -1) << TT_SCU_CLKDIV_CTL0_DIV_ECO_CFG_Pos);

        Mcu_PubClkInfo.ClkDiv0 = ClkDivTmp;

        TT_SCU->CLK_RAND = (uint32)(((uint32)ClockCfgPtr->Sm4ClkRand << TT_SCU_CLK_RAND_SM4_RAND_SEL_Pos) | ((uint32)ClockCfgPtr->Sm4ClkRandEn << TT_SCU_CLK_RAND_SM4_RAND_EN_Pos))       | \
                            (((uint32)ClockCfgPtr->SkaClkRand << TT_SCU_CLK_RAND_SKA_RAND_SEL_Pos) | ((uint32)ClockCfgPtr->SkaClkRandEn << TT_SCU_CLK_RAND_SKA_RAND_EN_Pos))      | \
                            (((uint32)ClockCfgPtr->HashClkRand << TT_SCU_CLK_RAND_HASH_RAND_SEL_Pos) | ((uint32)ClockCfgPtr->HashClkRandEn << TT_SCU_CLK_RAND_HASH_RAND_EN_Pos));

        ClkDivTmp = 0U;

    #if defined(USE_CAN_MODULE) && (USE_CAN_MODULE == STD_ON)
    #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_07();
    #endif
        if (ClockCfgPtr->CanPEUserPLLEnable == TRUE)
        {
            (void)Base_Drv_UnlockProtReg();
            TT_SCU->CGU_CLK_SEL |= TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Msk;
            (void)Base_Drv_LockProtReg();
        }
        else
        {
            (void)Base_Drv_UnlockProtReg();
            TT_SCU->CGU_CLK_SEL &= ~TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Msk;
            (void)Base_Drv_LockProtReg();
        }
    #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_07();
    #endif
        Mcu_PubClkInfo.CanPeClk = ClockCfgPtr->CanPeClk;
    #endif

    #if defined(USE_I3C_MODULE) && (USE_I3C_MODULE == STD_ON)
        TT_ParaCheck((ClockCfgPtr->I3c0ClkDiv > TT_SCU_CLK_DIV_CTL1_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
            ClkDivTmp |= (ClockCfgPtr->I3c0ClkDiv - 1) << TT_SCU_CLKDIV_CTL1_DIV_I3C0_CFG_Pos;
        }

    #endif

    #if defined(USE_ETH_MODULE) && (USE_ETH_MODULE == STD_ON)
        TT_ParaCheck((ClockCfgPtr->EpllClockConfig != NULL_PTR) && \
            (ClockCfgPtr->EpllClockConfig->EmacRxTxClkDiv > TT_SCU_CLK_DIV_CTL1_EMAC_TXRX_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
        TT_ParaCheck((ClockCfgPtr->EpllClockConfig != NULL_PTR) && \
            (ClockCfgPtr->EpllClockConfig->EmacRmiiRefClkDiv > TT_SCU_CLK_DIV_CTL1_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
        TT_ParaCheck((ClockCfgPtr->EpllClockConfig != NULL_PTR) && \
            (ClockCfgPtr->EpllClockConfig->EmacPtpRefClkDiv > TT_SCU_CLK_DIV_CTL1_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
        if ((TT_RET_SUCCESS == Ret) && (ClockCfgPtr->EpllClockConfig != NULL_PTR)) 
        {
            ClkDivTmp |= ((ClockCfgPtr->EpllClockConfig->EmacRxTxClkDiv - 1) << TT_SCU_CLKDIV_CTL1_DIV_EMAC_RXTX_CFG_Pos)        | \
                    ((ClockCfgPtr->EpllClockConfig->EmacRmiiRefClkDiv - 1) << TT_SCU_CLKDIV_CTL1_DIV_EMAC_RMII_CFG_Pos)     | \
                    ((ClockCfgPtr->EpllClockConfig->EmacPtpRefClkDiv- 1) << TT_SCU_CLKDIV_CTL1_DIV_EMAC_PTP_REF_CFG_Pos);
        }
    #endif

        Mcu_PubClkInfo.ClkDiv1 |= ClkDivTmp;

    #if defined(USE_SAI_MODULE) && (USE_SAI_MODULE == STD_ON)
        TT_ParaCheck((ClockCfgPtr->I2s0MClkFracDiv > TT_SCU_CLK_DIV_CTL2_FRACTION_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
        TT_ParaCheck((ClockCfgPtr->I2s0MClkIntDiv > TT_SCU_CLK_DIV_CTL2_INT_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
        TT_ParaCheck((ClockCfgPtr->I2s0SClkFracDiv > TT_SCU_CLK_DIV_CTL2_FRACTION_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
        TT_ParaCheck((ClockCfgPtr->I2s0SClkIntDiv > TT_SCU_CLK_DIV_CTL2_INT_MAX),TT_RET_PARAM_CONFIG_ERR, &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
        /* ECO div for i2s */
        Mcu_PubClkInfo.ClkDiv2 = (uint32)((uint32)(ClockCfgPtr->I2s0MClkFracDiv - 1U) << TT_SCU_CLKDIV_CTL2_DIV_I2S0_MCLK_FRAC_Pos ) | \
                   ((uint32)(ClockCfgPtr->I2s0MClkIntDiv - 1U) << TT_SCU_CLKDIV_CTL2_DIV_I2S0_MCLK_INT_Pos)     | \
                   ((uint32)(ClockCfgPtr->I2s0SClkFracDiv - 1U) << TT_SCU_CLKDIV_CTL2_DIV_I2S0_SCLK_FRAC_Pos)   | \
                   ((uint32)(ClockCfgPtr->I2s0SClkIntDiv - 1U) << TT_SCU_CLKDIV_CTL2_DIV_I2S0_SCLK_INT_Pos);
       } 
    #endif

        Mcu_PubClkInfo.IHOClk = ClockCfgPtr->IhoClk;
        Mcu_PubClkInfo.ECOClk = ClockCfgPtr->EcoClk;
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
/******************************************************************************
*                            Private Functions
******************************************************************************/
/**
* @brief        Mcu_Hw_Clk_PriGetPByClk
* @details      Get PTmp By Clk in pll
* @param[in]    PllClock: the dest pll clock
* @param[in]    PTmp: Pll P Param
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Clk_PriGetPByClk(uint32 PllClock, uint32 *PTmp)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (PllClock <= 31250000)
    {
        *PTmp = 32;
    }
    else if (PllClock <= 62500000)
    {
        *PTmp = 16;
    }
    else if (PllClock <= 125000000)
    {
        *PTmp = 8;
    }
    else if (PllClock <= 250000000)
    {
        *PTmp = 4;
    }
    else if (PllClock <= 500000000)
    {
        *PTmp = 2;
    }
    else if (PllClock <= 1000000000)
    {
        *PTmp = 1;
    }
    else
    {
        Ret = TT_RET_NOT_FOUND_ERR;
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_PriCovertPTmp
* @details      Covert PTmp to P
* @param[in]    PTmp:
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static uint32 Mcu_Hw_Clk_PriCovertPTmp(uint32 PTmp)
{
    uint32 Ret = 0;

    switch(PTmp)
    {
        case 1:
            Ret = 0;
            break;
        case 2:
            Ret = 1;
            break;
        case 4:
            Ret = 2;
            break;
        case 8:
            Ret = 3;
            break;
        case 16:
            Ret = 4;
            break;
        case 32:
            Ret = 5;
            break;
        default:
            /* default */
            Ret = 0xFF;
            break;
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_PriMpllFindNMP
* @details      find the dest N M P paras in pll config
* @param[in]    PllClock: the dest pll clock
* @param[in]    OscClk: the dest Osc clock
* @param[in]    PPtr: the dest P
* @param[in]    MsPtr: the dest Ms
* @param[in]    Nsptr: the dest Ns
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Clk_PriMpllFindNMP(uint32 PllClock, uint32 OscClk, uint32 *PPtr, uint32 *MsPtr, uint32 *Nsptr)
{
    uint32 FreqTmp = 0U, OscClock = 0U;
    uint32  PTmp = 0U, MsTmp = 0U, NsTmp = 0U;
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((PllClock > MCU_EPLL_CLK) || (PllClock == 0U) || (OscClk == 0U)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck(((PPtr == NULL_PTR) || (MsPtr == NULL_PTR) || (Nsptr == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        FreqTmp = PllClock / 1000000U;
        OscClock = OscClk / 1000000U;
        Ret = Mcu_Hw_Clk_PriGetPByClk(PllClock, &PTmp);
        if (Ret == TT_RET_SUCCESS)
        {
            MsTmp = (((OscClock - ((OscClock / 16) * 16)) > 0U) ? ((OscClock / 16) + 1) : (OscClock / 16));
            for (; MsTmp <= (OscClock / 2); MsTmp++)
            {
                NsTmp = (PTmp * FreqTmp * MsTmp) / OscClock;

                if (((NsTmp*OscClock) >= (500 * MsTmp)) && ((NsTmp*OscClock) <= (MsTmp * 1000)) && ((NsTmp * OscClock) == (MsTmp * PTmp *FreqTmp)))
                {
                    break;
                }
                else
                {
                    /* do nothing */
                }
            }

            if (MsTmp > (OscClock / 2U))
            {
                Ret = TT_RET_NOT_FOUND_ERR;
            }
            else
            {
                PTmp = Mcu_Hw_Clk_PriCovertPTmp(PTmp);
                *PPtr = PTmp;
                *MsPtr = MsTmp;
                *Nsptr = NsTmp;
            }
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
/**
* @brief        Mcu_Hw_Clk_PriEPllConfig
* @details      Epll configuration
* @param[in]    PllClock: the dest pll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Clk_PriEPllConfig (TT_CONST uint32 PllClock)
{
    uint32 ms = 0U, ns = 0U, p = 0U;
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 CmuFlag = 0U;
#if (TT_SAFETY == STD_ON)
    uint32 TmpClk = 0U;
#endif
#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
    uint32 TimeoutTicks = 0;
    uint32 CurrentTicks = 0;
    uint32 ElapsedTicks = 0;
    uint32 TempTicks = 0;
#else
    uint32 TimeoutCount = 0;
#endif

    TT_ParaCheck(((PllClock > MCU_EPLL_CLK)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if(TT_RET_SUCCESS == Mcu_Hw_Clk_PriMpllFindNMP(PllClock,Mcu_PubClkInfo.ECOClk, (uint32 *)&p, (uint32 *)&ms, (uint32 *)&ns))
        {
            (void)Mcu_Hw_Cmu_StoreStop(&CmuFlag);
            TT_SCU->EPLL_CTL  |= TT_SCU_EPLL_CTL_BYPASS_Msk;
            TT_SCU->EPLL_CTL  |= TT_SCU_MPLL_CTL_RSTB_Msk;
            TT_SCU->EPLL_CTL  |= TT_SCU_EPLL_CTL_STANDBY_Msk;
            TT_SCU->EPLL_CTL  = (uint32)(TT_SCU->EPLL_CTL & (~0xFFFFU))       | \
                                   ((p << TT_SCU_EPLL_CTL_FR_Pos) | \
                                   (ns << TT_SCU_EPLL_CTL_NS_Pos) | ms);
            TT_SCU->EPLL_CTL &= ~TT_SCU_EPLL_CTL_STANDBY_Msk;

        #if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
            (void)Base_Drv_Timer_MicrosToTicks(MCU_MAX_TIMEOUT_DURATION,&TimeoutTicks);
            (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
        #endif
            /* Wait PLL to be locked or stable */
            while ((TT_SCU->EPLL_CTL & (TT_SCU_EPLL_CTL_LOCK_Msk)) == 0U)
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
            #ifdef USING_OS_AUTOSAROS
                SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_08();
            #endif
                (void)Base_Drv_UnlockProtReg();
                TT_SCU->CLKDIV_CTL1 = Mcu_PubClkInfo.ClkDiv1;
                (void)Base_Drv_LockProtReg();
            #ifdef USING_OS_AUTOSAROS
                SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_08();
            #endif
                /* If PLL is locked then switch to PLL output */
                TT_SCU->EPLL_CTL &= ~TT_SCU_EPLL_CTL_BYPASS_Msk;
            #if (TT_SAFETY == STD_ON)
                Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL1, Mcu_PubClkInfo.ClkDiv1, &Ret);
                Mcu_Hw_Clk_PriRegReadBack((TT_SCU->EPLL_CTL & TT_SCU_EPLL_CTL_BYPASS_Msk), 0, &Ret);
            #endif
            }

            (void)Mcu_Hw_Cmu_LoadStart(&CmuFlag);

        #if (TT_SAFETY == STD_ON)
            Ret = Mcu_Hw_Clk_GetEpll(&TmpClk);
            if ((Ret == TT_RET_SUCCESS) && (PllClock == TmpClk))
            {
                Ret = TT_RET_SUCCESS;
            }
            else
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }
        #endif

        }
        else
        {
            Ret = TT_RET_STATUS_CLK_ERR;
        }

    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Clk_PriMpllSwitch
* @details      Mcu Main Pll switch
* @param[in]    PllClock - the dest pll clock (E:240000000)
* @param[in]    SysClk - system clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          USE_CMU_MODULE, if Cmu was used, need close all cmu before switch PLL
*/
static TT_RetType Mcu_Hw_Clk_PriMpllSwitch(TT_CONST uint32 PllClock,TT_CONST uint32 SysClk)
{
    uint32 ms = 0, ns = 0, p = 0;
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 CmuFlag = 0;
    uint32 BusClk = 0;
#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
    uint32 TimeoutTicks = 0;
    uint32 CurrentTicks = 0;
    uint32 ElapsedTicks = 0;
    uint32 TempTicks = 0;
#else
    uint32 TimeoutCount = 0;
#endif

    if(TT_RET_SUCCESS != Mcu_Hw_Clk_PriMpllFindNMP(PllClock,Mcu_PubClkInfo.ECOClk, (uint32 *)&p, (uint32 *)&ms, (uint32 *)&ns))
    {
        Ret = TT_RET_STATUS_CLK_ERR;
    }
    else
    {
        /* Stop all CMU */
        (void)Mcu_Hw_Cmu_StoreStop(&CmuFlag);

        /* If the upturn mode is used, you need to wait longer. so set the FCU time first */
        if (SysClk < PllClock)
        {
            /* set dest clk FCU time */
            Ret = Mcu_Hw_Misc_FcuTimingConfig(PllClock / (((Mcu_PubClkInfo.ClkDiv0 & TT_SCU_CLKDIV_CTL0_DIV_BUS_CFG_Msk) >> TT_SCU_CLKDIV_CTL0_DIV_BUS_CFG_Pos) + 1));
        }

        TT_SCU->MPLL_CTL  |= TT_SCU_MPLL_CTL_BYPASS_Msk;
        TT_SCU->MPLL_CTL  |= TT_SCU_MPLL_CTL_RSTB_Msk;
        TT_SCU->MPLL_CTL  |= TT_SCU_MPLL_CTL_STANDBY_Msk;

        TT_SCU->MPLL_CTL  = (TT_SCU->MPLL_CTL & ~0xFFFFU)       | \
                   ((p << TT_SCU_MPLL_CTL_FR_Pos) | \
                   (ns << TT_SCU_MPLL_CTL_NS_Pos) | ms);

        TT_SCU->MPLL_CTL &= ~TT_SCU_MPLL_CTL_STANDBY_Msk;

    #if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
        (void)Base_Drv_Timer_MicrosToTicks(MCU_MAX_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
    #endif
        /* Wait PLL to be locked or stable */
        while ((TT_SCU->MPLL_CTL & TT_SCU_MPLL_CTL_LOCK_Msk) == 0U)
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

        /* The pll is not locked and cannot be switch to PLL output */
        if(Ret == TT_RET_SUCCESS)
        {
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_09();
        #endif
            (void)Base_Drv_UnlockProtReg();
            TT_SCU->CLKDIV_CTL0 = Mcu_PubClkInfo.ClkDiv0;
            TT_SCU->CLKDIV_CTL1 = Mcu_PubClkInfo.ClkDiv1;
            TT_SCU->CLKDIV_CTL2 = Mcu_PubClkInfo.ClkDiv2;
            (void)Base_Drv_LockProtReg();
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_09();
        #endif

        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL0, Mcu_PubClkInfo.ClkDiv0, &Ret);
            Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL1, Mcu_PubClkInfo.ClkDiv1, &Ret);
            Mcu_Hw_Clk_PriRegReadBack(TT_SCU->CLKDIV_CTL2, Mcu_PubClkInfo.ClkDiv2, &Ret);
        #endif
            /* If PLL is locked then switch to PLL output */
            TT_SCU->MPLL_CTL &= ~TT_SCU_MPLL_CTL_BYPASS_Msk;
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Clk_PriRegReadBack((TT_SCU->MPLL_CTL & TT_SCU_MPLL_CTL_BYPASS_Msk), 0, &Ret);
        #endif
            /* If the frequency is reduced, reset the value after the configuration is complete */
            if (SysClk >= PllClock)
            {
                /* set dest clk FCU time */
                Ret = Mcu_Hw_Clk_GetBus(&BusClk);
                if (Ret == TT_RET_SUCCESS)
                {
                    Ret = Mcu_Hw_Misc_FcuTimingConfig(BusClk);
                }
                else
                {
                    /* do nothing */
                }
            }
        }
        /* Restore all CMU */
        (void)Mcu_Hw_Cmu_LoadStart(&CmuFlag);
    }

    return Ret;
}

#if defined(USE_CAN_MODULE) && (USE_CAN_MODULE == STD_ON)
/**
* @brief        Mcu_Hw_Clk_PriCanPllConfig
* @details      Can pll configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Clk_PriCanPllConfig (void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 SysClk = 0;

    if ((Mcu_PubClkInfo.CanPeClk > 0))
    {
        /* clk main */
        if (((TT_SCU->CGU_CLK_SEL & TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Msk) > 0U))
        {
            Ret = Mcu_Hw_Clk_GetSystem(&SysClk);
            if (TT_RET_SUCCESS == Ret)
            {
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_10();
        #endif
            (void)Base_Drv_UnlockProtReg();
            TT_SCU->CGU_CLK_SEL |= TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Msk;
            TT_SCU->CLKDIV_CTL1 |= ((SysClk / Mcu_PubClkInfo.CanPeClk) - 1) << TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG_Pos;
            (void)Base_Drv_LockProtReg();
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_10();
        #endif

        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Clk_PriRegReadBack((TT_SCU->CGU_CLK_SEL & TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Msk), TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Msk, &Ret);
            Mcu_Hw_Clk_PriRegReadBack((TT_SCU->CLKDIV_CTL1 & TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG_Msk), (((SysClk / Mcu_PubClkInfo.CanPeClk) - 1) << TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG_Pos), &Ret);
        #endif
            }
            else
            {
            /* do nothing */
            }
        }
        else /* eco */
        {
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_11();
        #endif
            (void)Base_Drv_UnlockProtReg();
            TT_SCU->CLKDIV_CTL1 |= (( Mcu_PubClkInfo.ECOClk / Mcu_PubClkInfo.CanPeClk) - 1) << TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG_Pos;
            (void)Base_Drv_LockProtReg();
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_11();
        #endif
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Clk_PriRegReadBack((TT_SCU->CLKDIV_CTL1 & TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG_Msk), (((Mcu_PubClkInfo.ECOClk / Mcu_PubClkInfo.CanPeClk) - 1) << TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG_Pos), &Ret);
        #endif
        }
    }

    return Ret;
}
#endif

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Clk_PriRegReadBack
* @details       Ppu Register Read Back
* @param[in]     ActualValue - Actual Value
* @param[in]     TargetValue - Target Value
* @param[out]    Ret - TT_RET_SUCCESS - success
                 Others - fail
* @return        void
* @retval
* @pre
*/
LOCAL_INLINE void Mcu_Hw_Clk_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret)
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

#ifdef __cplusplus
}
#endif
