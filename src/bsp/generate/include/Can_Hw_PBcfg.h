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
**  FILENAME     : Can_HW_PBcfg.h                                             **
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

#ifndef CAN_HW_PBCFG_H
#define CAN_HW_PBCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_PBCFG_VENDOR_ID_H                     1541
#define FLEXCAN_HW_PBCFG_MODULE_ID_H                     80
#define FLEXCAN_HW_PBCFG_AR_RELEASE_MAJOR_VERSION_H      4
#define FLEXCAN_HW_PBCFG_AR_RELEASE_MINOR_VERSION_H      4
#define FLEXCAN_HW_PBCFG_AR_RELEASE_PATCH_VERSION_H      0
#define FLEXCAN_HW_PBCFG_SW_MAJOR_VERSION_H              1
#define FLEXCAN_HW_PBCFG_SW_MINOR_VERSION_H              1
#define FLEXCAN_HW_PBCFG_SW_PATCH_VERSION_H              0
/******************************************************************************
*                       File Version Checks
******************************************************************************/

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define FLEXCAN_HW_PB_CFG  \
    extern TT_CONST Flexcan_Hw_ConfigType Flexcan_aCtrlConfigPB[3U];

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CAN_HW_PBCFG_H */
