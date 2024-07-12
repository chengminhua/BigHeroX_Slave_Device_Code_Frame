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
#ifndef A8V2E_FTM_H
#define A8V2E_FTM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_FTM_VENDOR_ID_H                     1541
#define A8V2E_FTM_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_FTM_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_FTM_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_FTM_SW_MAJOR_VERSION_H              1
#define A8V2E_FTM_SW_MINOR_VERSION_H              1
#define A8V2E_FTM_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_FTM.h and TT_Common.h file version check */
#if (A8V2E_FTM_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_FTM.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_FTM_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_FTM_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_FTM_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_FTM.h and TT_Common.h are different"
#endif
#if ((A8V2E_FTM_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_FTM_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_FTM_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_FTM.h and TT_Common.h are different"
#endif
 
/* =========================================================================================================================== */
/* ================                                          TT_FTM                                          ================ */
/* =========================================================================================================================== */
/**
  * @brief FlexTimer Module 0 (TT_FTM)
  */
typedef struct {                                /*!< (@ 0x400A5000) TT_FTM0 Structure                                          */
  __IOM uint32_t  SC;                           /*!< (@ 0x00000000) Status And Control                                         */
  __IOM uint32_t  CNT;                          /*!< (@ 0x00000004) Counter                                                    */
  __IOM uint32_t  MOD;                          /*!< (@ 0x00000008) Modulo                                                     */
  struct
  {
    __IOM uint32_t  CnSC;                       /*!< (@ 0x0000000C) Channel (n) Status And Control                             */
    __IOM uint32_t  CnV;                        /*!< (@ 0x00000010) Channel (n) Value                                          */
  }CONTROLS[8];
  __IOM uint32_t  CNTIN;                        /*!< (@ 0x0000004C) Counter Initial Value                                      */
  __IOM uint32_t  STATUS;                       /*!< (@ 0x00000050) Capture And Compare Status                                 */
  __IOM uint32_t  MODE;                         /*!< (@ 0x00000054) Features Mode Selection                                    */
  __IOM uint32_t  SYNC;                         /*!< (@ 0x00000058) Synchronization                                            */
  __IOM uint32_t  OUTINIT;                      /*!< (@ 0x0000005C) Initial State For Channels Output                          */
  __IOM uint32_t  OUTMASK;                      /*!< (@ 0x00000060) Output Mask                                                */
  __IOM uint32_t  COMBINE;                      /*!< (@ 0x00000064) Function For Linked Channels                               */
  __IOM uint32_t  DEADTIME;                     /*!< (@ 0x00000068) Deadtime Configuration                                     */
  __IOM uint32_t  EXTTRIG;                      /*!< (@ 0x0000006C) FTM External Trigger                                       */
  __IOM uint32_t  POL;                          /*!< (@ 0x00000070) Channels Polarity                                          */
  __IOM uint32_t  FMS;                          /*!< (@ 0x00000074) Fault Mode Status                                          */
  __IOM uint32_t  FILTER;                       /*!< (@ 0x00000078) Input Capture Filter Control                               */
  __IOM uint32_t  FLTCTRL;                      /*!< (@ 0x0000007C) Fault Control                                              */
  __IOM uint32_t  QDCTRL;                       /*!< (@ 0x00000080) Quadrature Decoder Control And Status                      */
  __IOM uint32_t  CONF;                         /*!< (@ 0x00000084) Configuration                                              */
  __IOM uint32_t  FLTPOL;                       /*!< (@ 0x00000088) FTM Fault Input Polarity                                   */
  __IOM uint32_t  SYNCONF;                      /*!< (@ 0x0000008C) Synchronization Configuration                              */
  __IOM uint32_t  INVCTRL;                      /*!< (@ 0x00000090) FTM Inverting Control                                      */
  __IOM uint32_t  SWOCTRL;                      /*!< (@ 0x00000094) FTM Software Output Control                                */
  __IOM uint32_t  PWMLOAD;                      /*!< (@ 0x00000098) FTM PWM Load                                               */
  __IOM uint32_t  HCR;                          /*!< (@ 0x0000009C) Half Cycle Register                                        */
  struct
  {
    __IOM uint32_t  PAIRnDEADTIME;              /*!< (@ 0x000000A0) Pair n Deadtime Configuration                              */
    __IM  uint32_t  RESERVED;
  }PAIRDEADTIME[4];
  __IM  uint32_t  RESERVED3[81];
  __IOM uint32_t  MOD_MIRROR;                   /*!< (@ 0x00000200) Mirror of Modulo Value                                     */
  __IOM uint32_t  CnV_MIRROR[8];                /*!< (@ 0x00000204) Mirror of Channel (n) Match Value                          */
  __IM  uint32_t  RESERVED4[885];
  __IOM uint32_t  SV_ADDR;                      /*!< (@ 0x00000FF8) Mirror of Modulo Value                                     */
  __IM  uint32_t  ID_REG;                       /*!< (@ 0x00000FFC) Mirror of Modulo Value                                     */
} TT_FTM_Type;                                  /*!< Size = 548 (0x224)                                                        */

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */
#define TT_FTM0_BASE                	  0x40110000UL
#define TT_FTM1_BASE                	  0x40111000UL
#define TT_FTM2_BASE                	  0x400D4000UL
#define TT_FTM3_BASE                	  0x400D5000UL
#define TT_FTM4_BASE               		  0x400AB000UL
#define TT_FTM5_BASE                	  0x400AC000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define TT_FTM0                     	  ((TT_FTM_Type*)            TT_FTM0_BASE)
#define TT_FTM1                     	  ((TT_FTM_Type*)            TT_FTM1_BASE)
#define TT_FTM2                     	  ((TT_FTM_Type*)            TT_FTM2_BASE)
#define TT_FTM3                     	  ((TT_FTM_Type*)            TT_FTM3_BASE)
#define TT_FTM4                     	  ((TT_FTM_Type*)            TT_FTM4_BASE)
#define TT_FTM5                     	  ((TT_FTM_Type*)            TT_FTM5_BASE)

#define TT_FTM_BASE_PTRS           		  {TT_FTM0,TT_FTM1,TT_FTM2,TT_FTM3,TT_FTM4,TT_FTM5}

/* =========================================================================================================================== */
/* ================                                          TT_FTM                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  SC  =========================================================== */
#define TT_FTM_SC_PS_Pos                  (0UL)                     /*!< TT_FTM SC: PS (Bit 0)                                 */
#define TT_FTM_SC_PS_Msk                  (0x7UL)                   /*!< TT_FTM SC: PS (Bitfield-Mask: 0x07)                   */
#define TT_FTM_SC_CLKS_Pos                (3UL)                     /*!< TT_FTM SC: CLKS (Bit 3)                               */
#define TT_FTM_SC_CLKS_Msk                (0x18UL)                  /*!< TT_FTM SC: CLKS (Bitfield-Mask: 0x03)                 */
#define TT_FTM_SC_CPWMS_Pos               (5UL)                     /*!< TT_FTM SC: CPWMS (Bit 5)                              */
#define TT_FTM_SC_CPWMS_Msk               (0x20UL)                  /*!< TT_FTM SC: CPWMS (Bitfield-Mask: 0x01)                */
#define TT_FTM_SC_RIE_Pos                 (6UL)                     /*!< TT_FTM SC: RIE (Bit 6)                                */
#define TT_FTM_SC_RIE_Msk                 (0x40UL)                  /*!< TT_FTM SC: RIE (Bitfield-Mask: 0x01)                  */
#define TT_FTM_SC_RF_Pos                  (7UL)                     /*!< TT_FTM SC: RF (Bit 7)                                 */
#define TT_FTM_SC_RF_Msk                  (0x80UL)                  /*!< TT_FTM SC: RF (Bitfield-Mask: 0x01)                   */
#define TT_FTM_SC_TOIE_Pos                (8UL)                     /*!< TT_FTM SC: TOIE (Bit 8)                               */
#define TT_FTM_SC_TOIE_Msk                (0x100UL)                 /*!< TT_FTM SC: TOIE (Bitfield-Mask: 0x01)                 */
#define TT_FTM_SC_TOF_Pos                 (9UL)                     /*!< TT_FTM SC: TOF (Bit 9)                                */
#define TT_FTM_SC_TOF_Msk                 (0x200UL)                 /*!< TT_FTM SC: TOF (Bitfield-Mask: 0x01)                  */
#define TT_FTM_SC_PWMENn_Pos              (16UL)                    /*!< TT_FTM SC: PWMEN0 (Bit 16)                            */
#define TT_FTM_SC_PWMENn_Msk              (0xFF0000UL)               /*!< TT_FTM SC: PWMEN0 (Bitfield-Mask: 0xff)               */
#define TT_FTM_SC_FLTPS_Pos               (24UL)                    /*!< TT_FTM SC: FLTPS (Bit 24)                             */
#define TT_FTM_SC_FLTPS_Msk               (0xf000000UL)             /*!< TT_FTM SC: FLTPS (Bitfield-Mask: 0x0f)                */
/* ==========================================================  CNT  ========================================================== */
#define TT_FTM_CNT_COUNT_Pos              (0UL)                     /*!< TT_FTM CNT: COUNT (Bit 0)                             */
#define TT_FTM_CNT_COUNT_Msk              (0xffffUL)                /*!< TT_FTM CNT: COUNT (Bitfield-Mask: 0xffff)             */
/* ==========================================================  MOD  ========================================================== */
#define TT_FTM_MOD_MOD_Pos                (0UL)                     /*!< TT_FTM MOD: MOD (Bit 0)                               */
#define TT_FTM_MOD_MOD_Msk                (0xffffUL)                /*!< TT_FTM MOD: MOD (Bitfield-Mask: 0xffff)               */
/* =========================================================  CnSC  ========================================================== */
#define TT_FTM_CnSC_DMA_Pos               (0UL)                     /*!< TT_FTM CnSC: DMA (Bit 0)                              */
#define TT_FTM_CnSC_DMA_Msk               (0x1UL)                   /*!< TT_FTM CnSC: DMA (Bitfield-Mask: 0x01)                */
#define TT_FTM_CnSC_ICRST_Pos             (1UL)                     /*!< TT_FTM CnSC: ICRST (Bit 1)                            */
#define TT_FTM_CnSC_ICRST_Msk             (0x2UL)                   /*!< TT_FTM CnSC: ICRST (Bitfield-Mask: 0x01)              */
#define TT_FTM_CnSC_ELSA_Pos              (2UL)                     /*!< TT_FTM CnSC: ELSA (Bit 2)                             */
#define TT_FTM_CnSC_ELSA_Msk              (0x4UL)                   /*!< TT_FTM CnSC: ELSA (Bitfield-Mask: 0x01)               */
#define TT_FTM_CnSC_ELSB_Pos              (3UL)                     /*!< TT_FTM CnSC: ELSB (Bit 3)                             */
#define TT_FTM_CnSC_ELSB_Msk              (0x8UL)                   /*!< TT_FTM CnSC: ELSB (Bitfield-Mask: 0x01)               */
#define TT_FTM_CnSC_MSA_Pos               (4UL)                     /*!< TT_FTM CnSC: MSA (Bit 4)                              */
#define TT_FTM_CnSC_MSA_Msk               (0x10UL)                  /*!< TT_FTM CnSC: MSA (Bitfield-Mask: 0x01)                */
#define TT_FTM_CnSC_MSB_Pos               (5UL)                     /*!< TT_FTM CnSC: MSB (Bit 5)                              */
#define TT_FTM_CnSC_MSB_Msk               (0x20UL)                  /*!< TT_FTM CnSC: MSB (Bitfield-Mask: 0x01)                */
#define TT_FTM_CnSC_CHIE_Pos              (6UL)                     /*!< TT_FTM CnSC: CHIE (Bit 6)                             */
#define TT_FTM_CnSC_CHIE_Msk              (0x40UL)                  /*!< TT_FTM CnSC: CHIE (Bitfield-Mask: 0x01)               */
#define TT_FTM_CnSC_CHF_Pos               (7UL)                     /*!< TT_FTM CnSC: CHF (Bit 7)                              */
#define TT_FTM_CnSC_CHF_Msk               (0x80UL)                  /*!< TT_FTM CnSC: CHF (Bitfield-Mask: 0x01)                */
#define TT_FTM_CnSC_TRIGMODE_Pos          (8UL)                     /*!< TT_FTM CnSC: TRIGMODE (Bit 8)                         */
#define TT_FTM_CnSC_TRIGMODE_Msk          (0x100UL)                 /*!< TT_FTM CnSC: TRIGMODE (Bitfield-Mask: 0x01)           */
#define TT_FTM_CnSC_CHIS_Pos              (9UL)                     /*!< TT_FTM CnSC: CHIS (Bit 9)                             */
#define TT_FTM_CnSC_CHIS_Msk              (0x200UL)                 /*!< TT_FTM CnSC: CHIS (Bitfield-Mask: 0x01)               */
#define TT_FTM_CnSC_CHOV_Pos              (10UL)                    /*!< TT_FTM CnSC: CHOV (Bit 10)                            */
#define TT_FTM_CnSC_CHOV_Msk              (0x400UL)                 /*!< TT_FTM CnSC: CHOV (Bitfield-Mask: 0x01)               */
/* ==========================================================  CnV  ========================================================== */
#define TT_FTM_CnV_VAL_Pos                (0UL)                     /*!< TT_FTM CnV: VAL (Bit 0)                               */
#define TT_FTM_CnV_VAL_Msk                (0xffffUL)                /*!< TT_FTM CnV: VAL (Bitfield-Mask: 0xffff)               */
/* =========================================================  CNTIN  ========================================================= */
#define TT_FTM_CNTIN_INIT_Pos             (0UL)                     /*!< TT_FTM CNTIN: INIT (Bit 0)                            */
#define TT_FTM_CNTIN_INIT_Msk             (0xffffUL)                /*!< TT_FTM CNTIN: INIT (Bitfield-Mask: 0xffff)            */
/* ========================================================  STATUS  ========================================================= */
#define TT_FTM_STATUS_CH0F_Pos            (0UL)                     /*!< TT_FTM STATUS: CH0F (Bit 0)                           */
#define TT_FTM_STATUS_CH0F_Msk            (0x1UL)                   /*!< TT_FTM STATUS: CH0F (Bitfield-Mask: 0x01)             */
#define TT_FTM_STATUS_CH1F_Pos            (1UL)                     /*!< TT_FTM STATUS: CH1F (Bit 1)                           */
#define TT_FTM_STATUS_CH1F_Msk            (0x2UL)                   /*!< TT_FTM STATUS: CH1F (Bitfield-Mask: 0x01)             */
#define TT_FTM_STATUS_CH2F_Pos            (2UL)                     /*!< TT_FTM STATUS: CH2F (Bit 2)                           */
#define TT_FTM_STATUS_CH2F_Msk            (0x4UL)                   /*!< TT_FTM STATUS: CH2F (Bitfield-Mask: 0x01)             */
#define TT_FTM_STATUS_CH3F_Pos            (3UL)                     /*!< TT_FTM STATUS: CH3F (Bit 3)                           */
#define TT_FTM_STATUS_CH3F_Msk            (0x8UL)                   /*!< TT_FTM STATUS: CH3F (Bitfield-Mask: 0x01)             */
#define TT_FTM_STATUS_CH4F_Pos            (4UL)                     /*!< TT_FTM STATUS: CH4F (Bit 4)                           */
#define TT_FTM_STATUS_CH4F_Msk            (0x10UL)                  /*!< TT_FTM STATUS: CH4F (Bitfield-Mask: 0x01)             */
#define TT_FTM_STATUS_CH5F_Pos            (5UL)                     /*!< TT_FTM STATUS: CH5F (Bit 5)                           */
#define TT_FTM_STATUS_CH5F_Msk            (0x20UL)                  /*!< TT_FTM STATUS: CH5F (Bitfield-Mask: 0x01)             */
#define TT_FTM_STATUS_CH6F_Pos            (6UL)                     /*!< TT_FTM STATUS: CH6F (Bit 6)                           */
#define TT_FTM_STATUS_CH6F_Msk            (0x40UL)                  /*!< TT_FTM STATUS: CH6F (Bitfield-Mask: 0x01)             */
#define TT_FTM_STATUS_CH7F_Pos            (7UL)                     /*!< TT_FTM STATUS: CH7F (Bit 7)                           */
#define TT_FTM_STATUS_CH7F_Msk            (0x80UL)                  /*!< TT_FTM STATUS: CH7F (Bitfield-Mask: 0x01)             */
/* =========================================================  MODE  ========================================================== */
#define TT_FTM_MODE_FTMEN_Pos             (0UL)                     /*!< TT_FTM MODE: FTMEN (Bit 0)                            */
#define TT_FTM_MODE_FTMEN_Msk             (0x1UL)                   /*!< TT_FTM MODE: FTMEN (Bitfield-Mask: 0x01)              */
#define TT_FTM_MODE_INIT_Pos              (1UL)                     /*!< TT_FTM MODE: INIT (Bit 1)                             */
#define TT_FTM_MODE_INIT_Msk              (0x2UL)                   /*!< TT_FTM MODE: INIT (Bitfield-Mask: 0x01)               */
#define TT_FTM_MODE_WPDIS_Pos             (2UL)                     /*!< TT_FTM MODE: WPDIS (Bit 2)                            */
#define TT_FTM_MODE_WPDIS_Msk             (0x4UL)                   /*!< TT_FTM MODE: WPDIS (Bitfield-Mask: 0x01)              */
#define TT_FTM_MODE_PWMSYNC_Pos           (3UL)                     /*!< TT_FTM MODE: PWMSYNC (Bit 3)                          */
#define TT_FTM_MODE_PWMSYNC_Msk           (0x8UL)                   /*!< TT_FTM MODE: PWMSYNC (Bitfield-Mask: 0x01)            */
#define TT_FTM_MODE_CAPTEST_Pos           (4UL)                     /*!< TT_FTM MODE: CAPTEST (Bit 4)                          */
#define TT_FTM_MODE_CAPTEST_Msk           (0x10UL)                  /*!< TT_FTM MODE: CAPTEST (Bitfield-Mask: 0x01)            */
#define TT_FTM_MODE_FAULTM_Pos            (5UL)                     /*!< TT_FTM MODE: FAULTM (Bit 5)                           */
#define TT_FTM_MODE_FAULTM_Msk            (0x60UL)                  /*!< TT_FTM MODE: FAULTM (Bitfield-Mask: 0x03)             */
#define TT_FTM_MODE_FAULTIE_Pos           (7UL)                     /*!< TT_FTM MODE: FAULTIE (Bit 7)                          */
#define TT_FTM_MODE_FAULTIE_Msk           (0x80UL)                  /*!< TT_FTM MODE: FAULTIE (Bitfield-Mask: 0x01)            */
/* =========================================================  SYNC  ========================================================== */
#define TT_FTM_SYNC_CNTMIN_Pos            (0UL)                     /*!< TT_FTM SYNC: CNTMIN (Bit 0)                           */
#define TT_FTM_SYNC_CNTMIN_Msk            (0x1UL)                   /*!< TT_FTM SYNC: CNTMIN (Bitfield-Mask: 0x01)             */
#define TT_FTM_SYNC_CNTMAX_Pos            (1UL)                     /*!< TT_FTM SYNC: CNTMAX (Bit 1)                           */
#define TT_FTM_SYNC_CNTMAX_Msk            (0x2UL)                   /*!< TT_FTM SYNC: CNTMAX (Bitfield-Mask: 0x01)             */
#define TT_FTM_SYNC_REINIT_Pos            (2UL)                     /*!< TT_FTM SYNC: REINIT (Bit 2)                           */
#define TT_FTM_SYNC_REINIT_Msk            (0x4UL)                   /*!< TT_FTM SYNC: REINIT (Bitfield-Mask: 0x01)             */
#define TT_FTM_SYNC_SYNCHOM_Pos           (3UL)                     /*!< TT_FTM SYNC: SYNCHOM (Bit 3)                          */
#define TT_FTM_SYNC_SYNCHOM_Msk           (0x8UL)                   /*!< TT_FTM SYNC: SYNCHOM (Bitfield-Mask: 0x01)            */
#define TT_FTM_SYNC_TRIG0_Pos             (4UL)                     /*!< TT_FTM SYNC: TRIG0 (Bit 4)                            */
#define TT_FTM_SYNC_TRIG0_Msk             (0x10UL)                  /*!< TT_FTM SYNC: TRIG0 (Bitfield-Mask: 0x01)              */
#define TT_FTM_SYNC_TRIG1_Pos             (5UL)                     /*!< TT_FTM SYNC: TRIG1 (Bit 5)                            */
#define TT_FTM_SYNC_TRIG1_Msk             (0x20UL)                  /*!< TT_FTM SYNC: TRIG1 (Bitfield-Mask: 0x01)              */
#define TT_FTM_SYNC_TRIG2_Pos             (6UL)                     /*!< TT_FTM SYNC: TRIG2 (Bit 6)                            */
#define TT_FTM_SYNC_TRIG2_Msk             (0x40UL)                  /*!< TT_FTM SYNC: TRIG2 (Bitfield-Mask: 0x01)              */
#define TT_FTM_SYNC_SWSYNC_Pos            (7UL)                     /*!< TT_FTM SYNC: SWSYNC (Bit 7)                           */
#define TT_FTM_SYNC_SWSYNC_Msk            (0x80UL)                  /*!< TT_FTM SYNC: SWSYNC (Bitfield-Mask: 0x01)             */
/* ========================================================  OUTINIT  ======================================================== */
#define TT_FTM_OUTINIT_CH0OI_Pos          (0UL)                     /*!< TT_FTM OUTINIT: CH0OI (Bit 0)                         */
#define TT_FTM_OUTINIT_CH0OI_Msk          (0x1UL)                   /*!< TT_FTM OUTINIT: CH0OI (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTINIT_CH1OI_Pos          (1UL)                     /*!< TT_FTM OUTINIT: CH1OI (Bit 1)                         */
#define TT_FTM_OUTINIT_CH1OI_Msk          (0x2UL)                   /*!< TT_FTM OUTINIT: CH1OI (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTINIT_CH2OI_Pos          (2UL)                     /*!< TT_FTM OUTINIT: CH2OI (Bit 2)                         */
#define TT_FTM_OUTINIT_CH2OI_Msk          (0x4UL)                   /*!< TT_FTM OUTINIT: CH2OI (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTINIT_CH3OI_Pos          (3UL)                     /*!< TT_FTM OUTINIT: CH3OI (Bit 3)                         */
#define TT_FTM_OUTINIT_CH3OI_Msk          (0x8UL)                   /*!< TT_FTM OUTINIT: CH3OI (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTINIT_CH4OI_Pos          (4UL)                     /*!< TT_FTM OUTINIT: CH4OI (Bit 4)                         */
#define TT_FTM_OUTINIT_CH4OI_Msk          (0x10UL)                  /*!< TT_FTM OUTINIT: CH4OI (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTINIT_CH5OI_Pos          (5UL)                     /*!< TT_FTM OUTINIT: CH5OI (Bit 5)                         */
#define TT_FTM_OUTINIT_CH5OI_Msk          (0x20UL)                  /*!< TT_FTM OUTINIT: CH5OI (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTINIT_CH6OI_Pos          (6UL)                     /*!< TT_FTM OUTINIT: CH6OI (Bit 6)                         */
#define TT_FTM_OUTINIT_CH6OI_Msk          (0x40UL)                  /*!< TT_FTM OUTINIT: CH6OI (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTINIT_CH7OI_Pos          (7UL)                     /*!< TT_FTM OUTINIT: CH7OI (Bit 7)                         */
#define TT_FTM_OUTINIT_CH7OI_Msk          (0x80UL)                  /*!< TT_FTM OUTINIT: CH7OI (Bitfield-Mask: 0x01)           */
/* ========================================================  OUTMASK  ======================================================== */
#define TT_FTM_OUTMASK_CH0OM_Pos          (0UL)                     /*!< TT_FTM OUTMASK: CH0OM (Bit 0)                         */
#define TT_FTM_OUTMASK_CH0OM_Msk          (0x1UL)                   /*!< TT_FTM OUTMASK: CH0OM (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTMASK_CH1OM_Pos          (1UL)                     /*!< TT_FTM OUTMASK: CH1OM (Bit 1)                         */
#define TT_FTM_OUTMASK_CH1OM_Msk          (0x2UL)                   /*!< TT_FTM OUTMASK: CH1OM (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTMASK_CH2OM_Pos          (2UL)                     /*!< TT_FTM OUTMASK: CH2OM (Bit 2)                         */
#define TT_FTM_OUTMASK_CH2OM_Msk          (0x4UL)                   /*!< TT_FTM OUTMASK: CH2OM (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTMASK_CH3OM_Pos          (3UL)                     /*!< TT_FTM OUTMASK: CH3OM (Bit 3)                         */
#define TT_FTM_OUTMASK_CH3OM_Msk          (0x8UL)                   /*!< TT_FTM OUTMASK: CH3OM (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTMASK_CH4OM_Pos          (4UL)                     /*!< TT_FTM OUTMASK: CH4OM (Bit 4)                         */
#define TT_FTM_OUTMASK_CH4OM_Msk          (0x10UL)                  /*!< TT_FTM OUTMASK: CH4OM (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTMASK_CH5OM_Pos          (5UL)                     /*!< TT_FTM OUTMASK: CH5OM (Bit 5)                         */
#define TT_FTM_OUTMASK_CH5OM_Msk          (0x20UL)                  /*!< TT_FTM OUTMASK: CH5OM (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTMASK_CH6OM_Pos          (6UL)                     /*!< TT_FTM OUTMASK: CH6OM (Bit 6)                         */
#define TT_FTM_OUTMASK_CH6OM_Msk          (0x40UL)                  /*!< TT_FTM OUTMASK: CH6OM (Bitfield-Mask: 0x01)           */
#define TT_FTM_OUTMASK_CH7OM_Pos          (7UL)                     /*!< TT_FTM OUTMASK: CH7OM (Bit 7)                         */
#define TT_FTM_OUTMASK_CH7OM_Msk          (0x80UL)                  /*!< TT_FTM OUTMASK: CH7OM (Bitfield-Mask: 0x01)           */
/* ========================================================  COMBINE  ======================================================== */
#define TT_FTM_COMBINE_COMBINEn_Pos       (0UL)                     /*!< TT_FTM COMBINE: COMBINE0 (Bit 0)                      */
#define TT_FTM_COMBINE_COMBINEn_Msk       (0x1UL)                   /*!< TT_FTM COMBINE: COMBINE0 (Bitfield-Mask: 0x01)        */
#define TT_FTM_COMBINE_COMPn_Pos          (1UL)                     /*!< TT_FTM COMBINE: COMP0 (Bit 1)                         */
#define TT_FTM_COMBINE_COMPn_Msk          (0x2UL)                   /*!< TT_FTM COMBINE: COMP0 (Bitfield-Mask: 0x01)           */
#define TT_FTM_COMBINE_DECAPENn_Pos       (2UL)                     /*!< TT_FTM COMBINE: DECAPEN0 (Bit 2)                      */
#define TT_FTM_COMBINE_DECAPENn_Msk       (0x4UL)                   /*!< TT_FTM COMBINE: DECAPEN0 (Bitfield-Mask: 0x01)        */
#define TT_FTM_COMBINE_DECAPn_Pos         (3UL)                     /*!< TT_FTM COMBINE: DECAP0 (Bit 3)                        */
#define TT_FTM_COMBINE_DECAPn_Msk         (0x8UL)                   /*!< TT_FTM COMBINE: DECAP0 (Bitfield-Mask: 0x01)          */
#define TT_FTM_COMBINE_DTENn_Pos          (4UL)                     /*!< TT_FTM COMBINE: DTEN0 (Bit 4)                         */
#define TT_FTM_COMBINE_DTENn_Msk          (0x10UL)                  /*!< TT_FTM COMBINE: DTEN0 (Bitfield-Mask: 0x01)           */
#define TT_FTM_COMBINE_SYNCENn_Pos        (5UL)                     /*!< TT_FTM COMBINE: SYNCEN0 (Bit 5)                       */
#define TT_FTM_COMBINE_SYNCENn_Msk        (0x20UL)                  /*!< TT_FTM COMBINE: SYNCEN0 (Bitfield-Mask: 0x01)         */
#define TT_FTM_COMBINE_FAULTENn_Pos       (6UL)                     /*!< TT_FTM COMBINE: FAULTEN0 (Bit 6)                      */
#define TT_FTM_COMBINE_FAULTENn_Msk       (0x40UL)                  /*!< TT_FTM COMBINE: FAULTEN0 (Bitfield-Mask: 0x01)        */
#define TT_FTM_COMBINE_MCOMBINEn_Pos      (7UL)                     /*!< TT_FTM COMBINE: MCOMBINE0 (Bit 7)                     */
#define TT_FTM_COMBINE_MCOMBINEn_Msk      (0x80UL)                  /*!< TT_FTM COMBINE: MCOMBINE0 (Bitfield-Mask: 0x01)       */
/* =======================================================  DEADTIME  ======================================================== */
#define TT_FTM_DEADTIME_DTVAL_Pos         (0UL)                     /*!< TT_FTM DEADTIME: DTVAL (Bit 0)                        */
#define TT_FTM_DEADTIME_DTVAL_Msk         (0x3fUL)                  /*!< TT_FTM DEADTIME: DTVAL (Bitfield-Mask: 0x3f)          */
#define TT_FTM_DEADTIME_DTPS_Pos          (6UL)                     /*!< TT_FTM DEADTIME: DTPS (Bit 6)                         */
#define TT_FTM_DEADTIME_DTPS_Msk          (0xc0UL)                  /*!< TT_FTM DEADTIME: DTPS (Bitfield-Mask: 0x03)           */
#define TT_FTM_DEADTIME_DTVALEX_Pos       (16UL)                    /*!< TT_FTM DEADTIME: DTVALEX (Bit 16)                     */
#define TT_FTM_DEADTIME_DTVALEX_Msk       (0xf0000UL)               /*!< TT_FTM DEADTIME: DTVALEX (Bitfield-Mask: 0x0f)        */
/* ========================================================  EXTTRIG  ======================================================== */
#define TT_FTM_EXTTRIG_CH2TRIG_Pos        (0UL)                     /*!< TT_FTM EXTTRIG: CH2TRIG (Bit 0)                       */
#define TT_FTM_EXTTRIG_CH2TRIG_Msk        (0x1UL)                   /*!< TT_FTM EXTTRIG: CH2TRIG (Bitfield-Mask: 0x01)         */
#define TT_FTM_EXTTRIG_CH3TRIG_Pos        (1UL)                     /*!< TT_FTM EXTTRIG: CH3TRIG (Bit 1)                       */
#define TT_FTM_EXTTRIG_CH3TRIG_Msk        (0x2UL)                   /*!< TT_FTM EXTTRIG: CH3TRIG (Bitfield-Mask: 0x01)         */
#define TT_FTM_EXTTRIG_CH4TRIG_Pos        (2UL)                     /*!< TT_FTM EXTTRIG: CH4TRIG (Bit 2)                       */
#define TT_FTM_EXTTRIG_CH4TRIG_Msk        (0x4UL)                   /*!< TT_FTM EXTTRIG: CH4TRIG (Bitfield-Mask: 0x01)         */
#define TT_FTM_EXTTRIG_CH5TRIG_Pos        (3UL)                     /*!< TT_FTM EXTTRIG: CH5TRIG (Bit 3)                       */
#define TT_FTM_EXTTRIG_CH5TRIG_Msk        (0x8UL)                   /*!< TT_FTM EXTTRIG: CH5TRIG (Bitfield-Mask: 0x01)         */
#define TT_FTM_EXTTRIG_CH0TRIG_Pos        (4UL)                     /*!< TT_FTM EXTTRIG: CH0TRIG (Bit 4)                       */
#define TT_FTM_EXTTRIG_CH0TRIG_Msk        (0x10UL)                  /*!< TT_FTM EXTTRIG: CH0TRIG (Bitfield-Mask: 0x01)         */
#define TT_FTM_EXTTRIG_CH1TRIG_Pos        (5UL)                     /*!< TT_FTM EXTTRIG: CH1TRIG (Bit 5)                       */
#define TT_FTM_EXTTRIG_CH1TRIG_Msk        (0x20UL)                  /*!< TT_FTM EXTTRIG: CH1TRIG (Bitfield-Mask: 0x01)         */
#define TT_FTM_EXTTRIG_INITTRIGEN_Pos     (6UL)                     /*!< TT_FTM EXTTRIG: INITTRIGEN (Bit 6)                    */
#define TT_FTM_EXTTRIG_INITTRIGEN_Msk     (0x40UL)                  /*!< TT_FTM EXTTRIG: INITTRIGEN (Bitfield-Mask: 0x01)      */
#define TT_FTM_EXTTRIG_TRIGF_Pos          (7UL)                     /*!< TT_FTM EXTTRIG: TRIGF (Bit 7)                         */
#define TT_FTM_EXTTRIG_TRIGF_Msk          (0x80UL)                  /*!< TT_FTM EXTTRIG: TRIGF (Bitfield-Mask: 0x01)           */
#define TT_FTM_EXTTRIG_CH6TRIG_Pos        (8UL)                     /*!< TT_FTM EXTTRIG: CH6TRIG (Bit 8)                       */
#define TT_FTM_EXTTRIG_CH6TRIG_Msk        (0x100UL)                 /*!< TT_FTM EXTTRIG: CH6TRIG (Bitfield-Mask: 0x01)         */
#define TT_FTM_EXTTRIG_CH7TRIG_Pos        (9UL)                     /*!< TT_FTM EXTTRIG: CH7TRIG (Bit 9)                       */
#define TT_FTM_EXTTRIG_CH7TRIG_Msk        (0x200UL)                 /*!< TT_FTM EXTTRIG: CH7TRIG (Bitfield-Mask: 0x01)         */
/* ==========================================================  POL  ========================================================== */
#define TT_FTM_POL_POL0_Pos               (0UL)                     /*!< TT_FTM POL: POL0 (Bit 0)                              */
#define TT_FTM_POL_POL0_Msk               (0x1UL)                   /*!< TT_FTM POL: POL0 (Bitfield-Mask: 0x01)                */
#define TT_FTM_POL_POL1_Pos               (1UL)                     /*!< TT_FTM POL: POL1 (Bit 1)                              */
#define TT_FTM_POL_POL1_Msk               (0x2UL)                   /*!< TT_FTM POL: POL1 (Bitfield-Mask: 0x01)                */
#define TT_FTM_POL_POL2_Pos               (2UL)                     /*!< TT_FTM POL: POL2 (Bit 2)                              */
#define TT_FTM_POL_POL2_Msk               (0x4UL)                   /*!< TT_FTM POL: POL2 (Bitfield-Mask: 0x01)                */
#define TT_FTM_POL_POL3_Pos               (3UL)                     /*!< TT_FTM POL: POL3 (Bit 3)                              */
#define TT_FTM_POL_POL3_Msk               (0x8UL)                   /*!< TT_FTM POL: POL3 (Bitfield-Mask: 0x01)                */
#define TT_FTM_POL_POL4_Pos               (4UL)                     /*!< TT_FTM POL: POL4 (Bit 4)                              */
#define TT_FTM_POL_POL4_Msk               (0x10UL)                  /*!< TT_FTM POL: POL4 (Bitfield-Mask: 0x01)                */
#define TT_FTM_POL_POL5_Pos               (5UL)                     /*!< TT_FTM POL: POL5 (Bit 5)                              */
#define TT_FTM_POL_POL5_Msk               (0x20UL)                  /*!< TT_FTM POL: POL5 (Bitfield-Mask: 0x01)                */
#define TT_FTM_POL_POL6_Pos               (6UL)                     /*!< TT_FTM POL: POL6 (Bit 6)                              */
#define TT_FTM_POL_POL6_Msk               (0x40UL)                  /*!< TT_FTM POL: POL6 (Bitfield-Mask: 0x01)                */
#define TT_FTM_POL_POL7_Pos               (7UL)                     /*!< TT_FTM POL: POL7 (Bit 7)                              */
#define TT_FTM_POL_POL7_Msk               (0x80UL)                  /*!< TT_FTM POL: POL7 (Bitfield-Mask: 0x01)                */
/* ==========================================================  FMS  ========================================================== */
#define TT_FTM_FMS_FAULTF0_Pos            (0UL)                     /*!< TT_FTM FMS: FAULTF0 (Bit 0)                           */
#define TT_FTM_FMS_FAULTF0_Msk            (0x1UL)                   /*!< TT_FTM FMS: FAULTF0 (Bitfield-Mask: 0x01)             */
#define TT_FTM_FMS_FAULTF1_Pos            (1UL)                     /*!< TT_FTM FMS: FAULTF1 (Bit 1)                           */
#define TT_FTM_FMS_FAULTF1_Msk            (0x2UL)                   /*!< TT_FTM FMS: FAULTF1 (Bitfield-Mask: 0x01)             */
#define TT_FTM_FMS_FAULTF2_Pos            (2UL)                     /*!< TT_FTM FMS: FAULTF2 (Bit 2)                           */
#define TT_FTM_FMS_FAULTF2_Msk            (0x4UL)                   /*!< TT_FTM FMS: FAULTF2 (Bitfield-Mask: 0x01)             */
#define TT_FTM_FMS_FAULTF3_Pos            (3UL)                     /*!< TT_FTM FMS: FAULTF3 (Bit 3)                           */
#define TT_FTM_FMS_FAULTF3_Msk            (0x8UL)                   /*!< TT_FTM FMS: FAULTF3 (Bitfield-Mask: 0x01)             */
#define TT_FTM_FMS_FAULTIN_Pos            (5UL)                     /*!< TT_FTM FMS: FAULTIN (Bit 5)                           */
#define TT_FTM_FMS_FAULTIN_Msk            (0x20UL)                  /*!< TT_FTM FMS: FAULTIN (Bitfield-Mask: 0x01)             */
#define TT_FTM_FMS_WPEN_Pos               (6UL)                     /*!< TT_FTM FMS: WPEN (Bit 6)                              */
#define TT_FTM_FMS_WPEN_Msk               (0x40UL)                  /*!< TT_FTM FMS: WPEN (Bitfield-Mask: 0x01)                */
#define TT_FTM_FMS_FAULTF_Pos             (7UL)                     /*!< TT_FTM FMS: FAULTF (Bit 7)                            */
#define TT_FTM_FMS_FAULTF_Msk             (0x80UL)                  /*!< TT_FTM FMS: FAULTF (Bitfield-Mask: 0x01)              */
/* ========================================================  FILTER  ========================================================= */
#define TT_FTM_FILTER_CHnFVAL_Pos         (0UL)                     /*!< TT_FTM FILTER: CHnFVAL (Bit 0)                        */
#define TT_FTM_FILTER_CHnFVAL_Msk         (0xfUL)                   /*!< TT_FTM FILTER: CHnFVAL (Bitfield-Mask: 0x0f)          */
/* ========================================================  FLTCTRL  ======================================================== */
#define TT_FTM_FLTCTRL_FAULT0EN_Pos       (0UL)                     /*!< TT_FTM FLTCTRL: FAULT0EN (Bit 0)                      */
#define TT_FTM_FLTCTRL_FAULT0EN_Msk       (0x1UL)                   /*!< TT_FTM FLTCTRL: FAULT0EN (Bitfield-Mask: 0x01)        */
#define TT_FTM_FLTCTRL_FAULT1EN_Pos       (1UL)                     /*!< TT_FTM FLTCTRL: FAULT1EN (Bit 1)                      */
#define TT_FTM_FLTCTRL_FAULT1EN_Msk       (0x2UL)                   /*!< TT_FTM FLTCTRL: FAULT1EN (Bitfield-Mask: 0x01)        */
#define TT_FTM_FLTCTRL_FAULT2EN_Pos       (2UL)                     /*!< TT_FTM FLTCTRL: FAULT2EN (Bit 2)                      */
#define TT_FTM_FLTCTRL_FAULT2EN_Msk       (0x4UL)                   /*!< TT_FTM FLTCTRL: FAULT2EN (Bitfield-Mask: 0x01)        */
#define TT_FTM_FLTCTRL_FAULT3EN_Pos       (3UL)                     /*!< TT_FTM FLTCTRL: FAULT3EN (Bit 3)                      */
#define TT_FTM_FLTCTRL_FAULT3EN_Msk       (0x8UL)                   /*!< TT_FTM FLTCTRL: FAULT3EN (Bitfield-Mask: 0x01)        */
#define TT_FTM_FLTCTRL_FFLTR0EN_Pos       (4UL)                     /*!< TT_FTM FLTCTRL: FFLTR0EN (Bit 4)                      */
#define TT_FTM_FLTCTRL_FFLTR0EN_Msk       (0x10UL)                  /*!< TT_FTM FLTCTRL: FFLTR0EN (Bitfield-Mask: 0x01)        */
#define TT_FTM_FLTCTRL_FFLTR1EN_Pos       (5UL)                     /*!< TT_FTM FLTCTRL: FFLTR1EN (Bit 5)                      */
#define TT_FTM_FLTCTRL_FFLTR1EN_Msk       (0x20UL)                  /*!< TT_FTM FLTCTRL: FFLTR1EN (Bitfield-Mask: 0x01)        */
#define TT_FTM_FLTCTRL_FFLTR2EN_Pos       (6UL)                     /*!< TT_FTM FLTCTRL: FFLTR2EN (Bit 6)                      */
#define TT_FTM_FLTCTRL_FFLTR2EN_Msk       (0x40UL)                  /*!< TT_FTM FLTCTRL: FFLTR2EN (Bitfield-Mask: 0x01)        */
#define TT_FTM_FLTCTRL_FFLTR3EN_Pos       (7UL)                     /*!< TT_FTM FLTCTRL: FFLTR3EN (Bit 7)                      */
#define TT_FTM_FLTCTRL_FFLTR3EN_Msk       (0x80UL)                  /*!< TT_FTM FLTCTRL: FFLTR3EN (Bitfield-Mask: 0x01)        */
#define TT_FTM_FLTCTRL_FFVAL_Pos          (8UL)                     /*!< TT_FTM FLTCTRL: FFVAL (Bit 8)                         */
#define TT_FTM_FLTCTRL_FFVAL_Msk          (0xf00UL)                 /*!< TT_FTM FLTCTRL: FFVAL (Bitfield-Mask: 0x0f)           */
#define TT_FTM_FLTCTRL_FSTATE_Pos         (15UL)                    /*!< TT_FTM FLTCTRL: FSTATE (Bit 15)                       */
#define TT_FTM_FLTCTRL_FSTATE_Msk         (0x8000UL)                /*!< TT_FTM FLTCTRL: FSTATE (Bitfield-Mask: 0x01)          */
/* ========================================================  QDCTRL  ========================================================= */
#define TT_FTM_QDCTRL_QUADEN_Pos          (0UL)                     /*!< TT_FTM QDCTRL: QUADEN (Bit 0)                         */
#define TT_FTM_QDCTRL_QUADEN_Msk          (0x1UL)                   /*!< TT_FTM QDCTRL: QUADEN (Bitfield-Mask: 0x01)           */
#define TT_FTM_QDCTRL_TOFDIR_Pos          (1UL)                     /*!< TT_FTM QDCTRL: TOFDIR (Bit 1)                         */
#define TT_FTM_QDCTRL_TOFDIR_Msk          (0x2UL)                   /*!< TT_FTM QDCTRL: TOFDIR (Bitfield-Mask: 0x01)           */
#define TT_FTM_QDCTRL_QUADIR_Pos          (2UL)                     /*!< TT_FTM QDCTRL: QUADIR (Bit 2)                         */
#define TT_FTM_QDCTRL_QUADIR_Msk          (0x4UL)                   /*!< TT_FTM QDCTRL: QUADIR (Bitfield-Mask: 0x01)           */
#define TT_FTM_QDCTRL_QUADMODE_Pos        (3UL)                     /*!< TT_FTM QDCTRL: QUADMODE (Bit 3)                       */
#define TT_FTM_QDCTRL_QUADMODE_Msk        (0x8UL)                   /*!< TT_FTM QDCTRL: QUADMODE (Bitfield-Mask: 0x01)         */
#define TT_FTM_QDCTRL_PHBPOL_Pos          (4UL)                     /*!< TT_FTM QDCTRL: PHBPOL (Bit 4)                         */
#define TT_FTM_QDCTRL_PHBPOL_Msk          (0x10UL)                  /*!< TT_FTM QDCTRL: PHBPOL (Bitfield-Mask: 0x01)           */
#define TT_FTM_QDCTRL_PHAPOL_Pos          (5UL)                     /*!< TT_FTM QDCTRL: PHAPOL (Bit 5)                         */
#define TT_FTM_QDCTRL_PHAPOL_Msk          (0x20UL)                  /*!< TT_FTM QDCTRL: PHAPOL (Bitfield-Mask: 0x01)           */
#define TT_FTM_QDCTRL_PHBFLTREN_Pos       (6UL)                     /*!< TT_FTM QDCTRL: PHBFLTREN (Bit 6)                      */
#define TT_FTM_QDCTRL_PHBFLTREN_Msk       (0x40UL)                  /*!< TT_FTM QDCTRL: PHBFLTREN (Bitfield-Mask: 0x01)        */
#define TT_FTM_QDCTRL_PHAFLTREN_Pos       (7UL)                     /*!< TT_FTM QDCTRL: PHAFLTREN (Bit 7)                      */
#define TT_FTM_QDCTRL_PHAFLTREN_Msk       (0x80UL)                  /*!< TT_FTM QDCTRL: PHAFLTREN (Bitfield-Mask: 0x01)        */
/* =========================================================  CONF  ========================================================== */
#define TT_FTM_CONF_LDFQ_Pos              (0UL)                     /*!< TT_FTM CONF: LDFQ (Bit 0)                             */
#define TT_FTM_CONF_LDFQ_Msk              (0x1fUL)                  /*!< TT_FTM CONF: LDFQ (Bitfield-Mask: 0x1f)               */
#define TT_FTM_CONF_BDMMODE_Pos           (6UL)                     /*!< TT_FTM CONF: BDMMODE (Bit 6)                          */
#define TT_FTM_CONF_BDMMODE_Msk           (0xc0UL)                  /*!< TT_FTM CONF: BDMMODE (Bitfield-Mask: 0x03)            */
#define TT_FTM_CONF_GTBEEN_Pos            (9UL)                     /*!< TT_FTM CONF: GTBEEN (Bit 9)                           */
#define TT_FTM_CONF_GTBEEN_Msk            (0x200UL)                 /*!< TT_FTM CONF: GTBEEN (Bitfield-Mask: 0x01)             */
#define TT_FTM_CONF_GTBEOUT_Pos           (10UL)                    /*!< TT_FTM CONF: GTBEOUT (Bit 10)                         */
#define TT_FTM_CONF_GTBEOUT_Msk           (0x400UL)                 /*!< TT_FTM CONF: GTBEOUT (Bitfield-Mask: 0x01)            */
#define TT_FTM_CONF_ITRIGR_Pos            (11UL)                    /*!< TT_FTM CONF: ITRIGR (Bit 11)                          */
#define TT_FTM_CONF_ITRIGR_Msk            (0x800UL)                 /*!< TT_FTM CONF: ITRIGR (Bitfield-Mask: 0x01)             */
/* ========================================================  FLTPOL  ========================================================= */
#define TT_FTM_FLTPOL_FLT0POL_Pos         (0UL)                     /*!< TT_FTM FLTPOL: FLT0POL (Bit 0)                        */
#define TT_FTM_FLTPOL_FLT0POL_Msk         (0x1UL)                   /*!< TT_FTM FLTPOL: FLT0POL (Bitfield-Mask: 0x01)          */
#define TT_FTM_FLTPOL_FLT1POL_Pos         (1UL)                     /*!< TT_FTM FLTPOL: FLT1POL (Bit 1)                        */
#define TT_FTM_FLTPOL_FLT1POL_Msk         (0x2UL)                   /*!< TT_FTM FLTPOL: FLT1POL (Bitfield-Mask: 0x01)          */
#define TT_FTM_FLTPOL_FLT2POL_Pos         (2UL)                     /*!< TT_FTM FLTPOL: FLT2POL (Bit 2)                        */
#define TT_FTM_FLTPOL_FLT2POL_Msk         (0x4UL)                   /*!< TT_FTM FLTPOL: FLT2POL (Bitfield-Mask: 0x01)          */
#define TT_FTM_FLTPOL_FLT3POL_Pos         (3UL)                     /*!< TT_FTM FLTPOL: FLT3POL (Bit 3)                        */
#define TT_FTM_FLTPOL_FLT3POL_Msk         (0x8UL)                   /*!< TT_FTM FLTPOL: FLT3POL (Bitfield-Mask: 0x01)          */
/* ========================================================  SYNCONF  ======================================================== */
#define TT_FTM_SYNCONF_HWTRIGMODE_Pos     (0UL)                     /*!< TT_FTM SYNCONF: HWTRIGMODE (Bit 0)                    */
#define TT_FTM_SYNCONF_HWTRIGMODE_Msk     (0x1UL)                   /*!< TT_FTM SYNCONF: HWTRIGMODE (Bitfield-Mask: 0x01)      */
#define TT_FTM_SYNCONF_CNTINC_Pos         (2UL)                     /*!< TT_FTM SYNCONF: CNTINC (Bit 2)                        */
#define TT_FTM_SYNCONF_CNTINC_Msk         (0x4UL)                   /*!< TT_FTM SYNCONF: CNTINC (Bitfield-Mask: 0x01)          */
#define TT_FTM_SYNCONF_INVC_Pos           (4UL)                     /*!< TT_FTM SYNCONF: INVC (Bit 4)                          */
#define TT_FTM_SYNCONF_INVC_Msk           (0x10UL)                  /*!< TT_FTM SYNCONF: INVC (Bitfield-Mask: 0x01)            */
#define TT_FTM_SYNCONF_SWOC_Pos           (5UL)                     /*!< TT_FTM SYNCONF: SWOC (Bit 5)                          */
#define TT_FTM_SYNCONF_SWOC_Msk           (0x20UL)                  /*!< TT_FTM SYNCONF: SWOC (Bitfield-Mask: 0x01)            */
#define TT_FTM_SYNCONF_SYNCMODE_Pos       (7UL)                     /*!< TT_FTM SYNCONF: SYNCMODE (Bit 7)                      */
#define TT_FTM_SYNCONF_SYNCMODE_Msk       (0x80UL)                  /*!< TT_FTM SYNCONF: SYNCMODE (Bitfield-Mask: 0x01)        */
#define TT_FTM_SYNCONF_SWRSTCNT_Pos       (8UL)                     /*!< TT_FTM SYNCONF: SWRSTCNT (Bit 8)                      */
#define TT_FTM_SYNCONF_SWRSTCNT_Msk       (0x100UL)                 /*!< TT_FTM SYNCONF: SWRSTCNT (Bitfield-Mask: 0x01)        */
#define TT_FTM_SYNCONF_SWWRBUF_Pos        (9UL)                     /*!< TT_FTM SYNCONF: SWWRBUF (Bit 9)                       */
#define TT_FTM_SYNCONF_SWWRBUF_Msk        (0x200UL)                 /*!< TT_FTM SYNCONF: SWWRBUF (Bitfield-Mask: 0x01)         */
#define TT_FTM_SYNCONF_SWOM_Pos           (10UL)                    /*!< TT_FTM SYNCONF: SWOM (Bit 10)                         */
#define TT_FTM_SYNCONF_SWOM_Msk           (0x400UL)                 /*!< TT_FTM SYNCONF: SWOM (Bitfield-Mask: 0x01)            */
#define TT_FTM_SYNCONF_SWINVC_Pos         (11UL)                    /*!< TT_FTM SYNCONF: SWINVC (Bit 11)                       */
#define TT_FTM_SYNCONF_SWINVC_Msk         (0x800UL)                 /*!< TT_FTM SYNCONF: SWINVC (Bitfield-Mask: 0x01)          */
#define TT_FTM_SYNCONF_SWSOC_Pos          (12UL)                    /*!< TT_FTM SYNCONF: SWSOC (Bit 12)                        */
#define TT_FTM_SYNCONF_SWSOC_Msk          (0x1000UL)                /*!< TT_FTM SYNCONF: SWSOC (Bitfield-Mask: 0x01)           */
#define TT_FTM_SYNCONF_HWRSTCNT_Pos       (16UL)                    /*!< TT_FTM SYNCONF: HWRSTCNT (Bit 16)                     */
#define TT_FTM_SYNCONF_HWRSTCNT_Msk       (0x10000UL)               /*!< TT_FTM SYNCONF: HWRSTCNT (Bitfield-Mask: 0x01)        */
#define TT_FTM_SYNCONF_HWWRBUF_Pos        (17UL)                    /*!< TT_FTM SYNCONF: HWWRBUF (Bit 17)                      */
#define TT_FTM_SYNCONF_HWWRBUF_Msk        (0x20000UL)               /*!< TT_FTM SYNCONF: HWWRBUF (Bitfield-Mask: 0x01)         */
#define TT_FTM_SYNCONF_HWOM_Pos           (18UL)                    /*!< TT_FTM SYNCONF: HWOM (Bit 18)                         */
#define TT_FTM_SYNCONF_HWOM_Msk           (0x40000UL)               /*!< TT_FTM SYNCONF: HWOM (Bitfield-Mask: 0x01)            */
#define TT_FTM_SYNCONF_HWINVC_Pos         (19UL)                    /*!< TT_FTM SYNCONF: HWINVC (Bit 19)                       */
#define TT_FTM_SYNCONF_HWINVC_Msk         (0x80000UL)               /*!< TT_FTM SYNCONF: HWINVC (Bitfield-Mask: 0x01)          */
#define TT_FTM_SYNCONF_HWSOC_Pos          (20UL)                    /*!< TT_FTM SYNCONF: HWSOC (Bit 20)                        */
#define TT_FTM_SYNCONF_HWSOC_Msk          (0x100000UL)              /*!< TT_FTM SYNCONF: HWSOC (Bitfield-Mask: 0x01)           */
/* ========================================================  INVCTRL  ======================================================== */
#define TT_FTM_INVCTRL_INV0EN_Pos         (0UL)                     /*!< TT_FTM INVCTRL: INV0EN (Bit 0)                        */
#define TT_FTM_INVCTRL_INV0EN_Msk         (0x1UL)                   /*!< TT_FTM INVCTRL: INV0EN (Bitfield-Mask: 0x01)          */
#define TT_FTM_INVCTRL_INV1EN_Pos         (1UL)                     /*!< TT_FTM INVCTRL: INV1EN (Bit 1)                        */
#define TT_FTM_INVCTRL_INV1EN_Msk         (0x2UL)                   /*!< TT_FTM INVCTRL: INV1EN (Bitfield-Mask: 0x01)          */
#define TT_FTM_INVCTRL_INV2EN_Pos         (2UL)                     /*!< TT_FTM INVCTRL: INV2EN (Bit 2)                        */
#define TT_FTM_INVCTRL_INV2EN_Msk         (0x4UL)                   /*!< TT_FTM INVCTRL: INV2EN (Bitfield-Mask: 0x01)          */
#define TT_FTM_INVCTRL_INV3EN_Pos         (3UL)                     /*!< TT_FTM INVCTRL: INV3EN (Bit 3)                        */
#define TT_FTM_INVCTRL_INV3EN_Msk         (0x8UL)                   /*!< TT_FTM INVCTRL: INV3EN (Bitfield-Mask: 0x01)          */
/* ========================================================  SWOCTRL  ======================================================== */
#define TT_FTM_SWOCTRL_CHnOC_Pos          (0UL)                     /*!< TT_FTM SWOCTRL: CH0OC (Bit 0)                         */
#define TT_FTM_SWOCTRL_CHnOC_Msk          (0x1UL)                   /*!< TT_FTM SWOCTRL: CH0OC (Bitfield-Mask: 0x01)           */
#define TT_FTM_SWOCTRL_CHnOCV_Pos         (8UL)                     /*!< TT_FTM SWOCTRL: CH0OCV (Bit 8)                        */
#define TT_FTM_SWOCTRL_CHnOCV_Msk         (0x100UL)                 /*!< TT_FTM SWOCTRL: CH0OCV (Bitfield-Mask: 0x01)          */
/* ========================================================  PWMLOAD  ======================================================== */
#define TT_FTM_PWMLOAD_CH0SEL_Pos         (0UL)                     /*!< TT_FTM PWMLOAD: CH0SEL (Bit 0)                        */
#define TT_FTM_PWMLOAD_CH0SEL_Msk         (0x1UL)                   /*!< TT_FTM PWMLOAD: CH0SEL (Bitfield-Mask: 0x01)          */
#define TT_FTM_PWMLOAD_CH1SEL_Pos         (1UL)                     /*!< TT_FTM PWMLOAD: CH1SEL (Bit 1)                        */
#define TT_FTM_PWMLOAD_CH1SEL_Msk         (0x2UL)                   /*!< TT_FTM PWMLOAD: CH1SEL (Bitfield-Mask: 0x01)          */
#define TT_FTM_PWMLOAD_CH2SEL_Pos         (2UL)                     /*!< TT_FTM PWMLOAD: CH2SEL (Bit 2)                        */
#define TT_FTM_PWMLOAD_CH2SEL_Msk         (0x4UL)                   /*!< TT_FTM PWMLOAD: CH2SEL (Bitfield-Mask: 0x01)          */
#define TT_FTM_PWMLOAD_CH3SEL_Pos         (3UL)                     /*!< TT_FTM PWMLOAD: CH3SEL (Bit 3)                        */
#define TT_FTM_PWMLOAD_CH3SEL_Msk         (0x8UL)                   /*!< TT_FTM PWMLOAD: CH3SEL (Bitfield-Mask: 0x01)          */
#define TT_FTM_PWMLOAD_CH4SEL_Pos         (4UL)                     /*!< TT_FTM PWMLOAD: CH4SEL (Bit 4)                        */
#define TT_FTM_PWMLOAD_CH4SEL_Msk         (0x10UL)                  /*!< TT_FTM PWMLOAD: CH4SEL (Bitfield-Mask: 0x01)          */
#define TT_FTM_PWMLOAD_CH5SEL_Pos         (5UL)                     /*!< TT_FTM PWMLOAD: CH5SEL (Bit 5)                        */
#define TT_FTM_PWMLOAD_CH5SEL_Msk         (0x20UL)                  /*!< TT_FTM PWMLOAD: CH5SEL (Bitfield-Mask: 0x01)          */
#define TT_FTM_PWMLOAD_CH6SEL_Pos         (6UL)                     /*!< TT_FTM PWMLOAD: CH6SEL (Bit 6)                        */
#define TT_FTM_PWMLOAD_CH6SEL_Msk         (0x40UL)                  /*!< TT_FTM PWMLOAD: CH6SEL (Bitfield-Mask: 0x01)          */
#define TT_FTM_PWMLOAD_CH7SEL_Pos         (7UL)                     /*!< TT_FTM PWMLOAD: CH7SEL (Bit 7)                        */
#define TT_FTM_PWMLOAD_CH7SEL_Msk         (0x80UL)                  /*!< TT_FTM PWMLOAD: CH7SEL (Bitfield-Mask: 0x01)          */
#define TT_FTM_PWMLOAD_HCSEL_Pos          (8UL)                     /*!< TT_FTM PWMLOAD: HCSEL (Bit 8)                         */
#define TT_FTM_PWMLOAD_HCSEL_Msk          (0x100UL)                 /*!< TT_FTM PWMLOAD: HCSEL (Bitfield-Mask: 0x01)           */
#define TT_FTM_PWMLOAD_LDOK_Pos           (9UL)                     /*!< TT_FTM PWMLOAD: LDOK (Bit 9)                          */
#define TT_FTM_PWMLOAD_LDOK_Msk           (0x200UL)                 /*!< TT_FTM PWMLOAD: LDOK (Bitfield-Mask: 0x01)            */
#define TT_FTM_PWMLOAD_GLEN_Pos           (10UL)                    /*!< TT_FTM PWMLOAD: GLEN (Bit 10)                         */
#define TT_FTM_PWMLOAD_GLEN_Msk           (0x400UL)                 /*!< TT_FTM PWMLOAD: GLEN (Bitfield-Mask: 0x01)            */
#define TT_FTM_PWMLOAD_GLDOK_Pos          (11UL)                    /*!< TT_FTM PWMLOAD: GLDOK (Bit 11)                        */
#define TT_FTM_PWMLOAD_GLDOK_Msk          (0x800UL)                 /*!< TT_FTM PWMLOAD: GLDOK (Bitfield-Mask: 0x01)           */
/* ==========================================================  HCR  ========================================================== */
#define TT_FTM_HCR_HCVAL_Pos              (0UL)                     /*!< TT_FTM HCR: HCVAL (Bit 0)                             */
#define TT_FTM_HCR_HCVAL_Msk              (0xffffUL)                /*!< TT_FTM HCR: HCVAL (Bitfield-Mask: 0xffff)             */
/* =====================================================  PAIRnDEADTIME  ===================================================== */
#define TT_FTM_PAIRnDEADTIME_DTVAL_Pos    (0UL)                     /*!< TT_FTM PAIRnDEADTIME: DTVAL (Bit 0)                   */
#define TT_FTM_PAIRnDEADTIME_DTVAL_Msk    (0x3fUL)                  /*!< TT_FTM PAIRnDEADTIME: DTVAL (Bitfield-Mask: 0x3f)     */
#define TT_FTM_PAIRnDEADTIME_DTPS_Pos     (6UL)                     /*!< TT_FTM PAIRnDEADTIME: DTPS (Bit 6)                    */
#define TT_FTM_PAIRnDEADTIME_DTPS_Msk     (0xc0UL)                  /*!< TT_FTM PAIRnDEADTIME: DTPS (Bitfield-Mask: 0x03)      */
#define TT_FTM_PAIRnDEADTIME_DTVALEX_Pos  (16UL)                    /*!< TT_FTM PAIRnDEADTIME: DTVALEX (Bit 16)                */
#define TT_FTM_PAIRnDEADTIME_DTVALEX_Msk  (0xf0000UL)               /*!< TT_FTM PAIRnDEADTIME: DTVALEX (Bitfield-Mask: 0x0f)   */
/* ======================================================  MOD_MIRROR  ======================================================= */
#define TT_FTM_MOD_MIRROR_FRACMOD_Pos     (11UL)                    /*!< TT_FTM MOD_MIRROR: FRACMOD (Bit 11)                   */
#define TT_FTM_MOD_MIRROR_FRACMOD_Msk     (0xf800UL)                /*!< TT_FTM MOD_MIRROR: FRACMOD (Bitfield-Mask: 0x1f)      */
#define TT_FTM_MOD_MIRROR_MOD_Pos         (16UL)                    /*!< TT_FTM MOD_MIRROR: MOD (Bit 16)                       */
#define TT_FTM_MOD_MIRROR_MOD_Msk         (0xffff0000UL)            /*!< TT_FTM MOD_MIRROR: MOD (Bitfield-Mask: 0xffff)        */
/* ======================================================  CnV_MIRROR  ======================================================= */
#define TT_FTM_CnV_MIRROR_FRACVAL_Pos     (11UL)                    /*!< TT_FTM CnV_MIRROR: FRACVAL (Bit 11)                   */
#define TT_FTM_CnV_MIRROR_FRACVAL_Msk     (0xf800UL)                /*!< TT_FTM CnV_MIRROR: FRACVAL (Bitfield-Mask: 0x1f)      */
#define TT_FTM_CnV_MIRROR_VAL_Pos         (16UL)                    /*!< TT_FTM CnV_MIRROR: VAL (Bit 16)                       */
#define TT_FTM_CnV_MIRROR_VAL_Msk         (0xffff0000UL)            /*!< TT_FTM CnV_MIRROR: VAL (Bitfield-Mask: 0xffff)        */

/* =========================================================================================================================== */
/* ================                                        TT_FTM                                         ================ */
/* =========================================================================================================================== */

extern TT_CONST uint32 FTM_BASE_ADDR32[];
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
@brief  FTM (FTM0-FTM5)
@details A8 System Memory Map
*/
#define FTM_0_BASEADDR        	0x40110000UL
#define FTM_1_BASEADDR        	0x40111000UL
#define FTM_2_BASEADDR         	0x400D4000UL
#define FTM_3_BASEADDR         	0x400D5000UL
#define FTM_4_BASEADDR         	0x400AB000UL
#define FTM_5_BASEADDR         	0x400AC000UL

#define FTM_MOD_MASK_U8     	((uint8)0xF8)
#define FTM_MOD_SHIFT       	((uint8)3U)
#define FTM_CH_MASK_U8      	((uint8)0x7)
#define FTM_CH_SHIFT        	((uint8)0U)

/**
* @brief FTM module decoding
*/
#define FTM_MODULE_INDEX_U8(ch)      ((uint8)(((ch) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT))

/**
* @brief FTM channel decoding
*/
#define FTM_CHANNEL_INDEX_U8(ch)     ((uint8)(((ch) & FTM_CH_MASK_U8)  >> FTM_CH_SHIFT))

/**
* @brief FTM module encoding
*/
#define FTM_MODULE_CHANNEL_U8(module, ch)     ((uint8)(((module) << FTM_MOD_SHIFT) | (ch)))

/**
* @{
* @brief FTM Module Registers - Channel specific registers.
*/
#define FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx) (FTM_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(3UL)) + 0xCUL))
#define FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx)  (FTM_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(3UL)) + 0x10UL))
#define FTM_CV_MIRROR_ADDR32(u8ModuleIdx, u8ChannelIdx)  (FTM_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(2UL)) + 0x204UL))

/**
* @{
* @brief FTM Module Registers - Configuration registers.
*/
#define FTM_SC_ADDR32(u8ModuleIdx)                                  (FTM_BASE_ADDR32[(u8ModuleIdx)])
#define FTM_CNT_ADDR32(u8ModuleIdx)                                 (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x4UL)
#define FTM_MOD_ADDR32(u8ModuleIdx)                                 (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x8UL)
#define FTM_CNTIN_ADDR32(u8ModuleIdx)                               (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x4CUL)
#define FTM_STATUS_ADDR32(u8ModuleIdx)                              (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x50UL)           
#define FTM_MODE_ADDR32(u8ModuleIdx)                                (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x54UL)     
#define FTM_SYNC_ADDR32(u8ModuleIdx)                                (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x58UL)
#define FTM_OUTINIT_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x5CUL)
#define FTM_OUTMASK_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x60UL)
#define FTM_COMBINE_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x64UL)
#define FTM_DEADTIME_ADDR32(u8ModuleIdx)                            (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x68UL)
#define FTM_EXTTRIG_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x6CUL)
#define FTM_POL_ADDR32(u8ModuleIdx)                                 (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x70UL)
#define FTM_FMS_ADDR32(u8ModuleIdx)                                 (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x74UL)
#define FTM_FILTER_ADDR32(u8ModuleIdx)                              (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x78UL)   
#define FTM_FLTCTRL_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x7CUL)
#define FTM_QDCTRL_ADDR32(u8ModuleIdx)                              (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x80UL)
#define FTM_CONF_ADDR32(u8ModuleIdx)                                (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x84UL)
#define FTM_FLTPOL_ADDR32(u8ModuleIdx)                              (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x88UL)
#define FTM_SYNCONF_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x8CUL)
#define FTM_INVCTRL_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x90UL)
#define FTM_SWOCTRL_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x94UL)
#define FTM_PWMLOAD_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x98UL)
#define FTM_HCR_ADDR32(u8ModuleIdx)                              	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x9CUL)
#define FTM_PAIR0DEADTIME_ADDR32(u8ModuleIdx)                       (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0xA0UL)
#define FTM_PAIR1DEADTIME_ADDR32(u8ModuleIdx)                       (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0xA8UL)
#define FTM_PAIR2DEADTIME_ADDR32(u8ModuleIdx)                       (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0xB0UL)
#define FTM_PAIR3DEADTIME_ADDR32(u8ModuleIdx)                       (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0xB8UL)
#define FTM_MOD_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x200UL)
#define FTM_C0V_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x204UL)
#define FTM_C1V_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x208UL)
#define FTM_C2V_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x20CUL)
#define FTM_C3V_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x210UL)
#define FTM_C4V_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x214UL)
#define FTM_C5V_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x218UL)
#define FTM_C6V_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x21CUL)
#define FTM_C7V_MIRROR_ADDR32(u8ModuleIdx)                         	(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x220UL)
#define FTM_SV_ADDR32(u8ModuleIdx) 									(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0xFF8UL)
#define FTM_ID_ADDR32(u8ModuleIdx) 									(FTM_BASE_ADDR32[(u8ModuleIdx)] + 0xFFCUL)

/** MASK and SHIFT values for each register field */
/**
@{
* @brief FTMx_SC - Status And Control Register - bitfield mask and shift defines.
*/
#define FTM_SC_TOF_MASK_U32                 ((uint32)(BIT9))
#ifndef FTM_SC_TOF_SHIFT
#define FTM_SC_TOF_SHIFT                    ((uint32)(9U))
#endif

#define FTM_SC_TOIE_MASK_U32                ((uint32)(BIT8))
#ifndef FTM_SC_TOIE_SHIFT
#define FTM_SC_TOIE_SHIFT                   ((uint32)(8U))
#endif

#define FTM_SC_RF_MASK_U32                  ((uint32)(BIT7))
#ifndef FTM_SC_RF_SHIFT
#define FTM_SC_RF_SHIFT                     ((uint32)(7U))
#endif

#define FTM_SC_RIE_MASK_U32                 ((uint32)(BIT6))
#ifndef FTM_SC_RIE_SHIFT
#define FTM_SC_RIE_SHIFT                    ((uint32)(6U))
#endif

#define FTM_SC_CPWMS_MASK_U32               ((uint32)(BIT5))
#ifndef FTM_SC_CPWMS_SHIFT
#define FTM_SC_CPWMS_SHIFT                  ((uint32)(5U))
#endif

#define FTM_SC_CLKS_MASK_U32                ((uint32)(BIT4|BIT3))
#ifndef FTM_SC_CLKS_SHIFT
#define FTM_SC_CLKS_SHIFT                   ((uint32)(3U))
#endif

#define FTM_SC_PS_MASK_U32                  ((uint32)(BIT2|BIT1|BIT0))

/**
* @{
* @brief FTMx_MOD - Modulo Register - bitfield mask and shift defines.
*/
#define FTM_MOD_MOD_MASK_U32                ((uint32)(0xFFFF))
#define FTM_MOD_MOD_MASK_SHIFT              ((uint32)(0U))
#define FTM_MOD_MOD_MAX_VALUE               ((uint32)(0xFFFF))

/**
* @{
* @brief FTMx_CnSC - Channel Status And Control Register - bitfield mask and shift defines.
*/
#define FTM_CSC_CHOV_MASK_U32       ((uint32)(BIT10))
#define FTM_CSC_CHOV_SHIFT          ((uint32)(10U))
#define FTM_CSC_CHIS_MASK_U32       ((uint32)(BIT9))
#define FTM_CSC_CHIS_SHIFT          ((uint32)(9U))

#define FTM_CSC_TRIGMODE_MASK_U32          ((uint32)(BIT8))
#define FTM_CSC_TRIGMODE_SHIFT             ((uint32)(8U))

#define FTM_CSC_CHF_MASK_U32               ((uint32)(BIT7))
#define FTM_CSC_CHF_SHIFT                  ((uint32)(7U))

#define FTM_CSC_CHIE_MASK_U32              ((uint32)(BIT6))
#define FTM_CSC_CHIE_SHIFT                 ((uint32)(6U))

#define FTM_CSC_MSB_MASK_U32               ((uint32)(BIT5))
#define FTM_CSC_MSB_SHIFT                  ((uint32)(5U))

#define FTM_CSC_MSA_MASK_U32               ((uint32)(BIT4))
#define FTM_CSC_MSA_SHIFT                  ((uint32)(4U))

#define FTM_CSC_ELSB_MASK_U32              ((uint32)(BIT3))
#define FTM_CSC_ELSB_SHIFT                 ((uint32)(3U))

#define FTM_CSC_ELSA_MASK_U32              ((uint32)(BIT2))
#define FTM_CSC_ELSA_SHIFT                 ((uint32)(2U))

#define FTM_CSC_ICRST_MASK_U32             ((uint32)(BIT1))
#define FTM_CSC_ICRST_SHIFT                ((uint32)(1U))

#define FTM_CSC_DMA_MASK_U32               ((uint32)(BIT0))
#define FTM_CSC_DMA_SHIFT                  ((uint32)(0U))

/**
@{
* @brief FTMx_CnV - Channel Value - bitfield mask and shift defines.
*/
#define FTM_CV_VAL_MASK_U32                ((uint32)(0xFFFFU))

/**
@{
* @brief FTMx_CNT - Counter Value - bitfield mask and shift defines.
*/

#define FTM_CNT_COUNT_MASK_U32             ((uint32)(0xFFFFU))
/**
@{
* @brief FTMx_CNTIN - Counter Initial Value - bitfield mask and shift defines.
*/
#define FTM_CNTIN_INIT_MASK_U32            ((uint32)(0xFFFFU))  

/**
@{
* @brief FTMx_STATUS - Capture and Compare Status Register - bitfield mask and shift defines.
*/
#define FTM_STATUS_CH7F_MASK_U32            ((uint32)(BIT7))
#ifndef FTM_STATUS_CH7F_SHIFT
#define FTM_STATUS_CH7F_SHIFT               ((uint32)(7U))
#endif

#define FTM_STATUS_CH6F_MASK_U32            ((uint32)(BIT6))
#ifndef FTM_STATUS_CH6F_SHIFT
#define FTM_STATUS_CH6F_SHIFT               ((uint32)(6U))
#endif

#define FTM_STATUS_CH5F_MASK_U32            ((uint32)(BIT5))
#ifndef FTM_STATUS_CH5F_SHIFT
#define FTM_STATUS_CH5F_SHIFT               ((uint32)(5U))
#endif

#define FTM_STATUS_CH4F_MASK_U32            ((uint32)(BIT4))
#ifndef FTM_STATUS_CH4F_SHIFT
#define FTM_STATUS_CH4F_SHIFT               ((uint32)(4U))
#endif

#define FTM_STATUS_CH3F_MASK_U32            ((uint32)(BIT3))
#ifndef FTM_STATUS_CH3F_SHIFT
#define FTM_STATUS_CH3F_SHIFT               ((uint32)(3U))
#endif

#define FTM_STATUS_CH2F_MASK_U32            ((uint32)(BIT2))
#ifndef FTM_STATUS_CH2F_SHIFT
#define FTM_STATUS_CH2F_SHIFT               ((uint32)(2U))
#endif

#define FTM_STATUS_CH1F_MASK_U32            ((uint32)(BIT1))
#ifndef FTM_STATUS_CH1F_SHIFT
#define FTM_STATUS_CH1F_SHIFT               ((uint32)(1U))
#endif

#define FTM_STATUS_CH0F_MASK_U32            ((uint32)(BIT0))

/**
@{
* @brief FTMx_MODE - Features Mode Selection Register - bitfield mask and shift defines.
*/
#define FTM_MODE_FAULTIE_MASK_U32           ((uint32)(BIT7))
#ifndef FTM_MODE_FAULTIE_SHIFT
#define FTM_MODE_FAULTIE_SHIFT              ((uint32)(7U))
#endif

#define FTM_MODE_FAULTM_MASK_U32            ((uint32)(BIT6|BIT5))
#ifndef FTM_MODE_FAULTM_SHIFT
#define FTM_MODE_FAULTM_SHIFT               ((uint32)(5U))
#endif

#define FTM_MODE_CAPTEST_MASK_U32           ((uint32)(BIT4))
#ifndef FTM_MODE_CAPTEST_SHIFT
#define FTM_MODE_CAPTEST_SHIFT              ((uint32)(4U))
#endif

#define FTM_MODE_PWMSYNC_MASK_U32           ((uint32)(BIT3))
#ifndef FTM_MODE_PWMSYNC_SHIFT
#define FTM_MODE_PWMSYNC_SHIFT              ((uint32)(3U))
#endif

#define FTM_MODE_WPDIS_MASK_U32             ((uint32)(BIT2))
#ifndef FTM_MODE_WPDIS_SHIFT
#define FTM_MODE_WPDIS_SHIFT                ((uint32)(2U))
#endif

#define FTM_MODE_INIT_MASK_U32              ((uint32)(BIT1))
#ifndef FTM_MODE_INIT_SHIFT
#define FTM_MODE_INIT_SHIFT                 ((uint32)(1U))
#endif

#define FTM_MODE_FTMEN_MASK_U32             ((uint32)(BIT0))

/**
@{
* @brief FTMx_SYNC - Synchronization Register - bitfield mask and shift defines.
*/
#define FTM_SYNC_SWSYNC_MASK_U32         ((uint32)(BIT7))
#ifndef FTM_SYNC_SWSYNC_SHIFT
#define FTM_SYNC_SWSYNC_SHIFT            ((uint32)(7U))
#endif

#define FTM_SYNC_TRIG2_MASK_U32          ((uint32)(BIT6))
#ifndef FTM_SYNC_TRIG2_SHIFT
#define FTM_SYNC_TRIG2_SHIFT             ((uint32)(6U))
#endif

#define FTM_SYNC_TRIG1_MASK_U32          ((uint32)(BIT5))
#ifndef FTM_SYNC_TRIG1_SHIFT
#define FTM_SYNC_TRIG1_SHIFT             ((uint32)(5U))
#endif

#define FTM_SYNC_TRIG0_MASK_U32          ((uint32)(BIT4))
#ifndef FTM_SYNC_TRIG0_SHIFT
#define FTM_SYNC_TRIG0_SHIFT             ((uint32)(4U))
#endif

#define FTM_SYNC_SYNCHOM_MASK_U32        ((uint32)(BIT3))
#ifndef FTM_SYNC_SYNCHOM_SHIFT
#define FTM_SYNC_SYNCHOM_SHIFT           ((uint32)(3U))
#endif

#define FTM_SYNC_REINIT_MASK_U32         ((uint32)(BIT2))
#ifndef FTM_SYNC_REINIT_SHIFT
#define FTM_SYNC_REINIT_SHIFT            ((uint32)(2U))
#endif

#define FTM_SYNC_CNTMAX_MASK_U32         ((uint32)(BIT1))
#ifndef FTM_SYNC_CNTMAX_SHIFT
#define FTM_SYNC_CNTMAX_SHIFT            ((uint32)(1U))
#endif

#define FTM_SYNC_CNTMIN_MASK_U32         ((uint32)(BIT0))

/**
@{
* @brief FTMx_OUTINIT - Initial State For Channels Output - bitfield mask and shift defines.
*/
#define FTM_OUTINIT_CH7OI_MASK_U32       ((uint32)(BIT7))
#ifndef FTM_OUTINIT_CH7OI_SHIFT
#define FTM_OUTINIT_CH7OI_SHIFT          ((uint32)(7U))
#endif

#define FTM_OUTINIT_CH6OI_MASK_U32       ((uint32)(BIT6))
#ifndef FTM_OUTINIT_CH6OI_SHIFT
#define FTM_OUTINIT_CH6OI_SHIFT          ((uint32)(6U))
#endif

#define FTM_OUTINIT_CH5OI_MASK_U32       ((uint32)(BIT5))
#ifndef FTM_OUTINIT_CH5OI_SHIFT
#define FTM_OUTINIT_CH5OI_SHIFT          ((uint32)(5U))
#endif

#define FTM_OUTINIT_CH4OI_MASK_U32       ((uint32)(BIT4))
#ifndef FTM_OUTINIT_CH4OI_SHIFT
#define FTM_OUTINIT_CH4OI_SHIFT          ((uint32)(4U))
#endif

#define FTM_OUTINIT_CH3OI_MASK_U32       ((uint32)(BIT3))
#ifndef FTM_OUTINIT_CH3OI_SHIFT
#define FTM_OUTINIT_CH3OI_SHIFT          ((uint32)(3U))
#endif

#define FTM_OUTINIT_CH2OI_MASK_U32       ((uint32)(BIT2))
#ifndef FTM_OUTINIT_CH2OI_SHIFT
#define FTM_OUTINIT_CH2OI_SHIFT          ((uint32)(2U))
#endif

#define FTM_OUTINIT_CH1OI_MASK_U32       ((uint32)(BIT1))
#ifndef FTM_OUTINIT_CH1OI_SHIFT
#define FTM_OUTINIT_CH1OI_SHIFT          ((uint32)(1U))
#endif

#define FTM_OUTINIT_CH0OI_MASK_U32       ((uint32)(BIT0))

/**
@{
* @brief FTMx_OUTMASK - Output Mask - bitfield mask and shift defines.
*/
#define FTM_OUTMASK_CH7OM_MASK_U32       ((uint32)(BIT7))
#ifndef FTM_OUTMASK_CH7OM_SHIFT
#define FTM_OUTMASK_CH7OM_SHIFT          ((uint32)(7U))
#endif

#define FTM_OUTMASK_CH6OM_MASK_U32       ((uint32)(BIT6))
#ifndef FTM_OUTMASK_CH6OM_SHIFT
#define FTM_OUTMASK_CH6OM_SHIFT          ((uint32)(6U))
#endif

#define FTM_OUTMASK_CH5OM_MASK_U32       ((uint32)(BIT5))
#ifndef FTM_OUTMASK_CH5OM_SHIFT
#define FTM_OUTMASK_CH5OM_SHIFT          ((uint32)(5U))
#endif

#define FTM_OUTMASK_CH4OM_MASK_U32       ((uint32)(BIT4))
#ifndef FTM_OUTMASK_CH4OM_SHIFT
#define FTM_OUTMASK_CH4OM_SHIFT          ((uint32)(4U))
#endif

#define FTM_OUTMASK_CH3OM_MASK_U32       ((uint32)(BIT3))
#ifndef FTM_OUTMASK_CH3OM_SHIFT
#define FTM_OUTMASK_CH3OM_SHIFT          ((uint32)(3U))
#endif

#define FTM_OUTMASK_CH2OM_MASK_U32       ((uint32)(BIT2))
#ifndef FTM_OUTMASK_CH2OM_SHIFT
#define FTM_OUTMASK_CH2OM_SHIFT          ((uint32)(2U))
#endif

#define FTM_OUTMASK_CH1OM_MASK_U32       ((uint32)(BIT1))
#ifndef FTM_OUTMASK_CH1OM_SHIFT
#define FTM_OUTMASK_CH1OM_SHIFT          ((uint32)(1U))
#endif

#define FTM_OUTMASK_CH0OM_MASK_U32       ((uint32)(BIT0))

/**
@{
* @brief FTMx_COMBINE - Function For Linked Channels - bitfield mask and shift defines.
*/
#define FTM_COMBINE_MCOMBINE3_MASK_U32   ((uint32)(BIT31))
#ifndef FTM_COMBINE_MCOMBINE3_SHIFT
#define FTM_COMBINE_MCOMBINE3_SHIFT      ((uint32)(31U))
#endif

#define FTM_COMBINE_FAULTEN3_MASK_U32    ((uint32)(BIT30))
#ifndef FTM_COMBINE_FAULTEN3_SHIFT
#define FTM_COMBINE_FAULTEN3_SHIFT       ((uint32)(30U))
#endif

#define FTM_COMBINE_SYNCEN3_MASK_U32     ((uint32)(BIT29))
#ifndef FTM_COMBINE_SYNCEN3_SHIFT
#define FTM_COMBINE_SYNCEN3_SHIFT        ((uint32)(29U))
#endif

#define FTM_COMBINE_DTEN3_MASK_U32       ((uint32)(BIT28))
#ifndef FTM_COMBINE_DTEN3_SHIFT
#define FTM_COMBINE_DTEN3_SHIFT          ((uint32)(28U))
#endif

#define FTM_COMBINE_DECAP3_MASK_U32      ((uint32)(BIT27))
#ifndef FTM_COMBINE_DECAP3_SHIFT
#define FTM_COMBINE_DECAP3_SHIFT         ((uint32)(27U))
#endif

#define FTM_COMBINE_DECAPEN3_MASK_U32    ((uint32)(BIT26))
#ifndef FTM_COMBINE_DECAPEN3_SHIFT
#define FTM_COMBINE_DECAPEN3_SHIFT       ((uint32)(26U))
#endif

#define FTM_COMBINE_COMP3_MASK_U32       ((uint32)(BIT25))
#ifndef FTM_COMBINE_COMP3_SHIFT
#define FTM_COMBINE_COMP3_SHIFT          ((uint32)(25U))
#endif

#define FTM_COMBINE_COMBINE3_MASK_U32    ((uint32)(BIT24))
#ifndef FTM_COMBINE_COMBINE3_SHIFT
#define FTM_COMBINE_COMBINE3_SHIFT       ((uint32)(24U))
#endif

#define FTM_COMBINE_MCOMBINE2_MASK_U32   ((uint32)(BIT23))
#ifndef FTM_COMBINE_MCOMBINE2_SHIFT
#define FTM_COMBINE_MCOMBINE2_SHIFT      ((uint32)(23))
#endif

#define FTM_COMBINE_FAULTEN2_MASK_U32    ((uint32)(BIT22))
#ifndef FTM_COMBINE_FAULTEN2_SHIFT
#define FTM_COMBINE_FAULTEN2_SHIFT       ((uint32)(22U))
#endif

#define FTM_COMBINE_SYNCEN2_MASK_U32     ((uint32)(BIT21))
#ifndef FTM_COMBINE_SYNCEN2_SHIFT
#define FTM_COMBINE_SYNCEN2_SHIFT        ((uint32)(21U))
#endif

#define FTM_COMBINE_DTEN2_MASK_U32       ((uint32)(BIT20))
#ifndef FTM_COMBINE_DTEN2_SHIFT
#define FTM_COMBINE_DTEN2_SHIFT          ((uint32)(20U))
#endif

#define FTM_COMBINE_DECAP2_MASK_U32      ((uint32)(BIT19))
#ifndef FTM_COMBINE_DECAP2_SHIFT
#define FTM_COMBINE_DECAP2_SHIFT         ((uint32)(19U))
#endif

#define FTM_COMBINE_DECAPEN2_MASK_U32    ((uint32)(BIT18))
#ifndef FTM_COMBINE_DECAPEN2_SHIFT
#define FTM_COMBINE_DECAPEN2_SHIFT       ((uint32)(18U))
#endif

#define FTM_COMBINE_COMP2_MASK_U32       ((uint32)(BIT17))
#ifndef FTM_COMBINE_COMP2_SHIFT
#define FTM_COMBINE_COMP2_SHIFT          ((uint32)(17U))
#endif

#define FTM_COMBINE_COMBINE2_MASK_U32    ((uint32)(BIT16))
#ifndef FTM_COMBINE_COMBINE2_SHIFT
#define FTM_COMBINE_COMBINE2_SHIFT       ((uint32)(16U))
#endif

#define FTM_COMBINE_MCOMBINE1_MASK_U32   ((uint32)(BIT15))
#ifndef FTM_COMBINE_MCOMBINE1_SHIFT
#define FTM_COMBINE_MCOMBINE1_SHIFT      ((uint32)(15))
#endif

#define FTM_COMBINE_FAULTEN1_MASK_U32    ((uint32)(BIT14))
#ifndef FTM_COMBINE_FAULTEN1_SHIFT
#define FTM_COMBINE_FAULTEN1_SHIFT       ((uint32)(14U))
#endif

#define FTM_COMBINE_SYNCEN1_MASK_U32     ((uint32)(BIT13))
#ifndef FTM_COMBINE_SYNCEN1_SHIFT
#define FTM_COMBINE_SYNCEN1_SHIFT        ((uint32)(13U))
#endif

#define FTM_COMBINE_DTEN1_MASK_U32       ((uint32)(BIT12))
#ifndef FTM_COMBINE_DTEN1_SHIFT
#define FTM_COMBINE_DTEN1_SHIFT          ((uint32)(12U))
#endif

#define FTM_COMBINE_DECAP1_MASK_U32      ((uint32)(BIT11))
#ifndef FTM_COMBINE_DECAP1_SHIFT
#define FTM_COMBINE_DECAP1_SHIFT         ((uint32)(11U))
#endif

#define FTM_COMBINE_DECAPEN1_MASK_U32    ((uint32)(BIT10))
#ifndef FTM_COMBINE_DECAPEN1_SHIFT
#define FTM_COMBINE_DECAPEN1_SHIFT       ((uint32)(10U))
#endif

#define FTM_COMBINE_COMP1_MASK_U32       ((uint32)(BIT9))
#ifndef FTM_COMBINE_COMP1_SHIFT
#define FTM_COMBINE_COMP1_SHIFT          ((uint32)(9U))
#endif

#define FTM_COMBINE_COMBINE1_MASK_U32    ((uint32)(BIT8))
#ifndef FTM_COMBINE_COMBINE1_SHIFT
#define FTM_COMBINE_COMBINE1_SHIFT       ((uint32)(8U))
#endif


#define FTM_COMBINE_MCOMBINE0_MASK_U32   ((uint32)(BIT7))
#ifndef FTM_COMBINE_MCOMBINE0_SHIFT
#define FTM_COMBINE_MCOMBINE0_SHIFT      ((uint32)(7))
#endif

#define FTM_COMBINE_FAULTEN0_MASK_U32    ((uint32)(BIT6))
#ifndef FTM_COMBINE_FAULTEN0_SHIFT
#define FTM_COMBINE_FAULTEN0_SHIFT       ((uint32)(6U))
#endif

#define FTM_COMBINE_SYNCEN0_MASK_U32     ((uint32)(BIT5))
#ifndef FTM_COMBINE_SYNCEN0_SHIFT
#define FTM_COMBINE_SYNCEN0_SHIFT        ((uint32)(5U))
#endif

#define FTM_COMBINE_DTEN0_MASK_U32       ((uint32)(BIT4))
#ifndef FTM_COMBINE_DTEN0_SHIFT
#define FTM_COMBINE_DTEN0_SHIFT          ((uint32)(4U))
#endif

#define FTM_COMBINE_DECAP0_MASK_U32      ((uint32)(BIT3))
#ifndef FTM_COMBINE_DECAP0_SHIFT
#define FTM_COMBINE_DECAP0_SHIFT         ((uint32)(3U))
#endif

#define FTM_COMBINE_DECAPEN0_MASK_U32    ((uint32)(BIT2))
#ifndef FTM_COMBINE_DECAPEN0_SHIFT
#define FTM_COMBINE_DECAPEN0_SHIFT       ((uint32)(2U))
#endif

#define FTM_COMBINE_COMP0_MASK_U32       ((uint32)(BIT1))
#ifndef FTM_COMBINE_COMP0_SHIFT
#define FTM_COMBINE_COMP0_SHIFT          ((uint32)(1U))
#endif

#define FTM_COMBINE_COMBINE0_MASK_U32    ((uint32)(BIT0))
#ifndef FTM_COMBINE_COMBINE0_SHIFT
#define FTM_COMBINE_COMBINE0_SHIFT       ((uint32)(0U))
#endif

#define FTM_COMBINE_COMBINEx_SHIFT(u8ChannelIdx)        ((uint32)((((u8ChannelIdx) >> 1U) * 8U) + 0U))
#define FTM_COMBINE_COMBINEx_MASK_U32(u8ChannelIdx)     ((uint32)(BIT0 << FTM_COMBINE_COMBINEx_SHIFT(u8ChannelIdx)))

#define FTM_COMBINE_DECAPx_SHIFT(u8ChannelIdx)          ((uint32)((((u8ChannelIdx) >> 1U) * 8U) + 3U))
#define FTM_COMBINE_DECAPx_MASK_U32(u8ChannelIdx)       ((uint32)(BIT0 << FTM_COMBINE_DECAPx_SHIFT(u8ChannelIdx)))

#define FTM_COMBINE_DECAPENx_SHIFT(u8ChannelIdx)        ((uint32)((((u8ChannelIdx) >> 1U) * 8U)+ 2U))
#define FTM_COMBINE_DECAPENx_MASK_U32(u8ChannelIdx)     ((uint32)(BIT0 << FTM_COMBINE_DECAPENx_SHIFT(u8ChannelIdx)))

/**
@{
* @brief FTMx_DEADTIME - Deadtime Insertion Control - bitfield mask and shift defines.
*/
#define FTM_DEADTIME_DTVALEX_MASK_U32  ((uint32)(BIT19|BIT18|BIT17|BIT16))
#ifndef FTM_DEADTIME_DTVALEX_SHIFT
#define FTM_DEADTIME_DTVALEX_SHIFT     ((uint32)(16U))
#endif

#define FTM_DEADTIME_DTPS_MASK_U32      ((uint32)(BIT7|BIT6))
#ifndef FTM_DEADTIME_DTPS_SHIFT
#define FTM_DEADTIME_DTPS_SHIFT         ((uint32)(6U))
#endif

#define FTM_DEADTIME_DTVAL_MASK_U32     ((uint32)(BIT5|BIT4|BIT3|BIT2|BIT1|BIT0))

/**
@{
* @brief FTMx_EXTTRIG - FTM External Trigger - bitfield mask and shift defines.
*/
#define FTM_EXTTRIG_CH7TRIG_MASK_U32          ((uint32)(BIT9))
#ifndef FTM_EXTTRIG_CH7TRIG_SHIFT
#define FTM_EXTTRIG_CH7TRIG_SHIFT             ((uint32)(9U))
#endif

#define FTM_EXTTRIG_CH6TRIG_MASK_U32          ((uint32)(BIT8))
#ifndef FTM_EXTTRIG_CH6TRIG_SHIFT
#define FTM_EXTTRIG_CH6TRIG_SHIFT             ((uint32)(8U))
#endif

#define FTM_EXTTRIG_TRIGF_MASK_U32            ((uint32)(BIT7))
#ifndef FTM_EXTTRIG_TRIGF_SHIFT
#define FTM_EXTTRIG_TRIGF_SHIFT               ((uint32)(7U))
#endif

#define FTM_EXTTRIG_INITTRIGEN_MASK_U32       ((uint32)(BIT6))
#ifndef FTM_EXTTRIG_INITTRIGEN_SHIFT
#define FTM_EXTTRIG_INITTRIGEN_SHIFT          ((uint32)(6U))
#endif

#define FTM_EXTTRIG_CH1TRIG_MASK_U32          ((uint32)(BIT5))
#ifndef FTM_EXTTRIG_CH1TRIG_SHIFT
#define FTM_EXTTRIG_CH1TRIG_SHIFT             ((uint32)(5U))
#endif

#define FTM_EXTTRIG_CH0TRIG_MASK_U32          ((uint32)(BIT4))
#ifndef FTM_EXTTRIG_CH0TRIG_SHIFT
#define FTM_EXTTRIG_CH0TRIG_SHIFT             ((uint32)(4U))
#endif

#define FTM_EXTTRIG_CH5TRIG_MASK_U32          ((uint32)(BIT3))
#ifndef FTM_EXTTRIG_CH5TRIG_SHIFT
#define FTM_EXTTRIG_CH5TRIG_SHIFT             ((uint32)(3U))
#endif

#define FTM_EXTTRIG_CH4TRIG_MASK_U32          ((uint32)(BIT2))
#ifndef FTM_EXTTRIG_CH4TRIG_SHIFT
#define FTM_EXTTRIG_CH4TRIG_SHIFT             ((uint32)(2U))
#endif

#define FTM_EXTTRIG_CH3TRIG_MASK_U32          ((uint32)(BIT1))
#ifndef FTM_EXTTRIG_CH3TRIG_SHIFT
#define FTM_EXTTRIG_CH3TRIG_SHIFT             ((uint32)(1U))
#endif

#define FTM_EXTTRIG_CH2TRIG_MASK_U32          ((uint32)(BIT0))

/**
@{
* @brief FTMx_POL - Channels Polarity - bitfield mask and shift defines.
*/
#define FTM_POL_POL7_MASK_U32               ((uint32)(BIT7))
#ifndef FTM_POL_POL7_SHIFT
#define FTM_POL_POL7_SHIFT                  ((uint32)(7U))
#endif

#define FTM_POL_POL6_MASK_U32               ((uint32)(BIT6))
#ifndef FTM_POL_POL6_SHIFT
#define FTM_POL_POL6_SHIFT                  ((uint32)(6U))
#endif

#define FTM_POL_POL5_MASK_U32               ((uint32)(BIT5))
#ifndef FTM_POL_POL5_SHIFT
#define FTM_POL_POL5_SHIFT                  ((uint32)(5U))
#endif

#define FTM_POL_POL4_MASK_U32               ((uint32)(BIT4))
#ifndef FTM_POL_POL4_SHIFT
#define FTM_POL_POL4_SHIFT                  ((uint32)(4U))
#endif

#define FTM_POL_POL3_MASK_U32               ((uint32)(BIT3))
#ifndef FTM_POL_POL3_SHIFT
#define FTM_POL_POL3_SHIFT                  ((uint32)(3U))
#endif

#define FTM_POL_POL2_MASK_U32               ((uint32)(BIT2))
#ifndef FTM_POL_POL2_SHIFT
#define FTM_POL_POL2_SHIFT                  ((uint32)(2U))
#endif

#define FTM_POL_POL1_MASK_U32               ((uint32)(BIT1))
#ifndef FTM_POL_POL1_SHIFT
#define FTM_POL_POL1_SHIFT                  ((uint32)(1U))
#endif

#define FTM_POL_POL0_MASK_U32               ((uint32)(BIT0))

/**
@{
* @brief FTMx_FMS - Fault Mode Status - bitfield mask and shift defines.
*/
#define FTM_FMS_FAULTF_MASK_U32              ((uint32)(BIT7))
#ifndef FTM_FMS_FAULTF_SHIFT
#define FTM_FMS_FAULTF_SHIFT                 ((uint32)(7U))
#endif

#define FTM_FMS_WPEN_MASK_U32                ((uint32)(BIT6))
#ifndef FTM_FMS_WPEN_SHIFT
#define FTM_FMS_WPEN_SHIFT                   ((uint32)(6U))
#endif

#define FTM_FMS_FAULTIN_MASK_U32             ((uint32)(BIT5))
#ifndef FTM_FMS_FAULTIN_SHIFT
#define FTM_FMS_FAULTIN_SHIFT                ((uint32)(5U))
#endif

#define FTM_FMS_FAULTF3_MASK_U32             ((uint32)(BIT3))
#ifndef FTM_FMS_FAULTF3_SHIFT
#define FTM_FMS_FAULTF3_SHIFT                ((uint32)(3U))
#endif

#define FTM_FMS_FAULTF2_MASK_U32             ((uint32)(BIT2))
#ifndef FTM_FMS_FAULTF2_SHIFT
#define FTM_FMS_FAULTF2_SHIFT                ((uint32)(2U))
#endif

#define FTM_FMS_FAULTF1_MASK_U32             ((uint32)(BIT1))
#ifndef FTM_FMS_FAULTF1_SHIFT
#define FTM_FMS_FAULTF1_SHIFT                ((uint32)(1U))
#endif

#define FTM_FMS_FAULTF0_MASK_U32             ((uint32)(BIT0))

/**
@{
* @brief FTMx_FILTER - Input Capture Filter Control - bitfield mask and shift defines.
*/
#define FTM_FILTER_CH3FVAL_MASK_U32                 ((uint32)(BIT15|BIT14|BIT13|BIT12))
#ifndef FTM_FILTER_CH3FVAL_SHIFT
#define FTM_FILTER_CH3FVAL_SHIFT                    ((uint32)(12U))
#endif

#define FTM_FILTER_CH2FVAL_MASK_U32                 ((uint32)(BIT11|BIT10|BIT9|BIT8))
#ifndef FTM_FILTER_CH2FVAL_SHIFT
#define FTM_FILTER_CH2FVAL_SHIFT                    ((uint32)(8U))
#endif

#define FTM_FILTER_CH1FVAL_MASK_U32                 ((uint32)(BIT7|BIT6|BIT5|BIT4))
#ifndef FTM_FILTER_CH1FVAL_SHIFT
#define FTM_FILTER_CH1FVAL_SHIFT                    ((uint32)(4U))
#endif

#define FTM_FILTER_CH0FVAL_MASK_U32                 ((uint32)(BIT3|BIT2|BIT1|BIT0))
#ifndef FTM_FILTER_CH0FVAL_SHIFT
#define FTM_FILTER_CH0FVAL_SHIFT                    ((uint32)(0U))
#endif

#define FTM_FILTER_CHxFVAL_SHIFT(u8ChannelIdx)      ((uint32)((u8ChannelIdx) << 2UL))
#define FTM_FILTER_CHxFVAL_MASK_U32(u8ChannelIdx)   (FTM_FILTER_CH0FVAL_MASK_U32 << FTM_FILTER_CHxFVAL_SHIFT(u8ChannelIdx))

#define FTM_FILTER_MAX_NO_CH                        ((uint8)(4U))

/**
@{
* @brief FTMx_FLTCTRL - Fault Control - bitfield mask and shift defines.
*/
#define FTM_FLTCTRL_FSTATE_MASK_U32          ((uint32)(BIT15))
#ifndef FTM_FLTCTRL_FSTATE_SHIFT
#define FTM_FLTCTRL_FSTATE_SHIFT             ((uint32)(15U))
#endif

#define FTM_FLTCTRL_FFVAL_MASK_U32           ((uint32)(BIT11|BIT10|BIT9|BIT8))
#ifndef FTM_FLTCTRL_FFVAL_SHIFT
#define FTM_FLTCTRL_FFVAL_SHIFT              ((uint32)(8U))
#endif

#define FTM_FLTCTRL_FFLTR3EN_MASK_U32        ((uint32)(BIT7))
#ifndef FTM_FLTCTRL_FFLTR3EN_SHIFT
#define FTM_FLTCTRL_FFLTR3EN_SHIFT           ((uint32)(7U))
#endif

#define FTM_FLTCTRL_FFLTR2EN_MASK_U32        ((uint32)(BIT6))
#ifndef FTM_FLTCTRL_FFLTR2EN_SHIFT
#define FTM_FLTCTRL_FFLTR2EN_SHIFT           ((uint32)(6U))
#endif

#define FTM_FLTCTRL_FFLTR1EN_MASK_U32        ((uint32)(BIT5))
#ifndef FTM_FLTCTRL_FFLTR1EN_SHIFT
#define FTM_FLTCTRL_FFLTR1EN_SHIFT           ((uint32)(5U))
#endif

#define FTM_FLTCTRL_FFLTR0EN_MASK_U32        ((uint32)(BIT4))
#ifndef FTM_FLTCTRL_FFLTR0EN_SHIFT
#define FTM_FLTCTRL_FFLTR0EN_SHIFT           ((uint32)(4U))
#endif

#define FTM_FLTCTRL_FAULT3EN_MASK_U32        ((uint32)(BIT3))
#ifndef FTM_FLTCTRL_FAULT3EN_SHIFT
#define FTM_FLTCTRL_FAULT3EN_SHIFT           ((uint32)(3U))
#endif

#define FTM_FLTCTRL_FAULT2EN_MASK_U32        ((uint32)(BIT2))
#ifndef FTM_FLTCTRL_FAULT2EN_SHIFT
#define FTM_FLTCTRL_FAULT2EN_SHIFT           ((uint32)(2U))
#endif

#define FTM_FLTCTRL_FAULT1EN_MASK_U32        ((uint32)(BIT1))
#ifndef FTM_FLTCTRL_FAULT1EN_SHIFT
#define FTM_FLTCTRL_FAULT1EN_SHIFT           ((uint32)(1U))
#endif

#define FTM_FLTCTRL_FAULT0EN_MASK_U32        ((uint32)(BIT0))

/**
@{
* @brief FTMx_QDCTRL - Quadrature Decoder Control And Status - bitfield mask and shift defines.
*/
#define FTM_QDCTRL_PHAFLTREN_MASK_U32        ((uint32)(BIT7))
#ifndef FTM_QDCTRL_PHAFLTREN_SHIFT
#define FTM_QDCTRL_PHAFLTREN_SHIFT           ((uint32)(7U))
#endif

#define FTM_QDCTRL_PHBFLTREN_MASK_U32        ((uint32)(BIT6))
#ifndef FTM_QDCTRL_PHBFLTREN_SHIFT
#define FTM_QDCTRL_PHBFLTREN_SHIFT           ((uint32)(6U))
#endif

#define FTM_QDCTRL_PHAPOL_MASK_U32           ((uint32)(BIT5))
#ifndef FTM_QDCTRL_PHAPOL_SHIFT
#define FTM_QDCTRL_PHAPOL_SHIFT              ((uint32)(5U))
#endif

#define FTM_QDCTRL_PHBPOL_MASK_U32           ((uint32)(BIT4))
#ifndef FTM_QDCTRL_PHBPOL_SHIFT
#define FTM_QDCTRL_PHBPOL_SHIFT              ((uint32)(4U))
#endif

#define FTM_QDCTRL_QUADMODE_MASK_U32         ((uint32)(BIT3))
#ifndef FTM_QDCTRL_QUADMODE_SHIFT
#define FTM_QDCTRL_QUADMODE_SHIFT            ((uint32)(3U))
#endif

#define FTM_QDCTRL_QUADIR_MASK_U32           ((uint32)(BIT2))
#ifndef FTM_QDCTRL_QUADIR_SHIFT
#define FTM_QDCTRL_QUADIR_SHIFT              ((uint32)(2U))
#endif

#define FTM_QDCTRL_TOFDIR_MASK_U32           ((uint32)(BIT1))
#ifndef FTM_QDCTRL_TOFDIR_SHIFT
#define FTM_QDCTRL_TOFDIR_SHIFT              ((uint32)(1U))
#endif

#define FTM_QDCTRL_QUADEN_MASK_U32           ((uint32)(BIT0))

/**
@{
* @brief FTMx_CONF - Configuration - bitfield mask and shift defines.
*/
#define FTM_CONF_GTBEOUT_MASK_U32           ((uint32)(BIT10))
#ifndef FTM_CONF_GTBEOUT_SHIFT
#define FTM_CONF_GTBEOUT_SHIFT              ((uint32)(10U))
#endif

#define FTM_CONF_GTBEEN_MASK_U32            ((uint32)(BIT9))
#ifndef FTM_CONF_GTBEEN_SHIFT
#define FTM_CONF_GTBEEN_SHIFT               ((uint32)(9U))
#endif

#define FTM_CONF_BDMMODE_MASK_U32           ((uint32)(BIT7|BIT6))
#ifndef FTM_CONF_BDMMODE_SHIFT
#define FTM_CONF_BDMMODE_SHIFT              ((uint32)(6U))
#endif

#define FTM_CONF_NUMTOF_MASK_U32            ((uint32)(BIT4|BIT3|BIT2|BIT1|BIT0))

/**
@{
* @brief FTMx_FLTPOL - Fault Input Polarity - bitfield mask and shift defines.
*/
#define FTM_FLTPOL_FLT3POL_MASK_U32         ((uint32)(BIT3))
#ifndef FTM_FLTPOL_FLT3POL_SHIFT
#define FTM_FLTPOL_FLT3POL_SHIFT            ((uint32)(3U))
#endif

#define FTM_FLTPOL_FLT2POL_MASK_U32         ((uint32)(BIT2))
#ifndef FTM_FLTPOL_FLT2POL_SHIFT
#define FTM_FLTPOL_FLT2POL_SHIFT            ((uint32)(2U))
#endif

#define FTM_FLTPOL_FLT1POL_MASK_U32         ((uint32)(BIT1))
#ifndef FTM_FLTPOL_FLT1POL_SHIFT
#define FTM_FLTPOL_FLT1POL_SHIFT            ((uint32)(1U))
#endif

#define FTM_FLTPOL_FLT0POL_MASK_U32         ((uint32)(BIT0))

/**
@{
* @brief FTMx_SYNCONF - Synchronization Configuration - bitfield mask and shift defines.
*/
#define FTM_SYNCONF_HWSOC_MASK_U32          ((uint32)(BIT20))
#ifndef FTM_SYNCONF_HWSOC_SHIFT
#define FTM_SYNCONF_HWSOC_SHIFT             ((uint32)(20U))
#endif

#define FTM_SYNCONF_HWINVC_MASK_U32         ((uint32)(BIT19))
#ifndef FTM_SYNCONF_HWINVC_SHIFT
#define FTM_SYNCONF_HWINVC_SHIFT            ((uint32)(19U))
#endif

#define FTM_SYNCONF_HWOM_MASK_U32           ((uint32)(BIT18))
#ifndef FTM_SYNCONF_HWOM_SHIFT
#define FTM_SYNCONF_HWOM_SHIFT              ((uint32)(18U))
#endif

#define FTM_SYNCONF_HWWRBUF_MASK_U32        ((uint32)(BIT17))
#ifndef FTM_SYNCONF_HWWRBUF_SHIFT
#define FTM_SYNCONF_HWWRBUF_SHIFT           ((uint32)(17U))
#endif

#define FTM_SYNCONF_HWRSTCNT_MASK_U32       ((uint32)(BIT16))
#ifndef FTM_SYNCONF_HWRSTCNT_SHIFT
#define FTM_SYNCONF_HWRSTCNT_SHIFT          ((uint32)(16U))
#endif

#define FTM_SYNCONF_SWSOC_MASK_U32          ((uint32)(BIT12))
#ifndef FTM_SYNCONF_SWSOC_SHIFT
#define FTM_SYNCONF_SWSOC_SHIFT             ((uint32)(12U))
#endif

#define FTM_SYNCONF_SWINVC_MASK_U32         ((uint32)(BIT11))
#ifndef FTM_SYNCONF_SWINVC_SHIFT
#define FTM_SYNCONF_SWINVC_SHIFT            ((uint32)(11U))
#endif

#define FTM_SYNCONF_SWOM_MASK_U32           ((uint32)(BIT10))
#ifndef FTM_SYNCONF_SWOM_SHIFT
#define FTM_SYNCONF_SWOM_SHIFT              ((uint32)(10U))
#endif

#define FTM_SYNCONF_SWWRBUF_MASK_U32        ((uint32)(BIT9))
#ifndef FTM_SYNCONF_SWWRBUF_SHIFT
#define FTM_SYNCONF_SWWRBUF_SHIFT           ((uint32)(9U))
#endif

#define FTM_SYNCONF_SWRSTCNT_MASK_U32       ((uint32)(BIT8))
#ifndef FTM_SYNCONF_SWRSTCNT_SHIFT
#define FTM_SYNCONF_SWRSTCNT_SHIFT          ((uint32)(8U))
#endif

#define FTM_SYNCONF_SYNCMODE_MASK_U32       ((uint32)(BIT7))
#ifndef FTM_SYNCONF_SYNCMODE_SHIFT
#define FTM_SYNCONF_SYNCMODE_SHIFT          ((uint32)(7U))
#endif

#define FTM_SYNCONF_SWOC_MASK_U32           ((uint32)(BIT5))
#ifndef FTM_SYNCONF_SWOC_SHIFT
#define FTM_SYNCONF_SWOC_SHIFT              ((uint32)(5U))
#endif

#define FTM_SYNCONF_INVC_MASK_U32           ((uint32)(BIT4))
#ifndef FTM_SYNCONF_INVC_SHIFT
#define FTM_SYNCONF_INVC_SHIFT              ((uint32)(4U))
#endif

#define FTM_SYNCONF_CNTINC_MASK_U32         ((uint32)(BIT2))
#ifndef FTM_SYNCONF_CNTINC_SHIFT
#define FTM_SYNCONF_CNTINC_SHIFT            ((uint32)(2U))
#endif

#define FTM_SYNCONF_HWTRIGMODE_MASK_U32     ((uint32)(BIT0))

/**
@{
* @brief FTMx_INVCTRL - Inverting Control - bitfield mask and shift defines.
*/
#define FTM_INVCTRL_INV3EN_MASK_U32     ((uint32)(BIT3))
#ifndef FTM_INVCTRL_INV3EN_SHIFT
#define FTM_INVCTRL_INV3EN_SHIFT        ((uint32)(3U))
#endif

#define FTM_INVCTRL_INV2EN_MASK_U32     ((uint32)(BIT2))
#ifndef FTM_INVCTRL_INV2EN_SHIFT
#define FTM_INVCTRL_INV2EN_SHIFT        ((uint32)(2U))
#endif

#define FTM_INVCTRL_INV1EN_MASK_U32     ((uint32)(BIT1))
#ifndef FTM_INVCTRL_INV1EN_SHIFT
#define FTM_INVCTRL_INV1EN_SHIFT        ((uint32)(1U))
#endif

#define FTM_INVCTRL_INV0EN_MASK_U32     ((uint32)(BIT0))

/**
@{
* @brief FTMx_SWOCTRL - Software Output Control - bitfield mask and shift defines.
*/
#define FTM_SWOCTRL_CH7OCV_MASK_U32     ((uint32)(BIT15))
#ifndef FTM_SWOCTRL_CH7OCV_SHIFT
#define FTM_SWOCTRL_CH7OCV_SHIFT        ((uint32)(15U))
#endif

#define FTM_SWOCTRL_CH6OCV_MASK_U32     ((uint32)(BIT14))
#ifndef FTM_SWOCTRL_CH6OCV_SHIFT
#define FTM_SWOCTRL_CH6OCV_SHIFT        ((uint32)(14U))
#endif

#define FTM_SWOCTRL_CH5OCV_MASK_U32     ((uint32)(BIT13))
#ifndef FTM_SWOCTRL_CH5OCV_SHIFT
#define FTM_SWOCTRL_CH5OCV_SHIFT        ((uint32)(13U))
#endif

#define FTM_SWOCTRL_CH4OCV_MASK_U32     ((uint32)(BIT12))
#ifndef FTM_SWOCTRL_CH4OCV_SHIFT
#define FTM_SWOCTRL_CH4OCV_SHIFT        ((uint32)(12U))
#endif

#define FTM_SWOCTRL_CH3OCV_MASK_U32     ((uint32)(BIT11))
#ifndef FTM_SWOCTRL_CH3OCV_SHIFT
#define FTM_SWOCTRL_CH3OCV_SHIFT        ((uint32)(11U))
#endif

#define FTM_SWOCTRL_CH2OCV_MASK_U32     ((uint32)(BIT10))
#ifndef FTM_SWOCTRL_CH2OCV_SHIFT
#define FTM_SWOCTRL_CH2OCV_SHIFT        ((uint32)(10U))
#endif

#define FTM_SWOCTRL_CH1OCV_MASK_U32     ((uint32)(BIT9))
#ifndef FTM_SWOCTRL_CH1OCV_SHIFT
#define FTM_SWOCTRL_CH1OCV_SHIFT        ((uint32)(9U))
#endif

#define FTM_SWOCTRL_CH0OCV_MASK_U32     ((uint32)(BIT8))
#ifndef FTM_SWOCTRL_CH0OCV_SHIFT
#define FTM_SWOCTRL_CH0OCV_SHIFT        ((uint32)(8U))
#endif

#define FTM_SWOCTRL_CH7OC_MASK_U32      ((uint32)(BIT7))
#ifndef FTM_SWOCTRL_CH7OC_SHIFT
#define FTM_SWOCTRL_CH7OC_SHIFT         ((uint32)(7U))
#endif

#define FTM_SWOCTRL_CH6OC_MASK_U32      ((uint32)(BIT6))
#ifndef FTM_SWOCTRL_CH6OC_SHIFT
#define FTM_SWOCTRL_CH6OC_SHIFT         ((uint32)(6U))
#endif

#define FTM_SWOCTRL_CH5OC_MASK_U32      ((uint32)(BIT5))
#ifndef FTM_SWOCTRL_CH5OC_SHIFT
#define FTM_SWOCTRL_CH5OC_SHIFT         ((uint32)(5U))
#endif

#define FTM_SWOCTRL_CH4OC_MASK_U32      ((uint32)(BIT4))
#ifndef FTM_SWOCTRL_CH4OC_SHIFT
#define FTM_SWOCTRL_CH4OC_SHIFT         ((uint32)(4U))
#endif

#define FTM_SWOCTRL_CH3OC_MASK_U32      ((uint32)(BIT3))
#ifndef FTM_SWOCTRL_CH3OC_SHIFT
#define FTM_SWOCTRL_CH3OC_SHIFT         ((uint32)(3U))
#endif

#define FTM_SWOCTRL_CH2OC_MASK_U32      ((uint32)(BIT2))
#ifndef FTM_SWOCTRL_CH2OC_SHIFT
#define FTM_SWOCTRL_CH2OC_SHIFT         ((uint32)(2U))
#endif

#define FTM_SWOCTRL_CH1OC_MASK_U32      ((uint32)(BIT1))
#ifndef FTM_SWOCTRL_CH1OC_SHIFT
#define FTM_SWOCTRL_CH1OC_SHIFT         ((uint32)(1U))
#endif

#define FTM_SWOCTRL_CH0OC_MASK_U32      ((uint32)(BIT0))

/**
@{
* @brief FTMx_PWMLOAD - PWM Load - bitfield mask and shift defines.
*/
#define FTM_PWMLOAD_GLDOK_MASK_U32       ((uint32)(BIT11))
#ifndef FTM_PWMLOAD_GLDOK_SHIFT
#define FTM_PWMLOAD_GLDOK_SHIFT          ((uint32)(11U))
#endif

#define FTM_PWMLOAD_GLEN_MASK_U32       ((uint32)(BIT10))
#ifndef FTM_PWMLOAD_GLEN_SHIFT
#define FTM_PWMLOAD_GLEN_SHIFT          ((uint32)(10U))
#endif

#define FTM_PWMLOAD_LDOK_MASK_U32       ((uint32)(BIT9))
#ifndef FTM_PWMLOAD_LDOK_SHIFT
#define FTM_PWMLOAD_LDOK_SHIFT          ((uint32)(9U))
#endif

#define FTM_PWMLOAD_HCSEL_MASK_U32       ((uint32)(BIT8))
#ifndef FTM_PWMLOAD_HCSEL_SHIFT
#define FTM_PWMLOAD_HCSEL_SHIFT          ((uint32)(8U))
#endif

#define FTM_PWMLOAD_CH7SEL_MASK_U32     ((uint32)(BIT7))
#ifndef FTM_PWMLOAD_CH7SEL_SHIFT
#define FTM_PWMLOAD_CH7SEL_SHIFT        ((uint32)(7U))
#endif

#define FTM_PWMLOAD_CH6SEL_MASK_U32     ((uint32)(BIT6))
#ifndef FTM_PWMLOAD_CH6SEL_SHIFT
#define FTM_PWMLOAD_CH6SEL_SHIFT        ((uint32)(6U))
#endif

#define FTM_PWMLOAD_CH5SEL_MASK_U32     ((uint32)(BIT5))
#ifndef FTM_PWMLOAD_CH5SEL_SHIFT
#define FTM_PWMLOAD_CH5SEL_SHIFT        ((uint32)(5U))
#endif

#define FTM_PWMLOAD_CH4SEL_MASK_U32     ((uint32)(BIT4))
#ifndef FTM_PWMLOAD_CH4SEL_SHIFT
#define FTM_PWMLOAD_CH4SEL_SHIFT        ((uint32)(4U))
#endif

#define FTM_PWMLOAD_CH3SEL_MASK_U32     ((uint32)(BIT3))
#ifndef FTM_PWMLOAD_CH3SEL_SHIFT
#define FTM_PWMLOAD_CH3SEL_SHIFT        ((uint32)(3U))
#endif

#define FTM_PWMLOAD_CH2SEL_MASK_U32     ((uint32)(BIT2))
#ifndef FTM_PWMLOAD_CH2SEL_SHIFT
#define FTM_PWMLOAD_CH2SEL_SHIFT        ((uint32)(2U))
#endif

#define FTM_PWMLOAD_CH1SEL_MASK_U32     ((uint32)(BIT1))
#ifndef FTM_PWMLOAD_CH1SEL_SHIFT
#define FTM_PWMLOAD_CH1SEL_SHIFT        ((uint32)(1U))
#endif

#define FTM_PWMLOAD_CH0SEL_MASK_U32     ((uint32)(BIT0))

/** Bitfield defines. */
/**
* @{
* @brief FTMx_CnSC - bitfield defines.
*/
#define FTM_CSC_CHF_NO_EVENT_U32         ((uint32)(0U))
#define FTM_CSC_CHF_EVENT_OCCURED_U32    ((uint32)(1U) << FTM_CSC_CHF_SHIFT)
#define FTM_CSC_CHIE_DISABLE_U32         ((uint32)(0U))
#define FTM_CSC_CHIE_ENABLE_U32          ((uint32)(1U) << FTM_CSC_CHIE_SHIFT )

#define FTM_CSC_MSX_PWMFORM_U32          ((uint32)(1U) << FTM_CSC_MSB_SHIFT )

#define FTM_CSC_ELSX_PWMFORM_U32         ((uint32)(1U) << FTM_CSC_ELSB_SHIFT )

#define FTM_CSC_DMA_DISABLE_U32          ((uint32)(0U))
#define FTM_CSC_DMA_ENABLE_U32           ((uint32)(1U))

/**
* @{
* @brief FTMx_SC - bitfield defines.
*/
#define FTM_SC_TOF_NO_OVF_U32                ((uint32)(0U) << FTM_SC_TOF_SHIFT) 
#define FTM_SC_TOF_OVF_U32                   ((uint32)(1U) << FTM_SC_TOF_SHIFT)
#define FTM_SC_TOIE_DISABLE_U32              ((uint32)(0U) << FTM_SC_TOIE_SHIFT)
#define FTM_SC_TOIE_ENABLE_U32               ((uint32)(1U) << FTM_SC_TOIE_SHIFT)
#define FTM_SC_RF_NO_RIF_U32                 ((uint32)(0U) << FTM_SC_RF_SHIFT) 
#define FTM_SC_RF_RIF_U32                    ((uint32)(1U) << FTM_SC_RF_SHIFT)
#define FTM_SC_RIE_DISABLE_U32               ((uint32)(0U) << FTM_SC_RIE_SHIFT)
#define FTM_SC_RIE_ENABLE_U32                ((uint32)(1U) << FTM_SC_RIE_SHIFT)
#define FTM_SC_CPWMS_UP_COUNTING_U32         ((uint32)(0U) << FTM_SC_CPWMS_SHIFT)
#define FTM_SC_CPWMS_UP_DOWN_COUNTING_U32    ((uint32)(1U) << FTM_SC_CPWMS_SHIFT)
#define FTM_SC_CLKS_NO_CLOCKS_U32            ((uint32)(0U) << FTM_SC_CLKS_SHIFT)
#define FTM_SC_CLKS_SYS_CLOCK_U32            ((uint32)(1U) << FTM_SC_CLKS_SHIFT)
#define FTM_SC_CLKS_FIXED_FREQ_CLOCK_U32     ((uint32)(2U) << FTM_SC_CLKS_SHIFT)
#define FTM_SC_CLKS_EXTERNAL_CLOCK_U32       ((uint32)(3U) << FTM_SC_CLKS_SHIFT)
#define FTM_SC_PS_DIV1_U32                   ((uint32)(0U))
#define FTM_SC_PS_DIV2_U32                   ((uint32)(1U))
#define FTM_SC_PS_DIV4_U32                   ((uint32)(2U))
#define FTM_SC_PS_DIV8_U32                   ((uint32)(3U))
#define FTM_SC_PS_DIV16_U32                  ((uint32)(4U))
#define FTM_SC_PS_DIV32_U32                  ((uint32)(5U))
#define FTM_SC_PS_DIV64_U32                  ((uint32)(6U))
#define FTM_SC_PS_DIV128_U32                 ((uint32)(7U))
#define FTM_SC_PWMOUTPUTEN_SHIFT             ((uint32)(16U))

/**
* @{
* @brief FTMx_MODE - bitfield defines.
*/
#define FTM_MODE_FAULTIE_DISABLE_U32        ((uint32)(0U))
#define FTM_MODE_FAULTIE_ENABLE_U32         ((uint32)(1U) << FTM_MODE_FAULTIE_SHIFT)
#define FTM_MODE_FAULTM_DISABLED_U32        ((uint32)(0U))
#define FTM_MODE_FAULTM_ENABLE_EVEN_U32     ((uint32)(1U) << FTM_MODE_FAULTM_SHIFT)
#define FTM_MODE_FAULTM_ENABLED_MANUAL_U32  ((uint32)(2U) << FTM_MODE_FAULTM_SHIFT)
#define FTM_MODE_FAULTM_ENABLED_AUTO_U32    ((uint32)(3U) << FTM_MODE_FAULTM_SHIFT)
#define FTM_MODE_CAPTEST_DISABLE_U32        ((uint32)(0U))
#define FTM_MODE_CAPTEST_ENABLE_U32         ((uint32)(1U) << FTM_MODE_CAPTEST_SHIFT)

#define FTM_MODE_PWMSYNC_ENABLE_U32         ((uint32)(1U) << FTM_MODE_PWMSYNC_SHIFT)
#define FTM_MODE_PWMSYNC_DISABLE_U32        ((uint32)(0U))

#define FTM_MODE_WPDIS_ENABLE_U32           ((uint32)(0U)) 
#define FTM_MODE_WPDIS_DISABLE_U32          ((uint32)(1U) << FTM_MODE_WPDIS_SHIFT)

#define FTM_MODE_INIT_ENABLE_U32            ((uint32)(1U) << FTM_MODE_INIT_SHIFT) 
#define FTM_MODE_INIT_DISABLE_U32           ((uint32)(0U))

#define FTM_MODE_FTMEN_ENABLE_U32           ((uint32)(1U)) 
#define FTM_MODE_FTMEN_DISABLE_U32          ((uint32)(0U))

/**
* @{
* @brief FTMx_SYNC - bitfield defines.
*/
#define FTM_SYNC_SWSYNC_SELECTED_U32        ((uint32)(1U))
#define FTM_SYNC_SWSYNC_NOT_SELECTED_U32    ((uint32)(0U))
#define FTM_SYNC_TRIG2_DISABLE_U32          ((uint32)(0U))
#define FTM_SYNC_TRIG2_ENABLE_U32           ((uint32)(1U))
#define FTM_SYNC_TRIG1_DISABLE_U32          ((uint32)(0U))
#define FTM_SYNC_TRIG1_ENABLE_U32           ((uint32)(1U))
#define FTM_SYNC_TRIG0_DISABLE_U32          ((uint32)(0U))
#define FTM_SYNC_TRIG0_ENABLE_U32           ((uint32)(1U))
#define FTM_SYNC_SYNCHOM_RISING_EDGE_U32    ((uint32)(0U))
#define FTM_SYNC_SYNCHOM_SYNC_U32           ((uint32)(1U))

#define FTM_SYNC_REINIT_DISABLE_U32         ((uint32)(0U))
#define FTM_SYNC_REINIT_ENABLE_U32          ((uint32)(1U))

#define FTM_SYNC_CNTMAX_DISABLE_U32         ((uint32)(0U))
#define FTM_SYNC_CNTMAX_ENABLE_U32          ((uint32)(1U))
#define FTM_SYNC_CNTMIN_DISABLE_U32         ((uint32)(0U))
#define FTM_SYNC_CNTMIN_ENABLE_U32          ((uint32)(1U))

/**
* @{
* @brief FTMx_COMBINE - bitfield defines.
*/
#define FTM_COMBINE_MCOMBINE3_DISABLE_U32    ((uint32)(0U))
#define FTM_COMBINE_MCOMBINE3_ENABLE_U32     ((uint32)(1U) << FTM_COMBINE_MCOMBINE3_SHIFT)
#define FTM_COMBINE_FAULTEN3_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_FAULTEN3_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_FAULTEN3_SHIFT)
#define FTM_COMBINE_SYNCEN3_DISABLE_U32      ((uint32)(0U))
#define FTM_COMBINE_SYNCEN3_ENABLE_U32       ((uint32)(1U) << FTM_COMBINE_SYNCEN3_SHIFT)
#define FTM_COMBINE_DTEN3_DISABLE_U32        ((uint32)(0U)) 
#define FTM_COMBINE_DTEN3_ENABLE_U32         ((uint32)(1U) << FTM_COMBINE_DTEN3_SHIFT)
#define FTM_COMBINE_DECAP3_INACTIVE_U32      ((uint32)(0U))
#define FTM_COMBINE_DECAP3_ACTIVE_U32        ((uint32)(1U) << FTM_COMBINE_DECAP3_SHIFT)
#define FTM_COMBINE_COMP3_SAME_U32           ((uint32)(0U))
#define FTM_COMBINE_COMP3_COMPLEMENT_U32     ((uint32)(1U) << FTM_COMBINE_COMP3_SHIFT)
#define FTM_COMBINE_COMBINE3_INDEPENDENT_U32 ((uint32)(0U))
#define FTM_COMBINE_COMBINE3_COMBINED_U32    ((uint32)(1U)  << FTM_COMBINE_COMBINE3_SHIFT)

#define FTM_COMBINE_MCOMBINE2_DISABLE_U32    ((uint32)(0U))
#define FTM_COMBINE_MCOMBINE2_ENABLE_U32     ((uint32)(1U) << FTM_COMBINE_MCOMBINE2_SHIFT)
#define FTM_COMBINE_FAULTEN2_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_FAULTEN2_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_FAULTEN2_SHIFT)
#define FTM_COMBINE_SYNCEN2_DISABLE_U32      ((uint32)(0U))
#define FTM_COMBINE_SYNCEN2_ENABLE_U32       ((uint32)(1U) << FTM_COMBINE_SYNCEN2_SHIFT)
#define FTM_COMBINE_DTEN2_DISABLE_U32        ((uint32)(0U))
#define FTM_COMBINE_DTEN2_ENABLE_U32         ((uint32)(1U) << FTM_COMBINE_DTEN2_SHIFT)
#define FTM_COMBINE_DECAP2_INACTIVE_U32      ((uint32)(0U))
#define FTM_COMBINE_DECAP2_ACTIVE_U32        ((uint32)(1U) << FTM_COMBINE_DECAP2_SHIFT)
#define FTM_COMBINE_COMP2_SAME_U32           ((uint32)(0U))
#define FTM_COMBINE_COMP2_COMPLEMENT_U32     ((uint32)(1U)  << FTM_COMBINE_COMP2_SHIFT)
#define FTM_COMBINE_COMBINE2_INDEPENDENT_U32 ((uint32)(0U))
#define FTM_COMBINE_COMBINE2_COMBINED_U32    ((uint32)(1U) << FTM_COMBINE_COMBINE2_SHIFT)

#define FTM_COMBINE_MCOMBINE1_DISABLE_U32    ((uint32)(0U))
#define FTM_COMBINE_MCOMBINE1_ENABLE_U32     ((uint32)(1U) << FTM_COMBINE_MCOMBINE1_SHIFT)
#define FTM_COMBINE_FAULTEN1_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_FAULTEN1_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_FAULTEN1_SHIFT)
#define FTM_COMBINE_SYNCEN1_DISABLE_U32      ((uint32)(0U))
#define FTM_COMBINE_SYNCEN1_ENABLE_U32       ((uint32)(1U) << FTM_COMBINE_SYNCEN1_SHIFT)
#define FTM_COMBINE_DTEN1_DISABLE_U32        ((uint32)(0U))
#define FTM_COMBINE_DTEN1_ENABLE_U32         ((uint32)(1U) << FTM_COMBINE_DTEN1_SHIFT)
#define FTM_COMBINE_DECAP1_INACTIVE_U32      ((uint32)(0U))
#define FTM_COMBINE_DECAP1_ACTIVE_U32        ((uint32)(1U) << FTM_COMBINE_DECAP1_SHIFT)
#define FTM_COMBINE_COMP1_SAME_U32           ((uint32)(0U))
#define FTM_COMBINE_COMP1_COMPLEMENT_U32     (((uint32)(1U)) << FTM_COMBINE_COMP1_SHIFT)
#define FTM_COMBINE_COMBINE1_INDEPENDENT_U32 ((uint32)(0U))
#define FTM_COMBINE_COMBINE1_COMBINED_U32    ((uint32)(1U) << FTM_COMBINE_COMBINE1_SHIFT)

#define FTM_COMBINE_MCOMBINE0_DISABLE_U32    ((uint32)(0U))
#define FTM_COMBINE_MCOMBINE0_ENABLE_U32     ((uint32)(1U) << FTM_COMBINE_MCOMBINE0_SHIFT)
#define FTM_COMBINE_FAULTEN0_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_FAULTEN0_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_FAULTEN0_SHIFT)
#define FTM_COMBINE_SYNCEN0_DISABLE_U32      ((uint32)(0U))
#define FTM_COMBINE_SYNCEN0_ENABLE_U32       ((uint32)(1U) << FTM_COMBINE_SYNCEN0_SHIFT)
#define FTM_COMBINE_DTEN0_DISABLE_U32        ((uint32)(0U))
#define FTM_COMBINE_DTEN0_ENABLE_U32         ((uint32)(1U) << FTM_COMBINE_DTEN0_SHIFT)
#define FTM_COMBINE_DECAP0_INACTIVE_U32      ((uint32)(0U))
#define FTM_COMBINE_DECAP0_ACTIVE_U32        ((uint32)(1U) << FTM_COMBINE_DECAP0_SHIFT)
#define FTM_COMBINE_COMP0_SAME_U32           ((uint32)(0U))
#define FTM_COMBINE_COMP0_COMPLEMENT_U32     ((uint32)(1U) << FTM_COMBINE_COMP0_SHIFT)
#define FTM_COMBINE_COMBINE0_INDEPENDENT_U32 ((uint32)(0U))
#define FTM_COMBINE_COMBINE0_COMBINED_U32    ((uint32)(1U))

/**
* @{
* @brief FTMx_DEADTIME - bitfield defines.
*/
#define FTM_DEADTIME_DTPS_DIV1_U32          ((uint32)(0U)) 
#define FTM_DEADTIME_DTPS_DIV4_U32          (((uint32)(2U)) << FTM_DEADTIME_DTPS_SHIFT)
#define FTM_DEADTIME_DTPS_DIV16_U32         (((uint32)(3U)) << FTM_DEADTIME_DTPS_SHIFT)

/**
* @{
* @brief FTMx_EXTTRIG - bitfield defines.
*/
#define FTM_EXTTRIG_TRIGF_TRIGGER_U32       ((uint32)(1U))
#define FTM_EXTTRIG_TRIGF_NO_TRIGGER_U32    ((uint32)(0U))
#define FTM_EXTTRIG_INITTRIGEN_ENABLE_U32   ((uint32)(1U))
#define FTM_EXTTRIG_INITTRIGEN_DISABLE_U32  ((uint32)(0U))
#define FTM_EXTTRIG_CH1TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH1TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH0TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH0TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH5TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH5TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH4TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH4TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH3TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH3TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH2TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH2TRIG_ENABLE_U32      ((uint32)(1U))

/**
* @{
* @brief FTMx_POL - bitfield defines.
*/
#define FTM_POL_POL7_LOW_U32            ((uint32)(1U) << FTM_POL_POL7_SHIFT)
#define FTM_POL_POL7_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL6_LOW_U32            ((uint32)(1U) << FTM_POL_POL6_SHIFT)
#define FTM_POL_POL6_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL5_LOW_U32            ((uint32)(1U) << FTM_POL_POL5_SHIFT)
#define FTM_POL_POL5_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL4_LOW_U32            ((uint32)(1U) << FTM_POL_POL4_SHIFT)
#define FTM_POL_POL4_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL3_LOW_U32            ((uint32)(1U) << FTM_POL_POL3_SHIFT)
#define FTM_POL_POL3_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL2_LOW_U32            ((uint32)(1U) << FTM_POL_POL2_SHIFT)
#define FTM_POL_POL2_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL1_LOW_U32            ((uint32)(1U) << FTM_POL_POL1_SHIFT)
#define FTM_POL_POL1_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL0_LOW_U32            ((uint32)(1U))
#define FTM_POL_POL0_HIGH_U32           ((uint32)(0U))

/**
* @{
* @brief FTMx_FMS - bitfield defines.
*/
#define FTM_FMS_FAULTF_FAULT_U32            ((uint32)(1U) << FTM_FMS_FAULTF_SHIFT)
#define FTM_FMS_FAULTF_NO_FAULT_U32         ((uint32)(0U))
#define FTM_FMS_WPEN_ENABLE_U32             (((uint32)(1U)) << FTM_FMS_WPEN_SHIFT)
#define FTM_FMS_WPEN_DISABLE_U32            ((uint32)(0U))
#define FTM_FMS_FAULTIN_LOGIC_OR_IS_0_U32   ((uint32)(0U)) /*TO DO: check again*/
#define FTM_FMS_FAULTIN_LOGIC_OR_IS_1_U32   ((uint32)(1U) << FTM_FMS_FAULTIN_SHIFT)
#define FTM_FMS_FAULTF3_FAULT_U32           ((uint32)(1U) << FTM_FMS_FAULTF3_SHIFT)
#define FTM_FMS_FAULTF3_NO_FAULT_U32        ((uint32)(0U))  
#define FTM_FMS_FAULTF2_FAULT_U32           ((uint32)(1U) << FTM_FMS_FAULTF2_SHIFT)
#define FTM_FMS_FAULTF2_NO_FAULT_U32        ((uint32)(0U))  
#define FTM_FMS_FAULTF1_FAULT_U32           ((uint32)(1U) << FTM_FMS_FAULTF1_SHIFT)
#define FTM_FMS_FAULTF1_NO_FAULT_U32        ((uint32)(0U))  
#define FTM_FMS_FAULTF0_FAULT_U32           ((uint32)(1U))
#define FTM_FMS_FAULTF0_NO_FAULT_U32        ((uint32)(0U))  

/**
* @{
* @brief FTMx_FLTCTRL - bitfield defines.
*/
#define FTM_FLTCTRL_FLTSTATE_SAFEVALUE_U32  ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR3EN_TRISTATE_U32   ((uint32)(1U) << FTM_FLTCTRL_FSTATE_SHIFT)
#define FTM_FLTCTRL_FFVAL_U32(value)        (((uint32)(value)) << FTM_FLTCTRL_FFVAL_SHIFT)
#define FTM_FLTCTRL_FFLTR3EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR3EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FFLTR3EN_SHIFT)
#define FTM_FLTCTRL_FFLTR2EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR2EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FFLTR2EN_SHIFT)
#define FTM_FLTCTRL_FFLTR1EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR1EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FFLTR1EN_SHIFT)
#define FTM_FLTCTRL_FFLTR0EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR0EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FFLTR0EN_SHIFT)
#define FTM_FLTCTRL_FAULT3EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FAULT3EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FAULT3EN_SHIFT)
#define FTM_FLTCTRL_FAULT2EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FAULT2EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FAULT2EN_SHIFT)
#define FTM_FLTCTRL_FAULT1EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FAULT1EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FAULT1EN_SHIFT)
#define FTM_FLTCTRL_FAULT0EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FAULT0EN_ENABLE_U32     ((uint32)(1U))

/**
* @{
* @brief FTMx_QDCTRL - bitfield defines.
*/
#define FTM_QDCTRL_PHAFLTREN_ENABLE_U32     ((uint32)(1U))
#define FTM_QDCTRL_PHAFLTREN_DISABLE_U32    ((uint32)(0U))
#define FTM_QDCTRL_PHBFLTREN_ENABLE_U32     ((uint32)(1U))
#define FTM_QDCTRL_PHBFLTREN_DISABLE_U32    ((uint32)(0U))
#define FTM_QDCTRL_PHAPOL_NORMAL_U32        ((uint32)(0U))
#define FTM_QDCTRL_PHAPOL_INVERTED_U32      ((uint32)(1U))
#define FTM_QDCTRL_PHBPOL_NORMAL_U32        ((uint32)(0U))
#define FTM_QDCTRL_PHBPOL_INVERTED_U32      ((uint32)(1U))
#define FTM_QDCTRL_PHA_PHB_MODE_U32         ((uint32)(0U))
#define FTM_QDCTRL_COUNT_DIRECTION_MODE_U32 ((uint32)(1U))
#define FTM_QDCTRL_QUADIR_DECREMENT_U32     ((uint32)(0U))
#define FTM_QDCTRL_QUADIR_INCREMENT_U32     ((uint32)(1U))
#define FTM_QDCTRL_TOFDIR_BOTTOM_U32        ((uint32)(0U))
#define FTM_QDCTRL_TOFDIR_TOP_U32           ((uint32)(1U))
#define FTM_QDCTRL_QUADEN_DISABLE_U32       ((uint32)(0U))
#define FTM_QDCTRL_QUADEN_ENABLE_U32        ((uint32)(1U))

/**
* @{
* @brief FTMx_CONF - bitfield defines.
*/
#define FTM_CONF_GTBEOUT_ENABLE_U32         (((uint32)(1U)) << FTM_CONF_GTBEOUT_SHIFT)
#define FTM_CONF_GTBEOUT_DISABLE_U32        ((uint32)(0U))
#define FTM_CONF_GTBEN_ENABLE_U32           (((uint32)(1U)) << FTM_CONF_GTBEN_SHIFT)
#define FTM_CONF_GTBEEN_DISABLE_U32         ((uint32)(0U))
#define FTM_CONF_BDMMODE_ALLSTOP_U32        ((uint32)(0U))
#define FTM_CONF_BDMMODE_OUTPUTSSAFE_U32    ((uint32)(1U) <<  FTM_CONF_BDMMODE_SHIFT)
#define FTM_CONF_BDMMODE_OUTPUTSRUN_U32     ((uint32)(2U) <<  FTM_CONF_BDMMODE_SHIFT)
#define FTM_CONF_BDMMODE_ALLRUN_U32         ((uint32)(3U) <<  FTM_CONF_BDMMODE_SHIFT)

/**
* @{
* @brief FTMx_FLTPOL - bitfield defines.
*/
#define FTM_FLTPOL_FLT3POL_LOW_U32      ((uint32)(0U))
#define FTM_FLTPOL_FLT3POL_HIGH_U32     (((uint32)(1U)) << FTM_FLTPOL_FLT3POL_SHIFT)
#define FTM_FLTPOL_FLT2POL_LOW_U32      ((uint32)(0U))
#define FTM_FLTPOL_FLT2POL_HIGH_U32     (((uint32)(1U)) << FTM_FLTPOL_FLT2POL_SHIFT)
#define FTM_FLTPOL_FLT1POL_LOW_U32      ((uint32)(0U))
#define FTM_FLTPOL_FLT1POL_HIGH_U32     (((uint32)(1U)) << FTM_FLTPOL_FLT1POL_SHIFT)
#define FTM_FLTPOL_FLT0POL_LOW_U32      ((uint32)(0U))
#define FTM_FLTPOL_FLT0POL_HIGH_U32     ((uint32)(1U))


/**
* @{
* @brief FTMx_SYNCONF - bitfield defines.
*/


/**
* @{
* @brief FTMx_INVCTRL - bitfield defines.
*/
#define FTM_INVCTRL_INV3EN_DISABLE_U32      ((uint32)(0U))
#define FTM_INVCTRL_INV3EN_ENABLE_U32       (((uint32)(1U)) << FTM_INVCTRL_INV3EN_SHIFT)
#define FTM_INVCTRL_INV2EN_DISABLE_U32      ((uint32)(0U))
#define FTM_INVCTRL_INV2EN_ENABLE_U32       (((uint32)(1U)) << FTM_INVCTRL_INV2EN_SHIFT)
#define FTM_INVCTRL_INV1EN_DISABLE_U32      ((uint32)(0U))
#define FTM_INVCTRL_INV1EN_ENABLE_U32       (((uint32)(1U)) << FTM_INVCTRL_INV1EN_SHIFT)
#define FTM_INVCTRL_INV0EN_DISABLE_U32      ((uint32)(0U))
#define FTM_INVCTRL_INV0EN_ENABLE_U32       ((uint32)(1U))

/**
* @{
* @brief FTMx_SWOCTRL - bitfield defines.
*/
#define FTM_SWOCTRL_CH7OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH7OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH7OCV_SHIFT)
#define FTM_SWOCTRL_CH6OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH6OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH6OCV_SHIFT)
#define FTM_SWOCTRL_CH5OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH5OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH5OCV_SHIFT)
#define FTM_SWOCTRL_CH4OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH4OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH4OCV_SHIFT)
#define FTM_SWOCTRL_CH3OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH3OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH3OCV_SHIFT)
#define FTM_SWOCTRL_CH2OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH2OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH2OCV_SHIFT)
#define FTM_SWOCTRL_CH1OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH1OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH1OCV_SHIFT)
#define FTM_SWOCTRL_CH0OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH0OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH0OCV_SHIFT)

#define FTM_SWOCTRL_CH7OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH7OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH7OC_SHIFT)
#define FTM_SWOCTRL_CH6OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH6OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH6OC_SHIFT)
#define FTM_SWOCTRL_CH5OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH5OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH5OC_SHIFT)
#define FTM_SWOCTRL_CH4OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH4OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH4OC_SHIFT)
#define FTM_SWOCTRL_CH3OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH3OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH3OC_SHIFT)
#define FTM_SWOCTRL_CH2OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH2OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH2OC_SHIFT)
#define FTM_SWOCTRL_CH1OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH1OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH1OC_SHIFT)
#define FTM_SWOCTRL_CH0OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH0OC_ENABLE_U32        ((uint32)(1U))

/**
* @{
* @brief FTMx_PWMLOAD - bitfield defines.
*/
#define FTM_PWMLOAD_LDOK_DISABLE_U32       	((uint32)(0U))
#define FTM_PWMLOAD_LDOK_ENABLE_U32        	(((uint32)(1U)) << FTM_PWMLOAD_LDOK_SHIFT)
#define FTM_PWMLOAD_CH7SEL_DISABLE_U32     	((uint32)(0U))
#define FTM_PWMLOAD_CH7SEL_ENABLE_U32      	(((uint32)(1U)) << FTM_PWMLOAD_CH7SEL_SHIFT)
#define FTM_PWMLOAD_CH6SEL_DISABLE_U32     	((uint32)(0U))
#define FTM_PWMLOAD_CH6SEL_ENABLE_U32      	(((uint32)(1U)) << FTM_PWMLOAD_CH6SEL_SHIFT)
#define FTM_PWMLOAD_CH5SEL_DISABLE_U32     	((uint32)(0U))
#define FTM_PWMLOAD_CH5SEL_ENABLE_U32      	(((uint32)(1U)) << FTM_PWMLOAD_CH5SEL_SHIFT)
#define FTM_PWMLOAD_CH4SEL_DISABLE_U32     	((uint32)(0U))
#define FTM_PWMLOAD_CH4SEL_ENABLE_U32      	(((uint32)(1U)) << FTM_PWMLOAD_CH4SEL_SHIFT)
#define FTM_PWMLOAD_CH3SEL_DISABLE_U32     	((uint32)(0U))
#define FTM_PWMLOAD_CH3SEL_ENABLE_U32      	(((uint32)(1U)) << FTM_PWMLOAD_CH3SEL_SHIFT)
#define FTM_PWMLOAD_CH2SEL_DISABLE_U32     	((uint32)(0U))
#define FTM_PWMLOAD_CH2SEL_ENABLE_U32      	(((uint32)(1U)) << FTM_PWMLOAD_CH2SEL_SHIFT)
#define FTM_PWMLOAD_CH1SEL_DISABLE_U32     	((uint32)(0U))
#define FTM_PWMLOAD_CH1SEL_ENABLE_U32      	(((uint32)(1U)) << FTM_PWMLOAD_CH1SEL_SHIFT)
#define FTM_PWMLOAD_CH0SEL_DISABLE_U32     	((uint32)(0U))
#define FTM_PWMLOAD_CH0SEL_ENABLE_U32      	((uint32)(1U))

/**
* @{
* @brief FTMx_MOD_MIRROR - bitfield defines.
*/
#define FTM_MOD_MIRROR_FRACMOD_MASK_U32 	((uint32)(BIT15|BIT14|BIT13|BIT12|BIT11))
#ifndef FTM_MOD_MIRROR_FRACMOD_SHIFT
#define FTM_MOD_MIRROR_FRACMOD_SHIFT     	((uint32)(11U))
#endif

/**
* @{
* @brief FTMx_CV_MIRROR - bitfield defines.
*/
#define FTM_CV_MIRROR_FRACVAL_MASK_U32     	((uint32)(BIT15|BIT14|BIT13|BIT12|BIT11))
#ifndef FTM_CV_MIRROR_FRACVAL_SHIFT
#define FTM_CV_MIRROR_FRACVAL_SHIFT    		((uint32)(11U))
#endif

#define FTM0        		                    (0U)
#define FTM1        		                    (1U)
#define FTM2        		                    (2U)
#define FTM3        		                    (3U)
#define FTM4        		                    (4U)
#define FTM5       		 	                    (5U)
                    
#define FTM0_CH0    		                    (0U)
#define FTM0_CH1    		                    (1U)
#define FTM0_CH2    		                    (2U)
#define FTM0_CH3    		                    (3U)
#define FTM0_CH4    		                    (4U)
#define FTM0_CH5    		                    (5U)
#define FTM0_CH6    		                    (6U)
#define FTM0_CH7    		                    (7U)
#define FTM1_CH0    		                    (8U)
#define FTM1_CH1    		                    (9U)
#define FTM1_CH2    		                    (10U)
#define FTM1_CH3    		                    (11U)
#define FTM1_CH4    		                    (12U)
#define FTM1_CH5    		                    (13U)
#define FTM1_CH6    		                    (14U)
#define FTM1_CH7    		                    (15U)
#define FTM2_CH0    		                    (16U)
#define FTM2_CH1    		                    (17U)
#define FTM2_CH2    		                    (18U)
#define FTM2_CH3    		                    (19U)
#define FTM2_CH4    		                    (20U)
#define FTM2_CH5    		                    (21U)
#define FTM2_CH6    		                    (22U)
#define FTM2_CH7    		                    (23U)
#define FTM3_CH0    		                    (24U)
#define FTM3_CH1    		                    (25U)
#define FTM3_CH2    		                    (26U)
#define FTM3_CH3    		                    (27U)
#define FTM3_CH4    		                    (28U)
#define FTM3_CH5    		                    (29U)
#define FTM3_CH6    		                    (30U)
#define FTM3_CH7    		                    (31U)
#define FTM4_CH0    		                    (32U)
#define FTM4_CH1    		                    (33U)
#define FTM4_CH2    		                    (34U)
#define FTM4_CH3    		                    (35U)
#define FTM4_CH4    		                    (36U)
#define FTM4_CH5    		                    (37U)
#define FTM4_CH6    		                    (38U)
#define FTM4_CH7    		                    (39U)
#define FTM5_CH0    		                    (40U)
#define FTM5_CH1    		                    (41U)
#define FTM5_CH2    		                    (42U)
#define FTM5_CH3    		                    (43U)
#define FTM5_CH4    		                    (44U)
#define FTM5_CH5    		                    (45U)
#define FTM5_CH6    		                    (46U)
#define FTM5_CH7    		                    (47U)

#define FTM0_CHx                                (0U)
#define FTM1_CHx                                (8U)
#define FTM2_CHx                                (16U)
#define FTM3_CHx                                (24U)
#define FTM4_CHx                                (32U)
#define FTM5_CHx                                (40U)

#define FTM_CHANNEL_NUMBER						(8U)
#define FTM_MODULE_NUMBER						(6U)
#define FTM_HARDWARECHANNEL_NUMBER				(48U)

#define FTM_COUNT_MAX                           (65535U)

#define GET_FTM_MODULE(FtmHardwareChannel)		((FtmHardwareChannel) >> 3)
#define GET_FTM_CHANNEL(FtmHardwareChannel)		((FtmHardwareChannel) & 0x07)

#ifdef FTM_GLOBAL

#ifdef GPT_FTM_GLOBAL
#define GPT_START_SEC_VAR_INIT_PTR
#include "Gpt_MemMap.h"
TT_FTM_Type *Ftm_PubReg[FTM_MODULE_NUMBER] = TT_FTM_BASE_PTRS;
#define GPT_STOP_SEC_VAR_INIT_PTR
#include "Gpt_MemMap.h"
#endif

#ifdef ICU_FTM_GLOBAL
#define ICU_START_SEC_VAR_INIT_PTR
#include "Icu_MemMap.h"
TT_FTM_Type *Ftm_PubReg[FTM_MODULE_NUMBER] = TT_FTM_BASE_PTRS;
#define ICU_STOP_SEC_VAR_INIT_PTR
#include "Icu_MemMap.h"
#endif

#ifdef OCU_FTM_GLOBAL
#define OCU_START_SEC_VAR_INIT_PTR
#include "Ocu_MemMap.h"
TT_FTM_Type *Ftm_PubReg[FTM_MODULE_NUMBER] = TT_FTM_BASE_PTRS;
#define OCU_STOP_SEC_VAR_INIT_PTR
#include "Ocu_MemMap.h"
#endif

#else
extern TT_FTM_Type *Ftm_PubReg[FTM_MODULE_NUMBER];
#endif

#ifdef __cplusplus
}
#endif

#endif
