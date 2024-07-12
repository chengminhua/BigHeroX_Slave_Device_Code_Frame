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
**  FILENAME     : Port_Hw_Types.h                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Port Driver Source File                                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/* Header Protection */
#ifndef PORT_HW_TYPES_H
#define PORT_HW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#ifdef USING_OS_AUTOSAROS
#include "Port_Cfg.h"
#else
#include "Port_Drv_Cfg.h"
#endif

#if defined(USE_DIO_MODULE) && (USE_DIO_MODULE == STD_ON)
#include "Dio_Hw.h"
#include "Dio_Hw_Irq.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PORT_HW_TYPES_VENDOR_ID_H                     1541
#define PORT_HW_TYPES_MODULE_ID_H                     124
#define PORT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define PORT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define PORT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define PORT_HW_TYPES_SW_MAJOR_VERSION_H              1
#define PORT_HW_TYPES_SW_MINOR_VERSION_H              1
#define PORT_HW_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifdef USING_OS_AUTOSAROS
/* Port_Hw_Types.h and Port_Cfg.h file version check */
#if (PORT_HW_TYPES_VENDOR_ID_H != PORT_CFG_VENDOR_ID_H)
    #error "Port_Hw_Types.h and Port_Cfg.h have different vendor ids"
#endif
#if (PORT_HW_TYPES_MODULE_ID_H != PORT_CFG_MODULE_ID_H)
    #error "Port_Hw_Types.h and Port_Cfg.h have different module ids"
#endif
#if ((PORT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != PORT_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != PORT_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != PORT_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Hw_Types.h and Port_Cfg.h are different"
#endif
#if ((PORT_HW_TYPES_SW_MAJOR_VERSION_H != PORT_CFG_SW_MAJOR_VERSION_H) || \
     (PORT_HW_TYPES_SW_MINOR_VERSION_H != PORT_CFG_SW_MINOR_VERSION_H) || \
     (PORT_HW_TYPES_SW_PATCH_VERSION_H != PORT_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Hw_Types.h and Port_Cfg.h are different"
#endif
#else
/* Port_Hw_Types.h and Port_Drv_Cfg.h file version check */
#if (PORT_HW_TYPES_VENDOR_ID_H != PORT_DRV_CFG_VENDOR_ID_H)
    #error "Port_Hw_Types.h and Port_Drv_Cfg.h have different vendor ids"
#endif
#if (PORT_HW_TYPES_MODULE_ID_H != PORT_DRV_CFG_MODULE_ID_H)
    #error "Port_Hw_Types.h and Port_Drv_Cfg.h have different module ids"
#endif
#if ((PORT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != PORT_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != PORT_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != PORT_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Hw_Types.h and Port_Drv_Cfg.h are different"
#endif
#if ((PORT_HW_TYPES_SW_MAJOR_VERSION_H != PORT_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (PORT_HW_TYPES_SW_MINOR_VERSION_H != PORT_DRV_CFG_SW_MINOR_VERSION_H) || \
     (PORT_HW_TYPES_SW_PATCH_VERSION_H != PORT_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Hw_Types.h and Port_Drv_Cfg.h are different"
#endif
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Port_Hw_Types.h Port.h file version check */

/* Macro definitions for API Service ID */
/* Service Id for Port_Init API */
#define PORT_INIT_ID                                         (0x00U)
/* Service Id for Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_ID                            (0x01U)
/* Service Id for Port_RefreshPortDirection API */
#define PORT_REFRESH_PORT_DIRECTION_ID                       (0x02U)
/* Service Id for Port_GetVersionInfo API */
#define PORT_GET_VERSION_INFO_ID                             (0x03U)
/* Service Id for Port_SetPinMode API */
#define PORT_SET_PIN_MODE_ID                                 (0x04U)

/* Macro definitions for Error Codes specified by AUTOSAR */
#define PORT_E_PARAM_PIN                                 (0x0A)
#define PORT_E_DIRECTION_UNCHANGEABLE                    (0x0B)
#define PORT_E_INIT_FAILED                               (0x0C)
#define PORT_E_PARAM_INVALID_MODE                        (0x0D)
#define PORT_E_MODE_UNCHANGEABLE                         (0x0E)
#define PORT_E_UNINIT                                    (0x0F)
#define PORT_E_PARAM_POINTER                             (0x10)

/* Pin maximum configurable number */
#define PORT_PIN_NUM_MAX         (160U)

/* Pin INPUT maximum configurable number */
#define PORT_PIN_NUM_INPUT_GPIO         (147U)
/* Pin OUTPUT maximum configurable number */
#define PORT_PIN_NUM_OUTPUT_GPIO        (127U)

/* GPIO 0-147 input functions list */
#define PORT_PIN_MODE_INPUT_GPIO  PORT_PIN_MODE_INPUT_FUNC00
/* GPIO 148-159 input functions list */
#define PORT_PIN_MODE_INPUT_GPIOE  PORT_PIN_MODE_INPUT_FUNC03
/* GPIO 0-128 out functions list */
#define PORT_PIN_MODE_OUTPUT_GPIO  PORT_PIN_MODE_OUTPUT_FUNC00
/* GPIO 129-159 out functions list */
#define PORT_PIN_MODE_OUTPUT_GPIOE  PORT_PIN_MODE_OUTPUT_FUNC02

/* Pad Register Bit Defines */
/* input offset */
#define PAD_INPUT_OFFSET_FUNC           (0U)
#define PAD_INPUT_OFFSET_IE             (4U)
#define PAD_INPUT_OFFSET_PD             (5U)
#define PAD_INPUT_OFFSET_PU             (6U)
#define PAD_INPUT_CONFIG_LOCK           (7U)

/* output offset */
#define PAD_OUTPUT_OFFSET_FUNC         (0UL)
#define PAD_OUTPUT_OFFSET_PP_OD        (3UL)
#define PAD_OUTPUT_OFFSET_OE           (4UL)
#define PAD_OUTPUT_OFFSET_DRIVE        (5UL)
#define PAD_OUTPUT_FUNC_LOCK           (6UL)

/* get PadID */
#define PAD_GET_REG_INDEX(PadID)           ((PadID) >> 2)
/* get offset */
#define PAD_GET_REG_INNER_OFFSET(PadID)    ((((PadID) & (uint32)0x03)) << 3)
/* output flag */
#define PAD_OUTPUT_FLAG                    (0x10U)

/* Port INFUNC Register address */
#define PORT_GET_INFUNCTION_CFG(Function, ConfigLock, PullDownEnable, PullUpEnable, InputEnable) \
                (((Function) << PAD_INPUT_OFFSET_FUNC) \
                | ((uint32)(((uint32)(ConfigLock)) << PAD_INPUT_CONFIG_LOCK)) \
                | ((uint32)(((uint32)(PullDownEnable)) << PAD_INPUT_OFFSET_PD)) \
                | ((uint32)(PullUpEnable) << PAD_INPUT_OFFSET_PU) \
                | ((uint32)(InputEnable) << PAD_INPUT_OFFSET_IE))
/* Port OUTFUNC Register address */
#define PORT_GET_OUTFUNCTION_CFG(Function, ConfigLock, ModeValue, DriverLevel, OutputEnable) \
                (((Function) << PAD_OUTPUT_OFFSET_FUNC) \
                | ((uint32)(((uint32)(ConfigLock)) << PAD_OUTPUT_FUNC_LOCK)) \
                | ((uint32)(((uint32)(ModeValue)) << PAD_OUTPUT_OFFSET_PP_OD)) \
                | ((uint32)(DriverLevel) << PAD_OUTPUT_OFFSET_DRIVE) \
                | ((uint32)(OutputEnable) << PAD_OUTPUT_OFFSET_OE))

#if (USE_DIO_MODULE == STD_ON)
/* Dio PORT ID */
#define DIO_GET_PORT_FROM_PIN_ID(ChannelId) ((ChannelId) / 32)
/* Dio PIN ID */
#define DIO_GET_BIT_FROM_PIN_ID(ChannelId)  ((ChannelId) % 32)

/* Dio OUTFUNC Register address */
#define DIO_INFUNCTION_SELECT(PinID, InputFunction)  \
                (((PinID) > PORT_PIN_NUM_INPUT_GPIO) ? ((InputFunction) == PORT_PIN_MODE_INPUT_GPIOE) : \
                ((InputFunction) == PORT_PIN_MODE_INPUT_GPIO))
/* Dio OUTFUNC Register address */
#define DIO_OUTFUNCTION_SELECT(PinID, OutputFunction)  \
                (((PinID) > PORT_PIN_NUM_OUTPUT_GPIO) ? ((OutputFunction) == PORT_PIN_MODE_OUTPUT_GPIOE) : \
                 ((OutputFunction) == PORT_PIN_MODE_OUTPUT_GPIO))
#endif


/******************************************************************************
*                            Enums
*******************************************************************************/
/*enum definitions */
typedef enum
{
    /* INPUT PIN is assigned with value 0, like UART RX*/
    PORT_PIN_IN  = 0U,
    /* OUTPUT PIN is assigned with value 1, like UART TX*/
    PORT_PIN_OUT = 1U,
    /* OUTPUT PIN is assigned with value 2, like I2C SDA*/
    PORT_PIN_IN_OUT = 2U
} Port_PinDirectionType;

typedef enum
{
    /* Push Pull*/
    PORT_PIN_OUTPUT_MODE_PP  = 0U,
    /* Open Drain*/
    PORT_PIN_OUTPUT_MODE_OD  = 1U
} Port_PinOutputModeValueType;

/* output driver level */
typedef enum
{
    PORT_PIN_DRIVER_LEVEL_0,
    PORT_PIN_DRIVER_LEVEL_1
} Port_PinDriverLevelType;

/* input functions list */
typedef enum
{
    PORT_PIN_MODE_INPUT_FUNC00,
    PORT_PIN_MODE_INPUT_FUNC01,
    PORT_PIN_MODE_INPUT_FUNC02,
    PORT_PIN_MODE_INPUT_FUNC03,
    PORT_PIN_MODE_INPUT_FUNC04,
    PORT_PIN_MODE_INPUT_FUNC05,
    PORT_PIN_MODE_INPUT_FUNC06,
    PORT_PIN_MODE_INPUT_FUNC07,
    PORT_PIN_MODE_INPUT_FUNC08,
    PORT_PIN_MODE_INPUT_FUNC09,
    PORT_PIN_MODE_INPUT_FUNC10,
    PORT_PIN_MODE_INPUT_FUNC11,
    PORT_PIN_MODE_INPUT_FUNC12,
    PORT_PIN_MODE_INPUT_FUNC13,
    PORT_PIN_MODE_INPUT_FUNC14,
    PORT_PIN_MODE_INPUT_FUNC15
}Port_PinModeInputFunctionType;

/* out functions list */
typedef enum
{
    PORT_PIN_MODE_OUTPUT_FUNC00 = 0,
    PORT_PIN_MODE_OUTPUT_FUNC01 = 1,
    PORT_PIN_MODE_OUTPUT_FUNC02 = 2,
    PORT_PIN_MODE_OUTPUT_FUNC03 = 3,
    PORT_PIN_MODE_OUTPUT_FUNC04 = 4,
    PORT_PIN_MODE_OUTPUT_FUNC05 = 5,
    PORT_PIN_MODE_OUTPUT_FUNC06 = 6,
    PORT_PIN_MODE_OUTPUT_FUNC07 = 7
}Port_PinModeOutputFunctionType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* Pin  number */
typedef uint32 Port_PinType;
/* Pin Mode configurable number */
typedef uint32 Port_PinModeType;

/* pin detaul config */
typedef struct
{
    /* pin Gtm mode out enable */
    boolean PinModeGtmOut;
    /* pin input enable */
    boolean PinInputEnable;
    /* pin output enable */
    boolean PinOutputEnable;
    /* pin input config lock enable */
    boolean PinInputConfigLock;
    /* pin output config lock enable */
    boolean PinOutputFuncLock;
    /* pin input Pull Down enable */
    boolean PinInputPullDownEnable;
    /* pin input Pull Up enable */
    boolean PinInputPullUpEnable;
    /* Dio input Interrupt enable */
    boolean PinInputInterruptUsed;
    /* pin Gtm select function */
    uint8 PinGtmOutSelectFunc;
#if defined(USE_DIO_MODULE) && (USE_DIO_MODULE == STD_ON)
    /* Dio Interrupt Trigger */
    Dio_ExitTriggerType PinExitTrigger;
#endif
    /* pin Direction */
    Port_PinDirectionType PinDirection;
    /* pin input select function */
    Port_PinModeInputFunctionType PinModeInputFunction;
    /* pin output select function */
    Port_PinModeOutputFunctionType PinModeOutputFunction;
    /* pin Driver  Level */
    Port_PinDriverLevelType PinDriverLevel;
    /* pin output mode */
    Port_PinOutputModeValueType PinOutputModeValue;
    /* pin Gtm out enable */
    uint16 PinGtmOutSelect;
}Port_PinDetailCfgType;

/* pin total config */
typedef struct
{
    /* Pin ID */
    uint32 PinID;
    /* Pin initial select number */
    uint32 PinInitialSelectNumber;
    /* Pin configuration */
    TT_CONST Port_PinDetailCfgType *PinDetailCfg;
}Port_PinTotalCfgType;

/* Port map */
typedef struct
{
    /* Pin Map */
    TT_CONST uint32 *PinMap;
    /* Pin DirectionChangeable Map */
    TT_CONST uint32 *PinDirectionChangeableMap;
    /* Pin ModeChangeable Map */
    TT_CONST uint32 *PinModeChangeableMap;
}Port_PinMapType;

/* container entry */
typedef struct
{
    /* Port Number of pins */
    uint32 Port_NumberOfPortPins;
    /* Total configuration of pin */
    TT_CONST Port_PinTotalCfgType *PinTotalCfg;
}Port_ContainerType;

/* function struct entry */
typedef struct
{
    /* Port Number */
    uint32 Port_NumberOfContainers;
    /* container entry */
    TT_CONST Port_ContainerType *Containers;
    /* Port map */
    TT_CONST Port_PinMapType *PortPinMap;
    uint32 Crc;
}Port_ConfigType;

typedef struct
{
    /* pin Direction */
    Port_PinDirectionType Direction;
    /* pin output select function */
    Port_PinModeOutputFunctionType PinOutputMode;
   /* pin input select function */
    Port_PinModeInputFunctionType PinInputMode;
    /* pin Driver  Level */
    Port_PinDriverLevelType DriverLevel;
    /* pin input config lock enable */
    boolean PinInputConfigLock;
    /* pin output config lock enable */
    boolean PinOutputFuncLock;
    /* pin input enable */
    boolean PinInputEnable;
    /* pin output enable */
    boolean PinOutputEnable;
    /* pin input Pull Down enable */
    boolean PinInputPullDownEnable;
    /* pin output Pull Down enable */
    boolean PinInputPullUpEnable;
    /* Dio input Interrupt enable */
    boolean PinInputInterruptUsed;
#if defined(USE_DIO_MODULE) && (USE_DIO_MODULE == STD_ON)
    /* Dio Interrupt Trigger */
    Dio_ExitTriggerType PinExitTrigger;
#endif
    /* pin output mode */
    Port_PinOutputModeValueType PinOutputModeValue;
}Port_PinAllCfgType;

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
/* Port Config Data */
extern TT_CONST Port_ConfigType Port_ConfigData;

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif

