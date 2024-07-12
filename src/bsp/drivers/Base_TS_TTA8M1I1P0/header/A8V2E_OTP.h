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
#ifndef A8V2E_OTP_H
#define A8V2E_OTP_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_OTP_VENDOR_ID_H                     1541
#define A8V2E_OTP_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_OTP_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_OTP_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_OTP_SW_MAJOR_VERSION_H              1
#define A8V2E_OTP_SW_MINOR_VERSION_H              1
#define A8V2E_OTP_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_OTP.h and TT_Common.h file version check */
#if (A8V2E_OTP_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_OTP.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_OTP_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_OTP_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_OTP_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_OTP.h and TT_Common.h are different"
#endif
#if ((A8V2E_OTP_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_OTP_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_OTP_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_OTP.h and TT_Common.h are different"
#endif


/* =========================================================================================================================== */
/* ================                                        TT_FCU                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief OTP Controller Device (TT_OTP)
  */

typedef struct {                                /*!< (@ 0x01400000) TT_OTP Structure                                       */
  __IOM uint32_t  OTP[8192];                    /*!< (@ 0x00000000) OTP Content                                                */
} POTP_Type;                              /*!< Size = 28672 (0x7000)                                                     */


/**
  * @brief DOTP Controller Device (TT_DOTP)
  */

typedef struct {                                /*!< (@ 0x01580000) TT_DOTP Structure                                      */
  __IOM uint32_t  OTP[2048];                    /*!< (@ 0x00000000) OTP Content                                                */
} DOTP_Type;                             /*!< Size = 4096 (0x1000)                                                      */


/** Number of instances of the FCU module. */
#define POTP_INSTANCE_COUNT                       	(1u)

/* FCU - Peripheral instance base addresses */
/** Peripheral FCU base address */
#define TT_POTP_BASE                                 (0x01400000UL)
#define TT_POTP_SIZE             				 	  0x8000      /* OTP size in bytes */

/** Peripheral FCU base pointer */
#define TT_POTP                                      ((POTP_Type *)TT_POTP_BASE)

/** Array initializer of FCU peripheral base addresses */
#define TT_POTP_BASE_ADDRS                        	{ TT_POTP_BASE }

/** Array initializer of FCU peripheral base pointers */
#define TT_POTP_BASE_PTRS                         	{ TT_POTP}

/** Number of instances of the FCU module. */
#define DOTP_INSTANCE_COUNT                       	(1u)

/* FCU - Peripheral instance base addresses */
/** Peripheral FCU base address */
#define TT_DOTP_BASE                                (0x01540000UL)
#define TT_DOTP_SIZE            					0x2000      /* DOTP size in bytes */

/** Peripheral FCU base pointer */
#define TT_DOTP                                    	((DOTP_Type *)TT_DOTP_BASE)

/** Array initializer of FCU peripheral base addresses */
#define TT_DOTP_BASE_ADDRS                        	{ TT_DOTP_BASE }

/** Array initializer of FCU peripheral base pointers */
#define TT_DOTP_BASE_PTRS                         	{ TT_DOTP}



/* OTP address and value */
#define OTP_SYSCONFIG0_WORDADDR         (8U)

#define OTP_CONFIG_WORD0                (uint32)(TT_POTP->OTP[OTP_SYSCONFIG0_WORDADDR + 0])
#define OTP_CONFIG_WORD1                (uint32)(TT_POTP->OTP[OTP_SYSCONFIG0_WORDADDR + 1])
#define OTP_CONFIG_WORD2                (uint32)(TT_POTP->OTP[OTP_SYSCONFIG0_WORDADDR + 2])
#define OTP_CONFIG_WORD3                (uint32)(TT_POTP->OTP[OTP_SYSCONFIG0_WORDADDR + 3])
#define OTP_CONFIG_WORD4                (uint32)(TT_POTP->OTP[OTP_SYSCONFIG0_WORDADDR + 4])
#define OTP_CONFIG_WORD5                (uint32)(TT_POTP->OTP[OTP_SYSCONFIG0_WORDADDR + 5])
#define OTP_CONFIG_WORD6                (uint32)(TT_POTP->OTP[OTP_SYSCONFIG0_WORDADDR + 6])
#define OTP_CONFIG_WORD7                (uint32)(TT_POTP->OTP[OTP_SYSCONFIG0_WORDADDR + 7])

#define OTP_HSM_U16                     (uint16)(OTP_CONFIG_WORD0 & 0xFFFFU)
#define OTP_FLASH_SIZE_U16              (uint16)((OTP_CONFIG_WORD0 >> 16) & 0xFFFFU)
#define OTP_SRAM_SIZE_U16               (uint16)(OTP_CONFIG_WORD1 & 0xFFFFU)
#define OTP_DFLASH_SIZE_U16             (uint16)((OTP_CONFIG_WORD1 >> 16) & 0xFFFFU)
#define OTP_HSM_POWER_U16               (uint16)(OTP_CONFIG_WORD2 & 0xFFFFU);
#define OTP_OSC_CONFIG_U32              (uint32)(((OTP_CONFIG_WORD2 >> 16) & 0xFFFFU) | (OTP_CONFIG_WORD3 & 0xFFFFU))
#define OTP_EEP_CONFIG_U16              (uint16)((OTP_CONFIG_WORD3 >> 16) & 0xFFFFU)
#define OTP_ENDINIT_DIS_U16             (uint16)(OTP_CONFIG_WORD4 & 0xFFFFU)
#define OTP_M7_WAIT_HSM_U16             (uint16)((OTP_CONFIG_WORD4 >> 16) & 0xFFFFU)
#define OTP_BL_CONFIG_U32               (uint32)(OTP_CONFIG_WORD5 & 0xFFFFU)

#define OTP_ENDINIT_ENABLE              ((OTP_ENDINIT_DIS_U16 == 0xAA55) ? FALSE : TRUE)


#define OTP_USRCFG_WORDADDR				      (0x100U)
#define OTP_USRCFG_WORD0                (uint32)(TT_POTP->OTP[OTP_USRCFG_WORDADDR + 2])
#define OTP_MBIST_ENABLE              	(((OTP_USRCFG_WORD0 & 0xFFFFU) == 0xAA55U) ? TRUE : FALSE)
#define OTP_LBIST_ENABLE              	((((OTP_USRCFG_WORD0 >> 16) & 0xFFFFU) == 0xAA55U) ? TRUE : FALSE)
#define OTP_BIST_ENABLE              	  (OTP_MBIST_ENABLE || OTP_LBIST_ENABLE)


#ifdef __cplusplus
}
#endif

#endif  /* A8V2E_OTP_H */
