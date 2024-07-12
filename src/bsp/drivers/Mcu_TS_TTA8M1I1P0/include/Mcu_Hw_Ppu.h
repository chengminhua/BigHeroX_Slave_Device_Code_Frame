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
**  FILENAME     : Mcu_Hw_Ppu.h                                               **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Template Driver Source File                                **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef MCU_PPU_HW_H
#define MCU_PPU_HW_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Hw_Ppu_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_PPU_VENDOR_ID_H                     1541
#define MCU_HW_PPU_MODULE_ID_H                     101
#define MCU_HW_PPU_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_PPU_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_PPU_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_PPU_SW_MAJOR_VERSION_H              1
#define MCU_HW_PPU_SW_MINOR_VERSION_H              1
#define MCU_HW_PPU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Ppu.h and Mcu_Hw_Ppu_Types.h file version check */
#if (MCU_HW_PPU_VENDOR_ID_H != MCU_HW_PPU_TYPES_VENDOR_ID_H)
    #error "Mcu_Hw_Ppu.h and Mcu_Hw_Ppu_Types.h have different vendor id"
#endif
#if (MCU_HW_PPU_MODULE_ID_H != MCU_HW_PPU_TYPES_MODULE_ID_H)
    #error "Mcu_Hw_Ppu.h and Mcu_Hw_Ppu_Types.h have different module id"
#endif
#if ((MCU_HW_PPU_AR_RELEASE_MAJOR_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PPU_AR_RELEASE_MINOR_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PPU_AR_RELEASE_PATCH_VERSION_H != MCU_HW_PPU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Ppu.h and Mcu_Hw_Ppu_Types.h are different"
#endif
#if ((MCU_HW_PPU_SW_MAJOR_VERSION_H != MCU_HW_PPU_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PPU_SW_MINOR_VERSION_H != MCU_HW_PPU_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_HW_PPU_SW_PATCH_VERSION_H != MCU_HW_PPU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Ppu.h and Mcu_Hw_Ppu_Types.h are different"
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
* @brief         Mcu_Hw_Ppu_DisAccessControl
* @details       Ppu control all modules disenable access permision
* @param[in]     Type - the moudle will be disenable access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Ppu_DisAccessControl(TT_CONST PPU_CONTROL_Type Type);

/**
* @brief         Mcu_Hw_Ppu_EnAccessControl
* @details       Ppu control all modules enable access permision
* @param[in]     Type - the moudle will be enable access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Ppu_EnAccessControl(TT_CONST PPU_CONTROL_Type Type);

/**
* @brief         Mcu_Hw_Ppu_DisUserAccess
* @details       Ppu control all modules disenable user access permision
* @param[in]     Type - the moudle will be disenable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Ppu_DisUserAccess(TT_CONST PPU_CONTROL_Type Type);


/**
* @brief         Mcu_Hw_Ppu_DisUserAccess
* @details       Ppu control all modules enable user access permision
* @param[in]     Type - the moudle will be enable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Ppu_EnUserAccess(TT_CONST PPU_CONTROL_Type Type);

/**
* @brief        Mcu_Hw_Ppu_Config
* @details      Service to Set PPU Config
* @param[in]    McuPpuSettingConfig - PPU setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Ppu_Config(TT_CONST Mcu_Hw_PpuSettingConfigType *McuPpuSettingConfig);

/**
* @brief         Mcu_Hw_Ppu_GetErrStatus
* @details       Ppu get error Status
* @param[in]     Type - the moudle will be enable user access
* @param[out]    Status - error status
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Ppu_GetErrStatus(TT_CONST PPU_CONTROL_Type Type,uint32 *Status);

/**
* @brief         Mcu_Hw_Ppu_ClearErrStatus
* @details       Ppu Clear error Status
* @param[in]     Type - the moudle will be enable user access
* @param[out]    Status - error status
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
extern TT_RetType Mcu_Hw_Ppu_ClearErrStatus(TT_CONST PPU_CONTROL_Type Type);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MCU_PPU_HW_H */
