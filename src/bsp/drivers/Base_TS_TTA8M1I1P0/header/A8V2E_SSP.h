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
#ifndef A8V2E_SSP_H
#define A8V2E_SSP_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_SSP_VENDOR_ID_H                     1541
#define A8V2E_SSP_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_SSP_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_SSP_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_SSP_SW_MAJOR_VERSION_H              1
#define A8V2E_SSP_SW_MINOR_VERSION_H              1
#define A8V2E_SSP_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_SSP.h and TT_Common.h file version check */
#if (A8V2E_SSP_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_SSP.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_SSP_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_SSP_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_SSP_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_SSP.h and TT_Common.h are different"
#endif
#if ((A8V2E_SSP_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_SSP_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_SSP_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_SSP.h and TT_Common.h are different"
#endif


 
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
/**
  * @brief Synchronous Serial Port Device 0 (TT_SSP0)
  */

typedef struct {                                /*!< (@ 0x40180000) TT_SSP0 Structure                                      */
  __IOM uint32  CR0;                          /*!< (@ 0x00000000) Control Register 0. Selects the serial clock
                                                                    rate, bus type, and data size.                             */
  __IOM uint32  CR1;                          /*!< (@ 0x00000004) Control Register 1. Selects master/slave and
                                                                    other modes.                                               */
  __IOM uint32  DR;                           /*!< (@ 0x00000008) Data Register. Writes fill the transmit FIFO,
                                                                    and reads empty the receive FIFO.                          */
  __IM  uint32  SR;                           /*!< (@ 0x0000000C) Status Register                                            */
  __IOM uint32  CPSR;                         /*!< (@ 0x00000010) Clock Prescale Register                                    */
  __IOM uint32  IMSC;                         /*!< (@ 0x00000014) Interrupt Mask Set and Clear Register                      */
  __IM  uint32  RIS;                          /*!< (@ 0x00000018) Raw Interrupt Status Register                              */
  __IM  uint32  MIS;                          /*!< (@ 0x0000001C) Masked Interrupt Status Register                           */
  __OM  uint32  ICR;                          /*!< (@ 0x00000020) SSPICR Interrupt Clear Register                            */
  __IOM uint32  DMACR;                        /*!< (@ 0x00000024) SSP0 DMA control register                                  */
  __IOM uint32  SPIMODE;                      /*!< (@ 0x00000028) Slave Sampling Clock Mode                                  */
  __IOM uint32  SPIMDLY;                      /*!< (@ 0x0000002C) Delay.                                                     */
  __IOM uint32  SPIMCT;                       /*!< (@ 0x00000030) Delay.                                                     */
  __IOM uint32  SPICS;                        /*!< (@ 0x00000034) Cs.                                                        */
  __IOM uint32  SPIMDLY2;                     /*!< (@ 0x00000038) Delay2.                                                    */
  __IOM uint32  SPIMDUTY;                     /*!< (@ 0x0000003C) Duty.                                                      */
  __IOM uint32  SPIRXFIFO;                    /*!< (@ 0x00000040) Duty.                                                      */
  __IOM uint32  SPITXFIFO;                    /*!< (@ 0x00000044) Duty.                                                      */
  __IOM uint32  SPICONF;                      /*!< (@ 0x00000048) Spi conf.                                                  */
  __IOM uint32  SPIFLAG;                      /*!< (@ 0x0000004C) Flag.                                                      */
  __IOM uint32  SPI_SUPV;                     /*!< (@ 0x00000050) Supervisor.                                                */  
  __IM  uint32  RESERVED[995];
  __IM  uint32  PIDR0;                        /*!< (@ 0x00000FE0) Peripheral ID 0 Register                                   */
  __IM  uint32  PIDR1;                        /*!< (@ 0x00000FE4) Peripheral ID 1 Register                                   */
  __IM  uint32  PIDR2;                        /*!< (@ 0x00000FE8) Peripheral ID 2 Register                                   */
  __IM  uint32  PIDR3;                        /*!< (@ 0x00000FEC) Peripheral ID 3 Register                                   */
  __IM  uint32  CIDR0;                        /*!< (@ 0x00000FF0) Component ID 0 Register                                    */
  __IM  uint32  CIDR1;                        /*!< (@ 0x00000FF4) Component ID 1 Register                                    */
  __IM  uint32  CIDR2;                        /*!< (@ 0x00000FF8) Component ID 2 Register                                    */
  __IM  uint32  CIDR3;                        /*!< (@ 0x00000FFC) Component ID 3 Register                                    */
} SSP_RegType;                             /*!< Size = 4096 (0x1000)                                                      */


/** Number of instances of the SSP module. */
#define SSP_INSTANCE_COUNT                     (8u)

/* SSP - Peripheral instance base addresses */
/** Peripheral SSP0 base address */
#define TT_SSP0_BASE            0x40180000UL
/** Peripheral SSP0 base pointer */
#define TT_SSP0                 ((SSP_RegType*)       TT_SSP0_BASE)

/** Peripheral SSP1 base address */
#define TT_SSP1_BASE            0x40190000UL
/** Peripheral SSP1 base pointer */
#define TT_SSP1                 ((SSP_RegType*)       TT_SSP1_BASE)

/** Peripheral SSP2 base address */
#define TT_SSP2_BASE            0x40181000UL
/** Peripheral SSP2 base pointer */
#define TT_SSP2                 ((SSP_RegType*)       TT_SSP2_BASE)

/** Peripheral SSP3 base address */
#define TT_SSP3_BASE            0x40191000UL
/** Peripheral SSP3 base pointer */
#define TT_SSP3                 ((SSP_RegType*)       TT_SSP3_BASE)

/** Peripheral SSP4 base address */
#define TT_SSP4_BASE            0x40187000UL
/** Peripheral SSP4 base pointer */
#define TT_SSP4                 ((SSP_RegType*)       TT_SSP4_BASE)

/** Peripheral SSP5 base address */
#define TT_SSP5_BASE            0x40196000UL
/** Peripheral SSP5 base pointer */
#define TT_SSP5                 ((SSP_RegType*)       TT_SSP5_BASE)

/** Peripheral SSP6 base address */
#define TT_SSP6_BASE            0x40189000UL
/** Peripheral SSP6 base pointer */
#define TT_SSP6                 ((SSP_RegType*)       TT_SSP6_BASE)

/** Peripheral SSP7 base address */
#define TT_SSP7_BASE            0x4019A000UL
/** Peripheral SSP7 base pointer */
#define TT_SSP7                 ((SSP_RegType*)       TT_SSP7_BASE)

