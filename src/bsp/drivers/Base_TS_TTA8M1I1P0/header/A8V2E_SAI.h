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
#ifndef A8V2E_SAI_H
#define A8V2E_SAI_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"


/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_SAI_VENDOR_ID_H                     1541
#define A8V2E_SAI_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_SAI_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_SAI_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_SAI_SW_MAJOR_VERSION_H              1
#define A8V2E_SAI_SW_MINOR_VERSION_H              1
#define A8V2E_SAI_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_SAI.h and TT_Common.h file version check */
#if (A8V2E_SAI_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_SAI.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_SAI_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_SAI_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_SAI_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_SAI.h and TT_Common.h are different"
#endif
#if ((A8V2E_SAI_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_SAI_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_SAI_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_SAI.h and TT_Common.h are different"
#endif


/**
  * @brief TT_I2S0_CHANNEL [CHANNEL] (Channel cluster)
  */
typedef struct {
  __IOM uint32_t  LEFT_RXTX;                    /*!< (@ 0x00000000) Left Receive or Left Transmit Register                     */
  __IOM uint32_t  RIGHT_RXTX;                   /*!< (@ 0x00000004) Right Receive or Right Transmit Register                   */
  __IOM uint32_t  RER;                          /*!< (@ 0x00000008) Receive Enable Register                                    */
  __IOM uint32_t  TER;                          /*!< (@ 0x0000000C) Transmit Enable Register                                   */
  __IOM uint32_t  RCR;                          /*!< (@ 0x00000010) Receive Configuration Register                             */
  __IOM uint32_t  TCR;                          /*!< (@ 0x00000014) Transmit Configuration Register                            */
  __IM  uint32_t  ISR;                          /*!< (@ 0x00000018) Interrupt Status Register                                  */
  __IOM uint32_t  IMR;                          /*!< (@ 0x0000001C) Interrupt Mask Register                                    */
  __IM  uint32_t  ROR;                          /*!< (@ 0x00000020) Receive Overrun Register                                   */
  __IM  uint32_t  TOR;                          /*!< (@ 0x00000024) Transmit Overrun Register                                  */
  __IOM uint32_t  RFCR;                         /*!< (@ 0x00000028) Receive FIFO Configuration Register                        */
  __IOM uint32_t  TFCR;                         /*!< (@ 0x0000002C) Transmit FIFO Configuration Register                       */
  __IOM uint32_t  RFF;                          /*!< (@ 0x00000030) Receive FIFO Flush Register                                */
  __IOM uint32_t  TFF;                          /*!< (@ 0x00000034) Transmit FIFO Flush Register                               */
  __IOM uint32_t  _RESERVED0;                   /*!< (@ 0x00000038) _RESERVED0                                                 */
  __IOM uint32_t  _RESERVED1;                   /*!< (@ 0x0000003C) _RESERVED0                                                 */
} TT_I2S0_CHANNEL_Type;                     /*!< Size = 64 (0x40)                                                          */
/* =========================================================================================================================== */
/* ================                                        TT_I2S0                                        ================ */
/* =========================================================================================================================== */


/**
  * @brief Inter-Integrated Sound Interface 0 (TT_I2S0)
  */

typedef struct {                                /*!< (@ 0x40120000) TT_I2S0 Structure                                      */
  __IOM uint32_t  IER;                          /*!< (@ 0x00000000) Enable Register                                            */
  __IOM uint32_t  IRER;                         /*!< (@ 0x00000004) Receiver Block Enable Register                             */
  __IOM uint32_t  ITER;                         /*!< (@ 0x00000008) Transmitter Block Enable Register                          */
  __IOM uint32_t  CER;                          /*!< (@ 0x0000000C) Clock Generation enable                                    */
  __IOM uint32_t  CCR;                          /*!< (@ 0x00000010) Clock Configuration Register                               */
  __IOM uint32_t  RXFFR;                        /*!< (@ 0x00000014) Receiver Block FIFO Reset Register                         */
  __IOM uint32_t  TXFFR;                        /*!< (@ 0x00000018) Transmitter Block FIFO Reset Register                      */
  __IM  uint32_t  RESERVED;
  __IOM TT_I2S0_CHANNEL_Type CHANNEL0;      /*!< (@ 0x00000020) Channel cluster                                            */
  __IOM TT_I2S0_CHANNEL_Type CHANNEL1;      /*!< (@ 0x00000060) Channel cluster                                            */
  __IOM TT_I2S0_CHANNEL_Type CHANNEL2;      /*!< (@ 0x000000A0) Channel cluster                                            */
  __IOM TT_I2S0_CHANNEL_Type CHANNEL3;      /*!< (@ 0x000000E0) Channel cluster                                            */
  __IM  uint32_t  RESERVED1[40];
  __IOM uint32_t  RXDMA;                        /*!< (@ 0x000001C0) Receiver Block DMA Register                                */
  __IOM uint32_t  RRXDMA;                       /*!< (@ 0x000001C4) Reset Receiver Block DMA Register                          */
  __IOM uint32_t  TXDMA;                        /*!< (@ 0x000001C8) Transmitter Block DMA Register                             */
  __IOM uint32_t  RTXDMA;                       /*!< (@ 0x000001CC) Reset Transmitter Block DMA Register                       */
  __IM  uint32_t  RESERVED2[8];
  __IOM uint32_t  I2S_COMP_PARAM_2;             /*!< (@ 0x000001F0) Component Parameter Register 2                             */
  __IOM uint32_t  I2S_COMP_PARAM_1;             /*!< (@ 0x000001F4) Component Parameter Register 1                             */
  __IOM uint32_t  I2S_COMP_VERSION_1;           /*!< (@ 0x000001F8) Component Version Register                                 */
  __IOM uint32_t  I2S_COMP_TYPE;                /*!< (@ 0x000001FC) Component Type Register                                    */
  __IOM uint32_t  DMACR;                        /*!< (@ 0x00000200) DMA Control Register.                                      */
  __IM  uint32_t  RXDMA_CH;                     /*!< (@ 0x00000204) Receiver Block DMA Register.                               */
  __IM  uint32_t  RESERVED3[3];
  __OM  uint32_t  TXDMA_CH;                     /*!< (@ 0x00000214) Transmit Block DMA Register.                               */
} TT_I2S_Type;                              /*!< Size = 536 (0x218)                                                        */

#define TT_I2S0_BASE            0x40117000UL

#define TT_I2S0                 ((TT_I2S_Type *)TT_I2S0_BASE)

/* =========================================================================================================================== */
/* ================                                        TT_I2S                                         ================ */
/* =========================================================================================================================== */

