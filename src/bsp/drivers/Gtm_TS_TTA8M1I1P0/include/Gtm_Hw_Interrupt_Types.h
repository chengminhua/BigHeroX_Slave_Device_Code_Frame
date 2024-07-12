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
**  FILENAME     : Gtm_Hw_Interrupt_Types.h                                   **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Gtm Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef GTM_HW_INTERRUPT_TYPES_H
#define GTM_HW_INTERRUPT_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Base.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_INTERRUPT_TYPES_VENDOR_ID_H                      1541
#define GTM_HW_INTERRUPT_TYPES_MODULE_ID_H                      221
#define GTM_HW_INTERRUPT_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_INTERRUPT_TYPES_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_INTERRUPT_TYPES_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_INTERRUPT_TYPES_SW_MAJOR_VERSION_H               1
#define GTM_HW_INTERRUPT_TYPES_SW_MINOR_VERSION_H               1
#define GTM_HW_INTERRUPT_TYPES_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Base.h Gtm_Hw_Interrput_Types.h file version check */
#if (GTM_HW_BASE_VENDOR_ID_H != GTM_HW_INTERRUPT_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Interrput_Types.h have different vendor ids"
#endif

#if (GTM_HW_BASE_MODULE_ID_H != GTM_HW_INTERRUPT_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Interrput_Types.h have different module ids"
#endif

#if ((GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_INTERRUPT_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H != GTM_HW_INTERRUPT_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H != GTM_HW_INTERRUPT_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Interrput_Types.h are different"
#endif

#if ((GTM_HW_BASE_SW_MAJOR_VERSION_H != GTM_HW_INTERRUPT_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_SW_MINOR_VERSION_H != GTM_HW_INTERRUPT_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_BASE_SW_PATCH_VERSION_H != GTM_HW_INTERRUPT_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Interrput_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/****************** TIM Module ******************/
/* Tim interrupt enable value */
#define TIM_INTTERRUPT_ENABLE     (1U)

/* The bit value in the Tim interrupt event register */
#define TIM_NEWVAL_EVENT          (0x1U)
#define TIM_ECNTOFL_EVENT         (0x2U)
#define TIM_CNTOFL_EVENT          (0x4U)
#define TIM_GPROFL_EVENT          (0x8U)
#define TIM_TODET_EVENT           (0x10U)
#define TIM_GLITCHDET_EVENT       (0x20U)

/****************** TOM Module ******************/
/* Tom interrupt enable value */
#define TOM_INTTERRUPT_ENABLE     (1U)

/* The bit value in the Tom interrupt event register */
#define TOM_CCU0TC_EVENT          (0x1U)
#define TOM_CCU1TC_EVENT          (0x2U)

/******************************************************************************
*                            Enums
*******************************************************************************/


/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* Tim interrupt callback function pointer type */
typedef void (*TimNotifation)(uint8 event);

/* Tom interrupt callback function pointer type */
typedef void (*TomNotifation)(uint8 event);

/* Tim interrupt information structure type */
typedef struct  {
    /* Tim channel register address pointer */
    volatile GTM_TIM_CH_bf_type *timChannel;
    /* Tim interrupt callback function pointer */
    volatile TimNotifation  timNotifacation;
    /* Tim private data pointer */
    volatile void *         priv;
}Gtm_TimIntInfoType;

/* Tom interrupt information structure type */
typedef struct  {
    /* Tom channel register address pointer */
    volatile GTM_TOM_CH_bf_type *tomChannel;
    /* Tom interrupt callback function pointer */
    volatile TomNotifation  tomNotifacation;
    /* Tom private data pointer */
    volatile void *         priv;
}Gtm_TomIntInfoType;



#ifdef __cplusplus
}
#endif

#endif /* _Alioth_Gtm_Interrupt_H_ */
/** @} */
