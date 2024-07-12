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
**  FILENAME     : Mcu_Hw_Ppu_Types.h                                         **
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
#ifndef MCU_HW_PPU_TYPES_H
#define MCU_HW_PPU_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcu_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_PPU_TYPES_VENDOR_ID_H                     1541
#define MCU_HW_PPU_TYPES_MODULE_ID_H                     101
#define MCU_HW_PPU_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_PPU_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_PPU_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_PPU_TYPES_SW_MAJOR_VERSION_H              1
#define MCU_HW_PPU_TYPES_SW_MINOR_VERSION_H              1
#define MCU_HW_PPU_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Ppu_Types.h and Mcu_Cfg.h file version check */
#if (MCU_HW_PPU_TYPES_VENDOR_ID_H != MCU_CFG_VENDOR_ID_H)
    #error "Mcu_Hw_Ppu_Types.h and Mcu_Cfg.h have different vendor id"
#endif
#if (MCU_HW_PPU_TYPES_MODULE_ID_H != MCU_CFG_MODULE_ID_H)
    #error "Mcu_Hw_Ppu_Types.h and Mcu_Cfg.h have different module id"
#endif
#if ((MCU_HW_PPU_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PPU_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PPU_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Ppu_Types.h and Mcu_Cfg.h are different"
#endif
#if ((MCU_HW_PPU_TYPES_SW_MAJOR_VERSION_H != MCU_CFG_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PPU_TYPES_SW_MINOR_VERSION_H != MCU_CFG_SW_MINOR_VERSION_H) || \
     (MCU_HW_PPU_TYPES_SW_PATCH_VERSION_H != MCU_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Ppu_Types.h and Mcu_Cfg.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Ppu control type assert */
#define MCU_PPU_CONTROL_TYPE_ASSERT(type) ((((uint32)(type) <= (uint32)PPU_CONTROL_PPU)) || \
                                          (((uint32)(type) >= (uint32)PPU_APB1_START) && ((uint32)(type) <= (uint32)PPU_CONTROL_STCU)) || \
                                          (((uint32)(type) >= (uint32)PPU_APB4_START) && ((uint32)(type) <= (uint32)PPU_CONTROL_EIM)) || \
                                          (((uint32)(type) >= (uint32)PPU_APB5_START) && ((uint32)(type) <= (uint32)PPU_CONTROL_LIN15)) || \
                                          (((uint32)(type) >= (uint32)PPU_AHB0_START) && ((uint32)(type) <= (uint32)PPU_CONTROL_SPI6)) || \
                                          (((uint32)(type) >= (uint32)PPU_AHB1_START) && ((uint32)(type) <= (uint32)PPU_CONTROL_SPI7)) || \
                                          (((uint32)(type) == (uint32)PPU_CONTROL_GTM_AXIS)) || \
                                          ((uint32)(type) == (uint32)PPU_CONTROL_ALL))

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* Ppu Type */
typedef uint32 Mcu_PpuType;

/* Ppu config*/
typedef struct
{
    boolean McuPpuAPB1ConfigLock;   /* Ppu apb1 config lock */
    boolean McuPpuAPB2ConfigLock;   /* Ppu apb2 config lock */
    boolean McuPpuAPB3ConfigLock;   /* Ppu apb3 config lock */
    boolean McuPpuAPB4ConfigLock;   /* Ppu apb4 config lock */
    boolean McuPpuAPB5ConfigLock;   /* Ppu apb5 config lock */
    boolean McuPpuAHB0ConfigLock;   /* Ppu ahb0 config lock */
    boolean McuPpuAHB1ConfigLock;   /* Ppu ahb1 config lock */
    boolean McuPpuAHB4ConfigLock;   /* Ppu ahb4 config lock */

    uint32  McuPpuAPB1;             /* PPU control apb1 access mode (can access or not) */
    uint32  McuPpuAPB2;             /* PPU control apb2 access mode (can access or not) */
    uint32  McuPpuAPB3;             /* PPU control apb3 access mode (can access or not) */
    uint32  McuPpuAPB4;             /* PPU control apb4 access mode (can access or not) */
    uint32  McuPpuAPB5;             /* PPU control apb5 access mode (can access or not) */
    uint32  McuPpuAHB0;             /* PPU control ahb0 access mode (can access or not) */
    uint32  McuPpuAHB1;             /* PPU control ahb1 access mode (can access or not) */
    uint32  McuPpuAHB4;             /* PPU control ahb4 access mode (can access or not) */

    uint32  McuPpuSUAPB1;           /* PPU control apb1 access mode (User or Privilege) */
    uint32  McuPpuSUAPB2;           /* PPU control apb2 access mode (User or Privilege) */
    uint32  McuPpuSUAPB3;           /* PPU control apb3 access mode (User or Privilege) */
    uint32  McuPpuSUAPB4;           /* PPU control apb4 access mode (User or Privilege) */
    uint32  McuPpuSUAPB5;           /* PPU control apb5 access mode (User or Privilege) */
    uint32  McuPpuSUAHB0;           /* PPU control ahb0 access mode (User or Privilege) */
    uint32  McuPpuSUAHB1;           /* PPU control ahb1 access mode (User or Privilege) */
    uint32  McuPpuSUAHB4;           /* PPU control ahb4 access mode (User or Privilege) */
}Mcu_Hw_PpuSettingConfigType;
/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* MCU_HW_PPU_TYPES_H */
