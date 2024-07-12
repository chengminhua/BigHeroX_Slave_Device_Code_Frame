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
**  FILENAME     : Platform_Hw_IntCtrl.h                                      **
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
#ifndef PLATFORM_HW_INTCTRL_H
#define PLATFORM_HW_INTCTRL_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Hw_IntCtrl_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_INTCTRL_VENDOR_ID_H                     1541
#define PLATFORM_HW_INTCTRL_MODULE_ID_H                     219
#define PLATFORM_HW_INTCTRL_AR_RELEASE_MAJOR_VERSION_H      4
#define PLATFORM_HW_INTCTRL_AR_RELEASE_MINOR_VERSION_H      4
#define PLATFORM_HW_INTCTRL_AR_RELEASE_PATCH_VERSION_H      0
#define PLATFORM_HW_INTCTRL_SW_MAJOR_VERSION_H              1
#define PLATFORM_HW_INTCTRL_SW_MINOR_VERSION_H              1
#define PLATFORM_HW_INTCTRL_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_IntCtrl.h and Platform_Hw_IntCtrl_Types.h file version check */
#if (PLATFORM_HW_INTCTRL_VENDOR_ID_H != PLATFORM_HW_INTCTRL_TYPES_VENDOR_ID_H)
    #error "Platform_Hw_IntCtrl.h and Platform_Hw_IntCtrl_Types.h have different vendor id"
#endif
#if (PLATFORM_HW_INTCTRL_MODULE_ID_H != PLATFORM_HW_INTCTRL_TYPES_MODULE_ID_H)
    #error "Platform_Hw_IntCtrl.h and Platform_Hw_IntCtrl_Types.h have different module id"
#endif
#if ((PLATFORM_HW_INTCTRL_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_AR_RELEASE_MINOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_AR_RELEASE_PATCH_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_IntCtrl.h and Platform_Hw_IntCtrl_Types.h are different"
#endif
#if ((PLATFORM_HW_INTCTRL_SW_MAJOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_SW_MINOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_SW_PATCH_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_IntCtrl.h and Platform_Hw_IntCtrl_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
#define PLATFORM_START_SEC_CODE_SLOW
#include "Platform_MemMap.h"
/**
 * @internal
 * @brief       Initializes the configured interrupts at interrupt controller level.
 * @param[in]   pIntCtrlCtrlConfig  Pointer to a CONSTant Platform interrupt control setting.
 * @implements  IntCtrl_Ip_Init_Activity
 */
extern TT_RetType Platform_Hw_IntCtrl_Init(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig);

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
extern TT_RetType Platform_Hw_IntCtrl_SetPriority(
    TT_CONST IRQn_Type eIrqNumber, 
    TT_CONST uint8 preemptionPriority, 
    TT_CONST uint8 subPriority);

/**
 * @brief       Get an interrupt priority value.
 * @param[in]   eIrqNumber  Device specific interrupt number in range [0, MAX_IRQn].
 * @param[out]  RetVal  Grouped priority value of specific interrupt.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_IntCtrl_GetPriority(TT_CONST IRQn_Type eIrqNumber, uint8 * TT_CONST RetVal);

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
extern TT_RetType Platform_Hw_IntCtrl_GroupingSetPriority(TT_CONST uint32 PriorityGroup);

/**
 * @brief       Get priority grouping.
 * @details     Reads the priority grouping field from the NVIC Interrupt Controller.
 * @param[out]  RetVal  Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_IntCtrl_GroupingGetPriority(uint32 * TT_CONST RetVal);

/**
 * @brief       Enable en interrupt.
 * @details     Enables a device specific interrupt in the NVIC interrupt controller.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_IntCtrl_EnableIRQ(TT_CONST IRQn_Type IRQn);

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
extern TT_RetType Platform_Hw_IntCtrl_GetEnableIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal);

/**
 * @brief       Disable an interrupt.
 * @details     Disables a device specific interrupt in the NVIC interrupt controller.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_IntCtrl_DisableIRQ(TT_CONST IRQn_Type IRQn);

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
extern TT_RetType Platform_Hw_IntCtrl_GetPendingIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal);

/**
 * @brief       Set an interrupt to be pending.
 * @details     Sets the pending bit of a device specific interrupt in the NVIC pending register.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_IntCtrl_SetPendingIRQ(TT_CONST IRQn_Type IRQn);

/**
 * @brief       Clear an interrupt pending status.
 * @details     Clears the pending bit of a device specific interrupt in the NVIC pending register.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_IntCtrl_ClearPendingIRQ(TT_CONST IRQn_Type IRQn);

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
extern TT_RetType Platform_Hw_IntCtrl_GetActive(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal);

/**
 * @brief       Trigger a interrupt by means of software trigger.
 * @param[in]   IRQn  Device specific interrupt number in range [0, MAX_IRQn].
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_IntCtrl_SoftTrig(TT_CONST IRQn_Type IRQn);

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
extern TT_RetType Platform_Hw_IntCtrl_EncodePriority(TT_CONST uint32 PriorityGroup,TT_CONST uint32 PreemptPriority,
                                              TT_CONST uint32 SubPriority,uint32 * TT_CONST RetType);

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
extern TT_RetType Platform_Hw_IntCtrl_DecodePriority(TT_CONST uint32 Priority,TT_CONST uint32 PriorityGroup,
                                              uint32 * TT_CONST pPreemptPriority,uint32 * TT_CONST pSubPriority);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* PLATFORM_HW_INTCTRL_H */
