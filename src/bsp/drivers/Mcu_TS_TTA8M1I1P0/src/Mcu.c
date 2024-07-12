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
**  FILENAME     : Mcu.c                                                      **
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
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu.h"
#include "Mcu_Drv.h"
#include "Base_Drv.h"
#if defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#include "Base_Tools.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_VENDOR_ID_C                     1541
#define MCU_MODULE_ID_C                     101
#define MCU_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_AR_RELEASE_MINOR_VERSION_C      4
#define MCU_AR_RELEASE_PATCH_VERSION_C      0
#define MCU_SW_MAJOR_VERSION_C              1
#define MCU_SW_MINOR_VERSION_C              1
#define MCU_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu.c and Mcu.h file version check */
#if (MCU_VENDOR_ID_C != MCU_VENDOR_ID_H)
    #error "Mcu.c and Mcu.h have different vendor id"
#endif
#if (MCU_MODULE_ID_C != MCU_MODULE_ID_H)
    #error "Mcu.c and Mcu.h have different module id"
#endif
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_AR_RELEASE_PATCH_VERSION_C != MCU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu.c and Mcu.h are different"
#endif
#if ((MCU_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION_H) || \
     (MCU_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION_H) || \
     (MCU_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu.c and Mcu.h are different"
#endif

/* Mcu.c and Mcu_Drv.h file version check */
#if (MCU_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Mcu.c and Mcu_Drv.h have different vendor id"
#endif
#if (MCU_MODULE_ID_C != MCU_DRV_MODULE_ID_H)
    #error "Mcu.c and Mcu_Drv.h have different module id"
#endif
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu.c and Mcu_Drv.h are different"
#endif
#if ((MCU_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (MCU_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (MCU_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu.c and Mcu_Drv.h are different"
#endif

/* Mcu.c and Base_Drv.h file version check */
#if (MCU_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
    #error "Mcu.c and Base_Drv.h have different vendor id"
#endif
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu.c and Base_Drv.h are different"
#endif
#if ((MCU_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (MCU_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
     (MCU_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu.c and Base_Drv.h are different"
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/* Mcu.c and Base_Tools.h file version check */
#if (MCU_VENDOR_ID_C != BASE_TOOLS_VENDOR_ID_H)
    #error "Mcu.c and Base_Tools.h have different vendor id"
#endif
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_AR_RELEASE_PATCH_VERSION_C != BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu.c and Base_Tools.h are different"
#endif
#if ((MCU_SW_MAJOR_VERSION_C != BASE_TOOLS_SW_MAJOR_VERSION_H) || \
     (MCU_SW_MINOR_VERSION_C != BASE_TOOLS_SW_MINOR_VERSION_H) || \
     (MCU_SW_PATCH_VERSION_C != BASE_TOOLS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu.c and Base_Tools.h are different"
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

#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"
/* Mcu Status Data */
static Mcu_StatusType Mcu_PubStatusData = {0};

#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
* @brief         Mcu_PriParamCheck
* @details       Reports Det error.
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Mcu_PriParamCheck(bool Expr, uint8 ApiId, uint8 ErrId, Std_ReturnType *RetVal);

#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h" 

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_PriU32ToResetReason
* @details      Covert uint32 to Mcu_ResetType
* @param[in]    ResetReason - reset uint32
* @return       Mcu_ResetType
* @retval       Mcu_ResetType Type Result
* @pre
*/
static Mcu_ResetType Mcu_PriU32ToResetReason(uint32 ResetReason);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE_SLOW
#include "Mcu_MemMap.h"
#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_PriReadRamSectionVerify.
* @details       Ram Verify.
* @param[in]     McuRamSettingPtr - Ram Section Setting pointer
* @return
* @retval
* @pre
*/
static Std_ReturnType Mcu_PriReadRamSectionVerify(TT_CONST Mcu_RamSectionSettingConfigType *McuRamSettingPtr);

/**
* @brief         Mcu_PriRamSectionVerify.
* @details       Ram Verify.
* @param[in]     RamSection - Ram Section Index
* @return
* @retval
* @pre
*/
static Std_ReturnType Mcu_PriRamSectionVerify(Mcu_RamSectionType RamSection);

#if (MCU_NO_PLL == STD_OFF)
/**
* @brief        Mcu_PriInitCheck
* @details      Check Mcu Config
* @param[in]    ConfigPtr : Const Ptr to Mcu Module
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_PriInitCheck(void);

/**
* @brief        Mcu_PriCoreClkCheck
* @details      Service to initalize the PLL & other MCU clock options
* @param[in]    ClockCfgPtr - Clock setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_PriCoreClkCheck(TT_CONST Mcu_Hw_ClockSettingConfigType *ClockCfgPtr);

/**
* @brief        Mcu_PriPeriClkCheck
* @details      Service to initalize the PLL & other MCU clock options
* @param[in]    ClockCfgPtr - Clock setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_PriPeriClkCheck(TT_CONST Mcu_Hw_ClockSettingConfigType *ClockCfgPtr);
#endif

/**
 * @brief         Mcu_PriMClockPpuCalcCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     ConfigPtr configuration parameter
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static void Mcu_PriSleepClockPpuCalcCfgCrc(TT_CONST Mcu_ConfigType *ConfigPtr,uint32 *crc);

/**
 * @brief         Mcu_PriModeCalcCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     ConfigPtr configuration parameter
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static void Mcu_PriModeCalcCfgCrc(TT_CONST Mcu_ConfigType *ConfigPtr,uint32 *crc);

/**
 * @brief         Mcu_PriCmuCalcCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     ConfigPtr configuration parameter
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static void Mcu_PriCmuCalcCfgCrc(TT_CONST Mcu_ConfigType *ConfigPtr,uint32 *crc);

/**
 * @brief         Mcu_PriCalcCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     ConfigPtr configuration parameter
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static uint32 Mcu_PriCalcCfgCrc(TT_CONST Mcu_ConfigType *ConfigPtr);
#endif

/**
* @brief         Mcu_PriRamSection.
* @details       Ram Verify.
* @param[in]     McuRamSettingPtr - Ram Section configuration pointer
* @return
* @retval
* @pre
*/
static Std_ReturnType Mcu_PriWriteRamSection(TT_CONST Mcu_RamSectionSettingConfigType *McuRamSettingPtr);

#if defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
LOCAL_INLINE void Mcu_DemErrorReport(Std_ReturnType RetVal)
{
    if(E_OK != RetVal)
    {
        if ((uint32)STD_ON == Mcu_PubStatusData.ConfigPtr->DemErrorConfig.ErrorClockFailureCfg.state)
        {
            /* SWS_Mcu_00053 */
            (void)Dem_SetEventStatus((Dem_EventIdType)Mcu_PubStatusData.ConfigPtr->DemErrorConfig.ErrorClockFailureCfg.id,  DEM_EVENT_STATUS_FAILED);
        }
    }
}
#endif

/******************************************************************************
*                         Public Functions
******************************************************************************/

/******************************************************************************
*  Service name    : Mcu_Init
*  Syntax          : void Mcu_Init( TT_CONST Mcu_ConfigType* ConfigPtr )
*  Service ID      : 0x00
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : ConfigPtr - Pointer to MCU driver configuration set
*  Parameters (out): None
*  Return value    : None
*  Description     : Service for MCU initialization
******************************************************************************/
void Mcu_Init(TT_CONST Mcu_ConfigType *ConfigPtr)
{
    Std_ReturnType  RetVal      = E_OK;
    TT_RetType      TTRetVal    = TT_RET_SUCCESS;
#if (TT_SAFETY == STD_ON)
    uint32 Crc = 0;
#endif
#if defined(MCU_CONFIG_VARIANT) && (MCU_CONFIG_VARIANT == MODULE_VARIANT_PRECOMPILE)
    {
        Mcu_PriParamCheck((NULL_PTR != ConfigPtr), MCU_SI_INIT,
                          MCU_E_PARAM_POINTER, (Std_ReturnType *)&RetVal);
        Mcu_PubStatusData.ConfigPtr = (TT_CONST Mcu_ConfigType *)&McuConfigData;
    }
#else
    {       
        /* Mcu_FSR_001 */
        Mcu_PriParamCheck((NULL_PTR == ConfigPtr), MCU_SI_INIT,
                       MCU_E_PARAM_POINTER, (Std_ReturnType *)&RetVal);
        Mcu_PubStatusData.ConfigPtr = ConfigPtr;
    }
#endif
#if (TT_SAFETY == STD_ON)
    if (RetVal == E_OK)
    {
        Crc = Mcu_PriCalcCfgCrc(Mcu_PubStatusData.ConfigPtr);
        Mcu_PriParamCheck((Crc != Mcu_PubStatusData.ConfigPtr->Crc),MCU_SI_INIT,MCU_E_PARAM_CONFIG,&RetVal);
    }
    else
    {
        /* do nothing */
    }
#endif
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized == TRUE),
                       MCU_SI_INIT,
                       MCU_E_INIT_FAILED,
                       (Std_ReturnType *)&RetVal);

    if (RetVal == E_OK)
    {
        (void)Mcu_Drv_Pmu_SetCallBack(Mcu_PubStatusData.ConfigPtr->McuPmuCallBack);

        if (TRUE == Mcu_PubStatusData.ConfigPtr->McuDefaultRUNModeEnable)
        {
            TTRetVal = Mcu_Drv_Pmu_ConfigMode((TT_CONST Mcu_Hw_ModeSettingConfigType *)&Mcu_PubStatusData.ConfigPtr->McuModeSettingConfig[Mcu_PubStatusData.ConfigPtr->McuDefaultRUNModeNum]);
            Mcu_PriParamCheck((TTRetVal != TT_RET_SUCCESS), MCU_SI_INIT,
                              MCU_E_INIT_FAILED, (Std_ReturnType *)&RetVal);
            if (E_OK == RetVal)
            {
                Mcu_PubStatusData.initialized = TRUE;
            }
            else
            {
                Mcu_PubStatusData.initialized = FALSE;
            }
        }
        else
        {
            Mcu_PubStatusData.initialized = TRUE;
        }
    }
    else
    {
        /* do nothing */
    }
}

/******************************************************************************
*  Service name    : Mcu_InitRamSection
*  Syntax          : Std_ReturnType Mcu_InitRamSection(
                                            Mcu_RamSectionType RamSection)
*  Service ID      : 0x01
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : RamSection - Selects RAM memory section provided in
                                  configuration set.
*  Parameters (out): None
*  Return value    : E_OK: command has been accepted
*                    E_NOT_OK: command has not been accepted
*  Description     : Service to initalize the RAM section wise.
******************************************************************************/
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    Std_ReturnType                          RetVal               = E_OK;
    TT_CONST Mcu_RamSectionSettingConfigType *McuRamSettingPtr   = NULL_PTR;

    /* SWS_Mcu_00136 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized != TRUE),
                       MCU_SI_INITRAMSECTION,
                       MCU_E_UNINIT,
                       (Std_ReturnType *)&RetVal);

    /* SWS_Mcu_00021 */
    Mcu_PriParamCheck(((uint32)RamSection >= MCU_NUM_RAM_SECTORS),
                       MCU_SI_INITRAMSECTION,
                       MCU_E_PARAM_RAMSECTION,
                       (Std_ReturnType *)&RetVal);

    Mcu_PriParamCheck(Mcu_PubStatusData.ConfigPtr->McuRamSettingConfig == NULL_PTR,
                       MCU_SI_INITRAMSECTION,
                       MCU_E_PARAM_POINTER,
                       (Std_ReturnType *)&RetVal);

    if(RetVal == E_OK)
    {
        McuRamSettingPtr = (TT_CONST Mcu_RamSectionSettingConfigType *)&Mcu_PubStatusData.ConfigPtr->McuRamSettingConfig[RamSection];

        RetVal = Mcu_PriWriteRamSection(McuRamSettingPtr);

#if (TT_SAFETY == STD_ON)
        if (RetVal == E_OK)
        {
            RetVal = Mcu_PriRamSectionVerify(RamSection);
        }
#endif
    }
    else
    {
        /* do nothing */
    }
    
    return RetVal;
}

#if (MCU_INIT_CLOCK == STD_ON)
/******************************************************************************
*  Service name    : Mcu_InitClock
*  Syntax          : Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting )
*  Service ID      : 0x02
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : Clock Setting
*  Parameters (out): None
*  Return value    : E_OK: command has been accepted
*                    E_NOT_OK: command has not been accepted
*  Description     : Service to initalize the PLL & other MCU clock options
******************************************************************************/
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
{
    Std_ReturnType  RetVal = E_OK;
    TT_RetType      TT_RetVal = TT_RET_SUCCESS;

    /* SWS_Mcu_00139 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized != TRUE) || (Mcu_PubStatusData.Clkinitialized == TRUE),
                       MCU_SI_INITCLOCK,
                       MCU_E_UNINIT,
                       (Std_ReturnType *)&RetVal);

    /* SWS_Mcu_00019 */
    Mcu_PriParamCheck((ClockSetting >= MCU_NUM_CLOCK_SETTING),
                       MCU_SI_INITCLOCK,
                       MCU_E_PARAM_CLOCK,
                       (Std_ReturnType *)&RetVal);

    if(RetVal == E_OK)
    {
        Mcu_PubStatusData.ClockSetting = ClockSetting;
        Mcu_PubStatusData.IhoClk = Mcu_PubStatusData.ConfigPtr->McuClockSettingConfig[ClockSetting].IhoClk;
        Mcu_PubStatusData.EcoClk = Mcu_PubStatusData.ConfigPtr->McuClockSettingConfig[ClockSetting].EcoClk;

        TT_RetVal = Mcu_Drv_Clk_Init((TT_CONST Mcu_Hw_ClockSettingConfigType *)&Mcu_PubStatusData.ConfigPtr->McuClockSettingConfig[ClockSetting]);

        Mcu_PriParamCheck((TT_RetVal != TT_RET_SUCCESS), MCU_SI_INITCLOCK,
                                      MCU_E_INIT_FAILED, (Std_ReturnType *)&RetVal);
    }
    else
    {
        /* do nothing */
    }

    if (RetVal == E_OK)
    {
        Mcu_PubStatusData.Clkinitialized = TRUE;
    }
    else
    {
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
        TT_DET_REPORT_ERR(MCU_MODULE_ID_C, MCU_INSTANCE_ID, MCU_SI_INITCLOCK, MCU_E_INIT_FAILED);

    #endif
        RetVal = E_NOT_OK;
    }

    return RetVal ;
}
#endif

#if (MCU_NO_PLL == STD_OFF)
/******************************************************************************
*  Service name    : Mcu_DistributePllClock
*  Syntax          : Std_ReturnType Mcu_DistributePllClock( void )
*  Service ID      : 0x03
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : E_OK: command has been accepted
*                    E_NOT_OK: command has not been accepted
*  Description     : Activates the PLL clock to the MCU clock distribution.
******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void)
{
    Std_ReturnType          RetVal      = E_OK;
    TT_RetType              TTRetVal    = TT_RET_STATUS_ERR;
    uint8                   PllStatus   = 0U;
#ifndef MCU_FPGA_CLK
    TT_RetType              RetMpll     = TT_RET_STATUS_ERR;
    TT_RetType              RetEpll     = TT_RET_SUCCESS;
#endif

    /* SWS_Mcu_00125 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized != TRUE) || (Mcu_PubStatusData.Clkinitialized != TRUE),
                       MCU_SI_DISTRIBUTEPLLCLK,
                       MCU_E_UNINIT,
                       (Std_ReturnType *)&RetVal);

    /* SWS_Mcu_00122 */
    /* SWS_Mcu_00142 */
    if (RetVal == E_OK)
    {
        TTRetVal = Mcu_Drv_Clk_GetPllStatus(&PllStatus);
        Mcu_PriParamCheck(((PllStatus == 0U) || (TTRetVal != TT_RET_SUCCESS)),
                           MCU_SI_DISTRIBUTEPLLCLK,
                           MCU_E_PLL_NOT_LOCKED,
                           (Std_ReturnType *)&RetVal);
    }
    else
    {
        /* do nothing */
    }

#ifndef MCU_FPGA_CLK
    if((RetVal == E_OK) &&  (NULL_PTR != Mcu_PubStatusData.ConfigPtr))
    {
        if (Mcu_PubStatusData.ConfigPtr->McuClockSettingConfig[Mcu_PubStatusData.ClockSetting].CoreClk > 0U)
        {
            RetMpll = Mcu_Drv_Clk_PllConfig(Mcu_PubStatusData.ConfigPtr->McuClockSettingConfig[Mcu_PubStatusData.ClockSetting].CoreClk, MCU_MPLL_TYPE);
        }
        else
        {
            /* do nothing */
        }

        if (Mcu_PubStatusData.ConfigPtr->McuClockSettingConfig[Mcu_PubStatusData.ClockSetting].EpllClockConfig != NULL_PTR)
        {
            RetEpll = Mcu_Drv_Clk_PllConfig(Mcu_PubStatusData.ConfigPtr->McuClockSettingConfig[Mcu_PubStatusData.ClockSetting].EpllClockConfig->EpllClk, MCU_EPLL_TYPE);
        }
        else
        {
            /* do nothing */
        }


        if ((RetMpll == TT_RET_SUCCESS) && (RetEpll == TT_RET_SUCCESS))
        {
            if (Mcu_PubStatusData.ConfigPtr->McuCmuSettingConfig != NULL_PTR)
            {
                TTRetVal = Mcu_Drv_Cmu_Init(Mcu_PubStatusData.ConfigPtr->McuCmuSettingConfig);
                Mcu_PriParamCheck((TTRetVal != TT_RET_SUCCESS),
                                                       MCU_SI_DISTRIBUTEPLLCLK,
                                                       MCU_E_PARAM_CONFIG,
                                                       (Std_ReturnType *)&RetVal);
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            RetVal = E_NOT_OK;
        }
    }
    else
    {
        (void)RetMpll;
        (void)RetEpll;
        RetVal = E_NOT_OK;
    }
#endif
    if (RetVal != E_OK)
    {
        RetVal = E_NOT_OK;
    }

#if defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    Mcu_DemErrorReport(RetVal);
#endif

#if (TT_SAFETY == STD_ON)
    if (RetVal == E_OK)
    {
        TTRetVal = Mcu_PriInitCheck();
        if (TT_RET_SUCCESS != TTRetVal)
        {
            RetVal = E_NOT_OK;
        }
    }
    else
    {
        /* do nothing */
    }
#endif

    return RetVal;
}
#endif

#if (MCU_VERSION_INFO_API == STD_ON)
/******************************************************************************
*  Service name    : Mcu_GetVersionInfo
*  Syntax          : void Mcu_GetVersionInfo(Std_VersionInfoType* versioninfo)
*  Service ID      : 0x09
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): versioninfo : Pointer to where to store the version
                     information of this module.
*  Return value    : None
*  Description     : This service returns the version information of this module.
********************************************************************************/
void Mcu_GetVersionInfo(Std_VersionInfoType *Versioninfo)
{
    Std_ReturnType RetVal = E_OK;

    /* MCU_FSR_002 */
    Mcu_PriParamCheck((NULL_PTR == Versioninfo),
                      MCU_SI_GETVERSIONINFO,MCU_E_PARAM_POINTER,
                      (Std_ReturnType *)&RetVal);

    if (E_OK == RetVal)
    {
        Versioninfo->vendorID = MCU_VENDOR_ID_C;
        Versioninfo->moduleID = MCU_MODULE_ID_C;
        Versioninfo->sw_major_version = MCU_SW_MAJOR_VERSION_C;
        Versioninfo->sw_minor_version = MCU_SW_MINOR_VERSION_C;
        Versioninfo->sw_patch_version = MCU_SW_PATCH_VERSION_C;
    }
    else
    {
        /* do nothing */
    }
}
#endif

#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h" 

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h" 
/******************************************************************************
*  Service name    : Mcu_GetPllStatus
*  Syntax          : Mcu_PllStatusType Mcu_GetPllStatus( void )
*  Service ID      : 0x04
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : Mcu_PllStatusType - PLL status
*  Description     : This service provides the lock status of the PLL.
******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
    Mcu_PllStatusType       RetStatus   = MCU_PLL_STATUS_UNDEFINED;

    /* SWS_Mcu_00206 */
#if(MCU_NO_PLL != STD_ON)
    Std_ReturnType          RetVal      = E_OK;
    TT_RetType              TTRetVal    = TT_RET_SUCCESS;
    uint8                   PllStatus   = 0;

    /* SWS_Mcu_00132 */
    /* SWS_Mcu_00125 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized != TRUE),
                      MCU_SI_GETPLLSTATUS,
                      MCU_E_UNINIT,
                      (Std_ReturnType *)&RetVal);
    if(RetVal == E_OK)
    {
        TTRetVal = Mcu_Drv_Clk_GetPllStatus(&PllStatus);
        Mcu_PriParamCheck((TTRetVal != TT_RET_SUCCESS),
                          MCU_SI_GETPLLSTATUS,
                          MCU_E_PARAM_POINTER,
                          (Std_ReturnType *)&RetVal);

        if (RetVal == E_OK)
        {
            if (PllStatus == (uint8)MCU_CLK_PLL_UNLOCKED)
            {
                RetStatus = MCU_PLL_UNLOCKED;
            }
            else if (PllStatus == (uint8)MCU_CLK_PLL_LOCKED)
            {
                RetStatus = MCU_PLL_LOCKED;
            }
            else
            {
                RetStatus = MCU_PLL_STATUS_UNDEFINED;
            }
        }
    }
    else
    {
        RetStatus = MCU_PLL_STATUS_UNDEFINED;
    }
#endif

    return RetStatus;
}

/******************************************************************************
*  Service name    : Mcu_GetResetReason
*  Syntax          : Mcu_ResetType Mcu_GetResetReason( void )
*  Service ID      : 0x05
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : Mcu_ResetType
*  Description     : The service reads the reset type from the hardware.
******************************************************************************/
Mcu_ResetType Mcu_GetResetReason(void)
{
    Std_ReturnType  RetVal          = E_OK;
    TT_RetType      TTRet           = TT_RET_SUCCESS;
    uint32          ResetReason     = 7U;  /* default MCU_RESET_UNDEFINED */
    Mcu_ResetType   ResetRet        = MCU_RESET_UNDEFINED;
    
    /* SWS_Mcu_00133 */
    /* SWS_Mcu_00125 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized != TRUE),
                       MCU_SI_GETRESETREASON,
                       MCU_E_UNINIT,
                       (Std_ReturnType *)&RetVal);

    if(RetVal == E_OK)
    {
        TTRet = Mcu_Drv_Pmu_GetResetReason(&ResetReason);
        Mcu_PriParamCheck((TTRet != TT_RET_SUCCESS),
                          MCU_SI_GETRESETREASON,
                          MCU_E_PARAM_POINTER, (Std_ReturnType *)&RetVal);
        if (TT_RET_SUCCESS == TTRet)
        {
            ResetRet = Mcu_PriU32ToResetReason(ResetReason);
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

    return ResetRet;
}

/******************************************************************************
*  Service name    : Mcu_GetResetRawValue
*  Syntax          : Mcu_RawResetType Mcu_GetResetRawValue( void )
*  Service ID      : 0x06
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : Mcu_RawResetType
*  Description     : The service reads the reset type from the hardware register.
********************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
    Std_ReturnType      RetVal      = E_OK;
    TT_RetType          TTRetVal    = TT_RET_SUCCESS;
    Mcu_RawResetType    ResetValue  = 0U;
    
    /* SWS_Mcu_00135 */
    /* SWS_Mcu_00125 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized != TRUE),
                       MCU_SI_GETRESETRAWVAL,
                       MCU_E_UNINIT,
                       (Std_ReturnType *)&RetVal);

    if(RetVal == E_OK)
    {
        TTRetVal = Mcu_Drv_Pmu_GetResetRawValue(&ResetValue);

        Mcu_PriParamCheck((TTRetVal != TT_RET_SUCCESS),
                          MCU_SI_GETRESETRAWVAL,
                          MCU_E_PARAM_POINTER,
                          (Std_ReturnType *)&RetVal);
    }
    else
    {
        /* do nothing */
    }
    
    return ResetValue;
}

#if (MCU_PERFORM_RESET_API == STD_ON)
/******************************************************************************
*  Service name    : Mcu_PerformReset
*  Syntax          : void Mcu_PerformReset( void )
*  Service ID      : 0x07
*  Sync/Async      : Synchronous
*  Reentrancy      : Non-reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : None
*  Description     : The service performs a microcontroller reset.
********************************************************************************/
void Mcu_PerformReset(void)
{
    Std_ReturnType RetVal = E_OK;
    TT_RetType   TTRetVal = TT_RET_SUCCESS;
    
    /* SWS_Mcu_00125 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized != TRUE),
                       MCU_SI_PERFORMRESET,
                       MCU_E_UNINIT,
                       (Std_ReturnType *)&RetVal);

    if(RetVal == E_OK)
    {
        TTRetVal = Mcu_Drv_Misc_PerformReset();
        Mcu_PriParamCheck((TTRetVal != TT_RET_SUCCESS),
                          MCU_SI_PERFORMRESET,
                          MCU_E_PARAM_CONFIG,
                          (Std_ReturnType *)&RetVal);
    }
    else
    {
        /* do nothing */
    }
}
#endif

