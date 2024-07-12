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
**  FILENAME     : Dma_Hw.h                                                   **
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
#ifndef DMA_HW_H
#define DMA_HW_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dma_Hw_Types.h"

#ifdef USING_OS_AUTOSAROS
#include "SchM_Dma.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DMA_HW_VENDOR_ID_H                    (1541U)
#define DMA_HW_MODULE_ID_H                    (220U)
#define DMA_HW_AR_RELEASE_MAJOR_VERSION_H     (4U)
#define DMA_HW_AR_RELEASE_MINOR_VERSION_H     (4U)
#define DMA_HW_AR_RELEASE_PATCH_VERSION_H     (0U)
#define DMA_HW_SW_MAJOR_VERSION_H             (1U)
#define DMA_HW_SW_MINOR_VERSION_H             (1U)
#define DMA_HW_SW_PATCH_VERSION_H             (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dma_Hw.h Dma_Hw_Types.h file version check */
#if (DMA_HW_TYPES_VENDOR_ID_H != DMA_HW_VENDOR_ID_H)
    #error "Dma_Hw_Types.h and Dma_Hw.h have different vendor ids"
#endif

#if (DMA_HW_TYPES_MODULE_ID_H != DMA_HW_MODULE_ID_H)
    #error "Dma_Hw_Types.h and Dma_Hw.h have different module ids"
#endif

#if ((DMA_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != DMA_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (DMA_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != DMA_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (DMA_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != DMA_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Hw.h and Dma_Hw_Types.h are different"
#endif

#if ((DMA_HW_TYPES_SW_MAJOR_VERSION_H != DMA_HW_SW_MAJOR_VERSION_H) || \
     (DMA_HW_TYPES_SW_MINOR_VERSION_H != DMA_HW_SW_MINOR_VERSION_H) || \
     (DMA_HW_TYPES_SW_PATCH_VERSION_H != DMA_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Hw.h and Dma_Hw_Types.h are different"
#endif

/* Dma_Hw.h SchM_Dma.h file version check */
#ifdef USING_OS_AUTOSAROS
#if (SCHM_DMA_VENDOR_ID_H != DMA_HW_VENDOR_ID_H)
    #error "SchM_Dma.h and Dma_Hw.h have different vendor ids"
#endif

#if ((SCHM_DMA_AR_RELEASE_MAJOR_VERSION != DMA_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (SCHM_DMA_AR_RELEASE_MINOR_VERSION != DMA_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (SCHM_DMA_AR_RELEASE_REVISION_VERSION != DMA_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Hw.h and SchM_Dma.h are different"
#endif

#if ((SCHM_DMA_SW_MAJOR_VERSION != DMA_HW_SW_MAJOR_VERSION_H) || \
     (SCHM_DMA_SW_MINOR_VERSION != DMA_HW_SW_MINOR_VERSION_H) || \
     (SCHM_DMA_SW_PATCH_VERSION != DMA_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Hw.h and SchM_Dma.h are different"
#endif
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

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
*                            Public Functions
*******************************************************************************/
#define DMA_START_SEC_CODE_FAST
#include "Dma_MemMap.h"
/**
* @brief          TT_RetType Dma_Hw_Init
* @details        Initialize DMA peripheral
* @param[in]      Ch        Channel number (0..31)
* @retval         TT_RET_SUCCESS - success
                  Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_Init (TT_CONST uint32 Ch);
#define DMA_STOP_SEC_CODE_FAST
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE_SLOW
#include "Dma_MemMap.h"
/**
* @brief        Dma_Hw_DeInit
* @details      De-initialize DMA peripheral
* @param[in]    Hardware - Dma Hardware Unit
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_DeInit (TT_CONST uint32 Hardware);
#define DMA_STOP_SEC_CODE_SLOW
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE_FAST
#include "Dma_MemMap.h"
/**
* @brief          Dma_Hw_ChannelConfigure
* @details        Configure  DMA channel for next transfer
* @param[in]      DmaChannelCfg config data
* @param[in]      DmaTranferSize   transfer size
* @param[in]      DmaSourceAddress Source address
* @param[in]      DmaDestAddress   Destination address
* @param[in]      Cb_Event         Channel callback pointer
* @return         TT_RetType
* @retval         TT_RET_SUCCESS - success
                  Others - fail
*/
extern TT_RetType Dma_Hw_ChannelConfigure (TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg,
                                           TT_CONST uint32           DmaTranferSize,
                                           TT_CONST uint32           DmaSourceAddress,
                                           TT_CONST uint32           DmaDestAddress,
                                           Dma_SignalEvent_t         Cb_Event);
#define DMA_STOP_SEC_CODE_FAST
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/**
* @brief         Dma_Hw_OneShotTrigger
* @details       Trigger one shot mode
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_OneShotTrigger(TT_CONST uint32 Ch);

/**
* @brief         Dma_Hw_DisableOneShot
* @details       Disable one shot mode
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_DisableOneShot(TT_CONST uint32 Ch);

/**
* @brief         Dma_Hw_DisableContinuation
* @details       Disable continuation mode
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_DisableContinuation(TT_CONST uint32 Ch);

/**
* @brief         Dma_Hw_ChannelEnable
* @details       Enable DMA channel
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_ChannelEnable (TT_CONST uint32 Ch);

/**
* @brief         Dma_Hw_ChannelDisable
* @details       Disable DMA channel
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_ChannelDisable (TT_CONST uint32 Ch);

/**
* @brief         Dma_Hw_ChannelGetCount
* @details       Get number of transferred data
* @param[in]     Ch - Dma channel id
* @param[out]    Count - Number of transferred data
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_ChannelGetCount (TT_CONST uint32 Ch, uint32 *Count);

/**
* @brief         Dma_Hw_ChannelGetStatus
* @details       Get DMA active channel
* @param[in]     Ch - Dma channel id
* @param[out]    Busy - Dma channel status
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_ChannelGetStatus(TT_CONST uint32 Ch, uint32 *Busy);

/**
* @brief         Dma_Hw_Softwaretrigger
* @details       Provide a software trigger request for Dma channel
* @param[in]     DmaChannelCfg - config data
* @param[in]     BReq - Software trigger request group id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Dma_Hw_Softwaretrigger(TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg,TT_CONST uint32 BReq);
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE_FAST
#include "Dma_MemMap.h"
ISR(GPDMA0_COMBINE_IRQHandler);

ISR(GPDMA1_COMBINE_IRQHandler);

ISR(GPDMA2_COMBINE_IRQHandler);

ISR(GPDMA3_COMBINE_IRQHandler);
#define DMA_STOP_SEC_CODE_FAST
#include "Dma_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