/* ==========================================================  IER  ========================================================== */
#define TT_I2S_IER_IEN_Pos            (0UL)                     /*!< TT_I2S IER: IEN (Bit 0)                           */
#define TT_I2S_IER_IEN_Msk            (0x1UL)                   /*!< TT_I2S IER: IEN (Bitfield-Mask: 0x01)             */
/* =========================================================  IRER  ========================================================== */
#define TT_I2S_IRER_RXEN_Pos          (0UL)                     /*!< TT_I2S IRER: RXEN (Bit 0)                         */
#define TT_I2S_IRER_RXEN_Msk          (0x1UL)                   /*!< TT_I2S IRER: RXEN (Bitfield-Mask: 0x01)           */
/* =========================================================  ITER  ========================================================== */
#define TT_I2S_ITER_TXEN_Pos          (0UL)                     /*!< TT_I2S ITER: TXEN (Bit 0)                         */
#define TT_I2S_ITER_TXEN_Msk          (0x1UL)                   /*!< TT_I2S ITER: TXEN (Bitfield-Mask: 0x01)           */
/* ==========================================================  CER  ========================================================== */
#define TT_I2S_CER_CLKEN_Pos          (0UL)                     /*!< TT_I2S CER: CLKEN (Bit 0)                         */
#define TT_I2S_CER_CLKEN_Msk          (0x1UL)                   /*!< TT_I2S CER: CLKEN (Bitfield-Mask: 0x01)           */
/* ==========================================================  CCR  ========================================================== */
#define TT_I2S_CCR_CLK_GATE_Pos       (0UL)                     /*!< TT_I2S CCR: CLK_GATE (Bit 0)                      */
#define TT_I2S_CCR_CLK_GATE_Msk       (0x7UL)                   /*!< TT_I2S CCR: CLK_GATE (Bitfield-Mask: 0x07)        */
#define TT_I2S_CCR_CLK_WORD_SIZE_Pos  (3UL)                     /*!< TT_I2S CCR: CLK_WORD_SIZE (Bit 3)                 */
#define TT_I2S_CCR_CLK_WORD_SIZE_Msk  (0x18UL)                  /*!< TT_I2S CCR: CLK_WORD_SIZE (Bitfield-Mask: 0x03)   */
/* =========================================================  RXFFR  ========================================================= */
#define TT_I2S_RXFFR_RXFFR_Pos        (0UL)                     /*!< TT_I2S RXFFR: RXFFR (Bit 0)                       */
#define TT_I2S_RXFFR_RXFFR_Msk        (0x1UL)                   /*!< TT_I2S RXFFR: RXFFR (Bitfield-Mask: 0x01)         */
/* =========================================================  TXFFR  ========================================================= */
#define TT_I2S_TXFFR_TXFFR_Pos        (0UL)                     /*!< TT_I2S TXFFR: TXFFR (Bit 0)                       */
#define TT_I2S_TXFFR_TXFFR_Msk        (0x1UL)                   /*!< TT_I2S TXFFR: TXFFR (Bitfield-Mask: 0x01)         */
/* =========================================================  RXDMA  ========================================================= */
/* ========================================================  RRXDMA  ========================================================= */
/* =========================================================  TXDMA  ========================================================= */
/* ========================================================  RTXDMA  ========================================================= */
/* ===================================================  I2S_COMP_PARAM_2  ==================================================== */
/* ===================================================  I2S_COMP_PARAM_1  ==================================================== */
/* ==================================================  I2S_COMP_VERSION_1  =================================================== */
/* =====================================================  I2S_COMP_TYPE  ===================================================== */
/* =========================================================  DMACR  ========================================================= */
#define TT_I2S_DMACR_DMAEN_TXBLOCK_Pos (17UL)                   /*!< TT_I2S DMACR: DMAEN_TXBLOCK (Bit 17)              */
#define TT_I2S_DMACR_DMAEN_TXBLOCK_Msk (0x20000UL)              /*!< TT_I2S DMACR: DMAEN_TXBLOCK (Bitfield-Mask: 0x01) */
#define TT_I2S_DMACR_DMAEN_RXBLOCK_Pos (16UL)                   /*!< TT_I2S DMACR: DMAEN_RXBLOCK (Bit 16)              */
#define TT_I2S_DMACR_DMAEN_RXBLOCK_Msk (0x10000UL)              /*!< TT_I2S DMACR: DMAEN_RXBLOCK (Bitfield-Mask: 0x01) */
#define TT_I2S_DMACR_DMAEN_TXCH_3_Pos (11UL)                    /*!< TT_I2S DMACR: DMAEN_TXCH_3 (Bit 11)               */
#define TT_I2S_DMACR_DMAEN_TXCH_3_Msk (0x800UL)                 /*!< TT_I2S DMACR: DMAEN_TXCH_3 (Bitfield-Mask: 0x01)  */
#define TT_I2S_DMACR_DMAEN_TXCH_2_Pos (10UL)                    /*!< TT_I2S DMACR: DMAEN_TXCH_2 (Bit 10)               */
#define TT_I2S_DMACR_DMAEN_TXCH_2_Msk (0x400UL)                 /*!< TT_I2S DMACR: DMAEN_TXCH_2 (Bitfield-Mask: 0x01)  */
#define TT_I2S_DMACR_DMAEN_TXCH_1_Pos (9UL)                     /*!< TT_I2S DMACR: DMAEN_TXCH_1 (Bit 9)                */
#define TT_I2S_DMACR_DMAEN_TXCH_1_Msk (0x200UL)                 /*!< TT_I2S DMACR: DMAEN_TXCH_1 (Bitfield-Mask: 0x01)  */
#define TT_I2S_DMACR_DMAEN_TXCH_0_Pos (8UL)                     /*!< TT_I2S DMACR: DMAEN_TXCH_0 (Bit 8)                */
#define TT_I2S_DMACR_DMAEN_TXCH_0_Msk (0x100UL)                 /*!< TT_I2S DMACR: DMAEN_TXCH_0 (Bitfield-Mask: 0x01)  */
#define TT_I2S_DMACR_DMAEN_RXCH_3_Pos (3UL)                     /*!< TT_I2S DMACR: DMAEN_RXCH_3 (Bit 3)                */
#define TT_I2S_DMACR_DMAEN_RXCH_3_Msk (0x8UL)                   /*!< TT_I2S DMACR: DMAEN_RXCH_3 (Bitfield-Mask: 0x01)  */
#define TT_I2S_DMACR_DMAEN_RXCH_2_Pos (2UL)                     /*!< TT_I2S DMACR: DMAEN_RXCH_2 (Bit 2)                */
#define TT_I2S_DMACR_DMAEN_RXCH_2_Msk (0x4UL)                   /*!< TT_I2S DMACR: DMAEN_RXCH_2 (Bitfield-Mask: 0x01)  */
#define TT_I2S_DMACR_DMAEN_RXCH_1_Pos (1UL)                     /*!< TT_I2S DMACR: DMAEN_RXCH_1 (Bit 1)                */
#define TT_I2S_DMACR_DMAEN_RXCH_1_Msk (0x2UL)                   /*!< TT_I2S DMACR: DMAEN_RXCH_1 (Bitfield-Mask: 0x01)  */
#define TT_I2S_DMACR_DMAEN_RXCH_0_Pos (0UL)                     /*!< TT_I2S DMACR: DMAEN_RXCH_0 (Bit 0)                */
#define TT_I2S_DMACR_DMAEN_RXCH_0_Msk (0x1UL)                   /*!< TT_I2S DMACR: DMAEN_RXCH_0 (Bitfield-Mask: 0x01)  */
/* =======================================================  RXDMA_CH  ======================================================== */
/* =======================================================  TXDMA_CH  ======================================================== */


/* =========================================================================================================================== */
/* ================                                          CHANNEL                                          ================ */
/* =========================================================================================================================== */

/* =======================================================  LEFT_RXTX  ======================================================= */
/* ======================================================  RIGHT_RXTX  ======================================================= */
/* ==========================================================  RER  ========================================================== */
#define CHANNEL_RER_RXCHENX_Pos           (0UL)                     /*!< CHANNEL RER: RXCHENX (Bit 0)                          */
#define CHANNEL_RER_RXCHENX_Msk           (0x1UL)                   /*!< CHANNEL RER: RXCHENX (Bitfield-Mask: 0x01)            */
/* ==========================================================  TER  ========================================================== */
#define CHANNEL_TER_TXCHENX_Pos           (0UL)                     /*!< CHANNEL TER: TXCHENX (Bit 0)                          */
#define CHANNEL_TER_TXCHENX_Msk           (0x1UL)                   /*!< CHANNEL TER: TXCHENX (Bitfield-Mask: 0x01)            */
/* ==========================================================  RCR  ========================================================== */
#define CHANNEL_RCR_WLEN_Pos              (0UL)                     /*!< CHANNEL RCR: WLEN (Bit 0)                             */
#define CHANNEL_RCR_WLEN_Msk              (0x7UL)                   /*!< CHANNEL RCR: WLEN (Bitfield-Mask: 0x07)               */
/* ==========================================================  TCR  ========================================================== */
#define CHANNEL_TCR_WLEN_Pos              (0UL)                     /*!< CHANNEL TCR: WLEN (Bit 0)                             */
#define CHANNEL_TCR_WLEN_Msk              (0x7UL)                   /*!< CHANNEL TCR: WLEN (Bitfield-Mask: 0x07)               */
/* ==========================================================  ISR  ========================================================== */
#define CHANNEL_ISR_RXDA_Pos              (0UL)                     /*!< CHANNEL ISR: RXDA (Bit 0)                             */
#define CHANNEL_ISR_RXDA_Msk              (0x1UL)                   /*!< CHANNEL ISR: RXDA (Bitfield-Mask: 0x01)               */
#define CHANNEL_ISR_RXFO_Pos              (1UL)                     /*!< CHANNEL ISR: RXFO (Bit 1)                             */
#define CHANNEL_ISR_RXFO_Msk              (0x2UL)                   /*!< CHANNEL ISR: RXFO (Bitfield-Mask: 0x01)               */
#define CHANNEL_ISR_TXFE_Pos              (4UL)                     /*!< CHANNEL ISR: TXFE (Bit 4)                             */
#define CHANNEL_ISR_TXFE_Msk              (0x10UL)                  /*!< CHANNEL ISR: TXFE (Bitfield-Mask: 0x01)               */
#define CHANNEL_ISR_TXFO_Pos              (5UL)                     /*!< CHANNEL ISR: TXFO (Bit 5)                             */
#define CHANNEL_ISR_TXFO_Msk              (0x20UL)                  /*!< CHANNEL ISR: TXFO (Bitfield-Mask: 0x01)               */
/* ==========================================================  IMR  ========================================================== */
#define CHANNEL_IMR_RXDAM_Pos             (0UL)                     /*!< CHANNEL IMR: RXDAM (Bit 0)                            */
#define CHANNEL_IMR_RXDAM_Msk             (0x1UL)                   /*!< CHANNEL IMR: RXDAM (Bitfield-Mask: 0x01)              */
#define CHANNEL_IMR_RXFOM_Pos             (1UL)                     /*!< CHANNEL IMR: RXFOM (Bit 1)                            */
#define CHANNEL_IMR_RXFOM_Msk             (0x2UL)                   /*!< CHANNEL IMR: RXFOM (Bitfield-Mask: 0x01)              */
#define CHANNEL_IMR_TXFEM_Pos             (4UL)                     /*!< CHANNEL IMR: TXFEM (Bit 4)                            */
#define CHANNEL_IMR_TXFEM_Msk             (0x10UL)                  /*!< CHANNEL IMR: TXFEM (Bitfield-Mask: 0x01)              */
#define CHANNEL_IMR_TXFOM_Pos             (5UL)                     /*!< CHANNEL IMR: TXFOM (Bit 5)                            */
#define CHANNEL_IMR_TXFOM_Msk             (0x20UL)                  /*!< CHANNEL IMR: TXFOM (Bitfield-Mask: 0x01)              */
/* ==========================================================  ROR  ========================================================== */
#define CHANNEL_ROR_RXCHO_Pos             (0UL)                     /*!< CHANNEL ROR: RXCHO (Bit 0)                            */
#define CHANNEL_ROR_RXCHO_Msk             (0x1UL)                   /*!< CHANNEL ROR: RXCHO (Bitfield-Mask: 0x01)              */
/* ==========================================================  TOR  ========================================================== */
#define CHANNEL_TOR_TXCHO_Pos             (0UL)                     /*!< CHANNEL TOR: TXCHO (Bit 0)                            */
#define CHANNEL_TOR_TXCHO_Msk             (0x1UL)                   /*!< CHANNEL TOR: TXCHO (Bitfield-Mask: 0x01)              */
/* =========================================================  RFCR  ========================================================== */
#define CHANNEL_RFCR_RXCHDT_Pos           (0UL)                     /*!< CHANNEL RFCR: RXCHDT (Bit 0)                          */
#define CHANNEL_RFCR_RXCHDT_Msk           (0xfUL)                   /*!< CHANNEL RFCR: RXCHDT (Bitfield-Mask: 0x0f)            */
/* =========================================================  TFCR  ========================================================== */
#define CHANNEL_TFCR_TXCHET_Pos           (0UL)                     /*!< CHANNEL TFCR: TXCHET (Bit 0)                          */
#define CHANNEL_TFCR_TXCHET_Msk           (0xfUL)                   /*!< CHANNEL TFCR: TXCHET (Bitfield-Mask: 0x0f)            */
/* ==========================================================  RFF  ========================================================== */
#define CHANNEL_RFF_RXCHFR_Pos            (0UL)                     /*!< CHANNEL RFF: RXCHFR (Bit 0)                           */
#define CHANNEL_RFF_RXCHFR_Msk            (0x1UL)                   /*!< CHANNEL RFF: RXCHFR (Bitfield-Mask: 0x01)             */
/* ==========================================================  TFF  ========================================================== */
#define CHANNEL_TFF_RTXCHFR_Pos           (0UL)                     /*!< CHANNEL TFF: RTXCHFR (Bit 0)                          */
#define CHANNEL_TFF_RTXCHFR_Msk           (0x1UL)                   /*!< CHANNEL TFF: RTXCHFR (Bitfield-Mask: 0x01)            */
/* =======================================================  _RESERVED  ======================================================= */


