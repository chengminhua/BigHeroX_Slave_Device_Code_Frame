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
**  FILENAME     : Port_Drv.h                                                 **
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
#ifndef PORT_DRV_H
#define PORT_DRV_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Port_Hw.h"
#include "Port_Drv_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PORT_DRV_VENDOR_ID_H                     1541
#define PORT_DRV_MODULE_ID_H                     124
#define PORT_DRV_AR_RELEASE_MAJOR_VERSION_H      4
#define PORT_DRV_AR_RELEASE_MINOR_VERSION_H      4
#define PORT_DRV_AR_RELEASE_PATCH_VERSION_H      0
#define PORT_DRV_SW_MAJOR_VERSION_H              1
#define PORT_DRV_SW_MINOR_VERSION_H              1
#define PORT_DRV_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Port_Drv.h and Port_Hw.h file version check */
#if (PORT_DRV_VENDOR_ID_H != PORT_HW_VENDOR_ID_H)
    #error "Port_Drv.h and Port_Hw.h have different vendor ids"
#endif
#if (PORT_DRV_MODULE_ID_H != PORT_HW_MODULE_ID_H)
    #error "Port_Drv.h and Port_Hw.h have different module ids"
#endif
#if ((PORT_DRV_AR_RELEASE_MAJOR_VERSION_H != PORT_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_DRV_AR_RELEASE_MINOR_VERSION_H != PORT_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_DRV_AR_RELEASE_PATCH_VERSION_H != PORT_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Drv.h and Port_Hw.h are different"
#endif
#if ((PORT_DRV_SW_MAJOR_VERSION_H != PORT_HW_SW_MAJOR_VERSION_H) || \
     (PORT_DRV_SW_MINOR_VERSION_H != PORT_HW_SW_MINOR_VERSION_H) || \
     (PORT_DRV_SW_PATCH_VERSION_H != PORT_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Drv.h and Port_Hw.h are different"
#endif

/* Port_Drv.h and Port_Drv_Types.h file version check */
#if (PORT_DRV_VENDOR_ID_H != PORT_DRV_TYPES_VENDOR_ID_H)
    #error "Port_Drv.h and Port_Drv_Types.h have different vendor ids"
#endif
#if (PORT_DRV_MODULE_ID_H != PORT_DRV_TYPES_MODULE_ID_H)
    #error "Port_Drv.h and Port_Drv_Types.h have different module ids"
#endif
#if ((PORT_DRV_AR_RELEASE_MAJOR_VERSION_H != PORT_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_DRV_AR_RELEASE_MINOR_VERSION_H != PORT_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_DRV_AR_RELEASE_PATCH_VERSION_H != PORT_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Drv.h and Port_Drv_Types.h are different"
#endif
#if ((PORT_DRV_SW_MAJOR_VERSION_H != PORT_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (PORT_DRV_SW_MINOR_VERSION_H != PORT_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (PORT_DRV_SW_PATCH_VERSION_H != PORT_DRV_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Drv.h and Port_Drv_Types.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

#define PORT_START_SEC_CODE_SLOW
#include "Port_MemMap.h"
/******************************************************************************
*  Service name     : Port_Drv_Init
*  Syntax           : TT_RetType Port_Drv_Init(TT_CONST Port_ConfigType *ConfigPtr)
*  Service ID       : 100
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : ConfigPtr - Pointer to configuration set
*  Parameters (out) : None
*  Return value     : None
*  Description      : Initializes the Port Driver module.
******************************************************************************/
TT_RetType Port_Drv_Init(TT_CONST Port_ConfigType *ConfigPtr);
#define PORT_STOP_SEC_CODE_SLOW
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/******************************************************************************
*  Service name     : Port_Hw_SetPinDirection
*  Syntax           : TT_RetType Port_Drv_SetPinDirection(
*                       TT_CONST Port_PinType Pin,
*                       TT_CONST Port_PinDirectionType Direction)
*  Service ID       : 101
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Pin - Pin ID
*                     Direction - Pin Direction
*  Parameters (out) : None
*  Return value     : None
*  Description      : Sets the port pin direction.
******************************************************************************/
TT_RetType Port_Drv_SetPinDirection(TT_CONST Port_PinType Pin, TT_CONST Port_PinDirectionType Direction);

/******************************************************************************
*  Service name     : Port_Drv_SetPinMode
*  Syntax           : TT_RetType Port_Drv_SetPinMode(
*                     TT_CONST Port_PinType Pin,
*                     TT_CONST Port_PinModeType Mode)
*  Service ID       : 102
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Pin - Pin ID
*                     Mode - Pin Mode
*  Parameters (out) : None
*  Return value     : None
*  Description      : Sets the PORT pin mode.
******************************************************************************/
TT_RetType Port_Drv_SetPinMode(TT_CONST Port_PinType Pin, TT_CONST Port_PinModeType Mode);

/******************************************************************************
*  Service name     : Port_Drv_SetPinAllCfg
*  Syntax           : TT_RetType Port_Drv_SetPinAllCfg(
*                     TT_CONST Port_PinType Pin,
*                     TT_CONST Port_PinAllCfgType *PinAllCfg)
*  Service ID       : 103
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Pin - Pin ID
*                     PinAllCfg - Pin configuration
*  Parameters (out) : None
*  Return value     : None
*  Description      : Sets the PORT pin all configurations.
******************************************************************************/
TT_RetType Port_Drv_SetPinAllCfg(TT_CONST Port_PinType Pin,TT_CONST Port_PinAllCfgType *PinAllCfg);

/******************************************************************************
*  Service name     : Port_Drv_GetVersionInfo
*  Syntax           : TT_RetType Port_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo)
*  Service ID       : 104
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : VersionInfo: Pointer to where to store the version
                      information of this module
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Returns the version information of this module.
******************************************************************************/
TT_RetType Port_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"



#ifdef __cplusplus
}
#endif

#endif

