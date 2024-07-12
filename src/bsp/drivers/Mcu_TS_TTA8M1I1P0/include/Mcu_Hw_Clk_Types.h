/*******************************************************************************
**                                                                            **
** Copyright (C) ThinkTech Technologies (2023)                                **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to ThinkTech      **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Mcu_Hw_Clk_Types.h                                         **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Mcu Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef MCU_HW_CLK_TYPES_H
#define MCU_HW_CLK_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_CLK_TYPES_VENDOR_ID_H                     1541
#define MCU_HW_CLK_TYPES_MODULE_ID_H                     101
#define MCU_HW_CLK_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_CLK_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_CLK_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_CLK_TYPES_SW_MAJOR_VERSION_H              1
#define MCU_HW_CLK_TYPES_SW_MINOR_VERSION_H              1
#define MCU_HW_CLK_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Clk_Types.h and Mcu_Cfg.h file version check */
#if (MCU_HW_CLK_TYPES_VENDOR_ID_H != MCU_CFG_VENDOR_ID_H)
    #error "Mcu_Hw_Clk_Types.h and Mcu_Cfg.h have different vendor id"
#endif
#if (MCU_HW_CLK_TYPES_MODULE_ID_H != MCU_CFG_MODULE_ID_H)
    #error "Mcu_Hw_Clk_Types.h and Mcu_Cfg.h have different module id"
#endif
#if ((MCU_HW_CLK_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CLK_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Clk_Types.h and Mcu_Cfg.h are different"
#endif
#if ((MCU_HW_CLK_TYPES_SW_MAJOR_VERSION_H != MCU_CFG_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_TYPES_SW_MINOR_VERSION_H != MCU_CFG_SW_MINOR_VERSION_H) || \
     (MCU_HW_CLK_TYPES_SW_PATCH_VERSION_H != MCU_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Clk_Types.h and Mcu_Cfg.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Can pe clock assert */
#define MCU_CLK_PERIPHNAME_TYPE_ASSERT(type)    (((type) <= MCU_CLOCK_CAN_PE))

/* Control clock type assert */
#define MCU_CLK_CONTROL_TYPE_ASSERT(type)       (((type) < TT_SCU_CLK_CONTROL_END))

/* sleep clock type assert */
#define MCU_CLK_SLEEP_TYPE_ASSERT(type)         ((((type) <= TT_SCU_CLK_SLEEP_SSP6)) || \
                                                (((type) >= TT_SCU_CLK_SLEEP_SENT7) && ((type) <= TT_SCU_CLK_SLEEP_TRNG)) || \
                                                (((type) >= TT_SCU_CLK_SLEEP_STCU) && ((type) <= TT_SCU_CLK_SLEEP_PMU_APB)) || \
                                                (((type) >= TT_SCU_CLK_SLEEP_SCU) && ((type) < TT_SCU_CLK_SLEEP_END)) || \
                                                ((type) == TT_SCU_CLK_SLEEP_EIM))

/* peristop type assert */
#define MCU_CLK_PERISTOP_TYPE_ASSERT(type)      (((type) < TT_SCU_PERI_STOP_END))

#define TT_SCU_LOCAL_RESET_OFFSET               (0x4U)       /* LOCAL_RESET base addresses offset */
#define TT_SCU_CLK_STOP_OFFSET                  (0x120U)     /* CLK_STOP base addresses offset */
#define TT_SCU_CLK_SLEEP_OFFSET                 (0x12CU)     /* CLK_SLEEP base addresses offset */
#define TT_SCU_PERI_STOP_OFFSET                 (0x148U)     /* PERI_STOP base addresses offset */

#define TT_SCU_CLK_CIPHER_DIV_MAX               (0x10U)       /* scu clock cipher divsion maximun */
#define TT_SCU_CLK_DIV_CTL1_MAX                 (0x8U)        /* scu clock divsion ctlrol maximun */
#define TT_SCU_CLK_DIV_CTL1_EMAC_TXRX_MAX       (0x2U)        /* scu  Ethernet RxTx clock divsion  maximun */
#define TT_SCU_CLK_DIV_CTL2_FRACTION_MAX        (0x1000U)     /* scu clock fractional divsion maximun */
#define TT_SCU_CLK_DIV_CTL2_INT_MAX             (0x10U)       /* scu clock integer divsion maximun */

/* Clock Defines */
#define MCU_OSC_IHO_DEFAULT                     (48000000UL)  /* iho clock default frequency */
#define MCU_OSC_ECO_DEFAULT                     (40000000UL)  /* eco clock default frequency */
#define MCU_CORE_CLK_MAX                        (240000000UL) /* core clock maximun frequency */
#define MCU_BUS_CLK_MAX                         (120000000UL) /* bus clock maximun frequency */
/******************************************************************************
*                            Enums
*******************************************************************************/
/* Pll Lock Status */
typedef enum
{
    MCU_CLK_PLL_UNLOCKED,
    MCU_CLK_PLL_LOCKED
}Mcu_Hw_ClkPLLStatus;

