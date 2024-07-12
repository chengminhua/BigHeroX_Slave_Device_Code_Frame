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
#ifndef A8V2_PDB_H
#define A8V2_PDB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_PDB_VENDOR_ID_H                     1541
#define A8V2_PDB_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_PDB_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_PDB_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_PDB_SW_MAJOR_VERSION_H              1
#define A8V2_PDB_SW_MINOR_VERSION_H              1
#define A8V2_PDB_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_PDB.h and TT_Common.h file version check */
#if (A8V2_PDB_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_PDB.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_PDB_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_PDB_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_PDB_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_PDB.h and TT_Common.h are different"
#endif
#if ((A8V2_PDB_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_PDB_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_PDB_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_PDB.h and TT_Common.h are different"
#endif


typedef enum
{
	PDB_GROUP_0_CH_0 = 0U,
	PDB_GROUP_0_CH_1 = 1U,
	PDB_GROUP_0_CH_2 = 2U,
	PDB_GROUP_0_CH_3 = 3U,
	PDB_GROUP_0_CH_4 = 4U,
	PDB_GROUP_0_CH_5 = 5U,
	PDB_GROUP_0_CH_6 = 6U,
	PDB_GROUP_0_CH_7 = 7U,
	PDB_GROUP_1_CH_0 = 8U,
	PDB_GROUP_1_CH_1 = 9U,
	PDB_GROUP_1_CH_2 = 10U,
	PDB_GROUP_1_CH_3 = 11U,
	PDB_GROUP_1_CH_4 = 12U,
	PDB_GROUP_1_CH_5 = 13U,
	PDB_GROUP_1_CH_6 = 14U,
	PDB_GROUP_1_CH_7 = 15U,
	PDB_GROUP_INVALID_CH = 16U
}Pdb_PreTriggerChannelType;
/**
  * @brief TT_PDB_CLUSTER [CH] (PDB channel.)
  */
typedef struct {
  __IOM uint32_t  CHxC1;                        /*!< (@ 0x00000000) Control Register.                                          */
  __IOM uint32_t  CHxS;                         /*!< (@ 0x00000004) Status Register.                                           */
  __IOM uint32_t  CHxDLY[8];                    /*!< (@ 0x00000008) Delay Register.                                            */
} TT_PDB_CLUSTER_Type;                      /*!< Size = 40 (0x28)                                                          */

/* =========================================================================================================================== */
/* ================                                        TT_PDB                                         ================ */
/* =========================================================================================================================== */

/**
  * @brief PDB Unit. (TT_PDB0)
  */

typedef struct {                                /*!< (@ 0x40198000) TT_PDB0 Structure                                      */
  __IOM uint32_t  SC;                           /*!< (@ 0x00000000) Control Status Register.                                   */
  __IOM uint32_t  MOD;                          /*!< (@ 0x00000004) Counter Mode.                                              */
  __IM  uint32_t  CNT;                          /*!< (@ 0x00000008) Current Count.                                             */
  __IOM uint32_t  IDLY;                         /*!< (@ 0x0000000C) Interrupt Delay.                                           */
  __IOM TT_PDB_CLUSTER_Type CH[2];              /*!< (@ 0x00000010) PDB channel.                                               */
  __IOM uint32_t  POEN;                         /*!< (@ 0x00000060) Delay Register Enable.                                     */
  __IOM uint32_t  PO0DLY;                       /*!< (@ 0x00000064) Delay Register.                                            */
} Pdb_RegType, *Pdb_RegMemMapPtr;               /*!< Size = 104 (0x68)                                                         */

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define TT_PDB0_BASE            0x40198000UL
#define TT_PDB1_BASE            0x40199000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define TT_PDB0                 ((Pdb_RegMemMapPtr)        TT_PDB0_BASE)
#define TT_PDB1                 ((Pdb_RegMemMapPtr)        TT_PDB1_BASE)

#define TT_PDB_BASE_PTRS       {TT_PDB0, TT_PDB1}

/* =========================================================================================================================== */
/* ================                                        TT_PDB                                         ================ */
/* =========================================================================================================================== */

/* ==========================================================  SC  =========================================================== */
#define TT_PDB_SC_LDOK_Pos            (0UL)                     /*!< TT_PDB SC: LDOK (Bit 0)                           */
#define TT_PDB_SC_LDOK_Msk            (0x1UL)                   /*!< TT_PDB SC: LDOK (Bitfield-Mask: 0x01)             */
#define TT_PDB_SC_CONT_Pos            (1UL)                     /*!< TT_PDB SC: CONT (Bit 1)                           */
#define TT_PDB_SC_CONT_Msk            (0x2UL)                   /*!< TT_PDB SC: CONT (Bitfield-Mask: 0x01)             */
#define TT_PDB_SC_MULT_Pos            (2UL)                     /*!< TT_PDB SC: MULT (Bit 2)                           */
#define TT_PDB_SC_MULT_Msk            (0xcUL)                   /*!< TT_PDB SC: MULT (Bitfield-Mask: 0x03)             */
#define TT_PDB_SC_PDBIE_Pos           (5UL)                     /*!< TT_PDB SC: PDBIE (Bit 5)                          */
#define TT_PDB_SC_PDBIE_Msk           (0x20UL)                  /*!< TT_PDB SC: PDBIE (Bitfield-Mask: 0x01)            */
#define TT_PDB_SC_PDBIF_Pos           (6UL)                     /*!< TT_PDB SC: PDBIF (Bit 6)                          */
#define TT_PDB_SC_PDBIF_Msk           (0x40UL)                  /*!< TT_PDB SC: PDBIF (Bitfield-Mask: 0x01)            */
#define TT_PDB_SC_PDBEN_Pos           (7UL)                     /*!< TT_PDB SC: PDBEN (Bit 7)                          */
#define TT_PDB_SC_PDBEN_Msk           (0x80UL)                  /*!< TT_PDB SC: PDBEN (Bitfield-Mask: 0x01)            */
#define TT_PDB_SC_TRGSEL_Pos          (8UL)                     /*!< TT_PDB SC: TRGSEL (Bit 8)                         */
#define TT_PDB_SC_TRGSEL_Msk          (0xf00UL)                 /*!< TT_PDB SC: TRGSEL (Bitfield-Mask: 0x0f)           */
#define TT_PDB_SC_PRESCALER_Pos       (12UL)                    /*!< TT_PDB SC: PRESCALER (Bit 12)                     */
#define TT_PDB_SC_PRESCALER_Msk       (0x7000UL)                /*!< TT_PDB SC: PRESCALER (Bitfield-Mask: 0x07)        */
#define TT_PDB_SC_DMAEN_Pos           (15UL)                    /*!< TT_PDB SC: DMAEN (Bit 15)                         */
#define TT_PDB_SC_DMAEN_Msk           (0x8000UL)                /*!< TT_PDB SC: DMAEN (Bitfield-Mask: 0x01)            */
#define TT_PDB_SC_SWTRIG_Pos          (16UL)                    /*!< TT_PDB SC: SWTRIG (Bit 16)                        */
#define TT_PDB_SC_SWTRIG_Msk          (0x10000UL)               /*!< TT_PDB SC: SWTRIG (Bitfield-Mask: 0x01)           */
#define TT_PDB_SC_PDBEIE_Pos          (17UL)                    /*!< TT_PDB SC: PDBEIE (Bit 17)                        */
#define TT_PDB_SC_PDBEIE_Msk          (0x20000UL)               /*!< TT_PDB SC: PDBEIE (Bitfield-Mask: 0x01)           */
#define TT_PDB_SC_LDMOD_Pos           (18UL)                    /*!< TT_PDB SC: LDMOD (Bit 18)                         */
#define TT_PDB_SC_LDMOD_Msk           (0xc0000UL)               /*!< TT_PDB SC: LDMOD (Bitfield-Mask: 0x03)            */
/* ==========================================================  MOD  ========================================================== */
#define TT_PDB_MOD_FIELD_Pos          (0UL)                     /*!< TT_PDB MOD: FIELD (Bit 0)                         */
#define TT_PDB_MOD_FIELD_Msk          (0xffffUL)                /*!< TT_PDB MOD: FIELD (Bitfield-Mask: 0xffff)         */
/* ==========================================================  CNT  ========================================================== */
#define TT_PDB_CNT_FIELD_Pos          (0UL)                     /*!< TT_PDB CNT: FIELD (Bit 0)                         */
#define TT_PDB_CNT_FIELD_Msk          (0xffffUL)                /*!< TT_PDB CNT: FIELD (Bitfield-Mask: 0xffff)         */
/* =========================================================  IDLY  ========================================================== */
#define TT_PDB_IDLY_FIELD_Pos         (0UL)                     /*!< TT_PDB IDLY: FIELD (Bit 0)                        */
#define TT_PDB_IDLY_FIELD_Msk         (0xffffUL)                /*!< TT_PDB IDLY: FIELD (Bitfield-Mask: 0xffff)        */
/* =========================================================  POEN  ========================================================== */
#define TT_PDB_POEN_FIELD_Pos         (0UL)                     /*!< TT_PDB POEN: FIELD (Bit 0)                        */
#define TT_PDB_POEN_FIELD_Msk         (0xffUL)                  /*!< TT_PDB POEN: FIELD (Bitfield-Mask: 0xff)          */
/* ========================================================  PO0DLY  ========================================================= */
#define TT_PDB_PO0DLY_DLY2_Pos        (0UL)                     /*!< TT_PDB PO0DLY: DLY2 (Bit 0)                       */
#define TT_PDB_PO0DLY_DLY2_Msk        (0xffffUL)                /*!< TT_PDB PO0DLY: DLY2 (Bitfield-Mask: 0xffff)       */
#define TT_PDB_PO0DLY_DLY1_Pos        (16UL)                    /*!< TT_PDB PO0DLY: DLY1 (Bit 16)                      */
#define TT_PDB_PO0DLY_DLY1_Msk        (0xffff0000UL)            /*!< TT_PDB PO0DLY: DLY1 (Bitfield-Mask: 0xffff)       */

/* =========================================================================================================================== */
/* ================                                            CH                                             ================ */
/* =========================================================================================================================== */

/* =========================================================  CHxC1  ========================================================= */
#define CH_CHxC1_EN_Pos                   (0UL)                     /*!< CH CHxC1: EN (Bit 0)                                  */
#define CH_CHxC1_EN_Msk                   (0xffUL)                  /*!< CH CHxC1: EN (Bitfield-Mask: 0xff)                    */
#define CH_CHxC1_TOS_Pos                  (8UL)                     /*!< CH CHxC1: TOS (Bit 8)                                 */
#define CH_CHxC1_TOS_Msk                  (0xff00UL)                /*!< CH CHxC1: TOS (Bitfield-Mask: 0xff)                   */
/* =========================================================  CHxS  ========================================================== */
#define CH_CHxS_ERR_Pos                   (0UL)                     /*!< CH CHxS: ERR (Bit 0)                                  */
#define CH_CHxS_ERR_Msk                   (0xffUL)                  /*!< CH CHxS: ERR (Bitfield-Mask: 0xff)                    */
#define CH_CHxS_CF_Pos                    (16UL)                    /*!< CH CHxS: CF (Bit 16)                                  */
#define CH_CHxS_CF_Msk                    (0xff0000UL)              /*!< CH CHxS: CF (Bitfield-Mask: 0xff)                     */
/* ========================================================  CHxDLY  ========================================================= */
#define CH_CHxDLY_DLY_Pos                 (0UL)                     /*!< CH CHxDLY: DLY (Bit 0)                                */
#define CH_CHxDLY_DLY_Msk                 (0xffffUL)                /*!< CH CHxDLY: DLY (Bitfield-Mask: 0xffff)                */


#ifdef __cplusplus
}
#endif

#endif  /* end of A8V2_PDB_H */
