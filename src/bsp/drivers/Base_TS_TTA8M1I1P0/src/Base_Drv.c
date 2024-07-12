
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
**  FILENAME     : Base_Drv.c                                                 **
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
#include "Base_Hw.h"
#include "Mcu_Drv.h"
#include "Base_Drv.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Base.h"
#endif
#if defined(USE_ENDINIT_MODULE) && (USE_ENDINIT_MODULE == STD_ON)
#include "EndInit_Drv.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_DRV_VENDOR_ID_C                     1541
#define BASE_DRV_MODULE_ID_C                     218
#define BASE_DRV_AR_RELEASE_MAJOR_VERSION_C      4
#define BASE_DRV_AR_RELEASE_MINOR_VERSION_C      4
#define BASE_DRV_AR_RELEASE_PATCH_VERSION_C      0
#define BASE_DRV_SW_MAJOR_VERSION_C              1
#define BASE_DRV_SW_MINOR_VERSION_C              1
#define BASE_DRV_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Drv.c and Base_Hw.h file version check */
#if (BASE_DRV_VENDOR_ID_C != BASE_HW_VENDOR_ID_H)
    #error "Base_Drv.c and Base_Hw.h have different vendor id"
#endif
#if (BASE_DRV_MODULE_ID_C != BASE_HW_MODULE_ID_H)
    #error "Base_Drv.c and Base_Hw.h have different module id"
