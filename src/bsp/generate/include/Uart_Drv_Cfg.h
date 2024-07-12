/*************************************************************************************
**                                                                                  **
** Copyright (c) ThinkTech Technologies (2023)                                      **
**                                                                                  **
** All rights reserved.                                                             **
**                                                                                  **
** This document contains proprietary information beloging to ThinkTech             **
** Technologies. Passing on and copying of this document, and communication         **
** of its contents is not permitted without prior written authorization.            **
**                                                                                  **
**************************************************************************************
**                                                                                  **
**  FILENAME     : Uart_Drv_Cfg.h                                                   **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : Uart Driver Configuration Generated File                         **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                    **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                                 History                                             **
*[V1.1.0]:                                                                            **
*************************************************************************************/
#ifndef UART_DRV_CFG_H
#define UART_DRV_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_UART.h"
#include "A8V2E_LIN.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define UART_DRV_CFG_VENDOR_ID_H                     (1541U)
#define UART_DRV_CFG_MODULE_ID_H                     (227U)
#define UART_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define UART_DRV_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define UART_DRV_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define UART_DRV_CFG_SW_MAJOR_VERSION_H              (1U)
#define UART_DRV_CFG_SW_MINOR_VERSION_H              (1U)
#define UART_DRV_CFG_SW_PATCH_VERSION_H              (0U)

#define UART_INSTANCE_ID                             (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Uart_Drv_Cfg.h and A8V2E_Uart.h file version check */
#if (UART_DRV_CFG_VENDOR_ID_H != A8V2E_UART_VENDOR_ID_H)
    #error "Uart_Drv_Cfg.h and A8V2E_Uart.h have different vendor ids"
#endif
#if ((UART_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_UART_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_DRV_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_UART_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_UART_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Drv_Cfg.h and A8V2E_Uart.h are different"
#endif
#if ((UART_DRV_CFG_SW_MAJOR_VERSION_H != A8V2E_UART_SW_MAJOR_VERSION_H) || \
     (UART_DRV_CFG_SW_MINOR_VERSION_H != A8V2E_UART_SW_MINOR_VERSION_H) || \
     (UART_DRV_CFG_SW_PATCH_VERSION_H != A8V2E_UART_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Drv_Cfg.h and A8V2E_Uart.h are different"
#endif

/* Uart_Drv_Cfg.h and A8V2E_Lin.h file version check */
#if (UART_DRV_CFG_VENDOR_ID_H != A8V2E_LIN_VENDOR_ID_H)
    #error "Uart_Drv_Cfg.h and  A8V2E_Lin.h have different vendor ids"
#endif
#if ((UART_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_LIN_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_DRV_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_LIN_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_LIN_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Drv_Cfg.h and  A8V2E_Lin.h are different"
#endif
#if ((UART_DRV_CFG_SW_MAJOR_VERSION_H != A8V2E_LIN_SW_MAJOR_VERSION_H) || \
     (UART_DRV_CFG_SW_MINOR_VERSION_H != A8V2E_LIN_SW_MINOR_VERSION_H) || \
     (UART_DRV_CFG_SW_PATCH_VERSION_H != A8V2E_LIN_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Drv_Cfg.h and  A8V2E_Lin.h are different"
#endif


/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define UART_PRECOMPILE_SUPPORT

#define UART_VERSION_INFO_API                 (STD_OFF)

#define UART_DEV_ERROR_DETECT                 (STD_OFF)

/* This this will set the timer source for osif that will be used for timeout */
#define UART_TIMEOUT_SUPERVISION_ENABLE         (STD_OFF)

/**
* @brief Channels that are actually used
*/
#define ALL_CONTROLLER_COUNT                  (2U)

/**
* @brief The amount of Uart and Lin used by the chip
*/
#define UART_CONTROLLER_COUNT                 (4U)
#define LIN_CONTROLLER_COUNT                  (16U)


/**
* @brief Uart and Lin are actually used
*/
#define UART_CONFIGED_COUNT                   (2U)
#define LIN_CONFIGED_COUNT                    (0U)
#define UART1_CONFIGED
#define UART1_IRQ_ENABLE

#define UART0_CONFIGED
#define UART0_DMA_ENABLE

#define UART_DMA_ENABLE                       (STD_ON)

#define LIN_UART_ENABLE                       (STD_OFF)
#define LIN_DMA_ENABLE                       (STD_OFF)

#define LIN_IRQ_ENABLE                       (STD_OFF)
#define LIN_UART_OVERSAMPLERATE               (STD_OFF)

/******************************************************************************
*                            Defines checks
*******************************************************************************/
#ifndef UART_VERSION_INFO_API
    #error"UART_VERSION_INFO_API error"
#else
#if ((UART_VERSION_INFO_API != STD_ON) && (UART_VERSION_INFO_API != STD_OFF))
    #error"UART_VERSION_INFO_API error"
#endif
#endif

#ifndef UART_DEV_ERROR_DETECT
    #error"UART_DEV_ERROR_DETECT error"
#else
#if ((UART_DEV_ERROR_DETECT != STD_ON) && (UART_DEV_ERROR_DETECT != STD_OFF))
    #error"UART_DEV_ERROR_DETECT error"
#endif
#endif


#ifndef UART_TIMEOUT_SUPERVISION_ENABLE
    #error"UART_TIMEOUT_SUPERVISION_ENABLE error"
#else
#if ((UART_TIMEOUT_SUPERVISION_ENABLE != STD_ON) && (UART_TIMEOUT_SUPERVISION_ENABLE != STD_OFF))
    #error"UART_TIMEOUT_SUPERVISION_ENABLE error"
#endif
#endif

#if (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
#if (UART_TIMEOUT_DURATION <= 0)
	#error"UART_TIMEOUT_DURATION error"
#endif
#endif

#ifndef UART_CONTROLLER_COUNT
    #error"UART_CONTROLLER_COUNT error"
#else
#if (UART_CONTROLLER_COUNT  != 4)
    #error"UART_CONTROLLER_COUNT error"
#endif
#endif


#ifndef LIN_CONTROLLER_COUNT
    #error"LIN_CONTROLLER_COUNT error"
#else
#if (LIN_CONTROLLER_COUNT != 16)
    #error"LIN_CONTROLLER_COUNT error"
#endif
#endif

#ifndef ALL_CONTROLLER_COUNT
    #error"ALL_CONTROLLER_COUNT error"
#else
#if ((ALL_CONTROLLER_COUNT  < 1) || (ALL_CONTROLLER_COUNT > UART_CONTROLLER_COUNT + LIN_CONTROLLER_COUNT))
    #error"ALL_CONTROLLER_COUNT error"
#endif
#endif

#ifndef UART_CONFIGED_COUNT
    #error"UART_CONFIGED_COUNT error"
#else
#if ((UART_CONFIGED_COUNT < 0) || (UART_CONFIGED_COUNT > 4))
    #error"UART_CONFIGED_COUNT error"
#endif
#endif

#ifndef LIN_CONFIGED_COUNT
    #error"LIN_CONFIGED_COUNT error"
#else
#if ((LIN_CONFIGED_COUNT < 0) || (LIN_CONFIGED_COUNT > 16))
    #error"LIN_CONFIGED_COUNT error"
#endif
#endif


#ifndef UART_DMA_ENABLE
    #error"UART_DMA_ENABLE error"
#else
#if ((UART_DMA_ENABLE != STD_ON) && (UART_DMA_ENABLE != STD_OFF))
    #error"UART_DMA_ENABLE error"
#endif
#endif

#ifndef LIN_IRQ_ENABLE
    #error"LIN_IRQ_ENABLE error"
#else
#if ((LIN_IRQ_ENABLE != STD_ON) && (LIN_IRQ_ENABLE != STD_OFF))
    #error"LIN_IRQ_ENABLE error"
#endif
#endif

#ifndef LIN_UART_OVERSAMPLERATE
    #error"LIN_UART_OVERSAMPLERATE error"
#else
#if ((LIN_UART_OVERSAMPLERATE != STD_ON) && (LIN_UART_OVERSAMPLERATE != STD_OFF))
    #error"LIN_UART_OVERSAMPLERATE error"
#endif
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#endif /* UART_DRV_CFG_H */
