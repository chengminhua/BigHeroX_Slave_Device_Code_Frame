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
**  FILENAME     : Mcu_Hw_Pmu.h                                               **
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
#ifndef MCU_HW_PMU_H
#define MCU_HW_PMU_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Hw_Pmu_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_PMU_VENDOR_ID_H                     1541
#define MCU_HW_PMU_MODULE_ID_H                     101
#define MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_PMU_SW_MAJOR_VERSION_H              1
#define MCU_HW_PMU_SW_MINOR_VERSION_H              1
#define MCU_HW_PMU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Pmu.h and Mcu_Hw_Pmu_Types.h file version check */
#if (MCU_HW_PMU_VENDOR_ID_H != MCU_HW_PMU_TYPES_VENDOR_ID_H)
    #error "Mcu_Hw_Pmu.h and Mcu_Hw_Pmu_Types.h have different vendor id"
#endif
#if (MCU_HW_PMU_MODULE_ID_H != MCU_HW_PMU_TYPES_MODULE_ID_H)
    #error "Mcu_Hw_Pmu.h and Mcu_Hw_Pmu_Types.h have different module id"
#endif
#if ((MCU_HW_PMU_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_PMU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_MINOR_VERSION_H != MCU_HW_PMU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PMU_AR_RELEASE_PATCH_VERSION_H != MCU_HW_PMU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Pmu.h and Mcu_Hw_Pmu_Types.h are different"
#endif
#if ((MCU_HW_PMU_SW_MAJOR_VERSION_H != MCU_HW_PMU_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PMU_SW_MINOR_VERSION_H != MCU_HW_PMU_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_HW_PMU_SW_PATCH_VERSION_H != MCU_HW_PMU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Pmu.h and Mcu_Hw_Pmu_Types.h are different"
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
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief         Mcu_Hw_Pmu_GetUserValue
* @details       Get user's register value
* @param[in]     Index - Register hardware unit
* @param[out]    Value - The value of the user register
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_GetUserValue(TT_CONST uint32 Index, uint32 *Value);

/**
* @brief        Mcu_Hw_Pmu_SetUserValue
* @details      Set The value of the user register.
* @param[in]    Value - The value of the user register
* @param[in]    Index - Register hardware unit
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_SetUserValue(TT_CONST uint32 Value, TT_CONST uint32 Index);

/**
* @brief        Mcu_Hw_Pmu_LocalReset
* @details      Pmu local reset.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_LocalReset(void);

/**
* @brief        Mcu_Hw_Pmu_ConfigNmi
* @details      Nmi configuration.
* @param[in]    PmuNmiConfig - Nmi configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_ConfigNmi(TT_CONST Mcu_Hw_PmuNmiConfigType *PmuNmiConfig);

/**
* @brief        Mcu_Hw_Pmu_ConfigGpio
* @details      Gpio configuration.
* @param[in]    PmuGpioConfig - Gpio configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_ConfigGpio(TT_CONST Mcu_Hw_PmuGpioConfigType *PmuGpioConfig);

/**
* @brief        Mcu_EnterStandby
* @details      cpu enter standby mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_EnterStandby(void);

/**
* @brief        Mcu_Hw_Pmu_EnterSleep
* @details      cpu enter sleep mode
* @param[in]    OscDiv:  cpu run in osc clock by div
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_EnterSleep(TT_CONST uint32 OscDiv);

/**
* @brief        Mcu_Hw_Pmu_GetResetRawValue
* @details      Get reset raw value
* @param[out]   Value - Reset raw value
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_GetResetRawValue(uint32 *Value);

/**
* @brief        Mcu_Hw_Pmu_GetResetReason
* @details      Get reset reason
* @param[out]   Value - Reset reason
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_GetResetReason(uint32 *Value);

/**
* @brief        Mcu_Hw_Pmu_ConfigMode
* @details      Service to Set MCU Lowe Power Mode
* @param[in]    McuModeSettingConfig - Mcu mode setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_ConfigMode(TT_CONST Mcu_Hw_ModeSettingConfigType *McuModeSettingConfig);

/**
* @brief        Mcu_Hw_Pmu_SetCallBack
* @details      Set Callback function
* @param[in]    callback function name
* @return
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_SetCallBack(TT_Notification callback);

#ifdef A8V2E
/**
* @brief        Mcu_Hw_Pmu_SetHsmCipPowerDown
* @details      Service to Set Hsm and Cipher Power Mode
* @param[in]    Type - Hsm or Cipher
* @param[in]    Enable - TRUE  :Power Down
*             - FALSE :Power up
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_SetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,TT_CONST boolean Enable);

/**
* @brief        Mcu_Hw_Pmu_GetHsmCipPowerDown
* @details      Service to Get Hsm and Cipher Power Down Status
* @param[in]    Type - Hsm or Cipher
* @param[out]    Enable - TRUE  :Power Down
*              - FALSE :Power up
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Pmu_GetHsmCipPowerDown(TT_CONST Mcu_Hw_PowerDownType Type,uint32* Enable);
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MCU_PMU_HW_H */
