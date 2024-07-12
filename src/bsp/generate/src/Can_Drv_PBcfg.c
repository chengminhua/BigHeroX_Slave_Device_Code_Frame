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
**  FILENAME     : Can_Drv_PBcfg.c                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Can Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Drv.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/

#define CAN_DRV_PBCFG_VENDOR_ID_C                     1541
#define CAN_DRV_PBCFG_MODULE_ID_C                     80
#define CAN_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CAN_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define CAN_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C      0
#define CAN_DRV_PBCFG_SW_MAJOR_VERSION_C              1
#define CAN_DRV_PBCFG_SW_MINOR_VERSION_C              1
#define CAN_DRV_PBCFG_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and Can_Drv.h are of the same vendor */
#if (CAN_DRV_PBCFG_VENDOR_ID_C != CAN_DRV_VENDOR_ID_H)
    #error "Can_Drv_PBcfg.c and Can_Drv.h have different vendor ids"
#endif
#if (CAN_DRV_PBCFG_MODULE_ID_C != CAN_DRV_MODULE_ID_H)
    #error "Can_Drv_PBcfg.c and Can_Drv.h have different module ids"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != CAN_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C    != CAN_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C != CAN_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Can_Drv_PBcfg.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Software version */
#if ((CAN_DRV_PBCFG_SW_MAJOR_VERSION_C != CAN_DRV_SW_MAJOR_VERSION_H) || \
     (CAN_DRV_PBCFG_SW_MINOR_VERSION_C != CAN_DRV_SW_MINOR_VERSION_H) || \
     (CAN_DRV_PBCFG_SW_PATCH_VERSION_C != CAN_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_Drv_PBcfg.c and Can_Drv.h are different"
#endif
/******************************************************************************
*                            Public Variables
*******************************************************************************/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

/**
* @brief   Export FLEXCAN configurations.
*/
TT_CONST Can_Drv_HwChannelConfigType CanIpwHwChannelConfig0 =
{
    /* Here should be included the structure from FLEXCAN_HW_CFg*/
    &Flexcan_aCtrlConfigPB[0U]
};
TT_CONST Can_Drv_HwChannelConfigType CanIpwHwChannelConfig1 =
{
    /* Here should be included the structure from FLEXCAN_HW_CFg*/
    &Flexcan_aCtrlConfigPB[1U]
};
TT_CONST Can_Drv_HwChannelConfigType CanIpwHwChannelConfig2 =
{
    /* Here should be included the structure from FLEXCAN_HW_CFg*/
    &Flexcan_aCtrlConfigPB[2U]
};


#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

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
#endif
/** @} */
