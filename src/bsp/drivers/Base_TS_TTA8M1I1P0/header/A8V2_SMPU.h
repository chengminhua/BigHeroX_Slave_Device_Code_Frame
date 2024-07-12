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
#ifndef A8V2_SMPU_H
#define A8V2_SMPU_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_SMPU_VENDOR_ID_H                     1541
#define A8V2_SMPU_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_SMPU_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_SMPU_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_SMPU_SW_MAJOR_VERSION_H              1
#define A8V2_SMPU_SW_MINOR_VERSION_H              1
#define A8V2_SMPU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_SMPU.h and TT_Common.h file version check */
#if (A8V2_SMPU_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_SMPU.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_SMPU_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_SMPU_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_SMPU_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_SMPU.h and TT_Common.h are different"
#endif
#if ((A8V2_SMPU_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_SMPU_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_SMPU_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_SMPU.h and TT_Common.h are different"
#endif


 
/**
  * @brief Inter-Integrated Circuit Bus 0 (TT_SMPU)
  */

/**
  * @brief TT_SMPU_PORT_ERROR [PORT_ERROR] (Port error information.)
  */
typedef struct {
  __IM  uint32  EAR;                          /*!< (@ 0x00000000) Error Address Register.                                    */
  
  union {
    __IM  uint32 reg;                         /*!< (@ 0x00000004) Error Detail Register.                                     */
    
    struct {
      __IM  uint32 HWRITE     : 1;            /*!< [0..0] HWRITE Signal Error.                                               */
      __IM  uint32 HPROT      : 2;            /*!< [2..1] HPROT Signal Error.                                                */
      __IM  uint32            : 1;
      __IM  uint32 HMASTER    : 4;            /*!< [7..4] HMASTER Signal Error.                                              */
    } bit;
  } EDR;
} TT_SMPU_PORT_ERROR_Type;                  /*!< Size = 8 (0x8)                                                            */


/**
  * @brief TT_SMPU_MEM_REGION [MEM_PFLASH_REGION] (Pflash region.)
  */
typedef struct {
  union {
    __IOM uint32 reg;                         /*!< (@ 0x00000000) Region Start Address.                                      */
    
    struct {
      __IM  uint32            : 7;
      __IOM uint32 ADDRESS    : 25;           /*!< [31..7] Start Address.                                                    */
    } bit;
  } START;
  
  union {
    __IOM uint32 reg;                         /*!< (@ 0x00000004) Region End Address.                                        */
    
    struct {
      __IM  uint32            : 7;
      __IOM uint32 ADDRESS    : 25;           /*!< [31..7] End Address.                                                      */
    } bit;
  } END;
  
  union {
    __IOM uint32 reg;                         /*!< (@ 0x00000008) Region Config.                                             */
    
    struct {
      __IOM uint32 M0_USER_WRITE : 1;         /*!< [0..0] User Write Enable.                                                 */
      __IOM uint32 M0_USER_READ : 1;          /*!< [1..1] User Read Enable.                                                  */
      __IOM uint32 M0_PRIVILEGE_WRITE : 1;    /*!< [2..2] Privilege Write Enable.                                            */
      __IOM uint32 M0_PRIVILEGE_READ : 1;     /*!< [3..3] Privilege Read Enable.                                             */
      __IOM uint32 CIPHER_DMA_USER_WRITE : 1; /*!< [4..4] User Write Enable.                                                 */
      __IOM uint32 CIPHER_DMA_USER_READ : 1;  /*!< [5..5] User Read Enable.                                                  */
      __IOM uint32 CIPHER_DMA_PRIVILEGE_WRITE : 1;/*!< [6..6] Privilege Write Enable.                                        */
      __IOM uint32 CIPHER_DMA_PRIVILEGE_READ : 1;/*!< [7..7] Privilege Read Enable.                                          */
      __IOM uint32 M7_CRC_USER_WRITE : 1;     /*!< [8..8] User Write Enable.                                                 */
      __IOM uint32 M7_CRC_USER_READ : 1;      /*!< [9..9] User Read Enable.                                                  */
      __IOM uint32 M7_CRC_PRIVILEGE_WRITE : 1;/*!< [10..10] Privilege Write Enable.                                          */
      __IOM uint32 M7_CRC_PRIVILEGE_READ : 1; /*!< [11..11] Privilege Read Enable.                                           */
      __IOM uint32 ADC_USER_WRITE : 1;        /*!< [12..12] User Write Enable.                                               */
      __IOM uint32 ADC_USER_READ : 1;         /*!< [13..13] User Read Enable.                                                */
      __IOM uint32 ADC_PRIVILEGE_WRITE : 1;   /*!< [14..14] Privilege Write Enable.                                          */
      __IOM uint32 ADC_PRIVILEGE_READ : 1;    /*!< [15..15] Privilege Read Enable.                                           */
      __IOM uint32 DMAC_USER_WRITE : 1;       /*!< [16..16] User Write Enable.                                               */
      __IOM uint32 DMAC_USER_READ : 1;        /*!< [17..17] User Read Enable.                                                */
      __IOM uint32 DMAC_PRIVILEGE_WRITE : 1;  /*!< [18..18] Privilege Write Enable.                                          */
      __IOM uint32 DMAC_PRIVILEGE_READ : 1;   /*!< [19..19] Privilege Read Enable.                                           */
      __IOM uint32 AXIBUSIC_USER_WRITE : 1;   /*!< [20..20] User Write Enable.                                               */
      __IOM uint32 AXIBUSIC_USER_READ : 1;    /*!< [21..21] User Read Enable.                                                */
      __IOM uint32 AXIBUSIC_PRIVILEGE_WRITE : 1;/*!< [22..22] Privilege Write Enable.                                        */
      __IOM uint32 AXIBUSIC_PRIVILEGE_READ : 1;/*!< [23..23] Privilege Read Enable.                                          */
      __IOM uint32 GTM_USER_WRITE : 1;        /*!< [24..24] User Write Enable.                                               */
      __IOM uint32 GTM_USER_READ : 1;         /*!< [25..25] User Read Enable.                                                */
      __IOM uint32 GTM_PRIVILEGE_WRITE : 1;   /*!< [26..26] Privilege Write Enable.                                          */
      __IOM uint32 GTM_PRIVILEGE_READ : 1;    /*!< [27..27] Privilege Read Enable.                                           */
    } bit;
  } RIGHTS_CONFIG_0;
  
  union {
    __IOM uint32 reg;                         /*!< (@ 0x0000000C) Region Control.                                            */
    
    struct {
      __IOM uint32 VALID      : 1;            /*!< [0..0] Region Valid.                                                      */
      __IM  uint32            : 3;
      __IOM uint32 LOCK       : 1;            /*!< [4..4] Region Lock.                                                       */
    } bit;
  } CONTROL;
  
  union {
    __IOM uint32 reg;                         /*!< (@ 0x00000010) Region Config.                                             */
    
    struct {
      __IOM uint32 M7_USER_WRITE : 1;         /*!< [0..0] User Write Enable.                                                 */
      __IOM uint32 M7_USER_READ : 1;          /*!< [1..1] User Read Enable.                                                  */
      __IOM uint32 M7_USER_EXECUTE : 1;       /*!< [2..2] User execute Enable.                                               */
      __IM  uint32            : 1;
      __IOM uint32 M7_PRIVILEGE_WRITE : 1;    /*!< [4..4] Privilege Write Enable.                                            */
      __IOM uint32 M0_PRIVILEGE_READ : 1;     /*!< [5..5] Privilege Read Enable.                                             */
      __IOM uint32 M7_PRIVILEGE_EXECUTE : 1;  /*!< [6..6] Privilege execute Enable.                                          */
      __IM  uint32            : 1;
      __IOM uint32 QSPI0_USER_WRITE : 1;      /*!< [8..8] User Write Enable.                                                 */
      __IOM uint32 QSPI0_USER_READ : 1;       /*!< [9..9] User Read Enable.                                                  */
      __IOM uint32 QSPI0_PRIVILEGE_WRITE : 1; /*!< [10..10] Privilege Write Enable.                                          */
      __IOM uint32 QSPI0_PRIVILEGE_READ : 1;  /*!< [11..11] Privilege Read Enable.                                           */
      __IOM uint32 ETH_USER_WRITE : 1;        /*!< [12..12] User Write Enable.                                               */
      __IOM uint32 ETH_USER_READ : 1;         /*!< [13..13] User Read Enable.                                                */
      __IOM uint32 ETH_PRIVILEGE_WRITE : 1;   /*!< [14..14] Privilege Write Enable.                                          */
      __IOM uint32 ETH_PRIVILEGE_READ : 1;    /*!< [15..15] Privilege Read Enable.                                           */
      __IOM uint32 GTM1_USER_WRITE : 1;        /*!< [24..24] User Write Enable.                                               */
      __IOM uint32 GTM1_USER_READ : 1;         /*!< [25..25] User Read Enable.                                                */
      __IOM uint32 GTM1_PRIVILEGE_WRITE : 1;   /*!< [26..26] Privilege Write Enable.                                          */
      __IOM uint32 GTM1_PRIVILEGE_READ : 1;    /*!< [27..27] Privilege Read Enable.                                           */
      __IOM uint32 GTM2_USER_WRITE : 1;        /*!< [24..24] User Write Enable.                                               */
      __IOM uint32 GTM2_USER_READ : 1;         /*!< [25..25] User Read Enable.                                                */
      __IOM uint32 GTM2_PRIVILEGE_WRITE : 1;   /*!< [26..26] Privilege Write Enable.                                          */
      __IOM uint32 GTM2_PRIVILEGE_READ : 1;    /*!< [27..27] Privilege Read Enable.                                           */

    } bit;
  } RIGHTS_CONFIG_1;
  __IM  uint32  RESERVED[3];
} TT_REGION_CONFIG_Type;                     /*!< Size = 32 (0x20)                                                          */

