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
**  FILENAME     : Can_Drv.h                                                  **
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

#ifndef CAN_DRV_H
#define CAN_DRV_H

#ifdef __cplusplus
extern "C"{
#endif


/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Types.h"
#ifdef USING_OS_AUTOSAROS
#include "CanIf.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/

#define CAN_DRV_VENDOR_ID_H                    1541
#define CAN_DRV_MODULE_ID_H                    80
#define CAN_DRV_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_DRV_AR_RELEASE_MINOR_VERSION_H     4
#define CAN_DRV_AR_RELEASE_PATCH_VERSION_H     0
#define CAN_DRV_SW_MAJOR_VERSION_H             1
#define CAN_DRV_SW_MINOR_VERSION_H             1
#define CAN_DRV_SW_PATCH_VERSION_H             0
/**@}*/

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifdef USING_OS_AUTOSAROS
/* Check if current file and FlexCAN_Hw header file are of the same vendor */
#if (CAN_DRV_VENDOR_ID_H != CANIF_VENDOR_ID_H)
    #error "Can_Drv.h and CanIf.h have different vendor ids"
#endif

/* Check if current file and FlexCAN_Hw header file are of the same Autosar version */
#if ((CAN_DRV_AR_RELEASE_MAJOR_VERSION_H    != CANIF_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_DRV_AR_RELEASE_MINOR_VERSION_H    != CANIF_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_DRV_AR_RELEASE_PATCH_VERSION_H != CANIF_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Can_Drv.h and CanIf.h are different"
#endif
/* Check if current file and FlexCAN_Hw header file are of the same Software version */
#if ((CAN_DRV_SW_MAJOR_VERSION_H != CANIF_SW_MAJOR_VERSION_H) || \
     (CAN_DRV_SW_MINOR_VERSION_H != CANIF_SW_MINOR_VERSION_H) || \
     (CAN_DRV_SW_PATCH_VERSION_H != CANIF_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_Drv.h and CanIf.h are different"
#endif
#endif

/* Check if current file and Can_Flexcan_Types header file are of the same vendor */
#if (CAN_DRV_VENDOR_ID_H != CAN_FLEXCAN_TYPES_VENDOR_ID_H)
    #error "Can_Drv.h and Can_Flexcan_Types.h have different vendor ids"
#endif
#if (CAN_DRV_MODULE_ID_H != CAN_FLEXCAN_TYPES_MODULE_ID_H)
    #error "Can_Drv.h and Can_Flexcan_Types.h have different module ids"
#endif
/* Check if current file and Can_Flexcan_Types header file are of the same Autosar version */
#if ((CAN_DRV_AR_RELEASE_MAJOR_VERSION_H    != CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_DRV_AR_RELEASE_MINOR_VERSION_H    != CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_DRV_AR_RELEASE_PATCH_VERSION_H != CAN_FLEXCAN_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Can_Drv.h and Can_Flexcan_Types.h are different"
#endif
/* Check if current file and Can_Flexcan_Types header file are of the same Software version */
#if ((CAN_DRV_SW_MAJOR_VERSION_H != CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_DRV_SW_MINOR_VERSION_H != CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_DRV_SW_PATCH_VERSION_H != CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_Drv.h and Can_Flexcan_Types.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Inport external structure defined by DRV */
CAN_DRV_EXT
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
CAN_DRV_EXT_ICOM
#endif
/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
#ifndef USING_OS_AUTOSAROS
/* @violates @ref Can_c_REF_5 MISRA 2012 Advisory Rule 8.9 */
extern TT_CONST Can_ConfigType Can_Config;
extern TT_CONST Can_ControllerConfigType Can_aControllerConfig[CAN_CONTROLLER_CONFIG_COUNT];
extern TT_CONST Can_HwObjectConfigType Can_aHwObjectConfig[CAN_HWOBJECT_CONFIG_COUNT];
#endif
extern uint16 Can_au16BaudrateIDConfig[CAN_CONTROLLER_CONFIG_COUNT];

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
extern TT_CONST Can_IcomConfigsType * Can_apxCtrlConfigIcomIndex[CAN_CONTROLLER_CONFIG_COUNT];
#endif
/******************************************************************************
*                            FUNCTION PROTOTYPES
*******************************************************************************/

/* @violates @ref Can_Flexcan_h_REF_2 MISRA 2012 Advisory Rule 4.9 */
#define Call_Can_FlexCan_Init(instance, status, Can_pControllerConfig)         FlexCAN_Hw_Init(instance, status, Can_pControllerConfig)
    
/******************************************************************************
*  Service name     : Can_Drv_Init
*  Syntax           : TT_RetType Can_Drv_Init(TT_CONST Can_ConfigType * Config)
*  Service ID       : 100
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Config - Pointer to driver configuration
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Initialize the CAN driver
******************************************************************************/
TT_RetType Can_Drv_Init(TT_CONST Can_ConfigType * Config);

/******************************************************************************
*  Service name     : Can_Drv_DeInit
*  Syntax           : TT_RetType Can_Drv_DeInit(void)
*  Service ID       : 101
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Can_DeInit_Activity
******************************************************************************/
TT_RetType Can_Drv_DeInit(void);

#if (CAN_SET_BAUDRATE_API == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_SetBaudrate
*  Syntax           : TT_RetType Can_Drv_SetBaudrate(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint16 BaudRateConfigID)
*  Service ID       : 102
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant (For the same controller)
*  Parameters (in)  : Can_pControllerConfig - Controller Config
*  Parameters (in)  : BaudRateConfigID - BaudRateConfig ID
*  Return value     : TT_RetType
*  Description      : This function set baudrate
******************************************************************************/
TT_RetType Can_Drv_SetBaudrate
(
        TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
        uint16 BaudRateConfigID
);
#endif

/******************************************************************************
*  Service name     : Can_Drv_SetControllerToStartMode
*  Syntax           : TT_RetType Can_Drv_SetControllerToStartMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 103
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Set Controller to participate the CAN network
******************************************************************************/
TT_RetType Can_Drv_SetControllerToStartMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);

/******************************************************************************
*  Service name     : Can_Drv_SetControllerToStopMode
*  Syntax           : TT_RetType Can_Drv_SetControllerToStopMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 105
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Set Controller to stop participating the CAN network
******************************************************************************/
TT_RetType Can_Drv_SetControllerToStopMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);

/******************************************************************************
*  Service name     : Can_Drv_DisableControllerInterrupts
*  Syntax           : TT_RetType Can_Drv_DisableControllerInterrupts(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 106
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Disable Can Controller Interrupts
******************************************************************************/
TT_RetType Can_Drv_DisableControllerInterrupts(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);

/******************************************************************************
*  Service name     : Can_Drv_EnableControllerInterrupts
*  Syntax           : TT_RetType Can_Drv_EnableControllerInterrupts(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 107
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Enable Can Controller Interrupts
******************************************************************************/
TT_RetType Can_Drv_EnableControllerInterrupts(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);

/******************************************************************************
*  Service name     : Can_Drv_CheckWakeup
*  Syntax           : TT_RetType Can_Drv_CheckWakeup(uint8 Controller,boolean *retval)
*  Service ID       : 121
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Controller - Can Controller
*  Parameters (out) : retval - wakeup value
*  Return value     : TT_RetType
*  Description      : Check WakeUp state
******************************************************************************/
TT_RetType Can_Drv_CheckWakeup(uint8 Controller,boolean *retval);

/******************************************************************************
*  Service name     : Can_Drv_GetControllerErrorState
*  Syntax           : TT_RetType Can_Drv_GetControllerErrorState(TT_CONST Can_ControllerConfigType * Can_pControllerConfig,uint8 *CanErrorState)
*  Service ID       : 108
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant (for the same controller)
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : CanErrorState - Error State
*  Return value     : TT_RetType
*  Description      : Get Controller Error State
******************************************************************************/
TT_RetType Can_Drv_GetControllerErrorState(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 *CanErrorState);