#define TT_SAI_API_VERSION TT_DRIVER_VERSION_MAJOR_MINOR(1,1)  /* API version */


/****** SAI Control Codes *****/

#define TT_SAI_CONTROL_Msk             (0xFFU)
#define TT_SAI_CONFIGURE_TX            (0x01U)     ///< Configure Transmitter;  arg1 and arg2 provide additional configuration
#define TT_SAI_CONFIGURE_RX            (0x02U)     ///< Configure Receiver;     arg1 and arg2 provide additional configuration
#define TT_SAI_CONTROL_TX              (0x03U)     ///< Control Transmitter;    arg1.0: 0=disable (default), 1=enable; arg1.1: mute
#define TT_SAI_CONTROL_RX              (0x04U)     ///< Control Receiver;       arg1.0: 0=disable (default), 1=enable
#define TT_SAI_MASK_SLOTS_TX           (0x05U)     ///< Mask Transmitter slots; arg1 = mask (bit: 0=active, 1=inactive); all configured slots are active by default
#define TT_SAI_MASK_SLOTS_RX           (0x06U)     ///< Mask Receiver    slots; arg1 = mask (bit: 0=active, 1=inactive); all configured slots are active by default
#define TT_SAI_ABORT_SEND              (0x07U)     ///< Abort \ref TT_SAI_Send
#define TT_SAI_ABORT_RECEIVE           (0x08U)     ///< Abort \ref TT_SAI_Receive

/*----- SAI Control Codes: Configuration Parameters: Mode -----*/
#define TT_SAI_MODE_Pos                 8
#define TT_SAI_MODE_Msk                (1U << TT_SAI_MODE_Pos)
#define TT_SAI_MODE_MASTER             (1U << TT_SAI_MODE_Pos)                ///< Master Mode
#define TT_SAI_MODE_SLAVE              (0U << TT_SAI_MODE_Pos)                ///< Slave Mode (default)

/*----- SAI Control Codes: Configuration Parameters: Synchronization -----*/
#define TT_SAI_SYNCHRONIZATION_Pos      9
#define TT_SAI_SYNCHRONIZATION_Msk     (1U << TT_SAI_SYNCHRONIZATION_Pos)
#define TT_SAI_ASYNCHRONOUS            (0U << TT_SAI_SYNCHRONIZATION_Pos)     ///< Asynchronous (default)
#define TT_SAI_SYNCHRONOUS             (1U << TT_SAI_SYNCHRONIZATION_Pos)     ///< Synchronous

/*----- SAI Control Codes: Configuration Parameters: Protocol -----*/
#define TT_SAI_PROTOCOL_Pos             10
#define TT_SAI_PROTOCOL_Msk            (7U << TT_SAI_PROTOCOL_Pos)
#define TT_SAI_PROTOCOL_USER           (0U << TT_SAI_PROTOCOL_Pos)            ///< User defined (default)
#define TT_SAI_PROTOCOL_I2S            (1U << TT_SAI_PROTOCOL_Pos)            ///< I2S
#define TT_SAI_PROTOCOL_MSB_JUSTIFIED  (2U << TT_SAI_PROTOCOL_Pos)            ///< MSB (left) justified
#define TT_SAI_PROTOCOL_LSB_JUSTIFIED  (3U << TT_SAI_PROTOCOL_Pos)            ///< LSB (right) justified
#define TT_SAI_PROTOCOL_PCM_SHORT      (4U << TT_SAI_PROTOCOL_Pos)            ///< PCM with short frame
#define TT_SAI_PROTOCOL_PCM_LONG       (5U << TT_SAI_PROTOCOL_Pos)            ///< PCM with long frame
#define TT_SAI_PROTOCOL_AC97           (6U << TT_SAI_PROTOCOL_Pos)            ///< AC'97

/*----- SAI Control Codes: Configuration Parameters: Data Size -----*/
#define TT_SAI_DATA_SIZE_Pos            13
#define TT_SAI_DATA_SIZE_Msk                    (0x1FU  << TT_SAI_DATA_SIZE_Pos)
#define TT_SAI_DATA_SIZE(n)            (((((n)+2)*4-1)&0x1FU) << TT_SAI_DATA_SIZE_Pos)  ///< Data size in bits (8..32)

/*----- SAI Control Codes: Configuration Parameters: Bit Order -----*/
#define TT_SAI_BIT_ORDER_Pos            18
#define TT_SAI_BIT_ORDER_Msk           (1U << TT_SAI_BIT_ORDER_Pos)
#define TT_SAI_MSB_FIRST               (0U << TT_SAI_BIT_ORDER_Pos)           ///< Data is transferred with MSB first (default)
#define TT_SAI_LSB_FIRST               (1U << TT_SAI_BIT_ORDER_Pos)           ///< Data is transferred with LSB first; User Protocol only (ignored otherwise)

/*----- SAI Control Codes: Configuration Parameters: Mono Mode -----*/
#define TT_SAI_MONO_MODE               (1U << 19)                              ///< Mono Mode (only for I2S, MSB/LSB justified)

/*----- SAI Control Codes:Configuration Parameters: Companding -----*/
#define TT_SAI_COMPANDING_Pos           20
#define TT_SAI_COMPANDING_Msk          (3U << TT_SAI_COMPANDING_Pos)
#define TT_SAI_COMPANDING_NONE         (0U << TT_SAI_COMPANDING_Pos)          ///< No compading (default)
#define TT_SAI_COMPANDING_A_LAW        (2U << TT_SAI_COMPANDING_Pos)          ///< A-Law companding
#define TT_SAI_COMPANDING_U_LAW        (3U << TT_SAI_COMPANDING_Pos)          ///< u-Law companding

/*----- SAI Control Codes: Configuration Parameters: Clock Polarity -----*/
#define TT_SAI_CLOCK_POLARITY_Pos       23
#define TT_SAI_CLOCK_POLARITY_Msk      (1U << TT_SAI_CLOCK_POLARITY_Pos)
#define TT_SAI_CLOCK_POLARITY_0        (0U << TT_SAI_CLOCK_POLARITY_Pos)      ///< Drive on falling edge, Capture on rising  edge (default)
#define TT_SAI_CLOCK_POLARITY_1        (1U << TT_SAI_CLOCK_POLARITY_Pos)      ///< Drive on rising  edge, Capture on falling edge

/*----- SAI Control Codes: Configuration Parameters: Master Clock Pin -----*/
#define TT_SAI_MCLK_PIN_Pos             24
#define TT_SAI_MCLK_PIN_Msk            (3U << TT_SAI_MCLK_PIN_Pos)
#define TT_SAI_MCLK_PIN_INACTIVE       (0U << TT_SAI_MCLK_PIN_Pos)            ///< MCLK not used (default)
#define TT_SAI_MCLK_PIN_OUTPUT         (1U << TT_SAI_MCLK_PIN_Pos)            ///< MCLK is output (Master only)
#define TT_SAI_MCLK_PIN_INPUT          (2U << TT_SAI_MCLK_PIN_Pos)            ///< MCLK is input  (Master only)


/****** SAI Configuration (arg1) *****/

/*----- SAI Configuration (arg1): Frame Length -----*/
#define TT_SAI_FRAME_LENGTH_Pos          0
#define TT_SAI_FRAME_LENGTH_Msk                  (0x3FFU  << TT_SAI_FRAME_LENGTH_Pos)
#define TT_SAI_FRAME_LENGTH(n)          ((((n)-1)&0x3FFU) << TT_SAI_FRAME_LENGTH_Pos)     ///< Frame length in bits (8..1024); default depends on protocol and data

/*----- SAI Configuration (arg1): Frame Sync Width -----*/
#define TT_SAI_FRAME_SYNC_WIDTH_Pos      10
#define TT_SAI_FRAME_SYNC_WIDTH_Msk              (0xFFU  << TT_SAI_FRAME_SYNC_WIDTH_Pos)
#define TT_SAI_FRAME_SYNC_WIDTH(n)      ((((n)-1)&0xFFU) << TT_SAI_FRAME_SYNC_WIDTH_Pos)  ///< Frame Sync width in bits (1..256); default=1; User Protocol only (ignored otherwise)

/*----- SAI Configuration (arg1): Frame Sync Polarity -----*/
#define TT_SAI_FRAME_SYNC_POLARITY_Pos   18
#define TT_SAI_FRAME_SYNC_POLARITY_Msk  (1U << TT_SAI_FRAME_SYNC_POLARITY_Pos)
#define TT_SAI_FRAME_SYNC_POLARITY_HIGH (0U << TT_SAI_FRAME_SYNC_POLARITY_Pos)            ///< Frame Sync is active high (default); User Protocol only (ignored otherwise)
#define TT_SAI_FRAME_SYNC_POLARITY_LOW  (1U << TT_SAI_FRAME_SYNC_POLARITY_Pos)            ///< Frame Sync is active low; User Protocol only (ignored otherwise)

/*----- SAI Configuration (arg1): Frame Sync Early -----*/
#define TT_SAI_FRAME_SYNC_EARLY         (1U << 19)                                         ///< Frame Sync one bit before the first bit of the frame; User Protocol only (ignored otherwise)

/*----- SAI Configuration (arg1): Slot Count -----*/
#define TT_SAI_SLOT_COUNT_Pos            20
#define TT_SAI_SLOT_COUNT_Msk                    (0x1FU  << TT_SAI_SLOT_COUNT_Pos)
#define TT_SAI_SLOT_COUNT(n)            ((((n)-1)&0x1FU) << TT_SAI_SLOT_COUNT_Pos)        ///< Number of slots in frame (1..32); default=1; User Protocol only (ignored otherwise)

/*----- SAI Configuration (arg1): Slot Size -----*/
#define TT_SAI_SLOT_SIZE_Pos             25
#define TT_SAI_SLOT_SIZE_Msk            (3U << TT_SAI_SLOT_SIZE_Pos)
#define TT_SAI_SLOT_SIZE_DEFAULT        (0U << TT_SAI_SLOT_SIZE_Pos)                      ///< Slot size is equal to data size (default)
#define TT_SAI_SLOT_SIZE_16             (1U << TT_SAI_SLOT_SIZE_Pos)                      ///< Slot size = 16 bits; User Protocol only (ignored otherwise)
#define TT_SAI_SLOT_SIZE_32             (3U << TT_SAI_SLOT_SIZE_Pos)                      ///< Slot size = 32 bits; User Protocol only (ignored otherwise)

/*----- SAI Configuration (arg1): Slot Offset -----*/
#define TT_SAI_SLOT_OFFSET_Pos           27
#define TT_SAI_SLOT_OFFSET_Msk               (0x1FU  << TT_SAI_SLOT_OFFSET_Pos)
#define TT_SAI_SLOT_OFFSET(n)           (((n)&0x1FU) << TT_SAI_SLOT_OFFSET_Pos)           ///< Offset of first data bit in slot (0..31); default=0; User Protocol only (ignored otherwise)

/****** SAI Configuration (arg2) *****/

/*----- SAI Control Codes: Configuration Parameters: Audio Frequency (Master only) -----*/
#define TT_SAI_AUDIO_FREQ_Msk          (0x0FFFFFU)                                         ///< Audio frequency mask

/*----- SAI Control Codes: Configuration Parameters: Master Clock Prescaler (Master only and MCLK Pin) -----*/
#define TT_SAI_MCLK_PRESCALER_Pos       20
#define TT_SAI_MCLK_PRESCALER_Msk      (0xFFFU << TT_SAI_MCLK_PRESCALER_Pos)
#define TT_SAI_MCLK_PRESCALER(n)       ((((n)-1)&0xFFFU) << TT_SAI_MCLK_PRESCALER_Pos)    ///< MCLK prescaler; Audio_frequency = MCLK/n; n = 1..4096 (default=1)


/****** SAI specific error codes *****/
#define TT_SAI_ERROR_SYNCHRONIZATION       (TT_DRIVER_ERROR_SPECIFIC - 1)     ///< Specified Synchronization not supported
#define TT_SAI_ERROR_PROTOCOL              (TT_DRIVER_ERROR_SPECIFIC - 2)     ///< Specified Protocol not supported
#define TT_SAI_ERROR_DATA_SIZE             (TT_DRIVER_ERROR_SPECIFIC - 3)     ///< Specified Data size not supported
#define TT_SAI_ERROR_BIT_ORDER             (TT_DRIVER_ERROR_SPECIFIC - 4)     ///< Specified Bit order not supported
#define TT_SAI_ERROR_MONO_MODE             (TT_DRIVER_ERROR_SPECIFIC - 5)     ///< Specified Mono mode not supported
#define TT_SAI_ERROR_COMPANDING            (TT_DRIVER_ERROR_SPECIFIC - 6)     ///< Specified Companding not supported
#define TT_SAI_ERROR_CLOCK_POLARITY        (TT_DRIVER_ERROR_SPECIFIC - 7)     ///< Specified Clock polarity not supported
#define TT_SAI_ERROR_AUDIO_FREQ            (TT_DRIVER_ERROR_SPECIFIC - 8)     ///< Specified Audio frequency not supported
#define TT_SAI_ERROR_MCLK_PIN              (TT_DRIVER_ERROR_SPECIFIC - 9)     ///< Specified MCLK Pin setting not supported
#define TT_SAI_ERROR_MCLK_PRESCALER        (TT_DRIVER_ERROR_SPECIFIC - 10)    ///< Specified MCLK Prescaler not supported
#define TT_SAI_ERROR_FRAME_LENGHT          (TT_DRIVER_ERROR_SPECIFIC - 11)    ///< Specified Frame length not supported
#define TT_SAI_ERROR_FRAME_SYNC_WIDTH      (TT_DRIVER_ERROR_SPECIFIC - 12)    ///< Specified Frame Sync width not supported
#define TT_SAI_ERROR_FRAME_SYNC_POLARITY   (TT_DRIVER_ERROR_SPECIFIC - 13)    ///< Specified Frame Sync polarity not supported
#define TT_SAI_ERROR_FRAME_SYNC_EARLY      (TT_DRIVER_ERROR_SPECIFIC - 14)    ///< Specified Frame Sync early not supported
#define TT_SAI_ERROR_SLOT_COUNT            (TT_DRIVER_ERROR_SPECIFIC - 15)    ///< Specified Slot count not supported
#define TT_SAI_ERROR_SLOT_SIZE             (TT_DRIVER_ERROR_SPECIFIC - 16)    ///< Specified Slot size not supported
#define TT_SAI_ERROR_SLOT_OFFESET          (TT_DRIVER_ERROR_SPECIFIC - 17)    ///< Specified Slot offset not supported


/**
\brief SAI Status
*/
typedef volatile struct _TT_SAI_STATUS {
  uint32 tx_busy          : 1;        ///< Transmitter busy flag
  uint32 rx_busy          : 1;        ///< Receiver busy flag
  uint32 tx_underflow     : 1;        ///< Transmit data underflow detected (cleared on start of next send operation)
  uint32 rx_overflow      : 1;        ///< Receive data overflow detected (cleared on start of next receive operation)
  uint32 frame_error      : 1;        ///< Sync Frame error detected (cleared on start of next send/receive operation)
  uint32 reserved         : 27;
} TT_SAI_STATUS;


/****** SAI Event *****/
#define TT_SAI_EVENT_SEND_COMPLETE     (1U << 0)   ///< Send completed
#define TT_SAI_EVENT_RECEIVE_COMPLETE  (1U << 1)   ///< Receive completed
#define TT_SAI_EVENT_TX_UNDERFLOW      (1U << 2)   ///< Transmit data not available
#define TT_SAI_EVENT_RX_OVERFLOW       (1U << 3)   ///< Receive data overflow
#define TT_SAI_EVENT_FRAME_ERROR       (1U << 4)   ///< Sync Frame error in Slave mode (optional)


#ifdef __cplusplus
}
#endif
#endif
