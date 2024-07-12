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
**  FILENAME     : Dio_Hw_Types.h                                             **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Dio Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef DIO_HW_TYPES_H
#define DIO_HW_TYPES_H
/******************************************************************************
*                            Includes
******************************************************************************/
#ifdef USING_OS_AUTOSAROS
#include "Dio_Cfg.h"
#else
#include "Dio_Drv_Cfg.h"
#endif

#ifdef USING_OS_AUTOSAROS
#include "SchM_Dio.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_HW_TYPES_VENDOR_ID_H                    (1541)
#define DIO_HW_TYPES_MODULE_ID_H                    (120)
#define DIO_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H     (4)
#define DIO_HW_TYPES_AR_RELEASE_MINOR_VERSION_H     (4)
#define DIO_HW_TYPES_AR_RELEASE_PATCH_VERSION_H     (0)
#define DIO_HW_TYPES_SW_MAJOR_VERSION_H             (1)
#define DIO_HW_TYPES_SW_MINOR_VERSION_H             (1)
#define DIO_HW_TYPES_SW_PATCH_VERSION_H             (0)
/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifdef USING_OS_AUTOSAROS
/* Dio_Hw_Types.h Dio_Cfg.h file version check */
#if (DIO_HW_TYPES_VENDOR_ID_H != DIO_CFG_VENDOR_ID_H)
    #error "Dio_Hw_Types.h and Dio_Cfg.h have different vendor ids"
#endif

#if (DIO_HW_TYPES_MODULE_ID_H != DIO_CFG_MODULE_ID_H)
    #error "Dio_Hw_Types.h and Dio_Cfg.h have different module ids"
#endif

#if ((DIO_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != DIO_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != DIO_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != DIO_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Hw_Types.h and Dio_Cfg.h are different"
#endif

#if ((DIO_HW_TYPES_SW_MAJOR_VERSION_H != DIO_CFG_SW_MAJOR_VERSION_H) || \
     (DIO_HW_TYPES_SW_MINOR_VERSION_H != DIO_CFG_SW_MINOR_VERSION_H) || \
     (DIO_HW_TYPES_SW_PATCH_VERSION_H != DIO_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Hw_Types.h and Dio_Cfg.h are different"
#endif
#else
/* Dio_Hw_Types.h Dio_Drv_Cfg.h file version check */
#if (DIO_HW_TYPES_VENDOR_ID_H != DIO_DRV_CFG_VENDOR_ID_H)
    #error "Dio_Hw_Types.h and Dio_Drv_Cfg.h have different vendor ids"
#endif

#if (DIO_HW_TYPES_MODULE_ID_H != DIO_DRV_CFG_MODULE_ID_H)
    #error "Dio_Hw_Types.h and Dio_Drv_Cfg.h have different module ids"
#endif

#if ((DIO_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != DIO_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != DIO_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != DIO_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Hw_Types.h and Dio_Drv_Cfg.h are different"
#endif

#if ((DIO_HW_TYPES_SW_MAJOR_VERSION_H != DIO_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (DIO_HW_TYPES_SW_MINOR_VERSION_H != DIO_DRV_CFG_SW_MINOR_VERSION_H) || \
     (DIO_HW_TYPES_SW_PATCH_VERSION_H != DIO_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Hw_Types.h and Dio_Drv_Cfg.h are different"
#endif
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* GET PORT ID */
#define DIO_GET_PORT_FROM_CHANNEL_ID(ChannelId)     ((ChannelId) / 32)
/* GET CHANNEL ID */
#define DIO_GET_BIT_FROM_CHANNEL_ID(ChannelId)      ((ChannelId) % 32)

/* Channel numbers */
#define DIO_NUMBER_OF_CHANNEL                       ((uint32)32)
/* Port numbers */
#define DIO_PORT_NUMBER                             ((uint32)5)
/* ALL CHANNEL numbers */
#define DIO_ALL_CHANNEL                             (DIO_NUMBER_OF_CHANNEL*DIO_PORT_NUMBER)

/* PORT ID */
#define PORTA (0)
#define PORTB (1)
#define PORTC (2)
#define PORTD (3)
#define PORTE (4)

/*SWS_DIO_00175 - Invalid channel name requested */
#define DIO_E_PARAM_INVALID_CHANNEL_ID              (0x0Au)
#define DIO_E_PARAM_CONFIG                          (0x10u)
#define DIO_E_PARAM_INVALID_PORT_ID                 (0x14u)
#define DIO_E_PARAM_INVALID_GROUP_ID                (0x1Fu)
#define DIO_E_PARAM_POINTER                         (0x20u)

/* Port List */
#define    DIO_PORT_TYPE_ID_0                       (0U)
#define    DIO_PORT_TYPE_ID_1                       (1U)
#define    DIO_PORT_TYPE_ID_2                       (2U)
#define    DIO_PORT_TYPE_ID_3                       (3U)
#define    DIO_PORT_TYPE_ID_4                       (4U)

#ifndef USING_OS_AUTOSAROS
/* Function pointer to Callback Function. */
typedef  void  (*Dio_NotificationType)(uint32 ch);
#endif

/* Dio Is Channel Used */
#define DIO_IS_CHANNEL_USED(ChannelId) (\
        (Dio_GlobalData.UsedChannelsMap[((ChannelId) / 32UL)] & (1UL << ((ChannelId) % 32UL)))>0?1:0)
/* Dio Is Port Used */
#define DIO_IS_PORT_USED(PortId)       (\
        (Dio_GlobalData.UsedPortsMap & (1UL << ((PortId) % 32UL)))>0?1:0)
/******************************************************************************
*                            Enums
*******************************************************************************/
typedef enum {
    /* INPUT PIN is assigned with value 0*/
    DIO_PIN_IN  = 0u,   
    /* OUTPUT PIN is assigned with value 1*/
    DIO_PIN_OUT = 1u
} Dio_PinDirectionType;

typedef enum {
    /* TRIGGER RISING */
    DIO_TRIGGER_RISING  = 0u,
    /* TRIGGER FALLING */
    DIO_TRIGGER_FALLING = 1u,
    /* TRIGGER BOTH */
    DIO_TRIGGER_BOTH    = 2u,
    /* TRIGGER HIGH */
    DIO_TRIGGER_HIGH    = 3u,
    /* TRIGGER LOW */
    DIO_TRIGGER_LOW     = 4u
} Dio_ExitTriggerType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* Dio_ChannelType
SWS_Dio_00182 - Dio_ChannelType
SWS_Dio_00015 - Parameters of type Dio_ChannelType contain the numeric ID of a DIO channel.
SWS_Dio_00180 - The mapping of the ID is implementation specific but not configurable.*/

typedef uint32 Dio_ChannelType;

/* Dio_PortType
SWS_Dio_00183 - Dio_PortType
SWS_Dio_00018 - Parameters of type Dio_PortType contain the numeric ID of a DIO port.
SWS_Dio_00181 - The mapping of ID is implementation specific but not configurable.*/

typedef uint32 Dio_PortType;

typedef struct {
    /* Channel Id */
    Dio_ChannelType      DioChannelId;
    /* Whether interrupts are enabled */
    boolean              InterruptUsed;
    /* Interrupt trigger mode */
    Dio_ExitTriggerType  Trigger;
} Dio_ChannelConfigType;

/**
*   @brief Type for the definition of a channel group, which consists of several adjoining channels within a port.
*   This structure contains Dio_PortType, Offset and Mask
*/
typedef struct {
    /* Port Id */
    Dio_PortType DioPortId;
    /* Port Offset */
    uint8        DioPortOffset;
    /* Port Mask */
    uint32       DioPortMask;
} Dio_ChannelGroupType;

/* Dio_LevelType
SWS_Dio_00185 - Dio_LevelType
SWS_Dio_00023 - Dio_LevelType is the type for the possible levels that a DIO channel can have (input or output) */
typedef uint8 Dio_LevelType;


/* Dio_PortLevelType
SWS_Dio_00186 - Dio_PortLevelType
SWS_Dio_00103 - The port width within the types defined for the DIO Driver
                shall be the size of the largest port on the MCU which may be
                accessed by the DIO Drive.
SWS_Dio_00024 - Dio_PortLevelType is the type for the value of a DIO port*/
typedef uint32 Dio_PortLevelType;

typedef struct
{
    /* Port Config */
    TT_CONST Dio_PortType *Dio_PortConfigData;
    /* Channel Config */
    TT_CONST Dio_ChannelType *DioChannelConfigData;
    /* Channel Croup Config */
    TT_CONST Dio_ChannelGroupType  *DioChannelGroupConfigData;
#ifndef USING_OS_AUTOSAROS
    /* GPIO0 callback function */
    Dio_NotificationType GPIO0Notification;
    /* GPIO1 callback function */
    Dio_NotificationType GPIO1Notification;
    /* GPIO2 callback function */
    Dio_NotificationType GPIO2Notification;
    /* GPIO3 callback function */
    Dio_NotificationType GPIO3Notification;
    /* GPIO4 callback function */
    Dio_NotificationType GPIO4Notification;
#endif
}Dio_ConfigType;

typedef struct {
    /* Data Config */
    TT_CONST Dio_ConfigType *Config;
    /* Used Ports Map */
    TT_CONST Dio_PortType UsedPortsMap;
    /* Used Channels Map */
    TT_CONST Dio_ChannelType *UsedChannelsMap;
    /* The module Crc value is retained */
    TT_CONST uint32 DioCrc;
} Dio_GlobalType;

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
extern TT_CONST Dio_GlobalType Dio_GlobalData;


#endif /* end of DIO_HW_TYPES_H */

