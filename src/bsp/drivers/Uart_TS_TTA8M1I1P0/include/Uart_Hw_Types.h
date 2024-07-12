/*************************************************************************************
**                                                                                  **
** Copyright (c) ThinkTech Technologies (2023)                                      **
**                                                                                  **
** All rights reserved.                                                             **
**                                                                                  **
** This document contains proprietary information beloging to ThinkTech             **
** Technologies. Passing on and copying of this document, and communication         **
** of its contents is not permitted without prior written authorization.            **
**                                                                                  **
**************************************************************************************
**                                                                                  **
**  FILENAME     : Uart_Hw_Types.h                                                  **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : Uart Driver Source File                                          **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                     **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                               History                                             **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifndef UART_HW_TYPES_H
#define UART_HW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Uart_Drv_Cfg.h"
/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define UART_HW_TYPES_VENDOR_ID_H                     1541
#define UART_HW_TYPES_MODULE_ID_H                     227
#define UART_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define UART_HW_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define UART_HW_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define UART_HW_TYPES_SW_MAJOR_VERSION_H              1
#define UART_HW_TYPES_SW_MINOR_VERSION_H              1
#define UART_HW_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/

/* Uart_Hw_Types.h and Uart_Drv_Cfg.h file version check */
#if (UART_HW_TYPES_VENDOR_ID_H != UART_DRV_CFG_VENDOR_ID_H)
    #error "Uart_Hw_Types.h and Uart_Drv_Cfg.h have different vendor ids"
#endif
#if (UART_HW_TYPES_MODULE_ID_H != UART_DRV_CFG_MODULE_ID_H)
    #error "Uart_Hw_Types.h and Uart_Drv_Cfg.h have different module ids"
#endif
#if ((UART_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != UART_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != UART_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != UART_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hw_Types.h and Uart_Drv_Cfg.h are different"
#endif
#if ((UART_HW_TYPES_SW_MAJOR_VERSION_H != UART_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (UART_HW_TYPES_SW_MINOR_VERSION_H != UART_DRV_CFG_SW_MINOR_VERSION_H) || \
     (UART_HW_TYPES_SW_PATCH_VERSION_H != UART_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hw_Types.h and Uart_Drv_Cfg.h are different"
#endif

/******************************************************************************
 *                      Global variable  Definitions
 ******************************************************************************/
/* Software ID difference between Uart and LIN */
#define UART_LIN_ID_DIFF                (0x04)
/*Uart Hard ID MAX */
#define UART_HDID_MAX                   (3UL)

/******************************************************************************
 *                            Structures And Typedefs
 *******************************************************************************/
 /**
 \brief USART Status
 */
typedef struct _TT_USART_STATUS
{
    /* Transmitter busy flag */
    uint32 tx_busy          :1;
    /* Receiver busy flag */
    uint32 rx_busy          :1;
    /* Transmit data underflow detected (cleared on start of next send operation) */
    uint32 tx_underflow     :1;
    /* Receive data overflow detected (cleared on start of next receive operation) */
    uint32 rx_overflow      :1;
    /* Break detected on receive (cleared on start of next receive operation) */
    uint32 rx_break         :1;
    /* Framing error detected on receive (cleared on start of next receive operation) */
    uint32 rx_framing_error :1;
    /* Parity error detected on receive (cleared on start of next receive operation) */
    uint32 rx_parity_error  :1;
    uint32 reserved         :25;
} Uart_StatusFlag;

/* Pointer to \ref TT_USART_SignalEvent : Signal USART Event. */
typedef void (*TT_USART_SignalEvent_t)(uint32 event);

/**
 \brief USART Callback Event
 */
typedef enum _TT_USART_CALLBACK_EVENT
{
    /* Send completed; however USART may still transmit data */
    TT_USART_EVENT_SEND_COMPLETE             = (1UL << 0),
    /* Send incompleted */
    TT_USART_EVENT_SEND_INCOMPLETE           = (1UL << 1),
    /* Receive completed */
    TT_USART_EVENT_RECEIVE_COMPLETE          = (1UL << 2),
    /* Receive incompleted */
    TT_USART_EVENT_RECEIVE_INCOMPLETE        = (1UL << 3),
    /* Output compare error */
    TT_USART_EVENT_RX_OUTPUT_COMPARE_ERROR   = (1UL << 4),
    /* Receive data overflow */
    TT_USART_EVENT_RX_OVERFLOW               = (1UL << 5),
    /* Stuck at zero error */
    TT_USART_EVENT_RX_STUCK_AT_ZERO_ERROR    = (1UL << 6),
    /* Break detected on receive */
    TT_USART_EVENT_RX_BREAK                  = (1UL << 7),
    /* Framing error detected on receive */
    TT_USART_EVENT_RX_FRAMING_ERROR          = (1UL << 8),
    /* Parity error detected on receive */
    TT_USART_EVENT_RX_PARITY_ERROR           = (1UL << 9),
    /* Noise error */
    TT_USART_EVENT_RX_NOISE_ERROR            = (1UL << 10),
    /* Receive timeout */
    TT_USART_EVENT_RX_TIMEOUT_ERROR          = (1UL << 11),
} Uart_CallBackEvent;

/**
 \brief Overall Uart status
 */
typedef enum
{
    UART_STATUS_UNINIT,
    UART_STATUS_IDLE,
    UART_STATUS_BUSY,
} Uart_StatusType;


/**
 \brief USART Device Driver Capabilities.
 */
typedef struct _Uart_Capabilities
{
    /* supports UART (Asynchronous) mode */
    uint32 asynchronous         :1;
    /* supports Synchronous Master mode */
    uint32 synchronous_master   :1;
    /* supports Synchronous Slave mode */
    uint32 synchronous_slave    :1;
    /* supports UART Single-wire mode */
    uint32 single_wire          :1;
    /* supports UART IrDA mode */
    uint32 irda                 :1;
    /* supports UART Smart Card mode */
    uint32 smart_card           :1;
    /* Smart Card Clock generator available */
    uint32 smart_card_clock     :1;
    /* RTS Flow Control available */
    uint32 flow_control_rts     :1;
    /* CTS Flow Control available */
    uint32 flow_control_cts     :1;
    /* Transmit completed event: \ref TT_USART_EVENT_TX_COMPLETE */
    uint32 event_tx_complete    :1;
    /* Signal receive character timeout event: \ref TT_USART_EVENT_RX_TIMEOUT */
    uint32 event_rx_timeout     :1;
    /* RTS Line: 0=not available, 1=available */
    uint32 rts                  :1;
    /* CTS Line: 0=not available, 1=available */
    uint32 cts                  :1;
    /* DTR Line: 0=not available, 1=available */
    uint32 dtr                  :1;
    /* DSR Line: 0=not available, 1=available */
    uint32 dsr                  :1;
    /* DCD Line: 0=not available, 1=available */
    uint32 dcd                  :1;
    /* RI Line: 0=not available, 1=available */
    uint32 ri                   :1;
    /* Signal CTS change event: \ref TT_USART_EVENT_CTS */
    uint32 event_cts            :1;
    /* Signal DSR change event: \ref TT_USART_EVENT_DSR */
    uint32 event_dsr            :1;
    /* Signal DCD change event: \ref TT_USART_EVENT_DCD */
    uint32 event_dcd            :1;
    /* Signal RI change event: \ref TT_USART_EVENT_RI */
    uint32 event_ri             :1;
    /* Reserved (must be zero) */
    uint32 reserved             :11;
} Uart_Capabilities;

/**
 \brief UART Transfer Information (Run-Time)
 */
typedef struct _Uart_TransferInfo
{
    /* Total number of data to be received */
    uint32          rx_num;
    /* Total number of data to be send */
    uint32          tx_num;
    /* Pointer to in data buffer */
    uint8*          rx_buf;
    /* Pointer to out data buffer */
    uint8*          tx_buf;
    /* Number of data received */
    volatile uint32 rx_cnt;
    /* Number of data sent */
    volatile uint32 tx_cnt;
    /* Transmit default value (used in USART_SYNC_MASTER_MODE_RX) */
    uint8           tx_def_val;
    /* Receive dump value (used in USART_SYNC_MASTER_MODE_TX) */
    uint8           rx_dump_val;
    /* Send active flag */
    volatile uint8  send_active;
    /* Synchronous mode */
    volatile uint8  sync_mode;
} Uart_TransferInfo;

/**
 \brief _Uart_RxStatus
 */
typedef struct _Uart_RxStatus
{
    /* Receiver busy flag */
    uint32   rx_busy           :1;
    /* Receive data overflow detected (cleared on start of next receive operation) */
    uint32   rx_overflow       :1;
    /* Break detected on receive (cleared on start of next receive operation) */
    uint32   rx_break          :1;
    /* Framing error detected on receive (cleared on start of next receive operation) */
    uint32   rx_framing_error  :1;
    /* Parity error detected on receive (cleared on start of next receive operation) */
    uint32   rx_parity_error   :1;

} Uart_RxStatus;

/**
 \brief UART Information (Run-Time)
 */
typedef struct _Uart_Info
{
    /* Event callback */
    TT_USART_SignalEvent_t      cb_event;
    /* Receive status flags */
    Uart_RxStatus               rx_status;
    /* Transfer information */
    Uart_TransferInfo           xfer;
    /* USART driver flags */
    Uart_StatusType             flags;
    /* Baudrate */
    uint32                      baudrate;
} Uart_Info;
/**
 \brief UART data bits
 */
typedef enum
{
    UART_DATA_BITS_5,
    UART_DATA_BITS_6,
    UART_DATA_BITS_7,
    UART_DATA_BITS_8
} Uart_NumCharFrameType;

/**
 \brief UART stop bits
 */
typedef enum
{
    UART_STOP_BITS_1,
    UART_STOP_BITS_2
} Uart_NumStopBitsType;

/**
 \brief Enum for parity checking
 */
typedef enum
{
    UART_PARITY_NO,
    UART_PARITY_EVEN,
    UART_PARITY_ODD
} Uart_ParityType;
/**
 \brief USART  Channel Modem Control
 */
typedef enum
{
    UART_CHANNEL,
    LIN_UART_CHANNEL
} Uart_ChannelMode;

/**
 \brief USART  Work Modem Control
 */
typedef enum _TT_USART_WORK_MODE
{
    /* work in poll */
    TT_USART_WORK_POLL,
    /* work in irq */
    TT_USART_WORK_IRQ,
    /* work in dma */
    TT_USART_WORK_DMA
} Uart_WorkMod;
/**
 \brief Threshold setting
 */
typedef enum
{
    UART_FIFO_ON_ONE_EIGHT_LEVEL,
    UART_FIFO_ON_ONE_FOUR_LEVEL,
    UART_FIFO_ON_ONE_TWO_LEVEL,
    UART_FIFO_ON_THREE_FOURE_LEVEL,
    UART_FIFO_ON_SEVEN_EIGHT_LEVEL
} Uart_FifoThreshold;
#if (UART_DMA_ENABLE == STD_ON)
/**
 \brief DMA configuration of the Uart
 */
typedef struct _Uart_DmaType {
/*  boolean UartDmaModeEnable; */
  uint32 UartDmaConfigId;
  /* DMA Event callback */
  TT_USART_SignalEvent_t cb_event;
} Uart_DmaType;
#endif


/**
 \brief UART Resources definitions
 */
typedef struct
{
    /* Capabilities */
    Uart_Capabilities       capabilities;
    Uart_RegType*           reg;
    Uart_WorkMod            work_mode;
    /* USART clocks frequency */
    uint32                  base_clk;
#if (UART_DMA_ENABLE == STD_ON)
    Uart_DmaType*           dma_tx;
    Uart_DmaType*           dma_rx;
#endif
    Uart_Info*             info;
} Uart_ResourcesType;

/**
 \Enum for standard baudrates
 */
typedef uint32 Uart_BaudrateType;



/**
 \Enum for Uart or Lin Hardware ID
 */
typedef enum
{
    UART_0,
    UART_1,
    UART_2,
    UART_3,
    LINU_0,
    LINU_1,
    LINU_2,
    LINU_3,
    LINU_4,
    LINU_5,
    LINU_6,
    LINU_7,
    LINU_8,
    LINU_9,
    LINU_10,
    LINU_11,
    LINU_12,
    LINU_13,
    LINU_14,
    LINU_15,
} Uart_LinuHardType;

/**
 \Structure for Uart Packet config type
 */
typedef struct
{
    Uart_LinuHardType HwUnit;
    Uart_ChannelMode ChannelMode;
    Uart_WorkMod WorkMode;
    /* data bits*/
    uint8 NumCharFrame;
    /* Stop bits*/
    uint8 NumStopBits;
    /* Check type*/
    uint8 ParityType;
    /* Flow control type*/
    boolean RtsCtsFlowCtrl;
    boolean TxTrigger;
    boolean RxTrigger;
    /* Transmission trigger mask */
    Uart_FifoThreshold TxFifoLevel;
    /* Receive trigger mask */
    Uart_FifoThreshold RxFifoLevel;
#if (LIN_UART_OVERSAMPLERATE == STD_ON)
    uint8 LinOverSampleRate;
    uint8 LinSamplePoint;
#endif
    Uart_BaudrateType Baudrate;
#if (UART_DMA_ENABLE == STD_ON)
    uint32 UartRxDmaConfigId;
    uint32 UartTxDmaConfigId;
#endif
    /* Event callback */
    TT_USART_SignalEvent_t cb_event;
} Uart_CtrlConfigType;

/**
 \Cofiguration Structure for UART
 */
typedef struct
{
    TT_CONST Uart_CtrlConfigType* CtrlCfgPtr;
} Uart_ConfigType;

extern TT_CONST Uart_ConfigType UartConfigData;

#ifdef __cplusplus
}
#endif

#endif
