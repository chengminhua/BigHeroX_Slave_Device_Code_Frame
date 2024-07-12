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
#ifndef A8V2_DMA_H
#define A8V2_DMA_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_DMA_VENDOR_ID_H                     1541
#define A8V2_DMA_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_DMA_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_DMA_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_DMA_SW_MAJOR_VERSION_H              1
#define A8V2_DMA_SW_MINOR_VERSION_H              1
#define A8V2_DMA_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_DMA.h and TT_Common.h file version check */
#if (A8V2_DMA_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_DMA.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_DMA_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_DMA_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_DMA_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_DMA.h and TT_Common.h are different"
#endif
#if ((A8V2_DMA_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_DMA_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_DMA_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_DMA.h and TT_Common.h are different"
#endif


/**
  * @brief DMA Channel Config
  */
typedef struct {
    __IOM uint32  SRCADDR;                    /*!< (@ 0x00000000) DMA Channel Source Address Register                        */
    __IOM uint32  DESTADDR;                   /*!< (@ 0x00000004) DMA Channel Destination Address Register                   */
    __IOM uint32  LLI;                        /*!< (@ 0x00000008) DMA Channel Linked List Item Register                      */
    __IOM uint32  CONTROL;                    /*!< (@ 0x0000000C) DMA Channel Control Register                               */
    __IOM uint32  CONFIG;                     /*!< (@ 0x00000010) DMA Channel Configuration Register                         */
    __IOM uint32  MODE_EN;                    /*!< (@ 0x00000014) Mode Enable                                                */
    __IOM uint32  ONEMODE_EN;                 /*!< (@ 0x00000018) One Mode Channel X Enable                                  */
    __IOM uint32  MODE_CLR;                   /*!< (@ 0x0000001C) Mode Enable Clear                                          */
} TT_GPDMA0_ChannelConfig_Type;               /*!< Size = 32 (0x20)                                                          */
/* =========================================================================================================================== */
/* ================                                       DMA                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief General Purpose DMA (DMA) 0 (TT_DMA0)
  */

typedef struct {                                /*!< (@ 0x40182000) TT_DMA0 Structure                                    */
    __IM  uint32  INTSTAT;                      /*!< (@ 0x00000000) DMA Interrupt Status Register                              */
    __IM  uint32  INTTCSTAT;                    /*!< (@ 0x00000004) DMA Interrupt Terminal Count Request Status Register       */
    __OM  uint32  INTTCCLEAR;                   /*!< (@ 0x00000008) DMA Interrupt Terminal Count Request Clear Register        */
    __IM  uint32  INTERRSTAT;                   /*!< (@ 0x0000000C) DMA Interrupt Error Status Register                        */
    __OM  uint32  INTERRCLR;                    /*!< (@ 0x00000010) DMA Interrupt Error Clear Register                         */
    __IM  uint32  RAWINTTCSTAT;                 /*!< (@ 0x00000014) DMA Raw Interrupt Terminal Count Status Register           */
    __IM  uint32  RAWINTERRSTAT;                /*!< (@ 0x00000018) DMA Raw Error Interrupt Status Register                    */
    __IM  uint32  ENBLDCHNS;                    /*!< (@ 0x0000001C) DMA Enabled Channel Register                               */
    __IOM uint32  SOFTBREQ;                     /*!< (@ 0x00000020) DMA Software Burst Request Register                        */
    __IOM uint32  SOFTSREQ;                     /*!< (@ 0x00000024) DMA Software Single Request Register                       */
    __IOM uint32  SOFTLBREQ;                    /*!< (@ 0x00000028) DMA Software Last Burst Request Register                   */
    __IOM uint32  SOFTLSREQ;                    /*!< (@ 0x0000002C) DMA Software Last Single Request Register                  */
    __IOM uint32  CONFIG;                       /*!< (@ 0x00000030) DMA Configuration Register                                 */
    __IOM uint32  SYNC;                         /*!< (@ 0x00000034) DMA Synchronization Register                               */
    __IOM uint32  DMACREGSEL[4];                /*!< (@ 0x00000038) DMA Synchronization Register                               */
    __IM  uint32  RESERVED[46];
    __IOM TT_GPDMA0_ChannelConfig_Type ChannelConfig[8];/*!< (@ 0x00000100) DMA Channel Config                                 */
    __IM  uint32  RESERVED1[192];
    __IOM uint32  CITCR;                        /*!< (@ 0x00000500) Test Model                                                 */
    __IOM uint32  CITOP1;                       /*!< (@ 0x00000504) Response value in test mode                                */
    __IOM uint32  CITOP2;                       /*!< (@ 0x00000508) Response value in test mode                                */
    __IOM uint32  CITOP3;                       /*!< (@ 0x0000050C) Response value in test mode                                */
    __IM  uint32  RESERVED2[692];
    __IM  uint32  PIDR0;                        /*!< (@ 0x00000FE0) Peripheral ID 0 Register                                   */
    __IM  uint32  PIDR1;                        /*!< (@ 0x00000FE4) Peripheral ID 1 Register                                   */
    __IM  uint32  PIDR2;                        /*!< (@ 0x00000FE8) Peripheral ID 2 Register                                   */
    __IM  uint32  PIDR3;                        /*!< (@ 0x00000FEC) Peripheral ID 3 Register                                   */
    __IM  uint32  CIDR0;                        /*!< (@ 0x00000FF0) Component ID 0 Register                                    */
    __IM  uint32  CIDR1;                        /*!< (@ 0x00000FF4) Component ID 1 Register                                    */
    __IM  uint32  CIDR2;                        /*!< (@ 0x00000FF8) Component ID 2 Register                                    */
    __IM  uint32  CIDR3;                        /*!< (@ 0x00000FFC) Component ID 3 Register                                    */
} Dma_RegType;                                  /*!< Size = 4096 (0x1000)                                                      */

#define TT_DMA0_BASE          0x40182000UL
#define TT_DMA1_BASE          0x40183000UL
#define TT_DMA2_BASE          0x40184000UL
#define TT_DMA3_BASE          0x40185000UL
/* =========================================================================================================================== */
/* ================                                       TT_DMA                                        ================ */
/* =========================================================================================================================== */

#define TT_DMA0               ((Dma_RegType*)TT_DMA0_BASE)
#define TT_DMA1               ((Dma_RegType*)TT_DMA1_BASE)
#define TT_DMA2               ((Dma_RegType*)TT_DMA2_BASE)
#define TT_DMA3               ((Dma_RegType*)TT_DMA3_BASE)
/* ========================================================  INTSTAT  ======================================================== */
#define TT_DMA_INTSTAT_INTSTAT0_Pos (0UL)                     /*!< TT_DMA INTSTAT: INTSTAT0 (Bit 0)                */
#define TT_DMA_INTSTAT_INTSTAT0_Msk (0x1UL)                   /*!< TT_DMA INTSTAT: INTSTAT0 (Bitfield-Mask: 0x01)  */
#define TT_DMA_INTSTAT_INTSTAT1_Pos (1UL)                     /*!< TT_DMA INTSTAT: INTSTAT1 (Bit 1)                */
#define TT_DMA_INTSTAT_INTSTAT1_Msk (0x2UL)                   /*!< TT_DMA INTSTAT: INTSTAT1 (Bitfield-Mask: 0x01)  */
#define TT_DMA_INTSTAT_INTSTAT2_Pos (2UL)                     /*!< TT_DMA INTSTAT: INTSTAT2 (Bit 2)                */
#define TT_DMA_INTSTAT_INTSTAT2_Msk (0x4UL)                   /*!< TT_DMA INTSTAT: INTSTAT2 (Bitfield-Mask: 0x01)  */
#define TT_DMA_INTSTAT_INTSTAT3_Pos (3UL)                     /*!< TT_DMA INTSTAT: INTSTAT3 (Bit 3)                */
#define TT_DMA_INTSTAT_INTSTAT3_Msk (0x8UL)                   /*!< TT_DMA INTSTAT: INTSTAT3 (Bitfield-Mask: 0x01)  */
#define TT_DMA_INTSTAT_INTSTAT4_Pos (4UL)                     /*!< TT_DMA INTSTAT: INTSTAT4 (Bit 4)                */
#define TT_DMA_INTSTAT_INTSTAT4_Msk (0x10UL)                  /*!< TT_DMA INTSTAT: INTSTAT4 (Bitfield-Mask: 0x01)  */
#define TT_DMA_INTSTAT_INTSTAT5_Pos (5UL)                     /*!< TT_DMA INTSTAT: INTSTAT5 (Bit 5)                */
#define TT_DMA_INTSTAT_INTSTAT5_Msk (0x20UL)                  /*!< TT_DMA INTSTAT: INTSTAT5 (Bitfield-Mask: 0x01)  */
#define TT_DMA_INTSTAT_INTSTAT6_Pos (6UL)                     /*!< TT_DMA INTSTAT: INTSTAT6 (Bit 6)                */
#define TT_DMA_INTSTAT_INTSTAT6_Msk (0x40UL)                  /*!< TT_DMA INTSTAT: INTSTAT6 (Bitfield-Mask: 0x01)  */
#define TT_DMA_INTSTAT_INTSTAT7_Pos (7UL)                     /*!< TT_DMA INTSTAT: INTSTAT7 (Bit 7)                */
#define TT_DMA_INTSTAT_INTSTAT7_Msk (0x80UL)                  /*!< TT_DMA INTSTAT: INTSTAT7 (Bitfield-Mask: 0x01)  */
/* =======================================================  INTTCSTAT  ======================================================= */
#define TT_DMA_INTTCSTAT_INTTCSTAT0_Pos (0UL)                 /*!< TT_DMA INTTCSTAT: INTTCSTAT0 (Bit 0)            */
#define TT_DMA_INTTCSTAT_INTTCSTAT0_Msk (0x1UL)               /*!< TT_DMA INTTCSTAT: INTTCSTAT0 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCSTAT_INTTCSTAT1_Pos (1UL)                 /*!< TT_DMA INTTCSTAT: INTTCSTAT1 (Bit 1)            */
#define TT_DMA_INTTCSTAT_INTTCSTAT1_Msk (0x2UL)               /*!< TT_DMA INTTCSTAT: INTTCSTAT1 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCSTAT_INTTCSTAT2_Pos (2UL)                 /*!< TT_DMA INTTCSTAT: INTTCSTAT2 (Bit 2)            */
#define TT_DMA_INTTCSTAT_INTTCSTAT2_Msk (0x4UL)               /*!< TT_DMA INTTCSTAT: INTTCSTAT2 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCSTAT_INTTCSTAT3_Pos (3UL)                 /*!< TT_DMA INTTCSTAT: INTTCSTAT3 (Bit 3)            */
#define TT_DMA_INTTCSTAT_INTTCSTAT3_Msk (0x8UL)               /*!< TT_DMA INTTCSTAT: INTTCSTAT3 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCSTAT_INTTCSTAT4_Pos (4UL)                 /*!< TT_DMA INTTCSTAT: INTTCSTAT4 (Bit 4)            */
#define TT_DMA_INTTCSTAT_INTTCSTAT4_Msk (0x10UL)              /*!< TT_DMA INTTCSTAT: INTTCSTAT4 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCSTAT_INTTCSTAT5_Pos (5UL)                 /*!< TT_DMA INTTCSTAT: INTTCSTAT5 (Bit 5)            */
#define TT_DMA_INTTCSTAT_INTTCSTAT5_Msk (0x20UL)              /*!< TT_DMA INTTCSTAT: INTTCSTAT5 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCSTAT_INTTCSTAT6_Pos (6UL)                 /*!< TT_DMA INTTCSTAT: INTTCSTAT6 (Bit 6)            */
#define TT_DMA_INTTCSTAT_INTTCSTAT6_Msk (0x40UL)              /*!< TT_DMA INTTCSTAT: INTTCSTAT6 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCSTAT_INTTCSTAT7_Pos (7UL)                 /*!< TT_DMA INTTCSTAT: INTTCSTAT7 (Bit 7)            */
#define TT_DMA_INTTCSTAT_INTTCSTAT7_Msk (0x80UL)              /*!< TT_DMA INTTCSTAT: INTTCSTAT7 (Bitfield-Mask: 0x01) */
/* ======================================================  INTTCCLEAR  ======================================================= */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR0_Pos (0UL)               /*!< TT_DMA INTTCCLEAR: INTTCCLEAR0 (Bit 0)          */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR0_Msk (0x1UL)             /*!< TT_DMA INTTCCLEAR: INTTCCLEAR0 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR1_Pos (1UL)               /*!< TT_DMA INTTCCLEAR: INTTCCLEAR1 (Bit 1)          */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR1_Msk (0x2UL)             /*!< TT_DMA INTTCCLEAR: INTTCCLEAR1 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR2_Pos (2UL)               /*!< TT_DMA INTTCCLEAR: INTTCCLEAR2 (Bit 2)          */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR2_Msk (0x4UL)             /*!< TT_DMA INTTCCLEAR: INTTCCLEAR2 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR3_Pos (3UL)               /*!< TT_DMA INTTCCLEAR: INTTCCLEAR3 (Bit 3)          */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR3_Msk (0x8UL)             /*!< TT_DMA INTTCCLEAR: INTTCCLEAR3 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR4_Pos (4UL)               /*!< TT_DMA INTTCCLEAR: INTTCCLEAR4 (Bit 4)          */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR4_Msk (0x10UL)            /*!< TT_DMA INTTCCLEAR: INTTCCLEAR4 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR5_Pos (5UL)               /*!< TT_DMA INTTCCLEAR: INTTCCLEAR5 (Bit 5)          */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR5_Msk (0x20UL)            /*!< TT_DMA INTTCCLEAR: INTTCCLEAR5 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR6_Pos (6UL)               /*!< TT_DMA INTTCCLEAR: INTTCCLEAR6 (Bit 6)          */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR6_Msk (0x40UL)            /*!< TT_DMA INTTCCLEAR: INTTCCLEAR6 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR7_Pos (7UL)               /*!< TT_DMA INTTCCLEAR: INTTCCLEAR7 (Bit 7)          */
#define TT_DMA_INTTCCLEAR_INTTCCLEAR7_Msk (0x80UL)            /*!< TT_DMA INTTCCLEAR: INTTCCLEAR7 (Bitfield-Mask: 0x01) */
/* ======================================================  INTERRSTAT  ======================================================= */
#define TT_DMA_INTERRSTAT_INTERRSTAT0_Pos (0UL)               /*!< TT_DMA INTERRSTAT: INTERRSTAT0 (Bit 0)          */
#define TT_DMA_INTERRSTAT_INTERRSTAT0_Msk (0x1UL)             /*!< TT_DMA INTERRSTAT: INTERRSTAT0 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRSTAT_INTERRSTAT1_Pos (1UL)               /*!< TT_DMA INTERRSTAT: INTERRSTAT1 (Bit 1)          */
#define TT_DMA_INTERRSTAT_INTERRSTAT1_Msk (0x2UL)             /*!< TT_DMA INTERRSTAT: INTERRSTAT1 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRSTAT_INTERRSTAT2_Pos (2UL)               /*!< TT_DMA INTERRSTAT: INTERRSTAT2 (Bit 2)          */
#define TT_DMA_INTERRSTAT_INTERRSTAT2_Msk (0x4UL)             /*!< TT_DMA INTERRSTAT: INTERRSTAT2 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRSTAT_INTERRSTAT3_Pos (3UL)               /*!< TT_DMA INTERRSTAT: INTERRSTAT3 (Bit 3)          */
#define TT_DMA_INTERRSTAT_INTERRSTAT3_Msk (0x8UL)             /*!< TT_DMA INTERRSTAT: INTERRSTAT3 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRSTAT_INTERRSTAT4_Pos (4UL)               /*!< TT_DMA INTERRSTAT: INTERRSTAT4 (Bit 4)          */
#define TT_DMA_INTERRSTAT_INTERRSTAT4_Msk (0x10UL)            /*!< TT_DMA INTERRSTAT: INTERRSTAT4 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRSTAT_INTERRSTAT5_Pos (5UL)               /*!< TT_DMA INTERRSTAT: INTERRSTAT5 (Bit 5)          */
#define TT_DMA_INTERRSTAT_INTERRSTAT5_Msk (0x20UL)            /*!< TT_DMA INTERRSTAT: INTERRSTAT5 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRSTAT_INTERRSTAT6_Pos (6UL)               /*!< TT_DMA INTERRSTAT: INTERRSTAT6 (Bit 6)          */
#define TT_DMA_INTERRSTAT_INTERRSTAT6_Msk (0x40UL)            /*!< TT_DMA INTERRSTAT: INTERRSTAT6 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRSTAT_INTERRSTAT7_Pos (7UL)               /*!< TT_DMA INTERRSTAT: INTERRSTAT7 (Bit 7)          */
#define TT_DMA_INTERRSTAT_INTERRSTAT7_Msk (0x80UL)            /*!< TT_DMA INTERRSTAT: INTERRSTAT7 (Bitfield-Mask: 0x01) */
/* =======================================================  INTERRCLR  ======================================================= */
#define TT_DMA_INTERRCLR_INTERRCLR0_Pos (0UL)                 /*!< TT_DMA INTERRCLR: INTERRCLR0 (Bit 0)            */
#define TT_DMA_INTERRCLR_INTERRCLR0_Msk (0x1UL)               /*!< TT_DMA INTERRCLR: INTERRCLR0 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRCLR_INTERRCLR1_Pos (1UL)                 /*!< TT_DMA INTERRCLR: INTERRCLR1 (Bit 1)            */
#define TT_DMA_INTERRCLR_INTERRCLR1_Msk (0x2UL)               /*!< TT_DMA INTERRCLR: INTERRCLR1 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRCLR_INTERRCLR2_Pos (2UL)                 /*!< TT_DMA INTERRCLR: INTERRCLR2 (Bit 2)            */
#define TT_DMA_INTERRCLR_INTERRCLR2_Msk (0x4UL)               /*!< TT_DMA INTERRCLR: INTERRCLR2 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRCLR_INTERRCLR3_Pos (3UL)                 /*!< TT_DMA INTERRCLR: INTERRCLR3 (Bit 3)            */
#define TT_DMA_INTERRCLR_INTERRCLR3_Msk (0x8UL)               /*!< TT_DMA INTERRCLR: INTERRCLR3 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRCLR_INTERRCLR4_Pos (4UL)                 /*!< TT_DMA INTERRCLR: INTERRCLR4 (Bit 4)            */
#define TT_DMA_INTERRCLR_INTERRCLR4_Msk (0x10UL)              /*!< TT_DMA INTERRCLR: INTERRCLR4 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRCLR_INTERRCLR5_Pos (5UL)                 /*!< TT_DMA INTERRCLR: INTERRCLR5 (Bit 5)            */
#define TT_DMA_INTERRCLR_INTERRCLR5_Msk (0x20UL)              /*!< TT_DMA INTERRCLR: INTERRCLR5 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRCLR_INTERRCLR6_Pos (6UL)                 /*!< TT_DMA INTERRCLR: INTERRCLR6 (Bit 6)            */
#define TT_DMA_INTERRCLR_INTERRCLR6_Msk (0x40UL)              /*!< TT_DMA INTERRCLR: INTERRCLR6 (Bitfield-Mask: 0x01) */
#define TT_DMA_INTERRCLR_INTERRCLR7_Pos (7UL)                 /*!< TT_DMA INTERRCLR: INTERRCLR7 (Bit 7)            */
#define TT_DMA_INTERRCLR_INTERRCLR7_Msk (0x80UL)              /*!< TT_DMA INTERRCLR: INTERRCLR7 (Bitfield-Mask: 0x01) */
/* =====================================================  RAWINTTCSTAT  ====================================================== */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT0_Pos (0UL)           /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT0 (Bit 0)      */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT0_Msk (0x1UL)         /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT0 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT1_Pos (1UL)           /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT1 (Bit 1)      */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT1_Msk (0x2UL)         /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT1 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT2_Pos (2UL)           /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT2 (Bit 2)      */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT2_Msk (0x4UL)         /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT2 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT3_Pos (3UL)           /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT3 (Bit 3)      */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT3_Msk (0x8UL)         /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT3 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT4_Pos (4UL)           /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT4 (Bit 4)      */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT4_Msk (0x10UL)        /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT4 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT5_Pos (5UL)           /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT5 (Bit 5)      */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT5_Msk (0x20UL)        /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT5 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT6_Pos (6UL)           /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT6 (Bit 6)      */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT6_Msk (0x40UL)        /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT6 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT7_Pos (7UL)           /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT7 (Bit 7)      */
#define TT_DMA_RAWINTTCSTAT_RAWINTTCSTAT7_Msk (0x80UL)        /*!< TT_DMA RAWINTTCSTAT: RAWINTTCSTAT7 (Bitfield-Mask: 0x01) */
/* =====================================================  RAWINTERRSTAT  ===================================================== */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT0_Pos (0UL)         /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT0 (Bit 0)    */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT0_Msk (0x1UL)       /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT0 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT1_Pos (1UL)         /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT1 (Bit 1)    */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT1_Msk (0x2UL)       /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT1 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT2_Pos (2UL)         /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT2 (Bit 2)    */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT2_Msk (0x4UL)       /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT2 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT3_Pos (3UL)         /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT3 (Bit 3)    */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT3_Msk (0x8UL)       /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT3 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT4_Pos (4UL)         /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT4 (Bit 4)    */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT4_Msk (0x10UL)      /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT4 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT5_Pos (5UL)         /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT5 (Bit 5)    */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT5_Msk (0x20UL)      /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT5 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT6_Pos (6UL)         /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT6 (Bit 6)    */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT6_Msk (0x40UL)      /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT6 (Bitfield-Mask: 0x01) */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT7_Pos (7UL)         /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT7 (Bit 7)    */
#define TT_DMA_RAWINTERRSTAT_RAWINTERRSTAT7_Msk (0x80UL)      /*!< TT_DMA RAWINTERRSTAT: RAWINTERRSTAT7 (Bitfield-Mask: 0x01) */
/* =======================================================  ENBLDCHNS  ======================================================= */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS0_Pos (0UL)           /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS0 (Bit 0)      */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS0_Msk (0x1UL)         /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS0 (Bitfield-Mask: 0x01) */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS1_Pos (1UL)           /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS1 (Bit 1)      */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS1_Msk (0x2UL)         /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS1 (Bitfield-Mask: 0x01) */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS2_Pos (2UL)           /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS2 (Bit 2)      */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS2_Msk (0x4UL)         /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS2 (Bitfield-Mask: 0x01) */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS3_Pos (3UL)           /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS3 (Bit 3)      */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS3_Msk (0x8UL)         /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS3 (Bitfield-Mask: 0x01) */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS4_Pos (4UL)           /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS4 (Bit 4)      */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS4_Msk (0x10UL)        /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS4 (Bitfield-Mask: 0x01) */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS5_Pos (5UL)           /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS5 (Bit 5)      */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS5_Msk (0x20UL)        /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS5 (Bitfield-Mask: 0x01) */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS6_Pos (6UL)           /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS6 (Bit 6)      */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS6_Msk (0x40UL)        /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS6 (Bitfield-Mask: 0x01) */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS7_Pos (7UL)           /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS7 (Bit 7)      */
#define TT_DMA_ENBLDCHNS_ENABLEDCHANNELS7_Msk (0x80UL)        /*!< TT_DMA ENBLDCHNS: ENABLEDCHANNELS7 (Bitfield-Mask: 0x01) */
/* =======================================================  SOFTBREQ  ======================================================== */
#define TT_DMA_SOFTBREQ_SOFTBREQ0_Pos (0UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ0 (Bit 0)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ0_Msk (0x1UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ0 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ1_Pos (1UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ1 (Bit 1)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ1_Msk (0x2UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ1 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ2_Pos (2UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ2 (Bit 2)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ2_Msk (0x4UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ2 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ3_Pos (3UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ3 (Bit 3)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ3_Msk (0x8UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ3 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ4_Pos (4UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ4 (Bit 4)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ4_Msk (0x10UL)                /*!< TT_DMA SOFTBREQ: SOFTBREQ4 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ5_Pos (5UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ5 (Bit 5)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ5_Msk (0x20UL)                /*!< TT_DMA SOFTBREQ: SOFTBREQ5 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ6_Pos (6UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ6 (Bit 6)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ6_Msk (0x40UL)                /*!< TT_DMA SOFTBREQ: SOFTBREQ6 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ7_Pos (7UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ7 (Bit 7)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ7_Msk (0x80UL)                /*!< TT_DMA SOFTBREQ: SOFTBREQ7 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ8_Pos (8UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ8 (Bit 8)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ8_Msk (0x100UL)               /*!< TT_DMA SOFTBREQ: SOFTBREQ8 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ9_Pos (9UL)                   /*!< TT_DMA SOFTBREQ: SOFTBREQ9 (Bit 9)              */
#define TT_DMA_SOFTBREQ_SOFTBREQ9_Msk (0x200UL)               /*!< TT_DMA SOFTBREQ: SOFTBREQ9 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ10_Pos (10UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ10 (Bit 10)            */
#define TT_DMA_SOFTBREQ_SOFTBREQ10_Msk (0x400UL)              /*!< TT_DMA SOFTBREQ: SOFTBREQ10 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ11_Pos (11UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ11 (Bit 11)            */
#define TT_DMA_SOFTBREQ_SOFTBREQ11_Msk (0x800UL)              /*!< TT_DMA SOFTBREQ: SOFTBREQ11 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ12_Pos (12UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ12 (Bit 12)            */
#define TT_DMA_SOFTBREQ_SOFTBREQ12_Msk (0x1000UL)             /*!< TT_DMA SOFTBREQ: SOFTBREQ12 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ13_Pos (13UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ13 (Bit 13)            */
#define TT_DMA_SOFTBREQ_SOFTBREQ13_Msk (0x2000UL)             /*!< TT_DMA SOFTBREQ: SOFTBREQ13 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ14_Pos (14UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ14 (Bit 14)            */
#define TT_DMA_SOFTBREQ_SOFTBREQ14_Msk (0x4000UL)             /*!< TT_DMA SOFTBREQ: SOFTBREQ14 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTBREQ_SOFTBREQ15_Pos (15UL)                 /*!< TT_DMA SOFTBREQ: SOFTBREQ15 (Bit 15)            */
#define TT_DMA_SOFTBREQ_SOFTBREQ15_Msk (0x8000UL)             /*!< TT_DMA SOFTBREQ: SOFTBREQ15 (Bitfield-Mask: 0x01) */
/* =======================================================  SOFTSREQ  ======================================================== */
#define TT_DMA_SOFTSREQ_SOFTSREQ0_Pos (0UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ0 (Bit 0)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ0_Msk (0x1UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ0 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ1_Pos (1UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ1 (Bit 1)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ1_Msk (0x2UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ1 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ2_Pos (2UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ2 (Bit 2)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ2_Msk (0x4UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ2 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ3_Pos (3UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ3 (Bit 3)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ3_Msk (0x8UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ3 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ4_Pos (4UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ4 (Bit 4)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ4_Msk (0x10UL)                /*!< TT_DMA SOFTSREQ: SOFTSREQ4 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ5_Pos (5UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ5 (Bit 5)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ5_Msk (0x20UL)                /*!< TT_DMA SOFTSREQ: SOFTSREQ5 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ6_Pos (6UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ6 (Bit 6)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ6_Msk (0x40UL)                /*!< TT_DMA SOFTSREQ: SOFTSREQ6 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ7_Pos (7UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ7 (Bit 7)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ7_Msk (0x80UL)                /*!< TT_DMA SOFTSREQ: SOFTSREQ7 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ8_Pos (8UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ8 (Bit 8)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ8_Msk (0x100UL)               /*!< TT_DMA SOFTSREQ: SOFTSREQ8 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ9_Pos (9UL)                   /*!< TT_DMA SOFTSREQ: SOFTSREQ9 (Bit 9)              */
#define TT_DMA_SOFTSREQ_SOFTSREQ9_Msk (0x200UL)               /*!< TT_DMA SOFTSREQ: SOFTSREQ9 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ10_Pos (10UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ10 (Bit 10)            */
#define TT_DMA_SOFTSREQ_SOFTSREQ10_Msk (0x400UL)              /*!< TT_DMA SOFTSREQ: SOFTSREQ10 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ11_Pos (11UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ11 (Bit 11)            */
#define TT_DMA_SOFTSREQ_SOFTSREQ11_Msk (0x800UL)              /*!< TT_DMA SOFTSREQ: SOFTSREQ11 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ12_Pos (12UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ12 (Bit 12)            */
#define TT_DMA_SOFTSREQ_SOFTSREQ12_Msk (0x1000UL)             /*!< TT_DMA SOFTSREQ: SOFTSREQ12 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ13_Pos (13UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ13 (Bit 13)            */
#define TT_DMA_SOFTSREQ_SOFTSREQ13_Msk (0x2000UL)             /*!< TT_DMA SOFTSREQ: SOFTSREQ13 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ14_Pos (14UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ14 (Bit 14)            */
#define TT_DMA_SOFTSREQ_SOFTSREQ14_Msk (0x4000UL)             /*!< TT_DMA SOFTSREQ: SOFTSREQ14 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTSREQ_SOFTSREQ15_Pos (15UL)                 /*!< TT_DMA SOFTSREQ: SOFTSREQ15 (Bit 15)            */
#define TT_DMA_SOFTSREQ_SOFTSREQ15_Msk (0x8000UL)             /*!< TT_DMA SOFTSREQ: SOFTSREQ15 (Bitfield-Mask: 0x01) */
/* =======================================================  SOFTLBREQ  ======================================================= */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ0_Pos (0UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ0 (Bit 0)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ0_Msk (0x1UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ0 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ1_Pos (1UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ1 (Bit 1)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ1_Msk (0x2UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ1 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ2_Pos (2UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ2 (Bit 2)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ2_Msk (0x4UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ2 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ3_Pos (3UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ3 (Bit 3)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ3_Msk (0x8UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ3 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ4_Pos (4UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ4 (Bit 4)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ4_Msk (0x10UL)              /*!< TT_DMA SOFTLBREQ: SOFTLBREQ4 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ5_Pos (5UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ5 (Bit 5)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ5_Msk (0x20UL)              /*!< TT_DMA SOFTLBREQ: SOFTLBREQ5 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ6_Pos (6UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ6 (Bit 6)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ6_Msk (0x40UL)              /*!< TT_DMA SOFTLBREQ: SOFTLBREQ6 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ7_Pos (7UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ7 (Bit 7)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ7_Msk (0x80UL)              /*!< TT_DMA SOFTLBREQ: SOFTLBREQ7 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ8_Pos (8UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ8 (Bit 8)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ8_Msk (0x100UL)             /*!< TT_DMA SOFTLBREQ: SOFTLBREQ8 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ9_Pos (9UL)                 /*!< TT_DMA SOFTLBREQ: SOFTLBREQ9 (Bit 9)            */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ9_Msk (0x200UL)             /*!< TT_DMA SOFTLBREQ: SOFTLBREQ9 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ10_Pos (10UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ10 (Bit 10)          */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ10_Msk (0x400UL)            /*!< TT_DMA SOFTLBREQ: SOFTLBREQ10 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ11_Pos (11UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ11 (Bit 11)          */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ11_Msk (0x800UL)            /*!< TT_DMA SOFTLBREQ: SOFTLBREQ11 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ12_Pos (12UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ12 (Bit 12)          */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ12_Msk (0x1000UL)           /*!< TT_DMA SOFTLBREQ: SOFTLBREQ12 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ13_Pos (13UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ13 (Bit 13)          */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ13_Msk (0x2000UL)           /*!< TT_DMA SOFTLBREQ: SOFTLBREQ13 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ14_Pos (14UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ14 (Bit 14)          */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ14_Msk (0x4000UL)           /*!< TT_DMA SOFTLBREQ: SOFTLBREQ14 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ15_Pos (15UL)               /*!< TT_DMA SOFTLBREQ: SOFTLBREQ15 (Bit 15)          */
#define TT_DMA_SOFTLBREQ_SOFTLBREQ15_Msk (0x8000UL)           /*!< TT_DMA SOFTLBREQ: SOFTLBREQ15 (Bitfield-Mask: 0x01) */
/* =======================================================  SOFTLSREQ  ======================================================= */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ0_Pos (0UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ0 (Bit 0)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ0_Msk (0x1UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ0 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ1_Pos (1UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ1 (Bit 1)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ1_Msk (0x2UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ1 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ2_Pos (2UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ2 (Bit 2)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ2_Msk (0x4UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ2 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ3_Pos (3UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ3 (Bit 3)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ3_Msk (0x8UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ3 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ4_Pos (4UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ4 (Bit 4)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ4_Msk (0x10UL)              /*!< TT_DMA SOFTLSREQ: SOFTLSREQ4 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ5_Pos (5UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ5 (Bit 5)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ5_Msk (0x20UL)              /*!< TT_DMA SOFTLSREQ: SOFTLSREQ5 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ6_Pos (6UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ6 (Bit 6)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ6_Msk (0x40UL)              /*!< TT_DMA SOFTLSREQ: SOFTLSREQ6 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ7_Pos (7UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ7 (Bit 7)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ7_Msk (0x80UL)              /*!< TT_DMA SOFTLSREQ: SOFTLSREQ7 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ8_Pos (8UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ8 (Bit 8)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ8_Msk (0x100UL)             /*!< TT_DMA SOFTLSREQ: SOFTLSREQ8 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ9_Pos (9UL)                 /*!< TT_DMA SOFTLSREQ: SOFTLSREQ9 (Bit 9)            */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ9_Msk (0x200UL)             /*!< TT_DMA SOFTLSREQ: SOFTLSREQ9 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ10_Pos (10UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ10 (Bit 10)          */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ10_Msk (0x400UL)            /*!< TT_DMA SOFTLSREQ: SOFTLSREQ10 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ11_Pos (11UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ11 (Bit 11)          */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ11_Msk (0x800UL)            /*!< TT_DMA SOFTLSREQ: SOFTLSREQ11 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ12_Pos (12UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ12 (Bit 12)          */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ12_Msk (0x1000UL)           /*!< TT_DMA SOFTLSREQ: SOFTLSREQ12 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ13_Pos (13UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ13 (Bit 13)          */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ13_Msk (0x2000UL)           /*!< TT_DMA SOFTLSREQ: SOFTLSREQ13 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ14_Pos (14UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ14 (Bit 14)          */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ14_Msk (0x4000UL)           /*!< TT_DMA SOFTLSREQ: SOFTLSREQ14 (Bitfield-Mask: 0x01) */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ15_Pos (15UL)               /*!< TT_DMA SOFTLSREQ: SOFTLSREQ15 (Bit 15)          */
#define TT_DMA_SOFTLSREQ_SOFTLSREQ15_Msk (0x8000UL)           /*!< TT_DMA SOFTLSREQ: SOFTLSREQ15 (Bitfield-Mask: 0x01) */
/* ========================================================  CONFIG  ========================================================= */
#define TT_DMA_CONFIG_E_Pos         (0UL)                     /*!< TT_DMA CONFIG: E (Bit 0)                        */
#define TT_DMA_CONFIG_E_Msk         (0x1UL)                   /*!< TT_DMA CONFIG: E (Bitfield-Mask: 0x01)          */
#define TT_DMA_CONFIG_M1_Pos        (1UL)                     /*!< TT_DMA CONFIG: M1 (Bit 1)                       */
#define TT_DMA_CONFIG_M1_Msk        (0x2UL)                   /*!< TT_DMA CONFIG: M1 (Bitfield-Mask: 0x01)         */
#define TT_DMA_CONFIG_M2_Pos        (2UL)                     /*!< TT_DMA CONFIG: M2 (Bit 2)                       */
#define TT_DMA_CONFIG_M2_Msk        (0x4UL)                   /*!< TT_DMA CONFIG: M2 (Bitfield-Mask: 0x01)         */
/* =========================================================  SYNC  ========================================================== */
#define TT_DMA_SYNC_DMACSYNC0_Pos   (0UL)                     /*!< TT_DMA SYNC: DMACSYNC0 (Bit 0)                  */
#define TT_DMA_SYNC_DMACSYNC0_Msk   (0x1UL)                   /*!< TT_DMA SYNC: DMACSYNC0 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC1_Pos   (1UL)                     /*!< TT_DMA SYNC: DMACSYNC1 (Bit 1)                  */
#define TT_DMA_SYNC_DMACSYNC1_Msk   (0x2UL)                   /*!< TT_DMA SYNC: DMACSYNC1 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC2_Pos   (2UL)                     /*!< TT_DMA SYNC: DMACSYNC2 (Bit 2)                  */
#define TT_DMA_SYNC_DMACSYNC2_Msk   (0x4UL)                   /*!< TT_DMA SYNC: DMACSYNC2 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC3_Pos   (3UL)                     /*!< TT_DMA SYNC: DMACSYNC3 (Bit 3)                  */
#define TT_DMA_SYNC_DMACSYNC3_Msk   (0x8UL)                   /*!< TT_DMA SYNC: DMACSYNC3 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC4_Pos   (4UL)                     /*!< TT_DMA SYNC: DMACSYNC4 (Bit 4)                  */
#define TT_DMA_SYNC_DMACSYNC4_Msk   (0x10UL)                  /*!< TT_DMA SYNC: DMACSYNC4 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC5_Pos   (5UL)                     /*!< TT_DMA SYNC: DMACSYNC5 (Bit 5)                  */
#define TT_DMA_SYNC_DMACSYNC5_Msk   (0x20UL)                  /*!< TT_DMA SYNC: DMACSYNC5 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC6_Pos   (6UL)                     /*!< TT_DMA SYNC: DMACSYNC6 (Bit 6)                  */
#define TT_DMA_SYNC_DMACSYNC6_Msk   (0x40UL)                  /*!< TT_DMA SYNC: DMACSYNC6 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC7_Pos   (7UL)                     /*!< TT_DMA SYNC: DMACSYNC7 (Bit 7)                  */
#define TT_DMA_SYNC_DMACSYNC7_Msk   (0x80UL)                  /*!< TT_DMA SYNC: DMACSYNC7 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC8_Pos   (8UL)                     /*!< TT_DMA SYNC: DMACSYNC8 (Bit 8)                  */
#define TT_DMA_SYNC_DMACSYNC8_Msk   (0x100UL)                 /*!< TT_DMA SYNC: DMACSYNC8 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC9_Pos   (9UL)                     /*!< TT_DMA SYNC: DMACSYNC9 (Bit 9)                  */
#define TT_DMA_SYNC_DMACSYNC9_Msk   (0x200UL)                 /*!< TT_DMA SYNC: DMACSYNC9 (Bitfield-Mask: 0x01)    */
#define TT_DMA_SYNC_DMACSYNC10_Pos  (10UL)                    /*!< TT_DMA SYNC: DMACSYNC10 (Bit 10)                */
#define TT_DMA_SYNC_DMACSYNC10_Msk  (0x400UL)                 /*!< TT_DMA SYNC: DMACSYNC10 (Bitfield-Mask: 0x01)   */
#define TT_DMA_SYNC_DMACSYNC11_Pos  (11UL)                    /*!< TT_DMA SYNC: DMACSYNC11 (Bit 11)                */
#define TT_DMA_SYNC_DMACSYNC11_Msk  (0x800UL)                 /*!< TT_DMA SYNC: DMACSYNC11 (Bitfield-Mask: 0x01)   */
#define TT_DMA_SYNC_DMACSYNC12_Pos  (12UL)                    /*!< TT_DMA SYNC: DMACSYNC12 (Bit 12)                */
#define TT_DMA_SYNC_DMACSYNC12_Msk  (0x1000UL)                /*!< TT_DMA SYNC: DMACSYNC12 (Bitfield-Mask: 0x01)   */
#define TT_DMA_SYNC_DMACSYNC13_Pos  (13UL)                    /*!< TT_DMA SYNC: DMACSYNC13 (Bit 13)                */
#define TT_DMA_SYNC_DMACSYNC13_Msk  (0x2000UL)                /*!< TT_DMA SYNC: DMACSYNC13 (Bitfield-Mask: 0x01)   */
#define TT_DMA_SYNC_DMACSYNC14_Pos  (14UL)                    /*!< TT_DMA SYNC: DMACSYNC14 (Bit 14)                */
#define TT_DMA_SYNC_DMACSYNC14_Msk  (0x4000UL)                /*!< TT_DMA SYNC: DMACSYNC14 (Bitfield-Mask: 0x01)   */
#define TT_DMA_SYNC_DMACSYNC15_Pos  (15UL)                    /*!< TT_DMA SYNC: DMACSYNC15 (Bit 15)                */
#define TT_DMA_SYNC_DMACSYNC15_Msk  (0x8000UL)                /*!< TT_DMA SYNC: DMACSYNC15 (Bitfield-Mask: 0x01)   */
/* ======================================================  DMACREGSEL  ======================================================= */
#define TT_DMA_DMACREGSEL_SEL3_Pos  (24UL)                    /*!< TT_DMA DMACREGSEL: SEL3 (Bit 24)                */
#define TT_DMA_DMACREGSEL_SEL3_Msk  (0x3f000000UL)            /*!< TT_DMA DMACREGSEL: SEL3 (Bitfield-Mask: 0x3f)   */
#define TT_DMA_DMACREGSEL_SEL2_Pos  (16UL)                    /*!< TT_DMA DMACREGSEL: SEL2 (Bit 16)                */
#define TT_DMA_DMACREGSEL_SEL2_Msk  (0x3f0000UL)              /*!< TT_DMA DMACREGSEL: SEL2 (Bitfield-Mask: 0x3f)   */
#define TT_DMA_DMACREGSEL_SEL1_Pos  (8UL)                     /*!< TT_DMA DMACREGSEL: SEL1 (Bit 8)                 */
#define TT_DMA_DMACREGSEL_SEL1_Msk  (0x3f00UL)                /*!< TT_DMA DMACREGSEL: SEL1 (Bitfield-Mask: 0x3f)   */
#define TT_DMA_DMACREGSEL_SEL0_Pos  (0UL)                     /*!< TT_DMA DMACREGSEL: SEL0 (Bit 0)                 */
#define TT_DMA_DMACREGSEL_SEL0_Msk  (0x3fUL)                  /*!< TT_DMA DMACREGSEL: SEL0 (Bitfield-Mask: 0x3f)   */
/* =======================================================  CSRCADDR  ======================================================== */
#define TT_DMA_CSRCADDR_SRCADDR_Pos (0UL)                     /*!< TT_DMA CSRCADDR: SRCADDR (Bit 0)                */
#define TT_DMA_CSRCADDR_SRCADDR_Msk (0xffffffffUL)            /*!< TT_DMA CSRCADDR: SRCADDR (Bitfield-Mask: 0xffffffff) */
/* =======================================================  CDESTADDR  ======================================================= */
#define TT_DMA_CDESTADDR_DESTADDR_Pos (0UL)                   /*!< TT_DMA CDESTADDR: DESTADDR (Bit 0)              */
#define TT_DMA_CDESTADDR_DESTADDR_Msk (0xffffffffUL)          /*!< TT_DMA CDESTADDR: DESTADDR (Bitfield-Mask: 0xffffffff) */
/* =========================================================  CLLI  ========================================================== */
#define TT_DMA_CLLI_LM_Pos          (0UL)                     /*!< TT_DMA CLLI: LM (Bit 0)                         */
#define TT_DMA_CLLI_LM_Msk          (0x1UL)                   /*!< TT_DMA CLLI: LM (Bitfield-Mask: 0x01)           */
#define TT_DMA_CLLI_AUTOSTART_Pos   (1UL)                     /*!< TT_DMA CLLI: AUTOSTART (Bit 1)                  */
#define TT_DMA_CLLI_AUTOSTART_Msk   (0x2UL)                   /*!< TT_DMA CLLI: AUTOSTART (Bitfield-Mask: 0x01)    */
#define TT_DMA_CLLI_LLI_Pos         (2UL)                     /*!< TT_DMA CLLI: LLI (Bit 2)                        */
#define TT_DMA_CLLI_LLI_Msk         (0xfffffffcUL)            /*!< TT_DMA CLLI: LLI (Bitfield-Mask: 0x3fffffff)    */
/* =======================================================  CCONTROL  ======================================================== */
#define TT_DMA_CCONTROL_TRANSFERSIZE_Pos (0UL)                /*!< TT_DMA CCONTROL: TRANSFERSIZE (Bit 0)           */
#define TT_DMA_CCONTROL_TRANSFERSIZE_Msk (0xfffUL)            /*!< TT_DMA CCONTROL: TRANSFERSIZE (Bitfield-Mask: 0xfff) */
#define TT_DMA_CCONTROL_SBSIZE_Pos  (12UL)                    /*!< TT_DMA CCONTROL: SBSIZE (Bit 12)                */
#define TT_DMA_CCONTROL_SBSIZE_Msk  (0x7000UL)                /*!< TT_DMA CCONTROL: SBSIZE (Bitfield-Mask: 0x07)   */
#define TT_DMA_CCONTROL_DBSIZE_Pos  (15UL)                    /*!< TT_DMA CCONTROL: DBSIZE (Bit 15)                */
#define TT_DMA_CCONTROL_DBSIZE_Msk  (0x38000UL)               /*!< TT_DMA CCONTROL: DBSIZE (Bitfield-Mask: 0x07)   */
#define TT_DMA_CCONTROL_SWIDTH_Pos  (18UL)                    /*!< TT_DMA CCONTROL: SWIDTH (Bit 18)                */
#define TT_DMA_CCONTROL_SWIDTH_Msk  (0xc0000UL)               /*!< TT_DMA CCONTROL: SWIDTH (Bitfield-Mask: 0x03)   */
#define TT_DMA_CCONTROL_INT_TTRG_Pos (20UL)                   /*!< TT_DMA CCONTROL: INT_TTRG (Bit 20)              */
#define TT_DMA_CCONTROL_INT_TTRG_Msk (0x100000UL)             /*!< TT_DMA CCONTROL: INT_TTRG (Bitfield-Mask: 0x01) */
#define TT_DMA_CCONTROL_DWIDTH_Pos  (21UL)                    /*!< TT_DMA CCONTROL: DWIDTH (Bit 21)                */
#define TT_DMA_CCONTROL_DWIDTH_Msk  (0xe00000UL)              /*!< TT_DMA CCONTROL: DWIDTH (Bitfield-Mask: 0x07)   */
#define TT_DMA_CCONTROL_ALLINONE_Pos (23UL)                   /*!< TT_DMA CCONTROL: ALLINONE (Bit 20)              */
#define TT_DMA_CCONTROL_ALLINONE_Msk (0x800000UL)             /*!< TT_DMA CCONTROL: ALLINONE (Bitfield-Mask: 0x01) */
#define TT_DMA_CCONTROL_S_Pos       (24UL)                    /*!< TT_DMA CCONTROL: S (Bit 24)                     */
#define TT_DMA_CCONTROL_S_Msk       (0x1000000UL)             /*!< TT_DMA CCONTROL: S (Bitfield-Mask: 0x01)        */
#define TT_DMA_CCONTROL_D_Pos       (25UL)                    /*!< TT_DMA CCONTROL: D (Bit 25)                     */
#define TT_DMA_CCONTROL_D_Msk       (0x2000000UL)             /*!< TT_DMA CCONTROL: D (Bitfield-Mask: 0x01)        */
#define TT_DMA_CCONTROL_SI_Pos      (26UL)                    /*!< TT_DMA CCONTROL: SI (Bit 26)                    */
#define TT_DMA_CCONTROL_SI_Msk      (0x4000000UL)             /*!< TT_DMA CCONTROL: SI (Bitfield-Mask: 0x01)       */
#define TT_DMA_CCONTROL_DI_Pos      (27UL)                    /*!< TT_DMA CCONTROL: DI (Bit 27)                    */
#define TT_DMA_CCONTROL_DI_Msk      (0x8000000UL)             /*!< TT_DMA CCONTROL: DI (Bitfield-Mask: 0x01)       */
#define TT_DMA_CCONTROL_PROT1_Pos   (28UL)                    /*!< TT_DMA CCONTROL: PROT1 (Bit 28)                 */
#define TT_DMA_CCONTROL_PROT1_Msk   (0x10000000UL)            /*!< TT_DMA CCONTROL: PROT1 (Bitfield-Mask: 0x01)    */
#define TT_DMA_CCONTROL_PROT2_Pos   (29UL)                    /*!< TT_DMA CCONTROL: PROT2 (Bit 29)                 */
#define TT_DMA_CCONTROL_PROT2_Msk   (0x20000000UL)            /*!< TT_DMA CCONTROL: PROT2 (Bitfield-Mask: 0x01)    */
#define TT_DMA_CCONTROL_PROT3_Pos   (30UL)                    /*!< TT_DMA CCONTROL: PROT3 (Bit 30)                 */
#define TT_DMA_CCONTROL_PROT3_Msk   (0x40000000UL)            /*!< TT_DMA CCONTROL: PROT3 (Bitfield-Mask: 0x01)    */
#define TT_DMA_CCONTROL_I_Pos       (31UL)                    /*!< TT_DMA CCONTROL: I (Bit 31)                     */
#define TT_DMA_CCONTROL_I_Msk       (0x80000000UL)            /*!< TT_DMA CCONTROL: I (Bitfield-Mask: 0x01)        */
/* ========================================================  CCONFIG  ======================================================== */
#define TT_DMA_CCONFIG_E_Pos        (0UL)                     /*!< TT_DMA CCONFIG: E (Bit 0)                       */
#define TT_DMA_CCONFIG_E_Msk        (0x1UL)                   /*!< TT_DMA CCONFIG: E (Bitfield-Mask: 0x01)         */
#define TT_DMA_CCONFIG_SRCPERIPHERAL_Pos (1UL)                /*!< TT_DMA CCONFIG: SRCPERIPHERAL (Bit 1)           */
#define TT_DMA_CCONFIG_SRCPERIPHERAL_Msk (0x1eUL)             /*!< TT_DMA CCONFIG: SRCPERIPHERAL (Bitfield-Mask: 0x0f) */
#define TT_DMA_CCONFIG_DESTPERIPHERAL_Pos (6UL)               /*!< TT_DMA CCONFIG: DESTPERIPHERAL (Bit 6)          */
#define TT_DMA_CCONFIG_DESTPERIPHERAL_Msk (0x3c0UL)           /*!< TT_DMA CCONFIG: DESTPERIPHERAL (Bitfield-Mask: 0x0f) */
#define TT_DMA_CCONFIG_FLOWCNTRL_Pos (11UL)                   /*!< TT_DMA CCONFIG: FLOWCNTRL (Bit 11)              */
#define TT_DMA_CCONFIG_FLOWCNTRL_Msk (0x3800UL)               /*!< TT_DMA CCONFIG: FLOWCNTRL (Bitfield-Mask: 0x07) */
#define TT_DMA_CCONFIG_IE_Pos       (14UL)                    /*!< TT_DMA CCONFIG: IE (Bit 14)                     */
#define TT_DMA_CCONFIG_IE_Msk       (0x4000UL)                /*!< TT_DMA CCONFIG: IE (Bitfield-Mask: 0x01)        */
#define TT_DMA_CCONFIG_ITC_Pos      (15UL)                    /*!< TT_DMA CCONFIG: ITC (Bit 15)                    */
#define TT_DMA_CCONFIG_ITC_Msk      (0x8000UL)                /*!< TT_DMA CCONFIG: ITC (Bitfield-Mask: 0x01)       */
#define TT_DMA_CCONFIG_L_Pos        (16UL)                    /*!< TT_DMA CCONFIG: L (Bit 16)                      */
#define TT_DMA_CCONFIG_L_Msk        (0x10000UL)               /*!< TT_DMA CCONFIG: L (Bitfield-Mask: 0x01)         */
#define TT_DMA_CCONFIG_A_Pos        (17UL)                    /*!< TT_DMA CCONFIG: A (Bit 17)                      */
#define TT_DMA_CCONFIG_A_Msk        (0x20000UL)               /*!< TT_DMA CCONFIG: A (Bitfield-Mask: 0x01)         */
#define TT_DMA_CCONFIG_H_Pos        (18UL)                    /*!< TT_DMA CCONFIG: H (Bit 18)                      */
#define TT_DMA_CCONFIG_H_Msk        (0x40000UL)               /*!< TT_DMA CCONFIG: H (Bitfield-Mask: 0x01)         */
/* =======================================================  CMODE_EN  ======================================================== */
#define TT_DMA_CMODE_EN_ONE_MODE_EN_TEMP_Pos (0UL)            /*!< TT_DMA CMODE_EN: ONE_MODE_EN_TEMP (Bit 0)       */
#define TT_DMA_CMODE_EN_ONE_MODE_EN_TEMP_Msk (0xffUL)         /*!< TT_DMA CMODE_EN: ONE_MODE_EN_TEMP (Bitfield-Mask: 0xff) */
#define TT_DMA_CMODE_EN_CONTINUE_MODE_EN_TEMP_Pos (8UL)       /*!< TT_DMA CMODE_EN: CONTINUE_MODE_EN_TEMP (Bit 8)  */
#define TT_DMA_CMODE_EN_CONTINUE_MODE_EN_TEMP_Msk (0x100UL)   /*!< TT_DMA CMODE_EN: CONTINUE_MODE_EN_TEMP (Bitfield-Mask: 0x01) */
#define TT_DMA_CMODE_EN_ONE_MODE_EN_CNT_Pos (16UL)            /*!< TT_DMA CMODE_EN: ONE_MODE_EN_CNT (Bit 16)       */
#define TT_DMA_CMODE_EN_ONE_MODE_EN_CNT_Msk (0xff0000UL)      /*!< TT_DMA CMODE_EN: ONE_MODE_EN_CNT (Bitfield-Mask: 0xff) */
#define TT_DMA_CMODE_EN_ONE_MODE_EN_Pos (24UL)                /*!< TT_DMA CMODE_EN: ONE_MODE_EN (Bit 24)           */
#define TT_DMA_CMODE_EN_ONE_MODE_EN_Msk (0x1000000UL)         /*!< TT_DMA CMODE_EN: ONE_MODE_EN (Bitfield-Mask: 0x01) */
#define TT_DMA_CMODE_EN_CONTINUE_MODE_EN_Pos (25UL)           /*!< TT_DMA CMODE_EN: CONTINUE_MODE_EN (Bit 25)      */
#define TT_DMA_CMODE_EN_CONTINUE_MODE_EN_Msk (0x2000000UL)    /*!< TT_DMA CMODE_EN: CONTINUE_MODE_EN (Bitfield-Mask: 0x01) */
/* =====================================================  C_ONEMODE_EN  ====================================================== */
#define TT_DMA_C_ONEMODE_EN_ONE_MODE_EN_Pos (0UL)             /*!< TT_DMA C_ONEMODE_EN: ONE_MODE_EN (Bit 0)        */
#define TT_DMA_C_ONEMODE_EN_ONE_MODE_EN_Msk (0x1UL)           /*!< TT_DMA C_ONEMODE_EN: ONE_MODE_EN (Bitfield-Mask: 0x01) */
#define TT_DMA_C_CH_BUSY_Pos (16UL)            				  /*!< TT_DMA_C_CH_BUSY_Pos (Bit 16)        */
#define TT_DMA_C_CH_BUSY_Msk (0x10000UL)                          /*!< TT_DMA_C_CH_BUSY_Msk (Bitfield-Mask: 0x01) */
/* ======================================================  C_MODE_CLR  ======================================================= */
#define TT_DMA_C_MODE_CLR_CONTINUE_MODE_CLR_Pos (0UL)         /*!< TT_DMA C_MODE_CLR: CONTINUE_MODE_CLR (Bit 0)    */
#define TT_DMA_C_MODE_CLR_CONTINUE_MODE_CLR_Msk (0x1UL)       /*!< TT_DMA C_MODE_CLR: CONTINUE_MODE_CLR (Bitfield-Mask: 0x01) */
#define TT_DMA_C_MODE_CLR_ONE_MODE_CNT_CLR_Pos (8UL)          /*!< TT_DMA C_MODE_CLR: ONE_MODE_CNT_CLR (Bit 8)     */
#define TT_DMA_C_MODE_CLR_ONE_MODE_CNT_CLR_Msk (0x100UL)      /*!< TT_DMA C_MODE_CLR: ONE_MODE_CNT_CLR (Bitfield-Mask: 0x01) */
/* =========================================================  PIDR0  ========================================================= */
/* =========================================================  PIDR1  ========================================================= */
/* =========================================================  PIDR2  ========================================================= */
/* =========================================================  PIDR3  ========================================================= */
/* =========================================================  CIDR0  ========================================================= */
/* =========================================================  CIDR1  ========================================================= */
/* =========================================================  CIDR2  ========================================================= */
/* =========================================================  CIDR3  ========================================================= */
/* =========================================================  CITCR  ========================================================= */
#define TT_DMA_CITCR_T_Pos          (0UL)                     /*!< TT_DMA CITCR: T (Bit 0)                         */
#define TT_DMA_CITCR_T_Msk          (0x1UL)                   /*!< TT_DMA CITCR: T (Bitfield-Mask: 0x01)           */
/* ========================================================  CITOR1  ========================================================= */
#define TT_DMA_CITOR1_DMACCLR_Pos   (0UL)                     /*!< TT_DMA CITOR1: DMACCLR (Bit 0)                  */
#define TT_DMA_CITOR1_DMACCLR_Msk   (0xffffUL)                /*!< TT_DMA CITOR1: DMACCLR (Bitfield-Mask: 0xffff)  */
/* ========================================================  CITOR2  ========================================================= */
#define TT_DMA_CITOR2_DMACTC_Pos    (0UL)                     /*!< TT_DMA CITOR2: DMACTC (Bit 0)                   */
#define TT_DMA_CITOR2_DMACTC_Msk    (0xffffUL)                /*!< TT_DMA CITOR2: DMACTC (Bitfield-Mask: 0xffff)   */
/* ========================================================  CITOR3  ========================================================= */
#define TT_DMA_CITOR3_TC_Pos        (0UL)                     /*!< TT_DMA CITOR3: TC (Bit 0)                       */
#define TT_DMA_CITOR3_TC_Msk        (0x1UL)                   /*!< TT_DMA CITOR3: TC (Bitfield-Mask: 0x01)         */
#define TT_DMA_CITOR3_E_Pos         (1UL)                     /*!< TT_DMA CITOR3: E (Bit 1)                        */
#define TT_DMA_CITOR3_E_Msk         (0x2UL)                   /*!< TT_DMA CITOR3: E (Bitfield-Mask: 0x01)          */

#ifdef __cplusplus
}
#endif

#endif
