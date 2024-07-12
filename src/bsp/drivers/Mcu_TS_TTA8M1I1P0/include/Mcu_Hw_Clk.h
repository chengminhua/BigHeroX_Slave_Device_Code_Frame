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
**  FILENAME     : Mcu_Hw_Clk.h                                               **
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

#ifndef MCU_HW_CLK_H
#define MCU_HW_CLK_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Hw_Clk_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_CLK_VENDOR_ID_H                     1541
#define MCU_HW_CLK_MODULE_ID_H                     101
#define MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_CLK_SW_MAJOR_VERSION_H              1
#define MCU_HW_CLK_SW_MINOR_VERSION_H              1
#define MCU_HW_CLK_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Clk.h and Mcu_Hw_Clk_Types.h file version check */
#if (MCU_HW_CLK_VENDOR_ID_H != MCU_HW_CLK_TYPES_VENDOR_ID_H)
    #error "Mcu_Hw_Clk.h and Mcu_Hw_Clk_Types.h have different vendor id"
#endif
#if (MCU_HW_CLK_MODULE_ID_H != MCU_HW_CLK_TYPES_MODULE_ID_H)
    #error "Mcu_Hw_Clk.h and Mcu_Hw_Clk_Types.h have different module id"
#endif
#if ((MCU_HW_CLK_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_MINOR_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CLK_AR_RELEASE_PATCH_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Clk.h and Mcu_Hw_Clk_Types.h are different"
#endif
#if ((MCU_HW_CLK_SW_MAJOR_VERSION_H != MCU_HW_CLK_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CLK_SW_MINOR_VERSION_H != MCU_HW_CLK_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_HW_CLK_SW_PATCH_VERSION_H != MCU_HW_CLK_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Clk.h and Mcu_Hw_Clk_Types.h are different"
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
#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock config information */
extern Mcu_Hw_ClkInfoType Mcu_PubClkInfo;

#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_Hw_Clk_GetBus
* @details      Get bus clock
* @param[out]   Clk - Bus clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          MCU_FPGA_CLK: only for test
*/
extern TT_RetType Mcu_Hw_Clk_GetBus (uint32 *Clk);

/**
* @brief        Mcu_Hw_Clk_GetPeriph
* @details      Get the dest Peripheral clock
* @param[in]    PeripheralName - the dest Peripheral in Mcu_PeriphNameType
* @param[out]   Result - the dest Peripheral clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          MCU_FPGA_CLK: only for test
*/
extern TT_RetType Mcu_Hw_Clk_GetPeriph(TT_CONST Mcu_Hw_PeriphNameType PeripheralName, Mcu_PeripheralClockValType *Result);

/**
* @brief        Mcu_Hw_Clk_GetSystem
* @details      Get system clock
* @param[out]   Clk - system clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_GetSystem (uint32 *Clk);

/**
* @brief        Mcu_Hw_Clk_GetMpll
* @details      Get Mpll clock
* @param[out]   Clk - Mpll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_GetMpll (uint32 *Clk);

/**
* @brief        Mcu_Hw_Clk_GetEpll
* @details      Get Epll clock
* @param[out]   Clk - Epll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_GetEpll (uint32 *Clk);

/**
* @brief        Mcu_Hw_Clk_MpllConfig
* @details      Mcu Main Pll Config
* @param[in]    PllClock - the dest pll clock (E:240000000)
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          USE_CMU_MODULE, if Cmu was used, need close all cmu before switch PLL
*/
extern TT_RetType Mcu_Hw_Clk_MpllConfig (TT_CONST uint32 PllClock);

/**
* @brief        Mcu_Hw_Clk_EpllConfig
* @details      Mcu Eth Pll Config
* @param[in]    PllClock - the dest pll clock (E:250000000),0 means Max
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre          USE_CMU_MODULE, if Cmu was used, need close all cmu before switch PLL
*/
extern TT_RetType Mcu_Hw_Clk_EpllConfig (TT_CONST uint32 PllClock);

/**
* @brief        Mcu_Hw_Clk_StopModules
* @details      Mcu control module clk stop
* @param[in]    Type - The Module will be clock stop
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_StopModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type);

/**
* @brief        Mcu_Hw_Clk_StartModules
* @details      Mcu control module clk start
* @param[in]    Type - The Module will be clock start
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_StartModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type);

/**
* @brief        Mcu_Hw_Clk_StatusModules
* @details      Mcu control module clk status
* @param[in]    Type - The Module will be get the status
* @param[out]   Status - the clock status of this module
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_StatusModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type, boolean *Status);

/**
* @brief        Mcu_Hw_Clk_SleepModules
* @details      Mcu control module clk sleep
* @param[in]    Type - The Module will be clock sleep
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_SleepModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type);

/**
* @brief        Mcu_Hw_Clk_AwakenModules
* @details      Mcu control module clk sleep
* @param[in]    Type - The Module will be clock sleep
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_AwakenModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type);

/**
* @brief        Mcu_Hw_Clk_PeriStopModules
* @details      mcu Stop Peril module(can/lin)
* @param[in]    Type - The Module will be clock stop
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_PeriStopModules(TT_CONST TT_SCU_PERI_STOP_Type Type);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE_SLOW
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_Hw_Clk_Init
* @details      Service to initalize the PLL & other MCU clock options
* @param[in]    ClockCfgPtr - Clock setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_Init(TT_CONST Mcu_Hw_ClockSettingConfigType * TT_CONST ClockCfgPtr);

#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_Hw_Clk_GetMPllStatus
* @details      This service provides the lock status of the PLL.
* @param[out]   Status - Status of Pll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_GetMPllStatus(uint8 *Status);

/**
* @brief        Mcu_Hw_Clk_GetEPllStatus
* @details      This service provides the lock status of the PLL.
* @param[out]   Status - Status of Pll clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Clk_GetEPllStatus(uint8 *Status);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Private Functions
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* MCU_CLK_HW_H */
