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
**  FILENAME     : Mcu_Drv.h                                                  **
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
#ifndef MCU_DRV_H
#define MCU_DRV_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Drv_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_DRV_VENDOR_ID_H                     1541
#define MCU_DRV_MODULE_ID_H                     101
#define MCU_DRV_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_DRV_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_DRV_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_DRV_SW_MAJOR_VERSION_H              1
#define MCU_DRV_SW_MINOR_VERSION_H              1
#define MCU_DRV_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Drv.h and Mcu_Drv_Types.h file version check */
#if (MCU_DRV_VENDOR_ID_H != MCU_DRV_TYPES_VENDOR_ID_H)
    #error "Mcu_Drv.h and Mcu_Drv_Types.h have different vendor id"
#endif
#if (MCU_DRV_MODULE_ID_H != MCU_DRV_TYPES_MODULE_ID_H)
    #error "Mcu_Drv.h and Mcu_Drv_Types.h have different module id"
#endif
#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_H != MCU_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_H != MCU_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_H != MCU_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.h and Mcu_Drv_Types.h are different"
#endif
#if ((MCU_DRV_SW_MAJOR_VERSION_H != MCU_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_DRV_SW_MINOR_VERSION_H != MCU_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_DRV_SW_PATCH_VERSION_H != MCU_DRV_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.h and Mcu_Drv_Types.h are different"
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

/******************************************************************************
*                            Public Prototypes
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
extern TT_RetType Mcu_Drv_Cmu_Init(TT_CONST Mcu_Hw_CmuConfigType * TT_CONST CmuConfig);

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
extern TT_RetType  Mcu_Drv_Rtc_Init(TT_CONST Rtc_ConfigType * TT_CONST RtcConfig);

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
extern TT_RetType Mcu_Drv_Clk_Init(TT_CONST Mcu_Hw_ClockSettingConfigType * TT_CONST ClockCfgPtr);

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
extern TT_RetType Mcu_Drv_Cmu_Start(TT_CONST uint8 num, TT_CONST uint32 AlarmType);

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
extern TT_RetType Mcu_Drv_Cmu_Stop(TT_CONST uint8 num, TT_CONST uint32 AlarmType);

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
extern TT_RetType Mcu_Drv_Ppu_Control(TT_CONST boolean Access, TT_CONST boolean UserMode, TT_CONST PPU_CONTROL_Type Type);

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
extern TT_RetType Mcu_Drv_Ppu_GetErrStatus(TT_CONST PPU_CONTROL_Type Type,uint32 *Status);

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
extern TT_RetType Mcu_Drv_Ppu_ClearErrStatus(TT_CONST PPU_CONTROL_Type Type);

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
extern TT_RetType  Mcu_Drv_Rtc_Start(TT_CONST uint32 RtcValue, TT_CONST uint32 ApiValue);

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
extern TT_RetType Mcu_Drv_Rtc_GetState(uint32 *Status);

/******************************************************************************
*  Service name    : Mcu_Drv_Rtc_Clear
*  Syntax          : TT_RetType  Mcu_Drv_Rtc_Clear(TT_CONST uint32 flag)
*  Service ID      : 119U
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : flag - Reset value of the register
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Clear Rtc register.
******************************************************************************/
extern TT_RetType  Mcu_Drv_Rtc_Clear(TT_CONST uint32 flag);

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
extern TT_RetType Mcu_Drv_Misc_LocalResetModules(TT_CONST TT_SCU_LOCAL_RST_Type Type);

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
extern TT_RetType Mcu_Drv_Misc_PerformReset(void);

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
extern TT_RetType Mcu_Drv_Pmu_GetUserValue(TT_CONST uint32 Index, uint32 *Value);

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
extern TT_RetType Mcu_Drv_Pmu_SetUserValue(TT_CONST uint32 Value, TT_CONST uint32 Index);

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
extern TT_RetType Mcu_Drv_Pmu_LocalReset(void);

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
extern TT_RetType Mcu_Drv_Pmu_ConfigNmi(TT_CONST Mcu_Hw_PmuNmiConfigType *PmuNmiConfig);

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
extern TT_RetType Mcu_Drv_Pmu_ConfigGpio(TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig);

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
extern TT_RetType Mcu_Drv_Pmu_GetResetRawValue(uint32 *Value);

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
extern TT_RetType Mcu_Drv_Pmu_GetResetReason(uint32 *Value);

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
extern TT_RetType Mcu_Drv_Pmu_EnterStandby(void);

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
extern TT_RetType Mcu_Drv_Pmu_EnterSleep(TT_CONST uint32 OscDiv);

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
extern TT_RetType Mcu_Drv_Pmu_ConfigMode(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig);

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
extern TT_RetType Mcu_Drv_Pmu_SetCallBack(TT_Notification callback);

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
extern TT_RetType Mcu_Drv_Clk_GetPeriph(TT_CONST Mcu_Hw_PeriphNameType PeripheralName, Mcu_PeripheralClockValType *Clk);

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
extern TT_RetType Mcu_Drv_Clk_PllConfig (TT_CONST uint32 PllClock, TT_CONST Mcu_Hw_PllType PllType);

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
extern TT_RetType Mcu_Drv_Clk_StopModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type);

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
extern TT_RetType Mcu_Drv_Clk_StartModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type);

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
extern TT_RetType Mcu_Drv_Clk_StatusModules(TT_CONST TT_SCU_CLK_CONTROL_Type Type, boolean *Status);

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
extern TT_RetType Mcu_Drv_Clk_SleepModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type);

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
extern TT_RetType Mcu_Drv_Clk_AwakenModules(TT_CONST TT_SCU_CLK_SLEEP_Type Type);

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
extern TT_RetType Mcu_Drv_Clk_PeriStopModules(TT_CONST TT_SCU_PERI_STOP_Type Type);

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
extern TT_RetType Mcu_Drv_Clk_GetPllStatus(uint8 *Value);

#ifdef A8V2E
/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_SetHsmCipPowerDown
*  Syntax          : TT_RetType Mcu_Drv_Pmu_SetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,TT_CONST boolean Enable)
*  Service ID      : 132U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : Type - Hsm or Cipher
*  Parameters (in) : Enable - TRUE  :Power Down
*                  - FALSE :Power up
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Service to Set Hsm and Cipher Power Mode
******************************************************************************/
extern TT_RetType Mcu_Drv_Pmu_SetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,TT_CONST boolean Enable);

/******************************************************************************
*  Service name    : Mcu_Drv_Pmu_GetHsmCipPowerDown
*  Syntax          : TT_RetType Mcu_Drv_Pmu_GetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,uint32* Enable)
*  Service ID      : 132U
*  Sync/Async      : Synchronous
*  Reentrancy      : Non Reentrant
*  Parameters (in) : Type - Hsm or Cipher
*  Parameters (out) : Enable - TRUE  :Power Down
*                   - FALSE :Power up
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Service to Get Hsm and Cipher Power Down Status
******************************************************************************/
extern TT_RetType Mcu_Drv_Pmu_GetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,uint32* Enable);
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Private Functions
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
