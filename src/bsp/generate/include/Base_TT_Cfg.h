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
**  FILENAME     : Base_TT_Cfg.h                                              **
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
#ifndef BASE_TT_CFG_H
#define BASE_TT_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_NVIC.h"
#include "A8V2E_FPU.h"
#include "A8V2E_MPU.h"
#include "A8V2E_SCB.h"
#include "A8V2E_SCU.h"
#include "A8V2E_UART.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_TT_CFG_VENDOR_ID_H                     (1541U)
#define BASE_TT_CFG_MODULE_ID_H                     (218U)
#define BASE_TT_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define BASE_TT_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define BASE_TT_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define BASE_TT_CFG_SW_MAJOR_VERSION_H              (1U)
#define BASE_TT_CFG_SW_MINOR_VERSION_H              (1U)
#define BASE_TT_CFG_SW_PATCH_VERSION_H              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_TT_Cfg.h and A8V2E_NVIC.h file version check */
#if (BASE_TT_CFG_VENDOR_ID_H != A8V2E_NVIC_VENDOR_ID_H)
    #error "Base_TT_Cfg.h and A8V2E_NVIC.h have different vendor id"
#endif
#if ((BASE_TT_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_NVIC_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_NVIC_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_NVIC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_TT_Cfg.h and A8V2E_NVIC.h are different"
#endif
#if ((BASE_TT_CFG_SW_MAJOR_VERSION_H != A8V2E_NVIC_SW_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_SW_MINOR_VERSION_H != A8V2E_NVIC_SW_MINOR_VERSION_H) || \
     (BASE_TT_CFG_SW_PATCH_VERSION_H != A8V2E_NVIC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_TT_Cfg.h and A8V2E_NVIC.h are different"
#endif

/* Base_TT_Cfg.h and A8V2E_FPU.h file version check */
#if (BASE_TT_CFG_VENDOR_ID_H != A8V2E_FPU_VENDOR_ID_H)
    #error "Base_TT_Cfg.h and A8V2E_FPU.h have different vendor id"
#endif
#if ((BASE_TT_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_FPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_FPU_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_FPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_TT_Cfg.h and A8V2E_FPU.h are different"
#endif
#if ((BASE_TT_CFG_SW_MAJOR_VERSION_H != A8V2E_FPU_SW_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_SW_MINOR_VERSION_H != A8V2E_FPU_SW_MINOR_VERSION_H) || \
     (BASE_TT_CFG_SW_PATCH_VERSION_H != A8V2E_FPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_TT_Cfg.h and A8V2E_FPU.h are different"
#endif

/* Base_TT_Cfg.h and A8V2E_MPU.h file version check */
#if (BASE_TT_CFG_VENDOR_ID_H != A8V2E_MPU_VENDOR_ID_H)
    #error "Base_TT_Cfg.h and A8V2E_MPU.h have different vendor id"
#endif
#if ((BASE_TT_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_MPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_MPU_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_MPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_TT_Cfg.h and A8V2E_MPU.h are different"
#endif
#if ((BASE_TT_CFG_SW_MAJOR_VERSION_H != A8V2E_MPU_SW_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_SW_MINOR_VERSION_H != A8V2E_MPU_SW_MINOR_VERSION_H) || \
     (BASE_TT_CFG_SW_PATCH_VERSION_H != A8V2E_MPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_TT_Cfg.h and A8V2E_MPU.h are different"
#endif

/* Base_TT_Cfg.h and A8V2E_SCB.h file version check */
#if (BASE_TT_CFG_VENDOR_ID_H != A8V2E_SCB_VENDOR_ID_H)
    #error "Base_TT_Cfg.h and A8V2E_SCB.h have different vendor id"
#endif
#if ((BASE_TT_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_SCB_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_SCB_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_SCB_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_TT_Cfg.h and A8V2E_SCB.h are different"
#endif
#if ((BASE_TT_CFG_SW_MAJOR_VERSION_H != A8V2E_SCB_SW_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_SW_MINOR_VERSION_H != A8V2E_SCB_SW_MINOR_VERSION_H) || \
     (BASE_TT_CFG_SW_PATCH_VERSION_H != A8V2E_SCB_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_TT_Cfg.h and A8V2E_SCB.h are different"
#endif

/* Base_TT_Cfg.h and A8V2E_SCU.h file version check */
#if (BASE_TT_CFG_VENDOR_ID_H != A8V2E_SCU_VENDOR_ID_H)
    #error "Base_TT_Cfg.h and A8V2E_SCU.h have different vendor id"
#endif
#if ((BASE_TT_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_SCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_SCU_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_SCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_TT_Cfg.h and A8V2E_SCU.h are different"
#endif
#if ((BASE_TT_CFG_SW_MAJOR_VERSION_H != A8V2E_SCU_SW_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_SW_MINOR_VERSION_H != A8V2E_SCU_SW_MINOR_VERSION_H) || \
     (BASE_TT_CFG_SW_PATCH_VERSION_H != A8V2E_SCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_TT_Cfg.h and A8V2E_SCU.h are different"
#endif

/* Base_TT_Cfg.h and A8V2E_UART.h file version check */
#if (BASE_TT_CFG_VENDOR_ID_H != A8V2E_UART_VENDOR_ID_H)
    #error "Base_TT_Cfg.h and A8V2E_UART.h have different vendor id"
#endif
#if ((BASE_TT_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_UART_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_UART_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TT_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_UART_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_TT_Cfg.h and A8V2E_UART.h are different"
#endif
#if ((BASE_TT_CFG_SW_MAJOR_VERSION_H != A8V2E_UART_SW_MAJOR_VERSION_H) || \
     (BASE_TT_CFG_SW_MINOR_VERSION_H != A8V2E_UART_SW_MINOR_VERSION_H) || \
     (BASE_TT_CFG_SW_PATCH_VERSION_H != A8V2E_UART_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_TT_Cfg.h and A8V2E_UART.h are different"
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

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
 
#endif /* BASE_TT_CFG_H */
