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
**  FILENAME     : Can_Hw_Cfg.h                                               **
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
#ifndef CAN_HW_CFG_H_
#define CAN_HW_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Hw_PBcfg.h"
#include "A8V2E_CAN.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_CFG_VENDOR_ID_H                           1541
#define FLEXCAN_HW_CFG_MODULE_ID_H                           80
#define FLEXCAN_HW_CFG_AR_RELEASE_MAJOR_VERSION_H            4
#define FLEXCAN_HW_CFG_AR_RELEASE_MINOR_VERSION_H            4
#define FLEXCAN_HW_CFG_AR_RELEASE_PATCH_VERSION_H            0
#define FLEXCAN_HW_CFG_SW_MAJOR_VERSION_H                    1
#define FLEXCAN_HW_CFG_SW_MINOR_VERSION_H                    1
#define FLEXCAN_HW_CFG_SW_PATCH_VERSION_H                    0

#define FLEXCAN_HW_CFG_ALIOTH_VENDOR_ID_H                      A8V2E_CAN_VENDOR_ID_H
#define FLEXCAN_HW_CFG_ALIOTH_AR_RELEASE_MAJOR_VERSION_H       A8V2E_CAN_AR_RELEASE_MAJOR_VERSION_H
#define FLEXCAN_HW_CFG_ALIOTH_AR_RELEASE_MINOR_VERSION_H   A8V2E_CAN_AR_RELEASE_MINOR_VERSION_H
#define FLEXCAN_HW_CFG_ALIOTH_AR_RELEASE_PATCH_VERSION_H       A8V2E_CAN_AR_RELEASE_PATCH_VERSION_H
#define FLEXCAN_HW_CFG_ALIOTH_SW_MAJOR_VERSION_H               A8V2E_CAN_SW_MAJOR_VERSION_H
#define FLEXCAN_HW_CFG_ALIOTH_SW_MINOR_VERSION_H               A8V2E_CAN_SW_MINOR_VERSION_H
#define FLEXCAN_HW_CFG_ALIOTH_SW_PATCH_VERSION_H               A8V2E_CAN_SW_PATCH_VERSION_H

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/* Check if current file and CAN_Hw_PBcfg.h header file are of the same vendor */
#if (FLEXCAN_HW_CFG_VENDOR_ID_H != FLEXCAN_HW_PBCFG_VENDOR_ID_H)
#error "FlexCAN_Hw_Cfg.h and CAN_Hw_PBcfg.h have different vendor ids"
#endif
    #if (FLEXCAN_HW_CFG_MODULE_ID_H != FLEXCAN_HW_PBCFG_MODULE_ID_H)
        #error "FlexCAN_Hw_Cfg.h and CAN_Hw_PBcfg.h have different module ids"
    #endif
/* Check if current file and CAN_Hw_PBcfg.h header file are of the same Autosar version */
#if ((FLEXCAN_HW_CFG_AR_RELEASE_MAJOR_VERSION_H   != FLEXCAN_HW_PBCFG_AR_RELEASE_MAJOR_VERSION_H) || \
(FLEXCAN_HW_CFG_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_HW_PBCFG_AR_RELEASE_MINOR_VERSION_H) || \
(FLEXCAN_HW_CFG_AR_RELEASE_PATCH_VERSION_H != FLEXCAN_HW_PBCFG_AR_RELEASE_PATCH_VERSION_H) \
)
#error "AutoSar Version Numbers of CAN_Hw_Cfg.h and FlexCAN_Hw_PBcfg.h are different"
#endif
/* Check if current file and CAN_Hw_PBcfg.h header file are of the same Software version */
#if ((FLEXCAN_HW_CFG_SW_MAJOR_VERSION_H != FLEXCAN_HW_PBCFG_SW_MAJOR_VERSION_H) || \
(FLEXCAN_HW_CFG_SW_MINOR_VERSION_H != FLEXCAN_HW_PBCFG_SW_MINOR_VERSION_H) || \
(FLEXCAN_HW_CFG_SW_PATCH_VERSION_H != FLEXCAN_HW_PBCFG_SW_PATCH_VERSION_H) \
)
#error "Software Version Numbers of CAN_Hw_Cfg.h and FlexCAN_Hw_PBcfg.h are different"
#endif


/* Check if current file and A8V2E_CAN.h header file are of the same vendor */
#if (FLEXCAN_HW_CFG_VENDOR_ID_H != A8V2E_CAN_VENDOR_ID_H)
#error "FlexCAN_Hw_Cfg.h and A8V2E_CAN.h have different vendor ids"
#endif
/* Check if current file and A8.h header file are of the same Autosar version */
#if ((FLEXCAN_HW_CFG_AR_RELEASE_MAJOR_VERSION_H   != A8V2E_CAN_AR_RELEASE_MAJOR_VERSION_H) || \
(FLEXCAN_HW_CFG_AR_RELEASE_MINOR_VERSION_H    != A8V2E_CAN_AR_RELEASE_MINOR_VERSION_H) || \
(FLEXCAN_HW_CFG_AR_RELEASE_PATCH_VERSION_H != A8V2E_CAN_AR_RELEASE_PATCH_VERSION_H) \
)
#error "AutoSar Version Numbers of FlexCAN_Hw_Cfg.h and A8V2E_CAN.h are different"
#endif
/* Check if current file and A8V2E_CAN.h header file are of the same Software version */
#if ((FLEXCAN_HW_CFG_SW_MAJOR_VERSION_H != A8V2E_CAN_SW_MAJOR_VERSION_H) || \
(FLEXCAN_HW_CFG_SW_MINOR_VERSION_H != A8V2E_CAN_SW_MINOR_VERSION_H) || \
(FLEXCAN_HW_CFG_SW_PATCH_VERSION_H != A8V2E_CAN_SW_PATCH_VERSION_H) \
)
#error "Software Version Numbers of FlexCAN_Hw_Cfg.h and A8V2E_CAN.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* External Structures generated by FlexCAN_Hw_PBCfg */
#define FLEXCAN_HW_CONFIG_EXT \
    FLEXCAN_HW_PB_CFG
/* for HLD, no need to extern states */
#define FLEXCAN_HW_STATE_EXT

/*! @brief Enables / Disables user mode support */
#define FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT                  (STD_OFF)

#define CanTimeoutSupervisionEnabled                         (STD_OFF)

/* @brief Maximum number of Message Buffers supported for payload size 8 for any of the CAN instances */
#define FLEXCAN_HW_FEATURE_MAX_MB_NUM                        (128U)

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN0 */
#define FLEXCAN_HW_FEATURE_INSTANCE_0_MAX_MB_NUM             (128U)

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN1 */
#define FLEXCAN_HW_FEATURE_INSTANCE_1_MAX_MB_NUM             (128U)

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN2 */
#define FLEXCAN_HW_FEATURE_INSTANCE_2_MAX_MB_NUM             (128U)

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN3 */
#define FLEXCAN_HW_FEATURE_INSTANCE_3_MAX_MB_NUM             (128U)

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN4 */
#define FLEXCAN_HW_FEATURE_INSTANCE_4_MAX_MB_NUM             (128U)

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN5 */
#define FLEXCAN_HW_FEATURE_INSTANCE_5_MAX_MB_NUM             (128U)

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN6 */
#define FLEXCAN_HW_FEATURE_INSTANCE_6_MAX_MB_NUM             (128U)

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN7 */
#define FLEXCAN_HW_FEATURE_INSTANCE_7_MAX_MB_NUM             (128U)


/* @brief Array of maximum number of Message Buffers supported for payload size 8 for all the CAN instances */
#define FLEXCAN_HW_FEATURE_MAX_MB_NUM_ARRAY { \
                                                             FLEXCAN_HW_FEATURE_INSTANCE_0_MAX_MB_NUM, \
                                                             FLEXCAN_HW_FEATURE_INSTANCE_1_MAX_MB_NUM, \
                                                             FLEXCAN_HW_FEATURE_INSTANCE_2_MAX_MB_NUM, \
                                                             FLEXCAN_HW_FEATURE_INSTANCE_3_MAX_MB_NUM, \
                                                             FLEXCAN_HW_FEATURE_INSTANCE_4_MAX_MB_NUM, \
                                                             FLEXCAN_HW_FEATURE_INSTANCE_5_MAX_MB_NUM, \
                                                             FLEXCAN_HW_FEATURE_INSTANCE_6_MAX_MB_NUM, \
                                                             FLEXCAN_HW_FEATURE_INSTANCE_7_MAX_MB_NUM \
}

/* @brief Has DMA enable (bit field MCR[DMA]). */
#define FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE                    (STD_OFF)
/* @brief Has Supervisor Mode MCR[SUPV] */
#define FLEXCAN_HW_FEATURE_HAS_SUPV                          (STD_ON)
/* @brief Has Flexible Data Rate */
#define FLEXCAN_HW_FEATURE_HAS_FD                            (STD_ON)
/* @bried FlexCAN has Detection And Correction of Memory Errors */
#define FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET                   (STD_ON)
/* @brief Has FlexCAN Enhanced Rx FIFO mode */
#define FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO              (STD_ON)
/* @brief Has FlexCAN expandable memory */
#define FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY             (STD_ON)
/* @brief Has FlexCAN Timestamp enabled */
#define FLEXCAN_HW_FEATURE_HAS_TS_ENABLE                     (STD_ON)
/* @brief Has FlexCAN Enhanced Rx FIFO has interrupts available */
#define FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO_INTERRUPT    (STD_OFF)
/* @brief Enable use of Enhanced CBT time segments and ENTDC */
#define FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT                   (STD_ON)
/* @brief Has FD Iso Option Mode  */
#define FLEXCAN_HW_FEATURE_SWITCHINGISOMODE                  (STD_ON)
/* @brief Has Protocol exception Mode */
#define FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION                 (STD_ON)
/* @brief Has Edge filter Feature */
#define FLEXCAN_HW_FEATURE_EDGEFILTER                        (STD_ON)
/* @brief Has Pretending Network Feature */
#define FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING          (STD_OFF)



/**
*   @brief      Can Rx/Tx common interrupt support
*/
#define FLEXCAN_HW_MB_INTERRUPT_SUPPORT                      (STD_ON)

/**
*   @brief      Can Bus Off interrupt support
*/
#define FLEXCAN_HW_BUSOFF_INTERRUPT_SUPPORT                  (STD_ON)

/**
*   @brief      Can Error interrupt support
*/
#define FLEXCAN_HW_ERROR_INTERRUPT_SUPPORT                   (STD_ON)

/* Defines the No Of Message Buffers Partions Suppport MBDSR regions */
#define FLEXCAN_HW_FEATURE_MBDSR_COUNT                       (4U)

/* Enable Development Error Detection */
#define FLEXCAN_HW_DEV_ERROR_DETECT                          (STD_OFF)

/******************************************************************************
*                            Defines Checks
******************************************************************************/
#ifndef FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT
    #error "FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT error"
#else
#if((FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT != STD_ON) && (FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT != STD_OFF))
    #error "FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT error"
#endif
#endif

#ifndef CanTimeoutSupervisionEnabled
    #error "CanTimeoutSupervisionEnabled error"
#else
#if((CanTimeoutSupervisionEnabled != STD_ON) && (CanTimeoutSupervisionEnabled != STD_OFF))
    #error "CanTimeoutSupervisionEnabled error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_MAX_MB_NUM error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_INSTANCE_0_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_INSTANCE_0_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_INSTANCE_0_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_INSTANCE_0_MAX_MB_NUM error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_INSTANCE_1_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_INSTANCE_1_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_INSTANCE_1_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_INSTANCE_1_MAX_MB_NUM error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_INSTANCE_2_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_INSTANCE_2_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_INSTANCE_2_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_INSTANCE_2_MAX_MB_NUM error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_INSTANCE_3_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_INSTANCE_3_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_INSTANCE_3_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_INSTANCE_3_MAX_MB_NUM error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_INSTANCE_4_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_INSTANCE_4_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_INSTANCE_4_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_INSTANCE_4_MAX_MB_NUM error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_INSTANCE_5_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_INSTANCE_5_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_INSTANCE_5_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_INSTANCE_5_MAX_MB_NUM error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_INSTANCE_6_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_INSTANCE_6_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_INSTANCE_6_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_INSTANCE_6_MAX_MB_NUM error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_INSTANCE_7_MAX_MB_NUM
    #error "FLEXCAN_HW_FEATURE_INSTANCE_7_MAX_MB_NUM error"
#else
#if(FLEXCAN_HW_FEATURE_INSTANCE_7_MAX_MB_NUM > 128U)
    #error "FLEXCAN_HW_FEATURE_INSTANCE_7_MAX_MB_NUM error"
#endif
#endif


#ifndef FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE
    #error "FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_SUPV
    #error "FLEXCAN_HW_FEATURE_HAS_SUPV error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_SUPV != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_SUPV != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_SUPV error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_FD
    #error "FLEXCAN_HW_FEATURE_HAS_FD error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_FD != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_FD != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_FD error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET
    #error "FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO
    #error "FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY
    #error "FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_TS_ENABLE
    #error "FLEXCAN_HW_FEATURE_HAS_TS_ENABLE error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_TS_ENABLE != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_TS_ENABLE != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_TS_ENABLE error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO_INTERRUPT
    #error "FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO_INTERRUPT error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO_INTERRUPT != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO_INTERRUPT != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO_INTERRUPT error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT
    #error "FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_SWITCHINGISOMODE
    #error "FLEXCAN_HW_FEATURE_SWITCHINGISOMODE error"
#else
#if((FLEXCAN_HW_FEATURE_SWITCHINGISOMODE != STD_ON) && (FLEXCAN_HW_FEATURE_SWITCHINGISOMODE != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_SWITCHINGISOMODE error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION
    #error "FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION error"
#else
#if((FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION != STD_ON) && (FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_EDGEFILTER
    #error "FLEXCAN_HW_FEATURE_EDGEFILTER error"
#else
#if((FLEXCAN_HW_FEATURE_EDGEFILTER != STD_ON) && (FLEXCAN_HW_FEATURE_EDGEFILTER != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_EDGEFILTER error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING
    #error "FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING error"
#else
#if((FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING != STD_ON) && (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING != STD_OFF))
    #error "FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING error"
#endif
#endif

#ifndef FLEXCAN_HW_MB_INTERRUPT_SUPPORT
    #error "FLEXCAN_HW_MB_INTERRUPT_SUPPORT error"
#else
#if((FLEXCAN_HW_MB_INTERRUPT_SUPPORT != STD_ON) && (FLEXCAN_HW_MB_INTERRUPT_SUPPORT != STD_OFF))
    #error "FLEXCAN_HW_MB_INTERRUPT_SUPPORT error"
#endif
#endif

#ifndef FLEXCAN_HW_BUSOFF_INTERRUPT_SUPPORT
    #error "FLEXCAN_HW_BUSOFF_INTERRUPT_SUPPORT error"
#else
#if((FLEXCAN_HW_BUSOFF_INTERRUPT_SUPPORT != STD_ON) && (FLEXCAN_HW_BUSOFF_INTERRUPT_SUPPORT != STD_OFF))
    #error "FLEXCAN_HW_BUSOFF_INTERRUPT_SUPPORT error"
#endif
#endif

#ifndef FLEXCAN_HW_ERROR_INTERRUPT_SUPPORT
    #error "FLEXCAN_HW_ERROR_INTERRUPT_SUPPORT error"
#else
#if((FLEXCAN_HW_ERROR_INTERRUPT_SUPPORT != STD_ON) && (FLEXCAN_HW_ERROR_INTERRUPT_SUPPORT != STD_OFF))
    #error "FLEXCAN_HW_ERROR_INTERRUPT_SUPPORT error"
#endif
#endif

#ifndef FLEXCAN_HW_FEATURE_MBDSR_COUNT
    #error "FLEXCAN_HW_FEATURE_MBDSR_COUNT error"
#else
#if(FLEXCAN_HW_FEATURE_MBDSR_COUNT > 4U)
    #error "FLEXCAN_HW_FEATURE_MBDSR_COUNT error"
#endif
#endif

#ifndef FLEXCAN_HW_DEV_ERROR_DETECT
    #error "FLEXCAN_HW_DEV_ERROR_DETECT error"
#else
#if((FLEXCAN_HW_DEV_ERROR_DETECT != STD_ON) && (FLEXCAN_HW_DEV_ERROR_DETECT != STD_OFF))
    #error "FLEXCAN_HW_DEV_ERROR_DETECT error"
#endif
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* Can_HW_CFG_H_ */
