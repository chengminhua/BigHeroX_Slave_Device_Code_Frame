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
#ifndef A8V2E_GPIO_H
#define A8V2E_GPIO_H

#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_GPIO_VENDOR_ID_H                     1541
#define A8V2E_GPIO_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_GPIO_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_GPIO_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_GPIO_SW_MAJOR_VERSION_H              1
#define A8V2E_GPIO_SW_MINOR_VERSION_H              1
#define A8V2E_GPIO_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_GPIO.h and TT_Common.h file version check */
#if (A8V2E_GPIO_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_GPIO.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_GPIO_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_GPIO_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_GPIO_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_GPIO.h and TT_Common.h are different"
#endif
#if ((A8V2E_GPIO_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_GPIO_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_GPIO_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_GPIO.h and TT_Common.h are different"
#endif


 

typedef struct {                                /*!< (@ 0x400D1000) TT_GPIOA Structure                                     */
  __IOM uint32  DATA;                         /*!< (@ 0x00000000) GPIO Data Register                                         */
  __IOM uint32  DIR;                          /*!< (@ 0x00000004) GPIO data direction register                               */
  __IOM uint32  AFSEL;                        /*!< (@ 0x00000008) GPIO Interrupt Sense Register                              */
  __OM  uint32  SOR;                          /*!< (@ 0x0000000C) Set GPIO pin is 1.                                         */
  __OM  uint32  COR;                          /*!< (@ 0x00000010) Clear GPIO pin.                                            */
  __OM  uint32  TOR;                          /*!< (@ 0x00000014) Toggle GPIO pin.                                           */
  __IOM uint32  GF;                           /*!< (@ 0x00000018) Burr range config.                                         */
  __IOM uint32  IS;                           /*!< (@ 0x0000001C) GPIO Interrupt Sense Register                              */
  __IOM uint32  IBE;                          /*!< (@ 0x00000020) GPIO Interrupt Both-Edge Register                          */
  __IOM uint32  IEV;                          /*!< (@ 0x00000024) GPIO Interrupt Event Register                              */
  __IOM uint32  IE;                           /*!< (@ 0x00000028) GPIO Interrupt Enable Register.                            */
  __IM  uint32  RIS;                          /*!< (@ 0x0000002C) GPIO Raw Interrupt Status Register.                        */
  __IM  uint32  MIS;                          /*!< (@ 0x00000030) GPIO Masked Interrupt Status Register.                     */
  __OM  uint32  IC;                           /*!< (@ 0x00000034) GPIO Interrupt Clear Register.                             */
  __IOM uint32  ITCR;                         /*!< (@ 0x00000038) GPIO test mode.                                            */
  __IOM uint32  ITIP1;                        /*!< (@ 0x0000003C) Test Input Data Bit 1.                                     */
  __IOM uint32  ITIP2;                        /*!< (@ 0x00000040) Test Input Data Bit 2.                                     */
  __OM  uint32  ITOP1;                        /*!< (@ 0x00000044) Test Output Data Bit 1.                                    */
  __IM  uint32  ITOP2;                        /*!< (@ 0x00000048) Test Output Data Bit 2.                                    */
  __IOM uint32  ITOP3;                        /*!< (@ 0x0000004C) Test Output Data Bit 2.                                    */
  __IM  uint32  RESERVED[1003];
  __IOM uint32  SV;                           /*!< (@ 0x000000FF8) Privileged Mode Registers.                                */
  __IM  uint32  ID;                           /*!< (@ 0x000000FFC) ID Registers.                                             */
} Dio_RegType, *GPIO_RegMemMapPtr;                            /*!< Size = 4096 (0x1000)                                                      */

/** Number of instances of the GPIO module. */
#define GPIO_INSTANCE_COUNT                       (5u)

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO base address */
#define TT_GPIO_BASE0                              (0x400D1000UL)
#define TT_GPIO_BASE1                              (0x400D2000UL)
#define TT_GPIO_BASE2                              (0x400D3000UL)
#define TT_GPIO_BASE3                              (0x40112000UL)
#define TT_GPIO_BASE4                              (0x40113000UL)

/** Peripheral GPIO base pointer */
#define TT_GPIO0                                   ((Dio_RegType *)TT_GPIO_BASE0)
#define TT_GPIO1                                   ((Dio_RegType *)TT_GPIO_BASE1)
#define TT_GPIO2                                   ((Dio_RegType *)TT_GPIO_BASE2)
#define TT_GPIO3                                   ((Dio_RegType *)TT_GPIO_BASE3)
#define TT_GPIO4                                   ((Dio_RegType *)TT_GPIO_BASE4)

/** Array initializer of GPIO peripheral base addresses */
#define TT_GPIO_BASE_ADDRS                        { TT_GPIO_BASE0,TT_GPIO_BASE1,TT_GPIO_BASE2,TT_GPIO_BASE3,TT_GPIO_BASE4}

/** Array initializer of GPIO peripheral base pointers */
#define TT_GPIO_BASE_PTRS                         { TT_GPIO0,TT_GPIO1,TT_GPIO2,TT_GPIO3,TT_GPIO4}

#ifdef __cplusplus
}
#endif

#endif /* end of A8V2E_GPIO_H */
