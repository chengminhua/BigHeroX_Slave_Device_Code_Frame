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
**  FILENAME     : Can_Hw_PBcfg.c                                             **
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

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Hw_Types.h"
#include "Can_Irq.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_PBCFG_VENDOR_ID_C                       1541
#define FLEXCAN_HW_PBCFG_MODULE_ID_C                       80
#define FLEXCAN_HW_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FLEXCAN_HW_PBCFG_AR_RELEASE_MINOR_VERSION_C        4
#define FLEXCAN_HW_PBCFG_AR_RELEASE_PATCH_VERSION_C        0
#define FLEXCAN_HW_PBCFG_SW_MAJOR_VERSION_C                1
#define FLEXCAN_HW_PBCFG_SW_MINOR_VERSION_C                1
#define FLEXCAN_HW_PBCFG_SW_PATCH_VERSION_C                0
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and FlexCAN_Hw_Types header file are of the same vendor */
#if (FLEXCAN_HW_PBCFG_VENDOR_ID_C != FLEXCAN_HW_TYPES_VENDOR_ID_H)
    #error "FlexCAN_Hw__PBcfg.c and FlexCAN_Hw_Types.h have different vendor ids"
#endif
#if (FLEXCAN_HW_PBCFG_MODULE_ID_C != FLEXCAN_HW_TYPES_MODULE_ID_H)
    #error "FlexCAN_Hw__PBcfg.c and FlexCAN_Hw_Types.h have different module ids"
#endif
/* Check if current file and FlexCAN_Hw_Types header file are of the same Autosar version */
#if ((FLEXCAN_HW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FLEXCAN_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_PBCFG_AR_RELEASE_MINOR_VERSION_C != FLEXCAN_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_PBCFG_AR_RELEASE_PATCH_VERSION_C != FLEXCAN_HW_TYPES_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Hw_PBcfg.c and FlexCAN_Hw_Types.h are different"
#endif
/* Check if current file and FlexCAN_Hw_Types header file are of the same Software version */
#if ((FLEXCAN_HW_PBCFG_SW_MAJOR_VERSION_C != FLEXCAN_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_PBCFG_SW_MINOR_VERSION_C != FLEXCAN_HW_TYPES_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_PBCFG_SW_PATCH_VERSION_C != FLEXCAN_HW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Hw_PBcfg.c and FlexCAN_Hw_Types.h are different"
#endif

/* Check if current file and Can_Irq header file are of the same vendor */
#if (FLEXCAN_HW_PBCFG_VENDOR_ID_C != CAN_IRQ_VENDOR_ID_H)
    #error "FlexCAN_Hw_PBcfg.c and Can_Irq.h have different vendor ids"
#endif
#if (FLEXCAN_HW_PBCFG_MODULE_ID_C != CAN_IRQ_MODULE_ID_H)
        #error "FlexCAN_Hw_PBcfg.c and Can_Irq.h have different module ids"
    #endif
/* Check if current file and Can_Irq header file are of the same Autosar version */
#if ((FLEXCAN_HW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CAN_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_PBCFG_AR_RELEASE_MINOR_VERSION_C != CAN_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_PBCFG_AR_RELEASE_PATCH_VERSION_C != CAN_IRQ_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Hw_PBcfg.c and Can_Irq.h are different"
#endif
/* Check if current file and Can_Irq header file are of the same Software version */
#if ((FLEXCAN_HW_PBCFG_SW_MAJOR_VERSION_C != CAN_IRQ_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_PBCFG_SW_MINOR_VERSION_C != CAN_IRQ_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_PBCFG_SW_PATCH_VERSION_C != CAN_IRQ_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Hw_PBcfg.c and Can_Irq.h are different"
#endif


/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Public Constants
*******************************************************************************/

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

TT_CONST Flexcan_Hw_ConfigType Flexcan_aCtrlConfigPB[3U]=
{
    /* Can Hardware Channel CAN2 */
    {
        /* Number Of Message Buffer used .max_num_mb */
        .max_num_mb = (uint8)67U,
        /*Can Hw filter count* .num_id_filters */
        .num_id_filters = (Flexcan_Hw_RxFifoIdFilterNumType)0U,
        /* Legacy FIFO ENABLED .is_rx_fifo_needed */
        .is_rx_fifo_needed = (boolean)FALSE,
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        /* The number of standard ID filter elements */
        .num_enhanced_std_id_filters = 0U,
        /* The number of extended ID filter elements */
        .num_enhanced_ext_id_filters = 0U,
        /* The number of enhanced Rx FIFO watermark */
        .num_enhanced_watermark = 19U,
        /* The Enhanced Rx FIFO feature is enabled or not. */
        .is_enhanced_rx_fifo_needed = (boolean)FALSE,
#endif
        /* Loopback enabled .flexcanMode */
        .flexcanMode = FLEXCAN_NORMAL_MODE,
        /* Controller Options .ctrlOptions */
        .ctrlOptions = (uint32)( FLEXCAN_HW_ISO_U32 | FLEXCAN_HW_EACEN_U32),
        /* Can FD RamBlock specified .payload */
        .payload = {
                        .payloadBlock0 = FLEXCAN_PAYLOAD_SIZE_8,
                        .payloadBlock1 = FLEXCAN_PAYLOAD_SIZE_16,
                        .payloadBlock2 = FLEXCAN_PAYLOAD_SIZE_32,
                        .payloadBlock3 = FLEXCAN_PAYLOAD_SIZE_64
                   },
        /* Can FD enabled .fd_enable */
        .fd_enable = (boolean)TRUE,
        /* Cbt support .extCbtEnable */
        .enhCbtEnable = (boolean)FALSE,
        /*  BRS for FD .bitRateSwitch */
        .bitRateSwitch = (boolean)TRUE,
        /* Values for normal baudrate .bitrate */
        .bitrate = {
                        .propSeg = (uint8)3U,
                        .phaseSeg1 = (uint8)2U,
                        .phaseSeg2 = (uint8)1U,
                        .preDivider = (uint16)3U,
                        .rJumpwidth = (uint8)1U
                   },
        /* Values for CBT baudrate .bitrate_cbt */
        .bitrate_cbt = {
                            .propSeg = (uint8)3U,
                            .phaseSeg1 = (uint8)2U,
                            .phaseSeg2 = (uint8)2U,
                            .preDivider = (uint16)1U,
                            .rJumpwidth = (uint8)1U,
                       },
        /* Fifo Transfer Type .transfer_type */
        .transfer_type = FLEXCAN_RXFIFO_USING_INTERRUPTS,
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* DMA channel number used for transfers. */
        .rxFifoDMAChannel = (uint8)0U,
        .cb_event = NULL_PTR,
#endif
        /* Controller Callback .Callback */
        .Callback = Can_CommonIrqCallback,
        /* Error Callback .ErrorCallback */
        .ErrorCallback = Can_ErrorIrqCallback
    },
    /* Can Hardware Channel CAN1 */
    {
        /* Number Of Message Buffer used .max_num_mb */
        .max_num_mb = (uint8)98U,
        /*Can Hw filter count* .num_id_filters */
        .num_id_filters = (Flexcan_Hw_RxFifoIdFilterNumType)0U,
        /* Legacy FIFO ENABLED .is_rx_fifo_needed */
        .is_rx_fifo_needed = (boolean)FALSE,
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        /* The number of standard ID filter elements */
        .num_enhanced_std_id_filters = 0U,
        /* The number of extended ID filter elements */
        .num_enhanced_ext_id_filters = 0U,
        /* The number of enhanced Rx FIFO watermark */
        .num_enhanced_watermark = 19U,
        /* The Enhanced Rx FIFO feature is enabled or not. */
        .is_enhanced_rx_fifo_needed = (boolean)FALSE,
#endif
        /* Loopback enabled .flexcanMode */
        .flexcanMode = FLEXCAN_NORMAL_MODE,
        /* Controller Options .ctrlOptions */
        .ctrlOptions = (uint32)( FLEXCAN_HW_ISO_U32 | FLEXCAN_HW_EACEN_U32),
        /* Can FD RamBlock specified .payload */
        .payload = {
                        .payloadBlock0 = FLEXCAN_PAYLOAD_SIZE_8,
                        .payloadBlock1 = FLEXCAN_PAYLOAD_SIZE_8,
                        .payloadBlock2 = FLEXCAN_PAYLOAD_SIZE_8,
                        .payloadBlock3 = FLEXCAN_PAYLOAD_SIZE_8
                   },
        /* Can FD enabled .fd_enable */
        .fd_enable = (boolean)TRUE,
        /* Cbt support .extCbtEnable */
        .enhCbtEnable = (boolean)FALSE,
        /*  BRS for FD .bitRateSwitch */
        .bitRateSwitch = (boolean)FALSE,
        /* Values for normal baudrate .bitrate */
        .bitrate = {
                        .propSeg = (uint8)3U,
                        .phaseSeg1 = (uint8)2U,
                        .phaseSeg2 = (uint8)1U,
                        .preDivider = (uint16)3U,
                        .rJumpwidth = (uint8)1U
                   },
        /* Values for CBT baudrate .bitrate_cbt */
        .bitrate_cbt = {
                            .propSeg = (uint8)3U,
                            .phaseSeg1 = (uint8)2U,
                            .phaseSeg2 = (uint8)1U,
                            .preDivider = (uint16)3U,
                            .rJumpwidth = (uint8)1U,
                       },
        /* Fifo Transfer Type .transfer_type */
        .transfer_type = FLEXCAN_RXFIFO_USING_INTERRUPTS,
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* DMA channel number used for transfers. */
        .rxFifoDMAChannel = (uint8)0U,
        .cb_event = NULL_PTR,
#endif
        /* Controller Callback .Callback */
        .Callback = Can_CommonIrqCallback,
        /* Error Callback .ErrorCallback */
        .ErrorCallback = Can_ErrorIrqCallback
    },
    /* Can Hardware Channel CAN4 */
    {
        /* Number Of Message Buffer used .max_num_mb */
        .max_num_mb = (uint8)67U,
        /*Can Hw filter count* .num_id_filters */
        .num_id_filters = (Flexcan_Hw_RxFifoIdFilterNumType)0U,
        /* Legacy FIFO ENABLED .is_rx_fifo_needed */
        .is_rx_fifo_needed = (boolean)FALSE,
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        /* The number of standard ID filter elements */
        .num_enhanced_std_id_filters = 0U,
        /* The number of extended ID filter elements */
        .num_enhanced_ext_id_filters = 0U,
        /* The number of enhanced Rx FIFO watermark */
        .num_enhanced_watermark = 19U,
        /* The Enhanced Rx FIFO feature is enabled or not. */
        .is_enhanced_rx_fifo_needed = (boolean)FALSE,
#endif
        /* Loopback enabled .flexcanMode */
        .flexcanMode = FLEXCAN_NORMAL_MODE,
        /* Controller Options .ctrlOptions */
        .ctrlOptions = (uint32)( FLEXCAN_HW_ISO_U32 | FLEXCAN_HW_EACEN_U32),
        /* Can FD RamBlock specified .payload */
        .payload = {
                        .payloadBlock0 = FLEXCAN_PAYLOAD_SIZE_8,
                        .payloadBlock1 = FLEXCAN_PAYLOAD_SIZE_16,
                        .payloadBlock2 = FLEXCAN_PAYLOAD_SIZE_32,
                        .payloadBlock3 = FLEXCAN_PAYLOAD_SIZE_64
                   },
        /* Can FD enabled .fd_enable */
        .fd_enable = (boolean)TRUE,
        /* Cbt support .extCbtEnable */
        .enhCbtEnable = (boolean)FALSE,
        /*  BRS for FD .bitRateSwitch */
        .bitRateSwitch = (boolean)FALSE,
        /* Values for normal baudrate .bitrate */
        .bitrate = {
                        .propSeg = (uint8)3U,
                        .phaseSeg1 = (uint8)2U,
                        .phaseSeg2 = (uint8)1U,
                        .preDivider = (uint16)3U,
                        .rJumpwidth = (uint8)1U
                   },
        /* Values for CBT baudrate .bitrate_cbt */
        .bitrate_cbt = {
                            .propSeg = (uint8)3U,
                            .phaseSeg1 = (uint8)2U,
                            .phaseSeg2 = (uint8)1U,
                            .preDivider = (uint16)3U,
                            .rJumpwidth = (uint8)1U,
                       },
        /* Fifo Transfer Type .transfer_type */
        .transfer_type = FLEXCAN_RXFIFO_USING_INTERRUPTS,
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* DMA channel number used for transfers. */
        .rxFifoDMAChannel = (uint8)0U,
        .cb_event = NULL_PTR,
#endif
        /* Controller Callback .Callback */
        .Callback = Can_CommonIrqCallback,
        /* Error Callback .ErrorCallback */
        .ErrorCallback = Can_ErrorIrqCallback
    }
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
