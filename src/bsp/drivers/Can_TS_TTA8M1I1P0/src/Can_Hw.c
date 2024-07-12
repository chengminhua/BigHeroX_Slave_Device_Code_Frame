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
**  FILENAME     : Can_Hw.c                                                   **
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
#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Hw.h"
#include "Can_Hw_Irq.h"
#include "Can_Hw_Cfg.h"
#include "Mcu_Drv.h"
#include "string.h"
#include "Mcu_Hw_Ppu.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_VENDOR_ID_C                      1541
#define FLEXCAN_HW_MODULE_ID_C                      80
#define FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_C       4
#define FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_C       0
#define FLEXCAN_HW_SW_MAJOR_VERSION_C               1
#define FLEXCAN_HW_SW_MINOR_VERSION_C               1
#define FLEXCAN_HW_SW_PATCH_VERSION_C               0
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and Can_Hw.h header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_C != FLEXCAN_HW_VENDOR_ID_H)
    #error "Can_Hw.c and Can_Hw.h have different vendor ids"
#endif
#if (FLEXCAN_HW_MODULE_ID_C != FLEXCAN_HW_MODULE_ID_H)
    #error "Can_Hw.c and Can_Hw.h  have different module ids"
#endif
/* Check if current file and FlexCAN_Hw.h header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_C != FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.c and Can_Hw.h are different"
#endif
/* Check if current file and FlexCAN_Hw.h header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_C != FLEXCAN_HW_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_C != FLEXCAN_HW_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_C != FLEXCAN_HW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.c and Can_Hw.h are different"
#endif

/* Check if current file and Can_Hw_Irq.h header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_C != FLEXCAN_HW_IRQ_VENDOR_ID_H)
    #error "Can_Hw.c and Can_Hw_Irq.h have different vendor ids"
#endif
/* Check if current file and Can_Hw_Irq.h header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_HW_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_HW_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_C != FLEXCAN_HW_IRQ_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.c and Can_Hw_Irq.h are different"
#endif
/* Check if current file and Can_Hw_Irq.h header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_C != FLEXCAN_HW_IRQ_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_C != FLEXCAN_HW_IRQ_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_C != FLEXCAN_HW_IRQ_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.c and Can_Hw_Irq.h are different"
#endif

/* Check if current file and Can_Hw_Cfg.h header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_C != FLEXCAN_HW_CFG_VENDOR_ID_H)
    #error "Can_Hw.c and Can_Hw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_Hw_Cfg.h header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_HW_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_HW_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_C != FLEXCAN_HW_CFG_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.c and Can_Hw_Cfg.h are different"
#endif
/* Check if current file and Can_Hw_Cfg.h header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_C != FLEXCAN_HW_CFG_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_C != FLEXCAN_HW_CFG_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_C != FLEXCAN_HW_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.c and Can_Hw_Cfg.h are different"
#endif

    /* Check if current file and Mcu_Drv.h header file are of the same Autosar version */
    #if (FLEXCAN_HW_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
        #error "Can_Hw.h and Mcu_Drv.h have different vendor ids"
    #endif
    #if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_C    != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
         (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_C    != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
         (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
        #error "AutoSar Version Numbers of Can_Hw.h and Mcu_Drv.h are different"
    #endif
    /* Check if current file and Mcu_Drv.h header file are of the same Software version */
    #if ((FLEXCAN_HW_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
         (FLEXCAN_HW_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
         (FLEXCAN_HW_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H) )
        #error "Software Version Numbers of Can_Hw.h and Mcu_Drv.h are different"
    #endif

/* Check if current file and Mcu_Hw_Ppu.h header file are of the same vendor */
#if (FLEXCAN_HW_VENDOR_ID_C != MCU_HW_PPU_VENDOR_ID_H)
    #error "Can_Hw.c and Mcu_Hw_Ppu.h have different vendor ids"
#endif
/* Check if current file and Mcu_Hw_Ppu.h header file are of the same Autosar version */
#if ((FLEXCAN_HW_AR_RELEASE_MAJOR_VERSION_C    != MCU_HW_PPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_MINOR_VERSION_C    != MCU_HW_PPU_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_AR_RELEASE_PATCH_VERSION_C != MCU_HW_PPU_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw.c and Mcu_Hw_Ppu.h are different"
#endif
/* Check if current file and Mcu_Hw_Ppu.h header file are of the same Software version */
#if ((FLEXCAN_HW_SW_MAJOR_VERSION_C != MCU_HW_PPU_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_SW_MINOR_VERSION_C != MCU_HW_PPU_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_SW_PATCH_VERSION_C != MCU_HW_PPU_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw.c and Mcu_Hw_Ppu.h are different"
#endif
/******************************************************************************
*                            Private Macros
*******************************************************************************/
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/* ENHANCE TRASNFER DIMENSION LIST */
#define FLEXCAN_HW_ENHANCE_TRASNFER_DIMENSION_LIST (13U)
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)  */
/* TRASNFER DIMENSION LIST */
#define FLEXCAN_HW_TRASNFER_DIMENSION_LIST (10U)
#endif /*(FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)*/

/* CAN FD extended data length DLC encoding */
#define FLEXCAN_HW_DLC_VALUE_12_BYTES              9U
#define FLEXCAN_HW_DLC_VALUE_16_BYTES              10U
#define FLEXCAN_HW_DLC_VALUE_20_BYTES              11U
#define FLEXCAN_HW_DLC_VALUE_24_BYTES              12U
#define FLEXCAN_HW_DLC_VALUE_32_BYTES              13U
#define FLEXCAN_HW_DLC_VALUE_48_BYTES              14U
#define FLEXCAN_HW_DLC_VALUE_64_BYTES              15U
/* RXFIFO FILTER TABLE OFFSET */
#define FLEXCAN_HW_RX_FIFO_FILTER_TABLE_OFFSET      0x18U
/* RXFIFO ACCEPT REMOTE FRAME */
#define FLEXCAN_HW_RX_FIFO_ACCEPT_REMOTE_FRAME      1UL
/* RXFIFO ACCEPT EXT FRAME */
#define FLEXCAN_HW_RX_FIFO_ACCEPT_EXT_FRAME         1UL

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/* ENHANCED RXFIFO FILTER TABLE BASE  */
#define FLEXCAN_HW_ENHANCED_RX_FIFO_FILTER_TABLE_BASE       0x0U
#endif

/* Determines the RxFIFO Filter element number */
#define FLEXCAN_HW_RXFIFO_FILTER_ELEM_NUM(x) (((x) + 1U) * 8U)
/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/
#define CAN_START_SEC_CONST_32
#include "Can_MemMap.h"

/* Table of base addresses for CAN instances. */
static TT_CAN_Type * TT_CONST Flexcan_Hw_apxBase[] = IP_FLEXCAN_BASE_PTRS;

#define CAN_STOP_SEC_CONST_32
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_FAST_CLEARED_32
#include "Can_MemMap.h"

/* Save the interrupt mask */
static volatile uint32 FlexCAN_Hw_au32ImaskBuff[FLEXCAN_INSTANCE_COUNT][FLEXCAN_HW_FEATURE_MBDSR_COUNT];

#define CAN_STOP_SEC_VAR_FAST_CLEARED_32
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_PTR
#include "Can_MemMap.h"

/* Pointer to runtime state structure.*/
static Flexcan_Hw_StateType * Flexcan_Hw_apxState[FLEXCAN_INSTANCE_COUNT];
    
#define CAN_STOP_SEC_VAR_CLEARED_PTR
#include "Can_MemMap.h"

/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
/**
* @brief        Initialize fifo and dma if requested
* @details      Initialize fifo and dma if requested
* @param[in]    pBase - The CAN base address
* @param[in]    Flexcan_Hw_pData - Can Hardware Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriInitRxFifo(TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_ConfigType * Flexcan_Hw_pData);

/**
* @brief        Initialize basically controller
* @details      Initialize basically controller
* @param[in]    Instance - CAN Instance
* @param[in]    pBase - The CAN base address
* @param[in]    Flexcan_Hw_pData - Can Hardware Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriInitController(uint8 Instance, TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_ConfigType * Flexcan_Hw_pData);

/**
* @brief        Initialize basically controller
* @details      Initialize basically controller
* @param[in]    pBase - The CAN base address
* @param[in]    Flexcan_Hw_pData - Can Hardware Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriInitCtroll(TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_ConfigType * Flexcan_Hw_pData);

/**
* @brief        The process of receiving data and enabling the interrupt
* @details      Initiate (start) a receive by beginning the process of receiving data and enabling the interrupt
* @param[in]    instance - CAN Instance
* @param[in]    mb_idx - mb index
* @param[in]    data - Data receiving address
* @param[in]    isPolling - Whether polling is enabled
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriStartRxMsgBufferData(uint8 instance,
                                                              uint8 mb_idx,
                                                              Flexcan_Hw_MsgBuffType * data,
                                                              boolean isPolling
                                                             );
/**
* @brief        Initiate (start) a transmit by beginning the process of sending data
* @details      Initiate (start) a transmit by beginning the process of sending data
* @param[in]    Flexcan_Hw_u8Instance - CAN Instance
* @param[in]    mb_idx - mb index
* @param[in]    tx_info - Points to send message data
* @param[in]    msg_id - Message id
* @param[in]    mb_data - Points to send data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriStartSendData(uint8 Flexcan_Hw_u8Instance,
                                                   uint8 mb_idx,
                                                   TT_CONST Flexcan_Hw_DataInfoType * tx_info,
                                                   uint32 msg_id,
                                                   TT_CONST uint8 * mb_data
                                                  );

/**
* @brief        The process of receiving data and enabling the interrupt
* @details      Initiate (start) a receive by beginning the process of receiving data and enabling the interrupt
* @param[in]    instance - CAN Instance
* @param[in]    data - Points to receive data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriStartRxMsgFifoData(uint8 instance, Flexcan_Hw_MsgBuffType * data);

/**
* @brief        IRQ Handler
* @details      Process IRQHandler in case of Rx MessageBuffer selection for CAN interface
* @param[in]    instance - CAN Instance
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriIRQHandlerRxMB(uint8 instance, uint32 mb_idx);

/**
* @brief        IRQ Handler
* @details      Process IRQHandler in case of Tx MessageBuffer selection for CAN interface
* @param[in]    u8Instance - CAN Instance
* @param[in]    u32MbIdx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriIRQHandlerTxMB(uint8 u8Instance, uint32 u32MbIdx);

/**
* @brief        RxFIFO IRQ Handler
* @details      Process IRQHandler in case of RxFIFO mode selection for CAN interface
* @param[in]    instance - CAN Instance
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriIRQHandlerRxFIFO(uint8 instance, uint32 mb_idx);

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
* @brief        DMA mode Callback
* @details      DMA mode Callback
* @param[in]    instance - CAN Instance
* @param[in]    event - Callback event
* @return       void
* @retval       None
*/
static void DMA_Can_Callback(uint8 instance, uint32 event);
#endif

/**
* @brief        AbortTxTransfer
* @details      Abort transfer for Tx buffer
* @param[in]    u8Instance - CAN Instance
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriAbortTxTransfer(uint8 u8Instance, uint8 mb_idx);

/**
* @brief        Abort Rx Transfer
* @details      Abort transfer for Rx normal or legacy fifo if enabled
* @param[in]    u8Instance - CAN Instance
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriAbortRxTransfer(uint8 u8Instance, uint8 mb_idx);

/**
* @brief        The process of receiving data and disabling the interrupt
* @details      Finish up a receive by completing the process of receiving data and disabling the interrupt
* @param[in]    Instance - CAN Instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriCompleteRxMsgFifoData(uint8 instance);

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
* @brief        ENHANCED RxFIFO IRQ Handler
* @details      Process IRQHandler in case of Enhanced RxFIFO mode selection for CAN interface
* @param[in]    instance - CAN Instance
* @param[in]    intType - interrupt Type
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriIRQHandlerEnRxFIFO(uint8 instance, uint32 intType);

/**
* @brief        The process of receiving data and disabling the interrupt
* @details      Finish up a receive by completing the process of receiving data and disabling the interrupt
* @param[in]    Instance - CAN Instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriCompRxMsgEnFifoData(uint8 instance);

/**
* @brief        The process of receiving data and enabling the interrupt
* @details      Initiate (start) a receive by beginning the process of receiving data and enabling the interrupt
* @param[in]    instance - CAN Instance
* @param[in]    data - Data receiving address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriStartRxMsgEnFifoData(uint8 instance, Flexcan_Hw_MsgBuffType * data);

#endif

/**
* @brief        Compute DLC Value
* @details      Compute DLC Value
* @param[in]    payloadSize - payload Size
* @return       uint8
* @retval       DLC Value
*/
static uint8 Can_Hw_PriComputeDLCValue(uint8 payloadSize);

/**
* @brief        Clear RAM
* @details      Clears FlexCAN memory positions that require initialization
* @param[in]    base - CAN Base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriClearRAM(TT_CAN_Type * base);

/**
* @brief        Returns the start of a MB area, based on its index
* @details      Sets the FlexCAN message buffer fields for transmitting
* @param[in]    base - The can base address
* @param[in]    msgBuffIdx - Index of the message buffer
* @param[in]    addr - Pointer to the beginning of the MBs space address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriGetMsgBuffRegion(TT_CONST TT_CAN_Type * base, uint32 msgBuffIdx, volatile uint32 ** addr);

/**
* @brief        Lock the RX message buffer
* @details      Lock the RX message buffer
* @param[in]    base - The can base address
* @param[in]    msgBuffIdx - msgBuff Idx
* @return       void
* @retval       None
*/
LOCAL_INLINE void Can_Hw_PriLockRxMsgBuff(TT_CONST TT_CAN_Type * base,
                           uint32 msgBuffIdx
                          );

/**
* @brief        Gets the message buffer timestamp value
* @details      Gets the message buffer timestamp value
* @param[in]    base - The can base address
* @param[in]    msgBuffIdx - msgBuff Idx
* @return       uint32
* @retval       value of timestamp for selected message buffer
*/
LOCAL_INLINE uint32 Can_Hw_PriGetMsgBuffTimestamp(TT_CONST TT_CAN_Type * base, uint32 msgBuffIdx);

/**
* @brief        Check If mb index is out of range or not
* @details      Check If mb index is out of range or not
* @param[in]    pBase - The FlexCAN base address
* @param[in]    u8MbIndex - MB index
* @param[in]    bIsLegacyFifoEn - Legacy fifo enabled or not
* @param[in]    u32MaxMbNum - Max mb number
* @return       boolean
* @retval       Ture - within the limits of
*               False - out of range
*/
LOCAL_INLINE boolean Can_Hw_PriIsMbOutOfRange
(
    TT_CONST TT_CAN_Type * pBase,
    uint8 u8MbIndex,
    boolean bIsLegacyFifoEn,
    uint32 u32MaxMbNum
);

/**
* @brief        Set operation mode
* @details      Set operation mode
* @param[in]    base - The can base address
* @param[in]    mode - Set an operation mode
* @return       void
* @retval       None
*/
LOCAL_INLINE void Can_Hw_PriSetOperationMode(TT_CAN_Type * base, Flexcan_Hw_ModesType mode);

/**
* @brief        Returns the payload size of the MBs (in bytes)
* @details      Returns the payload size of the MBs (in bytes)
* @param[in]    base - The can base address
* @param[in]    mbdsrIdx - mb Idx
* @param[out]   payloadSize - payload Size
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriGetPayloadSize(TT_CONST TT_CAN_Type * base, uint8 mbdsrIdx, uint8 * payloadSize);

/**
* @brief        Computes the maximum payload size (in bytes), given a DLC
* @details      Computes the maximum payload size (in bytes), given a DLC
* @param[in]    dlcValue - DLC code from the MB memory
* @return       uint8
* @retval       payload size (in bytes)
*/
LOCAL_INLINE uint8 Can_Hw_PriComputePayloadSize(uint8 dlcValue);

/**
* @brief        Computes the maximum RAM size occupied by MBs
* @details      Get The Max no of MBs allowed on CAN instance
* @param[in]    base - The can base address
* @return       uint32
* @retval       The Max No of MBs on the CAN instance
*/
static uint32 Can_Hw_PriGetMaxMbNum(TT_CONST TT_CAN_Type * base);

/**
* @brief        Enter Freeze Mode
* @details      Enter the freeze mode
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnterFreezeMode(TT_CAN_Type * base);

/**
* @brief        Enable Controller
* @details      Enable Controller
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnableController(TT_CAN_Type * base);

/**
* @brief        Enable can
* @details      Enable the clock for FlexCAN Module
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnable(TT_CAN_Type * base);

/**
* @brief        Exit Freeze Mode
* @details      Exit Freeze Mode
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriExitFreezeMode(TT_CAN_Type * base);

/**
* @brief        Disable CAN module
* @details      Disable CAN module
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriDisable(TT_CAN_Type * base);

/**
* @brief        Set Error Int
* @details      Enable the error interrupts
* @param[in]    base - The can base address
* @param[in]    errType - error Type
* @param[in]    enable - enable Error Int
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetErrIntCmd(TT_CAN_Type * base,
                          flexcan_int_type_t errType,
                          boolean enable
                         );

/**
* @brief        Initialize FlexCAN module
* @details      This function will reset FlexCAN module, set maximum number of message
*               buffers, initialize all message buffers as inactive, enable RX FIFO
*               if needed, mask all mask bits, and disable all MB interrupts.
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriInit(TT_CAN_Type * base);

/**
* @brief        Enable Rx FIFO feature
* @details      Enable Rx FIFO feature
* @param[in]    base - The can base address
* @param[in]    numOfFilters - The number of Rx FIFO filters
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnableRxFifo(TT_CAN_Type * base, uint32 numOfFilters);

/**
* @brief        Sets the payload size of the MBs
* @details      Sets the payload size of the MBs
* @param[in]    base - The can base address
* @param[in]    payloadSize - payload Size
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetPayloadSize(TT_CAN_Type * base, TT_CONST Flexcan_Hw_PayloadSizeType * payloadSize);

/**
* @brief        Gets the payload size of the MBs
* @details      Gets the payload size of the MBs
* @param[in]    base - The can base address
* @param[in]    maxMsgBuffNum - max MsgBuff Num
* @param[out]   payloadSize - payload Size
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriGetMbPayloadSize(TT_CONST TT_CAN_Type * base, uint32 maxMsgBuffNum, uint8 * payloadSize);

/**
* @brief        Enables/Disables the FlexCAN Message Buffer interrupt
* @details      Enables/Disables the FlexCAN Message Buffer interrupt
* @param[in]    base - The can base address
* @param[in]    u8Instance - Can Instance
* @param[in]    msgBuffIdx - Index of the message buffer
* @param[in]    enable - choose enable or disable
* @param[in]    bIsIntActive - Int Active
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetMsgBuffIntCmd(TT_CAN_Type * base,
                                               uint8 u8Instance,
                                               uint32 msgBuffIdx,
                                               boolean enable,
                                               boolean bIsIntActive
                                              );

/**
* @brief        Disable the corresponding Message Buffer interrupt only if interrupts are active
* @details      Disable the corresponding Message Buffer interrupt only if interrupts are active
* @param[in]    pBase - The can base address
* @param[in]    u8Instance - Can Instance
* @param[in]    mb_idx - Index of the message buffer
* @param[in]    bIsIntActive - Int Active
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriClearMsgBuffIntCmd(TT_CAN_Type * pBase,
                                uint8 u8Instance,
                                uint32 mb_idx,
                                boolean bIsIntActive
                               );

/**
* @brief        Disable all interrupts
* @details      Disable all interrupts
* @param[in]    pBase - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriDisableInterrupts(TT_CAN_Type * pBase);

/**
* @brief        Enable all interrupts configured
* @details      Enable all interrupts configured
* @param[in]    pBase - The can base address
* @param[in]    u8Instance - A FlexCAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnableInterrupts(TT_CAN_Type * pBase, uint8 u8Instance);

/**
* @brief        Sets the FlexCAN message buffer fields for receiving
* @details      Sets the FlexCAN message buffer fields for receiving
* @param[in]    base - The FlexCAN base address
* @param[in]    msgBuffIdx - Index of the message buffer
* @param[in]    cs - CODE/status values (RX)
* @param[in]    msgId - ID of the message to receive
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetRxMsgBuff(TT_CONST TT_CAN_Type * base,
                          uint32 msgBuffIdx,
                          TT_CONST Flexcan_Hw_MsbuffCodeStatusType * cs,
                          uint32 msgId
                         );

/**
* @brief        Gets the FlexCAN message buffer fields
* @details      Gets the FlexCAN message buffer fields
* @param[in]    base - The FlexCAN base address
* @param[in]    msgBuffIdx - Index of the message buffer
* @param[out]   msgBuff - The fields of the message buffer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriGetMsgBuff(TT_CONST TT_CAN_Type * base,
                        uint32 msgBuffIdx,
                        Flexcan_Hw_MsgBuffType * msgBuff
                       );

/**
* @brief        Sets the FlexCAN message buffer fields for transmitting
* @details      Sets the FlexCAN message buffer fields for transmitting
* @param[in]    pMbAddr - The Message buffer address
* @param[in]    cs - CODE/status values (TX)
* @param[in]    msgId - ID of the message to transmit
* @param[in]    msgData - Bytes of the FlexCAN message
* @param[in]    isRemote - Will set RTR remote Flag
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetTxMsgBuff(volatile uint32 * TT_CONST pMbAddr,
                          TT_CONST Flexcan_Hw_MsbuffCodeStatusType * cs,
                          uint32 msgId,
                          TT_CONST uint8 * msgData,
                          TT_CONST boolean isRemote
                         );

/**
* @brief        Sets  the maximum number of Message Buffers
* @details      Sets  the maximum number of Message Buffers
* @param[in]    base - The FlexCAN base address
* @param[in]    maxMsgBuffNum - Maximum number of message buffers
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetMaxMsgBuffNum(TT_CAN_Type * base, uint32 maxMsgBuffNum);

/**
* @brief        Sets the FlexCAN Rx FIFO fields
* @details      Sets the FlexCAN Rx FIFO fields
* @param[in]    base - The FlexCAN base address
* @param[in]    idFormat - The format of the Rx FIFO ID Filter Table Elements
* @param[in]    idFilterTable - The ID filter table elements which contain RTR bit,IDE bit, and RX message ID
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetRxFifoFilter(TT_CAN_Type * base,
                             Flexcan_Hw_RxFifoIdElementFormatType idFormat,
                             TT_CONST Flexcan_Hw_IdTableType * idFilterTable
                            );

/**
* @brief        Gets the FlexCAN Rx FIFO data
* @details      Gets the FlexCAN Rx FIFO data
* @param[in]    base - The FlexCAN base address
* @param[in]    rxFifo - The FlexCAN receive FIFO data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriReadRxFifo(TT_CONST TT_CAN_Type * base,
                        Flexcan_Hw_MsgBuffType * rxFifo
                       );

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)

/**
* @brief        Enable Enhanced Rx FIFO feature
* @details      Enable Enhanced Rx FIFO feature
* @param[in]    base - The FlexCAN base address
* @param[in]    numOfStdIDFilters - num Of Std ID Filters
* @param[in]    numOfExtIDFilters - num Of Ext ID Filters
* @param[in]    numOfWatermark - num Of Watermark
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnableEnhancedRxFifo(TT_CAN_Type * base,
                                                   uint32 numOfStdIDFilters,
                                                   uint32 numOfExtIDFilters,
                                                   uint32 numOfWatermark);

/**
* @brief        Configure Enhanced RX FIFO ID filter table elements
* @details      Configure Enhanced RX FIFO ID filter table elements
* @param[in]    base - The FlexCAN base address
* @param[in]    idFilterTable - id Filter Table
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetEnhancedRxFifoFilter(TT_CAN_Type * base, TT_CONST Flexcan_Hw_EnhancedIdTableType * idFilterTable);

/**
* @brief        Read Enhanced Rx FIFO data
* @details      Copy Enhanced Rx FIFO data output into user's buffer
* @param[in]    base - The FlexCAN base address
* @param[in]    rxFifo - The FlexCAN receive FIFO data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriReadEnhancedRxFifo(TT_CONST TT_CAN_Type * base, Flexcan_Hw_MsgBuffType * rxFifo);
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
* @brief        Clear Legacy fifo data
* @details      Clear Legacy fifo data
* @param[in]    base - The FlexCAN base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriClearOutputLegacyFIFO(TT_CAN_Type * base);

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) || (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
* @brief        Clear Enhance fifo data
* @details      Clear Enhance fifo data
* @param[in]    base - The FlexCAN base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriClearOutputEnhanceFIFO(TT_CAN_Type * base);
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
#endif /* (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON) */

/**
* @brief        configure controller depending on options
* @details      configure controller depending on options
* @param[in]    pBase - The FlexCAN base address
* @param[in]    u32Options - Controller Options
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriConfigCtrlOptions(TT_CAN_Type * pBase, uint32 u32Options);

#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/**
* @brief        Configures the Pretended Networking mode
* @details      Configures the Pretended Networking mode
* @param[in]    pBase - The FlexCAN base address
* @param[in]    pnConfig - The pretended networking configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriConfigPN(TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_PnConfigType * pPnConfig);
#endif /* FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING */

/**
* @brief        Reset Imask Buffers
* @details      Reset Imask Buffers
* @param[in]    Instance - The CAN instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriResetImaskBuff(uint8 Instance);
/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Set User Mode
* @details      Set User Mode
* @param[in]    Flexcan_Hw_u8Instance - Can Instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetIpUserMode(uint8 Flexcan_Hw_u8Instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    TT_ParaCheck((Flexcan_Hw_u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[Flexcan_Hw_u8Instance];

        MCAL_MEM_SYNC_BARRIER();
        pBase->FLEXCAN_MCR &= ~TT_CAN_FLEXCAN_MCR_SUPV_Msk;
        MCAL_MEM_SYNC_BARRIER();

        switch(Flexcan_Hw_u8Instance)
        {
        case 0:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, TRUE, PPU_CONTROL_CAN0);
            break;
        case 1:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, TRUE, PPU_CONTROL_CAN1);
            break;
        case 2:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, TRUE, PPU_CONTROL_CAN2);
            break;
        case 3:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, TRUE, PPU_CONTROL_CAN3);
            break;
        case 4:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, TRUE, PPU_CONTROL_CAN4);
            break;
        case 5:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, TRUE, PPU_CONTROL_CAN5);
            break;
        case 6:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, TRUE, PPU_CONTROL_CAN6);
            break;
        default:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, TRUE, PPU_CONTROL_CAN7);
            break;
        }
    }
    else
    {

    }
    return TTRetVal;
}

/**
* @brief        Set Privilege Mode
* @details      Set Privilege Mode
* @param[in]    Flexcan_Hw_u8Instance - Can Instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetIpPrivilegeMode(uint8 Flexcan_Hw_u8Instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    TT_ParaCheck((Flexcan_Hw_u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[Flexcan_Hw_u8Instance];

        MCAL_MEM_SYNC_BARRIER();
        pBase->FLEXCAN_MCR |= TT_CAN_FLEXCAN_MCR_SUPV_Msk;
        MCAL_MEM_SYNC_BARRIER();

        switch(Flexcan_Hw_u8Instance)
        {
        case 0:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, FALSE, PPU_CONTROL_CAN0);
            break;
        case 1:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, FALSE, PPU_CONTROL_CAN1);
            break;
        case 2:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, FALSE, PPU_CONTROL_CAN2);
            break;
        case 3:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, FALSE, PPU_CONTROL_CAN3);
            break;
        case 4:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, FALSE, PPU_CONTROL_CAN4);
            break;
        case 5:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, FALSE, PPU_CONTROL_CAN5);
            break;
        case 6:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, FALSE, PPU_CONTROL_CAN6);
            break;
        default:
            TTRetVal = Mcu_Drv_Ppu_Control(TRUE, FALSE, PPU_CONTROL_CAN7);
            break;
        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
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
TT_RetType Can_Hw_Init_Privileged(uint8 Flexcan_Hw_u8Instance,
                                       Flexcan_Hw_StateType * Flexcan_Hw_pState,
                                       TT_CONST Flexcan_Hw_ConfigType * Flexcan_Hw_pData)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    uint32 i = 0;
    TT_ParaCheck((Flexcan_Hw_u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((NULL_PTR == Flexcan_Hw_pState)
            || (NULL_PTR == Flexcan_Hw_pData)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[Flexcan_Hw_u8Instance];
        switch(Flexcan_Hw_u8Instance)
        {
        case 0:
            TTRetVal = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_CAN0);
            break;
        case 1:
            TTRetVal = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_CAN1);
            break;
        case 2:
            TTRetVal = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_CAN2);
            break;
        case 3:
            TTRetVal = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_CAN3);
            break;
        case 4:
            TTRetVal = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_CAN4);
            break;
        case 5:
            TTRetVal = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_CAN5);
            break;
        case 6:
            TTRetVal = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_CAN6);
            break;
        default:
            TTRetVal = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_CAN7);
            break;
        }
        if(TT_RET_SUCCESS == TTRetVal)
        {
            TTRetVal = Can_Hw_PriEnableController(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = Can_Hw_PriInitController(Flexcan_Hw_u8Instance, pBase, Flexcan_Hw_pData);
                if (TT_RET_SUCCESS == TTRetVal)
                {
                    /* Enable the use of extended bit time definitions */
                    FlexCAN_BtfEnable(pBase, Flexcan_Hw_pData->fd_enable);

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
                    if (Flexcan_Hw_pData->enhCbtEnable)
                    {
                        /* Enable Enhanced CBT time segments */
                        pBase->FLEXCAN_CTRL2 |= TT_CAN_FLEXCAN_CTRL2_BTE_Msk;
                        FlexCAN_SetEnhancedNominalTimeSegments(pBase, &Flexcan_Hw_pData->bitrate);
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                        if (Flexcan_Hw_pData->fd_enable)
                        {
                            FlexCAN_SetEnhancedDataTimeSegments(pBase, &Flexcan_Hw_pData->bitrate_cbt);
                        }
                        else
                        {

                        }
#endif
                    }
                    else
#endif    /* End of (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)  */
                    {
                        /* Disable Enhanced CBT time segments */
                        pBase->FLEXCAN_CTRL2 &= ~TT_CAN_FLEXCAN_CTRL2_BTE_Msk;
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                        /* Set bit rate. */
                        if (Flexcan_Hw_pData->fd_enable)
                        {
                            /* Write Normal bit time configuration to CBT register */
                            FlexCAN_SetExtendedTimeSegments(pBase, &Flexcan_Hw_pData->bitrate);
                            /* Write Data bit time configuration to FDCBT register */
                            FlexCAN_SetFDTimeSegments(pBase, &Flexcan_Hw_pData->bitrate_cbt);
                        }
                        else
#endif
                        {
                            /* Write Normal bit time configuration to CTRL1 register */
                            FlexCAN_SetTimeSegments(pBase, &Flexcan_Hw_pData->bitrate);
                        }
                    }

                    /* Select mode */
                    Can_Hw_PriSetOperationMode(pBase, Flexcan_Hw_pData->flexcanMode);

#if (STD_ON == FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT)
#if (STD_ON == FLEXCAN_HW_FEATURE_HAS_SUPV)
                    TTRetVal = Call_Can_Hw_SetIpUserMode(Flexcan_Hw_u8Instance);
#endif
#endif

                    for (i = 0; i < (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM; i++)
                    {
                        /* Check if blocking need to be any more present in sync\async discussions */
                        /* Sync up isPolling status with hw (Imask), at the begining all Imask = 0 => isPolling = TRUE */
                        Flexcan_Hw_pState->mbs[i].isPolling = TRUE;
                        Flexcan_Hw_pState->mbs[i].pMBmessage = NULL_PTR;
                        Flexcan_Hw_pState->mbs[i].state = FLEXCAN_MB_IDLE;
                        Flexcan_Hw_pState->mbs[i].time_stamp = 0U;
                    }
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
                    /* Sync up isPolling status with hw (Imask), at the begining all Imask = 0 => isPolling = TRUE */
                    Flexcan_Hw_pState->enhancedFifoOutput.isPolling = TRUE;
                    Flexcan_Hw_pState->enhancedFifoOutput.state = FLEXCAN_MB_IDLE;
#endif

                    Flexcan_Hw_pState->transferType = Flexcan_Hw_pData->transfer_type;
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
                    Flexcan_Hw_pState->rxFifoDMAChannel = Flexcan_Hw_pData->rxFifoDMAChannel;
                    Flexcan_Hw_pState->cb_event         = Flexcan_Hw_pData->cb_event;
#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */

                    /* Clear Callbacks in case of autovariables garbage */
                    Flexcan_Hw_pState->callback = Flexcan_Hw_pData->Callback;
                    Flexcan_Hw_pState->callbackParam = NULL_PTR;
                    Flexcan_Hw_pState->error_callback = Flexcan_Hw_pData->ErrorCallback;
                    Flexcan_Hw_pState->errorCallbackParam = NULL_PTR;
                    Flexcan_Hw_pState->bIsLegacyFifoEn = Flexcan_Hw_pData->is_rx_fifo_needed;
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
                    Flexcan_Hw_pState->bIsEnhancedFifoEn = Flexcan_Hw_pData->is_enhanced_rx_fifo_needed;
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
                    Flexcan_Hw_pState->u32MaxMbNum = Flexcan_Hw_pData->max_num_mb;
                    Flexcan_Hw_pState->isIntActive = TRUE;
                    /* Save runtime structure pointers so irq handler can point to the correct state structure */
                    Flexcan_Hw_apxState[Flexcan_Hw_u8Instance] = Flexcan_Hw_pState;
                }
                else
                {

                }
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
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
                                      TT_CONST uint8 * mb_data)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
#if (FLEXCAN_HW_MB_INTERRUPT_SUPPORT == STD_ON)
    Flexcan_Hw_StateType * state = NULL_PTR;
#endif

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((NULL_PTR == tx_info)
            || (NULL_PTR == mb_data)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        if (!FlexCAN_IsListenOnlyModeEnabled(base))
        {
            TTRetVal = Can_Hw_PriStartSendData(instance, mb_idx, tx_info, msg_id, mb_data);
#if (FLEXCAN_HW_MB_INTERRUPT_SUPPORT == STD_ON)
            if ((TT_RET_SUCCESS == TTRetVal) && (FALSE == tx_info->is_polling))
            {
                state = Flexcan_Hw_apxState[instance];
                /* Enable message buffer interrupt*/
                TTRetVal = Can_Hw_PriSetMsgBuffIntCmd(base, instance, mb_idx, TRUE, state->isIntActive);
            }
            else
            {

            }
#endif
        }
        else
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
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
                                            uint32 msg_id)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType TTRetValArray[3] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};
    Flexcan_Hw_MsbuffCodeStatusType cs = {0};
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == rx_info), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
        if (TRUE == Can_Hw_PriIsMbOutOfRange(base, mb_idx, state->bIsLegacyFifoEn, state->u32MaxMbNum))
        {
            TTRetVal = TT_RET_PARAM_INDEX_ERR;
        }
        else
        {
            /* Clear the message buffer flag if previous remained triggered */
            FlexCAN_ClearMsgBuffIntStatusFlag(base, mb_idx);

            cs.dataLen = rx_info->data_length;
            cs.msgIdType = rx_info->msg_id_type;
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            cs.fd_enable = rx_info->fd_enable;
#endif

            /* Initialize rx mb*/
            cs.code = (uint32)FLEXCAN_RX_NOT_USED;
            TTRetValArray[0] = Can_Hw_PriSetRxMsgBuff(base, mb_idx, &cs, msg_id);

            /* Initialize receive MB*/
            cs.code = (uint32)FLEXCAN_RX_INACTIVE;
            TTRetValArray[1] = Can_Hw_PriSetRxMsgBuff(base, mb_idx, &cs, msg_id);

            /* Set up FlexCAN message buffer fields for receiving data*/
            cs.code = (uint32)FLEXCAN_RX_EMPTY;
            TTRetValArray[2] = Can_Hw_PriSetRxMsgBuff(base, mb_idx, &cs, msg_id);
            if((TT_RET_SUCCESS != TTRetValArray[0])
                    || (TT_RET_SUCCESS != TTRetValArray[1])
                    || (TT_RET_SUCCESS != TTRetValArray[2]))
            {
                TTRetVal = TT_RET_OPT_REG_ERR;
            }
            else
            {

            }
        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
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
                                         boolean isPolling)
{

    TT_RetType TTRetVal = TT_RET_SUCCESS;
#if (FLEXCAN_HW_MB_INTERRUPT_SUPPORT == STD_ON)
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
#endif
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((TRUE != isPolling) && (FALSE != isPolling)), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_PriStartRxMsgBufferData(instance, mb_idx, data, isPolling);
#if (FLEXCAN_HW_MB_INTERRUPT_SUPPORT == STD_ON)
        if ((TT_RET_SUCCESS == TTRetVal) && (FALSE == isPolling))
        {
            base = Flexcan_Hw_apxBase[instance];
            state = Flexcan_Hw_apxState[instance];
            /* Enable MB interrupt*/
            TTRetVal = Can_Hw_PriSetMsgBuffIntCmd(base, instance, mb_idx, TRUE, state->isIntActive);
        }
        else
        {

        }
#endif
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))

/**
* @brief        Logic Check
* @details      Logic Check
* @param[in]    ConfigPtr - Const Ptr to Can Config data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_LogicCheck(Flexcan_Hw_ModesType Mode,uint8 ControllerOffset)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    static TT_CAN_Type * TT_CONST Flexcan_Base[] = IP_FLEXCAN_BASE_PTRS;

    if (Mode == FLEXCAN_NORMAL_MODE)
    {
        TT_CAN_Type * pBase = Flexcan_Base[ControllerOffset];
        if ((((pBase->FLEXCAN_CTRL1 & TT_CAN_FLEXCAN_CTRL1_LOM_Msk) >> TT_CAN_FLEXCAN_CTRL1_LOM_Pos) == 0) && (((pBase->FLEXCAN_CTRL1 & TT_CAN_FLEXCAN_CTRL1_LPB_Msk) >> TT_CAN_FLEXCAN_CTRL1_LPB_Pos) == 0))
        {
            Ret = TT_RET_SUCCESS;
        }
        else
        {
            Ret = TT_RET_STATUS_INIT_ERR;
        }
    }
    else if (Mode == FLEXCAN_LISTEN_ONLY_MODE)
    {
        TT_CAN_Type * pBase = Flexcan_Base[ControllerOffset];
        if (((pBase->FLEXCAN_CTRL1 & TT_CAN_FLEXCAN_CTRL1_LOM_Msk) >> TT_CAN_FLEXCAN_CTRL1_LOM_Pos) == 1)
        {
            Ret = TT_RET_SUCCESS;
        }
        else
        {
            Ret = TT_RET_STATUS_INIT_ERR;
        }
    }
    else
    {
        TT_CAN_Type * pBase = Flexcan_Base[ControllerOffset];
        if ((((pBase->FLEXCAN_CTRL1 & TT_CAN_FLEXCAN_CTRL1_LOM_Msk) >> TT_CAN_FLEXCAN_CTRL1_LOM_Pos) == 0) && (((pBase->FLEXCAN_CTRL1 & TT_CAN_FLEXCAN_CTRL1_LPB_Msk) >> TT_CAN_FLEXCAN_CTRL1_LPB_Pos) == 1))
        {
            Ret = TT_RET_SUCCESS;
        }
        else
        {
            Ret = TT_RET_STATUS_INIT_ERR;
        }
    }

    return Ret;
}

#endif /* INITCHECK_CAN */

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)

#ifdef CanHwUnit_0
void DMA_Can_Callback0(uint32 event)
{ 
    DMA_Can_Callback(0U, event);
}
#endif

#ifdef CanHwUnit_1
void DMA_Can_Callback1(uint32 event)
{ 
    DMA_Can_Callback(1U, event); 
}
#endif

#ifdef CanHwUnit_2
void DMA_Can_Callback2(uint32 event)
{ 
    DMA_Can_Callback(2U, event); 
}
#endif

#ifdef CanHwUnit_3
void DMA_Can_Callback3(uint32 event)
{ 
    DMA_Can_Callback(3U, event); 
}
#endif

#ifdef CanHwUnit_4
void DMA_Can_Callback4(uint32 event)
{ 
    DMA_Can_Callback(4U, event);
}
#endif

#ifdef CanHwUnit_5
void DMA_Can_Callback5(uint32 event)
{ 
    DMA_Can_Callback(5U, event); 
}
#endif

#ifdef CanHwUnit_6
void DMA_Can_Callback6(uint32 event)
{ 
    DMA_Can_Callback(6U, event); 
}
#endif

#ifdef CanHwUnit_7
void DMA_Can_Callback7(uint32 event)
{ 
    DMA_Can_Callback(7U, event); 
}
#endif

#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */

/**
* @brief        Receives a CAN frame using the message FIFO
* @details      Receives a CAN frame using the message FIFO
* @param[in]    instance - A FlexCAN instance number
* @param[out]   data - The FlexCAN receive message buffer data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_RxFifo(uint8 instance, Flexcan_Hw_MsgBuffType * data)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TT_CONST TT_CAN_Type *TT_CONST base = Flexcan_Hw_apxBase[instance];
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        if (TRUE == FlexCAN_IsEnhancedRxFifoEnabled(base))
        {
            TTRetVal = Can_Hw_PriStartRxMsgEnFifoData(instance, data);
        }
        else
        {
#endif /*FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO*/
            TTRetVal = Can_Hw_PriStartRxMsgFifoData(instance, data);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        }
#endif

    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
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
TT_RetType Can_Hw_ConfigRxFifo_Privileged(uint8 instance,
                                              Flexcan_Hw_RxFifoIdElementFormatType id_format,
                                              TT_CONST Flexcan_Hw_IdTableType * id_filter_table)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    boolean disabled = FALSE;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((id_format > FLEXCAN_RX_FIFO_ID_FORMAT_D), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == id_filter_table), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        TT_CONST boolean freeze = FlexCAN_IsFreezeMode(pBase);
        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
            /* Initialize rx fifo*/
            TTRetVal = Can_Hw_PriSetRxFifoFilter(pBase, id_format, id_filter_table);
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

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
TT_RetType Can_Hw_ConfigEnhancedRxFifo_Privileged(uint8 instance, TT_CONST Flexcan_Hw_EnhancedIdTableType * id_filter_table)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    boolean disabled = FALSE;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == id_filter_table), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }


        TT_CONST boolean freeze = FlexCAN_IsFreezeMode(pBase);
        if((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if(TT_RET_SUCCESS == TTRetVal)
        {
            /* Initialize rx fifo*/
            TTRetVal = Can_Hw_PriSetEnhancedRxFifoFilter(pBase, id_filter_table);
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if (TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
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
TT_RetType Can_Hw_GetTransferStatus(uint8 instance, uint8 mb_idx, Flexcan_Hw_StatusType *status)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_StateType * state = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((mb_idx >= (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM) && (FLEXCAN_HW_MB_ENHANCED_RXFIFO != mb_idx)), TT_RET_PARAM_INDEX_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == status), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        state = Flexcan_Hw_apxState[instance];
        if (mb_idx < (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM)
        {
            if (FLEXCAN_MB_IDLE == state->mbs[mb_idx].state)
            {
                *status = FLEXCAN_STATUS_SUCCESS;
            }

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
            else if (FLEXCAN_MB_DMA_ERROR == state->mbs[mb_idx].state)
            {
                *status = FLEXCAN_STATUS_ERROR;
            }
#endif
            else
            {
                *status = FLEXCAN_STATUS_BUSY;
            }
        }
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        else
        {
            if (FLEXCAN_MB_IDLE == state->enhancedFifoOutput.state)
            {
                *status = FLEXCAN_STATUS_SUCCESS;
            }

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
            else if (FLEXCAN_MB_DMA_ERROR == state->enhancedFifoOutput.state)
            {
                *status = FLEXCAN_STATUS_ERROR;
            }
#endif
            else
            {
                *status = FLEXCAN_STATUS_BUSY;
            }
        }
#else
        else
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        This handler read data from MB or FIFO, and then clear the interrupt flags
* @details      This handler read data from MB or FIFO, and then clear the interrupt flags
* @param[in]    instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_Mbor_IRQHandler(uint8 instance)
{
    uint32 u32MbHandle = 0U;
    uint32 flag_reg = 0;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
        uint32 mb_idx = 0;

        /* Check if instance initialized */
        if (NULL_PTR != state)
        {
            flag_reg = FlexCAN_GetMsgBuffIntStatusFlag(base, mb_idx);

            while (flag_reg == 0U)
            {
                mb_idx++;
                flag_reg = FlexCAN_GetMsgBuffIntStatusFlag(base, mb_idx);

                if (mb_idx >= Can_Hw_PriGetMaxMbNum(base))
                {
                    break;
                }
                else
                {

                }
            }

            /* Check Tx/Rx interrupt flag and clear the interrupt */
            if (flag_reg != 0U)
            {
                /* For legacy fifo, mb handler is FLEXCAN_HW_MB_HANDLE_RXFIFO(0) */
                u32MbHandle = mb_idx;

                if ((TRUE == state->bIsLegacyFifoEn) && (mb_idx <= FLEXCAN_HW_LEGACY_RXFIFO_OVERFLOW))
                {
                    (void)Can_Hw_PriIRQHandlerRxFIFO(instance, mb_idx);
                    u32MbHandle = (uint32)FLEXCAN_HW_MB_HANDLE_RXFIFO;
                }
                else
                {
                    /* Check mailbox completed reception */
                    if (FLEXCAN_MB_RX_BUSY == state->mbs[u32MbHandle].state)
                    {
                        (void)Can_Hw_PriIRQHandlerRxMB(instance, mb_idx);
                    }
                    else
                    {

                    }
                }

                /* Check mailbox completed transmission */
                if (FLEXCAN_MB_TX_BUSY == state->mbs[u32MbHandle].state)
                {
                    (void)Can_Hw_PriIRQHandlerTxMB(instance, mb_idx);
                }
                else
                {

                }

                /* Check for spurious interrupt */
                if (FlexCAN_GetMsgBuffIntStatusFlag(base, mb_idx) != 0U)
                {
                    if (state->mbs[u32MbHandle].state == FLEXCAN_MB_IDLE)
                    {
                        /* In case of desynchronized status of the MB to avoid trapping in ISR
                         * clear the MB flag */
                        FlexCAN_ClearMsgBuffIntStatusFlag(base, mb_idx);
                    }
                    else
                    {

                    }
                }
                else
                {

                }
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return;
}

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
* @brief        Enhanced RxFifo IRQHandler
* @details      Enhanced RxFifo IRQHandler
* @param[in]    u8Instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_EnhancedRxFifo_IRQHandler(uint8 u8Instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[u8Instance];
        state = Flexcan_Hw_apxState[u8Instance];
        uint32 u32intType = 0U;

        /* Get the interrupts that are enabled and ready */
        for (u32intType = FLEXCAN_HW_ENHANCED_RXFIFO_WATERMARK; u32intType >= FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE; u32intType--)
        {
            if ((uint8)0U != FlexCAN_GetEnhancedRxFIFOStatusFlag(base, u32intType))
            {
                if ((uint8)0U != FlexCAN_GetEnhancedRxFIFOIntStatusFlag(base, u32intType))
                {
                    (void)Can_Hw_PriIRQHandlerEnRxFIFO(u8Instance, u32intType);
                }

                /* just process spurious interrupt when no real interrupt at all */
                else if (FALSE == state->enhancedFifoOutput.isPolling)
                {
                    /* Process spurious interrupt */
                    (void)FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, u32intType);
                }
                else
                {
                    
                }
            }
            else
            {

            }
        }
    }
    else
    {

    }

    return;
}
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */

/**
* @brief        Error interrupt handler for FLEXCAN
* @details      Error interrupt handler for FLEXCAN
* @param[in]    instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_Error_IRQHandler(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
        uint32 u32ErrStatus = 0U;

        /* Check if the instance initialized */
        if (NULL_PTR != state)
        {
            /* Get error status to get value updated */
            u32ErrStatus = pBase->FLEXCAN_ESR1;

            if (((uint32)0U != (u32ErrStatus & ((uint32)TT_CAN_FLEXCAN_ESR1_ERRINT_Msk))) && ((uint32)0U != (pBase->FLEXCAN_CTRL1 & ((uint32)TT_CAN_FLEXCAN_CTRL1_ERRMSK_Msk))))
            {
                pBase->FLEXCAN_ESR1 = TT_CAN_FLEXCAN_ESR1_ERRINT_Msk;
                if (state->error_callback != NULL_PTR)
                {
                    state->error_callback(instance, FLEXCAN_EVENT_ERROR, u32ErrStatus, state);
                    /* Get error status to get value updated due to user may handle ESR1 register */
                    u32ErrStatus = pBase->FLEXCAN_ESR1;
                }
                else
                {

                }
            }
            else
            {

            }
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            if (((uint32)0U != (u32ErrStatus & ((uint32)TT_CAN_FLEXCAN_ESR1_ERRINT_FAST_Msk))) && ((uint32)0U != (pBase->FLEXCAN_CTRL2 & ((uint32)TT_CAN_FLEXCAN_CTRL2_ERRMSK_FAST_Msk))))
            {
                pBase->FLEXCAN_ESR1 = TT_CAN_FLEXCAN_ESR1_ERRINT_FAST_Msk;
                /* Invoke callback */
                if (state->error_callback != NULL_PTR)
                {
                    state->error_callback(instance, FLEXCAN_EVENT_ERROR_FAST, u32ErrStatus, state);
                    u32ErrStatus = pBase->FLEXCAN_ESR1;
                }
                else
                {

                }
            }
            else
            {

            }
#endif /* FLEXCAN_HW_FEATURE_HAS_FD */

            if (0U != (u32ErrStatus & TT_CAN_FLEXCAN_ESR1_ERROVR_Msk))
            {
                pBase->FLEXCAN_ESR1 = TT_CAN_FLEXCAN_ESR1_ERROVR_Msk;
                /* Invoke callback */
                if (state->error_callback != NULL_PTR)
                {
                    state->error_callback(instance, FLEXCAN_EVENT_ERROR, u32ErrStatus, state);
                }
                else
                {

                }
            }
            else
            {

            }
        }
        else
        {
            pBase->FLEXCAN_ESR1 = FLEXCAN_HW_ERROR_INT;
        }
    }
    else
    {

    }

    return;
}

/**
* @brief        BusOff and Tx/Rx Warning interrupt handler for FLEXCAN
* @details      BusOff and Tx/Rx Warning interrupt handler for FLEXCAN
* @param[in]    instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_Busoff_IRQHandler(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
        uint32 u32ErrStatus = 0U;

        /* Check If Driver initialized */
        if (NULL_PTR != state)
        {
            /* Get error status to get value updated */
            u32ErrStatus = base->FLEXCAN_ESR1;

            if ((0U != (u32ErrStatus & FLEXCAN_HW_BUS_OFF_INT)) && (0U != (base->FLEXCAN_CTRL1 & TT_CAN_FLEXCAN_CTRL1_BOFFMSK_Msk)))
            {
                base->FLEXCAN_ESR1 = FLEXCAN_HW_BUS_OFF_INT;
                /* Invoke callback */
                if (state->error_callback != NULL_PTR)
                {
                    state->error_callback(instance, FLEXCAN_EVENT_BUSOFF, u32ErrStatus, state);
                }
                else
                {

                }
            }
            else
            {

            }
        }
        else
        {
            base->FLEXCAN_ESR1 = FLEXCAN_HW_BUS_OFF_INT;
        }
    }
    else
    {

    }

    return;
}

/**
* @brief        TX/RX Warnning IRQHandler
* @details      TX/RX Warnning IRQHandler
* @param[in]    instance - A FlexCAN instance number
* @return       void
* @retval       None
*/
void CANx_TXRX_Warnning_IRQHandler(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
        uint32 u32ErrStatus = 0U;

        /* Check if the instance initialized */
        if (NULL_PTR != state)
        {
            /* Get error status to get value updated */
            u32ErrStatus = pBase->FLEXCAN_ESR1;

            if ((0U != (u32ErrStatus & TT_CAN_FLEXCAN_ECR_TX_ERR_COUNTER_Msk)) && (0U != (pBase->FLEXCAN_CTRL1 & TT_CAN_FLEXCAN_CTRL1_TWRNMSK_Msk)))
            {
                pBase->FLEXCAN_ESR1 = TT_CAN_FLEXCAN_ESR1_TWRNINT_Msk;
                /* Invoke callback */
                if (state->error_callback != NULL_PTR)
                {
                    state->error_callback(instance, FLEXCAN_EVENT_TX_WARNING, u32ErrStatus, state);
                    /* Get error status to get value updated due to user may handle ESR1 register */
                    u32ErrStatus = pBase->FLEXCAN_ESR1;
                }
                else
                {

                }
            }
            else
            {

            }

            if ((0U != (u32ErrStatus & TT_CAN_FLEXCAN_ECR_RX_ERR_COUNTER_Msk)) && (0U != (pBase->FLEXCAN_CTRL1 & TT_CAN_FLEXCAN_CTRL1_RWRNMSK_Msk)))
            {
                pBase->FLEXCAN_ESR1 = TT_CAN_FLEXCAN_ESR1_RWRNINT_Msk;
                /* Invoke callback */
                if (state->error_callback != NULL_PTR)
                {
                    state->error_callback(instance, FLEXCAN_EVENT_RX_WARNING, u32ErrStatus, state);
                    /* Get error status to get value updated due to user may handle ESR1 register */
                }
                else
                {

                }
            }
            else
            {

            }
        }
        else
        {
            pBase->FLEXCAN_ESR1 = FLEXCAN_HW_TXRXWARN_INT;
        }
    }
    else
    {

    }

    return;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Reports various error conditions detected in the reception and transmission of a CAN frame and some general status of the device
* @details      Reports various error conditions detected in the reception and transmission of a CAN frame and some general status of the device
* @param[in]    instance - A FlexCAN instance number
* @param[out]   ErrStatus - Error Status
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetErrorStatus(uint8 instance, uint32 *ErrStatus)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == ErrStatus), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        *ErrStatus = (uint32)(base->FLEXCAN_ESR1);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Reports Transmit error counter for all errors detected in transmitted messages
* @details      Reports Transmit error counter for all errors detected in transmitted messages
* @param[in]    instance - A FlexCAN instance number
* @param[out]   ErrorCounter - Error Counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetControllerTxErrCounter(uint8 instance, uint8 * ErrorCounter)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == ErrorCounter), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        *ErrorCounter = (uint8)((base->FLEXCAN_ECR & TT_CAN_FLEXCAN_ECR_TX_ERR_COUNTER_Msk) >> TT_CAN_FLEXCAN_ECR_TX_ERR_COUNTER_Pos);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Reports Receive error counter for all errors detected in received messages
* @details      Reports Receive error counter for all errors detected in received messages
* @param[in]    instance - A FlexCAN instance number
* @param[out]   ErrorCounter - Error Counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetControllerRxErrCounter(uint8 instance, uint8 * ErrorCounter)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == ErrorCounter), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        *ErrorCounter =  (uint8)((base->FLEXCAN_ECR & TT_CAN_FLEXCAN_ECR_RX_ERR_COUNTER_Msk) >> TT_CAN_FLEXCAN_ECR_RX_ERR_COUNTER_Pos);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set Rx Message Buffer global mask as the mask value provided
* @details      Set Rx Message Buffer global mask as the mask value provided
* @param[in]    instance - A FlexCAN instance number
* @param[in]    mask - global mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxMbGlbMask_Privileged(uint8 instance, uint32 mask)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    boolean freeze = FALSE;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);
        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        freeze = FlexCAN_IsFreezeMode(pBase);

        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }
        if(TT_RET_SUCCESS == TTRetVal)
        {
            FlexCAN_SetRxMsgBuffGlobalMask(pBase, mask);
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }

        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Enter Driver In freeze Mode
* @details      Enter Driver In freeze Mode
* @param[in]    instance - A FlexCAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_EnterFrzMode_Privileged(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        TTRetVal = Can_Hw_PriEnterFreezeMode(base);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Exit Driver from freeze Mode
* @details      Exit Driver from freeze Mode
* @param[in]    instance - A FlexCAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_ExitFreezeMode_Privileged(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        TTRetVal = Can_Hw_PriExitFreezeMode(base);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set Rx individual mask as absolute value provided by mask parameter
* @details      Set Rx individual mask as absolute value provided by mask parameter
* @param[in]    instance - A CAN instance number
* @param[in]    mb_idx - mb index
* @param[in]    mask - Rx individual mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxIndMask_Privileged(uint8 instance, uint8 mb_idx, uint32 mask)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    boolean freeze = FALSE;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);

        if ((mb_idx > (((pBase->FLEXCAN_MCR) & TT_CAN_FLEXCAN_MCR_MAXMB_Msk) >> TT_CAN_FLEXCAN_MCR_MAXMB_Pos)))
        {
            TTRetVal = TT_RET_PARAM_INDEX_ERR;
        }
        else
        {
            if (TRUE == disabled)
            {
                TTRetVal = Can_Hw_PriEnable(pBase);
            }
            else
            {

            }
            freeze = FlexCAN_IsFreezeMode(pBase);

            if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
            {
                TTRetVal = TT_RET_STATUS_ERR;
            }
            else
            {

            }
            if (TT_RET_SUCCESS == TTRetVal)
            {
                FlexCAN_SetRxIndividualMask(pBase, mb_idx, mask);
            }
            else
            {

            }

            if (TRUE == disabled)
            {
                status = Can_Hw_PriDisable(pBase);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    TTRetVal = status;
                }
                else
                {

                }
            }
            else
            {

            }
        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set RxFifo Global Mask
* @details      Set RxFifo Global Mask
* @param[in]    instance - A CAN instance number
* @param[in]    mask - RxFifo Global Mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxFifoGlMsk_Privileged(uint8 instance, uint32 mask)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    boolean freeze = FALSE;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }


        freeze = FlexCAN_IsFreezeMode(pBase);
        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
            FlexCAN_SetRxFifoGlobalMask(pBase, mask);
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Shutdown a CAN module
* @details      Shutdown a CAN module
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_Deinit_Privileged(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];

        /* Enter Freeze Mode Required before to enter Disabled Mode */
        TTRetVal = Can_Hw_PriEnterFreezeMode(base);
        if (TT_RET_SUCCESS == TTRetVal)
        {
            /* wait for disable */
            TTRetVal = Can_Hw_PriDisable(base);
            if (TT_RET_SUCCESS == TTRetVal)
            {
                switch(instance)
                {
                case 0:
                    TTRetVal = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_CAN0);
                    break;
                case 1:
                    TTRetVal = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_CAN1);
                    break;
                case 2:
                    TTRetVal = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_CAN2);
                    break;
                case 3:
                    TTRetVal = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_CAN3);
                    break;
                case 4:
                    TTRetVal = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_CAN4);
                    break;
                case 5:
                    TTRetVal = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_CAN5);
                    break;
                case 6:
                    TTRetVal = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_CAN6);
                    break;
                default:
                    TTRetVal = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_CAN7);
                    break;
                }
                /* Clear state pointer that is checked by FLEXCAN_DRV_Init */
                Flexcan_Hw_apxState[instance] = NULL_PTR;
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Process received Rx MessageBuffer or RxFifo
* @details      Process received Rx MessageBuffer or RxFifo
* @param[in]    instance - A CAN instance number
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_MainFunctionRead(uint8 instance, uint8 mb_idx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        TT_ParaCheck(((mb_idx >= (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM) && (FLEXCAN_HW_MB_ENHANCED_RXFIFO != mb_idx)), TT_RET_PARAM_INDEX_ERR, &TTRetVal);
#else
        TT_ParaCheck((mb_idx >= (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM), TT_RET_PARAM_INDEX_ERR, &TTRetVal);
#endif

        if(TT_RET_SUCCESS == TTRetVal)
        {
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
            if ((uint8)FLEXCAN_HW_MB_ENHANCED_RXFIFO == mb_idx)
            {
                if (TRUE == FlexCAN_IsEnhancedRxFifoEnabled(base))
                {
                    if (FlexCAN_GetEnhancedRxFIFOStatusFlag(base, FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE) != 0U)
                    {
                        TTRetVal = Can_Hw_PriIRQHandlerEnRxFIFO(instance, FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE);
                    }
                    else
                    {

                    }
                }
                else
                {

                }
            }
            else
            {
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
                if ((TRUE == state->bIsLegacyFifoEn) && (mb_idx <= FLEXCAN_HW_LEGACY_RXFIFO_OVERFLOW))
                {
                    /* just process available legacy fifo event only */
                    if ((uint8)FLEXCAN_HW_MB_HANDLE_RXFIFO == mb_idx)
                    {
                        if (FlexCAN_GetBuffStatusFlag(base, FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE) != 0U)
                        {
                            TTRetVal = Can_Hw_PriIRQHandlerRxFIFO(instance, FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE);
                        }
                        else
                        {

                        }
                    }
                    else
                    {

                    }
                }
                else
                {
                    if (FlexCAN_GetBuffStatusFlag(base, mb_idx) != 0U)
                    {
                        /* Check mailbox completed reception */
                        if (FLEXCAN_MB_RX_BUSY == state->mbs[mb_idx].state)
                        {
                            TTRetVal = Can_Hw_PriIRQHandlerRxMB(instance, mb_idx);
                        }
                        else
                        {

                        }
                    }
                    else
                    {

                    }
                }
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
            }
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Check if BusOff occurred
* @details      Check if BusOff occurred
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_MainFuncBusOff_Privileged(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    uint32 u32ErrStatus = 0U;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];

        /* Get error status */
        u32ErrStatus = base->FLEXCAN_ESR1;

        if (0U != (u32ErrStatus & TT_CAN_FLEXCAN_ESR1_BOFFINT_Msk))
        {
            /* Invoke callback */
            if (state->error_callback != NULL_PTR)
            {
                state->error_callback(instance, FLEXCAN_EVENT_BUSOFF, u32ErrStatus, state);
            }
            else
            {

            }
            /* Clear BusOff Status Flag */
            base->FLEXCAN_ESR1 = TT_CAN_FLEXCAN_ESR1_BOFFINT_Msk;
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Process transmitted Tx MessageBuffer
* @details      Process transmitted Tx MessageBuffer
* @param[in]    instance - A CAN instance number
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_MainFunctionWrite(uint8 instance, uint8 mb_idx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];

        if (FlexCAN_GetBuffStatusFlag(base, mb_idx) != 0U)
        {
            state->mbs[mb_idx].time_stamp = Can_Hw_PriGetMsgBuffTimestamp(base, mb_idx);
            FlexCAN_UnlockRxMsgBuff(base);

            /* Clear message buffer flag */
            FlexCAN_ClearMsgBuffIntStatusFlag(base, mb_idx);
            state->mbs[mb_idx].state = FLEXCAN_MB_IDLE;
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Check if the FlexCAN instance is STOPPED
* @details      Check if the FlexCAN instance is STOPPED
* @param[in]    instance - A CAN instance number
* @param[out]   result - Stop Mode result
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetStopMode_Privileged(uint8 instance, boolean * result)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == result), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        *result =  (boolean)((TT_CAN_FLEXCAN_MCR_LPMACK_Msk == (base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_LPMACK_Msk)) ? TRUE : FALSE);
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Check if the CAN instance is STARTED
* @details      Check if the CAN instance is STARTED
* @param[in]    instance - A CAN instance number
* @param[out]   result - Start Mode result
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetStartMode_Privileged(uint8 instance, boolean *result)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == result), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        *result =  (boolean)((0U == (base->FLEXCAN_MCR & (TT_CAN_FLEXCAN_MCR_LPMACK_Msk | TT_CAN_FLEXCAN_MCR_FRZACK_Msk))) ? TRUE : FALSE);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set the CAN instance in START mode
* @details      Set the CAN instance in START mode
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetStartMode_Privileged(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        /* Enable Flexcan Module */
        pBase->FLEXCAN_MCR &= ~TT_CAN_FLEXCAN_MCR_MDIS_Msk;

        TTRetVal = Can_Hw_PriExitFreezeMode(pBase);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set the CAN instance in STOP mode
* @details      Set the CAN instance in STOP mode
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetStopMode_Privileged(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TTRetVal = Can_Hw_PriEnterFreezeMode(pBase);
        if (TT_RET_SUCCESS == TTRetVal)
        {
            TTRetVal = Can_Hw_PriDisable(pBase);
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Set RX masking type
* @details      Set RX masking type
* @param[in]    instance - A CAN instance number
* @param[in]    type - mask type
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxMaskType_Privileged(uint8 instance, Flexcan_Hw_RxMaskType type)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((type > FLEXCAN_RX_MASK_INDIVIDUAL), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        TT_CONST boolean freeze = FlexCAN_IsFreezeMode(pBase);
        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
            FlexCAN_SetRxMaskType(pBase, type);
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Set Bitrate
* @details      Set Bitrate
* @param[in]    instance - A CAN instance number
* @param[in]    bitrate - bitrate
* @param[in]    enhExt - extended time segments
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetBitrate_Privileged(uint8 instance, TT_CONST Flexcan_Hw_TimeSegmentType * bitrate, boolean enhExt)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == bitrate), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    TT_ParaCheck(((TRUE != enhExt) && (FALSE != enhExt)), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        /* Check if the FlexCAN is enabled or not */
        TT_CONST boolean disabled = (boolean)(((pBase->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_MDIS_Msk) != 0U) ? TRUE : FALSE);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_OFF)
        (void)enhExt;
#endif
        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }
        /* Check if controller is in freeze mode or not */
        TT_CONST boolean freeze = (boolean)(((pBase->FLEXCAN_MCR & (TT_CAN_FLEXCAN_MCR_FRZACK_Msk)) != 0U)? TRUE : FALSE);
        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
            /* Enable the use of extended bit time definitions */
            FlexCAN_BteEnable(pBase, enhExt);

            if (TRUE == enhExt)
            {
                /* Set extended time segments*/
                FlexCAN_SetEnhancedNominalTimeSegments(pBase, bitrate);
            }
            else
#endif
            {
                if (TRUE == FlexCAN_IsBtfEnabled(pBase))
                {
                    FlexCAN_SetExtendedTimeSegments(pBase, bitrate);
                }
                else
                {
                    FlexCAN_SetTimeSegments(pBase, bitrate);
                }
            }
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if (TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set Bitrate
* @details      Set Bitrate
* @param[in]    instance - A CAN instance number
* @param[in]    bitrate - bitrate
* @param[in]    bitRateSwitch - bitRate Switch
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetBitrateFD_Privileged(uint8 instance, TT_CONST Flexcan_Hw_TimeSegmentType * bitrate, boolean bitRateSwitch)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == bitrate), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    TT_ParaCheck(((TRUE != bitRateSwitch) && (FALSE != bitRateSwitch)), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean fd_enable = FlexCAN_IsFDEnabled(pBase);
        /* Check if the FlexCAN is enabled or not */
        TT_CONST boolean disabled = (boolean)(((pBase->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_MDIS_Msk) != 0U) ? TRUE : FALSE);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        /* Check if controller is in freeze mode or not */
        TT_CONST boolean freeze = (boolean)(((pBase->FLEXCAN_MCR & (TT_CAN_FLEXCAN_MCR_FRZACK_Msk)) != 0U)? TRUE : FALSE);

        if ((FALSE == fd_enable) || ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal)))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
            TT_CONST boolean enhCbt = FlexCAN_IsBteEnabled(pBase);
#endif

            FlexCAN_SetFDEnabled(pBase, fd_enable, bitRateSwitch);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
            if (TRUE == enhCbt)
            {
                FlexCAN_SetEnhancedDataTimeSegments(pBase, bitrate);
            }
            else
#endif
            {
                /* Set time segments*/
                FlexCAN_SetFDTimeSegments(pBase, bitrate);
            }

        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if (TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Enables/Disables the Transceiver Delay Compensation feature and sets the Transceiver Delay Compensation Offset
* @details      Enables/Disables the Transceiver Delay Compensation feature and sets the Transceiver Delay Compensation Offset
* @param[in]    instance - A CAN instance number
* @param[in]    enable - Enables/Disables the Transceiver Delay Compensation
* @param[in]    offset - the Transceiver Delay Compensation Offset
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetTDCOffset_Privileged(uint8 instance, boolean enable, uint8 offset)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((TRUE != enable) && (FALSE != enable)), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);
        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        TT_CONST boolean freeze = FlexCAN_IsFreezeMode(pBase);

        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if(TT_RET_SUCCESS == TTRetVal)
        {

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
            /* End critical section: implementation depends on integrator */
            if (TT_CAN_FLEXCAN_CTRL2_BTE_Msk == (pBase->FLEXCAN_CTRL2 & TT_CAN_FLEXCAN_CTRL2_BTE_Msk))
            {
                FlexCAN_SetEnhancedTDCOffset(pBase, enable, offset);
            }
            else
#endif
            {
                /* Enable/Disable TDC and set the TDC Offset */
                FlexCAN_SetTDCOffset(pBase, enable, offset);
            }

            /* Check if enhaced CBT is Enabled */
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set FlexCAN Tx Arbitration Start Delay
* @details      Set FlexCAN Tx Arbitration Start Delay
* @param[in]    instance - A CAN instance number
* @param[in]    value - Tx Arbitration Start Delay
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetTxArbDelay_Privileged(uint8 instance,  uint8 value)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        TT_CONST boolean freeze = FlexCAN_IsFreezeMode(pBase);

        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
            FlexCAN_SetTxArbitrationStartDelay(pBase, value);
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if (TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
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
TT_RetType Can_Hw_GetBuffStatusFlag(uint8 instance, uint8 msgBuffIdx, boolean * flag)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((msgBuffIdx >= (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM) && (FLEXCAN_HW_MB_ENHANCED_RXFIFO != msgBuffIdx)), TT_RET_PARAM_INDEX_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == flag), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        if (FLEXCAN_HW_MB_ENHANCED_RXFIFO == msgBuffIdx)
        {
            *flag = (boolean)((1U == FlexCAN_GetEnhancedRxFIFOStatusFlag(pBase, FLEXCAN_HW_ENHANCED_RXFIFO_OVERFLOW)) ? TRUE : FALSE);
        }
        else
#endif
        {
            *flag = (boolean)((1U == FlexCAN_GetBuffStatusFlag(pBase, msgBuffIdx)) ? TRUE : FALSE);
        }
    }
    else
    {

    }
    return TTRetVal;
}

/**
* @brief        Clear FlexCAN Message Buffer Status Flag
* @details      Clear FlexCAN Message Buffer Status Flag
* @param[in]    instance - A CAN instance number
* @param[in]    msgBuffIdx - Index of the message buffer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_ClearBuffStatusFlag(uint8 instance, uint8 msgBuffIdx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((msgBuffIdx >= (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM) && (FLEXCAN_HW_MB_ENHANCED_RXFIFO != msgBuffIdx)), TT_RET_PARAM_INDEX_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        if (FLEXCAN_HW_MB_ENHANCED_RXFIFO == msgBuffIdx)
        {
            FlexCAN_ClearEnhancedRxFifoIntStatusFlag(pBase, FLEXCAN_HW_ENHANCED_RXFIFO_OVERFLOW);
        }
        else
#endif
        {
            FlexCAN_ClearMsgBuffIntStatusFlag(pBase, msgBuffIdx);
        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Enable all mb interrupts configured
* @details      Enable all mb interrupts configured
* @param[in]    u8Instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_EnInterrupts_Privileged(uint8 u8Instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        state = Flexcan_Hw_apxState[u8Instance];
        if (TRUE == FlexCAN_IsEnabled(pBase))
        {
            TTRetVal = Can_Hw_PriEnableInterrupts(pBase, u8Instance);
            if(TT_RET_SUCCESS == TTRetVal)
            {
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
                if ((TRUE == FlexCAN_IsEnhancedRxFifoEnabled(pBase)) && (FALSE == state->enhancedFifoOutput.isPolling))
                {   /* Check if Enabled Enhanced Fifo */
                    FlexCAN_SetEnhancedRxFifoIntAll(pBase, TRUE);
                }
                else
                {

                }
#endif
                state->isIntActive = TRUE;
            }
            else
            {

            }
        }
        else
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Disable all mb interrupts configured
* @details      Disable all mb interrupts configured
* @param[in]    u8Instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_DisInterrupts_Privileged(uint8 u8Instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        if (TRUE == FlexCAN_IsEnabled(pBase))
        {
            TTRetVal = Can_Hw_PriDisableInterrupts(pBase);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
            /* Check if Enabled Enhanced Fifo */
            if((TRUE == FlexCAN_IsEnhancedRxFifoEnabled(pBase)) && (TT_RET_SUCCESS == TTRetVal))
            {
                FlexCAN_SetEnhancedRxFifoIntAll(pBase, FALSE);
            }
            else
            {

            }
#endif

        }
        else
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
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
TT_RetType Can_Hw_SetPriority(uint8 u8Instance, Flexcan_TxPriority TxPrio, Flexcan_RxPriority RxPrio)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        if(FlexCAN_IsFreezeMode(pBase) == false)
        {
            TTRetVal = Can_Hw_PriEnterFreezeMode(pBase);
        }
        else
        {

        }
        if(TT_RET_SUCCESS == TTRetVal)
        {
            switch(TxPrio)
            {
            case CAN_TX_PRIORITY_LOW_NUMBER:
                pBase->FLEXCAN_CTRL1 &= ~TT_CAN_FLEXCAN_CTRL1_LBUF_Msk;
                pBase->FLEXCAN_CTRL1 |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LBUF, 1U);
                break;

            case CAN_TX_PRIORITY_LOCAL_ENABLE:
                pBase->FLEXCAN_CTRL1 &= ~TT_CAN_FLEXCAN_CTRL1_LBUF_Msk;
                pBase->FLEXCAN_MCR &= ~TT_CAN_FLEXCAN_MCR_LPRIOEN_Msk;

                pBase->FLEXCAN_CTRL1 |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LBUF, 0U);
                pBase->FLEXCAN_MCR |= TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_LPRIOEN, 1U);

                break;

            case CAN_TX_PRIORITY_LOCAL_DISABLE:
                pBase->FLEXCAN_CTRL1 &= ~TT_CAN_FLEXCAN_CTRL1_LBUF_Msk;
                pBase->FLEXCAN_MCR &= ~TT_CAN_FLEXCAN_MCR_LPRIOEN_Msk;

                pBase->FLEXCAN_CTRL1 |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LBUF, 0U);
                pBase->FLEXCAN_MCR |= TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_LPRIOEN, 0U);
                break;
                
            default:
                TTRetVal = TT_RET_PARAM_ERR;
                break;
            }

            switch(RxPrio)
            {
            case CAN_RX_PRIORITY_RXFIFO_TO_MB:
                pBase->FLEXCAN_CTRL2 &= ~TT_CAN_FLEXCAN_CTRL2_MRP_Msk;
                pBase->FLEXCAN_CTRL2 |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_MRP, 0U);
                break;

            case CAN_RX_PRIORITY_MB_TO_RXFIFO:
                pBase->FLEXCAN_CTRL2 &= ~TT_CAN_FLEXCAN_CTRL2_MRP_Msk;
                pBase->FLEXCAN_CTRL2 |= TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_MRP, 1U);
                break;
            default:
                TTRetVal = TT_RET_PARAM_ERR;
                break;
            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Enable\Disable Error or BusOff Interrupt
