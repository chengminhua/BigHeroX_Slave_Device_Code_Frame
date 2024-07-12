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
**  FILENAME     : I2c_Drv.c                                                        **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : I2C Driver Source File                                           **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                     **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                           History                                                 **
*[V1.1.0]:                                                                          **
*************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "I2c_Drv.h"
#include "I2c_Hw.h"

#ifdef USING_OS_AUTOSAROS
#include "SchM_I2c.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define I2C_DRV_VENDOR_ID_C                      1541
#define I2C_DRV_MODULE_ID_C                      222
#define I2C_DRV_AR_RELEASE_MAJOR_VERSION_C       4
#define I2C_DRV_AR_RELEASE_MINOR_VERSION_C       4
#define I2C_DRV_AR_RELEASE_PATCH_VERSION_C       0
#define I2C_DRV_SW_MAJOR_VERSION_C               1
#define I2C_DRV_SW_MINOR_VERSION_C               1
#define I2C_DRV_SW_PATCH_VERSION_C               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* I2c_Drv.h I2c_Drv.c file version check */
#if (I2C_DRV_VENDOR_ID_C != I2C_DRV_VENDOR_ID_H)
    #error "I2c_Drv.h and I2c_Drv.c have different vendor ids"
#endif

#if (I2C_DRV_MODULE_ID_C != I2C_DRV_MODULE_ID_H)
    #error "I2c_Drv.h and I2c_Drv.c have different module ids"
#endif

#if ((I2C_DRV_AR_RELEASE_MAJOR_VERSION_C != I2C_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (I2C_DRV_AR_RELEASE_MINOR_VERSION_C != I2C_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (I2C_DRV_AR_RELEASE_PATCH_VERSION_C != I2C_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of I2c_Drv.h and I2c_Drv.c are different"
#endif

#if ((I2C_DRV_SW_MAJOR_VERSION_C != I2C_DRV_SW_MAJOR_VERSION_H) || \
     (I2C_DRV_SW_MINOR_VERSION_C != I2C_DRV_SW_MINOR_VERSION_H) || \
     (I2C_DRV_SW_PATCH_VERSION_C != I2C_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of I2c_Drv.h and I2c_Drv.c are different"
#endif

/* I2c_Hw.h I2c_Drv.c file version check */
#if (I2C_DRV_VENDOR_ID_C != I2C_HW_VENDOR_ID_H)
    #error "I2c_Hw.h and I2c_Drv.c have different vendor ids"
#endif

#if (I2C_DRV_MODULE_ID_C != I2C_HW_MODULE_ID_H)
    #error "I2c_Hw.h and I2c_Drv.c have different module ids"
#endif

#if ((I2C_DRV_AR_RELEASE_MAJOR_VERSION_C != I2C_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (I2C_DRV_AR_RELEASE_MINOR_VERSION_C != I2C_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (I2C_DRV_AR_RELEASE_PATCH_VERSION_C != I2C_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of I2c_Hw.h and I2c_Drv.c are different"
#endif

#if ((I2C_DRV_SW_MAJOR_VERSION_C != I2C_HW_SW_MAJOR_VERSION_H) || \
     (I2C_DRV_SW_MINOR_VERSION_C != I2C_HW_SW_MINOR_VERSION_H) || \
     (I2C_DRV_SW_PATCH_VERSION_C != I2C_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of I2c_Hw.h and I2c_Drv.c are different"
#endif

/******************************************************************************
 *                            Private Macros
 *******************************************************************************/
#define I2C_DRV_TT_STATUS_DEFAULT(ApiID)       (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET)       | \
                                                        ((ApiID) << TT_APIID_OFFSET) | \
                                                        (I2C_DRV_MODULE_ID_C << TT_MODULEID_OFFSET))

/******************************************************************************
*                       Private Variable
******************************************************************************/
#define I2C_START_SEC_VAR_FAST_CLEARED_BOOLEAN
#include "I2c_MemMap.h"
/* Initially made I2c UNINIT,once I2c_Init calls it becomes TRUE */
static boolean I2c_PubInitialised = FALSE;

#define I2C_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
#include "I2c_MemMap.h"

/******************************************************************************
*                    Private Function Declaration
******************************************************************************/
/**
 * @brief      :  Reporting error status
 * @details    :  Reporting error status
 * @param[in]  :  Expr  - The condition of error occurs
 *                ApiId - Error status code
 *                ErrId - Determine whether an error occurred
 * @param[out] :  RetVal - Current status setting
 * @return     :  void
 * @retval     :  None
 *
 **/
LOCAL_INLINE void I2c_Drv_PriParaCheck(bool Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal);

/**
 * @brief      :  Reporting error status
 * @details    :  Reporting error status
 * @param[in]  :  ApiId - Error status code
 *                ErrId - Determine whether an error occurred
 * @param[out] :  None
 * @return     :  void
 * @retval     :  None
 *
 **/
LOCAL_INLINE void I2c_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId);

