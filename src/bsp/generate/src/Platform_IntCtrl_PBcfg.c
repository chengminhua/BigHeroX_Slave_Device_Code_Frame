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
**  FILENAME     : Platform_IntCtrl_PBcfg.c                                   **
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

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Hw_IntCtrl_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_INTCTRL_PBCFG_VENDOR_ID_C                     (1541U)
#define PLATFORM_INTCTRL_PBCFG_MODULE_ID_C                     (219U)
#define PLATFORM_INTCTRL_PBCFG_INSTANCE_ID_C                   (0U)
#define PLATFORM_INTCTRL_PBCFG_AR_RELEASE_MAJOR_VERSION_C      (4U)
#define PLATFORM_INTCTRL_PBCFG_AR_RELEASE_MINOR_VERSION_C      (4U)
#define PLATFORM_INTCTRL_PBCFG_AR_RELEASE_PATCH_VERSION_C      (0U)
#define PLATFORM_INTCTRL_PBCFG_SW_MAJOR_VERSION_C              (1U)
#define PLATFORM_INTCTRL_PBCFG_SW_MINOR_VERSION_C              (1U)
#define PLATFORM_INTCTRL_PBCFG_SW_PATCH_VERSION_C              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_IntCtrl_PBcfg.c and Platform_Hw_IntCtrl_Types file version check */
#if (PLATFORM_INTCTRL_PBCFG_VENDOR_ID_C != PLATFORM_HW_INTCTRL_TYPES_VENDOR_ID_H)
    #error "Platform_IntCtrl_PBcfg.c and Platform_Hw_IntCtrl_Types.h have different vendor id"
#endif
#if (PLATFORM_INTCTRL_PBCFG_MODULE_ID_C != PLATFORM_HW_INTCTRL_TYPES_MODULE_ID_H)
    #error "Platform_IntCtrl_PBcfg.c and Platform_Hw_IntCtrl_Types.h have different module id"
#endif
#if ((PLATFORM_INTCTRL_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_INTCTRL_PBCFG_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_INTCTRL_PBCFG_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_IntCtrl_PBcfg.c and Platform_Hw_IntCtrl_Types.h are different"
#endif
#if ((PLATFORM_INTCTRL_PBCFG_SW_MAJOR_VERSION_C != PLATFORM_HW_INTCTRL_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_INTCTRL_PBCFG_SW_MINOR_VERSION_C != PLATFORM_HW_INTCTRL_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_INTCTRL_PBCFG_SW_PATCH_VERSION_C != PLATFORM_HW_INTCTRL_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_IntCtrl_PBcfg.c and Platform_Hw_IntCtrl_Types.h are different"
#endif


/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/

/******************************************************************************
*                            Public Constants
*******************************************************************************/

#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 

/* List of configurations for interrupts */
/* Interrupt number  
 * Interrupt state (enabled/disabled) 
 * Interrupt PreemptionPriority 
 * Interrupt SubPriority */
static TT_CONST PlatformIntCtrl_IrqConfigType aIrqConfiguration[] = {
    {CTI0_IRQn, FALSE, 0U, 0U},
    {CTI1_IRQn, FALSE, 0U, 0U},
    {SMU0_IRQn, FALSE, 0U, 0U},
    {SHDN_IRQn, TRUE, 2U, 2U},
    {ENDINIT_IRQn, FALSE, 0U, 0U},
    {PMU_IRQn, FALSE, 0U, 0U},
    {DFCU_IRQn, FALSE, 0U, 0U},
    {PFCU_IRQn, FALSE, 0U, 0U},
    {DEBUG_IRQn, FALSE, 0U, 0U},
    {CRC_IRQn, FALSE, 0U, 0U},
    {WWDT_IRQn, FALSE, 0U, 0U},
    {ADCSENSOR_IRQn, FALSE, 0U, 0U},
    {MAILBOX_IRQn, FALSE, 0U, 0U},
    {PKI_IRQn, FALSE, 0U, 0U},
    {SM4_IRQn, FALSE, 0U, 0U},
    {HASH_IRQn, FALSE, 0U, 0U},
    {SKA_IRQn, FALSE, 0U, 0U},
    {TRNG_IRQn, FALSE, 0U, 0U},
    {GPDMA0_COMBINE_IRQn, TRUE, 2U, 2U},
    {GPDMA1_COMBINE_IRQn, FALSE, 2U, 2U},
    {GPDMA2_COMBINE_IRQn, FALSE, 0U, 0U},
    {GPDMA3_COMBINE_IRQn, FALSE, 0U, 0U},
    {PDB0_IRQn, FALSE, 0U, 0U},
    {PDB0_ERR_IRQn, FALSE, 0U, 0U},
    {PDB1_IRQn, FALSE, 0U, 0U},
    {PDB1_ERR_IRQn, FALSE, 0U, 0U},
    {ADC0_IRQn, TRUE, 1U, 1U},
    {ADC1_IRQn, TRUE, 1U, 1U},
    {ADC2_IRQn, TRUE, 1U, 1U},
    {ADC3_IRQn, FALSE, 0U, 0U},
    {ADC4_IRQn, FALSE, 0U, 0U},
    {ADC5_IRQn, FALSE, 0U, 0U},
    {SENT0_IRQn, FALSE, 0U, 0U},
    {SENT1_IRQn, FALSE, 0U, 0U},
    {SENT2_IRQn, FALSE, 0U, 0U},
    {SENT3_IRQn, FALSE, 0U, 0U},
    {SENT4_IRQn, FALSE, 0U, 0U},
    {SENT5_IRQn, FALSE, 0U, 0U},
    {SENT6_IRQn, FALSE, 0U, 0U},
    {SENT7_IRQn, FALSE, 0U, 0U},
    {QSPI0_IRQn, FALSE, 0U, 0U},
    {ENET_LPI_IRQn, FALSE, 0U, 0U},
    {ENET_SBD_IRQn, TRUE, 2U, 2U},
    {ENET_PMT_IRQn, FALSE, 0U, 0U},
    {UART0_COMBINE_IRQn, FALSE, 0U, 0U},
    {UART1_COMBINE_IRQn, TRUE, 0U, 0U},
    {UART2_COMBINE_IRQn, TRUE, 0U, 0U},
    {UART3_COMBINE_IRQn, FALSE, 0U, 0U},
    {LIN0_IRQn, TRUE, 2U, 2U},
    {LIN1_IRQn, FALSE, 0U, 0U},
    {LIN2_IRQn, FALSE, 0U, 0U},
    {LIN3_IRQn, FALSE, 0U, 0U},
    {LIN4_IRQn, FALSE, 0U, 0U},
    {LIN5_IRQn, FALSE, 0U, 0U},
    {LIN6_IRQn, FALSE, 0U, 0U},
    {LIN7_IRQn, FALSE, 0U, 0U},
    {LIN8_IRQn, FALSE, 0U, 0U},
    {LIN9_IRQn, FALSE, 0U, 0U},
    {LIN10_IRQn, FALSE, 0U, 0U},
    {LIN11_IRQn, FALSE, 0U, 0U},
    {LIN12_IRQn, FALSE, 0U, 0U},
    {LIN13_IRQn, FALSE, 0U, 0U},
    {LIN14_IRQn, FALSE, 0U, 0U},
    {LIN15_IRQn, FALSE, 0U, 0U},
    {I2C0_IRQn, TRUE, 2U, 2U},
    {I2C1_IRQn, FALSE, 0U, 0U},
    {I3C0_IRQn, TRUE, 2U, 2U},
    {SSP0_COMBINE_IRQn, TRUE, 2U, 2U},
    {SSP1_COMBINE_IRQn, FALSE, 0U, 0U},
    {SSP2_COMBINE_IRQn, FALSE, 0U, 0U},
    {SSP3_COMBINE_IRQn, TRUE, 2U, 2U},
    {SSP4_COMBINE_IRQn, FALSE, 0U, 0U},
    {SSP5_COMBINE_IRQn, FALSE, 0U, 0U},
    {SSP6_COMBINE_IRQn, FALSE, 0U, 0U},
    {SSP7_COMBINE_IRQn, FALSE, 0U, 0U},
    {GPIOA_IRQn, FALSE, 0U, 0U},
    {GPIOB_IRQn, FALSE, 0U, 0U},
    {GPIOC_IRQn, FALSE, 0U, 0U},
    {GPIOD_IRQn, FALSE, 0U, 0U},
    {GPIOE_IRQn, FALSE, 0U, 0U},
    {I2S0_IRQn, FALSE, 0U, 0U},
    {CAN_Busoff0_IRQn, FALSE, 1U, 1U},
    {CAN_Error0_IRQn, FALSE, 1U, 1U},
    {CAN_Mbor0_IRQn, FALSE, 1U, 1U},
    {CAN_EnhancedRxFifo0_IRQn, FALSE, 0U, 0U},
    {CAN_TXRX_Warnning0_IRQn, FALSE, 1U, 1U},
    {CAN_Wakeup0_IRQn, FALSE, 0U, 0U},
    {CAN_Busoff1_IRQn, TRUE, 1U, 1U},
    {CAN_Error1_IRQn, TRUE, 1U, 1U},
    {CAN_Mbor1_IRQn, TRUE, 1U, 1U},
    {CAN_EnhancedRxFifo1_IRQn, FALSE, 0U, 0U},
    {CAN_TXRX_Warnning1_IRQn, TRUE, 1U, 1U},
    {CAN_Wakeup1_IRQn, FALSE, 0U, 0U},
    {CAN_Busoff2_IRQn, TRUE, 1U, 1U},
    {CAN_Error2_IRQn, TRUE, 1U, 1U},
    {CAN_Mbor2_IRQn, TRUE, 1U, 1U},
    {CAN_EnhancedRxFifo2_IRQn, FALSE, 0U, 0U},
    {CAN_TXRX_Warnning2_IRQn, TRUE, 1U, 1U},
    {CAN_Wakeup2_IRQn, FALSE, 0U, 0U},
    {CAN_Busoff3_IRQn, FALSE, 0U, 0U},
    {CAN_Error3_IRQn, FALSE, 0U, 0U},
    {CAN_Mbor3_IRQn, FALSE, 0U, 0U},
    {CAN_EnhancedRxFifo3_IRQn, FALSE, 0U, 0U},
    {CAN_TXRX_Warnning3_IRQn, FALSE, 0U, 0U},
    {CAN_Wakeup3_IRQn, FALSE, 0U, 0U},
    {CAN_Busoff4_IRQn, TRUE, 1U, 1U},
    {CAN_Error4_IRQn, TRUE, 1U, 1U},
    {CAN_Mbor4_IRQn, TRUE, 1U, 1U},
    {CAN_EnhancedRxFifo4_IRQn, FALSE, 0U, 0U},
    {CAN_TXRX_Warnning4_IRQn, TRUE, 1U, 1U},
    {CAN_Wakeup4_IRQn, FALSE, 0U, 0U},
    {CAN_Busoff5_IRQn, FALSE, 1U, 1U},
    {CAN_Error5_IRQn, FALSE, 1U, 1U},
    {CAN_Mbor5_IRQn, FALSE, 1U, 1U},
    {CAN_EnhancedRxFifo5_IRQn, FALSE, 0U, 0U},
    {CAN_TXRX_Warnning5_IRQn, FALSE, 1U, 1U},
    {CAN_Wakeup5_IRQn, FALSE, 0U, 0U},
    {CAN_Busoff6_IRQn, FALSE, 1U, 1U},
    {CAN_Error6_IRQn, FALSE, 1U, 1U},
    {CAN_Mbor6_IRQn, FALSE, 1U, 1U},
    {CAN_EnhancedRxFifo6_IRQn, FALSE, 0U, 0U},
    {CAN_TXRX_Warnning6_IRQn, FALSE, 1U, 1U},
    {CAN_Wakeup6_IRQn, FALSE, 0U, 0U},
    {CAN_Busoff7_IRQn, FALSE, 0U, 0U},
    {CAN_Error7_IRQn, FALSE, 0U, 0U},
    {CAN_Mbor7_IRQn, FALSE, 0U, 0U},
    {CAN_EnhancedRxFifo7_IRQn, FALSE, 0U, 0U},
    {CAN_TXRX_Warnning7_IRQn, FALSE, 0U, 0U},
    {CAN_Wakeup7_IRQn, FALSE, 0U, 0U},
    {STM0_IRQn, FALSE, 0U, 0U},
    {STM1_IRQn, FALSE, 0U, 0U},
    {FTM0_IRQn, FALSE, 0U, 0U},
    {FTM1_IRQn, TRUE, 3U, 1U},
    {FTM2_IRQn, FALSE, 0U, 0U},
    {FTM3_IRQn, FALSE, 0U, 0U},
    {FTM4_IRQn, FALSE, 0U, 0U},
    {FTM5_IRQn, FALSE, 0U, 0U},
    {GTM_ATOM3_IRQn, FALSE, 0U, 0U},
    {GTM_ATOM2_IRQn, FALSE, 0U, 0U},
    {GTM_ATOM1_IRQn, FALSE, 0U, 0U},
    {GTM_ATOM0_IRQn, FALSE, 0U, 0U},
    {GTM_TIO3_G1_HO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO3_G1_LO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO2_G1_HO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO2_G1_HL_IRQn, FALSE, 0U, 0U},
    {GTM_TIO1_G1_HO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO1_G1_HL_IRQn, FALSE, 0U, 0U},
    {GTM_TIO0_G1_HO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO0_G1_HL_IRQn, FALSE, 0U, 0U},
    {GTM_TIO3_G0_HO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO3_G0_LO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO2_G0_HO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO2_G0_HL_IRQn, FALSE, 0U, 0U},
    {GTM_TIO1_G0_HO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO1_G0_HL_IRQn, FALSE, 0U, 0U},
    {GTM_TIO0_G0_HO_IRQn, FALSE, 0U, 0U},
    {GTM_TIO0_G0_HL_IRQn, FALSE, 0U, 0U},
    {GTM_MCS2_S_HO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS2_S_LO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS1_S_HO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS1_S_LO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS0_S_HO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS0_S_LO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS2_HO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS2_LO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS1_HO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS1_LO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS0_HO_IRQn, FALSE, 0U, 0U},
    {GTM_MCS0_LO_IRQn, FALSE, 0U, 0U},
    {GTM_PSM_HO_IRQn, FALSE, 0U, 0U},
    {GTM_PSM_LO_IRQn, FALSE, 0U, 0U},
    {GTM_DPLL_HO_IRQn, FALSE, 0U, 0U},
    {GTM_DPLL_LO_IRQn, FALSE, 0U, 0U},
    {GTM_SPE1_IRQn, FALSE, 0U, 0U},
    {GTM_SPE0_IRQn, FALSE, 0U, 0U},
    {GTM_CMP_IRQn, FALSE, 0U, 0U},
    {GTM_BRC_IRQn, FALSE, 0U, 0U},
    {GTM_ARU_IRQn, FALSE, 0U, 0U},
    {GTM_AEI_IRQn, FALSE, 0U, 0U},
    {GTM_ERR_IRQn, FALSE, 0U, 0U},
    {GTM_TIM0_0_IRQn, FALSE, 0U, 0U},
    {GTM_TIM0_1_IRQn, FALSE, 0U, 0U},
    {GTM_TIM0_2_IRQn, FALSE, 0U, 0U},
    {GTM_TIM0_3_IRQn, FALSE, 0U, 0U},
    {GTM_TIM0_4_IRQn, FALSE, 0U, 0U},
    {GTM_TIM0_5_IRQn, FALSE, 0U, 0U},
    {GTM_TIM0_6_IRQn, FALSE, 0U, 0U},
    {GTM_TIM0_7_IRQn, FALSE, 0U, 0U},
    {GTM_TIM1_0_IRQn, FALSE, 0U, 0U},
    {GTM_TIM1_1_IRQn, FALSE, 0U, 0U},
    {GTM_TIM1_2_IRQn, FALSE, 0U, 0U},
    {GTM_TIM1_3_IRQn, FALSE, 0U, 0U},
    {GTM_TIM1_4_IRQn, FALSE, 0U, 0U},
    {GTM_TIM1_5_IRQn, FALSE, 0U, 0U},
    {GTM_TIM1_6_IRQn, FALSE, 0U, 0U},
    {GTM_TIM1_7_IRQn, FALSE, 0U, 0U},
    {GTM_TIM2_0_IRQn, FALSE, 0U, 0U},
    {GTM_TIM2_1_IRQn, FALSE, 0U, 0U},
    {GTM_TIM2_2_IRQn, FALSE, 0U, 0U},
    {GTM_TIM2_3_IRQn, FALSE, 0U, 0U},
    {GTM_TIM2_4_IRQn, FALSE, 0U, 0U},
    {GTM_TIM2_5_IRQn, FALSE, 0U, 0U},
    {GTM_TIM2_6_IRQn, FALSE, 0U, 0U},
    {GTM_TIM2_7_IRQn, FALSE, 0U, 0U},
    {GTM_TOM0_0_IRQn, FALSE, 0U, 0U},
    {GTM_TOM0_1_IRQn, FALSE, 0U, 0U},
    {GTM_TOM0_2_IRQn, FALSE, 0U, 0U},
    {GTM_TOM0_3_IRQn, FALSE, 0U, 0U},
    {GTM_TOM0_4_IRQn, FALSE, 0U, 0U},
    {GTM_TOM0_5_IRQn, FALSE, 0U, 0U},
    {GTM_TOM0_6_IRQn, FALSE, 0U, 0U},
    {GTM_TOM0_7_IRQn, FALSE, 0U, 0U},
    {GTM_TOM1_0_IRQn, FALSE, 0U, 0U},
    {GTM_TOM1_1_IRQn, FALSE, 0U, 0U},
    {GTM_TOM1_2_IRQn, FALSE, 0U, 0U},
    {GTM_TOM1_3_IRQn, FALSE, 0U, 0U},
    {GTM_TOM1_4_IRQn, FALSE, 0U, 0U},
    {GTM_TOM1_5_IRQn, FALSE, 0U, 0U},
    {GTM_TOM1_6_IRQn, FALSE, 0U, 0U},
    {GTM_TOM1_7_IRQn, FALSE, 0U, 0U}
};

/* Configuration structure for interrupt controller */
TT_CONST Platform_Hw_IntCtrlConfigType PlatformIntCtrl_ConfigData = {
    .ConfigIrqCount = 220U,
    .IrqConfig      = aIrqConfiguration
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus /* __cplusplus */ 
}
#endif
