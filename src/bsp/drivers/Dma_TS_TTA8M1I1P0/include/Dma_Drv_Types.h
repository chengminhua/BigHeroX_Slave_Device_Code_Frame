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
**  FILENAME     : Dma_Drv_Types.h                                            **
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
#ifndef DMA_DRV_TYPES_H
#define DMA_DRV_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dma_Hw_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DMA_DRV_TYPES_VENDOR_ID_H                    (1541U)
#define DMA_DRV_TYPES_MODULE_ID_H                    (220UL)
#define DMA_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H     (4U)
#define DMA_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H     (4U)
#define DMA_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H     (0U)
#define DMA_DRV_TYPES_SW_MAJOR_VERSION_H             (1U)
#define DMA_DRV_TYPES_SW_MINOR_VERSION_H             (1U)
#define DMA_DRV_TYPES_SW_PATCH_VERSION_H             (0U)
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dma_Hw_Types.h Dma_Drv_Types.h file version check */
#if (DMA_DRV_TYPES_VENDOR_ID_H != DMA_HW_TYPES_VENDOR_ID_H)
    #error "Dma_Drv_Types.h and Dma_Hw_Types.h have different vendor ids"
#endif

#if (DMA_DRV_TYPES_MODULE_ID_H != DMA_HW_TYPES_MODULE_ID_H)
    #error "Dma_Drv_Types.h and Dma_Hw_Types.h have different module ids"
#endif

#if ((DMA_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != DMA_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (DMA_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != DMA_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (DMA_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != DMA_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Hw_Types.h and Dma_Drv_Types.h are different"
#endif

#if ((DMA_DRV_TYPES_SW_MAJOR_VERSION_H != DMA_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (DMA_DRV_TYPES_SW_MINOR_VERSION_H != DMA_HW_TYPES_SW_MINOR_VERSION_H) || \
     (DMA_DRV_TYPES_SW_PATCH_VERSION_H != DMA_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Hw_Types.h and Dma_Drv_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define DMA_INIT_SERVICE_ID                             (100u)      /* Service ID For Dma_Drv_Init API */
#define DMA_DEINIT_SERVICE_ID                           (101u)      /* Service ID For Dma_Drv_DeInit API */
#define DMA_CHANNEL_CONFIGURE_ID                        (102u)      /* Service ID For Dma_Drv_ChannelConfigure API */
#define DMA_CHANNEL_ENABLE_SERVICE_ID                   (103u)      /* Service ID For Dma_Drv_ChannelEnable API */
#define DMA_CHANNEL_DISABLE_SERVICE_ID                  (104u)      /* Service ID For Dma_Drv_ChannelDisable API */
#define DMA_CHANNEL_GET_STATUS_SERVICE_ID               (105u)      /* Service ID For Dma_Drv_ChannelGetStatus API */
#define DMA_CHANNEL_GET_COUNT_SERVICE_ID                (106u)      /* Service ID For Dma_Drv_ChannelGetCount API */
#define DMA_CHANNEL_ONESHOT_TRIGGER_SERVICE_ID          (107u)      /* Service ID For Dma_Drv_OneShotTrigger API */
#define DMA_CHANNEL_DISABLE_ONESHOT_SERVICE_ID          (108u)      /* Service ID For Dma_Drv_DisableOneShot API */
#define DMA_CHANNEL_DISABLE_CONTINUATION_SERVICE_ID     (109u)      /* Service ID For Dma_Drv_DisableContinuation API */
#define DMA_SOFTWARETRIGGER_ID                          (110u)      /* Service ID For Dma_Drv_Softwaretrigger API */
#define DMA_GETVERSIONINFO_SID                          (111u)      /* Service ID For Dma_Drv_GetVersionInfo API */
/*Status error message*/
#define DMA_DRV_TT_STATUS_DEFAULT(ApiID) (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET)| \
                                                      ((ApiID) << TT_APIID_OFFSET)          | \
                                                      (DMA_DRV_TYPES_MODULE_ID_H << TT_MODULEID_OFFSET))
/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/*Universal Dma configuration*/
typedef Dma_Hw_ChannelConfigType      Dma_Drv_ChannelConfigType;
/*Dma linked Head type*/
typedef Dma_Hw_LinkHeadType           Dma_Drv_LinkHeadType;
/*Dma linked Node type*/
typedef Dma_Hw_LinkNodeType           Dma_Drv_LinkNodeType;
/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */
