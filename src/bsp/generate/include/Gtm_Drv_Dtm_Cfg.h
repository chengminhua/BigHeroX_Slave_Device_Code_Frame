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
**  FILENAME     : Gtm_Drv_Dtm_Cfg.h                                           **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


#ifndef GTM_DRV_DTM_CFG_H
#define GTM_DRV_DTM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "A8V2E_GTM.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_DRV_DTM_CFG_VENDOR_ID_H       1541
#define GTM_DRV_DTM_CFG_MODULE_ID_H       221

#define GTM_DRV_DTM_CFG_AR_RELEASE_MAJOR_VERSION_H     4
#define GTM_DRV_DTM_CFG_AR_RELEASE_MINOR_VERSION_H     4
#define GTM_DRV_DTM_CFG_AR_RELEASE_PATCH_VERSION_H     0

#define GTM_DRV_DTM_CFG_SW_MAJOR_VERSION_H    1
#define GTM_DRV_DTM_CFG_SW_MINOR_VERSION_H    1
#define GTM_DRV_DTM_CFG_SW_PATCH_VERSION_H    0
#define GTM_DRV_DTM_INSTANCE_ID_H             (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and A8V2E_GTM.h header file are of the same vendor */
#if (GTM_DRV_DTM_CFG_VENDOR_ID_H != A8V2E_GTM_VENDOR_ID_H)
#error "Gtm_Drv_Dtm_Cfg.h and A8V2E_GTM.h have different vendor ids"
#endif
/* Check if current file and A8V2E_GTM.h header file are of the same Autosar version */
#if ((GTM_DRV_DTM_CFG_AR_RELEASE_MAJOR_VERSION_H   != A8V2E_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
    (GTM_DRV_DTM_CFG_AR_RELEASE_MINOR_VERSION_H    != A8V2E_GTM_AR_RELEASE_MINOR_VERSION_H) || \
    (GTM_DRV_DTM_CFG_AR_RELEASE_PATCH_VERSION_H    != A8V2E_GTM_AR_RELEASE_REVISION_VERSION_H))
#error "AutoSar Version Numbers of Gtm_Drv_Dtm_Cfg.h and A8V2E_GTM.h are different"
#endif
/* Check if current file and A8V2E_GTM.h header file are of the same Software version */
#if ((GTM_DRV_DTM_CFG_SW_MAJOR_VERSION_H != A8V2E_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_DTM_CFG_SW_MINOR_VERSION_H != A8V2E_GTM_SW_MINOR_VERSION_H) || \
     (GTM_DRV_DTM_CFG_SW_PATCH_VERSION_H != A8V2E_GTM_SW_PATCH_VERSION_H))
#error "Software Version Numbers of Gtm_Drv_Dtm_Cfg.h and A8V2E_GTM.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

#define GTM_DTM_DEV_ERROR_DETECT                   (STD_OFF)
/**
 * @name    Dead time Output Polarity
 * @{
 */
#define DTM_NOT_INVERTED               (0U)
#define DTM_INVERTED                   (1U)
/** @} */

/**
 * @name    Dead time Update Mode
 * @{
 */
#define DTM_FALLING_EDGE_UPDATE        (0U)
#define DTM_RISING_EDGE_UPDATE         (1U)
/** @} */

/**
 * @name    Dead time clock source
 * @{
 */
#define DTM_SYS_CLK                    (0U)
#define DTM_CMU_CLK0                   (1U)
#define DTM_CMU_CLK1_FXCLK0            (2U)
#define DTM_CMU_CLK2_FXCLK1            (3U)
/** @} */

/**
 * @name    Dead time type
 * @{
 */
#define DTM_DEADTIME_DISABLED            (0U)
#define DTM_DEADTIME_STANDARD            (0U)
#define DTM_DEADTIME_CROSS_CHANNEL       (1U)
/** @} */

/* -------- DTM Enable -------- */
#define TT_GTM_USE_DTM           (FALSE)

/* -------- CDTM0 Enable -------- */
#define TT_GTM_USE_CDTM0       (FALSE)

/* -------- CDTM1 Enable -------- */
#define TT_GTM_USE_CDTM1       (FALSE)

/* -------- CDTM2 Enable -------- */
#define TT_GTM_USE_CDTM2       (FALSE)

/* -------- CDTM3 Enable -------- */
#define TT_GTM_USE_CDTM3       (FALSE)


/* -------- CDTM0 Settings -------- */
/* -------- DTM0 Settings --------- */
#define CDTM0_DTM0_ENABLED               (FALSE)

/* -------- DTM1 Settings --------- */
#define CDTM0_DTM1_ENABLED               (FALSE)

/* -------- DTM2 Settings --------- */
#define CDTM0_DTM2_ENABLED               (FALSE)

/* -------- DTM3 Settings --------- */
#define CDTM0_DTM3_ENABLED               (FALSE)

/* -------- DTM4 Settings --------- */
#define CDTM0_DTM4_ENABLED               (FALSE)

/* -------- DTM5 Settings --------- */
#define CDTM0_DTM5_ENABLED               (FALSE)

/* -------- CDTM1 Settings -------- */
/* -------- CDTM2 Settings -------- */
/* -------- CDTM3 Settings -------- */

/******************************************************************************
*                            Defines Check
*******************************************************************************/
#ifndef GTM_DTM_DEV_ERROR_DETECT
    #error "GTM_DTM_DEV_ERROR_DETECT not define error"
#endif
#if ((GTM_DTM_DEV_ERROR_DETECT != STD_ON) && (GTM_DTM_DEV_ERROR_DETECT != STD_OFF))
    #error "GTM_DTM_DEV_ERROR_DETECT config error"
#endif    

#ifndef TT_GTM_USE_DTM
    #error "TT_GTM_USE_DTM not define error"
#endif
#if ((TT_GTM_USE_DTM != TRUE) && (TT_GTM_USE_DTM != FALSE))
    #error "TT_GTM_USE_DTM config error"
#endif
#ifndef TT_GTM_USE_CDTM0
    #error "TT_GTM_USE_CDTM0 not define error"
#endif
#if ((TT_GTM_USE_CDTM0 != TRUE) && (TT_GTM_USE_CDTM0 != FALSE))
    #error "TT_GTM_USE_CDTM0 config error"
#endif
#ifndef TT_GTM_USE_CDTM1
    #error "TT_GTM_USE_CDTM1 not define error"
#endif
#if ((TT_GTM_USE_CDTM1 != TRUE) && (TT_GTM_USE_CDTM1 != FALSE))
    #error "TT_GTM_USE_CDTM1 config error"
#endif
#ifndef TT_GTM_USE_CDTM2
    #error "TT_GTM_USE_CDTM2 not define error"
#endif
#if ((TT_GTM_USE_CDTM2 != TRUE) && (TT_GTM_USE_CDTM2 != FALSE))
    #error "TT_GTM_USE_CDTM2 config error"
#endif
#ifndef TT_GTM_USE_CDTM3
    #error "TT_GTM_USE_CDTM3 not define error"
#endif
#if ((TT_GTM_USE_CDTM3 != TRUE) && (TT_GTM_USE_CDTM3 != FALSE))
    #error "TT_GTM_USE_CDTM3 config error"
#endif

/* -------- CDTM0 Settings -------- */
/* -------- CDTM0_DTM0 Settings --------- */
#ifndef CDTM0_DTM0_ENABLED
    #error "CDTM0_DTM0_ENABLED not define error"
#endif        
#if ((CDTM0_DTM0_ENABLED != TRUE) && (CDTM0_DTM0_ENABLED != FALSE))
    #error "CDTM0_DTM0_ENABLED config error"
#endif
/* -------- CDTM0_DTM1 Settings --------- */
#ifndef CDTM0_DTM1_ENABLED
    #error "CDTM0_DTM1_ENABLED not define error"
#endif        
#if ((CDTM0_DTM1_ENABLED != TRUE) && (CDTM0_DTM1_ENABLED != FALSE))
    #error "CDTM0_DTM1_ENABLED config error"
#endif
/* -------- CDTM0_DTM2 Settings --------- */
#ifndef CDTM0_DTM2_ENABLED
    #error "CDTM0_DTM2_ENABLED not define error"
#endif        
#if ((CDTM0_DTM2_ENABLED != TRUE) && (CDTM0_DTM2_ENABLED != FALSE))
    #error "CDTM0_DTM2_ENABLED config error"
#endif
/* -------- CDTM0_DTM3 Settings --------- */
#ifndef CDTM0_DTM3_ENABLED
    #error "CDTM0_DTM3_ENABLED not define error"
#endif        
#if ((CDTM0_DTM3_ENABLED != TRUE) && (CDTM0_DTM3_ENABLED != FALSE))
    #error "CDTM0_DTM3_ENABLED config error"
#endif
/* -------- CDTM0_DTM4 Settings --------- */
#ifndef CDTM0_DTM4_ENABLED
    #error "CDTM0_DTM4_ENABLED not define error"
#endif        
#if ((CDTM0_DTM4_ENABLED != TRUE) && (CDTM0_DTM4_ENABLED != FALSE))
    #error "CDTM0_DTM4_ENABLED config error"
#endif
/* -------- CDTM0_DTM5 Settings --------- */
#ifndef CDTM0_DTM5_ENABLED
    #error "CDTM0_DTM5_ENABLED not define error"
#endif        
#if ((CDTM0_DTM5_ENABLED != TRUE) && (CDTM0_DTM5_ENABLED != FALSE))
    #error "CDTM0_DTM5_ENABLED config error"
#endif
/* -------- CDTM1 Settings -------- */
/* -------- CDTM2 Settings -------- */
/* -------- CDTM3 Settings -------- */

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

#endif /* GTM_DTM_CFG_H */

/** @} */


