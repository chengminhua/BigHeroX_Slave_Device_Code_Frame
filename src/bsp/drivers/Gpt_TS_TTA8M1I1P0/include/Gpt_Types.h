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
**  FILENAME     : Gpt_Types.h                                                **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : GPT Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gpt_Hw_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GPT_TYPES_VENDOR_ID_H                           1541
#define GPT_TYPES_MODULE_ID_H                           100
#define GPT_TYPES_AR_RELEASE_MAJOR_VERSION_H            4
#define GPT_TYPES_AR_RELEASE_MINOR_VERSION_H            4
#define GPT_TYPES_AR_RELEASE_PATCH_VERSION_H            0
#define GPT_TYPES_SW_MAJOR_VERSION_H                    1
#define GPT_TYPES_SW_MINOR_VERSION_H                    1
#define GPT_TYPES_SW_PATCH_VERSION_H                    0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gpt_Types.h Gpt_Hw_Types.h file version check */
#if (GPT_TYPES_VENDOR_ID_H != GPT_HW_TYPES_VENDOR_ID_H)
    #error "Gpt_Types.h and Gpt_Hw_Types.h have different vendor id"
#endif

#if (GPT_TYPES_MODULE_ID_H != GPT_HW_TYPES_MODULE_ID_H)
    #error "Gpt_Types.h and Gpt_Hw_Types.h have different module id"
#endif

#if ((GPT_TYPES_AR_RELEASE_MAJOR_VERSION_H != GPT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_TYPES_AR_RELEASE_MINOR_VERSION_H != GPT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_TYPES_AR_RELEASE_PATCH_VERSION_H != GPT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_Types.h and Gpt_Hw_Types.h are different"
#endif

#if ((GPT_TYPES_SW_MAJOR_VERSION_H != GPT_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (GPT_TYPES_SW_MINOR_VERSION_H != GPT_HW_TYPES_SW_MINOR_VERSION_H) || \
     (GPT_TYPES_SW_PATCH_VERSION_H != GPT_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_Types.h and Gpt_Hw_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* An alias for the Gpt_Hw_ChannelType. */
typedef Gpt_Hw_ChannelType              Gpt_ChannelType;

/* An alias for the Gpt_Hw_ValueType. */
typedef Gpt_Hw_ValueType                Gpt_ValueType;

/* An alias for the Gpt_Hw_FtmPredefTimerConfigType. */
typedef Gpt_Hw_FtmPredefTimerConfigType Gpt_FtmPredefTimerConfigType;

/* An alias for the Gpt_Hw_FtmModuleConfigType. */
typedef Gpt_Hw_FtmChannelConfigType     Gpt_FtmChannelConfigType;

/* An alias for the Gpt_Hw_FtmModuleConfigType. */
typedef Gpt_Hw_FtmModuleConfigType      Gpt_FtmModuleConfigType;

/* A function pointer of type void. */
typedef void                            (*Gpt_ChannelNotificationType)(void);

#define GPT_GETVERSIONINFO_ID           (0x00U)    	/* Service ID for Gpt_GetVersionInfo API */
#define GPT_INIT_ID                     (0x01U)   	/* Service ID for Gpt_Init API */
#define GPT_DEINIT_ID                   (0x02U)    	/* Service ID for Gpt_DeInit API */
#define GPT_GETTIMEELAPSED_ID           (0x03U)    	/* Service ID for Gpt_GetTimeElapsed API */
#define GPT_GETTIMEREMAINING_ID         (0x04U)    	/* Service ID for Gpt_GetTimeRemaining API */
#define GPT_STARTTIMER_ID               (0x05U)    	/* Service ID for Gpt_StartTimer API */
#define GPT_STOPTIMER_ID                (0x06U)    	/* Service ID for Gpt_StopTimer API */
#define GPT_ENABLENOTIFICATION_ID       (0x07U)    	/* Service ID for Gpt_EnableNotification API */
#define GPT_DISABLENOTIFICATION_ID      (0x08U)    	/* Service ID for Gpt_DisableNotification API */
#define GPT_SETMODE_ID                  (0x09U)     /* Service ID for Gpt_DisableNotification API */
#define GPT_DISABLEWAKEUP_ID            (0x0AU)     /* Service ID for Gpt_DisableNotification API */
#define GPT_ENABLEWAKEUP_ID             (0x0BU)     /* Service ID for Gpt_DisableNotification API */
#define GPT_CHECKWAKEUP_ID              (0x0CU)     /* Service ID for Gpt_DisableNotification API */
#define GPT_GETPREDEFTIMERVALUE_ID      (0x0DU)     /* Service ID for Gpt_DisableNotification API */

#define GPT_E_UNINIT                    (0x0AU)    	/* API service called without module initialization */
#define GPT_E_ALREADY_INITIALIZED       (0x0DU)    	/* API service for initialization called when already initialized */
#define GPT_E_INIT_FAILED               (0x0EU)     /* API error return code: Init function failed */
#define GPT_E_PARAM_CHANNEL             (0x14U)    	/* API parameter checking: invalid channel */
#define GPT_E_PARAM_VALUE               (0x15U)    	/* API parameter checking: invalid value */
#define GPT_E_PARAM_POINTER             (0x16U)    	/* API parameter checking: invalid pointer */
#define GPT_E_PARAM_PREDEF_TIMER        (0x17U)     /* API parameter checking: invalid Predef Timer */
#define GPT_E_PARAM_MODE                (0x1FU)     /* API parameter checking: invalid mode */
#define GPT_E_BUSY                      (0x0BU)    	/* API service called when timer channel is still busy (running) */
#define GPT_E_MODE                      (0x0CU)     /* API service called when driver is in wrong mode */

#define GPT_E_SYSTEM                    (0x64U)     /* GPT driver system error */
#define GPT_E_PARAM_CONFIG              (0x65U)     /* API parameter checking: configuration */

/* The number of times the counter generates 100us */
#define GPT_COUTER_100US                (100U)

/* 16bit counter Max */
#define GPT_COUNTER_MAX_16BIT           (65535U)

/* 24bit counter Max */
#define GPT_COUNTER_MAX_24BIT           (16777215U)

/* 32bit counter Max */
#define GPT_COUNTER_MAX_32BIT           (4294967295U)

/******************************************************************************
*                            Enums
*******************************************************************************/
/* Global status of the GPT driver */
typedef enum
{
    GPT_STATE_UNINIT    = 0x00U,        /* The module is in the uninitialized state */
    GPT_STATE_IDLE      = 0x01U         /* The module is in the idle state */
} Gpt_GlobalStateType;

/* Channel status of the GPT driver */
typedef enum
{
    GPT_CH_STATUS_UNINITIALIZED = 0X00U,        /* Uninitalized status */
    GPT_CH_STATUS_INITIALIZED   = 0x01U,        /* Initalized status */
    GPT_CH_STATUS_STOPPED       = 0x02U,        /* Stopped status */
    GPT_CH_STATUS_EXPIRED       = 0x03U,        /* Expired status */
    GPT_CH_STATUS_RUNNING       = 0x04U        /* Running status */
} Gpt_ChannelStatusType;

/* Channel mode of the GPT driver */
typedef enum
{
    GPT_CH_MODE_CONTINUOUS = 0x00U,     /* Continuous mode */
    GPT_CH_MODE_ONESHOT    = 0x01U      /* One-Shot mode */
} Gpt_ChannelModeType;

/* Modes of the GPT driver. */
typedef enum
{
    GPT_MODE_NORMAL = 0x00U,            /* Normal operation mode of the GPT */
    GPT_MODE_SLEEP  = 0x01U             /* Operation for reduced power operation mode. In sleep mode only wakeup capable channels are available. */
} Gpt_ModeType;

/* Type for GPT Predef Timers */
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT      = 0x00U,    /* GPT Predef Timer with tick duration 1µs and range 16bit */
    GPT_PREDEF_TIMER_1US_24BIT      = 0x01U,    /* GPT Predef Timer with tick duration 1µs and range 24bit */
    GPT_PREDEF_TIMER_1US_32BIT      = 0x02U,    /* GPT Predef Timer with tick duration 1µs and range 32bit */
    GPT_PREDEF_TIMER_100US_32BIT    = 0x03U     /* GPT Predef Timer with tick duration 100µs and range 32bit */
} Gpt_PredefTimerType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* GPT drives the global state structure */
typedef struct
{
    uint8   Gpt1usNumber;           /* The number of times the timer generates 1us */
    uint16  Gpt1us16bitNumber;      /* The number of times the timer generates 1us (16bit) */
    uint32  Gpt1us24bitNumber;      /* The number of times the timer generates 1us (24bit) */
    uint32  Gpt1us32bitNumber;      /* The number of times the timer generates 1us (32bit) */
    uint32  Gpt100us32bitNumber;    /* The number of times the timer generates 100us (32bit) */
} Gpt_PredefTimeValueType;

/* GPT drives the global state structure */
typedef struct
{
    Gpt_ChannelStatusType   GptChannelStatus[GPT_CHANNEL_CONFIG_NUMBER];                /* Channel status of the GPT driver */
    boolean                 GptChannelNotificationStatus[GPT_CHANNEL_CONFIG_NUMBER];    /* Channel notification status of the GPT driver */
    Gpt_ValueType           GptTargetValue[GPT_CHANNEL_CONFIG_NUMBER];                  /* Channel target value for the GPT driver */
} Gpt_GlobalType;

/* Channel configuration for the GPT driver */
typedef struct
{
    Gpt_ChannelModeType         GptChannelMode;             /* Channel mode of the GPT driver */
    Gpt_ValueType               GptChannelTickValueMax;     /* The channel maximum tick value of the GPT driver */
    uint32                      GptChannelTickFrequency;    /* The channel tick frequency of the GPT driver */
    Gpt_ChannelNotificationType GptChannelNotification;     /* The channel notification function for the GPT driver */
} Gpt_ChannelConfigType;

/* This is the type of the data structure including the configuration set required for initializing the GPT timer unit. */
typedef struct
{
    TT_CONST uint8                         *GptFtmHardwareChannelMap;   /* Mapping between the hardware channel of the GPT driver and the FTM module */
    TT_CONST Gpt_ChannelConfigType         *GptChannelConfig;           /* Channel configuration for the GPT driver. */
    TT_CONST Gpt_FtmPredefTimerConfigType  *GptFtmPredefTimerConfig;    /* GPT predef timer configuration for the FTM module */
    TT_CONST Gpt_FtmChannelConfigType      *GptFtmChannelConfig;        /* FTM channel configuration for the GPT driver */
    TT_CONST Gpt_FtmModuleConfigType       *GptFtmModuleConfig;         /* FTM module configuration for the GPT driver */
    TT_CONST uint32                        GptCrc;                      /* Crc check value of the GPT driver */
} Gpt_ConfigType;

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
/* This is the type of the data structure including the configuration set required for initializing the GPT timer unit. */
extern TT_CONST Gpt_ConfigType GptConfigData;

#ifdef __cplusplus
}
#endif

#endif
