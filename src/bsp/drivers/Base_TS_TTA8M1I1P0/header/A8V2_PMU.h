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
#ifndef A8V2_PMU_H
#define A8V2_PMU_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_PMU_VENDOR_ID_H                     1541
#define A8V2_PMU_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_PMU_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_PMU_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_PMU_SW_MAJOR_VERSION_H              1
#define A8V2_PMU_SW_MINOR_VERSION_H              1
#define A8V2_PMU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_PMU.h and TT_Common.h file version check */
#if (A8V2_PMU_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_PMU.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_PMU_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_PMU_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_PMU_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_PMU.h and TT_Common.h are different"
#endif
#if ((A8V2_PMU_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_PMU_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_PMU_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_PMU.h and TT_Common.h are different"
#endif


/* =========================================================================================================================== */
/* ================                                          TT_PMU                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief PMU Controller, did not access direct (TT_PMU)
  */

typedef struct {                                /*!< (@ 0x400A0000) TT_PMU Structure                                           */
  __IOM uint32_t  CR;                           /*!< (@ 0x00000000) Control Register                                           */
  __IOM uint32_t  USER0;                        /*!< (@ 0x00000004) User Defined Register 0                                    */
  __IOM uint32_t  USER1;                        /*!< (@ 0x00000008) User Defined Register 1                                    */
  __IOM uint32_t  LOCAL_RST;                    /*!< (@ 0x0000000C) PMU Local reset Register                                   */
  __IM  uint32_t  STATUS;                       /*!< (@ 0x00000010) Program Pointer Register                                   */
  __IOM uint32_t  SUPV_REG;                     /*!< (@ 0x00000014) SUPV_REG                                                   */
  __IOM uint32_t  BUCK_CR;                      /*!< (@ 0x00000018) Program Pointer Register                                   */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  IER;                          /*!< (@ 0x00000020) Input enbale register                                      */
  __IOM uint32_t  OER;                          /*!< (@ 0x00000024) Output enbale register                                     */
  __IOM uint32_t  DOR;                          /*!< (@ 0x00000028) Data Output register                                       */
  __IOM uint32_t  PUR;                          /*!< (@ 0x0000002C) Pull up register                                           */
  __IOM uint32_t  PDR;                          /*!< (@ 0x00000030) Pull up register                                           */
  __IM  uint32_t  RESERVED1[3];
  __IOM uint32_t  NSR;                          /*!< (@ 0x00000040) Nmi Status Flag Register                                   */
  __IOM uint32_t  NCR;                          /*!< (@ 0x00000044) Nmi Config Register                                        */
  __IOM uint32_t  WISR;                         /*!< (@ 0x00000048) Wakeuo/Interrupt Status Flag Register                      */
  __IOM uint32_t  IRER;                         /*!< (@ 0x0000004C) Interrupt Request Enable Register                          */
  __IOM uint32_t  WRER;                         /*!< (@ 0x00000050) Wakeup Request Enable Register                             */
  __IOM uint32_t  WIREER;                       /*!< (@ 0x00000054) Wakeup/Interrupt Rising-edge Event Enable Register         */
  __IOM uint32_t  WIFEER;                       /*!< (@ 0x00000058) Wakeup/Interrupt Falling-edge Event Enable Register        */
  __IOM uint32_t  WIFER;                        /*!< (@ 0x0000005C) Wakeup/Interrupt Filter Enable Register                    */
  __IM  uint32_t  RESERVED2[39];
  __IM  uint32_t  ID_REG;                       /*!< (@ 0x000000FC) ID_REG                                                     */
} Pmu_RegType, *Pmu_RegMemMapPtr;               /*!< Size = 4096 (0x1000)                                                      */

/** Number of instances of the TIMER module. */
#define TT_PMU_INSTANCE_COUNT                 (1U)

/* TT_PMU - Peripheral instance base addresses */
/** Peripheral TT_PMU base address */
#define TT_PMU_BASE                           (0x400A0000UL)
/** Peripheral TT_PMU base pointer */
#define TT_PMU                                ((Pmu_RegMemMapPtr)TT_PMU_BASE)
/** Array initializer of TT_PMU peripheral base addresses */
#define TT_PMU_BASE_ADDRS                     { TT_PMU_BASE }
/** Array initializer of TT_PMU peripheral base pointers */
#define TT_PMU_BASE_PTRS                      { TT_PMU }