/******************************************************************************
*  Service name     : Can_Drv_GetControllerRxErrorCounter
*  Syntax           : TT_RetType Can_Drv_GetControllerRxErrorCounter(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 * RxErrorCounter)
*  Service ID       : 110
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant (for the same controller)
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : RxErrorCounter - Error Counter
*  Return value     : TT_RetType
*  Description      : Get Controller Rx Error Counter
******************************************************************************/
TT_RetType Can_Drv_GetControllerRxErrorCounter(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 * RxErrorCounter);

/******************************************************************************
*  Service name     : Can_Drv_GetControllerTxErrorCounter
*  Syntax           : TT_RetType Can_Drv_GetControllerTxErrorCounter(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 * TxErrorCounter)
*  Service ID       : 109
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant (for the same controller)
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : TxErrorCounter - Error Counter
*  Return value     : TT_RetType
*  Description      : Get Controller Tx Error Counter
******************************************************************************/
TT_RetType Can_Drv_GetControllerTxErrorCounter(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 * TxErrorCounter);

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_ListenOnlyMode
*  Syntax           : TT_RetType Can_Drv_ListenOnlyMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_ListenOnlyType State)
*  Service ID       : 104
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : State - Listen Only Mode Or Normal Mode
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Enable or disable Listen Only Mode
******************************************************************************/
TT_RetType Can_Drv_ListenOnlyMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_ListenOnlyType State);
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

/******************************************************************************
*  Service name     : Can_Drv_Write
*  Syntax           : TT_RetType Can_Drv_Write(Can_HwHandleType Hth,TT_CONST Can_PduType * PduInfo)
*  Service ID       : 111
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant (thread-safe)
*  Parameters (in)  : Hth - Tx Hardware Object
*  Parameters (in)  : PduInfo - Pdu information
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Write Pduinfo to Hw Buffer and request transmission
******************************************************************************/
TT_RetType Can_Drv_Write
(
    Can_HwHandleType Hth,
    TT_CONST Can_PduType * PduInfo
);

#if (CAN_ABORT_MB_API == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_AbortMb
*  Syntax           : TT_RetType Can_Drv_AbortMb(Can_HwHandleType Hth)
*  Service ID       : 120
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Hth - HW-transmit handler
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Abort outstanding transmissions
******************************************************************************/
TT_RetType Can_Drv_AbortMb
(
    Can_HwHandleType Hth
);
#endif


/******************************************************************************
*  Service name     : Can_Drv_MainFunction_Write
*  Syntax           : TT_RetType Can_Drv_MainFunction_Write(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig)
*  Service ID       : 112
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Polling Tx Confirmation
******************************************************************************/
TT_RetType Can_Drv_MainFunction_Write
(
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig
);

/******************************************************************************
*  Service name     : Can_Drv_MainFunction_Read
*  Syntax           : TT_RetType Can_Drv_MainFunction_Read(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig)
*  Service ID       : 113
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Polling Rx Indication
******************************************************************************/
TT_RetType Can_Drv_MainFunction_Read
(
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig
);

/******************************************************************************
*  Service name     : Can_Drv_MainFunction_BusOff
*  Syntax           : TT_RetType Can_Drv_MainFunction_BusOff(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 114
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Polling Bus Off
******************************************************************************/
TT_RetType Can_Drv_MainFunction_BusOff(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);

/******************************************************************************
*  Service name     : Can_Drv_MainFunction_Mode
*  Syntax           : TT_RetType Can_Drv_MainFunction_Mode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, Can_ControllerStateType * Can_pControllerState)
*  Service ID       : 115
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : Can_pControllerState - Can Controller State
*  Return value     : TT_RetType
*  Description      : Polling Controller Mode Transitions
******************************************************************************/
TT_RetType Can_Drv_MainFunction_Mode
(
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    Can_ControllerStateType * Can_pControllerState
);

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_ProcessTxMesgBuffer
*  Syntax           : TT_RetType Can_Drv_ProcessTxMesgBuffer(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8MbIdx)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (in)  : u8MbIdx - Can Mailbox Index
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process Tx Interrupt
******************************************************************************/
TT_RetType Can_Drv_ProcessTxMesgBuffer
(
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,
    uint8 u8MbIdx
);

/******************************************************************************
*  Service name     : Can_Drv_ProcessRxMesgBuffer
*  Syntax           : TT_RetType Can_Drv_ProcessRxMesgBuffer(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8MbIdx)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (in)  : u8MbIdx - Can Mailbox Index
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process Rx Interrupt
******************************************************************************/
TT_RetType Can_Drv_ProcessRxMesgBuffer
(
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,
    uint8 u8MbIdx
);
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_ProcessRxLegacyDma
*  Syntax           : TT_RetType Can_Drv_ProcessRxLegacyDma(TT_CONST Can_ControllerConfigType * Can_pControllerConfig,TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,uint8 u8Event)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (in)  : u8Event - DMA Complete Or Error
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process Rx Interrupt
******************************************************************************/
TT_RetType Can_Drv_ProcessRxLegacyDma
(
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,
    uint8 u8Event
);
#endif
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_ProcessRxEnhance
*  Syntax           : TT_RetType Can_Drv_ProcessRxEnhance(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8Event)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (in)  : u8Event - DMA Complete Or Error
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process Rx Enhance FIFO Interrupt
******************************************************************************/
TT_RetType Can_Drv_ProcessRxEnhance
(
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,
    uint8 u8Event
);
#endif

#endif

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_DeactivateIcomConfiguration
*  Syntax           : TT_RetType Can_Drv_DeactivateIcomConfiguration(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 116
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Deactivate Icom  Configuration
******************************************************************************/
extern TT_RetType Can_Drv_DeactivateIcomConfiguration(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);
/******************************************************************************
*  Service name     : Can_Drv_SetIcomConfiguration
*  Syntax           : TT_RetType Can_Drv_SetIcomConfiguration(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_IcomConfigsType * pIcomConfig)
*  Service ID       : 117
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : pIcomConfig - Icom Configuration
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Set Icom  Configuration
******************************************************************************/
extern TT_RetType Can_Drv_SetIcomConfiguration(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_IcomConfigsType * pIcomConfig);
/******************************************************************************
*  Service name     : Can_Drv_ProcessPN
*  Syntax           : TT_RetType Can_Drv_ProcessPN(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_IcomConfigsType * pIcomConfig)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : pIcomConfig - Icom Configuration
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process PN Mode
******************************************************************************/
extern TT_RetType Can_Drv_ProcessPN(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_IcomConfigsType * pIcomConfig);
#endif

#ifndef USING_OS_AUTOSAROS
/******************************************************************************
*  Service name     : CanIf_TxConfirmation
*  Syntax           : void CanIf_TxConfirmation(PduIdType CanTxPduId)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : CanTxPduId - Tx Pdu Id
*  Return value     : void
*  Description      : Send a callback function where you can define the send success flag
******************************************************************************/
void CanIf_TxConfirmation(PduIdType CanTxPduId);

/******************************************************************************
*  Service name     : CanIf_RxIndication
*  Syntax           : void CanIf_RxIndication( TT_CONST Can_HwType * Mailbox, TT_CONST PduInfoType * PduInfoPtr)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Mailbox - Storing message information
*  Parameters (in)  : PduInfoPtr - Stores the data pointer and length
*  Return value     : void
*  Description      : The receive callback function allows the user to define the receive success flag and view the received data
******************************************************************************/
void CanIf_RxIndication( TT_CONST Can_HwType * Mailbox, TT_CONST PduInfoType * PduInfoPtr);

#if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType * PduInfoPtr);
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif /*TEMPLATE_H*/

/** @} */
