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
**  FILENAME     : Base_Hw.c                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Base Driver Source File                                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            Includes
******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Base_Cfg.h"
#include "Base_Hw.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_HW_VENDOR_ID_C                     1541
#define BASE_HW_MODULE_ID_C                     218
#define BASE_HW_AR_RELEASE_MAJOR_VERSION_C      4
#define BASE_HW_AR_RELEASE_MINOR_VERSION_C      4
#define BASE_HW_AR_RELEASE_PATCH_VERSION_C      0
#define BASE_HW_SW_MAJOR_VERSION_C              1
#define BASE_HW_SW_MINOR_VERSION_C              1
#define BASE_HW_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Hw.c and Base_Cfg.h file version check */
#if (BASE_HW_VENDOR_ID_C != BASE_CFG_VENDOR_ID_H)
    #error "Base_Hw.c and Base_Cfg.h have different vendor id"
#endif
#if (BASE_HW_MODULE_ID_C != BASE_CFG_MODULE_ID_H)
    #error "Base_Hw.c and Base_Cfg.h have different module id"
#endif
#if ((BASE_HW_AR_RELEASE_MAJOR_VERSION_C != BASE_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_HW_AR_RELEASE_MINOR_VERSION_C != BASE_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_HW_AR_RELEASE_PATCH_VERSION_C != BASE_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Hw.c and Base_Cfg.h are different"
#endif
#if ((BASE_HW_SW_MAJOR_VERSION_C != BASE_CFG_SW_MAJOR_VERSION_H) || \
     (BASE_HW_SW_MINOR_VERSION_C != BASE_CFG_SW_MINOR_VERSION_H) || \
     (BASE_HW_SW_PATCH_VERSION_C != BASE_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Hw.c and Base_Cfg.h are different"
#endif

/* Base_Hw.c and Base_Hw.h file version check */
#if (BASE_HW_VENDOR_ID_C != BASE_HW_VENDOR_ID_H)
    #error "Base_Hw.c and Base_Hw.h have different vendor id"
#endif
#if (BASE_HW_MODULE_ID_C != BASE_HW_MODULE_ID_H)
    #error "Base_Hw.c and Base_Hw.h have different module id"
#endif
#if ((BASE_HW_AR_RELEASE_MAJOR_VERSION_C != BASE_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_HW_AR_RELEASE_MINOR_VERSION_C != BASE_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_HW_AR_RELEASE_PATCH_VERSION_C != BASE_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Hw.c and Base_Hw.h are different"
#endif
#if ((BASE_HW_SW_MAJOR_VERSION_C != BASE_HW_SW_MAJOR_VERSION_H) || \
     (BASE_HW_SW_MINOR_VERSION_C != BASE_HW_SW_MINOR_VERSION_H) || \
     (BASE_HW_SW_PATCH_VERSION_C != BASE_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Hw.c and Base_Hw.h are different"
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
/*  */
#define SYSTICK_GET_COUNTER()                   ((TT_SYSTICK->CVR) & TT_SYSTICK_CVR_CURRENT_MASK)

#define SYSTICK_DELTA_OUTER(high, low, max)     ((max) - ((high) - (low)))

#define SYSTICK_DELTA_INNER(high, low)          ((high) - (low))

#define SYSTICK_OVERFLOWED(curr, ref)           (curr > ref)

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
*                            Public Functions
*******************************************************************************/

#define BASE_START_SEC_CODE_SLOW
#include "Base_MemMap.h"

/**
 * @brief       Base Module Init function, should be call first if use Base Module
 * @details     This function initializes the Base module and should be called during startup, before every
 *              other intialization other than Mcu.
 * @param       ticks
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Base_Hw_Init(TT_CONST uint32 ticks)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((ticks == 0), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        TT_SYSTICK->CSRr = TT_SYSTICK_CSR_ENABLE(0u);
        TT_SYSTICK->RVR = TT_SYSTICK_RVR_RELOAD(ticks);
        TT_SYSTICK->CVR = TT_SYSTICK_CVR_CURRENT(0U);
        TT_SYSTICK->CSRr = 0U;
#if defined(BASE_SYSTICK_EXTCLK) && (BASE_SYSTICK_EXTCLK == STD_ON)
        TT_SYSTICK->CSRr |= TT_SYSTICK_CSR_CLKSOURCE(0u);
#else
        TT_SYSTICK->CSRr |= TT_SYSTICK_CSR_CLKSOURCE(1u);
#endif
#if defined(BASE_SYSTEM_TIMER_IRQ) && (BASE_SYSTEM_TIMER_IRQ == STD_ON)
        TT_SYSTICK->CSRr |= TT_SYSTICK_CSR_TICKINT(1u);
#else
        TT_SYSTICK->CSRr |= TT_SYSTICK_CSR_TICKINT(0u);
#endif
        TT_SYSTICK->CSRr |= TT_SYSTICK_CSR_ENABLE(1u);
    }
    else
    {
        /* do nothing */
    }
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#if defined(BASE_SYSTICK_EXTCLK) && (BASE_SYSTICK_EXTCLK == STD_ON)
    TT_ParaCheck((TT_SYSTICK->CSRr & TT_SYSTICK_CSR_CLKSOURCE(1u)) ==TT_SYSTICK_CSR_CLKSOURCE(1u),
                 TT_RET_PARAM_ERR, &Ret);
#else
    TT_ParaCheck((TT_SYSTICK->CSRr & TT_SYSTICK_CSR_CLKSOURCE(1u)) !=TT_SYSTICK_CSR_CLKSOURCE(1u),
                     TT_RET_PARAM_ERR, &Ret);
#endif
#if defined(BASE_SYSTEM_TIMER_IRQ) && (BASE_SYSTEM_TIMER_IRQ == STD_ON)
        TT_ParaCheck((TT_SYSTICK->CSRr & TT_SYSTICK_CSR_TICKINT(1u)) !=TT_SYSTICK_CSR_TICKINT(1u),
                             TT_RET_PARAM_ERR, &Ret);
#else
        TT_ParaCheck((TT_SYSTICK->CSRr & TT_SYSTICK_CSR_TICKINT(1u)) ==TT_SYSTICK_CSR_TICKINT(1u),
                             TT_RET_PARAM_ERR, &Ret);
#endif

#endif
    return Ret;
}
#define BASE_STOP_SEC_CODE_SLOW
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
/**
 * @brief       Get the current value counter
 * @details     This function returns the current value of the counter.
 * @param[out]  Count  The current value of the counter
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         Base module must be initialized.
 */
