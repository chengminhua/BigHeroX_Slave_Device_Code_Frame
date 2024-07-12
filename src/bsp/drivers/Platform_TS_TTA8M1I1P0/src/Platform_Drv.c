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
**  FILENAME     : Platform_Drv.c                                             **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Source File                                **
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
#include "Platform_Drv.h"
#include "Platform_Hw_IntCtrl.h"
#include "Platform_Hw_Mpu.h"
#include "Platform_Hw_Misc.h"
#include "Platform_Hw_Cache.h"
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#include "Base_Tools.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_DRV_VENDOR_ID_C                     1541
#define PLATFORM_DRV_MODULE_ID_C                     219
#define PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_C      4
#define PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_C      4
#define PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_C      0
#define PLATFORM_DRV_SW_MAJOR_VERSION_C              1
#define PLATFORM_DRV_SW_MINOR_VERSION_C              1
#define PLATFORM_DRV_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Drv.c and Platform_Drv.h file version check */
#if (PLATFORM_DRV_VENDOR_ID_C != PLATFORM_DRV_VENDOR_ID_H)
    #error "Platform_Drv.c and Platform_Drv.h have different vendor id"
#endif
#if (PLATFORM_DRV_MODULE_ID_C != PLATFORM_DRV_MODULE_ID_H)
    #error "Platform_Drv.c and Platform_Drv.h have different module id"
#endif
#if ((PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_C != PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_C != PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv.c and Platform_Drv.h are different"
#endif
#if ((PLATFORM_DRV_SW_MAJOR_VERSION_C != PLATFORM_DRV_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_SW_MINOR_VERSION_C != PLATFORM_DRV_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_SW_PATCH_VERSION_C != PLATFORM_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv.c and Platform_Drv.h are different"
#endif

/* Platform_Drv.c and Platform_Hw_IntCtrl.h file version check */
#if (PLATFORM_DRV_VENDOR_ID_C != PLATFORM_HW_INTCTRL_VENDOR_ID_H)
    #error "Platform_Drv.c and Platform_Hw_IntCtrl.h have different vendor id"
#endif
#if (PLATFORM_DRV_MODULE_ID_C != PLATFORM_HW_INTCTRL_MODULE_ID_H)
    #error "Platform_Drv.c and Platform_Hw_IntCtrl.h have different module id"
#endif
#if ((PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_INTCTRL_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_INTCTRL_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_INTCTRL_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv.c and Platform_Hw_IntCtrl.h are different"
#endif
#if ((PLATFORM_DRV_SW_MAJOR_VERSION_C != PLATFORM_HW_INTCTRL_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_SW_MINOR_VERSION_C != PLATFORM_HW_INTCTRL_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_SW_PATCH_VERSION_C != PLATFORM_HW_INTCTRL_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv.c and Platform_Hw_IntCtrl.h are different"
#endif

/* Platform_Drv.c and Platform_Hw_Mpu.h file version check */
#if (PLATFORM_DRV_VENDOR_ID_C != PLATFORM_HW_MPU_VENDOR_ID_H)
    #error "Platform_Drv.c and Platform_Hw_Mpu.h have different vendor id"
#endif
#if (PLATFORM_DRV_MODULE_ID_C != PLATFORM_HW_MPU_MODULE_ID_H)
    #error "Platform_Drv.c and Platform_Hw_Mpu.h have different module id"
#endif
#if ((PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_MPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_MPU_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_MPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv.c and Platform_Hw_Mpu.h are different"
#endif
#if ((PLATFORM_DRV_SW_MAJOR_VERSION_C != PLATFORM_HW_MPU_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_SW_MINOR_VERSION_C != PLATFORM_HW_MPU_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_SW_PATCH_VERSION_C != PLATFORM_HW_MPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv.c and Platform_Hw_Mpu.h are different"
#endif

/* Platform_Drv.c and Platform_Hw_Misc.h file version check */
#if (PLATFORM_DRV_VENDOR_ID_C != PLATFORM_HW_MISC_VENDOR_ID_H)
    #error "Platform_Drv.c and Platform_Hw_Misc.h have different vendor id"
#endif
#if (PLATFORM_DRV_MODULE_ID_C != PLATFORM_HW_MISC_MODULE_ID_H)
    #error "Platform_Drv.c and Platform_Hw_Misc.h have different module id"
#endif
#if ((PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_MISC_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_MISC_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_MISC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv.c and Platform_Hw_Misc.h are different"
#endif
#if ((PLATFORM_DRV_SW_MAJOR_VERSION_C != PLATFORM_HW_MISC_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_SW_MINOR_VERSION_C != PLATFORM_HW_MISC_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_SW_PATCH_VERSION_C != PLATFORM_HW_MISC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv.c and Platform_Hw_Misc.h are different"
#endif

/* Platform_Drv.c and Platform_Hw_Cache.h file version check */
#if (PLATFORM_DRV_VENDOR_ID_C != PLATFORM_HW_CACHE_VENDOR_ID_H)
    #error "Platform_Drv.c and Platform_Hw_Cache.h have different vendor id"
#endif
#if (PLATFORM_DRV_MODULE_ID_C != PLATFORM_HW_CACHE_MODULE_ID_H)
    #error "Platform_Drv.c and Platform_Hw_Cache.h have different module id"
#endif
#if ((PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv.c and Platform_Hw_Cache.h are different"
#endif
#if ((PLATFORM_DRV_SW_MAJOR_VERSION_C != PLATFORM_HW_CACHE_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_SW_MINOR_VERSION_C != PLATFORM_HW_CACHE_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_SW_PATCH_VERSION_C != PLATFORM_HW_CACHE_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv.c and Platform_Hw_Cache.h are different"
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#include "Base_Tools.h"
/* Platform_Drv.c and Base_Tools.h file version check */
#if (PLATFORM_DRV_VENDOR_ID_C != BASE_TOOLS_VENDOR_ID_H)
    #error "Platform_Drv.c and Base_Tools.h have different vendor id"
#endif
#if ((PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_C != BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Tools.c and Base_Tools.h are different"
#endif
#if ((PLATFORM_DRV_SW_MAJOR_VERSION_C != BASE_TOOLS_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_SW_MINOR_VERSION_C != BASE_TOOLS_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_SW_PATCH_VERSION_C != BASE_TOOLS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv.c and Base_Tools.h are different"
#endif
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
/* Module id */
#define PLATFORM_MODULE_ID                          (PLATFORM_DRV_MODULE_ID_C)
/* Platform Driver Default Status */
#define PLATFORM_DRV_TT_STATUS_DEFAULT(ApiID)       (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET)         | \
                                                                ((ApiID) << TT_APIID_OFFSET)                    | \
                                                                (PLATFORM_MODULE_ID << TT_MODULEID_OFFSET))

/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)

#define PLATFORM_START_SEC_VAR_INIT_32
#include "Platform_MemMap.h"

#ifdef _VCAST_MINGW_C
    uint32 *__RAM_NO_CACHEABLE_START;
    uint32 *__RAM_NO_CACHEABLE_END;
#else
    extern uint32 __RAM_NO_CACHEABLE_START[];
    extern uint32 __RAM_NO_CACHEABLE_END[];
#endif

#define PLATFORM_STOP_SEC_VAR_INIT_32
#include "Platform_MemMap.h"
#endif
/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/**
 * @brief       Platform_Drv_Cache_PriAddrCheck
 * @details     Cache address check
 * @param[in]   addr  Address
 * @param[in]   dsize  Size of memory block (in number of bytes)
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
*/
static TT_RetType Platform_Drv_Cache_PriAddrCheck(uint32 * TT_CONST addr, TT_CONST uint32 dsize);   

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
#endif

#define PLATFORM_START_SEC_CODE_FAST
#include "Platform_MemMap.h"

/**
* @brief         Platform_Drv_PriParaCheck
* @details       Reports Det error if PLATFORM_DEV_ERROR_DETECT == STD_ON
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Platform_Drv_PriParaCheck(bool Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal);

/**
* @brief         Platform_Drv_PriRetCheck
* @details       Reports Return Value error if PLATFORM_DEV_ERROR_DETECT == STD_ON
* @param[in]     ApiId - Service Id of API
* @param[out]    ErrId - Error Id of Condition
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Platform_Drv_PriRetCheck(uint8 ApiId, TT_RetType *ErrId);
#define PLATFORM_STOP_SEC_CODE_FAST
#include "Platform_MemMap.h"

#define PLATFORM_START_SEC_CODE_SLOW
#include "Platform_MemMap.h"

#if (TT_SAFETY == STD_ON)
/**
* @brief        Platform_PriInitCheck
* @details      Check Platform Config
* @param[in]    pConfig  Pointer to a CONSTant Platform module setting
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Platform_PriInitCheck(TT_CONST Platform_Drv_ConfigType * TT_CONST pConfig);

/**
* @brief        Platform_PriIrqInitCheck(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig)
* @details      Initializes the configured interrupts at interrupt controller level.
* @param[in]    pConfig  Pointer to a CONSTant IntCtrl setting
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Platform_PriIrqInitCheck(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig);

/**
 * @brief         Platform_PriCalcCustomCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     Non
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static uint32 Platform_PriCalcCfgCrc(TT_CONST Platform_Drv_ConfigType * TT_CONST pConfig);
#endif

/******************************************************************************
*                            Public Functions
*******************************************************************************/
#if (PLATFORM_VERSION_INFO_API == STD_ON)
/******************************************************************************
*  Service name    : Platform_Drv_GetVersionInfo
*  Syntax          : TT_RetType Platform_Drv_GetVersionInfo(Std_VersionInfoType* versioninfo)
*  Service ID      : 145
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): versioninfo : Pointer to where to store the version
                     information of this module.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This service returns the version information of this module.
********************************************************************************/
TT_RetType Platform_Drv_GetVersionInfo(Std_VersionInfoType *Versioninfo)
{
    TT_RetType RetVal = TT_RET_SUCCESS;

    Platform_Drv_PriParaCheck((NULL_PTR == Versioninfo),
            PLATFORM_DRV_SI_GETVERSIONINFO,TT_RET_PARAM_NULL_PTR_ERR, &RetVal);

    if (TT_RET_SUCCESS == RetVal)
    {
        Versioninfo->vendorID = PLATFORM_DRV_VENDOR_ID_C;
        Versioninfo->moduleID = PLATFORM_DRV_MODULE_ID_C;
        Versioninfo->sw_major_version = PLATFORM_DRV_SW_MAJOR_VERSION_C;
        Versioninfo->sw_minor_version = PLATFORM_DRV_SW_MINOR_VERSION_C;
        Versioninfo->sw_patch_version = PLATFORM_DRV_SW_PATCH_VERSION_C;
    }
    else
    {
        /* do nothing */
    }
    
    return RetVal;
}
#endif

/*****************************************************************************
*  Service name    : Platform_Drv_Init
*  Syntax          : TT_RetType Platform_Drv_Init(TT_CONST Platform_Drv_ConfigType * TT_CONST pConfig)
*  Service ID      : 100
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : pConfig  Pointer to a CONSTant Platform module setting
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes the platform settings based on user configuration.
******************************************************************************/
TT_RetType Platform_Drv_Init(TT_CONST Platform_Drv_ConfigType * TT_CONST pConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Platform_Drv_ConfigType *TmpPtr = NULL_PTR;
#if (TT_SAFETY == STD_ON)
    uint32 Crc = 0;
#endif
#ifdef PLATFORM_PRECOMPILE_SUPPORT
    Platform_Drv_PriParaCheck((pConfig != NULL_PTR), PLATFORM_DRV_SI_INIT, TT_RET_PARAM_INVALID_PTR_ERR, &Ret);
    TmpPtr = (TT_CONST Platform_Drv_ConfigType *)&Platform_ConfigData;
#else
        Platform_Drv_PriParaCheck((pConfig == NULL_PTR), PLATFORM_DRV_SI_INIT, TT_RET_PARAM_NULL_PTR_ERR, &Ret);
        TmpPtr = pConfig;
        if (NULL_PTR != TmpPtr)
#endif
        {
        #if (TT_SAFETY == STD_ON)
            Crc = Platform_PriCalcCfgCrc(TmpPtr);
            Platform_Drv_PriParaCheck((Crc != TmpPtr->Crc),PLATFORM_DRV_SI_INIT,TT_RET_PARAM_CONFIG_ERR,&Ret);

            if (Ret == TT_RET_SUCCESS)
            {
        #endif
                Ret = Platform_Drv_IntCtrl_Init(TmpPtr->IntCtrlConfig);
            #if (PLATFORM_ENABLE_MPU == STD_ON)
                if (Ret == TT_RET_SUCCESS)
                {
                    Ret = Platform_Drv_Mpu_Init(TmpPtr->MpuConfig);
                }
                else
                {
                    /* do nothing */
                }
            #endif

            #if (TT_SAFETY == STD_ON)
                if (Ret == TT_RET_SUCCESS)
                {
                    Ret = Platform_PriInitCheck(TmpPtr);
                }
                else
                {
                    /* do nothing */
                }
            #endif
        #if (TT_SAFETY == STD_ON)
            }
        #endif
            Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INIT, &Ret);
        }

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_Init
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_Init(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig)
*  Service ID      : 101
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : pIntCtrlCtrlConfig  Pointer to a CONSTant Platform interrupt control setting.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes the configured interrupts at interrupt controller level.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_Init(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_Init(pIntCtrlCtrlConfig);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_INIT, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Init
*  Syntax          : TT_RetType Platform_Drv_Mpu_Init(TT_CONST Platform_Hw_MpuConfigType * TT_CONST pConfig)
*  Service ID      : 130
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : pConfig  Pointer to configuration structure for MPU M7.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes the Memory Protection Unit general parameters and
*                    region configurations.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_Init(TT_CONST Platform_Hw_MpuConfigType * TT_CONST pConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_Init(pConfig);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_INIT, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Deinit
*  Syntax          : TT_RetType Platform_Drv_Mpu_Deinit(void)
*  Service ID      : 132
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Disables the module and resets all region configurations.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_Deinit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_Deinit();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_DEINIT, &Ret);

    return Ret;
}

#define PLATFORM_STOP_SEC_CODE_SLOW
#include "Platform_MemMap.h"

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_SetPriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_SetPriority(TT_CONST IRQn_Type eIrqNumber, TT_CONST uint8 preemptionPriority, TT_CONST uint8 subPriority)
*  Service ID      : 102
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : eIrqNumber  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (in) : preemptionPriority  Preemptive priority value in range [0, 2^{7-priorityGroup}-1].
*  Parameters (in) : subPriority  Subpriority value in range [0, 2^{priorityGroup+1}-1].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : The range of preemption priority and sub priority depends on the value of priorityGroup
*                    which you may obtain with SetPriorityGrouping().
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_SetPriority(TT_CONST IRQn_Type eIrqNumber, TT_CONST uint8 preemptionPriority, TT_CONST uint8 subPriority)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_SetPriority(eIrqNumber, preemptionPriority, subPriority);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_SET_PRIORITY, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GetPriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GetPriority(TT_CONST IRQn_Type eIrqNumber, uint8 * TT_CONST RetVal)
*  Service ID      : 103
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : eIrqNumber  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): RetVal  Grouped priority value of specific interrupt.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get an interrupt priority value.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_GetPriority(TT_CONST IRQn_Type eIrqNumber, uint8 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_GetPriority(eIrqNumber, RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_GET_PRIORITY, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GroupingSetPriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GroupingSetPriority(TT_CONST uint32 PriorityGroup)
*  Service ID      : 104
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : PriorityGroup  Priority grouping field.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Sets the priority grouping field using the required unlock sequence.
*                    The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
*                    Only values from 0..7 are used.
*                    In case of a conflict between priority grouping and available
*                    priority bits (PLATFORM_INT_CTRL_GROUP_BITS), the smallest possible priority group is set.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_GroupingSetPriority(TT_CONST uint32 PriorityGroup)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_GroupingSetPriority(PriorityGroup);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_SET_PRIORITY_GROUPING, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GroupingGetPriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GroupingGetPriority(uint32 * TT_CONST RetVal)
*  Service ID      : 105
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): RetVal  Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Reads the priority grouping field from the NVIC Interrupt Controller.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_GroupingGetPriority(uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_GroupingGetPriority(RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_GET_PRIORITY_GROUPING, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_EnableIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_EnableIRQ(TT_CONST IRQn_Type IRQn)
*  Service ID      : 106
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Enables a device specific interrupt in the NVIC interrupt controller.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_EnableIRQ(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_EnableIRQ(IRQn);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_ENABLE_IRQ, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GetEnableIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GetEnableIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
*  Service ID      : 107
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): RetVal  Interrupt enable status.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Returns a device specific interrupt enable status from the NVIC interrupt controller.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_GetEnableIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_GetEnableIRQ(IRQn, RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_GET_ENABLE_IRQ, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_DisableIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_DisableIRQ(TT_CONST IRQn_Type IRQn)
*  Service ID      : 108
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Disables a device specific interrupt in the NVIC interrupt controller.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_DisableIRQ(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_DisableIRQ(IRQn);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_DISABLE_IRQ, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GetPendingIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GetPendingIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
*  Service ID      : 109
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): Interrupt status is pending or not.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Reads the NVIC pending register and returns the pending bit for the specified device specific interrupt.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_GetPendingIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_GetPendingIRQ(IRQn, RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_GET_PENDING_IRQ, &Ret);
    
    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_SetPendingIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_SetPendingIRQ(TT_CONST IRQn_Type IRQn)
*  Service ID      : 110
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Sets the pending bit of a device specific interrupt in the NVIC pending register.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_SetPendingIRQ(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_SetPendingIRQ(IRQn);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_SET_PENDING_IRQ, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_ClearPendingIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_ClearPendingIRQ(TT_CONST IRQn_Type IRQn)
*  Service ID      : 111
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Clears the pending bit of a device specific interrupt in the NVIC pending register.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_ClearPendingIRQ(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_ClearPendingIRQ(IRQn);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_CLEAR_PENDING_IRQ, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GetActive
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GetActive(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
*  Service ID      : 112
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): RetVal  Interrupt active status.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Reads the active register in the NVIC and returns the active bit for the device specific interrupt.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_GetActive(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_GetActive(IRQn, RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_GET_ACTIVE, &Ret);

    return Ret;
}


/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_SoftTrig
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_SoftTrig(TT_CONST IRQn_Type IRQn)
*  Service ID      : 143
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Trigger a interrupt by means of software trigger.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_SoftTrig(TT_CONST IRQn_Type IRQn)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_SoftTrig(IRQn);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_SET_SOFTTRIG, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_EncodePriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_EncodePriority(TT_CONST uint32 PriorityGroup,TT_CONST uint32 PreemptPriority,
*                                                                   TT_CONST uint32 SubPriority,uint32 * TT_CONST RetVal)
*  Service ID      : 113
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : PriorityGroup  Used priority group.
*  Parameters (in) : PreemptPriority  Preemptive priority value (starting from 0).
*  Parameters (in) : SubPriority  Subpriority value (starting from 0).
*  Parameters (out): RetVal  Encoded priority. Value can be used in the function
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Encodes the priority for an interrupt with the given priority group,
*                    preemptive priority value, and subpriority value.
*                    In case of a conflict between priority grouping and available
*                    priority bits (PLATFORM_INT_CTRL_GROUP_BITS), the smallest possible priority group is set.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_EncodePriority(TT_CONST uint32 PriorityGroup,TT_CONST uint32 PreemptPriority,
                                               TT_CONST uint32 SubPriority,uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_EncodePriority(PriorityGroup, PreemptPriority, SubPriority, RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_ENCODE_PRIORITY, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_DecodePriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_DecodePriority(TT_CONST uint32 Priority,TT_CONST uint32 PriorityGroup,
*                                                                   uint32* TT_CONST pPreemptPriority,uint32* TT_CONST pSubPriority)
*  Service ID      : 114
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : Priority   Priority value, which can be retrieved with the function \ref Platform_Drv_IntCtrl_GetPriority().
*  Parameters (in) : PriorityGroup  Used priority group.
*  Parameters (out): pPreemptPriority  Preemptive priority value (starting from 0).
*  Parameters (out): pSubPriority  Subpriority value (starting from 0).
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes the platform settings based on user configuration.
******************************************************************************/
TT_RetType Platform_Drv_IntCtrl_DecodePriority(TT_CONST uint32 Priority,TT_CONST uint32 PriorityGroup,
                                                uint32* TT_CONST pPreemptPriority,uint32* TT_CONST pSubPriority)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_IntCtrl_DecodePriority(Priority, PriorityGroup, pPreemptPriority, pSubPriority);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INTCTRL_DECODE_PRIORITY, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Misc_GetFPUType
*  Syntax          : TT_RetType Platform_Drv_Misc_GetFPUType(uint32 * TT_CONST RetVal)
*  Service ID      : 115
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): RetVal  FPU type.
*                       0  No FPU.
*                       1  Single precision FPU.
*                       2  Double + Single precision FPU.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get FPU type.
******************************************************************************/
TT_RetType Platform_Drv_Misc_GetFPUType(uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Misc_GetFPUType(RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MISC_GET_FPU_TYPE, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Misc_SetVector
*  Syntax          : TT_RetType Platform_Drv_Misc_SetVector(TT_CONST IRQn_Type IRQn, TT_CONST uint32 vector)
*  Service ID      : 117
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Interrupt number in range [0, MAX_IRQn].
*  Parameters (in) : vector  Address of interrupt handler function.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Set interrupt vector.
******************************************************************************/
TT_RetType Platform_Drv_Misc_SetVector(TT_CONST IRQn_Type IRQn, TT_CONST uint32 vector)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Misc_SetVector(IRQn, vector);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MISC_SET_VECTOR, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Misc_GetVector
*  Syntax          : TT_RetType Platform_Drv_Misc_GetVector(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
*  Service ID      : 118
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Interrupt number in range [0, MAX_IRQn].
*  Parameters (out): RetVal  Address of interrupt handler function stored in uint32.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get Interrupt Vector.
******************************************************************************/
TT_RetType Platform_Drv_Misc_GetVector(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Misc_GetVector(IRQn, RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MISC_GET_VECTOR, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_EnableICache
*  Syntax          : TT_RetType Platform_Drv_Cache_EnableICache(void)
*  Service ID      : 119
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Turns on I-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_EnableICache(void)
{
#if defined (PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Platform_Hw_Cache_EnableICache();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CACHE_ENABLE_ICACHE, &Ret);
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_DisableICache
*  Syntax          : TT_RetType Platform_Drv_Cache_DisableICache(void)
*  Service ID      : 120
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Turns off I-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_DisableICache(void)
{
#if defined (PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Platform_Hw_Cache_DisableICache();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CACHE_DISABLE_ICACHE, &Ret);
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_InvalidateICache
*  Syntax          : TT_RetType Platform_Drv_Cache_InvalidateICache(void)
*  Service ID      : 121
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Invalidate I-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_InvalidateICache(void)
{
#if defined (PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Platform_Hw_Cache_InvalidateICache();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CACHE_INVALIDATE_ICACHE, &Ret);
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_AddrInvalidateICache
*  Syntax          : TT_RetType Platform_Drv_Cache_AddrInvalidateICache(void * TT_CONST addr, TT_CONST uint32 isize)
*  Service ID      : 144
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : addr    address
*  Parameters (in) : isize   size of memory block (in number of bytes)
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Invalidate I-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_AddrInvalidICache(void * TT_CONST addr, TT_CONST uint32 isize)
{
#if defined (PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Drv_Cache_PriAddrCheck(addr, isize);
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Platform_Hw_Cache_AddrInvalidICache(addr, isize);
        Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INVALIDATE_ICACHE_BY_ADDR, &Ret);
    }
    else
    {
        /* do nothing */
    }

#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
    (void)addr;
    (void)isize;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_EnableDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_EnableDCache(void)
*  Service ID      : 122
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Turns on D-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_EnableDCache(void)
{
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Platform_Hw_Cache_EnableDCache();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CACHE_ENABLE_DCACHE, &Ret);
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_DisableDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_DisableDCache(void)
*  Service ID      : 123
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Turns off D-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_DisableDCache(void)
{
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Platform_Hw_Cache_DisableDCache();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CACHE_DISABLE_DCACHE, &Ret);
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_InvalidateDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_InvalidateDCache(void)
*  Service ID      : 124
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Invalidate D-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_InvalidateDCache(void)
{
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Platform_Hw_Cache_InvalidateDCache();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CACHE_INVALIDATE_DCACHE, &Ret);
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_CleanDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_CleanDCache(void)
*  Service ID      : 125
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Cleans D-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_CleanDCache(void)
{
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
   TT_RetType Ret = TT_RET_SUCCESS;
   Ret = Platform_Hw_Cache_CleanDCache ();
   Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CACHE_CLEAN_DCACHE, &Ret);
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_CleanInvalidateDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_CleanInvalidateDCache(void)
*  Service ID      : 126
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Cleans & Invalidate D-Cache.
******************************************************************************/
TT_RetType Platform_Drv_Cache_CleanInvalidateDCache(void)
{
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Platform_Hw_Cache_CleanInvalidateDCache();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CACHE_CLEAN_INVALIDATE_DCACHE, &Ret);
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_AddrInvalidateDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_AddrInvalidateDCache(void)
*  Service ID      : 127
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : addr  Address
*  Parameters (in) : dsize  Size of memory block (in number of bytes)
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Invalidates D-Cache for the given address.
*                    D-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
*                    D-Cache memory blocks which are part of given address + given size are invalidated.
******************************************************************************/
TT_RetType Platform_Drv_Cache_AddrInvalidateDCache(void * TT_CONST addr, TT_CONST uint32 dsize)
{
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Drv_Cache_PriAddrCheck(addr, dsize);
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Platform_Hw_Cache_AddrInvalidateDCache(addr, dsize);
        Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_INVALIDATE_DCACHE_BY_ADDR, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
    (void)addr;
    (void)dsize;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_AddrCleanDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_AddrCleanDCache(void)
*  Service ID      : 128
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : addr  Address
*  Parameters (in) : dsize  Size of memory block (in number of bytes)
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Cleans D-Cache for the given address.
*                    D-Cache is Cleaned starting from a 32 byte aligned address in 32 byte granularity.
*                    D-Cache memory blocks which are part of given address + given size are invalidated.
******************************************************************************/
TT_RetType Platform_Drv_Cache_AddrCleanDCache(uint32 * TT_CONST addr, TT_CONST uint32 dsize)
{
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Drv_Cache_PriAddrCheck(addr, dsize);
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Platform_Hw_Cache_AddrCleanDCache(addr, dsize);
        Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CLEAN_DCACHE_BY_ADDR, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
    (void)addr;
    (void)dsize;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_AddrCleanInvalidateDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_AddrCleanInvalidateDCache(void)
*  Service ID      : 129
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : addr  Address
*  Parameters (in) : dsize  Size of memory block (in number of bytes)
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Cleans and invalidates D-Cache for the given address.
*                    D-Cache is Cleaned and invalidated starting from a 32 byte aligned address in 32 byte granularity.
*                    D-Cache memory blocks which are part of given address + given size are invalidated.
******************************************************************************/
TT_RetType Platform_Drv_Cache_AddrCleanInvalidateDCache(uint32 * TT_CONST addr, TT_CONST uint32 dsize)
{
#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Drv_Cache_PriAddrCheck(addr, dsize);
    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Platform_Hw_Cache_AddrCleanInvalidateDCache (addr, dsize);
        Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_CLEAN_INVALIDATE_DCACHE_BY_ADDR, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
    (void)addr;
    (void)dsize;
#endif

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_SetRegionConfig
*  Syntax          : TT_RetType Platform_Drv_Mpu_SetRegionConfig(TT_CONST uint8 RegionNum, TT_CONST Platform_Hw_MpuRegionConfigType * TT_CONST pUserConfigPtr)
*  Service ID      : 131
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : u8RegionNum  Region number.
*  Parameters (in) : pUserConfigPtr  Pointer to the region configuration structure for MPU M7.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Configures the region selected by u8RegionNum with the data from pUserConfigPtr.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_SetRegionConfig(TT_CONST uint8 RegionNum, TT_CONST Platform_Hw_MpuRegionConfigType * TT_CONST pUserConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_SetRegionConfig(RegionNum, pUserConfigPtr);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_SET_REGION_CONFIG, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_EnableRegion
*  Syntax          : TT_RetType Platform_Drv_Mpu_EnableRegion(TT_CONST uint8 u8RegionNum, TT_CONST boolean bEnable)
*  Service ID      : 133
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : u8RegionNum  Region to be modified.
*  Parameters (in) : bEnable  Specifies whether the region is enabled or disabled.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Enables or disabled a specific region.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_EnableRegion(TT_CONST uint8 u8RegionNum, TT_CONST boolean bEnable)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_EnableRegion(u8RegionNum, bEnable);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_ENABLE_REGION, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_SetAccessRight
*  Syntax          : TT_RetType Platform_Drv_Mpu_SetAccessRight(TT_CONST uint8 u8RegionNum, TT_CONST Platform_Hw_MpuAccessRightsType eRights)
*  Service ID      : 134
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : u8RegionNum  Region to be modified.
*  Parameters (in) : eRights  Specifies the new access rights.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Modify the access rights for a specific region
******************************************************************************/
TT_RetType Platform_Drv_Mpu_SetAccessRight(TT_CONST uint8 u8RegionNum, TT_CONST Platform_Hw_MpuAccessRightsType eRights)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_SetAccessRight(u8RegionNum, eRights);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_SET_ACCESS_RIGHT, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_GetErrorDetails
*  Syntax          : TT_RetType Platform_Drv_Mpu_GetErrorDetails(Platform_Hw_MpuErrorDetailsType * TT_CONST pErrorDetails, boolean * TT_CONST RetVal)
*  Service ID      : 135
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): pErrorDetails  Storage where the data will be saved.
*  Parameters (out): RetVal
*                     TRUE  If an error was present.
*                     FALSE  Otherwise.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Retrieve error details
******************************************************************************/
TT_RetType Platform_Drv_Mpu_GetErrorDetails(Platform_Hw_MpuErrorDetailsType * TT_CONST pErrorDetails, boolean * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_GetErrorDetails(pErrorDetails, RetVal);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_GET_ERROR_DETAILS, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Enable
*  Syntax          : TT_RetType Platform_Drv_Mpu_Enable(TT_CONST uint32 MPU_Control)
*  Service ID      : 136
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : MPU_Control Default access permissions for unconfigured regions
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Enable the MPU.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_Enable(TT_CONST uint32 MPU_Control)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_Enable(MPU_Control);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_ENABLE, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Disable
*  Syntax          : TT_RetType Platform_Drv_Mpu_Disable(void)
*  Service ID      : 137
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Disable the MPU, must disable MPU first before config MPU.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_Disable(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_Disable();
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_DISABLE, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_ClrRegion
*  Syntax          : TT_RetType Platform_Drv_Mpu_ClrRegion(TT_CONST uint32 rnr)
*  Service ID      : 138
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : rnr  Region number to be cleared.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Clear and disable the given MPU region.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_ClrRegion(TT_CONST uint32 rnr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_ClrRegion(rnr);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_CLR_REGION, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_SetRegion
*  Syntax          : TT_RetType Platform_Drv_Mpu_SetRegion(TT_CONST uint32 rbar, TT_CONST uint32 rasr)
*  Service ID      : 139
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : rbar  Value for RBAR register.
*  Parameters (in) : rasr  Value for RASR register.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Configure an MPU region.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_SetRegion(TT_CONST uint32 rbar, TT_CONST uint32 rasr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_SetRegion(rbar, rasr);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_SET_REGION, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_SetRegionEx
*  Syntax          : TT_RetType Platform_Drv_Mpu_SetRegionEx(TT_CONST uint32 rnr,TT_CONST uint32 rbar,TT_CONST uint32 rasr)
*  Service ID      : 140
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : rnr  Region number to be configured.
*  Parameters (in) : rbar  Value for RBAR register.
*  Parameters (in) : rasr  Value for RASR register.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Configure the given MPU region.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_SetRegionEx(TT_CONST uint32 rnr,TT_CONST uint32 rbar,TT_CONST uint32 rasr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_SetRegionEx(rnr, rbar, rasr);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_SET_REGION_EX, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Load
*  Syntax          : TT_RetType Platform_Drv_Mpu_Load(TT_CONST MPU_Region_t * TT_CONST table, TT_CONST uint32 cnt)
*  Service ID      : 141
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : table  Pointer to the MPU configuration table.
*  Parameters (in) : cnt  Amount of regions to be configured.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Load the given number of MPU regions from a table.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_Load(TT_CONST MPU_Region_t * TT_CONST table, TT_CONST uint32 cnt)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_Load(table, cnt);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_LOAD, &Ret);

    return Ret;
}

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_ConfigRegion
*  Syntax          : TT_RetType Platform_Drv_Mpu_ConfigRegion(TT_CONST Platform_Hw_MpuRegionInitTypeDef * TT_CONST MPU_Init)
*  Service ID      : 142
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : MPU_Init  Pointer to a Platform_Hw_MpuRegionInitTypeDef structure that contains
*                    the initialization and configuration information.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes and configures the Region and the memory to be protected.
******************************************************************************/
TT_RetType Platform_Drv_Mpu_ConfigRegion(TT_CONST Platform_Hw_MpuRegionInitTypeDef * TT_CONST MPU_Init)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_Hw_Mpu_ConfigRegion(MPU_Init);
    Platform_Drv_PriRetCheck(PLATFORM_DRV_SI_MPU_CONFIG_REGION, &Ret);

    return Ret;
}

#if defined (PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
/**
 * @brief       Platform_Drv_Cache_PriAddrCheck
 * @details     Cache address check
 *              D-Cache is cleaned starting from a 32 byte aligned address in 32 byte granularity.
 *              D-Cache memory blocks which are part of given address + given size are cleaned.
 * @param[in]   addr  Address
 * @param[in]   dsize  Size of memory block (in number of bytes)
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
*/
static TT_RetType Platform_Drv_Cache_PriAddrCheck(uint32 * TT_CONST addr, TT_CONST uint32 dsize)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(addr == NULL_PTR, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    (void)dsize;
    if (TT_RET_SUCCESS == Ret)
    {
        /* cacheable sram */
        if (((uint32)addr >= TT_MEM_SRAM_START) && ((uint32)addr < (TT_MEM_SRAM_START + TT_MEM_SRAM_SIZE)))
        {
            if (((uint32)addr >= (uint32)__RAM_NO_CACHEABLE_START) && ((uint32)addr < (uint32)__RAM_NO_CACHEABLE_END))
            {
                Ret = TT_RET_PARAM_ADDR_ERR;
            }
            else
            {
                Ret = TT_RET_SUCCESS;
            }
        }
        /* pflash */
        else if (((uint32)addr >= PFLASH_BASE) && ((uint32)addr < (PFLASH_BASE + PFLASH_SIZE)))
        {
            Ret = TT_RET_SUCCESS;
        }
        /* dflash */
        else if (((uint32)addr >= DFLASH_BASE) && ((uint32)addr < (DFLASH_BASE + DFLASH_SIZE)))
        {
            Ret = TT_RET_SUCCESS;
        }
        else
        {
            Ret = TT_RET_PARAM_ADDR_ERR;
        }

    }

    return Ret;
}
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/
#define PLATFORM_START_SEC_CODE_FAST
#include "Platform_MemMap.h"
/**
* @brief         Platform_Drv_PriParaCheck
* @details       Reports Det error if PLATFORM_DEV_ERROR_DETECT == STD_ON
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Platform_Drv_PriParaCheck(bool Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(PLATFORM_DRV_TT_STATUS_DEFAULT(ApiId), ErrId);
#if defined(PLATFORM_DEV_ERROR_DETECT) && (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(PLATFORM_MODULE_ID, ApiId, ErrId);
            ModuleDet_ReportError(PLATFORM_MODULE_ID, PLATFORM_INSTANCE_ID, ApiId, (uint8)ErrId);
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
}

/**
* @brief         Platform_Drv_PriRetCheck
* @details       Reports Return Value error if PLATFORM_DEV_ERROR_DETECT == STD_ON
* @param[in]     ApiId - Service Id of API
* @param[out]    ErrId - Error Id of Condition
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Platform_Drv_PriRetCheck(uint8 ApiId, TT_RetType *ErrId)
{
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
#if defined(PLATFORM_DEV_ERROR_DETECT) && (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(PLATFORM_MODULE_ID, ApiId, *ErrId);
            ModuleDet_ReportError(PLATFORM_MODULE_ID, PLATFORM_INSTANCE_ID, ApiId, (uint8)((*ErrId) & (0xFFU)));
#endif
            *ErrId = TT_SET_STATUS_TYPE(PLATFORM_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
        }
        else
        {
            /* nothing */
        }
    }
    else
    {
        /* nothing */
    }
}
#define PLATFORM_STOP_SEC_CODE_FAST
#include "Platform_MemMap.h"

#define PLATFORM_START_SEC_CODE_SLOW
#include "Platform_MemMap.h"

#if (TT_SAFETY == STD_ON)
/**
* @brief        Platform_PriInitCheck
* @details      Check Platform Config
* @param[in]    pConfig  Pointer to a CONSTant Platform module setting
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Platform_PriInitCheck(TT_CONST Platform_Drv_ConfigType * TT_CONST pConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Platform_PriIrqInitCheck(pConfig->IntCtrlConfig);

    return Ret;
}

/**
* @brief        Platform_PriIrqInitCheck(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig)
* @details      Initializes the configured interrupts at interrupt controller level.
* @param[in]    pConfig  Pointer to a CONSTant IntCtrl setting
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Platform_PriIrqInitCheck(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 irqIdx = 0U;
    uint32 RetVal = 0U;
    uint8 PriorityRet = 0U;
    uint8 Tmp = 0U;

    TT_ParaCheck((pIntCtrlCtrlConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((pIntCtrlCtrlConfig != NULL_PTR) && (pIntCtrlCtrlConfig->ConfigIrqCount > PLATFORM_INT_CTRL_IRQ_COUNT), TT_RET_PARAM_COUNT_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Platform_Drv_IntCtrl_GroupingGetPriority(&RetVal);
        if ((Ret == TT_RET_SUCCESS) && (RetVal == (7U - PLATFORM_INT_CTRL_GROUP_BITS)))
        {
            for (irqIdx = 0; irqIdx < pIntCtrlCtrlConfig->ConfigIrqCount; irqIdx++)
            {
                Tmp = (pIntCtrlCtrlConfig->IrqConfig[irqIdx].PreemptionPriority << (8U - PLATFORM_INT_CTRL_GROUP_BITS)) \
                            + ((0xFFU >> PLATFORM_INT_CTRL_GROUP_BITS) & pIntCtrlCtrlConfig->IrqConfig[irqIdx].SubPriority);
                Ret = Platform_Drv_IntCtrl_GetPriority(pIntCtrlCtrlConfig->IrqConfig[irqIdx].IrqNumber, &PriorityRet);
                if ((Ret != TT_RET_SUCCESS) || (Tmp != PriorityRet))
                {
                    Ret = TT_RET_STATUS_INITCHECK_ERR;
                    break;
                }
                else
                {
                    Ret = Platform_Drv_IntCtrl_GetEnableIRQ(pIntCtrlCtrlConfig->IrqConfig[irqIdx].IrqNumber, &RetVal);
                    if ((Ret != TT_RET_SUCCESS) || ((uint32)pIntCtrlCtrlConfig->IrqConfig[irqIdx].IrqEnabled != RetVal))
                    {
                        Ret = TT_RET_STATUS_INITCHECK_ERR;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        else
        {
            Ret = TT_RET_STATUS_INITCHECK_ERR;
        }

    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief         Platform_PriCalcCustomCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     Non
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static uint32 Platform_PriCalcCfgCrc(TT_CONST Platform_Drv_ConfigType * TT_CONST pConfig)
{
   /* Reset the accumulated CRC value */
    uint32 u32AccCRCremainder=0;

    if(pConfig->IntCtrlConfig != NULL_PTR)
    {
        for(uint32 i=0;i<pConfig->IntCtrlConfig->ConfigIrqCount;i++)
        {
            Base_AccumulateCRC((uint32)pConfig->IntCtrlConfig->IrqConfig[i].IrqNumber, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)pConfig->IntCtrlConfig->IrqConfig[i].IrqEnabled, &u32AccCRCremainder);
            Base_AccumulateCRC(pConfig->IntCtrlConfig->IrqConfig[i].PreemptionPriority, &u32AccCRCremainder);
            Base_AccumulateCRC(pConfig->IntCtrlConfig->IrqConfig[i].SubPriority, &u32AccCRCremainder);
        }
        Base_AccumulateCRC(pConfig->IntCtrlConfig->ConfigIrqCount, &u32AccCRCremainder);
    }

    if(pConfig->MpuConfig != NULL_PTR)
    {
        if(pConfig->MpuConfig->RegionConfigArr != NULL_PTR)
        {
            for(uint32 i=0;i<pConfig->MpuConfig->RegionCnt;i++)
            {
                Base_AccumulateCRC(pConfig->MpuConfig->RegionConfigArr[i].RegionNum, &u32AccCRCremainder);
                Base_AccumulateCRC(pConfig->MpuConfig->RegionConfigArr[i].StartAddr, &u32AccCRCremainder);
                Base_AccumulateCRC(pConfig->MpuConfig->RegionConfigArr[i].EndAddr, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)pConfig->MpuConfig->RegionConfigArr[i].MemType, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)pConfig->MpuConfig->RegionConfigArr[i].AccessRight, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)pConfig->MpuConfig->RegionConfigArr[i].OuterCachePolicy, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)pConfig->MpuConfig->RegionConfigArr[i].InnerCachePolicy, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)pConfig->MpuConfig->RegionConfigArr[i].SubRegMask, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)pConfig->MpuConfig->RegionConfigArr[i].Shareable, &u32AccCRCremainder);
            }
        }
        Base_AccumulateCRC((uint32)pConfig->MpuConfig->DefaultMapEn, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)pConfig->MpuConfig->EnableRunHFNMI, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)pConfig->MpuConfig->EnMemManageInterrupt, &u32AccCRCremainder);
        Base_AccumulateCRC(pConfig->MpuConfig->RegionCnt, &u32AccCRCremainder);
    }

    return ((uint32)Base_FinalizeCRC(&u32AccCRCremainder));
}

#endif /* TT_SAFETY */


#define PLATFORM_STOP_SEC_CODE_SLOW
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
