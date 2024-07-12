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
**  FILENAME     : Dma_Hw_Types.h                                             **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : DMA Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef DMA_HW_TYPES_H
#define DMA_HW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dma_Drv_Cfg.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DMA_HW_TYPES_VENDOR_ID_H                    (1541U)
#define DMA_HW_TYPES_MODULE_ID_H                    (220U)
#define DMA_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H     (4U)
#define DMA_HW_TYPES_AR_RELEASE_MINOR_VERSION_H     (4U)
#define DMA_HW_TYPES_AR_RELEASE_PATCH_VERSION_H     (0U)
#define DMA_HW_TYPES_SW_MAJOR_VERSION_H             (1U)
#define DMA_HW_TYPES_SW_MINOR_VERSION_H             (1U)
#define DMA_HW_TYPES_SW_PATCH_VERSION_H             (0U)
/******************************************************************************
*                            File Version Checks
******************************************************************************/

/* Dma_Hw_Types.h Dma_Drv_Cfg.h file version check */
#if (DMA_DRV_CFG_VENDOR_ID_H != DMA_HW_TYPES_VENDOR_ID_H)
    #error "Dma_Drv_Cfg.h and Dma_Hw_Types.h have different vendor ids"
#endif

#if (DMA_DRV_CFG_MODULE_ID_H != DMA_HW_TYPES_MODULE_ID_H)
    #error "Dma_Drv_Cfg.h and Dma_Hw_Types.h have different module ids"
#endif

#if ((DMA_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H != DMA_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (DMA_DRV_CFG_AR_RELEASE_MINOR_VERSION_H != DMA_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (DMA_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != DMA_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Hw_Types.h and Dma_Drv_Cfg.h are different"
#endif

#if ((DMA_DRV_CFG_SW_MAJOR_VERSION_H != DMA_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (DMA_DRV_CFG_SW_MINOR_VERSION_H != DMA_HW_TYPES_SW_MINOR_VERSION_H) || \
     (DMA_DRV_CFG_SW_PATCH_VERSION_H != DMA_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Hw_Types.h and Dma_Drv_Cfg.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* DMA NORMAL MODE */
#define DMA_NORMAL_MODE                (0U)
/* DMA ONESHOT MODE */
#define DMA_ONESHOT_MODE               (1U) 
/* DMA CONTINUOUS MODE */
#define DMA_CONTINUOUS_MODE            (2U) 

/* Number of DMA PERIPHERALID*/
#define DMA_NUMBER_OF_PERIPHERALID (64U)

#if defined(DMA0_FLOW_CONTROL) && (DMA0_FLOW_CONTROL == STD_ON)
/* UART0 transmit */
#define   DMA0_PERISEL_UART0_TX    (0U)
/* UART0 receive  */
#define   DMA0_PERISEL_UART0_RX    (1U)
/* UART1 transmit */
#define   DMA0_PERISEL_UART1_TX    (2U)
/* UART1 receive  */
#define   DMA0_PERISEL_UART1_RX    (3U)
/* SSP0 transmit */
#define   DMA0_PERISEL_SSP0_TX     (4U)
/* SSP0 receive  */
#define   DMA0_PERISEL_SSP0_RX     (5U)
/* SSP1 transmit */
#define   DMA0_PERISEL_SSP1_TX     (6U)
/* SSP1 receive  */
#define   DMA0_PERISEL_SSP1_RX     (7U)
/* SSP2 transmit */
#define   DMA0_PERISEL_SSP2_TX     (8U)
/* SSP2 receive  */
#define   DMA0_PERISEL_SSP2_RX     (9U)
/* SSP3 transmit */
#define   DMA0_PERISEL_SSP3_TX     (10U)
/* SSP3 receive  */
#define   DMA0_PERISEL_SSP3_RX     (11U)
/* I2S0 transmit */
#define   DMA0_PERISEL_I2S0_TX     (12U)
/* I2S0 receive  */
#define   DMA0_PERISEL_I2S0_RX     (13U)
/* I2C0 transmit */
#define   DMA0_PERISEL_I2C0_TX     (14U)
/* I2C0 receive  */
#define   DMA0_PERISEL_I2C0_RX     (15U)
/* I3C0 transmit */
#define   DMA0_PERISEL_I3C0_TX     (16U)
/* I3C0 receive  */
#define   DMA0_PERISEL_I3C0_RX     (17U)
/* PDB0   */
#define   DMA0_PERISEL_PDB0        (18U)
/* PDB1   */
#define   DMA0_PERISEL_PDB1        (19U)
/* LIN0 transmit */
#define   DMA0_PERISEL_LIN0_TX     (20U)
/* LIN0 receive */
#define   DMA0_PERISEL_LIN0_RX     (21U)
/* LIN1 transmit */
#define   DMA0_PERISEL_LIN1_TX     (22U)
/* LIN1 receive */
#define   DMA0_PERISEL_LIN1_RX     (23U)
/* LIN2 transmit */
#define   DMA0_PERISEL_LIN2_TX     (24U)
/* LIN2 receive */
#define   DMA0_PERISEL_LIN2_RX     (25U)
/* LIN3 transmit */
#define   DMA0_PERISEL_LIN3_TX     (26U)
/* LIN3 receive */
#define   DMA0_PERISEL_LIN3_RX     (27U)
/* LIN4 transmit */
#define   DMA0_PERISEL_LIN4_TX     (28U)
/* LIN4 receive */
#define   DMA0_PERISEL_LIN4_RX     (29U)
/* LIN5 transmit */
#define   DMA0_PERISEL_LIN5_TX     (30U)
/* LIN5 receive */
#define   DMA0_PERISEL_LIN5_RX     (31U)
/* LIN6 transmit */
#define   DMA0_PERISEL_LIN6_TX     (32U)
/* LIN6 receive */
#define   DMA0_PERISEL_LIN6_RX     (33U)
/* LIN7 transmit */
#define   DMA0_PERISEL_LIN7_TX     (34U)
/* LIN7 receive */
#define   DMA0_PERISEL_LIN7_RX     (35U)
/* Sent0 receive*/
#define   DMA0_PERISEL_SENT0       (36U)
/* Sent1 receive*/
#define   DMA0_PERISEL_SENT1       (37U)
/* Sent2  receive*/
#define   DMA0_PERISEL_SENT2       (38U)
/* Sent3  receive*/
#define   DMA0_PERISEL_SENT3       (39U)
/* CAN0 receive */
#define   DMA0_PERISEL_CAN0        (40U)
/* CAN1 receive */
#define   DMA0_PERISEL_CAN1        (41U)
/* CAN2 receive */
#define   DMA0_PERISEL_CAN2        (42U)
/* CAN3 receive */
#define   DMA0_PERISEL_CAN3        (43U)
/* trgmux_trg_out_98  */
#define   DMA0_trgmux_trg_out_98   (44U)
/* trgmux_trg_out_99  */
#define   DMA0_trgmux_trg_out_99   (45U)
/* trgmux_trg_out_100 */
#define   DMA0_trgmux_trg_out_100  (46U)
/* trgmux_trg_out_101 */
#define   DMA0_trgmux_trg_out_101  (47U)
/* FTM0_0 */
#define   DMA0_PERISEL_FTM0_0      (48U)
/* FTM0_1 */
#define   DMA0_PERISEL_FTM0_1      (49U)
/* FTM0_2 */
#define   DMA0_PERISEL_FTM0_2      (50U)
/* FTM0_3 */
#define   DMA0_PERISEL_FTM0_3      (51U)
/* FTM0_4 */
#define   DMA0_PERISEL_FTM0_4      (52U)
/* FTM0_5 */
#define   DMA0_PERISEL_FTM0_5      (53U)
/* FTM0_6 */
#define   DMA0_PERISEL_FTM0_6      (54U)
/* FTM0_7 */
#define   DMA0_PERISEL_FTM0_7      (55U)
/* FTM1_0 */
#define   DMA0_PERISEL_FTM1_0      (56U)
/* FTM1_1 */
#define   DMA0_PERISEL_FTM1_1      (57U)
/* FTM1_2 */
#define   DMA0_PERISEL_FTM1_2      (58U)
/* FTM1_3 */
#define   DMA0_PERISEL_FTM1_3      (59U)
/* FTM1_4 */
#define   DMA0_PERISEL_FTM1_4      (60U)
/* FTM1_5 */
#define   DMA0_PERISEL_FTM1_5      (61U)
/* FTM1_6 */
#define   DMA0_PERISEL_FTM1_6      (62U)
/* FTM1_7 */
#define   DMA0_PERISEL_FTM1_7      (63U)
#endif

#if defined(DMA1_FLOW_CONTROL) && (DMA1_FLOW_CONTROL == STD_ON)
/* UART0 transmit */
#define   DMA1_PERISEL_UART0_TX    (0U)
/* UART0 receive  */
#define   DMA1_PERISEL_UART0_RX    (1U)
/* UART1 transmit */
#define   DMA1_PERISEL_UART1_TX    (2U)
/* UART1 receive  */
#define   DMA1_PERISEL_UART1_RX    (3U)
/* SSP0 transmit */
#define   DMA1_PERISEL_SSP0_TX     (4U)
/* SSP0 receive  */
#define   DMA1_PERISEL_SSP0_RX     (5U)
/* SSP1 transmit */
#define   DMA1_PERISEL_SSP1_TX     (6U)
/* SSP1 receive  */
#define   DMA1_PERISEL_SSP1_RX     (7U)
/* SSP2 transmit */
#define   DMA1_PERISEL_SSP2_TX     (8U)
/* SSP2 receive  */
#define   DMA1_PERISEL_SSP2_RX     (9U)
/* SSP3 transmit */
#define   DMA1_PERISEL_SSP3_TX     (10U)
/* SSP3 receive  */
#define   DMA1_PERISEL_SSP3_RX     (11U)
/* I2S0 transmit */
#define   DMA1_PERISEL_I2S0_TX     (12U)
/* I2S0 receive  */
#define   DMA1_PERISEL_I2S0_RX     (13U)
/* I2C0 transmit */
#define   DMA1_PERISEL_I2C0_TX     (14U)
/* I2C0 receive  */
#define   DMA1_PERISEL_I2C0_RX     (15U)
/* I3C0 transmit */
#define   DMA1_PERISEL_I3C0_TX     (16U)
/* I3C0 receive  */
#define   DMA1_PERISEL_I3C0_RX     (17U)
/* PDB0   */
#define   DMA1_PERISEL_PDB0        (18U)
/* PDB1   */
#define   DMA1_PERISEL_PDB1        (19U)
/* LIN0 transmit */
#define   DMA1_PERISEL_LIN0_TX     (20U)
/* LIN0 receive */
#define   DMA1_PERISEL_LIN0_RX     (21U)
/* LIN1 transmit */
#define   DMA1_PERISEL_LIN1_TX     (22U)
/* LIN1 receive */
#define   DMA1_PERISEL_LIN1_RX     (23U)
/* LIN2 transmit */
#define   DMA1_PERISEL_LIN2_TX     (24U)
/* LIN2 receive */
#define   DMA1_PERISEL_LIN2_RX     (25U)
/* LIN3 transmit */
#define   DMA1_PERISEL_LIN3_TX     (26U)
/* LIN3 receive */
#define   DMA1_PERISEL_LIN3_RX     (27U)
/* LIN4 transmit */
#define   DMA1_PERISEL_LIN4_TX     (28U)
/* LIN4 receive */
#define   DMA1_PERISEL_LIN4_RX     (29U)
/* LIN5 transmit */
#define   DMA1_PERISEL_LIN5_TX     (30U)
/* LIN5 receive */
#define   DMA1_PERISEL_LIN5_RX     (31U)
/* LIN6 transmit */
#define   DMA1_PERISEL_LIN6_TX     (32U)
/* LIN6 receive */
#define   DMA1_PERISEL_LIN6_RX     (33U)
/* LIN7 transmit */
#define   DMA1_PERISEL_LIN7_TX     (34U)
/* LIN7 receive */
#define   DMA1_PERISEL_LIN7_RX     (35U)
/* Sent0 receive*/
#define   DMA1_PERISEL_SENT0       (36U)
/* Sent1 receive*/
#define   DMA1_PERISEL_SENT1       (37U)
/* Sent2  receive*/
#define   DMA1_PERISEL_SENT2       (38U)
/* Sent3  receive*/
#define   DMA1_PERISEL_SENT3       (39U)
/* CAN0 receive */
#define   DMA1_PERISEL_CAN0        (40U)
/* CAN1 receive */
#define   DMA1_PERISEL_CAN1        (41U)
/* CAN2 receive */
#define   DMA1_PERISEL_CAN2        (42U)
/* CAN3 receive */
#define   DMA1_PERISEL_CAN3        (43U)
/* trgmux_trg_out_98  */
#define   DMA1_trgmux_trg_out_98   (44U)
/* trgmux_trg_out_99  */
#define   DMA1_trgmux_trg_out_99   (45U)
/* trgmux_trg_out_100 */
#define   DMA1_trgmux_trg_out_100  (46U)
/* trgmux_trg_out_101 */
#define   DMA1_trgmux_trg_out_101  (47U)
/* FTM0_0 */
#define   DMA1_PERISEL_FTM0_0      (48U)
/* FTM0_1 */
#define   DMA1_PERISEL_FTM0_1      (49U)
/* FTM0_2 */
#define   DMA1_PERISEL_FTM0_2      (50U)
/* FTM0_3 */
#define   DMA1_PERISEL_FTM0_3      (51U)
/* FTM0_4 */
#define   DMA1_PERISEL_FTM0_4      (52U)
/* FTM0_5 */
#define   DMA1_PERISEL_FTM0_5      (53U)
/* FTM0_6 */
#define   DMA1_PERISEL_FTM0_6      (54U)
/* FTM0_7 */
#define   DMA1_PERISEL_FTM0_7      (55U)
/* FTM1_0 */
#define   DMA1_PERISEL_FTM1_0      (56U)
/* FTM1_1 */
#define   DMA1_PERISEL_FTM1_1      (57U)
/* FTM1_2 */
#define   DMA1_PERISEL_FTM1_2      (58U)
/* FTM1_3 */
#define   DMA1_PERISEL_FTM1_3      (59U)
/* FTM1_4 */
#define   DMA1_PERISEL_FTM1_4      (60U)
/* FTM1_5 */
#define   DMA1_PERISEL_FTM1_5      (61U)
/* FTM1_6 */
#define   DMA1_PERISEL_FTM1_6      (62U)
/* FTM1_7 */
#define   DMA1_PERISEL_FTM1_7      (63U)
#endif

#if defined(DMA2_FLOW_CONTROL) && (DMA2_FLOW_CONTROL == STD_ON)
/* UART2 transmit */
#define   DMA2_PERISEL_UART2_TX    (0U)
/* UART2 receive  */
#define   DMA2_PERISEL_UART2_RX    (1U)
/* UART3 transmit */
#define   DMA2_PERISEL_UART3_TX    (2U)
/* UART3 receive  */
#define   DMA2_PERISEL_UART3_RX    (3U)
/* SSP4 transmit */
#define   DMA2_PERISEL_SSP4_TX     (4U)
/* SSP4 receive  */
#define   DMA2_PERISEL_SSP4_RX     (5U)
/* SSP5 transmit */
#define   DMA2_PERISEL_SSP5_TX     (6U)
/* SSP5 receive  */
#define   DMA2_PERISEL_SSP5_RX     (7U)
/* SSP6 transmit */
#define   DMA2_PERISEL_SSP6_TX     (8U)
/* SSP6 receive  */
#define   DMA2_PERISEL_SSP6_RX     (9U)
/* SSP7 transmit */
#define   DMA2_PERISEL_SSP7_TX     (10U)
/* SSP7 receive  */
#define   DMA2_PERISEL_SSP7_RX     (11U)
/* I2S0 transmit  */
#define   DMA2_PERISEL_I2S0_TX     (12U)
/* I2S0 receive  */
#define   DMA2_PERISEL_I2S0_RX     (13U)
/* I2C1 transmit */
#define   DMA2_PERISEL_I2C1_TX     (14U)
/* I2C1 receive  */
#define   DMA2_PERISEL_I2C1_RX     (15U)
/* I3C0 transmit */
#define   DMA2_PERISEL_I3C0_TX     (16U)
/* I3C0 receive */
#define   DMA2_PERISEL_I3C0_RX     (17U)
/* PDB0   */
#define   DMA2_PERISEL_PDB0        (18U)
/* PDB1   */
#define   DMA2_PERISEL_PDB1        (19U)
/* LIN8 transmit */
#define   DMA2_PERISEL_LIN8_TX     (20U)
/* LIN8 receive */
#define   DMA2_PERISEL_LIN8_RX     (21U)
/* LIN9 transmit */
#define   DMA2_PERISEL_LIN9_TX     (22U)
/* LIN9 receive */
#define   DMA2_PERISEL_LIN9_RX     (23U)
/* LIN10 transmit */
#define   DMA2_PERISEL_LIN10_TX    (24U)
/* LIN10 receive */
#define   DMA2_PERISEL_LIN10_RX    (25U)
/* LIN11 transmit */
#define   DMA2_PERISEL_LIN11_TX    (26U)
/* LIN11 receive */
#define   DMA2_PERISEL_LIN11_RX    (27U)
/* LIN12 transmit */
#define   DMA2_PERISEL_LIN12_TX    (28U)
/* LIN12 receive */
#define   DMA2_PERISEL_LIN12_RX    (29U)
/* LIN13 transmit */
#define   DMA2_PERISEL_LIN13_TX    (30U)
/* LIN13 receive */
#define   DMA2_PERISEL_LIN13_RX    (31U)
/* LIN14 transmit */
#define   DMA2_PERISEL_LIN14_TX    (32U)
/* LIN14 receive */
#define   DMA2_PERISEL_LIN14_RX    (33U)
/* LIN15 transmit */
#define   DMA2_PERISEL_LIN15_TX    (34U)
/* LIN15 receive */
#define   DMA2_PERISEL_LIN15_RX    (35U)
/* SENT4 transmit */
#define   DMA2_PERISEL_SENT4       (36U)
/* SENT5 transmit */
#define   DMA2_PERISEL_SENT5       (37U)
/* SENT6 transmit */
#define   DMA2_PERISEL_SENT6       (38U)
/* SENT7 transmit */
#define   DMA2_PERISEL_SENT7       (39U)
/* CAN4 receive */
#define   DMA2_PERISEL_CAN4        (40U)
/* CAN5 receive */
#define   DMA2_PERISEL_CAN5        (41U)
/* CAN6 receive */
#define   DMA2_PERISEL_CAN6        (42U)
/* CAN7 receive */
#define   DMA2_PERISEL_CAN7        (43U)
/* trgmux_trg_out_102  */
#define   DMA2_trgmux_trg_out_102  (44U)
/* trgmux_trg_out_103  */
#define   DMA2_trgmux_trg_out_103  (45U)
/* trgmux_trg_out_104 */
#define   DMA2_trgmux_trg_out_104  (46U)
/* trgmux_trg_out_105 */
#define   DMA2_trgmux_trg_out_105  (47U)
/* FTM2_0 transmit */
#define   DMA2_PERISEL_FTM2_0      (48U)
/* FTM2_1 transmit */
#define   DMA2_PERISEL_FTM2_1      (49U)
/* FTM2_2 transmit */
#define   DMA2_PERISEL_FTM2_2      (50U)
/* FTM2_3 transmit */
#define   DMA2_PERISEL_FTM2_3      (51U)
/* FTM2_4 transmit */
#define   DMA2_PERISEL_FTM2_4      (52U)
/* FTM2_5 transmit */
#define   DMA2_PERISEL_FTM2_5      (53U)
/* FTM2_6 transmit */
#define   DMA2_PERISEL_FTM2_6      (54U)
/* FTM2_7 transmit */
#define   DMA2_PERISEL_FTM2_7      (55U)
/* FTM3_0 transmit */
#define   DMA2_PERISEL_FTM3_0      (56U)
/* FTM3_1 transmit */
#define   DMA2_PERISEL_FTM3_1      (57U)
/* FTM3_2 transmit */
#define   DMA2_PERISEL_FTM3_2      (58U)
/* FTM3_3 transmit */
#define   DMA2_PERISEL_FTM3_3      (59U)
/* FTM3_4 transmit */
#define   DMA2_PERISEL_FTM3_4      (60U)
/* FTM3_5 transmit */
#define   DMA2_PERISEL_FTM3_5      (61U)
/* FTM3_6 transmit */
#define   DMA2_PERISEL_FTM3_6      (62U)
/* FTM3_7 transmit */
#define   DMA2_PERISEL_FTM3_7      (63U)
#endif

#if defined(DMA3_FLOW_CONTROL) && (DMA3_FLOW_CONTROL == STD_ON)
/* UART2 transmit */
#define   DMA3_PERISEL_UART2_TX    (0U)
/* UART2 receive  */
#define   DMA3_PERISEL_UART2_RX    (1U)
/* UART3 transmit */
#define   DMA3_PERISEL_UART3_TX    (2U)
/* UART3 receive  */
#define   DMA3_PERISEL_UART3_RX    (3U)
/* SSP4 transmit */
#define   DMA3_PERISEL_SSP4_TX     (4U)
/* SSP4 receive  */
#define   DMA3_PERISEL_SSP4_RX     (5U)
/* SSP5 transmit */
#define   DMA3_PERISEL_SSP5_TX     (6U)
/* SSP5 receive  */
#define   DMA3_PERISEL_SSP5_RX     (7U)
/* SSP6 transmit */
#define   DMA3_PERISEL_SSP6_TX     (8U)
/* SSP6 receive  */
#define   DMA3_PERISEL_SSP6_RX     (9U)
/* SSP7 transmit */
#define   DMA3_PERISEL_SSP7_TX     (10U)
/* SSP7 receive  */
#define   DMA3_PERISEL_SSP7_RX     (11U)
/* I2S0 transmit  */
#define   DMA3_PERISEL_I2S0_TX     (12U)
/* I2S0 receive  */
#define   DMA3_PERISEL_I2S0_RX     (13U)
/* I2C1 transmit */
#define   DMA3_PERISEL_I2C1_TX     (14U)
/* I2C1 receive  */
#define   DMA3_PERISEL_I2C1_RX     (15U)
/* I3C0 transmit */
#define   DMA3_PERISEL_I3C0_TX     (16U)
/* I3C0 receive */
#define   DMA3_PERISEL_I3C0_RX     (17U)
/* PDB0   */
#define   DMA3_PERISEL_PDB0        (18U)
/* PDB1   */
#define   DMA3_PERISEL_PDB1        (19U)
/* LIN8 transmit */
#define   DMA3_PERISEL_LIN8_TX     (20U)
/* LIN8 receive */
#define   DMA3_PERISEL_LIN8_RX     (21U)
/* LIN9 transmit */
#define   DMA3_PERISEL_LIN9_TX     (22U)
/* LIN9 receive */
#define   DMA3_PERISEL_LIN9_RX     (23U)
/* LIN10 transmit */
#define   DMA3_PERISEL_LIN10_TX    (24U)
/* LIN10 receive */
#define   DMA3_PERISEL_LIN10_RX    (25U)
/* LIN11 transmit */
#define   DMA3_PERISEL_LIN11_TX    (26U)
/* LIN11 receive */
#define   DMA3_PERISEL_LIN11_RX    (27U)
/* LIN12 transmit */
#define   DMA3_PERISEL_LIN12_TX    (28U)
/* LIN12 receive */
#define   DMA3_PERISEL_LIN12_RX    (29U)
/* LIN13 transmit */
#define   DMA3_PERISEL_LIN13_TX    (30U)
/* LIN13 receive */
#define   DMA3_PERISEL_LIN13_RX    (31U)
/* LIN14 transmit */
#define   DMA3_PERISEL_LIN14_TX    (32U)
/* LIN14 receive */
#define   DMA3_PERISEL_LIN14_RX    (33U)
/* LIN15 transmit */
#define   DMA3_PERISEL_LIN15_TX    (34U)
/* LIN15 receive */
#define   DMA3_PERISEL_LIN15_RX    (35U)
/* SENT4 transmit */
#define   DMA3_PERISEL_SENT4       (36U)
/* SENT5 transmit */
#define   DMA3_PERISEL_SENT5       (37U)
/* SENT6 transmit */
#define   DMA3_PERISEL_SENT6       (38U)
/* SENT7 transmit */
#define   DMA3_PERISEL_SENT7       (39U)
/* CAN4 receive */
#define   DMA3_PERISEL_CAN4        (40U)
/* CAN5 receive */
#define   DMA3_PERISEL_CAN5        (41U)
/* CAN6 receive */
#define   DMA3_PERISEL_CAN6        (42U)
/* CAN7 receive */
#define   DMA3_PERISEL_CAN7        (43U)
/* trgmux_trg_out_102  */
#define   DMA3_trgmux_trg_out_102  (44U)
/* trgmux_trg_out_103  */
#define   DMA3_trgmux_trg_out_103  (45U)
/* trgmux_trg_out_104 */
#define   DMA3_trgmux_trg_out_104  (46U)
/* trgmux_trg_out_105 */
#define   DMA3_trgmux_trg_out_105  (47U)
/* FTM4_0 transmit */
#define   DMA3_PERISEL_FTM4_0      (48U)
/* FTM4_1 transmit */
#define   DMA3_PERISEL_FTM4_1      (49U)
/* FTM4_2 transmit */
#define   DMA3_PERISEL_FTM4_2      (50U)
/* FTM4_3 transmit */
#define   DMA3_PERISEL_FTM4_3      (51U)
/* FTM4_4 transmit */
#define   DMA3_PERISEL_FTM4_4      (52U)
/* FTM4_5 transmit */
#define   DMA3_PERISEL_FTM4_5      (53U)
/* FTM4_6 transmit */
#define   DMA3_PERISEL_FTM4_6      (54U)
/* FTM4_7 transmit */
#define   DMA3_PERISEL_FTM4_7      (55U)
/* FTM5_0 transmit */
#define   DMA3_PERISEL_FTM5_0      (56U)
/* FTM5_1 transmit */
#define   DMA3_PERISEL_FTM5_1      (57U)
/* FTM5_2 transmit */
#define   DMA3_PERISEL_FTM5_2      (58U)
/* FTM5_3 transmit */
#define   DMA3_PERISEL_FTM5_3      (59U)
/* FTM5_4 transmit */
#define   DMA3_PERISEL_FTM5_4      (60U)
/* FTM5_5 transmit */
#define   DMA3_PERISEL_FTM5_5      (61U)
/* FTM5_6 transmit */
#define   DMA3_PERISEL_FTM5_6      (62U)
/* FTM5_7 transmit */
#define   DMA3_PERISEL_FTM5_7      (63U)
#endif

#define   INVALID                  (0U)

/* Number of DMA channels*/
#define DMA_NUMBER_OF_CHANNEL           ((uint32) 8U)
#define DMA_NUMBERS                     ((uint32) 4U)
#define DMA_NUMBER_OF_CHANNELS          (DMA_NUMBER_OF_CHANNEL * DMA_NUMBERS)

/* DMA Events*/
#define DMA_EVENT_TERMINAL_COUNT_REQUEST (1U)
#define DMA_EVENT_ERROR                  (2U)
/******************************************************************************
*                            Enums
*******************************************************************************/
/** @brief Dmac access mode*/
typedef enum
{
    DMA_USER_MODE = 0U,
    DMA_PRIVILEGE_MODE
} Dma_Hw_AccessModetype;

/** @brief Dmac data width*/
typedef enum
{
    DMA_8_BIT_DATA = 0U,
    DMA_16_BIT_DATA,
    DMA_32_BIT_DATA,
    DMA_64_BIT_DATA
} Dma_Hw_DataWidthType;

/** @brief Dmac transmission burst size*/
typedef enum
{
    DMA_1_BURST = 0U,
    DMA_4_BURST,
    DMA_8_BURST,
    DMA_16_BURST,
    DMA_32_BURST,
    DMA_64_BURST,
    DMA_128_BURST,
    DMA_256_BURST
}Dma_Hw_BurstSizeType;

/** @brief Dmac flow control*/
typedef enum
{
    DMA_CONTROL_MEMERY_TO_MEMERY = 0U,
    DMA_CONTROL_MEMERY_TO_PERIPHERAL,
    DMA_CONTROL_PERIPHERAL_TO_MEMERY,
    DMA_CONTROL_PERIPHERAL_TO_PERIPHERAL
} Dma_Hw_FlowControlType;

/** @brief Dmac Master control*/
typedef enum
{
   DMA_MASTER1          = 0U,
   DMA_MASTER2
} Dma_Hw_MasterType;
/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/**
*@fn          void Dma_SignalEvent_t (uint32 event)
*@brief       Signal DMA Events.
*@param[in]   event  DMA Event mask
*@return      none
*/
typedef void (*Dma_SignalEvent_t) (uint32 event);

/* DMA Channel info block structur */
typedef struct {
    /* Linked list mode */
    boolean           LliMode;
    /* Dma transfer mode */
    uint8             DmaMode;
    /* Dma Source Address */
    uint32            SrcAddr;
    /* Dma Dest Address */
    uint32            DestAddr;
    /* Dma transfer size */
    uint32            Size;
    /* Dma transfer count */
    uint32            Cnt;
    Dma_SignalEvent_t cb_event;
} Dma_Hw_Channel_Info;

/** @brief Dmac link list node */
typedef struct Dma_Hw_LinkNodeType
{
    /** @brief DMA Channel Source Address */
    uint32               DmaSrcAddr;
    /** @brief DMA Channel Destination Address */
    uint32               DmaDestAddr;
    /** @brief DMA Channel Linked List Item */
    TT_CONST struct Dma_Hw_LinkNodeType* DmaLinkNext;
    /** @brief DMA Channel tranfer size */
    uint32               DmaTranferSize :12;
    /** @brief DMA Channel source burst size */
    uint32               DmaSourceBurstSize :3;
    /** @brief DMA Channel dest burst size */
    uint32               DmaDestBurstSize :3;
    /** @brief DMA Channel souce data width */
    uint32               DmaSourceDataWidth :2;
    /** @brief DMA Channel Interrupt triggering enabled */
    uint32               DmaIntTtrg :1;
    /** @brief DMA Channel dest data width */
    uint32               DmaDestDataWidth :2;
    /** @brief DMA Channel all in one */
    uint32               DmaAllInOne :1;
    /** @brief DMA Source tranfer Master select */
    uint32                DmaSMaster :1;
    /** @brief DMA Dest tranfer Master select */
    uint32                DmaDMaster :1;
    /** @brief DMA source address self increment or not*/
    uint32               DmaSourceIncrease :1;
    /** @brief DMA dest address self increment or not*/
    uint32               DmaDestIncrease :1;
    /** @brief DMA access mode*/
    uint32               DmaAccessMode :3;
    /** @brief DMA interrupt enable*/
    uint32               DmaLliIrqEn   :1;
} Dma_Hw_LinkNodeType;

/** @brief Dmac link list head node */
typedef struct
{
    /** @brief link node count */
    uint32 DmaNodeCount;
    /** @brief LLI Value */
    uint32 DmaLLI;
    /** @brief link list head node pointer*/
    TT_CONST Dma_Hw_LinkNodeType* DmaNode;
} Dma_Hw_LinkHeadType;

/** @brief Dmac link list head node */
typedef struct
{
    /** @brief Dma continuous mode enable */
    boolean DmaContinuousMode;
    /** @brief DMA source address self increment or not*/
    boolean DmaSourceIncrease;
    /** @brief DMA dest address self increment or not*/
    boolean DmaDestIncrease;
    /** @brief DMA Channel Interrupt triggering enabled*/
    boolean DmaIntTtrg;
    /** @brief DMA Channel all in one*/
    boolean DmaAllInOne;
    /** @brief DMA Channel Irq En*/
    boolean DmaIrqEn;
    /** @brief Number of single mode */
    uint8 DmaOneshotMode;
    /** @brief ID of software layer definition */
    uint32 DmaConfigId;
    /** @brief ID of dmac channel */
    uint32 DmaChannelId;
    /** @brief DMA access mode*/
    Dma_Hw_AccessModetype DmaAccessMode;
    /** @brief DMA Source tranfer Master select */
    Dma_Hw_MasterType  DmaSMaster;
    /** @brief DMA Dest tranfer Master select */
    Dma_Hw_MasterType  DmaDMaster;
    /** @brief DMA Channel souce data width */
    Dma_Hw_DataWidthType DmaSourceDataWidth;
    /** @brief DMA Channel dest data width */
    Dma_Hw_DataWidthType DmaDestDataWidth;
    /** @brief DMA Channel source burst size */
    Dma_Hw_BurstSizeType DmaSourceBurstSize;
    /** @brief DMA Channel dest burst size */
    Dma_Hw_BurstSizeType DmaDestBurstSize;
    /** @brief Select Dmac flow control*/
    Dma_Hw_FlowControlType DmaFlowControl;
    /** @brief Select dmac Source periphera id*/
    uint32 DmaSrcPeripheralId;
    /** @brief Select dmac Dest periphera id*/
    uint32 DmaDestPeripheralId;
    /** @brief Use link list function */
    TT_CONST Dma_Hw_LinkHeadType *DmaLinkHead;
    /** @brief The module Crc value is retained */
    TT_CONST uint32 DmaCrc;
} Dma_Hw_ChannelConfigType;
/******************************************************************************
*                         GLOBAL VARIABLE DECLARATIONS
******************************************************************************/
/** @brief Configuration contaner */
#define DMA_START_SEC_CONST_UNSPECIFIED
#include "Dma_MemMap.h"
/* Configuration data common to all channels of the DMAC driver */
extern TT_CONST Dma_Hw_ChannelConfigType DmaChannelConfig[DMA_CONFIG_NUMBER];
#define DMA_STOP_SEC_CONST_UNSPECIFIED
#include "Dma_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif
