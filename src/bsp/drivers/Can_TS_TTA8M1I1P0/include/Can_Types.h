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
**  FILENAME     : Can_Types.h                                                **
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

#ifndef CAN_TYPES_H
#define CAN_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Drv_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_FLEXCAN_TYPES_VENDOR_ID_H                    1541
/* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
#define CAN_FLEXCAN_TYPES_MODULE_ID_H                    80
#define CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H     4
#define CAN_FLEXCAN_TYPES_AR_RELEASE_PATCH_VERSION_H     0
#define CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H             1
#define CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H             1
#define CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H             0
/**@}*/

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and Can_Drv_Types.h are of the same vendor */
#if (CAN_FLEXCAN_TYPES_VENDOR_ID_H != CAN_DRV_TYPES_VENDOR_ID_H) 
    #error "Can_Types.h and Can_Drv_Types.h have different vendor ids"
#endif
#if (CAN_FLEXCAN_TYPES_MODULE_ID_H != CAN_DRV_TYPES_MODULE_ID_H)
    #error "Can_Types.h and Can_Drv_Types.h have different module ids"
#endif
/* Check if current file and Can_Drv_Types.h are of the same Autosar version */
#if ((CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H    != CAN_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H    != CAN_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_FLEXCAN_TYPES_AR_RELEASE_PATCH_VERSION_H != CAN_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Types.h and Can_Drv_Types.h are different"
#endif
/* Check if current file and Can_Drv_Types.h are of the same Software version */
#if ((CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H != CAN_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H != CAN_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H != CAN_DRV_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Types.h and Can_Drv_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/*! @brief Development Error ID for "API Service called with wrong parameter" */
#define CAN_E_PARAM_POINTER                         ((uint8)0x01U)
/*! @brief Development Error ID for "API Service called with wrong parameter" */
#define CAN_E_PARAM_HANDLE                          ((uint8)0x02U)
/*! @brief Development Error ID for "API Service called with wrong parameter" */
#define CAN_E_PARAM_DATA_LENGTH                     ((uint8)0x03U)
/*! @brief Development Error ID for "API Service called with wrong parameter" */
#define CAN_E_PARAM_CONTROLLER                      ((uint8)0x04U)
/*! @brief Development Error ID for "API Service used without initialization" */
#define CAN_E_UNINIT                                ((uint8)0x05U)
/*! @brief Development Error ID for "Invalid transition for the current mode" */
#define CAN_E_TRANSITION                            ((uint8)0x06U)
#if (CAN_SET_BAUDRATE_API == STD_ON)
/*! @brief Development Error ID for "Parameter Baudrate has an invalid value" */
#define CAN_E_PARAM_BAUDRATE                        ((uint8)0x07U)
#endif
/* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
#define CAN_E_ICOM_CONFIG_INVALID                   ((uint8)0x08U)
/*! @brief Development Error ID for "Invalid configuration set selection" */
#define CAN_E_INIT_FAILED                           ((uint8)0x09U)

/*! @brief Runtime Error ID for "Received CAN message is lost" */
#define CAN_E_DATALOST                              ((uint8)0x01U)

/*! @brief Service ID of Can_Init */
#define CAN_SID_INIT                                ((uint8)0x00U)
/* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
/*! @brief Service ID of Can_MainFunction_Write */
#define CAN_SID_MAIN_FUNCTION_WRITE                 ((uint8)0x01U)
/*! @brief Service ID of Can_SetControllerMode */
#define CAN_SID_SET_CONTROLLER_MODE                 ((uint8)0x03U)
/*! @brief Service ID of Can_DisableControllerInterrupts */
#define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS       ((uint8)0x04U)
/*! @brief Service ID of Can_EnableControllerInterrupts */
#define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS        ((uint8)0x05U)
/*! @brief Service ID of Can_Write */
#define CAN_SID_WRITE                               ((uint8)0x06U)
#if (CAN_VERSION_INFO_API == STD_ON)
/*! @brief Service ID of Can_GetVersionInfo */
#define CAN_SID_GET_VERSION_INFO                    ((uint8)0x07U)
#endif
/* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
/*! @brief Service ID of Can_MainFunction_BusOff */
#define CAN_SID_MAIN_FUNCTION_BUS_OFF               ((uint8)0x09U)
#if (CAN_WAKEUP_SUPPORT == STD_ON)
#define CAN_SID_MAIN_FUNCTION_WAKEUP                ((uint8)0x0AU)
#endif
#if (CAN_CHECK_WAKEUP_API == STD_ON)
#define CAN_SID_CHECK_WAKEUP                        ((uint8)0x0BU)
#endif
/* @violates @ref Can_Flexcan_Types_h_REF_1 MISRA 2012 Advisory Rule 2.5 */
/*! @brief Service ID of Can_MainFunction_Mode */
#define CAN_SID_MAIN_FUNCTION_MODE                  ((uint8)0x0CU)
#if (CAN_SET_BAUDRATE_API == STD_ON)
/*! @brief Service ID of Can_SetBaudrate */
#define CAN_SID_SET_BAUDRATE                        ((uint8)0x0FU)
#endif
/*! @brief Service ID of Can_DeInit */
#define CAN_SID_DEINIT                              ((uint8)0x10U)
/*! @brief Service ID of Can_GetControllerErrorState */
#define CAN_SID_GET_CONTROLLER_ERROR_STATE          ((uint8)0x11U)
/*! @brief Service ID of Can_GetControllerMode */
#define CAN_SID_GET_CONTROLLER_MODE                 ((uint8)0x12U)
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
#define CAN_SID_SET_ICOM_CONFIG                     ((uint8)0x21U)
#endif
/*! @brief Service ID of Can_GetControllerRxErrorCounter */
#define CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER     ((uint8)0x30U)
/*! @brief Service ID of Can_GetControllerTxErrorCounter */
#define CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER     ((uint8)0x31U)
#if (CAN_ABORT_MB_API == STD_ON)
/*! @brief Service ID of Can_AbortMb */
#define CAN_SID_ABORT_MB                            ((uint8)0x14U)
#endif
/*! @brief Service ID of Can_MainFunction_Read */
#define CAN_SID_MAIN_FUNCTION_READ                  ((uint8)0x08U)
#if (CAN_LISTEN_ONLY_MODE == STD_ON)
#define CAN_SID_LISTEN_ONLY_MODE                    ((uint8)0x32U)
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */
/*! @brief FD FRAME */
#define CAN_FD_FRAME_U32                            ((uint32)0x40000000U)
/*! @brief EXTENDED ID */
#define CAN_EXTENDED_ID_U32                         ((uint32)0x80000000U)

/******************************************************************************
*                            Enums
*******************************************************************************/
/** @brief Can Hardware Object Handle*/
typedef enum
{
    CAN_RECEIVE = 0,    /**< @brief Specifies the HardwareObject is used as Receive */
    CAN_TRANSMIT        /**< @brief Specifies the HardwareObject is used as Transmit */
}Can_HwObjectHandleType;

/** @brief Can Id Message */
typedef enum
{
    CAN_STANDARD = 0,   /**< @brief All the CANIDs are of type standard only (11bit). */
    CAN_EXTENDED,       /**< @brief All the CANIDs are of type extended only (29 bit) */
    CAN_MIXED           /**< @brief All the CANIDs are of type extended only (29 bit) */
}Can_IdMessageType;

/** @brief Message Buffer Type: TX, RX, RX FIFO */
typedef enum
{
    CAN_RX_NORMAL = 0,            /**< @brief Specifies the HardwareObject is used as Normal Receive Object */
    CAN_RX_LEGACY_FIFO,           /**< @brief Specifies the HardwareObject is used as Legacy FIFO Receive Object */
    CAN_RX_ENHANCED_FIFO,         /**< @brief Specifies the HardwareObject is used as Enhanced FIFO Receive Object */
    CAN_TX_NORMAL                 /**< @brief Specifies the HardwareObject is used as Normal Transmit Object */
}Can_MbType;

/** @brief Legacy FIFO ID Acceptance Mode */
typedef enum
{
    CAN_LEGACY_FIFO_FORMAT_A = 0U,  /**< @brief One full ID (standard and extended) per ID filter table element. */
    CAN_LEGACY_FIFO_FORMAT_B = 1U,  /**< @brief Two full standard IDs or two partial 14-bit (standard and extended) IDs per ID filter table element. */
    CAN_LEGACY_FIFO_FORMAT_C = 2U   /**< @brief Four partial 8-bit standard IDs per ID filter table element. */
}Can_LegacyFIFOAcceptanceModeType;

#if (CAN_TIMESTAMP_ENABLE == STD_ON)
    typedef void (*Can_TxTimestampPCallBackType)(Can_HwHandleType Hoh, uint32 CanTxPduId, uint32 u32TimestampVal);
    typedef void (*Can_RxTimestampPCallBackType)(Can_HwHandleType Hoh, uint32 u32TimestampVal);
#endif

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
/** @brief Listen Only Type */
typedef enum
{
    NORMAL_MODE          = 0U,     /**< @brief Normal mode. */
    LISTEN_ONLY_MODE     = 1U      /**< @brief Enable Listen Only mode. */
}Can_ListenOnlyType;
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
typedef void (*Can_NotifyType)(void);

/** @brief Can Hardware Filter */
typedef struct
{
    TT_CONST uint32 Can_u32HwFilterCode;   /**< @brief Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    TT_CONST uint32 Can_u32HwFilterMask;   /**< @brief Describes a mask for hardware-based filtering of CAN identifiers. */
}Can_HwFilterType;

/** @brief Can Hardware Object */
typedef struct
{
    /** @brief Can Hardware Object ID */
    TT_CONST Can_HwHandleType Can_HwObjectID;
     /** @brief Specifies the processing of HOH is Polling or Interrupt */
    TT_CONST boolean Can_bHwObjectUsesPolling;
    /** @brief Specifies the Hw object is enable/disable Trigger Transmit */
    TT_CONST boolean Can_bTriggerTransmit;
    /** @brief Specifies Hardware Object is used as Transmit or as Receive Object */
    TT_CONST Can_HwObjectHandleType Can_HohType;
    /** @brief Specifies the type of Message ID: STANDARD, EXTENDED, MIXED */
    TT_CONST Can_IdMessageType Can_IdMessage;  
    /** @brief Number of Hardware Objects used to implement one HOH */
    TT_CONST uint8 Can_u8ObjectCount;
    /** @brief Can MainFunction RW period reference */
    TT_CONST uint8 Can_MainFuncPeriodIndex;
    /** @brief Specifies the Max data length of Hw Object */
    TT_CONST uint8 Can_u8PayloadLength;
    /** @brief Specifies the value which is used to pad unspecified data */
    TT_CONST uint8 Can_u8PaddingValue;    
    /** @brief Pointer to Hw Filter Config */
    TT_CONST Can_HwFilterType * Can_pHwFilterConfig;
    /** @brief Specifies the Message Buffer is TX, RX or RX FIFO */
    TT_CONST Can_MbType Can_eReceiveType;
    /** @brief Pointer to Hw Buffer Address */
    TT_CONST uint32 * Can_pHwBufferAddr;
    /** @brief The number of Can Hw Filter Config */
    TT_CONST uint8 Can_u8HwFilterCount;
    /** @brief Buffer Index in Message buffer ram */
    TT_CONST uint8 Can_u8HwBufferIndex;    
     /** @brief The parameter is used to detect the MB which is use to get Timestamp or not */
#if (CAN_TIMESTAMP_ENABLE == STD_ON)
    TT_CONST boolean CanTimestampEnable;
#endif
}Can_HwObjectConfigType;

/** @brief Can Bit Rate */
typedef struct
{
    /** @brief Propagation Segment */
    TT_CONST uint8 Can_u8PropSeg;
    /** @brief Phase Segment 1 */
    TT_CONST uint8 Can_u8PhaseSeg1;
    /** @brief Prescaler Devider */
    TT_CONST uint16 Can_u16Prescaler;
    /** @brief Phase Segment 2 */
    TT_CONST uint8 Can_u8PhaseSeg2;   
    /** @brief Synchronization Jump Width*/
    TT_CONST uint8 Can_u8ResyncJumpWidth;
}Can_TimeSegmentType;

/** @brief Can Baudrate */
typedef struct
{
    /** @brief enhance CBT support */
    TT_CONST boolean Can_bEnhanceCBTEnable;
    /** @brief Tx Bit Rate Switch */
    TT_CONST boolean Can_bBitRateSwitch;
    /** @brief Can FD support */
    TT_CONST boolean Can_bFDFrame;  
    /** @brief Specifies the Transmission Arbitration start delay */
    TT_CONST uint8 Can_u8TxArbitrationStartDelay;
    /** @brief Nominal Bit Rate */
    TT_CONST Can_TimeSegmentType Can_NominalBitRate;
    /** @brief Data Bit Rate (using when support FD and Bit Rate Swith is set) */
    TT_CONST Can_TimeSegmentType Can_DataBitRate;   
    /** @brief Transmiter Delay Compensation Enable */
    TT_CONST boolean Can_bTrcvDelayEnable;   
    /** @brief Specifies the Transmiter Delay Compensation Offset */
    TT_CONST uint8 Can_u8TrcvDelayCompOffset;
}Can_BaudrateConfigType;

/** @brief Can Controller */
typedef struct
{
    /** @brief Abstracted CanIf Controller ID */
    TT_CONST uint8 Can_u8AbstControllerID;
    /** @brief Controller ID */
    TT_CONST uint8 Can_u8ControllerID;
    /** @brief Controller Offset */
    TT_CONST uint8 Can_u8ControllerOffset;
    /** @brief Define Controller is used in Config */
    TT_CONST boolean Can_bActivation;
    /** @brief Bus Off uses Polling */
    TT_CONST boolean Can_bBusOffUsesPolling;
    /** @brief Tx Priority */
    TT_CONST Flexcan_TxPriority Tx_Priority;
    /** @brief Rx Priority */
    TT_CONST Flexcan_RxPriority Rx_Priority;
    /** @brief Specifies the Global mask of Legacy FIFO */
    TT_CONST uint32 Can_u32LegacyGlobalMask;
    /** @brief ID Acceptance Mode */
    TT_CONST Can_LegacyFIFOAcceptanceModeType Can_eLegacyAcceptanceMode;
    /** @brief Legacy FIFO Warning Notification */
    TT_CONST Can_NotifyType Can_pLegacyFiFoWarnNotif;
    /** @brief Legacy FIFO Overflow Notification */
    TT_CONST Can_NotifyType Can_pLegacyFiFoOvfNotif;
    /** @brief Enhance FIFO Overflow Notification */
    TT_CONST Can_NotifyType Can_pEnhanceFiFoOvfNotif;
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /** @brief Enhance FIFO Dma Error Notification */
    TT_CONST Can_NotifyType Can_pDmaErrorNotif;
    /** @brief Pointer to DMA destination address */
    Flexcan_Hw_MsgBuffType * pDmaDstAddr;
#endif
    /** @brief Error Interrupt enable */
    TT_CONST boolean bErrEn;
    /** @brief Error Notification */
    TT_CONST Can_NotifyType Can_pErrNotif;
    /** @brief Error FD Notification */
    TT_CONST Can_NotifyType Can_pFDErrNotif;
    /** @brief Default Baudrate ID */
    TT_CONST uint16 Can_u16DefaultBaudrateID;
     /** @brief Number of Baurate Configured */
    TT_CONST uint16 Can_u16BaudrateConfigCount;
    /** @brief Pointer to Baudrate Config */
    TT_CONST Can_BaudrateConfigType * Can_pBaudrateConfig;
    /** @brief Pointer to Controller config */
    TT_CONST Can_Drv_HwChannelConfigType * HwChannelIpConfig;
    /** @brief The number of Hw Objects referred to Controller */
    TT_CONST uint8 Can_u8HwObjectRefCount;
    /** @brief Pointer point to Pointer to Hw Object that refer to Controller */
    TT_CONST Can_HwObjectConfigType * TT_CONST * Can_ppHwObject;
#if (CAN_TIMESTAMP_ENABLE == STD_ON)
    /** @brief Pointer to TX Timestamp notification function. */
    TT_CONST Can_TxTimestampPCallBackType CanTxTimestampNotification;
    /** @brief Pointer to RX Timestamp notification function. */
    TT_CONST Can_RxTimestampPCallBackType CanRxTimestampNotification;
#endif
}Can_ControllerConfigType;

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
typedef struct
{
    TT_CONST uint8 u8CanIcomConfigId;
    TT_CONST Can_Drv_IcomRxMessageConfigsType * pCanIcomRxMessageConfigs;
} Can_IcomConfigsType;
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */

/** @brief Can Configuration */
typedef struct
{
    /** @brief Configuration Core ID */
    TT_CONST uint32 Can_u32CoreID;
    /** @brief The first Hth after Hrh consecutive */
    TT_CONST Can_HwHandleType Can_uHthFirstIndex;
    /** @brief Mapping Controller ID to Controller hardware offset */
    TT_CONST uint8 * Can_pCtrlOffsetToCtrlIDMap;
    /** @brief Mapping Controller ID to Hardware Object ID */
    TT_CONST uint8 * Can_pHwObjIDToCtrlIDMap;
    /** @brief Pointer to Can Hardware Object Config */
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig;
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
    /** @brief The size of Can Pn Configs */
    TT_CONST uint8 u8NumCanIcomConfigs;
    /** brief Pointer point to Can Pn Configs */
    TT_CONST Can_IcomConfigsType * pCanIcomConfigs;
#endif /* (!!CAN##!!_##PUBLIC_ICOM_SUPPORT == STD_ON) */
    /** @brief Pointer to Can Controller Config */
    TT_CONST Can_ControllerConfigType * TT_CONST * Can_ppController;
}Can_ConfigType;

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            FUNCTION PROTOTYPES
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* CAN_FLEXCAN_TYPES_H */
