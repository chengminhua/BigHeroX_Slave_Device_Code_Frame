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
**  FILENAME     : Gtm_Drv_Interrupt_Cfg.h                                    **
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

#ifndef GTM_DRV_INTERRUPT_CFG_H
#define GTM_DRV_INTERRUPT_CFG_H

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
#define GTM_DRV_INTERRUPT_CFG_VENDOR_ID_H       1541
#define GTM_DRV_INTERRUPT_CFG_MODULE_ID_H       221

#define GTM_DRV_INTERRUPT_CFG_AR_RELEASE_MAJOR_VERSION_H     4
#define GTM_DRV_INTERRUPT_CFG_AR_RELEASE_MINOR_VERSION_H     4
#define GTM_DRV_INTERRUPT_CFG_AR_RELEASE_PATCH_VERSION_H     0

#define GTM_DRV_INTERRUPT_CFG_SW_MAJOR_VERSION_H    1
#define GTM_DRV_INTERRUPT_CFG_SW_MINOR_VERSION_H    1
#define GTM_DRV_INTERRUPT_CFG_SW_PATCH_VERSION_H    0
#define GTM_DRV_INTERRUPT_INSTANCE_ID_H             (0U)


/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and A8V2E_GTM.h header file are of the same vendor */
#if (GTM_DRV_INTERRUPT_CFG_VENDOR_ID_H != A8V2E_GTM_VENDOR_ID_H)
#error "Gtm_Drv_Interrupt_Cfg.h and A8V2E_GTM.h have different vendor ids"
#endif
/* Check if current file and A8V2E_GTM.h header file are of the same Autosar version */
#if ((GTM_DRV_INTERRUPT_CFG_AR_RELEASE_MAJOR_VERSION_H   != A8V2E_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
    (GTM_DRV_INTERRUPT_CFG_AR_RELEASE_MINOR_VERSION_H    != A8V2E_GTM_AR_RELEASE_MINOR_VERSION_H) || \
    (GTM_DRV_INTERRUPT_CFG_AR_RELEASE_PATCH_VERSION_H    != A8V2E_GTM_AR_RELEASE_REVISION_VERSION_H))
#error "AutoSar Version Numbers of Gtm_Drv_Interrupt_Cfg.h and A8V2E_GTM.h are different"
#endif
/* Check if current file and A8V2E_GTM.h header file are of the same Software version */
#if ((GTM_DRV_INTERRUPT_CFG_SW_MAJOR_VERSION_H != A8V2E_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_INTERRUPT_CFG_SW_MINOR_VERSION_H != A8V2E_GTM_SW_MINOR_VERSION_H) || \
     (GTM_DRV_INTERRUPT_CFG_SW_PATCH_VERSION_H != A8V2E_GTM_SW_PATCH_VERSION_H))
#error "Software Version Numbers of Gtm_Drv_Interrupt_Cfg.h and A8V2E_GTM.h are different"
#endif


/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define GTM_INTERRUPT_DEV_ERROR_DETECT                   (STD_OFF)

#define    GTM_INTERRUPT_LEVEL_MODE              (0U)
#define    GTM_INTERRUPT_PULSE_MODE              (1U)
#define    GTM_INTERRUPT_PULSE_NOTIFY_MODE       (2U)
#define    GTM_INTERRUPT_SINGLE_PULSE_MODE       (3U)




/* ---------------- TOM0 channel 0-1 interrupt Enable ---------------- */
#define TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM0 channel 2-3 interrupt Enable ---------------- */
#define TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM0 channel 4-5 interrupt Enable ---------------- */
#define TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM0 channel 6-7 interrupt Enable ---------------- */
#define TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM0 channel 8-9 interrupt Enable ---------------- */
#define TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM0 channel 10-11 interrupt Enable ---------------- */
#define TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM0 channel 12-13 interrupt Enable ---------------- */
#define TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM0 channel 14-15 interrupt Enable ---------------- */
#define TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM1 channel 0-1 interrupt Enable ---------------- */
#define TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM1 channel 2-3 interrupt Enable ---------------- */
#define TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM1 channel 4-5 interrupt Enable ---------------- */
#define TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM1 channel 6-7 interrupt Enable ---------------- */
#define TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM1 channel 8-9 interrupt Enable ---------------- */
#define TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM1 channel 10-11 interrupt Enable ---------------- */
#define TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM1 channel 12-13 interrupt Enable ---------------- */
#define TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE   (FALSE)

/* ---------------- TOM1 channel 14-15 interrupt Enable ---------------- */
#define TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE   (FALSE)


/******************************************************************************
*                            Defines Check
*******************************************************************************/
#ifndef GTM_INTERRUPT_DEV_ERROR_DETECT
    #error "GTM_INTERRUPT_DEV_ERROR_DETECT not define error"
#endif
#if ((GTM_INTERRUPT_DEV_ERROR_DETECT != STD_OFF) && (GTM_INTERRUPT_DEV_ERROR_DETECT != STD_ON))
    #error "GTM_INTERRUPT_DEV_ERROR_DETECT config error"
#endif


/* ---------------- TOM0 channel interrupt Enable check ---------------- */
#ifndef TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE
    #error "TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE
    #error "TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE
    #error "TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE
    #error "TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE
    #error "TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE
    #error "TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE
    #error "TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE
    #error "TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE config error"
#endif    
/* ---------------- TOM1 channel interrupt Enable check ---------------- */
#ifndef TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE
    #error "TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE
    #error "TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE
    #error "TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE
    #error "TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE
    #error "TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE
    #error "TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE
    #error "TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE config error"
#endif    
#ifndef TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE
    #error "TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE not define error"
#endif
#if ((TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE != TRUE) && (TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE != FALSE))
    #error "TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE config error"
#endif    

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

#endif /* GTM_INTERRUPT_CFG_H */

/** @} */