/* Pll Type */
typedef enum
{
    MCU_MPLL_TYPE,
    MCU_EPLL_TYPE
}Mcu_Hw_PllType;

/* PeripheralName - the dest Peripheral in Mcu_PeriphNameType*/
typedef enum
{
    /* system */
    MCU_CLOCK_SYSTEM    ,
    MCU_CLOCK_BUS       ,
    MCU_CLOCK_MPLL      ,
    MCU_CLOCK_EPLL      ,

    /* APB0 */
    MCU_CLOCK_APB0      ,
    MCU_CLOCK_SCU       ,
    MCU_CLOCK_DBG       ,
    MCU_CLOCK_PPU       ,

    /* APB1 */
    MCU_CLOCK_APB1      ,
    MCU_CLOCK_PMU       ,
    MCU_CLOCK_SMPU      ,
    MCU_CLOCK_TIMER     ,
    MCU_CLOCK_WDG       ,
    MCU_CLOCK_CRC       ,
    MCU_CLOCK_UART0     ,
    MCU_CLOCK_UART1     ,
    MCU_CLOCK_I2C0      ,
    MCU_CLOCK_I2C1      ,
    MCU_CLOCK_SENT4     ,
    MCU_CLOCK_SENT5     ,
    MCU_CLOCK_FTM4      ,
    MCU_CLOCK_FTM5      ,
    MCU_CLOCK_IOM       ,
    MCU_CLOCK_SENT2     ,
    MCU_CLOCK_SENT3     ,

    /* APB2 */
    MCU_CLOCK_APB2      ,
    MCU_CLOCK_CAN0      ,
    MCU_CLOCK_CAN1      ,
    MCU_CLOCK_CAN2      ,
    MCU_CLOCK_CAN3      ,
    MCU_CLOCK_I3C0      ,
    MCU_CLOCK_GPIO0     ,
    MCU_CLOCK_GPIO1     ,
    MCU_CLOCK_GPIO2     ,
    MCU_CLOCK_FTM2      ,
    MCU_CLOCK_FTM3      ,
    MCU_CLOCK_ADCSENSOR ,
    MCU_CLOCK_UART2     ,
    MCU_CLOCK_UART3     ,
    MCU_CLOCK_SMU       ,
    MCU_CLOCK_GTMREG    ,
    MCU_CLOCK_INTM      ,

    /* APB3 */
    MCU_CLOCK_APB3      ,
    MCU_CLOCK_CAN4      ,
    MCU_CLOCK_CAN5      ,
    MCU_CLOCK_CAN6      ,
    MCU_CLOCK_CAN7      ,
    MCU_CLOCK_FTM0      ,
    MCU_CLOCK_FTM1      ,
    MCU_CLOCK_GPIO3     ,
    MCU_CLOCK_GPIO4     ,
    MCU_CLOCK_SENT0     ,
    MCU_CLOCK_SENT1     ,
    MCU_CLOCK_TRIGMUX   ,
    MCU_CLOCK_I2S0      ,
    MCU_CLOCK_SENT6     ,
    MCU_CLOCK_SENT7     ,
    MCU_CLOCK_STCU      ,

    /* APB4 */
    MCU_CLOCK_APB4      ,
    MCU_CLOCK_LIN0      ,
    MCU_CLOCK_LIN1      ,
    MCU_CLOCK_LIN2      ,
    MCU_CLOCK_LIN3      ,
    MCU_CLOCK_LIN4      ,
    MCU_CLOCK_LIN5      ,
    MCU_CLOCK_LIN6      ,
    MCU_CLOCK_LIN7      ,
    MCU_CLOCK_EIM       ,

    /* APB5 */
    MCU_CLOCK_APB5      ,
    MCU_CLOCK_LIN8      ,
    MCU_CLOCK_LIN9      ,
    MCU_CLOCK_LIN10     ,
    MCU_CLOCK_LIN11     ,
    MCU_CLOCK_LIN12     ,
    MCU_CLOCK_LIN13     ,
    MCU_CLOCK_LIN14     ,
    MCU_CLOCK_LIN15     ,

    /* AHB0 */
    MCU_CLOCK_AHB0      ,
    MCU_CLOCK_SPI0      ,
    MCU_CLOCK_SPI2      ,
    MCU_CLOCK_DMAC0     ,
    MCU_CLOCK_DMAC1     ,
    MCU_CLOCK_DMAC2     ,
    MCU_CLOCK_DMAC3     ,
    MCU_CLOCK_ADC       ,
    MCU_CLOCK_SPI4      ,
    MCU_CLOCK_DFCU      ,
    MCU_CLOCK_SPI6      ,

    /* AHB1 */
    MCU_CLOCK_AHB1      ,
    MCU_CLOCK_SPI1      ,
    MCU_CLOCK_SPI3      ,
    MCU_CLOCK_FCU       ,
    MCU_CLOCK_EMAC      ,
    MCU_CLOCK_SPI5      ,
    MCU_CLOCK_PDB0      ,
    MCU_CLOCK_PDB1      ,
    MCU_CLOCK_SPI7      ,

    /* AHB4 */
    MCU_CLOCK_AHB4      ,
    MCU_CLOCK_GTMAXIS   ,

    /* Can PE */
    MCU_CLOCK_CAN_PE
}Mcu_Hw_PeriphNameType;

/* Cryptor Clock Rand Level */
typedef enum
{
    MCU_CRYPTO_CLK_RAND_4_1,
    MCU_CRYPTO_CLK_RAND_8_1,
    MCU_CRYPTO_CLK_RAND_16_1,
    MCU_CRYPTO_CLK_RAND_32_1
}Mcu_Hw_CryptoClkRandType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* Variable to store Peripheral clock value */
typedef uint32 Mcu_PeripheralClockValType;

/* Epll Clock Config */
typedef struct
{
    uint32 EpllClk;                                        /* Epll Clock */
    uint32 EmacPtpRefClkDiv;                               /* Epll PTP Reference clock frequency division*/
    uint32 EmacRmiiRefClkDiv;                              /* Epll Rmii Reference clock frequency division*/
    uint32 EmacRxTxClkDiv;                                 /* Epll RxTx Reference clock frequency division*/
} Mcu_Hw_EpllClockConfigType;

/* Clock Config */
typedef struct
{
    boolean                BusClkHalfCoreEnable;           /* Bus clock half Core clock enable */
    boolean                APB0ClkHalfBusEnable;           /* APB0 clock half bus clock enable */
    boolean                APB1ClkHalfBusEnable;           /* APB1 clock half bus clock enable */
    boolean                APB2ClkHalfBusEnable;           /* APB1 clock half bus clock enable */
    boolean                APB3ClkHalfBusEnable;           /* APB3 clock half bus clock enable */
    boolean                CanPEUserPLLEnable;             /* Can pe clock used Pll enable */
    boolean                Sm4ClkRandEn;                   /* Sm4 clock rand enable */
    boolean                SkaClkRandEn;                   /* Ska clock rand enable */
    boolean                HashClkRandEn;                  /* Hash clock rand enable */
    uint32                 IhoClk;                         /* Inner high clock, default 48M */
    uint32                 EcoClk;                         /* External clock, default 40M */
    uint32                 EcoDivLP;                       /* Eco div for lower power */
    uint32                 CoreClk;                        /* Core clock */
    uint32                 CanPeClk;                       /* Can pe clock */
    uint32                 Sm4ClkDiv;                      /* Sm4 clock division  */
    Mcu_Hw_CryptoClkRandType  Sm4ClkRand;                  /* Sm4 clock rand  */
    uint32                 SkaClkDiv;                      /* Ska clock division  */
    Mcu_Hw_CryptoClkRandType  SkaClkRand;                  /* Ska clock rand  */
    uint32                 HashClkDiv;                     /* Hash clock division */
    Mcu_Hw_CryptoClkRandType  HashClkRand;                 /* Hash clock rand  */
    uint32                 I3c0ClkDiv;                     /* I3c0 clock division  */
    uint32                 I2s0SClkIntDiv;                 /* I2s0 Sclk integer division  */
    uint32                 I2s0SClkFracDiv;                /* I2s0 Sclk fractional division  */
    uint32                 I2s0MClkIntDiv;                 /* I2s0 Mclk integer division  */
    uint32                 I2s0MClkFracDiv;                /* I2s0 Mclk fractional division  */
    TT_CONST Mcu_Hw_EpllClockConfigType *EpllClockConfig;  /* Epll Clock Config */
} Mcu_Hw_ClockSettingConfigType;

/* Clock config information */
typedef struct
{
    uint32 ECOClk;                                         /* Eco Clock */
    uint32 IHOClk;                                         /* Iho Clock */
    uint32 CanPeClk;                                       /* Can Pe Clock */
    uint32 ClkDiv0;                                        /* Clock division config 0 */
    uint32 ClkDiv1;                                        /* Clock division config 1 */
    uint32 ClkDiv2;                                        /* Clock division config 2 */
}Mcu_Hw_ClkInfoType;
/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* MCU_HW_CLK_TYPES_H */
