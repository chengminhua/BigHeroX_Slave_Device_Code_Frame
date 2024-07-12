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
#ifndef A8V2_DFCU_H
#define A8V2_DFCU_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_DFCU_VENDOR_ID_H                     1541
#define A8V2_DFCU_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_DFCU_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_DFCU_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_DFCU_SW_MAJOR_VERSION_H              1
#define A8V2_DFCU_SW_MINOR_VERSION_H              1
#define A8V2_DFCU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_DFCU.h and TT_Common.h file version check */
#if (A8V2_DFCU_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_DFCU.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_DFCU_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_DFCU_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_DFCU_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_DFCU.h and TT_Common.h are different"
#endif
#if ((A8V2_DFCU_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_DFCU_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_DFCU_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_DFCU.h and TT_Common.h are different"
#endif


/* =========================================================================================================================== */
/* ================                                          TT_DFCU                                          ================ */
/* =========================================================================================================================== */


/**
  * @brief DFCU Controller Device (TT_DFCU)
  */

typedef struct {                                /*!< (@ 0x40188000) TT_DFCU Structure                                          */
  __OM  uint32_t  ACODER;                       /*!< (@ 0x00000000) Coder register                                             */
  __OM  uint32_t  KEYR;                         /*!< (@ 0x00000004) Flash Key Register                                         */
  __IOM uint32_t  CR0;                          /*!< (@ 0x00000008) Control register                                           */
  __IOM uint32_t  CR1;                          /*!< (@ 0x0000000C) Control register                                           */
  __IOM uint32_t  INTEN;                        /*!< (@ 0x00000010) Interrupt Enable Register                                  */
  __IM  uint32_t  INTSR;                        /*!< (@ 0x00000014) Interrupt Status Register                                  */
  __IOM uint32_t  SR;                           /*!< (@ 0x00000018) Status register                                            */
  __IM  uint32_t  RESERVED;
  __IM  uint32_t  FAIL_ADDRESS;                 /*!< (@ 0x00000020) Fail Address Register                                      */
  __IM  uint32_t  RESERVED1[7];
  __IOM uint32_t  RLR;                          /*!< (@ 0x00000040) Read Latency Register                                      */
  __IOM uint32_t  E2CR;                         /*!< (@ 0x00000044) E2PROM configuration register.                             */
  __IM  uint32_t  RESERVED2[2];
  __IOM uint32_t  WRPR[2];                      /*!< (@ 0x00000050) Write protection Register                                  */
  __IM  uint32_t  RESERVED3[2];
  __IOM uint32_t  WRLK[2];                      /*!< (@ 0x00000060) Write protection Lock.                                     */
  __IM  uint32_t  RESERVED4[6];
  __IOM uint32_t  SWAP;                         /*!< (@ 0x00000080) SWAP Register.                                             */
  __IM  uint32_t  RESERVED5[3];
  __IOM uint32_t  SUPV;                         /*!< (@ 0x00000090) Flash acceess mode register.                               */
  __IM  uint32_t  RESERVED6[27];
  __IOM uint32_t  VIDR;                         /*!< (@ 0x00000100) Version ID Register.                                       */
} DFCU_Type, *DFCU_MemMapPtr;                    /*!< Size = 260 (0x104)                                                        */

/** Number of instances of the EEP module. */
#define TT_EEP_INSTANCE_COUNT                       (1u)

/* EEP - Peripheral instance base addresses */
/** Peripheral EEP base address */
#define TT_EEP_BASE                              (0x01542000UL)

/** Number of instances of the FCU module. */
#define TT_DFCU_INSTANCE_COUNT                       (1u)

/* FCU - Peripheral instance base addresses */
/** Peripheral FCU base address */
#define TT_DFCU_BASE                              (0x40188000UL)

/** Peripheral FCU base pointer */
#define TT_DFCU                                   ((DFCU_Type *)TT_DFCU_BASE)

/** Array initializer of FCU peripheral base addresses */
#define TT_DFCU_BASE_ADDRS                        {TT_DFCU_BASE }

/** Array initializer of FCU peripheral base pointers */
#define TT_DFCU_BASE_PTRS                         { TT_DFCU}


#define DFLASH_BASE             0x1500000U
#define DFLASH_SIZE_128K        0x20000U
#define DFLASH_SIZE_256K        0x40000U
#define DFLASH_SIZE             DFLASH_SIZE_256K
#define DFLASH_SECTOR_SIZE      0x1000UL
#define DFLASH_NVR_ADDR         0x1540000U
#define DFLASH_NVR_SIZE         0x2000U

/* EEP */
#define EEP_RAM_ADDR            0x01542000UL
#define EEP_RAM_SIZE            0x1000UL /* 4KB */

/* =========================================================================================================================== */
/* ================                                          TT_DFCU                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  ACODER  ========================================================= */
/* =========================================================  KEYR  ========================================================== */
/* ==========================================================  CR0  ========================================================== */
#define TT_DFCU_CR0_PROGRAM_EN_Pos        (0UL)                     /*!< TT_DFCU CR0: PROGRAM_EN (Bit 0)                       */
#define TT_DFCU_CR0_PROGRAM_EN_Msk        (0x1UL)                   /*!< TT_DFCU CR0: PROGRAM_EN (Bitfield-Mask: 0x01)         */
#define TT_DFCU_CR0_SECTOR_ERASE_EN_Pos   (1UL)                     /*!< TT_DFCU CR0: SECTOR_ERASE_EN (Bit 1)                  */
#define TT_DFCU_CR0_SECTOR_ERASE_EN_Msk   (0x2UL)                   /*!< TT_DFCU CR0: SECTOR_ERASE_EN (Bitfield-Mask: 0x01)    */
#define TT_DFCU_CR0_CHIP_ERASE_EN_Pos     (2UL)                     /*!< TT_DFCU CR0: CHIP_ERASE_EN (Bit 2)                    */
#define TT_DFCU_CR0_CHIP_ERASE_EN_Msk     (0x4UL)                   /*!< TT_DFCU CR0: CHIP_ERASE_EN (Bitfield-Mask: 0x01)      */
#define TT_DFCU_CR0_PG_STAT_Pos           (3UL)                     /*!< TT_DFCU CR0: PG_STAT (Bit 3)                          */
#define TT_DFCU_CR0_PG_STAT_Msk           (0x8UL)                   /*!< TT_DFCU CR0: PG_STAT (Bitfield-Mask: 0x01)            */
#define TT_DFCU_CR0_ERASE_START_Pos       (4UL)                     /*!< TT_DFCU CR0: ERASE_START (Bit 4)                      */
#define TT_DFCU_CR0_ERASE_START_Msk       (0x10UL)                  /*!< TT_DFCU CR0: ERASE_START (Bitfield-Mask: 0x01)        */
#define TT_DFCU_CR0_ERV_START_Pos         (5UL)                     /*!< TT_DFCU CR0: ERV_START (Bit 5)                        */
#define TT_DFCU_CR0_ERV_START_Msk         (0x20UL)                  /*!< TT_DFCU CR0: ERV_START (Bitfield-Mask: 0x01)          */
#define TT_DFCU_CR0_KEY_LOCK_Pos          (6UL)                     /*!< TT_DFCU CR0: KEY_LOCK (Bit 6)                         */
#define TT_DFCU_CR0_KEY_LOCK_Msk          (0x40UL)                  /*!< TT_DFCU CR0: KEY_LOCK (Bitfield-Mask: 0x01)           */
#define TT_DFCU_CR0_SECTOR_ADDRESS_Pos    (12UL)                    /*!< TT_DFCU CR0: SECTOR_ADDRESS (Bit 12)                  */
#define TT_DFCU_CR0_SECTOR_ADDRESS_Msk    (0x1f000UL)               /*!< TT_DFCU CR0: SECTOR_ADDRESS (Bitfield-Mask: 0x1f)     */
/* ==========================================================  CR1  ========================================================== */
#define TT_DFCU_CR1_PROGRAM_EN_Pos        (0UL)                     /*!< TT_DFCU CR1: PROGRAM_EN (Bit 0)                       */
#define TT_DFCU_CR1_PROGRAM_EN_Msk        (0x1UL)                   /*!< TT_DFCU CR1: PROGRAM_EN (Bitfield-Mask: 0x01)         */
#define TT_DFCU_CR1_SECTOR_ERASE_EN_Pos   (1UL)                     /*!< TT_DFCU CR1: SECTOR_ERASE_EN (Bit 1)                  */
#define TT_DFCU_CR1_SECTOR_ERASE_EN_Msk   (0x2UL)                   /*!< TT_DFCU CR1: SECTOR_ERASE_EN (Bitfield-Mask: 0x01)    */
#define TT_DFCU_CR1_CHIP_ERASE_EN_Pos     (2UL)                     /*!< TT_DFCU CR1: CHIP_ERASE_EN (Bit 2)                    */
#define TT_DFCU_CR1_CHIP_ERASE_EN_Msk     (0x4UL)                   /*!< TT_DFCU CR1: CHIP_ERASE_EN (Bitfield-Mask: 0x01)      */
#define TT_DFCU_CR1_PG_STAT_Pos           (3UL)                     /*!< TT_DFCU CR1: PG_STAT (Bit 3)                          */
#define TT_DFCU_CR1_PG_STAT_Msk           (0x8UL)                   /*!< TT_DFCU CR1: PG_STAT (Bitfield-Mask: 0x01)            */
#define TT_DFCU_CR1_ERASE_START_Pos       (4UL)                     /*!< TT_DFCU CR1: ERASE_START (Bit 4)                      */
#define TT_DFCU_CR1_ERASE_START_Msk       (0x10UL)                  /*!< TT_DFCU CR1: ERASE_START (Bitfield-Mask: 0x01)        */
#define TT_DFCU_CR1_ERV_START_Pos         (5UL)                     /*!< TT_DFCU CR1: ERV_START (Bit 5)                        */
#define TT_DFCU_CR1_ERV_START_Msk         (0x20UL)                  /*!< TT_DFCU CR1: ERV_START (Bitfield-Mask: 0x01)          */
#define TT_DFCU_CR1_SECTOR_ADDRESS_Pos    (12UL)                    /*!< TT_DFCU CR1: SECTOR_ADDRESS (Bit 12)                  */
#define TT_DFCU_CR1_SECTOR_ADDRESS_Msk    (0x3f000UL)               /*!< TT_DFCU CR1: SECTOR_ADDRESS (Bitfield-Mask: 0x3f)     */
/* =========================================================  INTEN  ========================================================= */
#define TT_DFCU_INTEN_PGL_DONE_INTEN_Pos  (0UL)                     /*!< TT_DFCU INTEN: PGL_DONE_INTEN (Bit 0)                 */
#define TT_DFCU_INTEN_PGL_DONE_INTEN_Msk  (0x1UL)                   /*!< TT_DFCU INTEN: PGL_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_PGH_DONE_INTEN_Pos  (1UL)                     /*!< TT_DFCU INTEN: PGH_DONE_INTEN (Bit 1)                 */
#define TT_DFCU_INTEN_PGH_DONE_INTEN_Msk  (0x2UL)                   /*!< TT_DFCU INTEN: PGH_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_SEL_DONE_INTEN_Pos  (2UL)                     /*!< TT_DFCU INTEN: SEL_DONE_INTEN (Bit 2)                 */
#define TT_DFCU_INTEN_SEL_DONE_INTEN_Msk  (0x4UL)                   /*!< TT_DFCU INTEN: SEL_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_SEH_DONE_INTEN_Pos  (3UL)                     /*!< TT_DFCU INTEN: SEH_DONE_INTEN (Bit 3)                 */
#define TT_DFCU_INTEN_SEH_DONE_INTEN_Msk  (0x8UL)                   /*!< TT_DFCU INTEN: SEH_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_CEL_DONE_INTEN_Pos  (4UL)                     /*!< TT_DFCU INTEN: CEL_DONE_INTEN (Bit 4)                 */
#define TT_DFCU_INTEN_CEL_DONE_INTEN_Msk  (0x10UL)                  /*!< TT_DFCU INTEN: CEL_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_CEH_DONE_INTEN_Pos  (5UL)                     /*!< TT_DFCU INTEN: CEH_DONE_INTEN (Bit 5)                 */
#define TT_DFCU_INTEN_CEH_DONE_INTEN_Msk  (0x20UL)                  /*!< TT_DFCU INTEN: CEH_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_EVL_DONE_INTEN_Pos  (6UL)                     /*!< TT_DFCU INTEN: EVL_DONE_INTEN (Bit 6)                 */
#define TT_DFCU_INTEN_EVL_DONE_INTEN_Msk  (0x40UL)                  /*!< TT_DFCU INTEN: EVL_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_EVH_DONE_INTEN_Pos  (7UL)                     /*!< TT_DFCU INTEN: EVH_DONE_INTEN (Bit 7)                 */
#define TT_DFCU_INTEN_EVH_DONE_INTEN_Msk  (0x80UL)                  /*!< TT_DFCU INTEN: EVH_DONE_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_PGL_ERR_INTEN_Pos   (8UL)                     /*!< TT_DFCU INTEN: PGL_ERR_INTEN (Bit 8)                  */
#define TT_DFCU_INTEN_PGL_ERR_INTEN_Msk   (0x100UL)                 /*!< TT_DFCU INTEN: PGL_ERR_INTEN (Bitfield-Mask: 0x01)    */
#define TT_DFCU_INTEN_PGH_ERR_INTEN_Pos   (9UL)                     /*!< TT_DFCU INTEN: PGH_ERR_INTEN (Bit 9)                  */
#define TT_DFCU_INTEN_PGH_ERR_INTEN_Msk   (0x200UL)                 /*!< TT_DFCU INTEN: PGH_ERR_INTEN (Bitfield-Mask: 0x01)    */
#define TT_DFCU_INTEN_PGL_TOUT_INTEN_Pos  (10UL)                    /*!< TT_DFCU INTEN: PGL_TOUT_INTEN (Bit 10)                */
#define TT_DFCU_INTEN_PGL_TOUT_INTEN_Msk  (0x400UL)                 /*!< TT_DFCU INTEN: PGL_TOUT_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_PGH_TOUT_INTEN_Pos  (11UL)                    /*!< TT_DFCU INTEN: PGH_TOUT_INTEN (Bit 11)                */
#define TT_DFCU_INTEN_PGH_TOUT_INTEN_Msk  (0x800UL)                 /*!< TT_DFCU INTEN: PGH_TOUT_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_WRPRTERRL_INTEN_Pos (12UL)                    /*!< TT_DFCU INTEN: WRPRTERRL_INTEN (Bit 12)               */
#define TT_DFCU_INTEN_WRPRTERRL_INTEN_Msk (0x1000UL)                /*!< TT_DFCU INTEN: WRPRTERRL_INTEN (Bitfield-Mask: 0x01)  */
#define TT_DFCU_INTEN_WRPRTERRH_INTEN_Pos (13UL)                    /*!< TT_DFCU INTEN: WRPRTERRH_INTEN (Bit 13)               */
#define TT_DFCU_INTEN_WRPRTERRH_INTEN_Msk (0x2000UL)                /*!< TT_DFCU INTEN: WRPRTERRH_INTEN (Bitfield-Mask: 0x01)  */
#define TT_DFCU_INTEN_RD_INVD_INTEN_Pos   (14UL)                    /*!< TT_DFCU INTEN: RD_INVD_INTEN (Bit 14)                 */
#define TT_DFCU_INTEN_RD_INVD_INTEN_Msk   (0x4000UL)                /*!< TT_DFCU INTEN: RD_INVD_INTEN (Bitfield-Mask: 0x01)    */
#define TT_DFCU_INTEN_KEY_ERR_INTEN_Pos   (15UL)                    /*!< TT_DFCU INTEN: KEY_ERR_INTEN (Bit 15)                 */
#define TT_DFCU_INTEN_KEY_ERR_INTEN_Msk   (0x8000UL)                /*!< TT_DFCU INTEN: KEY_ERR_INTEN (Bitfield-Mask: 0x01)    */
#define TT_DFCU_INTEN_CODE_ERR_INTEN_Pos  (16UL)                    /*!< TT_DFCU INTEN: CODE_ERR_INTEN (Bit 16)                */
#define TT_DFCU_INTEN_CODE_ERR_INTEN_Msk  (0x10000UL)               /*!< TT_DFCU INTEN: CODE_ERR_INTEN (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTEN_E2_WR_ERR_INTEN_Pos (17UL)                    /*!< TT_DFCU INTEN: E2_WR_ERR_INTEN (Bit 17)               */
#define TT_DFCU_INTEN_E2_WR_ERR_INTEN_Msk (0x20000UL)               /*!< TT_DFCU INTEN: E2_WR_ERR_INTEN (Bitfield-Mask: 0x01)  */
#define TT_DFCU_INTEN_E2_WREADY_INTEN_Pos (18UL)                    /*!< TT_DFCU INTEN: E2_WREADY_INTEN (Bit 18)               */
#define TT_DFCU_INTEN_E2_WREADY_INTEN_Msk (0x40000UL)               /*!< TT_DFCU INTEN: E2_WREADY_INTEN (Bitfield-Mask: 0x01)  */
/* =========================================================  INTSR  ========================================================= */
#define TT_DFCU_INTSR_PGL_DONE_INTSR_Pos  (0UL)                     /*!< TT_DFCU INTSR: PGL_DONE_INTSR (Bit 0)                 */
#define TT_DFCU_INTSR_PGL_DONE_INTSR_Msk  (0x1UL)                   /*!< TT_DFCU INTSR: PGL_DONE_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_PGH_DONE_INTSR_Pos  (1UL)                     /*!< TT_DFCU INTSR: PGH_DONE_INTSR (Bit 1)                 */
#define TT_DFCU_INTSR_PGH_DONE_INTSR_Msk  (0x2UL)                   /*!< TT_DFCU INTSR: PGH_DONE_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_SEL_DONE_INTSR_Pos  (2UL)                     /*!< TT_DFCU INTSR: SEL_DONE_INTSR (Bit 2)                 */
#define TT_DFCU_INTSR_SEL_DONE_INTSR_Msk  (0x4UL)                   /*!< TT_DFCU INTSR: SEL_DONE_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_SEH_DONE_INTSR_Pos  (3UL)                     /*!< TT_DFCU INTSR: SEH_DONE_INTSR (Bit 3)                 */
#define TT_DFCU_INTSR_SEH_DONE_INTSR_Msk  (0x8UL)                   /*!< TT_DFCU INTSR: SEH_DONE_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_CEL_DONE_INTSR_Pos  (4UL)                     /*!< TT_DFCU INTSR: CEL_DONE_INTSR (Bit 4)                 */
#define TT_DFCU_INTSR_CEL_DONE_INTSR_Msk  (0x10UL)                  /*!< TT_DFCU INTSR: CEL_DONE_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_CEH_DONE_INTSR_Pos  (5UL)                     /*!< TT_DFCU INTSR: CEH_DONE_INTSR (Bit 5)                 */
#define TT_DFCU_INTSR_CEH_DONE_INTSR_Msk  (0x20UL)                  /*!< TT_DFCU INTSR: CEH_DONE_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_EVL_DONE_INTSR_Pos  (6UL)                     /*!< TT_DFCU INTSR: EVL_DONE_INTSR (Bit 6)                 */
#define TT_DFCU_INTSR_EVL_DONE_INTSR_Msk  (0x40UL)                  /*!< TT_DFCU INTSR: EVL_DONE_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_EVH_DONE_INTSR_Pos  (7UL)                     /*!< TT_DFCU INTSR: EVH_DONE_INTSR (Bit 7)                 */
#define TT_DFCU_INTSR_EVH_DONE_INTSR_Msk  (0x80UL)                  /*!< TT_DFCU INTSR: EVH_DONE_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_PGL_ERR_INTSR_Pos   (8UL)                     /*!< TT_DFCU INTSR: PGL_ERR_INTSR (Bit 8)                  */
#define TT_DFCU_INTSR_PGL_ERR_INTSR_Msk   (0x100UL)                 /*!< TT_DFCU INTSR: PGL_ERR_INTSR (Bitfield-Mask: 0x01)    */
#define TT_DFCU_INTSR_PGH_ERR_INTSR_Pos   (9UL)                     /*!< TT_DFCU INTSR: PGH_ERR_INTSR (Bit 9)                  */
#define TT_DFCU_INTSR_PGH_ERR_INTSR_Msk   (0x200UL)                 /*!< TT_DFCU INTSR: PGH_ERR_INTSR (Bitfield-Mask: 0x01)    */
#define TT_DFCU_INTSR_PGL_TOUT_INTSR_Pos  (10UL)                    /*!< TT_DFCU INTSR: PGL_TOUT_INTSR (Bit 10)                */
#define TT_DFCU_INTSR_PGL_TOUT_INTSR_Msk  (0x400UL)                 /*!< TT_DFCU INTSR: PGL_TOUT_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_PGH_TOUT_INTSR_Pos  (11UL)                    /*!< TT_DFCU INTSR: PGH_TOUT_INTSR (Bit 11)                */
#define TT_DFCU_INTSR_PGH_TOUT_INTSR_Msk  (0x800UL)                 /*!< TT_DFCU INTSR: PGH_TOUT_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_WRPRTERRL_INTSR_Pos (12UL)                    /*!< TT_DFCU INTSR: WRPRTERRL_INTSR (Bit 12)               */
#define TT_DFCU_INTSR_WRPRTERRL_INTSR_Msk (0x1000UL)                /*!< TT_DFCU INTSR: WRPRTERRL_INTSR (Bitfield-Mask: 0x01)  */
#define TT_DFCU_INTSR_WRPRTERRH_INTSR_Pos (13UL)                    /*!< TT_DFCU INTSR: WRPRTERRH_INTSR (Bit 13)               */
#define TT_DFCU_INTSR_WRPRTERRH_INTSR_Msk (0x2000UL)                /*!< TT_DFCU INTSR: WRPRTERRH_INTSR (Bitfield-Mask: 0x01)  */
#define TT_DFCU_INTSR_RD_INVD_INTSR_Pos   (14UL)                    /*!< TT_DFCU INTSR: RD_INVD_INTSR (Bit 14)                 */
#define TT_DFCU_INTSR_RD_INVD_INTSR_Msk   (0x4000UL)                /*!< TT_DFCU INTSR: RD_INVD_INTSR (Bitfield-Mask: 0x01)    */
#define TT_DFCU_INTSR_KEY_ERR_INTSR_Pos   (15UL)                    /*!< TT_DFCU INTSR: KEY_ERR_INTSR (Bit 15)                 */
#define TT_DFCU_INTSR_KEY_ERR_INTSR_Msk   (0x8000UL)                /*!< TT_DFCU INTSR: KEY_ERR_INTSR (Bitfield-Mask: 0x01)    */
#define TT_DFCU_INTSR_CODE_ERR_INTSR_Pos  (16UL)                    /*!< TT_DFCU INTSR: CODE_ERR_INTSR (Bit 16)                */
#define TT_DFCU_INTSR_CODE_ERR_INTSR_Msk  (0x10000UL)               /*!< TT_DFCU INTSR: CODE_ERR_INTSR (Bitfield-Mask: 0x01)   */
#define TT_DFCU_INTSR_E2_WR_ERR_INTSR_Pos (17UL)                    /*!< TT_DFCU INTSR: E2_WR_ERR_INTSR (Bit 17)               */
#define TT_DFCU_INTSR_E2_WR_ERR_INTSR_Msk (0x20000UL)               /*!< TT_DFCU INTSR: E2_WR_ERR_INTSR (Bitfield-Mask: 0x01)  */
#define TT_DFCU_INTSR_E2_WREADY_INTSR_Pos (18UL)                    /*!< TT_DFCU INTSR: E2_WREADY_INTSR (Bit 18)               */
#define TT_DFCU_INTSR_E2_WREADY_INTSR_Msk (0x40000UL)               /*!< TT_DFCU INTSR: E2_WREADY_INTSR (Bitfield-Mask: 0x01)  */
/* ==========================================================  SR  =========================================================== */
#define TT_DFCU_SR_SIZE_Pos               (26UL)                    /*!< TT_DFCU SR: SIZE (Bit 26)                             */
#define TT_DFCU_SR_SIZE_Msk               (0x4000000UL)             /*!< TT_DFCU SR: SIZE (Bitfield-Mask: 0x01)                */
#define TT_DFCU_SR_BUSY_Pos               (25UL)                    /*!< TT_DFCU SR: BUSY (Bit 25)                             */
#define TT_DFCU_SR_BUSY_Msk               (0x2000000UL)             /*!< TT_DFCU SR: BUSY (Bitfield-Mask: 0x01)                */
#define TT_DFCU_SR_NVR_WR_ALLOW_Pos       (24UL)                    /*!< TT_DFCU SR: NVR_WR_ALLOW (Bit 24)                     */
#define TT_DFCU_SR_NVR_WR_ALLOW_Msk       (0x1000000UL)             /*!< TT_DFCU SR: NVR_WR_ALLOW (Bitfield-Mask: 0x01)        */
#define TT_DFCU_SR_MAIN_WR_ALLOW_Pos      (23UL)                    /*!< TT_DFCU SR: MAIN_WR_ALLOW (Bit 23)                    */
#define TT_DFCU_SR_MAIN_WR_ALLOW_Msk      (0x800000UL)              /*!< TT_DFCU SR: MAIN_WR_ALLOW (Bitfield-Mask: 0x01)       */
#define TT_DFCU_SR_HWI_DOWN_Pos           (22UL)                    /*!< TT_DFCU SR: HWI_DOWN (Bit 22)                         */
#define TT_DFCU_SR_HWI_DOWN_Msk           (0x400000UL)              /*!< TT_DFCU SR: HWI_DOWN (Bitfield-Mask: 0x01)            */
#define TT_DFCU_SR_PGH_ACK_SR_Pos         (21UL)                    /*!< TT_DFCU SR: PGH_ACK_SR (Bit 21)                       */
#define TT_DFCU_SR_PGH_ACK_SR_Msk         (0x200000UL)              /*!< TT_DFCU SR: PGH_ACK_SR (Bitfield-Mask: 0x01)          */
#define TT_DFCU_SR_PGL_ACK_SR_Pos         (20UL)                    /*!< TT_DFCU SR: PGL_ACK_SR (Bit 20)                       */
#define TT_DFCU_SR_PGL_ACK_SR_Msk         (0x100000UL)              /*!< TT_DFCU SR: PGL_ACK_SR (Bitfield-Mask: 0x01)          */
#define TT_DFCU_SR_E2_LOAD_READY_Pos      (19UL)                    /*!< TT_DFCU SR: E2_LOAD_READY (Bit 19)                    */
#define TT_DFCU_SR_E2_LOAD_READY_Msk      (0x80000UL)               /*!< TT_DFCU SR: E2_LOAD_READY (Bitfield-Mask: 0x01)       */
#define TT_DFCU_SR_E2_WREADY_Pos          (18UL)                    /*!< TT_DFCU SR: E2_WREADY (Bit 18)                        */
#define TT_DFCU_SR_E2_WREADY_Msk          (0x40000UL)               /*!< TT_DFCU SR: E2_WREADY (Bitfield-Mask: 0x01)           */
#define TT_DFCU_SR_E2_WR_ERR_Pos          (17UL)                    /*!< TT_DFCU SR: E2_WR_ERR (Bit 17)                        */
#define TT_DFCU_SR_E2_WR_ERR_Msk          (0x20000UL)               /*!< TT_DFCU SR: E2_WR_ERR (Bitfield-Mask: 0x01)           */
#define TT_DFCU_SR_CODE_ERR_SR_Pos        (16UL)                    /*!< TT_DFCU SR: CODE_ERR_SR (Bit 16)                      */
#define TT_DFCU_SR_CODE_ERR_SR_Msk        (0x10000UL)               /*!< TT_DFCU SR: CODE_ERR_SR (Bitfield-Mask: 0x01)         */
#define TT_DFCU_SR_KEY_ERR_SR_Pos         (15UL)                    /*!< TT_DFCU SR: KEY_ERR_SR (Bit 15)                       */
#define TT_DFCU_SR_KEY_ERR_SR_Msk         (0x8000UL)                /*!< TT_DFCU SR: KEY_ERR_SR (Bitfield-Mask: 0x01)          */
#define TT_DFCU_SR_RD_INVD_SR_Pos         (14UL)                    /*!< TT_DFCU SR: RD_INVD_SR (Bit 14)                       */
#define TT_DFCU_SR_RD_INVD_SR_Msk         (0x4000UL)                /*!< TT_DFCU SR: RD_INVD_SR (Bitfield-Mask: 0x01)          */
#define TT_DFCU_SR_WRPRTERRH_SR_Pos       (13UL)                    /*!< TT_DFCU SR: WRPRTERRH_SR (Bit 13)                     */
#define TT_DFCU_SR_WRPRTERRH_SR_Msk       (0x2000UL)                /*!< TT_DFCU SR: WRPRTERRH_SR (Bitfield-Mask: 0x01)        */
#define TT_DFCU_SR_WRPRTERRL_SR_Pos       (12UL)                    /*!< TT_DFCU SR: WRPRTERRL_SR (Bit 12)                     */
#define TT_DFCU_SR_WRPRTERRL_SR_Msk       (0x1000UL)                /*!< TT_DFCU SR: WRPRTERRL_SR (Bitfield-Mask: 0x01)        */
#define TT_DFCU_SR_PGH_TOUT_SR_Pos        (11UL)                    /*!< TT_DFCU SR: PGH_TOUT_SR (Bit 11)                      */
#define TT_DFCU_SR_PGH_TOUT_SR_Msk        (0x800UL)                 /*!< TT_DFCU SR: PGH_TOUT_SR (Bitfield-Mask: 0x01)         */
#define TT_DFCU_SR_PGL_TOUT_SR_Pos        (10UL)                    /*!< TT_DFCU SR: PGL_TOUT_SR (Bit 10)                      */
#define TT_DFCU_SR_PGL_TOUT_SR_Msk        (0x400UL)                 /*!< TT_DFCU SR: PGL_TOUT_SR (Bitfield-Mask: 0x01)         */
#define TT_DFCU_SR_PGH_ERR_SR_Pos         (9UL)                     /*!< TT_DFCU SR: PGH_ERR_SR (Bit 9)                        */
#define TT_DFCU_SR_PGH_ERR_SR_Msk         (0x200UL)                 /*!< TT_DFCU SR: PGH_ERR_SR (Bitfield-Mask: 0x01)          */
#define TT_DFCU_SR_PGL_ERR_SR_Pos         (8UL)                     /*!< TT_DFCU SR: PGL_ERR_SR (Bit 8)                        */
#define TT_DFCU_SR_PGL_ERR_SR_Msk         (0x100UL)                 /*!< TT_DFCU SR: PGL_ERR_SR (Bitfield-Mask: 0x01)          */
#define TT_DFCU_SR_EVH_ERR_SR_Pos         (7UL)                     /*!< TT_DFCU SR: EVH_ERR_SR (Bit 7)                        */
#define TT_DFCU_SR_EVH_ERR_SR_Msk         (0x80UL)                  /*!< TT_DFCU SR: EVH_ERR_SR (Bitfield-Mask: 0x01)          */
#define TT_DFCU_SR_EVL_ERR_SR_Pos         (6UL)                     /*!< TT_DFCU SR: EVL_ERR_SR (Bit 6)                        */
#define TT_DFCU_SR_EVL_ERR_SR_Msk         (0x40UL)                  /*!< TT_DFCU SR: EVL_ERR_SR (Bitfield-Mask: 0x01)          */
#define TT_DFCU_SR_CEH_DONE_SR_Pos        (5UL)                     /*!< TT_DFCU SR: CEH_DONE_SR (Bit 5)                       */
#define TT_DFCU_SR_CEH_DONE_SR_Msk        (0x20UL)                  /*!< TT_DFCU SR: CEH_DONE_SR (Bitfield-Mask: 0x01)         */
#define TT_DFCU_SR_CEL_DONE_SR_Pos        (4UL)                     /*!< TT_DFCU SR: CEL_DONE_SR (Bit 4)                       */
#define TT_DFCU_SR_CEL_DONE_SR_Msk        (0x10UL)                  /*!< TT_DFCU SR: CEL_DONE_SR (Bitfield-Mask: 0x01)         */
#define TT_DFCU_SR_SEH_DONE_SR_Pos        (3UL)                     /*!< TT_DFCU SR: SEH_DONE_SR (Bit 3)                       */
#define TT_DFCU_SR_SEH_DONE_SR_Msk        (0x8UL)                   /*!< TT_DFCU SR: SEH_DONE_SR (Bitfield-Mask: 0x01)         */
#define TT_DFCU_SR_SEL_DONE_SR_Pos        (2UL)                     /*!< TT_DFCU SR: SEL_DONE_SR (Bit 2)                       */
#define TT_DFCU_SR_SEL_DONE_SR_Msk        (0x4UL)                   /*!< TT_DFCU SR: SEL_DONE_SR (Bitfield-Mask: 0x01)         */
#define TT_DFCU_SR_PGH_DONE_SR_Pos        (1UL)                     /*!< TT_DFCU SR: PGH_DONE_SR (Bit 1)                       */
#define TT_DFCU_SR_PGH_DONE_SR_Msk        (0x2UL)                   /*!< TT_DFCU SR: PGH_DONE_SR (Bitfield-Mask: 0x01)         */
#define TT_DFCU_SR_PGL_DONE_SR_Pos        (0UL)                     /*!< TT_DFCU SR: PGL_DONE_SR (Bit 0)                       */
#define TT_DFCU_SR_PGL_DONE_SR_Msk        (0x1UL)                   /*!< TT_DFCU SR: PGL_DONE_SR (Bitfield-Mask: 0x01)         */
/* =====================================================  FAIL_ADDRESS  ====================================================== */
#define TT_DFCU_FAIL_ADDRESS_FAILADDRESS_Pos (0UL)                  /*!< TT_DFCU FAIL_ADDRESS: FAILADDRESS (Bit 0)             */
#define TT_DFCU_FAIL_ADDRESS_FAILADDRESS_Msk (0xffffffffUL)         /*!< TT_DFCU FAIL_ADDRESS: FAILADDRESS (Bitfield-Mask: 0xffffffff) */
/* ==========================================================  RLR  ========================================================== */
#define TT_DFCU_RLR_RD_LATENCY_Pos        (0UL)                     /*!< TT_DFCU RLR: RD_LATENCY (Bit 0)                       */
#define TT_DFCU_RLR_RD_LATENCY_Msk        (0x7UL)                   /*!< TT_DFCU RLR: RD_LATENCY (Bitfield-Mask: 0x07)         */
/* =========================================================  E2CR  ========================================================== */
#define TT_DFCU_E2CR_E2_EN_Pos            (0UL)                     /*!< TT_DFCU E2CR: E2_EN (Bit 0)                           */
#define TT_DFCU_E2CR_E2_EN_Msk            (0x1UL)                   /*!< TT_DFCU E2CR: E2_EN (Bitfield-Mask: 0x01)             */
#define TT_DFCU_E2CR_E2_ERV_Pos           (1UL)                     /*!< TT_DFCU E2CR: E2_ERV (Bit 1)                          */
#define TT_DFCU_E2CR_E2_ERV_Msk           (0x2UL)                   /*!< TT_DFCU E2CR: E2_ERV (Bitfield-Mask: 0x01)            */
#define TT_DFCU_E2CR_E2_PGV_Pos           (2UL)                     /*!< TT_DFCU E2CR: E2_PGV (Bit 2)                          */
#define TT_DFCU_E2CR_E2_PGV_Msk           (0x4UL)                   /*!< TT_DFCU E2CR: E2_PGV (Bitfield-Mask: 0x01)            */
#define TT_DFCU_E2CR_E2_LOCK_Pos          (31UL)                    /*!< TT_DFCU E2CR: E2_LOCK (Bit 31)                        */
#define TT_DFCU_E2CR_E2_LOCK_Msk          (0x80000000UL)            /*!< TT_DFCU E2CR: E2_LOCK (Bitfield-Mask: 0x01)           */
/* =========================================================  WRPR  ========================================================== */
/* =========================================================  WRLK  ========================================================== */
/* =========================================================  SWAP  ========================================================== */
#define TT_DFCU_SWAP_LEN_Pos              (0UL)                     /*!< TT_DFCU SWAP: LEN (Bit 0)                             */
#define TT_DFCU_SWAP_LEN_Msk              (0x1fUL)                  /*!< TT_DFCU SWAP: LEN (Bitfield-Mask: 0x1f)               */
#define TT_DFCU_SWAP_BASE0_ADDRESS_Pos    (8UL)                     /*!< TT_DFCU SWAP: BASE0_ADDRESS (Bit 8)                   */
#define TT_DFCU_SWAP_BASE0_ADDRESS_Msk    (0x3f00UL)                /*!< TT_DFCU SWAP: BASE0_ADDRESS (Bitfield-Mask: 0x3f)     */
#define TT_DFCU_SWAP_BASE1_ADDRESS_Pos    (16UL)                    /*!< TT_DFCU SWAP: BASE1_ADDRESS (Bit 16)                  */
#define TT_DFCU_SWAP_BASE1_ADDRESS_Msk    (0x3f0000UL)              /*!< TT_DFCU SWAP: BASE1_ADDRESS (Bitfield-Mask: 0x3f)     */
#define TT_DFCU_SWAP_EN_Pos               (31UL)                    /*!< TT_DFCU SWAP: EN (Bit 31)                             */
#define TT_DFCU_SWAP_EN_Msk               (0x80000000UL)            /*!< TT_DFCU SWAP: EN (Bitfield-Mask: 0x01)                */
/* =========================================================  SUPV  ========================================================== */
#define TT_DFCU_SUPV_SUPV_Pos             (0UL)                     /*!< TT_DFCU SUPV: SUPV (Bit 0)                            */
#define TT_DFCU_SUPV_SUPV_Msk             (0x1UL)                   /*!< TT_DFCU SUPV: SUPV (Bitfield-Mask: 0x01)              */
/* =========================================================  VIDR  ========================================================== */

#ifdef __cplusplus
}
#endif

#endif  /* A8V2_DFCU_H */
