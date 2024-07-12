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
**  FILENAME     : Can_Hw.h                                                   **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Template Driver Source File                                **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef CAN_HW_H_
#define CAN_HW_H_

/**
* @file Can_Hw.h
*
* @brief FlexCAN Hw Driver Header File
* @details FlexCAN Hw Driver Header File contains the APIs and structures exported by FlexCAN Driver
*
* @addtogroup FlexCAN
* @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Cfg.h"
#include "Can_Hw_Wrapper.h"
#include "Can_GeneralTypes.h"
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
#include "Base_Drv.h"
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "TT_Devassert.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_VENDOR_ID_H                      1541
#define FLEXCAN_HW_MODULE_ID_H                      80
#define FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H       4
#define FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H       0
#define FLEXCAN_HW_SW_MAJOR_VERSION_H               1
#define FLEXCAN_HW_SW_MINOR_VERSION_H               1
#define FLEXCAN_HW_SW_PATCH_VERSION_H               0
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and Can_GeneralTypes header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_H != CAN_GENERALTYPES_VENDOR_ID_H)
    #error "Can_Hw.h and Can_GeneralTypes.h have different vendor ids"
#endif
#if (FLEXCAN_HW_MODULE_ID_H != CAN_GENERALTYPES_MODULE_ID_H)
    #error "Can_Hw.h and Can_GeneralTypes.h have different module ids"
#endif
/* Check if current file and Can_GeneralTypes header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H    != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H    != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H != CAN_GENERALTYPES_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.h and Can_GeneralTypes.h are different"
#endif
/* Check if current file and Can_GeneralTypes header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_H != CAN_GENERALTYPES_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_H != CAN_GENERALTYPES_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_H != CAN_GENERALTYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.h and Can_GeneralTypes.h are different"
#endif

/* Check if current file and Can_Cfg header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_H != CAN_CFG_VENDOR_ID_H)
    #error "Can_Hw.h and Can_Cfg.h have different vendor ids"
#endif
#if (FLEXCAN_HW_MODULE_ID_H != CAN_CFG_MODULE_ID_H)
    #error "Can_Hw.h and Can_Cfg.h have different module ids"
#endif
/* Check if current file and Can_Cfg header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H    != CAN_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H    != CAN_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H != CAN_CFG_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.h and Can_Cfg.h are different"
#endif
/* Check if current file and Can_Cfg header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_H != CAN_CFG_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_H != CAN_CFG_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_H != CAN_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.h and Can_Cfg.h are different"
#endif
/* Check if current file and Can_Hw_Wrapper header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_H != FLEXCAN_HW_WRAPPER_VENDOR_ID_H)
    #error "Can_Hw.h and Can_Hw_Wrapper.h have different vendor ids"
#endif
/* Check if current file and Can_Hw_Wrapper header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_HW_WRAPPER_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_HW_WRAPPER_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H != FLEXCAN_HW_WRAPPER_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.h and Can_Hw_Wrapper.h are different"
#endif
/* Check if current file and Can_Hw_Wrapper header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_H != FLEXCAN_HW_WRAPPER_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_H != FLEXCAN_HW_WRAPPER_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_H != FLEXCAN_HW_WRAPPER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.h and Can_Hw_Wrapper.h are different"
#endif

#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
/* Check if current file and Base_Drv header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_H != BASE_DRV_VENDOR_ID_H)
    #error "Can_Hw.h and Base_Drv.h have different vendor ids"
#endif
/* Check if current file and Base_Drv header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H    != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H    != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H != BASE_DRV_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.h and Base_Drv.h are different"
#endif
/* Check if current file and Base_Drv header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_H != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_H != BASE_DRV_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_H != BASE_DRV_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.h and Base_Drv.h are different"
#endif
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* Check if current file and TT_Devassert header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_H != TT_DEVASSERT_VENDOR_ID_H)
    #error "Can_Hw.h and TT_Devassert.h have different vendor ids"
#endif
/* Check if current file and TT_Devassert header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H    != TT_DEVASSERT_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H    != TT_DEVASSERT_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H != TT_DEVASSERT_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.h and TT_Devassert.h are different"
#endif
/* Check if current file and TT_Devassert header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_H != TT_DEVASSERT_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_H != TT_DEVASSERT_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_H != TT_DEVASSERT_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.h and TT_Devassert.h are different"
#endif
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define FLEXCAN_HW_MB_HANDLE_RXFIFO                       (0U)
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
#define FLEXCAN_HW_MB_ENHANCED_RXFIFO                     (255U)
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
#define FLEXCAN_RXIMR_COUNT                               (128U)


/* Calling the external Configuration symbols defined by FlexCAN_Hw_Cfg.h */
FLEXCAN_HW_CONFIG_EXT

#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
FLEXCAN_HW_PN_CONFIG_EXT
#endif

/* @brief Frames available in Rx FIFO flag shift */
#define FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE           (5U)
/* @brief Rx FIFO warning flag shift */
#define FLEXCAN_HW_LEGACY_RXFIFO_WARNING                   (6U)
/* @brief Rx FIFO overflow flag shift */
#define FLEXCAN_HW_LEGACY_RXFIFO_OVERFLOW                  (7U)
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/* @brief Frames available in Enhanced Rx FIFO flag shift */
#define FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE         (28U)
/* @brief Enhanced Rx FIFO Watermark Indication flag shift */
#define FLEXCAN_HW_ENHANCED_RXFIFO_WATERMARK               (29U)
/* @brief Enhanced Rx FIFO Overflow  flag shift */
#define FLEXCAN_HW_ENHANCED_RXFIFO_OVERFLOW                (30U)
/* @brief Enhanced Rx FIFO Underflow flag shift */
#define FLEXCAN_HW_ENHANCED_RXFIFO_UNDERFLOW               (31U)
/*! @brief FlexCAN Enhanced Fifo Embedded RAM address offset */
#define FLEXCAN_HW_FEATURE_ENHANCED_FIFO_RAM_OFFSET        (0x00002000u)
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

/*! @brief FlexCAN Embedded RAM address offset */
#define FLEXCAN_HW_FEATURE_RAM_OFFSET                      (0x00000080u)
#define FLEXCAN_HW_FEATURE_SMB_OFFSET                      (0xAB0U)
#define FLEXCAN_HW_CAN_SMB_SIZE                            (12U)
#define FLEXCAN_HW_FEATURE_SMB_CANFD_OFFSET                (0xF28U)
#define FLEXCAN_HW_SMB_CANFD_SIZE                          (54U)

#if (STD_ON == FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY)
/*! @brief FlexCAN Expandable Embedded RAM address offset */
#define FLEXCAN_HW_FEATURE_EXP_RAM_OFFSET                  (0x00001000u)
#define FLEXCAN_HW_RAM1n_COUNT                             (512U)
#endif /* (STD_ON == FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY) */

#if (STD_ON == FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO)
#define FLEXCAN_HW_FEATURE_EXP_RXFIFO_OFFSET                (0x2000U)
#define FLEXCAN_EXP_HW_RXFIFO_SIZE                          (640U)
#define FLEXCAN_HW_FEATURE_EXP_RXFIFO_FILTER_OFFSET         (0x3000U)
#define FLEXCAN_HW_EXP_RXFIFO_FILTER_SIZE                   (128U)
#endif

#define FLEXCAN_HW_ALL_INT                                  (0x3B0006U)                 /*!< Masks for wakeup, error, bus off*/


#define FLEXCAN_HW_BUS_OFF_INT                              (0x80004U)                  /*!< Masks for busOff, Tx/Rx Warning */
#define FLEXCAN_HW_ERROR_INT                                (0x300002U)                 /*!< Masks for ErrorOvr, ErrorFast, Error */
#define FLEXCAN_HW_TXRXWARN_INT                             (0x30000U) 

#define FLEXCAN_HW_ESR1_FLTCONF_BUS_OFF                     (0x00000020U)

#define FLEXCAN_HW_ID_EXT_Msk                               (0x3FFFFu)
#define FLEXCAN_HW_ID_EXT_Pos                               (0)
#define FLEXCAN_HW_ID_EXT_WIDTH                             (18)

#define FLEXCAN_HW_ID_STD_Msk                               (0x1FFC0000u)
#define FLEXCAN_HW_ID_STD_Pos                               (18)
#define FLEXCAN_HW_ID_STD_WIDTH                             (11)

#define FLEXCAN_HW_ID_PRIO_Msk                              (0xE0000000u)
#define FLEXCAN_HW_ID_PRIO_Pos                              (29)
#define FLEXCAN_HW_ID_PRIO_WIDTH                            (3)
/* CS Bit Fields */
#define FLEXCAN_HW_CS_TIME_STAMP_Msk                        (0xFFFFu)
#define FLEXCAN_HW_CS_TIME_STAMP_Pos                        (0)
#define FLEXCAN_HW_CS_TIME_STAMP_WIDTH                      (16)

#define FLEXCAN_HW_CS_DLC_Msk                               (0xF0000u)
#define FLEXCAN_HW_CS_DLC_Pos                               (16)
#define FLEXCAN_HW_CS_DLC_WIDTH                             (4)

#define FLEXCAN_HW_CS_RTR_Msk                               (0x100000u)
#define FLEXCAN_HW_CS_RTR_Pos                               (20)
#define FLEXCAN_HW_CS_RTR_WIDTH                             (1)

#define FLEXCAN_HW_CS_IDE_Msk                               (0x200000u)
#define FLEXCAN_HW_CS_IDE_Pos                               (21)
#define FLEXCAN_HW_CS_IDE_WIDTH                             (1)

#define FLEXCAN_HW_CS_SRR_Msk                               (0x400000u)
#define FLEXCAN_HW_CS_SRR_Pos                               (22)
#define FLEXCAN_HW_CS_SRR_WIDTH                             (1)

#define FLEXCAN_HW_CS_CODE_Msk                              (0xF000000u)
#define FLEXCAN_HW_CS_CODE_Pos                              (24)
#define FLEXCAN_HW_CS_CODE_WIDTH                            (4)

#define FLEXCAN_HW_CS_IDHIT_Msk                             (0xFF800000u)
#define FLEXCAN_HW_CS_IDHIT_Pos                             (23)
#define FLEXCAN_HW_CS_IDHIT_WIDTH                           (9)

#define FLEXCAN_HW_MB_EDL_Msk                               (0x80000000u)
#define FLEXCAN_HW_MB_BRS_Msk                               (0x40000000u)

#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATAB_RTR_Pos       (31U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format A&B RTR mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATAB_IDE_Pos       (30U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format A&B IDE mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_RTR_Pos        (15U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B RTR-2 mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_IDE_Pos        (14U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B IDE-2 mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATA_EXT_Msk        (0x3FFFFFFFU) /*!< FlexCAN RX FIFO ID filter*/
/*! format A extended mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATA_EXT_Pos        (1U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format A extended shift.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATA_STD_Msk        (0x3FF80000U) /*!< FlexCAN RX FIFO ID filter*/
/*! format A standard mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATA_STD_Pos        (19U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format A standard shift.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_Msk        (0x1FFF8000U) /*!< FlexCAN RX FIFO ID filter*/
/*! format B extended mask1.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_Pos1       (16U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B extended shift 1.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_Pos2       (0U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format B extended shift 2.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_STD_Msk        (0x7FFU)      /*!< FlexCAN RX FIFO ID filter*/
/*! format B standard mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_STD_Pos1       (19U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B standard shift1.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_STD_Pos2       (3U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format B standard shift2.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_Pos    (15U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B extended compare shift.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_Msk        (0x1FE00000U) /*!< FlexCAN RX FIFO ID filter*/
/*! format C mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_Msk        (0x7F8U)      /*!< FlexCAN RX FIFO ID filter*/
/*! format C mask.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos1           (24U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format C shift1.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos2           (16U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format C shift2.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos3           (8U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format C shift3.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos4           (0U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format C shift4.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_Pos    (21U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format C extended compare shift.*/
#define FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_Pos    (3U)          /*!< FlexCAN RX FIFO ID filter*/

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)

#define FLEXCAN_HW_ENHANCED_IDHIT_Msk                       (0x7Fu)
#define FLEXCAN_HW_ENHANCED_IDHIT_Pos                       (0)
#define FLEXCAN_HW_ENHANCED_IDHIT_WIDTH                     (7)

#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_FSCH_Pos      (30U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard & Extended FSCH shift.*/
#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_RTR2_Pos  (27U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard RTR-2 shift.*/
#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_RTR1_Pos  (11U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard RTR-1 shift.*/
#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_RTR_Pos   (29U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Extended RTR shift.*/
#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_Pos2      (16U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard ID-2 shift.*/
#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_Pos1      (0U)              /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard ID-1 shift.*/
#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_Msk       (0x7FFU)          /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard ID mask.*/
#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_Pos       (0U)              /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Extended ID shift.*/
#define FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_Msk       (0x1FFFFFFFU)     /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Mask for enable all enhanced interrupts */
#define FLEXCAN_HW_ENHACED_RX_FIFO_ALL_INTERRUPT_Msk        ( TT_CAN_FLEXCAN_ERFIER_ERFUFWIE_Msk | TT_CAN_FLEXCAN_ERFIER_ERFOVFIE_Msk | \
                                                              TT_CAN_FLEXCAN_ERFIER_ERFWMIIE_Msk | TT_CAN_FLEXCAN_ERFIER_ERFDAIE_Msk )

/*! Mask for disable all enhanced interrupts */
#define FLEXCAN_HW_ENHACED_RX_FIFO_NO_INTERRUPT_Msk         (0U)
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_On) */

/* This are for little endians cores and supporting rev32 asm instuction */
#define FLEXCAN_HW_SWAP_BYTES_IN_WORD_INDEX(index)          (((index) & ~3U) + (3U - ((index) & 3U)))
#define FLEXCAN_HW_SWAP_BYTES_IN_WORD(a, b)                 FLEXCAN_HW_REV_BYTES_32(a, b)
#define FLEXCAN_HW_REV_BYTES_32(a, b)                       ((b) = (((a) & 0xFF000000U) >> 24U) | (((a) & 0xFF0000U) >> 8U) \
                                                             | (((a) & 0xFF00U) << 8U) | (((a) & 0xFFU) << 24U))

/** Number of instances of the FLEXCAN module. */
#define FLEXCAN_INSTANCE_COUNT                              (8u)

/******************************************************************************
*                            Enums
*******************************************************************************/
/*! @brief FlexCAN message buffer CODE for Rx buffers*/
enum
{
    FLEXCAN_RX_INACTIVE  = 0x0, /*!< MB is not active.*/
    FLEXCAN_RX_FULL      = 0x2, /*!< MB is full.*/
    FLEXCAN_RX_EMPTY     = 0x4, /*!< MB is active and empty.*/
    FLEXCAN_RX_OVERRUN   = 0x6, /*!< MB is overwritten into a full buffer.*/
    FLEXCAN_RX_BUSY      = 0x8, /*!< FlexCAN is updating the contents of the MB.*/
                                /*!  The CPU must not access the MB.*/
    FLEXCAN_RX_RANSWER   = 0xA, /*!< A frame was configured to recognize a Remote Request Frame*/
                                /*!  and transmit a Response Frame in return.*/
    FLEXCAN_RX_NOT_USED   = 0xF /*!< Not used*/
};

/*! @brief FlexCAN message buffer CODE FOR Tx buffers*/
enum
{
    FLEXCAN_TX_INACTIVE  = 0x08, /*!< MB is not active.*/
    FLEXCAN_TX_ABORT     = 0x09, /*!< MB is aborted.*/
    FLEXCAN_TX_DATA      = 0x0C, /*!< MB is a TX Data Frame(MB RTR must be 0).*/
    FLEXCAN_TX_REMOTE    = 0x1C, /*!< MB is a TX Remote Request Frame (MB RTR must be 1).*/
    FLEXCAN_TX_TANSWER   = 0x0E, /*!< MB is a TX Response Request Frame from.*/
                                 /*!  an incoming Remote Request Frame.*/
    FLEXCAN_TX_NOT_USED   = 0xF  /*!< Not used*/
};

/*! @brief FlexCAN error interrupt types
 */
typedef enum
{
    FLEXCAN_INT_RX_WARNING = TT_CAN_FLEXCAN_CTRL1_RWRNMSK_Msk,     /*!< RX warning interrupt*/
    FLEXCAN_INT_TX_WARNING = TT_CAN_FLEXCAN_CTRL1_TWRNMSK_Msk,     /*!< TX warning interrupt*/
    FLEXCAN_INT_ERR        = TT_CAN_FLEXCAN_CTRL1_ERRMSK_Msk,      /*!< Error interrupt*/
    FLEXCAN_INT_ERR_FAST,                                    /*!< Error Fast interrupt*/
    FLEXCAN_INT_BUSOFF     = TT_CAN_FLEXCAN_CTRL1_BOFFMSK_Msk,     /*!< Bus off interrupt*/
} flexcan_int_type_t;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/*! @brief FlexCAN Message Buffer code and status for transmit and receive
 */
typedef struct
{
    uint32 code;                        /*!< MB code for TX or RX buffers.*/
                                        /*! Defined by flexcan_mb_code_rx_t and flexcan_mb_code_tx_t */
    Flexcan_Hw_MsgBuffIdType msgIdType; /*!< Type of message ID (standard or extended)*/
    uint32 dataLen;                     /*!< Length of Data in Bytes*/
    boolean fd_enable;
    uint8 fd_padding;
    boolean enable_brs;                   /* Enable bit rate switch*/
} Flexcan_Hw_MsbuffCodeStatusType;

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            FUNCTION PROTOTYPES
*******************************************************************************/

/**
* @brief        Initialize the CAN driver
* @details      Initialize the CAN driver
* @param[in]    Flexcan_Hw_u8Instance - Can Instance
* @param[in]    Flexcan_Hw_pState - Points to the Can hardware status
* @param[in]    Flexcan_Hw_pData - Points to the Can Config data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
#define FlexCAN_Hw_Init(Flexcan_Hw_u8Instance, Flexcan_Hw_pState, Flexcan_Hw_pData) \
                Call_FlexCAN_Hw_Init(Flexcan_Hw_u8Instance, Flexcan_Hw_pState, Flexcan_Hw_pData)

/**
* @brief        Sends a CAN frame using the specified message buffer
* @details      Sends a CAN frame using the specified message buffer
* @param[in]    instance - A FlexCAN instance number
* @param[in]    mb_idx - Index of the message buffer
* @param[in]    tx_info - Data info
* @param[in]    msg_id - ID of the message to transmit
* @param[in]    mb_data - Data Bytes of the FlexCAN message
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_Send(uint8 instance,
                                      uint8 mb_idx,
                                      TT_CONST Flexcan_Hw_DataInfoType * tx_info,
                                      uint32 msg_id,
                                      TT_CONST uint8 * mb_data);

/**
* @brief        Receives a CAN frame using the specified message buffer
* @details      Receives a CAN frame using the specified message buffer
* @param[in]    instance - A FlexCAN instance number
* @param[in]    mb_idx - Index of the message buffer
* @param[out]   data - The FlexCAN receive message buffer data
* @param[in]    isPolling - If the message will be send using pooling(true) or interrupt(false)
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_Receive(uint8 instance,
                                       uint8 mb_idx,
                                       Flexcan_Hw_MsgBuffType * data,
                                       boolean isPolling);

/**
* @brief        Confgure RX FIFO ID filter table elements
* @details      Confgure RX FIFO ID filter table elements
* @param[in]    instance - A FlexCAN instance number
* @param[in]    id_format - id format
* @param[in]    id_filter_table - id filter table
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
#define Can_Hw_ConfigRxFifo(instance, id_format, id_filter_table) \
                Call_Can_Hw_ConfigRxFifo(instance, id_format, id_filter_table)

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
* @brief        Confgure Enhanced RX FIFO ID filter table elements
* @details      Confgure Enhanced RX FIFO ID filter table elements
* @param[in]    instance - A FlexCAN instance number
* @param[in]    id_filter_table - id filter table
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
#define Can_Hw_ConfigEnhancedRxFifo(instance, id_filter_table) \
        Call_Can_Hw_ConfigEnhancedRxFifo(instance, id_filter_table)

#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

/**
* @brief        Receives a CAN frame using the message FIFO
* @details      Receives a CAN frame using the message FIFO
* @param[in]    instance - A FlexCAN instance number
* @param[out]   data - The FlexCAN receive message buffer data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_RxFifo(uint8 instance, Flexcan_Hw_MsgBuffType * data);

/**
* @brief        CAN receive message buffer field configuration
* @details      CAN receive message buffer field configuration
* @param[in]    instance - A FlexCAN instance number
* @param[in]    mb_idx - Index of the message buffer
* @param[in]    rx_info - Data info
* @param[in]    msg_id - ID of the message to transmit
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_ConfigRxMb(uint8 instance,
                                            uint8 mb_idx,
                                            TT_CONST Flexcan_Hw_DataInfoType * rx_info,
                                            uint32 msg_id
                                           );

/**
 *  @brief     Sets the FlexCAN Rx individual mask
 *  @details   This function will set directly the mask value as is provided.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mb_idx   Index of the message buffer
 *  @param[in] mask     Mask value
 *  @note      This function should be called from StopMode or FreezeMode.
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid.
 *
 */
#define Can_Hw_SetRxIndMask(instance, mb_idx, mask) \
        Call_Can_Hw_SetRxIndMask(instance, mb_idx, mask)

/**
 *  @brief     Sets the FlexCAN Rx MB global mask.
 *  @details   This function will set directly the mask value as is provided.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mask     Mask value
 *  @note      This function should be called from StopMode or FreezeMode.
 *  @return      FLEXCAN_STATUS_SUCCESS if successful;<br>
 *               FLEXCAN_STATUS_ERROR if fail to set;<br>
 *               FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define Can_Hw_SetRxMbGlbMask(instance, mask) \
        Call_Can_Hw_SetRxMbGlbMask(instance, mask)

/**
 * @brief Sets the FlexCAN Rx FIFO global mask.
 * This mask is applied to all filters ID regardless the ID Filter format.
 *
 * @param[in]   instance    A FlexCAN instance number
 * @param[in]   mask        Mask Value.
 * @note      This function should be called from StopMode or FreezeMode.
 * @return      FLEXCAN_STATUS_SUCCESS if successful;<br>
 *              FLEXCAN_STATUS_ERROR if fail to set;<br>
 *              FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define Can_Hw_SetRxFifoGlMsk(instance, mask) \
        Call_Can_Hw_SetRxFifoGlMsk(instance, mask)

/**
* @brief        Process received Rx MessageBuffer or RxFifo
* @details      Process received Rx MessageBuffer or RxFifo
* @param[in]    instance - A CAN instance number
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_MainFunctionRead(uint8 instance, uint8 mb_idx);

/**
* @brief        Process transmitted Tx MessageBuffer
* @details      Process transmitted Tx MessageBuffer
* @param[in]    instance - A CAN instance number
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_MainFunctionWrite(uint8 instance, uint8 mb_idx);

/**
 *  @brief     Check a bus-off event.
 *  @details   This function will check bus activity of FlexCAN module and
 *             if a bus off event is detected will suspend the future bus activities by setting
 *             module in stop mode.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful busoff and set on stop;<br>
 *             FLEXCAN_STATUS_ERROR if no busoff event detected;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in the configured timeout value.<br>
 *
 */
#define Can_Hw_MainFuncBusOff(instance) \
                Call_Can_Hw_MainFuncBusOff(instance)

/**
 *  @brief     Enter FlexCAN Module in Freeze Mode.
 *  @details   This function will suspend bus activity of FlexCAN module and
 *             set it to Freeze Mode to allow module configuration.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in the configured timeout value.<br>
 *
 */
#define Can_Hw_EnterFrzMode(instance) \
        Call_Can_Hw_EnterFrzMode(instance)

/**
 *  @brief     Exit FlexCAN Module from Freeze Mode.
 *  @details   This function will allow FlexCAN module to participate to the BUS activity and
 *             restore normal opertaion of the driver.
 *  @param[in] instance A FlexCAN instance number
 *  @note      This function should be called from FreezeMode.
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in the configured timeout value.<br>
 *
 */
#define Can_Hw_ExitFreezeMode(instance) \
        Call_Can_Hw_ExitFreezeMode(instance)

/**
 *  @brief     DeInitilize the FlexCAN instance driver
 *  @details   This function will make future operataions of FlexCAN instance imposibile and will restore
 *             it's state to default value as before initialization.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define Can_Hw_Deinit(instance) \
        Call_Can_Hw_Deinit(instance)

/**
 *  @brief     Get Start Mode Status
 *  @details   Return if the instance is in Start Mode
 *  @param[in] instance A FlexCAN instance number
 *  @return    True instance is in START Mode
 *             False instance is not in START Mode
 *
 */
#define Can_Hw_GetStartMode(instance, result) \
        Call_Can_Hw_GetStartMode(instance, result)

/**
 *  @brief     Set the FlexCAN instance in START mode
 *  @details   Set the FlexCAN instance in START mode, allowing to participate to bus transfers.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define Can_Hw_SetStartMode(instance) \
        Call_Can_Hw_SetStartMode(instance)

/**
 *  @brief     Set the FlexCAN instance in STOP mode
 *  @details   Set the FlexCAN instance in START mode, this will prevent instance to participate to
 *  bus transactions and disable module clocks.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define Can_Hw_SetStopMode(instance) \
        Call_Can_Hw_SetStopMode(instance)

/**
 *  @brief     Enable\Disable listen Only Mode
 *  @details   This function will Enable or Disable listen Only Mode.
 *  @note      This function should be called from StopMode or FreezeMode.
 *  @param[in] u8Instance A FlexCAN instance number
 *  @param[in] listenonlystate     Enable\Disable interrupt selected
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_ERROR if fail to set;<br>
 *
 */
#define Can_Hw_SetLisOnlyMode(instance, listenonlystate) \
        Call_Can_Hw_SetLisOnlyMode(instance, listenonlystate)

/**
* @brief        Returns whether the previous FlexCAN transfer has finished,In case Enhanced Rx Fifo, mb_idx will be 255
* @details      Returns whether the previous FlexCAN transfer has finished,In case Enhanced Rx Fifo, mb_idx will be 255
* @param[in]    instance - A FlexCAN instance number
* @param[in]    mb_idx - The index of the message buffer
* @param[out]   status - Transfer Status
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetTransferStatus(uint8 instance, uint8 mb_idx, Flexcan_Hw_StatusType *status);

/**
* @brief        Reports various error conditions detected in the reception and transmission of a CAN frame and some general status of the device
* @details      Reports various error conditions detected in the reception and transmission of a CAN frame and some general status of the device
* @param[in]    instance - A FlexCAN instance number
* @param[out]   ErrStatus - Error Status
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetErrorStatus(uint8 instance, uint32 *ErrStatus);

/**
* @brief        Reports Transmit error counter for all errors detected in transmitted messages
* @details      Reports Transmit error counter for all errors detected in transmitted messages
* @param[in]    instance - A FlexCAN instance number
* @param[out]   ErrorCounter - Error Counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetControllerTxErrCounter(uint8 instance, uint8 * ErrorCounter);

/**
* @brief        Reports Receive error counter for all errors detected in received messages
* @details      Reports Receive error counter for all errors detected in received messages
* @param[in]    instance - A FlexCAN instance number
* @param[out]   ErrorCounter - Error Counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetControllerRxErrCounter(uint8 instance, uint8 * ErrorCounter);

/**
 *  @brief      Set RX masking type
 *  @details    This function will set RX masking type as RX global mask or RX individual mask
 *  @param[in]  instance: A FlexCAN instance number
 *  @param[in]  type: FlexCAN Rx mask type
 *  @note       This function should be called from StopMode or FreezeMode.
 *  @return     FLEXCAN_STATUS_SUCCESS if successful<br>
 *              FLEXCAN_STATUS_ERROR if controller is not in freeze mode<br>
 *
 */
#define Can_Hw_SetRxMaskType(instance, type) \
        Call_Can_Hw_SetRxMaskType(instance, type)

/**
 *  @brief      Set Rx14Mask filter for message buffer 14.
 *  @details    This function will set directly the mask value as is provided.
 *  @param[in]  instance: A FlexCAN instance number
 *  @param[in]  mask: The value applied for mask
 *  @note       This function should be called from StopMode or FreezeMode.
 *  @return     FLEXCAN_STATUS_SUCCESS if successful<br>
 *              FLEXCAN_STATUS_ERROR if controller is not in freeze mode<br>
 *
 */
#define Can_Hw_SetRxMb14Mask(instance, mask) \
        Call_Can_Hw_SetRxMb14Mask(instance, mask)

/**
 *  @brief      Set Rx15Mask filter for message buffer 15.
 *  @details    This function will set directly the mask value as is provided.
 *  @param[in]  instance: A FlexCAN instance number
 *  @param[in]  mask: The value applied for mask
 *  @note       This function should be called from StopMode or FreezeMode.
 *  @return     FLEXCAN_STATUS_SUCCESS if successful<br>
 *              FLEXCAN_STATUS_ERROR if controller is not in freeze mode<br>
 *
 */
#define Can_Hw_SetRxMb15Mask(instance, mask) \
        Call_Can_Hw_SetRxMb15Mask(instance, mask)

/**
 * @brief Sets the FlexCAN bit rate for standard frames or the arbitration phase of FD frames.
 * @details This function request the FlexCAN module to be in Stop Mode or in Freeze Mode.
 * @param[in]   instance    A FlexCAN instance number
 * @param[in]   bitrate     A pointer to the FlexCAN bit rate settings.
 * @param[in]   enhExt      The time segments used are set in Enhanced Time Seg Registers
 * @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *            FLEXCAN_STATUS_ERROR if fail to set;<br>
 *            FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define Can_Hw_SetBitrate(instance, bitrate, enhExt) \
        Call_Can_Hw_SetBitrate(instance, bitrate, enhExt)

#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)

/**
 * @brief Sets the FlexCAN bit rate for the data phase of FD frames.
 * @details This function request the FlexCAN module to be in Stop Mode or in Freeze Mode.
 * @param[in]   instance    A FlexCAN instance number
 * @param[in]   bitrate     A pointer to the FlexCAN bit rate settings.
 * @param[in]   fd_enable   Enable/Disable Fd Frame Feature Support
 * @param[in]   bitRateSwitch Enable/Disable of FD Data Bitrate Switch support
 * @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *            FLEXCAN_STATUS_ERROR if fail to set;<br>
 *            FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define Can_Hw_SetBitrateFD(instance, bitrate, bitRateSwitch) \
        Call_Can_Hw_SetBitrateFD(instance, bitrate, bitRateSwitch)

/**
 *  @brief     This function will set how many CAN bits the Tx arbitration process start point can
 *             be delayed from the first bit of CRC field on CAN bus.
 *  @details   This function request the FlexCAN module to be in Stop Mode or in Freeze Mode.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] value    Tx Arbitration Start Delay value
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_ERROR if fail to set;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define Can_Hw_SetTxArbDelay(instance, value) \
        Call_Can_Hw_SetTxArbDelay(instance, value)

/**
 * @brief Enables/Disables the Transceiver Delay Compensation feature and sets
 * the Transceiver Delay Compensation Offset (offset value to be added to the
 * measured transceiver's loop delay in order to define the position of the
 * delayed comparison point when bit rate switching is active).
 * @details This function request the FlexCAN module to be in Stop Mode or in Freeze Mode.
 * @param[in]   instance    A FlexCAN instance number
 * @param[in]   enable Enable/Disable Transceiver Delay Compensation
 * @param[in]   offset Transceiver Delay Compensation Offset
 * @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *            FLEXCAN_STATUS_ERROR if fail to set;<br>
 *            FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define Can_Hw_SetTDCOffset(instance, enable, offset) \
        Call_Can_Hw_SetTDCOffset(instance, enable, offset)
#endif /* FLEXCAN_HW_FEATURE_HAS_FD == STD_ON */

/**
* @brief        Get FlexCAN Message Buffer Status Flag for an operation
* @details      Get FlexCAN Message Buffer Status Flag for an operation
* @param[in]    instance - A CAN instance number
* @param[in]    msgBuffIdx - msg Buff Index
* @param[out]   flag - Buff Status Flag
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetBuffStatusFlag(uint8 instance, uint8 msgBuffIdx, boolean * flag);

 /**
 * @brief        Clear FlexCAN Message Buffer Status Flag
 * @details      Clear FlexCAN Message Buffer Status Flag
 * @param[in]    instance - A CAN instance number
 * @param[in]    msgBuffIdx - Index of the message buffer
 * @return       TT_RetType
 * @retval       TT_RET_SUCCESS - success
 *               Other - fail
 */
TT_RetType Can_Hw_ClearBuffStatusFlag(uint8 instance,
                                    uint8 msgBuffIdx);

/**
 * @brief Enable all interrupts configured.
 * @details Enable all interrupts configured.
 * @param[in]   u8Instance    A FlexCAN instance number
 * @return    FLEXCAN_STATUS_SUCCESS if successful<br>
 *            FLEXCAN_STATUS_ERROR if fail to set<br>
 */
#define Can_Hw_EnInterrupts(u8Instance) \
        Call_Can_Hw_EnInterrupts(u8Instance)

/**
 * @brief Disable all interrupts.
 * @details Disable all interrupts.
 * @param[in]   u8Instance    A FlexCAN instance number
 * @return    FLEXCAN_STATUS_SUCCESS if successful<br>
 *            FLEXCAN_STATUS_ERROR if fail to set<br>
 */
#define Can_Hw_DisInterrupts(u8Instance) \
        Call_Can_Hw_DisInterrupts(u8Instance)

/**
 *  @brief     Enable\Disable Error or BusOff Interrupt
 *  @details   This function will set Error or BusOff interrupt, Error Fast is available only
 *             if FD CAN support is active.
 *  @Note      This function should be called from StopMode or FreezeMode.
 *             When an error interrupt is set and error callback function is installed,
 *             The error callback function will be invoked with a respective event occurred and status of ESR1 register:
 *             In the callback, if another event(got from ESR1 register) recognized(Error, Error Fast, Bus Off, Tx/Rx warning)
 *             Then it should be cleared by FlexCAN_Hw_ClearErrorStatus with a respective mask to avoid dupplication.
 *  @param[in] u8Instance A FlexCAN instance number
 *  @param[in] type       Interrupt Type
 *  @param[in] enable     Enable\Disable interrupt selected
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_ERROR if fail to set;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define Can_Hw_SetErrorInt(u8Instance, type, enable) \
        Call_Can_Hw_SetErrorInt(u8Instance, type, enable)

/**
* @brief        This function shuts down the CAN by disabling interrupts and the transmitter/receiver
* @details      This function shuts down the CAN by disabling interrupts and the transmitter/receiver
* @param[in]    u8Instance - A CAN instance number
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_AbortTransfer(uint8 u8Instance,
                                               uint8 mb_idx);


/**
 *  @brief     Get Stop Mode Status
 *  @details   Return if the instance is in Stop Mode
 *  @param[in] instance A FlexCAN instance number
 *  @return    True instance is in STOP Mode
 *             False instance is not in STOP Mode
 *
 */
#define Can_Hw_GetStopMode(instance, result) \
        Call_Can_Hw_GetStopMode(instance, result)

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Logic Check
* @details      Logic Check
* @param[in]    ConfigPtr - Const Ptr to Can Config data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_LogicCheck(Flexcan_Hw_ModesType Mode,uint8 ControllerOffset);
#endif

/*!
 * @brief Receives a CAN frame using the specified message buffer, in a blocking manner.
 *
 * This function receives a CAN frame using a configured message buffer. The function
 * blocks until either a frame was received, or the specified timeout expired.
 *
 *  @param[in] instance  A FlexCAN instance number
 *  @param[in] mb_idx    Index of the message buffer
 *  @param[out] data     The FlexCAN receive message buffer data.
 *  @param[in] isPolling If the message will be send using pooling(true) or interrupt(false).
 *  @param[in] timeout_ms A timeout for the transfer in milliseconds.
 *  @return FLEXCAN_STATUS_SUCCESS if successfull operation;<br>
 *          FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid;<br>
 *          FLEXCAN_STATUS_BUSY if the message buffer is used for other operation.<br>
 *          FLEXCAN_STATUS_TIMEOUT if the timeout is reached.<br>
 */
TT_RetType FlexCAN_Hw_ReceiveBlocking(uint8 instance,
                                                 uint8 mb_idx,
                                                 Flexcan_Hw_MsgBuffType * data,
                                                 boolean isPolling,
                                                 uint32 u32TimeoutMs);


#if (FLEXCAN_HW_FEATURE_HAS_TS_ENABLE == STD_ON)
/*!
 * @brief This function configure the timestamp settings.
 *
 * This function will allow to set the timestamp timer source and config the
 * HR Timer selected capture point for timestamp.
 * @note  Need enable clock counter for the source selected before use HR Time Stamp.
 *
 *  @param[in] instance  A FlexCAN instance number
 *  @param[in] time_stamp A timestamp configuration structure
 *  @return FLEXCAN_STATUS_SUCCESS if successful operation;<br>
 *          FLEXCAN_STATUS_ERROR if fail to set;<br>
 *          FLEXCAN_STATUS_TIMEOUT if the timeout is reached.<br>
 */
#define Can_Hw_CfgTimeStamp(instance) \
        Call_Can_Hw_CfgTimeStamp(instance)
#endif /* FLEXCAN_HW_FEATURE_HAS_TS_ENABLE == STD_ON */

#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/*!
 * @brief Configures Pretended Networking settings.
 * @details This function will enable or disable the Pretended Network feature and configure PN the
 * wakeup events and filters. This function requires the FlexCAN module to be in Stop Mode or in Freeze Mode.
 * @note In order this feature to work, the FlexCAN module need to be in Start Mode after configuring PN
 * and the Protocol Clock needed to remain active during sleep mode.
 *
 * @param[in] u8Instance The FlexCAN instance number.
 * @param[in] bEnable Enable/Disable Pretended Networking mode.
 * @param[in] pPnConfig Pointer to the Pretended Networking configuration structure.
 * @return FLEXCAN_STATUS_SUCCESS if successful operation;<br>
 *         FLEXCAN_STATUS_ERROR if fail to set;<br>
 *         FLEXCAN_STATUS_TIMEOUT if the timeout is reached.<br>
 */
#define Can_Hw_ConfigPN(u8Instance, bEnable, pPnConfig) \
        Call_Can_Hw_ConfigPN(u8Instance, bEnable, pPnConfig)

/**
* @brief        Extracts one of the frames which triggered the wake up event
* @details      Extracts one of the frames which triggered the wake up event
* @param[in]    u8Instance - A CAN instance number
* @param[in]    u8WmbIndex - The index of the message buffer to be extracted
* @param[out]   pWmb - Pointer to the message buffer structure where the frame will be saved
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetWMB(uint8 u8Instance,
                        uint8 u8WmbIndex,
                        Flexcan_Hw_MsgBuffType * pWmb);

#endif /* FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING */

/**
* @brief        Set Priority
* @details      Set Priority
* @param[in]    u8Instance - A CAN instance number
* @param[in]    TxPrio - Tx Priority
* @param[in]    RxPrio - Rx Priority
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetPriority(uint8 u8Instance, Flexcan_TxPriority TxPrio, Flexcan_RxPriority RxPrio);

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
* @brief        Configure the number of words to transfer for each Enhanced Rx FIFO data element in DMA mode
* @details      Configure the number of words to transfer for each Enhanced Rx FIFO data element in DMA mode
* @param[in]    u8Instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_ConfigRxFifoDMAReqCount(uint8 u8Instance);
#endif

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
#ifdef CanHwUnit_0
void DMA_Can_Callback0(uint32 event);
#endif
#ifdef CanHwUnit_1
void DMA_Can_Callback1(uint32 event);
#endif
#ifdef CanHwUnit_2
void DMA_Can_Callback2(uint32 event);
#endif
#ifdef CanHwUnit_3
void DMA_Can_Callback3(uint32 event);
#endif
#ifdef CanHwUnit_4
void DMA_Can_Callback4(uint32 event);
#endif
#ifdef CanHwUnit_5
void DMA_Can_Callback5(uint32 event);
#endif
#ifdef CanHwUnit_6
void DMA_Can_Callback6(uint32 event);
#endif
#ifdef CanHwUnit_7
void DMA_Can_Callback7(uint32 event);
#endif
#ifdef CanHwUnit_8
void DMA_Can_Callback8(uint32 event);
#endif
#ifdef CanHwUnit_9
void DMA_Can_Callback9(uint32 event);
#endif
#ifdef CanHwUnit_10
void DMA_Can_Callback10(uint32 event);

#endif
#ifdef CanHwUnit_11
void DMA_Can_Callback11(uint32 event);
#endif

#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */

/**
* @brief        Get CAN TXWRN Status Flag
* @details      Get CAN TXWRN Status Flag
* @param[in]    Instance - Can Instance
* @param[out]   TXWRNS_Flag - TX warning Status flag
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_TXWRNStatusFlag(uint8 Instance,boolean *TXWRNS_Flag);

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/*!
 * @brief Sets the FlexCAN RX FIFO global mask.
 *
 * @param[in]   base  The FlexCAN base address
 * @param[in]   Mask     Sets mask
 */
LOCAL_INLINE void FlexCAN_SetRxFifoGlobalMask(TT_CAN_Type * base, uint32 Mask)
{
    (base->FLEXCAN_RXFGMASK) = Mask;
}

/*!
 * @brief Enables/Disables the Transceiver Delay Compensation feature and sets
 * the Transceiver Delay Compensation Offset (offset value to be added to the
 * measured transceiver's loop delay in order to define the position of the
 * delayed comparison point when bit rate switching is active).
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable Transceiver Delay Compensation
 * @param   offset Transceiver Delay Compensation Offset
 */
LOCAL_INLINE void FlexCAN_SetTDCOffset(TT_CAN_Type * base,
                                        boolean enable,
                                        uint8 offset)
{
    uint32 tmp;

    tmp = base->FLEXCAN_FDCTRL;
    tmp &= ~(TT_CAN_FLEXCAN_FDCTRL_TDCEN_Msk | TT_CAN_FLEXCAN_FDCTRL_TDCOFF_Msk);

    if (enable)
    {
        tmp = tmp | TT_CAN_FLEXCAN_FDCTRL_TDCEN_Msk;
        tmp = tmp | TT_VAL2FLD(TT_CAN_FLEXCAN_FDCTRL_TDCOFF, offset);
    }

    base->FLEXCAN_FDCTRL = tmp;
}

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
/*!
 * @brief Enables/Disables the Transceiver Delay Compensation feature and sets
 * the Transceiver Delay Compensation Offset (offset value to be added to the
 * measured transceiver's loop delay in order to define the position of the
 * delayed comparison point when bit rate switching is active).
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable Transceiver Delay Compensation
 * @param   offset Transceiver Delay Compensation Offset
 */
LOCAL_INLINE void FlexCAN_SetEnhancedTDCOffset(TT_CAN_Type * base,
                                                boolean enable,
                                                uint8 offset
                                               )
{
    uint32 tmp;

    tmp = base->FLEXCAN_ETDC;
    tmp &= ~(TT_CAN_FLEXCAN_ETDC_ETDCEN_Msk | TT_CAN_FLEXCAN_ETDC_ETDCOFF_Msk);

    if (enable)
    {
        tmp = tmp | TT_CAN_FLEXCAN_ETDC_ETDCEN_Msk;
        tmp = tmp | TT_VAL2FLD(TT_CAN_FLEXCAN_ETDC_ETDCOFF, offset);
    }

    base->FLEXCAN_ETDC = tmp;
}
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/*!
 * @brief Checks if the FlexCAN is enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
LOCAL_INLINE boolean FlexCAN_IsEnabled(TT_CONST TT_CAN_Type * pBase)
{
    return (((pBase->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_MDIS_Msk) >> TT_CAN_FLEXCAN_MCR_MDIS_Pos) != 0U) ? FALSE : TRUE;
}

#if (FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET == STD_ON)
/*!
 * @brief Disable Error Detection and Correction of Memory Errors.
 *
 * @param   base  The FlexCAN base address
 */
LOCAL_INLINE void FlexCAN_DisableMemErrorDetection(TT_CAN_Type * base)
{
    /* Enable write of MECR register */
    base->FLEXCAN_CTRL2 |=  TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_ECRWRE, 1U);
    /* Enable write of MECR */
    base->FLEXCAN_MECR = TT_VAL2FLD(TT_CAN_FLEXCAN_MECR_ECRWRDIS, 0U);
    /* Disable Error Detection and Correction mechanism,
     * that will set CAN in Freez Mode in case of trigger */
    base->FLEXCAN_MECR = TT_VAL2FLD(TT_CAN_FLEXCAN_MECR_NCEFAFRZ, 0U);
    /* Disable memory error correction */
    base->FLEXCAN_MECR |= TT_VAL2FLD(TT_CAN_FLEXCAN_MECR_ECCDIS, 1U);
    /* Disable write of MECR */
    base->FLEXCAN_CTRL2 &= ~(TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_ECRWRE, 1U));
}
#endif /* FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET */

/*!
 * @brief Enables/Disables Flexible Data rate (if supported).
 *
 * @param   base    The FlexCAN base address
 * @param   enable  TRUE to enable; FALSE to disable
 */
LOCAL_INLINE void FlexCAN_SetFDEnabled(TT_CAN_Type * base,
                                        boolean enableFD,
                                        boolean enableBRS)
{
    base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_FDEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_FDEN, enableFD ? 1UL : 0UL);

    /* Enable BitRate Switch support from BRS_TX_MB field or ignore it */
    base->FLEXCAN_FDCTRL = (base->FLEXCAN_FDCTRL & ~TT_CAN_FLEXCAN_FDCTRL_FDRATE_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_FDCTRL_FDRATE, enableBRS ? 1UL : 0UL);

    /* Disable Transmission Delay Compensation by default */
    base->FLEXCAN_FDCTRL &= ~(TT_CAN_FLEXCAN_FDCTRL_TDCEN_Msk | TT_CAN_FLEXCAN_FDCTRL_TDCOFF_Msk);
}

/*!
 * @brief Enables/Disables Listen Only Mode.
 *
 * @param   base    The FlexCAN base address
 * @param   enable  TRUE to enable; FALSE to disable
 */
LOCAL_INLINE void FlexCAN_SetListenOnlyMode(TT_CAN_Type * base, boolean enableListenOnly)
{
    base->FLEXCAN_CTRL1 = (base->FLEXCAN_CTRL1 & ~TT_CAN_FLEXCAN_CTRL1_LOM_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LOM, enableListenOnly ? 1UL : 0UL);
}

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)

/*!
 * @brief Clears the FIFO
 *
 * @param   base  The FlexCAN base address
 */
LOCAL_INLINE void FlexCAN_ClearFIFO(TT_CAN_Type * base)
{
    base->FLEXCAN_IFLAG1 = TT_CAN_FLEXCAN_IFLAG1_BUF01_Msk;
}

/*!
 * @brief Enables/Disables the DMA support for RxFIFO.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable DMA support
 */
LOCAL_INLINE void FlexCAN_SetRxFifoDMA(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_DMA_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_DMA, enable ? 1UL : 0UL);
}

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/*!
 * @brief Resets Enhanced Rx FIFO engine and state.
 *
 * @param   base  The FlexCAN base address
 */
LOCAL_INLINE void FlexCAN_ClearEnhancedRxFifoEngine(TT_CAN_Type * base)
{
    base->FLEXCAN_ERFSR |= TT_CAN_FLEXCAN_ERFSR_ERFCLR_Msk;
}

/*!
 * @brief Clears the Enhanced Rx FIFO
 *
 * @param   base  The FlexCAN base address
 */
LOCAL_INLINE void FlexCAN_ClearEnhancedFIFO(TT_CAN_Type * base)
{
    base->FLEXCAN_ERFSR = TT_CAN_FLEXCAN_ERFSR_ERFCLR_Msk;
}

/*!
 * @brief Configure the number of words to transfer for each Enhanced Rx FIFO data element in DMA mode.
 *
 * @param   base    The FlexCAN base address
 * @param   numOfWords   The number of words to transfer
 */
LOCAL_INLINE void FlexCAN_ConfigEnhancedRxFifoDMA(TT_CAN_Type * base, uint32 numOfWords)
{   
    base->FLEXCAN_ERFCR = (base->FLEXCAN_ERFCR & (~TT_CAN_FLEXCAN_ERFCR_DMALW_Msk)) | (((numOfWords - 1U) << TT_CAN_FLEXCAN_ERFCR_DMALW_Pos) & TT_CAN_FLEXCAN_ERFCR_DMALW_Msk);
}

#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */

#endif /* if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/*!
 * @brief Unlocks the FlexCAN Rx message buffer.
 *
 * @param   base     The FlexCAN base address
 */
LOCAL_INLINE void FlexCAN_UnlockRxMsgBuff(TT_CONST TT_CAN_Type * base)
{
    /* Unlock the mailbox by reading the free running timer */
    (void)base->FLEXCAN_TIMER;
}

/*!
 * @brief Clears the interrupt flag of the message buffers.
 *
 * @param   base        The FlexCAN base address
 * @param   msgBuffIdx  Index of the message buffer
 */
LOCAL_INLINE void FlexCAN_ClearMsgBuffIntStatusFlag(TT_CAN_Type * base, uint32 msgBuffIdx)
{
    TT_CONST uint32 flag = ((uint32)1U << (msgBuffIdx % 32U));

    /* Clear the corresponding message buffer interrupt flag*/
    if (msgBuffIdx < 32U)
    {
        (base->FLEXCAN_IFLAG1) = (flag);
    }

#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U
    else if (msgBuffIdx < 64U)
    {
        (base->FLEXCAN_IFLAG2) = (flag);
    }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 64U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif
#endif /* if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U */
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U
    else if (msgBuffIdx < 96U)
    {
        (base->FLEXCAN_IFLAG3) = (flag);
    }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 96U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif
#endif /* if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U */
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U
    else
    {
        (base->FLEXCAN_IFLAG4) = (flag);
    }
#endif
}

/*!
 * @brief Get the interrupt flag of the message buffers.
 *
 * @param   base                The FlexCAN base address
 * @param   msgBuffIdx  Index of the message buffer
 * @return  flag        The value of interrupt flag of the message buffer.
 */
LOCAL_INLINE uint8 FlexCAN_GetBuffStatusFlag(TT_CONST TT_CAN_Type * base, uint32 msgBuffIdx)
{
    uint32 flag = 0U;

    if (msgBuffIdx < 32U)
    {
        flag = ((base->FLEXCAN_IFLAG1 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }

#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U
    else if (msgBuffIdx < 64U)
    {
        flag = ((base->FLEXCAN_IFLAG2 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 64U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 64U */
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U */

#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U
    else if (msgBuffIdx < 96U)
    {
        flag = ((base->FLEXCAN_IFLAG3 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 96U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 96U */
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U */

#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U
    else
    {
        flag = ((base->FLEXCAN_IFLAG4 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#endif

    return (uint8)flag;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/*!
 * @brief Get the interrupt Imask of the message buffers.
 *
 * @param   base                The FlexCAN base address
 * @param   msgBuffIdx  Index of the message buffer
 * @return  Imask        The value of interrupt Imask of the message buffer.
 */
LOCAL_INLINE uint8 FlexCAN_GetBuffStatusImask(TT_CONST TT_CAN_Type * base, uint32 msgBuffIdx)
{
    uint32 u32Imask = 0U;

    if (msgBuffIdx < 32U)
    {
        u32Imask = ((base->FLEXCAN_IMASK1 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }

#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U
    else if (msgBuffIdx < 64U)
    {
        u32Imask = ((base->FLEXCAN_IMASK2 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 64U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 64U */
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U */

#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U
    else if (msgBuffIdx < 96U)
    {
        u32Imask = ((base->FLEXCAN_IMASK3 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 96U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 96U */
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U */

#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U
    else
    {
        u32Imask = ((base->FLEXCAN_IMASK4 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#endif

    return (uint8)u32Imask;
}

/*!
 * @brief Sets the FlexCAN time segments for setting up bit rate for FD BRS.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
LOCAL_INLINE void FlexCAN_SetFDTimeSegments(TT_CAN_Type * base, TT_CONST Flexcan_Hw_TimeSegmentType * timeSeg)
{
    /* Set FlexCAN time segments*/
    base->FLEXCAN_FDCBT &= ~(TT_CAN_FLEXCAN_FDCBT_FPROPSEG_Msk | TT_CAN_FLEXCAN_FDCBT_FPSEG2_Msk |  \
                             TT_CAN_FLEXCAN_FDCBT_FPSEG1_Msk | TT_CAN_FLEXCAN_FDCBT_FPRESDIV_Msk |  \
                             TT_CAN_FLEXCAN_FDCBT_FRJW_Msk);
            
    base->FLEXCAN_FDCBT |= (TT_VAL2FLD(TT_CAN_FLEXCAN_FDCBT_FPROPSEG, timeSeg->propSeg)       |  \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_FDCBT_FPSEG2, timeSeg->phaseSeg2)       |  \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_FDCBT_FPSEG1, timeSeg->phaseSeg1)       |  \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_FDCBT_FPRESDIV, timeSeg->preDivider)    |  \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_FDCBT_FRJW, timeSeg->rJumpwidth)) ;   
}

/*!
 * @brief Sets the FlexCAN time segments for setting up bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
LOCAL_INLINE void FlexCAN_SetTimeSegments(TT_CAN_Type * base, TT_CONST Flexcan_Hw_TimeSegmentType * timeSeg)
{
    base->FLEXCAN_CTRL1 &= ~(TT_CAN_FLEXCAN_CTRL1_PROPSEG_Msk | TT_CAN_FLEXCAN_CTRL1_PSEG2_Msk |  \
                            TT_CAN_FLEXCAN_CTRL1_PSEG1_Msk | TT_CAN_FLEXCAN_CTRL1_PRESDIV_Msk  |  \
                            TT_CAN_FLEXCAN_CTRL1_RJW_Msk);
            
    base->FLEXCAN_CTRL1 |= (TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PROPSEG, timeSeg->propSeg)    |   \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PSEG2, timeSeg->phaseSeg2)    |   \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PSEG1, timeSeg->phaseSeg1)    |   \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PRESDIV, timeSeg->preDivider) |   \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_RJW, timeSeg->rJumpwidth));
}

/*!
 * @brief Sets the FlexCAN extended time segments for setting up bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
LOCAL_INLINE void FlexCAN_SetExtendedTimeSegments(TT_CAN_Type * base, TT_CONST Flexcan_Hw_TimeSegmentType * timeSeg)
{
    /* If extended bit time definitions are enabled, use CBT register */
    base->FLEXCAN_CBT &= ~(TT_CAN_FLEXCAN_CBT_EPROPSEG_Msk | TT_CAN_FLEXCAN_CBT_EPSEG2_Msk      |  \
                               TT_CAN_FLEXCAN_CBT_EPSEG1_Msk | TT_CAN_FLEXCAN_CBT_EPRESDIV_Msk  |  \
                               TT_CAN_FLEXCAN_CBT_ERJW_Msk);
                
    base->FLEXCAN_CBT |= (TT_VAL2FLD(TT_CAN_FLEXCAN_CBT_EPROPSEG, timeSeg->propSeg)          |   \
                              TT_VAL2FLD(TT_CAN_FLEXCAN_CBT_EPSEG2, timeSeg->phaseSeg2)      |   \
                              TT_VAL2FLD(TT_CAN_FLEXCAN_CBT_EPSEG1, timeSeg->phaseSeg1)      |   \
                              TT_VAL2FLD(TT_CAN_FLEXCAN_CBT_EPRESDIV, timeSeg->preDivider)   |   \
                              TT_VAL2FLD(TT_CAN_FLEXCAN_CBT_ERJW, timeSeg->rJumpwidth)) ;   
}

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
/*!
 * @brief Sets the FlexCAN Enhanced time segments for setting up nominal bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
LOCAL_INLINE void FlexCAN_SetEnhancedNominalTimeSegments(TT_CAN_Type * base, TT_CONST Flexcan_Hw_TimeSegmentType * timeSeg)
{
    base->FLEXCAN_EPRS |= TT_VAL2FLD(TT_CAN_FLEXCAN_EPRS_ENPRESDIV, timeSeg->preDivider);
                    
    base->FLEXCAN_ENCBT &= ~(TT_CAN_FLEXCAN_ENCBT_NTSEG2_Msk | TT_CAN_FLEXCAN_ENCBT_NTSEG1_Msk | TT_CAN_FLEXCAN_ENCBT_NRJW_Msk);    

    base->FLEXCAN_ENCBT |= (TT_VAL2FLD(TT_CAN_FLEXCAN_ENCBT_NTSEG2, timeSeg->phaseSeg2)  |  \
                           TT_VAL2FLD(TT_CAN_FLEXCAN_ENCBT_NTSEG1, timeSeg->phaseSeg1)   |  \
                           TT_VAL2FLD(TT_CAN_FLEXCAN_ENCBT_NRJW, timeSeg->rJumpwidth));
}

/*!
 * @brief Get the FlexCAN Enhanced time segments for nominal bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
LOCAL_INLINE void FlexCAN_GetEnhancedNominalTimeSegments(TT_CONST TT_CAN_Type * base, Flexcan_Hw_TimeSegmentType * timeSeg)
{
    timeSeg->propSeg = 0;
    timeSeg->preDivider = ((base->FLEXCAN_EPRS & TT_CAN_FLEXCAN_EPRS_ENPRESDIV_Msk) >> TT_CAN_FLEXCAN_EPRS_ENPRESDIV_Pos);
    timeSeg->phaseSeg1 = ((base->FLEXCAN_ENCBT & TT_CAN_FLEXCAN_ENCBT_NTSEG1_Msk) >> TT_CAN_FLEXCAN_ENCBT_NTSEG1_Pos);
    timeSeg->phaseSeg2 = ((base->FLEXCAN_ENCBT & TT_CAN_FLEXCAN_ENCBT_NTSEG2_Msk) >> TT_CAN_FLEXCAN_ENCBT_NTSEG2_Pos);
    timeSeg->rJumpwidth = ((base->FLEXCAN_ENCBT & TT_CAN_FLEXCAN_ENCBT_NRJW_Msk) >> TT_CAN_FLEXCAN_ENCBT_NRJW_Pos);
}

/*!
 * @brief Sets the FlexCAN Enhanced time segments for setting up data bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
LOCAL_INLINE void FlexCAN_SetEnhancedDataTimeSegments(TT_CAN_Type * base, TT_CONST Flexcan_Hw_TimeSegmentType * timeSeg)
{
    base->FLEXCAN_EPRS |= TT_VAL2FLD(TT_CAN_FLEXCAN_EPRS_EDPRESDIV, timeSeg->preDivider);
                    
    base->FLEXCAN_EDCBT &= ~(TT_CAN_FLEXCAN_EDCBT_DTSEG2_Msk | TT_CAN_FLEXCAN_EDCBT_DTSEG1_Msk | TT_CAN_FLEXCAN_EDCBT_DRJW_Msk);    

    base->FLEXCAN_EDCBT |= (TT_VAL2FLD(TT_CAN_FLEXCAN_EDCBT_DTSEG2, timeSeg->phaseSeg2)  |  \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_EDCBT_DTSEG1, timeSeg->phaseSeg1)  |  \
                            TT_VAL2FLD(TT_CAN_FLEXCAN_EDCBT_DRJW, timeSeg->rJumpwidth));
}

LOCAL_INLINE void FlexCAN_GetEnhancedDataTimeSegments(TT_CONST TT_CAN_Type * base, Flexcan_Hw_TimeSegmentType * timeSeg)
{

    timeSeg->propSeg = 0U;
    timeSeg->phaseSeg1 = ((base->FLEXCAN_EDCBT & TT_CAN_FLEXCAN_EDCBT_DTSEG1_Msk) >> TT_CAN_FLEXCAN_EDCBT_DTSEG1_Pos);
    timeSeg->phaseSeg2 = ((base->FLEXCAN_EDCBT & TT_CAN_FLEXCAN_EDCBT_DTSEG2_Msk) >> TT_CAN_FLEXCAN_EDCBT_DTSEG2_Pos);
    timeSeg->rJumpwidth = ((base->FLEXCAN_EDCBT & TT_CAN_FLEXCAN_EDCBT_DRJW_Msk) >> TT_CAN_FLEXCAN_EDCBT_DRJW_Pos);
    timeSeg->preDivider = ((base->FLEXCAN_EPRS & TT_CAN_FLEXCAN_EPRS_EDPRESDIV_Msk) >> TT_CAN_FLEXCAN_EPRS_EDPRESDIV_Pos);
}
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON) */

/*!
 * @brief Gets the FlexCAN extended time segments used for setting up bit rate.
 *
 * @param[in]   base The FlexCAN base address
 * @param[out]   timeSeg    FlexCAN time segments read for bit rate
 */
LOCAL_INLINE void FlexCAN_GetExtendedTimeSegments(TT_CONST TT_CAN_Type * base, Flexcan_Hw_TimeSegmentType * timeSeg)
{
    timeSeg->preDivider = ((base->FLEXCAN_CBT) & TT_CAN_FLEXCAN_CBT_EPRESDIV_Msk) >> TT_CAN_FLEXCAN_CBT_EPRESDIV_Pos;
    timeSeg->propSeg = ((base->FLEXCAN_CBT) & TT_CAN_FLEXCAN_CBT_EPROPSEG_Msk) >> TT_CAN_FLEXCAN_CBT_EPROPSEG_Pos;
    timeSeg->phaseSeg1 = ((base->FLEXCAN_CBT) & TT_CAN_FLEXCAN_CBT_EPSEG1_Msk) >> TT_CAN_FLEXCAN_CBT_EPSEG1_Pos;
    timeSeg->phaseSeg2 = ((base->FLEXCAN_CBT) & TT_CAN_FLEXCAN_CBT_EPSEG2_Msk) >> TT_CAN_FLEXCAN_CBT_EPSEG2_Pos;
    timeSeg->rJumpwidth = ((base->FLEXCAN_CBT) & TT_CAN_FLEXCAN_CBT_ERJW_Msk) >> TT_CAN_FLEXCAN_CBT_ERJW_Pos;
}

/*!
 * @brief Gets the FlexCAN time segments to calculate the bit rate.
 *
 * @param[in]   base The FlexCAN base address
 * @param[out]   timeSeg    FlexCAN time segments read for bit rate
 */
LOCAL_INLINE void FlexCAN_GetTimeSegments(TT_CONST TT_CAN_Type * base, Flexcan_Hw_TimeSegmentType * timeSeg)
{
    timeSeg->preDivider = ((base->FLEXCAN_CTRL1) & TT_CAN_FLEXCAN_CTRL1_PRESDIV_Msk) >> TT_CAN_FLEXCAN_CTRL1_PRESDIV_Pos;
    timeSeg->propSeg = ((base->FLEXCAN_CTRL1) & TT_CAN_FLEXCAN_CTRL1_PROPSEG_Msk) >> TT_CAN_FLEXCAN_CTRL1_PROPSEG_Pos;
    timeSeg->phaseSeg1 = ((base->FLEXCAN_CTRL1) & TT_CAN_FLEXCAN_CTRL1_PSEG1_Msk) >> TT_CAN_FLEXCAN_CTRL1_PSEG1_Pos;
    timeSeg->phaseSeg2 = ((base->FLEXCAN_CTRL1) & TT_CAN_FLEXCAN_CTRL1_PSEG2_Msk) >> TT_CAN_FLEXCAN_CTRL1_PSEG2_Pos;
    timeSeg->rJumpwidth = ((base->FLEXCAN_CTRL1) & TT_CAN_FLEXCAN_CTRL1_RJW_Msk) >> TT_CAN_FLEXCAN_CTRL1_RJW_Pos;
}

/*!
 * @brief Gets the  FlexCAN time segments for FD BRS to calculate the bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments read for bit rate
 */
LOCAL_INLINE void FlexCAN_GetFDTimeSegments(TT_CONST TT_CAN_Type * base, Flexcan_Hw_TimeSegmentType * timeSeg)
{
    timeSeg->preDivider = ((base->FLEXCAN_FDCBT) & TT_CAN_FLEXCAN_FDCBT_FPRESDIV_Msk) >> TT_CAN_FLEXCAN_FDCBT_FPRESDIV_Pos;
    timeSeg->propSeg = ((base->FLEXCAN_FDCBT) & TT_CAN_FLEXCAN_FDCBT_FPROPSEG_Msk) >> TT_CAN_FLEXCAN_FDCBT_FPROPSEG_Pos;
    timeSeg->phaseSeg1 = ((base->FLEXCAN_FDCBT) & TT_CAN_FLEXCAN_FDCBT_FPSEG1_Msk) >> TT_CAN_FLEXCAN_FDCBT_FPSEG1_Pos;
    timeSeg->phaseSeg2 = ((base->FLEXCAN_FDCBT) & TT_CAN_FLEXCAN_FDCBT_FPSEG2_Msk) >> TT_CAN_FLEXCAN_FDCBT_FPSEG2_Pos;
    timeSeg->rJumpwidth = ((base->FLEXCAN_FDCBT) & TT_CAN_FLEXCAN_FDCBT_FRJW_Msk) >> TT_CAN_FLEXCAN_FDCBT_FRJW_Pos;
}

/*!
 * @brief Checks if the Extended Time Segment are enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
LOCAL_INLINE boolean FlexCAN_IsBtfEnabled(TT_CONST TT_CAN_Type * pBase)
{
    return (0U == ((pBase->FLEXCAN_CBT & TT_CAN_FLEXCAN_CBT_BTF_Msk) >> TT_CAN_FLEXCAN_CBT_BTF_Pos)) ? FALSE : TRUE;
}

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
/*!
 * @brief Checks if the Enhanced Time Segment are enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
LOCAL_INLINE boolean FlexCAN_IsBteEnabled(TT_CONST TT_CAN_Type * pBase)
{
    return (0U == ((pBase->FLEXCAN_CTRL2 & TT_CAN_FLEXCAN_CTRL2_BTE_Msk) >> TT_CAN_FLEXCAN_CTRL2_BTE_Pos)) ? FALSE : TRUE;
}

/*!
 * @brief Set the Enhanced Time Segment are enabled or disabled.
 *
 * @param   base    The FlexCAN base address
 * @param   enableCBT Enable/Disable use of Enhanced Time Segments
 */
LOCAL_INLINE void FlexCAN_BteEnable(TT_CAN_Type * base, boolean enableCBT)
{   /* Enable the use of extended bit time definitions */
    base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_BTE_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_BTE, enableCBT ? 1UL : 0UL);
}
#endif
/*!
 * @brief Set the Extended Time Segment are enabled or disabled.
 *
 * @param   base    The FlexCAN base address
 * @param   enableCBT Enable/Disable use of Extent Time Segments
 */
LOCAL_INLINE void FlexCAN_BtfEnable(TT_CAN_Type * base, boolean enableCBT)
{   /* Enable the use of extended bit time definitions */
    base->FLEXCAN_CBT = (base->FLEXCAN_CBT & ~TT_CAN_FLEXCAN_CBT_BTF_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CBT_BTF, enableCBT ? 1UL : 0UL);
}


/*!
 * @brief Enables/Disables the Self Reception feature.
 *
 * If enabled, FlexCAN is allowed to receive frames transmitted by itself.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable Self Reception
 */
LOCAL_INLINE void FlexCAN_SetSelfReception(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_SRXDIS_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_SRXDIS, enable ? 0UL : 1UL);
}

/*!
 * @brief Checks if the Flexible Data rate feature is enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
LOCAL_INLINE boolean FlexCAN_IsFDEnabled(TT_CONST TT_CAN_Type * base)
{
    return ((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_FDEN_Msk) >> TT_CAN_FLEXCAN_MCR_FDEN_Pos) != 0U;
}

/*!
 * @brief Checks if the listen only mode is enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
LOCAL_INLINE boolean FlexCAN_IsListenOnlyModeEnabled(TT_CONST TT_CAN_Type * base)
{
    return (((base->FLEXCAN_CTRL1 & (TT_CAN_FLEXCAN_CTRL1_LOM_Msk)) != 0U) ? TRUE : FALSE);
}

/*!
 * @brief Return last Message Buffer Occupied By RxFIFO
 *
 * @param   x    Number of Configured RxFIFO Filters
 * @return  number of last MB occupied by RxFIFO
 */
LOCAL_INLINE uint32 RxFifoOcuppiedLastMsgBuff(uint32 x)
{
    return 5U + ((((x) + 1U) * 8U) / 4U);
}


/*!
 * @brief Enables/Disables FD frame compatible with ISO-FD Frame ISO 11898-1 (2003)
 *
 * The CAN FD protocol has been improved to increase the failure detection capability that was in the original CAN FD protocol,
 * which is also called non-ISO CAN FD, by CAN in Automation (CiA). A three-bit stuff counter and a parity bit have been introduced
 * in the improved CAN FD protocol, now called ISO CAN FD. The CRC calculation has also been modified. All these improvements
 * make the ISO CAN FD protocol incompatible with the non-FD CAN FD protocol.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable ISO FD Compatible mode.
 */
#if (FLEXCAN_HW_FEATURE_SWITCHINGISOMODE == STD_ON)
LOCAL_INLINE void FlexCAN_SetIsoCan(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_ISOCANFDEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_ISOCANFDEN, enable ? 1UL : 0UL);
}
#endif

LOCAL_INLINE void FlexCAN_SetEntireFrameArbitrationFieldComparison(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_EACEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_EACEN, enable ? 1UL : 0UL);
}
#if (FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION == STD_ON)
LOCAL_INLINE void FlexCAN_SetProtocolException(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_PREXCEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_PREXCEN, enable ? 1UL : 0UL);
}
#endif
LOCAL_INLINE void FlexCAN_SetRemoteReqStore(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_RRS_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_RRS, enable ? 1UL : 0UL);
}
LOCAL_INLINE void FlexCAN_SetBusOffAutorecovery(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_CTRL1 = (base->FLEXCAN_CTRL1 & ~TT_CAN_FLEXCAN_CTRL1_BOFFREC_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_BOFFREC, enable ? 0UL : 1UL);
}
#if (FLEXCAN_HW_FEATURE_EDGEFILTER == STD_ON)
LOCAL_INLINE void FlexCAN_SetEdgeFilter(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_EDFLTDIS_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_EDFLTDIS, enable ? 0UL : 1UL);
}
#endif
LOCAL_INLINE void FlexCAN_CanBitSampling(TT_CAN_Type * base, boolean enable)
{
    base->FLEXCAN_CTRL1 = (base->FLEXCAN_CTRL1 & ~TT_CAN_FLEXCAN_CTRL1_SMP_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_SMP, enable ? 1UL : 0UL);
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/*!
 * @brief Gets the individual FlexCAN MB interrupt flag.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 * @return  the individual Message Buffer interrupt flag (0 and 1 are the flag value)
 */
LOCAL_INLINE uint8 FlexCAN_GetMsgBuffIntStatusFlag(TT_CONST TT_CAN_Type * base, uint32 msgBuffIdx)
{
    /* This need to be protected multithread access*/
    uint8 flag = 0;
    uint32 mask;

    if (msgBuffIdx < 32U)
    {
        mask = base->FLEXCAN_IMASK1 & TT_CAN_FLEXCAN_IMASK1_BUF31TO0M_Msk;
        flag = (uint8)(((base->FLEXCAN_IFLAG1 & mask) >> (msgBuffIdx % 32U)) & 1U);
    }

#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U
    else if (msgBuffIdx < 64U)
    {
        mask = base->FLEXCAN_IMASK2 & TT_CAN_FLEXCAN_IMASK2_BUF63TO32M_Msk;
        flag = (uint8)(((base->FLEXCAN_IFLAG2 & mask) >> (msgBuffIdx % 32U)) & 1U);
    }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 64U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif
#endif /* if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U */
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U
    else if (msgBuffIdx < 96U)
    {
        mask = base->FLEXCAN_IMASK3 & TT_CAN_FLEXCAN_IMASK3_BUF95TO64M_Msk;
        flag = (uint8)(((base->FLEXCAN_IFLAG3 & mask) >> (msgBuffIdx % 32U)) & 1U);
    }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM <= 96U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif
#endif /* if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U */
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U
    else
    {
        mask = base->FLEXCAN_IMASK4 & TT_CAN_FLEXCAN_IMASK4_BUF127TO96M_Msk;
        flag = (uint8)(((base->FLEXCAN_IFLAG4 & mask) >> (msgBuffIdx % 32U)) & 1U);
    }
#endif

    return flag;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/*!
 * @brief Sets the FlexCAN Rx Message Buffer global mask.
 *
 * @param   base  The FlexCAN base address
 * @param   Mask  Mask Value
 */
LOCAL_INLINE void FlexCAN_SetRxMsgBuffGlobalMask(TT_CAN_Type * base, uint32 Mask)
{
    (base->FLEXCAN_RXMGMASK) = Mask;
}

/*!
 * @brief Sets the FlexCAN Rx individual mask for ID filtering in the Rx Message Buffers and the Rx FIFO.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer/filter
 * @param   mask     Individual mask
 */
LOCAL_INLINE void FlexCAN_SetRxIndividualMask(TT_CAN_Type * base,
                                               uint32 msgBuffIdx,
                                               uint32 mask)
{
    base->FLEXCAN_RXIMR[msgBuffIdx] = mask; 
}

/*!
 * @brief Check if controller is in freeze mode or not.
 *
 * @param   base  The FlexCAN base address
 * @return  TRUE if controller is in freeze mode
 *          FALSE if controller is not in freeze mode
 */
LOCAL_INLINE boolean FlexCAN_IsFreezeMode(TT_CONST TT_CAN_Type * base)
{
    return (((base->FLEXCAN_MCR & (TT_CAN_FLEXCAN_MCR_FRZACK_Msk)) != 0U)? TRUE : FALSE);
}

LOCAL_INLINE void FlexCAN_SetTxArbitrationStartDelay(TT_CAN_Type * base, uint8 tasd)
{
    base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_TASD_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_TASD, tasd);
}

/*!
 * @brief Sets the Rx masking type.
 *
 * @param   base  The FlexCAN base address
 * @param   type         The FlexCAN Rx mask type
 */
LOCAL_INLINE void FlexCAN_SetRxMaskType(TT_CAN_Type * base, Flexcan_Hw_RxMaskType type)
{
    /* Set RX masking type (RX global mask or RX individual mask)*/
    if (FLEXCAN_RX_MASK_GLOBAL == type)
    {
        /* Enable Global RX masking */
        base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_IRMQ_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_IRMQ, 0U);
    }
    else
    {
        /* Enable Individual Rx Masking and Queue */
        base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_IRMQ_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_IRMQ, 1U);
    }
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"



#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/*!
 * @brief Checks if Enhanced Rx FIFO is enabled.
 *
 * @param   base     The FlexCAN base address
 * @return  EnhancedRxFifo status (TRUE = enabled / FALSE = disabled)
 */
LOCAL_INLINE boolean FlexCAN_IsEnhancedRxFifoEnabled(TT_CONST TT_CAN_Type * base)
{
    return ((((base->FLEXCAN_ERFCR & TT_CAN_FLEXCAN_ERFCR_ERFEN_Msk) >> TT_CAN_FLEXCAN_ERFCR_ERFEN_Pos) != 0U) ? (TRUE): (FALSE));
}

/*!
 * @brief   Enable/Disable All(Underflow, Overflow, Watermark and frame available) interrupts for Enhanced Rx FIFO
 * @param   base     The FlexCAN base address
 * @param   enable   Enable/Disable interrupts for Enhanced Rx FIFO
 * @return  None
 */
LOCAL_INLINE void FlexCAN_SetEnhancedRxFifoIntAll(TT_CAN_Type * base, boolean enable)
{
    if (TRUE == enable)
    {
        (base->FLEXCAN_ERFIER) = (uint32)(FLEXCAN_HW_ENHACED_RX_FIFO_ALL_INTERRUPT_Msk);
    }
    else
    {
        (base->FLEXCAN_ERFIER) = (uint32)(FLEXCAN_HW_ENHACED_RX_FIFO_NO_INTERRUPT_Msk);
    }
}

/*!
 * @brief Gets the individual FlexCAN Enhanced Rx FIFO flag.
 *
 * @param   base        The FlexCAN base address
 * @param   intFlag     Index of the Enhanced Rx FIFO flag
 * @return  the individual Enhanced Rx FIFO flag (0 and 1 are the flag value)
 */
LOCAL_INLINE uint8 FlexCAN_GetEnhancedRxFIFOStatusFlag(TT_CONST TT_CAN_Type * base, uint32 intFlag)
{
    return (uint8)((base->FLEXCAN_ERFSR & ((uint32)1U << ((uint8)intFlag & (uint8)0x1F))) >> ((uint8)intFlag & (uint8)0x1F));
}

/*!
 * @brief Clears the interrupt flag of the Enhanced Rx FIFO.
 *
 * @param   base  The FlexCAN base address
 * @param   intFlag       Index of the Enhanced Rx FIFO interrupt flag
 */
LOCAL_INLINE void FlexCAN_ClearEnhancedRxFifoIntStatusFlag(TT_CAN_Type * base, uint32 intFlag)
{
    (base->FLEXCAN_ERFSR) = (uint32)1U << intFlag;
}

/*!
 * @brief Gets the individual FlexCAN Enhanced Rx FIFO interrupt flag.
 *
 * @param   base        The FlexCAN base address
 * @param   intFlag     Index of the Enhanced Rx FIFO interrupt flag
 * @return  the individual Enhanced Rx FIFO interrupt flag (0 and 1 are the flag value)
 */
LOCAL_INLINE uint8 FlexCAN_GetEnhancedRxFIFOIntStatusFlag(TT_CONST TT_CAN_Type * base, uint32 intFlag)
{
    return (uint8)((base->FLEXCAN_ERFIER & ((uint32)1U << ((uint8)intFlag & (uint8)0x1F))) >> ((uint8)intFlag & (uint8)0x1F));
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/*!
 * @brief Gets the Wake Up INT Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up by INT Flag Bit
 */
LOCAL_INLINE uint8 FlexCAN_GetWAKINT(TT_CONST TT_CAN_Type * pBase)
{
    return (uint8)((pBase->FLEXCAN_ESR1 & TT_CAN_FLEXCAN_ESR1_WAKINT_Msk) >> TT_CAN_FLEXCAN_ESR1_WAKINT_Pos);
}
/*!
 * @brief Cler the Wake Up INT Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up by INT Flag Bit
 */
LOCAL_INLINE void FlexCAN_ClearWAKINT(TT_CAN_Type * pBase)
{
    pBase->FLEXCAN_ESR1 = TT_CAN_FLEXCAN_ESR1_WAKINT_Msk;
}
/*!
 * @brief Gets the Wake Up INT Enable Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up INT Enable Bit
 */
LOCAL_INLINE uint8 FlexCAN_GetWAKIE(TT_CONST TT_CAN_Type * pBase)
{
    return (uint8)((pBase->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_WAKMSK_Msk) >> TT_CAN_FLEXCAN_MCR_WAKMSK_Pos);
}
/*!
 * @brief Configures Pretended Networking mode filtering selection.
 *
 * @param   pBase  The FlexCAN base address
 * @param   pPnConfig The pretended networking configuration
 *
 */
LOCAL_INLINE void FlexCAN_SetPNFilteringSelection(TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_PnConfigType * pPnConfig)
{
    uint32 tmp;

    tmp = pBase->FLEXCAN_CTRL1_PN;
    tmp &= ~(TT_CAN_FLEXCAN_CTRL1_PN_WTOF_MSK_Msk   |
             TT_CAN_FLEXCAN_CTRL1_PN_WUMF_MSK_Msk   |
             TT_CAN_FLEXCAN_CTRL1_PN_NMATCH_Msk     |
             TT_CAN_FLEXCAN_CTRL1_PN_PLFS_Msk       |
             TT_CAN_FLEXCAN_CTRL1_PN_IDFS_Msk       |
             TT_CAN_FLEXCAN_CTRL1_PN_FCS_Msk);
    /* enable wakeup timeout interrupt */
    tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PN_WTOF_MSK, pPnConfig->bWakeUpTimeout ? 1UL : 0UL);
    /* enable wakeup match interrupt */
    tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PN_WUMF_MSK, pPnConfig->bWakeUpMatch ? 1UL : 0UL);
    tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PN_NMATCH, pPnConfig->u16NumMatches);
    tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PN_FCS, pPnConfig->eFilterComb);
    tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PN_IDFS, pPnConfig->eIdFilterType);
    tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_PN_PLFS, pPnConfig->ePayloadFilterType);
    pBase->FLEXCAN_CTRL1_PN = tmp;  
}

/*!
 * @brief Set PN timeout value.
 *
 * @param   pBase  The FlexCAN base address
 * @param   u16TimeoutValue  timeout for no message matching
 */
LOCAL_INLINE void FlexCAN_SetPNTimeoutValue(TT_CAN_Type * pBase, uint16 u16TimeoutValue)
{
    pBase->FLEXCAN_CTRL2_PN = (pBase->FLEXCAN_CTRL2_PN & ~TT_CAN_FLEXCAN_CTRL2_PN_MATCHTO_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_PN_MATCHTO, u16TimeoutValue);
}

/*!
 * @brief Configures the Pretended Networking ID Filter 1.
 *
 * @param   pBase  The FlexCAN base address
 * @param   idFilter  The ID Filter configuration
 */
LOCAL_INLINE void FlexCAN_SetPNIdFilter1(TT_CAN_Type * pBase, Flexcan_Hw_PnIdFilterType idFilter)
{
    uint32 u32Tmp;

    u32Tmp = pBase->FLEXCAN_FLT_ID1;
    u32Tmp &= ~(TT_CAN_FLEXCAN_FLT_ID1_FLT_IDE_Msk | TT_CAN_FLEXCAN_FLT_ID1_FLT_RTR_Msk | TT_CAN_FLEXCAN_FLT_ID1_FLT_ID1_Msk);
    u32Tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_ID1_FLT_IDE, idFilter.bExtendedId ? 1UL : 0UL);
    u32Tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_ID1_FLT_RTR, idFilter.bRemoteFrame ? 1UL : 0UL);
    if (idFilter.bExtendedId)
    {
        u32Tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_ID1_FLT_ID1, idFilter.u32Id);
    }
    else
    {
        u32Tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_ID1_FLT_ID1, idFilter.u32Id << FLEXCAN_HW_ID_STD_Pos);
    }

    pBase->FLEXCAN_FLT_ID1 = u32Tmp;
}

/*!
 * @brief Configures the Pretended Networking ID Filter 2 Check IDE&RTR.
 *
 * @param   pBase  The FlexCAN base address

 */
LOCAL_INLINE void FlexCAN_SetPNIdFilter2Check(TT_CAN_Type * pBase)
{
    pBase->FLEXCAN_FLT_ID2_IDMASK |= TT_CAN_FLEXCAN_FLT_ID2_IDMASK_IDE_MSK_Msk | TT_CAN_FLEXCAN_FLT_ID2_IDMASK_RTR_MSK_Msk;
}
/*!
 * @brief Configures the Pretended Networking ID Filter 2.
 *
 * @param   pBase  The FlexCAN base address
 * @param   pPnConfig  The pretended networking configuration
 */
LOCAL_INLINE void FlexCAN_SetPNIdFilter2(TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_PnConfigType * pPnConfig)
{
    uint32 u32Tmp;  

    u32Tmp = pBase->FLEXCAN_FLT_ID2_IDMASK;
    u32Tmp &= ~((TT_CAN_FLEXCAN_FLT_ID2_IDMASK_IDE_MSK_Msk) | (TT_CAN_FLEXCAN_FLT_ID2_IDMASK_RTR_MSK_Msk) | (TT_CAN_FLEXCAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK_Msk));
    u32Tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_ID2_IDMASK_IDE_MSK, pPnConfig->idFilter2.bExtendedId ? 1UL : 0UL);
    u32Tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_ID2_IDMASK_RTR_MSK, pPnConfig->idFilter2.bRemoteFrame ? 1UL : 0UL);
    
    /* Check if idFilter1 is extended and apply accordingly mask */
    if (pPnConfig->idFilter1.bExtendedId)
    {
        u32Tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK, pPnConfig->idFilter2.u32Id);
    }
    else
    {
        u32Tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK, pPnConfig->idFilter2.u32Id << FLEXCAN_HW_ID_STD_Pos);
    }

    pBase->FLEXCAN_FLT_ID2_IDMASK = u32Tmp;
}


/*!
 * @brief Set PN DLC Filter.
 *
 * @param   pBase  The FlexCAN base address
 * @param   timeoutValue  timeout for no message matching
 */
LOCAL_INLINE void FlexCAN_SetPNDlcFilter(TT_CAN_Type * pBase, uint8 u8DlcLow, uint8 u8DlcHigh)
{
    uint32 tmp;

    tmp = pBase->FLEXCAN_FLT_DLC;
    tmp &= ~(TT_CAN_FLEXCAN_FLT_DLC_FLT_DLC_LO_Msk | TT_CAN_FLEXCAN_FLT_DLC_FLT_DLC_HI_Msk);
    tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_DLC_FLT_DLC_HI, u8DlcHigh);
    tmp |= TT_VAL2FLD(TT_CAN_FLEXCAN_FLT_DLC_FLT_DLC_LO, u8DlcLow);
    pBase->FLEXCAN_FLT_DLC = tmp;
}

/*!
 * @brief Set PN Payload High Filter 1.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pPayload  message Payload filter
 */
LOCAL_INLINE void FlexCAN_SetPNPayloadHighFilter1(TT_CAN_Type * pBase, TT_CONST uint8 * pPayload)
{
    pBase->FLEXCAN_PL1_HI = TT_VAL2FLD(TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_4, pPayload[4]) | \
                   TT_VAL2FLD(TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_5, pPayload[5]) | \
                   TT_VAL2FLD(TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_6, pPayload[6]) | \
                   TT_VAL2FLD(TT_CAN_FLEXCAN_PL1_HI_Data_BYTE_7, pPayload[7]);
}

