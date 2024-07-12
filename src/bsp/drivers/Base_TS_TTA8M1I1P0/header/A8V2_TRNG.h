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
#ifndef A8V2_TRNG_H
#define A8V2_TRNG_H


#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_TRNG_VENDOR_ID_H                     1541
#define A8V2_TRNG_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_TRNG_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_TRNG_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_TRNG_SW_MAJOR_VERSION_H              1
#define A8V2_TRNG_SW_MINOR_VERSION_H              1
#define A8V2_TRNG_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_TRNG.h and TT_Common.h file version check */
#if (A8V2_TRNG_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_TRNG.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_TRNG_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_TRNG_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_TRNG_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_TRNG.h and TT_Common.h are different"
#endif
#if ((A8V2_TRNG_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_TRNG_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_TRNG_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_TRNG.h and TT_Common.h are different"
#endif


#define TT_TRNG_BASE            0x40067000UL

#define TT_TRNG                 ((TT_TRNG_Type*)       TT_TRNG_BASE)

/**
  * @brief True Random Number Generator Device (TT_TRNG)
  */

typedef struct {                                /*!< (@ 0x40067000) TT_TRNG Structure                                      */
  __IOM uint32_t  CR;                           /*!< (@ 0x00000000) TRNG CR register                                           */
  __IOM uint32_t  INTEN;                        /*!< (@ 0x00000004) TRNG INTEN register                                        */
  __IOM uint32_t  SR;                           /*!< (@ 0x00000008) TRNG SR register                                           */
  __IOM uint32_t  ENABLE;                       /*!< (@ 0x0000000C) TRNG enable register                                       */
  __IOM uint32_t  CH0_CR;                       /*!< (@ 0x00000010) RNG_CH0_CR register                                        */
  __IOM uint32_t  CH1_CR;                       /*!< (@ 0x00000014) CH1_CR register                                            */
  __IOM uint32_t  CH2_CR;                       /*!< (@ 0x00000018) RNG_CH2_CR register                                        */
  __IOM uint32_t  CH3_CR;                       /*!< (@ 0x0000001C) RNG_CH3_CR register                                        */
  __IOM uint32_t  CONFIG;                       /*!< (@ 0x00000020) TRNG CONFIG register                                       */
  __IM  uint32_t  RESERVED[3];
  __IM  uint32_t  TRNG_DATA0;                   /*!< (@ 0x00000030) TRNG DATA0 register                                        */
  __IM  uint32_t  TRNG_DATA1;                   /*!< (@ 0x00000034) TRNG DATA1 register                                        */
  __IM  uint32_t  TRNG_DATA2;                   /*!< (@ 0x00000038) TRNG DATA2 register                                        */
  __IM  uint32_t  TRNG_DATA3;                   /*!< (@ 0x0000003C) TRNG DATA3 register                                        */
  __IOM uint32_t  PRNG_DATA0;                   /*!< (@ 0x00000040) PRNG DATA0 register                                        */
  __IOM uint32_t  PRNG_DATA1;                   /*!< (@ 0x00000044) PRNG DATA1 register                                        */
  __IOM uint32_t  PRNG_DATA2;                   /*!< (@ 0x00000048) PRNG DATA2 register                                        */
  __IOM uint32_t  PRNG_DATA3;                   /*!< (@ 0x0000004C) PRNG DATA3 register                                        */
  __IM  uint32_t  RESERVED1[2];
  __IOM uint32_t  TEST;                         /*!< (@ 0x00000058) TRNG TEST register                                         */
} TT_TRNG_Type;                             /*!< Size = 92 (0x5c)                                                          */








/* ==========================================================  CR  =========================================================== */
#define TT_TRNG_CR_CHAIN0_EN_Pos      (0UL)                     /*!< TT_TRNG CR: CHAIN0_EN (Bit 0)                     */
#define TT_TRNG_CR_CHAIN0_EN_Msk      (0x1UL)                   /*!< TT_TRNG CR: CHAIN0_EN (Bitfield-Mask: 0x01)       */
#define TT_TRNG_CR_CHAIN1_EN_Pos      (1UL)                     /*!< TT_TRNG CR: CHAIN1_EN (Bit 1)                     */
#define TT_TRNG_CR_CHAIN1_EN_Msk      (0x2UL)                   /*!< TT_TRNG CR: CHAIN1_EN (Bitfield-Mask: 0x01)       */
#define TT_TRNG_CR_CHAIN2_EN_Pos      (2UL)                     /*!< TT_TRNG CR: CHAIN2_EN (Bit 2)                     */
#define TT_TRNG_CR_CHAIN2_EN_Msk      (0x4UL)                   /*!< TT_TRNG CR: CHAIN2_EN (Bitfield-Mask: 0x01)       */
#define TT_TRNG_CR_CHAIN3_EN_Pos      (3UL)                     /*!< TT_TRNG CR: CHAIN3_EN (Bit 3)                     */
#define TT_TRNG_CR_CHAIN3_EN_Msk      (0x8UL)                   /*!< TT_TRNG CR: CHAIN3_EN (Bitfield-Mask: 0x01)       */
#define TT_TRNG_CR_DFF_SEL_Pos        (4UL)                     /*!< TT_TRNG CR: DFF_SEL (Bit 4)                       */
#define TT_TRNG_CR_DFF_SEL_Msk        (0x10UL)                  /*!< TT_TRNG CR: DFF_SEL (Bitfield-Mask: 0x01)         */
#define TT_TRNG_CR_VNC_FORCE_EN_Pos   (5UL)                     /*!< TT_TRNG CR: VNC_FORCE_EN (Bit 5)                  */
#define TT_TRNG_CR_VNC_FORCE_EN_Msk   (0x20UL)                  /*!< TT_TRNG CR: VNC_FORCE_EN (Bitfield-Mask: 0x01)    */
#define TT_TRNG_CR_VNC_CHAIN_EN_Pos   (6UL)                     /*!< TT_TRNG CR: VNC_CHAIN_EN (Bit 6)                  */
#define TT_TRNG_CR_VNC_CHAIN_EN_Msk   (0x40UL)                  /*!< TT_TRNG CR: VNC_CHAIN_EN (Bitfield-Mask: 0x01)    */
#define TT_TRNG_CR_DFF_HW_SEL_Pos     (7UL)                     /*!< TT_TRNG CR: DFF_HW_SEL (Bit 7)                    */
#define TT_TRNG_CR_DFF_HW_SEL_Msk     (0x80UL)                  /*!< TT_TRNG CR: DFF_HW_SEL (Bitfield-Mask: 0x01)      */
#define TT_TRNG_CR_DIV_Pos            (8UL)                     /*!< TT_TRNG CR: DIV (Bit 8)                           */
#define TT_TRNG_CR_DIV_Msk            (0x700UL)                 /*!< TT_TRNG CR: DIV (Bitfield-Mask: 0x07)             */
#define TT_TRNG_CR_VNC_LEVEL_Pos      (12UL)                    /*!< TT_TRNG CR: VNC_LEVEL (Bit 12)                    */
#define TT_TRNG_CR_VNC_LEVEL_Msk      (0x7000UL)                /*!< TT_TRNG CR: VNC_LEVEL (Bitfield-Mask: 0x07)       */
#define TT_TRNG_CR_PRNG_SEED_Pos      (15UL)                    /*!< TT_TRNG CR: PRNG_SEED (Bit 15)                    */
#define TT_TRNG_CR_PRNG_SEED_Msk      (0x8000UL)                /*!< TT_TRNG CR: PRNG_SEED (Bitfield-Mask: 0x01)       */
/* =========================================================  INTEN  ========================================================= */
#define TT_TRNG_INTEN_VALID_INTEN_Pos (0UL)                     /*!< TT_TRNG INTEN: VALID_INTEN (Bit 0)                */
#define TT_TRNG_INTEN_VALID_INTEN_Msk (0x1UL)                   /*!< TT_TRNG INTEN: VALID_INTEN (Bitfield-Mask: 0x01)  */
#define TT_TRNG_INTEN_AUTOCORR_ERR_INTEN_Pos (1UL)              /*!< TT_TRNG INTEN: AUTOCORR_ERR_INTEN (Bit 1)         */
#define TT_TRNG_INTEN_AUTOCORR_ERR_INTEN_Msk (0x2UL)            /*!< TT_TRNG INTEN: AUTOCORR_ERR_INTEN (Bitfield-Mask: 0x01) */
#define TT_TRNG_INTEN_CRNGT_ERR_INTEN_Pos (2UL)                 /*!< TT_TRNG INTEN: CRNGT_ERR_INTEN (Bit 2)            */
#define TT_TRNG_INTEN_CRNGT_ERR_INTEN_Msk (0x4UL)               /*!< TT_TRNG INTEN: CRNGT_ERR_INTEN (Bitfield-Mask: 0x01) */
#define TT_TRNG_INTEN_VN_ERR_INTEN_Pos (3UL)                    /*!< TT_TRNG INTEN: VN_ERR_INTEN (Bit 3)               */
#define TT_TRNG_INTEN_VN_ERR_INTEN_Msk (0x8UL)                  /*!< TT_TRNG INTEN: VN_ERR_INTEN (Bitfield-Mask: 0x01) */
#define TT_TRNG_INTEN_PRNG_VALID_INTEN_Pos (4UL)                /*!< TT_TRNG INTEN: PRNG_VALID_INTEN (Bit 4)           */
#define TT_TRNG_INTEN_PRNG_VALID_INTEN_Msk (0x10UL)             /*!< TT_TRNG INTEN: PRNG_VALID_INTEN (Bitfield-Mask: 0x01) */
/* ==========================================================  SR  =========================================================== */
#define TT_TRNG_SR_TRNG_VALID_Pos     (0UL)                     /*!< TT_TRNG SR: TRNG_VALID (Bit 0)                    */
#define TT_TRNG_SR_TRNG_VALID_Msk     (0x1UL)                   /*!< TT_TRNG SR: TRNG_VALID (Bitfield-Mask: 0x01)      */
#define TT_TRNG_SR_AUTOCORR_ERR_Pos   (1UL)                     /*!< TT_TRNG SR: AUTOCORR_ERR (Bit 1)                  */
#define TT_TRNG_SR_AUTOCORR_ERR_Msk   (0x2UL)                   /*!< TT_TRNG SR: AUTOCORR_ERR (Bitfield-Mask: 0x01)    */
#define TT_TRNG_SR_CRNGT_ERR_Pos      (2UL)                     /*!< TT_TRNG SR: CRNGT_ERR (Bit 2)                     */
#define TT_TRNG_SR_CRNGT_ERR_Msk      (0x4UL)                   /*!< TT_TRNG SR: CRNGT_ERR (Bitfield-Mask: 0x01)       */
#define TT_TRNG_SR_VN_ERR_Pos         (3UL)                     /*!< TT_TRNG SR: VN_ERR (Bit 3)                        */
#define TT_TRNG_SR_VN_ERR_Msk         (0x8UL)                   /*!< TT_TRNG SR: VN_ERR (Bitfield-Mask: 0x01)          */
#define TT_TRNG_SR_PRNG_VALID_Pos     (4UL)                     /*!< TT_TRNG SR: PRNG_VALID (Bit 4)                    */
#define TT_TRNG_SR_PRNG_VALID_Msk     (0x10UL)                  /*!< TT_TRNG SR: PRNG_VALID (Bitfield-Mask: 0x01)      */
#define TT_TRNG_SR_SRMA_KEY_POOR_Pos  (5UL)                     /*!< TT_TRNG SR: SRMA_KEY_POOR (Bit 5)                 */
#define TT_TRNG_SR_SRMA_KEY_POOR_Msk  (0x20UL)                  /*!< TT_TRNG SR: SRMA_KEY_POOR (Bitfield-Mask: 0x01)   */
/* ========================================================  ENABLE  ========================================================= */
#define TT_TRNG_ENABLE_TRNG_ENABLE_Pos (0UL)                    /*!< TT_TRNG ENABLE: TRNG_ENABLE (Bit 0)               */
#define TT_TRNG_ENABLE_TRNG_ENABLE_Msk (0x1UL)                  /*!< TT_TRNG ENABLE: TRNG_ENABLE (Bitfield-Mask: 0x01) */
#define TT_TRNG_ENABLE_PRNG_ENABLE_Pos (1UL)                    /*!< TT_TRNG ENABLE: PRNG_ENABLE (Bit 1)               */
#define TT_TRNG_ENABLE_PRNG_ENABLE_Msk (0x2UL)                  /*!< TT_TRNG ENABLE: PRNG_ENABLE (Bitfield-Mask: 0x01) */
/* ========================================================  CH0_CR  ========================================================= */
#define TT_TRNG_CH0_CR_CH0_CLK_Pos    (0UL)                     /*!< TT_TRNG CH0_CR: CH0_CLK (Bit 0)                   */
#define TT_TRNG_CH0_CR_CH0_CLK_Msk    (0x3UL)                   /*!< TT_TRNG CH0_CR: CH0_CLK (Bitfield-Mask: 0x03)     */
#define TT_TRNG_CH0_CR_LOCK_Pos       (31UL)                    /*!< TT_TRNG CH0_CR: LOCK (Bit 31)                     */
#define TT_TRNG_CH0_CR_LOCK_Msk       (0x80000000UL)            /*!< TT_TRNG CH0_CR: LOCK (Bitfield-Mask: 0x01)        */
/* ========================================================  CH1_CR  ========================================================= */
#define TT_TRNG_CH1_CR_CH1_CLK_Pos    (0UL)                     /*!< TT_TRNG CH1_CR: CH1_CLK (Bit 0)                   */
#define TT_TRNG_CH1_CR_CH1_CLK_Msk    (0x3UL)                   /*!< TT_TRNG CH1_CR: CH1_CLK (Bitfield-Mask: 0x03)     */
#define TT_TRNG_CH1_CR_LOCK_Pos       (31UL)                    /*!< TT_TRNG CH1_CR: LOCK (Bit 31)                     */
#define TT_TRNG_CH1_CR_LOCK_Msk       (0x80000000UL)            /*!< TT_TRNG CH1_CR: LOCK (Bitfield-Mask: 0x01)        */
/* ========================================================  CH2_CR  ========================================================= */
#define TT_TRNG_CH2_CR_CH2_CLK_Pos    (0UL)                     /*!< TT_TRNG CH2_CR: CH2_CLK (Bit 0)                   */
#define TT_TRNG_CH2_CR_CH2_CLK_Msk    (0x3UL)                   /*!< TT_TRNG CH2_CR: CH2_CLK (Bitfield-Mask: 0x03)     */
#define TT_TRNG_CH2_CR_LOCK_Pos       (31UL)                    /*!< TT_TRNG CH2_CR: LOCK (Bit 31)                     */
#define TT_TRNG_CH2_CR_LOCK_Msk       (0x80000000UL)            /*!< TT_TRNG CH2_CR: LOCK (Bitfield-Mask: 0x01)        */
/* ========================================================  CH3_CR  ========================================================= */
#define TT_TRNG_CH3_CR_CH3_CLK_Pos    (0UL)                     /*!< TT_TRNG CH3_CR: CH3_CLK (Bit 0)                   */
#define TT_TRNG_CH3_CR_CH3_CLK_Msk    (0x3UL)                   /*!< TT_TRNG CH3_CR: CH3_CLK (Bitfield-Mask: 0x03)     */
#define TT_TRNG_CH3_CR_LOCK_Pos       (31UL)                    /*!< TT_TRNG CH3_CR: LOCK (Bit 31)                     */
#define TT_TRNG_CH3_CR_LOCK_Msk       (0x80000000UL)            /*!< TT_TRNG CH3_CR: LOCK (Bitfield-Mask: 0x01)        */
/* ========================================================  CONFIG  ========================================================= */
#define TT_TRNG_CONFIG_FNYM_EN_Pos    (0UL)                     /*!< TT_TRNG CONFIG: FNYM_EN (Bit 0)                   */
#define TT_TRNG_CONFIG_FNYM_EN_Msk    (0x1UL)                   /*!< TT_TRNG CONFIG: FNYM_EN (Bitfield-Mask: 0x01)     */
#define TT_TRNG_CONFIG_LFSR_EN_Pos    (1UL)                     /*!< TT_TRNG CONFIG: LFSR_EN (Bit 1)                   */
#define TT_TRNG_CONFIG_LFSR_EN_Msk    (0x2UL)                   /*!< TT_TRNG CONFIG: LFSR_EN (Bitfield-Mask: 0x01)     */
#define TT_TRNG_CONFIG_SM4_EN_Pos     (2UL)                     /*!< TT_TRNG CONFIG: SM4_EN (Bit 2)                    */
#define TT_TRNG_CONFIG_SM4_EN_Msk     (0x4UL)                   /*!< TT_TRNG CONFIG: SM4_EN (Bitfield-Mask: 0x01)      */
#define TT_TRNG_CONFIG_VNC_EN_Pos     (4UL)                     /*!< TT_TRNG CONFIG: VNC_EN (Bit 4)                    */
#define TT_TRNG_CONFIG_VNC_EN_Msk     (0x10UL)                  /*!< TT_TRNG CONFIG: VNC_EN (Bitfield-Mask: 0x01)      */
#define TT_TRNG_CONFIG_CRNGT_EN_Pos   (5UL)                     /*!< TT_TRNG CONFIG: CRNGT_EN (Bit 5)                  */
#define TT_TRNG_CONFIG_CRNGT_EN_Msk   (0x20UL)                  /*!< TT_TRNG CONFIG: CRNGT_EN (Bitfield-Mask: 0x01)    */
#define TT_TRNG_CONFIG_CORR_EN_Pos    (6UL)                     /*!< TT_TRNG CONFIG: CORR_EN (Bit 6)                   */
#define TT_TRNG_CONFIG_CORR_EN_Msk    (0x40UL)                  /*!< TT_TRNG CONFIG: CORR_EN (Bitfield-Mask: 0x01)     */
#define TT_TRNG_CONFIG_CORR_LEV_Pos   (8UL)                     /*!< TT_TRNG CONFIG: CORR_LEV (Bit 8)                  */
#define TT_TRNG_CONFIG_CORR_LEV_Msk   (0x300UL)                 /*!< TT_TRNG CONFIG: CORR_LEV (Bitfield-Mask: 0x03)    */
#define TT_TRNG_CONFIG_CORR_CNT_Pos   (10UL)                    /*!< TT_TRNG CONFIG: CORR_CNT (Bit 10)                 */
#define TT_TRNG_CONFIG_CORR_CNT_Msk   (0xc00UL)                 /*!< TT_TRNG CONFIG: CORR_CNT (Bitfield-Mask: 0x03)    */
#define TT_TRNG_CONFIG_SAMP_CNT_Pos   (16UL)                    /*!< TT_TRNG CONFIG: SAMP_CNT (Bit 16)                 */
#define TT_TRNG_CONFIG_SAMP_CNT_Msk   (0xff0000UL)              /*!< TT_TRNG CONFIG: SAMP_CNT (Bitfield-Mask: 0xff)    */
#define TT_TRNG_CONFIG_LOCK_Pos       (31UL)                    /*!< TT_TRNG CONFIG: LOCK (Bit 31)                     */
#define TT_TRNG_CONFIG_LOCK_Msk       (0x80000000UL)            /*!< TT_TRNG CONFIG: LOCK (Bitfield-Mask: 0x01)        */
/* ======================================================  TRNG_DATA0  ======================================================= */
#define TT_TRNG_TRNG_DATA0_ERH_DATA_Pos (0UL)                   /*!< TT_TRNG TRNG_DATA0: ERH_DATA (Bit 0)              */
#define TT_TRNG_TRNG_DATA0_ERH_DATA_Msk (0xffffffffUL)          /*!< TT_TRNG TRNG_DATA0: ERH_DATA (Bitfield-Mask: 0xffffffff) */
/* ======================================================  TRNG_DATA1  ======================================================= */
#define TT_TRNG_TRNG_DATA1_ERH_DATA_Pos (0UL)                   /*!< TT_TRNG TRNG_DATA1: ERH_DATA (Bit 0)              */
#define TT_TRNG_TRNG_DATA1_ERH_DATA_Msk (0xffffffffUL)          /*!< TT_TRNG TRNG_DATA1: ERH_DATA (Bitfield-Mask: 0xffffffff) */
/* ======================================================  TRNG_DATA2  ======================================================= */
#define TT_TRNG_TRNG_DATA2_ERH_DATA_Pos (0UL)                   /*!< TT_TRNG TRNG_DATA2: ERH_DATA (Bit 0)              */
#define TT_TRNG_TRNG_DATA2_ERH_DATA_Msk (0xffffffffUL)          /*!< TT_TRNG TRNG_DATA2: ERH_DATA (Bitfield-Mask: 0xffffffff) */
/* ======================================================  TRNG_DATA3  ======================================================= */
#define TT_TRNG_TRNG_DATA3_ERH_DATA_Pos (0UL)                   /*!< TT_TRNG TRNG_DATA3: ERH_DATA (Bit 0)              */
#define TT_TRNG_TRNG_DATA3_ERH_DATA_Msk (0xffffffffUL)          /*!< TT_TRNG TRNG_DATA3: ERH_DATA (Bitfield-Mask: 0xffffffff) */
/* ======================================================  PRNG_DATA0  ======================================================= */
#define TT_TRNG_PRNG_DATA0_ERH_DATA_Pos (0UL)                   /*!< TT_TRNG PRNG_DATA0: ERH_DATA (Bit 0)              */
#define TT_TRNG_PRNG_DATA0_ERH_DATA_Msk (0xffffffffUL)          /*!< TT_TRNG PRNG_DATA0: ERH_DATA (Bitfield-Mask: 0xffffffff) */
/* ======================================================  PRNG_DATA1  ======================================================= */
#define TT_TRNG_PRNG_DATA1_ERH_DATA_Pos (0UL)                   /*!< TT_TRNG PRNG_DATA1: ERH_DATA (Bit 0)              */
#define TT_TRNG_PRNG_DATA1_ERH_DATA_Msk (0xffffffffUL)          /*!< TT_TRNG PRNG_DATA1: ERH_DATA (Bitfield-Mask: 0xffffffff) */
/* ======================================================  PRNG_DATA2  ======================================================= */
#define TT_TRNG_PRNG_DATA2_ERH_DATA_Pos (0UL)                   /*!< TT_TRNG PRNG_DATA2: ERH_DATA (Bit 0)              */
#define TT_TRNG_PRNG_DATA2_ERH_DATA_Msk (0xffffffffUL)          /*!< TT_TRNG PRNG_DATA2: ERH_DATA (Bitfield-Mask: 0xffffffff) */
/* ======================================================  PRNG_DATA3  ======================================================= */
#define TT_TRNG_PRNG_DATA3_ERH_DATA_Pos (0UL)                   /*!< TT_TRNG PRNG_DATA3: ERH_DATA (Bit 0)              */
#define TT_TRNG_PRNG_DATA3_ERH_DATA_Msk (0xffffffffUL)          /*!< TT_TRNG PRNG_DATA3: ERH_DATA (Bitfield-Mask: 0xffffffff) */
/* =========================================================  TEST  ========================================================== */
#define TT_TRNG_TEST_TEST_EN_Pos      (0UL)                     /*!< TT_TRNG TEST: TEST_EN (Bit 0)                     */
#define TT_TRNG_TEST_TEST_EN_Msk      (0x1UL)                   /*!< TT_TRNG TEST: TEST_EN (Bitfield-Mask: 0x01)       */
#define TT_TRNG_TEST_TEST_SEL_Pos     (1UL)                     /*!< TT_TRNG TEST: TEST_SEL (Bit 1)                    */
#define TT_TRNG_TEST_TEST_SEL_Msk     (0xeUL)                   /*!< TT_TRNG TEST: TEST_SEL (Bitfield-Mask: 0x07)      */

#ifdef __cplusplus
}
#endif

#endif  /* end of A8V2_TRNG_H */
