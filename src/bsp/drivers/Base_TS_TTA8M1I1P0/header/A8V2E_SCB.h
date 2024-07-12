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

#ifndef A8V2E_SCB_H
#define A8V2E_SCB_H

#include <TT_Common.h>

#ifdef __cplusplus
 extern "C" {
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_SCB_VENDOR_ID_H                     1541
#define A8V2E_SCB_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_SCB_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_SCB_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_SCB_SW_MAJOR_VERSION_H              1
#define A8V2E_SCB_SW_MINOR_VERSION_H              1
#define A8V2E_SCB_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_SCB.h and TT_Common.h file version check */
#if (A8V2E_SCB_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_SCB.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_SCB_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_SCB_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_SCB_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_SCB.h and TT_Common.h are different"
#endif
#if ((A8V2E_SCB_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_SCB_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_SCB_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_SCB.h and TT_Common.h are different"
#endif


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_SCB     System Control Block (SCB)
  \brief    Type definitions for the System Control Block Registers
  @{
 */

/**
  \brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  __IM  uint32 CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  __IOM uint32 ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  __IOM uint32 VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  __IOM uint32 AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  __IOM uint32 SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  __IOM uint32 CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  __IOM uint8_t  SHPR[12U];              /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  __IOM uint32 SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  __IOM uint32 CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  __IOM uint32 HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  __IOM uint32 DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  __IOM uint32 MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  __IOM uint32 BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  __IOM uint32 AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  __IM  uint32 ID_PFR[2U];             /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  __IM  uint32 ID_DFR;                 /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  __IM  uint32 ID_AFR;                 /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  __IM  uint32 ID_MFR[4U];             /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  __IM  uint32 ID_ISAR[5U];            /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
        uint32 RESERVED0[1U];
  __IM  uint32 CLIDR;                  /*!< Offset: 0x078 (R/ )  Cache Level ID register */
  __IM  uint32 CTR;                    /*!< Offset: 0x07C (R/ )  Cache Type register */
  __IM  uint32 CCSIDR;                 /*!< Offset: 0x080 (R/ )  Cache Size ID Register */
  __IOM uint32 CSSELR;                 /*!< Offset: 0x084 (R/W)  Cache Size Selection Register */
  __IOM uint32 CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
        uint32 RESERVED3[93U];
  __OM  uint32 STIR;                   /*!< Offset: 0x200 ( /W)  Software Triggered Interrupt Register */
        uint32 RESERVED4[15U];
  __IM  uint32 MVFR0;                  /*!< Offset: 0x240 (R/ )  Media and VFP Feature Register 0 */
  __IM  uint32 MVFR1;                  /*!< Offset: 0x244 (R/ )  Media and VFP Feature Register 1 */
  __IM  uint32 MVFR2;                  /*!< Offset: 0x248 (R/ )  Media and VFP Feature Register 2 */
        uint32 RESERVED5[1U];
  __OM  uint32 ICIALLU;                /*!< Offset: 0x250 ( /W)  I-Cache Invalidate All to PoU */
        uint32 RESERVED6[1U];
  __OM  uint32 ICIMVAU;                /*!< Offset: 0x258 ( /W)  I-Cache Invalidate by MVA to PoU */
  __OM  uint32 DCIMVAC;                /*!< Offset: 0x25C ( /W)  D-Cache Invalidate by MVA to PoC */
  __OM  uint32 DCISW;                  /*!< Offset: 0x260 ( /W)  D-Cache Invalidate by Set-way */
  __OM  uint32 DCCMVAU;                /*!< Offset: 0x264 ( /W)  D-Cache Clean by MVA to PoU */
  __OM  uint32 DCCMVAC;                /*!< Offset: 0x268 ( /W)  D-Cache Clean by MVA to PoC */
  __OM  uint32 DCCSW;                  /*!< Offset: 0x26C ( /W)  D-Cache Clean by Set-way */
  __OM  uint32 DCCIMVAC;               /*!< Offset: 0x270 ( /W)  D-Cache Clean and Invalidate by MVA to PoC */
  __OM  uint32 DCCISW;                 /*!< Offset: 0x274 ( /W)  D-Cache Clean and Invalidate by Set-way */
  __OM  uint32 BPIALL;                 /*!< Offset: 0x278 ( /W)  Branch Predictor Invalidate All */
        uint32 RESERVED7[5U];
  __IOM uint32 ITCMCR;                 /*!< Offset: 0x290 (R/W)  Instruction Tightly-Coupled Memory Control Register */
  __IOM uint32 DTCMCR;                 /*!< Offset: 0x294 (R/W)  Data Tightly-Coupled Memory Control Registers */
  __IOM uint32 AHBPCR;                 /*!< Offset: 0x298 (R/W)  AHBP Control Register */
  __IOM uint32 CACR;                   /*!< Offset: 0x29C (R/W)  L1 Cache Control Register */
  __IOM uint32 AHBSCR;                 /*!< Offset: 0x2A0 (R/W)  AHB Slave Control Register */
        uint32 RESERVED8[1U];
  __IOM uint32 ABFSR;                  /*!< Offset: 0x2A8 (R/W)  Auxiliary Bus Fault Status Register */
} SCB_RegType;

#define     TT_MEM_SRAM_START           0x20100000U
#define     TT_MEM_SRAM_SIZE            0x400000U

/* TODO: Might be moved in a core specific file */
/* SCB CPUID Register Definitions */
#define TT_SCB_CPUID_IMPLEMENTER_Pos          24U                                            /*!< SCB CPUID: IMPLEMENTER Position */
#define TT_SCB_CPUID_IMPLEMENTER_Msk          (0xFFUL << TT_SCB_CPUID_IMPLEMENTER_Pos)          /*!< SCB CPUID: IMPLEMENTER Mask */

#define TT_SCB_CPUID_VARIANT_Pos              20U                                            /*!< SCB CPUID: VARIANT Position */
#define TT_SCB_CPUID_VARIANT_Msk              (0xFUL << TT_SCB_CPUID_VARIANT_Pos)               /*!< SCB CPUID: VARIANT Mask */

#define TT_SCB_CPUID_ARCHITECTURE_Pos         16U                                            /*!< SCB CPUID: ARCHITECTURE Position */
#define TT_SCB_CPUID_ARCHITECTURE_Msk         (0xFUL << TT_SCB_CPUID_ARCHITECTURE_Pos)          /*!< SCB CPUID: ARCHITECTURE Mask */

#define TT_SCB_CPUID_PARTNO_Pos                4U                                            /*!< SCB CPUID: PARTNO Position */
#define TT_SCB_CPUID_PARTNO_Msk               (0xFFFUL << TT_SCB_CPUID_PARTNO_Pos)              /*!< SCB CPUID: PARTNO Mask */

#define TT_SCB_CPUID_REVISION_Pos              0U                                            /*!< SCB CPUID: REVISION Position */
#define TT_SCB_CPUID_REVISION_Msk             (0xFUL /*<< SCB_CPUID_REVISION_Pos*/)          /*!< SCB CPUID: REVISION Mask */

/* SCB Interrupt Control State Register Definitions */
#define TT_SCB_ICSR_NMIPENDSET_Pos            31U                                            /*!< SCB ICSR: NMIPENDSET Position */
#define TT_SCB_ICSR_NMIPENDSET_Msk            (1UL << TT_SCB_ICSR_NMIPENDSET_Pos)               /*!< SCB ICSR: NMIPENDSET Mask */

#define TT_SCB_ICSR_PENDSVSET_Pos             28U                                            /*!< SCB ICSR: PENDSVSET Position */
#define TT_SCB_ICSR_PENDSVSET_Msk             (1UL << TT_SCB_ICSR_PENDSVSET_Pos)                /*!< SCB ICSR: PENDSVSET Mask */

#define TT_SCB_ICSR_PENDSVCLR_Pos             27U                                            /*!< SCB ICSR: PENDSVCLR Position */
#define TT_SCB_ICSR_PENDSVCLR_Msk             (1UL << TT_SCB_ICSR_PENDSVCLR_Pos)                /*!< SCB ICSR: PENDSVCLR Mask */

#define TT_SCB_ICSR_PENDSTSET_Pos             26U                                            /*!< SCB ICSR: PENDSTSET Position */
#define TT_SCB_ICSR_PENDSTSET_Msk             (1UL << TT_SCB_ICSR_PENDSTSET_Pos)                /*!< SCB ICSR: PENDSTSET Mask */

#define TT_SCB_ICSR_PENDSTCLR_Pos             25U                                            /*!< SCB ICSR: PENDSTCLR Position */
#define TT_SCB_ICSR_PENDSTCLR_Msk             (1UL << TT_SCB_ICSR_PENDSTCLR_Pos)                /*!< SCB ICSR: PENDSTCLR Mask */

#define TT_SCB_ICSR_ISRPREEMPT_Pos            23U                                            /*!< SCB ICSR: ISRPREEMPT Position */
#define TT_SCB_ICSR_ISRPREEMPT_Msk            (1UL << TT_SCB_ICSR_ISRPREEMPT_Pos)               /*!< SCB ICSR: ISRPREEMPT Mask */

#define TT_SCB_ICSR_ISRPENDING_Pos            22U                                            /*!< SCB ICSR: ISRPENDING Position */
#define TT_SCB_ICSR_ISRPENDING_Msk            (1UL << TT_SCB_ICSR_ISRPENDING_Pos)               /*!< SCB ICSR: ISRPENDING Mask */

#define TT_SCB_ICSR_VECTPENDING_Pos           12U                                            /*!< SCB ICSR: VECTPENDING Position */
#define TT_SCB_ICSR_VECTPENDING_Msk           (0x1FFUL << TT_SCB_ICSR_VECTPENDING_Pos)          /*!< SCB ICSR: VECTPENDING Mask */

#define TT_SCB_ICSR_RETTOBASE_Pos             11U                                            /*!< SCB ICSR: RETTOBASE Position */
#define TT_SCB_ICSR_RETTOBASE_Msk             (1UL << TT_SCB_ICSR_RETTOBASE_Pos)                /*!< SCB ICSR: RETTOBASE Mask */

#define TT_SCB_ICSR_VECTACTIVE_Pos             0U                                            /*!< SCB ICSR: VECTACTIVE Position */
#define TT_SCB_ICSR_VECTACTIVE_Msk            (0x1FFUL /*<< SCB_ICSR_VECTACTIVE_Pos*/)       /*!< SCB ICSR: VECTACTIVE Mask */

/* SCB Vector Table Offset Register Definitions */
#define TT_SCB_VTOR_TBLOFF_Pos                 7U                                            /*!< SCB VTOR: TBLOFF Position */
#define TT_SCB_VTOR_TBLOFF_Msk                (0x1FFFFFFUL << TT_SCB_VTOR_TBLOFF_Pos)           /*!< SCB VTOR: TBLOFF Mask */

/* SCB Application Interrupt and Reset Control Register Definitions */
#define TT_SCB_AIRCR_VECTKEY_Pos              16U                                            /*!< SCB AIRCR: VECTKEY Position */
#define TT_SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << TT_SCB_AIRCR_VECTKEY_Pos)            /*!< SCB AIRCR: VECTKEY Mask */

#define TT_SCB_AIRCR_VECTKEYSTAT_Pos          16U                                            /*!< SCB AIRCR: VECTKEYSTAT Position */
#define TT_SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFUL << TT_SCB_AIRCR_VECTKEYSTAT_Pos)        /*!< SCB AIRCR: VECTKEYSTAT Mask */

#define TT_SCB_AIRCR_ENDIANESS_Pos            15U                                            /*!< SCB AIRCR: ENDIANESS Position */
#define TT_SCB_AIRCR_ENDIANESS_Msk            (1UL << TT_SCB_AIRCR_ENDIANESS_Pos)               /*!< SCB AIRCR: ENDIANESS Mask */

#define TT_SCB_AIRCR_PRIGROUP_Pos              8U                                            /*!< SCB AIRCR: PRIGROUP Position */
#define TT_SCB_AIRCR_PRIGROUP_Msk             (7UL << TT_SCB_AIRCR_PRIGROUP_Pos)                /*!< SCB AIRCR: PRIGROUP Mask */

#define TT_SCB_AIRCR_SYSRESETREQ_Pos           2U                                            /*!< SCB AIRCR: SYSRESETREQ Position */
#define TT_SCB_AIRCR_SYSRESETREQ_Msk          (1UL << TT_SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ Mask */

#define TT_SCB_AIRCR_VECTCLRACTIVE_Pos         1U                                            /*!< SCB AIRCR: VECTCLRACTIVE Position */
#define TT_SCB_AIRCR_VECTCLRACTIVE_Msk        (1UL << TT_SCB_AIRCR_VECTCLRACTIVE_Pos)           /*!< SCB AIRCR: VECTCLRACTIVE Mask */

#define TT_SCB_AIRCR_VECTRESET_Pos             0U                                            /*!< SCB AIRCR: VECTRESET Position */
#define TT_SCB_AIRCR_VECTRESET_Msk            (1UL /*<< SCB_AIRCR_VECTRESET_Pos*/)           /*!< SCB AIRCR: VECTRESET Mask */

/* SCB System Control Register Definitions */
#define TT_SCB_SCR_SEVONPEND_Pos               4U                                            /*!< SCB SCR: SEVONPEND Position */
#define TT_SCB_SCR_SEVONPEND_Msk              (1UL << TT_SCB_SCR_SEVONPEND_Pos)                 /*!< SCB SCR: SEVONPEND Mask */

#define TT_SCB_SCR_SLEEPDEEP_Pos               2U                                            /*!< SCB SCR: SLEEPDEEP Position */
#define TT_SCB_SCR_SLEEPDEEP_Msk              (1UL << TT_SCB_SCR_SLEEPDEEP_Pos)                 /*!< SCB SCR: SLEEPDEEP Mask */

#define TT_SCB_SCR_SLEEPONEXIT_Pos             1U                                            /*!< SCB SCR: SLEEPONEXIT Position */
#define TT_SCB_SCR_SLEEPONEXIT_Msk            (1UL << TT_SCB_SCR_SLEEPONEXIT_Pos)               /*!< SCB SCR: SLEEPONEXIT Mask */

/* SCB Configuration Control Register Definitions */
#define TT_SCB_CCR_BP_Pos                      18U                                           /*!< SCB CCR: Branch prediction enable bit Position */
#define TT_SCB_CCR_BP_Msk                     (1UL << TT_SCB_CCR_BP_Pos)                        /*!< SCB CCR: Branch prediction enable bit Mask */

#define TT_SCB_CCR_IC_Pos                      17U                                           /*!< SCB CCR: Instruction cache enable bit Position */
#define TT_SCB_CCR_IC_Msk                     (1UL << TT_SCB_CCR_IC_Pos)                        /*!< SCB CCR: Instruction cache enable bit Mask */

#define TT_SCB_CCR_DC_Pos                      16U                                           /*!< SCB CCR: Cache enable bit Position */
#define TT_SCB_CCR_DC_Msk                     (1UL << TT_SCB_CCR_DC_Pos)                        /*!< SCB CCR: Cache enable bit Mask */

#define TT_SCB_CCR_STKALIGN_Pos                9U                                            /*!< SCB CCR: STKALIGN Position */
#define TT_SCB_CCR_STKALIGN_Msk               (1UL << TT_SCB_CCR_STKALIGN_Pos)                  /*!< SCB CCR: STKALIGN Mask */

#define TT_SCB_CCR_BFHFNMIGN_Pos               8U                                            /*!< SCB CCR: BFHFNMIGN Position */
#define TT_SCB_CCR_BFHFNMIGN_Msk              (1UL << TT_SCB_CCR_BFHFNMIGN_Pos)                 /*!< SCB CCR: BFHFNMIGN Mask */

#define TT_SCB_CCR_DIV_0_TRP_Pos               4U                                            /*!< SCB CCR: DIV_0_TRP Position */
#define TT_SCB_CCR_DIV_0_TRP_Msk              (1UL << TT_SCB_CCR_DIV_0_TRP_Pos)                 /*!< SCB CCR: DIV_0_TRP Mask */

#define TT_SCB_CCR_UNALIGN_TRP_Pos             3U                                            /*!< SCB CCR: UNALIGN_TRP Position */
#define TT_SCB_CCR_UNALIGN_TRP_Msk            (1UL << TT_SCB_CCR_UNALIGN_TRP_Pos)               /*!< SCB CCR: UNALIGN_TRP Mask */

#define TT_SCB_CCR_USERSETMPEND_Pos            1U                                            /*!< SCB CCR: USERSETMPEND Position */
#define TT_SCB_CCR_USERSETMPEND_Msk           (1UL << TT_SCB_CCR_USERSETMPEND_Pos)              /*!< SCB CCR: USERSETMPEND Mask */

#define TT_SCB_CCR_NONBASETHRDENA_Pos          0U                                            /*!< SCB CCR: NONBASETHRDENA Position */
#define TT_SCB_CCR_NONBASETHRDENA_Msk         (1UL /*<< SCB_CCR_NONBASETHRDENA_Pos*/)        /*!< SCB CCR: NONBASETHRDENA Mask */

/* SCB System Handler Control and State Register Definitions */
#define TT_SCB_SHCSR_USGFAULTENA_Pos          18U                                            /*!< SCB SHCSR: USGFAULTENA Position */
#define TT_SCB_SHCSR_USGFAULTENA_Msk          (1UL << TT_SCB_SHCSR_USGFAULTENA_Pos)             /*!< SCB SHCSR: USGFAULTENA Mask */

#define TT_SCB_SHCSR_BUSFAULTENA_Pos          17U                                            /*!< SCB SHCSR: BUSFAULTENA Position */
#define TT_SCB_SHCSR_BUSFAULTENA_Msk          (1UL << TT_SCB_SHCSR_BUSFAULTENA_Pos)             /*!< SCB SHCSR: BUSFAULTENA Mask */

#define TT_SCB_SHCSR_MEMFAULTENA_Pos          16U                                            /*!< SCB SHCSR: MEMFAULTENA Position */
#define TT_SCB_SHCSR_MEMFAULTENA_Msk          (1UL << TT_SCB_SHCSR_MEMFAULTENA_Pos)             /*!< SCB SHCSR: MEMFAULTENA Mask */

#define TT_SCB_SHCSR_SVCALLPENDED_Pos         15U                                            /*!< SCB SHCSR: SVCALLPENDED Position */
#define TT_SCB_SHCSR_SVCALLPENDED_Msk         (1UL << TT_SCB_SHCSR_SVCALLPENDED_Pos)            /*!< SCB SHCSR: SVCALLPENDED Mask */

#define TT_SCB_SHCSR_BUSFAULTPENDED_Pos       14U                                            /*!< SCB SHCSR: BUSFAULTPENDED Position */
#define TT_SCB_SHCSR_BUSFAULTPENDED_Msk       (1UL << TT_SCB_SHCSR_BUSFAULTPENDED_Pos)          /*!< SCB SHCSR: BUSFAULTPENDED Mask */

#define TT_SCB_SHCSR_MEMFAULTPENDED_Pos       13U                                            /*!< SCB SHCSR: MEMFAULTPENDED Position */
#define TT_SCB_SHCSR_MEMFAULTPENDED_Msk       (1UL << TT_SCB_SHCSR_MEMFAULTPENDED_Pos)          /*!< SCB SHCSR: MEMFAULTPENDED Mask */

#define TT_SCB_SHCSR_USGFAULTPENDED_Pos       12U                                            /*!< SCB SHCSR: USGFAULTPENDED Position */
#define TT_SCB_SHCSR_USGFAULTPENDED_Msk       (1UL << TT_SCB_SHCSR_USGFAULTPENDED_Pos)          /*!< SCB SHCSR: USGFAULTPENDED Mask */

#define TT_SCB_SHCSR_SYSTICKACT_Pos           11U                                            /*!< SCB SHCSR: SYSTICKACT Position */
#define TT_SCB_SHCSR_SYSTICKACT_Msk           (1UL << TT_SCB_SHCSR_SYSTICKACT_Pos)              /*!< SCB SHCSR: SYSTICKACT Mask */

#define TT_SCB_SHCSR_PENDSVACT_Pos            10U                                            /*!< SCB SHCSR: PENDSVACT Position */
#define TT_SCB_SHCSR_PENDSVACT_Msk            (1UL << TT_SCB_SHCSR_PENDSVACT_Pos)               /*!< SCB SHCSR: PENDSVACT Mask */

#define TT_SCB_SHCSR_MONITORACT_Pos            8U                                            /*!< SCB SHCSR: MONITORACT Position */
#define TT_SCB_SHCSR_MONITORACT_Msk           (1UL << TT_SCB_SHCSR_MONITORACT_Pos)              /*!< SCB SHCSR: MONITORACT Mask */

#define TT_SCB_SHCSR_SVCALLACT_Pos             7U                                            /*!< SCB SHCSR: SVCALLACT Position */
#define TT_SCB_SHCSR_SVCALLACT_Msk            (1UL << TT_SCB_SHCSR_SVCALLACT_Pos)               /*!< SCB SHCSR: SVCALLACT Mask */

#define TT_SCB_SHCSR_USGFAULTACT_Pos           3U                                            /*!< SCB SHCSR: USGFAULTACT Position */
#define TT_SCB_SHCSR_USGFAULTACT_Msk          (1UL << TT_SCB_SHCSR_USGFAULTACT_Pos)             /*!< SCB SHCSR: USGFAULTACT Mask */

#define TT_SCB_SHCSR_BUSFAULTACT_Pos           1U                                            /*!< SCB SHCSR: BUSFAULTACT Position */
#define TT_SCB_SHCSR_BUSFAULTACT_Msk          (1UL << TT_SCB_SHCSR_BUSFAULTACT_Pos)             /*!< SCB SHCSR: BUSFAULTACT Mask */

#define TT_SCB_SHCSR_MEMFAULTACT_Pos           0U                                            /*!< SCB SHCSR: MEMFAULTACT Position */
#define TT_SCB_SHCSR_MEMFAULTACT_Msk          (1UL /*<< SCB_SHCSR_MEMFAULTACT_Pos*/)         /*!< SCB SHCSR: MEMFAULTACT Mask */

/* SCB Configurable Fault Status Register Definitions */
#define TT_SCB_CFSR_USGFAULTSR_Pos            16U                                            /*!< SCB CFSR: Usage Fault Status Register Position */
#define TT_SCB_CFSR_USGFAULTSR_Msk            (0xFFFFUL << TT_SCB_CFSR_USGFAULTSR_Pos)          /*!< SCB CFSR: Usage Fault Status Register Mask */

#define TT_SCB_CFSR_BUSFAULTSR_Pos             8U                                            /*!< SCB CFSR: Bus Fault Status Register Position */
#define TT_SCB_CFSR_BUSFAULTSR_Msk            (0xFFUL << TT_SCB_CFSR_BUSFAULTSR_Pos)            /*!< SCB CFSR: Bus Fault Status Register Mask */

#define TT_SCB_CFSR_MEMFAULTSR_Pos             0U                                            /*!< SCB CFSR: Memory Manage Fault Status Register Position */
#define TT_SCB_CFSR_MEMFAULTSR_Msk            (0xFFUL /*<< SCB_CFSR_MEMFAULTSR_Pos*/)        /*!< SCB CFSR: Memory Manage Fault Status Register Mask */

/* MemManage Fault Status Register (part of SCB Configurable Fault Status Register) */
#define TT_SCB_CFSR_MMARVALID_Pos             (TT_SCB_SHCSR_MEMFAULTACT_Pos + 7U)               /*!< SCB CFSR (MMFSR): MMARVALID Position */
#define TT_SCB_CFSR_MMARVALID_Msk             (1UL << TT_SCB_CFSR_MMARVALID_Pos)                /*!< SCB CFSR (MMFSR): MMARVALID Mask */

#define TT_SCB_CFSR_MLSPERR_Pos               (TT_SCB_SHCSR_MEMFAULTACT_Pos + 5U)               /*!< SCB CFSR (MMFSR): MLSPERR Position */
#define TT_SCB_CFSR_MLSPERR_Msk               (1UL << TT_SCB_CFSR_MLSPERR_Pos)                  /*!< SCB CFSR (MMFSR): MLSPERR Mask */

#define TT_SCB_CFSR_MSTKERR_Pos               (TT_SCB_SHCSR_MEMFAULTACT_Pos + 4U)               /*!< SCB CFSR (MMFSR): MSTKERR Position */
#define TT_SCB_CFSR_MSTKERR_Msk               (1UL << TT_SCB_CFSR_MSTKERR_Pos)                  /*!< SCB CFSR (MMFSR): MSTKERR Mask */

#define TT_SCB_CFSR_MUNSTKERR_Pos             (TT_SCB_SHCSR_MEMFAULTACT_Pos + 3U)               /*!< SCB CFSR (MMFSR): MUNSTKERR Position */
#define TT_SCB_CFSR_MUNSTKERR_Msk             (1UL << TT_SCB_CFSR_MUNSTKERR_Pos)                /*!< SCB CFSR (MMFSR): MUNSTKERR Mask */

#define TT_SCB_CFSR_DACCVIOL_Pos              (TT_SCB_SHCSR_MEMFAULTACT_Pos + 1U)               /*!< SCB CFSR (MMFSR): DACCVIOL Position */
#define TT_SCB_CFSR_DACCVIOL_Msk              (1UL << TT_SCB_CFSR_DACCVIOL_Pos)                 /*!< SCB CFSR (MMFSR): DACCVIOL Mask */

#define TT_SCB_CFSR_IACCVIOL_Pos              (TT_SCB_SHCSR_MEMFAULTACT_Pos + 0U)               /*!< SCB CFSR (MMFSR): IACCVIOL Position */
#define TT_SCB_CFSR_IACCVIOL_Msk              (1UL /*<< SCB_CFSR_IACCVIOL_Pos*/)             /*!< SCB CFSR (MMFSR): IACCVIOL Mask */

/* BusFault Status Register (part of SCB Configurable Fault Status Register) */
#define TT_SCB_CFSR_BFARVALID_Pos            (TT_SCB_CFSR_BUSFAULTSR_Pos + 7U)                  /*!< SCB CFSR (BFSR): BFARVALID Position */
#define TT_SCB_CFSR_BFARVALID_Msk            (1UL << TT_SCB_CFSR_BFARVALID_Pos)                 /*!< SCB CFSR (BFSR): BFARVALID Mask */

#define TT_SCB_CFSR_LSPERR_Pos               (TT_SCB_CFSR_BUSFAULTSR_Pos + 5U)                  /*!< SCB CFSR (BFSR): LSPERR Position */
#define TT_SCB_CFSR_LSPERR_Msk               (1UL << TT_SCB_CFSR_LSPERR_Pos)                    /*!< SCB CFSR (BFSR): LSPERR Mask */

#define TT_SCB_CFSR_STKERR_Pos               (TT_SCB_CFSR_BUSFAULTSR_Pos + 4U)                  /*!< SCB CFSR (BFSR): STKERR Position */
#define TT_SCB_CFSR_STKERR_Msk               (1UL << TT_SCB_CFSR_STKERR_Pos)                    /*!< SCB CFSR (BFSR): STKERR Mask */

#define TT_SCB_CFSR_UNSTKERR_Pos             (TT_SCB_CFSR_BUSFAULTSR_Pos + 3U)                  /*!< SCB CFSR (BFSR): UNSTKERR Position */
#define TT_SCB_CFSR_UNSTKERR_Msk             (1UL << TT_SCB_CFSR_UNSTKERR_Pos)                  /*!< SCB CFSR (BFSR): UNSTKERR Mask */

#define TT_SCB_CFSR_IMPRECISERR_Pos          (TT_SCB_CFSR_BUSFAULTSR_Pos + 2U)                  /*!< SCB CFSR (BFSR): IMPRECISERR Position */
#define TT_SCB_CFSR_IMPRECISERR_Msk          (1UL << TT_SCB_CFSR_IMPRECISERR_Pos)               /*!< SCB CFSR (BFSR): IMPRECISERR Mask */

#define TT_SCB_CFSR_PRECISERR_Pos            (TT_SCB_CFSR_BUSFAULTSR_Pos + 1U)                  /*!< SCB CFSR (BFSR): PRECISERR Position */
#define TT_SCB_CFSR_PRECISERR_Msk            (1UL << TT_SCB_CFSR_PRECISERR_Pos)                 /*!< SCB CFSR (BFSR): PRECISERR Mask */

#define TT_SCB_CFSR_IBUSERR_Pos              (TT_SCB_CFSR_BUSFAULTSR_Pos + 0U)                  /*!< SCB CFSR (BFSR): IBUSERR Position */
#define TT_SCB_CFSR_IBUSERR_Msk              (1UL << TT_SCB_CFSR_IBUSERR_Pos)                   /*!< SCB CFSR (BFSR): IBUSERR Mask */

/* UsageFault Status Register (part of SCB Configurable Fault Status Register) */
#define TT_SCB_CFSR_DIVBYZERO_Pos            (TT_SCB_CFSR_USGFAULTSR_Pos + 9U)                  /*!< SCB CFSR (UFSR): DIVBYZERO Position */
#define TT_SCB_CFSR_DIVBYZERO_Msk            (1UL << TT_SCB_CFSR_DIVBYZERO_Pos)                 /*!< SCB CFSR (UFSR): DIVBYZERO Mask */

#define TT_SCB_CFSR_UNALIGNED_Pos            (TT_SCB_CFSR_USGFAULTSR_Pos + 8U)                  /*!< SCB CFSR (UFSR): UNALIGNED Position */
#define TT_SCB_CFSR_UNALIGNED_Msk            (1UL << TT_SCB_CFSR_UNALIGNED_Pos)                 /*!< SCB CFSR (UFSR): UNALIGNED Mask */

#define TT_SCB_CFSR_NOCP_Pos                 (TT_SCB_CFSR_USGFAULTSR_Pos + 3U)                  /*!< SCB CFSR (UFSR): NOCP Position */
#define TT_SCB_CFSR_NOCP_Msk                 (1UL << TT_SCB_CFSR_NOCP_Pos)                      /*!< SCB CFSR (UFSR): NOCP Mask */

#define TT_SCB_CFSR_INVPC_Pos                (TT_SCB_CFSR_USGFAULTSR_Pos + 2U)                  /*!< SCB CFSR (UFSR): INVPC Position */
#define TT_SCB_CFSR_INVPC_Msk                (1UL << TT_SCB_CFSR_INVPC_Pos)                     /*!< SCB CFSR (UFSR): INVPC Mask */

#define TT_SCB_CFSR_INVSTATE_Pos             (TT_SCB_CFSR_USGFAULTSR_Pos + 1U)                  /*!< SCB CFSR (UFSR): INVSTATE Position */
#define TT_SCB_CFSR_INVSTATE_Msk             (1UL << TT_SCB_CFSR_INVSTATE_Pos)                  /*!< SCB CFSR (UFSR): INVSTATE Mask */

#define TT_SCB_CFSR_UNDEFINSTR_Pos           (TT_SCB_CFSR_USGFAULTSR_Pos + 0U)                  /*!< SCB CFSR (UFSR): UNDEFINSTR Position */
#define TT_SCB_CFSR_UNDEFINSTR_Msk           (1UL << TT_SCB_CFSR_UNDEFINSTR_Pos)                /*!< SCB CFSR (UFSR): UNDEFINSTR Mask */

/* SCB Hard Fault Status Register Definitions */
#define TT_SCB_HFSR_DEBUGEVT_Pos              31U                                            /*!< SCB HFSR: DEBUGEVT Position */
#define TT_SCB_HFSR_DEBUGEVT_Msk              (1UL << TT_SCB_HFSR_DEBUGEVT_Pos)                 /*!< SCB HFSR: DEBUGEVT Mask */

#define TT_SCB_HFSR_FORCED_Pos                30U                                            /*!< SCB HFSR: FORCED Position */
#define TT_SCB_HFSR_FORCED_Msk                (1UL << TT_SCB_HFSR_FORCED_Pos)                   /*!< SCB HFSR: FORCED Mask */

#define TT_SCB_HFSR_VECTTBL_Pos                1U                                            /*!< SCB HFSR: VECTTBL Position */
#define TT_SCB_HFSR_VECTTBL_Msk               (1UL << TT_SCB_HFSR_VECTTBL_Pos)                  /*!< SCB HFSR: VECTTBL Mask */

/* SCB Debug Fault Status Register Definitions */
#define TT_SCB_DFSR_EXTERNAL_Pos               4U                                            /*!< SCB DFSR: EXTERNAL Position */
#define TT_SCB_DFSR_EXTERNAL_Msk              (1UL << TT_SCB_DFSR_EXTERNAL_Pos)                 /*!< SCB DFSR: EXTERNAL Mask */

#define TT_SCB_DFSR_VCATCH_Pos                 3U                                            /*!< SCB DFSR: VCATCH Position */
#define TT_SCB_DFSR_VCATCH_Msk                (1UL << TT_SCB_DFSR_VCATCH_Pos)                   /*!< SCB DFSR: VCATCH Mask */

#define TT_SCB_DFSR_DWTTRAP_Pos                2U                                            /*!< SCB DFSR: DWTTRAP Position */
#define TT_SCB_DFSR_DWTTRAP_Msk               (1UL << TT_SCB_DFSR_DWTTRAP_Pos)                  /*!< SCB DFSR: DWTTRAP Mask */

#define TT_SCB_DFSR_BKPT_Pos                   1U                                            /*!< SCB DFSR: BKPT Position */
#define TT_SCB_DFSR_BKPT_Msk                  (1UL << TT_SCB_DFSR_BKPT_Pos)                     /*!< SCB DFSR: BKPT Mask */

#define TT_SCB_DFSR_HALTED_Pos                 0U                                            /*!< SCB DFSR: HALTED Position */
#define TT_SCB_DFSR_HALTED_Msk                (1UL /*<< SCB_DFSR_HALTED_Pos*/)               /*!< SCB DFSR: HALTED Mask */

/* SCB Cache Level ID Register Definitions */
#define TT_SCB_CLIDR_LOUU_Pos                 27U                                            /*!< SCB CLIDR: LoUU Position */
#define TT_SCB_CLIDR_LOUU_Msk                 (7UL << TT_SCB_CLIDR_LOUU_Pos)                    /*!< SCB CLIDR: LoUU Mask */

#define TT_SCB_CLIDR_LOC_Pos                  24U                                            /*!< SCB CLIDR: LoC Position */
#define TT_SCB_CLIDR_LOC_Msk                  (7UL << TT_SCB_CLIDR_LOC_Pos)                     /*!< SCB CLIDR: LoC Mask */

/* SCB Cache Type Register Definitions */
#define TT_SCB_CTR_FORMAT_Pos                 29U                                            /*!< SCB CTR: Format Position */
#define TT_SCB_CTR_FORMAT_Msk                 (7UL << TT_SCB_CTR_FORMAT_Pos)                    /*!< SCB CTR: Format Mask */

#define TT_SCB_CTR_CWG_Pos                    24U                                            /*!< SCB CTR: CWG Position */
#define TT_SCB_CTR_CWG_Msk                    (0xFUL << TT_SCB_CTR_CWG_Pos)                     /*!< SCB CTR: CWG Mask */

#define TT_SCB_CTR_ERG_Pos                    20U                                            /*!< SCB CTR: ERG Position */
#define TT_SCB_CTR_ERG_Msk                    (0xFUL << TT_SCB_CTR_ERG_Pos)                     /*!< SCB CTR: ERG Mask */

#define TT_SCB_CTR_DMINLINE_Pos               16U                                            /*!< SCB CTR: DminLine Position */
#define TT_SCB_CTR_DMINLINE_Msk               (0xFUL << TT_SCB_CTR_DMINLINE_Pos)                /*!< SCB CTR: DminLine Mask */

#define TT_SCB_CTR_IMINLINE_Pos                0U                                            /*!< SCB CTR: ImInLine Position */
#define TT_SCB_CTR_IMINLINE_Msk               (0xFUL /*<< SCB_CTR_IMINLINE_Pos*/)            /*!< SCB CTR: ImInLine Mask */

/* SCB Cache Size ID Register Definitions */
#define TT_SCB_CCSIDR_WT_Pos                  31U                                            /*!< SCB CCSIDR: WT Position */
#define TT_SCB_CCSIDR_WT_Msk                  (1UL << TT_SCB_CCSIDR_WT_Pos)                     /*!< SCB CCSIDR: WT Mask */

#define TT_SCB_CCSIDR_WB_Pos                  30U                                            /*!< SCB CCSIDR: WB Position */
#define TT_SCB_CCSIDR_WB_Msk                  (1UL << TT_SCB_CCSIDR_WB_Pos)                     /*!< SCB CCSIDR: WB Mask */

#define TT_SCB_CCSIDR_RA_Pos                  29U                                            /*!< SCB CCSIDR: RA Position */
#define TT_SCB_CCSIDR_RA_Msk                  (1UL << TT_SCB_CCSIDR_RA_Pos)                     /*!< SCB CCSIDR: RA Mask */

#define TT_SCB_CCSIDR_WA_Pos                  28U                                            /*!< SCB CCSIDR: WA Position */
#define TT_SCB_CCSIDR_WA_Msk                  (1UL << TT_SCB_CCSIDR_WA_Pos)                     /*!< SCB CCSIDR: WA Mask */

#define TT_SCB_CCSIDR_NUMSETS_Pos             13U                                            /*!< SCB CCSIDR: NumSets Position */
#define TT_SCB_CCSIDR_NUMSETS_Msk             (0x7FFFUL << TT_SCB_CCSIDR_NUMSETS_Pos)           /*!< SCB CCSIDR: NumSets Mask */

#define TT_SCB_CCSIDR_ASSOCIATIVITY_Pos        3U                                            /*!< SCB CCSIDR: Associativity Position */
#define TT_SCB_CCSIDR_ASSOCIATIVITY_Msk       (0x3FFUL << TT_SCB_CCSIDR_ASSOCIATIVITY_Pos)      /*!< SCB CCSIDR: Associativity Mask */

#define TT_SCB_CCSIDR_LINESIZE_Pos             0U                                            /*!< SCB CCSIDR: LineSize Position */
#define TT_SCB_CCSIDR_LINESIZE_Msk            (7UL /*<< SCB_CCSIDR_LINESIZE_Pos*/)           /*!< SCB CCSIDR: LineSize Mask */

/* SCB Cache Size Selection Register Definitions */
#define TT_SCB_CSSELR_LEVEL_Pos                1U                                            /*!< SCB CSSELR: Level Position */
#define TT_SCB_CSSELR_LEVEL_Msk               (7UL << TT_SCB_CSSELR_LEVEL_Pos)                  /*!< SCB CSSELR: Level Mask */

#define TT_SCB_CSSELR_IND_Pos                  0U                                            /*!< SCB CSSELR: InD Position */
#define TT_SCB_CSSELR_IND_Msk                 (1UL /*<< SCB_CSSELR_IND_Pos*/)                /*!< SCB CSSELR: InD Mask */

/* SCB Software Triggered Interrupt Register Definitions */
#define TT_SCB_STIR_INTID_Pos                  0U                                            /*!< SCB STIR: INTID Position */
#define TT_SCB_STIR_INTID_Msk                 (0x1FFUL /*<< SCB_STIR_INTID_Pos*/)            /*!< SCB STIR: INTID Mask */

/* SCB D-Cache Invalidate by Set-way Register Definitions */
#define TT_SCB_DCISW_WAY_Pos                  30U                                            /*!< SCB DCISW: Way Position */
#define TT_SCB_DCISW_WAY_Msk                  (3UL << TT_SCB_DCISW_WAY_Pos)                     /*!< SCB DCISW: Way Mask */

#define TT_SCB_DCISW_SET_Pos                   5U                                            /*!< SCB DCISW: Set Position */
#define TT_SCB_DCISW_SET_Msk                  (0x1FFUL << TT_SCB_DCISW_SET_Pos)                 /*!< SCB DCISW: Set Mask */

/* SCB D-Cache Clean by Set-way Register Definitions */
#define TT_SCB_DCCSW_WAY_Pos                  30U                                            /*!< SCB DCCSW: Way Position */
#define TT_SCB_DCCSW_WAY_Msk                  (3UL << TT_SCB_DCCSW_WAY_Pos)                     /*!< SCB DCCSW: Way Mask */

#define TT_SCB_DCCSW_SET_Pos                   5U                                            /*!< SCB DCCSW: Set Position */
#define TT_SCB_DCCSW_SET_Msk                  (0x1FFUL << TT_SCB_DCCSW_SET_Pos)                 /*!< SCB DCCSW: Set Mask */

/* SCB D-Cache Clean and Invalidate by Set-way Register Definitions */
#define TT_SCB_DCCISW_WAY_Pos                 30U                                            /*!< SCB DCCISW: Way Position */
#define TT_SCB_DCCISW_WAY_Msk                 (3UL << TT_SCB_DCCISW_WAY_Pos)                    /*!< SCB DCCISW: Way Mask */

#define TT_SCB_DCCISW_SET_Pos                  5U                                            /*!< SCB DCCISW: Set Position */
#define TT_SCB_DCCISW_SET_Msk                 (0x1FFUL << TT_SCB_DCCISW_SET_Pos)                /*!< SCB DCCISW: Set Mask */

/* Instruction Tightly-Coupled Memory Control Register Definitions */
#define TT_SCB_ITCMCR_SZ_Pos                   3U                                            /*!< SCB ITCMCR: SZ Position */
#define TT_SCB_ITCMCR_SZ_Msk                  (0xFUL << TT_SCB_ITCMCR_SZ_Pos)                   /*!< SCB ITCMCR: SZ Mask */

#define TT_SCB_ITCMCR_RETEN_Pos                2U                                            /*!< SCB ITCMCR: RETEN Position */
#define TT_SCB_ITCMCR_RETEN_Msk               (1UL << TT_SCB_ITCMCR_RETEN_Pos)                  /*!< SCB ITCMCR: RETEN Mask */

#define TT_SCB_ITCMCR_RMW_Pos                  1U                                            /*!< SCB ITCMCR: RMW Position */
#define TT_SCB_ITCMCR_RMW_Msk                 (1UL << TT_SCB_ITCMCR_RMW_Pos)                    /*!< SCB ITCMCR: RMW Mask */

#define TT_SCB_ITCMCR_EN_Pos                   0U                                            /*!< SCB ITCMCR: EN Position */
#define TT_SCB_ITCMCR_EN_Msk                  (1UL /*<< SCB_ITCMCR_EN_Pos*/)                 /*!< SCB ITCMCR: EN Mask */

/* Data Tightly-Coupled Memory Control Register Definitions */
#define TT_SCB_DTCMCR_SZ_Pos                   3U                                            /*!< SCB DTCMCR: SZ Position */
#define TT_SCB_DTCMCR_SZ_Msk                  (0xFUL << TT_SCB_DTCMCR_SZ_Pos)                   /*!< SCB DTCMCR: SZ Mask */

#define TT_SCB_DTCMCR_RETEN_Pos                2U                                            /*!< SCB DTCMCR: RETEN Position */
#define TT_SCB_DTCMCR_RETEN_Msk               (1UL << TT_SCB_DTCMCR_RETEN_Pos)                   /*!< SCB DTCMCR: RETEN Mask */

#define TT_SCB_DTCMCR_RMW_Pos                  1U                                            /*!< SCB DTCMCR: RMW Position */
#define TT_SCB_DTCMCR_RMW_Msk                 (1UL << TT_SCB_DTCMCR_RMW_Pos)                    /*!< SCB DTCMCR: RMW Mask */

#define TT_SCB_DTCMCR_EN_Pos                   0U                                            /*!< SCB DTCMCR: EN Position */
#define TT_SCB_DTCMCR_EN_Msk                  (1UL /*<< SCB_DTCMCR_EN_Pos*/)                 /*!< SCB DTCMCR: EN Mask */

/* AHBP Control Register Definitions */
#define TT_SCB_AHBPCR_SZ_Pos                   1U                                            /*!< SCB AHBPCR: SZ Position */
#define TT_SCB_AHBPCR_SZ_Msk                  (7UL << TT_SCB_AHBPCR_SZ_Pos)                     /*!< SCB AHBPCR: SZ Mask */

#define TT_SCB_AHBPCR_EN_Pos                   0U                                            /*!< SCB AHBPCR: EN Position */
#define TT_SCB_AHBPCR_EN_Msk                  (1UL /*<< SCB_AHBPCR_EN_Pos*/)                 /*!< SCB AHBPCR: EN Mask */

/* L1 Cache Control Register Definitions */
#define TT_SCB_CACR_FORCEWT_Pos                2U                                            /*!< SCB CACR: FORCEWT Position */
#define TT_SCB_CACR_FORCEWT_Msk               (1UL << TT_SCB_CACR_FORCEWT_Pos)                  /*!< SCB CACR: FORCEWT Mask */

#define TT_SCB_CACR_ECCEN_Pos                  1U                                            /*!< SCB CACR: ECCEN Position */
#define TT_SCB_CACR_ECCEN_Msk                 (1UL << TT_SCB_CACR_ECCEN_Pos)                    /*!< SCB CACR: ECCEN Mask */

#define TT_SCB_CACR_ECCDIS_Pos                 1U                                            /*!< SCB CACR: ECCDIS Position */
#define TT_SCB_CACR_ECCDIS_Msk                (1UL << TT_SCB_CACR_ECCDIS_Pos)                   /*!< SCB CACR: ECCDIS Mask */

#define TT_SCB_CACR_SIWT_Pos                   0U                                            /*!< SCB CACR: SIWT Position */
#define TT_SCB_CACR_SIWT_Msk                  (1UL /*<< SCB_CACR_SIWT_Pos*/)                 /*!< SCB CACR: SIWT Mask */

/* AHBS Control Register Definitions */
#define TT_SCB_AHBSCR_INITCOUNT_Pos           11U                                            /*!< SCB AHBSCR: INITCOUNT Position */
#define TT_SCB_AHBSCR_INITCOUNT_Msk           (0x1FUL << TT_SCB_AHBPCR_INITCOUNT_Pos)           /*!< SCB AHBSCR: INITCOUNT Mask */

#define TT_SCB_AHBSCR_TPRI_Pos                 2U                                            /*!< SCB AHBSCR: TPRI Position */
#define TT_SCB_AHBSCR_TPRI_Msk                (0x1FFUL << TT_SCB_AHBPCR_TPRI_Pos)               /*!< SCB AHBSCR: TPRI Mask */

#define TT_SCB_AHBSCR_CTL_Pos                  0U                                            /*!< SCB AHBSCR: CTL Position*/
#define TT_SCB_AHBSCR_CTL_Msk                 (3UL /*<< SCB_AHBPCR_CTL_Pos*/)                /*!< SCB AHBSCR: CTL Mask */

/* Auxiliary Bus Fault Status Register Definitions */
#define TT_SCB_ABFSR_AXIMTYPE_Pos              8U                                            /*!< SCB ABFSR: AXIMTYPE Position*/
#define TT_SCB_ABFSR_AXIMTYPE_Msk             (3UL << TT_SCB_ABFSR_AXIMTYPE_Pos)                /*!< SCB ABFSR: AXIMTYPE Mask */

#define TT_SCB_ABFSR_EPPB_Pos                  4U                                            /*!< SCB ABFSR: EPPB Position*/
#define TT_SCB_ABFSR_EPPB_Msk                 (1UL << TT_SCB_ABFSR_EPPB_Pos)                    /*!< SCB ABFSR: EPPB Mask */

#define TT_SCB_ABFSR_AXIM_Pos                  3U                                            /*!< SCB ABFSR: AXIM Position*/
#define TT_SCB_ABFSR_AXIM_Msk                 (1UL << TT_SCB_ABFSR_AXIM_Pos)                    /*!< SCB ABFSR: AXIM Mask */

#define TT_SCB_ABFSR_AHBP_Pos                  2U                                            /*!< SCB ABFSR: AHBP Position*/
#define TT_SCB_ABFSR_AHBP_Msk                 (1UL << TT_SCB_ABFSR_AHBP_Pos)                    /*!< SCB ABFSR: AHBP Mask */

#define TT_SCB_ABFSR_DTCM_Pos                  1U                                            /*!< SCB ABFSR: DTCM Position*/
#define TT_SCB_ABFSR_DTCM_Msk                 (1UL << TT_SCB_ABFSR_DTCM_Pos)                    /*!< SCB ABFSR: DTCM Mask */

#define TT_SCB_ABFSR_ITCM_Pos                  0U                                            /*!< SCB ABFSR: ITCM Position*/
#define TT_SCB_ABFSR_ITCM_Msk                 (1UL /*<< SCB_ABFSR_ITCM_Pos*/)                /*!< SCB ABFSR: ITCM Mask */

/* Cache Size ID Register Macros */
#define TT_CCSIDR_WAYS(x)         (((x) & TT_SCB_CCSIDR_ASSOCIATIVITY_Msk) >> TT_SCB_CCSIDR_ASSOCIATIVITY_Pos)
#define TT_CCSIDR_SETS(x)         (((x) & TT_SCB_CCSIDR_NUMSETS_Msk      ) >> TT_SCB_CCSIDR_NUMSETS_Pos      )

/*@} end of group CMSIS_SCB */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_SCnSCB System Controls not in SCB (SCnSCB)
  \brief    Type definitions for the System Control and ID Register not in the SCB
  @{
 */

/**
  \brief  Structure type to access the System Control and ID Register not in the SCB.
 */
typedef struct
{
    uint32 RESERVED0[1U];
    __IM  uint32 ICTR;                   /*!< Offset: 0x004 (R/ )  Interrupt Controller Type Register */
    __IOM uint32 ACTLR;                  /*!< Offset: 0x008 (R/W)  Auxiliary Control Register */
} SCnSCB_RegType;

/* Interrupt Controller Type Register Definitions */
#define TT_SCnSCB_ICTR_INTLINESNUM_Pos         0U                                         /*!< ICTR: INTLINESNUM Position */
#define TT_SCnSCB_ICTR_INTLINESNUM_Msk        (0xFUL /*<< SCnSCB_ICTR_INTLINESNUM_Pos*/)  /*!< ICTR: INTLINESNUM Mask */

/* Auxiliary Control Register Definitions */
#define TT_SCnSCB_ACTLR_DISDYNADD_Pos         26U                                         /*!< ACTLR: DISDYNADD Position */
#define TT_SCnSCB_ACTLR_DISDYNADD_Msk         (1UL << TT_SCnSCB_ACTLR_DISDYNADD_Pos)         /*!< ACTLR: DISDYNADD Mask */

#define TT_SCnSCB_ACTLR_DISISSCH1_Pos         21U                                         /*!< ACTLR: DISISSCH1 Position */
#define TT_SCnSCB_ACTLR_DISISSCH1_Msk         (0x1FUL << TT_SCnSCB_ACTLR_DISISSCH1_Pos)      /*!< ACTLR: DISISSCH1 Mask */

#define TT_SCnSCB_ACTLR_DISDI_Pos             16U                                         /*!< ACTLR: DISDI Position */
#define TT_SCnSCB_ACTLR_DISDI_Msk             (0x1FUL << TT_SCnSCB_ACTLR_DISDI_Pos)          /*!< ACTLR: DISDI Mask */

#define TT_SCnSCB_ACTLR_DISCRITAXIRUR_Pos     15U                                         /*!< ACTLR: DISCRITAXIRUR Position */
#define TT_SCnSCB_ACTLR_DISCRITAXIRUR_Msk     (1UL << TT_SCnSCB_ACTLR_DISCRITAXIRUR_Pos)     /*!< ACTLR: DISCRITAXIRUR Mask */

#define TT_SCnSCB_ACTLR_DISBTACALLOC_Pos      14U                                         /*!< ACTLR: DISBTACALLOC Position */
#define TT_SCnSCB_ACTLR_DISBTACALLOC_Msk      (1UL << TT_SCnSCB_ACTLR_DISBTACALLOC_Pos)      /*!< ACTLR: DISBTACALLOC Mask */

#define TT_SCnSCB_ACTLR_DISBTACREAD_Pos       13U                                         /*!< ACTLR: DISBTACREAD Position */
#define TT_SCnSCB_ACTLR_DISBTACREAD_Msk       (1UL << TT_SCnSCB_ACTLR_DISBTACREAD_Pos)       /*!< ACTLR: DISBTACREAD Mask */

#define TT_SCnSCB_ACTLR_DISITMATBFLUSH_Pos    12U                                         /*!< ACTLR: DISITMATBFLUSH Position */
#define TT_SCnSCB_ACTLR_DISITMATBFLUSH_Msk    (1UL << TT_SCnSCB_ACTLR_DISITMATBFLUSH_Pos)    /*!< ACTLR: DISITMATBFLUSH Mask */

#define TT_SCnSCB_ACTLR_DISRAMODE_Pos         11U                                         /*!< ACTLR: DISRAMODE Position */
#define TT_SCnSCB_ACTLR_DISRAMODE_Msk         (1UL << TT_SCnSCB_ACTLR_DISRAMODE_Pos)         /*!< ACTLR: DISRAMODE Mask */

#define TT_SCnSCB_ACTLR_FPEXCODIS_Pos         10U                                         /*!< ACTLR: FPEXCODIS Position */
#define TT_SCnSCB_ACTLR_FPEXCODIS_Msk         (1UL << TT_SCnSCB_ACTLR_FPEXCODIS_Pos)         /*!< ACTLR: FPEXCODIS Mask */

#define TT_SCnSCB_ACTLR_DISFOLD_Pos            2U                                         /*!< ACTLR: DISFOLD Position */
#define TT_SCnSCB_ACTLR_DISFOLD_Msk           (1UL << TT_SCnSCB_ACTLR_DISFOLD_Pos)           /*!< ACTLR: DISFOLD Mask */

#define TT_SCnSCB_ACTLR_DISMCYCINT_Pos         0U                                         /*!< ACTLR: DISMCYCINT Position */
#define TT_SCnSCB_ACTLR_DISMCYCINT_Msk        (1UL /*<< SCnSCB_ACTLR_DISMCYCINT_Pos*/)    /*!< ACTLR: DISMCYCINT Mask */

/**
  \ingroup    CMSIS_core_register
  \defgroup   CMSIS_core_base     Core Definitions
  \brief      Definitions for base addresses, unions, and structures.
  @{
 */

/* Memory mapping of Core Hardware */
#define TT_SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define TT_SCB_BASE            (0xE000E000UL +  0x0D00UL)                    /*!< System Control Block Base Address */

#define TT_SCnSCB              ((SCnSCB_RegType    *)     TT_SCS_BASE      )   /*!< System control Register not in SCB */
#define TT_SCB                 ((SCB_RegType       *)     TT_SCB_BASE      )   /*!< SCB configuration struct */



#ifdef __cplusplus
}
#endif

#endif /*  */

