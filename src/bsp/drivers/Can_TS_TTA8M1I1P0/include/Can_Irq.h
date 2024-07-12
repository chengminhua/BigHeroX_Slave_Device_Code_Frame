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
**  FILENAME     : Can_Irq.h                                                  **
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

#ifndef CAN_IRQ_H
#define CAN_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Drv.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_IRQ_VENDOR_ID_H                   1541
#define CAN_IRQ_MODULE_ID_H                   80
#define CAN_IRQ_AR_RELEASE_MAJOR_VERSION_H    4
#define CAN_IRQ_AR_RELEASE_MINOR_VERSION_H    4
#define CAN_IRQ_AR_RELEASE_PATCH_VERSION_H    0
#define CAN_IRQ_SW_MAJOR_VERSION_H            1
#define CAN_IRQ_SW_MINOR_VERSION_H            1
#define CAN_IRQ_SW_PATCH_VERSION_H            0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and Can_Flexcan_Types.h header file are of the same vendor */
#if (CAN_IRQ_VENDOR_ID_H != CAN_FLEXCAN_TYPES_VENDOR_ID_H)
    #error "Can_Irq.h and Can_Flexcan_Types.h have different vendor ids"
#endif
#if (CAN_IRQ_MODULE_ID_H != CAN_FLEXCAN_TYPES_MODULE_ID_H)
    #error "Can_Irq.h and Can_Flexcan_Types.h have different module ids"
#endif
/* Check if current file and Can_Flexcan_Types.h file are of the same Autosar version */
#if ((CAN_IRQ_AR_RELEASE_MAJOR_VERSION_H    != CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IRQ_AR_RELEASE_MINOR_VERSION_H    != CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IRQ_AR_RELEASE_PATCH_VERSION_H != CAN_FLEXCAN_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Can_Irq.h and Can_Flexcan_Types.h are different"
#endif
/* Check if current file and Can_Flexcan_Types header file are of the same Software version */
#if ((CAN_IRQ_SW_MAJOR_VERSION_H != CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_IRQ_SW_MINOR_VERSION_H != CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_IRQ_SW_PATCH_VERSION_H != CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_Irq.h and Can_Flexcan_Types.h are different"
#endif
/******************************************************************************
*                            Public Constants
*******************************************************************************/
/* Saving configuration data */
extern TT_CONST Can_ConfigType * Can_apxConfig;
/* Saving Controller State */
extern Can_ControllerStateType Can_eControllerState[CAN_CONTROLLER_CONFIG_COUNT];
/******************************************************************************
*                            FUNCTION PROTOTYPES
*******************************************************************************/

#if ((CAN_MB_INTERRUPT_SUPPORT == STD_ON) || (CAN_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON))
/* Common Irq Callback */
void Can_CommonIrqCallback(uint8 u8Instance,
                           Flexcan_Hw_EventType event,
                           uint32 u32buffIdx,
                           TT_CONST Flexcan_Hw_StateType *driverState);
#endif 

/* Error Irq Callback */
void Can_ErrorIrqCallback(uint8 u8Instance,
                          Flexcan_Hw_EventType event,
                          uint32 u32ErrStatus,
                          TT_CONST Flexcan_Hw_StateType * flexcanState);

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
/* Function process Message Buffer Interrupt */
void Can_ProcessMesgBufferCommonInterrupt(uint8 u8CtrlOffset, uint8 u8MbIdx, Can_MbType mbType);
#endif /* (CAN_MB_INTERRUPT_SUPPORT == STD_ON) */

/* Function process Bus Off Interrupt */
void Can_ProcessBusOffInterrupt(uint8 u8CtrlOffset);

#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
/* Function process Error Interrupt */
void Can_ProcessErrorInterrupt(uint8 u8CtrlOffset, boolean bIsErrFast);
#endif /* (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON) */

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/* Process PN Interrupt */
void Can_ProcessPNInterrupt(uint8 u8CtrlOffset);
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_IRQ_H */
