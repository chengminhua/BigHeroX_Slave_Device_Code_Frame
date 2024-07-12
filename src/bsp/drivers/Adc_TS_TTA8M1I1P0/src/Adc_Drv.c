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
**  FILENAME     : Adc_Drv.c                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Adc_Drv.h"
#include "Adc_Hw.h"
#ifndef USING_OS_AUTOSAROS
#if ((TT_SAFETY) && (TT_SAFETY == STD_ON))
#include "Base_Tools.h"
#endif
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define ADC_DRV_VENDOR_ID_C                             1541
#define ADC_DRV_MODULE_ID_C                             123
#define ADC_DRV_INSTANCE_ID_C                           0
#define ADC_DRV_AR_RELEASE_MAJOR_VERSION_C              4
#define ADC_DRV_AR_RELEASE_MINOR_VERSION_C              4
#define ADC_DRV_AR_RELEASE_PATCH_VERSION_C              0
#define ADC_DRV_SW_MAJOR_VERSION_C                      1
#define ADC_DRV_SW_MINOR_VERSION_C                      1
#define ADC_DRV_SW_PATCH_VERSION_C                      0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Adc_Drv.c Adc_Drv.h file version check */
#if (ADC_DRV_VENDOR_ID_C != ADC_DRV_VENDOR_ID_H)
    #error "Adc_Drv.c and Adc_Drv.h have different vendor ids"
#endif

#if (ADC_DRV_MODULE_ID_C != ADC_DRV_MODULE_ID_H)
    #error "Adc_Drv.c and Adc_Drv.h have different module ids"
#endif

#if (ADC_DRV_INSTANCE_ID_C != ADC_DRV_INSTANCE_ID_H)
    #error "Adc_Drv.c and Adc_Drv.h have different Instance ids"
#endif

#if ((ADC_DRV_AR_RELEASE_MAJOR_VERSION_C != ADC_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_DRV_AR_RELEASE_MINOR_VERSION_C != ADC_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_DRV_AR_RELEASE_PATCH_VERSION_C != ADC_DRV_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Drv.c and Adc_Drv.h are different"
#endif

#if ((ADC_DRV_SW_MAJOR_VERSION_C != ADC_DRV_SW_MAJOR_VERSION_H) || \
     (ADC_DRV_SW_MINOR_VERSION_C != ADC_DRV_SW_MINOR_VERSION_H) || \
     (ADC_DRV_SW_PATCH_VERSION_C != ADC_DRV_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Drv.c and Adc_Drv.h are different"
#endif

/* Adc_Drv.c Adc_Hw.h file version check */
#if (ADC_DRV_VENDOR_ID_C != ADC_HW_VENDOR_ID_H)
    #error "Adc_Drv.c and Adc_Hw.h have different vendor ids"
#endif

#if (ADC_DRV_MODULE_ID_C != ADC_HW_MODULE_ID_H)
    #error "Adc_Drv.c and Adc_Hw.h have different module ids"
#endif

#if (ADC_DRV_INSTANCE_ID_C != ADC_HW_INSTANCE_ID_H)
    #error "Adc_Drv.c and Adc_Hw.h have different Instance ids"
#endif

#if ((ADC_DRV_AR_RELEASE_MAJOR_VERSION_C != ADC_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_DRV_AR_RELEASE_MINOR_VERSION_C != ADC_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_DRV_AR_RELEASE_PATCH_VERSION_C != ADC_HW_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Drv.c and Adc_Hw.h are different"
#endif

#if ((ADC_DRV_SW_MAJOR_VERSION_C != ADC_HW_SW_MAJOR_VERSION_H) || \
     (ADC_DRV_SW_MINOR_VERSION_C != ADC_HW_SW_MINOR_VERSION_H) || \
     (ADC_DRV_SW_PATCH_VERSION_C != ADC_HW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Drv.c and Adc_Hw.h are different"
#endif

#ifndef USING_OS_AUTOSAROS
#if ((TT_SAFETY) && (TT_SAFETY == STD_ON))
/* Adc_Drv.c Base_Tools.h file version check */
#if (ADC_DRV_VENDOR_ID_C != BASE_TOOLS_VENDOR_ID_H)
    #error "Adc_Drv.c and Base_Tools.h have different vendor ids"
#endif

#if ((ADC_DRV_AR_RELEASE_MAJOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_DRV_AR_RELEASE_MINOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_DRV_AR_RELEASE_PATCH_VERSION_C != BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Drv.c and Base_Tools.h are different"
#endif

#if ((ADC_DRV_SW_MAJOR_VERSION_C != BASE_TOOLS_SW_MAJOR_VERSION_H) || \
     (ADC_DRV_SW_MINOR_VERSION_C != BASE_TOOLS_SW_MINOR_VERSION_H) || \
     (ADC_DRV_SW_PATCH_VERSION_C != BASE_TOOLS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Drv.c and Base_Tools.h are different"
#endif

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
#define ADC_START_SEC_VAR_CLEARED_BOOLEAN
#include "Adc_MemMap.h"

/*ADC hardware unit initialization status*/
static boolean AdcDrv_PubInitialised[ADC_MAX_HW_UNITS] = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};

#define ADC_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Adc_MemMap.h"
/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/
#define ADC_START_SEC_VAR_CLEARED_PTR
#include "Adc_MemMap.h"

/*Global variable declaration of configuration information*/
TT_CONST Adc_Drv_ConfigType *AdcDrv_PubConfigSet = NULL_PTR;
TT_CONST Adc_Hw_HwUnitConfigType *AdcHw_PubConfigSet = NULL_PTR;

#define ADC_STOP_SEC_VAR_CLEARED_PTR
#include "Adc_MemMap.h"

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
static void Adc_Drv_PriConfig (void);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
 * @brief   Self test.
 *
 * @param[in]     ConfigPtr : configuration data
 * @param[out]    TT_RET_SUCCESS : Success
 *                Other          : Failure
 *
 */
LOCAL_INLINE TT_RetType Adc_Drv_PriInitCheck(TT_CONST Adc_Drv_ConfigType *ConfigPtr);

/**
 * @brief   Calculate the Crc check code of the configuration data.
 *
 * @param[in]     Void
 * @@return       Crc check code
 * 
 */
#ifndef USING_OS_AUTOSAROS
LOCAL_INLINE uint32 Adc_Drv_PriCalCfgCrc(TT_CONST Adc_Drv_ConfigType *AdcDrv_CfgData);
#endif

#endif

#define ADC_START_SEC_CODE_FAST
#include "Adc_MemMap.h"
/**
 * @brief   Reports Det error if ADC_DEV_ERROR_DETECT == STD_ON.
 *
 * @param[in]     Expr - boolean expression to check API conditions
 * @param[in]     ApiId - Service Id of API
 * @param[in]     ErrId - Error Id of Condition
 * @param[out]    RetVal - variable to check return type
 *
 */
LOCAL_INLINE void Adc_Drv_PriParaCheck(boolean Expr,
                                       uint8 ApiId,
                                       TT_RetType ErrId,
                                       TT_RetType *RetVal);

/**
 * @brief   Reports Det error if ADC_DEV_ERROR_DETECT == STD_ON.
 *
 * @param[in]     ApiId - Service Id of API
 * @param[out]    ErrId - variable to check return type
 *
 */
LOCAL_INLINE void Adc_Drv_PriRetCheck (uint32 ApiId, TT_RetType *ErrId);

#define ADC_STOP_SEC_CODE_FAST
#include "Adc_MemMap.h"
/******************************************************************************
 *                         Public Functions                                    *
 ******************************************************************************/
 
#define ADC_START_SEC_CODE_SLOW
#include "Adc_MemMap.h"
/******************************************************************************
 *  Service name    : Adc_Drv_Init
 *  Syntax          : TT_RetType Adc_Drv_Init(TT_CONST Adc_Drv_ConfigType* ConfigPtr)
 *  Service ID      : 100
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant
 *  Parameters (in) : ConfigPtr : Configuration information
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to initialize the ADC.
 ********************************************************************************/
TT_RetType Adc_Drv_Init (TT_CONST Adc_Drv_ConfigType* ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#ifndef ADC_PRECOMPILE_SUPPORT
    TT_CONST Adc_Drv_ConfigType* Adc_Drv_ConfigPtr = ConfigPtr;
#endif
    uint8 Unit = 0;

    for(Unit = 0; Unit < ADC_MAX_UNITS; Unit++)
    {
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != FALSE), ADC_DRV_SI_INIT,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }

#ifdef ADC_PRECOMPILE_SUPPORT
    Adc_Drv_PriParaCheck ((ConfigPtr != NULL_PTR), ADC_DRV_SI_INIT,
                          TT_RET_PARAM_NULL_PTR_ERR, &Ret);
#else
    Adc_Drv_PriParaCheck ((ConfigPtr == NULL_PTR), ADC_DRV_SI_INIT,
                          TT_RET_PARAM_NULL_PTR_ERR, &Ret);
#endif
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Mcu_Drv_Clk_StartModules (TT_SCU_CLK_CONTROL_ADC);
        if(Ret == TT_RET_SUCCESS)
        {
#ifdef ADC_PRECOMPILE_SUPPORT
            AdcDrv_PubConfigSet = &AdcDrvConfigData;
#else
            AdcDrv_PubConfigSet = Adc_Drv_ConfigPtr;
#endif

            Adc_Drv_PriParaCheck ((AdcDrv_PubConfigSet->AdcHwUinitConfig == NULL_PTR), \
                                 ADC_DRV_SI_INIT,TT_RET_PARAM_NULL_PTR_ERR, &Ret);
            if (Ret == TT_RET_SUCCESS)
            {
                AdcHw_PubConfigSet = AdcDrv_PubConfigSet->AdcHwUinitConfig;
            }
            else
            {
                /* do nothing */
            }
#ifndef USING_OS_AUTOSAROS
#if(defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            if (Ret == TT_RET_SUCCESS)
            {
                Ret = Adc_Drv_PriCalCfgCrc(AdcDrv_PubConfigSet);
            }
            else
            {
                /* do nothing */
            }
#endif
#endif
            if (Ret == TT_RET_SUCCESS)
            {
                for (Unit = 0; Unit < ADC_MAX_UNITS; Unit++)
                {
//                    Ret = Adc_Hw_SelfCorrecting(AdcDrv_PubConfigSet->AdcHwUinitConfig[Unit].AdcHwUnitId,
//                                                AdcDrv_PubConfigSet->AdcCom->PowerMode);
                    if(Ret != TT_RET_SUCCESS)
                    {
                        break;
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
            }
            else
            {
                /* do nothing */
            }

            if (Ret == TT_RET_SUCCESS)
            {
                Ret = Adc_Hw_CommonInit (AdcDrv_PubConfigSet->AdcCom);
            }
            else
            {
                /* do nothing */
            }

            if (Ret == TT_RET_SUCCESS)
            {
                Adc_Drv_PriConfig();
            }
            else
            {
                /* do nothing */
            }
        }
        Adc_Drv_PriRetCheck (ADC_DRV_SI_INIT, &Ret);
    }
    else
    {
        /* do nothing */
    }

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Adc_Drv_PriInitCheck(AdcDrv_PubConfigSet);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_INIT, &Ret);
    }
    else
    {
        /* do nothing */
    }
#endif

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_DeInit
 *  Syntax          : TT_RetType Adc_Drv_DeInit(TT_CONST Adc_Drv_HwUnitType HwUnit)
 *  Service ID      : 101
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant
 *  Parameters (in) : HwUnit : Hardware unit ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to deinitializes the ADC.
 ********************************************************************************/
TT_RetType Adc_Drv_DeInit (TT_CONST Adc_Drv_HwUnitType HwUnit)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Adc_Drv_PriParaCheck (((uint32)HwUnit > ADC_MAX), ADC_DRV_SI_DEINIT,
                          TT_RET_PARAM_INDEX_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[HwUnit] != TRUE),
                              ADC_DRV_SI_DEINIT, TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_AdcxDisable (HwUnit);
        if(Ret == TT_RET_SUCCESS)
        {
            AdcDrv_PubInitialised[HwUnit] = FALSE;
        }
        else
        {
            Adc_Drv_PriRetCheck (ADC_DRV_SI_DEINIT, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define ADC_STOP_SEC_CODE_SLOW
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/******************************************************************************
 *  Service name    : Adc_Drv_ChannelConfig
 *  Syntax          : TT_RetType Adc_Drv_ChannelConfig(TT_CONST Adc_Drv_ChannelType AdcChannel)
 *  Service ID      : 102
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to configure channels.
 ********************************************************************************/
TT_RetType Adc_Drv_ChannelConfig (TT_CONST Adc_Drv_ChannelType AdcChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_CHANNEL_CONFIG,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_CHANNEL_CONFIG,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_ChannelConfig (&AdcDrv_PubConfigSet->ChannelConfig[AdcChannel]);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_CHANNEL_CONFIG, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_StartConversion
 *  Syntax          : TT_RetType Adc_Drv_StartConversion(TT_CONST Adc_Drv_ChannelType AdcChannel)
 *  Service ID      : 103
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to start conversion.
 ********************************************************************************/
TT_RetType Adc_Drv_StartConversion (TT_CONST Adc_Drv_ChannelType AdcChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_START_CONVERSION,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_START_CONVERSION,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_StartConvert (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_START_CONVERSION, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_GetGlobalState
 *  Syntax          : TT_RetType Adc_Drv_GetGlobalState(TT_CONST Adc_Drv_HwUnitType HwUnit,uint32 *Value)
 *  Service ID      : 104
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : HwUnit: Adc Unit Id
 *  Parameters (out): Value : Gets a pointer to the state
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to get ADC unit global state.
 ********************************************************************************/
TT_RetType Adc_Drv_GetGlobalState (TT_CONST Adc_Drv_HwUnitType HwUnit,
                                   uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Adc_Drv_PriParaCheck (((uint32)HwUnit > ADC_MAX), ADC_DRV_SI_GET_GLOBAL_STATE,
                          TT_RET_PARAM_INDEX_ERR, &Ret);
    if (Ret == TT_RET_SUCCESS)
    {
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[HwUnit] != TRUE), ADC_DRV_SI_GET_GLOBAL_STATE,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_GetGlobalState (HwUnit, Value);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_GET_GLOBAL_STATE, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_GetCurrentState
 *  Syntax          : TT_RetType Adc_Drv_GetCurrentState(TT_CONST Adc_Drv_HwUnitType HwUnit,uint32 *Value)
 *  Service ID      : 105
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : HwUnit: Adc Unit Id
 *  Parameters (out): Value : Gets a pointer to the state
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to obtain the current state of the ADC hardware.
 ********************************************************************************/
TT_RetType Adc_Drv_GetCurrentState (TT_CONST Adc_Drv_HwUnitType HwUnit,
                                    uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Adc_Drv_PriParaCheck (((uint32)HwUnit > ADC_MAX), ADC_DRV_SI_GET_CURRENT_STATE,
                          TT_RET_PARAM_INDEX_ERR, &Ret);
    if (Ret == TT_RET_SUCCESS)
    {
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[HwUnit] != TRUE), ADC_DRV_SI_GET_CURRENT_STATE,
                          TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_GetCurrentState (HwUnit, Value);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_GET_CURRENT_STATE, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_GetChannelState
 *  Syntax          : TT_RetType Adc_Drv_GetChannelState(TT_CONST Adc_Drv_ChannelType AdcChannel,uint32 *Value)
 *  Service ID      : 106
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): Value : Gets a pointer to the state
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to get channel state.
 ********************************************************************************/
TT_RetType Adc_Drv_GetChannelState (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                    uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_GET_CHANNEL_STATE,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_GET_CHANNEL_STATE,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_GetChannelState (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, Value);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_GET_CHANNEL_STATE, &Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_GetValue
 *  Syntax          : TT_RetType Adc_Drv_GetValue(TT_CONST Adc_Drv_ChannelType AdcChannel,uint16 *Value)
 *  Service ID      : 107
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): Value      : sample data
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to get channel sample data.
 ********************************************************************************/
TT_RetType Adc_Drv_GetValue (TT_CONST Adc_Drv_ChannelType AdcChannel,
                             uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_GET_VALUE,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_GET_VALUE,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_GetValue (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, Value);
        Adc_Drv_PriRetCheck(ADC_DRV_SI_GET_VALUE, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetDmaBUffer
 *  Syntax          : TT_RetType Adc_Drv_SetDmaBUffer(TT_CONST Adc_Drv_ChannelType AdcChannel,uint32 *Result)
 *  Service ID      : 108
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant for the same AdcChannel,reentrant for different
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Result     : DMA result address
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set channel DMA result buffer.
 ********************************************************************************/
TT_RetType Adc_Drv_SetDmaBuffer (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                 TT_CONST uint16 *Result)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_SET_DMA_BUFFER,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_SET_DMA_BUFFER,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_SetDmaBuff (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, Result);
        Adc_Drv_PriRetCheck(ADC_DRV_SI_SET_DMA_BUFFER, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetDmaIncraddr
 *  Syntax          : TT_RetType Adc_Drv_SetDmaIncraddr(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST uint32 Incraddr)
 *  Service ID      : 109
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant for the same AdcChannel,reentrant for different
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Result     : DMA result address
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set channel Address increment.
 ********************************************************************************/
TT_RetType Adc_Drv_SetDmaIncraddr (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                   TT_CONST uint32 Incraddr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_SET_DMA_INCRADDR,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_SET_DMA_INCRADDR,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_Set_DmaIncraddr (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, Incraddr);
        Adc_Drv_PriRetCheck(ADC_DRV_SI_SET_DMA_INCRADDR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_StopConversion
 *  Syntax          : TT_RetType Adc_Drv_StopConversion(TT_CONST Adc_Drv_HwUnitType HwUnit,TT_CONST Adc_Drv_StopModeType StopMode)
 *  Service ID      : 110
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : HwUnit     : Hardware ID
 *                    StopMode   : ADC Hardware stop mode
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to stop ADC hardware sampling.
 ********************************************************************************/
TT_RetType Adc_Drv_StopConversion (TT_CONST Adc_Drv_HwUnitType HwUnit,
                                   TT_CONST Adc_Drv_StopModeType StopMode)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Adc_Drv_PriParaCheck (((uint32)HwUnit > ADC_MAX), ADC_DRV_SI_STOP_CONVERSION,
                          TT_RET_PARAM_INDEX_ERR, &Ret);
    if (Ret == TT_RET_SUCCESS)
    {
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[HwUnit] != TRUE), ADC_DRV_SI_STOP_CONVERSION,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_StopConversion (HwUnit, StopMode);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_STOP_CONVERSION, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_ClearGlobalState
 *  Syntax          : TT_RetType Adc_Drv_ClearGlobalState(TT_CONST Adc_Drv_ChannelType AdcChannel,boolean DmaClear)
 *  Service ID      : 111
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    DmaClear   : clear DMA flag
 *  Parameters (out): NON
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to clear the ADC unit state.
 ********************************************************************************/
TT_RetType Adc_Drv_ClearGlobalState(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST boolean DmaClear)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_CLEAR_GLOBAL_STATE,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_CLEAR_GLOBAL_STATE,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_ClearGlobalState(AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId,DmaClear);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_CLEAR_GLOBAL_STATE, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_EnableHwTrig
 *  Syntax          : TT_RetType Adc_Drv_EnableHwTrig(TT_CONST Adc_Drv_ChannelType AdcChannel)
 *  Service ID      : 112
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to enable Hw trigger.
 ********************************************************************************/
TT_RetType Adc_Drv_EnableHwTrig (TT_CONST Adc_Drv_ChannelType AdcChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_ENABLE_HWTRIG,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_ENABLE_HWTRIG,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_EnableHwTrig (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_ENABLE_HWTRIG, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_DisableHwTrig
 *  Syntax          : TT_RetType Adc_Drv_DisableHwTrig(TT_CONST Adc_Drv_ChannelType AdcChannel)
 *  Service ID      : 113
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *  Parameters (out): NON
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to enable Hw trigger.
 ********************************************************************************/
TT_RetType Adc_Drv_DisableHwTrig (TT_CONST Adc_Drv_ChannelType AdcChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_DISABLE_HWTRIG,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_DISABLE_HWTRIG,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_DisableHwTrig (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_DISABLE_HWTRIG, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetSequence
 *  Syntax          : TT_RetType Adc_Drv_SetSequence(TT_CONST Adc_Drv_HwUnitType HwUnit,TT_CONST uint32 Queue)
 *  Service ID      : 114
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant for the same HwUnit,reentrant for different
 *  Parameters (in) : HwUnit : ADC Hardware ID
 *                    Queue  : Queue data,four bits representing a channel, low transmission first
 *  Parameters (out): NON
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set the sequence sampling sequence.
 ********************************************************************************/
TT_RetType Adc_Drv_SetSequence (TT_CONST Adc_Drv_HwUnitType HwUnit,
                                TT_CONST uint32 Queue)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Adc_Drv_PriParaCheck (((uint32)HwUnit > ADC_MAX), ADC_DRV_SI_SET_SEQUENCE,
                          TT_RET_PARAM_INDEX_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[HwUnit] != TRUE), ADC_DRV_SI_SET_SEQUENCE,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_SetSquence (HwUnit, Queue);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_SET_SEQUENCE, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetCTrigger
 *  Syntax          : TT_RetType Adc_Drv_SetCTrigger(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST Adc_Drv_CTrigType NextChannel)
 *  Service ID      : 115
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant for the same AdcChannel,reentrant for different
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    NextChannel: ID of the next channel triggered by cascade
 *  Parameters (out): NON
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set cascade trigger.
 ********************************************************************************/
TT_RetType Adc_Drv_SetCTrigger (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                TT_CONST Adc_Drv_CTrigType NextChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_SET_CTRIGGER,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_SET_CTRIGGER,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_SetCTrigger (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, NextChannel);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_SET_CTRIGGER, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetDmaTransCount
 *  Syntax          : TT_RetType Adc_Drv_SetDmaTransCount(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST uint8 Cnt)
 *  Service ID      : 116
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Cnt     : DMA Transmission count
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set DMA Transmission count.
 ********************************************************************************/
TT_RetType Adc_Drv_SetDmaTransCount (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                     TT_CONST uint8 Cnt)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX),ADC_DRV_SI_SET_DMATRANS_COUNT,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_SET_DMATRANS_COUNT,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_SetDmaTransCount (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, Cnt);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_SET_DMATRANS_COUNT, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetTrigger
 *  Syntax          : TT_RetType Adc_Drv_SetTrigger(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST Adc_Drv_TrigSrcType TrigSrc,TT_CONST Adc_Drv_HwTrigSigType TrigSig)
 *  Service ID      : 117
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant for the same AdcChannel,reentrant for different
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    TrigSrc    : Trigger source
 *                    TrigSig    : Trigger Edge
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set Trigger.
 ********************************************************************************/
TT_RetType Adc_Drv_SetTrigger (TT_CONST Adc_Drv_ChannelType AdcChannel,
                               TT_CONST Adc_Drv_TrigSrcType TrigSrc,
                               TT_CONST Adc_Drv_HwTrigSigType TrigSig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_SET_TRIGGER,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_SET_TRIGGER,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_SetTrigger (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, TrigSrc, TrigSig);
        Adc_Drv_PriRetCheck(ADC_DRV_SI_SET_TRIGGER, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetReadyIntEn
 *  Syntax          : TT_RetType Adc_Drv_SetDmaTransCount(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST uint8 Enable)
 *  Service ID      : 118
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Enable     : Ready interrupt enable
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set Ready interrupt enable.
 ********************************************************************************/
TT_RetType Adc_Drv_SetReadyIntEn (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                  TT_CONST uint8 Enable)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_SET_READY_INTEN,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_SET_READY_INTEN,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_SetReadyIntEn (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, Enable);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_SET_READY_INTEN, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetPriority
 *  Syntax          : TT_RetType Adc_Drv_SetPriority(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST Adc_Hw_PriorityType Pri)
 *  Service ID      : 119
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Non reentrant for the same AdcChannel,reentrant for different
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Pri        : Channel priority
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set Ready interrupt enable.
 ********************************************************************************/
TT_RetType Adc_Drv_SetPriority (TT_CONST Adc_Drv_ChannelType AdcChannel,
                                TT_CONST Adc_Drv_PriorityType Pri)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_SET_PRIORITY,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_SET_PRIORITY,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_SetCPriority (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, Pri);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_SET_PRIORITY, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *  Service name    : Adc_Drv_SetDmaEn
 *  Syntax          : TT_RetType Adc_Drv_SetDmaEn(TT_CONST Adc_Drv_ChannelType AdcChannel,TT_CONST boolean Enable,TT_CONST boolean IntEnable)
 *  Service ID      : 120
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : AdcChannel : Hardware channel ID
 *                    Enable     : DMA enable
 *                    IntEnable  : DMA Int enable
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : This service is used to set Ready interrupt enable.
 ********************************************************************************/
TT_RetType Adc_Drv_SetDmaEn (TT_CONST Adc_Drv_ChannelType AdcChannel,
                             TT_CONST boolean Enable,
                             TT_CONST boolean IntEnable)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    Adc_Drv_PriParaCheck ((AdcChannel > ADC_CHANNEL_MAX), ADC_DRV_SI_SET_DMAEN,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Unit = ((AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId) & (uint8)0xF0) >> 4;
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[Unit] != TRUE), ADC_DRV_SI_SET_DMAEN,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Adc_Hw_SetDmaEn (AdcDrv_PubConfigSet->ChannelConfig[AdcChannel].ChId, Enable, IntEnable);
        Adc_Drv_PriRetCheck (ADC_DRV_SI_SET_DMAEN, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE_SLOW
#include "Adc_MemMap.h"

/******************************************************************************
 *  Service name    : Adc_GetVersionInfo
 *  Syntax          : void Adc_Drv_GetVersionInfo (Std_VersionInfoType* version info)
 *  Service ID      : 121
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : None
 *  Parameters (out): versioninfo - Pointer to where to store the version information of this module.
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : Returns the version information of this module.
 ******************************************************************************/
TT_RetType Adc_Drv_GetVersionInfo (Std_VersionInfoType *versioninfo)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Adc_Drv_PriParaCheck ((NULL_PTR == versioninfo), ADC_DRV_SI_GETVER_INFO,
                          TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        (versioninfo)->vendorID = (uint16) ADC_DRV_VENDOR_ID_H;
        (versioninfo)->moduleID = (uint16) ADC_DRV_MODULE_ID_H;
        (versioninfo)->sw_major_version = (uint8) ADC_DRV_SW_MAJOR_VERSION_H;
        (versioninfo)->sw_minor_version = (uint8) ADC_DRV_SW_MINOR_VERSION_H;
        (versioninfo)->sw_patch_version = (uint8) ADC_DRV_SW_PATCH_VERSION_H;
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

#define ADC_STOP_SEC_CODE_SLOW
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/******************************************************************************
 *  Service name    : Adc_Drv_ClearGlobalStateInMask
 *  Syntax          : TT_RetType Adc_Drv_ClearGlobalStateInMask(TT_CONST Adc_Drv_HwUnitType HwUnit, TT_CONST uint32 Cl_Mask)
 *  Service ID      : 122
 *  Sync/Async      : Synchronous
 *  Reentrancy      : Reentrant
 *  Parameters (in) : HwUnit : ADC Hardware ID
 *  Parameters (out): None
 *  Return value    : TT_RET_SUCCESS : Success
 *                    Other          : Failure
 *  Description     : Use the write mask to clear the flag.
 ********************************************************************************/
TT_RetType Adc_Drv_ClearGlobalStateInMask(TT_CONST Adc_Drv_HwUnitType HwUnit, TT_CONST uint32 Cl_Mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Adc_Drv_PriParaCheck (((uint32)HwUnit > ADC_MAX), ADC_DRV_SI_CLGLOBALST_IN_MASK,
                          TT_RET_PARAM_INDEX_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        Adc_Drv_PriParaCheck ((AdcDrv_PubInitialised[HwUnit] != TRUE), ADC_DRV_SI_CLGLOBALST_IN_MASK,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    if(Ret == TT_RET_SUCCESS)
    {
        Adc_Hw_IrqAdcxClearState((uint32)HwUnit,Cl_Mask);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
#define ADC_START_SEC_CODE_SLOW
#include "Adc_MemMap.h"

static void Adc_Drv_PriConfig (void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 Unit = 0;

    for (Unit = 0; Unit < ADC_MAX_UNITS; Unit++)
    {
        Ret = Adc_Hw_AdcxConfig(&AdcDrv_PubConfigSet->AdcHwUinitConfig[Unit]);
        if (Ret == TT_RET_SUCCESS)
        {
            AdcDrv_PubInitialised[AdcDrv_PubConfigSet->AdcHwUinitConfig[Unit].AdcHwUnitId] = TRUE;
        }
        else
        {
            AdcDrv_PubInitialised[AdcDrv_PubConfigSet->AdcHwUinitConfig[Unit].AdcHwUnitId] = FALSE;
            break;
        }
    }
}

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
 * @brief   Self test.
 *
 * @param[in]     ConfigPtr : configuration data
 * @param[out]    None
 *
 */
LOCAL_INLINE TT_RetType Adc_Drv_PriInitCheck(TT_CONST Adc_Drv_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Mask = 0;
    uint32 AxCFR = 0;
    uint8 Index = 0;

    Mask = ((uint32)ConfigPtr->AdcCom->FirShift << TT_ADC_AGC0_FIR_SHIFT_Pos) |\
           ((uint32)ConfigPtr->AdcCom->STSamp << TT_ADC_AGC0_STSAMP_Pos)|\
           ((uint32)ConfigPtr->AdcCom->FTSamp << TT_ADC_AGC0_FTSAMP_Pos) | \
           ((uint32)ConfigPtr->AdcCom->Div << TT_ADC_AGC0_DIV_Pos)  |\
           ((uint32)ConfigPtr->AdcCom->Acg0_Wp << TT_ADC_AGC0_AGC0_WP_Pos);

    for(Index = 0; Index < ADC_MAX_UNITS; Index++)
    {
        AxCFR = ((uint32)ConfigPtr->AdcHwUinitConfig[Index].Enable << TT_ADC_CFR_EN_Pos) |\
                ((uint32)ConfigPtr->AdcHwUinitConfig[Index].CMode << TT_ADC_CFR_CMCODE_Pos) |\
                ((uint32)ConfigPtr->AdcHwUinitConfig[Index].CompenEn << TT_ADC_CFR_COMPUEN_Pos ) |\
                ((uint32)ConfigPtr->AdcHwUinitConfig[Index].WaitRead << TT_ADC_CFR_WAIT_TO_READ_Pos ) |\
                ((uint32)ConfigPtr->AdcHwUinitConfig[Index].DmaEn << TT_ADC_CFR_DMA_EN_Pos ) |\
                ((uint32)ConfigPtr->AdcHwUinitConfig[Index].DmaIntEn << TT_ADC_CFR_DMA_INT_EN_Pos ) |\
                ((uint32)ConfigPtr->AdcHwUinitConfig[Index].DmaMode << TT_ADC_CFR_DMA_MODE_Pos);

        Ret = Adc_Hw_InitCheck(AdcDrv_PubConfigSet->AdcHwUinitConfig[Index].AdcHwUnitId,Mask,AxCFR);
        if(Ret != TT_RET_SUCCESS)
        {
            AdcDrv_PubInitialised[AdcDrv_PubConfigSet->AdcHwUinitConfig[Index].AdcHwUnitId] = FALSE;
        }
        else
        {
            /* do nothing */
        }
    }

    return Ret;
}

/**
 * @brief   Calculate the Crc check code of the configuration data.
 *
 * @param[in]     AdcDrv_PubConfigSet      Configuration data pointer.
 * @@return       Crc check code
 *
 */
#ifndef USING_OS_AUTOSAROS
LOCAL_INLINE TT_RetType Adc_Drv_PriCalCfgCrc(TT_CONST Adc_Drv_ConfigType *AdcDrv_CfgData)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 AdcCrcData = 0;
    uint32 AdcCrc = 0;
    sint32 Adc_filter = 0;
    sint32 Adc_Comp = 0;
    uint8 Adc_ChId =0;

    Adc_Drv_PriParaCheck ((NULL_PTR == AdcDrv_CfgData->AdcCom), ADC_DRV_SI_INIT,
                          TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    Adc_Drv_PriParaCheck ((NULL_PTR != AdcDrv_CfgData->AdcCom) && (NULL_PTR == AdcDrv_CfgData->AdcCom->Filter), 
                          ADC_DRV_SI_INIT, TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    Adc_Drv_PriParaCheck ((NULL_PTR == AdcDrv_CfgData->ChannelConfig), ADC_DRV_SI_INIT,
                          TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcCom->Filter->Fir_Wp, &AdcCrcData);

        for(uint8 i = 0; i<25; i++)
        {
            Adc_filter = AdcDrv_CfgData->AdcCom->Filter->filters[i] + 65535;
            Base_AccumulateCRC((TT_CONST uint32)Adc_filter, &AdcCrcData);
        }

        Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcCom->Div, &AdcCrcData);
        Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcCom->STSamp, &AdcCrcData);
        Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcCom->FTSamp, &AdcCrcData);
        Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcCom->PowerMode, &AdcCrcData);
        Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcCom->FirShift, &AdcCrcData);
#ifdef A8V2E
        Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcCom->Clk_Stop, &AdcCrcData);
#endif
        Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcCom->Acg0_Wp, &AdcCrcData);

        for(uint8 i = 0; i<ADC_MAX_UNITS; i++)
        {
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].AdcHwUnitId, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].Enable, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].WaitRead, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].CompenEn, &AdcCrcData);
            Adc_Comp = (TT_CONST sint32)AdcDrv_CfgData->AdcHwUinitConfig[i].CompenData + 4095;
            Base_AccumulateCRC((TT_CONST uint32)Adc_Comp, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].DmaEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].DmaIntEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].DmaMode, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].Queue, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->AdcHwUinitConfig[i].CMode, &AdcCrcData);
        }

        for(uint8 i = 0; i<ADC_CHANNEL_MAX; i++)
        {
            Adc_ChId = AdcDrv_CfgData->ChannelConfig[i].ChId & 0xFU;
            Base_AccumulateCRC((TT_CONST uint32)Adc_ChId, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].Shift, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].SampNum, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].ReadyIntEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].FSampEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].FirEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].HCompEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].LCompEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].HCompIntEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].LCompIntEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].ThresholdH, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].ThresholdL, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].TrgDmaIntEn, &AdcCrcData);
#ifdef A8V2E
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].TimeoutIntEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].CompIntEn, &AdcCrcData);
#endif
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].TrgIntEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].TrigSrc, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].TrigEdge, &AdcCrcData);
            if(AdcDrv_CfgData->ChannelConfig[i].CTrig == 0)
            {
                Base_AccumulateCRC((TT_CONST uint32)0, &AdcCrcData);
            }
            else
            {
                Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].CTrig-1, &AdcCrcData);
            }
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].Priority, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].DmaConfig.DmaErrorEn, &AdcCrcData);
            Base_AccumulateCRC((TT_CONST uint32)AdcDrv_CfgData->ChannelConfig[i].DmaConfig.DmaTranCount, &AdcCrcData);
        }
    }
    else
    {
        /* do nothing */
    }

    AdcCrc = (uint32)Base_FinalizeCRC(&AdcCrcData);

    if(AdcDrv_PubConfigSet->Crc != AdcCrc)
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#endif
#endif

#define ADC_STOP_SEC_CODE_SLOW
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE_FAST
#include "Adc_MemMap.h"
/**
 * @brief   Reports Det error if ADC_DEV_ERROR_DETECT == STD_ON.
 *
 * @param[in]     Expr - boolean expression to check API conditions
 * @param[in]     ApiId - Service Id of API
 * @param[in]     ErrId - Error Id of Condition
 * @param[out]    RetVal - variable to check return type
 *
 */
LOCAL_INLINE void Adc_Drv_PriParaCheck(boolean Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(ADC_DRV_TT_STATUS_DEFAULT(ApiId), ErrId);
#if defined(ADC_DEV_ERROR_DETECT) && (ADC_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(ADC_DRV_MODULE_ID_C, ApiId, ErrId);
            ModuleDet_ReportError(ADC_DRV_MODULE_ID_C, 0, (uint8)(ApiId & 0xFFU), (uint8)(ErrId & 0xFFU));
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
    *(RetVal) = ((uint32)(RetVal) > 1) ? 0U: 1U;
#endif
}

/**
 * @brief   Reports Det error if ADC_DEV_ERROR_DETECT == STD_ON.
 *
 * @param[in]     ApiId - Service Id of API
 * @param[out]    ErrId - variable to check return type
 *
 */
LOCAL_INLINE void Adc_Drv_PriRetCheck (uint32 ApiId, TT_RetType *ErrId)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
#if defined(ADC_DEV_ERROR_DETECT) && (ADC_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(ADC_DRV_MODULE_ID_C, (uint8 )ApiId, *ErrId);
            ModuleDet_ReportError(ADC_DRV_MODULE_ID_C, 0, (uint8)(ApiId & 0xFFU), (uint8)(*ErrId & 0xFFU));
#endif
            *ErrId = TT_SET_STATUS_TYPE(ADC_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
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

#define ADC_STOP_SEC_CODE_FAST
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif
