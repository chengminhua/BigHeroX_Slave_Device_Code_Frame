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
**  FILENAME     : Can_Hw_Irq.h                                               **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Can Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef CAN_HW_IRQ_H
#define CAN_HW_IRQ_H


#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Hw.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_IRQ_VENDOR_ID_H                      1541
#define FLEXCAN_HW_IRQ_MODULE_ID_H                      80
#define FLEXCAN_HW_IRQ_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_HW_IRQ_AR_RELEASE_MINOR_VERSION_H       4
#define FLEXCAN_HW_IRQ_AR_RELEASE_PATCH_VERSION_H       0
#define FLEXCAN_HW_IRQ_SW_MAJOR_VERSION_H               1
#define FLEXCAN_HW_IRQ_SW_MINOR_VERSION_H               1
#define FLEXCAN_HW_IRQ_SW_PATCH_VERSION_H               0
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and FlexCAN_Hw_HwAccess header file are of the same vendor */
#if (FLEXCAN_HW_IRQ_VENDOR_ID_H != FLEXCAN_HW_VENDOR_ID_H)
    #error "FlexCAN_Hw_Irq.h and FlexCAN_Hw_HwAccess.h have different vendor ids"
#endif
#if (FLEXCAN_HW_IRQ_MODULE_ID_H != FLEXCAN_HW_MODULE_ID_H)
    #error "FlexCAN_Hw_Irq.h and FlexCAN_Hw_HwAccess.h have different module ids"
#endif
/* Check if current file and FlexCAN_Hw_HwAccess header file are of the same Autosar version */
#if ((FLEXCAN_HW_IRQ_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_IRQ_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_IRQ_AR_RELEASE_PATCH_VERSION_H != FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Hw_Irq.h and FlexCAN_Hw_HwAccess.h are different"
#endif
/* Check if current file and FlexCAN_Hw_HwAccess header file are of the same Software version */
#if ((FLEXCAN_HW_IRQ_SW_MAJOR_VERSION_H != FLEXCAN_HW_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_IRQ_SW_MINOR_VERSION_H != FLEXCAN_HW_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_IRQ_SW_PATCH_VERSION_H != FLEXCAN_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Hw_Irq.h and FlexCAN_Hw_HwAccess.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

/******************************************************************************
*                            FUNCTION PROTOTYPES
*******************************************************************************/

#ifdef CanHwUnit_0
ISR(CAN_Mbor0_IRQHandler);
ISR(CAN_Error0_IRQHandler);
ISR(CAN_Busoff0_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo0_IRQHandler);
#endif
ISR(CAN_TXRX_Warnning0_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup0_IRQHandler);
#endif
#endif /* CanHwUnit_0 */

#ifdef CanHwUnit_1
ISR(CAN_Mbor1_IRQHandler);
ISR(CAN_Error1_IRQHandler);
ISR(CAN_Busoff1_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo1_IRQHandler);
#endif
ISR(CAN_TXRX_Warnning1_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup1_IRQHandler);
#endif
#endif /* CanHwUnit_1 */

#ifdef CanHwUnit_2
ISR(CAN_Mbor2_IRQHandler);
ISR(CAN_Error2_IRQHandler);
ISR(CAN_Busoff2_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo2_IRQHandler);
#endif
ISR(CAN_TXRX_Warnning2_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup2_IRQHandler);
#endif
#endif /* CanHwUnit_2 */

#ifdef CanHwUnit_3
ISR(CAN_Mbor3_IRQHandler);
ISR(CAN_Error3_IRQHandler);
ISR(CAN_Busoff3_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo3_IRQHandler);
#endif
ISR(CAN_TXRX_Warnning3_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup3_IRQHandler);
#endif
#endif /* CanHwUnit_3 */

#ifdef CanHwUnit_4
ISR(CAN_Mbor4_IRQHandler);
ISR(CAN_Error4_IRQHandler);
ISR(CAN_Busoff4_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo4_IRQHandler);
#endif
ISR(CAN_TXRX_Warnning4_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup4_IRQHandler);
#endif
#endif /* CanHwUnit_4 */

#ifdef CanHwUnit_5
ISR(CAN_Mbor5_IRQHandler);
ISR(CAN_Error5_IRQHandler);
ISR(CAN_Busoff5_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo5_IRQHandler);
#endif
ISR(CAN_TXRX_Warnning5_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup5_IRQHandler);
#endif
#endif /* CanHwUnit_5 */

#ifdef CanHwUnit_6
ISR(CAN_Mbor6_IRQHandler);
ISR(CAN_Error6_IRQHandler);
ISR(CAN_Busoff6_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo6_IRQHandler);
#endif
ISR(CAN_TXRX_Warnning6_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup6_IRQHandler);
#endif
#endif /* CanHwUnit_6 */

#ifdef CanHwUnit_7
ISR(CAN_Mbor7_IRQHandler);
ISR(CAN_Error7_IRQHandler);
ISR(CAN_Busoff7_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo7_IRQHandler);
#endif
ISR(CAN_TXRX_Warnning7_IRQHandler);
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup7_IRQHandler);
#endif
#endif /* CanHwUnit_7 */

/**
* @brief        This handler read data from MB or FIFO, and then clear the interrupt flags
* @details      This handler read data from MB or FIFO, and then clear the interrupt flags
* @param[in]    instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_Mbor_IRQHandler(uint8 instance);

/**
* @brief        Error interrupt handler for FLEXCAN
* @details      Error interrupt handler for FLEXCAN
* @param[in]    instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_Error_IRQHandler(uint8 instance);

/**
* @brief        BusOff and Tx/Rx Warning interrupt handler for FLEXCAN
* @details      BusOff and Tx/Rx Warning interrupt handler for FLEXCAN
* @param[in]    instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_Busoff_IRQHandler(uint8 instance);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
* @brief        Enhanced RxFifo IRQHandler
* @details      Enhanced RxFifo IRQHandler
* @param[in]    u8Instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_EnhancedRxFifo_IRQHandler(uint8 u8Instance);
#endif

/**
* @brief        TX/RX Warnning IRQHandler
* @details      TX/RX Warnning IRQHandler
* @param[in]    instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_TXRX_Warnning_IRQHandler(uint8 instance);

#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/**
* @brief        Wake up handler for CAN
* @details      Wake up handler for CAN
* @param[in]    u8Instance - A CAN instance number
* @return       void
* @retval       None
*/
void CANx_Wakeup_IRQHandler(uint8 u8Instance);
#endif


#ifdef __cplusplus
}
#endif


#endif /* FLEXCAN_HW_IRQ_H*/
/** @} */
