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
**  FILENAME     : Platform_Hw_IntCtrl.c                                      **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Source File                                **
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

#include "Platform_Hw_IntCtrl.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_INTCTRL_VENDOR_ID_C                     1541
#define PLATFORM_HW_INTCTRL_MODULE_ID_C                     219
#define PLATFORM_HW_INTCTRL_AR_RELEASE_MAJOR_VERSION_C      4
#define PLATFORM_HW_INTCTRL_AR_RELEASE_MINOR_VERSION_C      4
#define PLATFORM_HW_INTCTRL_AR_RELEASE_PATCH_VERSION_C      0
#define PLATFORM_HW_INTCTRL_SW_MAJOR_VERSION_C              1
#define PLATFORM_HW_INTCTRL_SW_MINOR_VERSION_C              1
#define PLATFORM_HW_INTCTRL_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_IntCtrl.c and Platform_Hw_IntCtrl.h file version check */
#if (PLATFORM_HW_INTCTRL_VENDOR_ID_C != PLATFORM_HW_INTCTRL_VENDOR_ID_H)
    #error "Platform_Hw_IntCtrl.c and Platform_Hw_IntCtrl.h have different vendor id"
#endif
#if (PLATFORM_HW_INTCTRL_MODULE_ID_C != PLATFORM_HW_INTCTRL_MODULE_ID_H)
    #error "Platform_Hw_IntCtrl.c and Platform_Hw_IntCtrl.h have different module id"
#endif
#if ((PLATFORM_HW_INTCTRL_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_INTCTRL_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_INTCTRL_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_INTCTRL_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_IntCtrl.c and Platform_Hw_IntCtrl.h are different"
#endif
#if ((PLATFORM_HW_INTCTRL_SW_MAJOR_VERSION_C != PLATFORM_HW_INTCTRL_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_SW_MINOR_VERSION_C != PLATFORM_HW_INTCTRL_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_SW_PATCH_VERSION_C != PLATFORM_HW_INTCTRL_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_IntCtrl.c and Platform_Hw_IntCtrl.h are different"
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
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

#define PLATFORM_START_SEC_CODE_SLOW
#include "Platform_MemMap.h"

/**
 * @internal
 * @brief       Initializes the configured interrupts at interrupt controller level.
 * @param[in]   pIntCtrlCtrlConfig  Pointer to a CONSTant Platform interrupt control setting.
 * @implements  IntCtrl_Ip_Init_Activity
 */
TT_RetType Platform_Hw_IntCtrl_Init(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    
    uint32 irqIdx = 0;

    TT_ParaCheck((pIntCtrlCtrlConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((pIntCtrlCtrlConfig != NULL_PTR) && (pIntCtrlCtrlConfig->ConfigIrqCount > PLATFORM_INT_CTRL_IRQ_COUNT), TT_RET_PARAM_COUNT_ERR, &Ret);
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Platform_Hw_IntCtrl_GroupingSetPriority(7U - PLATFORM_INT_CTRL_GROUP_BITS);
        TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
        if (Ret == TT_RET_SUCCESS)
        {
            for (irqIdx = 0; irqIdx < pIntCtrlCtrlConfig->ConfigIrqCount; irqIdx++)
            {
                Ret = Platform_Hw_IntCtrl_ClearPendingIRQ(pIntCtrlCtrlConfig->IrqConfig[irqIdx].IrqNumber);
                TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
                Ret = Platform_Hw_IntCtrl_SetPriority(pIntCtrlCtrlConfig->IrqConfig[irqIdx].IrqNumber,
                                        pIntCtrlCtrlConfig->IrqConfig[irqIdx].PreemptionPriority,
                                    pIntCtrlCtrlConfig->IrqConfig[irqIdx].SubPriority);
                TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);

                if (Ret == TT_RET_SUCCESS)
                {
                    if ((uint8)pIntCtrlCtrlConfig->IrqConfig[irqIdx].IrqEnabled > 0U)
                    {
                        Ret = Platform_Hw_IntCtrl_EnableIRQ(pIntCtrlCtrlConfig->IrqConfig[irqIdx].IrqNumber);
                        TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
                    }
                    else
                    {
                        Ret = Platform_Hw_IntCtrl_DisableIRQ(pIntCtrlCtrlConfig->IrqConfig[irqIdx].IrqNumber);
                        TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
                    }
                }
                else
                {

                }

                if (Ret != TT_RET_SUCCESS)
                {
                    break;
                }
                else
                {

                }
            }
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define PLATFORM_STOP_SEC_CODE_SLOW
#include "Platform_MemMap.h"

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/**
 * @brief       Set interrupt priority value by passing preemption priority and sub priority.
 * @details     The range of preemption priority and sub priority depends on the value of priorityGroup
 *              which you may obtain with SetPriorityGrouping().
 * @param[in]   eIrqNumber  Device specific interrupt number in range [0, MAX_IRQn].
 * @param[in]   preemptionPriority  Preemptive priority value in range [0, 2^{7-priorityGroup}-1].
 * @param[in]   subPriority  Subpriority value in range [0, 2^{priorityGroup+1}-1].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_SetPriority(TT_CONST IRQn_Type eIrqNumber,TT_CONST uint8 preemptionPriority,TT_CONST uint8 subPriority)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 u8Priority = 0;
    uint32 Grouping = 0;

    Ret = Platform_Hw_IntCtrl_GroupingGetPriority(&Grouping);
    TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck(((eIrqNumber < PLATFORM_INT_CTRL_IRQ_MIN) || (eIrqNumber > PLATFORM_INT_CTRL_IRQ_MAX)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck((!IS_INTCTRL_PRIORITY(Grouping, preemptionPriority, subPriority)), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        u8Priority = (preemptionPriority << (1 + Grouping)) | ((0xFFU >> (7 - Grouping)) & subPriority);
        /* Clear the old value from the register */
        TT_NVIC->IP[eIrqNumber] &= ~0xFFU;
        TT_NVIC->IP[eIrqNumber] = u8Priority;

    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((TT_NVIC->IP[eIrqNumber] != u8Priority), TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Get an interrupt priority value.
 * @param[in]   eIrqNumber  Device specific interrupt number in range [0, MAX_IRQn].
 * @param[out]  RetVal  Grouped priority value of specific interrupt.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_GetPriority(TT_CONST IRQn_Type eIrqNumber, uint8 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((RetVal == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((eIrqNumber < PLATFORM_INT_CTRL_IRQ_MIN) || (eIrqNumber > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *RetVal = (uint8)TT_NVIC->IP[eIrqNumber];
    }
    else
    {
        /* do nothing */
    }
    
    return Ret;
}

/**
 * @brief       Set priority grouping.
 * @details     Sets the priority grouping field using the required unlock sequence.
                The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
                Only values from 0..7 are used.
                In case of a conflict between priority grouping and available
                priority bits (PLATFORM_INT_CTRL_GROUP_BITS), the smallest possible priority group is set.
 * @param[in]   PriorityGroup  Priority grouping field.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_GroupingSetPriority(TT_CONST uint32 PriorityGroup)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 reg_value = 0;
    uint32 PriorityGroupTmp = 0U;

    TT_ParaCheck((!IS_INTCTRL_PRIORITY_GROUPING(PriorityGroup)), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        PriorityGroupTmp = (PriorityGroup & (uint32)0x07UL);             /* only values 0..7 are used          */

        reg_value  =  TT_SCB->AIRCR;                                                   /* read old register configuration    */
        reg_value &= ~((uint32)(TT_SCB_AIRCR_VECTKEY_Msk | TT_SCB_AIRCR_PRIGROUP_Msk)); /* clear bits to change               */
        reg_value  =  (reg_value                                   |
                    ((uint32)0x5FAUL << TT_SCB_AIRCR_VECTKEY_Pos) |
                    (PriorityGroupTmp << TT_SCB_AIRCR_PRIGROUP_Pos)  );              /* Insert write key and priority group */
        TT_SCB->AIRCR =  reg_value;

    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((((TT_SCB->AIRCR & TT_SCB_AIRCR_PRIGROUP_Msk) >> TT_SCB_AIRCR_PRIGROUP_Pos) != PriorityGroupTmp), TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Get priority grouping.
 * @details     Reads the priority grouping field from the NVIC Interrupt Controller.
 * @param[out]  RetVal  Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_GroupingGetPriority(uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((RetVal == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    
    if (Ret == TT_RET_SUCCESS)
    {
        *RetVal = ((uint32)((TT_SCB->AIRCR & TT_SCB_AIRCR_PRIGROUP_Msk) >> TT_SCB_AIRCR_PRIGROUP_Pos));
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Enable en interrupt.
 * @details     Enables a device specific interrupt in the NVIC interrupt controller.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_EnableIRQ(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        TT_NVIC->ISER[(((uint32)IRQn) >> 5UL)] = (uint32)(1UL << (((uint32)IRQn) & 0x1FUL));
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck(((TT_NVIC->ISER[(((uint32)IRQn) >> 5UL)] & (uint32)(1UL << (((uint32)IRQn) & 0x1FUL))) == 0), TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Get an interrupt enable status.
 * @details     Returns a device specific interrupt enable status from the NVIC interrupt controller.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @param[out]  RetVal  Interrupt enable status.
 * - \b         0  Interrupt is not enabled.
 * - \b         1  Interrupt is enabled.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_GetEnableIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((RetVal == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *RetVal = ((uint32)(((TT_NVIC->ISER[(((uint32)IRQn) >> 5UL)] & (1UL << (((uint32)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Disable an interrupt.
 * @details     Disables a device specific interrupt in the NVIC interrupt controller.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_DisableIRQ(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        TT_NVIC->ICER[(((uint32)IRQn) >> 5UL)] = (uint32)(1UL << (((uint32)IRQn) & 0x1FUL));
        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck(((TT_NVIC->ICER[(((uint32)IRQn) >> 5UL)] & (uint32)(1UL << (((uint32)IRQn) & 0x1FUL))) != 0), TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/**
 * @brief       Get an interrupt pending status.
 * @details     Reads the NVIC pending register and returns the pending bit for the specified device specific interrupt.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @param[out]  RetVal  Interrupt pending status.
 * - \b         0  Interrupt status is not pending.
 * - \b         1  Interrupt status is pending.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_GetPendingIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(RetVal == NULL_PTR, TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *RetVal = (uint32)(((TT_NVIC->ISPR[(((uint32)IRQn) >> 5UL)] & (1UL << (((uint32)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Set an interrupt to be pending.
 * @details     Sets the pending bit of a device specific interrupt in the NVIC pending register.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_SetPendingIRQ(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        TT_NVIC->ISPR[(((uint32)IRQn) >> 5UL)] = (uint32)(1UL << (((uint32)IRQn) & 0x1FUL));
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Clear an interrupt pending status.
 * @details     Clears the pending bit of a device specific interrupt in the NVIC pending register.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_ClearPendingIRQ(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        TT_NVIC->ICPR[(((uint32)IRQn) >> 5UL)] = (uint32)(1UL << (((uint32)IRQn) & 0x1FUL));
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Get an interrupt active status.
 * @details     Reads the active register in the NVIC and returns the active bit for the device specific interrupt.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @param[out]  RetVal  Interrupt active status.
 * - \b         0  Interrupt status is not active.
 * - \b         1  Interrupt status is active.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_GetActive(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((RetVal == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *RetVal = (uint32)(((TT_NVIC->IABR[(((uint32)IRQn) >> 5UL)] & (1UL << (((uint32)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Trigger a interrupt by means of software trigger.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_SoftTrig(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        TT_NVIC->STIR = ((uint32)IRQn & TT_NVIC_STIR_INTID_Msk);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Encode priority value from preempt priority and sub priority.
 * @details     Encodes the priority for an interrupt with the given priority group,
 *              preemptive priority value, and subpriority value.
 *              In case of a conflict between priority grouping and available
 *              priority bits (PLATFORM_INT_CTRL_GROUP_BITS), the smallest possible priority group is set.
 * @param[in]   PriorityGroup  Used priority group.
 * @param[in]   PreemptPriority  Preemptive priority value (starting from 0).
 * @param[in]   SubPriority  Subpriority value (starting from 0).
 * @param[out]  RetVal  Encoded priority. Value can be used in the function \ref Platform_Drv_IntCtrl_SetPriority().
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_EncodePriority(TT_CONST uint32 PriorityGroup,TT_CONST uint32 PreemptPriority,
                                              TT_CONST uint32 SubPriority,uint32 * TT_CONST RetType)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 PriorityGroupTmp = 0U;
    uint32 PreemptPriorityBits = 0U;
    uint32 SubPriorityBits = 0U;

    TT_ParaCheck(!IS_INTCTRL_PRIORITY_GROUPING(PriorityGroup), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((RetType == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        PriorityGroupTmp = (PriorityGroup & (uint32)0x07UL);   /* only values 0..7 are used          */
        PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32)(PLATFORM_INT_CTRL_GROUP_BITS)) ? (uint32)(PLATFORM_INT_CTRL_GROUP_BITS) : (uint32)(7UL - PriorityGroupTmp);
        SubPriorityBits     = ((PriorityGroupTmp + (uint32)(PLATFORM_INT_CTRL_GROUP_BITS)) < (uint32)7UL) ? (uint32)0UL : (uint32)((PriorityGroupTmp - 7UL) + (uint32)(PLATFORM_INT_CTRL_GROUP_BITS));

        *RetType = (
            ((PreemptPriority & (uint32)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
            ((SubPriority     & (uint32)((1UL << (SubPriorityBits    )) - 1UL)))
            );
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Decode priority.
 * @details     Decodes an interrupt priority value with a given priority group to
 *              preemptive priority value and subpriority value.
 *              In case of a conflict between priority grouping and available
 *              priority bits (PLATFORM_INT_CTRL_GROUP_BITS) the smallest possible priority group is set.
 * @param[in]   Priority   Priority value, which can be retrieved with the function \ref Platform_Drv_IntCtrl_GetPriority().
 * @param[in]   PriorityGroup  Used priority group.
 * @param[out]  pPreemptPriority  Preemptive priority value (starting from 0).
 * @param[out]  pSubPriority  Subpriority value (starting from 0).
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_IntCtrl_DecodePriority(TT_CONST uint32 Priority,TT_CONST uint32 PriorityGroup,
                                              uint32 * TT_CONST pPreemptPriority,uint32 * TT_CONST pSubPriority)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 PriorityGroupTmp = 0U;
    uint32 PreemptPriorityBits = 0U;
    uint32 SubPriorityBits = 0U;

    TT_ParaCheck(((pPreemptPriority == NULL_PTR) || (pSubPriority == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((!IS_INTCTRL_ENCODED_PRIORITY(Priority)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((!IS_INTCTRL_PRIORITY_GROUPING(PriorityGroup)), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        PriorityGroupTmp = (PriorityGroup & (uint32)0x07UL);   /* only values 0..7 are used          */
        PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32)(PLATFORM_INT_CTRL_GROUP_BITS)) ? (uint32)(PLATFORM_INT_CTRL_GROUP_BITS) : (uint32)(7UL - PriorityGroupTmp);
        SubPriorityBits     = ((PriorityGroupTmp + (uint32)(PLATFORM_INT_CTRL_GROUP_BITS)) < (uint32)7UL) ? (uint32)0UL : (uint32)((PriorityGroupTmp - 7UL) + (uint32)(PLATFORM_INT_CTRL_GROUP_BITS));

        *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32)((1UL << (PreemptPriorityBits)) - 1UL);
        *pSubPriority     = (Priority                   ) & (uint32)((1UL << (SubPriorityBits    )) - 1UL);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*                            Private Functions
******************************************************************************/


#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
