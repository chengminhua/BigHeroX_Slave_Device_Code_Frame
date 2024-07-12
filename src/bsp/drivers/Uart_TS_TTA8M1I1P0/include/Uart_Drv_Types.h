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
**  FILENAME     : Uart_Drv_Types.h                                                 **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : Uart Driver Source File                                          **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                     **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                               History                                             **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifndef UART_DRV_TYPES_H
#define UART_DRV_TYPES_H
/******************************************************************************
 *                            Includes
 ******************************************************************************/
#include "Uart_Hal_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define UART_DRV_TYPES_VENDOR_ID_H                     1541
#define UART_DRV_TYPES_MODULE_ID_H                     227
#define UART_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define UART_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define UART_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define UART_DRV_TYPES_SW_MAJOR_VERSION_H              1
#define UART_DRV_TYPES_SW_MINOR_VERSION_H              1
#define UART_DRV_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Uart_Drv_Types.h and Uart_Hal_Types.h file version check */
#if (UART_DRV_TYPES_VENDOR_ID_H != UART_HAL_TYPES_VENDOR_ID_H)
    #error "Uart_Drv_Types.h and Uart_Hal_Types.h have different vendor ids"
#endif
#if (UART_DRV_TYPES_MODULE_ID_H != UART_HAL_TYPES_MODULE_ID_H)
    #error "Uart_Drv_Types.h and Uart_Hal_Types.h have different module ids"
#endif
#if ((UART_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != UART_HAL_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != UART_HAL_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != UART_HAL_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Drv_Types.h and Uart_Hal_Types.h are different"
#endif
#if ((UART_DRV_TYPES_SW_MAJOR_VERSION_H != UART_HAL_TYPES_SW_MAJOR_VERSION_H) || \
     (UART_DRV_TYPES_SW_MINOR_VERSION_H != UART_HAL_TYPES_SW_MINOR_VERSION_H) || \
     (UART_DRV_TYPES_SW_PATCH_VERSION_H != UART_HAL_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Drv_Types.h and Uart_Hal_Types.h are different"
#endif

/******************************************************************************
 *                            Defines And Macros
 *******************************************************************************/
/* Service id for initialization of UART.*/
#define UART_SI_INIT                          100u
/* Service id for Deinitialization of UART */
#define UART_SI_DEINIT                        101u
/* Service id for UART Transmission */
#define UART_SI_SYNCTRANSMIT                  102u
/* Service id for UART Transmission */
#define UART_SI_ASYNCTRANSMIT                 103u
/* Service id for UART Reception */
#define UART_SI_SYNCRECEIVE                   104u
/* Service id for UART Reception */
#define UART_SI_ASYNCRECEIVE                  105u
/* Service id to get status of the UART */
#define UART_SI_GETSTATUS                     106u
/* Service id  to indicate type of error in module operation */
#define UART_SI_GETERRORSTATUS                107u
/* Service id to set the baud rate for UART. */
#define UART_SI_SET_BAUDARTE                  108u
/* Service Id for Uart_GetVersionInfo API */
#define UART_SI_GET_VERSIONINFO               109u
#ifdef __cplusplus
}
#endif

#endif
