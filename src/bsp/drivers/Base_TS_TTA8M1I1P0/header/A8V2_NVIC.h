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

#ifndef A8V2_NVIC_H
#define A8V2_NVIC_H

#include "TT_Common.h"

#ifdef __cplusplus
 extern "C" {
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_NVIC_VENDOR_ID_H                     1541
#define A8V2_NVIC_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_NVIC_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_NVIC_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_NVIC_SW_MAJOR_VERSION_H              1
#define A8V2_NVIC_SW_MINOR_VERSION_H              1
#define A8V2_NVIC_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_CORE.h and TT_Common.h file version check */
#if (A8V2_NVIC_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_CORE.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_NVIC_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_NVIC_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_NVIC_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_CORE.h and TT_Common.h are different"
#endif
#if ((A8V2_NVIC_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_NVIC_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_NVIC_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_CORE.h and TT_Common.h are different"
#endif


/**
  \ingroup    CMSIS_core_register
  \defgroup   CMSIS_NVIC  Nested Vectored Interrupt Controller (NVIC)
  \brief      Type definitions for the NVIC Registers
  @{
 */

/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  __IOM uint32 ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32 RESERVED0[24U];
  __IOM uint32 ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32 RESERVED1[24U];
  __IOM uint32 ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32 RESERVED2[24U];
  __IOM uint32 ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32 RESERVED3[24U];
  __IOM uint32 IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32 RESERVED4[56U];
  __IOM uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32 RESERVED5[644U];
  __OM  uint32 STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_RegType;

/* Software Triggered Interrupt Register Definitions */
#define TT_NVIC_STIR_INTID_Pos                 0U                                         /*!< STIR: INTLINESNUM Position */
#define TT_NVIC_STIR_INTID_Msk                (0x1FFUL /*<< NVIC_STIR_INTID_Pos*/)        /*!< STIR: INTLINESNUM Mask */
#define TT_NVIC_ISER_COUNT                      8u
#define TT_NVIC_ICER_COUNT                      8u
#define TT_NVIC_ISPR_COUNT                      8u
#define TT_NVIC_ICPR_COUNT                      8u
#define TT_NVIC_IP_COUNT                        240u
#define TT_NVIC_USER_IRQ_OFFSET                 16


#define TT_NVIC_BASE           (0xE000E000UL +  0x0100UL)                    /*!< NVIC Base Address */

#define TT_NVIC                ((NVIC_RegType      *)     TT_NVIC_BASE     )   /*!< NVIC configuration struct */


#ifdef __cplusplus
}
#endif

#endif /* __CORE_CM7_H_DEPENDANT */

