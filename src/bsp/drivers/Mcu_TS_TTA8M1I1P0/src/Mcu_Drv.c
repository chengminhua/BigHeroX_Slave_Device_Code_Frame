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
**  FILENAME     : Mcu_Drv.c                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Mcu Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcu_Drv.h"
#include "Mcu_Hw_Clk.h"
#include "Mcu_Hw_Cmu.h"
#include "Mcu_Hw_Rtc.h"
#include "Mcu_Hw_Ppu.h"
#include "Mcu_Hw_Pmu.h"
#include "Mcu_Hw_Misc.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_DRV_VENDOR_ID_C                     1541
#define MCU_DRV_MODULE_ID_C                     101
#define MCU_DRV_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_DRV_AR_RELEASE_MINOR_VERSION_C      4
#define MCU_DRV_AR_RELEASE_PATCH_VERSION_C      0
#define MCU_DRV_SW_MAJOR_VERSION_C              1
#define MCU_DRV_SW_MINOR_VERSION_C              1
#define MCU_DRV_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Drv.c and Mcu_Drv.h file version check */
#if (MCU_DRV_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Mcu_Drv.c and Mcu_Drv.h have different vendor id"
#endif
#if (MCU_DRV_MODULE_ID_C != MCU_DRV_MODULE_ID_H)
    #error "Mcu_Drv.c and Mcu_Drv.h have different module id"
#endif
#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.c and Mcu_Drv.h are different"
#endif
#if ((MCU_DRV_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (MCU_DRV_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.c and Mcu_Drv.h are different"
#endif

/* Mcu_Drv.c and Mcu_Hw_Clk.h file version check */
#if (MCU_DRV_VENDOR_ID_C != MCU_HW_CLK_VENDOR_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Clk.h have different vendor id"
#endif
#if (MCU_DRV_MODULE_ID_C != MCU_HW_CLK_MODULE_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Clk.h have different module id"
#endif
#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.c and Mcu_Hw_Clk.h are different"
#endif
#if ((MCU_DRV_SW_MAJOR_VERSION_C != MCU_HW_CLK_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_SW_MINOR_VERSION_C != MCU_HW_CLK_SW_MINOR_VERSION_H) || \
     (MCU_DRV_SW_PATCH_VERSION_C != MCU_HW_CLK_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.c and Mcu_Hw_Clk.h are different"
#endif

/* Mcu_Drv.c and Mcu_Hw_Cmu.h file version check */
#if (MCU_DRV_VENDOR_ID_C != MCU_HW_CMU_VENDOR_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Cmu.h have different vendor id"
#endif
#if (MCU_DRV_MODULE_ID_C != MCU_HW_CMU_MODULE_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Cmu.h have different module id"
#endif
#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_CMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_HW_CMU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_HW_CMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.c and Mcu_Hw_Cmu.h are different"
#endif
#if ((MCU_DRV_SW_MAJOR_VERSION_C != MCU_HW_CMU_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_SW_MINOR_VERSION_C != MCU_HW_CMU_SW_MINOR_VERSION_H) || \
     (MCU_DRV_SW_PATCH_VERSION_C != MCU_HW_CMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.c and Mcu_Hw_Cmu.h are different"
#endif

/* Mcu_Drv.c and Mcu_Hw_Rtc.h file version check */
#if (MCU_DRV_VENDOR_ID_C != MCU_HW_RTC_VENDOR_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Rtc.h have different vendor id"
#endif
#if (MCU_DRV_MODULE_ID_C != MCU_HW_RTC_MODULE_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Rtc.h have different module id"
#endif
#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_RTC_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_HW_RTC_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_HW_RTC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.c and Mcu_Hw_Rtc.h are different"
#endif
#if ((MCU_DRV_SW_MAJOR_VERSION_C != MCU_HW_RTC_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_SW_MINOR_VERSION_C != MCU_HW_RTC_SW_MINOR_VERSION_H) || \
     (MCU_DRV_SW_PATCH_VERSION_C != MCU_HW_RTC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.c and Mcu_Hw_Rtc.h are different"
#endif

/* Mcu_Drv.c and Mcu_Hw_Ppu.h file version check */
#if (MCU_DRV_VENDOR_ID_C != MCU_HW_PPU_VENDOR_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Ppu.h have different vendor id"
#endif
#if (MCU_DRV_MODULE_ID_C != MCU_HW_PPU_MODULE_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Ppu.h have different module id"
#endif
#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_PPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_HW_PPU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_HW_PPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.c and Mcu_Hw_Ppu.h are different"
#endif
#if ((MCU_DRV_SW_MAJOR_VERSION_C != MCU_HW_PPU_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_SW_MINOR_VERSION_C != MCU_HW_PPU_SW_MINOR_VERSION_H) || \
     (MCU_DRV_SW_PATCH_VERSION_C != MCU_HW_PPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.c and Mcu_Hw_Ppu.h are different"
#endif

/* Mcu_Drv.c and Mcu_Hw_Pmu.h file version check */
#if (MCU_DRV_VENDOR_ID_C != MCU_HW_PMU_VENDOR_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Pmu.h have different vendor id"
#endif
#if (MCU_DRV_MODULE_ID_C != MCU_HW_PMU_MODULE_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Pmu.h have different module id"
#endif
#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.c and Mcu_Hw_Pmu.h are different"
#endif
#if ((MCU_DRV_SW_MAJOR_VERSION_C != MCU_HW_PMU_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_SW_MINOR_VERSION_C != MCU_HW_PMU_SW_MINOR_VERSION_H) || \
     (MCU_DRV_SW_PATCH_VERSION_C != MCU_HW_PMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.c and Mcu_Hw_Pmu.h are different"
#endif

/* Mcu_Drv.c and Mcu_Hw_Misc.h file version check */
#if (MCU_DRV_VENDOR_ID_C != MCU_HW_MISC_VENDOR_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Misc.h have different vendor id"
#endif
#if (MCU_DRV_MODULE_ID_C != MCU_HW_MISC_MODULE_ID_H)
    #error "Mcu_Drv.c and Mcu_Hw_Misc.h have different module id"
#endif
#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.c and Mcu_Hw_Misc.h are different"
#endif
#if ((MCU_DRV_SW_MAJOR_VERSION_C != MCU_HW_MISC_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_SW_MINOR_VERSION_C != MCU_HW_MISC_SW_MINOR_VERSION_H) || \
     (MCU_DRV_SW_PATCH_VERSION_C != MCU_HW_MISC_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.c and Mcu_Hw_Misc.h are different"
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
#define MCU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"

static boolean McuDrv_PubCmuInited = (boolean)FALSE;   /* Cmu init flag */
static boolean McuDrv_PubRtcInited = (boolean)FALSE;   /* Rtc init flag */
static boolean McuDrv_PubClkInited = (boolean)FALSE;   /* Clock init flag */

#define MCU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#define MCU_START_SEC_CODE_FAST
#include "Mcu_MemMap.h"
/**
* @brief         Mcu_Drv_PriParaCheck
* @details       Reports Det error if MCU_DEV_ERROR_DETECT == STD_ON
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        TT_RetType         
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Mcu_Drv_PriParaCheck(bool Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal);

/**
* @brief         Mcu_Drv_PriRetCheck
* @details       Reports Return Value error if MCU_DEV_ERROR_DETECT == STD_ON
* @param[in]     ApiId - Service Id of API
* @param[out]    ErrId - Error Id of Condition
* @return        TT_RetType         
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Mcu_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId);

#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define MCU_START_SEC_CODE_SLOW
#include "Mcu_MemMap.h"
/******************************************************************************
*  Service name    : Mcu_Drv_Cmu_Init
*  Syntax          : TT_RetType Mcu_Drv_Cmu_Init(TT_CONST Mcu_CmuConfigType * TT_CONST CmuConfig)
*  Service ID      : 112U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : CmuItem : Cmu configuration
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This service initialize cmu
********************************************************************************/
TT_RetType Mcu_Drv_Cmu_Init(TT_CONST Mcu_Hw_CmuConfigType * TT_CONST CmuConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubCmuInited == TRUE, MCU_DRV_SI_CMU_INIT, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Hw_Cmu_Init(CmuConfig);
        if (Ret == TT_RET_SUCCESS)
        {
            McuDrv_PubCmuInited = TRUE;
        }
        else
        {
            /* do nothing */
        }
        Mcu_Drv_PriRetCheck(MCU_DRV_SI_CMU_INIT, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Rtc_Init
*  Syntax          : TT_RetType  Mcu_Drv_Rtc_Init(TT_CONST Rtc_ConfigType * TT_CONST RtcConfig)
*  Service ID      : 116U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : RtcConfig : Rtc configuration
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This service initialize Rtc
********************************************************************************/
TT_RetType  Mcu_Drv_Rtc_Init(TT_CONST Rtc_ConfigType * TT_CONST RtcConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubRtcInited == TRUE, MCU_DRV_SI_RTC_INIT, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
       Ret = Mcu_Hw_Rtc_Init(RtcConfig);
       if (Ret == TT_RET_SUCCESS)
       {
           McuDrv_PubRtcInited = TRUE;
       }
       else
       {
           /* do nothing */
       }
       Mcu_Drv_PriRetCheck( MCU_DRV_SI_RTC_INIT, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_Init
*  Syntax          : TT_RetType Mcu_Drv_Clk_Init(TT_CONST Mcu_Hw_ClockSettingConfigType * TT_CONST ClockCfgPtr)
*  Service ID      : 100U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : ClockCfgPtr : clock configuration
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This service initialize clock
********************************************************************************/
TT_RetType Mcu_Drv_Clk_Init(TT_CONST Mcu_Hw_ClockSettingConfigType * TT_CONST ClockCfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubClkInited == TRUE, MCU_DRV_SI_CLK_INIT, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Hw_Clk_Init(ClockCfgPtr);

        if (Ret == TT_RET_SUCCESS)
        {
            McuDrv_PubClkInited = TRUE;
        }
        else
        {
            /* do nothing */
        }
        Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_INIT, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*  Service name    : Mcu_Drv_Cmu_Start
*  Syntax          : TT_RetType Mcu_Drv_Cmu_Start(TT_CONST uint8 num, TT_CONST MCU_CMU_ALARM_TYPE AlarmType)
*  Service ID      : 113U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : num : The number of cmu
                     AlarmType : Cmu alarm type
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Service to start MCU Cmu
******************************************************************************/
TT_RetType Mcu_Drv_Cmu_Start(TT_CONST uint8 num, TT_CONST uint32 AlarmType)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubCmuInited != TRUE, MCU_DRV_SI_CMU_START, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Hw_Cmu_Start(num, AlarmType);
        Mcu_Drv_PriRetCheck( MCU_DRV_SI_CMU_START, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Cmu_Stop
*  Syntax          : TT_RetType Mcu_Drv_Cmu_Stop(TT_CONST uint8 num, TT_CONST MCU_CMU_ALARM_TYPE AlarmType)
*  Service ID      : 114U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : num : The number of cmu
                     AlarmType : Cmu alarm type
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Service to stop  Cmu
******************************************************************************/
TT_RetType Mcu_Drv_Cmu_Stop(TT_CONST uint8 num, TT_CONST uint32 AlarmType)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubCmuInited != TRUE, MCU_DRV_SI_CMU_STOP, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Hw_Cmu_Stop(num, AlarmType);
        Mcu_Drv_PriRetCheck( MCU_DRV_SI_CMU_STOP, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Ppu_Control
*  Syntax          : TT_RetType Mcu_Drv_Ppu_Control(TT_CONST boolean Access, TT_CONST boolean UserMode, TT_CONST PPU_CONTROL_Type Type)
*  Service ID      : 115U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : Access - periph can be access yes or no by cpu
*  Parameters (in) : UserMode - true:User mode, false: privilege
*  Parameters (in) : Type - periph type
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Ppu control periph access and user/privilege mode.
******************************************************************************/
TT_RetType Mcu_Drv_Ppu_Control(TT_CONST boolean Access, TT_CONST boolean UserMode, TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck((Access != TRUE)&&(Access != FALSE), MCU_DRV_SI_PPU_CONTROL, TT_RET_PARAM_ERR, &Ret);
    Mcu_Drv_PriParaCheck((UserMode != TRUE)&&(UserMode != FALSE), MCU_DRV_SI_PPU_CONTROL, TT_RET_PARAM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if (Access == TRUE)
        {
            Ret = Mcu_Hw_Ppu_EnAccessControl(Type);
        }
        else
        {
            Ret = Mcu_Hw_Ppu_DisAccessControl(Type);
        }

        if (TT_RET_SUCCESS == Ret)
        {
            if (UserMode == TRUE)
            {
                Ret =  Mcu_Hw_Ppu_EnUserAccess(Type);
            }
            else
            {
                Ret =  Mcu_Hw_Ppu_DisUserAccess(Type);
            }
        }
        else
        {
            /* do nothing */
        }

        Mcu_Drv_PriRetCheck( MCU_DRV_SI_PPU_CONTROL, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Ppu_GetErrStatus
*  Syntax          : TT_RetType Mcu_Drv_Ppu_GetErrStatus(TT_CONST PPU_CONTROL_Type Type,uint32 *Status)
*  Service ID      : 133U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - the moudle will be enable user access
*  Parameters (out): Status - error status
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Ppu get error Status.
******************************************************************************/
TT_RetType Mcu_Drv_Ppu_GetErrStatus(TT_CONST PPU_CONTROL_Type Type,uint32 *Status)
{
    TT_RetType Ret = TT_RET_SUCCESS;

	Ret =  Mcu_Hw_Ppu_GetErrStatus(Type,Status);
	Mcu_Drv_PriRetCheck( MCU_DRV_SI_PPU_GETERRSTATUS, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Ppu_ClearErrStatus
*  Syntax          : TT_RetType Mcu_Drv_Ppu_ClearErrStatus(TT_CONST PPU_CONTROL_Type Type)
*  Service ID      : 134U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - the moudle will be enable user access
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Ppu Clear error Status
******************************************************************************/
TT_RetType Mcu_Drv_Ppu_ClearErrStatus(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret =  Mcu_Hw_Ppu_ClearErrStatus(Type);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PPU_CLEARERRSTATUS, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Rtc_Start
*  Syntax          : TT_RetType  Mcu_Drv_Rtc_Start(TT_CONST uint32 RtcValue, TT_CONST uint32 ApiValue)
*  Service ID      : 117U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : RtcValue - Rtc comparison values
*  Parameters (in) : ApiValue - The period value of the Rtc interval
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Start Rtc.
******************************************************************************/
TT_RetType  Mcu_Drv_Rtc_Start(TT_CONST uint32 RtcValue, TT_CONST uint32 ApiValue)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubRtcInited != TRUE, MCU_DRV_SI_RTC_START, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
       Ret = Mcu_Hw_Rtc_Start(RtcValue, ApiValue);
       Mcu_Drv_PriRetCheck( MCU_DRV_SI_RTC_START, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Rtc_GetState
*  Syntax          : TT_RetType Mcu_Drv_Rtc_GetState(uint32 *Status)
*  Service ID      : 118U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : None
*  Parameters (out): Status - Status of Rtc
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get Rtc status.
******************************************************************************/
TT_RetType Mcu_Drv_Rtc_GetState(uint32 *Status)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubRtcInited != TRUE, MCU_DRV_SI_RTC_GET_STATUE, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Hw_Rtc_GetState(Status);
        Mcu_Drv_PriRetCheck( MCU_DRV_SI_RTC_START, &Ret);
    }
    else
    {
        /* do nothing */
    }    

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Rtc_Clear
*  Syntax          : TT_RetType  Mcu_Drv_Rtc_Clear(TT_CONST uint32 flag)
*  Service ID      : 119U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : flag - Reset value of the register
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Clear Rtc register.
******************************************************************************/
TT_RetType  Mcu_Drv_Rtc_Clear(TT_CONST uint32 flag)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubRtcInited != TRUE, MCU_DRV_SI_RTC_CLEAR, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
       Ret = Mcu_Hw_Rtc_Clear(flag);
       Mcu_Drv_PriRetCheck(MCU_DRV_SI_RTC_CLEAR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Misc_LocalResetModules
*  Syntax          : TT_RetType Mcu_Drv_Misc_LocalResetModules(TT_CONST TT_SCU_LOCAL_RST_Type Type)
*  Service ID      : 120U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - The Module will be local reset
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Mcu control modules local reset
******************************************************************************/
TT_RetType Mcu_Drv_Misc_LocalResetModules(TT_CONST TT_SCU_LOCAL_RST_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Misc_LocalResetModules(Type);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_MISC_LOCAL_RESET_MODUlES, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Misc_PerformReset
*  Syntax          : TT_RetType Mcu_Drv_Misc_PerformReset(void)
*  Service ID      : 121U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : The service performs a microcontroller reset.
******************************************************************************/
TT_RetType Mcu_Drv_Misc_PerformReset(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Misc_PerformReset();
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_GET_USER_VALUE, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_GetUserValue
*  Syntax          : TT_RetType Mcu_Drv_Pmu_GetUserValue(TT_CONST uint32 Index, uint32 *Value)
*  Service ID      : 122U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Index - Register hardware unit
*  Parameters (out): Value - The value of the user register
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get The value of the user register.
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_GetUserValue(TT_CONST uint32 Index, uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_GetUserValue(Index, Value);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_GET_USER_VALUE, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_SetUserValue
*  Syntax          : TT_RetType Mcu_Drv_Pmu_SetUserValue(TT_CONST uint32 Value, TT_CONST uint32 Index)
*  Service ID      : 123U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Value - The value of the user register
*  Parameters (in) : Index - Register hardware unit
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Set The value of the user register.
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_SetUserValue(TT_CONST uint32 Value, TT_CONST uint32 Index)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_SetUserValue(Value, Index);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_SET_USER_VALUE, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_LocalReset
*  Syntax          : TT_RetType Mcu_Drv_Pmu_LocalReset(void)
*  Service ID      : 124U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Pmu local reset.
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_LocalReset(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_LocalReset();
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_LOCAL_RESET, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_ConfigNmi
*  Syntax          : TT_RetType Mcu_Drv_Pmu_ConfigNmi(TT_CONST Mcu_Hw_PmuNmiConfigType *PmuNmiConfig)
*  Service ID      : 125U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : PmuNmiConfig - Nmi configuration
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Nmi configuration.
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_ConfigNmi(TT_CONST Mcu_Hw_PmuNmiConfigType *PmuNmiConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_ConfigNmi(PmuNmiConfig);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_CONFIG_NMI, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_ConfigGpio
*  Syntax          : TT_RetType Mcu_Drv_Pmu_ConfigGpio(TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig)
*  Service ID      : 126U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : PmuGpioConfig - Gpio configuration
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Gpio configuration.
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_ConfigGpio(TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_ConfigGpio(PmuGpioConfig);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_CONFIG_GPIO, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_GetResetRawValue
*  Syntax          : TT_RetType Mcu_Drv_Pmu_GetResetRawValue(uint32 *Value)
*  Service ID      : 127U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): Value - Reset raw value
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get reset raw value
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_GetResetRawValue(uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_GetResetRawValue(Value);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_GET_RESET_RAW_VALUe, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_GetResetReason
*  Syntax          : TT_RetType Mcu_Drv_Pmu_GetResetReason(uint32 *Value)
*  Service ID      : 128U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): Value - Reset reason
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get reset reason
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_GetResetReason(uint32 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_GetResetReason(Value);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_GET_RESET_REASON, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_EnterStandby
*  Syntax          : TT_RetType Mcu_Drv_Pmu_EnterStandby(void)
*  Service ID      : 129U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     :  cpu enter standby mode
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_EnterStandby(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_EnterStandby();
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_ENTER_STANDBY, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_EnterSleep
*  Syntax          : TT_RetType Mcu_Drv_Pmu_EnterSleep(TT_CONST uint32 OscDiv)
*  Service ID      : 130U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : OscDiv - cpu run in osc clock by div
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : cpu enter sleep mode
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_EnterSleep(TT_CONST uint32 OscDiv)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_EnterSleep(OscDiv);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_ENTER_SLEEP, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_ConfigMode
*  Syntax          : TT_RetType Mcu_Drv_Pmu_ConfigMode(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig)
*  Service ID      : 131U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : McuModeSettingConfig - Mode setting configuration
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Service to Set MCU Lowe Power Mode
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_ConfigMode(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig)
{
    TT_RetType  Ret = TT_RET_SUCCESS;
    TT_RetType  Ret1 = TT_RET_SUCCESS;
    uint32      Count   = 0U;

    Mcu_Drv_PriParaCheck((McuModeSettingConfig == NULL_PTR), MCU_DRV_SI_PMU_CONFIG_MODE, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        for (Count = 0; Count < McuModeSettingConfig->PmuGpioConfigCount; Count++)
        {
            Ret = Mcu_Hw_Pmu_ConfigGpio(&McuModeSettingConfig->PmuGpioConfig[Count]);
            if (Ret != TT_RET_SUCCESS)
            {
                break;
            }
            else
            {
                continue;
            }
        }

        for (Count = 0; Count < McuModeSettingConfig->PmuNmiConfigCount; Count++)
        {
            Ret1 = Mcu_Hw_Pmu_ConfigNmi(&McuModeSettingConfig->PmuNmiConfig[Count]);
            if (Ret1 != TT_RET_SUCCESS)
            {
                break;
            }
            else
            {
                continue;
            }
        }

        if ((Ret == TT_RET_SUCCESS)&&(Ret1 == TT_RET_SUCCESS))
        {
            Ret = Mcu_Hw_Pmu_ConfigMode(McuModeSettingConfig);
        }
        else if(Ret == TT_RET_SUCCESS)
        {
            Ret = Ret1;
        }
        else
        {
            /* do nothing */
        }

        Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_CONFIG_MODE, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_SetCallBack
*  Syntax          : TT_RetType Mcu_Drv_Pmu_SetCallBack(TT_Notification callback)
*  Service ID      : 132U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : callback function name
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Set Callback function
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_SetCallBack(TT_Notification callback)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_SetCallBack(callback);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_CONFIG_CB, &Ret);

    return Ret;
}


#ifdef A8V2E
/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_SetHsmCipPowerDown
*  Syntax          : TT_RetType Mcu_Drv_Pmu_SetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,TT_CONST boolean Enable)
*  Service ID      : 135U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : Type - Hsm or Cipher
*  Parameters (in) : Enable - TRUE  :Power Down
*                        - FALSE :Power up
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Service to Set Hsm and Cipher Power Mode
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_SetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,TT_CONST boolean Enable)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_SetHsmCipPowerDown(Type,Enable);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_SETHSMCIPPOWERDOWN, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_GetHsmCipPowerDown
*  Syntax          : TT_RetType Mcu_Drv_Pmu_GetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,uint32* Enable)
*  Service ID      : 136U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : Type - Hsm or Cipher
*  Parameters (out) : Enable - TRUE  :Power Down
*                        - FALSE :Power up
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Service to Get Hsm and Cipher Power Down Status
******************************************************************************/
TT_RetType Mcu_Drv_Pmu_GetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,uint32* Enable)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Pmu_GetHsmCipPowerDown(Type,Enable);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_PMU_GETHSMCIPPOWERDOWN, &Ret);

    return Ret;
}
#endif

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_GetPeriph
*  Syntax          : TT_RetType Mcu_Drv_Clk_GetPeriph(TT_CONST Mcu_Hw_PeriphNameType PeripheralName, Mcu_PeripheralClockValType *Clk)
*  Service ID      : 101U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : PeripheralName - the dest Peripheral in Mcu_PeriphNameType
*  Parameters (out): Clk - the dest Peripheral clock
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get peripheral clock
******************************************************************************/
TT_RetType Mcu_Drv_Clk_GetPeriph(TT_CONST Mcu_Hw_PeriphNameType PeripheralName, Mcu_PeripheralClockValType *Clk)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck((!MCU_CLK_PERIPHNAME_TYPE_ASSERT(PeripheralName)), MCU_DRV_SI_CLK_GET_PERIPH, TT_RET_PARAM_ENUM_ERR, &Ret);
    Mcu_Drv_PriParaCheck(Clk == NULL_PTR, MCU_DRV_SI_CLK_GET_PERIPH, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if (MCU_CLOCK_SYSTEM == PeripheralName)
        {
            Ret = Mcu_Hw_Clk_GetSystem(Clk);
        }
        else if (MCU_CLOCK_BUS == PeripheralName)
        {
            Ret = Mcu_Hw_Clk_GetBus(Clk);
        }
        else if (MCU_CLOCK_MPLL == PeripheralName)
        {
            Ret = Mcu_Hw_Clk_GetMpll(Clk);
        }
        else if (MCU_CLOCK_EPLL == PeripheralName)
        {
            Ret = Mcu_Hw_Clk_GetEpll(Clk);
        }
        /* AHB0 - AHB4 */
        else if (((uint32)PeripheralName >= (uint32)MCU_CLOCK_AHB0) && ((uint32)PeripheralName <= (uint32)MCU_CLOCK_GTMAXIS))
        {
            Ret = Mcu_Hw_Clk_GetBus(Clk);
        }
        else
        {
            Ret = Mcu_Hw_Clk_GetPeriph(PeripheralName, Clk);
        }

        Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_GET_PERIPH, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_PllConfig
*  Syntax          : TT_RetType Mcu_Drv_Clk_PllConfig (TT_CONST uint32 PllClock, TT_CONST Mcu_Hw_PllType PllType)
*  Service ID      : 102U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : PllClock - the dest pll clock
*  Parameters (in) : PllType - Choose MPLL of EPLL
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Mcu Main Pll Config
******************************************************************************/
TT_RetType Mcu_Drv_Clk_PllConfig (TT_CONST uint32 PllClock, TT_CONST Mcu_Hw_PllType PllType)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Mcu_Drv_PriParaCheck(McuDrv_PubClkInited != TRUE, MCU_DRV_SI_CLK_PLL_CONFIG, TT_RET_STATUS_INIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        switch (PllType)
        {
            case MCU_MPLL_TYPE:
                Ret = Mcu_Hw_Clk_MpllConfig(PllClock);
                break;
            case MCU_EPLL_TYPE:
                Ret = Mcu_Hw_Clk_EpllConfig(PllClock);
                break;
            default:
                /* default */
                Ret = TT_RET_PARAM_ENUM_ERR;
                break;
        }
        Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_PLL_CONFIG, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_StopModules
*  Syntax          : TT_RetType Mcu_Drv_Clk_StopModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type)
*  Service ID      : 104U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - The Module will be clock stop
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Mcu control module clk stop
******************************************************************************/
TT_RetType Mcu_Drv_Clk_StopModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Clk_StopModules(Type);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_STOP_MODULES, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_StartModules
*  Syntax          : TT_RetType Mcu_Drv_Clk_StartModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type)
*  Service ID      : 105U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - The Module will be clock start
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Mcu control module clk start
******************************************************************************/
TT_RetType Mcu_Drv_Clk_StartModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Clk_StartModules(Type);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_START_MODULES, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_StatusModules
*  Syntax          : TT_RetType Mcu_Drv_Clk_StatusModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type, boolean *Status)
*  Service ID      : 106U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - The Module will be get the status
*  Parameters (out): Status - the clock status of this module
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Mcu control module clk status
******************************************************************************/
TT_RetType Mcu_Drv_Clk_StatusModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type, boolean *Status)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Clk_StatusModules(Type, Status);
//    Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_STATUS_MODULES, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_SleepModules
*  Syntax          : TT_RetType Mcu_Drv_Clk_SleepModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type)
*  Service ID      : 107U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - The Module will be clock sleep
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Mcu control module clk sleep
******************************************************************************/
TT_RetType Mcu_Drv_Clk_SleepModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Clk_SleepModules(Type);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_SLEEP_MODULES, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_AwakenModules
*  Syntax          : TT_RetType Mcu_Drv_Clk_AwakenModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type)
*  Service ID      : 108U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - The Module will be clock sleep
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Mcu control module clk awaken
******************************************************************************/
TT_RetType Mcu_Drv_Clk_AwakenModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Clk_AwakenModules(Type);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_SLEEP_MODULES, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_PeriStopModules
*  Syntax          : TT_RetType Mcu_Drv_Clk_PeriStopModules(TT_CONST TT_SCU_PERI_STOP_Type Type)
*  Service ID      : 109U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Type - The Module will be clock stop
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : mcu Stop Peril module
******************************************************************************/
TT_RetType Mcu_Drv_Clk_PeriStopModules(TT_CONST TT_SCU_PERI_STOP_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Hw_Clk_PeriStopModules(Type);
    Mcu_Drv_PriRetCheck( MCU_DRV_SI_CLK_PERI_STOP_MODULES, &Ret);

    return Ret;
}

/******************************************************************************
*  Service name    : Mcu_Drv_Clk_GetPllStatus
*  Syntax          : TT_RetType Mcu_Drv_Clk_GetPllStatus(uint8 *Value)
*  Service ID      : 110U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): Value - Status of Pll clock
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This service provides the lock status of the PLL.
******************************************************************************/
TT_RetType Mcu_Drv_Clk_GetPllStatus(uint8 *Value)
{
    TT_RetType Ret        = TT_RET_SUCCESS;
    TT_RetType Ret1       = TT_RET_SUCCESS;
    uint8 MPllValue       = 0;
    uint8 EPllValue       = 0;

    Mcu_Drv_PriParaCheck((Value == NULL_PTR), MCU_DRV_SI_CLk_GET_PLL_STATUS, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Hw_Clk_GetMPllStatus(&MPllValue);
        Ret1 = Mcu_Hw_Clk_GetEPllStatus(&EPllValue);
        if ((TT_RET_SUCCESS == Ret) && (TT_RET_SUCCESS == Ret1) && \
                (MPllValue == (uint8)MCU_CLK_PLL_LOCKED) && (EPllValue == (uint8)MCU_CLK_PLL_LOCKED))
        {
            *Value = (uint8)MCU_CLK_PLL_LOCKED;
        }
        else
        {
            *Value = (uint8)MCU_CLK_PLL_UNLOCKED;
        }
        Mcu_Drv_PriRetCheck(MCU_DRV_SI_CLk_GET_PLL_STATUS, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE_FAST
#include "Mcu_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/
/**
* @brief         Mcu_Drv_PriParaCheck
* @details       Reports Det error if MCU_DEV_ERROR_DETECT == STD_ON
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Mcu_Drv_PriParaCheck(bool Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(MCU_DRV_TT_STATUS_DEFAULT(ApiId), ErrId);
#if defined(MCU_DEV_ERROR_DETECT) && (MCU_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(MCU_MODULE_ID, ApiId, ErrId);
            ModuleDet_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, (uint8)(ApiId & 0xFFU), (uint8)(ErrId & 0xFFU));
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
* @brief         Mcu_Drv_PriRetCheck
* @details       Reports Return Value error if MCU_DEV_ERROR_DETECT == STD_ON
* @param[in]     ApiId - Service Id of API
* @param[out]    ErrId - Error Id of Condition
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Mcu_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId)
{
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
#if defined(MCU_DEV_ERROR_DETECT) && (MCU_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(MCU_MODULE_ID, ApiId, *ErrId);
            ModuleDet_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, (uint8)(ApiId & 0xFFU), (uint8)(*ErrId & 0xFFU));
#endif
            *ErrId = TT_SET_STATUS_TYPE(MCU_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
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

#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
