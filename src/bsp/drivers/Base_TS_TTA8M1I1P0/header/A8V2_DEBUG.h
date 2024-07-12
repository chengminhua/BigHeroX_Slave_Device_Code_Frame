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

#ifndef A8V2_DEBUG_H
#define A8V2_DEBUG_H

#include "TT_Common.h"

#ifdef __cplusplus
 extern "C" {
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_DEBUG_VENDOR_ID_H                     1541
#define A8V2_DEBUG_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_DEBUG_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_DEBUG_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_DEBUG_SW_MAJOR_VERSION_H              1
#define A8V2_DEBUG_SW_MINOR_VERSION_H              1
#define A8V2_DEBUG_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_DEBUG.h and TT_Common.h file version check */
#if (A8V2_DEBUG_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_DEBUG.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_DEBUG_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_DEBUG_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_DEBUG_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_DEBUG.h and TT_Common.h are different"
#endif
#if ((A8V2_DEBUG_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_DEBUG_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_DEBUG_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_DEBUG.h and TT_Common.h are different"
#endif


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_ITM     Instrumentation Trace Macrocell (ITM)
  \brief    Type definitions for the Instrumentation Trace Macrocell (ITM)
  @{
 */

/**
  \brief  Structure type to access the Instrumentation Trace Macrocell Register (ITM).
 */
typedef struct
{
  __OM  union
  {
    __OM  uint8_t    u8;                 /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 8-bit */
    __OM  uint16_t   u16;                /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 16-bit */
    __OM  uint32   u32;                /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 32-bit */
  }  PORT [32U];                         /*!< Offset: 0x000 ( /W)  ITM Stimulus Port Registers */
        uint32 RESERVED0[864U];
  __IOM uint32 TER;                    /*!< Offset: 0xE00 (R/W)  ITM Trace Enable Register */
        uint32 RESERVED1[15U];
  __IOM uint32 TPR;                    /*!< Offset: 0xE40 (R/W)  ITM Trace Privilege Register */
        uint32 RESERVED2[15U];
  __IOM uint32 TCR;                    /*!< Offset: 0xE80 (R/W)  ITM Trace Control Register */
        uint32 RESERVED3[32U];
        uint32 RESERVED4[43U];
  __OM  uint32 LAR;                    /*!< Offset: 0xFB0 ( /W)  ITM Lock Access Register */
  __IM  uint32 LSR;                    /*!< Offset: 0xFB4 (R/ )  ITM Lock Status Register */
        uint32 RESERVED5[6U];
  __IM  uint32 PID4;                   /*!< Offset: 0xFD0 (R/ )  ITM Peripheral Identification Register #4 */
  __IM  uint32 PID5;                   /*!< Offset: 0xFD4 (R/ )  ITM Peripheral Identification Register #5 */
  __IM  uint32 PID6;                   /*!< Offset: 0xFD8 (R/ )  ITM Peripheral Identification Register #6 */
  __IM  uint32 PID7;                   /*!< Offset: 0xFDC (R/ )  ITM Peripheral Identification Register #7 */
  __IM  uint32 PID0;                   /*!< Offset: 0xFE0 (R/ )  ITM Peripheral Identification Register #0 */
  __IM  uint32 PID1;                   /*!< Offset: 0xFE4 (R/ )  ITM Peripheral Identification Register #1 */
  __IM  uint32 PID2;                   /*!< Offset: 0xFE8 (R/ )  ITM Peripheral Identification Register #2 */
  __IM  uint32 PID3;                   /*!< Offset: 0xFEC (R/ )  ITM Peripheral Identification Register #3 */
  __IM  uint32 CID0;                   /*!< Offset: 0xFF0 (R/ )  ITM Component  Identification Register #0 */
  __IM  uint32 CID1;                   /*!< Offset: 0xFF4 (R/ )  ITM Component  Identification Register #1 */
  __IM  uint32 CID2;                   /*!< Offset: 0xFF8 (R/ )  ITM Component  Identification Register #2 */
  __IM  uint32 CID3;                   /*!< Offset: 0xFFC (R/ )  ITM Component  Identification Register #3 */
} ITM_RegType;

/* ITM Trace Privilege Register Definitions */
#define TT_ITM_TPR_PRIVMASK_Pos                0U                                            /*!< ITM TPR: PRIVMASK Position */
#define TT_ITM_TPR_PRIVMASK_Msk               (0xFFFFFFFFUL /*<< ITM_TPR_PRIVMASK_Pos*/)     /*!< ITM TPR: PRIVMASK Mask */

/* ITM Trace Control Register Definitions */
#define TT_ITM_TCR_BUSY_Pos                   23U                                            /*!< ITM TCR: BUSY Position */
#define TT_ITM_TCR_BUSY_Msk                   (1UL << TT_ITM_TCR_BUSY_Pos)                      /*!< ITM TCR: BUSY Mask */

#define TT_ITM_TCR_TraceBusID_Pos             16U                                            /*!< ITM TCR: ATBID Position */
#define TT_ITM_TCR_TraceBusID_Msk             (0x7FUL << TT_ITM_TCR_TraceBusID_Pos)             /*!< ITM TCR: ATBID Mask */

#define TT_ITM_TCR_GTSFREQ_Pos                10U                                            /*!< ITM TCR: Global timestamp frequency Position */
#define TT_ITM_TCR_GTSFREQ_Msk                (3UL << TT_ITM_TCR_GTSFREQ_Pos)                   /*!< ITM TCR: Global timestamp frequency Mask */

#define TT_ITM_TCR_TSPrescale_Pos              8U                                            /*!< ITM TCR: TSPrescale Position */
#define TT_ITM_TCR_TSPrescale_Msk             (3UL << TT_ITM_TCR_TSPrescale_Pos)                /*!< ITM TCR: TSPrescale Mask */

#define TT_ITM_TCR_SWOENA_Pos                  4U                                            /*!< ITM TCR: SWOENA Position */
#define TT_ITM_TCR_SWOENA_Msk                 (1UL << TT_ITM_TCR_SWOENA_Pos)                    /*!< ITM TCR: SWOENA Mask */

#define TT_ITM_TCR_DWTENA_Pos                  3U                                            /*!< ITM TCR: DWTENA Position */
#define TT_ITM_TCR_DWTENA_Msk                 (1UL << TT_ITM_TCR_DWTENA_Pos)                    /*!< ITM TCR: DWTENA Mask */

#define TT_ITM_TCR_SYNCENA_Pos                 2U                                            /*!< ITM TCR: SYNCENA Position */
#define TT_ITM_TCR_SYNCENA_Msk                (1UL << TT_ITM_TCR_SYNCENA_Pos)                   /*!< ITM TCR: SYNCENA Mask */

#define TT_ITM_TCR_TSENA_Pos                   1U                                            /*!< ITM TCR: TSENA Position */
#define TT_ITM_TCR_TSENA_Msk                  (1UL << TT_ITM_TCR_TSENA_Pos)                     /*!< ITM TCR: TSENA Mask */

#define TT_ITM_TCR_ITMENA_Pos                  0U                                            /*!< ITM TCR: ITM Enable bit Position */
#define TT_ITM_TCR_ITMENA_Msk                 (1UL /*<< ITM_TCR_ITMENA_Pos*/)                /*!< ITM TCR: ITM Enable bit Mask */

/* ITM Lock Status Register Definitions */
#define TT_ITM_LSR_ByteAcc_Pos                 2U                                            /*!< ITM LSR: ByteAcc Position */
#define TT_ITM_LSR_ByteAcc_Msk                (1UL << TT_ITM_LSR_ByteAcc_Pos)                   /*!< ITM LSR: ByteAcc Mask */

#define TT_ITM_LSR_Access_Pos                  1U                                            /*!< ITM LSR: Access Position */
#define TT_ITM_LSR_Access_Msk                 (1UL << TT_ITM_LSR_Access_Pos)                    /*!< ITM LSR: Access Mask */

#define TT_ITM_LSR_Present_Pos                 0U                                            /*!< ITM LSR: Present Position */
#define TT_ITM_LSR_Present_Msk                (1UL /*<< ITM_LSR_Present_Pos*/)               /*!< ITM LSR: Present Mask */

/*@}*/ /* end of group CMSIS_ITM */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_DWT     Data Watchpoint and Trace (DWT)
  \brief    Type definitions for the Data Watchpoint and Trace (DWT)
  @{
 */

/**
  \brief  Structure type to access the Data Watchpoint and Trace Register (DWT).
 */
typedef struct
{
  __IOM uint32 CTRL;                   /*!< Offset: 0x000 (R/W)  Control Register */
  __IOM uint32 CYCCNT;                 /*!< Offset: 0x004 (R/W)  Cycle Count Register */
  __IOM uint32 CPICNT;                 /*!< Offset: 0x008 (R/W)  CPI Count Register */
  __IOM uint32 EXCCNT;                 /*!< Offset: 0x00C (R/W)  Exception Overhead Count Register */
  __IOM uint32 SLEEPCNT;               /*!< Offset: 0x010 (R/W)  Sleep Count Register */
  __IOM uint32 LSUCNT;                 /*!< Offset: 0x014 (R/W)  LSU Count Register */
  __IOM uint32 FOLDCNT;                /*!< Offset: 0x018 (R/W)  Folded-instruction Count Register */
  __IM  uint32 PCSR;                   /*!< Offset: 0x01C (R/ )  Program Counter Sample Register */
  __IOM uint32 COMP0;                  /*!< Offset: 0x020 (R/W)  Comparator Register 0 */
  __IOM uint32 MASK0;                  /*!< Offset: 0x024 (R/W)  Mask Register 0 */
  __IOM uint32 FUNCTION0;              /*!< Offset: 0x028 (R/W)  Function Register 0 */
        uint32 RESERVED0[1U];
  __IOM uint32 COMP1;                  /*!< Offset: 0x030 (R/W)  Comparator Register 1 */
  __IOM uint32 MASK1;                  /*!< Offset: 0x034 (R/W)  Mask Register 1 */
  __IOM uint32 FUNCTION1;              /*!< Offset: 0x038 (R/W)  Function Register 1 */
        uint32 RESERVED1[1U];
  __IOM uint32 COMP2;                  /*!< Offset: 0x040 (R/W)  Comparator Register 2 */
  __IOM uint32 MASK2;                  /*!< Offset: 0x044 (R/W)  Mask Register 2 */
  __IOM uint32 FUNCTION2;              /*!< Offset: 0x048 (R/W)  Function Register 2 */
        uint32 RESERVED2[1U];
  __IOM uint32 COMP3;                  /*!< Offset: 0x050 (R/W)  Comparator Register 3 */
  __IOM uint32 MASK3;                  /*!< Offset: 0x054 (R/W)  Mask Register 3 */
  __IOM uint32 FUNCTION3;              /*!< Offset: 0x058 (R/W)  Function Register 3 */
        uint32 RESERVED3[981U];
  __OM  uint32 LAR;                    /*!< Offset: 0xFB0 (  W)  Lock Access Register */
  __IM  uint32 LSR;                    /*!< Offset: 0xFB4 (R  )  Lock Status Register */
} DWT_RegType;

/* DWT Control Register Definitions */
#define TT_DWT_CTRL_NUMCOMP_Pos               28U                                         /*!< DWT CTRL: NUMCOMP Position */
#define TT_DWT_CTRL_NUMCOMP_Msk               (0xFUL << TT_DWT_CTRL_NUMCOMP_Pos)             /*!< DWT CTRL: NUMCOMP Mask */

#define TT_DWT_CTRL_NOTRCPKT_Pos              27U                                         /*!< DWT CTRL: NOTRCPKT Position */
#define TT_DWT_CTRL_NOTRCPKT_Msk              (0x1UL << TT_DWT_CTRL_NOTRCPKT_Pos)            /*!< DWT CTRL: NOTRCPKT Mask */

#define TT_DWT_CTRL_NOEXTTRIG_Pos             26U                                         /*!< DWT CTRL: NOEXTTRIG Position */
#define TT_DWT_CTRL_NOEXTTRIG_Msk             (0x1UL << TT_DWT_CTRL_NOEXTTRIG_Pos)           /*!< DWT CTRL: NOEXTTRIG Mask */

#define TT_DWT_CTRL_NOCYCCNT_Pos              25U                                         /*!< DWT CTRL: NOCYCCNT Position */
#define TT_DWT_CTRL_NOCYCCNT_Msk              (0x1UL << TT_DWT_CTRL_NOCYCCNT_Pos)            /*!< DWT CTRL: NOCYCCNT Mask */

#define TT_DWT_CTRL_NOPRFCNT_Pos              24U                                         /*!< DWT CTRL: NOPRFCNT Position */
#define TT_DWT_CTRL_NOPRFCNT_Msk              (0x1UL << TT_DWT_CTRL_NOPRFCNT_Pos)            /*!< DWT CTRL: NOPRFCNT Mask */

#define TT_DWT_CTRL_CYCEVTENA_Pos             22U                                         /*!< DWT CTRL: CYCEVTENA Position */
#define TT_DWT_CTRL_CYCEVTENA_Msk             (0x1UL << TT_DWT_CTRL_CYCEVTENA_Pos)           /*!< DWT CTRL: CYCEVTENA Mask */

#define TT_DWT_CTRL_FOLDEVTENA_Pos            21U                                         /*!< DWT CTRL: FOLDEVTENA Position */
#define TT_DWT_CTRL_FOLDEVTENA_Msk            (0x1UL << TT_DWT_CTRL_FOLDEVTENA_Pos)          /*!< DWT CTRL: FOLDEVTENA Mask */

#define TT_DWT_CTRL_LSUEVTENA_Pos             20U                                         /*!< DWT CTRL: LSUEVTENA Position */
#define TT_DWT_CTRL_LSUEVTENA_Msk             (0x1UL << TT_DWT_CTRL_LSUEVTENA_Pos)           /*!< DWT CTRL: LSUEVTENA Mask */

#define TT_DWT_CTRL_SLEEPEVTENA_Pos           19U                                         /*!< DWT CTRL: SLEEPEVTENA Position */
#define TT_DWT_CTRL_SLEEPEVTENA_Msk           (0x1UL << TT_DWT_CTRL_SLEEPEVTENA_Pos)         /*!< DWT CTRL: SLEEPEVTENA Mask */

#define TT_DWT_CTRL_EXCEVTENA_Pos             18U                                         /*!< DWT CTRL: EXCEVTENA Position */
#define TT_DWT_CTRL_EXCEVTENA_Msk             (0x1UL << TT_DWT_CTRL_EXCEVTENA_Pos)           /*!< DWT CTRL: EXCEVTENA Mask */

#define TT_DWT_CTRL_CPIEVTENA_Pos             17U                                         /*!< DWT CTRL: CPIEVTENA Position */
#define TT_DWT_CTRL_CPIEVTENA_Msk             (0x1UL << TT_DWT_CTRL_CPIEVTENA_Pos)           /*!< DWT CTRL: CPIEVTENA Mask */

#define TT_DWT_CTRL_EXCTRCENA_Pos             16U                                         /*!< DWT CTRL: EXCTRCENA Position */
#define TT_DWT_CTRL_EXCTRCENA_Msk             (0x1UL << TT_DWT_CTRL_EXCTRCENA_Pos)           /*!< DWT CTRL: EXCTRCENA Mask */

#define TT_DWT_CTRL_PCSAMPLENA_Pos            12U                                         /*!< DWT CTRL: PCSAMPLENA Position */
#define TT_DWT_CTRL_PCSAMPLENA_Msk            (0x1UL << TT_DWT_CTRL_PCSAMPLENA_Pos)          /*!< DWT CTRL: PCSAMPLENA Mask */

#define TT_DWT_CTRL_SYNCTAP_Pos               10U                                         /*!< DWT CTRL: SYNCTAP Position */
#define TT_DWT_CTRL_SYNCTAP_Msk               (0x3UL << TT_DWT_CTRL_SYNCTAP_Pos)             /*!< DWT CTRL: SYNCTAP Mask */

#define TT_DWT_CTRL_CYCTAP_Pos                 9U                                         /*!< DWT CTRL: CYCTAP Position */
#define TT_DWT_CTRL_CYCTAP_Msk                (0x1UL << TT_DWT_CTRL_CYCTAP_Pos)              /*!< DWT CTRL: CYCTAP Mask */

#define TT_DWT_CTRL_POSTINIT_Pos               5U                                         /*!< DWT CTRL: POSTINIT Position */
#define TT_DWT_CTRL_POSTINIT_Msk              (0xFUL << TT_DWT_CTRL_POSTINIT_Pos)            /*!< DWT CTRL: POSTINIT Mask */

#define TT_DWT_CTRL_POSTPRESET_Pos             1U                                         /*!< DWT CTRL: POSTPRESET Position */
#define TT_DWT_CTRL_POSTPRESET_Msk            (0xFUL << TT_DWT_CTRL_POSTPRESET_Pos)          /*!< DWT CTRL: POSTPRESET Mask */

#define TT_DWT_CTRL_CYCCNTENA_Pos              0U                                         /*!< DWT CTRL: CYCCNTENA Position */
#define TT_DWT_CTRL_CYCCNTENA_Msk             (0x1UL /*<< DWT_CTRL_CYCCNTENA_Pos*/)       /*!< DWT CTRL: CYCCNTENA Mask */

/* DWT CPI Count Register Definitions */
#define TT_DWT_CPICNT_CPICNT_Pos               0U                                         /*!< DWT CPICNT: CPICNT Position */
#define TT_DWT_CPICNT_CPICNT_Msk              (0xFFUL /*<< DWT_CPICNT_CPICNT_Pos*/)       /*!< DWT CPICNT: CPICNT Mask */

/* DWT Exception Overhead Count Register Definitions */
#define TT_DWT_EXCCNT_EXCCNT_Pos               0U                                         /*!< DWT EXCCNT: EXCCNT Position */
#define TT_DWT_EXCCNT_EXCCNT_Msk              (0xFFUL /*<< DWT_EXCCNT_EXCCNT_Pos*/)       /*!< DWT EXCCNT: EXCCNT Mask */

/* DWT Sleep Count Register Definitions */
#define TT_DWT_SLEEPCNT_SLEEPCNT_Pos           0U                                         /*!< DWT SLEEPCNT: SLEEPCNT Position */
#define TT_DWT_SLEEPCNT_SLEEPCNT_Msk          (0xFFUL /*<< DWT_SLEEPCNT_SLEEPCNT_Pos*/)   /*!< DWT SLEEPCNT: SLEEPCNT Mask */

/* DWT LSU Count Register Definitions */
#define TT_DWT_LSUCNT_LSUCNT_Pos               0U                                         /*!< DWT LSUCNT: LSUCNT Position */
#define TT_DWT_LSUCNT_LSUCNT_Msk              (0xFFUL /*<< DWT_LSUCNT_LSUCNT_Pos*/)       /*!< DWT LSUCNT: LSUCNT Mask */

/* DWT Folded-instruction Count Register Definitions */
#define TT_DWT_FOLDCNT_FOLDCNT_Pos             0U                                         /*!< DWT FOLDCNT: FOLDCNT Position */
#define TT_DWT_FOLDCNT_FOLDCNT_Msk            (0xFFUL /*<< DWT_FOLDCNT_FOLDCNT_Pos*/)     /*!< DWT FOLDCNT: FOLDCNT Mask */

/* DWT Comparator Mask Register Definitions */
#define TT_DWT_MASK_MASK_Pos                   0U                                         /*!< DWT MASK: MASK Position */
#define TT_DWT_MASK_MASK_Msk                  (0x1FUL /*<< DWT_MASK_MASK_Pos*/)           /*!< DWT MASK: MASK Mask */

/* DWT Comparator Function Register Definitions */
#define TT_DWT_FUNCTION_MATCHED_Pos           24U                                         /*!< DWT FUNCTION: MATCHED Position */
#define TT_DWT_FUNCTION_MATCHED_Msk           (0x1UL << TT_DWT_FUNCTION_MATCHED_Pos)         /*!< DWT FUNCTION: MATCHED Mask */

#define TT_DWT_FUNCTION_DATAVADDR1_Pos        16U                                         /*!< DWT FUNCTION: DATAVADDR1 Position */
#define TT_DWT_FUNCTION_DATAVADDR1_Msk        (0xFUL << TT_DWT_FUNCTION_DATAVADDR1_Pos)      /*!< DWT FUNCTION: DATAVADDR1 Mask */

#define TT_DWT_FUNCTION_DATAVADDR0_Pos        12U                                         /*!< DWT FUNCTION: DATAVADDR0 Position */
#define TT_DWT_FUNCTION_DATAVADDR0_Msk        (0xFUL << TT_DWT_FUNCTION_DATAVADDR0_Pos)      /*!< DWT FUNCTION: DATAVADDR0 Mask */

#define TT_DWT_FUNCTION_DATAVSIZE_Pos         10U                                         /*!< DWT FUNCTION: DATAVSIZE Position */
#define TT_DWT_FUNCTION_DATAVSIZE_Msk         (0x3UL << TT_DWT_FUNCTION_DATAVSIZE_Pos)       /*!< DWT FUNCTION: DATAVSIZE Mask */

#define TT_DWT_FUNCTION_LNK1ENA_Pos            9U                                         /*!< DWT FUNCTION: LNK1ENA Position */
#define TT_DWT_FUNCTION_LNK1ENA_Msk           (0x1UL << TT_DWT_FUNCTION_LNK1ENA_Pos)         /*!< DWT FUNCTION: LNK1ENA Mask */

#define TT_DWT_FUNCTION_DATAVMATCH_Pos         8U                                         /*!< DWT FUNCTION: DATAVMATCH Position */
#define TT_DWT_FUNCTION_DATAVMATCH_Msk        (0x1UL << TT_DWT_FUNCTION_DATAVMATCH_Pos)      /*!< DWT FUNCTION: DATAVMATCH Mask */

#define TT_DWT_FUNCTION_CYCMATCH_Pos           7U                                         /*!< DWT FUNCTION: CYCMATCH Position */
#define TT_DWT_FUNCTION_CYCMATCH_Msk          (0x1UL << TT_DWT_FUNCTION_CYCMATCH_Pos)        /*!< DWT FUNCTION: CYCMATCH Mask */

#define TT_DWT_FUNCTION_EMITRANGE_Pos          5U                                         /*!< DWT FUNCTION: EMITRANGE Position */
#define TT_DWT_FUNCTION_EMITRANGE_Msk         (0x1UL << TT_DWT_FUNCTION_EMITRANGE_Pos)       /*!< DWT FUNCTION: EMITRANGE Mask */

#define TT_DWT_FUNCTION_FUNCTION_Pos           0U                                         /*!< DWT FUNCTION: FUNCTION Position */
#define TT_DWT_FUNCTION_FUNCTION_Msk          (0xFUL /*<< DWT_FUNCTION_FUNCTION_Pos*/)    /*!< DWT FUNCTION: FUNCTION Mask */

/*@}*/ /* end of group CMSIS_DWT */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_TPI     Trace Port Interface (TPI)
  \brief    Type definitions for the Trace Port Interface (TPI)
  @{
 */

/**
  \brief  Structure type to access the Trace Port Interface Register (TPI).
 */
typedef struct
{
  __IM  uint32 SSPSR;                  /*!< Offset: 0x000 (R/ )  Supported Parallel Port Size Register */
  __IOM uint32 CSPSR;                  /*!< Offset: 0x004 (R/W)  Current Parallel Port Size Register */
        uint32 RESERVED0[2U];
  __IOM uint32 ACPR;                   /*!< Offset: 0x010 (R/W)  Asynchronous Clock Prescaler Register */
        uint32 RESERVED1[55U];
  __IOM uint32 SPPR;                   /*!< Offset: 0x0F0 (R/W)  Selected Pin Protocol Register */
        uint32 RESERVED2[131U];
  __IM  uint32 FFSR;                   /*!< Offset: 0x300 (R/ )  Formatter and Flush Status Register */
  __IOM uint32 FFCR;                   /*!< Offset: 0x304 (R/W)  Formatter and Flush Control Register */
  __IM  uint32 FSCR;                   /*!< Offset: 0x308 (R/ )  Formatter Synchronization Counter Register */
        uint32 RESERVED3[759U];
  __IM  uint32 TRIGGER;                /*!< Offset: 0xEE8 (R/ )  TRIGGER Register */
  __IM  uint32 FIFO0;                  /*!< Offset: 0xEEC (R/ )  Integration ETM Data */
  __IM  uint32 ITATBCTR2;              /*!< Offset: 0xEF0 (R/ )  ITATBCTR2 */
        uint32 RESERVED4[1U];
  __IM  uint32 ITATBCTR0;              /*!< Offset: 0xEF8 (R/ )  ITATBCTR0 */
  __IM  uint32 FIFO1;                  /*!< Offset: 0xEFC (R/ )  Integration ITM Data */
  __IOM uint32 ITCTRL;                 /*!< Offset: 0xF00 (R/W)  Integration Mode Control */
        uint32 RESERVED5[39U];
  __IOM uint32 CLAIMSET;               /*!< Offset: 0xFA0 (R/W)  Claim tag set */
  __IOM uint32 CLAIMCLR;               /*!< Offset: 0xFA4 (R/W)  Claim tag clear */
        uint32 RESERVED7[8U];
  __IM  uint32 DEVID;                  /*!< Offset: 0xFC8 (R/ )  TPIU_DEVID */
  __IM  uint32 DEVTYPE;                /*!< Offset: 0xFCC (R/ )  TPIU_DEVTYPE */
} TPI_RegType;

/* TPI Asynchronous Clock Prescaler Register Definitions */
#define TT_TPI_ACPR_PRESCALER_Pos              0U                                         /*!< TPI ACPR: PRESCALER Position */
#define TT_TPI_ACPR_PRESCALER_Msk             (0x1FFFUL /*<< TPI_ACPR_PRESCALER_Pos*/)    /*!< TPI ACPR: PRESCALER Mask */

/* TPI Selected Pin Protocol Register Definitions */
#define TT_TPI_SPPR_TXMODE_Pos                 0U                                         /*!< TPI SPPR: TXMODE Position */
#define TT_TPI_SPPR_TXMODE_Msk                (0x3UL /*<< TPI_SPPR_TXMODE_Pos*/)          /*!< TPI SPPR: TXMODE Mask */

/* TPI Formatter and Flush Status Register Definitions */
#define TT_TPI_FFSR_FtNonStop_Pos              3U                                         /*!< TPI FFSR: FtNonStop Position */
#define TT_TPI_FFSR_FtNonStop_Msk             (0x1UL << TT_TPI_FFSR_FtNonStop_Pos)           /*!< TPI FFSR: FtNonStop Mask */

#define TT_TPI_FFSR_TCPresent_Pos              2U                                         /*!< TPI FFSR: TCPresent Position */
#define TT_TPI_FFSR_TCPresent_Msk             (0x1UL << TT_TPI_FFSR_TCPresent_Pos)           /*!< TPI FFSR: TCPresent Mask */

#define TT_TPI_FFSR_FtStopped_Pos              1U                                         /*!< TPI FFSR: FtStopped Position */
#define TT_TPI_FFSR_FtStopped_Msk             (0x1UL << TT_TPI_FFSR_FtStopped_Pos)           /*!< TPI FFSR: FtStopped Mask */

#define TT_TPI_FFSR_FlInProg_Pos               0U                                         /*!< TPI FFSR: FlInProg Position */
#define TT_TPI_FFSR_FlInProg_Msk              (0x1UL /*<< TPI_FFSR_FlInProg_Pos*/)        /*!< TPI FFSR: FlInProg Mask */

/* TPI Formatter and Flush Control Register Definitions */
#define TT_TPI_FFCR_TrigIn_Pos                 8U                                         /*!< TPI FFCR: TrigIn Position */
#define TT_TPI_FFCR_TrigIn_Msk                (0x1UL << TT_TPI_FFCR_TrigIn_Pos)              /*!< TPI FFCR: TrigIn Mask */

#define TT_TPI_FFCR_EnFCont_Pos                1U                                         /*!< TPI FFCR: EnFCont Position */
#define TT_TPI_FFCR_EnFCont_Msk               (0x1UL << TT_TPI_FFCR_EnFCont_Pos)             /*!< TPI FFCR: EnFCont Mask */

/* TPI TRIGGER Register Definitions */
#define TT_TPI_TRIGGER_TRIGGER_Pos             0U                                         /*!< TPI TRIGGER: TRIGGER Position */
#define TT_TPI_TRIGGER_TRIGGER_Msk            (0x1UL /*<< TPI_TRIGGER_TRIGGER_Pos*/)      /*!< TPI TRIGGER: TRIGGER Mask */

/* TPI Integration ETM Data Register Definitions (FIFO0) */
#define TT_TPI_FIFO0_ITM_ATVALID_Pos          29U                                         /*!< TPI FIFO0: ITM_ATVALID Position */
#define TT_TPI_FIFO0_ITM_ATVALID_Msk          (0x1UL << TT_TPI_FIFO0_ITM_ATVALID_Pos)        /*!< TPI FIFO0: ITM_ATVALID Mask */

#define TT_TPI_FIFO0_ITM_bytecount_Pos        27U                                         /*!< TPI FIFO0: ITM_bytecount Position */
#define TT_TPI_FIFO0_ITM_bytecount_Msk        (0x3UL << TT_TPI_FIFO0_ITM_bytecount_Pos)      /*!< TPI FIFO0: ITM_bytecount Mask */

#define TT_TPI_FIFO0_ETM_ATVALID_Pos          26U                                         /*!< TPI FIFO0: ETM_ATVALID Position */
#define TT_TPI_FIFO0_ETM_ATVALID_Msk          (0x1UL << TT_TPI_FIFO0_ETM_ATVALID_Pos)        /*!< TPI FIFO0: ETM_ATVALID Mask */

#define TT_TPI_FIFO0_ETM_bytecount_Pos        24U                                         /*!< TPI FIFO0: ETM_bytecount Position */
#define TT_TPI_FIFO0_ETM_bytecount_Msk        (0x3UL << TT_TPI_FIFO0_ETM_bytecount_Pos)      /*!< TPI FIFO0: ETM_bytecount Mask */

#define TT_TPI_FIFO0_ETM2_Pos                 16U                                         /*!< TPI FIFO0: ETM2 Position */
#define TT_TPI_FIFO0_ETM2_Msk                 (0xFFUL << TT_TPI_FIFO0_ETM2_Pos)              /*!< TPI FIFO0: ETM2 Mask */

#define TT_TPI_FIFO0_ETM1_Pos                  8U                                         /*!< TPI FIFO0: ETM1 Position */
#define TT_TPI_FIFO0_ETM1_Msk                 (0xFFUL << TT_TPI_FIFO0_ETM1_Pos)              /*!< TPI FIFO0: ETM1 Mask */

#define TT_TPI_FIFO0_ETM0_Pos                  0U                                         /*!< TPI FIFO0: ETM0 Position */
#define TT_TPI_FIFO0_ETM0_Msk                 (0xFFUL /*<< TPI_FIFO0_ETM0_Pos*/)          /*!< TPI FIFO0: ETM0 Mask */

/* TPI ITATBCTR2 Register Definitions */
#define TT_TPI_ITATBCTR2_ATREADY2_Pos          0U                                         /*!< TPI ITATBCTR2: ATREADY2 Position */
#define TT_TPI_ITATBCTR2_ATREADY2_Msk         (0x1UL /*<< TPI_ITATBCTR2_ATREADY2_Pos*/)   /*!< TPI ITATBCTR2: ATREADY2 Mask */

#define TT_TPI_ITATBCTR2_ATREADY1_Pos          0U                                         /*!< TPI ITATBCTR2: ATREADY1 Position */
#define TT_TPI_ITATBCTR2_ATREADY1_Msk         (0x1UL /*<< TPI_ITATBCTR2_ATREADY1_Pos*/)   /*!< TPI ITATBCTR2: ATREADY1 Mask */

/* TPI Integration ITM Data Register Definitions (FIFO1) */
#define TT_TPI_FIFO1_ITM_ATVALID_Pos          29U                                         /*!< TPI FIFO1: ITM_ATVALID Position */
#define TT_TPI_FIFO1_ITM_ATVALID_Msk          (0x1UL << TT_TPI_FIFO1_ITM_ATVALID_Pos)        /*!< TPI FIFO1: ITM_ATVALID Mask */

#define TT_TPI_FIFO1_ITM_bytecount_Pos        27U                                         /*!< TPI FIFO1: ITM_bytecount Position */
#define TT_TPI_FIFO1_ITM_bytecount_Msk        (0x3UL << TT_TPI_FIFO1_ITM_bytecount_Pos)      /*!< TPI FIFO1: ITM_bytecount Mask */

#define TT_TPI_FIFO1_ETM_ATVALID_Pos          26U                                         /*!< TPI FIFO1: ETM_ATVALID Position */
#define TT_TPI_FIFO1_ETM_ATVALID_Msk          (0x1UL << TT_TPI_FIFO1_ETM_ATVALID_Pos)        /*!< TPI FIFO1: ETM_ATVALID Mask */

#define TT_TPI_FIFO1_ETM_bytecount_Pos        24U                                         /*!< TPI FIFO1: ETM_bytecount Position */
#define TT_TPI_FIFO1_ETM_bytecount_Msk        (0x3UL << TT_TPI_FIFO1_ETM_bytecount_Pos)      /*!< TPI FIFO1: ETM_bytecount Mask */

#define TT_TPI_FIFO1_ITM2_Pos                 16U                                         /*!< TPI FIFO1: ITM2 Position */
#define TT_TPI_FIFO1_ITM2_Msk                 (0xFFUL << TT_TPI_FIFO1_ITM2_Pos)              /*!< TPI FIFO1: ITM2 Mask */

#define TT_TPI_FIFO1_ITM1_Pos                  8U                                         /*!< TPI FIFO1: ITM1 Position */
#define TT_TPI_FIFO1_ITM1_Msk                 (0xFFUL << TT_TPI_FIFO1_ITM1_Pos)              /*!< TPI FIFO1: ITM1 Mask */

#define TT_TPI_FIFO1_ITM0_Pos                  0U                                         /*!< TPI FIFO1: ITM0 Position */
#define TT_TPI_FIFO1_ITM0_Msk                 (0xFFUL /*<< TPI_FIFO1_ITM0_Pos*/)          /*!< TPI FIFO1: ITM0 Mask */

/* TPI ITATBCTR0 Register Definitions */
#define TT_TPI_ITATBCTR0_ATREADY2_Pos          0U                                         /*!< TPI ITATBCTR0: ATREADY2 Position */
#define TT_TPI_ITATBCTR0_ATREADY2_Msk         (0x1UL /*<< TPI_ITATBCTR0_ATREADY2_Pos*/)   /*!< TPI ITATBCTR0: ATREADY2 Mask */

#define TT_TPI_ITATBCTR0_ATREADY1_Pos          0U                                         /*!< TPI ITATBCTR0: ATREADY1 Position */
#define TT_TPI_ITATBCTR0_ATREADY1_Msk         (0x1UL /*<< TPI_ITATBCTR0_ATREADY1_Pos*/)   /*!< TPI ITATBCTR0: ATREADY1 Mask */

/* TPI Integration Mode Control Register Definitions */
#define TT_TPI_ITCTRL_Mode_Pos                 0U                                         /*!< TPI ITCTRL: Mode Position */
#define TT_TPI_ITCTRL_Mode_Msk                (0x3UL /*<< TPI_ITCTRL_Mode_Pos*/)          /*!< TPI ITCTRL: Mode Mask */

/* TPI DEVID Register Definitions */
#define TT_TPI_DEVID_NRZVALID_Pos             11U                                         /*!< TPI DEVID: NRZVALID Position */
#define TT_TPI_DEVID_NRZVALID_Msk             (0x1UL << TT_TPI_DEVID_NRZVALID_Pos)           /*!< TPI DEVID: NRZVALID Mask */

#define TT_TPI_DEVID_MANCVALID_Pos            10U                                         /*!< TPI DEVID: MANCVALID Position */
#define TT_TPI_DEVID_MANCVALID_Msk            (0x1UL << TT_TPI_DEVID_MANCVALID_Pos)          /*!< TPI DEVID: MANCVALID Mask */

#define TT_TPI_DEVID_PTINVALID_Pos             9U                                         /*!< TPI DEVID: PTINVALID Position */
#define TT_TPI_DEVID_PTINVALID_Msk            (0x1UL << TT_TPI_DEVID_PTINVALID_Pos)          /*!< TPI DEVID: PTINVALID Mask */

#define TT_TPI_DEVID_MinBufSz_Pos              6U                                         /*!< TPI DEVID: MinBufSz Position */
#define TT_TPI_DEVID_MinBufSz_Msk             (0x7UL << TT_TPI_DEVID_MinBufSz_Pos)           /*!< TPI DEVID: MinBufSz Mask */

#define TT_TPI_DEVID_AsynClkIn_Pos             5U                                         /*!< TPI DEVID: AsynClkIn Position */
#define TT_TPI_DEVID_AsynClkIn_Msk            (0x1UL << TT_TPI_DEVID_AsynClkIn_Pos)          /*!< TPI DEVID: AsynClkIn Mask */

#define TT_TPI_DEVID_NrTraceInput_Pos          0U                                         /*!< TPI DEVID: NrTraceInput Position */
#define TT_TPI_DEVID_NrTraceInput_Msk         (0x1FUL /*<< TPI_DEVID_NrTraceInput_Pos*/)  /*!< TPI DEVID: NrTraceInput Mask */

/* TPI DEVTYPE Register Definitions */
#define TT_TPI_DEVTYPE_SubType_Pos             4U                                         /*!< TPI DEVTYPE: SubType Position */
#define TT_TPI_DEVTYPE_SubType_Msk            (0xFUL /*<< TPI_DEVTYPE_SubType_Pos*/)      /*!< TPI DEVTYPE: SubType Mask */

#define TT_TPI_DEVTYPE_MajorType_Pos           0U                                         /*!< TPI DEVTYPE: MajorType Position */
#define TT_TPI_DEVTYPE_MajorType_Msk          (0xFUL << TT_TPI_DEVTYPE_MajorType_Pos)        /*!< TPI DEVTYPE: MajorType Mask */

/*@}*/ /* end of group CMSIS_TPI */

/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_CoreDebug       Core Debug Registers (CoreDebug)
  \brief    Type definitions for the Core Debug Registers
  @{
 */

/**
  \brief  Structure type to access the Core Debug Register (CoreDebug).
 */
typedef struct
{
  __IOM uint32 DHCSR;                  /*!< Offset: 0x000 (R/W)  Debug Halting Control and Status Register */
  __OM  uint32 DCRSR;                  /*!< Offset: 0x004 ( /W)  Debug Core Register Selector Register */
  __IOM uint32 DCRDR;                  /*!< Offset: 0x008 (R/W)  Debug Core Register Data Register */
  __IOM uint32 DEMCR;                  /*!< Offset: 0x00C (R/W)  Debug Exception and Monitor Control Register */
} CoreDebug_RegType;

/* Debug Halting Control and Status Register Definitions */
#define TT_CoreDebug_DHCSR_DBGKEY_Pos         16U                                            /*!< CoreDebug DHCSR: DBGKEY Position */
#define TT_CoreDebug_DHCSR_DBGKEY_Msk         (0xFFFFUL << TT_CoreDebug_DHCSR_DBGKEY_Pos)       /*!< CoreDebug DHCSR: DBGKEY Mask */

#define TT_CoreDebug_DHCSR_S_RESET_ST_Pos     25U                                            /*!< CoreDebug DHCSR: S_RESET_ST Position */
#define TT_CoreDebug_DHCSR_S_RESET_ST_Msk     (1UL << TT_CoreDebug_DHCSR_S_RESET_ST_Pos)        /*!< CoreDebug DHCSR: S_RESET_ST Mask */

#define TT_CoreDebug_DHCSR_S_RETIRE_ST_Pos    24U                                            /*!< CoreDebug DHCSR: S_RETIRE_ST Position */
#define TT_CoreDebug_DHCSR_S_RETIRE_ST_Msk    (1UL << TT_CoreDebug_DHCSR_S_RETIRE_ST_Pos)       /*!< CoreDebug DHCSR: S_RETIRE_ST Mask */

#define TT_CoreDebug_DHCSR_S_LOCKUP_Pos       19U                                            /*!< CoreDebug DHCSR: S_LOCKUP Position */
#define TT_CoreDebug_DHCSR_S_LOCKUP_Msk       (1UL << TT_CoreDebug_DHCSR_S_LOCKUP_Pos)          /*!< CoreDebug DHCSR: S_LOCKUP Mask */

#define TT_CoreDebug_DHCSR_S_SLEEP_Pos        18U                                            /*!< CoreDebug DHCSR: S_SLEEP Position */
#define TT_CoreDebug_DHCSR_S_SLEEP_Msk        (1UL << TT_CoreDebug_DHCSR_S_SLEEP_Pos)           /*!< CoreDebug DHCSR: S_SLEEP Mask */

#define TT_CoreDebug_DHCSR_S_HALT_Pos         17U                                            /*!< CoreDebug DHCSR: S_HALT Position */
#define TT_CoreDebug_DHCSR_S_HALT_Msk         (1UL << TT_CoreDebug_DHCSR_S_HALT_Pos)            /*!< CoreDebug DHCSR: S_HALT Mask */

#define TT_CoreDebug_DHCSR_S_REGRDY_Pos       16U                                            /*!< CoreDebug DHCSR: S_REGRDY Position */
#define TT_CoreDebug_DHCSR_S_REGRDY_Msk       (1UL << TT_CoreDebug_DHCSR_S_REGRDY_Pos)          /*!< CoreDebug DHCSR: S_REGRDY Mask */

#define TT_CoreDebug_DHCSR_C_SNAPSTALL_Pos     5U                                            /*!< CoreDebug DHCSR: C_SNAPSTALL Position */
#define TT_CoreDebug_DHCSR_C_SNAPSTALL_Msk    (1UL << TT_CoreDebug_DHCSR_C_SNAPSTALL_Pos)       /*!< CoreDebug DHCSR: C_SNAPSTALL Mask */

#define TT_CoreDebug_DHCSR_C_MASKINTS_Pos      3U                                            /*!< CoreDebug DHCSR: C_MASKINTS Position */
#define TT_CoreDebug_DHCSR_C_MASKINTS_Msk     (1UL << TT_CoreDebug_DHCSR_C_MASKINTS_Pos)        /*!< CoreDebug DHCSR: C_MASKINTS Mask */

#define TT_CoreDebug_DHCSR_C_STEP_Pos          2U                                            /*!< CoreDebug DHCSR: C_STEP Position */
#define TT_CoreDebug_DHCSR_C_STEP_Msk         (1UL << TT_CoreDebug_DHCSR_C_STEP_Pos)            /*!< CoreDebug DHCSR: C_STEP Mask */

#define TT_CoreDebug_DHCSR_C_HALT_Pos          1U                                            /*!< CoreDebug DHCSR: C_HALT Position */
#define TT_CoreDebug_DHCSR_C_HALT_Msk         (1UL << TT_CoreDebug_DHCSR_C_HALT_Pos)            /*!< CoreDebug DHCSR: C_HALT Mask */

#define TT_CoreDebug_DHCSR_C_DEBUGEN_Pos       0U                                            /*!< CoreDebug DHCSR: C_DEBUGEN Position */
#define TT_CoreDebug_DHCSR_C_DEBUGEN_Msk      (1UL /*<< CoreDebug_DHCSR_C_DEBUGEN_Pos*/)     /*!< CoreDebug DHCSR: C_DEBUGEN Mask */

/* Debug Core Register Selector Register Definitions */
#define TT_CoreDebug_DCRSR_REGWnR_Pos         16U                                            /*!< CoreDebug DCRSR: REGWnR Position */
#define TT_CoreDebug_DCRSR_REGWnR_Msk         (1UL << TT_CoreDebug_DCRSR_REGWnR_Pos)            /*!< CoreDebug DCRSR: REGWnR Mask */

#define TT_CoreDebug_DCRSR_REGSEL_Pos          0U                                            /*!< CoreDebug DCRSR: REGSEL Position */
#define TT_CoreDebug_DCRSR_REGSEL_Msk         (0x1FUL /*<< CoreDebug_DCRSR_REGSEL_Pos*/)     /*!< CoreDebug DCRSR: REGSEL Mask */

/* Debug Exception and Monitor Control Register Definitions */
#define TT_CoreDebug_DEMCR_TRCENA_Pos         24U                                            /*!< CoreDebug DEMCR: TRCENA Position */
#define TT_CoreDebug_DEMCR_TRCENA_Msk         (1UL << TT_CoreDebug_DEMCR_TRCENA_Pos)            /*!< CoreDebug DEMCR: TRCENA Mask */

#define TT_CoreDebug_DEMCR_MON_REQ_Pos        19U                                            /*!< CoreDebug DEMCR: MON_REQ Position */
#define TT_CoreDebug_DEMCR_MON_REQ_Msk        (1UL << TT_CoreDebug_DEMCR_MON_REQ_Pos)           /*!< CoreDebug DEMCR: MON_REQ Mask */

#define TT_CoreDebug_DEMCR_MON_STEP_Pos       18U                                            /*!< CoreDebug DEMCR: MON_STEP Position */
#define TT_CoreDebug_DEMCR_MON_STEP_Msk       (1UL << TT_CoreDebug_DEMCR_MON_STEP_Pos)          /*!< CoreDebug DEMCR: MON_STEP Mask */

#define TT_CoreDebug_DEMCR_MON_PEND_Pos       17U                                            /*!< CoreDebug DEMCR: MON_PEND Position */
#define TT_CoreDebug_DEMCR_MON_PEND_Msk       (1UL << TT_CoreDebug_DEMCR_MON_PEND_Pos)          /*!< CoreDebug DEMCR: MON_PEND Mask */

#define TT_CoreDebug_DEMCR_MON_EN_Pos         16U                                            /*!< CoreDebug DEMCR: MON_EN Position */
#define TT_CoreDebug_DEMCR_MON_EN_Msk         (1UL << TT_CoreDebug_DEMCR_MON_EN_Pos)            /*!< CoreDebug DEMCR: MON_EN Mask */

#define TT_CoreDebug_DEMCR_VC_HARDERR_Pos     10U                                            /*!< CoreDebug DEMCR: VC_HARDERR Position */
#define TT_CoreDebug_DEMCR_VC_HARDERR_Msk     (1UL << TT_CoreDebug_DEMCR_VC_HARDERR_Pos)        /*!< CoreDebug DEMCR: VC_HARDERR Mask */

#define TT_CoreDebug_DEMCR_VC_INTERR_Pos       9U                                            /*!< CoreDebug DEMCR: VC_INTERR Position */
#define TT_CoreDebug_DEMCR_VC_INTERR_Msk      (1UL << TT_CoreDebug_DEMCR_VC_INTERR_Pos)         /*!< CoreDebug DEMCR: VC_INTERR Mask */

#define TT_CoreDebug_DEMCR_VC_BUSERR_Pos       8U                                            /*!< CoreDebug DEMCR: VC_BUSERR Position */
#define TT_CoreDebug_DEMCR_VC_BUSERR_Msk      (1UL << TT_CoreDebug_DEMCR_VC_BUSERR_Pos)         /*!< CoreDebug DEMCR: VC_BUSERR Mask */

#define TT_CoreDebug_DEMCR_VC_STATERR_Pos      7U                                            /*!< CoreDebug DEMCR: VC_STATERR Position */
#define TT_CoreDebug_DEMCR_VC_STATERR_Msk     (1UL << TT_CoreDebug_DEMCR_VC_STATERR_Pos)        /*!< CoreDebug DEMCR: VC_STATERR Mask */

#define TT_CoreDebug_DEMCR_VC_CHKERR_Pos       6U                                            /*!< CoreDebug DEMCR: VC_CHKERR Position */
#define TT_CoreDebug_DEMCR_VC_CHKERR_Msk      (1UL << TT_CoreDebug_DEMCR_VC_CHKERR_Pos)         /*!< CoreDebug DEMCR: VC_CHKERR Mask */

#define TT_CoreDebug_DEMCR_VC_NOCPERR_Pos      5U                                            /*!< CoreDebug DEMCR: VC_NOCPERR Position */
#define TT_CoreDebug_DEMCR_VC_NOCPERR_Msk     (1UL << TT_CoreDebug_DEMCR_VC_NOCPERR_Pos)        /*!< CoreDebug DEMCR: VC_NOCPERR Mask */

#define TT_CoreDebug_DEMCR_VC_MMERR_Pos        4U                                            /*!< CoreDebug DEMCR: VC_MMERR Position */
#define TT_CoreDebug_DEMCR_VC_MMERR_Msk       (1UL << TT_CoreDebug_DEMCR_VC_MMERR_Pos)          /*!< CoreDebug DEMCR: VC_MMERR Mask */

#define TT_CoreDebug_DEMCR_VC_CORERESET_Pos    0U                                            /*!< CoreDebug DEMCR: VC_CORERESET Position */
#define TT_CoreDebug_DEMCR_VC_CORERESET_Msk   (1UL /*<< CoreDebug_DEMCR_VC_CORERESET_Pos*/)  /*!< CoreDebug DEMCR: VC_CORERESET Mask */



/* Memory mapping of Core Hardware */
#define TT_ITM_BASE            (0xE0000000UL)                            /*!< ITM Base Address */
#define TT_DWT_BASE            (0xE0001000UL)                            /*!< DWT Base Address */
#define TT_TPI_BASE            (0xE0040000UL)                            /*!< TPI Base Address */
#define TT_CoreDebug_BASE      (0xE000EDF0UL)                            /*!< Core Debug Base Address */

#define TT_ITM                 ((ITM_RegType       *)     TT_ITM_BASE      )   /*!< ITM configuration struct */
#define TT_DWT                 ((DWT_RegType       *)     TT_DWT_BASE      )   /*!< DWT configuration struct */
#define TT_TPI                 ((TPI_RegType       *)     TT_TPI_BASE      )   /*!< TPI configuration struct */
#define TT_CoreDebug           ((CoreDebug_RegType *)     TT_CoreDebug_BASE)   /*!< Core Debug configuration struct */



#ifdef __cplusplus
}
#endif

#endif

