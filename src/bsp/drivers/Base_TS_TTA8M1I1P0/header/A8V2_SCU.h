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
#ifndef A8V2_SCU_H
#define A8V2_SCU_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_SCU_VENDOR_ID_H                     1541
#define A8V2_SCU_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_SCU_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_SCU_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_SCU_SW_MAJOR_VERSION_H              1
#define A8V2_SCU_SW_MINOR_VERSION_H              1
#define A8V2_SCU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_SCU.h and TT_Common.h file version check */
#if (A8V2_SCU_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_SCU.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_SCU_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_SCU_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_SCU_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_SCU.h and TT_Common.h are different"
#endif
#if ((A8V2_SCU_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_SCU_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_SCU_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_SCU.h and TT_Common.h are different"
#endif

/**
  * @brief TT_SCU_CMUX [CMUX] (Cmu.)
  */
typedef struct {
  __IOM uint32_t  CMUX_CR;                      /*!< (@ 0x00000000) CMU Control Register.                                      */
  __IOM uint32_t  CMUX_CHKW;                    /*!< (@ 0x00000004) CMU Check Windows Register.                                */
  __IOM uint32_t  CMUX_THD;                     /*!< (@ 0x00000008) CMU Threshold Register.                                    */
  __IM  uint32_t  RESERVED;
} TT_SCU_CMUX_Type;                             /*!< Size = 16 (0x10)                                                          */

 
/**
  * @brief System Control Unit (TT_SCU)
  */

typedef struct {                                /*!< (@ 0x40070000) TT_SCU Structure                                           */
  __IM  uint32_t  RESET_SOURCE;                 /*!< (@ 0x00000000) Last Reset Source.                                         */
  __IOM uint32_t  LOCAL_RST0;                   /*!< (@ 0x00000004) Local 0 Reset Source.                                      */
  __IOM uint32_t  LOCAL_RST1;                   /*!< (@ 0x00000008) Local 1 Reset Source.                                      */
  __IOM uint32_t  LOCAL_RST2;                   /*!< (@ 0x0000000C) Local 2 Reset Source.                                      */
  __IOM uint32_t  M7_VTOR;                      /*!< (@ 0x00000010) M7 VTOR Register.                                          */
  __IM  uint32_t  BPIN_CR;                      /*!< (@ 0x00000014) M7 Boot PIN Control.                                       */
  __IOM uint32_t  RGU_RSTB_DEGLITCH;            /*!< (@ 0x00000018) RGU rstb Deglitch Register.                                */
  __IOM uint32_t  RGU_SRAM_CLR_CR;              /*!< (@ 0x0000001C) RGU_SRAM_CLR_CR control Register.                          */
  __IM  uint32_t  RESERVED[56];
  __IOM uint32_t  ECO_CTL;                      /*!< (@ 0x00000100) ECO CTL Register.                                          */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  MPLL_CTL;                     /*!< (@ 0x00000108) MPLL CTL Register.                                         */
  __IOM uint32_t  EPLL_CTL;                     /*!< (@ 0x0000010C) EPLL CTL Register.                                         */
  __IOM uint32_t  CLKDIV_CTL0;                  /*!< (@ 0x00000110) Clock Division Register.                                   */
  __IOM uint32_t  CLKDIV_CTL1;                  /*!< (@ 0x00000114) Clock Division Register.                                   */
  __IOM uint32_t  CLKDIV_CTL2;                  /*!< (@ 0x00000118) Clock Division Register.                                   */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  CLK_STOP0;                    /*!< (@ 0x00000120) Clock Control Register.                                    */
  __IOM uint32_t  CLK_STOP1;                    /*!< (@ 0x00000124) Clock Control Register.                                    */
  __IOM uint32_t  CLK_STOP2;                    /*!< (@ 0x00000128) Clock Control Register.                                    */
  __IOM uint32_t  CLK_SLEEP0;                   /*!< (@ 0x0000012C) Clock Sleep 0 Register.                                    */
  __IOM uint32_t  CLK_SLEEP1;                   /*!< (@ 0x00000130) Clock Sleep 1 Register.                                    */
  __IOM uint32_t  CLK_SLEEP2;                   /*!< (@ 0x00000134) Clock Sleep 2 Register.                                    */
  __IOM uint32_t  LP_CTL;                       /*!< (@ 0x00000138) LP CTL Register.                                           */
  __IOM uint32_t  PLL_LOCK_TIME;                /*!< (@ 0x0000013C) PLL Lock Time Register.                                    */
  __IOM uint32_t  CLK_RAND;                     /*!< (@ 0x00000140) Clock Rand Register.                                       */
  __IOM uint32_t  LFSR_SEED;                    /*!< (@ 0x00000144) LFSR Seed Register.                                        */
  __IOM uint32_t  PERI_STOP;                    /*!< (@ 0x00000148) Peri stop, 1 means hw will request IP go into
                                                                    STOP mode when WFI.                                        */
  __IOM uint32_t  CGU_CLK_SEL;                  /*!< (@ 0x0000014C) CGU_CLK_SEL Register.                                      */
  __IOM uint32_t  SCU_PD_CTL;                   /*!< (@ 0x00000150) M7 go into standby wait hsm deelpsleep enable.             */
  __IOM uint32_t  CGU_M7CLKEN_CR;               /*!< (@ 0x00000154) M7 Delay Cycles.                                           */
  __IM  uint32_t  RESERVED3[43];
  __IM  uint32_t  BIST_STATE;                   /*!< (@ 0x00000204) SCU Bost State Register.                                   */
  __IOM uint32_t  PROBE_SEL;                    /*!< (@ 0x00000208) SCU Probe Select Register.                                 */
  __IOM uint32_t  FTM_CLB_CFG;                  /*!< (@ 0x0000020C) FTM Global Config Select Config Register.                  */
  __IOM uint32_t  QSPI_MISC_CFG;                /*!< (@ 0x00000210) QSPI misc config.                                          */
  __IOM uint32_t  EMAC_MISC_CFG;                /*!< (@ 0x00000214) EMAC misc config.                                          */
  __IM  uint32_t  RESERVED4[58];
  __IOM uint32_t  ANA_CR;                       /*!< (@ 0x00000300) ANA Ccontrol Register.                                     */
  __IOM uint32_t  ANA_TRIM0;                    /*!< (@ 0x00000304) Analog Trimming Register 0.                                */
  __IOM uint32_t  ANA_TRIM1;                    /*!< (@ 0x00000308) Analog Trimming Register 1.                                */
  __IOM uint32_t  ANA_TRIM2;                    /*!< (@ 0x0000030C) Analog Trimming Register 2.                                */
  __IOM uint32_t  ANA_TRIM3;                    /*!< (@ 0x00000310) Analog Trimming Register 3.                                */
  __IOM uint32_t  ANA_TRIM_CR;                  /*!< (@ 0x00000314) Analog Trimming Control Register.                          */
  __IOM uint32_t  ANA_TEST_CR;                  /*!< (@ 0x00000318) ANA Test Register.                                         */
  __IOM uint32_t  ANA_BUCK_TCR;                 /*!< (@ 0x0000031C) ANA_BUCK_TCR.                                              */
  __IM  uint32_t  RESERVED5[56];
  __IOM TT_SCU_CMUX_Type CMUX[10];              /*!< (@ 0x00000400) Cmu.                                                       */
  __IM  uint32_t  RESERVED6[24];
  __IOM uint32_t  INT_CR;                       /*!< (@ 0x00000500) SCU Interrupt Control Register.                            */
  __OM  uint32_t  INT_STATUS;                   /*!< (@ 0x00000504) SCU status Control Register.                               */
  __IM  uint32_t  RESERVED7[62];
  __IM  uint32_t  SCU_ID;                       /*!< (@ 0x00000600) SCU ID Register.                                           */
  __IOM uint32_t  SCU_SUPV;                     /*!< (@ 0x00000604) SCU ID Register.                                           */
  __IM  uint32_t  RESERVED8[62];
  __OM  uint32_t  SJTAG_KEY0;                   /*!< (@ 0x00000700) Secure Jtag Key0.                                          */
  __OM  uint32_t  SJTAG_KEY1;                   /*!< (@ 0x00000704) Secure Jtag Key1.                                          */
  __OM  uint32_t  SJTAG_KEY2;                   /*!< (@ 0x00000708) Secure Jtag Key2.                                          */
  __OM  uint32_t  SJTAG_KEY3;                   /*!< (@ 0x0000070C) Secure Jtag Key3.                                          */
  __IM  uint32_t  RESERVED9[60];
  __IOM uint32_t  PAD_INFUN[40];                /*!< (@ 0x00000800) Pad Select Register.                                       */
  __IM  uint32_t  RESERVED10[20];
  __IOM uint32_t  IOM_INSEL0;                   /*!< (@ 0x000008F0) IOM Select Register.                                       */
  __IOM uint32_t  IOM_INSEL1;                   /*!< (@ 0x000008F4) IOM Select Register.                                       */
  __IM  uint32_t  RESERVED11[2];
  __IOM uint32_t  PAD_FUNC[40];                 /*!< (@ 0x00000900) Select Pad Function Register.                              */
  __IM  uint32_t  RESERVED12[24];
  __IOM uint32_t  PAD_PROBE[10];                /*!< (@ 0x00000A00) Select Pad Probesel.                                       */
  __IM  uint32_t  RESERVED13[54];
  __IOM uint32_t  PROBE_SEL_REG0;               /*!< (@ 0x00000B00) Probesel Select Register0.                                 */
  __IOM uint32_t  PROBE_SEL_REG1;               /*!< (@ 0x00000B04) Probesel Select Register1.                                 */
  __IM  uint32_t  RESERVED14[62];
  __IOM uint32_t  WDTSCON0;                     /*!< (@ 0x00000C00) Safety WDT Control Register 0.                             */
  __IOM uint32_t  WDTSCON1;                     /*!< (@ 0x00000C04) Safety WDT Control Register 0.                             */
  __IOM uint32_t  WDTSR;                        /*!< (@ 0x00000C08) Safety WDT status Register 0.                              */
  __IOM uint32_t  SEICON0;                      /*!< (@ 0x00000C0C) Safety WDT status Register 0.                              */
  __IOM uint32_t  SEICON1;                      /*!< (@ 0x00000C10) Safety WDT status Register 0.                              */
  __IOM uint32_t  SEISR;                        /*!< (@ 0x00000C14) Safety WDT status Register 0.                              */
  __IM  uint32_t  RESERVED15[58];
  __IOM uint32_t  RMU_CR;                       /*!< (@ 0x00000D00) Rmu control Register.                                      */
  __IM  uint32_t  RESERVED16[187];
  __IM  uint32_t  CHIP_ID;                      /*!< (@ 0x00000FF0) Chip Id Register.                                          */
} SCU_Type, *SCU_MemMapPtr;                     /*!< Size = 2824 (0xb08)                                                        */

/* Only use for pad_iomux*/
typedef struct {      
    uint32  Pad_InFunc[40];
}TT_PAD_INFUNC_Type;

typedef struct {      
    uint32  Pad_OutFunc[40];
}TT_PAD_OUTFUNC_Type;


/** Number of instances of the SCU module. */
#define SCU_INSTANCE_COUNT                       (1u)

/* SCU - Peripheral instance base addresses */
/** Peripheral SCU base address */
#define TT_SCU_BASE                              (0x40070000UL)

/** Peripheral SCU base pointer */
#define TT_SCU                                   ((SCU_Type *)TT_SCU_BASE)

/** Array initializer of SCU peripheral base addresses */
#define TT_SCU_BASE_ADDRS                        { TT_SCU_BASE }

/** Array initializer of SCU peripheral base pointers */
#define TT_SCU_BASE_PTRS                         { TT_SCU }

#define TT_SCU_BASE                    (0x40070000UL)
#define TT_PAD_INFUNC_BASE             (TT_SCU_BASE + 0x00000800)
#define TT_PAD_OUTFUNC_BASE            (TT_SCU_BASE + 0x00000900)

#define TT_PAD_INFUNC                  ((TT_PAD_INFUNC_Type*)        TT_PAD_INFUNC_BASE)
#define TT_PAD_OUTFUNC                 ((TT_PAD_OUTFUNC_Type*)        TT_PAD_OUTFUNC_BASE)

/* These enums are used control stop/start module clock static*/
typedef enum
{
    TT_SCU_CLK_CONTROL_FTM0     = 0,
    TT_SCU_CLK_CONTROL_FTM1     = 1,
    TT_SCU_CLK_CONTROL_FTM2     = 2,
    TT_SCU_CLK_CONTROL_FTM3     = 3,
    TT_SCU_CLK_CONTROL_FTM4     = 4,
    TT_SCU_CLK_CONTROL_FTM5     = 5,
    TT_SCU_CLK_CONTROL_I3C0     = 6,
    TT_SCU_CLK_CONTROL_CRC      = 8,
    TT_SCU_CLK_CONTROL_DMAC0    = 9,
    TT_SCU_CLK_CONTROL_DMAC1    = 10,
    TT_SCU_CLK_CONTROL_DMAC2    = 11,
    TT_SCU_CLK_CONTROL_DMAC3    = 12,
    TT_SCU_CLK_CONTROL_EMAC     = 13,
    TT_SCU_CLK_CONTROL_GPIO0    = 14,
    TT_SCU_CLK_CONTROL_GPIO1    = 15,
    TT_SCU_CLK_CONTROL_GPIO2    = 16,
    TT_SCU_CLK_CONTROL_GPIO3    = 17,
    TT_SCU_CLK_CONTROL_GPIO4    = 18,
    TT_SCU_CLK_CONTROL_I2S0     = 19,
    TT_SCU_CLK_CONTROL_SENT6    = 20,
    TT_SCU_CLK_CONTROL_IOM      = 21,
    TT_SCU_CLK_CONTROL_SENT0    = 22,
    TT_SCU_CLK_CONTROL_SENT1    = 23,
    TT_SCU_CLK_CONTROL_SENT2    = 24,
    TT_SCU_CLK_CONTROL_SENT3    = 25,
    TT_SCU_CLK_CONTROL_SENT4    = 26,
    TT_SCU_CLK_CONTROL_SENT5    = 27,
    TT_SCU_CLK_CONTROL_TIMER    = 28,
    TT_SCU_CLK_CONTROL_UART0    = 29,
    TT_SCU_CLK_CONTROL_UART1    = 30,
    TT_SCU_CLK_CONTROL_UART2    = 31,

    TT_SCU_CLK_CONTROL_UART3    = 32,
    TT_SCU_CLK_CONTROL_WDT      = 33,
    TT_SCU_CLK_CONTROL_QSPI0    = 34,
    TT_SCU_CLK_CONTROL_SSP7     = 35,
    TT_SCU_CLK_CONTROL_SSP0     = 36,
    TT_SCU_CLK_CONTROL_SSP1     = 37,
    TT_SCU_CLK_CONTROL_SSP2     = 38,
    TT_SCU_CLK_CONTROL_SSP3     = 39,
    TT_SCU_CLK_CONTROL_SSP4     = 40,
    TT_SCU_CLK_CONTROL_SSP5     = 41,
    TT_SCU_CLK_CONTROL_I2C0     = 42,
    TT_SCU_CLK_CONTROL_I2C1     = 43,
    TT_SCU_CLK_CONTROL_LIN0     = 44,
    TT_SCU_CLK_CONTROL_LIN1     = 45,
    TT_SCU_CLK_CONTROL_LIN2     = 46,
    TT_SCU_CLK_CONTROL_LIN3     = 47,
    TT_SCU_CLK_CONTROL_LIN4     = 48,
    TT_SCU_CLK_CONTROL_LIN5     = 49,
    TT_SCU_CLK_CONTROL_LIN6     = 50,
    TT_SCU_CLK_CONTROL_LIN7     = 51,
    TT_SCU_CLK_CONTROL_LIN8     = 52,
    TT_SCU_CLK_CONTROL_LIN9     = 53,
    TT_SCU_CLK_CONTROL_LIN10    = 54,
    TT_SCU_CLK_CONTROL_LIN11    = 55,
    TT_SCU_CLK_CONTROL_LIN12    = 56,
    TT_SCU_CLK_CONTROL_LIN13    = 57,
    TT_SCU_CLK_CONTROL_LIN14    = 58,
    TT_SCU_CLK_CONTROL_LIN15    = 59,
    TT_SCU_CLK_CONTROL_SSP6     = 60,
    TT_SCU_CLK_CONTROL_CAN0     = 61,
    TT_SCU_CLK_CONTROL_CAN1     = 62,
    TT_SCU_CLK_CONTROL_CAN2     = 63,
    
    TT_SCU_CLK_CONTROL_CAN3     = 64,
    TT_SCU_CLK_CONTROL_CAN4     = 65,
    TT_SCU_CLK_CONTROL_CAN5     = 66,
    TT_SCU_CLK_CONTROL_CAN6     = 67,
    TT_SCU_CLK_CONTROL_CAN7     = 68,
    TT_SCU_CLK_CONTROL_SENT7    = 69 ,
    TT_SCU_CLK_CONTROL_TRIG_MUX     = 70,
    TT_SCU_CLK_CONTROL_ADC_SENSOR   = 71 ,
    TT_SCU_CLK_CONTROL_INTM         = 72,
    TT_SCU_CLK_CONTROL_SHIELD_CIP   = 73,
    TT_SCU_CLK_CONTROL_PKI          = 74,
    TT_SCU_CLK_CONTROL_HASH         = 75,
    TT_SCU_CLK_CONTROL_SKA          = 76,
    TT_SCU_CLK_CONTROL_SM4          = 77,
    TT_SCU_CLK_CONTROL_LASER_CIP    = 78,
    TT_SCU_CLK_CONTROL_TRNG         = 79,
    TT_SCU_CLK_CONTROL_DEBUG        = 80,
    TT_SCU_CLK_CONTROL_HSM          = 81,
    TT_SCU_CLK_CONTROL_STCU         = 82,
    TT_SCU_CLK_CONTROL_MBX          = 83,
    TT_SCU_CLK_CONTROL_ADC          = 84,
    TT_SCU_CLK_CONTROL_PMU_APB      = 85,
    TT_SCU_CLK_CONTROL_GTM          = 86,
    TT_SCU_CLK_CONTROL_EIM          = 87,
    TT_SCU_CLK_CONTROL_END
}TT_SCU_CLK_CONTROL_Type;

/* These enums are used control stop/start module clock dynamic*/
typedef enum
{
    TT_SCU_CLK_SLEEP_FTM0     = 0,
    TT_SCU_CLK_SLEEP_FTM1     = 1,
    TT_SCU_CLK_SLEEP_FTM2     = 2,
    TT_SCU_CLK_SLEEP_FTM3     = 3,
    TT_SCU_CLK_SLEEP_FTM4     = 4,
    TT_SCU_CLK_SLEEP_FTM5     = 5,
    TT_SCU_CLK_SLEEP_I3C0     = 6,
    TT_SCU_CLK_SLEEP_CRC      = 8,
    TT_SCU_CLK_SLEEP_DMAC0    = 9,
    TT_SCU_CLK_SLEEP_DMAC1    = 10,
    TT_SCU_CLK_SLEEP_DMAC2    = 11,
    TT_SCU_CLK_SLEEP_DMAC3    = 12,
    TT_SCU_CLK_SLEEP_EMAC     = 13,
    TT_SCU_CLK_SLEEP_GPIO0    = 14,
    TT_SCU_CLK_SLEEP_GPIO1    = 15,
    TT_SCU_CLK_SLEEP_GPIO2    = 16,
    TT_SCU_CLK_SLEEP_GPIO3    = 17,
    TT_SCU_CLK_SLEEP_GPIO4    = 18,
    TT_SCU_CLK_SLEEP_I2S0     = 19,
    TT_SCU_CLK_SLEEP_SENT6    = 20,
    TT_SCU_CLK_SLEEP_IOM      = 21,
    TT_SCU_CLK_SLEEP_SENT0    = 22,
    TT_SCU_CLK_SLEEP_SENT1    = 23,
    TT_SCU_CLK_SLEEP_SENT2    = 24,
    TT_SCU_CLK_SLEEP_SENT3    = 25,
    TT_SCU_CLK_SLEEP_SENT4    = 26,
    TT_SCU_CLK_SLEEP_SENT5    = 27,
    TT_SCU_CLK_SLEEP_STM      = 28,
    TT_SCU_CLK_SLEEP_UART0    = 29,
    TT_SCU_CLK_SLEEP_UART1    = 30,
    TT_SCU_CLK_SLEEP_UART2    = 31,
    
    TT_SCU_CLK_SLEEP_UART3    = 32,
    TT_SCU_CLK_SLEEP_WDT      = 33,
    TT_SCU_CLK_SLEEP_QSPI0    = 34,
    TT_SCU_CLK_SLEEP_SSP7     = 35,
    TT_SCU_CLK_SLEEP_SSP0     = 36,
    TT_SCU_CLK_SLEEP_SSP1     = 37,
    TT_SCU_CLK_SLEEP_SSP2     = 38,
    TT_SCU_CLK_SLEEP_SSP3     = 39,
    TT_SCU_CLK_SLEEP_SSP4     = 40,
    TT_SCU_CLK_SLEEP_SSP5     = 41,
    TT_SCU_CLK_SLEEP_I2C0     = 42,
    TT_SCU_CLK_SLEEP_I2C1     = 43,
    TT_SCU_CLK_SLEEP_LIN0     = 44,
    TT_SCU_CLK_SLEEP_LIN1     = 45,
    TT_SCU_CLK_SLEEP_LIN2     = 46,
    TT_SCU_CLK_SLEEP_LIN3     = 47,
    TT_SCU_CLK_SLEEP_LIN4     = 48,
    TT_SCU_CLK_SLEEP_LIN5     = 49,
    TT_SCU_CLK_SLEEP_LIN6     = 50,
    TT_SCU_CLK_SLEEP_LIN7     = 51,
    TT_SCU_CLK_SLEEP_LIN8     = 52,
    TT_SCU_CLK_SLEEP_LIN9     = 53,
    TT_SCU_CLK_SLEEP_LIN10    = 54,
    TT_SCU_CLK_SLEEP_LIN11    = 55,
    TT_SCU_CLK_SLEEP_LIN12    = 56,
    TT_SCU_CLK_SLEEP_LIN13    = 57,
    TT_SCU_CLK_SLEEP_LIN14    = 58,
    TT_SCU_CLK_SLEEP_LIN15    = 59,
    TT_SCU_CLK_SLEEP_SSP6     = 60,
    
    TT_SCU_CLK_SLEEP_SENT7          = 69,
    TT_SCU_CLK_SLEEP_TRIG_MUX       = 70,
    TT_SCU_CLK_SLEEP_ADC_SENSOR     = 71,
    TT_SCU_CLK_SLEEP_INTM           = 72,
    TT_SCU_CLK_SLEEP_SHIELD_CIP     = 73,
    TT_SCU_CLK_SLEEP_PKI            = 74,
    TT_SCU_CLK_SLEEP_HASH           = 75,
    TT_SCU_CLK_SLEEP_SKA            = 76,
    TT_SCU_CLK_SLEEP_SM4            = 77,
    TT_SCU_CLK_SLEEP_LASER_CIP      = 78,
    TT_SCU_CLK_SLEEP_TRNG           = 79,

    TT_SCU_CLK_SLEEP_STCU     = 82 ,
    TT_SCU_CLK_SLEEP_MBX      = 83 ,
    TT_SCU_CLK_SLEEP_ADC      = 84 ,
    TT_SCU_CLK_SLEEP_PMU_APB  = 85     ,
    TT_SCU_CLK_SLEEP_EIM      = 87 ,
    TT_SCU_CLK_SLEEP_SCU      = 90,
    TT_SCU_CLK_SLEEP_SMU      = 91,
    TT_SCU_CLK_SLEEP_TCM      = 92,
    TT_SCU_CLK_SLEEP_FCU      = 93,
    TT_SCU_CLK_SLEEP_AHB      = 94,
    TT_SCU_CLK_SLEEP_AXI      = 95,

    TT_SCU_CLK_SLEEP_END
}TT_SCU_CLK_SLEEP_Type;

/* These enums are used control can/lin stop clock */
typedef enum
{
    TT_SCU_PERI_STOP_LIN0   = 0,
    TT_SCU_PERI_STOP_LIN1   = 1,
    TT_SCU_PERI_STOP_LIN2   = 2,
    TT_SCU_PERI_STOP_LIN3   = 3,
    TT_SCU_PERI_STOP_LIN4   = 4,
    TT_SCU_PERI_STOP_LIN5   = 5,
    TT_SCU_PERI_STOP_LIN6   = 6,
    TT_SCU_PERI_STOP_LIN7   = 7,
    TT_SCU_PERI_STOP_LIN8   = 8,
    TT_SCU_PERI_STOP_LIN9   = 9,
    TT_SCU_PERI_STOP_LIN10  = 10,
    TT_SCU_PERI_STOP_LIN11  = 11,
    TT_SCU_PERI_STOP_LIN12  = 12,
    TT_SCU_PERI_STOP_LIN13  = 13,
    TT_SCU_PERI_STOP_LIN14  = 14,
    TT_SCU_PERI_STOP_LIN15  = 15,
    TT_SCU_PERI_STOP_CAN0   = 16,
    TT_SCU_PERI_STOP_CAN1   = 17,
    TT_SCU_PERI_STOP_CAN2   = 18,
    TT_SCU_PERI_STOP_CAN3   = 19,
    TT_SCU_PERI_STOP_CAN4   = 20,
    TT_SCU_PERI_STOP_CAN5   = 21,
    TT_SCU_PERI_STOP_CAN6   = 22,
    TT_SCU_PERI_STOP_CAN7   = 23,
    TT_SCU_PERI_STOP_END
}TT_SCU_PERI_STOP_Type;

/* These enums are used control module reset*/
typedef enum
{
    TT_SCU_LOCAL_RST_FTM0   = 0,
    TT_SCU_LOCAL_RST_FTM1   = 1 ,
    TT_SCU_LOCAL_RST_FTM2   = 2 ,
    TT_SCU_LOCAL_RST_FTM3   = 3 ,
    TT_SCU_LOCAL_RST_FTM4   = 4 ,
    TT_SCU_LOCAL_RST_FTM5   = 5 ,
    TT_SCU_LOCAL_RST_I3C0   = 6 ,
    TT_SCU_LOCAL_RST_GPIOF  = 7  ,
    TT_SCU_LOCAL_RST_CRC    = 8 ,
    TT_SCU_LOCAL_RST_DMAC0  = 9 ,
    TT_SCU_LOCAL_RST_DMAC1  = 10 ,
    TT_SCU_LOCAL_RST_DMAC2  = 11 ,
    TT_SCU_LOCAL_RST_DMAC3  = 12 ,
    TT_SCU_LOCAL_RST_EMAC   = 13,
    TT_SCU_LOCAL_RST_GPIO0  = 14 ,
    TT_SCU_LOCAL_RST_GPIO1  = 15 ,
    TT_SCU_LOCAL_RST_GPIO2  = 16 ,
    TT_SCU_LOCAL_RST_GPIO3  = 17 ,
    TT_SCU_LOCAL_RST_GPIO4  = 18 ,
    TT_SCU_LOCAL_RST_I2S0   = 19 ,
    TT_SCU_LOCAL_RST_SENT6  = 20  ,
    TT_SCU_LOCAL_RST_IOM    = 21 ,
    TT_SCU_LOCAL_RST_SENT0  = 22 ,
    TT_SCU_LOCAL_RST_SENT1  = 23 ,
    TT_SCU_LOCAL_RST_SENT2  = 24 ,
    TT_SCU_LOCAL_RST_SENT3  = 25 ,
    TT_SCU_LOCAL_RST_SENT4  = 26 ,
    TT_SCU_LOCAL_RST_SENT5  = 27 ,
    TT_SCU_LOCAL_RST_TIMER  = 28 ,
    TT_SCU_LOCAL_RST_UART0  = 29 ,
    TT_SCU_LOCAL_RST_UART1  = 30 ,
    TT_SCU_LOCAL_RST_UART2  = 31 ,
    
    TT_SCU_LOCAL_RST_UART3  = 32 ,
    TT_SCU_LOCAL_RST_WDT    = 33 ,
    TT_SCU_LOCAL_RST_QSPI0  = 34 ,
    TT_SCU_LOCAL_RST_SSP7   = 35 ,
    TT_SCU_LOCAL_RST_SSP0   = 36 ,
    TT_SCU_LOCAL_RST_SSP1   = 37 ,
    TT_SCU_LOCAL_RST_SSP2   = 38 ,
    TT_SCU_LOCAL_RST_SSP3   = 39 ,
    TT_SCU_LOCAL_RST_SSP4   = 40 ,
    TT_SCU_LOCAL_RST_SSP5   = 41 ,
    TT_SCU_LOCAL_RST_I2C0   = 42 ,
    TT_SCU_LOCAL_RST_I2C1   = 43 ,
    TT_SCU_LOCAL_RST_LIN0   = 44 ,
    TT_SCU_LOCAL_RST_LIN1   = 45 ,
    TT_SCU_LOCAL_RST_LIN2   = 46 ,
    TT_SCU_LOCAL_RST_LIN3   = 47 ,
    TT_SCU_LOCAL_RST_LIN4   = 48 ,
    TT_SCU_LOCAL_RST_LIN5   = 49 ,
    TT_SCU_LOCAL_RST_LIN6   = 50 ,
    TT_SCU_LOCAL_RST_LIN7   = 51 ,
    TT_SCU_LOCAL_RST_LIN8   = 52 ,
    TT_SCU_LOCAL_RST_LIN9   = 53 ,
    TT_SCU_LOCAL_RST_LIN10  = 54 ,
    TT_SCU_LOCAL_RST_LIN11  = 55 ,
    TT_SCU_LOCAL_RST_LIN12  = 56 ,
    TT_SCU_LOCAL_RST_LIN13  = 57 ,
    TT_SCU_LOCAL_RST_LIN14  = 58 ,
    TT_SCU_LOCAL_RST_LIN15  = 59 ,
    TT_SCU_LOCAL_RST_SSP6   = 60 ,
    TT_SCU_LOCAL_RST_CAN0   = 61 ,
    TT_SCU_LOCAL_RST_CAN1   = 62 ,
    TT_SCU_LOCAL_RST_CAN2   = 63 ,
    
    TT_SCU_LOCAL_RST_CAN3   = 64 ,
    TT_SCU_LOCAL_RST_CAN4   = 65 ,
    TT_SCU_LOCAL_RST_CAN5   = 66 ,
    TT_SCU_LOCAL_RST_CAN6   = 67 ,
    TT_SCU_LOCAL_RST_CAN7   = 68 ,
    TT_SCU_LOCAL_RST_SENT7  = 69  ,
    TT_SCU_LOCAL_RST_CIP_SHIELD = 73,
    TT_SCU_LOCAL_RST_PKI     = 74,
    TT_SCU_LOCAL_RST_HASH    = 75,
    TT_SCU_LOCAL_RST_SKA     = 76,
    TT_SCU_LOCAL_RST_SM4     = 77,
    TT_SCU_LOCAL_RST_LASER1  = 78,
    TT_SCU_LOCAL_RST_TRNG    = 79,
    TT_SCU_LOCAL_RST_MBX     = 80,
    TT_SCU_LOCAL_RST_ADC     = 81,
    
    TT_SCU_LOCAL_RST_HSM_SUBSYSTEM = 93,
    TT_SCU_LOCAL_RST_M7_CORE = 94
}TT_SCU_LOCAL_RST_Type;

/* =========================================================================================================================== */
/* ================                                        TT_SCU                                         ================ */
/* =========================================================================================================================== */

/* =====================================================  RESET_SOURCE  ====================================================== */
#define TT_SCU_RESET_SOURCE_POR_OR_PIN_Pos (0UL)                /*!< TT_SCU RESET_SOURCE: POR_OR_PIN (Bit 0)           */
#define TT_SCU_RESET_SOURCE_POR_OR_PIN_Msk (0x1UL)              /*!< TT_SCU RESET_SOURCE: POR_OR_PIN (Bitfield-Mask: 0x01) */
#define TT_SCU_RESET_SOURCE_LOW_POWER_Pos (1UL)                 /*!< TT_SCU RESET_SOURCE: LOW_POWER (Bit 1)            */
#define TT_SCU_RESET_SOURCE_LOW_POWER_Msk (0x2UL)               /*!< TT_SCU RESET_SOURCE: LOW_POWER (Bitfield-Mask: 0x01) */
#define TT_SCU_RESET_SOURCE_RSTB_PIN_Pos (2UL)                  /*!< TT_SCU RESET_SOURCE: RSTB_PIN (Bit 2)             */
#define TT_SCU_RESET_SOURCE_RSTB_PIN_Msk (0x4UL)                /*!< TT_SCU RESET_SOURCE: RSTB_PIN (Bitfield-Mask: 0x01) */
#define TT_SCU_RESET_SOURCE_ERR_LBIST_Pos (3UL)                 /*!< TT_SCU RESET_SOURCE: ERR_LBIST (Bit 3)            */
#define TT_SCU_RESET_SOURCE_ERR_LBIST_Msk (0x8UL)               /*!< TT_SCU RESET_SOURCE: ERR_LBIST (Bitfield-Mask: 0x01) */
#define TT_SCU_RESET_SOURCE_NORMAL_LBIST_Pos (4UL)              /*!< TT_SCU RESET_SOURCE: NORMAL_LBIST (Bit 4)         */
#define TT_SCU_RESET_SOURCE_NORMAL_LBIST_Msk (0x10UL)           /*!< TT_SCU RESET_SOURCE: NORMAL_LBIST (Bitfield-Mask: 0x01) */
#define TT_SCU_RESET_SOURCE_SMU_WARNING_Pos (5UL)               /*!< TT_SCU RESET_SOURCE: SMU_WARNING (Bit 5)          */
#define TT_SCU_RESET_SOURCE_SMU_WARNING_Msk (0x20UL)            /*!< TT_SCU RESET_SOURCE: SMU_WARNING (Bitfield-Mask: 0x01) */
#define TT_SCU_RESET_SOURCE_SOFTWARE_Pos (6UL)                  /*!< TT_SCU RESET_SOURCE: SOFTWARE (Bit 6)             */
#define TT_SCU_RESET_SOURCE_SOFTWARE_Msk (0x40UL)               /*!< TT_SCU RESET_SOURCE: SOFTWARE (Bitfield-Mask: 0x01) */
#define TT_SCU_RESET_SOURCE_SYS_STABLE_Pos (30UL)               /*!< TT_SCU RESET_SOURCE: SYS_STABLE (Bit 30)          */
#define TT_SCU_RESET_SOURCE_SYS_STABLE_Msk (0x40000000UL)       /*!< TT_SCU RESET_SOURCE: SYS_STABLE (Bitfield-Mask: 0x01) */
#define TT_SCU_RESET_SOURCE_SYS_ACTIVE_Pos (31UL)               /*!< TT_SCU RESET_SOURCE: SYS_ACTIVE (Bit 31)          */
#define TT_SCU_RESET_SOURCE_SYS_ACTIVE_Msk (0x80000000UL)       /*!< TT_SCU RESET_SOURCE: SYS_ACTIVE (Bitfield-Mask: 0x01) */
/* ======================================================  LOCAL_RST0  ======================================================= */
#define TT_SCU_LOCAL_RST0_FTM0_Pos    (0UL)                     /*!< TT_SCU LOCAL_RST0: FTM0 (Bit 0)                   */
#define TT_SCU_LOCAL_RST0_FTM0_Msk    (0x1UL)                   /*!< TT_SCU LOCAL_RST0: FTM0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_FTM1_Pos    (1UL)                     /*!< TT_SCU LOCAL_RST0: FTM1 (Bit 1)                   */
#define TT_SCU_LOCAL_RST0_FTM1_Msk    (0x2UL)                   /*!< TT_SCU LOCAL_RST0: FTM1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_FTM2_Pos    (2UL)                     /*!< TT_SCU LOCAL_RST0: FTM2 (Bit 2)                   */
#define TT_SCU_LOCAL_RST0_FTM2_Msk    (0x4UL)                   /*!< TT_SCU LOCAL_RST0: FTM2 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_FTM3_Pos    (3UL)                     /*!< TT_SCU LOCAL_RST0: FTM3 (Bit 3)                   */
#define TT_SCU_LOCAL_RST0_FTM3_Msk    (0x8UL)                   /*!< TT_SCU LOCAL_RST0: FTM3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_FTM4_Pos    (4UL)                     /*!< TT_SCU LOCAL_RST0: FTM4 (Bit 4)                   */
#define TT_SCU_LOCAL_RST0_FTM4_Msk    (0x10UL)                  /*!< TT_SCU LOCAL_RST0: FTM4 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_FTM5_Pos    (5UL)                     /*!< TT_SCU LOCAL_RST0: FTM5 (Bit 5)                   */
#define TT_SCU_LOCAL_RST0_FTM5_Msk    (0x20UL)                  /*!< TT_SCU LOCAL_RST0: FTM5 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_I3C0_Pos    (6UL)                     /*!< TT_SCU LOCAL_RST0: I3C0 (Bit 6)                   */
#define TT_SCU_LOCAL_RST0_I3C0_Msk    (0x40UL)                  /*!< TT_SCU LOCAL_RST0: I3C0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_CRC_Pos     (8UL)                     /*!< TT_SCU LOCAL_RST0: CRC (Bit 8)                    */
#define TT_SCU_LOCAL_RST0_CRC_Msk     (0x100UL)                 /*!< TT_SCU LOCAL_RST0: CRC (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST0_DMAC0_Pos   (9UL)                     /*!< TT_SCU LOCAL_RST0: DMAC0 (Bit 9)                  */
#define TT_SCU_LOCAL_RST0_DMAC0_Msk   (0x200UL)                 /*!< TT_SCU LOCAL_RST0: DMAC0 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_DMAC1_Pos   (10UL)                    /*!< TT_SCU LOCAL_RST0: DMAC1 (Bit 10)                 */
#define TT_SCU_LOCAL_RST0_DMAC1_Msk   (0x400UL)                 /*!< TT_SCU LOCAL_RST0: DMAC1 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_DMAC2_Pos   (11UL)                    /*!< TT_SCU LOCAL_RST0: DMAC2 (Bit 11)                 */
#define TT_SCU_LOCAL_RST0_DMAC2_Msk   (0x800UL)                 /*!< TT_SCU LOCAL_RST0: DMAC2 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_DMAC3_Pos   (12UL)                    /*!< TT_SCU LOCAL_RST0: DMAC3 (Bit 12)                 */
#define TT_SCU_LOCAL_RST0_DMAC3_Msk   (0x1000UL)                /*!< TT_SCU LOCAL_RST0: DMAC3 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_EMAC_Pos    (13UL)                    /*!< TT_SCU LOCAL_RST0: EMAC (Bit 13)                  */
#define TT_SCU_LOCAL_RST0_EMAC_Msk    (0x2000UL)                /*!< TT_SCU LOCAL_RST0: EMAC (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_GPIOA_Pos   (14UL)                    /*!< TT_SCU LOCAL_RST0: GPIOA (Bit 14)                 */
#define TT_SCU_LOCAL_RST0_GPIOA_Msk   (0x4000UL)                /*!< TT_SCU LOCAL_RST0: GPIOA (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_GPIOB_Pos   (15UL)                    /*!< TT_SCU LOCAL_RST0: GPIOB (Bit 15)                 */
#define TT_SCU_LOCAL_RST0_GPIOB_Msk   (0x8000UL)                /*!< TT_SCU LOCAL_RST0: GPIOB (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_GPIOC_Pos   (16UL)                    /*!< TT_SCU LOCAL_RST0: GPIOC (Bit 16)                 */
#define TT_SCU_LOCAL_RST0_GPIOC_Msk   (0x10000UL)               /*!< TT_SCU LOCAL_RST0: GPIOC (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_GPIOD_Pos   (17UL)                    /*!< TT_SCU LOCAL_RST0: GPIOD (Bit 17)                 */
#define TT_SCU_LOCAL_RST0_GPIOD_Msk   (0x20000UL)               /*!< TT_SCU LOCAL_RST0: GPIOD (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_GPIOE_Pos   (18UL)                    /*!< TT_SCU LOCAL_RST0: GPIOE (Bit 18)                 */
#define TT_SCU_LOCAL_RST0_GPIOE_Msk   (0x40000UL)               /*!< TT_SCU LOCAL_RST0: GPIOE (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_I2S0_Pos    (19UL)                    /*!< TT_SCU LOCAL_RST0: I2S0 (Bit 19)                  */
#define TT_SCU_LOCAL_RST0_I2S0_Msk    (0x80000UL)               /*!< TT_SCU LOCAL_RST0: I2S0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST0_SENT6_Pos   (20UL)                    /*!< TT_SCU LOCAL_RST0: SENT6 (Bit 20)                 */
#define TT_SCU_LOCAL_RST0_SENT6_Msk   (0x100000UL)              /*!< TT_SCU LOCAL_RST0: SENT6 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_IOM_Pos     (21UL)                    /*!< TT_SCU LOCAL_RST0: IOM (Bit 21)                   */
#define TT_SCU_LOCAL_RST0_IOM_Msk     (0x200000UL)              /*!< TT_SCU LOCAL_RST0: IOM (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST0_SENT0_Pos   (22UL)                    /*!< TT_SCU LOCAL_RST0: SENT0 (Bit 22)                 */
#define TT_SCU_LOCAL_RST0_SENT0_Msk   (0x400000UL)              /*!< TT_SCU LOCAL_RST0: SENT0 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_SENT1_Pos   (23UL)                    /*!< TT_SCU LOCAL_RST0: SENT1 (Bit 23)                 */
#define TT_SCU_LOCAL_RST0_SENT1_Msk   (0x800000UL)              /*!< TT_SCU LOCAL_RST0: SENT1 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_SENT2_Pos   (24UL)                    /*!< TT_SCU LOCAL_RST0: SENT2 (Bit 24)                 */
#define TT_SCU_LOCAL_RST0_SENT2_Msk   (0x1000000UL)             /*!< TT_SCU LOCAL_RST0: SENT2 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_SENT3_Pos   (25UL)                    /*!< TT_SCU LOCAL_RST0: SENT3 (Bit 25)                 */
#define TT_SCU_LOCAL_RST0_SENT3_Msk   (0x2000000UL)             /*!< TT_SCU LOCAL_RST0: SENT3 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_SENT4_Pos   (26UL)                    /*!< TT_SCU LOCAL_RST0: SENT4 (Bit 26)                 */
#define TT_SCU_LOCAL_RST0_SENT4_Msk   (0x4000000UL)             /*!< TT_SCU LOCAL_RST0: SENT4 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_SENT5_Pos   (27UL)                    /*!< TT_SCU LOCAL_RST0: SENT5 (Bit 27)                 */
#define TT_SCU_LOCAL_RST0_SENT5_Msk   (0x8000000UL)             /*!< TT_SCU LOCAL_RST0: SENT5 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_TIMER_Pos   (28UL)                    /*!< TT_SCU LOCAL_RST0: TIMER (Bit 28)                 */
#define TT_SCU_LOCAL_RST0_TIMER_Msk   (0x10000000UL)            /*!< TT_SCU LOCAL_RST0: TIMER (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_UART0_Pos   (29UL)                    /*!< TT_SCU LOCAL_RST0: UART0 (Bit 29)                 */
#define TT_SCU_LOCAL_RST0_UART0_Msk   (0x20000000UL)            /*!< TT_SCU LOCAL_RST0: UART0 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_UART1_Pos   (30UL)                    /*!< TT_SCU LOCAL_RST0: UART1 (Bit 30)                 */
#define TT_SCU_LOCAL_RST0_UART1_Msk   (0x40000000UL)            /*!< TT_SCU LOCAL_RST0: UART1 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST0_UART2_Pos   (31UL)                    /*!< TT_SCU LOCAL_RST0: UART2 (Bit 31)                 */
#define TT_SCU_LOCAL_RST0_UART2_Msk   (0x80000000UL)            /*!< TT_SCU LOCAL_RST0: UART2 (Bitfield-Mask: 0x01)    */
/* ======================================================  LOCAL_RST1  ======================================================= */
#define TT_SCU_LOCAL_RST1_UART3_Pos   (0UL)                     /*!< TT_SCU LOCAL_RST1: UART3 (Bit 0)                  */
#define TT_SCU_LOCAL_RST1_UART3_Msk   (0x1UL)                   /*!< TT_SCU LOCAL_RST1: UART3 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST1_WDT_Pos     (1UL)                     /*!< TT_SCU LOCAL_RST1: WDT (Bit 1)                    */
#define TT_SCU_LOCAL_RST1_WDT_Msk     (0x2UL)                   /*!< TT_SCU LOCAL_RST1: WDT (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST1_QSPI0_Pos   (2UL)                     /*!< TT_SCU LOCAL_RST1: QSPI0 (Bit 2)                  */
#define TT_SCU_LOCAL_RST1_QSPI0_Msk   (0x4UL)                   /*!< TT_SCU LOCAL_RST1: QSPI0 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST1_SSP7_Pos    (3UL)                     /*!< TT_SCU LOCAL_RST1: SSP7 (Bit 3)                   */
#define TT_SCU_LOCAL_RST1_SSP7_Msk    (0x8UL)                   /*!< TT_SCU LOCAL_RST1: SSP7 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_SSP0_Pos    (4UL)                     /*!< TT_SCU LOCAL_RST1: SSP0 (Bit 4)                   */
#define TT_SCU_LOCAL_RST1_SSP0_Msk    (0x10UL)                  /*!< TT_SCU LOCAL_RST1: SSP0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_SSP1_Pos    (5UL)                     /*!< TT_SCU LOCAL_RST1: SSP1 (Bit 5)                   */
#define TT_SCU_LOCAL_RST1_SSP1_Msk    (0x20UL)                  /*!< TT_SCU LOCAL_RST1: SSP1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_SSP2_Pos    (6UL)                     /*!< TT_SCU LOCAL_RST1: SSP2 (Bit 6)                   */
#define TT_SCU_LOCAL_RST1_SSP2_Msk    (0x40UL)                  /*!< TT_SCU LOCAL_RST1: SSP2 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_SSP3_Pos    (7UL)                     /*!< TT_SCU LOCAL_RST1: SSP3 (Bit 7)                   */
#define TT_SCU_LOCAL_RST1_SSP3_Msk    (0x80UL)                  /*!< TT_SCU LOCAL_RST1: SSP3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_SSP4_Pos    (8UL)                     /*!< TT_SCU LOCAL_RST1: SSP4 (Bit 8)                   */
#define TT_SCU_LOCAL_RST1_SSP4_Msk    (0x100UL)                 /*!< TT_SCU LOCAL_RST1: SSP4 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_SSP5_Pos    (9UL)                     /*!< TT_SCU LOCAL_RST1: SSP5 (Bit 9)                   */
#define TT_SCU_LOCAL_RST1_SSP5_Msk    (0x200UL)                 /*!< TT_SCU LOCAL_RST1: SSP5 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_I2C0_Pos    (10UL)                    /*!< TT_SCU LOCAL_RST1: I2C0 (Bit 10)                  */
#define TT_SCU_LOCAL_RST1_I2C0_Msk    (0x400UL)                 /*!< TT_SCU LOCAL_RST1: I2C0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_I2C1_Pos    (11UL)                    /*!< TT_SCU LOCAL_RST1: I2C1 (Bit 11)                  */
#define TT_SCU_LOCAL_RST1_I2C1_Msk    (0x800UL)                 /*!< TT_SCU LOCAL_RST1: I2C1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN0_Pos    (12UL)                    /*!< TT_SCU LOCAL_RST1: LIN0 (Bit 12)                  */
#define TT_SCU_LOCAL_RST1_LIN0_Msk    (0x1000UL)                /*!< TT_SCU LOCAL_RST1: LIN0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN1_Pos    (13UL)                    /*!< TT_SCU LOCAL_RST1: LIN1 (Bit 13)                  */
#define TT_SCU_LOCAL_RST1_LIN1_Msk    (0x2000UL)                /*!< TT_SCU LOCAL_RST1: LIN1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN2_Pos    (14UL)                    /*!< TT_SCU LOCAL_RST1: LIN2 (Bit 14)                  */
#define TT_SCU_LOCAL_RST1_LIN2_Msk    (0x4000UL)                /*!< TT_SCU LOCAL_RST1: LIN2 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN3_Pos    (15UL)                    /*!< TT_SCU LOCAL_RST1: LIN3 (Bit 15)                  */
#define TT_SCU_LOCAL_RST1_LIN3_Msk    (0x8000UL)                /*!< TT_SCU LOCAL_RST1: LIN3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN4_Pos    (16UL)                    /*!< TT_SCU LOCAL_RST1: LIN4 (Bit 16)                  */
#define TT_SCU_LOCAL_RST1_LIN4_Msk    (0x10000UL)               /*!< TT_SCU LOCAL_RST1: LIN4 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN5_Pos    (17UL)                    /*!< TT_SCU LOCAL_RST1: LIN5 (Bit 17)                  */
#define TT_SCU_LOCAL_RST1_LIN5_Msk    (0x20000UL)               /*!< TT_SCU LOCAL_RST1: LIN5 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN6_Pos    (18UL)                    /*!< TT_SCU LOCAL_RST1: LIN6 (Bit 18)                  */
#define TT_SCU_LOCAL_RST1_LIN6_Msk    (0x40000UL)               /*!< TT_SCU LOCAL_RST1: LIN6 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN7_Pos    (19UL)                    /*!< TT_SCU LOCAL_RST1: LIN7 (Bit 19)                  */
#define TT_SCU_LOCAL_RST1_LIN7_Msk    (0x80000UL)               /*!< TT_SCU LOCAL_RST1: LIN7 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN8_Pos    (20UL)                    /*!< TT_SCU LOCAL_RST1: LIN8 (Bit 20)                  */
#define TT_SCU_LOCAL_RST1_LIN8_Msk    (0x100000UL)              /*!< TT_SCU LOCAL_RST1: LIN8 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN9_Pos    (21UL)                    /*!< TT_SCU LOCAL_RST1: LIN9 (Bit 21)                  */
#define TT_SCU_LOCAL_RST1_LIN9_Msk    (0x200000UL)              /*!< TT_SCU LOCAL_RST1: LIN9 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_LIN10_Pos   (22UL)                    /*!< TT_SCU LOCAL_RST1: LIN10 (Bit 22)                 */
#define TT_SCU_LOCAL_RST1_LIN10_Msk   (0x400000UL)              /*!< TT_SCU LOCAL_RST1: LIN10 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST1_LIN11_Pos   (23UL)                    /*!< TT_SCU LOCAL_RST1: LIN11 (Bit 23)                 */
#define TT_SCU_LOCAL_RST1_LIN11_Msk   (0x800000UL)              /*!< TT_SCU LOCAL_RST1: LIN11 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST1_LIN12_Pos   (24UL)                    /*!< TT_SCU LOCAL_RST1: LIN12 (Bit 24)                 */
#define TT_SCU_LOCAL_RST1_LIN12_Msk   (0x1000000UL)             /*!< TT_SCU LOCAL_RST1: LIN12 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST1_LIN13_Pos   (25UL)                    /*!< TT_SCU LOCAL_RST1: LIN13 (Bit 25)                 */
#define TT_SCU_LOCAL_RST1_LIN13_Msk   (0x2000000UL)             /*!< TT_SCU LOCAL_RST1: LIN13 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST1_LIN14_Pos   (26UL)                    /*!< TT_SCU LOCAL_RST1: LIN14 (Bit 26)                 */
#define TT_SCU_LOCAL_RST1_LIN14_Msk   (0x4000000UL)             /*!< TT_SCU LOCAL_RST1: LIN14 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST1_LIN15_Pos   (27UL)                    /*!< TT_SCU LOCAL_RST1: LIN15 (Bit 27)                 */
#define TT_SCU_LOCAL_RST1_LIN15_Msk   (0x8000000UL)             /*!< TT_SCU LOCAL_RST1: LIN15 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST1_SSP6_Pos    (28UL)                    /*!< TT_SCU LOCAL_RST1: SSP6 (Bit 28)                  */
#define TT_SCU_LOCAL_RST1_SSP6_Msk    (0x10000000UL)            /*!< TT_SCU LOCAL_RST1: SSP6 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_CAN0_Pos    (29UL)                    /*!< TT_SCU LOCAL_RST1: CAN0 (Bit 29)                  */
#define TT_SCU_LOCAL_RST1_CAN0_Msk    (0x20000000UL)            /*!< TT_SCU LOCAL_RST1: CAN0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_CAN1_Pos    (30UL)                    /*!< TT_SCU LOCAL_RST1: CAN1 (Bit 30)                  */
#define TT_SCU_LOCAL_RST1_CAN1_Msk    (0x40000000UL)            /*!< TT_SCU LOCAL_RST1: CAN1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST1_CAN2_Pos    (31UL)                    /*!< TT_SCU LOCAL_RST1: CAN2 (Bit 31)                  */
#define TT_SCU_LOCAL_RST1_CAN2_Msk    (0x80000000UL)            /*!< TT_SCU LOCAL_RST1: CAN2 (Bitfield-Mask: 0x01)     */
/* ======================================================  LOCAL_RST2  ======================================================= */
#define TT_SCU_LOCAL_RST2_CAN3_Pos    (0UL)                     /*!< TT_SCU LOCAL_RST2: CAN3 (Bit 0)                   */
#define TT_SCU_LOCAL_RST2_CAN3_Msk    (0x1UL)                   /*!< TT_SCU LOCAL_RST2: CAN3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST2_CAN4_Pos    (1UL)                     /*!< TT_SCU LOCAL_RST2: CAN4 (Bit 1)                   */
#define TT_SCU_LOCAL_RST2_CAN4_Msk    (0x2UL)                   /*!< TT_SCU LOCAL_RST2: CAN4 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST2_CAN5_Pos    (2UL)                     /*!< TT_SCU LOCAL_RST2: CAN5 (Bit 2)                   */
#define TT_SCU_LOCAL_RST2_CAN5_Msk    (0x4UL)                   /*!< TT_SCU LOCAL_RST2: CAN5 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST2_CAN6_Pos    (3UL)                     /*!< TT_SCU LOCAL_RST2: CAN6 (Bit 3)                   */
#define TT_SCU_LOCAL_RST2_CAN6_Msk    (0x8UL)                   /*!< TT_SCU LOCAL_RST2: CAN6 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST2_CAN7_Pos    (4UL)                     /*!< TT_SCU LOCAL_RST2: CAN7 (Bit 4)                   */
#define TT_SCU_LOCAL_RST2_CAN7_Msk    (0x10UL)                  /*!< TT_SCU LOCAL_RST2: CAN7 (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST2_SENT7_Pos   (5UL)                     /*!< TT_SCU LOCAL_RST2: SENT7 (Bit 5)                  */
#define TT_SCU_LOCAL_RST2_SENT7_Msk   (0x20UL)                  /*!< TT_SCU LOCAL_RST2: SENT7 (Bitfield-Mask: 0x01)    */
#define TT_SCU_LOCAL_RST2_CIP_SHIELD_Pos (9UL)                  /*!< TT_SCU LOCAL_RST2: CIP_SHIELD (Bit 9)             */
#define TT_SCU_LOCAL_RST2_CIP_SHIELD_Msk (0x200UL)              /*!< TT_SCU LOCAL_RST2: CIP_SHIELD (Bitfield-Mask: 0x01) */
#define TT_SCU_LOCAL_RST2_PKI_Pos     (10UL)                    /*!< TT_SCU LOCAL_RST2: PKI (Bit 10)                   */
#define TT_SCU_LOCAL_RST2_PKI_Msk     (0x400UL)                 /*!< TT_SCU LOCAL_RST2: PKI (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST2_HASH_Pos    (11UL)                    /*!< TT_SCU LOCAL_RST2: HASH (Bit 11)                  */
#define TT_SCU_LOCAL_RST2_HASH_Msk    (0x800UL)                 /*!< TT_SCU LOCAL_RST2: HASH (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST2_SKA_Pos     (12UL)                    /*!< TT_SCU LOCAL_RST2: SKA (Bit 12)                   */
#define TT_SCU_LOCAL_RST2_SKA_Msk     (0x1000UL)                /*!< TT_SCU LOCAL_RST2: SKA (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST2_SM4_Pos     (13UL)                    /*!< TT_SCU LOCAL_RST2: SM4 (Bit 13)                   */
#define TT_SCU_LOCAL_RST2_SM4_Msk     (0x2000UL)                /*!< TT_SCU LOCAL_RST2: SM4 (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST2_LASER1_Pos  (14UL)                    /*!< TT_SCU LOCAL_RST2: LASER1 (Bit 14)                */
#define TT_SCU_LOCAL_RST2_LASER1_Msk  (0x4000UL)                /*!< TT_SCU LOCAL_RST2: LASER1 (Bitfield-Mask: 0x01)   */
#define TT_SCU_LOCAL_RST2_TRNG_Pos    (15UL)                    /*!< TT_SCU LOCAL_RST2: TRNG (Bit 15)                  */
#define TT_SCU_LOCAL_RST2_TRNG_Msk    (0x8000UL)                /*!< TT_SCU LOCAL_RST2: TRNG (Bitfield-Mask: 0x01)     */
#define TT_SCU_LOCAL_RST2_MBX_Pos     (16UL)                    /*!< TT_SCU LOCAL_RST2: MBX (Bit 16)                   */
#define TT_SCU_LOCAL_RST2_MBX_Msk     (0x10000UL)               /*!< TT_SCU LOCAL_RST2: MBX (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST2_ADC_Pos     (17UL)                    /*!< TT_SCU LOCAL_RST2: ADC (Bit 17)                   */
#define TT_SCU_LOCAL_RST2_ADC_Msk     (0x20000UL)               /*!< TT_SCU LOCAL_RST2: ADC (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST2_Gtm_Pos     (28UL)                    /*!< TT_SCU LOCAL_RST2: Gtm (Bit 28)                   */
#define TT_SCU_LOCAL_RST2_Gtm_Msk     (0x10000000UL)            /*!< TT_SCU LOCAL_RST2: Gtm (Bitfield-Mask: 0x01)      */
#define TT_SCU_LOCAL_RST2_HSM_SUBSYSTEM_Pos (29UL)              /*!< TT_SCU LOCAL_RST2: HSM_SUBSYSTEM (Bit 29)         */
#define TT_SCU_LOCAL_RST2_HSM_SUBSYSTEM_Msk (0x20000000UL)      /*!< TT_SCU LOCAL_RST2: HSM_SUBSYSTEM (Bitfield-Mask: 0x01) */
#define TT_SCU_LOCAL_RST2_M7_CORE_Pos (30UL)                    /*!< TT_SCU LOCAL_RST2: M7_CORE (Bit 30)               */
#define TT_SCU_LOCAL_RST2_M7_CORE_Msk (0x40000000UL)            /*!< TT_SCU LOCAL_RST2: M7_CORE (Bitfield-Mask: 0x01)  */
/* ========================================================  M7_VTOR  ======================================================== */
#define TT_SCU_M7_VTOR_ADDR_Pos       (0UL)                     /*!< TT_SCU M7_VTOR: ADDR (Bit 0)                      */
#define TT_SCU_M7_VTOR_ADDR_Msk       (0xffffffffUL)            /*!< TT_SCU M7_VTOR: ADDR (Bitfield-Mask: 0xffffffff)  */
/* ========================================================  BPIN_CR  ======================================================== */
#define TT_SCU_BPIN_CR_BOOT_SEL_Pos   (0UL)                     /*!< TT_SCU BPIN_CR: BOOT_SEL (Bit 0)                  */
#define TT_SCU_BPIN_CR_BOOT_SEL_Msk   (0x3UL)                   /*!< TT_SCU BPIN_CR: BOOT_SEL (Bitfield-Mask: 0x03)    */
#define TT_SCU_BPIN_CR_BOOT_SEL_Update_Pos (31UL)               /*!< TT_SCU BPIN_CR: BOOT_SEL_Update (Bit 31)          */
#define TT_SCU_BPIN_CR_BOOT_SEL_Update_Msk (0x80000000UL)       /*!< TT_SCU BPIN_CR: BOOT_SEL_Update (Bitfield-Mask: 0x01) */
/* ===================================================  RGU_RSTB_DEGLITCH  =================================================== */
#define TT_SCU_RGU_RSTB_DEGLITCH_TDH_Pos (0UL)                  /*!< TT_SCU RGU_RSTB_DEGLITCH: TDH (Bit 0)             */
#define TT_SCU_RGU_RSTB_DEGLITCH_TDH_Msk (0x1ffUL)              /*!< TT_SCU RGU_RSTB_DEGLITCH: TDH (Bitfield-Mask: 0x1ff) */
#define TT_SCU_RGU_RSTB_DEGLITCH_ENABLE_Pos (31UL)              /*!< TT_SCU RGU_RSTB_DEGLITCH: ENABLE (Bit 31)         */
#define TT_SCU_RGU_RSTB_DEGLITCH_ENABLE_Msk (0x80000000UL)      /*!< TT_SCU RGU_RSTB_DEGLITCH: ENABLE (Bitfield-Mask: 0x01) */
/* ====================================================  RGU_SRAM_CLR_CR  ==================================================== */
#define TT_SCU_RGU_SRAM_CLR_CR_RSTB_PIN_CLR_SRAM_Pos (2UL)      /*!< TT_SCU RGU_SRAM_CLR_CR: RSTB_PIN_CLR_SRAM (Bit 2) */
#define TT_SCU_RGU_SRAM_CLR_CR_RSTB_PIN_CLR_SRAM_Msk (0x4UL)    /*!< TT_SCU RGU_SRAM_CLR_CR: RSTB_PIN_CLR_SRAM (Bitfield-Mask: 0x01) */
#define TT_SCU_RGU_SRAM_CLR_CR_LBIST_ERR_CLR_SRAM_Pos (3UL)     /*!< TT_SCU RGU_SRAM_CLR_CR: LBIST_ERR_CLR_SRAM (Bit 3) */
#define TT_SCU_RGU_SRAM_CLR_CR_LBIST_ERR_CLR_SRAM_Msk (0x8UL)   /*!< TT_SCU RGU_SRAM_CLR_CR: LBIST_ERR_CLR_SRAM (Bitfield-Mask: 0x01) */
#define TT_SCU_RGU_SRAM_CLR_CR_LBIST_NORMAL_CLR_SRAM_Pos (4UL)  /*!< TT_SCU RGU_SRAM_CLR_CR: LBIST_NORMAL_CLR_SRAM (Bit 4) */
#define TT_SCU_RGU_SRAM_CLR_CR_LBIST_NORMAL_CLR_SRAM_Msk (0x10UL) /*!< TT_SCU RGU_SRAM_CLR_CR: LBIST_NORMAL_CLR_SRAM (Bitfield-Mask: 0x01) */
#define TT_SCU_RGU_SRAM_CLR_CR_SMU_CLR_SRAM_Pos (5UL)           /*!< TT_SCU RGU_SRAM_CLR_CR: SMU_CLR_SRAM (Bit 5)      */
#define TT_SCU_RGU_SRAM_CLR_CR_SMU_CLR_SRAM_Msk (0x20UL)        /*!< TT_SCU RGU_SRAM_CLR_CR: SMU_CLR_SRAM (Bitfield-Mask: 0x01) */
/* ========================================================  ECO_CTL  ======================================================== */
#define TT_SCU_ECO_CTL_FEB_Pos        (0UL)                     /*!< TT_SCU ECO_CTL: FEB (Bit 0)                       */
#define TT_SCU_ECO_CTL_FEB_Msk        (0x1UL)                   /*!< TT_SCU ECO_CTL: FEB (Bitfield-Mask: 0x01)         */
#define TT_SCU_ECO_CTL_S0_S1_Pos      (1UL)                     /*!< TT_SCU ECO_CTL: S0_S1 (Bit 1)                     */
#define TT_SCU_ECO_CTL_S0_S1_Msk      (0x6UL)                   /*!< TT_SCU ECO_CTL: S0_S1 (Bitfield-Mask: 0x03)       */
#define TT_SCU_ECO_CTL_EB_B_Pos       (3UL)                     /*!< TT_SCU ECO_CTL: EB_B (Bit 3)                      */
#define TT_SCU_ECO_CTL_EB_B_Msk       (0x18UL)                  /*!< TT_SCU ECO_CTL: EB_B (Bitfield-Mask: 0x03)        */
/* =======================================================  MPLL_CTL  ======================================================== */
#define TT_SCU_MPLL_CTL_MS_Pos        (0UL)                     /*!< TT_SCU MPLL_CTL: MS (Bit 0)                       */
#define TT_SCU_MPLL_CTL_MS_Msk        (0xfUL)                   /*!< TT_SCU MPLL_CTL: MS (Bitfield-Mask: 0x0f)         */
#define TT_SCU_MPLL_CTL_NS_Pos        (4UL)                     /*!< TT_SCU MPLL_CTL: NS (Bit 4)                       */
#define TT_SCU_MPLL_CTL_NS_Msk        (0x1ff0UL)                /*!< TT_SCU MPLL_CTL: NS (Bitfield-Mask: 0x1ff)        */
#define TT_SCU_MPLL_CTL_FR_Pos        (13UL)                    /*!< TT_SCU MPLL_CTL: FR (Bit 13)                      */
#define TT_SCU_MPLL_CTL_FR_Msk        (0xe000UL)                /*!< TT_SCU MPLL_CTL: FR (Bitfield-Mask: 0x07)         */
#define TT_SCU_MPLL_CTL_STANDBY_Pos   (16UL)                    /*!< TT_SCU MPLL_CTL: STANDBY (Bit 16)                 */
#define TT_SCU_MPLL_CTL_STANDBY_Msk   (0x10000UL)               /*!< TT_SCU MPLL_CTL: STANDBY (Bitfield-Mask: 0x01)    */
#define TT_SCU_MPLL_CTL_REF_SEL_Pos   (17UL)                    /*!< TT_SCU MPLL_CTL: REF_SEL (Bit 17)                 */
#define TT_SCU_MPLL_CTL_REF_SEL_Msk   (0x20000UL)               /*!< TT_SCU MPLL_CTL: REF_SEL (Bitfield-Mask: 0x01)    */
#define TT_SCU_MPLL_CTL_BYPASS_Pos    (18UL)                    /*!< TT_SCU MPLL_CTL: BYPASS (Bit 18)                  */
#define TT_SCU_MPLL_CTL_BYPASS_Msk    (0x40000UL)               /*!< TT_SCU MPLL_CTL: BYPASS (Bitfield-Mask: 0x01)     */
#define TT_SCU_MPLL_CTL_RSTB_Pos      (19UL)                    /*!< TT_SCU MPLL_CTL: RSTB (Bit 19)                    */
#define TT_SCU_MPLL_CTL_RSTB_Msk      (0x80000UL)               /*!< TT_SCU MPLL_CTL: RSTB (Bitfield-Mask: 0x01)       */
#define TT_SCU_MPLL_CTL_LOCK_Pos      (31UL)                    /*!< TT_SCU MPLL_CTL: LOCK (Bit 31)                    */
#define TT_SCU_MPLL_CTL_LOCK_Msk      (0x80000000UL)            /*!< TT_SCU MPLL_CTL: LOCK (Bitfield-Mask: 0x01)       */
/* =======================================================  EPLL_CTL  ======================================================== */
#define TT_SCU_EPLL_CTL_MS_Pos        (0UL)                     /*!< TT_SCU EPLL_CTL: MS (Bit 0)                       */
#define TT_SCU_EPLL_CTL_MS_Msk        (0xfUL)                   /*!< TT_SCU EPLL_CTL: MS (Bitfield-Mask: 0x0f)         */
#define TT_SCU_EPLL_CTL_NS_Pos        (4UL)                     /*!< TT_SCU EPLL_CTL: NS (Bit 4)                       */
#define TT_SCU_EPLL_CTL_NS_Msk        (0x1ff0UL)                /*!< TT_SCU EPLL_CTL: NS (Bitfield-Mask: 0x1ff)        */
#define TT_SCU_EPLL_CTL_FR_Pos        (13UL)                    /*!< TT_SCU EPLL_CTL: FR (Bit 13)                      */
#define TT_SCU_EPLL_CTL_FR_Msk        (0xe000UL)                /*!< TT_SCU EPLL_CTL: FR (Bitfield-Mask: 0x07)         */
#define TT_SCU_EPLL_CTL_STANDBY_Pos   (16UL)                    /*!< TT_SCU EPLL_CTL: STANDBY (Bit 16)                 */
#define TT_SCU_EPLL_CTL_STANDBY_Msk   (0x10000UL)               /*!< TT_SCU EPLL_CTL: STANDBY (Bitfield-Mask: 0x01)    */
#define TT_SCU_EPLL_CTL_REF_SEL_Pos   (17UL)                    /*!< TT_SCU EPLL_CTL: REF_SEL (Bit 17)                 */
#define TT_SCU_EPLL_CTL_REF_SEL_Msk   (0x20000UL)               /*!< TT_SCU EPLL_CTL: REF_SEL (Bitfield-Mask: 0x01)    */
#define TT_SCU_EPLL_CTL_BYPASS_Pos    (18UL)                    /*!< TT_SCU EPLL_CTL: BYPASS (Bit 18)                  */
#define TT_SCU_EPLL_CTL_BYPASS_Msk    (0x40000UL)               /*!< TT_SCU EPLL_CTL: BYPASS (Bitfield-Mask: 0x01)     */
#define TT_SCU_EPLL_CTL_RSTB_Pos      (19UL)                    /*!< TT_SCU EPLL_CTL: RSTB (Bit 19)                    */
#define TT_SCU_EPLL_CTL_RSTB_Msk      (0x80000UL)               /*!< TT_SCU EPLL_CTL: RSTB (Bitfield-Mask: 0x01)       */
#define TT_SCU_EPLL_CTL_LOCK_Pos      (31UL)                    /*!< TT_SCU EPLL_CTL: LOCK (Bit 31)                    */
#define TT_SCU_EPLL_CTL_LOCK_Msk      (0x80000000UL)            /*!< TT_SCU EPLL_CTL: LOCK (Bitfield-Mask: 0x01)       */
/* ======================================================  CLKDIV_CTL0  ====================================================== */
#define TT_SCU_CLKDIV_CTL0_DIV_PERI0_Pos (4UL)                  /*!< TT_SCU CLKDIV_CTL0: DIV_PERI0 (Bit 4)             */
#define TT_SCU_CLKDIV_CTL0_DIV_PERI0_Msk (0x10UL)               /*!< TT_SCU CLKDIV_CTL0: DIV_PERI0 (Bitfield-Mask: 0x01) */
#define TT_SCU_CLKDIV_CTL0_DIV_PERI1_Pos (5UL)                  /*!< TT_SCU CLKDIV_CTL0: DIV_PERI1 (Bit 5)             */
#define TT_SCU_CLKDIV_CTL0_DIV_PERI1_Msk (0x20UL)               /*!< TT_SCU CLKDIV_CTL0: DIV_PERI1 (Bitfield-Mask: 0x01) */
#define TT_SCU_CLKDIV_CTL0_DIV_PERI2_Pos (6UL)                  /*!< TT_SCU CLKDIV_CTL0: DIV_PERI2 (Bit 6)             */
#define TT_SCU_CLKDIV_CTL0_DIV_PERI2_Msk (0x40UL)               /*!< TT_SCU CLKDIV_CTL0: DIV_PERI2 (Bitfield-Mask: 0x01) */
#define TT_SCU_CLKDIV_CTL0_DIV_PERI3_Pos (7UL)                  /*!< TT_SCU CLKDIV_CTL0: DIV_PERI3 (Bit 7)             */
#define TT_SCU_CLKDIV_CTL0_DIV_PERI3_Msk (0x80UL)               /*!< TT_SCU CLKDIV_CTL0: DIV_PERI3 (Bitfield-Mask: 0x01) */
#define TT_SCU_CLKDIV_CTL0_DIV_SM4_CFG_Pos (12UL)               /*!< TT_SCU CLKDIV_CTL0: DIV_SM4_CFG (Bit 12)          */
#define TT_SCU_CLKDIV_CTL0_DIV_SM4_CFG_Msk (0xf000UL)           /*!< TT_SCU CLKDIV_CTL0: DIV_SM4_CFG (Bitfield-Mask: 0x0f) */
#define TT_SCU_CLKDIV_CTL0_DIV_SKA_CFG_Pos (16UL)               /*!< TT_SCU CLKDIV_CTL0: DIV_SKA_CFG (Bit 16)          */
#define TT_SCU_CLKDIV_CTL0_DIV_SKA_CFG_Msk (0xf0000UL)          /*!< TT_SCU CLKDIV_CTL0: DIV_SKA_CFG (Bitfield-Mask: 0x0f) */
#define TT_SCU_CLKDIV_CTL0_DIV_HASH_CFG_Pos (20UL)              /*!< TT_SCU CLKDIV_CTL0: DIV_HASH_CFG (Bit 20)         */
#define TT_SCU_CLKDIV_CTL0_DIV_HASH_CFG_Msk (0xf00000UL)        /*!< TT_SCU CLKDIV_CTL0: DIV_HASH_CFG (Bitfield-Mask: 0x0f) */
#define TT_SCU_CLKDIV_CTL0_DIV_ECO_CFG_Pos (24UL)               /*!< TT_SCU CLKDIV_CTL0: DIV_ECO_CFG (Bit 24)          */
#define TT_SCU_CLKDIV_CTL0_DIV_ECO_CFG_Msk (0xf000000UL)        /*!< TT_SCU CLKDIV_CTL0: DIV_ECO_CFG (Bitfield-Mask: 0x0f) */
#define TT_SCU_CLKDIV_CTL0_DIV_BUS_CFG_Pos (31UL)               /*!< TT_SCU CLKDIV_CTL0: DIV_BUS_CFG (Bit 31)          */
#define TT_SCU_CLKDIV_CTL0_DIV_BUS_CFG_Msk (0x80000000UL)       /*!< TT_SCU CLKDIV_CTL0: DIV_BUS_CFG (Bitfield-Mask: 0x01) */
/* ======================================================  CLKDIV_CTL1  ====================================================== */
#define TT_SCU_CLKDIV_CTL1_DIV_EMAC_RXTX_CFG_Pos (0UL)          /*!< TT_SCU CLKDIV_CTL1: DIV_EMAC_RXTX_CFG (Bit 0)     */
#define TT_SCU_CLKDIV_CTL1_DIV_EMAC_RXTX_CFG_Msk (0x1UL)        /*!< TT_SCU CLKDIV_CTL1: DIV_EMAC_RXTX_CFG (Bitfield-Mask: 0x01) */
#define TT_SCU_CLKDIV_CTL1_DIV_EMAC_RMII_CFG_Pos (8UL)          /*!< TT_SCU CLKDIV_CTL1: DIV_EMAC_RMII_CFG (Bit 8)     */
#define TT_SCU_CLKDIV_CTL1_DIV_EMAC_RMII_CFG_Msk (0x700UL)      /*!< TT_SCU CLKDIV_CTL1: DIV_EMAC_RMII_CFG (Bitfield-Mask: 0x07) */
#define TT_SCU_CLKDIV_CTL1_DIV_EMAC_PTP_REF_CFG_Pos (12UL)      /*!< TT_SCU CLKDIV_CTL1: DIV_EMAC_PTP_REF_CFG (Bit 12) */
#define TT_SCU_CLKDIV_CTL1_DIV_EMAC_PTP_REF_CFG_Msk (0x7000UL)  /*!< TT_SCU CLKDIV_CTL1: DIV_EMAC_PTP_REF_CFG (Bitfield-Mask: 0x07) */
#define TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG_Pos (20UL)            /*!< TT_SCU CLKDIV_CTL1: DIV_CAN_PE_CFG (Bit 20)       */
#define TT_SCU_CLKDIV_CTL1_DIV_CAN_PE_CFG_Msk (0x700000UL)      /*!< TT_SCU CLKDIV_CTL1: DIV_CAN_PE_CFG (Bitfield-Mask: 0x07) */
#define TT_SCU_CLKDIV_CTL1_DIV_I3C0_CFG_Pos (28UL)              /*!< TT_SCU CLKDIV_CTL1: DIV_I3C0_CFG (Bit 28)         */
#define TT_SCU_CLKDIV_CTL1_DIV_I3C0_CFG_Msk (0xf0000000UL)      /*!< TT_SCU CLKDIV_CTL1: DIV_I3C0_CFG (Bitfield-Mask: 0x0f) */
/* ======================================================  CLKDIV_CTL2  ====================================================== */
#define TT_SCU_CLKDIV_CTL2_DIV_I2S0_MCLK_FRAC_Pos (0UL)         /*!< TT_SCU CLKDIV_CTL2: DIV_I2S0_MCLK_FRAC (Bit 0)    */
#define TT_SCU_CLKDIV_CTL2_DIV_I2S0_MCLK_FRAC_Msk (0xfffUL)     /*!< TT_SCU CLKDIV_CTL2: DIV_I2S0_MCLK_FRAC (Bitfield-Mask: 0xfff) */
#define TT_SCU_CLKDIV_CTL2_DIV_I2S0_MCLK_INT_Pos (12UL)         /*!< TT_SCU CLKDIV_CTL2: DIV_I2S0_MCLK_INT (Bit 12)    */
#define TT_SCU_CLKDIV_CTL2_DIV_I2S0_MCLK_INT_Msk (0xf000UL)     /*!< TT_SCU CLKDIV_CTL2: DIV_I2S0_MCLK_INT (Bitfield-Mask: 0x0f) */
#define TT_SCU_CLKDIV_CTL2_DIV_I2S0_SCLK_FRAC_Pos (16UL)        /*!< TT_SCU CLKDIV_CTL2: DIV_I2S0_SCLK_FRAC (Bit 16)   */
#define TT_SCU_CLKDIV_CTL2_DIV_I2S0_SCLK_FRAC_Msk (0xfff0000UL) /*!< TT_SCU CLKDIV_CTL2: DIV_I2S0_SCLK_FRAC (Bitfield-Mask: 0xfff) */
#define TT_SCU_CLKDIV_CTL2_DIV_I2S0_SCLK_INT_Pos (28UL)         /*!< TT_SCU CLKDIV_CTL2: DIV_I2S0_SCLK_INT (Bit 28)    */
#define TT_SCU_CLKDIV_CTL2_DIV_I2S0_SCLK_INT_Msk (0xf0000000UL) /*!< TT_SCU CLKDIV_CTL2: DIV_I2S0_SCLK_INT (Bitfield-Mask: 0x0f) */
/* =======================================================  CLK_STOP0  ======================================================= */
#define TT_SCU_CLK_STOP0_FTM0_Pos     (0UL)                     /*!< TT_SCU CLK_STOP0: FTM0 (Bit 0)                    */
#define TT_SCU_CLK_STOP0_FTM0_Msk     (0x1UL)                   /*!< TT_SCU CLK_STOP0: FTM0 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_FTM1_Pos     (1UL)                     /*!< TT_SCU CLK_STOP0: FTM1 (Bit 1)                    */
#define TT_SCU_CLK_STOP0_FTM1_Msk     (0x2UL)                   /*!< TT_SCU CLK_STOP0: FTM1 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_FTM2_Pos     (2UL)                     /*!< TT_SCU CLK_STOP0: FTM2 (Bit 2)                    */
#define TT_SCU_CLK_STOP0_FTM2_Msk     (0x4UL)                   /*!< TT_SCU CLK_STOP0: FTM2 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_FTM3_Pos     (3UL)                     /*!< TT_SCU CLK_STOP0: FTM3 (Bit 3)                    */
#define TT_SCU_CLK_STOP0_FTM3_Msk     (0x8UL)                   /*!< TT_SCU CLK_STOP0: FTM3 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_FTM4_Pos     (4UL)                     /*!< TT_SCU CLK_STOP0: FTM4 (Bit 4)                    */
#define TT_SCU_CLK_STOP0_FTM4_Msk     (0x10UL)                  /*!< TT_SCU CLK_STOP0: FTM4 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_FTM5_Pos     (5UL)                     /*!< TT_SCU CLK_STOP0: FTM5 (Bit 5)                    */
#define TT_SCU_CLK_STOP0_FTM5_Msk     (0x20UL)                  /*!< TT_SCU CLK_STOP0: FTM5 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_I3C0_Pos     (6UL)                     /*!< TT_SCU CLK_STOP0: I3C0 (Bit 6)                    */
#define TT_SCU_CLK_STOP0_I3C0_Msk     (0x40UL)                  /*!< TT_SCU CLK_STOP0: I3C0 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_CRC_Pos      (8UL)                     /*!< TT_SCU CLK_STOP0: CRC (Bit 8)                     */
#define TT_SCU_CLK_STOP0_CRC_Msk      (0x100UL)                 /*!< TT_SCU CLK_STOP0: CRC (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP0_DMAC0_Pos    (9UL)                     /*!< TT_SCU CLK_STOP0: DMAC0 (Bit 9)                   */
#define TT_SCU_CLK_STOP0_DMAC0_Msk    (0x200UL)                 /*!< TT_SCU CLK_STOP0: DMAC0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_DMAC1_Pos    (10UL)                    /*!< TT_SCU CLK_STOP0: DMAC1 (Bit 10)                  */
#define TT_SCU_CLK_STOP0_DMAC1_Msk    (0x400UL)                 /*!< TT_SCU CLK_STOP0: DMAC1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_DMAC2_Pos    (11UL)                    /*!< TT_SCU CLK_STOP0: DMAC2 (Bit 11)                  */
#define TT_SCU_CLK_STOP0_DMAC2_Msk    (0x800UL)                 /*!< TT_SCU CLK_STOP0: DMAC2 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_DMAC3_Pos    (12UL)                    /*!< TT_SCU CLK_STOP0: DMAC3 (Bit 12)                  */
#define TT_SCU_CLK_STOP0_DMAC3_Msk    (0x1000UL)                /*!< TT_SCU CLK_STOP0: DMAC3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_EMAC_Pos     (13UL)                    /*!< TT_SCU CLK_STOP0: EMAC (Bit 13)                   */
#define TT_SCU_CLK_STOP0_EMAC_Msk     (0x2000UL)                /*!< TT_SCU CLK_STOP0: EMAC (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_GPIOA_Pos    (14UL)                    /*!< TT_SCU CLK_STOP0: GPIOA (Bit 14)                  */
#define TT_SCU_CLK_STOP0_GPIOA_Msk    (0x4000UL)                /*!< TT_SCU CLK_STOP0: GPIOA (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_GPIOB_Pos    (15UL)                    /*!< TT_SCU CLK_STOP0: GPIOB (Bit 15)                  */
#define TT_SCU_CLK_STOP0_GPIOB_Msk    (0x8000UL)                /*!< TT_SCU CLK_STOP0: GPIOB (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_GPIOC_Pos    (16UL)                    /*!< TT_SCU CLK_STOP0: GPIOC (Bit 16)                  */
#define TT_SCU_CLK_STOP0_GPIOC_Msk    (0x10000UL)               /*!< TT_SCU CLK_STOP0: GPIOC (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_GPIOD_Pos    (17UL)                    /*!< TT_SCU CLK_STOP0: GPIOD (Bit 17)                  */
#define TT_SCU_CLK_STOP0_GPIOD_Msk    (0x20000UL)               /*!< TT_SCU CLK_STOP0: GPIOD (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_GPIOE_Pos    (18UL)                    /*!< TT_SCU CLK_STOP0: GPIOE (Bit 18)                  */
#define TT_SCU_CLK_STOP0_GPIOE_Msk    (0x40000UL)               /*!< TT_SCU CLK_STOP0: GPIOE (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_I2S0_Pos     (19UL)                    /*!< TT_SCU CLK_STOP0: I2S0 (Bit 19)                   */
#define TT_SCU_CLK_STOP0_I2S0_Msk     (0x80000UL)               /*!< TT_SCU CLK_STOP0: I2S0 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP0_SENT6_Pos    (20UL)                    /*!< TT_SCU CLK_STOP0: SENT6 (Bit 20)                  */
#define TT_SCU_CLK_STOP0_SENT6_Msk    (0x100000UL)              /*!< TT_SCU CLK_STOP0: SENT6 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_IOM_Pos      (21UL)                    /*!< TT_SCU CLK_STOP0: IOM (Bit 21)                    */
#define TT_SCU_CLK_STOP0_IOM_Msk      (0x200000UL)              /*!< TT_SCU CLK_STOP0: IOM (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP0_SENT0_Pos    (22UL)                    /*!< TT_SCU CLK_STOP0: SENT0 (Bit 22)                  */
#define TT_SCU_CLK_STOP0_SENT0_Msk    (0x400000UL)              /*!< TT_SCU CLK_STOP0: SENT0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_SENT1_Pos    (23UL)                    /*!< TT_SCU CLK_STOP0: SENT1 (Bit 23)                  */
#define TT_SCU_CLK_STOP0_SENT1_Msk    (0x800000UL)              /*!< TT_SCU CLK_STOP0: SENT1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_SENT2_Pos    (24UL)                    /*!< TT_SCU CLK_STOP0: SENT2 (Bit 24)                  */
#define TT_SCU_CLK_STOP0_SENT2_Msk    (0x1000000UL)             /*!< TT_SCU CLK_STOP0: SENT2 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_SENT3_Pos    (25UL)                    /*!< TT_SCU CLK_STOP0: SENT3 (Bit 25)                  */
#define TT_SCU_CLK_STOP0_SENT3_Msk    (0x2000000UL)             /*!< TT_SCU CLK_STOP0: SENT3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_SENT4_Pos    (26UL)                    /*!< TT_SCU CLK_STOP0: SENT4 (Bit 26)                  */
#define TT_SCU_CLK_STOP0_SENT4_Msk    (0x4000000UL)             /*!< TT_SCU CLK_STOP0: SENT4 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_SENT5_Pos    (27UL)                    /*!< TT_SCU CLK_STOP0: SENT5 (Bit 27)                  */
#define TT_SCU_CLK_STOP0_SENT5_Msk    (0x8000000UL)             /*!< TT_SCU CLK_STOP0: SENT5 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_TIMER_Pos    (28UL)                    /*!< TT_SCU CLK_STOP0: TIMER (Bit 28)                  */
#define TT_SCU_CLK_STOP0_TIMER_Msk    (0x10000000UL)            /*!< TT_SCU CLK_STOP0: TIMER (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_UART0_Pos    (29UL)                    /*!< TT_SCU CLK_STOP0: UART0 (Bit 29)                  */
#define TT_SCU_CLK_STOP0_UART0_Msk    (0x20000000UL)            /*!< TT_SCU CLK_STOP0: UART0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_UART1_Pos    (30UL)                    /*!< TT_SCU CLK_STOP0: UART1 (Bit 30)                  */
#define TT_SCU_CLK_STOP0_UART1_Msk    (0x40000000UL)            /*!< TT_SCU CLK_STOP0: UART1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP0_UART2_Pos    (31UL)                    /*!< TT_SCU CLK_STOP0: UART2 (Bit 31)                  */
#define TT_SCU_CLK_STOP0_UART2_Msk    (0x80000000UL)            /*!< TT_SCU CLK_STOP0: UART2 (Bitfield-Mask: 0x01)     */
/* =======================================================  CLK_STOP1  ======================================================= */
#define TT_SCU_CLK_STOP1_UART3_Pos    (0UL)                     /*!< TT_SCU CLK_STOP1: UART3 (Bit 0)                   */
#define TT_SCU_CLK_STOP1_UART3_Msk    (0x1UL)                   /*!< TT_SCU CLK_STOP1: UART3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP1_WDT_Pos      (1UL)                     /*!< TT_SCU CLK_STOP1: WDT (Bit 1)                     */
#define TT_SCU_CLK_STOP1_WDT_Msk      (0x2UL)                   /*!< TT_SCU CLK_STOP1: WDT (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP1_QSPI0_Pos    (2UL)                     /*!< TT_SCU CLK_STOP1: QSPI0 (Bit 2)                   */
#define TT_SCU_CLK_STOP1_QSPI0_Msk    (0x4UL)                   /*!< TT_SCU CLK_STOP1: QSPI0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP1_SSP7_Pos     (3UL)                     /*!< TT_SCU CLK_STOP1: SSP7 (Bit 3)                    */
#define TT_SCU_CLK_STOP1_SSP7_Msk     (0x8UL)                   /*!< TT_SCU CLK_STOP1: SSP7 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_SSP0_Pos     (4UL)                     /*!< TT_SCU CLK_STOP1: SSP0 (Bit 4)                    */
#define TT_SCU_CLK_STOP1_SSP0_Msk     (0x10UL)                  /*!< TT_SCU CLK_STOP1: SSP0 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_SSP1_Pos     (5UL)                     /*!< TT_SCU CLK_STOP1: SSP1 (Bit 5)                    */
#define TT_SCU_CLK_STOP1_SSP1_Msk     (0x20UL)                  /*!< TT_SCU CLK_STOP1: SSP1 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_SSP2_Pos     (6UL)                     /*!< TT_SCU CLK_STOP1: SSP2 (Bit 6)                    */
#define TT_SCU_CLK_STOP1_SSP2_Msk     (0x40UL)                  /*!< TT_SCU CLK_STOP1: SSP2 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_SSP3_Pos     (7UL)                     /*!< TT_SCU CLK_STOP1: SSP3 (Bit 7)                    */
#define TT_SCU_CLK_STOP1_SSP3_Msk     (0x80UL)                  /*!< TT_SCU CLK_STOP1: SSP3 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_SSP4_Pos     (8UL)                     /*!< TT_SCU CLK_STOP1: SSP4 (Bit 8)                    */
#define TT_SCU_CLK_STOP1_SSP4_Msk     (0x100UL)                 /*!< TT_SCU CLK_STOP1: SSP4 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_SSP5_Pos     (9UL)                     /*!< TT_SCU CLK_STOP1: SSP5 (Bit 9)                    */
#define TT_SCU_CLK_STOP1_SSP5_Msk     (0x200UL)                 /*!< TT_SCU CLK_STOP1: SSP5 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_I2C0_Pos     (10UL)                    /*!< TT_SCU CLK_STOP1: I2C0 (Bit 10)                   */
#define TT_SCU_CLK_STOP1_I2C0_Msk     (0x400UL)                 /*!< TT_SCU CLK_STOP1: I2C0 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_I2C1_Pos     (11UL)                    /*!< TT_SCU CLK_STOP1: I2C1 (Bit 11)                   */
#define TT_SCU_CLK_STOP1_I2C1_Msk     (0x800UL)                 /*!< TT_SCU CLK_STOP1: I2C1 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN0_Pos     (12UL)                    /*!< TT_SCU CLK_STOP1: LIN0 (Bit 12)                   */
#define TT_SCU_CLK_STOP1_LIN0_Msk     (0x1000UL)                /*!< TT_SCU CLK_STOP1: LIN0 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN1_Pos     (13UL)                    /*!< TT_SCU CLK_STOP1: LIN1 (Bit 13)                   */
#define TT_SCU_CLK_STOP1_LIN1_Msk     (0x2000UL)                /*!< TT_SCU CLK_STOP1: LIN1 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN2_Pos     (14UL)                    /*!< TT_SCU CLK_STOP1: LIN2 (Bit 14)                   */
#define TT_SCU_CLK_STOP1_LIN2_Msk     (0x4000UL)                /*!< TT_SCU CLK_STOP1: LIN2 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN3_Pos     (15UL)                    /*!< TT_SCU CLK_STOP1: LIN3 (Bit 15)                   */
#define TT_SCU_CLK_STOP1_LIN3_Msk     (0x8000UL)                /*!< TT_SCU CLK_STOP1: LIN3 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN4_Pos     (16UL)                    /*!< TT_SCU CLK_STOP1: LIN4 (Bit 16)                   */
#define TT_SCU_CLK_STOP1_LIN4_Msk     (0x10000UL)               /*!< TT_SCU CLK_STOP1: LIN4 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN5_Pos     (17UL)                    /*!< TT_SCU CLK_STOP1: LIN5 (Bit 17)                   */
#define TT_SCU_CLK_STOP1_LIN5_Msk     (0x20000UL)               /*!< TT_SCU CLK_STOP1: LIN5 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN6_Pos     (18UL)                    /*!< TT_SCU CLK_STOP1: LIN6 (Bit 18)                   */
#define TT_SCU_CLK_STOP1_LIN6_Msk     (0x40000UL)               /*!< TT_SCU CLK_STOP1: LIN6 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN7_Pos     (19UL)                    /*!< TT_SCU CLK_STOP1: LIN7 (Bit 19)                   */
#define TT_SCU_CLK_STOP1_LIN7_Msk     (0x80000UL)               /*!< TT_SCU CLK_STOP1: LIN7 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN8_Pos     (20UL)                    /*!< TT_SCU CLK_STOP1: LIN8 (Bit 20)                   */
#define TT_SCU_CLK_STOP1_LIN8_Msk     (0x100000UL)              /*!< TT_SCU CLK_STOP1: LIN8 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN9_Pos     (21UL)                    /*!< TT_SCU CLK_STOP1: LIN9 (Bit 21)                   */
#define TT_SCU_CLK_STOP1_LIN9_Msk     (0x200000UL)              /*!< TT_SCU CLK_STOP1: LIN9 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_LIN10_Pos    (22UL)                    /*!< TT_SCU CLK_STOP1: LIN10 (Bit 22)                  */
#define TT_SCU_CLK_STOP1_LIN10_Msk    (0x400000UL)              /*!< TT_SCU CLK_STOP1: LIN10 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP1_LIN11_Pos    (23UL)                    /*!< TT_SCU CLK_STOP1: LIN11 (Bit 23)                  */
#define TT_SCU_CLK_STOP1_LIN11_Msk    (0x800000UL)              /*!< TT_SCU CLK_STOP1: LIN11 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP1_LIN12_Pos    (24UL)                    /*!< TT_SCU CLK_STOP1: LIN12 (Bit 24)                  */
#define TT_SCU_CLK_STOP1_LIN12_Msk    (0x1000000UL)             /*!< TT_SCU CLK_STOP1: LIN12 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP1_LIN13_Pos    (25UL)                    /*!< TT_SCU CLK_STOP1: LIN13 (Bit 25)                  */
#define TT_SCU_CLK_STOP1_LIN13_Msk    (0x2000000UL)             /*!< TT_SCU CLK_STOP1: LIN13 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP1_LIN14_Pos    (26UL)                    /*!< TT_SCU CLK_STOP1: LIN14 (Bit 26)                  */
#define TT_SCU_CLK_STOP1_LIN14_Msk    (0x4000000UL)             /*!< TT_SCU CLK_STOP1: LIN14 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP1_LIN15_Pos    (27UL)                    /*!< TT_SCU CLK_STOP1: LIN15 (Bit 27)                  */
#define TT_SCU_CLK_STOP1_LIN15_Msk    (0x8000000UL)             /*!< TT_SCU CLK_STOP1: LIN15 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP1_SSP6_Pos     (28UL)                    /*!< TT_SCU CLK_STOP1: SSP6 (Bit 28)                   */
#define TT_SCU_CLK_STOP1_SSP6_Msk     (0x10000000UL)            /*!< TT_SCU CLK_STOP1: SSP6 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_CAN0_Pos     (29UL)                    /*!< TT_SCU CLK_STOP1: CAN0 (Bit 29)                   */
#define TT_SCU_CLK_STOP1_CAN0_Msk     (0x20000000UL)            /*!< TT_SCU CLK_STOP1: CAN0 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_CAN1_Pos     (30UL)                    /*!< TT_SCU CLK_STOP1: CAN1 (Bit 30)                   */
#define TT_SCU_CLK_STOP1_CAN1_Msk     (0x40000000UL)            /*!< TT_SCU CLK_STOP1: CAN1 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP1_CAN2_Pos     (31UL)                    /*!< TT_SCU CLK_STOP1: CAN2 (Bit 31)                   */
#define TT_SCU_CLK_STOP1_CAN2_Msk     (0x80000000UL)            /*!< TT_SCU CLK_STOP1: CAN2 (Bitfield-Mask: 0x01)      */
/* =======================================================  CLK_STOP2  ======================================================= */
#define TT_SCU_CLK_STOP2_CAN3_Pos     (0UL)                     /*!< TT_SCU CLK_STOP2: CAN3 (Bit 0)                    */
#define TT_SCU_CLK_STOP2_CAN3_Msk     (0x1UL)                   /*!< TT_SCU CLK_STOP2: CAN3 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP2_CAN4_Pos     (1UL)                     /*!< TT_SCU CLK_STOP2: CAN4 (Bit 1)                    */
#define TT_SCU_CLK_STOP2_CAN4_Msk     (0x2UL)                   /*!< TT_SCU CLK_STOP2: CAN4 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP2_CAN5_Pos     (2UL)                     /*!< TT_SCU CLK_STOP2: CAN5 (Bit 2)                    */
#define TT_SCU_CLK_STOP2_CAN5_Msk     (0x4UL)                   /*!< TT_SCU CLK_STOP2: CAN5 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP2_CAN6_Pos     (3UL)                     /*!< TT_SCU CLK_STOP2: CAN6 (Bit 3)                    */
#define TT_SCU_CLK_STOP2_CAN6_Msk     (0x8UL)                   /*!< TT_SCU CLK_STOP2: CAN6 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP2_CAN7_Pos     (4UL)                     /*!< TT_SCU CLK_STOP2: CAN7 (Bit 4)                    */
#define TT_SCU_CLK_STOP2_CAN7_Msk     (0x10UL)                  /*!< TT_SCU CLK_STOP2: CAN7 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP2_SENT7_Pos    (5UL)                     /*!< TT_SCU CLK_STOP2: SENT7 (Bit 5)                   */
#define TT_SCU_CLK_STOP2_SENT7_Msk    (0x20UL)                  /*!< TT_SCU CLK_STOP2: SENT7 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP2_TRIG_MUX_Pos (6UL)                     /*!< TT_SCU CLK_STOP2: TRIG_MUX (Bit 6)                */
#define TT_SCU_CLK_STOP2_TRIG_MUX_Msk (0x40UL)                  /*!< TT_SCU CLK_STOP2: TRIG_MUX (Bitfield-Mask: 0x01)  */
#define TT_SCU_CLK_STOP2_ADCSENSOR_Pos (7UL)                    /*!< TT_SCU CLK_STOP2: ADCSENSOR (Bit 7)               */
#define TT_SCU_CLK_STOP2_ADCSENSOR_Msk (0x80UL)                 /*!< TT_SCU CLK_STOP2: ADCSENSOR (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_STOP2_INTM_Pos     (8UL)                     /*!< TT_SCU CLK_STOP2: INTM (Bit 8)                    */
#define TT_SCU_CLK_STOP2_INTM_Msk     (0x100UL)                 /*!< TT_SCU CLK_STOP2: INTM (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP2_SHIELD_CIP_Pos (9UL)                   /*!< TT_SCU CLK_STOP2: SHIELD_CIP (Bit 9)              */
#define TT_SCU_CLK_STOP2_SHIELD_CIP_Msk (0x200UL)               /*!< TT_SCU CLK_STOP2: SHIELD_CIP (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_STOP2_PKI_Pos      (10UL)                    /*!< TT_SCU CLK_STOP2: PKI (Bit 10)                    */
#define TT_SCU_CLK_STOP2_PKI_Msk      (0x400UL)                 /*!< TT_SCU CLK_STOP2: PKI (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP2_HASH_Pos     (11UL)                    /*!< TT_SCU CLK_STOP2: HASH (Bit 11)                   */
#define TT_SCU_CLK_STOP2_HASH_Msk     (0x800UL)                 /*!< TT_SCU CLK_STOP2: HASH (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP2_SKA_Pos      (12UL)                    /*!< TT_SCU CLK_STOP2: SKA (Bit 12)                    */
#define TT_SCU_CLK_STOP2_SKA_Msk      (0x1000UL)                /*!< TT_SCU CLK_STOP2: SKA (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP2_SM4_Pos      (13UL)                    /*!< TT_SCU CLK_STOP2: SM4 (Bit 13)                    */
#define TT_SCU_CLK_STOP2_SM4_Msk      (0x2000UL)                /*!< TT_SCU CLK_STOP2: SM4 (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP2_LASER_CIP_Pos (14UL)                   /*!< TT_SCU CLK_STOP2: LASER_CIP (Bit 14)              */
#define TT_SCU_CLK_STOP2_LASER_CIP_Msk (0x4000UL)               /*!< TT_SCU CLK_STOP2: LASER_CIP (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_STOP2_TRNG_Pos     (15UL)                    /*!< TT_SCU CLK_STOP2: TRNG (Bit 15)                   */
#define TT_SCU_CLK_STOP2_TRNG_Msk     (0x8000UL)                /*!< TT_SCU CLK_STOP2: TRNG (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_STOP2_DEBUG_Pos    (16UL)                    /*!< TT_SCU CLK_STOP2: DEBUG (Bit 16)                  */
#define TT_SCU_CLK_STOP2_DEBUG_Msk    (0x10000UL)               /*!< TT_SCU CLK_STOP2: DEBUG (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_STOP2_HSM_Pos      (17UL)                    /*!< TT_SCU CLK_STOP2: HSM (Bit 17)                    */
#define TT_SCU_CLK_STOP2_HSM_Msk      (0x20000UL)               /*!< TT_SCU CLK_STOP2: HSM (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP2_STCU_Pos      (18UL)                    /*!< TT_SCU CLK_STOP2: STCU (Bit 18)                    */
#define TT_SCU_CLK_STOP2_STCU_Msk      (0x40000UL)               /*!< TT_SCU CLK_STOP2: STCU (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP2_MBX_Pos      (19UL)                    /*!< TT_SCU CLK_STOP2: MBX (Bit 19)                    */
#define TT_SCU_CLK_STOP2_MBX_Msk      (0x80000UL)               /*!< TT_SCU CLK_STOP2: MBX (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP2_ADC_Pos      (20UL)                    /*!< TT_SCU CLK_STOP2: ADC (Bit 20)                    */
#define TT_SCU_CLK_STOP2_ADC_Msk      (0x100000UL)              /*!< TT_SCU CLK_STOP2: ADC (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP2_PMU_APB_Pos  (21UL)                    /*!< TT_SCU CLK_STOP2: PMU_APB (Bit 21)                */
#define TT_SCU_CLK_STOP2_PMU_APB_Msk  (0x200000UL)              /*!< TT_SCU CLK_STOP2: PMU_APB (Bitfield-Mask: 0x01)   */
#define TT_SCU_CLK_STOP2_GTM_Pos      (22UL)                    /*!< TT_SCU CLK_STOP2: GTM (Bit 22)                    */
#define TT_SCU_CLK_STOP2_GTM_Msk      (0x400000UL)              /*!< TT_SCU CLK_STOP2: GTM (Bitfield-Mask: 0x01)       */
#define TT_SCU_CLK_STOP2_EIM_Pos      (23UL)                    /*!< TT_SCU CLK_STOP2: EIM (Bit 23)                    */
#define TT_SCU_CLK_STOP2_EIM_Msk      (0x800000UL)              /*!< TT_SCU CLK_STOP2: EIM (Bitfield-Mask: 0x01)       */
/* ======================================================  CLK_SLEEP0  ======================================================= */
#define TT_SCU_CLK_SLEEP0_FTM0_Pos    (0UL)                     /*!< TT_SCU CLK_SLEEP0: FTM0 (Bit 0)                   */
#define TT_SCU_CLK_SLEEP0_FTM0_Msk    (0x1UL)                   /*!< TT_SCU CLK_SLEEP0: FTM0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP0_FTM1_Pos    (1UL)                     /*!< TT_SCU CLK_SLEEP0: FTM1 (Bit 1)                   */
#define TT_SCU_CLK_SLEEP0_FTM1_Msk    (0x2UL)                   /*!< TT_SCU CLK_SLEEP0: FTM1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP0_FTM2_Pos    (2UL)                     /*!< TT_SCU CLK_SLEEP0: FTM2 (Bit 2)                   */
#define TT_SCU_CLK_SLEEP0_FTM2_Msk    (0x4UL)                   /*!< TT_SCU CLK_SLEEP0: FTM2 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP0_FTM3_Pos    (3UL)                     /*!< TT_SCU CLK_SLEEP0: FTM3 (Bit 3)                   */
#define TT_SCU_CLK_SLEEP0_FTM3_Msk    (0x8UL)                   /*!< TT_SCU CLK_SLEEP0: FTM3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP0_FTM4_Pos    (4UL)                     /*!< TT_SCU CLK_SLEEP0: FTM4 (Bit 4)                   */
#define TT_SCU_CLK_SLEEP0_FTM4_Msk    (0x10UL)                  /*!< TT_SCU CLK_SLEEP0: FTM4 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP0_FTM5_Pos    (5UL)                     /*!< TT_SCU CLK_SLEEP0: FTM5 (Bit 5)                   */
#define TT_SCU_CLK_SLEEP0_FTM5_Msk    (0x20UL)                  /*!< TT_SCU CLK_SLEEP0: FTM5 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP0_I3C0_Pos    (6UL)                     /*!< TT_SCU CLK_SLEEP0: I3C0 (Bit 6)                   */
#define TT_SCU_CLK_SLEEP0_I3C0_Msk    (0x40UL)                  /*!< TT_SCU CLK_SLEEP0: I3C0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP0_CRC_Pos     (8UL)                     /*!< TT_SCU CLK_SLEEP0: CRC (Bit 8)                    */
#define TT_SCU_CLK_SLEEP0_CRC_Msk     (0x100UL)                 /*!< TT_SCU CLK_SLEEP0: CRC (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP0_DMAC0_Pos   (9UL)                     /*!< TT_SCU CLK_SLEEP0: DMAC0 (Bit 9)                  */
#define TT_SCU_CLK_SLEEP0_DMAC0_Msk   (0x200UL)                 /*!< TT_SCU CLK_SLEEP0: DMAC0 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_DMAC1_Pos   (10UL)                    /*!< TT_SCU CLK_SLEEP0: DMAC1 (Bit 10)                 */
#define TT_SCU_CLK_SLEEP0_DMAC1_Msk   (0x400UL)                 /*!< TT_SCU CLK_SLEEP0: DMAC1 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_DMAC2_Pos   (11UL)                    /*!< TT_SCU CLK_SLEEP0: DMAC2 (Bit 11)                 */
#define TT_SCU_CLK_SLEEP0_DMAC2_Msk   (0x800UL)                 /*!< TT_SCU CLK_SLEEP0: DMAC2 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_DMAC3_Pos   (12UL)                    /*!< TT_SCU CLK_SLEEP0: DMAC3 (Bit 12)                 */
#define TT_SCU_CLK_SLEEP0_DMAC3_Msk   (0x1000UL)                /*!< TT_SCU CLK_SLEEP0: DMAC3 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_ETHERNET_Pos (13UL)                   /*!< TT_SCU CLK_SLEEP0: ETHERNET (Bit 13)              */
#define TT_SCU_CLK_SLEEP0_ETHERNET_Msk (0x2000UL)               /*!< TT_SCU CLK_SLEEP0: ETHERNET (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_SLEEP0_GPIOA_Pos   (14UL)                    /*!< TT_SCU CLK_SLEEP0: GPIOA (Bit 14)                 */
#define TT_SCU_CLK_SLEEP0_GPIOA_Msk   (0x4000UL)                /*!< TT_SCU CLK_SLEEP0: GPIOA (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_GPIOB_Pos   (15UL)                    /*!< TT_SCU CLK_SLEEP0: GPIOB (Bit 15)                 */
#define TT_SCU_CLK_SLEEP0_GPIOB_Msk   (0x8000UL)                /*!< TT_SCU CLK_SLEEP0: GPIOB (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_GPIOC_Pos   (16UL)                    /*!< TT_SCU CLK_SLEEP0: GPIOC (Bit 16)                 */
#define TT_SCU_CLK_SLEEP0_GPIOC_Msk   (0x10000UL)               /*!< TT_SCU CLK_SLEEP0: GPIOC (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_GPIOD_Pos   (17UL)                    /*!< TT_SCU CLK_SLEEP0: GPIOD (Bit 17)                 */
#define TT_SCU_CLK_SLEEP0_GPIOD_Msk   (0x20000UL)               /*!< TT_SCU CLK_SLEEP0: GPIOD (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_GPIOE_Pos   (18UL)                    /*!< TT_SCU CLK_SLEEP0: GPIOE (Bit 18)                 */
#define TT_SCU_CLK_SLEEP0_GPIOE_Msk   (0x40000UL)               /*!< TT_SCU CLK_SLEEP0: GPIOE (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_I2S0_Pos    (19UL)                    /*!< TT_SCU CLK_SLEEP0: I2S0 (Bit 19)                  */
#define TT_SCU_CLK_SLEEP0_I2S0_Msk    (0x80000UL)               /*!< TT_SCU CLK_SLEEP0: I2S0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP0_SENT6_Pos   (20UL)                    /*!< TT_SCU CLK_SLEEP0: SENT6 (Bit 20)                 */
#define TT_SCU_CLK_SLEEP0_SENT6_Msk   (0x100000UL)              /*!< TT_SCU CLK_SLEEP0: SENT6 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_IOM_Pos     (21UL)                    /*!< TT_SCU CLK_SLEEP0: IOM (Bit 21)                   */
#define TT_SCU_CLK_SLEEP0_IOM_Msk     (0x200000UL)              /*!< TT_SCU CLK_SLEEP0: IOM (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP0_SENT0_Pos   (22UL)                    /*!< TT_SCU CLK_SLEEP0: SENT0 (Bit 22)                 */
#define TT_SCU_CLK_SLEEP0_SENT0_Msk   (0x400000UL)              /*!< TT_SCU CLK_SLEEP0: SENT0 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_SENT1_Pos   (23UL)                    /*!< TT_SCU CLK_SLEEP0: SENT1 (Bit 23)                 */
#define TT_SCU_CLK_SLEEP0_SENT1_Msk   (0x800000UL)              /*!< TT_SCU CLK_SLEEP0: SENT1 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_SENT2_Pos   (24UL)                    /*!< TT_SCU CLK_SLEEP0: SENT2 (Bit 24)                 */
#define TT_SCU_CLK_SLEEP0_SENT2_Msk   (0x1000000UL)             /*!< TT_SCU CLK_SLEEP0: SENT2 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_SENT3_Pos   (25UL)                    /*!< TT_SCU CLK_SLEEP0: SENT3 (Bit 25)                 */
#define TT_SCU_CLK_SLEEP0_SENT3_Msk   (0x2000000UL)             /*!< TT_SCU CLK_SLEEP0: SENT3 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_SENT4_Pos   (26UL)                    /*!< TT_SCU CLK_SLEEP0: SENT4 (Bit 26)                 */
#define TT_SCU_CLK_SLEEP0_SENT4_Msk   (0x4000000UL)             /*!< TT_SCU CLK_SLEEP0: SENT4 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_SENT5_Pos   (27UL)                    /*!< TT_SCU CLK_SLEEP0: SENT5 (Bit 27)                 */
#define TT_SCU_CLK_SLEEP0_SENT5_Msk   (0x8000000UL)             /*!< TT_SCU CLK_SLEEP0: SENT5 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_TIMER_Pos   (28UL)                    /*!< TT_SCU CLK_SLEEP0: TIMER (Bit 28)                 */
#define TT_SCU_CLK_SLEEP0_TIMER_Msk   (0x10000000UL)            /*!< TT_SCU CLK_SLEEP0: TIMER (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_UART0_Pos   (29UL)                    /*!< TT_SCU CLK_SLEEP0: UART0 (Bit 29)                 */
#define TT_SCU_CLK_SLEEP0_UART0_Msk   (0x20000000UL)            /*!< TT_SCU CLK_SLEEP0: UART0 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_UART1_Pos   (30UL)                    /*!< TT_SCU CLK_SLEEP0: UART1 (Bit 30)                 */
#define TT_SCU_CLK_SLEEP0_UART1_Msk   (0x40000000UL)            /*!< TT_SCU CLK_SLEEP0: UART1 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP0_UART2_Pos   (31UL)                    /*!< TT_SCU CLK_SLEEP0: UART2 (Bit 31)                 */
#define TT_SCU_CLK_SLEEP0_UART2_Msk   (0x80000000UL)            /*!< TT_SCU CLK_SLEEP0: UART2 (Bitfield-Mask: 0x01)    */
/* ======================================================  CLK_SLEEP1  ======================================================= */
#define TT_SCU_CLK_SLEEP1_UART3_Pos   (0UL)                     /*!< TT_SCU CLK_SLEEP1: UART3 (Bit 0)                  */
#define TT_SCU_CLK_SLEEP1_UART3_Msk   (0x1UL)                   /*!< TT_SCU CLK_SLEEP1: UART3 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP1_WDT_Pos     (1UL)                     /*!< TT_SCU CLK_SLEEP1: WDT (Bit 1)                    */
#define TT_SCU_CLK_SLEEP1_WDT_Msk     (0x2UL)                   /*!< TT_SCU CLK_SLEEP1: WDT (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP1_QSPI0_Pos   (2UL)                     /*!< TT_SCU CLK_SLEEP1: QSPI0 (Bit 2)                  */
#define TT_SCU_CLK_SLEEP1_QSPI0_Msk   (0x4UL)                   /*!< TT_SCU CLK_SLEEP1: QSPI0 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP1_SSP7_Pos    (3UL)                     /*!< TT_SCU CLK_SLEEP1: SSP7 (Bit 3)                   */
#define TT_SCU_CLK_SLEEP1_SSP7_Msk    (0x8UL)                   /*!< TT_SCU CLK_SLEEP1: SSP7 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_SSP0_Pos    (4UL)                     /*!< TT_SCU CLK_SLEEP1: SSP0 (Bit 4)                   */
#define TT_SCU_CLK_SLEEP1_SSP0_Msk    (0x10UL)                  /*!< TT_SCU CLK_SLEEP1: SSP0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_SSP1_Pos    (5UL)                     /*!< TT_SCU CLK_SLEEP1: SSP1 (Bit 5)                   */
#define TT_SCU_CLK_SLEEP1_SSP1_Msk    (0x20UL)                  /*!< TT_SCU CLK_SLEEP1: SSP1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_SSP2_Pos    (6UL)                     /*!< TT_SCU CLK_SLEEP1: SSP2 (Bit 6)                   */
#define TT_SCU_CLK_SLEEP1_SSP2_Msk    (0x40UL)                  /*!< TT_SCU CLK_SLEEP1: SSP2 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_SSP3_Pos    (7UL)                     /*!< TT_SCU CLK_SLEEP1: SSP3 (Bit 7)                   */
#define TT_SCU_CLK_SLEEP1_SSP3_Msk    (0x80UL)                  /*!< TT_SCU CLK_SLEEP1: SSP3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_SSP4_Pos    (8UL)                     /*!< TT_SCU CLK_SLEEP1: SSP4 (Bit 8)                   */
#define TT_SCU_CLK_SLEEP1_SSP4_Msk    (0x100UL)                 /*!< TT_SCU CLK_SLEEP1: SSP4 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_SSP5_Pos    (9UL)                     /*!< TT_SCU CLK_SLEEP1: SSP5 (Bit 9)                   */
#define TT_SCU_CLK_SLEEP1_SSP5_Msk    (0x200UL)                 /*!< TT_SCU CLK_SLEEP1: SSP5 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_I2C0_Pos    (10UL)                    /*!< TT_SCU CLK_SLEEP1: I2C0 (Bit 10)                  */
#define TT_SCU_CLK_SLEEP1_I2C0_Msk    (0x400UL)                 /*!< TT_SCU CLK_SLEEP1: I2C0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_I2C1_Pos    (11UL)                    /*!< TT_SCU CLK_SLEEP1: I2C1 (Bit 11)                  */
#define TT_SCU_CLK_SLEEP1_I2C1_Msk    (0x800UL)                 /*!< TT_SCU CLK_SLEEP1: I2C1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN0_Pos    (12UL)                    /*!< TT_SCU CLK_SLEEP1: LIN0 (Bit 12)                  */
#define TT_SCU_CLK_SLEEP1_LIN0_Msk    (0x1000UL)                /*!< TT_SCU CLK_SLEEP1: LIN0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN1_Pos    (13UL)                    /*!< TT_SCU CLK_SLEEP1: LIN1 (Bit 13)                  */
#define TT_SCU_CLK_SLEEP1_LIN1_Msk    (0x2000UL)                /*!< TT_SCU CLK_SLEEP1: LIN1 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN2_Pos    (14UL)                    /*!< TT_SCU CLK_SLEEP1: LIN2 (Bit 14)                  */
#define TT_SCU_CLK_SLEEP1_LIN2_Msk    (0x4000UL)                /*!< TT_SCU CLK_SLEEP1: LIN2 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN3_Pos    (15UL)                    /*!< TT_SCU CLK_SLEEP1: LIN3 (Bit 15)                  */
#define TT_SCU_CLK_SLEEP1_LIN3_Msk    (0x8000UL)                /*!< TT_SCU CLK_SLEEP1: LIN3 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN4_Pos    (16UL)                    /*!< TT_SCU CLK_SLEEP1: LIN4 (Bit 16)                  */
#define TT_SCU_CLK_SLEEP1_LIN4_Msk    (0x10000UL)               /*!< TT_SCU CLK_SLEEP1: LIN4 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN5_Pos    (17UL)                    /*!< TT_SCU CLK_SLEEP1: LIN5 (Bit 17)                  */
#define TT_SCU_CLK_SLEEP1_LIN5_Msk    (0x20000UL)               /*!< TT_SCU CLK_SLEEP1: LIN5 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN6_Pos    (18UL)                    /*!< TT_SCU CLK_SLEEP1: LIN6 (Bit 18)                  */
#define TT_SCU_CLK_SLEEP1_LIN6_Msk    (0x40000UL)               /*!< TT_SCU CLK_SLEEP1: LIN6 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN7_Pos    (19UL)                    /*!< TT_SCU CLK_SLEEP1: LIN7 (Bit 19)                  */
#define TT_SCU_CLK_SLEEP1_LIN7_Msk    (0x80000UL)               /*!< TT_SCU CLK_SLEEP1: LIN7 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN8_Pos    (20UL)                    /*!< TT_SCU CLK_SLEEP1: LIN8 (Bit 20)                  */
#define TT_SCU_CLK_SLEEP1_LIN8_Msk    (0x100000UL)              /*!< TT_SCU CLK_SLEEP1: LIN8 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN9_Pos    (21UL)                    /*!< TT_SCU CLK_SLEEP1: LIN9 (Bit 21)                  */
#define TT_SCU_CLK_SLEEP1_LIN9_Msk    (0x200000UL)              /*!< TT_SCU CLK_SLEEP1: LIN9 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP1_LIN10_Pos   (22UL)                    /*!< TT_SCU CLK_SLEEP1: LIN10 (Bit 22)                 */
#define TT_SCU_CLK_SLEEP1_LIN10_Msk   (0x400000UL)              /*!< TT_SCU CLK_SLEEP1: LIN10 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP1_LIN11_Pos   (23UL)                    /*!< TT_SCU CLK_SLEEP1: LIN11 (Bit 23)                 */
#define TT_SCU_CLK_SLEEP1_LIN11_Msk   (0x800000UL)              /*!< TT_SCU CLK_SLEEP1: LIN11 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP1_LIN12_Pos   (24UL)                    /*!< TT_SCU CLK_SLEEP1: LIN12 (Bit 24)                 */
#define TT_SCU_CLK_SLEEP1_LIN12_Msk   (0x1000000UL)             /*!< TT_SCU CLK_SLEEP1: LIN12 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP1_LIN13_Pos   (25UL)                    /*!< TT_SCU CLK_SLEEP1: LIN13 (Bit 25)                 */
#define TT_SCU_CLK_SLEEP1_LIN13_Msk   (0x2000000UL)             /*!< TT_SCU CLK_SLEEP1: LIN13 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP1_LIN14_Pos   (26UL)                    /*!< TT_SCU CLK_SLEEP1: LIN14 (Bit 26)                 */
#define TT_SCU_CLK_SLEEP1_LIN14_Msk   (0x4000000UL)             /*!< TT_SCU CLK_SLEEP1: LIN14 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP1_LIN15_Pos   (27UL)                    /*!< TT_SCU CLK_SLEEP1: LIN15 (Bit 27)                 */
#define TT_SCU_CLK_SLEEP1_LIN15_Msk   (0x8000000UL)             /*!< TT_SCU CLK_SLEEP1: LIN15 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP1_SSP6_Pos    (28UL)                    /*!< TT_SCU CLK_SLEEP1: SSP6 (Bit 28)                  */
#define TT_SCU_CLK_SLEEP1_SSP6_Msk    (0x10000000UL)            /*!< TT_SCU CLK_SLEEP1: SSP6 (Bitfield-Mask: 0x01)     */
/* ======================================================  CLK_SLEEP2  ======================================================= */
#define TT_SCU_CLK_SLEEP2_SENT7_Pos   (5UL)                     /*!< TT_SCU CLK_SLEEP2: SENT7 (Bit 5)                  */
#define TT_SCU_CLK_SLEEP2_SENT7_Msk   (0x20UL)                  /*!< TT_SCU CLK_SLEEP2: SENT7 (Bitfield-Mask: 0x01)    */
#define TT_SCU_CLK_SLEEP2_TRIG_MUX_Pos (6UL)                    /*!< TT_SCU CLK_SLEEP2: TRIG_MUX (Bit 6)               */
#define TT_SCU_CLK_SLEEP2_TRIG_MUX_Msk (0x40UL)                 /*!< TT_SCU CLK_SLEEP2: TRIG_MUX (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_SLEEP2_ADCSENSOR_Pos (7UL)                   /*!< TT_SCU CLK_SLEEP2: ADCSENSOR (Bit 7)              */
#define TT_SCU_CLK_SLEEP2_ADCSENSOR_Msk (0x80UL)                /*!< TT_SCU CLK_SLEEP2: ADCSENSOR (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_SLEEP2_INTM_Pos    (8UL)                     /*!< TT_SCU CLK_SLEEP2: INTM (Bit 8)                   */
#define TT_SCU_CLK_SLEEP2_INTM_Msk    (0x100UL)                 /*!< TT_SCU CLK_SLEEP2: INTM (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP2_SHIELD_CIP_Pos (9UL)                  /*!< TT_SCU CLK_SLEEP2: SHIELD_CIP (Bit 9)             */
#define TT_SCU_CLK_SLEEP2_SHIELD_CIP_Msk (0x200UL)              /*!< TT_SCU CLK_SLEEP2: SHIELD_CIP (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_SLEEP2_PKI_Pos     (10UL)                    /*!< TT_SCU CLK_SLEEP2: PKI (Bit 10)                   */
#define TT_SCU_CLK_SLEEP2_PKI_Msk     (0x400UL)                 /*!< TT_SCU CLK_SLEEP2: PKI (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_HASH_Pos    (11UL)                    /*!< TT_SCU CLK_SLEEP2: HASH (Bit 11)                  */
#define TT_SCU_CLK_SLEEP2_HASH_Msk    (0x800UL)                 /*!< TT_SCU CLK_SLEEP2: HASH (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP2_SKA_Pos     (12UL)                    /*!< TT_SCU CLK_SLEEP2: SKA (Bit 12)                   */
#define TT_SCU_CLK_SLEEP2_SKA_Msk     (0x1000UL)                /*!< TT_SCU CLK_SLEEP2: SKA (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_SM4_Pos     (13UL)                    /*!< TT_SCU CLK_SLEEP2: SM4 (Bit 13)                   */
#define TT_SCU_CLK_SLEEP2_SM4_Msk     (0x2000UL)                /*!< TT_SCU CLK_SLEEP2: SM4 (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_LASER_CIP_Pos (14UL)                  /*!< TT_SCU CLK_SLEEP2: LASER_CIP (Bit 14)             */
#define TT_SCU_CLK_SLEEP2_LASER_CIP_Msk (0x4000UL)              /*!< TT_SCU CLK_SLEEP2: LASER_CIP (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_SLEEP2_TRNG_Pos    (15UL)                    /*!< TT_SCU CLK_SLEEP2: TRNG (Bit 15)                  */
#define TT_SCU_CLK_SLEEP2_TRNG_Msk    (0x8000UL)                /*!< TT_SCU CLK_SLEEP2: TRNG (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP2_STCU_Pos     (18UL)                    /*!< TT_SCU CLK_SLEEP2: STCU (Bit 18)                   */
#define TT_SCU_CLK_SLEEP2_STCU_Msk     (0x40000UL)               /*!< TT_SCU CLK_SLEEP2: STCU (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_MBX_Pos     (19UL)                    /*!< TT_SCU CLK_SLEEP2: MBX (Bit 19)                   */
#define TT_SCU_CLK_SLEEP2_MBX_Msk     (0x80000UL)               /*!< TT_SCU CLK_SLEEP2: MBX (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_ADC_Pos     (20UL)                    /*!< TT_SCU CLK_SLEEP2: ADC (Bit 20)                   */
#define TT_SCU_CLK_SLEEP2_ADC_Msk     (0x100000UL)              /*!< TT_SCU CLK_SLEEP2: ADC (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_PMU_APB_Pos (21UL)                    /*!< TT_SCU CLK_SLEEP2: PMU_APB (Bit 21)               */
#define TT_SCU_CLK_SLEEP2_PMU_APB_Msk (0x200000UL)              /*!< TT_SCU CLK_SLEEP2: PMU_APB (Bitfield-Mask: 0x01)  */
#define TT_SCU_CLK_SLEEP2_EIM_Pos     (23UL)                    /*!< TT_SCU CLK_SLEEP2: EIM (Bit 23)                   */
#define TT_SCU_CLK_SLEEP2_EIM_Msk     (0x800000UL)              /*!< TT_SCU CLK_SLEEP2: EIM (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_SCU_Pos     (26UL)                    /*!< TT_SCU CLK_SLEEP2: SCU (Bit 26)                   */
#define TT_SCU_CLK_SLEEP2_SCU_Msk     (0x4000000UL)             /*!< TT_SCU CLK_SLEEP2: SCU (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_SMU_Pos     (27UL)                    /*!< TT_SCU CLK_SLEEP2: SMU (Bit 27)                   */
#define TT_SCU_CLK_SLEEP2_SMU_Msk     (0x8000000UL)             /*!< TT_SCU CLK_SLEEP2: SMU (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_TCM_Pos     (28UL)                    /*!< TT_SCU CLK_SLEEP2: TCM (Bit 28)                   */
#define TT_SCU_CLK_SLEEP2_TCM_Msk     (0x10000000UL)            /*!< TT_SCU CLK_SLEEP2: TCM (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_FCU_Pos     (29UL)                    /*!< TT_SCU CLK_SLEEP2: FCU (Bit 29)                   */
#define TT_SCU_CLK_SLEEP2_FCU_Msk     (0x20000000UL)            /*!< TT_SCU CLK_SLEEP2: FCU (Bitfield-Mask: 0x01)      */
#define TT_SCU_CLK_SLEEP2_OCN0_Pos    (30UL)                    /*!< TT_SCU CLK_SLEEP2: OCN0 (Bit 30)                  */
#define TT_SCU_CLK_SLEEP2_OCN0_Msk    (0x40000000UL)            /*!< TT_SCU CLK_SLEEP2: OCN0 (Bitfield-Mask: 0x01)     */
#define TT_SCU_CLK_SLEEP2_OCN1_Pos    (31UL)                    /*!< TT_SCU CLK_SLEEP2: OCN1 (Bit 31)                  */
#define TT_SCU_CLK_SLEEP2_OCN1_Msk    (0x80000000UL)            /*!< TT_SCU CLK_SLEEP2: OCN1 (Bitfield-Mask: 0x01)     */
/* ========================================================  LP_CTL  ========================================================= */
#define TT_SCU_LP_CTL_FLASH_PD_Pos    (0UL)                     /*!< TT_SCU LP_CTL: FLASH_PD (Bit 0)                   */
#define TT_SCU_LP_CTL_FLASH_PD_Msk    (0x1UL)                   /*!< TT_SCU LP_CTL: FLASH_PD (Bitfield-Mask: 0x01)     */
#define TT_SCU_LP_CTL_OSC_DISABLE_Pos (1UL)                     /*!< TT_SCU LP_CTL: OSC_DISABLE (Bit 1)                */
#define TT_SCU_LP_CTL_OSC_DISABLE_Msk (0x2UL)                   /*!< TT_SCU LP_CTL: OSC_DISABLE (Bitfield-Mask: 0x01)  */
#define TT_SCU_LP_CTL_ECO_DISABLE_Pos (2UL)                     /*!< TT_SCU LP_CTL: ECO_DISABLE (Bit 2)                */
#define TT_SCU_LP_CTL_ECO_DISABLE_Msk (0x4UL)                   /*!< TT_SCU LP_CTL: ECO_DISABLE (Bitfield-Mask: 0x01)  */
#define TT_SCU_LP_CTL_SRAM_RETENTION_Pos (8UL)                  /*!< TT_SCU LP_CTL: SRAM_RETENTION (Bit 8)             */
#define TT_SCU_LP_CTL_SRAM_RETENTION_Msk (0x100UL)              /*!< TT_SCU LP_CTL: SRAM_RETENTION (Bitfield-Mask: 0x01) */
#define TT_SCU_LP_CTL_HSM_PD_Pos      (16UL)                    /*!< TT_SCU LP_CTL: HSM_PD (Bit 16)                    */
#define TT_SCU_LP_CTL_HSM_PD_Msk      (0x10000UL)               /*!< TT_SCU LP_CTL: HSM_PD (Bitfield-Mask: 0x01)       */
#define TT_SCU_LP_CTL_CIP_PD_Pos      (17UL)                    /*!< TT_SCU LP_CTL: CIP_PD (Bit 17)                    */
#define TT_SCU_LP_CTL_CIP_PD_Msk      (0x20000UL)               /*!< TT_SCU LP_CTL: CIP_PD (Bitfield-Mask: 0x01)       */
/* =====================================================  PLL_LOCK_TIME  ===================================================== */
#define TT_SCU_PLL_LOCK_TIME_MPLL_LOCK_TIME_Pos (0UL)           /*!< TT_SCU PLL_LOCK_TIME: MPLL_LOCK_TIME (Bit 0)      */
#define TT_SCU_PLL_LOCK_TIME_MPLL_LOCK_TIME_Msk (0xffffUL)      /*!< TT_SCU PLL_LOCK_TIME: MPLL_LOCK_TIME (Bitfield-Mask: 0xffff) */
#define TT_SCU_PLL_LOCK_TIME_EPLL_LOCK_TIME_Pos (16UL)          /*!< TT_SCU PLL_LOCK_TIME: EPLL_LOCK_TIME (Bit 16)     */
#define TT_SCU_PLL_LOCK_TIME_EPLL_LOCK_TIME_Msk (0xffff0000UL)  /*!< TT_SCU PLL_LOCK_TIME: EPLL_LOCK_TIME (Bitfield-Mask: 0xffff) */
/* =======================================================  CLK_RAND  ======================================================== */
#define TT_SCU_CLK_RAND_HASH_RAND_EN_Pos (1UL)                  /*!< TT_SCU CLK_RAND: HASH_RAND_EN (Bit 1)             */
#define TT_SCU_CLK_RAND_HASH_RAND_EN_Msk (0x2UL)                /*!< TT_SCU CLK_RAND: HASH_RAND_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_RAND_SKA_RAND_EN_Pos (2UL)                   /*!< TT_SCU CLK_RAND: SKA_RAND_EN (Bit 2)              */
#define TT_SCU_CLK_RAND_SKA_RAND_EN_Msk (0x4UL)                 /*!< TT_SCU CLK_RAND: SKA_RAND_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_RAND_SM4_RAND_EN_Pos (3UL)                   /*!< TT_SCU CLK_RAND: SM4_RAND_EN (Bit 3)              */
#define TT_SCU_CLK_RAND_SM4_RAND_EN_Msk (0x8UL)                 /*!< TT_SCU CLK_RAND: SM4_RAND_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_CLK_RAND_HASH_RAND_SEL_Pos (8UL)                 /*!< TT_SCU CLK_RAND: HASH_RAND_SEL (Bit 8)            */
#define TT_SCU_CLK_RAND_HASH_RAND_SEL_Msk (0xf00UL)             /*!< TT_SCU CLK_RAND: HASH_RAND_SEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_CLK_RAND_SKA_RAND_SEL_Pos (12UL)                 /*!< TT_SCU CLK_RAND: SKA_RAND_SEL (Bit 12)            */
#define TT_SCU_CLK_RAND_SKA_RAND_SEL_Msk (0xf000UL)             /*!< TT_SCU CLK_RAND: SKA_RAND_SEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_CLK_RAND_SM4_RAND_SEL_Pos (16UL)                 /*!< TT_SCU CLK_RAND: SM4_RAND_SEL (Bit 16)            */
#define TT_SCU_CLK_RAND_SM4_RAND_SEL_Msk (0xf0000UL)            /*!< TT_SCU CLK_RAND: SM4_RAND_SEL (Bitfield-Mask: 0x0f) */
/* =======================================================  LFSR_SEED  ======================================================= */
#define TT_SCU_LFSR_SEED_FIELD_Pos    (0UL)                     /*!< TT_SCU LFSR_SEED: FIELD (Bit 0)                   */
#define TT_SCU_LFSR_SEED_FIELD_Msk    (0xffffffffUL)            /*!< TT_SCU LFSR_SEED: FIELD (Bitfield-Mask: 0xffffffff) */
/* =======================================================  PERI_STOP  ======================================================= */
#define TT_SCU_PERI_STOP_STOP_LIN0_Pos (0UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN0 (Bit 0)               */
#define TT_SCU_PERI_STOP_STOP_LIN0_Msk (0x1UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN0 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN1_Pos (1UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN1 (Bit 1)               */
#define TT_SCU_PERI_STOP_STOP_LIN1_Msk (0x2UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN1 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN2_Pos (2UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN2 (Bit 2)               */
#define TT_SCU_PERI_STOP_STOP_LIN2_Msk (0x4UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN2 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN3_Pos (3UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN3 (Bit 3)               */
#define TT_SCU_PERI_STOP_STOP_LIN3_Msk (0x8UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN3 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN4_Pos (4UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN4 (Bit 4)               */
#define TT_SCU_PERI_STOP_STOP_LIN4_Msk (0x10UL)                 /*!< TT_SCU PERI_STOP: STOP_LIN4 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN5_Pos (5UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN5 (Bit 5)               */
#define TT_SCU_PERI_STOP_STOP_LIN5_Msk (0x20UL)                 /*!< TT_SCU PERI_STOP: STOP_LIN5 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN6_Pos (6UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN6 (Bit 6)               */
#define TT_SCU_PERI_STOP_STOP_LIN6_Msk (0x40UL)                 /*!< TT_SCU PERI_STOP: STOP_LIN6 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN7_Pos (7UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN7 (Bit 7)               */
#define TT_SCU_PERI_STOP_STOP_LIN7_Msk (0x80UL)                 /*!< TT_SCU PERI_STOP: STOP_LIN7 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN8_Pos (8UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN8 (Bit 8)               */
#define TT_SCU_PERI_STOP_STOP_LIN8_Msk (0x100UL)                /*!< TT_SCU PERI_STOP: STOP_LIN8 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN9_Pos (9UL)                    /*!< TT_SCU PERI_STOP: STOP_LIN9 (Bit 9)               */
#define TT_SCU_PERI_STOP_STOP_LIN9_Msk (0x200UL)                /*!< TT_SCU PERI_STOP: STOP_LIN9 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN10_Pos (10UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN10 (Bit 10)             */
#define TT_SCU_PERI_STOP_STOP_LIN10_Msk (0x400UL)               /*!< TT_SCU PERI_STOP: STOP_LIN10 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN11_Pos (11UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN11 (Bit 11)             */
#define TT_SCU_PERI_STOP_STOP_LIN11_Msk (0x800UL)               /*!< TT_SCU PERI_STOP: STOP_LIN11 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN12_Pos (12UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN12 (Bit 12)             */
#define TT_SCU_PERI_STOP_STOP_LIN12_Msk (0x1000UL)              /*!< TT_SCU PERI_STOP: STOP_LIN12 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN13_Pos (13UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN13 (Bit 13)             */
#define TT_SCU_PERI_STOP_STOP_LIN13_Msk (0x2000UL)              /*!< TT_SCU PERI_STOP: STOP_LIN13 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN14_Pos (14UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN14 (Bit 14)             */
#define TT_SCU_PERI_STOP_STOP_LIN14_Msk (0x4000UL)              /*!< TT_SCU PERI_STOP: STOP_LIN14 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_LIN15_Pos (15UL)                  /*!< TT_SCU PERI_STOP: STOP_LIN15 (Bit 15)             */
#define TT_SCU_PERI_STOP_STOP_LIN15_Msk (0x8000UL)              /*!< TT_SCU PERI_STOP: STOP_LIN15 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_CAN0_Pos (16UL)                   /*!< TT_SCU PERI_STOP: STOP_CAN0 (Bit 16)              */
#define TT_SCU_PERI_STOP_STOP_CAN0_Msk (0x10000UL)              /*!< TT_SCU PERI_STOP: STOP_CAN0 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_CAN1_Pos (17UL)                   /*!< TT_SCU PERI_STOP: STOP_CAN1 (Bit 17)              */
#define TT_SCU_PERI_STOP_STOP_CAN1_Msk (0x20000UL)              /*!< TT_SCU PERI_STOP: STOP_CAN1 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_CAN2_Pos (18UL)                   /*!< TT_SCU PERI_STOP: STOP_CAN2 (Bit 18)              */
#define TT_SCU_PERI_STOP_STOP_CAN2_Msk (0x40000UL)              /*!< TT_SCU PERI_STOP: STOP_CAN2 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_CAN3_Pos (19UL)                   /*!< TT_SCU PERI_STOP: STOP_CAN3 (Bit 19)              */
#define TT_SCU_PERI_STOP_STOP_CAN3_Msk (0x80000UL)              /*!< TT_SCU PERI_STOP: STOP_CAN3 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_CAN4_Pos (20UL)                   /*!< TT_SCU PERI_STOP: STOP_CAN4 (Bit 20)              */
#define TT_SCU_PERI_STOP_STOP_CAN4_Msk (0x100000UL)             /*!< TT_SCU PERI_STOP: STOP_CAN4 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_CAN5_Pos (21UL)                   /*!< TT_SCU PERI_STOP: STOP_CAN5 (Bit 21)              */
#define TT_SCU_PERI_STOP_STOP_CAN5_Msk (0x200000UL)             /*!< TT_SCU PERI_STOP: STOP_CAN5 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_CAN6_Pos (22UL)                   /*!< TT_SCU PERI_STOP: STOP_CAN6 (Bit 22)              */
#define TT_SCU_PERI_STOP_STOP_CAN6_Msk (0x400000UL)             /*!< TT_SCU PERI_STOP: STOP_CAN6 (Bitfield-Mask: 0x01) */
#define TT_SCU_PERI_STOP_STOP_CAN7_Pos (23UL)                   /*!< TT_SCU PERI_STOP: STOP_CAN7 (Bit 23)              */
#define TT_SCU_PERI_STOP_STOP_CAN7_Msk (0x800000UL)             /*!< TT_SCU PERI_STOP: STOP_CAN7 (Bitfield-Mask: 0x01) */
/* ======================================================  CGU_CLK_SEL  ====================================================== */
#define TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Pos (0UL)               /*!< TT_SCU CGU_CLK_SEL: SEL_CLK_MAIN (Bit 0)          */
#define TT_SCU_CGU_CLK_SEL_SEL_CLK_MAIN_Msk (0x1UL)             /*!< TT_SCU CGU_CLK_SEL: SEL_CLK_MAIN (Bitfield-Mask: 0x01) */
#define TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Pos (4UL)                /*!< TT_SCU CGU_CLK_SEL: SEL_CLK_CAN (Bit 4)           */
#define TT_SCU_CGU_CLK_SEL_SEL_CLK_CAN_Msk (0x10UL)             /*!< TT_SCU CGU_CLK_SEL: SEL_CLK_CAN (Bitfield-Mask: 0x01) */
/* ======================================================  SCU_PD_CTL  ======================================================= */
#define TT_SCU_SCU_PD_CTL_WAIT_HSM_DS_Pos (0UL)                 /*!< TT_SCU SCU_PD_CTL: WAIT_HSM_DS (Bit 0)            */
#define TT_SCU_SCU_PD_CTL_WAIT_HSM_DS_Msk (0x1UL)               /*!< TT_SCU SCU_PD_CTL: WAIT_HSM_DS (Bitfield-Mask: 0x01) */
/* ====================================================  CGU_M7CLKEN_CR  ===================================================== */
#define TT_SCU_CGU_M7CLKEN_CR_CLKEN_DELAY_Pos (0UL)             /*!< TT_SCU CGU_M7CLKEN_CR: CLKEN_DELAY (Bit 0)        */
#define TT_SCU_CGU_M7CLKEN_CR_CLKEN_DELAY_Msk (0x1UL)           /*!< TT_SCU CGU_M7CLKEN_CR: CLKEN_DELAY (Bitfield-Mask: 0x01) */
#define TT_SCU_CGU_M7CLKEN_CR_FCLKEN_DELAY_Pos (1UL)            /*!< TT_SCU CGU_M7CLKEN_CR: FCLKEN_DELAY (Bit 1)       */
#define TT_SCU_CGU_M7CLKEN_CR_FCLKEN_DELAY_Msk (0x2UL)          /*!< TT_SCU CGU_M7CLKEN_CR: FCLKEN_DELAY (Bitfield-Mask: 0x01) */
#define TT_SCU_CGU_M7CLKEN_CR_HCLKEN_DELAY_Pos (2UL)            /*!< TT_SCU CGU_M7CLKEN_CR: HCLKEN_DELAY (Bit 2)       */
#define TT_SCU_CGU_M7CLKEN_CR_HCLKEN_DELAY_Msk (0x4UL)          /*!< TT_SCU CGU_M7CLKEN_CR: HCLKEN_DELAY (Bitfield-Mask: 0x01) */
/* ======================================================  BIST_STATE  ======================================================= */
#define TT_SCU_BIST_STATE_FAIL_EQ3_Pos (0UL)                    /*!< TT_SCU BIST_STATE: FAIL_EQ3 (Bit 0)               */
#define TT_SCU_BIST_STATE_FAIL_EQ3_Msk (0x1UL)                  /*!< TT_SCU BIST_STATE: FAIL_EQ3 (Bitfield-Mask: 0x01) */
/* =======================================================  PROBE_SEL  ======================================================= */
#define TT_SCU_PROBE_SEL_CLK_PROBE_SEL_Pos (0UL)                /*!< TT_SCU PROBE_SEL: CLK_PROBE_SEL (Bit 0)           */
#define TT_SCU_PROBE_SEL_CLK_PROBE_SEL_Msk (0xfUL)              /*!< TT_SCU PROBE_SEL: CLK_PROBE_SEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_PROBE_SEL_PROBE_ENABLE_Pos (31UL)                /*!< TT_SCU PROBE_SEL: PROBE_ENABLE (Bit 31)           */
#define TT_SCU_PROBE_SEL_PROBE_ENABLE_Msk (0x80000000UL)        /*!< TT_SCU PROBE_SEL: PROBE_ENABLE (Bitfield-Mask: 0x01) */
/* ======================================================  FTM_CLB_CFG  ====================================================== */
#define TT_SCU_FTM_CLB_CFG_FTM_GTB_SPLIT_EN_Pos (0UL)           /*!< TT_SCU FTM_CLB_CFG: FTM_GTB_SPLIT_EN (Bit 0)      */
#define TT_SCU_FTM_CLB_CFG_FTM_GTB_SPLIT_EN_Msk (0x1UL)         /*!< TT_SCU FTM_CLB_CFG: FTM_GTB_SPLIT_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_FTM_CLB_CFG_FTM2_HALL_CH1_EN_Pos (1UL)           /*!< TT_SCU FTM_CLB_CFG: FTM2_HALL_CH1_EN (Bit 1)      */
#define TT_SCU_FTM_CLB_CFG_FTM2_HALL_CH1_EN_Msk (0x2UL)         /*!< TT_SCU FTM_CLB_CFG: FTM2_HALL_CH1_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_FTM_CLB_CFG_FTM2_HALL_CH3_EN_Pos (2UL)           /*!< TT_SCU FTM_CLB_CFG: FTM2_HALL_CH3_EN (Bit 2)      */
#define TT_SCU_FTM_CLB_CFG_FTM2_HALL_CH3_EN_Msk (0x4UL)         /*!< TT_SCU FTM_CLB_CFG: FTM2_HALL_CH3_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_FTM_CLB_CFG_FTM_FIX_CLK_SEL_Pos (3UL)            /*!< TT_SCU FTM_CLB_CFG: FTM_FIX_CLK_SEL (Bit 3)       */
#define TT_SCU_FTM_CLB_CFG_FTM_FIX_CLK_SEL_Msk (0xf8UL)         /*!< TT_SCU FTM_CLB_CFG: FTM_FIX_CLK_SEL (Bitfield-Mask: 0x1f) */
/* =====================================================  QSPI_MISC_CFG  ===================================================== */
#define TT_SCU_QSPI_MISC_CFG_QSPI0_SLAVE_SEL_Pos (0UL)          /*!< TT_SCU QSPI_MISC_CFG: QSPI0_SLAVE_SEL (Bit 0)     */
#define TT_SCU_QSPI_MISC_CFG_QSPI0_SLAVE_SEL_Msk (0x1UL)        /*!< TT_SCU QSPI_MISC_CFG: QSPI0_SLAVE_SEL (Bitfield-Mask: 0x01) */
#define TT_SCU_QSPI_MISC_CFG_QSPI1_SLAVE_SEL_Pos (1UL)          /*!< TT_SCU QSPI_MISC_CFG: QSPI1_SLAVE_SEL (Bit 1)     */
#define TT_SCU_QSPI_MISC_CFG_QSPI1_SLAVE_SEL_Msk (0x2UL)        /*!< TT_SCU QSPI_MISC_CFG: QSPI1_SLAVE_SEL (Bitfield-Mask: 0x01) */
/* =====================================================  EMAC_MISC_CFG  ===================================================== */
#define TT_SCU_EMAC_MISC_CFG_PHY_INTERFACE_Pos (0UL)            /*!< TT_SCU EMAC_MISC_CFG: PHY_INTERFACE (Bit 0)       */
#define TT_SCU_EMAC_MISC_CFG_PHY_INTERFACE_Msk (0x7UL)          /*!< TT_SCU EMAC_MISC_CFG: PHY_INTERFACE (Bitfield-Mask: 0x07) */
#define TT_SCU_EMAC_MISC_CFG_EXT_CLK_EXIST_Pos (3UL)            /*!< TT_SCU EMAC_MISC_CFG: EXT_CLK_EXIST (Bit 3)       */
#define TT_SCU_EMAC_MISC_CFG_EXT_CLK_EXIST_Msk (0x8UL)          /*!< TT_SCU EMAC_MISC_CFG: EXT_CLK_EXIST (Bitfield-Mask: 0x01) */
#define TT_SCU_EMAC_MISC_CFG_INV_TX_IN_Pos (4UL)                /*!< TT_SCU EMAC_MISC_CFG: INV_TX_IN (Bit 4)           */
#define TT_SCU_EMAC_MISC_CFG_INV_TX_IN_Msk (0x30UL)             /*!< TT_SCU EMAC_MISC_CFG: INV_TX_IN (Bitfield-Mask: 0x03) */
#define TT_SCU_EMAC_MISC_CFG_INV_RX_IN_Pos (6UL)                /*!< TT_SCU EMAC_MISC_CFG: INV_RX_IN (Bit 6)           */
#define TT_SCU_EMAC_MISC_CFG_INV_RX_IN_Msk (0xc0UL)             /*!< TT_SCU EMAC_MISC_CFG: INV_RX_IN (Bitfield-Mask: 0x03) */
#define TT_SCU_EMAC_MISC_CFG_INV_TX_OUT_Pos (8UL)               /*!< TT_SCU EMAC_MISC_CFG: INV_TX_OUT (Bit 8)          */
#define TT_SCU_EMAC_MISC_CFG_INV_TX_OUT_Msk (0x300UL)           /*!< TT_SCU EMAC_MISC_CFG: INV_TX_OUT (Bitfield-Mask: 0x03) */
/* ========================================================  ANA_CR  ========================================================= */
#define TT_SCU_ANA_CR_DIGITAL_12V_Pos (0UL)                     /*!< TT_SCU ANA_CR: DIGITAL_12V (Bit 0)                */
#define TT_SCU_ANA_CR_DIGITAL_12V_Msk (0x1UL)                   /*!< TT_SCU ANA_CR: DIGITAL_12V (Bitfield-Mask: 0x01)  */
#define TT_SCU_ANA_CR_TEMP_SENSOR0_Pos (1UL)                    /*!< TT_SCU ANA_CR: TEMP_SENSOR0 (Bit 1)               */
#define TT_SCU_ANA_CR_TEMP_SENSOR0_Msk (0x2UL)                  /*!< TT_SCU ANA_CR: TEMP_SENSOR0 (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_CR_TEMP_SENSOR1_Pos (2UL)                    /*!< TT_SCU ANA_CR: TEMP_SENSOR1 (Bit 2)               */
#define TT_SCU_ANA_CR_TEMP_SENSOR1_Msk (0x4UL)                  /*!< TT_SCU ANA_CR: TEMP_SENSOR1 (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_CR_DIGITAL_12V_BURR_Pos (16UL)               /*!< TT_SCU ANA_CR: DIGITAL_12V_BURR (Bit 16)          */
#define TT_SCU_ANA_CR_DIGITAL_12V_BURR_Msk (0x10000UL)          /*!< TT_SCU ANA_CR: DIGITAL_12V_BURR (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_CR_ANALOG_BURR_Pos (17UL)                    /*!< TT_SCU ANA_CR: ANALOG_BURR (Bit 17)               */
#define TT_SCU_ANA_CR_ANALOG_BURR_Msk (0x20000UL)               /*!< TT_SCU ANA_CR: ANALOG_BURR (Bitfield-Mask: 0x01)  */
#define TT_SCU_ANA_CR_LDOF_INPUT_BURR_Pos (18UL)                /*!< TT_SCU ANA_CR: LDOF_INPUT_BURR (Bit 18)           */
#define TT_SCU_ANA_CR_LDOF_INPUT_BURR_Msk (0x40000UL)           /*!< TT_SCU ANA_CR: LDOF_INPUT_BURR (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_CR_LDOF_OUTPUT_BURR_Pos (19UL)               /*!< TT_SCU ANA_CR: LDOF_OUTPUT_BURR (Bit 19)          */
#define TT_SCU_ANA_CR_LDOF_OUTPUT_BURR_Msk (0x80000UL)          /*!< TT_SCU ANA_CR: LDOF_OUTPUT_BURR (Bitfield-Mask: 0x01) */
/* =======================================================  ANA_TRIM0  ======================================================= */
#define TT_SCU_ANA_TRIM0_FIELD_Pos    (0UL)                     /*!< TT_SCU ANA_TRIM0: FIELD (Bit 0)                   */
#define TT_SCU_ANA_TRIM0_FIELD_Msk    (0xffffffffUL)            /*!< TT_SCU ANA_TRIM0: FIELD (Bitfield-Mask: 0xffffffff) */
/* =======================================================  ANA_TRIM1  ======================================================= */
#define TT_SCU_ANA_TRIM1_FIELD_Pos    (0UL)                     /*!< TT_SCU ANA_TRIM1: FIELD (Bit 0)                   */
#define TT_SCU_ANA_TRIM1_FIELD_Msk    (0xffffffffUL)            /*!< TT_SCU ANA_TRIM1: FIELD (Bitfield-Mask: 0xffffffff) */
/* =======================================================  ANA_TRIM2  ======================================================= */
#define TT_SCU_ANA_TRIM2_FIELD_Pos    (0UL)                     /*!< TT_SCU ANA_TRIM2: FIELD (Bit 0)                   */
#define TT_SCU_ANA_TRIM2_FIELD_Msk    (0xffffffffUL)            /*!< TT_SCU ANA_TRIM2: FIELD (Bitfield-Mask: 0xffffffff) */
/* =======================================================  ANA_TRIM3  ======================================================= */
#define TT_SCU_ANA_TRIM3_FIELD_Pos    (0UL)                     /*!< TT_SCU ANA_TRIM3: FIELD (Bit 0)                   */
#define TT_SCU_ANA_TRIM3_FIELD_Msk    (0xffffffffUL)            /*!< TT_SCU ANA_TRIM3: FIELD (Bitfield-Mask: 0xffffffff) */
/* ======================================================  ANA_TRIM_CR  ====================================================== */
#define TT_SCU_ANA_TRIM_CR_BG0_TRIM_VLD_Pos (0UL)               /*!< TT_SCU ANA_TRIM_CR: BG0_TRIM_VLD (Bit 0)          */
#define TT_SCU_ANA_TRIM_CR_BG0_TRIM_VLD_Msk (0x1UL)             /*!< TT_SCU ANA_TRIM_CR: BG0_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_BG1_TRIM_VLD_Pos (1UL)               /*!< TT_SCU ANA_TRIM_CR: BG1_TRIM_VLD (Bit 1)          */
#define TT_SCU_ANA_TRIM_CR_BG1_TRIM_VLD_Msk (0x2UL)             /*!< TT_SCU ANA_TRIM_CR: BG1_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_LDOF_TRIM_VLD_Pos (2UL)              /*!< TT_SCU ANA_TRIM_CR: LDOF_TRIM_VLD (Bit 2)         */
#define TT_SCU_ANA_TRIM_CR_LDOF_TRIM_VLD_Msk (0x4UL)            /*!< TT_SCU ANA_TRIM_CR: LDOF_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_LDOA_TRIM_VLD_Pos (3UL)              /*!< TT_SCU ANA_TRIM_CR: LDOA_TRIM_VLD (Bit 3)         */
#define TT_SCU_ANA_TRIM_CR_LDOA_TRIM_VLD_Msk (0x8UL)            /*!< TT_SCU ANA_TRIM_CR: LDOA_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_LDOD_TRIM_VLD_Pos (4UL)              /*!< TT_SCU ANA_TRIM_CR: LDOD_TRIM_VLD (Bit 4)         */
#define TT_SCU_ANA_TRIM_CR_LDOD_TRIM_VLD_Msk (0x10UL)           /*!< TT_SCU ANA_TRIM_CR: LDOD_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_LDOC0_TRIM_VLD_Pos (5UL)             /*!< TT_SCU ANA_TRIM_CR: LDOC0_TRIM_VLD (Bit 5)        */
#define TT_SCU_ANA_TRIM_CR_LDOC0_TRIM_VLD_Msk (0x20UL)          /*!< TT_SCU ANA_TRIM_CR: LDOC0_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_LDOC1_TRIM_VLD_Pos (6UL)             /*!< TT_SCU ANA_TRIM_CR: LDOC1_TRIM_VLD (Bit 6)        */
#define TT_SCU_ANA_TRIM_CR_LDOC1_TRIM_VLD_Msk (0x40UL)          /*!< TT_SCU ANA_TRIM_CR: LDOC1_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_TEMPER0_TRIM_VLD_Pos (7UL)           /*!< TT_SCU ANA_TRIM_CR: TEMPER0_TRIM_VLD (Bit 7)      */
#define TT_SCU_ANA_TRIM_CR_TEMPER0_TRIM_VLD_Msk (0x80UL)        /*!< TT_SCU ANA_TRIM_CR: TEMPER0_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_TEMPER1_TRIM_VLD_Pos (8UL)           /*!< TT_SCU ANA_TRIM_CR: TEMPER1_TRIM_VLD (Bit 8)      */
#define TT_SCU_ANA_TRIM_CR_TEMPER1_TRIM_VLD_Msk (0x100UL)       /*!< TT_SCU ANA_TRIM_CR: TEMPER1_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_ILO_TRIM_VLD_Pos (9UL)               /*!< TT_SCU ANA_TRIM_CR: ILO_TRIM_VLD (Bit 9)          */
#define TT_SCU_ANA_TRIM_CR_ILO_TRIM_VLD_Msk (0x200UL)           /*!< TT_SCU ANA_TRIM_CR: ILO_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_IHO_TRIM_VLD_Pos (10UL)              /*!< TT_SCU ANA_TRIM_CR: IHO_TRIM_VLD (Bit 10)         */
#define TT_SCU_ANA_TRIM_CR_IHO_TRIM_VLD_Msk (0x400UL)           /*!< TT_SCU ANA_TRIM_CR: IHO_TRIM_VLD (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_LDOP_SWITCH_DIS_Pos (16UL)           /*!< TT_SCU ANA_TRIM_CR: LDOP_SWITCH_DIS (Bit 16)      */
#define TT_SCU_ANA_TRIM_CR_LDOP_SWITCH_DIS_Msk (0x10000UL)      /*!< TT_SCU ANA_TRIM_CR: LDOP_SWITCH_DIS (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_TRIM_CR_ANA_TRIM_LK_Pos (31UL)               /*!< TT_SCU ANA_TRIM_CR: ANA_TRIM_LK (Bit 31)          */
#define TT_SCU_ANA_TRIM_CR_ANA_TRIM_LK_Msk (0x80000000UL)       /*!< TT_SCU ANA_TRIM_CR: ANA_TRIM_LK (Bitfield-Mask: 0x01) */
/* ======================================================  ANA_TEST_CR  ====================================================== */
#define TT_SCU_ANA_TEST_CR_BBPASS_Pos (0UL)                     /*!< TT_SCU ANA_TEST_CR: BBPASS (Bit 0)                */
#define TT_SCU_ANA_TEST_CR_BBPASS_Msk (0x1UL)                   /*!< TT_SCU ANA_TEST_CR: BBPASS (Bitfield-Mask: 0x01)  */
#define TT_SCU_ANA_TEST_CR_TEST_SEL_Pos (1UL)                   /*!< TT_SCU ANA_TEST_CR: TEST_SEL (Bit 1)              */
#define TT_SCU_ANA_TEST_CR_TEST_SEL_Msk (0x1eUL)                /*!< TT_SCU ANA_TEST_CR: TEST_SEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_ANA_TEST_CR_FLASH_TM0_SEL_Pos (5UL)              /*!< TT_SCU ANA_TEST_CR: FLASH_TM0_SEL (Bit 5)         */
#define TT_SCU_ANA_TEST_CR_FLASH_TM0_SEL_Msk (0xe0UL)           /*!< TT_SCU ANA_TEST_CR: FLASH_TM0_SEL (Bitfield-Mask: 0x07) */
#define TT_SCU_ANA_TEST_CR_ENABLE_Pos (31UL)                    /*!< TT_SCU ANA_TEST_CR: ENABLE (Bit 31)               */
#define TT_SCU_ANA_TEST_CR_ENABLE_Msk (0x80000000UL)            /*!< TT_SCU ANA_TEST_CR: ENABLE (Bitfield-Mask: 0x01)  */
/* =====================================================  ANA_BUCK_TCR  ====================================================== */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_EN_Pos (0UL)               /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_EN (Bit 0)          */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_EN_Msk (0x1UL)             /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_SLEEP_Pos (1UL)            /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_SLEEP (Bit 1)       */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_SLEEP_Msk (0x2UL)          /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_SLEEP (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_PWM_Pos (2UL)              /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_PWM (Bit 2)         */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_PWM_Msk (0x4UL)            /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_PWM (Bitfield-Mask: 0x01) */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_MODULE_CTR_Pos (4UL)       /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_MODULE_CTR (Bit 4)  */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_MODULE_CTR_Msk (0x7ff0UL)  /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_MODULE_CTR (Bitfield-Mask: 0x7ff) */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_ATEST_SEL_Pos (16UL)       /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_ATEST_SEL (Bit 16)  */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_ATEST_SEL_Msk (0x3f0000UL) /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_ATEST_SEL (Bitfield-Mask: 0x3f) */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_TEST_VLD_Pos (31UL)        /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_TEST_VLD (Bit 31)   */
#define TT_SCU_ANA_BUCK_TCR_ANA_BUCK_TEST_VLD_Msk (0x80000000UL) /*!< TT_SCU ANA_BUCK_TCR: ANA_BUCK_TEST_VLD (Bitfield-Mask: 0x01) */
/* =========================================================================================================================== */
/* ================                                           CMUX                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  CMUX_CR  ======================================================== */
#define TT_SCU_CMUX_CMUX_CR_EN_Pos        (0UL)                     /*!< EN (Bit 0)                                            */
#define TT_SCU_CMUX_CMUX_CR_EN_Msk        (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
#define TT_SCU_CMUX_CMUX_CR_HTHD_ALARM_EN_Pos (1UL)                 /*!< HTHD_ALARM_EN (Bit 1)                                 */
#define TT_SCU_CMUX_CMUX_CR_HTHD_ALARM_EN_Msk (0x2UL)               /*!< HTHD_ALARM_EN (Bitfield-Mask: 0x01)                   */
#define TT_SCU_CMUX_CMUX_CR_LTHD_ALARM_EN_Pos (2UL)                 /*!< LTHD_ALARM_EN (Bit 2)                                 */
#define TT_SCU_CMUX_CMUX_CR_LTHD_ALARM_EN_Msk (0x4UL)               /*!< LTHD_ALARM_EN (Bitfield-Mask: 0x01)                   */
#define TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Pos (3UL)              /*!< TIMEOUT_ALARM_EN (Bit 3)                              */
#define TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk (0x8UL)            /*!< TIMEOUT_ALARM_EN (Bitfield-Mask: 0x01)                */
/* =======================================================  CMUX_CHKW  ======================================================= */
#define TT_SCU_CMUX_CMUX_CHKW_FIELD_Pos   (0UL)                     /*!< FIELD (Bit 0)                                         */
#define TT_SCU_CMUX_CMUX_CHKW_FIELD_Msk   (0x1fUL)                  /*!< FIELD (Bitfield-Mask: 0x1f)                           */
/* =======================================================  CMUX_THD  ======================================================== */
#define TT_SCU_CMUX_CMUX_THD_LTHD_Pos     (0UL)                     /*!< LTHD (Bit 0)                                          */
#define TT_SCU_CMUX_CMUX_THD_LTHD_Msk     (0xffUL)                  /*!< LTHD (Bitfield-Mask: 0xff)                            */
#define TT_SCU_CMUX_CMUX_THD_HTHD_Pos     (16UL)                    /*!< HTHD (Bit 16)                                         */
#define TT_SCU_CMUX_CMUX_THD_HTHD_Msk     (0xff0000UL)              /*!< HTHD (Bitfield-Mask: 0xff)                            */

/* ========================================================  INT_CR  ========================================================= */
#define TT_SCU_INT_CR_RSTB_RST_SHDN_Pos (0UL)                   /*!< TT_SCU INT_CR: RSTB_RST_SHDN (Bit 0)              */
#define TT_SCU_INT_CR_RSTB_RST_SHDN_Msk (0x1UL)                 /*!< TT_SCU INT_CR: RSTB_RST_SHDN (Bitfield-Mask: 0x01) */
#define TT_SCU_INT_CR_SMU_RST_SHDN_Pos (1UL)                    /*!< TT_SCU INT_CR: SMU_RST_SHDN (Bit 1)               */
#define TT_SCU_INT_CR_SMU_RST_SHDN_Msk (0x2UL)                  /*!< TT_SCU INT_CR: SMU_RST_SHDN (Bitfield-Mask: 0x01) */
#define TT_SCU_INT_CR_SOFT_RST_SHDN_Pos (2UL)                   /*!< TT_SCU INT_CR: SOFT_RST_SHDN (Bit 2)              */
#define TT_SCU_INT_CR_SOFT_RST_SHDN_Msk (0x4UL)                 /*!< TT_SCU INT_CR: SOFT_RST_SHDN (Bitfield-Mask: 0x01) */
#define TT_SCU_INT_CR_SMU_CPU0_RST_SHDN_Pos (3UL)               /*!< TT_SCU INT_CR: SMU_CPU0_RST_SHDN (Bit 3)          */
#define TT_SCU_INT_CR_SMU_CPU0_RST_SHDN_Msk (0x8UL)             /*!< TT_SCU INT_CR: SMU_CPU0_RST_SHDN (Bitfield-Mask: 0x01) */
/* ======================================================  INT_STATUS  ======================================================= */
#define TT_SCU_INT_STATUS_RSTB_RESET_Pos (0UL)                  /*!< TT_SCU INT_STATUS: RSTB_RESET (Bit 0)             */
#define TT_SCU_INT_STATUS_RSTB_RESET_Msk (0x1UL)                /*!< TT_SCU INT_STATUS: RSTB_RESET (Bitfield-Mask: 0x01) */
#define TT_SCU_INT_STATUS_SMU_RST_SHDN_STATUS_Pos (1UL)         /*!< TT_SCU INT_STATUS: SMU_RST_SHDN_STATUS (Bit 1)    */
#define TT_SCU_INT_STATUS_SMU_RST_SHDN_STATUS_Msk (0x2UL)       /*!< TT_SCU INT_STATUS: SMU_RST_SHDN_STATUS (Bitfield-Mask: 0x01) */
#define TT_SCU_INT_STATUS_SOFT_RST_SHDN_STATUS_Pos (2UL)        /*!< TT_SCU INT_STATUS: SOFT_RST_SHDN_STATUS (Bit 2)   */
#define TT_SCU_INT_STATUS_SOFT_RST_SHDN_STATUS_Msk (0x4UL)      /*!< TT_SCU INT_STATUS: SOFT_RST_SHDN_STATUS (Bitfield-Mask: 0x01) */
#define TT_SCU_INT_STATUS_SMU_CPU0_RST_SHDN_STATUS_Pos (3UL)    /*!< TT_SCU INT_STATUS: SMU_CPU0_RST_SHDN_STATUS (Bit 3) */
#define TT_SCU_INT_STATUS_SMU_CPU0_RST_SHDN_STATUS_Msk (0x8UL)  /*!< TT_SCU INT_STATUS: SMU_CPU0_RST_SHDN_STATUS (Bitfield-Mask: 0x01) */
/* ========================================================  SCU_ID  ========================================================= */
#define TT_SCU_SCU_ID_ID_Pos          (0UL)                     /*!< TT_SCU SCU_ID: ID (Bit 0)                         */
#define TT_SCU_SCU_ID_ID_Msk          (0xffffffffUL)            /*!< TT_SCU SCU_ID: ID (Bitfield-Mask: 0xffffffff)     */
/* =======================================================  SCU_SUPV  ======================================================== */
#define TT_SCU_SCU_SUPV_MODE_Pos      (0UL)                     /*!< TT_SCU SCU_SUPV: MODE (Bit 0)                     */
#define TT_SCU_SCU_SUPV_MODE_Msk      (0x1UL)                   /*!< TT_SCU SCU_SUPV: MODE (Bitfield-Mask: 0x01)       */
/* ======================================================  SJTAG_KEY0  ======================================================= */
#define TT_SCU_SJTAG_KEY0_KEY_Pos     (0UL)                     /*!< TT_SCU SJTAG_KEY0: KEY (Bit 0)                    */
#define TT_SCU_SJTAG_KEY0_KEY_Msk     (0xffffffffUL)            /*!< TT_SCU SJTAG_KEY0: KEY (Bitfield-Mask: 0xffffffff) */
/* ======================================================  SJTAG_KEY1  ======================================================= */
#define TT_SCU_SJTAG_KEY1_KEY_Pos     (0UL)                     /*!< TT_SCU SJTAG_KEY1: KEY (Bit 0)                    */
#define TT_SCU_SJTAG_KEY1_KEY_Msk     (0xffffffffUL)            /*!< TT_SCU SJTAG_KEY1: KEY (Bitfield-Mask: 0xffffffff) */
/* ======================================================  SJTAG_KEY2  ======================================================= */
#define TT_SCU_SJTAG_KEY2_KEY_Pos     (0UL)                     /*!< TT_SCU SJTAG_KEY2: KEY (Bit 0)                    */
#define TT_SCU_SJTAG_KEY2_KEY_Msk     (0xffffffffUL)            /*!< TT_SCU SJTAG_KEY2: KEY (Bitfield-Mask: 0xffffffff) */
/* ======================================================  SJTAG_KEY3  ======================================================= */
#define TT_SCU_SJTAG_KEY3_KEY_Pos     (0UL)                     /*!< TT_SCU SJTAG_KEY3: KEY (Bit 0)                    */
#define TT_SCU_SJTAG_KEY3_KEY_Msk     (0xffffffffUL)            /*!< TT_SCU SJTAG_KEY3: KEY (Bitfield-Mask: 0xffffffff) */
/* =======================================================  PAD_INFUN  ======================================================= */
#define TT_SCU_PAD_INFUN_PAD0_INSEL_Pos (0UL)                   /*!< TT_SCU PAD_INFUN: PAD0_INSEL (Bit 0)              */
#define TT_SCU_PAD_INFUN_PAD0_INSEL_Msk (0xfUL)                 /*!< TT_SCU PAD_INFUN: PAD0_INSEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_PAD_INFUN_PAD0_INPUT_EN_Pos (4UL)                /*!< TT_SCU PAD_INFUN: PAD0_INPUT_EN (Bit 4)           */
#define TT_SCU_PAD_INFUN_PAD0_INPUT_EN_Msk (0x10UL)             /*!< TT_SCU PAD_INFUN: PAD0_INPUT_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD0_PD_EN_Pos (5UL)                   /*!< TT_SCU PAD_INFUN: PAD0_PD_EN (Bit 5)              */
#define TT_SCU_PAD_INFUN_PAD0_PD_EN_Msk (0x20UL)                /*!< TT_SCU PAD_INFUN: PAD0_PD_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD0_PU_EN_Pos (6UL)                   /*!< TT_SCU PAD_INFUN: PAD0_PU_EN (Bit 6)              */
#define TT_SCU_PAD_INFUN_PAD0_PU_EN_Msk (0x40UL)                /*!< TT_SCU PAD_INFUN: PAD0_PU_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD0_INPUT_LOCK_Pos (7UL)              /*!< TT_SCU PAD_INFUN: PAD0_INPUT_LOCK (Bit 7)         */
#define TT_SCU_PAD_INFUN_PAD0_INPUT_LOCK_Msk (0x80UL)           /*!< TT_SCU PAD_INFUN: PAD0_INPUT_LOCK (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD1_INSEL_Pos (8UL)                   /*!< TT_SCU PAD_INFUN: PAD1_INSEL (Bit 8)              */
#define TT_SCU_PAD_INFUN_PAD1_INSEL_Msk (0xf00UL)               /*!< TT_SCU PAD_INFUN: PAD1_INSEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_PAD_INFUN_PAD1_INPUT_EN_Pos (12UL)               /*!< TT_SCU PAD_INFUN: PAD1_INPUT_EN (Bit 12)          */
#define TT_SCU_PAD_INFUN_PAD1_INPUT_EN_Msk (0x1000UL)           /*!< TT_SCU PAD_INFUN: PAD1_INPUT_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD1_PD_EN_Pos (13UL)                  /*!< TT_SCU PAD_INFUN: PAD1_PD_EN (Bit 13)             */
#define TT_SCU_PAD_INFUN_PAD1_PD_EN_Msk (0x2000UL)              /*!< TT_SCU PAD_INFUN: PAD1_PD_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD1_PU_EN_Pos (14UL)                  /*!< TT_SCU PAD_INFUN: PAD1_PU_EN (Bit 14)             */
#define TT_SCU_PAD_INFUN_PAD1_PU_EN_Msk (0x4000UL)              /*!< TT_SCU PAD_INFUN: PAD1_PU_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD1_INPUT_LOCK_Pos (15UL)             /*!< TT_SCU PAD_INFUN: PAD1_INPUT_LOCK (Bit 15)        */
#define TT_SCU_PAD_INFUN_PAD1_INPUT_LOCK_Msk (0x8000UL)         /*!< TT_SCU PAD_INFUN: PAD1_INPUT_LOCK (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD2_INSEL_Pos (16UL)                  /*!< TT_SCU PAD_INFUN: PAD2_INSEL (Bit 16)             */
#define TT_SCU_PAD_INFUN_PAD2_INSEL_Msk (0xf0000UL)             /*!< TT_SCU PAD_INFUN: PAD2_INSEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_PAD_INFUN_PAD2_INPUT_EN_Pos (20UL)               /*!< TT_SCU PAD_INFUN: PAD2_INPUT_EN (Bit 20)          */
#define TT_SCU_PAD_INFUN_PAD2_INPUT_EN_Msk (0x100000UL)         /*!< TT_SCU PAD_INFUN: PAD2_INPUT_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD2_PD_EN_Pos (21UL)                  /*!< TT_SCU PAD_INFUN: PAD2_PD_EN (Bit 21)             */
#define TT_SCU_PAD_INFUN_PAD2_PD_EN_Msk (0x200000UL)            /*!< TT_SCU PAD_INFUN: PAD2_PD_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD2_PU_EN_Pos (22UL)                  /*!< TT_SCU PAD_INFUN: PAD2_PU_EN (Bit 22)             */
#define TT_SCU_PAD_INFUN_PAD2_PU_EN_Msk (0x400000UL)            /*!< TT_SCU PAD_INFUN: PAD2_PU_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD2_INPUT_LOCK_Pos (23UL)             /*!< TT_SCU PAD_INFUN: PAD2_INPUT_LOCK (Bit 23)        */
#define TT_SCU_PAD_INFUN_PAD2_INPUT_LOCK_Msk (0x800000UL)       /*!< TT_SCU PAD_INFUN: PAD2_INPUT_LOCK (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD3_INSEL_Pos (24UL)                  /*!< TT_SCU PAD_INFUN: PAD3_INSEL (Bit 24)             */
#define TT_SCU_PAD_INFUN_PAD3_INSEL_Msk (0xf000000UL)           /*!< TT_SCU PAD_INFUN: PAD3_INSEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_PAD_INFUN_PAD3_INPUT_EN_Pos (28UL)               /*!< TT_SCU PAD_INFUN: PAD3_INPUT_EN (Bit 28)          */
#define TT_SCU_PAD_INFUN_PAD3_INPUT_EN_Msk (0x10000000UL)       /*!< TT_SCU PAD_INFUN: PAD3_INPUT_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD3_PD_EN_Pos (29UL)                  /*!< TT_SCU PAD_INFUN: PAD3_PD_EN (Bit 29)             */
#define TT_SCU_PAD_INFUN_PAD3_PD_EN_Msk (0x20000000UL)          /*!< TT_SCU PAD_INFUN: PAD3_PD_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD3_PU_EN_Pos (30UL)                  /*!< TT_SCU PAD_INFUN: PAD3_PU_EN (Bit 30)             */
#define TT_SCU_PAD_INFUN_PAD3_PU_EN_Msk (0x40000000UL)          /*!< TT_SCU PAD_INFUN: PAD3_PU_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_INFUN_PAD3_INPUT_LOCK_Pos (31UL)             /*!< TT_SCU PAD_INFUN: PAD3_INPUT_LOCK (Bit 31)        */
#define TT_SCU_PAD_INFUN_PAD3_INPUT_LOCK_Msk (0x80000000UL)     /*!< TT_SCU PAD_INFUN: PAD3_INPUT_LOCK (Bitfield-Mask: 0x01) */
/* =======================================================  IOM_INSEL  ======================================================= */
#define TT_SCU_IOM_INSEL_IOM0_INSEL_Pos (0UL)                   /*!< TT_SCU IOM_INSEL: IOM0_INSEL (Bit 0)              */
#define TT_SCU_IOM_INSEL_IOM0_INSEL_Msk (0x7UL)                 /*!< TT_SCU IOM_INSEL: IOM0_INSEL (Bitfield-Mask: 0x07) */
#define TT_SCU_IOM_INSEL_IOM1_INSEL_Pos (4UL)                   /*!< TT_SCU IOM_INSEL: IOM1_INSEL (Bit 4)              */
#define TT_SCU_IOM_INSEL_IOM1_INSEL_Msk (0x70UL)                /*!< TT_SCU IOM_INSEL: IOM1_INSEL (Bitfield-Mask: 0x07) */
#define TT_SCU_IOM_INSEL_IOM2_INSEL_Pos (8UL)                   /*!< TT_SCU IOM_INSEL: IOM2_INSEL (Bit 8)              */
#define TT_SCU_IOM_INSEL_IOM2_INSEL_Msk (0x700UL)               /*!< TT_SCU IOM_INSEL: IOM2_INSEL (Bitfield-Mask: 0x07) */
#define TT_SCU_IOM_INSEL_IOM3_INSEL_Pos (12UL)                  /*!< TT_SCU IOM_INSEL: IOM3_INSEL (Bit 12)             */
#define TT_SCU_IOM_INSEL_IOM3_INSEL_Msk (0x7000UL)              /*!< TT_SCU IOM_INSEL: IOM3_INSEL (Bitfield-Mask: 0x07) */
#define TT_SCU_IOM_INSEL_IOM4_INSEL_Pos (16UL)                  /*!< TT_SCU IOM_INSEL: IOM4_INSEL (Bit 16)             */
#define TT_SCU_IOM_INSEL_IOM4_INSEL_Msk (0x70000UL)             /*!< TT_SCU IOM_INSEL: IOM4_INSEL (Bitfield-Mask: 0x07) */
#define TT_SCU_IOM_INSEL_IOM5_INSEL_Pos (20UL)                  /*!< TT_SCU IOM_INSEL: IOM5_INSEL (Bit 20)             */
#define TT_SCU_IOM_INSEL_IOM5_INSEL_Msk (0x700000UL)            /*!< TT_SCU IOM_INSEL: IOM5_INSEL (Bitfield-Mask: 0x07) */
#define TT_SCU_IOM_INSEL_IOM6_INSEL_Pos (24UL)                  /*!< TT_SCU IOM_INSEL: IOM6_INSEL (Bit 24)             */
#define TT_SCU_IOM_INSEL_IOM6_INSEL_Msk (0x7000000UL)           /*!< TT_SCU IOM_INSEL: IOM6_INSEL (Bitfield-Mask: 0x07) */
#define TT_SCU_IOM_INSEL_IOM7_INSEL_Pos (28UL)                  /*!< TT_SCU IOM_INSEL: IOM7_INSEL (Bit 28)             */
#define TT_SCU_IOM_INSEL_IOM7_INSEL_Msk (0x70000000UL)          /*!< TT_SCU IOM_INSEL: IOM7_INSEL (Bitfield-Mask: 0x07) */
/* =======================================================  PAD_FUNC  ======================================================== */
#define TT_SCU_PAD_FUNC_PAD0_FUNC_Pos (0UL)                     /*!< TT_SCU PAD_FUNC: PAD0_FUNC (Bit 0)                */
#define TT_SCU_PAD_FUNC_PAD0_FUNC_Msk (0x7UL)                   /*!< TT_SCU PAD_FUNC: PAD0_FUNC (Bitfield-Mask: 0x07)  */
#define TT_SCU_PAD_FUNC_PAD0_MODE_Pos (3UL)                     /*!< TT_SCU PAD_FUNC: PAD0_MODE (Bit 3)                */
#define TT_SCU_PAD_FUNC_PAD0_MODE_Msk (0x8UL)                   /*!< TT_SCU PAD_FUNC: PAD0_MODE (Bitfield-Mask: 0x01)  */
#define TT_SCU_PAD_FUNC_PAD0_OUTPUT_Pos (4UL)                   /*!< TT_SCU PAD_FUNC: PAD0_OUTPUT (Bit 4)              */
#define TT_SCU_PAD_FUNC_PAD0_OUTPUT_Msk (0x10UL)                /*!< TT_SCU PAD_FUNC: PAD0_OUTPUT (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD0_DRIVE_Pos (5UL)                    /*!< TT_SCU PAD_FUNC: PAD0_DRIVE (Bit 5)               */
#define TT_SCU_PAD_FUNC_PAD0_DRIVE_Msk (0x20UL)                 /*!< TT_SCU PAD_FUNC: PAD0_DRIVE (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD0_OUTFUNC_LOCK_Pos (6UL)             /*!< TT_SCU PAD_FUNC: PAD0_OUTFUNC_LOCK (Bit 6)        */
#define TT_SCU_PAD_FUNC_PAD0_OUTFUNC_LOCK_Msk (0x40UL)          /*!< TT_SCU PAD_FUNC: PAD0_OUTFUNC_LOCK (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD1_FUNC_Pos (8UL)                     /*!< TT_SCU PAD_FUNC: PAD1_FUNC (Bit 8)                */
#define TT_SCU_PAD_FUNC_PAD1_FUNC_Msk (0x700UL)                 /*!< TT_SCU PAD_FUNC: PAD1_FUNC (Bitfield-Mask: 0x07)  */
#define TT_SCU_PAD_FUNC_PAD1_MODE_Pos (11UL)                    /*!< TT_SCU PAD_FUNC: PAD1_MODE (Bit 11)               */
#define TT_SCU_PAD_FUNC_PAD1_MODE_Msk (0x800UL)                 /*!< TT_SCU PAD_FUNC: PAD1_MODE (Bitfield-Mask: 0x01)  */
#define TT_SCU_PAD_FUNC_PAD1_OUTPUT_Pos (12UL)                  /*!< TT_SCU PAD_FUNC: PAD1_OUTPUT (Bit 12)             */
#define TT_SCU_PAD_FUNC_PAD1_OUTPUT_Msk (0x1000UL)              /*!< TT_SCU PAD_FUNC: PAD1_OUTPUT (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD1_DRIVE_Pos (13UL)                   /*!< TT_SCU PAD_FUNC: PAD1_DRIVE (Bit 13)              */
#define TT_SCU_PAD_FUNC_PAD1_DRIVE_Msk (0x2000UL)               /*!< TT_SCU PAD_FUNC: PAD1_DRIVE (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD1_OUTFUNC_LOCK_Pos (14UL)            /*!< TT_SCU PAD_FUNC: PAD1_OUTFUNC_LOCK (Bit 14)       */
#define TT_SCU_PAD_FUNC_PAD1_OUTFUNC_LOCK_Msk (0x4000UL)        /*!< TT_SCU PAD_FUNC: PAD1_OUTFUNC_LOCK (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD2_FUNC_Pos (16UL)                    /*!< TT_SCU PAD_FUNC: PAD2_FUNC (Bit 16)               */
#define TT_SCU_PAD_FUNC_PAD2_FUNC_Msk (0x70000UL)               /*!< TT_SCU PAD_FUNC: PAD2_FUNC (Bitfield-Mask: 0x07)  */
#define TT_SCU_PAD_FUNC_PAD2_MODE_Pos (19UL)                    /*!< TT_SCU PAD_FUNC: PAD2_MODE (Bit 19)               */
#define TT_SCU_PAD_FUNC_PAD2_MODE_Msk (0x80000UL)               /*!< TT_SCU PAD_FUNC: PAD2_MODE (Bitfield-Mask: 0x01)  */
#define TT_SCU_PAD_FUNC_PAD2_OUTPUT_Pos (20UL)                  /*!< TT_SCU PAD_FUNC: PAD2_OUTPUT (Bit 20)             */
#define TT_SCU_PAD_FUNC_PAD2_OUTPUT_Msk (0x100000UL)            /*!< TT_SCU PAD_FUNC: PAD2_OUTPUT (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD2_DRIVE_Pos (21UL)                   /*!< TT_SCU PAD_FUNC: PAD2_DRIVE (Bit 21)              */
#define TT_SCU_PAD_FUNC_PAD2_DRIVE_Msk (0x200000UL)             /*!< TT_SCU PAD_FUNC: PAD2_DRIVE (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD2_OUTFUNC_LOCK_Pos (22UL)            /*!< TT_SCU PAD_FUNC: PAD2_OUTFUNC_LOCK (Bit 22)       */
#define TT_SCU_PAD_FUNC_PAD2_OUTFUNC_LOCK_Msk (0x400000UL)      /*!< TT_SCU PAD_FUNC: PAD2_OUTFUNC_LOCK (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD3_FUNC_Pos (24UL)                    /*!< TT_SCU PAD_FUNC: PAD3_FUNC (Bit 24)               */
#define TT_SCU_PAD_FUNC_PAD3_FUNC_Msk (0x7000000UL)             /*!< TT_SCU PAD_FUNC: PAD3_FUNC (Bitfield-Mask: 0x07)  */
#define TT_SCU_PAD_FUNC_PAD3_MODE_Pos (27UL)                    /*!< TT_SCU PAD_FUNC: PAD3_MODE (Bit 27)               */
#define TT_SCU_PAD_FUNC_PAD3_MODE_Msk (0x8000000UL)             /*!< TT_SCU PAD_FUNC: PAD3_MODE (Bitfield-Mask: 0x01)  */
#define TT_SCU_PAD_FUNC_PAD3_OUTPUT_Pos (28UL)                  /*!< TT_SCU PAD_FUNC: PAD3_OUTPUT (Bit 28)             */
#define TT_SCU_PAD_FUNC_PAD3_OUTPUT_Msk (0x10000000UL)          /*!< TT_SCU PAD_FUNC: PAD3_OUTPUT (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD3_DRIVE_Pos (29UL)                   /*!< TT_SCU PAD_FUNC: PAD3_DRIVE (Bit 29)              */
#define TT_SCU_PAD_FUNC_PAD3_DRIVE_Msk (0x20000000UL)           /*!< TT_SCU PAD_FUNC: PAD3_DRIVE (Bitfield-Mask: 0x01) */
#define TT_SCU_PAD_FUNC_PAD3_OUTFUNC_LOCK_Pos (30UL)            /*!< TT_SCU PAD_FUNC: PAD3_OUTFUNC_LOCK (Bit 30)       */
#define TT_SCU_PAD_FUNC_PAD3_OUTFUNC_LOCK_Msk (0x40000000UL)    /*!< TT_SCU PAD_FUNC: PAD3_OUTFUNC_LOCK (Bitfield-Mask: 0x01) */
/* =======================================================  PAD_PROBE  ======================================================= */
#define TT_SCU_PAD_PROBE_PAD0_PROBESEL_Pos (0UL)                /*!< TT_SCU PAD_PROBE: PAD0_PROBESEL (Bit 0)           */
#define TT_SCU_PAD_PROBE_PAD0_PROBESEL_Msk (0x3UL)              /*!< TT_SCU PAD_PROBE: PAD0_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD1_PROBESEL_Pos (2UL)                /*!< TT_SCU PAD_PROBE: PAD1_PROBESEL (Bit 2)           */
#define TT_SCU_PAD_PROBE_PAD1_PROBESEL_Msk (0xcUL)              /*!< TT_SCU PAD_PROBE: PAD1_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD2_PROBESEL_Pos (4UL)                /*!< TT_SCU PAD_PROBE: PAD2_PROBESEL (Bit 4)           */
#define TT_SCU_PAD_PROBE_PAD2_PROBESEL_Msk (0x30UL)             /*!< TT_SCU PAD_PROBE: PAD2_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD3_PROBESEL_Pos (6UL)                /*!< TT_SCU PAD_PROBE: PAD3_PROBESEL (Bit 6)           */
#define TT_SCU_PAD_PROBE_PAD3_PROBESEL_Msk (0xc0UL)             /*!< TT_SCU PAD_PROBE: PAD3_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD4_PROBESEL_Pos (8UL)                /*!< TT_SCU PAD_PROBE: PAD4_PROBESEL (Bit 8)           */
#define TT_SCU_PAD_PROBE_PAD4_PROBESEL_Msk (0x300UL)            /*!< TT_SCU PAD_PROBE: PAD4_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD5_PROBESEL_Pos (10UL)               /*!< TT_SCU PAD_PROBE: PAD5_PROBESEL (Bit 10)          */
#define TT_SCU_PAD_PROBE_PAD5_PROBESEL_Msk (0xc00UL)            /*!< TT_SCU PAD_PROBE: PAD5_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD6_PROBESEL_Pos (12UL)               /*!< TT_SCU PAD_PROBE: PAD6_PROBESEL (Bit 12)          */
#define TT_SCU_PAD_PROBE_PAD6_PROBESEL_Msk (0x3000UL)           /*!< TT_SCU PAD_PROBE: PAD6_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD7_PROBESEL_Pos (14UL)               /*!< TT_SCU PAD_PROBE: PAD7_PROBESEL (Bit 14)          */
#define TT_SCU_PAD_PROBE_PAD7_PROBESEL_Msk (0xc000UL)           /*!< TT_SCU PAD_PROBE: PAD7_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD8_PROBESEL_Pos (16UL)               /*!< TT_SCU PAD_PROBE: PAD8_PROBESEL (Bit 16)          */
#define TT_SCU_PAD_PROBE_PAD8_PROBESEL_Msk (0x30000UL)          /*!< TT_SCU PAD_PROBE: PAD8_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD9_PROBESEL_Pos (18UL)               /*!< TT_SCU PAD_PROBE: PAD9_PROBESEL (Bit 18)          */
#define TT_SCU_PAD_PROBE_PAD9_PROBESEL_Msk (0xc0000UL)          /*!< TT_SCU PAD_PROBE: PAD9_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD10_PROBESEL_Pos (20UL)              /*!< TT_SCU PAD_PROBE: PAD10_PROBESEL (Bit 20)         */
#define TT_SCU_PAD_PROBE_PAD10_PROBESEL_Msk (0x300000UL)        /*!< TT_SCU PAD_PROBE: PAD10_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD11_PROBESEL_Pos (22UL)              /*!< TT_SCU PAD_PROBE: PAD11_PROBESEL (Bit 22)         */
#define TT_SCU_PAD_PROBE_PAD11_PROBESEL_Msk (0xc00000UL)        /*!< TT_SCU PAD_PROBE: PAD11_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD12_PROBESEL_Pos (24UL)              /*!< TT_SCU PAD_PROBE: PAD12_PROBESEL (Bit 24)         */
#define TT_SCU_PAD_PROBE_PAD12_PROBESEL_Msk (0x3000000UL)       /*!< TT_SCU PAD_PROBE: PAD12_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD13_PROBESEL_Pos (26UL)              /*!< TT_SCU PAD_PROBE: PAD13_PROBESEL (Bit 26)         */
#define TT_SCU_PAD_PROBE_PAD13_PROBESEL_Msk (0xc000000UL)       /*!< TT_SCU PAD_PROBE: PAD13_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD14_PROBESEL_Pos (28UL)              /*!< TT_SCU PAD_PROBE: PAD14_PROBESEL (Bit 28)         */
#define TT_SCU_PAD_PROBE_PAD14_PROBESEL_Msk (0x30000000UL)      /*!< TT_SCU PAD_PROBE: PAD14_PROBESEL (Bitfield-Mask: 0x03) */
#define TT_SCU_PAD_PROBE_PAD15_PROBESEL_Pos (30UL)              /*!< TT_SCU PAD_PROBE: PAD15_PROBESEL (Bit 30)         */
#define TT_SCU_PAD_PROBE_PAD15_PROBESEL_Msk (0xc0000000UL)      /*!< TT_SCU PAD_PROBE: PAD15_PROBESEL (Bitfield-Mask: 0x03) */
/* ====================================================  PROBE_SEL_REG0  ===================================================== */
#define TT_SCU_PROBE_SEL_REG0_PROBE_CAN_SEL_Pos (0UL)           /*!< TT_SCU PROBE_SEL_REG0: PROBE_CAN_SEL (Bit 0)      */
#define TT_SCU_PROBE_SEL_REG0_PROBE_CAN_SEL_Msk (0xfUL)         /*!< TT_SCU PROBE_SEL_REG0: PROBE_CAN_SEL (Bitfield-Mask: 0x0f) */
#define TT_SCU_PROBE_SEL_REG0_CAN_PROBE_EN_Pos (4UL)            /*!< TT_SCU PROBE_SEL_REG0: CAN_PROBE_EN (Bit 4)       */
#define TT_SCU_PROBE_SEL_REG0_CAN_PROBE_EN_Msk (0x10UL)         /*!< TT_SCU PROBE_SEL_REG0: CAN_PROBE_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PROBE_SEL_REG0_FTM_PROBE_SEL_Pos (8UL)           /*!< TT_SCU PROBE_SEL_REG0: FTM_PROBE_SEL (Bit 8)      */
#define TT_SCU_PROBE_SEL_REG0_FTM_PROBE_SEL_Msk (0x700UL)       /*!< TT_SCU PROBE_SEL_REG0: FTM_PROBE_SEL (Bitfield-Mask: 0x07) */
#define TT_SCU_PROBE_SEL_REG0_FTM_PROBE_EN_Pos (11UL)           /*!< TT_SCU PROBE_SEL_REG0: FTM_PROBE_EN (Bit 11)      */
#define TT_SCU_PROBE_SEL_REG0_FTM_PROBE_EN_Msk (0x800UL)        /*!< TT_SCU PROBE_SEL_REG0: FTM_PROBE_EN (Bitfield-Mask: 0x01) */
#define TT_SCU_PROBE_SEL_REG0_X2SRAM_PROBE_SEL_Pos (12UL)       /*!< TT_SCU PROBE_SEL_REG0: X2SRAM_PROBE_SEL (Bit 12)  */
#define TT_SCU_PROBE_SEL_REG0_X2SRAM_PROBE_SEL_Msk (0x7000UL)   /*!< TT_SCU PROBE_SEL_REG0: X2SRAM_PROBE_SEL (Bitfield-Mask: 0x07) */
#define TT_SCU_PROBE_SEL_REG0_X2SRAM_PROBE_EN_Pos (15UL)        /*!< TT_SCU PROBE_SEL_REG0: X2SRAM_PROBE_EN (Bit 15)   */
#define TT_SCU_PROBE_SEL_REG0_X2SRAM_PROBE_EN_Msk (0x8000UL)    /*!< TT_SCU PROBE_SEL_REG0: X2SRAM_PROBE_EN (Bitfield-Mask: 0x01) */
/* ====================================================  PROBE_SEL_REG1  ===================================================== */
#define TT_SCU_PROBE_SEL_REG1_FIELD_Pos (0UL)                   /*!< TT_SCU PROBE_SEL_REG1: FIELD (Bit 0)              */
#define TT_SCU_PROBE_SEL_REG1_FIELD_Msk (0xffffffffUL)          /*!< TT_SCU PROBE_SEL_REG1: FIELD (Bitfield-Mask: 0xffffffff) */
/* =======================================================  WDTSCON0  ======================================================== */
#define TT_SCU_WDTSCON0_ENDINIT_Pos   (0UL)                     /*!< TT_SCU WDTSCON0: ENDINIT (Bit 0)                  */
#define TT_SCU_WDTSCON0_ENDINIT_Msk   (0x1UL)                   /*!< TT_SCU WDTSCON0: ENDINIT (Bitfield-Mask: 0x01)    */
#define TT_SCU_WDTSCON0_LCK_Pos       (1UL)                     /*!< TT_SCU WDTSCON0: LCK (Bit 1)                      */
#define TT_SCU_WDTSCON0_LCK_Msk       (0x2UL)                   /*!< TT_SCU WDTSCON0: LCK (Bitfield-Mask: 0x01)        */
#define TT_SCU_WDTSCON0_PW_Pos        (2UL)                     /*!< TT_SCU WDTSCON0: PW (Bit 2)                       */
#define TT_SCU_WDTSCON0_PW_Msk        (0xfffcUL)                /*!< TT_SCU WDTSCON0: PW (Bitfield-Mask: 0x3fff)       */
#define TT_SCU_WDTSCON0_REL_Pos       (16UL)                    /*!< TT_SCU WDTSCON0: REL (Bit 16)                     */
#define TT_SCU_WDTSCON0_REL_Msk       (0xffff0000UL)            /*!< TT_SCU WDTSCON0: REL (Bitfield-Mask: 0xffff)      */
/* =======================================================  WDTSCON1  ======================================================== */
#define TT_SCU_WDTSCON1_IR0_Pos       (2UL)                     /*!< TT_SCU WDTSCON1: IR0 (Bit 2)                      */
#define TT_SCU_WDTSCON1_IR0_Msk       (0x4UL)                   /*!< TT_SCU WDTSCON1: IR0 (Bitfield-Mask: 0x01)        */
#define TT_SCU_WDTSCON1_DR_Pos        (3UL)                     /*!< TT_SCU WDTSCON1: DR (Bit 3)                       */
#define TT_SCU_WDTSCON1_DR_Msk        (0x8UL)                   /*!< TT_SCU WDTSCON1: DR (Bitfield-Mask: 0x01)         */
#define TT_SCU_WDTSCON1_IR1_Pos       (5UL)                     /*!< TT_SCU WDTSCON1: IR1 (Bit 5)                      */
#define TT_SCU_WDTSCON1_IR1_Msk       (0x20UL)                  /*!< TT_SCU WDTSCON1: IR1 (Bitfield-Mask: 0x01)        */
#define TT_SCU_WDTSCON1_IREN_Pos      (6UL)                   /*!< TT_SCU WDTSCON1: IREN (Bit 6)                       */
#define TT_SCU_WDTSCON1_IREN_Msk      (0x40UL)                /*!< TT_SCU WDTSCON1: IREN (Bitfield-Mask: 0x01)         */
#define TT_SCU_WDTSCON1_PAR_Pos       (7UL)                     /*!< TT_SCU WDTSCON1: PAR (Bit 7)                      */
#define TT_SCU_WDTSCON1_PAR_Msk       (0x80UL)                  /*!< TT_SCU WDTSCON1: PAR (Bitfield-Mask: 0x01)        */
#define TT_SCU_WDTSCON1_TCR_Pos       (8UL)                     /*!< TT_SCU WDTSCON1: TCR (Bit 8)                      */
#define TT_SCU_WDTSCON1_TCR_Msk       (0x100UL)                 /*!< TT_SCU WDTSCON1: TCR (Bitfield-Mask: 0x01)        */
#define TT_SCU_WDTSCON1_TCTR_Pos      (9UL)                     /*!< TT_SCU WDTSCON1: TCTR (Bit 9)                     */
#define TT_SCU_WDTSCON1_TCTR_Msk      (0xfe00UL)                /*!< TT_SCU WDTSCON1: TCTR (Bitfield-Mask: 0x7f)       */
/* =========================================================  WDTSR  ========================================================= */
#define TT_SCU_WDTSR_AE_Pos           (0UL)                     /*!< TT_SCU WDTSR: AE (Bit 0)                          */
#define TT_SCU_WDTSR_AE_Msk           (0x1UL)                   /*!< TT_SCU WDTSR: AE (Bitfield-Mask: 0x01)            */
#define TT_SCU_WDTSR_OE_Pos           (1UL)                     /*!< TT_SCU WDTSR: OE (Bit 1)                          */
#define TT_SCU_WDTSR_OE_Msk           (0x2UL)                   /*!< TT_SCU WDTSR: OE (Bitfield-Mask: 0x01)            */
#define TT_SCU_WDTSR_IS0_Pos          (2UL)                     /*!< TT_SCU WDTSR: IS0 (Bit 2)                         */
#define TT_SCU_WDTSR_IS0_Msk          (0x4UL)                   /*!< TT_SCU WDTSR: IS0 (Bitfield-Mask: 0x01)           */
#define TT_SCU_WDTSR_DS_Pos           (3UL)                     /*!< TT_SCU WDTSR: DS (Bit 3)                          */
#define TT_SCU_WDTSR_DS_Msk           (0x8UL)                   /*!< TT_SCU WDTSR: DS (Bitfield-Mask: 0x01)            */
#define TT_SCU_WDTSR_TO_Pos           (4UL)                     /*!< TT_SCU WDTSR: TO (Bit 4)                          */
#define TT_SCU_WDTSR_TO_Msk           (0x10UL)                  /*!< TT_SCU WDTSR: TO (Bitfield-Mask: 0x01)            */
#define TT_SCU_WDTSR_IS1_Pos          (5UL)                     /*!< TT_SCU WDTSR: IS1 (Bit 5)                         */
#define TT_SCU_WDTSR_IS1_Msk          (0x20UL)                  /*!< TT_SCU WDTSR: IS1 (Bitfield-Mask: 0x01)           */
#define TT_SCU_WDTSR_IRS_Pos          (6UL)                    /*!< TT_SCU WDTSR: IRS (Bit 6)                          */
#define TT_SCU_WDTSR_IRS_Msk          (0x40UL)                 /*!< TT_SCU WDTSR: IRS (Bitfield-Mask: 0x01)            */
#define TT_SCU_WDTSR_PAS_Pos          (7UL)                     /*!< TT_SCU WDTSR: PAS (Bit 7)                         */
#define TT_SCU_WDTSR_PAS_Msk          (0x80UL)                  /*!< TT_SCU WDTSR: PAS (Bitfield-Mask: 0x01)           */
#define TT_SCU_WDTSR_TCS_Pos          (8UL)                     /*!< TT_SCU WDTSR: TCS (Bit 8)                         */
#define TT_SCU_WDTSR_TCS_Msk          (0x100UL)                 /*!< TT_SCU WDTSR: TCS (Bitfield-Mask: 0x01)           */
#define TT_SCU_WDTSR_TCT_Pos          (9UL)                     /*!< TT_SCU WDTSR: TCT (Bit 9)                         */
#define TT_SCU_WDTSR_TCT_Msk          (0xfe00UL)                /*!< TT_SCU WDTSR: TCT (Bitfield-Mask: 0x7f)           */
#define TT_SCU_WDTSR_TIM_Pos          (16UL)                    /*!< TT_SCU WDTSR: TIM (Bit 16)                        */
#define TT_SCU_WDTSR_TIM_Msk          (0xffff0000UL)            /*!< TT_SCU WDTSR: TIM (Bitfield-Mask: 0xffff)         */
/* ========================================================  SEICON0  ======================================================== */
#define TT_SCU_SEICON0_ENDINIT_Pos    (1UL)                     /*!< TT_SCU SEICON0: ENDINIT (Bit 1)                   */
#define TT_SCU_SEICON0_ENDINIT_Msk    (0x2UL)                   /*!< TT_SCU SEICON0: ENDINIT (Bitfield-Mask: 0x01)     */
#define TT_SCU_SEICON0_EPW_Pos        (2UL)                     /*!< TT_SCU SEICON0: EPW (Bit 2)                       */
#define TT_SCU_SEICON0_EPW_Msk        (0xfffcUL)                /*!< TT_SCU SEICON0: EPW (Bitfield-Mask: 0x3fff)       */
#define TT_SCU_SEICON0_REL_Pos        (16UL)                    /*!< TT_SCU SEICON0: REL (Bit 16)                      */
#define TT_SCU_SEICON0_REL_Msk        (0xffff0000UL)            /*!< TT_SCU SEICON0: REL (Bitfield-Mask: 0xffff)       */
/* ========================================================  SEICON1  ======================================================== */
#define TT_SCU_SEICON1_IR0_Pos        (2UL)                     /*!< TT_SCU SEICON1: IR0 (Bit 2)                       */
#define TT_SCU_SEICON1_IR0_Msk        (0x4UL)                   /*!< TT_SCU SEICON1: IR0 (Bitfield-Mask: 0x01)         */
#define TT_SCU_SEICON1_DR_Pos         (3UL)                     /*!< TT_SCU SEICON1: DR (Bit 3)                        */
#define TT_SCU_SEICON1_DR_Msk         (0x8UL)                   /*!< TT_SCU SEICON1: DR (Bitfield-Mask: 0x01)          */
#define TT_SCU_SEICON1_IR1_Pos        (5UL)                     /*!< TT_SCU SEICON1: IR1 (Bit 5)                       */
#define TT_SCU_SEICON1_IR1_Msk        (0x20UL)                  /*!< TT_SCU SEICON1: IR1 (Bitfield-Mask: 0x01)         */
/* =========================================================  SEISR  ========================================================= */
#define TT_SCU_SEISR_AE_Pos           (0UL)                     /*!< TT_SCU SEISR: AE (Bit 0)                          */
#define TT_SCU_SEISR_AE_Msk           (0x1UL)                   /*!< TT_SCU SEISR: AE (Bitfield-Mask: 0x01)            */
#define TT_SCU_SEISR_OE_Pos           (1UL)                     /*!< TT_SCU SEISR: OE (Bit 1)                          */
#define TT_SCU_SEISR_OE_Msk           (0x2UL)                   /*!< TT_SCU SEISR: OE (Bitfield-Mask: 0x01)            */
#define TT_SCU_SEISR_IS0_Pos          (2UL)                     /*!< TT_SCU SEISR: IS0 (Bit 2)                         */
#define TT_SCU_SEISR_IS0_Msk          (0x4UL)                   /*!< TT_SCU SEISR: IS0 (Bitfield-Mask: 0x01)           */
#define TT_SCU_SEISR_DS_Pos           (3UL)                     /*!< TT_SCU SEISR: DS (Bit 3)                          */
#define TT_SCU_SEISR_DS_Msk           (0x8UL)                   /*!< TT_SCU SEISR: DS (Bitfield-Mask: 0x01)            */
#define TT_SCU_SEISR_TO_Pos           (4UL)                     /*!< TT_SCU SEISR: TO (Bit 4)                          */
#define TT_SCU_SEISR_TO_Msk           (0x10UL)                  /*!< TT_SCU SEISR: TO (Bitfield-Mask: 0x01)            */
#define TT_SCU_SEISR_IS1_Pos          (5UL)                     /*!< TT_SCU SEISR: IS1 (Bit 5)                         */
#define TT_SCU_SEISR_IS1_Msk          (0x20UL)                  /*!< TT_SCU SEISR: IS1 (Bitfield-Mask: 0x01)           */
#define TT_SCU_SEISR_TIM_Pos          (16UL)                    /*!< TT_SCU SEISR: TIM (Bit 16)                        */
#define TT_SCU_SEISR_TIM_Msk          (0xffff0000UL)            /*!< TT_SCU SEISR: TIM (Bitfield-Mask: 0xffff)         */
/* ========================================================  RMU_CR  ========================================================= */
#define TT_SCU_RMU_CR_ENABLE_Pos      (0UL)                     /*!< TT_SCU RMU_CR: ENABLE (Bit 0)                     */
#define TT_SCU_RMU_CR_ENABLE_Msk      (0x1UL)                   /*!< TT_SCU RMU_CR: ENABLE (Bitfield-Mask: 0x01)       */
/* ========================================================  CHIP_ID  ======================================================== */
#define TT_SCU_CHIP_ID_ID_Pos         (0UL)                     /*!< TT_SCU CHIP_ID: ID (Bit 0)                        */
#define TT_SCU_CHIP_ID_ID_Msk         (0xffffffffUL)            /*!< TT_SCU CHIP_ID: ID (Bitfield-Mask: 0xffffffff)    */



/* ==========================================  TT_SCU BPIN_CR BOOT_SEL [0..1]  =========================================== */
typedef enum {                                  /*!< TT_SCU_BPIN_CR_BOOT_SEL                                               */
  TT_SCU_BPIN_CR_BOOT_SEL_BOOT_SEL_FLASH = 1,/*!< BOOT_SEL_FLASH : Boot Select 0.                                          */
  TT_SCU_BPIN_CR_BOOT_SEL_BOOT_SEL_QSPI1 = 2,/*!< BOOT_SEL_QSPI1 : Boot Select 2.                                          */
  TT_SCU_BPIN_CR_BOOT_SEL_BOOT_SEL_ITCM = 3/*!< BOOT_SEL_ITCM : Boot Select 3.                                            */
} TT_SCU_BPIN_CR_BOOT_SEL_Enum;

/* ========================================================  ECO_CTL  ======================================================== */
/* ============================================  TT_SCU ECO_CTL S0_S1 [1..2]  ============================================ */
typedef enum {                                  /*!< TT_SCU_ECO_CTL_S0_S1                                                  */
  TT_SCU_ECO_CTL_S0_S1_1MHZ_12MHZ  = 0,     /*!< 1MHZ_12MHZ : 1MHz to 12MHz.                                               */
  TT_SCU_ECO_CTL_S0_S1_12MHZ_24MHZ = 1,     /*!< 12MHZ_24MHZ : 12MHz to 24MHz.                                             */
  TT_SCU_ECO_CTL_S0_S1_24MHZ_42MHZ = 2,     /*!< 24MHZ_42MHZ : 24MHz to 42MHz.                                             */
  TT_SCU_ECO_CTL_S0_S1_42MHZ_66MHZ = 3     /*!< 42MHZ_66MHZ : 42MHz to 66MHz.                                             */
} TT_SCU_ECO_CTL_S0_S1_Enum;

/* ============================================  TT_SCU ECO_CTL EB_B [3..4]  ============================================= */
typedef enum {                                  /*!< TT_SCU_ECO_CTL_EB_B                                                   */
  TT_SCU_ECO_CTL_EB_B_POWER_DOWN   = 0,     /*!< POWER_DOWN : Power Down.                                                  */
  TT_SCU_ECO_CTL_EB_B_PARALLEL     = 1,     /*!< PARALLEL : Parallel Mode.                                                 */
  TT_SCU_ECO_CTL_EB_B_OSC          = 2,     /*!< OSC : OSC Mode.                                                           */
  TT_SCU_ECO_CTL_EB_B_THREE_STAT   = 3     /*!< THREE_STAT : Three Stat Mode.                                             */
} TT_SCU_ECO_CTL_EB_B_Enum;

/* =======================================================  MPLL_CTL  ======================================================== */
/* =======================================================  EPLL_CTL  ======================================================== */
/* ======================================================  CLKDIV_CTL0  ====================================================== */
/* ========================================  TT_SCU CLKDIV_CTL0 DIV_PERI0 [4..4]  ======================================== */
typedef enum {                                  /*!< TT_SCU_CLKDIV_CTL0_DIV_PERI0                                          */
  TT_SCU_CLKDIV_CTL0_DIV_PERI0_NO_DIVISION = 0,/*!< NO_DIVISION : No Frequence Division.                                   */
  TT_SCU_CLKDIV_CTL0_DIV_PERI0_2_DIVISION = 1/*!< 2_DIVISION : 2 Frequence Division.                                      */
} TT_SCU_CLKDIV_CTL0_DIV_PERI0_Enum;

/* ========================================  TT_SCU CLKDIV_CTL0 DIV_PERI1 [5..5]  ======================================== */
typedef enum {                                  /*!< TT_SCU_CLKDIV_CTL0_DIV_PERI1                                          */
  TT_SCU_CLKDIV_CTL0_DIV_PERI1_NO_DIVISION = 0,/*!< NO_DIVISION : No Frequence Division.                                   */
  TT_SCU_CLKDIV_CTL0_DIV_PERI1_2_DIVISION = 1/*!< 2_DIVISION : 2 Frequence Division.                                      */
} TT_SCU_CLKDIV_CTL0_DIV_PERI1_Enum;

/* ========================================  TT_SCU CLKDIV_CTL0 DIV_PERI2 [6..6]  ======================================== */
typedef enum {                                  /*!< TT_SCU_CLKDIV_CTL0_DIV_PERI2                                          */
  TT_SCU_CLKDIV_CTL0_DIV_PERI2_NO_DIVISION = 0,/*!< NO_DIVISION : No Frequence Division.                                   */
  TT_SCU_CLKDIV_CTL0_DIV_PERI2_2_DIVISION = 1/*!< 2_DIVISION : 2 Frequence Division.                                      */
} TT_SCU_CLKDIV_CTL0_DIV_PERI2_Enum;

/* ========================================  TT_SCU CLKDIV_CTL0 DIV_PERI3 [7..7]  ======================================== */
typedef enum {                                  /*!< TT_SCU_CLKDIV_CTL0_DIV_PERI3                                          */
  TT_SCU_CLKDIV_CTL0_DIV_PERI3_NO_DIVISION = 0,/*!< NO_DIVISION : No Frequence Division.                                   */
  TT_SCU_CLKDIV_CTL0_DIV_PERI3_2_DIVISION = 1/*!< 2_DIVISION : 2 Frequence Division.                                      */
} TT_SCU_CLKDIV_CTL0_DIV_PERI3_Enum;

/* ======================================================  CLKDIV_CTL1  ====================================================== */
/* ======================================================  CLKDIV_CTL2  ====================================================== */
/* ======================================================  CLKDIV_CTL3  ====================================================== */
/* =======================================================  CLK_STOP0  ======================================================= */
/* =======================================================  CLK_STOP1  ======================================================= */
/* =======================================================  CLK_STOP2  ======================================================= */
/* ======================================================  CLK_SLEEP0  ======================================================= */
/* ======================================================  CLK_SLEEP1  ======================================================= */
/* ======================================================  CLK_SLEEP2  ======================================================= */
/* ========================================================  LP_CTL  ========================================================= */
/* =====================================================  PLL_LOCK_TIME  ===================================================== */
/* =======================================================  CLK_RAND  ======================================================== */
/* =======================================================  LFSR_SEED  ======================================================= */
/* =======================================================  PERI_STOP  ======================================================= */
/* =====================================================  SCU_CFG_LOCK  ====================================================== */
/* ======================================================  BIST_STATE  ======================================================= */
/* =======================================================  PROBE_SEL  ======================================================= */
/* ======================================================  FTM_CLB_CFG  ====================================================== */
/* =====================================================  QSPI_MISC_CFG  ===================================================== */
/* =====================================================  EMAC_MISC_CFG  ===================================================== */
/* =====================================  TT_SCU EMAC_MISC_CFG PHY_INTERFACE [0..2]  ===================================== */
typedef enum {                                  /*!< TT_SCU_EMAC_MISC_CFG_PHY_INTERFACE                                    */
  TT_SCU_EMAC_MISC_CFG_PHY_INTERFACE_GMII_MII = 0,/*!< GMII_MII : GMII or MII                                              */
  TT_SCU_EMAC_MISC_CFG_PHY_INTERFACE_RGMII = 1,/*!< RGMII : RGMII                                                          */
  TT_SCU_EMAC_MISC_CFG_PHY_INTERFACE_RMII = 4/*!< RMII : RMII                                                             */
} TT_SCU_EMAC_MISC_CFG_PHY_INTERFACE_Enum;

#ifdef __cplusplus
}
#endif

#endif /* A8V2_SCU_H */
