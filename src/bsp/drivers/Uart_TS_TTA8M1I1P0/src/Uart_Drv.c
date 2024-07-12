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
**  FILENAME     : Uart_Drv.c                                                       **
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
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                            Includes
 ******************************************************************************/
#include "Uart_Drv.h"
#include "Uart_Hal.h"

#ifdef USING_OS_AUTOSAROS
#include "SchM_Uart.h"
#endif
/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define UART_DRV_VENDOR_ID_C                     1541
#define UART_DRV_MODULE_ID_C                     227
#define UART_DRV_AR_RELEASE_MAJOR_VERSION_C      4
#define UART_DRV_AR_RELEASE_MINOR_VERSION_C      4
#define UART_DRV_AR_RELEASE_PATCH_VERSION_C      0
#define UART_DRV_SW_MAJOR_VERSION_C              1
#define UART_DRV_SW_MINOR_VERSION_C              1
#define UART_DRV_SW_PATCH_VERSION_C              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Uart_Drv.c and Uart_Drv.h file version check */
#if (UART_DRV_VENDOR_ID_C != UART_DRV_VENDOR_ID_H)
    #error "Uart_Drv.c and Uart_Drv.h have different vendor ids"
#endif
#if (UART_DRV_MODULE_ID_C != UART_DRV_MODULE_ID_H)
    #error "Uart_Drv.c and Uart_Drv.h have different module ids"
#endif
#if ((UART_DRV_AR_RELEASE_MAJOR_VERSION_C != UART_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_DRV_AR_RELEASE_MINOR_VERSION_C != UART_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_DRV_AR_RELEASE_PATCH_VERSION_C != UART_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Drv.c and Uart_Drv.h are different"
#endif
#if ((UART_DRV_SW_MAJOR_VERSION_C != UART_DRV_SW_MAJOR_VERSION_H) || \
     (UART_DRV_SW_MINOR_VERSION_C != UART_DRV_SW_MINOR_VERSION_H) || \
     (UART_DRV_SW_PATCH_VERSION_C != UART_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Drv.c and Uart_Drv.h are different"
#endif

/* Uart_Drv.c and Uart_Hal.h file version check */
#if (UART_DRV_VENDOR_ID_C != UART_HAL_VENDOR_ID_H)
    #error "Uart_Drv.c and Uart_Hal.h have different vendor ids"
#endif
#if (UART_DRV_MODULE_ID_C != UART_HAL_MODULE_ID_H)
    #error "Uart_Drv.c and Uart_Hal.h have different module ids"
#endif
#if ((UART_DRV_AR_RELEASE_MAJOR_VERSION_C != UART_HAL_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_DRV_AR_RELEASE_MINOR_VERSION_C != UART_HAL_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_DRV_AR_RELEASE_PATCH_VERSION_C != UART_HAL_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Drv.c and Uart_Hal.h are different"
#endif
#if ((UART_DRV_SW_MAJOR_VERSION_C != UART_HAL_SW_MAJOR_VERSION_H) || \
     (UART_DRV_SW_MINOR_VERSION_C != UART_HAL_SW_MINOR_VERSION_H) || \
     (UART_DRV_SW_PATCH_VERSION_C != UART_HAL_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Drv.c and Uart_Hal.h are different"
#endif
/******************************************************************************
 *                            Private Typedefs
 *******************************************************************************/

/******************************************************************************
 *                            Private Macros
 *******************************************************************************/
/* Error message stitching */
#define UART_DRV_TT_STATUS_DEFAULT(ApiID)       (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET)| \
                                                ((ApiID) << TT_APIID_OFFSET) | \
                                                (UART_DRV_MODULE_ID_C << TT_MODULEID_OFFSET))
/******************************************************************************
 *                            Private Constants
 *******************************************************************************/

/******************************************************************************
 *                            Private Variables
 *******************************************************************************/
#define UART_START_SEC_VAR_FAST_CLEARED_BOOLEAN
#include "Uart_MemMap.h"
/* Initializes the status flag */
static boolean Uart_PubInitialised = FALSE;

#define UART_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
#include "Uart_MemMap.h"
/******************************************************************************
 *                            Public Constants
 *******************************************************************************/

/******************************************************************************
 *                            Public Variables
 *******************************************************************************/

/******************************************************************************
 *                       Private Variable Definitions
 ******************************************************************************/
/******************************************************************************
*                    Private Function Declaration
******************************************************************************/

/**
 * @brief      :  Reporting error status
 * @details    :  Reporting error status
 *
 * @param[in]  :  Expr  - The condition of error occurs
 *                ApiId - Error status code
 *                ErrId - Determine whether an error occurred
 * @param[out] :  RetVal - Current status setting
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
LOCAL_INLINE void Uart_Drv_PriParaCheck(boolean Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal);

/**
 * @brief      :  Reporting error status
 * @details    :  Reporting error status
 *
 * @param[in]  :  ApiId - Error status code
 *                ErrId - Determine whether an error occurred
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
LOCAL_INLINE void Uart_Drv_PriRetCheck(uint8 ApiId, TT_RetType *ErrId);

/******************************************************************************
 *                            Public Functions
 *******************************************************************************/

#define UART_START_SEC_CODE_SLOW
#include "Uart_MemMap.h"
/******************************************************************************
*  Service name      : Uart_Drv_Init
*  Syntax            : TT_RetType Uart_Drv_Init(TT_CONST Uart_ConfigType *CfgPtr)
*  Service ID        : 100
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : CfgPtr - Pointer to configtype structure
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: The initialization is complete
*                      Other: Initialization is not complete
*  Description       : Service for initialization of UART
******************************************************************************/
TT_RetType Uart_Drv_Init(TT_CONST Uart_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Uart_ConfigType *TmpPtr = NULL_PTR;


#ifdef UART_PRECOMPILE_SUPPORT
    Uart_Drv_PriParaCheck((NULL_PTR != ConfigPtr),
                           UART_SI_INIT,
                           TT_RET_PARAM_INVALID_PTR_ERR,
                           &Ret);
    if(TT_RET_SUCCESS == Ret)
    {
        TmpPtr = (TT_CONST Uart_ConfigType *) &UartConfigData;
    }
    else
    {
        /* do nothing */
    }

#else
    Uart_Drv_PriParaCheck((NULL_PTR == ConfigPtr),
                           UART_SI_INIT,
                           TT_RET_PARAM_NULL_PTR_ERR,
                           &Ret);
    if(TT_RET_SUCCESS == Ret)
    {
        TmpPtr = ConfigPtr;
    }
    else
    {
        /* do nothing */
    }


#endif

    /* Check if Uart_Init initialized already or not */
    Uart_Drv_PriParaCheck((FALSE != Uart_PubInitialised),
                           UART_SI_INIT,
                           TT_RET_STATUS_INIT_ERR,
                           &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_Init(TmpPtr);
        Uart_Drv_PriRetCheck(UART_SI_INIT, &Ret);
    }
    else
    {
        /* do nothing */
    }

#if (TT_SAFETY == STD_ON)
    if(TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_InitCheck(TmpPtr);
        Uart_Drv_PriRetCheck(UART_SI_INIT, &Ret);
    }
    else
    {
        /* do nothing */
    }
#endif
    if(TT_RET_SUCCESS == Ret)
    {
        Uart_PubInitialised = TRUE;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name      : Uart_Drv_DeInit
*  Syntax            : TT_RetType Uart_Drv_DeInit(void)
*  Service ID        : 101
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : None
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: De-initialization command accepted
*                      Other: De-initialization command has not been accepted
*  Description       : Service for De-initialization of UART
******************************************************************************/
TT_RetType Uart_Drv_DeInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Check if Uart_Init initialised already or not */
    Uart_Drv_PriParaCheck((Uart_PubInitialised == FALSE),
                            UART_SI_DEINIT,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);

    /* Once condition is true start Uart_DeInit function in HAL layer */
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_DeInit();
        Uart_Drv_PriRetCheck(UART_SI_DEINIT, &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
            Uart_PubInitialised = FALSE;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
    return Ret;
} /* end of Uart_DeInit API */

#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"


#define UART_START_SEC_CODE_FAST
#include "Uart_MemMap.h"
/******************************************************************************
*  Service name      : Uart_Drv_SyncTransmit
*  Syntax            : TT_RetType Uart_Drv_SyncTransmit(TT_CONST Uart_LinuHardType HwUnit,
*                                                       uint8 *TxBuf,
*                                                       uint16 Length)
*  Service ID        : 102
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit - Module ID of the Hardware unit to transmit
*                      TxBuf  - Pointer to the data to be transmitted
*                      Length - Number of bytes to be transmitted. Range: 0 - 65535
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: Synctransmit command accepted
*                      Other: Synctransmit command not accepted
*  Description       : Service for UART SyncTransmit
******************************************************************************/
TT_RetType Uart_Drv_SyncTransmit(TT_CONST Uart_LinuHardType HwUnit,uint8 *TxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Check if Uart_Init initialised already or not */
    Uart_Drv_PriParaCheck((TRUE != Uart_PubInitialised),
                            UART_SI_SYNCTRANSMIT,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_SyncTransmit(HwUnit,TxBuf,Length);
        Uart_Drv_PriRetCheck(UART_SI_SYNCTRANSMIT, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
*  Service name      : Uart_Drv_AsyncTransmit
*  Syntax            : TT_RetType Uart_Drv_AsyncTransmit(TT_CONST Uart_LinuHardType HwUnit,
*                                                        uint8 *TxBuf,
*                                                        uint16 Length)
*  Service ID        : 103
*  Sync/Async        : Asynchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit - Module ID of the Hardware unit to transmit
*                      TxBuf  - Pointer to the data to be transmitted
*                      Length - Number of bytes to be transmitted. Range: 0 - 65535
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: Asynctransmit command accepted
*                      Other: Asynctransmit command not accepted
*  Description       : Service for UART Transmission
******************************************************************************/
TT_RetType Uart_Drv_AsyncTransmit(TT_CONST Uart_LinuHardType HwUnit,uint8 *TxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Check if Uart_Init initialised already or not */
    Uart_Drv_PriParaCheck((TRUE != Uart_PubInitialised),
                            UART_SI_ASYNCTRANSMIT,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_AsyncTransmit(HwUnit, TxBuf, Length);
        Uart_Drv_PriRetCheck(UART_SI_ASYNCTRANSMIT, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
*  Service name      : Uart_Drv_SyncReceive
*  Syntax            : TT_RetType Uart_Drv_SyncReceive(TT_CONST Uart_LinuHardType HwUnit,
*                                                  uint8 *RxBuf,
*                                                  uint16 Length)
*  Service ID        : 104
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit - Module ID of the Hardware unit to transmit
*                      Length - Number of bytes which were read
*
*  Parameters (out)  :  RxBuf  - Buffer to store received data
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: Syncreceive command accepted
*                      Other: Syncreceive command not accepted
*  Description       : Service for UART Reception
******************************************************************************/
TT_RetType Uart_Drv_SyncReceive(TT_CONST Uart_LinuHardType HwUnit,uint8 *RxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Check if Uart_Init initialised already or not */
    Uart_Drv_PriParaCheck((TRUE != Uart_PubInitialised),
                            UART_SI_SYNCRECEIVE,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_SyncReceive(HwUnit, RxBuf, Length);
        Uart_Drv_PriRetCheck(UART_SI_SYNCRECEIVE, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
*  Service name      : Uart_Drv_AsyncReceive
*  Syntax            : TT_RetType Uart_Drv_AsyncReceive(TT_CONST Uart_LinuHardType HwUnit,
*                                                       uint8 *RxBuf,
*                                                       uint16 Length)
*  Service ID        : 105
*  Sync/Async        : Asynchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit - Module ID of the Hardware unit to transmit
*                      Length - Number of bytes which were read
*
*  Parameters (out)  :  RxBuf  - Buffer to store received data
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: Asyncreceive command accepted
*                      Other: Asyncreceive command not accepted
*  Description       : Service for UART Reception
******************************************************************************/
TT_RetType Uart_Drv_AsyncReceive(TT_CONST Uart_LinuHardType HwUnit,uint8 *RxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Check if Uart_Init initialised already or not */
    Uart_Drv_PriParaCheck((TRUE != Uart_PubInitialised),
                            UART_SI_ASYNCRECEIVE,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_AsyncReceive(HwUnit, RxBuf, Length);
        Uart_Drv_PriRetCheck(UART_SI_ASYNCRECEIVE, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
*  Service name      : Uart_Drv_GetStatus
*  Syntax            : TT_RetType Uart_Drv_GetStatus(TT_CONST Uart_LinuHardType HwUnit,
*                                                    Uart_StatusType* UartStatus)
*  Service ID        : 106
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : HwUnit -  Module ID of the Hardware unit to get status
*
*  Parameters (out)  : UartStatus - Get module status
*  Return value      : TT_RET_SUCCESS - Get status command accepted
*                      Other - Get status not accepted
*  Description       : Service to get status of the UART
******************************************************************************/
TT_RetType Uart_Drv_GetStatus(TT_CONST Uart_LinuHardType HwUnit, Uart_StatusType *UartStatus)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    /* Check if Uart_Init initialised already or not */
    Uart_Drv_PriParaCheck((NULL_PTR == UartStatus),
    						UART_SI_GETSTATUS,
							TT_RET_PARAM_NULL_PTR_ERR,
                            &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if (Uart_PubInitialised == TRUE)
        {

            Ret = Uart_Hal_GetStatus(HwUnit, UartStatus);
            Uart_Drv_PriRetCheck(UART_SI_GETSTATUS, &Ret);
        }
        else
        {
            *UartStatus = UART_STATUS_UNINIT;
        }
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

#define UART_STOP_SEC_CODE_FAST
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE_SLOW
#include "Uart_MemMap.h"
/******************************************************************************
*  Service name      : Uart_Drv_GetErrorStatus
*  Syntax            : TT_RetType Uart_Drv_GetErrorStatus(TT_CONST Uart_LinuHardType HwUnit,
*                                                         uint8 *ErrorInfo)
*  Service ID        : 107
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : HwUnit -  Module ID of the Hardware unit to get status
*
*  Parameters (out)  : ErrorInfo - bit encoded as follows
*                      For details about the error, see the information
*                      in the Uart_CallBackEvent enumeration
*  Return value      : TT_RET_SUCCESS - Get error status command accepted
*                      Other - Get error status not accepted
*  Description       : Service to indicate type of error in module operation
******************************************************************************/
TT_RetType Uart_Drv_GetErrorStatus(TT_CONST Uart_LinuHardType HwUnit, uint32 *ErrorInfo)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Uart_StatusType Status = UART_STATUS_UNINIT;
    
    /* Check if Uart_Init initialised already or not */
    Uart_Drv_PriParaCheck((FALSE == Uart_PubInitialised),
                            UART_SI_GETERRORSTATUS,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_GetStatus(HwUnit, &Status);
        if (TT_RET_SUCCESS == Ret)
        {
            if ((UART_STATUS_IDLE == Status) || (UART_STATUS_BUSY == Status))
            {

                Ret = Uart_Hal_GetErrorStatus(HwUnit, ErrorInfo);
            }
            else
            {
                /* do nothing */
            }

        }
        else
        {
            /* do nothing */
        }
        Uart_Drv_PriRetCheck(UART_SI_GETERRORSTATUS, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
*  Service name      : Uart_SetBaudrate
*  Syntax            : TT_RetType Uart_SetBaudrate(TT_CONST Uart_LinuHardType HwUnit,
*                                                  Uart_BaudrateType Baudrate)
*  Service ID        : 108
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : HwUnit -  Module ID of the Hardware unit to get status
*                      Baudrate - Baud rate needs to be set
*  Parameters (out)  : None
*  Return value      : TT_RET_SUCCESS - Set baudrate command accepted.
*                      Other - Set baudrate command not accepted.
*  Description       : This service shall set the baud rate for UART
******************************************************************************/
TT_RetType Uart_Drv_SetBaudrate(TT_CONST Uart_LinuHardType HwUnit, Uart_BaudrateType Baudrate)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Uart_StatusType Status = UART_STATUS_UNINIT;

    /* Check if Uart_Init initialised already or not */
    Uart_Drv_PriParaCheck((Uart_PubInitialised == FALSE),
                            UART_SI_SET_BAUDARTE,
                            TT_RET_STATUS_UNINIT_ERR,
                            &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Uart_Hal_GetStatus(HwUnit, &Status);
        if(TT_RET_SUCCESS == Ret)
        {

            if (UART_STATUS_IDLE == Status)
            {
                /* Set appropriate baudrate to the module */
                Ret = Uart_Hal_SetBaudrate(HwUnit, Baudrate);
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        Uart_Drv_PriRetCheck(UART_SI_SET_BAUDARTE, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"
#if (UART_VERSION_INFO_API == STD_ON)

#define UART_START_SEC_CODE_SLOW
#include "Uart_MemMap.h"
/******************************************************************************
*  Service name      : Uart_Drv_GetVersionInfo
*  Syntax            : TT_RetType Uart_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo)
*  Service ID        : 109
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : VersionInfo: Pointer to where to store the version
*                      information of this module
*  Parameters (out)  : None
*  Return value      : TT_RET_SUCCESS - Set baudrate command accepted.
*                      Other - Set baudrate command not accepted.
*  Description       : Returns the version information of this module.
******************************************************************************/
TT_RetType Uart_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Uart_Drv_PriParaCheck((NULL_PTR == VersionInfo),
                        UART_SI_GET_VERSIONINFO,
                        TT_RET_PARAM_NULL_PTR_ERR,
                        &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        VersionInfo->vendorID         = UART_DRV_VENDOR_ID_H;
        VersionInfo->moduleID         = UART_DRV_MODULE_ID_H;
        VersionInfo->sw_major_version = UART_DRV_SW_MAJOR_VERSION_H;
        VersionInfo->sw_minor_version = UART_DRV_SW_MINOR_VERSION_H;
        VersionInfo->sw_patch_version = UART_DRV_SW_PATCH_VERSION_H;
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}
#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"
#endif

#define UART_START_SEC_CODE_FAST
#include "Uart_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
/**
 * @brief      :  Reporting error status
 * @details    :  Reporting error status
 *
 * @param[in]  :  Expr  - The condition of error occurs
 *                ApiId - Error status code
 *                ErrId - Determine whether an error occurred
 * @param[out] :  RetVal - Current status setting
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
LOCAL_INLINE void Uart_Drv_PriParaCheck(boolean Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{

#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(UART_DRV_TT_STATUS_DEFAULT(ApiId), ErrId);
#if defined(UART_DEV_ERROR_DETECT) && (UART_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(UART_DRV_MODULE_ID_C, ApiId, ErrId);
            ModuleDet_ReportError(UART_DRV_MODULE_ID_C, 0, ApiId, (uint8)ErrId);
#endif
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    (void)RetVal;
    *(RetVal) = ((uint32)(RetVal) > 1) ? 0U: 1U;
#endif


}
/**
 * @brief      :  Reporting error status
 * @details    :  Reporting error status
 *
 * @param[in]  :  ApiId - Error status code
 *                ErrId - Determine whether an error occurred
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
LOCAL_INLINE void Uart_Drv_PriRetCheck(uint8 ApiId, TT_RetType *ErrId)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
#if defined(UART_DEV_ERROR_DETECT) && (UART_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(UART_DRV_MODULE_ID_C, (uint8 )ApiId, *ErrId);
            ModuleDet_ReportError (UART_DRV_MODULE_ID_C, 0,ApiId, (uint8) (*ErrId));
#endif
            *ErrId = TT_SET_STATUS_TYPE(UART_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)ApiId;
    (void)ErrId;
#endif
}

#define UART_STOP_SEC_CODE_FAST
#include "Uart_MemMap.h"


#ifdef __cplusplus
}
#endif

