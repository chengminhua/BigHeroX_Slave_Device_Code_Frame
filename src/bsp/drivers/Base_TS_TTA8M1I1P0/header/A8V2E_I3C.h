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
#ifndef A8V2E_I3C_H
#define A8V2E_I3C_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_I3C_VENDOR_ID_H                     1541
#define A8V2E_I3C_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_I3C_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_I3C_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_I3C_SW_MAJOR_VERSION_H              1
#define A8V2E_I3C_SW_MINOR_VERSION_H              1
#define A8V2E_I3C_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_I3C.h and TT_Common.h file version check */
#if (A8V2E_I3C_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_I3C.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_I3C_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_I3C_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_I3C_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_I3C.h and TT_Common.h are different"
#endif
#if ((A8V2E_I3C_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_I3C_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_I3C_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_I3C.h and TT_Common.h are different"
#endif


typedef struct {                                /*!< (@ 0x400D0000) TT_I3C0 Structure                                      */
  __IOM uint32  MCONFIG;                      /*!< (@ 0x00000000) Master Configuration Register                              */
  __IOM uint32  SCONFIG;                      /*!< (@ 0x00000004) Slave Configuration Register                               */
  __IOM uint32  SSTATUS;                      /*!< (@ 0x00000008) Slave Status Register                                      */
  __IOM uint32  SCTRL;                        /*!< (@ 0x0000000C) Slave Control Register                                     */
  __IOM uint32  SINTSET;                      /*!< (@ 0x00000010) Slave Interrupt Set Register                               */
  __OM  uint32  SINTCLR;                      /*!< (@ 0x00000014) Slave Interrupt Clear Register                             */
  __IM  uint32  SINTMASKED;                   /*!< (@ 0x00000018) Slave Interrupt Mask Register                              */
  __IOM uint32  SERRWARN;                     /*!< (@ 0x0000001C) Slave Errors and Warnings Register                         */
  __IOM uint32  SDMACTRL;                     /*!< (@ 0x00000020) Slave DMA Control Register                                 */
  __IOM uint32  HDRBTCFG;                     /*!< (@ 0x00000024) Contains setup information associated with HDR-BT
                                                                    mode.                                                      */
  __IM  uint32  HDRBTLAST;                    /*!< (@ 0x00000028) Contains the data length of the most recent HDR-BT
                                                                    mode transfer.                                             */
  __IOM uint32  SDATACTRL;                    /*!< (@ 0x0000002C) Slave Data Control Register                                */
  __OM  uint32  SWDATAB;                      /*!< (@ 0x00000030) Slave Write Data Byte Register                             */
  __OM  uint32  SWDATABE;                     /*!< (@ 0x00000034) Slave Write Data Byte End                                  */
  __OM  uint32  SWDATAH;                      /*!< (@ 0x00000038) Slave Write Data Half-word Register                        */
  __OM  uint32  SWDATAHE;                     /*!< (@ 0x0000003C) Slave Write Data Half-word End Register                    */
  __IM  uint32  SRDATAB;                      /*!< (@ 0x00000040) Slave Read Data Byte Register                              */
  __IM  uint32  RESERVED;
  __IM  uint32  SRDATAH;                      /*!< (@ 0x00000048) Slave Read Data Half-word Register                         */
  __IM  uint32  RESERVED1[2];
  __OM  uint32  WDATAB1;                      /*!< (@ 0x00000054) Provide a way to write.                                    */
  __IM  uint32  RESERVED2;
  __IM  uint32  SCAPABILITIES2;               /*!< (@ 0x0000005C) The capabilities 2 register.                               */
  __IM  uint32  SCAPABILITIES;                /*!< (@ 0x00000060) Slave Capabilities Register                                */
  __IM  uint32  SDYNADDR;                     /*!< (@ 0x00000064) Slave Dynamic Address Register                             */
  __IOM uint32  SMAXLIMITS;                   /*!< (@ 0x00000068) Slave Maximum Limits Register                              */
  __IOM uint32  SIDPARTNO;                    /*!< (@ 0x0000006C) Slave ID Part Number Register                              */
  __IOM uint32  SIDEXT;                       /*!< (@ 0x00000070) Slave ID Extension Register                                */
  __IOM uint32  SVENDORID;                    /*!< (@ 0x00000074) Slave Vendor ID Register                                   */
  __IOM uint32  STCCLOCK;                     /*!< (@ 0x00000078) Slave Time Control Clock Register                          */
  __IM  uint32  SMSGLAST;                     /*!< (@ 0x0000007C) Recent transfer.                                           */
  __IM  uint32  RESERVED3;
  __IOM uint32  MCTRL;                        /*!< (@ 0x00000084) Master Main Control Register                               */
  __IOM uint32  MSTATUS;                      /*!< (@ 0x00000088) Master Status Register                                     */
  __IOM uint32  MIBIRULES;                    /*!< (@ 0x0000008C) Master In-band Interrupt Registry and Rules Register       */
  __IOM uint32  MINTSET;                      /*!< (@ 0x00000090) Master Interrupt Set Register                              */
  __OM  uint32  MINTCLR;                      /*!< (@ 0x00000094) Master Interrupt Clear Register                            */
  __IM  uint32  MINTMASKED;                   /*!< (@ 0x00000098) Master Interrupt Mask Register                             */
  __IOM uint32  MERRWARN;                     /*!< (@ 0x0000009C) Master Errors and Warnings Register                        */
  __IOM uint32  MDMACTRL;                     /*!< (@ 0x000000A0) Master DMA Control Register                                */
  __IOM uint32  MHDRBTCFG;                    /*!< (@ 0x000000A4) Master Data Control Register                               */
  __IOM uint32  MHDRBTLAST;                   /*!< (@ 0x000000A8V2E) Most recent HDR-BT mode tranfser                           */
  __IOM uint32  MDATACTRL;                    /*!< (@ 0x000000AC) Master Data Control Register                               */
  __OM  uint32  MWDATAB;                      /*!< (@ 0x000000B0) Master Write Data Byte Register                            */
  __OM  uint32  MWDATABE;                     /*!< (@ 0x000000B4) Master Write Data Byte End Register                        */
  __OM  uint32  MWDATAH;                      /*!< (@ 0x000000B8) Master Write Data Half-word Register                       */
  __OM  uint32  MWDATAHE;                     /*!< (@ 0x000000BC) Master Write Data Byte End Register                        */
  __IM  uint32  MRDATAB;                      /*!< (@ 0x000000C0) Master Read Data Byte Register                             */
  __IM  uint32  RESERVED4;
  __IM  uint32  MRDATAH;                      /*!< (@ 0x000000C8) Master Read Data Half-word Register                        */
  __OM  uint32  MWDATAB1;                     /*!< (@ 0x000000CC) Provide a way to write                                     */
  
  union {
    __OM  uint32 MWMSG_SDR_CONTROL; /*!< (@ 0x000000D0) Master Write Message in SDR mode                           */
    __OM  uint32 MWMSG_SDR_DATA;    /*!< (@ 0x000000D0) Master Write Message Data in SDR mode                      */
  }MWMSG_SDR;
  __IM  uint32  MRMSG_SDR;                    /*!< (@ 0x000000D4) Master Read Message in SDR mode                            */
  
  union {
    __OM  uint32 MWMSG_DDR_CONTROL; /*!< (@ 0x000000D8) Master Write Message in DDR mode                           */
    __OM  uint32 MWMSG_DDR_DATA;    /*!< (@ 0x000000D8) Master Write Message Data in DDR mode                      */
    __OM  uint32 MWMSG_DDR_ADDRCMD; /*!< (@ 0x000000D8) Address and command                                        */
  }MWMSG_DDR;
  __IM  uint32  MRMSG_DDR;                    /*!< (@ 0x000000DC) Master Read Message in DDR mode                            */
  __IM  uint32  RESERVED5;
  __IOM uint32  MDYNADDR;                     /*!< (@ 0x000000E4) Master Dynamic Address Register                            */
  __IM  uint32  RESERVED6[2];
  __OM  uint32  MWDATAW;                      /*!< (@ 0x000000F0) Used to write word data for HDR-BT mode                    */
  __IM  uint32  RESERVED7;
  __IM  uint32  MRDATAW;                      /*!< (@ 0x000000F8) Used to read word data for HDR-BT mode                     */
  __IM  uint32  RESERVED8;
  __IOM uint32  RSTACTTIME;                   /*!< (@ 0x00000100) Hold value of reset time                                   */
  __IM  uint32  RESERVED9[15];
  __IOM uint32  IBIEXT1;                      /*!< (@ 0x00000140) Stores up to three extended IBI data bytes and
                                                                    controls                                                   */
  __IOM uint32  IBIEXT2;                      /*!< (@ 0x00000144) Stores up to three extended IBI data bytes                 */
  __IM  uint32  RESERVED10[2];
  __OM  uint32  WDATAW;                       /*!< (@ 0x00000150) Write word data into the transmit buffer                   */
  __IM  uint32  RESERVED11;
  __IM  uint32  RDATAW;                       /*!< (@ 0x00000158) read word data into the receive buffer                     */
  __IM  uint32  RESERVED12[936];
  __IM  uint32  SID;                          /*!< (@ 0x00000FFC) Slave Module ID Register                                   */
} TT_I3C_Type;                              /*!< Size = 4096 (0x1000)                                                      */

#define TT_I3C0_BASE            0x400D0000UL

#define TT_I3C0                 ((TT_I3C_Type*)        TT_I3C0_BASE)

#define TT_I3C_COUNT            1U

/* =========================================================================================================================== */
/* ================                                        TT_I3C                                         ================ */
/* =========================================================================================================================== */

/* ========================================================  MCONFIG  ======================================================== */
#define TT_I3C_MCONFIG_MSTENA_Pos     (0UL)                     /*!< TT_I3C MCONFIG: MSTENA (Bit 0)                    */
#define TT_I3C_MCONFIG_MSTENA_Msk     (0x3UL)                   /*!< TT_I3C MCONFIG: MSTENA (Bitfield-Mask: 0x03)      */
#define TT_I3C_MCONFIG_DISTO_Pos      (3UL)                     /*!< TT_I3C MCONFIG: DISTO (Bit 3)                     */
#define TT_I3C_MCONFIG_DISTO_Msk      (0x8UL)                   /*!< TT_I3C MCONFIG: DISTO (Bitfield-Mask: 0x01)       */
#define TT_I3C_MCONFIG_HKEEP_Pos      (4UL)                     /*!< TT_I3C MCONFIG: HKEEP (Bit 4)                     */
#define TT_I3C_MCONFIG_HKEEP_Msk      (0x30UL)                  /*!< TT_I3C MCONFIG: HKEEP (Bitfield-Mask: 0x03)       */
#define TT_I3C_MCONFIG_ODSTOP_Pos     (6UL)                     /*!< TT_I3C MCONFIG: ODSTOP (Bit 6)                    */
#define TT_I3C_MCONFIG_ODSTOP_Msk     (0x40UL)                  /*!< TT_I3C MCONFIG: ODSTOP (Bitfield-Mask: 0x01)      */
#define TT_I3C_MCONFIG_PPBAUD_Pos     (8UL)                     /*!< TT_I3C MCONFIG: PPBAUD (Bit 8)                    */
#define TT_I3C_MCONFIG_PPBAUD_Msk     (0xf00UL)                 /*!< TT_I3C MCONFIG: PPBAUD (Bitfield-Mask: 0x0f)      */
#define TT_I3C_MCONFIG_PPLOW_Pos      (12UL)                    /*!< TT_I3C MCONFIG: PPLOW (Bit 12)                    */
#define TT_I3C_MCONFIG_PPLOW_Msk      (0xf000UL)                /*!< TT_I3C MCONFIG: PPLOW (Bitfield-Mask: 0x0f)       */
#define TT_I3C_MCONFIG_ODBAUD_Pos     (16UL)                    /*!< TT_I3C MCONFIG: ODBAUD (Bit 16)                   */
#define TT_I3C_MCONFIG_ODBAUD_Msk     (0xff0000UL)              /*!< TT_I3C MCONFIG: ODBAUD (Bitfield-Mask: 0xff)      */
#define TT_I3C_MCONFIG_ODHPP_Pos      (24UL)                    /*!< TT_I3C MCONFIG: ODHPP (Bit 24)                    */
#define TT_I3C_MCONFIG_ODHPP_Msk      (0x1000000UL)             /*!< TT_I3C MCONFIG: ODHPP (Bitfield-Mask: 0x01)       */
#define TT_I3C_MCONFIG_SKEW_Pos       (25UL)                    /*!< TT_I3C MCONFIG: SKEW (Bit 25)                     */
#define TT_I3C_MCONFIG_SKEW_Msk       (0xe000000UL)             /*!< TT_I3C MCONFIG: SKEW (Bitfield-Mask: 0x07)        */
#define TT_I3C_MCONFIG_I2CBAUD_Pos    (28UL)                    /*!< TT_I3C MCONFIG: I2CBAUD (Bit 28)                  */
#define TT_I3C_MCONFIG_I2CBAUD_Msk    (0xf0000000UL)            /*!< TT_I3C MCONFIG: I2CBAUD (Bitfield-Mask: 0x0f)     */
/* ========================================================  SCONFIG  ======================================================== */
#define TT_I3C_SCONFIG_SLVENA_Pos     (0UL)                     /*!< TT_I3C SCONFIG: SLVENA (Bit 0)                    */
#define TT_I3C_SCONFIG_SLVENA_Msk     (0x1UL)                   /*!< TT_I3C SCONFIG: SLVENA (Bitfield-Mask: 0x01)      */
#define TT_I3C_SCONFIG_MATCHSS_Pos    (2UL)                     /*!< TT_I3C SCONFIG: MATCHSS (Bit 2)                   */
#define TT_I3C_SCONFIG_MATCHSS_Msk    (0x4UL)                   /*!< TT_I3C SCONFIG: MATCHSS (Bitfield-Mask: 0x01)     */
#define TT_I3C_SCONFIG_S0IGNORE_Pos   (3UL)                     /*!< TT_I3C SCONFIG: S0IGNORE (Bit 3)                  */
#define TT_I3C_SCONFIG_S0IGNORE_Msk   (0x8UL)                   /*!< TT_I3C SCONFIG: S0IGNORE (Bitfield-Mask: 0x01)    */
#define TT_I3C_SCONFIG_BTML_Pos       (5UL)                     /*!< TT_I3C SCONFIG: BTML (Bit 5)                      */
#define TT_I3C_SCONFIG_BTML_Msk       (0x60UL)                  /*!< TT_I3C SCONFIG: BTML (Bitfield-Mask: 0x03)        */
#define TT_I3C_SCONFIG_IDRAND_Pos     (8UL)                     /*!< TT_I3C SCONFIG: IDRAND (Bit 8)                    */
#define TT_I3C_SCONFIG_IDRAND_Msk     (0x100UL)                 /*!< TT_I3C SCONFIG: IDRAND (Bitfield-Mask: 0x01)      */
#define TT_I3C_SCONFIG_OFFLINE_Pos    (9UL)                     /*!< TT_I3C SCONFIG: OFFLINE (Bit 9)                   */
#define TT_I3C_SCONFIG_OFFLINE_Msk    (0x200UL)                 /*!< TT_I3C SCONFIG: OFFLINE (Bitfield-Mask: 0x01)     */
#define TT_I3C_SCONFIG_BAMATCH_Pos    (16UL)                    /*!< TT_I3C SCONFIG: BAMATCH (Bit 16)                  */
#define TT_I3C_SCONFIG_BAMATCH_Msk    (0xff0000UL)              /*!< TT_I3C SCONFIG: BAMATCH (Bitfield-Mask: 0xff)     */
#define TT_I3C_SCONFIG_SADDR_Pos      (25UL)                    /*!< TT_I3C SCONFIG: SADDR (Bit 25)                    */
#define TT_I3C_SCONFIG_SADDR_Msk      (0xfe000000UL)            /*!< TT_I3C SCONFIG: SADDR (Bitfield-Mask: 0x7f)       */
/* ========================================================  SSTATUS  ======================================================== */
#define TT_I3C_SSTATUS_STNOTSTOP_Pos  (0UL)                     /*!< TT_I3C SSTATUS: STNOTSTOP (Bit 0)                 */
#define TT_I3C_SSTATUS_STNOTSTOP_Msk  (0x1UL)                   /*!< TT_I3C SSTATUS: STNOTSTOP (Bitfield-Mask: 0x01)   */
#define TT_I3C_SSTATUS_STMSG_Pos      (1UL)                     /*!< TT_I3C SSTATUS: STMSG (Bit 1)                     */
#define TT_I3C_SSTATUS_STMSG_Msk      (0x2UL)                   /*!< TT_I3C SSTATUS: STMSG (Bitfield-Mask: 0x01)       */
#define TT_I3C_SSTATUS_STCCCH_Pos     (2UL)                     /*!< TT_I3C SSTATUS: STCCCH (Bit 2)                    */
#define TT_I3C_SSTATUS_STCCCH_Msk     (0x4UL)                   /*!< TT_I3C SSTATUS: STCCCH (Bitfield-Mask: 0x01)      */
#define TT_I3C_SSTATUS_STREQRD_Pos    (3UL)                     /*!< TT_I3C SSTATUS: STREQRD (Bit 3)                   */
#define TT_I3C_SSTATUS_STREQRD_Msk    (0x8UL)                   /*!< TT_I3C SSTATUS: STREQRD (Bitfield-Mask: 0x01)     */
#define TT_I3C_SSTATUS_STREQWR_Pos    (4UL)                     /*!< TT_I3C SSTATUS: STREQWR (Bit 4)                   */
#define TT_I3C_SSTATUS_STREQWR_Msk    (0x10UL)                  /*!< TT_I3C SSTATUS: STREQWR (Bitfield-Mask: 0x01)     */
#define TT_I3C_SSTATUS_STDAA_Pos      (5UL)                     /*!< TT_I3C SSTATUS: STDAA (Bit 5)                     */
#define TT_I3C_SSTATUS_STDAA_Msk      (0x20UL)                  /*!< TT_I3C SSTATUS: STDAA (Bitfield-Mask: 0x01)       */
#define TT_I3C_SSTATUS_STHDR_Pos      (6UL)                     /*!< TT_I3C SSTATUS: STHDR (Bit 6)                     */
#define TT_I3C_SSTATUS_STHDR_Msk      (0x40UL)                  /*!< TT_I3C SSTATUS: STHDR (Bitfield-Mask: 0x01)       */
#define TT_I3C_SSTATUS_START_Pos      (8UL)                     /*!< TT_I3C SSTATUS: START (Bit 8)                     */
#define TT_I3C_SSTATUS_START_Msk      (0x100UL)                 /*!< TT_I3C SSTATUS: START (Bitfield-Mask: 0x01)       */
#define TT_I3C_SSTATUS_MATCHED_Pos    (9UL)                     /*!< TT_I3C SSTATUS: MATCHED (Bit 9)                   */
#define TT_I3C_SSTATUS_MATCHED_Msk    (0x200UL)                 /*!< TT_I3C SSTATUS: MATCHED (Bitfield-Mask: 0x01)     */
#define TT_I3C_SSTATUS_STOP_Pos       (10UL)                    /*!< TT_I3C SSTATUS: STOP (Bit 10)                     */
#define TT_I3C_SSTATUS_STOP_Msk       (0x400UL)                 /*!< TT_I3C SSTATUS: STOP (Bitfield-Mask: 0x01)        */
#define TT_I3C_SSTATUS_RX_PEND_Pos    (11UL)                    /*!< TT_I3C SSTATUS: RX_PEND (Bit 11)                  */
#define TT_I3C_SSTATUS_RX_PEND_Msk    (0x800UL)                 /*!< TT_I3C SSTATUS: RX_PEND (Bitfield-Mask: 0x01)     */
#define TT_I3C_SSTATUS_TXNOTFULL_Pos  (12UL)                    /*!< TT_I3C SSTATUS: TXNOTFULL (Bit 12)                */
#define TT_I3C_SSTATUS_TXNOTFULL_Msk  (0x1000UL)                /*!< TT_I3C SSTATUS: TXNOTFULL (Bitfield-Mask: 0x01)   */
#define TT_I3C_SSTATUS_DACHG_Pos      (13UL)                    /*!< TT_I3C SSTATUS: DACHG (Bit 13)                    */
#define TT_I3C_SSTATUS_DACHG_Msk      (0x2000UL)                /*!< TT_I3C SSTATUS: DACHG (Bitfield-Mask: 0x01)       */
#define TT_I3C_SSTATUS_CCC_Pos        (14UL)                    /*!< TT_I3C SSTATUS: CCC (Bit 14)                      */
#define TT_I3C_SSTATUS_CCC_Msk        (0x4000UL)                /*!< TT_I3C SSTATUS: CCC (Bitfield-Mask: 0x01)         */
#define TT_I3C_SSTATUS_ERRWARN_Pos    (15UL)                    /*!< TT_I3C SSTATUS: ERRWARN (Bit 15)                  */
#define TT_I3C_SSTATUS_ERRWARN_Msk    (0x8000UL)                /*!< TT_I3C SSTATUS: ERRWARN (Bitfield-Mask: 0x01)     */
#define TT_I3C_SSTATUS_HDRMATCH_Pos   (16UL)                    /*!< TT_I3C SSTATUS: HDRMATCH (Bit 16)                 */
#define TT_I3C_SSTATUS_HDRMATCH_Msk   (0x10000UL)               /*!< TT_I3C SSTATUS: HDRMATCH (Bitfield-Mask: 0x01)    */
#define TT_I3C_SSTATUS_CHANDLED_Pos   (17UL)                    /*!< TT_I3C SSTATUS: CHANDLED (Bit 17)                 */
#define TT_I3C_SSTATUS_CHANDLED_Msk   (0x20000UL)               /*!< TT_I3C SSTATUS: CHANDLED (Bitfield-Mask: 0x01)    */
#define TT_I3C_SSTATUS_EVENT_Pos      (18UL)                    /*!< TT_I3C SSTATUS: EVENT (Bit 18)                    */
#define TT_I3C_SSTATUS_EVENT_Msk      (0x40000UL)               /*!< TT_I3C SSTATUS: EVENT (Bitfield-Mask: 0x01)       */
#define TT_I3C_SSTATUS_TGTRST_Pos     (19UL)                    /*!< TT_I3C SSTATUS: TGTRST (Bit 19)                   */
#define TT_I3C_SSTATUS_TGTRST_Msk     (0x80000UL)               /*!< TT_I3C SSTATUS: TGTRST (Bitfield-Mask: 0x01)      */
#define TT_I3C_SSTATUS_EVDET_Pos      (20UL)                    /*!< TT_I3C SSTATUS: EVDET (Bit 20)                    */
#define TT_I3C_SSTATUS_EVDET_Msk      (0x300000UL)              /*!< TT_I3C SSTATUS: EVDET (Bitfield-Mask: 0x03)       */
#define TT_I3C_SSTATUS_IBIDIS_Pos     (24UL)                    /*!< TT_I3C SSTATUS: IBIDIS (Bit 24)                   */
#define TT_I3C_SSTATUS_IBIDIS_Msk     (0x1000000UL)             /*!< TT_I3C SSTATUS: IBIDIS (Bitfield-Mask: 0x01)      */
#define TT_I3C_SSTATUS_MRDIS_Pos      (25UL)                    /*!< TT_I3C SSTATUS: MRDIS (Bit 25)                    */
#define TT_I3C_SSTATUS_MRDIS_Msk      (0x2000000UL)             /*!< TT_I3C SSTATUS: MRDIS (Bitfield-Mask: 0x01)       */
#define TT_I3C_SSTATUS_HJDIS_Pos      (27UL)                    /*!< TT_I3C SSTATUS: HJDIS (Bit 27)                    */
#define TT_I3C_SSTATUS_HJDIS_Msk      (0x8000000UL)             /*!< TT_I3C SSTATUS: HJDIS (Bitfield-Mask: 0x01)       */
#define TT_I3C_SSTATUS_ACTSTATE_Pos   (28UL)                    /*!< TT_I3C SSTATUS: ACTSTATE (Bit 28)                 */
#define TT_I3C_SSTATUS_ACTSTATE_Msk   (0x30000000UL)            /*!< TT_I3C SSTATUS: ACTSTATE (Bitfield-Mask: 0x03)    */
#define TT_I3C_SSTATUS_TIMECTRL_Pos   (30UL)                    /*!< TT_I3C SSTATUS: TIMECTRL (Bit 30)                 */
#define TT_I3C_SSTATUS_TIMECTRL_Msk   (0xc0000000UL)            /*!< TT_I3C SSTATUS: TIMECTRL (Bitfield-Mask: 0x03)    */
/* =========================================================  SCTRL  ========================================================= */
#define TT_I3C_SCTRL_EVENT_Pos        (0UL)                     /*!< TT_I3C SCTRL: EVENT (Bit 0)                       */
#define TT_I3C_SCTRL_EVENT_Msk        (0x3UL)                   /*!< TT_I3C SCTRL: EVENT (Bitfield-Mask: 0x03)         */
#define TT_I3C_SCTRL_EXTDATA_Pos      (3UL)                     /*!< TT_I3C SCTRL: EXTDATA (Bit 3)                     */
#define TT_I3C_SCTRL_EXTDATA_Msk      (0x8UL)                   /*!< TT_I3C SCTRL: EXTDATA (Bitfield-Mask: 0x01)       */
#define TT_I3C_SCTRL_IBIDATA_Pos      (8UL)                     /*!< TT_I3C SCTRL: IBIDATA (Bit 8)                     */
#define TT_I3C_SCTRL_IBIDATA_Msk      (0xff00UL)                /*!< TT_I3C SCTRL: IBIDATA (Bitfield-Mask: 0xff)       */
#define TT_I3C_SCTRL_PENDINT_Pos      (16UL)                    /*!< TT_I3C SCTRL: PENDINT (Bit 16)                    */
#define TT_I3C_SCTRL_PENDINT_Msk      (0xf0000UL)               /*!< TT_I3C SCTRL: PENDINT (Bitfield-Mask: 0x0f)       */
#define TT_I3C_SCTRL_ACTSTATE_Pos     (20UL)                    /*!< TT_I3C SCTRL: ACTSTATE (Bit 20)                   */
#define TT_I3C_SCTRL_ACTSTATE_Msk     (0x300000UL)              /*!< TT_I3C SCTRL: ACTSTATE (Bitfield-Mask: 0x03)      */
#define TT_I3C_SCTRL_VENDINFO_Pos     (24UL)                    /*!< TT_I3C SCTRL: VENDINFO (Bit 24)                   */
#define TT_I3C_SCTRL_VENDINFO_Msk     (0xff000000UL)            /*!< TT_I3C SCTRL: VENDINFO (Bitfield-Mask: 0xff)      */
/* ========================================================  SINTSET  ======================================================== */
#define TT_I3C_SINTSET_START_Pos      (8UL)                     /*!< TT_I3C SINTSET: START (Bit 8)                     */
#define TT_I3C_SINTSET_START_Msk      (0x100UL)                 /*!< TT_I3C SINTSET: START (Bitfield-Mask: 0x01)       */
#define TT_I3C_SINTSET_MATCHED_Pos    (9UL)                     /*!< TT_I3C SINTSET: MATCHED (Bit 9)                   */
#define TT_I3C_SINTSET_MATCHED_Msk    (0x200UL)                 /*!< TT_I3C SINTSET: MATCHED (Bitfield-Mask: 0x01)     */
#define TT_I3C_SINTSET_STOP_Pos       (10UL)                    /*!< TT_I3C SINTSET: STOP (Bit 10)                     */
#define TT_I3C_SINTSET_STOP_Msk       (0x400UL)                 /*!< TT_I3C SINTSET: STOP (Bitfield-Mask: 0x01)        */
#define TT_I3C_SINTSET_RXPEND_Pos     (11UL)                    /*!< TT_I3C SINTSET: RXPEND (Bit 11)                   */
#define TT_I3C_SINTSET_RXPEND_Msk     (0x800UL)                 /*!< TT_I3C SINTSET: RXPEND (Bitfield-Mask: 0x01)      */
#define TT_I3C_SINTSET_TXSEND_Pos     (12UL)                    /*!< TT_I3C SINTSET: TXSEND (Bit 12)                   */
#define TT_I3C_SINTSET_TXSEND_Msk     (0x1000UL)                /*!< TT_I3C SINTSET: TXSEND (Bitfield-Mask: 0x01)      */
#define TT_I3C_SINTSET_DACHG_Pos      (13UL)                    /*!< TT_I3C SINTSET: DACHG (Bit 13)                    */
#define TT_I3C_SINTSET_DACHG_Msk      (0x2000UL)                /*!< TT_I3C SINTSET: DACHG (Bitfield-Mask: 0x01)       */
#define TT_I3C_SINTSET_CCC_Pos        (14UL)                    /*!< TT_I3C SINTSET: CCC (Bit 14)                      */
#define TT_I3C_SINTSET_CCC_Msk        (0x4000UL)                /*!< TT_I3C SINTSET: CCC (Bitfield-Mask: 0x01)         */
#define TT_I3C_SINTSET_ERRWARN_Pos    (15UL)                    /*!< TT_I3C SINTSET: ERRWARN (Bit 15)                  */
#define TT_I3C_SINTSET_ERRWARN_Msk    (0x8000UL)                /*!< TT_I3C SINTSET: ERRWARN (Bitfield-Mask: 0x01)     */
#define TT_I3C_SINTSET_DDRMATCHED_Pos (16UL)                    /*!< TT_I3C SINTSET: DDRMATCHED (Bit 16)               */
#define TT_I3C_SINTSET_DDRMATCHED_Msk (0x10000UL)               /*!< TT_I3C SINTSET: DDRMATCHED (Bitfield-Mask: 0x01)  */
#define TT_I3C_SINTSET_CHANDLED_Pos   (17UL)                    /*!< TT_I3C SINTSET: CHANDLED (Bit 17)                 */
#define TT_I3C_SINTSET_CHANDLED_Msk   (0x20000UL)               /*!< TT_I3C SINTSET: CHANDLED (Bitfield-Mask: 0x01)    */
#define TT_I3C_SINTSET_EVENT_Pos      (18UL)                    /*!< TT_I3C SINTSET: EVENT (Bit 18)                    */
#define TT_I3C_SINTSET_EVENT_Msk      (0x40000UL)               /*!< TT_I3C SINTSET: EVENT (Bitfield-Mask: 0x01)       */
#define TT_I3C_SINTSET_TGTRST_Pos     (19UL)                    /*!< TT_I3C SINTSET: TGTRST (Bit 19)                   */
#define TT_I3C_SINTSET_TGTRST_Msk     (0x80000UL)               /*!< TT_I3C SINTSET: TGTRST (Bitfield-Mask: 0x01)      */
/* ========================================================  SINTCLR  ======================================================== */
#define TT_I3C_SINTCLR_START_Pos      (8UL)                     /*!< TT_I3C SINTCLR: START (Bit 8)                     */
#define TT_I3C_SINTCLR_START_Msk      (0x100UL)                 /*!< TT_I3C SINTCLR: START (Bitfield-Mask: 0x01)       */
#define TT_I3C_SINTCLR_MATCHED_Pos    (9UL)                     /*!< TT_I3C SINTCLR: MATCHED (Bit 9)                   */
#define TT_I3C_SINTCLR_MATCHED_Msk    (0x200UL)                 /*!< TT_I3C SINTCLR: MATCHED (Bitfield-Mask: 0x01)     */
#define TT_I3C_SINTCLR_STOP_Pos       (10UL)                    /*!< TT_I3C SINTCLR: STOP (Bit 10)                     */
#define TT_I3C_SINTCLR_STOP_Msk       (0x400UL)                 /*!< TT_I3C SINTCLR: STOP (Bitfield-Mask: 0x01)        */
#define TT_I3C_SINTCLR_RXPEND_Pos     (11UL)                    /*!< TT_I3C SINTCLR: RXPEND (Bit 11)                   */
#define TT_I3C_SINTCLR_RXPEND_Msk     (0x800UL)                 /*!< TT_I3C SINTCLR: RXPEND (Bitfield-Mask: 0x01)      */
#define TT_I3C_SINTCLR_TXSEND_Pos     (12UL)                    /*!< TT_I3C SINTCLR: TXSEND (Bit 12)                   */
#define TT_I3C_SINTCLR_TXSEND_Msk     (0x1000UL)                /*!< TT_I3C SINTCLR: TXSEND (Bitfield-Mask: 0x01)      */
#define TT_I3C_SINTCLR_DACHG_Pos      (13UL)                    /*!< TT_I3C SINTCLR: DACHG (Bit 13)                    */
#define TT_I3C_SINTCLR_DACHG_Msk      (0x2000UL)                /*!< TT_I3C SINTCLR: DACHG (Bitfield-Mask: 0x01)       */
#define TT_I3C_SINTCLR_CCC_Pos        (14UL)                    /*!< TT_I3C SINTCLR: CCC (Bit 14)                      */
#define TT_I3C_SINTCLR_CCC_Msk        (0x4000UL)                /*!< TT_I3C SINTCLR: CCC (Bitfield-Mask: 0x01)         */
#define TT_I3C_SINTCLR_ERRWARN_Pos    (15UL)                    /*!< TT_I3C SINTCLR: ERRWARN (Bit 15)                  */
#define TT_I3C_SINTCLR_ERRWARN_Msk    (0x8000UL)                /*!< TT_I3C SINTCLR: ERRWARN (Bitfield-Mask: 0x01)     */
#define TT_I3C_SINTCLR_DDRMATCHED_Pos (16UL)                    /*!< TT_I3C SINTCLR: DDRMATCHED (Bit 16)               */
#define TT_I3C_SINTCLR_DDRMATCHED_Msk (0x10000UL)               /*!< TT_I3C SINTCLR: DDRMATCHED (Bitfield-Mask: 0x01)  */
#define TT_I3C_SINTCLR_CHANDLED_Pos   (17UL)                    /*!< TT_I3C SINTCLR: CHANDLED (Bit 17)                 */
#define TT_I3C_SINTCLR_CHANDLED_Msk   (0x20000UL)               /*!< TT_I3C SINTCLR: CHANDLED (Bitfield-Mask: 0x01)    */
#define TT_I3C_SINTCLR_EVENT_Pos      (18UL)                    /*!< TT_I3C SINTCLR: EVENT (Bit 18)                    */
#define TT_I3C_SINTCLR_EVENT_Msk      (0x40000UL)               /*!< TT_I3C SINTCLR: EVENT (Bitfield-Mask: 0x01)       */
#define TT_I3C_SINTCLR_TGTRST_Pos     (19UL)                    /*!< TT_I3C SINTCLR: TGTRST (Bit 19)                   */
#define TT_I3C_SINTCLR_TGTRST_Msk     (0x80000UL)               /*!< TT_I3C SINTCLR: TGTRST (Bitfield-Mask: 0x01)      */
/* ======================================================  SINTMASKED  ======================================================= */
#define TT_I3C_SINTMASKED_START_Pos   (8UL)                     /*!< TT_I3C SINTMASKED: START (Bit 8)                  */
#define TT_I3C_SINTMASKED_START_Msk   (0x100UL)                 /*!< TT_I3C SINTMASKED: START (Bitfield-Mask: 0x01)    */
#define TT_I3C_SINTMASKED_MATCHED_Pos (9UL)                     /*!< TT_I3C SINTMASKED: MATCHED (Bit 9)                */
#define TT_I3C_SINTMASKED_MATCHED_Msk (0x200UL)                 /*!< TT_I3C SINTMASKED: MATCHED (Bitfield-Mask: 0x01)  */
#define TT_I3C_SINTMASKED_STOP_Pos    (10UL)                    /*!< TT_I3C SINTMASKED: STOP (Bit 10)                  */
#define TT_I3C_SINTMASKED_STOP_Msk    (0x400UL)                 /*!< TT_I3C SINTMASKED: STOP (Bitfield-Mask: 0x01)     */
#define TT_I3C_SINTMASKED_RXPEND_Pos  (11UL)                    /*!< TT_I3C SINTMASKED: RXPEND (Bit 11)                */
#define TT_I3C_SINTMASKED_RXPEND_Msk  (0x800UL)                 /*!< TT_I3C SINTMASKED: RXPEND (Bitfield-Mask: 0x01)   */
#define TT_I3C_SINTMASKED_TXSEND_Pos  (12UL)                    /*!< TT_I3C SINTMASKED: TXSEND (Bit 12)                */
#define TT_I3C_SINTMASKED_TXSEND_Msk  (0x1000UL)                /*!< TT_I3C SINTMASKED: TXSEND (Bitfield-Mask: 0x01)   */
#define TT_I3C_SINTMASKED_DACHG_Pos   (13UL)                    /*!< TT_I3C SINTMASKED: DACHG (Bit 13)                 */
#define TT_I3C_SINTMASKED_DACHG_Msk   (0x2000UL)                /*!< TT_I3C SINTMASKED: DACHG (Bitfield-Mask: 0x01)    */
#define TT_I3C_SINTMASKED_CCC_Pos     (14UL)                    /*!< TT_I3C SINTMASKED: CCC (Bit 14)                   */
#define TT_I3C_SINTMASKED_CCC_Msk     (0x4000UL)                /*!< TT_I3C SINTMASKED: CCC (Bitfield-Mask: 0x01)      */
#define TT_I3C_SINTMASKED_ERRWARN_Pos (15UL)                    /*!< TT_I3C SINTMASKED: ERRWARN (Bit 15)               */
#define TT_I3C_SINTMASKED_ERRWARN_Msk (0x8000UL)                /*!< TT_I3C SINTMASKED: ERRWARN (Bitfield-Mask: 0x01)  */
#define TT_I3C_SINTMASKED_DDRMATCHED_Pos (16UL)                 /*!< TT_I3C SINTMASKED: DDRMATCHED (Bit 16)            */
#define TT_I3C_SINTMASKED_DDRMATCHED_Msk (0x10000UL)            /*!< TT_I3C SINTMASKED: DDRMATCHED (Bitfield-Mask: 0x01) */
#define TT_I3C_SINTMASKED_CHANDLED_Pos (17UL)                   /*!< TT_I3C SINTMASKED: CHANDLED (Bit 17)              */
#define TT_I3C_SINTMASKED_CHANDLED_Msk (0x20000UL)              /*!< TT_I3C SINTMASKED: CHANDLED (Bitfield-Mask: 0x01) */
#define TT_I3C_SINTMASKED_EVENT_Pos   (18UL)                    /*!< TT_I3C SINTMASKED: EVENT (Bit 18)                 */
#define TT_I3C_SINTMASKED_EVENT_Msk   (0x40000UL)               /*!< TT_I3C SINTMASKED: EVENT (Bitfield-Mask: 0x01)    */
#define TT_I3C_SINTMASKED_TGTRST_Pos  (19UL)                    /*!< TT_I3C SINTMASKED: TGTRST (Bit 19)                */
#define TT_I3C_SINTMASKED_TGTRST_Msk  (0x80000UL)               /*!< TT_I3C SINTMASKED: TGTRST (Bitfield-Mask: 0x01)   */
/* =======================================================  SERRWARN  ======================================================== */
#define TT_I3C_SERRWARN_ORUN_Pos      (0UL)                     /*!< TT_I3C SERRWARN: ORUN (Bit 0)                     */
#define TT_I3C_SERRWARN_ORUN_Msk      (0x1UL)                   /*!< TT_I3C SERRWARN: ORUN (Bitfield-Mask: 0x01)       */
#define TT_I3C_SERRWARN_URUN_Pos      (1UL)                     /*!< TT_I3C SERRWARN: URUN (Bit 1)                     */
#define TT_I3C_SERRWARN_URUN_Msk      (0x2UL)                   /*!< TT_I3C SERRWARN: URUN (Bitfield-Mask: 0x01)       */
#define TT_I3C_SERRWARN_URUNNACK_Pos  (2UL)                     /*!< TT_I3C SERRWARN: URUNNACK (Bit 2)                 */
#define TT_I3C_SERRWARN_URUNNACK_Msk  (0x4UL)                   /*!< TT_I3C SERRWARN: URUNNACK (Bitfield-Mask: 0x01)   */
#define TT_I3C_SERRWARN_TERM_Pos      (3UL)                     /*!< TT_I3C SERRWARN: TERM (Bit 3)                     */
#define TT_I3C_SERRWARN_TERM_Msk      (0x8UL)                   /*!< TT_I3C SERRWARN: TERM (Bitfield-Mask: 0x01)       */
#define TT_I3C_SERRWARN_INVSTART_Pos  (4UL)                     /*!< TT_I3C SERRWARN: INVSTART (Bit 4)                 */
#define TT_I3C_SERRWARN_INVSTART_Msk  (0x10UL)                  /*!< TT_I3C SERRWARN: INVSTART (Bitfield-Mask: 0x01)   */
#define TT_I3C_SERRWARN_SPAR_Pos      (8UL)                     /*!< TT_I3C SERRWARN: SPAR (Bit 8)                     */
#define TT_I3C_SERRWARN_SPAR_Msk      (0x100UL)                 /*!< TT_I3C SERRWARN: SPAR (Bitfield-Mask: 0x01)       */
#define TT_I3C_SERRWARN_HPAR_Pos      (9UL)                     /*!< TT_I3C SERRWARN: HPAR (Bit 9)                     */
#define TT_I3C_SERRWARN_HPAR_Msk      (0x200UL)                 /*!< TT_I3C SERRWARN: HPAR (Bitfield-Mask: 0x01)       */
#define TT_I3C_SERRWARN_HCRC_Pos      (10UL)                    /*!< TT_I3C SERRWARN: HCRC (Bit 10)                    */
#define TT_I3C_SERRWARN_HCRC_Msk      (0x400UL)                 /*!< TT_I3C SERRWARN: HCRC (Bitfield-Mask: 0x01)       */
#define TT_I3C_SERRWARN_S0S1_Pos      (11UL)                    /*!< TT_I3C SERRWARN: S0S1 (Bit 11)                    */
#define TT_I3C_SERRWARN_S0S1_Msk      (0x800UL)                 /*!< TT_I3C SERRWARN: S0S1 (Bitfield-Mask: 0x01)       */
#define TT_I3C_SERRWARN_HNOVERIFY_Pos (12UL)                    /*!< TT_I3C SERRWARN: HNOVERIFY (Bit 12)               */
#define TT_I3C_SERRWARN_HNOVERIFY_Msk (0x1000UL)                /*!< TT_I3C SERRWARN: HNOVERIFY (Bitfield-Mask: 0x01)  */
#define TT_I3C_SERRWARN_HINVREQ_Pos   (13UL)                    /*!< TT_I3C SERRWARN: HINVREQ (Bit 13)                 */
#define TT_I3C_SERRWARN_HINVREQ_Msk   (0x2000UL)                /*!< TT_I3C SERRWARN: HINVREQ (Bitfield-Mask: 0x01)    */
#define TT_I3C_SERRWARN_OREAD_Pos     (16UL)                    /*!< TT_I3C SERRWARN: OREAD (Bit 16)                   */
#define TT_I3C_SERRWARN_OREAD_Msk     (0x10000UL)               /*!< TT_I3C SERRWARN: OREAD (Bitfield-Mask: 0x01)      */
#define TT_I3C_SERRWARN_OWRITE_Pos    (17UL)                    /*!< TT_I3C SERRWARN: OWRITE (Bit 17)                  */
#define TT_I3C_SERRWARN_OWRITE_Msk    (0x20000UL)               /*!< TT_I3C SERRWARN: OWRITE (Bitfield-Mask: 0x01)     */
#define TT_I3C_SERRWARN_WRONGSIZE_Pos (21UL)                    /*!< TT_I3C SERRWARN: WRONGSIZE (Bit 21)               */
#define TT_I3C_SERRWARN_WRONGSIZE_Msk (0x200000UL)              /*!< TT_I3C SERRWARN: WRONGSIZE (Bitfield-Mask: 0x01)  */
/* =======================================================  SDMACTRL  ======================================================== */
#define TT_I3C_SDMACTRL_DMAFB_Pos     (0UL)                     /*!< TT_I3C SDMACTRL: DMAFB (Bit 0)                    */
#define TT_I3C_SDMACTRL_DMAFB_Msk     (0x3UL)                   /*!< TT_I3C SDMACTRL: DMAFB (Bitfield-Mask: 0x03)      */
#define TT_I3C_SDMACTRL_DMATB_Pos     (2UL)                     /*!< TT_I3C SDMACTRL: DMATB (Bit 2)                    */
#define TT_I3C_SDMACTRL_DMATB_Msk     (0xcUL)                   /*!< TT_I3C SDMACTRL: DMATB (Bitfield-Mask: 0x03)      */
#define TT_I3C_SDMACTRL_DMAWIDTH_Pos  (4UL)                     /*!< TT_I3C SDMACTRL: DMAWIDTH (Bit 4)                 */
#define TT_I3C_SDMACTRL_DMAWIDTH_Msk  (0x30UL)                  /*!< TT_I3C SDMACTRL: DMAWIDTH (Bitfield-Mask: 0x03)   */
/* =======================================================  HDRBTCFG  ======================================================== */
#define TT_I3C_HDRBTCFG_CRC32_Pos     (2UL)                     /*!< TT_I3C HDRBTCFG: CRC32 (Bit 2)                    */
#define TT_I3C_HDRBTCFG_CRC32_Msk     (0x4UL)                   /*!< TT_I3C HDRBTCFG: CRC32 (Bitfield-Mask: 0x01)      */
#define TT_I3C_HDRBTCFG_WDATAMAX_Pos  (4UL)                     /*!< TT_I3C HDRBTCFG: WDATAMAX (Bit 4)                 */
#define TT_I3C_HDRBTCFG_WDATAMAX_Msk  (0xfff0UL)                /*!< TT_I3C HDRBTCFG: WDATAMAX (Bitfield-Mask: 0xfff)  */
#define TT_I3C_HDRBTCFG_RDATALEN_Pos  (16UL)                    /*!< TT_I3C HDRBTCFG: RDATALEN (Bit 16)                */
#define TT_I3C_HDRBTCFG_RDATALEN_Msk  (0xffff0000UL)            /*!< TT_I3C HDRBTCFG: RDATALEN (Bitfield-Mask: 0xffff) */
/* =======================================================  HDRBTLAST  ======================================================= */
#define TT_I3C_HDRBTLAST_DATALEN_Pos  (16UL)                    /*!< TT_I3C HDRBTLAST: DATALEN (Bit 16)                */
#define TT_I3C_HDRBTLAST_DATALEN_Msk  (0xffff0000UL)            /*!< TT_I3C HDRBTLAST: DATALEN (Bitfield-Mask: 0xffff) */
/* =======================================================  SDATACTRL  ======================================================= */
#define TT_I3C_SDATACTRL_FLUSHTB_Pos  (0UL)                     /*!< TT_I3C SDATACTRL: FLUSHTB (Bit 0)                 */
#define TT_I3C_SDATACTRL_FLUSHTB_Msk  (0x1UL)                   /*!< TT_I3C SDATACTRL: FLUSHTB (Bitfield-Mask: 0x01)   */
#define TT_I3C_SDATACTRL_FLUSHFB_Pos  (1UL)                     /*!< TT_I3C SDATACTRL: FLUSHFB (Bit 1)                 */
#define TT_I3C_SDATACTRL_FLUSHFB_Msk  (0x2UL)                   /*!< TT_I3C SDATACTRL: FLUSHFB (Bitfield-Mask: 0x01)   */
#define TT_I3C_SDATACTRL_UNLOCK_Pos   (3UL)                     /*!< TT_I3C SDATACTRL: UNLOCK (Bit 3)                  */
#define TT_I3C_SDATACTRL_UNLOCK_Msk   (0x8UL)                   /*!< TT_I3C SDATACTRL: UNLOCK (Bitfield-Mask: 0x01)    */
#define TT_I3C_SDATACTRL_TXTRIG_Pos   (4UL)                     /*!< TT_I3C SDATACTRL: TXTRIG (Bit 4)                  */
#define TT_I3C_SDATACTRL_TXTRIG_Msk   (0x30UL)                  /*!< TT_I3C SDATACTRL: TXTRIG (Bitfield-Mask: 0x03)    */
#define TT_I3C_SDATACTRL_RXTRIG_Pos   (6UL)                     /*!< TT_I3C SDATACTRL: RXTRIG (Bit 6)                  */
#define TT_I3C_SDATACTRL_RXTRIG_Msk   (0xc0UL)                  /*!< TT_I3C SDATACTRL: RXTRIG (Bitfield-Mask: 0x03)    */
#define TT_I3C_SDATACTRL_TXCOUNT_Pos  (16UL)                    /*!< TT_I3C SDATACTRL: TXCOUNT (Bit 16)                */
#define TT_I3C_SDATACTRL_TXCOUNT_Msk  (0x1f0000UL)              /*!< TT_I3C SDATACTRL: TXCOUNT (Bitfield-Mask: 0x1f)   */
#define TT_I3C_SDATACTRL_RXCOUNT_Pos  (24UL)                    /*!< TT_I3C SDATACTRL: RXCOUNT (Bit 24)                */
#define TT_I3C_SDATACTRL_RXCOUNT_Msk  (0x1f000000UL)            /*!< TT_I3C SDATACTRL: RXCOUNT (Bitfield-Mask: 0x1f)   */
#define TT_I3C_SDATACTRL_TXFULL_Pos   (30UL)                    /*!< TT_I3C SDATACTRL: TXFULL (Bit 30)                 */
#define TT_I3C_SDATACTRL_TXFULL_Msk   (0x40000000UL)            /*!< TT_I3C SDATACTRL: TXFULL (Bitfield-Mask: 0x01)    */
#define TT_I3C_SDATACTRL_RXEMPTY_Pos  (31UL)                    /*!< TT_I3C SDATACTRL: RXEMPTY (Bit 31)                */
#define TT_I3C_SDATACTRL_RXEMPTY_Msk  (0x80000000UL)            /*!< TT_I3C SDATACTRL: RXEMPTY (Bitfield-Mask: 0x01)   */
/* ========================================================  SWDATAB  ======================================================== */
#define TT_I3C_SWDATAB_DATA_Pos       (0UL)                     /*!< TT_I3C SWDATAB: DATA (Bit 0)                      */
#define TT_I3C_SWDATAB_DATA_Msk       (0xffUL)                  /*!< TT_I3C SWDATAB: DATA (Bitfield-Mask: 0xff)        */
#define TT_I3C_SWDATAB_END_Pos        (8UL)                     /*!< TT_I3C SWDATAB: END (Bit 8)                       */
#define TT_I3C_SWDATAB_END_Msk        (0x100UL)                 /*!< TT_I3C SWDATAB: END (Bitfield-Mask: 0x01)         */
#define TT_I3C_SWDATAB_END_ALSO_Pos   (16UL)                    /*!< TT_I3C SWDATAB: END_ALSO (Bit 16)                 */
#define TT_I3C_SWDATAB_END_ALSO_Msk   (0x10000UL)               /*!< TT_I3C SWDATAB: END_ALSO (Bitfield-Mask: 0x01)    */
/* =======================================================  SWDATABE  ======================================================== */
#define TT_I3C_SWDATABE_DATA_Pos      (0UL)                     /*!< TT_I3C SWDATABE: DATA (Bit 0)                     */
#define TT_I3C_SWDATABE_DATA_Msk      (0xffUL)                  /*!< TT_I3C SWDATABE: DATA (Bitfield-Mask: 0xff)       */
/* ========================================================  SWDATAH  ======================================================== */
#define TT_I3C_SWDATAH_DATA0_Pos      (0UL)                     /*!< TT_I3C SWDATAH: DATA0 (Bit 0)                     */
#define TT_I3C_SWDATAH_DATA0_Msk      (0xffUL)                  /*!< TT_I3C SWDATAH: DATA0 (Bitfield-Mask: 0xff)       */
#define TT_I3C_SWDATAH_DATA1_Pos      (8UL)                     /*!< TT_I3C SWDATAH: DATA1 (Bit 8)                     */
#define TT_I3C_SWDATAH_DATA1_Msk      (0xff00UL)                /*!< TT_I3C SWDATAH: DATA1 (Bitfield-Mask: 0xff)       */
#define TT_I3C_SWDATAH_END_Pos        (16UL)                    /*!< TT_I3C SWDATAH: END (Bit 16)                      */
#define TT_I3C_SWDATAH_END_Msk        (0x10000UL)               /*!< TT_I3C SWDATAH: END (Bitfield-Mask: 0x01)         */
/* =======================================================  SWDATAHE  ======================================================== */
#define TT_I3C_SWDATAHE_DATA0_Pos     (0UL)                     /*!< TT_I3C SWDATAHE: DATA0 (Bit 0)                    */
#define TT_I3C_SWDATAHE_DATA0_Msk     (0xffUL)                  /*!< TT_I3C SWDATAHE: DATA0 (Bitfield-Mask: 0xff)      */
#define TT_I3C_SWDATAHE_DATA1_Pos     (8UL)                     /*!< TT_I3C SWDATAHE: DATA1 (Bit 8)                    */
#define TT_I3C_SWDATAHE_DATA1_Msk     (0xff00UL)                /*!< TT_I3C SWDATAHE: DATA1 (Bitfield-Mask: 0xff)      */
/* ========================================================  SRDATAB  ======================================================== */
#define TT_I3C_SRDATAB_DATA0_Pos      (0UL)                     /*!< TT_I3C SRDATAB: DATA0 (Bit 0)                     */
#define TT_I3C_SRDATAB_DATA0_Msk      (0xffUL)                  /*!< TT_I3C SRDATAB: DATA0 (Bitfield-Mask: 0xff)       */
/* ========================================================  SRDATAH  ======================================================== */
#define TT_I3C_SRDATAH_LSB_Pos        (0UL)                     /*!< TT_I3C SRDATAH: LSB (Bit 0)                       */
#define TT_I3C_SRDATAH_LSB_Msk        (0xffUL)                  /*!< TT_I3C SRDATAH: LSB (Bitfield-Mask: 0xff)         */
#define TT_I3C_SRDATAH_MSB_Pos        (8UL)                     /*!< TT_I3C SRDATAH: MSB (Bit 8)                       */
#define TT_I3C_SRDATAH_MSB_Msk        (0xff00UL)                /*!< TT_I3C SRDATAH: MSB (Bitfield-Mask: 0xff)         */
/* ========================================================  WDATAB1  ======================================================== */
#define TT_I3C_WDATAB1_DATA_Pos       (0UL)                     /*!< TT_I3C WDATAB1: DATA (Bit 0)                      */
#define TT_I3C_WDATAB1_DATA_Msk       (0xffUL)                  /*!< TT_I3C WDATAB1: DATA (Bitfield-Mask: 0xff)        */
/* ====================================================  SCAPABILITIES2  ===================================================== */
#define TT_I3C_SCAPABILITIES2_MAPCNT_Pos (0UL)                  /*!< TT_I3C SCAPABILITIES2: MAPCNT (Bit 0)             */
#define TT_I3C_SCAPABILITIES2_MAPCNT_Msk (0xfUL)                /*!< TT_I3C SCAPABILITIES2: MAPCNT (Bitfield-Mask: 0x0f) */
#define TT_I3C_SCAPABILITIES2_I2C10B_Pos (4UL)                  /*!< TT_I3C SCAPABILITIES2: I2C10B (Bit 4)             */
#define TT_I3C_SCAPABILITIES2_I2C10B_Msk (0x10UL)               /*!< TT_I3C SCAPABILITIES2: I2C10B (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_I2CRST_Pos (5UL)                  /*!< TT_I3C SCAPABILITIES2: I2CRST (Bit 5)             */
#define TT_I3C_SCAPABILITIES2_I2CRST_Msk (0x20UL)               /*!< TT_I3C SCAPABILITIES2: I2CRST (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_I2CDEVID_Pos (6UL)                /*!< TT_I3C SCAPABILITIES2: I2CDEVID (Bit 6)           */
#define TT_I3C_SCAPABILITIES2_I2CDEVID_Msk (0x40UL)             /*!< TT_I3C SCAPABILITIES2: I2CDEVID (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_DATA32_Pos (7UL)                  /*!< TT_I3C SCAPABILITIES2: DATA32 (Bit 7)             */
#define TT_I3C_SCAPABILITIES2_DATA32_Msk (0x80UL)               /*!< TT_I3C SCAPABILITIES2: DATA32 (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_IBIEXT_Pos (8UL)                  /*!< TT_I3C SCAPABILITIES2: IBIEXT (Bit 8)             */
#define TT_I3C_SCAPABILITIES2_IBIEXT_Msk (0x100UL)              /*!< TT_I3C SCAPABILITIES2: IBIEXT (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_IBIXREG_Pos (9UL)                 /*!< TT_I3C SCAPABILITIES2: IBIXREG (Bit 9)            */
#define TT_I3C_SCAPABILITIES2_IBIXREG_Msk (0x200UL)             /*!< TT_I3C SCAPABILITIES2: IBIXREG (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_SMLANE_Pos (12UL)                 /*!< TT_I3C SCAPABILITIES2: SMLANE (Bit 12)            */
#define TT_I3C_SCAPABILITIES2_SMLANE_Msk (0x3000UL)             /*!< TT_I3C SCAPABILITIES2: SMLANE (Bitfield-Mask: 0x03) */
#define TT_I3C_SCAPABILITIES2_V1_1_Pos (16UL)                   /*!< TT_I3C SCAPABILITIES2: V1_1 (Bit 16)              */
#define TT_I3C_SCAPABILITIES2_V1_1_Msk (0x10000UL)              /*!< TT_I3C SCAPABILITIES2: V1_1 (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_TGTRST_Pos (17UL)                 /*!< TT_I3C SCAPABILITIES2: TGTRST (Bit 17)            */
#define TT_I3C_SCAPABILITIES2_TGTRST_Msk (0x20000UL)            /*!< TT_I3C SCAPABILITIES2: TGTRST (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_GROUP_Pos (18UL)                  /*!< TT_I3C SCAPABILITIES2: GROUP (Bit 18)             */
#define TT_I3C_SCAPABILITIES2_GROUP_Msk (0xc0000UL)             /*!< TT_I3C SCAPABILITIES2: GROUP (Bitfield-Mask: 0x03) */
#define TT_I3C_SCAPABILITIES2_AASA_Pos (21UL)                   /*!< TT_I3C SCAPABILITIES2: AASA (Bit 21)              */
#define TT_I3C_SCAPABILITIES2_AASA_Msk (0x200000UL)             /*!< TT_I3C SCAPABILITIES2: AASA (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_SSTSUB_Pos (22UL)                 /*!< TT_I3C SCAPABILITIES2: SSTSUB (Bit 22)            */
#define TT_I3C_SCAPABILITIES2_SSTSUB_Msk (0x400000UL)           /*!< TT_I3C SCAPABILITIES2: SSTSUB (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES2_SSTWR_Pos (23UL)                  /*!< TT_I3C SCAPABILITIES2: SSTWR (Bit 23)             */
#define TT_I3C_SCAPABILITIES2_SSTWR_Msk (0x800000UL)            /*!< TT_I3C SCAPABILITIES2: SSTWR (Bitfield-Mask: 0x01) */
/* =====================================================  SCAPABILITIES  ===================================================== */
#define TT_I3C_SCAPABILITIES_IDENA_Pos (0UL)                    /*!< TT_I3C SCAPABILITIES: IDENA (Bit 0)               */
#define TT_I3C_SCAPABILITIES_IDENA_Msk (0x3UL)                  /*!< TT_I3C SCAPABILITIES: IDENA (Bitfield-Mask: 0x03) */
#define TT_I3C_SCAPABILITIES_IDREG_Pos (2UL)                    /*!< TT_I3C SCAPABILITIES: IDREG (Bit 2)               */
#define TT_I3C_SCAPABILITIES_IDREG_Msk (0x3cUL)                 /*!< TT_I3C SCAPABILITIES: IDREG (Bitfield-Mask: 0x0f) */
#define TT_I3C_SCAPABILITIES_HDRSUPP_Pos (6UL)                  /*!< TT_I3C SCAPABILITIES: HDRSUPP (Bit 6)             */
#define TT_I3C_SCAPABILITIES_HDRSUPP_Msk (0x1c0UL)              /*!< TT_I3C SCAPABILITIES: HDRSUPP (Bitfield-Mask: 0x07) */
#define TT_I3C_SCAPABILITIES_MASTER_Pos (9UL)                   /*!< TT_I3C SCAPABILITIES: MASTER (Bit 9)              */
#define TT_I3C_SCAPABILITIES_MASTER_Msk (0x200UL)               /*!< TT_I3C SCAPABILITIES: MASTER (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES_SADDR_Pos (10UL)                   /*!< TT_I3C SCAPABILITIES: SADDR (Bit 10)              */
#define TT_I3C_SCAPABILITIES_SADDR_Msk (0xc00UL)                /*!< TT_I3C SCAPABILITIES: SADDR (Bitfield-Mask: 0x03) */
#define TT_I3C_SCAPABILITIES_CCCHANDLE_Pos (12UL)               /*!< TT_I3C SCAPABILITIES: CCCHANDLE (Bit 12)          */
#define TT_I3C_SCAPABILITIES_CCCHANDLE_Msk (0xf000UL)           /*!< TT_I3C SCAPABILITIES: CCCHANDLE (Bitfield-Mask: 0x0f) */
#define TT_I3C_SCAPABILITIES_IBI_MR_HJ_Pos (16UL)               /*!< TT_I3C SCAPABILITIES: IBI_MR_HJ (Bit 16)          */
#define TT_I3C_SCAPABILITIES_IBI_MR_HJ_Msk (0x1f0000UL)         /*!< TT_I3C SCAPABILITIES: IBI_MR_HJ (Bitfield-Mask: 0x1f) */
#define TT_I3C_SCAPABILITIES_TIMECTRL_Pos (21UL)                /*!< TT_I3C SCAPABILITIES: TIMECTRL (Bit 21)           */
#define TT_I3C_SCAPABILITIES_TIMECTRL_Msk (0x200000UL)          /*!< TT_I3C SCAPABILITIES: TIMECTRL (Bitfield-Mask: 0x01) */
#define TT_I3C_SCAPABILITIES_EXTFIFO_Pos (23UL)                 /*!< TT_I3C SCAPABILITIES: EXTFIFO (Bit 23)            */
#define TT_I3C_SCAPABILITIES_EXTFIFO_Msk (0x3800000UL)          /*!< TT_I3C SCAPABILITIES: EXTFIFO (Bitfield-Mask: 0x07) */
#define TT_I3C_SCAPABILITIES_FIFOTX_Pos (26UL)                  /*!< TT_I3C SCAPABILITIES: FIFOTX (Bit 26)             */
#define TT_I3C_SCAPABILITIES_FIFOTX_Msk (0xc000000UL)           /*!< TT_I3C SCAPABILITIES: FIFOTX (Bitfield-Mask: 0x03) */
#define TT_I3C_SCAPABILITIES_FIFORX_Pos (28UL)                  /*!< TT_I3C SCAPABILITIES: FIFORX (Bit 28)             */
#define TT_I3C_SCAPABILITIES_FIFORX_Msk (0x30000000UL)          /*!< TT_I3C SCAPABILITIES: FIFORX (Bitfield-Mask: 0x03) */
#define TT_I3C_SCAPABILITIES_INT_Pos  (30UL)                    /*!< TT_I3C SCAPABILITIES: INT (Bit 30)                */
#define TT_I3C_SCAPABILITIES_INT_Msk  (0x40000000UL)            /*!< TT_I3C SCAPABILITIES: INT (Bitfield-Mask: 0x01)   */
#define TT_I3C_SCAPABILITIES_DMA_Pos  (31UL)                    /*!< TT_I3C SCAPABILITIES: DMA (Bit 31)                */
#define TT_I3C_SCAPABILITIES_DMA_Msk  (0x80000000UL)            /*!< TT_I3C SCAPABILITIES: DMA (Bitfield-Mask: 0x01)   */
/* =======================================================  SDYNADDR  ======================================================== */
#define TT_I3C_SDYNADDR_DAVALID_Pos   (0UL)                     /*!< TT_I3C SDYNADDR: DAVALID (Bit 0)                  */
#define TT_I3C_SDYNADDR_DAVALID_Msk   (0x1UL)                   /*!< TT_I3C SDYNADDR: DAVALID (Bitfield-Mask: 0x01)    */
#define TT_I3C_SDYNADDR_DADDR_Pos     (1UL)                     /*!< TT_I3C SDYNADDR: DADDR (Bit 1)                    */
#define TT_I3C_SDYNADDR_DADDR_Msk     (0xfeUL)                  /*!< TT_I3C SDYNADDR: DADDR (Bitfield-Mask: 0x7f)      */
/* ======================================================  SMAXLIMITS  ======================================================= */
#define TT_I3C_SMAXLIMITS_MAXRD_Pos   (0UL)                     /*!< TT_I3C SMAXLIMITS: MAXRD (Bit 0)                  */
#define TT_I3C_SMAXLIMITS_MAXRD_Msk   (0xfffUL)                 /*!< TT_I3C SMAXLIMITS: MAXRD (Bitfield-Mask: 0xfff)   */
#define TT_I3C_SMAXLIMITS_MAXWR_Pos   (16UL)                    /*!< TT_I3C SMAXLIMITS: MAXWR (Bit 16)                 */
#define TT_I3C_SMAXLIMITS_MAXWR_Msk   (0xfff0000UL)             /*!< TT_I3C SMAXLIMITS: MAXWR (Bitfield-Mask: 0xfff)   */
/* =======================================================  SIDPARTNO  ======================================================= */
#define TT_I3C_SIDPARTNO_VENDDEF_Pos  (0UL)                     /*!< TT_I3C SIDPARTNO: VENDDEF (Bit 0)                 */
#define TT_I3C_SIDPARTNO_VENDDEF_Msk  (0xfffUL)                 /*!< TT_I3C SIDPARTNO: VENDDEF (Bitfield-Mask: 0xfff)  */
#define TT_I3C_SIDPARTNO_INSTID_Pos   (12UL)                    /*!< TT_I3C SIDPARTNO: INSTID (Bit 12)                 */
#define TT_I3C_SIDPARTNO_INSTID_Msk   (0xf000UL)                /*!< TT_I3C SIDPARTNO: INSTID (Bitfield-Mask: 0x0f)    */
#define TT_I3C_SIDPARTNO_PARTID_Pos   (16UL)                    /*!< TT_I3C SIDPARTNO: PARTID (Bit 16)                 */
#define TT_I3C_SIDPARTNO_PARTID_Msk   (0xffff0000UL)            /*!< TT_I3C SIDPARTNO: PARTID (Bitfield-Mask: 0xffff)  */
/* ========================================================  SIDEXT  ========================================================= */
#define TT_I3C_SIDEXT_INSTANCE_Pos    (0UL)                     /*!< TT_I3C SIDEXT: INSTANCE (Bit 0)                   */
#define TT_I3C_SIDEXT_INSTANCE_Msk    (0xfUL)                   /*!< TT_I3C SIDEXT: INSTANCE (Bitfield-Mask: 0x0f)     */
#define TT_I3C_SIDEXT_DCR_Pos         (8UL)                     /*!< TT_I3C SIDEXT: DCR (Bit 8)                        */
#define TT_I3C_SIDEXT_DCR_Msk         (0xff00UL)                /*!< TT_I3C SIDEXT: DCR (Bitfield-Mask: 0xff)          */
#define TT_I3C_SIDEXT_BCR_Pos         (16UL)                    /*!< TT_I3C SIDEXT: BCR (Bit 16)                       */
#define TT_I3C_SIDEXT_BCR_Msk         (0xff0000UL)              /*!< TT_I3C SIDEXT: BCR (Bitfield-Mask: 0xff)          */
/* =======================================================  SVENDORID  ======================================================= */
#define TT_I3C_SVENDORID_VID_Pos      (0UL)                     /*!< TT_I3C SVENDORID: VID (Bit 0)                     */
#define TT_I3C_SVENDORID_VID_Msk      (0x7fffUL)                /*!< TT_I3C SVENDORID: VID (Bitfield-Mask: 0x7fff)     */
/* =======================================================  STCCLOCK  ======================================================== */
#define TT_I3C_STCCLOCK_ACCURACY_Pos  (0UL)                     /*!< TT_I3C STCCLOCK: ACCURACY (Bit 0)                 */
#define TT_I3C_STCCLOCK_ACCURACY_Msk  (0xffUL)                  /*!< TT_I3C STCCLOCK: ACCURACY (Bitfield-Mask: 0xff)   */
#define TT_I3C_STCCLOCK_FREQ_Pos      (8UL)                     /*!< TT_I3C STCCLOCK: FREQ (Bit 8)                     */
#define TT_I3C_STCCLOCK_FREQ_Msk      (0xff00UL)                /*!< TT_I3C STCCLOCK: FREQ (Bitfield-Mask: 0xff)       */
/* =======================================================  SMSGLAST  ======================================================== */
#define TT_I3C_SMSGLAST_LASTSTATIC_Pos (4UL)                    /*!< TT_I3C SMSGLAST: LASTSTATIC (Bit 4)               */
#define TT_I3C_SMSGLAST_LASTSTATIC_Msk (0x10UL)                 /*!< TT_I3C SMSGLAST: LASTSTATIC (Bitfield-Mask: 0x01) */
#define TT_I3C_SMSGLAST_LASTMODE_Pos  (6UL)                     /*!< TT_I3C SMSGLAST: LASTMODE (Bit 6)                 */
#define TT_I3C_SMSGLAST_LASTMODE_Msk  (0xc0UL)                  /*!< TT_I3C SMSGLAST: LASTMODE (Bitfield-Mask: 0x03)   */
#define TT_I3C_SMSGLAST_LASTMODE1_Pos (14UL)                    /*!< TT_I3C SMSGLAST: LASTMODE1 (Bit 14)               */
#define TT_I3C_SMSGLAST_LASTMODE1_Msk (0xc000UL)                /*!< TT_I3C SMSGLAST: LASTMODE1 (Bitfield-Mask: 0x03)  */
#define TT_I3C_SMSGLAST_LASTMODE2_Pos (22UL)                    /*!< TT_I3C SMSGLAST: LASTMODE2 (Bit 22)               */
#define TT_I3C_SMSGLAST_LASTMODE2_Msk (0xc00000UL)              /*!< TT_I3C SMSGLAST: LASTMODE2 (Bitfield-Mask: 0x03)  */
/* =========================================================  MCTRL  ========================================================= */
#define TT_I3C_MCTRL_REQUEST_Pos      (0UL)                     /*!< TT_I3C MCTRL: REQUEST (Bit 0)                     */
#define TT_I3C_MCTRL_REQUEST_Msk      (0x7UL)                   /*!< TT_I3C MCTRL: REQUEST (Bitfield-Mask: 0x07)       */
#define TT_I3C_MCTRL_TYPE_Pos         (4UL)                     /*!< TT_I3C MCTRL: TYPE (Bit 4)                        */
#define TT_I3C_MCTRL_TYPE_Msk         (0x30UL)                  /*!< TT_I3C MCTRL: TYPE (Bitfield-Mask: 0x03)          */
#define TT_I3C_MCTRL_IBIRESP_Pos      (6UL)                     /*!< TT_I3C MCTRL: IBIRESP (Bit 6)                     */
#define TT_I3C_MCTRL_IBIRESP_Msk      (0xc0UL)                  /*!< TT_I3C MCTRL: IBIRESP (Bitfield-Mask: 0x03)       */
#define TT_I3C_MCTRL_DIR_Pos          (8UL)                     /*!< TT_I3C MCTRL: DIR (Bit 8)                         */
#define TT_I3C_MCTRL_DIR_Msk          (0x100UL)                 /*!< TT_I3C MCTRL: DIR (Bitfield-Mask: 0x01)           */
#define TT_I3C_MCTRL_ADDR_Pos         (9UL)                     /*!< TT_I3C MCTRL: ADDR (Bit 9)                        */
#define TT_I3C_MCTRL_ADDR_Msk         (0xfe00UL)                /*!< TT_I3C MCTRL: ADDR (Bitfield-Mask: 0x7f)          */
#define TT_I3C_MCTRL_RDTERM_Pos       (16UL)                    /*!< TT_I3C MCTRL: RDTERM (Bit 16)                     */
#define TT_I3C_MCTRL_RDTERM_Msk       (0xff0000UL)              /*!< TT_I3C MCTRL: RDTERM (Bitfield-Mask: 0xff)        */
/* ========================================================  MSTATUS  ======================================================== */
#define TT_I3C_MSTATUS_STATE_Pos      (0UL)                     /*!< TT_I3C MSTATUS: STATE (Bit 0)                     */
#define TT_I3C_MSTATUS_STATE_Msk      (0x7UL)                   /*!< TT_I3C MSTATUS: STATE (Bitfield-Mask: 0x07)       */
#define TT_I3C_MSTATUS_BETWEEN_Pos    (4UL)                     /*!< TT_I3C MSTATUS: BETWEEN (Bit 4)                   */
#define TT_I3C_MSTATUS_BETWEEN_Msk    (0x10UL)                  /*!< TT_I3C MSTATUS: BETWEEN (Bitfield-Mask: 0x01)     */
#define TT_I3C_MSTATUS_NACKED_Pos     (5UL)                     /*!< TT_I3C MSTATUS: NACKED (Bit 5)                    */
#define TT_I3C_MSTATUS_NACKED_Msk     (0x20UL)                  /*!< TT_I3C MSTATUS: NACKED (Bitfield-Mask: 0x01)      */
#define TT_I3C_MSTATUS_IBITYPE_Pos    (6UL)                     /*!< TT_I3C MSTATUS: IBITYPE (Bit 6)                   */
#define TT_I3C_MSTATUS_IBITYPE_Msk    (0xc0UL)                  /*!< TT_I3C MSTATUS: IBITYPE (Bitfield-Mask: 0x03)     */
#define TT_I3C_MSTATUS_SLVSTART_Pos   (8UL)                     /*!< TT_I3C MSTATUS: SLVSTART (Bit 8)                  */
#define TT_I3C_MSTATUS_SLVSTART_Msk   (0x100UL)                 /*!< TT_I3C MSTATUS: SLVSTART (Bitfield-Mask: 0x01)    */
#define TT_I3C_MSTATUS_MCTRLDONE_Pos  (9UL)                     /*!< TT_I3C MSTATUS: MCTRLDONE (Bit 9)                 */
#define TT_I3C_MSTATUS_MCTRLDONE_Msk  (0x200UL)                 /*!< TT_I3C MSTATUS: MCTRLDONE (Bitfield-Mask: 0x01)   */
#define TT_I3C_MSTATUS_COMPLETE_Pos   (10UL)                    /*!< TT_I3C MSTATUS: COMPLETE (Bit 10)                 */
#define TT_I3C_MSTATUS_COMPLETE_Msk   (0x400UL)                 /*!< TT_I3C MSTATUS: COMPLETE (Bitfield-Mask: 0x01)    */
#define TT_I3C_MSTATUS_RXPEND_Pos     (11UL)                    /*!< TT_I3C MSTATUS: RXPEND (Bit 11)                   */
#define TT_I3C_MSTATUS_RXPEND_Msk     (0x800UL)                 /*!< TT_I3C MSTATUS: RXPEND (Bitfield-Mask: 0x01)      */
#define TT_I3C_MSTATUS_TXNOTFULL_Pos  (12UL)                    /*!< TT_I3C MSTATUS: TXNOTFULL (Bit 12)                */
#define TT_I3C_MSTATUS_TXNOTFULL_Msk  (0x1000UL)                /*!< TT_I3C MSTATUS: TXNOTFULL (Bitfield-Mask: 0x01)   */
#define TT_I3C_MSTATUS_IBIWON_Pos     (13UL)                    /*!< TT_I3C MSTATUS: IBIWON (Bit 13)                   */
#define TT_I3C_MSTATUS_IBIWON_Msk     (0x2000UL)                /*!< TT_I3C MSTATUS: IBIWON (Bitfield-Mask: 0x01)      */
#define TT_I3C_MSTATUS_ERRWARN_Pos    (15UL)                    /*!< TT_I3C MSTATUS: ERRWARN (Bit 15)                  */
#define TT_I3C_MSTATUS_ERRWARN_Msk    (0x8000UL)                /*!< TT_I3C MSTATUS: ERRWARN (Bitfield-Mask: 0x01)     */
#define TT_I3C_MSTATUS_NOWMASTER_Pos  (19UL)                    /*!< TT_I3C MSTATUS: NOWMASTER (Bit 19)                */
#define TT_I3C_MSTATUS_NOWMASTER_Msk  (0x80000UL)               /*!< TT_I3C MSTATUS: NOWMASTER (Bitfield-Mask: 0x01)   */
#define TT_I3C_MSTATUS_IBIADDR_Pos    (24UL)                    /*!< TT_I3C MSTATUS: IBIADDR (Bit 24)                  */
#define TT_I3C_MSTATUS_IBIADDR_Msk    (0x7f000000UL)            /*!< TT_I3C MSTATUS: IBIADDR (Bitfield-Mask: 0x7f)     */
/* =======================================================  MIBIRULES  ======================================================= */
#define TT_I3C_MIBIRULES_ADDR0_Pos    (0UL)                     /*!< TT_I3C MIBIRULES: ADDR0 (Bit 0)                   */
#define TT_I3C_MIBIRULES_ADDR0_Msk    (0x3fUL)                  /*!< TT_I3C MIBIRULES: ADDR0 (Bitfield-Mask: 0x3f)     */
#define TT_I3C_MIBIRULES_ADDR1_Pos    (6UL)                     /*!< TT_I3C MIBIRULES: ADDR1 (Bit 6)                   */
#define TT_I3C_MIBIRULES_ADDR1_Msk    (0xfc0UL)                 /*!< TT_I3C MIBIRULES: ADDR1 (Bitfield-Mask: 0x3f)     */
#define TT_I3C_MIBIRULES_ADDR2_Pos    (12UL)                    /*!< TT_I3C MIBIRULES: ADDR2 (Bit 12)                  */
#define TT_I3C_MIBIRULES_ADDR2_Msk    (0x3f000UL)               /*!< TT_I3C MIBIRULES: ADDR2 (Bitfield-Mask: 0x3f)     */
#define TT_I3C_MIBIRULES_ADDR3_Pos    (18UL)                    /*!< TT_I3C MIBIRULES: ADDR3 (Bit 18)                  */
#define TT_I3C_MIBIRULES_ADDR3_Msk    (0xfc0000UL)              /*!< TT_I3C MIBIRULES: ADDR3 (Bitfield-Mask: 0x3f)     */
#define TT_I3C_MIBIRULES_ADDR4_Pos    (24UL)                    /*!< TT_I3C MIBIRULES: ADDR4 (Bit 24)                  */
#define TT_I3C_MIBIRULES_ADDR4_Msk    (0x3f000000UL)            /*!< TT_I3C MIBIRULES: ADDR4 (Bitfield-Mask: 0x3f)     */
#define TT_I3C_MIBIRULES_MSB0_Pos     (30UL)                    /*!< TT_I3C MIBIRULES: MSB0 (Bit 30)                   */
#define TT_I3C_MIBIRULES_MSB0_Msk     (0x40000000UL)            /*!< TT_I3C MIBIRULES: MSB0 (Bitfield-Mask: 0x01)      */
#define TT_I3C_MIBIRULES_NOBYTE_Pos   (31UL)                    /*!< TT_I3C MIBIRULES: NOBYTE (Bit 31)                 */
#define TT_I3C_MIBIRULES_NOBYTE_Msk   (0x80000000UL)            /*!< TT_I3C MIBIRULES: NOBYTE (Bitfield-Mask: 0x01)    */
/* ========================================================  MINTSET  ======================================================== */
#define TT_I3C_MINTSET_SLVSTART_Pos   (8UL)                     /*!< TT_I3C MINTSET: SLVSTART (Bit 8)                  */
#define TT_I3C_MINTSET_SLVSTART_Msk   (0x100UL)                 /*!< TT_I3C MINTSET: SLVSTART (Bitfield-Mask: 0x01)    */
#define TT_I3C_MINTSET_MCTRLDONE_Pos  (9UL)                     /*!< TT_I3C MINTSET: MCTRLDONE (Bit 9)                 */
#define TT_I3C_MINTSET_MCTRLDONE_Msk  (0x200UL)                 /*!< TT_I3C MINTSET: MCTRLDONE (Bitfield-Mask: 0x01)   */
#define TT_I3C_MINTSET_COMPLETE_Pos   (10UL)                    /*!< TT_I3C MINTSET: COMPLETE (Bit 10)                 */
#define TT_I3C_MINTSET_COMPLETE_Msk   (0x400UL)                 /*!< TT_I3C MINTSET: COMPLETE (Bitfield-Mask: 0x01)    */
#define TT_I3C_MINTSET_RXPEND_Pos     (11UL)                    /*!< TT_I3C MINTSET: RXPEND (Bit 11)                   */
#define TT_I3C_MINTSET_RXPEND_Msk     (0x800UL)                 /*!< TT_I3C MINTSET: RXPEND (Bitfield-Mask: 0x01)      */
#define TT_I3C_MINTSET_TXNOTFULL_Pos  (12UL)                    /*!< TT_I3C MINTSET: TXNOTFULL (Bit 12)                */
#define TT_I3C_MINTSET_TXNOTFULL_Msk  (0x1000UL)                /*!< TT_I3C MINTSET: TXNOTFULL (Bitfield-Mask: 0x01)   */
#define TT_I3C_MINTSET_IBIWON_Pos     (13UL)                    /*!< TT_I3C MINTSET: IBIWON (Bit 13)                   */
#define TT_I3C_MINTSET_IBIWON_Msk     (0x2000UL)                /*!< TT_I3C MINTSET: IBIWON (Bitfield-Mask: 0x01)      */
#define TT_I3C_MINTSET_ERRWARN_Pos    (15UL)                    /*!< TT_I3C MINTSET: ERRWARN (Bit 15)                  */
#define TT_I3C_MINTSET_ERRWARN_Msk    (0x8000UL)                /*!< TT_I3C MINTSET: ERRWARN (Bitfield-Mask: 0x01)     */
#define TT_I3C_MINTSET_NOWMASTER_Pos  (19UL)                    /*!< TT_I3C MINTSET: NOWMASTER (Bit 19)                */
#define TT_I3C_MINTSET_NOWMASTER_Msk  (0x80000UL)               /*!< TT_I3C MINTSET: NOWMASTER (Bitfield-Mask: 0x01)   */
/* ========================================================  MINTCLR  ======================================================== */
#define TT_I3C_MINTCLR_SLVSTART_Pos   (8UL)                     /*!< TT_I3C MINTCLR: SLVSTART (Bit 8)                  */
#define TT_I3C_MINTCLR_SLVSTART_Msk   (0x100UL)                 /*!< TT_I3C MINTCLR: SLVSTART (Bitfield-Mask: 0x01)    */
#define TT_I3C_MINTCLR_MCTRLDONE_Pos  (9UL)                     /*!< TT_I3C MINTCLR: MCTRLDONE (Bit 9)                 */
#define TT_I3C_MINTCLR_MCTRLDONE_Msk  (0x200UL)                 /*!< TT_I3C MINTCLR: MCTRLDONE (Bitfield-Mask: 0x01)   */
#define TT_I3C_MINTCLR_COMPLETE_Pos   (10UL)                    /*!< TT_I3C MINTCLR: COMPLETE (Bit 10)                 */
#define TT_I3C_MINTCLR_COMPLETE_Msk   (0x400UL)                 /*!< TT_I3C MINTCLR: COMPLETE (Bitfield-Mask: 0x01)    */
#define TT_I3C_MINTCLR_RXPEND_Pos     (11UL)                    /*!< TT_I3C MINTCLR: RXPEND (Bit 11)                   */
#define TT_I3C_MINTCLR_RXPEND_Msk     (0x800UL)                 /*!< TT_I3C MINTCLR: RXPEND (Bitfield-Mask: 0x01)      */
#define TT_I3C_MINTCLR_TXNOTFULL_Pos  (12UL)                    /*!< TT_I3C MINTCLR: TXNOTFULL (Bit 12)                */
#define TT_I3C_MINTCLR_TXNOTFULL_Msk  (0x1000UL)                /*!< TT_I3C MINTCLR: TXNOTFULL (Bitfield-Mask: 0x01)   */
#define TT_I3C_MINTCLR_IBIWON_Pos     (13UL)                    /*!< TT_I3C MINTCLR: IBIWON (Bit 13)                   */
#define TT_I3C_MINTCLR_IBIWON_Msk     (0x2000UL)                /*!< TT_I3C MINTCLR: IBIWON (Bitfield-Mask: 0x01)      */
#define TT_I3C_MINTCLR_ERRWARN_Pos    (15UL)                    /*!< TT_I3C MINTCLR: ERRWARN (Bit 15)                  */
#define TT_I3C_MINTCLR_ERRWARN_Msk    (0x8000UL)                /*!< TT_I3C MINTCLR: ERRWARN (Bitfield-Mask: 0x01)     */
#define TT_I3C_MINTCLR_NOWMASTER_Pos  (19UL)                    /*!< TT_I3C MINTCLR: NOWMASTER (Bit 19)                */
#define TT_I3C_MINTCLR_NOWMASTER_Msk  (0x80000UL)               /*!< TT_I3C MINTCLR: NOWMASTER (Bitfield-Mask: 0x01)   */
/* ======================================================  MINTMASKED  ======================================================= */
#define TT_I3C_MINTMASKED_SLVSTART_Pos (8UL)                    /*!< TT_I3C MINTMASKED: SLVSTART (Bit 8)               */
#define TT_I3C_MINTMASKED_SLVSTART_Msk (0x100UL)                /*!< TT_I3C MINTMASKED: SLVSTART (Bitfield-Mask: 0x01) */
#define TT_I3C_MINTMASKED_MCTRLDONE_Pos (9UL)                   /*!< TT_I3C MINTMASKED: MCTRLDONE (Bit 9)              */
#define TT_I3C_MINTMASKED_MCTRLDONE_Msk (0x200UL)               /*!< TT_I3C MINTMASKED: MCTRLDONE (Bitfield-Mask: 0x01) */
#define TT_I3C_MINTMASKED_COMPLETE_Pos (10UL)                   /*!< TT_I3C MINTMASKED: COMPLETE (Bit 10)              */
#define TT_I3C_MINTMASKED_COMPLETE_Msk (0x400UL)                /*!< TT_I3C MINTMASKED: COMPLETE (Bitfield-Mask: 0x01) */
#define TT_I3C_MINTMASKED_RXPEND_Pos  (11UL)                    /*!< TT_I3C MINTMASKED: RXPEND (Bit 11)                */
#define TT_I3C_MINTMASKED_RXPEND_Msk  (0x800UL)                 /*!< TT_I3C MINTMASKED: RXPEND (Bitfield-Mask: 0x01)   */
#define TT_I3C_MINTMASKED_TXNOTFULL_Pos (12UL)                  /*!< TT_I3C MINTMASKED: TXNOTFULL (Bit 12)             */
#define TT_I3C_MINTMASKED_TXNOTFULL_Msk (0x1000UL)              /*!< TT_I3C MINTMASKED: TXNOTFULL (Bitfield-Mask: 0x01) */
#define TT_I3C_MINTMASKED_IBIWON_Pos  (13UL)                    /*!< TT_I3C MINTMASKED: IBIWON (Bit 13)                */
#define TT_I3C_MINTMASKED_IBIWON_Msk  (0x2000UL)                /*!< TT_I3C MINTMASKED: IBIWON (Bitfield-Mask: 0x01)   */
#define TT_I3C_MINTMASKED_ERRWARN_Pos (15UL)                    /*!< TT_I3C MINTMASKED: ERRWARN (Bit 15)               */
#define TT_I3C_MINTMASKED_ERRWARN_Msk (0x8000UL)                /*!< TT_I3C MINTMASKED: ERRWARN (Bitfield-Mask: 0x01)  */
#define TT_I3C_MINTMASKED_NOWMASTER_Pos (19UL)                  /*!< TT_I3C MINTMASKED: NOWMASTER (Bit 19)             */
#define TT_I3C_MINTMASKED_NOWMASTER_Msk (0x80000UL)             /*!< TT_I3C MINTMASKED: NOWMASTER (Bitfield-Mask: 0x01) */
/* =======================================================  MERRWARN  ======================================================== */
#define TT_I3C_MERRWARN_NACK_Pos      (2UL)                     /*!< TT_I3C MERRWARN: NACK (Bit 2)                     */
#define TT_I3C_MERRWARN_NACK_Msk      (0x4UL)                   /*!< TT_I3C MERRWARN: NACK (Bitfield-Mask: 0x01)       */
#define TT_I3C_MERRWARN_WRABT_Pos     (3UL)                     /*!< TT_I3C MERRWARN: WRABT (Bit 3)                    */
#define TT_I3C_MERRWARN_WRABT_Msk     (0x8UL)                   /*!< TT_I3C MERRWARN: WRABT (Bitfield-Mask: 0x01)      */
#define TT_I3C_MERRWARN_TERM_Pos      (4UL)                     /*!< TT_I3C MERRWARN: TERM (Bit 4)                     */
#define TT_I3C_MERRWARN_TERM_Msk      (0x10UL)                  /*!< TT_I3C MERRWARN: TERM (Bitfield-Mask: 0x01)       */
#define TT_I3C_MERRWARN_HPAR_Pos      (9UL)                     /*!< TT_I3C MERRWARN: HPAR (Bit 9)                     */
#define TT_I3C_MERRWARN_HPAR_Msk      (0x200UL)                 /*!< TT_I3C MERRWARN: HPAR (Bitfield-Mask: 0x01)       */
#define TT_I3C_MERRWARN_HCRC_Pos      (10UL)                    /*!< TT_I3C MERRWARN: HCRC (Bit 10)                    */
#define TT_I3C_MERRWARN_HCRC_Msk      (0x400UL)                 /*!< TT_I3C MERRWARN: HCRC (Bitfield-Mask: 0x01)       */
#define TT_I3C_MERRWARN_HNOVERIFY_Pos (12UL)                    /*!< TT_I3C MERRWARN: HNOVERIFY (Bit 12)               */
#define TT_I3C_MERRWARN_HNOVERIFY_Msk (0x1000UL)                /*!< TT_I3C MERRWARN: HNOVERIFY (Bitfield-Mask: 0x01)  */
#define TT_I3C_MERRWARN_OREAD_Pos     (16UL)                    /*!< TT_I3C MERRWARN: OREAD (Bit 16)                   */
#define TT_I3C_MERRWARN_OREAD_Msk     (0x10000UL)               /*!< TT_I3C MERRWARN: OREAD (Bitfield-Mask: 0x01)      */
#define TT_I3C_MERRWARN_OWRITE_Pos    (17UL)                    /*!< TT_I3C MERRWARN: OWRITE (Bit 17)                  */
#define TT_I3C_MERRWARN_OWRITE_Msk    (0x20000UL)               /*!< TT_I3C MERRWARN: OWRITE (Bitfield-Mask: 0x01)     */
#define TT_I3C_MERRWARN_MSGERR_Pos    (18UL)                    /*!< TT_I3C MERRWARN: MSGERR (Bit 18)                  */
#define TT_I3C_MERRWARN_MSGERR_Msk    (0x40000UL)               /*!< TT_I3C MERRWARN: MSGERR (Bitfield-Mask: 0x01)     */
#define TT_I3C_MERRWARN_INVREQ_Pos    (19UL)                    /*!< TT_I3C MERRWARN: INVREQ (Bit 19)                  */
#define TT_I3C_MERRWARN_INVREQ_Msk    (0x80000UL)               /*!< TT_I3C MERRWARN: INVREQ (Bitfield-Mask: 0x01)     */
#define TT_I3C_MERRWARN_TIMEOUT_Pos   (20UL)                    /*!< TT_I3C MERRWARN: TIMEOUT (Bit 20)                 */
#define TT_I3C_MERRWARN_TIMEOUT_Msk   (0x100000UL)              /*!< TT_I3C MERRWARN: TIMEOUT (Bitfield-Mask: 0x01)    */
#define TT_I3C_MERRWARN_WRONGSIZE_Pos (21UL)                    /*!< TT_I3C MERRWARN: WRONGSIZE (Bit 21)               */
#define TT_I3C_MERRWARN_WRONGSIZE_Msk (0x200000UL)              /*!< TT_I3C MERRWARN: WRONGSIZE (Bitfield-Mask: 0x01)  */
/* =======================================================  MDMACTRL  ======================================================== */
#define TT_I3C_MDMACTRL_DMAFB_Pos     (0UL)                     /*!< TT_I3C MDMACTRL: DMAFB (Bit 0)                    */
#define TT_I3C_MDMACTRL_DMAFB_Msk     (0x3UL)                   /*!< TT_I3C MDMACTRL: DMAFB (Bitfield-Mask: 0x03)      */
#define TT_I3C_MDMACTRL_DMATB_Pos     (2UL)                     /*!< TT_I3C MDMACTRL: DMATB (Bit 2)                    */
#define TT_I3C_MDMACTRL_DMATB_Msk     (0xcUL)                   /*!< TT_I3C MDMACTRL: DMATB (Bitfield-Mask: 0x03)      */
#define TT_I3C_MDMACTRL_DMAWIDTH_Pos  (4UL)                     /*!< TT_I3C MDMACTRL: DMAWIDTH (Bit 4)                 */
#define TT_I3C_MDMACTRL_DMAWIDTH_Msk  (0x30UL)                  /*!< TT_I3C MDMACTRL: DMAWIDTH (Bitfield-Mask: 0x03)   */
/* =======================================================  MHDRBTCFG  ======================================================= */
#define TT_I3C_MHDRBTCFG_MLHDR_Pos    (0UL)                     /*!< TT_I3C MHDRBTCFG: MLHDR (Bit 0)                   */
#define TT_I3C_MHDRBTCFG_MLHDR_Msk    (0x3UL)                   /*!< TT_I3C MHDRBTCFG: MLHDR (Bitfield-Mask: 0x03)     */
#define TT_I3C_MHDRBTCFG_MLDAT_Pos    (2UL)                     /*!< TT_I3C MHDRBTCFG: MLDAT (Bit 2)                   */
#define TT_I3C_MHDRBTCFG_MLDAT_Msk    (0xcUL)                   /*!< TT_I3C MHDRBTCFG: MLDAT (Bitfield-Mask: 0x03)     */
#define TT_I3C_MHDRBTCFG_CRC32_Pos    (4UL)                     /*!< TT_I3C MHDRBTCFG: CRC32 (Bit 4)                   */
#define TT_I3C_MHDRBTCFG_CRC32_Msk    (0x10UL)                  /*!< TT_I3C MHDRBTCFG: CRC32 (Bitfield-Mask: 0x01)     */
#define TT_I3C_MHDRBTCFG_DATALEN_Pos  (16UL)                    /*!< TT_I3C MHDRBTCFG: DATALEN (Bit 16)                */
#define TT_I3C_MHDRBTCFG_DATALEN_Msk  (0xffff0000UL)            /*!< TT_I3C MHDRBTCFG: DATALEN (Bitfield-Mask: 0xffff) */
/* ======================================================  MHDRBTLAST  ======================================================= */
#define TT_I3C_MHDRBTLAST_DATALEN_Pos (16UL)                    /*!< TT_I3C MHDRBTLAST: DATALEN (Bit 16)               */
#define TT_I3C_MHDRBTLAST_DATALEN_Msk (0xffff0000UL)            /*!< TT_I3C MHDRBTLAST: DATALEN (Bitfield-Mask: 0xffff) */
/* =======================================================  MDATACTRL  ======================================================= */
#define TT_I3C_MDATACTRL_FLUSHTB_Pos  (0UL)                     /*!< TT_I3C MDATACTRL: FLUSHTB (Bit 0)                 */
#define TT_I3C_MDATACTRL_FLUSHTB_Msk  (0x1UL)                   /*!< TT_I3C MDATACTRL: FLUSHTB (Bitfield-Mask: 0x01)   */
#define TT_I3C_MDATACTRL_FLUSHFB_Pos  (1UL)                     /*!< TT_I3C MDATACTRL: FLUSHFB (Bit 1)                 */
#define TT_I3C_MDATACTRL_FLUSHFB_Msk  (0x2UL)                   /*!< TT_I3C MDATACTRL: FLUSHFB (Bitfield-Mask: 0x01)   */
#define TT_I3C_MDATACTRL_UNLOCK_Pos   (3UL)                     /*!< TT_I3C MDATACTRL: UNLOCK (Bit 3)                  */
#define TT_I3C_MDATACTRL_UNLOCK_Msk   (0x8UL)                   /*!< TT_I3C MDATACTRL: UNLOCK (Bitfield-Mask: 0x01)    */
#define TT_I3C_MDATACTRL_TXTRIG_Pos   (4UL)                     /*!< TT_I3C MDATACTRL: TXTRIG (Bit 4)                  */
#define TT_I3C_MDATACTRL_TXTRIG_Msk   (0x30UL)                  /*!< TT_I3C MDATACTRL: TXTRIG (Bitfield-Mask: 0x03)    */
#define TT_I3C_MDATACTRL_RXTRIG_Pos   (6UL)                     /*!< TT_I3C MDATACTRL: RXTRIG (Bit 6)                  */
#define TT_I3C_MDATACTRL_RXTRIG_Msk   (0xc0UL)                  /*!< TT_I3C MDATACTRL: RXTRIG (Bitfield-Mask: 0x03)    */
#define TT_I3C_MDATACTRL_TXCOUNT_Pos  (16UL)                    /*!< TT_I3C MDATACTRL: TXCOUNT (Bit 16)                */
#define TT_I3C_MDATACTRL_TXCOUNT_Msk  (0x3f0000UL)              /*!< TT_I3C MDATACTRL: TXCOUNT (Bitfield-Mask: 0x3f)   */
#define TT_I3C_MDATACTRL_RXCOUNT_Pos  (24UL)                    /*!< TT_I3C MDATACTRL: RXCOUNT (Bit 24)                */
#define TT_I3C_MDATACTRL_RXCOUNT_Msk  (0x3f000000UL)            /*!< TT_I3C MDATACTRL: RXCOUNT (Bitfield-Mask: 0x3f)   */
#define TT_I3C_MDATACTRL_TXFULL_Pos   (30UL)                    /*!< TT_I3C MDATACTRL: TXFULL (Bit 30)                 */
#define TT_I3C_MDATACTRL_TXFULL_Msk   (0x40000000UL)            /*!< TT_I3C MDATACTRL: TXFULL (Bitfield-Mask: 0x01)    */
#define TT_I3C_MDATACTRL_RXEMPTY_Pos  (31UL)                    /*!< TT_I3C MDATACTRL: RXEMPTY (Bit 31)                */
#define TT_I3C_MDATACTRL_RXEMPTY_Msk  (0x80000000UL)            /*!< TT_I3C MDATACTRL: RXEMPTY (Bitfield-Mask: 0x01)   */
/* ========================================================  MWDATAB  ======================================================== */
#define TT_I3C_MWDATAB_DATA_Pos       (0UL)                     /*!< TT_I3C MWDATAB: DATA (Bit 0)                      */
#define TT_I3C_MWDATAB_DATA_Msk       (0xffUL)                  /*!< TT_I3C MWDATAB: DATA (Bitfield-Mask: 0xff)        */
#define TT_I3C_MWDATAB_END_Pos        (8UL)                     /*!< TT_I3C MWDATAB: END (Bit 8)                       */
#define TT_I3C_MWDATAB_END_Msk        (0x100UL)                 /*!< TT_I3C MWDATAB: END (Bitfield-Mask: 0x01)         */
#define TT_I3C_MWDATAB_END_ALSO_Pos   (16UL)                    /*!< TT_I3C MWDATAB: END_ALSO (Bit 16)                 */
#define TT_I3C_MWDATAB_END_ALSO_Msk   (0x10000UL)               /*!< TT_I3C MWDATAB: END_ALSO (Bitfield-Mask: 0x01)    */
/* =======================================================  MWDATABE  ======================================================== */
#define TT_I3C_MWDATABE_DATA_Pos      (0UL)                     /*!< TT_I3C MWDATABE: DATA (Bit 0)                     */
#define TT_I3C_MWDATABE_DATA_Msk      (0xffUL)                  /*!< TT_I3C MWDATABE: DATA (Bitfield-Mask: 0xff)       */
/* ========================================================  MWDATAH  ======================================================== */
#define TT_I3C_MWDATAH_DATA0_Pos      (0UL)                     /*!< TT_I3C MWDATAH: DATA0 (Bit 0)                     */
#define TT_I3C_MWDATAH_DATA0_Msk      (0xffUL)                  /*!< TT_I3C MWDATAH: DATA0 (Bitfield-Mask: 0xff)       */
#define TT_I3C_MWDATAH_DATA1_Pos      (8UL)                     /*!< TT_I3C MWDATAH: DATA1 (Bit 8)                     */
#define TT_I3C_MWDATAH_DATA1_Msk      (0xff00UL)                /*!< TT_I3C MWDATAH: DATA1 (Bitfield-Mask: 0xff)       */
#define TT_I3C_MWDATAH_END_Pos        (16UL)                    /*!< TT_I3C MWDATAH: END (Bit 16)                      */
#define TT_I3C_MWDATAH_END_Msk        (0x10000UL)               /*!< TT_I3C MWDATAH: END (Bitfield-Mask: 0x01)         */
/* =======================================================  MWDATAHE  ======================================================== */
#define TT_I3C_MWDATAHE_DATA0_Pos     (0UL)                     /*!< TT_I3C MWDATAHE: DATA0 (Bit 0)                    */
#define TT_I3C_MWDATAHE_DATA0_Msk     (0xffUL)                  /*!< TT_I3C MWDATAHE: DATA0 (Bitfield-Mask: 0xff)      */
#define TT_I3C_MWDATAHE_DATA1_Pos     (8UL)                     /*!< TT_I3C MWDATAHE: DATA1 (Bit 8)                    */
#define TT_I3C_MWDATAHE_DATA1_Msk     (0xff00UL)                /*!< TT_I3C MWDATAHE: DATA1 (Bitfield-Mask: 0xff)      */
/* ========================================================  MRDATAB  ======================================================== */
#define TT_I3C_MRDATAB_VALUE_Pos      (0UL)                     /*!< TT_I3C MRDATAB: VALUE (Bit 0)                     */
#define TT_I3C_MRDATAB_VALUE_Msk      (0xffUL)                  /*!< TT_I3C MRDATAB: VALUE (Bitfield-Mask: 0xff)       */
/* ========================================================  MRDATAH  ======================================================== */
#define TT_I3C_MRDATAH_LSB_Pos        (0UL)                     /*!< TT_I3C MRDATAH: LSB (Bit 0)                       */
#define TT_I3C_MRDATAH_LSB_Msk        (0xffUL)                  /*!< TT_I3C MRDATAH: LSB (Bitfield-Mask: 0xff)         */
#define TT_I3C_MRDATAH_MSB_Pos        (8UL)                     /*!< TT_I3C MRDATAH: MSB (Bit 8)                       */
#define TT_I3C_MRDATAH_MSB_Msk        (0xff00UL)                /*!< TT_I3C MRDATAH: MSB (Bitfield-Mask: 0xff)         */
/* =======================================================  MWDATAB1  ======================================================== */
#define TT_I3C_MWDATAB1_DATA_Pos      (0UL)                     /*!< TT_I3C MWDATAB1: DATA (Bit 0)                     */
#define TT_I3C_MWDATAB1_DATA_Msk      (0xffUL)                  /*!< TT_I3C MWDATAB1: DATA (Bitfield-Mask: 0xff)       */
/* ==============================================  MWMSG_SDR_CONTROL_MWMSG_SDR  ============================================== */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_DIR_Pos (0UL)        /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: DIR (Bit 0)   */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_DIR_Msk (0x1UL)      /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: DIR (Bitfield-Mask: 0x01) */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_ADDR_Pos (1UL)       /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: ADDR (Bit 1)  */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_ADDR_Msk (0xfeUL)    /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: ADDR (Bitfield-Mask: 0x7f) */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_END_Pos (8UL)        /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: END (Bit 8)   */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_END_Msk (0x100UL)    /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: END (Bitfield-Mask: 0x01) */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_I2C_Pos (10UL)       /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: I2C (Bit 10)  */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_I2C_Msk (0x400UL)    /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: I2C (Bitfield-Mask: 0x01) */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_LEN_Pos (11UL)       /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: LEN (Bit 11)  */
#define TT_I3C_MWMSG_SDR_CONTROL_MWMSG_SDR_LEN_Msk (0xf800UL)   /*!< TT_I3C MWMSG_SDR_CONTROL_MWMSG_SDR: LEN (Bitfield-Mask: 0x1f) */
/* ===============================================  MWMSG_SDR_DATA_MWMSG_SDR  ================================================ */
#define TT_I3C_MWMSG_SDR_DATA_MWMSG_SDR_DATA16B_Pos (0UL)       /*!< TT_I3C MWMSG_SDR_DATA_MWMSG_SDR: DATA16B (Bit 0)  */
#define TT_I3C_MWMSG_SDR_DATA_MWMSG_SDR_DATA16B_Msk (0xffffUL)  /*!< TT_I3C MWMSG_SDR_DATA_MWMSG_SDR: DATA16B (Bitfield-Mask: 0xffff) */
/* =======================================================  MRMSG_SDR  ======================================================= */
#define TT_I3C_MRMSG_SDR_DATA_Pos     (0UL)                     /*!< TT_I3C MRMSG_SDR: DATA (Bit 0)                    */
#define TT_I3C_MRMSG_SDR_DATA_Msk     (0xffffUL)                /*!< TT_I3C MRMSG_SDR: DATA (Bitfield-Mask: 0xffff)    */
/* ==============================================  MWMSG_DDR_CONTROL_MWMSG_DDR  ============================================== */
#define TT_I3C_MWMSG_DDR_CONTROL_MWMSG_DDR_LEN_Pos (0UL)        /*!< TT_I3C MWMSG_DDR_CONTROL_MWMSG_DDR: LEN (Bit 0)   */
#define TT_I3C_MWMSG_DDR_CONTROL_MWMSG_DDR_LEN_Msk (0x3ffUL)    /*!< TT_I3C MWMSG_DDR_CONTROL_MWMSG_DDR: LEN (Bitfield-Mask: 0x3ff) */
#define TT_I3C_MWMSG_DDR_CONTROL_MWMSG_DDR_END_Pos (14UL)       /*!< TT_I3C MWMSG_DDR_CONTROL_MWMSG_DDR: END (Bit 14)  */
#define TT_I3C_MWMSG_DDR_CONTROL_MWMSG_DDR_END_Msk (0x4000UL)   /*!< TT_I3C MWMSG_DDR_CONTROL_MWMSG_DDR: END (Bitfield-Mask: 0x01) */
/* ===============================================  MWMSG_DDR_DATA_MWMSG_DDR  ================================================ */
#define TT_I3C_MWMSG_DDR_DATA_MWMSG_DDR_DATA16B_Pos (0UL)       /*!< TT_I3C MWMSG_DDR_DATA_MWMSG_DDR: DATA16B (Bit 0)  */
#define TT_I3C_MWMSG_DDR_DATA_MWMSG_DDR_DATA16B_Msk (0xffffUL)  /*!< TT_I3C MWMSG_DDR_DATA_MWMSG_DDR: DATA16B (Bitfield-Mask: 0xffff) */
/* ==============================================  MWMSG_DDR_ADDRCMD_MWMSG_DDR  ============================================== */
#define TT_I3C_MWMSG_DDR_ADDRCMD_MWMSG_DDR_CMD_Pos (0UL)        /*!< TT_I3C MWMSG_DDR_ADDRCMD_MWMSG_DDR: CMD (Bit 0)   */
#define TT_I3C_MWMSG_DDR_ADDRCMD_MWMSG_DDR_CMD_Msk (0x7fUL)     /*!< TT_I3C MWMSG_DDR_ADDRCMD_MWMSG_DDR: CMD (Bitfield-Mask: 0x7f) */
#define TT_I3C_MWMSG_DDR_ADDRCMD_MWMSG_DDR_DIR_Pos (7UL)        /*!< TT_I3C MWMSG_DDR_ADDRCMD_MWMSG_DDR: DIR (Bit 7)   */
#define TT_I3C_MWMSG_DDR_ADDRCMD_MWMSG_DDR_DIR_Msk (0x80UL)     /*!< TT_I3C MWMSG_DDR_ADDRCMD_MWMSG_DDR: DIR (Bitfield-Mask: 0x01) */
#define TT_I3C_MWMSG_DDR_ADDRCMD_MWMSG_DDR_ADDR_Pos (9UL)       /*!< TT_I3C MWMSG_DDR_ADDRCMD_MWMSG_DDR: ADDR (Bit 9)  */
#define TT_I3C_MWMSG_DDR_ADDRCMD_MWMSG_DDR_ADDR_Msk (0xfe00UL)  /*!< TT_I3C MWMSG_DDR_ADDRCMD_MWMSG_DDR: ADDR (Bitfield-Mask: 0x7f) */
/* =======================================================  MRMSG_DDR  ======================================================= */
#define TT_I3C_MRMSG_DDR_DATA_Pos     (0UL)                     /*!< TT_I3C MRMSG_DDR: DATA (Bit 0)                    */
#define TT_I3C_MRMSG_DDR_DATA_Msk     (0xffffUL)                /*!< TT_I3C MRMSG_DDR: DATA (Bitfield-Mask: 0xffff)    */
/* =======================================================  MDYNADDR  ======================================================== */
#define TT_I3C_MDYNADDR_DAVALID_Pos   (0UL)                     /*!< TT_I3C MDYNADDR: DAVALID (Bit 0)                  */
#define TT_I3C_MDYNADDR_DAVALID_Msk   (0x1UL)                   /*!< TT_I3C MDYNADDR: DAVALID (Bitfield-Mask: 0x01)    */
#define TT_I3C_MDYNADDR_DADDR_Pos     (1UL)                     /*!< TT_I3C MDYNADDR: DADDR (Bit 1)                    */
#define TT_I3C_MDYNADDR_DADDR_Msk     (0xfeUL)                  /*!< TT_I3C MDYNADDR: DADDR (Bitfield-Mask: 0x7f)      */
/* ========================================================  MWDATAW  ======================================================== */
#define TT_I3C_MWDATAW_DATA_Pos       (0UL)                     /*!< TT_I3C MWDATAW: DATA (Bit 0)                      */
#define TT_I3C_MWDATAW_DATA_Msk       (0xffffffffUL)            /*!< TT_I3C MWDATAW: DATA (Bitfield-Mask: 0xffffffff)  */
/* ========================================================  MRDATAW  ======================================================== */
#define TT_I3C_MRDATAW_DATA_Pos       (0UL)                     /*!< TT_I3C MRDATAW: DATA (Bit 0)                      */
#define TT_I3C_MRDATAW_DATA_Msk       (0xffffffffUL)            /*!< TT_I3C MRDATAW: DATA (Bitfield-Mask: 0xffffffff)  */
/* ======================================================  RSTACTTIME  ======================================================= */
#define TT_I3C_RSTACTTIME_SYSRSTTIM_Pos (0UL)                   /*!< TT_I3C RSTACTTIME: SYSRSTTIM (Bit 0)              */
#define TT_I3C_RSTACTTIME_SYSRSTTIM_Msk (0xffUL)                /*!< TT_I3C RSTACTTIME: SYSRSTTIM (Bitfield-Mask: 0xff) */
#define TT_I3C_RSTACTTIME_PERRSTTIM_Pos (8UL)                   /*!< TT_I3C RSTACTTIME: PERRSTTIM (Bit 8)              */
#define TT_I3C_RSTACTTIME_PERRSTTIM_Msk (0xff00UL)              /*!< TT_I3C RSTACTTIME: PERRSTTIM (Bitfield-Mask: 0xff) */
/* ========================================================  IBIEXT1  ======================================================== */
#define TT_I3C_IBIEXT1_CNT_Pos        (0UL)                     /*!< TT_I3C IBIEXT1: CNT (Bit 0)                       */
#define TT_I3C_IBIEXT1_CNT_Msk        (0x7UL)                   /*!< TT_I3C IBIEXT1: CNT (Bitfield-Mask: 0x07)         */
#define TT_I3C_IBIEXT1_MAX_Pos        (4UL)                     /*!< TT_I3C IBIEXT1: MAX (Bit 4)                       */
#define TT_I3C_IBIEXT1_MAX_Msk        (0x70UL)                  /*!< TT_I3C IBIEXT1: MAX (Bitfield-Mask: 0x07)         */
#define TT_I3C_IBIEXT1_EXT1_Pos       (8UL)                     /*!< TT_I3C IBIEXT1: EXT1 (Bit 8)                      */
#define TT_I3C_IBIEXT1_EXT1_Msk       (0xff00UL)                /*!< TT_I3C IBIEXT1: EXT1 (Bitfield-Mask: 0xff)        */
#define TT_I3C_IBIEXT1_EXT2_Pos       (16UL)                    /*!< TT_I3C IBIEXT1: EXT2 (Bit 16)                     */
#define TT_I3C_IBIEXT1_EXT2_Msk       (0xff0000UL)              /*!< TT_I3C IBIEXT1: EXT2 (Bitfield-Mask: 0xff)        */
#define TT_I3C_IBIEXT1_EXT3_Pos       (24UL)                    /*!< TT_I3C IBIEXT1: EXT3 (Bit 24)                     */
#define TT_I3C_IBIEXT1_EXT3_Msk       (0xff000000UL)            /*!< TT_I3C IBIEXT1: EXT3 (Bitfield-Mask: 0xff)        */
/* ========================================================  IBIEXT2  ======================================================== */
#define TT_I3C_IBIEXT2_EXT4_Pos       (0UL)                     /*!< TT_I3C IBIEXT2: EXT4 (Bit 0)                      */
#define TT_I3C_IBIEXT2_EXT4_Msk       (0xffUL)                  /*!< TT_I3C IBIEXT2: EXT4 (Bitfield-Mask: 0xff)        */
#define TT_I3C_IBIEXT2_EXT5_Pos       (8UL)                     /*!< TT_I3C IBIEXT2: EXT5 (Bit 8)                      */
#define TT_I3C_IBIEXT2_EXT5_Msk       (0xff00UL)                /*!< TT_I3C IBIEXT2: EXT5 (Bitfield-Mask: 0xff)        */
#define TT_I3C_IBIEXT2_EXT6_Pos       (16UL)                    /*!< TT_I3C IBIEXT2: EXT6 (Bit 16)                     */
#define TT_I3C_IBIEXT2_EXT6_Msk       (0xff0000UL)              /*!< TT_I3C IBIEXT2: EXT6 (Bitfield-Mask: 0xff)        */
#define TT_I3C_IBIEXT2_EXT7_Pos       (24UL)                    /*!< TT_I3C IBIEXT2: EXT7 (Bit 24)                     */
#define TT_I3C_IBIEXT2_EXT7_Msk       (0xff000000UL)            /*!< TT_I3C IBIEXT2: EXT7 (Bitfield-Mask: 0xff)        */
/* ========================================================  WDATAW  ========================================================= */
#define TT_I3C_WDATAW_DATA_Pos        (0UL)                     /*!< TT_I3C WDATAW: DATA (Bit 0)                       */
#define TT_I3C_WDATAW_DATA_Msk        (0xffffffffUL)            /*!< TT_I3C WDATAW: DATA (Bitfield-Mask: 0xffffffff)   */
/* ========================================================  RDATAW  ========================================================= */
#define TT_I3C_RDATAW_DATA_Pos        (0UL)                     /*!< TT_I3C RDATAW: DATA (Bit 0)                       */
#define TT_I3C_RDATAW_DATA_Msk        (0xffffffffUL)            /*!< TT_I3C RDATAW: DATA (Bitfield-Mask: 0xffffffff)   */
/* ==========================================================  SID  ========================================================== */
#define TT_I3C_SID_ID_Pos             (0UL)                     /*!< TT_I3C SID: ID (Bit 0)                            */
#define TT_I3C_SID_ID_Msk             (0xffffffffUL)            /*!< TT_I3C SID: ID (Bitfield-Mask: 0xffffffff)        */

#ifdef __cplusplus
}
#endif

#endif
