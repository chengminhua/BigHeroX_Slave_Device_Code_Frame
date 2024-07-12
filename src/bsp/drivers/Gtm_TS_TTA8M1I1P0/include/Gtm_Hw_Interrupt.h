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
**  FILENAME     : Gtm_Hw_Interrupt.h                                         **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Gtm Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef GTM_HW_INTERRUPT_H
#define GTM_HW_INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Interrupt_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_INTERRUPT_VENDOR_ID_H                      1541
#define GTM_HW_INTERRUPT_MODULE_ID_H                      221
#define GTM_HW_INTERRUPT_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_INTERRUPT_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_INTERRUPT_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_INTERRUPT_SW_MAJOR_VERSION_H               1
#define GTM_HW_INTERRUPT_SW_MINOR_VERSION_H               1
#define GTM_HW_INTERRUPT_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Interrupt_Types.h Gtm_Hw_Interrupt.h file version check */
#if (GTM_HW_INTERRUPT_TYPES_VENDOR_ID_H != GTM_HW_INTERRUPT_VENDOR_ID_H)
    #error "Gtm_Hw_Interrupt_Types.h and Gtm_Hw_Interrupt.h have different vendor ids"
#endif

#if (GTM_HW_INTERRUPT_TYPES_MODULE_ID_H != GTM_HW_INTERRUPT_MODULE_ID_H)
    #error "Gtm_Hw_Interrupt_Types.h and Gtm_Hw_Interrupt.h have different module ids"
#endif

#if ((GTM_HW_INTERRUPT_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_INTERRUPT_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_INTERRUPT_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_INTERRUPT_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_INTERRUPT_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_INTERRUPT_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Interrupt_Types.h and Gtm_Hw_Interrupt.h are different"
#endif

#if ((GTM_HW_INTERRUPT_TYPES_SW_MAJOR_VERSION_H != GTM_HW_INTERRUPT_SW_MAJOR_VERSION_H) || \
     (GTM_HW_INTERRUPT_TYPES_SW_MINOR_VERSION_H != GTM_HW_INTERRUPT_SW_MINOR_VERSION_H) || \
     (GTM_HW_INTERRUPT_TYPES_SW_PATCH_VERSION_H != GTM_HW_INTERRUPT_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Interrupt_Types.h and Gtm_Hw_Interrupt.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/


/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

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
*                            Public Functions
*******************************************************************************/
/**
* @brief        Gtm_Hw_Interrupt_TimIntInit
* @details      Initialize interrupt configuration
* @param[in]    void
* @return       void
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_TimIntInit(void);

/**
* @brief        Gtm_Hw_Interrupt_TimIntInitCheck
* @details      Initialize interrupt configuration check
* @param[in]    void
* @return       void
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_TimIntInitCheck(void);

/**
* @brief        Gtm_Hw_Interrupt_TomIntInit
* @details      Initialize interrupt configuration
* @param[in]    void
* @return       void
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_TomIntInit(void);

/**
* @brief        Gtm_Hw_Interrupt_TomIntInitCheck
* @details      Initialize interrupt configuration check
* @param[in]    void
* @return       void
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_TomIntInitCheck(void);


/*************** Tom0 channel 0-1 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_0_IRQHandler);
#endif /* TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE */

/*************** Tom0 channel 2-3 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_1_IRQHandler);
#endif /* TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE */

/*************** Tom0 channel 4-5 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_2_IRQHandler);
#endif /* TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE */

/*************** Tom0 channel 6-7 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_3_IRQHandler);
#endif /* TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE */

/*************** Tom0 channel 8-9 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_4_IRQHandler);
#endif /* TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE */

/*************** Tom0 channel 10-11 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_5_IRQHandler);
#endif /* TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE */

/*************** Tom0 channel 12-13 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_6_IRQHandler);
#endif /* TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE */

/*************** Tom0 channel 14-15 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_7_IRQHandler);
#endif /* TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE */

/*************** Tom1 channel 0-1 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_0_IRQHandler);
#endif /* TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE */

/*************** Tom1 channel 2-3 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_1_IRQHandler);
#endif /* TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE */

/*************** Tom1 channel 4-5 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_2_IRQHandler);
#endif /* TT_GTM_TOM1_CH2_INTERRUPT_ENABLE */

/*************** Tom1 channel 6-7 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_3_IRQHandler);
#endif /* TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE */

/*************** Tom1 channel 8-9 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_4_IRQHandler);
#endif /* TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE */

/*************** Tom1 channel 10-11 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_5_IRQHandler);
#endif /* TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE */

/*************** Tom1 channel 12-13 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_6_IRQHandler);
#endif /* TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE */

/*************** Tom1 channel 14-15 interrupt handler declaration ***************/
#if (defined(TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_7_IRQHandler);
#endif /* TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE */

/*************** Tim0 channel 0 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH0_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_0_IRQHandler);
#endif /* TT_GTM_TIM0_CH0_INTERRUPT_ENABLE */

/*************** Tim0 channel 1 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_1_IRQHandler);
#endif /* TT_GTM_TIM0_CH1_INTERRUPT_ENABLE */

/*************** Tim0 channel 2 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH2_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_2_IRQHandler);
#endif /* TT_GTM_TIM0_CH2_INTERRUPT_ENABLE */

/*************** Tim0 channel 3 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_3_IRQHandler);
#endif /* TT_GTM_TIM0_CH3_INTERRUPT_ENABLE */

/*************** Tim0 channel 4 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH4_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_4_IRQHandler);
#endif /* TT_GTM_TIM0_CH4_INTERRUPT_ENABLE */

/*************** Tim0 channel 5 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_5_IRQHandler);
#endif /* TT_GTM_TIM0_CH5_INTERRUPT_ENABLE */

/*************** Tim0 channel 6 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH6_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_6_IRQHandler);
#endif /* TT_GTM_TIM0_CH6_INTERRUPT_ENABLE */

/*************** Tim0 channel 7 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_7_IRQHandler);
#endif /* TT_GTM_TIM0_CH7_INTERRUPT_ENABLE */

/*************** Tim1 channel 0 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH0_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_0_IRQHandler);
#endif /* TT_GTM_TIM1_CH0_INTERRUPT_ENABLE */

/*************** Tim1 channel 1 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_1_IRQHandler);
#endif /* TT_GTM_TIM1_CH1_INTERRUPT_ENABLE */

/*************** Tim1 channel 2 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH2_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_2_IRQHandler);
#endif /* TT_GTM_TIM1_CH2_INTERRUPT_ENABLE */

/*************** Tim1 channel 3 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_3_IRQHandler);
#endif /* TT_GTM_TIM1_CH3_INTERRUPT_ENABLE */

/*************** Tim1 channel 4 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH4_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_4_IRQHandler);
#endif /* TT_GTM_TIM1_CH4_INTERRUPT_ENABLE */

/*************** Tim1 channel 5 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_5_IRQHandler);
#endif /* TT_GTM_TIM1_CH5_INTERRUPT_ENABLE */

/*************** Tim1 channel 6 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH6_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_6_IRQHandler);
#endif /* TT_GTM_TIM1_CH6_INTERRUPT_ENABLE */

/*************** Tim1 channel 7 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_7_IRQHandler);
#endif /* TT_GTM_TIM1_CH7_INTERRUPT_ENABLE */

/*************** Tim2 channel 0 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM2_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH0_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_0_IRQHandler);
#endif /* TT_GTM_TIM2_CH0_INTERRUPT_ENABLE */

/*************** Tim2 channel 1 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM2_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_1_IRQHandler);
#endif /* TT_GTM_TIM2_CH1_INTERRUPT_ENABLE */

/*************** Tim2 channel 2 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM2_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH2_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_2_IRQHandler);
#endif /* TT_GTM_TIM2_CH2_INTERRUPT_ENABLE */

/*************** Tim2 channel 3 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_3_IRQHandler);
#endif /* TT_GTM_TIM2_CH3_INTERRUPT_ENABLE */

/*************** Tim2 channel 4 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM2_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH4_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_4_IRQHandler);
#endif /* TT_GTM_TIM2_CH4_INTERRUPT_ENABLE */

/*************** Tim2 channel 5 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM2_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_5_IRQHandler);
#endif /* TT_GTM_TIM2_CH5_INTERRUPT_ENABLE */

/*************** Tim2 channel 6 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM2_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH6_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_6_IRQHandler);
#endif /* TT_GTM_TIM2_CH6_INTERRUPT_ENABLE */

/*************** Tim2 channel 7 interrupt handler declaration ***************/
#if (defined(TT_GTM_TIM2_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_7_IRQHandler);
#endif /* TT_GTM_TIM2_CH7_INTERRUPT_ENABLE */

#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */
