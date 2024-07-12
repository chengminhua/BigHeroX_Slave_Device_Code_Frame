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
**  FILENAME     : Dma_Drv_Cfg.h                                              **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : DMA Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef DMA_DRV_CFG_H
#define DMA_DRV_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_DMA.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DMA_DRV_CFG_VENDOR_ID_H                       (1541U)
#define DMA_DRV_CFG_MODULE_ID_H                       (220U)
#define DMA_DRV_CFG_INSTANCE_ID_H                     (0U)
#define DMA_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H        (4U)
#define DMA_DRV_CFG_AR_RELEASE_MINOR_VERSION_H        (4U)
#define DMA_DRV_CFG_AR_RELEASE_PATCH_VERSION_H        (0U)
#define DMA_DRV_CFG_SW_MAJOR_VERSION_H                (1U)
#define DMA_DRV_CFG_SW_MINOR_VERSION_H                (1U)
#define DMA_DRV_CFG_SW_PATCH_VERSION_H                (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#if (A8V2E_DMA_VENDOR_ID_H != DMA_DRV_CFG_VENDOR_ID_H)
    #error "A8V2E_DMA.h and Dma_Drv_Cfg.h have different vendor ids"
#endif

#if ((A8V2E_DMA_AR_RELEASE_MAJOR_VERSION_H != DMA_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_DMA_AR_RELEASE_MINOR_VERSION_H != DMA_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_DMA_AR_RELEASE_PATCH_VERSION_H != DMA_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_DMA.h and Dma_Drv_Cfg.h are different"
#endif

#if ((A8V2E_DMA_SW_MAJOR_VERSION_H != DMA_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (A8V2E_DMA_SW_MINOR_VERSION_H != DMA_DRV_CFG_SW_MINOR_VERSION_H) || \
     (A8V2E_DMA_SW_PATCH_VERSION_H != DMA_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_DMA.h and Dma_Drv_Cfg.h are different"
#endif

/******************************************************************************
*                                  Constants
******************************************************************************/

/******************************************************************************
*                              Defines and Macros
******************************************************************************/
#define DMA_VERSION_INFO_API              (STD_OFF)

#define DMA_DEV_ERROR_DETECT              (STD_OFF)

#define DMA_CONFIG_NUMBER                 (2U)


#define DMA_DRV_MODULE_ID                 (DMA_DRV_CFG_MODULE_ID_H)

#define DMA_DRV_INSTANCE_ID               (DMA_DRV_CFG_INSTANCE_ID_H)

#define DMA0_FLOW_CONTROL                 (STD_ON)

#define DMA1_FLOW_CONTROL                 (STD_OFF)

#define DMA2_FLOW_CONTROL                 (STD_OFF)

#define DMA3_FLOW_CONTROL                 (STD_OFF)

#define DMA0_CHANNEL0   
#define DMA0_CHANNEL1

/******************************************************************************
*                           Defines Check 
******************************************************************************/
#ifndef DMA_CONFIG_NUMBER
    #error "DMA CONFIG NUMBER Defines Error"
#else
#if(DMA_CONFIG_NUMBER != 2U)
    #error "DMA CONFIG NUMBER Defines Error"
#endif
#endif

#ifndef DMA_DRV_MODULE_ID
    #error "DMA DRV MODULE ID Defines Error"
#else
#if(DMA_DRV_MODULE_ID != DMA_DRV_CFG_MODULE_ID_H)
    #error "DMA DRV MODULE ID Defines Error"
#endif
#endif

#ifndef DMA_DRV_INSTANCE_ID
    #error "DMA DRV INSTANCE ID Defines Error"
#else
#if(DMA_DRV_INSTANCE_ID != DMA_DRV_CFG_INSTANCE_ID_H)
    #error "DMA DRV INSTANCE ID Defines Error"
#endif
#endif

#ifndef DMA_VERSION_INFO_API
    #error "DMA VERSION INFO API Defines Error"
#else
#if((DMA_VERSION_INFO_API != STD_OFF) && (DMA_VERSION_INFO_API != STD_ON))
    #error "DMA VERSION INFO API Defines Error"
#endif
#endif

#ifndef DMA_DEV_ERROR_DETECT
    #error "DMA ERROR DETECT Defines Error"
#else
#if((DMA_DEV_ERROR_DETECT != STD_OFF) && (DMA_DEV_ERROR_DETECT != STD_ON))
    #error "DMA ERROR DETECT Defines Error"
#endif
#endif

#ifndef DMA0_FLOW_CONTROL
    #error "DMA0 FLOW CONTROL Defines Error"
#else
#if((DMA0_FLOW_CONTROL != STD_OFF) && (DMA0_FLOW_CONTROL != STD_ON))
    #error "DMA0 FLOW CONTROL Defines Error"
#endif
#endif

#ifndef DMA1_FLOW_CONTROL
    #error "DMA1 FLOW CONTROL Defines Error"
#else
#if((DMA1_FLOW_CONTROL != STD_OFF) && (DMA1_FLOW_CONTROL != STD_ON))
    #error "DMA1 FLOW CONTROL Defines Error"
#endif
#endif

#ifndef DMA2_FLOW_CONTROL
    #error "DMA2 FLOW CONTROL Defines Error"
#else
#if((DMA2_FLOW_CONTROL != STD_OFF) && (DMA2_FLOW_CONTROL != STD_ON))
    #error "DMA2 FLOW CONTROL Defines Error"
#endif
#endif

#ifndef DMA3_FLOW_CONTROL
    #error "DMA3 FLOW CONTROL Defines Error"
#else
#if((DMA3_FLOW_CONTROL != STD_OFF) && (DMA3_FLOW_CONTROL != STD_ON))
    #error "DMA3 FLOW CONTROL Defines Error"
#endif
#endif
/******************************************************************************
*                               Enums 
******************************************************************************/

/******************************************************************************
*                       Structures and other Typedefs                 
******************************************************************************/

/******************************************************************************
*                    Global Variable Declarations                           
******************************************************************************/

/******************************************************************************
*                        Function Prototypes                         
******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
