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
**  FILENAME     : Uart_Hal_Types.h                                                 **
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
#ifndef UART_HAL_TYPES_H
#define UART_HAL_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                            Includes
 ******************************************************************************/
#include "Linu_Hw_Types.h"

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define UART_HAL_TYPES_VENDOR_ID_H                     1541
#define UART_HAL_TYPES_MODULE_ID_H                     227
#define UART_HAL_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define UART_HAL_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define UART_HAL_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define UART_HAL_TYPES_SW_MAJOR_VERSION_H              1
#define UART_HAL_TYPES_SW_MINOR_VERSION_H              1
#define UART_HAL_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Uart_Hal_Types.h and Linu_Hw_Types.h file version check */
#if (UART_HAL_TYPES_VENDOR_ID_H != LINU_HW_TYPES_VENDOR_ID_H)
    #error "Uart_Hal_Types.h and Linu_Hw_Types.h have different vendor ids"
#endif
#if (UART_HAL_TYPES_MODULE_ID_H != LINU_HW_TYPES_MODULE_ID_H)
    #error "Uart_Hal_Types.h and Linu_Hw_Types.h have different module ids"
#endif
#if ((UART_HAL_TYPES_AR_RELEASE_MAJOR_VERSION_H != LINU_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HAL_TYPES_AR_RELEASE_MINOR_VERSION_H != LINU_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HAL_TYPES_AR_RELEASE_PATCH_VERSION_H != LINU_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hal_Types.h and Linu_Hw_Types.h are different"
#endif
#if ((UART_HAL_TYPES_SW_MAJOR_VERSION_H != LINU_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (UART_HAL_TYPES_SW_MINOR_VERSION_H != LINU_HW_TYPES_SW_MINOR_VERSION_H) || \
     (UART_HAL_TYPES_SW_PATCH_VERSION_H != LINU_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hal_Types.h and Linu_Hw_Types.h are different"
#endif


#ifdef __cplusplus
}
#endif

#endif /* UART_H */
