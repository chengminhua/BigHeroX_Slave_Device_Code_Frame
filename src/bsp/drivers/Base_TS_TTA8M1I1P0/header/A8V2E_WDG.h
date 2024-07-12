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
#ifndef A8V2E_WDG_H
#define A8V2E_WDG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_WDG_VENDOR_ID_H                     1541
#define A8V2E_WDG_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_WDG_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_WDG_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_WDG_SW_MAJOR_VERSION_H              1
#define A8V2E_WDG_SW_MINOR_VERSION_H              1
#define A8V2E_WDG_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_WDG.h and TT_Common.h file version check */
#if (A8V2E_WDG_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_WDG.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_WDG_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_WDG_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_WDG_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_WDG.h and TT_Common.h are different"
#endif
#if ((A8V2E_WDG_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_WDG_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_WDG_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_WDG.h and TT_Common.h are different"
#endif

/* =========================================================================================================================== */
/* ================                                        TT_WDG                                        ================ */
/* =========================================================================================================================== */


/**
  * @brief Window Watchdog Timer (TT_WDG)
  */

typedef struct {                                /*!< (@ 0x400A3000) TT_WWDT Structure                                          */
  __OM  uint32_t  INPUT;                        /*!< (@ 0x00000000) WWindow atchdog Input Register                             */
  __IOM uint32_t  INIT_COUNT;                   /*!< (@ 0x00000004) Window Watchdog init_count Register                        */
  __OM  uint32_t  INIT_VALUE;                   /*!< (@ 0x00000008) Window Watchdog init_value Register                        */
  __IOM uint32_t  WINDOWN_VALUE;                /*!< (@ 0x0000000C) Window Watchdog window Register                            */
  __IOM uint32_t  CONTROL;                      /*!< (@ 0x00000010) Window Watchdog control Register                           */
  __OM  uint32_t  INTERRUPT;                    /*!< (@ 0x00000014) Window Watchdog interrupt Register                         */
  __IOM uint32_t  LOCK;                         /*!< (@ 0x00000018) Window Watchdog Lock Register                              */
  __IOM uint32_t  INTNUM;                       /*!< (@ 0x0000001C) Window Watchdog Interrupt count Register                   */
  __IM  uint32_t  RESERVED[7];
  __IOM uint32_t  SV;                           /*!< (@ 0x0000003C) Window Watchdog SV Register                                */
} Wdg_RegType,*Wdg_RegMemMapPtr;     


#define TT_WDG_BASE            0x400A3000UL
#define TT_WDG                 ((Wdg_RegType*)       TT_WDG_BASE)
/* =========================================================================================================================== */
/* ================                                        TT_WDG                                        ================ */
/* =========================================================================================================================== */

/* =========================================================  INPUT  ========================================================= */
/* ======================================================  INIT_COUNT  ======================================================= */
/* ======================================================  INIT_VALUE  ======================================================= */
/* =====================================================  WINDOWN_VALUE  ===================================================== */
/* ========================================================  CONTROL  ======================================================== */
#define TT_WDG_CONTROL_ENABLE_Pos    (0UL)                     /*!< TT_WDG CONTROL: ENABLE (Bit 0)                   */
#define TT_WDG_CONTROL_ENABLE_Msk    (0x1UL)                   /*!< TT_WDG CONTROL: ENABLE (Bitfield-Mask: 0x01)     */
#define TT_WDG_CONTROL_VALUE_SELECT_Pos (1UL)                  /*!< TT_WDG CONTROL: VALUE_SELECT (Bit 1)             */
#define TT_WDG_CONTROL_VALUE_SELECT_Msk (0x2UL)                /*!< TT_WDG CONTROL: VALUE_SELECT (Bitfield-Mask: 0x01) */
#define TT_WDG_CONTROL_INT_ENABLE_Pos (2UL)                    /*!< TT_WDG CONTROL: INT_ENABLE (Bit 2)               */
#define TT_WDG_CONTROL_INT_ENABLE_Msk (0x4UL)                  /*!< TT_WDG CONTROL: INT_ENABLE (Bitfield-Mask: 0x01) */
/* =======================================================  INTERRUPT  ======================================================= */
#define TT_WDG_INTERRUPT_Pos (0x0UL)                           /*!< TT_WDG INTERRUPT: INTERRUPT (Bit 2)               */
#define TT_WDG_INTERRUPT_Msk (0x1UL)                           /*!< TT_WDG INTERRUPT: INTERRUPT (Bitfield-Mask: 0x01) */
/* =========================================================  LOCK  ========================================================== */
#define TT_WDG_LOCK_Pos (0x0UL)                                /*!< TT_WDG LOCK: LOCK (Bit 2)               */
#define TT_WDG_LOCK_Msk (0x1UL)                                /*!< TT_WDG LOCK: LOCK (Bitfield-Mask: 0x01) */
/* ========================================================  INTNUM  ========================================================= */
#define TT_WDG_INTNUM_Pos         (0UL)                     /*!< TT_WWDT INTNUM: INTNUM (Bit 0)                        */
#define TT_WDG_INTNUM_Msk         (0xffffffffUL)            /*!< TT_WWDT INTNUM: INTNUM (Bitfield-Mask: 0xffffffff)    */
/* ==========================================================  SV  =========================================================== */
#define TT_WDG_SV_Pos             (0UL)                  /*!< TT_WWDT SV: WDT_SV (Bit 0)                            */
#define TT_WDG_SV_Msk             (0x1UL)                /*!< TT_WWDT SV: WDT_SV (Bitfield-Mask: 0x01)              */

#ifdef __cplusplus
}
#endif

#endif  /* end of A8V2E_TRNG_H */
