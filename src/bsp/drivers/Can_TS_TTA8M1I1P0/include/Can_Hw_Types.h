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
**  FILENAME     : Can_Hw_Types.h                                             **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Can Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/

#ifndef CAN_HW_TYPES_H_
#define CAN_HW_TYPES_H_

/**
* @file Can_Hw_Types.h
*
* @brief FlexCAN Hw Types Header File
* @details This Files Contains the FlexCAN Hw data types used external by FlexCAN Hw Driver
*
* @addtogroup FlexCAN
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Hw_Cfg.h"

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
#include "Dma_Drv.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_TYPES_VENDOR_ID_H                      1541
#define FLEXCAN_HW_TYPES_MODULE_ID_H                      80
#define FLEXCAN_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_HW_TYPES_AR_RELEASE_MINOR_VERSION_H       4
#define FLEXCAN_HW_TYPES_AR_RELEASE_PATCH_VERSION_H       0
#define FLEXCAN_HW_TYPES_SW_MAJOR_VERSION_H               1
#define FLEXCAN_HW_TYPES_SW_MINOR_VERSION_H               1
#define FLEXCAN_HW_TYPES_SW_PATCH_VERSION_H               0
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and FlexCAN_Hw_Cfg header file are of the same vendor */
#if (FLEXCAN_HW_TYPES_VENDOR_ID_H != FLEXCAN_HW_CFG_VENDOR_ID_H)
    #error "FlexCAN_Hw_Types.h and FlexCAN_Hw_Cfg.h have different vendor ids"
#endif
#if (FLEXCAN_HW_TYPES_MODULE_ID_H != FLEXCAN_HW_CFG_MODULE_ID_H)
    #error "FlexCAN_Hw_Types.h and FlexCAN_Hw_Cfg.h have different module ids"
#endif
/* Check if current file and FlexCAN_Hw_Cfg header file are of the same Autosar version */
#if ((FLEXCAN_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_HW_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_TYPES_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_HW_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != FLEXCAN_HW_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Hw_Types.h and FlexCAN_Hw_Cfg.h are different"
#endif
/* Check if current file and FlexCAN_Hw_Cfg header file are of the same Software version */
#if ((FLEXCAN_HW_TYPES_SW_MAJOR_VERSION_H != FLEXCAN_HW_CFG_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_TYPES_SW_MINOR_VERSION_H != FLEXCAN_HW_CFG_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_TYPES_SW_PATCH_VERSION_H != FLEXCAN_HW_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Hw_Types.h and FlexCAN_Hw_Cfg.h are different"
#endif

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /* Check if current file and Dma header file are of the same Autosar version */
    #if (FLEXCAN_HW_TYPES_VENDOR_ID_H != DMA_DRV_VENDOR_ID_H)
        #error "FlexCAN_Hw_Types.h and Dma_Drv.h have different vendor ids"
    #endif
    #if ((FLEXCAN_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H    != DMA_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
         (FLEXCAN_HW_TYPES_AR_RELEASE_MINOR_VERSION_H    != DMA_DRV_AR_RELEASE_MINOR_VERSION_H) || \
         (FLEXCAN_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != DMA_DRV_AR_RELEASE_PATCH_VERSION_H))
        #error "AutoSar Version Numbers of FlexCAN_Hw_Types.h and Dma_Drv.h are different"
    #endif
    /* Check if current file and Dma header file are of the same Software version */
    #if ((FLEXCAN_HW_TYPES_SW_MAJOR_VERSION_H != DMA_DRV_SW_MAJOR_VERSION_H) || \
         (FLEXCAN_HW_TYPES_SW_MINOR_VERSION_H != DMA_DRV_SW_MINOR_VERSION_H) || \
         (FLEXCAN_HW_TYPES_SW_PATCH_VERSION_H != DMA_DRV_SW_PATCH_VERSION_H) )
        #error "Software Version Numbers of FlexCAN_Hw_Types.h and Dma_Drv.h are different"
    #endif
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/**@brief Remote Request Store enable */
#define FLEXCAN_HW_REM_STORE_U32                   ((uint32)0x00000001U)
/**@brief Three samples to determine the value of received bit */
#define FLEXCAN_HW_THREE_SAMPLES_U32               ((uint32)0x00000002U)
/**@brief Define how controller recover from bus off state */
#define FLEXCAN_HW_BUSOFF_RECOVERY_U32             ((uint32)0x00000004U)
/**@brief Protocol Exception */
#define FLEXCAN_HW_PROTOCOL_EXCEPTION_U32          ((uint32)0x00000008U)
/**@brief Edge Filter */
#define FLEXCAN_HW_EDGE_FILTER_U32                 ((uint32)0x00000010U)
/**@brief CAN FD protocol according to ISO specification (ISO 11898-1) */
#define FLEXCAN_HW_ISO_U32                         ((uint32)0x00000020U)
/**@brief Entire Frame Arbitration Field Comparison */
#define FLEXCAN_HW_EACEN_U32                       ((uint32)0x00000040U)
/******************************************************************************
*                            Enums
*******************************************************************************/

/*! @brief The type of the RxFIFO transfer (interrupts/DMA).
 */
/* implements Flexcan_Hw_RxFifoTransferType_enum */
typedef enum
{
    FLEXCAN_RXFIFO_USING_INTERRUPTS,    /**< Use interrupts for RxFIFO. */
    FLEXCAN_RXFIFO_USING_POLLING,       /**< Use polling method for RxFIFO */
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
    FLEXCAN_RXFIFO_USING_DMA            /**< Use DMA for RxFIFO. */
#endif
} Flexcan_Hw_RxFifoTransferType;

/*! @brief FlexCAN Rx FIFO filters number
 */
/* implements  Flexcan_Hw_RxFifoIdFilterNumType_enum */
typedef enum
{
    FLEXCAN_RX_FIFO_ID_FILTERS_8   = 0x0,         /**<  8 Rx FIFO Filters. @internal gui name="8 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_16  = 0x1,         /**<  16 Rx FIFO Filters. @internal gui name="16 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_24  = 0x2,         /**<  24 Rx FIFO Filters. @internal gui name="24 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_32  = 0x3,         /**<  32 Rx FIFO Filters. @internal gui name="32 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_40  = 0x4,         /**<  40 Rx FIFO Filters. @internal gui name="40 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_48  = 0x5,         /**<  48 Rx FIFO Filters. @internal gui name="48 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_56  = 0x6,         /**<  56 Rx FIFO Filters. @internal gui name="56 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_64  = 0x7,         /**<  64 Rx FIFO Filters. @internal gui name="64 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_72  = 0x8,         /**<  72 Rx FIFO Filters. @internal gui name="72 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_80  = 0x9,         /**<  80 Rx FIFO Filters. @internal gui name="80 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_88  = 0xA,         /**<  88 Rx FIFO Filters. @internal gui name="88 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_96  = 0xB,         /**<  96 Rx FIFO Filters. @internal gui name="96 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_104 = 0xC,         /**< 104 Rx FIFO Filters. @internal gui name="104 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_112 = 0xD,         /**< 112 Rx FIFO Filters. @internal gui name="112 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_120 = 0xE,         /**< 120 Rx FIFO Filters. @internal gui name="120 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_128 = 0xF          /**< 128 Rx FIFO Filters. @internal gui name="128 Rx FIFO Filters" */
} Flexcan_Hw_RxFifoIdFilterNumType;

/*! @brief FlexCAN Rx mask type.
 */
/* implements  Flexcan_Hw_RxMaskType_enum */
typedef enum
{
    FLEXCAN_RX_MASK_GLOBAL,      /**< Rx global mask */
    FLEXCAN_RX_MASK_INDIVIDUAL   /**< Rx individual mask */
} Flexcan_Hw_RxMaskType;


/*! @brief FlexCAN payload sizes
 */
/* implements Flexcan_Hw_FdPayloadSizeType_enum */
typedef enum
{
    FLEXCAN_PAYLOAD_SIZE_8 = 0,  /**< FlexCAN message buffer payload size in bytes*/
    FLEXCAN_PAYLOAD_SIZE_16 ,    /**< FlexCAN message buffer payload size in bytes*/
    FLEXCAN_PAYLOAD_SIZE_32 ,    /**< FlexCAN message buffer payload size in bytes*/
    FLEXCAN_PAYLOAD_SIZE_64      /**< FlexCAN message buffer payload size in bytes*/
} Flexcan_Hw_FdPayloadSizeType;


/*! @brief FlexCAN operation modes
 */
/*  implements  Flexcan_Hw_ModesType_enum */
typedef enum
{
    FLEXCAN_NORMAL_MODE,        /**< Normal mode or user mode @internal gui name="Normal" */
    FLEXCAN_LISTEN_ONLY_MODE,   /**< Listen-only mode @internal gui name="Listen-only" */
    FLEXCAN_LOOPBACK_MODE       /**< Loop-back mode @internal gui name="Loop back" */
} Flexcan_Hw_ModesType;

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/*! @brief FlexCAN Enhanced Rx FIFO filter type */
/* implements  Flexcan_Hw_EnhancedFilterType_structure */
typedef enum
{
    FLEXCAN_HW_ENHANCED_RX_FIFO_ONE_ID_FILTER = 0U,         /*!< Filter element with filter + mask scheme*/
    FLEXCAN_HW_ENHANCED_RX_FIFO_RANGE_ID_FILTER,       /*!< Filter element with range scheme*/
    FLEXCAN_HW_ENHANCED_RX_FIFO_TWO_ID_FILTER          /*!< Filter element with 2-filter scheme*/
} Flexcan_Hw_EnhancedFilterType;

/*! @brief FlexCAN Enhanced Rx FIFO ID filter table structure */
/* implements  Flexcan_Hw_EnhancedIdTableType_structure */
typedef struct
{
    Flexcan_Hw_EnhancedFilterType filterType;       /*!< Enhanced Rx FIFO filter type*/
    boolean isExtendedFrame;                           /*!< Extended frame*/
    boolean rtr2;                                      /*!< Enhanced Rx FIFO RTR2 */
    boolean rtr1;                                      /*!< Enhanced Rx FIFO RTR1 */
    uint32 id2;                                     /*!< Enhanced Rx FIFO ID2 filter element*/
    uint32 id1;                                     /*!< Enhanced Rx FIFO ID1 filter element*/
} Flexcan_Hw_EnhancedIdTableType;
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */

/*! @brief The state of a given MB (idle/Rx busy/Tx busy). */
/* implements  Flexcan_Hw_MbStateType_enum */
typedef enum
{
    FLEXCAN_MB_IDLE,      /**< The MB is not used by any transfer. */
    FLEXCAN_MB_RX_BUSY,   /**< The MB is used for a reception. */
    FLEXCAN_MB_TX_BUSY,   /**< The MB is used for a transmission. */
    FLEXCAN_MB_RX_OVER_ERROR,   /**< The MB is used for a reception. */
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
    FLEXCAN_MB_DMA_ERROR /**< The MB is used as DMA source and fail to transfer */
#endif
} Flexcan_Hw_MbStateType;

/*! @brief The type of the event which occurred when the callback was invoked.
 */
/* implements Flexcan_Hw_EventType_enum */
typedef enum
{
    FLEXCAN_EVENT_RX_COMPLETE = 0U,     /**< A frame was received in the configured Rx MB. */
    FLEXCAN_EVENT_RXFIFO_COMPLETE, /**< A frame was received in the Rx FIFO. */
    FLEXCAN_EVENT_RXFIFO_WARNING,  /**< Rx FIFO is almost full (5 frames). */
    FLEXCAN_EVENT_RXFIFO_OVERFLOW, /**< Rx FIFO is full (incoming message was lost). */
    FLEXCAN_EVENT_TX_COMPLETE,     /**< A frame was sent from the configured Tx MB. */
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    FLEXCAN_EVENT_ENHANCED_RXFIFO_COMPLETE,     /**< A frame was received in the Enhanced Rx FIFO. */
    FLEXCAN_EVENT_ENHANCED_RXFIFO_WATERMARK,    /**< The number of messages available is greater */
                                                /**< than the watermark defined. */
    FLEXCAN_EVENT_ENHANCED_RXFIFO_OVERFLOW,     /**< Enhanced Rx FIFO is full (incoming message was lost). */
    FLEXCAN_EVENT_ENHANCED_RXFIFO_UNDERFLOW,    /**< An underflow condition occurred in the enhanced Rx FIFO. */
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
    FLEXCAN_EVENT_WAKEUP_TIMEOUT,  /**< An wake up event occurred due to timeout. */
    FLEXCAN_EVENT_WAKEUP_MATCH,    /**< An wake up event occurred due to matching. */
#endif /* (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */
#if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE
    FLEXCAN_EVENT_DMA_COMPLETE = 11U,   /**< A complete transfer occurred on DMA */
    FLEXCAN_EVENT_DMA_ERROR = 12U,      /**< A DMA transfer fail, because of a DMA channel error */
#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
    FLEXCAN_EVENT_ERROR,         /**<  Errors detected in CAN frames of any format (interrupt mode only) */
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
    FLEXCAN_EVENT_ERROR_FAST,   /**< Errors detected in the data phase of CAN FD frames with the BRS bit set only (interrupt mode only) */
#endif /* FLEXCAN_HW_FEATURE_HAS_FD */
    FLEXCAN_EVENT_BUSOFF,       /**< FlexCAN module entered Bus Off state */
    FLEXCAN_EVENT_RX_WARNING,     /*!< The Rx error counter transitioned from less than 96 to greater than or equal to 96 (interrupt mode only) */
    FLEXCAN_EVENT_TX_WARNING     /*!< The Tx error counter transitioned from less than 96 to greater than or equal to 96 (interrupt mode only) */
} Flexcan_Hw_EventType;

/** @brief FlexCAN error interrupt types
 */
/* implements  Flexcan_Hw_ErrorIntType_enum */
typedef enum
{
    FLEXCAN_HW_INT_RX_WARNING,     /*!< RX warning interrupt*/
    FLEXCAN_HW_INT_TX_WARNING,     /*!< TX warning interrupt*/
    FLEXCAN_HW_INT_ERR,            /*!< Error interrupt*/
    FLEXCAN_HW_INT_ERR_FAST,       /*!< Error Fast interrupt*/
    FLEXCAN_HW_INT_BUSOFF          /*!< Bus off interrupt*/
} Flexcan_Hw_ErrorIntType;

/** @brief FlexCAN Message Buffer ID type
 *  @details FlexCAN Id Type, Standard or Extended
 */
/* implements Flexcan_Hw_MsgBuffIdType_enum */
typedef enum
{
    FLEXCAN_MSG_ID_STD = 0,     /**< Standard ID*/
    FLEXCAN_MSG_ID_EXT          /**< Extended ID*/
} Flexcan_Hw_MsgBuffIdType;

/** @brief ID formats for Rx FIFO
 *  @details Legacy RxFIFO Id Format Types
 */
/*  implements Flexcan_Hw_RxFifoIdElementFormatType_enum */
typedef enum
{
    FLEXCAN_RX_FIFO_ID_FORMAT_A, /**< One full ID (standard and extended) per ID Filter Table element.*/
    FLEXCAN_RX_FIFO_ID_FORMAT_B, /**< Two full standard IDs or two partial 14-bit (standard and
                                      extended) IDs per ID Filter Table element.*/
    FLEXCAN_RX_FIFO_ID_FORMAT_C, /**< Four partial 8-bit Standard IDs per ID Filter Table element.*/
    FLEXCAN_RX_FIFO_ID_FORMAT_D  /**< All frames rejected.*/
} Flexcan_Hw_RxFifoIdElementFormatType;

/** @brief The status used and reported by FlexCAN Hw driver.
 *  @details The FlexCAN specific error codes
 */
/* implements  Flexcan_Hw_StatusType_enum */
typedef enum
{
    FLEXCAN_STATUS_SUCCESS  = E_OK,          /**< Successfull Operation Completed */
    FLEXCAN_STATUS_ERROR    = E_NOT_OK,         /**< Error Operation Completed */
    FLEXCAN_STATUS_BUSY,                     /**< Busy Operation Completed */
    FLEXCAN_STATUS_TIMEOUT,                  /**< TimeOut Operation Completed */
    FLEXCAN_STATUS_BUFF_OUT_OF_RANGE,        /**< The specified MB index is out of the configurable range */
    FLEXCAN_STATUS_NO_TRANSFER_IN_PROGRESS   /**< There is no transmission or reception in progress */
} Flexcan_Hw_StatusType;

/** @brief implements Tx Priority enum */
typedef enum
{
    CAN_TX_PRIORITY_LOW_NUMBER,
    CAN_TX_PRIORITY_LOCAL_ENABLE,
    CAN_TX_PRIORITY_LOCAL_DISABLE
} Flexcan_TxPriority;

/** @brief implements Rx Priority enum */
typedef enum
{
    CAN_RX_PRIORITY_RXFIFO_TO_MB,
    CAN_RX_PRIORITY_MB_TO_RXFIFO
} Flexcan_RxPriority;

/*! @brief Pretended Networking filtering combinations */
typedef enum
{
    FLEXCAN_FILTER_ID,                  /*!< Message ID filtering only */
    FLEXCAN_FILTER_ID_PAYLOAD,          /*!< Message ID and payload filtering */
    FLEXCAN_FILTER_ID_NTIMES,           /*!< Message ID filtering occurring a specified number of times */
    FLEXCAN_FILTER_ID_PAYLOAD_NTIMES    /*!< Message ID and payload filtering  occurring a specified number of times */
} Flexcan_Hw_PnfilterCombinationType;

/*! @brief Pretended Networking matching schemes */
typedef enum
{
    FLEXCAN_FILTER_MATCH_EXACT,   /*!< Match an exact target value. */
    FLEXCAN_FILTER_MATCH_GEQ,     /*!< Match greater than or equal to a specified target value. */
    FLEXCAN_FILTER_MATCH_LEQ,     /*!< Match less than or equal to a specified target value. */
    FLEXCAN_FILTER_MATCH_RANGE    /*!< Match inside a range, greater than or equal to a specified lower limit and smaller than or
                                      equal to a specified upper limit. */
} Flexcan_Hw_PnFilterSelectionType;
/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/*! @brief FlexCAN bitrate related structures
 */
/* implements  Flexcan_Hw_TimeSegmentType_structure */
typedef struct
{
    uint32 propSeg;         /**< Propagation segment*/
    uint32 phaseSeg1;       /**< Phase segment 1*/
    uint32 phaseSeg2;       /**< Phase segment 2*/
    uint32 preDivider;      /**< Clock prescaler division factor*/
    uint32 rJumpwidth;      /**< Resync jump width*/
} Flexcan_Hw_TimeSegmentType;

/*! @brief FlexCAN Blocks payload sizes structure
 */
/*  implements  Flexcan_Hw_PayloadSizeType_structure */
typedef struct
{   /** Payload for  Ram Block 0*/
    Flexcan_Hw_FdPayloadSizeType payloadBlock0;
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 1)
    /** Payload for Ram Block 1 */
    Flexcan_Hw_FdPayloadSizeType payloadBlock1;
