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
#ifndef A8V2E_ADC_H
#define A8V2E_ADC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

 
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_ADC_VENDOR_ID_H                     1541
#define A8V2E_ADC_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_ADC_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_ADC_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_ADC_SW_MAJOR_VERSION_H              1
#define A8V2E_ADC_SW_MINOR_VERSION_H              1
#define A8V2E_ADC_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_ADC.h and TT_Common.h file version check */
#if (A8V2E_ADC_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_ADC.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_ADC_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_ADC_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_ADC_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_ADC.h and TT_Common.h are different"
#endif
#if ((A8V2E_ADC_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_ADC_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_ADC_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_ADC.h and TT_Common.h are different"
#endif


typedef struct {    /*!< AxCyRegT Struct (ADCx CHANNELy Common Register Struct )                          */
  __IOM uint32  AxCyCFR;                     /*!< (@ 0x00000000) ADC Config.                                                */
  __IOM uint32  AxCyCTRLR;                   /*!< (@ 0x00000004) ADC Control.                                               */
  __IOM uint32  AxCyTVR;                     /*!< (@ 0x00000008) ADC threshhold register.                                   */
  __IM  uint32  AxCySTR;                     /*!< (@ 0x0000000C) ADC Flag register.                                         */
  __IM  uint32  AxCyRESULT;                  /*!< (@ 0x00000010) ADC Result.                                                */
  __IOM uint32  AxDMAADDR;                   /*!< (@ 0x00000014) DMA Address.                                                 */
  __IOM uint32  AxDMAINCRADDR;              /*!< (@ 0x00000018) DMA Address increment.                                     */
  __IM  uint32  RESERVED[1];
}TT_ADC_AxCyREG_Type;

typedef struct {
  __IOM TT_ADC_AxCyREG_Type AXCYREGT[14];      /*!< (@ 0x00000000) ADC register group Channel.                                */
  __IM  uint32  RESERVED5[16];
}TT_ADC_AxCHREG_Type;


typedef volatile struct  {                                /*!< (@ 0x40186000) TT_ADC Structure                                       */
  __IOM uint32  AGC0;                         /*!< (@ 0x00000000) ADC Global Division.                                       */
  __IM  uint32  RESERVED;
  __IOM uint32  GSTR[6];                     /*!< (@ 0x00000008) AG0 Stor.                                                  */
  __IOM uint32  ADCFIR[25];                   /*!< (@ 0x00000020) ADC Filtering.                                             */
  __IM  uint32  RESERVED1[3];
  __IOM uint32  CFR[6];                      /*!< (@ 0x00000090) ADC Config.                                                */
  __IM  uint32  RESERVED2[2];
  __IM  uint32  STR[6];                      /*!< (@ 0x000000B0) ADC Config.                                                */
  __IM  uint32  RESERVED3[2];
  __IOM uint32  REQSEQ[6];                   /*!< (@ 0x000000D0) Channel ID.                                                */
  __IM  uint32  RESERVED4[6];
  __IOM TT_ADC_AxCHREG_Type AXCHREGT[6];      /*!< (@ 0x00000100) ADC register group Channel. */
  __IOM uint32  FULLVOLT[6];                 /*!< (@ 0x00000D00) FULLVOLT.                                                */
  __IM  uint32  RESERVED12[2];
  __IOM uint32  ADC0_INFO_REG[14];            /*!< (@ 0x00000D20) ADC Test.                                                  */
  __IM  uint32  RESERVED13[2];
  __IOM uint32  ADC1_INFO_REG[14];            /*!< (@ 0x00000D60) ADC Test.                                                  */
  __IM  uint32  RESERVED14[2];
  __IOM uint32  ADC2_INFO_REG[14];            /*!< (@ 0x00000DA0) ADC Test.                                                  */
  __IM  uint32  RESERVED15[10];
  __IOM uint32  ADCTEST[6];                 /*!< (@ 0x00000E00) ADC Test.                                                  */
  __IM  uint32  RESERVED16[2];
  __IOM uint32  ADC3_INFO_REG[14];            /*!< (@ 0x00000E20) ADC Test.                                                  */
  __IM  uint32  RESERVED17[2];
  __IOM uint32  ADC4_INFO_REG[14];            /*!< (@ 0x00000E60) ADC Test.                                                  */
  __IM  uint32  RESERVED18[2];
  __IOM uint32  ADC5_INFO_REG[14];            /*!< (@ 0x00000EA0) ADC Test.                                                  */
  __IM  uint32  RESERVED19[10];
  __IOM uint32  ADCTRIM;                 	  /*!< (@ 0x00000F00) ADC Trimming.                                              */
  __IOM uint32  DAC_CHOP;                 	  /*!< (@ 0x00000F00) DAC chop.                                              */
  __IM  uint32  RESERVED20[6];
  __IOM uint32  PRI_REG;                      /*!< (@ 0x00000F20) Pri reg.                                                   */
  __IOM uint32  ADC_TEST;                     /*!< (@ 0x00000F24) ADC TEST reg.                                                   */
  __IOM uint32  PROBE_SEL;                    /*!< (@ 0x00000F28) PROBE_SEL.                                                 */
} Adc_RegType;                                 /*!< Size = 4096 (0x1000)                                                      */


#define TT_ADC_BASE             0x40186000UL

#define TT_ADC                  ((Adc_RegType*)TT_ADC_BASE)

#define AXOFFSET                 ((volatile uint32 *)(TT_ADC_BASE + 0xCD0U))

#define TT_ADC_IS_DMA_ADDR_VALID(ADDR)        ((((ADDR) & 0x01UL) == 0) && (((ADDR) >= 0x20000000UL) && ((ADDR) <= 0x20200000UL)))
    
/* =========================================================================================================================== */
/* ================                                       TT_ADC                                        ================ */
/* =========================================================================================================================== */
/* =========================================================  AGC0  ========================================================== */
#define TT_ADC_AGC0_DIV_Pos               (0UL)                     /*!< TT_ADC AGC0: DIV (Bit 0)                              */
#define TT_ADC_AGC0_DIV_Msk               (0xfUL)                   /*!< TT_ADC AGC0: DIV (Bitfield-Mask: 0x0f)                */
#define TT_ADC_AGC0_CLK_STOP_Pos          (4UL)                     /*!< TT_ADC AGC0: DIV (Bit 0)                              */
#define TT_ADC_AGC0_CLK_STOP_Msk          (0x10UL)                   /*!< TT_ADC AGC0: DIV (Bitfield-Mask: 0x0f)                */
#define TT_ADC_AGC0_Reserved0_Pos         (5UL)                     /*!< TT_ADC AGC0: Reserved0 (Bit 4)                        */
#define TT_ADC_AGC0_Reserved0_Msk         (0xe0UL)                  /*!< TT_ADC AGC0: Reserved0 (Bitfield-Mask: 0x0f)          */
#define TT_ADC_AGC0_FTSAMP_Pos            (8UL)                     /*!< TT_ADC AGC0: FTSAMP (Bit 8)                           */
#define TT_ADC_AGC0_FTSAMP_Msk            (0x1f00UL)                /*!< TT_ADC AGC0: FTSAMP (Bitfield-Mask: 0x1f)             */
#define TT_ADC_AGC0_Reserved1_Pos         (13UL)                    /*!< TT_ADC AGC0: Reserved1 (Bit 13)                       */
#define TT_ADC_AGC0_Reserved1_Msk         (0xe000UL)                /*!< TT_ADC AGC0: Reserved1 (Bitfield-Mask: 0x07)          */
#define TT_ADC_AGC0_STSAMP_Pos            (16UL)                    /*!< TT_ADC AGC0: STSAMP (Bit 16)                          */
#define TT_ADC_AGC0_STSAMP_Msk            (0xff0000UL)              /*!< TT_ADC AGC0: STSAMP (Bitfield-Mask: 0xff)             */
#define TT_ADC_AGC0_FIR_SHIFT_Pos         (24UL)                    /*!< TT_ADC AGC0: FIR_SHIFT (Bit 24)                       */
#define TT_ADC_AGC0_FIR_SHIFT_Msk         (0x1f000000UL)            /*!< TT_ADC AGC0: FIR_SHIFT (Bitfield-Mask: 0x1f)          */
#define TT_ADC_AGC0_Reserved2_Pos         (29UL)                    /*!< TT_ADC AGC0: Reserved2 (Bit 29)                       */
#define TT_ADC_AGC0_Reserved2_Msk         (0x60000000UL)            /*!< TT_ADC AGC0: Reserved2 (Bitfield-Mask: 0x03)          */
#define TT_ADC_AGC0_AGC0_WP_Pos           (31UL)                    /*!< TT_ADC AGC0: AGC0_WP (Bit 31)                         */
#define TT_ADC_AGC0_AGC0_WP_Msk           (0x80000000UL)            /*!< TT_ADC AGC0: AGC0_WP (Bitfield-Mask: 0x01)            */
/* =========================================================  GSTR  ========================================================== */
#define TT_ADC_GSTR_READY0_Pos            (0UL)                     /*!< TT_ADC GSTR: READY0 (Bit 0)                           */
#define TT_ADC_GSTR_READY0_Msk            (0x1UL)                   /*!< TT_ADC GSTR: READY0 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY1_Pos            (1UL)                     /*!< TT_ADC GSTR: READY1 (Bit 1)                           */
#define TT_ADC_GSTR_READY1_Msk            (0x2UL)                   /*!< TT_ADC GSTR: READY1 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY2_Pos            (2UL)                     /*!< TT_ADC GSTR: READY2 (Bit 2)                           */
#define TT_ADC_GSTR_READY2_Msk            (0x4UL)                   /*!< TT_ADC GSTR: READY2 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY3_Pos            (3UL)                     /*!< TT_ADC GSTR: READY3 (Bit 3)                           */
#define TT_ADC_GSTR_READY3_Msk            (0x8UL)                   /*!< TT_ADC GSTR: READY3 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY4_Pos            (4UL)                     /*!< TT_ADC GSTR: READY4 (Bit 4)                           */
#define TT_ADC_GSTR_READY4_Msk            (0x10UL)                  /*!< TT_ADC GSTR: READY4 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY5_Pos            (5UL)                     /*!< TT_ADC GSTR: READY5 (Bit 5)                           */
#define TT_ADC_GSTR_READY5_Msk            (0x20UL)                  /*!< TT_ADC GSTR: READY5 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY6_Pos            (6UL)                     /*!< TT_ADC GSTR: READY6 (Bit 6)                           */
#define TT_ADC_GSTR_READY6_Msk            (0x40UL)                  /*!< TT_ADC GSTR: READY6 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY7_Pos            (7UL)                     /*!< TT_ADC GSTR: READY7 (Bit 7)                           */
#define TT_ADC_GSTR_READY7_Msk            (0x80UL)                  /*!< TT_ADC GSTR: READY7 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY8_Pos            (8UL)                     /*!< TT_ADC GSTR: READY8 (Bit 8)                           */
#define TT_ADC_GSTR_READY8_Msk            (0x100UL)                 /*!< TT_ADC GSTR: READY8 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY9_Pos            (9UL)                     /*!< TT_ADC GSTR: READY9 (Bit 9)                           */
#define TT_ADC_GSTR_READY9_Msk            (0x200UL)                 /*!< TT_ADC GSTR: READY9 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_READY10_Pos           (10UL)                    /*!< TT_ADC GSTR: READY10 (Bit 10)                         */
#define TT_ADC_GSTR_READY10_Msk           (0x400UL)                 /*!< TT_ADC GSTR: READY10 (Bitfield-Mask: 0x01)            */
#define TT_ADC_GSTR_READY11_Pos           (11UL)                    /*!< TT_ADC GSTR: READY11 (Bit 11)                         */
#define TT_ADC_GSTR_READY11_Msk           (0x800UL)                 /*!< TT_ADC GSTR: READY11 (Bitfield-Mask: 0x01)            */
#define TT_ADC_GSTR_READY12_Pos           (12UL)                    /*!< TT_ADC GSTR: READY12 (Bit 12)                         */
#define TT_ADC_GSTR_READY12_Msk           (0x1000UL)                /*!< TT_ADC GSTR: READY12 (Bitfield-Mask: 0x01)            */
#define TT_ADC_GSTR_READY13_Pos           (13UL)                    /*!< TT_ADC GSTR: READY13 (Bit 13)                         */
#define TT_ADC_GSTR_READY13_Msk           (0x2000UL)                /*!< TT_ADC GSTR: READY13 (Bitfield-Mask: 0x01)            */
#define TT_ADC_GSTR_Reserved0_Pos         (14UL)                    /*!< TT_ADC GSTR: Reserved0 (Bit 14)                       */
#define TT_ADC_GSTR_Reserved0_Msk         (0xc000UL)                /*!< TT_ADC GSTR: Reserved0 (Bitfield-Mask: 0x03)          */
#define TT_ADC_GSTR_ERROR0_Pos            (16UL)                    /*!< TT_ADC GSTR: ERROR0 (Bit 16)                          */
#define TT_ADC_GSTR_ERROR0_Msk            (0x10000UL)               /*!< TT_ADC GSTR: ERROR0 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR1_Pos            (17UL)                    /*!< TT_ADC GSTR: ERROR1 (Bit 17)                          */
#define TT_ADC_GSTR_ERROR1_Msk            (0x20000UL)               /*!< TT_ADC GSTR: ERROR1 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR2_Pos            (18UL)                    /*!< TT_ADC GSTR: ERROR2 (Bit 18)                          */
#define TT_ADC_GSTR_ERROR2_Msk            (0x40000UL)               /*!< TT_ADC GSTR: ERROR2 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR3_Pos            (19UL)                    /*!< TT_ADC GSTR: ERROR3 (Bit 19)                          */
#define TT_ADC_GSTR_ERROR3_Msk            (0x80000UL)               /*!< TT_ADC GSTR: ERROR3 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR4_Pos            (20UL)                    /*!< TT_ADC GSTR: ERROR4 (Bit 20)                          */
#define TT_ADC_GSTR_ERROR4_Msk            (0x100000UL)              /*!< TT_ADC GSTR: ERROR4 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR5_Pos            (21UL)                    /*!< TT_ADC GSTR: ERROR5 (Bit 21)                          */
#define TT_ADC_GSTR_ERROR5_Msk            (0x200000UL)              /*!< TT_ADC GSTR: ERROR5 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR6_Pos            (22UL)                    /*!< TT_ADC GSTR: ERROR6 (Bit 22)                          */
#define TT_ADC_GSTR_ERROR6_Msk            (0x400000UL)              /*!< TT_ADC GSTR: ERROR6 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR7_Pos            (23UL)                    /*!< TT_ADC GSTR: ERROR7 (Bit 23)                          */
#define TT_ADC_GSTR_ERROR7_Msk            (0x800000UL)              /*!< TT_ADC GSTR: ERROR7 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR8_Pos            (24UL)                    /*!< TT_ADC GSTR: ERROR8 (Bit 24)                          */
#define TT_ADC_GSTR_ERROR8_Msk            (0x1000000UL)             /*!< TT_ADC GSTR: ERROR8 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR9_Pos            (25UL)                    /*!< TT_ADC GSTR: ERROR9 (Bit 25)                          */
#define TT_ADC_GSTR_ERROR9_Msk            (0x2000000UL)             /*!< TT_ADC GSTR: ERROR9 (Bitfield-Mask: 0x01)             */
#define TT_ADC_GSTR_ERROR10_Pos           (26UL)                    /*!< TT_ADC GSTR: ERROR10 (Bit 26)                         */
#define TT_ADC_GSTR_ERROR10_Msk           (0x4000000UL)             /*!< TT_ADC GSTR: ERROR10 (Bitfield-Mask: 0x01)            */
#define TT_ADC_GSTR_ERROR11_Pos           (27UL)                    /*!< TT_ADC GSTR: ERROR11 (Bit 27)                         */
#define TT_ADC_GSTR_ERROR11_Msk           (0x8000000UL)             /*!< TT_ADC GSTR: ERROR11 (Bitfield-Mask: 0x01)            */
#define TT_ADC_GSTR_ERROR12_Pos           (28UL)                    /*!< TT_ADC GSTR: ERROR12 (Bit 28)                         */
#define TT_ADC_GSTR_ERROR12_Msk           (0x10000000UL)            /*!< TT_ADC GSTR: ERROR12 (Bitfield-Mask: 0x01)            */
#define TT_ADC_GSTR_ERROR13_Pos           (29UL)                    /*!< TT_ADC GSTR: ERROR13 (Bit 29)                         */
#define TT_ADC_GSTR_ERROR13_Msk           (0x20000000UL)            /*!< TT_ADC GSTR: ERROR13 (Bitfield-Mask: 0x01)            */
#define TT_ADC_GSTR_DMA_READY_Pos         (30UL)                    /*!< TT_ADC GSTR: DMA_READY (Bit 30)                       */
#define TT_ADC_GSTR_DMA_READY_Msk         (0x40000000UL)            /*!< TT_ADC GSTR: DMA_READY (Bitfield-Mask: 0x01)          */


/* ========================================================  ADCFIR  ========================================================= */
#define TT_ADC_ADCFIR_FIR_Pos             (0UL)                     /*!< TT_ADC ADCFIR: FIR (Bit 0)                            */
#define TT_ADC_ADCFIR_FIR_Msk             (0x1ffffUL)               /*!< TT_ADC ADCFIR: FIR (Bitfield-Mask: 0x1ffff)           */
#define TT_ADC_ADCFIR_Reserved0_Pos       (17UL)                    /*!< TT_ADC ADCFIR: Reserved0 (Bit 17)                     */
#define TT_ADC_ADCFIR_Reserved0_Msk       (0x7ffe0000UL)            /*!< TT_ADC ADCFIR: Reserved0 (Bitfield-Mask: 0x3fff)      */
#define TT_ADC_ADCFIR_FIR_WP_Pos          (31UL)                    /*!< TT_ADC ADCFIR: FIR_WP (Bit 31)                        */
#define TT_ADC_ADCFIR_FIR_WP_Msk          (0x80000000UL)            /*!< TT_ADC ADCFIR: FIR_WP (Bitfield-Mask: 0x01)           */
/* =========================================================  CFR  ========================================================== */
#define TT_ADC_CFR_EN_Pos                (0UL)                     /*!< TT_ADC CFR: EN (Bit 0)                               */
#define TT_ADC_CFR_EN_Msk                (0x1UL)                   /*!< TT_ADC CFR: EN (Bitfield-Mask: 0x01)                 */
#define TT_ADC_CFR_COMPUEN_Pos           (1UL)                     /*!< TT_ADC CFR: COMPUEN (Bit 1)                          */
#define TT_ADC_CFR_COMPUEN_Msk           (0x2UL)                   /*!< TT_ADC CFR: COMPUEN (Bitfield-Mask: 0x01)            */
#define TT_ADC_CFR_CMCODE_Pos            (2UL)                     /*!< TT_ADC CFR: CMCODE (Bit 2)                           */
#define TT_ADC_CFR_CMCODE_Msk            (0x4UL)                   /*!< TT_ADC CFR: CMCODE (Bitfield-Mask: 0x01)             */
#define TT_ADC_CFR_DMA_MODE_Pos          (3UL)                     /*!< TT_ADC CFR: DMA_MODE (Bit 3)                         */
#define TT_ADC_CFR_DMA_MODE_Msk          (0x8UL)                   /*!< TT_ADC CFR: DMA_MODE (Bitfield-Mask: 0x01)           */
#define TT_ADC_CFR_ADCSTOP_Pos           (4UL)                     /*!< TT_ADC CFR: ADCSTOP (Bit 4)                          */
#define TT_ADC_CFR_ADCSTOP_Msk           (0x30UL)                  /*!< TT_ADC CFR: ADCSTOP (Bitfield-Mask: 0x03)            */
#define TT_ADC_CFR_DMA_EN_Pos            (6UL)                     /*!< TT_ADC CFR: DMA_EN (Bit 6)                           */
#define TT_ADC_CFR_DMA_EN_Msk            (0x40UL)                  /*!< TT_ADC CFR: DMA_EN (Bitfield-Mask: 0x01)             */
#define TT_ADC_CFR_DMA_INT_EN_Pos        (7UL)                     /*!< TT_ADC CFR: DMA_INT_EN (Bit 7)                       */
#define TT_ADC_CFR_DMA_INT_EN_Msk        (0x80UL)                  /*!< TT_ADC CFR: DMA_INT_EN (Bitfield-Mask: 0x01)         */
#define TT_ADC_CFR_COMP_DATA_Pos         (8UL)                     /*!< TT_ADC CFR: COMP_DATA (Bit 8)                        */
#define TT_ADC_CFR_COMP_DATA_Msk         (0x1fff00UL)              /*!< TT_ADC CFR: COMP_DATA (Bitfield-Mask: 0x1fff)        */
#define TT_ADC_CFR_WAIT_TO_READ_Pos      (21UL)                    /*!< TT_ADC CFR: WAIT_TO_READ (Bit 21)                    */
#define TT_ADC_CFR_WAIT_TO_READ_Msk      (0x200000UL)              /*!< TT_ADC CFR: WAIT_TO_READ (Bitfield-Mask: 0x01)       */
#define TT_ADC_CFR_CMP_CHOP_EN_Pos        (22UL)                    /*!< TT_ADC CFR: CMP_CHOP_EN (Bit 22)                      */
#define TT_ADC_CFR_CMP_CHOP_EN_Msk        (0x400000UL)              /*!< TT_ADC CFR: CMP_CHOP_EN (Bitfield-Mask: 0x01)         */
#define TT_ADC_CFR_Reserved0_Pos         (23UL)                    /*!< TT_ADC CFR: Reserved0 (Bit 23)                       */
#define TT_ADC_CFR_Reserved0_Msk         (0xff800000UL)            /*!< TT_ADC CFR: Reserved0 (Bitfield-Mask: 0x1ff)         */
/* =========================================================  STR  ========================================================== */
#define TT_ADC_STR_BUSY_Pos          (0UL)                     /*!< TT_ADC STR: BUSY (Bit 0)                         */
#define TT_ADC_STR_BUSY_Msk          (0x1UL)                   /*!< TT_ADC STR: BUSY (Bitfield-Mask: 0x01)           */
#define TT_ADC_STR_Reserved0_Pos         (1UL)                     /*!< TT_ADC STR: Reserved0 (Bit 1)                        */
#define TT_ADC_STR_Reserved0_Msk         (0xeUL)                   /*!< TT_ADC STR: Reserved0 (Bitfield-Mask: 0x07)          */
#define TT_ADC_STR_CSEL_Pos              (4UL)                     /*!< TT_ADC STR: CSEL (Bit 4)                             */
#define TT_ADC_STR_CSEL_Msk              (0xf0UL)                  /*!< TT_ADC STR: CSEL (Bitfield-Mask: 0x0f)               */
#define TT_ADC_STR_Reserved1_Pos         (8UL)                     /*!< TT_ADC STR: Reserved1 (Bit 8)                        */
#define TT_ADC_STR_Reserved1_Msk         (0xffffff00UL)            /*!< TT_ADC STR: Reserved1 (Bitfield-Mask: 0xffffff)      */
/* ========================================================  REQSEQ  ========================================================= */
#define TT_ADC_REQSEQ_REQ_SEQ0_Pos        (0UL)                     /*!< TT_ADC REQSEQ: REQ_SEQ0 (Bit 0)                       */
#define TT_ADC_REQSEQ_REQ_SEQ0_Msk        (0xfUL)                   /*!< TT_ADC REQSEQ: REQ_SEQ0 (Bitfield-Mask: 0x0f)         */
#define TT_ADC_REQSEQ_REQ_SEQ1_Pos        (4UL)                     /*!< TT_ADC REQSEQ: REQ_SEQ1 (Bit 4)                       */
#define TT_ADC_REQSEQ_REQ_SEQ1_Msk        (0xf0UL)                  /*!< TT_ADC REQSEQ: REQ_SEQ1 (Bitfield-Mask: 0x0f)         */
#define TT_ADC_REQSEQ_REQ_SEQ2_Pos        (8UL)                     /*!< TT_ADC REQSEQ: REQ_SEQ2 (Bit 8)                       */
#define TT_ADC_REQSEQ_REQ_SEQ2_Msk        (0xf00UL)                 /*!< TT_ADC REQSEQ: REQ_SEQ2 (Bitfield-Mask: 0x0f)         */
#define TT_ADC_REQSEQ_REQ_SEQ3_Pos        (12UL)                    /*!< TT_ADC REQSEQ: REQ_SEQ3 (Bit 12)                      */
#define TT_ADC_REQSEQ_REQ_SEQ3_Msk        (0xf000UL)                /*!< TT_ADC REQSEQ: REQ_SEQ3 (Bitfield-Mask: 0x0f)         */
#define TT_ADC_REQSEQ_REQ_SEQ4_Pos        (16UL)                    /*!< TT_ADC REQSEQ: REQ_SEQ4 (Bit 16)                      */
#define TT_ADC_REQSEQ_REQ_SEQ4_Msk        (0xf0000UL)               /*!< TT_ADC REQSEQ: REQ_SEQ4 (Bitfield-Mask: 0x0f)         */
#define TT_ADC_REQSEQ_REQ_SEQ5_Pos        (20UL)                    /*!< TT_ADC REQSEQ: REQ_SEQ5 (Bit 20)                      */
#define TT_ADC_REQSEQ_REQ_SEQ5_Msk        (0xf00000UL)              /*!< TT_ADC REQSEQ: REQ_SEQ5 (Bitfield-Mask: 0x0f)         */
#define TT_ADC_REQSEQ_REQ_SEQ6_Pos        (24UL)                    /*!< TT_ADC REQSEQ: REQ_SEQ6 (Bit 24)                      */
#define TT_ADC_REQSEQ_REQ_SEQ6_Msk        (0xf000000UL)             /*!< TT_ADC REQSEQ: REQ_SEQ6 (Bitfield-Mask: 0x0f)         */
#define TT_ADC_REQSEQ_REQ_SEQ7_Pos        (28UL)                    /*!< TT_ADC REQSEQ: REQ_SEQ7 (Bit 28)                      */
#define TT_ADC_REQSEQ_REQ_SEQ7_Msk        (0xf0000000UL)            /*!< TT_ADC REQSEQ: REQ_SEQ7 (Bitfield-Mask: 0x0f)         */
/* ========================================================  OFFSET  ========================================================= */
#define TT_ADC_OFFSET_OFFSET_DATA_Pos     (0UL)                     /*!< TT_ADC OFFSET: OFFSET_DATA (Bit 0)                    */
#define TT_ADC_OFFSET_OFFSET_DATA_Msk     (0x1fffUL)                /*!< TT_ADC OFFSET: OFFSET_DATA (Bitfield-Mask: 0x1fff)    */
#define TT_ADC_OFFSET_Reserved0_Pos       (13UL)                    /*!< TT_ADC OFFSET: Reserved0 (Bit 13)                     */
#define TT_ADC_OFFSET_Reserved0_Msk       (0x7fffe000UL)            /*!< TT_ADC OFFSET: Reserved0 (Bitfield-Mask: 0x3ffff)     */
#define TT_ADC_OFFSET_OFFSET_LOCK_Pos     (31UL)                    /*!< TT_ADC OFFSET: OFFSET_LOCK (Bit 31)                   */
#define TT_ADC_OFFSET_OFFSET_LOCK_Msk     (0x80000000UL)            /*!< TT_ADC OFFSET: OFFSET_LOCK (Bitfield-Mask: 0x01)      */
/* =======================================================  FULLVOLT  ======================================================== */
#define TT_ADC_FULLVOLT_FULL_VOLT_Pos     (0UL)                     /*!< TT_ADC FULLVOLT: FULL_VOLT (Bit 0)                    */
#define TT_ADC_FULLVOLT_FULL_VOLT_Msk     (0xfffUL)                 /*!< TT_ADC FULLVOLT: FULL_VOLT (Bitfield-Mask: 0xfff)     */
#define TT_ADC_FULLVOLT_Reserved0_Pos     (12UL)                    /*!< TT_ADC FULLVOLT: Reserved0 (Bit 12)                   */
#define TT_ADC_FULLVOLT_Reserved0_Msk     (0x7ffff000UL)            /*!< TT_ADC FULLVOLT: Reserved0 (Bitfield-Mask: 0x7ffff)   */
#define TT_ADC_FULLVOLT_FULL_VOLT_LOCK_Pos (31UL)                   /*!< TT_ADC FULLVOLT: FULL_VOLT_LOCK (Bit 31)              */
#define TT_ADC_FULLVOLT_FULL_VOLT_LOCK_Msk (0x80000000UL)           /*!< TT_ADC FULLVOLT: FULL_VOLT_LOCK (Bitfield-Mask: 0x01) */
/* =====================================================  ADC0_INFO_REG  ===================================================== */
#define TT_ADC_ADC0_INFO_REG_INFO_REG_Pos (0UL)                     /*!< TT_ADC ADC0_INFO_REG: INFO_REG (Bit 0)                */
#define TT_ADC_ADC0_INFO_REG_INFO_REG_Msk (0x3fffffffUL)            /*!< TT_ADC ADC0_INFO_REG: INFO_REG (Bitfield-Mask: 0x3fffffff) */
#define TT_ADC_ADC0_INFO_REG_Reserved0_Pos (30UL)                   /*!< TT_ADC ADC0_INFO_REG: Reserved0 (Bit 30)              */
#define TT_ADC_ADC0_INFO_REG_Reserved0_Msk (0xc0000000UL)           /*!< TT_ADC ADC0_INFO_REG: Reserved0 (Bitfield-Mask: 0x03) */
/* =====================================================  ADC1_INFO_REG  ===================================================== */
#define TT_ADC_ADC1_INFO_REG_INFO_REG_Pos (0UL)                     /*!< TT_ADC ADC1_INFO_REG: INFO_REG (Bit 0)                */
#define TT_ADC_ADC1_INFO_REG_INFO_REG_Msk (0x3fffffffUL)            /*!< TT_ADC ADC1_INFO_REG: INFO_REG (Bitfield-Mask: 0x3fffffff) */
#define TT_ADC_ADC1_INFO_REG_Reserved0_Pos (30UL)                   /*!< TT_ADC ADC1_INFO_REG: Reserved0 (Bit 30)              */
#define TT_ADC_ADC1_INFO_REG_Reserved0_Msk (0xc0000000UL)           /*!< TT_ADC ADC1_INFO_REG: Reserved0 (Bitfield-Mask: 0x03) */
/* =====================================================  ADC2_INFO_REG  ===================================================== */
#define TT_ADC_ADC2_INFO_REG_INFO_REG_Pos (0UL)                     /*!< TT_ADC ADC2_INFO_REG: INFO_REG (Bit 0)                */
#define TT_ADC_ADC2_INFO_REG_INFO_REG_Msk (0x3fffffffUL)            /*!< TT_ADC ADC2_INFO_REG: INFO_REG (Bitfield-Mask: 0x3fffffff) */
#define TT_ADC_ADC2_INFO_REG_Reserved0_Pos (30UL)                   /*!< TT_ADC ADC2_INFO_REG: Reserved0 (Bit 30)              */
#define TT_ADC_ADC2_INFO_REG_Reserved0_Msk (0xc0000000UL)           /*!< TT_ADC ADC2_INFO_REG: Reserved0 (Bitfield-Mask: 0x03) */
/* ========================================================  ADCTEST  ======================================================== */
#define TT_ADC_ADCTEST_TESTREQ_Pos        (0UL)                     /*!< TT_ADC ADCTEST: TESTREQ (Bit 0)                       */
#define TT_ADC_ADCTEST_TESTREQ_Msk        (0x1UL)                   /*!< TT_ADC ADCTEST: TESTREQ (Bitfield-Mask: 0x01)         */
#define TT_ADC_ADCTEST_Reserved0_Pos      (1UL)                     /*!< TT_ADC ADCTEST: Reserved0 (Bit 1)                     */
#define TT_ADC_ADCTEST_Reserved0_Msk      (0xeUL)                   /*!< TT_ADC ADCTEST: Reserved0 (Bitfield-Mask: 0x07)       */
#define TT_ADC_ADCTEST_TESTCHSEL_Pos      (4UL)                     /*!< TT_ADC ADCTEST: TESTCHSEL (Bit 4)                     */
#define TT_ADC_ADCTEST_TESTCHSEL_Msk      (0x30UL)                  /*!< TT_ADC ADCTEST: TESTCHSEL (Bitfield-Mask: 0x03)       */
#define TT_ADC_ADCTEST_Reserved1_Pos      (6UL)                     /*!< TT_ADC ADCTEST: Reserved1 (Bit 6)                     */
#define TT_ADC_ADCTEST_Reserved1_Msk      (0xffffffc0UL)            /*!< TT_ADC ADCTEST: Reserved1 (Bitfield-Mask: 0x3ffffff)  */
/* =====================================================  ADC3_INFO_REG  ===================================================== */
#define TT_ADC_ADC3_INFO_REG_INFO_REG_Pos (0UL)                     /*!< TT_ADC ADC3_INFO_REG: INFO_REG (Bit 0)                */
#define TT_ADC_ADC3_INFO_REG_INFO_REG_Msk (0x3fffffffUL)            /*!< TT_ADC ADC3_INFO_REG: INFO_REG (Bitfield-Mask: 0x3fffffff) */
#define TT_ADC_ADC3_INFO_REG_Reserved0_Pos (30UL)                   /*!< TT_ADC ADC3_INFO_REG: Reserved0 (Bit 30)              */
#define TT_ADC_ADC3_INFO_REG_Reserved0_Msk (0xc0000000UL)           /*!< TT_ADC ADC3_INFO_REG: Reserved0 (Bitfield-Mask: 0x03) */
/* =====================================================  ADC4_INFO_REG  ===================================================== */
#define TT_ADC_ADC4_INFO_REG_INFO_REG_Pos (0UL)                     /*!< TT_ADC ADC4_INFO_REG: INFO_REG (Bit 0)                */
#define TT_ADC_ADC4_INFO_REG_INFO_REG_Msk (0x3fffffffUL)            /*!< TT_ADC ADC4_INFO_REG: INFO_REG (Bitfield-Mask: 0x3fffffff) */
#define TT_ADC_ADC4_INFO_REG_Reserved0_Pos (30UL)                   /*!< TT_ADC ADC4_INFO_REG: Reserved0 (Bit 30)              */
#define TT_ADC_ADC4_INFO_REG_Reserved0_Msk (0xc0000000UL)           /*!< TT_ADC ADC4_INFO_REG: Reserved0 (Bitfield-Mask: 0x03) */
/* =====================================================  ADC5_INFO_REG  ===================================================== */
#define TT_ADC_ADC5_INFO_REG_INFO_REG_Pos (0UL)                     /*!< TT_ADC ADC5_INFO_REG: INFO_REG (Bit 0)                */
#define TT_ADC_ADC5_INFO_REG_INFO_REG_Msk (0x3fffffffUL)            /*!< TT_ADC ADC5_INFO_REG: INFO_REG (Bitfield-Mask: 0x3fffffff) */
#define TT_ADC_ADC5_INFO_REG_Reserved0_Pos (30UL)                   /*!< TT_ADC ADC5_INFO_REG: Reserved0 (Bit 30)              */
#define TT_ADC_ADC5_INFO_REG_Reserved0_Msk (0xc0000000UL)           /*!< TT_ADC ADC5_INFO_REG: Reserved0 (Bitfield-Mask: 0x03) */
/* ========================================================  ADCTRIM  ======================================================== */
#define TT_ADC_ADCTRIM_ADC0_TRIM_Pos      (0UL)                     /*!< TT_ADC ADCTRIM: ADC0_TRIM (Bit 0)                     */
#define TT_ADC_ADCTRIM_ADC0_TRIM_Msk      (0x1UL)                   /*!< TT_ADC ADCTRIM: ADC0_TRIM (Bitfield-Mask: 0x01)       */
#define TT_ADC_ADCTRIM_ADC1_TRIM_Pos      (1UL)                     /*!< TT_ADC ADCTRIM: ADC1_TRIM (Bit 1)                     */
#define TT_ADC_ADCTRIM_ADC1_TRIM_Msk      (0x2UL)                   /*!< TT_ADC ADCTRIM: ADC1_TRIM (Bitfield-Mask: 0x01)       */
#define TT_ADC_ADCTRIM_ADC2_TRIM_Pos      (2UL)                     /*!< TT_ADC ADCTRIM: ADC2_TRIM (Bit 2)                     */
#define TT_ADC_ADCTRIM_ADC2_TRIM_Msk      (0x4UL)                   /*!< TT_ADC ADCTRIM: ADC2_TRIM (Bitfield-Mask: 0x01)       */
#define TT_ADC_ADCTRIM_ADC3_TRIM_Pos      (3UL)                     /*!< TT_ADC ADCTRIM: ADC3_TRIM (Bit 3)                     */
#define TT_ADC_ADCTRIM_ADC3_TRIM_Msk      (0x8UL)                   /*!< TT_ADC ADCTRIM: ADC3_TRIM (Bitfield-Mask: 0x01)       */
#define TT_ADC_ADCTRIM_ADC4_TRIM_Pos      (4UL)                     /*!< TT_ADC ADCTRIM: ADC4_TRIM (Bit 4)                     */
#define TT_ADC_ADCTRIM_ADC4_TRIM_Msk      (0x10UL)                  /*!< TT_ADC ADCTRIM: ADC4_TRIM (Bitfield-Mask: 0x01)       */
#define TT_ADC_ADCTRIM_ADC5_TRIM_Pos      (5UL)                     /*!< TT_ADC ADCTRIM: ADC5_TRIM (Bit 5)                     */
#define TT_ADC_ADCTRIM_ADC5_TRIM_Msk      (0x20UL)                  /*!< TT_ADC ADCTRIM: ADC5_TRIM (Bitfield-Mask: 0x01)       */
#define TT_ADC_ADCTRIM_Reserved0_Pos      (6UL)                     /*!< TT_ADC ADCTRIM: Reserved0 (Bit 6)                     */
#define TT_ADC_ADCTRIM_Reserved0_Msk      (0xffffffc0UL)            /*!< TT_ADC ADCTRIM: Reserved0 (Bitfield-Mask: 0x3ffffff)  */
/* =======================================================  DAC_CHOP  ======================================================== */
#define TT_ADC_DAC_CHOP_DAC_CHOP_Pos      (0UL)                     /*!< TT_ADC DAC_CHOP: DAC_CHOP (Bit 0)                     */
#define TT_ADC_DAC_CHOP_DAC_CHOP_Msk      (0x1UL)                   /*!< TT_ADC DAC_CHOP: DAC_CHOP (Bitfield-Mask: 0x01)       */
#define TT_ADC_DAC_CHOP_Reserved0_Pos     (1UL)                     /*!< TT_ADC DAC_CHOP: Reserved0 (Bit 1)                    */
#define TT_ADC_DAC_CHOP_Reserved0_Msk     (0xfffffffeUL)            /*!< TT_ADC DAC_CHOP: Reserved0 (Bitfield-Mask: 0x7fffffff) */
/* ========================================================  PRI_REG  ======================================================== */
#define TT_ADC_PRI_REG_PRIVILEDGE_Pos     (0UL)                     /*!< TT_ADC PRI_REG: PRIVILEDGE (Bit 0)                    */
#define TT_ADC_PRI_REG_PRIVILEDGE_Msk     (0x1UL)                   /*!< TT_ADC PRI_REG: PRIVILEDGE (Bitfield-Mask: 0x01)      */
#define TT_ADC_PRI_REG_Reserved0_Pos      (1UL)                     /*!< TT_ADC PRI_REG: Reserved0 (Bit 1)                     */
#define TT_ADC_PRI_REG_Reserved0_Msk      (0xfffffffeUL)            /*!< TT_ADC PRI_REG: Reserved0 (Bitfield-Mask: 0x7fffffff) */
/* ========================================================  PRI_REG  ======================================================== */
#define TT_ADC_PRI_REG_PRIVILEDGE_Pos     (0UL)                     /*!< TT_ADC PRI_REG: PRIVILEDGE (Bit 0)                    */
#define TT_ADC_PRI_REG_PRIVILEDGE_Msk     (0x1UL)                   /*!< TT_ADC PRI_REG: PRIVILEDGE (Bitfield-Mask: 0x01)      */
/* =======================================================  ADC_TEST  ======================================================== */
#define TT_ADC_ADC_TEST_ADC_SELF_TEST_SEL_Pos (0UL)                 /*!< TT_ADC ADC_TEST: ADC_SELF_TEST_SEL (Bit 0)            */
#define TT_ADC_ADC_TEST_ADC_SELF_TEST_SEL_Msk (0xffUL)              /*!< TT_ADC ADC_TEST: ADC_SELF_TEST_SEL (Bitfield-Mask: 0xff) */
#define TT_ADC_ADC_TEST_ADC_SELF_TEST_EN_Pos (8UL)                  /*!< TT_ADC ADC_TEST: ADC_SELF_TEST_EN (Bit 8)             */
#define TT_ADC_ADC_TEST_ADC_SELF_TEST_EN_Msk (0x100UL)              /*!< TT_ADC ADC_TEST: ADC_SELF_TEST_EN (Bitfield-Mask: 0x01) */
#define TT_ADC_ADC_TEST_Reserved0_Pos     (9UL)                     /*!< TT_ADC ADC_TEST: Reserved0 (Bit 9)                    */
#define TT_ADC_ADC_TEST_Reserved0_Msk     (0xfffffe00UL)            /*!< TT_ADC ADC_TEST: Reserved0 (Bitfield-Mask: 0x7fffff)  */
/* =======================================================  PROBE_SEL  ======================================================= */
#define TT_ADC_PROBE_SEL_PROBLE_SEL_Pos   (0UL)                     /*!< TT_ADC PROBE_SEL: PROBLE_SEL (Bit 0)                  */
#define TT_ADC_PROBE_SEL_PROBLE_SEL_Msk   (0x7UL)                   /*!< TT_ADC PROBE_SEL: PROBLE_SEL (Bitfield-Mask: 0x07)    */
#define TT_ADC_PROBE_SEL_PROBLE_EN_Pos    (3UL)                     /*!< TT_ADC PROBE_SEL: PROBLE_EN (Bit 3)                   */
#define TT_ADC_PROBE_SEL_PROBLE_EN_Msk    (0x8UL)                   /*!< TT_ADC PROBE_SEL: PROBLE_EN (Bitfield-Mask: 0x01)     */
#define TT_ADC_PROBE_SEL_ADC_ANALOG_SEL_Pos (4UL)                   /*!< TT_ADC PROBE_SEL: ADC_ANALOG_SEL (Bit 4)              */
#define TT_ADC_PROBE_SEL_ADC_ANALOG_SEL_Msk (0x70UL)                /*!< TT_ADC PROBE_SEL: ADC_ANALOG_SEL (Bitfield-Mask: 0x07) */
#define TT_ADC_PROBE_SEL_ADC_BYPASS_Pos   (7UL)                     /*!< TT_ADC PROBE_SEL: ADC_BYPASS (Bit 7)                  */
#define TT_ADC_PROBE_SEL_ADC_BYPASS_Msk   (0x80UL)                  /*!< TT_ADC PROBE_SEL: ADC_BYPASS (Bitfield-Mask: 0x01)    */
#define TT_ADC_PROBE_SEL_Reserved0_Pos    (8UL)                     /*!< TT_ADC PROBE_SEL: Reserved0 (Bit 8)                   */
#define TT_ADC_PROBE_SEL_Reserved0_Msk    (0xff00UL)                /*!< TT_ADC PROBE_SEL: Reserved0 (Bitfield-Mask: 0xff)     */
#define TT_ADC_PROBE_SEL_WR_PROT_Pos      (16UL)                    /*!< TT_ADC PROBE_SEL: WR_PROT (Bit 16)                    */
#define TT_ADC_PROBE_SEL_WR_PROT_Msk      (0xffff0000UL)            /*!< TT_ADC PROBE_SEL: WR_PROT (Bitfield-Mask: 0xffff)     */