#endif
#if ((BASE_DRV_AR_RELEASE_MAJOR_VERSION_C != BASE_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_MINOR_VERSION_C != BASE_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_PATCH_VERSION_C != BASE_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Drv.c and Base_Hw.h are different"
#endif
#if ((BASE_DRV_SW_MAJOR_VERSION_C != BASE_HW_SW_MAJOR_VERSION_H) || \
     (BASE_DRV_SW_MINOR_VERSION_C != BASE_HW_SW_MINOR_VERSION_H) || \
     (BASE_DRV_SW_PATCH_VERSION_C != BASE_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Drv.c and Base_Hw.h are different"
#endif

/* Base_Drv.c and Mcu_Drv.h file version check */
#if (BASE_DRV_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Base_Drv.c and Mcu_Drv.h have different vendor id"
#endif
#if ((BASE_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Drv.c and Mcu_Drv.h are different"
#endif
#if ((BASE_DRV_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (BASE_DRV_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (BASE_DRV_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Drv.c and Mcu_Drv.h are different"
#endif

/* Base_Drv.c and Base_Drv.h file version check */
#if (BASE_DRV_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
    #error "Base_Drv.c and Base_Drv.h have different vendor id"
#endif
#if (BASE_DRV_MODULE_ID_C != BASE_DRV_MODULE_ID_H)
    #error "Base_Drv.c and Base_Drv.h have different module id"
#endif
#if ((BASE_DRV_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Drv.c and Base_Drv.h are different"
#endif
#if ((BASE_DRV_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (BASE_DRV_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
     (BASE_DRV_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Drv.c and Base_Drv.h are different"
#endif

/* Base_Drv.c and SchM_Base.h file version check */
#ifdef USING_OS_AUTOSAROS
#if (BASE_DRV_VENDOR_ID_C != SCHM_BASE_VENDOR_ID_H)
    #error "Base_Drv.c and Base_Drv.h have different vendor id"
#endif
#if ((BASE_DRV_AR_RELEASE_MAJOR_VERSION_C != SCHM_BASE_AR_RELEASE_MAJOR_VERSION) || \
     (BASE_DRV_AR_RELEASE_MINOR_VERSION_C != SCHM_BASE_AR_RELEASE_MINOR_VERSION) || \
     (BASE_DRV_AR_RELEASE_PATCH_VERSION_C != SCHM_BASE_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Base_Drv.c and Base_Drv.h are different"
#endif
#if ((BASE_DRV_SW_MAJOR_VERSION_C != SCHM_BASE_SW_MAJOR_VERSION) || \
     (BASE_DRV_SW_MINOR_VERSION_C != SCHM_BASE_SW_MINOR_VERSION) || \
     (BASE_DRV_SW_PATCH_VERSION_C != SCHM_BASE_SW_PATCH_VERSION))
    #error "Software Version Numbers of Base_Drv.c and Base_Drv.h are different"
#endif
#endif
/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
#define SYSTICKS_MAX_COUNT      (4096U)
/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/
#define BASE_START_SEC_VAR_CLEARED_BOOLEAN
#include "Base_MemMap.h"
/* Base Init */
static boolean Base_PubInit = FALSE;

#define BASE_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Base_MemMap.h"


#define BASE_START_SEC_VAR_INIT_32
#include "Base_MemMap.h"
/* Base Internal Frequencies */
static uint32 Base_au32InternalFrequencies = 48;

#define BASE_STOP_SEC_VAR_INIT_32
#include "Base_MemMap.h"

/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/
#define BASE_START_SEC_CODE
#include "Base_MemMap.h"


/**
* @brief         Base_Check_PriParaCheck.
* @details       Base_Check_PriParaCheck
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - ServiceApiId -Service Id of API
* @param[in]     ErrId - Error Id of Conditionl
* @param[out]    RetVal - variable to check return type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Base_Check_PriParaCheck(bool Expr, uint32 ApiId, TT_RetType ErrId, TT_RetType *RetVal);
/**
* @brief         Base_Check_PriRetCheck.
* @details       Base_Check_PriRetCheck
* @param[in]     ApiId - ServiceApiId -Service Id of API
* @param[out]    ErrId - Error Id of Conditionl
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Base_Check_PriRetCheck(uint32 ApiId, TT_RetType *ErrId);
/******************************************************************************
*                            Public Functions
*******************************************************************************/

#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"
/*****************************************************************************
*  Service name    : Base_Drv_Init
*  Syntax          : TT_RetType Base_Drv_Init(void)
*  Service ID      : 100
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This function initializes the Base module and should be called during startup, before every
*                    other intialization other than Mcu..
******************************************************************************/
#define BASE_START_SEC_CODE_SLOW
#include "Base_MemMap.h"
TT_RetType Base_Drv_Init(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Base_Check_PriParaCheck((Base_PubInit == TRUE),
        BASE_DRV_SI_INIT, TT_RET_PARAM_MODE_ERR, &Ret);
    if (Ret == TT_RET_SUCCESS)
    {

#if defined(BASE_SYSTICK_EXTCLK) && (BASE_SYSTICK_EXTCLK == STD_ON)
        Base_au32InternalFrequencies = BASE_SYSTICK_EXT_CLK / 1000000;
#else
        uint32 SystemClk =  0U;
        Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_SYSTEM, &SystemClk);
        Base_au32InternalFrequencies = SystemClk / 1000000;
#endif
#if defined(BASE_SYSTICK_EXTCLK) && (BASE_SYSTICK_EXTCLK == STD_OFF)
        if (Ret == TT_RET_SUCCESS)
        {
#endif
#if defined(BASE_SYSTEM_TIMER_IRQ) && (BASE_SYSTEM_TIMER_IRQ == STD_ON)
            Ret = Base_Hw_Init(Base_au32InternalFrequencies * BASE_HZ);
#else
            Ret = Base_Hw_Init(0xFFFFFFU);
#endif
            if(Ret == TT_RET_SUCCESS )
            {
                Base_PubInit = TRUE;
            }
            {
                /* do nothing */
            }
#if defined(BASE_SYSTICK_EXTCLK) && (BASE_SYSTICK_EXTCLK == STD_OFF)
        }
        else
        {
            /* do nothing */
        }
#endif


        Base_Check_PriRetCheck(BASE_DRV_SI_INIT, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/*****************************************************************************
*  Service name    : Base_Drv_Uninit
*  Syntax          : TT_RetType Base_Drv_Uninit(void)
*  Service ID      : 101
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Base Module UnInit function
******************************************************************************/
TT_RetType Base_Drv_Uninit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Base_Check_PriParaCheck((Base_PubInit != TRUE),
        BASE_DRV_SI_UNINIT, TT_RET_PARAM_MODE_ERR, &Ret);
    
    if (Ret == TT_RET_SUCCESS)
    {
        Base_au32InternalFrequencies = 0;
        Base_PubInit = FALSE;
    }
    else
    {
        /* do nothing */
    }

    return Ret;

}
#define BASE_STOP_SEC_CODE_SLOW
#include "Base_MemMap.h"
/*****************************************************************************
*  Service name    : Base_Drv_Timer_GetCounter
*  Syntax          : TT_RetType Base_Drv_Timer_GetCounter(uint32 * TT_CONST Counter)
*  Service ID      : 102
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This function returns the current value of the counter.
******************************************************************************/
#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
TT_RetType Base_Drv_Timer_GetCounter(uint32 * TT_CONST Counter)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Base_Check_PriParaCheck((Base_PubInit != TRUE),
        BASE_DRV_SI_GET_COUNTER, TT_RET_PARAM_MODE_ERR, &Ret);

    
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Base_Hw_Timer_GetCounter(Counter);
        Base_Check_PriRetCheck(BASE_DRV_SI_GET_COUNTER, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/*****************************************************************************
*  Service name    : Base_Drv_Timer_GetElapsed
*  Syntax          : TT_RetType Base_Drv_Timer_GetElapsed(uint32 * TT_CONST CurrentRef, uint32 * TT_CONST Elapsed)
*  Service ID      : 103
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): Elapsed  Elapsed time
*  Parameters (inout): CurrentRef  Reference counter value, updated to current counter value
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Function returns the delta time in ticks compared to a reference, and updates the reference.
******************************************************************************/
TT_RetType Base_Drv_Timer_GetElapsed(uint32 * TT_CONST CurrentRef, uint32 * TT_CONST Elapsed)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Base_Check_PriParaCheck((Base_PubInit != TRUE),
        BASE_DRV_SI_GET_ELAPSED, TT_RET_PARAM_MODE_ERR, &Ret);
    
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Base_Hw_Timer_GetElapsed(CurrentRef, Elapsed);
        Base_Check_PriRetCheck(BASE_DRV_SI_GET_ELAPSED, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/*****************************************************************************
*  Service name    : Base_Drv_Timer_MicrosToTicks
*  Syntax          : TT_RetType Base_Drv_Timer_MicrosToTicks(TT_CONST uint32 Micros, uint32 * TT_CONST Ticks)
*  Service ID      : 104
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Micros  microseconds value
*  Parameters (out): Ticks  equivalent value in ticks
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This function converts a value from microsecond units to ticks units.
******************************************************************************/
TT_RetType Base_Drv_Timer_MicrosToTicks(TT_CONST uint32 Micros, uint32 * TT_CONST Ticks)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint64 interim = 0;

    Base_Check_PriParaCheck((Base_PubInit != TRUE),
                            BASE_DRV_SI_MICROS_TO_TICKS, TT_RET_PARAM_MODE_ERR, &Ret);
    Base_Check_PriParaCheck((Ticks == NULL_PTR),
                            BASE_DRV_SI_MICROS_TO_TICKS, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        interim = Micros * (uint64)Base_au32InternalFrequencies;
        /* check that computed value fits in 32 bits */
        *Ticks = (uint32)(interim & 0xFFFFFFFFU);

        if (interim > 0xFFFFFFFFU)
        {
            Ret = TT_RET_STATUS_ERR;
        }
        else
        {
            /* do nothing */
        }
        Base_Check_PriRetCheck(BASE_DRV_SI_MICROS_TO_TICKS, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/*****************************************************************************
*  Service name    : Base_Drv_Usdelay
*  Syntax          : TT_RetType Base_Drv_Usdelay(TT_CONST uint32 Us)
*  Service ID      : 105
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : us  Microsecond value
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Delay us by timer
******************************************************************************/
TT_RetType Base_Drv_Usdelay(TT_CONST uint32 Us)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 StartTime = 0U;
    uint32 CurrentTime = 0U;
    uint32 TimeOut = 0U;
    uint32 Elapsed = 0U;

    Base_Check_PriParaCheck((Base_PubInit != TRUE),
                            BASE_DRV_SI_USDELAY, TT_RET_PARAM_MODE_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        (void)Base_Drv_Timer_MicrosToTicks(Us, &TimeOut);
        (void)Base_Hw_Timer_GetCounter(&StartTime);

        while (CurrentTime < TimeOut)
        {
            Ret = Base_Hw_Timer_GetElapsed(&StartTime, &Elapsed);
            CurrentTime += Elapsed;
        }
        Base_Check_PriRetCheck(BASE_DRV_SI_USDELAY, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/*****************************************************************************
*  Service name    : Base_Drv_Msdelay
*  Syntax          : TT_RetType Base_Drv_Msdelay(TT_CONST uint32 Ms)
*  Service ID      : 106
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : ms  Microsecond value
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Delay ms by timer
******************************************************************************/
TT_RetType Base_Drv_Msdelay(TT_CONST uint32 Ms)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Base_Check_PriParaCheck((Base_PubInit != TRUE),
                            BASE_DRV_SI_MSDELAY, TT_RET_PARAM_MODE_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Base_Drv_Usdelay(Ms*1000);
        Base_Check_PriRetCheck(BASE_DRV_SI_MSDELAY, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/*****************************************************************************
*  Service name    : Base_Drv_UnlockProtReg
*  Syntax          : TT_RetType Base_Drv_UnlockProtReg(void)
*  Service ID      : 107
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : unlock endinit
******************************************************************************/
TT_RetType Base_Drv_UnlockProtReg(void)
{
    TT_RetType Ret=TT_RET_SUCCESS;
    if ((OTP_ENDINIT_ENABLE == TRUE) && ((TT_SCU->WDTSCON0 & TT_SCU_WDTSCON0_ENDINIT_Msk) > 0))
    {
#if defined(USE_ENDINIT_MODULE) && (USE_ENDINIT_MODULE == STD_ON)
        Ret = EndInit_Drv_ClearEndInit();
#endif
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/*****************************************************************************
*  Service name    : Base_Drv_LockProtReg
*  Syntax          : TT_RetType Base_Drv_LockProtReg(void)
*  Service ID      : 108
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : lock endinit
******************************************************************************/
TT_RetType Base_Drv_LockProtReg(void)
{
    TT_RetType Ret=TT_RET_SUCCESS;
    if (OTP_ENDINIT_ENABLE)
    {
#if defined(USE_ENDINIT_MODULE) && (USE_ENDINIT_MODULE == STD_ON)
        Ret = EndInit_Drv_SetEndInit();
#endif
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
*                         Private Function
******************************************************************************/
/**
* @brief         Base_Check_PriParaCheck.
* @details       Base_Check_PriParaCheck
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - ServiceApiId -Service Id of API
* @param[in]     ErrId - Error Id of Conditionl
* @param[out]    RetVal - variable to check return type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Base_Check_PriParaCheck(bool Expr, uint32 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(BASE_CHECK_TT_STATUS_DEFAULT(ApiId), ErrId);
#if defined(BASE_DEV_ERROR_DETECT) && (BASE_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(BASE_MODULE_ID,  (uint8)ApiId, ErrId);
            ModuleDet_ReportError(BASE_MODULE_ID, BASE_INSTANCE_ID, (uint8)ApiId, (uint8)ErrId);
#endif
        }
        else
        {
            /* nothing */
        }
    }
    else
    {
        /* nothing */
    }
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    (void)RetVal;
}

/**
* @brief         Base_Check_PriRetCheck.
* @details       Base_Check_PriRetCheck
* @param[in]     ApiId - ServiceApiId -Service Id of API
* @param[out]    ErrId - Error Id of Conditionl
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Base_Check_PriRetCheck(uint32 ApiId, TT_RetType *ErrId)
{
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
            TT_DRV_REPORT_ERR(BASE_MODULE_ID, ApiId, *ErrId);
#if defined(BASE_DEV_ERROR_DETECT) && (BASE_DEV_ERROR_DETECT == STD_ON)
            ModuleDet_ReportError(BASE_MODULE_ID, BASE_INSTANCE_ID, (uint8)ApiId, (uint8)(*ErrId & 0xFFU));
            *ErrId = TT_SET_STATUS_TYPE(BASE_CHECK_TT_STATUS_DEFAULT(ApiId), *ErrId);
#endif
        }
        else
        {
            /* nothing */
        }
    }
    else
    {
        /* nothing */
    }
}


#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#ifdef __cplusplus
}
#endif
