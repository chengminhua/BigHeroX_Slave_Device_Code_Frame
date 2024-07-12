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
#ifndef A8V2E_I2C_H
#define A8V2E_I2C_H
#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_I2C_VENDOR_ID_H                     1541
#define A8V2E_I2C_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_I2C_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_I2C_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_I2C_SW_MAJOR_VERSION_H              1
#define A8V2E_I2C_SW_MINOR_VERSION_H              1
#define A8V2E_I2C_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_I2C.h and TT_Common.h file version check */
#if (A8V2E_I2C_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_I2C.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_I2C_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_I2C_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_I2C_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_I2C.h and TT_Common.h are different"
#endif
#if ((A8V2E_I2C_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_I2C_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_I2C_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_I2C.h and TT_Common.h are different"
#endif


/**
  * @brief Inter-Integrated Circuit Bus 0 (TT_I2C0)
  */
typedef volatile struct {                                /*!< (@ 0x400A7000) TT_I2C0 Structure                                      */
    __IOM uint32  CON;                          /*!< (@ 0x00000000) I2C Control Register.                                      */
    __IOM uint32  TAR;                          /*!< (@ 0x00000004) I2C Target Address Register.                               */
    __IOM uint32  SAR;                          /*!< (@ 0x00000008) I2C Slave Address Register.                                */
    __IOM uint32  HS_MADDR;                     /*!< (@ 0x0000000C) I2C High Speed Master Mode Code Address Register.          */
    __IOM uint32  DATA_CMD;                     /*!< (@ 0x00000010) I2C Rx/Tx Data Buffer and Command Register.                */
    __IOM uint32  SS_SCL_HCNT;                  /*!< (@ 0x00000014) Standard Speed I2C Clock SCL High Count Register.          */
    __IOM uint32  SS_SCL_LCNT;                  /*!< (@ 0x00000018) Standard Speed I2C Clock SCL Low Count Register.           */
    __IOM uint32  FS_SCL_HCNT;                  /*!< (@ 0x0000001C) Fast Speed I2C Clock SCL High Count Register.              */
    __IOM uint32  FS_SCL_LCNT;                  /*!< (@ 0x00000020) Fast Speed I2C Clock SCL Low Count Register.               */
    __IOM uint32  HS_SCL_HCNT;                  /*!< (@ 0x00000024) Fast Speed I2C Clock SCL Low Count Register.               */
    __IOM uint32  HS_SCL_LCNT;                  /*!< (@ 0x00000028) High Speed I2C Clock SCL Low Count Register.               */
    __IM  uint32  INTR_STAT;                    /*!< (@ 0x0000002C) I2C Interrupt Status Register.                             */
    __IOM uint32  INTR_MASK;                    /*!< (@ 0x00000030) I2C Interrupt Mask Register.                               */
    __IM  uint32  RAW_INTR_STAT;                /*!< (@ 0x00000034) I2C Raw Interrupt Status Register.                         */
    __IOM uint32  RX_TL;                        /*!< (@ 0x00000038) I2C Receive FIFO Threshold Register.                       */
    __IOM uint32  TX_TL;                        /*!< (@ 0x0000003C) I2C Transmit FIFO Threshold Register.                      */
    __IM  uint32  CLR_INTR;                     /*!< (@ 0x00000040) Clear Combined and Individual Interrupt Register.          */
    __IM  uint32  CLR_RX_UNDER;                 /*!< (@ 0x00000044) Clear RX_UNDER Interrupt Register.                         */
    __IM  uint32  CLR_RX_OVER;                  /*!< (@ 0x00000048) Clear RX_OVER Interrupt Register.                          */
    __IM  uint32  CLR_TX_OVER;                  /*!< (@ 0x0000004C) Clear TX_OVER Interrupt Register.                          */
    __IM  uint32  CLR_RD_REQ;                   /*!< (@ 0x00000050) Clear TX_OVER Interrupt Register.                          */
    __IM  uint32  CLR_TX_ABRT;                  /*!< (@ 0x00000054) Clear TX_ABRT Interrupt Register.                          */
    __IM  uint32  CLR_RX_DONE;                  /*!< (@ 0x00000058) Clear RX_DONE Interrupt Register.                          */
    __IM  uint32  CLR_ACTIVITY;                 /*!< (@ 0x0000005C) Clear ACTIVITY Interrupt Register.                         */
    __IM  uint32  CLR_STOP_DET;                 /*!< (@ 0x00000060) Clear STOP_DET Interrupt Register.                         */
    __IM  uint32  CLR_START_DET;                /*!< (@ 0x00000064) Clear START_DET Interrupt Register.                        */
    __IM  uint32  CLR_GEN_CALL;                 /*!< (@ 0x00000068) Clear GEN_CALL Interrupt Register.                         */
    __IOM uint32  ENABLE;                       /*!< (@ 0x0000006C) I2C Enable Register.                                       */
    __IM  uint32  STATUS;                       /*!< (@ 0x00000070) I2C Status Register.                                       */
    __IM  uint32  TXFLR;                        /*!< (@ 0x00000074) I2C Transmit FIFO Level Register.                          */
    __IM  uint32  RXFLR;                        /*!< (@ 0x00000078) I2C Receive FIFO Level Register.                           */
    __IOM uint32  SDA_HOLD;                     /*!< (@ 0x0000007C) I2C SDA Hold Time Length Register.                         */
    __IM  uint32  TX_ABRT_SOURCE;               /*!< (@ 0x00000080) I2C Transmit Abort Source Register.                        */
    __IOM uint32  SLV_DATA_NACK_ONLY;           /*!< (@ 0x00000084) Generate Slave Data NACK Register.                         */
    __IOM uint32  DMA_CR;                       /*!< (@ 0x00000088) DMA Control Register.                                      */
    __IOM uint32  DMA_TDLR;                     /*!< (@ 0x0000008C) DMA Transmit Data Level Register.                          */
    __IOM uint32  DMA_RDLR;                     /*!< (@ 0x00000090) I2C Receive Data Level Register.                           */
    __IOM uint32  SDA_SETUP;                    /*!< (@ 0x00000094) I2C SDA Setup Register.                                    */
    __IOM uint32  ACK_GENERAL_CALL;             /*!< (@ 0x00000098) I2C ACK General Call Register.                             */
    __IM  uint32  ENABLE_STATUS;                /*!< (@ 0x0000009C) I2C Enable Status Register.                                */
    __IOM uint32  FS_SPKLEN;                    /*!< (@ 0x000000A0) I2C SS and FS Spike Suppression Limit Register.            */
    __IOM uint32  HS_SPKLEN;                    /*!< (@ 0x000000A4) I2C HS Spike Suppression Limit Register.                   */
    __IM  uint32  CLR_RESTART_DET;              /*!< (@ 0x000000A8) Clear RESTART_DET Interrupt Register.  .                   */
    __IOM uint32  SCL_STUCK_AT_LOW_TIMEOUT;     /*!< (@ 0x000000AC) I2C SCL Stuck at Low Timeout.                              */
    __IOM  uint32 SDA_STUCK_AT_LOW_TIMEOUT;    /*!< (@ 0x000000B0) I2C SDA Stuck at Low Timeout. .  .                        */
    __IOM  uint32 CLR_SCL_STUCK_DET;           /*!< (@ 0x000000B4)Clear SCL Stuck at Low Detect Interrupt Register         */
    __IOM uint32  RESERVED[16];
    __IM  uint32  COMP_VERSION;                 /*!< (@ 0x000000F8) I2C Component Version Register.                            */
    __IM  uint32  COMP_TYPE;                    /*!< (@ 0x000000FC) I2C Component Type Register.                               */
} I2c_RegType, *I2c_RegMemMapPtr;                            /*!< Size = 4096 (0x1000)                                                      */

/** Number of instances of the I2C module. */
#define I2C_INSTANCE_COUNT                       (2u)

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C base address */
#define IP_I2C_BASE0                              (0x400A7000UL)
#define IP_I2C_BASE1                              (0x400A8000UL)

/** Peripheral I2C base pointer */
#define IP_I2C0                                   ((I2c_RegType *)IP_I2C_BASE0)
#define IP_I2C1                                   ((I2c_RegType *)IP_I2C_BASE1)

/** Array initializer of I2C peripheral base addresses */
#define IP_I2C_BASE_ADDRS                        { IP_I2C_BASE0, IP_I2C_BASE1 }

/** Array initializer of I2C peripheral base pointers */
#define IP_I2C_BASE_PTRS                         { IP_I2C0,  IP_I2C1}

/* =========================================================================================================================== */
/* ================                                        TT_I2C0                                        ================ */
/* =========================================================================================================================== */

/* ==========================================================  CON  ========================================================== */
#define TT_I2C0_CON_MASTER_Pos        (0UL)                     /*!< TT_I2C0 CON: MASTER (Bit 0)                       */
#define TT_I2C0_CON_MASTER_Msk        (0x1UL)                   /*!< TT_I2C0 CON: MASTER (Bitfield-Mask: 0x01)         */
#define TT_I2C0_CON_SPEED_Pos         (1UL)                     /*!< TT_I2C0 CON: SPEED (Bit 1)                        */
#define TT_I2C0_CON_SPEED_Msk         (0x6UL)                   /*!< TT_I2C0 CON: SPEED (Bitfield-Mask: 0x03)          */
#define TT_I2C0_CON_10BIT_ADDR_SLAVE_Pos (3UL)                  /*!< TT_I2C0 CON: 10BIT_ADDR_SLAVE (Bit 3)             */
#define TT_I2C0_CON_10BIT_ADDR_SLAVE_Msk (0x8UL)                /*!< TT_I2C0 CON: 10BIT_ADDR_SLAVE (Bitfield-Mask: 0x01) */
#define TT_I2C0_CON_10BIT_ADDR_MASTER_Pos (4UL)                 /*!< TT_I2C0 CON: 10BIT_ADDR_MASTER (Bit 4)            */
#define TT_I2C0_CON_10BIT_ADDR_MASTER_Msk (0x10UL)              /*!< TT_I2C0 CON: 10BIT_ADDR_MASTER (Bitfield-Mask: 0x01) */
#define TT_I2C0_CON_RESTART_EN_Pos    (5UL)                     /*!< TT_I2C0 CON: RESTART_EN (Bit 5)                   */
#define TT_I2C0_CON_RESTART_EN_Msk    (0x20UL)                  /*!< TT_I2C0 CON: RESTART_EN (Bitfield-Mask: 0x01)     */
#define TT_I2C0_CON_SLAVE_DISABLE_Pos (6UL)                     /*!< TT_I2C0 CON: SLAVE_DISABLE (Bit 6)                */
#define TT_I2C0_CON_SLAVE_DISABLE_Msk (0x40UL)                  /*!< TT_I2C0 CON: SLAVE_DISABLE (Bitfield-Mask: 0x01)  */
#define TT_I2C0_CON_STOP_DET_IFADDRESSED_Pos (7UL)                  /*!< TT_I2C0 CON: STOP_DET_IFADDRESSED (Bit 7)             */
#define TT_I2C0_CON_STOP_DET_IFADDRESSED_Msk (0x80UL)               /*!< TT_I2C0 CON: STOP_DET_IFADDRESSED (Bitfield-Mask: 0x01) */
#define TT_I2C0_CON_TX_EMPTY_CTRL_Pos     (8UL)                     /*!< TT_I2C0 CON: TX_EMPTY_CTRL (Bit 8)                    */
#define TT_I2C0_CON_TX_EMPTY_CTRL_Msk     (0x100UL)                 /*!< TT_I2C0 CON: TX_EMPTY_CTRL (Bitfield-Mask: 0x01)      */
#define TT_I2C0_CON_RX_FIFO_FULL_HLD_CTRL_Pos (9UL)                 /*!< TT_I2C0 CON: RX_FIFO_FULL_HLD_CTRL (Bit 9)            */
#define TT_I2C0_CON_RX_FIFO_FULL_HLD_CTRL_Msk (0x200UL)             /*!< TT_I2C0 CON: RX_FIFO_FULL_HLD_CTRL (Bitfield-Mask: 0x01) */
#define TT_I2C0_CON_STOP_DET_IF_MASTER_ACTIVE_Pos (10UL)            /*!< TT_I2C0 CON: STOP_DET_IF_MASTER_ACTIVE (Bit 10)       */
#define TT_I2C0_CON_STOP_DET_IF_MASTER_ACTIVE_Msk (0x400UL)         /*!< TT_I2C0 CON: STOP_DET_IF_MASTER_ACTIVE (Bitfield-Mask: 0x01) */
#define TT_I2C0_CON_BUS_CLEAR_FEATURE_CTRL_Pos (11UL)               /*!< TT_I2C0 CON: BUS_CLEAR_FEATURE_CTRL (Bit 11)          */
#define TT_I2C0_CON_BUS_CLEAR_FEATURE_CTRL_Msk (0x800UL)            /*!< TT_I2C0 CON: BUS_CLEAR_FEATURE_CTRL (Bitfield-Mask: 0x01) */
/* ==========================================================  TAR  ==========================================================*/
#define TT_I2C0_TAR_TAR_Pos           (0UL)                     /*!< TT_I2C0 TAR: TAR (Bit 0)                          */
#define TT_I2C0_TAR_TAR_Msk           (0x3ffUL)                 /*!< TT_I2C0 TAR: TAR (Bitfield-Mask: 0x3ff)           */
#define TT_I2C0_TAR_GC_OR_START_Pos   (10UL)                    /*!< TT_I2C0 TAR: GC_OR_START (Bit 10)                 */
#define TT_I2C0_TAR_GC_OR_START_Msk   (0x400UL)                 /*!< TT_I2C0 TAR: GC_OR_START (Bitfield-Mask: 0x01)    */
#define TT_I2C0_TAR_SPECIAL_Pos       (11UL)                    /*!< TT_I2C0 TAR: SPECIAL (Bit 11)                     */
#define TT_I2C0_TAR_SPECIAL_Msk       (0x800UL)                 /*!< TT_I2C0 TAR: SPECIAL (Bitfield-Mask: 0x01)        */
#define TT_I2C0_TAR_10BIT_ADDR_MASTER_Pos (12UL)                /*!< TT_I2C0 TAR: 10BIT_ADDR_MASTER (Bit 12)           */
#define TT_I2C0_TAR_10BIT_ADDR_MASTER_Msk (0x1000UL)            /*!< TT_I2C0 TAR: 10BIT_ADDR_MASTER (Bitfield-Mask: 0x01)*/
/* ==========================================================  SAR  ==========================================================*/
#define TT_I2C0_SAR_SAR_Pos           (0UL)                     /*!< TT_I2C0 SAR: SAR (Bit 0)                          */
#define TT_I2C0_SAR_SAR_Msk           (0x3ffUL)                 /*!< TT_I2C0 SAR: SAR (Bitfield-Mask: 0x3ff)           */
/* =======================================================  HS_MADDR  ======================================================== */
#define TT_I2C0_HS_MADDR_HS_MAR_Pos   (0UL)                     /*!< TT_I2C0 HS_MADDR: HS_MAR (Bit 0)                  */
#define TT_I2C0_HS_MADDR_HS_MAR_Msk   (0x7UL)                   /*!< TT_I2C0 HS_MADDR: HS_MAR (Bitfield-Mask: 0x07)    */
/* =======================================================  DATA_CMD  ======================================================== */
#define TT_I2C0_DATA_CMD_DAT_Pos      (0UL)                     /*!< TT_I2C0 DATA_CMD: DAT (Bit 0)                     */
#define TT_I2C0_DATA_CMD_DAT_Msk      (0xffUL)                  /*!< TT_I2C0 DATA_CMD: DAT (Bitfield-Mask: 0xff)       */
#define TT_I2C0_DATA_CMD_CMD_Pos      (8UL)                     /*!< TT_I2C0 DATA_CMD: CMD (Bit 8)                     */
#define TT_I2C0_DATA_CMD_CMD_Msk      (0x100UL)                 /*!< TT_I2C0 DATA_CMD: CMD (Bitfield-Mask: 0x01)       */
#define TT_I2C0_DATA_CMD_STOP_Pos     (9UL)                     /*!< TT_I2C0 DATA_CMD: STOP (Bit 9)                    */
#define TT_I2C0_DATA_CMD_STOP_Msk     (0x200UL)                 /*!< TT_I2C0 DATA_CMD: STOP (Bitfield-Mask: 0x01)      */
#define TT_I2C0_DATA_CMD_RESTART_Pos  (10UL)                    /*!< TT_I2C0 DATA_CMD: RESTART (Bit 10)                */
#define TT_I2C0_DATA_CMD_RESTART_Msk  (0x400UL)                 /*!< TT_I2C0 DATA_CMD: RESTART (Bitfield-Mask: 0x01)   */
/* ======================================================  SS_SCL_HCNT  ====================================================== */
#define TT_I2C0_SS_SCL_HCNT_SS_SCL_HCNT_Pos (0UL)               /*!< TT_I2C0 SS_SCL_HCNT: SS_SCL_HCNT (Bit 0)          */
#define TT_I2C0_SS_SCL_HCNT_SS_SCL_HCNT_Msk (0xffffUL)          /*!< TT_I2C0 SS_SCL_HCNT: SS_SCL_HCNT (Bitfield-Mask: 0xffff) */
/* ======================================================  SS_SCL_LCNT  ====================================================== */
#define TT_I2C0_SS_SCL_LCNT_SS_SCL_LCNT_Pos (0UL)               /*!< TT_I2C0 SS_SCL_LCNT: SS_SCL_LCNT (Bit 0)          */
#define TT_I2C0_SS_SCL_LCNT_SS_SCL_LCNT_Msk (0xffffUL)          /*!< TT_I2C0 SS_SCL_LCNT: SS_SCL_LCNT (Bitfield-Mask: 0xffff) */
/* ======================================================  FS_SCL_HCNT  ====================================================== */
#define TT_I2C0_FS_SCL_HCNT_FS_SCL_HCNT_Pos (0UL)               /*!< TT_I2C0 FS_SCL_HCNT: FS_SCL_HCNT (Bit 0)          */
#define TT_I2C0_FS_SCL_HCNT_FS_SCL_HCNT_Msk (0xffffUL)          /*!< TT_I2C0 FS_SCL_HCNT: FS_SCL_HCNT (Bitfield-Mask: 0xffff) */
/* ======================================================  FS_SCL_LCNT  ====================================================== */
#define TT_I2C0_FS_SCL_LCNT_FS_SCL_LCNT_Pos (0UL)               /*!< TT_I2C0 FS_SCL_LCNT: FS_SCL_LCNT (Bit 0)          */
#define TT_I2C0_FS_SCL_LCNT_FS_SCL_LCNT_Msk (0xffffUL)          /*!< TT_I2C0 FS_SCL_LCNT: FS_SCL_LCNT (Bitfield-Mask: 0xffff) */
/* ======================================================  HS_SCL_HCNT  ====================================================== */
#define TT_I2C0_HS_SCL_HCNT_HS_SCL_HCNT_Pos (0UL)               /*!< TT_I2C0 HS_SCL_HCNT: HS_SCL_HCNT (Bit 0)          */
#define TT_I2C0_HS_SCL_HCNT_HS_SCL_HCNT_Msk (0xffffUL)          /*!< TT_I2C0 HS_SCL_HCNT: HS_SCL_HCNT (Bitfield-Mask: 0xffff) */
/* ======================================================  HS_SCL_LCNT  ====================================================== */
#define TT_I2C0_HS_SCL_LCNT_HS_SCL_LCNT_Pos (0UL)               /*!< TT_I2C0 HS_SCL_LCNT: HS_SCL_LCNT (Bit 0)          */
#define TT_I2C0_HS_SCL_LCNT_HS_SCL_LCNT_Msk (0xffffUL)          /*!< TT_I2C0 HS_SCL_LCNT: HS_SCL_LCNT (Bitfield-Mask: 0xffff) */
/* =======================================================  INTR_STAT  ======================================================= */
#define TT_I2C0_INTR_STAT_R_RX_UNDER_Pos (0UL)                  /*!< TT_I2C0 INTR_STAT: R_RX_UNDER (Bit 0)             */
#define TT_I2C0_INTR_STAT_R_RX_UNDER_Msk (0x1UL)                /*!< TT_I2C0 INTR_STAT: R_RX_UNDER (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_RX_OVER_Pos (1UL)                   /*!< TT_I2C0 INTR_STAT: R_RX_OVER (Bit 1)              */
#define TT_I2C0_INTR_STAT_R_RX_OVER_Msk (0x2UL)                 /*!< TT_I2C0 INTR_STAT: R_RX_OVER (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_RX_FULL_Pos (2UL)                   /*!< TT_I2C0 INTR_STAT: R_RX_FULL (Bit 2)              */
#define TT_I2C0_INTR_STAT_R_RX_FULL_Msk (0x4UL)                 /*!< TT_I2C0 INTR_STAT: R_RX_FULL (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_TX_OVER_Pos (3UL)                   /*!< TT_I2C0 INTR_STAT: R_TX_OVER (Bit 3)              */
#define TT_I2C0_INTR_STAT_R_TX_OVER_Msk (0x8UL)                 /*!< TT_I2C0 INTR_STAT: R_TX_OVER (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_TX_EMPTY_Pos (4UL)                  /*!< TT_I2C0 INTR_STAT: R_TX_EMPTY (Bit 4)             */
#define TT_I2C0_INTR_STAT_R_TX_EMPTY_Msk (0x10UL)               /*!< TT_I2C0 INTR_STAT: R_TX_EMPTY (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_RD_REQ_Pos (5UL)                    /*!< TT_I2C0 INTR_STAT: R_RD_REQ (Bit 5)               */
#define TT_I2C0_INTR_STAT_R_RD_REQ_Msk (0x20UL)                 /*!< TT_I2C0 INTR_STAT: R_RD_REQ (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_TX_ABRT_Pos (6UL)                   /*!< TT_I2C0 INTR_STAT: R_TX_ABRT (Bit 6)              */
#define TT_I2C0_INTR_STAT_R_TX_ABRT_Msk (0x40UL)                /*!< TT_I2C0 INTR_STAT: R_TX_ABRT (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_RX_DONE_Pos (7UL)                   /*!< TT_I2C0 INTR_STAT: R_RX_DONE (Bit 7)              */
#define TT_I2C0_INTR_STAT_R_RX_DONE_Msk (0x80UL)                /*!< TT_I2C0 INTR_STAT: R_RX_DONE (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_ACTIVITY_Pos (8UL)                  /*!< TT_I2C0 INTR_STAT: R_ACTIVITY (Bit 8)             */
#define TT_I2C0_INTR_STAT_R_ACTIVITY_Msk (0x100UL)              /*!< TT_I2C0 INTR_STAT: R_ACTIVITY (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_STOP_DET_Pos (9UL)                  /*!< TT_I2C0 INTR_STAT: R_STOP_DET (Bit 9)             */
#define TT_I2C0_INTR_STAT_R_STOP_DET_Msk (0x200UL)              /*!< TT_I2C0 INTR_STAT: R_STOP_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_START_DET_Pos (10UL)                /*!< TT_I2C0 INTR_STAT: R_START_DET (Bit 10)           */
#define TT_I2C0_INTR_STAT_R_START_DET_Msk (0x400UL)             /*!< TT_I2C0 INTR_STAT: R_START_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_GEN_CALL_Pos (11UL)                 /*!< TT_I2C0 INTR_STAT: R_GEN_CALL (Bit 11)            */
#define TT_I2C0_INTR_STAT_R_GEN_CALL_Msk (0x800UL)              /*!< TT_I2C0 INTR_STAT: R_GEN_CALL (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_RESTART_DET_Pos (12UL)                  /*!< TT_I2C0 INTR_STAT: R_RESTART_DET (Bit 12)             */
#define TT_I2C0_INTR_STAT_R_RESTART_DET_Msk (0x1000UL)              /*!< TT_I2C0 INTR_STAT: R_RESTART_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_MASTER_ON_HOLD_Pos (13UL)               /*!< TT_I2C0 INTR_STAT: R_MASTER_ON_HOLD (Bit 13)          */
#define TT_I2C0_INTR_STAT_R_MASTER_ON_HOLD_Msk (0x2000UL)           /*!< TT_I2C0 INTR_STAT: R_MASTER_ON_HOLD (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_SCL_STUCK_AT_LOW_Pos (14UL)             /*!< TT_I2C0 INTR_STAT: R_SCL_STUCK_AT_LOW (Bit 14)        */
#define TT_I2C0_INTR_STAT_R_SCL_STUCK_AT_LOW_Msk (0x4000UL)         /*!< TT_I2C0 INTR_STAT: R_SCL_STUCK_AT_LOW (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_WR_REQ_Pos    (15UL)                    /*!< TT_I2C0 INTR_STAT: R_WR_REQ (Bit 15)                  */
#define TT_I2C0_INTR_STAT_R_WR_REQ_Msk    (0x8000UL)                /*!< TT_I2C0 INTR_STAT: R_WR_REQ (Bitfield-Mask: 0x01)     */
#define TT_I2C0_INTR_STAT_R_SLV_ADDR1_TAG_Pos (16UL)                /*!< TT_I2C0 INTR_STAT: R_SLV_ADDR1_TAG (Bit 16)           */
#define TT_I2C0_INTR_STAT_R_SLV_ADDR1_TAG_Msk (0x10000UL)           /*!< TT_I2C0 INTR_STAT: R_SLV_ADDR1_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_SLV_ADDR2_TAG_Pos (17UL)                /*!< TT_I2C0 INTR_STAT: R_SLV_ADDR2_TAG (Bit 17)           */
#define TT_I2C0_INTR_STAT_R_SLV_ADDR2_TAG_Msk (0x20000UL)           /*!< TT_I2C0 INTR_STAT: R_SLV_ADDR2_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_SLV_ADDR3_TAG_Pos (18UL)                /*!< TT_I2C0 INTR_STAT: R_SLV_ADDR3_TAG (Bit 18)           */
#define TT_I2C0_INTR_STAT_R_SLV_ADDR3_TAG_Msk (0x40000UL)           /*!< TT_I2C0 INTR_STAT: R_SLV_ADDR3_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_STAT_R_SLV_ADDR4_TAG_Pos (19UL)                /*!< TT_I2C0 INTR_STAT: R_SLV_ADDR4_TAG (Bit 19)           */
#define TT_I2C0_INTR_STAT_R_SLV_ADDR4_TAG_Msk (0x80000UL)           /*!< TT_I2C0 INTR_STAT: R_SLV_ADDR4_TAG (Bitfield-Mask: 0x01) */
/* =======================================================  INTR_MASK  ======================================================= */
#define TT_I2C0_INTR_MASK_M_RX_UNDER_Pos (0UL)                  /*!< TT_I2C0 INTR_MASK: M_RX_UNDER (Bit 0)             */
#define TT_I2C0_INTR_MASK_M_RX_UNDER_Msk (0x1UL)                /*!< TT_I2C0 INTR_MASK: M_RX_UNDER (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_RX_OVER_Pos (1UL)                   /*!< TT_I2C0 INTR_MASK: M_RX_OVER (Bit 1)              */
#define TT_I2C0_INTR_MASK_M_RX_OVER_Msk (0x2UL)                 /*!< TT_I2C0 INTR_MASK: M_RX_OVER (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_RX_FULL_Pos (2UL)                   /*!< TT_I2C0 INTR_MASK: M_RX_FULL (Bit 2)              */
#define TT_I2C0_INTR_MASK_M_RX_FULL_Msk (0x4UL)                 /*!< TT_I2C0 INTR_MASK: M_RX_FULL (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_TX_OVER_Pos (3UL)                   /*!< TT_I2C0 INTR_MASK: M_TX_OVER (Bit 3)              */
#define TT_I2C0_INTR_MASK_M_TX_OVER_Msk (0x8UL)                 /*!< TT_I2C0 INTR_MASK: M_TX_OVER (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_TX_EMPTY_Pos (4UL)                  /*!< TT_I2C0 INTR_MASK: M_TX_EMPTY (Bit 4)             */
#define TT_I2C0_INTR_MASK_M_TX_EMPTY_Msk (0x10UL)               /*!< TT_I2C0 INTR_MASK: M_TX_EMPTY (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_RD_REQ_Pos (5UL)                    /*!< TT_I2C0 INTR_MASK: M_RD_REQ (Bit 5)               */
#define TT_I2C0_INTR_MASK_M_RD_REQ_Msk (0x20UL)                 /*!< TT_I2C0 INTR_MASK: M_RD_REQ (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_TX_ABRT_Pos (6UL)                   /*!< TT_I2C0 INTR_MASK: M_TX_ABRT (Bit 6)              */
#define TT_I2C0_INTR_MASK_M_TX_ABRT_Msk (0x40UL)                /*!< TT_I2C0 INTR_MASK: M_TX_ABRT (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_RX_DONE_Pos (7UL)                   /*!< TT_I2C0 INTR_MASK: M_RX_DONE (Bit 7)              */
#define TT_I2C0_INTR_MASK_M_RX_DONE_Msk (0x80UL)                /*!< TT_I2C0 INTR_MASK: M_RX_DONE (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_ACTIVITY_Pos (8UL)                  /*!< TT_I2C0 INTR_MASK: M_ACTIVITY (Bit 8)             */
#define TT_I2C0_INTR_MASK_M_ACTIVITY_Msk (0x100UL)              /*!< TT_I2C0 INTR_MASK: M_ACTIVITY (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_STOP_DET_Pos (9UL)                  /*!< TT_I2C0 INTR_MASK: M_STOP_DET (Bit 9)             */
#define TT_I2C0_INTR_MASK_M_STOP_DET_Msk (0x200UL)              /*!< TT_I2C0 INTR_MASK: M_STOP_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_START_DET_Pos (10UL)                /*!< TT_I2C0 INTR_MASK: M_START_DET (Bit 10)           */
#define TT_I2C0_INTR_MASK_M_START_DET_Msk (0x400UL)             /*!< TT_I2C0 INTR_MASK: M_START_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_GEN_CALL_Pos (11UL)                 /*!< TT_I2C0 INTR_MASK: M_GEN_CALL (Bit 11)            */
#define TT_I2C0_INTR_MASK_M_GEN_CALL_Msk (0x800UL)              /*!< TT_I2C0 INTR_MASK: M_GEN_CALL (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_RESTART_DET_Pos (12UL)                  /*!< TT_I2C0 INTR_MASK: M_RESTART_DET (Bit 12)             */
#define TT_I2C0_INTR_MASK_M_RESTART_DET_Msk (0x1000UL)              /*!< TT_I2C0 INTR_MASK: M_RESTART_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_MASTER_ON_HOLD_Pos (13UL)               /*!< TT_I2C0 INTR_MASK: M_MASTER_ON_HOLD (Bit 13)          */
#define TT_I2C0_INTR_MASK_M_MASTER_ON_HOLD_Msk (0x2000UL)           /*!< TT_I2C0 INTR_MASK: M_MASTER_ON_HOLD (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_SCL_STUCK_AT_LOW_Pos (14UL)             /*!< TT_I2C0 INTR_MASK: M_SCL_STUCK_AT_LOW (Bit 14)        */
#define TT_I2C0_INTR_MASK_M_SCL_STUCK_AT_LOW_Msk (0x4000UL)         /*!< TT_I2C0 INTR_MASK: M_SCL_STUCK_AT_LOW (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_WR_REQ_Pos    (15UL)                    /*!< TT_I2C0 INTR_MASK: M_WR_REQ (Bit 15)                  */
#define TT_I2C0_INTR_MASK_M_WR_REQ_Msk    (0x8000UL)                /*!< TT_I2C0 INTR_MASK: M_WR_REQ (Bitfield-Mask: 0x01)     */
#define TT_I2C0_INTR_MASK_M_SLV_ADDR1_TAG_Pos (16UL)                /*!< TT_I2C0 INTR_MASK: M_SLV_ADDR1_TAG (Bit 16)           */
#define TT_I2C0_INTR_MASK_M_SLV_ADDR1_TAG_Msk (0x10000UL)           /*!< TT_I2C0 INTR_MASK: M_SLV_ADDR1_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_SLV_ADDR2_TAG_Pos (17UL)                /*!< TT_I2C0 INTR_MASK: M_SLV_ADDR2_TAG (Bit 17)           */
#define TT_I2C0_INTR_MASK_M_SLV_ADDR2_TAG_Msk (0x20000UL)           /*!< TT_I2C0 INTR_MASK: M_SLV_ADDR2_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_SLV_ADDR3_TAG_Pos (18UL)                /*!< TT_I2C0 INTR_MASK: M_SLV_ADDR3_TAG (Bit 18)           */
#define TT_I2C0_INTR_MASK_M_SLV_ADDR3_TAG_Msk (0x40000UL)           /*!< TT_I2C0 INTR_MASK: M_SLV_ADDR3_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_INTR_MASK_M_SLV_ADDR4_TAG_Pos (19UL)                /*!< TT_I2C0 INTR_MASK: M_SLV_ADDR4_TAG (Bit 19)           */
#define TT_I2C0_INTR_MASK_M_SLV_ADDR4_TAG_Msk (0x80000UL)           /*!< TT_I2C0 INTR_MASK: M_SLV_ADDR4_TAG (Bitfield-Mask: 0x01) */
/* =====================================================  RAW_INTR_STAT  ===================================================== */
#define TT_I2C0_RAW_INTR_STAT_RX_UNDER_Pos (0UL)                /*!< TT_I2C0 RAW_INTR_STAT: RX_UNDER (Bit 0)           */
#define TT_I2C0_RAW_INTR_STAT_RX_UNDER_Msk (0x1UL)              /*!< TT_I2C0 RAW_INTR_STAT: RX_UNDER (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_RX_OVER_Pos (1UL)                 /*!< TT_I2C0 RAW_INTR_STAT: RX_OVER (Bit 1)            */
#define TT_I2C0_RAW_INTR_STAT_RX_OVER_Msk (0x2UL)               /*!< TT_I2C0 RAW_INTR_STAT: RX_OVER (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_RX_FULL_Pos (2UL)                 /*!< TT_I2C0 RAW_INTR_STAT: RX_FULL (Bit 2)            */
#define TT_I2C0_RAW_INTR_STAT_RX_FULL_Msk (0x4UL)               /*!< TT_I2C0 RAW_INTR_STAT: RX_FULL (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_TX_OVER_Pos (3UL)                 /*!< TT_I2C0 RAW_INTR_STAT: TX_OVER (Bit 3)            */
#define TT_I2C0_RAW_INTR_STAT_TX_OVER_Msk (0x8UL)               /*!< TT_I2C0 RAW_INTR_STAT: TX_OVER (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_TX_EMPTY_Pos (4UL)                /*!< TT_I2C0 RAW_INTR_STAT: TX_EMPTY (Bit 4)           */
#define TT_I2C0_RAW_INTR_STAT_TX_EMPTY_Msk (0x10UL)             /*!< TT_I2C0 RAW_INTR_STAT: TX_EMPTY (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_RD_REQ_Pos (5UL)                  /*!< TT_I2C0 RAW_INTR_STAT: RD_REQ (Bit 5)             */
#define TT_I2C0_RAW_INTR_STAT_RD_REQ_Msk (0x20UL)               /*!< TT_I2C0 RAW_INTR_STAT: RD_REQ (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_TX_ABRT_Pos (6UL)                 /*!< TT_I2C0 RAW_INTR_STAT: TX_ABRT (Bit 6)            */
#define TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk (0x40UL)              /*!< TT_I2C0 RAW_INTR_STAT: TX_ABRT (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_RX_DONE_Pos (7UL)                 /*!< TT_I2C0 RAW_INTR_STAT: RX_DONE (Bit 7)            */
#define TT_I2C0_RAW_INTR_STAT_RX_DONE_Msk (0x80UL)              /*!< TT_I2C0 RAW_INTR_STAT: RX_DONE (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_ACTIVITY_Pos (8UL)                /*!< TT_I2C0 RAW_INTR_STAT: ACTIVITY (Bit 8)           */
#define TT_I2C0_RAW_INTR_STAT_ACTIVITY_Msk (0x100UL)            /*!< TT_I2C0 RAW_INTR_STAT: ACTIVITY (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_STOP_DET_Pos (9UL)                /*!< TT_I2C0 RAW_INTR_STAT: STOP_DET (Bit 9)           */
#define TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk (0x200UL)            /*!< TT_I2C0 RAW_INTR_STAT: STOP_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_START_DET_Pos (10UL)              /*!< TT_I2C0 RAW_INTR_STAT: START_DET (Bit 10)         */
#define TT_I2C0_RAW_INTR_STAT_START_DET_Msk (0x400UL)           /*!< TT_I2C0 RAW_INTR_STAT: START_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_GEN_CALL_Pos (11UL)               /*!< TT_I2C0 RAW_INTR_STAT: GEN_CALL (Bit 11)          */
#define TT_I2C0_RAW_INTR_STAT_GEN_CALL_Msk (0x800UL)            /*!< TT_I2C0 RAW_INTR_STAT: GEN_CALL (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_RESTART_DET_Pos (12UL)                /*!< TT_I2C0 RAW_INTR_STAT: RESTART_DET (Bit 12)           */
#define TT_I2C0_RAW_INTR_STAT_RESTART_DET_Msk (0x1000UL)            /*!< TT_I2C0 RAW_INTR_STAT: RESTART_DET (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_MASTER_ON_HOLD_Pos (13UL)             /*!< TT_I2C0 RAW_INTR_STAT: MASTER_ON_HOLD (Bit 13)        */
#define TT_I2C0_RAW_INTR_STAT_MASTER_ON_HOLD_Msk (0x2000UL)         /*!< TT_I2C0 RAW_INTR_STAT: MASTER_ON_HOLD (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Pos (14UL)           /*!< TT_I2C0 RAW_INTR_STAT: SCL_STUCK_AT_LOW (Bit 14)      */
#define TT_I2C0_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Msk (0x4000UL)       /*!< TT_I2C0 RAW_INTR_STAT: SCL_STUCK_AT_LOW (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_WR_REQ_Pos  (15UL)                    /*!< TT_I2C0 RAW_INTR_STAT: WR_REQ (Bit 15)                */
#define TT_I2C0_RAW_INTR_STAT_WR_REQ_Msk  (0x8000UL)                /*!< TT_I2C0 RAW_INTR_STAT: WR_REQ (Bitfield-Mask: 0x01)   */
#define TT_I2C0_RAW_INTR_STAT_SLV_ADDR1_TAG_Pos (16UL)              /*!< TT_I2C0 RAW_INTR_STAT: SLV_ADDR1_TAG (Bit 16)         */
#define TT_I2C0_RAW_INTR_STAT_SLV_ADDR1_TAG_Msk (0x10000UL)         /*!< TT_I2C0 RAW_INTR_STAT: SLV_ADDR1_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_SLV_ADDR2_TAG_Pos (17UL)              /*!< TT_I2C0 RAW_INTR_STAT: SLV_ADDR2_TAG (Bit 17)         */
#define TT_I2C0_RAW_INTR_STAT_SLV_ADDR2_TAG_Msk (0x20000UL)         /*!< TT_I2C0 RAW_INTR_STAT: SLV_ADDR2_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_SLV_ADDR3_TAG_Pos (18UL)              /*!< TT_I2C0 RAW_INTR_STAT: SLV_ADDR3_TAG (Bit 18)         */
#define TT_I2C0_RAW_INTR_STAT_SLV_ADDR3_TAG_Msk (0x40000UL)         /*!< TT_I2C0 RAW_INTR_STAT: SLV_ADDR3_TAG (Bitfield-Mask: 0x01) */
#define TT_I2C0_RAW_INTR_STAT_SLV_ADDR4_TAG_Pos (19UL)              /*!< TT_I2C0 RAW_INTR_STAT: SLV_ADDR4_TAG (Bit 19)         */
#define TT_I2C0_RAW_INTR_STAT_SLV_ADDR4_TAG_Msk (0x80000UL)         /*!< TT_I2C0 RAW_INTR_STAT: SLV_ADDR4_TAG (Bitfield-Mask: 0x01) */
/* =========================================================  RX_TL  ========================================================= */
#define TT_I2C0_RX_TL_RX_TL_Pos       (0UL)                     /*!< TT_I2C0 RX_TL: RX_TL (Bit 0)                      */
#define TT_I2C0_RX_TL_RX_TL_Msk       (0xffUL)                  /*!< TT_I2C0 RX_TL: RX_TL (Bitfield-Mask: 0xff)        */
/* =========================================================  TX_TL  ========================================================= */
#define TT_I2C0_TX_TL_TX_TL_Pos       (0UL)                     /*!< TT_I2C0 TX_TL: TX_TL (Bit 0)                      */
#define TT_I2C0_TX_TL_TX_TL_Msk       (0xffUL)                  /*!< TT_I2C0 TX_TL: TX_TL (Bitfield-Mask: 0xff)        */
/* =======================================================  CLR_INTR  ======================================================== */
#define TT_I2C0_CLR_INTR_TX_TL_Pos    (0UL)                     /*!< TT_I2C0 CLR_INTR: TX_TL (Bit 0)                   */
#define TT_I2C0_CLR_INTR_TX_TL_Msk    (0x1UL)                   /*!< TT_I2C0 CLR_INTR: TX_TL (Bitfield-Mask: 0x01)     */
/* =====================================================  CLR_RX_UNDER  ====================================================== */
#define TT_I2C0_CLR_RX_UNDER_CLR_RX_UNDER_Pos (0UL)             /*!< TT_I2C0 CLR_RX_UNDER: CLR_RX_UNDER (Bit 0)        */
#define TT_I2C0_CLR_RX_UNDER_CLR_RX_UNDER_Msk (0x1UL)           /*!< TT_I2C0 CLR_RX_UNDER: CLR_RX_UNDER (Bitfield-Mask: 0x01) */
/* ======================================================  CLR_RX_OVER  ====================================================== */
#define TT_I2C0_CLR_RX_OVER_CLR_RX_OVER_Pos (0UL)               /*!< TT_I2C0 CLR_RX_OVER: CLR_RX_OVER (Bit 0)          */
#define TT_I2C0_CLR_RX_OVER_CLR_RX_OVER_Msk (0x1UL)             /*!< TT_I2C0 CLR_RX_OVER: CLR_RX_OVER (Bitfield-Mask: 0x01) */
/* ======================================================  CLR_TX_OVER  ====================================================== */
#define TT_I2C0_CLR_TX_OVER_CLR_TX_OVER_Pos (0UL)               /*!< TT_I2C0 CLR_TX_OVER: CLR_TX_OVER (Bit 0)          */
#define TT_I2C0_CLR_TX_OVER_CLR_TX_OVER_Msk (0x1UL)             /*!< TT_I2C0 CLR_TX_OVER: CLR_TX_OVER (Bitfield-Mask: 0x01) */
/* ======================================================  CLR_RD_REQ  ======================================================= */
#define TT_I2C0_CLR_RD_REQ_CLR_RD_REQ_Pos (0UL)                 /*!< TT_I2C0 CLR_RD_REQ: CLR_RD_REQ (Bit 0)            */
#define TT_I2C0_CLR_RD_REQ_CLR_RD_REQ_Msk (0x1UL)               /*!< TT_I2C0 CLR_RD_REQ: CLR_RD_REQ (Bitfield-Mask: 0x01) */
/* ======================================================  CLR_TX_ABRT  ====================================================== */
#define TT_I2C0_CLR_TX_ABRT_CLR_TX_ABRT_Pos (0UL)               /*!< TT_I2C0 CLR_TX_ABRT: CLR_TX_ABRT (Bit 0)          */
#define TT_I2C0_CLR_TX_ABRT_CLR_TX_ABRT_Msk (0x1UL)             /*!< TT_I2C0 CLR_TX_ABRT: CLR_TX_ABRT (Bitfield-Mask: 0x01) */
/* ======================================================  CLR_RX_DONE  ====================================================== */
#define TT_I2C0_CLR_RX_DONE_CLR_RX_DONE_Pos (0UL)               /*!< TT_I2C0 CLR_RX_DONE: CLR_RX_DONE (Bit 0)          */
#define TT_I2C0_CLR_RX_DONE_CLR_RX_DONE_Msk (0x1UL)             /*!< TT_I2C0 CLR_RX_DONE: CLR_RX_DONE (Bitfield-Mask: 0x01) */
/* =====================================================  CLR_ACTIVITY  ====================================================== */
#define TT_I2C0_CLR_ACTIVITY_CLR_ACTIVITY_Pos (0UL)             /*!< TT_I2C0 CLR_ACTIVITY: CLR_ACTIVITY (Bit 0)        */
#define TT_I2C0_CLR_ACTIVITY_CLR_ACTIVITY_Msk (0x1UL)           /*!< TT_I2C0 CLR_ACTIVITY: CLR_ACTIVITY (Bitfield-Mask: 0x01) */
/* =====================================================  CLR_STOP_DET  ====================================================== */
#define TT_I2C0_CLR_STOP_DET_CLR_STOP_DET_Pos (0UL)             /*!< TT_I2C0 CLR_STOP_DET: CLR_STOP_DET (Bit 0)        */
#define TT_I2C0_CLR_STOP_DET_CLR_STOP_DET_Msk (0x1UL)           /*!< TT_I2C0 CLR_STOP_DET: CLR_STOP_DET (Bitfield-Mask: 0x01) */
/* =====================================================  CLR_START_DET  ===================================================== */
#define TT_I2C0_CLR_START_DET_CLR_START_DET_Pos (0UL)           /*!< TT_I2C0 CLR_START_DET: CLR_START_DET (Bit 0)      */
#define TT_I2C0_CLR_START_DET_CLR_START_DET_Msk (0x1UL)         /*!< TT_I2C0 CLR_START_DET: CLR_START_DET (Bitfield-Mask: 0x01) */
/* =====================================================  CLR_GEN_CALL  ====================================================== */
#define TT_I2C0_CLR_GEN_CALL_CLR_GEN_CALL_Pos (0UL)             /*!< TT_I2C0 CLR_GEN_CALL: CLR_GEN_CALL (Bit 0)        */
#define TT_I2C0_CLR_GEN_CALL_CLR_GEN_CALL_Msk (0x1UL)           /*!< TT_I2C0 CLR_GEN_CALL: CLR_GEN_CALL (Bitfield-Mask: 0x01) */
/* ========================================================  ENABLE  ========================================================= */
#define TT_I2C0_ENABLE_ENABLE_Pos     (0UL)                     /*!< TT_I2C0 ENABLE: ENABLE (Bit 0)                    */
#define TT_I2C0_ENABLE_ENABLE_Msk     (0x1UL)                   /*!< TT_I2C0 ENABLE: ENABLE (Bitfield-Mask: 0x01)      */
#define TT_I2C0_ENABLE_ABORT_Pos          (1UL)                     /*!< TT_I2C0 ENABLE: ABORT (Bit 1)                         */
#define TT_I2C0_ENABLE_ABORT_Msk          (0x2UL)                   /*!< TT_I2C0 ENABLE: ABORT (Bitfield-Mask: 0x01)           */
#define TT_I2C0_ENABLE_TX_CMD_BLOCK_Pos   (2UL)                     /*!< TT_I2C0 ENABLE: TX_CMD_BLOCK (Bit 2)                  */
#define TT_I2C0_ENABLE_TX_CMD_BLOCK_Msk   (0x4UL)                   /*!< TT_I2C0 ENABLE: TX_CMD_BLOCK (Bitfield-Mask: 0x01)    */
#define TT_I2C0_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Pos (3UL)          /*!< TT_I2C0 ENABLE: SDA_STUCK_RECOVERY_ENABLE (Bit 3)     */
#define TT_I2C0_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Msk (0x8UL)        /*!< TT_I2C0 ENABLE: SDA_STUCK_RECOVERY_ENABLE (Bitfield-Mask: 0x01) */
#define TT_I2C0_ENABLE_RSVD_IC_ENABLE_1_Pos (4UL)                   /*!< TT_I2C0 ENABLE: RSVD_IC_ENABLE_1 (Bit 4)              */
#define TT_I2C0_ENABLE_RSVD_IC_ENABLE_1_Msk (0xfff0UL)              /*!< TT_I2C0 ENABLE: RSVD_IC_ENABLE_1 (Bitfield-Mask: 0xfff) */
/* ========================================================  STATUS  ========================================================= */
#define TT_I2C0_STATUS_ACTIVITY_Pos   (0UL)                     /*!< TT_I2C0 STATUS: ACTIVITY (Bit 0)                  */
#define TT_I2C0_STATUS_ACTIVITY_Msk   (0x1UL)                   /*!< TT_I2C0 STATUS: ACTIVITY (Bitfield-Mask: 0x01)    */
#define TT_I2C0_STATUS_TFNF_Pos       (1UL)                     /*!< TT_I2C0 STATUS: TFNF (Bit 1)                      */
#define TT_I2C0_STATUS_TFNF_Msk       (0x2UL)                   /*!< TT_I2C0 STATUS: TFNF (Bitfield-Mask: 0x01)        */
#define TT_I2C0_STATUS_TFE_Pos        (2UL)                     /*!< TT_I2C0 STATUS: TFE (Bit 2)                       */
#define TT_I2C0_STATUS_TFE_Msk        (0x4UL)                   /*!< TT_I2C0 STATUS: TFE (Bitfield-Mask: 0x01)         */
#define TT_I2C0_STATUS_RFNE_Pos       (3UL)                     /*!< TT_I2C0 STATUS: RFNE (Bit 3)                      */
#define TT_I2C0_STATUS_RFNE_Msk       (0x8UL)                   /*!< TT_I2C0 STATUS: RFNE (Bitfield-Mask: 0x01)        */
#define TT_I2C0_STATUS_RFF_Pos        (4UL)                     /*!< TT_I2C0 STATUS: RFF (Bit 4)                       */
#define TT_I2C0_STATUS_RFF_Msk        (0x10UL)                  /*!< TT_I2C0 STATUS: RFF (Bitfield-Mask: 0x01)         */
#define TT_I2C0_STATUS_MST_ACTIVITY_Pos (5UL)                   /*!< TT_I2C0 STATUS: MST_ACTIVITY (Bit 5)              */
#define TT_I2C0_STATUS_MST_ACTIVITY_Msk (0x20UL)                /*!< TT_I2C0 STATUS: MST_ACTIVITY (Bitfield-Mask: 0x01) */
#define TT_I2C0_STATUS_SLV_ACTIVITY_Pos (6UL)                   /*!< TT_I2C0 STATUS: SLV_ACTIVITY (Bit 6)              */
#define TT_I2C0_STATUS_SLV_ACTIVITY_Msk (0x40UL)                /*!< TT_I2C0 STATUS: SLV_ACTIVITY (Bitfield-Mask: 0x01) */
#define TT_I2C0_STATUS_MST_HOLD_TX_FIFO_EMPTY_Pos (7UL)             /*!< TT_I2C0 STATUS: MST_HOLD_TX_FIFO_EMPTY (Bit 7)        */
#define TT_I2C0_STATUS_MST_HOLD_TX_FIFO_EMPTY_Msk (0x80UL)          /*!< TT_I2C0 STATUS: MST_HOLD_TX_FIFO_EMPTY (Bitfield-Mask: 0x01) */
#define TT_I2C0_STATUS_MST_HOLD_RX_FIFO_FULL_Pos (8UL)              /*!< TT_I2C0 STATUS: MST_HOLD_RX_FIFO_FULL (Bit 8)         */
#define TT_I2C0_STATUS_MST_HOLD_RX_FIFO_FULL_Msk (0x100UL)          /*!< TT_I2C0 STATUS: MST_HOLD_RX_FIFO_FULL (Bitfield-Mask: 0x01) */
#define TT_I2C0_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Pos (9UL)             /*!< TT_I2C0 STATUS: SLV_HOLD_TX_FIFO_EMPTY (Bit 9)        */
#define TT_I2C0_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Msk (0x200UL)         /*!< TT_I2C0 STATUS: SLV_HOLD_TX_FIFO_EMPTY (Bitfield-Mask: 0x01) */
#define TT_I2C0_STATUS_SLV_HOLD_RX_FIFO_FULL_Pos (10UL)             /*!< TT_I2C0 STATUS: SLV_HOLD_RX_FIFO_FULL (Bit 10)        */
#define TT_I2C0_STATUS_SLV_HOLD_RX_FIFO_FULL_Msk (0x400UL)          /*!< TT_I2C0 STATUS: SLV_HOLD_RX_FIFO_FULL (Bitfield-Mask: 0x01) */
#define TT_I2C0_STATUS_SDA_STUCK_NOT_RECOVERED_Pos (11UL)           /*!< TT_I2C0 STATUS: SDA_STUCK_NOT_RECOVERED (Bit 11)      */
#define TT_I2C0_STATUS_SDA_STUCK_NOT_RECOVERED_Msk (0x800UL)        /*!< TT_I2C0 STATUS: SDA_STUCK_NOT_RECOVERED (Bitfield-Mask: 0x01) */
#define TT_I2C0_STATUS_SLV_ISO_SAR_DATA_CLK_STRETCH_Pos (12UL)      /*!< TT_I2C0 STATUS: SLV_ISO_SAR_DATA_CLK_STRETCH (Bit 12) */
#define TT_I2C0_STATUS_SLV_ISO_SAR_DATA_CLK_STRETCH_Msk (0x1000UL)  /*!< TT_I2C0 STATUS: SLV_ISO_SAR_DATA_CLK_STRETCH (Bitfield-Mask: 0x01) */
/* =========================================================  TXFLR  ========================================================= */
#define TT_I2C0_TXFLR_TXFLR_Pos       (0UL)                     /*!< TT_I2C0 TXFLR: TXFLR (Bit 0)                      */
#define TT_I2C0_TXFLR_TXFLR_Msk       (0xffffffffUL)            /*!< TT_I2C0 TXFLR: TXFLR (Bitfield-Mask: 0xffffffff)  */
/* =========================================================  RXFLR  ========================================================= */
#define TT_I2C0_RXFLR_RXFLR_Pos       (0UL)                     /*!< TT_I2C0 RXFLR: RXFLR (Bit 0)                      */
#define TT_I2C0_RXFLR_RXFLR_Msk       (0xffffffffUL)            /*!< TT_I2C0 RXFLR: RXFLR (Bitfield-Mask: 0xffffffff)  */
/* =======================================================  SDA_HOLD  ======================================================== */
#define TT_I2C0_SDA_HOLD_SDA_HOLD_Pos (0UL)                     /*!< TT_I2C0 SDA_HOLD: SDA_HOLD (Bit 0)                */
#define TT_I2C0_SDA_HOLD_SDA_HOLD_Msk (0xffffUL)                /*!< TT_I2C0 SDA_HOLD: SDA_HOLD (Bitfield-Mask: 0xffff) */
#define TT_I2C0_SDA_HOLD_SDA_RX_HOLD_Pos  (16UL)                    /*!< TT_I2C0 SDA_HOLD: SDA_RX_HOLD (Bit 16)                */
#define TT_I2C0_SDA_HOLD_SDA_RX_HOLD_Msk  (0xff0000UL)              /*!< TT_I2C0 SDA_HOLD: SDA_RX_HOLD (Bitfield-Mask: 0xff)   */
/* ====================================================  TX_ABRT_SOURCE  ===================================================== */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Pos (0UL)     /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_7B_ADDR_NOACK (Bit 0) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Msk (0x1UL)   /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_7B_ADDR_NOACK (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Pos (1UL)     /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_10ADDR1_NOACK (Bit 1) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Msk (0x2UL)   /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_10ADDR1_NOACK (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Pos (2UL)     /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_10ADDR2_NOACK (Bit 2) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Msk (0x4UL)   /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_10ADDR2_NOACK (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Pos (3UL)      /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_TXDATA_NOACK (Bit 3) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Msk (0x8UL)    /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_TXDATA_NOACK (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Pos (4UL)       /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_GCALL_NOACK (Bit 4)  */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Msk (0x10UL)    /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_GCALL_NOACK (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_GCALL_READ_Pos (5UL)        /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_GCALL_READ (Bit 5)   */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_GCALL_READ_Msk (0x20UL)     /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_GCALL_READ (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Pos (6UL)         /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_HS_ACKDET (Bit 6)    */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Msk (0x40UL)      /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_HS_ACKDET (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Pos (7UL)      /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SBYTE_ACKDET (Bit 7) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Msk (0x80UL)   /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SBYTE_ACKDET (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_HS_NORSTR_Pos (8UL)         /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_HS_NORSTR (Bit 8)    */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_HS_NORSTR_Msk (0x100UL)     /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_HS_NORSTR (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Pos (9UL)     /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SBYTE_NORSTRT (Bit 9) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Msk (0x200UL) /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SBYTE_NORSTRT (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Pos (10UL)   /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_10B_RD_NORSTRT (Bit 10) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Msk (0x400UL) /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_10B_RD_NORSTRT (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Pos (11UL)       /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_MASTER_DIS (Bit 11)  */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Msk (0x800UL)    /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_MASTER_DIS (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ARB_LOST_Pos (12UL)              /*!< TT_I2C0 TX_ABRT_SOURCE: ARB_LOST (Bit 12)         */
#define TT_I2C0_TX_ABRT_SOURCE_ARB_LOST_Msk (0x1000UL)          /*!< TT_I2C0 TX_ABRT_SOURCE: ARB_LOST (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Pos (13UL)  /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SLVFLUSH_TXFIFO (Bit 13) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Msk (0x2000UL) /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SLVFLUSH_TXFIFO (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Pos (14UL)      /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SLV_ARBLOST (Bit 14) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Msk (0x4000UL)  /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SLV_ARBLOST (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Pos (15UL)       /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SLVRD_INTX (Bit 15)  */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Msk (0x8000UL)   /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SLVRD_INTX (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_USER_ABRT_Pos (16UL)            /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_USER_ABRT (Bit 16)       */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_USER_ABRT_Msk (0x10000UL)       /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_USER_ABRT (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Pos (17UL)     /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SDA_STUCK_AT_LOW (Bit 17) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Msk (0x20000UL) /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_SDA_STUCK_AT_LOW (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Pos (18UL)         /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_DEVICE_NOACK (Bit 18)    */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Msk (0x40000UL)    /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_DEVICE_NOACK (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Pos (19UL) /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_DEVICE_SLVADDR_NOACK (Bit 19) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Msk (0x80000UL) /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_DEVICE_SLVADDR_NOACK (Bitfield-Mask: 0x01) */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Pos (20UL)         /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_DEVICE_WRITE (Bit 20)    */
#define TT_I2C0_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Msk (0x100000UL)   /*!< TT_I2C0 TX_ABRT_SOURCE: ABRT_DEVICE_WRITE (Bitfield-Mask: 0x01) */
/* ==================================================  SLV_DATA_NACK_ONLY  =================================================== */
#define TT_I2C0_SLV_DATA_NACK_ONLY_NACK_Pos (0UL)               /*!< TT_I2C0 SLV_DATA_NACK_ONLY: NACK (Bit 0)          */
#define TT_I2C0_SLV_DATA_NACK_ONLY_NACK_Msk (0x1UL)             /*!< TT_I2C0 SLV_DATA_NACK_ONLY: NACK (Bitfield-Mask: 0x01) */
/* ========================================================  DMA_CR  ========================================================= */
#define TT_I2C0_DMA_CR_RDMAE_Pos      (0UL)                     /*!< TT_I2C0 DMA_CR: RDMAE (Bit 0)                     */
#define TT_I2C0_DMA_CR_RDMAE_Msk      (0x1UL)                   /*!< TT_I2C0 DMA_CR: RDMAE (Bitfield-Mask: 0x01)       */
#define TT_I2C0_DMA_CR_TDMAE_Pos      (1UL)                     /*!< TT_I2C0 DMA_CR: TDMAE (Bit 1)                     */
#define TT_I2C0_DMA_CR_TDMAE_Msk      (0x2UL)                   /*!< TT_I2C0 DMA_CR: TDMAE (Bitfield-Mask: 0x01)       */
/* =======================================================  DMA_TDLR  ======================================================== */
#define TT_I2C0_DMA_TDLR_DMATDL_Pos   (0UL)                     /*!< TT_I2C0 DMA_TDLR: DMATDL (Bit 0)                  */
#define TT_I2C0_DMA_TDLR_DMATDL_Msk   (0xffffffffUL)            /*!< TT_I2C0 DMA_TDLR: DMATDL (Bitfield-Mask: 0xffffffff) */
/* =======================================================  DMA_RDLR  ======================================================== */
#define TT_I2C0_DMA_RDLR_DMARDL_Pos   (0UL)                     /*!< TT_I2C0 DMA_RDLR: DMARDL (Bit 0)                  */
#define TT_I2C0_DMA_RDLR_DMARDL_Msk   (0xffffffffUL)            /*!< TT_I2C0 DMA_RDLR: DMARDL (Bitfield-Mask: 0xffffffff) */
/* =======================================================  SDA_SETUP  ======================================================= */
#define TT_I2C0_SDA_SETUP_SDA_SETUP_Pos (0UL)                   /*!< TT_I2C0 SDA_SETUP: SDA_SETUP (Bit 0)              */
#define TT_I2C0_SDA_SETUP_SDA_SETUP_Msk (0xffUL)                /*!< TT_I2C0 SDA_SETUP: SDA_SETUP (Bitfield-Mask: 0xff) */
/* ===================================================  ACK_GENERAL_CALL  ==================================================== */
#define TT_I2C0_ACK_GENERAL_CALL_ACK_GEN_CALL_Pos (0UL)         /*!< TT_I2C0 ACK_GENERAL_CALL: ACK_GEN_CALL (Bit 0)    */
#define TT_I2C0_ACK_GENERAL_CALL_ACK_GEN_CALL_Msk (0x1UL)       /*!< TT_I2C0 ACK_GENERAL_CALL: ACK_GEN_CALL (Bitfield-Mask: 0x01) */
/* =====================================================  ENABLE_STATUS  ===================================================== */
#define TT_I2C0_ENABLE_STATUS_EN_Pos  (0UL)                     /*!< TT_I2C0 ENABLE_STATUS: EN (Bit 0)                 */
#define TT_I2C0_ENABLE_STATUS_EN_Msk  (0x1UL)                   /*!< TT_I2C0 ENABLE_STATUS: EN (Bitfield-Mask: 0x01)   */
#define TT_I2C0_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Pos (1UL) /*!< TT_I2C0 ENABLE_STATUS: SLV_DISABLED_WHILE_BUSY (Bit 1) */
#define TT_I2C0_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Msk (0x2UL) /*!< TT_I2C0 ENABLE_STATUS: SLV_DISABLED_WHILE_BUSY (Bitfield-Mask: 0x01) */
#define TT_I2C0_ENABLE_STATUS_SLV_RX_DATA_LOST_Pos (2UL)        /*!< TT_I2C0 ENABLE_STATUS: SLV_RX_DATA_LOST (Bit 2)   */
#define TT_I2C0_ENABLE_STATUS_SLV_RX_DATA_LOST_Msk (0x4UL)      /*!< TT_I2C0 ENABLE_STATUS: SLV_RX_DATA_LOST (Bitfield-Mask: 0x01) */
/* =======================================================  FS_SPKLEN  ======================================================= */
#define TT_I2C0_FS_SPKLEN_FS_SPKLEN_Pos (0UL)                   /*!< TT_I2C0 FS_SPKLEN: FS_SPKLEN (Bit 0)              */
#define TT_I2C0_FS_SPKLEN_FS_SPKLEN_Msk (0xffUL)                /*!< TT_I2C0 FS_SPKLEN: FS_SPKLEN (Bitfield-Mask: 0xff) */
/* =======================================================  HS_SPKLEN  ======================================================= */
#define TT_I2C0_HS_SPKLEN_HS_SPKLEN_Pos (0UL)                   /*!< TT_I2C0 HS_SPKLEN: HS_SPKLEN (Bit 0)              */
#define TT_I2C0_HS_SPKLEN_HS_SPKLEN_Msk (0xffUL)                /*!< TT_I2C0 HS_SPKLEN: HS_SPKLEN (Bitfield-Mask: 0xff) */
/* ====================================================  CLR_RESTART_DET  ==================================================== */
#define TT_I2C0_CLR_RESTART_DET_CLR_RESTART_DET_Pos (0UL)           /*!< TT_I2C0 CLR_RESTART_DET: CLR_RESTART_DET (Bit 0)      */
#define TT_I2C0_CLR_RESTART_DET_CLR_RESTART_DET_Msk (0x1UL)         /*!< TT_I2C0 CLR_RESTART_DET: CLR_RESTART_DET (Bitfield-Mask: 0x01) */
/* ===============================================  SCL_STUCK_AT_LOW_TIMEOUT  ================================================ */
#define TT_I2C0_SCL_STUCK_AT_LOW_TIMEOUT_SCL_STUCK_LOW_TIMEOUT_Pos (0UL) /*!< TT_I2C0 SCL_STUCK_AT_LOW_TIMEOUT: SCL_STUCK_LOW_TIMEOUT (Bit 0) */
#define TT_I2C0_SCL_STUCK_AT_LOW_TIMEOUT_SCL_STUCK_LOW_TIMEOUT_Msk (0xffffffffUL) /*!< TT_I2C0 SCL_STUCK_AT_LOW_TIMEOUT: SCL_STUCK_LOW_TIMEOUT (Bitfield-Mask: 0xffffffff) */
/* ===============================================  SDA_STUCK_AT_LOW_TIMEOUT  ================================================ */
#define TT_I2C0_SDA_STUCK_AT_LOW_TIMEOUT_SDA_STUCK_LOW_TIMEOUT_Pos (0UL) /*!< TT_I2C0 SDA_STUCK_AT_LOW_TIMEOUT: SDA_STUCK_LOW_TIMEOUT (Bit 0) */
#define TT_I2C0_SDA_STUCK_AT_LOW_TIMEOUT_SDA_STUCK_LOW_TIMEOUT_Msk (0xffffffffUL) /*!< TT_I2C0 SDA_STUCK_AT_LOW_TIMEOUT: SDA_STUCK_LOW_TIMEOUT (Bitfield-Mask: 0xffffffff) */
/* ===================================================  CLR_SCL_STUCK_DET  =================================================== */
#define TT_I2C0_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Pos (0UL)       /*!< TT_I2C0 CLR_SCL_STUCK_DET: CLR_SCL_STUCK_DET (Bit 0)  */
#define TT_I2C0_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Msk (0x1UL)     /*!< TT_I2C0 CLR_SCL_STUCK_DET: CLR_SCL_STUCK_DET (Bitfield-Mask: 0x01) */
/* =====================================================  COMP_VERSION  ====================================================== */
#define TT_I2C0_COMP_VERSION_COMP_VERSION_Pos (0UL)             /*!< TT_I2C0 COMP_VERSION: COMP_VERSION (Bit 0)        */
#define TT_I2C0_COMP_VERSION_COMP_VERSION_Msk (0xffffffffUL)    /*!< TT_I2C0 COMP_VERSION: COMP_VERSION (Bitfield-Mask: 0xffffffff) */
/* =======================================================  COMP_TYPE  ======================================================= */
#define TT_I2C0_COMP_TYPE_COMP_TYPE_Pos (0UL)                   /*!< TT_I2C0 COMP_TYPE: COMP_TYPE (Bit 0)              */
#define TT_I2C0_COMP_TYPE_COMP_TYPE_Msk (0xffffffffUL)          /*!< TT_I2C0 COMP_TYPE: COMP_TYPE (Bitfield-Mask: 0xffffffff) */

#ifdef __cplusplus
}
#endif

#endif /* A8V2E_I2C_H */
