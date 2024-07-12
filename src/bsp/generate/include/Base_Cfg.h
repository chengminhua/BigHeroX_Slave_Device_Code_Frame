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
**  FILENAME     : Base_Cfg.h                                                 **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Base Driver Configuration Generated File                   **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef BASE_CFG_H
#define BASE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_SYSTICK.h"
#include "A8V2E_OTP.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_CFG_VENDOR_ID_H                     (1541U)
#define BASE_CFG_MODULE_ID_H                     (218U)
#define BASE_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define BASE_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define BASE_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define BASE_CFG_SW_MAJOR_VERSION_H              (1U)
#define BASE_CFG_SW_MINOR_VERSION_H              (1U)
#define BASE_CFG_SW_PATCH_VERSION_H              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/* Base_Cfg.h and A8V2E_SYSTICK.h file version check */
#if (BASE_CFG_VENDOR_ID_H != A8V2E_SYSTICK_VENDOR_ID_H)
    #error "Base_Cfg.h and A8V2E_SYSTICK.h have different vendor id"
#endif
#if ((BASE_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_SYSTICK_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_SYSTICK_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_SYSTICK_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Cfg.h and A8V2E_SYSTICK.h are different"
#endif
#if ((BASE_CFG_SW_MAJOR_VERSION_H != A8V2E_SYSTICK_SW_MAJOR_VERSION_H) || \
     (BASE_CFG_SW_MINOR_VERSION_H != A8V2E_SYSTICK_SW_MINOR_VERSION_H) || \
     (BASE_CFG_SW_PATCH_VERSION_H != A8V2E_SYSTICK_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Cfg.h and A8V2E_SYSTICK.h are different"
#endif


/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
#define BASE_MODULE_ID                    (218U)

#define BASE_INSTANCE_ID                     (0U)

#define BASE_DEV_ERROR_DETECT             (STD_OFF)

#define BASE_SYSTEM_TIMER_IRQ             (STD_OFF)

#define BASE_SYSTICK_EXTCLK               (STD_OFF)

#if defined(BASE_SYSTEM_TIMER_IRQ) && (BASE_SYSTEM_TIMER_IRQ == STD_ON)
extern void (Base_CallBack)(void);
#endif
/******************************************************************************
*                               Defines Check
******************************************************************************/

#if (BASE_MODULE_ID != (218U))
    #error "BASE_MODULE_ID config error"
#endif

#if ((BASE_INSTANCE_ID < 0) && (BASE_INSTANCE_ID >  255) )
    #error "BASE_INSTANCE_ID config error"
#endif


#if ((BASE_DEV_ERROR_DETECT != STD_ON) && (BASE_DEV_ERROR_DETECT != STD_OFF))
	#error "BASE_DEV_ERROR_DETECT config error"
#endif

#if ((BASE_SYSTEM_TIMER_IRQ != STD_ON) && (BASE_SYSTEM_TIMER_IRQ != STD_OFF))
	#error "BASE_SYSTEM_TIMER_IRQ config error"
#endif

#if ((BASE_SYSTICK_EXTCLK != STD_ON) && (BASE_SYSTICK_EXTCLK != STD_OFF))
	#error "BASE_SYSTICK_EXTCLK config error"
#endif


/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/

/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */  
 
#endif /* BASE_CFG_H */
