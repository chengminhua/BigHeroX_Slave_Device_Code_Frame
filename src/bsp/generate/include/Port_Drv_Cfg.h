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
**  FILENAME     : Port_Drv_Cfg.h                                             **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Port Driver Configuration Generated File                   **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.0.0]:                                                                    **
*******************************************************************************/
#ifndef PORT_DRV_CFG_H
#define PORT_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/	
#include "A8V2E_SCU.h"
#include "A8V2E_GPIO.h"
#include "A8V2E_GTM.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PORT_DRV_CFG_VENDOR_ID_H                      1541
#define PORT_DRV_CFG_MODULE_ID_H                      124

#define PORT_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H       4
#define PORT_DRV_CFG_AR_RELEASE_MINOR_VERSION_H       4
#define PORT_DRV_CFG_AR_RELEASE_REVISION_VERSION_H    0

#define PORT_DRV_CFG_SW_MAJOR_VERSION_H               1
#define PORT_DRV_CFG_SW_MINOR_VERSION_H               1
#define PORT_DRV_CFG_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_SCU.h Port_Drv_Cfg.h file version check */
#if (A8V2E_SCU_VENDOR_ID_H != PORT_DRV_CFG_VENDOR_ID_H)
    #error "A8V2E_SCU.h and Port_Drv_Cfg.h have different vendor ids"
#endif

#if ((A8V2E_SCU_AR_RELEASE_MAJOR_VERSION_H != PORT_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_SCU_AR_RELEASE_MINOR_VERSION_H != PORT_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) 	  || \
     (A8V2E_SCU_AR_RELEASE_PATCH_VERSION_H != PORT_DRV_CFG_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_SCU.h and Port_Drv_Cfg.h are different"
#endif

#if ((A8V2E_SCU_SW_MAJOR_VERSION_H != PORT_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (A8V2E_SCU_SW_MINOR_VERSION_H != PORT_DRV_CFG_SW_MINOR_VERSION_H) 	  || \
     (A8V2E_SCU_SW_PATCH_VERSION_H != PORT_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_SCU.h and Port_Drv_Cfg.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define PORT_MODULE_ID                            PORT_DRV_CFG_MODULE_ID_H

#define PORT_INSTANCE_ID                          (0U)

#define PORT_PRECOMPILE_SUPPORT

#define PORT_DEV_ERROR_DETECT                     (STD_OFF)

#define PORT_VERSION_INFO_API                     (STD_OFF)

#define PORT_SET_PIN_MODE_API                     (STD_OFF)

#define PORT_SET_PIN_DIRECTION_API                (STD_OFF)

/******************************************************************************
*                               Defines Check
******************************************************************************/

#if ((PORT_MODULE_ID != PORT_DRV_CFG_MODULE_ID_H))
    #error "PORT_MODULE_ID config error"
#endif

#if ((PORT_INSTANCE_ID != 0U))
    #error "PORT_INSTANCE_ID config error"
#endif

#if ((PORT_DEV_ERROR_DETECT != STD_ON) && (PORT_DEV_ERROR_DETECT != STD_OFF))
    #error "PORT_DEV_ERROR_DETECT config error"
#endif

#if ((PORT_VERSION_INFO_API != STD_ON) && (PORT_VERSION_INFO_API != STD_OFF))
    #error "PORT_VERSION_INFO_API config error"
#endif

#if ((PORT_SET_PIN_MODE_API != STD_ON) && (PORT_SET_PIN_MODE_API != STD_OFF))
    #error "PORT_SET_PIN_MODE_API config error"
#endif

#if ((PORT_SET_PIN_DIRECTION_API != STD_ON) && (PORT_SET_PIN_DIRECTION_API != STD_OFF))
    #error "PORT_SET_PIN_DIRECTION_API config error"
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

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PORT_DRV_CFG_H */
