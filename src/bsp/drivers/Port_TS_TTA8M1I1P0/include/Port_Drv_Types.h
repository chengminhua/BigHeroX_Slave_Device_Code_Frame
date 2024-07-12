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
**  FILENAME     : Port_Drv_Types.h                                           **
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
#ifndef PORT_DRV_TYPES_H
#define PORT_DRV_TYPES_H

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
#define PORT_DRV_TYPES_VENDOR_ID_H                     1541
#define PORT_DRV_TYPES_MODULE_ID_H                     124
#define PORT_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define PORT_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define PORT_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define PORT_DRV_TYPES_SW_MAJOR_VERSION_H              1
#define PORT_DRV_TYPES_SW_MINOR_VERSION_H              1
#define PORT_DRV_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Port_Drv_Types.h and Port_Hw_Types.h file version check */
#if (PORT_DRV_TYPES_VENDOR_ID_H != PORT_HW_TYPES_VENDOR_ID_H)
    #error "Port_Drv_Types.h and Port_Hw_Types.h have different vendor ids"
#endif
#if (PORT_DRV_TYPES_MODULE_ID_H != PORT_HW_TYPES_MODULE_ID_H)
    #error "Port_Drv_Types.h and Port_Hw_Types.h have different module ids"
#endif
#if ((PORT_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != PORT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != PORT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != PORT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Drv_Types.h and Port_Hw_Types.h are different"
#endif
#if ((PORT_DRV_TYPES_SW_MAJOR_VERSION_H != PORT_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (PORT_DRV_TYPES_SW_MINOR_VERSION_H != PORT_HW_TYPES_SW_MINOR_VERSION_H) || \
     (PORT_DRV_TYPES_SW_PATCH_VERSION_H != PORT_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Drv_Types.h and Port_Hw_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Service ID For Port Drv API */
#define PORT_DRV_SI_INIT                      (100U)
/* Service ID For Port Drv API */
#define PORT_DRV_SI_SETPINDIRECTION           (101U)
/* Service ID For Port Drv API */
#define PORT_DRV_SI_SETPINMODE                (102U)
/* Service ID For Port Drv API */
#define PORT_DRV_SI_SETPINALLCFG              (103U)

/*  Port Drv Mux */
#define PORTMUXNUM                            (1U)
/*  Port NUM */
#define PORTNUM                               (0U)
/* Error code combination */
#define PORT_DRV_TT_STATUS_DEFAULT(ApiID)       (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET)       | \
                                                        ((ApiID) << TT_APIID_OFFSET) | \
                                                        (PORT_MODULE_ID << TT_MODULEID_OFFSET))
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
#ifdef __cplusplus
}
#endif

#endif
