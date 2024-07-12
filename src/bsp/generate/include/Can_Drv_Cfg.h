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
**  FILENAME     : Can_Drv_Cfg.h                                              **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Can Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/

#ifndef CAN_DRV_CFG_H
#define CAN_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/

#include "Can_Drv_PBcfg.h"

#include "Can_Hw_Cfg.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_DRV_CFG_VENDOR_ID_H                    1541
#define CAN_DRV_CFG_MODULE_ID_H                    80
#define CAN_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_DRV_CFG_AR_RELEASE_MINOR_VERSION_H     4
#define CAN_DRV_CFG_AR_RELEASE_PATCH_VERSION_H     0
#define CAN_DRV_CFG_SW_MAJOR_VERSION_H             1
#define CAN_DRV_CFG_SW_MINOR_VERSION_H             1
#define CAN_DRV_CFG_SW_PATCH_VERSION_H             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/* Checks against CAN_Hw_Cfg.h */
#if (CAN_DRV_CFG_VENDOR_ID_H != FLEXCAN_HW_CFG_VENDOR_ID_H)
    #error "Can_Drv_Cfg.h and CAN_Hw_Cfg.h have different vendor ids"
#endif
#if (CAN_DRV_CFG_MODULE_ID_H != FLEXCAN_HW_CFG_MODULE_ID_H)
    #error "Can_Drv_Cfg.h and CAN_Hw_Cfg.h have different module ids"
#endif
#if ((CAN_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_HW_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_DRV_CFG_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_HW_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != FLEXCAN_HW_CFG_AR_RELEASE_PATCH_VERSION_H) \
     )
     #error "AUTOSAR Version Numbers of Can_Drv_Cfg.h and CAN_Hw_Cfg.h are different"
#endif
#if ((CAN_DRV_CFG_SW_MAJOR_VERSION_H != FLEXCAN_HW_CFG_SW_MAJOR_VERSION_H) || \
     (CAN_DRV_CFG_SW_MINOR_VERSION_H != FLEXCAN_HW_CFG_SW_MINOR_VERSION_H) || \
     (CAN_DRV_CFG_SW_PATCH_VERSION_H != FLEXCAN_HW_CFG_SW_PATCH_VERSION_H) \
     )
    #error "Software Version Numbers of Can_Drv_Cfg.h and CAN_Hw_Cfg.h are different"
#endif

/* Checks against Can_Drv_PBcfg.h */
#if (CAN_DRV_CFG_VENDOR_ID != CAN_VENDOR_ID_DRV_PBCFG_H)
    #error "Can_Drv_Cfg.h and Can_Drv_PBcfg.h have different vendor ids"
#endif
#if ((CAN_DRV_CFG_AR_RELEASE_MAJOR_VERSION    != CAN_AR_RELEASE_MAJOR_VERSION_DRV_PBCFG_H) || \
     (CAN_DRV_CFG_AR_RELEASE_MINOR_VERSION    != CAN_AR_RELEASE_MINOR_VERSION_DRV_PBCFG_H) || \
     (CAN_DRV_CFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION_DRV_PBCFG_H) \
    )
    #error "AUTOSAR Version Numbers of Can_Drv_Cfg.h and Can_Drv_PBcfg.h are different"
#endif
#if ((CAN_DRV_CFG_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION_DRV_PBCFG_H) || \
     (CAN_DRV_CFG_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION_DRV_PBCFG_H) || \
     (CAN_DRV_CFG_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION_DRV_PBCFG_H) \
    )
    #error "Software Version Numbers of Can_Drv_Cfg.h and Can_Drv_PBcfg.h are different"
#endif


/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define CAN_USE_FLEXCAN_HW                     STD_ON
#define CAN_MB_INTERRUPT_SUPPORT               FLEXCAN_HW_MB_INTERRUPT_SUPPORT
#define CAN_ERROR_INTERRUPT_SUPPORT            FLEXCAN_HW_ERROR_INTERRUPT_SUPPORT
#define CAN_BUSOFF_INTERRUPT_SUPPORT           FLEXCAN_HW_BUSOFF_INTERRUPT_SUPPORT
#define CAN_FEATURE_HAS_DMA_ENABLE             FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE
#define CAN_FEATURE_HAS_PRETENDED_NETWORKING   FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING
#define CAN_FEATURE_HAS_ENHANCED_RX_FIFO       FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO
#define CAN_MB_ENHANCED_RXFIFO                 FLEXCAN_HW_MB_ENHANCED_RXFIFO
#define CAN_FEATURE_HAS_FD                     FLEXCAN_HW_FEATURE_HAS_FD
#define CAN_DRV_EXT \
CAN_DRV_CONFIG_PB
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
*                            Defines Checks
******************************************************************************/
#ifndef CAN_USE_FLEXCAN_HW
    #error "CAN_USE_FLEXCAN_HW error"
#else
#if((CAN_USE_FLEXCAN_HW != STD_ON) && (CAN_USE_FLEXCAN_HW != STD_OFF))
    #error "CAN_USE_FLEXCAN_HW error"
#endif
#endif

#ifndef CAN_MB_INTERRUPT_SUPPORT
    #error "CAN_MB_INTERRUPT_SUPPORT error"
#else
#if(CAN_MB_INTERRUPT_SUPPORT != FLEXCAN_HW_MB_INTERRUPT_SUPPORT)
    #error "CAN_MB_INTERRUPT_SUPPORT error"
#endif
#endif

#ifndef CAN_ERROR_INTERRUPT_SUPPORT
    #error "CAN_ERROR_INTERRUPT_SUPPORT error"
#else
#if(CAN_ERROR_INTERRUPT_SUPPORT != FLEXCAN_HW_ERROR_INTERRUPT_SUPPORT)
    #error "CAN_ERROR_INTERRUPT_SUPPORT error"
#endif
#endif

#ifndef CAN_BUSOFF_INTERRUPT_SUPPORT
    #error "CAN_BUSOFF_INTERRUPT_SUPPORT error"
#else
#if(CAN_BUSOFF_INTERRUPT_SUPPORT != FLEXCAN_HW_BUSOFF_INTERRUPT_SUPPORT)
    #error "CAN_BUSOFF_INTERRUPT_SUPPORT error"
#endif
#endif

#ifndef CAN_FEATURE_HAS_DMA_ENABLE
    #error "CAN_FEATURE_HAS_DMA_ENABLE error"
#else
#if(CAN_FEATURE_HAS_DMA_ENABLE != FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE)
    #error "CAN_FEATURE_HAS_DMA_ENABLE error"
#endif
#endif

#ifndef CAN_FEATURE_HAS_PRETENDED_NETWORKING
    #error "CAN_FEATURE_HAS_PRETENDED_NETWORKING error"
#else
#if(CAN_FEATURE_HAS_PRETENDED_NETWORKING != FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING)
    #error "CAN_FEATURE_HAS_PRETENDED_NETWORKING error"
#endif
#endif

#ifndef CAN_FEATURE_HAS_ENHANCED_RX_FIFO
    #error "CAN_FEATURE_HAS_ENHANCED_RX_FIFO error"
#else
#if(CAN_FEATURE_HAS_ENHANCED_RX_FIFO != FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO)
    #error "CAN_FEATURE_HAS_ENHANCED_RX_FIFO error"
#endif
#endif

#ifndef CAN_MB_ENHANCED_RXFIFO
    #error "CAN_MB_ENHANCED_RXFIFO error"
#else
#if(CAN_MB_ENHANCED_RXFIFO != FLEXCAN_HW_MB_ENHANCED_RXFIFO)
    #error "CAN_MB_ENHANCED_RXFIFO error"
#endif
#endif

#ifndef CAN_FEATURE_HAS_FD
    #error "CAN_FEATURE_HAS_FD error"
#else
#if(CAN_FEATURE_HAS_FD != FLEXCAN_HW_FEATURE_HAS_FD)
    #error "CAN_FEATURE_HAS_FD error"
#endif
#endif


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_DRV_CFG_H */
