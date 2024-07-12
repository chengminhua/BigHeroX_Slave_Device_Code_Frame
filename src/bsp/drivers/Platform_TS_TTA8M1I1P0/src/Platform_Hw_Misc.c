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
**  FILENAME     : Platform_Hw_Misc.c                                         **
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
#include "Platform_Hw_Misc.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_MISC_VENDOR_ID_C                     1541
#define PLATFORM_HW_MISC_MODULE_ID_C                     219
#define PLATFORM_HW_MISC_AR_RELEASE_MAJOR_VERSION_C      4
#define PLATFORM_HW_MISC_AR_RELEASE_MINOR_VERSION_C      4
#define PLATFORM_HW_MISC_AR_RELEASE_PATCH_VERSION_C      0
#define PLATFORM_HW_MISC_SW_MAJOR_VERSION_C              1
#define PLATFORM_HW_MISC_SW_MINOR_VERSION_C              1
#define PLATFORM_HW_MISC_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/* Platform_Hw_Misc.c and Platform_Hw_Misc.h file version check */
#if (PLATFORM_HW_MISC_VENDOR_ID_C != PLATFORM_HW_MISC_VENDOR_ID_H)
    #error "Platform_Hw_Misc.c and Platform_Hw_Misc.h have different vendor id"
#endif
#if (PLATFORM_HW_MISC_MODULE_ID_C != PLATFORM_HW_MISC_MODULE_ID_H)
    #error "Platform_Hw_Misc.c and Platform_Hw_Misc.h have different module id"
#endif
#if ((PLATFORM_HW_MISC_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_MISC_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MISC_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_MISC_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_MISC_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_MISC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_Misc.c and Platform_Hw_Misc.h are different"
#endif
#if ((PLATFORM_HW_MISC_SW_MAJOR_VERSION_C != PLATFORM_HW_MISC_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MISC_SW_MINOR_VERSION_C != PLATFORM_HW_MISC_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_MISC_SW_PATCH_VERSION_C != PLATFORM_HW_MISC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_Misc.c and Platform_Hw_Misc.h are different"
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
TT_RetType Platform_Hw_Misc_SetVector(TT_CONST IRQn_Type IRQn, TT_CONST uint32 vector)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 *vectors = NULL_PTR;

    TT_ParaCheck((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck(((vector & 0x01U) != 1), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        vectors = (uint32 *)TT_SCB->VTOR;
        vectors[(sint32)IRQn + TT_NVIC_USER_IRQ_OFFSET] = vector;
        MCAL_DATA_SYNC_BARRIER();
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((vectors[(sint32)IRQn + TT_NVIC_USER_IRQ_OFFSET] != vector), TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
TT_RetType Platform_Hw_Misc_GetVector(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 *vectors = NULL_PTR;

    TT_ParaCheck((RetVal == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck(((IRQn < PLATFORM_INT_CTRL_IRQ_MIN) || (IRQn > PLATFORM_INT_CTRL_IRQ_MAX)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        vectors = (uint32 *)TT_SCB->VTOR;
        *RetVal = vectors[(sint32)IRQn + TT_NVIC_USER_IRQ_OFFSET];
    }
    else
    {
    }

    return Ret;
}

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
TT_RetType Platform_Hw_Misc_GetFPUType(uint32 * TT_CONST RetVal)
{
  TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((RetVal == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        uint32 mvfr0 = 0;

        mvfr0 = TT_SCB->MVFR0;
        if ((mvfr0 & (TT_FPU_MVFR0_Single_precision_Msk | TT_FPU_MVFR0_Double_precision_Msk)) == 0x220U)
        {
            *RetVal = 2U; /* Double + Single precision FPU */
        }
        else if ((mvfr0 & (TT_FPU_MVFR0_Single_precision_Msk | TT_FPU_MVFR0_Double_precision_Msk)) == 0x020U)
        {
            *RetVal = 1U; /* Single precision FPU */
        }
        else
        {
            *RetVal = 0U; /* No FPU */
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif
