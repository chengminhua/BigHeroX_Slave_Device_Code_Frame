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
#ifndef A8V2_RTC_H
#define A8V2_RTC_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_RTC_VENDOR_ID_H                     1541
#define A8V2_RTC_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_RTC_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_RTC_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_RTC_SW_MAJOR_VERSION_H              1
#define A8V2_RTC_SW_MINOR_VERSION_H              1
#define A8V2_RTC_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_RTC.h and TT_Common.h file version check */
#if (A8V2_RTC_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_RTC.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_RTC_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_RTC_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_RTC_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_RTC.h and TT_Common.h are different"
#endif
#if ((A8V2_RTC_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_RTC_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_RTC_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_RTC.h and TT_Common.h are different"
#endif


/* =========================================================================================================================== */
/* ================                                        TT_RTC                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Error Inject Module (TT_RTC)
  */

typedef struct {                                /*!< (@ 0x00005000) TT_RTC Structure                                       */
  __IM  uint32  RESERVED[4];
  __IOM uint32  SV;                           /*!< (@ 0x00000014) RTC SV Register                                            */
  __IM  uint32  RESERVED1[59];  
  __IOM uint32  RTCC;                         /*!< (@ 0x00000100) RTC Control Register                                       */
  __IOM uint32  RTCS;                         /*!< (@ 0x00000104) RTC Status Register                                        */
  __IOM uint32  APIVAL;                       /*!< (@ 0x00000108) API Compare value Register                                 */
  __IOM uint32  RTCVAL;                       /*!< (@ 0x0000010C) RTC Compare value Register                                 */
} Rtc_RegType, *Rtc_RegMemMapPtr;               /*!< Size = 272 (0x110)                                                        */


/** Number of instances of the I2C module. */
#define RTC_INSTANCE_COUNT                       (2u)

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define IP_RTC_BASE                              (0x400A0000UL)

/** Peripheral RTC base pointer */
#define IP_RTC                                   ((Rtc_RegType *)IP_RTC_BASE)

/** Array initializer of RTC peripheral base addresses */
#define IP_RTC_BASE_ADDRS                        { IP_RTC_BASE }

/** Array initializer of RTC peripheral base pointers */
#define IP_RTC_BASE_PTRS                         { IP_RTC }

/* =========================================================================================================================== */
/* ================                                        TT_RTC                                         ================ */
/* =========================================================================================================================== */

/* =========================================================  RTCC  ========================================================== */
#define TT_RTC_RTCC_WAKEUP_EN_Pos     (9UL)                     /*!< TT_RTC RTCC: WAKEUP_EN (Bit 9)                    */
#define TT_RTC_RTCC_WAKEUP_EN_Msk     (0x200UL)                 /*!< TT_RTC RTCC: WAKEUP_EN (Bitfield-Mask: 0x01)      */
#define TT_RTC_RTCC_DIV32EN_Pos       (13UL)                    /*!< TT_RTC RTCC: DIV32EN (Bit 13)                     */
#define TT_RTC_RTCC_DIV32EN_Msk       (0x2000UL)                /*!< TT_RTC RTCC: DIV32EN (Bitfield-Mask: 0x01)        */
#define TT_RTC_RTCC_APIIE_Pos         (14UL)                    /*!< TT_RTC RTCC: APIIE (Bit 14)                       */
#define TT_RTC_RTCC_APIIE_Msk         (0x4000UL)                /*!< TT_RTC RTCC: APIIE (Bitfield-Mask: 0x01)          */
#define TT_RTC_RTCC_APIEN_Pos         (15UL)                    /*!< TT_RTC RTCC: APIEN (Bit 15)                       */
#define TT_RTC_RTCC_APIEN_Msk         (0x8000UL)                /*!< TT_RTC RTCC: APIEN (Bitfield-Mask: 0x01)          */
#define TT_RTC_RTCC_ROVRIE_Pos        (27UL)                    /*!< TT_RTC RTCC: ROVRIE (Bit 27)                      */
#define TT_RTC_RTCC_ROVRIE_Msk        (0x8000000UL)             /*!< TT_RTC RTCC: ROVRIE (Bitfield-Mask: 0x01)         */
#define TT_RTC_RTCC_ROVREN_Pos        (28UL)                    /*!< TT_RTC RTCC: ROVREN (Bit 28)                      */
#define TT_RTC_RTCC_ROVREN_Msk        (0x10000000UL)            /*!< TT_RTC RTCC: ROVREN (Bitfield-Mask: 0x01)         */
#define TT_RTC_RTCC_FRZEN_Pos         (29UL)                    /*!< TT_RTC RTCC: FRZEN (Bit 29)                       */
#define TT_RTC_RTCC_FRZEN_Msk         (0x20000000UL)            /*!< TT_RTC RTCC: FRZEN (Bitfield-Mask: 0x01)          */
#define TT_RTC_RTCC_RTCIE_Pos         (30UL)                    /*!< TT_RTC RTCC: RTCIE (Bit 30)                       */
#define TT_RTC_RTCC_RTCIE_Msk         (0x40000000UL)            /*!< TT_RTC RTCC: RTCIE (Bitfield-Mask: 0x01)          */
#define TT_RTC_RTCC_CNTEN_Pos         (31UL)                    /*!< TT_RTC RTCC: CNTEN (Bit 31)                       */
#define TT_RTC_RTCC_CNTEN_Msk         (0x80000000UL)            /*!< TT_RTC RTCC: CNTEN (Bitfield-Mask: 0x01)          */
/* =========================================================  RTCS  ========================================================== */
#define TT_RTC_RTCS_ROVRF_Pos         (10UL)                    /*!< TT_RTC RTCS: ROVRF (Bit 10)                       */
#define TT_RTC_RTCS_ROVRF_Msk         (0x400UL)                 /*!< TT_RTC RTCS: ROVRF (Bitfield-Mask: 0x01)          */
#define TT_RTC_RTCS_APIF_Pos          (13UL)                    /*!< TT_RTC RTCS: APIF (Bit 13)                        */
#define TT_RTC_RTCS_APIF_Msk          (0x2000UL)                /*!< TT_RTC RTCS: APIF (Bitfield-Mask: 0x01)           */
#define TT_RTC_RTCS_RTCF_Pos          (29UL)                    /*!< TT_RTC RTCS: RTCF (Bit 29)                        */
#define TT_RTC_RTCS_RTCF_Msk          (0x20000000UL)            /*!< TT_RTC RTCS: RTCF (Bitfield-Mask: 0x01)           */
/* ========================================================  APIVAL  ========================================================= */
#define TT_RTC_APIVAL_APIVAL_Pos      (0UL)                     /*!< TT_RTC APIVAL: APIVAL (Bit 0)                     */
#define TT_RTC_APIVAL_APIVAL_Msk      (0xffffffffUL)            /*!< TT_RTC APIVAL: APIVAL (Bitfield-Mask: 0xffffffff) */
/* ========================================================  RTCVAL  ========================================================= */
#define TT_RTC_RTCVAL_RTCVAL_Pos      (0UL)                     /*!< TT_RTC RTCVAL: RTCVAL (Bit 0)                     */
#define TT_RTC_RTCVAL_RTCVAL_Msk      (0xffffffffUL)            /*!< TT_RTC RTCVAL: RTCVAL (Bitfield-Mask: 0xffffffff) */

#ifdef __cplusplus
}
#endif

#endif  /* A8V2_FCU_H */
