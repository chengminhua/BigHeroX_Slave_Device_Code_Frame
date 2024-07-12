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
#ifndef A8V2_CAN_H
#define A8V2_CAN_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_CAN_VENDOR_ID_H                     1541
#define A8V2_CAN_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_CAN_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_CAN_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_CAN_SW_MAJOR_VERSION_H              1
#define A8V2_CAN_SW_MINOR_VERSION_H              1
#define A8V2_CAN_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_CAN.h and TT_Common.h file version check */
#if (A8V2_CAN_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_CAN.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_CAN_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_CAN_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_CAN_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_CAN.h and TT_Common.h are different"
#endif
#if ((A8V2_CAN_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_CAN_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_CAN_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_CAN.h and TT_Common.h are different"
#endif


/**
  * @brief TT_CAN0_WMB [WMB] (WMB cluster)
  */
typedef struct {
  __IM  uint32_t  FLEXCAN_WMB_CS;               /*!< (@ 0x00000000) Each of the four WMBs contains a register to
                                                                    store the Control Status information.                      */
  __IM  uint32_t  FLEXCAN_WMB_ID;               /*!< (@ 0x00000004) Each of the four WMBs contains a register to
                                                                    store the ID information.                                  */
  __IM  uint32_t  FLEXCAN_WMB_D03;              /*!< (@ 0x00000008) Each of the four WMBs contains a register to
                                                                    store the data byte.                                       */
  __IM  uint32_t  FLEXCAN_WMB_D47;              /*!< (@ 0x0000000C) Each of the four WMBs contains a register to
                                                                    store the data byte.                                       */
} TT_CAN0_WMB_Type;                         /*!< Size = 16 (0x10)                                                          */

/* =========================================================================================================================== */
/* ================                                        TT_CAN0                                        ================ */
/* =========================================================================================================================== */


/**
  * @brief FLEXCAN 0 (TT_CAN0)
  */

typedef struct {                                /*!< (@ 0x400C0000) TT_CAN0 Structure                                      */
  __IOM uint32_t  FLEXCAN_MCR;                  /*!< (@ 0x00000000) Module Configuration Register                              */
  __IOM uint32_t  FLEXCAN_CTRL1;                /*!< (@ 0x00000004) Control 1 Register                                         */
  __IOM uint32_t  FLEXCAN_TIMER;                /*!< (@ 0x00000008) Free Running Timer Register                                */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  FLEXCAN_RXMGMASK;             /*!< (@ 0x00000010) Rx Mailboxes Global Mask Register                          */
  __IOM uint32_t  FLEXCAN_RX14MASK;             /*!< (@ 0x00000014) Rx Buffer 14 Mask Register                                 */
  __IOM uint32_t  FLEXCAN_RX15MASK;             /*!< (@ 0x00000018) Rx Buffer 15 Mask Register                                 */
  __IOM uint32_t  FLEXCAN_ECR;                  /*!< (@ 0x0000001C) Error Counter Register                                     */
  __IOM uint32_t  FLEXCAN_ESR1;                 /*!< (@ 0x00000020) Error and Status 1 Register                                */
  __IOM uint32_t  FLEXCAN_IMASK2;               /*!< (@ 0x00000024) Interrupt Masks 2 Register                                 */
  __IOM uint32_t  FLEXCAN_IMASK1;               /*!< (@ 0x00000028) Interrupt Masks 1 Register                                 */
  __IOM uint32_t  FLEXCAN_IFLAG2;               /*!< (@ 0x0000002C) Interrupt Flags 2 Register                                 */
  __IOM uint32_t  FLEXCAN_IFLAG1;               /*!< (@ 0x00000030) Interrupt Flags 1 Register                                 */
  __IOM uint32_t  FLEXCAN_CTRL2;                /*!< (@ 0x00000034) Control 2 Register                                         */
  __IM  uint32_t  FLEXCAN_ESR2;                 /*!< (@ 0x00000038) Error and Status 2 Register                                */
  __IM  uint32_t  RESERVED1[2];
  __IM  uint32_t  FLEXCAN_CRCR;                 /*!< (@ 0x00000044) CRC Register                                               */
  __IOM uint32_t  FLEXCAN_RXFGMASK;             /*!< (@ 0x00000048) Rx FIFO Global Mask Register                               */
  __IM  uint32_t  FLEXCAN_RXFIR;                /*!< (@ 0x0000004C) Rx FIFO Information Register                               */
  __IOM uint32_t  FLEXCAN_CBT;                  /*!< (@ 0x00000050) The CAN_CBT register is an alternative way to
                                                                    store the CAN bit timing variables described
                                                                    in the CAN_CTRL1 register.                                 */
  __IM  uint32_t  RESERVED2[5];
  __IOM uint32_t  FLEXCAN_IMASK4;               /*!< (@ 0x00000068) The CAN_IMSK4 register allows any number of the
                                                                    32 message buffer interrupt to be enable
                                                                    or disabled for MB127 to MB96.                             */
  __IOM uint32_t  FLEXCAN_IMASK3;               /*!< (@ 0x0000006C) The CAN_IMSK3 register allows any number of the
                                                                    32 message buffer interrupt to be enable
                                                                    or disabled for MB95 to 64.                                */
  __IOM uint32_t  FLEXCAN_IFLAG4;               /*!< (@ 0x00000070) The CAN_IFLAG4 register defines the flag for
                                                                    32 message buffer interrupt for MB127 to
                                                                    MB96.                                                      */
  __IOM uint32_t  FLEXCAN_IFLAG3;               /*!< (@ 0x00000074) The CAN_IFLAG3 register defines the flag for
                                                                    32 message buffer interrupt for MB95 to
                                                                    MB64.                                                      */
  __IM  uint32_t  RESERVED3[2];
  __IOM uint32_t  FLEXCAN_RAMn[512];            /*!< (@ 0x00000080) RAMn Register                                              */
  __IOM uint32_t  FLEXCAN_RXIMR[128];           /*!< (@ 0x00000880) Rx Individual Mask Registers                               */
  __IM  uint32_t  RESERVED4[24];
  __IOM uint32_t  FLEXCAN_MECR;                 /*!< (@ 0x00000AE0) contaubs control bit for memory error detection
                                                                    and correction.                                            */
  __IOM uint32_t  FLEXCAN_ERRIAR;               /*!< (@ 0x00000AE4) Glitch Filter Width Registers                              */
  __IOM uint32_t  FLEXCAN_ERRIDPR;              /*!< (@ 0x00000AE8) Glitch Filter Width Registers                              */
  __IOM uint32_t  FLEXCAN_ERRIPPR;              /*!< (@ 0x00000AEC) The register holds the error pattern to be injected
                                                                    in parity bits read from memort along with
                                                                    data world.                                                */
  __IM  uint32_t  FLEXCAN_RERRAR;               /*!< (@ 0x00000AF0) The register reports the address used for an
                                                                    access in which an error was detected.                     */
  __IM  uint32_t  FLEXCAN_RERRDR;               /*!< (@ 0x00000AF4) The register reports the raw data read from memory
                                                                    with error.                                                */
  __IM  uint32_t  FLEXCAN_RERRSYNR;             /*!< (@ 0x00000AF8) The register hold the syndrome detected in a
                                                                    memory read with error.                                    */
  __IOM uint32_t  FLEXCAN_ERRSR;                /*!< (@ 0x00000AFC) The register hold the status bits if the error
                                                                    correction and detection operations.                       */
  __IOM uint32_t  FLEXCAN_CTRL1_PN;             /*!< (@ 0x00000B00) The register contains bits for Pretended Networking
                                                                    mode filtering selection.                                  */
  __IOM uint32_t  FLEXCAN_CTRL2_PN;             /*!< (@ 0x00000B04) The register contains configuration bits for
                                                                    the timeout value under pretended networking
                                                                    mode.                                                      */
  __IOM uint32_t  FLEXCAN_WU_MTC;               /*!< (@ 0x00000B08) The register contains wakeup information related
                                                                    to matching processes performed.                           */
  __IOM uint32_t  FLEXCAN_FLT_ID1;              /*!< (@ 0x00000B0C) The register contains the FLT_ID1 target value
                                                                    and the IDE and RTR target value used to
                                                                    filter an incoming message.                                */
  __IOM uint32_t  FLEXCAN_FLT_DLC;              /*!< (@ 0x00000B10) The register contains the DLC inside range target
                                                                    values used to filter an incoming message.                 */
  __IOM uint32_t  FLEXCAN_PL1_LO;               /*!< (@ 0x00000B14) The register contains Payload Filter 1 low order
                                                                    bits of the target value used to filter
                                                                    incoming message payload.                                  */
  __IOM uint32_t  FLEXCAN_PL1_HI;               /*!< (@ 0x00000B18) The register contains Payload Filter 1 high order
                                                                    bits of the target value used to filter
                                                                    incoming message payload.                                  */
  __IOM uint32_t  FLEXCAN_FLT_ID2_IDMASK;       /*!< (@ 0x00000B1C) The register contains the FLT_ID2 target value
                                                                    used only as the upper limit value in ID
                                                                    range detection.                                           */
  __IOM uint32_t  FLEXCAN_PL2_PLMASK_LO;        /*!< (@ 0x00000B20) It contains the low order vits for the Payload
                                                                    Filter 2 used only as the upper limit value
                                                                    in a poyload range detection.                              */
  __IOM uint32_t  FLEXCAN_PL2_PLMASK_HI;        /*!< (@ 0x00000B24) It contains the high order vits for the Payload
                                                                    Filter 2 used only as the upper limit value
                                                                    in a poyload range detection.                              */
  __IM  uint32_t  RESERVED5[6];
  __IOM TT_CAN0_WMB_Type WMB[4];            /*!< (@ 0x00000B40) WMB cluster                                                */
  __IM  uint32_t  RESERVED6[28];
  __IOM uint32_t  FLEXCAN_EPRS;                 /*!< (@ 0x00000BF0) CAN bit timing.                                            */
  __IOM uint32_t  FLEXCAN_ENCBT;                /*!< (@ 0x00000BF4) ENCBT.                                                     */
  __IOM uint32_t  FLEXCAN_EDCBT;                /*!< (@ 0x00000BF8) EDCBT.                                                     */
  __IOM uint32_t  FLEXCAN_ETDC;                 /*!< (@ 0x00000BFC) ETDC.                                                      */
  __IOM uint32_t  FLEXCAN_FDCTRL;               /*!< (@ 0x00000C00) It contains the high order vits for the Payload
                                                                    Filter 2 used only as the upper limit value
                                                                    in a poyload range detection.                              */
  __IOM uint32_t  FLEXCAN_FDCBT;                /*!< (@ 0x00000C04) It contains the high order vits for the Payload
                                                                    Filter 2 used only as the upper limit value
                                                                    in a poyload range detection.                              */
  __IM  uint32_t  FLEXCAN_FDCRC;                /*!< (@ 0x00000C08) It contains the high order vits for the Payload
                                                                    Filter 2 used only as the upper limit value
                                                                    in a poyload range detection.                              */
  __IOM uint32_t  FLEXCAN_ERFCR;                /*!< (@ 0x00000C0C) ERFCR.                                                     */
  __IOM uint32_t  FLEXCAN_ERFIER;               /*!< (@ 0x00000C10) ERFIER.                                                    */
  __IOM uint32_t  FLEXCAN_ERFSR;                /*!< (@ 0x00000C14) ERFSR.                                                     */
  __IM  uint32_t  RESERVED7[6];
  __IOM uint32_t  FLEXCAN_HR_TIME_STAMP[128];   /*!< (@ 0x00000C30) High resolution Time Stamp Register.                       */
  __IM  uint32_t  RESERVED8[2164];
  __IOM uint32_t  FLEXCAN_ERFFEL[128];          /*!< (@ 0x00003000) Enhanced Rx Fifo Filter Element Register.                  */
} TT_CAN_Type;                              /*!< Size = 12800 (0x3200)                                                     */


#define TT_CAN0_BASE            0x400C0000UL
#define TT_CAN1_BASE            0x400C4000UL
#define TT_CAN2_BASE            0x400C8000UL
#define TT_CAN3_BASE            0x400CC000UL
#define TT_CAN4_BASE            0x40100000UL
#define TT_CAN5_BASE            0x40104000UL
#define TT_CAN6_BASE            0x40108000UL
#define TT_CAN7_BASE            0x4010C000UL

#define TT_CAN0                 ((TT_CAN_Type*)        TT_CAN0_BASE)
#define TT_CAN1                 ((TT_CAN_Type*)        TT_CAN1_BASE)
#define TT_CAN2                 ((TT_CAN_Type*)        TT_CAN2_BASE)
#define TT_CAN3                 ((TT_CAN_Type*)        TT_CAN3_BASE)
#define TT_CAN4                 ((TT_CAN_Type*)        TT_CAN4_BASE)
#define TT_CAN5                 ((TT_CAN_Type*)        TT_CAN5_BASE)
#define TT_CAN6                 ((TT_CAN_Type*)        TT_CAN6_BASE)
#define TT_CAN7                 ((TT_CAN_Type*)        TT_CAN7_BASE)

#define IP_FLEXCAN_BASE_PTRS       {TT_CAN0, TT_CAN1, TT_CAN2, TT_CAN3, \
									TT_CAN4, TT_CAN5, TT_CAN6, TT_CAN7 }

/* =========================================================================================================================== */
/* ================                                        TT_CAN                                         ================ */
/* =========================================================================================================================== */

/* ======================================================  FLEXCAN_MCR  ====================================================== */
#define TT_CAN_FLEXCAN_MCR_MAXMB_Pos  (0UL)                     /*!< TT_CAN FLEXCAN_MCR: MAXMB (Bit 0)                 */
#define TT_CAN_FLEXCAN_MCR_MAXMB_Msk  (0x7fUL)                  /*!< TT_CAN FLEXCAN_MCR: MAXMB (Bitfield-Mask: 0x7f)   */
#define TT_CAN_FLEXCAN_MCR_IDAM_Pos   (8UL)                     /*!< TT_CAN FLEXCAN_MCR: IDAM (Bit 8)                  */
#define TT_CAN_FLEXCAN_MCR_IDAM_Msk   (0x300UL)                 /*!< TT_CAN FLEXCAN_MCR: IDAM (Bitfield-Mask: 0x03)    */
#define TT_CAN_FLEXCAN_MCR_FDEN_Pos   (11UL)                    /*!< TT_CAN FLEXCAN_MCR: FDEN (Bit 11)                 */
#define TT_CAN_FLEXCAN_MCR_FDEN_Msk   (0x800UL)                 /*!< TT_CAN FLEXCAN_MCR: FDEN (Bitfield-Mask: 0x01)    */
#define TT_CAN_FLEXCAN_MCR_AEN_Pos    (12UL)                    /*!< TT_CAN FLEXCAN_MCR: AEN (Bit 12)                  */
#define TT_CAN_FLEXCAN_MCR_AEN_Msk    (0x1000UL)                /*!< TT_CAN FLEXCAN_MCR: AEN (Bitfield-Mask: 0x01)     */
#define TT_CAN_FLEXCAN_MCR_LPRIOEN_Pos (13UL)                   /*!< TT_CAN FLEXCAN_MCR: LPRIOEN (Bit 13)              */
#define TT_CAN_FLEXCAN_MCR_LPRIOEN_Msk (0x2000UL)               /*!< TT_CAN FLEXCAN_MCR: LPRIOEN (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MCR_PNET_EN_Pos (14UL)                   /*!< TT_CAN FLEXCAN_MCR: PNET_EN (Bit 14)              */
#define TT_CAN_FLEXCAN_MCR_PNET_EN_Msk (0x4000UL)               /*!< TT_CAN FLEXCAN_MCR: PNET_EN (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MCR_DMA_Pos    (15UL)                    /*!< TT_CAN FLEXCAN_MCR: DMA (Bit 15)                  */
#define TT_CAN_FLEXCAN_MCR_DMA_Msk    (0x8000UL)                /*!< TT_CAN FLEXCAN_MCR: DMA (Bitfield-Mask: 0x01)     */
#define TT_CAN_FLEXCAN_MCR_IRMQ_Pos   (16UL)                    /*!< TT_CAN FLEXCAN_MCR: IRMQ (Bit 16)                 */
#define TT_CAN_FLEXCAN_MCR_IRMQ_Msk   (0x10000UL)               /*!< TT_CAN FLEXCAN_MCR: IRMQ (Bitfield-Mask: 0x01)    */
#define TT_CAN_FLEXCAN_MCR_SRXDIS_Pos (17UL)                    /*!< TT_CAN FLEXCAN_MCR: SRXDIS (Bit 17)               */
#define TT_CAN_FLEXCAN_MCR_SRXDIS_Msk (0x20000UL)               /*!< TT_CAN FLEXCAN_MCR: SRXDIS (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_MCR_DOZE_Pos   (18UL)                    /*!< TT_CAN FLEXCAN_MCR: DOZE (Bit 18)                 */
#define TT_CAN_FLEXCAN_MCR_DOZE_Msk   (0x40000UL)               /*!< TT_CAN FLEXCAN_MCR: DOZE (Bitfield-Mask: 0x01)    */
#define TT_CAN_FLEXCAN_MCR_WAKSRC_Pos (19UL)                    /*!< TT_CAN FLEXCAN_MCR: WAKSRC (Bit 19)               */
#define TT_CAN_FLEXCAN_MCR_WAKSRC_Msk (0x80000UL)               /*!< TT_CAN FLEXCAN_MCR: WAKSRC (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_MCR_LPMACK_Pos (20UL)                    /*!< TT_CAN FLEXCAN_MCR: LPMACK (Bit 20)               */
#define TT_CAN_FLEXCAN_MCR_LPMACK_Msk (0x100000UL)              /*!< TT_CAN FLEXCAN_MCR: LPMACK (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_MCR_WRNEN_Pos  (21UL)                    /*!< TT_CAN FLEXCAN_MCR: WRNEN (Bit 21)                */
#define TT_CAN_FLEXCAN_MCR_WRNEN_Msk  (0x200000UL)              /*!< TT_CAN FLEXCAN_MCR: WRNEN (Bitfield-Mask: 0x01)   */
#define TT_CAN_FLEXCAN_MCR_SLFWAK_Pos (22UL)                    /*!< TT_CAN FLEXCAN_MCR: SLFWAK (Bit 22)               */
#define TT_CAN_FLEXCAN_MCR_SLFWAK_Msk (0x400000UL)              /*!< TT_CAN FLEXCAN_MCR: SLFWAK (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_MCR_SUPV_Pos   (23UL)                    /*!< TT_CAN FLEXCAN_MCR: SUPV (Bit 23)                 */
#define TT_CAN_FLEXCAN_MCR_SUPV_Msk   (0x800000UL)              /*!< TT_CAN FLEXCAN_MCR: SUPV (Bitfield-Mask: 0x01)    */
#define TT_CAN_FLEXCAN_MCR_FRZACK_Pos (24UL)                    /*!< TT_CAN FLEXCAN_MCR: FRZACK (Bit 24)               */
#define TT_CAN_FLEXCAN_MCR_FRZACK_Msk (0x1000000UL)             /*!< TT_CAN FLEXCAN_MCR: FRZACK (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_MCR_SOFTRST_Pos (25UL)                   /*!< TT_CAN FLEXCAN_MCR: SOFTRST (Bit 25)              */
#define TT_CAN_FLEXCAN_MCR_SOFTRST_Msk (0x2000000UL)            /*!< TT_CAN FLEXCAN_MCR: SOFTRST (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MCR_WAKMSK_Pos (26UL)                    /*!< TT_CAN FLEXCAN_MCR: WAKMSK (Bit 26)               */
#define TT_CAN_FLEXCAN_MCR_WAKMSK_Msk (0x4000000UL)             /*!< TT_CAN FLEXCAN_MCR: WAKMSK (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_MCR_NOTRDY_Pos (27UL)                    /*!< TT_CAN FLEXCAN_MCR: NOTRDY (Bit 27)               */
#define TT_CAN_FLEXCAN_MCR_NOTRDY_Msk (0x8000000UL)             /*!< TT_CAN FLEXCAN_MCR: NOTRDY (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_MCR_HALT_Pos   (28UL)                    /*!< TT_CAN FLEXCAN_MCR: HALT (Bit 28)                 */
#define TT_CAN_FLEXCAN_MCR_HALT_Msk   (0x10000000UL)            /*!< TT_CAN FLEXCAN_MCR: HALT (Bitfield-Mask: 0x01)    */
#define TT_CAN_FLEXCAN_MCR_RFEN_Pos   (29UL)                    /*!< TT_CAN FLEXCAN_MCR: RFEN (Bit 29)                 */
#define TT_CAN_FLEXCAN_MCR_RFEN_Msk   (0x20000000UL)            /*!< TT_CAN FLEXCAN_MCR: RFEN (Bitfield-Mask: 0x01)    */
#define TT_CAN_FLEXCAN_MCR_FRZ_Pos    (30UL)                    /*!< TT_CAN FLEXCAN_MCR: FRZ (Bit 30)                  */
#define TT_CAN_FLEXCAN_MCR_FRZ_Msk    (0x40000000UL)            /*!< TT_CAN FLEXCAN_MCR: FRZ (Bitfield-Mask: 0x01)     */
#define TT_CAN_FLEXCAN_MCR_MDIS_Pos   (31UL)                    /*!< TT_CAN FLEXCAN_MCR: MDIS (Bit 31)                 */
#define TT_CAN_FLEXCAN_MCR_MDIS_Msk   (0x80000000UL)            /*!< TT_CAN FLEXCAN_MCR: MDIS (Bitfield-Mask: 0x01)    */
/* =====================================================  FLEXCAN_CTRL1  ===================================================== */
#define TT_CAN_FLEXCAN_CTRL1_PROPSEG_Pos (0UL)                  /*!< TT_CAN FLEXCAN_CTRL1: PROPSEG (Bit 0)             */
#define TT_CAN_FLEXCAN_CTRL1_PROPSEG_Msk (0x7UL)                /*!< TT_CAN FLEXCAN_CTRL1: PROPSEG (Bitfield-Mask: 0x07) */
#define TT_CAN_FLEXCAN_CTRL1_LOM_Pos  (3UL)                     /*!< TT_CAN FLEXCAN_CTRL1: LOM (Bit 3)                 */
#define TT_CAN_FLEXCAN_CTRL1_LOM_Msk  (0x8UL)                   /*!< TT_CAN FLEXCAN_CTRL1: LOM (Bitfield-Mask: 0x01)   */
#define TT_CAN_FLEXCAN_CTRL1_LBUF_Pos (4UL)                     /*!< TT_CAN FLEXCAN_CTRL1: LBUF (Bit 4)                */
#define TT_CAN_FLEXCAN_CTRL1_LBUF_Msk (0x10UL)                  /*!< TT_CAN FLEXCAN_CTRL1: LBUF (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_CTRL1_TSYN_Pos (5UL)                     /*!< TT_CAN FLEXCAN_CTRL1: TSYN (Bit 5)                */
#define TT_CAN_FLEXCAN_CTRL1_TSYN_Msk (0x20UL)                  /*!< TT_CAN FLEXCAN_CTRL1: TSYN (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_CTRL1_BOFFREC_Pos (6UL)                  /*!< TT_CAN FLEXCAN_CTRL1: BOFFREC (Bit 6)             */
#define TT_CAN_FLEXCAN_CTRL1_BOFFREC_Msk (0x40UL)               /*!< TT_CAN FLEXCAN_CTRL1: BOFFREC (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL1_SMP_Pos  (7UL)                     /*!< TT_CAN FLEXCAN_CTRL1: SMP (Bit 7)                 */
#define TT_CAN_FLEXCAN_CTRL1_SMP_Msk  (0x80UL)                  /*!< TT_CAN FLEXCAN_CTRL1: SMP (Bitfield-Mask: 0x01)   */
#define TT_CAN_FLEXCAN_CTRL1_RWRNMSK_Pos (10UL)                 /*!< TT_CAN FLEXCAN_CTRL1: RWRNMSK (Bit 10)            */
#define TT_CAN_FLEXCAN_CTRL1_RWRNMSK_Msk (0x400UL)              /*!< TT_CAN FLEXCAN_CTRL1: RWRNMSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL1_TWRNMSK_Pos (11UL)                 /*!< TT_CAN FLEXCAN_CTRL1: TWRNMSK (Bit 11)            */
#define TT_CAN_FLEXCAN_CTRL1_TWRNMSK_Msk (0x800UL)              /*!< TT_CAN FLEXCAN_CTRL1: TWRNMSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL1_LPB_Pos  (12UL)                    /*!< TT_CAN FLEXCAN_CTRL1: LPB (Bit 12)                */
#define TT_CAN_FLEXCAN_CTRL1_LPB_Msk  (0x1000UL)                /*!< TT_CAN FLEXCAN_CTRL1: LPB (Bitfield-Mask: 0x01)   */
#define TT_CAN_FLEXCAN_CTRL1_CLKSRC_Pos (13UL)                  /*!< TT_CAN FLEXCAN_CTRL1: CLKSRC (Bit 13)             */
#define TT_CAN_FLEXCAN_CTRL1_CLKSRC_Msk (0x2000UL)              /*!< TT_CAN FLEXCAN_CTRL1: CLKSRC (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL1_ERRMSK_Pos (14UL)                  /*!< TT_CAN FLEXCAN_CTRL1: ERRMSK (Bit 14)             */
#define TT_CAN_FLEXCAN_CTRL1_ERRMSK_Msk (0x4000UL)              /*!< TT_CAN FLEXCAN_CTRL1: ERRMSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL1_BOFFMSK_Pos (15UL)                 /*!< TT_CAN FLEXCAN_CTRL1: BOFFMSK (Bit 15)            */
#define TT_CAN_FLEXCAN_CTRL1_BOFFMSK_Msk (0x8000UL)             /*!< TT_CAN FLEXCAN_CTRL1: BOFFMSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL1_PSEG2_Pos (16UL)                   /*!< TT_CAN FLEXCAN_CTRL1: PSEG2 (Bit 16)              */
#define TT_CAN_FLEXCAN_CTRL1_PSEG2_Msk (0x70000UL)              /*!< TT_CAN FLEXCAN_CTRL1: PSEG2 (Bitfield-Mask: 0x07) */
#define TT_CAN_FLEXCAN_CTRL1_PSEG1_Pos (19UL)                   /*!< TT_CAN FLEXCAN_CTRL1: PSEG1 (Bit 19)              */
#define TT_CAN_FLEXCAN_CTRL1_PSEG1_Msk (0x380000UL)             /*!< TT_CAN FLEXCAN_CTRL1: PSEG1 (Bitfield-Mask: 0x07) */
#define TT_CAN_FLEXCAN_CTRL1_RJW_Pos  (22UL)                    /*!< TT_CAN FLEXCAN_CTRL1: RJW (Bit 22)                */
#define TT_CAN_FLEXCAN_CTRL1_RJW_Msk  (0xc00000UL)              /*!< TT_CAN FLEXCAN_CTRL1: RJW (Bitfield-Mask: 0x03)   */
#define TT_CAN_FLEXCAN_CTRL1_PRESDIV_Pos (24UL)                 /*!< TT_CAN FLEXCAN_CTRL1: PRESDIV (Bit 24)            */
#define TT_CAN_FLEXCAN_CTRL1_PRESDIV_Msk (0xff000000UL)         /*!< TT_CAN FLEXCAN_CTRL1: PRESDIV (Bitfield-Mask: 0xff) */
/* =====================================================  FLEXCAN_TIMER  ===================================================== */
#define TT_CAN_FLEXCAN_TIMER_TIMER_Pos (0UL)                    /*!< TT_CAN FLEXCAN_TIMER: TIMER (Bit 0)               */
#define TT_CAN_FLEXCAN_TIMER_TIMER_Msk (0xffffUL)               /*!< TT_CAN FLEXCAN_TIMER: TIMER (Bitfield-Mask: 0xffff) */
/* ===================================================  FLEXCAN_RXMGMASK  ==================================================== */
#define TT_CAN_FLEXCAN_RXMGMASK_MG_Pos (0UL)                    /*!< TT_CAN FLEXCAN_RXMGMASK: MG (Bit 0)               */
#define TT_CAN_FLEXCAN_RXMGMASK_MG_Msk (0xffffffffUL)           /*!< TT_CAN FLEXCAN_RXMGMASK: MG (Bitfield-Mask: 0xffffffff) */
/* ===================================================  FLEXCAN_RX14MASK  ==================================================== */
#define TT_CAN_FLEXCAN_RX14MASK_RX14M_Pos (0UL)                 /*!< TT_CAN FLEXCAN_RX14MASK: RX14M (Bit 0)            */
#define TT_CAN_FLEXCAN_RX14MASK_RX14M_Msk (0xffffffffUL)        /*!< TT_CAN FLEXCAN_RX14MASK: RX14M (Bitfield-Mask: 0xffffffff) */
/* ===================================================  FLEXCAN_RX15MASK  ==================================================== */
#define TT_CAN_FLEXCAN_RX15MASK_RX15M_Pos (0UL)                 /*!< TT_CAN FLEXCAN_RX15MASK: RX15M (Bit 0)            */
#define TT_CAN_FLEXCAN_RX15MASK_RX15M_Msk (0xffffffffUL)        /*!< TT_CAN FLEXCAN_RX15MASK: RX15M (Bitfield-Mask: 0xffffffff) */
/* ======================================================  FLEXCAN_ECR  ====================================================== */
#define TT_CAN_FLEXCAN_ECR_TX_ERR_COUNTER_Pos (0UL)             /*!< TT_CAN FLEXCAN_ECR: TX_ERR_COUNTER (Bit 0)        */
#define TT_CAN_FLEXCAN_ECR_TX_ERR_COUNTER_Msk (0xffUL)          /*!< TT_CAN FLEXCAN_ECR: TX_ERR_COUNTER (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_ECR_RX_ERR_COUNTER_Pos (8UL)             /*!< TT_CAN FLEXCAN_ECR: RX_ERR_COUNTER (Bit 8)        */
#define TT_CAN_FLEXCAN_ECR_RX_ERR_COUNTER_Msk (0xff00UL)        /*!< TT_CAN FLEXCAN_ECR: RX_ERR_COUNTER (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_ECR_TXERRCNT_FAST_Pos (16UL)             /*!< TT_CAN FLEXCAN_ECR: TXERRCNT_FAST (Bit 16)        */
#define TT_CAN_FLEXCAN_ECR_TXERRCNT_FAST_Msk (0xff0000UL)       /*!< TT_CAN FLEXCAN_ECR: TXERRCNT_FAST (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_ECR_RXERRCNT_FAST_Pos (24UL)             /*!< TT_CAN FLEXCAN_ECR: RXERRCNT_FAST (Bit 24)        */
#define TT_CAN_FLEXCAN_ECR_RXERRCNT_FAST_Msk (0xff000000UL)     /*!< TT_CAN FLEXCAN_ECR: RXERRCNT_FAST (Bitfield-Mask: 0xff) */
/* =====================================================  FLEXCAN_ESR1  ====================================================== */
#define TT_CAN_FLEXCAN_ESR1_WAKINT_Pos (0UL)                    /*!< TT_CAN FLEXCAN_ESR1: WAKINT (Bit 0)               */
#define TT_CAN_FLEXCAN_ESR1_WAKINT_Msk (0x1UL)                  /*!< TT_CAN FLEXCAN_ESR1: WAKINT (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_ERRINT_Pos (1UL)                    /*!< TT_CAN FLEXCAN_ESR1: ERRINT (Bit 1)               */
#define TT_CAN_FLEXCAN_ESR1_ERRINT_Msk (0x2UL)                  /*!< TT_CAN FLEXCAN_ESR1: ERRINT (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_BOFFINT_Pos (2UL)                   /*!< TT_CAN FLEXCAN_ESR1: BOFFINT (Bit 2)              */
#define TT_CAN_FLEXCAN_ESR1_BOFFINT_Msk (0x4UL)                 /*!< TT_CAN FLEXCAN_ESR1: BOFFINT (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_RX_Pos    (3UL)                     /*!< TT_CAN FLEXCAN_ESR1: RX (Bit 3)                   */
#define TT_CAN_FLEXCAN_ESR1_RX_Msk    (0x8UL)                   /*!< TT_CAN FLEXCAN_ESR1: RX (Bitfield-Mask: 0x01)     */
#define TT_CAN_FLEXCAN_ESR1_FLTCONF_Pos (4UL)                   /*!< TT_CAN FLEXCAN_ESR1: FLTCONF (Bit 4)              */
#define TT_CAN_FLEXCAN_ESR1_FLTCONF_Msk (0x30UL)                /*!< TT_CAN FLEXCAN_ESR1: FLTCONF (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_ESR1_TX_Pos    (6UL)                     /*!< TT_CAN FLEXCAN_ESR1: TX (Bit 6)                   */
#define TT_CAN_FLEXCAN_ESR1_TX_Msk    (0x40UL)                  /*!< TT_CAN FLEXCAN_ESR1: TX (Bitfield-Mask: 0x01)     */
#define TT_CAN_FLEXCAN_ESR1_IDLE_Pos  (7UL)                     /*!< TT_CAN FLEXCAN_ESR1: IDLE (Bit 7)                 */
#define TT_CAN_FLEXCAN_ESR1_IDLE_Msk  (0x80UL)                  /*!< TT_CAN FLEXCAN_ESR1: IDLE (Bitfield-Mask: 0x01)   */
#define TT_CAN_FLEXCAN_ESR1_RXWRN_Pos (8UL)                     /*!< TT_CAN FLEXCAN_ESR1: RXWRN (Bit 8)                */
#define TT_CAN_FLEXCAN_ESR1_RXWRN_Msk (0x100UL)                 /*!< TT_CAN FLEXCAN_ESR1: RXWRN (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_ESR1_TXWRN_Pos (9UL)                     /*!< TT_CAN FLEXCAN_ESR1: TXWRN (Bit 9)                */
#define TT_CAN_FLEXCAN_ESR1_TXWRN_Msk (0x200UL)                 /*!< TT_CAN FLEXCAN_ESR1: TXWRN (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_ESR1_STFERR_Pos (10UL)                   /*!< TT_CAN FLEXCAN_ESR1: STFERR (Bit 10)              */
#define TT_CAN_FLEXCAN_ESR1_STFERR_Msk (0x400UL)                /*!< TT_CAN FLEXCAN_ESR1: STFERR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_FRMERR_Pos (11UL)                   /*!< TT_CAN FLEXCAN_ESR1: FRMERR (Bit 11)              */
#define TT_CAN_FLEXCAN_ESR1_FRMERR_Msk (0x800UL)                /*!< TT_CAN FLEXCAN_ESR1: FRMERR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_CRCERR_Pos (12UL)                   /*!< TT_CAN FLEXCAN_ESR1: CRCERR (Bit 12)              */
#define TT_CAN_FLEXCAN_ESR1_CRCERR_Msk (0x1000UL)               /*!< TT_CAN FLEXCAN_ESR1: CRCERR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_ACKERR_Pos (13UL)                   /*!< TT_CAN FLEXCAN_ESR1: ACKERR (Bit 13)              */
#define TT_CAN_FLEXCAN_ESR1_ACKERR_Msk (0x2000UL)               /*!< TT_CAN FLEXCAN_ESR1: ACKERR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_BIT0ERR_Pos (14UL)                  /*!< TT_CAN FLEXCAN_ESR1: BIT0ERR (Bit 14)             */
#define TT_CAN_FLEXCAN_ESR1_BIT0ERR_Msk (0x4000UL)              /*!< TT_CAN FLEXCAN_ESR1: BIT0ERR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_BIT1ERR_Pos (15UL)                  /*!< TT_CAN FLEXCAN_ESR1: BIT1ERR (Bit 15)             */
#define TT_CAN_FLEXCAN_ESR1_BIT1ERR_Msk (0x8000UL)              /*!< TT_CAN FLEXCAN_ESR1: BIT1ERR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_RWRNINT_Pos (16UL)                  /*!< TT_CAN FLEXCAN_ESR1: RWRNINT (Bit 16)             */
#define TT_CAN_FLEXCAN_ESR1_RWRNINT_Msk (0x10000UL)             /*!< TT_CAN FLEXCAN_ESR1: RWRNINT (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_TWRNINT_Pos (17UL)                  /*!< TT_CAN FLEXCAN_ESR1: TWRNINT (Bit 17)             */
#define TT_CAN_FLEXCAN_ESR1_TWRNINT_Msk (0x20000UL)             /*!< TT_CAN FLEXCAN_ESR1: TWRNINT (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_SYNCH_Pos (18UL)                    /*!< TT_CAN FLEXCAN_ESR1: SYNCH (Bit 18)               */
#define TT_CAN_FLEXCAN_ESR1_SYNCH_Msk (0x40000UL)               /*!< TT_CAN FLEXCAN_ESR1: SYNCH (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_ESR1_BOFFDONEINT_Pos (19UL)              /*!< TT_CAN FLEXCAN_ESR1: BOFFDONEINT (Bit 19)         */
#define TT_CAN_FLEXCAN_ESR1_BOFFDONEINT_Msk (0x80000UL)         /*!< TT_CAN FLEXCAN_ESR1: BOFFDONEINT (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_ERRINT_FAST_Pos (20UL)              /*!< TT_CAN FLEXCAN_ESR1: ERRINT_FAST (Bit 20)         */
#define TT_CAN_FLEXCAN_ESR1_ERRINT_FAST_Msk (0x100000UL)        /*!< TT_CAN FLEXCAN_ESR1: ERRINT_FAST (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_ERROVR_Pos (21UL)                   /*!< TT_CAN FLEXCAN_ESR1: ERROVR (Bit 21)              */
#define TT_CAN_FLEXCAN_ESR1_ERROVR_Msk (0x200000UL)             /*!< TT_CAN FLEXCAN_ESR1: ERROVR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_STFERR_FAST_Pos (26UL)              /*!< TT_CAN FLEXCAN_ESR1: STFERR_FAST (Bit 26)         */
#define TT_CAN_FLEXCAN_ESR1_STFERR_FAST_Msk (0x4000000UL)       /*!< TT_CAN FLEXCAN_ESR1: STFERR_FAST (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_FRMERR_FAST_Pos (27UL)              /*!< TT_CAN FLEXCAN_ESR1: FRMERR_FAST (Bit 27)         */
#define TT_CAN_FLEXCAN_ESR1_FRMERR_FAST_Msk (0x8000000UL)       /*!< TT_CAN FLEXCAN_ESR1: FRMERR_FAST (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_CRCERR_FAST_Pos (28UL)              /*!< TT_CAN FLEXCAN_ESR1: CRCERR_FAST (Bit 28)         */
#define TT_CAN_FLEXCAN_ESR1_CRCERR_FAST_Msk (0x10000000UL)      /*!< TT_CAN FLEXCAN_ESR1: CRCERR_FAST (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_BIT0ERR_FAST_Pos (30UL)             /*!< TT_CAN FLEXCAN_ESR1: BIT0ERR_FAST (Bit 30)        */
#define TT_CAN_FLEXCAN_ESR1_BIT0ERR_FAST_Msk (0x40000000UL)     /*!< TT_CAN FLEXCAN_ESR1: BIT0ERR_FAST (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ESR1_BIT1ERR_FAST_Pos (31UL)             /*!< TT_CAN FLEXCAN_ESR1: BIT1ERR_FAST (Bit 31)        */
#define TT_CAN_FLEXCAN_ESR1_BIT1ERR_FAST_Msk (0x80000000UL)     /*!< TT_CAN FLEXCAN_ESR1: BIT1ERR_FAST (Bitfield-Mask: 0x01) */
/* ====================================================  FLEXCAN_IMASK2  ===================================================== */
#define TT_CAN_FLEXCAN_IMASK2_BUF63TO32M_Pos (0UL)                   /*!< TT_CAN FLEXCAN_IMASK2: BUFHM (Bit 0)              */
#define TT_CAN_FLEXCAN_IMASK2_BUF63TO32M_Msk (0xffffffffUL)          /*!< TT_CAN FLEXCAN_IMASK2: BUFHM (Bitfield-Mask: 0xffffffff) */
/* ====================================================  FLEXCAN_IMASK1  ===================================================== */
#define TT_CAN_FLEXCAN_IMASK1_BUF31TO0M_pos (0UL)                   /*!< TT_CAN FLEXCAN_IMASK1: BUFLM (Bit 0)              */
#define TT_CAN_FLEXCAN_IMASK1_BUF31TO0M_Msk (0xffffffffUL)          /*!< TT_CAN FLEXCAN_IMASK1: BUFLM (Bitfield-Mask: 0xffffffff) */
/* ====================================================  FLEXCAN_IFLAG2  ===================================================== */
#define TT_CAN_FLEXCAN_IFLAG2_BUF63TO32M_Pos (0UL)                   /*!< TT_CAN FLEXCAN_IFLAG2: BUFHI (Bit 0)              */
#define TT_CAN_FLEXCAN_IFLAG2_BUF63TO32M_Msk (0xffffffffUL)          /*!< TT_CAN FLEXCAN_IFLAG2: BUFHI (Bitfield-Mask: 0xffffffff) */
/* ====================================================  FLEXCAN_IFLAG1  ===================================================== */
#define TT_CAN_FLEXCAN_IFLAG1_BUF01_Pos (0UL)                   /*!< TT_CAN FLEXCAN_IFLAG1: BUF01 (Bit 0)              */
#define TT_CAN_FLEXCAN_IFLAG1_BUF01_Msk (0x1UL)                 /*!< TT_CAN FLEXCAN_IFLAG1: BUF01 (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_IFLAG1_BUF4TO0I_Pos (1UL)                /*!< TT_CAN FLEXCAN_IFLAG1: BUF4TO0I (Bit 1)           */
#define TT_CAN_FLEXCAN_IFLAG1_BUF4TO0I_Msk (0x1eUL)             /*!< TT_CAN FLEXCAN_IFLAG1: BUF4TO0I (Bitfield-Mask: 0x0f) */
#define TT_CAN_FLEXCAN_IFLAG1_BUF5I_Pos (5UL)                   /*!< TT_CAN FLEXCAN_IFLAG1: BUF5I (Bit 5)              */
#define TT_CAN_FLEXCAN_IFLAG1_BUF5I_Msk (0x20UL)                /*!< TT_CAN FLEXCAN_IFLAG1: BUF5I (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_IFLAG1_BUF6I_Pos (6UL)                   /*!< TT_CAN FLEXCAN_IFLAG1: BUF6I (Bit 6)              */
#define TT_CAN_FLEXCAN_IFLAG1_BUF6I_Msk (0x40UL)                /*!< TT_CAN FLEXCAN_IFLAG1: BUF6I (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_IFLAG1_BUF7I_Pos (7UL)                   /*!< TT_CAN FLEXCAN_IFLAG1: BUF7I (Bit 7)              */
#define TT_CAN_FLEXCAN_IFLAG1_BUF7I_Msk (0x80UL)                /*!< TT_CAN FLEXCAN_IFLAG1: BUF7I (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_IFLAG1_BUF31TO8I_Pos (8UL)               /*!< TT_CAN FLEXCAN_IFLAG1: BUF31TO8I (Bit 8)          */
#define TT_CAN_FLEXCAN_IFLAG1_BUF31TO8I_Msk (0xffffff00UL)      /*!< TT_CAN FLEXCAN_IFLAG1: BUF31TO8I (Bitfield-Mask: 0xffffff) */
/* =====================================================  FLEXCAN_CTRL2  ===================================================== */
#define TT_CAN_FLEXCAN_CTRL2_DRC_Pos (0UL)                /*!< TT_CAN FLEXCAN_CTRL2: TSTAMPCAP (Bit 6)           */
#define TT_CAN_FLEXCAN_CTRL2_DRC_Msk (0x7UL)             /*!< TT_CAN FLEXCAN_CTRL2: TSTAMPCAP (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_CTRL2_TSTAMPCAP_Pos (6UL)                /*!< TT_CAN FLEXCAN_CTRL2: TSTAMPCAP (Bit 6)           */
#define TT_CAN_FLEXCAN_CTRL2_TSTAMPCAP_Msk (0xc0UL)             /*!< TT_CAN FLEXCAN_CTRL2: TSTAMPCAP (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_CTRL2_MBTSBASE_Pos (8UL)                 /*!< TT_CAN FLEXCAN_CTRL2: MBTSBASE (Bit 8)            */
#define TT_CAN_FLEXCAN_CTRL2_MBTSBASE_Msk (0x300UL)             /*!< TT_CAN FLEXCAN_CTRL2: MBTSBASE (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_CTRL2_EDFLTDIS_Pos (11UL)                /*!< TT_CAN FLEXCAN_CTRL2: EDFLTDIS (Bit 11)           */
#define TT_CAN_FLEXCAN_CTRL2_EDFLTDIS_Msk (0x800UL)             /*!< TT_CAN FLEXCAN_CTRL2: EDFLTDIS (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL2_ISOCANFDEN_Pos (12UL)              /*!< TT_CAN FLEXCAN_CTRL2: ISOCANFDEN (Bit 12)         */
#define TT_CAN_FLEXCAN_CTRL2_ISOCANFDEN_Msk (0x1000UL)          /*!< TT_CAN FLEXCAN_CTRL2: ISOCANFDEN (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL2_BTE_Pos  (13UL)                    /*!< TT_CAN FLEXCAN_CTRL2: BTE (Bit 13)                */
#define TT_CAN_FLEXCAN_CTRL2_BTE_Msk  (0x2000UL)                /*!< TT_CAN FLEXCAN_CTRL2: BTE (Bitfield-Mask: 0x01)   */
#define TT_CAN_FLEXCAN_CTRL2_PREXCEN_Pos (14UL)                 /*!< TT_CAN FLEXCAN_CTRL2: PREXCEN (Bit 14)            */
#define TT_CAN_FLEXCAN_CTRL2_PREXCEN_Msk (0x4000UL)             /*!< TT_CAN FLEXCAN_CTRL2: PREXCEN (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL2_TIMER_SRC_Pos (15UL)               /*!< TT_CAN FLEXCAN_CTRL2: TIMER_SRC (Bit 15)          */
#define TT_CAN_FLEXCAN_CTRL2_TIMER_SRC_Msk (0x8000UL)           /*!< TT_CAN FLEXCAN_CTRL2: TIMER_SRC (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL2_EACEN_Pos (16UL)                   /*!< TT_CAN FLEXCAN_CTRL2: EACEN (Bit 16)              */
#define TT_CAN_FLEXCAN_CTRL2_EACEN_Msk (0x10000UL)              /*!< TT_CAN FLEXCAN_CTRL2: EACEN (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL2_RRS_Pos  (17UL)                    /*!< TT_CAN FLEXCAN_CTRL2: RRS (Bit 17)                */
#define TT_CAN_FLEXCAN_CTRL2_RRS_Msk  (0x20000UL)               /*!< TT_CAN FLEXCAN_CTRL2: RRS (Bitfield-Mask: 0x01)   */
#define TT_CAN_FLEXCAN_CTRL2_MRP_Pos  (18UL)                    /*!< TT_CAN FLEXCAN_CTRL2: MRP (Bit 18)                */
#define TT_CAN_FLEXCAN_CTRL2_MRP_Msk  (0x40000UL)               /*!< TT_CAN FLEXCAN_CTRL2: MRP (Bitfield-Mask: 0x01)   */
#define TT_CAN_FLEXCAN_CTRL2_TASD_Pos (19UL)                    /*!< TT_CAN FLEXCAN_CTRL2: TASD (Bit 19)               */
#define TT_CAN_FLEXCAN_CTRL2_TASD_Msk (0xf80000UL)              /*!< TT_CAN FLEXCAN_CTRL2: TASD (Bitfield-Mask: 0x1f)  */
#define TT_CAN_FLEXCAN_CTRL2_RFFN_Pos (24UL)                    /*!< TT_CAN FLEXCAN_CTRL2: RFFN (Bit 24)               */
#define TT_CAN_FLEXCAN_CTRL2_RFFN_Msk (0xf000000UL)             /*!< TT_CAN FLEXCAN_CTRL2: RFFN (Bitfield-Mask: 0x0f)  */
#define TT_CAN_FLEXCAN_CTRL2_WRMFRZ_Pos (28UL)                  /*!< TT_CAN FLEXCAN_CTRL2: WRMFRZ (Bit 28)             */
#define TT_CAN_FLEXCAN_CTRL2_WRMFRZ_Msk (0x10000000UL)          /*!< TT_CAN FLEXCAN_CTRL2: WRMFRZ (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL2_ECRWRE_Pos (29UL)                  /*!< TT_CAN FLEXCAN_CTRL2: ECRWRE (Bit 29)             */
#define TT_CAN_FLEXCAN_CTRL2_ECRWRE_Msk (0x20000000UL)          /*!< TT_CAN FLEXCAN_CTRL2: ECRWRE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL2_BOFFDONEMSK_Pos (30UL)             /*!< TT_CAN FLEXCAN_CTRL2: BOFFDONEMSK (Bit 30)        */
#define TT_CAN_FLEXCAN_CTRL2_BOFFDONEMSK_Msk (0x40000000UL)     /*!< TT_CAN FLEXCAN_CTRL2: BOFFDONEMSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL2_ERRMSK_FAST_Pos (31UL)             /*!< TT_CAN FLEXCAN_CTRL2: ERRMSK_FAST (Bit 31)        */
#define TT_CAN_FLEXCAN_CTRL2_ERRMSK_FAST_Msk (0x80000000UL)     /*!< TT_CAN FLEXCAN_CTRL2: ERRMSK_FAST (Bitfield-Mask: 0x01) */
/* =====================================================  FLEXCAN_ESR2  ====================================================== */
#define TT_CAN_FLEXCAN_ESR2_IMB_Pos   (13UL)                    /*!< TT_CAN FLEXCAN_ESR2: IMB (Bit 13)                 */
#define TT_CAN_FLEXCAN_ESR2_IMB_Msk   (0x2000UL)                /*!< TT_CAN FLEXCAN_ESR2: IMB (Bitfield-Mask: 0x01)    */
#define TT_CAN_FLEXCAN_ESR2_VPS_Pos   (14UL)                    /*!< TT_CAN FLEXCAN_ESR2: VPS (Bit 14)                 */
#define TT_CAN_FLEXCAN_ESR2_VPS_Msk   (0x4000UL)                /*!< TT_CAN FLEXCAN_ESR2: VPS (Bitfield-Mask: 0x01)    */
#define TT_CAN_FLEXCAN_ESR2_LPTM_Pos  (16UL)                    /*!< TT_CAN FLEXCAN_ESR2: LPTM (Bit 16)                */
#define TT_CAN_FLEXCAN_ESR2_LPTM_Msk  (0x7f0000UL)              /*!< TT_CAN FLEXCAN_ESR2: LPTM (Bitfield-Mask: 0x7f)   */
/* =====================================================  FLEXCAN_CRCR  ====================================================== */
#define TT_CAN_FLEXCAN_CRCR_TXCRC_Pos (0UL)                     /*!< TT_CAN FLEXCAN_CRCR: TXCRC (Bit 0)                */
#define TT_CAN_FLEXCAN_CRCR_TXCRC_Msk (0x7fffUL)                /*!< TT_CAN FLEXCAN_CRCR: TXCRC (Bitfield-Mask: 0x7fff) */
#define TT_CAN_FLEXCAN_CRCR_MBCRC_Pos (16UL)                    /*!< TT_CAN FLEXCAN_CRCR: MBCRC (Bit 16)               */
#define TT_CAN_FLEXCAN_CRCR_MBCRC_Msk (0x7f0000UL)              /*!< TT_CAN FLEXCAN_CRCR: MBCRC (Bitfield-Mask: 0x7f)  */
/* ===================================================  FLEXCAN_RXFGMASK  ==================================================== */
#define TT_CAN_FLEXCAN_RXFGMASK_FGM_Pos (0UL)                   /*!< TT_CAN FLEXCAN_RXFGMASK: FGM (Bit 0)              */
#define TT_CAN_FLEXCAN_RXFGMASK_FGM_Msk (0xffffffffUL)          /*!< TT_CAN FLEXCAN_RXFGMASK: FGM (Bitfield-Mask: 0xffffffff) */
/* =====================================================  FLEXCAN_RXFIR  ===================================================== */
#define TT_CAN_FLEXCAN_RXFIR_IDHIT_Pos (0UL)                    /*!< TT_CAN FLEXCAN_RXFIR: IDHIT (Bit 0)               */
#define TT_CAN_FLEXCAN_RXFIR_IDHIT_Msk (0x1ffUL)                /*!< TT_CAN FLEXCAN_RXFIR: IDHIT (Bitfield-Mask: 0x1ff) */
/* ======================================================  FLEXCAN_CBT  ====================================================== */
#define TT_CAN_FLEXCAN_CBT_BTF_Pos    (31UL)                    /*!< TT_CAN FLEXCAN_CBT: BTF (Bit 31)                  */
#define TT_CAN_FLEXCAN_CBT_BTF_Msk    (0x80000000UL)            /*!< TT_CAN FLEXCAN_CBT: BTF (Bitfield-Mask: 0x01)     */
#define TT_CAN_FLEXCAN_CBT_EPRESDIV_Pos (21UL)                  /*!< TT_CAN FLEXCAN_CBT: EPRESDIV (Bit 21)             */
#define TT_CAN_FLEXCAN_CBT_EPRESDIV_Msk (0x7fe00000UL)          /*!< TT_CAN FLEXCAN_CBT: EPRESDIV (Bitfield-Mask: 0x3ff) */
#define TT_CAN_FLEXCAN_CBT_ERJW_Pos   (16UL)                    /*!< TT_CAN FLEXCAN_CBT: ERJW (Bit 16)                 */
#define TT_CAN_FLEXCAN_CBT_ERJW_Msk   (0x1f0000UL)              /*!< TT_CAN FLEXCAN_CBT: ERJW (Bitfield-Mask: 0x1f)    */
#define TT_CAN_FLEXCAN_CBT_EPROPSEG_Pos (10UL)                  /*!< TT_CAN FLEXCAN_CBT: EPROPSEG (Bit 10)             */
#define TT_CAN_FLEXCAN_CBT_EPROPSEG_Msk (0xfc00UL)              /*!< TT_CAN FLEXCAN_CBT: EPROPSEG (Bitfield-Mask: 0x3f) */
#define TT_CAN_FLEXCAN_CBT_EPSEG1_Pos (5UL)                     /*!< TT_CAN FLEXCAN_CBT: EPSEG1 (Bit 5)                */
#define TT_CAN_FLEXCAN_CBT_EPSEG1_Msk (0x3e0UL)                 /*!< TT_CAN FLEXCAN_CBT: EPSEG1 (Bitfield-Mask: 0x1f)  */
#define TT_CAN_FLEXCAN_CBT_EPSEG2_Pos (0UL)                     /*!< TT_CAN FLEXCAN_CBT: EPSEG2 (Bit 0)                */
#define TT_CAN_FLEXCAN_CBT_EPSEG2_Msk (0x1fUL)                  /*!< TT_CAN FLEXCAN_CBT: EPSEG2 (Bitfield-Mask: 0x1f)  */
/* ====================================================  FLEXCAN_IMASK4  ===================================================== */
#define TT_CAN_FLEXCAN_IMASK4_BUF127TO96M_Pos (0UL)             /*!< TT_CAN FLEXCAN_IMASK4: BUF127TO96M (Bit 0)        */
#define TT_CAN_FLEXCAN_IMASK4_BUF127TO96M_Msk (0xffffffffUL)    /*!< TT_CAN FLEXCAN_IMASK4: BUF127TO96M (Bitfield-Mask: 0xffffffff) */
/* ====================================================  FLEXCAN_IMASK3  ===================================================== */
#define TT_CAN_FLEXCAN_IMASK3_BUF95TO64M_Pos (0UL)              /*!< TT_CAN FLEXCAN_IMASK3: BUF95TO64M (Bit 0)         */
#define TT_CAN_FLEXCAN_IMASK3_BUF95TO64M_Msk (0xffffffffUL)     /*!< TT_CAN FLEXCAN_IMASK3: BUF95TO64M (Bitfield-Mask: 0xffffffff) */
/* ====================================================  FLEXCAN_IFLAG4  ===================================================== */
#define TT_CAN_FLEXCAN_IFLAG4_BUF127TO96M_Pos (0UL)             /*!< TT_CAN FLEXCAN_IFLAG4: BUF127TO96M (Bit 0)        */
#define TT_CAN_FLEXCAN_IFLAG4_BUF127TO96M_Msk (0xffffffffUL)    /*!< TT_CAN FLEXCAN_IFLAG4: BUF127TO96M (Bitfield-Mask: 0xffffffff) */
/* ====================================================  FLEXCAN_IFLAG3  ===================================================== */
#define TT_CAN_FLEXCAN_IFLAG3_BUF95TO64M_Pos (0UL)              /*!< TT_CAN FLEXCAN_IFLAG3: BUF95TO64M (Bit 0)         */
#define TT_CAN_FLEXCAN_IFLAG3_BUF95TO64M_Msk (0xffffffffUL)     /*!< TT_CAN FLEXCAN_IFLAG3: BUF95TO64M (Bitfield-Mask: 0xffffffff) */
/* =====================================================  FLEXCAN_RAMn  ====================================================== */
/* =====================================================  FLEXCAN_RXIMR  ===================================================== */
#define TT_CAN_FLEXCAN_RXIMR_MI_Pos   (0UL)                     /*!< TT_CAN FLEXCAN_RXIMR: MI (Bit 0)                  */
#define TT_CAN_FLEXCAN_RXIMR_MI_Msk   (0xffffffffUL)            /*!< TT_CAN FLEXCAN_RXIMR: MI (Bitfield-Mask: 0xffffffff) */
/* =====================================================  FLEXCAN_MECR  ====================================================== */
#define TT_CAN_FLEXCAN_MECR_ECRWRDIS_Pos (31UL)                 /*!< TT_CAN FLEXCAN_MECR: ECRWRDIS (Bit 31)            */
#define TT_CAN_FLEXCAN_MECR_ECRWRDIS_Msk (0x80000000UL)         /*!< TT_CAN FLEXCAN_MECR: ECRWRDIS (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_HANCEI_MSK_Pos (19UL)               /*!< TT_CAN FLEXCAN_MECR: HANCEI_MSK (Bit 19)          */
#define TT_CAN_FLEXCAN_MECR_HANCEI_MSK_Msk (0x80000UL)          /*!< TT_CAN FLEXCAN_MECR: HANCEI_MSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_FANCEI_MSK_Pos (18UL)               /*!< TT_CAN FLEXCAN_MECR: FANCEI_MSK (Bit 18)          */
#define TT_CAN_FLEXCAN_MECR_FANCEI_MSK_Msk (0x40000UL)          /*!< TT_CAN FLEXCAN_MECR: FANCEI_MSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_CEI_MSK_Pos (16UL)                  /*!< TT_CAN FLEXCAN_MECR: CEI_MSK (Bit 16)             */
#define TT_CAN_FLEXCAN_MECR_CEI_MSK_Msk (0x10000UL)             /*!< TT_CAN FLEXCAN_MECR: CEI_MSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_HAERRIE_Pos (15UL)                  /*!< TT_CAN FLEXCAN_MECR: HAERRIE (Bit 15)             */
#define TT_CAN_FLEXCAN_MECR_HAERRIE_Msk (0x8000UL)              /*!< TT_CAN FLEXCAN_MECR: HAERRIE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_FAERRIE_Pos (14UL)                  /*!< TT_CAN FLEXCAN_MECR: FAERRIE (Bit 14)             */
#define TT_CAN_FLEXCAN_MECR_FAERRIE_Msk (0x4000UL)              /*!< TT_CAN FLEXCAN_MECR: FAERRIE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_EXTERRIE_Pos (13UL)                 /*!< TT_CAN FLEXCAN_MECR: EXTERRIE (Bit 13)            */
#define TT_CAN_FLEXCAN_MECR_EXTERRIE_Msk (0x2000UL)             /*!< TT_CAN FLEXCAN_MECR: EXTERRIE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_RERRDIS_Pos (9UL)                   /*!< TT_CAN FLEXCAN_MECR: RERRDIS (Bit 9)              */
#define TT_CAN_FLEXCAN_MECR_RERRDIS_Msk (0x200UL)               /*!< TT_CAN FLEXCAN_MECR: RERRDIS (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_ECCDIS_Pos (8UL)                    /*!< TT_CAN FLEXCAN_MECR: ECCDIS (Bit 8)               */
#define TT_CAN_FLEXCAN_MECR_ECCDIS_Msk (0x100UL)                /*!< TT_CAN FLEXCAN_MECR: ECCDIS (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_MECR_NCEFAFRZ_Pos (7UL)                  /*!< TT_CAN FLEXCAN_MECR: NCEFAFRZ (Bit 7)             */
#define TT_CAN_FLEXCAN_MECR_NCEFAFRZ_Msk (0x80UL)               /*!< TT_CAN FLEXCAN_MECR: NCEFAFRZ (Bitfield-Mask: 0x01) */
/* ====================================================  FLEXCAN_ERRIAR  ===================================================== */
#define TT_CAN_FLEXCAN_ERRIAR_INJADDR_L_Pos (0UL)               /*!< TT_CAN FLEXCAN_ERRIAR: INJADDR_L (Bit 0)          */
#define TT_CAN_FLEXCAN_ERRIAR_INJADDR_L_Msk (0x3UL)             /*!< TT_CAN FLEXCAN_ERRIAR: INJADDR_L (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_ERRIAR_INJADDR_H_Pos (2UL)               /*!< TT_CAN FLEXCAN_ERRIAR: INJADDR_H (Bit 2)          */
#define TT_CAN_FLEXCAN_ERRIAR_INJADDR_H_Msk (0x3ffcUL)          /*!< TT_CAN FLEXCAN_ERRIAR: INJADDR_H (Bitfield-Mask: 0xfff) */
/* ====================================================  FLEXCAN_ERRIDPR  ==================================================== */
#define TT_CAN_FLEXCAN_ERRIDPR_DFLIP_Pos (0UL)                  /*!< TT_CAN FLEXCAN_ERRIDPR: DFLIP (Bit 0)             */
#define TT_CAN_FLEXCAN_ERRIDPR_DFLIP_Msk (0xffffffffUL)         /*!< TT_CAN FLEXCAN_ERRIDPR: DFLIP (Bitfield-Mask: 0xffffffff) */
/* ====================================================  FLEXCAN_ERRIPPR  ==================================================== */
#define TT_CAN_FLEXCAN_ERRIPPR_PFLIP0_Pos (0UL)                 /*!< TT_CAN FLEXCAN_ERRIPPR: PFLIP0 (Bit 0)            */
#define TT_CAN_FLEXCAN_ERRIPPR_PFLIP0_Msk (0x1fUL)              /*!< TT_CAN FLEXCAN_ERRIPPR: PFLIP0 (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_ERRIPPR_PFLIP1_Pos (8UL)                 /*!< TT_CAN FLEXCAN_ERRIPPR: PFLIP1 (Bit 8)            */
#define TT_CAN_FLEXCAN_ERRIPPR_PFLIP1_Msk (0x1f00UL)            /*!< TT_CAN FLEXCAN_ERRIPPR: PFLIP1 (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_ERRIPPR_PFLIP2_Pos (16UL)                /*!< TT_CAN FLEXCAN_ERRIPPR: PFLIP2 (Bit 16)           */
#define TT_CAN_FLEXCAN_ERRIPPR_PFLIP2_Msk (0x1f0000UL)          /*!< TT_CAN FLEXCAN_ERRIPPR: PFLIP2 (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_ERRIPPR_PFLIP3_Pos (24UL)                /*!< TT_CAN FLEXCAN_ERRIPPR: PFLIP3 (Bit 24)           */
#define TT_CAN_FLEXCAN_ERRIPPR_PFLIP3_Msk (0x1f000000UL)        /*!< TT_CAN FLEXCAN_ERRIPPR: PFLIP3 (Bitfield-Mask: 0x1f) */
/* ====================================================  FLEXCAN_RERRAR  ===================================================== */
#define TT_CAN_FLEXCAN_RERRAR_ERRADDR_Pos (0UL)                 /*!< TT_CAN FLEXCAN_RERRAR: ERRADDR (Bit 0)            */
#define TT_CAN_FLEXCAN_RERRAR_ERRADDR_Msk (0x3fffUL)            /*!< TT_CAN FLEXCAN_RERRAR: ERRADDR (Bitfield-Mask: 0x3fff) */
#define TT_CAN_FLEXCAN_RERRAR_SAID_Pos (16UL)                   /*!< TT_CAN FLEXCAN_RERRAR: SAID (Bit 16)              */
#define TT_CAN_FLEXCAN_RERRAR_SAID_Msk (0x70000UL)              /*!< TT_CAN FLEXCAN_RERRAR: SAID (Bitfield-Mask: 0x07) */
#define TT_CAN_FLEXCAN_RERRAR_NCE_Pos (24UL)                    /*!< TT_CAN FLEXCAN_RERRAR: NCE (Bit 24)               */
#define TT_CAN_FLEXCAN_RERRAR_NCE_Msk (0x1000000UL)             /*!< TT_CAN FLEXCAN_RERRAR: NCE (Bitfield-Mask: 0x01)  */
/* ====================================================  FLEXCAN_RERRDR  ===================================================== */
#define TT_CAN_FLEXCAN_RERRDR_RDATA_Pos (0UL)                   /*!< TT_CAN FLEXCAN_RERRDR: RDATA (Bit 0)              */
#define TT_CAN_FLEXCAN_RERRDR_RDATA_Msk (0xffffffffUL)          /*!< TT_CAN FLEXCAN_RERRDR: RDATA (Bitfield-Mask: 0xffffffff) */
/* ===================================================  FLEXCAN_RERRSYNR  ==================================================== */
#define TT_CAN_FLEXCAN_RERRSYNR_SYND0_Pos (0UL)                 /*!< TT_CAN FLEXCAN_RERRSYNR: SYND0 (Bit 0)            */
#define TT_CAN_FLEXCAN_RERRSYNR_SYND0_Msk (0x1fUL)              /*!< TT_CAN FLEXCAN_RERRSYNR: SYND0 (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_RERRSYNR_BE0_Pos (7UL)                   /*!< TT_CAN FLEXCAN_RERRSYNR: BE0 (Bit 7)              */
#define TT_CAN_FLEXCAN_RERRSYNR_BE0_Msk (0x80UL)                /*!< TT_CAN FLEXCAN_RERRSYNR: BE0 (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_RERRSYNR_BYND1_Pos (8UL)                 /*!< TT_CAN FLEXCAN_RERRSYNR: BYND1 (Bit 8)            */
#define TT_CAN_FLEXCAN_RERRSYNR_BYND1_Msk (0x1f00UL)            /*!< TT_CAN FLEXCAN_RERRSYNR: BYND1 (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_RERRSYNR_BE1_Pos (15UL)                  /*!< TT_CAN FLEXCAN_RERRSYNR: BE1 (Bit 15)             */
#define TT_CAN_FLEXCAN_RERRSYNR_BE1_Msk (0x8000UL)              /*!< TT_CAN FLEXCAN_RERRSYNR: BE1 (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_RERRSYNR_SYND2_Pos (16UL)                /*!< TT_CAN FLEXCAN_RERRSYNR: SYND2 (Bit 16)           */
#define TT_CAN_FLEXCAN_RERRSYNR_SYND2_Msk (0x1f0000UL)          /*!< TT_CAN FLEXCAN_RERRSYNR: SYND2 (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_RERRSYNR_BE2_Pos (23UL)                  /*!< TT_CAN FLEXCAN_RERRSYNR: BE2 (Bit 23)             */
#define TT_CAN_FLEXCAN_RERRSYNR_BE2_Msk (0x800000UL)            /*!< TT_CAN FLEXCAN_RERRSYNR: BE2 (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_RERRSYNR_SYND3_Pos (24UL)                /*!< TT_CAN FLEXCAN_RERRSYNR: SYND3 (Bit 24)           */
#define TT_CAN_FLEXCAN_RERRSYNR_SYND3_Msk (0x1f000000UL)        /*!< TT_CAN FLEXCAN_RERRSYNR: SYND3 (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_RERRSYNR_BE3_Pos (31UL)                  /*!< TT_CAN FLEXCAN_RERRSYNR: BE3 (Bit 31)             */
#define TT_CAN_FLEXCAN_RERRSYNR_BE3_Msk (0x80000000UL)          /*!< TT_CAN FLEXCAN_RERRSYNR: BE3 (Bitfield-Mask: 0x01) */
/* =====================================================  FLEXCAN_ERRSR  ===================================================== */
#define TT_CAN_FLEXCAN_ERRSR_HANCEIF_Pos (19UL)                 /*!< TT_CAN FLEXCAN_ERRSR: HANCEIF (Bit 19)            */
#define TT_CAN_FLEXCAN_ERRSR_HANCEIF_Msk (0x80000UL)            /*!< TT_CAN FLEXCAN_ERRSR: HANCEIF (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERRSR_FANCEIF_Pos (18UL)                 /*!< TT_CAN FLEXCAN_ERRSR: FANCEIF (Bit 18)            */
#define TT_CAN_FLEXCAN_ERRSR_FANCEIF_Msk (0x40000UL)            /*!< TT_CAN FLEXCAN_ERRSR: FANCEIF (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERRSR_CEIF_Pos (16UL)                    /*!< TT_CAN FLEXCAN_ERRSR: CEIF (Bit 16)               */
#define TT_CAN_FLEXCAN_ERRSR_CEIF_Msk (0x10000UL)               /*!< TT_CAN FLEXCAN_ERRSR: CEIF (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_ERRSR_HANCEIOF_Pos (3UL)                 /*!< TT_CAN FLEXCAN_ERRSR: HANCEIOF (Bit 3)            */
#define TT_CAN_FLEXCAN_ERRSR_HANCEIOF_Msk (0x8UL)               /*!< TT_CAN FLEXCAN_ERRSR: HANCEIOF (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERRSR_FANCEIOF_Pos (2UL)                 /*!< TT_CAN FLEXCAN_ERRSR: FANCEIOF (Bit 2)            */
#define TT_CAN_FLEXCAN_ERRSR_FANCEIOF_Msk (0x4UL)               /*!< TT_CAN FLEXCAN_ERRSR: FANCEIOF (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERRSR_CEIOF_Pos (0UL)                    /*!< TT_CAN FLEXCAN_ERRSR: CEIOF (Bit 0)               */
#define TT_CAN_FLEXCAN_ERRSR_CEIOF_Msk (0x1UL)                  /*!< TT_CAN FLEXCAN_ERRSR: CEIOF (Bitfield-Mask: 0x01) */
/* ===================================================  FLEXCAN_CTRL1_PN  ==================================================== */
#define TT_CAN_FLEXCAN_CTRL1_PN_WTOF_MSK_Pos (17UL)             /*!< TT_CAN FLEXCAN_CTRL1_PN: WTOF_MSK (Bit 17)        */
#define TT_CAN_FLEXCAN_CTRL1_PN_WTOF_MSK_Msk (0x20000UL)        /*!< TT_CAN FLEXCAN_CTRL1_PN: WTOF_MSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL1_PN_WUMF_MSK_Pos (16UL)             /*!< TT_CAN FLEXCAN_CTRL1_PN: WUMF_MSK (Bit 16)        */
#define TT_CAN_FLEXCAN_CTRL1_PN_WUMF_MSK_Msk (0x10000UL)        /*!< TT_CAN FLEXCAN_CTRL1_PN: WUMF_MSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_CTRL1_PN_NMATCH_Pos (8UL)                /*!< TT_CAN FLEXCAN_CTRL1_PN: NMATCH (Bit 8)           */
#define TT_CAN_FLEXCAN_CTRL1_PN_NMATCH_Msk (0xff00UL)           /*!< TT_CAN FLEXCAN_CTRL1_PN: NMATCH (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_CTRL1_PN_PLFS_Pos (4UL)                  /*!< TT_CAN FLEXCAN_CTRL1_PN: PLFS (Bit 4)             */
#define TT_CAN_FLEXCAN_CTRL1_PN_PLFS_Msk (0x30UL)               /*!< TT_CAN FLEXCAN_CTRL1_PN: PLFS (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_CTRL1_PN_IDFS_Pos (2UL)                  /*!< TT_CAN FLEXCAN_CTRL1_PN: IDFS (Bit 2)             */
#define TT_CAN_FLEXCAN_CTRL1_PN_IDFS_Msk (0xcUL)                /*!< TT_CAN FLEXCAN_CTRL1_PN: IDFS (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_CTRL1_PN_FCS_Pos (0UL)                   /*!< TT_CAN FLEXCAN_CTRL1_PN: FCS (Bit 0)              */
#define TT_CAN_FLEXCAN_CTRL1_PN_FCS_Msk (0x3UL)                 /*!< TT_CAN FLEXCAN_CTRL1_PN: FCS (Bitfield-Mask: 0x03) */
/* ===================================================  FLEXCAN_CTRL2_PN  ==================================================== */
#define TT_CAN_FLEXCAN_CTRL2_PN_MATCHTO_Pos (0UL)               /*!< TT_CAN FLEXCAN_CTRL2_PN: MATCHTO (Bit 0)          */
#define TT_CAN_FLEXCAN_CTRL2_PN_MATCHTO_Msk (0xffffUL)          /*!< TT_CAN FLEXCAN_CTRL2_PN: MATCHTO (Bitfield-Mask: 0xffff) */
/* ====================================================  FLEXCAN_WU_MTC  ===================================================== */
#define TT_CAN_FLEXCAN_WU_MTC_WTOF_Pos (17UL)                   /*!< TT_CAN FLEXCAN_WU_MTC: WTOF (Bit 17)              */
#define TT_CAN_FLEXCAN_WU_MTC_WTOF_Msk (0x20000UL)              /*!< TT_CAN FLEXCAN_WU_MTC: WTOF (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_WU_MTC_WUMF_Pos (16UL)                   /*!< TT_CAN FLEXCAN_WU_MTC: WUMF (Bit 16)              */
#define TT_CAN_FLEXCAN_WU_MTC_WUMF_Msk (0x10000UL)              /*!< TT_CAN FLEXCAN_WU_MTC: WUMF (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_WU_MTC_MCOUNTER_Pos (8UL)                /*!< TT_CAN FLEXCAN_WU_MTC: MCOUNTER (Bit 8)           */
#define TT_CAN_FLEXCAN_WU_MTC_MCOUNTER_Msk (0xff00UL)           /*!< TT_CAN FLEXCAN_WU_MTC: MCOUNTER (Bitfield-Mask: 0xff) */
/* ====================================================  FLEXCAN_FLT_ID1  ==================================================== */
#define TT_CAN_FLEXCAN_FLT_ID1_FLT_IDE_Pos (30UL)               /*!< TT_CAN FLEXCAN_FLT_ID1: FLT_IDE (Bit 30)          */
#define TT_CAN_FLEXCAN_FLT_ID1_FLT_IDE_Msk (0x40000000UL)       /*!< TT_CAN FLEXCAN_FLT_ID1: FLT_IDE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_FLT_ID1_FLT_RTR_Pos (29UL)               /*!< TT_CAN FLEXCAN_FLT_ID1: FLT_RTR (Bit 29)          */
#define TT_CAN_FLEXCAN_FLT_ID1_FLT_RTR_Msk (0x20000000UL)       /*!< TT_CAN FLEXCAN_FLT_ID1: FLT_RTR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_FLT_ID1_FLT_ID1_Pos (0UL)                /*!< TT_CAN FLEXCAN_FLT_ID1: FLT_ID1 (Bit 0)           */
#define TT_CAN_FLEXCAN_FLT_ID1_FLT_ID1_Msk (0x1fffffffUL)       /*!< TT_CAN FLEXCAN_FLT_ID1: FLT_ID1 (Bitfield-Mask: 0x1fffffff) */
/* ====================================================  FLEXCAN_FLT_DLC  ==================================================== */
#define TT_CAN_FLEXCAN_FLT_DLC_FLT_DLC_LO_Pos (16UL)            /*!< TT_CAN FLEXCAN_FLT_DLC: FLT_DLC_LO (Bit 16)       */
#define TT_CAN_FLEXCAN_FLT_DLC_FLT_DLC_LO_Msk (0xf0000UL)       /*!< TT_CAN FLEXCAN_FLT_DLC: FLT_DLC_LO (Bitfield-Mask: 0x0f) */
#define TT_CAN_FLEXCAN_FLT_DLC_FLT_DLC_HI_Pos (0UL)             /*!< TT_CAN FLEXCAN_FLT_DLC: FLT_DLC_HI (Bit 0)        */
#define TT_CAN_FLEXCAN_FLT_DLC_FLT_DLC_HI_Msk (0xfUL)           /*!< TT_CAN FLEXCAN_FLT_DLC: FLT_DLC_HI (Bitfield-Mask: 0x0f) */
/* ====================================================  FLEXCAN_PL1_LO  ===================================================== */
#define TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_0_Pos (24UL)            /*!< TT_CAN FLEXCAN_PL1_LO: Data_BYTE_0 (Bit 24)       */
#define TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_0_Msk (0xff000000UL)    /*!< TT_CAN FLEXCAN_PL1_LO: Data_BYTE_0 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_1_Pos (16UL)            /*!< TT_CAN FLEXCAN_PL1_LO: Data_BYTE_1 (Bit 16)       */
#define TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_1_Msk (0xff0000UL)      /*!< TT_CAN FLEXCAN_PL1_LO: Data_BYTE_1 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_2_Pos (8UL)             /*!< TT_CAN FLEXCAN_PL1_LO: Data_BYTE_2 (Bit 8)        */
#define TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_2_Msk (0xff00UL)        /*!< TT_CAN FLEXCAN_PL1_LO: Data_BYTE_2 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_3_Pos (0UL)             /*!< TT_CAN FLEXCAN_PL1_LO: Data_BYTE_3 (Bit 0)        */
#define TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_3_Msk (0xffUL)          /*!< TT_CAN FLEXCAN_PL1_LO: Data_BYTE_3 (Bitfield-Mask: 0xff) */
/* ====================================================  FLEXCAN_PL1_HI  ===================================================== */
#define TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_4_Pos (24UL)            /*!< TT_CAN FLEXCAN_PL1_HI: Data_BYTE_4 (Bit 24)       */
#define TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_4_Msk (0xff000000UL)    /*!< TT_CAN FLEXCAN_PL1_HI: Data_BYTE_4 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_5_Pos (16UL)            /*!< TT_CAN FLEXCAN_PL1_HI: Data_BYTE_5 (Bit 16)       */
#define TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_5_Msk (0xff0000UL)      /*!< TT_CAN FLEXCAN_PL1_HI: Data_BYTE_5 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_6_Pos (8UL)             /*!< TT_CAN FLEXCAN_PL1_HI: Data_BYTE_6 (Bit 8)        */
#define TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_6_Msk (0xff00UL)        /*!< TT_CAN FLEXCAN_PL1_HI: Data_BYTE_6 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_7_Pos (0UL)             /*!< TT_CAN FLEXCAN_PL1_HI: Data_BYTE_7 (Bit 0)        */
#define TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_7_Msk (0xffUL)          /*!< TT_CAN FLEXCAN_PL1_HI: Data_BYTE_7 (Bitfield-Mask: 0xff) */
/* ================================================  FLEXCAN_FLT_ID2_IDMASK  ================================================= */
#define TT_CAN_FLEXCAN_FLT_ID2_IDMASK_IDE_MSK_Pos (30UL)        /*!< TT_CAN FLEXCAN_FLT_ID2_IDMASK: IDE_MSK (Bit 30)   */
#define TT_CAN_FLEXCAN_FLT_ID2_IDMASK_IDE_MSK_Msk (0x40000000UL) /*!< TT_CAN FLEXCAN_FLT_ID2_IDMASK: IDE_MSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_FLT_ID2_IDMASK_RTR_MSK_Pos (29UL)        /*!< TT_CAN FLEXCAN_FLT_ID2_IDMASK: RTR_MSK (Bit 29)   */
#define TT_CAN_FLEXCAN_FLT_ID2_IDMASK_RTR_MSK_Msk (0x20000000UL) /*!< TT_CAN FLEXCAN_FLT_ID2_IDMASK: RTR_MSK (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK_Pos (0UL)  /*!< TT_CAN FLEXCAN_FLT_ID2_IDMASK: FLT_ID2_IDMASK (Bit 0) */
#define TT_CAN_FLEXCAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK_Msk (0x1fffffffUL) /*!< TT_CAN FLEXCAN_FLT_ID2_IDMASK: FLT_ID2_IDMASK (Bitfield-Mask: 0x1fffffff) */
/* =================================================  FLEXCAN_PL2_PLMASK_LO  ================================================= */
#define TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_0_Pos (24UL)     /*!< TT_CAN FLEXCAN_PL2_PLMASK_LO: Data_BYTE_0 (Bit 24) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_0_Msk (0xff000000UL) /*!< TT_CAN FLEXCAN_PL2_PLMASK_LO: Data_BYTE_0 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_1_Pos (16UL)     /*!< TT_CAN FLEXCAN_PL2_PLMASK_LO: Data_BYTE_1 (Bit 16) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_1_Msk (0xff0000UL) /*!< TT_CAN FLEXCAN_PL2_PLMASK_LO: Data_BYTE_1 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_2_Pos (8UL)      /*!< TT_CAN FLEXCAN_PL2_PLMASK_LO: Data_BYTE_2 (Bit 8) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_2_Msk (0xff00UL) /*!< TT_CAN FLEXCAN_PL2_PLMASK_LO: Data_BYTE_2 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_3_Pos (0UL)      /*!< TT_CAN FLEXCAN_PL2_PLMASK_LO: Data_BYTE_3 (Bit 0) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_3_Msk (0xffUL)   /*!< TT_CAN FLEXCAN_PL2_PLMASK_LO: Data_BYTE_3 (Bitfield-Mask: 0xff) */
/* =================================================  FLEXCAN_PL2_PLMASK_HI  ================================================= */
#define TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_4_Pos (24UL)     /*!< TT_CAN FLEXCAN_PL2_PLMASK_HI: Data_BYTE_4 (Bit 24) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_4_Msk (0xff000000UL) /*!< TT_CAN FLEXCAN_PL2_PLMASK_HI: Data_BYTE_4 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_5_Pos (16UL)     /*!< TT_CAN FLEXCAN_PL2_PLMASK_HI: Data_BYTE_5 (Bit 16) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_5_Msk (0xff0000UL) /*!< TT_CAN FLEXCAN_PL2_PLMASK_HI: Data_BYTE_5 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_6_Pos (8UL)      /*!< TT_CAN FLEXCAN_PL2_PLMASK_HI: Data_BYTE_6 (Bit 8) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_6_Msk (0xff00UL) /*!< TT_CAN FLEXCAN_PL2_PLMASK_HI: Data_BYTE_6 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_7_Pos (0UL)      /*!< TT_CAN FLEXCAN_PL2_PLMASK_HI: Data_BYTE_7 (Bit 0) */
#define TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_7_Msk (0xffUL)   /*!< TT_CAN FLEXCAN_PL2_PLMASK_HI: Data_BYTE_7 (Bitfield-Mask: 0xff) */
/* =====================================================  FLEXCAN_EPRS  ====================================================== */
#define TT_CAN_FLEXCAN_EPRS_ENPRESDIV_Pos (0UL)                 /*!< TT_CAN FLEXCAN_EPRS: ENPRESDIV (Bit 0)            */
#define TT_CAN_FLEXCAN_EPRS_ENPRESDIV_Msk (0x3ffUL)             /*!< TT_CAN FLEXCAN_EPRS: ENPRESDIV (Bitfield-Mask: 0x3ff) */
#define TT_CAN_FLEXCAN_EPRS_EDPRESDIV_Pos (16UL)                /*!< TT_CAN FLEXCAN_EPRS: EDPRESDIV (Bit 16)           */
#define TT_CAN_FLEXCAN_EPRS_EDPRESDIV_Msk (0x3ff0000UL)         /*!< TT_CAN FLEXCAN_EPRS: EDPRESDIV (Bitfield-Mask: 0x3ff) */
/* =====================================================  FLEXCAN_ENCBT  ===================================================== */
#define TT_CAN_FLEXCAN_ENCBT_NTSEG1_Pos (0UL)                   /*!< TT_CAN FLEXCAN_ENCBT: NTSEG1 (Bit 0)              */
#define TT_CAN_FLEXCAN_ENCBT_NTSEG1_Msk (0xffUL)                /*!< TT_CAN FLEXCAN_ENCBT: NTSEG1 (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_ENCBT_NTSEG2_Pos (12UL)                  /*!< TT_CAN FLEXCAN_ENCBT: NTSEG2 (Bit 12)             */
#define TT_CAN_FLEXCAN_ENCBT_NTSEG2_Msk (0x7f000UL)             /*!< TT_CAN FLEXCAN_ENCBT: NTSEG2 (Bitfield-Mask: 0x7f) */
#define TT_CAN_FLEXCAN_ENCBT_NRJW_Pos (22UL)                    /*!< TT_CAN FLEXCAN_ENCBT: NRJW (Bit 22)               */
#define TT_CAN_FLEXCAN_ENCBT_NRJW_Msk (0x1fc00000UL)            /*!< TT_CAN FLEXCAN_ENCBT: NRJW (Bitfield-Mask: 0x7f)  */
/* =====================================================  FLEXCAN_EDCBT  ===================================================== */
#define TT_CAN_FLEXCAN_EDCBT_DTSEG1_Pos (0UL)                   /*!< TT_CAN FLEXCAN_EDCBT: DTSEG1 (Bit 0)              */
#define TT_CAN_FLEXCAN_EDCBT_DTSEG1_Msk (0x1fUL)                /*!< TT_CAN FLEXCAN_EDCBT: DTSEG1 (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_EDCBT_DTSEG2_Pos (12UL)                  /*!< TT_CAN FLEXCAN_EDCBT: DTSEG2 (Bit 12)             */
#define TT_CAN_FLEXCAN_EDCBT_DTSEG2_Msk (0xf000UL)              /*!< TT_CAN FLEXCAN_EDCBT: DTSEG2 (Bitfield-Mask: 0x0f) */
#define TT_CAN_FLEXCAN_EDCBT_DRJW_Pos (22UL)                    /*!< TT_CAN FLEXCAN_EDCBT: DRJW (Bit 22)               */
#define TT_CAN_FLEXCAN_EDCBT_DRJW_Msk (0x3c00000UL)             /*!< TT_CAN FLEXCAN_EDCBT: DRJW (Bitfield-Mask: 0x0f)  */
/* =====================================================  FLEXCAN_ETDC  ====================================================== */
#define TT_CAN_FLEXCAN_ETDC_ETDCVAL_Pos (0UL)                   /*!< TT_CAN FLEXCAN_ETDC: ETDCVAL (Bit 0)              */
#define TT_CAN_FLEXCAN_ETDC_ETDCVAL_Msk (0xffUL)                /*!< TT_CAN FLEXCAN_ETDC: ETDCVAL (Bitfield-Mask: 0xff) */
#define TT_CAN_FLEXCAN_ETDC_ETDCFAIL_Pos (15UL)                 /*!< TT_CAN FLEXCAN_ETDC: ETDCFAIL (Bit 15)            */
#define TT_CAN_FLEXCAN_ETDC_ETDCFAIL_Msk (0x8000UL)             /*!< TT_CAN FLEXCAN_ETDC: ETDCFAIL (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ETDC_ETDCOFF_Pos (16UL)                  /*!< TT_CAN FLEXCAN_ETDC: ETDCOFF (Bit 16)             */
#define TT_CAN_FLEXCAN_ETDC_ETDCOFF_Msk (0x7f0000UL)            /*!< TT_CAN FLEXCAN_ETDC: ETDCOFF (Bitfield-Mask: 0x7f) */
#define TT_CAN_FLEXCAN_ETDC_TDMDIS_Pos (30UL)                   /*!< TT_CAN FLEXCAN_ETDC: TDMDIS (Bit 30)              */
#define TT_CAN_FLEXCAN_ETDC_TDMDIS_Msk (0x40000000UL)           /*!< TT_CAN FLEXCAN_ETDC: TDMDIS (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ETDC_ETDCEN_Pos (31UL)                   /*!< TT_CAN FLEXCAN_ETDC: ETDCEN (Bit 31)              */
#define TT_CAN_FLEXCAN_ETDC_ETDCEN_Msk (0x80000000UL)           /*!< TT_CAN FLEXCAN_ETDC: ETDCEN (Bitfield-Mask: 0x01) */
/* ====================================================  FLEXCAN_FDCTRL  ===================================================== */
#define TT_CAN_FLEXCAN_FDCTRL_FDRATE_Pos (31UL)                 /*!< TT_CAN FLEXCAN_FDCTRL: FDRATE (Bit 31)            */
#define TT_CAN_FLEXCAN_FDCTRL_FDRATE_Msk (0x80000000UL)         /*!< TT_CAN FLEXCAN_FDCTRL: FDRATE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_FDCTRL_MBDSR3_Pos (25UL)                 /*!< TT_CAN FLEXCAN_FDCTRL: MBDSR3 (Bit 25)            */
#define TT_CAN_FLEXCAN_FDCTRL_MBDSR3_Msk (0x6000000UL)          /*!< TT_CAN FLEXCAN_FDCTRL: MBDSR3 (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_FDCTRL_MBDSR2_Pos (22UL)                 /*!< TT_CAN FLEXCAN_FDCTRL: MBDSR2 (Bit 22)            */
#define TT_CAN_FLEXCAN_FDCTRL_MBDSR2_Msk (0xc00000UL)           /*!< TT_CAN FLEXCAN_FDCTRL: MBDSR2 (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_FDCTRL_MBDSR1_Pos (19UL)                 /*!< TT_CAN FLEXCAN_FDCTRL: MBDSR1 (Bit 19)            */
#define TT_CAN_FLEXCAN_FDCTRL_MBDSR1_Msk (0x180000UL)           /*!< TT_CAN FLEXCAN_FDCTRL: MBDSR1 (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_FDCTRL_MBDSR0_Pos (16UL)                 /*!< TT_CAN FLEXCAN_FDCTRL: MBDSR0 (Bit 16)            */
#define TT_CAN_FLEXCAN_FDCTRL_MBDSR0_Msk (0x30000UL)            /*!< TT_CAN FLEXCAN_FDCTRL: MBDSR0 (Bitfield-Mask: 0x03) */
#define TT_CAN_FLEXCAN_FDCTRL_TDCEN_Pos (15UL)                  /*!< TT_CAN FLEXCAN_FDCTRL: TDCEN (Bit 15)             */
#define TT_CAN_FLEXCAN_FDCTRL_TDCEN_Msk (0x8000UL)              /*!< TT_CAN FLEXCAN_FDCTRL: TDCEN (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_FDCTRL_TDCFAIL_Pos (14UL)                /*!< TT_CAN FLEXCAN_FDCTRL: TDCFAIL (Bit 14)           */
#define TT_CAN_FLEXCAN_FDCTRL_TDCFAIL_Msk (0x4000UL)            /*!< TT_CAN FLEXCAN_FDCTRL: TDCFAIL (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_FDCTRL_TDCOFF_Pos (8UL)                  /*!< TT_CAN FLEXCAN_FDCTRL: TDCOFF (Bit 8)             */
#define TT_CAN_FLEXCAN_FDCTRL_TDCOFF_Msk (0x1f00UL)             /*!< TT_CAN FLEXCAN_FDCTRL: TDCOFF (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_FDCTRL_TDCVAL_Pos (0UL)                  /*!< TT_CAN FLEXCAN_FDCTRL: TDCVAL (Bit 0)             */
#define TT_CAN_FLEXCAN_FDCTRL_TDCVAL_Msk (0x3fUL)               /*!< TT_CAN FLEXCAN_FDCTRL: TDCVAL (Bitfield-Mask: 0x3f) */
/* =====================================================  FLEXCAN_FDCBT  ===================================================== */
#define TT_CAN_FLEXCAN_FDCBT_FPRESDIV_Pos (20UL)                /*!< TT_CAN FLEXCAN_FDCBT: FPRESDIV (Bit 20)           */
#define TT_CAN_FLEXCAN_FDCBT_FPRESDIV_Msk (0x3ff00000UL)        /*!< TT_CAN FLEXCAN_FDCBT: FPRESDIV (Bitfield-Mask: 0x3ff) */
#define TT_CAN_FLEXCAN_FDCBT_FRJW_Pos (16UL)                    /*!< TT_CAN FLEXCAN_FDCBT: FRJW (Bit 16)               */
#define TT_CAN_FLEXCAN_FDCBT_FRJW_Msk (0x70000UL)               /*!< TT_CAN FLEXCAN_FDCBT: FRJW (Bitfield-Mask: 0x07)  */
#define TT_CAN_FLEXCAN_FDCBT_FPROPSEG_Pos (10UL)                /*!< TT_CAN FLEXCAN_FDCBT: FPROPSEG (Bit 10)           */
#define TT_CAN_FLEXCAN_FDCBT_FPROPSEG_Msk (0x7c00UL)            /*!< TT_CAN FLEXCAN_FDCBT: FPROPSEG (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_FDCBT_FPSEG1_Pos (5UL)                   /*!< TT_CAN FLEXCAN_FDCBT: FPSEG1 (Bit 5)              */
#define TT_CAN_FLEXCAN_FDCBT_FPSEG1_Msk (0xe0UL)                /*!< TT_CAN FLEXCAN_FDCBT: FPSEG1 (Bitfield-Mask: 0x07) */
#define TT_CAN_FLEXCAN_FDCBT_FPSEG2_Pos (0UL)                   /*!< TT_CAN FLEXCAN_FDCBT: FPSEG2 (Bit 0)              */
#define TT_CAN_FLEXCAN_FDCBT_FPSEG2_Msk (0x7UL)                 /*!< TT_CAN FLEXCAN_FDCBT: FPSEG2 (Bitfield-Mask: 0x07) */
/* =====================================================  FLEXCAN_FDCRC  ===================================================== */
#define TT_CAN_FLEXCAN_FDCRC_FD_MBCRC_Pos (24UL)                /*!< TT_CAN FLEXCAN_FDCRC: FD_MBCRC (Bit 24)           */
#define TT_CAN_FLEXCAN_FDCRC_FD_MBCRC_Msk (0x7f000000UL)        /*!< TT_CAN FLEXCAN_FDCRC: FD_MBCRC (Bitfield-Mask: 0x7f) */
#define TT_CAN_FLEXCAN_FDCRC_FD_TXCRC_Pos (0UL)                 /*!< TT_CAN FLEXCAN_FDCRC: FD_TXCRC (Bit 0)            */
#define TT_CAN_FLEXCAN_FDCRC_FD_TXCRC_Msk (0x1fffffUL)          /*!< TT_CAN FLEXCAN_FDCRC: FD_TXCRC (Bitfield-Mask: 0x1fffff) */
/* =====================================================  FLEXCAN_ERFCR  ===================================================== */
#define TT_CAN_FLEXCAN_ERFCR_ERFWM_Pos (0UL)                    /*!< TT_CAN FLEXCAN_ERFCR: ERFWM (Bit 0)               */
#define TT_CAN_FLEXCAN_ERFCR_ERFWM_Msk (0x1fUL)                 /*!< TT_CAN FLEXCAN_ERFCR: ERFWM (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_ERFCR_NFE_Pos  (8UL)                     /*!< TT_CAN FLEXCAN_ERFCR: NFE (Bit 8)                 */
#define TT_CAN_FLEXCAN_ERFCR_NFE_Msk  (0x3f00UL)                /*!< TT_CAN FLEXCAN_ERFCR: NFE (Bitfield-Mask: 0x3f)   */
#define TT_CAN_FLEXCAN_ERFCR_NEXIF_Pos (16UL)                   /*!< TT_CAN FLEXCAN_ERFCR: NEXIF (Bit 16)              */
#define TT_CAN_FLEXCAN_ERFCR_NEXIF_Msk (0x7f0000UL)             /*!< TT_CAN FLEXCAN_ERFCR: NEXIF (Bitfield-Mask: 0x7f) */
#define TT_CAN_FLEXCAN_ERFCR_DMALW_Pos (26UL)                   /*!< TT_CAN FLEXCAN_ERFCR: DMALW (Bit 26)              */
#define TT_CAN_FLEXCAN_ERFCR_DMALW_Msk (0x7c000000UL)           /*!< TT_CAN FLEXCAN_ERFCR: DMALW (Bitfield-Mask: 0x1f) */
#define TT_CAN_FLEXCAN_ERFCR_ERFEN_Pos (31UL)                   /*!< TT_CAN FLEXCAN_ERFCR: ERFEN (Bit 31)              */
#define TT_CAN_FLEXCAN_ERFCR_ERFEN_Msk (0x80000000UL)           /*!< TT_CAN FLEXCAN_ERFCR: ERFEN (Bitfield-Mask: 0x01) */
/* ====================================================  FLEXCAN_ERFIER  ===================================================== */
#define TT_CAN_FLEXCAN_ERFIER_ERFDAIE_Pos (28UL)                /*!< TT_CAN FLEXCAN_ERFIER: ERFDAIE (Bit 28)           */
#define TT_CAN_FLEXCAN_ERFIER_ERFDAIE_Msk (0x10000000UL)        /*!< TT_CAN FLEXCAN_ERFIER: ERFDAIE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERFIER_ERFWMIIE_Pos (29UL)               /*!< TT_CAN FLEXCAN_ERFIER: ERFWMIIE (Bit 29)          */
#define TT_CAN_FLEXCAN_ERFIER_ERFWMIIE_Msk (0x20000000UL)       /*!< TT_CAN FLEXCAN_ERFIER: ERFWMIIE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERFIER_ERFOVFIE_Pos (30UL)               /*!< TT_CAN FLEXCAN_ERFIER: ERFOVFIE (Bit 30)          */
#define TT_CAN_FLEXCAN_ERFIER_ERFOVFIE_Msk (0x40000000UL)       /*!< TT_CAN FLEXCAN_ERFIER: ERFOVFIE (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERFIER_ERFUFWIE_Pos (31UL)               /*!< TT_CAN FLEXCAN_ERFIER: ERFUFWIE (Bit 31)          */
#define TT_CAN_FLEXCAN_ERFIER_ERFUFWIE_Msk (0x80000000UL)       /*!< TT_CAN FLEXCAN_ERFIER: ERFUFWIE (Bitfield-Mask: 0x01) */
/* =====================================================  FLEXCAN_ERFSR  ===================================================== */
#define TT_CAN_FLEXCAN_ERFSR_ERFEL_Pos (0UL)                    /*!< TT_CAN FLEXCAN_ERFSR: ERFEL (Bit 0)               */
#define TT_CAN_FLEXCAN_ERFSR_ERFEL_Msk (0x3fUL)                 /*!< TT_CAN FLEXCAN_ERFSR: ERFEL (Bitfield-Mask: 0x3f) */
#define TT_CAN_FLEXCAN_ERFSR_ERFF_Pos (16UL)                    /*!< TT_CAN FLEXCAN_ERFSR: ERFF (Bit 16)               */
#define TT_CAN_FLEXCAN_ERFSR_ERFF_Msk (0x10000UL)               /*!< TT_CAN FLEXCAN_ERFSR: ERFF (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_ERFSR_ERFE_Pos (17UL)                    /*!< TT_CAN FLEXCAN_ERFSR: ERFE (Bit 17)               */
#define TT_CAN_FLEXCAN_ERFSR_ERFE_Msk (0x20000UL)               /*!< TT_CAN FLEXCAN_ERFSR: ERFE (Bitfield-Mask: 0x01)  */
#define TT_CAN_FLEXCAN_ERFSR_ERFCLR_Pos (27UL)                  /*!< TT_CAN FLEXCAN_ERFSR: ERFCLR (Bit 27)             */
#define TT_CAN_FLEXCAN_ERFSR_ERFCLR_Msk (0x8000000UL)           /*!< TT_CAN FLEXCAN_ERFSR: ERFCLR (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERFSR_ERFDA_Pos (28UL)                   /*!< TT_CAN FLEXCAN_ERFSR: ERFDA (Bit 28)              */
#define TT_CAN_FLEXCAN_ERFSR_ERFDA_Msk (0x10000000UL)           /*!< TT_CAN FLEXCAN_ERFSR: ERFDA (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERFSR_ERFWMI_Pos (29UL)                  /*!< TT_CAN FLEXCAN_ERFSR: ERFWMI (Bit 29)             */
#define TT_CAN_FLEXCAN_ERFSR_ERFWMI_Msk (0x20000000UL)          /*!< TT_CAN FLEXCAN_ERFSR: ERFWMI (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERFSR_ERFOVF_Pos (30UL)                  /*!< TT_CAN FLEXCAN_ERFSR: ERFOVF (Bit 30)             */
#define TT_CAN_FLEXCAN_ERFSR_ERFOVF_Msk (0x40000000UL)          /*!< TT_CAN FLEXCAN_ERFSR: ERFOVF (Bitfield-Mask: 0x01) */
#define TT_CAN_FLEXCAN_ERFSR_ERFUFW_Pos (31UL)                  /*!< TT_CAN FLEXCAN_ERFSR: ERFUFW (Bit 31)             */
#define TT_CAN_FLEXCAN_ERFSR_ERFUFW_Msk (0x80000000UL)          /*!< TT_CAN FLEXCAN_ERFSR: ERFUFW (Bitfield-Mask: 0x01) */
/* =================================================  FLEXCAN_HR_TIME_STAMP  ================================================= */
#define TT_CAN_FLEXCAN_HR_TIME_STAMP_TS_Pos (0UL)               /*!< TT_CAN FLEXCAN_HR_TIME_STAMP: TS (Bit 0)          */
#define TT_CAN_FLEXCAN_HR_TIME_STAMP_TS_Msk (0xffffffffUL)      /*!< TT_CAN FLEXCAN_HR_TIME_STAMP: TS (Bitfield-Mask: 0xffffffff) */
/* ====================================================  FLEXCAN_ERFFEL  ===================================================== */
#define TT_CAN_FLEXCAN_ERFFEL_FEL_Pos (0UL)                     /*!< TT_CAN FLEXCAN_ERFFEL: FEL (Bit 0)                */
#define TT_CAN_FLEXCAN_ERFFEL_FEL_Msk (0xffffffffUL)            /*!< TT_CAN FLEXCAN_ERFFEL: FEL (Bitfield-Mask: 0xffffffff) */
	
#ifdef __cplusplus
}
#endif

#endif

