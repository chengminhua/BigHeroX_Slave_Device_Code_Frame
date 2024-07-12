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
**  FILENAME     : Mcu_Hw_Misc.h                                              **
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
#ifndef MCU_HW_MISC_H
#define MCU_HW_MISC_H

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
#define MCU_HW_MISC_VENDOR_ID_H                     1541
#define MCU_HW_MISC_MODULE_ID_H                     101
#define MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_MISC_SW_MAJOR_VERSION_H              1
#define MCU_HW_MISC_SW_MINOR_VERSION_H              1
#define MCU_HW_MISC_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Misc.h and Mcu_Hw_Clk_Types.h file version check */
#if (MCU_HW_MISC_VENDOR_ID_H != MCU_HW_CLK_TYPES_VENDOR_ID_H)
    #error "Mcu_Hw_Misc.h and Mcu_Hw_Clk_Types.h have different vendor id"
#endif
#if (MCU_HW_MISC_MODULE_ID_H != MCU_HW_CLK_TYPES_MODULE_ID_H)
    #error "Mcu_Hw_Misc.h and Mcu_Hw_Clk_Types.h have different module id"
#endif
#if ((MCU_HW_MISC_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_MISC_AR_RELEASE_MINOR_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_MISC_AR_RELEASE_PATCH_VERSION_H != MCU_HW_CLK_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Misc.h and Mcu_Hw_Clk_Types.h are different"
#endif
#if ((MCU_HW_MISC_SW_MAJOR_VERSION_H != MCU_HW_CLK_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_HW_MISC_SW_MINOR_VERSION_H != MCU_HW_CLK_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_HW_MISC_SW_PATCH_VERSION_H != MCU_HW_CLK_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Misc.h and Mcu_Hw_Clk_Types.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Local reset  type assert */
#define MCU_MISC_LOCALRST_TYPE_ASSERT(type) ((((type) <= TT_SCU_LOCAL_RST_SENT7)) || \
                                          (((type) >= TT_SCU_LOCAL_RST_CIP_SHIELD) && ((type) <= TT_SCU_LOCAL_RST_ADC)) || \
                                          (((type) >= TT_SCU_LOCAL_RST_HSM_SUBSYSTEM) && ((type) <= TT_SCU_LOCAL_RST_M7_CORE)))
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
* @brief        Mcu_LocalResetModules
* @details      Mcu control modules local reset
* @param[in]    Type - The Module will be local reset
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Misc_LocalResetModules(TT_CONST TT_SCU_LOCAL_RST_Type Type);

/**
* @brief        Mcu_Hw_Misc_PerformReset
* @details      The service performs a microcontroller reset.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Misc_PerformReset(void);

/**
* @brief        Mcu_Hw_Misc_FcuTimingConfig
* @details      Fcu time configuration
* @param[in]    Clock: the dest clock
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Misc_FcuTimingConfig(TT_CONST uint32 Clock);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
