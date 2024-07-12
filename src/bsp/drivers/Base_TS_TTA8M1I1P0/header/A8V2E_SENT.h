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
#ifndef A8V2E_SENT_H
#define A8V2E_SENT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_SENT_VENDOR_ID_H                     1541
#define A8V2E_SENT_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_SENT_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_SENT_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_SENT_SW_MAJOR_VERSION_H              1
#define A8V2E_SENT_SW_MINOR_VERSION_H              1
#define A8V2E_SENT_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_SENT.h and TT_Common.h file version check */
#if (A8V2E_SENT_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_SENT.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_SENT_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_SENT_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_SENT_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_SENT.h and TT_Common.h are different"
#endif
#if ((A8V2E_SENT_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_SENT_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_SENT_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_SENT.h and TT_Common.h are different"
#endif


 

/* =========================================================================================================================== */
/* ================                                       TT_SENT0                                        ================ */
/* =========================================================================================================================== */


/**
  * @brief SENT0 module register. (TT_SENT0)
  */

typedef struct {                              /*!< (@ 0x40114000) TT_SENT0 Structure                                         */
  __IOM uint32  INT_EN;                       /*!< (@ 0x00000000) Interrupt enable register                                  */
  __IOM uint32  INT_STATUS;                   /*!< (@ 0x00000004) Interrupt status register                                  */
  __IOM uint32  PULSE_CONFIG;                 /*!< (@ 0x00000008) Threshold configuration register                           */

  union {
    __IM  uint32 SLOW;                        /*!< (@ 0x0000000C) short Message data register                                */
    __IOM uint32 SLOW_ENHANCE_0;              /*!< (@ 0x0000000C) Message enhance data 0 register                            */
    __IOM uint32 SLOW_ENHANCE_1;              /*!< (@ 0x0000000C) Message enhance data 1 register                            */
  }MESSAGE;
  __IOM uint32  CONTROL;                      /*!< (@ 0x00000010) Contorl register                                           */
  __IOM uint32  PRESCALER_VALUE;              /*!< (@ 0x00000014) Clock preset register                                      */
  __IM  uint32  FRAME_COUNT;                  /*!< (@ 0x00000018) Transmitted frame length                                   */
  __IM  uint32  FRAME_DATA;                   /*!< (@ 0x0000001C) Transmitted frame length                                   */
  __IOM uint32  DATA_TYPE;                    /*!< (@ 0x00000020) Data pos register                                          */
  __IM  uint32  STATUS;                       /*!< (@ 0x00000024) Status register                                            */
  __IM  uint32  TIME_STAMP;                   /*!< (@ 0x00000028) Time stamp register                                        */
  __IOM uint32  TIME_STAMP_PREDIVIDER;        /*!< (@ 0x0000002C) Time stamp predivider register                             */
  __IOM uint32  WDT_COUNT;                    /*!< (@ 0x00000030) Wdt count                                                  */
  __IM  uint32  RECEIVE_TIME_STAMP;           /*!< (@ 0x00000034) Receive time stamp                                         */
  __IOM uint32  SENT_SUPV;                    /*!< (@ 0x00000038) Sent access mode                                           */
  __IM  uint32  RESERVED[49];
  __IOM uint32  SPC_CONTROL;                  /*!< (@ 0x00000100) Spc control                                                */
  __IM  uint32  RESERVED1[63];
  __IOM uint32  SPC_PROT;                     /*!< (@ 0x00000200) Spc prot                                                   */
  __IM  uint32  RESERVED2[126];
  __IM  uint32  SENT_ID;                      /*!< (@ 0x000003FC) Sent id                                                    */
} Sent_RegType;                               /*!< Size = 1024 (0x400)                                                       */

#define TT_SENT0_BASE           0x40114000UL
#define TT_SENT1_BASE           0x40115000UL
#define TT_SENT2_BASE           0x400AE000UL
#define TT_SENT3_BASE           0x400AF000UL
#define TT_SENT4_BASE           0x400A9000UL
#define TT_SENT5_BASE           0x400AA000UL
#define TT_SENT6_BASE           0x40118000UL
#define TT_SENT7_BASE           0x40119000UL

#define TT_SENT0          ((Sent_RegType*)TT_SENT0_BASE)
#define TT_SENT1          ((Sent_RegType*)TT_SENT1_BASE)
#define TT_SENT2          ((Sent_RegType*)TT_SENT2_BASE)
#define TT_SENT3          ((Sent_RegType*)TT_SENT3_BASE)
#define TT_SENT4          ((Sent_RegType*)TT_SENT4_BASE)
#define TT_SENT5          ((Sent_RegType*)TT_SENT5_BASE)
#define TT_SENT6          ((Sent_RegType*)TT_SENT6_BASE)
#define TT_SENT7          ((Sent_RegType*)TT_SENT7_BASE)
/* =========================================================================================================================== */
/* ================                                          TT_SENT                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  INT_EN  ========================================================= */
#define TT_SENT_INT_EN_FRAME_RECEIVE_EN_Pos (0UL)                   /*!< TT_SENT INT_EN: FRAME_RECEIVE_EN (Bit 0)              */
#define TT_SENT_INT_EN_FRAME_RECEIVE_EN_Msk (0x1UL)                 /*!< TT_SENT INT_EN: FRAME_RECEIVE_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_MESSAGE_RECEIVE_EN_Pos (1UL)                 /*!< TT_SENT INT_EN: MESSAGE_RECEIVE_EN (Bit 1)            */
#define TT_SENT_INT_EN_MESSAGE_RECEIVE_EN_Msk (0x2UL)               /*!< TT_SENT INT_EN: MESSAGE_RECEIVE_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_Reserved0_Pos      (2UL)                     /*!< TT_SENT INT_EN: Reserved0 (Bit 2)                     */
#define TT_SENT_INT_EN_Reserved0_Msk      (0x4UL)                   /*!< TT_SENT INT_EN: Reserved0 (Bitfield-Mask: 0x01)       */
#define TT_SENT_INT_EN_CALIB_PULSE_ERR_EN_Pos (3UL)                 /*!< TT_SENT INT_EN: CALIB_PULSE_ERR_EN (Bit 3)            */
#define TT_SENT_INT_EN_CALIB_PULSE_ERR_EN_Msk (0x8UL)               /*!< TT_SENT INT_EN: CALIB_PULSE_ERR_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_FAST_CRC_ERR_EN_Pos (4UL)                    /*!< TT_SENT INT_EN: FAST_CRC_ERR_EN (Bit 4)               */
#define TT_SENT_INT_EN_FAST_CRC_ERR_EN_Msk (0x10UL)                 /*!< TT_SENT INT_EN: FAST_CRC_ERR_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_PAUSE_ERR_EN_Pos   (5UL)                     /*!< TT_SENT INT_EN: PAUSE_ERR_EN (Bit 5)                  */
#define TT_SENT_INT_EN_PAUSE_ERR_EN_Msk   (0x20UL)                  /*!< TT_SENT INT_EN: PAUSE_ERR_EN (Bitfield-Mask: 0x01)    */
#define TT_SENT_INT_EN_SHORT_MESSAGE_ERR_EN_Pos (6UL)               /*!< TT_SENT INT_EN: SHORT_MESSAGE_ERR_EN (Bit 6)          */
#define TT_SENT_INT_EN_SHORT_MESSAGE_ERR_EN_Msk (0x40UL)            /*!< TT_SENT INT_EN: SHORT_MESSAGE_ERR_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_ENHANCE_MESSAGE_ERR_EN_Pos (7UL)             /*!< TT_SENT INT_EN: ENHANCE_MESSAGE_ERR_EN (Bit 7)        */
#define TT_SENT_INT_EN_ENHANCE_MESSAGE_ERR_EN_Msk (0x80UL)          /*!< TT_SENT INT_EN: ENHANCE_MESSAGE_ERR_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_SLOW_CRC_ERR_EN_Pos (8UL)                    /*!< TT_SENT INT_EN: SLOW_CRC_ERR_EN (Bit 8)               */
#define TT_SENT_INT_EN_SLOW_CRC_ERR_EN_Msk (0x100UL)                /*!< TT_SENT INT_EN: SLOW_CRC_ERR_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_DATA_COUNT_ERR_EN_Pos (9UL)                  /*!< TT_SENT INT_EN: DATA_COUNT_ERR_EN (Bit 9)             */
#define TT_SENT_INT_EN_DATA_COUNT_ERR_EN_Msk (0x200UL)              /*!< TT_SENT INT_EN: DATA_COUNT_ERR_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_SUCCESSIVE_CALIB_ERR_EN_Pos (10UL)           /*!< TT_SENT INT_EN: SUCCESSIVE_CALIB_ERR_EN (Bit 10)      */
#define TT_SENT_INT_EN_SUCCESSIVE_CALIB_ERR_EN_Msk (0x400UL)        /*!< TT_SENT INT_EN: SUCCESSIVE_CALIB_ERR_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_FIFO_EMPTY_EN_Pos  (11UL)                    /*!< TT_SENT INT_EN: FIFO_EMPTY_EN (Bit 11)                */
#define TT_SENT_INT_EN_FIFO_EMPTY_EN_Msk  (0x800UL)                 /*!< TT_SENT INT_EN: FIFO_EMPTY_EN (Bitfield-Mask: 0x01)   */
#define TT_SENT_INT_EN_FIFO_FULL_EN_Pos   (12UL)                    /*!< TT_SENT INT_EN: FIFO_FULL_EN (Bit 12)                 */
#define TT_SENT_INT_EN_FIFO_FULL_EN_Msk   (0x1000UL)                /*!< TT_SENT INT_EN: FIFO_FULL_EN (Bitfield-Mask: 0x01)    */
#define TT_SENT_INT_EN_WDT_ERR_EN_Pos     (13UL)                    /*!< TT_SENT INT_EN: WDT_ERR_EN (Bit 13)                   */
#define TT_SENT_INT_EN_WDT_ERR_EN_Msk     (0x2000UL)                /*!< TT_SENT INT_EN: WDT_ERR_EN (Bitfield-Mask: 0x01)      */
#define TT_SENT_INT_EN_DATA_TICK_ERR_EN_Pos (14UL)                  /*!< TT_SENT INT_EN: DATA_TICK_ERR_EN (Bit 14)             */
#define TT_SENT_INT_EN_DATA_TICK_ERR_EN_Msk (0x4000UL)              /*!< TT_SENT INT_EN: DATA_TICK_ERR_EN (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_EN_FRAME_ERR_EN_Pos   (15UL)                    /*!< TT_SENT INT_EN: FRAME_ERR_EN (Bit 15)                 */
#define TT_SENT_INT_EN_FRAME_ERR_EN_Msk   (0x8000UL)                /*!< TT_SENT INT_EN: FRAME_ERR_EN (Bitfield-Mask: 0x01)    */
#define TT_SENT_INT_EN_GLITCH_ERR_EN_Pos  (16UL)                    /*!< TT_SENT INT_EN: GLITCH_ERR_EN (Bit 16)                */
#define TT_SENT_INT_EN_GLITCH_ERR_EN_Msk  (0x10000UL)               /*!< TT_SENT INT_EN: GLITCH_ERR_EN (Bitfield-Mask: 0x01)   */
#define TT_SENT_INT_EN_Reserved1_Pos      (17UL)                    /*!< TT_SENT INT_EN: Reserved1 (Bit 17)                    */
#define TT_SENT_INT_EN_Reserved1_Msk      (0xfffe0000UL)            /*!< TT_SENT INT_EN: Reserved1 (Bitfield-Mask: 0x7fff)     */
/* ======================================================  INT_STATUS  ======================================================= */
#define TT_SENT_INT_STATUS_FRAME_RECEIVE_Pos (0UL)                  /*!< TT_SENT INT_STATUS: FRAME_RECEIVE (Bit 0)             */
#define TT_SENT_INT_STATUS_FRAME_RECEIVE_Msk (0x1UL)                /*!< TT_SENT INT_STATUS: FRAME_RECEIVE (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_MESSAGE_RECEIVE_Pos (1UL)                /*!< TT_SENT INT_STATUS: MESSAGE_RECEIVE (Bit 1)           */
#define TT_SENT_INT_STATUS_MESSAGE_RECEIVE_Msk (0x2UL)              /*!< TT_SENT INT_STATUS: MESSAGE_RECEIVE (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_Reserved0_Pos  (2UL)                     /*!< TT_SENT INT_STATUS: Reserved0 (Bit 2)                 */
#define TT_SENT_INT_STATUS_Reserved0_Msk  (0x4UL)                   /*!< TT_SENT INT_STATUS: Reserved0 (Bitfield-Mask: 0x01)   */
#define TT_SENT_INT_STATUS_CALIB_PULSE_ERR_Pos (3UL)                /*!< TT_SENT INT_STATUS: CALIB_PULSE_ERR (Bit 3)           */
#define TT_SENT_INT_STATUS_CALIB_PULSE_ERR_Msk (0x8UL)              /*!< TT_SENT INT_STATUS: CALIB_PULSE_ERR (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_FAST_CRC_ERR_Pos (4UL)                   /*!< TT_SENT INT_STATUS: FAST_CRC_ERR (Bit 4)              */
#define TT_SENT_INT_STATUS_FAST_CRC_ERR_Msk (0x10UL)                /*!< TT_SENT INT_STATUS: FAST_CRC_ERR (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_PAUSE_ERR_Pos  (5UL)                     /*!< TT_SENT INT_STATUS: PAUSE_ERR (Bit 5)                 */
#define TT_SENT_INT_STATUS_PAUSE_ERR_Msk  (0x20UL)                  /*!< TT_SENT INT_STATUS: PAUSE_ERR (Bitfield-Mask: 0x01)   */
#define TT_SENT_INT_STATUS_SHORT_MESSAGE_ERR_Pos (6UL)              /*!< TT_SENT INT_STATUS: SHORT_MESSAGE_ERR (Bit 6)         */
#define TT_SENT_INT_STATUS_SHORT_MESSAGE_ERR_Msk (0x40UL)           /*!< TT_SENT INT_STATUS: SHORT_MESSAGE_ERR (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_ENHANCE_MESSAGE_ERR_Pos (7UL)            /*!< TT_SENT INT_STATUS: ENHANCE_MESSAGE_ERR (Bit 7)       */
#define TT_SENT_INT_STATUS_ENHANCE_MESSAGE_ERR_Msk (0x80UL)         /*!< TT_SENT INT_STATUS: ENHANCE_MESSAGE_ERR (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_SLOW_MESSAGE_CRC_ERR_Pos (8UL)           /*!< TT_SENT INT_STATUS: SLOW_MESSAGE_CRC_ERR (Bit 8)      */
#define TT_SENT_INT_STATUS_SLOW_MESSAGE_CRC_ERR_Msk (0x100UL)       /*!< TT_SENT INT_STATUS: SLOW_MESSAGE_CRC_ERR (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_DATA_COUNT_ERR_Pos (9UL)                 /*!< TT_SENT INT_STATUS: DATA_COUNT_ERR (Bit 9)            */
#define TT_SENT_INT_STATUS_DATA_COUNT_ERR_Msk (0x200UL)             /*!< TT_SENT INT_STATUS: DATA_COUNT_ERR (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_SUCCESSIVE_CALIB_ERR_Pos (10UL)          /*!< TT_SENT INT_STATUS: SUCCESSIVE_CALIB_ERR (Bit 10)     */
#define TT_SENT_INT_STATUS_SUCCESSIVE_CALIB_ERR_Msk (0x400UL)       /*!< TT_SENT INT_STATUS: SUCCESSIVE_CALIB_ERR (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_FIFO_EMPTY_Pos (11UL)                    /*!< TT_SENT INT_STATUS: FIFO_EMPTY (Bit 11)               */
#define TT_SENT_INT_STATUS_FIFO_EMPTY_Msk (0x800UL)                 /*!< TT_SENT INT_STATUS: FIFO_EMPTY (Bitfield-Mask: 0x01)  */
#define TT_SENT_INT_STATUS_FIFO_FULL_Pos  (12UL)                    /*!< TT_SENT INT_STATUS: FIFO_FULL (Bit 12)                */
#define TT_SENT_INT_STATUS_FIFO_FULL_Msk  (0x1000UL)                /*!< TT_SENT INT_STATUS: FIFO_FULL (Bitfield-Mask: 0x01)   */
#define TT_SENT_INT_STATUS_WDT_ERR_Pos    (13UL)                    /*!< TT_SENT INT_STATUS: WDT_ERR (Bit 13)                  */
#define TT_SENT_INT_STATUS_WDT_ERR_Msk    (0x2000UL)                /*!< TT_SENT INT_STATUS: WDT_ERR (Bitfield-Mask: 0x01)     */
#define TT_SENT_INT_STATUS_DATA_TICK_ERR_Pos (14UL)                 /*!< TT_SENT INT_STATUS: DATA_TICK_ERR (Bit 14)            */
#define TT_SENT_INT_STATUS_DATA_TICK_ERR_Msk (0x4000UL)             /*!< TT_SENT INT_STATUS: DATA_TICK_ERR (Bitfield-Mask: 0x01) */
#define TT_SENT_INT_STATUS_FRAME_ERR_Pos  (15UL)                    /*!< TT_SENT INT_STATUS: FRAME_ERR (Bit 15)                */
#define TT_SENT_INT_STATUS_FRAME_ERR_Msk  (0x8000UL)                /*!< TT_SENT INT_STATUS: FRAME_ERR (Bitfield-Mask: 0x01)   */
#define TT_SENT_INT_STATUS_GLITCH_ERR_Pos (16UL)                    /*!< TT_SENT INT_STATUS: GLITCH_ERR (Bit 16)               */
#define TT_SENT_INT_STATUS_GLITCH_ERR_Msk (0x10000UL)               /*!< TT_SENT INT_STATUS: GLITCH_ERR (Bitfield-Mask: 0x01)  */
#define TT_SENT_INT_STATUS_Reserved1_Pos  (17UL)                    /*!< TT_SENT INT_STATUS: Reserved1 (Bit 17)                */
#define TT_SENT_INT_STATUS_Reserved1_Msk  (0xfffe0000UL)            /*!< TT_SENT INT_STATUS: Reserved1 (Bitfield-Mask: 0x7fff) */
/* =====================================================  PULSE_CONFIG  ====================================================== */
#define TT_SENT_PULSE_CONFIG_CALIB_PULSE_MIN_Pos (0UL)              /*!< TT_SENT PULSE_CONFIG: CALIB_PULSE_MIN (Bit 0)         */
#define TT_SENT_PULSE_CONFIG_CALIB_PULSE_MIN_Msk (0xfUL)            /*!< TT_SENT PULSE_CONFIG: CALIB_PULSE_MIN (Bitfield-Mask: 0x0f) */
#define TT_SENT_PULSE_CONFIG_CALIB_PULSE_MAX_Pos (4UL)              /*!< TT_SENT PULSE_CONFIG: CALIB_PULSE_MAX (Bit 4)         */
#define TT_SENT_PULSE_CONFIG_CALIB_PULSE_MAX_Msk (0xf0UL)           /*!< TT_SENT PULSE_CONFIG: CALIB_PULSE_MAX (Bitfield-Mask: 0x0f) */
#define TT_SENT_PULSE_CONFIG_STEP_Pos     (8UL)                     /*!< TT_SENT PULSE_CONFIG: STEP (Bit 8)                    */
#define TT_SENT_PULSE_CONFIG_STEP_Msk     (0x3ff00UL)               /*!< TT_SENT PULSE_CONFIG: STEP (Bitfield-Mask: 0x3ff)     */
#define TT_SENT_PULSE_CONFIG_CORRECT_STEP_Pos (18UL)                /*!< TT_SENT PULSE_CONFIG: CORRECT_STEP (Bit 18)           */
#define TT_SENT_PULSE_CONFIG_CORRECT_STEP_Msk (0xffc0000UL)         /*!< TT_SENT PULSE_CONFIG: CORRECT_STEP (Bitfield-Mask: 0x3ff) */
/* =====================================================  SLOW_MESSAGE  ====================================================== */
#define TT_SENT_SLOW_MESSAGE_CRC_Pos      (0UL)                     /*!< TT_SENT SLOW_MESSAGE: CRC (Bit 0)                     */
#define TT_SENT_SLOW_MESSAGE_CRC_Msk      (0xfUL)                   /*!< TT_SENT SLOW_MESSAGE: CRC (Bitfield-Mask: 0x0f)       */
#define TT_SENT_SLOW_MESSAGE_DATA_Pos     (4UL)                     /*!< TT_SENT SLOW_MESSAGE: DATA (Bit 4)                    */
#define TT_SENT_SLOW_MESSAGE_DATA_Msk     (0xff0UL)                 /*!< TT_SENT SLOW_MESSAGE: DATA (Bitfield-Mask: 0xff)      */
#define TT_SENT_SLOW_MESSAGE_ID_Pos       (12UL)                    /*!< TT_SENT SLOW_MESSAGE: ID (Bit 12)                     */
#define TT_SENT_SLOW_MESSAGE_ID_Msk       (0xf000UL)                /*!< TT_SENT SLOW_MESSAGE: ID (Bitfield-Mask: 0x0f)        */
#define TT_SENT_SLOW_MESSAGE_CONFIG_Pos   (26UL)                    /*!< TT_SENT SLOW_MESSAGE: CONFIG (Bit 26)                 */
#define TT_SENT_SLOW_MESSAGE_CONFIG_Msk   (0x4000000UL)             /*!< TT_SENT SLOW_MESSAGE: CONFIG (Bitfield-Mask: 0x01)    */
/* ================================================  SLOW_ENHANCE_0_MESSAGE  ================================================= */
#define TT_SENT_SLOW_ENHANCE_0_MESSAGE_CRC_Pos (0UL)                /*!< TT_SENT SLOW_ENHANCE_0_MESSAGE: CRC (Bit 0)           */
#define TT_SENT_SLOW_ENHANCE_0_MESSAGE_CRC_Msk (0x3fUL)             /*!< TT_SENT SLOW_ENHANCE_0_MESSAGE: CRC (Bitfield-Mask: 0x3f) */
#define TT_SENT_SLOW_ENHANCE_0_MESSAGE_DATA_Pos (6UL)               /*!< TT_SENT SLOW_ENHANCE_0_MESSAGE: DATA (Bit 6)          */
#define TT_SENT_SLOW_ENHANCE_0_MESSAGE_DATA_Msk (0x3ffc0UL)         /*!< TT_SENT SLOW_ENHANCE_0_MESSAGE: DATA (Bitfield-Mask: 0xfff) */
#define TT_SENT_SLOW_ENHANCE_0_MESSAGE_ID_Pos (18UL)                /*!< TT_SENT SLOW_ENHANCE_0_MESSAGE: ID (Bit 18)           */
#define TT_SENT_SLOW_ENHANCE_0_MESSAGE_ID_Msk (0x3fc0000UL)         /*!< TT_SENT SLOW_ENHANCE_0_MESSAGE: ID (Bitfield-Mask: 0xff) */
#define TT_SENT_SLOW_ENHANCE_0_MESSAGE_CONFIG_Pos (26UL)            /*!< TT_SENT SLOW_ENHANCE_0_MESSAGE: CONFIG (Bit 26)       */
#define TT_SENT_SLOW_ENHANCE_0_MESSAGE_CONFIG_Msk (0x4000000UL)     /*!< TT_SENT SLOW_ENHANCE_0_MESSAGE: CONFIG (Bitfield-Mask: 0x01) */
/* ================================================  SLOW_ENHANCE_1_MESSAGE  ================================================= */
#define TT_SENT_SLOW_ENHANCE_1_MESSAGE_CRC_Pos (0UL)                /*!< TT_SENT SLOW_ENHANCE_1_MESSAGE: CRC (Bit 0)           */
#define TT_SENT_SLOW_ENHANCE_1_MESSAGE_CRC_Msk (0x3fUL)             /*!< TT_SENT SLOW_ENHANCE_1_MESSAGE: CRC (Bitfield-Mask: 0x3f) */
#define TT_SENT_SLOW_ENHANCE_1_MESSAGE_DATA_Pos (6UL)               /*!< TT_SENT SLOW_ENHANCE_1_MESSAGE: DATA (Bit 6)          */
#define TT_SENT_SLOW_ENHANCE_1_MESSAGE_DATA_Msk (0x3fffc0UL)        /*!< TT_SENT SLOW_ENHANCE_1_MESSAGE: DATA (Bitfield-Mask: 0xffff) */
#define TT_SENT_SLOW_ENHANCE_1_MESSAGE_ID_Pos (22UL)                /*!< TT_SENT SLOW_ENHANCE_1_MESSAGE: ID (Bit 22)           */
#define TT_SENT_SLOW_ENHANCE_1_MESSAGE_ID_Msk (0x3c00000UL)         /*!< TT_SENT SLOW_ENHANCE_1_MESSAGE: ID (Bitfield-Mask: 0x0f) */
#define TT_SENT_SLOW_ENHANCE_1_MESSAGE_CONFIG_Pos (26UL)            /*!< TT_SENT SLOW_ENHANCE_1_MESSAGE: CONFIG (Bit 26)       */
#define TT_SENT_SLOW_ENHANCE_1_MESSAGE_CONFIG_Msk (0x4000000UL)     /*!< TT_SENT SLOW_ENHANCE_1_MESSAGE: CONFIG (Bitfield-Mask: 0x01) */
/* ========================================================  CONTROL  ======================================================== */
#define TT_SENT_CONTROL_MESSAGE_TYPE_Pos  (0UL)                     /*!< TT_SENT CONTROL: MESSAGE_TYPE (Bit 0)                 */
#define TT_SENT_CONTROL_MESSAGE_TYPE_Msk  (0x3UL)                   /*!< TT_SENT CONTROL: MESSAGE_TYPE (Bitfield-Mask: 0x03)   */
#define TT_SENT_CONTROL_NIBBLE_NUMBER_Pos (2UL)                     /*!< TT_SENT CONTROL: NIBBLE_NUMBER (Bit 2)                */
#define TT_SENT_CONTROL_NIBBLE_NUMBER_Msk (0x1cUL)                  /*!< TT_SENT CONTROL: NIBBLE_NUMBER (Bitfield-Mask: 0x07)  */
#define TT_SENT_CONTROL_CALIB_CHECK_TYPE_Pos (5UL)                  /*!< TT_SENT CONTROL: CALIB_CHECK_TYPE (Bit 5)             */
#define TT_SENT_CONTROL_CALIB_CHECK_TYPE_Msk (0x60UL)               /*!< TT_SENT CONTROL: CALIB_CHECK_TYPE (Bitfield-Mask: 0x03) */
#define TT_SENT_CONTROL_CRC_TYPE_Pos      (7UL)                     /*!< TT_SENT CONTROL: CRC_TYPE (Bit 7)                     */
#define TT_SENT_CONTROL_CRC_TYPE_Msk      (0x80UL)                  /*!< TT_SENT CONTROL: CRC_TYPE (Bitfield-Mask: 0x01)       */
#define TT_SENT_CONTROL_FILTER_EN_Pos     (8UL)                     /*!< TT_SENT CONTROL: FILTER_EN (Bit 8)                    */
#define TT_SENT_CONTROL_FILTER_EN_Msk     (0x100UL)                 /*!< TT_SENT CONTROL: FILTER_EN (Bitfield-Mask: 0x01)      */
#define TT_SENT_CONTROL_FILTER_COUNT_Pos  (9UL)                     /*!< TT_SENT CONTROL: FILTER_COUNT (Bit 9)                 */
#define TT_SENT_CONTROL_FILTER_COUNT_Msk  (0x3fe00UL)               /*!< TT_SENT CONTROL: FILTER_COUNT (Bitfield-Mask: 0x1ff)  */
#define TT_SENT_CONTROL_SENT_EN_Pos       (18UL)                    /*!< TT_SENT CONTROL: SENT_EN (Bit 18)                     */
#define TT_SENT_CONTROL_SENT_EN_Msk       (0x40000UL)               /*!< TT_SENT CONTROL: SENT_EN (Bitfield-Mask: 0x01)        */
#define TT_SENT_CONTROL_DMA_EN_Pos        (19UL)                    /*!< TT_SENT CONTROL: DMA_EN (Bit 19)                      */
#define TT_SENT_CONTROL_DMA_EN_Msk        (0x80000UL)               /*!< TT_SENT CONTROL: DMA_EN (Bitfield-Mask: 0x01)         */
#define TT_SENT_CONTROL_PAUSE_EN_Pos      (20UL)                    /*!< TT_SENT CONTROL: PAUSE_EN (Bit 20)                    */
#define TT_SENT_CONTROL_PAUSE_EN_Msk      (0x100000UL)              /*!< TT_SENT CONTROL: PAUSE_EN (Bitfield-Mask: 0x01)       */
#define TT_SENT_CONTROL_WR_EN_Pos         (21UL)                    /*!< TT_SENT CONTROL: WR_EN (Bit 21)                       */
#define TT_SENT_CONTROL_WR_EN_Msk         (0x200000UL)              /*!< TT_SENT CONTROL: WR_EN (Bitfield-Mask: 0x01)          */
#define TT_SENT_CONTROL_STATUS_CRC_EN_Pos (22UL)                    /*!< TT_SENT CONTROL: STATUS_CRC_EN (Bit 22)               */
#define TT_SENT_CONTROL_STATUS_CRC_EN_Msk (0x400000UL)              /*!< TT_SENT CONTROL: STATUS_CRC_EN (Bitfield-Mask: 0x01)  */
#define TT_SENT_CONTROL_DATA_RECEIVE_Pos  (23UL)                    /*!< TT_SENT CONTROL: DATA_RECEIVE (Bit 23)                */
#define TT_SENT_CONTROL_DATA_RECEIVE_Msk  (0x800000UL)              /*!< TT_SENT CONTROL: DATA_RECEIVE (Bitfield-Mask: 0x01)   */
#define TT_SENT_CONTROL_IIE_Pos           (24UL)                    /*!< TT_SENT CONTROL: IIE (Bit 24)                         */
#define TT_SENT_CONTROL_IIE_Msk           (0x1000000UL)             /*!< TT_SENT CONTROL: IIE (Bitfield-Mask: 0x01)            */
#define TT_SENT_CONTROL_ALTER_CRC_EN_Pos  (25UL)                    /*!< TT_SENT CONTROL: ALTER_CRC_EN (Bit 25)                */
#define TT_SENT_CONTROL_ALTER_CRC_EN_Msk  (0x2000000UL)             /*!< TT_SENT CONTROL: ALTER_CRC_EN (Bitfield-Mask: 0x01)   */
#define TT_SENT_CONTROL_TICK_MODE_EN_Pos  (26UL)                    /*!< TT_SENT CONTROL: TICK_MODE_EN (Bit 26)                */
#define TT_SENT_CONTROL_TICK_MODE_EN_Msk  (0x4000000UL)             /*!< TT_SENT CONTROL: TICK_MODE_EN (Bitfield-Mask: 0x01)   */
/* ====================================================  PRESCALER_VALUE  ==================================================== */
#define TT_SENT_PRESCALER_VALUE_PRESCALER_Pos (0UL)                 /*!< TT_SENT PRESCALER_VALUE: PRESCALER (Bit 0)            */
#define TT_SENT_PRESCALER_VALUE_PRESCALER_Msk (0xffffUL)            /*!< TT_SENT PRESCALER_VALUE: PRESCALER (Bitfield-Mask: 0xffff) */
#define TT_SENT_PRESCALER_VALUE_Reserved0_Pos (16UL)                /*!< TT_SENT PRESCALER_VALUE: Reserved0 (Bit 16)           */
#define TT_SENT_PRESCALER_VALUE_Reserved0_Msk (0xffff0000UL)        /*!< TT_SENT PRESCALER_VALUE: Reserved0 (Bitfield-Mask: 0xffff) */
/* ======================================================  FRAME_COUNT  ====================================================== */
#define TT_SENT_FRAME_COUNT_FRAME_COUNT_Pos (0UL)                   /*!< TT_SENT FRAME_COUNT: FRAME_COUNT (Bit 0)              */
#define TT_SENT_FRAME_COUNT_FRAME_COUNT_Msk (0x1fUL)                /*!< TT_SENT FRAME_COUNT: FRAME_COUNT (Bitfield-Mask: 0x1f) */
#define TT_SENT_FRAME_COUNT_Reserved0_Pos (5UL)                     /*!< TT_SENT FRAME_COUNT: Reserved0 (Bit 5)                */
#define TT_SENT_FRAME_COUNT_Reserved0_Msk (0xffffffe0UL)            /*!< TT_SENT FRAME_COUNT: Reserved0 (Bitfield-Mask: 0x7ffffff) */
/* ======================================================  FRAME_DATA  ======================================================= */
#define TT_SENT_FRAME_DATA_DATA_Pos       (0UL)                     /*!< TT_SENT FRAME_DATA: DATA (Bit 0)                      */
#define TT_SENT_FRAME_DATA_DATA_Msk       (0xffffffffUL)            /*!< TT_SENT FRAME_DATA: DATA (Bitfield-Mask: 0xffffffff)  */
/* =======================================================  DATA_TYPE  ======================================================= */
#define TT_SENT_DATA_TYPE_CTRL_Pos        (0UL)                     /*!< TT_SENT DATA_TYPE: CTRL (Bit 0)                       */
#define TT_SENT_DATA_TYPE_CTRL_Msk        (0xffffffffUL)            /*!< TT_SENT DATA_TYPE: CTRL (Bitfield-Mask: 0xffffffff)   */
/* ========================================================  STATUS  ========================================================= */
#define TT_SENT_STATUS_FRAME_STATUS_Pos   (0UL)                     /*!< TT_SENT STATUS: FRAME_STATUS (Bit 0)                  */
#define TT_SENT_STATUS_FRAME_STATUS_Msk   (0xfUL)                   /*!< TT_SENT STATUS: FRAME_STATUS (Bitfield-Mask: 0x0f)    */
#define TT_SENT_STATUS_CRC_Pos            (4UL)                     /*!< TT_SENT STATUS: CRC (Bit 4)                           */
#define TT_SENT_STATUS_CRC_Msk            (0xf0UL)                  /*!< TT_SENT STATUS: CRC (Bitfield-Mask: 0x0f)             */
#define TT_SENT_STATUS_MONITOR_IN_Pos     (8UL)                     /*!< TT_SENT STATUS: MONITOR_IN (Bit 8)                    */
#define TT_SENT_STATUS_MONITOR_IN_Msk     (0x100UL)                 /*!< TT_SENT STATUS: MONITOR_IN (Bitfield-Mask: 0x01)      */
#define TT_SENT_STATUS_SENT_STATE_Pos     (9UL)                     /*!< TT_SENT STATUS: SENT_STATE (Bit 9)                    */
#define TT_SENT_STATUS_SENT_STATE_Msk     (0xe00UL)                 /*!< TT_SENT STATUS: SENT_STATE (Bitfield-Mask: 0x07)      */
/* ======================================================  TIME_STAMP  ======================================================= */
#define TT_SENT_TIME_STAMP_CTS_Pos        (0UL)                     /*!< TT_SENT TIME_STAMP: CTS (Bit 0)                       */
#define TT_SENT_TIME_STAMP_CTS_Msk        (0xffffffffUL)            /*!< TT_SENT TIME_STAMP: CTS (Bitfield-Mask: 0xffffffff)   */
/* =================================================  TIME_STAMP_PREDIVIDER  ================================================= */
#define TT_SENT_TIME_STAMP_PREDIVIDER_TDIV_Pos (0UL)                /*!< TT_SENT TIME_STAMP_PREDIVIDER: TDIV (Bit 0)           */
#define TT_SENT_TIME_STAMP_PREDIVIDER_TDIV_Msk (0xfffffUL)          /*!< TT_SENT TIME_STAMP_PREDIVIDER: TDIV (Bitfield-Mask: 0xfffff) */
/* =======================================================  WDT_COUNT  ======================================================= */
#define TT_SENT_WDT_COUNT_WDL_Pos         (0UL)                     /*!< TT_SENT WDT_COUNT: WDL (Bit 0)                        */
#define TT_SENT_WDT_COUNT_WDL_Msk         (0xffffUL)                /*!< TT_SENT WDT_COUNT: WDL (Bitfield-Mask: 0xffff)        */
/* ==================================================  RECEIVE_TIME_STAMP  =================================================== */
#define TT_SENT_RECEIVE_TIME_STAMP_LTS_Pos (0UL)                    /*!< TT_SENT RECEIVE_TIME_STAMP: LTS (Bit 0)               */
#define TT_SENT_RECEIVE_TIME_STAMP_LTS_Msk (0xffffffffUL)           /*!< TT_SENT RECEIVE_TIME_STAMP: LTS (Bitfield-Mask: 0xffffffff) */
/* =======================================================  SENT_SUPV  ======================================================= */
#define TT_SENT_SENT_SUPV_SUPV_Pos        (0UL)                     /*!< TT_SENT SENT_SUPV: SUPV (Bit 0)                       */
#define TT_SENT_SENT_SUPV_SUPV_Msk        (0x1UL)                   /*!< TT_SENT SENT_SUPV: SUPV (Bitfield-Mask: 0x01)         */
/* ======================================================  SPC_CONTROL  ====================================================== */
#define TT_SENT_SPC_CONTROL_LOW_PULSE_Pos (0UL)                     /*!< TT_SENT SPC_CONTROL: LOW_PULSE (Bit 0)                */
#define TT_SENT_SPC_CONTROL_LOW_PULSE_Msk (0x3fUL)                  /*!< TT_SENT SPC_CONTROL: LOW_PULSE (Bitfield-Mask: 0x3f)  */
#define TT_SENT_SPC_CONTROL_DELAY_PULSE_Pos (6UL)                   /*!< TT_SENT SPC_CONTROL: DELAY_PULSE (Bit 6)              */
#define TT_SENT_SPC_CONTROL_DELAY_PULSE_Msk (0xfc0UL)               /*!< TT_SENT SPC_CONTROL: DELAY_PULSE (Bitfield-Mask: 0x3f) */
#define TT_SENT_SPC_CONTROL_TRIG_Pos      (12UL)                    /*!< TT_SENT SPC_CONTROL: TRIG (Bit 12)                    */
#define TT_SENT_SPC_CONTROL_TRIG_Msk      (0x3000UL)                /*!< TT_SENT SPC_CONTROL: TRIG (Bitfield-Mask: 0x03)       */
#define TT_SENT_SPC_CONTROL_EXTERNAL_TRIGGER_SELECT_Pos (14UL)      /*!< TT_SENT SPC_CONTROL: EXTERNAL_TRIGGER_SELECT (Bit 14) */
#define TT_SENT_SPC_CONTROL_EXTERNAL_TRIGGER_SELECT_Msk (0x3c000UL) /*!< TT_SENT SPC_CONTROL: EXTERNAL_TRIGGER_SELECT (Bitfield-Mask: 0x0f) */
/* =======================================================  SPC_PROT  ======================================================== */
#define TT_SENT_SPC_PROT_SPC_KEY_0_Pos    (0UL)                     /*!< TT_SENT SPC_PROT: SPC_KEY_0 (Bit 0)                   */
#define TT_SENT_SPC_PROT_SPC_KEY_0_Msk    (0x1UL)                   /*!< TT_SENT SPC_PROT: SPC_KEY_0 (Bitfield-Mask: 0x01)     */
#define TT_SENT_SPC_PROT_SPC_KEY_1_Pos    (1UL)                     /*!< TT_SENT SPC_PROT: SPC_KEY_1 (Bit 1)                   */
#define TT_SENT_SPC_PROT_SPC_KEY_1_Msk    (0x2UL)                   /*!< TT_SENT SPC_PROT: SPC_KEY_1 (Bitfield-Mask: 0x01)     */
#define TT_SENT_SPC_PROT_Reserved0_Pos    (2UL)                     /*!< TT_SENT SPC_PROT: Reserved0 (Bit 2)                   */
#define TT_SENT_SPC_PROT_Reserved0_Msk    (0xfffffffcUL)            /*!< TT_SENT SPC_PROT: Reserved0 (Bitfield-Mask: 0x3fffffff) */
/* ========================================================  SENT_ID  ======================================================== */
#define TT_SENT_SENT_ID_VERSION_Pos       (0UL)                     /*!< TT_SENT SENT_ID: VERSION (Bit 0)                      */
#define TT_SENT_SENT_ID_VERSION_Msk       (0xffUL)                  /*!< TT_SENT SENT_ID: VERSION (Bitfield-Mask: 0xff)        */
#define TT_SENT_SENT_ID_BIT_WIDTH_Pos     (8UL)                     /*!< TT_SENT SENT_ID: BIT_WIDTH (Bit 8)                    */
#define TT_SENT_SENT_ID_BIT_WIDTH_Msk     (0xff00UL)                /*!< TT_SENT SENT_ID: BIT_WIDTH (Bitfield-Mask: 0xff)      */
#define TT_SENT_SENT_ID_MOUDLE_ID_Pos     (16UL)                    /*!< TT_SENT SENT_ID: MOUDLE_ID (Bit 16)                   */
#define TT_SENT_SENT_ID_MOUDLE_ID_Msk     (0xffff0000UL)            /*!< TT_SENT SENT_ID: MOUDLE_ID (Bitfield-Mask: 0xffff)    */ 


#ifdef __cplusplus
}
#endif

#endif