/******************************************************************************
*                         Public Functions                                    *
******************************************************************************/
#define I2C_START_SEC_CODE_SLOW
#include "I2c_MemMap.h"
/******************************************************************************
*  Service name      : I2c_Drv_Init
*  Syntax            : TT_RetType I2c_Drv_Init(TT_CONST I2c_Hw_ConfigType* CfgPtr)
*  Service ID[hex]   : 100
*  Sync/Async        : Synchronous
*  Reentrancy        : Non reentrant
*  Parameters (in)   : CfgPtr - Pointer to configtype structure
*  Parameters (out)  : None
*  Return value      : TT_RetType
*                      TT_RET_SUCCESS: The initialization is complete
*                    : Other: Initialization is not complete
*  Description       : Service for initialization of I2c
******************************************************************************/
TT_RetType I2c_Drv_Init(TT_CONST I2c_ConfigType *CfgPtr)
{
  TT_RetType Ret = TT_RET_SUCCESS;
  TT_CONST I2c_ConfigType *TmpPtr = NULL_PTR;

#ifdef I2C_PRECOMPILE_SUPPORT
  I2c_Drv_PriParaCheck((NULL_PTR != CfgPtr),
                         I2C_SI_INIT,
                         TT_RET_PARAM_INVALID_PTR_ERR,
                         &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        TmpPtr = ( TT_CONST I2c_ConfigType *)&I2C_CfgData;
    }
    else
    {
        /* do nothing */
    }
#else
  I2c_Drv_PriParaCheck((NULL_PTR == CfgPtr),
                           I2C_SI_INIT,
                           TT_RET_PARAM_NULL_PTR_ERR,
                           &Ret);
  if (TT_RET_SUCCESS == Ret)
    {
        TmpPtr = CfgPtr;
    }
    else
    {
        /* do nothing */
    }
#endif
    /* Check if I2c_Init initialized already or not */
    I2c_Drv_PriParaCheck((FALSE != I2c_PubInitialised),
                        I2C_SI_INIT,
                        TT_RET_STATUS_UNINIT_ERR,
                        &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = I2c_Hw_Init(TmpPtr);
        I2c_Drv_PriRetCheck(I2C_SI_INIT,&Ret);
    }
    else
    {
        /* do nothing */
    }

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    if(TT_RET_SUCCESS == Ret)
    {
        Ret = I2c_Hw_InitCheck(TmpPtr);
        I2c_Drv_PriRetCheck(I2C_SI_INIT,&Ret);
    }
    else
    {
        /* do nothing */
    }
#endif


    if(TT_RET_SUCCESS == Ret)
    {
        I2c_PubInitialised = TRUE;
    }
    else
    {
        /* do nothing */
    }

  return Ret;
} /* end of I2c_Init API */

/******************************************************************************
*  Service name    : I2c_Drv_DeInit
*  Syntax          : TT_RetType I2c_Drv_DeInit(void)
*  Service ID      : 101
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameter (in)  : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS - De-initialization command accepted
*                    Other - De-initialization command has not been accepted
*  Description     : Service for De-initialization of I2C
******************************************************************************/
TT_RetType I2c_Drv_DeInit(void)
{
   TT_RetType Ret = TT_RET_SUCCESS;

    /* Check if I2c_Init initialised already or not */
    I2c_Drv_PriParaCheck((TRUE != I2c_PubInitialised),
                          I2C_SI_DEINIT,
                          TT_RET_STATUS_UNINIT_ERR,
                          &Ret);
    /* Once condition is true start I2c_DeInit function in Hw layer */
    if(TT_RET_SUCCESS == Ret)
    {
        Ret = I2c_Hw_DeInit();
        I2c_Drv_PriRetCheck(TT_RET_STATUS_UNINIT_ERR,&Ret);

      if(TT_RET_SUCCESS == Ret)
      {
          I2c_PubInitialised = FALSE;
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

}

#define I2C_STOP_SEC_CODE_SLOW
#include "I2c_MemMap.h"

#define I2C_START_SEC_CODE_FAST
#include "I2c_MemMap.h"
/******************************************************************************
*  Service name       : I2c_Drv_SyncTransmit
*  Syntax             : TT_RetType I2c_Drv_SyncTransmit(TT_CONST uint8 HwUnit,
*                                                       TT_CONST uint8 *TxBuf,
*                                                       uint16 Length)
*  Service ID         : 102
*  Sync/Async         : Synchronous
*  Reentrancy         : Non reentrant
*  Parameter (in)     : HwUnit - Select an I2C module
*                       TxBuf  - Pointer to the data to be transmitted
*                       Length - Number of bytes to be transmitted. Range: 0 - 65535
*  Parameters (out)   : None
*  Return value       : TT_RET_SUCCESS - Transmit command accepted
*                       Other - Transmit command not accepted
*  Description        : Service for I2c Transmission
*******************************************************************************************/
TT_RetType I2c_Drv_SyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf , uint16 Length)
{
    TT_RetType  Ret = TT_RET_SUCCESS;
    I2c_StatusType Status = TT_I2C_STATE_IDLE;

    /* Check if I2c_Init initialised already or not */
    I2c_Drv_PriParaCheck((TRUE != I2c_PubInitialised),
                        I2C_SI_SYNCTRANSMIT,
                        TT_RET_STATUS_UNINIT_ERR,
                        &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = I2c_Hw_GetStatus(HwUnit,&Status);
        if ((TT_RET_SUCCESS == Ret) && (TT_I2C_STATE_IDLE == Status))
        {
          Ret = I2c_Hw_SyncTransmit(HwUnit,TxBuf,Length);
        }
        else
        {
            /* do nothing */
        }
        I2c_Drv_PriRetCheck(TT_RET_STATUS_TRANSITION_ERR,&Ret);
    }
  return Ret;
}
/******************************************************************************
*  Service name       : I2c_Drv_AsyncTransmit
*  Syntax             : TT_RetType I2c_Drv_AsyncTransmit(TT_CONST uint8 HwUnit,
*                                                       TT_CONST uint8 *TxBuf,
*                                                       uint16 Length)
*  Service ID         : 103
*  Sync/Async          : Asynchronous
*  Reentrancy         : Non reentrant
*  Parameter (in)     : HwUnit - Select an I2C module
*                       TxBuf  - Pointer to the data to be transmitted
*                       Length - Number of bytes to be transmitted. Range: 0 - 65535
*  Parameters (out)   : None
*  Return value       : TT_RET_SUCCESS - Transmit command accepted
*                       Other - Transmit command not accepted
*  Description        : Service for I2c Transmission
*******************************************************************************************/
TT_RetType I2c_Drv_AsyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf , uint16 Length)
{
  TT_RetType  Ret = TT_RET_SUCCESS;
  I2c_StatusType Status = TT_I2C_STATE_IDLE;

    /* Check if I2c_Init initialised already or not */
    I2c_Drv_PriParaCheck((TRUE != I2c_PubInitialised),
                        I2C_SI_ASYNCTRANSMIT,
                        TT_RET_STATUS_UNINIT_ERR,
                        &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = I2c_Hw_GetStatus(HwUnit,&Status);
        if ((TT_RET_SUCCESS == Ret) && (TT_I2C_STATE_IDLE == Status))
        {
          Ret = I2c_Hw_AsyncTransmit(HwUnit,TxBuf, Length);
        }
        else
        {
            /* do nothing */
        }
        I2c_Drv_PriRetCheck(TT_RET_STATUS_TRANSITION_ERR,&Ret);

    }

    return Ret;

}

/******************************************************************************
*  Service name       : I2c_Drv_AsyncReceive
*  Syntax             : TT_RetType I2c_Drv_AsyncReceive(TT_CONST uint8 HwUnit,
*                                                       uint8 *RxBuf,
*                                                       uint16 *Length)
*  Service ID         : 104
*  Sync/Async          : Asynchronous
*  Reentrancy         : Non reentrant
*  Parameter (in)     : HwUnit - Select an I2C module
*                       Length - Number of bytes which will be read
*  Parameters (out)   : RxBuf  - Buffer to store received data
*  Return value       : TT_RET_SUCCESS - Receive command accepted
*                       Other - Receive command not accepted
*  Description        : Service for I2C Reception
*******************************************************************************************/
TT_RetType I2c_Drv_AsyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length)
{
  TT_RetType  Ret = TT_RET_SUCCESS;
  I2c_StatusType Status = TT_I2C_STATE_IDLE;

    /* Check if I2c_Init initialised already or not */
    I2c_Drv_PriParaCheck((TRUE != I2c_PubInitialised),
                        I2C_SI_ASYNCRECEIVE,
                        TT_RET_STATUS_UNINIT_ERR,
                        &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
      Ret = I2c_Hw_GetStatus(HwUnit,&Status);
        if ((TT_RET_SUCCESS == Ret) && (TT_I2C_STATE_IDLE == Status))
        {
            Ret = I2c_Hw_AsyncReceive(HwUnit,RxBuf,Length);
        }
        else
        {
            /* do nothing */
        }
        I2c_Drv_PriRetCheck(TT_RET_STATUS_ERR,&Ret);
  }

    return Ret;

}

/******************************************************************************
*  Service name       : I2c_Drv_SyncReceive
*  Syntax             : TT_RetType I2c_Drv_SyncReceive(TT_CONST uint8 HwUnit,
*                                                      uint8 *RxBuf,
*                                                      uint16 *Length)
*  Service ID         : 105
*  Sync/Async         : Synchronous
*  Reentrancy         : Non reentrant
*  Parameter (in)     : HwUnit - Select an I2C module
*                       Length - Number of bytes which will be read
*  Parameters (out)   : RxBuf  - Buffer to store received data
*  Return value       : TT_RET_SUCCESS - Receive command accepted
*                       Other - Receive command not accepted
*  Description        : Service for I2C Reception
*******************************************************************************************/
TT_RetType I2c_Drv_SyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length)
{
    TT_RetType  Ret = TT_RET_SUCCESS;
    I2c_StatusType Status = TT_I2C_STATE_IDLE;

    /* Check if I2c_Init initialised already or not */
    I2c_Drv_PriParaCheck((TRUE != I2c_PubInitialised),
                        I2C_SI_SYNCRECEIVE,
                        TT_RET_STATUS_UNINIT_ERR,
                        &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = I2c_Hw_GetStatus(HwUnit,&Status);
        if ((TT_RET_SUCCESS == Ret) && (TT_I2C_STATE_IDLE == Status))
        {
            Ret = I2c_Hw_SyncReceive(HwUnit,RxBuf,Length);
        }
        else
        {
            /* do nothing */
        }
        I2c_Drv_PriRetCheck(TT_RET_STATUS_ERR,&Ret);
    }

    return Ret;

}

