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
**  FILENAME     : Can_Drv_PBcfg.h                                            **
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

#ifndef CAN_DRV_PBCFG_H
#define CAN_DRV_PBCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_DRV_PBCFG_VENDOR_ID_H                      1541
#define CAN_DRV_PBCFG_MODULE_ID_H                      80
#define CAN_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_H       4
#define CAN_DRV_PBCF_AR_RELEASE_MINOR_VERSIONG_H       4
#define CAN_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_H       0
#define CAN_DRV_PBCFG_SW_MAJOR_VERSION_H               1
#define CAN_DRV_PBCFG_SW_MINOR_VERSION_H               1
#define CAN_DRV_PBCFG_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define CAN_DRV_CONFIG_PB \
    extern TT_CONST Can_Drv_HwChannelConfigType CanIpwHwChannelConfig0;\
    extern TT_CONST Can_Drv_HwChannelConfigType CanIpwHwChannelConfig1;\
    extern TT_CONST Can_Drv_HwChannelConfigType CanIpwHwChannelConfig2;

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

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _CAN_DRV_PBCFG_H_ */

/** @} */