* @details      Enable\Disable Error or BusOff Interrupt
* @param[in]    u8Instance - A CAN instance number
* @param[in]    type - Error Int Type
* @param[in]    enable - Enable\Disable Error Interrupt
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetErrorInt_Privileged(uint8 u8Instance, Flexcan_Hw_ErrorIntType type, boolean enable)
{

    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((TRUE != enable) && (FALSE != enable)), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        if(TT_RET_SUCCESS == TTRetVal)
        {
            switch (type)
            {
                case FLEXCAN_HW_INT_BUSOFF:
                {
                    TTRetVal = Can_Hw_PriSetErrIntCmd(pBase, FLEXCAN_INT_BUSOFF, enable);
                    break;
                }
                case FLEXCAN_HW_INT_ERR:
                {
                    TTRetVal = Can_Hw_PriSetErrIntCmd(pBase, FLEXCAN_INT_ERR, enable);
                    break;
                }
                case FLEXCAN_HW_INT_ERR_FAST :
                {
                    TTRetVal = Can_Hw_PriSetErrIntCmd(pBase, FLEXCAN_INT_ERR_FAST, enable);
                    break;
                }
                case FLEXCAN_HW_INT_RX_WARNING :
                {

                    if (TRUE != FlexCAN_IsFreezeMode(pBase))
                    {
                        TTRetVal = TT_RET_STATUS_ERR;
                    }
                    else
                    {
                        TTRetVal = Can_Hw_PriSetErrIntCmd(pBase, FLEXCAN_INT_RX_WARNING, enable);
                    }
                    break;
                }
                case FLEXCAN_HW_INT_TX_WARNING :
                {

                    if (TRUE != FlexCAN_IsFreezeMode(pBase))
                    {
                        TTRetVal = TT_RET_STATUS_ERR;
                    }
                    else

                    {
                        TTRetVal = Can_Hw_PriSetErrIntCmd(pBase, FLEXCAN_INT_TX_WARNING, enable);
                    }
                    break;
                }
                default:
                    TTRetVal = TT_RET_PARAM_ERR;
                    break;
            }
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
* @brief        Configure the number of words to transfer for each Enhanced Rx FIFO data element in DMA mode
* @details      Configure the number of words to transfer for each Enhanced Rx FIFO data element in DMA mode
* @param[in]    u8Instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_ConfigRxFifoDMAReqCount(uint8 u8Instance)
{   
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    uint32 reqCount = 0;
    TT_CONST uint32 numOfWords = 20U;
    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        if(TRUE == ((pBase->FLEXCAN_ERFCR & TT_CAN_FLEXCAN_ERFCR_ERFEN_Msk) >> TT_CAN_FLEXCAN_ERFCR_ERFEN_Pos))
        {
            reqCount = (uint32)((4UL * numOfWords) / 16UL);
            pBase->FLEXCAN_CTRL2 |= (uint32)(reqCount & 0x7U);
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}
#endif

/**
* @brief        This function shuts down the CAN by disabling interrupts and the transmitter/receiver
* @details      This function shuts down the CAN by disabling interrupts and the transmitter/receiver
* @param[in]    u8Instance - A CAN instance number
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_AbortTransfer(uint8 u8Instance, uint8 mb_idx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;

    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((mb_idx >= (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM) && (255u != mb_idx)), TT_RET_PARAM_INDEX_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        state = Flexcan_Hw_apxState[u8Instance];
        if (mb_idx < (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM)
        {
            if (FLEXCAN_MB_IDLE == state->mbs[mb_idx].state)
            {
                TTRetVal = TT_RET_IO_ABORT_ERR;
            }
            else
            {
                TTRetVal = Can_Hw_PriClearMsgBuffIntCmd(pBase, u8Instance, mb_idx, state->isIntActive);
                    if((FLEXCAN_MB_TX_BUSY == state->mbs[mb_idx].state) && (TT_RET_SUCCESS == TTRetVal))
                    {
                        TTRetVal = Can_Hw_PriAbortTxTransfer(u8Instance, mb_idx);
                    }
                    else
                    {

                    }

                    if((FLEXCAN_MB_RX_BUSY == state->mbs[mb_idx].state) && (TT_RET_SUCCESS == TTRetVal))
                    {
                        TTRetVal = Can_Hw_PriAbortRxTransfer(u8Instance, mb_idx);
                    }
                    else
                    {

                    }
            }
        }
        else
        {
#if ((FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) && (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON))
            /* Check if transfer is done over DMA and stop transfer */
            if ((FLEXCAN_MB_RX_BUSY == state->enhancedFifoOutput.state) && (FLEXCAN_RXFIFO_USING_DMA == state->transferType))
            {
                state->enhancedFifoOutput.state = FLEXCAN_MB_IDLE;
            }
            else
            {
                TTRetVal = TT_RET_IO_ABORT_ERR;
            }
#endif /* if FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set Rx14Mask filter for message buffer 14
* @details      Set Rx14Mask filter for message buffer 14
* @param[in]    instance - A CAN instance number
* @param[in]    mask - Rx mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxMb14Mask_Privileged(uint8 instance, uint32 mask)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        boolean freeze = FALSE;
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        freeze = FlexCAN_IsFreezeMode(pBase);

        if((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if(TT_RET_SUCCESS == TTRetVal)
        {
            pBase->FLEXCAN_RX14MASK = mask;
        }
        else
        {

        }
        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set Rx15Mask filter for message buffer 15
* @details      Set Rx15Mask filter for message buffer 15
* @param[in]    instance - A CAN instance number
* @param[in]    mask - Rx mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxMb15Mask_Privileged(uint8 instance, uint32 mask)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        boolean freeze = FALSE;
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        freeze = FlexCAN_IsFreezeMode(pBase);

        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
            pBase->FLEXCAN_RX15MASK = mask;
        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if (TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set FlexCAN Listen Only
* @details      Set FlexCAN Listen Only
* @param[in]    instance - A CAN instance number
* @param[in]    enable - enable or disable Listen Only mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetLisOnlyMode_Privileged(uint8 instance, TT_CONST boolean enable)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((TRUE != enable) && (FALSE != enable)), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);
        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        TT_CONST boolean freeze = FlexCAN_IsFreezeMode(pBase);

        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {

            FlexCAN_SetListenOnlyMode(pBase, enable);

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if (TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#if (FLEXCAN_HW_FEATURE_HAS_TS_ENABLE == STD_ON)
/**
* @brief        Timestamp configuration
* @details      Timestamp configuration
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_CfgTimeStamp_Privileged(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[instance];
        TT_CONST boolean disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }

        TT_CONST boolean freeze = FlexCAN_IsFreezeMode(pBase);

        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
            pBase->FLEXCAN_CTRL2 &= ~(TT_CAN_FLEXCAN_CTRL2_TIMER_SRC_Msk | TT_CAN_FLEXCAN_CTRL2_MBTSBASE_Msk);
        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
        }

    }
    else
    {

    }

    return TTRetVal;
}
#endif /* FLEXCAN_HW_FEATURE_HAS_TS_ENABLE */

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/**
* @brief        Configures Pretended Networking settings
* @details      Configures Pretended Networking settings
* @param[in]    instance - A CAN instance number
* @param[in]    bEnable - Enable Pretended Networking
* @param[in]    pPnConfig - Pn Config data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_ConfigPN_Privileged(uint8 u8Instance,
                                          boolean bEnable,
                                          TT_CONST Flexcan_Hw_PnConfigType * pPnConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType status = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((TRUE != bEnable) && (FALSE != bEnable)), TT_RET_PARAM_VALUE_ERR, &TTRetVal);
    TT_ParaCheck(((NULL_PTR == pPnConfig) && (TRUE == bEnable)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        boolean disabled = !FlexCAN_IsEnabled(pBase);

        if (TRUE == disabled)
        {
            TTRetVal = Can_Hw_PriEnable(pBase);
        }
        else
        {

        }

        boolean freeze = FlexCAN_IsFreezeMode(pBase);

        if ((FALSE == freeze) && (TT_RET_SUCCESS == TTRetVal))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if (TT_RET_SUCCESS == TTRetVal)
        {
            if (bEnable)
            {
                TTRetVal = Can_Hw_PriConfigPN(pBase, pPnConfig);
            }
            else
            {

            }

            FlexCAN_SetPN(pBase, bEnable);

        }
        else
        {

        }

        if (TRUE == disabled)
        {
            status = Can_Hw_PriDisable(pBase);
            if (TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = status;
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

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
        Flexcan_Hw_MsgBuffType * pWmb)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;

    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((u8WmbIndex >= 4), TT_RET_PARAM_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == pWmb), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        uint32 * pTmp, pWmbData;

        pTmp = (uint32 *)(uint32)(pWmb->data);
        pWmbData = pBase->WMB[u8WmbIndex].FLEXCAN_WMB_D03;
        FLEXCAN_HW_SWAP_BYTES_IN_WORD(pWmbData, *pTmp);

        pWmbData = pBase->WMB[u8WmbIndex].FLEXCAN_WMB_D47;
        FLEXCAN_HW_SWAP_BYTES_IN_WORD(pWmbData, pTmp[1]);

        pWmb->cs = pBase->WMB[u8WmbIndex].FLEXCAN_WMB_CS;

        if ((pWmb->cs & FLEXCAN_HW_CS_IDE_Msk) != 0U)
        {
            pWmb->msgId = pBase->WMB[u8WmbIndex].FLEXCAN_WMB_ID;
        }
        else
        {
            pWmb->msgId = pBase->WMB[u8WmbIndex].FLEXCAN_WMB_ID >> FLEXCAN_HW_ID_STD_Pos;
        }

        pWmb->dataLen = (uint8)((pWmb->cs & FLEXCAN_HW_CS_DLC_Msk) >> 16U);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Wake up handler for CAN
* @details      Wake up handler for CAN
* @param[in]    u8Instance - A CAN instance number
* @return       void
* @retval       None
*/
void CANx_Wakeup_IRQHandler(uint8 u8Instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        TT_CAN_Type * pBase = Flexcan_Hw_apxBase[u8Instance];
        TT_CONST Flexcan_Hw_StateType * pState = Flexcan_Hw_apxState[u8Instance];
        if(FlexCAN_GetWTOF(pBase) != 0U)
        {
            FlexCAN_ClearWTOF(pBase);
            /* Invoke callback */
            if ((0U != FlexCAN_GetWTOIE(pBase)) && (pState->callback != NULL_PTR))
            {
                pState->callback(u8Instance, FLEXCAN_EVENT_WAKEUP_TIMEOUT, 0U, pState);
            }
            else
            {

            }
        }
        else
        {

        }


        if (FlexCAN_GetWUMF(pBase) != 0U)
        {
            FlexCAN_ClearWUMF(pBase);
            /* Invoke callback */
            if ((0U != FlexCAN_GetWUMIE(pBase)) && (pState->callback != NULL_PTR))
            {
                pState->callback(u8Instance, FLEXCAN_EVENT_WAKEUP_MATCH, 0U, pState);
            }
            else
            {

            }
        }
        else
        {

        }

        if(FlexCAN_GetWAKINT(pBase) != 0U)
        {
            FlexCAN_ClearWAKINT(pBase);
            /* Invoke callback */
            if ((0U != FlexCAN_GetWAKIE(pBase)) && (pState->callback != NULL_PTR))
            {
                pState->callback(u8Instance, FLEXCAN_EVENT_WAKEUP_MATCH, 0U, pState);
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }
}

#endif /* FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING */

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Get CAN TXWRN Status Flag
* @details      Get CAN TXWRN Status Flag
* @param[in]    Instance - Can Instance
* @param[out]   TXWRNS_Flag - TX warning Status flag
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_TXWRNStatusFlag(uint8 Instance,boolean *TXWRNS_Flag)
{
    TT_CAN_Type * pBase = NULL_PTR;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == TXWRNS_Flag), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[Instance];
        if(((pBase->FLEXCAN_ESR1 & TT_CAN_FLEXCAN_ESR1_TXWRN_Msk) >> TT_CAN_FLEXCAN_ESR1_TXWRN_Pos) == TRUE)
        {
            /* TXERRCNT is greater than or equal to 96 */
            *TXWRNS_Flag = TRUE;
        }
        else
        {
            *TXWRNS_Flag = FALSE;
        }
    }
    else
    {

    }
    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Initialize fifo and dma if requested
* @details      Initialize fifo and dma if requested
* @param[in]    pBase - The CAN base address
* @param[in]    Flexcan_Hw_pData - Can Hardware Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriInitRxFifo(TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_ConfigType * Flexcan_Hw_pData)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == pBase)
            || (NULL_PTR == Flexcan_Hw_pData)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* Enable RxFIFO feature, if requested. This might fail if the FD mode is enabled. */
        if (Flexcan_Hw_pData->is_rx_fifo_needed)
        {
            TTRetVal = Can_Hw_PriEnableRxFifo(pBase, (uint32)Flexcan_Hw_pData->num_id_filters);
        }
        else
        {

        }

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        /* Enable Enhanced RxFIFO feature, if requested.
         * This might fail if the current CAN instance does not support Enhaneced RxFIFO or the Rx FIFO is enabled. */
        if ((TT_RET_SUCCESS == TTRetVal) && (Flexcan_Hw_pData->is_enhanced_rx_fifo_needed))
        {
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
            if (FLEXCAN_RXFIFO_USING_DMA == Flexcan_Hw_pData->transfer_type)
            {
                TTRetVal = Can_Hw_PriEnableEnhancedRxFifo(pBase,
                        (uint32)Flexcan_Hw_pData->num_enhanced_std_id_filters,
                        (uint32)Flexcan_Hw_pData->num_enhanced_ext_id_filters,
                        (uint32)0U); /* for dma, each a frame received -> a minor loop */
            }
            else
#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
            {
                TTRetVal = Can_Hw_PriEnableEnhancedRxFifo(pBase,
                        (uint32)Flexcan_Hw_pData->num_enhanced_std_id_filters,
                        (uint32)Flexcan_Hw_pData->num_enhanced_ext_id_filters,
                        (uint32)Flexcan_Hw_pData->num_enhanced_watermark);
            }
        }
        else
        {

        }
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        if (TT_RET_SUCCESS == TTRetVal)
        {
            /* Enable DMA support for RxFIFO transfer, if requested. */
            if (FLEXCAN_RXFIFO_USING_DMA == Flexcan_Hw_pData->transfer_type)
            {
                if (((pBase->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_RFEN_Msk) >> TT_CAN_FLEXCAN_MCR_RFEN_Pos) != 0U)
                {
                    FlexCAN_SetRxFifoDMA(pBase, TRUE);
                }
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
                else if (FlexCAN_IsEnhancedRxFifoEnabled(pBase))
                {
                    FlexCAN_SetRxFifoDMA(pBase, TRUE);
                    FlexCAN_ConfigEnhancedRxFifoDMA(pBase, 20U);
                }
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
                else
                {
                    TTRetVal = TT_RET_STATUS_ERR;
                }
            }
            else
            {
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
                /* Clear Enhanced Rx FIFO status.*/
                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(pBase, FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE);
                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(pBase, FLEXCAN_HW_ENHANCED_RXFIFO_WATERMARK);
                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(pBase, FLEXCAN_HW_ENHANCED_RXFIFO_OVERFLOW);
                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(pBase, FLEXCAN_HW_ENHANCED_RXFIFO_UNDERFLOW);
                /* Clear the Enhanced RX FIFO engine */
                FlexCAN_ClearEnhancedRxFifoEngine(pBase);

#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */
                FlexCAN_SetRxFifoDMA(pBase, FALSE);
            }
        }
        else
        {

        }
#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Initialize basically controller
* @details      Initialize basically controller
* @param[in]    pBase - The CAN base address
* @param[in]    Flexcan_Hw_pData - Can Hardware Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriInitCtroll(TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_ConfigType * Flexcan_Hw_pData)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == pBase)
            || (NULL_PTR == Flexcan_Hw_pData)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* Disable the self reception feature if FlexCAN is not in loopback mode. */
        if (Flexcan_Hw_pData->flexcanMode != FLEXCAN_LOOPBACK_MODE)
        {
            FlexCAN_SetSelfReception(pBase, FALSE);
        }
        else
        {

        }

        /* Init legacy fifo, enhanced fifo if requested. */
        TTRetVal = Can_Hw_PriInitRxFifo(pBase, Flexcan_Hw_pData);
        if(TT_RET_SUCCESS == TTRetVal)
        {
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            /* Set payload size. */
            TTRetVal = Can_Hw_PriSetPayloadSize(pBase, &Flexcan_Hw_pData->payload);
            if(TT_RET_SUCCESS == TTRetVal)
            {
#endif /* FLEXCAN_HW_FEATURE_HAS_FD */
                TTRetVal = Can_Hw_PriSetMaxMsgBuffNum(pBase, Flexcan_Hw_pData->max_num_mb);
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            }
            else
            {

            }
#endif/* FLEXCAN_HW_FEATURE_HAS_FD */
        }
        else
        {

        }

        if(TT_RET_SUCCESS != TTRetVal)
        {
            /* To enter Disable Mode requires FreezMode first */
            if (FlexCAN_IsFreezeMode(pBase) == FALSE)
            {
                (void)Can_Hw_PriEnterFreezeMode(pBase);
            }
            else
            {

            }
            (void)Can_Hw_PriDisable(pBase);
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Initialize basically controller
* @details      Initialize basically controller
* @param[in]    Instance - CAN Instance
* @param[in]    pBase - The CAN base address
* @param[in]    Flexcan_Hw_pData - Can Hardware Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriInitController(uint8 Instance, TT_CAN_Type * pBase, TT_CONST Flexcan_Hw_ConfigType * Flexcan_Hw_pData)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((NULL_PTR == pBase)
            || (NULL_PTR == Flexcan_Hw_pData)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        if (FlexCAN_IsFreezeMode(pBase) == FALSE)
        {
            TTRetVal = Can_Hw_PriEnterFreezeMode(pBase);
        }
        else
        {

        }

        if(TT_RET_SUCCESS == TTRetVal)
        {
            /* Initialize FLEXCAN device */
            TTRetVal = Can_Hw_PriInit(pBase);
            if(TT_RET_SUCCESS == TTRetVal)
            {
#if (FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET == STD_ON)
                /* Disable the Protection again because is enabled by soft reset */
                FlexCAN_DisableMemErrorDetection(pBase);
#endif

                /* Enable/Disable FD and check FD was set as expected. Setting FD as enabled
                 * might fail if the current CAN instance does not support FD. */
                FlexCAN_SetFDEnabled(pBase, Flexcan_Hw_pData->fd_enable, Flexcan_Hw_pData->bitRateSwitch);
                /* No more required, I don't expect any other NPIs with and without Interfaces with FD support
                 * if (FLEXCAN_IsFDEnabled(base) != Flexcan_Hw_pData->fd_enable)
            {
                return FLEXCAN_STATUS_ERROR;
            }*/
                /* configure depends on controller options. */
                TTRetVal = Can_Hw_PriConfigCtrlOptions(pBase, Flexcan_Hw_pData->ctrlOptions);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    /* reset Imask buffers */
                    TTRetVal = Can_Hw_PriResetImaskBuff(Instance);
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        TTRetVal = Can_Hw_PriInitCtroll(pBase, Flexcan_Hw_pData);
                    }
                    else
                    {

                    }
                }
                else
                {

                }
            }
            else
            {

            }

            if(TT_RET_SUCCESS != TTRetVal)
            {
                /* To enter Disable Mode requires FreezMode first */
                (void)Can_Hw_PriDisable(pBase);
            }
            else
            {

            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"


#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        The process of receiving data and disabling the interrupt
* @details      Finish up a receive by completing the process of receiving data and disabling the interrupt
* @param[in]    Instance - CAN Instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriCompleteRxMsgFifoData(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType TTRetValArray[3] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
        if (FLEXCAN_RXFIFO_USING_INTERRUPTS == state->transferType)
        {
            /* Disable RX FIFO interrupts*/
            TTRetValArray[0] = Can_Hw_PriSetMsgBuffIntCmd(base, instance, FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE, FALSE, state->isIntActive);
            TTRetValArray[1] = Can_Hw_PriSetMsgBuffIntCmd(base, instance, FLEXCAN_HW_LEGACY_RXFIFO_WARNING, FALSE, state->isIntActive);
            TTRetValArray[2] = Can_Hw_PriSetMsgBuffIntCmd(base, instance, FLEXCAN_HW_LEGACY_RXFIFO_OVERFLOW, FALSE, state->isIntActive);
            if((TT_RET_SUCCESS != TTRetValArray[0])
                    || (TT_RET_SUCCESS != TTRetValArray[1])
                    || (TT_RET_SUCCESS != TTRetValArray[2]))
            {
                TTRetVal = TT_RET_OPT_REG_ERR;
            }
            else
            {

            }
        }
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if (FLEXCAN_RXFIFO_USING_DMA == state->transferType)
        {
            if (state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state != FLEXCAN_MB_DMA_ERROR)
            {
                Flexcan_Hw_MsgBuffType * fifo_message = state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].pMBmessage;
                uint32 *TT_CONST msgData_32 = (uint32 *)(uint32)fifo_message->data;

                /* Adjust the ID if it is not extended */
                if (0U == ((fifo_message->cs) & FLEXCAN_HW_CS_IDE_Msk))
                {
                    fifo_message->msgId = (fifo_message->msgId >> FLEXCAN_HW_ID_STD_Pos);
                }
                else
                {

                }

                /* Extract the data length */
                fifo_message->dataLen = (uint8)((fifo_message->cs & FLEXCAN_HW_CS_DLC_Msk) >> FLEXCAN_HW_CS_DLC_Pos);
                /* Extract the IDHIT */
                fifo_message->id_hit = (uint8)((fifo_message->cs & FLEXCAN_HW_CS_IDHIT_Msk) >> FLEXCAN_HW_CS_IDHIT_Pos);
                /* Extract the Time Stamp */
                fifo_message->time_stamp = (uint32)((fifo_message->cs & FLEXCAN_HW_CS_TIME_STAMP_Msk) >> FLEXCAN_HW_CS_TIME_STAMP_Pos);
                /* Reverse the endianness */
                FLEXCAN_HW_SWAP_BYTES_IN_WORD(msgData_32[0], msgData_32[0]);
                FLEXCAN_HW_SWAP_BYTES_IN_WORD(msgData_32[1], msgData_32[1]);
            }
            else
            {

            }
        }
        else
        {
            /* do nothing when transferType is POLLING */
        }
#endif /* if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
        /* Clear fifo message*/
        state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].pMBmessage = NULL_PTR;

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        if (state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state != FLEXCAN_MB_DMA_ERROR)
        {
            state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state = FLEXCAN_MB_IDLE;

            if ((state->callback != NULL_PTR) && (FLEXCAN_RXFIFO_USING_DMA == state->transferType))
            {
                state->callback(instance, FLEXCAN_EVENT_DMA_COMPLETE, FLEXCAN_HW_MB_HANDLE_RXFIFO, state);
            }
            else
            {

            }
        }
        else
        {

        }
#else
    state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state = FLEXCAN_MB_IDLE;
#endif /* if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
    }
    else
    {

    }

    return TTRetVal;
}


#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
* @brief        The process of receiving data and disabling the interrupt
* @details      Finish up a receive by completing the process of receiving data and disabling the interrupt
* @param[in]    Instance - CAN Instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriCompRxMsgEnFifoData(uint8 instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
    uint8 j = 0;
    Flexcan_Hw_MsgBuffType * fifo_message = NULL_PTR;
    uint32 * msgData_32 = NULL_PTR;
    uint8 flexcan_mb_dlc_value = 0U;
    uint8 can_dlc_payload = 0U;
    uint8 can_real_payload = 0U;
#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
        if(FALSE == state->enhancedFifoOutput.isPolling)
        {
            /* Reset to default value to avoid re-enable when calling Ip_EnableInterrupt */
            state->enhancedFifoOutput.isPolling = TRUE;
            /* Disable Enhanced RX FIFO interrupts*/
            FlexCAN_SetEnhancedRxFifoIntAll(base, FALSE);
        }
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if(FLEXCAN_RXFIFO_USING_DMA == state->transferType)
        {
            if(state->enhancedFifoOutput.state != FLEXCAN_MB_DMA_ERROR)
            {
                fifo_message = state->enhancedFifoOutput.pMBmessage;

                msgData_32 = &((uint32 *)((uint32)fifo_message))[2U];
                /* Adjust the ID if it is not extended */
                if (0U == ((fifo_message->cs) & FLEXCAN_HW_CS_IDE_Msk))
                {
                    fifo_message->msgId = fifo_message->msgId >> FLEXCAN_HW_ID_STD_Pos;
                }
                else
                {

                }

                /* Extract the data length */
                flexcan_mb_dlc_value = (uint8)((fifo_message->cs & FLEXCAN_HW_CS_DLC_Msk) >> FLEXCAN_HW_CS_DLC_Pos);
                can_dlc_payload = Can_Hw_PriComputePayloadSize(flexcan_mb_dlc_value);
                /* Extract the IDHIT and Time Stamp */
                if ((fifo_message->cs & FLEXCAN_HW_CS_RTR_Msk) != 0U)
                {
                    can_real_payload = 0U;
                }
                else
                {
                    can_real_payload = can_dlc_payload;
                }

                TT_CONST uint8 idhit_offset = (can_real_payload >> 2U) + (((can_real_payload % 4U) != 0U) ? 1U : 0U);

                fifo_message->time_stamp = (uint32)((fifo_message->cs & FLEXCAN_HW_CS_TIME_STAMP_Msk) >> FLEXCAN_HW_CS_TIME_STAMP_Pos);

                /* Extract the IDHIT */
                fifo_message->id_hit = (uint8)(((msgData_32[idhit_offset]) & FLEXCAN_HW_ENHANCED_IDHIT_Msk) >> FLEXCAN_HW_ENHANCED_IDHIT_Pos);
                /* Extract the dataLen */
                fifo_message->dataLen = can_dlc_payload;
                /* Reverse the endianness */
                for (j = 0U; j < idhit_offset; j++)
                {
                    FLEXCAN_HW_SWAP_BYTES_IN_WORD(msgData_32[j], msgData_32[j]);
                }

            }
            else
            {
                /* If Enhanced Rx FIFO has Pending Request that generated error,
                 * the EnhancedRxFIFO need to be empty to activate DMA */
                TTRetVal = Can_Hw_PriClearOutputEnhanceFIFO(base);
            }
        }
#endif /* if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
        else
        {
            /* avoid misra */
        }

        /* Clear enhanced rx fifo message*/
        state->enhancedFifoOutput.pMBmessage = NULL_PTR;

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        if(state->enhancedFifoOutput.state != FLEXCAN_MB_DMA_ERROR)
        {
            state->enhancedFifoOutput.state = FLEXCAN_MB_IDLE;
            if((state->callback != NULL_PTR) && (FLEXCAN_RXFIFO_USING_DMA == state->transferType))
            {
                state->callback(instance, FLEXCAN_EVENT_DMA_COMPLETE, FLEXCAN_HW_MB_ENHANCED_RXFIFO, state);
            }
            else
            {

            }
        }
        else
        {

        }
#else  /* if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
        state->enhancedFifoOutput.state = FLEXCAN_MB_IDLE;
#endif /* if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        The process of receiving data and enabling the interrupt
* @details      Initiate (start) a receive by beginning the process of receiving data and enabling the interrupt
* @param[in]    instance - CAN Instance
* @param[in]    data - Data receiving address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriStartRxMsgEnFifoData(uint8 instance, Flexcan_Hw_MsgBuffType * data)
{
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];
        /* Start receiving fifo */
        if(FLEXCAN_MB_RX_BUSY == state->enhancedFifoOutput.state)
        {
            TTRetVal = TT_RET_IO_BUSY_ERR;
        }
        else
        {
            state->enhancedFifoOutput.state = FLEXCAN_MB_RX_BUSY;
            /* This will get filled by the interrupt handler */
            state->enhancedFifoOutput.pMBmessage = data;
            if(FLEXCAN_RXFIFO_USING_INTERRUPTS == state->transferType)
            {
                state->enhancedFifoOutput.isPolling = FALSE;
                if (TRUE == state->isIntActive)
                {
                    /* Enable All Enhanced RX FIFO interrupts*/
                    FlexCAN_SetEnhancedRxFifoIntAll(base, TRUE);
                }
                else
                {

                }
            }
            else
            {

            }
            if(FLEXCAN_RXFIFO_USING_POLLING == state->transferType)
            {
                state->enhancedFifoOutput.isPolling = TRUE;
            }
            else
            {

            }

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
            if (FLEXCAN_RXFIFO_USING_DMA == state->transferType)
            {
                TT_ParaCheck((NULL_PTR == data), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    volatile uint32 *address;
                    address = (volatile uint32 *)((uint32)base + FLEXCAN_HW_FEATURE_EXP_RXFIFO_OFFSET);

                    TTRetVal = Dma_Drv_ChannelConfigure (&DmaChannelConfig[state->rxFifoDMAChannel],
                            20U,
                            (uint32)address,
                            (uint32)data,
                            state->cb_event);
                }
                else
                {

                }
            }
            else
            {

            }
#endif /* if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
        }
    }
    else
    {

    }

    return TTRetVal;
}

#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        The process of receiving data and enabling the interrupt
* @details      Initiate (start) a receive by beginning the process of receiving data and enabling the interrupt
* @param[in]    instance - CAN Instance
* @param[in]    mb_idx - mb index
* @param[in]    data - Data receiving address
* @param[in]    isPolling - Whether polling is enabled
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriStartRxMsgBufferData(uint8 instance,
                                                              uint8 mb_idx,
                                                              Flexcan_Hw_MsgBuffType * data,
                                                              boolean isPolling)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
            base = Flexcan_Hw_apxBase[instance];
            state = Flexcan_Hw_apxState[instance];
            if (TRUE == Can_Hw_PriIsMbOutOfRange(base, mb_idx, state->bIsLegacyFifoEn, state->u32MaxMbNum))
            {
                TTRetVal = TT_RET_PARAM_INDEX_ERR;
            }
            else
            {
                /* Start receiving mailbox */
                if((state->mbs[mb_idx].state == FLEXCAN_MB_IDLE) || (state->mbs[mb_idx].state == FLEXCAN_MB_RX_OVER_ERROR))
                {
                    state->mbs[mb_idx].state = FLEXCAN_MB_RX_BUSY;
                    state->mbs[mb_idx].pMBmessage = data;
                    state->mbs[mb_idx].isPolling = isPolling;
                }
                else
                {
                    TTRetVal = TT_RET_IO_BUSY_ERR;
                }
            }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Initiate (start) a transmit by beginning the process of sending data
* @details      Initiate (start) a transmit by beginning the process of sending data
* @param[in]    Flexcan_Hw_u8Instance - CAN Instance
* @param[in]    mb_idx - mb index
* @param[in]    tx_info - Points to send message data
* @param[in]    msg_id - Message id
* @param[in]    mb_data - Points to send data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriStartSendData(uint8 Flexcan_Hw_u8Instance,
                                                   uint8 mb_idx,
                                                   TT_CONST Flexcan_Hw_DataInfoType * tx_info,
                                                   uint32 msg_id,
                                                   TT_CONST uint8 * mb_data
                                                  )
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_MsbuffCodeStatusType cs = {0};
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    volatile uint32 * pMbAddr = NULL_PTR;
    TT_ParaCheck((Flexcan_Hw_u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck(((NULL_PTR == tx_info)
            || (NULL_PTR == mb_data)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        state = Flexcan_Hw_apxState[Flexcan_Hw_u8Instance];
        base = Flexcan_Hw_apxBase[Flexcan_Hw_u8Instance];
        /* aici e ilogic ca nu are rost sa faci checkul dupa ce ai alocat aiurea */
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
        uint8 mbPayload = 0;
        TTRetVal = Can_Hw_PriGetMbPayloadSize(base, mb_idx, &mbPayload);
        /* Check if the Payload Size is smaller than the payload configured */
        TT_ParaCheck((((uint8)tx_info->data_length) > mbPayload), TT_RET_PARAM_LEN_ERR, &TTRetVal);
        if(TT_RET_SUCCESS == TTRetVal)
        {
#else
            TT_ParaCheck((((uint8)tx_info->data_length) > 8), TT_RET_PARAM_LEN_ERR, &TTRetVal);
#endif
            if(TRUE == Can_Hw_PriIsMbOutOfRange(base, mb_idx, state->bIsLegacyFifoEn, state->u32MaxMbNum))
            {
                TTRetVal = TT_RET_PARAM_INDEX_ERR;
            }
            else
            {
                if (state->mbs[mb_idx].state != FLEXCAN_MB_IDLE)
                {
                    TTRetVal = (uint32)FLEXCAN_MB_TX_BUSY;
                }
                else
                {
                    /* Clear message buffer flag */
                    FlexCAN_ClearMsgBuffIntStatusFlag(base, mb_idx);

                    state->mbs[mb_idx].state = FLEXCAN_MB_TX_BUSY;
                    state->mbs[mb_idx].time_stamp = 0U;
                    state->mbs[mb_idx].isPolling = tx_info->is_polling;
                    state->mbs[mb_idx].isRemote = tx_info->is_remote;

                    cs.dataLen = tx_info->data_length;

                    cs.msgIdType = tx_info->msg_id_type;

#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                    cs.fd_enable  = tx_info->fd_enable;
                    cs.fd_padding = tx_info->fd_padding;
                    cs.enable_brs = tx_info->enable_brs;
#else
                    cs.fd_enable  = FALSE;
                    cs.enable_brs = FALSE;
                    cs.fd_padding = 0x00U;
#endif

                    if (tx_info->is_remote)
                    {
                        cs.code = (uint32)FLEXCAN_TX_REMOTE;
                    }
                    else
                    {
                        cs.code = (uint32)FLEXCAN_TX_DATA;
                    }

                    TTRetVal = Can_Hw_PriGetMsgBuffRegion(base, mb_idx, &pMbAddr);
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        TTRetVal = Can_Hw_PriSetTxMsgBuff(pMbAddr, &cs, msg_id, mb_data, FALSE);
                    }
                    else
                    {

                    }
                }
            }
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
        }
        else
        {

        }
#endif
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        The process of receiving data and enabling the interrupt
* @details      Initiate (start) a receive by beginning the process of receiving data and enabling the interrupt
* @param[in]    instance - CAN Instance
* @param[in]    data - Points to receive data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriStartRxMsgFifoData(uint8 instance, Flexcan_Hw_MsgBuffType * data)
{

    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType TTRetValArray[3] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];

        /* Check if RxFIFO feature is enabled */
        if (FALSE == state->bIsLegacyFifoEn)
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
            if (FLEXCAN_RXFIFO_USING_DMA == state->transferType)
            {
                if (FLEXCAN_MB_DMA_ERROR == state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state)
                {
                    /* Check if FIFO has Pending Request that generated error,
                     * the RxFIFO need to be empty to activate DMA */
#if defined(MCAL_ENABLE_USER_MODE_SUPPORT) && (FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT == STD_OFF)
                    TTRetVal = Base_Trusted_Call1param(Can_Hw_PriClearOutputLegacyFIFO, base);
#else
                    TTRetVal = Can_Hw_PriClearOutputLegacyFIFO(base);
#endif

                    /* Change status of MB to be reconfigured with DMA transfer */
                    state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state = FLEXCAN_MB_IDLE;
                }
                else
                {

                }
            }
            else
            {

            }
            if(TT_RET_SUCCESS == TTRetVal)
            {
#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */

                /* Start receiving fifo */
                if (state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state != FLEXCAN_MB_IDLE)
                {
                    TTRetVal = TT_RET_IO_BUSY_ERR;
                }
                else
                {
                    state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state = FLEXCAN_MB_RX_BUSY;
                    if (FLEXCAN_RXFIFO_USING_POLLING == state->transferType)
                    {
                        state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].isPolling = TRUE;
                    }
                    else
                    {

                    }

                    /* This will get filled by the interrupt handler */
                    state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].pMBmessage = data;

                    if (FLEXCAN_RXFIFO_USING_INTERRUPTS == state->transferType)
                    {
                        state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].isPolling = FALSE;
                        /* Enable RX FIFO interrupts*/
                        TTRetValArray[0] = Can_Hw_PriSetMsgBuffIntCmd(base, instance, FLEXCAN_HW_LEGACY_RXFIFO_WARNING, TRUE, state->isIntActive);
                        TTRetValArray[1] = Can_Hw_PriSetMsgBuffIntCmd(base, instance, FLEXCAN_HW_LEGACY_RXFIFO_OVERFLOW, TRUE, state->isIntActive);
                        TTRetValArray[2] = Can_Hw_PriSetMsgBuffIntCmd(base, instance, FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE, TRUE, state->isIntActive);
                        if((TT_RET_SUCCESS != TTRetValArray[0])
                                || (TT_RET_SUCCESS != TTRetValArray[1])
                                || (TT_RET_SUCCESS != TTRetValArray[2]))
                        {
                            TTRetVal = TT_RET_OPT_REG_ERR;
                        }
                        else
                        {

                        }
                    }
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
                    else if (FLEXCAN_RXFIFO_USING_DMA == state->transferType)
                    {
                        TT_ParaCheck((NULL_PTR == data), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
                        if(TT_RET_SUCCESS == TTRetVal)
                        {
                            TTRetVal = Dma_Drv_ChannelConfigure (&DmaChannelConfig[state->rxFifoDMAChannel],
                                    4U,
                                    (uint32)(base->FLEXCAN_RAMn),
                                    (uint32)data,
                                    state->cb_event);
                        }
                        else
                        {

                        }
                    }
#endif /* if FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */
                    else
                    {

                    }
                }
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
            }
            else
            {

            }
#endif
        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        IRQ Handler
* @details      Process IRQHandler in case of Rx MessageBuffer selection for CAN interface
* @param[in]    instance - CAN Instance
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriIRQHandlerRxMB(uint8 instance, uint32 mb_idx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    Flexcan_Hw_MsgBuffType data = {0};
    boolean bCurrentIntStat = FALSE;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((mb_idx >= (uint8)FLEXCAN_HW_FEATURE_MAX_MB_NUM), TT_RET_PARAM_INDEX_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];

        /* If use pass NULL_PTR, they can get data in callback function by getting state->mbs[mb_idx].pMBmessage  */
        if (NULL_PTR == state->mbs[mb_idx].pMBmessage)
        {
            state->mbs[mb_idx].pMBmessage = (Flexcan_Hw_MsgBuffType *)&data;
        }
        else
        {
            (void)data;
        }
        /* Lock RX message buffer and RX FIFO*/
        Can_Hw_PriLockRxMsgBuff(base, mb_idx);

        /* Get RX MB field values*/
        TTRetVal = Can_Hw_PriGetMsgBuff(base, mb_idx, state->mbs[mb_idx].pMBmessage);
        if(TT_RET_SUCCESS != TTRetVal)
        {
            state->mbs[mb_idx].state = FLEXCAN_MB_RX_OVER_ERROR;
        }
        else
        {
            state->mbs[mb_idx].state = FLEXCAN_MB_IDLE;
        }

        FlexCAN_ClearMsgBuffIntStatusFlag(base, mb_idx);

        /* the CODE field is updated with an incorrect value when MBx is locked by software for more than 20 CAN bit times and FIFO enable */
        if ((state->bIsLegacyFifoEn) && ((uint32)FLEXCAN_RX_INACTIVE == ((state->mbs[mb_idx].pMBmessage->cs & FLEXCAN_HW_CS_CODE_Msk) >> FLEXCAN_HW_CS_CODE_Pos)))
        {
            /* Update the cs code for next sequence move in MB.
                A CPU write into the C/S word also unlocks the MB */
            volatile uint32 * flexcan_mb = NULL_PTR;
            TTRetVal = Can_Hw_PriGetMsgBuffRegion(base, mb_idx, &flexcan_mb);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                *flexcan_mb &= ~FLEXCAN_HW_CS_CODE_Msk;
                *flexcan_mb |= (((uint32)FLEXCAN_RX_EMPTY) << FLEXCAN_HW_CS_CODE_Pos) & FLEXCAN_HW_CS_CODE_Msk;
            }
            else
            {

            }
        }
        else
        {
            /* Unlock RX message buffer and RX FIFO*/
            FlexCAN_UnlockRxMsgBuff(base);
        }

        bCurrentIntStat = state->mbs[mb_idx].isPolling;

        /* Invoke callback */
        if (state->callback != NULL_PTR)
        {
            state->callback(instance, FLEXCAN_EVENT_RX_COMPLETE, mb_idx, state);
        }
        else
        {

        }

        if ((FLEXCAN_MB_IDLE == state->mbs[mb_idx].state) && (FALSE == state->mbs[mb_idx].isPolling))
        {
            /* callback is not called, need to reset to default value */
            state->mbs[mb_idx].isPolling = TRUE;
            /* Disable the transmitter data register empty interrupt for case: mb is interrupt (it was not use in above callback with the same index) */
            TTRetVal = Can_Hw_PriSetMsgBuffIntCmd(base, instance, mb_idx, FALSE, state->isIntActive);
        }
        else if ((FALSE == bCurrentIntStat) && (TRUE == state->mbs[mb_idx].isPolling))
        {
            /* Disable the transmitter data register empty interrupt for case: switch from interrupt to polling for the same MB (called in above callback with same mb index) */
            TTRetVal = Can_Hw_PriSetMsgBuffIntCmd(base, instance, mb_idx, FALSE, state->isIntActive);
        }
        else
        {
            /* Prevent misra */
            /* When processing type change from POLL->POLL or INTERRUPT -> INTERRUPT(this Mb is used continously in callback), no need to disable interrupt in the ISR */
        }
        /* Clear Mb message */
        state->mbs[mb_idx].pMBmessage = NULL_PTR;
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        IRQ Handler
* @details      Process IRQHandler in case of Tx MessageBuffer selection for CAN interface
* @param[in]    u8Instance - CAN Instance
* @param[in]    u32MbIdx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriIRQHandlerTxMB(uint8 u8Instance, uint32 u32MbIdx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    Flexcan_Hw_StateType * pState = NULL_PTR;
    Flexcan_Hw_MsgBuffType mb = {0};
    boolean bCurrentIntStat = FALSE;

    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        pState = Flexcan_Hw_apxState[u8Instance];
        if (pState->mbs[u32MbIdx].isRemote)
        {
            Can_Hw_PriLockRxMsgBuff(pBase, u32MbIdx);
            TTRetVal = Can_Hw_PriGetMsgBuff(pBase, u32MbIdx, &mb);
            FlexCAN_UnlockRxMsgBuff(pBase);
            pState->mbs[u32MbIdx].time_stamp = mb.time_stamp;
            /* If the frame was a remote frame, clear the flag only if the response was
             * not received yet. If the response was received, leave the flag set in order
             * to be handled when the user calls FLEXCAN_DRV_RxMessageBuffer. */
            if ((uint32)FLEXCAN_RX_EMPTY == ((mb.cs & FLEXCAN_HW_CS_CODE_Msk) >> FLEXCAN_HW_CS_CODE_Pos))
            {
                FlexCAN_ClearMsgBuffIntStatusFlag(pBase, u32MbIdx);
            }
            else
            {

            }
        }
        else
        {
            pState->mbs[u32MbIdx].time_stamp = Can_Hw_PriGetMsgBuffTimestamp(pBase, u32MbIdx);
            FlexCAN_UnlockRxMsgBuff(pBase);
            FlexCAN_ClearMsgBuffIntStatusFlag(pBase, u32MbIdx);
        }

        if(TT_RET_SUCCESS == TTRetVal)
        {
            pState->mbs[u32MbIdx].state = FLEXCAN_MB_IDLE;

            bCurrentIntStat = pState->mbs[u32MbIdx].isPolling;

            /* Invoke callback */
            if (pState->callback != NULL_PTR)
            {
                pState->callback(u8Instance, FLEXCAN_EVENT_TX_COMPLETE, u32MbIdx, pState);
            }
            else
            {

            }

            if ((FLEXCAN_MB_IDLE == pState->mbs[u32MbIdx].state) && (FALSE == pState->mbs[u32MbIdx].isPolling))
            {
                /* callback is not called, need to reset to default value */
                pState->mbs[u32MbIdx].isPolling = TRUE;
                /* Disable the transmitter data register empty interrupt for case: mb is interrupt (it was not use in above callback with the same index) */
                TTRetVal = Can_Hw_PriSetMsgBuffIntCmd(pBase, u8Instance, u32MbIdx, FALSE, pState->isIntActive);
            }
            else if ((FALSE == bCurrentIntStat) && (TRUE == pState->mbs[u32MbIdx].isPolling))
            {
                /* Disable the transmitter data register empty interrupt for case: switch from interrupt to polling for the same MB (called in above callback with same mb index) */
                TTRetVal = Can_Hw_PriSetMsgBuffIntCmd(pBase, u8Instance, u32MbIdx, FALSE, pState->isIntActive);
            }
            else
            {
                /* Prevent misra */
                /* When processing type change from POLL->POLL or INTERRUPT -> INTERRUPT(this Mb is used continously in callback), no need to disable interrupt in the ISR */
            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        RxFIFO IRQ Handler
* @details      Process IRQHandler in case of RxFIFO mode selection for CAN interface
* @param[in]    instance - CAN Instance
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriIRQHandlerRxFIFO(uint8 instance, uint32 mb_idx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    Flexcan_Hw_MsgBuffType data = {0};

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];

        /* If use pass NULL_PTR, they can get data in callback function by getting state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].pMBmessage  */
        if (NULL_PTR == state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].pMBmessage)
        {
            state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].pMBmessage = &data;
        }
        switch (mb_idx)
        {
        case FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE:
            if (FLEXCAN_MB_RX_BUSY == state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state)
            {
                /* Get RX FIFO field values */
                TTRetVal = Can_Hw_PriReadRxFifo(base, state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].pMBmessage);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    FlexCAN_ClearMsgBuffIntStatusFlag(base, mb_idx);

                    state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state = FLEXCAN_MB_IDLE;

                    /* Invoke callback */
                    if (state->callback != NULL_PTR)
                    {
                        state->callback(instance, FLEXCAN_EVENT_RXFIFO_COMPLETE, FLEXCAN_HW_MB_HANDLE_RXFIFO, state);
                    }
                    else
                    {

                    }

                    if (FLEXCAN_MB_IDLE == state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state)
                    {
                        /* reset to default value */
                        state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].isPolling = TRUE;
                        /* Complete receive data */
                        TTRetVal = Can_Hw_PriCompleteRxMsgFifoData(instance);
                    }
                    else
                    {

                    }
                }
                else
                {

                }
            }
            else
            {

            }

            break;
        case FLEXCAN_HW_LEGACY_RXFIFO_WARNING:
            FlexCAN_ClearMsgBuffIntStatusFlag(base, mb_idx);

            /* Invoke callback */
            if (state->callback != NULL_PTR)
            {
                state->callback(instance, FLEXCAN_EVENT_RXFIFO_WARNING, FLEXCAN_HW_MB_HANDLE_RXFIFO, state);
            }
            else
            {

            }

            break;
        case FLEXCAN_HW_LEGACY_RXFIFO_OVERFLOW:
            FlexCAN_ClearMsgBuffIntStatusFlag(base, mb_idx);

            /* Invoke callback */
            if (state->callback != NULL_PTR)
            {
                state->callback(instance, FLEXCAN_EVENT_RXFIFO_OVERFLOW, FLEXCAN_HW_MB_HANDLE_RXFIFO, state);
            }
            else
            {

            }

            break;
        default:
            /* Do Nothing */
            break;
        }
    }
    else
    {

    }

    return TTRetVal;
}

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
* @brief        ENHANCED RxFIFO IRQ Handler
* @details      Process IRQHandler in case of Enhanced RxFIFO mode selection for CAN interface
* @param[in]    instance - CAN Instance
* @param[in]    intType - interrupt Type
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriIRQHandlerEnRxFIFO(uint8 instance, uint32 intType)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    Flexcan_Hw_MsgBuffType data = {0};

    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];

        switch (intType)
        {
        case FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE:
            if (FLEXCAN_MB_RX_BUSY == state->enhancedFifoOutput.state)
            {
                /* If use pass NULL_PTR, they can get data in callback function by getting state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].pMBmessage  */
                if (NULL_PTR == state->enhancedFifoOutput.pMBmessage)
                {
                    state->enhancedFifoOutput.pMBmessage = &data;
                }
                else
                {

                }

                /* Get Enhanced RX FIFO field values */
                TTRetVal = Can_Hw_PriReadEnhancedRxFifo(base, state->enhancedFifoOutput.pMBmessage);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, intType);
                    state->enhancedFifoOutput.state = FLEXCAN_MB_IDLE;

                    /* Invoke callback */
                    if (state->callback != NULL_PTR)
                    {
                        state->callback(instance, FLEXCAN_EVENT_ENHANCED_RXFIFO_COMPLETE, FLEXCAN_HW_MB_ENHANCED_RXFIFO, state);
                    }
                    else
                    {

                    }

                    if (FLEXCAN_MB_IDLE == state->enhancedFifoOutput.state)
                    {
                        /* Complete receive data */
                        TTRetVal = Can_Hw_PriCompRxMsgEnFifoData(instance);
                    }
                    else
                    {

                    }
                }
                else
                {

                }

            }
            else
            {

            }

            break;
        case FLEXCAN_HW_ENHANCED_RXFIFO_WATERMARK:
            FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, intType);

            /* Invoke callback */
            if (state->callback != NULL_PTR)
            {
                state->callback(instance, FLEXCAN_EVENT_ENHANCED_RXFIFO_WATERMARK, FLEXCAN_HW_MB_ENHANCED_RXFIFO, state);
            }
            else
            {

            }

            break;
        case FLEXCAN_HW_ENHANCED_RXFIFO_OVERFLOW:
            FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, intType);

            /* Invoke callback */
            if (state->callback != NULL_PTR)
            {
                state->callback(instance, FLEXCAN_EVENT_ENHANCED_RXFIFO_OVERFLOW, FLEXCAN_HW_MB_ENHANCED_RXFIFO, state);
            }
            else
            {

            }

            break;
        case FLEXCAN_HW_ENHANCED_RXFIFO_UNDERFLOW:
            FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, intType);

            /* Invoke callback */
            if (state->callback != NULL_PTR)
            {
                state->callback(instance, FLEXCAN_EVENT_ENHANCED_RXFIFO_UNDERFLOW, FLEXCAN_HW_MB_ENHANCED_RXFIFO, state);
            }
            else
            {

            }

            break;
        default:
            /* Do Nothing */
            break;
        }
    }
    else
    {

    }

    return TTRetVal;
}
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */


#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
* @brief        DMA mode Callback
* @details      DMA mode Callback
* @param[in]    instance - CAN Instance
* @param[in]    event - Callback event
* @return       void
* @retval       None
*/
static void DMA_Can_Callback(uint8 instance, uint32 event)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * base = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        base = Flexcan_Hw_apxBase[instance];
        state = Flexcan_Hw_apxState[instance];

        switch (event)
        {
        case DMA_EVENT_ERROR:
            state->mbs[FLEXCAN_HW_MB_HANDLE_RXFIFO].state = FLEXCAN_MB_DMA_ERROR;
            if (state->callback != NULL_PTR)
            {
                state->callback(instance, FLEXCAN_EVENT_DMA_ERROR, FLEXCAN_HW_MB_HANDLE_RXFIFO, state);
            }
            else
            {

            }

            break;

        case DMA_EVENT_TERMINAL_COUNT_REQUEST:
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
            if (TRUE == FlexCAN_IsEnhancedRxFifoEnabled(base))
            {
                /* Need to add handler for Enhaced RxFifoDataDMA */
                (void)Can_Hw_PriCompRxMsgEnFifoData(instance);
            }
            else
            {
#endif
                (void)Can_Hw_PriCompleteRxMsgFifoData(instance);
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
            }
#endif
            break;

        default:
            /* do nothing */
            break;
        }
    }
    else
    {

    }

    return;
}
#endif

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        AbortTxTransfer
* @details      Abort transfer for Tx buffer
* @param[in]    u8Instance - CAN Instance
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriAbortTxTransfer(uint8 u8Instance, uint8 mb_idx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_CAN_Type * pBase = NULL_PTR;
    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        state = Flexcan_Hw_apxState[u8Instance];

#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        uint32 TimeoutTicks = 0;
        uint32 CurrentTicks = 0;
        (void)Base_Drv_Timer_MicrosToTicks(FLEXCAN_HW_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
        uint32 Temp = 0;
        uint32 ElapsedTicks = 0U;
#endif
        uint32 flexcan_mb_config = 0;
        volatile uint32 * flexcan_mb = NULL_PTR;

        TTRetVal = Can_Hw_PriGetMsgBuffRegion(pBase, mb_idx, &flexcan_mb);
        if(TT_RET_SUCCESS == TTRetVal)
        {
            flexcan_mb_config = * flexcan_mb;
            /* Reset the code */
            flexcan_mb_config &= (~FLEXCAN_HW_CS_CODE_Msk);
            flexcan_mb_config |= (uint32)(((uint32)FLEXCAN_TX_ABORT & (uint32)0x1F) << (uint8)FLEXCAN_HW_CS_CODE_Pos) & (uint32)FLEXCAN_HW_CS_CODE_Msk;
            *flexcan_mb = flexcan_mb_config;

            while (0U == FlexCAN_GetBuffStatusFlag(pBase, mb_idx))
            {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
                (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&Temp);
                ElapsedTicks += Temp;
                if (ElapsedTicks >= TimeoutTicks)
                {
                    TTRetVal = TT_RET_STATUS_TIMEOUT_ERR;
                    break;
                }
                else
                {

                }
#endif
            }

#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
            if(TT_RET_SUCCESS == TTRetVal)
            {
#endif
                flexcan_mb_config = *flexcan_mb;

                if ((uint32)FLEXCAN_TX_ABORT == ((flexcan_mb_config & FLEXCAN_HW_CS_CODE_Msk) >> FLEXCAN_HW_CS_CODE_Pos))
                {
                    /* Transmission have been aborted */
                    TTRetVal = TT_RET_SUCCESS;
                }
                else
                {
                    TTRetVal = TT_RET_IO_ABORT_ERR;
                }
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
            }
#endif
            /* Clear message buffer flag */
            FlexCAN_ClearMsgBuffIntStatusFlag(pBase, mb_idx);
            state->mbs[mb_idx].state = FLEXCAN_MB_IDLE;
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Abort Rx Transfer
* @details      Abort transfer for Rx normal or legacy fifo if enabled
* @param[in]    u8Instance - CAN Instance
* @param[in]    mb_idx - mb index
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriAbortRxTransfer(uint8 u8Instance, uint8 mb_idx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CAN_Type * pBase = NULL_PTR;
    Flexcan_Hw_StateType * state = NULL_PTR;
    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        pBase = Flexcan_Hw_apxBase[u8Instance];
        state = Flexcan_Hw_apxState[u8Instance];
        uint32 val1 = 0U;
        uint32 val2 = 0U;
        uint32 flexcan_mb_config = 0;
        volatile uint32 * flexcan_mb = NULL_PTR;

        state->mbs[mb_idx].state = FLEXCAN_MB_IDLE;
        /* Check if fifo enabled */
        if (TRUE == state->bIsLegacyFifoEn)
        {
            /* Get the number of RX FIFO Filters*/
            val1 = (((pBase->FLEXCAN_CTRL2) & TT_CAN_FLEXCAN_CTRL2_RFFN_Msk) >> TT_CAN_FLEXCAN_CTRL2_RFFN_Pos);
            /* Get the number if MBs occupied by RX FIFO and ID filter table*/
            /* the Rx FIFO occupies the memory space originally reserved for MB0-5*/
            /* Every number of RFFN means 8 number of RX FIFO filters*/
            /* and every 4 number of RX FIFO filters occupied one MB*/
            val2 = RxFifoOcuppiedLastMsgBuff(val1);
        }
        else
        {
        }

        if ((FALSE == state->bIsLegacyFifoEn) || (mb_idx > val2))
        {
            /* This operation is not allowed for MB that are part of RxFIFO */
            TTRetVal = Can_Hw_PriGetMsgBuffRegion(pBase, mb_idx, &flexcan_mb);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                flexcan_mb_config = * flexcan_mb;
                /* Reset the code and unlock the MB */
                flexcan_mb_config &= (uint32)(~FLEXCAN_HW_CS_CODE_Msk);
                flexcan_mb_config |= (uint32)(((uint32)FLEXCAN_RX_INACTIVE & (uint32)0x1F) << (uint8)FLEXCAN_HW_CS_CODE_Pos) & (uint32)FLEXCAN_HW_CS_CODE_Msk;
                *flexcan_mb = flexcan_mb_config;
                /* Reconfigure The MB as left by RxMBconfig */
                flexcan_mb_config &= (~FLEXCAN_HW_CS_CODE_Msk);
                flexcan_mb_config |= (uint32)(((uint32)FLEXCAN_RX_EMPTY & (uint32)0x1F) << (uint8)FLEXCAN_HW_CS_CODE_Pos) & (uint32)FLEXCAN_HW_CS_CODE_Msk;
                *flexcan_mb = flexcan_mb_config;
            }
            else
            {

            }
        }
        else
        {

        }

        if(TT_RET_SUCCESS == TTRetVal)
        {
            if ((TRUE == state->bIsLegacyFifoEn) && (FLEXCAN_HW_MB_HANDLE_RXFIFO == mb_idx))
            {
                TTRetVal = Can_Hw_PriClearMsgBuffIntCmd(pBase, u8Instance, FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE, state->isIntActive);
            }
            else
            {

            }
        }
        else
        {

        }
        /* Clear message buffer flag */
        FlexCAN_ClearMsgBuffIntStatusFlag(pBase, mb_idx);
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Compute DLC Value
* @details      Compute DLC Value
* @param[in]    payloadSize - payload Size
* @return       uint8
* @retval       DLC Value
*/
static uint8 Can_Hw_PriComputeDLCValue(uint8 payloadSize)
{
    uint32 ret = 0xFFU;                   /* 0,  1,  2,  3,  4,  5,  6,  7,  8, */
    TT_CONST uint8 payload_code[65] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U,
                                           /* 9 to 12 payload have DLC Code 12 Bytes */
                                           FLEXCAN_HW_DLC_VALUE_12_BYTES, FLEXCAN_HW_DLC_VALUE_12_BYTES, FLEXCAN_HW_DLC_VALUE_12_BYTES, FLEXCAN_HW_DLC_VALUE_12_BYTES,
                                           /* 13 to 16 payload have DLC Code 16 Bytes */
                                           FLEXCAN_HW_DLC_VALUE_16_BYTES, FLEXCAN_HW_DLC_VALUE_16_BYTES, FLEXCAN_HW_DLC_VALUE_16_BYTES, FLEXCAN_HW_DLC_VALUE_16_BYTES,
                                           /* 17 to 20 payload have DLC Code 20 Bytes */
                                           FLEXCAN_HW_DLC_VALUE_20_BYTES, FLEXCAN_HW_DLC_VALUE_20_BYTES, FLEXCAN_HW_DLC_VALUE_20_BYTES, FLEXCAN_HW_DLC_VALUE_20_BYTES,
                                           /* 21 to 24 payload have DLC Code 24 Bytes */
                                           FLEXCAN_HW_DLC_VALUE_24_BYTES, FLEXCAN_HW_DLC_VALUE_24_BYTES, FLEXCAN_HW_DLC_VALUE_24_BYTES, FLEXCAN_HW_DLC_VALUE_24_BYTES,
                                           /* 25 to 32 payload have DLC Code 32 Bytes */
                                           FLEXCAN_HW_DLC_VALUE_32_BYTES, FLEXCAN_HW_DLC_VALUE_32_BYTES, FLEXCAN_HW_DLC_VALUE_32_BYTES, FLEXCAN_HW_DLC_VALUE_32_BYTES,
                                           FLEXCAN_HW_DLC_VALUE_32_BYTES, FLEXCAN_HW_DLC_VALUE_32_BYTES, FLEXCAN_HW_DLC_VALUE_32_BYTES, FLEXCAN_HW_DLC_VALUE_32_BYTES,
                                           /* 33 to 48 payload have DLC Code 48 Bytes */
                                           FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES,
                                           FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES,
                                           FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES,
                                           FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES, FLEXCAN_HW_DLC_VALUE_48_BYTES,
                                           /* 49 to 64 payload have DLC Code 64 Bytes */
                                           FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES,
                                           FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES,
                                           FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES,
                                           FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES, FLEXCAN_HW_DLC_VALUE_64_BYTES
                                          };

    if (payloadSize <= 64U)
    {
        ret = payload_code[payloadSize];
    }
    else
    {
        /* The argument is not a valid payload size will return 0xFF*/
    }

    return (uint8)ret;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Clear RAM
* @details      Clears FlexCAN memory positions that require initialization
* @param[in]    base - CAN Base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriClearRAM(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32 databyte = 0U;
        TT_CONST uint32 RAM_size   = Can_Hw_PriGetMaxMbNum(base) * 4U;
        TT_CONST uint32 RXIMR_size = Can_Hw_PriGetMaxMbNum(base);
        /* Address of base + ram offset to point to MB start address */
        volatile uint32 * RAM = (uint32 *)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_RAM_OFFSET);
        /* Clear MB region */
        for (databyte = 0U; databyte < RAM_size; databyte++)
        {
            RAM[databyte] = 0x0U;
        }

        RAM = (volatile uint32 *)base->FLEXCAN_RXIMR;
        /* Clear RXIMR region */
        for (databyte = 0U; databyte < RXIMR_size; databyte++)
        {
            RAM[databyte] = 0x0U;
        }

#if (FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY == STD_ON)
        RAM = (uint32 *)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_EXP_RAM_OFFSET);
        /* Clear Expanded Memory region */
        for (databyte = 0U; databyte < FLEXCAN_HW_RAM1n_COUNT; databyte++)
        {
            RAM[databyte] = 0x0U;
        }
#endif /* if FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY */

#if (FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET == STD_ON)
        /* Set WRMFRZ bit in CTRL2 Register to grant write access to memory */
        base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_WRMFRZ_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_WRMFRZ, 1U);
        TT_CONST uint32 ram_addr = (uint32)base + (uint32)FLEXCAN_HW_FEATURE_RAM_OFFSET;
        RAM = (volatile uint32 *)ram_addr;

        /* Clear RXMGMASK, RXFGMASK, RX14MASK, RX15MASK RAM mapping */
        base->FLEXCAN_RXMGMASK = 0U;
        base->FLEXCAN_RXFGMASK = 0U;
        base->FLEXCAN_RX14MASK = 0U;
        base->FLEXCAN_RX15MASK = 0U;

#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
        for (databyte = 0U; databyte < (uint32)1U; databyte++)
        {
            RAM[databyte] = 0U;
        }
#endif

        /* Clear WRMFRZ bit in CTRL2 Register to restrict write access to memory */
        base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_WRMFRZ_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_WRMFRZ, 0U);
#endif /* if FLEXCAN_HW_FEATURE_HAS_MEM_ERR_DET */
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Computes the maximum payload size (in bytes), given a DLC
* @details      Computes the maximum payload size (in bytes), given a DLC
* @param[in]    dlcValue - DLC code from the MB memory
* @return       uint8
* @retval       payload size (in bytes)
*/
LOCAL_INLINE uint8 Can_Hw_PriComputePayloadSize(uint8 dlcValue)
{
    uint8 ret = 8U;

    if (dlcValue <= 8U)
    {
        ret = dlcValue;
    }
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
    else
    {
        switch (dlcValue)
        {
            case FLEXCAN_HW_DLC_VALUE_12_BYTES:
                ret = 12U;
                break;
            case FLEXCAN_HW_DLC_VALUE_16_BYTES:
                ret = 16U;
                break;
            case FLEXCAN_HW_DLC_VALUE_20_BYTES:
                ret = 20U;
                break;
            case FLEXCAN_HW_DLC_VALUE_24_BYTES:
                ret = 24U;
                break;
            case FLEXCAN_HW_DLC_VALUE_32_BYTES:
                ret = 32U;
                break;
            case FLEXCAN_HW_DLC_VALUE_48_BYTES:
                ret = 48U;
                break;
            case FLEXCAN_HW_DLC_VALUE_64_BYTES:
                ret = 64U;
                break;
            default:
                /* The argument is not a valid DLC size */
                break;
        }
    }
#endif /* FLEXCAN_HW_FEATURE_HAS_FD */

    return ret;
}

/**
* @brief        Returns the start of a MB area, based on its index
* @details      Sets the FlexCAN message buffer fields for transmitting
* @param[in]    base - The can base address
* @param[in]    msgBuffIdx - Index of the message buffer
* @param[in]    addr - Pointer to the beginning of the MBs space address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriGetMsgBuffRegion(TT_CONST TT_CAN_Type * base, uint32 msgBuffIdx, volatile uint32 ** addr)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == addr)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        TT_CONST uint8 arbitration_field_size = 8U;
        uint8 mb_size = 0U;
        TT_CONST uint32 ramBlockSize = 512U;
        uint32 ramBlockOffset = 0;
        uint32 msgBuffIdxBackup = msgBuffIdx;
        uint8 i=0U;
        uint8 maxMbNum=0U;
        uint32 mb_index=0U;
        uint8 payload_size=0U;
        volatile uint32 *TT_CONST RAM = (uint32*)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_RAM_OFFSET);
#if (FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY == STD_ON)
        volatile uint32 *TT_CONST RAM_EXPANDED = (uint32*)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_EXP_RAM_OFFSET);
#endif

        for (i=0; i< (uint8)FLEXCAN_HW_FEATURE_MBDSR_COUNT; i++)
        {
            TTRetVal = Can_Hw_PriGetPayloadSize(base, i, &payload_size);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                mb_size = (uint8)(payload_size + arbitration_field_size);
                maxMbNum = (uint8)(ramBlockSize / mb_size);
                if (maxMbNum > msgBuffIdxBackup)
                {
                    break;
                }
                else
                {

                }
                ramBlockOffset += 128U;
                msgBuffIdxBackup -= maxMbNum;
            }
            else
            {
                break;
            }
        }
        if(TT_RET_SUCCESS == TTRetVal)
        {
#if (FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY == STD_ON)
            if ((uint8)FLEXCAN_HW_FEATURE_MBDSR_COUNT == i)
            {
                /* Multiply the MB index by the MB size (in words) */
                /* for expanded ramblock:
                 * maxMbNum per one block: 7
                 * mb_size per one Mb: 72
                 */
                mb_index = ((msgBuffIdxBackup / 7U) * 128U) + ((msgBuffIdxBackup % 7U) * (72U >> 2U));
                *addr = &(RAM_EXPANDED[mb_index]);
            }
            else
#endif
            {
                /* Multiply the MB index by the MB size (in words) */
                mb_index = ramBlockOffset + ((msgBuffIdxBackup % (uint32)maxMbNum) * ((uint32)mb_size >> 2U));
                *addr = &(RAM[mb_index]);
            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Computes the maximum RAM size occupied by MBs
* @details      Get The Max no of MBs allowed on CAN instance
* @param[in]    base - The can base address
* @return       uint32
* @retval       The Max No of MBs on the CAN instance
*/
static uint32 Can_Hw_PriGetMaxMbNum(TT_CONST TT_CAN_Type * base)
{
    uint32 i, ret = 0u;
    TT_CAN_Type * TT_CONST flexcanBase[] = IP_FLEXCAN_BASE_PTRS;
    TT_CONST uint32 maxMbNum[] = FLEXCAN_HW_FEATURE_MAX_MB_NUM_ARRAY;

    for (i = 0u; i < FLEXCAN_INSTANCE_COUNT; i++)
    {
        if (base == flexcanBase[i])
        {
            ret = maxMbNum[i];
        }
        else
        {

        }
    }
    return ret;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Enter Freeze Mode
* @details      Enter the freeze mode
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnterFreezeMode(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        uint32 TimeoutTicks = 0;
        uint32 CurrentTicks = 0;
        (void)Base_Drv_Timer_MicrosToTicks(FLEXCAN_HW_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
        uint32 Temp = 0;
        uint32 ElapsedTicks = 0U;
#endif
        /* Start critical section: implementation depends on integrator */

        base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_FRZ_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_FRZ, 1U);
        base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_HALT_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_HALT, 1U);

        if (((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_MDIS_Msk) >> TT_CAN_FLEXCAN_MCR_MDIS_Pos) == 1U)
        {
            base->FLEXCAN_MCR &= ~TT_CAN_FLEXCAN_MCR_MDIS_Msk;
        }
        else
        {

        }

        /* Wait for entering the freeze mode */
        while (((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_FRZACK_Msk) != TT_CAN_FLEXCAN_MCR_FRZACK_Msk))
        {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
            (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&Temp);
            ElapsedTicks += Temp;
            if (ElapsedTicks >= TimeoutTicks)
            {
                TTRetVal = TT_RET_STATUS_TIMEOUT_ERR;
                break;
            }
            else
            {

            }
#endif
        }

    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Enable Controller
* @details      Enable Controller
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnableController(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        uint32 TimeoutTicks = 0;
        uint32 CurrentTicks = 0;
        (void)Base_Drv_Timer_MicrosToTicks(FLEXCAN_HW_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
        uint32 Temp = 0;
        uint32 ElapsedTicks = 0U;
#endif

        if(((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_LPMACK_Msk) >> TT_CAN_FLEXCAN_MCR_LPMACK_Pos) == 1U)
        {
            /* Enable clock */
            base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_MDIS_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_MDIS, 0U);
            base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_FRZ_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_FRZ, 0U);
            base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_HALT_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_HALT, 0U);

            while (((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_NOTRDY_Msk) >> TT_CAN_FLEXCAN_MCR_NOTRDY_Pos) != 0U)
            {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
                (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&Temp);
                ElapsedTicks += Temp;
                if (ElapsedTicks >= TimeoutTicks)
                {
                    TTRetVal = TT_RET_STATUS_TIMEOUT_ERR;
                    break;
                }
                else
                {

                }
#endif
            }
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Enable can
* @details      Enable the clock for FlexCAN Module
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnable(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        uint32 TimeoutTicks = 0;
        uint32 CurrentTicks = 0;
        (void)Base_Drv_Timer_MicrosToTicks(FLEXCAN_HW_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
        uint32 Temp = 0;
        uint32 ElapsedTicks = 0U;
#endif

        /* Enable clock */
        base->FLEXCAN_MCR &= ~TT_CAN_FLEXCAN_MCR_MDIS_Msk;

        while (0U == ((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_FRZACK_Msk) >> TT_CAN_FLEXCAN_MCR_FRZACK_Pos))
        {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
            (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&Temp);
            ElapsedTicks += Temp;
            if (ElapsedTicks >= TimeoutTicks)
            {
                TTRetVal = TT_RET_STATUS_TIMEOUT_ERR;
                break;
            }
            else
            {

            }
#endif
        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Exit Freeze Mode
* @details      Exit Freeze Mode
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriExitFreezeMode(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        uint32 TimeoutTicks = 0;
        uint32 CurrentTicks = 0;
        (void)Base_Drv_Timer_MicrosToTicks(FLEXCAN_HW_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
        uint32 Temp = 0;
        uint32 ElapsedTicks = 0U;
#endif

        base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_HALT_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_HALT, 0U);
        base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_FRZ_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_FRZ, 0U);

        while (((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_FRZACK_Msk) >> TT_CAN_FLEXCAN_MCR_FRZACK_Pos) != 0U)
        {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
            (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&Temp);
            ElapsedTicks += Temp;
            if (ElapsedTicks >= TimeoutTicks)
            {
                TTRetVal = TT_RET_STATUS_TIMEOUT_ERR;
                break;
            }
            else
            {

            }
#endif
        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Disable CAN module
* @details      Disable CAN module
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriDisable(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        uint32 TimeoutTicks = 0;
        uint32 CurrentTicks = 0;
        (void)Base_Drv_Timer_MicrosToTicks(FLEXCAN_HW_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
        uint32 Temp = 0;
        uint32 ElapsedTicks = 0U;
#endif

        /* To access the memory mapped registers */
        /* Enter disable mode (hard reset). */
        if (0U == ((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_MDIS_Msk) >> TT_CAN_FLEXCAN_MCR_MDIS_Pos))
        {

            base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_MDIS_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_MDIS, 1U);

            while (0U == ((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_LPMACK_Msk) >> TT_CAN_FLEXCAN_MCR_LPMACK_Pos))
            {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
                (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&Temp);
                ElapsedTicks += Temp;
                if (ElapsedTicks >= TimeoutTicks)
                {
                    TTRetVal = TT_RET_STATUS_TIMEOUT_ERR;
                    break;
                }
                else
                {

                }
#endif
            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Set Error Int
* @details      Enable the error interrupts
* @param[in]    base - The can base address
* @param[in]    errType - error Type
* @param[in]    enable - enable Error Int
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetErrIntCmd(TT_CAN_Type * base, flexcan_int_type_t errType, boolean enable)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32 temp = (uint32)errType;
        if (enable)
        {
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            if (FLEXCAN_INT_ERR_FAST == errType)
            {
                base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_ERRMSK_FAST_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_ERRMSK_FAST, 1U);
                (void)temp;
            }
            else
#endif
{
                if ((FLEXCAN_INT_RX_WARNING == errType) || (FLEXCAN_INT_TX_WARNING == errType))
                {
                    base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_WRNEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_WRNEN, 1U);
                }
                else
                {

                }
                base->FLEXCAN_CTRL1 |= temp;
}
        }
        else
        {
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            if (FLEXCAN_INT_ERR_FAST == errType)
            {
                base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_ERRMSK_FAST_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL2_ERRMSK_FAST, 0U);
                (void)temp;
            }
            else
#endif
{
                base->FLEXCAN_CTRL1 &= ~temp;
                temp = base->FLEXCAN_CTRL1;
                if ((0U == (temp & (uint32)FLEXCAN_INT_RX_WARNING)) && (0U == (temp & (uint32)FLEXCAN_INT_TX_WARNING)))
                {
                    /* If WRNEN disabled then both FLEXCAN_INT_RX_WARNING and FLEXCAN_INT_TX_WARNING will be disabled */
                    base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_WRNEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_WRNEN, 0U);
                }
                else
                {

                }
}
        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Initialize FlexCAN module
* @details      This function will reset FlexCAN module, set maximum number of message
*               buffers, initialize all message buffers as inactive, enable RX FIFO
*               if needed, mask all mask bits, and disable all MB interrupts.
* @param[in]    base - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriInit(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        uint32 TimeoutTicks = 0;
        uint32 CurrentTicks = 0;
        (void)Base_Drv_Timer_MicrosToTicks(FLEXCAN_HW_TIMEOUT_DURATION,&TimeoutTicks);
        (void)Base_Drv_Timer_GetCounter(&CurrentTicks);
        uint32 Temp = 0;
        uint32 ElapsedTicks = 0U;
#endif

        /* Reset the FLEXCAN */
        base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_SOFTRST_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_SOFTRST, 1U);

        while (((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_SOFTRST_Msk) >> TT_CAN_FLEXCAN_MCR_SOFTRST_Pos) != 0U)
        {
#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
            (void)Base_Drv_Timer_GetElapsed(&CurrentTicks,&Temp);
            ElapsedTicks += Temp;
            if (ElapsedTicks >= TimeoutTicks)
            {
                TTRetVal = TT_RET_STATUS_TIMEOUT_ERR;
                break;
            }
            else
            {

            }
#endif
        }

#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        if (TT_RET_SUCCESS == TTRetVal)
        {
#endif
            /* Avoid Abort Transmission, use Inactive MB */
            base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_AEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_AEN, 1U);
            /* Clear FlexCAN memory */
            TTRetVal = Can_Hw_PriClearRAM(base);
            /* Rx global mask*/
            (base->FLEXCAN_RXMGMASK) = (uint32)(TT_CAN_FLEXCAN_RXMGMASK_MG_Msk);
            /* Rx reg 14 mask*/
            (base->FLEXCAN_RX14MASK) =  (uint32)(TT_CAN_FLEXCAN_RX14MASK_RX14M_Msk);
            /* Rx reg 15 mask*/
            (base->FLEXCAN_RX15MASK) = (uint32)(TT_CAN_FLEXCAN_RX15MASK_RX15M_Msk);
            /* Disable all MB interrupts */
            (base->FLEXCAN_IMASK1) = 0x0;
            /* Clear all MB interrupt flags */
            (base->FLEXCAN_IFLAG1) = TT_CAN_FLEXCAN_IMASK1_BUF31TO0M_Msk;
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U
            if (Can_Hw_PriGetMaxMbNum(base) > 32U)
            {
                (base->FLEXCAN_IMASK2) = 0x0;
                (base->FLEXCAN_IFLAG2) = TT_CAN_FLEXCAN_IMASK2_BUF63TO32M_Msk;
            }
            else
            {

            }
#endif
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U
            if (Can_Hw_PriGetMaxMbNum(base) > 64U)
            {
                (base->FLEXCAN_IMASK3) = 0x0;
                (base->FLEXCAN_IFLAG3) = TT_CAN_FLEXCAN_IMASK3_BUF95TO64M_Msk;
            }
            else
            {

            }
#endif
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U
            if (Can_Hw_PriGetMaxMbNum(base) > 96U)
            {
                (base->FLEXCAN_IMASK4) = 0x0;
                (base->FLEXCAN_IFLAG4) = TT_CAN_FLEXCAN_IMASK4_BUF127TO96M_Msk;
            }
            else
            {

            }
#endif
/* Clear all error interrupt flags */
            base->FLEXCAN_ESR1 = FLEXCAN_HW_ALL_INT;
            /* clear registers which are not effected by soft reset */
            base->FLEXCAN_CTRL1 = (uint32)0x00000000U;
            base->FLEXCAN_CTRL2 = (uint32)0x00100000U;
            base->FLEXCAN_CBT   = (uint32)0x00000000U;

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCE_CBT == STD_ON)
            base->FLEXCAN_EPRS  = (uint32)0x00000000U;
            base->FLEXCAN_ENCBT = (uint32)0x00000000U;
            base->FLEXCAN_EDCBT = (uint32)0x00000000U;
            base->FLEXCAN_ETDC  = (uint32)0x00008000U;
#endif
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            base->FLEXCAN_FDCBT = (uint32)0x00000000U;
            base->FLEXCAN_FDCTRL = (uint32)0x80004100U;
#endif /* (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON) */

#if defined(CanTimeoutSupervisionEnabled) && (CanTimeoutSupervisionEnabled == STD_ON)
        }
        else
        {

        }
#endif
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Enable Rx FIFO feature
* @details      Enable Rx FIFO feature
* @param[in]    base - The can base address
* @param[in]    numOfFilters - The number of Rx FIFO filters
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnableRxFifo(TT_CAN_Type * base,
                                         uint32 numOfFilters)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32 i = 0U;
        TT_CONST  uint16 noOfMbx = (uint16)Can_Hw_PriGetMaxMbNum(base);

        /* RxFIFO cannot be enabled if FD is enabled */
        if (((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_FDEN_Msk) >> TT_CAN_FLEXCAN_MCR_FDEN_Pos) != 0U)
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }
        if (TT_RET_SUCCESS == TTRetVal)
        {
            /* Enable RX FIFO */
            base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_RFEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_RFEN, 1U);
            /* Set the number of the RX FIFO filters needed */
            base->FLEXCAN_CTRL2 = (base->FLEXCAN_CTRL2 & ~TT_CAN_FLEXCAN_CTRL2_RFFN_Msk) | ((numOfFilters << TT_CAN_FLEXCAN_CTRL2_RFFN_Pos) & TT_CAN_FLEXCAN_CTRL2_RFFN_Msk);
            /* RX FIFO global mask, take in consideration all filter fields*/
            (base->FLEXCAN_RXFGMASK) = TT_CAN_FLEXCAN_RXFGMASK_FGM_Msk;

            for (i = 0U; i < noOfMbx; i++)
            {
                /* RX individual mask */
                base->FLEXCAN_RXIMR[i] = (TT_CAN_FLEXCAN_RXIMR_MI_Msk << FLEXCAN_HW_ID_EXT_Pos) & (FLEXCAN_HW_ID_STD_Msk | FLEXCAN_HW_ID_EXT_Msk);
            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
/**
* @brief        Sets the payload size of the MBs
* @details      Sets the payload size of the MBs
* @param[in]    base - The can base address
* @param[in]    payloadSize - payload Size
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetPayloadSize(TT_CAN_Type * base,
                            TT_CONST Flexcan_Hw_PayloadSizeType * payloadSize)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == payloadSize)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32 tmp = 0;
        TT_ParaCheck(((FALSE == FlexCAN_IsFDEnabled(base)) && (FLEXCAN_PAYLOAD_SIZE_8 != payloadSize->payloadBlock0)), TT_RET_PARAM_CONFIG_ERR, &TTRetVal);
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 1U)
        TT_ParaCheck(((FALSE == FlexCAN_IsFDEnabled(base)) && (FLEXCAN_PAYLOAD_SIZE_8 != payloadSize->payloadBlock1)), TT_RET_PARAM_CONFIG_ERR, &TTRetVal);
#endif
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 2U)
        TT_ParaCheck(((FALSE == FlexCAN_IsFDEnabled(base)) && (FLEXCAN_PAYLOAD_SIZE_8 != payloadSize->payloadBlock2)), TT_RET_PARAM_CONFIG_ERR, &TTRetVal);
#endif
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 3U)
        TT_ParaCheck(((FALSE == FlexCAN_IsFDEnabled(base)) && (FLEXCAN_PAYLOAD_SIZE_8 != payloadSize->payloadBlock3)), TT_RET_PARAM_CONFIG_ERR, &TTRetVal);
#endif
        if(TT_RET_SUCCESS == TTRetVal)
        {
            /* If FD is not enabled, only 8 bytes payload is supported */
            if (FlexCAN_IsFDEnabled(base))
            {
                tmp = base->FLEXCAN_FDCTRL;
                tmp &= ~(TT_CAN_FLEXCAN_FDCTRL_MBDSR0_Msk);
                tmp |= ((uint32)payloadSize->payloadBlock0) << TT_CAN_FLEXCAN_FDCTRL_MBDSR0_Pos;
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 1U)
                tmp &= ~(TT_CAN_FLEXCAN_FDCTRL_MBDSR1_Msk);
                tmp |= ((uint32)payloadSize->payloadBlock1) << TT_CAN_FLEXCAN_FDCTRL_MBDSR1_Pos;
#endif
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 2U)
                tmp &= ~(TT_CAN_FLEXCAN_FDCTRL_MBDSR2_Msk);
                tmp |= ((uint32)payloadSize->payloadBlock2) << TT_CAN_FLEXCAN_FDCTRL_MBDSR2_Pos;
#endif
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 3U)
                tmp &= ~(TT_CAN_FLEXCAN_FDCTRL_MBDSR3_Msk);
                tmp |= ((uint32)payloadSize->payloadBlock3) << TT_CAN_FLEXCAN_FDCTRL_MBDSR3_Pos;
#endif
                base->FLEXCAN_FDCTRL = tmp;
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#endif /* End FLEXCAN_HW_FEATURE_HAS_FD */

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Returns the payload size of the MBs (in bytes)
* @details      Returns the payload size of the MBs (in bytes)
* @param[in]    base - The can base address
* @param[in]    mbdsrIdx - mb Idx
* @param[out]   payloadSize - payload Size
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriGetPayloadSize(TT_CONST TT_CAN_Type * base, uint8 mbdsrIdx, uint8 * payloadSize)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == payloadSize)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        switch (mbdsrIdx)
        {
        case 0 :
            *payloadSize = (uint8)(8UL << ((base->FLEXCAN_FDCTRL & TT_CAN_FLEXCAN_FDCTRL_MBDSR0_Msk) >> TT_CAN_FLEXCAN_FDCTRL_MBDSR0_Pos));
            break;
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 1U)
        case 1 :
            *payloadSize = (uint8)(8UL << ((base->FLEXCAN_FDCTRL & TT_CAN_FLEXCAN_FDCTRL_MBDSR1_Msk) >> TT_CAN_FLEXCAN_FDCTRL_MBDSR1_Pos));
            break;
#endif
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 2U)
        case 2 :
            *payloadSize = (uint8)(8UL << ((base->FLEXCAN_FDCTRL & TT_CAN_FLEXCAN_FDCTRL_MBDSR2_Msk) >> TT_CAN_FLEXCAN_FDCTRL_MBDSR2_Pos));
            break;
#endif
#if (FLEXCAN_HW_FEATURE_MBDSR_COUNT > 3U)
        case 3 :
            *payloadSize = (uint8)(8UL << ((base->FLEXCAN_FDCTRL & TT_CAN_FLEXCAN_FDCTRL_MBDSR3_Msk) >> TT_CAN_FLEXCAN_FDCTRL_MBDSR3_Pos));
            break;
#endif
        default :
            *payloadSize = (uint8)(8UL << ((base->FLEXCAN_FDCTRL & TT_CAN_FLEXCAN_FDCTRL_MBDSR0_Msk) >> TT_CAN_FLEXCAN_FDCTRL_MBDSR0_Pos));
            break;
        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Gets the payload size of the MBs
* @details      Gets the payload size of the MBs
* @param[in]    base - The can base address
* @param[in]    maxMsgBuffNum - max MsgBuff Num
* @param[out]   payloadSize - payload Size
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriGetMbPayloadSize(TT_CONST TT_CAN_Type * base, uint32 maxMsgBuffNum, uint8 * payloadSize)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == payloadSize)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        TT_CONST uint8 arbitration_field_size = 8U;
        TT_CONST uint32 ramBlockSize = 512U;
        uint8 maxMbBlockNum = 0U;
        uint8 i=0U;
        uint8 mb_size = 0U;
        *payloadSize = 8;
        for (i=0; i< (uint8)FLEXCAN_HW_FEATURE_MBDSR_COUNT; i++)
        {
            /* Check that the number of MBs is supported based on the payload size*/
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            TTRetVal = Can_Hw_PriGetPayloadSize(base, i, payloadSize);
#endif /* Else can_real_payload will remain as 8 payload size */
            mb_size = (uint8)(*payloadSize + arbitration_field_size);
            maxMbBlockNum += (uint8)(ramBlockSize / mb_size);
            if (maxMbBlockNum > maxMsgBuffNum)
            {
                break;
            }
            else
            {

            }
        }
#if (STD_ON == FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY)
        /* exceeded normal ram block */
        if ((uint8)FLEXCAN_HW_FEATURE_MBDSR_COUNT == i)
        {
            *payloadSize = 64U;
        }
        else
        {

        }
#endif
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Lock the RX message buffer
* @details      Lock the RX message buffer
* @param[in]    base - The can base address
* @param[in]    msgBuffIdx - msgBuff Idx
* @return       void
* @retval       None
*/
LOCAL_INLINE void Can_Hw_PriLockRxMsgBuff(TT_CONST TT_CAN_Type * base, uint32 msgBuffIdx)
{
    volatile uint32 * flexcan_mb = NULL_PTR;
    (void)Can_Hw_PriGetMsgBuffRegion(base, msgBuffIdx, &flexcan_mb);

    if(NULL_PTR != flexcan_mb)
    {
        /* Lock the mailbox by reading it */
        (void)*flexcan_mb;
    }
    else
    {

    }
}

/**
* @brief        Enables/Disables the FlexCAN Message Buffer interrupt
* @details      Enables/Disables the FlexCAN Message Buffer interrupt
* @param[in]    base - The can base address
* @param[in]    u8Instance - Can Instance
* @param[in]    msgBuffIdx - Index of the message buffer
* @param[in]    enable - choose enable or disable
* @param[in]    bIsIntActive - Int Active
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetMsgBuffIntCmd(TT_CAN_Type * base,
                                               uint8 u8Instance,
                                               uint32 msgBuffIdx,
                                               boolean enable,
                                               boolean bIsIntActive)
{
    uint32 temp = 0;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* Enable the corresponding message buffer Interrupt */
        temp = 1UL << (msgBuffIdx % 32U);
        if (msgBuffIdx < 32U)
        {
            if (enable)
            {
                FlexCAN_Hw_au32ImaskBuff[u8Instance][0U] = ((FlexCAN_Hw_au32ImaskBuff[u8Instance][0U]) | (temp));
                if (TRUE == bIsIntActive)
                {
                    base->FLEXCAN_IMASK1 = FlexCAN_Hw_au32ImaskBuff[u8Instance][0U];
                }
                else
                {

                }

            }
            else
            {
                FlexCAN_Hw_au32ImaskBuff[u8Instance][0U] = ((FlexCAN_Hw_au32ImaskBuff[u8Instance][0U]) & ~(temp));
                base->FLEXCAN_IMASK1 = FlexCAN_Hw_au32ImaskBuff[u8Instance][0U];

            }
        }
        else
        {

        }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U
        if ((msgBuffIdx >= 32U) && (msgBuffIdx < 64U))
        {
            if (enable)
            {
                FlexCAN_Hw_au32ImaskBuff[u8Instance][1U] = ((FlexCAN_Hw_au32ImaskBuff[u8Instance][1U]) | (temp));
                if (TRUE == bIsIntActive)
                {
                    base->FLEXCAN_IMASK2 = FlexCAN_Hw_au32ImaskBuff[u8Instance][1U];
                }
                else
                {

                }
            }
            else
            {
                FlexCAN_Hw_au32ImaskBuff[u8Instance][1U] = ((FlexCAN_Hw_au32ImaskBuff[u8Instance][1U]) & ~(temp));
                base->FLEXCAN_IMASK2 = FlexCAN_Hw_au32ImaskBuff[u8Instance][1U];
            }
        }
        else
        {

        }
#endif /* if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U */
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U
        if ((msgBuffIdx >= 64U) && (msgBuffIdx < 96U))
        {
            if (enable)
            {
                FlexCAN_Hw_au32ImaskBuff[u8Instance][2U] = ((FlexCAN_Hw_au32ImaskBuff[u8Instance][2U]) | (temp));
                if (TRUE == bIsIntActive)
                {
                    base->FLEXCAN_IMASK3 = FlexCAN_Hw_au32ImaskBuff[u8Instance][2U];
                }
                else
                {

                }
            }
            else
            {
                FlexCAN_Hw_au32ImaskBuff[u8Instance][2U] = ((FlexCAN_Hw_au32ImaskBuff[u8Instance][2U]) & ~(temp));
                base->FLEXCAN_IMASK3 = FlexCAN_Hw_au32ImaskBuff[u8Instance][2U];

            }
        }
        else
        {

        }
#endif /* if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U */
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U
        if (msgBuffIdx >= 96U)
        {
            if (enable)
            {
                FlexCAN_Hw_au32ImaskBuff[u8Instance][3U] = ((FlexCAN_Hw_au32ImaskBuff[u8Instance][3U]) | (temp));
                if (TRUE == bIsIntActive)
                {
                    base->FLEXCAN_IMASK4 = FlexCAN_Hw_au32ImaskBuff[u8Instance][3U];
                }
                else
                {

                }
            }
            else
            {
                FlexCAN_Hw_au32ImaskBuff[u8Instance][3U] = ((FlexCAN_Hw_au32ImaskBuff[u8Instance][3U]) & ~(temp));
                base->FLEXCAN_IMASK4 = FlexCAN_Hw_au32ImaskBuff[u8Instance][3U];
            }
        }
        else
        {

        }
#endif /* if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U */
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Disable the corresponding Message Buffer interrupt only if interrupts are active
* @details      Disable the corresponding Message Buffer interrupt only if interrupts are active
* @param[in]    pBase - The can base address
* @param[in]    u8Instance - Can Instance
* @param[in]    mb_idx - Index of the message buffer
* @param[in]    bIsIntActive - Int Active
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriClearMsgBuffIntCmd(TT_CAN_Type * pBase,
                                uint8 u8Instance,
                                uint32 mb_idx,
                                boolean bIsIntActive
                               )
{
    TT_CONST uint32 temp = (1UL << (mb_idx % 32U));
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == pBase), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {

        /* Stop the running transfer. */
        if (mb_idx < 32U)
        {
            FlexCAN_Hw_au32ImaskBuff[u8Instance][0U] = (pBase->FLEXCAN_IMASK1 & (~temp));
            if (TRUE == bIsIntActive)
            {
                pBase->FLEXCAN_IMASK1 = FlexCAN_Hw_au32ImaskBuff[u8Instance][0U];
            }
            else
            {

            }

        }
        else
        {

        }
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U
        if ((mb_idx >= 32U) && (mb_idx < 64U))
        {
            FlexCAN_Hw_au32ImaskBuff[u8Instance][1U] = (pBase->FLEXCAN_IMASK2 & (~temp));
            if (TRUE == bIsIntActive)
            {
                pBase->FLEXCAN_IMASK2 = FlexCAN_Hw_au32ImaskBuff[u8Instance][1U];
            }
            else
            {

            }

        }
        else
        {

        }
#endif
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U
        if ((mb_idx >= 64U) && (mb_idx < 96U))
        {
            FlexCAN_Hw_au32ImaskBuff[u8Instance][2U] = (pBase->FLEXCAN_IMASK3 & (~temp));
            if (TRUE == bIsIntActive)
            {
                pBase->FLEXCAN_IMASK3 = FlexCAN_Hw_au32ImaskBuff[u8Instance][2U];
            }
            else
            {

            }

        }
        else
        {

        }
#endif /* FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U */
#if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U
        if (mb_idx >= 96U)
        {
            FlexCAN_Hw_au32ImaskBuff[u8Instance][3U] = (pBase->FLEXCAN_IMASK4 & (~temp));
            if (TRUE == bIsIntActive)
            {
                pBase->FLEXCAN_IMASK4 = FlexCAN_Hw_au32ImaskBuff[u8Instance][3U];
            }
            else
            {

            }

        }
        else
        {

        }
#endif /* #if FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U */
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Disable all interrupts
* @details      Disable all interrupts
* @param[in]    pBase - The can base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriDisableInterrupts(TT_CAN_Type * pBase)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == pBase), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U)
        TT_CONST uint32 u32MaxMbCrtlNum = Can_Hw_PriGetMaxMbNum(pBase);
#endif /* (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U) */

        pBase->FLEXCAN_IMASK1 = 0U;
#if (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U)
        if (u32MaxMbCrtlNum > 32U)
        {
            pBase->FLEXCAN_IMASK2 = 0U;
        }
        else
        {

        }
#endif /* (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U) */
#if (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U)
        if (u32MaxMbCrtlNum > 64U)
        {
            pBase->FLEXCAN_IMASK3 = 0U;
        }
        else
        {

        }
#endif /* (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U) */
#if (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U)
        if (u32MaxMbCrtlNum > 96U)
        {
            pBase->FLEXCAN_IMASK4 = 0U;
        }
        else
        {

        }
#endif /* (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U) */
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Enable all interrupts configured
* @details      Enable all interrupts configured
* @param[in]    pBase - The can base address
* @param[in]    u8Instance - A FlexCAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnableInterrupts(TT_CAN_Type * pBase, uint8 u8Instance)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((u8Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == pBase), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U)
        TT_CONST uint32 u32MaxMbCrtlNum = Can_Hw_PriGetMaxMbNum(pBase);
#endif /* (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U) */

        pBase->FLEXCAN_IMASK1 = FlexCAN_Hw_au32ImaskBuff[u8Instance][0U];
#if (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U)
        if (u32MaxMbCrtlNum > 32U)
        {
            pBase->FLEXCAN_IMASK2 = FlexCAN_Hw_au32ImaskBuff[u8Instance][1U];
        }
        else
        {

        }
#endif /* (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 32U) */
#if (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U)
        if (u32MaxMbCrtlNum > 64U)
        {
            pBase->FLEXCAN_IMASK3 = FlexCAN_Hw_au32ImaskBuff[u8Instance][2U];
        }
        else
        {

        }
#endif /* (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 64U) */
#if (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U)
        if (u32MaxMbCrtlNum > 96U)
        {
            pBase->FLEXCAN_IMASK4 = FlexCAN_Hw_au32ImaskBuff[u8Instance][3U];
        }
        else
        {

        }
#endif /* (FLEXCAN_HW_FEATURE_MAX_MB_NUM > 96U) */
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Sets the FlexCAN message buffer fields for receiving
* @details      Sets the FlexCAN message buffer fields for receiving
* @param[in]    base - The FlexCAN base address
* @param[in]    msgBuffIdx - Index of the message buffer
* @param[in]    cs - CODE/status values (RX)
* @param[in]    msgId - ID of the message to receive
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetRxMsgBuff(TT_CONST TT_CAN_Type * base,
                          uint32 msgBuffIdx,
                          TT_CONST Flexcan_Hw_MsbuffCodeStatusType * cs,
                          uint32 msgId)
{
    volatile uint32 * flexcan_mb = NULL_PTR;
    volatile uint32 * flexcan_mb_id = NULL_PTR;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == cs)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32_t val1, val2 = 1;
        TTRetVal = Can_Hw_PriGetMsgBuffRegion(base, msgBuffIdx, &flexcan_mb);
        if(TT_RET_SUCCESS == TTRetVal)
        {
            flexcan_mb_id = &flexcan_mb[1];

            /* Check if RX FIFO is enabled */
            if (TRUE == ((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_RFEN_Msk) >> TT_CAN_FLEXCAN_MCR_RFEN_Pos))
            {
                /* Get the number of RX FIFO Filters*/
                val1 = (((base->FLEXCAN_CTRL2) & TT_CAN_FLEXCAN_CTRL2_RFFN_Msk) >> TT_CAN_FLEXCAN_CTRL2_RFFN_Pos);
                val2 = 5U + (((val1 + 1U) * 8U) / 4U);

                if (msgBuffIdx <= val2)
                {
                    TTRetVal = TT_RET_PARAM_INDEX_ERR;
                }
                else
                {

                }
            }
            else
            {

            }

            if(TT_RET_SUCCESS == TTRetVal)
            {
                /* Clean up the arbitration field area */
                *flexcan_mb = 0;
                *flexcan_mb_id = 0;

                /* Set the ID according the format structure */
                if (FLEXCAN_MSG_ID_EXT == cs->msgIdType)
                {
                    /* Set IDE */
                    *flexcan_mb |= FLEXCAN_HW_CS_IDE_Msk;

                    /* Clear SRR bit */
                    *flexcan_mb &= ~FLEXCAN_HW_CS_SRR_Msk;

                    /* ID [28-0] */
                    *flexcan_mb_id &= ~(FLEXCAN_HW_ID_STD_Msk | FLEXCAN_HW_ID_EXT_Msk);
                    *flexcan_mb_id |= (msgId & (FLEXCAN_HW_ID_STD_Msk | FLEXCAN_HW_ID_EXT_Msk));
                }
                else
                {

                }

                if (FLEXCAN_MSG_ID_STD == cs->msgIdType)
                {
                    /* Make sure IDE and SRR are not set */
                    *flexcan_mb &= ~(FLEXCAN_HW_CS_IDE_Msk | FLEXCAN_HW_CS_SRR_Msk);

                    /* ID[28-18] */
                    *flexcan_mb_id &= ~FLEXCAN_HW_ID_STD_Msk;
                    *flexcan_mb_id |= (msgId << FLEXCAN_HW_ID_STD_Pos) & FLEXCAN_HW_ID_STD_Msk;
                }
                else
                {

                }

                /* Set MB CODE */
                if ((uint32)FLEXCAN_RX_NOT_USED != cs->code)
                {
                    *flexcan_mb &= ~FLEXCAN_HW_CS_CODE_Msk;
                    *flexcan_mb |= (cs->code << FLEXCAN_HW_CS_CODE_Pos) & FLEXCAN_HW_CS_CODE_Msk;
                }
                else
                {

                }
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Gets the message buffer timestamp value
* @details      Gets the message buffer timestamp value
* @param[in]    base - The can base address
* @param[in]    msgBuffIdx - msgBuff Idx
* @return       uint32
* @retval       value of timestamp for selected message buffer
*/
LOCAL_INLINE uint32 Can_Hw_PriGetMsgBuffTimestamp(TT_CONST TT_CAN_Type * base, uint32 msgBuffIdx)
{
    uint32 TimeStamp = 0U;
    volatile  uint32 * Flexcan_Mb = NULL_PTR;
    (void)Can_Hw_PriGetMsgBuffRegion(base, msgBuffIdx, &Flexcan_Mb);
    if(NULL_PTR != Flexcan_Mb)
    {
        TimeStamp = (uint32)((*Flexcan_Mb & FLEXCAN_HW_CS_TIME_STAMP_Msk) >> FLEXCAN_HW_CS_TIME_STAMP_Pos);
    }
    else
    {

    }

    return TimeStamp;
}

/**
* @brief        Gets the FlexCAN message buffer fields
* @details      Gets the FlexCAN message buffer fields
* @param[in]    base - The FlexCAN base address
* @param[in]    msgBuffIdx - Index of the message buffer
* @param[out]   msgBuff - The fields of the message buffer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriGetMsgBuff(TT_CONST TT_CAN_Type * base,
                        uint32 msgBuffIdx,
                        Flexcan_Hw_MsgBuffType * msgBuff)
{

    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == msgBuff)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint8 i = 0U;

        volatile uint32 * Flexcan_Mb = NULL_PTR;
        TTRetVal = Can_Hw_PriGetMsgBuffRegion(base, msgBuffIdx, &Flexcan_Mb);
        if(TT_RET_SUCCESS == TTRetVal)
        {
            volatile TT_CONST uint32 *TT_CONST Flexcan_Mb_Id   = &Flexcan_Mb[1];
            volatile TT_CONST uint8 *TT_CONST Flexcan_Mb_Data = (volatile TT_CONST uint8 *)(&Flexcan_Mb[2]);
            volatile TT_CONST uint32 *TT_CONST Flexcan_Mb_Data_32 = &Flexcan_Mb[2];
            uint32 *TT_CONST MsgBuff_Data_32 = (uint32 *)(uint32)(msgBuff->data);
            uint32 MbWord = 0;

            TT_CONST uint8 Flexcan_Mb_Dlc_Value = (uint8)(((*Flexcan_Mb) & FLEXCAN_HW_CS_DLC_Msk) >> 16);
            uint8 Payload_Size = Can_Hw_PriComputePayloadSize(Flexcan_Mb_Dlc_Value);


#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
            uint8 TmpPayload_Size = 0;
            TTRetVal = Can_Hw_PriGetMbPayloadSize(base, msgBuffIdx, &TmpPayload_Size);
            /* Payload Size is based on MBDSR for 1 MBDSR corresponds 32 * 8Bytes MBs  */
            if((Payload_Size > TmpPayload_Size) && (TT_RET_SUCCESS == TTRetVal))
            {
                Payload_Size = TmpPayload_Size;
                TTRetVal = TT_RET_FULL_ERR;
            }
            else
            {

            }
#endif /* FLEXCAN_HW_FEATURE_HAS_FD */

            msgBuff->dataLen = Payload_Size;
            /* Get a MB field values */
            msgBuff->cs = *Flexcan_Mb;
            if ((msgBuff->cs & FLEXCAN_HW_CS_IDE_Msk) != 0U)
            {
                msgBuff->msgId = (*Flexcan_Mb_Id);
            }
            else
            {
                msgBuff->msgId = (*Flexcan_Mb_Id) >> FLEXCAN_HW_ID_STD_Pos;
            }

            msgBuff->time_stamp = (uint32)((msgBuff->cs & FLEXCAN_HW_CS_TIME_STAMP_Msk) >> FLEXCAN_HW_CS_TIME_STAMP_Pos);

            for (i = 0U; i < (Payload_Size & ~3U); i += 4U)
            {
                MbWord = Flexcan_Mb_Data_32[i >> 2U];
                FLEXCAN_HW_SWAP_BYTES_IN_WORD(MbWord, MsgBuff_Data_32[i >> 2U]);
            }
            for (; i < Payload_Size; i++)
            {   /* Max allowed value for index is 63 */
                msgBuff->data[i] = Flexcan_Mb_Data[FLEXCAN_HW_SWAP_BYTES_IN_WORD_INDEX(i)];
            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Sets the FlexCAN message buffer fields for transmitting
* @details      Sets the FlexCAN message buffer fields for transmitting
* @param[in]    pMbAddr - The Message buffer address
* @param[in]    cs - CODE/status values (TX)
* @param[in]    msgId - ID of the message to transmit
* @param[in]    msgData - Bytes of the FlexCAN message
* @param[in]    isRemote - Will set RTR remote Flag
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetTxMsgBuff(volatile uint32 * TT_CONST pMbAddr,
                          TT_CONST Flexcan_Hw_MsbuffCodeStatusType * cs,
                          uint32 msgId,
                          TT_CONST uint8 * msgData,
                          TT_CONST boolean isRemote)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == pMbAddr) || (NULL_PTR == cs)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32 Flexcan_Mb_Config = 0;
        uint32 DataByte = 0;
        uint8 Dlc_Value = 0;
        uint8 Payload_Size = 0;
        volatile uint32 *TT_CONST Flexcan_Mb = pMbAddr;
        volatile uint32 *TT_CONST Flexcan_Mb_Id   = &Flexcan_Mb[1];
        volatile uint8 *TT_CONST Flexcan_Mb_Data = (volatile uint8*)(&Flexcan_Mb[2]);
        volatile uint32 *TT_CONST Flexcan_Mb_Data_32 = &Flexcan_Mb[2];
        TT_CONST uint32 *TT_CONST MsgData_32 = (TT_CONST uint32*)(TT_CONST uint32)msgData;

        /* Clean up the arbitration field area and set TxMB Inactive */
        *Flexcan_Mb = (uint32)((((uint32)FLEXCAN_TX_INACTIVE & (uint32)0x1F) << (uint8)FLEXCAN_HW_CS_CODE_Pos) & (uint32)FLEXCAN_HW_CS_CODE_Msk);
        *Flexcan_Mb_Id = 0;

        /* Compute the value of the DLC field */
        Dlc_Value = Can_Hw_PriComputeDLCValue((uint8)cs->dataLen);
        if(0xFFU != Dlc_Value)
        {
            /* Copy user's buffer into the message buffer data area */
            if (msgData != NULL_PTR)
            {
                for (DataByte = 0; DataByte < (cs->dataLen & ~3U); DataByte += 4U)
                {
                    FLEXCAN_HW_SWAP_BYTES_IN_WORD((MsgData_32[DataByte >> 2U]), (Flexcan_Mb_Data_32[DataByte >> 2U]));
                }

                for ( ; DataByte < cs->dataLen; DataByte++)
                {
                    Flexcan_Mb_Data[FLEXCAN_HW_SWAP_BYTES_IN_WORD_INDEX(DataByte)] =  msgData[DataByte];
                }

#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                Payload_Size = Can_Hw_PriComputePayloadSize(Dlc_Value);
                /* Add padding, if needed */
                for (DataByte = cs->dataLen; DataByte < Payload_Size; DataByte++)
                {
                    Flexcan_Mb_Data[FLEXCAN_HW_SWAP_BYTES_IN_WORD_INDEX(DataByte)] = cs->fd_padding;
                }
#endif /* FLEXCAN_HW_FEATURE_HAS_FD */
            }
            else
            {

            }

            /* Set the ID according the format structure */
            if (FLEXCAN_MSG_ID_EXT == cs->msgIdType)
            {
                /* ID [28-0] */
                *Flexcan_Mb_Id &= ~(FLEXCAN_HW_ID_STD_Msk | FLEXCAN_HW_ID_EXT_Msk);
                *Flexcan_Mb_Id |= (msgId & (FLEXCAN_HW_ID_STD_Msk | FLEXCAN_HW_ID_EXT_Msk));
                /* Set IDE and SRR bit*/
                Flexcan_Mb_Config |= (FLEXCAN_HW_CS_IDE_Msk | FLEXCAN_HW_CS_SRR_Msk);
            }
            else
            {

            }
            if (FLEXCAN_MSG_ID_STD == cs->msgIdType)
            {
                /* ID[28-18] */
                *Flexcan_Mb_Id &= ~FLEXCAN_HW_ID_STD_Msk;
                *Flexcan_Mb_Id |= (msgId << FLEXCAN_HW_ID_STD_Pos) & FLEXCAN_HW_ID_STD_Msk;
                /* make sure IDE and SRR are not set */
                Flexcan_Mb_Config &= ~(FLEXCAN_HW_CS_IDE_Msk | FLEXCAN_HW_CS_SRR_Msk);
            }
            else
            {

            }
            /* Set the length of data in bytes */
            Flexcan_Mb_Config &= ~FLEXCAN_HW_CS_DLC_Msk;
            Flexcan_Mb_Config |= ((uint32)Dlc_Value << FLEXCAN_HW_CS_DLC_Pos) & FLEXCAN_HW_CS_DLC_Msk;
            /* Set MB CODE */
            if (cs->code != (uint32)FLEXCAN_TX_NOT_USED)
            {

                if ((uint32)FLEXCAN_TX_REMOTE == cs->code)
                {
                    /* Set RTR bit */
                    Flexcan_Mb_Config |= FLEXCAN_HW_CS_RTR_Msk;
                }
                else
                {
                    if (TRUE == isRemote)
                    {
                        /* Set RTR bit */
                        Flexcan_Mb_Config |= FLEXCAN_HW_CS_RTR_Msk;
                    }
                    else
                    {

                    }
                }

                /* Reset the code */
                Flexcan_Mb_Config &= ~FLEXCAN_HW_CS_CODE_Msk;
                /* Set the code */
                if (cs->fd_enable)
                {
                    Flexcan_Mb_Config |= ((cs->code << FLEXCAN_HW_CS_CODE_Pos) & FLEXCAN_HW_CS_CODE_Msk) | FLEXCAN_HW_MB_EDL_Msk;
                    /* In case of FD frame not supported RTR */
                    Flexcan_Mb_Config &= ~FLEXCAN_HW_CS_RTR_Msk;

                    if (cs->enable_brs)
                    {
                        Flexcan_Mb_Config |= FLEXCAN_HW_MB_BRS_Msk;
                    }
                    else
                    {

                    }
                }
                else
                {
                    Flexcan_Mb_Config |= (cs->code << FLEXCAN_HW_CS_CODE_Pos) & FLEXCAN_HW_CS_CODE_Msk;
                }

                *Flexcan_Mb |= Flexcan_Mb_Config;
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Sets  the maximum number of Message Buffers
* @details      Sets  the maximum number of Message Buffers
* @param[in]    base - The FlexCAN base address
* @param[in]    maxMsgBuffNum - Maximum number of message buffers
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetMaxMsgBuffNum(TT_CAN_Type * base, uint32 maxMsgBuffNum)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((maxMsgBuffNum == 0U), TT_RET_PARAM_COUNT_ERR, &TTRetVal);
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint8 MsgBuffIdx = 0;
        uint32 DataByte = 0;
#if (STD_ON == FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY)
        volatile uint32 *TT_CONST RAM_EXPANDED = (uint32*)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_EXP_RAM_OFFSET);
#else
        volatile uint32 *TT_CONST RAM = (uint32*)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_RAM_OFFSET);
#endif /* FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY */
        volatile uint32 * ValEndMbPointer = NULL_PTR;
        volatile uint32 *Flexcan_Mb = NULL_PTR;
        volatile uint32 *Flexcan_Mb_Id   = NULL_PTR ;
        volatile uint8  *Flexcan_Mb_Data = NULL_PTR;
        TT_CONST uint8 Arbitration_Field_Size = 8U;
        uint8 Can_Real_Payload = 8;
        TTRetVal = Can_Hw_PriGetMbPayloadSize(base, maxMsgBuffNum - (uint32)1U, &Can_Real_Payload);
        uint32 ValEndMb = 0U;
        uint32 ValEndRam = 0U;
        if(TT_RET_SUCCESS == TTRetVal)
        {
            TTRetVal = Can_Hw_PriGetMsgBuffRegion(base, (maxMsgBuffNum - (uint32)1U), &ValEndMbPointer);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                ValEndMb = (uint32)ValEndMbPointer + (uint32)Can_Real_Payload + (uint32)Arbitration_Field_Size;

#if (STD_ON == FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY)
                ValEndRam = (uint32)&RAM_EXPANDED[FLEXCAN_HW_RAM1n_COUNT];
#else
                ValEndRam = (uint32)&RAM[(Can_Hw_PriGetMaxMbNum(base) * 4U)];
#endif /* FLEXCAN_HW_FEATURE_HAS_EXPANDABLE_MEMORY */

                if ((maxMsgBuffNum > Can_Hw_PriGetMaxMbNum(base)) || (ValEndMb > ValEndRam))
                {
                    TTRetVal = TT_RET_PARAM_INDEX_ERR;
                }
                else
                {

                }

                if(TT_RET_SUCCESS == TTRetVal)
                {
                    /* Set the maximum number of MBs*/
                    base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_MAXMB_Msk) | (((maxMsgBuffNum-1U) << TT_CAN_FLEXCAN_MCR_MAXMB_Pos) & TT_CAN_FLEXCAN_MCR_MAXMB_Msk);
                    if (((base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_RFEN_Msk) >> TT_CAN_FLEXCAN_MCR_RFEN_Pos) == 0U)
                    {
                        /* Initialize all message buffers as inactive */
                        for (MsgBuffIdx = 0; ((MsgBuffIdx < maxMsgBuffNum) && (TT_RET_SUCCESS == TTRetVal)); MsgBuffIdx++)
                        {
                            TTRetVal = Can_Hw_PriGetMsgBuffRegion(base, MsgBuffIdx, &Flexcan_Mb);
                            if(TT_RET_SUCCESS == TTRetVal)
                            {
                                Flexcan_Mb_Id   = &Flexcan_Mb[1];
                                Flexcan_Mb_Data = (volatile uint8*)(&Flexcan_Mb[2]);
                                *Flexcan_Mb = 0x0U;
                                *Flexcan_Mb_Id = 0x0U;
                                TTRetVal = Can_Hw_PriGetMbPayloadSize(base, MsgBuffIdx, &Can_Real_Payload);
                                for (DataByte = 0; DataByte < Can_Real_Payload; DataByte++)
                                {
                                    Flexcan_Mb_Data[DataByte] = 0x0U;
                                }
                            }
                            else
                            {

                            }
                        }
                    }
                    else
                    {

                    }
                }
                else
                {

                }
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/**
* @brief        Set operation mode
* @details      Set operation mode
* @param[in]    base - The can base address
* @param[in]    mode - Set an operation mode
* @return       void
* @retval       None
*/
LOCAL_INLINE void Can_Hw_PriSetOperationMode(TT_CAN_Type * base, Flexcan_Hw_ModesType mode)
{
    switch (mode)
    {
        case FLEXCAN_NORMAL_MODE:
            base->FLEXCAN_CTRL1 = (base->FLEXCAN_CTRL1 & ~TT_CAN_FLEXCAN_CTRL1_LOM_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LOM, 0U);
            base->FLEXCAN_CTRL1 = (base->FLEXCAN_CTRL1 & ~TT_CAN_FLEXCAN_CTRL1_LPB_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LPB, 0U);
            break;
        case FLEXCAN_LISTEN_ONLY_MODE:
            base->FLEXCAN_CTRL1 = (base->FLEXCAN_CTRL1 & ~TT_CAN_FLEXCAN_CTRL1_LOM_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LOM, 1U);
            break;
        case FLEXCAN_LOOPBACK_MODE:
            base->FLEXCAN_CTRL1 = (base->FLEXCAN_CTRL1 & ~TT_CAN_FLEXCAN_CTRL1_LPB_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LPB, 1U);
            base->FLEXCAN_CTRL1 = (base->FLEXCAN_CTRL1 & ~TT_CAN_FLEXCAN_CTRL1_LOM_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_CTRL1_LOM, 0U);
            /* Enable Self Reception */
            base->FLEXCAN_MCR = (base->FLEXCAN_MCR & ~TT_CAN_FLEXCAN_MCR_SRXDIS_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_MCR_SRXDIS, 0UL);
            break;
        default:
            /* do nothing */
            break;
    }
}

/**
* @brief        Sets the FlexCAN Rx FIFO fields
* @details      Sets the FlexCAN Rx FIFO fields
* @param[in]    base - The FlexCAN base address
* @param[in]    idFormat - The format of the Rx FIFO ID Filter Table Elements
* @param[in]    idFilterTable - The ID filter table elements which contain RTR bit,IDE bit, and RX message ID
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetRxFifoFilter(TT_CAN_Type * base,
                             Flexcan_Hw_RxFifoIdElementFormatType idFormat,
                             TT_CONST Flexcan_Hw_IdTableType * idFilterTable)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == idFilterTable)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* Set RX FIFO ID filter table elements*/
        uint32 i, j, NumOfFilters;
        uint32 Val1 = 0UL, Val2 = 0UL, Val = 0UL;
        volatile uint32 *TT_CONST FilterTable = (uint32 *)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_RAM_OFFSET + ((uint32)FLEXCAN_HW_RX_FIFO_FILTER_TABLE_OFFSET * 4U));

        NumOfFilters = (((base->FLEXCAN_CTRL2) & TT_CAN_FLEXCAN_CTRL2_RFFN_Msk) >> TT_CAN_FLEXCAN_CTRL2_RFFN_Pos);
        switch (idFormat)
        {
        case (FLEXCAN_RX_FIFO_ID_FORMAT_A):

                    /* One full ID (standard and extended) per ID Filter Table element.*/
                    (base->FLEXCAN_MCR) =
                            (((base->FLEXCAN_MCR) & ~(TT_CAN_FLEXCAN_MCR_IDAM_Msk)) |
                                    ((((uint32)(((uint32)(FLEXCAN_RX_FIFO_ID_FORMAT_A)) << TT_CAN_FLEXCAN_MCR_IDAM_Pos)) & TT_CAN_FLEXCAN_MCR_IDAM_Msk)));

        for (i = 0U; i < FLEXCAN_HW_RXFIFO_FILTER_ELEM_NUM(NumOfFilters); i++)
        {
            Val = 0UL;

            if (idFilterTable[i].isRemoteFrame)
            {
                Val = FLEXCAN_HW_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATAB_RTR_Pos;
            }
            else
            {

            }

            if (idFilterTable[i].isExtendedFrame)
            {
                Val |= FLEXCAN_HW_RX_FIFO_ACCEPT_EXT_FRAME << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATAB_IDE_Pos;
                FilterTable[i] = Val + ((idFilterTable[i].id << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATA_EXT_Pos) &
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATA_EXT_Msk
                );
            }
            else
            {
                FilterTable[i] = Val + ((idFilterTable[i].id << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATA_STD_Pos) &
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATA_STD_Msk
                );
            }
        }
        break;
        case (FLEXCAN_RX_FIFO_ID_FORMAT_B):
                    /* Two full standard IDs or two partial 14-bit (standard and extended) IDs*/

                    (base->FLEXCAN_MCR) =
                            (((base->FLEXCAN_MCR) & ~(TT_CAN_FLEXCAN_MCR_IDAM_Msk)) | ((((uint32)(((uint32)(FLEXCAN_RX_FIFO_ID_FORMAT_B)) << TT_CAN_FLEXCAN_MCR_IDAM_Pos)) & TT_CAN_FLEXCAN_MCR_IDAM_Msk)));

        j = 0U;
        for (i = 0U; i < FLEXCAN_HW_RXFIFO_FILTER_ELEM_NUM(NumOfFilters); i++)
        {
            Val1 = 0U;
            Val2 = 0U;

            if (idFilterTable[j].isRemoteFrame)
            {
                Val1 = FLEXCAN_HW_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATAB_RTR_Pos;
            }
            else
            {

            }

            if (idFilterTable[j + 1U].isRemoteFrame)
            {
                Val2 = FLEXCAN_HW_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_RTR_Pos;
            }
            else
            {

            }

            if (idFilterTable[j].isExtendedFrame)
            {
                Val1 |= FLEXCAN_HW_RX_FIFO_ACCEPT_EXT_FRAME << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATAB_IDE_Pos;

                FilterTable[i] = Val1 + (((idFilterTable[j].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_Pos1
                );
            }
            else
            {
                FilterTable[i] = Val1 + ((idFilterTable[j].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_STD_Msk) <<
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_STD_Pos1
                );
            }

            if (idFilterTable[j + 1U].isExtendedFrame)
            {
                Val2 |= FLEXCAN_HW_RX_FIFO_ACCEPT_EXT_FRAME << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_IDE_Pos;

                FilterTable[i] |= Val2 + (((idFilterTable[j + 1U].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_EXT_Pos2
                );
            }
            else
            {
                FilterTable[i] |= Val2 + ((idFilterTable[j + 1U].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_STD_Msk) <<
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATB_STD_Pos2
                );
            }

            j = j + 2U;
        }
        break;
        case (FLEXCAN_RX_FIFO_ID_FORMAT_C):
                    /* Four partial 8-bit Standard IDs per ID Filter Table element.*/

                    (base->FLEXCAN_MCR) =
                            (((base->FLEXCAN_MCR) & ~(TT_CAN_FLEXCAN_MCR_IDAM_Msk)) |
                                    ((((uint32)((FLEXCAN_RX_FIFO_ID_FORMAT_C) << TT_CAN_FLEXCAN_MCR_IDAM_Pos)) & TT_CAN_FLEXCAN_MCR_IDAM_Msk)));

        j = 0U;
        for (i = 0U; i < FLEXCAN_HW_RXFIFO_FILTER_ELEM_NUM(NumOfFilters); i++)
        {
            if (idFilterTable[j].isExtendedFrame)
            {
                FilterTable[i] = Val1 + (((idFilterTable[j].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos1
                );
            }
            else
            {
                FilterTable[i] = Val1 + (((idFilterTable[j].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos1
                );
            }

            if (idFilterTable[j + 1U].isExtendedFrame)
            {
                FilterTable[i] |= Val1 + (((idFilterTable[j + 1U].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos2
                );
            }
            else
            {
                FilterTable[i] |= Val1 + (((idFilterTable[j + 1U].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos2
                );
            }

            if (idFilterTable[j + 2U].isExtendedFrame)
            {
                FilterTable[i] |= Val1 + (((idFilterTable[j + 2U].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos3
                );
            }
            else
            {
                FilterTable[i] |= Val1 + (((idFilterTable[j + 2U].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos3
                );
            }

            if (idFilterTable[j + 3U].isExtendedFrame)
            {
                FilterTable[i] |= Val1 + (((idFilterTable[j + 3U].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_Msk) >>
                        FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_Pos
                ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos4
                );
            }
            else
            {
                FilterTable[i] |= Val1 +
                        (((idFilterTable[j + 3U].id & FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_Msk) >>
                                FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_Pos
                        ) << FLEXCAN_HW_RX_FIFO_ID_FILTER_FORMATC_Pos4
                        );
            }

            j = j + 4U;
        }
        break;
        case (FLEXCAN_RX_FIFO_ID_FORMAT_D):
                    /* All frames rejected.*/

                    (base->FLEXCAN_MCR) = (((base->FLEXCAN_MCR) & ~(TT_CAN_FLEXCAN_MCR_IDAM_Msk)) |
                            ((((uint32)((FLEXCAN_RX_FIFO_ID_FORMAT_D) << TT_CAN_FLEXCAN_MCR_IDAM_Pos)) & TT_CAN_FLEXCAN_MCR_IDAM_Msk)));

        break;

        default:
        /* do nothing */
        break;
        }
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Gets the FlexCAN Rx FIFO data
* @details      Gets the FlexCAN Rx FIFO data
* @param[in]    base - The FlexCAN base address
* @param[in]    rxFifo - The FlexCAN receive FIFO data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriReadRxFifo(TT_CONST TT_CAN_Type * base, Flexcan_Hw_MsgBuffType * rxFifo)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == rxFifo)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32 DataByte = 0;
        uint32 MbWord = 0;
        volatile TT_CONST uint32 *TT_CONST flexcan_mb = (uint32 *)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_RAM_OFFSET);
        volatile TT_CONST uint32 *TT_CONST flexcan_mb_id = &flexcan_mb[1];
        volatile TT_CONST uint32 *TT_CONST flexcan_mb_data_32 = &flexcan_mb[2];
        uint32 *TT_CONST msgData_32 = (uint32 *)(uint32)(rxFifo->data);
        TT_CONST uint8 flexcan_mb_dlc_value = (uint8)(((*flexcan_mb) & FLEXCAN_HW_CS_DLC_Msk) >> 16);
        uint8 can_real_payload = Can_Hw_PriComputePayloadSize(flexcan_mb_dlc_value);
        /*
       Check if the length of received data packet bigger than the maximum length accepted,
       then processing flow shall continue with the maximum length defined by configuration.
       Legacy FIFO just support in normal mode.
         */
        /* no need to check if FD enabled or not because this function just is invoked when legacy fifo enabled only ! */
        if (can_real_payload > 8U)
        {
            can_real_payload = 8U;
        }
        else
        {

        }

        rxFifo->dataLen = can_real_payload;
        rxFifo->cs = *flexcan_mb;
        if ((rxFifo->cs & FLEXCAN_HW_CS_IDE_Msk) != 0U)
        {
            rxFifo->msgId = *flexcan_mb_id;
        }
        else
        {
            rxFifo->msgId = (*flexcan_mb_id) >> FLEXCAN_HW_ID_STD_Pos;
        }
        /* Extract the IDHIT */
        rxFifo->id_hit = (uint8)base->FLEXCAN_RXFIR;
        /* Extract the Time Stamp */
        rxFifo->time_stamp = (uint32)((rxFifo->cs & FLEXCAN_HW_CS_TIME_STAMP_Msk) >> FLEXCAN_HW_CS_TIME_STAMP_Pos);

        /* Copy MB[0] data field into user's buffer */
        for (DataByte = 0U; DataByte < can_real_payload; DataByte += 4U)
        {
            MbWord = flexcan_mb_data_32[DataByte >> 2U];
            FLEXCAN_HW_SWAP_BYTES_IN_WORD((MbWord), (msgData_32[DataByte >> 2U]));
        }
    }
    else
    {

    }

    return TTRetVal;
}
#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
* @brief        Read Enhanced Rx FIFO data
* @details      Copy Enhanced Rx FIFO data output into user's buffer
* @param[in]    base - The FlexCAN base address
* @param[in]    rxFifo - The FlexCAN receive FIFO data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriReadEnhancedRxFifo(TT_CONST TT_CAN_Type * base, Flexcan_Hw_MsgBuffType * rxFifo)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == rxFifo)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32 DataByte = 0;
        uint32 MbWord = 0;
        uint8 Idhit_Offset = 0;
        volatile TT_CONST uint32 *TT_CONST Flexcan_Mb = (uint32 *)((uint32)base + (uint32)FLEXCAN_HW_FEATURE_ENHANCED_FIFO_RAM_OFFSET);
        volatile TT_CONST uint32 *TT_CONST Flexcan_Mb_Id = &Flexcan_Mb[1];
        volatile TT_CONST uint32 *TT_CONST Flexcan_Mb_Data_32 = &Flexcan_Mb[2];
        uint32 * MsgData_32 = NULL_PTR;

        /* Compute payload size */
        TT_CONST uint8 flexcan_mb_dlc_value = (uint8)(((*Flexcan_Mb) & FLEXCAN_HW_CS_DLC_Msk) >> FLEXCAN_HW_CS_DLC_Pos);
        uint8 can_real_payload = Can_Hw_PriComputePayloadSize(flexcan_mb_dlc_value);

        MsgData_32 = (uint32 *)(uint32)(rxFifo->data);
        rxFifo->dataLen = can_real_payload;
        rxFifo->cs = *Flexcan_Mb;

        if ((rxFifo->cs & FLEXCAN_HW_CS_IDE_Msk) != 0U)
        {
            rxFifo->msgId = *Flexcan_Mb_Id;
        }
        else
        {
            rxFifo->msgId = (*Flexcan_Mb_Id) >> FLEXCAN_HW_ID_STD_Pos;
        }

        if ((rxFifo->cs & FLEXCAN_HW_CS_RTR_Msk) != 0U)
        {
            can_real_payload = 0U;
        }
        else
        {

        }

        Idhit_Offset = (can_real_payload >> 2U) + (((can_real_payload % 4U) != 0U) ? 1U : 0U);

        /* Extract the IDHIT */
        rxFifo->id_hit = (uint8)(((Flexcan_Mb_Data_32[Idhit_Offset]) & FLEXCAN_HW_ENHANCED_IDHIT_Msk) >> FLEXCAN_HW_ENHANCED_IDHIT_Pos);

        rxFifo->time_stamp = (uint32)((rxFifo->cs & FLEXCAN_HW_CS_TIME_STAMP_Msk) >> FLEXCAN_HW_CS_TIME_STAMP_Pos);

        /* Copy EnhancedRxFIFO data field into user's buffer */
        for (DataByte = 0U; DataByte < can_real_payload; DataByte += 4U)
        {
            MbWord = Flexcan_Mb_Data_32[DataByte >> 2U];
            FLEXCAN_HW_SWAP_BYTES_IN_WORD((MbWord), (MsgData_32[DataByte >> 2U]));
        }
    }
    else
    {

    }

    return TTRetVal;
}
#endif /* FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO */

/**
* @brief        Check If mb index is out of range or not
* @details      Check If mb index is out of range or not
* @param[in]    pBase - The FlexCAN base address
* @param[in]    u8MbIndex - MB index
* @param[in]    bIsLegacyFifoEn - Legacy fifo enabled or not
* @param[in]    u32MaxMbNum - Max mb number
* @return       boolean
* @retval       Ture - within the limits of
*               False - out of range
*/
LOCAL_INLINE boolean Can_Hw_PriIsMbOutOfRange
(
    TT_CONST TT_CAN_Type * pBase,
    uint8 u8MbIndex,
    boolean bIsLegacyFifoEn,
    uint32 u32MaxMbNum
)
{
    boolean ReturnValue = FALSE;
    uint32 u32NumOfFiFoElement = 0U;
    uint32 u32NumOfMbOccupiedByFiFo = 0U;

    if (u8MbIndex >= (uint8)u32MaxMbNum)
    {
       ReturnValue = TRUE;
    }
    /* Check if RX FIFO is enabled*/
    else if (TRUE == bIsLegacyFifoEn)
    {
        /* Get the number of RX FIFO Filters*/
        u32NumOfFiFoElement = (((pBase->FLEXCAN_CTRL2) & TT_CAN_FLEXCAN_CTRL2_RFFN_Msk) >> TT_CAN_FLEXCAN_CTRL2_RFFN_Pos);
        /* Get the number if MBs occupied by RX FIFO and ID filter table*/
        /* the Rx FIFO occupies the memory space originally reserved for MB0-5*/
        /* Every number of RFFN means 8 number of RX FIFO filters*/
        /* and every 4 number of RX FIFO filters occupied one MB*/
        u32NumOfMbOccupiedByFiFo = 5U + ((((u32NumOfFiFoElement) + 1U) * 8U) / 4U);
        if (u8MbIndex <= u32NumOfMbOccupiedByFiFo)
        {
            ReturnValue = TRUE;
        }
        else
        {

        }
    }
    else
    {
        ReturnValue = FALSE;
    }

    return ReturnValue;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
* @brief        Enable Enhanced Rx FIFO feature
* @details      Enable Enhanced Rx FIFO feature
* @param[in]    base - The FlexCAN base address
* @param[in]    numOfStdIDFilters - num Of Std ID Filters
* @param[in]    numOfExtIDFilters - num Of Ext ID Filters
* @param[in]    numOfWatermark - num Of Watermark
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriEnableEnhancedRxFifo(TT_CAN_Type * base,
                                                   uint32 numOfStdIDFilters,
                                                   uint32 numOfExtIDFilters,
                                                   uint32 numOfWatermark)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint32 NumOfEnhancedFilters = 0U;

        /* NumOfEnhancedFilters equals (numOfStdIDFilters/2) + numOfExtIDFilters - 1u */
        NumOfEnhancedFilters = (numOfStdIDFilters >> 1u) + numOfExtIDFilters - 1u;

        if ((0U == numOfStdIDFilters) && (0U == numOfExtIDFilters))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }
        /* If the no of Std Filters is odd */
        if (1U == (numOfStdIDFilters & 1U))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }
        /*Enhanced RX FIFO and Legacy RX FIFO cannot be enabled at the same time.*/
        if (TT_CAN_FLEXCAN_MCR_RFEN_Msk == (base->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_RFEN_Msk))
        {
            TTRetVal = TT_RET_STATUS_ERR;
        }
        else
        {

        }

        if(TT_RET_SUCCESS == TTRetVal)
        {
            /* Enable Enhanced Rx FIFO */
            base->FLEXCAN_ERFCR = (base->FLEXCAN_ERFCR & ~TT_CAN_FLEXCAN_ERFCR_ERFEN_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_ERFCR_ERFEN, 1U);
            /* Reset Enhanced Rx FIFO engine */
            base->FLEXCAN_ERFSR = (base->FLEXCAN_ERFSR & ~TT_CAN_FLEXCAN_ERFSR_ERFCLR_Msk) | TT_VAL2FLD(TT_CAN_FLEXCAN_ERFSR_ERFCLR, 1U);
            /* Clear the status bits of the Enhanced RX FIFO */
            base->FLEXCAN_ERFSR = base->FLEXCAN_ERFSR & ~(TT_CAN_FLEXCAN_ERFSR_ERFUFW_Msk | TT_CAN_FLEXCAN_ERFSR_ERFOVF_Msk | TT_CAN_FLEXCAN_ERFSR_ERFWMI_Msk | TT_CAN_FLEXCAN_ERFSR_ERFDA_Msk);
            /* Set the total number of enhanced Rx FIFO filter elements */
            base->FLEXCAN_ERFCR = (base->FLEXCAN_ERFCR & ~TT_CAN_FLEXCAN_ERFCR_NFE_Msk) | ((NumOfEnhancedFilters << TT_CAN_FLEXCAN_ERFCR_NFE_Pos) & TT_CAN_FLEXCAN_ERFCR_NFE_Msk);
            /* Set the number of extended ID filter elements */
            base->FLEXCAN_ERFCR = (base->FLEXCAN_ERFCR & ~TT_CAN_FLEXCAN_ERFCR_NEXIF_Msk) | ((numOfExtIDFilters << TT_CAN_FLEXCAN_ERFCR_NEXIF_Pos) & TT_CAN_FLEXCAN_ERFCR_NEXIF_Msk);
            /* Set the Enhanced Rx FIFO watermark */
            base->FLEXCAN_ERFCR = (base->FLEXCAN_ERFCR & ~TT_CAN_FLEXCAN_ERFCR_ERFWM_Msk) | ((numOfWatermark << TT_CAN_FLEXCAN_ERFCR_ERFWM_Pos) & TT_CAN_FLEXCAN_ERFCR_ERFWM_Msk);
        }
        else
        {

        }

    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Configure Enhanced RX FIFO ID filter table elements
* @details      Configure Enhanced RX FIFO ID filter table elements
* @param[in]    base - The FlexCAN base address
* @param[in]    idFilterTable - id Filter Table
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriSetEnhancedRxFifoFilter(TT_CAN_Type * base, TT_CONST Flexcan_Hw_EnhancedIdTableType * idFilterTable)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == base) || (NULL_PTR == idFilterTable)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* Set Enhanced RX FIFO ID filter table elements*/
        uint32 i, j, n, NumOfEnhancedFilter, NumOfExtIDFilter, NumOfStdIDFilter;
        uint32 Val2 = 0U, Val1 = 0U, Val = 0U;

        volatile uint32 * FilterExtIDTable = NULL_PTR;
        volatile uint32 * FilterStdIDTable = NULL_PTR;

        NumOfEnhancedFilter = (((base->FLEXCAN_ERFCR) & TT_CAN_FLEXCAN_ERFCR_NFE_Msk) >> TT_CAN_FLEXCAN_ERFCR_NFE_Pos);
        NumOfExtIDFilter = (((base->FLEXCAN_ERFCR) & TT_CAN_FLEXCAN_ERFCR_NEXIF_Msk) >> TT_CAN_FLEXCAN_ERFCR_NEXIF_Pos);
        NumOfStdIDFilter = 2U * (NumOfEnhancedFilter - NumOfExtIDFilter + 1U);
        FilterExtIDTable = (volatile uint32 *)&base->FLEXCAN_ERFFEL[FLEXCAN_HW_ENHANCED_RX_FIFO_FILTER_TABLE_BASE];
        FilterStdIDTable = (volatile uint32 *)&base->FLEXCAN_ERFFEL[NumOfExtIDFilter * 2U];
        j = 0U;
        n = 0U;
        for (i = 0U; i < (NumOfExtIDFilter + NumOfStdIDFilter); i++)
        {
            if (!(idFilterTable[i].isExtendedFrame))
            {
                Val = 0U;
                if (idFilterTable[i].rtr2)
                {
                    Val = FLEXCAN_HW_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_RTR2_Pos;
                }
                else
                {

                }

                if (idFilterTable[i].rtr1)
                {
                    Val |= FLEXCAN_HW_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_RTR1_Pos;
                }
                else
                {

                }

                FilterStdIDTable[j] =
                        ((idFilterTable[i].id2 & FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_Msk) << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_Pos2) |
                        ((idFilterTable[i].id1 & FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_Msk) << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_STD_Pos1) | Val;
                switch (idFilterTable[i].filterType)
                {
                case FLEXCAN_HW_ENHANCED_RX_FIFO_ONE_ID_FILTER :
                    FilterStdIDTable[j] |= (uint32)FLEXCAN_HW_ENHANCED_RX_FIFO_ONE_ID_FILTER << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_FSCH_Pos;
                    break;
                case FLEXCAN_HW_ENHANCED_RX_FIFO_RANGE_ID_FILTER :
                    FilterStdIDTable[j] |= (uint32)FLEXCAN_HW_ENHANCED_RX_FIFO_RANGE_ID_FILTER << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_FSCH_Pos;
                    break;
                case FLEXCAN_HW_ENHANCED_RX_FIFO_TWO_ID_FILTER :
                    FilterStdIDTable[j] |= (uint32)FLEXCAN_HW_ENHANCED_RX_FIFO_TWO_ID_FILTER << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_FSCH_Pos;
                    break;
                default:
                    /* do nothing */
                    break;
                }
                j++;
            }
            else
            {
                Val2 = 0U;
                Val1 = 0U;
                if (idFilterTable[i].rtr2)
                {
                    Val2 = FLEXCAN_HW_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_RTR_Pos;
                }
                else
                {

                }

                if (idFilterTable[i].rtr1)
                {
                    Val1 = FLEXCAN_HW_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_RTR_Pos;
                }
                else
                {

                }
                FilterExtIDTable[n] = ((idFilterTable[i].id2 & FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_Msk) << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_Pos) | Val2;

                FilterExtIDTable[n + 1U] = ((idFilterTable[i].id1 & FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_Msk) << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_EXT_Pos) | Val1;
                switch (idFilterTable[i].filterType)
                {
                case FLEXCAN_HW_ENHANCED_RX_FIFO_ONE_ID_FILTER :
                    FilterExtIDTable[n] |= (uint32)FLEXCAN_HW_ENHANCED_RX_FIFO_ONE_ID_FILTER << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_FSCH_Pos;
                    break;
                case FLEXCAN_HW_ENHANCED_RX_FIFO_RANGE_ID_FILTER :
                    FilterExtIDTable[n] |= (uint32)FLEXCAN_HW_ENHANCED_RX_FIFO_RANGE_ID_FILTER << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_FSCH_Pos;
                    break;
                case FLEXCAN_HW_ENHANCED_RX_FIFO_TWO_ID_FILTER :
                    FilterExtIDTable[n] |= (uint32)FLEXCAN_HW_ENHANCED_RX_FIFO_TWO_ID_FILTER << FLEXCAN_HW_ENHANCED_RX_FIFO_ID_FILTER_FSCH_Pos;
                    break;
                default:
                    /* do nothing */
                    break;
                }
                n = n + 2U;
            }
        }
    }
    else
    {

    }

    return TTRetVal;
}

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
* @brief        Clear Enhance fifo data
* @details      Clear Enhance fifo data
* @param[in]    base - The FlexCAN base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriClearOutputEnhanceFIFO(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        volatile TT_CONST uint32 *TT_CONST Ram = (uint32 *)((uint32)base);
        TT_CONST uint32 LastWord_Offset = ((uint32)0x204C) / ((uint32)4U); /* fixed, because DMALW is always = 19 */

        /* If Enhanced Rx FIFO has Pending Request that generated error,
         * the EnhancedRxFIFO need to be empty to activate DMA */
        if ((uint8)1U == FlexCAN_GetEnhancedRxFIFOStatusFlag(base, FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE))
        {
            /* Enter CAN in freeze Mode to allow Enhanced Rx FIFO Clear */
            TTRetVal = Can_Hw_PriEnterFreezeMode(base);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                FlexCAN_ClearEnhancedFIFO(base);

                do
                {
                    if ((uint32)TT_CAN_FLEXCAN_MCR_DMA_Msk == (base->FLEXCAN_MCR & ((uint32)TT_CAN_FLEXCAN_MCR_DMA_Msk)))
                    {
                        /* Read Enhanced Output to clear DMA pending request */
                        (void)Ram[LastWord_Offset];
                    }
                    else
                    {
                        FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE);
                    }
                }
                while (1U == FlexCAN_GetEnhancedRxFIFOStatusFlag(base, FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE)); /* avoid blocking */

                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_HW_ENHANCED_RXFIFO_OVERFLOW);
                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_HW_ENHANCED_RXFIFO_WATERMARK);
                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_HW_ENHANCED_RXFIFO_FRAME_AVAILABLE);
                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_HW_ENHANCED_RXFIFO_UNDERFLOW);

                /* Return CAN to normal Mode */
                TTRetVal = Can_Hw_PriExitFreezeMode(base);
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}
#endif /* (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON) */

#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"

#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
* @brief        Clear Legacy fifo data
* @details      Clear Legacy fifo data
* @param[in]    base - The FlexCAN base address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriClearOutputLegacyFIFO(TT_CAN_Type * base)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == base), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        volatile TT_CONST uint32 *TT_CONST Ram = (uint32 *)((uint32)base);
        TT_CONST uint32 LastWord_Offset = ((uint32)0x8C) / ((uint32)4U); /* fixed, dma last word */

        /* Check if FIFO has Pending Request that generated error,
         * the RxFIFO need to be empty to activate DMA */
        if ((uint8)1U == FlexCAN_GetBuffStatusFlag(base, FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE))
        {
            /* Enter CAN in freeze Mode to allow FIFO Clear */
            TTRetVal = Can_Hw_PriEnterFreezeMode(base);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                FlexCAN_ClearFIFO(base);
                if ((uint32)TT_CAN_FLEXCAN_MCR_DMA_Msk == (base->FLEXCAN_MCR & ((uint32)TT_CAN_FLEXCAN_MCR_DMA_Msk)))
                {
                    do
                    {
                        /* Read Offset 0x8C to clear DMA pending request */
                        (void)Ram[LastWord_Offset];
                    }
                    while (1U == FlexCAN_GetBuffStatusFlag(base, FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE)); /* avoid blocking */
                }
                else
                {

                }

                FlexCAN_ClearMsgBuffIntStatusFlag(base, FLEXCAN_HW_LEGACY_RXFIFO_FRAME_AVAILABLE);
                FlexCAN_ClearMsgBuffIntStatusFlag(base, FLEXCAN_HW_LEGACY_RXFIFO_WARNING);
                FlexCAN_ClearMsgBuffIntStatusFlag(base, FLEXCAN_HW_LEGACY_RXFIFO_OVERFLOW);

                /* Return CAN to normal Mode */
                TTRetVal = Can_Hw_PriExitFreezeMode(base);
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}
#endif /* FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE */

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        configure controller depending on options
* @details      configure controller depending on options
* @param[in]    pBase - The FlexCAN base address
* @param[in]    u32Options - Controller Options
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriConfigCtrlOptions(TT_CAN_Type * pBase, uint32 u32Options)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((NULL_PTR == pBase), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if (FLEXCAN_HW_FEATURE_SWITCHINGISOMODE == STD_ON)
        /* If the FD feature is enabled, in order to be ISO-compliant. */
        if ((u32Options & FLEXCAN_HW_ISO_U32) != 0U)
        {
            FlexCAN_SetIsoCan(pBase, TRUE);
        }
        else
        {
            /* This maybe don't have sense if the Deinit returns the state of registers at init values */
            FlexCAN_SetIsoCan(pBase, FALSE);
        }
#endif /*(FLEXCAN_HW_FEATURE_SWITCHINGISOMODE == STD_ON) */
        /* Set Entire Frame Arbitration Field Comparison. */
        if ((u32Options & FLEXCAN_HW_EACEN_U32) != 0U)
        {
            FlexCAN_SetEntireFrameArbitrationFieldComparison(pBase, TRUE);
        }
        else
        {
            FlexCAN_SetEntireFrameArbitrationFieldComparison(pBase, FALSE);
        }
#if (FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION == STD_ON)
        /* Set protocol Exception */
        if ((u32Options & FLEXCAN_HW_PROTOCOL_EXCEPTION_U32) != 0U)
        {
            FlexCAN_SetProtocolException(pBase, TRUE);
        }
        else
        {
            FlexCAN_SetProtocolException(pBase, FALSE);
        }
#endif /* Endif  (FLEXCAN_HW_FEATURE_PROTOCOLEXCEPTION == STD_ON)  */
        /* Set CAN Bit Sampling */
        if (((u32Options & FLEXCAN_HW_THREE_SAMPLES_U32) != 0U) && (0U == (pBase->FLEXCAN_MCR & TT_CAN_FLEXCAN_MCR_FDEN_Msk)))
        {
            FlexCAN_CanBitSampling(pBase, TRUE);
        }
        else
        {
            FlexCAN_CanBitSampling(pBase, FALSE);
        }

        /* Set AutoBusOff Recovery */
        if ((u32Options & FLEXCAN_HW_BUSOFF_RECOVERY_U32) != 0U)
        {
            FlexCAN_SetBusOffAutorecovery(pBase, TRUE);
        }
        else
        {
            FlexCAN_SetBusOffAutorecovery(pBase, FALSE);
        }
        /* Set Remote Request Store for received of Remote Request Frames */
        if ((u32Options & FLEXCAN_HW_REM_STORE_U32) != 0U)
        {
            FlexCAN_SetRemoteReqStore(pBase, TRUE);
        }
        else
        {
            FlexCAN_SetRemoteReqStore(pBase, FALSE);
        }
#if (FLEXCAN_HW_FEATURE_EDGEFILTER == STD_ON)
        /* Set Edge Filter */
        if ((u32Options & FLEXCAN_HW_EDGE_FILTER_U32) != 0U)
        {
            FlexCAN_SetEdgeFilter(pBase, TRUE);
        }
        else
        {
            FlexCAN_SetEdgeFilter(pBase, FALSE);
        }
#endif /* End of (FLEXCAN_HW_FEATURE_EDGEFILTER == STD_ON)  */
    }
    else
    {

    }

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/**
* @brief        Configures the Pretended Networking mode
* @details      Configures the Pretended Networking mode
* @param[in]    pBase - The FlexCAN base address
* @param[in]    pnConfig - The pretended networking configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriConfigPN(TT_CAN_Type * pBase,
                      TT_CONST Flexcan_Hw_PnConfigType * pPnConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck(((NULL_PTR == pBase) || (NULL_PTR == pPnConfig)), TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* Configure specific pretended networking settings */
        FlexCAN_SetPNFilteringSelection(pBase, pPnConfig);

        FlexCAN_SetPNTimeoutValue(pBase, pPnConfig->u16MatchTimeout);

        /* Configure ID filtering */
        FlexCAN_SetPNIdFilter1(pBase, pPnConfig->idFilter1);

        /* Configure the second ID, if needed (as mask for exact matching or higher limit for range matching) */
        if ((FLEXCAN_FILTER_MATCH_EXACT == pPnConfig->eIdFilterType) || (FLEXCAN_FILTER_MATCH_RANGE == pPnConfig->eIdFilterType))
        {
            FlexCAN_SetPNIdFilter2(pBase, pPnConfig);
        }
        else
        {
            /* In other case need only to check the IDE and RTR match the ID_Msk is not considered */
            FlexCAN_SetPNIdFilter2Check(pBase);
        }

        /* Configure payload filtering, if requested */
        if ((FLEXCAN_FILTER_ID_PAYLOAD == pPnConfig->eFilterComb) || (FLEXCAN_FILTER_ID_PAYLOAD_NTIMES == pPnConfig->eFilterComb))
        {
            FlexCAN_SetPNDlcFilter(pBase, pPnConfig->payloadFilter.u8DlcLow, pPnConfig->payloadFilter.u8DlcHigh);

            FlexCAN_SetPNPayloadHighFilter1(pBase, pPnConfig->payloadFilter.aPayload1);
            FlexCAN_SetPNPayloadLowFilter1(pBase, pPnConfig->payloadFilter.aPayload1);

            /* Configure the second payload, if needed (as mask for exact matching or higher limit for range matching) */
            if ((FLEXCAN_FILTER_MATCH_EXACT == pPnConfig->ePayloadFilterType) || (FLEXCAN_FILTER_MATCH_RANGE == pPnConfig->ePayloadFilterType))
            {
                FlexCAN_SetPNPayloadHighFilter2(pBase, pPnConfig->payloadFilter.aPayload2);
                FlexCAN_SetPNPayloadLowFilter2(pBase, pPnConfig->payloadFilter.aPayload2);
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }

    return TTRetVal;
}

#endif /* FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING */

/**
* @brief        Reset Imask Buffers
* @details      Reset Imask Buffers
* @param[in]    Instance - The CAN instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Hw_PriResetImaskBuff(uint8 Instance)
{

    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_ParaCheck((Instance >= FLEXCAN_INSTANCE_COUNT), TT_RET_PARAM_CHANNEL_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        uint8 ImaskCnt = 0U;

        for (ImaskCnt = 0U; ImaskCnt < FLEXCAN_HW_FEATURE_MBDSR_COUNT; ImaskCnt++)
        {
            FlexCAN_Hw_au32ImaskBuff[Instance][ImaskCnt] = 0U;
        }
    }
    else
    {

    }
    return TTRetVal;
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif
