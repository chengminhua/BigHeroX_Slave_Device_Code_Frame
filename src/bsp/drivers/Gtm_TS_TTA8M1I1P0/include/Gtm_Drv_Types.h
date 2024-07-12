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
**  FILENAME     : Gtm_Drv_Types.h                                            **
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
#ifndef GTM_DRV_TYPES_H
#define GTM_DRV_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Dtm_Types.h"
#include "Gtm_Hw_Tbu_Types.h"
#include "Gtm_Hw_Cmu_Types.h"
#include "Gtm_Hw_Tim_Types.h"
#include "Gtm_Hw_Tom_Types.h"
#include "Gtm_Hw_Interrupt_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_DRV_TYPES_VENDOR_ID_H                      1541
#define GTM_DRV_TYPES_MODULE_ID_H                      221
#define GTM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_DRV_TYPES_SW_MAJOR_VERSION_H               1
#define GTM_DRV_TYPES_SW_MINOR_VERSION_H               1
#define GTM_DRV_TYPES_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Dtm_Types.h Gtm_Drv_Types.h file version check */
#if (GTM_DRV_TYPES_VENDOR_ID_H != GTM_HW_DTM_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Dtm_Types.h and Gtm_Drv_Types.h have different vendor ids"
#endif

#if (GTM_DRV_TYPES_MODULE_ID_H != GTM_HW_DTM_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Dtm_Types.h and Gtm_Drv_Types.h have different module ids"
#endif

#if ((GTM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_DTM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_DTM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_DTM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Dtm_Types.h and Gtm_Drv_Types.h are different"
#endif

#if ((GTM_DRV_TYPES_SW_MAJOR_VERSION_H != GTM_HW_DTM_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_MINOR_VERSION_H != GTM_HW_DTM_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_PATCH_VERSION_H != GTM_HW_DTM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Dtm_Types.h and Gtm_Drv_Types.h are different"
#endif


/* Gtm_Hw_Tbu_Types.h Gtm_Drv_Types.h file version check */
#if (GTM_DRV_TYPES_VENDOR_ID_H != GTM_HW_TBU_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Tbu_Types.h and Gtm_Drv_Types.h have different vendor ids"
#endif

#if (GTM_DRV_TYPES_MODULE_ID_H != GTM_HW_TBU_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Tbu_Types.h and Gtm_Drv_Types.h have different module ids"
#endif

#if ((GTM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tbu_Types.h and Gtm_Drv_Types.h are different"
#endif

#if ((GTM_DRV_TYPES_SW_MAJOR_VERSION_H != GTM_HW_TBU_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_MINOR_VERSION_H != GTM_HW_TBU_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_PATCH_VERSION_H != GTM_HW_TBU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tbu_Types.h and Gtm_Drv_Types.h are different"
#endif

/* Gtm_Hw_Cmu_Types.h Gtm_Drv_Types.h file version check */
#if (GTM_DRV_TYPES_VENDOR_ID_H != GTM_HW_CMU_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Cmu_Types.h and Gtm_Drv_Types.h have different vendor ids"
#endif

#if (GTM_DRV_TYPES_MODULE_ID_H != GTM_HW_CMU_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Cmu_Types.h and Gtm_Drv_Types.h have different module ids"
#endif

#if ((GTM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_CMU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_CMU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_CMU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Cmu_Types.h and Gtm_Drv_Types.h are different"
#endif

#if ((GTM_DRV_TYPES_SW_MAJOR_VERSION_H != GTM_HW_CMU_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_MINOR_VERSION_H != GTM_HW_CMU_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_PATCH_VERSION_H != GTM_HW_CMU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Cmu_Types.h and Gtm_Drv_Types.h are different"
#endif

/* Gtm_Hw_Tim_Types.h Gtm_Drv_Types.h file version check */
#if (GTM_DRV_TYPES_VENDOR_ID_H != GTM_HW_TIM_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Tim_Types.h and Gtm_Drv_Types.h have different vendor ids"
#endif

#if (GTM_DRV_TYPES_MODULE_ID_H != GTM_HW_TIM_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Tim_Types.h and Gtm_Drv_Types.h have different module ids"
#endif

#if ((GTM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tim_Types.h and Gtm_Drv_Types.h are different"
#endif

#if ((GTM_DRV_TYPES_SW_MAJOR_VERSION_H != GTM_HW_TIM_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_MINOR_VERSION_H != GTM_HW_TIM_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_PATCH_VERSION_H != GTM_HW_TIM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tim_Types.h and Gtm_Drv_Types.h are different"
#endif

/* Gtm_Hw_Tom_Types.h Gtm_Drv_Types.h file version check */
#if (GTM_DRV_TYPES_VENDOR_ID_H != GTM_HW_TOM_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Tom_Types.h and Gtm_Drv_Types.h have different vendor ids"
#endif

#if (GTM_DRV_TYPES_MODULE_ID_H != GTM_HW_TOM_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Tom_Types.h and Gtm_Drv_Types.h have different module ids"
#endif

#if ((GTM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tom_Types.h and Gtm_Drv_Types.h are different"
#endif

#if ((GTM_DRV_TYPES_SW_MAJOR_VERSION_H != GTM_HW_TOM_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_MINOR_VERSION_H != GTM_HW_TOM_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_PATCH_VERSION_H != GTM_HW_TOM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tom_Types.h and Gtm_Drv_Types.h are different"
#endif

/* Gtm_Hw_Interrupt_Types.h Gtm_Drv_Types.h file version check */
#if (GTM_DRV_TYPES_VENDOR_ID_H != GTM_HW_INTERRUPT_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Interrupt_Types.h and Gtm_Drv_Types.h have different vendor ids"
#endif

#if (GTM_DRV_TYPES_MODULE_ID_H != GTM_HW_INTERRUPT_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Interrupt_Types.h and Gtm_Drv_Types.h have different module ids"
#endif

#if ((GTM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_INTERRUPT_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_INTERRUPT_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_INTERRUPT_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Interrupt_Types.h and Gtm_Drv_Types.h are different"
#endif

#if ((GTM_DRV_TYPES_SW_MAJOR_VERSION_H != GTM_HW_INTERRUPT_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_MINOR_VERSION_H != GTM_HW_INTERRUPT_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_DRV_TYPES_SW_PATCH_VERSION_H != GTM_HW_INTERRUPT_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Interrupt_Types.h and Gtm_Drv_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Macro definitions for API Service ID */
#define GTM_INIT_ID                                 (0x00U)
#define GTM_DEINIT_ID                               (0x01U)
#define GTM_CMU_START_ID                            (0x02U)
#define GTM_CMU_STOP_ID                             (0x03U)
#define GTM_CMU_GET_CLOCK_ID                        (0x04U)
#define GTM_CMU_SET_CLOCK_ID                        (0x05U)

#define GTM_TBU_SATRT_ID                            (0x06U)
#define GTM_TBU_STOP_ID                             (0x07U)
#define GTM_TBU_START_CHANNEL_ID                    (0x08U)
#define GTM_TBU_STOP_CHANNEL_ID                     (0x09U)
#define GTM_TBU_SET_CLOCK_CHANNEL_ID                (0x0AU)
#define GTM_TBU_GET_CLOCK_CHANNEL_ID                (0x0BU)
#define GTM_TBU_SET_TIME_BASE_CHANNEL_ID            (0x0CU)
#define GTM_TBU_GET_TIME_BASE_CHANNEL_ID            (0x0DU)
#define GTM_TBU_SET_LOW_RES_CHANNEL0_ID             (0x0EU)
#define GTM_TBU_GET_LOW_RES_CHANNEL0_ID             (0x0FU)
#define GTM_TBU_SET_RUNNING_MODE_CHANNEL12_ID       (0x10U)
#define GTM_TBU_GET_RUNNING_MODE_CHANNEL12_ID       (0x11U)

#define GTM_TOM_INIT_ID                             (0x12U)
#define GTM_TOM_CHANNEL_ENABLE_ID                   (0x13U)
#define GTM_TOM_CHANNEL_DISABLE_ID                  (0x14U)
#define GTM_TOM_SET_HOST_TRIGGER_ID                 (0x15U)
#define GTM_TOM_SET_UPDATE_CTRL_ID                  (0x16U)
#define GTM_TOM_SET_COUNTER_CN0_ID                  (0x17U)
#define GTM_TOM_GET_COUNTER_CN0_ID                  (0x18U)
#define GTM_TOM_SET_COUNTER_CM0_ID                  (0x19U)
#define GTM_TOM_GET_COUNTER_CM0_ID                  (0x1AU)
#define GTM_TOM_SET_COUNTER_CM1_ID                  (0x1BU)
#define GTM_TOM_GET_COUNTER_CM1_ID                  (0x1CU)
#define GTM_TOM_SET_COUNTER_SR0_ID                  (0x1DU)
#define GTM_TOM_GET_COUNTER_SR0_ID                  (0x1EU)
#define GTM_TOM_SET_COUNTER_SR1_ID                  (0x1FU)
#define GTM_TOM_GET_COUNTER_SR1_ID                  (0x20U)
#define GTM_TOM_SET_INT_ID                          (0x21U)

#define GTM_TIM_INIT_ID                             (0x22U)
#define GTM_TIM_START_MEASURE_ID                    (0x23U)
#define GTM_TIM_STOP_MEASURE_ID                     (0x24U)
#define GTM_TIM_GET_PWM_INFORMATION_ID              (0x25U)
#define GTM_TIM_GET_MEASURE_INFORMATION_ID          (0x26U)
#define GTM_TIM_GET_PULSE_TIME_ID                   (0x27U)
#define GTM_TIM_GET_STATUS_FLAGS_ID                 (0x28U)
#define GTM_TIM_CLEAR_STATUS_FLAGS_ID               (0x29U)
#define GTM_TIM_SET_VALUE_ID                        (0x2AU)
#define GTM_TIM_SET_INT_ID                          (0x2BU)

#define GTM_DTM_START_ID                            (0x2CU)
#define GTM_DTM_STOP_ID                             (0x2DU)
#define GTM_DTM_SETDEADTIME_ID                      (0x32U)

#define GTM_Monitor_ClSCLK_ID                       (0x2EU)
#define GTM_Monitor_TIMINPUT_ID                     (0x2FU)

#define GTM_INITCHECK_ID                            (0x30U)
#define GTM_GETVERSIONINFO_ID                       (0x31U)

/******************************************************************************
*                            Enums
*******************************************************************************/
/* GTM initialization state flag */
typedef enum {
    GTM_STATE_UNINITIALIZED,
    GTM_STATE_INITIALIZED,
} Gtm_StateTypeDef;

/* GTM module operating status flag */
typedef enum {
    GTM_STATUS_UNINITIALIZED,
    GTM_STATUS_INITIALIZED,
    GTM_STATUS_RUNNING,
    GTM_STATUS_STOPPED
} Gtm_StatusTypeDef;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* CMU status flag structure type */
typedef struct {
    Gtm_StatusTypeDef cmuStatus;
} Gtm_CmuFlagTypeDef;

/* Tbu status flag structure type */
typedef struct {
    Gtm_StatusTypeDef TbuChannelStatus[4];
} Gtm_TbuFlagTypeDef;

/* Tim status flag structure type */
typedef struct {
    Gtm_StatusTypeDef TimChannelStatus[TIM_MAX + 1U];
    Tim_ChannelModeSelectType TimChannelMode[TIM_MAX + 1U];
} Gtm_TimFlagTypeDef;

/* Tom status flag structure type */
typedef struct {
    Gtm_StatusTypeDef TomChannelStatus[TOM_MAX + 1U];
} Gtm_TomFlagTypeDef;

/* Cdtm status flag structure type */
typedef struct {
    Gtm_StatusTypeDef CdtmChannelStatus[6];
} Gtm_CdtmFlagTypeDef;

/* Gtm All submodule status flag structure type */
typedef struct {
    /* Gtm initialization flag */
    Gtm_StateTypeDef    GtmInitState;
    /* Cmu working status flag */
    Gtm_CmuFlagTypeDef  CmuFlag;
    /* Tbu working status flag */
    Gtm_TbuFlagTypeDef  TbuFlag;
    /* Tim working status flag */
    Gtm_TimFlagTypeDef  TimFlag;
    /* Tom working status flag */
    Gtm_TomFlagTypeDef  TomFlag;
    /* Cdtm working status flag */
    Gtm_CdtmFlagTypeDef CdtmFlag[4];
} Gtm_FlagTypeDef;

/************************ Type for Module configuration ***********************/
/*The structure contains the configuration parameters of the GTM driver.*/
typedef struct
{
    /* Tbu configuration poniter */
    TT_CONST Tbu_ConfigType *TbuConfig;
    /* Tom configuration poniter */
    TT_CONST Tom_ConfigType *TomConfig;
    /* Tim configuration poniter */
    TT_CONST Tim_ConfigType *TimConfig;
    /* Tom connnection triggerMux configuration poniter */
    TT_CONST Gtm_ConnectionsConfigType *GtmConnectionsConfig;
    /* Configure the Crc for data generation */
    TT_CONST uint32 Crc;
}Gtm_ConfigType;


#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */
