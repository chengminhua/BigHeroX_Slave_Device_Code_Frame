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
**  FILENAME     : Uart_Hal.c                                                       **
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
#include "Uart_Hal.h"
#include "Linu_Hw.h"
#include "Uart_Hw.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define UART_HAL_VENDOR_ID_C                     1541
#define UART_HAL_MODULE_ID_C                     227
#define UART_HAL_AR_RELEASE_MAJOR_VERSION_C      4
#define UART_HAL_AR_RELEASE_MINOR_VERSION_C      4
#define UART_HAL_AR_RELEASE_PATCH_VERSION_C      0
#define UART_HAL_SW_MAJOR_VERSION_C              1
#define UART_HAL_SW_MINOR_VERSION_C              1
#define UART_HAL_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Uart_Hal.c and Uart_Hal.h file version check */
#if (UART_HAL_VENDOR_ID_C != UART_HAL_VENDOR_ID_H)
    #error "Uart_Hal.c and Uart_Hal.h have different vendor ids"
#endif
#if (UART_HAL_MODULE_ID_C != UART_HAL_MODULE_ID_H)
    #error "Uart_Hal.c and Uart_Hal.h have different module ids"
#endif
#if ((UART_HAL_AR_RELEASE_MAJOR_VERSION_C != UART_HAL_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HAL_AR_RELEASE_MINOR_VERSION_C != UART_HAL_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HAL_AR_RELEASE_PATCH_VERSION_C != UART_HAL_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hal.c and Uart_Hal.h are different"
#endif
#if ((UART_HAL_SW_MAJOR_VERSION_C != UART_HAL_SW_MAJOR_VERSION_H) || \
     (UART_HAL_SW_MINOR_VERSION_C != UART_HAL_SW_MINOR_VERSION_H) || \
     (UART_HAL_SW_PATCH_VERSION_C != UART_HAL_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hal.c and Uart_Hal.h are different"
#endif

/* Uart_Hal.c and Uart_Hw.h file version check */
#if (UART_HAL_VENDOR_ID_C != UART_HW_VENDOR_ID_H)
    #error "Uart_Hal.c and Uart_Hw.h have different vendor ids"
#endif
#if (UART_HAL_MODULE_ID_C != UART_HW_MODULE_ID_H)
    #error "Uart_Hal.c and Uart_Hw.h have different module ids"
#endif
#if ((UART_HAL_AR_RELEASE_MAJOR_VERSION_C != UART_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HAL_AR_RELEASE_MINOR_VERSION_C != UART_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HAL_AR_RELEASE_PATCH_VERSION_C != UART_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hal.c and Uart_Hw.h are different"
#endif
#if ((UART_HAL_SW_MAJOR_VERSION_C != UART_HW_SW_MAJOR_VERSION_H) || \
     (UART_HAL_SW_MINOR_VERSION_C != UART_HW_SW_MINOR_VERSION_H) || \
     (UART_HAL_SW_PATCH_VERSION_C != UART_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hal.c and Uart_Hw.h are different"
#endif

#if (LIN_UART_ENABLE == STD_ON)
/* Uart_Hal.c and Linu_Hw.h file version check */
#if (UART_HAL_VENDOR_ID_C != LINU_HW_VENDOR_ID_H)
    #error "Uart_Hal.c and Linu_Hw.h have different vendor ids"
#endif
#if (UART_HAL_MODULE_ID_C != LINU_HW_MODULE_ID_H)
    #error "Uart_Hal.c and Linu_Hw.h have different module ids"
#endif
#if ((UART_HAL_AR_RELEASE_MAJOR_VERSION_C != LINU_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HAL_AR_RELEASE_MINOR_VERSION_C != LINU_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HAL_AR_RELEASE_PATCH_VERSION_C != LINU_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hal.c and Linu_Hw.h are different"
#endif
#if ((UART_HAL_SW_MAJOR_VERSION_C != LINU_HW_SW_MAJOR_VERSION_H) || \
     (UART_HAL_SW_MINOR_VERSION_C != LINU_HW_SW_MINOR_VERSION_H) || \
     (UART_HAL_SW_PATCH_VERSION_C != LINU_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hal.c and Linu_Hw.h are different"
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

/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/
/******************************************************************************
*                         Public Functions                                    *
******************************************************************************/
#define UART_START_SEC_CODE_SLOW
#include "Uart_MemMap.h"
/**
 * @brief      :  Service for initialization of UART
 * @details    :  Select serial uart initialization mode
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: The initialization is complete
 *             :  Other: Initialization is not complete
 *
 **/
TT_RetType Uart_Hal_Init(TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

	Ret = Uart_Hw_Init(CfgPtr);
	if(TT_RET_SUCCESS ==Ret )
	{
		#if (LIN_UART_ENABLE == STD_ON)
			Ret = Linu_Hw_Init(CfgPtr);
		#endif
	}
	else
	{
		/* do nothing */
	}

    return Ret;
}

#if (TT_SAFETY == STD_ON)
/**
 * @brief      :  Serves initial security checks
 * @details    :  Serves initial security checks
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Initialize register Settings successfully
 *             :  Other: There is a problem with the initialization register setting
 *
 **/
TT_RetType Uart_Hal_InitCheck(TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == CfgPtr), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if(TT_RET_SUCCESS ==Ret )
    {
        Ret = Uart_Hw_InitCheck(CfgPtr);
        if(TT_RET_SUCCESS ==Ret )
        {
            #if (LIN_UART_ENABLE == STD_ON)
                Ret = Linu_Hw_InitCheck(CfgPtr);
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
    return Ret;
}
#endif

/**
 * @brief      :  Service for Deinitialization of UART
 * @details    :  Select serial uart De-initialization mode
 *
 * @param[in]  :  None
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: De-initialization command accepted
 *             :  Other: De-initialization command has not been accepted
 *
 **/
TT_RetType Uart_Hal_DeInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Uart_Hw_DeInit();

    if(Ret == TT_RET_SUCCESS)
    {
        #if (LIN_UART_ENABLE == STD_ON)
            Ret = Linu_Hw_DeInit();
        #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE_FAST
#include "Uart_MemMap.h"
/**
 * @brief      :  Service for UART SyncTransmission
 * @details    :  Service for UART SyncTransmission
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  Other: Transmit command not accepted
 *
 **/
TT_RetType Uart_Hal_SyncTransmit(TT_CONST Uart_LinuHardType HwUnit,uint8 *TxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (LIN_UART_ENABLE == STD_ON)
    uint8 HwUnit_Flag = 0;
#endif

     if(HwUnit < LINU_0)
     {
       Ret = Uart_Hw_SyncTransmit((uint8)HwUnit, TxBuf, Length);
     }
     else
     {
#if (LIN_UART_ENABLE == STD_ON)
            HwUnit_Flag = (uint8)HwUnit - (uint8)LINU_0;
            Ret = Linu_Hw_SyncTransmit(HwUnit_Flag,TxBuf,Length);
#endif
     }

    return Ret;
}

/**
 * @brief      :  Service for UART AsyncTransmission
 * @details    :  Service for UART AsyncTransmission
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  Other: Transmit command not accepted
 *
 **/
TT_RetType Uart_Hal_AsyncTransmit(TT_CONST Uart_LinuHardType HwUnit,uint8 *TxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (LIN_UART_ENABLE == STD_ON)
    uint8 HwUnit_Flag = 0;
#endif

    if(HwUnit < LINU_0)
    {
      Ret = Uart_Hw_AsyncTransmit((uint8)HwUnit, TxBuf, Length);
    }
    else
    {
#if (LIN_UART_ENABLE == STD_ON)
        HwUnit_Flag = (uint8)HwUnit - (uint8)LINU_0;
        Ret = Linu_Hw_AsyncTransmit(HwUnit_Flag,TxBuf,Length);
#endif
    }

    return Ret;
}
/**
 * @brief      :  Service for UART SyncReceive
 * @details    :  Service for UART SyncReceive
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  Other: Receive command not accepted
 *
 **/
TT_RetType Uart_Hal_SyncReceive(TT_CONST Uart_LinuHardType HwUnit,uint8 *RxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (LIN_UART_ENABLE == STD_ON)
    uint8 HwUnit_Flag = 0;
#endif
    if(HwUnit < LINU_0)
    {
        Ret = Uart_Hw_SyncReceive((uint8)HwUnit, RxBuf, Length);
    }
    else
    {
#if (LIN_UART_ENABLE == STD_ON)
        HwUnit_Flag = (uint8)HwUnit - (uint8)LINU_0;
        Ret = Linu_Hw_SyncReceive(HwUnit_Flag, RxBuf, Length);
#endif
    }

    return Ret;
}

/**
 * @brief      :  Service for UART AsyncReceive
 * @details    :  Service for UART AsyncReceive
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  Other: Receive command not accepted
 *
 **/
TT_RetType Uart_Hal_AsyncReceive(TT_CONST Uart_LinuHardType HwUnit,uint8 *RxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (LIN_UART_ENABLE == STD_ON)
    uint8 HwUnit_Flag = 0;
#endif
    if(HwUnit < LINU_0)
    {
        Ret = Uart_Hw_AsyncReceive((uint8)HwUnit, RxBuf, Length);
    }
    else
    {
#if (LIN_UART_ENABLE == STD_ON)
        HwUnit_Flag = (uint8)HwUnit - (uint8)LINU_0;
        Ret = Linu_Hw_AsyncReceive(HwUnit_Flag, RxBuf, Length);
#endif
    }

    return Ret;
}
/**
 * @brief      :  Service to get status of the UART
 * @details    :  Service to get status of the UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  UartStatus  - The current status of the uart is
 *                             uninitialized, idle and Busy.
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get status command accepted
 *             :  Other: Get status not accepted
 *
 **/
TT_RetType Uart_Hal_GetStatus(TT_CONST Uart_LinuHardType HwUnit, Uart_StatusType *UartStatus)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (LIN_UART_ENABLE == STD_ON)
    uint8 HwUnit_Flag = 0;
#endif

    if(HwUnit < LINU_0)
    {
        Ret = Uart_Hw_GetStatus((uint8)HwUnit, UartStatus);
    }
    else
    {
#if (LIN_UART_ENABLE == STD_ON)
        HwUnit_Flag = (uint8)HwUnit - (uint8)LINU_0;
        Ret = Linu_Hw_GetStatus(HwUnit_Flag,UartStatus);
#endif
    }

    return Ret;
}

#define UART_STOP_SEC_CODE_FAST
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE
#include "Uart_MemMap.h"
/**
 * @brief      :  Service to indicate type of error in module operation
 * @details    :  Service to indicate type of error in module operation
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  ErrorInfo  - The current Error information of the uart is
 *                             uninitialized, idle and Busy.
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get Error information command accepted
 *             :  Other: Get Error information command not accepted
 *
 **/
TT_RetType Uart_Hal_GetErrorStatus(TT_CONST Uart_LinuHardType HwUnit, uint32 *ErrorInfo)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    #if (LIN_UART_ENABLE == STD_ON)
        uint8 HwUnit_Flag = 0;
    #endif

    if(HwUnit < LINU_0)
    {
        Ret = Uart_Hw_GetErrorStatus((uint8)HwUnit, ErrorInfo);
    }
    else
    {
#if (LIN_UART_ENABLE == STD_ON)
        HwUnit_Flag = (uint8)HwUnit - (uint8)LINU_0;
        Ret = Linu_Hw_GetErrorStatus(HwUnit_Flag, ErrorInfo);
#endif
    }

    return Ret;
}

/**
 * @brief      :  This service shall set the baud rate for UART
 * @details    :  This service shall set the baud rate for UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Baudrate - Set baud rate
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set Baudrate command accepted
 *             :  Other: Set Baudrate command not accepted
 *
 **/
TT_RetType Uart_Hal_SetBaudrate(TT_CONST Uart_LinuHardType HwUnit, Uart_BaudrateType Baudrate)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (LIN_UART_ENABLE == STD_ON)
    uint8 HwUnit_Flag = 0;
#endif

    if(HwUnit < LINU_0)
    {
        Ret = Uart_Hw_SetBaudrate((uint8)HwUnit, Baudrate);
    }
    else
    {
#if (LIN_UART_ENABLE == STD_ON)
        HwUnit_Flag = (uint8)HwUnit - (uint8)LINU_0;
        Ret = Linu_Hw_SetBaudrate(HwUnit_Flag,Baudrate);
#endif
    }

    return Ret;
}
#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

