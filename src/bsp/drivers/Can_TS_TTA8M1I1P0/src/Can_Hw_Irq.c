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
**  FILENAME     : Can_Hw_Irq.c                                               **
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

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Hw_Irq.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_IRQ_VENDOR_ID_C                      1541
#define FLEXCAN_HW_IRQ_MODULE_ID_C                      80
#define FLEXCAN_HW_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXCAN_HW_IRQ_AR_RELEASE_MINOR_VERSION_C       4
#define FLEXCAN_HW_IRQ_AR_RELEASE_PATCH_VERSION_C       0
#define FLEXCAN_HW_IRQ_SW_MAJOR_VERSION_C               1
#define FLEXCAN_HW_IRQ_SW_MINOR_VERSION_C               1
#define FLEXCAN_HW_IRQ_SW_PATCH_VERSION_C               0
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and FlexCAN_Hw_Irq header file are of the same vendor */
#if (FLEXCAN_HW_IRQ_VENDOR_ID_C != FLEXCAN_HW_IRQ_VENDOR_ID_H)
    #error "FlexCAN_Hw_Irq.c and FlexCAN_Hw_Irq.h have different vendor ids"
#endif
#if (FLEXCAN_HW_IRQ_MODULE_ID_C != FLEXCAN_HW_IRQ_MODULE_ID_H)
    #error "FlexCAN_Hw_Irq.c and FlexCAN_Hw_Irq.h  have different module ids"
#endif
/* Check if current file and FlexCAN_Hw_Irq header file are of the same Autosar version */
#if ((FLEXCAN_HW_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_HW_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_HW_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_IRQ_AR_RELEASE_PATCH_VERSION_C != FLEXCAN_HW_IRQ_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Hw_Irq.c and FlexCAN_Hw_Irq.h are different"
#endif
/* Check if current file and FlexCAN_Hw_Irq header file are of the same Software version */
#if ((FLEXCAN_HW_IRQ_SW_MAJOR_VERSION_C != FLEXCAN_HW_IRQ_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_IRQ_SW_MINOR_VERSION_C != FLEXCAN_HW_IRQ_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_IRQ_SW_PATCH_VERSION_C != FLEXCAN_HW_IRQ_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Hw_Irq.c and FlexCAN_Hw_Irq.h are different"
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

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"

#ifdef CanHwUnit_0
ISR(CAN_Mbor0_IRQHandler)
{
    CANx_Mbor_IRQHandler (0);
}
ISR(CAN_Error0_IRQHandler)
{
   CANx_Error_IRQHandler (0);
}
ISR(CAN_Busoff0_IRQHandler)
{
   CANx_Busoff_IRQHandler (0);
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo0_IRQHandler)
{
   CANx_EnhancedRxFifo_IRQHandler (0);
}
#endif
ISR(CAN_TXRX_Warnning0_IRQHandler)
{
  CANx_TXRX_Warnning_IRQHandler (0);
}
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup0_IRQHandler)
{
    CANx_Wakeup_IRQHandler (0);
}
#endif
#endif /* CanHwUnit_0 */

#ifdef CanHwUnit_1
ISR(CAN_Mbor1_IRQHandler)
{
    CANx_Mbor_IRQHandler (1);
}
ISR(CAN_Error1_IRQHandler)
{
    CANx_Error_IRQHandler (1);
}
ISR(CAN_Busoff1_IRQHandler)
{
    CANx_Busoff_IRQHandler (1);
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo1_IRQHandler)
{
    CANx_EnhancedRxFifo_IRQHandler (1);
}
#endif
ISR(CAN_TXRX_Warnning1_IRQHandler)
{
    CANx_TXRX_Warnning_IRQHandler (1);
}
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup1_IRQHandler)
{
    CANx_Wakeup_IRQHandler (1);
}
#endif
#endif /* CanHwUnit_1 */

#ifdef CanHwUnit_2
ISR(CAN_Mbor2_IRQHandler)
{
    CANx_Mbor_IRQHandler (2);
}
ISR(CAN_Error2_IRQHandler)
{
    CANx_Error_IRQHandler (2);
}
ISR(CAN_Busoff2_IRQHandler)
{
    CANx_Busoff_IRQHandler (2);
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo2_IRQHandler)
{
    CANx_EnhancedRxFifo_IRQHandler (2);
}
#endif
ISR(CAN_TXRX_Warnning2_IRQHandler)
{
    CANx_TXRX_Warnning_IRQHandler (2);
}
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup2_IRQHandler)
{
    CANx_Wakeup_IRQHandler (2);
}
#endif
#endif /* CanHwUnit_2 */

#ifdef CanHwUnit_3
ISR(CAN_Mbor3_IRQHandler)
{
    CANx_Mbor_IRQHandler (3);
}
ISR(CAN_Error3_IRQHandler)
{
    CANx_Error_IRQHandler (3);
}
ISR(CAN_Busoff3_IRQHandler)
{
    CANx_Busoff_IRQHandler (3);
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo3_IRQHandler)
{
    CANx_EnhancedRxFifo_IRQHandler (3);
}
#endif
ISR(CAN_TXRX_Warnning3_IRQHandler)
{
    CANx_TXRX_Warnning_IRQHandler (3);
}
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup3_IRQHandler)
{
    CANx_Wakeup_IRQHandler (3);
}
#endif
#endif /* CanHwUnit_3 */

#ifdef CanHwUnit_4
ISR(CAN_Mbor4_IRQHandler)
{
    CANx_Mbor_IRQHandler (4);
}
ISR(CAN_Error4_IRQHandler)
{
    CANx_Error_IRQHandler (4);
}
ISR(CAN_Busoff4_IRQHandler)
{
    CANx_Busoff_IRQHandler (4);
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo4_IRQHandler)
{
    CANx_EnhancedRxFifo_IRQHandler (4);
}
#endif
ISR(CAN_TXRX_Warnning4_IRQHandler)
{
    CANx_TXRX_Warnning_IRQHandler (4);
}
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup4_IRQHandler)
{
    CANx_Wakeup_IRQHandler (4);
}
#endif
#endif /* CanHwUnit_4 */

#ifdef CanHwUnit_5
ISR(CAN_Mbor5_IRQHandler)
{
    CANx_Mbor_IRQHandler (5);
}
ISR(CAN_Error5_IRQHandler)
{
    CANx_Error_IRQHandler (5);
}
ISR(CAN_Busoff5_IRQHandler)
{
    CANx_Busoff_IRQHandler (5);
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo5_IRQHandler)
{
    CANx_EnhancedRxFifo_IRQHandler (5);
}
#endif
ISR(CAN_TXRX_Warnning5_IRQHandler)
{
    CANx_TXRX_Warnning_IRQHandler (5);
}
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup5_IRQHandler)
{
    CANx_Wakeup_IRQHandler (5);
}
#endif
#endif /* CanHwUnit_5 */

#ifdef CanHwUnit_6
ISR(CAN_Mbor6_IRQHandler)
{
    CANx_Mbor_IRQHandler (6);
}
ISR(CAN_Error6_IRQHandler)
{
    CANx_Error_IRQHandler (6);
}
ISR(CAN_Busoff6_IRQHandler)
{
    CANx_Busoff_IRQHandler (6);
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo6_IRQHandler)
{
    CANx_EnhancedRxFifo_IRQHandler (6);
}
#endif
ISR(CAN_TXRX_Warnning6_IRQHandler)
{
    CANx_TXRX_Warnning_IRQHandler (6);
}
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup6_IRQHandler)
{
    CANx_Wakeup_IRQHandler (6);
}
#endif
#endif /* CanHwUnit_6 */

#ifdef CanHwUnit_7
ISR(CAN_Mbor7_IRQHandler)
{
    CANx_Mbor_IRQHandler (7);
}
ISR(CAN_Error7_IRQHandler)
{
    CANx_Error_IRQHandler (7);
}
ISR(CAN_Busoff7_IRQHandler)
{
    CANx_Busoff_IRQHandler (7);
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
ISR(CAN_EnhancedRxFifo7_IRQHandler)
{
    CANx_EnhancedRxFifo_IRQHandler (7);
}
#endif
ISR(CAN_TXRX_Warnning7_IRQHandler)
{
    CANx_TXRX_Warnning_IRQHandler (7);
}
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN_Wakeup7_IRQHandler)
{
    CANx_Wakeup_IRQHandler (7);
}
#endif
#endif /* CanHwUnit_7 */

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif
