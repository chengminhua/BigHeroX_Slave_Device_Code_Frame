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
**  FILENAME     : Base_Hw.h                                                  **
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
*                            History                                          **
*[V1.0.1]:                                                                    **
*******************************************************************************/
#ifndef BASE_HW_H
#define BASE_HW_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_HW_VENDOR_ID_H                     1541
#define BASE_HW_MODULE_ID_H                     218
#define BASE_HW_AR_RELEASE_MAJOR_VERSION_H      4
#define BASE_HW_AR_RELEASE_MINOR_VERSION_H      4
#define BASE_HW_AR_RELEASE_PATCH_VERSION_H      0
#define BASE_HW_SW_MAJOR_VERSION_H              1
#define BASE_HW_SW_MINOR_VERSION_H              1
#define BASE_HW_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Hw.h and TT_Common.h file version check */
#if (BASE_HW_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "Base_Hw.h and TT_Common.h have different vendor id"
#endif
#if ((BASE_HW_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_HW_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_HW_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Hw.h and TT_Common.h are different"
#endif
#if ((BASE_HW_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (BASE_HW_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (BASE_HW_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Hw.h and TT_Common.h are different"
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
#define BASE_START_SEC_CODE_SLOW
#include "Base_MemMap.h"
/**
 * @brief       Base Module Init function, should be call first if use Base Module
 * @details     This function initializes the Base module and should be called during startup, before every
 *              other intialization other than Mcu.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Base_Hw_Init(TT_CONST uint32 ticks);

/**
 * @brief       Get the current value counter
 * @details     This function returns the current value of the counter.
 * @param[out]  Count  The current value of the counter
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         Base module must be initialized.
 */
#define BASE_STOP_SEC_CODE_SLOW
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
extern TT_RetType Base_Hw_Timer_GetCounter(uint32 * TT_CONST RetVal);
/**
 * @brief       Get the elapsed value from a reference point
 * @details     Function returns the delta time in ticks compared to a reference, and updates the reference.
 * @param[in,out] CurrentRef  Reference counter value, updated to current counter value
 * @param[out]  Elapsed  Elapsed time
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         Base module must be initialized.
 */
extern TT_RetType Base_Hw_Timer_GetElapsed(uint32 * TT_CONST CurrentRef, uint32 * TT_CONST RetVal);

/**
 * @brief       Get the irq count
 * @details     Function returns the delta time in ticks compared to a reference, and updates the reference.
 * @param[in,out] CurrentRef  Reference counter value, updated to current counter value
 * @param[out]  Elapsed  Elapsed time
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         Base module must be initialized.
 */
extern TT_RetType Base_Hw_GetIrqCount(uint32 * TT_CONST RetVal);
#if defined(BASE_SYSTEM_TIMER_IRQ) && (BASE_SYSTEM_TIMER_IRQ == STD_ON)
ISR(SysTick_IRQHandler);
#endif
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* BASE_HW_H */
