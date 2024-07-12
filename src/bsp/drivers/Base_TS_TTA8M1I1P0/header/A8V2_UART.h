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
#ifndef A8V2_UART_H
#define A8V2_UART_H


#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

 /******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_UART_VENDOR_ID_H                     1541
#define A8V2_UART_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_UART_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_UART_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_UART_SW_MAJOR_VERSION_H              1
#define A8V2_UART_SW_MINOR_VERSION_H              1
#define A8V2_UART_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_UART.h and TT_Common.h file version check */
#if (A8V2_UART_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_UART.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_UART_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_UART_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_UART_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_UART.h and TT_Common.h are different"
#endif
#if ((A8V2_UART_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_UART_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_UART_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_UART.h and TT_Common.h are different"
#endif

typedef volatile struct  {                      /*!< (@ 0x400A5000) TT_UART0 Structure                         */
    __IOM uint32  DR;                           /*!< (@ 0x00000000) Data Register                                              */
    __IOM uint32  RSR_ECR;                      /*!< (@ 0x00000004) Receive Status/Error Clear Register                 */
    __IM  uint32  RESERVED[4];
    __IOM uint32  FR;                           /*!< (@ 0x00000018) Flag Register                                              */
    __IM  uint32  RESERVED1;
    __IOM uint32  ILPR;                         /*!< (@ 0x00000020) IrDA Low-power Counter register                            */
    __IOM uint32  IBDR;                         /*!< (@ 0x00000024) Integer Baud Rate Register                                 */
    __IOM uint32  FBDR;                         /*!< (@ 0x00000028) Fractional Baud Rate Register                              */
    __IOM uint32  LCR_H;                        /*!< (@ 0x0000002C) Line Control Register                                      */
    __IOM uint32  CR;                    /*!< (@ 0x00000030) Cntrol Register                                            */
    __IOM uint32  IFLS;                         /*!< (@ 0x00000034) Interrupt FIFO Level Select Register                       */
    __IOM uint32  IMSC;                         /*!< (@ 0x00000038) Interrupt Mask set_Clear Register                          */
    __IM  uint32  RIS;                          /*!< (@ 0x0000003C) Raw Interrupt Status Register                              */
    __IM  uint32  MIS;                          /*!< (@ 0x00000040) Masked Interrupt Status Register                           */
    __OM  uint32  ICR;                          /*!< (@ 0x00000044) Interrupt Clear Register                                   */
    __IOM uint32  DMACR;                        /*!< (@ 0x00000048) DMA Control Register                                       */
    __IM  uint32  RESERVED2[21];
    __IOM uint32  TMSC;                         /*!< (@ 0x000000A0) DMA Trigger Register                                       */
    __IM  uint32  RESERVED3[975];
    __IM  uint32  PIDR0;                        /*!< (@ 0x00000FE0) Peripheral ID 0 Register                                   */
    __IM  uint32  PIDR1;                        /*!< (@ 0x00000FE4) Peripheral ID 1 Register                                   */
    __IM  uint32  PIDR2;                        /*!< (@ 0x00000FE8) Peripheral ID 2 Register                                   */
    __IM  uint32  PIDR3;                        /*!< (@ 0x00000FEC) Peripheral ID 3 Register                                   */
    __IM  uint32  CIDR0;                        /*!< (@ 0x00000FF0) Component ID 0 Register                                    */
    __IM  uint32  CIDR1;                        /*!< (@ 0x00000FF4) Component ID 1 Register                                    */
    __IM  uint32  CIDR2;                              /*!< (@ 0x00000FF8) Component ID 2 Register                                    */
    __IM  uint32  CIDR3;                              /*!< (@ 0x00000FFC) Component ID 3 Register                                    */
} Uart_RegType, *UART_RegMemMapPtr;                   /*!< Size = 4096 (0x1000)                                                      */


/** Number of instances of the UART module. */
#define UART_INSTANCE_COUNT                       (4u)

/* UART - Peripheral instance base addresses */
/** Peripheral UART base address */
#define IP_UART0_BASE                              (0x400A5000UL)
#define IP_UART1_BASE                              (0x400A6000UL)
#define IP_UART2_BASE                              (0x400D7000UL)
#define IP_UART3_BASE                              (0x400D8000UL)
/** Peripheral UART base pointer */
#define IP_UART0                                   ((Uart_RegType *)IP_UART0_BASE)
#define IP_UART1                                   ((Uart_RegType *)IP_UART1_BASE)
#define IP_UART2                                   ((Uart_RegType *)IP_UART2_BASE)
#define IP_UART3                                   ((Uart_RegType *)IP_UART3_BASE)
/** Array initializer of UART peripheral base addresses */
#define IP_UART_BASE_ADDRS                        { IP_UART0_BASE, IP_UART1_BASE,IP_UART2_BASE,IP_UART3_BASE}
/** Array initializer of UART peripheral base pointers */
#define IP_UART_BASE_PTRS                         { IP_UART0, IP_UART1, IP_UART2, IP_UART3 }

/* =========================================================================================================================== */
/* ================                                       TT_UART0                                        ================ */
/* =========================================================================================================================== */

/* ==========================================================  DR  =========================================================== */
#define TT_UART0_DR_DATA_Pos          (0UL)                     /*!< TT_UART0 DR: DATA (Bit 0)                         */
#define TT_UART0_DR_DATA_Msk          (0xffUL)                  /*!< TT_UART0 DR: DATA (Bitfield-Mask: 0xff)           */
#define TT_UART0_DR_FE_Pos            (8UL)                     /*!< TT_UART0 DR: FE (Bit 8)                           */
#define TT_UART0_DR_FE_Msk            (0x100UL)                 /*!< TT_UART0 DR: FE (Bitfield-Mask: 0x01)             */
#define TT_UART0_DR_PE_Pos            (9UL)                     /*!< TT_UART0 DR: PE (Bit 9)                           */
#define TT_UART0_DR_PE_Msk            (0x200UL)                 /*!< TT_UART0 DR: PE (Bitfield-Mask: 0x01)             */
#define TT_UART0_DR_BE_Pos            (10UL)                    /*!< TT_UART0 DR: BE (Bit 10)                          */
#define TT_UART0_DR_BE_Msk            (0x400UL)                 /*!< TT_UART0 DR: BE (Bitfield-Mask: 0x01)             */
#define TT_UART0_DR_OE_Pos            (11UL)                    /*!< TT_UART0 DR: OE (Bit 11)                          */
#define TT_UART0_DR_OE_Msk            (0x800UL)                 /*!< TT_UART0 DR: OE (Bitfield-Mask: 0x01)             */
/* ==========================================================  RSR  ========================================================== */
#define TT_UART0_RSR_FE_Pos           (0UL)                     /*!< TT_UART0 RSR: FE (Bit 0)                          */
#define TT_UART0_RSR_FE_Msk           (0x1UL)                   /*!< TT_UART0 RSR: FE (Bitfield-Mask: 0x01)            */
#define TT_UART0_RSR_PE_Pos           (1UL)                     /*!< TT_UART0 RSR: PE (Bit 1)                          */
#define TT_UART0_RSR_PE_Msk           (0x2UL)                   /*!< TT_UART0 RSR: PE (Bitfield-Mask: 0x01)            */
#define TT_UART0_RSR_BE_Pos           (2UL)                     /*!< TT_UART0 RSR: BE (Bit 2)                          */
#define TT_UART0_RSR_BE_Msk           (0x4UL)                   /*!< TT_UART0 RSR: BE (Bitfield-Mask: 0x01)            */
#define TT_UART0_RSR_OE_Pos           (3UL)                     /*!< TT_UART0 RSR: OE (Bit 3)                          */
#define TT_UART0_RSR_OE_Msk           (0x8UL)                   /*!< TT_UART0 RSR: OE (Bitfield-Mask: 0x01)            */
/* ==========================================================  ECR  ========================================================== */
#define TT_UART0_ECR_FE_Pos           (0UL)                     /*!< TT_UART0 ECR: FE (Bit 0)                          */
#define TT_UART0_ECR_FE_Msk           (0x1UL)                   /*!< TT_UART0 ECR: FE (Bitfield-Mask: 0x01)            */
#define TT_UART0_ECR_PE_Pos           (1UL)                     /*!< TT_UART0 ECR: PE (Bit 1)                          */
#define TT_UART0_ECR_PE_Msk           (0x2UL)                   /*!< TT_UART0 ECR: PE (Bitfield-Mask: 0x01)            */
#define TT_UART0_ECR_BE_Pos           (2UL)                     /*!< TT_UART0 ECR: BE (Bit 2)                          */
#define TT_UART0_ECR_BE_Msk           (0x4UL)                   /*!< TT_UART0 ECR: BE (Bitfield-Mask: 0x01)            */
#define TT_UART0_ECR_OE_Pos           (3UL)                     /*!< TT_UART0 ECR: OE (Bit 3)                          */
#define TT_UART0_ECR_OE_Msk           (0x8UL)                   /*!< TT_UART0 ECR: OE (Bitfield-Mask: 0x01)            */
/* ==========================================================  FR  =========================================================== */
#define TT_UART0_FR_CTS_Pos           (0UL)                     /*!< TT_UART0 FR: CTS (Bit 0)                          */
#define TT_UART0_FR_CTS_Msk           (0x1UL)                   /*!< TT_UART0 FR: CTS (Bitfield-Mask: 0x01)            */
#define TT_UART0_FR_DSR_Pos           (1UL)                     /*!< TT_UART0 FR: DSR (Bit 1)                          */
#define TT_UART0_FR_DSR_Msk           (0x2UL)                   /*!< TT_UART0 FR: DSR (Bitfield-Mask: 0x01)            */
#define TT_UART0_FR_DCD_Pos           (2UL)                     /*!< TT_UART0 FR: DCD (Bit 2)                          */
#define TT_UART0_FR_DCD_Msk           (0x4UL)                   /*!< TT_UART0 FR: DCD (Bitfield-Mask: 0x01)            */
#define TT_UART0_FR_BUSY_Pos          (3UL)                     /*!< TT_UART0 FR: BUSY (Bit 3)                         */
#define TT_UART0_FR_BUSY_Msk          (0x8UL)                   /*!< TT_UART0 FR: BUSY (Bitfield-Mask: 0x01)           */
#define TT_UART0_FR_RXFE_Pos          (4UL)                     /*!< TT_UART0 FR: RXFE (Bit 4)                         */
#define TT_UART0_FR_RXFE_Msk          (0x10UL)                  /*!< TT_UART0 FR: RXFE (Bitfield-Mask: 0x01)           */
#define TT_UART0_FR_TXFF_Pos          (5UL)                     /*!< TT_UART0 FR: TXFF (Bit 5)                         */
#define TT_UART0_FR_TXFF_Msk          (0x20UL)                  /*!< TT_UART0 FR: TXFF (Bitfield-Mask: 0x01)           */
#define TT_UART0_FR_RXFF_Pos          (6UL)                     /*!< TT_UART0 FR: RXFF (Bit 6)                         */
#define TT_UART0_FR_RXFF_Msk          (0x40UL)                  /*!< TT_UART0 FR: RXFF (Bitfield-Mask: 0x01)           */
#define TT_UART0_FR_TXFE_Pos          (7UL)                     /*!< TT_UART0 FR: TXFE (Bit 7)                         */
#define TT_UART0_FR_TXFE_Msk          (0x80UL)                  /*!< TT_UART0 FR: TXFE (Bitfield-Mask: 0x01)           */
#define TT_UART0_FR_RI_Pos            (8UL)                     /*!< TT_UART0 FR: RI (Bit 8)                           */
#define TT_UART0_FR_RI_Msk            (0x100UL)                 /*!< TT_UART0 FR: RI (Bitfield-Mask: 0x01)             */
/* =========================================================  ILPR  ========================================================== */
#define TT_UART0_ILPR_ILPDVSR_Pos     (0UL)                     /*!< TT_UART0 ILPR: ILPDVSR (Bit 0)                    */
#define TT_UART0_ILPR_ILPDVSR_Msk     (0xffUL)                  /*!< TT_UART0 ILPR: ILPDVSR (Bitfield-Mask: 0xff)      */
/* =========================================================  IBDR  ========================================================== */
#define TT_UART0_IBDR_BAUDDIVINT_Pos  (0UL)                     /*!< TT_UART0 IBDR: BAUDDIVINT (Bit 0)                 */
#define TT_UART0_IBDR_BAUDDIVINT_Msk  (0xffffUL)                /*!< TT_UART0 IBDR: BAUDDIVINT (Bitfield-Mask: 0xffff) */
/* =========================================================  FBDR  ========================================================== */
#define TT_UART0_FBDR_BAUDDIVFRAC_Pos (0UL)                     /*!< TT_UART0 FBDR: BAUDDIVFRAC (Bit 0)                */
#define TT_UART0_FBDR_BAUDDIVFRAC_Msk (0x3fUL)                  /*!< TT_UART0 FBDR: BAUDDIVFRAC (Bitfield-Mask: 0x3f)  */
/* =========================================================  LCR_H  ========================================================= */
#define TT_UART0_LCR_H_BRK_Pos        (0UL)                     /*!< TT_UART0 LCR_H: BRK (Bit 0)                       */
#define TT_UART0_LCR_H_BRK_Msk        (0x1UL)                   /*!< TT_UART0 LCR_H: BRK (Bitfield-Mask: 0x01)         */
#define TT_UART0_LCR_H_PEN_Pos        (1UL)                     /*!< TT_UART0 LCR_H: PEN (Bit 1)                       */
#define TT_UART0_LCR_H_PEN_Msk        (0x2UL)                   /*!< TT_UART0 LCR_H: PEN (Bitfield-Mask: 0x01)         */
#define TT_UART0_LCR_H_EPS_Pos        (2UL)                     /*!< TT_UART0 LCR_H: EPS (Bit 2)                       */
#define TT_UART0_LCR_H_EPS_Msk        (0x4UL)                   /*!< TT_UART0 LCR_H: EPS (Bitfield-Mask: 0x01)         */
#define TT_UART0_LCR_H_STP2_Pos       (3UL)                     /*!< TT_UART0 LCR_H: STP2 (Bit 3)                      */
#define TT_UART0_LCR_H_STP2_Msk       (0x8UL)                   /*!< TT_UART0 LCR_H: STP2 (Bitfield-Mask: 0x01)        */
#define TT_UART0_LCR_H_FEN_Pos        (4UL)                     /*!< TT_UART0 LCR_H: FEN (Bit 4)                       */
#define TT_UART0_LCR_H_FEN_Msk        (0x10UL)                  /*!< TT_UART0 LCR_H: FEN (Bitfield-Mask: 0x01)         */
#define TT_UART0_LCR_H_WLEN_Pos       (5UL)                     /*!< TT_UART0 LCR_H: WLEN (Bit 5)                      */
#define TT_UART0_LCR_H_WLEN_Msk       (0x60UL)                  /*!< TT_UART0 LCR_H: WLEN (Bitfield-Mask: 0x03)        */
#define TT_UART0_LCR_H_SPS_Pos        (7UL)                     /*!< TT_UART0 LCR_H: SPS (Bit 7)                       */
#define TT_UART0_LCR_H_SPS_Msk        (0x80UL)                  /*!< TT_UART0 LCR_H: SPS (Bitfield-Mask: 0x01)         */
/* ==========================================================  CR  =========================================================== */
#define TT_UART0_CR_UARTEN_Pos        (0UL)                     /*!< TT_UART0 CR: UARTEN (Bit 0)                       */
#define TT_UART0_CR_UARTEN_Msk        (0x1UL)                   /*!< TT_UART0 CR: UARTEN (Bitfield-Mask: 0x01)         */
#define TT_UART0_CR_SIREN_Pos         (1UL)                     /*!< TT_UART0 CR: SIREN (Bit 1)                        */
#define TT_UART0_CR_SIREN_Msk         (0x2UL)                   /*!< TT_UART0 CR: SIREN (Bitfield-Mask: 0x01)          */
#define TT_UART0_CR_SIRLP_Pos         (2UL)                     /*!< TT_UART0 CR: SIRLP (Bit 2)                        */
#define TT_UART0_CR_SIRLP_Msk         (0x4UL)                   /*!< TT_UART0 CR: SIRLP (Bitfield-Mask: 0x01)          */
#define TT_UART0_CR_TXE_Pos           (8UL)                     /*!< TT_UART0 CR: TXE (Bit 8)                          */
#define TT_UART0_CR_TXE_Msk           (0x100UL)                 /*!< TT_UART0 CR: TXE (Bitfield-Mask: 0x01)            */
#define TT_UART0_CR_RXE_Pos           (9UL)                     /*!< TT_UART0 CR: RXE (Bit 9)                          */
#define TT_UART0_CR_RXE_Msk           (0x200UL)                 /*!< TT_UART0 CR: RXE (Bitfield-Mask: 0x01)            */
#define TT_UART0_CR_DTR_Pos           (10UL)                    /*!< TT_UART0 CR: DTR (Bit 10)                         */
#define TT_UART0_CR_DTR_Msk           (0x400UL)                 /*!< TT_UART0 CR: DTR (Bitfield-Mask: 0x01)            */
#define TT_UART0_CR_RTS_Pos           (11UL)                    /*!< TT_UART0 CR: RTS (Bit 11)                         */
#define TT_UART0_CR_RTS_Msk           (0x800UL)                 /*!< TT_UART0 CR: RTS (Bitfield-Mask: 0x01)            */
#define TT_UART0_CR_RTSEN_Pos         (14UL)                    /*!< TT_UART0 CR: RTSEN (Bit 14)                       */
#define TT_UART0_CR_RTSEN_Msk         (0x4000UL)                /*!< TT_UART0 CR: RTSEN (Bitfield-Mask: 0x01)          */
#define TT_UART0_CR_CTSEN_Pos         (15UL)                    /*!< TT_UART0 CR: CTSEN (Bit 15)                       */
#define TT_UART0_CR_CTSEN_Msk         (0x8000UL)                /*!< TT_UART0 CR: CTSEN (Bitfield-Mask: 0x01)          */
/* =========================================================  IFLS  ========================================================== */
#define TT_UART0_IFLS_TXIFLSEL_Pos    (0UL)                     /*!< TT_UART0 IFLS: TXIFLSEL (Bit 0)                   */
#define TT_UART0_IFLS_TXIFLSEL_Msk    (0x7UL)                   /*!< TT_UART0 IFLS: TXIFLSEL (Bitfield-Mask: 0x07)     */
#define TT_UART0_IFLS_RXIFLSEL_Pos    (3UL)                     /*!< TT_UART0 IFLS: RXIFLSEL (Bit 3)                   */
#define TT_UART0_IFLS_RXIFLSEL_Msk    (0x38UL)                  /*!< TT_UART0 IFLS: RXIFLSEL (Bitfield-Mask: 0x07)     */
/* =========================================================  IMSC  ========================================================== */
#define TT_UART0_IMSC_RIMIM_Pos       (0UL)                     /*!< TT_UART0 IMSC: RIMIM (Bit 0)                      */
#define TT_UART0_IMSC_RIMIM_Msk       (0x1UL)                   /*!< TT_UART0 IMSC: RIMIM (Bitfield-Mask: 0x01)        */
#define TT_UART0_IMSC_CTSMIM_Pos      (1UL)                     /*!< TT_UART0 IMSC: CTSMIM (Bit 1)                     */
#define TT_UART0_IMSC_CTSMIM_Msk      (0x2UL)                   /*!< TT_UART0 IMSC: CTSMIM (Bitfield-Mask: 0x01)       */
#define TT_UART0_IMSC_DCDMIM_Pos      (2UL)                     /*!< TT_UART0 IMSC: DCDMIM (Bit 2)                     */
#define TT_UART0_IMSC_DCDMIM_Msk      (0x4UL)                   /*!< TT_UART0 IMSC: DCDMIM (Bitfield-Mask: 0x01)       */
#define TT_UART0_IMSC_DSRMIM_Pos      (3UL)                     /*!< TT_UART0 IMSC: DSRMIM (Bit 3)                     */
#define TT_UART0_IMSC_DSRMIM_Msk      (0x8UL)                   /*!< TT_UART0 IMSC: DSRMIM (Bitfield-Mask: 0x01)       */
#define TT_UART0_IMSC_RXIM_Pos        (4UL)                     /*!< TT_UART0 IMSC: RXIM (Bit 4)                       */
#define TT_UART0_IMSC_RXIM_Msk        (0x10UL)                  /*!< TT_UART0 IMSC: RXIM (Bitfield-Mask: 0x01)         */
#define TT_UART0_IMSC_TXIM_Pos        (5UL)                     /*!< TT_UART0 IMSC: TXIM (Bit 5)                       */
#define TT_UART0_IMSC_TXIM_Msk        (0x20UL)                  /*!< TT_UART0 IMSC: TXIM (Bitfield-Mask: 0x01)         */
#define TT_UART0_IMSC_RTIM_Pos        (6UL)                     /*!< TT_UART0 IMSC: RTIM (Bit 6)                       */
#define TT_UART0_IMSC_RTIM_Msk        (0x40UL)                  /*!< TT_UART0 IMSC: RTIM (Bitfield-Mask: 0x01)         */
#define TT_UART0_IMSC_FEIM_Pos        (7UL)                     /*!< TT_UART0 IMSC: FEIM (Bit 7)                       */
#define TT_UART0_IMSC_FEIM_Msk        (0x80UL)                  /*!< TT_UART0 IMSC: FEIM (Bitfield-Mask: 0x01)         */
#define TT_UART0_IMSC_PEIM_Pos        (8UL)                     /*!< TT_UART0 IMSC: PEIM (Bit 8)                       */
#define TT_UART0_IMSC_PEIM_Msk        (0x100UL)                 /*!< TT_UART0 IMSC: PEIM (Bitfield-Mask: 0x01)         */
#define TT_UART0_IMSC_BEIM_Pos        (9UL)                     /*!< TT_UART0 IMSC: BEIM (Bit 9)                       */
#define TT_UART0_IMSC_BEIM_Msk        (0x200UL)                 /*!< TT_UART0 IMSC: BEIM (Bitfield-Mask: 0x01)         */
#define TT_UART0_IMSC_OEIM_Pos        (10UL)                    /*!< TT_UART0 IMSC: OEIM (Bit 10)                      */
#define TT_UART0_IMSC_OEIM_Msk        (0x400UL)                 /*!< TT_UART0 IMSC: OEIM (Bitfield-Mask: 0x01)         */
/* ==========================================================  RIS  ========================================================== */
#define TT_UART0_RIS_RIRMIS_Pos       (0UL)                     /*!< TT_UART0 RIS: RIRMIS (Bit 0)                      */
#define TT_UART0_RIS_RIRMIS_Msk       (0x1UL)                   /*!< TT_UART0 RIS: RIRMIS (Bitfield-Mask: 0x01)        */
#define TT_UART0_RIS_CTSRMIS_Pos      (1UL)                     /*!< TT_UART0 RIS: CTSRMIS (Bit 1)                     */
#define TT_UART0_RIS_CTSRMIS_Msk      (0x2UL)                   /*!< TT_UART0 RIS: CTSRMIS (Bitfield-Mask: 0x01)       */
#define TT_UART0_RIS_DCDRMIS_Pos      (2UL)                     /*!< TT_UART0 RIS: DCDRMIS (Bit 2)                     */
#define TT_UART0_RIS_DCDRMIS_Msk      (0x4UL)                   /*!< TT_UART0 RIS: DCDRMIS (Bitfield-Mask: 0x01)       */
#define TT_UART0_RIS_DSRRMIS_Pos      (3UL)                     /*!< TT_UART0 RIS: DSRRMIS (Bit 3)                     */
#define TT_UART0_RIS_DSRRMIS_Msk      (0x8UL)                   /*!< TT_UART0 RIS: DSRRMIS (Bitfield-Mask: 0x01)       */
#define TT_UART0_RIS_RXRIS_Pos        (4UL)                     /*!< TT_UART0 RIS: RXRIS (Bit 4)                       */
#define TT_UART0_RIS_RXRIS_Msk        (0x10UL)                  /*!< TT_UART0 RIS: RXRIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_RIS_TXRIS_Pos        (5UL)                     /*!< TT_UART0 RIS: TXRIS (Bit 5)                       */
#define TT_UART0_RIS_TXRIS_Msk        (0x20UL)                  /*!< TT_UART0 RIS: TXRIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_RIS_RTRIS_Pos        (6UL)                     /*!< TT_UART0 RIS: RTRIS (Bit 6)                       */
#define TT_UART0_RIS_RTRIS_Msk        (0x40UL)                  /*!< TT_UART0 RIS: RTRIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_RIS_FERIS_Pos        (7UL)                     /*!< TT_UART0 RIS: FERIS (Bit 7)                       */
#define TT_UART0_RIS_FERIS_Msk        (0x80UL)                  /*!< TT_UART0 RIS: FERIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_RIS_PERIS_Pos        (8UL)                     /*!< TT_UART0 RIS: PERIS (Bit 8)                       */
#define TT_UART0_RIS_PERIS_Msk        (0x100UL)                 /*!< TT_UART0 RIS: PERIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_RIS_BERIS_Pos        (9UL)                     /*!< TT_UART0 RIS: BERIS (Bit 9)                       */
#define TT_UART0_RIS_BERIS_Msk        (0x200UL)                 /*!< TT_UART0 RIS: BERIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_RIS_OERIS_Pos        (10UL)                    /*!< TT_UART0 RIS: OERIS (Bit 10)                      */
#define TT_UART0_RIS_OERIS_Msk        (0x400UL)                 /*!< TT_UART0 RIS: OERIS (Bitfield-Mask: 0x01)         */
/* ==========================================================  MIS  ========================================================== */
#define TT_UART0_MIS_RIMMIS_Pos       (0UL)                     /*!< TT_UART0 MIS: RIMMIS (Bit 0)                      */
#define TT_UART0_MIS_RIMMIS_Msk       (0x1UL)                   /*!< TT_UART0 MIS: RIMMIS (Bitfield-Mask: 0x01)        */
#define TT_UART0_MIS_CTSMMIS_Pos      (1UL)                     /*!< TT_UART0 MIS: CTSMMIS (Bit 1)                     */
#define TT_UART0_MIS_CTSMMIS_Msk      (0x2UL)                   /*!< TT_UART0 MIS: CTSMMIS (Bitfield-Mask: 0x01)       */
#define TT_UART0_MIS_DCDMMIS_Pos      (2UL)                     /*!< TT_UART0 MIS: DCDMMIS (Bit 2)                     */
#define TT_UART0_MIS_DCDMMIS_Msk      (0x4UL)                   /*!< TT_UART0 MIS: DCDMMIS (Bitfield-Mask: 0x01)       */
#define TT_UART0_MIS_DSRMMIS_Pos      (3UL)                     /*!< TT_UART0 MIS: DSRMMIS (Bit 3)                     */
#define TT_UART0_MIS_DSRMMIS_Msk      (0x8UL)                   /*!< TT_UART0 MIS: DSRMMIS (Bitfield-Mask: 0x01)       */
#define TT_UART0_MIS_RXMIS_Pos        (4UL)                     /*!< TT_UART0 MIS: RXMIS (Bit 4)                       */
#define TT_UART0_MIS_RXMIS_Msk        (0x10UL)                  /*!< TT_UART0 MIS: RXMIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_MIS_TXMIS_Pos        (5UL)                     /*!< TT_UART0 MIS: TXMIS (Bit 5)                       */
#define TT_UART0_MIS_TXMIS_Msk        (0x20UL)                  /*!< TT_UART0 MIS: TXMIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_MIS_RTMIS_Pos        (6UL)                     /*!< TT_UART0 MIS: RTMIS (Bit 6)                       */
#define TT_UART0_MIS_RTMIS_Msk        (0x40UL)                  /*!< TT_UART0 MIS: RTMIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_MIS_FEMIS_Pos        (7UL)                     /*!< TT_UART0 MIS: FEMIS (Bit 7)                       */
#define TT_UART0_MIS_FEMIS_Msk        (0x80UL)                  /*!< TT_UART0 MIS: FEMIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_MIS_PEMIS_Pos        (8UL)                     /*!< TT_UART0 MIS: PEMIS (Bit 8)                       */
#define TT_UART0_MIS_PEMIS_Msk        (0x100UL)                 /*!< TT_UART0 MIS: PEMIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_MIS_BEMIS_Pos        (9UL)                     /*!< TT_UART0 MIS: BEMIS (Bit 9)                       */
#define TT_UART0_MIS_BEMIS_Msk        (0x200UL)                 /*!< TT_UART0 MIS: BEMIS (Bitfield-Mask: 0x01)         */
#define TT_UART0_MIS_OEMIS_Pos        (10UL)                    /*!< TT_UART0 MIS: OEMIS (Bit 10)                      */
#define TT_UART0_MIS_OEMIS_Msk        (0x400UL)                 /*!< TT_UART0 MIS: OEMIS (Bitfield-Mask: 0x01)         */
/* ==========================================================  ICR  ========================================================== */
#define TT_UART0_ICR_RIMIC_Pos        (0UL)                     /*!< TT_UART0 ICR: RIMIC (Bit 0)                       */
#define TT_UART0_ICR_RIMIC_Msk        (0x1UL)                   /*!< TT_UART0 ICR: RIMIC (Bitfield-Mask: 0x01)         */
#define TT_UART0_ICR_CTSMIC_Pos       (1UL)                     /*!< TT_UART0 ICR: CTSMIC (Bit 1)                      */
#define TT_UART0_ICR_CTSMIC_Msk       (0x2UL)                   /*!< TT_UART0 ICR: CTSMIC (Bitfield-Mask: 0x01)        */
#define TT_UART0_ICR_DCDMIC_Pos       (2UL)                     /*!< TT_UART0 ICR: DCDMIC (Bit 2)                      */
#define TT_UART0_ICR_DCDMIC_Msk       (0x4UL)                   /*!< TT_UART0 ICR: DCDMIC (Bitfield-Mask: 0x01)        */
#define TT_UART0_ICR_DSRMIC_Pos       (3UL)                     /*!< TT_UART0 ICR: DSRMIC (Bit 3)                      */
#define TT_UART0_ICR_DSRMIC_Msk       (0x8UL)                   /*!< TT_UART0 ICR: DSRMIC (Bitfield-Mask: 0x01)        */
#define TT_UART0_ICR_RXIC_Pos         (4UL)                     /*!< TT_UART0 ICR: RXIC (Bit 4)                        */
#define TT_UART0_ICR_RXIC_Msk         (0x10UL)                  /*!< TT_UART0 ICR: RXIC (Bitfield-Mask: 0x01)          */
#define TT_UART0_ICR_TXIC_Pos         (5UL)                     /*!< TT_UART0 ICR: TXIC (Bit 5)                        */
#define TT_UART0_ICR_TXIC_Msk         (0x20UL)                  /*!< TT_UART0 ICR: TXIC (Bitfield-Mask: 0x01)          */
#define TT_UART0_ICR_RTIC_Pos         (6UL)                     /*!< TT_UART0 ICR: RTIC (Bit 6)                        */
#define TT_UART0_ICR_RTIC_Msk         (0x40UL)                  /*!< TT_UART0 ICR: RTIC (Bitfield-Mask: 0x01)          */
#define TT_UART0_ICR_FEIC_Pos         (7UL)                     /*!< TT_UART0 ICR: FEIC (Bit 7)                        */
#define TT_UART0_ICR_FEIC_Msk         (0x80UL)                  /*!< TT_UART0 ICR: FEIC (Bitfield-Mask: 0x01)          */
#define TT_UART0_ICR_PEIC_Pos         (8UL)                     /*!< TT_UART0 ICR: PEIC (Bit 8)                        */
#define TT_UART0_ICR_PEIC_Msk         (0x100UL)                 /*!< TT_UART0 ICR: PEIC (Bitfield-Mask: 0x01)          */
#define TT_UART0_ICR_BEIC_Pos         (9UL)                     /*!< TT_UART0 ICR: BEIC (Bit 9)                        */
#define TT_UART0_ICR_BEIC_Msk         (0x200UL)                 /*!< TT_UART0 ICR: BEIC (Bitfield-Mask: 0x01)          */
#define TT_UART0_ICR_OEIC_Pos         (10UL)                    /*!< TT_UART0 ICR: OEIC (Bit 10)                       */
#define TT_UART0_ICR_OEIC_Msk         (0x400UL)                 /*!< TT_UART0 ICR: OEIC (Bitfield-Mask: 0x01)          */
/* =========================================================  DMACR  ========================================================= */
#define TT_UART0_DMACR_RXDMAE_Pos     (0UL)                     /*!< TT_UART0 DMACR: RXDMAE (Bit 0)                    */
#define TT_UART0_DMACR_RXDMAE_Msk     (0x1UL)                   /*!< TT_UART0 DMACR: RXDMAE (Bitfield-Mask: 0x01)      */
#define TT_UART0_DMACR_TXDMAE_Pos     (1UL)                     /*!< TT_UART0 DMACR: TXDMAE (Bit 1)                    */
#define TT_UART0_DMACR_TXDMAE_Msk     (0x2UL)                   /*!< TT_UART0 DMACR: TXDMAE (Bitfield-Mask: 0x01)      */
#define TT_UART0_DMACR_DMAONERR_Pos   (2UL)                     /*!< TT_UART0 DMACR: DMAONERR (Bit 2)                  */
#define TT_UART0_DMACR_DMAONERR_Msk   (0x4UL)                   /*!< TT_UART0 DMACR: DMAONERR (Bitfield-Mask: 0x01)    */
/* =========================================================  TMSC  ========================================================= */
#define TT_UART0_TMSC_RXTM_Pos     (4UL)                       /*!< TT_UART0 TMSC: RXTM (Bit 0)                    */
#define TT_UART0_TMSC_RXTM_Msk     (0x10UL)                    /*!< TT_UART0 TMSC: RXTM (Bitfield-Mask: 0x01)      */
#define TT_UART0_TMSC_TXTM_Pos     (5UL)                       /*!< TT_UART0 TMSC: TXTM (Bit 1)                    */
#define TT_UART0_TMSC_TXTM_Msk     (0x20UL)                    /*!< TT_UART0 TMSC: TXTM (Bitfield-Mask: 0x01)      */
/* =========================================================  PIDR0  ========================================================= */
/* =========================================================  PIDR1  ========================================================= */
/* =========================================================  PIDR2  ========================================================= */
/* =========================================================  PIDR3  ========================================================= */
/* =========================================================  CIDR0  ========================================================= */
/* =========================================================  CIDR1  ========================================================= */
/* =========================================================  CIDR2  ========================================================= */
/* =========================================================  CIDR3  ========================================================= */

#ifdef __cplusplus
}
#endif

#endif  /* end of A8V2_UART_H */