#define I2C_STOP_SEC_CODE_FAST
#include "I2c_MemMap.h"

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/******************************************************************************
*  Service name     : I2c_Drv_GetStatus
*  Syntax           : TT_RetType I2c_Drv_GetStatus(TT_CONST uint8 HwUnit,
*                                                  I2c_StatusType* I2cStatus)
*  Service ID       : 106
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : HwUnit - Select an I2C module
*  Parameters (out) : I2cStatus - Gets the status of I2c
*  Return value     : TT_RetType
*                     TT_RET_SUCCESS - Get status command accepted
*                     Other - Get status command not accepted
*  Description      : The service gets the status of the I2c.
******************************************************************************/
TT_RetType I2c_Drv_GetStatus(TT_CONST uint8 HwUnit,I2c_StatusType* I2cStatus)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /*Check whether HwUnit is reasonable */
    I2c_Drv_PriParaCheck(((uint8)I2C_CONTROLLER_COUNT <= HwUnit),
                         I2C_SI_GETSTATUS,
                        TT_RET_PARAM_INVALID_DATA_ERR,
                        &Ret);

    I2c_Drv_PriParaCheck((I2cStatus == NULL_PTR),
                         I2C_SI_GETSTATUS,
                          TT_RET_PARAM_NULL_PTR_ERR,
                          &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if (I2c_PubInitialised == TRUE)
        {
            Ret = I2c_Hw_GetStatus(HwUnit,I2cStatus);
        }
        else
        {
            *I2cStatus = TT_I2C_STATE_UNINIT;
        }
        I2c_Drv_PriRetCheck(TT_RET_STATUS_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
*  Service name     : I2c_Drv_SetTargetAdderss
*  Syntax           : TT_RetType I2c_Hw_SetMasteradder(TT_CONST uint8 HwUnit,
*                                                      uint16 Adder)
*  Service ID       : 107
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : HwUnit - Select an I2C module
*                     Adder - Set address The correct address is there:
*                     [0x9,0xb]、[0xd,0x60][0x62,0x77]、[0x7d,0x7F]
*  Parameters (out) : I2cStatus - Gets the status of I2c
*  Return value     : TT_RetType
*                     TT_RET_SUCCESS - Set adder command accepted
*                     Other - Set adder command not accepted
*  Description      : The service set adder of the I2c.
******************************************************************************/
TT_RetType I2c_Drv_SetTargetAdderss(TT_CONST uint8 HwUnit, uint16 Adder)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Check if I2c_Init initialised already or not */
    I2c_Drv_PriParaCheck((TRUE != I2c_PubInitialised),
                         I2C_SI_SETTARGETADDERSS,
                         TT_RET_STATUS_UNINIT_ERR,
                         &Ret);

    /*Check whether HwUnit is reasonable */
    I2c_Drv_PriParaCheck(((uint8)I2C_CONTROLLER_COUNT <= HwUnit),
                         I2C_SI_SETTARGETADDERSS,
                         TT_RET_PARAM_INVALID_DATA_ERR,
                         &Ret);
    I2c_Drv_PriParaCheck(((I2C_HW_ADDER_MAX < Adder)||
                         ((HIGH_SPEED_MASTER_CODE_MIN <= Adder)&& (SMBUS_HOST >= Adder))||
                         ((RESERVED_ADDERSS_MIN <= Adder)&& (RESERVED_ADDERSS_MAX >= Adder))||
                         (Adder == SMBUS_ALERT_RESPONSE_ADDERSS)||
                         (SMBUS_DEVICE_DEFAULT_ADDERSS == Adder)),
                         I2C_SI_SETTARGETADDERSS,
                         TT_RET_PARAM_ADDR_ERR,
                         &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = I2c_Hw_SetTargetAdderss(HwUnit,Adder);
        I2c_Drv_PriRetCheck(TT_RET_STATUS_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#if (I2C_VERSION_INFO_API == STD_ON)
#define I2C_START_SEC_CODE_SLOW
#include "I2c_MemMap.h"
/******************************************************************************
*  Service name     : I2c_GetVersionInfo
*  Syntax           : void I2c_GetVersionInfo(Std_VersionInfoType* VersionInfo)
*  Service ID       : 109
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : None
*  Parameters (out) : VersionInfo: Pointer to where to store the version
*                     information of this module
*  Return value     : TT_RetType
*                     TT_RET_SUCCESS - Get version information command accepted
*                     Other - Get version information command not accepted
*  Description      : Returns the version information of this module.
******************************************************************************/
TT_RetType I2c_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    I2c_Drv_PriParaCheck((NULL_PTR == VersionInfo),
                        I2C_SI_GETVERSIONINFO,
                        TT_RET_PARAM_NULL_PTR_ERR,
                        &Ret);

    if (E_OK == Ret)
    {
        VersionInfo->vendorID         = I2C_DRV_VENDOR_ID_C;
        VersionInfo->moduleID         = I2C_DRV_MODULE_ID_C;
        VersionInfo->sw_major_version = I2C_DRV_SW_MAJOR_VERSION_C;
        VersionInfo->sw_minor_version = I2C_DRV_SW_MINOR_VERSION_C;
        VersionInfo->sw_patch_version = I2C_DRV_SW_PATCH_VERSION_C;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#define I2C_STOP_SEC_CODE_SLOW
#include "I2c_MemMap.h"
#endif
/******************************************************************************
*                            Private Functions
******************************************************************************/
#define I2C_START_SEC_CODE_FAST
#include "I2c_MemMap.h"
/**
 * @brief      :  Reporting error status
 * @details    :  Reporting error status
 * @param[in]  :  Expr  - The condition of error occurs
 *                ApiId - Error status code
 *                ErrId - Determine whether an error occurred
 * @param[out] :  RetVal - Current status setting
 * @return     :  void
 * @retval     :  None
 *
 **/
LOCAL_INLINE void I2c_Drv_PriParaCheck(bool Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(I2C_DRV_TT_STATUS_DEFAULT(ApiId), ErrId);
#if defined(I2C_DEV_ERROR_DETECT) && (I2C_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(I2C_DRV_MODULE_ID_C, ApiId, ErrId);
            ModuleDet_ReportError(I2C_DRV_MODULE_ID_C, 0, ApiId, (uint8)ErrId);
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
 * @param[in]  :  ApiId - Error status code
 *                ErrId - Determine whether an error occurred
 * @param[out] :  None
 * @return     :  void
 * @retval     :  None
 *
 **/
LOCAL_INLINE void I2c_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
#if defined(I2C_DEV_ERROR_DETECT) && (I2C_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(I2C_DRV_MODULE_ID_C, (uint8 )ApiId, *ErrId);
            ModuleDet_ReportError (I2C_DRV_MODULE_ID_C, 0, (uint8) ApiId, (uint8) (*ErrId));
#endif
            *ErrId = TT_SET_STATUS_TYPE(I2C_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
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

#define I2C_STOP_SEC_CODE_FAST
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif
