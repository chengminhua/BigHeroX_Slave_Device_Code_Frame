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
#ifndef A8V2E_QSPI_H
#define A8V2E_QSPI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_QSPI_VENDOR_ID_H                     1541
#define A8V2E_QSPI_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_QSPI_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_QSPI_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_QSPI_SW_MAJOR_VERSION_H              1
#define A8V2E_QSPI_SW_MINOR_VERSION_H              1
#define A8V2E_QSPI_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_QSPI.h and TT_Common.h file version check */
#if (A8V2E_QSPI_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_QSPI.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_QSPI_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_QSPI_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_QSPI_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_QSPI.h and TT_Common.h are different"
#endif
#if ((A8V2E_QSPI_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_QSPI_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_QSPI_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_QSPI.h and TT_Common.h are different"
#endif


/**
  * @brief Serial Peripheral Interface 0 (master) (TT_QSPI0)
  */

typedef struct {                                /*!< (@ 0xA0000000) TT_QSPI0 Structure                                     */
  __IOM uint32_t  CTRLR0;                       /*!< (@ 0x00000000) Control Register 0                                         */
  __IOM uint32_t  CTRLR1;                       /*!< (@ 0x00000004) Control Register 1                                         */
  __IOM uint32_t  SSIENR;                       /*!< (@ 0x00000008) Enable Register                                            */
  __IOM uint32_t  MWCR;                         /*!< (@ 0x0000000C) Microwire Control Register                                 */
  __IOM uint32_t  SER;                          /*!< (@ 0x00000010) Slave Enable Register                                      */
  __IOM uint32_t  BAUDR;                        /*!< (@ 0x00000014) Baud Rate Select                                           */
  __IOM uint32_t  TXFTLR;                       /*!< (@ 0x00000018) Transmit FIFO Threshold Level                              */
  __IOM uint32_t  RXFTLR;                       /*!< (@ 0x0000001C) Receive FIFO Threshold Level                               */
  __IOM uint32_t  TXFLR;                        /*!< (@ 0x00000020) Transmit FIFO Level Register                               */
  __IOM uint32_t  RXFLR;                        /*!< (@ 0x00000024) Receive FIFO Level Register                                */
  __IM  uint32_t  SR;                           /*!< (@ 0x00000028) Status Register                                            */
  __IOM uint32_t  IMR;                          /*!< (@ 0x0000002C) Interrupt Mask Register                                    */
  __IM  uint32_t  ISR;                          /*!< (@ 0x00000030) Interrupt Status Register                                  */
  __IM  uint32_t  RISR;                         /*!< (@ 0x00000034) Raw Interrupt Status Register                              */
  __IM  uint32_t  TXEICR;                       /*!< (@ 0x00000038) Transmit FIFO Error Interrupt Clear Register.              */
  __IM  uint32_t  RXOICR;                       /*!< (@ 0x0000003C) Receive FIFO Overflow Interrupt Clear Register             */
  __IM  uint32_t  RXUICR;                       /*!< (@ 0x00000040) Receive FIFO Underflow Interrupt Clear Register            */
  __IM  uint32_t  MSTICR;                       /*!< (@ 0x00000044) Multi-Master Interrupt Clear Register                      */
  __IM  uint32_t  ICR;                          /*!< (@ 0x00000048) Interrupt Clear Register                                   */
  __IOM uint32_t  DMACR;                        /*!< (@ 0x0000004C) DMA Control Register                                       */
  __IOM uint32_t  AXIAWLEN;                     /*!< (@ 0x00000050) Destination Burst Length.                                  */
  __IOM uint32_t  AXIARLEN;                     /*!< (@ 0x00000054) Source Burst Length                                        */
  __IM  uint32_t  IDR;                          /*!< (@ 0x00000058) Identification Register                                    */
  __IM  uint32_t  SSIC_VERSION_ID;              /*!< (@ 0x0000005C) DWC_ssi component version                                  */
  __IOM uint32_t  DR[36];                       /*!< (@ 0x00000060) Data Register                                              */
  __IOM uint32_t  RX_SAMPLE_DELAY;              /*!< (@ 0x000000F0) RX Sample Delay Register                                   */
  __IOM uint32_t  SPI_CTRLR0;                  /*!< (@ 0x000000F4) qspi Control Register                                      */
  __IOM uint32_t  DDR_DRIVE_EDGE;               /*!< (@ 0x000000F8) This Register is valid only when SSIC_HAS_DDR
                                                                    is equal to 1.                                             */
  __IOM uint32  XIP_MODE_BITS;                /*!< (@ 0x000000FC) XIP Mode bits                                              */
  __IOM uint32  XIP_INCR_INST;                /*!< (@ 0x00000100) XIP INCR transfer opcode                                   */
  __IOM uint32  XIP_WRAP_INST;                /*!< (@ 0x00000104) XIP WRAP transfer opcode                                   */
  __IM  uint32  RESERVED0[3];
  __IOM uint32  XIP_CNT_TIME_OUT;             /*!< (@ 0x00000114) XIP time out register for continuous transfers             */
  __IM  uint32  RESERVED1[2];
  __IOM uint32  SPIDR;                        /*!< (@ 0x00000120) SPI Device Register                                        */
  __IOM uint32  SPIAR;                        /*!< (@ 0x00000124) SPI Device Address Register.                               */
  __IOM uint32  AXIAR0;                       /*!< (@ 0x00000128) AXI Address Register 0.                                    */
  __IM  uint32  RESERVED2;
  __IOM uint32  AXIECR;                       /*!< (@ 0x00000130) AXI Master Error Interrupt Clear Register.                 */
  __IOM uint32  DONECR;                       /*!< (@ 0x00000134) Transfer Done Clear Interrupt Clear Register.              */
} Qspi_RegType;                             /*!< Size = 312 (0x138)                                                            */


#define TT_QSPI0_BASE           0xA0000000UL

/** Peripheral QSPI0 base pointer */
#define TT_QSPI0       ((Qspi_RegType *)TT_QSPI0_BASE)
/* =========================================================================================================================== */
/* ================                                        TT_QSPI                                        ================ */
/* =========================================================================================================================== */

/* ========================================================  CTRLR0  ========================================================= */
#define TT_QSPI_CTRLR0_DFS_Pos        (0UL)                     /*!< TT_QSPI CTRLR0: DFS (Bit 0)                       */
#define TT_QSPI_CTRLR0_DFS_Msk        (0x1fUL)                  /*!< TT_QSPI CTRLR0: DFS (Bitfield-Mask: 0x1f)         */
#define TT_QSPI_CTRLR0_FRF_Pos        (6UL)                     /*!< TT_QSPI CTRLR0: FRF (Bit 6)                       */
#define TT_QSPI_CTRLR0_FRF_Msk        (0xc0UL)                  /*!< TT_QSPI CTRLR0: FRF (Bitfield-Mask: 0x03)         */
#define TT_QSPI_CTRLR0_SCPH_Pos       (8UL)                     /*!< TT_QSPI CTRLR0: SCPH (Bit 8)                      */
#define TT_QSPI_CTRLR0_SCPH_Msk       (0x100UL)                 /*!< TT_QSPI CTRLR0: SCPH (Bitfield-Mask: 0x01)        */
#define TT_QSPI_CTRLR0_SCPOL_Pos      (9UL)                     /*!< TT_QSPI CTRLR0: SCPOL (Bit 9)                     */
#define TT_QSPI_CTRLR0_SCPOL_Msk      (0x200UL)                 /*!< TT_QSPI CTRLR0: SCPOL (Bitfield-Mask: 0x01)       */
#define TT_QSPI_CTRLR0_TMOD_Pos       (10UL)                    /*!< TT_QSPI CTRLR0: TMOD (Bit 10)                     */
#define TT_QSPI_CTRLR0_TMOD_Msk       (0xc00UL)                 /*!< TT_QSPI CTRLR0: TMOD (Bitfield-Mask: 0x03)        */
#define TT_QSPI_CTRLR0_SLV_OE_Pos     (12UL)                    /*!< TT_QSPI CTRLR0: SLV_OE (Bit 12)                   */
#define TT_QSPI_CTRLR0_SLV_OE_Msk     (0x1000UL)                /*!< TT_QSPI CTRLR0: SLV_OE (Bitfield-Mask: 0x01)      */
#define TT_QSPI_CTRLR0_SRL_Pos        (13UL)                    /*!< TT_QSPI CTRLR0: SRL (Bit 13)                      */
#define TT_QSPI_CTRLR0_SRL_Msk        (0x2000UL)                /*!< TT_QSPI CTRLR0: SRL (Bitfield-Mask: 0x01)         */
#define TT_QSPI_CTRLR0_SSTE_Pos       (14UL)                    /*!< TT_QSPI CTRLR0: SSTE (Bit 14)                     */
#define TT_QSPI_CTRLR0_SSTE_Msk       (0x4000UL)                /*!< TT_QSPI CTRLR0: SSTE (Bitfield-Mask: 0x01)        */
#define TT_QSPI_CTRLR0_CFS_Pos        (16UL)                    /*!< TT_QSPI CTRLR0: CFS (Bit 16)                      */
#define TT_QSPI_CTRLR0_CFS_Msk        (0xf0000UL)               /*!< TT_QSPI CTRLR0: CFS (Bitfield-Mask: 0x0f)         */
#define TT_QSPI_CTRLR0_SPI_FRF_Pos    (22UL)                    /*!< TT_QSPI CTRLR0: SPI_FRF (Bit 22)                  */
#define TT_QSPI_CTRLR0_SPI_FRF_Msk    (0xc00000UL)              /*!< TT_QSPI CTRLR0: SPI_FRF (Bitfield-Mask: 0x03)     */
#define TT_QSPI_CTRLR0_SPI_HYPERBUS_EN_Pos (24UL)               /*!< TT_QSPI CTRLR0: SPI_HYPERBUS_EN (Bit 24)          */
#define TT_QSPI_CTRLR0_SPI_HYPERBUS_EN_Msk (0x1000000UL)        /*!< TT_QSPI CTRLR0: SPI_HYPERBUS_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_CTRLR0_SPI_DWS_EN_Pos (25UL)                    /*!< TT_QSPI CTRLR0: SPI_DWS_EN (Bit 25)               */
#define TT_QSPI_CTRLR0_SPI_DWS_EN_Msk (0x2000000UL)             /*!< TT_QSPI CTRLR0: SPI_DWS_EN (Bitfield-Mask: 0x01)  */
#define TT_QSPI_CTRLR0_SSI_IS_MST_Pos (31UL)                    /*!< TT_QSPI CTRLR0: SSI_IS_MST (Bit 31)               */
#define TT_QSPI_CTRLR0_SSI_IS_MST_Msk (0x80000000UL)            /*!< TT_QSPI CTRLR0: SSI_IS_MST (Bitfield-Mask: 0x01)  */
/* ========================================================  CTRLR1  ========================================================= */
#define TT_QSPI_CTRLR1_NDF_Pos        (0UL)                     /*!< TT_QSPI CTRLR1: NDF (Bit 0)                       */
#define TT_QSPI_CTRLR1_NDF_Msk        (0xffffUL)                /*!< TT_QSPI CTRLR1: NDF (Bitfield-Mask: 0xffff)       */
/* ========================================================  SSIENR  ========================================================= */
#define TT_QSPI_SSIENR_SSIC_EN_Pos    (0UL)                     /*!< TT_QSPI SSIENR: SSIC_EN (Bit 0)                   */
#define TT_QSPI_SSIENR_SSIC_EN_Msk    (0x1UL)                   /*!< TT_QSPI SSIENR: SSIC_EN (Bitfield-Mask: 0x01)     */
/* =========================================================  MWCR  ========================================================== */
#define TT_QSPI_MWCR_MHS_Pos          (2UL)                     /*!< TT_QSPI MWCR: MHS (Bit 2)                         */
#define TT_QSPI_MWCR_MHS_Msk          (0x4UL)                   /*!< TT_QSPI MWCR: MHS (Bitfield-Mask: 0x01)           */
#define TT_QSPI_MWCR_MDD_Pos          (1UL)                     /*!< TT_QSPI MWCR: MDD (Bit 1)                         */
#define TT_QSPI_MWCR_MDD_Msk          (0x2UL)                   /*!< TT_QSPI MWCR: MDD (Bitfield-Mask: 0x01)           */
#define TT_QSPI_MWCR_MWMOD_Pos        (0UL)                     /*!< TT_QSPI MWCR: MWMOD (Bit 0)                       */
#define TT_QSPI_MWCR_MWMOD_Msk        (0x1UL)                   /*!< TT_QSPI MWCR: MWMOD (Bitfield-Mask: 0x01)         */
/* ==========================================================  SER  ========================================================== */
/* =========================================================  BAUDR  ========================================================= */
#define TT_QSPI_BAUDR_SCKDV_Pos       (1UL)                     /*!< TT_QSPI BAUDR: SCKDV (Bit 1)                      */
#define TT_QSPI_BAUDR_SCKDV_Msk       (0xfffeUL)                /*!< TT_QSPI BAUDR: SCKDV (Bitfield-Mask: 0x7fff)      */
/* ========================================================  TXFTLR  ========================================================= */
/* ========================================================  RXFTLR  ========================================================= */
/* =========================================================  TXFLR  ========================================================= */
/* =========================================================  RXFLR  ========================================================= */
/* ==========================================================  SR  =========================================================== */
#define TT_QSPI_SR_CMPLTD_DF_Pos      (15UL)                    /*!< TT_QSPI SR: CMPLTD_DF (Bit 15)                    */
#define TT_QSPI_SR_CMPLTD_DF_Msk      (0xffff8000UL)            /*!< TT_QSPI SR: CMPLTD_DF (Bitfield-Mask: 0x1ffff)    */
#define TT_QSPI_SR_DCOL_Pos           (6UL)                     /*!< TT_QSPI SR: DCOL (Bit 6)                          */
#define TT_QSPI_SR_DCOL_Msk           (0x40UL)                  /*!< TT_QSPI SR: DCOL (Bitfield-Mask: 0x01)            */
#define TT_QSPI_SR_TXE_Pos            (5UL)                     /*!< TT_QSPI SR: TXE (Bit 5)                           */
#define TT_QSPI_SR_TXE_Msk            (0x20UL)                  /*!< TT_QSPI SR: TXE (Bitfield-Mask: 0x01)             */
#define TT_QSPI_SR_RFF_Pos            (4UL)                     /*!< TT_QSPI SR: RFF (Bit 4)                           */
#define TT_QSPI_SR_RFF_Msk            (0x10UL)                  /*!< TT_QSPI SR: RFF (Bitfield-Mask: 0x01)             */
#define TT_QSPI_SR_RFNE_Pos           (3UL)                     /*!< TT_QSPI SR: RFNE (Bit 3)                          */
#define TT_QSPI_SR_RFNE_Msk           (0x8UL)                   /*!< TT_QSPI SR: RFNE (Bitfield-Mask: 0x01)            */
#define TT_QSPI_SR_TFE_Pos            (2UL)                     /*!< TT_QSPI SR: TFE (Bit 2)                           */
#define TT_QSPI_SR_TFE_Msk            (0x4UL)                   /*!< TT_QSPI SR: TFE (Bitfield-Mask: 0x01)             */
#define TT_QSPI_SR_TFNF_Pos           (1UL)                     /*!< TT_QSPI SR: TFNF (Bit 1)                          */
#define TT_QSPI_SR_TFNF_Msk           (0x2UL)                   /*!< TT_QSPI SR: TFNF (Bitfield-Mask: 0x01)            */
#define TT_QSPI_SR_BUSY_Pos           (0UL)                     /*!< TT_QSPI SR: BUSY (Bit 0)                          */
#define TT_QSPI_SR_BUSY_Msk           (0x1UL)                   /*!< TT_QSPI SR: BUSY (Bitfield-Mask: 0x01)            */
/* ==========================================================  IMR  ========================================================== */
#define TT_QSPI_IMR_DONEM_Pos         (11UL)                    /*!< TT_QSPI IMR: DONEM (Bit 11)                       */
#define TT_QSPI_IMR_DONEM_Msk         (0x800UL)                 /*!< TT_QSPI IMR: DONEM (Bitfield-Mask: 0x01)          */
#define TT_QSPI_IMR_SPITEM_Pos        (10UL)                    /*!< TT_QSPI IMR: SPITEM (Bit 10)                      */
#define TT_QSPI_IMR_SPITEM_Msk        (0x400UL)                 /*!< TT_QSPI IMR: SPITEM (Bitfield-Mask: 0x01)         */
#define TT_QSPI_IMR_AXIEM_Pos         (8UL)                     /*!< TT_QSPI IMR: AXIEM (Bit 8)                        */
#define TT_QSPI_IMR_AXIEM_Msk         (0x100UL)                 /*!< TT_QSPI IMR: AXIEM (Bitfield-Mask: 0x01)          */
#define TT_QSPI_IMR_TXUIM_Pos         (7UL)                     /*!< TT_QSPI IMR: TXUIM (Bit 7)                        */
#define TT_QSPI_IMR_TXUIM_Msk         (0x80UL)                  /*!< TT_QSPI IMR: TXUIM (Bitfield-Mask: 0x01)          */
#define TT_QSPI_IMR_XRXOIM_Pos        (6UL)                     /*!< TT_QSPI IMR: XRXOIM (Bit 6)                       */
#define TT_QSPI_IMR_XRXOIM_Msk        (0x40UL)                  /*!< TT_QSPI IMR: XRXOIM (Bitfield-Mask: 0x01)         */
#define TT_QSPI_IMR_MSTIM_Pos         (5UL)                     /*!< TT_QSPI IMR: MSTIM (Bit 5)                        */
#define TT_QSPI_IMR_MSTIM_Msk         (0x20UL)                  /*!< TT_QSPI IMR: MSTIM (Bitfield-Mask: 0x01)          */
#define TT_QSPI_IMR_RXFIM_Pos         (4UL)                     /*!< TT_QSPI IMR: RXFIM (Bit 4)                        */
#define TT_QSPI_IMR_RXFIM_Msk         (0x10UL)                  /*!< TT_QSPI IMR: RXFIM (Bitfield-Mask: 0x01)          */
#define TT_QSPI_IMR_RXOIM_Pos         (3UL)                     /*!< TT_QSPI IMR: RXOIM (Bit 3)                        */
#define TT_QSPI_IMR_RXOIM_Msk         (0x8UL)                   /*!< TT_QSPI IMR: RXOIM (Bitfield-Mask: 0x01)          */
#define TT_QSPI_IMR_RXUIM_Pos         (2UL)                     /*!< TT_QSPI IMR: RXUIM (Bit 2)                        */
#define TT_QSPI_IMR_RXUIM_Msk         (0x4UL)                   /*!< TT_QSPI IMR: RXUIM (Bitfield-Mask: 0x01)          */
#define TT_QSPI_IMR_TXOIM_Pos         (1UL)                     /*!< TT_QSPI IMR: TXOIM (Bit 1)                        */
#define TT_QSPI_IMR_TXOIM_Msk         (0x2UL)                   /*!< TT_QSPI IMR: TXOIM (Bitfield-Mask: 0x01)          */
#define TT_QSPI_IMR_TXEIM_Pos         (0UL)                     /*!< TT_QSPI IMR: TXEIM (Bit 0)                        */
#define TT_QSPI_IMR_TXEIM_Msk         (0x1UL)                   /*!< TT_QSPI IMR: TXEIM (Bitfield-Mask: 0x01)          */
/* ==========================================================  ISR  ========================================================== */
#define TT_QSPI_ISR_DONES_Pos         (11UL)                    /*!< TT_QSPI ISR: DONES (Bit 11)                       */
#define TT_QSPI_ISR_DONES_Msk         (0x800UL)                 /*!< TT_QSPI ISR: DONES (Bitfield-Mask: 0x01)          */
#define TT_QSPI_ISR_SPITES_Pos        (10UL)                    /*!< TT_QSPI ISR: SPITES (Bit 10)                      */
#define TT_QSPI_ISR_SPITES_Msk        (0x400UL)                 /*!< TT_QSPI ISR: SPITES (Bitfield-Mask: 0x01)         */
#define TT_QSPI_ISR_AXIES_Pos         (8UL)                     /*!< TT_QSPI ISR: AXIES (Bit 8)                        */
#define TT_QSPI_ISR_AXIES_Msk         (0x100UL)                 /*!< TT_QSPI ISR: AXIES (Bitfield-Mask: 0x01)          */
#define TT_QSPI_ISR_TXUIS_Pos         (7UL)                     /*!< TT_QSPI ISR: TXUIS (Bit 7)                        */
#define TT_QSPI_ISR_TXUIS_Msk         (0x80UL)                  /*!< TT_QSPI ISR: TXUIS (Bitfield-Mask: 0x01)          */
#define TT_QSPI_ISR_XRXOIS_Pos        (6UL)                     /*!< TT_QSPI ISR: XRXOIS (Bit 6)                       */
#define TT_QSPI_ISR_XRXOIS_Msk        (0x40UL)                  /*!< TT_QSPI ISR: XRXOIS (Bitfield-Mask: 0x01)         */
#define TT_QSPI_ISR_MSTIS_Pos         (5UL)                     /*!< TT_QSPI ISR: MSTIS (Bit 5)                        */
#define TT_QSPI_ISR_MSTIS_Msk         (0x20UL)                  /*!< TT_QSPI ISR: MSTIS (Bitfield-Mask: 0x01)          */
#define TT_QSPI_ISR_RXFIS_Pos         (4UL)                     /*!< TT_QSPI ISR: RXFIS (Bit 4)                        */
#define TT_QSPI_ISR_RXFIS_Msk         (0x10UL)                  /*!< TT_QSPI ISR: RXFIS (Bitfield-Mask: 0x01)          */
#define TT_QSPI_ISR_RXOIS_Pos         (3UL)                     /*!< TT_QSPI ISR: RXOIS (Bit 3)                        */
#define TT_QSPI_ISR_RXOIS_Msk         (0x8UL)                   /*!< TT_QSPI ISR: RXOIS (Bitfield-Mask: 0x01)          */
#define TT_QSPI_ISR_RXUIS_Pos         (2UL)                     /*!< TT_QSPI ISR: RXUIS (Bit 2)                        */
#define TT_QSPI_ISR_RXUIS_Msk         (0x4UL)                   /*!< TT_QSPI ISR: RXUIS (Bitfield-Mask: 0x01)          */
#define TT_QSPI_ISR_TXOIS_Pos         (1UL)                     /*!< TT_QSPI ISR: TXOIS (Bit 1)                        */
#define TT_QSPI_ISR_TXOIS_Msk         (0x2UL)                   /*!< TT_QSPI ISR: TXOIS (Bitfield-Mask: 0x01)          */
#define TT_QSPI_ISR_TXEIS_Pos         (0UL)                     /*!< TT_QSPI ISR: TXEIS (Bit 0)                        */
#define TT_QSPI_ISR_TXEIS_Msk         (0x1UL)                   /*!< TT_QSPI ISR: TXEIS (Bitfield-Mask: 0x01)          */
/* =========================================================  RISR  ========================================================== */
#define TT_QSPI_RISR_DONER_Pos        (11UL)                    /*!< TT_QSPI RISR: DONER (Bit 11)                      */
#define TT_QSPI_RISR_DONER_Msk        (0x800UL)                 /*!< TT_QSPI RISR: DONER (Bitfield-Mask: 0x01)         */
#define TT_QSPI_RISR_SPITER_Pos       (10UL)                    /*!< TT_QSPI RISR: SPITER (Bit 10)                     */
#define TT_QSPI_RISR_SPITER_Msk       (0x400UL)                 /*!< TT_QSPI RISR: SPITER (Bitfield-Mask: 0x01)        */
#define TT_QSPI_RISR_AXIER_Pos        (8UL)                     /*!< TT_QSPI RISR: AXIER (Bit 8)                       */
#define TT_QSPI_RISR_AXIER_Msk        (0x100UL)                 /*!< TT_QSPI RISR: AXIER (Bitfield-Mask: 0x01)         */
#define TT_QSPI_RISR_TXUIR_Pos        (7UL)                     /*!< TT_QSPI RISR: TXUIR (Bit 7)                       */
#define TT_QSPI_RISR_TXUIR_Msk        (0x80UL)                  /*!< TT_QSPI RISR: TXUIR (Bitfield-Mask: 0x01)         */
#define TT_QSPI_RISR_XRXOIR_Pos       (6UL)                     /*!< TT_QSPI RISR: XRXOIR (Bit 6)                      */
#define TT_QSPI_RISR_XRXOIR_Msk       (0x40UL)                  /*!< TT_QSPI RISR: XRXOIR (Bitfield-Mask: 0x01)        */
#define TT_QSPI_RISR_MSTIR_Pos        (5UL)                     /*!< TT_QSPI RISR: MSTIR (Bit 5)                       */
#define TT_QSPI_RISR_MSTIR_Msk        (0x20UL)                  /*!< TT_QSPI RISR: MSTIR (Bitfield-Mask: 0x01)         */
#define TT_QSPI_RISR_RXFIR_Pos        (4UL)                     /*!< TT_QSPI RISR: RXFIR (Bit 4)                       */
#define TT_QSPI_RISR_RXFIR_Msk        (0x10UL)                  /*!< TT_QSPI RISR: RXFIR (Bitfield-Mask: 0x01)         */
#define TT_QSPI_RISR_RXOIR_Pos        (3UL)                     /*!< TT_QSPI RISR: RXOIR (Bit 3)                       */
#define TT_QSPI_RISR_RXOIR_Msk        (0x8UL)                   /*!< TT_QSPI RISR: RXOIR (Bitfield-Mask: 0x01)         */
#define TT_QSPI_RISR_RXUIR_Pos        (2UL)                     /*!< TT_QSPI RISR: RXUIR (Bit 2)                       */
#define TT_QSPI_RISR_RXUIR_Msk        (0x4UL)                   /*!< TT_QSPI RISR: RXUIR (Bitfield-Mask: 0x01)         */
#define TT_QSPI_RISR_TXOIR_Pos        (1UL)                     /*!< TT_QSPI RISR: TXOIR (Bit 1)                       */
#define TT_QSPI_RISR_TXOIR_Msk        (0x2UL)                   /*!< TT_QSPI RISR: TXOIR (Bitfield-Mask: 0x01)         */
#define TT_QSPI_RISR_TXEIR_Pos        (0UL)                     /*!< TT_QSPI RISR: TXEIR (Bit 0)                       */
#define TT_QSPI_RISR_TXEIR_Msk        (0x1UL)                   /*!< TT_QSPI RISR: TXEIR (Bitfield-Mask: 0x01)         */
/* ========================================================  TXEICR  ========================================================= */
#define TT_QSPI_TXEICR_TXEICR_Pos     (0UL)                     /*!< TT_QSPI TXEICR: TXEICR (Bit 0)                    */
#define TT_QSPI_TXEICR_TXEICR_Msk     (0x1UL)                   /*!< TT_QSPI TXEICR: TXEICR (Bitfield-Mask: 0x01)      */
/* ========================================================  RXOICR  ========================================================= */
#define TT_QSPI_RXOICR_RXOICR_Pos     (0UL)                     /*!< TT_QSPI RXOICR: RXOICR (Bit 0)                    */
#define TT_QSPI_RXOICR_RXOICR_Msk     (0x1UL)                   /*!< TT_QSPI RXOICR: RXOICR (Bitfield-Mask: 0x01)      */
/* ========================================================  RXUICR  ========================================================= */
#define TT_QSPI_RXUICR_RXUICR_Pos     (0UL)                     /*!< TT_QSPI RXUICR: RXUICR (Bit 0)                    */
#define TT_QSPI_RXUICR_RXUICR_Msk     (0x1UL)                   /*!< TT_QSPI RXUICR: RXUICR (Bitfield-Mask: 0x01)      */
/* ========================================================  MSTICR  ========================================================= */
#define TT_QSPI_MSTICR_MSTICR_Pos     (0UL)                     /*!< TT_QSPI MSTICR: MSTICR (Bit 0)                    */
#define TT_QSPI_MSTICR_MSTICR_Msk     (0x1UL)                   /*!< TT_QSPI MSTICR: MSTICR (Bitfield-Mask: 0x01)      */
/* ==========================================================  ICR  ========================================================== */
#define TT_QSPI_ICR_ICR_Pos           (0UL)                     /*!< TT_QSPI ICR: ICR (Bit 0)                          */
#define TT_QSPI_ICR_ICR_Msk           (0x1UL)                   /*!< TT_QSPI ICR: ICR (Bitfield-Mask: 0x01)            */
/* =========================================================  DMACR  ========================================================= */
#define TT_QSPI_DMACR_APROT_Pos       (12UL)                    /*!< TT_QSPI DMACR: APROT (Bit 12)                     */
#define TT_QSPI_DMACR_APROT_Msk       (0x3000UL)                /*!< TT_QSPI DMACR: APROT (Bitfield-Mask: 0x07)        */
#define TT_QSPI_DMACR_ACACHE_Pos      (8UL)                     /*!< TT_QSPI DMACR: ACACHE (Bit 8)                     */
#define TT_QSPI_DMACR_ACACHE_Msk      (0xf00UL)                 /*!< TT_QSPI DMACR: ACACHE (Bitfield-Mask: 0x0f)       */
#define TT_QSPI_DMACR_AINC_Pos        (6UL)                     /*!< TT_QSPI DMACR: AINC (Bit 6)                       */
#define TT_QSPI_DMACR_AINC_Msk        (0x40UL)                  /*!< TT_QSPI DMACR: AINC (Bitfield-Mask: 0x01)         */
#define TT_QSPI_DMACR_ATW_Pos         (3UL)                     /*!< TT_QSPI DMACR: ATW (Bit 3)                        */
#define TT_QSPI_DMACR_ATW_Msk         (0x18UL)                  /*!< TT_QSPI DMACR: ATW (Bitfield-Mask: 0x03)          */
#define TT_QSPI_DMACR_IDMAE_Pos       (2UL)                     /*!< TT_QSPI DMACR: IDMAE (Bit 2)                      */
#define TT_QSPI_DMACR_IDMAE_Msk       (0x4UL)                   /*!< TT_QSPI DMACR: IDMAE (Bitfield-Mask: 0x01)        */
#define TT_QSPI_DMACR_TDMAE_Pos       (1UL)                     /*!< TT_QSPI DMACR: TDMAE (Bit 1)                      */
#define TT_QSPI_DMACR_TDMAE_Msk       (0x2UL)                   /*!< TT_QSPI DMACR: TDMAE (Bitfield-Mask: 0x01)        */
#define TT_QSPI_DMACR_RDMAE_Pos       (0UL)                     /*!< TT_QSPI DMACR: RDMAE (Bit 0)                      */
#define TT_QSPI_DMACR_RDMAE_Msk       (0x1UL)                   /*!< TT_QSPI DMACR: RDMAE (Bitfield-Mask: 0x01)        */
/* =======================================================  AXIAWLEN  ======================================================== */
#define TT_QSPI_AXIAWLEN_AWLEN_Pos    (8UL)                     /*!< TT_QSPI AXIAWLEN: AWLEN (Bit 8)                   */
#define TT_QSPI_AXIAWLEN_AWLEN_Msk    (0xf00UL)                 /*!< TT_QSPI AXIAWLEN: AWLEN (Bitfield-Mask: 0x0f)     */
/* =======================================================  AXIARLEN  ======================================================== */
#define TT_QSPI_AXIARLEN_ARLEN_Pos    (8UL)                     /*!< TT_QSPI AXIARLEN: ARLEN (Bit 8)                   */
#define TT_QSPI_AXIARLEN_ARLEN_Msk    (0xf00UL)                 /*!< TT_QSPI AXIARLEN: ARLEN (Bitfield-Mask: 0x0f)     */
/* ==========================================================  IDR  ========================================================== */
#define TT_QSPI_IDR_IDCODE_Pos        (0UL)                     /*!< TT_QSPI IDR: IDCODE (Bit 0)                       */
#define TT_QSPI_IDR_IDCODE_Msk        (0xffffffffUL)            /*!< TT_QSPI IDR: IDCODE (Bitfield-Mask: 0xffffffff)   */
/* ====================================================  SSIC_VERSION_ID  ==================================================== */
#define TT_QSPI_SSIC_VERSION_ID_SSIC_COMP_VERSION_Pos (0UL)     /*!< TT_QSPI SSIC_VERSION_ID: SSIC_COMP_VERSION (Bit 0) */
#define TT_QSPI_SSIC_VERSION_ID_SSIC_COMP_VERSION_Msk (0xffffffffUL) /*!< TT_QSPI SSIC_VERSION_ID: SSIC_COMP_VERSION (Bitfield-Mask: 0xffffffff) */
/* ==========================================================  DR  =========================================================== */
#define TT_QSPI_DR_FIELD_Pos          (0UL)                     /*!< TT_QSPI DR: FIELD (Bit 0)                         */
#define TT_QSPI_DR_FIELD_Msk          (0xffffffffUL)            /*!< TT_QSPI DR: FIELD (Bitfield-Mask: 0xffffffff)     */
/* ====================================================  RX_SAMPLE_DELAY  ==================================================== */
#define TT_QSPI_RX_SAMPLE_DELAY_SE_Pos (16UL)                   /*!< TT_QSPI RX_SAMPLE_DELAY: SE (Bit 16)              */
#define TT_QSPI_RX_SAMPLE_DELAY_SE_Msk (0x10000UL)              /*!< TT_QSPI RX_SAMPLE_DELAY: SE (Bitfield-Mask: 0x01) */
#define TT_QSPI_RX_SAMPLE_DELAY_RSD_Pos (0UL)                   /*!< TT_QSPI RX_SAMPLE_DELAY: RSD (Bit 0)              */
#define TT_QSPI_RX_SAMPLE_DELAY_RSD_Msk (0xffUL)                /*!< TT_QSPI RX_SAMPLE_DELAY: RSD (Bitfield-Mask: 0xff) */
/* ======================================================  SPI_CTRLR0  ====================================================== */
#define TT_QSPI_SPI_CTRLR0_TRANS_TYPE_Pos (0UL)                /*!< TT_QSPI QSPI_CTRLR0: TRANS_TYPE (Bit 0)           */
#define TT_QSPI_SPI_CTRLR0_TRANS_TYPE_Msk (0x3UL)              /*!< TT_QSPI QSPI_CTRLR0: TRANS_TYPE (Bitfield-Mask: 0x03) */
#define TT_QSPI_SPI_CTRLR0_ADDR_L_Pos (2UL)                    /*!< TT_QSPI QSPI_CTRLR0: ADDR_L (Bit 2)               */
#define TT_QSPI_SPI_CTRLR0_ADDR_L_Msk (0x3cUL)                 /*!< TT_QSPI QSPI_CTRLR0: ADDR_L (Bitfield-Mask: 0x0f) */
#define TT_QSPI_SPI_CTRLR0_XIP_MD_BIT_EN_Pos (7UL)             /*!< TT_QSPI QSPI_CTRLR0: XIP_MD_BIT_EN (Bit 7)        */
#define TT_QSPI_SPI_CTRLR0_XIP_MD_BIT_EN_Msk (0x80UL)          /*!< TT_QSPI QSPI_CTRLR0: XIP_MD_BIT_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_INST_L_Pos (8UL)                    /*!< TT_QSPI QSPI_CTRLR0: INST_L (Bit 8)               */
#define TT_QSPI_SPI_CTRLR0_INST_L_Msk (0x300UL)                /*!< TT_QSPI QSPI_CTRLR0: INST_L (Bitfield-Mask: 0x03) */
#define TT_QSPI_SPI_CTRLR0_WAIT_CYCLES_Pos (11UL)              /*!< TT_QSPI QSPI_CTRLR0: WAIT_CYCLES (Bit 11)         */
#define TT_QSPI_SPI_CTRLR0_WAIT_CYCLES_Msk (0xf800UL)          /*!< TT_QSPI QSPI_CTRLR0: WAIT_CYCLES (Bitfield-Mask: 0x1f) */
#define TT_QSPI_SPI_CTRLR0_SPI_DDR_EN_Pos (16UL)               /*!< TT_QSPI QSPI_CTRLR0: SPI_DDR_EN (Bit 16)          */
#define TT_QSPI_SPI_CTRLR0_SPI_DDR_EN_Msk (0x10000UL)          /*!< TT_QSPI QSPI_CTRLR0: SPI_DDR_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_INST_DDR_EN_Pos (17UL)              /*!< TT_QSPI QSPI_CTRLR0: INST_DDR_EN (Bit 17)         */
#define TT_QSPI_SPI_CTRLR0_INST_DDR_EN_Msk (0x20000UL)         /*!< TT_QSPI QSPI_CTRLR0: INST_DDR_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_SPI_RXDS_EN_Pos (18UL)              /*!< TT_QSPI QSPI_CTRLR0: SPI_RXDS_EN (Bit 18)         */
#define TT_QSPI_SPI_CTRLR0_SPI_RXDS_EN_Msk (0x40000UL)         /*!< TT_QSPI QSPI_CTRLR0: SPI_RXDS_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_XIP_DFS_HC_Pos (19UL)               /*!< TT_QSPI QSPI_CTRLR0: XIP_DFS_HC (Bit 19)          */
#define TT_QSPI_SPI_CTRLR0_XIP_DFS_HC_Msk (0x80000UL)          /*!< TT_QSPI QSPI_CTRLR0: XIP_DFS_HC (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_XIP_INST_E_Pos (20UL)               /*!< TT_QSPI QSPI_CTRLR0: XIP_INST_E (Bit 20)          */
#define TT_QSPI_SPI_CTRLR0_XIP_INST_E_Msk (0x100000UL)         /*!< TT_QSPI QSPI_CTRLR0: XIP_INST_E (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_SSIC_XIP_CONT_XFER_EN_Pos (21UL)    /*!< TT_QSPI QSPI_CTRLR0: SSIC_XIP_CONT_XFER_EN (Bit 21) */
#define TT_QSPI_SPI_CTRLR0_SSIC_XIP_CONT_XFER_EN_Msk (0x200000UL) /*!< TT_QSPI QSPI_CTRLR0: SSIC_XIP_CONT_XFER_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_SPI_DM_EN_Pos (24UL)                /*!< TT_QSPI QSPI_CTRLR0: SPI_DM_EN (Bit 24)           */
#define TT_QSPI_SPI_CTRLR0_SPI_DM_EN_Msk (0x1000000UL)         /*!< TT_QSPI QSPI_CTRLR0: SPI_DM_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Pos (25UL)          /*!< TT_QSPI QSPI_CTRLR0: SPI_RXDS_SIG_EN (Bit 25)     */
#define TT_QSPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Msk (0x2000000UL)   /*!< TT_QSPI QSPI_CTRLR0: SPI_RXDS_SIG_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_XIP_MBL_Pos (26UL)                  /*!< TT_QSPI QSPI_CTRLR0: XIP_MBL (Bit 26)             */
#define TT_QSPI_SPI_CTRLR0_XIP_MBL_Msk (0xc000000UL)           /*!< TT_QSPI QSPI_CTRLR0: XIP_MBL (Bitfield-Mask: 0x03) */
#define TT_QSPI_SPI_CTRLR0_XIP_PREFETCH_EN_Pos (29UL)          /*!< TT_QSPI QSPI_CTRLR0: XIP_PREFETCH_EN (Bit 29)     */
#define TT_QSPI_SPI_CTRLR0_XIP_PREFETCH_EN_Msk (0x20000000UL)  /*!< TT_QSPI QSPI_CTRLR0: XIP_PREFETCH_EN (Bitfield-Mask: 0x01) */
#define TT_QSPI_SPI_CTRLR0_CLK_STRETCH_EN_Pos (30UL)           /*!< TT_QSPI QSPI_CTRLR0: CLK_STRETCH_EN (Bit 30)      */
#define TT_QSPI_SPI_CTRLR0_CLK_STRETCH_EN_Msk (0x40000000UL)   /*!< TT_QSPI QSPI_CTRLR0: CLK_STRETCH_EN (Bitfield-Mask: 0x01) */
/* ====================================================  DDR_DRIVE_EDGE  ===================================================== */
#define TT_QSPI_DDR_DRIVE_EDGE_TDE_Pos (0UL)                    /*!< TT_QSPI DDR_DRIVE_EDGE: TDE (Bit 0)               */
#define TT_QSPI_DDR_DRIVE_EDGE_TDE_Msk (0xffUL)                 /*!< TT_QSPI DDR_DRIVE_EDGE: TDE (Bitfield-Mask: 0xff) */
/* =====================================================  XIP_MODE_BITS  ===================================================== */
#define TT_QSPI_XIP_MODE_BITS_XIP_MD_BITS_Pos (0UL)             /*!< TT_QSPI XIP_MODE_BITS: XIP_MD_BITS (Bit 0)        */
#define TT_QSPI_XIP_MODE_BITS_XIP_MD_BITS_Msk (0xffffUL)        /*!< TT_QSPI XIP_MODE_BITS: XIP_MD_BITS (Bitfield-Mask: 0xffff) */
/* =====================================================  XIP_INCR_INST  ===================================================== */
#define TT_QSPI_XIP_INCR_INST_INCR_INST_Pos (0UL)               /*!< TT_QSPI XIP_INCR_INST: INCR_INST (Bit 0)          */
#define TT_QSPI_XIP_INCR_INST_INCR_INST_Msk (0xffffUL)          /*!< TT_QSPI XIP_INCR_INST: INCR_INST (Bitfield-Mask: 0xffff) */
/* =====================================================  XIP_WRAP_INST  ===================================================== */
#define TT_QSPI_XIP_WRAP_INST_WRAP_INST_Pos (0UL)               /*!< TT_QSPI XIP_WRAP_INST: WRAP_INST (Bit 0)          */
#define TT_QSPI_XIP_WRAP_INST_WRAP_INST_Msk (0xffffUL)          /*!< TT_QSPI XIP_WRAP_INST: WRAP_INST (Bitfield-Mask: 0xffff) */
/* ===================================================  XIP_CNT_TIME_OUT  ==================================================== */
#define TT_QSPI_XIP_CNT_TIME_OUT_XTOC_Pos (0UL)                 /*!< TT_QSPI XIP_CNT_TIME_OUT: XTOC (Bit 0)            */
#define TT_QSPI_XIP_CNT_TIME_OUT_XTOC_Msk (0xffUL)              /*!< TT_QSPI XIP_CNT_TIME_OUT: XTOC (Bitfield-Mask: 0xff) */
/* =========================================================  SPIDR  ========================================================= */
#define TT_QSPI_SPIDR_SPI_INST_Pos    (0UL)                     /*!< TT_QSPI SPIDR: SPI_INST (Bit 0)                   */
#define TT_QSPI_SPIDR_SPI_INST_Msk    (0xffffUL)                /*!< TT_QSPI SPIDR: SPI_INST (Bitfield-Mask: 0xffff)   */
/* =========================================================  SPIAR  ========================================================= */
#define TT_QSPI_SPIAR_SDAR_Pos        (0UL)                     /*!< TT_QSPI SPIAR: SDAR (Bit 0)                       */
#define TT_QSPI_SPIAR_SDAR_Msk        (0xffffffffUL)            /*!< TT_QSPI SPIAR: SDAR (Bitfield-Mask: 0xffffffff)   */
/* ========================================================  AXIAR0  ========================================================= */
#define TT_QSPI_AXIAR0_AXIAR_0_31_Pos (0UL)                     /*!< TT_QSPI AXIAR0: AXIAR_0_31 (Bit 0)                */
#define TT_QSPI_AXIAR0_AXIAR_0_31_Msk (0xffffffffUL)            /*!< TT_QSPI AXIAR0: AXIAR_0_31 (Bitfield-Mask: 0xffffffff) */
/* ========================================================  AXIECR  ========================================================= */
#define TT_QSPI_AXIECR_AXIECR_Pos     (0UL)                     /*!< TT_QSPI AXIECR: AXIECR (Bit 0)                    */
#define TT_QSPI_AXIECR_AXIECR_Msk     (0x1UL)                   /*!< TT_QSPI AXIECR: AXIECR (Bitfield-Mask: 0x01)      */
/* ========================================================  DONECR  ========================================================= */
#define TT_QSPI_DONECR_DONECR_Pos     (0UL)                     /*!< TT_QSPI DONECR: DONECR (Bit 0)                    */
#define TT_QSPI_DONECR_DONECR_Msk     (0x1UL)                   /*!< TT_QSPI DONECR: DONECR (Bitfield-Mask: 0x01)      */

#ifdef __cplusplus
}
#endif
#endif
