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
**  FILENAME     : Linu_Hw.c                                                        **
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
#include "Linu_Hw.h"
#include "Base_Drv.h"
#include "Mcu_Drv.h"

#if (LIN_DMA_ENABLE == STD_ON)
#include "Dma_Drv.h"
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define LINU_HW_VENDOR_ID_C                     1541
#define LINU_HW_MODULE_ID_C                     227
#define LINU_HW_AR_RELEASE_MAJOR_VERSION_C      4
#define LINU_HW_AR_RELEASE_MINOR_VERSION_C      4
#define LINU_HW_AR_RELEASE_PATCH_VERSION_C      0
#define LINU_HW_SW_MAJOR_VERSION_C              1
#define LINU_HW_SW_MINOR_VERSION_C              1
#define LINU_HW_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Linu_Hw.c and Linu_Hw.h file version check */
#if (LINU_HW_VENDOR_ID_C != LINU_HW_VENDOR_ID_H)
#error "Linu_Hw.c and Linu_Hw.h have different vendor ids"
#endif
#if (LINU_HW_MODULE_ID_C != LINU_HW_MODULE_ID_H)
#error "Linu_Hw.c and Linu_Hw.h have different module ids"
#endif
#if ((LINU_HW_AR_RELEASE_MAJOR_VERSION_C != LINU_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (LINU_HW_AR_RELEASE_MINOR_VERSION_C != LINU_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (LINU_HW_AR_RELEASE_PATCH_VERSION_C != LINU_HW_AR_RELEASE_PATCH_VERSION_H))
#error "AutoSar Version Numbers of Linu_Hw.c and Linu_Hw.h are different"
#endif
#if ((LINU_HW_SW_MAJOR_VERSION_C != LINU_HW_SW_MAJOR_VERSION_H) || \
     (LINU_HW_SW_MINOR_VERSION_C != LINU_HW_SW_MINOR_VERSION_H) || \
     (LINU_HW_SW_PATCH_VERSION_C != LINU_HW_SW_PATCH_VERSION_H))
#error "Software Version Numbers of Linu_Hw.c and Linu_Hw.h are different"
#endif

/* Linu_Hw.c and Mcu_Drv.h file version check */
#if (LINU_HW_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Linu_Hw.c and Mcu_Drv.h have different vendor ids"
#endif
#if ((LINU_HW_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (LINU_HW_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (LINU_HW_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Linu_Hw.c and Mcu_Drv.h are different"
#endif
#if ((LINU_HW_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (LINU_HW_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (LINU_HW_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Linu_Hw.c and Mcu_Drv.h are different"
#endif

/* Linu_Hw.c and Base_Drv.h file version check */
#if (LINU_HW_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
    #error "Linu_Hw.c and Base_Drv.h have different vendor ids"
#endif
#if ((LINU_HW_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (LINU_HW_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (LINU_HW_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Linu_Hw.c and Base_Drv.h are different"
#endif
#if ((LINU_HW_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
     (LINU_HW_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
     (LINU_HW_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Linu_Hw.c and Base_Drv.h are different"
#endif
#if (LIN_DMA_ENABLE == STD_ON)
    /* Linu_Hw.c and Dma_Drv.h file version check */
    #if (LINU_HW_VENDOR_ID_C != DMA_DRV_VENDOR_ID_H)
        #error "Linu_Hw.c and Dma_Drv.h have different vendor ids"
    #endif
    #if ((LINU_HW_AR_RELEASE_MAJOR_VERSION_C != DMA_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
         (LINU_HW_AR_RELEASE_MINOR_VERSION_C != DMA_DRV_AR_RELEASE_MINOR_VERSION_H) || \
         (LINU_HW_AR_RELEASE_PATCH_VERSION_C != DMA_DRV_AR_RELEASE_PATCH_VERSION_H))
        #error "AutoSar Version Numbers of Linu_Hw.c and Dma_Drv.h are different"
    #endif
    #if ((LINU_HW_SW_MAJOR_VERSION_C != DMA_DRV_SW_MAJOR_VERSION_H) || \
         (LINU_HW_SW_MINOR_VERSION_C != DMA_DRV_SW_MINOR_VERSION_H) || \
         (LINU_HW_SW_PATCH_VERSION_C != DMA_DRV_SW_PATCH_VERSION_H))
        #error "Software Version Numbers of Linu_Hw.c and Dma_Drv.h are different"
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
*                    Private Function Declaration
******************************************************************************/
#if (LIN_UART_ENABLE == STD_ON)
#ifdef LIN0_DMA_ENABLE
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
static void Linu_Hw_PriDmaTx0(uint32 event);
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
static void Linu_Hw_PriDmaRx0(uint32 event);
#endif

#ifdef LIN1_DMA_ENABLE
   static void Linu_Hw_PriDmaTx1(uint32 event);
   static void Linu_Hw_PriDmaRx1(uint32 event);
#endif

#ifdef LIN2_DMA_ENABLE
   static void Linu_Hw_PriDmaTx2(uint32 event);
   static void Linu_Hw_PriDmaRx2(uint32 event);
#endif

#ifdef LIN3_DMA_ENABLE
   static void Linu_Hw_PriDmaTx3(uint32 event);
   static void Linu_Hw_PriDmaRx3(uint32 event);
#endif

#ifdef LIN4_DMA_ENABLE
   static void Linu_Hw_PriDmaTx4(uint32 event);
   static void Linu_Hw_PriDmaRx4(uint32 event);
#endif

#ifdef LIN5_DMA_ENABLE
   static void Linu_Hw_PriDmaTx5(uint32 event);
   static void Linu_Hw_PriDmaRx5(uint32 event);
#endif

#ifdef LIN6_DMA_ENABLE
   static void Linu_Hw_PriDmaTx6(uint32 event);
   static void Linu_Hw_PriDmaRx6(uint32 event);
#endif

#ifdef LIN7_DMA_ENABLE
   static void Linu_Hw_PriDmaTx7(uint32 event);
   static void Linu_Hw_PriDmaRx7(uint32 event);
#endif

#ifdef LIN8_DMA_ENABLE
   static void Linu_Hw_PriDmaTx8(uint32 event);
   static void Linu_Hw_PriDmaRx8(uint32 event);
#endif

#ifdef LIN9_DMA_ENABLE
   static void Linu_Hw_PriDmaTx9(uint32 event);
   static void Linu_Hw_PriDmaRx9(uint32 event);
#endif

#ifdef LIN10_DMA_ENABLE
   static void Linu_Hw_PriDmaTx10(uint32 event);
   static void Linu_Hw_PriDmaRx10(uint32 event);
#endif

#ifdef LIN11_DMA_ENABLE
   static void Linu_Hw_PriDmaTx11(uint32 event);
   static void Linu_Hw_PriDmaRx11(uint32 event);
#endif

#ifdef LIN12_DMA_ENABLE
   static void Linu_Hw_PriDmaTx12(uint32 event);
   static void Linu_Hw_PriDmaRx12(uint32 event);
#endif

#ifdef LIN13_DMA_ENABLE
   static void Linu_Hw_PriDmaTx13(uint32 event);
   static void Linu_Hw_PriDmaRx13(uint32 event);
#endif

#ifdef LIN14_DMA_ENABLE
   static void Linu_Hw_PriDmaTx14(uint32 event);
   static void Linu_Hw_PriDmaRx14(uint32 event);
#endif

#ifdef LIN15_DMA_ENABLE
   static void Linu_Hw_PriDmaTx15(uint32 event);
   static void Linu_Hw_PriDmaRx15(uint32 event);
#endif
/**
 * @brief      :  Gets the peripheral clock
 * @details    :  Gets the peripheral clock
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware
 * @param[out] :  LinSysClk - Store the peripheral clock
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriGetPeriphClk(uint8 HwUnit,uint32* LinSysClk);

/**
 * @brief      :  Turn on peripheral clock
 * @details    :  Turn on peripheral clock
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriStartClk(uint8 HwUnit);

/**
 * @brief      :  Disable the Uart clock
 * @details    :  Disable the Uart clock
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriStopClk(uint8 HwUnit);

/**
 * @brief      :  Map Linu_PubMap to  Linu_PubResources
 * @details    :  The subscript of the Linu_PubMap array indicates the corresponding Lin0 to Lin15,
 *                and the member value of the Linu_PubMap array is the array subscript of Linu_PubResources.
 *                Linu_PubResources[Linu_PubMap[LINU_0]] Indirectly accesses hardware resources corresponding to the serial port
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Map command accepted
 *             :  Other: Map command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriMapsort(TT_CONST Uart_ConfigType *CfgPtr);

/**
 * @brief      :  Set Lin-Uart Low data bits
 * @details    :  Set Lin-Uart Low data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumCharFrame  - Data bit pattern
 *                ParityType - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriSetLowData(uint8 HwUnit,uint8 NumCharFrame,uint8 ParityType);

/**
 * @brief      :  Set Lin-Uart Hingh data bits
 * @details    :  Set Lin-Uart Low data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumCharFrame  - Data bit pattern
 *                ParityType - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriSetHighBits(uint8 HwUnit,uint8 NumCharFrame,uint8 ParityType);

/**
 * @brief      :  Set Lin-Uart several data bits
 * @details    :  Set Lin-Uart several data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumCharFrame  - Data bit pattern
 *                ParityType - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriSetdatabits(uint8 HwUnit,uint8 NumCharFrame,uint8 ParityType);

/**
 * @brief      :  Set Lin-Uart several data bits
 * @details    :  Set Lin-Uart several data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                ParityType - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriSetParity(uint8 HwUnit,uint8 ParityType);

/**
 * @brief      :  Set Lin-Uart Stop bits
 * @details    :  Set Lin-Uart Stop bits
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
static TT_RetType Linu_Hw_PriSetstopbits(uint8 HwUnit,uint8 NumStopBits);

/**
 * @brief      :  Example Set the Lin-Uart mode
 * @details    :  Example Set the Lin-Uart mode
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
static TT_RetType Linu_Hw_PriSetMode(uint8 flag ,uint8 HwUnit,TT_CONST Uart_ConfigType *CfgPtr);

/**
* @brief      :  Fill data into the data register
* @details    :  Fill data into the data register
*
* @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
*                LenType - data bits
* @param[out] :  None
*
* @return     :  void
* @retval     :  None
*
**/
static void Linu_Hw_PriWriteData(uint8 HwUnit,uint8 LenType);

/**
* @brief      :  Lin-Uart IRQ Receive
* @details    :  Lin-Uart IRQ Receive
*
* @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
* @param[out] :  None
*
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Receive command accepted
*             :  Other: Receive command not accepted
*
**/
static TT_RetType Linu_Hw_PriIrqReceive(TT_CONST uint8 HwUnit);

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
static uint32 Linu_Hw_PriRxLineInt(TT_CONST uint8 HwUnit);
#if(LIN_IRQ_ENABLE == STD_ON)
/**
 * @brief      :  LIN Combine Interrupt Receive handler.
 * @details    :  USART Combine Interrupt Receive handler.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static uint32 Linu_Hw_PriReceiveHandler(TT_CONST uint8 HwUnit);

/**
 * @brief      :  LIN Combine Interrupt handler.
 * @details    :  USART Combine Interrupt handler.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Linu_Hw_PriIrqHandler(TT_CONST uint8 HwUnit);
#endif

#if(LIN_DMA_ENABLE == STD_ON)
/**
 * @brief      : UART Interrupt handler.
 * @details    : UART Interrupt handler.
 *
 * @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
 *               event - GPDMA_EVENT_TERMINAL_COUNT_REQUEST / GPDMA_EVENT_ERROR
 * @param[out] : None
 *
 * @return     : void
 * @retval     : None
 *
 **/
static void Linu_Hw_PriDmaTxEvent(TT_CONST uint8 HwUnit, uint32 event);
/**
* @brief      : UART DMA Interrupt handler.
* @details    : UART DMA Interrupt handler.
*
* @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
*               event - GPDMA_EVENT_TERMINAL_COUNT_REQUEST / GPDMA_EVENT_ERROR
* @param[out] : None
*
* @return     : void
* @retval     : None
*
**/
static void Linu_Hw_PriDmaRxEvent(uint8 HwUnit, uint32 event);
#endif
/******************************************************************************
*                      Global variable  Definitions
******************************************************************************/

#define UART_START_SEC_VAR_FAST_INIT_8
#include "Uart_MemMap.h"
/**
* @brief      :  Linu_PubMap serves Linu_PubResources
* @details       Array subscripts correspond to LIN0 to LIN15.
*                Array members in Uart_Map are used to map LIN
*                hardware resources in Linu_PubResources
*
*/
static uint8 Linu_PubMap[LIN_CONTROLLER_COUNT] ={
                                                    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,\
                                                    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
                                                };

#define UART_STOP_SEC_VAR_FAST_INIT_8
#include "Uart_MemMap.h"

#define UART_START_SEC_VAR_SLOW_INIT_8
#include "Uart_MemMap.h"
/**
* @brief      :  Used for Lin to get the clock
* @details       Used to store the enumeration value
*                corresponding to the Lin fetch clock
*
*/
static TT_CONST Mcu_Hw_PeriphNameType Linu_PubGetClk[LIN_CONTROLLER_COUNT] =
{
    MCU_CLOCK_LIN0,MCU_CLOCK_LIN1,MCU_CLOCK_LIN2,MCU_CLOCK_LIN3,
    MCU_CLOCK_LIN4,MCU_CLOCK_LIN5,MCU_CLOCK_LIN6,MCU_CLOCK_LIN7,
    MCU_CLOCK_LIN8,MCU_CLOCK_LIN9,MCU_CLOCK_LIN10,MCU_CLOCK_LIN11,
    MCU_CLOCK_LIN12,MCU_CLOCK_LIN13,MCU_CLOCK_LIN14,MCU_CLOCK_LIN15
};
/**
* @brief      :  Is used for Lin to turn the clock on and off
* @details       Enumeration values corresponding to Lin off clock and on clock
*
*/
static TT_CONST TT_SCU_CLK_CONTROL_Type Linu_MapStartStopClk[LIN_CONTROLLER_COUNT] =
{
    TT_SCU_CLK_CONTROL_LIN0,TT_SCU_CLK_CONTROL_LIN1,TT_SCU_CLK_CONTROL_LIN2,TT_SCU_CLK_CONTROL_LIN3,
    TT_SCU_CLK_CONTROL_LIN4,TT_SCU_CLK_CONTROL_LIN5,TT_SCU_CLK_CONTROL_LIN6,TT_SCU_CLK_CONTROL_LIN7,
    TT_SCU_CLK_CONTROL_LIN8,TT_SCU_CLK_CONTROL_LIN9,TT_SCU_CLK_CONTROL_LIN10,TT_SCU_CLK_CONTROL_LIN11,
    TT_SCU_CLK_CONTROL_LIN12,TT_SCU_CLK_CONTROL_LIN13,TT_SCU_CLK_CONTROL_LIN14,TT_SCU_CLK_CONTROL_LIN15

};

#define UART_STOP_SEC_VAR_SLOW_INIT_8
#include "Uart_MemMap.h"

#define UART_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

#ifdef LIN0_CONFIGED
/**
* @brief      :  Running status information
* @details       Running status information
*
*/
static Linu_InfoType Linu0_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif
#ifdef LIN1_CONFIGED
static Linu_InfoType Linu1_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#ifdef LIN2_CONFIGED
static Linu_InfoType Linu2_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif
#ifdef LIN3_CONFIGED
static Linu_InfoType Linu3_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#ifdef LIN4_CONFIGED
static Linu_InfoType Linu4_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#ifdef LIN5_CONFIGED
static Linu_InfoType Linu5_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#ifdef LIN6_CONFIGED
static Linu_InfoType Linu6_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif
#ifdef LIN7_CONFIGED
static Linu_InfoType Linu7_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#ifdef LIN8_CONFIGED
static Linu_InfoType Linu8_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif
#ifdef LIN9_CONFIGED
static Linu_InfoType Linu9_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#ifdef LIN10_CONFIGED
static Linu_InfoType Linu10_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif
#ifdef LIN11_CONFIGED
static Linu_InfoType Linu11_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#ifdef LIN12_CONFIGED
static Linu_InfoType Linu12_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif
#ifdef LIN13_CONFIGED
static Linu_InfoType Linu13_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif
#ifdef LIN14_CONFIGED
static Linu_InfoType Linu14_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#ifdef LIN15_CONFIGED
static Linu_InfoType Linu15_Info =
{
    .cb_event  = NULL_PTR,
    .xfer      = {0,0,NULL_PTR,NULL_PTR,0,0,0},
    .status    = {0,0,0,0,0,0,0,0,0},
    .flags     = UART_STATUS_UNINIT,
    .baudrate  = 0,
    .LenType   = 0
};
#endif

#define UART_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

#define UART_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Uart_MemMap.h"

#ifdef LIN0_DMA_ENABLE
/**
* @brief      :  Sends Dma channel and callback function information
* @details       Sends Dma channel and callback function information
*
*/
static Linu_DmaType Linu0_DmaTx = {
                                    .LinDmaConfigId = 0,
                                    .cb_event       = Linu_Hw_PriDmaTx0
                                  };
/**
* @brief      :  Receive Dma channel and callback function information
* @details       Receive Dma channel and callback function information
*
*/
static Linu_DmaType Linu0_DmaRx = {
                                    .LinDmaConfigId = 0,
                                    .cb_event       = Linu_Hw_PriDmaRx0
                                  };
#endif


#ifdef LIN1_DMA_ENABLE
    static Linu_DmaType Linu1_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx1
                                      };
    static Linu_DmaType Linu1_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx1
                                      };
#endif


#ifdef LIN2_DMA_ENABLE
    static Linu_DmaType Linu2_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx2
                                      };
    static Linu_DmaType Linu2_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx2
                                      };
#endif


#ifdef LIN3_DMA_ENABLE
    static Linu_DmaType Linu3_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx3
                                      };
    static Linu_DmaType Linu3_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx3
                                      };
#endif

#ifdef LIN4_DMA_ENABLE
    static Linu_DmaType Linu4_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx4
                                      };
    static Linu_DmaType Linu4_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx4
                                      };
#endif


#ifdef LIN5_DMA_ENABLE
    static Linu_DmaType Linu5_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx5
                                      };
    static Linu_DmaType Linu5_DmaRx = {
                                      .LinDmaConfigId = 0,
                                      .cb_event       = Linu_Hw_PriDmaRx5
                                      };
#endif


#ifdef LIN6_DMA_ENABLE
    static Linu_DmaType Linu6_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx6
                                      };
    static Linu_DmaType Linu6_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx6
                                      };
#endif


#ifdef LIN7_DMA_ENABLE
    static Linu_DmaType Linu7_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx7
                                      };
    static Linu_DmaType Linu7_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx7
                                      };
#endif


#ifdef LIN8_DMA_ENABLE
    static Linu_DmaType Linu8_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx8
                                      };
    static Linu_DmaType Linu8_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx8
                                      };
#endif

#ifdef LIN9_DMA_ENABLE
    static Linu_DmaType Linu9_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx9
                                      };
    static Linu_DmaType Linu9_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx9
                                      };
#endif

#ifdef LIN10_DMA_ENABLE
    static Linu_DmaType Linu10_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx10
                                       };
    static Linu_DmaType Linu10_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx10
                                       };
#endif

#ifdef LIN11_DMA_ENABLE
    static Linu_DmaType Linu11_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx11
                                        };
    static Linu_DmaType Linu11_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx11
                                       };
#endif

#ifdef LIN12_DMA_ENABLE
    static Linu_DmaType Linu12_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx12
                                       };
    static Linu_DmaType Linu12_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx12
                                       };
#endif

#ifdef LIN13_DMA_ENABLE
    static Linu_DmaType Linu13_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx13
                                       };
    static Linu_DmaType Linu13_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx13
                                       };
#endif

#ifdef LIN14_DMA_ENABLE
    static Linu_DmaType Linu14_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx14
                                       };
    static Linu_DmaType Linu14_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx14
                                       };
#endif


#ifdef LIN15_DMA_ENABLE
    static Linu_DmaType Linu15_DmaTx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaTx15
                                       };
    static Linu_DmaType Linu15_DmaRx = {
                                        .LinDmaConfigId = 0,
                                        .cb_event       = Linu_Hw_PriDmaRx15
                                       };
#endif
/**
* @brief      :  Hardware resources and runtime information structures for Lin
* @details       Hardware resources and runtime information structures for Lin
*
*/
static Linu_Resources Linu_PubResources[LIN_CONFIGED_COUNT] =
{
#ifdef LIN0_CONFIGED
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN0_DMA_ENABLE
        .dma_tx      = &Linu0_DmaTx,
        .dma_rx      = &Linu0_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu0_Info
    }
#endif
#ifdef LIN1_CONFIGED
#if defined(LIN0_CONFIGED)
    ,
#endif
    {
        .reg = TT_LIN1,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN1_DMA_ENABLE
        .dma_tx      = &Linu1_DmaTx,
        .dma_rx      = &Linu1_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu1_Info
    }
#endif
#ifdef LIN2_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)
    ,
#endif
    {
        .reg = TT_LIN2,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN2_DMA_ENABLE
        .dma_tx      = &Linu2_DmaTx,
        .dma_rx      = &Linu2_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu2_Info
    }
#endif
#ifdef LIN3_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||defined(LIN2_CONFIGED)
    ,
#endif
    {
        .reg = TT_LIN3,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN3_DMA_ENABLE
        .dma_tx      = &Linu3_DmaTx,
        .dma_rx      = &Linu3_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu3_Info
    }
#endif
#ifdef LIN4_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)
	,
#endif
    {
        .reg = TT_LIN4,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN4_DMA_ENABLE
        .dma_tx      = &Linu4_DmaTx,
        .dma_rx      = &Linu4_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu4_Info
    }
#endif
#ifdef LIN5_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
	defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
	defined(LIN4_CONFIGED)
,
#endif
    {
        .reg = TT_LIN5,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN5_DMA_ENABLE
        .dma_tx      = &Linu5_DmaTx,
        .dma_rx      = &Linu5_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu5_Info
    }
    #endif

#ifdef LIN6_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN6_DMA_ENABLE
        .dma_tx      = &Linu6_DmaTx,
        .dma_rx      = &Linu6_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu6_Info
    }
#endif

#ifdef LIN7_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN7_DMA_ENABLE
        .dma_tx      = &Linu7_DmaTx,
        .dma_rx      = &Linu7_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu7_Info
    }
#endif

#ifdef LIN8_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)||defined(LIN7_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN8_DMA_ENABLE
        .dma_tx      = &Linu8_DmaTx,
        .dma_rx      = &Linu8_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu8_Info
    }
#endif

#ifdef LIN9_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)||defined(LIN7_CONFIGED)||\
    defined(LIN8_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN9_DMA_ENABLE
        .dma_tx      = &Linu9_DmaTx,
        .dma_rx      = &Linu9_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu9_Info
    }
#endif

#ifdef LIN10_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)||defined(LIN7_CONFIGED)||\
    defined(LIN8_CONFIGED)||defined(LIN9_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN10_DMA_ENABLE
        .dma_tx      = &Linu10_DmaTx,
        .dma_rx      = &Linu10_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu10_Info
    }
#endif

#ifdef LIN11_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)||defined(LIN7_CONFIGED)||\
    defined(LIN8_CONFIGED)||defined(LIN9_CONFIGED)||\
    defined(LIN10_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN11_DMA_ENABLE
        .dma_tx      = &Linu11_DmaTx,
        .dma_rx      = &Linu11_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu11_Info
    }
#endif

#ifdef LIN12_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)||defined(LIN7_CONFIGED)||\
    defined(LIN8_CONFIGED)||defined(LIN9_CONFIGED)||\
    defined(LIN10_CONFIGED)||defined(LIN11_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN12_DMA_ENABLE
        .dma_tx      = &Linu12_DmaTx,
        .dma_rx      = &Linu12_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu12_Info
    }
#endif

#ifdef LIN13_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)||defined(LIN7_CONFIGED)||\
    defined(LIN8_CONFIGED)||defined(LIN9_CONFIGED)||\
    defined(LIN10_CONFIGED)||defined(LIN11_CONFIGED)||\
    defined(LIN12_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN13_DMA_ENABLE
        .dma_tx      = &Linu13_DmaTx,
        .dma_rx      = &Linu13_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu13_Info
    }
#endif

#ifdef LIN14_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)||defined(LIN7_CONFIGED)||\
    defined(LIN8_CONFIGED)||defined(LIN9_CONFIGED)||\
    defined(LIN10_CONFIGED)||defined(LIN11_CONFIGED)||\
    defined(LIN12_CONFIGED)||defined(LIN13_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN14_DMA_ENABLE
        .dma_tx      = &Linu14_DmaTx,
        .dma_rx      = &Linu14_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu14_Info
    }
#endif

#ifdef LIN15_CONFIGED
#if defined(LIN0_CONFIGED)||defined(LIN1_CONFIGED)||\
    defined(LIN2_CONFIGED)||defined(LIN3_CONFIGED)||\
    defined(LIN4_CONFIGED)||defined(LIN5_CONFIGED)||\
    defined(LIN6_CONFIGED)||defined(LIN7_CONFIGED)||\
    defined(LIN8_CONFIGED)||defined(LIN9_CONFIGED)||\
    defined(LIN10_CONFIGED)||defined(LIN11_CONFIGED)||\
    defined(LIN12_CONFIGED)||defined(LIN13_CONFIGED)||\
    defined(LIN14_CONFIGED)
,
#endif
    {
        .reg = TT_LIN0,
        .work_mode   =TT_USART_WORK_POLL,
        .base_clk    = 0,
#if (LIN_DMA_ENABLE == STD_ON)
#ifdef LIN15_DMA_ENABLE
        .dma_tx      = &Linu15_DmaTx,
        .dma_rx      = &Linu15_DmaRx,
#else
        .dma_tx      = NULL,
        .dma_rx      = NULL,
#endif
#endif
        .info        = &Linu15_Info
    }
#endif
};
#define UART_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Uart_MemMap.h"

/******************************************************************************
 *                         Public Functions                                    *
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
 *             :  E_NOT_OK: Initialization is not complete
 *
 **/
TT_RetType Linu_Hw_Init(TT_CONST Uart_ConfigType* CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Reg_Linsr = 0;
    uint8  HwUnit = 0;
    uint8 i = 0;
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;

    (void)Base_Drv_Timer_MicrosToTicks(UART_TIMEOUT_DURATION, &uS2Ticks);
#endif

    Ret = Linu_Hw_PriMapsort(CfgPtr);

	for (i = UART_CONFIGED_COUNT; (i < ALL_CONTROLLER_COUNT) && (TT_RET_SUCCESS == Ret); i++)
	{
		HwUnit =(uint8) CfgPtr->CtrlCfgPtr[i].HwUnit - (uint8)LINU_0;
		Ret = Linu_Hw_PriStartClk(HwUnit);

		if(TT_RET_SUCCESS == Ret)
		{
			/* Initialize LIN Run-time Resources */
			Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event = CfgPtr->CtrlCfgPtr[i].cb_event;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.buffer_overrun = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_framing_error = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_szf = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_nf = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.oc_error = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_parity_error = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_timeout = 0U;
			Linu_PubResources[Linu_PubMap[HwUnit]].work_mode = CfgPtr->CtrlCfgPtr[i].WorkMode;

			/* enter initialization mode. */
			Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINCR1 &= ~TT_LIN_LINCR1_SLEEP_Msk;
			Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINCR1 |= TT_LIN_LINCR1_INIT_Msk;

			Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_UART_Msk;
			Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINTCSR |= (uint32)TT_LIN_LINTCSR_MODE_Msk;
			Reg_Linsr = ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINSR & TT_LIN_LINSR_LINS_Msk) >> TT_LIN_LINSR_LINS_Pos);

#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			Ret = Base_Drv_Timer_GetCounter(&timeStart);
#endif
			while (Reg_Linsr != 1U)
			{
				Reg_Linsr = ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINSR & TT_LIN_LINSR_LINS_Msk) >> TT_LIN_LINSR_LINS_Pos);
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
				(void)Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
				if(timeElapsed >= uS2Ticks)
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

#if (LIN_DMA_ENABLE == STD_ON)
			if (Linu_PubResources[Linu_PubMap[HwUnit]].dma_tx != NULL_PTR)
			{
				Linu_PubResources[Linu_PubMap[HwUnit]].dma_tx->LinDmaConfigId = CfgPtr->CtrlCfgPtr[i].UartTxDmaConfigId;
			}
			else
			{
				/* do nothing */
			}

			if (Linu_PubResources[Linu_PubMap[HwUnit]].dma_rx != NULL_PTR)
			{
				Linu_PubResources[Linu_PubMap[HwUnit]].dma_rx->LinDmaConfigId = CfgPtr->CtrlCfgPtr[i].UartRxDmaConfigId;
			}
			else
			{
				/* do nothing */
			}
#endif
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			if(Ret == TT_RET_SUCCESS)
			{

#if (LIN_UART_OVERSAMPLERATE == STD_ON)
				/* enable reduced oversampling */
				Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_ROSE_Msk;
				Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (((uint32)(CfgPtr->CtrlCfgPtr[i].LinOverSampleRate)) << TT_LIN_UARTCR_OSR_Pos);
				Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= ((((uint32)(CfgPtr->CtrlCfgPtr[i].LinSamplePoint)) << TT_LIN_UARTCR_CSP_Pos) & TT_LIN_UARTCR_CSP_Msk);
#else
				Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_ROSE_Msk;
#endif
				/* Set various modes */
				Ret = Linu_Hw_PriSetMode(i,HwUnit,CfgPtr);

			}
			else
			{
				/* do nothing */
			}
#else

#if (LIN_UART_OVERSAMPLERATE == STD_ON)
			/* enable reduced oversampling */
			Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_ROSE_Msk;
			Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (((uint32)(CfgPtr->CtrlCfgPtr[i].LinOverSampleRate)) << TT_LIN_UARTCR_OSR_Pos);
			Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= ((((uint32)(CfgPtr->CtrlCfgPtr[i].LinSamplePoint)) << TT_LIN_UARTCR_CSP_Pos) & TT_LIN_UARTCR_CSP_Msk);
#else
			Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_ROSE_Msk;
#endif
			/* Set various modes */
			Ret = Linu_Hw_PriSetMode(i,HwUnit,CfgPtr);
#endif
			if(Ret == TT_RET_SUCCESS)
			{
				Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINCR1 &= ~TT_LIN_LINCR1_INIT_Msk;
				Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
			}
			else
			{

			}
		}
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
TT_RetType Linu_Hw_InitCheck(TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8  HwUnit = 0;

    for (uint8 i = UART_CONFIGED_COUNT; i < ALL_CONTROLLER_COUNT; i++)
    {
        HwUnit =(uint8) CfgPtr->CtrlCfgPtr[i].HwUnit - (uint8)LINU_0;
        if((Ret == TT_RET_SUCCESS) && (Linu_PubMap[HwUnit] != 0xFFU))
        {
            if((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_UART_Msk) != 0)
            {
                /* do nothing */
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
                break;
            }

            if((Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINTCSR & TT_LIN_LINTCSR_MODE_Msk) != 0)
            {
                /* do nothing */
            }
            else
            {
                Ret = TT_RET_STATUS_ERR;
                break;
            }

        }
        else
        {
            Ret = TT_RET_STATUS_ERR;
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
 *             :  E_NOT_OK: De-initialization command has not been accepted
 *
 **/
TT_RetType Linu_Hw_DeInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Reg_Linsr = 0;
    uint8 i = 0;
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    Ret = Base_Drv_Timer_MicrosToTicks(UART_TIMEOUT_DURATION, &uS2Ticks);
#endif

    for (i = 0; i < LIN_CONFIGED_COUNT; i++)
    {

		if (Linu_PubResources[i].info->flags == UART_STATUS_IDLE)
		{
			Linu_PubResources[i].reg->LINCR1 &= ~TT_LIN_LINCR1_SLEEP_Msk;
			Linu_PubResources[i].reg->LINCR1 |= TT_LIN_LINCR1_INIT_Msk;
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			Ret = Base_Drv_Timer_GetCounter(&timeStart);
#endif
			Reg_Linsr = ((Linu_PubResources[i].reg->LINSR & TT_LIN_LINSR_LINS_Msk) >> TT_LIN_LINSR_LINS_Pos);
			while (Reg_Linsr != 1U)
			{
				Reg_Linsr = ((Linu_PubResources[i].reg->LINSR & TT_LIN_LINSR_LINS_Msk) >> TT_LIN_LINSR_LINS_Pos);
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
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			if(TT_RET_SUCCESS == Ret)
			{
				/* clear UART bit */
				Linu_PubResources[i].reg->UARTCR &= ~TT_LIN_UARTCR_UART_Msk;
				Linu_PubResources[i].reg->LINTCSR &= ~(uint32)TT_LIN_LINTCSR_MODE_Msk;
				/* disable interrupt */
				Linu_PubResources[i].reg->LINIER = 0U;
				/* Reset LIN status flags */
				Linu_PubResources[i].info->flags = UART_STATUS_UNINIT;
				Ret = Linu_Hw_PriStopClk(i);
			}
			else
			{
				break;
			}
#else
			/* clear UART bit */
			Linu_PubResources[i].reg->UARTCR &= ~TT_LIN_UARTCR_UART_Msk;
			Linu_PubResources[i].reg->LINTCSR &= ~(uint32)TT_LIN_LINTCSR_MODE_Msk;
			/* disable interrupt */
			Linu_PubResources[i].reg->LINIER = 0U;
			/* Reset LIN status flags */
			Linu_PubResources[i].info->flags = UART_STATUS_UNINIT;
			Ret = Linu_Hw_PriStopClk(i);
#endif
		}
		else
		{
			Ret = TT_RET_STATUS_ERR;
			break;
		}
    }
    return Ret;
}   /* end of Uart_Hal_DeInit */

/**
 * @brief      :  This service shall set the baud rate for UART
 * @details    :  This service shall set the baud rate for UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                baudrate - Set baud rate
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set Baudrate command accepted
 *             :  Other: Set Baudrate command not accepted
 *
 **/
TT_RetType Linu_Hw_SetBaudrate(TT_CONST uint8 HwUnit, uint32 baudrate)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 osr = 0;
    uint32 mantissa = 0;
    uint32 LinSysClk = 0U;
    uint32 di_current = 0;
    uint32 fractionNumerator = 0;
    uint32 fractionDenominator = 0;
    float divider = 0.0f;
    float prescaler= 0.0f;
    float fraction = 0.0f;
    float numerator = 0.0f;

    TT_ParaCheck(((HwUnit >= LIN_CONTROLLER_COUNT)||(Linu_PubMap[HwUnit] >= LIN_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck(!((baudrate == 600)||(baudrate == 1200)||
                  (baudrate == 2400)||(baudrate == 4800)||
                  (baudrate == 9600)||(baudrate == 14400)||
                  (baudrate == 19200)||(baudrate == 28800)||
                  (baudrate == 38400)||(baudrate == 56000)||
                  (baudrate == 57600)||(baudrate == 76800)||
                  (baudrate == 115200)||(baudrate == 128000)||
                  (baudrate == 230400)||(baudrate == 256000)||
                  (baudrate == 460800)||(baudrate == 912600)||
                  (baudrate == 1382400)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_UART_Msk) == 0), TT_RET_STATUS_ERR, &Ret);


    if(TT_RET_SUCCESS == Ret)
    {
        Ret = Linu_Hw_PriGetPeriphClk(HwUnit,&LinSysClk);
        if(TT_RET_SUCCESS == Ret)
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].base_clk = LinSysClk;
            di_current = (LinSysClk * 2) / baudrate;
            divider = (float)di_current;

            if ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_ROSE_Msk) != 0)
            {
                /* UART mode and reduced oversampling enable */
                osr = (uint8)((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_OSR_Msk) >> TT_LIN_UARTCR_OSR_Pos);
            }
            else
            {
                osr = 16U;
            }

            prescaler = divider / ((float)osr);
            mantissa = (uint32)prescaler;

            fraction = prescaler - (float)mantissa;
            fractionDenominator = ((uint32)1 << 4U);
            numerator = (fraction * (float)fractionDenominator + 0.5F);
            fractionNumerator = (uint32)numerator;

            if (fractionNumerator == fractionDenominator)
            {
                fractionNumerator = 0;
                mantissa++;
            }
            else
            {
                /* do nothing */
            }

            Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIBRR &= ~TT_LIN_LINIBRR_IBR_Msk;
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIBRR |= (mantissa & TT_LIN_LINIBRR_IBR_Msk);

            if ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_ROSE_Msk) != 0) /* UART mode and reduced oversampling enable */
            {
                Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINFBRR &= ~TT_LIN_LINFBRR_FBR_Msk; /* prohibited to use LINFBRR_FBR, should be programmed to 0. */
            }
            else
            {
                Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINFBRR &= ~(TT_LIN_LINFBRR_FBR_Msk);
                Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINFBRR |= (fractionNumerator & TT_LIN_LINFBRR_FBR_Msk);
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


#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE_FAST
#include "Uart_MemMap.h"
/**
 * @brief      :  Service for UART SyncTransmit
 * @details    :  Service for UART SyncTransmit
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  E_NOT_OK: Transmit command not accepted
 *
 **/
TT_RetType Linu_Hw_SyncTransmit(TT_CONST uint8 HwUnit,uint8* TxBuf,uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    Ret = Base_Drv_Timer_MicrosToTicks(UART_TIMEOUT_DURATION, &uS2Ticks);
#endif

    TT_ParaCheck(((HwUnit >= LIN_CONTROLLER_COUNT)||(Linu_PubMap[HwUnit] >= LIN_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((TxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].work_mode != TT_USART_WORK_POLL), TT_RET_STATUS_TRANSITION_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info == NULL), TT_RET_PARAM_ERR, &Ret);
	TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info->flags == UART_STATUS_UNINIT), TT_RET_STATUS_ERR, &Ret);
	TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy != 0U), TT_RET_STATUS_ERR, &Ret);
	TT_ParaCheck((Ret != TT_RET_SUCCESS) || ((Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType > (uint8)LIN_UART_EIGHT_BITS)&&
				 ((Length & 1U) != 0)), TT_RET_PARAM_LEN_ERR, &Ret);

	if(TT_RET_SUCCESS == Ret)
	{
		/* Save transmit buffer info */
		Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy = 1U;
		Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_buf = TxBuf;
		Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_num = Length;
		Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt = 0U;
		Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_BUSY;
		/* enable TX and clear DTF flag */
		Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DTFTFF_Msk;
		Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_TxEn_Msk;


		if((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_TFBM_Msk) != 0)
		{
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			Ret = Base_Drv_Timer_GetCounter(&timeStart);
#endif
			while (Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt < Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_num)
			{
				if((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR & TT_LIN_UARTSR_DTFTFF_Msk) != 0)
				{
					Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DTFTFF_Msk;
					Linu_Hw_PriWriteData(HwUnit,Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType);
				}
				else
				{
					/* do noting */
				}
				if (Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt == 0U)
				{
					Linu_Hw_PriWriteData(HwUnit,Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType);
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

		Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy = 0U;
		Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
		/* clear DTF flag and disable TX */
		Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DTFTFF_Msk;
		Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_TxEn_Msk;
		}
		else
		{
			Ret = TT_RET_STATUS_ERR;
		}
	}
	else
	{
	/* do nothing */
	}

    return Ret;
}


/**
 * @brief      :  Service for UART AsyncTransmit
 * @details    :  Service for UART AsyncTransmit
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                TxBuf  - Pointer to the data to be transmitted
 *                Length - Number of bytes to be transmitted. Range: 0 - 65535
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Transmit command accepted
 *             :  E_NOT_OK: Transmit command not accepted
 *
 **/
TT_RetType Linu_Hw_AsyncTransmit(TT_CONST uint8 HwUnit,uint8* TxBuf,uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((HwUnit >= LIN_CONTROLLER_COUNT)||(Linu_PubMap[HwUnit] >= LIN_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((TxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info == NULL), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].work_mode == TT_USART_WORK_POLL), TT_RET_STATUS_TRANSITION_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        TT_ParaCheck((Linu_PubResources[Linu_PubMap[HwUnit]].info->flags == UART_STATUS_UNINIT), TT_RET_STATUS_ERR, &Ret);
        TT_ParaCheck((Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy != 0U), TT_RET_STATUS_ERR, &Ret);
        TT_ParaCheck(((Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType > (uint8)LIN_UART_EIGHT_BITS)&&
                     ((Length & 1U) != 0)), TT_RET_PARAM_LEN_ERR, &Ret);

        if(TT_RET_SUCCESS == Ret)
        {
            /* Save transmit buffer info */
            Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy = 1U;
            Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_buf = TxBuf;
            Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_num = Length;
            Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt = 0U;
            Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_BUSY;
            /* enable TX and clear DTF flag */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DTFTFF_Msk;
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_TxEn_Msk;

        #if (LIN_DMA_ENABLE == STD_ON)
            if ((Linu_PubResources[Linu_PubMap[HwUnit]].work_mode == TT_USART_WORK_DMA) && (Linu_PubResources[Linu_PubMap[HwUnit]].dma_tx != NULL_PTR))
            {
                /* Configure DMA channel */
                Ret = Dma_Drv_ChannelConfigure(&DmaChannelConfig[Linu_PubResources[Linu_PubMap[HwUnit]].dma_tx->LinDmaConfigId],
                                                Length,
                                                (uint32)TxBuf,
                                                (uint32)&Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRL,
                                                Linu_PubResources[Linu_PubMap[HwUnit]].dma_tx->cb_event);
                if (TT_RET_SUCCESS == Ret)
                {
                    /* Enable DMA Transmit */
                    Linu_PubResources[Linu_PubMap[HwUnit]].reg->DMATXE = 1U;
                }
                else
                {
                    Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy = 0U;
                    Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
                }
            }
            else
        #endif
            {
                /* enable TX interrupt */
                Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER |= TT_LIN_LINIER_DTIE_Msk;
                Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER |= UART_ERROR_ALL_INT;

                if((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_TFBM_Msk) != 0)
                {
                    Linu_Hw_PriWriteData(HwUnit,Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType);

                }
                else
                {
                    Ret = TT_RET_STATUS_ERR;
                }
            }

        }
        else
        {
            /* doing nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief      :  Service for UART SyncReceive
 * @details    :  Service for UART SyncReceive
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  E_NOT_OK: Receive command not accepted
 *
 **/
TT_RetType  Linu_Hw_SyncReceive(TT_CONST uint8 HwUnit,uint8* RxBuf,uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    Ret = Base_Drv_Timer_MicrosToTicks(UART_TIMEOUT_DURATION, &uS2Ticks);
#endif

    TT_ParaCheck(((HwUnit >= LIN_CONTROLLER_COUNT)||(Linu_PubMap[HwUnit] >= LIN_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((RxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info == NULL), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].work_mode != TT_USART_WORK_POLL), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info->flags == UART_STATUS_UNINIT), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy != 0U), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || ((Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType > (uint8)LIN_UART_EIGHT_BITS)&&
                 ((Length & 1U) != 0)), TT_RET_PARAM_LEN_ERR, &Ret);

	if(TT_RET_SUCCESS == Ret)
	{
	   /* Set RX busy flag */
	   Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy = 1U;

	   /* Save receive buffer info */
	   Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf = RxBuf;
	   Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_num = Length;
	   Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt = 0U;
	   Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_BUSY;

	   /* enable RX and clear flags */
	   Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DRFRFE_Msk | TT_LIN_UARTSR_RMB_Msk;
	   Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_RxEn_Msk;

#if defined(UART_TIMEOUT_SUPERVISION_ENABLE) && (UART_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			Ret = Base_Drv_Timer_GetCounter(&timeStart);
#endif
	   /* Get available data from RX FIFO */
	   while (Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt < Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_num)
	   {
		   if((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR & TT_LIN_UARTSR_DRFRFE_Msk) != 0)
		   {
			   if ((Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType == (uint8)LIN_UART_SEVEN_BITS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType == (uint8)LIN_UART_EIGHT_BITS)) /* data length 7/8 */
			   {
				   *(Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf) = (uint8)(Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRM);
				   ++Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf;
				   ++Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt;
			   }
			   else
			   {
				   /* do nothing */
			   }

			   if ((Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType == (uint8)LIN_UART_FIFTEEN_BITS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType == (uint8)LIN_UART_SIXTEEN_BITS)) /* data length 15/16 */
			   {
				   Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf[0] = (uint8)(Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRM);
				   Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf[1] = (uint8)(Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRM >> 8U);
				   Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf += 2;
				   Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt += 2;
			   }
			   else
			   {
				   /* do nothing*/
			   }
			   Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DRFRFE_Msk;
		   }
		   else
		   {
			   /* do nothing */
		   }

		   if ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR & UART_ALL_ERROR_FLAG) != 0)
		   {
			   (void)Linu_Hw_PriRxLineInt(HwUnit);
			   Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= UART_ALL_ERROR_FLAG;

			   /* Clear all error interrupts in IER register */
			   if ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER & UART_ERROR_ALL_INT) != 0U)
			   {
				   Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER &= ~UART_ERROR_ALL_INT;
			   }
			   else
			   {
				   /* do nothing */
			   }
			  Ret = TT_RET_IO_RX_ERR;
			  break;
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
	   /* clear flags and disable RX */
	   Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= (TT_LIN_UARTSR_DRFRFE_Msk | TT_LIN_UARTSR_RMB_Msk);
	   Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_RxEn_Msk;

	   Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy = 0U;
	   Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;

   }
   else
   {
	   /* do nothing */
   }
    return Ret;
}

/**
 * @brief      :  Service for UART AsyncReceive
 * @details    :  Service for UART AsyncReceive
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                Length - Number of bytes which were read
 * @param[out] :  RxBuf  - Buffer to store received data
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Receive command accepted
 *             :  E_NOT_OK: Receive command not accepted
 *
 **/
TT_RetType  Linu_Hw_AsyncReceive(TT_CONST uint8 HwUnit,uint8* RxBuf,uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((HwUnit >= LIN_CONTROLLER_COUNT)||(Linu_PubMap[HwUnit] >= LIN_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((RxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info == NULL), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].work_mode == TT_USART_WORK_POLL), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        TT_ParaCheck((Linu_PubResources[Linu_PubMap[HwUnit]].info->flags == UART_STATUS_UNINIT), TT_RET_STATUS_ERR, &Ret);
        TT_ParaCheck((Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy != 0U), TT_RET_STATUS_ERR, &Ret);
        TT_ParaCheck(((Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType > (uint8)LIN_UART_EIGHT_BITS)&&
                     ((Length & 1U) != 0)), TT_RET_PARAM_LEN_ERR, &Ret);

        if(TT_RET_SUCCESS == Ret)
        {
            /* Set RX busy flag */
            Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy = 1U;

            /* Save receive buffer info */
            Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf = RxBuf;
            Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_num = Length;
            Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt = 0U;

            Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_BUSY;

            /* enable RX and clear flags */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DRFRFE_Msk | TT_LIN_UARTSR_RMB_Msk;
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_RxEn_Msk;

        #if (LIN_DMA_ENABLE == STD_ON)
            if ((Linu_PubResources[Linu_PubMap[HwUnit]].work_mode == TT_USART_WORK_DMA) && ((Linu_PubResources[Linu_PubMap[HwUnit]].dma_rx) != NULL_PTR))
            {
                /* Configure DMA channel */
                Ret = Dma_Drv_ChannelConfigure(&DmaChannelConfig[Linu_PubResources[Linu_PubMap[HwUnit]].dma_rx->LinDmaConfigId],
                    Length,
                    (uint32)&Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRM,
                    (uint32)RxBuf,
                    Linu_PubResources[Linu_PubMap[HwUnit]].dma_rx->cb_event);
                if (Ret == TT_RET_SUCCESS)
                {
                    /* Enable DMA Receive */
                    Linu_PubResources[Linu_PubMap[HwUnit]].reg->DMARXE = 1U;
                }
                else
                {
                    Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy = 0U;
                    Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
                }
            }
            else
        #endif
            {
                Ret = Linu_Hw_PriIrqReceive(HwUnit);
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
 * @brief      :  Service to get status of the UART
 * @details    :  Service to get status of the UART
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  UartStatus  - The current status of the uart is
 *                             uninitialized, idle and Busy.
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get status command accepted
 *             :  E_NOT_OK: Get status not accepted
 *
 **/
TT_RetType Linu_Hw_GetStatus(TT_CONST uint8 HwUnit, Uart_StatusType* Status)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_ParaCheck(((HwUnit >= LIN_CONTROLLER_COUNT)||(Linu_PubMap[HwUnit] >= LIN_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((NULL_PTR == Status), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (Linu_PubResources[Linu_PubMap[HwUnit]].info == NULL_PTR), TT_RET_PARAM_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        *Status = Linu_PubResources[Linu_PubMap[HwUnit]].info->flags;
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/**
 * @brief      :  Get the receiving error message
 * @details    :  Get the receiving error message
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  ErrorInfo  - Get the receiving error message
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Get status command accepted
 *             :  E_NOT_OK: Get status not accepted
 *
 **/
TT_RetType Linu_Hw_GetErrorStatus(TT_CONST uint8 HwUnit, uint32* ErrorInfo)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((HwUnit >= LIN_CONTROLLER_COUNT)||(Linu_PubMap[HwUnit] >= LIN_CONTROLLER_COUNT)), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((ErrorInfo == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Ret != TT_RET_SUCCESS) || (*ErrorInfo != 0), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck(((Ret != TT_RET_SUCCESS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info == NULL_PTR)), TT_RET_PARAM_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {

        if(Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_nf == 1U)
         {
            *ErrorInfo |= (uint32)TT_USART_EVENT_RX_NOISE_ERROR;
         }
         else
         {
             /* do nothing */
         }

         /* Timeout */

         if(Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_timeout == 1U)
         {
             *ErrorInfo |= (uint32)TT_USART_EVENT_RX_TIMEOUT_ERROR;
         }
         else
         {
             /* do nothing */
         }

         /* OverRun error */
         if(Linu_PubResources[Linu_PubMap[HwUnit]].info->status.buffer_overrun == 1U)
         {
             *ErrorInfo |= (uint32)TT_USART_EVENT_RX_OVERFLOW;
         }
         else
         {
             /* do nothing */
         }

         /* Framing error */
         if(Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_framing_error == 1U)
         {
             *ErrorInfo |= (uint32)TT_USART_EVENT_RX_FRAMING_ERROR;
         }
         else
         {
             /* do nothing */
         }

         /* Parity error */
         if(Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_parity_error == 1U)
         {
             *ErrorInfo |= (uint32)TT_USART_EVENT_RX_PARITY_ERROR;
         }
         else
         {
             /* do nothing */
         }


         /* Output compare error */
         if(Linu_PubResources[Linu_PubMap[HwUnit]].info->status.oc_error == 1U)
         {
             *ErrorInfo |= (uint32)TT_USART_EVENT_RX_OUTPUT_COMPARE_ERROR;
         }
         else
         {
             /* do nothing */
         }

         /* Stuck at zero error */

         if(Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_szf == 1U)
         {
             *ErrorInfo |= (uint32)TT_USART_EVENT_RX_STUCK_AT_ZERO_ERROR;
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

#if(LIN_IRQ_ENABLE == STD_ON)
#ifdef LIN0_IRQ_ENABLE
/**
 * @brief      : UART Interrupt handler.
 * @details    : UART Interrupt handler.
 *
 * @param[in]  : None
 * @param[out] : None
 *
 * @return     : void
 * @retval     : None
 *
 **/
ISR(LIN0_IRQHandler);
ISR(LIN0_IRQHandler)
{
    Linu_Hw_PriIrqHandler(0);
}
#endif

#ifdef LIN1_IRQ_ENABLE
ISR(LIN1_IRQHandler);
ISR(LIN1_IRQHandler)
{
    Linu_Hw_PriIrqHandler(1);
}
#endif

#ifdef LIN2_IRQ_ENABLE
ISR(LIN2_IRQHandler);
ISR(LIN2_IRQHandler)
{
    Linu_Hw_PriIrqHandler(2);
}
#endif

#ifdef LIN3_IRQ_ENABLE
ISR(LIN3_IRQHandler);
ISR(LIN3_IRQHandler)

{
    Linu_Hw_PriIrqHandler(3);
}
#endif

#ifdef LIN4_IRQ_ENABLE
ISR(LIN4_IRQHandler);
ISR(LIN4_IRQHandler)
{
    Linu_Hw_PriIrqHandler(4);
}
#endif

#ifdef LIN5_IRQ_ENABLE
ISR(LIN5_IRQHandler);
ISR(LIN5_IRQHandler)
{
    Linu_Hw_PriIrqHandler(5);
}
#endif

#ifdef LIN6_IRQ_ENABLE
ISR(LIN6_IRQHandler);
ISR(LIN6_IRQHandler)
{
    Linu_Hw_PriIrqHandler(6);
}
#endif

#ifdef LIN7_IRQ_ENABLE
ISR(LIN7_IRQHandler);
ISR(LIN7_IRQHandler)
{
    Linu_Hw_PriIrqHandler(7);
}
#endif

#ifdef LIN8_IRQ_ENABLE
ISR(LIN8_IRQHandler);
ISR(LIN8_IRQHandler)
{
    Linu_Hw_PriIrqHandler(8);
}
#endif

#ifdef LIN9_IRQ_ENABLE
ISR(LIN9_IRQHandler);
ISR(LIN9_IRQHandler)
{
    Linu_Hw_PriIrqHandler(9);
}
#endif

#ifdef LIN10_IRQ_ENABLE
ISR(LIN10_IRQHandler);
ISR(LIN10_IRQHandler)
{
    Linu_Hw_PriIrqHandler(10);
}
#endif

#ifdef LIN11_IRQ_ENABLE
ISR(LIN11_IRQHandler);
ISR(LIN11_IRQHandler)
{
    Linu_Hw_PriIrqHandler(11);
}
#endif

#ifdef LIN12_IRQ_ENABLE
ISR(LIN12_IRQHandler);
ISR(LIN12_IRQHandler)
{
    Linu_Hw_PriIrqHandler(12);
}
#endif

#ifdef LIN13_IRQ_ENABLE
ISR(LIN13_IRQHandler);
ISR(LIN13_IRQHandler)
{
    Linu_Hw_PriIrqHandler(13);
}
#endif

#ifdef LIN14_IRQ_ENABLE
ISR(LIN14_IRQHandler);
ISR(LIN14_IRQHandler)
{
    Linu_Hw_PriIrqHandler(14);
}
#endif

#ifdef LIN15_IRQ_ENABLE
ISR(LIN15_IRQHandler);
ISR(LIN15_IRQHandler)
{
    Linu_Hw_PriIrqHandler(15);
}
#endif
#endif/*LIN_IRQ_ENABLE */
#define UART_STOP_SEC_CODE_FAST
#include "Uart_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/
#define UART_START_SEC_CODE_SLOW
#include "Uart_MemMap.h"
/**
 * @brief      :  Gets the peripheral clock
 * @details    :  Gets the peripheral clock
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware
 * @param[out] :  LinSysClk - Store the peripheral clock
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriGetPeriphClk(uint8 HwUnit,uint32* LinSysClk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_ParaCheck(((uint8)LIN_CONTROLLER_COUNT <= (uint8)HwUnit), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Drv_Clk_GetPeriph(Linu_PubGetClk[HwUnit], LinSysClk);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief      :  Turn on peripheral clock
 * @details    :  Turn on peripheral clock
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriStartClk(uint8 HwUnit)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_ParaCheck(((uint8)LIN_CONTROLLER_COUNT<= (uint8)HwUnit), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        Ret = Mcu_Drv_Clk_StartModules(Linu_MapStartStopClk[HwUnit]);

    }
    else
    {
        /* do nothing */
    }


    return Ret;
}

/**
 * @brief      :  Disable the Uart clock
 * @details    :  Disable the Uart clock
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriStopClk(uint8 HwUnit)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Ret = Mcu_Drv_Clk_StopModules(Linu_MapStartStopClk[HwUnit]);
    return Ret;
}

/**
 * @brief      :  Map Linu_PubMap to  Linu_PubResources
 * @details    :  The subscript of the Linu_PubMap array indicates the corresponding Lin0 to Lin15,
 *                and the member value of the Linu_PubMap array is the array subscript of Linu_PubResources.
 *                Linu_PubResources[Linu_PubMap[LINU_0]] Indirectly accesses hardware resources corresponding to the serial port
 *
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Map command accepted
 *             :  Other: Map command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriMapsort(TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 HwUnit = 0;
    uint8 i = 0;
    uint8 j =0;
    uint8 Map_Sort = 0;

    if(NULL_PTR != CfgPtr)
    {
        /* Gets the initialized LINU */
        for(i = UART_CONFIGED_COUNT;i < ALL_CONTROLLER_COUNT; i++)
        {
          HwUnit =(uint8)CfgPtr->CtrlCfgPtr[i].HwUnit - (uint8)LINU_0;

          if(LIN_CONTROLLER_COUNT > HwUnit)
          {
              Linu_PubMap[HwUnit] = j;
              j++;
          }
          else
          {
              Ret = TT_RET_PARAM_INVALID_DATA_ERR;
              break;
          }

        }

        if(TT_RET_SUCCESS ==  Ret)
        {
            /* mapping relation */
            for(i = 0;i < LIN_CONTROLLER_COUNT; i++)
            {
              if(Linu_PubMap[i] != 0xFFU)
              {
                  Linu_PubMap[i] = Map_Sort;
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

        }
    }
    else
    {
       Ret =  TT_RET_PARAM_NULL_PTR_ERR;
    }
    return Ret;
}
/**
 * @brief      :  Set Lin-Uart Low data bits
 * @details    :  Set Lin-Uart Low data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumCharFrame  - Data bit pattern
 *                ParityType - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriSetLowData(uint8 HwUnit,uint8 NumCharFrame,uint8 ParityType)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if((uint8)LIN_UART_SEVEN_BITS == NumCharFrame)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_VAL2FLD(TT_LIN_UARTCR_WL1, 0) | TT_VAL2FLD(TT_LIN_UARTCR_WL0, 0);

        if(((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_RFBM_Msk) == 0) && ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_TFBM_Msk) == 0))
       {
            /* define transmit/receive number of bytes is 1 byte */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)TT_VAL2FLD(TT_LIN_UARTCR_TDFL_TFC, 0);
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)TT_VAL2FLD(TT_LIN_UARTCR_RDFL_RFC, 0);
        }
        else
        {
            /* do nothing */
        }
        /* must be enable parity control */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_PCE_Msk;
    }
    else if((uint8)LIN_UART_EIGHT_BITS == NumCharFrame)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_VAL2FLD(TT_LIN_UARTCR_WL1, 0) | TT_VAL2FLD(TT_LIN_UARTCR_WL0, 1);

        if(((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_RFBM_Msk) == 0) && ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_TFBM_Msk) == 0))
        {
            /* define transmit/receive number of bytes is 1 byte */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)TT_VAL2FLD(TT_LIN_UARTCR_TDFL_TFC, 0);
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)TT_VAL2FLD(TT_LIN_UARTCR_RDFL_RFC, 0);
        }
        else
        {
        /* do nothing */
        }

        if (ParityType != (uint8)LIN_UART_NO_PARITY) /* parity control */
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_PCE_Msk;
        }
        else
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_PCE_Msk;
        }
    }
    else
    {
        Ret = TT_RET_STATUS_ERR;
    }

    return Ret;
}

/**
 * @brief      :  Set Lin-Uart Hingh data bits
 * @details    :  Set Lin-Uart Low data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumCharFrame  - Data bit pattern
 *                ParityType - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriSetHighBits(uint8 HwUnit,uint8 NumCharFrame,uint8 ParityType)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if((uint8)LIN_UART_FIFTEEN_BITS == NumCharFrame)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_VAL2FLD(TT_LIN_UARTCR_WL1, 1) | TT_VAL2FLD(TT_LIN_UARTCR_WL0, 0);

        if(((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_RFBM_Msk) == 0) && ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_TFBM_Msk) == 0))
        {
            /* define transmit/receive number of bytes is 2 byte */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)TT_VAL2FLD(TT_LIN_UARTCR_TDFL_TFC, 1);
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)TT_VAL2FLD(TT_LIN_UARTCR_RDFL_RFC, 1);
        }

        /* must be enable parity control */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_PCE_Msk;
    }
    else if((uint8)LIN_UART_SIXTEEN_BITS == NumCharFrame)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_VAL2FLD(TT_LIN_UARTCR_WL1, 1) | TT_VAL2FLD(TT_LIN_UARTCR_WL0, 1);

        if(((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_RFBM_Msk) == 0) &&
            (Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_TFBM_Msk) == 0)
        {
            /* define transmit/receive number of bytes is 2 byte */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)TT_VAL2FLD(TT_LIN_UARTCR_TDFL_TFC, 1);
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)TT_VAL2FLD(TT_LIN_UARTCR_RDFL_RFC, 1);
        }
        else
        {
            /* do nothing */
        }

        if (ParityType != (uint8)LIN_UART_NO_PARITY) /* parity control */
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_PCE_Msk;
        }
        else
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_PCE_Msk;
        }
        /* only in the 16bits support WLS=1 transfer */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= TT_LIN_UARTCR_WLS_Msk;
    }
    else
    {
        Ret = TT_RET_STATUS_ERR;
    }

    return Ret;
}

/**
 * @brief      :  Set Lin-Uart several data bits
 * @details    :  Set Lin-Uart several data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                NumCharFrame  - Data bit pattern
 *                ParityType - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriSetdatabits(uint8 HwUnit,uint8 NumCharFrame,uint8 ParityType)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if((uint8)LIN_UART_EIGHT_BITS >= NumCharFrame)
    {
        Ret = Linu_Hw_PriSetLowData(HwUnit,NumCharFrame,ParityType);
    }
    else if((uint8)LIN_UART_SIXTEEN_BITS >= NumCharFrame)
    {
        Ret = Linu_Hw_PriSetHighBits(HwUnit,NumCharFrame,ParityType);
    }
    else
    {
        Ret = TT_RET_PARAM_ENUM_ERR;
    }

   return Ret;
}

/**
 * @brief      :  Set Lin-Uart several data bits
 * @details    :  Set Lin-Uart several data bits
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 *                ParityType - Parity pattern
 * @param[out] :  None
 *
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Set command accepted
 *             :  Other: Set command not accepted
 *
 **/
static TT_RetType Linu_Hw_PriSetParity(uint8 HwUnit,uint8 ParityType)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    switch (ParityType)
    {
    case (uint8)LIN_UART_EVEN_PARITY:
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)(0UL << TT_LIN_UARTCR_PC1_Pos) | (0UL << TT_LIN_UARTCR_PC0_Pos);
        break;

    case (uint8)LIN_UART_ODD_PARITY:
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)(0UL << TT_LIN_UARTCR_PC1_Pos) | (1UL << TT_LIN_UARTCR_PC0_Pos);
        break;

    case (uint8)LIN_UART_ZERO_PARITY:
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)(1UL << TT_LIN_UARTCR_PC1_Pos) | (0UL << TT_LIN_UARTCR_PC0_Pos);
        break;

    case (uint8)LIN_UART_ONE_PARITY:
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)(1UL << TT_LIN_UARTCR_PC1_Pos) | (1UL << TT_LIN_UARTCR_PC0_Pos);
        break;

    default:
        Ret = TT_RET_PARAM_ENUM_ERR;
        break;
    }


    return Ret;

}

/**
 * @brief      :  Set Lin-Uart Stop bits
 * @details    :  Set Lin-Uart Stop bits
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
static TT_RetType Linu_Hw_PriSetstopbits(uint8 HwUnit,uint8 NumStopBits)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    switch (NumStopBits)
    {
    case (uint8)LIN_UART_ONE_STOPBIT:
        /* receive stop bits */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)(0UL << TT_LIN_UARTCR_SBUR_Pos);
        /* transmit stop bits */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->GCR |= TT_VAL2FLD(TT_LIN_GCR_STOP, 0);
        break;

    case (uint8)LIN_UART_TWO_STOPBITS:
        /* receive stop bits */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)(1UL << TT_LIN_UARTCR_SBUR_Pos);
        /* transmit stop bits */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->GCR |= TT_VAL2FLD(TT_LIN_GCR_STOP, 1);
        break;

    case (uint8)LIN_UART_THREE_STOPBITS:
        /* receive stop bits */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (uint32)(2UL << TT_LIN_UARTCR_SBUR_Pos);
        break;
    default:
        Ret = TT_RET_PARAM_ENUM_ERR;
        break;
    }

    return Ret;
}

/**
 * @brief      :  Example Set the Lin-Uart mode
 * @details    :  Example Set the Lin-Uart mode
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
static TT_RetType Linu_Hw_PriSetMode(uint8 flag ,uint8 HwUnit,TT_CONST Uart_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;


    if (Linu_PubResources[Linu_PubMap[HwUnit]].work_mode == TT_USART_WORK_DMA)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (TT_VAL2FLD(TT_LIN_UARTCR_RFBM, 1U) | \
            TT_VAL2FLD(TT_LIN_UARTCR_TFBM, 1U));  /* FIFO mode */
    }
    else
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR |= (TT_VAL2FLD(TT_LIN_UARTCR_RFBM, 0U) | \
        TT_VAL2FLD(TT_LIN_UARTCR_TFBM, 0U));  /* Buffer mode */
    }

    /* configure data bits */
    Ret = Linu_Hw_PriSetdatabits(HwUnit,CfgPtr->CtrlCfgPtr[flag].NumCharFrame,CfgPtr->CtrlCfgPtr[flag].ParityType);

    /* configure parity type */
    if((TT_RET_SUCCESS == Ret) &&(Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_PCE_Msk) != 0)
    {
        Ret = Linu_Hw_PriSetParity(HwUnit,CfgPtr->CtrlCfgPtr[flag].ParityType);
    }
    else
    {
        /* do nothing */
    }

    if(TT_RET_SUCCESS == Ret)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType = CfgPtr->CtrlCfgPtr[flag].NumCharFrame;
        /* configure Stop bits */
        Ret = Linu_Hw_PriSetstopbits(HwUnit,CfgPtr->CtrlCfgPtr[flag].NumStopBits);
    }
    else
    {

    }

    if(TT_RET_SUCCESS == Ret)
    {
        /* Set Baudrate */
        Ret = Linu_Hw_SetBaudrate(HwUnit, CfgPtr->CtrlCfgPtr[flag].Baudrate);
    }
    else
    {

    }

    return Ret;
}

#if(LIN_DMA_ENABLE == STD_ON)
/**
 * @brief      : UART DMA Interrupt handler.
 * @details    : UART DMA Interrupt handler.
 *
 * @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
 *               event - GPDMA_EVENT_TERMINAL_COUNT_REQUEST / GPDMA_EVENT_ERROR
 * @param[out] : None
 *
 * @return     : void
 * @retval     : None
 *
 **/
static void Linu_Hw_PriDmaTxEvent(TT_CONST uint8 HwUnit, uint32 event)
{
    switch (event)
    {
    case DMA_EVENT_TERMINAL_COUNT_REQUEST:
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->DMATXE = 0;

        if (Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR == TT_LIN_UARTCR_UART_Msk)
        {
            /* disable TX */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_TxEn_Msk;
        }
        else
        {
            /* do nothing */
        }

        Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt = Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_num;
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy = 0U;
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINSR |= TT_LIN_LINSR_DTF_Msk;
        Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;

        if (Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event != NULL_PTR)
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event(TT_USART_EVENT_SEND_COMPLETE);
        }
        else
        {
            /* do nothing */
        }
        break;

    case DMA_EVENT_ERROR:   /* nothing */
        if (Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event != NULL_PTR)
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event(TT_USART_EVENT_SEND_INCOMPLETE);
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
 *               event - GPDMA_EVENT_TERMINAL_COUNT_REQUEST / GPDMA_EVENT_ERROR
 * @param[out] : None
 *
 * @return     : void
 * @retval     : None
 *
 **/
static void Linu_Hw_PriDmaRxEvent(uint8 HwUnit, uint32 event)
{
    switch (event)
    {
    case (uint32)DMA_EVENT_TERMINAL_COUNT_REQUEST:
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->DMARXE = 0;

        if (Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR == TT_LIN_UARTCR_UART_Msk)
        {
            /* disable RX */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_RxEn_Msk;
        }
        else
        {
            /* do nothing */
        }

        Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt = Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_num;
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy = 0U;
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINSR |= TT_LIN_LINSR_DRF_Msk | TT_LIN_LINSR_DRBNE_Msk | TT_LIN_UARTSR_RMB_Msk;
        Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;

        if (Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event != NULL_PTR)
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event(TT_USART_EVENT_RECEIVE_COMPLETE);
        }
        else
        {
            /* do nothing */
        }
        break;

    case (uint32)DMA_EVENT_ERROR:
        if (Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event != NULL_PTR)
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event(TT_USART_EVENT_SEND_INCOMPLETE);
        }
        else
        {
            /* do nothing */
        }
        break;
    default:
        /* do nothing */
        break;
    }
}

#ifdef LIN0_DMA_ENABLE
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
static void Linu_Hw_PriDmaTx0(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(0, event);
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
static void Linu_Hw_PriDmaRx0(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(0, event);
}
#endif

#ifdef LIN1_DMA_ENABLE
static void Linu_Hw_PriDmaTx1(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(1, event);
}
static void Linu_Hw_PriDmaRx1(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(1, event);
}
#endif

#ifdef LIN2_DMA_ENABLE
static void Linu_Hw_PriDmaTx2(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(2, event);
}
static void Linu_Hw_PriDmaRx2(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(2, event);
}
#endif

#ifdef LIN3_DMA_ENABLE
static void Linu_Hw_PriDmaTx3(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(3, event);
}
static void Linu_Hw_PriDmaRx3(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(3, event);
}
#endif

#ifdef LIN4_DMA_ENABLE
static void Linu_Hw_PriDmaTx4(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(4, event);
}
static void Linu_Hw_PriDmaRx4(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(4, event);
}
#endif

#ifdef LIN5_DMA_ENABLE
static void Linu_Hw_PriDmaTx5(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(5, event);
}
static void Linu_Hw_PriDmaRx5(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(5, event);
}
#endif

#ifdef LIN6_DMA_ENABLE
static void Linu_Hw_PriDmaTx6(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(6, event);
}
static void Linu_Hw_PriDmaRx6(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(6, event);
}
#endif

#ifdef LIN7_DMA_ENABLE
static void Linu_Hw_PriDmaTx7(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(7, event);
}
static void Linu_Hw_PriDmaRx7(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(7, event);
}
#endif

#ifdef LIN8_DMA_ENABLE
static void Linu_Hw_PriDmaTx8(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(8, event);
}
static void Linu_Hw_PriDmaRx8(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(8, event);
}
#endif

#ifdef LIN9_DMA_ENABLE
static void Linu_Hw_PriDmaTx9(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(9, event);
}
static void Linu_Hw_PriDmaRx9(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(9, event);
}
#endif

#ifdef LIN10_DMA_ENABLE
static void Linu_Hw_PriDmaTx10(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(10, event);
}
static void Linu_Hw_PriDmaRx10(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(10, event);
}
#endif

#ifdef LIN11_DMA_ENABLE
static void Linu_Hw_PriDmaTx11(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(11, event);
}
static void Linu_Hw_PriDmaRx11(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(11, event);
}
#endif

#ifdef LIN12_DMA_ENABLE
static void Linu_Hw_PriDmaTx12(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(12, event);
}
static void Linu_Hw_PriDmaRx12(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(12, event);
}
#endif

#ifdef LIN13_DMA_ENABLE
static void Linu_Hw_PriDmaTx13(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(13, event);
}
static void Linu_Hw_PriDmaRx13(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(13, event);
}
#endif

#ifdef LIN14_DMA_ENABLE
static void Linu_Hw_PriDmaTx14(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(14, event);
}
static void Linu_Hw_PriDmaRx14(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(14, event);
}
#endif

#ifdef LIN15_DMA_ENABLE
static void Linu_Hw_PriDmaTx15(uint32 event)
{
    Linu_Hw_PriDmaTxEvent(15, event);
}
static void Linu_Hw_PriDmaRx15(uint32 event)
{
    Linu_Hw_PriDmaRxEvent(15, event);
}
#endif
#endif/* if defined(LIN_DMA_ENABLE.... */

#define UART_STOP_SEC_CODE_SLOW
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE_FAST
#include "Uart_MemMap.h"
/**
* @brief      :  Fill data into the data register
* @details    :  Fill data into the data register
*
* @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
*                LenType - data bits
* @param[out] :  None
*
* @return     :  void
* @retval     :  None
*
**/
static void Linu_Hw_PriWriteData(uint8 HwUnit,uint8 LenType)
{
   uint32 regValTemp = 0;
   if ((LenType == (uint8)LIN_UART_SEVEN_BITS) || (LenType == (uint8)LIN_UART_EIGHT_BITS)) /* data length 7/8 */
   {
       regValTemp = Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRL;
       regValTemp &= ~TT_LIN_BDRL_DATA0_Msk;
       regValTemp |= *Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_buf;
       Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRL = regValTemp;

       ++Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_buf;
       ++Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt;
   }
   else if ((LenType == (uint8)LIN_UART_FIFTEEN_BITS) || (LenType == (uint8)LIN_UART_SIXTEEN_BITS)) /* data length 15/16 */
   {
       regValTemp = Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRL;
       regValTemp &= ~(TT_LIN_BDRL_DATA0_Msk | TT_LIN_BDRL_DATA1_Msk);
       regValTemp |= (((uint32)(Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_buf[0])) | (((uint32)(Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_buf[1])) << 8U));
       Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRL = regValTemp;

       Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_buf += 2;
       Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt += 2;
   }
   else
   {
       /* do nothing */
   }
}

/**
* @brief      :  Lin-Uart IRQ Receive
* @details    :  Lin-Uart IRQ Receive
*
* @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
* @param[out] :  None
*
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Receive command accepted
*             :  Other: Receive command not accepted
*
**/
static TT_RetType Linu_Hw_PriIrqReceive(TT_CONST uint8 HwUnit)
{
   TT_RetType Ret = TT_RET_SUCCESS;

   if((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_RFBM_Msk) != 0)
   {
       Ret = TT_RET_STATUS_ERR;
   }
   else
   {
       /* do nothing */
   }
   if(TT_RET_SUCCESS == Ret)
   {
       /* in buffer mode, can't receive 12bits data frame */
       if((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR & TT_LIN_UARTCR_WLS_Msk) != 0)
       {
           Ret = TT_RET_STATUS_ERR;
       }
       else
       {
           /* do nothing */
       }

       /* enable RX interrput */
       Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER |= TT_LIN_LINIER_DRIE_Msk;
       Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER |= UART_ERROR_ALL_INT;

   }


   return Ret;
}

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
static uint32 Linu_Hw_PriRxLineInt(TT_CONST uint8 HwUnit)
{
    uint32 rsr = 0;
    uint32 event = 0;

    rsr = Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR;

    /* Noise error */
    if((rsr & TT_LIN_UARTSR_NF_Msk) == TT_LIN_UARTSR_NF_Msk)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_nf = 1U;
        event |= (uint32)TT_USART_EVENT_RX_NOISE_ERROR;
    }
    else
    {
        /* do nothing */
    }

    /* Timeout */

    if((rsr & TT_LIN_UARTSR_TO_Msk) == TT_LIN_UARTSR_TO_Msk)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_timeout = 1U;
        event |= (uint32)TT_USART_EVENT_RX_TIMEOUT_ERROR;
    }
    else
    {
        /* do nothing */
    }

    /* OverRun error */
    if((rsr & TT_LIN_UARTSR_BOF_Msk) == TT_LIN_UARTSR_BOF_Msk)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.buffer_overrun = 1U;
        event |= (uint32)TT_USART_EVENT_RX_OVERFLOW;
    }
    else
    {
        /* do nothing */
    }

    /* Framing error */
    if((rsr & TT_LIN_UARTSR_FEF_Msk) == TT_LIN_UARTSR_FEF_Msk)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_framing_error = 1U;
        event |= (uint32)TT_USART_EVENT_RX_FRAMING_ERROR;
    }
    else
    {
        /* do nothing */
    }

    /* Parity error */
    if((rsr & TT_LIN_UARTSR_PE_Msk) == TT_LIN_UARTSR_PE_Msk)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_parity_error = 1U;
        event |= (uint32)TT_USART_EVENT_RX_PARITY_ERROR;
    }
    else
    {
        /* do nothing */
    }


    /* Output compare error */
    if((rsr & TT_LIN_UARTSR_OCF_Msk) == TT_LIN_UARTSR_OCF_Msk)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.oc_error = 1U;
        event |= (uint32)TT_USART_EVENT_RX_OUTPUT_COMPARE_ERROR;
    }
    else
    {
        /* do nothing */
    }

    /* Stuck at zero error */

    if((rsr & TT_LIN_UARTSR_SZF_Msk) == TT_LIN_UARTSR_SZF_Msk)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_szf = 1U;
        event |= (uint32)TT_USART_EVENT_RX_STUCK_AT_ZERO_ERROR;
    }
    else
    {
        /* do nothing */
    }

    return event;
}
#if(LIN_IRQ_ENABLE == STD_ON)
/**
 * @brief      :  LIN Combine Interrupt Receive handler.
 * @details    :  USART Combine Interrupt Receive handler.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static uint32 Linu_Hw_PriReceiveHandler(TT_CONST uint8 HwUnit)
{

    uint32 event = 0;

    Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DRFRFE_Msk;
    if ((Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType == (uint8)LIN_UART_SEVEN_BITS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType == (uint8)LIN_UART_EIGHT_BITS)) /* data length 7/8 */
    {
        *(Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf) = (uint8)(Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRM);
        ++Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf;
        ++Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt;
    }
    else if ((Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType == (uint8)LIN_UART_FIFTEEN_BITS) || (Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType == (uint8)LIN_UART_SIXTEEN_BITS)) /* data length 15/16 */
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf[0] = (uint8)(Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRM);
        Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf[1] = (uint8)(Linu_PubResources[Linu_PubMap[HwUnit]].reg->BDRM >> 8U);
        Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_buf += 2;
        Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt += 2;
    }
    else
    {
        /* do nothing */
    }

    /* Check if requested amount of data is received */
    if (Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt == Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_num)
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->status.rx_busy = 0U;

        /* clear flags and disable RX */
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= (TT_LIN_UARTSR_DRFRFE_Msk | TT_LIN_UARTSR_RMB_Msk);

        Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER &= ~TT_LIN_LINIER_DRIE_Msk;
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_RxEn_Msk;

        Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;

        event |= (uint32)TT_USART_EVENT_RECEIVE_COMPLETE;
    }
    else if (Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_cnt > Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.rx_num)
    {
        event |= (uint32)TT_USART_EVENT_RX_OVERFLOW;
    }
    else
    {
        /* do nothing */
    }
    return event;

}

/**
 * @brief      :  LIN Combine Interrupt handler.
 * @details    :  USART Combine Interrupt handler.
 *
 * @param[in]  :  HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] :  None
 *
 * @return     :  void
 * @retval     :  None
 *
 **/
static void Linu_Hw_PriIrqHandler(TT_CONST uint8 HwUnit)
{
    uint32 event = 0;
    uint32 sr = (uint32)0;

    sr = Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR;
    /* Transmit Interrupt */
    if ((sr & TT_LIN_UARTSR_DTFTFF_Msk) != 0)
    {
        if (Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_num > Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt)
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= (uint8)TT_LIN_UARTSR_DTFTFF_Msk;
            Linu_Hw_PriWriteData(HwUnit,Linu_PubResources[Linu_PubMap[HwUnit]].info->LenType);
        }
        else
        {
            /* do nothing */
        }
        if (Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_num == Linu_PubResources[Linu_PubMap[HwUnit]].info->xfer.tx_cnt)
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].info->status.tx_busy = 0U;

            /* clear DTF flag and disable TX */
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= TT_LIN_UARTSR_DTFTFF_Msk;
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER &= ~TT_LIN_LINIER_DTIE_Msk;
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTCR &= ~TT_LIN_UARTCR_TxEn_Msk;
            Linu_PubResources[Linu_PubMap[HwUnit]].info->flags = UART_STATUS_IDLE;
            event |= (uint32)TT_USART_EVENT_SEND_COMPLETE;
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

    /* Receive data available interrupt */
    if ((sr & TT_LIN_UARTSR_DRFRFE_Msk) != 0)
    {
        event |= Linu_Hw_PriReceiveHandler(HwUnit);
    }
    else
    {
        /* do nothing */
    }

    /* deal with error interrupt */
    if ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR & UART_ALL_ERROR_FLAG) != 0)
    {
        event |= Linu_Hw_PriRxLineInt(HwUnit);
        Linu_PubResources[Linu_PubMap[HwUnit]].reg->UARTSR |= UART_ALL_ERROR_FLAG;

        /* Clear all error interrupts in IER register */
        if ((Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER & UART_ERROR_ALL_INT) != 0U)
        {
            Linu_PubResources[Linu_PubMap[HwUnit]].reg->LINIER &= ~UART_ERROR_ALL_INT;
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

    if((Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event != NULL_PTR) && (event != 0))
    {
        Linu_PubResources[Linu_PubMap[HwUnit]].info->cb_event(event);
    }
    else
    {
        /* do nothing */
    }
}
#define UART_STOP_SEC_CODE_FAST
#include "Uart_MemMap.h"
#endif
#endif/* LIN_UART_ENABLE == STD_ON */

#ifdef __cplusplus
}
#endif

