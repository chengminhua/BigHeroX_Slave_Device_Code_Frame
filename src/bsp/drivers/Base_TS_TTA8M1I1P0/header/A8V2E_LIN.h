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
#ifndef A8V2E_LIN_H
#define A8V2E_LIN_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_LIN_VENDOR_ID_H                     1541
#define A8V2E_LIN_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_LIN_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_LIN_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_LIN_SW_MAJOR_VERSION_H              1
#define A8V2E_LIN_SW_MINOR_VERSION_H              1
#define A8V2E_LIN_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifndef A8V2E_LIN_H
/* A8V2E_LIN.h and TT_Common.h file version check */
#if (A8V2E_LIN_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_LIN.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_LIN_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_LIN_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_LIN_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_LIN.h and TT_Common.h are different"
#endif
#if ((A8V2E_LIN_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_LIN_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_LIN_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_LIN.h and TT_Common.h are different"
#endif
#endif

typedef struct {                                /*!< (@ 0x40140000) TT_LIN0 Structure                                      */
  __IOM uint32  LINCR1;              /*!< (@ 0x00000000) LIN Control Register 1                                     */
  __IOM uint32  LINIER;              /*!< (@ 0x00000004) LIN Interrupt enable register                              */
  __IOM uint32  LINSR;               /*!< (@ 0x00000008) LIN Status Register                                        */
  __IOM uint32  LINESR;              /*!< (@ 0x0000000C) LIN Error Status Register                                  */
  __IOM uint32  UARTCR;              /*!< (@ 0x00000010) UART Mode Control Register                                 */
  __IOM uint32  UARTSR;              /*!< (@ 0x00000014) UART Mode Status Register                                  */
  __IOM uint32  LINTCSR;             /*!< (@ 0x00000018) LIN Time-Out Control Status Register                       */
  __IOM uint32  LINOCR;              /*!< (@ 0x0000001C) LIN Output Compare Register                                */
  __IOM uint32  LINTOCR;             /*!< (@ 0x00000020) LIN Time-Out Control Register                              */
  __IOM uint32  LINFBRR;             /*!< (@ 0x00000024) LIN Fractional Baud Rate Register                          */
  __IOM uint32  LINIBRR;             /*!< (@ 0x00000028) LIN Integer Baud Rate Register                             */
  __IOM uint32  LINCFR;              /*!< (@ 0x0000002C) LIN Checksum Field Register                                */
  __IOM uint32  LINCR2;              /*!< (@ 0x00000030) LIN Control Register 2                                     */
  __IOM uint32  BIDR;                /*!< (@ 0x00000034) Buffer Identifier Register                                 */
  __IOM uint32  BDRL;                /*!< (@ 0x00000038) Buffer Data Register Least Significant                     */
  __IOM uint32  BDRM;                /*!< (@ 0x0000003C) Buffer Data Register Most Significant                      */
  __IOM uint32  IFER;                /*!< (@ 0x00000040) Identifier Filter Enable Register                          */
  __IM  uint32  IFMI;                /*!< (@ 0x00000044) Identifier Filter Match Index                              */
  __IOM uint32  IFMR;                /*!< (@ 0x00000048) Identifier Filter Mode Register                            */
  __IOM uint32  IFCR[16];            /*!< (@ 0x0000004C) Global Control Register                                    */
  __IOM uint32  GCR;                 /*!< (@ 0x0000008C) Global Control Register                                    */
  __IOM uint32  UARTPTO;             /*!< (@ 0x00000090) UART Preset Timeout Register                               */
  __IM  uint32  UARTCTO;             /*!< (@ 0x00000094) UART Current Timeout Register                              */
  __IOM uint32  DMATXE;              /*!< (@ 0x00000098) DMA Tx Enable Register                                     */
  __IOM uint32  DMARXE;              /*!< (@ 0x0000009C) DMA Rx Enable Register                                     */
} TT_LIN_Type;                              /*!< Size = 160 (0xa0)                                                         */

#define TT_LIN0_BASE            0x40140000UL
#define TT_LIN1_BASE            0x40141000UL
#define TT_LIN2_BASE            0x40142000UL
#define TT_LIN3_BASE            0x40143000UL
#define TT_LIN4_BASE            0x40144000UL
#define TT_LIN5_BASE            0x40145000UL
#define TT_LIN6_BASE            0x40146000UL
#define TT_LIN7_BASE            0x40147000UL
#define TT_LIN8_BASE            0x40150000UL
#define TT_LIN9_BASE            0x40151000UL
#define TT_LIN10_BASE           0x40152000UL
#define TT_LIN11_BASE           0x40153000UL
#define TT_LIN12_BASE           0x40154000UL
#define TT_LIN13_BASE           0x40155000UL
#define TT_LIN14_BASE           0x40156000UL
#define TT_LIN15_BASE           0x40157000UL

#define TT_LIN0                 ((TT_LIN_Type*)        TT_LIN0_BASE)
#define TT_LIN1                 ((TT_LIN_Type*)        TT_LIN1_BASE)
#define TT_LIN2                 ((TT_LIN_Type*)        TT_LIN2_BASE)
#define TT_LIN3                 ((TT_LIN_Type*)        TT_LIN3_BASE)
#define TT_LIN4                 ((TT_LIN_Type*)        TT_LIN4_BASE)
#define TT_LIN5                 ((TT_LIN_Type*)        TT_LIN5_BASE)
#define TT_LIN6                 ((TT_LIN_Type*)        TT_LIN6_BASE)
#define TT_LIN7                 ((TT_LIN_Type*)        TT_LIN7_BASE)
#define TT_LIN8                 ((TT_LIN_Type*)        TT_LIN8_BASE)
#define TT_LIN9                 ((TT_LIN_Type*)        TT_LIN9_BASE)
#define TT_LIN10                ((TT_LIN_Type*)        TT_LIN10_BASE)
#define TT_LIN11                ((TT_LIN_Type*)        TT_LIN11_BASE)
#define TT_LIN12                ((TT_LIN_Type*)        TT_LIN12_BASE)
#define TT_LIN13                ((TT_LIN_Type*)        TT_LIN13_BASE)
#define TT_LIN14                ((TT_LIN_Type*)        TT_LIN14_BASE)
#define TT_LIN15                ((TT_LIN_Type*)        TT_LIN15_BASE)
                                                                  
/* =========================================================================================================================== */
/* ================                                        TT_LIN                                         ================ */
/* =========================================================================================================================== */

/* ====================================================  LINCR1  ==================================================== */
#define TT_LIN_LINCR1_INIT_Pos (0UL)                   /*!< TT_LIN LINCR1: INIT (Bit 0)              */
#define TT_LIN_LINCR1_INIT_Msk (0x1UL)                 /*!< TT_LIN LINCR1: INIT (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_SLEEP_Pos (1UL)                  /*!< TT_LIN LINCR1: SLEEP (Bit 1)             */
#define TT_LIN_LINCR1_SLEEP_Msk (0x2UL)                /*!< TT_LIN LINCR1: SLEEP (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_RBLM_Pos (2UL)                   /*!< TT_LIN LINCR1: RBLM (Bit 2)              */
#define TT_LIN_LINCR1_RBLM_Msk (0x4UL)                 /*!< TT_LIN LINCR1: RBLM (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_SSBL_Pos (3UL)                   /*!< TT_LIN LINCR1: SSBL (Bit 3)              */
#define TT_LIN_LINCR1_SSBL_Msk (0x8UL)                 /*!< TT_LIN LINCR1: SSBL (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_MME_Pos (4UL)                    /*!< TT_LIN LINCR1: MME (Bit 4)               */
#define TT_LIN_LINCR1_MME_Msk (0x10UL)                 /*!< TT_LIN LINCR1: MME (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_LBKM_Pos (5UL)                   /*!< TT_LIN LINCR1: LBKM (Bit 5)              */
#define TT_LIN_LINCR1_LBKM_Msk (0x20UL)                /*!< TT_LIN LINCR1: LBKM (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_BF_Pos (7UL)                     /*!< TT_LIN LINCR1: BF (Bit 7)                */
#define TT_LIN_LINCR1_BF_Msk (0x80UL)                  /*!< TT_LIN LINCR1: BF (Bitfield-Mask: 0x01)  */
#define TT_LIN_LINCR1_MBL_Pos (8UL)                    /*!< TT_LIN LINCR1: MBL (Bit 8)               */
#define TT_LIN_LINCR1_MBL_Msk (0xf00UL)                /*!< TT_LIN LINCR1: MBL (Bitfield-Mask: 0x0f) */
#define TT_LIN_LINCR1_AUTOWU_Pos (12UL)                /*!< TT_LIN LINCR1: AUTOWU (Bit 12)           */
#define TT_LIN_LINCR1_AUTOWU_Msk (0x1000UL)            /*!< TT_LIN LINCR1: AUTOWU (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_LASE_Pos (13UL)                  /*!< TT_LIN LINCR1: LASE (Bit 13)             */
#define TT_LIN_LINCR1_LASE_Msk (0x2000UL)              /*!< TT_LIN LINCR1: LASE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_CFD_Pos (14UL)                   /*!< TT_LIN LINCR1: CFD (Bit 14)              */
#define TT_LIN_LINCR1_CFD_Msk (0x4000UL)               /*!< TT_LIN LINCR1: CFD (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR1_CCD_Pos (15UL)                   /*!< TT_LIN LINCR1: CCD (Bit 15)              */
#define TT_LIN_LINCR1_CCD_Msk (0x8000UL)               /*!< TT_LIN LINCR1: CCD (Bitfield-Mask: 0x01) */
/* ====================================================  LINIER  ==================================================== */
#define TT_LIN_LINIER_HRIE_Pos (0UL)                   /*!< TT_LIN LINIER: HRIE (Bit 0)              */
#define TT_LIN_LINIER_HRIE_Msk (0x1UL)                 /*!< TT_LIN LINIER: HRIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_DTIE_Pos (1UL)                   /*!< TT_LIN LINIER: DTIE (Bit 1)              */
#define TT_LIN_LINIER_DTIE_Msk (0x2UL)                 /*!< TT_LIN LINIER: DTIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_DRIE_Pos (2UL)                   /*!< TT_LIN LINIER: DRIE (Bit 2)              */
#define TT_LIN_LINIER_DRIE_Msk (0x4UL)                 /*!< TT_LIN LINIER: DRIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_TOIE_Pos (3UL)                   /*!< TT_LIN LINIER: TOIE (Bit 3)              */
#define TT_LIN_LINIER_TOIE_Msk (0x8UL)                 /*!< TT_LIN LINIER: TOIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_WUIE_Pos (5UL)                   /*!< TT_LIN LINIER: WUIE (Bit 5)              */
#define TT_LIN_LINIER_WUIE_Msk (0x20UL)                /*!< TT_LIN LINIER: WUIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_LSIE_Pos (6UL)                   /*!< TT_LIN LINIER: LSIE (Bit 6)              */
#define TT_LIN_LINIER_LSIE_Msk (0x40UL)                /*!< TT_LIN LINIER: LSIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_BOIE_Pos (7UL)                   /*!< TT_LIN LINIER: BOIE (Bit 7)              */
#define TT_LIN_LINIER_BOIE_Msk (0x80UL)                /*!< TT_LIN LINIER: BOIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_FEIE_Pos (8UL)                   /*!< TT_LIN LINIER: FEIE (Bit 8)              */
#define TT_LIN_LINIER_FEIE_Msk (0x100UL)               /*!< TT_LIN LINIER: FEIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_HEIE_Pos (11UL)                  /*!< TT_LIN LINIER: HEIE (Bit 11)             */
#define TT_LIN_LINIER_HEIE_Msk (0x800UL)               /*!< TT_LIN LINIER: HEIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_CEIE_Pos (12UL)                  /*!< TT_LIN LINIER: CEIE (Bit 12)             */
#define TT_LIN_LINIER_CEIE_Msk (0x1000UL)              /*!< TT_LIN LINIER: CEIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_BEIE_Pos (13UL)                  /*!< TT_LIN LINIER: BEIE (Bit 13)             */
#define TT_LIN_LINIER_BEIE_Msk (0x2000UL)              /*!< TT_LIN LINIER: BEIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_OCIE_Pos (14UL)                  /*!< TT_LIN LINIER: OCIE (Bit 14)             */
#define TT_LIN_LINIER_OCIE_Msk (0x4000UL)              /*!< TT_LIN LINIER: OCIE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINIER_SZIE_Pos (15UL)                  /*!< TT_LIN LINIER: SZIE (Bit 15)             */
#define TT_LIN_LINIER_SZIE_Msk (0x8000UL)              /*!< TT_LIN LINIER: SZIE (Bitfield-Mask: 0x01) */
/* ====================================================  LINSR  ===================================================== */
#define TT_LIN_LINSR_HRF_Pos (0UL)                     /*!< TT_LIN LINSR: HRF (Bit 0)                */
#define TT_LIN_LINSR_HRF_Msk (0x1UL)                   /*!< TT_LIN LINSR: HRF (Bitfield-Mask: 0x01)  */
#define TT_LIN_LINSR_DTF_Pos (1UL)                     /*!< TT_LIN LINSR: DTF (Bit 1)                */
#define TT_LIN_LINSR_DTF_Msk (0x2UL)                   /*!< TT_LIN LINSR: DTF (Bitfield-Mask: 0x01)  */
#define TT_LIN_LINSR_DRF_Pos (2UL)                     /*!< TT_LIN LINSR: DRF (Bit 2)                */
#define TT_LIN_LINSR_DRF_Msk (0x4UL)                   /*!< TT_LIN LINSR: DRF (Bitfield-Mask: 0x01)  */
#define TT_LIN_LINSR_WUF_Pos (5UL)                     /*!< TT_LIN LINSR: WUF (Bit 5)                */
#define TT_LIN_LINSR_WUF_Msk (0x20UL)                  /*!< TT_LIN LINSR: WUF (Bitfield-Mask: 0x01)  */
#define TT_LIN_LINSR_RDI_Pos (6UL)                     /*!< TT_LIN LINSR: RDI (Bit 6)                */
#define TT_LIN_LINSR_RDI_Msk (0x40UL)                  /*!< TT_LIN LINSR: RDI (Bitfield-Mask: 0x01)  */
#define TT_LIN_LINSR_RXbusy_Pos (7UL)                  /*!< TT_LIN LINSR: RXbusy (Bit 7)             */
#define TT_LIN_LINSR_RXbusy_Msk (0x80UL)               /*!< TT_LIN LINSR: RXbusy (Bitfield-Mask: 0x01) */
#define TT_LIN_LINSR_DRBNE_Pos (8UL)                   /*!< TT_LIN LINSR: DRBNE (Bit 8)              */
#define TT_LIN_LINSR_DRBNE_Msk (0x100UL)               /*!< TT_LIN LINSR: DRBNE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINSR_RMB_Pos (9UL)                     /*!< TT_LIN LINSR: RMB (Bit 9)                */
#define TT_LIN_LINSR_RMB_Msk (0x200UL)                 /*!< TT_LIN LINSR: RMB (Bitfield-Mask: 0x01)  */
#define TT_LIN_LINSR_LINS_Pos (12UL)                   /*!< TT_LIN LINSR: LINS (Bit 12)              */
#define TT_LIN_LINSR_LINS_Msk (0xf000UL)               /*!< TT_LIN LINSR: LINS (Bitfield-Mask: 0x0f) */
#define TT_LIN_LINSR_RDC_Pos (16UL)                    /*!< TT_LIN LINSR: RDC (Bit 16)               */
#define TT_LIN_LINSR_RDC_Msk (0x70000UL)               /*!< TT_LIN LINSR: RDC (Bitfield-Mask: 0x07)  */
#define TT_LIN_LINSR_AUTOSYNC_COMP_Pos (19UL)          /*!< TT_LIN LINSR: AUTOSYNC_COMP (Bit 19)     */
#define TT_LIN_LINSR_AUTOSYNC_COMP_Msk (0x80000UL)     /*!< TT_LIN LINSR: AUTOSYNC_COMP (Bitfield-Mask: 0x01) */
/* ====================================================  LINESR  ==================================================== */
#define TT_LIN_LINESR_NF_Pos (0UL)                     /*!< TT_LIN LINESR: NF (Bit 0)                */
#define TT_LIN_LINESR_NF_Msk (0x1UL)                   /*!< TT_LIN LINESR: NF (Bitfield-Mask: 0x01)  */
#define TT_LIN_LINESR_BOF_Pos (7UL)                    /*!< TT_LIN LINESR: BOF (Bit 7)               */
#define TT_LIN_LINESR_BOF_Msk (0x80UL)                 /*!< TT_LIN LINESR: BOF (Bitfield-Mask: 0x01) */
#define TT_LIN_LINESR_FEF_Pos (8UL)                    /*!< TT_LIN LINESR: FEF (Bit 8)               */
#define TT_LIN_LINESR_FEF_Msk (0x100UL)                /*!< TT_LIN LINESR: FEF (Bitfield-Mask: 0x01) */
#define TT_LIN_LINESR_IDPEF_Pos (9UL)                  /*!< TT_LIN LINESR: IDPEF (Bit 9)             */
#define TT_LIN_LINESR_IDPEF_Msk (0x200UL)              /*!< TT_LIN LINESR: IDPEF (Bitfield-Mask: 0x01) */
#define TT_LIN_LINESR_SDEF_Pos (10UL)                  /*!< TT_LIN LINESR: SDEF (Bit 10)             */
#define TT_LIN_LINESR_SDEF_Msk (0x400UL)               /*!< TT_LIN LINESR: SDEF (Bitfield-Mask: 0x01) */
#define TT_LIN_LINESR_SFEF_Pos (11UL)                  /*!< TT_LIN LINESR: SFEF (Bit 11)             */
#define TT_LIN_LINESR_SFEF_Msk (0x800UL)               /*!< TT_LIN LINESR: SFEF (Bitfield-Mask: 0x01) */
#define TT_LIN_LINESR_CEF_Pos (12UL)                   /*!< TT_LIN LINESR: CEF (Bit 12)              */
#define TT_LIN_LINESR_CEF_Msk (0x1000UL)               /*!< TT_LIN LINESR: CEF (Bitfield-Mask: 0x01) */
#define TT_LIN_LINESR_BEF_Pos (13UL)                   /*!< TT_LIN LINESR: BEF (Bit 13)              */
#define TT_LIN_LINESR_BEF_Msk (0x2000UL)               /*!< TT_LIN LINESR: BEF (Bitfield-Mask: 0x01) */
#define TT_LIN_LINESR_OCF_Pos (14UL)                   /*!< TT_LIN LINESR: OCF (Bit 14)              */
#define TT_LIN_LINESR_OCF_Msk (0x4000UL)               /*!< TT_LIN LINESR: OCF (Bitfield-Mask: 0x01) */
#define TT_LIN_LINESR_SZF_Pos (15UL)                   /*!< TT_LIN LINESR: SZF (Bit 15)              */
#define TT_LIN_LINESR_SZF_Msk (0x8000UL)               /*!< TT_LIN LINESR: SZF (Bitfield-Mask: 0x01) */
/* ====================================================  UARTCR  ==================================================== */
#define TT_LIN_UARTCR_UART_Pos (0UL)                   /*!< TT_LIN UARTCR: UART (Bit 0)              */
#define TT_LIN_UARTCR_UART_Msk (0x1UL)                 /*!< TT_LIN UARTCR: UART (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_WL0_Pos (1UL)                    /*!< TT_LIN UARTCR: WL0 (Bit 1)               */
#define TT_LIN_UARTCR_WL0_Msk (0x2UL)                  /*!< TT_LIN UARTCR: WL0 (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_PCE_Pos (2UL)                    /*!< TT_LIN UARTCR: PCE (Bit 2)               */
#define TT_LIN_UARTCR_PCE_Msk (0x4UL)                  /*!< TT_LIN UARTCR: PCE (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_PC0_Pos (3UL)                    /*!< TT_LIN UARTCR: PC0 (Bit 3)               */
#define TT_LIN_UARTCR_PC0_Msk (0x8UL)                  /*!< TT_LIN UARTCR: PC0 (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_TxEn_Pos (4UL)                   /*!< TT_LIN UARTCR: TxEn (Bit 4)              */
#define TT_LIN_UARTCR_TxEn_Msk (0x10UL)                /*!< TT_LIN UARTCR: TxEn (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_RxEn_Pos (5UL)                   /*!< TT_LIN UARTCR: RxEn (Bit 5)              */
#define TT_LIN_UARTCR_RxEn_Msk (0x20UL)                /*!< TT_LIN UARTCR: RxEn (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_PC1_Pos (6UL)                    /*!< TT_LIN UARTCR: PC1 (Bit 6)               */
#define TT_LIN_UARTCR_PC1_Msk (0x40UL)                 /*!< TT_LIN UARTCR: PC1 (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_WL1_Pos (7UL)                    /*!< TT_LIN UARTCR: WL1 (Bit 7)               */
#define TT_LIN_UARTCR_WL1_Msk (0x80UL)                 /*!< TT_LIN UARTCR: WL1 (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_TFBM_Pos (8UL)                   /*!< TT_LIN UARTCR: TFBM (Bit 8)              */
#define TT_LIN_UARTCR_TFBM_Msk (0x100UL)               /*!< TT_LIN UARTCR: TFBM (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_RFBM_Pos (9UL)                   /*!< TT_LIN UARTCR: RFBM (Bit 9)              */
#define TT_LIN_UARTCR_RFBM_Msk (0x200UL)               /*!< TT_LIN UARTCR: RFBM (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_RDFL_RFC_Pos (10UL)              /*!< TT_LIN UARTCR: RDFL_RFC (Bit 10)         */
#define TT_LIN_UARTCR_RDFL_RFC_Msk (0x1c00UL)          /*!< TT_LIN UARTCR: RDFL_RFC (Bitfield-Mask: 0x07) */
#define TT_LIN_UARTCR_TDFL_TFC_Pos (13UL)              /*!< TT_LIN UARTCR: TDFL_TFC (Bit 13)         */
#define TT_LIN_UARTCR_TDFL_TFC_Msk (0xe000UL)          /*!< TT_LIN UARTCR: TDFL_TFC (Bitfield-Mask: 0x07) */
#define TT_LIN_UARTCR_WLS_Pos (16UL)                   /*!< TT_LIN UARTCR: WLS (Bit 16)              */
#define TT_LIN_UARTCR_WLS_Msk (0x10000UL)              /*!< TT_LIN UARTCR: WLS (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_SBUR_Pos (17UL)                  /*!< TT_LIN UARTCR: SBUR (Bit 17)             */
#define TT_LIN_UARTCR_SBUR_Msk (0x60000UL)             /*!< TT_LIN UARTCR: SBUR (Bitfield-Mask: 0x03) */
#define TT_LIN_UARTCR_DTU_PCETX_Pos (19UL)             /*!< TT_LIN UARTCR: DTU_PCETX (Bit 19)        */
#define TT_LIN_UARTCR_DTU_PCETX_Msk (0x80000UL)        /*!< TT_LIN UARTCR: DTU_PCETX (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_NEF_Pos (20UL)                   /*!< TT_LIN UARTCR: NEF (Bit 20)              */
#define TT_LIN_UARTCR_NEF_Msk (0x700000UL)             /*!< TT_LIN UARTCR: NEF (Bitfield-Mask: 0x07) */
#define TT_LIN_UARTCR_ROSE_Pos (23UL)                  /*!< TT_LIN UARTCR: ROSE (Bit 23)             */
#define TT_LIN_UARTCR_ROSE_Msk (0x800000UL)            /*!< TT_LIN UARTCR: ROSE (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTCR_OSR_Pos (24UL)                   /*!< TT_LIN UARTCR: OSR (Bit 24)              */
#define TT_LIN_UARTCR_OSR_Msk (0xf000000UL)            /*!< TT_LIN UARTCR: OSR (Bitfield-Mask: 0x0f) */
#define TT_LIN_UARTCR_CSP_Pos (28UL)                   /*!< TT_LIN UARTCR: CSP (Bit 28)              */
#define TT_LIN_UARTCR_CSP_Msk (0x70000000UL)           /*!< TT_LIN UARTCR: CSP (Bitfield-Mask: 0x07) */
#define TT_LIN_UARTCR_MIS_Pos (31UL)                   /*!< TT_LIN UARTCR: MIS (Bit 31)              */
#define TT_LIN_UARTCR_MIS_Msk (0x80000000UL)           /*!< TT_LIN UARTCR: MIS (Bitfield-Mask: 0x01) */
/* ====================================================  UARTSR  ==================================================== */
#define TT_LIN_UARTSR_NF_Pos (0UL)                     /*!< TT_LIN UARTSR: NF (Bit 0)                */
#define TT_LIN_UARTSR_NF_Msk (0x1UL)                   /*!< TT_LIN UARTSR: NF (Bitfield-Mask: 0x01)  */
#define TT_LIN_UARTSR_DTFTFF_Pos (1UL)                 /*!< TT_LIN UARTSR: DTFTFF (Bit 1)            */
#define TT_LIN_UARTSR_DTFTFF_Msk (0x2UL)               /*!< TT_LIN UARTSR: DTFTFF (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_DRFRFE_Pos (2UL)                 /*!< TT_LIN UARTSR: DRFRFE (Bit 2)            */
#define TT_LIN_UARTSR_DRFRFE_Msk (0x4UL)               /*!< TT_LIN UARTSR: DRFRFE (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_TO_Pos (3UL)                     /*!< TT_LIN UARTSR: TO (Bit 3)                */
#define TT_LIN_UARTSR_TO_Msk (0x8UL)                   /*!< TT_LIN UARTSR: TO (Bitfield-Mask: 0x01)  */
#define TT_LIN_UARTSR_RFNE_Pos (4UL)                   /*!< TT_LIN UARTSR: RFNE (Bit 4)              */
#define TT_LIN_UARTSR_RFNE_Msk (0x10UL)                /*!< TT_LIN UARTSR: RFNE (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_WUF_Pos (5UL)                    /*!< TT_LIN UARTSR: WUF (Bit 5)               */
#define TT_LIN_UARTSR_WUF_Msk (0x20UL)                 /*!< TT_LIN UARTSR: WUF (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_RDI_Pos (6UL)                    /*!< TT_LIN UARTSR: RDI (Bit 6)               */
#define TT_LIN_UARTSR_RDI_Msk (0x40UL)                 /*!< TT_LIN UARTSR: RDI (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_BOF_Pos (7UL)                    /*!< TT_LIN UARTSR: BOF (Bit 7)               */
#define TT_LIN_UARTSR_BOF_Msk (0x80UL)                 /*!< TT_LIN UARTSR: BOF (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_FEF_Pos (8UL)                    /*!< TT_LIN UARTSR: FEF (Bit 8)               */
#define TT_LIN_UARTSR_FEF_Msk (0x100UL)                /*!< TT_LIN UARTSR: FEF (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_RMB_Pos (9UL)                    /*!< TT_LIN UARTSR: RMB (Bit 9)               */
#define TT_LIN_UARTSR_RMB_Msk (0x200UL)                /*!< TT_LIN UARTSR: RMB (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_PE_Pos (10UL)                    /*!< TT_LIN UARTSR: PE (Bit 10)               */
#define TT_LIN_UARTSR_PE_Msk (0x3c00UL)                /*!< TT_LIN UARTSR: PE (Bitfield-Mask: 0x0f)  */
#define TT_LIN_UARTSR_OCF_Pos (14UL)                   /*!< TT_LIN UARTSR: OCF (Bit 14)              */
#define TT_LIN_UARTSR_OCF_Msk (0x4000UL)               /*!< TT_LIN UARTSR: OCF (Bitfield-Mask: 0x01) */
#define TT_LIN_UARTSR_SZF_Pos (15UL)                   /*!< TT_LIN UARTSR: SZF (Bit 15)              */
#define TT_LIN_UARTSR_SZF_Msk (0x8000UL)               /*!< TT_LIN UARTSR: SZF (Bitfield-Mask: 0x01) */
/* ===================================================  LINTCSR  ==================================================== */
#define TT_LIN_LINTCSR_CNT_Pos (0UL)                   /*!< TT_LIN LINTCSR: CNT (Bit 0)              */
#define TT_LIN_LINTCSR_CNT_Msk (0xffUL)                /*!< TT_LIN LINTCSR: CNT (Bitfield-Mask: 0xff) */
#define TT_LIN_LINTCSR_TOCE_Pos (8UL)                  /*!< TT_LIN LINTCSR: TOCE (Bit 8)             */
#define TT_LIN_LINTCSR_TOCE_Msk (0x100UL)              /*!< TT_LIN LINTCSR: TOCE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINTCSR_IOT_Pos (9UL)                   /*!< TT_LIN LINTCSR: IOT (Bit 9)              */
#define TT_LIN_LINTCSR_IOT_Msk (0x200UL)               /*!< TT_LIN LINTCSR: IOT (Bitfield-Mask: 0x01) */
#define TT_LIN_LINTCSR_MODE_Pos (10UL)                 /*!< TT_LIN LINTCSR: MODE (Bit 10)            */
#define TT_LIN_LINTCSR_MODE_Msk (0x400UL)              /*!< TT_LIN LINTCSR: MODE (Bitfield-Mask: 0x01) */
/* ====================================================  LINOCR  ==================================================== */
#define TT_LIN_LINOCR_OC1_Pos (0UL)                    /*!< TT_LIN LINOCR: OC1 (Bit 0)               */
#define TT_LIN_LINOCR_OC1_Msk (0xffUL)                 /*!< TT_LIN LINOCR: OC1 (Bitfield-Mask: 0xff) */
#define TT_LIN_LINOCR_OC2_Pos (8UL)                    /*!< TT_LIN LINOCR: OC2 (Bit 8)               */
#define TT_LIN_LINOCR_OC2_Msk (0xff00UL)               /*!< TT_LIN LINOCR: OC2 (Bitfield-Mask: 0xff) */
/* ===================================================  LINTOCR  ==================================================== */
#define TT_LIN_LINTOCR_HTO_Pos (0UL)                   /*!< TT_LIN LINTOCR: HTO (Bit 0)              */
#define TT_LIN_LINTOCR_HTO_Msk (0x7fUL)                /*!< TT_LIN LINTOCR: HTO (Bitfield-Mask: 0x7f) */
#define TT_LIN_LINTOCR_RTO_Pos (8UL)                   /*!< TT_LIN LINTOCR: RTO (Bit 8)              */
#define TT_LIN_LINTOCR_RTO_Msk (0xf00UL)               /*!< TT_LIN LINTOCR: RTO (Bitfield-Mask: 0x0f) */
/* ===================================================  LINFBRR  ==================================================== */
#define TT_LIN_LINFBRR_FBR_Pos (0UL)                   /*!< TT_LIN LINFBRR: FBR (Bit 0)              */
#define TT_LIN_LINFBRR_FBR_Msk (0xfUL)                 /*!< TT_LIN LINFBRR: FBR (Bitfield-Mask: 0x0f) */
/* ===================================================  LINIBRR  ==================================================== */
#define TT_LIN_LINIBRR_IBR_Pos (0UL)                   /*!< TT_LIN LINIBRR: IBR (Bit 0)              */
#define TT_LIN_LINIBRR_IBR_Msk (0xfffffUL)             /*!< TT_LIN LINIBRR: IBR (Bitfield-Mask: 0xfffff) */
/* ====================================================  LINCFR  ==================================================== */
#define TT_LIN_LINCFR_CF_Pos (0UL)                     /*!< TT_LIN LINCFR: CF (Bit 0)                */
#define TT_LIN_LINCFR_CF_Msk (0xffUL)                  /*!< TT_LIN LINCFR: CF (Bitfield-Mask: 0xff)  */
/* ====================================================  LINCR2  ==================================================== */
#define TT_LIN_LINCR2_HTRQ_Pos (8UL)                   /*!< TT_LIN LINCR2: HTRQ (Bit 8)              */
#define TT_LIN_LINCR2_HTRQ_Msk (0x100UL)               /*!< TT_LIN LINCR2: HTRQ (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR2_ABRQ_Pos (9UL)                   /*!< TT_LIN LINCR2: ABRQ (Bit 9)              */
#define TT_LIN_LINCR2_ABRQ_Msk (0x200UL)               /*!< TT_LIN LINCR2: ABRQ (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR2_DTRQ_Pos (10UL)                  /*!< TT_LIN LINCR2: DTRQ (Bit 10)             */
#define TT_LIN_LINCR2_DTRQ_Msk (0x400UL)               /*!< TT_LIN LINCR2: DTRQ (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR2_DDRQ_Pos (11UL)                  /*!< TT_LIN LINCR2: DDRQ (Bit 11)             */
#define TT_LIN_LINCR2_DDRQ_Msk (0x800UL)               /*!< TT_LIN LINCR2: DDRQ (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR2_WURQ_Pos (12UL)                  /*!< TT_LIN LINCR2: WURQ (Bit 12)             */
#define TT_LIN_LINCR2_WURQ_Msk (0x1000UL)              /*!< TT_LIN LINCR2: WURQ (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR2_IOPE_Pos (13UL)                  /*!< TT_LIN LINCR2: IOPE (Bit 13)             */
#define TT_LIN_LINCR2_IOPE_Msk (0x2000UL)              /*!< TT_LIN LINCR2: IOPE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR2_IOBE_Pos (14UL)                  /*!< TT_LIN LINCR2: IOBE (Bit 14)             */
#define TT_LIN_LINCR2_IOBE_Msk (0x4000UL)              /*!< TT_LIN LINCR2: IOBE (Bitfield-Mask: 0x01) */
#define TT_LIN_LINCR2_TBDE_Pos (15UL)                  /*!< TT_LIN LINCR2: TBDE (Bit 15)             */
#define TT_LIN_LINCR2_TBDE_Msk (0x8000UL)              /*!< TT_LIN LINCR2: TBDE (Bitfield-Mask: 0x01) */
/* =====================================================  BIDR  ===================================================== */
#define TT_LIN_BIDR_ID_Pos   (0UL)                     /*!< TT_LIN BIDR: ID (Bit 0)                  */
#define TT_LIN_BIDR_ID_Msk   (0x3fUL)                  /*!< TT_LIN BIDR: ID (Bitfield-Mask: 0x3f)    */
#define TT_LIN_BIDR_CCS_Pos  (8UL)                     /*!< TT_LIN BIDR: CCS (Bit 8)                 */
#define TT_LIN_BIDR_CCS_Msk  (0x100UL)                 /*!< TT_LIN BIDR: CCS (Bitfield-Mask: 0x01)   */
#define TT_LIN_BIDR_DIR_Pos  (9UL)                     /*!< TT_LIN BIDR: DIR (Bit 9)                 */
#define TT_LIN_BIDR_DIR_Msk  (0x200UL)                 /*!< TT_LIN BIDR: DIR (Bitfield-Mask: 0x01)   */
#define TT_LIN_BIDR_DFL_Pos  (10UL)                    /*!< TT_LIN BIDR: DFL (Bit 10)                */
#define TT_LIN_BIDR_DFL_Msk  (0x1c00UL)                /*!< TT_LIN BIDR: DFL (Bitfield-Mask: 0x07)   */
/* =====================================================  BDRL  ===================================================== */
#define TT_LIN_BDRL_DATA0_Pos (0UL)                    /*!< TT_LIN BDRL: DATA0 (Bit 0)               */
#define TT_LIN_BDRL_DATA0_Msk (0xffUL)                 /*!< TT_LIN BDRL: DATA0 (Bitfield-Mask: 0xff) */
#define TT_LIN_BDRL_DATA1_Pos (8UL)                    /*!< TT_LIN BDRL: DATA1 (Bit 8)               */
#define TT_LIN_BDRL_DATA1_Msk (0xff00UL)               /*!< TT_LIN BDRL: DATA1 (Bitfield-Mask: 0xff) */
#define TT_LIN_BDRL_DATA2_Pos (16UL)                   /*!< TT_LIN BDRL: DATA2 (Bit 16)              */
#define TT_LIN_BDRL_DATA2_Msk (0xff0000UL)             /*!< TT_LIN BDRL: DATA2 (Bitfield-Mask: 0xff) */
#define TT_LIN_BDRL_DATA3_Pos (24UL)                   /*!< TT_LIN BDRL: DATA3 (Bit 24)              */
#define TT_LIN_BDRL_DATA3_Msk (0xff000000UL)           /*!< TT_LIN BDRL: DATA3 (Bitfield-Mask: 0xff) */
/* =====================================================  BDRM  ===================================================== */
#define TT_LIN_BDRM_DATA4_Pos (0UL)                    /*!< TT_LIN BDRM: DATA4 (Bit 0)               */
#define TT_LIN_BDRM_DATA4_Msk (0xffUL)                 /*!< TT_LIN BDRM: DATA4 (Bitfield-Mask: 0xff) */
#define TT_LIN_BDRM_DATA5_Pos (8UL)                    /*!< TT_LIN BDRM: DATA5 (Bit 8)               */
#define TT_LIN_BDRM_DATA5_Msk (0xff00UL)               /*!< TT_LIN BDRM: DATA5 (Bitfield-Mask: 0xff) */
#define TT_LIN_BDRM_DATA6_Pos (16UL)                   /*!< TT_LIN BDRM: DATA6 (Bit 16)              */
#define TT_LIN_BDRM_DATA6_Msk (0xff0000UL)             /*!< TT_LIN BDRM: DATA6 (Bitfield-Mask: 0xff) */
#define TT_LIN_BDRM_DATA7_Pos (24UL)                   /*!< TT_LIN BDRM: DATA7 (Bit 24)              */
#define TT_LIN_BDRM_DATA7_Msk (0xff000000UL)           /*!< TT_LIN BDRM: DATA7 (Bitfield-Mask: 0xff) */
/* =====================================================  IFER  ===================================================== */
#define TT_LIN_IFER_FACT_Pos (0UL)                     /*!< TT_LIN IFER: FACT (Bit 0)                */
#define TT_LIN_IFER_FACT_Msk (0xffffUL)                /*!< TT_LIN IFER: FACT (Bitfield-Mask: 0xffff) */
/* =====================================================  IFMI  ===================================================== */
#define TT_LIN_IFMI_IFMI_Pos (0UL)                     /*!< TT_LIN IFMI: IFMI (Bit 0)                */
#define TT_LIN_IFMI_IFMI_Msk (0x1fUL)                  /*!< TT_LIN IFMI: IFMI (Bitfield-Mask: 0x1f)  */
/* =====================================================  IFMR  ===================================================== */
#define TT_LIN_IFMR_IFM_Pos  (0UL)                     /*!< TT_LIN IFMR: IFM (Bit 0)                 */
#define TT_LIN_IFMR_IFM_Msk  (0xffUL)                  /*!< TT_LIN IFMR: IFM (Bitfield-Mask: 0xff)   */
/* =====================================================  IFCR  ===================================================== */
#define TT_LIN_IFCR_ID_Pos   (0UL)                     /*!< TT_LIN IFCR: ID (Bit 0)                  */
#define TT_LIN_IFCR_ID_Msk   (0x3fUL)                  /*!< TT_LIN IFCR: ID (Bitfield-Mask: 0x3f)    */
#define TT_LIN_IFCR_CCS_Pos  (8UL)                     /*!< TT_LIN IFCR: CCS (Bit 8)                 */
#define TT_LIN_IFCR_CCS_Msk  (0x100UL)                 /*!< TT_LIN IFCR: CCS (Bitfield-Mask: 0x01)   */
#define TT_LIN_IFCR_DIR_Pos  (9UL)                     /*!< TT_LIN IFCR: DIR (Bit 9)                 */
#define TT_LIN_IFCR_DIR_Msk  (0x200UL)                 /*!< TT_LIN IFCR: DIR (Bitfield-Mask: 0x01)   */
#define TT_LIN_IFCR_DFL_Pos  (10UL)                    /*!< TT_LIN IFCR: DFL (Bit 10)                */
#define TT_LIN_IFCR_DFL_Msk  (0x1c00UL)                /*!< TT_LIN IFCR: DFL (Bitfield-Mask: 0x07)   */
/* =====================================================  GCR  ====================================================== */
#define TT_LIN_GCR_SR_Pos    (0UL)                     /*!< TT_LIN GCR: SR (Bit 0)                   */
#define TT_LIN_GCR_SR_Msk    (0x1UL)                   /*!< TT_LIN GCR: SR (Bitfield-Mask: 0x01)     */
#define TT_LIN_GCR_STOP_Pos  (1UL)                     /*!< TT_LIN GCR: STOP (Bit 1)                 */
#define TT_LIN_GCR_STOP_Msk  (0x2UL)                   /*!< TT_LIN GCR: STOP (Bitfield-Mask: 0x01)   */
#define TT_LIN_GCR_RDLIS_Pos (2UL)                     /*!< TT_LIN GCR: RDLIS (Bit 2)                */
#define TT_LIN_GCR_RDLIS_Msk (0x4UL)                   /*!< TT_LIN GCR: RDLIS (Bitfield-Mask: 0x01)  */
#define TT_LIN_GCR_TDLIS_Pos (3UL)                     /*!< TT_LIN GCR: TDLIS (Bit 3)                */
#define TT_LIN_GCR_TDLIS_Msk (0x8UL)                   /*!< TT_LIN GCR: TDLIS (Bitfield-Mask: 0x01)  */
#define TT_LIN_GCR_RDFBM_Pos (4UL)                     /*!< TT_LIN GCR: RDFBM (Bit 4)                */
#define TT_LIN_GCR_RDFBM_Msk (0x10UL)                  /*!< TT_LIN GCR: RDFBM (Bitfield-Mask: 0x01)  */
#define TT_LIN_GCR_TDFBM_Pos (5UL)                     /*!< TT_LIN GCR: TDFBM (Bit 5)                */
#define TT_LIN_GCR_TDFBM_Msk (0x20UL)                  /*!< TT_LIN GCR: TDFBM (Bitfield-Mask: 0x01)  */
/* ===================================================  UARTPTO  ==================================================== */
#define TT_LIN_UARTPTO_PTO_Pos (0UL)                   /*!< TT_LIN UARTPTO: PTO (Bit 0)              */
#define TT_LIN_UARTPTO_PTO_Msk (0xfffUL)               /*!< TT_LIN UARTPTO: PTO (Bitfield-Mask: 0xfff) */
/* ===================================================  UARTCTO  ==================================================== */
#define TT_LIN_UARTCTO_CTO_Pos (0UL)                   /*!< TT_LIN UARTCTO: CTO (Bit 0)              */
#define TT_LIN_UARTCTO_CTO_Msk (0xfffUL)               /*!< TT_LIN UARTCTO: CTO (Bitfield-Mask: 0xfff) */
/* ====================================================  DMATXE  ==================================================== */
#define TT_LIN_DMATXE_DTE_Pos (0UL)                    /*!< TT_LIN DMATXE: DTE (Bit 0)               */
#define TT_LIN_DMATXE_DTE_Msk (0xffffUL)               /*!< TT_LIN DMATXE: DTE (Bitfield-Mask: 0xffff) */
/* ====================================================  DMARXE  ==================================================== */
#define TT_LIN_DMARXE_DRE_Pos (0UL)                    /*!< TT_LIN DMARXE: DRE (Bit 0)               */
#define TT_LIN_DMARXE_DRE_Msk (0xffffUL)               /*!< TT_LIN DMARXE: DRE (Bitfield-Mask: 0xffff) */

/**
* @brief        The base address of all LIN channels
* @details      The base address of all LIN channels
*/
#define TT_LIN_BASE_PTRS                    {TT_LIN0,  TT_LIN1,  TT_LIN2,  TT_LIN3, \
                                             TT_LIN4,  TT_LIN5,  TT_LIN6,  TT_LIN7, \
                                             TT_LIN8,  TT_LIN9,  TT_LIN10, TT_LIN11,\
                                             TT_LIN12, TT_LIN13, TT_LIN14, TT_LIN15}
#define TT_LIN_PPU_CONTROL                  {PPU_CONTROL_LIN0,  PPU_CONTROL_LIN1,  PPU_CONTROL_LIN2,  PPU_CONTROL_LIN3, \
                                             PPU_CONTROL_LIN4,  PPU_CONTROL_LIN5,  PPU_CONTROL_LIN6,  PPU_CONTROL_LIN7, \
                                             PPU_CONTROL_LIN8,  PPU_CONTROL_LIN9,  PPU_CONTROL_LIN10, PPU_CONTROL_LIN11, \
                                             PPU_CONTROL_LIN12, PPU_CONTROL_LIN13, PPU_CONTROL_LIN14, PPU_CONTROL_LIN15}
#define TT_LIN_SCU_CLK_CONTROL              {TT_SCU_CLK_CONTROL_LIN0,  TT_SCU_CLK_CONTROL_LIN1,  TT_SCU_CLK_CONTROL_LIN2, \
                                             TT_SCU_CLK_CONTROL_LIN3,  TT_SCU_CLK_CONTROL_LIN4,  TT_SCU_CLK_CONTROL_LIN5, \
                                             TT_SCU_CLK_CONTROL_LIN6,  TT_SCU_CLK_CONTROL_LIN7,  TT_SCU_CLK_CONTROL_LIN8, \
                                             TT_SCU_CLK_CONTROL_LIN9,  TT_SCU_CLK_CONTROL_LIN10, TT_SCU_CLK_CONTROL_LIN11, \
                                             TT_SCU_CLK_CONTROL_LIN12, TT_SCU_CLK_CONTROL_LIN13, TT_SCU_CLK_CONTROL_LIN14, \
                                             TT_SCU_CLK_CONTROL_LIN15}
#define TT_LIN_MCU_CLK                      {MCU_CLOCK_LIN0,  MCU_CLOCK_LIN1,  MCU_CLOCK_LIN2,  MCU_CLOCK_LIN3, \
                                             MCU_CLOCK_LIN4,  MCU_CLOCK_LIN5,  MCU_CLOCK_LIN6,  MCU_CLOCK_LIN7, \
                                             MCU_CLOCK_LIN8,  MCU_CLOCK_LIN9,  MCU_CLOCK_LIN10, MCU_CLOCK_LIN11, \
                                             MCU_CLOCK_LIN12, MCU_CLOCK_LIN13, MCU_CLOCK_LIN14, MCU_CLOCK_LIN15}
#define TT_LIN_SCU_LOCAL_RST                {TT_SCU_LOCAL_RST_LIN0,  TT_SCU_LOCAL_RST_LIN1,  TT_SCU_LOCAL_RST_LIN2, \
                                             TT_SCU_LOCAL_RST_LIN3,  TT_SCU_LOCAL_RST_LIN4,  TT_SCU_LOCAL_RST_LIN5, \
                                             TT_SCU_LOCAL_RST_LIN6,  TT_SCU_LOCAL_RST_LIN7,  TT_SCU_LOCAL_RST_LIN8, \
                                             TT_SCU_LOCAL_RST_LIN9,  TT_SCU_LOCAL_RST_LIN10, TT_SCU_LOCAL_RST_LIN11, \
                                             TT_SCU_LOCAL_RST_LIN12, TT_SCU_LOCAL_RST_LIN13, TT_SCU_LOCAL_RST_LIN14, \
                                             TT_SCU_LOCAL_RST_LIN15}

#ifdef __cplusplus
}
#endif

#endif /* A8V2E_LIN_H */