#define TT_SPI_INIT   {TT_SSP0, TT_SSP1, TT_SSP2, TT_SSP3, TT_SSP4, TT_SSP5, TT_SSP6, TT_SSP7}
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* =========================================================================================================================== */
/* ================                                        TT_SSP0                                        ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR0  ========================================================== */
#define TT_SSP_CR0_DSS_Pos           (0UL)                     /*!< TT_SSP0 CR0: DSS (Bit 0)                          */
#define TT_SSP_CR0_DSS_Msk           (0x1fUL)                    /*!< TT_SSP0 CR0: DSS (Bitfield-Mask: 0x1f)            */
#define TT_SSP_CR0_FRF_Pos           (5UL)                      /*!< TT_SSP0 CR0: FRF (Bit 4)                          */
#define TT_SSP_CR0_FRF_Msk           (0x60UL)                   /*!< TT_SSP0 CR0: FRF (Bitfield-Mask: 0x03)            */
#define TT_SSP_CR0_CPOL_Pos          (7UL)                      /*!< TT_SSP0 CR0: CPOL (Bit 6)                         */
#define TT_SSP_CR0_CPOL_Msk          (0x80UL)                   /*!< TT_SSP0 CR0: CPOL (Bitfield-Mask: 0x01)           */
#define TT_SSP_CR0_CPHA_Pos          (8UL)                      /*!< TT_SSP0 CR0: CPHA (Bit 7)                         */
#define TT_SSP_CR0_CPHA_Msk          (0x100UL)                   /*!< TT_SSP0 CR0: CPHA (Bitfield-Mask: 0x01)           */
#define TT_SSP_CR0_SCR_Pos           (9UL)                      /*!< TT_SSP0 CR0: SCR (Bit 8)                          */
#define TT_SSP_CR0_SCR_Msk           (0x1fe00UL)                 /*!< TT_SSP0 CR0: SCR (Bitfield-Mask: 0xff)            */
/* ==========================================================  CR1  ========================================================== */
#define TT_SSP_CR1_LBM_Pos           (0UL)                     /*!< TT_SSP0 CR1: LBM (Bit 0)                          */
#define TT_SSP_CR1_LBM_Msk           (0x1UL)                   /*!< TT_SSP0 CR1: LBM (Bitfield-Mask: 0x01)            */
#define TT_SSP_CR1_SSE_Pos           (1UL)                     /*!< TT_SSP0 CR1: SSE (Bit 1)                          */
#define TT_SSP_CR1_SSE_Msk           (0x2UL)                   /*!< TT_SSP0 CR1: SSE (Bitfield-Mask: 0x01)            */
#define TT_SSP_CR1_MS_Pos            (2UL)                     /*!< TT_SSP0 CR1: MS (Bit 2)                           */
#define TT_SSP_CR1_MS_Msk            (0x4UL)                   /*!< TT_SSP0 CR1: MS (Bitfield-Mask: 0x01)             */
#define TT_SSP_CR1_SOD_Pos           (3UL)                     /*!< TT_SSP0 CR1: SOD (Bit 3)                          */
#define TT_SSP_CR1_SOD_Msk           (0x8UL)                   /*!< TT_SSP0 CR1: SOD (Bitfield-Mask: 0x01)            */
#define TT_SSP_CR1_REN_Pos           (4UL)                     /*!< TT_SSP0 CR1: REN (Bit 4)                          */
#define TT_SSP_CR1_REN_Msk           (0x10UL)                  /*!< TT_SSP0 CR1: REN (Bitfield-Mask: 0x01)            */
#define TT_SSP_CR1_CS_DEGLITCH_EN_Pos (5UL)                    /*!< TT_SSP0 CR1: CS_DEGLITCH_EN (Bit 5)               */
#define TT_SSP_CR1_CS_DEGLITCH_EN_Msk (0x20UL)                 /*!< TT_SSP0 CR1: CS_DEGLITCH_EN (Bitfield-Mask: 0x01) */
#define TT_SSP_CR1_SPH0_B2B_EN_Pos   (9UL)                     /*!< TT_SSP0 CR1: SPH0_B2B_EN (Bit 9)                  */
#define TT_SSP_CR1_SPH0_B2B_EN_Msk   (0x200UL)                 /*!< TT_SSP0 CR1: SPH0_B2B_EN (Bitfield-Mask: 0x01)    */
#define TT_SSP_CR1_TXD_FORWARD_EN_Pos (10UL)                   /*!< TT_SSP0 CR1: TXD_FORWARD_EN (Bit 10)              */
#define TT_SSP_CR1_TXD_FORWARD_EN_Msk (0x400UL)                /*!< TT_SSP0 CR1: TXD_FORWARD_EN (Bitfield-Mask: 0x01) */
#define TT_SSP_CR1_RXD_DLY_CNT_Pos   (11UL)                    /*!< TT_SSP0 CR1: RXD_DLY_CNT (Bit 11)                 */
#define TT_SSP_CR1_RXD_DLY_CNT_Msk   (0x1800UL)                /*!< TT_SSP0 CR1: RXD_DLY_CNT (Bitfield-Mask: 0x03)    */
#define TT_SSP_CR1_TXD_DLY_CNT_Pos   (13UL)                    /*!< TT_SSP0 CR1: TXD_DLY_CNT (Bit 13)                 */
#define TT_SSP_CR1_TXD_DLY_CNT_Msk   (0xe000UL)                /*!< TT_SSP0 CR1: TXD_DLY_CNT (Bitfield-Mask: 0x07)    */
/* ==========================================================  DR  =========================================================== */
#define TT_SSP_DR_DATA_Pos           (0UL)                     /*!< TT_SSP0 DR: DATA (Bit 0)                          */
#define TT_SSP_DR_DATA_Msk           (0xffffffffUL)                /*!< TT_SSP0 DR: DATA (Bitfield-Mask: 0xffffffff)          */
/* ==========================================================  SR  =========================================================== */
#define TT_SSP_SR_TFE_Pos            (0UL)                     /*!< TT_SSP0 SR: TFE (Bit 0)                           */
#define TT_SSP_SR_TFE_Msk            (0x1UL)                   /*!< TT_SSP0 SR: TFE (Bitfield-Mask: 0x01)             */
#define TT_SSP_SR_TNF_Pos            (1UL)                     /*!< TT_SSP0 SR: TNF (Bit 1)                           */
#define TT_SSP_SR_TNF_Msk            (0x2UL)                   /*!< TT_SSP0 SR: TNF (Bitfield-Mask: 0x01)             */
#define TT_SSP_SR_RNE_Pos            (2UL)                     /*!< TT_SSP0 SR: RNE (Bit 2)                           */
#define TT_SSP_SR_RNE_Msk            (0x4UL)                   /*!< TT_SSP0 SR: RNE (Bitfield-Mask: 0x01)             */
#define TT_SSP_SR_RFF_Pos            (3UL)                     /*!< TT_SSP0 SR: RFF (Bit 3)                           */
#define TT_SSP_SR_RFF_Msk            (0x8UL)                   /*!< TT_SSP0 SR: RFF (Bitfield-Mask: 0x01)             */
#define TT_SSP_SR_BSY_Pos            (4UL)                     /*!< TT_SSP0 SR: BSY (Bit 4)                           */
#define TT_SSP_SR_BSY_Msk            (0x10UL)                  /*!< TT_SSP0 SR: BSY (Bitfield-Mask: 0x01)             */
/* =========================================================  CPSR  ========================================================== */
#define TT_SSP_CPSR_CPSDVSR_Pos      (0UL)                     /*!< TT_SSP0 CPSR: CPSDVSR (Bit 0)                     */
#define TT_SSP_CPSR_CPSDVSR_Msk      (0xffUL)                  /*!< TT_SSP0 CPSR: CPSDVSR (Bitfield-Mask: 0xff)       */
/* =========================================================  IMSC  ========================================================== */
#define TT_SSP_IMSC_RORIM_Pos        (0UL)                     /*!< TT_SSP0 IMSC: RORIM (Bit 0)                       */
#define TT_SSP_IMSC_RORIM_Msk        (0x1UL)                   /*!< TT_SSP0 IMSC: RORIM (Bitfield-Mask: 0x01)         */
#define TT_SSP_IMSC_RTIM_Pos         (1UL)                     /*!< TT_SSP0 IMSC: RTIM (Bit 1)                        */
#define TT_SSP_IMSC_RTIM_Msk         (0x2UL)                   /*!< TT_SSP0 IMSC: RTIM (Bitfield-Mask: 0x01)          */
#define TT_SSP_IMSC_RXIM_Pos         (2UL)                     /*!< TT_SSP0 IMSC: RXIM (Bit 2)                        */
#define TT_SSP_IMSC_RXIM_Msk         (0x4UL)                   /*!< TT_SSP0 IMSC: RXIM (Bitfield-Mask: 0x01)          */
#define TT_SSP_IMSC_TXIM_Pos         (3UL)                     /*!< TT_SSP0 IMSC: TXIM (Bit 3)                        */
#define TT_SSP_IMSC_TXIM_Msk         (0x8UL)                   /*!< TT_SSP0 IMSC: TXIM (Bitfield-Mask: 0x01)          */
#define TT_SSP_IMSC_RX_TRIG_EN_Pos   (4UL)                     /*!< TT_SSP0 IMSC: RX_trig_en (Bit 4)                  */
#define TT_SSP_IMSC_RX_TRIG_EN_Msk   (0x10UL)                  /*!< TT_SSP0 IMSC: RX_trig_en (Bitfield-Mask: 0x01)    */
#define TT_SSP_IMSC_TX_TRIG_EN_Pos   (5UL)                     /*!< TT_SSP0 IMSC: TX_trig_en (Bit 5)                  */
#define TT_SSP_IMSC_TX_TRIG_EN_Msk   (0x20UL)                  /*!< TT_SSP0 IMSC: TX_trig_en (Bitfield-Mask: 0x01)    */
#define TT_SSP_IMSC_TXOVIM_Pos       (6UL)          		   /*!< TT_SSP0 IMSC: TXOVIM (Bit 6)                  */
#define TT_SSP_IMSC_TXOVIM_Msk   	 (0x40UL)                  /*!< TT_SSP0 IMSC: TXOVIM (Bitfield-Mask: 0x01)    */
#define TT_SSP_IMSC_RXUDIM_Pos   	 (7UL)                     /*!< TT_SSP0 IMSC: RXUDIM (Bit 7)                  */
#define TT_SSP_IMSC_RXUDIM_Msk   	 (0x80UL)                  /*!< TT_SSP0 IMSC: RXUDIM (Bitfield-Mask: 0x01)    */
#define TT_SSP_IMSC_TXUDIM_Pos   	 (8UL)                     /*!< TT_SSP0 IMSC: TXUDIM (Bit 8)                  */
#define TT_SSP_IMSC_TXUDIM_Msk   	 (0x100UL)                 /*!< TT_SSP0 IMSC: TXUDIM (Bitfield-Mask: 0x01)    */
/* ==========================================================  RIS  ========================================================== */
#define TT_SSP_RIS_RORRIS_Pos        (0UL)                     /*!< TT_SSP0 RIS: RORRIS (Bit 0)                       */
#define TT_SSP_RIS_RORRIS_Msk        (0x1UL)                   /*!< TT_SSP0 RIS: RORRIS (Bitfield-Mask: 0x01)         */
#define TT_SSP_RIS_RTRIS_Pos         (1UL)                     /*!< TT_SSP0 RIS: RTRIS (Bit 1)                        */
#define TT_SSP_RIS_RTRIS_Msk         (0x2UL)                   /*!< TT_SSP0 RIS: RTRIS (Bitfield-Mask: 0x01)          */
#define TT_SSP_RIS_RXRIS_Pos         (2UL)                     /*!< TT_SSP0 RIS: RXRIS (Bit 2)                        */
#define TT_SSP_RIS_RXRIS_Msk         (0x4UL)                   /*!< TT_SSP0 RIS: RXRIS (Bitfield-Mask: 0x01)          */
#define TT_SSP_RIS_TXRIS_Pos         (3UL)                     /*!< TT_SSP0 RIS: TXRIS (Bit 3)                        */
#define TT_SSP_RIS_TXRIS_Msk         (0x8UL)                   /*!< TT_SSP0 RIS: TXRIS (Bitfield-Mask: 0x01)          */
#define TT_SSP_RIS_TXOVRIS_Pos       (4UL)                     /*!< TT_SSP0 RIS: TXOVRIS (Bit 4)                        */
#define TT_SSP_RIS_TXOVRIS_Msk       (0x10UL)                  /*!< TT_SSP0 RIS: TXOVRIS (Bitfield-Mask: 0x01)          */
#define TT_SSP_RIS_RXUDRIS_Pos       (5UL)                     /*!< TT_SSP0 RIS: RXUDRIS (Bit 5)                        */
#define TT_SSP_RIS_RXUDRIS_Msk       (0x20UL)                  /*!< TT_SSP0 RIS: RXUDRIS (Bitfield-Mask: 0x01)          */
#define TT_SSP_RIS_TXUDRIS_Pos       (6UL)                     /*!< TT_SSP0 RIS: TXUDRIS (Bit 6)                        */
#define TT_SSP_RIS_TXUDRIS_Msk       (0x40UL)                  /*!< TT_SSP0 RIS: TXUDRIS (Bitfield-Mask: 0x01)          */
/* ==========================================================  MIS  ========================================================== */
#define TT_SSP_MIS_RORMIS_Pos        (0UL)                     /*!< TT_SSP0 MIS: RORMIS (Bit 0)                       */
#define TT_SSP_MIS_RORMIS_Msk        (0x1UL)                   /*!< TT_SSP0 MIS: RORMIS (Bitfield-Mask: 0x01)         */
#define TT_SSP_MIS_RTMIS_Pos         (1UL)                     /*!< TT_SSP0 MIS: RTMIS (Bit 1)                        */
#define TT_SSP_MIS_RTMIS_Msk         (0x2UL)                   /*!< TT_SSP0 MIS: RTMIS (Bitfield-Mask: 0x01)          */
#define TT_SSP_MIS_RXMIS_Pos         (2UL)                     /*!< TT_SSP0 MIS: RXMIS (Bit 2)                        */
#define TT_SSP_MIS_RXMIS_Msk         (0x4UL)                   /*!< TT_SSP0 MIS: RXMIS (Bitfield-Mask: 0x01)          */
#define TT_SSP_MIS_TXMIS_Pos         (3UL)                     /*!< TT_SSP0 MIS: TXMIS (Bit 3)                        */
#define TT_SSP_MIS_TXMIS_Msk         (0x8UL)                   /*!< TT_SSP0 MIS: TXMIS (Bitfield-Mask: 0x01)          */
#define TT_SSP_MIS_TXOVMIS_Pos       (4UL)                     /*!< TT_SSP0 MIS: TXOVMIS  (Bit 4)                        */
#define TT_SSP_MIS_TXOVMIS_Msk       (0x10UL)                  /*!< TT_SSP0 MIS: TXOVMIS  (Bitfield-Mask: 0x01)          */
#define TT_SSP_MIS_RXUDMIS_Pos       (5UL)                     /*!< TT_SSP0 MIS: RXUDMIS  (Bit 5)                        */
#define TT_SSP_MIS_RXUDMIS_Msk       (0x20UL)                  /*!< TT_SSP0 MIS: RXUDMIS  (Bitfield-Mask: 0x01)          */
#define TT_SSP_MIS_TXUDMIS_Pos       (6UL)                     /*!< TT_SSP0 MIS: TXUDMIS  (Bit 6)                        */
#define TT_SSP_MIS_TXUDMIS_Msk       (0x40UL)                  /*!< TT_SSP0 MIS: TXUDMIS  (Bitfield-Mask: 0x01)          */
/* ==========================================================  ICR  ========================================================== */
#define TT_SSP_ICR_RORIC_Pos         (0UL)                     /*!< TT_SSP0 ICR: RORIC (Bit 0)                        */
#define TT_SSP_ICR_RORIC_Msk         (0x1UL)                   /*!< TT_SSP0 ICR: RORIC (Bitfield-Mask: 0x01)          */
#define TT_SSP_ICR_RTIC_Pos          (1UL)                     /*!< TT_SSP0 ICR: RTIC (Bit 1)                         */
#define TT_SSP_ICR_RTIC_Msk          (0x2UL)                   /*!< TT_SSP0 ICR: RTIC (Bitfield-Mask: 0x01)           */
#define TT_SSP_ICR_TXOVIC_Pos        (2UL)                     /*!< TT_SSP0 ICR: TXOVIC  (Bit 2)                        */
#define TT_SSP_ICR_TXOVIC_Msk        (0x4UL)                   /*!< TT_SSP0 ICR: TXOVIC (Bitfield-Mask: 0x01)          */
#define TT_SSP_ICR_RXUDIC_Pos        (3UL)                     /*!< TT_SSP0 ICR: RXUDIC  (Bit 3)                         */
#define TT_SSP_ICR_RXUDIC_Msk        (0x8UL)                   /*!< TT_SSP0 ICR: RXUDIC  (Bitfield-Mask: 0x01)           */
#define TT_SSP_ICR_TXUDIC_Pos        (4UL)                     /*!< TT_SSP0 ICR: TXUDIC  (Bit 4)                        */
#define TT_SSP_ICR_TXUDIC_Msk        (0x10UL)                  /*!< TT_SSP0 ICR: TXUDIC (Bitfield-Mask: 0x01)          */
/* =========================================================  DMACR  ========================================================= */
#define TT_SSP_DMACR_RXDMAE_Pos      (0UL)                     /*!< TT_SSP0 DMACR: RXDMAE (Bit 0)                     */
#define TT_SSP_DMACR_RXDMAE_Msk      (0x1UL)                   /*!< TT_SSP0 DMACR: RXDMAE (Bitfield-Mask: 0x01)       */
#define TT_SSP_DMACR_TXDMAE_Pos      (1UL)                     /*!< TT_SSP0 DMACR: TXDMAE (Bit 1)                     */
#define TT_SSP_DMACR_TXDMAE_Msk      (0x2UL)                   /*!< TT_SSP0 DMACR: TXDMAE (Bitfield-Mask: 0x01)       */
/* ========================================================  SPIMODE  ======================================================== */
#define TT_SSP_SPIMODE_INCLOCK_SAMPLING_Pos (0UL)              /*!< TT_SSP0 SPIMODE: INCLOCK_SAMPLING (Bit 0)         */
#define TT_SSP_SPIMODE_INCLOCK_SAMPLING_Msk (0x1UL)            /*!< TT_SSP0 SPIMODE: INCLOCK_SAMPLING (Bitfield-Mask: 0x01) */
/* ========================================================  SPIMDLY  ======================================================== */
#define TT_SSP_SPIMDLY_CLK_CS_Pos    (0UL)                     /*!< TT_SSP0 SPIMDLY: CLK_CS (Bit 0)                   */
#define TT_SSP_SPIMDLY_CLK_CS_Msk    (0xffUL)                  /*!< TT_SSP0 SPIMDLY: CLK_CS (Bitfield-Mask: 0xff)     */
/* ========================================================  SPIMCT  ========================================================= */
#define TT_SSP_SPIMCT_DLYEN_Pos      (0UL)                     /*!< TT_SSP0 SPIMCT: DLYEN (Bit 0)                     */
#define TT_SSP_SPIMCT_DLYEN_Msk      (0x1UL)                   /*!< TT_SSP0 SPIMCT: DLYEN (Bitfield-Mask: 0x01)       */
#define TT_SSP_SPIMCT_TRAIL_EN_Pos   (1UL)                     /*!< TT_SSP0 SPIMCT: TRAIL_EN (Bit 1)                  */
#define TT_SSP_SPIMCT_TRAIL_EN_Msk   (0x2UL)                   /*!< TT_SSP0 SPIMCT: TRAIL_EN (Bitfield-Mask: 0x01)    */
#define TT_SSP_SPIMCT_MLAST_Pos      (2UL)                     /*!< TT_SSP0 SPIMCT: MLAST (Bit 2)                     */
#define TT_SSP_SPIMCT_MLAST_Msk      (0x4UL)                   /*!< TT_SSP0 SPIMCT: MLAST (Bitfield-Mask: 0x01)       */
#define TT_SSP_SPIMCT_MDUTY_EN_Pos   (3UL)                     /*!< TT_SSP0 SPIMCT: MDUTY_EN (Bit 3)                  */
#define TT_SSP_SPIMCT_MDUTY_EN_Msk   (0x8UL)                   /*!< TT_SSP0 SPIMCT: MDUTY_EN (Bitfield-Mask: 0x01)    */
#define TT_SSP_SPIMCT_IDLE_EN_Pos    (4UL)                     /*!< TT_SSP0 SPIMCT: IDLE_EN (Bit 4)                   */
#define TT_SSP_SPIMCT_IDLE_EN_Msk    (0x10UL)                  /*!< TT_SSP0 SPIMCT: IDLE_EN (Bitfield-Mask: 0x01)     */
#define TT_SSP_SPIMCT_DATA_TRAIL_EN_Pos   (5UL)                /*!< TT_SSP0 SPIMCT: DATA_TRAIL_EN (Bit 5)             */
#define TT_SSP_SPIMCT_DATA_TRAIL_EN_Msk   (0x20UL)             /*!< TT_SSP0 SPIMCT: DATA_TRAIL_EN (Bitfield-Mask: 0x01) */
#define TT_SSP_SPIMCT_SOFT_LAST_EN_Pos    (6UL)                /*!< TT_SSP0 SPIMCT: SOFT_LAST_EN (Bit 6)              */
#define TT_SSP_SPIMCT_SOFT_LAST_EN_Msk    (0x40UL)             /*!< TT_SSP0 SPIMCT: SOFT_LAST_EN (Bitfield-Mask: 0x01)*/
#define TT_SSP_SPIMCT_PRE_DATA_Pos        (8UL)                /*!< TT_SSP0 SPIMCT: PRE_DATA (Bit 8)                  */
#define TT_SSP_SPIMCT_PRE_DATA_Msk        (0xffff00UL)         /*!< TT_SSP0 SPIMCT: PRE_DATA (Bitfield-Mask: 0xffff)  */
/* =========================================================  SPICS  ========================================================= */
#define TT_SSP_SPICS_ACTIVE_Pos      (0UL)                     /*!< TT_SSP0 SPICS: ACTIVE (Bit 0)                     */
#define TT_SSP_SPICS_ACTIVE_Msk      (0x1UL)                   /*!< TT_SSP0 SPICS: ACTIVE (Bitfield-Mask: 0x01)       */
#define TT_SSP_SPICS_LINE0_Pos       (1UL)                     /*!< TT_SSP0 SPICS: LINE0 (Bit 1)                      */
#define TT_SSP_SPICS_LINE0_Msk       (0x2UL)                   /*!< TT_SSP0 SPICS: LINE0 (Bitfield-Mask: 0x01)        */
#define TT_SSP_SPICS_LINE1_Pos       (2UL)                     /*!< TT_SSP0 SPICS: LINE1 (Bit 2)                      */
#define TT_SSP_SPICS_LINE1_Msk       (0x4UL)                   /*!< TT_SSP0 SPICS: LINE1 (Bitfield-Mask: 0x01)        */
#define TT_SSP_SPICS_LINE2_Pos       (3UL)                     /*!< TT_SSP0 SPICS: LINE2 (Bit 3)                      */
#define TT_SSP_SPICS_LINE2_Msk       (0x8UL)                   /*!< TT_SSP0 SPICS: LINE2 (Bitfield-Mask: 0x01)        */
#define TT_SSP_SPICS_LINE3_Pos       (4UL)                     /*!< TT_SSP0 SPICS: LINE3 (Bit 4)                      */
#define TT_SSP_SPICS_LINE3_Msk       (0x10UL)                  /*!< TT_SSP0 SPICS: LINE3 (Bitfield-Mask: 0x01)        */
/* =======================================================  SPIMDLY2  ======================================================== */
#define TT_SSP_SPIMDLY2_CS_CLK_Pos   (0UL)                     /*!< TT_SSP0 SPIMDLY2: CS_CLK (Bit 0)                  */
#define TT_SSP_SPIMDLY2_CS_CLK_Msk   (0xffUL)                  /*!< TT_SSP0 SPIMDLY2: CS_CLK (Bitfield-Mask: 0x01)    */
#define TT_SSP_SPIMDLY2_IDLE_DELAY_Pos (8UL)                   /*!< TT_SSP0 SPIMDLY2: IDLE_DELAY (Bit 8)              */
#define TT_SSP_SPIMDLY2_IDLE_DELAY_Msk (0xff00UL)              /*!< TT_SSP0 SPIMDLY2: IDLE_DELAY (Bitfield-Mask: 0xff) */
/* =======================================================  SPIMDUTY  ======================================================== */
#define TT_SSP_SPIMDUTY_CLKSET_Pos   (0UL)                     /*!< TT_SSP0 SPIMDUTY: CLKSET (Bit 0)                  */
#define TT_SSP_SPIMDUTY_CLKSET_Msk   (0xffUL)                  /*!< TT_SSP0 SPIMDUTY: CLKSET (Bitfield-Mask: 0xff)    */
#define TT_SSP_SPIMDUTY_CLKHOLD_Pos  (8UL)                     /*!< TT_SSP0 SPIMDUTY: CLKHOLD (Bit 8)                 */
#define TT_SSP_SPIMDUTY_CLKHOLD_Msk  (0xff00UL)                /*!< TT_SSP0 SPIMDUTY: CLKHOLD (Bitfield-Mask: 0xff)   */
/* =======================================================  SPIRXFIFO  ======================================================= */
#define TT_SSP_SPIRXFIFO_RXFIFOINT_Pos (0UL)                   /*!< TT_SSP0 SPIRXFIFO: RXFIFOINT (Bit 0)              */
#define TT_SSP_SPIRXFIFO_RXFIFOINT_Msk (0x3fUL)                /*!< TT_SSP0 SPIRXFIFO: RXFIFOINT (Bitfield-Mask: 0x3f) */
#define TT_SSP_SPIRXFIFO_RXFIFOLEVEL_Pos (6UL)                 /*!< TT_SSP0 SPIRXFIFO: RXFIFOLEVEL (Bit 6)            */
#define TT_SSP_SPIRXFIFO_RXFIFOLEVEL_Msk (0xfc0UL)             /*!< TT_SSP0 SPIRXFIFO: RXFIFOLEVEL (Bitfield-Mask: 0x3f) */
/* =======================================================  SPITXFIFO  ======================================================= */
#define TT_SSP_SPITXFIFO_TXFIFOINT_Pos (0UL)                   /*!< TT_SSP0 SPITXFIFO: TXFIFOINT (Bit 0)              */
#define TT_SSP_SPITXFIFO_TXFIFOINT_Msk (0x3fUL)                /*!< TT_SSP0 SPITXFIFO: TXFIFOINT (Bitfield-Mask: 0x3f) */
#define TT_SSP_SPITXFIFO_TXFIFOLEVEL_Pos (6UL)                 /*!< TT_SSP0 SPITXFIFO: TXFIFOLEVEL (Bit 6)            */
#define TT_SSP_SPITXFIFO_TXFIFOLEVEL_Msk (0xfc0UL)             /*!< TT_SSP0 SPITXFIFO: TXFIFOLEVEL (Bitfield-Mask: 0x3f) */
/* ========================================================  SPICONF  ======================================================== */
#define TT_SSP_SPICONF_PARITY_EN_Pos (0UL)                     /*!< TT_SSP0 SPICONF: PARITY_EN (Bit 0)                */
#define TT_SSP_SPICONF_PARITY_EN_Msk (0x1UL)                   /*!< TT_SSP0 SPICONF: PARITY_EN (Bitfield-Mask: 0x01)  */
#define TT_SSP_SPICONF_PARITYP_Pos   (1UL)                     /*!< TT_SSP0 SPICONF: PARITYP (Bit 1)                  */
#define TT_SSP_SPICONF_PARITYP_Msk   (0x2UL)                   /*!< TT_SSP0 SPICONF: PARITYP (Bitfield-Mask: 0x01)    */
#define TT_SSP_SPICONF_PAREEN_Pos    (2UL)                     /*!< TT_SSP0 SPICONF: PAREEN (Bit 2)                   */
#define TT_SSP_SPICONF_PAREEN_Msk    (0x4UL)                   /*!< TT_SSP0 SPICONF: PAREEN (Bitfield-Mask: 0x01)     */
#define TT_SSP_SPICONF_MSB_Pos       (3UL)                     /*!< TT_SSP0 SPICONF: MSB (Bit 3)                      */
#define TT_SSP_SPICONF_MSB_Msk       (0x8UL)                   /*!< TT_SSP0 SPICONF: MSB (Bitfield-Mask: 0x01)        */
#define TT_SSP_SPICONF_SRF_Pos       (4UL)                     /*!< TT_SSP0 SPICONF: SRF (Bit 4)                      */
#define TT_SSP_SPICONF_SRF_Msk       (0x10UL)                  /*!< TT_SSP0 SPICONF: SRF (Bitfield-Mask: 0x01)        */
#define TT_SSP_SPICONF_RPV_Pos       (5UL)                     /*!< TT_SSP0 SPICONF: RPV (Bit 5)                      */
#define TT_SSP_SPICONF_RPV_Msk       (0x20UL)                  /*!< TT_SSP0 SPICONF: RPV (Bitfield-Mask: 0x01)        */
/* ========================================================  SPIFLAG  ======================================================== */
#define TT_SSP_SPIFLAG_PARE_Pos       (0UL)                    /*!< TT_SSP0 SPIFLAG: PARE (Bit 0)                     */
#define TT_SSP_SPIFLAG_PARE_Msk       (0x1UL)                  /*!< TT_SSP0 SPIFLAG: PARE (Bitfield-Mask: 0x01)       */
/* =======================================================  SPI_SUPV  ======================================================== */
#define TT_SSP_SPI_SUPV_SPISV_Pos    (0UL)                     /*!< TT_SSP0 SPI_SUPV: SPISV (Bit 0)                   */
#define TT_SSP_SPI_SUPV_SPISV_Msk    (0x1UL)                   /*!< TT_SSP0 SPI_SUPV: SPISV (Bitfield-Mask: 0x01)     */
/* =========================================================  PIDR0  ========================================================= */
/* =========================================================  PIDR1  ========================================================= */
/* =========================================================  PIDR2  ========================================================= */
/* =========================================================  PIDR3  ========================================================= */
/* =========================================================  CIDR0  ========================================================= */
/* =========================================================  CIDR1  ========================================================= */
/* =========================================================  CIDR2  ========================================================= */
/* =========================================================  CIDR3  ========================================================= */



/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif

