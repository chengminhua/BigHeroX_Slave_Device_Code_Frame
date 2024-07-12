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

#ifndef A8V2_FPU_H
#define A8V2_FPU_H

#include "TT_Common.h"

#ifdef __cplusplus
 extern "C" {
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_FPU_VENDOR_ID_H                     1541
#define A8V2_FPU_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_FPU_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_FPU_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_FPU_SW_MAJOR_VERSION_H              1
#define A8V2_FPU_SW_MINOR_VERSION_H              1
#define A8V2_FPU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_FPU.h and TT_Common.h file version check */
#if (A8V2_FPU_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_FPU.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_FPU_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_FPU_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_FPU_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_FPU.h and TT_Common.h are different"
#endif
#if ((A8V2_FPU_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_FPU_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_FPU_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_FPU.h and TT_Common.h are different"
#endif


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_FPU     Floating Point Unit (FPU)
  \brief    Type definitions for the Floating Point Unit (FPU)
  @{
 */

/**
  \brief  Structure type to access the Floating Point Unit (FPU).
 */
typedef struct
{
        uint32 RESERVED0[1U];
  __IOM uint32 FPCCR;                  /*!< Offset: 0x004 (R/W)  Floating-Point Context Control Register */
  __IOM uint32 FPCAR;                  /*!< Offset: 0x008 (R/W)  Floating-Point Context Address Register */
  __IOM uint32 FPDSCR;                 /*!< Offset: 0x00C (R/W)  Floating-Point Default Status Control Register */
  __IM  uint32 MVFR0;                  /*!< Offset: 0x010 (R/ )  Media and FP Feature Register 0 */
  __IM  uint32 MVFR1;                  /*!< Offset: 0x014 (R/ )  Media and FP Feature Register 1 */
  __IM  uint32 MVFR2;                  /*!< Offset: 0x018 (R/ )  Media and FP Feature Register 2 */
} FPU_Type;

/* Floating-Point Context Control Register Definitions */
#define TT_FPU_FPCCR_ASPEN_Pos                31U                                            /*!< FPCCR: ASPEN bit Position */
#define TT_FPU_FPCCR_ASPEN_Msk                (1UL << TT_FPU_FPCCR_ASPEN_Pos)                   /*!< FPCCR: ASPEN bit Mask */

#define TT_FPU_FPCCR_LSPEN_Pos                30U                                            /*!< FPCCR: LSPEN Position */
#define TT_FPU_FPCCR_LSPEN_Msk                (1UL << TT_FPU_FPCCR_LSPEN_Pos)                   /*!< FPCCR: LSPEN bit Mask */

#define TT_FPU_FPCCR_MONRDY_Pos                8U                                            /*!< FPCCR: MONRDY Position */
#define TT_FPU_FPCCR_MONRDY_Msk               (1UL << TT_FPU_FPCCR_MONRDY_Pos)                  /*!< FPCCR: MONRDY bit Mask */

#define TT_FPU_FPCCR_BFRDY_Pos                 6U                                            /*!< FPCCR: BFRDY Position */
#define TT_FPU_FPCCR_BFRDY_Msk                (1UL << TT_FPU_FPCCR_BFRDY_Pos)                   /*!< FPCCR: BFRDY bit Mask */

#define TT_FPU_FPCCR_MMRDY_Pos                 5U                                            /*!< FPCCR: MMRDY Position */
#define TT_FPU_FPCCR_MMRDY_Msk                (1UL << TT_FPU_FPCCR_MMRDY_Pos)                   /*!< FPCCR: MMRDY bit Mask */

#define TT_FPU_FPCCR_HFRDY_Pos                 4U                                            /*!< FPCCR: HFRDY Position */
#define TT_FPU_FPCCR_HFRDY_Msk                (1UL << TT_FPU_FPCCR_HFRDY_Pos)                   /*!< FPCCR: HFRDY bit Mask */

#define TT_FPU_FPCCR_THREAD_Pos                3U                                            /*!< FPCCR: processor mode bit Position */
#define TT_FPU_FPCCR_THREAD_Msk               (1UL << TT_FPU_FPCCR_THREAD_Pos)                  /*!< FPCCR: processor mode active bit Mask */

#define TT_FPU_FPCCR_USER_Pos                  1U                                            /*!< FPCCR: privilege level bit Position */
#define TT_FPU_FPCCR_USER_Msk                 (1UL << TT_FPU_FPCCR_USER_Pos)                    /*!< FPCCR: privilege level bit Mask */

#define TT_FPU_FPCCR_LSPACT_Pos                0U                                            /*!< FPCCR: Lazy state preservation active bit Position */
#define TT_FPU_FPCCR_LSPACT_Msk               (1UL /*<< FPU_FPCCR_LSPACT_Pos*/)              /*!< FPCCR: Lazy state preservation active bit Mask */

/* Floating-Point Context Address Register Definitions */
#define TT_FPU_FPCAR_ADDRESS_Pos               3U                                            /*!< FPCAR: ADDRESS bit Position */
#define TT_FPU_FPCAR_ADDRESS_Msk              (0x1FFFFFFFUL << TT_FPU_FPCAR_ADDRESS_Pos)        /*!< FPCAR: ADDRESS bit Mask */

/* Floating-Point Default Status Control Register Definitions */
#define TT_FPU_FPDSCR_AHP_Pos                 26U                                            /*!< FPDSCR: AHP bit Position */
#define TT_FPU_FPDSCR_AHP_Msk                 (1UL << TT_FPU_FPDSCR_AHP_Pos)                    /*!< FPDSCR: AHP bit Mask */

#define TT_FPU_FPDSCR_DN_Pos                  25U                                            /*!< FPDSCR: DN bit Position */
#define TT_FPU_FPDSCR_DN_Msk                  (1UL << TT_FPU_FPDSCR_DN_Pos)                     /*!< FPDSCR: DN bit Mask */

#define TT_FPU_FPDSCR_FZ_Pos                  24U                                            /*!< FPDSCR: FZ bit Position */
#define TT_FPU_FPDSCR_FZ_Msk                  (1UL << TT_FPU_FPDSCR_FZ_Pos)                     /*!< FPDSCR: FZ bit Mask */

#define TT_FPU_FPDSCR_RMode_Pos               22U                                            /*!< FPDSCR: RMode bit Position */
#define TT_FPU_FPDSCR_RMode_Msk               (3UL << TT_FPU_FPDSCR_RMode_Pos)                  /*!< FPDSCR: RMode bit Mask */

/* Media and FP Feature Register 0 Definitions */
#define TT_FPU_MVFR0_FP_rounding_modes_Pos    28U                                            /*!< MVFR0: FP rounding modes bits Position */
#define TT_FPU_MVFR0_FP_rounding_modes_Msk    (0xFUL << TT_FPU_MVFR0_FP_rounding_modes_Pos)     /*!< MVFR0: FP rounding modes bits Mask */

#define TT_FPU_MVFR0_Short_vectors_Pos        24U                                            /*!< MVFR0: Short vectors bits Position */
#define TT_FPU_MVFR0_Short_vectors_Msk        (0xFUL << TT_FPU_MVFR0_Short_vectors_Pos)         /*!< MVFR0: Short vectors bits Mask */

#define TT_FPU_MVFR0_Square_root_Pos          20U                                            /*!< MVFR0: Square root bits Position */
#define TT_FPU_MVFR0_Square_root_Msk          (0xFUL << TT_FPU_MVFR0_Square_root_Pos)           /*!< MVFR0: Square root bits Mask */

#define TT_FPU_MVFR0_Divide_Pos               16U                                            /*!< MVFR0: Divide bits Position */
#define TT_FPU_MVFR0_Divide_Msk               (0xFUL << TT_FPU_MVFR0_Divide_Pos)                /*!< MVFR0: Divide bits Mask */

#define TT_FPU_MVFR0_FP_excep_trapping_Pos    12U                                            /*!< MVFR0: FP exception trapping bits Position */
#define TT_FPU_MVFR0_FP_excep_trapping_Msk    (0xFUL << TT_FPU_MVFR0_FP_excep_trapping_Pos)     /*!< MVFR0: FP exception trapping bits Mask */

#define TT_FPU_MVFR0_Double_precision_Pos      8U                                            /*!< MVFR0: Double-precision bits Position */
#define TT_FPU_MVFR0_Double_precision_Msk     (0xFUL << TT_FPU_MVFR0_Double_precision_Pos)      /*!< MVFR0: Double-precision bits Mask */

#define TT_FPU_MVFR0_Single_precision_Pos      4U                                            /*!< MVFR0: Single-precision bits Position */
#define TT_FPU_MVFR0_Single_precision_Msk     (0xFUL << TT_FPU_MVFR0_Single_precision_Pos)      /*!< MVFR0: Single-precision bits Mask */

#define TT_FPU_MVFR0_A_SIMD_registers_Pos      0U                                            /*!< MVFR0: A_SIMD registers bits Position */
#define TT_FPU_MVFR0_A_SIMD_registers_Msk     (0xFUL /*<< FPU_MVFR0_A_SIMD_registers_Pos*/)  /*!< MVFR0: A_SIMD registers bits Mask */

/* Media and FP Feature Register 1 Definitions */
#define TT_FPU_MVFR1_FP_fused_MAC_Pos         28U                                            /*!< MVFR1: FP fused MAC bits Position */
#define TT_FPU_MVFR1_FP_fused_MAC_Msk         (0xFUL << TT_FPU_MVFR1_FP_fused_MAC_Pos)          /*!< MVFR1: FP fused MAC bits Mask */

#define TT_FPU_MVFR1_FP_HPFP_Pos              24U                                            /*!< MVFR1: FP HPFP bits Position */
#define TT_FPU_MVFR1_FP_HPFP_Msk              (0xFUL << TT_FPU_MVFR1_FP_HPFP_Pos)               /*!< MVFR1: FP HPFP bits Mask */

#define TT_FPU_MVFR1_D_NaN_mode_Pos            4U                                            /*!< MVFR1: D_NaN mode bits Position */
#define TT_FPU_MVFR1_D_NaN_mode_Msk           (0xFUL << TT_FPU_MVFR1_D_NaN_mode_Pos)            /*!< MVFR1: D_NaN mode bits Mask */

#define TT_FPU_MVFR1_FtZ_mode_Pos              0U                                            /*!< MVFR1: FtZ mode bits Position */
#define TT_FPU_MVFR1_FtZ_mode_Msk             (0xFUL /*<< FPU_MVFR1_FtZ_mode_Pos*/)          /*!< MVFR1: FtZ mode bits Mask */

/* Media and FP Feature Register 2 Definitions */

#define TT_FPU_MVFR2_VFP_Misc_Pos              4U                                            /*!< MVFR2: VFP Misc bits Position */
#define TT_FPU_MVFR2_VFP_Misc_Msk             (0xFUL << FPU_MVFR2_VFP_Misc_Pos)              /*!< MVFR2: VFP Misc bits Mask */

/* Memory mapping of Core Hardware */
#define TT_FPU_BASE            (0xE000E000UL +  0x0F30UL)                    /*!< Floating Point Unit */
#define TT_FPU                 ((FPU_RegType       *)     TT_FPU_BASE      )   /*!< Floating Point Unit */


#ifdef __cplusplus
}
#endif

#endif