/*!
 * @brief Set PN Payload Low Filter 1.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pPayload  message Payload filter
 */
LOCAL_INLINE void FlexCAN_SetPNPayloadLowFilter1(TT_CAN_Type * pBase, TT_CONST uint8 * pPayload)
{
    pBase->FLEXCAN_PL1_LO = TT_VAL2FLD(TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_0, pPayload[0]) | \
                   TT_VAL2FLD(TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_1, pPayload[1]) | \
                   TT_VAL2FLD(TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_2, pPayload[2]) | \
                   TT_VAL2FLD(TT_CAN_FLEXCAN_PL1_LO_Data_BYTE_3, pPayload[3]);
}

/*!
 * @brief Set PN Payload High Filter 2.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pPayload  message Payload filter
 */
LOCAL_INLINE void FlexCAN_SetPNPayloadHighFilter2(TT_CAN_Type * pBase, TT_CONST uint8 * pPayload)
{
    pBase->FLEXCAN_PL2_PLMASK_HI = TT_VAL2FLD(TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_4, pPayload[4]) | \
                          TT_VAL2FLD(TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_5, pPayload[5]) | \
                          TT_VAL2FLD(TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_6, pPayload[6]) | \
                          TT_VAL2FLD(TT_CAN_FLEXCAN_PL2_PLMASK_HI_Data_BYTE_7, pPayload[7]);
}

/*!
 * @brief Set PN Payload Low Filter 2.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pPayload  message Payload filter
 */
LOCAL_INLINE void FlexCAN_SetPNPayloadLowFilter2(TT_CAN_Type * pBase, TT_CONST uint8 * pPayload)
{
    pBase->FLEXCAN_PL2_PLMASK_LO = TT_VAL2FLD(TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_0, pPayload[0]) | \
                          TT_VAL2FLD(TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_1, pPayload[1]) | \
                          TT_VAL2FLD(TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_2, pPayload[2]) | \
                          TT_VAL2FLD(TT_CAN_FLEXCAN_PL2_PLMASK_LO_Data_BYTE_3, pPayload[3]);
}

/*!
 * @brief Enables/Disables the Pretended Networking mode.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   enable  Enable/Disable Pretending Networking
 */
LOCAL_INLINE void FlexCAN_SetPN(TT_CAN_Type * pBase, boolean enable)
{
    pBase->FLEXCAN_MCR = (pBase->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_PNET_EN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_PNET_EN, enable ? 1UL : 0UL);
}

/*!
 * @brief Checks if the Pretended Networking mode is enabled/disabled.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  FALSE if Pretended Networking mode is disabled;
 *          TRUE if Pretended Networking mode is enabled
 */
LOCAL_INLINE boolean FlexCAN_IsPNEnabled(TT_CONST TT_CAN_Type * pBase)
{
    return ((pBase->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_PNET_EN_Msk) >> TT_CAN_FLEXCAN_MCR_PNET_EN_Pos) != 0U;
}

/*!
 * @brief Gets the Wake Up by Timeout Flag Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up by Timeout Flag Bit
 */
LOCAL_INLINE uint8 FlexCAN_GetWTOF(TT_CONST TT_CAN_Type * pBase)
{
    return (uint8)((pBase->FLEXCAN_WU_MTC & TT_CAN_FLEXCAN_WU_MTC_WTOF_Msk) >> TT_CAN_FLEXCAN_WU_MTC_WTOF_Pos);
}

/*!
 * @brief Gets the Wake Up Timeout interrupt enable Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up Timeout interrupt enable Bit
 */
LOCAL_INLINE uint8 FlexCAN_GetWTOIE(TT_CONST TT_CAN_Type * pBase)
{
    return (uint8)((pBase->FLEXCAN_CTRL1_PN & TT_CAN_FLEXCAN_CTRL1_PN_WTOF_MSK_Msk) >> TT_CAN_FLEXCAN_CTRL1_PN_WTOF_MSK_Pos);
}

/*!
 * @brief Clears the Wake Up by Timeout Flag Bit.
 *
 * @param   pBase  The FlexCAN Base address
 */
LOCAL_INLINE void FlexCAN_ClearWTOF(TT_CAN_Type * pBase)
{
    pBase->FLEXCAN_WU_MTC = TT_CAN_FLEXCAN_WU_MTC_WTOF_Msk;
}

/*!
 * @brief Gets the Wake Up by Match Flag Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up by Match Flag Bit
 */
LOCAL_INLINE uint8 FlexCAN_GetWUMF(TT_CONST TT_CAN_Type * pBase)
{
    return (uint8)((pBase->FLEXCAN_WU_MTC & TT_CAN_FLEXCAN_WU_MTC_WUMF_Msk) >> TT_CAN_FLEXCAN_WU_MTC_WUMF_Pos);
}

/*!
 * @brief Gets the Wake Up Match IE Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up Match IE Bit
 */
LOCAL_INLINE uint8 FlexCAN_GetWUMIE(TT_CONST TT_CAN_Type * pBase)
{
    return (uint8)((pBase->FLEXCAN_CTRL1_PN & TT_CAN_FLEXCAN_CTRL1_PN_WUMF_MSK_Msk) >> TT_CAN_FLEXCAN_CTRL1_PN_WUMF_MSK_Pos);
}

/*!
 * @brief Clears the Wake Up by Match Flag Bit.
 *
 * @param   pBase  The FlexCAN Base address
 */
LOCAL_INLINE void FlexCAN_ClearWUMF(TT_CAN_Type * pBase)
{
    pBase->FLEXCAN_WU_MTC = TT_CAN_FLEXCAN_WU_MTC_WUMF_Msk;
}

#endif /* FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING */

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXCAN_HW_H_ */