/* =========================================================================================================================== */
/* ================                                          TT_PMU                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR  =========================================================== */
#define TT_PMU_CR_OSCIO_PD_Pos            (0UL)                     /*!< TT_PMU CR: OSCIO_PD (Bit 0)                           */
#define TT_PMU_CR_OSCIO_PD_Msk            (0x1UL)                   /*!< TT_PMU CR: OSCIO_PD (Bitfield-Mask: 0x01)             */
#define TT_PMU_CR_LVD_TRIG_EN_Pos         (1UL)                     /*!< TT_PMU CR: LVD_TRIG_EN (Bit 1)                        */
#define TT_PMU_CR_LVD_TRIG_EN_Msk         (0x2UL)                   /*!< TT_PMU CR: LVD_TRIG_EN (Bitfield-Mask: 0x01)          */
#define TT_PMU_CR_WKUP_EN_Pos             (2UL)                     /*!< TT_PMU CR: WKUP_EN (Bit 2)                            */
#define TT_PMU_CR_WKUP_EN_Msk             (0x4UL)                   /*!< TT_PMU CR: WKUP_EN (Bitfield-Mask: 0x01)              */
#define TT_PMU_CR_WKUP_DLY_Pos            (8UL)                     /*!< TT_PMU CR: WKUP_DLY (Bit 8)                           */
#define TT_PMU_CR_WKUP_DLY_Msk            (0xff00UL)                /*!< TT_PMU CR: WKUP_DLY (Bitfield-Mask: 0xff)             */
#define TT_PMU_CR_PROBE_SEL_Pos           (16UL)                    /*!< TT_PMU CR: PROBE_SEL (Bit 16)                         */
#define TT_PMU_CR_PROBE_SEL_Msk           (0x1f0000UL)              /*!< TT_PMU CR: PROBE_SEL (Bitfield-Mask: 0x1f)            */
/* =========================================================  USER0  ========================================================= */
/* =========================================================  USER1  ========================================================= */
/* =======================================================  LOCAL_RST  ======================================================= */
/* ========================================================  STATUS  ========================================================= */
#define TT_PMU_STATUS_IDLE_Pos            (0UL)                     /*!< TT_PMU STATUS: IDLE (Bit 0)                           */
#define TT_PMU_STATUS_IDLE_Msk            (0x1UL)                   /*!< TT_PMU STATUS: IDLE (Bitfield-Mask: 0x01)             */
#define TT_PMU_STATUS_WAKEUP_Pos          (2UL)                     /*!< TT_PMU STATUS: WAKEUP (Bit 2)                         */
#define TT_PMU_STATUS_WAKEUP_Msk          (0x4UL)                   /*!< TT_PMU STATUS: WAKEUP (Bitfield-Mask: 0x01)           */
#define TT_PMU_STATUS_WKUP_NMI_Pos        (3UL)                     /*!< TT_PMU STATUS: WKUP_NMI (Bit 3)                       */
#define TT_PMU_STATUS_WKUP_NMI_Msk        (0x8UL)                   /*!< TT_PMU STATUS: WKUP_NMI (Bitfield-Mask: 0x01)         */
#define TT_PMU_STATUS_LDO_TIMEOUT_Pos     (4UL)                     /*!< TT_PMU STATUS: LDO_TIMEOUT (Bit 4)                    */
#define TT_PMU_STATUS_LDO_TIMEOUT_Msk     (0x10UL)                  /*!< TT_PMU STATUS: LDO_TIMEOUT (Bitfield-Mask: 0x01)      */
#define TT_PMU_STATUS_DCDC_TIMEOUT_Pos    (5UL)                     /*!< TT_PMU STATUS: DCDC_TIMEOUT (Bit 5)                   */
#define TT_PMU_STATUS_DCDC_TIMEOUT_Msk    (0x20UL)                  /*!< TT_PMU STATUS: DCDC_TIMEOUT (Bitfield-Mask: 0x01)     */
#define TT_PMU_STATUS_PORN_TIMEOUT_Pos    (6UL)                     /*!< TT_PMU STATUS: PORN_TIMEOUT (Bit 6)                   */
#define TT_PMU_STATUS_PORN_TIMEOUT_Msk    (0x40UL)                  /*!< TT_PMU STATUS: PORN_TIMEOUT (Bitfield-Mask: 0x01)     */
/* =======================================================  SUPV_REG  ======================================================== */
#define TT_PMU_SUPV_REG_SUPV_Pos          (0UL)                     /*!< TT_PMU SUPV_REG: SUPV (Bit 0)                         */
#define TT_PMU_SUPV_REG_SUPV_Msk          (0x1UL)                   /*!< TT_PMU SUPV_REG: SUPV (Bitfield-Mask: 0x01)           */
/* ========================================================  BUCK_CR  ======================================================== */
#define TT_PMU_BUCK_CR_BUCK_PWM_Pos       (0UL)                     /*!< TT_PMU BUCK_CR: BUCK_PWM (Bit 0)                      */
#define TT_PMU_BUCK_CR_BUCK_PWM_Msk       (0x1UL)                   /*!< TT_PMU BUCK_CR: BUCK_PWM (Bitfield-Mask: 0x01)        */
#define TT_PMU_BUCK_CR_BUCK_SLEEP_Pos     (1UL)                     /*!< TT_PMU BUCK_CR: BUCK_SLEEP (Bit 1)                    */
#define TT_PMU_BUCK_CR_BUCK_SLEEP_Msk     (0x2UL)                   /*!< TT_PMU BUCK_CR: BUCK_SLEEP (Bitfield-Mask: 0x01)      */
/* ==========================================================  IER  ========================================================== */
#define TT_PMU_IER_WAKEUP_0_Pos           (0UL)                     /*!< TT_PMU IER: WAKEUP_0 (Bit 0)                          */
#define TT_PMU_IER_WAKEUP_0_Msk           (0x1UL)                   /*!< TT_PMU IER: WAKEUP_0 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_1_Pos           (1UL)                     /*!< TT_PMU IER: WAKEUP_1 (Bit 1)                          */
#define TT_PMU_IER_WAKEUP_1_Msk           (0x2UL)                   /*!< TT_PMU IER: WAKEUP_1 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_2_Pos           (2UL)                     /*!< TT_PMU IER: WAKEUP_2 (Bit 2)                          */
#define TT_PMU_IER_WAKEUP_2_Msk           (0x4UL)                   /*!< TT_PMU IER: WAKEUP_2 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_3_Pos           (3UL)                     /*!< TT_PMU IER: WAKEUP_3 (Bit 3)                          */
#define TT_PMU_IER_WAKEUP_3_Msk           (0x8UL)                   /*!< TT_PMU IER: WAKEUP_3 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_4_Pos           (4UL)                     /*!< TT_PMU IER: WAKEUP_4 (Bit 4)                          */
#define TT_PMU_IER_WAKEUP_4_Msk           (0x10UL)                  /*!< TT_PMU IER: WAKEUP_4 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_5_Pos           (5UL)                     /*!< TT_PMU IER: WAKEUP_5 (Bit 5)                          */
#define TT_PMU_IER_WAKEUP_5_Msk           (0x20UL)                  /*!< TT_PMU IER: WAKEUP_5 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_6_Pos           (6UL)                     /*!< TT_PMU IER: WAKEUP_6 (Bit 6)                          */
#define TT_PMU_IER_WAKEUP_6_Msk           (0x40UL)                  /*!< TT_PMU IER: WAKEUP_6 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_7_Pos           (7UL)                     /*!< TT_PMU IER: WAKEUP_7 (Bit 7)                          */
#define TT_PMU_IER_WAKEUP_7_Msk           (0x80UL)                  /*!< TT_PMU IER: WAKEUP_7 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_8_Pos           (8UL)                     /*!< TT_PMU IER: WAKEUP_8 (Bit 8)                          */
#define TT_PMU_IER_WAKEUP_8_Msk           (0x100UL)                 /*!< TT_PMU IER: WAKEUP_8 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_9_Pos           (9UL)                     /*!< TT_PMU IER: WAKEUP_9 (Bit 9)                          */
#define TT_PMU_IER_WAKEUP_9_Msk           (0x200UL)                 /*!< TT_PMU IER: WAKEUP_9 (Bitfield-Mask: 0x01)            */
#define TT_PMU_IER_WAKEUP_10_Pos          (10UL)                    /*!< TT_PMU IER: WAKEUP_10 (Bit 10)                        */
#define TT_PMU_IER_WAKEUP_10_Msk          (0x400UL)                 /*!< TT_PMU IER: WAKEUP_10 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_11_Pos          (11UL)                    /*!< TT_PMU IER: WAKEUP_11 (Bit 11)                        */
#define TT_PMU_IER_WAKEUP_11_Msk          (0x800UL)                 /*!< TT_PMU IER: WAKEUP_11 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_12_Pos          (12UL)                    /*!< TT_PMU IER: WAKEUP_12 (Bit 12)                        */
#define TT_PMU_IER_WAKEUP_12_Msk          (0x1000UL)                /*!< TT_PMU IER: WAKEUP_12 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_13_Pos          (13UL)                    /*!< TT_PMU IER: WAKEUP_13 (Bit 13)                        */
#define TT_PMU_IER_WAKEUP_13_Msk          (0x2000UL)                /*!< TT_PMU IER: WAKEUP_13 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_14_Pos          (14UL)                    /*!< TT_PMU IER: WAKEUP_14 (Bit 14)                        */
#define TT_PMU_IER_WAKEUP_14_Msk          (0x4000UL)                /*!< TT_PMU IER: WAKEUP_14 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_15_Pos          (15UL)                    /*!< TT_PMU IER: WAKEUP_15 (Bit 15)                        */
#define TT_PMU_IER_WAKEUP_15_Msk          (0x8000UL)                /*!< TT_PMU IER: WAKEUP_15 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_16_Pos          (16UL)                    /*!< TT_PMU IER: WAKEUP_16 (Bit 16)                        */
#define TT_PMU_IER_WAKEUP_16_Msk          (0x10000UL)               /*!< TT_PMU IER: WAKEUP_16 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_17_Pos          (17UL)                    /*!< TT_PMU IER: WAKEUP_17 (Bit 17)                        */
#define TT_PMU_IER_WAKEUP_17_Msk          (0x20000UL)               /*!< TT_PMU IER: WAKEUP_17 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_18_Pos          (18UL)                    /*!< TT_PMU IER: WAKEUP_18 (Bit 18)                        */
#define TT_PMU_IER_WAKEUP_18_Msk          (0x40000UL)               /*!< TT_PMU IER: WAKEUP_18 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_19_Pos          (19UL)                    /*!< TT_PMU IER: WAKEUP_19 (Bit 19)                        */
#define TT_PMU_IER_WAKEUP_19_Msk          (0x80000UL)               /*!< TT_PMU IER: WAKEUP_19 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_20_Pos          (20UL)                    /*!< TT_PMU IER: WAKEUP_20 (Bit 20)                        */
#define TT_PMU_IER_WAKEUP_20_Msk          (0x100000UL)              /*!< TT_PMU IER: WAKEUP_20 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_21_Pos          (21UL)                    /*!< TT_PMU IER: WAKEUP_21 (Bit 21)                        */
#define TT_PMU_IER_WAKEUP_21_Msk          (0x200000UL)              /*!< TT_PMU IER: WAKEUP_21 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_22_Pos          (22UL)                    /*!< TT_PMU IER: WAKEUP_22 (Bit 22)                        */
#define TT_PMU_IER_WAKEUP_22_Msk          (0x400000UL)              /*!< TT_PMU IER: WAKEUP_22 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_23_Pos          (23UL)                    /*!< TT_PMU IER: WAKEUP_23 (Bit 23)                        */
#define TT_PMU_IER_WAKEUP_23_Msk          (0x800000UL)              /*!< TT_PMU IER: WAKEUP_23 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_24_Pos          (24UL)                    /*!< TT_PMU IER: WAKEUP_24 (Bit 24)                        */
#define TT_PMU_IER_WAKEUP_24_Msk          (0x1000000UL)             /*!< TT_PMU IER: WAKEUP_24 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_25_Pos          (25UL)                    /*!< TT_PMU IER: WAKEUP_25 (Bit 25)                        */
#define TT_PMU_IER_WAKEUP_25_Msk          (0x2000000UL)             /*!< TT_PMU IER: WAKEUP_25 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_26_Pos          (26UL)                    /*!< TT_PMU IER: WAKEUP_26 (Bit 26)                        */
#define TT_PMU_IER_WAKEUP_26_Msk          (0x4000000UL)             /*!< TT_PMU IER: WAKEUP_26 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_27_Pos          (27UL)                    /*!< TT_PMU IER: WAKEUP_27 (Bit 27)                        */
#define TT_PMU_IER_WAKEUP_27_Msk          (0x8000000UL)             /*!< TT_PMU IER: WAKEUP_27 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_28_Pos          (28UL)                    /*!< TT_PMU IER: WAKEUP_28 (Bit 28)                        */
#define TT_PMU_IER_WAKEUP_28_Msk          (0x10000000UL)            /*!< TT_PMU IER: WAKEUP_28 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_29_Pos          (29UL)                    /*!< TT_PMU IER: WAKEUP_29 (Bit 29)                        */
#define TT_PMU_IER_WAKEUP_29_Msk          (0x20000000UL)            /*!< TT_PMU IER: WAKEUP_29 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_30_Pos          (30UL)                    /*!< TT_PMU IER: WAKEUP_30 (Bit 30)                        */
#define TT_PMU_IER_WAKEUP_30_Msk          (0x40000000UL)            /*!< TT_PMU IER: WAKEUP_30 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IER_WAKEUP_31_Pos          (31UL)                    /*!< TT_PMU IER: WAKEUP_31 (Bit 31)                        */
#define TT_PMU_IER_WAKEUP_31_Msk          (0x80000000UL)            /*!< TT_PMU IER: WAKEUP_31 (Bitfield-Mask: 0x01)           */
/* ==========================================================  OER  ========================================================== */
#define TT_PMU_OER_WAKEUP_0_Pos           (0UL)                     /*!< TT_PMU OER: WAKEUP_0 (Bit 0)                          */
#define TT_PMU_OER_WAKEUP_0_Msk           (0x1UL)                   /*!< TT_PMU OER: WAKEUP_0 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_1_Pos           (1UL)                     /*!< TT_PMU OER: WAKEUP_1 (Bit 1)                          */
#define TT_PMU_OER_WAKEUP_1_Msk           (0x2UL)                   /*!< TT_PMU OER: WAKEUP_1 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_2_Pos           (2UL)                     /*!< TT_PMU OER: WAKEUP_2 (Bit 2)                          */
#define TT_PMU_OER_WAKEUP_2_Msk           (0x4UL)                   /*!< TT_PMU OER: WAKEUP_2 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_3_Pos           (3UL)                     /*!< TT_PMU OER: WAKEUP_3 (Bit 3)                          */
#define TT_PMU_OER_WAKEUP_3_Msk           (0x8UL)                   /*!< TT_PMU OER: WAKEUP_3 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_4_Pos           (4UL)                     /*!< TT_PMU OER: WAKEUP_4 (Bit 4)                          */
#define TT_PMU_OER_WAKEUP_4_Msk           (0x10UL)                  /*!< TT_PMU OER: WAKEUP_4 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_5_Pos           (5UL)                     /*!< TT_PMU OER: WAKEUP_5 (Bit 5)                          */
#define TT_PMU_OER_WAKEUP_5_Msk           (0x20UL)                  /*!< TT_PMU OER: WAKEUP_5 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_6_Pos           (6UL)                     /*!< TT_PMU OER: WAKEUP_6 (Bit 6)                          */
#define TT_PMU_OER_WAKEUP_6_Msk           (0x40UL)                  /*!< TT_PMU OER: WAKEUP_6 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_7_Pos           (7UL)                     /*!< TT_PMU OER: WAKEUP_7 (Bit 7)                          */
#define TT_PMU_OER_WAKEUP_7_Msk           (0x80UL)                  /*!< TT_PMU OER: WAKEUP_7 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_8_Pos           (8UL)                     /*!< TT_PMU OER: WAKEUP_8 (Bit 8)                          */
#define TT_PMU_OER_WAKEUP_8_Msk           (0x100UL)                 /*!< TT_PMU OER: WAKEUP_8 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_9_Pos           (9UL)                     /*!< TT_PMU OER: WAKEUP_9 (Bit 9)                          */
#define TT_PMU_OER_WAKEUP_9_Msk           (0x200UL)                 /*!< TT_PMU OER: WAKEUP_9 (Bitfield-Mask: 0x01)            */
#define TT_PMU_OER_WAKEUP_10_Pos          (10UL)                    /*!< TT_PMU OER: WAKEUP_10 (Bit 10)                        */
#define TT_PMU_OER_WAKEUP_10_Msk          (0x400UL)                 /*!< TT_PMU OER: WAKEUP_10 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_11_Pos          (11UL)                    /*!< TT_PMU OER: WAKEUP_11 (Bit 11)                        */
#define TT_PMU_OER_WAKEUP_11_Msk          (0x800UL)                 /*!< TT_PMU OER: WAKEUP_11 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_12_Pos          (12UL)                    /*!< TT_PMU OER: WAKEUP_12 (Bit 12)                        */
#define TT_PMU_OER_WAKEUP_12_Msk          (0x1000UL)                /*!< TT_PMU OER: WAKEUP_12 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_13_Pos          (13UL)                    /*!< TT_PMU OER: WAKEUP_13 (Bit 13)                        */
#define TT_PMU_OER_WAKEUP_13_Msk          (0x2000UL)                /*!< TT_PMU OER: WAKEUP_13 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_14_Pos          (14UL)                    /*!< TT_PMU OER: WAKEUP_14 (Bit 14)                        */
#define TT_PMU_OER_WAKEUP_14_Msk          (0x4000UL)                /*!< TT_PMU OER: WAKEUP_14 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_15_Pos          (15UL)                    /*!< TT_PMU OER: WAKEUP_15 (Bit 15)                        */
#define TT_PMU_OER_WAKEUP_15_Msk          (0x8000UL)                /*!< TT_PMU OER: WAKEUP_15 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_16_Pos          (16UL)                    /*!< TT_PMU OER: WAKEUP_16 (Bit 16)                        */
#define TT_PMU_OER_WAKEUP_16_Msk          (0x10000UL)               /*!< TT_PMU OER: WAKEUP_16 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_17_Pos          (17UL)                    /*!< TT_PMU OER: WAKEUP_17 (Bit 17)                        */
#define TT_PMU_OER_WAKEUP_17_Msk          (0x20000UL)               /*!< TT_PMU OER: WAKEUP_17 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_18_Pos          (18UL)                    /*!< TT_PMU OER: WAKEUP_18 (Bit 18)                        */
#define TT_PMU_OER_WAKEUP_18_Msk          (0x40000UL)               /*!< TT_PMU OER: WAKEUP_18 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_19_Pos          (19UL)                    /*!< TT_PMU OER: WAKEUP_19 (Bit 19)                        */
#define TT_PMU_OER_WAKEUP_19_Msk          (0x80000UL)               /*!< TT_PMU OER: WAKEUP_19 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_20_Pos          (20UL)                    /*!< TT_PMU OER: WAKEUP_20 (Bit 20)                        */
#define TT_PMU_OER_WAKEUP_20_Msk          (0x100000UL)              /*!< TT_PMU OER: WAKEUP_20 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_21_Pos          (21UL)                    /*!< TT_PMU OER: WAKEUP_21 (Bit 21)                        */
#define TT_PMU_OER_WAKEUP_21_Msk          (0x200000UL)              /*!< TT_PMU OER: WAKEUP_21 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_22_Pos          (22UL)                    /*!< TT_PMU OER: WAKEUP_22 (Bit 22)                        */
#define TT_PMU_OER_WAKEUP_22_Msk          (0x400000UL)              /*!< TT_PMU OER: WAKEUP_22 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_23_Pos          (23UL)                    /*!< TT_PMU OER: WAKEUP_23 (Bit 23)                        */
#define TT_PMU_OER_WAKEUP_23_Msk          (0x800000UL)              /*!< TT_PMU OER: WAKEUP_23 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_24_Pos          (24UL)                    /*!< TT_PMU OER: WAKEUP_24 (Bit 24)                        */
#define TT_PMU_OER_WAKEUP_24_Msk          (0x1000000UL)             /*!< TT_PMU OER: WAKEUP_24 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_25_Pos          (25UL)                    /*!< TT_PMU OER: WAKEUP_25 (Bit 25)                        */
#define TT_PMU_OER_WAKEUP_25_Msk          (0x2000000UL)             /*!< TT_PMU OER: WAKEUP_25 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_26_Pos          (26UL)                    /*!< TT_PMU OER: WAKEUP_26 (Bit 26)                        */
#define TT_PMU_OER_WAKEUP_26_Msk          (0x4000000UL)             /*!< TT_PMU OER: WAKEUP_26 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_27_Pos          (27UL)                    /*!< TT_PMU OER: WAKEUP_27 (Bit 27)                        */
#define TT_PMU_OER_WAKEUP_27_Msk          (0x8000000UL)             /*!< TT_PMU OER: WAKEUP_27 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_28_Pos          (28UL)                    /*!< TT_PMU OER: WAKEUP_28 (Bit 28)                        */
#define TT_PMU_OER_WAKEUP_28_Msk          (0x10000000UL)            /*!< TT_PMU OER: WAKEUP_28 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_29_Pos          (29UL)                    /*!< TT_PMU OER: WAKEUP_29 (Bit 29)                        */
#define TT_PMU_OER_WAKEUP_29_Msk          (0x20000000UL)            /*!< TT_PMU OER: WAKEUP_29 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_30_Pos          (30UL)                    /*!< TT_PMU OER: WAKEUP_30 (Bit 30)                        */
#define TT_PMU_OER_WAKEUP_30_Msk          (0x40000000UL)            /*!< TT_PMU OER: WAKEUP_30 (Bitfield-Mask: 0x01)           */
#define TT_PMU_OER_WAKEUP_31_Pos          (31UL)                    /*!< TT_PMU OER: WAKEUP_31 (Bit 31)                        */
#define TT_PMU_OER_WAKEUP_31_Msk          (0x80000000UL)            /*!< TT_PMU OER: WAKEUP_31 (Bitfield-Mask: 0x01)           */
/* ==========================================================  DOR  ========================================================== */
#define TT_PMU_DOR_WAKEUP_0_Pos           (0UL)                     /*!< TT_PMU DOR: WAKEUP_0 (Bit 0)                          */
#define TT_PMU_DOR_WAKEUP_0_Msk           (0x1UL)                   /*!< TT_PMU DOR: WAKEUP_0 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_1_Pos           (1UL)                     /*!< TT_PMU DOR: WAKEUP_1 (Bit 1)                          */
#define TT_PMU_DOR_WAKEUP_1_Msk           (0x2UL)                   /*!< TT_PMU DOR: WAKEUP_1 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_2_Pos           (2UL)                     /*!< TT_PMU DOR: WAKEUP_2 (Bit 2)                          */
#define TT_PMU_DOR_WAKEUP_2_Msk           (0x4UL)                   /*!< TT_PMU DOR: WAKEUP_2 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_3_Pos           (3UL)                     /*!< TT_PMU DOR: WAKEUP_3 (Bit 3)                          */
#define TT_PMU_DOR_WAKEUP_3_Msk           (0x8UL)                   /*!< TT_PMU DOR: WAKEUP_3 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_4_Pos           (4UL)                     /*!< TT_PMU DOR: WAKEUP_4 (Bit 4)                          */
#define TT_PMU_DOR_WAKEUP_4_Msk           (0x10UL)                  /*!< TT_PMU DOR: WAKEUP_4 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_5_Pos           (5UL)                     /*!< TT_PMU DOR: WAKEUP_5 (Bit 5)                          */
#define TT_PMU_DOR_WAKEUP_5_Msk           (0x20UL)                  /*!< TT_PMU DOR: WAKEUP_5 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_6_Pos           (6UL)                     /*!< TT_PMU DOR: WAKEUP_6 (Bit 6)                          */
#define TT_PMU_DOR_WAKEUP_6_Msk           (0x40UL)                  /*!< TT_PMU DOR: WAKEUP_6 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_7_Pos           (7UL)                     /*!< TT_PMU DOR: WAKEUP_7 (Bit 7)                          */
#define TT_PMU_DOR_WAKEUP_7_Msk           (0x80UL)                  /*!< TT_PMU DOR: WAKEUP_7 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_8_Pos           (8UL)                     /*!< TT_PMU DOR: WAKEUP_8 (Bit 8)                          */
#define TT_PMU_DOR_WAKEUP_8_Msk           (0x100UL)                 /*!< TT_PMU DOR: WAKEUP_8 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_9_Pos           (9UL)                     /*!< TT_PMU DOR: WAKEUP_9 (Bit 9)                          */
#define TT_PMU_DOR_WAKEUP_9_Msk           (0x200UL)                 /*!< TT_PMU DOR: WAKEUP_9 (Bitfield-Mask: 0x01)            */
#define TT_PMU_DOR_WAKEUP_10_Pos          (10UL)                    /*!< TT_PMU DOR: WAKEUP_10 (Bit 10)                        */
#define TT_PMU_DOR_WAKEUP_10_Msk          (0x400UL)                 /*!< TT_PMU DOR: WAKEUP_10 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_11_Pos          (11UL)                    /*!< TT_PMU DOR: WAKEUP_11 (Bit 11)                        */
#define TT_PMU_DOR_WAKEUP_11_Msk          (0x800UL)                 /*!< TT_PMU DOR: WAKEUP_11 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_12_Pos          (12UL)                    /*!< TT_PMU DOR: WAKEUP_12 (Bit 12)                        */
#define TT_PMU_DOR_WAKEUP_12_Msk          (0x1000UL)                /*!< TT_PMU DOR: WAKEUP_12 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_13_Pos          (13UL)                    /*!< TT_PMU DOR: WAKEUP_13 (Bit 13)                        */
#define TT_PMU_DOR_WAKEUP_13_Msk          (0x2000UL)                /*!< TT_PMU DOR: WAKEUP_13 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_14_Pos          (14UL)                    /*!< TT_PMU DOR: WAKEUP_14 (Bit 14)                        */
#define TT_PMU_DOR_WAKEUP_14_Msk          (0x4000UL)                /*!< TT_PMU DOR: WAKEUP_14 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_15_Pos          (15UL)                    /*!< TT_PMU DOR: WAKEUP_15 (Bit 15)                        */
#define TT_PMU_DOR_WAKEUP_15_Msk          (0x8000UL)                /*!< TT_PMU DOR: WAKEUP_15 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_16_Pos          (16UL)                    /*!< TT_PMU DOR: WAKEUP_16 (Bit 16)                        */
#define TT_PMU_DOR_WAKEUP_16_Msk          (0x10000UL)               /*!< TT_PMU DOR: WAKEUP_16 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_17_Pos          (17UL)                    /*!< TT_PMU DOR: WAKEUP_17 (Bit 17)                        */
#define TT_PMU_DOR_WAKEUP_17_Msk          (0x20000UL)               /*!< TT_PMU DOR: WAKEUP_17 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_18_Pos          (18UL)                    /*!< TT_PMU DOR: WAKEUP_18 (Bit 18)                        */
#define TT_PMU_DOR_WAKEUP_18_Msk          (0x40000UL)               /*!< TT_PMU DOR: WAKEUP_18 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_19_Pos          (19UL)                    /*!< TT_PMU DOR: WAKEUP_19 (Bit 19)                        */
#define TT_PMU_DOR_WAKEUP_19_Msk          (0x80000UL)               /*!< TT_PMU DOR: WAKEUP_19 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_20_Pos          (20UL)                    /*!< TT_PMU DOR: WAKEUP_20 (Bit 20)                        */
#define TT_PMU_DOR_WAKEUP_20_Msk          (0x100000UL)              /*!< TT_PMU DOR: WAKEUP_20 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_21_Pos          (21UL)                    /*!< TT_PMU DOR: WAKEUP_21 (Bit 21)                        */
#define TT_PMU_DOR_WAKEUP_21_Msk          (0x200000UL)              /*!< TT_PMU DOR: WAKEUP_21 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_22_Pos          (22UL)                    /*!< TT_PMU DOR: WAKEUP_22 (Bit 22)                        */
#define TT_PMU_DOR_WAKEUP_22_Msk          (0x400000UL)              /*!< TT_PMU DOR: WAKEUP_22 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_23_Pos          (23UL)                    /*!< TT_PMU DOR: WAKEUP_23 (Bit 23)                        */
#define TT_PMU_DOR_WAKEUP_23_Msk          (0x800000UL)              /*!< TT_PMU DOR: WAKEUP_23 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_24_Pos          (24UL)                    /*!< TT_PMU DOR: WAKEUP_24 (Bit 24)                        */
#define TT_PMU_DOR_WAKEUP_24_Msk          (0x1000000UL)             /*!< TT_PMU DOR: WAKEUP_24 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_25_Pos          (25UL)                    /*!< TT_PMU DOR: WAKEUP_25 (Bit 25)                        */
#define TT_PMU_DOR_WAKEUP_25_Msk          (0x2000000UL)             /*!< TT_PMU DOR: WAKEUP_25 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_26_Pos          (26UL)                    /*!< TT_PMU DOR: WAKEUP_26 (Bit 26)                        */
#define TT_PMU_DOR_WAKEUP_26_Msk          (0x4000000UL)             /*!< TT_PMU DOR: WAKEUP_26 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_27_Pos          (27UL)                    /*!< TT_PMU DOR: WAKEUP_27 (Bit 27)                        */
#define TT_PMU_DOR_WAKEUP_27_Msk          (0x8000000UL)             /*!< TT_PMU DOR: WAKEUP_27 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_28_Pos          (28UL)                    /*!< TT_PMU DOR: WAKEUP_28 (Bit 28)                        */
#define TT_PMU_DOR_WAKEUP_28_Msk          (0x10000000UL)            /*!< TT_PMU DOR: WAKEUP_28 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_29_Pos          (29UL)                    /*!< TT_PMU DOR: WAKEUP_29 (Bit 29)                        */
#define TT_PMU_DOR_WAKEUP_29_Msk          (0x20000000UL)            /*!< TT_PMU DOR: WAKEUP_29 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_30_Pos          (30UL)                    /*!< TT_PMU DOR: WAKEUP_30 (Bit 30)                        */
#define TT_PMU_DOR_WAKEUP_30_Msk          (0x40000000UL)            /*!< TT_PMU DOR: WAKEUP_30 (Bitfield-Mask: 0x01)           */
#define TT_PMU_DOR_WAKEUP_31_Pos          (31UL)                    /*!< TT_PMU DOR: WAKEUP_31 (Bit 31)                        */
#define TT_PMU_DOR_WAKEUP_31_Msk          (0x80000000UL)            /*!< TT_PMU DOR: WAKEUP_31 (Bitfield-Mask: 0x01)           */
/* ==========================================================  PUR  ========================================================== */
#define TT_PMU_PUR_WAKEUP_0_Pos           (0UL)                     /*!< TT_PMU PUR: WAKEUP_0 (Bit 0)                          */
#define TT_PMU_PUR_WAKEUP_0_Msk           (0x1UL)                   /*!< TT_PMU PUR: WAKEUP_0 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_1_Pos           (1UL)                     /*!< TT_PMU PUR: WAKEUP_1 (Bit 1)                          */
#define TT_PMU_PUR_WAKEUP_1_Msk           (0x2UL)                   /*!< TT_PMU PUR: WAKEUP_1 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_2_Pos           (2UL)                     /*!< TT_PMU PUR: WAKEUP_2 (Bit 2)                          */
#define TT_PMU_PUR_WAKEUP_2_Msk           (0x4UL)                   /*!< TT_PMU PUR: WAKEUP_2 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_3_Pos           (3UL)                     /*!< TT_PMU PUR: WAKEUP_3 (Bit 3)                          */
#define TT_PMU_PUR_WAKEUP_3_Msk           (0x8UL)                   /*!< TT_PMU PUR: WAKEUP_3 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_4_Pos           (4UL)                     /*!< TT_PMU PUR: WAKEUP_4 (Bit 4)                          */
#define TT_PMU_PUR_WAKEUP_4_Msk           (0x10UL)                  /*!< TT_PMU PUR: WAKEUP_4 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_5_Pos           (5UL)                     /*!< TT_PMU PUR: WAKEUP_5 (Bit 5)                          */
#define TT_PMU_PUR_WAKEUP_5_Msk           (0x20UL)                  /*!< TT_PMU PUR: WAKEUP_5 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_6_Pos           (6UL)                     /*!< TT_PMU PUR: WAKEUP_6 (Bit 6)                          */
#define TT_PMU_PUR_WAKEUP_6_Msk           (0x40UL)                  /*!< TT_PMU PUR: WAKEUP_6 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_7_Pos           (7UL)                     /*!< TT_PMU PUR: WAKEUP_7 (Bit 7)                          */
#define TT_PMU_PUR_WAKEUP_7_Msk           (0x80UL)                  /*!< TT_PMU PUR: WAKEUP_7 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_8_Pos           (8UL)                     /*!< TT_PMU PUR: WAKEUP_8 (Bit 8)                          */
#define TT_PMU_PUR_WAKEUP_8_Msk           (0x100UL)                 /*!< TT_PMU PUR: WAKEUP_8 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_9_Pos           (9UL)                     /*!< TT_PMU PUR: WAKEUP_9 (Bit 9)                          */
#define TT_PMU_PUR_WAKEUP_9_Msk           (0x200UL)                 /*!< TT_PMU PUR: WAKEUP_9 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PUR_WAKEUP_10_Pos          (10UL)                    /*!< TT_PMU PUR: WAKEUP_10 (Bit 10)                        */
#define TT_PMU_PUR_WAKEUP_10_Msk          (0x400UL)                 /*!< TT_PMU PUR: WAKEUP_10 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_11_Pos          (11UL)                    /*!< TT_PMU PUR: WAKEUP_11 (Bit 11)                        */
#define TT_PMU_PUR_WAKEUP_11_Msk          (0x800UL)                 /*!< TT_PMU PUR: WAKEUP_11 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_12_Pos          (12UL)                    /*!< TT_PMU PUR: WAKEUP_12 (Bit 12)                        */
#define TT_PMU_PUR_WAKEUP_12_Msk          (0x1000UL)                /*!< TT_PMU PUR: WAKEUP_12 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_13_Pos          (13UL)                    /*!< TT_PMU PUR: WAKEUP_13 (Bit 13)                        */
#define TT_PMU_PUR_WAKEUP_13_Msk          (0x2000UL)                /*!< TT_PMU PUR: WAKEUP_13 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_14_Pos          (14UL)                    /*!< TT_PMU PUR: WAKEUP_14 (Bit 14)                        */
#define TT_PMU_PUR_WAKEUP_14_Msk          (0x4000UL)                /*!< TT_PMU PUR: WAKEUP_14 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_15_Pos          (15UL)                    /*!< TT_PMU PUR: WAKEUP_15 (Bit 15)                        */
#define TT_PMU_PUR_WAKEUP_15_Msk          (0x8000UL)                /*!< TT_PMU PUR: WAKEUP_15 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_16_Pos          (16UL)                    /*!< TT_PMU PUR: WAKEUP_16 (Bit 16)                        */
#define TT_PMU_PUR_WAKEUP_16_Msk          (0x10000UL)               /*!< TT_PMU PUR: WAKEUP_16 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_17_Pos          (17UL)                    /*!< TT_PMU PUR: WAKEUP_17 (Bit 17)                        */
#define TT_PMU_PUR_WAKEUP_17_Msk          (0x20000UL)               /*!< TT_PMU PUR: WAKEUP_17 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_18_Pos          (18UL)                    /*!< TT_PMU PUR: WAKEUP_18 (Bit 18)                        */
#define TT_PMU_PUR_WAKEUP_18_Msk          (0x40000UL)               /*!< TT_PMU PUR: WAKEUP_18 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_19_Pos          (19UL)                    /*!< TT_PMU PUR: WAKEUP_19 (Bit 19)                        */
#define TT_PMU_PUR_WAKEUP_19_Msk          (0x80000UL)               /*!< TT_PMU PUR: WAKEUP_19 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_20_Pos          (20UL)                    /*!< TT_PMU PUR: WAKEUP_20 (Bit 20)                        */
#define TT_PMU_PUR_WAKEUP_20_Msk          (0x100000UL)              /*!< TT_PMU PUR: WAKEUP_20 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_21_Pos          (21UL)                    /*!< TT_PMU PUR: WAKEUP_21 (Bit 21)                        */
#define TT_PMU_PUR_WAKEUP_21_Msk          (0x200000UL)              /*!< TT_PMU PUR: WAKEUP_21 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_22_Pos          (22UL)                    /*!< TT_PMU PUR: WAKEUP_22 (Bit 22)                        */
#define TT_PMU_PUR_WAKEUP_22_Msk          (0x400000UL)              /*!< TT_PMU PUR: WAKEUP_22 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_23_Pos          (23UL)                    /*!< TT_PMU PUR: WAKEUP_23 (Bit 23)                        */
#define TT_PMU_PUR_WAKEUP_23_Msk          (0x800000UL)              /*!< TT_PMU PUR: WAKEUP_23 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_24_Pos          (24UL)                    /*!< TT_PMU PUR: WAKEUP_24 (Bit 24)                        */
#define TT_PMU_PUR_WAKEUP_24_Msk          (0x1000000UL)             /*!< TT_PMU PUR: WAKEUP_24 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_25_Pos          (25UL)                    /*!< TT_PMU PUR: WAKEUP_25 (Bit 25)                        */
#define TT_PMU_PUR_WAKEUP_25_Msk          (0x2000000UL)             /*!< TT_PMU PUR: WAKEUP_25 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_26_Pos          (26UL)                    /*!< TT_PMU PUR: WAKEUP_26 (Bit 26)                        */
#define TT_PMU_PUR_WAKEUP_26_Msk          (0x4000000UL)             /*!< TT_PMU PUR: WAKEUP_26 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_27_Pos          (27UL)                    /*!< TT_PMU PUR: WAKEUP_27 (Bit 27)                        */
#define TT_PMU_PUR_WAKEUP_27_Msk          (0x8000000UL)             /*!< TT_PMU PUR: WAKEUP_27 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_28_Pos          (28UL)                    /*!< TT_PMU PUR: WAKEUP_28 (Bit 28)                        */
#define TT_PMU_PUR_WAKEUP_28_Msk          (0x10000000UL)            /*!< TT_PMU PUR: WAKEUP_28 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_29_Pos          (29UL)                    /*!< TT_PMU PUR: WAKEUP_29 (Bit 29)                        */
#define TT_PMU_PUR_WAKEUP_29_Msk          (0x20000000UL)            /*!< TT_PMU PUR: WAKEUP_29 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_30_Pos          (30UL)                    /*!< TT_PMU PUR: WAKEUP_30 (Bit 30)                        */
#define TT_PMU_PUR_WAKEUP_30_Msk          (0x40000000UL)            /*!< TT_PMU PUR: WAKEUP_30 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PUR_WAKEUP_31_Pos          (31UL)                    /*!< TT_PMU PUR: WAKEUP_31 (Bit 31)                        */
#define TT_PMU_PUR_WAKEUP_31_Msk          (0x80000000UL)            /*!< TT_PMU PUR: WAKEUP_31 (Bitfield-Mask: 0x01)           */
/* ==========================================================  PDR  ========================================================== */
#define TT_PMU_PDR_WAKEUP_0_Pos           (0UL)                     /*!< TT_PMU PDR: WAKEUP_0 (Bit 0)                          */
#define TT_PMU_PDR_WAKEUP_0_Msk           (0x1UL)                   /*!< TT_PMU PDR: WAKEUP_0 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_1_Pos           (1UL)                     /*!< TT_PMU PDR: WAKEUP_1 (Bit 1)                          */
#define TT_PMU_PDR_WAKEUP_1_Msk           (0x2UL)                   /*!< TT_PMU PDR: WAKEUP_1 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_2_Pos           (2UL)                     /*!< TT_PMU PDR: WAKEUP_2 (Bit 2)                          */
#define TT_PMU_PDR_WAKEUP_2_Msk           (0x4UL)                   /*!< TT_PMU PDR: WAKEUP_2 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_3_Pos           (3UL)                     /*!< TT_PMU PDR: WAKEUP_3 (Bit 3)                          */
#define TT_PMU_PDR_WAKEUP_3_Msk           (0x8UL)                   /*!< TT_PMU PDR: WAKEUP_3 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_4_Pos           (4UL)                     /*!< TT_PMU PDR: WAKEUP_4 (Bit 4)                          */
#define TT_PMU_PDR_WAKEUP_4_Msk           (0x10UL)                  /*!< TT_PMU PDR: WAKEUP_4 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_5_Pos           (5UL)                     /*!< TT_PMU PDR: WAKEUP_5 (Bit 5)                          */
#define TT_PMU_PDR_WAKEUP_5_Msk           (0x20UL)                  /*!< TT_PMU PDR: WAKEUP_5 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_6_Pos           (6UL)                     /*!< TT_PMU PDR: WAKEUP_6 (Bit 6)                          */
#define TT_PMU_PDR_WAKEUP_6_Msk           (0x40UL)                  /*!< TT_PMU PDR: WAKEUP_6 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_7_Pos           (7UL)                     /*!< TT_PMU PDR: WAKEUP_7 (Bit 7)                          */
#define TT_PMU_PDR_WAKEUP_7_Msk           (0x80UL)                  /*!< TT_PMU PDR: WAKEUP_7 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_8_Pos           (8UL)                     /*!< TT_PMU PDR: WAKEUP_8 (Bit 8)                          */
#define TT_PMU_PDR_WAKEUP_8_Msk           (0x100UL)                 /*!< TT_PMU PDR: WAKEUP_8 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_9_Pos           (9UL)                     /*!< TT_PMU PDR: WAKEUP_9 (Bit 9)                          */
#define TT_PMU_PDR_WAKEUP_9_Msk           (0x200UL)                 /*!< TT_PMU PDR: WAKEUP_9 (Bitfield-Mask: 0x01)            */
#define TT_PMU_PDR_WAKEUP_10_Pos          (10UL)                    /*!< TT_PMU PDR: WAKEUP_10 (Bit 10)                        */
#define TT_PMU_PDR_WAKEUP_10_Msk          (0x400UL)                 /*!< TT_PMU PDR: WAKEUP_10 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_11_Pos          (11UL)                    /*!< TT_PMU PDR: WAKEUP_11 (Bit 11)                        */
#define TT_PMU_PDR_WAKEUP_11_Msk          (0x800UL)                 /*!< TT_PMU PDR: WAKEUP_11 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_12_Pos          (12UL)                    /*!< TT_PMU PDR: WAKEUP_12 (Bit 12)                        */
#define TT_PMU_PDR_WAKEUP_12_Msk          (0x1000UL)                /*!< TT_PMU PDR: WAKEUP_12 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_13_Pos          (13UL)                    /*!< TT_PMU PDR: WAKEUP_13 (Bit 13)                        */
#define TT_PMU_PDR_WAKEUP_13_Msk          (0x2000UL)                /*!< TT_PMU PDR: WAKEUP_13 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_14_Pos          (14UL)                    /*!< TT_PMU PDR: WAKEUP_14 (Bit 14)                        */
#define TT_PMU_PDR_WAKEUP_14_Msk          (0x4000UL)                /*!< TT_PMU PDR: WAKEUP_14 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_15_Pos          (15UL)                    /*!< TT_PMU PDR: WAKEUP_15 (Bit 15)                        */
#define TT_PMU_PDR_WAKEUP_15_Msk          (0x8000UL)                /*!< TT_PMU PDR: WAKEUP_15 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_16_Pos          (16UL)                    /*!< TT_PMU PDR: WAKEUP_16 (Bit 16)                        */
#define TT_PMU_PDR_WAKEUP_16_Msk          (0x10000UL)               /*!< TT_PMU PDR: WAKEUP_16 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_17_Pos          (17UL)                    /*!< TT_PMU PDR: WAKEUP_17 (Bit 17)                        */
#define TT_PMU_PDR_WAKEUP_17_Msk          (0x20000UL)               /*!< TT_PMU PDR: WAKEUP_17 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_18_Pos          (18UL)                    /*!< TT_PMU PDR: WAKEUP_18 (Bit 18)                        */
#define TT_PMU_PDR_WAKEUP_18_Msk          (0x40000UL)               /*!< TT_PMU PDR: WAKEUP_18 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_19_Pos          (19UL)                    /*!< TT_PMU PDR: WAKEUP_19 (Bit 19)                        */
#define TT_PMU_PDR_WAKEUP_19_Msk          (0x80000UL)               /*!< TT_PMU PDR: WAKEUP_19 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_20_Pos          (20UL)                    /*!< TT_PMU PDR: WAKEUP_20 (Bit 20)                        */
#define TT_PMU_PDR_WAKEUP_20_Msk          (0x100000UL)              /*!< TT_PMU PDR: WAKEUP_20 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_21_Pos          (21UL)                    /*!< TT_PMU PDR: WAKEUP_21 (Bit 21)                        */
#define TT_PMU_PDR_WAKEUP_21_Msk          (0x200000UL)              /*!< TT_PMU PDR: WAKEUP_21 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_22_Pos          (22UL)                    /*!< TT_PMU PDR: WAKEUP_22 (Bit 22)                        */
#define TT_PMU_PDR_WAKEUP_22_Msk          (0x400000UL)              /*!< TT_PMU PDR: WAKEUP_22 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_23_Pos          (23UL)                    /*!< TT_PMU PDR: WAKEUP_23 (Bit 23)                        */
#define TT_PMU_PDR_WAKEUP_23_Msk          (0x800000UL)              /*!< TT_PMU PDR: WAKEUP_23 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_24_Pos          (24UL)                    /*!< TT_PMU PDR: WAKEUP_24 (Bit 24)                        */
#define TT_PMU_PDR_WAKEUP_24_Msk          (0x1000000UL)             /*!< TT_PMU PDR: WAKEUP_24 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_25_Pos          (25UL)                    /*!< TT_PMU PDR: WAKEUP_25 (Bit 25)                        */
#define TT_PMU_PDR_WAKEUP_25_Msk          (0x2000000UL)             /*!< TT_PMU PDR: WAKEUP_25 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_26_Pos          (26UL)                    /*!< TT_PMU PDR: WAKEUP_26 (Bit 26)                        */
#define TT_PMU_PDR_WAKEUP_26_Msk          (0x4000000UL)             /*!< TT_PMU PDR: WAKEUP_26 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_27_Pos          (27UL)                    /*!< TT_PMU PDR: WAKEUP_27 (Bit 27)                        */
#define TT_PMU_PDR_WAKEUP_27_Msk          (0x8000000UL)             /*!< TT_PMU PDR: WAKEUP_27 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_28_Pos          (28UL)                    /*!< TT_PMU PDR: WAKEUP_28 (Bit 28)                        */
#define TT_PMU_PDR_WAKEUP_28_Msk          (0x10000000UL)            /*!< TT_PMU PDR: WAKEUP_28 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_29_Pos          (29UL)                    /*!< TT_PMU PDR: WAKEUP_29 (Bit 29)                        */
#define TT_PMU_PDR_WAKEUP_29_Msk          (0x20000000UL)            /*!< TT_PMU PDR: WAKEUP_29 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_30_Pos          (30UL)                    /*!< TT_PMU PDR: WAKEUP_30 (Bit 30)                        */
#define TT_PMU_PDR_WAKEUP_30_Msk          (0x40000000UL)            /*!< TT_PMU PDR: WAKEUP_30 (Bitfield-Mask: 0x01)           */
#define TT_PMU_PDR_WAKEUP_31_Pos          (31UL)                    /*!< TT_PMU PDR: WAKEUP_31 (Bit 31)                        */
#define TT_PMU_PDR_WAKEUP_31_Msk          (0x80000000UL)            /*!< TT_PMU PDR: WAKEUP_31 (Bitfield-Mask: 0x01)           */
/* ==========================================================  NSR  ========================================================== */
#define TT_PMU_NSR_NIF0_Pos               (0UL)                     /*!< TT_PMU NSR: NIF0 (Bit 0)                              */
#define TT_PMU_NSR_NIF0_Msk               (0x1UL)                   /*!< TT_PMU NSR: NIF0 (Bitfield-Mask: 0x01)                */
/* ==========================================================  NCR  ========================================================== */
#define TT_PMU_NCR_NFE0_Pos               (0UL)                     /*!< TT_PMU NCR: NFE0 (Bit 0)                              */
#define TT_PMU_NCR_NFE0_Msk               (0x1UL)                   /*!< TT_PMU NCR: NFE0 (Bitfield-Mask: 0x01)                */
#define TT_PMU_NCR_NFEE0_Pos              (1UL)                     /*!< TT_PMU NCR: NFEE0 (Bit 1)                             */
#define TT_PMU_NCR_NFEE0_Msk              (0x2UL)                   /*!< TT_PMU NCR: NFEE0 (Bitfield-Mask: 0x01)               */
#define TT_PMU_NCR_NREE0_Pos              (2UL)                     /*!< TT_PMU NCR: NREE0 (Bit 2)                             */
#define TT_PMU_NCR_NREE0_Msk              (0x4UL)                   /*!< TT_PMU NCR: NREE0 (Bitfield-Mask: 0x01)               */
#define TT_PMU_NCR_NMIEN_Pos              (3UL)                     /*!< TT_PMU NCR: NMIEN (Bit 3)                             */
#define TT_PMU_NCR_NMIEN_Msk              (0x8UL)                   /*!< TT_PMU NCR: NMIEN (Bitfield-Mask: 0x01)               */
#define TT_PMU_NCR_NWRE0_Pos              (4UL)                     /*!< TT_PMU NCR: NWRE0 (Bit 4)                             */
#define TT_PMU_NCR_NWRE0_Msk              (0x10UL)                  /*!< TT_PMU NCR: NWRE0 (Bitfield-Mask: 0x01)               */
/* =========================================================  WISR  ========================================================== */
#define TT_PMU_WISR_WAKEUP_0_Pos          (0UL)                     /*!< TT_PMU WISR: WAKEUP_0 (Bit 0)                         */
#define TT_PMU_WISR_WAKEUP_0_Msk          (0x1UL)                   /*!< TT_PMU WISR: WAKEUP_0 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_1_Pos          (1UL)                     /*!< TT_PMU WISR: WAKEUP_1 (Bit 1)                         */
#define TT_PMU_WISR_WAKEUP_1_Msk          (0x2UL)                   /*!< TT_PMU WISR: WAKEUP_1 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_2_Pos          (2UL)                     /*!< TT_PMU WISR: WAKEUP_2 (Bit 2)                         */
#define TT_PMU_WISR_WAKEUP_2_Msk          (0x4UL)                   /*!< TT_PMU WISR: WAKEUP_2 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_3_Pos          (3UL)                     /*!< TT_PMU WISR: WAKEUP_3 (Bit 3)                         */
#define TT_PMU_WISR_WAKEUP_3_Msk          (0x8UL)                   /*!< TT_PMU WISR: WAKEUP_3 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_4_Pos          (4UL)                     /*!< TT_PMU WISR: WAKEUP_4 (Bit 4)                         */
#define TT_PMU_WISR_WAKEUP_4_Msk          (0x10UL)                  /*!< TT_PMU WISR: WAKEUP_4 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_5_Pos          (5UL)                     /*!< TT_PMU WISR: WAKEUP_5 (Bit 5)                         */
#define TT_PMU_WISR_WAKEUP_5_Msk          (0x20UL)                  /*!< TT_PMU WISR: WAKEUP_5 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_6_Pos          (6UL)                     /*!< TT_PMU WISR: WAKEUP_6 (Bit 6)                         */
#define TT_PMU_WISR_WAKEUP_6_Msk          (0x40UL)                  /*!< TT_PMU WISR: WAKEUP_6 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_7_Pos          (7UL)                     /*!< TT_PMU WISR: WAKEUP_7 (Bit 7)                         */
#define TT_PMU_WISR_WAKEUP_7_Msk          (0x80UL)                  /*!< TT_PMU WISR: WAKEUP_7 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_8_Pos          (8UL)                     /*!< TT_PMU WISR: WAKEUP_8 (Bit 8)                         */
#define TT_PMU_WISR_WAKEUP_8_Msk          (0x100UL)                 /*!< TT_PMU WISR: WAKEUP_8 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_9_Pos          (9UL)                     /*!< TT_PMU WISR: WAKEUP_9 (Bit 9)                         */
#define TT_PMU_WISR_WAKEUP_9_Msk          (0x200UL)                 /*!< TT_PMU WISR: WAKEUP_9 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WISR_WAKEUP_10_Pos         (10UL)                    /*!< TT_PMU WISR: WAKEUP_10 (Bit 10)                       */
#define TT_PMU_WISR_WAKEUP_10_Msk         (0x400UL)                 /*!< TT_PMU WISR: WAKEUP_10 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_11_Pos         (11UL)                    /*!< TT_PMU WISR: WAKEUP_11 (Bit 11)                       */
#define TT_PMU_WISR_WAKEUP_11_Msk         (0x800UL)                 /*!< TT_PMU WISR: WAKEUP_11 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_12_Pos         (12UL)                    /*!< TT_PMU WISR: WAKEUP_12 (Bit 12)                       */
#define TT_PMU_WISR_WAKEUP_12_Msk         (0x1000UL)                /*!< TT_PMU WISR: WAKEUP_12 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_13_Pos         (13UL)                    /*!< TT_PMU WISR: WAKEUP_13 (Bit 13)                       */
#define TT_PMU_WISR_WAKEUP_13_Msk         (0x2000UL)                /*!< TT_PMU WISR: WAKEUP_13 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_14_Pos         (14UL)                    /*!< TT_PMU WISR: WAKEUP_14 (Bit 14)                       */
#define TT_PMU_WISR_WAKEUP_14_Msk         (0x4000UL)                /*!< TT_PMU WISR: WAKEUP_14 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_15_Pos         (15UL)                    /*!< TT_PMU WISR: WAKEUP_15 (Bit 15)                       */
#define TT_PMU_WISR_WAKEUP_15_Msk         (0x8000UL)                /*!< TT_PMU WISR: WAKEUP_15 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_16_Pos         (16UL)                    /*!< TT_PMU WISR: WAKEUP_16 (Bit 16)                       */
#define TT_PMU_WISR_WAKEUP_16_Msk         (0x10000UL)               /*!< TT_PMU WISR: WAKEUP_16 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_17_Pos         (17UL)                    /*!< TT_PMU WISR: WAKEUP_17 (Bit 17)                       */
#define TT_PMU_WISR_WAKEUP_17_Msk         (0x20000UL)               /*!< TT_PMU WISR: WAKEUP_17 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_18_Pos         (18UL)                    /*!< TT_PMU WISR: WAKEUP_18 (Bit 18)                       */
#define TT_PMU_WISR_WAKEUP_18_Msk         (0x40000UL)               /*!< TT_PMU WISR: WAKEUP_18 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_19_Pos         (19UL)                    /*!< TT_PMU WISR: WAKEUP_19 (Bit 19)                       */
#define TT_PMU_WISR_WAKEUP_19_Msk         (0x80000UL)               /*!< TT_PMU WISR: WAKEUP_19 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_20_Pos         (20UL)                    /*!< TT_PMU WISR: WAKEUP_20 (Bit 20)                       */
#define TT_PMU_WISR_WAKEUP_20_Msk         (0x100000UL)              /*!< TT_PMU WISR: WAKEUP_20 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_21_Pos         (21UL)                    /*!< TT_PMU WISR: WAKEUP_21 (Bit 21)                       */
#define TT_PMU_WISR_WAKEUP_21_Msk         (0x200000UL)              /*!< TT_PMU WISR: WAKEUP_21 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_22_Pos         (22UL)                    /*!< TT_PMU WISR: WAKEUP_22 (Bit 22)                       */
#define TT_PMU_WISR_WAKEUP_22_Msk         (0x400000UL)              /*!< TT_PMU WISR: WAKEUP_22 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_23_Pos         (23UL)                    /*!< TT_PMU WISR: WAKEUP_23 (Bit 23)                       */
#define TT_PMU_WISR_WAKEUP_23_Msk         (0x800000UL)              /*!< TT_PMU WISR: WAKEUP_23 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_24_Pos         (24UL)                    /*!< TT_PMU WISR: WAKEUP_24 (Bit 24)                       */
#define TT_PMU_WISR_WAKEUP_24_Msk         (0x1000000UL)             /*!< TT_PMU WISR: WAKEUP_24 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_25_Pos         (25UL)                    /*!< TT_PMU WISR: WAKEUP_25 (Bit 25)                       */
#define TT_PMU_WISR_WAKEUP_25_Msk         (0x2000000UL)             /*!< TT_PMU WISR: WAKEUP_25 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_26_Pos         (26UL)                    /*!< TT_PMU WISR: WAKEUP_26 (Bit 26)                       */
#define TT_PMU_WISR_WAKEUP_26_Msk         (0x4000000UL)             /*!< TT_PMU WISR: WAKEUP_26 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_27_Pos         (27UL)                    /*!< TT_PMU WISR: WAKEUP_27 (Bit 27)                       */
#define TT_PMU_WISR_WAKEUP_27_Msk         (0x8000000UL)             /*!< TT_PMU WISR: WAKEUP_27 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_28_Pos         (28UL)                    /*!< TT_PMU WISR: WAKEUP_28 (Bit 28)                       */
#define TT_PMU_WISR_WAKEUP_28_Msk         (0x10000000UL)            /*!< TT_PMU WISR: WAKEUP_28 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_29_Pos         (29UL)                    /*!< TT_PMU WISR: WAKEUP_29 (Bit 29)                       */
#define TT_PMU_WISR_WAKEUP_29_Msk         (0x20000000UL)            /*!< TT_PMU WISR: WAKEUP_29 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_30_Pos         (30UL)                    /*!< TT_PMU WISR: WAKEUP_30 (Bit 30)                       */
#define TT_PMU_WISR_WAKEUP_30_Msk         (0x40000000UL)            /*!< TT_PMU WISR: WAKEUP_30 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WISR_WAKEUP_31_Pos         (31UL)                    /*!< TT_PMU WISR: WAKEUP_31 (Bit 31)                       */
#define TT_PMU_WISR_WAKEUP_31_Msk         (0x80000000UL)            /*!< TT_PMU WISR: WAKEUP_31 (Bitfield-Mask: 0x01)          */
/* =========================================================  IRER  ========================================================== */
#define TT_PMU_IRER_WAKEUP_0_Pos          (0UL)                     /*!< TT_PMU IRER: WAKEUP_0 (Bit 0)                         */
#define TT_PMU_IRER_WAKEUP_0_Msk          (0x1UL)                   /*!< TT_PMU IRER: WAKEUP_0 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_1_Pos          (1UL)                     /*!< TT_PMU IRER: WAKEUP_1 (Bit 1)                         */
#define TT_PMU_IRER_WAKEUP_1_Msk          (0x2UL)                   /*!< TT_PMU IRER: WAKEUP_1 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_2_Pos          (2UL)                     /*!< TT_PMU IRER: WAKEUP_2 (Bit 2)                         */
#define TT_PMU_IRER_WAKEUP_2_Msk          (0x4UL)                   /*!< TT_PMU IRER: WAKEUP_2 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_3_Pos          (3UL)                     /*!< TT_PMU IRER: WAKEUP_3 (Bit 3)                         */
#define TT_PMU_IRER_WAKEUP_3_Msk          (0x8UL)                   /*!< TT_PMU IRER: WAKEUP_3 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_4_Pos          (4UL)                     /*!< TT_PMU IRER: WAKEUP_4 (Bit 4)                         */
#define TT_PMU_IRER_WAKEUP_4_Msk          (0x10UL)                  /*!< TT_PMU IRER: WAKEUP_4 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_5_Pos          (5UL)                     /*!< TT_PMU IRER: WAKEUP_5 (Bit 5)                         */
#define TT_PMU_IRER_WAKEUP_5_Msk          (0x20UL)                  /*!< TT_PMU IRER: WAKEUP_5 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_6_Pos          (6UL)                     /*!< TT_PMU IRER: WAKEUP_6 (Bit 6)                         */
#define TT_PMU_IRER_WAKEUP_6_Msk          (0x40UL)                  /*!< TT_PMU IRER: WAKEUP_6 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_7_Pos          (7UL)                     /*!< TT_PMU IRER: WAKEUP_7 (Bit 7)                         */
#define TT_PMU_IRER_WAKEUP_7_Msk          (0x80UL)                  /*!< TT_PMU IRER: WAKEUP_7 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_8_Pos          (8UL)                     /*!< TT_PMU IRER: WAKEUP_8 (Bit 8)                         */
#define TT_PMU_IRER_WAKEUP_8_Msk          (0x100UL)                 /*!< TT_PMU IRER: WAKEUP_8 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_9_Pos          (9UL)                     /*!< TT_PMU IRER: WAKEUP_9 (Bit 9)                         */
#define TT_PMU_IRER_WAKEUP_9_Msk          (0x200UL)                 /*!< TT_PMU IRER: WAKEUP_9 (Bitfield-Mask: 0x01)           */
#define TT_PMU_IRER_WAKEUP_10_Pos         (10UL)                    /*!< TT_PMU IRER: WAKEUP_10 (Bit 10)                       */
#define TT_PMU_IRER_WAKEUP_10_Msk         (0x400UL)                 /*!< TT_PMU IRER: WAKEUP_10 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_11_Pos         (11UL)                    /*!< TT_PMU IRER: WAKEUP_11 (Bit 11)                       */
#define TT_PMU_IRER_WAKEUP_11_Msk         (0x800UL)                 /*!< TT_PMU IRER: WAKEUP_11 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_12_Pos         (12UL)                    /*!< TT_PMU IRER: WAKEUP_12 (Bit 12)                       */
#define TT_PMU_IRER_WAKEUP_12_Msk         (0x1000UL)                /*!< TT_PMU IRER: WAKEUP_12 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_13_Pos         (13UL)                    /*!< TT_PMU IRER: WAKEUP_13 (Bit 13)                       */
#define TT_PMU_IRER_WAKEUP_13_Msk         (0x2000UL)                /*!< TT_PMU IRER: WAKEUP_13 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_14_Pos         (14UL)                    /*!< TT_PMU IRER: WAKEUP_14 (Bit 14)                       */
#define TT_PMU_IRER_WAKEUP_14_Msk         (0x4000UL)                /*!< TT_PMU IRER: WAKEUP_14 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_15_Pos         (15UL)                    /*!< TT_PMU IRER: WAKEUP_15 (Bit 15)                       */
#define TT_PMU_IRER_WAKEUP_15_Msk         (0x8000UL)                /*!< TT_PMU IRER: WAKEUP_15 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_16_Pos         (16UL)                    /*!< TT_PMU IRER: WAKEUP_16 (Bit 16)                       */
#define TT_PMU_IRER_WAKEUP_16_Msk         (0x10000UL)               /*!< TT_PMU IRER: WAKEUP_16 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_17_Pos         (17UL)                    /*!< TT_PMU IRER: WAKEUP_17 (Bit 17)                       */
#define TT_PMU_IRER_WAKEUP_17_Msk         (0x20000UL)               /*!< TT_PMU IRER: WAKEUP_17 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_18_Pos         (18UL)                    /*!< TT_PMU IRER: WAKEUP_18 (Bit 18)                       */
#define TT_PMU_IRER_WAKEUP_18_Msk         (0x40000UL)               /*!< TT_PMU IRER: WAKEUP_18 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_19_Pos         (19UL)                    /*!< TT_PMU IRER: WAKEUP_19 (Bit 19)                       */
#define TT_PMU_IRER_WAKEUP_19_Msk         (0x80000UL)               /*!< TT_PMU IRER: WAKEUP_19 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_20_Pos         (20UL)                    /*!< TT_PMU IRER: WAKEUP_20 (Bit 20)                       */
#define TT_PMU_IRER_WAKEUP_20_Msk         (0x100000UL)              /*!< TT_PMU IRER: WAKEUP_20 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_21_Pos         (21UL)                    /*!< TT_PMU IRER: WAKEUP_21 (Bit 21)                       */
#define TT_PMU_IRER_WAKEUP_21_Msk         (0x200000UL)              /*!< TT_PMU IRER: WAKEUP_21 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_22_Pos         (22UL)                    /*!< TT_PMU IRER: WAKEUP_22 (Bit 22)                       */
#define TT_PMU_IRER_WAKEUP_22_Msk         (0x400000UL)              /*!< TT_PMU IRER: WAKEUP_22 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_23_Pos         (23UL)                    /*!< TT_PMU IRER: WAKEUP_23 (Bit 23)                       */
#define TT_PMU_IRER_WAKEUP_23_Msk         (0x800000UL)              /*!< TT_PMU IRER: WAKEUP_23 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_24_Pos         (24UL)                    /*!< TT_PMU IRER: WAKEUP_24 (Bit 24)                       */
#define TT_PMU_IRER_WAKEUP_24_Msk         (0x1000000UL)             /*!< TT_PMU IRER: WAKEUP_24 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_25_Pos         (25UL)                    /*!< TT_PMU IRER: WAKEUP_25 (Bit 25)                       */
#define TT_PMU_IRER_WAKEUP_25_Msk         (0x2000000UL)             /*!< TT_PMU IRER: WAKEUP_25 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_26_Pos         (26UL)                    /*!< TT_PMU IRER: WAKEUP_26 (Bit 26)                       */
#define TT_PMU_IRER_WAKEUP_26_Msk         (0x4000000UL)             /*!< TT_PMU IRER: WAKEUP_26 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_27_Pos         (27UL)                    /*!< TT_PMU IRER: WAKEUP_27 (Bit 27)                       */
#define TT_PMU_IRER_WAKEUP_27_Msk         (0x8000000UL)             /*!< TT_PMU IRER: WAKEUP_27 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_28_Pos         (28UL)                    /*!< TT_PMU IRER: WAKEUP_28 (Bit 28)                       */
#define TT_PMU_IRER_WAKEUP_28_Msk         (0x10000000UL)            /*!< TT_PMU IRER: WAKEUP_28 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_29_Pos         (29UL)                    /*!< TT_PMU IRER: WAKEUP_29 (Bit 29)                       */
#define TT_PMU_IRER_WAKEUP_29_Msk         (0x20000000UL)            /*!< TT_PMU IRER: WAKEUP_29 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_30_Pos         (30UL)                    /*!< TT_PMU IRER: WAKEUP_30 (Bit 30)                       */
#define TT_PMU_IRER_WAKEUP_30_Msk         (0x40000000UL)            /*!< TT_PMU IRER: WAKEUP_30 (Bitfield-Mask: 0x01)          */
#define TT_PMU_IRER_WAKEUP_31_Pos         (31UL)                    /*!< TT_PMU IRER: WAKEUP_31 (Bit 31)                       */
#define TT_PMU_IRER_WAKEUP_31_Msk         (0x80000000UL)            /*!< TT_PMU IRER: WAKEUP_31 (Bitfield-Mask: 0x01)          */
/* =========================================================  WRER  ========================================================== */
#define TT_PMU_WRER_WAKEUP_0_Pos          (0UL)                     /*!< TT_PMU WRER: WAKEUP_0 (Bit 0)                         */
#define TT_PMU_WRER_WAKEUP_0_Msk          (0x1UL)                   /*!< TT_PMU WRER: WAKEUP_0 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_1_Pos          (1UL)                     /*!< TT_PMU WRER: WAKEUP_1 (Bit 1)                         */
#define TT_PMU_WRER_WAKEUP_1_Msk          (0x2UL)                   /*!< TT_PMU WRER: WAKEUP_1 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_2_Pos          (2UL)                     /*!< TT_PMU WRER: WAKEUP_2 (Bit 2)                         */
#define TT_PMU_WRER_WAKEUP_2_Msk          (0x4UL)                   /*!< TT_PMU WRER: WAKEUP_2 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_3_Pos          (3UL)                     /*!< TT_PMU WRER: WAKEUP_3 (Bit 3)                         */
#define TT_PMU_WRER_WAKEUP_3_Msk          (0x8UL)                   /*!< TT_PMU WRER: WAKEUP_3 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_4_Pos          (4UL)                     /*!< TT_PMU WRER: WAKEUP_4 (Bit 4)                         */
#define TT_PMU_WRER_WAKEUP_4_Msk          (0x10UL)                  /*!< TT_PMU WRER: WAKEUP_4 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_5_Pos          (5UL)                     /*!< TT_PMU WRER: WAKEUP_5 (Bit 5)                         */
#define TT_PMU_WRER_WAKEUP_5_Msk          (0x20UL)                  /*!< TT_PMU WRER: WAKEUP_5 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_6_Pos          (6UL)                     /*!< TT_PMU WRER: WAKEUP_6 (Bit 6)                         */
#define TT_PMU_WRER_WAKEUP_6_Msk          (0x40UL)                  /*!< TT_PMU WRER: WAKEUP_6 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_7_Pos          (7UL)                     /*!< TT_PMU WRER: WAKEUP_7 (Bit 7)                         */
#define TT_PMU_WRER_WAKEUP_7_Msk          (0x80UL)                  /*!< TT_PMU WRER: WAKEUP_7 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_8_Pos          (8UL)                     /*!< TT_PMU WRER: WAKEUP_8 (Bit 8)                         */
#define TT_PMU_WRER_WAKEUP_8_Msk          (0x100UL)                 /*!< TT_PMU WRER: WAKEUP_8 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_9_Pos          (9UL)                     /*!< TT_PMU WRER: WAKEUP_9 (Bit 9)                         */
#define TT_PMU_WRER_WAKEUP_9_Msk          (0x200UL)                 /*!< TT_PMU WRER: WAKEUP_9 (Bitfield-Mask: 0x01)           */
#define TT_PMU_WRER_WAKEUP_10_Pos         (10UL)                    /*!< TT_PMU WRER: WAKEUP_10 (Bit 10)                       */
#define TT_PMU_WRER_WAKEUP_10_Msk         (0x400UL)                 /*!< TT_PMU WRER: WAKEUP_10 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_11_Pos         (11UL)                    /*!< TT_PMU WRER: WAKEUP_11 (Bit 11)                       */
#define TT_PMU_WRER_WAKEUP_11_Msk         (0x800UL)                 /*!< TT_PMU WRER: WAKEUP_11 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_12_Pos         (12UL)                    /*!< TT_PMU WRER: WAKEUP_12 (Bit 12)                       */
#define TT_PMU_WRER_WAKEUP_12_Msk         (0x1000UL)                /*!< TT_PMU WRER: WAKEUP_12 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_13_Pos         (13UL)                    /*!< TT_PMU WRER: WAKEUP_13 (Bit 13)                       */
#define TT_PMU_WRER_WAKEUP_13_Msk         (0x2000UL)                /*!< TT_PMU WRER: WAKEUP_13 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_14_Pos         (14UL)                    /*!< TT_PMU WRER: WAKEUP_14 (Bit 14)                       */
#define TT_PMU_WRER_WAKEUP_14_Msk         (0x4000UL)                /*!< TT_PMU WRER: WAKEUP_14 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_15_Pos         (15UL)                    /*!< TT_PMU WRER: WAKEUP_15 (Bit 15)                       */
#define TT_PMU_WRER_WAKEUP_15_Msk         (0x8000UL)                /*!< TT_PMU WRER: WAKEUP_15 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_16_Pos         (16UL)                    /*!< TT_PMU WRER: WAKEUP_16 (Bit 16)                       */
#define TT_PMU_WRER_WAKEUP_16_Msk         (0x10000UL)               /*!< TT_PMU WRER: WAKEUP_16 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_17_Pos         (17UL)                    /*!< TT_PMU WRER: WAKEUP_17 (Bit 17)                       */
#define TT_PMU_WRER_WAKEUP_17_Msk         (0x20000UL)               /*!< TT_PMU WRER: WAKEUP_17 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_18_Pos         (18UL)                    /*!< TT_PMU WRER: WAKEUP_18 (Bit 18)                       */
#define TT_PMU_WRER_WAKEUP_18_Msk         (0x40000UL)               /*!< TT_PMU WRER: WAKEUP_18 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_19_Pos         (19UL)                    /*!< TT_PMU WRER: WAKEUP_19 (Bit 19)                       */
#define TT_PMU_WRER_WAKEUP_19_Msk         (0x80000UL)               /*!< TT_PMU WRER: WAKEUP_19 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_20_Pos         (20UL)                    /*!< TT_PMU WRER: WAKEUP_20 (Bit 20)                       */
#define TT_PMU_WRER_WAKEUP_20_Msk         (0x100000UL)              /*!< TT_PMU WRER: WAKEUP_20 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_21_Pos         (21UL)                    /*!< TT_PMU WRER: WAKEUP_21 (Bit 21)                       */
#define TT_PMU_WRER_WAKEUP_21_Msk         (0x200000UL)              /*!< TT_PMU WRER: WAKEUP_21 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_22_Pos         (22UL)                    /*!< TT_PMU WRER: WAKEUP_22 (Bit 22)                       */
#define TT_PMU_WRER_WAKEUP_22_Msk         (0x400000UL)              /*!< TT_PMU WRER: WAKEUP_22 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_23_Pos         (23UL)                    /*!< TT_PMU WRER: WAKEUP_23 (Bit 23)                       */
#define TT_PMU_WRER_WAKEUP_23_Msk         (0x800000UL)              /*!< TT_PMU WRER: WAKEUP_23 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_24_Pos         (24UL)                    /*!< TT_PMU WRER: WAKEUP_24 (Bit 24)                       */
#define TT_PMU_WRER_WAKEUP_24_Msk         (0x1000000UL)             /*!< TT_PMU WRER: WAKEUP_24 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_25_Pos         (25UL)                    /*!< TT_PMU WRER: WAKEUP_25 (Bit 25)                       */
#define TT_PMU_WRER_WAKEUP_25_Msk         (0x2000000UL)             /*!< TT_PMU WRER: WAKEUP_25 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_26_Pos         (26UL)                    /*!< TT_PMU WRER: WAKEUP_26 (Bit 26)                       */
#define TT_PMU_WRER_WAKEUP_26_Msk         (0x4000000UL)             /*!< TT_PMU WRER: WAKEUP_26 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_27_Pos         (27UL)                    /*!< TT_PMU WRER: WAKEUP_27 (Bit 27)                       */
#define TT_PMU_WRER_WAKEUP_27_Msk         (0x8000000UL)             /*!< TT_PMU WRER: WAKEUP_27 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_28_Pos         (28UL)                    /*!< TT_PMU WRER: WAKEUP_28 (Bit 28)                       */
#define TT_PMU_WRER_WAKEUP_28_Msk         (0x10000000UL)            /*!< TT_PMU WRER: WAKEUP_28 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_29_Pos         (29UL)                    /*!< TT_PMU WRER: WAKEUP_29 (Bit 29)                       */
#define TT_PMU_WRER_WAKEUP_29_Msk         (0x20000000UL)            /*!< TT_PMU WRER: WAKEUP_29 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_30_Pos         (30UL)                    /*!< TT_PMU WRER: WAKEUP_30 (Bit 30)                       */
#define TT_PMU_WRER_WAKEUP_30_Msk         (0x40000000UL)            /*!< TT_PMU WRER: WAKEUP_30 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WRER_WAKEUP_31_Pos         (31UL)                    /*!< TT_PMU WRER: WAKEUP_31 (Bit 31)                       */
#define TT_PMU_WRER_WAKEUP_31_Msk         (0x80000000UL)            /*!< TT_PMU WRER: WAKEUP_31 (Bitfield-Mask: 0x01)          */
/* ========================================================  WIREER  ========================================================= */
#define TT_PMU_WIREER_WAKEUP_0_Pos        (0UL)                     /*!< TT_PMU WIREER: WAKEUP_0 (Bit 0)                       */
#define TT_PMU_WIREER_WAKEUP_0_Msk        (0x1UL)                   /*!< TT_PMU WIREER: WAKEUP_0 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_1_Pos        (1UL)                     /*!< TT_PMU WIREER: WAKEUP_1 (Bit 1)                       */
#define TT_PMU_WIREER_WAKEUP_1_Msk        (0x2UL)                   /*!< TT_PMU WIREER: WAKEUP_1 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_2_Pos        (2UL)                     /*!< TT_PMU WIREER: WAKEUP_2 (Bit 2)                       */
#define TT_PMU_WIREER_WAKEUP_2_Msk        (0x4UL)                   /*!< TT_PMU WIREER: WAKEUP_2 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_3_Pos        (3UL)                     /*!< TT_PMU WIREER: WAKEUP_3 (Bit 3)                       */
#define TT_PMU_WIREER_WAKEUP_3_Msk        (0x8UL)                   /*!< TT_PMU WIREER: WAKEUP_3 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_4_Pos        (4UL)                     /*!< TT_PMU WIREER: WAKEUP_4 (Bit 4)                       */
#define TT_PMU_WIREER_WAKEUP_4_Msk        (0x10UL)                  /*!< TT_PMU WIREER: WAKEUP_4 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_5_Pos        (5UL)                     /*!< TT_PMU WIREER: WAKEUP_5 (Bit 5)                       */
#define TT_PMU_WIREER_WAKEUP_5_Msk        (0x20UL)                  /*!< TT_PMU WIREER: WAKEUP_5 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_6_Pos        (6UL)                     /*!< TT_PMU WIREER: WAKEUP_6 (Bit 6)                       */
#define TT_PMU_WIREER_WAKEUP_6_Msk        (0x40UL)                  /*!< TT_PMU WIREER: WAKEUP_6 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_7_Pos        (7UL)                     /*!< TT_PMU WIREER: WAKEUP_7 (Bit 7)                       */
#define TT_PMU_WIREER_WAKEUP_7_Msk        (0x80UL)                  /*!< TT_PMU WIREER: WAKEUP_7 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_8_Pos        (8UL)                     /*!< TT_PMU WIREER: WAKEUP_8 (Bit 8)                       */
#define TT_PMU_WIREER_WAKEUP_8_Msk        (0x100UL)                 /*!< TT_PMU WIREER: WAKEUP_8 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_9_Pos        (9UL)                     /*!< TT_PMU WIREER: WAKEUP_9 (Bit 9)                       */
#define TT_PMU_WIREER_WAKEUP_9_Msk        (0x200UL)                 /*!< TT_PMU WIREER: WAKEUP_9 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIREER_WAKEUP_10_Pos       (10UL)                    /*!< TT_PMU WIREER: WAKEUP_10 (Bit 10)                     */
#define TT_PMU_WIREER_WAKEUP_10_Msk       (0x400UL)                 /*!< TT_PMU WIREER: WAKEUP_10 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_11_Pos       (11UL)                    /*!< TT_PMU WIREER: WAKEUP_11 (Bit 11)                     */
#define TT_PMU_WIREER_WAKEUP_11_Msk       (0x800UL)                 /*!< TT_PMU WIREER: WAKEUP_11 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_12_Pos       (12UL)                    /*!< TT_PMU WIREER: WAKEUP_12 (Bit 12)                     */
#define TT_PMU_WIREER_WAKEUP_12_Msk       (0x1000UL)                /*!< TT_PMU WIREER: WAKEUP_12 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_13_Pos       (13UL)                    /*!< TT_PMU WIREER: WAKEUP_13 (Bit 13)                     */
#define TT_PMU_WIREER_WAKEUP_13_Msk       (0x2000UL)                /*!< TT_PMU WIREER: WAKEUP_13 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_14_Pos       (14UL)                    /*!< TT_PMU WIREER: WAKEUP_14 (Bit 14)                     */
#define TT_PMU_WIREER_WAKEUP_14_Msk       (0x4000UL)                /*!< TT_PMU WIREER: WAKEUP_14 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_15_Pos       (15UL)                    /*!< TT_PMU WIREER: WAKEUP_15 (Bit 15)                     */
#define TT_PMU_WIREER_WAKEUP_15_Msk       (0x8000UL)                /*!< TT_PMU WIREER: WAKEUP_15 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_16_Pos       (16UL)                    /*!< TT_PMU WIREER: WAKEUP_16 (Bit 16)                     */
#define TT_PMU_WIREER_WAKEUP_16_Msk       (0x10000UL)               /*!< TT_PMU WIREER: WAKEUP_16 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_17_Pos       (17UL)                    /*!< TT_PMU WIREER: WAKEUP_17 (Bit 17)                     */
#define TT_PMU_WIREER_WAKEUP_17_Msk       (0x20000UL)               /*!< TT_PMU WIREER: WAKEUP_17 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_18_Pos       (18UL)                    /*!< TT_PMU WIREER: WAKEUP_18 (Bit 18)                     */
#define TT_PMU_WIREER_WAKEUP_18_Msk       (0x40000UL)               /*!< TT_PMU WIREER: WAKEUP_18 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_19_Pos       (19UL)                    /*!< TT_PMU WIREER: WAKEUP_19 (Bit 19)                     */
#define TT_PMU_WIREER_WAKEUP_19_Msk       (0x80000UL)               /*!< TT_PMU WIREER: WAKEUP_19 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_20_Pos       (20UL)                    /*!< TT_PMU WIREER: WAKEUP_20 (Bit 20)                     */
#define TT_PMU_WIREER_WAKEUP_20_Msk       (0x100000UL)              /*!< TT_PMU WIREER: WAKEUP_20 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_21_Pos       (21UL)                    /*!< TT_PMU WIREER: WAKEUP_21 (Bit 21)                     */
#define TT_PMU_WIREER_WAKEUP_21_Msk       (0x200000UL)              /*!< TT_PMU WIREER: WAKEUP_21 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_22_Pos       (22UL)                    /*!< TT_PMU WIREER: WAKEUP_22 (Bit 22)                     */
#define TT_PMU_WIREER_WAKEUP_22_Msk       (0x400000UL)              /*!< TT_PMU WIREER: WAKEUP_22 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_23_Pos       (23UL)                    /*!< TT_PMU WIREER: WAKEUP_23 (Bit 23)                     */
#define TT_PMU_WIREER_WAKEUP_23_Msk       (0x800000UL)              /*!< TT_PMU WIREER: WAKEUP_23 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_24_Pos       (24UL)                    /*!< TT_PMU WIREER: WAKEUP_24 (Bit 24)                     */
#define TT_PMU_WIREER_WAKEUP_24_Msk       (0x1000000UL)             /*!< TT_PMU WIREER: WAKEUP_24 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_25_Pos       (25UL)                    /*!< TT_PMU WIREER: WAKEUP_25 (Bit 25)                     */
#define TT_PMU_WIREER_WAKEUP_25_Msk       (0x2000000UL)             /*!< TT_PMU WIREER: WAKEUP_25 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_26_Pos       (26UL)                    /*!< TT_PMU WIREER: WAKEUP_26 (Bit 26)                     */
#define TT_PMU_WIREER_WAKEUP_26_Msk       (0x4000000UL)             /*!< TT_PMU WIREER: WAKEUP_26 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_27_Pos       (27UL)                    /*!< TT_PMU WIREER: WAKEUP_27 (Bit 27)                     */
#define TT_PMU_WIREER_WAKEUP_27_Msk       (0x8000000UL)             /*!< TT_PMU WIREER: WAKEUP_27 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_28_Pos       (28UL)                    /*!< TT_PMU WIREER: WAKEUP_28 (Bit 28)                     */
#define TT_PMU_WIREER_WAKEUP_28_Msk       (0x10000000UL)            /*!< TT_PMU WIREER: WAKEUP_28 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_29_Pos       (29UL)                    /*!< TT_PMU WIREER: WAKEUP_29 (Bit 29)                     */
#define TT_PMU_WIREER_WAKEUP_29_Msk       (0x20000000UL)            /*!< TT_PMU WIREER: WAKEUP_29 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_30_Pos       (30UL)                    /*!< TT_PMU WIREER: WAKEUP_30 (Bit 30)                     */
#define TT_PMU_WIREER_WAKEUP_30_Msk       (0x40000000UL)            /*!< TT_PMU WIREER: WAKEUP_30 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIREER_WAKEUP_31_Pos       (31UL)                    /*!< TT_PMU WIREER: WAKEUP_31 (Bit 31)                     */
#define TT_PMU_WIREER_WAKEUP_31_Msk       (0x80000000UL)            /*!< TT_PMU WIREER: WAKEUP_31 (Bitfield-Mask: 0x01)        */
/* ========================================================  WIFEER  ========================================================= */
#define TT_PMU_WIFEER_WAKEUP_0_Pos        (0UL)                     /*!< TT_PMU WIFEER: WAKEUP_0 (Bit 0)                       */
#define TT_PMU_WIFEER_WAKEUP_0_Msk        (0x1UL)                   /*!< TT_PMU WIFEER: WAKEUP_0 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_1_Pos        (1UL)                     /*!< TT_PMU WIFEER: WAKEUP_1 (Bit 1)                       */
#define TT_PMU_WIFEER_WAKEUP_1_Msk        (0x2UL)                   /*!< TT_PMU WIFEER: WAKEUP_1 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_2_Pos        (2UL)                     /*!< TT_PMU WIFEER: WAKEUP_2 (Bit 2)                       */
#define TT_PMU_WIFEER_WAKEUP_2_Msk        (0x4UL)                   /*!< TT_PMU WIFEER: WAKEUP_2 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_3_Pos        (3UL)                     /*!< TT_PMU WIFEER: WAKEUP_3 (Bit 3)                       */
#define TT_PMU_WIFEER_WAKEUP_3_Msk        (0x8UL)                   /*!< TT_PMU WIFEER: WAKEUP_3 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_4_Pos        (4UL)                     /*!< TT_PMU WIFEER: WAKEUP_4 (Bit 4)                       */
#define TT_PMU_WIFEER_WAKEUP_4_Msk        (0x10UL)                  /*!< TT_PMU WIFEER: WAKEUP_4 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_5_Pos        (5UL)                     /*!< TT_PMU WIFEER: WAKEUP_5 (Bit 5)                       */
#define TT_PMU_WIFEER_WAKEUP_5_Msk        (0x20UL)                  /*!< TT_PMU WIFEER: WAKEUP_5 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_6_Pos        (6UL)                     /*!< TT_PMU WIFEER: WAKEUP_6 (Bit 6)                       */
#define TT_PMU_WIFEER_WAKEUP_6_Msk        (0x40UL)                  /*!< TT_PMU WIFEER: WAKEUP_6 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_7_Pos        (7UL)                     /*!< TT_PMU WIFEER: WAKEUP_7 (Bit 7)                       */
#define TT_PMU_WIFEER_WAKEUP_7_Msk        (0x80UL)                  /*!< TT_PMU WIFEER: WAKEUP_7 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_8_Pos        (8UL)                     /*!< TT_PMU WIFEER: WAKEUP_8 (Bit 8)                       */
#define TT_PMU_WIFEER_WAKEUP_8_Msk        (0x100UL)                 /*!< TT_PMU WIFEER: WAKEUP_8 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_9_Pos        (9UL)                     /*!< TT_PMU WIFEER: WAKEUP_9 (Bit 9)                       */
#define TT_PMU_WIFEER_WAKEUP_9_Msk        (0x200UL)                 /*!< TT_PMU WIFEER: WAKEUP_9 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFEER_WAKEUP_10_Pos       (10UL)                    /*!< TT_PMU WIFEER: WAKEUP_10 (Bit 10)                     */
#define TT_PMU_WIFEER_WAKEUP_10_Msk       (0x400UL)                 /*!< TT_PMU WIFEER: WAKEUP_10 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_11_Pos       (11UL)                    /*!< TT_PMU WIFEER: WAKEUP_11 (Bit 11)                     */
#define TT_PMU_WIFEER_WAKEUP_11_Msk       (0x800UL)                 /*!< TT_PMU WIFEER: WAKEUP_11 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_12_Pos       (12UL)                    /*!< TT_PMU WIFEER: WAKEUP_12 (Bit 12)                     */
#define TT_PMU_WIFEER_WAKEUP_12_Msk       (0x1000UL)                /*!< TT_PMU WIFEER: WAKEUP_12 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_13_Pos       (13UL)                    /*!< TT_PMU WIFEER: WAKEUP_13 (Bit 13)                     */
#define TT_PMU_WIFEER_WAKEUP_13_Msk       (0x2000UL)                /*!< TT_PMU WIFEER: WAKEUP_13 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_14_Pos       (14UL)                    /*!< TT_PMU WIFEER: WAKEUP_14 (Bit 14)                     */
#define TT_PMU_WIFEER_WAKEUP_14_Msk       (0x4000UL)                /*!< TT_PMU WIFEER: WAKEUP_14 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_15_Pos       (15UL)                    /*!< TT_PMU WIFEER: WAKEUP_15 (Bit 15)                     */
#define TT_PMU_WIFEER_WAKEUP_15_Msk       (0x8000UL)                /*!< TT_PMU WIFEER: WAKEUP_15 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_16_Pos       (16UL)                    /*!< TT_PMU WIFEER: WAKEUP_16 (Bit 16)                     */
#define TT_PMU_WIFEER_WAKEUP_16_Msk       (0x10000UL)               /*!< TT_PMU WIFEER: WAKEUP_16 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_17_Pos       (17UL)                    /*!< TT_PMU WIFEER: WAKEUP_17 (Bit 17)                     */
#define TT_PMU_WIFEER_WAKEUP_17_Msk       (0x20000UL)               /*!< TT_PMU WIFEER: WAKEUP_17 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_18_Pos       (18UL)                    /*!< TT_PMU WIFEER: WAKEUP_18 (Bit 18)                     */
#define TT_PMU_WIFEER_WAKEUP_18_Msk       (0x40000UL)               /*!< TT_PMU WIFEER: WAKEUP_18 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_19_Pos       (19UL)                    /*!< TT_PMU WIFEER: WAKEUP_19 (Bit 19)                     */
#define TT_PMU_WIFEER_WAKEUP_19_Msk       (0x80000UL)               /*!< TT_PMU WIFEER: WAKEUP_19 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_20_Pos       (20UL)                    /*!< TT_PMU WIFEER: WAKEUP_20 (Bit 20)                     */
#define TT_PMU_WIFEER_WAKEUP_20_Msk       (0x100000UL)              /*!< TT_PMU WIFEER: WAKEUP_20 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_21_Pos       (21UL)                    /*!< TT_PMU WIFEER: WAKEUP_21 (Bit 21)                     */
#define TT_PMU_WIFEER_WAKEUP_21_Msk       (0x200000UL)              /*!< TT_PMU WIFEER: WAKEUP_21 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_22_Pos       (22UL)                    /*!< TT_PMU WIFEER: WAKEUP_22 (Bit 22)                     */
#define TT_PMU_WIFEER_WAKEUP_22_Msk       (0x400000UL)              /*!< TT_PMU WIFEER: WAKEUP_22 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_23_Pos       (23UL)                    /*!< TT_PMU WIFEER: WAKEUP_23 (Bit 23)                     */
#define TT_PMU_WIFEER_WAKEUP_23_Msk       (0x800000UL)              /*!< TT_PMU WIFEER: WAKEUP_23 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_24_Pos       (24UL)                    /*!< TT_PMU WIFEER: WAKEUP_24 (Bit 24)                     */
#define TT_PMU_WIFEER_WAKEUP_24_Msk       (0x1000000UL)             /*!< TT_PMU WIFEER: WAKEUP_24 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_25_Pos       (25UL)                    /*!< TT_PMU WIFEER: WAKEUP_25 (Bit 25)                     */
#define TT_PMU_WIFEER_WAKEUP_25_Msk       (0x2000000UL)             /*!< TT_PMU WIFEER: WAKEUP_25 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_26_Pos       (26UL)                    /*!< TT_PMU WIFEER: WAKEUP_26 (Bit 26)                     */
#define TT_PMU_WIFEER_WAKEUP_26_Msk       (0x4000000UL)             /*!< TT_PMU WIFEER: WAKEUP_26 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_27_Pos       (27UL)                    /*!< TT_PMU WIFEER: WAKEUP_27 (Bit 27)                     */
#define TT_PMU_WIFEER_WAKEUP_27_Msk       (0x8000000UL)             /*!< TT_PMU WIFEER: WAKEUP_27 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_28_Pos       (28UL)                    /*!< TT_PMU WIFEER: WAKEUP_28 (Bit 28)                     */
#define TT_PMU_WIFEER_WAKEUP_28_Msk       (0x10000000UL)            /*!< TT_PMU WIFEER: WAKEUP_28 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_29_Pos       (29UL)                    /*!< TT_PMU WIFEER: WAKEUP_29 (Bit 29)                     */
#define TT_PMU_WIFEER_WAKEUP_29_Msk       (0x20000000UL)            /*!< TT_PMU WIFEER: WAKEUP_29 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_30_Pos       (30UL)                    /*!< TT_PMU WIFEER: WAKEUP_30 (Bit 30)                     */
#define TT_PMU_WIFEER_WAKEUP_30_Msk       (0x40000000UL)            /*!< TT_PMU WIFEER: WAKEUP_30 (Bitfield-Mask: 0x01)        */
#define TT_PMU_WIFEER_WAKEUP_31_Pos       (31UL)                    /*!< TT_PMU WIFEER: WAKEUP_31 (Bit 31)                     */
#define TT_PMU_WIFEER_WAKEUP_31_Msk       (0x80000000UL)            /*!< TT_PMU WIFEER: WAKEUP_31 (Bitfield-Mask: 0x01)        */
/* =========================================================  WIFER  ========================================================= */
#define TT_PMU_WIFER_WAKEUP_0_Pos         (0UL)                     /*!< TT_PMU WIFER: WAKEUP_0 (Bit 0)                        */
#define TT_PMU_WIFER_WAKEUP_0_Msk         (0x1UL)                   /*!< TT_PMU WIFER: WAKEUP_0 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_1_Pos         (1UL)                     /*!< TT_PMU WIFER: WAKEUP_1 (Bit 1)                        */
#define TT_PMU_WIFER_WAKEUP_1_Msk         (0x2UL)                   /*!< TT_PMU WIFER: WAKEUP_1 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_2_Pos         (2UL)                     /*!< TT_PMU WIFER: WAKEUP_2 (Bit 2)                        */
#define TT_PMU_WIFER_WAKEUP_2_Msk         (0x4UL)                   /*!< TT_PMU WIFER: WAKEUP_2 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_3_Pos         (3UL)                     /*!< TT_PMU WIFER: WAKEUP_3 (Bit 3)                        */
#define TT_PMU_WIFER_WAKEUP_3_Msk         (0x8UL)                   /*!< TT_PMU WIFER: WAKEUP_3 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_4_Pos         (4UL)                     /*!< TT_PMU WIFER: WAKEUP_4 (Bit 4)                        */
#define TT_PMU_WIFER_WAKEUP_4_Msk         (0x10UL)                  /*!< TT_PMU WIFER: WAKEUP_4 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_5_Pos         (5UL)                     /*!< TT_PMU WIFER: WAKEUP_5 (Bit 5)                        */
#define TT_PMU_WIFER_WAKEUP_5_Msk         (0x20UL)                  /*!< TT_PMU WIFER: WAKEUP_5 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_6_Pos         (6UL)                     /*!< TT_PMU WIFER: WAKEUP_6 (Bit 6)                        */
#define TT_PMU_WIFER_WAKEUP_6_Msk         (0x40UL)                  /*!< TT_PMU WIFER: WAKEUP_6 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_7_Pos         (7UL)                     /*!< TT_PMU WIFER: WAKEUP_7 (Bit 7)                        */
#define TT_PMU_WIFER_WAKEUP_7_Msk         (0x80UL)                  /*!< TT_PMU WIFER: WAKEUP_7 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_8_Pos         (8UL)                     /*!< TT_PMU WIFER: WAKEUP_8 (Bit 8)                        */
#define TT_PMU_WIFER_WAKEUP_8_Msk         (0x100UL)                 /*!< TT_PMU WIFER: WAKEUP_8 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_9_Pos         (9UL)                     /*!< TT_PMU WIFER: WAKEUP_9 (Bit 9)                        */
#define TT_PMU_WIFER_WAKEUP_9_Msk         (0x200UL)                 /*!< TT_PMU WIFER: WAKEUP_9 (Bitfield-Mask: 0x01)          */
#define TT_PMU_WIFER_WAKEUP_10_Pos        (10UL)                    /*!< TT_PMU WIFER: WAKEUP_10 (Bit 10)                      */
#define TT_PMU_WIFER_WAKEUP_10_Msk        (0x400UL)                 /*!< TT_PMU WIFER: WAKEUP_10 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_11_Pos        (11UL)                    /*!< TT_PMU WIFER: WAKEUP_11 (Bit 11)                      */
#define TT_PMU_WIFER_WAKEUP_11_Msk        (0x800UL)                 /*!< TT_PMU WIFER: WAKEUP_11 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_12_Pos        (12UL)                    /*!< TT_PMU WIFER: WAKEUP_12 (Bit 12)                      */
#define TT_PMU_WIFER_WAKEUP_12_Msk        (0x1000UL)                /*!< TT_PMU WIFER: WAKEUP_12 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_13_Pos        (13UL)                    /*!< TT_PMU WIFER: WAKEUP_13 (Bit 13)                      */
#define TT_PMU_WIFER_WAKEUP_13_Msk        (0x2000UL)                /*!< TT_PMU WIFER: WAKEUP_13 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_14_Pos        (14UL)                    /*!< TT_PMU WIFER: WAKEUP_14 (Bit 14)                      */
#define TT_PMU_WIFER_WAKEUP_14_Msk        (0x4000UL)                /*!< TT_PMU WIFER: WAKEUP_14 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_15_Pos        (15UL)                    /*!< TT_PMU WIFER: WAKEUP_15 (Bit 15)                      */
#define TT_PMU_WIFER_WAKEUP_15_Msk        (0x8000UL)                /*!< TT_PMU WIFER: WAKEUP_15 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_16_Pos        (16UL)                    /*!< TT_PMU WIFER: WAKEUP_16 (Bit 16)                      */
#define TT_PMU_WIFER_WAKEUP_16_Msk        (0x10000UL)               /*!< TT_PMU WIFER: WAKEUP_16 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_17_Pos        (17UL)                    /*!< TT_PMU WIFER: WAKEUP_17 (Bit 17)                      */
#define TT_PMU_WIFER_WAKEUP_17_Msk        (0x20000UL)               /*!< TT_PMU WIFER: WAKEUP_17 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_18_Pos        (18UL)                    /*!< TT_PMU WIFER: WAKEUP_18 (Bit 18)                      */
#define TT_PMU_WIFER_WAKEUP_18_Msk        (0x40000UL)               /*!< TT_PMU WIFER: WAKEUP_18 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_19_Pos        (19UL)                    /*!< TT_PMU WIFER: WAKEUP_19 (Bit 19)                      */
#define TT_PMU_WIFER_WAKEUP_19_Msk        (0x80000UL)               /*!< TT_PMU WIFER: WAKEUP_19 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_20_Pos        (20UL)                    /*!< TT_PMU WIFER: WAKEUP_20 (Bit 20)                      */
#define TT_PMU_WIFER_WAKEUP_20_Msk        (0x100000UL)              /*!< TT_PMU WIFER: WAKEUP_20 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_21_Pos        (21UL)                    /*!< TT_PMU WIFER: WAKEUP_21 (Bit 21)                      */
#define TT_PMU_WIFER_WAKEUP_21_Msk        (0x200000UL)              /*!< TT_PMU WIFER: WAKEUP_21 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_22_Pos        (22UL)                    /*!< TT_PMU WIFER: WAKEUP_22 (Bit 22)                      */
#define TT_PMU_WIFER_WAKEUP_22_Msk        (0x400000UL)              /*!< TT_PMU WIFER: WAKEUP_22 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_23_Pos        (23UL)                    /*!< TT_PMU WIFER: WAKEUP_23 (Bit 23)                      */
#define TT_PMU_WIFER_WAKEUP_23_Msk        (0x800000UL)              /*!< TT_PMU WIFER: WAKEUP_23 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_24_Pos        (24UL)                    /*!< TT_PMU WIFER: WAKEUP_24 (Bit 24)                      */
#define TT_PMU_WIFER_WAKEUP_24_Msk        (0x1000000UL)             /*!< TT_PMU WIFER: WAKEUP_24 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_25_Pos        (25UL)                    /*!< TT_PMU WIFER: WAKEUP_25 (Bit 25)                      */
#define TT_PMU_WIFER_WAKEUP_25_Msk        (0x2000000UL)             /*!< TT_PMU WIFER: WAKEUP_25 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_26_Pos        (26UL)                    /*!< TT_PMU WIFER: WAKEUP_26 (Bit 26)                      */
#define TT_PMU_WIFER_WAKEUP_26_Msk        (0x4000000UL)             /*!< TT_PMU WIFER: WAKEUP_26 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_27_Pos        (27UL)                    /*!< TT_PMU WIFER: WAKEUP_27 (Bit 27)                      */
#define TT_PMU_WIFER_WAKEUP_27_Msk        (0x8000000UL)             /*!< TT_PMU WIFER: WAKEUP_27 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_28_Pos        (28UL)                    /*!< TT_PMU WIFER: WAKEUP_28 (Bit 28)                      */
#define TT_PMU_WIFER_WAKEUP_28_Msk        (0x10000000UL)            /*!< TT_PMU WIFER: WAKEUP_28 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_29_Pos        (29UL)                    /*!< TT_PMU WIFER: WAKEUP_29 (Bit 29)                      */
#define TT_PMU_WIFER_WAKEUP_29_Msk        (0x20000000UL)            /*!< TT_PMU WIFER: WAKEUP_29 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_30_Pos        (30UL)                    /*!< TT_PMU WIFER: WAKEUP_30 (Bit 30)                      */
#define TT_PMU_WIFER_WAKEUP_30_Msk        (0x40000000UL)            /*!< TT_PMU WIFER: WAKEUP_30 (Bitfield-Mask: 0x01)         */
#define TT_PMU_WIFER_WAKEUP_31_Pos        (31UL)                    /*!< TT_PMU WIFER: WAKEUP_31 (Bit 31)                      */
#define TT_PMU_WIFER_WAKEUP_31_Msk        (0x80000000UL)            /*!< TT_PMU WIFER: WAKEUP_31 (Bitfield-Mask: 0x01)         */
/* ========================================================  ID_REG  ========================================================= */
#define TT_PMU_ID_REG_B_VERSION_Pos       (0UL)                     /*!< TT_PMU ID_REG: B_VERSION (Bit 0)                      */
#define TT_PMU_ID_REG_B_VERSION_Msk       (0xfUL)                   /*!< TT_PMU ID_REG: B_VERSION (Bitfield-Mask: 0x0f)        */
#define TT_PMU_ID_REG_M_VERSION_Pos       (4UL)                     /*!< TT_PMU ID_REG: M_VERSION (Bit 4)                      */
#define TT_PMU_ID_REG_M_VERSION_Msk       (0xf0UL)                  /*!< TT_PMU ID_REG: M_VERSION (Bitfield-Mask: 0x0f)        */
#define TT_PMU_ID_REG_REG_WIDTH_Pos       (8UL)                     /*!< TT_PMU ID_REG: REG_WIDTH (Bit 8)                      */
#define TT_PMU_ID_REG_REG_WIDTH_Msk       (0xff00UL)                /*!< TT_PMU ID_REG: REG_WIDTH (Bitfield-Mask: 0xff)        */
#define TT_PMU_ID_REG_M_NUM_Pos           (16UL)                    /*!< TT_PMU ID_REG: M_NUM (Bit 16)                         */
#define TT_PMU_ID_REG_M_NUM_Msk           (0xffff0000UL)            /*!< TT_PMU ID_REG: M_NUM (Bitfield-Mask: 0xffff)          */

#ifdef __cplusplus
}
#endif

#endif  /* end of A8V2_PMU_H */