#endif
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 2)
    /** Payload for Ram Block 2 */
    Flexcan_Hw_FdPayloadSizeType payloadBlock2;
#endif
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 3)
    /** Payload for Ram Block 3 */
    Flexcan_Hw_FdPayloadSizeType payloadBlock3;
#endif
} Flexcan_Hw_PayloadSizeType;

/*! @brief FlexCAN message buffer structure
 */
/*  implements  Flexcan_Hw_MsgBuffType_structure */
typedef struct
{
    uint32 cs;                        /**< Code and Status*/
    uint32 msgId;                     /**< Message Buffer ID*/
    uint8 data[64];                   /**< Data bytes of the FlexCAN message*/
    uint8 dataLen;                    /**< Length of data in bytes */
    uint8 id_hit;                     /**< Identifier Acceptance Filter Hit Indicator*/
    uint32 time_stamp;                /**< Free-Running Counter Time Stamp*/
} Flexcan_Hw_MsgBuffType;

/*! @brief Information needed for internal handling of a given MB. */
/* implements  Flexcan_Hw_MBhandleType_structure */
typedef struct
{
    Flexcan_Hw_MsgBuffType *pMBmessage;    /**< The FlexCAN MB structure */
    volatile Flexcan_Hw_MbStateType state;  /**< The state of the current MB (idle/Rx busy/Tx busy) */
    boolean isPolling;                      /**< True if the transfer is Polling Mode  */
    boolean isRemote;                       /**< True if the frame is a remote frame */
    uint32  time_stamp;                     /**< TimeStamp of the Message */
} Flexcan_Hw_MBhandleType;

/*!
 * @brief Internal driver state information.
 *
 * @note The contents of this structure are internal to the driver and should not be
 *      modified by users. Also, contents of the structure are subject to change in
 *      future releases.
 */
/* implements   Flexcan_Hw_StateType_structure */
typedef struct FlexCANState
{
    Flexcan_Hw_MBhandleType mbs[FLEXCAN_HW_FEATURE_MAX_MB_NUM];       /**< Array containing information
                                                                    related to each MB */
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    Flexcan_Hw_MBhandleType enhancedFifoOutput;                /**< Containing information output of Enhanced Rx FIFO */
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
    void (*callback)(uint8 instance,
                     Flexcan_Hw_EventType eventType,
                     uint32 buffIdx,
                     TT_CONST struct FlexCANState *driverState);        /**< IRQ handler callback function. */
    void *callbackParam;                                       /**< Parameter used to pass user data
                                                                    when invoking the callback function. */
    void (*error_callback)(uint8 instance,
                           Flexcan_Hw_EventType eventType,
                           uint32 u32ErrStatus,
                           TT_CONST struct FlexCANState *driverState);   /**< Error IRQ handler callback
                                                                    function. */
    void *errorCallbackParam;                                  /**< Parameter used to pass user data
                                                                    when invoking the error callback function. */
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
    uint8 rxFifoDMAChannel;                                    /**< DMA channel number used for transfers. */
    Dma_SignalEvent_t cb_event;     
#endif /* (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON) */
    Flexcan_Hw_RxFifoTransferType transferType;                /**< Type of RxFIFO transfer. */
    boolean bIsLegacyFifoEn;                                   /**< This controls whether the Rx FIFO feature is enabled or not. */
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    boolean bIsEnhancedFifoEn;                                 /**< This controls whether the Rx Enhanced FIFO feature is enabled or not. */
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
    uint32 u32MaxMbNum;                                        /**< The maximum number of Message Buffers. */
    boolean isIntActive;                                       /**< Save status of enabling/disabling interrupts in runtime. */
} Flexcan_Hw_StateType;

/*! @brief FlexCAN Driver callback function type
 */
/* implements FlexCAN_Hw_CallbackType_typdef */
typedef void (* FlexCAN_Hw_CallbackType)(uint8 instance,
                                         Flexcan_Hw_EventType eventType,
                                         uint32 buffIdx,
                                         TT_CONST Flexcan_Hw_StateType * flexcanState);

/*! @brief FlexCAN Driver error callback function type
 */
/* implements  FlexCAN_Hw_ErrorCallbackType_typdef  */
typedef void (* FlexCAN_Hw_ErrorCallbackType)(uint8 instance,
                                              Flexcan_Hw_EventType eventType,
                                              uint32 u32ErrStatus,
                                              TT_CONST Flexcan_Hw_StateType * flexcanState);

/*! @brief FlexCAN configuration
 * @internal gui name="Common configuration" id="flexcanCfg"
 */
/* implements   Flexcan_Hw_ConfigType_structure */
typedef struct
{
    uint32 max_num_mb;                              /**< The maximum number of Message Buffers
                                                         @internal gui name="Maximum number of message buffers" id="max_num_mb" */
    Flexcan_Hw_RxFifoIdFilterNumType num_id_filters; /**< The number of RX FIFO ID filters needed
                                                         @internal gui name="Number of RX FIFO ID filters" id="num_id_filters" */
    boolean is_rx_fifo_needed;                         /**< 1 if needed; 0 if not. This controls whether the Rx FIFO feature is enabled or not.
                                                         @internal gui name="Use rx fifo" id="is_rx_fifo_needed" */
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    uint32 num_enhanced_std_id_filters;             /**< The number of standard ID filter elements
                                                         @internal gui name="Number of standard ID filter elements" id="num_enhanced_std_id_filters" */
    uint32 num_enhanced_ext_id_filters;             /**< The number of extended ID filter elements
                                                         @internal gui name="Number of extended ID filter elements" id="num_enhanced_ext_id_filters" */
    uint32 num_enhanced_watermark;                  /**< The number of enhanced Rx FIFO watermark
                                                         @internal gui name="Number of enhanced Rx FIFO watermark" id="num_enhanced_watermark" */                                                       
    boolean is_enhanced_rx_fifo_needed;                /**< 1 if needed; 0 if not. This controls whether the Enhanced Rx FIFO feature is enabled or not.
                                                         @internal gui name="Use enhanced rx fifo" id="is_enhanced rx_fifo_needed" */
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
    Flexcan_Hw_ModesType flexcanMode;               /**< User configurable FlexCAN operation modes.
                                                         @internal gui name="Flexcan Operation Mode" id="flexcanMode" */
    uint32 ctrlOptions;                             /**< Use of different features support like ISO-FD, EDGE_FILTER, AUTO_BussOffRecovery, Protocol_Exception. */
    Flexcan_Hw_PayloadSizeType payload;               /**< The payload size of the mailboxes specified in bytes for every partition block */
    boolean fd_enable;                                 /**< Enable/Disable the Flexible Data Rate feature. */
    boolean enhCbtEnable;                               /**< The use of enhanced bit time segments format from ExCBT register, instead of CTRL1 or CBT register */
    boolean bitRateSwitch;                              /**< Enable of BitRate Switch support for FD frames */
    Flexcan_Hw_TimeSegmentType bitrate;                 /**< The bitrate used for standard frames or for the arbitration phase of FD frames. */
    Flexcan_Hw_TimeSegmentType bitrate_cbt;             /**< The bitrate used for the data phase of FD frames. */
    Flexcan_Hw_RxFifoTransferType transfer_type;   /**< Specifies if the Rx FIFO uses interrupts or DMA. */
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
    uint8 rxFifoDMAChannel;                                    /**< DMA channel number used for transfers. */   
    Dma_SignalEvent_t cb_event;     
#endif /* (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON) */  
    FlexCAN_Hw_CallbackType Callback;               /**< The Callback for Rx or Tx Events */
    FlexCAN_Hw_ErrorCallbackType ErrorCallback;     /**< The ErrorCallback for Error Events */
} Flexcan_Hw_ConfigType;

/** @brief FlexCAN Rx FIFO ID filter table structure
 *  @details Structure Used to configure and add filters to Legacy RxFIFO
 */
/* implements  Flexcan_Hw_IdTableType_structure */
typedef struct
{
    boolean isRemoteFrame;      /**< Remote frame*/
    boolean isExtendedFrame;    /**< Extended frame*/
    uint32 id;                  /**< Rx FIFO ID filter element*/
} Flexcan_Hw_IdTableType;

/** @brief FlexCAN data info from user
 *  @details This structure defines the members used to configure the Frame Parameters used to be Send or Receive.
 *           Some parameters are available based on configuration of driver like: fd_enable, fd_padding, enable_brs.
 */
/* implements  Flexcan_Hw_DataInfoType_structure */
typedef struct
{
    Flexcan_Hw_MsgBuffIdType msg_id_type;  /**< Type of message ID (standard or extended)*/
    uint32 data_length;                    /**< Length of Data in Bytes*/
    boolean fd_enable;                     /**< Enable or disable FD*/
    uint8 fd_padding;                      /**< Set a value for padding. It will be used when the data length code (DLC)
                                                 specifies a bigger payload size than data_length to fill the MB */
    boolean enable_brs;                    /**< Enable bit rate switch inside a CAN FD format frame*/
    boolean is_remote;                     /**< Specifies if the frame is standard or remote */
    boolean is_polling;                    /**< Specifies if the MB is in polling mode */
} Flexcan_Hw_DataInfoType;

#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/*! @brief Pretended Networking ID filter */
typedef struct
{
    boolean bExtendedId;    /*!< Specifies if the ID is standard or extended. */
    boolean bRemoteFrame;   /*!< Specifies if the frame is standard or remote. */
    uint32 u32Id;           /*!< Specifies the ID value. */
} Flexcan_Hw_PnIdFilterType;

/*! @brief Pretended Networking payload filter */
typedef struct
{
    uint8 u8DlcLow;       /*!< Specifies the lower limit of the payload size. */
    uint8 u8DlcHigh;      /*!< Specifies the upper limit of the payload size. */
    uint8 aPayload1[8U]; /*!< Specifies the payload to be matched (for MATCH_EXACT), the lower limit
                              (for MATCH_GEQ and MATCH_RANGE) or the upper limit (for MATCH_LEQ). */
    uint8 aPayload2[8U]; /*!< Specifies the mask (for MATCH_EXACT) or the upper limit (for MATCH_RANGE). */
} Flexcan_Hw_PnPayloadFilterType;

/*! @brief Pretended Networking configuration structure */
/* implements  Flexcan_Hw_PnConfigType_structure */
typedef struct
{
    boolean bWakeUpTimeout;                               /*!< Specifies if an wake up event is triggered on timeout. */
    boolean bWakeUpMatch;                                 /*!< Specifies if an wake up event is triggered on match. */
    uint16 u16NumMatches;                                 /*!< The number of matches needed before generating an wake up event. */
    uint16 u16MatchTimeout;                               /*!< Defines a timeout value that generates an wake up event if wakeUpTimeout is true. */
    Flexcan_Hw_PnfilterCombinationType eFilterComb;       /*!< Defines the filtering scheme used. */
    Flexcan_Hw_PnIdFilterType idFilter1;                  /*!< The configuration of the first ID filter (match exact / lower limit / upper limit). */
    Flexcan_Hw_PnIdFilterType idFilter2;                  /*!< The configuration of the second ID filter (mask / upper limit). */
    Flexcan_Hw_PnFilterSelectionType eIdFilterType;       /*!< Defines the ID filtering scheme. */
    Flexcan_Hw_PnFilterSelectionType ePayloadFilterType;  /*!< Defines the payload filtering scheme. */
    Flexcan_Hw_PnPayloadFilterType payloadFilter;         /*!< The configuration of the payload filter. */
} Flexcan_Hw_PnConfigType;
#endif /* (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXCAN_HW_TYPES_H_ */
