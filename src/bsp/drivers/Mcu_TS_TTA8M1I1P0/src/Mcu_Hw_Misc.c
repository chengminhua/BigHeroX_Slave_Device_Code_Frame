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
**  FILENAME     : Mcu_Hw_Misc.c                                              **
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
#include "Mcu_Hw_Misc.h"
#include "Base_Drv.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Mcu.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_MISC_VENDOR_ID_C                     1541
#define MCU_HW_MISC_MODULE_ID_C                     101
#define MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_C      4
#define MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_C      0
#define MCU_HW_MISC_SW_MAJOR_VERSION_C              1
#define MCU_HW_MISC_SW_MINOR_VERSION_C              1
#define MCU_HW_MISC_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Misc.c and Mcu_Hw_Misc.h file version check */
#if (MCU_HW_MISC_VENDOR_ID_C != MCU_HW_MISC_VENDOR_ID_H)
    #error "Mcu_Hw_Misc.c and Mcu_Hw_Misc.h have different vendor id"
#endif
#if (MCU_HW_MISC_MODULE_ID_C != MCU_HW_MISC_MODULE_ID_H)
    #error "Mcu_Hw_Misc.c and Mcu_Hw_Misc.h have different module id"
#endif
#if ((MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_C != MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_C != MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Misc.c and Mcu_Hw_Misc.h are different"
#endif
#if ((MCU_HW_MISC_SW_MAJOR_VERSION_C != MCU_HW_MISC_SW_MAJOR_VERSION_H) || \
     (MCU_HW_MISC_SW_MINOR_VERSION_C != MCU_HW_MISC_SW_MINOR_VERSION_H) || \
     (MCU_HW_MISC_SW_PATCH_VERSION_C != MCU_HW_MISC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Misc.c and Mcu_Hw_Misc.h are different"
#endif

#if (MCU_HW_MISC_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
    #error "Mcu_Hw_Misc.c and Base_TT_Cfg.h have different vendor id"
#endif
#if ((MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Misc.c and Base_TT_Cfg.h are different"
#endif
#if ((MCU_HW_MISC_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (MCU_HW_MISC_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
     (MCU_HW_MISC_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Misc.c and Base_TT_Cfg.h are different"
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

/******************************************************************************
*                         Private Function Declaration
******************************************************************************/

/******************************************************************************
*                         Public Functions
******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_Hw_Misc_LocalResetModules
* @details      Mcu control modules local reset
* @param[in]    Type - The Module will be local reset
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Misc_LocalResetModules(TT_CONST TT_SCU_LOCAL_RST_Type Type)
{
    uint32 offSet = 0U, pos = 0U, Tmp = 0U;
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
    uint32 TimeoutTicks = 0;
    uint32 CurrentTicks = 0;
    uint32 ElapsedTicks = 0;
    uint32 TempTicks = 0;
#else
    uint32 TimeoutCount = 0;
#endif

    TT_ParaCheck((!MCU_MISC_LOCALRST_TYPE_ASSERT(Type)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Tmp = (uint32)Type>>5U;
        offSet = TT_SCU_LOCAL_RESET_OFFSET + (Tmp * 0x4);
        Tmp = (((uint32)Type>>5U)<<5U);
        pos = (uint32)Type - Tmp;

        MCAL_DATA_SYNC_BARRIER();
    #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_12();
    #endif
        (void)Base_Drv_UnlockProtReg();
        (*(volatile uint32 *)(TT_SCU_BASE+offSet)) = ((uint32)1<<pos);
        (void)Base_Drv_LockProtReg();
    #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_12();
    #endif
    #if defined(MCU_TIMEOUT_ENABLED) && (MCU_TIMEOUT_ENABLED == STD_ON)
        (void)Base_Drv_Timer_MicrosToTicks(MCU_MAX_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
    #endif
        while( TRUE )
        {
            Tmp = ((*(volatile uint32 *)(TT_SCU_BASE+offSet)) >> pos) & 0x1U;
            if (Tmp == 0)
            {
                break;
            }
            else
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
        }
        MCAL_DATA_SYNC_BARRIER();
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Misc_PerformReset
* @details      The service performs a microcontroller reset.
* @return       TT_RetType
* @retval       not return - success
                TT_RET_STATUS_RESET_ERR - fail
* @pre
*/
TT_RetType Mcu_Hw_Misc_PerformReset(void)
{
    TT_CONST TT_RetType Ret = TT_RET_STATUS_RESET_ERR;

    MCAL_DATA_SYNC_BARRIER();
    TT_SCB->AIRCR  = (uint32)((0x5FAUL << TT_SCB_AIRCR_VECTKEY_Pos)        |
                             (TT_SCB->AIRCR & TT_SCB_AIRCR_PRIGROUP_Msk)   |
                             TT_SCB_AIRCR_SYSRESETREQ_Msk    );
    MCAL_DATA_SYNC_BARRIER();

#if (TT_SAFETY == STD_ON)
    MCAL_DATA_SYNC_BARRIER();
    (void)Mcu_Hw_Misc_LocalResetModules(TT_SCU_LOCAL_RST_M7_CORE);
    MCAL_DATA_SYNC_BARRIER();
    TT_SCB->AIRCR  = (uint32)((0x5FAUL << TT_SCB_AIRCR_VECTKEY_Pos)        |
                             (TT_SCB->AIRCR & TT_SCB_AIRCR_PRIGROUP_Msk)   |
                             TT_SCB_AIRCR_SYSRESETREQ_Msk    );
    MCAL_DATA_SYNC_BARRIER();
#endif

    return Ret;
}

/**
* @brief        Mcu_Hw_Misc_FcuTimingConfig
* @details      Fcu time configuration
* @param[in]    Clock: the dest clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Misc_FcuTimingConfig(TT_CONST uint32 Clock)
{
    uint32 Tmp = 0U;
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Value = 0;

    TT_ParaCheck((Clock > MCU_PLL_CLK), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Tmp = Clock / 1000000U;
        Value = (33 * Tmp) / 1000;
        if ((Value * 1000) != (33 * Tmp))
        {
            Value += 1;
        }
        else
        {
            /* do nothing */
        }
    #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_13();
    #endif
        (void)Base_Drv_UnlockProtReg();
        TT_DFCU->RLR = Value;

#ifdef A8V2
        if (Value > 1U)
        {
            TT_PFCU->RLR = Value - 1U;
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(TT_PFCU->RLR != (Value - 1U), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }
#elif defined  A8V2E
        TT_PFCU->RLR = Value;
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck(TT_PFCU->RLR != Value, TT_RET_OPT_REG_ERR, &Ret);
    #endif
#endif
        (void)Base_Drv_LockProtReg();
    #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_13();
    #endif
        Tmp = TT_DFCU->RLR;

        /* if not equal need unlock it */
        if (Tmp != Value)
        {
            /* unlock */
            TT_DFCU->ACODER = 0x54544139UL;
        #ifdef USING_OS_AUTOSAROS
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_14();
        #endif
            (void)Base_Drv_UnlockProtReg();
            TT_DFCU->RLR = Value;
            (void)Base_Drv_LockProtReg();
        #ifdef USING_OS_AUTOSAROS
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_14();
        #endif
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(TT_DFCU->RLR != Value, TT_RET_OPT_REG_ERR, &Ret);
        #endif
            /* Lock */
            TT_DFCU->ACODER = 0xABABBEC6UL;
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

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h" 

#ifdef __cplusplus
}
#endif