/* =========================================================================================================================== */
/* ================                                         A0CYREGT                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  A0CYCFR  ======================================================== */
#define A0CYREGT_A0CYCFR_HCOMPEN_Pos      (0UL)                     /*!< A0CYREGT A0CYCFR: HCOMPEN (Bit 0)                     */
#define A0CYREGT_A0CYCFR_HCOMPEN_Msk      (0x1UL)                   /*!< A0CYREGT A0CYCFR: HCOMPEN (Bitfield-Mask: 0x01)       */
#define A0CYREGT_A0CYCFR_LCOMPEN_Pos      (1UL)                     /*!< A0CYREGT A0CYCFR: LCOMPEN (Bit 1)                     */
#define A0CYREGT_A0CYCFR_LCOMPEN_Msk      (0x2UL)                   /*!< A0CYREGT A0CYCFR: LCOMPEN (Bitfield-Mask: 0x01)       */
#define A0CYREGT_A0CYCFR_FIREN_Pos        (2UL)                     /*!< A0CYREGT A0CYCFR: FIREN (Bit 2)                       */
#define A0CYREGT_A0CYCFR_FIREN_Msk        (0x4UL)                   /*!< A0CYREGT A0CYCFR: FIREN (Bitfield-Mask: 0x01)         */
#define A0CYREGT_A0CYCFR_FSAMPEN_Pos      (3UL)                     /*!< A0CYREGT A0CYCFR: FSAMPEN (Bit 3)                     */
#define A0CYREGT_A0CYCFR_FSAMPEN_Msk      (0x8UL)                   /*!< A0CYREGT A0CYCFR: FSAMPEN (Bitfield-Mask: 0x01)       */
#define A0CYREGT_A0CYCFR_TRGINTIN_Pos     (4UL)                     /*!< A0CYREGT A0CYCFR: TRGINTIN (Bit 4)                       */
#define A0CYREGT_A0CYCFR_TRGINTIN_Msk     (0x10UL)                   /*!< A0CYREGT A0CYCFR: TRGINTIN (Bitfield-Mask: 0x10)         */
#define A0CYREGT_A0CYCFR_TRGDMAINTEN_Pos  (5UL)                     /*!< A0CYREGT A0CYCFR: TRGDMAINTEN (Bit 5)                     */
#define A0CYREGT_A0CYCFR_TRGDMAINTEN_Msk  (0x20UL)                   /*!< A0CYREGT A0CYCFR: TRGDMAINTEN (Bitfield-Mask: 0x20)       */
#define A0CYREGT_A0CYCFR_TIMEOUTINTEN_Pos (6UL)                     /*!< A0CYREGT A0CYCFR: TIMEOUTINTEN (Bit 6)                */
#define A0CYREGT_A0CYCFR_TIMEOUTINTEN_Msk (0x40UL)                  /*!< A0CYREGT A0CYCFR: TIMEOUTINTEN (Bitfield-Mask: 0x01)  */
#define A0CYREGT_A0CYCFR_COMPINTEN_Pos    (7UL)                     /*!< A0CYREGT A0CYCFR: COMPINTEN (Bit 7)                   */
#define A0CYREGT_A0CYCFR_COMPINTEN_Msk    (0x80UL)                  /*!< A0CYREGT A0CYCFR: COMPINTEN (Bitfield-Mask: 0x01)     */
#define A0CYREGT_A0CYCFR_HCOMPINTEN_Pos   (8UL)                     /*!< A0CYREGT A0CYCFR: HCOMPINTEN (Bit 8)                  */
#define A0CYREGT_A0CYCFR_HCOMPINTEN_Msk   (0x100UL)                 /*!< A0CYREGT A0CYCFR: HCOMPINTEN (Bitfield-Mask: 0x01)    */
#define A0CYREGT_A0CYCFR_LCOMPINTEN_Pos   (9UL)                     /*!< A0CYREGT A0CYCFR: LCOMPINTEN (Bit 9)                  */
#define A0CYREGT_A0CYCFR_LCOMPINTEN_Msk   (0x200UL)                 /*!< A0CYREGT A0CYCFR: LCOMPINTEN (Bitfield-Mask: 0x01)    */
#define A0CYREGT_A0CYCFR_READYINTEN_Pos   (10UL)                    /*!< A0CYREGT A0CYCFR: READYINTEN (Bit 10)                 */
#define A0CYREGT_A0CYCFR_READYINTEN_Msk   (0x400UL)                 /*!< A0CYREGT A0CYCFR: READYINTEN (Bitfield-Mask: 0x01)    */
#define A0CYREGT_A0CYCFR_DMA_ERR_EN_Pos   (11UL)                    /*!< A0CYREGT A0CYCFR: DMA_ERR_EN (Bit 11)                 */
#define A0CYREGT_A0CYCFR_DMA_ERR_EN_Msk   (0x800UL)                 /*!< A0CYREGT A0CYCFR: DMA_ERR_EN (Bitfield-Mask: 0x01)    */
#define A0CYREGT_A0CYCFR_SAMPNUM_Pos      (12UL)                    /*!< A0CYREGT A0CYCFR: SAMPNUM (Bit 12)                    */
#define A0CYREGT_A0CYCFR_SAMPNUM_Msk      (0x1f000UL)               /*!< A0CYREGT A0CYCFR: SAMPNUM (Bitfield-Mask: 0x1f)       */
#define A0CYREGT_A0CYCFR_SHIFT_Pos        (20UL)                    /*!< A0CYREGT A0CYCFR: SHIFT (Bit 20)                      */
#define A0CYREGT_A0CYCFR_SHIFT_Msk        (0x1f00000UL)             /*!< A0CYREGT A0CYCFR: SHIFT (Bitfield-Mask: 0x1f)         */
#define A0CYREGT_A0CYCFR_CSAMP_EN_Pos     (25UL)                    /*!< A0CYREGT A0CYCFR: CSAMP_EN (Bit 25)                   */
#define A0CYREGT_A0CYCFR_CSAMP_EN_Msk     (0x2000000UL)             /*!< A0CYREGT A0CYCFR: CSAMP_EN (Bitfield-Mask: 0x01)      */
#define A0CYREGT_A0CYCFR_TRANS_SIZE_Pos   (26UL)                    /*!< A0CYREGT A0CYCFR: TRANS_SIZE (Bit 26)                 */
#define A0CYREGT_A0CYCFR_TRANS_SIZE_Msk   (0xfc000000UL)            /*!< A0CYREGT A0CYCFR: TRANS_SIZE (Bitfield-Mask: 0x3f)    */
/* =======================================================  A0CYCTRLR  ======================================================= */
#define A0CYREGT_A0CYCTRLR_REQ_Pos        (0UL)                     /*!< A0CYREGT A0CYCTRLR: REQ (Bit 0)                       */
#define A0CYREGT_A0CYCTRLR_REQ_Msk        (0x1UL)                   /*!< A0CYREGT A0CYCTRLR: REQ (Bitfield-Mask: 0x01)         */
#define A0CYREGT_A0CYCTRLR_CPRIO_Pos      (4UL)                     /*!< A0CYREGT A0CYCTRLR: CPRIO (Bit 4)                     */
#define A0CYREGT_A0CYCTRLR_CPRIO_Msk      (0x30UL)                  /*!< A0CYREGT A0CYCTRLR: CPRIO (Bitfield-Mask: 0x03)       */
#define A0CYREGT_A0CYCTRLR_CTRIGGLE_Pos   (8UL)                     /*!< A0CYREGT A0CYCTRLR: CTRIGGLE (Bit 8)                  */
#define A0CYREGT_A0CYCTRLR_CTRIGGLE_Msk   (0xf00UL)                 /*!< A0CYREGT A0CYCTRLR: CTRIGGLE (Bitfield-Mask: 0x0f)    */
#define A0CYREGT_A0CYCTRLR_PULSE_CTR_Pos  (12UL)                    /*!< A0CYREGT A0CYCTRLR: PULSE_CTR (Bit 12)                */
#define A0CYREGT_A0CYCTRLR_PULSE_CTR_Msk  (0x3000UL)                /*!< A0CYREGT A0CYCTRLR: PULSE_CTR (Bitfield-Mask: 0x03)   */
#define A0CYREGT_A0CYCTRLR_EXT_REQ_EN_Pos (14UL)                    /*!< A0CYREGT A0CYCTRLR: EXT_REQ_EN (Bit 14)               */
#define A0CYREGT_A0CYCTRLR_EXT_REQ_EN_Msk (0x4000UL)                /*!< A0CYREGT A0CYCTRLR: EXT_REQ_EN (Bitfield-Mask: 0x01)  */
/* ========================================================  A0CYTVR  ======================================================== */
#define A0CYREGT_A0CYTVR_THHOLDVALUEL_Pos (0UL)                     /*!< A0CYREGT A0CYTVR: THHOLDVALUEL (Bit 0)                */
#define A0CYREGT_A0CYTVR_THHOLDVALUEL_Msk (0xffffUL)                /*!< A0CYREGT A0CYTVR: THHOLDVALUEL (Bitfield-Mask: 0xffff) */
#define A0CYREGT_A0CYTVR_THHOLDVALUEH_Pos (16UL)                    /*!< A0CYREGT A0CYTVR: THHOLDVALUEH (Bit 16)               */
#define A0CYREGT_A0CYTVR_THHOLDVALUEH_Msk (0xffff0000UL)            /*!< A0CYREGT A0CYTVR: THHOLDVALUEH (Bitfield-Mask: 0xffff) */
/* ========================================================  A0CYSTR  ======================================================== */
#define A0CYREGT_A0CYSTR_READY_Pos        (0UL)                     /*!< A0CYREGT A0CYSTR: READY (Bit 0)                       */
#define A0CYREGT_A0CYSTR_READY_Msk        (0x1UL)                   /*!< A0CYREGT A0CYSTR: READY (Bitfield-Mask: 0x01)         */
#define A0CYREGT_A0CYSTR_DATAH_Pos        (1UL)                     /*!< A0CYREGT A0CYSTR: DATAH (Bit 1)                       */
#define A0CYREGT_A0CYSTR_DATAH_Msk        (0x2UL)                   /*!< A0CYREGT A0CYSTR: DATAH (Bitfield-Mask: 0x01)         */
#define A0CYREGT_A0CYSTR_DATAL_Pos        (2UL)                     /*!< A0CYREGT A0CYSTR: DATAL (Bit 2)                       */
#define A0CYREGT_A0CYSTR_DATAL_Msk        (0x4UL)                   /*!< A0CYREGT A0CYSTR: DATAL (Bitfield-Mask: 0x01)         */
#define A0CYREGT_A0CYSTR_DMA_RESPER_Pos   (3UL)                     /*!< A0CYREGT A0CYSTR: DMA_RESPER (Bit 3)                  */
#define A0CYREGT_A0CYSTR_DMA_RESPER_Msk   (0x8UL)                   /*!< A0CYREGT A0CYSTR: DMA_RESPER (Bitfield-Mask: 0x01)    */
#define A0CYREGT_A0CYSTR_COMPU_ER_Pos     (4UL)                     /*!< A0CYREGT A0CYSTR: COMPU_ER (Bit 4)                    */
#define A0CYREGT_A0CYSTR_COMPU_ER_Msk     (0x10UL)                  /*!< A0CYREGT A0CYSTR: COMPU_ER (Bitfield-Mask: 0x01)      */
#define A0CYREGT_A0CYSTR_TIMEOUT_ER_Pos   (5UL)                     /*!< A0CYREGT A0CYSTR: TIMEOUT_ER (Bit 5)                  */
#define A0CYREGT_A0CYSTR_TIMEOUT_ER_Msk   (0x20UL)                  /*!< A0CYREGT A0CYSTR: TIMEOUT_ER (Bitfield-Mask: 0x01)    */
/* ======================================================  A0CYRESULT  ======================================================= */
#define A0CYREGT_A0CYRESULT_RESULTDATA_Pos (0UL)                    /*!< A0CYREGT A0CYRESULT: RESULTDATA (Bit 0)               */
#define A0CYREGT_A0CYRESULT_RESULTDATA_Msk (0xffffUL)               /*!< A0CYREGT A0CYRESULT: RESULTDATA (Bitfield-Mask: 0xffff) */
/* =======================================================  A0DMAADDR  ======================================================= */
#define A0CYREGT_A0DMAADDR_DST_ADDR_Pos   (1UL)                     /*!< A0CYREGT A0DMAADDR: DST_ADDR (Bit 1)                  */
#define A0CYREGT_A0DMAADDR_DST_ADDR_Msk   (0xfffffffeUL)            /*!< A0CYREGT A0DMAADDR: DST_ADDR (Bitfield-Mask: 0xfffffffeUL) */
/* =======================================================  A0DMAADDRINCR  ======================================================= */
#define A0CYREGT_A0DMAADDR_INCR_ADDR_Pos  (0UL)                     /*!< A0CYREGT A0DMAADDR: INCR_ADDR (Bit 0)                */
#define A0CYREGT_A0DMAADDR_INCR_ADDR_Msk  (0x3fUL)                  /*!< A0CYREGT A0DMAADDR: INCR_ADDR (Bitfield-Mask: 0x3f)   */



/** @defgroup ADCx_AxCySTR_state_flags_definition 
  * @{
  */
#define TT_ADC_AxCySTR_READY_Msk                A0CYREGT_A0CYSTR_READY_Msk
#define TT_ADC_AxCySTR_DATAH_Msk                A0CYREGT_A0CYSTR_DATAH_Msk
#define TT_ADC_AxCySTR_DATAL_Msk                A0CYREGT_A0CYSTR_DATAL_Msk
#define TT_ADC_AxCySTR_DMA_RESPER_Msk           A0CYREGT_A0CYSTR_DMA_RESPER_Msk
#define TT_ADC_AxCySTR_COMPU_ER_Msk             A0CYREGT_A0CYSTR_COMPU_ER_Msk
#define TT_ADC_AxCySTR_TIMEOUT_ER_Msk           A0CYREGT_A0CYSTR_TIMEOUT_ER_Msk

#define TT_ADC_AxCySTR_READY_Pos                A0CYREGT_A0CYSTR_READY_Pos
#define TT_ADC_AxCySTR_DATAH_Pos                A0CYREGT_A0CYSTR_DATAH_Pos
#define TT_ADC_AxCySTR_DATAL_Pos                A0CYREGT_A0CYSTR_DATAL_Pos
#define TT_ADC_AxCySTR_DMA_RESPER_Pos           A0CYREGT_A0CYSTR_DMA_RESPER_Pos
#define TT_ADC_AxCySTR_COMPU_ER_Pos             A0CYREGT_A0CYSTR_COMPU_ER_Pos
#define TT_ADC_AxCySTR_TIMEOUT_ER_Pos           A0CYREGT_A0CYSTR_TIMEOUT_ER_Pos

/** @defgroup ADCx_CallBack_Event_flags_definition 
  * @{
  */ 
#define TT_ADC_CB_EVENT_DATA_REDAY        (0x1UL)
#define TT_ADC_CB_EVENT_THHOLD_HIGHT      (0x2UL)
#define TT_ADC_CB_EVENT_THHOLD_LOW        (0x4UL)
#define TT_ADC_CB_EVENT_DMA_RESPER        (0x8UL)
#define TT_ADC_CB_EVENT_COMP_ERROR        (0x10UL)
#define TT_ADC_CB_EVENT_TIMEOUT_ERROR     (0x20UL)
#define TT_ADC_CB_EVENT_DMA_READAY        (0x100UL)


/** @defgroup ADCx_STATE_flags_definition 
  * @{
  */ 
#define ADC_FLAG_READY_CHANNEL_0                     ((uint32)0x01)
#define ADC_FLAG_READY_CHANNEL_1                     ((uint32)0x02)
#define ADC_FLAG_READY_CHANNEL_2                     ((uint32)0x04)
#define ADC_FLAG_READY_CHANNEL_3                     ((uint32)0x08)
#define ADC_FLAG_READY_CHANNEL_4                     ((uint32)0x10)
#define ADC_FLAG_READY_CHANNEL_5                     ((uint32)0x20)
#define ADC_FLAG_READY_CHANNEL_6                     ((uint32)0x40)
#define ADC_FLAG_READY_CHANNEL_7                     ((uint32)0x80)
#define ADC_FLAG_READY_CHANNEL_8                     ((uint32)0x100)
#define ADC_FLAG_READY_CHANNEL_9                     ((uint32)0x200)
#define ADC_FLAG_READY_CHANNEL_10                    ((uint32)0x400)
#define ADC_FLAG_READY_CHANNEL_11                    ((uint32)0x800)
#define ADC_FLAG_READY_CHANNEL_12                    ((uint32)0x1000)
#define ADC_FLAG_READY_CHANNEL_13                    ((uint32)0x2000)
#define ADC_FLAG_ERROR_CHANNEL_0                     ((uint32)0x10000)
#define ADC_FLAG_ERROR_CHANNEL_1                     ((uint32)0x20000)
#define ADC_FLAG_ERROR_CHANNEL_2                     ((uint32)0x40000)
#define ADC_FLAG_ERROR_CHANNEL_3                     ((uint32)0x80000)
#define ADC_FLAG_ERROR_CHANNEL_4                     ((uint32)0x100000)
#define ADC_FLAG_ERROR_CHANNEL_5                     ((uint32)0x200000)
#define ADC_FLAG_ERROR_CHANNEL_6                     ((uint32)0x400000)
#define ADC_FLAG_ERROR_CHANNEL_7                     ((uint32)0x800000)
#define ADC_FLAG_ERROR_CHANNEL_8                     ((uint32)0x1000000)
#define ADC_FLAG_ERROR_CHANNEL_9                     ((uint32)0x2000000)
#define ADC_FLAG_ERROR_CHANNEL_10                    ((uint32)0x4000000)
#define ADC_FLAG_ERROR_CHANNEL_11                    ((uint32)0x8000000)
#define ADC_FLAG_ERROR_CHANNEL_12                    ((uint32)0x10000000)
#define ADC_FLAG_ERROR_CHANNEL_13                    ((uint32)0x20000000)


#define ADC_FLAG_ALL_CHANNEL_ERROR                   ((uint32)0x7FFF0000)
#define ADC_FLAG_ALL_CHANNEL_READY                   ((uint32)0x3FFF)
#define ADC_FLAG_READY_CHANNEL(CH)                   ((uint32)(ADC_FLAG_READY_CHANNEL_0 << (CH)))
#define ADC_FLAG_ERROR_CHANNEL(CH)                   ((uint32)(ADC_FLAG_ERROR_CHANNEL_0 << (CH)))

#define ADC_FLAG_THREHOLD_ERROR_MASK                 ((uint32)(A0CYREGT_A0CYSTR_DATAH_Pos |A0CYREGT_A0CYSTR_DATAL_Msk))




#define TT_ADC_PRECISION     12
#define TT_ADC_VALUE_MAX    ((1 << TT_ADC_PRECISION) - 1)

// ADC flags
#define ADC_FLAG_UNINITIALIZED       (0U)
#define ADC_FLAG_INITIALIZED       (1U)

#define TT_ADC_TRANSFER_SIZE_MAX       (63U)
#define TT_ADC_DMAADDR_INCR_MAX       (63U)


/** @defgroup ADCx_AxCyCTRLR_flags_definition 
* @{
*/ 
#define TT_ADC_AxCyCTRLR_REQ_Pos            A0CYREGT_A0CYCTRLR_REQ_Pos
#define TT_ADC_AxCyCTRLR_REQ_Msk            A0CYREGT_A0CYCTRLR_REQ_Msk
#define TT_ADC_AxCyCTRLR_CPRIO_Pos          A0CYREGT_A0CYCTRLR_CPRIO_Pos
#define TT_ADC_AxCyCTRLR_CPRIO_Msk          A0CYREGT_A0CYCTRLR_CPRIO_Msk
#define TT_ADC_AxCyCTRLR_CTRIGGLE_Pos       A0CYREGT_A0CYCTRLR_CTRIGGLE_Pos
#define TT_ADC_AxCyCTRLR_CTRIGGLE_Msk       A0CYREGT_A0CYCTRLR_CTRIGGLE_Msk
#define TT_ADC_AxCyCTRLR_PLUSECTRL_Pos      A0CYREGT_A0CYCTRLR_PULSE_CTR_Pos
#define TT_ADC_AxCyCTRLR_PLUSECTRL_Msk      A0CYREGT_A0CYCTRLR_PULSE_CTR_Msk
#define TT_ADC_AxCyCTRLR_EXTTRGEN_Pos       A0CYREGT_A0CYCTRLR_EXT_REQ_EN_Pos
#define TT_ADC_AxCyCTRLR_EXTTRGEN_Msk       A0CYREGT_A0CYCTRLR_EXT_REQ_EN_Msk

/** @defgroup ADCx_AxCyCFR_flags_definition 
* @{
*/ 
#define TT_ADC_AxCyCFR_HCOMPEN_Pos          A0CYREGT_A0CYCFR_HCOMPEN_Pos
#define TT_ADC_AxCyCFR_HCOMPEN_Msk          A0CYREGT_A0CYCFR_HCOMPEN_Msk
#define TT_ADC_AxCyCFR_LCOMPEN_Pos          A0CYREGT_A0CYCFR_LCOMPEN_Pos
#define TT_ADC_AxCyCFR_LCOMPEN_Msk          A0CYREGT_A0CYCFR_LCOMPEN_Msk
#define TT_ADC_AxCyCFR_FIREN_Pos            A0CYREGT_A0CYCFR_FIREN_Pos
#define TT_ADC_AxCyCFR_FIREN_Msk            A0CYREGT_A0CYCFR_FIREN_Msk
#define TT_ADC_AxCyCFR_FSAMPEN_Pos          A0CYREGT_A0CYCFR_FSAMPEN_Pos
#define TT_ADC_AxCyCFR_FSAMPEN_Msk          A0CYREGT_A0CYCFR_FSAMPEN_Msk
#define TT_ADC_AxCyCFR_TRGINTIN_Pos         A0CYREGT_A0CYCFR_TRGINTIN_Pos
#define TT_ADC_AxCyCFR_TRGINTIN_Msk         A0CYREGT_A0CYCFR_TRGINTIN_Msk
#define TT_ADC_AxCyCFR_TRGDMAINTEN_Pos      A0CYREGT_A0CYCFR_TRGDMAINTEN_Pos
#define TT_ADC_AxCyCFR_TRGDMAINTEN_Msk      A0CYREGT_A0CYCFR_TRGDMAINTEN_Msk
#define TT_ADC_AxCyCFR_TIMEOUTINTEN_Pos     A0CYREGT_A0CYCFR_TIMEOUTINTEN_Pos
#define TT_ADC_AxCyCFR_TIMEOUTINTEN_Msk     A0CYREGT_A0CYCFR_TIMEOUTINTEN_Msk
#define TT_ADC_AxCyCFR_COMPINTEN_Pos        A0CYREGT_A0CYCFR_COMPINTEN_Pos
#define TT_ADC_AxCyCFR_COMPINTEN_Msk        A0CYREGT_A0CYCFR_COMPINTEN_Msk
#define TT_ADC_AxCyCFR_HCOMPINTEN_Pos       A0CYREGT_A0CYCFR_HCOMPINTEN_Pos
#define TT_ADC_AxCyCFR_HCOMPINTEN_Msk       A0CYREGT_A0CYCFR_HCOMPINTEN_Msk
#define TT_ADC_AxCyCFR_LCOMPINTEN_Pos       A0CYREGT_A0CYCFR_LCOMPINTEN_Pos
#define TT_ADC_AxCyCFR_LCOMPINTEN_Msk       A0CYREGT_A0CYCFR_LCOMPINTEN_Msk
#define TT_ADC_AxCyCFR_READYINTEN_Pos       A0CYREGT_A0CYCFR_READYINTEN_Pos
#define TT_ADC_AxCyCFR_READYINTEN_Msk       A0CYREGT_A0CYCFR_READYINTEN_Msk
#define TT_ADC_AxCyCFR_SAMPNUM_Pos          A0CYREGT_A0CYCFR_SAMPNUM_Pos
#define TT_ADC_AxCyCFR_SAMPNUM_Msk          A0CYREGT_A0CYCFR_SAMPNUM_Msk
#define TT_ADC_AxCyCFR_SHIFT_Pos            A0CYREGT_A0CYCFR_SHIFT_Pos
#define TT_ADC_AxCyCFR_SHIFT_Msk            A0CYREGT_A0CYCFR_SHIFT_Msk
#define TT_ADC_AxCyCFR_CAMPEN_Pos           A0CYREGT_A0CYCFR_CSAMP_EN_Pos
#define TT_ADC_AxCyCFR_CAMPEN_Msk           A0CYREGT_A0CYCFR_CSAMP_EN_Msk
#define TT_ADC_AxCyCFR_DMA_ERR_Pos          A0CYREGT_A0CYCFR_DMA_ERR_EN_Pos
#define TT_ADC_AxCyCFR_DMA_ERR_Msk          A0CYREGT_A0CYCFR_DMA_ERR_EN_Msk
#define TT_ADC_AxCyCFR_TRANSIZE_Pos         A0CYREGT_A0CYCFR_TRANS_SIZE_Pos
#define TT_ADC_AxCyCFR_TRANSIZE_Msk         A0CYREGT_A0CYCFR_TRANS_SIZE_Msk


#define TT_ADC_AXCFR_COMPU_POLARITY_Pos       (20UL) 
#define TT_ADC_AXCFR_COMPU_POLARITY_Msk       (0x100000UL) 

/** @defgroup ADCx_AxCyTVR_flags_definition 
* @{
*/ 
#define TT_ADC_AxCyTVR_THHOLDVALUEL_Pos         A0CYREGT_A0CYTVR_THHOLDVALUEL_Pos
#define TT_ADC_AxCyTVR_THHOLDVALUEL_Msk         A0CYREGT_A0CYTVR_THHOLDVALUEL_Msk
#define TT_ADC_AxCyTVR_THHOLDVALUEH_Pos         A0CYREGT_A0CYTVR_THHOLDVALUEH_Pos
#define TT_ADC_AxCyTVR_THHOLDVALUEH_Msk         A0CYREGT_A0CYTVR_THHOLDVALUEH_Msk


/** @defgroup ADCx_AxCyDMAADDR_flags_definition 
* @{
*/ 
#define TT_ADC_AxCyDMAADDR_INC_Pos         A0CYREGT_A0DMAADDR_INCR_ADDR_Pos
#define TT_ADC_AxCyDMAADDR_INC_Msk         A0CYREGT_A0DMAADDR_INCR_ADDR_Msk
#define TT_ADC_AxCyDMAADDR_DST_Pos         A0CYREGT_A0DMAADDR_DST_ADDR_Pos
#define TT_ADC_AxCyDMAADDR_DST_Msk         A0CYREGT_A0DMAADDR_DST_ADDR_Msk




#ifdef __cplusplus
}
#endif

#endif  /* end of A8V2E_ADC_H */