/******************************************************************************
*  Service name    : Mcu_SetMode
*  Syntax          : void Mcu_SetMode( Mcu_ModeType McuMode )
*  Service ID      : 0x08
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : McuMode : Set different MCU power modes configured.
*  Parameters (out): None
*  Return value    : None
*  Description     : This service activates the MCU power modes.
********************************************************************************/
void Mcu_SetMode(Mcu_ModeType McuMode)
{
    TT_RetType TT_RetVal  = TT_RET_SUCCESS;
    Std_ReturnType RetVal = E_OK;

    /* SWS_Mcu_00125 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized != TRUE),
                        MCU_SI_SETMODE,
                       MCU_E_UNINIT,
                       (Std_ReturnType *)&RetVal);

#if (MCU_NUM_MODE_SETTING > 0)
    /* SWS_Mcu_00019 */
    Mcu_PriParamCheck((McuMode >= MCU_NUM_MODE_SETTING),
                        MCU_SI_SETMODE,
                       MCU_E_PARAM_MODE,
                       (Std_ReturnType *)&RetVal);
#endif

    Mcu_PriParamCheck(NULL_PTR == Mcu_PubStatusData.ConfigPtr->McuModeSettingConfig,
                      MCU_SI_SETMODE,
                      MCU_E_PARAM_POINTER,
                       (Std_ReturnType *)&RetVal);

    if(RetVal == E_OK)
    {
        TT_RetVal = Mcu_Drv_Pmu_ConfigMode((TT_CONST Mcu_Hw_ModeSettingConfigType *)&Mcu_PubStatusData.ConfigPtr->McuModeSettingConfig[McuMode]);

        Mcu_PriParamCheck((TT_RetVal != TT_RET_SUCCESS),
                          MCU_SI_SETMODE,
                          MCU_E_PARAM_CONFIG,
                          (Std_ReturnType *)&RetVal);
    }
    else
    {
        /* do nothing */
    }
}

#if defined(MCU_GET_RAM_STATE_API) && (MCU_GET_RAM_STATE_API == STD_ON)
/******************************************************************************
*  Service name    : Mcu_GetRamState
*  Syntax          : Mcu_RamStateType Mcu_GetRamState( void )
*  Service ID      : 0x0A
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : Mcu_RamStateType : Status of the Ram Content.
*  Description     : This service provides the actual status of the
                     microcontroller Ram. (if supported)
********************************************************************************/
Mcu_RamStateType Mcu_GetRamState(void)
{
    /* NOT IMPLEMENTED : RAM State not supported by Hardware */
    return MCU_RAMSTATE_VALID;
}
#endif

/******************************************************************************
*                            Private Functions
******************************************************************************/
/**
* @brief        Mcu_PriU32ToResetReason
* @details      Covert uint32 to Mcu_ResetType
* @param[in]    ResetReason - reset uint32
* @return       Mcu_ResetType
* @retval       Mcu_ResetType Type Result
* @pre
*/
static Mcu_ResetType Mcu_PriU32ToResetReason(uint32 ResetReason)
{
    Mcu_ResetType ResetRet = MCU_RESET_UNDEFINED;

    switch (ResetReason)
    {
        case 0:
            ResetRet = MCU_POWER_ON_RESET;
            break;
        case 1:
            ResetRet = MCU_LOWER_POWER_RESET;
            break;
        case 2:
            ResetRet = MCU_RSTB_PIN_RESET;
            break;
        case 3:
            ResetRet = MCU_BIST_FAIL_RESET;
            break;
        case 4:
            ResetRet = MCU_BIST_SUCCESS_RESET;
            break;
        case 5:
            ResetRet = MCU_SMU_ALARM_RESET;
            break;
        case 6:
            ResetRet = MCU_SOFT_RESET;
            break;
        case 30:
            ResetRet = MCU_SYSTEM_STABLE;
            break;
        case 31:
            ResetRet = MCU_SYSTEM_ACTIVE;
            break;
        case 7:
        default:
            ResetRet = MCU_RESET_UNDEFINED;
            break;
    }

    return ResetRet;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h" 

#define MCU_START_SEC_CODE_FAST
#include "Mcu_MemMap.h" 
/**
* @brief         Mcu_PriParamCheck
* @details       Reports Det error.
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Mcu_PriParamCheck(bool Expr, uint8 ApiId, uint8 ErrId, Std_ReturnType *RetVal)
{
    (void)ApiId;
    (void)ErrId;
    if(NULL_PTR != RetVal)
    {
        if ((TRUE == Expr) && (*RetVal == E_OK))
        {
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
            TT_DET_REPORT_ERR(MCU_MODULE_ID_C, MCU_INSTANCE_ID, ApiId, ErrId);
    #endif
            *RetVal = E_NOT_OK;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        
    }
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    (void)RetVal;
}
#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE_SLOW
#include "Mcu_MemMap.h" 

/**
* @brief         Mcu_PriRamSection.
* @details       Ram Verify.
* @param[in]     McuRamSettingPtr - Ram Section Setting pointer
* @return
* @retval
* @pre
*/
static Std_ReturnType Mcu_PriWriteRamSection(TT_CONST Mcu_RamSectionSettingConfigType *McuRamSettingPtr)
{
    Std_ReturnType RetVal  = E_OK;
    uint32 RamCounter      = 0U;
    uint32 RamCounterLimit = 0U;

    RamCounterLimit = McuRamSettingPtr->McuRamSectionSize / McuRamSettingPtr->McuRamSectionWriteSize;

    switch(McuRamSettingPtr->McuRamSectionWriteSize)
    {
        case 1:
            while (RamCounter < RamCounterLimit)
            {
                *((uint8 *)(McuRamSettingPtr->McuRamSectionBaseAddr + RamCounter)) = (uint8) (McuRamSettingPtr->McuRamDefaultValue);
                RamCounter++;
            }
            break;
        case 2:
            while (RamCounter < RamCounterLimit)
            {
                *((uint16 *)(McuRamSettingPtr->McuRamSectionBaseAddr + (RamCounter * 2))) = (uint16) (McuRamSettingPtr->McuRamDefaultValue);
                RamCounter ++;
            }
            break;
        case 4:
            while (RamCounter < RamCounterLimit)
            {
                *((uint32 *)(McuRamSettingPtr->McuRamSectionBaseAddr + (RamCounter * 4))) = (uint32) (McuRamSettingPtr->McuRamDefaultValue);
                RamCounter ++;
            }
            break;
        case 8:
            while (RamCounter < RamCounterLimit)
            {
                *((uint64 *)(McuRamSettingPtr->McuRamSectionBaseAddr + (RamCounter * 8))) = (uint64) (McuRamSettingPtr->McuRamDefaultValue);
                RamCounter ++;
            }
            break;
        default:
            RetVal = E_NOT_OK;
            break;
    }

    return RetVal;
}

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_PriReadRamSectionVerify.
* @details       Ram Verify.
* @param[in]     McuRamSettingPtr - Ram Section Setting pointer
* @return
* @retval
* @pre
*/
static Std_ReturnType Mcu_PriReadRamSectionVerify(TT_CONST Mcu_RamSectionSettingConfigType *McuRamSettingPtr)
{
    Std_ReturnType RetVal  = E_OK;
    uint32     RamCounter  = 0U;
    uint32 RamCounterLimit = 0U;

    RamCounterLimit = McuRamSettingPtr->McuRamSectionSize / McuRamSettingPtr->McuRamSectionWriteSize;

    /* Check the result */
    switch(McuRamSettingPtr->McuRamSectionWriteSize)
    {
        case 1:
            while (RamCounter < RamCounterLimit)
            {
                 if (*((uint8 *)(McuRamSettingPtr->McuRamSectionBaseAddr + RamCounter)) != (uint8) (McuRamSettingPtr->McuRamDefaultValue))
                 {
                     RetVal = E_NOT_OK;
                    break;
                 }
                 else
                 {
                     /* do nothing */
                 }
                 RamCounter++;
           }
            break;
        case 2:
            while (RamCounter < RamCounterLimit)
            {
                if (*((uint16 *)(McuRamSettingPtr->McuRamSectionBaseAddr + (RamCounter * 2))) != (uint16) (McuRamSettingPtr->McuRamDefaultValue))
                 {
                    RetVal = E_NOT_OK;
                    break;
                 }
                else
                {
                    /* do nothing */
                }
                RamCounter++;
            }
            break;
        case 4:
            while (RamCounter < RamCounterLimit)
            {
                if (*((uint32 *)(McuRamSettingPtr->McuRamSectionBaseAddr + (RamCounter * 4))) != (uint32) (McuRamSettingPtr->McuRamDefaultValue))
                 {
                    RetVal = E_NOT_OK;
                    break;
                 }
                else
                {

                }
                RamCounter++;
            }
            break;
        case 8:
            while (RamCounter < RamCounterLimit)
            {
                if (*((uint64 *)(McuRamSettingPtr->McuRamSectionBaseAddr + (RamCounter * 8))) != (uint64) (McuRamSettingPtr->McuRamDefaultValue))
                 {
                    RetVal = E_NOT_OK;
                    break;
                 }
                else
                {
                    /* do nothing */
                }
                RamCounter++;
            }
           break;
        default:
            RetVal = E_NOT_OK;
            /* default */
            break;
    }

    return RetVal;
}

/**
* @brief         Mcu_PriRamSectionVerify.
* @details       Ram Verify.
* @param[in]     RamSection - Ram Section Index
* @return
* @retval
* @pre
*/
static Std_ReturnType Mcu_PriRamSectionVerify(Mcu_RamSectionType RamSection)
{
    Std_ReturnType RetVal = E_OK;
    TT_CONST Mcu_RamSectionSettingConfigType   *McuRamSettingPtr = NULL_PTR;

    /* SWS_Mcu_00125 */
    Mcu_PriParamCheck((Mcu_PubStatusData.initialized == FALSE),
                       MCU_SI_INITRAMSECTION,
                       MCU_E_UNINIT,
                       (Std_ReturnType *)&RetVal);

    /* SWS_Mcu_00021 */
    Mcu_PriParamCheck(((uint32)RamSection > MCU_NUM_RAM_SECTORS),
                       MCU_SI_INITRAMSECTION,
                       MCU_E_PARAM_RAMSECTION,
                       (Std_ReturnType *)&RetVal);

    if(RetVal == E_OK)
    {
        McuRamSettingPtr = (TT_CONST Mcu_RamSectionSettingConfigType *)&Mcu_PubStatusData.ConfigPtr->McuRamSettingConfig[RamSection];

        RetVal = Mcu_PriReadRamSectionVerify(McuRamSettingPtr);
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

#if (MCU_NO_PLL == STD_OFF)
/**
* @brief        Mcu_PriInitCheck
* @details      Check Mcu Config
* @param[in]    ConfigPtr : Const Ptr to Mcu Module
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_PriInitCheck(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Mcu_Hw_ClockSettingConfigType * ClkSetPtr = \
            (TT_CONST Mcu_Hw_ClockSettingConfigType *)&Mcu_PubStatusData.ConfigPtr->McuClockSettingConfig[0];

    TT_ParaCheck(ClkSetPtr == NULL_PTR, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Mcu_PriCoreClkCheck(ClkSetPtr);
        if (Ret == TT_RET_SUCCESS)
        {
            Ret = Mcu_PriPeriClkCheck(ClkSetPtr);
        }
        else
        {
            Ret = TT_RET_STATUS_CLK_ERR;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_PriCoreClkCheck
* @details      Service to initalize the PLL & other MCU clock options
* @param[in]    ClockCfgPtr - Clock setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_PriCoreClkCheck(TT_CONST Mcu_Hw_ClockSettingConfigType *ClockCfgPtr)
{
    Mcu_PeripheralClockValType  MpllClk = 0U;
    Mcu_PeripheralClockValType  BusClk = 0U;
    Mcu_PeripheralClockValType  SystemClk = 0U;
    TT_RetType                  Ret = TT_RET_SUCCESS;
    TT_RetType                  Ret1 = TT_RET_SUCCESS;
#if defined(USE_ETH_MODULE) && (USE_ETH_MODULE == STD_ON)
    Mcu_PeripheralClockValType  EpllClk = 0U;
#endif

    TT_ParaCheck((ClockCfgPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_MPLL, &MpllClk);
        Ret1 = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_SYSTEM, &SystemClk);
        if ((Ret != TT_RET_SUCCESS) || (Ret1 != TT_RET_SUCCESS) || \
                (ClockCfgPtr->CoreClk != MpllClk) || (ClockCfgPtr->CoreClk != SystemClk))
        {
            Ret = TT_RET_STATUS_CLK_ERR;
        }
        else
        {
            /* do nothing */
        }

        Ret1 = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_BUS, &BusClk);
        if ((Ret1 != TT_RET_SUCCESS) || ((ClockCfgPtr->CoreClk / ((uint32)ClockCfgPtr->BusClkHalfCoreEnable + 1)) != BusClk))
        {
            Ret = TT_RET_STATUS_CLK_ERR;
        }
        else
        {
            /* do nothing */
        }
    #if defined(USE_ETH_MODULE) && (USE_ETH_MODULE == STD_ON)
        if (ClockCfgPtr->EpllClockConfig != NULL_PTR)
        {
            Ret1 = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_EPLL, &EpllClk);
            if ((Ret1 != TT_RET_SUCCESS) || (ClockCfgPtr->EpllClockConfig->EpllClk != EpllClk))
            {
                Ret = TT_RET_STATUS_CLK_ERR;
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

    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mcu_PriPeriClkCheck
* @details      Service to initalize the PLL & other MCU clock options
* @param[in]    ClockCfgPtr - Clock setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Mcu_PriPeriClkCheck(TT_CONST Mcu_Hw_ClockSettingConfigType *ClockCfgPtr)
{
    Mcu_PeripheralClockValType  TmpClk = 0U;
    TT_RetType                  Ret = TT_RET_SUCCESS;
    uint32                      BusClk = 0;

    TT_ParaCheck((ClockCfgPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_BUS, &BusClk);

    if (Ret == TT_RET_SUCCESS)
    {
        Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_APB0, &TmpClk);
        if ((Ret != TT_RET_SUCCESS) || (BusClk / ((uint32)ClockCfgPtr->APB0ClkHalfBusEnable + 1) != TmpClk))
        {
            Ret = TT_RET_STATUS_CLK_ERR;
        }
        else
        {
            Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_APB1, &TmpClk);
            if ((Ret != TT_RET_SUCCESS) || (BusClk / ((uint32)ClockCfgPtr->APB1ClkHalfBusEnable + 1) != TmpClk))
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }
            else
            {
                Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_APB2, &TmpClk);
                if ((Ret != TT_RET_SUCCESS) || (BusClk / ((uint32)ClockCfgPtr->APB2ClkHalfBusEnable + 1) != TmpClk))
                {
                    Ret = TT_RET_STATUS_CLK_ERR;
                }
                else
                {
                    Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_APB3, &TmpClk);
                    if ((Ret != TT_RET_SUCCESS) || (BusClk / ((uint32)ClockCfgPtr->APB3ClkHalfBusEnable + 1) != TmpClk))
                    {
                        Ret = TT_RET_STATUS_CLK_ERR;
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
            }
       }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#endif /* (MCU_NO_PLL == STD_OFF) */

#if (TT_SAFETY == STD_ON)
/**
 * @brief         Mcu_PriCalcCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     ConfigPtr configuration parameter
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static uint32 Mcu_PriCalcCfgCrc(TT_CONST Mcu_ConfigType *ConfigPtr)
{
    uint32 u32AccCRCremainder = 0;

    if(ConfigPtr->McuClockSettingConfig != NULL_PTR)
    {
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->CoreClk, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->IhoClk, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->EcoClk, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->EcoDivLP, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->BusClkHalfCoreEnable, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->APB0ClkHalfBusEnable, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->APB1ClkHalfBusEnable, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->APB2ClkHalfBusEnable, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->APB3ClkHalfBusEnable, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->CanPEUserPLLEnable, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->CanPeClk, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->Sm4ClkDiv, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->Sm4ClkRandEn, &u32AccCRCremainder);
        if(ConfigPtr->McuClockSettingConfig->Sm4ClkRandEn == TRUE)
        {
            Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->Sm4ClkRand, &u32AccCRCremainder);
        }
        else
        {

        }

        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->SkaClkDiv, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->SkaClkRandEn, &u32AccCRCremainder);
        if(ConfigPtr->McuClockSettingConfig->SkaClkRandEn == TRUE)
        {
            Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->SkaClkRand, &u32AccCRCremainder);
        }
        else
        {

        }

        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->HashClkDiv, &u32AccCRCremainder);
        Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->HashClkRandEn, &u32AccCRCremainder);
        if(ConfigPtr->McuClockSettingConfig->HashClkRandEn == TRUE)
        {
            Base_AccumulateCRC((uint32)ConfigPtr->McuClockSettingConfig->HashClkRand, &u32AccCRCremainder);
        }
        else
        {

        }

        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->I3c0ClkDiv, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->I2s0SClkIntDiv, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->I2s0SClkFracDiv, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->I2s0MClkIntDiv, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->I2s0MClkFracDiv, &u32AccCRCremainder);
        if(ConfigPtr->McuClockSettingConfig->EpllClockConfig != NULL_PTR)
        {
            Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->EpllClockConfig->EpllClk, &u32AccCRCremainder);
            Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->EpllClockConfig->EmacPtpRefClkDiv, &u32AccCRCremainder);
            Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->EpllClockConfig->EmacRmiiRefClkDiv, &u32AccCRCremainder);
            Base_AccumulateCRC(ConfigPtr->McuClockSettingConfig->EpllClockConfig->EmacRxTxClkDiv, &u32AccCRCremainder);
        }
        else
        {

        }
    }
    else
    {

    }

    Base_AccumulateCRC(ConfigPtr->McuRamSector, &u32AccCRCremainder);
    Base_AccumulateCRC(ConfigPtr->NumOfClockSetting, &u32AccCRCremainder);

    if(ConfigPtr->McuRamSettingConfig != NULL_PTR)
    {
        for(uint32 i=0; i<ConfigPtr->McuRamSector; i++)
        {
            Base_AccumulateCRC((uint32)((uint32)ConfigPtr->McuRamSettingConfig[i].McuRamDefaultValue&0xFFU), &u32AccCRCremainder);
            Base_AccumulateCRC(ConfigPtr->McuRamSettingConfig[i].McuRamSectionBaseAddr, &u32AccCRCremainder);
            Base_AccumulateCRC(ConfigPtr->McuRamSettingConfig[i].McuRamSectionSize, &u32AccCRCremainder);
            Base_AccumulateCRC(ConfigPtr->McuRamSettingConfig[i].McuRamSectionWriteSize, &u32AccCRCremainder);
        }
    }
    else
    {

    }

    if(ConfigPtr->McuDefaultRUNModeEnable == TRUE)
    {
        Base_AccumulateCRC((uint32)ConfigPtr->McuDefaultRUNModeEnable, &u32AccCRCremainder);
        Base_AccumulateCRC(ConfigPtr->McuDefaultRUNModeNum, &u32AccCRCremainder);
    }
    else
    {

    }

    Mcu_PriSleepClockPpuCalcCfgCrc(ConfigPtr,&u32AccCRCremainder);

    Mcu_PriModeCalcCfgCrc(ConfigPtr,&u32AccCRCremainder);

    Mcu_PriCmuCalcCfgCrc(ConfigPtr,&u32AccCRCremainder);

    return ((uint32)Base_FinalizeCRC(&u32AccCRCremainder));
}

/**
 * @brief         Mcu_PriMClockPpuCalcCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     ConfigPtr configuration parameter
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static void Mcu_PriSleepClockPpuCalcCfgCrc(TT_CONST Mcu_ConfigType *ConfigPtr,uint32 *crc)
{
    uint32 u32AccCRCremainder = *crc;

    if(ConfigPtr->McuModeSettingConfig != NULL_PTR)
    {
        for(uint32 i = 0; i < MCU_NUM_MODE_SETTING; i++)
        {
            if(ConfigPtr->McuModeSettingConfig[i].McuPeriphSleepClockConfig != NULL_PTR)
            {
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig0, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig1, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPeriphSleepClockConfig->McuPeriphtClockSleepConfig2, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPeriphSleepClockConfig->McuCanClockSleep, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPeriphSleepClockConfig->McuLinClockSleep, &u32AccCRCremainder);
            }
            else
            {

            }
        }

        for(uint32 i = 0; i < MCU_NUM_MODE_SETTING; i++)
        {
            if(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig != NULL_PTR)
            {
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB1, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB2, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB3, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB4, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB5, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAHB0, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAHB1, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAHB4, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB1ConfigLock, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB2ConfigLock, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB3ConfigLock, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB4ConfigLock, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAPB5ConfigLock, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAHB0ConfigLock, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAHB1ConfigLock, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuAHB4ConfigLock, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuSUAPB1, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuSUAPB2, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuSUAPB3, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuSUAPB4, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuSUAPB5, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuSUAHB0, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuSUAHB1, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuPpuSettingConfig->McuPpuSUAHB4, &u32AccCRCremainder);
            }
            else
            {

            }
        }

        *crc = u32AccCRCremainder;
    }
}

/**
 * @brief         Mcu_PriModeCalcCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     ConfigPtr configuration parameter
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static void Mcu_PriModeCalcCfgCrc(TT_CONST Mcu_ConfigType *ConfigPtr,uint32 *crc)
{
    uint32 u32AccCRCremainder = *crc;

    if(ConfigPtr->McuModeSettingConfig != NULL_PTR)
    {
        for(uint32 i = 0; i < MCU_NUM_MODE_SETTING; i++)
        {
            if(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig != NULL_PTR)
            {
                for(uint32 j = 0; j < ConfigPtr->McuModeSettingConfig[i].PmuGpioConfigCount; j++)
                {
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].Number, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].InputEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].InputFilterEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].InputEdgeRiseEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].InputEdgeFallEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].InputIntReqEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].InputWakeReqEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].OutEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].OutData, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].InputPullUpEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfig[j].InputPullDownEn, &u32AccCRCremainder);
                }
            }
            else
            {

            }

            if(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfig != NULL_PTR)
            {
                for(uint32 j = 0; j < ConfigPtr->McuModeSettingConfig[i].PmuNmiConfigCount; j++)
                {
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfig[j].NmiEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfig[j].InputFilterEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfig[j].InputEdgeRiseEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfig[j].InputEdgeFallEn, &u32AccCRCremainder);
                #ifdef A8V2E
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfig[j].InputFastFilterEn, &u32AccCRCremainder);
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfig[j].FastFilterCount, &u32AccCRCremainder);
                #endif
                    Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfig[j].InputWakeReqEn, &u32AccCRCremainder);
                }
            }
            else
            {

            }
        }

        for(uint32 i = 0; i < MCU_NUM_MODE_SETTING; i++)
        {
            Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].McuOperaMode, &u32AccCRCremainder);
            if(ConfigPtr->McuModeSettingConfig[i].McuOperaMode == MCU_OP_SLEEP_MODE)
            {
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].CipherPowerDownEn, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].HSMPowerDownEn, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].FlashPowerDownEn, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].IHOPowerDownEn, &u32AccCRCremainder);
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].ECOPowerDownEn, &u32AccCRCremainder);
                Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].OSCDiv, &u32AccCRCremainder);
            }
            else if(ConfigPtr->McuModeSettingConfig[i].McuOperaMode == MCU_OP_STANDBY_MODE)
            {
            #ifdef A8V2E
                Base_AccumulateCRC((uint32)ConfigPtr->McuModeSettingConfig[i].RstbWakupEn, &u32AccCRCremainder);
            #endif
            }
            else
            {

            }

            Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuGpioConfigCount, &u32AccCRCremainder);
            Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].PmuNmiConfigCount, &u32AccCRCremainder);
            Base_AccumulateCRC(ConfigPtr->McuModeSettingConfig[i].McuModeID, &u32AccCRCremainder);
        }

    }
    else
    {

    }

    *crc = u32AccCRCremainder;
}

/**
 * @brief         Mcu_PriCmuCalcCfgCrc.
 * @details       Calculates the crc value of the configuration parameter.
 * @param[in]     ConfigPtr configuration parameter
 * @param[out]    u32AccCRCremainder - crc value
 * @return
 * @retval
 * @pre
 */
static void Mcu_PriCmuCalcCfgCrc(TT_CONST Mcu_ConfigType *ConfigPtr,uint32 *crc)
{
    uint32 u32AccCRCremainder = *crc;

    if(ConfigPtr->McuCmuSettingConfig != NULL_PTR)
    {
        for(uint32 i = 0; i < MCU_CMU_ITEM_COUNTS; i++)
        {
            Base_AccumulateCRC(ConfigPtr->McuCmuSettingConfig[i].CmuIndex, &u32AccCRCremainder);
            if((ConfigPtr->McuCmuSettingConfig[i].CmuTimeoutAlarmEn == TRUE) ||  \
                    (ConfigPtr->McuCmuSettingConfig[i].CmuLthdAlarmEn == TRUE) ||  \
                    (ConfigPtr->McuCmuSettingConfig[i].CmuHthdAlarmEn == TRUE))
            {
                Base_AccumulateCRC(ConfigPtr->McuCmuSettingConfig[i].CmuChkwAlarmVal, &u32AccCRCremainder);
            }
            else
            {

            }

            if(ConfigPtr->McuCmuSettingConfig[i].CmuLthdAlarmEn == TRUE)
            {
                Base_AccumulateCRC(ConfigPtr->McuCmuSettingConfig[i].CmuLthdAlarmVal, &u32AccCRCremainder);
            }
            else
            {

            }

            if(ConfigPtr->McuCmuSettingConfig[i].CmuHthdAlarmEn == TRUE)
            {
                Base_AccumulateCRC(ConfigPtr->McuCmuSettingConfig[i].CmuHthdAlarmVal, &u32AccCRCremainder);
            }
            else
            {

            }
            Base_AccumulateCRC((uint32)ConfigPtr->McuCmuSettingConfig[i].CmuTimeoutAlarmEn, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->McuCmuSettingConfig[i].CmuLthdAlarmEn, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->McuCmuSettingConfig[i].CmuHthdAlarmEn, &u32AccCRCremainder);
        }
    }
    else
    {

    }

    *crc = u32AccCRCremainder;
}
#endif

#endif

#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h" 

#ifdef __cplusplus
}
#endif
