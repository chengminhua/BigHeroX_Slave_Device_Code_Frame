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
**  FILENAME     : Port_Hw.h                                                  **
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
#ifndef PORT_HW_H
#define PORT_HW_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Port_Hw_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PORT_HW_VENDOR_ID_H                     1541
#define PORT_HW_MODULE_ID_H                     124
#define PORT_HW_AR_RELEASE_MAJOR_VERSION_H      4
#define PORT_HW_AR_RELEASE_MINOR_VERSION_H      4
#define PORT_HW_AR_RELEASE_PATCH_VERSION_H      0
#define PORT_HW_SW_MAJOR_VERSION_H              1
#define PORT_HW_SW_MINOR_VERSION_H              1
#define PORT_HW_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Port_Hw.h and Port_Hw_Types.h file version check */
#if (PORT_HW_VENDOR_ID_H != PORT_HW_TYPES_VENDOR_ID_H)
    #error "Port_Hw.h and Port_Hw_Types.h have different vendor ids"
#endif
#if (PORT_HW_MODULE_ID_H != PORT_HW_TYPES_MODULE_ID_H)
    #error "Port_Hw.h and Port_Hw_Types.h have different module ids"
#endif
#if ((PORT_HW_AR_RELEASE_MAJOR_VERSION_H != PORT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_HW_AR_RELEASE_MINOR_VERSION_H != PORT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_HW_AR_RELEASE_PATCH_VERSION_H != PORT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Hw.h and Port_Hw_Types.h are different"
#endif
#if ((PORT_HW_SW_MAJOR_VERSION_H != PORT_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (PORT_HW_SW_MINOR_VERSION_H != PORT_HW_TYPES_SW_MINOR_VERSION_H) || \
     (PORT_HW_SW_PATCH_VERSION_H != PORT_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Hw.h and Port_Hw_Types.h are different"
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
/**
* @brief        Port_Hw_Init
* @details      Initializes the Port Driver module.
* @param[in]    ConfigPtr - Pointer to configuration set
* @return
* @retval
* @pre
*/
TT_RetType Port_Hw_Init(TT_CONST Port_ConfigType *ConfigPtr);
#define PORT_STOP_SEC_CODE_SLOW
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
* @brief        Port_Hal_SetPinDirection
* @details      Initializes the Port Driver module.
* @param[in]    Pin - Pin ID
*               Direction - Pin Direction
*               ConfigPtr - Pointer to configuration set
* @return
* @retval
* @pre
*/
TT_RetType Port_Hw_SetPinDirection(TT_CONST Port_PinType Pin, TT_CONST Port_PinDirectionType Direction, TT_CONST Port_ConfigType *ConfigPtr);

/**
* @brief        Port_Hal_SetPinMode
* @details      Initializes the Port Driver module.
* @param[in]    Pin - Pin ID
*               Mode - Pin Mode
*               ConfigPtr - Pointer to configuration set
* @return
* @retval
* @pre
*/
TT_RetType Port_Hw_SetPinMode(TT_CONST Port_PinType Pin, TT_CONST Port_PinModeType Mode,  TT_CONST Port_ConfigType *ConfigPtr);

/**
* @brief        Port_Hw_SetPinAllCfg
* @details      Initializes the Port Driver module.
* @param[in]    Pin - Pin ID
*               PinAllCfg - Pin all configuration
* @return
* @retval
* @pre
*/
TT_RetType Port_Hw_SetPinAllCfg(TT_CONST Port_PinType Pin,TT_CONST Port_PinAllCfgType *PinAllCfg);

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif

