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
#ifndef A8V2E_PPU_H
#define A8V2E_PPU_H
 
#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

 /******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_PPU_VENDOR_ID_H                     1541
#define A8V2E_PPU_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_PPU_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_PPU_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_PPU_SW_MAJOR_VERSION_H              1
#define A8V2E_PPU_SW_MINOR_VERSION_H              1
#define A8V2E_PPU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_PPU.h and TT_Common.h file version check */
#if (A8V2E_PPU_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_PPU.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_PPU_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_PPU_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_PPU_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_PPU.h and TT_Common.h are different"
#endif
#if ((A8V2E_PPU_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_PPU_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_PPU_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_PPU.h and TT_Common.h are different"
#endif


/* =========================================================================================================================== */
/* ================                                        TT_PPU                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief External PPU Device (TT_PPU)
  */

typedef struct {                                /*!< (@ 0x40072000) TT_PPU Structure                                           */
  __IM  uint32_t  APB0_USER;                    /*!< (@ 0x00000000) APB0_USER.                                                 */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  APB1_EN;                      /*!< (@ 0x00000008) APB1_EN.                                                   */
  __IOM uint32_t  APB2_EN;                      /*!< (@ 0x0000000C) APB2_M7_EN.                                                */
  __IOM uint32_t  APB3_EN;                      /*!< (@ 0x00000010) APB3_M7_EN.                                                */
  __IOM uint32_t  APB4_EN;                      /*!< (@ 0x00000014) APB4_M7_EN.                                                */
  __IM  uint32_t  RESERVED1[2];
  __IOM uint32_t  AHB0_EN;                      /*!< (@ 0x00000020) AHB0_M7_EN.                                                */
  __IOM uint32_t  AHB1_EN;                      /*!< (@ 0x00000024) AHB1_M7_EN.                                                */
  __IOM uint32_t  APB5_EN;                      /*!< (@ 0x00000028) APB5_M7_EN.                                                */
  __IOM uint32_t  AHB4_EN;                      /*!< (@ 0x0000002C) APB4_M7_EN.                                                */
  __IM  uint32_t  PLR0_USER;                    /*!< (@ 0x00000030) Protect User.                                              */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  PLR1_EN;                      /*!< (@ 0x00000038) Protect Enable.                                            */
  __IM  uint32_t  RESERVED3[2];
  __IOM  uint32_t  APB1_ERR;                     /*!< (@ 0x00000044) APB1_M7_ERR.                                               */
  __IOM  uint32_t  APB2_ERR;                     /*!< (@ 0x00000048) APB2_M7_ERR.                                               */
  __IOM  uint32_t  APB3_ERR;                     /*!< (@ 0x0000004C) APB3_M7_ERR.                                               */
  __IOM  uint32_t  APB4_ERR;                     /*!< (@ 0x00000050) APB4_M7_ERR.                                               */
  __IM  uint32_t  RESERVED4[3];
  __IOM  uint32_t  AHB0_ERR;                     /*!< (@ 0x00000060) AHB0_M7_ERR.                                               */
  __IOM  uint32_t  AHB1_ERR;                     /*!< (@ 0x00000064) AHB1_M7_ERR.                                               */
  __IOM  uint32_t  APB5_ERR;                     /*!< (@ 0x00000068) APB5_M7_ERR.                                               */
  __IOM  uint32_t  AHB4_ERR;                     /*!< (@ 0x0000006C) AHB4_M7_ERR.                                               */
  __IM  uint32_t  RESERVED5[4];
  __IOM uint32_t  APB1_PEN;                     /*!< (@ 0x00000080) APB1_PEN.                                                  */
  __IOM uint32_t  APB2_PEN;                     /*!< (@ 0x00000084) APB2_M7_PEN.                                               */
  __IOM uint32_t  APB3_PEN;                     /*!< (@ 0x00000088) APB3_M7_PEN.                                               */
  __IOM uint32_t  APB4_PEN;                     /*!< (@ 0x0000008C) APB4_M7_PEN.                                               */
  __IOM uint32_t  AHB0_PEN;                     /*!< (@ 0x00000090) AHB0_M7_PEN.                                               */
  __IOM uint32_t  AHB1_PEN;                     /*!< (@ 0x00000094) AHB1_M7_PEN.                                               */
  __IOM uint32_t  APB5_PEN;                     /*!< (@ 0x00000098) APB5_M7_PEN.                                               */
  __IOM uint32_t  AHB4_PEN;                     /*!< (@ 0x0000009C) APB4_M7_PEN.                                               */
  __IOM uint32_t  PPU_SUPV;                     /*!< (@ 0x000000A0) PPU_SUPV.                                                  */
  __IM  uint32_t  RESERVED6[982];
  __IM  uint32_t  ID_REG;                       /*!< (@ 0x00000FFC) ID_REG.                                                    */
}  Ppu_RegType, *Ppu_RegMemMapPtr;              /*!< Size = 104 (0x68)                                                         */



/* =========================================================================================================================== */
/* ================                                      TT_PPU_CIP                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief Cipher PPU Device (TT_PPU_CIP)
  */

typedef struct {                                /*!< (@ 0x40066000) TT_PPU_CIP Structure                                   */
  __IM  uint32_t  APB0_USER;                    /*!< (@ 0x00000000) APB0_USER.                                                 */
  __IOM uint32_t  APB0_EN;                      /*!< (@ 0x00000004) APB0_USER.                                                 */
  __IM  uint32_t  RESERVED[10];
  __IM  uint32_t  PLR0_USER;                    /*!< (@ 0x00000030) Protect User.                                              */
  __IOM uint32_t  PLR1_EN;                      /*!< (@ 0x00000034) Protect Enable.                                            */
  __IM  uint32_t  RESERVED1[2];
  __IM  uint32_t  APB0_ERR;                     /*!< (@ 0x00000040) APB0_ERR.                                                  */
} PpuCip_RegType, *PpuCip_RegMemMapPtr;         /*!< Size = 104 (0x68)                                                         */

/** Number of instances of the PPU module. */
#define PPU_INSTANCE_COUNT                          (1u)

/* PPU - Peripheral instance base addresses */
/** Peripheral PPU base address */
#define TT_PPU_BASE                                 (0x40072000UL)
#define TT_PPUCIP_BASE                              (0x40066000UL)

/** Peripheral PPU base pointer */
#define TT_PPU                                      ((Ppu_RegType *)TT_PPU_BASE)
#define TT_PPUCIP                                   ((PpuCip_RegType *)TT_PPUCIP_BASE)

/** Array initializer of PPU peripheral base addresses */
#define TT_PPU_BASE_ADDRS                           { TT_PPU_BASE }
#define TT_PPUCIP_BASE_ADDRS                        { TT_PPUCIP_BASE }

/** Array initializer of PPU peripheral base pointers */
#define TT_PPU_BASE_PTRS                            { TT_PPU}
#define TT_PPUCIP_BASE_PTRS                         { TT_PPUCIP}

typedef enum
{  
    /* APB0 */
    PPU_APB0_START        = 0,
    PPU_CONTROL_SCU       = 0,
    PPU_CONTROL_DBG       = 1,
    PPU_CONTROL_PPU       = 2,
    PPU_APB0_END          = 31,

    /* APB1 */
    PPU_APB1_START        = 32,
    PPU_CONTROL_PMU       = 32,
    PPU_CONTROL_SMPU      = 33,
    PPU_CONTROL_TIMER     = 34,
    PPU_CONTROL_WDT       = 35,
    PPU_CONTROL_CRC       = 36,
    PPU_CONTROL_UART0     = 37,
    PPU_CONTROL_UART1     = 38,
    PPU_CONTROL_I2C0      = 39,
    PPU_CONTROL_I2C1      = 40,
    PPU_CONTROL_SENT4     = 41,
    PPU_CONTROL_SENT5     = 42,
    PPU_CONTROL_FTM4      = 43,
    PPU_CONTROL_FTM5      = 44,
    PPU_CONTROL_IOM       = 45,
    PPU_CONTROL_SENT2     = 46,
    PPU_CONTROL_SENT3     = 47,
    PPU_APB1_END          = 47,

    /* APB2 */
    PPU_APB2_START        = 48,
    PPU_CONTROL_CAN0      = 48,
    PPU_CONTROL_CAN1      = 49,
    PPU_CONTROL_CAN2      = 50,
    PPU_CONTROL_CAN3      = 51,
    PPU_CONTROL_I3C0      = 52,
    PPU_CONTROL_GPIO0     = 53,
    PPU_CONTROL_GPIO1     = 54,
    PPU_CONTROL_GPIO2     = 55,
    PPU_CONTROL_FTM2      = 56,
    PPU_CONTROL_FTM3      = 57,
    PPU_CONTROL_ADCSENSOR = 58,
    PPU_CONTROL_UART2     = 59,
    PPU_CONTROL_UART3     = 60,
    PPU_CONTROL_SMU       = 61,
    PPU_CONTROL_GTMREG    = 62,
    PPU_CONTROL_INTM      = 63,
    PPU_APB2_END          = 63,

    /* APB3 */
    PPU_APB3_START        = 64,
    PPU_CONTROL_CAN4      = 64,
    PPU_CONTROL_CAN5      = 65,
    PPU_CONTROL_CAN6      = 66,
    PPU_CONTROL_CAN7      = 67,
    PPU_CONTROL_FTM0      = 68,
    PPU_CONTROL_FTM1      = 69,
    PPU_CONTROL_GPIO3     = 70,
    PPU_CONTROL_GPIO4     = 71,
    PPU_CONTROL_SENT0     = 72,
    PPU_CONTROL_SENT1     = 73,
    PPU_CONTROL_TRIGMUX   = 74,
    PPU_CONTROL_I2S0      = 75,
    PPU_CONTROL_SENT6     = 76,
    PPU_CONTROL_SENT7     = 77,
    PPU_CONTROL_STCU      = 78,
    PPU_APB3_END          = 95,

        /* APB4 */
    PPU_APB4_START        = 96,
    PPU_CONTROL_LIN0      = 96,
    PPU_CONTROL_LIN1      = 97,
    PPU_CONTROL_LIN2      = 98,
    PPU_CONTROL_LIN3      = 99,
    PPU_CONTROL_LIN4      = 100,
    PPU_CONTROL_LIN5      = 101,
    PPU_CONTROL_LIN6      = 102,
    PPU_CONTROL_LIN7      = 103,
    PPU_CONTROL_EIM       = 104,
    PPU_APB4_END          = 127,

    /* APB5 */
    PPU_APB5_START        = 128,
    PPU_CONTROL_LIN8      = 128,
    PPU_CONTROL_LIN9      = 129,
    PPU_CONTROL_LIN10     = 130,
    PPU_CONTROL_LIN11     = 131,
    PPU_CONTROL_LIN12     = 132,
    PPU_CONTROL_LIN13     = 133,
    PPU_CONTROL_LIN14     = 134,
    PPU_CONTROL_LIN15     = 135,
    PPU_APB5_END          = 159,

    /* AHB0 */
    PPU_AHB0_START        = 160,
    PPU_CONTROL_SPI0      = 160,
    PPU_CONTROL_SPI2      = 161,
    PPU_CONTROL_DMAC0     = 162,
    PPU_CONTROL_DMAC1     = 163,
    PPU_CONTROL_DMAC2     = 164,
    PPU_CONTROL_DMAC3     = 165,
    PPU_CONTROL_ADC       = 166,
    PPU_CONTROL_SPI4      = 167,
    PPU_CONTROL_DFCU      = 168,
    PPU_CONTROL_SPI6      = 169,
    PPU_AHB0_END          = 191,

    /* AHB1 */
    PPU_AHB1_START        = 192,
    PPU_CONTROL_SPI1      = 192,
    PPU_CONTROL_SPI3      = 193,
    PPU_CONTROL_FCU       = 194,
    PPU_CONTROL_EMAC      = 195,
    PPU_CONTROL_SPI5      = 196,
    PPU_CONTROL_PDB0      = 198,
    PPU_CONTROL_PDB1      = 199,
    PPU_CONTROL_SPI7      = 200,
    PPU_AHB1_END          = 223,

    /* AHB4 */
    PPU_AHB4_START        = 224,
    PPU_CONTROL_GTM_AXIS  = 224,
    PPU_AHB4_END          = 255,

    PPU_CONTROL_ALL       =  0xFFFF
}PPU_CONTROL_Type;
typedef enum
{
    /* AHB2 (Covert from APB0) */
    PPUCIP_CONTROL_SHIELD1,
    PPUCIP_CONTROL_SKA	,
    PPUCIP_CONTROL_PKI	,
    PPUCIP_CONTROL_HASH	,
    PPUCIP_CONTROL_SM4	,
    PPUCIP_CONTROL_PPU_CIP,
    PPUCIP_CONTROL_TRNG	,
    PPUCIP_CONTROL_END  
}PPUCIP_CONTROL_Type;

