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
#ifndef A8V2E_PFCU_H
#define A8V2E_PFCU_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_PFCU_VENDOR_ID_H                     1541
#define A8V2E_PFCU_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_PFCU_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_PFCU_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_PFCU_SW_MAJOR_VERSION_H              1
#define A8V2E_PFCU_SW_MINOR_VERSION_H              1
#define A8V2E_PFCU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_PFCU.h and TT_Common.h file version check */
#if (A8V2E_PFCU_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_PFCU.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_PFCU_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_PFCU_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_PFCU_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_PFCU.h and TT_Common.h are different"
#endif
#if ((A8V2E_PFCU_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_PFCU_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_PFCU_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_PFCU.h and TT_Common.h are different"
#endif


/* =========================================================================================================================== */
/* ================                                          TT_PFCU                                          ================ */
/* =========================================================================================================================== */


/**
  * @brief PFCU Controller Device (TT_PFCU)
  */

typedef struct {                                /*!< (@ 0x40192000) TT_PFCU Structure                                          */
  __IM  uint32_t  RESERVED;
  __OM  uint32_t  KEYR;                         /*!< (@ 0x00000004) Coder register                                             */
  __IOM uint32_t  CR;                           /*!< (@ 0x00000008) Control register                                           */
  __IOM uint32_t  INTENR;                       /*!< (@ 0x0000000C) Interrupt Enable Register                                  */
  __IM  uint32_t  INTSR;                        /*!< (@ 0x00000010) Interrupt Status Register                                  */
  __IOM uint32_t  SR;                           /*!< (@ 0x00000014) Status register                                            */
  __IM  uint32_t  RESERVED1[2];
  __IM  uint32_t  FAR;                          /*!< (@ 0x00000020) Fault Address Register                                     */
  __IM  uint32_t  RESERVED2[7];
  __IOM uint32_t  RLR;                          /*!< (@ 0x00000040) Read latency                                               */
  __IM  uint32_t  RESERVED3[3];
  __IOM uint32_t  WEPR[4];                      /*!< (@ 0x00000050) Write protection Register                                  */
  __IOM uint32_t  WEPLR[4];                     /*!< (@ 0x00000060) Write protection Lock.                                     */
  __IOM uint32_t  BLPR0;                        /*!< (@ 0x00000070) Bootload protection register.                              */
  __IOM uint32_t  BLPR1;                        /*!< (@ 0x00000074) Bootload protection register.                              */
  __IM  uint32_t  RESERVED4[2];
  __IOM uint32_t  SWAP0;                        /*!< (@ 0x00000080) SWAP function.                                             */
  __IOM uint32_t  SWAP1;                        /*!< (@ 0x00000084) SWAP function.                                             */
  __IM  uint32_t  RESERVED5[2];
  __IOM uint32_t  SUPV;                         /*!< (@ 0x00000090) Read latency                                               */
  __IM  uint32_t  RESERVED6[3];
  __OM  uint32_t  ACODER[4];                    /*!< (@ 0x000000A0) Read latency                                               */
  __IM  uint32_t  RESERVED7[20];
  __IM  uint32_t  VIDR;                         /*!< (@ 0x00000100) Read latency                                               */
} PFCU_Type, *PFCU_MemMapPtr;                    /*!< Size = 260 (0x104)                                                        */


/** Number of instances of the FCU module. */
#define TT_PFCU_INSTANCE_COUNT                       (1u)

/* FCU - Peripheral instance base addresses */
/** Peripheral FCU base address */
#define TT_PFCU_BASE                              (0x40192000UL)

/** Peripheral FCU base pointer */
#define TT_PFCU                                   ((PFCU_Type *)TT_PFCU_BASE)

/** Array initializer of FCU peripheral base addresses */
#define TT_PFCU_BASE_ADDRS                        { TT_PFCU_BASE }

/** Array initializer of FCU peripheral base pointers */
#define TT_PFCU_BASE_PTRS                         { TT_PFCU}

/* define flash info */
#define PFLASH_SIZE_1M          0x100000U
#define PFLASH_SIZE_2M          0x200000U
#define PFLASH_SIZE_4M          0x400000U
#define PFLASH_BASE             0x1000000U    /* Flash base address */
#define PFLASH_SIZE             0x400000U
#define PFLASH_NVR_ADDR         0x1400000U
#define PFLASH_NVR_SIZE         0x8000U

#define IS_IN_PFLASH(addr)      (((addr) >= PFLASH_BASE) && ((addr) < (PFLASH_BASE + PFLASH_SIZE)) ? TRUE : FALSE)
/* =========================================================================================================================== */
/* ================                                          TT_PFCU                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  KEYR  ========================================================== */
/* ==========================================================  CR  =========================================================== */
#define TT_PFCU_CR_PG_Pos                 (0UL)                     /*!< TT_PFCU CR: PG (Bit 0)                                */
#define TT_PFCU_CR_PG_Msk                 (0x1UL)                   /*!< TT_PFCU CR: PG (Bitfield-Mask: 0x01)                  */
#define TT_PFCU_CR_SEEN_Pos               (1UL)                     /*!< TT_PFCU CR: SEEN (Bit 1)                              */
#define TT_PFCU_CR_SEEN_Msk               (0x2UL)                   /*!< TT_PFCU CR: SEEN (Bitfield-Mask: 0x01)                */
#define TT_PFCU_CR_Reserved0_Pos          (2UL)                     /*!< TT_PFCU CR: Reserved0 (Bit 2)                         */
#define TT_PFCU_CR_Reserved0_Msk          (0x4UL)                   /*!< TT_PFCU CR: Reserved0 (Bitfield-Mask: 0x01)           */
#define TT_PFCU_CR_PG_START_Pos           (3UL)                     /*!< TT_PFCU CR: PG_START (Bit 3)                          */
#define TT_PFCU_CR_PG_START_Msk           (0x8UL)                   /*!< TT_PFCU CR: PG_START (Bitfield-Mask: 0x01)            */
#define TT_PFCU_CR_ER_START_Pos           (4UL)                     /*!< TT_PFCU CR: ER_START (Bit 4)                          */
#define TT_PFCU_CR_ER_START_Msk           (0x10UL)                  /*!< TT_PFCU CR: ER_START (Bitfield-Mask: 0x01)            */
#define TT_PFCU_CR_ERV_START_Pos          (5UL)                     /*!< TT_PFCU CR: ERV_START (Bit 5)                         */
#define TT_PFCU_CR_ERV_START_Msk          (0x20UL)                  /*!< TT_PFCU CR: ERV_START (Bitfield-Mask: 0x01)           */
#define TT_PFCU_CR_KRY_LOCK_Pos           (6UL)                     /*!< TT_PFCU CR: KRY_LOCK (Bit 6)                          */
#define TT_PFCU_CR_KRY_LOCK_Msk           (0x40UL)                  /*!< TT_PFCU CR: KRY_LOCK (Bitfield-Mask: 0x01)            */
#define TT_PFCU_CR_BLPR_WEN_Pos           (7UL)                     /*!< TT_PFCU CR: BLPR_WEN (Bit 7)                          */
#define TT_PFCU_CR_BLPR_WEN_Msk           (0x80UL)                  /*!< TT_PFCU CR: BLPR_WEN (Bitfield-Mask: 0x01)            */
#define TT_PFCU_CR_NVR_ECC_DIS_Pos        (8UL)                     /*!< TT_PFCU CR: NVR_ECC_DIS (Bit 8)                       */
#define TT_PFCU_CR_NVR_ECC_DIS_Msk        (0x100UL)                 /*!< TT_PFCU CR: NVR_ECC_DIS (Bitfield-Mask: 0x01)         */
#define TT_PFCU_CR_Reserved1_Pos          (9UL)                     /*!< TT_PFCU CR: Reserved1 (Bit 9)                         */
#define TT_PFCU_CR_Reserved1_Msk          (0x1e00UL)                /*!< TT_PFCU CR: Reserved1 (Bitfield-Mask: 0x0f)           */
#define TT_PFCU_CR_SE_ADDR_Pos            (13UL)                    /*!< TT_PFCU CR: SE_ADDR (Bit 13)                          */
#define TT_PFCU_CR_SE_ADDR_Msk            (0x3fe000UL)              /*!< TT_PFCU CR: SE_ADDR (Bitfield-Mask: 0x1ff)            */
#define TT_PFCU_CR_Reserved2_Pos          (22UL)                    /*!< TT_PFCU CR: Reserved2 (Bit 22)                        */
#define TT_PFCU_CR_Reserved2_Msk          (0xffc00000UL)            /*!< TT_PFCU CR: Reserved2 (Bitfield-Mask: 0x3ff)          */
/* ========================================================  INTENR  ========================================================= */
#define TT_PFCU_INTENR_PG_DONE_INTEN_Pos  (0UL)                     /*!< TT_PFCU INTENR: PG_DONE_INTEN (Bit 0)                 */
#define TT_PFCU_INTENR_PG_DONE_INTEN_Msk  (0x1UL)                   /*!< TT_PFCU INTENR: PG_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_PFCU_INTENR_SE_DONE_INTEN_Pos  (1UL)                     /*!< TT_PFCU INTENR: SE_DONE_INTEN (Bit 1)                 */
#define TT_PFCU_INTENR_SE_DONE_INTEN_Msk  (0x2UL)                   /*!< TT_PFCU INTENR: SE_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_PFCU_INTENR_EV_DONE_INTEN_Pos  (3UL)                     /*!< TT_PFCU INTENR: EV_DONE_INTEN (Bit 3)                 */
#define TT_PFCU_INTENR_EV_DONE_INTEN_Msk  (0x8UL)                   /*!< TT_PFCU INTENR: EV_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_PFCU_INTENR_PG_ERR_INTEN_Pos   (4UL)                     /*!< TT_PFCU INTENR: PG_ERR_INTEN (Bit 4)                  */
#define TT_PFCU_INTENR_PG_ERR_INTEN_Msk   (0x10UL)                  /*!< TT_PFCU INTENR: PG_ERR_INTEN (Bitfield-Mask: 0x01)    */
#define TT_PFCU_INTENR_WRPRTERR_INTEN_Pos (6UL)                     /*!< TT_PFCU INTENR: WRPRTERR_INTEN (Bit 6)                */
#define TT_PFCU_INTENR_WRPRTERR_INTEN_Msk (0x40UL)                  /*!< TT_PFCU INTENR: WRPRTERR_INTEN (Bitfield-Mask: 0x01)  */
#define TT_PFCU_INTENR_RD_INVD_INTEN_Pos  (7UL)                     /*!< TT_PFCU INTENR: RD_INVD_INTEN (Bit 7)                 */
#define TT_PFCU_INTENR_RD_INVD_INTEN_Msk  (0x80UL)                  /*!< TT_PFCU INTENR: RD_INVD_INTEN (Bitfield-Mask: 0x01)   */
#define TT_PFCU_INTENR_KEY_ERR_INTEN_Pos  (8UL)                     /*!< TT_PFCU INTENR: KEY_ERR_INTEN (Bit 8)                 */
#define TT_PFCU_INTENR_KEY_ERR_INTEN_Msk  (0x100UL)                 /*!< TT_PFCU INTENR: KEY_ERR_INTEN (Bitfield-Mask: 0x01)   */
#define TT_PFCU_INTENR_CODE_ERR_INTEN_Pos (9UL)                     /*!< TT_PFCU INTENR: CODE_ERR_INTEN (Bit 9)                */
#define TT_PFCU_INTENR_CODE_ERR_INTEN_Msk (0x200UL)                 /*!< TT_PFCU INTENR: CODE_ERR_INTEN (Bitfield-Mask: 0x01)  */
/* =========================================================  INTSR  ========================================================= */
#define TT_PFCU_INTSR_PG_DONE_INTSR_Pos   (0UL)                     /*!< TT_PFCU INTSR: PG_DONE_INTSR (Bit 0)                  */
#define TT_PFCU_INTSR_PG_DONE_INTSR_Msk   (0x1UL)                   /*!< TT_PFCU INTSR: PG_DONE_INTSR (Bitfield-Mask: 0x01)    */
#define TT_PFCU_INTSR_SE_DONE_INTSR_Pos   (1UL)                     /*!< TT_PFCU INTSR: SE_DONE_INTSR (Bit 1)                  */
#define TT_PFCU_INTSR_SE_DONE_INTSR_Msk   (0x2UL)                   /*!< TT_PFCU INTSR: SE_DONE_INTSR (Bitfield-Mask: 0x01)    */
#define TT_PFCU_INTSR_EV_DONE_INTSR_Pos   (3UL)                     /*!< TT_PFCU INTSR: EV_DONE_INTSR (Bit 3)                  */
#define TT_PFCU_INTSR_EV_DONE_INTSR_Msk   (0x8UL)                   /*!< TT_PFCU INTSR: EV_DONE_INTSR (Bitfield-Mask: 0x01)    */
#define TT_PFCU_INTSR_PG_ERR_INTSR_Pos    (4UL)                     /*!< TT_PFCU INTSR: PG_ERR_INTSR (Bit 4)                   */
#define TT_PFCU_INTSR_PG_ERR_INTSR_Msk    (0x10UL)                  /*!< TT_PFCU INTSR: PG_ERR_INTSR (Bitfield-Mask: 0x01)     */
#define TT_PFCU_INTSR_WRPRTERR_INTSR_Pos  (6UL)                     /*!< TT_PFCU INTSR: WRPRTERR_INTSR (Bit 6)                 */
#define TT_PFCU_INTSR_WRPRTERR_INTSR_Msk  (0x40UL)                  /*!< TT_PFCU INTSR: WRPRTERR_INTSR (Bitfield-Mask: 0x01)   */
#define TT_PFCU_INTSR_RD_INVD_INTSR_Pos   (7UL)                     /*!< TT_PFCU INTSR: RD_INVD_INTSR (Bit 7)                  */
#define TT_PFCU_INTSR_RD_INVD_INTSR_Msk   (0x80UL)                  /*!< TT_PFCU INTSR: RD_INVD_INTSR (Bitfield-Mask: 0x01)    */
#define TT_PFCU_INTSR_KEY_ERR_INTSR_Pos   (8UL)                     /*!< TT_PFCU INTSR: KEY_ERR_INTSR (Bit 8)                  */
#define TT_PFCU_INTSR_KEY_ERR_INTSR_Msk   (0x100UL)                 /*!< TT_PFCU INTSR: KEY_ERR_INTSR (Bitfield-Mask: 0x01)    */
#define TT_PFCU_INTSR_CODE_ERR_INTSR_Pos  (9UL)                     /*!< TT_PFCU INTSR: CODE_ERR_INTSR (Bit 9)                 */
#define TT_PFCU_INTSR_CODE_ERR_INTSR_Msk  (0x200UL)                 /*!< TT_PFCU INTSR: CODE_ERR_INTSR (Bitfield-Mask: 0x01)   */
/* ==========================================================  SR  =========================================================== */
#define TT_PFCU_SR_SAFETY_Pos             (30UL)                    /*!< TT_PFCU SR: SAFETY (Bit 30)                           */
#define TT_PFCU_SR_SAFETY_Msk             (0x40000000UL)            /*!< TT_PFCU SR: SAFETY (Bitfield-Mask: 0x01)              */
#define TT_PFCU_SR_SRAM_SIZE_Pos          (28UL)                    /*!< TT_PFCU SR: SRAM_SIZE (Bit 28)                        */
#define TT_PFCU_SR_SRAM_SIZE_Msk          (0x30000000UL)            /*!< TT_PFCU SR: SRAM_SIZE (Bitfield-Mask: 0x03)           */
#define TT_PFCU_SR_PFLASH_SIZE_Pos        (26UL)                    /*!< TT_PFCU SR: PFLASH_SIZE (Bit 26)                      */
#define TT_PFCU_SR_PFLASH_SIZE_Msk        (0xc000000UL)             /*!< TT_PFCU SR: PFLASH_SIZE (Bitfield-Mask: 0x03)         */
#define TT_PFCU_SR_FLASH_BSY_Pos          (25UL)                    /*!< TT_PFCU SR: FLASH_BSY (Bit 25)                        */
#define TT_PFCU_SR_FLASH_BSY_Msk          (0x2000000UL)             /*!< TT_PFCU SR: FLASH_BSY (Bitfield-Mask: 0x01)           */
#define TT_PFCU_SR_NVR_WR_ALLOW_Pos       (24UL)                    /*!< TT_PFCU SR: NVR_WR_ALLOW (Bit 24)                     */
#define TT_PFCU_SR_NVR_WR_ALLOW_Msk       (0x1000000UL)             /*!< TT_PFCU SR: NVR_WR_ALLOW (Bitfield-Mask: 0x01)        */
#define TT_PFCU_SR_MAIN_WR_ALLOW_Pos      (23UL)                    /*!< TT_PFCU SR: MAIN_WR_ALLOW (Bit 23)                    */
#define TT_PFCU_SR_MAIN_WR_ALLOW_Msk      (0x800000UL)              /*!< TT_PFCU SR: MAIN_WR_ALLOW (Bitfield-Mask: 0x01)       */
#define TT_PFCU_SR_HWI_DONE_Pos           (22UL)                    /*!< TT_PFCU SR: HWI_DONE (Bit 22)                         */
#define TT_PFCU_SR_HWI_DONE_Msk           (0x400000UL)              /*!< TT_PFCU SR: HWI_DONE (Bitfield-Mask: 0x01)            */
#define TT_PFCU_SR_NVR_BK_ERR_Pos         (10UL)                    /*!< TT_PFCU SR: NVR_BK_ERR (Bit 10)                       */
#define TT_PFCU_SR_NVR_BK_ERR_Msk         (0x400UL)                 /*!< TT_PFCU SR: NVR_BK_ERR (Bitfield-Mask: 0x01)          */
#define TT_PFCU_SR_CODE_ERR_SR_Pos        (9UL)                     /*!< TT_PFCU SR: CODE_ERR_SR (Bit 9)                       */
#define TT_PFCU_SR_CODE_ERR_SR_Msk        (0x200UL)                 /*!< TT_PFCU SR: CODE_ERR_SR (Bitfield-Mask: 0x01)         */
#define TT_PFCU_SR_KEY_ERR_SR_Pos         (8UL)                     /*!< TT_PFCU SR: KEY_ERR_SR (Bit 8)                        */
#define TT_PFCU_SR_KEY_ERR_SR_Msk         (0x100UL)                 /*!< TT_PFCU SR: KEY_ERR_SR (Bitfield-Mask: 0x01)          */
#define TT_PFCU_SR_RD_INVD_SR_Pos         (7UL)                     /*!< TT_PFCU SR: RD_INVD_SR (Bit 7)                        */
#define TT_PFCU_SR_RD_INVD_SR_Msk         (0x80UL)                  /*!< TT_PFCU SR: RD_INVD_SR (Bitfield-Mask: 0x01)          */
#define TT_PFCU_SR_WRPRTERR_SR_Pos        (6UL)                     /*!< TT_PFCU SR: WRPRTERR_SR (Bit 6)                       */
#define TT_PFCU_SR_WRPRTERR_SR_Msk        (0x40UL)                  /*!< TT_PFCU SR: WRPRTERR_SR (Bitfield-Mask: 0x01)         */
#define TT_PFCU_SR_PG_ERR_SR_Pos          (4UL)                     /*!< TT_PFCU SR: PG_ERR_SR (Bit 4)                         */
#define TT_PFCU_SR_PG_ERR_SR_Msk          (0x10UL)                  /*!< TT_PFCU SR: PG_ERR_SR (Bitfield-Mask: 0x01)           */
#define TT_PFCU_SR_EV_ERR_SR_Pos          (3UL)                     /*!< TT_PFCU SR: EV_ERR_SR (Bit 3)                         */
#define TT_PFCU_SR_EV_ERR_SR_Msk          (0x8UL)                   /*!< TT_PFCU SR: EV_ERR_SR (Bitfield-Mask: 0x01)           */
#define TT_PFCU_SR_SE_DONE_SR_Pos         (1UL)                     /*!< TT_PFCU SR: SE_DONE_SR (Bit 1)                        */
#define TT_PFCU_SR_SE_DONE_SR_Msk         (0x2UL)                   /*!< TT_PFCU SR: SE_DONE_SR (Bitfield-Mask: 0x01)          */
#define TT_PFCU_SR_PG_DONE_SR_Pos         (0UL)                     /*!< TT_PFCU SR: PG_DONE_SR (Bit 0)                        */
#define TT_PFCU_SR_PG_DONE_SR_Msk         (0x1UL)                   /*!< TT_PFCU SR: PG_DONE_SR (Bitfield-Mask: 0x01)          */
/* ==========================================================  FAR  ========================================================== */
#define TT_PFCU_FAR_FAILADDRESS_Pos       (0UL)                     /*!< TT_PFCU FAR: FAILADDRESS (Bit 0)                      */
#define TT_PFCU_FAR_FAILADDRESS_Msk       (0xffffffffUL)            /*!< TT_PFCU FAR: FAILADDRESS (Bitfield-Mask: 0xffffffff)  */
/* ==========================================================  RLR  ========================================================== */
#define TT_PFCU_RLR_RD_LATENCY_Pos        (0UL)                     /*!< TT_PFCU RLR: RD_LATENCY (Bit 0)                       */
#define TT_PFCU_RLR_RD_LATENCY_Msk        (0x7UL)                   /*!< TT_PFCU RLR: RD_LATENCY (Bitfield-Mask: 0x07)         */
/* =========================================================  WEPR  ========================================================== */
/* =========================================================  WEPLR  ========================================================= */
/* =========================================================  BLPR0  ========================================================= */
#define TT_PFCU_BLPR0_SECTOR_Pos          (0UL)                     /*!< TT_PFCU BLPR0: SECTOR (Bit 0)                         */
#define TT_PFCU_BLPR0_SECTOR_Msk          (0x1ffUL)                 /*!< TT_PFCU BLPR0: SECTOR (Bitfield-Mask: 0x1ff)          */
#define TT_PFCU_BLPR0_EN_Pos              (30UL)                    /*!< TT_PFCU BLPR0: EN (Bit 30)                            */
#define TT_PFCU_BLPR0_EN_Msk              (0x40000000UL)            /*!< TT_PFCU BLPR0: EN (Bitfield-Mask: 0x01)               */
#define TT_PFCU_BLPR0_LOCK_Pos            (31UL)                    /*!< TT_PFCU BLPR0: LOCK (Bit 31)                          */
#define TT_PFCU_BLPR0_LOCK_Msk            (0x80000000UL)            /*!< TT_PFCU BLPR0: LOCK (Bitfield-Mask: 0x01)             */
/* =========================================================  BLPR1  ========================================================= */
#define TT_PFCU_BLPR1_SECTOR_Pos          (0UL)                     /*!< TT_PFCU BLPR1: SECTOR (Bit 0)                         */
#define TT_PFCU_BLPR1_SECTOR_Msk          (0x1ffUL)                 /*!< TT_PFCU BLPR1: SECTOR (Bitfield-Mask: 0x1ff)          */
#define TT_PFCU_BLPR1_EN_Pos              (30UL)                    /*!< TT_PFCU BLPR1: EN (Bit 30)                            */
#define TT_PFCU_BLPR1_EN_Msk              (0x40000000UL)            /*!< TT_PFCU BLPR1: EN (Bitfield-Mask: 0x01)               */
#define TT_PFCU_BLPR1_LOCK_Pos            (31UL)                    /*!< TT_PFCU BLPR1: LOCK (Bit 31)                          */
#define TT_PFCU_BLPR1_LOCK_Msk            (0x80000000UL)            /*!< TT_PFCU BLPR1: LOCK (Bitfield-Mask: 0x01)             */
/* =========================================================  SWAP0  ========================================================= */
#define TT_PFCU_SWAP0_SWAP_LEN_Pos        (0UL)                     /*!< TT_PFCU SWAP0: SWAP_LEN (Bit 0)                       */
#define TT_PFCU_SWAP0_SWAP_LEN_Msk        (0x3fUL)                  /*!< TT_PFCU SWAP0: SWAP_LEN (Bitfield-Mask: 0x3f)         */
#define TT_PFCU_SWAP0_WSAP_BAR0_Pos       (8UL)                     /*!< TT_PFCU SWAP0: WSAP_BAR0 (Bit 8)                      */
#define TT_PFCU_SWAP0_WSAP_BAR0_Msk       (0x7f00UL)                /*!< TT_PFCU SWAP0: WSAP_BAR0 (Bitfield-Mask: 0x7f)        */
#define TT_PFCU_SWAP0_WSAP_BAR1_Pos       (16UL)                    /*!< TT_PFCU SWAP0: WSAP_BAR1 (Bit 16)                     */
#define TT_PFCU_SWAP0_WSAP_BAR1_Msk       (0x7f0000UL)              /*!< TT_PFCU SWAP0: WSAP_BAR1 (Bitfield-Mask: 0x7f)        */
#define TT_PFCU_SWAP0_WSAP_EN_Pos         (31UL)                    /*!< TT_PFCU SWAP0: WSAP_EN (Bit 31)                       */
#define TT_PFCU_SWAP0_WSAP_EN_Msk         (0x80000000UL)            /*!< TT_PFCU SWAP0: WSAP_EN (Bitfield-Mask: 0x01)          */
/* =========================================================  SWAP1  ========================================================= */
#define TT_PFCU_SWAP1_SWAP_LEN_Pos        (0UL)                     /*!< TT_PFCU SWAP1: SWAP_LEN (Bit 0)                       */
#define TT_PFCU_SWAP1_SWAP_LEN_Msk        (0x3fUL)                  /*!< TT_PFCU SWAP1: SWAP_LEN (Bitfield-Mask: 0x3f)         */
#define TT_PFCU_SWAP1_WSAP_BAR0_Pos       (8UL)                     /*!< TT_PFCU SWAP1: WSAP_BAR0 (Bit 8)                      */
#define TT_PFCU_SWAP1_WSAP_BAR0_Msk       (0x7f00UL)                /*!< TT_PFCU SWAP1: WSAP_BAR0 (Bitfield-Mask: 0x7f)        */
#define TT_PFCU_SWAP1_WSAP_BAR1_Pos       (16UL)                    /*!< TT_PFCU SWAP1: WSAP_BAR1 (Bit 16)                     */
#define TT_PFCU_SWAP1_WSAP_BAR1_Msk       (0x7f0000UL)              /*!< TT_PFCU SWAP1: WSAP_BAR1 (Bitfield-Mask: 0x7f)        */
#define TT_PFCU_SWAP1_WSAP_EN_Pos         (31UL)                    /*!< TT_PFCU SWAP1: WSAP_EN (Bit 31)                       */
#define TT_PFCU_SWAP1_WSAP_EN_Msk         (0x80000000UL)            /*!< TT_PFCU SWAP1: WSAP_EN (Bitfield-Mask: 0x01)          */
/* =========================================================  SUPV  ========================================================== */
#define TT_PFCU_SUPV_SUPV_Pos             (0UL)                     /*!< TT_PFCU SUPV: SUPV (Bit 0)                            */
#define TT_PFCU_SUPV_SUPV_Msk             (0x1UL)                   /*!< TT_PFCU SUPV: SUPV (Bitfield-Mask: 0x01)              */
/* ========================================================  ACODER  ========================================================= */
/* =========================================================  VIDR  ========================================================== */

#ifdef __cplusplus
}
#endif

#endif  /* A8V2E_PFCU_H */
