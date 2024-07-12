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
**  FILENAME     : Can_Cfg.h                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Can Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/

#ifndef CAN_CFG_H
#define CAN_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/

#include "Can_PBcfg.h"
#include "Can_GeneralTypes.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
/*
* @file           Can_Cfg.h
*/
#define CAN_CFG_VENDOR_ID_H                     1541
#define CAN_CFG_MODULE_ID_H                     80
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION_H      4
#define CAN_CFG_AR_RELEASE_MINOR_VERSION_H      4
#define CAN_CFG_AR_RELEASE_PATCH_VERSION_H      0
#define CAN_CFG_SW_MAJOR_VERSION_H              1
#define CAN_CFG_SW_MINOR_VERSION_H              1
#define CAN_CFG_SW_PATCH_VERSION_H              0
/******************************************************************************
*                       File Version Checks
******************************************************************************/

/* Check if header file and Can_PBcfg.h configuration header file are of the same vendor */
#if (CAN_PBCFG_VENDOR_ID_H != CAN_CFG_VENDOR_ID_H)
    #error "Can_PBcfg.h and Can_Cfg.h have different vendor ids"
#endif
#if (CAN_PBCFG_MODULE_ID_H != CAN_CFG_MODULE_ID_H)
    #error "Can_PBcfg.c and Can_Cfg.h have different module ids"
#endif
 /* Check if header file and Can_PBcfg.h configuration header file are of the same Autosar version */
#if ((CAN_PBCFG_AR_RELEASE_MAJOR_VERSION_H != CAN_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
(CAN_PBCFG_AR_RELEASE_MINOR_VERSION_H != CAN_CFG_AR_RELEASE_MINOR_VERSION_H) || \
(CAN_PBCFG_AR_RELEASE_PATCH_VERSION_H != CAN_CFG_AR_RELEASE_PATCH_VERSION_H) \
)
    #error "AutoSar Version Numbers of Can_PBcfg.h and Can_Cfg.h are different"
#endif
/* Check if header file and Can_PBcfg.h configuration header file are of the same software version */
#if ((CAN_PBCFG_SW_MAJOR_VERSION_H != CAN_CFG_SW_MAJOR_VERSION_H) || \
(CAN_PBCFG_SW_MINOR_VERSION_H != CAN_CFG_SW_MINOR_VERSION_H) || \
(CAN_PBCFG_SW_PATCH_VERSION_H != CAN_CFG_SW_PATCH_VERSION_H) \
)
    #error "Software Version Numbers of Can_PBcfg.h and Can_Cfg.h are different"
#endif

/* Check if header file and Can_GeneralTypes.h configuration header file are of the same vendor */
#if (CAN_GENERALTYPES_VENDOR_ID_H != CAN_CFG_VENDOR_ID_H)
    #error "Can_GeneralTypes.h and Can_Cfg.h have different vendor ids"
#endif
#if (CAN_GENERALTYPES_MODULE_ID_H != CAN_CFG_MODULE_ID_H)
    #error "Can_GeneralTypes.h and Can_Cfg.h have different module ids"
#endif
 /* Check if header file and Can_GeneralTypes.h configuration header file are of the same Autosar version */
#if ((CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION_H != CAN_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
(CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION_H != CAN_CFG_AR_RELEASE_MINOR_VERSION_H) || \
(CAN_GENERALTYPES_AR_RELEASE_PATCH_VERSION_H != CAN_CFG_AR_RELEASE_PATCH_VERSION_H) \
)
    #error "AutoSar Version Numbers of Can_GeneralTypes.h and Can_Cfg.h are different"
