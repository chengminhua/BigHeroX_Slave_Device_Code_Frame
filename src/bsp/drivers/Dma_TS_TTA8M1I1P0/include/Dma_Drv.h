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
**  FILENAME     : Dma_Drv.h                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Dma Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef DMA_DRV_H
#define DMA_DRV_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dma_Drv_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DMA_DRV_VENDOR_ID_H                    (1541U)
#define DMA_DRV_MODULE_ID_H                    (220U)
#define DMA_DRV_AR_RELEASE_MAJOR_VERSION_H     (4U)
#define DMA_DRV_AR_RELEASE_MINOR_VERSION_H     (4U)
#define DMA_DRV_AR_RELEASE_PATCH_VERSION_H     (0U)
#define DMA_DRV_SW_MAJOR_VERSION_H             (1U)
#define DMA_DRV_SW_MINOR_VERSION_H             (1U)
#define DMA_DRV_SW_PATCH_VERSION_H             (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dma_Drv.h Dma_Drv_Types.h file version check */
#if (DMA_DRV_TYPES_VENDOR_ID_H != DMA_DRV_VENDOR_ID_H)
    #error "Dma_Drv.h and Dma_Drv_Types.h have different vendor ids"
#endif

#if (DMA_DRV_TYPES_MODULE_ID_H != DMA_DRV_MODULE_ID_H)
    #error "Dma_Drv.h and Dma_Drv_Types.h have different module ids"
#endif

#if ((DMA_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != DMA_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (DMA_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != DMA_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (DMA_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != DMA_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Drv.h and Dma_Drv_Types.h are different"
#endif

#if ((DMA_DRV_TYPES_SW_MAJOR_VERSION_H != DMA_DRV_SW_MAJOR_VERSION_H) || \
     (DMA_DRV_TYPES_SW_MINOR_VERSION_H != DMA_DRV_SW_MINOR_VERSION_H) || \
     (DMA_DRV_TYPES_SW_PATCH_VERSION_H != DMA_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Drv.h and Dma_Drv_Types.h are different"
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
#define DMA_START_SEC_CODE_FAST
#include "Dma_MemMap.h"
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
/******************************************************************************
*  Service name     : Dma_Drv_Init
*  Syntax           : TT_RetType Dma_Drv_Init (uint32 Ch)
*  Service ID       : 100
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*                     TT_RET_STATUS_INIT_ERR - Channel already initialized
*  Description      : Initializes the Dma Driver module.
******************************************************************************/
extern TT_RetType Dma_Drv_Init (TT_CONST uint32 Ch);
#define DMA_STOP_SEC_CODE_FAST
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE_SLOW
#include "Dma_MemMap.h"
/******************************************************************************
*  Service name     : Dma_Drv_DeInit
*  Syntax           : TT_RetType Dma_Drv_DeInit (TT_CONST uint32 Hardware)
*  Service ID       : 101
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Hardware - Dma Hardware Unit
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*                     TT_RET_STATUS_UNINIT_ERR - Channel uninitialized
*  Description      : De-initialize the Dma Driver module.
******************************************************************************/
extern TT_RetType Dma_Drv_DeInit (TT_CONST uint32 Hardware);
#define DMA_STOP_SEC_CODE_SLOW
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/******************************************************************************
*  Service name     : Dma_Drv_ChannelConfigure
*  Syntax           : TT_RetType Dma_Drv_ChannelConfigure (TT_CONST Dma_Drv_ChannelConfigType* DmaChannelCfg,
                                                           TT_CONST uint32                 DmaTranferSize,
                                                           TT_CONST uint32                 DmaSourceAddress,
                                                           TT_CONST uint32                 DmaDestAddress,
                                                           Dma_SignalEvent_t               Cb_Event)
*  Service ID       : 102
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : DmaChannelCfg - Config data
*  Parameters (in)  : DmaTranferSize - Transfer size
*  Parameters (in)  : DmaSourceAddress - Source address
*  Parameters (in)  : DmaDestAddress - Destination address
*  Parameters (in)  : Cb_Event - Channel callback pointer
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_NULL_PTR_ERR - Config is NULL
*                     TT_RET_PARAM_CHANNEL_ERR - Channel id too large
*                     TT_RET_STATUS_ERR - Channel is active
*  Description      : Configure DMA channel for next transfer
******************************************************************************/
extern TT_RetType Dma_Drv_ChannelConfigure (TT_CONST Dma_Drv_ChannelConfigType* DmaChannelCfg,
                                            TT_CONST uint32              DmaTranferSize,
                                            TT_CONST uint32              DmaSourceAddress,
                                            TT_CONST uint32              DmaDestAddress,
                                            Dma_SignalEvent_t            Cb_Event);

/******************************************************************************
*  Service name     : Dma_Drv_ChannelEnable
*  Syntax           : TT_RetType Dma_Drv_ChannelEnable (TT_CONST uint32 Ch)
*  Service ID       : 103
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*                     TT_RET_STATUS_ERR - Channel is active
*  Description      : Enable DMA channel
******************************************************************************/
extern TT_RetType Dma_Drv_ChannelEnable (TT_CONST uint32 Ch);

/******************************************************************************
*  Service name     : Dma_Drv_ChannelDisable
*  Syntax           : TT_RetType Dma_ChannelDisable (TT_CONST uint32 Ch)
*  Service ID       : 104
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*  Description      : Disable DMA channel
******************************************************************************/
extern TT_RetType Dma_Drv_ChannelDisable (TT_CONST uint32 Ch);

/******************************************************************************
*  Service name     : Dma_Drv_ChannelGetStatus
*  Syntax           : TT_RetType Dma_Drv_ChannelGetStatus (TT_CONST uint32 Ch,
*                                                          uint32 *Busy)
*  Service ID       : 105
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Parameters (out) : Busy - Dma channel status
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*                     TT_RET_PARAM_NULL_PTR_ERR - Busy is NULL
*  Description      : Get DMA active channel
******************************************************************************/
extern TT_RetType Dma_Drv_ChannelGetStatus (TT_CONST uint32 Ch,
                                            uint32 *Busy);

/******************************************************************************
*  Service name     : Dma_Drv_ChannelGetCount
*  Syntax           : TT_RetType Dma_Drv_ChannelGetCount (TT_CONST uint32 Ch,
*                                                         uint32 *Count)
*  Service ID       : 106
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Parameters (out) : Count - Number of transferred data
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*                     TT_RET_PARAM_NULL_PTR_ERR - Count is NULL
*  Description      : Get number of transferred data
******************************************************************************/
extern TT_RetType Dma_Drv_ChannelGetCount (TT_CONST uint32 Ch,
                                           uint32 *Count);

/******************************************************************************
*  Service name     : Dma_Drv_OneShotTrigger
*  Syntax           : TT_RetType Dma_Drv_OneShotTrigger(TT_CONST uint32 Ch)
*  Service ID       : 107
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*  Description      : Trigger one shot mode
******************************************************************************/
extern TT_RetType Dma_Drv_OneShotTrigger(TT_CONST uint32 Ch);

/******************************************************************************
*  Service name     : Dma_Drv_DisableOneShot
*  Syntax           : TT_RetType Dma_Drv_DisableOneShot(TT_CONST uint32 Ch)
*  Service ID       : 108
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*  Description      : Disable one shot mode
******************************************************************************/
extern TT_RetType Dma_Drv_DisableOneShot(TT_CONST uint32 Ch);

/******************************************************************************
*  Service name     : Dma_Drv_DisableContinuation
*  Syntax           : TT_RetType Dma_Drv_DisableContinuation(TT_CONST uint32 Ch)
*  Service ID       : 109
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*  Description      : Disable continuation
******************************************************************************/
extern TT_RetType Dma_Drv_DisableContinuation(TT_CONST uint32 Ch);

/******************************************************************************
*  Service name     : Dma_Drv_Softwaretrigger
*  Syntax           : TT_RetType Dma_Drv_Softwaretrigger(TT_CONST Dma_Drv_ChannelConfigType* DmaChannelCfg,TT_CONST uint32 BReq)
*  Service ID       : 110
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : DmaChannelCfg - config data
*  Parameters (in)  : BReq - Software trigger request group id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_NULL_PTR_ERR - Channel config is NULL
*                     TT_RET_PARAM_ERR - BReq is too large
*  Description      : Provide a software trigger request for Dma channel
******************************************************************************/
extern TT_RetType Dma_Drv_Softwaretrigger(TT_CONST Dma_Drv_ChannelConfigType* DmaChannelCfg, TT_CONST uint32 BReq);

#if (DMA_VERSION_INFO_API == STD_ON)
/******************************************************************************
*  Service name    : Dma_Drv_GetVersionInfo
*  Syntax          : TT_RetType Dma_Drv_GetVersionInfo(Std_VersionInfoType*TT_CONST VersioninfoPtr)
*  Service ID      : 111
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): VersioninfoPtr - Pointer to where to store the version information of this module.
*  Return value    : TT_RET_SUCCESS - Funcation success
*                    TT_RET_PARAM_NULL_PTR_ERR - VersioninfoPtr is NULL
*  Description     : Returns the version information of this module.
******************************************************************************/
extern TT_RetType Dma_Drv_GetVersionInfo(Std_VersionInfoType*TT_CONST VersioninfoPtr);
#endif
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"
#endif
