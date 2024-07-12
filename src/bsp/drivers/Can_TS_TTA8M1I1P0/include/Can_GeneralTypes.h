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
**  FILENAME     : Can_GeneralTypes.h                                         **
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

#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

#ifdef USING_OS_AUTOSAROS
#include "Platform_Types.h"
#else
#include "TT_PlatformTypes.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_GENERALTYPES_VENDOR_ID_H                   1541
#define CAN_GENERALTYPES_MODULE_ID_H                   80
#define CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION_H    4
#define CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION_H    4
#define CAN_GENERALTYPES_AR_RELEASE_PATCH_VERSION_H    0
#define CAN_GENERALTYPES_SW_MAJOR_VERSION_H            1
#define CAN_GENERALTYPES_SW_MINOR_VERSION_H            1
#define CAN_GENERALTYPES_SW_PATCH_VERSION_H            0
/**@}*/
/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifndef USING_OS_AUTOSAROS
    /* Check if current file and TTPlatform_Types header file are of the same vendor */
    #if (CAN_GENERALTYPES_VENDOR_ID_H != TT_PLATFORM_TYPES_VENDOR_ID_H)
        #error "Can_GeneralTypes.h and TT_Platform_Types.h have different vendor ids"
    #endif
    /* Check if current file and TTPlatform_Types header file are of the same Autosar version */
    #if ((CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION_H    != TT_PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
         (CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION_H    != TT_PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
         (CAN_GENERALTYPES_AR_RELEASE_PATCH_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION_H))
        #error "AutoSar Version Numbers of Can_GeneralTypes.h and TT_Platform_Types.h are different"
    #endif
    /* Check if current file and TTPlatform_Types header file are of the same Software version */
    #if ((CAN_GENERALTYPES_SW_MAJOR_VERSION_H != TT_PLATFORM_TYPES_SW_MAJOR_VERSION_H) || \
         (CAN_GENERALTYPES_SW_MINOR_VERSION_H != TT_PLATFORM_TYPES_SW_MINOR_VERSION_H) || \
         (CAN_GENERALTYPES_SW_PATCH_VERSION_H != TT_PLATFORM_TYPES_SW_PATCH_VERSION_H))
        #error "Software Version Numbers of Can_GeneralTypes.h and TT_Platform_Types.h are different"
    #endif
#else
/* Check if current file and Platform_Types header file are of the same vendor */
    #if (CAN_GENERALTYPES_VENDOR_ID_H != PLATFORM_TYPES_VENDOR_ID_H)
        #error "Can_GeneralTypes.h and Platform_Types.h have different vendor ids"
    #endif
    /* Check if current file and Platform_Types header file are of the same Autosar version */
    #if ((CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION_H    != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
         (CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION_H    != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
         (CAN_GENERALTYPES_AR_RELEASE_PATCH_VERSION_H != PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION_H))
        #error "AutoSar Version Numbers of Can_GeneralTypes.h and Platform_Types.h are different"
    #endif
    /* Check if current file and Platform_Types header file are of the same Software version */
    #if ((CAN_GENERALTYPES_SW_MAJOR_VERSION_H != PLATFORM_TYPES_SW_MAJOR_VERSION_H) || \
         (CAN_GENERALTYPES_SW_MINOR_VERSION_H != PLATFORM_TYPES_SW_MINOR_VERSION_H) || \
         (CAN_GENERALTYPES_SW_PATCH_VERSION_H != PLATFORM_TYPES_SW_PATCH_VERSION_H))
        #error "Software Version Numbers of Can_GeneralTypes.h and Platform_Types.h are different"
    #endif
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/**
* @brief Transmit request could not be processed because no
*        transmit object was available
* @implements SymbolDefinitions_enum
*/
/** @violates @ref Can_GeneralTypes_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro.*/
#define CAN_BUSY    0x02
/******************************************************************************
*                            Enums
*******************************************************************************/

/**
* @brief          CAN Controller State Modes of operation.
* @details        States that are used by the several ControllerMode functions
* @implements     Can_ControllerStateType_enum
*/
typedef enum
{
    CAN_CS_UNINIT  = 0U,    /**< @brief CAN controller state UNINIT */
    CAN_CS_STARTED,         /**< @brief CAN controller state STARTED */
    CAN_CS_STOPPED,         /**< @brief CAN controller state STOPPED */
    CAN_CS_SLEEP            /**< @brief CAN controller state SLEEP */
} Can_ControllerStateType;

/**
* @brief          CAN Controller State Modes of operation.
* @details        Error states of a CAN controller
* @implements     Can_ErrorStateType_enum
*/
typedef enum
{
    CAN_ERRORSTATE_ACTIVE = 0U,     /**< @brief The CAN controller takes fully part in communication. */
    CAN_ERRORSTATE_PASSIVE,         /**< @brief The CAN controller takes part in communication, but does not send active error frames. */
    CAN_ERRORSTATE_BUSOFF           /**< @brief The CAN controller does not take part in communication. */
} Can_ErrorStateType;

/**
* @brief          CAN Transceiver modes.
* @details        Operating modes of the CAN Transceiver Driver.
*
*/
typedef enum
{
    CANTRCV_TRCVMODE_NORMAL = 0U, /**< @brief Transceiver mode NORMAL */
    CANTRCV_TRCVMODE_STANDBY,     /**< @brief Transceiver mode STANDBY */
    CANTRCV_TRCVMODE_SLEEP        /**< @brief Transceiver mode SLEEP */
} CanTrcv_TrcvModeType;

/**
* @brief          
* @details   This type shall be used to control the CAN transceiver concerning wake up events and wake up notifications.     
* According to [SWS_CanTrcv_00164] it should be present in Can_GeneralTypes.h
*/
typedef enum
{
    CANTRCV_WUMODE_ENABLE = 0x00,   /* The notification for wakeup events is enabled on the addressed transceiver. */
    CANTRCV_WUMODE_DISABLE = 0x01,  /* The notification for wakeup events is disabled on the addressed transceiver. */
    CANTRCV_WUMODE_CLEAR = 0x02     /* A stored wakeup event is cleared on the addressed transceiver. */
} CanTrcv_TrcvWakeupModeType;


/**
* @brief          
* @details   This type denotes the wake up reason detected by the CAN transceiver in detail.
* According to [SWS_CanTrcv_00165] it should be present in Can_GeneralTypes.h
*/
typedef enum
{
    CANTRCV_WU_ERROR            = 0, /* Due to an error wake up reason was not detected. This value may only be reported when error was reported to DEM before. */
    CANTRCV_WU_NOT_SUPPORTED    = 1, /* The transceiver does not support any information for the wake up reason.  */
    CANTRCV_WU_BY_BUS           = 2, /* The transceiver has detected, that the network has caused the wake up of the ECU. */
    CANTRCV_WU_INTERNALLY       = 3, /* The transceiver has detected, that the network has woken up by the ECU via a request to NORMAL mode. */
    CANTRCV_WU_RESET            = 4, /* The transceiver has detected, that the "wake up" is due to an ECU reset. */
    CANTRCV_WU_POWER_ON         = 5, /* The transceiver has detected, that the "wake up" is due to an ECU reset after power on. */
    CANTRCV_WU_BY_PIN           = 6, /* The transceiver has detected a wake-up event at one of the transceiver's pins (not at the CAN bus). */
    CANTRCV_WU_BY_SYSERR        = 7  /* The transceiver has detected, that the wake up of the ECU was caused by a HW related device failure. */
} CanTrcv_TrcvWakeupReasonType;

typedef enum
{
ICOM_SWITCH_E_OK = 0, /**< @brief The activation of Pretended Networking was successful */
ICOM_SWITCH_E_FAILED = 1 /**< @brief The activation of Pretended Networking was not successful */
} IcomSwitch_ErrorType;
/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/**
* @{
* @brief          Can_IdType
* @details        Represents the Identifier of an L-PDU. The two most significant bits specify theframe type:
* -00 CAN message with Standard CAN ID
* -01 CAN FD frame with Standard CAN ID
* -10 CAN message with Extended CAN ID
* -11 CAN FD frame with Extended CAN ID
* @implements     Can_IdType_type
*/
typedef  uint32  Can_IdType;

/** 
* @brief   This type serve as a unique identifier of a PDU within a software module.
*          Allowed ranges: uint8 .. uint16
* @implements PduIdType_type
*/
typedef uint16       PduIdType;

/** 
* @brief   This type serve as length information of a PDU in bytes.
*          Allowed ranges: uint8 .. uint32 
* @implements PduLengthType_Type
*/
typedef uint32       PduLengthType; 

/**
* @brief          Can_PduType
* @details        Type used to provide ID, DLC, SDU from CAN interface to CAN driver.
*                 HTH or HRH = ID+DLC+SDU.
* @implements     Can_PduType_structure
*/
typedef struct
{
    Can_IdType id; /**< @brief CAN L-PDU = Data Link Layer Protocol Data Unit.
                                             Consists of Identifier, DLC and Data(SDU)  It is
                                             uint32 for CAN_EXTENDEDID=STD_ON, else is uint16.
                                             */
    PduIdType swPduHandle; /**< @brief The L-PDU Handle = defined and placed
                                                     inside the CanIf module layer. Each handle
                                                     represents an L-PDU, which is a CONSTant
                                                     structure with information for Tx/Rx
                                                     processing. */
    uint8 length; /**< @brief DLC = Data Length Code (part of L-PDU that describes
                                            the SDU length). */
    uint8 * sdu; /**< @brief CAN L-SDU = Link Layer Service Data
                                                          Unit. Data that is transported inside
                                                          the L-PDU. */
} Can_PduType;


/**
* @{
* @brief          Can_HwHandleType
* @details        Represents the hardware object handles of a CAN hardware unit.
                  For CAN hardware units with more than 255 HW objects use extended range.
*                    used by "Can_Write" function.
*                 The driver does not distinguish between Extended and Mixed transmission modes.
*                 Extended transmission mode of operation behaves the same as Mixed mode.
* @implements     Can_HwHandleType_type
*/
typedef uint16 Can_HwHandleType;

/**
* @brief          Can_HwType
* @details        This type defines a data structure which clearly provides an Hardware Object 
                    Handle including its corresponding CAN Controller and therefore CanDrv as well 
                    as the specific CanId.
* @implements     Can_HwType_structure
*/

typedef struct
{
    Can_IdType CanId; /**< @brief Standard/Extended CAN ID of CAN L-PDU. */
                                             
    Can_HwHandleType  Hoh; /**< @brief ID of the corresponding Hardware Object Range */
    
    uint8 ControllerId; /**< @brief ControllerId provided by CanIf clearly 
                                            identify the corresponding controller */                                      
} Can_HwType;


/** 
* @brief Variables of this type are used to store the basic information about a PDU of any type,
*        namely a pointer variable pointing to it's SDU (payload), and the corresponding length 
*        of the SDU in bytes.
* @implements PduInfoType_structure
*/
typedef struct
{
    uint8 * SduDataPtr;   /**< pointer to the SDU (i.e. *payload data) of the PDU */
    PduLengthType  SduLength;    /**< length of the SDU in bytes */
} PduInfoType;

/** 
* @brief   Variables of the type IcomConfigIdType defines the configuration ID. An ID of 0 is the 
*          default configuration. An ID greater than 0 shall identify a configuration for Pretended Networking.
* @implements IcomConfigIdType_type
*/
typedef uint8  IcomConfigIdType;

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /*CAN_GENERAL_TYPES_H*/

/** @} */
