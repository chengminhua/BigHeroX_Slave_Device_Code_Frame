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
#ifndef A8V2_LASER_H
#define A8V2_LASER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_LASER_VENDOR_ID_H                     1541
#define A8V2_LASER_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_LASER_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_LASER_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_LASER_SW_MAJOR_VERSION_H              1
#define A8V2_LASER_SW_MINOR_VERSION_H              1
#define A8V2_LASER_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_LASER.h and TT_Common.h file version check */
#if (A8V2_LASER_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_LASER.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_LASER_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_LASER_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_LASER_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_LASER.h and TT_Common.h are different"
#endif
#if ((A8V2_LASER_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_LASER_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_LASER_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_LASER.h and TT_Common.h are different"
#endif


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
  * @brief Synchronous Serial Port Device(TT_LASER)
  */

typedef struct {                                /*!< (@ 0x40060000) TT_SHIELD Structure                                    */
  __IOM uint32_t  CR;                           /*!< (@ 0x00000000) Config Register                                            */
  __IOM uint32_t  DATA;                         /*!< (@ 0x00000004) OCFR Register                                              */
  __IOM uint32_t  OE;                         /*!< (@ 0x00000008) DATA Register                                              */
  __IOM uint32_t  SE;                      /*!< (@ 0x0000000C) Line Output Enable Register                                */
  __IOM uint32_t  SR;                       /*!< (@ 0x00000010) Interrupt Enable Register                                  */
  __IOM uint32_t  ERR;                      /*!< (@ 0x00000014) Line Status Register                                       */
  __IOM uint32_t  INTEN;                       /*!< (@ 0x00000018) Interrupt Status Register                                  */
} TT_LASER_Type;                           /*!< Size = 32 (0x20)                                                          */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
///* LASER - Peripheral instance base addresses */
///** Peripheral LASER0 base address */
//#define TT_LASER0_BASE          0x40080000UL
///** Peripheral LASER0 base pointer */
//#define TT_LASER0                 ((TT_LASER_Type*)       TT_LASER0_BASE)

/* LASER - Peripheral instance base addresses */
/** Peripheral LASER1 base address */
#define TT_LASER1_BASE          0x40065000UL
/** Peripheral LASER1 base pointer */
#define TT_LASER1                 ((TT_LASER_Type*)       TT_LASER1_BASE)

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif

