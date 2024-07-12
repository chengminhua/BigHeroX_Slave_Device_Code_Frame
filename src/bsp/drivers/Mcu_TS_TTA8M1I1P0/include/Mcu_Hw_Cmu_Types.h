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
**  FILENAME     : Mcu_Hw_Cmu_Types.h                                         **
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

#ifndef MCU_HW_CMU_TYPES_H
#define MCU_HW_CMU_TYPES_H
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_CMU_TYPES_VENDOR_ID_H                     1541
#define MCU_HW_CMU_TYPES_MODULE_ID_H                     101
#define MCU_HW_CMU_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_HW_CMU_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_HW_CMU_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_HW_CMU_TYPES_SW_MAJOR_VERSION_H              1
#define MCU_HW_CMU_TYPES_SW_MINOR_VERSION_H              1
#define MCU_HW_CMU_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Cmu_Types.h and Mcu_Cfg.h file version check */
#if (MCU_HW_CMU_TYPES_VENDOR_ID_H != MCU_CFG_VENDOR_ID_H)
    #error "Mcu_Hw_Cmu_Types.h and Mcu_Cfg.h have different vendor id"
#endif
#if (MCU_HW_CMU_TYPES_MODULE_ID_H != MCU_CFG_MODULE_ID_H)
    #error "Mcu_Hw_Cmu_Types.h and Mcu_Cfg.h have different module id"
#endif
#if ((MCU_HW_CMU_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCU_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CMU_TYPES_AR_RELEASE_MINOR_VERSION_H != MCU_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CMU_TYPES_AR_RELEASE_PATCH_VERSION_H != MCU_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Cmu_Types.h and Mcu_Cfg.h are different"
#endif
#if ((MCU_HW_CMU_TYPES_SW_MAJOR_VERSION_H != MCU_CFG_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CMU_TYPES_SW_MINOR_VERSION_H != MCU_CFG_SW_MINOR_VERSION_H) || \
     (MCU_HW_CMU_TYPES_SW_PATCH_VERSION_H != MCU_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Cmu_Types.h and Mcu_Cfg.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Cmu alarm type assert */
#define MCU_CMU_ALARM_TYPE_ASSERT(alarm) ((alarm & ((uint32)MCU_CMU_TYPE_HTH | (uint32)MCU_CMU_TYPE_LTH | (uint32)MCU_CMU_TYPE_TIMEOUT)) > 0)

/******************************************************************************
*                            Enums
*******************************************************************************/
/* Cmu alarm type */
typedef enum
{
    MCU_CMU_TYPE_HTH     = 0x2,
    MCU_CMU_TYPE_LTH     = 0x4,
    MCU_CMU_TYPE_TIMEOUT = 0x8
}MCU_CMU_ALARM_TYPE;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
/* Cmu config index in EB */
typedef uint8 Mcu_CmuType;

/* Cmu config */
typedef struct
{
    uint8   CmuIndex;                     /* Cmu index */
    boolean CmuTimeoutAlarmEn;            /* Cmu timeout alarm enbale */
    boolean CmuLthdAlarmEn;               /* Cmu low threshold value alarm enbale */
    boolean CmuHthdAlarmEn;               /* Cmu high threshold value alarm enbale */
    uint32  CmuChkwAlarmVal;              /* Cmu detection window alarm value  */
    uint32  CmuLthdAlarmVal;              /* Cmu low threshold alarm value  */
    uint32  CmuHthdAlarmVal;              /* Cmu high threshold alarm value  */
}Mcu_Hw_CmuConfigType;
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* CDD_EIM_ALIOTH_H */
