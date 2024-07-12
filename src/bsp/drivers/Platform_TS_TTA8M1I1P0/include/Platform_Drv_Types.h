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
**  FILENAME     : Platform_Drv_Types.h                                       **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Source File                                **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef PLATFORM_DRV_TYPESDEF_H
#define PLATFORM_DRV_TYPESDEF_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Hw_IntCtrl_Types.h"
#include "Platform_Hw_Mpu_Types.h"
#include "Platform_Drv_Cfg.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_DRV_TYPES_VENDOR_ID_H                     1541
#define PLATFORM_DRV_TYPES_MODULE_ID_H                     219
#define PLATFORM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define PLATFORM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define PLATFORM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define PLATFORM_DRV_TYPES_SW_MAJOR_VERSION_H              1
#define PLATFORM_DRV_TYPES_SW_MINOR_VERSION_H              1
#define PLATFORM_DRV_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Drv_Types.h and Platform_Hw_IntCtrl_Types.h file version check */
#if (PLATFORM_DRV_TYPES_VENDOR_ID_H != PLATFORM_HW_INTCTRL_TYPES_VENDOR_ID_H)
    #error "Platform_Drv_Types.h and Platform_Hw_IntCtrl_Types.h have different vendor id"
#endif
#if (PLATFORM_DRV_TYPES_MODULE_ID_H != PLATFORM_HW_INTCTRL_TYPES_MODULE_ID_H)
    #error "Platform_Drv_Types.h and Platform_Hw_IntCtrl_Types.h have different module id"
#endif
#if ((PLATFORM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv_Types.h and Platform_Hw_IntCtrl_Types.h are different"
#endif
#if ((PLATFORM_DRV_TYPES_SW_MAJOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_SW_MINOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_SW_PATCH_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv_Types.h and Platform_Hw_IntCtrl_Types.h are different"
#endif

/* Platform_Drv_Types.h and Platform_Hw_Mpu_Types.h file version check */
#if (PLATFORM_DRV_TYPES_VENDOR_ID_H != PLATFORM_HW_MPU_TYPES_VENDOR_ID_H)
    #error "Platform_Drv_Types.h and Platform_Hw_Mpu_Types.h have different vendor id"
#endif
#if (PLATFORM_DRV_TYPES_MODULE_ID_H != PLATFORM_HW_MPU_TYPES_MODULE_ID_H)
    #error "Platform_Drv_Types.h and Platform_Hw_Mpu_Types.h have different module id"
#endif
#if ((PLATFORM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv_Types.h and Platform_Hw_Mpu_Types.h are different"
#endif
#if ((PLATFORM_DRV_TYPES_SW_MAJOR_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_SW_MINOR_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_SW_PATCH_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv_Types.h and Platform_Hw_Mpu_Types.h are different"
#endif

/* Platform_Drv_Types.h and Platform_Drv_Cfg.h file version check */
#if (PLATFORM_DRV_TYPES_VENDOR_ID_H != PLATFORM_DRV_CFG_VENDOR_ID_H)
    #error "Platform_Drv_Types.h and Platform_Drv_Cfg.h have different vendor id"
#endif
#if (PLATFORM_DRV_TYPES_MODULE_ID_H != PLATFORM_DRV_CFG_MODULE_ID_H)
    #error "Platform_Drv_Types.h and Platform_Drv_Cfg.h have different module id"
#endif
#if ((PLATFORM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv_Types.h and Platform_Drv_Cfg.h are different"
#endif
#if ((PLATFORM_DRV_TYPES_SW_MAJOR_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_SW_MINOR_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_TYPES_SW_PATCH_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv_Types.h and Platform_Drv_Cfg.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/**
* @brief            Service ID of Platform_Drv_Init function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INIT                                 ((uint8)100U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_Init function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_INIT                         ((uint8)101U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_SetPriority function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_SET_PRIORITY                 ((uint8)102U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_GetPriority function
* @details          Parameter used when raising an error/exception  
*/
#define PLATFORM_DRV_SI_INTCTRL_GET_PRIORITY                 ((uint8)103U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_SetPriorityGrouping function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_SET_PRIORITY_GROUPING        ((uint8)104U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_GetPriorityGrouping function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_GET_PRIORITY_GROUPING        ((uint8)105U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_EnableIRQ function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_ENABLE_IRQ                   ((uint8)106U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_GetEnableIRQ function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_GET_ENABLE_IRQ               ((uint8)107U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_DisableIRQ function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_DISABLE_IRQ                  ((uint8)108U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_GetPendingIRQ function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_GET_PENDING_IRQ              ((uint8)109U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_SetPendingIRQ function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_SET_PENDING_IRQ              ((uint8)110U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_ClearPendingIRQ function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_CLEAR_PENDING_IRQ            ((uint8)111U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_GetActive function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_GET_ACTIVE                   ((uint8)112U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_EncodePriority function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_ENCODE_PRIORITY              ((uint8)113U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_DecodePriority function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_DECODE_PRIORITY              ((uint8)114U)

/**
* @brief            Service ID of Platform_Drv_Misc_GetFPUType function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MISC_GET_FPU_TYPE                    ((uint8)115U)

/**
* @brief            Service ID of Platform_Drv_Misc_SystemReset function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MISC_SYSTEM_RESET                    ((uint8)116U)

/**
* @brief            Service ID of Platform_Drv_Misc_SetVector function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MISC_SET_VECTOR                      ((uint8)117U)

/**
* @brief            Service ID of Platform_Drv_Misc_GetHandle function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MISC_GET_VECTOR                      ((uint8)118U)

/**
* @brief            Service ID of Platform_Drv_Cache_EnableICache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CACHE_ENABLE_ICACHE                  ((uint8)119U)

/**
* @brief            Service ID of Platform_Drv_Cache_DisableICache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CACHE_DISABLE_ICACHE                 ((uint8)120U)

/**
* @brief            Service ID of Platform_Drv_Cache_InvalidateICache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CACHE_INVALIDATE_ICACHE              ((uint8)121U)

/**
* @brief            Service ID of Platform_Drv_Cache_EnableDCache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CACHE_ENABLE_DCACHE                  ((uint8)122U)

/**
* @brief            Service ID of Platform_Drv_Cache_DisableDCache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CACHE_DISABLE_DCACHE                 ((uint8)123U)

/**
* @brief            Service ID of Platform_Drv_Cache_InvalidateDCache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CACHE_INVALIDATE_DCACHE              ((uint8)124U)

/**
* @brief            Service ID of Platform_Drv_Cache_CleanDCache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CACHE_CLEAN_DCACHE                   ((uint8)125U)

/**
* @brief            Service ID of Platform_Drv_Cache_CleanInvalidateDCache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CACHE_CLEAN_INVALIDATE_DCACHE        ((uint8)126U)

/**
* @brief            Service ID of Platform_Drv_Cache_AddrInvalidateDCache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INVALIDATE_DCACHE_BY_ADDR            ((uint8)127U)

/**
* @brief            Service ID of Platform_Drv_Cache_CleanDCache_by_Addr function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CLEAN_DCACHE_BY_ADDR                 ((uint8)128U)

/**
* @brief            Service ID of Platform_Drv_Cache_CleanInvalidateDCache_by_Addr function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_CLEAN_INVALIDATE_DCACHE_BY_ADDR      ((uint8)129U)

/**
* @brief            Service ID of Platform_Drv_Mpu_Init function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_INIT                             ((uint8)130U)

/**
* @brief            Service ID of Platform_Drv_Mpu_SetRegionConfig function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_SET_REGION_CONFIG                ((uint8)131U)

/**
* @brief            Service ID of Platform_Drv_Mpu_Deinit function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_DEINIT                           ((uint8)132U)

/**
* @brief            Service ID of Platform_Drv_Mpu_EnableRegion function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_ENABLE_REGION                    ((uint8)133U)

/**
* @brief            Service ID of Platform_Drv_Mpu_SetAccessRight function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_SET_ACCESS_RIGHT                 ((uint8)134U)

/**
* @brief            Service ID of Platform_Drv_Mpu_GetErrorDetails function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_GET_ERROR_DETAILS                ((uint8)135U)

/**
* @brief            Service ID of Platform_Drv_Mpu_Enable function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_ENABLE                           ((uint8)136U)

/**
* @brief            Service ID of Platform_Drv_Mpu_Disable function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_DISABLE                          ((uint8)137U)

/**
* @brief            Service ID of Platform_Drv_Mpu_ClrRegion function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_CLR_REGION                       ((uint8)138U)

/**
* @brief            Service ID of Platform_Drv_Mpu_SetRegion function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_SET_REGION                       ((uint8)139U)

/**
* @brief            Service ID of Platform_Drv_Mpu_SetRegionEx function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_SET_REGION_EX                    ((uint8)140U)

/**
* @brief            Service ID of Platform_Drv_Mpu_Load function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_LOAD                             ((uint8)141U)

/**
* @brief            Service ID of Platform_Drv_Mpu_ConfigRegion function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_MPU_CONFIG_REGION                    ((uint8)142U)

/**
* @brief            Service ID of Platform_Drv_IntCtrl_SoftTrig function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INTCTRL_SET_SOFTTRIG                 ((uint8)143U)

/**
* @brief            Service ID of Platform_Drv_Cache_AddrInvalidateICache function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_INVALIDATE_ICACHE_BY_ADDR            ((uint8)144U)

/**
* @brief            Service ID of Platform_Drv_GetVersionInfo function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_DRV_SI_GETVERSIONINFO                       ((uint8)145U)

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/**
* @brief          Configuration structure for PLATFORM CDD.
* @implements     Platform_ConfigType_struct
*/
typedef struct
{
    TT_CONST Platform_Hw_IntCtrlConfigType  *IntCtrlConfig;    /* interrupt config */
    TT_CONST Platform_Hw_MpuConfigType      *MpuConfig;        /* Mpu config */
    TT_CONST uint32 Crc;
}Platform_Drv_ConfigType;
/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 

/* Platform config Data*/
extern TT_CONST Platform_Drv_ConfigType Platform_ConfigData;

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_DRV_TYPESDEF_H */