#endif
/* Check if header file and Can_GeneralTypes.h configuration header file are of the same software version */
#if ((CAN_GENERALTYPES_SW_MAJOR_VERSION_H != CAN_CFG_SW_MAJOR_VERSION_H) || \
(CAN_GENERALTYPES_SW_MINOR_VERSION_H != CAN_CFG_SW_MINOR_VERSION_H) || \
(CAN_GENERALTYPES_SW_PATCH_VERSION_H != CAN_CFG_SW_PATCH_VERSION_H) \
)
    #error "Software Version Numbers of Can_GeneralTypes.h and Can_Cfg.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/**
*   @brief      Enable/Disable Precompile Support
*/
#define CAN_PRECOMPILE_SUPPORT          (STD_ON)

/**
*   @brief      Number of Can Controller Support
*/
#define CAN_HWCONTROLLER_SUPPORT        (8U)

/**
*   @brief      Controller unsed
*/
#define CAN_CONTROLLER_UNUSED           (0xFFU)

/**
*   @brief      The definition represent for Message buffer index which not assigned for any Hw Object
*/
#define CAN_HWOBJ_UNMAPPED              (0xFFFFU)

/**
*   @brief      Number Of Hw Message Buffer support
*/
#define CAN_HWMB_COUNT                  (128U)

/**
 *  @brief      The definition of TimeStamp Enable Support for Hw Objects
 */
#define CAN_TIMESTAMP_ENABLE            (STD_ON)

/**
*   @brief      Enable/Disable Development Error Detection and Notification
*/
#define CAN_DEV_ERROR_DETECT            (STD_OFF)

/**
*   @brief      Enable/Disable support Can_GetVersionInfo API
*/
#define CAN_VERSION_INFO_API            (STD_OFF)

/**
*   @brief      Enable/Disable support Can_SetBaudrate API
*/
#define CAN_SET_BAUDRATE_API            (STD_OFF)

/**
*   @brief      Enable/Disable support Can_AbortMb API
*/
#define CAN_ABORT_MB_API                (STD_OFF)

/**
*   @brief      Enable/Disable LPdu Callout Function
*/
#define CAN_LPDU_CALLOUT_FUNC_ENABLE    (STD_OFF)

/**
*   @brief      Enable/Disable Extended Range of Can Hw Object
*/
#define CAN_MBCOUNTEXTENSION            (STD_OFF)

/**
*   @brief      Instance of the Can Hw unit
*/
#define CAN_INSTANCE_ID                 (0U)

/**
*   @brief      Enable/Disable support Listen Only Mode
*/
#define CAN_LISTEN_ONLY_MODE            (STD_OFF)

/**
* @brief          Enable/Disable LPdu Receive callout function support
*/
#define CAN_LPDU_CALLOUT_SUPPORT        (STD_OFF)
#define CAN_LPDU_CALLOUT_FUNC_CALLED    

/**
*   @brief      Symbolic Name generated for CanMainFunctionRWPeriods
*/
#define CanMainFunctionRWPeriods0       (0U)

/**
*   @brief      Period for cyclic call of Main Function Read/Write
*/
#define CAN_MAINFUNCTION_MULTIPLE_WRITE (STD_OFF)
#define CAN_MAINFUNCTION_MULTIPLE_READ  (STD_OFF)       

/**
*   @brief      Period for cyclic call of Main Function Mode
*/
#define CAN_MAINFUNCTION_MODE_PERIOD    (0.001F)

/**
*   @brief      Number Of Can Controller Config
*/
#define CAN_CONTROLLER_CONFIG_COUNT     (3U)
/**
*   @brief      Number Of HardwareObject Config
*/
#define CAN_HWOBJECT_CONFIG_COUNT       (6U)
/**
*   @brief      Symbolic Name generated for Can Controller
*/

#define CanHwUnit_2                     ((uint8)2U)
    
#define CanController_0                 ((uint8)0U)

#define CanHwUnit_1                     ((uint8)1U)
    
#define CanController_1                 ((uint8)1U)

#define CanHwUnit_4                     ((uint8)4U)
    
#define CanController_2                 ((uint8)2U)

/**
*   @brief      Supporting Pretended Networking
*/
#define CAN_PUBLIC_ICOM_SUPPORT         (STD_OFF)

/**
*   @brief      Symbolic Name generated for Can HardwareObject
*/

#define CanHardwareObject0              ((Can_HwHandleType)0U)
#define CanHardwareObject1              ((Can_HwHandleType)1U)
#define CanHardwareObject2              ((Can_HwHandleType)2U)
#define CanHardwareObject3              ((Can_HwHandleType)3U)
#define CanHardwareObject4              ((Can_HwHandleType)4U)
#define CanHardwareObject5              ((Can_HwHandleType)5U)

/**
*   @brief      Enable/Disable support  Can_CheckWakeup API
*/
#define CAN_CHECK_WAKEUP_API            (STD_OFF)

/**
*   @brief      Can Tx Polling support
*/
#define CAN_TX_POLLING_SUPPORT          (STD_ON)

/**
*   @brief      Can Rx Polling support
*/
#define CAN_RX_POLLING_SUPPORT          (STD_OFF)

/**
*   @brief      Can Bus Off Polling support
*/
#define CAN_BUSOFF_POLLING_SUPPORT      (STD_OFF)

/**
*   @brief      Can Wakeup Polling support
*/
#define CAN_WAKEUP_POLLING_SUPPORT      (STD_ON)

/**
*   @brief      Can Wakeup support
*/
#define CAN_WAKEUP_SUPPORT              (STD_OFF)

/**
*   @brief      Can Rx/Tx common interrupt support
*/

/**
*   @brief      The definition was represented for at least one Hw Object enabled trigger transmit.
*/
#define CAN_TRIGGER_TRANSMIT_USED       (STD_OFF)

/**
*   @brief      Can Enhanced RxFiFo enabling.
*/
#define CAN_ENHANCED_FIFO_ENABLED       (STD_OFF)

#define CAN_CONFIG_EXT

/******************************************************************************
*                            FUNCTION PROTOTYPES
*******************************************************************************/
#define CAN_START_SEC_CODE_FAST
/* @violates @ref Can_PBcfg_c_REF_1 MISRA 2012 Required Directive 4.10 */
#include "Can_MemMap.h"

extern void Can0_ErrorNotify(void);
extern void Can1_ErrorNotify(void);
extern void Can6_ErrorNotify(void);

#if (CAN_TIMESTAMP_ENABLE == STD_ON)
#endif

#define CAN_STOP_SEC_CODE_FAST
/* @violates @ref Can_PBcfg_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_PBcfg_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"

/******************************************************************************
*                            Defines Checks
******************************************************************************/
#ifndef CAN_PRECOMPILE_SUPPORT
    #error "CAN_PRECOMPILE_SUPPORT error"
#else
#if((CAN_PRECOMPILE_SUPPORT != STD_ON) && (CAN_PRECOMPILE_SUPPORT != STD_OFF))
    #error "CAN_PRECOMPILE_SUPPORT error"
#endif
#endif

#ifndef CAN_HWCONTROLLER_SUPPORT
    #error "CAN_HWCONTROLLER_SUPPORT error"
#else
#if(CAN_HWCONTROLLER_SUPPORT != 8U)
    #error "CAN_HWCONTROLLER_SUPPORT error"
#endif
#endif

#ifndef CAN_CONTROLLER_UNUSED
    #error "CAN_CONTROLLER_UNUSED error"
#else
#if(CAN_CONTROLLER_UNUSED != 0xFFU)
    #error "CAN_CONTROLLER_UNUSED error"
#endif
#endif

#ifndef CAN_HWOBJ_UNMAPPED
    #error "CAN_HWOBJ_UNMAPPED error"
#else
#if(CAN_HWOBJ_UNMAPPED != 0xFFFFU)
    #error "CAN_HWOBJ_UNMAPPED error"
#endif
#endif

#ifndef CAN_HWMB_COUNT
    #error "CAN_HWMB_COUNT error"
#else
#if(CAN_HWMB_COUNT != 128U)
    #error "CAN_HWMB_COUNT error"
#endif
#endif

#ifndef CAN_TIMESTAMP_ENABLE
    #error "CAN_TIMESTAMP_ENABLE error"
#else
#if((CAN_TIMESTAMP_ENABLE != STD_ON) && (CAN_TIMESTAMP_ENABLE != STD_OFF))
    #error "CAN_TIMESTAMP_ENABLE error"
#endif
#endif

#ifndef CAN_DEV_ERROR_DETECT
    #error "CAN_DEV_ERROR_DETECT error"
#else
#if((CAN_DEV_ERROR_DETECT != STD_ON) && (CAN_DEV_ERROR_DETECT != STD_OFF))
    #error "CAN_DEV_ERROR_DETECT error"
#endif
#endif

#ifndef CAN_VERSION_INFO_API
    #error "CAN_VERSION_INFO_API error"
#else
#if((CAN_VERSION_INFO_API != STD_ON) && (CAN_VERSION_INFO_API != STD_OFF))
    #error "CAN_VERSION_INFO_API error"
#endif
#endif

#ifndef CAN_SET_BAUDRATE_API
    #error "CAN_SET_BAUDRATE_API error"
#else
#if((CAN_SET_BAUDRATE_API != STD_ON) && (CAN_SET_BAUDRATE_API != STD_OFF))
    #error "CAN_SET_BAUDRATE_API error"
#endif
#endif

#ifndef CAN_ABORT_MB_API
    #error "CAN_ABORT_MB_API error"
#else
#if((CAN_ABORT_MB_API != STD_ON) && (CAN_ABORT_MB_API != STD_OFF))
    #error "CAN_ABORT_MB_API error"
#endif
#endif

#ifndef CAN_LPDU_CALLOUT_FUNC_ENABLE
    #error "CAN_LPDU_CALLOUT_FUNC_ENABLE error"
#else
#if((CAN_LPDU_CALLOUT_FUNC_ENABLE != STD_ON) && (CAN_LPDU_CALLOUT_FUNC_ENABLE != STD_OFF))
    #error "CAN_LPDU_CALLOUT_FUNC_ENABLE error"
#endif
#endif

#ifndef CAN_MBCOUNTEXTENSION
    #error "CAN_MBCOUNTEXTENSION error"
#else
#if((CAN_MBCOUNTEXTENSION != STD_ON) && (CAN_MBCOUNTEXTENSION != STD_OFF))
    #error "CAN_MBCOUNTEXTENSION error"
#endif
#endif

#ifndef CAN_INSTANCE_ID
    #error "CAN_INSTANCE_ID error"
#else
#if(CAN_INSTANCE_ID > 255U)
    #error "CAN_INSTANCE_ID error"
#endif
#endif

#ifndef CAN_LISTEN_ONLY_MODE
    #error "CAN_LISTEN_ONLY_MODE error"
#else
#if((CAN_LISTEN_ONLY_MODE != STD_ON) && (CAN_LISTEN_ONLY_MODE != STD_OFF))
    #error "CAN_LISTEN_ONLY_MODE error"
#endif
#endif

#ifndef CAN_LPDU_CALLOUT_SUPPORT
    #error "CAN_LPDU_CALLOUT_SUPPORT error"
#else
#if((CAN_LPDU_CALLOUT_SUPPORT != STD_ON) && (CAN_LPDU_CALLOUT_SUPPORT != STD_OFF))
    #error "CAN_LPDU_CALLOUT_SUPPORT error"
#endif
#endif

#ifndef CAN_CONTROLLER_CONFIG_COUNT
    #error "CAN_CONTROLLER_CONFIG_COUNT error"
#else 
#if(CAN_CONTROLLER_CONFIG_COUNT > 8U)
    #error "CAN_CONTROLLER_CONFIG_COUNT error"
#endif
#endif

#ifndef CAN_HWOBJECT_CONFIG_COUNT
    #error "CAN_HWOBJECT_CONFIG_COUNT error"
#else     
#if(CAN_HWOBJECT_CONFIG_COUNT > 128U)
    #error "CAN_HWOBJECT_CONFIG_COUNT error"
#endif
#endif

#ifndef CAN_PUBLIC_ICOM_SUPPORT
    #error "CAN_PUBLIC_ICOM_SUPPORT error"
#else     
#if((CAN_PUBLIC_ICOM_SUPPORT != STD_ON) && (CAN_PUBLIC_ICOM_SUPPORT != STD_OFF))
    #error "CAN_PUBLIC_ICOM_SUPPORT error"
#endif
#endif

#ifndef CAN_CHECK_WAKEUP_API
    #error "CAN_CHECK_WAKEUP_API error"
#else     
#if((CAN_CHECK_WAKEUP_API != STD_ON) && (CAN_CHECK_WAKEUP_API != STD_OFF))
    #error "CAN_CHECK_WAKEUP_API error"
#endif
#endif

#ifndef CAN_TX_POLLING_SUPPORT
    #error "CAN_TX_POLLING_SUPPORT error"
#else 
#if((CAN_TX_POLLING_SUPPORT != STD_ON) && (CAN_TX_POLLING_SUPPORT != STD_OFF))
    #error "CAN_TX_POLLING_SUPPORT error"
#endif
#endif

#ifndef CAN_RX_POLLING_SUPPORT
    #error "CAN_RX_POLLING_SUPPORT error"
#else 
#if((CAN_RX_POLLING_SUPPORT != STD_ON) && (CAN_RX_POLLING_SUPPORT != STD_OFF))
    #error "CAN_RX_POLLING_SUPPORT error"
#endif
#endif

#ifndef CAN_BUSOFF_POLLING_SUPPORT
    #error "CAN_BUSOFF_POLLING_SUPPORT error"
#else 
#if((CAN_BUSOFF_POLLING_SUPPORT != STD_ON) && (CAN_BUSOFF_POLLING_SUPPORT != STD_OFF))
    #error "CAN_BUSOFF_POLLING_SUPPORT error"
#endif
#endif

#ifndef CAN_WAKEUP_POLLING_SUPPORT
    #error "CAN_WAKEUP_POLLING_SUPPORT error"
#else 
#if((CAN_WAKEUP_POLLING_SUPPORT != STD_ON) && (CAN_WAKEUP_POLLING_SUPPORT != STD_OFF))
    #error "CAN_WAKEUP_POLLING_SUPPORT error"
#endif
#endif

#ifndef CAN_WAKEUP_SUPPORT
    #error "CAN_WAKEUP_SUPPORT error"
#else
#if((CAN_WAKEUP_SUPPORT != STD_ON) && (CAN_WAKEUP_SUPPORT != STD_OFF))
    #error "CAN_WAKEUP_SUPPORT error"
#endif
#endif

#ifndef CAN_TRIGGER_TRANSMIT_USED
    #error "CAN_TRIGGER_TRANSMIT_USED error"
#else
#if((CAN_TRIGGER_TRANSMIT_USED != STD_ON) && (CAN_TRIGGER_TRANSMIT_USED != STD_OFF))
    #error "CAN_TRIGGER_TRANSMIT_USED error"
#endif
#endif

#ifndef CAN_ENHANCED_FIFO_ENABLED
    #error "CAN_ENHANCED_FIFO_ENABLED error"
#else
#if((CAN_ENHANCED_FIFO_ENABLED != STD_ON) && (CAN_ENHANCED_FIFO_ENABLED != STD_OFF))
    #error "CAN_ENHANCED_FIFO_ENABLED error"
#endif
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _CAN_CFG_H_ */
