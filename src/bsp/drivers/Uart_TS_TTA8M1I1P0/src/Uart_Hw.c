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
**  FILENAME     : Uart_Hw.c                                                        **
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
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                            Includes
 ******************************************************************************/
#include "Uart_Hw.h"
#include "Base_Drv.h"
#include "Mcu_Drv.h"

#if (UART_DMA_ENABLE == STD_ON)
#include "Dma_Drv.h"
#endif
/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define UART_HW_VENDOR_ID_C                     1541
#define UART_HW_MODULE_ID_C                     227
#define UART_HW_AR_RELEASE_MAJOR_VERSION_C      4
#define UART_HW_AR_RELEASE_MINOR_VERSION_C      4
#define UART_HW_AR_RELEASE_PATCH_VERSION_C      0
#define UART_HW_SW_MAJOR_VERSION_C              1
#define UART_HW_SW_MINOR_VERSION_C              1
#define UART_HW_SW_PATCH_VERSION_C              0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Uart_Hw.c and Uart_Hw.h file version check */
#if (UART_HW_VENDOR_ID_C != UART_HW_VENDOR_ID_H)
    #error "Uart_Hw.c and Uart_Hw.h have different vendor ids"
#endif
#if (UART_HW_MODULE_ID_C != UART_HW_MODULE_ID_H)
    #error "Uart_Hw.c and Uart_Hw.h have different module ids"
#endif
#if ((UART_HW_AR_RELEASE_MAJOR_VERSION_C != UART_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HW_AR_RELEASE_MINOR_VERSION_C != UART_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HW_AR_RELEASE_PATCH_VERSION_C != UART_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hw.c and Uart_Hw.h are different"
#endif
#if ((UART_HW_SW_MAJOR_VERSION_C != UART_HW_SW_MAJOR_VERSION_H) || \
     (UART_HW_SW_MINOR_VERSION_C != UART_HW_SW_MINOR_VERSION_H) || \
     (UART_HW_SW_PATCH_VERSION_C != UART_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hw.c and Uart_Hw.h are different"
#endif

/* Uart_Hw.c and Mcu_Drv.h file version check */
#if (UART_HW_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Uart_Hw.c and Mcu_Drv.h have different vendor ids"
#endif
#if ((UART_HW_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HW_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HW_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hw.c and Mcu_Drv.h are different"
#endif
#if ((UART_HW_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (UART_HW_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (UART_HW_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hw.c and Mcu_Drv.h are different"
#endif

/* Uart_Hw.c and Base_Drv.h file version check */
#if (UART_HW_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
    #error "Uart_Hw.c and Base_Drv.h have different vendor ids"
#endif
#if ((UART_HW_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (UART_HW_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (UART_HW_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Uart_Hw.c and Base_Drv.h are different"
#endif
#if ((UART_HW_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (UART_HW_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
     (UART_HW_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Uart_Hw.c and Base_Drv.h are different"
#endif
#if (UART_DMA_ENABLE == STD_ON)
    /* Uart_Hw.c and Dma_Drv.h file version check */
    #if (UART_HW_VENDOR_ID_C != DMA_DRV_VENDOR_ID_H)
        #error "Uart_Hw.c and Dma_Drv.h have different vendor ids"
    #endif
    #if ((UART_HW_AR_RELEASE_MAJOR_VERSION_C != DMA_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
         (UART_HW_AR_RELEASE_MINOR_VERSION_C != DMA_DRV_AR_RELEASE_MINOR_VERSION_H) || \
         (UART_HW_AR_RELEASE_PATCH_VERSION_C != DMA_DRV_AR_RELEASE_PATCH_VERSION_H))
        #error "AutoSar Version Numbers of Uart_Hw.c and Dma_Drv.h are different"
    #endif
    #if ((UART_HW_SW_MAJOR_VERSION_C != DMA_DRV_SW_MAJOR_VERSION_H) || \
         (UART_HW_SW_MINOR_VERSION_C != DMA_DRV_SW_MINOR_VERSION_H) || \
         (UART_HW_SW_PATCH_VERSION_C != DMA_DRV_SW_PATCH_VERSION_H))
        #error "Software Version Numbers of Uart_Hw.c and Dma_Drv.h are different"
    #endif
#endif
/******************************************************************************
 *                            Private Typedefs
 *******************************************************************************/

/******************************************************************************
 *                            Private Macros
 *******************************************************************************/

/******************************************************************************
 *                            Private Constants
 *******************************************************************************/

/******************************************************************************
 *                            Private Variables
 *******************************************************************************/

/******************************************************************************
 *                            Public Constants
 *******************************************************************************/

/******************************************************************************
 *                            Public Variables
 *******************************************************************************/

/******************************************************************************
*                    Private Function Declaration
******************************************************************************/
/**
 * @brief      :  Receive line interrupt handler
 * @details    :  Receive line interrupt handler
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  Rx Line event mask
 *
 **/
static uint32 Uart_Hw_PriRxLineIntHandler(TT_CONST uint8 HwUnit);
#if defined(UART0_IRQ_ENABLE) || defined(UART1_IRQ_ENABLE) || defined(UART2_IRQ_ENABLE) || defined(UART3_IRQ_ENABLE)
/**
 * @brief      :  USART Combine Interrupt handler for transmit.
 * @details    :  USART Combine Interrupt handler for transmit.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  event - Get the result of sending interrupt running
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriIrqHandlerTx(TT_CONST uint8 HwUnit,uint32* event);
/**
 * @brief      :  USART Combine Interrupt handler for Receive.
 * @details    :  USART Combine Interrupt handler for Receive.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  event - Get the result of receive interrupt running
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriIrqHandlerRx(TT_CONST uint8 HwUnit,uint32* event);
/**
 * @brief      :  USART Combine Interrupt handler for Receive and Transmit.
 * @details    :  USART Combine Interrupt handler for Receive and Transmit.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriIrqHandler(TT_CONST uint8 HwUnit);
#endif /* define(UART0_IRQ_ENABLE)||define(UART1_IRQ_ENABLE)||define(UART2_IRQ_ENABLE)||define(UART3_IRQ_ENABLE)*/
/**
 * @brief      :  Set Uart several data bits
 * @details    :  Set Uart several data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumCharFrame  - Data bit pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetdata(uint8 HwUnit,uint8 NumCharFrame);
/**
 * @brief      :  Set Uart several TX FIFO
 * @details    :  Set Uart several TX FIFO
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Tx_Fifo  - TX Depth of FIFO
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSettxfifo(uint8 HwUnit,uint8 Tx_Fifo);

/**
 * @brief      :  Set Uart several RX FIFO
 * @details    :  Set Uart several RX FIFO
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Rx_Fifo  - RX Depth of FIFO
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetrxfifo(uint8 HwUnit,uint8 Rx_Fifo);

/**
 * @brief      :  Set Uart Parity pattern
 * @details    :  Set Uart Parity pattern
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                ParityType  - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetParity(uint8 HwUnit,uint8 ParityType);

/**
 * @brief      :  Set Uart Stop bits
 * @details    :  Set Uart Stop bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumStopBits  - Stop bits
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetstopbits(uint8 HwUnit,uint8 NumStopBits);

/**
 * @brief      :  Map Uart_PubMap to Uart_Hw_PbResources
 * @details    :  The subscript of the Uart_PubMap array indicates the corresponding Uart0 to Uart3,
 *                and the member value of the Uart_PubMap array is the array subscript of Uart_Hw_PbResources.
 *                Uart_Hw_PbResources[Uart_PubMap[Uart_0]] Indirectly accesses hardware resources corresponding to the serial port
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Map command accepted
 *             :  Other: Map command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriMapsort(TT_CONST Uart_ConfigType *CfgPtr);

/**
 * @brief      :  Get clock frequency
 * @details    :  Get clock frequency
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  UartSysClk - Memory clock frequency
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriGetClk(uint8 HwUnit,uint32* UartSysClk);

/**
 * @brief      :  Start the clock to obtain the clock frequency
 * @details    :  Start the clock to obtain the clock frequency
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  UartSysClk - Memory clock frequency
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriClk(uint8 HwUnit,uint32* UartSysClk);

/**
 * @brief      :  Example Set the Uart mode
 * @details    :  Example Set the Uart mode
 *
 * @param[in]  :  flag - CfgPtr->CtrlCfgPtr array subscript
 *                HwUnit - Module ID of the Hardware unit to transmit
 *                CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetMode(uint8 flag ,uint8 HwUnit,TT_CONST Uart_ConfigType *CfgPtr);
#if defined(UART0_DMA_ENABLE) || defined(UART1_DMA_ENABLE) || defined(UART2_DMA_ENABLE) || defined(UART3_DMA_ENABLE)
/**
* @brief      : UART DMA Interrupt handler.
* @details    : UART DMA Interrupt handler.
*
* @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
*               event - DMA_EVENT_TERMINAL_COUNT_REQUEST / DMA_EVENT_ERROR
* @param[out] : None
*
* @return     : void
* @retval     : None
*
**/
static void Uart_Hw_PriTxDmaEvent (TT_CONST uint8 HwUnit, uint32 event);
/**
* @brief      : UART DMA Interrupt handler.
* @details    : UART DMA Interrupt handler.
*
* @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
*               event - DMA_EVENT_TERMINAL_COUNT_REQUEST / DMA_EVENT_ERROR
* @param[out] : None
*
* @return     : void
* @retval     : None
*
**/
static void Uart_Hw_PriRxDmaEvent (TT_CONST uint8 HwUnit, uint32 event);
#endif
/**
* @brief      :  Uart IRQ Transmit
* @details    :  Uart IRQ Transmit
*
* @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
* @param[out] :  None
*
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Transmit command accepted
*             :  Other: Transmit command not accepted
*
**/
static void Uart_Hw_PriAsyncTransmit(TT_CONST uint8 HwUnit);
/**
* @brief      :  Uart IRQ Receive
* @details    :  Uart IRQ Receive
*
* @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
* @param[out] :  None
*
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Receive command accepted
*             :  Other: Receive command not accepted
*
**/
static void Uart_Hw_PriAsyncReceive(TT_CONST uint8 HwUnit);
#ifdef UART0_DMA_ENABLE
/**
 * @brief      :  Gets the sending DMA run result function
 * @details    :  Gets the sending DMA run result function
 *
 * @param[in]  :  event - DMA run result event
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriDmaTx0(uint32 event);
/**
 * @brief      :  Gets the Receive DMA run result function
 * @details    :  Gets the Receive DMA run result function
 *
 * @param[in]  :  event - DMA run result event
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriDmaRx0(uint32 event);
#endif

#ifdef UART1_DMA_ENABLE
    static void Uart_Hw_PriDmaTx1 (uint32 event);
    static void Uart_Hw_PriDmaRx1 (uint32 event);
#endif
#ifdef UART2_DMA_ENABLE
    static void Uart_Hw_PriDmaTx2 (uint32 event);
    static void Uart_Hw_PriDmaRx2 (uint32 event);
#endif

#ifdef UART3_DMA_ENABLE
    static void Uart_Hw_PriDmaTx3 (uint32 event);
    static void Uart_Hw_PriDmaRx3 (uint32 event);
#endif

/******************************************************************************
*                      Global variable  Definitions
******************************************************************************/
#define UART_START_SEC_VAR_FAST_INIT_8
#include "Uart_MemMap.h"
/**
* @brief      :  Uart_PubMap serves Uart_Hw_PbResources
* @details       Array subscripts correspond to Uart0 to Uart3.
*                Array members in Uart_PubMap are used to map Uart
*                hardware resources in Uart_Hw_PbResources
*
*/

uint8 Uart_PubMap[UART_CONTROLLER_COUNT] = {0xFF,0xFF,0xFF,0xFF};

#define UART_STOP_SEC_VAR_FAST_INIT_8
#include "Uart_MemMap.h"

#define UART_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"
#ifdef UART0_CONFIGED
    /*Uart0 Information (Run-Time)*/
    static Uart_Info Uart0_Info = {
                                  .cb_event  = NULL_PTR,
                                  .rx_status = {0, 0, 0, 0, 0},
                                  .xfer      = {0, 0, NULL_PTR, NULL_PTR, 0, 0, 0, 0, 0, 0},
                                  .flags     = UART_STATUS_UNINIT,
                                  .baudrate  = 0
                                  };
#endif

#ifdef UART1_CONFIGED
    static Uart_Info Uart1_Info = {
                                    .cb_event  = NULL_PTR,
                                    .rx_status = {0, 0, 0, 0, 0},
                                    .xfer      = {0, 0, NULL_PTR, NULL_PTR, 0, 0, 0, 0, 0, 0},
                                    .flags     = UART_STATUS_UNINIT,
                                    .baudrate  = 0
                                  };
#endif

#ifdef UART2_CONFIGED
    static Uart_Info Uart2_Info = {
                                    .cb_event  = NULL_PTR,
                                    .rx_status = {0, 0, 0, 0, 0},
                                    .xfer      = {0, 0, NULL_PTR, NULL_PTR, 0, 0, 0, 0, 0, 0},
                                    .flags     = UART_STATUS_UNINIT,
                                    .baudrate  = 0
                                  };
#endif

#ifdef UART3_CONFIGED
    static Uart_Info Uart3_Info = {
                                    .cb_event  = NULL_PTR,
                                    .rx_status = {0, 0, 0, 0, 0},
                                    .xfer      = {0, 0, NULL_PTR, NULL_PTR, 0, 0, 0, 0, 0, 0},
                                    .flags     = UART_STATUS_UNINIT,
                                    .baudrate  = 0
                                  };
#endif
#define UART_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

#define UART_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Uart_MemMap.h"

#ifdef UART0_DMA_ENABLE
    /* DMA configuration of the Uart Tx */
    static Uart_DmaType Uart0_DmaTx = {
                                        .UartDmaConfigId = 0,
                                        .cb_event        = Uart_Hw_PriDmaTx0
                                      };
    /* DMA configuration of the Uart Rx */
    static Uart_DmaType Uart0_DmaRx = {0,
                                      Uart_Hw_PriDmaRx0};
#endif

#ifdef UART1_DMA_ENABLE
    static Uart_DmaType Uart1_DmaTx = {
                                        .UartDmaConfigId = 0,
                                        .cb_event        = Uart_Hw_PriDmaTx1
                                      };
    static Uart_DmaType Uart1_DmaRx = {
                                        .UartDmaConfigId = 0,
                                        .cb_event        = Uart_Hw_PriDmaRx1
                                      };
#endif

#ifdef UART2_DMA_ENABLE
    static Uart_DmaType Uart2_DmaTx = {
                                        .UartDmaConfigId = 0,
                                        .cb_event        = Uart_Hw_PriDmaTx2
                                      };
    static Uart_DmaType Uart2_DmaRx = {
                                        .UartDmaConfigId = 0,
                                        .cb_event        = Uart_Hw_PriDmaRx2
                                      };
#endif

#ifdef UART3_DMA_ENABLE
    static Uart_DmaType Uart3_DmaTx = {
                                        .UartDmaConfigId = 0,
                                        .cb_event        = Uart_Hw_PriDmaTx3
                                      };
    static Uart_DmaType Uart3_DmaRx = {
                                        .UartDmaConfigId = 0,
                                        .cb_event        = Uart_Hw_PriDmaRx3
                                      };
#endif

/* Resources during Uart running */
Uart_ResourcesType Uart_Hw_PbResources[UART_CONFIGED_COUNT] =
{
#ifdef UART0_CONFIGED
    {
        .capabilities = {
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        },
        /* UART register base */
        .reg = IP_UART0,
        /* default mode */
        .work_mode    = TT_USART_WORK_POLL,
        /* USART clocks frequency */
        .base_clk     = 0,
#if (UART_DMA_ENABLE == STD_ON)
#ifdef UART0_DMA_ENABLE
        /* Tx DMA config */
        .dma_tx       = &Uart0_DmaTx,
        /* Rx DMA config */
        .dma_rx       = &Uart0_DmaRx,
#else
        .dma_tx       = NULL_PTR,
        .dma_rx       = NULL_PTR,
#endif
#endif
        /* Run-Time Information */
        .info         = &Uart0_Info
    }
#endif
#ifdef UART1_CONFIGED
#if defined(UART0_CONFIGED)
,
#endif
    {
        .capabilities = {
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        },
        .reg = IP_UART1,
        .work_mode    = TT_USART_WORK_POLL,
        .base_clk     = 0,
#if (UART_DMA_ENABLE == STD_ON)
#ifdef UART1_DMA_ENABLE
        .dma_tx       = &Uart1_DmaTx,
        .dma_rx       = &Uart1_DmaRx,
#else
        .dma_tx       = NULL_PTR,
        .dma_rx       = NULL_PTR,
#endif
#endif
        .info         = &Uart1_Info
    }
#endif
#ifdef UART2_CONFIGED
#if defined(UART0_CONFIGED) || defined(UART1_CONFIGED)
,
#endif
    {
        .capabilities = {
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        },
        .reg = IP_UART2,
        .work_mode    = TT_USART_WORK_POLL,
        .base_clk     = 0,
#if (UART_DMA_ENABLE == STD_ON)
#ifdef UART2_DMA_ENABLE
        .dma_tx       = &Uart2_DmaTx,
        .dma_rx       = &Uart2_DmaRx,
#else
        .dma_tx       = NULL_PTR,
        .dma_rx       = NULL_PTR,
#endif
#endif
        .info         = &Uart2_Info
    }
#endif
#ifdef UART3_CONFIGED
#if defined(UART0_CONFIGED) || defined(UART1_CONFIGED) ||  defined(UART2_CONFIGED)
,
#endif
    {
        .capabilities = {
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        },
        .reg = IP_UART3,
        .work_mode    = TT_USART_WORK_POLL,
        .base_clk     = 0,
#if (UART_DMA_ENABLE == STD_ON)
#ifdef UART3_DMA_ENABLE
        .dma_tx       = &Uart3_DmaTx,
        .dma_rx       = &Uart3_DmaRx,
#else
        .dma_tx       = NULL_PTR,
        .dma_rx       = NULL_PTR,
#endif
#endif
        .info         = &Uart3_Info
    },
#endif
};

#define UART_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Uart_MemMap.h"

/******************************************************************************
 *                         Public Functions
 ******************************************************************************/
#define UART_START_SEC_CODE_SLOW
#include "Uart_MemMap.h"
/**
 * @brief      :  Service for initialization of UART
 * @details    :  Select serial uart initialization mode
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: The initialization is complete
 *             :  Other: Initialization is not complete
 *
 **/
TT_RetType Uart_Hw_Init(TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 HwUnit = 0, i = 0;
    Mcu_PeripheralClockValType UartSysClk = 0;

    Ret = Uart_Hw_PriMapsort(CfgPtr);

    if (TT_RET_SUCCESS == Ret)
    {
        for (i = 0; i < UART_CONFIGED_COUNT; i++)
        {
            HwUnit = (uint8)CfgPtr->CtrlCfgPtr[i].HwUnit;
            /* Get UART System Clock */
            Ret = Uart_Hw_PriClk(HwUnit,&UartSysClk);

            if (TT_RET_SUCCESS == Ret)
            {
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].base_clk = UartSysClk;
                /* Initialize USART Run-time Resources */
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event = CfgPtr->CtrlCfgPtr[i].cb_event;
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].work_mode = CfgPtr->CtrlCfgPtr[i].WorkMode;

        #if (UART_DMA_ENABLE == STD_ON)
                if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_tx != NULL_PTR)
                {
                    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_tx->UartDmaConfigId = CfgPtr->CtrlCfgPtr[i].UartTxDmaConfigId;
                }
                else
                {
                    /* do nothing */
                }

                if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_rx != NULL_PTR)
                {
                    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_rx->UartDmaConfigId = CfgPtr->CtrlCfgPtr[i].UartRxDmaConfigId;
                }
                else
                {
                    /* do nothing */
                }
        #endif


                /* Clear RTS/CTS and Enable the UART */
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->CR &= ~(TT_UART0_CR_RTSEN_Msk | TT_UART0_CR_CTSEN_Msk);
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->CR |= TT_UART0_CR_UARTEN_Msk |
                                                             TT_UART0_CR_TXE_Msk |
                                                             TT_UART0_CR_RXE_Msk;

                /* Enable interrupt other than TX/RX */
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IMSC |= TT_UART0_IMSC_OEIM_Msk |
                                                               TT_UART0_IMSC_BEIM_Msk |
                                                               TT_UART0_IMSC_PEIM_Msk |
                                                               TT_UART0_IMSC_FEIM_Msk |
                                                               TT_UART0_IMSC_DSRMIM_Msk;

                Ret = Uart_Hw_PriSetMode(i,HwUnit,CfgPtr);
                if( TT_RET_SUCCESS == Ret)
                {
                    /* Set configured flag */
                    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
                }
                else
                {
                    break;
                }

            }
            else
            {
                break;
            }
        }
    }
    else
    {
        /* do nothing */
    }
    
    return Ret;
}

#if (TT_SAFETY == STD_ON)
/**
 * @brief      :  Serves initial security checks
 * @details    :  Serves initial security checks
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: The initialization is complete
 *             :  Other: Initialization is not complete
 *
 **/
TT_RetType Uart_Hw_InitCheck(TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 HwUnit = 0, i = 0;
    uint32 Lcr_Eps = 0 , Lcr_Pen = 0 ,Lcr_Stop2 = 0;
    for (i = 0; i < UART_CONFIGED_COUNT; i++)
    {
        HwUnit = (uint8)CfgPtr->CtrlCfgPtr[i].HwUnit;
        if((Uart_PubMap[HwUnit] != 0xFFU) && (Ret == TT_RET_SUCCESS))
        {
        	Lcr_Eps = (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H & TT_UART0_LCR_H_EPS_Msk);
			Lcr_Pen = (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H & TT_UART0_LCR_H_PEN_Msk);
			Lcr_Stop2 = (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H & TT_UART0_LCR_H_STP2_Msk);

        	if((CfgPtr->CtrlCfgPtr[i].ParityType == (uint8)UART_PARITY_NO) && (Lcr_Eps != 0 || Lcr_Pen != 0))
        	{
        		Ret = TT_RET_STATUS_ERR;
        	}
        	else
        	{
        		/* do nothing */
        	}

        	if((CfgPtr->CtrlCfgPtr[i].ParityType == (uint8)UART_PARITY_EVEN) && (Lcr_Eps == 0 || Lcr_Pen == 0))
		    {
        		Ret = TT_RET_STATUS_ERR;
		    }
        	else
        	{
        		/* do nothing */
        	}

        	if((CfgPtr->CtrlCfgPtr[i].ParityType == (uint8)UART_PARITY_ODD) && (Lcr_Eps == 0 || Lcr_Pen != 0))

		    {
        		Ret = TT_RET_STATUS_ERR;
		    }
        	else
        	{
        		/* do nothing */
        	}

            if(Ret == TT_RET_SUCCESS)
            {

            	if((CfgPtr->CtrlCfgPtr[i].NumStopBits == (uint8)UART_STOP_BITS_1) && (Lcr_Stop2 != 0))
            	{
            		Ret = TT_RET_STATUS_ERR;
            	}
            	else
            	{
            		/* do noting */
            	}
            	if((CfgPtr->CtrlCfgPtr[i].NumStopBits == (uint8)UART_STOP_BITS_2) && (Lcr_Stop2 == 0))
            	{
            		Ret = TT_RET_STATUS_ERR;
            	}
            	else
            	{
            		/* do nothing */
            	}
            }
            else
            {
                Ret = TT_RET_STATUS_INIT_ERR;
                break;
            }
        }
        else
        {
            Ret = TT_RET_STATUS_INIT_ERR;
            break;
        }
    }

    return Ret;
}
#endif

/**
 * @brief      :  Service for Deinitialization of UART
 * @details    :  Select serial uart De-initialization mode
 *
 * @param[in]  :  None
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: De-initialization command accepted
 *             :  Other: De-initialization command has not been accepted
 *
 **/
TT_RetType Uart_Hw_DeInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 i = 0;
    
    for (i = 0; i < UART_CONTROLLER_COUNT; i++)
    {
        if(0xFFU != Uart_PubMap[i])
        {
            /* Whether the serial port is hardware initialized */
            if(Uart_Hw_PbResources[Uart_PubMap[i]].info->flags == UART_STATUS_IDLE)
            {
                /* Reset USART status flags */
                Uart_Hw_PbResources[Uart_PubMap[i]].info->flags = UART_STATUS_UNINIT;
                Uart_Hw_PbResources[Uart_PubMap[i]].info->rx_status.rx_busy = 0U;
                Uart_Hw_PbResources[Uart_PubMap[i]].info->rx_status.rx_overflow = 0U;
                Uart_Hw_PbResources[Uart_PubMap[i]].info->rx_status.rx_break = 0U;
                Uart_Hw_PbResources[Uart_PubMap[i]].info->rx_status.rx_framing_error = 0U;
                Uart_Hw_PbResources[Uart_PubMap[i]].info->rx_status.rx_parity_error = 0U;
                Uart_Hw_PbResources[Uart_PubMap[i]].info->xfer.send_active = 0U;
                Uart_Hw_PbResources[Uart_PubMap[i]].info->xfer.tx_def_val = 0U;
                Uart_PubMap[i] = 0xFFU;
                switch (i)
                {
                    case (uint8)UART_0:
                        (void)Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_UART0);
                        (void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_UART0);
                        break;
                    case (uint8)UART_1:
                        (void)Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_UART1);
                        (void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_UART1);
                        break;
                    case (uint8)UART_2:
                        (void)Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_UART2);
                        (void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_UART2);
                        break;
                    default:
                        (void)Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_UART3);
                        (void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_UART3);
                        break;
                }
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
                break;
            }
        }
        else
        {
            /* do nothing */
        }
    }

    return Ret;
}
#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE_FAST
#include "Uart_MemMap.h"
/**
 * @brief      :  Service for UART SyncTransmission
 * @details    :  Service for UART SyncTransmission
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  Other: Transmit command not accepted
 *
 **/
TT_RetType Uart_Hw_SyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    Ret = Base_Drv_Timer_MicrosToTicks(UART_TIMEOUT_DURATION, &uS2Ticks);
#endif

    TT_ParaCheck(((HwUnit >= UART_CONTROLLER_COUNT)||(Uart_PubMap[HwUnit] >= UART_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((TxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info == NULL_PTR), TT_RET_PARAM_ERR, &Ret);


    if (TT_RET_SUCCESS == Ret)
    {
        TT_ParaCheck((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags == UART_STATUS_UNINIT), TT_RET_STATUS_UNINIT_ERR, &Ret);
        TT_ParaCheck((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active != 0U), TT_RET_STATUS_TRANSITION_ERR, &Ret);

        if (TT_RET_SUCCESS == Ret)
        {
            /* Set Send active flag */
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active = 1U;

            /* Save transmit buffer info */
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_buf = TxBuf;
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_num = Length;
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt = 0U;
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_BUSY;

            /* Fill TX FIFO */
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= TT_UART0_LCR_H_FEN_Msk;
            #if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
                Ret = Base_Drv_Timer_GetCounter(&timeStart);
            #endif
            while (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt < Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_num)
            {
                if ((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->FR & TT_UART0_FR_TXFF_Msk) == 0)
                {
                    /* Select flow control mode */
                    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DR = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_buf[Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt];
                    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt++;
                }
                else
                {
                    /* do nothing */
                }

            #if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
                Ret = Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
                if (timeElapsed >= uS2Ticks)
                {
                    Ret = TT_RET_STATUS_TIMEOUT_ERR;
                    break;
                }
                else
                {
                    /* do nothing */
                }
            #endif
            }

            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active = 0U;
            if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy == 0U)
            {
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
/**
 * @brief      :  Service for UART AsyncTransmission
 * @details    :  Service for UART AsyncTransmission
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  Other: Transmit command not accepted
 *
 **/
TT_RetType Uart_Hw_AsyncTransmit(TT_CONST uint8 HwUnit,uint8 *TxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((HwUnit >= UART_CONTROLLER_COUNT)||(Uart_PubMap[HwUnit] >= UART_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((TxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].work_mode == TT_USART_WORK_POLL), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info == NULL_PTR), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags == UART_STATUS_UNINIT), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active != 0U), TT_RET_STATUS_ERR, &Ret);

	if (TT_RET_SUCCESS == Ret)
	{
		/* Set Send active flag */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active = 1U;

		/* Save transmit buffer info */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_buf = TxBuf;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_num = Length;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_BUSY;
		/* Fill TX FIFO */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= TT_UART0_LCR_H_FEN_Msk;


#if (UART_DMA_ENABLE == STD_ON)
		if ((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].work_mode == TT_USART_WORK_DMA) && (NULL_PTR !=Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_tx))
		{
			/* Configure DMA channel */
			Ret = Dma_Drv_ChannelConfigure(&DmaChannelConfig[Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_tx->UartDmaConfigId],
											Length,
											(uint32)TxBuf,
											(uint32)&Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DR,
											Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_tx->cb_event);
			if(TT_RET_SUCCESS == Ret)
			{
				/* Enable DMA Transmit */
				Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DMACR |= TT_UART0_DMACR_TXDMAE_Msk;
			}
			else
			{
				Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active = 0U;
				if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy == 0U)
				{
					Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
				}
				else
				{
					/* do nothing */
				}
				Ret = TT_RET_STATUS_DMAC_ERR;
			}

		}
		else
#endif
		{
			/* IRQ Mode */
			Uart_Hw_PriAsyncTransmit(HwUnit);
		}
	}
	else
	{

	}

    return Ret;
}

/**
 * @brief      :  Service for UART SyncReception
 * @details    :  Service for UART SyncReception
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  Other: Receive command not accepted
 *
 **/
TT_RetType Uart_Hw_SyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Temp = 0;
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    Ret = Base_Drv_Timer_MicrosToTicks(UART_TIMEOUT_DURATION, &uS2Ticks);
#endif

    TT_ParaCheck(((HwUnit >= UART_CONTROLLER_COUNT)||(Uart_PubMap[HwUnit] >= UART_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((RxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].work_mode != TT_USART_WORK_POLL), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info == NULL_PTR), TT_RET_PARAM_ERR, &Ret);
    /*USART is not configured (mode not selected) or Send is not completed yet*/
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags == UART_STATUS_UNINIT), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy != 0U), TT_RET_PARAM_ERR, &Ret);

	if (TT_RET_SUCCESS == Ret)
	{
		/* Set RX busy flag */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy = 1U;

		/* Clear RX statuses */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_break = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_framing_error = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_overflow = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_parity_error = 0U;

		/* Save receive buffer info */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_buf = RxBuf;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_num = Length;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_BUSY;

		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= TT_UART0_LCR_H_FEN_Msk;

		#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			Ret = Base_Drv_Timer_GetCounter(&timeStart);
		#endif
		/* Get available data from RX FIFO */
		while (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt < Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_num)
		{
			if((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->RSR_ECR & (TT_UART0_RSR_FE_Msk|TT_UART0_RSR_PE_Msk|TT_UART0_RSR_BE_Msk|TT_UART0_RSR_OE_Msk)) != 0)
			{
				(void)Uart_Hw_PriRxLineIntHandler(HwUnit);
				Ret = TT_RET_IO_RX_ERR;
				break;
			}
			else if ((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->FR & TT_UART0_FR_RXFE_Msk) == 0)
			{
				/* Read data from RX FIFO into receive buffer */
				Temp = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DR;
				Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_buf[Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt] = (uint8)(Temp & 0xFFU);
				Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt++;
			}
			else
			{
				/* do nothing */
			}
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			Ret = Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
			if (timeElapsed >= uS2Ticks)
			{
				Ret = TT_RET_STATUS_TIMEOUT_ERR;
				break;
			}
			else
			{
				/* do nothing */
			}
#endif
		}

		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy = 0U;

		if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active == 0U)
		{
			Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		/* do nothing */
	}

    return Ret;
}

/**
 * @brief      :  Service for UART AsyncReception
 * @details    :  Service for UART AsyncReception
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  Other: Receive command not accepted
 *
 **/
TT_RetType Uart_Hw_AsyncReceive(TT_CONST uint8 HwUnit,uint8 *RxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((HwUnit >= UART_CONTROLLER_COUNT)||(Uart_PubMap[HwUnit] >= UART_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((RxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].work_mode == TT_USART_WORK_POLL), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info == NULL_PTR), TT_RET_STATUS_UNINIT_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags == UART_STATUS_UNINIT), TT_RET_STATUS_UNINIT_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy != 0U), TT_RET_PARAM_ERR, &Ret);
	if (TT_RET_SUCCESS == Ret)
	{
		/* Set RX busy flag */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy = 1U;

		/* Clear RX statuses */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_break = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_framing_error = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_overflow = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_parity_error = 0U;

		/* Save receive buffer info */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_buf = RxBuf;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_num = Length;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt = 0U;
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_BUSY;

		/* Fill TX FIFO */
		Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= TT_UART0_LCR_H_FEN_Msk;

#if (UART_DMA_ENABLE == STD_ON)
		if ((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].work_mode == TT_USART_WORK_DMA) && (NULL_PTR != (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_rx)))
		{
			/* Configure DMA channel */
			Ret = Dma_Drv_ChannelConfigure(&DmaChannelConfig[Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_rx->UartDmaConfigId],
											Length,
											(uint32)&Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DR,
											(uint32)RxBuf,
											Uart_Hw_PbResources[Uart_PubMap[HwUnit]].dma_rx->cb_event);

			if(TT_RET_SUCCESS == Ret)
			{
				/* Enable DMA Receive */
				Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DMACR |= TT_UART0_DMACR_RXDMAE_Msk;
			}
			else
			{
				Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy = 0U;
				if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active == 0U)
				{
					Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
				}
				else
				{
					/* do nothing */
				}
				Ret = TT_RET_STATUS_DMAC_ERR;
			}

		}
		else
#endif
		{
		   Uart_Hw_PriAsyncReceive( HwUnit);
		}
	}
	else
	{
		/* do nothing */
	}

    return Ret;
}

/**
 * @brief      :  Service to get status of the UART
 * @details    :  Service to get status of the UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  UartStatus  - The current status of the uart is
 *                              uninitialized, idle and Busy.
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get status command accepted
 *             :  Other: Get status not accepted
 *
 **/
TT_RetType Uart_Hw_GetStatus(TT_CONST uint8 HwUnit, Uart_StatusType *status)
{

    TT_RetType Ret = TT_RET_SUCCESS;

    if(HwUnit< UART_CONTROLLER_COUNT)
    {
        if(status != NULL_PTR)
        {
            if (Uart_PubMap[HwUnit] != 0xFFU)
            {
                *status = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags;
            }
            else
            {
                *status = UART_STATUS_UNINIT;
            }

        }
        else
        {
            Ret = TT_RET_PARAM_NULL_PTR_ERR;
        }

    }
    else
    {
        Ret = TT_RET_PARAM_ERR;
    }

    return Ret;
}
#define UART_STOP_SEC_CODE_FAST
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE_SLOW
#include "Uart_MemMap.h"
/**
 * @brief      :  Service to indicate type of error in module operation
 * @details    :  Service to indicate type of error in module operation
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  ErrorInfo  - The current Error information of the uart is
 *                             uninitialized, idle and Busy.
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get Error information command accepted
 *             :  Other: Get Error information command not accepted
 *
 **/
TT_RetType Uart_Hw_GetErrorStatus(TT_CONST uint8 HwUnit, uint32 *ErrorInfo)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((UART_CONTROLLER_COUNT <= HwUnit) || (Uart_PubMap[HwUnit] >= UART_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((ErrorInfo == NULL_PTR) || (*ErrorInfo != 0), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck(((Ret != TT_RET_SUCCESS) || (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info == NULL_PTR)), TT_RET_PARAM_ERR, &Ret);


    if (TT_RET_SUCCESS == Ret)
    {
        if( Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_overflow == 1U)
         {
            *ErrorInfo |= (uint16)TT_USART_EVENT_RX_OVERFLOW;
         }
         else
         {
             /* do nothing*/
         }

         /* Parity error */
         if(Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_parity_error == 1U)
         {
             *ErrorInfo |= (uint16)TT_USART_EVENT_RX_PARITY_ERROR;
         }
         else
         {
             /* do nothing*/
         }

         /* Break detected */
         if(Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_break == 1U)
         {
             *ErrorInfo |= (uint16)TT_USART_EVENT_RX_BREAK;
         }
         else
         {
             /* do nothing */
         }

         /* Framing error */
         if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_framing_error == 1U)
         {
             *ErrorInfo |= (uint16)TT_USART_EVENT_RX_FRAMING_ERROR;
         }
         else
         {
             /* do nothing*/
         }
    }
    else
    {
        /* do nothing */
    }

    return Ret;

}

/**
 * @brief      :  This service shall set the baud rate for UART
 * @details    :  This service shall set the baud rate for UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Baudrate - Set baud rate
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set Baudrate command accepted
 *             :  Other: Set Baudrate command not accepted
 *
 **/
TT_RetType Uart_Hw_SetBaudrate(TT_CONST uint8 HwUnit, Uart_BaudrateType Baudrate)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Divider = 0;
    uint32 ibrd = 0;
    uint32 fbrd = 0;
    Mcu_PeripheralClockValType UartSysClk = 0;

    TT_ParaCheck(((HwUnit >= UART_CONTROLLER_COUNT)||(Uart_PubMap[HwUnit] >= UART_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
//    TT_ParaCheck(!((Baudrate == 600)||(Baudrate == 1200)||
//                  (Baudrate == 2400)||(Baudrate == 4800)||
//                  (Baudrate == 9600)||(Baudrate == 14400)||
//                  (Baudrate == 19200)||(Baudrate == 28800)||
//                  (Baudrate == 38400)||(Baudrate == 56000)||
//                  (Baudrate == 57600)||(Baudrate == 76800)||
//                  (Baudrate == 115200)||(Baudrate == 128000)||
//                  (Baudrate == 230400)||(Baudrate == 256000)||
//                  (Baudrate == 460800)||(Baudrate == 921600)||
//                  (Baudrate == 1382400)), TT_RET_PARAM_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        if(Uart_Hw_PbResources[Uart_PubMap[HwUnit]].base_clk > 0)
        {
            /* Get UART System Clock */
            UartSysClk = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].base_clk;
            Divider = ((UartSysClk * 10) / ((Baudrate / 100) << 4));
            ibrd = Divider / 1000;
            fbrd = (((Divider % 1000) << 6) + 500) / 1000;
            if (fbrd >= 64)
            {
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IBDR = ibrd + 1;
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->FBDR = 0;
            }
            else
            {
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IBDR = ibrd;
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->FBDR = fbrd;
            }

            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->baudrate = Baudrate;
        }
        else
        {
            Ret = TT_RET_STATUS_ERR;
        }

    }
    else
    {

    }
    return Ret;
}
#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE_FAST
#include "Uart_MemMap.h"
#ifdef UART0_IRQ_ENABLE
ISR(UART0_COMBINE_IRQHandler);
ISR(UART0_COMBINE_IRQHandler)
{
    Uart_Hw_PriIrqHandler (0);
}
#endif
#ifdef UART1_IRQ_ENABLE
ISR(UART1_COMBINE_IRQHandler);
ISR(UART1_COMBINE_IRQHandler)
{
    Uart_Hw_PriIrqHandler(1);
}
#endif
#ifdef UART2_IRQ_ENABLE
ISR(UART2_COMBINE_IRQHandler);
ISR(UART2_COMBINE_IRQHandler)
{
    Uart_Hw_PriIrqHandler (2);
}
#endif
#ifdef UART3_IRQ_ENABLE
ISR(UART3_COMBINE_IRQHandler);
ISR(UART3_COMBINE_IRQHandler)
{
    Uart_Hw_PriIrqHandler (3);
}
#endif
#define UART_STOP_SEC_CODE_FAST
#include "Uart_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/
#define UART_START_SEC_CODE_SLOW
#include "Uart_MemMap.h"
/**
 * @brief      :  Set Uart several data bits
 * @details    :  Set Uart several data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumCharFrame  - Data bit pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetdata(uint8 HwUnit,uint8 NumCharFrame)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H &= ~(TT_UART0_LCR_H_WLEN_Msk);

    switch (NumCharFrame)
    {
    case (uint8)UART_DATA_BITS_5:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= (0U << TT_UART0_LCR_H_WLEN_Pos);
        break;
    case (uint8)UART_DATA_BITS_6:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= (1U << TT_UART0_LCR_H_WLEN_Pos);
        break;
    case (uint8)UART_DATA_BITS_7:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= (2U << TT_UART0_LCR_H_WLEN_Pos);
        break;
    case (uint8)UART_DATA_BITS_8:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= (3U << TT_UART0_LCR_H_WLEN_Pos);
        break;
    default:
        Ret = TT_RET_PARAM_ENUM_ERR;
        break;
    }

   return Ret;
}

/**
 * @brief      :  Set Uart several TX FIFO
 * @details    :  Set Uart several TX FIFO
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Tx_Fifo  - TX Depth of FIFO
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSettxfifo(uint8 HwUnit,uint8 Tx_Fifo)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS &= ~(TT_UART0_IFLS_TXIFLSEL_Msk);

    switch (Tx_Fifo)
    {
    case (uint8)UART_FIFO_ON_ONE_EIGHT_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS &= ~(TT_UART0_IFLS_TXIFLSEL_Msk);
        break;
    case (uint8)UART_FIFO_ON_ONE_FOUR_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS |= (uint32)(0x1U << TT_UART0_IFLS_TXIFLSEL_Pos);
        break;
    case (uint8)UART_FIFO_ON_ONE_TWO_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS |= (uint32)(0x2U << TT_UART0_IFLS_TXIFLSEL_Pos);
        break;
    case (uint8)UART_FIFO_ON_THREE_FOURE_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS |= (uint32)(0x3U << TT_UART0_IFLS_TXIFLSEL_Pos);
        break;
    case (uint8)UART_FIFO_ON_SEVEN_EIGHT_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS |= (uint32)(0x4U << TT_UART0_IFLS_TXIFLSEL_Pos);
        break;
    default:
        Ret = TT_RET_PARAM_ENUM_ERR;
        break;
    }

    return Ret;
}

/**
 * @brief      :  Set Uart several RX FIFO
 * @details    :  Set Uart several RX FIFO
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Rx_Fifo  - RX Depth of FIFO
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetrxfifo(uint8 HwUnit,uint8 Rx_Fifo)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS &= ~(TT_UART0_IFLS_RXIFLSEL_Msk);

    switch (Rx_Fifo)
    {
    case (uint8)UART_FIFO_ON_ONE_EIGHT_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS &= ~TT_UART0_IFLS_RXIFLSEL_Msk;
        break;
    case (uint8)UART_FIFO_ON_ONE_FOUR_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS |= (uint32)(0x1U << TT_UART0_IFLS_RXIFLSEL_Pos);
        break;
    case (uint8)UART_FIFO_ON_ONE_TWO_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS |= (uint32)(0x2U << TT_UART0_IFLS_RXIFLSEL_Pos);
        break;
    case (uint8)UART_FIFO_ON_THREE_FOURE_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS |= (uint32)(0x3U << TT_UART0_IFLS_RXIFLSEL_Pos);
        break;
    case (uint8)UART_FIFO_ON_SEVEN_EIGHT_LEVEL:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IFLS |= (uint32)(0x4U << TT_UART0_IFLS_RXIFLSEL_Pos);
        break;
    default:
        Ret = TT_RET_PARAM_ENUM_ERR;
        break;
    }

    return Ret;
}

/**
 * @brief      :  Set Uart Parity pattern
 * @details    :  Set Uart Parity pattern
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                ParityType  - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetParity(uint8 HwUnit,uint8 ParityType)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H &= ~(TT_UART0_LCR_H_EPS_Msk | TT_UART0_LCR_H_PEN_Msk);
    switch (ParityType)
    {
    case (uint8)UART_PARITY_NO:
        break;
    case (uint8)UART_PARITY_EVEN:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= TT_UART0_LCR_H_EPS_Msk | TT_UART0_LCR_H_PEN_Msk;
        break;
    case (uint8)UART_PARITY_ODD:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= TT_UART0_LCR_H_PEN_Msk;
        break;
    default:
        Ret = TT_RET_PARAM_ENUM_ERR;
        break;
    }

    return Ret;

}

/**
 * @brief      :  Set Uart Stop bits
 * @details    :  Set Uart Stop bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumStopBits  - Stop bits
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetstopbits(uint8 HwUnit,uint8 NumStopBits)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H &= ~(TT_UART0_LCR_H_STP2_Msk);

    switch (NumStopBits)
    {
    case (uint8)UART_STOP_BITS_1:
        break;
    case (uint8)UART_STOP_BITS_2:
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->LCR_H |= TT_UART0_LCR_H_STP2_Msk;
        break;
    default:
        Ret = TT_RET_PARAM_ENUM_ERR;
        break;
    }

    return Ret;
}

/**
 * @brief      :  Map Uart_PubMap to Uart_Hw_PbResources
 * @details    :  The subscript of the Uart_PubMap array indicates the corresponding Uart0 to Uart3,
 *                and the member value of the Uart_PubMap array is the array subscript of Uart_Hw_PbResources.
 *                Uart_Hw_PbResources[Uart_PubMap[Uart_0]] Indirectly accesses hardware resources corresponding to the serial port
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Map command accepted
 *             :  Other: Map command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriMapsort(TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 HwUnit = 0;
    uint8 i = 0;
    uint8 Map_Sort = 0;

    if(NULL_PTR != CfgPtr)
    {
        /* Gets the initialized uart */
        for(i = 0;i < UART_CONFIGED_COUNT; i++)
        {
          HwUnit = (uint8)CfgPtr->CtrlCfgPtr[i].HwUnit;

          if(UART_CONTROLLER_COUNT > HwUnit)
          {
              Uart_PubMap[HwUnit] = i;
          }
          else
          {
              Ret = TT_RET_PARAM_ENUM_ERR;
              break;
          }

        }

        if(TT_RET_SUCCESS ==  Ret)
        {
            /* mapping relation */
            for(i = 0;i < UART_CONTROLLER_COUNT; i++)
            {
              if(Uart_PubMap[i] != 0xFFU)
              {
                  Uart_PubMap[i] = Map_Sort;
                  Map_Sort++;
              }
              else
              {
                  /* do nothing */
              }
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
       Ret =  TT_RET_PARAM_NULL_PTR_ERR;
    }
    return Ret;
}

/**
 * @brief      :  Get clock frequency
 * @details    :  Get clock frequency
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  UartSysClk - Memory clock frequency
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriGetClk(uint8 HwUnit,uint32* UartSysClk)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    switch (HwUnit)
    {
        case (uint8)UART_0:
            Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_UART0, UartSysClk);
            break;
        case (uint8)UART_1:
            Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_UART1, UartSysClk);
            break;
        case (uint8)UART_2:
            Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_UART2, UartSysClk);
            break;
        case (uint8)UART_3:
            Ret = Mcu_Drv_Clk_GetPeriph(MCU_CLOCK_UART3, UartSysClk);
            break;
        default:
            Ret = TT_RET_PARAM_CHANNEL_ERR;
            break;
    }
    return Ret;
}

/**
 * @brief      :  Start the clock to obtain the clock frequency
 * @details    :  Start the clock to obtain the clock frequency
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  UartSysClk - Memory clock frequency
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriClk(uint8 HwUnit,uint32* UartSysClk)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if(NULL_PTR != UartSysClk)
    {
        switch (HwUnit)
        {
            case (uint8)UART_0:
                Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_UART0);
                break;
            case (uint8)UART_1:
                Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_UART1);
                break;
            case (uint8)UART_2:
                Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_UART2);
                break;
            case (uint8)UART_3:
                Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_UART3);
                break;
            default:
                Ret = TT_RET_PARAM_CHANNEL_ERR;
                break;
        }
        if(TT_RET_SUCCESS == Ret)
        {
            Ret = Uart_Hw_PriGetClk(HwUnit,UartSysClk);
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief      :  Example Set the Uart mode
 * @details    :  Example Set the Uart mode
 *
 * @param[in]  :  flag - CfgPtr->CtrlCfgPtr array subscript
 *                HwUnit - Module ID of the Hardware unit to transmit
 *                CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Uart_Hw_PriSetMode(uint8 flag ,uint8 HwUnit,TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Disable the sending and receiving mask interrupt status bit */
    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->TMSC &= ~TT_UART0_TMSC_TXTM_Msk;
    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->TMSC &= ~TT_UART0_TMSC_RXTM_Msk;

    /* USART Set data bits */
    Ret = Uart_Hw_PriSetdata(HwUnit,((uint8)CfgPtr->CtrlCfgPtr[flag].NumCharFrame));

    if(TT_RET_SUCCESS == Ret)
    {
      /* USART Set tx fifo */
        Ret = Uart_Hw_PriSettxfifo(HwUnit,((uint8)CfgPtr->CtrlCfgPtr[flag].TxFifoLevel));
    }
    else
    {
        /* do nothing */
    }

    if(TT_RET_SUCCESS == Ret)
    {
      /* USART Set Rx fifo */
        Ret = Uart_Hw_PriSetrxfifo(HwUnit,((uint8)CfgPtr->CtrlCfgPtr[flag].RxFifoLevel));
    }
    else
    {
        /* do nothing */
    }

    if ((Ret == TT_RET_SUCCESS) && (CfgPtr->CtrlCfgPtr[flag].RtsCtsFlowCtrl == TRUE))
    {
         Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->CR |= (TT_UART0_CR_RTSEN_Msk | TT_UART0_CR_CTSEN_Msk);
    }
    else
    {
        /* do nothing */
    }

    if ((Ret == TT_RET_SUCCESS) && (CfgPtr->CtrlCfgPtr[flag].TxTrigger != 0))
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->TMSC |= TT_UART0_TMSC_TXTM_Msk;
    }
    else
    {
        /* do nothing */
    }

    if ((Ret == TT_RET_SUCCESS) && (CfgPtr->CtrlCfgPtr[flag].RxTrigger != 0))
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->TMSC |= TT_UART0_TMSC_RXTM_Msk;
    }
    else
    {
        /* do nothing */
    }


    if(TT_RET_SUCCESS == Ret)
    {
        /* USART Set Parity */
        Ret = Uart_Hw_PriSetParity(HwUnit,((uint8)CfgPtr->CtrlCfgPtr[flag].ParityType));
    }
    else
    {
        /* do nothing */
    }

    if(TT_RET_SUCCESS == Ret)
    {
        /* USART Set stop bits */
        Ret = Uart_Hw_PriSetstopbits(HwUnit,((uint8)CfgPtr->CtrlCfgPtr[flag].NumStopBits));
    }
    else
    {
        /* do nothing */
    }

    if(TT_RET_SUCCESS == Ret)
    {
        /* Uart Baudrate */
        Ret = Uart_Hw_SetBaudrate(HwUnit, CfgPtr->CtrlCfgPtr[flag].Baudrate);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#define UART_STOP_SEC_CODE_SLOW
#if defined(UART0_DMA_ENABLE) || defined(UART1_DMA_ENABLE) || defined(UART2_DMA_ENABLE) || defined(UART3_DMA_ENABLE)
/**
* @brief      : UART DMA Interrupt handler.
* @details    : UART DMA Interrupt handler.
*
* @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
*               event - DMA_EVENT_TERMINAL_COUNT_REQUEST / DMA_EVENT_ERROR
* @param[out] : None
*
* @return     : void
* @retval     : None
*
**/
static void Uart_Hw_PriTxDmaEvent (TT_CONST uint8 HwUnit, uint32 event)
{
   switch (event)
   {
       case DMA_EVENT_TERMINAL_COUNT_REQUEST:
           /* Diabled Transmit DMA request */
           Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DMACR &= ~TT_UART0_DMACR_TXDMAE_Msk;
           Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_num;
           /* Clear TX busy flag */
           Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active = 0U;

           if(Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy == 0U)
           {
               Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
           }
           else
           {
               /* do nothing */
           }
           /* Set Send Complete event for asynchronous transfers */
           if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event != NULL_PTR)
           {
               Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event (TT_USART_EVENT_SEND_COMPLETE);
           }
           else
           {
               /* do nothing */
           }
           break;
       case DMA_EVENT_ERROR:
           if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event != NULL_PTR)
           {
               Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event (TT_USART_EVENT_SEND_INCOMPLETE);
           }
           else
           {
               /* do nothing */
           }
           break;
       default:
           /* nothing */
           break;
   }
}
/**
* @brief      : UART DMA Interrupt handler.
* @details    : UART DMA Interrupt handler.
*
* @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
*               event - DMA_EVENT_TERMINAL_COUNT_REQUEST / DMA_EVENT_ERROR
* @param[out] : None
*
* @return     : void
* @retval     : None
*
**/
static void Uart_Hw_PriRxDmaEvent (TT_CONST uint8 HwUnit, uint32 event)
{
   switch (event)
   {
       case DMA_EVENT_TERMINAL_COUNT_REQUEST:
           /* Diabled Receive DMA request */
           Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DMACR &= ~TT_UART0_DMACR_RXDMAE_Msk;

           Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_num;
           Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy = 0U;

           if(Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active == 0U)
           {
               Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
           }
           else
           {
               /* do nothing */
           }

           /* Set Receive Complete event for asynchronous transfers */
           if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event != NULL_PTR)
           {
               Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event (TT_USART_EVENT_RECEIVE_COMPLETE);
           }
           else
           {
               /* do nothing */
           }
           break;
       case DMA_EVENT_ERROR:
           if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event != NULL_PTR)
           {
               Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event (TT_USART_EVENT_RECEIVE_INCOMPLETE);
           }
           else
           {
               /* do nothing */
           }
           break;
       default:
       /* nothing */
           break;
   }
}

#ifdef UART0_DMA_ENABLE
/**
 * @brief      :  Gets the sending DMA run result function
 * @details    :  Gets the sending DMA run result function
 *
 * @param[in]  :  event - DMA run result event
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriDmaTx0 (uint32 event)
{
    Uart_Hw_PriTxDmaEvent(0, event);
}
/**
 * @brief      :  Gets the Receive DMA run result function
 * @details    :  Gets the Receive DMA run result function
 *
 * @param[in]  :  event - DMA run result event
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriDmaRx0 (uint32 event)
{
    Uart_Hw_PriRxDmaEvent(0, event);
}
#endif

#ifdef UART1_DMA_ENABLE
static void Uart_Hw_PriDmaTx1 (uint32 event)
{
    Uart_Hw_PriTxDmaEvent(1, event);
}
static void Uart_Hw_PriDmaRx1 (uint32 event)
{
    Uart_Hw_PriRxDmaEvent(1, event);
}
#endif

#ifdef UART2_DMA_ENABLE
static void Uart_Hw_PriDmaTx2 (uint32 event)
{
    Uart_Hw_PriTxDmaEvent(2, event);
}
static void Uart_Hw_PriDmaRx2 (uint32 event)
{
    Uart_Hw_PriRxDmaEvent(2, event);
}
#endif

#ifdef UART3_DMA_ENABLE
static void Uart_Hw_PriDmaTx3 (uint32 event)
{
    Uart_Hw_PriTxDmaEvent(3, event);
}
static void Uart_Hw_PriDmaRx3 (uint32 event)
{
    Uart_Hw_PriRxDmaEvent(3, event);
}
#endif
#endif
#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE_FAST
#include "Uart_MemMap.h"
/**
* @brief      :  Uart IRQ Transmit
* @details    :  Uart IRQ Transmit
*
* @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
* @param[out] :  None
*
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Transmit command accepted
*             :  Other: Transmit command not accepted
*
**/
static void Uart_Hw_PriAsyncTransmit(TT_CONST uint8 HwUnit)
{

    while (((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->FR & TT_UART0_FR_TXFF_Msk) == 0)
        && (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt != Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_num))
    {

        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DR = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_buf[Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt];
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt++;
    }

    /* Enable transmit interrupt if not complete */
    if(Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt != Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_num)
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IMSC |= TT_UART0_IMSC_TXIM_Msk;
    }
    else
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active = 0U;

        if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy == 0U)
        {
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
        }
        else
        {
            /* do nothing */
        }

        if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event != NULL_PTR)
        {
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event(TT_USART_EVENT_SEND_COMPLETE);
        }
        else
        {
            /* do nothing */
        }
    }
}

/**
* @brief      :  Uart IRQ Receive
* @details    :  Uart IRQ Receive
*
* @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
* @param[out] :  None
*
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Receive command accepted
*             :  Other: Receive command not accepted
*
**/
static void Uart_Hw_PriAsyncReceive(TT_CONST uint8 HwUnit)
{
    uint32 Temp = 0;

    /* Get available data from RX FIFO */
    while (((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->FR & TT_UART0_FR_RXFE_Msk) == 0) &&
        (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt < Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_num))
    {
            /* Read data from RX FIFO into receive buffer */
            Temp = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DR;
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_buf[Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt] = (uint8)(Temp & 0xFFU);
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt++;
    }

    /* Check if requested amount of data is received */
    if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt != Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_num)
    {
        /* Enable receive data available interrupt */
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IMSC |= TT_UART0_IMSC_RXIM_Msk;
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IMSC |= (TT_UART0_IMSC_RTIM_Msk);/* timeout int mask */
    }
    else
    {
        /* Clear RX busy flag and set receive transfer complete event */
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy = 0U;

        if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active == 0U)
        {
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
        }
        else
        {
            /* do nothing */
        }

        if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event != NULL_PTR)
        {
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event(TT_USART_EVENT_RECEIVE_COMPLETE);
        }
        else
        {
            /* do nothing */
        }
    }

}
#define UART_STOP_SEC_CODE_FAST
/**
 * @brief      :  Receive line interrupt handler
 * @details    :  Receive line interrupt handler
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  Rx Line event mask
 *
 **/
static uint32 Uart_Hw_PriRxLineIntHandler(TT_CONST uint8 HwUnit)
{
    uint32 rsr = 0;
    uint32 event = 0;

    event = 0UL;
    rsr = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->RSR_ECR;
    /* clear error*/
    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->RSR_ECR |= TT_UART0_RSR_FE_Msk|
                                                            TT_UART0_RSR_PE_Msk|
                                                            TT_UART0_RSR_BE_Msk|
                                                            TT_UART0_RSR_OE_Msk;
    /* OverRun error */
    if((rsr & TT_UART0_RSR_OE_Msk) != 0)
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_overflow = 1U;
        event |= (uint16)TT_USART_EVENT_RX_OVERFLOW;
    }
    else
    {
        /* do nothing*/
    }

    /* Parity error */
    if((rsr & TT_UART0_RSR_PE_Msk) != 0)
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_parity_error = 1U;
        event |= (uint16)TT_USART_EVENT_RX_PARITY_ERROR;
    }
    else
    {
        /* do nothing*/
    }

    /* Break detected */
    if((rsr & TT_UART0_RSR_BE_Msk) != 0)
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_break = 1U;
        event |= (uint16)TT_USART_EVENT_RX_BREAK;
    }
    else
    {
        /* do nothing */
    }

    /* Framing error */
    if ((rsr & TT_UART0_RSR_FE_Msk) != 0)
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_framing_error = 1U;
        event |= (uint16)TT_USART_EVENT_RX_FRAMING_ERROR;
    }
    else
    {
        /* do nothing*/
    }
    return event;
}
#if defined(UART0_IRQ_ENABLE) || defined(UART1_IRQ_ENABLE) || defined(UART2_IRQ_ENABLE) || defined(UART3_IRQ_ENABLE)
/**
 * @brief      :  USART Combine Interrupt handler for transmit.
 * @details    :  USART Combine Interrupt handler for transmit.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  event - Get the result of sending interrupt running
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriIrqHandlerTx(TT_CONST uint8 HwUnit,uint32* event)
{
    while(((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->FR & TT_UART0_FR_TXFF_Msk) == 0) &&
         (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_num != Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt))
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DR = (uint32)Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_buf[Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt] & 0xFFU;
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt++;
    }

    /* Check if all data is transmitted */
    if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_num == Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.tx_cnt)
    {
        /* Mask Transmit Interrupt */
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IMSC &= ~TT_UART0_IMSC_TXIM_Msk;

        /* Clear TX busy flag */
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active = 0U;
        if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy == 0U)
        {
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
        }
        else
        {
            /* do nothing*/
        }

        /* Set send complete event */
        *event |= (uint16)TT_USART_EVENT_SEND_COMPLETE;
    }
    else
    {
        /* do nothing*/
    }
}
/**
 * @brief      :  USART Combine Interrupt handler for Receive.
 * @details    :  USART Combine Interrupt handler for Receive.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  event - Get the result of receive interrupt running
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriIrqHandlerRx(TT_CONST uint8 HwUnit,uint32* event)
{
    uint32 Temp = 0;
    /* Get available data from RX FIFO */
    while (((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->FR & TT_UART0_FR_RXFE_Msk) == 0)
            && (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_num != Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt))
    {
        /* Read data from RX FIFO into receive buffer */
        Temp = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->DR;
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_buf[Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt] = (uint8)(Temp & 0xFFU);
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt++;

        /* Check RX line interrupt for errors */
        *event |= Uart_Hw_PriRxLineIntHandler(HwUnit);

        /* Check if requested amount of data is received */
        if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_cnt == Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.rx_num)
        {
            /* Disable Receive interrupt */
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->IMSC &= ~TT_UART0_IMSC_RXIM_Msk;

            /* Clear RX busy flag and set receive transfer complete event */
            Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->rx_status.rx_busy = 0U;
            if (Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->xfer.send_active == 0U)
            {
                Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
            }
            else
            {
                /* do nothing */
            }
            *event |= (uint16)TT_USART_EVENT_RECEIVE_COMPLETE;
            break;
        }
        else
        {
            /* do nothing */
        }
    }
}

/**
 * @brief      :  USART Combine Interrupt handler for Receive and Transmit.
 * @details    :  USART Combine Interrupt handler for Receive and Transmit.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Uart_Hw_PriIrqHandler(TT_CONST uint8 HwUnit)
{
    uint32 mis = 0;
    uint32 event = 0;

    mis = Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->MIS;

    /* Clear All Interrupt */
    Uart_Hw_PbResources[Uart_PubMap[HwUnit]].reg->ICR |= (uint32)0x7FF;

    /* Transmit Interrupt */
    if((mis & TT_UART0_RIS_TXRIS_Msk) != 0)
    {
        Uart_Hw_PriIrqHandlerTx(HwUnit,&event);
    }
    else
    {
        /* do nothing*/
    }

    /* Receive Error */
    if((mis & (TT_UART0_RIS_OERIS_Msk | TT_UART0_RIS_BERIS_Msk |
    TT_UART0_RIS_PERIS_Msk | TT_UART0_RIS_FERIS_Msk)) != 0)
    {
        event |= Uart_Hw_PriRxLineIntHandler(HwUnit);
    }
    else
    {
        /* do nothing*/
    }

    /* Receive data available interrupt */
    if (((mis & TT_UART0_RIS_RXRIS_Msk) != 0) || ((mis & TT_UART0_RIS_RTRIS_Msk) != 0))
    {
        Uart_Hw_PriIrqHandlerRx(HwUnit,&event);
    }
    else
    {
        /* do nothing */
    }
    /* callback function */
    if ((Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event != NULL_PTR) && (event != 0U))
    {
        Uart_Hw_PbResources[Uart_PubMap[HwUnit]].info->cb_event(event);
    }
    else
    {
        /* do nothing */
    }
}
#endif /*((UART0_IRQ_ENABLE)||(UART1_IRQ_ENABLE)||(UART2_IRQ_ENABLE)||(UART3_IRQ_ENABLE)) */
#define UART_STOP_SEC_CODE_FAST
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

