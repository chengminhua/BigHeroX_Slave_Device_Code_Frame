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
**  FILENAME     : Platform_Mpu_Cfg.h                                         **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Configuration Generated File               **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef PLATFORM_MPU_CFG_H_
#define PLATFORM_MPU_CFG_H_

/**
*   @file Mpu_M7_Ip_Cfg.h
*
*   @addtogroup Mpu_M7_Ip Mpu M7 IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_SCB.h"
#include "A8V2E_MPU.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_MPU_CFG_VENDOR_ID_H                     (1541U)
#define PLATFORM_MPU_CFG_MODULE_ID_H                     (219U)
#define PLATFORM_MPU_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define PLATFORM_MPU_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define PLATFORM_MPU_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define PLATFORM_MPU_CFG_SW_MAJOR_VERSION_H              (1U)
#define PLATFORM_MPU_CFG_SW_MINOR_VERSION_H              (1U)
#define PLATFORM_MPU_CFG_SW_PATCH_VERSION_H              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Mpu_Cfg.h and A8V2E_SCB.h file version check */
#if (PLATFORM_MPU_CFG_VENDOR_ID_H != A8V2E_SCB_VENDOR_ID_H)
   #error "Platform_Mpu_Cfg.h and A8V2E_SCB.h have different vendor id"
#endif
#if ((PLATFORM_MPU_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_SCB_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_MPU_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_SCB_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_MPU_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_SCB_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Mpu_Cfg.h and A8V2E_SCB.h are different"
#endif
#if ((PLATFORM_MPU_CFG_SW_MAJOR_VERSION_H != A8V2E_SCB_SW_MAJOR_VERSION_H) || \
     (PLATFORM_MPU_CFG_SW_MINOR_VERSION_H != A8V2E_SCB_SW_MINOR_VERSION_H) || \
     (PLATFORM_MPU_CFG_SW_PATCH_VERSION_H != A8V2E_SCB_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Mpu_Cfg.h and A8V2E_SCB.h are different"
#endif

/* Platform_Mpu_Cfg.h and A8V2E_MPU.h file version check */
#if (PLATFORM_MPU_CFG_VENDOR_ID_H != A8V2E_MPU_VENDOR_ID_H)
    #error "Platform_Mpu_Cfg.h and A8V2E_SCB.h have different vendor id"
#endif
#if ((PLATFORM_MPU_CFG_AR_RELEASE_MAJOR_VERSION_H != A8V2E_MPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_MPU_CFG_AR_RELEASE_MINOR_VERSION_H != A8V2E_MPU_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_MPU_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_MPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Mpu_Cfg.h and A8V2E_MPU.h are different"
#endif
#if ((PLATFORM_MPU_CFG_SW_MAJOR_VERSION_H != A8V2E_MPU_SW_MAJOR_VERSION_H) || \
     (PLATFORM_MPU_CFG_SW_MINOR_VERSION_H != A8V2E_MPU_SW_MINOR_VERSION_H) || \
     (PLATFORM_MPU_CFG_SW_PATCH_VERSION_H != A8V2E_MPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Mpu_Cfg.h and A8V2E_MPU.h are different"
#endif


/******************************************************************************
*                            Defines And Macros
*******************************************************************************/ 
#define MPU_M7_IP_MIN_REGION_SIZE                             (32U)
#define MPU_M7_IP_EXECUTE_RIGHT_MASK                          (16U)
#define MPU_SCB_CFSR_MMFSR_MASK_VALID                         (59U)

/* MPU Enable */
#define PLATFORM_ENABLE_MPU                                   (STD_OFF)

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

/******************************************************************************
*                       Defines Checks
******************************************************************************/
#ifndef MPU_M7_IP_MIN_REGION_SIZE
    #error "MPU_M7_IP_MIN_REGION_SIZE Defines error"
#if (MPU_M7_IP_MIN_REGION_SIZE != (32U))
    #error "MPU_M7_IP_MIN_REGION_SIZE Defines error"
#endif
#endif

#ifndef MPU_M7_IP_EXECUTE_RIGHT_MASK
    #error "MPU_M7_IP_EXECUTE_RIGHT_MASK Defines error"
#if (MPU_M7_IP_EXECUTE_RIGHT_MASK != (16U))
    #error "MPU_M7_IP_EXECUTE_RIGHT_MASK Defines error"
#endif
#endif

#ifndef MPU_SCB_CFSR_MMFSR_MASK_VALID
    #error "MPU_SCB_CFSR_MMFSR_MASK_VALID Defines error"
#if (MPU_SCB_CFSR_MMFSR_MASK_VALID != (59U))
    #error "MPU_SCB_CFSR_MMFSR_MASK_VALID Defines error"
#endif
#endif

#ifndef PLATFORM_ENABLE_MPU
    #error "PLATFORM_ENABLE_MPU Defines error"
#if ((PLATFORM_ENABLE_MPU != STD_OFF) && (PLATFORM_ENABLE_MPU != STD_ON))
    #error "PLATFORM_ENABLE_MPU Defines error"
#endif
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#endif /* PLATFORM_MPU_CFG_H_ */
