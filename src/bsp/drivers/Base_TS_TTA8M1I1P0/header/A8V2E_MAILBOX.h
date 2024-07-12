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
#ifndef A8V2E_MAILBOX_H
#define A8V2E_MAILBOX_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_MAILBOX_VENDOR_ID_H                     1541
#define A8V2E_MAILBOX_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_MAILBOX_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_MAILBOX_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_MAILBOX_SW_MAJOR_VERSION_H              1
#define A8V2E_MAILBOX_SW_MINOR_VERSION_H              1
#define A8V2E_MAILBOX_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_MAILBOX.h and TT_Common.h file version check */
#if (A8V2E_MAILBOX_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_MAILBOX.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_MAILBOX_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_MAILBOX_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_MAILBOX_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_MAILBOX.h and TT_Common.h are different"
#endif
#if ((A8V2E_MAILBOX_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_MAILBOX_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_MAILBOX_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_MAILBOX.h and TT_Common.h are different"
#endif


/* =========================================================================================================================== */
/* ================                                      TT_MAILBOX                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief External mailbox Device (TT_MAILBOX)
  */

typedef struct {                                /*!< (@ 0x40050000) TT_MAILBOX Structure                                   */
  __OM  uint32_t  SET;                          /*!< (@ 0x00000000) SET Register                                               */
  __IM  uint32_t  RESERVED;
  __OM  uint32_t  CLEAR;                        /*!< (@ 0x00000008) CLEAR Register                                             */
  __IM  uint32_t  RESERVED1;
  __IM  uint32_t  STATUS;                       /*!< (@ 0x00000010) STATUS Register                                            */
  __IM  uint32_t  RESERVED2[7];
  __IM  uint32_t  HSM_STATUS;                   /*!< (@ 0x00000030) HSM STATUS Register                                        */
  __IM  uint32_t  RESERVED3[51];
  __IOM uint32_t  AP_RW_SHARE0;                 /*!< (@ 0x00000100) HSM read only Register0                                    */
  __IM  uint32_t  RESERVED4;
  __IOM uint32_t  AP_RW_SHARE1;                 /*!< (@ 0x00000108) HSM read only Register1                                    */
  __IM  uint32_t  RESERVED5;
  __IM  uint32_t  AP_RO_SHARE0;                 /*!< (@ 0x00000110) HSM read write Register0                                   */
  __IM  uint32_t  RESERVED6;
  __IM  uint32_t  AP_RO_SHARE1;                 /*!< (@ 0x00000118) HSM read write Register1                                   */
  __IM  uint32_t  RESERVED7[9];
  __IM  uint32_t  ID;                           /*!< (@ 0x00000140) mailbox ID Register                                        */
} MAILBOX_Type, *MAILBOX_MemMapPtr;                          /*!< Size = 324 (0x144)                                                        */

#define TT_MAILBOX_BASE         0x40050000UL
#define TT_MAILBOX              ((MAILBOX_Type*)    TT_MAILBOX_BASE)

#define TT_MAILBOX_SRAM_BASE		((uint8 *)0x40051000UL)
#define TT_MAILBOX_SRAM_SIZE			(4096)
#define MAILBOX_SLOT_MAX_NUM			(32)

/* =========================================================================================================================== */
/* ================                                      TT_MAILBOX                                       ================ */
/* =========================================================================================================================== */

/* ==========================================================  SET  ========================================================== */
/* =========================================================  CLEAR  ========================================================= */
/* ========================================================  STATUS  ========================================================= */
/* ======================================================  HSM_STATUS  ======================================================= */
/* =====================================================  AP_RW_SHARE0  ====================================================== */
#define TT_MAILBOX_AP_RW_SHARE0_updateFlag_Pos (0UL)            /*!< TT_MAILBOX AP_RW_SHARE0: updateFlag (Bit 0)       */
#define TT_MAILBOX_AP_RW_SHARE0_updateFlag_Msk (0x1UL)          /*!< TT_MAILBOX AP_RW_SHARE0: updateFlag (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RW_SHARE0_SlotsNum_Pos (1UL)              /*!< TT_MAILBOX AP_RW_SHARE0: SlotsNum (Bit 1)         */
#define TT_MAILBOX_AP_RW_SHARE0_SlotsNum_Msk (0x3eUL)           /*!< TT_MAILBOX AP_RW_SHARE0: SlotsNum (Bitfield-Mask: 0x1f) */
/* =====================================================  AP_RW_SHARE1  ====================================================== */
/* =====================================================  AP_RO_SHARE0  ====================================================== */
#define TT_MAILBOX_AP_RO_SHARE0_HSMSigM7Status_Pos (0UL)        /*!< TT_MAILBOX AP_RO_SHARE0: HSMSigM7Status (Bit 0)   */
#define TT_MAILBOX_AP_RO_SHARE0_HSMSigM7Status_Msk (0x1UL)      /*!< TT_MAILBOX AP_RO_SHARE0: HSMSigM7Status (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE0_HSMFWStatus_Pos (1UL)           /*!< TT_MAILBOX AP_RO_SHARE0: HSMFWStatus (Bit 1)      */
#define TT_MAILBOX_AP_RO_SHARE0_HSMFWStatus_Msk (0x6UL)         /*!< TT_MAILBOX AP_RO_SHARE0: HSMFWStatus (Bitfield-Mask: 0x03) */
#define TT_MAILBOX_AP_RO_SHARE0_HSMRunStatus_Pos (3UL)          /*!< TT_MAILBOX AP_RO_SHARE0: HSMRunStatus (Bit 3)     */
#define TT_MAILBOX_AP_RO_SHARE0_HSMRunStatus_Msk (0x8UL)        /*!< TT_MAILBOX AP_RO_SHARE0: HSMRunStatus (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE0_HSMVersion_Pos (4UL)            /*!< TT_MAILBOX AP_RO_SHARE0: HSMVersion (Bit 4)       */
#define TT_MAILBOX_AP_RO_SHARE0_HSMVersion_Msk (0x1ff0UL)       /*!< TT_MAILBOX AP_RO_SHARE0: HSMVersion (Bitfield-Mask: 0x1ff) */
#define TT_MAILBOX_AP_RO_SHARE0_BootROMVersion_Pos (13UL)       /*!< TT_MAILBOX AP_RO_SHARE0: BootROMVersion (Bit 13)  */
#define TT_MAILBOX_AP_RO_SHARE0_BootROMVersion_Msk (0x7e000UL)  /*!< TT_MAILBOX AP_RO_SHARE0: BootROMVersion (Bitfield-Mask: 0x3f) */
#define TT_MAILBOX_AP_RO_SHARE0_SM2SC_Pos (19UL)                /*!< TT_MAILBOX AP_RO_SHARE0: SM2SC (Bit 19)           */
#define TT_MAILBOX_AP_RO_SHARE0_SM2SC_Msk (0x80000UL)           /*!< TT_MAILBOX AP_RO_SHARE0: SM2SC (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE0_SM3SC_Pos (20UL)                /*!< TT_MAILBOX AP_RO_SHARE0: SM3SC (Bit 20)           */
#define TT_MAILBOX_AP_RO_SHARE0_SM3SC_Msk (0x100000UL)          /*!< TT_MAILBOX AP_RO_SHARE0: SM3SC (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE0_SM4SC_Pos (21UL)                /*!< TT_MAILBOX AP_RO_SHARE0: SM4SC (Bit 21)           */
#define TT_MAILBOX_AP_RO_SHARE0_SM4SC_Msk (0x200000UL)          /*!< TT_MAILBOX AP_RO_SHARE0: SM4SC (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE0_TRNGSC_Pos (22UL)               /*!< TT_MAILBOX AP_RO_SHARE0: TRNGSC (Bit 22)          */
#define TT_MAILBOX_AP_RO_SHARE0_TRNGSC_Msk (0x400000UL)         /*!< TT_MAILBOX AP_RO_SHARE0: TRNGSC (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE0_LCS_Pos (23UL)                  /*!< TT_MAILBOX AP_RO_SHARE0: LCS (Bit 23)             */
#define TT_MAILBOX_AP_RO_SHARE0_LCS_Msk (0x1800000UL)           /*!< TT_MAILBOX AP_RO_SHARE0: LCS (Bitfield-Mask: 0x03) */
#define TT_MAILBOX_AP_RO_SHARE0_SIG_ERR_Pos (25UL)              /*!< TT_MAILBOX AP_RO_SHARE0: SIG_ERR (Bit 25)         */
#define TT_MAILBOX_AP_RO_SHARE0_SIG_ERR_Msk (0x3e000000UL)      /*!< TT_MAILBOX AP_RO_SHARE0: SIG_ERR (Bitfield-Mask: 0x1f) */
/* =====================================================  AP_RO_SHARE1  ====================================================== */
#define TT_MAILBOX_AP_RO_SHARE1_tmpsensor_err_Pos (0UL)         /*!< TT_MAILBOX AP_RO_SHARE1: tmpsensor_err (Bit 0)    */
#define TT_MAILBOX_AP_RO_SHARE1_tmpsensor_err_Msk (0x1UL)       /*!< TT_MAILBOX AP_RO_SHARE1: tmpsensor_err (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_volsensor_err_Pos (1UL)         /*!< TT_MAILBOX AP_RO_SHARE1: volsensor_err (Bit 1)    */
#define TT_MAILBOX_AP_RO_SHARE1_volsensor_err_Msk (0x2UL)       /*!< TT_MAILBOX AP_RO_SHARE1: volsensor_err (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_shield_err_Pos (2UL)            /*!< TT_MAILBOX AP_RO_SHARE1: shield_err (Bit 2)       */
#define TT_MAILBOX_AP_RO_SHARE1_shield_err_Msk (0x4UL)          /*!< TT_MAILBOX AP_RO_SHARE1: shield_err (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_smpu_err_Pos (3UL)              /*!< TT_MAILBOX AP_RO_SHARE1: smpu_err (Bit 3)         */
#define TT_MAILBOX_AP_RO_SHARE1_smpu_err_Msk (0x8UL)            /*!< TT_MAILBOX AP_RO_SHARE1: smpu_err (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_fcu_err_Pos (4UL)               /*!< TT_MAILBOX AP_RO_SHARE1: fcu_err (Bit 4)          */
#define TT_MAILBOX_AP_RO_SHARE1_fcu_err_Msk (0x10UL)            /*!< TT_MAILBOX AP_RO_SHARE1: fcu_err (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_fcache_err_Pos (5UL)            /*!< TT_MAILBOX AP_RO_SHARE1: fcache_err (Bit 5)       */
#define TT_MAILBOX_AP_RO_SHARE1_fcache_err_Msk (0x20UL)         /*!< TT_MAILBOX AP_RO_SHARE1: fcache_err (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_rom_err_Pos (6UL)               /*!< TT_MAILBOX AP_RO_SHARE1: rom_err (Bit 6)          */
#define TT_MAILBOX_AP_RO_SHARE1_rom_err_Msk (0x40UL)            /*!< TT_MAILBOX AP_RO_SHARE1: rom_err (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_fcu_crc_Pos (7UL)               /*!< TT_MAILBOX AP_RO_SHARE1: fcu_crc (Bit 7)          */
#define TT_MAILBOX_AP_RO_SHARE1_fcu_crc_Msk (0x80UL)            /*!< TT_MAILBOX AP_RO_SHARE1: fcu_crc (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_misc_crc_Pos (8UL)              /*!< TT_MAILBOX AP_RO_SHARE1: misc_crc (Bit 8)         */
#define TT_MAILBOX_AP_RO_SHARE1_misc_crc_Msk (0x100UL)          /*!< TT_MAILBOX AP_RO_SHARE1: misc_crc (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_trng_crc_Pos (9UL)              /*!< TT_MAILBOX AP_RO_SHARE1: trng_crc (Bit 9)         */
#define TT_MAILBOX_AP_RO_SHARE1_trng_crc_Msk (0x200UL)          /*!< TT_MAILBOX AP_RO_SHARE1: trng_crc (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_smpu_crc_Pos (10UL)             /*!< TT_MAILBOX AP_RO_SHARE1: smpu_crc (Bit 10)        */
#define TT_MAILBOX_AP_RO_SHARE1_smpu_crc_Msk (0x400UL)          /*!< TT_MAILBOX AP_RO_SHARE1: smpu_crc (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_pmu_crc_Pos (11UL)              /*!< TT_MAILBOX AP_RO_SHARE1: pmu_crc (Bit 11)         */
#define TT_MAILBOX_AP_RO_SHARE1_pmu_crc_Msk (0x800UL)           /*!< TT_MAILBOX AP_RO_SHARE1: pmu_crc (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_pki_alarm_Pos (12UL)            /*!< TT_MAILBOX AP_RO_SHARE1: pki_alarm (Bit 12)       */
#define TT_MAILBOX_AP_RO_SHARE1_pki_alarm_Msk (0x1000UL)        /*!< TT_MAILBOX AP_RO_SHARE1: pki_alarm (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_aes_alrm_Pos (13UL)             /*!< TT_MAILBOX AP_RO_SHARE1: aes_alrm (Bit 13)        */
#define TT_MAILBOX_AP_RO_SHARE1_aes_alrm_Msk (0x2000UL)         /*!< TT_MAILBOX AP_RO_SHARE1: aes_alrm (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_des_alarm_Pos (14UL)            /*!< TT_MAILBOX AP_RO_SHARE1: des_alarm (Bit 14)       */
#define TT_MAILBOX_AP_RO_SHARE1_des_alarm_Msk (0x4000UL)        /*!< TT_MAILBOX AP_RO_SHARE1: des_alarm (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_laser_Pos (15UL)                /*!< TT_MAILBOX AP_RO_SHARE1: laser (Bit 15)           */
#define TT_MAILBOX_AP_RO_SHARE1_laser_Msk (0x8000UL)            /*!< TT_MAILBOX AP_RO_SHARE1: laser (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_vcc_gd_alarm_Pos (16UL)         /*!< TT_MAILBOX AP_RO_SHARE1: vcc_gd_alarm (Bit 16)    */
#define TT_MAILBOX_AP_RO_SHARE1_vcc_gd_alarm_Msk (0x10000UL)    /*!< TT_MAILBOX AP_RO_SHARE1: vcc_gd_alarm (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_cmu_alarm_Pos (17UL)            /*!< TT_MAILBOX AP_RO_SHARE1: cmu_alarm (Bit 17)       */
#define TT_MAILBOX_AP_RO_SHARE1_cmu_alarm_Msk (0x20000UL)       /*!< TT_MAILBOX AP_RO_SHARE1: cmu_alarm (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_otp_systemconfig_Pos (18UL)     /*!< TT_MAILBOX AP_RO_SHARE1: otp_systemconfig (Bit 18) */
#define TT_MAILBOX_AP_RO_SHARE1_otp_systemconfig_Msk (0x40000UL) /*!< TT_MAILBOX AP_RO_SHARE1: otp_systemconfig (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_mbist_Pos (19UL)                /*!< TT_MAILBOX AP_RO_SHARE1: mbist (Bit 19)           */
#define TT_MAILBOX_AP_RO_SHARE1_mbist_Msk (0x80000UL)           /*!< TT_MAILBOX AP_RO_SHARE1: mbist (Bitfield-Mask: 0x01) */
#define TT_MAILBOX_AP_RO_SHARE1_otp_hw_bnk_Pos (20UL)           /*!< TT_MAILBOX AP_RO_SHARE1: otp_hw_bnk (Bit 20)      */
#define TT_MAILBOX_AP_RO_SHARE1_otp_hw_bnk_Msk (0x100000UL)     /*!< TT_MAILBOX AP_RO_SHARE1: otp_hw_bnk (Bitfield-Mask: 0x01) */
/* ==========================================================  ID  =========================================================== */

#ifdef __cplusplus
}
#endif

#endif