/* =========================================================================================================================== */
/* ================                                        TT_SMPU                                        ================ */
/* =========================================================================================================================== */


/**
  * @brief SMPU Controller Device (TT_SMPU)
  */

typedef struct {                                /*!< (@ 0x400A1000) TT_SMPU Structure                                      */
  
  union {
    __IOM uint32 reg;                         /*!< (@ 0x00000000) Control/Error and Status Register                          */
    
    struct {
      __IOM uint32 AHB_TCM_ENABLE : 1;        /*!< [0..0] AHB Port 0 Enable.                                                 */
      __IOM uint32 MEM_PFLASH_ENABLE : 1;     /*!< [1..1] MEM Port 1 Enable.                                                 */
      __IOM uint32 MEM_SRAM0_ENABLE : 1;      /*!< [2..2] MEM Port 2 Enable.                                                 */
      __IOM uint32 MEM_SRAM1_ENABLE : 1;      /*!< [3..3] MEM Port 3 Enable.                                                 */
      __IOM uint32 MEM_DFLASH_ENABLE : 1;     /*!< [4..4] MEM Port 4 Enable.                                                 */
      __IM  uint32            : 7;
      __IOM uint32 SLAVE_PORT_NUM : 4;        /*!< [15..12] Number Of Slave Port.                                            */
      __IOM uint32 REVISION   : 4;            /*!< [19..16] Hardware Revision.                                               */
      __IM  uint32            : 7;
      __IOM uint32 MEM_DFLASH_ERROR : 1;      /*!< [27..27] MEM Port 4 Error.                                                */
      __IOM uint32 MEM_SRAM1_ERROR : 1;       /*!< [28..28] MEM Port 3 Error.                                                */
      __IOM uint32 MEM_SRAM0_ERROR : 1;       /*!< [29..29] MEM Port 2 Error.                                                */
      __IOM uint32 MEM_PFLASH_ERROR : 1;      /*!< [30..30] MEM Port 1 Error.                                                */
      __IOM uint32 AHB_TCM_ERROR : 1;         /*!< [31..31] AHB Port 0 Error.                                                */
    } bit;
  } CESR;
  
  union {
    __IOM uint32 reg;                         /*!< (@ 0x00000004) Port Lock Register.                                        */
    
    struct {
      __IOM uint32 AHB_TCM_LOCK : 1;          /*!< [0..0] AHB Port 0 Lock.                                                   */
      __IOM uint32 MEM_PFLASH_LOCK : 1;       /*!< [1..1] MEM Port 1 Lock.                                                   */
      __IOM uint32 MEM_SRAM0_LOCK : 1;        /*!< [2..2] MEM Port 2 Lock.                                                   */
      __IOM uint32 MEM_SRAM1_LOCK : 1;        /*!< [3..3] MEM Port 3 Lock.                                                   */
      __IOM uint32 MEM_DFLASH_LOCK : 1;       /*!< [4..4] MEM Port 4 Lock.                                                   */
    } bit;
  }PLR;
  __IM  uint32  RESERVED[2];
  __IOM TT_SMPU_PORT_ERROR_Type PORT_ERROR[5];/*!< (@ 0x00000010) Port error information.                                  */
  __IM  uint32  RESERVED1[18];
  
  union {
    __IOM uint32 reg[5];                      /*!< (@ 0x00000080) BackGround Config Register                                 */
    
    struct {
      __IOM uint32 EN         : 1;            /*!< [0..0] Enable Back Ground Region.                                         */
    } bit[5];
  } PORT_BG;
  __IM  uint32_t  RESERVED2[3];

   union {
     __IOM uint32_t reg;                         /*!< (@ 0x000000A0) Select access register                                     */

     struct {
       __IOM uint32_t EN         : 1;            /*!< [0..0] Select access mode.                                                */
     } bit;
   } SUPV;

   union {
     __IOM uint32_t reg;                         /*!< (@ 0x000000A4) M0 read control register                                   */

     struct {
       __IOM uint32_t ENABLE     : 1;            /*!< [0..0] Enable m0 read.                                                    */
     } bit;
   } M0_READ;
  __IM  uint32  RESERVED3[22];
  __IOM TT_REGION_CONFIG_Type AHB_TCM_REGION[8];/*!< (@ 0x00000100) Ahb tcm region.                                  */
  __IM  uint32  RESERVED4[384];
  __IOM TT_REGION_CONFIG_Type MEM_PFLASH_REGION[8];/*!< (@ 0x00000800) Pflash region.                             */
  __IOM TT_REGION_CONFIG_Type MEM_SRAM0_REGION[8];/*!< (@ 0x00000900) Sram region.                                 */
  __IOM TT_REGION_CONFIG_Type MEM_SRAM1_REGION[8];/*!< (@ 0x00000A00) Sram1 region.                                */
  __IOM TT_REGION_CONFIG_Type MEM_DFLASH_REGION[8];/*!< (@ 0x00000B00) Dflash region.                             */
  __IM  uint32_t  RESERVED5[255];
  __IM  uint32_t  ID_REG;                       /*!< (@ 0x00000FFC) SMPU ID Register								*/
} SMPU_Type,*SMPU_MemMapPtr;                             /*!< Size = 4096 (0x1000)                                                       */

#define TT_SMPU_BASE            0x400A1000UL
#define TT_SMPU                 ((SMPU_Type*)       TT_SMPU_BASE)


/* =========================================================================================================================== */
/* ================                                        TT_SMPU                                        ================ */
/* =========================================================================================================================== */

/* =========================================================  CESR  ========================================================== */
#define TT_SMPU_CESR_AHB_TCM_ENABLE_Pos (0UL)                   /*!< TT_SMPU CESR: AHB_TCM_ENABLE (Bit 0)              */
#define TT_SMPU_CESR_AHB_TCM_ENABLE_Msk (0x1UL)                 /*!< TT_SMPU CESR: AHB_TCM_ENABLE (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_MEM_PFLASH_ENABLE_Pos (1UL)                /*!< TT_SMPU CESR: MEM_PFLASH_ENABLE (Bit 1)           */
#define TT_SMPU_CESR_MEM_PFLASH_ENABLE_Msk (0x2UL)              /*!< TT_SMPU CESR: MEM_PFLASH_ENABLE (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_MEM_SRAM0_ENABLE_Pos (2UL)                 /*!< TT_SMPU CESR: MEM_SRAM0_ENABLE (Bit 2)            */
#define TT_SMPU_CESR_MEM_SRAM0_ENABLE_Msk (0x4UL)               /*!< TT_SMPU CESR: MEM_SRAM0_ENABLE (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_MEM_SRAM1_ENABLE_Pos (3UL)                 /*!< TT_SMPU CESR: MEM_SRAM1_ENABLE (Bit 3)            */
#define TT_SMPU_CESR_MEM_SRAM1_ENABLE_Msk (0x8UL)               /*!< TT_SMPU CESR: MEM_SRAM1_ENABLE (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_MEM_DFLASH_ENABLE_Pos (4UL)                /*!< TT_SMPU CESR: MEM_DFLASH_ENABLE (Bit 4)           */
#define TT_SMPU_CESR_MEM_DFLASH_ENABLE_Msk (0x10UL)             /*!< TT_SMPU CESR: MEM_DFLASH_ENABLE (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_SLAVE_PORT_NUM_Pos (12UL)                  /*!< TT_SMPU CESR: SLAVE_PORT_NUM (Bit 12)             */
#define TT_SMPU_CESR_SLAVE_PORT_NUM_Msk (0xf000UL)              /*!< TT_SMPU CESR: SLAVE_PORT_NUM (Bitfield-Mask: 0x0f) */
#define TT_SMPU_CESR_REVISION_Pos     (16UL)                    /*!< TT_SMPU CESR: REVISION (Bit 16)                   */
#define TT_SMPU_CESR_REVISION_Msk     (0xf0000UL)               /*!< TT_SMPU CESR: REVISION (Bitfield-Mask: 0x0f)      */
#define TT_SMPU_CESR_MEM_DFLASH_ERROR_Pos (27UL)                /*!< TT_SMPU CESR: MEM_DFLASH_ERROR (Bit 27)           */
#define TT_SMPU_CESR_MEM_DFLASH_ERROR_Msk (0x8000000UL)         /*!< TT_SMPU CESR: MEM_DFLASH_ERROR (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_MEM_SRAM1_ERROR_Pos (28UL)                 /*!< TT_SMPU CESR: MEM_SRAM1_ERROR (Bit 28)            */
#define TT_SMPU_CESR_MEM_SRAM1_ERROR_Msk (0x10000000UL)         /*!< TT_SMPU CESR: MEM_SRAM1_ERROR (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_MEM_SRAM0_ERROR_Pos (29UL)                 /*!< TT_SMPU CESR: MEM_SRAM0_ERROR (Bit 29)            */
#define TT_SMPU_CESR_MEM_SRAM0_ERROR_Msk (0x20000000UL)         /*!< TT_SMPU CESR: MEM_SRAM0_ERROR (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_MEM_PFLASH_ERROR_Pos (30UL)                /*!< TT_SMPU CESR: MEM_PFLASH_ERROR (Bit 30)           */
#define TT_SMPU_CESR_MEM_PFLASH_ERROR_Msk (0x40000000UL)        /*!< TT_SMPU CESR: MEM_PFLASH_ERROR (Bitfield-Mask: 0x01) */
#define TT_SMPU_CESR_AHB_TCM_ERROR_Pos (31UL)                   /*!< TT_SMPU CESR: AHB_TCM_ERROR (Bit 31)              */
#define TT_SMPU_CESR_AHB_TCM_ERROR_Msk (0x80000000UL)           /*!< TT_SMPU CESR: AHB_TCM_ERROR (Bitfield-Mask: 0x01) */
/* ==========================================================  PLR  ========================================================== */
#define TT_SMPU_PLR_AHB_TCM_LOCK_Pos  (0UL)                     /*!< TT_SMPU PLR: AHB_TCM_LOCK (Bit 0)                 */
#define TT_SMPU_PLR_AHB_TCM_LOCK_Msk  (0x1UL)                   /*!< TT_SMPU PLR: AHB_TCM_LOCK (Bitfield-Mask: 0x01)   */
#define TT_SMPU_PLR_MEM_PFLASH_LOCK_Pos (1UL)                   /*!< TT_SMPU PLR: MEM_PFLASH_LOCK (Bit 1)              */
#define TT_SMPU_PLR_MEM_PFLASH_LOCK_Msk (0x2UL)                 /*!< TT_SMPU PLR: MEM_PFLASH_LOCK (Bitfield-Mask: 0x01) */
#define TT_SMPU_PLR_MEM_SRAM0_LOCK_Pos (2UL)                    /*!< TT_SMPU PLR: MEM_SRAM0_LOCK (Bit 2)               */
#define TT_SMPU_PLR_MEM_SRAM0_LOCK_Msk (0x4UL)                  /*!< TT_SMPU PLR: MEM_SRAM0_LOCK (Bitfield-Mask: 0x01) */
#define TT_SMPU_PLR_MEM_SRAM1_LOCK_Pos (3UL)                    /*!< TT_SMPU PLR: MEM_SRAM1_LOCK (Bit 3)               */
#define TT_SMPU_PLR_MEM_SRAM1_LOCK_Msk (0x8UL)                  /*!< TT_SMPU PLR: MEM_SRAM1_LOCK (Bitfield-Mask: 0x01) */
#define TT_SMPU_PLR_MEM_DFLASH_LOCK_Pos (4UL)                   /*!< TT_SMPU PLR: MEM_DFLASH_LOCK (Bit 4)              */
#define TT_SMPU_PLR_MEM_DFLASH_LOCK_Msk (0x10UL)                /*!< TT_SMPU PLR: MEM_DFLASH_LOCK (Bitfield-Mask: 0x01) */
/* ========================================================  PORT_BG  ======================================================== */
#define TT_SMPU_PORT_BG_EN_Pos        (0UL)                     /*!< TT_SMPU PORT_BG: EN (Bit 0)                       */
#define TT_SMPU_PORT_BG_EN_Msk        (0x1UL)                   /*!< TT_SMPU PORT_BG: EN (Bitfield-Mask: 0x01)         */

/* =========================================================================================================================== */
/* ================                                        PORT_ERROR                                         ================ */
/* =========================================================================================================================== */

/* ==========================================================  EAR  ========================================================== */
/* ==========================================================  EDR  ========================================================== */
#define TT_SMPU_PORT_ERROR_EDR_HWRITE_Pos         (0UL)                     /*!< PORT_ERROR EDR: HWRITE (Bit 0)                        */
#define TT_SMPU_PORT_ERROR_EDR_HWRITE_Msk         (0x1UL)                   /*!< PORT_ERROR EDR: HWRITE (Bitfield-Mask: 0x01)          */
#define TT_SMPU_PORT_ERROR_EDR_HPROT_Pos          (1UL)                     /*!< PORT_ERROR EDR: HPROT (Bit 1)                         */
#define TT_SMPU_PORT_ERROR_EDR_HPROT_Msk          (0x6UL)                   /*!< PORT_ERROR EDR: HPROT (Bitfield-Mask: 0x03)           */
#define TT_SMPU_PORT_ERROR_EDR_HMASTER_Pos        (4UL)                     /*!< PORT_ERROR EDR: HMASTER (Bit 4)                       */
#define TT_SMPU_PORT_ERROR_EDR_HMASTER_Msk        (0xf0UL)                  /*!< PORT_ERROR EDR: HMASTER (Bitfield-Mask: 0x0f)         */


