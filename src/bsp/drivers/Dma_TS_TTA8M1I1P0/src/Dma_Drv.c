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
**  FILENAME     : Dma_Drv.c                                                  **
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
#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dma_Drv.h"
#include "Dma_Hw.h"

#if(defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#include "Base_Tools.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DMA_DRV_VENDOR_ID_C                      (1541U)
#define DMA_DRV_MODULE_ID_C                      (220U)
#define DMA_DRV_AR_RELEASE_MAJOR_VERSION_C       (4U)
#define DMA_DRV_AR_RELEASE_MINOR_VERSION_C       (4U)
#define DMA_DRV_AR_RELEASE_PATCH_VERSION_C       (0U)
#define DMA_DRV_SW_MAJOR_VERSION_C               (1U)
#define DMA_DRV_SW_MINOR_VERSION_C               (1U)
#define DMA_DRV_SW_PATCH_VERSION_C               (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dma_Drv.c Dma_Drv.h file version check */
#if (DMA_DRV_VENDOR_ID_C != DMA_DRV_VENDOR_ID_H)
    #error "Dma_Drv.h and Dma_Drv.c have different vendor ids"
#endif

#if (DMA_DRV_MODULE_ID_C != DMA_DRV_MODULE_ID_H)
    #error "Dma_Drv.h and Dma_Drv.c have different module ids"
#endif

#if ((DMA_DRV_AR_RELEASE_MAJOR_VERSION_C != DMA_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (DMA_DRV_AR_RELEASE_MINOR_VERSION_C != DMA_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (DMA_DRV_AR_RELEASE_PATCH_VERSION_C != DMA_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Drv.h and Dma_Drv.c are different"
#endif

/* Check if current file and Dma_Drv.h header file are of the same software version */
#if ((DMA_DRV_SW_MAJOR_VERSION_C != DMA_DRV_SW_MAJOR_VERSION_H) || \
     (DMA_DRV_SW_MINOR_VERSION_C != DMA_DRV_SW_MINOR_VERSION_H) || \
     (DMA_DRV_SW_PATCH_VERSION_C != DMA_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Drv.h and Dma_Drv.c are different"
#endif

/* Dma_Drv.c Dma_Hw.h file version check */
#if (DMA_DRV_VENDOR_ID_C != DMA_HW_VENDOR_ID_H)
    #error "Dma_Hw.h and Dma_Drv.c have different vendor ids"
#endif

#if (DMA_DRV_MODULE_ID_C != DMA_HW_MODULE_ID_H)
    #error "Dma_Hw.h and Dma_Drv.c have different module ids"
#endif

#if ((DMA_DRV_AR_RELEASE_MAJOR_VERSION_C != DMA_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (DMA_DRV_AR_RELEASE_MINOR_VERSION_C != DMA_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (DMA_DRV_AR_RELEASE_PATCH_VERSION_C != DMA_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Hw.h and Dma_Drv.c are different"
#endif

/* Check if current file and Dma_Drv.h header file are of the same software version */
#if ((DMA_DRV_SW_MAJOR_VERSION_C != DMA_HW_SW_MAJOR_VERSION_H) || \
     (DMA_DRV_SW_MINOR_VERSION_C != DMA_HW_SW_MINOR_VERSION_H) || \
     (DMA_DRV_SW_PATCH_VERSION_C != DMA_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Hw.h and Dma_Drv.c are different"
#endif

#if(defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/* Dma_Drv.c Base_Tools.h file version check */
#if (DMA_DRV_VENDOR_ID_C != BASE_TOOLS_VENDOR_ID_H)
    #error "Base_Tools.h and Dma_Drv.c have different vendor ids"
#endif

#if ((DMA_DRV_AR_RELEASE_MAJOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H) || \
     (DMA_DRV_AR_RELEASE_MINOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H) || \
     (DMA_DRV_AR_RELEASE_PATCH_VERSION_C != BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Tools.h and Dma_Drv.c are different"
#endif

/* Check if current file and Dma_Drv.h header file are of the same software version */
#if ((DMA_DRV_SW_MAJOR_VERSION_C != BASE_TOOLS_SW_MAJOR_VERSION_H) || \
     (DMA_DRV_SW_MINOR_VERSION_C != BASE_TOOLS_SW_MINOR_VERSION_H) || \
     (DMA_DRV_SW_PATCH_VERSION_C != BASE_TOOLS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Tools.h and Dma_Drv.c are different"
#endif
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/
#define DMA_START_SEC_VAR_CLEARED_32
#include "Dma_MemMap.h"
/*Initialize the state value*/
static volatile uint8 Init_cnt[DMA_NUMBERS] = {0U, 0U, 0U, 0U};
#define DMA_STOP_SEC_VAR_CLEARED_32
#include "Dma_MemMap.h"
/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/
#define DMA_START_SEC_CODE_FAST
#include "Dma_MemMap.h"
/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
/**
* @brief                Dma_Drv_PriParaCheck
* @details              Reports Det error if Dma_DEV_ERROR_DETECT == STD_ON
* @param[in]            Expr - boolean expression to check API conditions
* @param[in]            ApiId - ServiceApiId -Service Id of API
* @param[in]            ErrId - Error Id of Conditionl
* @param[out]           RetVal - variable to check return type
* @return
* @retval
* @pre
*/
LOCAL_INLINE void  Dma_Drv_PriParaCheck(boolean Expr,
                                        uint32 ApiId,
                                        TT_RetType ErrId,
                                        TT_RetType *RetVal);
/**
* @brief            Dma_Drv_PriRetCheck
* @details          Reports Det error if Dma_DEV_ERROR_DETECT == STD_ON
* @param[in]        ApiId - ServiceApiId -Service Id of API
* @param[out]       ErrId - Error Id of Conditionl
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Dma_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId);
#if(defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Dma_Drv_PriCalcCfgCrc.
* @details      Calculates the crc value of the configuration parameter.
* @param[in]    DmaChannelCfg - Config data
* @param[out]   u32AccCRCremainder - crc value
* @return       uint32
* @retval
* @pre
*/ 
static uint32 Dma_Drv_PriCalcCfgCrc(TT_CONST Dma_Drv_ChannelConfigType* DmaChannelCfg);
#endif
/******************************************************************************
*                            Public Functions
******************************************************************************/
/******************************************************************************
*  Service name     : Dma_Drv_Init
*  Syntax           : TT_RetType Dma_Drv_Init (TT_CONST uint32 Ch)
*  Service ID       : 100
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*                     TT_RET_STATUS_INIT_ERR - Channel already initialized
*  Description      : Initializes the Dma Driver module.
******************************************************************************/
TT_RetType Dma_Drv_Init (TT_CONST uint32 Ch)
{
    TT_CONST uint32 instance = Ch >> 3;
    
    TT_RetType Ret = TT_RET_SUCCESS ;
    Dma_Drv_PriParaCheck((Init_cnt[instance] != 0),
                        DMA_INIT_SERVICE_ID,
                        TT_RET_STATUS_INIT_ERR,
                        &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dma_Hw_Init(Ch);
        Dma_Drv_PriRetCheck(DMA_INIT_SERVICE_ID, &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
            Init_cnt[instance] = 1;
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}
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
TT_RetType Dma_Drv_DeInit (TT_CONST uint32 Hardware)
{
    TT_RetType Ret = TT_RET_SUCCESS ;

    Dma_Drv_PriParaCheck((Init_cnt[Hardware] != 1),
                        DMA_DEINIT_SERVICE_ID,
                        TT_RET_STATUS_UNINIT_ERR,
                        &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Dma_Hw_DeInit(Hardware);
        Dma_Drv_PriRetCheck(DMA_DEINIT_SERVICE_ID, &Ret);
        if(Ret == TT_RET_SUCCESS)
        {
            Init_cnt[Hardware] = 0;
        }
        else
        {
            Ret = TT_RET_STATUS_UNINIT_ERR;
        }
    }
    else
    {
        /*do nothing*/
    }
    return Ret;
}
#define DMA_STOP_SEC_CODE_SLOW
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE_FAST
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
TT_RetType Dma_Drv_ChannelConfigure (TT_CONST Dma_Drv_ChannelConfigType* DmaChannelCfg,
                                     TT_CONST uint32                 DmaTranferSize,
                                     TT_CONST uint32                 DmaSourceAddress,
                                     TT_CONST uint32                 DmaDestAddress,
                                     Dma_SignalEvent_t               Cb_Event)
{
    TT_RetType Ret = TT_RET_SUCCESS ;
    uint32 channel = 0;
    uint32 instance = 0;
    Dma_Drv_PriParaCheck((DmaChannelCfg == NULL_PTR),
                        DMA_CHANNEL_CONFIGURE_ID,
                        TT_RET_PARAM_NULL_PTR_ERR,
                        &Ret);
    if (Ret == TT_RET_SUCCESS)
    {
#if(defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        Dma_Drv_PriParaCheck((DmaChannelCfg->DmaCrc != Dma_Drv_PriCalcCfgCrc(DmaChannelCfg)),
                             DMA_CHANNEL_CONFIGURE_ID,
                             TT_RET_PARAM_CONFIG_ERR,
                             &Ret);
#endif
        Dma_Drv_PriParaCheck(DmaChannelCfg->DmaChannelId >= DMA_NUMBER_OF_CHANNELS,
                            DMA_CHANNEL_CONFIGURE_ID,
                            TT_RET_PARAM_CHANNEL_ERR,
                            &Ret);
        if (Ret == TT_RET_SUCCESS)
        {
            channel = DmaChannelCfg->DmaChannelId;
            instance = channel >> 3;

            if (Init_cnt[instance] == 0)
            {
#ifdef USING_OS_AUTOSAROS
                SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_03();
#endif
                Ret = Dma_Drv_Init(channel);
#ifdef USING_OS_AUTOSAROS
                SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_03();
#endif
            }
            else
            {
                /*do nothing*/
            }

            if (Ret == TT_RET_SUCCESS)
            {
                Ret = Dma_Hw_ChannelConfigure(DmaChannelCfg, DmaTranferSize, DmaSourceAddress, DmaDestAddress,Cb_Event);
            }
            else
            {
                /*do nothing*/
            }
            Dma_Drv_PriRetCheck(DMA_CHANNEL_CONFIGURE_ID, &Ret);
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}
#define DMA_STOP_SEC_CODE_FAST
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
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
TT_RetType Dma_Drv_ChannelEnable (TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS ;
    uint32 instance = Ch >> 3;

    if(Init_cnt[instance] != 0)
    {
        Ret = Dma_Hw_ChannelEnable(Ch);
        Dma_Drv_PriRetCheck(DMA_CHANNEL_ENABLE_SERVICE_ID, &Ret);
    }
    else
    {
        Ret =  TT_RET_STATUS_INIT_ERR;
    }

    return Ret;
}

/******************************************************************************
*  Service name     : Dma_Drv_ChannelDisable
*  Syntax           : TT_RetType Dma_Drv_ChannelDisable (TT_CONST uint32 Ch)
*  Service ID       : 104
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Ch - Dma channel id
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Channel id too large
*  Description      : Disable DMA channel
******************************************************************************/
TT_RetType Dma_Drv_ChannelDisable (TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS ;
    
    Ret = Dma_Hw_ChannelDisable(Ch);
    Dma_Drv_PriRetCheck(DMA_CHANNEL_DISABLE_SERVICE_ID, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name     : Dma_Drv_ChannelGetStatus
*  Syntax           : TT_RetType Dma_Drv_ChannelGetStatus (TT_CONST uint32 Ch,uint32 *Busy)
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
TT_RetType Dma_Drv_ChannelGetStatus (TT_CONST uint32 Ch, uint32 *Busy)
{
    TT_RetType Ret = TT_RET_SUCCESS ;

    Ret = Dma_Hw_ChannelGetStatus(Ch ,Busy);
    Dma_Drv_PriRetCheck(DMA_CHANNEL_GET_STATUS_SERVICE_ID, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name     : Dma_Drv_ChannelGetCount
*  Syntax           : TT_RetType Dma_Drv_ChannelGetCount (TT_CONST uint32 Ch,uint32 *Count)
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
TT_RetType Dma_Drv_ChannelGetCount (TT_CONST uint32 Ch, uint32 *Count)
{
    TT_RetType Ret = TT_RET_SUCCESS ;
    uint32 instance = Ch >> 3;

    Dma_Drv_PriParaCheck((Init_cnt[instance] != 1),
                        DMA_CHANNEL_GET_COUNT_SERVICE_ID,
                        TT_RET_STATUS_UNINIT_ERR,
                        &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dma_Hw_ChannelGetCount(Ch, Count);
        Dma_Drv_PriRetCheck(DMA_CHANNEL_GET_COUNT_SERVICE_ID, &Ret);
    }
    else
    {
        /*do nothing*/
    }
    
    return Ret;
}

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
TT_RetType Dma_Drv_OneShotTrigger(TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS ;
    uint32 instance = Ch >> 3;

    Dma_Drv_PriParaCheck((Init_cnt[instance] != 1),
                            DMA_CHANNEL_GET_COUNT_SERVICE_ID,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dma_Hw_OneShotTrigger(Ch);
        Dma_Drv_PriRetCheck(DMA_CHANNEL_ONESHOT_TRIGGER_SERVICE_ID, &Ret);
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}

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
TT_RetType Dma_Drv_DisableOneShot(TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS ;

    Ret = Dma_Hw_DisableOneShot(Ch);
    Dma_Drv_PriRetCheck(DMA_CHANNEL_DISABLE_ONESHOT_SERVICE_ID, &Ret);

    return Ret;
}

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
TT_RetType Dma_Drv_DisableContinuation(TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS ;

    Ret = Dma_Hw_DisableContinuation(Ch);
    Dma_Drv_PriRetCheck(DMA_CHANNEL_DISABLE_CONTINUATION_SERVICE_ID, &Ret);

    return Ret;
}

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
TT_RetType Dma_Drv_Softwaretrigger(TT_CONST Dma_Drv_ChannelConfigType* DmaChannelCfg, TT_CONST uint32 BReq)
{
    TT_RetType Ret = TT_RET_SUCCESS ;

    Dma_Drv_PriParaCheck((DmaChannelCfg == NULL_PTR),
                         DMA_SOFTWARETRIGGER_ID,
                        TT_RET_PARAM_NULL_PTR_ERR,
                        &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        uint32 instance = DmaChannelCfg->DmaChannelId >> 3;

        Dma_Drv_PriParaCheck((Init_cnt[instance] != 1),
                             DMA_SOFTWARETRIGGER_ID,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
            Ret = Dma_Hw_Softwaretrigger(DmaChannelCfg,BReq);
            Dma_Drv_PriRetCheck(DMA_SOFTWARETRIGGER_ID, &Ret);
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}
#if (DMA_VERSION_INFO_API == STD_ON)
/******************************************************************************
*  Service name    : Dma_Drv_GetVersionInfo
*  Syntax          : TT_RetType Dma_Drv_GetVersionInfo(Std_VersionInfoType* TT_CONST VersioninfoPtr)
*  Service ID      : 112
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): VersioninfoPtr - Pointer to where to store the version information of this module.
*  Return value    : TT_RET_SUCCESS - Funcation success
*                    TT_RET_PARAM_NULL_PTR_ERR - VersioninfoPtr is NULL
*  Description     : Returns the version information of this module.
******************************************************************************/
TT_RetType Dma_Drv_GetVersionInfo(Std_VersionInfoType* TT_CONST VersioninfoPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Dma_Drv_PriParaCheck((NULL_PTR == VersioninfoPtr),
                        DMA_GETVERSIONINFO_SID,
                        TT_RET_PARAM_NULL_PTR_ERR,
                        &Ret);
                        
    if (TT_RET_SUCCESS == Ret)
    {
        VersioninfoPtr->vendorID          = DMA_DRV_VENDOR_ID_H ;
        VersioninfoPtr->moduleID          = DMA_DRV_MODULE_ID_H ;
        VersioninfoPtr->sw_major_version = DMA_DRV_SW_MAJOR_VERSION_H ;
        VersioninfoPtr->sw_minor_version = DMA_DRV_SW_MINOR_VERSION_H ;
        VersioninfoPtr->sw_patch_version = DMA_DRV_SW_PATCH_VERSION_H ;
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}
#endif

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
/**
* @brief                Dma_Drv_PriParaCheck
* @details              Dma para check
* @param[in]            Expr - boolean expression to check API conditions
* @param[in]            ApiId - ServiceApiId -Service Id of API
* @param[in]            ErrId - Error Id of Conditionl
* @param[out]           RetVal - variable to check return type
* @return
* @retval
* @pre
*/
LOCAL_INLINE void  Dma_Drv_PriParaCheck(boolean Expr,
                                        uint32 ApiId,
                                        TT_RetType ErrId,
                                        TT_RetType *RetVal)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if(NULL_PTR != RetVal)
    {
        if ((TRUE == Expr) && (*RetVal == TT_RET_SUCCESS))
        {
            *RetVal = ErrId;
#if defined(DMA_DEV_ERROR_DETECT) && (DMA_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(DMA_DRV_MODULE_ID, (uint8)ApiId, ErrId);
            ModuleDet_ReportError(DMA_DRV_MODULE_ID, DMA_DRV_INSTANCE_ID, (uint8)ApiId, (uint8)ErrId);
#else
            (void)ApiId;
#endif
        }
        else
        {
        /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }
#else
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    *(RetVal) = ((uint32)(RetVal) > 1) ? 0U: 1U;
#endif
} /* end of Dma_Drv_PriParaCheck */

/**
* @brief            Dma_Drv_PriRetCheck
* @details          Dma return value check
* @param[in]        ApiId - ServiceApiId -Service Id of API
* @param[out]       ErrId - Error Id of Conditionl
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Dma_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if(NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
#if defined(DMA_DEV_ERROR_DETECT) && (DMA_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(DMA_DRV_MODULE_ID, (uint8)ApiId, *ErrId);
            ModuleDet_ReportError(DMA_DRV_MODULE_ID, DMA_DRV_INSTANCE_ID, (uint8)ApiId, (uint8)*ErrId);
#endif
            *ErrId = TT_SET_STATUS_TYPE(DMA_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }
#endif
    (void)ApiId;
    (void)ErrId;
}

#if(defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Dma_Drv_PriCalcCfgCrc.
* @details      Calculates the crc value of the configuration parameter.
* @param[in]    DmaChannelCfg - Config data
* @param[out]   None
* @return       uint32
* @retval       u32AccCRCremainder - crc value
* @pre
*/ 
static uint32 Dma_Drv_PriCalcCfgCrc(TT_CONST Dma_Drv_ChannelConfigType* DmaChannelCfg)
{
    /* Reset the accumulated CRC value */
    uint32 u32AccCRCremainder=0;
    uint32 i = 0;

    if(DmaChannelCfg != NULL)
    {
        if(DmaChannelCfg->DmaLinkHead != NULL)
        {
            for(i=0;i<DmaChannelCfg->DmaLinkHead->DmaNodeCount;i++)
            {
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaSourceIncrease),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaDestIncrease),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaSMaster),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaDMaster),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaSourceBurstSize),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaDestBurstSize),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaSourceDataWidth),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaDestDataWidth),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaAccessMode),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaIntTtrg),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaAllInOne),&u32AccCRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaLliIrqEn),&u32AccCRCremainder);
            }
            Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaLinkHead->DmaNodeCount),&u32AccCRCremainder);
        }
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaChannelId),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaSourceIncrease),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaDestIncrease),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaSMaster),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaDMaster),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaFlowControl),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaDestPeripheralId),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaSrcPeripheralId),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaAccessMode),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaSourceDataWidth),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaDestDataWidth),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaSourceBurstSize),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaDestBurstSize),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaIntTtrg),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaAllInOne),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaIrqEn),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaOneshotMode),&u32AccCRCremainder);
        Base_AccumulateCRC((TT_CONST uint32)(DmaChannelCfg->DmaContinuousMode),&u32AccCRCremainder);
    }
    else
    {
        /*do nothing*/
    }

    return ((uint32)Base_FinalizeCRC(&u32AccCRCremainder));
}
#endif

#ifdef __cplusplus
}
#endif
