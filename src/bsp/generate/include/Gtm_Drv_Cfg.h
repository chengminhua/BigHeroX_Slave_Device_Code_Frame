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
**  FILENAME     : Gtm_Drv_Cfg.h                                              **
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


#ifndef GTM_DRV_CFG_H
#define GTM_DRV_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/

#include "Gtm_Drv_Dtm_Cfg.h"
#include "Gtm_Drv_Interrupt_Cfg.h"
#include "Gtm_Drv_Tbu_Cfg.h"
#include "Gtm_Drv_Tim_Cfg.h"
#include "Gtm_Drv_Tom_Cfg.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_DRV_CFG_VENDOR_ID_H                    1541
#define GTM_DRV_CFG_MODULE_ID_H                    221

#define GTM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H     4
#define GTM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H     4
#define GTM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H     0

#define GTM_DRV_CFG_SW_MAJOR_VERSION_H             1
#define GTM_DRV_CFG_SW_MINOR_VERSION_H             1
#define GTM_DRV_CFG_SW_PATCH_VERSION_H             0
#define GTM_INSTANCE_ID                            0

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/* Check if current file and Gtm_Drv_Dtm_Cfg.h header file are of the same vendor */
#if (GTM_DRV_CFG_VENDOR_ID_H != GTM_DRV_DTM_CFG_VENDOR_ID_H)
    #error "Gtm_Drv_Cfg.h and Gtm_Drv_Dtm_Cfg.h have different vendor ids"
#endif
/* Check if current file and Gtm_Drv_Dtm_Cfg.h header file are of the same Autosar version */
#if ((GTM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H   != GTM_DRV_DTM_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H    != GTM_DRV_DTM_CFG_AR_RELEASE_MINOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != GTM_DRV_DTM_CFG_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Dtm_Cfg.h are different"
#endif
/* Check if current file and Gtm_Drv_Dtm_Cfg.h header file are of the same Software version */
#if ((GTM_DRV_CFG_SW_MAJOR_VERSION_H != GTM_DRV_DTM_CFG_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_MINOR_VERSION_H != GTM_DRV_DTM_CFG_SW_MINOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_PATCH_VERSION_H != GTM_DRV_DTM_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Dtm_Cfg.h are different"
#endif


/* Check if current file and Gtm_Drv_Interrupt_Cfg.h header file are of the same vendor */
#if (GTM_DRV_CFG_VENDOR_ID_H != GTM_DRV_INTERRUPT_CFG_VENDOR_ID_H)
    #error "Gtm_Drv_Cfg.h and Gtm_Drv_Interrupt_Cfg.h have different vendor ids"
#endif
/* Check if current file and Gtm_Drv_Interrupt_Cfg.h header file are of the same Autosar version */
#if ((GTM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H   != GTM_DRV_INTERRUPT_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H    != GTM_DRV_INTERRUPT_CFG_AR_RELEASE_MINOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != GTM_DRV_INTERRUPT_CFG_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Interrupt_Cfg.h are different"
#endif
/* Check if current file and Gtm_Drv_Interrupt_Cfg.h header file are of the same Software version */
#if ((GTM_DRV_CFG_SW_MAJOR_VERSION_H != GTM_DRV_INTERRUPT_CFG_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_MINOR_VERSION_H != GTM_DRV_INTERRUPT_CFG_SW_MINOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_PATCH_VERSION_H != GTM_DRV_INTERRUPT_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Interrupt_Cfg.h are different"
#endif

/* Check if current file and Gtm_Drv_Tbu_Cfg.h header file are of the same vendor */
#if (GTM_DRV_CFG_VENDOR_ID_H != GTM_DRV_TBU_CFG_VENDOR_ID_H)
    #error "Gtm_Drv_Cfg.h and Gtm_Drv_Tbu_Cfg.h have different vendor ids"
#endif
/* Check if current file and Gtm_Drv_Tbu_Cfg.h header file are of the same Autosar version */
#if ((GTM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H   != GTM_DRV_TBU_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H    != GTM_DRV_TBU_CFG_AR_RELEASE_MINOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != GTM_DRV_TBU_CFG_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Tbu_Cfg.h are different"
#endif
/* Check if current file and Gtm_Drv_Tbu_Cfg.h header file are of the same Software version */
#if ((GTM_DRV_CFG_SW_MAJOR_VERSION_H != GTM_DRV_TBU_CFG_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_MINOR_VERSION_H != GTM_DRV_TBU_CFG_SW_MINOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_PATCH_VERSION_H != GTM_DRV_TBU_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Tbu_Cfg.h are different"
#endif



/* Check if current file and Gtm_Drv_Tim_Cfg.h header file are of the same vendor */
#if (GTM_DRV_CFG_VENDOR_ID_H != GTM_DRV_TIM_CFG_VENDOR_ID_H)
    #error "Gtm_Drv_Cfg.h and Gtm_Drv_Tim_Cfg.h have different vendor ids"
#endif
/* Check if current file and Gtm_Drv_Tim_Cfg.h header file are of the same Autosar version */
#if ((GTM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H   != GTM_DRV_TIM_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H    != GTM_DRV_TIM_CFG_AR_RELEASE_MINOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != GTM_DRV_TIM_CFG_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Tim_Cfg.h are different"
#endif
/* Check if current file and Gtm_Drv_Tim_Cfg.h header file are of the same Software version */
#if ((GTM_DRV_CFG_SW_MAJOR_VERSION_H != GTM_DRV_TIM_CFG_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_MINOR_VERSION_H != GTM_DRV_TIM_CFG_SW_MINOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_PATCH_VERSION_H != GTM_DRV_TIM_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Tim_Cfg.h are different"
#endif



/* Check if current file and Gtm_Drv_Tom_Cfg.h header file are of the same vendor */
#if (GTM_DRV_CFG_VENDOR_ID_H != GTM_DRV_TOM_CFG_VENDOR_ID_H)
    #error "Gtm_Drv_Cfg.h and Gtm_Drv_Tom_Cfg.h have different vendor ids"
#endif
/* Check if current file and Gtm_Drv_Tom_Cfg.h header file are of the same Autosar version */
#if ((GTM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H   != GTM_DRV_TOM_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H    != GTM_DRV_TOM_CFG_AR_RELEASE_MINOR_VERSION_H) || \
    (GTM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != GTM_DRV_TOM_CFG_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Tom_Cfg.h are different"
#endif
/* Check if current file and Gtm_Drv_Tom_Cfg.h header file are of the same Software version */
#if ((GTM_DRV_CFG_SW_MAJOR_VERSION_H != GTM_DRV_TOM_CFG_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_MINOR_VERSION_H != GTM_DRV_TOM_CFG_SW_MINOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_PATCH_VERSION_H != GTM_DRV_TOM_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Gtm_Drv_Cfg.h and Gtm_Drv_Tom_Cfg.h are different"
#endif



/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

#define GTM_DEV_ERROR_DETECT                  (STD_OFF)

#define GTM_CONNECTION                        (FALSE)

#define GTM_PRECOMPILE_SUPPORT  

#define GTM_VERSION_INFO_API                  (STD_OFF)

#define TT_GTM_USED_TBU                       (FALSE)

#define GTM_SLEEP_DISABLE                     (0U)
#define GTM_SLEEP_ENABLE                      (1U)

#define OBSERVE_ONCE                          (0U)
#define ABORT_ONCE                            (1U)
#define RETRY                                 (2U)
#define ABORT                                 (3U)

#define GTM_AEI_INTERRUPT_LEVEL_MODE          (0U)
#define GTM_AEI_INTERRUPT_PULSE_MODE          (1U)
#define GTM_AEI_INTERRUPT_PULSE_NOTIFY_MODE   (2U)
#define GTM_AEI_INTERRUPT_SINGLE_PULSE_MODE   (3U)

#define GTM_CLUSTER0_ARU_DISABLE              (FALSE)
#define GTM_CLUSTER1_ARU_DISABLE              (FALSE)
#define GTM_CLUSTER2_ARU_DISABLE              (FALSE)
#define GTM_CLUSTER3_ARU_DISABLE              (FALSE)

#define GTM_CLUSTER_COUNT (4U)

#if (GTM_CLUSTER0_ARU_DISABLE == TRUE) || \
    (GTM_CLUSTER1_ARU_DISABLE == TRUE) || \
    (GTM_CLUSTER2_ARU_DISABLE == TRUE) || \
    (GTM_CLUSTER3_ARU_DISABLE == TRUE)

#define TT_GTM_USED_ARU TRUE
#else
#define TT_GTM_USED_ARU FALSE
#endif

#define GTM_INTERRUPT_MODE                          GTM_AEI_INTERRUPT_LEVEL_MODE
#define GTM_EN_RST_AND_FORCE_INT_FUNCTIONAL         (TRUE)

#define GTM_AEIM_UNSUPPORTED_ADDRESS_INT_EN         (FALSE)
#define GTM_AEIM_ILLEGAL_MODULEADD_INT_EN           (FALSE)
#define GTM_AEIM_UNSUPPORTED_BYTE_EN_INT_EN         (FALSE)
#define GTM_CLK_ENABLE_ERR_INT_EN                   (FALSE)
#define GTM_CLK_PERIOD_ERR_INT_EN                   (FALSE)

#define GTM_AEIM_UNSUPPORTED_ADDRESS_ERR_INT_EN     (FALSE)
#define GTM_AEIM_ILLEGAL_MODULEADD_ERR_INT_EN       (FALSE)
#define GTM_AEIM_UNSUPPORTED_BYTE_EN_EINT_EN        (FALSE)
#define GTM_CLK_ENABLE_ERR_EINT_EN                  (FALSE)
#define GTM_CLK_PERIOD_ERR_EINT_EN                  (FALSE)

#define GTM_AEI_TO_MODE                             OBSERVE_ONCE
#define GTM_AEI_TO_VALUE                            (0U)

#define GTM_AEI_TIMEOUT_EXCEPTIONINT_EN             (FALSE)
#define GTM_AEI_UNSUPPORTED_ADDRESS_INT_EN          (FALSE)
     
#define GTM_AEI_ILLEGAL_MODULE_ADD_INT_EN           (FALSE)
    
#define GTM_AEI_UNSUPPORTED_BYTE_EN_INT_EN          (FALSE)
    
#define GTM_AEI_TIMEOUT_EXCEPTION_ERR_INT_EN        (FALSE)

#define GTM_AEI_UNSUPPORTED_ADDRESS_ERR_INT_EN      (FALSE)

#define GTM_AEI_ILLEGAL_MODULEADD_ERR_INT_EN        (FALSE)

#define GTM_AEI_UNSUPPORTED_BYTE_EN_ERR_INT_EN      (FALSE)

/* AEI Interface config */
#define GTM_AEI_SYNC_BRIDGE_MODE_EN                 (FALSE)
#define GTM_AEI_MASK_WRITE_RESPONSE_EN              (FALSE)
#define GTM_AEI_BYPASS_SYNC_EN                      (FALSE)
#define GTM_MCS_AEIM_ACCESS_CLS0_DIS                (FALSE)
#define GTM_MCS_AEIM_ACCESS_CLS1_DIS                (FALSE)
#define GTM_MCS_AEIM_ACCESS_CLS2_DIS                (FALSE)
#define GTM_MCS_AEIM_ACCESS_CLS3_DIS                (FALSE)

/* cmu module config start */
#define GTM_CLS0_CLK_DIV      (0x1U)
#define GTM_CLS1_CLK_DIV      (0x1U)
#define GTM_CLS2_CLK_DIV      (0x1U)
#define GTM_CLS3_CLK_DIV      (0x1U)

#if (GTM_CLS0_CLK_DIV == 0) && ((TT_GTM_USED_TOM_0 == TRUE) || (TT_GTM_USED_TIM_0 == TRUE))
#error "Cluster0 clock not enable"
#endif

#if (GTM_CLS1_CLK_DIV == 0) && ((TT_GTM_USED_TOM_1 == TRUE) || (TT_GTM_USED_TIM_1 == TRUE))
#error "Cluster1 clock not enable"
#endif

#if (GTM_CLS2_CLK_DIV == 0) && (TT_GTM_USED_TIM_2 == TRUE)
#error "Cluster2 clock not enable"
#endif

#define CMU_GCLK_NUM          (1U)
#define CMU_GCLK_DEN          (1U)

#define CMU_CFGU_EN_CLK0      (TRUE)
#define CMU_CFGU_EN_CLK1      (FALSE)
#define CMU_CFGU_EN_CLK2      (FALSE)
#define CMU_CFGU_EN_CLK3      (FALSE)
#define CMU_CFGU_EN_CLK4      (FALSE)
#define CMU_CFGU_EN_CLK5      (FALSE)
#define CMU_CFGU_EN_CLK6      (FALSE)
#define CMU_CFGU_EN_CLK7      (FALSE)

#if ((CMU_CFGU_EN_CLK0 == FALSE) && (CMU_CFGU_EN_CLK1 == FALSE)  && \
     (CMU_CFGU_EN_CLK2 == FALSE) && (CMU_CFGU_EN_CLK3 == FALSE)  && \
     (CMU_CFGU_EN_CLK4 == FALSE) && (CMU_CFGU_EN_CLK5 == FALSE)  && \
     (CMU_CFGU_EN_CLK6 == FALSE) && (CMU_CFGU_EN_CLK7 == FALSE)) && \
     ((TT_GTM_USED_TIM_0 == TRUE) || (TT_GTM_USED_TIM_1 == TRUE) || (TT_GTM_USED_TIM_2 == TRUE))
#error "Res clock not enable"
#endif

#define CMU_CFGU_CLK_DIV0     (0U)
#define CMU_CFGU_CLK_DIV1     (0U)
#define CMU_CFGU_CLK_DIV2     (0U)
#define CMU_CFGU_CLK_DIV3     (0U)
#define CMU_CFGU_CLK_DIV4     (0U)
#define CMU_CFGU_CLK_DIV5     (0U)
#define CMU_CFGU_CLK_DIV6     (0U)
#define CMU_CFGU_CLK_DIV7     (0U)

#define CMU_CFGU_CLK6_SEL     CMU_CLK_6_DIVIDER
#define CMU_CFGU_CLK7_SEL     CMU_CLK_7_DIVIDER

#define CMU_EGU_EN_ECLK0      (TRUE)
#define CMU_EGU_EN_ECLK1      (FALSE)
#define CMU_EGU_EN_ECLK2      (FALSE)
#define CMU_EGU_ECLK0_NUM     (1U)
#define CMU_EGU_ECLK0_DEN     (1U)
#define CMU_EGU_ECLK1_NUM     (1U)
#define CMU_EGU_ECLK1_DEN     (1U)
#define CMU_EGU_ECLK2_NUM     (1U)
#define CMU_EGU_ECLK2_DEN     (1U)

#define CMU_FXCLK_ENABLE TRUE

#define CMU_FXCLK_SEL      GTM_GLOBAL_CLOCK

#if (CMU_FXCLK_ENABLE == FALSE) && ((TT_GTM_USED_TOM_0 == TRUE) || (TT_GTM_USED_TOM_1 == TRUE))
#error "Fixed clock not enable"
#endif

#define CMU_CLK_EN             ( CMU_ECLK0_ENABLED \
                                     | 0 \
                                     | 0 \
                                     | CMU_FXCLK_ENABLED \
                                     | CMU_CLK0_ENABLED \
                                     | 0 \
                                     | 0 \
                                     | 0 \
                                     | 0 \
                                     | 0 \
                                     | 0 \
                                     | 0 \
                                    )
/* cmu module config end */

/* Gtm timeout config */

#define GTM_TIMEOUT_MECHANISM     (STD_OFF)

/* Gtm clock monitor config */
#define GTM_MONITOR_CLS0_EN       (STD_OFF)
#define GTM_MONITOR_CLS0_DIV      (0x1U)

#define GTM_MONITOR_CLS1_EN       (STD_OFF)
#define GTM_MONITOR_CLS1_DIV      (0x1U)

#define GTM_MONITOR_CLS2_EN       (STD_OFF)
#define GTM_MONITOR_CLS2_DIV      (0x1U)

#define GTM_MONITOR_CLS3_EN       (STD_OFF)
#define GTM_MONITOR_CLS3_DIV      (0x0U)

#define GTM_TIM0CH0_INPUT_SEL     (0x0U)
#define GTM_TIM0CH1_INPUT_SEL     (0x0U)
#define GTM_TIM0CH2_INPUT_SEL     (0x0U)
#define GTM_TIM0CH3_INPUT_SEL     (0x0U)
#define GTM_TIM0CH4_INPUT_SEL     (0x0U)
#define GTM_TIM0CH5_INPUT_SEL     (0x0U)
#define GTM_TIM0CH6_INPUT_SEL     (0x0U)
#define GTM_TIM0CH7_INPUT_SEL     (0x0U)

#define GTM_MONITOR_OSC_DIV       (0U)

/******************************************************************************
*                            Defines Check
*******************************************************************************/
#ifndef GTM_DEV_ERROR_DETECT
    #error "GTM_DEV_ERROR_DETECT not define error"
#endif
#if ((GTM_DEV_ERROR_DETECT != STD_OFF) && (GTM_DEV_ERROR_DETECT != STD_ON))
    #error "GTM_DEV_ERROR_DETECT config error"
#endif
#ifndef GTM_CONNECTION
    #error "GTM_CONNECTION not define error"
#endif
#if ((GTM_CONNECTION != FALSE) && (GTM_CONNECTION != TRUE))
    #error "GTM_CONNECTION config error"
#endif

#ifndef TT_GTM_USED_TBU
    #error "TT_GTM_USED_TBU not define error"
#endif
#if ((TT_GTM_USED_TBU != FALSE) && (TT_GTM_USED_TBU != TRUE))
    #error "TT_GTM_USED_TBU config error"
#endif

#ifndef GTM_CLUSTER_COUNT
    #error "GTM_CLUSTER_COUNT not define error"
#endif
#if (GTM_CLUSTER_COUNT > 0x4)
    #error "GTM_CLUSTER_COUNT config error"
#endif

#ifndef TT_GTM_USED_ARU
    #error "TT_GTM_USED_ARU not define error"
#endif
#if ((TT_GTM_USED_ARU != FALSE) && (TT_GTM_USED_ARU != TRUE))
    #error "TT_GTM_USED_ARU config error"
#endif

#ifndef GTM_INTERRUPT_MODE
    #error "GTM_INTERRUPT_MODE not define error"
#endif
#if (GTM_INTERRUPT_MODE > 0x3)
    #error "GTM_INTERRUPT_MODE config error"
#endif
#ifndef GTM_EN_RST_AND_FORCE_INT_FUNCTIONAL
    #error "GTM_EN_RST_AND_FORCE_INT_FUNCTIONAL not define error"
#endif
#if ((GTM_EN_RST_AND_FORCE_INT_FUNCTIONAL != FALSE) && (GTM_EN_RST_AND_FORCE_INT_FUNCTIONAL != TRUE))
    #error "GTM_EN_RST_AND_FORCE_INT_FUNCTIONAL config error"
#endif
#ifndef GTM_AEIM_UNSUPPORTED_ADDRESS_INT_EN
    #error "GTM_AEIM_UNSUPPORTED_ADDRESS_INT_EN not define error"
#endif
#if ((GTM_AEIM_UNSUPPORTED_ADDRESS_INT_EN != FALSE) && (GTM_AEIM_UNSUPPORTED_ADDRESS_INT_EN != TRUE))
    #error "GTM_AEIM_UNSUPPORTED_ADDRESS_INT_EN config error"
#endif
#ifndef GTM_AEIM_ILLEGAL_MODULEADD_INT_EN
    #error "GTM_AEIM_ILLEGAL_MODULEADD_INT_EN not define error"
#endif
#if ((GTM_AEIM_ILLEGAL_MODULEADD_INT_EN != FALSE) && (GTM_AEIM_ILLEGAL_MODULEADD_INT_EN != TRUE))
    #error "GTM_AEIM_ILLEGAL_MODULEADD_INT_EN config error"
#endif
#ifndef GTM_AEIM_UNSUPPORTED_BYTE_EN_INT_EN
    #error "GTM_AEIM_UNSUPPORTED_BYTE_EN_INT_EN not define error"
#endif
#if ((GTM_AEIM_UNSUPPORTED_BYTE_EN_INT_EN != FALSE) && (GTM_AEIM_UNSUPPORTED_BYTE_EN_INT_EN != TRUE))
    #error "GTM_AEIM_UNSUPPORTED_BYTE_EN_INT_EN config error"
#endif
#ifndef GTM_CLK_ENABLE_ERR_INT_EN
    #error "GTM_CLK_ENABLE_ERR_INT_EN not define error"
#endif
#if ((GTM_CLK_ENABLE_ERR_INT_EN != FALSE) && (GTM_CLK_ENABLE_ERR_INT_EN != TRUE))
    #error "GTM_CLK_ENABLE_ERR_INT_EN config error"
#endif
#ifndef GTM_CLK_PERIOD_ERR_INT_EN
    #error "GTM_CLK_PERIOD_ERR_INT_EN not define error"
#endif
#if ((GTM_CLK_PERIOD_ERR_INT_EN != FALSE) && (GTM_CLK_PERIOD_ERR_INT_EN != TRUE))
    #error "GTM_CLK_PERIOD_ERR_INT_EN config error"
#endif
#ifndef GTM_AEIM_UNSUPPORTED_ADDRESS_ERR_INT_EN
    #error "GTM_AEIM_UNSUPPORTED_ADDRESS_ERR_INT_EN not define error"
#endif
#if ((GTM_AEIM_UNSUPPORTED_ADDRESS_ERR_INT_EN != FALSE) && (GTM_AEIM_UNSUPPORTED_ADDRESS_ERR_INT_EN != TRUE))
    #error "GTM_AEIM_UNSUPPORTED_ADDRESS_ERR_INT_EN config error"
#endif
#ifndef GTM_AEIM_ILLEGAL_MODULEADD_ERR_INT_EN
    #error "GTM_AEIM_ILLEGAL_MODULEADD_ERR_INT_EN not define error"
#endif
#if ((GTM_AEIM_ILLEGAL_MODULEADD_ERR_INT_EN != FALSE) && (GTM_AEIM_ILLEGAL_MODULEADD_ERR_INT_EN != TRUE))
    #error "GTM_AEIM_ILLEGAL_MODULEADD_ERR_INT_EN config error"
#endif
#ifndef GTM_AEIM_UNSUPPORTED_BYTE_EN_EINT_EN
    #error "GTM_AEIM_UNSUPPORTED_BYTE_EN_EINT_EN not define error"
#endif
#if ((GTM_AEIM_UNSUPPORTED_BYTE_EN_EINT_EN != FALSE) && (GTM_AEIM_UNSUPPORTED_BYTE_EN_EINT_EN != TRUE))
    #error "GTM_AEIM_UNSUPPORTED_BYTE_EN_EINT_EN config error"
#endif
#ifndef GTM_CLK_ENABLE_ERR_EINT_EN
    #error "GTM_CLK_ENABLE_ERR_EINT_EN not define error"
#endif
#if ((GTM_CLK_ENABLE_ERR_EINT_EN != FALSE) && (GTM_CLK_ENABLE_ERR_EINT_EN != TRUE))
    #error "GTM_CLK_ENABLE_ERR_EINT_EN config error"
#endif
#ifndef GTM_CLK_PERIOD_ERR_EINT_EN
    #error "GTM_CLK_PERIOD_ERR_EINT_EN not define error"
#endif
#if ((GTM_CLK_PERIOD_ERR_EINT_EN != FALSE) && (GTM_CLK_PERIOD_ERR_EINT_EN != TRUE))
    #error "GTM_CLK_PERIOD_ERR_EINT_EN config error"
#endif

#ifndef GTM_AEI_TO_MODE
    #error "GTM_AEI_TO_MODE not define error"
#endif
#if (GTM_AEI_TO_MODE > 0x3)
    #error "GTM_AEI_TO_MODE config error"
#endif
#ifndef GTM_AEI_TO_VALUE
    #error "GTM_AEI_TO_VALUE not define error"
#endif
#if (GTM_AEI_TO_VALUE > 0xFF)
    #error "GTM_AEI_TO_VALUE config error"
#endif

#ifndef GTM_AEI_TIMEOUT_EXCEPTIONINT_EN
    #error "GTM_AEI_TIMEOUT_EXCEPTIONINT_EN not define error"
#endif
#if ((GTM_AEI_TIMEOUT_EXCEPTIONINT_EN != FALSE) && (GTM_AEI_TIMEOUT_EXCEPTIONINT_EN != TRUE))
    #error "GTM_AEI_TIMEOUT_EXCEPTIONINT_EN config error"
#endif
#ifndef GTM_AEI_UNSUPPORTED_ADDRESS_INT_EN
    #error "GTM_AEI_UNSUPPORTED_ADDRESS_INT_EN not define error"
#endif
#if ((GTM_AEI_UNSUPPORTED_ADDRESS_INT_EN != FALSE) && (GTM_AEI_UNSUPPORTED_ADDRESS_INT_EN != TRUE))
    #error "GTM_AEI_UNSUPPORTED_ADDRESS_INT_EN config error"
#endif
#ifndef GTM_AEI_ILLEGAL_MODULE_ADD_INT_EN
    #error "GTM_AEI_ILLEGAL_MODULE_ADD_INT_EN not define error"
#endif
#if ((GTM_AEI_ILLEGAL_MODULE_ADD_INT_EN != FALSE) && (GTM_AEI_ILLEGAL_MODULE_ADD_INT_EN != TRUE))
    #error "GTM_AEI_ILLEGAL_MODULE_ADD_INT_EN config error"
#endif
#ifndef GTM_AEI_UNSUPPORTED_BYTE_EN_INT_EN
    #error "GTM_AEI_UNSUPPORTED_BYTE_EN_INT_EN not define error"
#endif
#if ((GTM_AEI_UNSUPPORTED_BYTE_EN_INT_EN != FALSE) && (GTM_AEI_UNSUPPORTED_BYTE_EN_INT_EN != TRUE))
    #error "GTM_AEI_UNSUPPORTED_BYTE_EN_INT_EN config error"
#endif
#ifndef GTM_AEI_TIMEOUT_EXCEPTION_ERR_INT_EN
    #error "GTM_AEI_TIMEOUT_EXCEPTION_ERR_INT_EN not define error"
#endif
#if ((GTM_AEI_TIMEOUT_EXCEPTION_ERR_INT_EN != FALSE) && (GTM_AEI_TIMEOUT_EXCEPTION_ERR_INT_EN != TRUE))
    #error "GTM_AEI_TIMEOUT_EXCEPTION_ERR_INT_EN config error"
#endif
#ifndef GTM_AEI_UNSUPPORTED_ADDRESS_ERR_INT_EN
    #error "GTM_AEI_UNSUPPORTED_ADDRESS_ERR_INT_EN not define error"
#endif
#if ((GTM_AEI_UNSUPPORTED_ADDRESS_ERR_INT_EN != FALSE) && (GTM_AEI_UNSUPPORTED_ADDRESS_ERR_INT_EN != TRUE))
    #error "GTM_AEI_UNSUPPORTED_ADDRESS_ERR_INT_EN config error"
#endif
#ifndef GTM_AEI_ILLEGAL_MODULEADD_ERR_INT_EN
    #error "GTM_AEI_ILLEGAL_MODULEADD_ERR_INT_EN not define error"
#endif
#if ((GTM_AEI_ILLEGAL_MODULEADD_ERR_INT_EN != FALSE) && (GTM_AEI_ILLEGAL_MODULEADD_ERR_INT_EN != TRUE))
    #error "GTM_AEI_ILLEGAL_MODULEADD_ERR_INT_EN config error"
#endif
#ifndef GTM_AEI_UNSUPPORTED_BYTE_EN_ERR_INT_EN
    #error "GTM_AEI_UNSUPPORTED_BYTE_EN_ERR_INT_EN not define error"
#endif
#if ((GTM_AEI_UNSUPPORTED_BYTE_EN_ERR_INT_EN != FALSE) && (GTM_AEI_UNSUPPORTED_BYTE_EN_ERR_INT_EN != TRUE))
    #error "GTM_AEI_UNSUPPORTED_BYTE_EN_ERR_INT_EN config error"
#endif

#ifndef GTM_AEI_SYNC_BRIDGE_MODE_EN
    #error "GTM_AEI_SYNC_BRIDGE_MODE_EN not define error"
#endif
#if ((GTM_AEI_SYNC_BRIDGE_MODE_EN != FALSE) && (GTM_AEI_SYNC_BRIDGE_MODE_EN != TRUE))
    #error "GTM_AEI_SYNC_BRIDGE_MODE_EN config error"
#endif
#ifndef GTM_AEI_MASK_WRITE_RESPONSE_EN
    #error "GTM_AEI_MASK_WRITE_RESPONSE_EN not define error"
#endif
#if ((GTM_AEI_MASK_WRITE_RESPONSE_EN != FALSE) && (GTM_AEI_MASK_WRITE_RESPONSE_EN != TRUE))
    #error "GTM_AEI_MASK_WRITE_RESPONSE_EN config error"
#endif
#ifndef GTM_AEI_BYPASS_SYNC_EN
    #error "GTM_AEI_BYPASS_SYNC_EN not define error"
