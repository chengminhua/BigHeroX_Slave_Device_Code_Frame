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
**  FILENAME     : Base_Drv_Types.h                                           **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Base Driver Source File                                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef BASE_CFG_TYPESDEF_H
#define BASE_CFG_TYPESDEF_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Base_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_DRV_TYPES_VENDOR_ID_H                     1541
#define BASE_DRV_TYPES_MODULE_ID_H                     218
#define BASE_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define BASE_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define BASE_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define BASE_DRV_TYPES_SW_MAJOR_VERSION_H              1
#define BASE_DRV_TYPES_SW_MINOR_VERSION_H              1
#define BASE_DRV_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Drv_Types.h and Base_Cfg.h file version check */
#if (BASE_DRV_TYPES_VENDOR_ID_H != BASE_CFG_VENDOR_ID_H)
    #error "Base_Drv_Types.h and Base_Cfg.h have different vendor id"
#endif
#if (BASE_DRV_TYPES_MODULE_ID_H != BASE_CFG_MODULE_ID_H)
    #error "Base_Drv_Types.h and Base_Cfg.h have different module id"
#endif
#if ((BASE_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != BASE_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != BASE_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != BASE_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Drv_Types.h and Base_Cfg.h are different"
#endif
#if ((BASE_DRV_TYPES_SW_MAJOR_VERSION_H != BASE_CFG_SW_MAJOR_VERSION_H) || \
     (BASE_DRV_TYPES_SW_MINOR_VERSION_H != BASE_CFG_SW_MINOR_VERSION_H) || \
     (BASE_DRV_TYPES_SW_PATCH_VERSION_H != BASE_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Drv_Types.h and Base_Cfg.h are different"
#endif

#if STD_ON == BASE_DEV_ERROR_DETECT
/* Base_Drv_Types.h and TT_Devassert.h file version check */
#if (BASE_DRV_TYPES_VENDOR_ID_H != TT_DEVASSERT_VENDOR_ID_H)
    #error "Base_Drv_Types.h and TT_Devassert.h have different vendor id"
#endif
#if ((BASE_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != TT_DEVASSERT_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != TT_DEVASSERT_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != TT_DEVASSERT_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Drv_Types.h and TT_Devassert.h are different"
#endif
#if ((BASE_DRV_TYPES_SW_MAJOR_VERSION_H != TT_DEVASSERT_SW_MAJOR_VERSION_H) || \
     (BASE_DRV_TYPES_SW_MINOR_VERSION_H != TT_DEVASSERT_SW_MINOR_VERSION_H) || \
     (BASE_DRV_TYPES_SW_PATCH_VERSION_H != TT_DEVASSERT_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Drv_Types.h and TT_Devassert.h are different"
#endif
#else
#endif /* STD_ON == BASE_DEV_ERROR_DETECT */

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

/* BASE INIT Service IDs */
#define BASE_DRV_SI_INIT                        ((uint8)100U)
/* BASE UNINIT Service IDs */
#define BASE_DRV_SI_UNINIT                      ((uint8)101U)
/* BASE GET COUNTER Service IDs */
#define BASE_DRV_SI_GET_COUNTER                 ((uint8)102U)
/* BASE GET ELAPSED Service IDs */
#define BASE_DRV_SI_GET_ELAPSED                 ((uint8)103U)
/* BASE MICROS_TO_TICKS Service IDs */
#define BASE_DRV_SI_MICROS_TO_TICKS             ((uint8)104U)
/* BASE USDELAY Service IDs */
#define BASE_DRV_SI_USDELAY                     ((uint8)105U)
/* BASE MSDELAY Service IDs */
#define BASE_DRV_SI_MSDELAY                     ((uint8)106U)
/* BASE UNLOCK_PRET_REG Service IDs */
#define BASE_DRV_SI_UNLOCK_PRET_REG             ((uint8)107U)
/* BASE LOCK_PRET_REG Service IDs */
#define BASE_DRV_SI_LOCK_PRET_REG               ((uint8)108U)

/* BASE DET Error Codes */                    
#define BASE_E_UNINIT                            (0x01U)
#define BASE_E_INV_API                           (0x02U)
#define BASE_E_INV_CORE_IDX                      (0x03U)
#define BASE_E_INIT_FAILED                       (0x04U)

/* Base Hz */
#define BASE_HZ                                 (1000U)
/* External clock */
#define BASE_SYSTICK_EXT_CLK                    (8000000U)
/*  */
#define BASE_CHECK_TT_STATUS_DEFAULT(ApiID)     (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET) | \
                                                             ((ApiID) << TT_APIID_OFFSET) | \
                                                             (BASE_MODULE_ID << TT_MODULEID_OFFSET))

/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/

/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */
  
#endif /* BASE_CFG_TYPESDEF_H */
