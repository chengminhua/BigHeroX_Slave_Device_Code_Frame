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
**  FILENAME     : Can_Drv_Types.h                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Can Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/

#ifndef CAN_DRV_TYPES_H
#define CAN_DRV_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Drv_Cfg.h"

#if (CAN_USE_FLEXCAN_HW  == STD_ON)
#include "Can_Hw.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_DRV_TYPES_VENDOR_ID_H                    1541
/* @violates @ref Can_DRV_Types_h_REF_1 2012 Advisory Rule 2.5. */
#define CAN_DRV_TYPES_MODULE_ID_H                    80
#define CAN_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H     4
#define CAN_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H     0
#define CAN_DRV_TYPES_SW_MAJOR_VERSION_H             1
#define CAN_DRV_TYPES_SW_MINOR_VERSION_H             1
#define CAN_DRV_TYPES_SW_PATCH_VERSION_H             0
/**@}*/

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#if (CAN_USE_FLEXCAN_HW  == STD_ON)
/* Check if current file and FlexCAN_Hw.h are of the same vendor */
#if (CAN_DRV_TYPES_VENDOR_ID_H != FLEXCAN_HW_VENDOR_ID_H)
#error "Can_DRV_Types.h and FlexCAN_Hw.h have different vendor ids"
#endif
#if (CAN_DRV_TYPES_MODULE_ID_H != FLEXCAN_HW_MODULE_ID_H)
    #error "Can_DRV_Types.h and FlexCAN_Hw.h have different module ids"
#endif
/* Check if current file and FlexCAN_Hw.h are of the same Autosar version */
#if ((CAN_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H))
  #error "AutoSar Version Numbers of Can_DRV_Types.h and FlexCAN_Hw.h are different"
#endif

/* Check if current file and FlexCAN_Hw.h are of the same software version */
#if ((CAN_DRV_TYPES_SW_MAJOR_VERSION_H != FLEXCAN_HW_SW_MAJOR_VERSION_H) || \
     (CAN_DRV_TYPES_SW_MINOR_VERSION_H != FLEXCAN_HW_SW_MINOR_VERSION_H) || \
     (CAN_DRV_TYPES_SW_PATCH_VERSION_H != FLEXCAN_HW_SW_PATCH_VERSION_H))
  #error "Software Version Numbers of Can_DRV_Types.h and FlexCAN_Hw.h are different"
#endif
#endif /* (CAN_USE_FLEXCAN_HW  == STD_ON) */

/* Check if current file and Can_Drv_Cfg.h are of the same vendor */
#if (CAN_DRV_TYPES_VENDOR_ID_H != CAN_DRV_CFG_VENDOR_ID_H)
#error "Can_DRV_Types.h and Can_Drv_Cfg.h have different vendor ids"
#endif
#if (CAN_DRV_TYPES_MODULE_ID_H != CAN_DRV_CFG_MODULE_ID_H)
    #error "Can_DRV_Types.h and Can_Drv_Cfg.h have different module ids"
#endif
/* Check if current file and Can_Drv_Cfg.h are of the same Autosar version */
#if ((CAN_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H !=    CAN_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H !=    CAN_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != CAN_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
  #error "AutoSar Version Numbers of Can_DRV_Types.h and Can_Drv_Cfg.h are different"
#endif
/* Check if current file and Can_Drv_Cfg.h are of the same software version */
#if ((CAN_DRV_TYPES_SW_MAJOR_VERSION_H != CAN_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (CAN_DRV_TYPES_SW_MINOR_VERSION_H != CAN_DRV_CFG_SW_MINOR_VERSION_H) || \
     (CAN_DRV_TYPES_SW_PATCH_VERSION_H != CAN_DRV_CFG_SW_PATCH_VERSION_H))
  #error "Software Version Numbers of Can_DRV_Types.h and Can_Drv_Cfg.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define CAN_DRV_SI_INIT                             (100U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_DEINIT                           (101U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_SET_BAUDRATE                     (102U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_SET_CONTROLLER_TO_START_MODE     (103U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_SET_LISTEN_ONLY_MODE             (104U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_SET_CONTROLLER_TO_STOP_MODE      (105U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_DISABLE_CONTROLLER_INTERRUPTS    (106U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_ENABLE_CONTROLLER_INTERRUPTS     (107U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_GET_CONTROLLER_ERROR_STATE       (108U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_GET_CONTROLLER_TX_ERROR_COUNTER  (109U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_GET_CONTROLLER_RX_ERROR_COUNTER  (110U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_WRITE                            (111U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_MAIN_FUNCTION_WRITE              (112U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_MAIN_FUNCTION_READ               (113U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_MAIN_FUNCTION_BUSOFF             (114U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_MAIN_FUNCTION_MODE               (115U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_DEACTIVATE_ICOM_CONFIGURATION    (116U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_SET_ICOM_CONFIGURATION           (117U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_INTERRUPTS_READ                  (118U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_INTERRUPTS_WRITE                 (119U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_INTERRUPTS_PN                    (119U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_ABORT_MB                         (120U)     /* Service ID For Can Drv API */
#define CAN_DRV_SI_CHECK_WAKEUP                     (121U)     /* Service ID For Can Drv API */

#define CAN_DRV_TT_STATUS_DEFAULT(ApiID)       (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET)       | \
                                                        ((ApiID) << TT_APIID_OFFSET) | \
                                                        (CAN_DRV_MODULE_ID_C << TT_MODULEID_OFFSET))

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/** @brief Can Hardware Config Type */
typedef struct {
TT_CONST Flexcan_Hw_ConfigType * pFlexcanIpHwConfig;
} Can_Drv_HwChannelConfigType;

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/** @brief Can pn Config Type */
typedef struct
{
    TT_CONST Flexcan_Hw_PnConfigType* pFlexcanIpPnConfig;
} Can_Drv_IcomRxMessageConfigsType;
#endif
/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
/******************************************************************************
*                            FUNCTION PROTOTYPES
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /*CAN_DRV_TYPES_H */

/** @} */
