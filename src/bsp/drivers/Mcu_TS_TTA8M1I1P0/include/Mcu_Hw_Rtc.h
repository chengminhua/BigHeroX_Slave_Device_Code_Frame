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
**  FILENAME     : Mcu_Hw_Rtc.h                                               **
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
#ifndef MCU_HW_RTC_H
#define MCU_HW_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcu_Hw_Rtc_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_RTC_VENDOR_ID_H                     1541
#define MCU_HW_RTC_MODULE_ID_H                     101
#define MCU_HW_RTC_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_RTC_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_RTC_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_RTC_SW_MAJOR_VERSION_H              1
#define MCU_HW_RTC_SW_MINOR_VERSION_H              1
#define MCU_HW_RTC_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifndef MCU_HW_RTC_H
/* Mcu_Hw_Rtc.h and Mcu_Hw_Rtc_Types.h file version check */
#if (MCU_HW_RTC_VENDOR_ID_H != MCU_HW_RTC_TYPES_VENDOR_ID_H)
    #error "Mcu_Hw_Rtc.h and Mcu_Hw_Rtc_Types.h have different vendor id"
#endif
#if (MCU_HW_RTC_MODULE_ID_H != MCU_HW_RTC_TYPES_MODULE_ID_H)
    #error "Mcu_Hw_Rtc.h and Mcu_Hw_Rtc_Types.h have different module id"
#endif
#if ((MCU_HW_RTC_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_RTC_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_RTC_AR_RELEASE_MINOR_VERSION_H != MCU_HW_RTC_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_RTC_AR_RELEASE_PATCH_VERSION_H != MCU_HW_RTC_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Rtc.h and Mcu_Hw_Rtc_Types.h are different"
#endif
#if ((MCU_HW_RTC_SW_MAJOR_VERSION_H != MCU_HW_RTC_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_HW_RTC_SW_MINOR_VERSION_H != MCU_HW_RTC_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_HW_RTC_SW_PATCH_VERSION_H != MCU_HW_RTC_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Rtc.h and Mcu_Hw_Rtc_Types.h are different"
#endif
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
* @brief         Mcu_Hw_Rtc_Init
* @details       Initialize Rtc
* @param[in]     RtcConfig - Rtc configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType  Mcu_Hw_Rtc_Init(TT_CONST Rtc_ConfigType * TT_CONST RtcConfig);

#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief        Mcu_Hw_Rtc_Start
* @details      Start Rtc.
* @param[in]    RtcValue - Rtc comparison values
* @param[in]    ApiValue - The period value of the Rtc interval
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType  Mcu_Hw_Rtc_Start(TT_CONST uint32 RtcValue, TT_CONST uint32 ApiValue);

/**
* @brief        Mcu_Hw_Rtc_GetStatue
* @details      Get Rtc status.
* @param[out]   Status - Status of Rtc
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Rtc_GetState(uint32 *Statue);

/**
* @brief        Mcu_Hw_Rtc_Clear
* @details      Clear Rtc register.
* @param[in]    flag - Reset value of the register
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType  Mcu_Hw_Rtc_Clear(TT_CONST uint32 flag);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MCU_HW_RTC_H */
