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
**  FILENAME     : Platform_Hw_Misc.h                                         **
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
#ifndef PLATFORM_HW_MISC_H
#define PLATFORM_HW_MISC_H

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
#define PLATFORM_HW_MISC_VENDOR_ID_H                     1541
#define PLATFORM_HW_MISC_MODULE_ID_H                     219
#define PLATFORM_HW_MISC_AR_RELEASE_MAJOR_VERSION_H      4
#define PLATFORM_HW_MISC_AR_RELEASE_MINOR_VERSION_H      4
#define PLATFORM_HW_MISC_AR_RELEASE_PATCH_VERSION_H      0
#define PLATFORM_HW_MISC_SW_MAJOR_VERSION_H              1
#define PLATFORM_HW_MISC_SW_MINOR_VERSION_H              1
#define PLATFORM_HW_MISC_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_Misc.h and Platform_Hw_IntCtrl_Types.h file version check */
#if (PLATFORM_HW_MISC_VENDOR_ID_H != PLATFORM_HW_INTCTRL_TYPES_VENDOR_ID_H)
    #error "Platform_Hw_Misc.h and Platform_Hw_IntCtrl_Types.h have different vendor id"
#endif
#if (PLATFORM_HW_MISC_MODULE_ID_H != PLATFORM_HW_INTCTRL_TYPES_MODULE_ID_H)
    #error "Platform_Hw_Misc.h and Platform_Hw_IntCtrl_Types.h have different module id"
#endif
#if ((PLATFORM_HW_MISC_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MISC_AR_RELEASE_MINOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_MISC_AR_RELEASE_PATCH_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_Misc.h and Platform_Hw_IntCtrl_Types.h are different"
#endif
#if ((PLATFORM_HW_MISC_SW_MAJOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MISC_SW_MINOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_MISC_SW_PATCH_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_Misc.h and Platform_Hw_IntCtrl_Types.h are different"
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
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief       Set interrupt vector.
 * @details     Sets an interrupt vector in SRAM based interrupt vector table.
 *              The interrupt number can be positive to specify a device specific interrupt,
 *              or negative to specify a processor exception.
 *              VTOR must been relocated to SRAM before.
 * @param[in]   IRQn  Interrupt number in range [0, MAX_IRQn].
 * @param[in]   vector  Address of interrupt handler function.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Misc_SetVector(TT_CONST IRQn_Type IRQn, TT_CONST uint32 vector);

/**
 * @brief       Get Interrupt Vector.
 * @details     Reads an interrupt vector from interrupt vector table.
 *              The interrupt number can be positive to specify a device specific interrupt,
 *              or negative to specify a processor exception.
 * @param[in]   IRQn  Interrupt number in range [0, MAX_IRQn].
 * @param[out]  RetVal  Address of interrupt handler function stored in uint32.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Misc_GetVector(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal);

/**
 * @brief       Get FPU type.
 * @details     Returns the FPU type.
 * @param[out]  RetVal  FPU type.
 * - \b         0  No FPU.
 * - \b         1  Single precision FPU.
 * - \b         2  Double + Single precision FPU.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         IntCtrl layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_Misc_GetFPUType(uint32 * TT_CONST RetVal);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/******************************************************************************
*                            Private Functions
*******************************************************************************/
#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* PLATFORM_HW_MISC_H */