#endif
#if ((GTM_AEI_BYPASS_SYNC_EN != FALSE) && (GTM_AEI_BYPASS_SYNC_EN != TRUE))
    #error "GTM_AEI_BYPASS_SYNC_EN config error"
#endif
#ifndef GTM_MCS_AEIM_ACCESS_CLS0_DIS
    #error "GTM_MCS_AEIM_ACCESS_CLS0_DIS not define error"
#endif
#if ((GTM_MCS_AEIM_ACCESS_CLS0_DIS != FALSE) && (GTM_MCS_AEIM_ACCESS_CLS0_DIS != TRUE))
    #error "GTM_MCS_AEIM_ACCESS_CLS0_DIS config error"
#endif
#ifndef GTM_MCS_AEIM_ACCESS_CLS1_DIS
    #error "GTM_MCS_AEIM_ACCESS_CLS1_DIS not define error"
#endif
#if ((GTM_MCS_AEIM_ACCESS_CLS1_DIS != FALSE) && (GTM_MCS_AEIM_ACCESS_CLS1_DIS != TRUE))
    #error "GTM_MCS_AEIM_ACCESS_CLS1_DIS config error"
#endif
#ifndef GTM_MCS_AEIM_ACCESS_CLS2_DIS
    #error "GTM_MCS_AEIM_ACCESS_CLS2_DIS not define error"
#endif
#if ((GTM_MCS_AEIM_ACCESS_CLS2_DIS != FALSE) && (GTM_MCS_AEIM_ACCESS_CLS2_DIS != TRUE))
    #error "GTM_MCS_AEIM_ACCESS_CLS2_DIS config error"
#endif
#ifndef GTM_MCS_AEIM_ACCESS_CLS3_DIS
    #error "GTM_MCS_AEIM_ACCESS_CLS3_DIS not define error"
#endif
#if ((GTM_MCS_AEIM_ACCESS_CLS3_DIS != FALSE) && (GTM_MCS_AEIM_ACCESS_CLS3_DIS != TRUE))
    #error "GTM_MCS_AEIM_ACCESS_CLS3_DIS config error"
#endif

#ifndef GTM_CLS0_CLK_DIV
    #error "GTM_CLS0_CLK_DIV not define error"
#endif
#if (GTM_CLS0_CLK_DIV > 0x2)
    #error "GTM_CLS0_CLK_DIV config error"
#endif
#ifndef GTM_CLS1_CLK_DIV
    #error "GTM_CLS1_CLK_DIV not define error"
#endif
#if (GTM_CLS1_CLK_DIV > 0x2)
    #error "GTM_CLS1_CLK_DIV config error"
#endif
#ifndef GTM_CLS2_CLK_DIV
    #error "GTM_CLS2_CLK_DIV not define error"
#endif
#if (GTM_CLS2_CLK_DIV > 0x2)
    #error "GTM_CLS2_CLK_DIV config error"
#endif
#ifndef GTM_CLS3_CLK_DIV
    #error "GTM_CLS3_CLK_DIV not define error"
#endif
#if (GTM_CLS3_CLK_DIV > 0x2)
    #error "GTM_CLS3_CLK_DIV config error"
#endif

#ifndef CMU_GCLK_NUM
    #error "CMU_GCLK_NUM not define error"
#endif
#if (CMU_GCLK_NUM > 0xFFFFFF)
    #error "CMU_GCLK_NUM config error"
#endif
#ifndef CMU_GCLK_DEN
    #error "CMU_GCLK_DEN not define error"
#endif
#if (CMU_GCLK_DEN > 0xFFFFFF)
    #error "CMU_GCLK_DEN config error"
#endif

#ifndef CMU_CFGU_EN_CLK0
    #error "CMU_CFGU_EN_CLK0 not define error"
#endif
#if ((CMU_CFGU_EN_CLK0 != FALSE) && (CMU_CFGU_EN_CLK0 != TRUE))
    #error "CMU_CFGU_EN_CLK0 config error"
#endif
#ifndef CMU_CFGU_EN_CLK1
    #error "CMU_CFGU_EN_CLK1 not define error"
#endif
#if ((CMU_CFGU_EN_CLK1 != FALSE) && (CMU_CFGU_EN_CLK1 != TRUE))
    #error "CMU_CFGU_EN_CLK1 config error"
#endif
#ifndef CMU_CFGU_EN_CLK2
    #error "CMU_CFGU_EN_CLK2 not define error"
#endif
#if ((CMU_CFGU_EN_CLK2 != FALSE) && (CMU_CFGU_EN_CLK2 != TRUE))
    #error "CMU_CFGU_EN_CLK2 config error"
#endif
#ifndef CMU_CFGU_EN_CLK3
    #error "CMU_CFGU_EN_CLK3 not define error"
#endif
#if ((CMU_CFGU_EN_CLK3 != FALSE) && (CMU_CFGU_EN_CLK3 != TRUE))
    #error "CMU_CFGU_EN_CLK3 config error"
#endif
#ifndef CMU_CFGU_EN_CLK4
    #error "CMU_CFGU_EN_CLK4 not define error"
#endif
#if ((CMU_CFGU_EN_CLK4 != FALSE) && (CMU_CFGU_EN_CLK4 != TRUE))
    #error "CMU_CFGU_EN_CLK4 config error"
#endif
#ifndef CMU_CFGU_EN_CLK5
    #error "CMU_CFGU_EN_CLK5 not define error"
#endif
#if ((CMU_CFGU_EN_CLK5 != FALSE) && (CMU_CFGU_EN_CLK5 != TRUE))
    #error "CMU_CFGU_EN_CLK5 config error"
#endif
#ifndef CMU_CFGU_EN_CLK6
    #error "CMU_CFGU_EN_CLK6 not define error"
#endif
#if ((CMU_CFGU_EN_CLK6 != FALSE) && (CMU_CFGU_EN_CLK6 != TRUE))
    #error "CMU_CFGU_EN_CLK6 config error"
#endif
#ifndef CMU_CFGU_EN_CLK7
    #error "CMU_CFGU_EN_CLK7 not define error"
#endif
#if ((CMU_CFGU_EN_CLK7 != FALSE) && (CMU_CFGU_EN_CLK7 != TRUE))
    #error "CMU_CFGU_EN_CLK7 config error"
#endif

#ifndef CMU_CFGU_CLK_DIV0
    #error "CMU_CFGU_CLK_DIV0 not define error"
#endif
#if (CMU_CFGU_CLK_DIV0 > 0xFFFFFF)
    #error "CMU_CFGU_CLK_DIV0 config error"
#endif
#ifndef CMU_CFGU_CLK_DIV1
    #error "CMU_CFGU_CLK_DIV1 not define error"
#endif
#if (CMU_CFGU_CLK_DIV1 > 0xFFFFFF)
    #error "CMU_CFGU_CLK_DIV1 config error"
#endif
#ifndef CMU_CFGU_CLK_DIV2
    #error "CMU_CFGU_CLK_DIV2 not define error"
#endif
#if (CMU_CFGU_CLK_DIV2 > 0xFFFFFF)
    #error "CMU_CFGU_CLK_DIV2 config error"
#endif
#ifndef CMU_CFGU_CLK_DIV3
    #error "CMU_CFGU_CLK_DIV3 not define error"
#endif
#if (CMU_CFGU_CLK_DIV3 > 0xFFFFFF)
    #error "CMU_CFGU_CLK_DIV3 config error"
#endif
#ifndef CMU_CFGU_CLK_DIV4
    #error "CMU_CFGU_CLK_DIV4 not define error"
#endif
#if (CMU_CFGU_CLK_DIV4 > 0xFFFFFF)
    #error "CMU_CFGU_CLK_DIV4 config error"
#endif
#ifndef CMU_CFGU_CLK_DIV5
    #error "CMU_CFGU_CLK_DIV5 not define error"
#endif
#if (CMU_CFGU_CLK_DIV5 > 0xFFFFFF)
    #error "CMU_CFGU_CLK_DIV5 config error"
#endif
#ifndef CMU_CFGU_CLK_DIV6
    #error "CMU_CFGU_CLK_DIV6 not define error"
#endif
#if (CMU_CFGU_CLK_DIV6 > 0xFFFFFF)
    #error "CMU_CFGU_CLK_DIV6 config error"
#endif
#ifndef CMU_CFGU_CLK_DIV7
    #error "CMU_CFGU_CLK_DIV7 not define error"
#endif
#if (CMU_CFGU_CLK_DIV7 > 0xFFFFFF)
    #error "CMU_CFGU_CLK_DIV7 config error"
#endif

#ifndef CMU_CFGU_CLK6_SEL
    #error "CMU_CFGU_CLK6_SEL not define error"
#endif
#if (CMU_CFGU_CLK6_SEL > CMU_SUB_INC1C_SIGNAL)
    #error "CMU_CFGU_CLK6_SEL config error"
#endif
#ifndef CMU_CFGU_CLK7_SEL
    #error "CMU_CFGU_CLK7_SEL not define error"
#endif
#if (CMU_CFGU_CLK7_SEL > CMU_SUB_INC2C_SIGNAL)
    #error "CMU_CFGU_CLK7_SEL config error"
#endif

#ifndef CMU_EGU_EN_ECLK0
    #error "CMU_EGU_EN_ECLK0 not define error"
#endif
#if ((CMU_EGU_EN_ECLK0 != FALSE) && (CMU_EGU_EN_ECLK0 != TRUE))
    #error "CMU_EGU_EN_ECLK0 config error"
#endif
#ifndef CMU_EGU_EN_ECLK1
    #error "CMU_EGU_EN_ECLK1 not define error"
#endif
#if ((CMU_EGU_EN_ECLK1 != FALSE) && (CMU_EGU_EN_ECLK1 != TRUE))
    #error "CMU_EGU_EN_ECLK1 config error"
#endif
#ifndef CMU_EGU_EN_ECLK2
    #error "CMU_EGU_EN_ECLK2 not define error"
#endif
#if ((CMU_EGU_EN_ECLK2 != FALSE) && (CMU_EGU_EN_ECLK2 != TRUE))
    #error "CMU_EGU_EN_ECLK2 config error"
#endif
#ifndef CMU_EGU_ECLK0_NUM
    #error "CMU_EGU_ECLK0_NUM not define error"
#endif
#if (CMU_EGU_ECLK0_NUM > 0xFFFFFF)
    #error "CMU_EGU_ECLK0_NUM config error"
#endif
#ifndef CMU_EGU_ECLK0_DEN
    #error "CMU_EGU_ECLK0_DEN not define error"
#endif
#if (CMU_EGU_ECLK0_DEN > 0xFFFFFF)
    #error "CMU_EGU_ECLK0_DEN config error"
#endif
#ifndef CMU_EGU_ECLK1_NUM
    #error "CMU_EGU_ECLK1_NUM not define error"
#endif
#if (CMU_EGU_ECLK1_NUM > 0xFFFFFF)
    #error "CMU_EGU_ECLK1_NUM config error"
#endif
#ifndef CMU_EGU_ECLK1_DEN
    #error "CMU_EGU_ECLK1_DEN not define error"
#endif
#if (CMU_EGU_ECLK1_DEN > 0xFFFFFF)
    #error "CMU_EGU_ECLK1_DEN config error"
#endif
#ifndef CMU_EGU_ECLK2_NUM
    #error "CMU_EGU_ECLK2_NUM not define error"
#endif
#if (CMU_EGU_ECLK2_NUM > 0xFFFFFF)
    #error "CMU_EGU_ECLK2_NUM config error"
#endif
#ifndef CMU_EGU_ECLK2_DEN
    #error "CMU_EGU_ECLK2_DEN not define error"
#endif
#if (CMU_EGU_ECLK2_DEN > 0xFFFFFF)
    #error "CMU_EGU_ECLK2_DEN config error"
#endif

#ifndef CMU_FXCLK_ENABLE
    #error "CMU_FXCLK_ENABLE not define error"
#endif
#if ((CMU_FXCLK_ENABLE != FALSE) && (CMU_FXCLK_ENABLE != TRUE))
    #error "CMU_FXCLK_ENABLE config error"
#endif
#ifndef CMU_FXCLK_SEL
    #error "CMU_FXCLK_SEL not define error"
#endif
#if (CMU_FXCLK_SEL > CMU_CLOCK_7_DIVIDER)
    #error "CMU_FXCLK_SEL config error"
#endif

#ifndef GTM_MONITOR_CLS0_EN
    #error "GTM_MONITOR_CLS0_EN not define error"
#endif
#if ((GTM_MONITOR_CLS0_EN != FALSE) && (GTM_MONITOR_CLS0_EN != TRUE))
    #error "GTM_MONITOR_CLS0_EN config error"
#endif
#ifndef GTM_MONITOR_CLS0_DIV
    #error "GTM_MONITOR_CLS0_DIV not define error"
#endif
#if (GTM_MONITOR_CLS0_DIV > 0x2)
    #error "GTM_MONITOR_CLS0_DIV config error"
#endif
#ifndef GTM_MONITOR_CLS1_EN
    #error "GTM_MONITOR_CLS1_EN not define error"
#endif
#if ((GTM_MONITOR_CLS1_EN != FALSE) && (GTM_MONITOR_CLS1_EN != TRUE))
    #error "GTM_MONITOR_CLS1_EN config error"
#endif
#ifndef GTM_MONITOR_CLS1_DIV
    #error "GTM_MONITOR_CLS1_DIV not define error"
#endif
#if (GTM_MONITOR_CLS1_DIV > 0x2)
    #error "GTM_MONITOR_CLS1_DIV config error"
#endif
#ifndef GTM_MONITOR_CLS2_EN
    #error "GTM_MONITOR_CLS2_EN not define error"
#endif
#if ((GTM_MONITOR_CLS2_EN != FALSE) && (GTM_MONITOR_CLS2_EN != TRUE))
    #error "GTM_MONITOR_CLS2_EN config error"
#endif
#ifndef GTM_MONITOR_CLS2_DIV
    #error "GTM_MONITOR_CLS2_DIV not define error"
#endif
#if (GTM_MONITOR_CLS2_DIV > 0x2)
    #error "GTM_MONITOR_CLS2_DIV config error"
#endif
#ifndef GTM_MONITOR_CLS3_EN
    #error "GTM_MONITOR_CLS3_EN not define error"
#endif
#if ((GTM_MONITOR_CLS3_EN != FALSE) && (GTM_MONITOR_CLS3_EN != TRUE))
    #error "GTM_MONITOR_CLS3_EN config error"
#endif
#ifndef GTM_MONITOR_CLS3_DIV
    #error "GTM_MONITOR_CLS3_DIV not define error"
#endif
#if (GTM_MONITOR_CLS3_DIV > 0x2)
    #error "GTM_MONITOR_CLS3_DIV config error"
#endif

#ifndef GTM_TIM0CH0_INPUT_SEL
    #error "GTM_TIM0CH0_INPUT_SEL not define error"
#endif
#if (GTM_TIM0CH0_INPUT_SEL > 0x4)
    #error "GTM_TIM0CH0_INPUT_SEL config error"
#endif
#ifndef GTM_TIM0CH1_INPUT_SEL
    #error "GTM_TIM0CH1_INPUT_SEL not define error"
#endif
#if (GTM_TIM0CH1_INPUT_SEL > 0x4)
    #error "GTM_TIM0CH1_INPUT_SEL config error"
#endif
#ifndef GTM_TIM0CH2_INPUT_SEL
    #error "GTM_TIM0CH2_INPUT_SEL not define error"
#endif
#if (GTM_TIM0CH2_INPUT_SEL > 0x4)
    #error "GTM_TIM0CH2_INPUT_SEL config error"
#endif
#ifndef GTM_TIM0CH3_INPUT_SEL
    #error "GTM_TIM0CH3_INPUT_SEL not define error"
#endif
#if (GTM_TIM0CH3_INPUT_SEL > 0x4)
    #error "GTM_TIM0CH3_INPUT_SEL config error"
#endif
#ifndef GTM_TIM0CH4_INPUT_SEL
    #error "GTM_TIM0CH4_INPUT_SEL not define error"
#endif
#if (GTM_TIM0CH4_INPUT_SEL > 0x4)
    #error "GTM_TIM0CH4_INPUT_SEL config error"
#endif
#ifndef GTM_TIM0CH5_INPUT_SEL
    #error "GTM_TIM0CH5_INPUT_SEL not define error"
#endif
#if (GTM_TIM0CH5_INPUT_SEL > 0x4)
    #error "GTM_TIM0CH5_INPUT_SEL config error"
#endif
#ifndef GTM_TIM0CH6_INPUT_SEL
    #error "GTM_TIM0CH6_INPUT_SEL not define error"
#endif
#if (GTM_TIM0CH6_INPUT_SEL > 0x4)
    #error "GTM_TIM0CH6_INPUT_SEL config error"
#endif
#ifndef GTM_TIM0CH7_INPUT_SEL
    #error "GTM_TIM0CH7_INPUT_SEL not define error"
#endif
#if (GTM_TIM0CH7_INPUT_SEL > 0x4)
    #error "GTM_TIM0CH7_INPUT_SEL config error"
#endif

#ifndef GTM_MONITOR_OSC_DIV
    #error "GTM_MONITOR_OSC_DIV not define error"
#endif
#if (GTM_MONITOR_OSC_DIV > 0xFF)
    #error "GTM_MONITOR_OSC_DIV config error"
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
/* Tom register information */
extern volatile GTM_TOM_bf_type *Tom_PubReg[2];
/* Tim register information */
extern volatile GTM_TIM_bf_type* Tim_PubReg[3];
/* Tim register information */
extern volatile GTM_CDTM_bf_type *Cdtm_PubReg[4];
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* GTM_CFG_H */

/** @} */


