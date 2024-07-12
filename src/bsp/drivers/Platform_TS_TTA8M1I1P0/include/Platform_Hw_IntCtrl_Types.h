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
**  FILENAME     : Platform_Hw_IntCtrl_Types.h                                **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Source File                                **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef PLATFORM_HW_INTCTRL_TYPES_H
#define PLATFORM_HW_INTCTRL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_IntCtrl_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_INTCTRL_TYPES_VENDOR_ID_H                     1541
#define PLATFORM_HW_INTCTRL_TYPES_MODULE_ID_H                     219
#define PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define PLATFORM_HW_INTCTRL_TYPES_SW_MAJOR_VERSION_H              1
#define PLATFORM_HW_INTCTRL_TYPES_SW_MINOR_VERSION_H              1
#define PLATFORM_HW_INTCTRL_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_IntCtrl_Types.h and Platform_IntCtrl_Cfg.h file version check */
#if (PLATFORM_HW_INTCTRL_TYPES_VENDOR_ID_H != PLATFORM_INTCTRL_CFG_VENDOR_ID_H)
    #error "Platform_Hw_IntCtrl_Types.h and Platform_IntCtrl_Cfg.h have different vendor id"
#endif
#if (PLATFORM_HW_INTCTRL_TYPES_MODULE_ID_H != PLATFORM_INTCTRL_CFG_MODULE_ID_H)
    #error "Platform_Hw_IntCtrl_Types.h and Platform_IntCtrl_Cfg.h have different module id"
#endif
#if ((PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_INTCTRL_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MINOR_VERSION_H != PLATFORM_INTCTRL_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_PATCH_VERSION_H != PLATFORM_INTCTRL_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_IntCtrl_Types.h and Platform_IntCtrl_Cfg.h are different"
#endif
#if ((PLATFORM_HW_INTCTRL_TYPES_SW_MAJOR_VERSION_H != PLATFORM_INTCTRL_CFG_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_TYPES_SW_MINOR_VERSION_H != PLATFORM_INTCTRL_CFG_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_INTCTRL_TYPES_SW_PATCH_VERSION_H != PLATFORM_INTCTRL_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_IntCtrl_Types.h and Platform_IntCtrl_Cfg.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* interrupt priority grouoing assert */
#define IS_INTCTRL_PRIORITY_GROUPING(GROUP)   (((GROUP) & ~(TT_SCB_AIRCR_PRIGROUP_Msk >> TT_SCB_AIRCR_PRIGROUP_Pos)) == 0U)
/* interrupt priority assert */
#define IS_INTCTRL_PRIORITY(GROUPING, PREEMPTION, SUB)  (((PREEMPTION) & ~(((uint32)1U << (7U-GROUPING)) - 1U)) == 0U && \
                                                         ((SUB) & ~(((uint32)1U << (1U+GROUPING)) - 1U)) == 0U)
/* interrupt encode priority assert */
#define IS_INTCTRL_ENCODED_PRIORITY(PRIORITY) (((PRIORITY) & ~((1 << 8) - 1U)) == 0)
/******************************************************************************
*                            Enums
*******************************************************************************/
/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* =======================================  ARM Cortex-M7 Specific Interrupt Numbers  ======================================== */
  Reset_IRQn                = -15,              /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn       = -14,              /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn            = -13,              /*!< -13  Hard Fault, all classes of Fault                                     */
  MemoryManagement_IRQn     = -12,              /*!< -12  Memory Management, MPU mismatch, including Access Violation
                                                     and No Match                                                              */
  BusFault_IRQn             = -11,              /*!< -11  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                     related Fault                                                             */
  UsageFault_IRQn           = -10,              /*!< -10  Usage Fault, i.e. Undef Instruction, Illegal State Transition        */
  SVCall_IRQn               =  -5,              /*!< -5 System Service Call via SVC instruction                                */
  DebugMonitor_IRQn         =  -4,              /*!< -4 Debug Monitor                                                          */
  PendSV_IRQn               =  -2,              /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn              =  -1,              /*!< -1 System Tick Timer                                                      */
/* ============================================  A8V2 Specific Interrupt Numbers  ============================================ */
  CTI0_IRQn                 =   0,              /*!< 0  CTI0                                                                   */
  CTI1_IRQn                 =   1,              /*!< 1  CTI1                                                                   */
  SMU0_IRQn                 =   2,              /*!< 2  SMU0                                                                   */
  SHDN_IRQn                 =   3,              /*!< 3  SHDN                                                                   */
  ENDINIT_IRQn              =   4,              /*!< 4  ENDINIT                                                                */
  PMU_IRQn                  =   5,              /*!< 5  PMU                                                                    */
  DFCU_IRQn                 =   6,              /*!< 6  DFCU                                                                   */
  PFCU_IRQn                 =   7,              /*!< 7  PFCU                                                                   */
  DEBUG_IRQn                =   8,              /*!< 8  DEBUG                                                                  */
  CRC_IRQn                  =   9,              /*!< 9  CRC Interrupt                                                          */
  WWDT_IRQn                 =  10,              /*!< 10 Window Watchdog Interrupt                                              */
  ADCSENSOR_IRQn            =  11,              /*!< 11 ADCSENSOR                                                              */
  MAILBOX_IRQn              =  12,              /*!< 12 mailbox Interrupt                                                      */
  PKI_IRQn                  =  13,              /*!< 13 PKI                                                                    */
  SM4_IRQn                  =  14,              /*!< 14 SM4                                                                    */
  HASH_IRQn                 =  15,              /*!< 15 HASH Interrupt                                                         */
  SKA_IRQn                  =  16,              /*!< 16 SKA Interrupt                                                          */
  TRNG_IRQn                 =  17,              /*!< 17 TRNG Interrupt                                                         */
  GPDMA0_COMBINE_IRQn       =  18,              /*!< 18 GPDMA0_COMBINE                                                         */
  GPDMA1_COMBINE_IRQn       =  19,              /*!< 19 GPDMA1_COMBINE                                                         */
  GPDMA2_COMBINE_IRQn       =  20,              /*!< 20 GPDMA2_COMBINE                                                         */
  GPDMA3_COMBINE_IRQn       =  21,              /*!< 21 GPDMA3_COMBINE                                                         */
  PDB0_IRQn                 =  22,              /*!< 22 PDB0                                                                   */
  PDB0_ERR_IRQn             =  23,              /*!< 23 PDB0_ERR                                                               */
  PDB1_IRQn                 =  24,              /*!< 24 PDB1                                                                   */
  PDB1_ERR_IRQn             =  25,              /*!< 25 PDB1_ERR                                                               */
  ADC0_IRQn                 =  26,              /*!< 26 ADC0                                                                   */
  ADC1_IRQn                 =  27,              /*!< 27 ADC1                                                                   */
  ADC2_IRQn                 =  28,              /*!< 28 ADC2                                                                   */
  ADC3_IRQn                 =  29,              /*!< 29 ADC3                                                                   */
  ADC4_IRQn                 =  30,              /*!< 30 ADC4                                                                   */
  ADC5_IRQn                 =  31,              /*!< 31 ADC5                                                                   */
  SENT0_IRQn                =  32,              /*!< 32 SENT0                                                                  */
  SENT1_IRQn                =  33,              /*!< 33 SENT1                                                                  */
  SENT2_IRQn                =  34,              /*!< 34 SENT2                                                                  */
  SENT3_IRQn                =  35,              /*!< 35 SENT3                                                                  */
  SENT4_IRQn                =  36,              /*!< 36 SENT4                                                                  */
  SENT5_IRQn                =  37,              /*!< 37 SENT5                                                                  */
  SENT6_IRQn                =  38,              /*!< 38 SENT6                                                                  */
  SENT7_IRQn                =  39,              /*!< 39 SENT7                                                                  */
  QSPI0_IRQn                =  40,              /*!< 40 QSPI0                                                                  */
  ENET_LPI_IRQn             =  41,              /*!< 41 ENET_LPI                                                               */
  ENET_SBD_IRQn             =  42,              /*!< 42 ENET_SBD                                                               */
  ENET_PMT_IRQn             =  43,              /*!< 43 ENET_PMT                                                               */
  UART0_COMBINE_IRQn        =  44,              /*!< 44 UART0_COMBINE                                                          */
  UART1_COMBINE_IRQn        =  45,              /*!< 45 UART1_COMBINE                                                          */
  UART2_COMBINE_IRQn        =  46,              /*!< 46 UART2_COMBINE                                                          */
  UART3_COMBINE_IRQn        =  47,              /*!< 47 UART3_COMBINE                                                          */
  LIN0_IRQn                 =  48,              /*!< 48 LIN0                                                                   */
  LIN1_IRQn                 =  49,              /*!< 49 LIN1                                                                   */
  LIN2_IRQn                 =  50,              /*!< 50 LIN2                                                                   */
  LIN3_IRQn                 =  51,              /*!< 51 LIN3                                                                   */
  LIN4_IRQn                 =  52,              /*!< 52 LIN4                                                                   */
  LIN5_IRQn                 =  53,              /*!< 53 LIN5                                                                   */
  LIN6_IRQn                 =  54,              /*!< 54 LIN6                                                                   */
  LIN7_IRQn                 =  55,              /*!< 55 LIN7                                                                   */
  LIN8_IRQn                 =  56,              /*!< 56 LIN8                                                                   */
  LIN9_IRQn                 =  57,              /*!< 57 LIN9                                                                   */
  LIN10_IRQn                =  58,              /*!< 58 LIN10                                                                  */
  LIN11_IRQn                =  59,              /*!< 59 LIN11                                                                  */
  LIN12_IRQn                =  60,              /*!< 60 LIN12                                                                  */
  LIN13_IRQn                =  61,              /*!< 61 LIN13                                                                  */
  LIN14_IRQn                =  62,              /*!< 62 LIN14                                                                  */
  LIN15_IRQn                =  63,              /*!< 63 LIN15                                                                  */
  I2C0_IRQn                 =  64,              /*!< 64 I2C0 Interrupt                                                         */
  I2C1_IRQn                 =  65,              /*!< 65 I2C1 Interrupt                                                         */
  I3C0_IRQn                 =  66,              /*!< 66 I3C0                                                                   */
  SSP0_COMBINE_IRQn         =  67,              /*!< 67 SSP0 Combined Interrupt                                                */
  SSP1_COMBINE_IRQn         =  68,              /*!< 68 SSP1 Combined Interrupt                                                */
  SSP2_COMBINE_IRQn         =  69,              /*!< 69 SSP2 Combined Interrupt                                                */
  SSP3_COMBINE_IRQn         =  70,              /*!< 70 SSP3 Combined Interrupt                                                */
  SSP4_COMBINE_IRQn         =  71,              /*!< 71 SSP4 Combined Interrupt                                                */
  SSP5_COMBINE_IRQn         =  72,              /*!< 72 SSP5 Combined Interrupt                                                */
  SSP6_COMBINE_IRQn         =  73,              /*!< 73 SSP6 Combined Interrupt                                                */
  SSP7_COMBINE_IRQn         =  74,              /*!< 74 SSP7 Combined Interrupt                                                */
  GPIOA_IRQn                =  75,              /*!< 75 GPIOA Interrupt                                                        */
  GPIOB_IRQn                =  76,              /*!< 76 GPIOB Interrupt                                                        */
  GPIOC_IRQn                =  77,              /*!< 77 GPIOC Interrupt                                                        */
  GPIOD_IRQn                =  78,              /*!< 78 GPIOD Interrupt                                                        */
  GPIOE_IRQn                =  79,              /*!< 79 GPIOE Interrupt                                                        */
  I2S0_IRQn                 =  80,              /*!< 80 I2S0                                                                   */
  CAN_Busoff0_IRQn          =  81,              /*!< 81 CAN_Busoff0                                                            */
  CAN_Error0_IRQn           =  82,              /*!< 82 CAN_Error0                                                             */
  CAN_Mbor0_IRQn            =  83,              /*!< 83 CAN_Mbor0                                                              */
  CAN_EnhancedRxFifo0_IRQn  =  84,              /*!< 84 CAN_EnhancedRxFifo0                                                    */
  CAN_TXRX_Warnning0_IRQn   =  85,              /*!< 85 CAN_TXRX_Warnning0                                                     */
  CAN_Wakeup0_IRQn          =  86,              /*!< 86 CAN_Wakeup0                                                            */
  CAN_Busoff1_IRQn          =  87,              /*!< 87 CAN_Busoff1                                                            */
  CAN_Error1_IRQn           =  88,              /*!< 88 CAN_Error1                                                             */
  CAN_Mbor1_IRQn            =  89,              /*!< 89 CAN_Mbor1                                                              */
  CAN_EnhancedRxFifo1_IRQn  =  90,              /*!< 90 CAN_EnhancedRxFifo1                                                    */
  CAN_TXRX_Warnning1_IRQn   =  91,              /*!< 91 CAN_TXRX_Warnning1                                                     */
  CAN_Wakeup1_IRQn          =  92,              /*!< 92 CAN_Wakeup1                                                            */
  CAN_Busoff2_IRQn          =  93,              /*!< 93 CAN_Busoff2                                                            */
  CAN_Error2_IRQn           =  94,              /*!< 94 CAN_Error2                                                             */
  CAN_Mbor2_IRQn            =  95,              /*!< 95 CAN_Mbor2                                                              */
  CAN_EnhancedRxFifo2_IRQn  =  96,              /*!< 96 CAN_EnhancedRxFifo2                                                    */
  CAN_TXRX_Warnning2_IRQn   =  97,              /*!< 97 CAN_TXRX_Warnning2                                                     */
  CAN_Wakeup2_IRQn          =  98,              /*!< 98 CAN_Wakeup2                                                            */
  CAN_Busoff3_IRQn          =  99,              /*!< 99 CAN_Busoff3                                                            */
  CAN_Error3_IRQn           = 100,              /*!< 100  CAN_Error3                                                           */
  CAN_Mbor3_IRQn            = 101,              /*!< 101  CAN_Mbor3                                                            */
  CAN_EnhancedRxFifo3_IRQn  = 102,              /*!< 102  CAN_EnhancedRxFifo3                                                  */
  CAN_TXRX_Warnning3_IRQn   = 103,              /*!< 103  CAN_TXRX_Warnning3                                                   */
  CAN_Wakeup3_IRQn          = 104,              /*!< 104  CAN_Wakeup3                                                          */
  CAN_Busoff4_IRQn          = 105,              /*!< 105  CAN_Busoff4                                                          */
  CAN_Error4_IRQn           = 106,              /*!< 106  CAN_Error4                                                           */
  CAN_Mbor4_IRQn            = 107,              /*!< 107  CAN_Mbor4                                                            */
  CAN_EnhancedRxFifo4_IRQn  = 108,              /*!< 108  CAN_EnhancedRxFifo4                                                  */
  CAN_TXRX_Warnning4_IRQn   = 109,              /*!< 109  CAN_TXRX_Warnning4                                                   */
  CAN_Wakeup4_IRQn          = 110,              /*!< 110  CAN_Wakeup4                                                          */
  CAN_Busoff5_IRQn          = 111,              /*!< 111  CAN_Busoff5                                                          */
  CAN_Error5_IRQn           = 112,              /*!< 112  CAN_Error5                                                           */
  CAN_Mbor5_IRQn            = 113,              /*!< 113  CAN_Mbor5                                                            */
  CAN_EnhancedRxFifo5_IRQn  = 114,              /*!< 114  CAN_EnhancedRxFifo5                                                  */
  CAN_TXRX_Warnning5_IRQn   = 115,              /*!< 115  CAN_TXRX_Warnning5                                                   */
  CAN_Wakeup5_IRQn          = 116,              /*!< 116  CAN_Wakeup5                                                          */
  CAN_Busoff6_IRQn          = 117,              /*!< 117  CAN_Busoff6                                                          */
  CAN_Error6_IRQn           = 118,              /*!< 118  CAN_Error6                                                           */
  CAN_Mbor6_IRQn            = 119,              /*!< 119  CAN_Mbor6                                                            */
  CAN_EnhancedRxFifo6_IRQn  = 120,              /*!< 120  CAN_EnhancedRxFifo6                                                  */
  CAN_TXRX_Warnning6_IRQn   = 121,              /*!< 121  CAN_TXRX_Warnning6                                                   */
  CAN_Wakeup6_IRQn          = 122,              /*!< 122  CAN_Wakeup6                                                          */
  CAN_Busoff7_IRQn          = 123,              /*!< 123  CAN_Busoff7                                                          */
  CAN_Error7_IRQn           = 124,              /*!< 124  CAN_Error7                                                           */
  CAN_Mbor7_IRQn            = 125,              /*!< 125  CAN_Mbor7                                                            */
  CAN_EnhancedRxFifo7_IRQn  = 126,              /*!< 126  CAN_EnhancedRxFifo7                                                  */
  CAN_TXRX_Warnning7_IRQn   = 127,              /*!< 127  CAN_TXRX_Warnning7                                                   */
  CAN_Wakeup7_IRQn          = 128,              /*!< 128  CAN_Wakeup7                                                          */
  STM0_IRQn                 = 129,              /*!< 129  Timer Interrupt                                                      */
  STM1_IRQn                 = 130,              /*!< 130  Timer Interrupt                                                      */
  FTM0_IRQn                 = 131,              /*!< 131  FlexTimer Module Interrupt                                           */
  FTM1_IRQn                 = 132,              /*!< 132  FTM1                                                                 */
  FTM2_IRQn                 = 133,              /*!< 133  FTM2                                                                 */
  FTM3_IRQn                 = 134,              /*!< 134  FTM3                                                                 */
  FTM4_IRQn                 = 135,              /*!< 135  FTM4                                                                 */
  FTM5_IRQn                 = 136,              /*!< 136  FTM5                                                                 */
  GTM_ATOM3_IRQn            = 137,              /*!< 137  GTM_ATOM3                                                            */
  GTM_ATOM2_IRQn            = 138,              /*!< 138  GTM_ATOM2                                                            */
  GTM_ATOM1_IRQn            = 139,              /*!< 139  GTM_ATOM1                                                            */
  GTM_ATOM0_IRQn            = 140,              /*!< 140  GTM_ATOM0                                                            */
  GTM_TIO3_G1_HO_IRQn       = 141,              /*!< 141  GTM_TIO3_G1_HO                                                       */
  GTM_TIO3_G1_LO_IRQn       = 142,              /*!< 142  GTM_TIO3_G1_LO                                                       */
  GTM_TIO2_G1_HO_IRQn       = 143,              /*!< 143  GTM_TIO2_G1_HO                                                       */
  GTM_TIO2_G1_HL_IRQn       = 144,              /*!< 144  GTM_TIO2_G1_HL                                                       */
  GTM_TIO1_G1_HO_IRQn       = 145,              /*!< 145  GTM_TIO1_G1_HO                                                       */
  GTM_TIO1_G1_HL_IRQn       = 146,              /*!< 146  GTM_TIO1_G1_HL                                                       */
  GTM_TIO0_G1_HO_IRQn       = 147,              /*!< 147  GTM_TIO0_G1_HO                                                       */
  GTM_TIO0_G1_HL_IRQn       = 148,              /*!< 148  GTM_TIO0_G1_HL                                                       */
  GTM_TIO3_G0_HO_IRQn       = 149,              /*!< 149  GTM_TIO3_G0_HO                                                       */
  GTM_TIO3_G0_LO_IRQn       = 150,              /*!< 150  GTM_TIO3_G0_LO                                                       */
  GTM_TIO2_G0_HO_IRQn       = 151,              /*!< 151  GTM_TIO2_G0_HO                                                       */
  GTM_TIO2_G0_HL_IRQn       = 152,              /*!< 152  GTM_TIO2_G0_HL                                                       */
  GTM_TIO1_G0_HO_IRQn       = 153,              /*!< 153  GTM_TIO1_G0_HO                                                       */
  GTM_TIO1_G0_HL_IRQn       = 154,              /*!< 154  GTM_TIO1_G0_HL                                                       */
  GTM_TIO0_G0_HO_IRQn       = 155,              /*!< 155  GTM_TIO0_G0_HO                                                       */
  GTM_TIO0_G0_HL_IRQn       = 156,              /*!< 156  GTM_TIO0_G0_HL                                                       */
  GTM_MCS2_S_HO_IRQn        = 157,              /*!< 157  GTM_MCS2_S_HO                                                        */
  GTM_MCS2_S_LO_IRQn        = 158,              /*!< 158  GTM_MCS2_S_LO                                                        */
  GTM_MCS1_S_HO_IRQn        = 159,              /*!< 159  GTM_MCS1_S_HO                                                        */
  GTM_MCS1_S_LO_IRQn        = 160,              /*!< 160  GTM_MCS1_S_LO                                                        */
  GTM_MCS0_S_HO_IRQn        = 161,              /*!< 161  GTM_MCS0_S_HO                                                        */
  GTM_MCS0_S_LO_IRQn        = 162,              /*!< 162  GTM_MCS0_S_LO                                                        */
  GTM_MCS2_HO_IRQn          = 163,              /*!< 163  GTM_MCS2_HO                                                          */
  GTM_MCS2_LO_IRQn          = 164,              /*!< 164  GTM_MCS2_LO                                                          */
  GTM_MCS1_HO_IRQn          = 165,              /*!< 165  GTM_MCS1_HO                                                          */
  GTM_MCS1_LO_IRQn          = 166,              /*!< 166  GTM_MCS1_LO                                                          */
  GTM_MCS0_HO_IRQn          = 167,              /*!< 167  GTM_MCS0_HO                                                          */
  GTM_MCS0_LO_IRQn          = 168,              /*!< 168  GTM_MCS0_LO                                                          */
  GTM_PSM_HO_IRQn           = 169,              /*!< 169  GTM_PSM_HO                                                           */
  GTM_PSM_LO_IRQn           = 170,              /*!< 170  GTM_PSM_LO                                                           */
  GTM_DPLL_HO_IRQn          = 171,              /*!< 171  GTM_DPLL_HO                                                          */
  GTM_DPLL_LO_IRQn          = 172,              /*!< 172  GTM_DPLL_LO                                                          */
  GTM_SPE1_IRQn             = 173,              /*!< 173  GTM_SPE1                                                             */
  GTM_SPE0_IRQn             = 174,              /*!< 174  GTM_SPE0                                                             */
  GTM_CMP_IRQn              = 175,              /*!< 175  GTM_CMP                                                              */
  GTM_BRC_IRQn              = 176,              /*!< 176  GTM_BRC                                                              */
  GTM_ARU_IRQn              = 177,              /*!< 177  GTM_ARU                                                              */
  GTM_AEI_IRQn              = 178,              /*!< 178  GTM_AEI                                                              */
  GTM_ERR_IRQn              = 179,              /*!< 179  GTM_ERR                                                              */
  GTM_TIM0_0_IRQn           = 180,              /*!< 180  GTM_TIM0_0                                                           */
  GTM_TIM0_1_IRQn           = 181,              /*!< 181  GTM_TIM0_1                                                           */
  GTM_TIM0_2_IRQn           = 182,              /*!< 182  GTM_TIM0_2                                                           */
  GTM_TIM0_3_IRQn           = 183,              /*!< 183  GTM_TIM0_3                                                           */
  GTM_TIM0_4_IRQn           = 184,              /*!< 184  GTM_TIM0_4                                                           */
  GTM_TIM0_5_IRQn           = 185,              /*!< 185  GTM_TIM0_5                                                           */
  GTM_TIM0_6_IRQn           = 186,              /*!< 186  GTM_TIM0_6                                                           */
  GTM_TIM0_7_IRQn           = 187,              /*!< 187  GTM_TIM0_7                                                           */
  GTM_TIM1_0_IRQn           = 188,              /*!< 188  GTM_TIM1_0                                                           */
  GTM_TIM1_1_IRQn           = 189,              /*!< 189  GTM_TIM1_1                                                           */
  GTM_TIM1_2_IRQn           = 190,              /*!< 190  GTM_TIM1_2                                                           */
  GTM_TIM1_3_IRQn           = 191,              /*!< 191  GTM_TIM1_3                                                           */
  GTM_TIM1_4_IRQn           = 192,              /*!< 192  GTM_TIM1_4                                                           */
  GTM_TIM1_5_IRQn           = 193,              /*!< 193  GTM_TIM1_5                                                           */
  GTM_TIM1_6_IRQn           = 194,              /*!< 194  GTM_TIM1_6                                                           */
  GTM_TIM1_7_IRQn           = 195,              /*!< 195  GTM_TIM1_7                                                           */
  GTM_TIM2_0_IRQn           = 196,              /*!< 196  GTM_TIM2_0                                                           */
  GTM_TIM2_1_IRQn           = 197,              /*!< 197  GTM_TIM2_1                                                           */
  GTM_TIM2_2_IRQn           = 198,              /*!< 198  GTM_TIM2_2                                                           */
  GTM_TIM2_3_IRQn           = 199,              /*!< 199  GTM_TIM2_3                                                           */
  GTM_TIM2_4_IRQn           = 200,              /*!< 200  GTM_TIM2_4                                                           */
  GTM_TIM2_5_IRQn           = 201,              /*!< 201  GTM_TIM2_5                                                           */
  GTM_TIM2_6_IRQn           = 202,              /*!< 202  GTM_TIM2_6                                                           */
  GTM_TIM2_7_IRQn           = 203,              /*!< 203  GTM_TIM2_7                                                           */
  GTM_TOM0_0_IRQn           = 204,              /*!< 204  GTM_TOM0_0                                                           */
  GTM_TOM0_1_IRQn           = 205,              /*!< 205  GTM_TOM0_1                                                           */
  GTM_TOM0_2_IRQn           = 206,              /*!< 206  GTM_TOM0_2                                                           */
  GTM_TOM0_3_IRQn           = 207,              /*!< 207  GTM_TOM0_3                                                           */
  GTM_TOM0_4_IRQn           = 208,              /*!< 208  GTM_TOM0_4                                                           */
  GTM_TOM0_5_IRQn           = 209,              /*!< 209  GTM_TOM0_5                                                           */
  GTM_TOM0_6_IRQn           = 210,              /*!< 210  GTM_TOM0_6                                                           */
  GTM_TOM0_7_IRQn           = 211,              /*!< 211  GTM_TOM0_7                                                           */
  GTM_TOM1_0_IRQn           = 212,              /*!< 212  GTM_TOM1_0                                                           */
  GTM_TOM1_1_IRQn           = 213,              /*!< 213  GTM_TOM1_1                                                           */
  GTM_TOM1_2_IRQn           = 214,              /*!< 214  GTM_TOM1_2                                                           */
  GTM_TOM1_3_IRQn           = 215,              /*!< 215  GTM_TOM1_3                                                           */
  GTM_TOM1_4_IRQn           = 216,              /*!< 216  GTM_TOM1_4                                                           */
  GTM_TOM1_5_IRQn           = 217,              /*!< 217  GTM_TOM1_5                                                           */
  GTM_TOM1_6_IRQn           = 218,              /*!< 218  GTM_TOM1_6                                                           */
  GTM_TOM1_7_IRQn           = 219               /*!< 219  GTM_TOM1_7                                                           */
} IRQn_Type;
/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/**
* @brief          Structure storing the state and priority configuration for an interrupt request.
* @implements     IntCtrl_Ip_IrqConfigType_typedef
*/
typedef struct
{
    /** @brief Interrupt number */
    IRQn_Type IrqNumber;
    /** @brief Interrupt state (enabled/disabled) */
    boolean IrqEnabled;
    /** @brief Interrupt priority */
    uint8 PreemptionPriority;
    uint8 SubPriority;
}PlatformIntCtrl_IrqConfigType;

/**
* @brief          Structure storing the list of state configurations for all configured interrupts.
* @implements     IntCtrl_Ip_CtrlConfigType_typedef
*/
typedef struct
{
    /** @brief Number of configured interrupts */
    uint32 ConfigIrqCount;
    /** @brief List of interrupts configurations */
    TT_CONST PlatformIntCtrl_IrqConfigType *IrqConfig;
}Platform_Hw_IntCtrlConfigType;

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 

/* Definition of the configuration structure for Platform IPW */
extern TT_CONST Platform_Hw_IntCtrlConfigType PlatformIntCtrl_ConfigData;

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_HW_INTCTRL_TYPES_H */
