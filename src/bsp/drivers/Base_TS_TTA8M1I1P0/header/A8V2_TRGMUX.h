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
#ifndef A8V2_TRGMUX_H
#define A8V2_TRGMUX_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_TRGMUX_VENDOR_ID_H                     1541
#define A8V2_TRGMUX_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_TRGMUX_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_TRGMUX_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_TRGMUX_SW_MAJOR_VERSION_H              1
#define A8V2_TRGMUX_SW_MINOR_VERSION_H              1
#define A8V2_TRGMUX_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_TRGMUX.h and TT_Common.h file version check */
#if (A8V2_TRGMUX_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_TRGMUX.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_TRGMUX_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_TRGMUX_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_TRGMUX_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_TRGMUX.h and TT_Common.h are different"
#endif
#if ((A8V2_TRGMUX_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_TRGMUX_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_TRGMUX_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_TRGMUX.h and TT_Common.h are different"
#endif


/**
  * @brief Inter-Integrated Circuit Bus 0 (TT_TRGMUX0)
  */

/* =========================================================================================================================== */
/* ================                                       TT_TRGMUX                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief Trigger Mux device (TT_TRGMUX)
  */

typedef struct {                                /*!< (@ 0x40116000) TT_TRGMUX Structure                                    */

  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000000) Trigger in Glitch Filter.                                  */

    struct {
      __IOM uint32_t GF_CNT     : 8;            /*!< [7..0] Glitch Filter Count.                                               */
      __IOM uint32_t Trgmux_en  : 1;            /*!< [8] Trgmux_en.                                               */
    } bit;
  } IN_GF;

  union {
    __IM  uint32_t reg;                         /*!< (@ 0x00000004) ID Register.                                               */

    struct {
      __IM  uint32_t ID         : 32;           /*!< [31..0] ID.                                                               */
    } bit;
  } ID;
  __IM  uint32_t  RESERVED[2];

  union {
    __IOM uint32_t reg[59];                     /*!< (@ 0x00000010) Trigger Mux Select register.                               */

    struct {
      __IOM uint32_t SEL0       : 8;            /*!< [7..0] SEL0.                                                              */
      __IOM uint32_t SEL1       : 8;            /*!< [15..8] SEL1.                                                             */
      __IOM uint32_t SEL2       : 8;            /*!< [23..16] SEL2.                                                            */
      __IOM uint32_t SEL3       : 8;            /*!< [31..24] SEL3.                                                            */
    } bit[59];
  } TRG_SEL;
}  TrgMux_RegType, *TrgMux_RegMemMapPtr;                            /*!< Size = 4096 (0x1000)                                                    */

/** Number of instances of the TRGMUX module. */
#define TRGMUX_INSTANCE_COUNT                       (1u)

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX base address */
#define IP_TRGMUX_BASE0                              (0x40116000UL)

/** Peripheral TRGMUX base pointer */
#define IP_TRGMUX0                                   ((TrgMux_RegType *)IP_TRGMUX_BASE0)
#define MODULE_TRGMUX0                               (*(TrgMux_RegType *)IP_TRGMUX_BASE0)

/** Array initializer of TRGMUX peripheral base addresses */
#define IP_TRGMUX_BASE_ADDRS                        { IP_TRGMUX_BASE0 }

/** Array initializer of TRGMUX peripheral base pointers */
#define IP_TRGMUX_BASE_PTRS                         { IP_TRGMUX0}

/* =========================================================================================================================== */
/* ================                                       TT_TRGMUX                                       ================ */
/* =========================================================================================================================== */

/* =========================================================  IN_GF  ========================================================= */
#define TT_TRGMUX_IN_GF_GF_CNT_Pos    (0UL)                     /*!< TT_TRGMUX IN_GF: GF_CNT (Bit 0)                   */
#define TT_TRGMUX_IN_GF_GF_CNT_Msk    (0xffUL)                  /*!< TT_TRGMUX IN_GF: GF_CNT (Bitfield-Mask: 0xff)     */
#define TT_TRGMUX_IN_GF_TRGMUX_EN_Pos (8UL)                     /*!< TT_TRGMUX IN_GF: TRGMUX_EN (Bit 0)                   */
#define TT_TRGMUX_IN_GF_TRGMUX_EN_Msk (0x100UL)                 /*!< TT_TRGMUX IN_GF: TRGMUX_EN (Bitfield-Mask: 0xff)     */
/* ==========================================================  ID  =========================================================== */
#define TT_TRGMUX_ID_ID_Pos           (0UL)                     /*!< TT_TRGMUX ID: ID (Bit 0)                          */
#define TT_TRGMUX_ID_ID_Msk           (0xffffffffUL)            /*!< TT_TRGMUX ID: ID (Bitfield-Mask: 0xffffffff)      */
/* ========================================================  TRG_SEL  ======================================================== */
#define TT_TRGMUX_TRG_SEL_SEL0_Pos    (0UL)                     /*!< TT_TRGMUX TRG_SEL: SEL0 (Bit 0)                   */
#define TT_TRGMUX_TRG_SEL_SEL0_Msk    (0xffUL)                  /*!< TT_TRGMUX TRG_SEL: SEL0 (Bitfield-Mask: 0xff)     */
#define TT_TRGMUX_TRG_SEL_SEL1_Pos    (8UL)                     /*!< TT_TRGMUX TRG_SEL: SEL1 (Bit 8)                   */
#define TT_TRGMUX_TRG_SEL_SEL1_Msk    (0xff00UL)                /*!< TT_TRGMUX TRG_SEL: SEL1 (Bitfield-Mask: 0xff)     */
#define TT_TRGMUX_TRG_SEL_SEL2_Pos    (16UL)                    /*!< TT_TRGMUX TRG_SEL: SEL2 (Bit 16)                  */
#define TT_TRGMUX_TRG_SEL_SEL2_Msk    (0xff0000UL)              /*!< TT_TRGMUX TRG_SEL: SEL2 (Bitfield-Mask: 0xff)     */
#define TT_TRGMUX_TRG_SEL_SEL3_Pos    (24UL)                    /*!< TT_TRGMUX TRG_SEL: SEL3 (Bit 24)                  */
#define TT_TRGMUX_TRG_SEL_SEL3_Msk    (0xff000000UL)            /*!< TT_TRGMUX TRG_SEL: SEL3 (Bitfield-Mask: 0xff)     */


#ifdef __cplusplus
}
#endif

#endif /* A8V2_TRGMUX_H */
