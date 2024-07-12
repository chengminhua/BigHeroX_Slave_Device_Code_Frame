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
**  FILENAME     : Gtm_Drv_Tom_Cfg.h                                          **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef GTM_DRV_TOM_CFG_H
#define GTM_DRV_TOM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_GTM.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_DRV_TOM_CFG_VENDOR_ID_H       1541
#define GTM_DRV_TOM_CFG_MODULE_ID_H       221

#define GTM_DRV_TOM_CFG_AR_RELEASE_MAJOR_VERSION_H     4
#define GTM_DRV_TOM_CFG_AR_RELEASE_MINOR_VERSION_H     4
#define GTM_DRV_TOM_CFG_AR_RELEASE_PATCH_VERSION_H     0

#define GTM_DRV_TOM_CFG_SW_MAJOR_VERSION_H    1
#define GTM_DRV_TOM_CFG_SW_MINOR_VERSION_H    1
#define GTM_DRV_TOM_CFG_SW_PATCH_VERSION_H    0
#define GTM_DRV_TOM_INSTANCE_ID_H             (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and A8V2E_GTM.h header file are of the same vendor */
#if (GTM_DRV_TOM_CFG_VENDOR_ID_H != A8V2E_GTM_VENDOR_ID_H)
#error "Gtm_Drv_Tom_Cfg.h and A8V2E_GTM.h have different vendor ids"
#endif
/* Check if current file and A8V2E_GTM.h header file are of the same Autosar version */
#if ((GTM_DRV_TOM_CFG_AR_RELEASE_MAJOR_VERSION_H   != A8V2E_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
    (GTM_DRV_TOM_CFG_AR_RELEASE_MINOR_VERSION_H    != A8V2E_GTM_AR_RELEASE_MINOR_VERSION_H) || \
    (GTM_DRV_TOM_CFG_AR_RELEASE_PATCH_VERSION_H    != A8V2E_GTM_AR_RELEASE_REVISION_VERSION_H))
#error "AutoSar Version Numbers of Gtm_Drv_Tom_Cfg.h and A8V2E_GTM.h are different"
#endif
/* Check if current file and A8V2E_GTM.h header file are of the same Software version */
#if ((GTM_DRV_TOM_CFG_SW_MAJOR_VERSION_H != A8V2E_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_TOM_CFG_SW_MINOR_VERSION_H != A8V2E_GTM_SW_MINOR_VERSION_H) || \
     (GTM_DRV_TOM_CFG_SW_PATCH_VERSION_H != A8V2E_GTM_SW_PATCH_VERSION_H))
#error "Software Version Numbers of Gtm_Drv_Tom_Cfg.h and A8V2E_GTM.h are different"
#endif


/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define GTM_TOM_DEV_ERROR_DETECT (STD_OFF)
#if ((GTM_TOM_DEV_ERROR_DETECT != STD_ON) && (GTM_TOM_DEV_ERROR_DETECT != STD_OFF))
    #error "GTM_TOM_DEV_ERROR_DETECT error"
#endif


#define TOM_MAX              (2U)
#define TOM_TCG_MAX          (4U)
#define TOM_INSTANCE         (2U)

#define TOM_0_CHANNEL_0            (0U)
#define TOM_0_CHANNEL_1            (1U)

/******************************************************************************
*                            Defines Check
*******************************************************************************/
#ifndef TOM_MAX
    #error "TOM_MAX not define error"
#endif
#if (TOM_MAX > 32)
    #error "TOM_MAX config error"
#endif
#ifndef TOM_TCG_MAX
    #error "TOM_TCG_MAX not define error"
#endif
#if (TOM_TCG_MAX > 4)
    #error "TOM_TCG_MAX config error"
#endif
#ifndef TOM_INSTANCE
    #error "TOM_INSTANCE not define error"
#endif
#if (TOM_INSTANCE > 2)
    #error "TOM_INSTANCE config error"
#endif

#ifndef TOM_0_CHANNEL_0
    #error "TOM_0_CHANNEL_0 not define error"
#endif
#if (TOM_0_CHANNEL_0 > 32)
    #error "TOM_0_CHANNEL_0 config error"
#endif
#ifndef TOM_0_CHANNEL_1
    #error "TOM_0_CHANNEL_1 not define error"
#endif
#if (TOM_0_CHANNEL_1 > 32)
    #error "TOM_0_CHANNEL_1 config error"
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
#endif

#endif /* GTM_TOM_CFG_H */

/** @} */