/* =========================================================================================================================== */
/* ================                                        TT_PPU                                         ================ */
/* =========================================================================================================================== */

/* =======================================================  APB0_USER  ======================================================= */
#define TT_PPU_APB0_USER_SCU_Pos          (0UL)                     /*!< TT_PPU APB0_USER: SCU (Bit 0)                         */
#define TT_PPU_APB0_USER_SCU_Msk          (0x1UL)                   /*!< TT_PPU APB0_USER: SCU (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB0_USER_GLB_DBG_CTL_Pos  (1UL)                     /*!< TT_PPU APB0_USER: GLB_DBG_CTL (Bit 1)                 */
#define TT_PPU_APB0_USER_GLB_DBG_CTL_Msk  (0x2UL)                   /*!< TT_PPU APB0_USER: GLB_DBG_CTL (Bitfield-Mask: 0x01)   */
#define TT_PPU_APB0_USER_PPU_Pos          (2UL)                     /*!< TT_PPU APB0_USER: PPU (Bit 2)                         */
#define TT_PPU_APB0_USER_PPU_Msk          (0x4UL)                   /*!< TT_PPU APB0_USER: PPU (Bitfield-Mask: 0x01)           */
/* ========================================================  APB1_EN  ======================================================== */
#define TT_PPU_APB1_EN_PMU_Pos            (0UL)                     /*!< TT_PPU APB1_EN: MPU (Bit 0)                           */
#define TT_PPU_APB1_EN_PMU_Msk            (0x1UL)                   /*!< TT_PPU APB1_EN: MPU (Bitfield-Mask: 0x01)             */
#define TT_PPU_APB1_EN_SMPU_Pos           (1UL)                     /*!< TT_PPU APB1_EN: SMPU (Bit 1)                          */
#define TT_PPU_APB1_EN_SMPU_Msk           (0x2UL)                   /*!< TT_PPU APB1_EN: SMPU (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_EN_TIMER_Pos          (2UL)                     /*!< TT_PPU APB1_EN: TIMER (Bit 2)                         */
#define TT_PPU_APB1_EN_TIMER_Msk          (0x4UL)                   /*!< TT_PPU APB1_EN: TIMER (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_EN_WDT_Pos            (3UL)                     /*!< TT_PPU APB1_EN: WDT (Bit 3)                           */
#define TT_PPU_APB1_EN_WDT_Msk            (0x8UL)                   /*!< TT_PPU APB1_EN: WDT (Bitfield-Mask: 0x01)             */
#define TT_PPU_APB1_EN_CRC_Pos            (4UL)                     /*!< TT_PPU APB1_EN: CRC (Bit 4)                           */
#define TT_PPU_APB1_EN_CRC_Msk            (0x10UL)                  /*!< TT_PPU APB1_EN: CRC (Bitfield-Mask: 0x01)             */
#define TT_PPU_APB1_EN_UART0_Pos          (5UL)                     /*!< TT_PPU APB1_EN: UART0 (Bit 5)                         */
#define TT_PPU_APB1_EN_UART0_Msk          (0x20UL)                  /*!< TT_PPU APB1_EN: UART0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_EN_UART1_Pos          (6UL)                     /*!< TT_PPU APB1_EN: UART1 (Bit 6)                         */
#define TT_PPU_APB1_EN_UART1_Msk          (0x40UL)                  /*!< TT_PPU APB1_EN: UART1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_EN_I2C0_Pos           (7UL)                     /*!< TT_PPU APB1_EN: I2C0 (Bit 7)                          */
#define TT_PPU_APB1_EN_I2C0_Msk           (0x80UL)                  /*!< TT_PPU APB1_EN: I2C0 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_EN_I2C1_Pos           (8UL)                     /*!< TT_PPU APB1_EN: I2C1 (Bit 8)                          */
#define TT_PPU_APB1_EN_I2C1_Msk           (0x100UL)                 /*!< TT_PPU APB1_EN: I2C1 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_EN_SENT4_Pos          (9UL)                     /*!< TT_PPU APB1_EN: SENT4 (Bit 9)                         */
#define TT_PPU_APB1_EN_SENT4_Msk          (0x200UL)                 /*!< TT_PPU APB1_EN: SENT4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_EN_SENT5_Pos          (10UL)                    /*!< TT_PPU APB1_EN: SENT5 (Bit 10)                        */
#define TT_PPU_APB1_EN_SENT5_Msk          (0x400UL)                 /*!< TT_PPU APB1_EN: SENT5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_EN_FTM4_Pos           (11UL)                    /*!< TT_PPU APB1_EN: FTM4 (Bit 11)                         */
#define TT_PPU_APB1_EN_FTM4_Msk           (0x800UL)                 /*!< TT_PPU APB1_EN: FTM4 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_EN_FTM5_Pos           (12UL)                    /*!< TT_PPU APB1_EN: FTM5 (Bit 12)                         */
#define TT_PPU_APB1_EN_FTM5_Msk           (0x1000UL)                /*!< TT_PPU APB1_EN: FTM5 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_EN_IOM_Pos            (13UL)                    /*!< TT_PPU APB1_EN: IOM (Bit 13)                          */
#define TT_PPU_APB1_EN_IOM_Msk            (0x2000UL)                /*!< TT_PPU APB1_EN: IOM (Bitfield-Mask: 0x01)             */
#define TT_PPU_APB1_EN_SENT2_Pos          (14UL)                    /*!< TT_PPU APB1_EN: SENT2 (Bit 14)                        */
#define TT_PPU_APB1_EN_SENT2_Msk          (0x4000UL)                /*!< TT_PPU APB1_EN: SENT2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_EN_SENT3_Pos          (15UL)                    /*!< TT_PPU APB1_EN: SENT3 (Bit 15)                        */
#define TT_PPU_APB1_EN_SENT3_Msk          (0x8000UL)                /*!< TT_PPU APB1_EN: SENT3 (Bitfield-Mask: 0x01)           */
/* ========================================================  APB2_EN  ======================================================== */
#define TT_PPU_APB2_EN_CAN0_Pos           (0UL)                     /*!< TT_PPU APB2_EN: CAN0 (Bit 0)                          */
#define TT_PPU_APB2_EN_CAN0_Msk           (0x1UL)                   /*!< TT_PPU APB2_EN: CAN0 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_EN_CAN1_Pos           (1UL)                     /*!< TT_PPU APB2_EN: CAN1 (Bit 1)                          */
#define TT_PPU_APB2_EN_CAN1_Msk           (0x2UL)                   /*!< TT_PPU APB2_EN: CAN1 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_EN_CAN2_Pos           (2UL)                     /*!< TT_PPU APB2_EN: CAN2 (Bit 2)                          */
#define TT_PPU_APB2_EN_CAN2_Msk           (0x4UL)                   /*!< TT_PPU APB2_EN: CAN2 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_EN_CAN3_Pos           (3UL)                     /*!< TT_PPU APB2_EN: CAN3 (Bit 3)                          */
#define TT_PPU_APB2_EN_CAN3_Msk           (0x8UL)                   /*!< TT_PPU APB2_EN: CAN3 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_EN_I3C0_Pos           (4UL)                     /*!< TT_PPU APB2_EN: I3C0 (Bit 4)                          */
#define TT_PPU_APB2_EN_I3C0_Msk           (0x10UL)                  /*!< TT_PPU APB2_EN: I3C0 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_EN_GPIO0_Pos          (5UL)                     /*!< TT_PPU APB2_EN: GPIO0 (Bit 5)                         */
#define TT_PPU_APB2_EN_GPIO0_Msk          (0x20UL)                  /*!< TT_PPU APB2_EN: GPIO0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_EN_GPIO1_Pos          (6UL)                     /*!< TT_PPU APB2_EN: GPIO1 (Bit 6)                         */
#define TT_PPU_APB2_EN_GPIO1_Msk          (0x40UL)                  /*!< TT_PPU APB2_EN: GPIO1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_EN_GPIO2_Pos          (7UL)                     /*!< TT_PPU APB2_EN: GPIO2 (Bit 7)                         */
#define TT_PPU_APB2_EN_GPIO2_Msk          (0x80UL)                  /*!< TT_PPU APB2_EN: GPIO2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_EN_FTM2_Pos           (8UL)                     /*!< TT_PPU APB2_EN: FTM2 (Bit 8)                          */
#define TT_PPU_APB2_EN_FTM2_Msk           (0x100UL)                 /*!< TT_PPU APB2_EN: FTM2 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_EN_FTM3_Pos           (9UL)                     /*!< TT_PPU APB2_EN: FTM3 (Bit 9)                          */
#define TT_PPU_APB2_EN_FTM3_Msk           (0x200UL)                 /*!< TT_PPU APB2_EN: FTM3 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_EN_ADC_SENSOR_Pos     (10UL)                    /*!< TT_PPU APB2_EN: ADC_SENSOR (Bit 10)                   */
#define TT_PPU_APB2_EN_ADC_SENSOR_Msk     (0x400UL)                 /*!< TT_PPU APB2_EN: ADC_SENSOR (Bitfield-Mask: 0x01)      */
#define TT_PPU_APB2_EN_UART2_Pos          (11UL)                    /*!< TT_PPU APB2_EN: UART2 (Bit 11)                        */
#define TT_PPU_APB2_EN_UART2_Msk          (0x800UL)                 /*!< TT_PPU APB2_EN: UART2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_EN_UART3_Pos          (12UL)                    /*!< TT_PPU APB2_EN: UART3 (Bit 12)                        */
#define TT_PPU_APB2_EN_UART3_Msk          (0x1000UL)                /*!< TT_PPU APB2_EN: UART3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_EN_SMU_Pos            (13UL)                    /*!< TT_PPU APB2_EN: SMU (Bit 13)                          */
#define TT_PPU_APB2_EN_SMU_Msk            (0x2000UL)                /*!< TT_PPU APB2_EN: SMU (Bitfield-Mask: 0x01)             */
#define TT_PPU_APB2_EN_GTM_REG_Pos        (14UL)                    /*!< TT_PPU APB2_EN: GTM_REG (Bit 14)                      */
#define TT_PPU_APB2_EN_GTM_REG_Msk        (0x4000UL)                /*!< TT_PPU APB2_EN: GTM_REG (Bitfield-Mask: 0x01)         */
#define TT_PPU_APB2_EN_INTM_Pos           (15UL)                    /*!< TT_PPU APB2_EN: INTM (Bit 15)                         */
#define TT_PPU_APB2_EN_INTM_Msk           (0x8000UL)                /*!< TT_PPU APB2_EN: INTM (Bitfield-Mask: 0x01)            */
/* ========================================================  APB3_EN  ======================================================== */
#define TT_PPU_APB3_EN_CAN4_Pos           (0UL)                     /*!< TT_PPU APB3_EN: CAN4 (Bit 0)                          */
#define TT_PPU_APB3_EN_CAN4_Msk           (0x1UL)                   /*!< TT_PPU APB3_EN: CAN4 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB3_EN_CAN5_Pos           (1UL)                     /*!< TT_PPU APB3_EN: CAN5 (Bit 1)                          */
#define TT_PPU_APB3_EN_CAN5_Msk           (0x2UL)                   /*!< TT_PPU APB3_EN: CAN5 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB3_EN_CAN6_Pos           (2UL)                     /*!< TT_PPU APB3_EN: CAN6 (Bit 2)                          */
#define TT_PPU_APB3_EN_CAN6_Msk           (0x4UL)                   /*!< TT_PPU APB3_EN: CAN6 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB3_EN_CAN7_Pos           (3UL)                     /*!< TT_PPU APB3_EN: CAN7 (Bit 3)                          */
#define TT_PPU_APB3_EN_CAN7_Msk           (0x8UL)                   /*!< TT_PPU APB3_EN: CAN7 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB3_EN_FTM0_Pos           (4UL)                     /*!< TT_PPU APB3_EN: FTM0 (Bit 4)                          */
#define TT_PPU_APB3_EN_FTM0_Msk           (0x10UL)                  /*!< TT_PPU APB3_EN: FTM0 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB3_EN_FTM1_Pos           (5UL)                     /*!< TT_PPU APB3_EN: FTM1 (Bit 5)                          */
#define TT_PPU_APB3_EN_FTM1_Msk           (0x20UL)                  /*!< TT_PPU APB3_EN: FTM1 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB3_EN_GPIO3_Pos          (6UL)                     /*!< TT_PPU APB3_EN: GPIO3 (Bit 6)                         */
#define TT_PPU_APB3_EN_GPIO3_Msk          (0x40UL)                  /*!< TT_PPU APB3_EN: GPIO3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_EN_GPIO4_Pos          (7UL)                     /*!< TT_PPU APB3_EN: GPIO4 (Bit 7)                         */
#define TT_PPU_APB3_EN_GPIO4_Msk          (0x80UL)                  /*!< TT_PPU APB3_EN: GPIO4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_EN_SENT0_Pos          (8UL)                     /*!< TT_PPU APB3_EN: SENT0 (Bit 8)                         */
#define TT_PPU_APB3_EN_SENT0_Msk          (0x100UL)                 /*!< TT_PPU APB3_EN: SENT0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_EN_SENT1_Pos          (9UL)                     /*!< TT_PPU APB3_EN: SENT1 (Bit 9)                         */
#define TT_PPU_APB3_EN_SENT1_Msk          (0x200UL)                 /*!< TT_PPU APB3_EN: SENT1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_EN_TRIG_MUX_Pos       (10UL)                    /*!< TT_PPU APB3_EN: TRIG_MUX (Bit 10)                     */
#define TT_PPU_APB3_EN_TRIG_MUX_Msk       (0x400UL)                 /*!< TT_PPU APB3_EN: TRIG_MUX (Bitfield-Mask: 0x01)        */
#define TT_PPU_APB3_EN_I2S0_Pos           (11UL)                    /*!< TT_PPU APB3_EN: I2S0 (Bit 11)                         */
#define TT_PPU_APB3_EN_I2S0_Msk           (0x800UL)                 /*!< TT_PPU APB3_EN: I2S0 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB3_EN_SENT6_Pos          (12UL)                    /*!< TT_PPU APB3_EN: SENT6 (Bit 12)                        */
#define TT_PPU_APB3_EN_SENT6_Msk          (0x1000UL)                /*!< TT_PPU APB3_EN: SENT6 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_EN_SENT7_Pos          (13UL)                    /*!< TT_PPU APB3_EN: SENT7 (Bit 13)                        */
#define TT_PPU_APB3_EN_SENT7_Msk          (0x2000UL)                /*!< TT_PPU APB3_EN: SENT7 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_EN_STCU_Pos            (14UL)                    /*!< TT_PPU APB3_EN: STU (Bit 14)                          */
#define TT_PPU_APB3_EN_STCU_Msk            (0x4000UL)                /*!< TT_PPU APB3_EN: STU (Bitfield-Mask: 0x01)             */
/* ========================================================  APB4_EN  ======================================================== */
#define TT_PPU_APB4_EN_LIN0_Pos           (0UL)                     /*!< TT_PPU APB4_EN: LIN0 (Bit 0)                          */
#define TT_PPU_APB4_EN_LIN0_Msk           (0x1UL)                   /*!< TT_PPU APB4_EN: LIN0 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB4_EN_LIN1_Pos           (1UL)                     /*!< TT_PPU APB4_EN: LIN1 (Bit 1)                          */
#define TT_PPU_APB4_EN_LIN1_Msk           (0x2UL)                   /*!< TT_PPU APB4_EN: LIN1 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB4_EN_LIN2_Pos           (2UL)                     /*!< TT_PPU APB4_EN: LIN2 (Bit 2)                          */
#define TT_PPU_APB4_EN_LIN2_Msk           (0x4UL)                   /*!< TT_PPU APB4_EN: LIN2 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB4_EN_LIN3_Pos           (3UL)                     /*!< TT_PPU APB4_EN: LIN3 (Bit 3)                          */
#define TT_PPU_APB4_EN_LIN3_Msk           (0x8UL)                   /*!< TT_PPU APB4_EN: LIN3 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB4_EN_LIN4_Pos           (4UL)                     /*!< TT_PPU APB4_EN: LIN4 (Bit 4)                          */
#define TT_PPU_APB4_EN_LIN4_Msk           (0x10UL)                  /*!< TT_PPU APB4_EN: LIN4 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB4_EN_LIN5_Pos           (5UL)                     /*!< TT_PPU APB4_EN: LIN5 (Bit 5)                          */
#define TT_PPU_APB4_EN_LIN5_Msk           (0x20UL)                  /*!< TT_PPU APB4_EN: LIN5 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB4_EN_LIN6_Pos           (6UL)                     /*!< TT_PPU APB4_EN: LIN6 (Bit 6)                          */
#define TT_PPU_APB4_EN_LIN6_Msk           (0x40UL)                  /*!< TT_PPU APB4_EN: LIN6 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB4_EN_LIN7_Pos           (7UL)                     /*!< TT_PPU APB4_EN: LIN7 (Bit 7)                          */
#define TT_PPU_APB4_EN_LIN7_Msk           (0x80UL)                  /*!< TT_PPU APB4_EN: LIN7 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB4_EN_EIM_Pos            (8UL)                     /*!< TT_PPU APB4_EN: EIM (Bit 8)                           */
#define TT_PPU_APB4_EN_EIM_Msk            (0x100UL)                 /*!< TT_PPU APB4_EN: EIM (Bitfield-Mask: 0x01)             */
/* ========================================================  AHB0_EN  ======================================================== */
#define TT_PPU_AHB0_EN_SPI0_Pos           (0UL)                     /*!< TT_PPU AHB0_EN: SPI0 (Bit 0)                          */
#define TT_PPU_AHB0_EN_SPI0_Msk           (0x1UL)                   /*!< TT_PPU AHB0_EN: SPI0 (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB0_EN_SPI2_Pos           (1UL)                     /*!< TT_PPU AHB0_EN: SPI2 (Bit 1)                          */
#define TT_PPU_AHB0_EN_SPI2_Msk           (0x2UL)                   /*!< TT_PPU AHB0_EN: SPI2 (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB0_EN_DMAC0_Pos          (2UL)                     /*!< TT_PPU AHB0_EN: DMAC0 (Bit 2)                         */
#define TT_PPU_AHB0_EN_DMAC0_Msk          (0x4UL)                   /*!< TT_PPU AHB0_EN: DMAC0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_EN_DMAC1_Pos          (3UL)                     /*!< TT_PPU AHB0_EN: DMAC1 (Bit 3)                         */
#define TT_PPU_AHB0_EN_DMAC1_Msk          (0x8UL)                   /*!< TT_PPU AHB0_EN: DMAC1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_EN_DMAC2_Pos          (4UL)                     /*!< TT_PPU AHB0_EN: DMAC2 (Bit 4)                         */
#define TT_PPU_AHB0_EN_DMAC2_Msk          (0x10UL)                  /*!< TT_PPU AHB0_EN: DMAC2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_EN_DMAC3_Pos          (5UL)                     /*!< TT_PPU AHB0_EN: DMAC3 (Bit 5)                         */
#define TT_PPU_AHB0_EN_DMAC3_Msk          (0x20UL)                  /*!< TT_PPU AHB0_EN: DMAC3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_EN_ADC_Pos            (6UL)                     /*!< TT_PPU AHB0_EN: ADC (Bit 6)                           */
#define TT_PPU_AHB0_EN_ADC_Msk            (0x40UL)                  /*!< TT_PPU AHB0_EN: ADC (Bitfield-Mask: 0x01)             */
#define TT_PPU_AHB0_EN_SPI4_Pos           (7UL)                     /*!< TT_PPU AHB0_EN: SPI4 (Bit 7)                          */
#define TT_PPU_AHB0_EN_SPI4_Msk           (0x80UL)                  /*!< TT_PPU AHB0_EN: SPI4 (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB0_EN_DFCU_REG_Pos       (8UL)                     /*!< TT_PPU AHB0_EN: DFCU_REG (Bit 8)                      */
#define TT_PPU_AHB0_EN_DFCU_REG_Msk       (0x100UL)                 /*!< TT_PPU AHB0_EN: DFCU_REG (Bitfield-Mask: 0x01)        */
#define TT_PPU_AHB0_EN_SPI6_Pos           (9UL)                     /*!< TT_PPU AHB0_EN: SPI6 (Bit 9)                          */
#define TT_PPU_AHB0_EN_SPI6_Msk           (0x200UL)                 /*!< TT_PPU AHB0_EN: SPI6 (Bitfield-Mask: 0x01)            */
/* ========================================================  AHB1_EN  ======================================================== */
#define TT_PPU_AHB1_EN_SPI1_Pos           (0UL)                     /*!< TT_PPU AHB1_EN: SPI1 (Bit 0)                          */
#define TT_PPU_AHB1_EN_SPI1_Msk           (0x1UL)                   /*!< TT_PPU AHB1_EN: SPI1 (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB1_EN_SPI3_Pos           (1UL)                     /*!< TT_PPU AHB1_EN: SPI3 (Bit 1)                          */
#define TT_PPU_AHB1_EN_SPI3_Msk           (0x2UL)                   /*!< TT_PPU AHB1_EN: SPI3 (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB1_EN_FCU_Pos            (2UL)                     /*!< TT_PPU AHB1_EN: FCU (Bit 2)                           */
#define TT_PPU_AHB1_EN_FCU_Msk            (0x4UL)                   /*!< TT_PPU AHB1_EN: FCU (Bitfield-Mask: 0x01)             */
#define TT_PPU_AHB1_EN_EMAC_Pos           (3UL)                     /*!< TT_PPU AHB1_EN: EMAC (Bit 3)                          */
#define TT_PPU_AHB1_EN_EMAC_Msk           (0x8UL)                   /*!< TT_PPU AHB1_EN: EMAC (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB1_EN_SPI5_Pos           (4UL)                     /*!< TT_PPU AHB1_EN: SPI5 (Bit 4)                          */
#define TT_PPU_AHB1_EN_SPI5_Msk           (0x10UL)                  /*!< TT_PPU AHB1_EN: SPI5 (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB1_EN_PDB0_Pos           (6UL)                     /*!< TT_PPU AHB1_EN: PDB0 (Bit 6)                          */
#define TT_PPU_AHB1_EN_PDB0_Msk           (0x40UL)                  /*!< TT_PPU AHB1_EN: PDB0 (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB1_EN_PDB1_Pos           (7UL)                     /*!< TT_PPU AHB1_EN: PDB1 (Bit 7)                          */
#define TT_PPU_AHB1_EN_PDB1_Msk           (0x80UL)                  /*!< TT_PPU AHB1_EN: PDB1 (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB1_EN_SPI7_Pos           (8UL)                     /*!< TT_PPU AHB1_EN: SPI7 (Bit 8)                          */
#define TT_PPU_AHB1_EN_SPI7_Msk           (0x100UL)                 /*!< TT_PPU AHB1_EN: SPI7 (Bitfield-Mask: 0x01)            */
/* ========================================================  APB5_EN  ======================================================== */
#define TT_PPU_APB5_EN_LIN8_Pos           (0UL)                     /*!< TT_PPU APB5_EN: LIN8 (Bit 0)                          */
#define TT_PPU_APB5_EN_LIN8_Msk           (0x1UL)                   /*!< TT_PPU APB5_EN: LIN8 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB5_EN_LIN9_Pos           (1UL)                     /*!< TT_PPU APB5_EN: LIN9 (Bit 1)                          */
#define TT_PPU_APB5_EN_LIN9_Msk           (0x2UL)                   /*!< TT_PPU APB5_EN: LIN9 (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB5_EN_LIN10_Pos          (2UL)                     /*!< TT_PPU APB5_EN: LIN10 (Bit 2)                         */
#define TT_PPU_APB5_EN_LIN10_Msk          (0x4UL)                   /*!< TT_PPU APB5_EN: LIN10 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_EN_LIN11_Pos          (3UL)                     /*!< TT_PPU APB5_EN: LIN11 (Bit 3)                         */
#define TT_PPU_APB5_EN_LIN11_Msk          (0x8UL)                   /*!< TT_PPU APB5_EN: LIN11 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_EN_LIN12_Pos          (4UL)                     /*!< TT_PPU APB5_EN: LIN12 (Bit 4)                         */
#define TT_PPU_APB5_EN_LIN12_Msk          (0x10UL)                  /*!< TT_PPU APB5_EN: LIN12 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_EN_LIN13_Pos          (5UL)                     /*!< TT_PPU APB5_EN: LIN13 (Bit 5)                         */
#define TT_PPU_APB5_EN_LIN13_Msk          (0x20UL)                  /*!< TT_PPU APB5_EN: LIN13 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_EN_LIN14_Pos          (6UL)                     /*!< TT_PPU APB5_EN: LIN14 (Bit 6)                         */
#define TT_PPU_APB5_EN_LIN14_Msk          (0x40UL)                  /*!< TT_PPU APB5_EN: LIN14 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_EN_LIN15_Pos          (7UL)                     /*!< TT_PPU APB5_EN: LIN15 (Bit 7)                         */
#define TT_PPU_APB5_EN_LIN15_Msk          (0x80UL)                  /*!< TT_PPU APB5_EN: LIN15 (Bitfield-Mask: 0x01)           */
/* ========================================================  AHB4_EN  ======================================================== */
#define TT_PPU_AHB4_EN_GTM_AXIS_Pos       (0UL)                     /*!< TT_PPU AHB4_EN: GTM_AXIS (Bit 0)                      */
#define TT_PPU_AHB4_EN_GTM_AXIS_Msk       (0x1UL)                   /*!< TT_PPU AHB4_EN: GTM_AXIS (Bitfield-Mask: 0x01)        */
/* =======================================================  PLR0_USER  ======================================================= */
#define TT_PPU_PLR0_USER_Locked_Pos       (0UL)                     /*!< TT_PPU PLR0_USER: Locked (Bit 0)                      */
#define TT_PPU_PLR0_USER_Locked_Msk       (0x1UL)                   /*!< TT_PPU PLR0_USER: Locked (Bitfield-Mask: 0x01)        */
/* ========================================================  PLR1_EN  ======================================================== */
/* ========================================================  PLR1_EN  ======================================================== */
#define TT_PPU_PLR1_EN_APB1_LOCKED_Pos    (0UL)                     /*!< TT_PPU PLR1_EN: APB1_LOCKED (Bit 0)                   */
#define TT_PPU_PLR1_EN_APB1_LOCKED_Msk    (0x1UL)                   /*!< TT_PPU PLR1_EN: APB1_LOCKED (Bitfield-Mask: 0x01)     */
#define TT_PPU_PLR1_EN_APB2_LOCKED_Pos    (1UL)                     /*!< TT_PPU PLR1_EN: APB2_LOCKED (Bit 1)                   */
#define TT_PPU_PLR1_EN_APB2_LOCKED_Msk    (0x2UL)                   /*!< TT_PPU PLR1_EN: APB2_LOCKED (Bitfield-Mask: 0x01)     */
#define TT_PPU_PLR1_EN_APB3_LOCKED_Pos    (2UL)                     /*!< TT_PPU PLR1_EN: APB3_LOCKED (Bit 2)                   */
#define TT_PPU_PLR1_EN_APB3_LOCKED_Msk    (0x4UL)                   /*!< TT_PPU PLR1_EN: APB3_LOCKED (Bitfield-Mask: 0x01)     */
#define TT_PPU_PLR1_EN_APB4_LOCKED_Pos    (3UL)                     /*!< TT_PPU PLR1_EN: APB4_LOCKED (Bit 3)                   */
#define TT_PPU_PLR1_EN_APB4_LOCKED_Msk    (0x8UL)                   /*!< TT_PPU PLR1_EN: APB4_LOCKED (Bitfield-Mask: 0x01)     */
#define TT_PPU_PLR1_EN_AHB0_LOCKED_Pos    (4UL)                     /*!< TT_PPU PLR1_EN: AHB0_LOCKED (Bit 4)                   */
#define TT_PPU_PLR1_EN_AHB0_LOCKED_Msk    (0x10UL)                  /*!< TT_PPU PLR1_EN: AHB0_LOCKED (Bitfield-Mask: 0x01)     */
#define TT_PPU_PLR1_EN_AHB1_LOCKED_Pos    (5UL)                     /*!< TT_PPU PLR1_EN: AHB1_LOCKED (Bit 5)                   */
#define TT_PPU_PLR1_EN_AHB1_LOCKED_Msk    (0x20UL)                  /*!< TT_PPU PLR1_EN: AHB1_LOCKED (Bitfield-Mask: 0x01)     */
#define TT_PPU_PLR1_EN_APB5_LOCKED_Pos    (6UL)                     /*!< TT_PPU PLR1_EN: APB5_LOCKED (Bit 6)                   */
#define TT_PPU_PLR1_EN_APB5_LOCKED_Msk    (0x40UL)                  /*!< TT_PPU PLR1_EN: APB5_LOCKED (Bitfield-Mask: 0x01)     */
#define TT_PPU_PLR1_EN_AHB4_LOCKED_Pos    (7UL)                     /*!< TT_PPU PLR1_EN: AHB4_LOCKED (Bit 7)                   */
#define TT_PPU_PLR1_EN_AHB4_LOCKED_Msk    (0x80UL)                  /*!< TT_PPU PLR1_EN: AHB4_LOCKED (Bitfield-Mask: 0x01)     */
/* =======================================================  APB1_ERR  ======================================================== */
#define TT_PPU_APB1_ERR_SMPU_Pos          (1UL)                     /*!< TT_PPU APB1_ERR: SMPU (Bit 1)                         */
#define TT_PPU_APB1_ERR_SMPU_Msk          (0x2UL)                   /*!< TT_PPU APB1_ERR: SMPU (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_ERR_TIMER_Pos         (2UL)                     /*!< TT_PPU APB1_ERR: TIMER (Bit 2)                        */
#define TT_PPU_APB1_ERR_TIMER_Msk         (0x4UL)                   /*!< TT_PPU APB1_ERR: TIMER (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_ERR_WDT_Pos           (3UL)                     /*!< TT_PPU APB1_ERR: WDT (Bit 3)                          */
#define TT_PPU_APB1_ERR_WDT_Msk           (0x8UL)                   /*!< TT_PPU APB1_ERR: WDT (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_ERR_CRC_Pos           (4UL)                     /*!< TT_PPU APB1_ERR: CRC (Bit 4)                          */
#define TT_PPU_APB1_ERR_CRC_Msk           (0x10UL)                  /*!< TT_PPU APB1_ERR: CRC (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_ERR_UART0_Pos         (5UL)                     /*!< TT_PPU APB1_ERR: UART0 (Bit 5)                        */
#define TT_PPU_APB1_ERR_UART0_Msk         (0x20UL)                  /*!< TT_PPU APB1_ERR: UART0 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_ERR_UART1_Pos         (6UL)                     /*!< TT_PPU APB1_ERR: UART1 (Bit 6)                        */
#define TT_PPU_APB1_ERR_UART1_Msk         (0x40UL)                  /*!< TT_PPU APB1_ERR: UART1 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_ERR_I2C0_Pos          (7UL)                     /*!< TT_PPU APB1_ERR: I2C0 (Bit 7)                         */
#define TT_PPU_APB1_ERR_I2C0_Msk          (0x80UL)                  /*!< TT_PPU APB1_ERR: I2C0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_ERR_I2C1_Pos          (8UL)                     /*!< TT_PPU APB1_ERR: I2C1 (Bit 8)                         */
#define TT_PPU_APB1_ERR_I2C1_Msk          (0x100UL)                 /*!< TT_PPU APB1_ERR: I2C1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_ERR_SENT4_Pos         (9UL)                     /*!< TT_PPU APB1_ERR: SENT4 (Bit 9)                        */
#define TT_PPU_APB1_ERR_SENT4_Msk         (0x200UL)                 /*!< TT_PPU APB1_ERR: SENT4 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_ERR_SENT5_Pos         (10UL)                    /*!< TT_PPU APB1_ERR: SENT5 (Bit 10)                       */
#define TT_PPU_APB1_ERR_SENT5_Msk         (0x400UL)                 /*!< TT_PPU APB1_ERR: SENT5 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_ERR_FTM4_Pos          (11UL)                    /*!< TT_PPU APB1_ERR: FTM4 (Bit 11)                        */
#define TT_PPU_APB1_ERR_FTM4_Msk          (0x800UL)                 /*!< TT_PPU APB1_ERR: FTM4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_ERR_FTM5_Pos          (12UL)                    /*!< TT_PPU APB1_ERR: FTM5 (Bit 12)                        */
#define TT_PPU_APB1_ERR_FTM5_Msk          (0x1000UL)                /*!< TT_PPU APB1_ERR: FTM5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_ERR_IOM_Pos           (13UL)                    /*!< TT_PPU APB1_ERR: IOM (Bit 13)                         */
#define TT_PPU_APB1_ERR_IOM_Msk           (0x2000UL)                /*!< TT_PPU APB1_ERR: IOM (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_ERR_SENT2_Pos         (14UL)                    /*!< TT_PPU APB1_ERR: SENT2 (Bit 14)                       */
#define TT_PPU_APB1_ERR_SENT2_Msk         (0x4000UL)                /*!< TT_PPU APB1_ERR: SENT2 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_ERR_SENT3_Pos         (15UL)                    /*!< TT_PPU APB1_ERR: SENT3 (Bit 15)                       */
#define TT_PPU_APB1_ERR_SENT3_Msk         (0x8000UL)                /*!< TT_PPU APB1_ERR: SENT3 (Bitfield-Mask: 0x01)          */
/* =======================================================  APB2_ERR  ======================================================== */
#define TT_PPU_APB2_ERR_CAN0_Pos          (0UL)                     /*!< TT_PPU APB2_ERR: CAN0 (Bit 0)                         */
#define TT_PPU_APB2_ERR_CAN0_Msk          (0x1UL)                   /*!< TT_PPU APB2_ERR: CAN0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_ERR_CAN1_Pos          (1UL)                     /*!< TT_PPU APB2_ERR: CAN1 (Bit 1)                         */
#define TT_PPU_APB2_ERR_CAN1_Msk          (0x2UL)                   /*!< TT_PPU APB2_ERR: CAN1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_ERR_CAN2_Pos          (2UL)                     /*!< TT_PPU APB2_ERR: CAN2 (Bit 2)                         */
#define TT_PPU_APB2_ERR_CAN2_Msk          (0x4UL)                   /*!< TT_PPU APB2_ERR: CAN2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_ERR_CAN3_Pos          (3UL)                     /*!< TT_PPU APB2_ERR: CAN3 (Bit 3)                         */
#define TT_PPU_APB2_ERR_CAN3_Msk          (0x8UL)                   /*!< TT_PPU APB2_ERR: CAN3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_ERR_I3C0_Pos          (4UL)                     /*!< TT_PPU APB2_ERR: I3C0 (Bit 4)                         */
#define TT_PPU_APB2_ERR_I3C0_Msk          (0x10UL)                  /*!< TT_PPU APB2_ERR: I3C0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_ERR_GPIO0_Pos         (5UL)                     /*!< TT_PPU APB2_ERR: GPIO0 (Bit 5)                        */
#define TT_PPU_APB2_ERR_GPIO0_Msk         (0x20UL)                  /*!< TT_PPU APB2_ERR: GPIO0 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_ERR_GPIO1_Pos         (6UL)                     /*!< TT_PPU APB2_ERR: GPIO1 (Bit 6)                        */
#define TT_PPU_APB2_ERR_GPIO1_Msk         (0x40UL)                  /*!< TT_PPU APB2_ERR: GPIO1 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_ERR_GPIO2_Pos         (7UL)                     /*!< TT_PPU APB2_ERR: GPIO2 (Bit 7)                        */
#define TT_PPU_APB2_ERR_GPIO2_Msk         (0x80UL)                  /*!< TT_PPU APB2_ERR: GPIO2 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_ERR_FTM2_Pos          (8UL)                     /*!< TT_PPU APB2_ERR: FTM2 (Bit 8)                         */
#define TT_PPU_APB2_ERR_FTM2_Msk          (0x100UL)                 /*!< TT_PPU APB2_ERR: FTM2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_ERR_FTM3_Pos          (9UL)                     /*!< TT_PPU APB2_ERR: FTM3 (Bit 9)                         */
#define TT_PPU_APB2_ERR_FTM3_Msk          (0x200UL)                 /*!< TT_PPU APB2_ERR: FTM3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_ERR_ADCSENSOR_Pos     (10UL)                    /*!< TT_PPU APB2_ERR: ADCSENSOR (Bit 10)                   */
#define TT_PPU_APB2_ERR_ADCSENSOR_Msk     (0x400UL)                 /*!< TT_PPU APB2_ERR: ADCSENSOR (Bitfield-Mask: 0x01)      */
#define TT_PPU_APB2_ERR_UART2_Pos         (11UL)                    /*!< TT_PPU APB2_ERR: UART2 (Bit 11)                       */
#define TT_PPU_APB2_ERR_UART2_Msk         (0x800UL)                 /*!< TT_PPU APB2_ERR: UART2 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_ERR_UART3_Pos         (12UL)                    /*!< TT_PPU APB2_ERR: UART3 (Bit 12)                       */
#define TT_PPU_APB2_ERR_UART3_Msk         (0x1000UL)                /*!< TT_PPU APB2_ERR: UART3 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_ERR_SMU_Pos           (13UL)                    /*!< TT_PPU APB2_ERR: SMU (Bit 13)                         */
#define TT_PPU_APB2_ERR_SMU_Msk           (0x2000UL)                /*!< TT_PPU APB2_ERR: SMU (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_ERR_GTMREG_Pos        (14UL)                    /*!< TT_PPU APB2_ERR: GTMREG (Bit 14)                      */
#define TT_PPU_APB2_ERR_GTMREG_Msk        (0x4000UL)                /*!< TT_PPU APB2_ERR: GTMREG (Bitfield-Mask: 0x01)         */
#define TT_PPU_APB2_ERR_INTM_Pos          (15UL)                    /*!< TT_PPU APB2_ERR: INTM (Bit 15)                        */
#define TT_PPU_APB2_ERR_INTM_Msk          (0x8000UL)                /*!< TT_PPU APB2_ERR: INTM (Bitfield-Mask: 0x01)           */
/* =======================================================  APB3_ERR  ======================================================== */
#define TT_PPU_APB3_ERR_CAN4_Pos          (0UL)                     /*!< TT_PPU APB3_ERR: CAN4 (Bit 0)                         */
#define TT_PPU_APB3_ERR_CAN4_Msk          (0x1UL)                   /*!< TT_PPU APB3_ERR: CAN4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_ERR_CAN5_Pos          (1UL)                     /*!< TT_PPU APB3_ERR: CAN5 (Bit 1)                         */
#define TT_PPU_APB3_ERR_CAN5_Msk          (0x2UL)                   /*!< TT_PPU APB3_ERR: CAN5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_ERR_CAN6_Pos          (2UL)                     /*!< TT_PPU APB3_ERR: CAN6 (Bit 2)                         */
#define TT_PPU_APB3_ERR_CAN6_Msk          (0x4UL)                   /*!< TT_PPU APB3_ERR: CAN6 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_ERR_CAN7_Pos          (3UL)                     /*!< TT_PPU APB3_ERR: CAN7 (Bit 3)                         */
#define TT_PPU_APB3_ERR_CAN7_Msk          (0x8UL)                   /*!< TT_PPU APB3_ERR: CAN7 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_ERR_FTM0_Pos          (4UL)                     /*!< TT_PPU APB3_ERR: FTM0 (Bit 4)                         */
#define TT_PPU_APB3_ERR_FTM0_Msk          (0x10UL)                  /*!< TT_PPU APB3_ERR: FTM0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_ERR_FTM1_Pos          (5UL)                     /*!< TT_PPU APB3_ERR: FTM1 (Bit 5)                         */
#define TT_PPU_APB3_ERR_FTM1_Msk          (0x20UL)                  /*!< TT_PPU APB3_ERR: FTM1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_ERR_GPIO3_Pos         (6UL)                     /*!< TT_PPU APB3_ERR: GPIO3 (Bit 6)                        */
#define TT_PPU_APB3_ERR_GPIO3_Msk         (0x40UL)                  /*!< TT_PPU APB3_ERR: GPIO3 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_ERR_GPIO4_Pos         (7UL)                     /*!< TT_PPU APB3_ERR: GPIO4 (Bit 7)                        */
#define TT_PPU_APB3_ERR_GPIO4_Msk         (0x80UL)                  /*!< TT_PPU APB3_ERR: GPIO4 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_ERR_SENT0_Pos         (8UL)                     /*!< TT_PPU APB3_ERR: SENT0 (Bit 8)                        */
#define TT_PPU_APB3_ERR_SENT0_Msk         (0x100UL)                 /*!< TT_PPU APB3_ERR: SENT0 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_ERR_SENT1_Pos         (9UL)                     /*!< TT_PPU APB3_ERR: SENT1 (Bit 9)                        */
#define TT_PPU_APB3_ERR_SENT1_Msk         (0x200UL)                 /*!< TT_PPU APB3_ERR: SENT1 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_ERR_TRIG_MUX_Pos      (10UL)                    /*!< TT_PPU APB3_ERR: TRIG_MUX (Bit 10)                    */
#define TT_PPU_APB3_ERR_TRIG_MUX_Msk      (0x400UL)                 /*!< TT_PPU APB3_ERR: TRIG_MUX (Bitfield-Mask: 0x01)       */
#define TT_PPU_APB3_ERR_I2S0_Pos          (11UL)                    /*!< TT_PPU APB3_ERR: I2S0 (Bit 11)                        */
#define TT_PPU_APB3_ERR_I2S0_Msk          (0x800UL)                 /*!< TT_PPU APB3_ERR: I2S0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_ERR_SENT6_Pos         (12UL)                    /*!< TT_PPU APB3_ERR: SENT6 (Bit 12)                       */
#define TT_PPU_APB3_ERR_SENT6_Msk         (0x1000UL)                /*!< TT_PPU APB3_ERR: SENT6 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_ERR_SENT7_Pos         (13UL)                    /*!< TT_PPU APB3_ERR: SENT7 (Bit 13)                       */
#define TT_PPU_APB3_ERR_SENT7_Msk         (0x2000UL)                /*!< TT_PPU APB3_ERR: SENT7 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_ERR_STCU_Pos           (14UL)                    /*!< TT_PPU APB3_ERR: STU (Bit 14)                         */
#define TT_PPU_APB3_ERR_STCU_Msk           (0x4000UL)                /*!< TT_PPU APB3_ERR: STU (Bitfield-Mask: 0x01)            */
/* =======================================================  APB4_ERR  ======================================================== */
#define TT_PPU_APB4_ERR_LIN0_Pos          (0UL)                     /*!< TT_PPU APB4_ERR: LIN0 (Bit 0)                         */
#define TT_PPU_APB4_ERR_LIN0_Msk          (0x1UL)                   /*!< TT_PPU APB4_ERR: LIN0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_ERR_LIN1_Pos          (1UL)                     /*!< TT_PPU APB4_ERR: LIN1 (Bit 1)                         */
#define TT_PPU_APB4_ERR_LIN1_Msk          (0x2UL)                   /*!< TT_PPU APB4_ERR: LIN1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_ERR_LIN2_Pos          (2UL)                     /*!< TT_PPU APB4_ERR: LIN2 (Bit 2)                         */
#define TT_PPU_APB4_ERR_LIN2_Msk          (0x4UL)                   /*!< TT_PPU APB4_ERR: LIN2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_ERR_LIN3_Pos          (3UL)                     /*!< TT_PPU APB4_ERR: LIN3 (Bit 3)                         */
#define TT_PPU_APB4_ERR_LIN3_Msk          (0x8UL)                   /*!< TT_PPU APB4_ERR: LIN3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_ERR_LIN4_Pos          (4UL)                     /*!< TT_PPU APB4_ERR: LIN4 (Bit 4)                         */
#define TT_PPU_APB4_ERR_LIN4_Msk          (0x10UL)                  /*!< TT_PPU APB4_ERR: LIN4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_ERR_LIN5_Pos          (5UL)                     /*!< TT_PPU APB4_ERR: LIN5 (Bit 5)                         */
#define TT_PPU_APB4_ERR_LIN5_Msk          (0x20UL)                  /*!< TT_PPU APB4_ERR: LIN5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_ERR_LIN6_Pos          (6UL)                     /*!< TT_PPU APB4_ERR: LIN6 (Bit 6)                         */
#define TT_PPU_APB4_ERR_LIN6_Msk          (0x40UL)                  /*!< TT_PPU APB4_ERR: LIN6 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_ERR_LIN7_Pos          (7UL)                     /*!< TT_PPU APB4_ERR: LIN7 (Bit 7)                         */
#define TT_PPU_APB4_ERR_LIN7_Msk          (0x80UL)                  /*!< TT_PPU APB4_ERR: LIN7 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_ERR_EIM_Pos           (8UL)                     /*!< TT_PPU APB4_ERR: EIM (Bit 8)                          */
#define TT_PPU_APB4_ERR_EIM_Msk           (0x100UL)                 /*!< TT_PPU APB4_ERR: EIM (Bitfield-Mask: 0x01)            */
/* =======================================================  AHB0_ERR  ======================================================== */
#define TT_PPU_AHB0_ERR_SPI0_Pos          (0UL)                     /*!< TT_PPU AHB0_ERR: SPI0 (Bit 0)                         */
#define TT_PPU_AHB0_ERR_SPI0_Msk          (0x1UL)                   /*!< TT_PPU AHB0_ERR: SPI0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_ERR_SPI2_Pos          (1UL)                     /*!< TT_PPU AHB0_ERR: SPI1 (Bit 1)                         */
#define TT_PPU_AHB0_ERR_SPI2_Msk          (0x2UL)                   /*!< TT_PPU AHB0_ERR: SPI1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_ERR_DMAC0_Pos         (2UL)                     /*!< TT_PPU AHB0_ERR: DMAC0 (Bit 2)                        */
#define TT_PPU_AHB0_ERR_DMAC0_Msk         (0x4UL)                   /*!< TT_PPU AHB0_ERR: DMAC0 (Bitfield-Mask: 0x01)          */
#define TT_PPU_AHB0_ERR_DMAC1_Pos         (3UL)                     /*!< TT_PPU AHB0_ERR: DMAC1 (Bit 3)                        */
#define TT_PPU_AHB0_ERR_DMAC1_Msk         (0x8UL)                   /*!< TT_PPU AHB0_ERR: DMAC1 (Bitfield-Mask: 0x01)          */
#define TT_PPU_AHB0_ERR_DMAC2_Pos         (4UL)                     /*!< TT_PPU AHB0_ERR: DMAC2 (Bit 4)                        */
#define TT_PPU_AHB0_ERR_DMAC2_Msk         (0x10UL)                  /*!< TT_PPU AHB0_ERR: DMAC2 (Bitfield-Mask: 0x01)          */
#define TT_PPU_AHB0_ERR_DMAC3_Pos         (5UL)                     /*!< TT_PPU AHB0_ERR: DMAC3 (Bit 5)                        */
#define TT_PPU_AHB0_ERR_DMAC3_Msk         (0x20UL)                  /*!< TT_PPU AHB0_ERR: DMAC3 (Bitfield-Mask: 0x01)          */
#define TT_PPU_AHB0_ERR_ADC_REG_Pos       (6UL)                     /*!< TT_PPU AHB0_ERR: ADC_REG (Bit 6)                      */
#define TT_PPU_AHB0_ERR_ADC_REG_Msk       (0x40UL)                  /*!< TT_PPU AHB0_ERR: ADC_REG (Bitfield-Mask: 0x01)        */
#define TT_PPU_AHB0_ERR_SPI4_Pos          (7UL)                     /*!< TT_PPU AHB0_ERR: SPI4 (Bit 7)                         */
#define TT_PPU_AHB0_ERR_SPI4_Msk          (0x80UL)                  /*!< TT_PPU AHB0_ERR: SPI4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_ERR_DFCU_REG_Pos      (8UL)                     /*!< TT_PPU AHB0_ERR: DFCU_REG (Bit 8)                     */
#define TT_PPU_AHB0_ERR_DFCU_REG_Msk      (0x100UL)                 /*!< TT_PPU AHB0_ERR: DFCU_REG (Bitfield-Mask: 0x01)       */
#define TT_PPU_AHB0_ERR_SPI6_Pos          (9UL)                     /*!< TT_PPU AHB0_ERR: SPI6 (Bit 9)                         */
#define TT_PPU_AHB0_ERR_SPI6_Msk          (0x200UL)                 /*!< TT_PPU AHB0_ERR: SPI6 (Bitfield-Mask: 0x01)           */
/* =======================================================  AHB1_ERR  ======================================================== */
#define TT_PPU_AHB1_ERR_SPI1_Pos          (0UL)                     /*!< TT_PPU AHB1_ERR: SPI1 (Bit 0)                         */
#define TT_PPU_AHB1_ERR_SPI1_Msk          (0x1UL)                   /*!< TT_PPU AHB1_ERR: SPI1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_ERR_SPI3_Pos          (1UL)                     /*!< TT_PPU AHB1_ERR: SPI3 (Bit 1)                         */
#define TT_PPU_AHB1_ERR_SPI3_Msk          (0x2UL)                   /*!< TT_PPU AHB1_ERR: SPI3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_ERR_FCU_Pos           (2UL)                     /*!< TT_PPU AHB1_ERR: FCU (Bit 2)                          */
#define TT_PPU_AHB1_ERR_FCU_Msk           (0x4UL)                   /*!< TT_PPU AHB1_ERR: FCU (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB1_ERR_EMAC_Pos          (3UL)                     /*!< TT_PPU AHB1_ERR: EMAC (Bit 3)                         */
#define TT_PPU_AHB1_ERR_EMAC_Msk          (0x8UL)                   /*!< TT_PPU AHB1_ERR: EMAC (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_ERR_SPI5_Pos          (4UL)                     /*!< TT_PPU AHB1_ERR: SPI5 (Bit 4)                         */
#define TT_PPU_AHB1_ERR_SPI5_Msk          (0x10UL)                  /*!< TT_PPU AHB1_ERR: SPI5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_ERR_PDB0_Pos          (6UL)                     /*!< TT_PPU AHB1_ERR: PDB0 (Bit 6)                         */
#define TT_PPU_AHB1_ERR_PDB0_Msk          (0x40UL)                  /*!< TT_PPU AHB1_ERR: PDB0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_ERR_PDB1_Pos          (7UL)                     /*!< TT_PPU AHB1_ERR: PDB1 (Bit 7)                         */
#define TT_PPU_AHB1_ERR_PDB1_Msk          (0x80UL)                  /*!< TT_PPU AHB1_ERR: PDB1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_ERR_SPI7_Pos          (8UL)                     /*!< TT_PPU AHB1_ERR: SPI7 (Bit 8)                         */
#define TT_PPU_AHB1_ERR_SPI7_Msk          (0x100UL)                 /*!< TT_PPU AHB1_ERR: SPI7 (Bitfield-Mask: 0x01)           */
/* =======================================================  APB5_ERR  ======================================================== */
#define TT_PPU_APB5_ERR_LIN8_Pos          (0UL)                     /*!< TT_PPU APB5_ERR: LIN8 (Bit 0)                         */
#define TT_PPU_APB5_ERR_LIN8_Msk          (0x1UL)                   /*!< TT_PPU APB5_ERR: LIN8 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_ERR_LIN9_Pos          (1UL)                     /*!< TT_PPU APB5_ERR: LIN9 (Bit 1)                         */
#define TT_PPU_APB5_ERR_LIN9_Msk          (0x2UL)                   /*!< TT_PPU APB5_ERR: LIN9 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_ERR_LIN10_Pos         (2UL)                     /*!< TT_PPU APB5_ERR: LIN10 (Bit 2)                        */
#define TT_PPU_APB5_ERR_LIN10_Msk         (0x4UL)                   /*!< TT_PPU APB5_ERR: LIN10 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_ERR_LIN11_Pos         (3UL)                     /*!< TT_PPU APB5_ERR: LIN11 (Bit 3)                        */
#define TT_PPU_APB5_ERR_LIN11_Msk         (0x8UL)                   /*!< TT_PPU APB5_ERR: LIN11 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_ERR_LIN12_Pos         (4UL)                     /*!< TT_PPU APB5_ERR: LIN12 (Bit 4)                        */
#define TT_PPU_APB5_ERR_LIN12_Msk         (0x10UL)                  /*!< TT_PPU APB5_ERR: LIN12 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_ERR_LIN13_Pos         (5UL)                     /*!< TT_PPU APB5_ERR: LIN13 (Bit 5)                        */
#define TT_PPU_APB5_ERR_LIN13_Msk         (0x20UL)                  /*!< TT_PPU APB5_ERR: LIN13 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_ERR_LIN14_Pos         (6UL)                     /*!< TT_PPU APB5_ERR: LIN14 (Bit 6)                        */
#define TT_PPU_APB5_ERR_LIN14_Msk         (0x40UL)                  /*!< TT_PPU APB5_ERR: LIN14 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_ERR_LIN15_Pos         (7UL)                     /*!< TT_PPU APB5_ERR: LIN15 (Bit 7)                        */
#define TT_PPU_APB5_ERR_LIN15_Msk         (0x80UL)                  /*!< TT_PPU APB5_ERR: LIN15 (Bitfield-Mask: 0x01)          */
/* =======================================================  AHB4_ERR  ======================================================== */
#define TT_PPU_AHB4_ERR_GTM_AXIS_Pos      (0UL)                     /*!< TT_PPU AHB4_ERR: GTM_AXIS (Bit 0)                     */
#define TT_PPU_AHB4_ERR_GTM_AXIS_Msk      (0x1UL)                   /*!< TT_PPU AHB4_ERR: GTM_AXIS (Bitfield-Mask: 0x01)       */
/* =======================================================  APB1_PEN  ======================================================== */
#define TT_PPU_APB1_PEN_PMU_Pos           (0UL)                     /*!< TT_PPU APB1_PEN: MPU (Bit 0)                          */
#define TT_PPU_APB1_PEN_PMU_Msk           (0x1UL)                   /*!< TT_PPU APB1_PEN: MPU (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_PEN_SMPU_Pos          (1UL)                     /*!< TT_PPU APB1_PEN: SMPU (Bit 1)                         */
#define TT_PPU_APB1_PEN_SMPU_Msk          (0x2UL)                   /*!< TT_PPU APB1_PEN: SMPU (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_PEN_TIMER_Pos         (2UL)                     /*!< TT_PPU APB1_PEN: TIMER (Bit 2)                        */
#define TT_PPU_APB1_PEN_TIMER_Msk         (0x4UL)                   /*!< TT_PPU APB1_PEN: TIMER (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_PEN_WDT_Pos           (3UL)                     /*!< TT_PPU APB1_PEN: WDT (Bit 3)                          */
#define TT_PPU_APB1_PEN_WDT_Msk           (0x8UL)                   /*!< TT_PPU APB1_PEN: WDT (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_PEN_CRC_Pos           (4UL)                     /*!< TT_PPU APB1_PEN: CRC (Bit 4)                          */
#define TT_PPU_APB1_PEN_CRC_Msk           (0x10UL)                  /*!< TT_PPU APB1_PEN: CRC (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_PEN_UART0_Pos         (5UL)                     /*!< TT_PPU APB1_PEN: UART0 (Bit 5)                        */
#define TT_PPU_APB1_PEN_UART0_Msk         (0x20UL)                  /*!< TT_PPU APB1_PEN: UART0 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_PEN_UART1_Pos         (6UL)                     /*!< TT_PPU APB1_PEN: UART1 (Bit 6)                        */
#define TT_PPU_APB1_PEN_UART1_Msk         (0x40UL)                  /*!< TT_PPU APB1_PEN: UART1 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_PEN_I2C0_Pos          (7UL)                     /*!< TT_PPU APB1_PEN: I2C0 (Bit 7)                         */
#define TT_PPU_APB1_PEN_I2C0_Msk          (0x80UL)                  /*!< TT_PPU APB1_PEN: I2C0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_PEN_I2C1_Pos          (8UL)                     /*!< TT_PPU APB1_PEN: I2C1 (Bit 8)                         */
#define TT_PPU_APB1_PEN_I2C1_Msk          (0x100UL)                 /*!< TT_PPU APB1_PEN: I2C1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_PEN_SENT4_Pos         (9UL)                     /*!< TT_PPU APB1_PEN: SENT4 (Bit 9)                        */
#define TT_PPU_APB1_PEN_SENT4_Msk         (0x200UL)                 /*!< TT_PPU APB1_PEN: SENT4 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_PEN_SENT5_Pos         (10UL)                    /*!< TT_PPU APB1_PEN: SENT5 (Bit 10)                       */
#define TT_PPU_APB1_PEN_SENT5_Msk         (0x400UL)                 /*!< TT_PPU APB1_PEN: SENT5 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_PEN_FTM4_Pos          (11UL)                    /*!< TT_PPU APB1_PEN: FTM4 (Bit 11)                        */
#define TT_PPU_APB1_PEN_FTM4_Msk          (0x800UL)                 /*!< TT_PPU APB1_PEN: FTM4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_PEN_FTM5_Pos          (12UL)                    /*!< TT_PPU APB1_PEN: FTM5 (Bit 12)                        */
#define TT_PPU_APB1_PEN_FTM5_Msk          (0x1000UL)                /*!< TT_PPU APB1_PEN: FTM5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB1_PEN_IOM_Pos           (13UL)                    /*!< TT_PPU APB1_PEN: IOM (Bit 13)                         */
#define TT_PPU_APB1_PEN_IOM_Msk           (0x2000UL)                /*!< TT_PPU APB1_PEN: IOM (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB1_PEN_SENT2_Pos         (14UL)                    /*!< TT_PPU APB1_PEN: SENT2 (Bit 14)                       */
#define TT_PPU_APB1_PEN_SENT2_Msk         (0x4000UL)                /*!< TT_PPU APB1_PEN: SENT2 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB1_PEN_SENT3_Pos         (15UL)                    /*!< TT_PPU APB1_PEN: SENT3 (Bit 15)                       */
#define TT_PPU_APB1_PEN_SENT3_Msk         (0x8000UL)                /*!< TT_PPU APB1_PEN: SENT3 (Bitfield-Mask: 0x01)          */
/* =======================================================  APB2_PEN  ======================================================== */
#define TT_PPU_APB2_PEN_CAN0_Pos          (0UL)                     /*!< TT_PPU APB2_PEN: CAN0 (Bit 0)                         */
#define TT_PPU_APB2_PEN_CAN0_Msk          (0x1UL)                   /*!< TT_PPU APB2_PEN: CAN0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_PEN_CAN1_Pos          (1UL)                     /*!< TT_PPU APB2_PEN: CAN1 (Bit 1)                         */
#define TT_PPU_APB2_PEN_CAN1_Msk          (0x2UL)                   /*!< TT_PPU APB2_PEN: CAN1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_PEN_CAN2_Pos          (2UL)                     /*!< TT_PPU APB2_PEN: CAN2 (Bit 2)                         */
#define TT_PPU_APB2_PEN_CAN2_Msk          (0x4UL)                   /*!< TT_PPU APB2_PEN: CAN2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_PEN_CAN3_Pos          (3UL)                     /*!< TT_PPU APB2_PEN: CAN3 (Bit 3)                         */
#define TT_PPU_APB2_PEN_CAN3_Msk          (0x8UL)                   /*!< TT_PPU APB2_PEN: CAN3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_PEN_I3C0_Pos          (4UL)                     /*!< TT_PPU APB2_PEN: I3C0 (Bit 4)                         */
#define TT_PPU_APB2_PEN_I3C0_Msk          (0x10UL)                  /*!< TT_PPU APB2_PEN: I3C0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_PEN_GPIO0_Pos         (5UL)                     /*!< TT_PPU APB2_PEN: GPIO0 (Bit 5)                        */
#define TT_PPU_APB2_PEN_GPIO0_Msk         (0x20UL)                  /*!< TT_PPU APB2_PEN: GPIO0 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_PEN_GPIO1_Pos         (6UL)                     /*!< TT_PPU APB2_PEN: GPIO1 (Bit 6)                        */
#define TT_PPU_APB2_PEN_GPIO1_Msk         (0x40UL)                  /*!< TT_PPU APB2_PEN: GPIO1 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_PEN_GPIO2_Pos         (7UL)                     /*!< TT_PPU APB2_PEN: GPIO2 (Bit 7)                        */
#define TT_PPU_APB2_PEN_GPIO2_Msk         (0x80UL)                  /*!< TT_PPU APB2_PEN: GPIO2 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_PEN_FTM2_Pos          (8UL)                     /*!< TT_PPU APB2_PEN: FTM2 (Bit 8)                         */
#define TT_PPU_APB2_PEN_FTM2_Msk          (0x100UL)                 /*!< TT_PPU APB2_PEN: FTM2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_PEN_FTM3_Pos          (9UL)                     /*!< TT_PPU APB2_PEN: FTM3 (Bit 9)                         */
#define TT_PPU_APB2_PEN_FTM3_Msk          (0x200UL)                 /*!< TT_PPU APB2_PEN: FTM3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB2_PEN_ADC_SENSOR_Pos    (10UL)                    /*!< TT_PPU APB2_PEN: ADC_SENSOR (Bit 10)                  */
#define TT_PPU_APB2_PEN_ADC_SENSOR_Msk    (0x400UL)                 /*!< TT_PPU APB2_PEN: ADC_SENSOR (Bitfield-Mask: 0x01)     */
#define TT_PPU_APB2_PEN_UART2_Pos         (11UL)                    /*!< TT_PPU APB2_PEN: UART2 (Bit 11)                       */
#define TT_PPU_APB2_PEN_UART2_Msk         (0x800UL)                 /*!< TT_PPU APB2_PEN: UART2 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_PEN_UART3_Pos         (12UL)                    /*!< TT_PPU APB2_PEN: UART3 (Bit 12)                       */
#define TT_PPU_APB2_PEN_UART3_Msk         (0x1000UL)                /*!< TT_PPU APB2_PEN: UART3 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB2_PEN_SMU_Pos           (13UL)                    /*!< TT_PPU APB2_PEN: SMU (Bit 13)                         */
#define TT_PPU_APB2_PEN_SMU_Msk           (0x2000UL)                /*!< TT_PPU APB2_PEN: SMU (Bitfield-Mask: 0x01)            */
#define TT_PPU_APB2_PEN_GTM_REG_Pos       (14UL)                    /*!< TT_PPU APB2_PEN: GTM_REG (Bit 14)                     */
#define TT_PPU_APB2_PEN_GTM_REG_Msk       (0x4000UL)                /*!< TT_PPU APB2_PEN: GTM_REG (Bitfield-Mask: 0x01)        */
#define TT_PPU_APB2_PEN_INTM_Pos          (15UL)                    /*!< TT_PPU APB2_PEN: INTM (Bit 15)                        */
#define TT_PPU_APB2_PEN_INTM_Msk          (0x8000UL)                /*!< TT_PPU APB2_PEN: INTM (Bitfield-Mask: 0x01)           */
/* =======================================================  APB3_PEN  ======================================================== */
#define TT_PPU_APB3_PEN_CAN4_Pos          (0UL)                     /*!< TT_PPU APB3_PEN: CAN4 (Bit 0)                         */
#define TT_PPU_APB3_PEN_CAN4_Msk          (0x1UL)                   /*!< TT_PPU APB3_PEN: CAN4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_PEN_CAN5_Pos          (1UL)                     /*!< TT_PPU APB3_PEN: CAN5 (Bit 1)                         */
#define TT_PPU_APB3_PEN_CAN5_Msk          (0x2UL)                   /*!< TT_PPU APB3_PEN: CAN5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_PEN_CAN6_Pos          (2UL)                     /*!< TT_PPU APB3_PEN: CAN6 (Bit 2)                         */
#define TT_PPU_APB3_PEN_CAN6_Msk          (0x4UL)                   /*!< TT_PPU APB3_PEN: CAN6 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_PEN_CAN7_Pos          (3UL)                     /*!< TT_PPU APB3_PEN: CAN7 (Bit 3)                         */
#define TT_PPU_APB3_PEN_CAN7_Msk          (0x8UL)                   /*!< TT_PPU APB3_PEN: CAN7 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_PEN_FTM0_Pos          (4UL)                     /*!< TT_PPU APB3_PEN: FTM0 (Bit 4)                         */
#define TT_PPU_APB3_PEN_FTM0_Msk          (0x10UL)                  /*!< TT_PPU APB3_PEN: FTM0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_PEN_FTM1_Pos          (5UL)                     /*!< TT_PPU APB3_PEN: FTM1 (Bit 5)                         */
#define TT_PPU_APB3_PEN_FTM1_Msk          (0x20UL)                  /*!< TT_PPU APB3_PEN: FTM1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_PEN_GPIO3_Pos         (6UL)                     /*!< TT_PPU APB3_PEN: GPIO3 (Bit 6)                        */
#define TT_PPU_APB3_PEN_GPIO3_Msk         (0x40UL)                  /*!< TT_PPU APB3_PEN: GPIO3 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_PEN_GPIO4_Pos         (7UL)                     /*!< TT_PPU APB3_PEN: GPIO4 (Bit 7)                        */
#define TT_PPU_APB3_PEN_GPIO4_Msk         (0x80UL)                  /*!< TT_PPU APB3_PEN: GPIO4 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_PEN_SENT0_Pos         (8UL)                     /*!< TT_PPU APB3_PEN: SENT0 (Bit 8)                        */
#define TT_PPU_APB3_PEN_SENT0_Msk         (0x100UL)                 /*!< TT_PPU APB3_PEN: SENT0 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_PEN_SENT1_Pos         (9UL)                     /*!< TT_PPU APB3_PEN: SENT1 (Bit 9)                        */
#define TT_PPU_APB3_PEN_SENT1_Msk         (0x200UL)                 /*!< TT_PPU APB3_PEN: SENT1 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_PEN_TRIG_MUX_Pos      (10UL)                    /*!< TT_PPU APB3_PEN: TRIG_MUX (Bit 10)                    */
#define TT_PPU_APB3_PEN_TRIG_MUX_Msk      (0x400UL)                 /*!< TT_PPU APB3_PEN: TRIG_MUX (Bitfield-Mask: 0x01)       */
#define TT_PPU_APB3_PEN_I2S0_Pos          (11UL)                    /*!< TT_PPU APB3_PEN: I2S0 (Bit 11)                        */
#define TT_PPU_APB3_PEN_I2S0_Msk          (0x800UL)                 /*!< TT_PPU APB3_PEN: I2S0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB3_PEN_SENT6_Pos         (12UL)                    /*!< TT_PPU APB3_PEN: SENT6 (Bit 12)                       */
#define TT_PPU_APB3_PEN_SENT6_Msk         (0x1000UL)                /*!< TT_PPU APB3_PEN: SENT6 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_PEN_SENT7_Pos         (13UL)                    /*!< TT_PPU APB3_PEN: SENT7 (Bit 13)                       */
#define TT_PPU_APB3_PEN_SENT7_Msk         (0x2000UL)                /*!< TT_PPU APB3_PEN: SENT7 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB3_PEN_STCU_Pos           (14UL)                    /*!< TT_PPU APB3_PEN: STU (Bit 14)                         */
#define TT_PPU_APB3_PEN_STCU_Msk           (0x4000UL)                /*!< TT_PPU APB3_PEN: STU (Bitfield-Mask: 0x01)            */
/* =======================================================  APB4_PEN  ======================================================== */
#define TT_PPU_APB4_PEN_LIN0_Pos          (0UL)                     /*!< TT_PPU APB4_PEN: LIN0 (Bit 0)                         */
#define TT_PPU_APB4_PEN_LIN0_Msk          (0x1UL)                   /*!< TT_PPU APB4_PEN: LIN0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_PEN_LIN1_Pos          (1UL)                     /*!< TT_PPU APB4_PEN: LIN1 (Bit 1)                         */
#define TT_PPU_APB4_PEN_LIN1_Msk          (0x2UL)                   /*!< TT_PPU APB4_PEN: LIN1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_PEN_LIN2_Pos          (2UL)                     /*!< TT_PPU APB4_PEN: LIN2 (Bit 2)                         */
#define TT_PPU_APB4_PEN_LIN2_Msk          (0x4UL)                   /*!< TT_PPU APB4_PEN: LIN2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_PEN_LIN3_Pos          (3UL)                     /*!< TT_PPU APB4_PEN: LIN3 (Bit 3)                         */
#define TT_PPU_APB4_PEN_LIN3_Msk          (0x8UL)                   /*!< TT_PPU APB4_PEN: LIN3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_PEN_LIN4_Pos          (4UL)                     /*!< TT_PPU APB4_PEN: LIN4 (Bit 4)                         */
#define TT_PPU_APB4_PEN_LIN4_Msk          (0x10UL)                  /*!< TT_PPU APB4_PEN: LIN4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_PEN_LIN5_Pos          (5UL)                     /*!< TT_PPU APB4_PEN: LIN5 (Bit 5)                         */
#define TT_PPU_APB4_PEN_LIN5_Msk          (0x20UL)                  /*!< TT_PPU APB4_PEN: LIN5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_PEN_LIN6_Pos          (6UL)                     /*!< TT_PPU APB4_PEN: LIN6 (Bit 6)                         */
#define TT_PPU_APB4_PEN_LIN6_Msk          (0x40UL)                  /*!< TT_PPU APB4_PEN: LIN6 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_PEN_LIN7_Pos          (7UL)                     /*!< TT_PPU APB4_PEN: LIN7 (Bit 7)                         */
#define TT_PPU_APB4_PEN_LIN7_Msk          (0x80UL)                  /*!< TT_PPU APB4_PEN: LIN7 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB4_PEN_EIM_Pos           (8UL)                     /*!< TT_PPU APB4_PEN: EIM (Bit 8)                          */
#define TT_PPU_APB4_PEN_EIM_Msk           (0x100UL)                 /*!< TT_PPU APB4_PEN: EIM (Bitfield-Mask: 0x01)            */
/* =======================================================  AHB0_PEN  ======================================================== */
#define TT_PPU_AHB0_PEN_SPI0_Pos          (0UL)                     /*!< TT_PPU AHB0_PEN: SPI0 (Bit 0)                         */
#define TT_PPU_AHB0_PEN_SPI0_Msk          (0x1UL)                   /*!< TT_PPU AHB0_PEN: SPI0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_PEN_SPI2_Pos          (1UL)                     /*!< TT_PPU AHB0_PEN: SPI2 (Bit 1)                         */
#define TT_PPU_AHB0_PEN_SPI2_Msk          (0x2UL)                   /*!< TT_PPU AHB0_PEN: SPI2 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_PEN_DMAC0_Pos         (2UL)                     /*!< TT_PPU AHB0_PEN: DMAC0 (Bit 2)                        */
#define TT_PPU_AHB0_PEN_DMAC0_Msk         (0x4UL)                   /*!< TT_PPU AHB0_PEN: DMAC0 (Bitfield-Mask: 0x01)          */
#define TT_PPU_AHB0_PEN_DMAC1_Pos         (3UL)                     /*!< TT_PPU AHB0_PEN: DMAC1 (Bit 3)                        */
#define TT_PPU_AHB0_PEN_DMAC1_Msk         (0x8UL)                   /*!< TT_PPU AHB0_PEN: DMAC1 (Bitfield-Mask: 0x01)          */
#define TT_PPU_AHB0_PEN_DMAC2_Pos         (4UL)                     /*!< TT_PPU AHB0_PEN: DMAC2 (Bit 4)                        */
#define TT_PPU_AHB0_PEN_DMAC2_Msk         (0x10UL)                  /*!< TT_PPU AHB0_PEN: DMAC2 (Bitfield-Mask: 0x01)          */
#define TT_PPU_AHB0_PEN_DMAC3_Pos         (5UL)                     /*!< TT_PPU AHB0_PEN: DMAC3 (Bit 5)                        */
#define TT_PPU_AHB0_PEN_DMAC3_Msk         (0x20UL)                  /*!< TT_PPU AHB0_PEN: DMAC3 (Bitfield-Mask: 0x01)          */
#define TT_PPU_AHB0_PEN_ADC_Pos           (6UL)                     /*!< TT_PPU AHB0_PEN: ADC (Bit 6)                          */
#define TT_PPU_AHB0_PEN_ADC_Msk           (0x40UL)                  /*!< TT_PPU AHB0_PEN: ADC (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB0_PEN_SPI4_Pos          (7UL)                     /*!< TT_PPU AHB0_PEN: SPI4 (Bit 7)                         */
#define TT_PPU_AHB0_PEN_SPI4_Msk          (0x80UL)                  /*!< TT_PPU AHB0_PEN: SPI4 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB0_PEN_DFCU_REG_Pos      (8UL)                     /*!< TT_PPU AHB0_PEN: DFCU_REG (Bit 8)                     */
#define TT_PPU_AHB0_PEN_DFCU_REG_Msk      (0x100UL)                 /*!< TT_PPU AHB0_PEN: DFCU_REG (Bitfield-Mask: 0x01)       */
#define TT_PPU_AHB0_PEN_SPI6_Pos          (9UL)                     /*!< TT_PPU AHB0_PEN: SPI6 (Bit 9)                         */
#define TT_PPU_AHB0_PEN_SPI6_Msk          (0x200UL)                 /*!< TT_PPU AHB0_PEN: SPI6 (Bitfield-Mask: 0x01)           */
/* =======================================================  AHB1_PEN  ======================================================== */
#define TT_PPU_AHB1_PEN_SPI1_Pos          (0UL)                     /*!< TT_PPU AHB1_PEN: SPI1 (Bit 0)                         */
#define TT_PPU_AHB1_PEN_SPI1_Msk          (0x1UL)                   /*!< TT_PPU AHB1_PEN: SPI1 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_PEN_SPI3_Pos          (1UL)                     /*!< TT_PPU AHB1_PEN: SPI3 (Bit 1)                         */
#define TT_PPU_AHB1_PEN_SPI3_Msk          (0x2UL)                   /*!< TT_PPU AHB1_PEN: SPI3 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_PEN_FCU_Pos           (2UL)                     /*!< TT_PPU AHB1_PEN: FCU (Bit 2)                          */
#define TT_PPU_AHB1_PEN_FCU_Msk           (0x4UL)                   /*!< TT_PPU AHB1_PEN: FCU (Bitfield-Mask: 0x01)            */
#define TT_PPU_AHB1_PEN_EMAC_Pos          (3UL)                     /*!< TT_PPU AHB1_PEN: EMAC (Bit 3)                         */
#define TT_PPU_AHB1_PEN_EMAC_Msk          (0x8UL)                   /*!< TT_PPU AHB1_PEN: EMAC (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_PEN_SPI5_Pos          (4UL)                     /*!< TT_PPU AHB1_PEN: SPI5 (Bit 4)                         */
#define TT_PPU_AHB1_PEN_SPI5_Msk          (0x10UL)                  /*!< TT_PPU AHB1_PEN: SPI5 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_PEN_PDB0_Pos          (6UL)                     /*!< TT_PPU AHB1_PEN: PDB0 (Bit 6)                         */
#define TT_PPU_AHB1_PEN_PDB0_Msk          (0x40UL)                  /*!< TT_PPU AHB1_PEN: PDB0 (Bitfield-Mask: 0x01)           */
#define TT_PPU_AHB1_PEN_PDB1_Pos          (7UL)                     /*!< TT_PPU AHB1_PEN: PDB1 (Bit 7)                         */
#define TT_PPU_AHB1_PEN_PDB1_Msk          (0x80UL)                  /*!< TT_PPU AHB1_PEN: PDB1 (Bitfield-Mask: 0x01)           */
/* =======================================================  APB5_PEN  ======================================================== */
#define TT_PPU_APB5_PEN_LIN8_Pos          (0UL)                     /*!< TT_PPU APB5_PEN: LIN8 (Bit 0)                         */
#define TT_PPU_APB5_PEN_LIN8_Msk          (0x1UL)                   /*!< TT_PPU APB5_PEN: LIN8 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_PEN_LIN9_Pos          (1UL)                     /*!< TT_PPU APB5_PEN: LIN9 (Bit 1)                         */
#define TT_PPU_APB5_PEN_LIN9_Msk          (0x2UL)                   /*!< TT_PPU APB5_PEN: LIN9 (Bitfield-Mask: 0x01)           */
#define TT_PPU_APB5_PEN_LIN10_Pos         (2UL)                     /*!< TT_PPU APB5_PEN: LIN10 (Bit 2)                        */
#define TT_PPU_APB5_PEN_LIN10_Msk         (0x4UL)                   /*!< TT_PPU APB5_PEN: LIN10 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_PEN_LIN11_Pos         (3UL)                     /*!< TT_PPU APB5_PEN: LIN11 (Bit 3)                        */
#define TT_PPU_APB5_PEN_LIN11_Msk         (0x8UL)                   /*!< TT_PPU APB5_PEN: LIN11 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_PEN_LIN12_Pos         (4UL)                     /*!< TT_PPU APB5_PEN: LIN12 (Bit 4)                        */
#define TT_PPU_APB5_PEN_LIN12_Msk         (0x10UL)                  /*!< TT_PPU APB5_PEN: LIN12 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_PEN_LIN13_Pos         (5UL)                     /*!< TT_PPU APB5_PEN: LIN13 (Bit 5)                        */
#define TT_PPU_APB5_PEN_LIN13_Msk         (0x20UL)                  /*!< TT_PPU APB5_PEN: LIN13 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_PEN_LIN14_Pos         (6UL)                     /*!< TT_PPU APB5_PEN: LIN14 (Bit 6)                        */
#define TT_PPU_APB5_PEN_LIN14_Msk         (0x40UL)                  /*!< TT_PPU APB5_PEN: LIN14 (Bitfield-Mask: 0x01)          */
#define TT_PPU_APB5_PEN_LIN15_Pos         (7UL)                     /*!< TT_PPU APB5_PEN: LIN15 (Bit 7)                        */
#define TT_PPU_APB5_PEN_LIN15_Msk         (0x80UL)                  /*!< TT_PPU APB5_PEN: LIN15 (Bitfield-Mask: 0x01)          */
/* =======================================================  AHB4_PEN  ======================================================== */
#define TT_PPU_AHB4_PEN_GTM_AXIS_Pos      (0UL)                     /*!< TT_PPU AHB4_PEN: GTM_AXIS (Bit 0)                     */
#define TT_PPU_AHB4_PEN_GTM_AXIS_Msk      (0x1UL)                   /*!< TT_PPU AHB4_PEN: GTM_AXIS (Bitfield-Mask: 0x01)       */
/* =======================================================  PPU_SUPV  ======================================================== */
#define TT_PPU_PPU_SUPV_SUPV_Pos          (0UL)                     /*!< TT_PPU PPU_SUPV: SUPV (Bit 0)                         */
#define TT_PPU_PPU_SUPV_SUPV_Msk          (0x1UL)                   /*!< TT_PPU PPU_SUPV: SUPV (Bitfield-Mask: 0x01)           */
/* ========================================================  ID_REG  ========================================================= */
#define TT_PPU_ID_REG_B_VERSION_Pos       (0UL)                     /*!< TT_PPU ID_REG: B_VERSION (Bit 0)                      */
#define TT_PPU_ID_REG_B_VERSION_Msk       (0xfUL)                   /*!< TT_PPU ID_REG: B_VERSION (Bitfield-Mask: 0x0f)        */
#define TT_PPU_ID_REG_M_VERSION_Pos       (4UL)                     /*!< TT_PPU ID_REG: M_VERSION (Bit 4)                      */
#define TT_PPU_ID_REG_M_VERSION_Msk       (0xf0UL)                  /*!< TT_PPU ID_REG: M_VERSION (Bitfield-Mask: 0x0f)        */
#define TT_PPU_ID_REG_REG_WIDTH_Pos       (8UL)                     /*!< TT_PPU ID_REG: REG_WIDTH (Bit 8)                      */
#define TT_PPU_ID_REG_REG_WIDTH_Msk       (0xff00UL)                /*!< TT_PPU ID_REG: REG_WIDTH (Bitfield-Mask: 0xff)        */
#define TT_PPU_ID_REG_M_NUM_Pos           (16UL)                    /*!< TT_PPU ID_REG: M_NUM (Bit 16)                         */
#define TT_PPU_ID_REG_M_NUM_Msk           (0xffff0000UL)            /*!< TT_PPU ID_REG: M_NUM (Bitfield-Mask: 0xffff)          */



#ifdef __cplusplus
}
#endif

#endif /* A8V2E_PPU_H */
