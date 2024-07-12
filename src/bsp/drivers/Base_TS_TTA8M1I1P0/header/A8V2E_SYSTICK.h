/************************************************************************************
*  Copyright (c) 2023, ThinkTech, Inc. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without modification,
*  are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice, this
*     list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice, this
*     list of conditions and the following disclaimer in the documentation and/or
*     other materials provided with the distribution.
*
*  3) Neither the name of the ThinkTech, Inc., nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
*  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
*  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
*  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
*  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
*  OF THE POSSIBILITY OF SUCH DAMAGE.
*************************************************************************************/

#ifndef A8V2E_SYSTICK_H
#define A8V2E_SYSTICK_H

#include "TT_Common.h"

#ifdef __cplusplus
 extern "C" {
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_SYSTICK_VENDOR_ID_H                     1541
#define A8V2E_SYSTICK_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_SYSTICK_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_SYSTICK_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_SYSTICK_SW_MAJOR_VERSION_H              1
#define A8V2E_SYSTICK_SW_MINOR_VERSION_H              1
#define A8V2E_SYSTICK_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_SYSTICK.h and TT_Common.h file version check */
#if (A8V2E_SYSTICK_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_SYSTICK.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_SYSTICK_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_SYSTICK_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_SYSTICK_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_SYSTICK.h and TT_Common.h are different"
#endif
#if ((A8V2E_SYSTICK_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_SYSTICK_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_SYSTICK_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_SYSTICK.h and TT_Common.h are different"
#endif


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_SysTick     System Tick Timer (SysTick)
  \brief    Type definitions for the System Timer Registers.
  @{
 */

/**
  \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct {
   uint32_t CSRr;                               /**< SysTick Control and Status Register, offset: 0x0 */
   uint32_t RVR;                               /**< SysTick Reload Value Register, offset: 0x4 */
   uint32_t CVR;                               /**< SysTick Current Value Register, offset: 0x8 */
    uint32_t CALIB;                             /**< SysTick Calibration Value Register, offset: 0xC */
} SysTick_RegType;

/* CSR Bit Fields */
#define TT_SYSTICK_CSR_ENABLE_MASK              0x1u
#define TT_SYSTICK_CSR_ENABLE_SHIFT             0u
#define TT_SYSTICK_CSR_ENABLE_WIDTH             1u
#define TT_SYSTICK_CSR_ENABLE(x)                (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_CSR_ENABLE_SHIFT))&TT_SYSTICK_CSR_ENABLE_MASK)
#define TT_SYSTICK_CSR_TICKINT_MASK             0x2u
#define TT_SYSTICK_CSR_TICKINT_SHIFT            1u
#define TT_SYSTICK_CSR_TICKINT_WIDTH            1u
#define TT_SYSTICK_CSR_TICKINT(x)               (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_CSR_TICKINT_SHIFT))&TT_SYSTICK_CSR_TICKINT_MASK)
#define TT_SYSTICK_CSR_CLKSOURCE_MASK           0x4u
#define TT_SYSTICK_CSR_CLKSOURCE_SHIFT          2u
#define TT_SYSTICK_CSR_CLKSOURCE_WIDTH          1u
#define TT_SYSTICK_CSR_CLKSOURCE(x)             (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_CSR_CLKSOURCE_SHIFT))&TT_SYSTICK_CSR_CLKSOURCE_MASK)
#define TT_SYSTICK_CSR_COUNTFLAG_MASK           0x10000u
#define TT_SYSTICK_CSR_COUNTFLAG_SHIFT          16u
#define TT_SYSTICK_CSR_COUNTFLAG_WIDTH          1u
#define TT_SYSTICK_CSR_COUNTFLAG(x)             (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_CSR_COUNTFLAG_SHIFT))&TT_SYSTICK_CSR_COUNTFLAG_MASK)
/* RVR Bit Fields */
#define TT_SYSTICK_RVR_RELOAD_MASK              0xFFFFFFu
#define TT_SYSTICK_RVR_RELOAD_SHIFT             0u
#define TT_SYSTICK_RVR_RELOAD_WIDTH             24u
#define TT_SYSTICK_RVR_RELOAD(x)                (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_RVR_RELOAD_SHIFT))&TT_SYSTICK_RVR_RELOAD_MASK)
/* CVR Bit Fields */
#define TT_SYSTICK_CVR_CURRENT_MASK             0xFFFFFFu
#define TT_SYSTICK_CVR_CURRENT_SHIFT            0u
#define TT_SYSTICK_CVR_CURRENT_WIDTH            24u
#define TT_SYSTICK_CVR_CURRENT(x)               (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_CVR_CURRENT_SHIFT))&TT_SYSTICK_CVR_CURRENT_MASK)
/* CALIB Bit Fields */
#define TT_SYSTICK_CALIB_TENMS_MASK             0xFFFFFFu
#define TT_SYSTICK_CALIB_TENMS_SHIFT            0u
#define TT_SYSTICK_CALIB_TENMS_WIDTH            24u
#define TT_SYSTICK_CALIB_TENMS(x)               (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_CALIB_TENMS_SHIFT))&TT_SYSTICK_CALIB_TENMS_MASK)
#define TT_SYSTICK_CALIB_SKEW_MASK              0x40000000u
#define TT_SYSTICK_CALIB_SKEW_SHIFT             30u
#define TT_SYSTICK_CALIB_SKEW_WIDTH
#define TT_SYSTICK_CALIB_SKEW(x)                (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_CALIB_SKEW_SHIFT))&TT_SYSTICK_CALIB_SKEW_MASK)
#define TT_SYSTICK_CALIB_NOREF_MASK             0x80000000u
#define TT_SYSTICK_CALIB_NOREF_SHIFT            31u
#define TT_SYSTICK_CALIB_NOREF_WIDTH            1u
#define TT_SYSTICK_CALIB_NOREF(x)               (((uint32_t)(((uint32_t)(x))<<TT_SYSTICK_CALIB_NOREF_SHIFT))&TT_SYSTICK_CALIB_NOREF_MASK)


#define TT_SysTick_BASE        (0xE000E000UL +  0x0010UL)                    /*!< SysTick Base Address */

#define TT_SYSTICK             ((SysTick_RegType      *)     TT_SysTick_BASE  )   /*!< SysTick configuration struct */


#ifdef __cplusplus
}
#endif

#endif