TT_RetType Base_Hw_Timer_GetCounter(uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((RetVal == NULL_PTR),
        TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *RetVal = SYSTICK_GET_COUNTER();
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief         Get the elapsed value from a reference point
 * @details       Function returns the delta time in ticks compared to a reference, and updates the reference.
 * @param[in,out] CurrentRef  Reference counter value, updated to current counter value
 * @param[out]    Elapsed  Elapsed time
 * @return        TT_RetType
 * @retval        Status whether function executes successfully or causes faults.
 * @pre           Base module must be initialized.
 */
TT_RetType Base_Hw_Timer_GetElapsed(uint32 * TT_CONST CurrentRef, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 CurrentVal = 0;
    uint32 dif = 0u;
    uint32 Current = 0;
    TT_ParaCheck((CurrentRef == NULL_PTR),
        TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((RetVal == NULL_PTR),
        TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    
    if (Ret == TT_RET_SUCCESS)
    {
        Current = (*CurrentRef) & 0xFFFFFFU;
        CurrentVal = SYSTICK_GET_COUNTER();
        if (SYSTICK_OVERFLOWED((CurrentVal), Current))
        {
            /* overflow occurred */
            dif = SYSTICK_DELTA_OUTER(CurrentVal, Current, (uint32)TT_SYSTICK->RVR);
        }
        else
        {
            /* overflow did not occur */
            dif = SYSTICK_DELTA_INNER(Current, CurrentVal);
        }

        *CurrentRef = CurrentVal;
        *RetVal = dif;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#if defined(BASE_SYSTEM_TIMER_IRQ) && (BASE_SYSTEM_TIMER_IRQ == STD_ON)
ISR(SysTick_IRQHandler)
{
    Base_CallBack();
}

#endif

#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#ifdef __cplusplus
}
#endif
