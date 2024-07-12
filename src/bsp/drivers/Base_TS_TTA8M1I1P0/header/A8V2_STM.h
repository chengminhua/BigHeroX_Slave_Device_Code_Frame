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
#ifndef A8V2_STM_H
#define A8V2_STM_H


#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_STM_VENDOR_ID_H                     1541
#define A8V2_STM_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_STM_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_STM_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_STM_SW_MAJOR_VERSION_H              1
#define A8V2_STM_SW_MINOR_VERSION_H              1
#define A8V2_STM_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_STM.h and TT_Common.h file version check */
#if (A8V2_STM_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_STM.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_STM_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_STM_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_STM_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_STM.h and TT_Common.h are different"
#endif
#if ((A8V2_STM_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_STM_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_STM_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_STM.h and TT_Common.h are different"
#endif


 
/**
  * @brief External Timer Device (TT_STM)
  */

typedef struct {                                /*!< (@ 0x400A2000) TT_STM Structure                                       */

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000000) Clock Control Register                                     */

    struct {
      __IOM uint32_t DISR       : 1;            /*!< [0..0] STM disable/enable config                                          */
      __IOM uint32_t EDIS       : 1;            /*!< [1..1] enable/disable timer count.                                        */
	  __IM  uint32              : 2;
      __IOM uint32 TRIG_OUT     : 2;
    } bit;
  } CLC;
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  ID;                           /*!< (@ 0x00000008) Timer ID Register                                          */
  __IM  uint32_t  RESERVED1;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000010) Timer0 Register                                            */

    struct {
      __IOM uint32_t STM_31_0   : 32;           /*!< [31..0] STM_31_0                                                          */
    } bit;
  } TIM0;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000014) Timer1 Register                                            */

    struct {
      __IOM uint32_t STM_35_4   : 32;           /*!< [31..0] STM_35_4                                                          */
    } bit;
  } TIM1;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000018) Timer2 Register                                            */

    struct {
      __IOM uint32_t STM_39_8   : 32;           /*!< [31..0] STM_39_8                                                          */
    } bit;
  } TIM2;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x0000001C) Timer1 Register                                            */

    struct {
      __IOM uint32_t STM_43_12  : 32;           /*!< [31..0] STM_43_12                                                         */
    } bit;
  } TIM3;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000020) Timer4 Register                                            */

    struct {
      __IOM uint32_t STM_47_16  : 32;           /*!< [31..0] STM_47_16                                                         */
    } bit;
  } TIM4;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000024) Timer5 Register                                            */

    struct {
      __IOM uint32_t STM_51_20  : 32;           /*!< [31..0] STM_51_20                                                         */
    } bit;
  } TIM5;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000028) Timer6 Register                                            */

    struct {
      __IOM uint32_t STM_63_32  : 32;           /*!< [31..0] STM_63_32                                                         */
    } bit;
  } TIM6;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x0000002C) CAP Register                                               */

    struct {
      __IOM uint32_t STMCAP_63_32 : 32;         /*!< [31..0] STMCAP_63_32                                                      */
    } bit;
  } CAP;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000030) CMP0 Register                                              */

    struct {
      __IOM uint32_t CMP0       : 32;           /*!< [31..0] CMP0                                                              */
    } bit;
  } CMP0;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000034) CMP1 Register                                              */

    struct {
      __IOM uint32_t CMP1       : 32;           /*!< [31..0] CMP1                                                              */
    } bit;
  } CMP1;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000038) CMCON Register                                             */

    struct {
      __IOM uint32_t MSIZE0     : 5;            /*!< [4..0] MSIZE0                                                             */
      __IM  uint32_t            : 3;
      __IOM uint32_t MSTART0     : 5;            /*!< [12..8] MSIZE0                                                            */
      __IM  uint32_t            : 3;
      __IOM uint32_t MSIZE1     : 5;            /*!< [20..16] MSIZE0                                                           */
      __IM  uint32_t            : 3;
      __IOM uint32_t MSTART1     : 5;            /*!< [28..24] MSIZE0                                                           */
    } bit;
  } CMCON;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x0000003C) Interrupt Control Register                                 */

    struct {
      __IOM uint32_t CMP0EN     : 1;            /*!< [0..0] CMP0EN                                                             */
      __IOM uint32_t CMP0IR     : 1;            /*!< [1..1] CMP0IR                                                             */
      __IOM uint32_t CMP0OS     : 1;            /*!< [2..2] CMP0 Out Select                                                    */
      __IM  uint32_t            : 1;
      __IOM uint32_t CMP1EN     : 1;            /*!< [4..4] CMP1EN                                                             */
      __IOM uint32_t CMP1IR     : 1;            /*!< [5..5] CMP1IR                                                             */
      __IOM uint32_t CMP1OS     : 1;            /*!< [6..6] CMP1 Out Select                                                    */
      __IM  uint32_t            : 24;
      __IOM uint32_t OVERFOLW   : 1;            /*!< [31..31] OVERFOLW                                                         */
    } bit;
  } ICR;

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000040) Interrupt Set/Clear Register                               */

    struct {
      __IOM uint32_t CMP0IRR    : 1;            /*!< [0..0] CMP0IRR                                                            */
      __IOM uint32_t CMP0ORS    : 1;            /*!< [1..1] CMP0ORS                                                            */
      __IOM uint32_t CMP1IRR    : 1;            /*!< [2..2] CMP1IRR                                                            */
      __IOM uint32_t CMP1ORS    : 1;            /*!< [3..3] CMP1ORS                                                            */
      __IOM uint32_t OV_CLREA   : 1;            /*!< [4..4] OV_CLREA                                                           */
    } bit;
  } ISCR;
  __IM  uint32_t  RESERVED2[3];

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000050) TIM0SV Register                                            */

    struct {
      __IOM uint32_t STM_31_0   : 32;           /*!< [31..0] STM_31_0                                                          */
    } bit;
  } TIM0SV;

  union {
    __IM  uint32_t reg;                         /*!< (@ 0x00000054) CAPSV Register                                             */

    struct {
      __IM  uint32_t STMCAP_63_32 : 32;         /*!< [31..0] STMCAP_63_32                                                      */
    } bit;
  } CAPSV;
  __IM  uint32_t  RESERVED3[36];

  union {
	  __IOM  uint32_t reg;                         /*!< (@ 0x000000E8) OCD Mode Control Register                                  */

    struct {
    	__IOM  uint32_t            : 24;
      __IOM  uint32_t SUS        : 4;            /*!< [27..24] OCDS pause Control                                               */
      __IOM  uint32_t SUS_P      : 1;            /*!< [28..28] SUS write protect Control                                        */
      __IOM  uint32_t SUSSTA     : 1;            /*!< [29..29] OCD Mode status                                                  */
    } bit;
  } OCS;
  __IM  uint32_t  RESERVED4[4];

  union {
       __IOM  uint32_t reg;                      /*!< (@ 0x000000FC) SV Register                                             */

     struct {
       __IOM  uint32_t SV         : 1;           /*!< [0..0] SV                                                                 */
       __IM   uint32_t            : 31;
     } bit;
   } SV;

} STM_BitType, *STM_MemMapPtr;                              /*!< Size = 236 (0xec)                                                         */



/** Number of instances of the TIMER module. */
#define STM_INSTANCE_COUNT                       (1u)

/* TIMER - Peripheral instance base addresses */
/** Peripheral TIMER base address */
#define TT_STM_BASE                              (0x400A2000UL)
/** Peripheral TIMER base pointer */
#define TT_STM                                   ((STM_BitType *)TT_STM_BASE)
/** Array initializer of TIMER peripheral base addresses */
#define TT_STM_BASE_ADDRS                        { TT_STM_BASE }
/** Array initializer of TIMER peripheral base pointers */
#define TT_STM_BASE_PTRS                         { IP_TIMER }

#define TT_STM_BITS                                   ((STM_BitType *)TT_STM_BASE)

/* =========================================================================================================================== */
/* ================                                        TT_STM                                         ================ */
/* =========================================================================================================================== */

/* ==========================================================  CLC  ========================================================== */
#define TT_STM_CLC_DISR_Pos           (0UL)                     /*!< TT_STM CLC: DISR (Bit 0)                          */
#define TT_STM_CLC_DISR_Msk           (0x1UL)                   /*!< TT_STM CLC: DISR (Bitfield-Mask: 0x01)            */
#define TT_STM_CLC_EDIS_Pos           (1UL)                     /*!< TT_STM CLC: EDIS (Bit 1)                          */
#define TT_STM_CLC_EDIS_Msk           (0x2UL)                   /*!< TT_STM CLC: EDIS (Bitfield-Mask: 0x01)            */
/* ==========================================================  ID  =========================================================== */
/* =========================================================  TIM0  ========================================================== */
#define TT_STM_TIM0_STM_31_0_Pos      (0UL)                     /*!< TT_STM TIM0: STM_31_0 (Bit 0)                     */
#define TT_STM_TIM0_STM_31_0_Msk      (0xffffffffUL)            /*!< TT_STM TIM0: STM_31_0 (Bitfield-Mask: 0xffffffff) */
/* =========================================================  TIM1  ========================================================== */
#define TT_STM_TIM1_STM_35_4_Pos      (0UL)                     /*!< TT_STM TIM1: STM_35_4 (Bit 0)                     */
#define TT_STM_TIM1_STM_35_4_Msk      (0xffffffffUL)            /*!< TT_STM TIM1: STM_35_4 (Bitfield-Mask: 0xffffffff) */
/* =========================================================  TIM2  ========================================================== */
#define TT_STM_TIM2_STM_39_8_Pos      (0UL)                     /*!< TT_STM TIM2: STM_39_8 (Bit 0)                     */
#define TT_STM_TIM2_STM_39_8_Msk      (0xffffffffUL)            /*!< TT_STM TIM2: STM_39_8 (Bitfield-Mask: 0xffffffff) */
/* =========================================================  TIM3  ========================================================== */
#define TT_STM_TIM3_STM_43_12_Pos     (0UL)                     /*!< TT_STM TIM3: STM_43_12 (Bit 0)                    */
#define TT_STM_TIM3_STM_43_12_Msk     (0xffffffffUL)            /*!< TT_STM TIM3: STM_43_12 (Bitfield-Mask: 0xffffffff) */
/* =========================================================  TIM4  ========================================================== */
#define TT_STM_TIM4_STM_47_16_Pos     (0UL)                     /*!< TT_STM TIM4: STM_47_16 (Bit 0)                    */
#define TT_STM_TIM4_STM_47_16_Msk     (0xffffffffUL)            /*!< TT_STM TIM4: STM_47_16 (Bitfield-Mask: 0xffffffff) */
/* =========================================================  TIM5  ========================================================== */
#define TT_STM_TIM5_STM_51_20_Pos     (0UL)                     /*!< TT_STM TIM5: STM_51_20 (Bit 0)                    */
#define TT_STM_TIM5_STM_51_20_Msk     (0xffffffffUL)            /*!< TT_STM TIM5: STM_51_20 (Bitfield-Mask: 0xffffffff) */
/* =========================================================  TIM6  ========================================================== */
#define TT_STM_TIM6_STM_63_32_Pos     (0UL)                     /*!< TT_STM TIM6: STM_63_32 (Bit 0)                    */
#define TT_STM_TIM6_STM_63_32_Msk     (0xffffffffUL)            /*!< TT_STM TIM6: STM_63_32 (Bitfield-Mask: 0xffffffff) */
/* ==========================================================  CAP  ========================================================== */
#define TT_STM_CAP_STMCAP_63_32_Pos   (0UL)                     /*!< TT_STM CAP: STMCAP_63_32 (Bit 0)                  */
#define TT_STM_CAP_STMCAP_63_32_Msk   (0xffffffffUL)            /*!< TT_STM CAP: STMCAP_63_32 (Bitfield-Mask: 0xffffffff) */
/* =========================================================  CMP0  ========================================================== */
#define TT_STM_CMP0_CMP0_Pos          (0UL)                     /*!< TT_STM CMP0: CMP0 (Bit 0)                         */
#define TT_STM_CMP0_CMP0_Msk          (0xffffffffUL)            /*!< TT_STM CMP0: CMP0 (Bitfield-Mask: 0xffffffff)     */
/* =========================================================  CMP1  ========================================================== */
#define TT_STM_CMP1_CMP1_Pos          (0UL)                     /*!< TT_STM CMP1: CMP1 (Bit 0)                         */
#define TT_STM_CMP1_CMP1_Msk          (0xffffffffUL)            /*!< TT_STM CMP1: CMP1 (Bitfield-Mask: 0xffffffff)     */
/* =========================================================  CMCON  ========================================================= */
#define TT_STM_CMCON_MSIZE0_Pos       (0UL)                     /*!< TT_STM CMCON: MSIZE0 (Bit 0)                      */
#define TT_STM_CMCON_MSIZE0_Msk       (0x1fUL)                  /*!< TT_STM CMCON: MSIZE0 (Bitfield-Mask: 0x1f)        */
#define TT_STM_CMCON_MSTART0_Pos       (8UL)                     /*!< TT_STM CMCON: MSTART0 (Bit 8)                      */
#define TT_STM_CMCON_MSTART0_Msk       (0x1f00UL)                /*!< TT_STM CMCON: MSTART0 (Bitfield-Mask: 0x1f)        */
#define TT_STM_CMCON_MSIZE1_Pos       (16UL)                    /*!< TT_STM CMCON: MSIZE1 (Bit 16)                     */
#define TT_STM_CMCON_MSIZE1_Msk       (0x1f0000UL)              /*!< TT_STM CMCON: MSIZE1 (Bitfield-Mask: 0x1f)        */
#define TT_STM_CMCON_MSTART1_Pos       (24UL)                    /*!< TT_STM CMCON: MSTART1 (Bit 24)                     */
#define TT_STM_CMCON_MSTART1_Msk       (0x1f000000UL)            /*!< TT_STM CMCON: MSTART1 (Bitfield-Mask: 0x1f)        */
/* ==========================================================  ICR  ========================================================== */
#define TT_STM_ICR_CMP0EN_Pos         (0UL)                     /*!< TT_STM ICR: CMP0EN (Bit 0)                        */
#define TT_STM_ICR_CMP0EN_Msk         (0x1UL)                   /*!< TT_STM ICR: CMP0EN (Bitfield-Mask: 0x01)          */
#define TT_STM_ICR_CMP0IR_Pos         (1UL)                     /*!< TT_STM ICR: CMP0IR (Bit 1)                        */
#define TT_STM_ICR_CMP0IR_Msk         (0x2UL)                   /*!< TT_STM ICR: CMP0IR (Bitfield-Mask: 0x01)          */
#define TT_STM_ICR_CMP0OS_Pos         (2UL)                     /*!< TT_STM ICR: CMP0OS (Bit 2)                        */
#define TT_STM_ICR_CMP0OS_Msk         (0x4UL)                   /*!< TT_STM ICR: CMP0OS (Bitfield-Mask: 0x01)          */
#define TT_STM_ICR_CMP1EN_Pos         (4UL)                     /*!< TT_STM ICR: CMP1EN (Bit 4)                        */
#define TT_STM_ICR_CMP1EN_Msk         (0x10UL)                  /*!< TT_STM ICR: CMP1EN (Bitfield-Mask: 0x01)          */
#define TT_STM_ICR_CMP1IR_Pos         (5UL)                     /*!< TT_STM ICR: CMP1IR (Bit 5)                        */
#define TT_STM_ICR_CMP1IR_Msk         (0x20UL)                  /*!< TT_STM ICR: CMP1IR (Bitfield-Mask: 0x01)          */
#define TT_STM_ICR_CMP1OS_Pos         (6UL)                     /*!< TT_STM ICR: CMP1OS (Bit 6)                        */
#define TT_STM_ICR_CMP1OS_Msk         (0x40UL)                  /*!< TT_STM ICR: CMP1OS (Bitfield-Mask: 0x01)          */
#define TT_STM_ICR_OVERFOLW_Pos       (31UL)                    /*!< TT_STM ICR: OVERFOLW (Bit 31)                     */
#define TT_STM_ICR_OVERFOLW_Msk       (0x80000000UL)            /*!< TT_STM ICR: OVERFOLW (Bitfield-Mask: 0x01)        */
/* =========================================================  ISCR  ========================================================== */
#define TT_STM_ISCR_CMP0IRR_Pos       (0UL)                     /*!< TT_STM ISCR: CMP0IRR (Bit 0)                      */
#define TT_STM_ISCR_CMP0IRR_Msk       (0x1UL)                   /*!< TT_STM ISCR: CMP0IRR (Bitfield-Mask: 0x01)        */
#define TT_STM_ISCR_CMP0ORS_Pos       (1UL)                     /*!< TT_STM ISCR: CMP0ORS (Bit 1)                      */
#define TT_STM_ISCR_CMP0ORS_Msk       (0x2UL)                   /*!< TT_STM ISCR: CMP0ORS (Bitfield-Mask: 0x01)        */
#define TT_STM_ISCR_CMP1IRR_Pos       (2UL)                     /*!< TT_STM ISCR: CMP1IRR (Bit 2)                      */
#define TT_STM_ISCR_CMP1IRR_Msk       (0x4UL)                   /*!< TT_STM ISCR: CMP1IRR (Bitfield-Mask: 0x01)        */
#define TT_STM_ISCR_CMP1ORS_Pos       (3UL)                     /*!< TT_STM ISCR: CMP1ORS (Bit 3)                      */
#define TT_STM_ISCR_CMP1ORS_Msk       (0x8UL)                   /*!< TT_STM ISCR: CMP1ORS (Bitfield-Mask: 0x01)        */
#define TT_STM_ISCR_OV_CLREA_Pos      (4UL)                     /*!< TT_STM ISCR: OV_CLREA (Bit 4)                     */
#define TT_STM_ISCR_OV_CLREA_Msk      (0x10UL)                  /*!< TT_STM ISCR: OV_CLREA (Bitfield-Mask: 0x01)       */
/* ========================================================  TIM0SV  ========================================================= */
#define TT_STM_TIM0SV_STM_31_0_Pos    (0UL)                     /*!< TT_STM TIM0SV: STM_31_0 (Bit 0)                   */
#define TT_STM_TIM0SV_STM_31_0_Msk    (0xffffffffUL)            /*!< TT_STM TIM0SV: STM_31_0 (Bitfield-Mask: 0xffffffff) */
/* =========================================================  CAPSV  ========================================================= */
#define TT_STM_CAPSV_STMCAP_63_32_Pos (0UL)                     /*!< TT_STM CAPSV: STMCAP_63_32 (Bit 0)                */
#define TT_STM_CAPSV_STMCAP_63_32_Msk (0xffffffffUL)            /*!< TT_STM CAPSV: STMCAP_63_32 (Bitfield-Mask: 0xffffffff) */
/* ==========================================================  OCS  ========================================================== */
#define TT_STM_OCS_SUS_Pos            (24UL)                    /*!< TT_STM OCS: SUS (Bit 24)                          */
#define TT_STM_OCS_SUS_Msk            (0xf000000UL)             /*!< TT_STM OCS: SUS (Bitfield-Mask: 0x0f)             */
#define TT_STM_OCS_SUS_P_Pos          (28UL)                    /*!< TT_STM OCS: SUS_P (Bit 28)                        */
#define TT_STM_OCS_SUS_P_Msk          (0x10000000UL)            /*!< TT_STM OCS: SUS_P (Bitfield-Mask: 0x01)           */
#define TT_STM_OCS_SUSSTA_Pos         (29UL)                    /*!< TT_STM OCS: SUSSTA (Bit 29)                       */
#define TT_STM_OCS_SUSSTA_Msk         (0x20000000UL)            /*!< TT_STM OCS: SUSSTA (Bitfield-Mask: 0x01)          */

#ifdef __cplusplus
}
#endif

#endif  /* end of A8V2_STM_H */