/* =========================================================================================================================== */
/* ================                                      AHB_TCM_REGION                                       ================ */
/* =========================================================================================================================== */

/* =========================================================  START  ========================================================= */
#define TT_SMPU_REGION_START_ADDRESS_Pos  (7UL)                     /*!< AHB_TCM_REGION START: ADDRESS (Bit 7)                 */
#define TT_SMPU_REGION_START_ADDRESS_Msk  (0xffffff80UL)            /*!< AHB_TCM_REGION START: ADDRESS (Bitfield-Mask: 0x1ffffff) */
/* ==========================================================  END  ========================================================== */
#define TT_SMPU_REGION_END_ADDRESS_Pos    (7UL)                     /*!< AHB_TCM_REGION END: ADDRESS (Bit 7)                   */
#define TT_SMPU_REGION_END_ADDRESS_Msk    (0xffffff80UL)            /*!< AHB_TCM_REGION END: ADDRESS (Bitfield-Mask: 0x1ffffff) */
/* =====================================================  RIGHTS0_CONFIG  ===================================================== */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M0_USER_WRITE_Pos (0UL)        /*!< AHB_TCM_REGION RIGHTS_CONFIG: M0_USER_WRITE (Bit 0)   */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M0_USER_WRITE_Msk (0x1UL)      /*!< AHB_TCM_REGION RIGHTS_CONFIG: M0_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M0_USER_READ_Pos (1UL)         /*!< AHB_TCM_REGION RIGHTS_CONFIG: M0_USER_READ (Bit 1)    */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M0_USER_READ_Msk (0x2UL)       /*!< AHB_TCM_REGION RIGHTS_CONFIG: M0_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M0_PRIVILEGE_WRITE_Pos (2UL)   /*!< AHB_TCM_REGION RIGHTS_CONFIG: M0_PRIVILEGE_WRITE (Bit 2) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M0_PRIVILEGE_WRITE_Msk (0x4UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: M0_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M0_PRIVILEGE_READ_Pos (3UL)    /*!< AHB_TCM_REGION RIGHTS_CONFIG: M0_PRIVILEGE_READ (Bit 3) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M0_PRIVILEGE_READ_Msk (0x8UL)  /*!< AHB_TCM_REGION RIGHTS_CONFIG: M0_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_CIPHER_DMA_USER_WRITE_Pos (4UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: CIPHER_DMA_USER_WRITE (Bit 4) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_CIPHER_DMA_USER_WRITE_Msk (0x10UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: CIPHER_DMA_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_CIPHER_DMA_USER_READ_Pos (5UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: CIPHER_DMA_USER_READ (Bit 5) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_CIPHER_DMA_USER_READ_Msk (0x20UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: CIPHER_DMA_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_CIPHER_DMA_PRIVILEGE_WRITE_Pos (6UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: CIPHER_DMA_PRIVILEGE_WRITE (Bit 6) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_CIPHER_DMA_PRIVILEGE_WRITE_Msk (0x40UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: CIPHER_DMA_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_CIPHER_DMA_PRIVILEGE_READ_Pos (7UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: CIPHER_DMA_PRIVILEGE_READ (Bit 7) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_CIPHER_DMA_PRIVILEGE_READ_Msk (0x80UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: CIPHER_DMA_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M7_CRC_USER_WRITE_Pos (8UL)    /*!< AHB_TCM_REGION RIGHTS_CONFIG: M7_CRC_USER_WRITE (Bit 8) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M7_CRC_USER_WRITE_Msk (0x100UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: M7_CRC_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M7_CRC_USER_READ_Pos (9UL)     /*!< AHB_TCM_REGION RIGHTS_CONFIG: M7_CRC_USER_READ (Bit 9) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M7_CRC_USER_READ_Msk (0x200UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: M7_CRC_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M7_CRC_PRIVILEGE_WRITE_Pos (10UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: M7_CRC_PRIVILEGE_WRITE (Bit 10) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M7_CRC_PRIVILEGE_WRITE_Msk (0x400UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: M7_CRC_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M7_CRC_PRIVILEGE_READ_Pos (11UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: M7_CRC_PRIVILEGE_READ (Bit 11) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_M7_CRC_PRIVILEGE_READ_Msk (0x800UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: M7_CRC_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_ADC_USER_WRITE_Pos (12UL)      /*!< AHB_TCM_REGION RIGHTS_CONFIG: ADC_USER_WRITE (Bit 12) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_ADC_USER_WRITE_Msk (0x1000UL)  /*!< AHB_TCM_REGION RIGHTS_CONFIG: ADC_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_ADC_USER_READ_Pos (13UL)       /*!< AHB_TCM_REGION RIGHTS_CONFIG: ADC_USER_READ (Bit 13)  */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_ADC_USER_READ_Msk (0x2000UL)   /*!< AHB_TCM_REGION RIGHTS_CONFIG: ADC_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_ADC_PRIVILEGE_WRITE_Pos (14UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: ADC_PRIVILEGE_WRITE (Bit 14) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_ADC_PRIVILEGE_WRITE_Msk (0x4000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: ADC_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_ADC_PRIVILEGE_READ_Pos (15UL)  /*!< AHB_TCM_REGION RIGHTS_CONFIG: ADC_PRIVILEGE_READ (Bit 15) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_ADC_PRIVILEGE_READ_Msk (0x8000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: ADC_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_DMAC_USER_WRITE_Pos (16UL)     /*!< AHB_TCM_REGION RIGHTS_CONFIG: DMAC_USER_WRITE (Bit 16) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_DMAC_USER_WRITE_Msk (0x10000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: DMAC_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_DMAC_USER_READ_Pos (17UL)      /*!< AHB_TCM_REGION RIGHTS_CONFIG: DMAC_USER_READ (Bit 17) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_DMAC_USER_READ_Msk (0x20000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: DMAC_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_DMAC_PRIVILEGE_WRITE_Pos (18UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: DMAC_PRIVILEGE_WRITE (Bit 18) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_DMAC_PRIVILEGE_WRITE_Msk (0x40000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: DMAC_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_DMAC_PRIVILEGE_READ_Pos (19UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: DMAC_PRIVILEGE_READ (Bit 19) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_DMAC_PRIVILEGE_READ_Msk (0x80000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: DMAC_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_AXIBUSIC_USER_WRITE_Pos (20UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: AXIBUSIC_USER_WRITE (Bit 20) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_AXIBUSIC_USER_WRITE_Msk (0x100000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: AXIBUSIC_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_AXIBUSIC_USER_READ_Pos (21UL)  /*!< AHB_TCM_REGION RIGHTS_CONFIG: AXIBUSIC_USER_READ (Bit 21) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_AXIBUSIC_USER_READ_Msk (0x200000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: AXIBUSIC_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_AXIBUSIC_PRIVILEGE_WRITE_Pos (22UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: AXIBUSIC_PRIVILEGE_WRITE (Bit 22) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_AXIBUSIC_PRIVILEGE_WRITE_Msk (0x400000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: AXIBUSIC_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_AXIBUSIC_PRIVILEGE_READ_Pos (23UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: AXIBUSIC_PRIVILEGE_READ (Bit 23) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_AXIBUSIC_PRIVILEGE_READ_Msk (0x800000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: AXIBUSIC_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_GTM_USER_WRITE_Pos (24UL)      /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_WRITE (Bit 24) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_GTM_USER_WRITE_Msk (0x1000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_GTM_USER_READ_Pos (25UL)       /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_READ (Bit 25)  */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_GTM_USER_READ_Msk (0x2000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_GTM_PRIVILEGE_WRITE_Pos (26UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_WRITE (Bit 26) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_GTM_PRIVILEGE_WRITE_Msk (0x4000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_GTM_PRIVILEGE_READ_Pos (27UL)  /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_READ (Bit 27) */
#define TT_SMPU_REGION_RIGHTS0_CONFIG_GTM_PRIVILEGE_READ_Msk (0x8000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_READ (Bitfield-Mask: 0x01) */


/* =====================================================  RIGHTS1_CONFIG  ===================================================== */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_USER_WRITE_Pos (0UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_USER_WRITE (Bit 0) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_USER_WRITE_Msk (0x1UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_USER_READ_Pos (1UL)  /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_USER_READ (Bit 1) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_USER_READ_Msk (0x2UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_USER_EXECUTE_Pos (2UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_USER_EXECUTE (Bit 2) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_USER_EXECUTE_Msk (0x4UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_USER_EXECUTE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_PRIVILEGE_WRITE_Pos (4UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_PRIVILEGE_WRITE (Bit 4) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_PRIVILEGE_WRITE_Msk (0x10UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_PRIVILEGE_READ_Pos (5UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M0_PRIVILEGE_READ (Bit 5) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_PRIVILEGE_READ_Msk (0x20UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M0_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_PRIVILEGE_EXECUTE_Pos (6UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_PRIVILEGE_EXECUTE (Bit 6) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_M7_PRIVILEGE_EXECUTE_Msk (0x40UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: M7_PRIVILEGE_EXECUTE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_QSPI0_USER_WRITE_Pos (8UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: QSPI0_USER_WRITE (Bit 8) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_QSPI0_USER_WRITE_Msk (0x100UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: QSPI0_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_QSPI0_USER_READ_Pos (9UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: QSPI0_USER_READ (Bit 9) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_QSPI0_USER_READ_Msk (0x200UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: QSPI0_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_QSPI0_PRIVILEGE_WRITE_Pos (10UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: QSPI0_PRIVILEGE_WRITE (Bit 10) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_QSPI0_PRIVILEGE_WRITE_Msk (0x400UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: QSPI0_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_QSPI0_PRIVILEGE_READ_Pos (11UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: QSPI0_PRIVILEGE_READ (Bit 11) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_QSPI0_PRIVILEGE_READ_Msk (0x800UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: QSPI0_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_ETH_USER_WRITE_Pos (12UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: ETH_USER_WRITE (Bit 12) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_ETH_USER_WRITE_Msk (0x1000UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: ETH_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_ETH_USER_READ_Pos (13UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: ETH_USER_READ (Bit 13) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_ETH_USER_READ_Msk (0x2000UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: ETH_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_ETH_PRIVILEGE_WRITE_Pos (14UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: ETH_PRIVILEGE_WRITE (Bit 14) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_ETH_PRIVILEGE_WRITE_Msk (0x4000UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: ETH_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_ETH_PRIVILEGE_READ_Pos (15UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: ETH_PRIVILEGE_READ (Bit 15) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_ETH_PRIVILEGE_READ_Msk (0x8000UL) /*!< MEM_REGION MEM_RIGHTS_CONFIG: ETH_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM1_USER_WRITE_Pos (24UL)      /*!< AHB_TCMREGION RIGHTS_CONFIG: GTM_USER_WRITE (Bit 24) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM1_USER_WRITE_Msk (0x1000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM1_USER_READ_Pos (25UL)       /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_READ (Bit 25)  */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM1_USER_READ_Msk (0x2000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM1_PRIVILEGE_WRITE_Pos (26UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_WRITE (Bit 26) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM1_PRIVILEGE_WRITE_Msk (0x4000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM1_PRIVILEGE_READ_Pos (27UL)  /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_READ (Bit 27) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM1_PRIVILEGE_READ_Msk (0x8000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM2_USER_WRITE_Pos (28UL)      /*!< AHB_TCMREGION RIGHTS_CONFIG: GTM_USER_WRITE (Bit 24) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM2_USER_WRITE_Msk (0x10000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM2_USER_READ_Pos (29UL)       /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_READ (Bit 25)  */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM2_USER_READ_Msk (0x20000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_USER_READ (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM2_PRIVILEGE_WRITE_Pos (30UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_WRITE (Bit 26) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM2_PRIVILEGE_WRITE_Msk (0x40000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_WRITE (Bitfield-Mask: 0x01) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM2_PRIVILEGE_READ_Pos (31UL)  /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_READ (Bit 27) */
#define TT_SMPU_REGION_RIGHTS1_CONFIG_GTM2_PRIVILEGE_READ_Msk (0x80000000UL) /*!< AHB_TCM_REGION RIGHTS_CONFIG: GTM_PRIVILEGE_READ (Bitfield-Mask: 0x01) */

/* ========================================================  CONTROL  ======================================================== */
#define TT_SMPU_REGION_CONTROL_VALID_Pos  (0UL)                     /*!< AHB_TCM_REGION CONTROL: VALID (Bit 0)                 */
#define TT_SMPU_REGION_CONTROL_VALID_Msk  (0x1UL)                   /*!< AHB_TCM_REGION CONTROL: VALID (Bitfield-Mask: 0x01)   */
#define TT_SMPU_REGION_CONTROL_LOCK_Pos   (4UL)                     /*!< AHB_TCM_REGION CONTROL: LOCK (Bit 4)                  */
#define TT_SMPU_REGION_CONTROL_LOCK_Msk   (0x10UL)                  /*!< AHB_TCM_REGION CONTROL: LOCK (Bitfield-Mask: 0x01)    */


#ifdef __cplusplus
}
#endif

#endif /* A8V2_SMPU_H */
