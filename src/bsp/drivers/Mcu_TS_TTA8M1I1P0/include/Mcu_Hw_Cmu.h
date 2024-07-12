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
**  FILENAME     : Mcu_Hw_Cmu.h                                               **
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

#ifndef MCU_HW_CMU_H
#define MCU_HW_CMU_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Hw_Cmu_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_CMU_VENDOR_ID_H                     1541
#define MCU_HW_CMU_MODULE_ID_H                     101
#define MCU_HW_CMU_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_CMU_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_CMU_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_CMU_SW_MAJOR_VERSION_H              1
#define MCU_HW_CMU_SW_MINOR_VERSION_H              1
#define MCU_HW_CMU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Cmu.h and Mcu_Hw_Cmu_Types.h file version check */
#if (MCU_HW_CMU_VENDOR_ID_H != MCU_HW_CMU_TYPES_VENDOR_ID_H)
    #error "Mcu_Hw_Cmu.h and Mcu_Hw_Cmu_Types.h have different vendor id"
#endif
#if (MCU_HW_CMU_MODULE_ID_H != MCU_HW_CMU_TYPES_MODULE_ID_H)
    #error "Mcu_Hw_Cmu.h and Mcu_Hw_Cmu_Types.h have different module id"
#endif
#if ((MCU_HW_CMU_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_CMU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CMU_AR_RELEASE_MINOR_VERSION_H != MCU_HW_CMU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CMU_AR_RELEASE_PATCH_VERSION_H != MCU_HW_CMU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Cmu.h and Mcu_Hw_Cmu_Types.h are different"
#endif
#if ((MCU_HW_CMU_SW_MAJOR_VERSION_H != MCU_HW_CMU_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CMU_SW_MINOR_VERSION_H != MCU_HW_CMU_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_HW_CMU_SW_PATCH_VERSION_H != MCU_HW_CMU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Cmu.h and Mcu_Hw_Cmu_Types.h are different"
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
/**
* @brief         Mcu_Hw_Cmu_Init
* @details       Service to initialize Cmu
* @param[in]     CmuConfig - Cmu configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Cmu_Init(TT_CONST Mcu_Hw_CmuConfigType * TT_CONST CmuConfig);

#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief         Mcu_Hw_Cmu_Start
* @details       Service to start MCU Cmu
* @param[in]     num - The number of Cmu
* @param[in]     AlarmType - Cmu alarm type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Cmu_Start(TT_CONST uint8 num, TT_CONST uint32 AlarmType);

/**
* @brief         Mcu_Hw_Cmu_Stop
* @details       Service to stop  Cmu
* @param[in]     num - The number of Cmu
* @param[in]     AlarmType - Cmu alarm type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Cmu_Stop(TT_CONST uint8 num, uint32 AlarmType);

/**
* @brief         Mcu_Hw_Cmu_StopStore
* @details       Service to initialize Cmu
* @param[in]     CmuConfig - Store configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Cmu_StoreStop(uint32 *CmuFlag);

/**
* @brief         Mcu_Hw_Cmu_LoadStart
* @details       Service to initialize Cmu
* @param[in]     CmuConfig - Store configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Cmu_LoadStart(uint32 *CmuFlag);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Private Functions
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* CDD_EIM_ALIOTH_H */
