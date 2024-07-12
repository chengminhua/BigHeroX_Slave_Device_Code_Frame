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
**  FILENAME     : Dma_Drv_PBCfg.c                                            **
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
#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dma_Drv.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DMA_DRV_CFG_VENDOR_ID_C                       (1541U)
#define DMA_DRV_CFG_MODULE_ID_C                       (220U)
#define DMA_DRV_CFG_AR_RELEASE_MAJOR_VERSION_C        (4U)
#define DMA_DRV_CFG_AR_RELEASE_MINOR_VERSION_C        (4U)
#define DMA_DRV_CFG_AR_RELEASE_PATCH_VERSION_C        (0U)
#define DMA_DRV_CFG_SW_MAJOR_VERSION_H_C              (1U)
#define DMA_DRV_CFG_SW_MINOR_VERSION_H_C              (1U)
#define DMA_DRV_CFG_SW_PATCH_VERSION_H_C              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
 /* Dma_Drv_PBCfg.c Dma_Drv.h file version check */
#if(DMA_DRV_VENDOR_ID_H != DMA_DRV_CFG_VENDOR_ID_C)
    #error "Dma_Drv.h and Dma_Drv_PBCfg.c have different vendor ids"
#endif

#if (DMA_DRV_MODULE_ID_H != DMA_DRV_CFG_MODULE_ID_C)
    #error "Dma_Drv.h and Dma_Drv_PBCfg.c have different module ids"
#endif

#if((DMA_DRV_AR_RELEASE_MAJOR_VERSION_H != DMA_DRV_CFG_AR_RELEASE_MAJOR_VERSION_C) || \
     (DMA_DRV_AR_RELEASE_MINOR_VERSION_H != DMA_DRV_CFG_AR_RELEASE_MINOR_VERSION_C) || \
     (DMA_DRV_AR_RELEASE_PATCH_VERSION_H != DMA_DRV_CFG_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of Dma_Drv_PBCfg.c and Dma_Drv.h are different"
#endif

#if((DMA_DRV_SW_MAJOR_VERSION_H != DMA_DRV_CFG_SW_MAJOR_VERSION_H_C) || \
    (DMA_DRV_SW_MINOR_VERSION_H != DMA_DRV_CFG_SW_MINOR_VERSION_H_C) || \
    (DMA_DRV_SW_PATCH_VERSION_H != DMA_DRV_CFG_SW_PATCH_VERSION_H_C))
    #error "Software Version Numbers of Dma_Drv_PBCfg.c and Dma_Drv.h are different"
#endif

/******************************************************************************
*                                 Structure and other types
******************************************************************************/


#define DMA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

TT_CONST Dma_Drv_ChannelConfigType DmaChannelConfig[2] =
{
    {
        .DmaChannelId        = 0,
        .DmaIrqEn            = TRUE,
        .DmaAccessMode       = DMA_PRIVILEGE_MODE,
        .DmaSourceIncrease   = FALSE,
        .DmaDestIncrease     = TRUE,
        .DmaSourceDataWidth  = DMA_8_BIT_DATA,
        .DmaIntTtrg          = FALSE,
        .DmaDestDataWidth    = DMA_8_BIT_DATA,
        .DmaAllInOne         = FALSE,
        .DmaSourceBurstSize  = DMA_1_BURST,
        .DmaDestBurstSize    = DMA_1_BURST,
        .DmaFlowControl      = DMA_CONTROL_PERIPHERAL_TO_MEMERY,
        .DmaSMaster          = DMA_MASTER1,
        .DmaDMaster          = DMA_MASTER1,
        .DmaOneshotMode      = 0,
        .DmaContinuousMode   = FALSE,
        .DmaSrcPeripheralId  = DMA0_PERISEL_UART0_RX,
        .DmaDestPeripheralId = INVALID,
        .DmaLinkHead         = NULL,
        .DmaCrc              = 41695U
    },
    {
        .DmaChannelId        = 1,
        .DmaIrqEn            = TRUE,
        .DmaAccessMode       = DMA_PRIVILEGE_MODE,
        .DmaSourceIncrease   = TRUE,
        .DmaDestIncrease     = FALSE,
        .DmaSourceDataWidth  = DMA_8_BIT_DATA,
        .DmaIntTtrg          = FALSE,
        .DmaDestDataWidth    = DMA_8_BIT_DATA,
        .DmaAllInOne         = FALSE,
        .DmaSourceBurstSize  = DMA_1_BURST,
        .DmaDestBurstSize    = DMA_1_BURST,
        .DmaFlowControl      = DMA_CONTROL_MEMERY_TO_MEMERY,
        .DmaSMaster          = DMA_MASTER1,
        .DmaDMaster          = DMA_MASTER1,
        .DmaOneshotMode      = 0,
        .DmaContinuousMode   = FALSE,
        .DmaSrcPeripheralId  = INVALID,
        .DmaDestPeripheralId = INVALID,
        .DmaLinkHead         = NULL,
        .DmaCrc              = 47271U
    }
};

#define DMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"


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
