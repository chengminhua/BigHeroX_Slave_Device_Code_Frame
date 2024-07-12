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
**  FILENAME     : TT.h                                                       **
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
*                            History                                          ** 
*[V1.1.0]:                                                                    ** 
*******************************************************************************/
#ifndef TT_H
#define TT_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#include "Base_TT_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_VENDOR_ID_H                     1541
#define TT_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_AR_RELEASE_MINOR_VERSION_H      4
#define TT_AR_RELEASE_PATCH_VERSION_H      0
#define TT_SW_MAJOR_VERSION_H              1
#define TT_SW_MINOR_VERSION_H              1
#define TT_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* TT.h and Base_TT_Cfg.h file version check */
#if (TT_VENDOR_ID_H != BASE_TT_CFG_VENDOR_ID_H)
    #error "TT.h and Base_TT_Cfg.h have different vendor id"
#endif
#if ((TT_AR_RELEASE_MAJOR_VERSION_H != BASE_TT_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_AR_RELEASE_MINOR_VERSION_H != BASE_TT_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_AR_RELEASE_PATCH_VERSION_H != BASE_TT_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT.h and Base_TT_Cfg.h are different"
#endif
#if ((TT_SW_MAJOR_VERSION_H != BASE_TT_CFG_SW_MAJOR_VERSION_H) || \
     (TT_SW_MINOR_VERSION_H != BASE_TT_CFG_SW_MINOR_VERSION_H) || \
     (TT_SW_PATCH_VERSION_H != BASE_TT_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT.h and Base_TT_Cfg.h are different"
#endif

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
#endif

#endif /* #ifndef TT_H */

