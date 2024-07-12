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
**  FILENAME     : Linu_Hw_Types.h                                                  **
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
*                           History                                                 **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifndef LINU_HW_TYPES_H
#define LINU_HW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                            Includes
 ******************************************************************************/
#include "Uart_Hw_Types.h"
/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define LINU_HW_TYPES_VENDOR_ID_H                     1541
#define LINU_HW_TYPES_MODULE_ID_H                     227
#define LINU_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define LINU_HW_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define LINU_HW_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define LINU_HW_TYPES_SW_MAJOR_VERSION_H              1
#define LINU_HW_TYPES_SW_MINOR_VERSION_H              1
#define LINU_HW_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Linu_Hw_Types.h and Uart_Hw_Types.h file version check */
#if (LINU_HW_TYPES_VENDOR_ID_H != UART_HW_TYPES_VENDOR_ID_H)
    #error "Linu_Hw_Types.h and Uart_Hw_Types.h have different vendor ids"
#endif
#if (LINU_HW_TYPES_MODULE_ID_H != UART_HW_TYPES_MODULE_ID_H)
    #error "Linu_Hw.h and Uart_Hw_Types.h have different module ids"
#endif
#if ((LINU_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != UART_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (LINU_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != UART_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (LINU_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != UART_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Linu_Hw_Types.h and Uart_Hw_Types.h are different"
#endif
#if ((LINU_HW_TYPES_SW_MAJOR_VERSION_H != UART_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (LINU_HW_TYPES_SW_MINOR_VERSION_H != UART_HW_TYPES_SW_MINOR_VERSION_H) || \
     (LINU_HW_TYPES_SW_PATCH_VERSION_H != UART_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Linu_Hw_Types.h and Uart_Hw_Types.h are different"
#endif

/******************************************************************************
 *                            Defines And Macros
 *******************************************************************************/
#if (LIN_UART_ENABLE == STD_ON)

#define UART_ERROR_ALL_INT          (0xC180U)
#define UART_ALL_ERROR_FLAG         (0xFD89U)

/******************************************************************************
 *                            Enums
 *******************************************************************************/
/**
 \data bits
 */
typedef enum
{
    LIN_UART_SEVEN_BITS,
    LIN_UART_EIGHT_BITS,
    LIN_UART_FIFTEEN_BITS,
    LIN_UART_SIXTEEN_BITS
} Linu_FrameBitType;
/**
 \stop bits
 */
typedef enum
{
    LIN_UART_ONE_STOPBIT,
    LIN_UART_TWO_STOPBITS,
    LIN_UART_THREE_STOPBITS
} Linu_StopType;

/**
 \Check type selection
 */
typedef enum
{
    LIN_UART_EVEN_PARITY,
    LIN_UART_ODD_PARITY,
    LIN_UART_ZERO_PARITY,
    LIN_UART_ONE_PARITY,
    LIN_UART_NO_PARITY
} Linu_ParityType;
/**
 \Sample point
 */
typedef enum
{
    LIN_UART_SAMPLE_POINT_2,
    LIN_UART_SAMPLE_POINT_3,
    LIN_UART_SAMPLE_POINT_4,
    LIN_UART_SAMPLE_POINT_5,
    LIN_UART_SAMPLE_POINT_0
} Linu_SamplePointType;
/**
 \ Over Sample rate
 */
typedef enum
{
    LIN_UART_OVERSAMPLE_RATE_4,
    LIN_UART_OVERSAMPLE_RATE_5,
    LIN_UART_OVERSAMPLE_RATE_6,
    LIN_UART_OVERSAMPLE_RATE_8
} Linu_OversampleRateType;
/******************************************************************************
 *                            Structures And Typedefs
 *******************************************************************************/
/**
 \ Transfer Information
 */
typedef struct _Linu_TransferInfoType
{
    /* Total number of transfers */
    uint32      tx_num;
    /* Total number of receive */
    uint32      rx_num;
    /* Pointer to in data buffer */
    uint8*      rx_buf;
    /* Pointer to out data buffer */
    uint8*      tx_buf;
    /* Number of data received only use in UART */
    uint32      rx_cnt;
    /* Number of data sent only use in UART */
    uint32      tx_cnt;
    /* Default transfer value */
    uint32      def_val;
} Linu_TransferInfoType;

/**
 \ Status Information
 */
typedef struct _Linu_StatusType
{
    /* Transfers busy flag */
    uint8 tx_busy;
    /* Receiver busy flag */
    uint8 rx_busy;
    /* Framing error detected on receive (cleared on start of next receive operation) */
    uint8 rx_framing_error;
    /* Parity error detected on receive (cleared on start of next receive operation) */
    uint8 rx_parity_error;
    /* stuck at zero flag */
    uint8 rx_szf;
    /* noise flag */
    uint8 rx_nf;
    /* timeout flag */
    uint8 rx_timeout;
    uint8 buffer_overrun;
    uint8 oc_error;
} Linu_StatusType;
/**
 \ Tatol Information
 */
typedef struct _Linu_InfoType
{
    /* Event Callback */
    TT_USART_SignalEvent_t      cb_event;
    /* transfer information */
    Linu_TransferInfoType       xfer;
    Linu_StatusType             status;
    /* LIN driver flags */
    Uart_StatusType             flags;
    /* Baudrate */
    uint32                      baudrate;
    /* data length */
    uint8                       LenType;
} Linu_InfoType;
/**
 \ DMA channel Information
 */
#if (UART_DMA_ENABLE == STD_ON)
typedef struct _Linu_DmaType
{
    uint32 LinDmaConfigId;
    TT_USART_SignalEvent_t cb_event;      /* DMA Event callback */
} Linu_DmaType;
#endif
/**
 \ Run hardware resource information
 */
typedef struct 
{
    TT_LIN_Type*           reg;
    Uart_WorkMod           work_mode;
    uint32                 base_clk;    /* USART clocks frequency */
#if (UART_DMA_ENABLE == STD_ON)
    Linu_DmaType*          dma_tx;
    Linu_DmaType*          dma_rx;
#endif
    Linu_InfoType*         info;
} Linu_Resources;

#endif

#endif

#ifdef __cplusplus
}
#endif
