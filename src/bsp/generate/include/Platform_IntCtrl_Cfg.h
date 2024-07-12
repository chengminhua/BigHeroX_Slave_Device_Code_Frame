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
**  FILENAME     : Platform_IntCtrl_Cfg.h                                     **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Configuration Generated File               **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef PLATFORM_INTCTRL_IP_CFG_H_
#define PLATFORM_INTCTRL_IP_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_SCB.h"
#include "A8V2E_NVIC.h"
#include "A8V2E_FPU.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_INTCTRL_CFG_VENDOR_ID_H                     (1541U)
#define PLATFORM_INTCTRL_CFG_MODULE_ID_H                     (219U)
#define PLATFORM_INTCTRL_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define PLATFORM_INTCTRL_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define PLATFORM_INTCTRL_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define PLATFORM_INTCTRL_CFG_SW_MAJOR_VERSION_H              (1U)
#define PLATFORM_INTCTRL_CFG_SW_MINOR_VERSION_H              (1U)
#define PLATFORM_INTCTRL_CFG_SW_PATCH_VERSION_H              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_IntCtrl_Cfg.h and A8V2E_SCB.h file version check */
#if (PLATFORM_INTCTRL_CFG_VENDOR_ID_H != A8V2E_SCB_VENDOR_ID_H)
    #error "Platform_IntCtrl_Cfg.h and A8V2E_SCB.h have different vendor id"
#endif
#if ((PLATFORM_INTCTRL_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_SCB_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_SCB_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_SCB_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_IntCtrl_Cfg.h and A8V2E_SCB.h are different"
#endif
#if ((PLATFORM_INTCTRL_CFG_SW_MAJOR_VERSION_H != A8V2E_SCB_SW_MAJOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_SW_MINOR_VERSION_H != A8V2E_SCB_SW_MINOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_SW_PATCH_VERSION_H != A8V2E_SCB_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_IntCtrl_Cfg.h and A8V2E_SCB.h are different"
#endif

/* Platform_IntCtrl_Cfg.h and A8V2E_NVIC.h file version check */
#if (PLATFORM_INTCTRL_CFG_VENDOR_ID_H != A8V2E_NVIC_VENDOR_ID_H)
    #error "Platform_IntCtrl_Cfg.h and A8V2E_NVIC.h have different vendor id"
#endif
#if ((PLATFORM_INTCTRL_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_NVIC_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_NVIC_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_NVIC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_IntCtrl_Cfg.h and A8V2E_NVIC.h are different"
#endif
#if ((PLATFORM_INTCTRL_CFG_SW_MAJOR_VERSION_H != A8V2E_NVIC_SW_MAJOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_SW_MINOR_VERSION_H != A8V2E_NVIC_SW_MINOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_SW_PATCH_VERSION_H != A8V2E_NVIC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_IntCtrl_Cfg.h and A8V2E_NVIC.h are different"
#endif

/* Platform_IntCtrl_Cfg.h and A8V2E_FPU.h file version check */
#if (PLATFORM_INTCTRL_CFG_VENDOR_ID_H != A8V2E_FPU_VENDOR_ID_H)
    #error "Platform_IntCtrl_Cfg.h and A8V2E_FPU.h have different vendor id"
#endif
#if ((PLATFORM_INTCTRL_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_FPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_FPU_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_FPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_IntCtrl_Cfg.h and A8V2E_FPU.h are different"
#endif
#if ((PLATFORM_INTCTRL_CFG_SW_MAJOR_VERSION_H != A8V2E_FPU_SW_MAJOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_SW_MINOR_VERSION_H != A8V2E_FPU_SW_MINOR_VERSION_H) || \
     (PLATFORM_INTCTRL_CFG_SW_PATCH_VERSION_H != A8V2E_FPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_IntCtrl_Cfg.h and A8V2E_FPU.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/ 
/* First implemented interrupt vector */
#define PLATFORM_INT_CTRL_IRQ_MIN                           (CTI0_IRQn)

/* Last implemented interrupt vector */
#define PLATFORM_INT_CTRL_IRQ_MAX                           ( GTM_TOM1_7_IRQn)

/* The interrupt counter value*/
#define PLATFORM_INT_CTRL_IRQ_COUNT                         (220U)

/* Number of priority bits implemented */
#define PLATFORM_INT_CTRL_NVIC_PRIO_BITS                    (8U)

/* Number of Group bits implemented */
#define PLATFORM_INT_CTRL_GROUP_BITS                        (4U)

/* FPU Enable */
#define PLATFORM_DISABLE_FPU                                (STD_OFF)

/* I-Cache Enable */
#define PLATFORM_I_CACHE_ENABLE                             (STD_ON)

/* D-Cache Enable */
#define PLATFORM_D_CACHE_ENABLE                             (STD_ON)

/* Divide Zero Hardfault Enable */
#define PLATFORM_DIVZEROHARDFAULTENABLE                     (STD_ON)

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
/* Declaration of interrupt handlers
 * NOTE: For application specific handlers, these functions must be implemented in the application code!
 */
extern void    CTI0_IRQHandler(void);
extern void    CTI1_IRQHandler(void);
extern void    SMU0_IRQHandler(void);
extern void    SHDN_IRQHandler(void);
extern void    ENDINIT_IRQHandler(void);
extern void    PMU_IRQHandler(void);
extern void    DFCU_IRQHandler(void);
extern void    PFCU_IRQHandler(void);
extern void    DEBUG_IRQHandler(void);
extern void    CRC_IRQHandler(void);
extern void    WWDT_IRQHandler(void);
extern void    ADCSENSOR_IRQHandler(void);
extern void    MAILBOX_IRQHandler(void);
extern void    PKI_IRQHandler(void);
extern void    SM4_IRQHandler(void);
extern void    HASH_IRQHandler(void);
extern void    SKA_IRQHandler(void);
extern void    TRNG_IRQHandler(void);
extern void    GPDMA0_COMBINE_IRQHandler(void);
extern void    GPDMA1_COMBINE_IRQHandler(void);
extern void    GPDMA2_COMBINE_IRQHandler(void);
extern void    GPDMA3_COMBINE_IRQHandler(void);
extern void    PDB0_IRQHandler(void);
extern void    PDB0_ERR_IRQHandler(void);
extern void    PDB1_IRQHandler(void);
extern void    PDB1_ERR_IRQHandler(void);
extern void    ADC0_IRQHandler(void);
extern void    ADC1_IRQHandler(void);
extern void    ADC2_IRQHandler(void);
extern void    ADC3_IRQHandler(void);
extern void    ADC4_IRQHandler(void);
extern void    ADC5_IRQHandler(void);
extern void    SENT0_IRQHandler(void);
extern void    SENT1_IRQHandler(void);
extern void    SENT2_IRQHandler(void);
extern void    SENT3_IRQHandler(void);
extern void    SENT4_IRQHandler(void);
extern void    SENT5_IRQHandler(void);
extern void    SENT6_IRQHandler(void);
extern void    SENT7_IRQHandler(void);
extern void    QSPI0_IRQHandler(void);
extern void    ENET_LPI_IRQHandler(void);
extern void    ENET_SBD_IRQHandler(void);
extern void    ENET_PMT_IRQHandler(void);
extern void    UART0_COMBINE_IRQHandler(void);
extern void    UART1_COMBINE_IRQHandler(void);
extern void    UART2_COMBINE_IRQHandler(void);
extern void    UART3_COMBINE_IRQHandler(void);
extern void    LIN0_IRQHandler(void);
extern void    LIN1_IRQHandler(void);
extern void    LIN2_IRQHandler(void);
extern void    LIN3_IRQHandler(void);
extern void    LIN4_IRQHandler(void);
extern void    LIN5_IRQHandler(void);
extern void    LIN6_IRQHandler(void);
extern void    LIN7_IRQHandler(void);
extern void    LIN8_IRQHandler(void);
extern void    LIN9_IRQHandler(void);
extern void    LIN10_IRQHandler(void);
extern void    LIN11_IRQHandler(void);
extern void    LIN12_IRQHandler(void);
extern void    LIN13_IRQHandler(void);
extern void    LIN14_IRQHandler(void);
extern void    LIN15_IRQHandler(void);
extern void    I2C0_IRQHandler(void);
extern void    I2C1_IRQHandler(void);
extern void    I3C0_IRQHandler(void);
extern void    SSP0_COMBINE_IRQHandler(void);
extern void    SSP1_COMBINE_IRQHandler(void);
extern void    SSP2_COMBINE_IRQHandler(void);
extern void    SSP3_COMBINE_IRQHandler(void);
extern void    SSP4_COMBINE_IRQHandler(void);
extern void    SSP5_COMBINE_IRQHandler(void);
extern void    SSP6_COMBINE_IRQHandler(void);
extern void    SSP7_COMBINE_IRQHandler(void);
extern void    GPIOA_IRQHandler(void);
extern void    GPIOB_IRQHandler(void);
extern void    GPIOC_IRQHandler(void);
extern void    GPIOD_IRQHandler(void);
extern void    GPIOE_IRQHandler(void);
extern void    I2S0_IRQHandler(void);
extern void    CAN_Busoff0_IRQHandler(void);
extern void    CAN_Error0_IRQHandler(void);
extern void    CAN_Mbor0_IRQHandler(void);
extern void    CAN_EnhancedRxFifo0_IRQHandler(void);
extern void    CAN_TXRX_Warnning0_IRQHandler(void);
extern void    CAN_Wakeup0_IRQHandler(void);
extern void    CAN_Busoff1_IRQHandler(void);
extern void    CAN_Error1_IRQHandler(void);
extern void    CAN_Mbor1_IRQHandler(void);
extern void    CAN_EnhancedRxFifo1_IRQHandler(void);
extern void    CAN_TXRX_Warnning1_IRQHandler(void);
extern void    CAN_Wakeup1_IRQHandler(void);
extern void    CAN_Busoff2_IRQHandler(void);
extern void    CAN_Error2_IRQHandler(void);
extern void    CAN_Mbor2_IRQHandler(void);
extern void    CAN_EnhancedRxFifo2_IRQHandler(void);
extern void    CAN_TXRX_Warnning2_IRQHandler(void);
extern void    CAN_Wakeup2_IRQHandler(void);
extern void    CAN_Busoff3_IRQHandler(void);
extern void    CAN_Error3_IRQHandler(void);
extern void    CAN_Mbor3_IRQHandler(void);
extern void    CAN_EnhancedRxFifo3_IRQHandler(void);
extern void    CAN_TXRX_Warnning3_IRQHandler(void);
extern void    CAN_Wakeup3_IRQHandler(void);
extern void    CAN_Busoff4_IRQHandler(void);
extern void    CAN_Error4_IRQHandler(void);
extern void    CAN_Mbor4_IRQHandler(void);
extern void    CAN_EnhancedRxFifo4_IRQHandler(void);
extern void    CAN_TXRX_Warnning4_IRQHandler(void);
extern void    CAN_Wakeup4_IRQHandler(void);
extern void    CAN_Busoff5_IRQHandler(void);
extern void    CAN_Error5_IRQHandler(void);
extern void    CAN_Mbor5_IRQHandler(void);
extern void    CAN_EnhancedRxFifo5_IRQHandler(void);
extern void    CAN_TXRX_Warnning5_IRQHandler(void);
extern void    CAN_Wakeup5_IRQHandler(void);
extern void    CAN_Busoff6_IRQHandler(void);
extern void    CAN_Error6_IRQHandler(void);
extern void    CAN_Mbor6_IRQHandler(void);
extern void    CAN_EnhancedRxFifo6_IRQHandler(void);
extern void    CAN_TXRX_Warnning6_IRQHandler(void);
extern void    CAN_Wakeup6_IRQHandler(void);
extern void    CAN_Busoff7_IRQHandler(void);
extern void    CAN_Error7_IRQHandler(void);
extern void    CAN_Mbor7_IRQHandler(void);
extern void    CAN_EnhancedRxFifo7_IRQHandler(void);
extern void    CAN_TXRX_Warnning7_IRQHandler(void);
extern void    CAN_Wakeup7_IRQHandler(void);
extern void    STM0_IRQHandler(void);
extern void    STM1_IRQHandler(void);
extern void    FTM0_IRQHandler(void);
extern void    FTM1_IRQHandler(void);
extern void    FTM2_IRQHandler(void);
extern void    FTM3_IRQHandler(void);
extern void    FTM4_IRQHandler(void);
extern void    FTM5_IRQHandler(void);
extern void    GTM_ATOM3_IRQHandler(void);
extern void    GTM_ATOM2_IRQHandler(void);
extern void    GTM_ATOM1_IRQHandler(void);
extern void    GTM_ATOM0_IRQHandler(void);
extern void    GTM_TIO3_G1_HO_IRQHandler(void);
extern void    GTM_TIO3_G1_LO_IRQHandler(void);
extern void    GTM_TIO2_G1_HO_IRQHandler(void);
extern void    GTM_TIO2_G1_HL_IRQHandler(void);
extern void    GTM_TIO1_G1_HO_IRQHandler(void);
extern void    GTM_TIO1_G1_HL_IRQHandler(void);
extern void    GTM_TIO0_G1_HO_IRQHandler(void);
extern void    GTM_TIO0_G1_HL_IRQHandler(void);
extern void    GTM_TIO3_G0_HO_IRQHandler(void);
extern void    GTM_TIO3_G0_LO_IRQHandler(void);
extern void    GTM_TIO2_G0_HO_IRQHandler(void);
extern void    GTM_TIO2_G0_HL_IRQHandler(void);
extern void    GTM_TIO1_G0_HO_IRQHandler(void);
extern void    GTM_TIO1_G0_HL_IRQHandler(void);
extern void    GTM_TIO0_G0_HO_IRQHandler(void);
extern void    GTM_TIO0_G0_HL_IRQHandler(void);
extern void    GTM_MCS2_S_HO_IRQHandler(void);
extern void    GTM_MCS2_S_LO_IRQHandler(void);
extern void    GTM_MCS1_S_HO_IRQHandler(void);
extern void    GTM_MCS1_S_LO_IRQHandler(void);
extern void    GTM_MCS0_S_HO_IRQHandler(void);
extern void    GTM_MCS0_S_LO_IRQHandler(void);
extern void    GTM_MCS2_HO_IRQHandler(void);
extern void    GTM_MCS2_LO_IRQHandler(void);
extern void    GTM_MCS1_HO_IRQHandler(void);
extern void    GTM_MCS1_LO_IRQHandler(void);
extern void    GTM_MCS0_HO_IRQHandler(void);
extern void    GTM_MCS0_LO_IRQHandler(void);
extern void    GTM_PSM_HO_IRQHandler(void);
extern void    GTM_PSM_LO_IRQHandler(void);
extern void    GTM_DPLL_HO_IRQHandler(void);
extern void    GTM_DPLL_LO_IRQHandler(void);
extern void    GTM_SPE1_IRQHandler(void);
extern void    GTM_SPE0_IRQHandler(void);
extern void    GTM_CMP_IRQHandler(void);
extern void    GTM_BRC_IRQHandler(void);
extern void    GTM_ARU_IRQHandler(void);
extern void    GTM_AEI_IRQHandler(void);
extern void    GTM_ERR_IRQHandler(void);
extern void    GTM_TIM0_0_IRQHandler(void);
extern void    GTM_TIM0_1_IRQHandler(void);
extern void    GTM_TIM0_2_IRQHandler(void);
extern void    GTM_TIM0_3_IRQHandler(void);
extern void    GTM_TIM0_4_IRQHandler(void);
extern void    GTM_TIM0_5_IRQHandler(void);
extern void    GTM_TIM0_6_IRQHandler(void);
extern void    GTM_TIM0_7_IRQHandler(void);
extern void    GTM_TIM1_0_IRQHandler(void);
extern void    GTM_TIM1_1_IRQHandler(void);
extern void    GTM_TIM1_2_IRQHandler(void);
extern void    GTM_TIM1_3_IRQHandler(void);
extern void    GTM_TIM1_4_IRQHandler(void);
extern void    GTM_TIM1_5_IRQHandler(void);
extern void    GTM_TIM1_6_IRQHandler(void);
extern void    GTM_TIM1_7_IRQHandler(void);
extern void    GTM_TIM2_0_IRQHandler(void);
extern void    GTM_TIM2_1_IRQHandler(void);
extern void    GTM_TIM2_2_IRQHandler(void);
extern void    GTM_TIM2_3_IRQHandler(void);
extern void    GTM_TIM2_4_IRQHandler(void);
extern void    GTM_TIM2_5_IRQHandler(void);
extern void    GTM_TIM2_6_IRQHandler(void);
extern void    GTM_TIM2_7_IRQHandler(void);
extern void    GTM_TOM0_0_IRQHandler(void);
extern void    GTM_TOM0_1_IRQHandler(void);
extern void    GTM_TOM0_2_IRQHandler(void);
extern void    GTM_TOM0_3_IRQHandler(void);
extern void    GTM_TOM0_4_IRQHandler(void);
extern void    GTM_TOM0_5_IRQHandler(void);
extern void    GTM_TOM0_6_IRQHandler(void);
extern void    GTM_TOM0_7_IRQHandler(void);
extern void    GTM_TOM1_0_IRQHandler(void);
extern void    GTM_TOM1_1_IRQHandler(void);
extern void    GTM_TOM1_2_IRQHandler(void);
extern void    GTM_TOM1_3_IRQHandler(void);
extern void    GTM_TOM1_4_IRQHandler(void);
extern void    GTM_TOM1_5_IRQHandler(void);
extern void    GTM_TOM1_6_IRQHandler(void);
extern void    GTM_TOM1_7_IRQHandler(void);
/******************************************************************************
*                            Private Functions
******************************************************************************/

/******************************************************************************
*                       Defines Checks
******************************************************************************/
#ifndef PLATFORM_INT_CTRL_IRQ_MIN
    #error "PLATFORM_INT_CTRL_IRQ_MIN Defines error"
#if (PLATFORM_INT_CTRL_IRQ_MIN != CTI0_IRQn)
    #error "PLATFORM_INT_CTRL_IRQ_MIN Defines error"
#endif
#endif

#ifndef PLATFORM_INT_CTRL_IRQ_MAX
    #error "PLATFORM_INT_CTRL_IRQ_MAX Defines error"
#if (PLATFORM_INT_CTRL_IRQ_MAX != GTM_TOM1_7_IRQn)
    #error "PLATFORM_INT_CTRL_IRQ_MAX Defines error"
#endif
#endif

#ifndef PLATFORM_INT_CTRL_IRQ_COUNT
    #error "PLATFORM_INT_CTRL_IRQ_COUNT Defines error"
#if (PLATFORM_INT_CTRL_IRQ_COUNT > 220) ||(PLATFORM_INT_CTRL_IRQ_COUNT != (220U))
    #error "PLATFORM_INT_CTRL_IRQ_COUNT Defines error"
#endif
#endif

#ifndef PLATFORM_INT_CTRL_NVIC_PRIO_BITS
    #error "PLATFORM_INT_CTRL_NVIC_PRIO_BITS Defines error"
#if (PLATFORM_INT_CTRL_NVIC_PRIO_BITS != 8)
    #error "PLATFORM_INT_CTRL_NVIC_PRIO_BITS Defines error"
#endif
#endif

#ifndef PLATFORM_INT_CTRL_GROUP_BITS
    #error "PLATFORM_INT_CTRL_GROUP_BITS Defines error"
#if (PLATFORM_INT_CTRL_GROUP_BITS > 7) || (PLATFORM_INT_CTRL_GROUP_BITS != (4U))
    #error "PLATFORM_INT_CTRL_GROUP_BITS Defines error"
#endif
#endif

#ifndef PLATFORM_DISABLE_FPU
    #error "PLATFORM_DISABLE_FPU Defines error"
#if ((PLATFORM_DISABLE_FPU != STD_OFF) && (PLATFORM_DISABLE_FPU != STD_ON))
    #error "PLATFORM_DISABLE_FPU Defines error"
#endif
#endif

#ifndef PLATFORM_I_CACHE_ENABLE
    #error "PLATFORM_I_CACHE_ENABLE Defines error"
#if ((PLATFORM_I_CACHE_ENABLE != STD_OFF) && (PLATFORM_I_CACHE_ENABLE != STD_ON))
    #error "PLATFORM_I_CACHE_ENABLE Defines error"
#endif
#endif

#ifndef PLATFORM_D_CACHE_ENABLE
    #error "PLATFORM_D_CACHE_ENABLE Defines error"
#if ((PLATFORM_D_CACHE_ENABLE != STD_OFF) && (PLATFORM_D_CACHE_ENABLE != STD_ON))
    #error "PLATFORM_D_CACHE_ENABLE Defines error"
#endif
#endif

#ifndef PLATFORM_DIVZEROHARDFAULTENABLE
    #error "PLATFORM_DIVZEROHARDFAULTENABLE Defines error"
#if ((PLATFORM_DIVZEROHARDFAULTENABLE != STD_OFF) && (PLATFORM_DIVZEROHARDFAULTENABLE != STD_ON))
    #error "PLATFORM_DIVZEROHARDFAULTENABLE Defines error"
#endif
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#endif /* PLATFORM_INTCTRL_IP_CFG_H_ */
