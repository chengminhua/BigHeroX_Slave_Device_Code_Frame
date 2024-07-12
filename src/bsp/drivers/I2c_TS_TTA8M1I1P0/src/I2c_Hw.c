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
**  FILENAME     : I2c_Hw.c                                                         **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : I2C Driver Source File                                           **
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
#include "I2c_Hw.h"
#include "Mcu_Drv.h"
#include "Base_Drv.h"
#if (I2C_DMA_ENABLE == STD_ON)
#include "Dma_Drv.h"
#endif

/**************************************************************************************************
*                                 Source File Version Information
***************************************************************************************************/
#define I2C_HW_VENDOR_ID_C                      1541
#define I2C_HW_MODULE_ID_C                      222
#define I2C_HW_AR_RELEASE_MAJOR_VERSION_C       4
#define I2C_HW_AR_RELEASE_MINOR_VERSION_C       4
#define I2C_HW_AR_RELEASE_PATCH_VERSION_C       0
#define I2C_HW_SW_MAJOR_VERSION_C               1
#define I2C_HW_SW_MINOR_VERSION_C               1
#define I2C_HW_SW_PATCH_VERSION_C               0

/*******************************************************************************
**                        File Version Checks
*******************************************************************************/
/* I2c_Hw.h I2c_HW.c file version check */
#if (I2C_HW_VENDOR_ID_H != I2C_HW_VENDOR_ID_C)
#error "I2c_Hw.h and I2c_Hw.c have different vendor id"
#endif
#if (I2C_HW_MODULE_ID_H != I2C_HW_MODULE_ID_C)
#error "I2c_Hw.h and I2c_Hw.c have different module id"
#endif
#if ((I2C_HW_AR_RELEASE_MAJOR_VERSION_H != I2C_HW_AR_RELEASE_MAJOR_VERSION_C) || \
    (I2C_HW_AR_RELEASE_MINOR_VERSION_H != I2C_HW_AR_RELEASE_MINOR_VERSION_C) || \
    (I2C_HW_AR_RELEASE_PATCH_VERSION_H != I2C_HW_AR_RELEASE_PATCH_VERSION_C))
#error "AutoSar Version Numbers of I2c_Hw.h and I2c_Hw.c are different"
#endif
#if ((I2C_HW_SW_MAJOR_VERSION_H != I2C_HW_SW_MAJOR_VERSION_C) || \
    (I2C_HW_SW_MINOR_VERSION_H != I2C_HW_SW_MINOR_VERSION_C) || \
    (I2C_HW_SW_PATCH_VERSION_H != I2C_HW_SW_PATCH_VERSION_C))
#error "Software Version Numbers of I2c_Hw.h and I2c_Hw.c are different"
#endif

#if (I2C_DMA_ENABLE == STD_ON)
    /* Dma_Drv.h I2c_HW.c file version check */
    #if (I2C_HW_VENDOR_ID_C != DMA_DRV_VENDOR_ID_H)
    #error "Dma_Drv.h and I2c_Hw.c have different vendor id"
    #endif
    #if ((I2C_HW_AR_RELEASE_MAJOR_VERSION_C != DMA_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
        (I2C_HW_AR_RELEASE_MINOR_VERSION_C != DMA_DRV_AR_RELEASE_MINOR_VERSION_H) || \
        (I2C_HW_AR_RELEASE_PATCH_VERSION_C != DMA_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Drv.h and I2c_Hw.c are different"
    #endif
    #if ((I2C_HW_SW_MAJOR_VERSION_C != DMA_DRV_SW_MAJOR_VERSION_H) || \
        (I2C_HW_SW_MINOR_VERSION_C != DMA_DRV_SW_MINOR_VERSION_H) || \
        (I2C_HW_SW_PATCH_VERSION_C != DMA_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Drv.h and I2c_Hw.c are different"
    #endif
#endif

/* Mcu_Drv.h I2c_HW.c file version check */
#if (I2C_HW_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
#error "Mcu_Drv.h and I2c_Hw.c have different vendor id"
#endif
#if ((I2C_HW_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
    (I2C_HW_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
    (I2C_HW_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
#error "AutoSar Version Numbers of Mcu_Drv.h and I2c_Hw.c are different"
#endif
#if ((I2C_HW_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
    (I2C_HW_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
    (I2C_HW_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
#error "Software Version Numbers of Mcu_Drv.h and I2c_Hw.c are different"
#endif

/* Base_Drv.h I2c_HW.c file version check */
#if (I2C_HW_VENDOR_ID_C != BASE_DRV_VENDOR_ID_H)
#error "Base_Drv.h and I2c_Hw.c have different vendor id"
#endif
#if ((I2C_HW_AR_RELEASE_MAJOR_VERSION_C != BASE_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
    (I2C_HW_AR_RELEASE_MINOR_VERSION_C != BASE_DRV_AR_RELEASE_MINOR_VERSION_H) || \
    (I2C_HW_AR_RELEASE_PATCH_VERSION_C != BASE_DRV_AR_RELEASE_PATCH_VERSION_H))
#error "AutoSar Version Numbers of Base_Drv.h and I2c_Hw.c are different"
#endif
#if ((I2C_HW_SW_MAJOR_VERSION_C != BASE_DRV_SW_MAJOR_VERSION_H) || \
    (I2C_HW_SW_MINOR_VERSION_C != BASE_DRV_SW_MINOR_VERSION_H) || \
    (I2C_HW_SW_PATCH_VERSION_C != BASE_DRV_SW_PATCH_VERSION_H))
#error "Software Version Numbers of Base_Drv.h and I2c_Hw.c are different"
#endif

/******************************************************************************
*                     Private Function Declaration
*******************************************************************************/
/**
 * @brief      :  Map I2c_PubMap to I2c_Hw_PbResources
 * @details    :  The subscript of the I2c_PubMap array indicates the corresponding I2c0 to I2c1,
 *                and the member value of the I2c_PubMap array is the array subscript of I2c_Hw_PbResources.
 *                Uart_Hw_PbResources[Uart_Map[Uart_0]] Indirectly accesses hardware resources corresponding to the serial port
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Map command accepted
 *             :  Other: Map command not accepted
 *
 **/
static TT_RetType I2c_Hw_PriMapsort(TT_CONST I2c_ConfigType* CfgPtr);

/**
* @brief      :  Set speed-related configurations
* @details    :  Set speed-related configurations
* @param[in]  :  HwUnit :Select an I2C module
*                I2c_ChannelMode : I2c Indicates the Master/slaver mode
*                I2C_Speed ：I2c Speed mode
* @param[out] :  None
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Mode setting succeeded
*             :  Other: Failed to set the mode
*
**/
static TT_RetType I2c_Hw_PriSetMode(uint8  HwUnit,I2c_WorkChannelType I2c_ChannelMode,I2c_SpeedType I2C_Speed);
/**
* @brief      :  Start the clock and obtain the corresponding clock frequency.
* @details    :  Initializing I2C includes: speed, master/slave mode, address, and so on
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  I2CSysClk :Save clock frequency
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS:  Starting and obtaining the clock command succeeded. Procedure
*             :  Other: Failure
*
**/
static TT_RetType I2c_Hw_PriClk(uint8 HwUnit,Mcu_PeripheralClockValType* I2CSysClk);

/**
* @brief      :  Service for I2c Slave Poll Transmission.
* @details    :  Service for I2c Slave Poll Transmission.
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
static TT_RetType I2c_Hw_PriSlaveSyncTransmit(uint8 HwUnit);

/**
* @brief      :  I2c_Hw_PriMclearIntrHbits .
* @details    :  Read the interrupt status and clear the Hight interrupt flag
* @param[in]  :  HwUnit :Select an I2C module
*                status   :Record the host interrupt status
* @param[out] :  None
* @return     :  uint32
* @retval     :  The return value requires the specific status reference register INTR_STAT
*
**/
static void I2c_Hw_PriMclearIntrHbits(uint8 HwUnit,uint32 status);

/**
* @brief      :  Service for I2C Interrupt .
* @details    :  Read the host interrupt status and clear the low interrupt flag
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  uint32
* @retval     :  The return value requires the specific status reference register INTR_STAT
*
**/
static uint32 I2c_Hw_PriMasterClearIntr(uint8 HwUnit);

/**
* @brief      :  Serves the I2C host interrupt function.
* @details    :  Host interrupt processing function, processing
*                host receiving and sending data
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  uint32
* @retval     :  Return the status of the I2C
*
**/
static uint32 I2c_Hw_PriMasterHandler(uint8  HwUnit);
/**
* @brief      :  Service for I2C slave Interrupt .
* @details    :  Read the Slaver interrupt status and clear the hight interrupt flag
* @param[in]  :  HwUnit :Select an I2C module
*                status   ：Records the interrupt status of the slave
* @param[out] :  None
* @return     :  uint32
* @retval     :  The return value requires the specific status reference register INTR_STAT
*
**/
static void I2c_Hw_PriSclearIntrHbits(uint8 HwUnit,uint32 status);

/**
* @brief      :  Service for I2C slave Interrupt .
* @details    :  Read the Slaver interrupt status and clear the hight interrupt flag
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  uint32
* @retval     :  The return value requires the specific status reference register INTR_STAT
*
**/
static uint32 I2c_Hw_PriSlaveClearIntr(uint8 HwUnit);
/**
* @brief      :  Serves the I2C Slave interrupt function.
* @details    :  The slave interrupts processing functions that
*                process data received and sent from the slave
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  uint32
* @retval     :  Return the status of the I2C
*
**/
static uint32 I2c_Hw_PriSlaveHandler(uint8  HwUnit);

#if defined(I2C0_DMA_ENABLE) || defined(I2C1_DMA_ENABLE)
/**
 * @brief      : I2c sends DMA mode event callback result function.
 * @details    : I2c sends DMA mode event callback result function.
 * @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
 *               event - DMA_EVENT_TERMINAL_COUNT_REQUEST / Other
 * @param[out] : None
 * @return     : void
 * @retval     : None
 *
 **/
static void I2c_Hw_PriDmaTxEvent(uint8 HwUnit, uint32 event);
/**
 * @brief      : I2c receive DMA mode event callback result function.
 * @details    : I2c receive DMA mode event callback result function.
 * @param[in]  : HwUnit - Module ID of the Hardware unit to receive
 *               event - GPDMA_EVENT_TERMINAL_COUNT_REQUEST / Other
 * @param[out] : None
 * @return     : void
 * @retval     : None
 *
 **/
static void I2c_Hw_PriDmaRxEvent(uint8 HwUnit, uint32 event);
#ifdef I2C0_DMA_ENABLE
/**
 * @brief      : I2c0 send DMA handler function.
 * @details    : I2c0 send DMA handler function.
 * @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] : None
 * @return     : void
 * @retval     : None
 *
 **/
void I2c_Hw_PriDmaTx0(uint32 event);
/**
 * @brief      : I2c0 receive DMA handler function
 * @details    : I2c0 receive DMA handler function
 * @param[in]  : HwUnit - Module ID of the Hardware unit to receive
 * @param[out] : None
 * @return     : void
 * @retval     : None
 *
 **/
void I2c_Hw_PriDmaRx0(uint32 event);
#endif
#ifdef I2C1_DMA_ENABLE
void I2c_Hw_PriDmaTx1(uint32 event);
void I2c_Hw_PriDmaRx1(uint32 event);
#endif
#endif
/**
* @brief      :  Serves the I2C interrupt function.
* @details    :  Determine whether the interrupt is from the machine or the host,
*                and call the callback function to set the status value to.
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  void
* @retval     :  void
*
**/
static void I2c_Hw_PriIrqHandler(uint8 HwUnit);
#ifdef A8V2E
/**
* @brief      :  I2c_Hw_PriUnlockDeadlock.
* @details    :  Remove the host deadlock condition
* @param[in]  :  HwUnit :Select an I2C module
* 				 status :Interrupt send message
* @param[out] :  None
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
static uint32 I2c_Hw_PriUnlockDeadlock(uint8  HwUnit,uint32 status);
#endif
/**
* @brief      :  I2c_Hw_PriSyncSlaReceive
* @details    :  I2c receives processing functions from the slave
*
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
*
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: Complete data received successfully
*             :  Other: Failed to receive completion data
*
**/
static TT_RetType I2c_Hw_PriSyncSlaReceive(TT_CONST uint8 HwUnit);


/******************************************************************************
*                    Private variable
******************************************************************************/

#define I2C_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"
/**
* @brief      :  I2C Control Information
* @details       Refer to the comments in the structure for details
*
*/
#ifdef I2C0_CONFIGED
static I2c_CtrlType I2C0_Info = {
                                 .cb_event = NULL_PTR,
                                 .status   = TT_I2C_STATE_UNINIT,
                                 .addr     = 0,
                                 .cnt      = 0,
                                 .nack     = 0,
                                 .data     =NULL_PTR,
                                 .num      = 0,
                                 .ncnt     = 0,
                                 .sdata    = NULL_PTR,
                                 .snum     = 0
                                };
#endif

#ifdef I2C1_CONFIGED
static I2c_CtrlType I2C1_Info = {
                                .cb_event = NULL_PTR,
                                .status   = TT_I2C_STATE_UNINIT,
                                .addr     = 0,
                                .cnt      = 0,
                                .nack     = 0,
                                .data     =NULL_PTR,
                                .num      = 0,
                                .ncnt     = 0,
                                .sdata    = NULL_PTR,
                                .snum     = 0
                                };
#endif

#define I2C_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "I2c_MemMap.h"

#ifdef I2C0_DMA_ENABLE
/**
* @brief         I2C DMATX Configuration
* @details       Refer to the comments in the structure for details
*/
static I2c_DmaType I2C0_DmaTx = {
                                .I2cDmaConfigId = 0,
                                .cb_event = I2c_Hw_PriDmaTx0
                                };
/**
* @brief         I2C DMARx Configuration
* @details       Refer to the comments in the structure for details
*/
static I2c_DmaType I2C0_DmaRx = {
                                .I2cDmaConfigId = 0,
                                .cb_event = I2c_Hw_PriDmaRx0
                                };
#endif

#ifdef I2C1_DMA_ENABLE
static I2c_DmaType I2C1_DmaTx = {
                                .I2cDmaConfigId = 0,
                                .cb_event = I2c_Hw_PriDmaTx1
                                };
static I2c_DmaType I2C1_DmaRx = {
                                .I2cDmaConfigId = 0,
                                .cb_event = I2c_Hw_PriDmaRx1
                                };
#endif

/**
* @brief      :  I2c_PubMap serves I2C_PubResources
* @details       Hardware resources and running status of the I2c
*
*/
static I2C_ResourcesType I2C_PubResources[I2C_CONFIGED_COUNT] =
{
#ifdef I2C0_CONFIGED
    {
    /* I2C register base */
    .reg = IP_I2C0,
    /* Run-Time Information */
    .ctrl = &I2C0_Info,
    .work_mode = TT_I2C_WORK_POLL,
#if(I2C_DMA_ENABLE ==STD_ON)
#ifdef I2C0_DMA_ENABLE
    .dma_tx = &I2C0_DmaTx,
    .dma_rx = &I2C0_DmaRx,
#else
    .dma_tx = NULL_PTR,
    .dma_rx = NULL_PTR,
#endif
#endif
    .base_clk = 0
    }
#endif
#ifdef I2C1_CONFIGED
#if defined(I2C0_CONFIGED)
,
#endif
    {
    /* I2C register base */
    .reg = IP_I2C1,
    /* Run-Time Information */
    .ctrl = &I2C1_Info,
    .work_mode = TT_I2C_WORK_POLL,
#if(I2C_DMA_ENABLE ==STD_ON)
#ifdef I2C1_DMA_ENABLE
    .dma_tx = &I2C1_DmaTx,
    .dma_rx = &I2C1_DmaRx,
#else
    .dma_tx = NULL_PTR,
    .dma_rx = NULL_PTR,
#endif
#endif
    .base_clk = 0
    }
#endif
};

#define I2C_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_FAST_INIT_8
#include "I2c_MemMap.h"
/**
* @brief      :  I2c_PubMap serves I2C_PubResources
* @details       Array subscripts correspond to I2c0 to I2c1.
*                Array members in I2c_PubMap are used to map I2c
*                hardware resources in I2C_PubResources
*
*/
static uint8 I2c_PubMap[I2C_CONTROLLER_COUNT] = {0xFF,0xFF};

#define I2C_STOP_SEC_VAR_FAST_INIT_8
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_SLOW_INIT_8
#include "I2c_MemMap.h"
/**
* @brief      :  Is used for I2c to turn the clock on and off
* @details       Enumeration values corresponding to I2c off clock and on clock
*
*/
static TT_CONST TT_SCU_CLK_CONTROL_Type I2c_PubStartClk[I2C_CONTROLLER_COUNT] = {TT_SCU_CLK_CONTROL_I2C0,TT_SCU_CLK_CONTROL_I2C1};

/**
* @brief      :  Used for I2c to get the clock
* @details       Used to store the enumeration value
*                corresponding to the I2c fetch clock
*
*/
static TT_CONST Mcu_Hw_PeriphNameType I2c_PubGetClk[I2C_CONTROLLER_COUNT] = {MCU_CLOCK_I2C0,MCU_CLOCK_I2C1};

#define I2C_STOP_SEC_VAR_SLOW_INIT_8
#include "I2c_MemMap.h"

/******************************************************************************
*                         Public Functions                                    *
******************************************************************************/
#define I2C_START_SEC_CODE_SLOW
#include "I2c_MemMap.h"
/**
* @brief      :  Initializes the I2c Driver module.
* @details    :  Initializing I2C includes: speed, master/slave mode, address, and so on
* @param[in]  :  CfgPtr :Pointer to configuration set
* @param[out] :  None
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
TT_RetType I2c_Hw_Init(TT_CONST I2c_ConfigType* CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 HwUnit = 0;
    uint8 i = 0;
    Mcu_PeripheralClockValType I2CSysClk = 0;

    Ret = I2c_Hw_PriMapsort(CfgPtr);

    if(TT_RET_SUCCESS == Ret)
    {
        for (i = 0; i < I2C_CONFIGED_COUNT; i++)
        {
            HwUnit = CfgPtr->CtrlCfgPtr[i].HwUnit;

            Ret = I2c_Hw_PriClk(HwUnit,&I2CSysClk);

            if ((Ret == TT_RET_SUCCESS) && (I2CSysClk > 0))
            {
                /* soft set status*/
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY;
                I2C_PubResources[I2c_PubMap[HwUnit]].base_clk = I2CSysClk;
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->addr = (uint8)CfgPtr->CtrlCfgPtr[i].Address;
                I2C_PubResources[I2c_PubMap[HwUnit]].work_mode = CfgPtr->CtrlCfgPtr[i].I2C_WorkMode;

                /* Reset all register*/
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0U;
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->RX_TL = 0U;
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->TX_TL = 0U;
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK = 0U;
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->TAR = 0U;
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event = CfgPtr->CtrlCfgPtr[i].cb_event;

    #if (I2C_DMA_ENABLE == STD_ON)
                if (I2C_PubResources[I2c_PubMap[HwUnit]].dma_tx != NULL_PTR)
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].dma_tx->I2cDmaConfigId = CfgPtr->CtrlCfgPtr[i].I2cTxDmaConfigId;
                }
                else
                {
                    /* do nothing */
                }
                if (I2C_PubResources[I2c_PubMap[HwUnit]].dma_rx != NULL_PTR)
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].dma_rx->I2cDmaConfigId = CfgPtr->CtrlCfgPtr[i].I2cRxDmaConfigId;
                }
                else
                {
                    /* do nothing */
                }
    #endif
                Ret= I2c_Hw_PriSetMode(HwUnit,CfgPtr->CtrlCfgPtr[i].I2C_WorkChannel,CfgPtr->CtrlCfgPtr[i].I2C_Speed);

                if(TT_RET_SUCCESS == Ret)
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
                }
                else
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_UNINIT;
                }
            }
            else
            {
                Ret = TT_RET_STATUS_CLK_ERR;
            }
        }
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
 * @brief      :  Serves initial security checks
 * @details    :  Serves initial security checks
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: The initialization is complete
 *             :  Other: Initialization is error
 *
 **/
TT_RetType I2c_Hw_InitCheck(TT_CONST I2c_ConfigType *CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 HwUnit = 0, i = 0;
    for (i = 0; i < I2C_CONFIGED_COUNT; i++)
    {
        HwUnit = CfgPtr->CtrlCfgPtr[i].HwUnit;
        if((I2c_PubMap[HwUnit] != 0xFFU) && (Ret == TT_RET_SUCCESS))
        {
            switch(CfgPtr->CtrlCfgPtr[i].I2C_WorkChannel)
            {
                case WORK_MODE_SLAVE:
                    Ret = ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->SAR & TT_I2C0_SAR_SAR_Msk) == (uint8)CfgPtr->CtrlCfgPtr[i].Address)?TT_RET_SUCCESS:TT_RET_STATUS_ERR;
                    break;
               default:
                   Ret = ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->TAR & TT_I2C0_TAR_TAR_Msk) == (uint8)CfgPtr->CtrlCfgPtr[i].Address)?TT_RET_SUCCESS:TT_RET_STATUS_ERR;
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
* @brief      :  Service for Deinitialization of I2C.
* @details    :  Check whether I2c is initialized
* @param[in]  :  None
* @param[out] :  None
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
TT_RetType I2c_Hw_DeInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 i = 0;

    for (i = 0; i < I2C_CONTROLLER_COUNT; i++)
    {
        if(0xFFU != I2c_PubMap[i])
        {

            if (I2C_PubResources[I2c_PubMap[i]].ctrl->status == TT_I2C_STATE_IDLE)
            {
                I2C_PubResources[I2c_PubMap[i]].ctrl->status = TT_I2C_STATE_UNINIT;
                I2c_PubMap[i] = 0xFFU;
                switch (i)
                {
                    case 0:
                        (void)Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_I2C0);
                        (void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_I2C0);
                        break;
                    default:
                        (void)Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_I2C1);
                        (void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_I2C1);
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

#define I2C_STOP_SEC_CODE_SLOW
#include "I2c_MemMap.h"

#define I2C_START_SEC_CODE_FAST
#include "I2c_MemMap.h"
/**
* @brief      :  Service for I2c POLL Transmission.
* @details    :  Select which I2C to send a fixed length of data
* @param[in]  :  HwUnit :Select an I2C module
*                Length :Number of bytes which will be read
*                TxBuf : Buffer to store transmit data
* @param[out] :  None
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
TT_RetType I2c_Hw_SyncTransmit(TT_CONST uint8 HwUnit,uint8* TxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Status = 0;

#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    (void) Base_Drv_Timer_MicrosToTicks(I2C_TIMEOUT_DURATION, &uS2Ticks);
#endif

    TT_ParaCheck((HwUnit >= I2C_CONTROLLER_COUNT), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((TxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2c_PubMap[HwUnit] >= I2C_CONTROLLER_COUNT), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status != TT_I2C_STATE_IDLE), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2C_PubResources[I2c_PubMap[HwUnit]].work_mode != TT_I2C_WORK_POLL), TT_RET_STATUS_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
       if (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) != 0UL)
            && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_SLAVE_DISABLE_Msk) != 0UL)) //master mode
        {
            /* Set control variables */
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY_TX;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->data = TxBuf;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num = (uint32)Length;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = 0U;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 1U;

#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
	(void) Base_Drv_Timer_GetCounter(&timeStart);
#endif
            while ((I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt < I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num) ||
                  ((Status & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) == 0))
            {
                Status = I2c_Hw_PriMasterClearIntr(HwUnit);

#ifdef A8V2E
                Ret = I2c_Hw_PriUnlockDeadlock(HwUnit,Status);
                if(Ret != TT_RET_SUCCESS)
                {
                	break;
                }
                else
                {
                	/* do nothing */
                }

#else
                if ((Status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0UL)
                {
                	Ret = TT_RET_IO_TX_ERR;
                	break;
                }
                else
                {
                	/* do nothing */
                }
#endif

                if (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_TFNF_Msk) != 0) &&
                    ((I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt < I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num)))
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD = I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->data[I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt];
                    I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt++;
                }
                else
                {
                	/* do nothing */
                }
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
				(void) Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
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
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
        }
       else if (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) == 0UL)
                  && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_SLAVE_DISABLE_Msk) == 0UL)) //slave mode
		{

		  /* Set control variables */
		  I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY_TX;
		  I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->sdata = TxBuf;
		  I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->snum = Length;
		  I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = 0U;

		  /* Update driver status */
		  I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 1U;
		  Ret = I2c_Hw_PriSlaveSyncTransmit(HwUnit);
		  I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
		  I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
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
* @brief      :  Service for I2c Transmission.
* @details    :  Select which I2C to send a fixed length of data
* @param[in]  :  HwUnit :Select an I2C module
*                Length :Number of bytes which will be read
*                TxBuf : Buffer to store transmit data
* @param[out] :  None
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
TT_RetType I2c_Hw_AsyncTransmit(TT_CONST uint8  HwUnit,uint8* TxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((HwUnit >= I2C_CONTROLLER_COUNT), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((TxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2c_PubMap[HwUnit] >= I2C_CONTROLLER_COUNT), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status != TT_I2C_STATE_IDLE), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2C_PubResources[I2c_PubMap[HwUnit]].work_mode == TT_I2C_WORK_POLL), TT_RET_STATUS_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {

        if (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) != 0UL)
            && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_SLAVE_DISABLE_Msk) != 0UL)) //master mode
        {

            /* Set control variables */
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY_TX;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->data = TxBuf;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num = (uint32)Length;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = 0U;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 1U;

	/*DMA*/
#if (I2C_DMA_ENABLE == STD_ON)
			if ((I2C_PubResources[I2c_PubMap[HwUnit]].work_mode == TT_I2C_WORK_DMA) && (I2C_PubResources[I2c_PubMap[HwUnit]].dma_tx !=NULL_PTR))
			{
				/* Configure DMA channel */
				Ret = Dma_Drv_ChannelConfigure(&DmaChannelConfig[I2C_PubResources[I2c_PubMap[HwUnit]].dma_tx->I2cDmaConfigId],
												Length,
												(uint32)TxBuf,
												(uint32)&I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD,
												I2C_PubResources[I2c_PubMap[HwUnit]].dma_tx->cb_event);
				if (Ret == TT_RET_SUCCESS)
				{
					/* Enable DMA Transmit */
					I2C_PubResources[I2c_PubMap[HwUnit]].reg->DMA_CR |= TT_I2C0_DMA_CR_TDMAE_Msk;
				}
				else
				{
					I2C_PubResources[HwUnit].ctrl->status = TT_I2C_STATE_IDLE;
				}
			}
			else
#endif
			{
				/* Unmask the Tx interrupt */
				I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK |= TT_I2C0_INTR_MASK_M_TX_EMPTY_Msk |
																	   TT_I2C0_INTR_MASK_M_TX_OVER_Msk |
																	   TT_I2C0_INTR_MASK_M_TX_ABRT_Msk;
#ifdef A8V2E
				I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK |=  TT_I2C0_INTR_MASK_M_SCL_STUCK_AT_LOW_Pos;
#endif
			}

        }
        else if (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) == 0UL)
			&& ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_SLAVE_DISABLE_Msk) == 0UL)) //slave mode
		{
			if (I2C_PubResources[I2c_PubMap[HwUnit]].work_mode == TT_I2C_WORK_IRQ)
			{
				/* Set control variables */
				I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY_TX;
				I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->sdata = TxBuf;
				I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->snum = Length;
				I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = 0U;
				I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 1U;

				/* Unmask the corresponding interrupts */
				I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK |= TT_I2C0_INTR_MASK_M_RX_DONE_Msk |
																	TT_I2C0_INTR_MASK_M_RD_REQ_Msk |
																	TT_I2C0_INTR_MASK_M_TX_ABRT_Msk |
																	TT_I2C0_INTR_MASK_M_TX_OVER_Msk;
			}
			else
			{

				Ret = TT_RET_STATUS_ERR;
			}

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
* @brief      :  Service for I2C asynchronous Reception.
* @details    :  Service for I2C asynchronous Reception.
* @param[in]  :  HwUnit :Select an I2C module
*                Length :Number of bytes which will be read
* @param[out] :  RxBuf : Buffer to store receive data
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: Complete data received successfully
*             :  Other: Failed to receive completion data
*
**/
TT_RetType  I2c_Hw_AsyncReceive(TT_CONST uint8  HwUnit, uint8* RxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((HwUnit >= I2C_CONTROLLER_COUNT), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((RxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2c_PubMap[HwUnit] >= I2C_CONTROLLER_COUNT), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status != TT_I2C_STATE_IDLE), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2C_PubResources[I2c_PubMap[HwUnit]].work_mode == TT_I2C_WORK_POLL), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) != 0) && \
    		((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_SLAVE_DISABLE_Msk) == 0)), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) == 0) && \
    		((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_SLAVE_DISABLE_Msk) != 0)), TT_RET_STATUS_ERR, &Ret);


    if(TT_RET_SUCCESS == Ret)
    {
    	/* slave mode */
        if ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) == 0)
        {

            /* Set control variables */
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY_RX;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->sdata = RxBuf;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->snum = Length;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = 0U;

            /* Update driver status */
           I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 1U;

#if(I2C_DMA_ENABLE == STD_ON)
            if ((I2C_PubResources[I2c_PubMap[HwUnit]].work_mode == TT_I2C_WORK_DMA) && (I2C_PubResources[I2c_PubMap[HwUnit]].dma_rx != NULL_PTR))
            {
                /* Configure DMA channel */
                Ret = Dma_Drv_ChannelConfigure(&DmaChannelConfig[I2C_PubResources[I2c_PubMap[HwUnit]].dma_rx->I2cDmaConfigId],
                                                Length,
                                                (uint32)&I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD,
                                                (uint32)RxBuf,
                                                I2C_PubResources[I2c_PubMap[HwUnit]].dma_rx->cb_event);
                if (Ret == TT_RET_SUCCESS)
                {
                    /* Enable DMA Receive */
                    I2C_PubResources[I2c_PubMap[HwUnit]].reg->DMA_CR |= TT_I2C0_DMA_CR_RDMAE_Msk;
                }
                else
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
                }
            }
            else
#endif
            {
                /* Unmask the corresponding interrupt */
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK |= TT_I2C0_INTR_MASK_M_RX_FULL_Msk |
                                                           TT_I2C0_INTR_MASK_M_RX_OVER_Msk |
                                                           TT_I2C0_INTR_MASK_M_RX_UNDER_Msk;

#ifdef A8V2E
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK |= TT_I2C0_INTR_MASK_M_TX_ABRT_Msk;
#endif


            }
        }
        else
        {
        	/* do nothing */
        }
        /* master mode */
		if ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) != 0UL)
        {
            if (I2C_PubResources[I2c_PubMap[HwUnit]].work_mode == TT_I2C_WORK_IRQ)
            {
                /* Set control variables */
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->data = RxBuf;
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num = (uint32)Length;
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = 0U;
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->ncnt = I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num;

                /* Update driver status */
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY_RX;
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 1U;

                /* Send a read request */
                while ((I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->ncnt > 0) && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_TFNF_Msk) != 0))
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD = TT_I2C0_DATA_CMD_CMD_Msk;
                    I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->ncnt--;
                }
                /* Unmask the corresponding interrupts */
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK = TT_I2C0_INTR_MASK_M_RX_FULL_Msk |
                                                                      TT_I2C0_INTR_MASK_M_RX_OVER_Msk |
                                                                      TT_I2C0_INTR_MASK_M_TX_ABRT_Msk |
                                                                      TT_I2C0_INTR_MASK_M_RX_UNDER_Msk;
#ifdef A8V2E
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK |=  TT_I2C0_INTR_MASK_M_SCL_STUCK_AT_LOW_Pos;
#endif
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

    }
    else
    {
        /* do nothing */
    }


    return Ret;
}

/**
* @brief      :  Service for I2C Synchronous receiving.
* @details    :  Service for I2C Synchronous receiving
*
* @param[in]  :  HwUnit :Select an I2C module
*                Length :Number of bytes which will be read
* @param[out] :  RxBuf : Buffer to store receive data
*
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: Complete data received successfully
*             :  Other: Failed to receive completion data
*
**/
TT_RetType  I2c_Hw_SyncReceive(TT_CONST uint8 HwUnit, uint8* RxBuf, uint16 Length)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Status = 0;

#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    (void) Base_Drv_Timer_MicrosToTicks(I2C_TIMEOUT_DURATION, &uS2Ticks);
#endif

    TT_ParaCheck((HwUnit >= I2C_CONTROLLER_COUNT), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((RxBuf == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Length == 0UL), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2c_PubMap[HwUnit] >= I2C_CONTROLLER_COUNT), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status != TT_I2C_STATE_IDLE), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((Ret == TT_RET_SUCCESS) && (I2C_PubResources[I2c_PubMap[HwUnit]].work_mode != TT_I2C_WORK_POLL), TT_RET_STATUS_ERR, &Ret);


    if(TT_RET_SUCCESS == Ret)
    {
    	/* Master mode */
        if (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) != 0)
            && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_SLAVE_DISABLE_Msk) != 0))
        {
            /* Set control variables */
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->data = RxBuf;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num = (uint32)Length;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = 0U;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->ncnt = I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num;

            /* Update driver status */
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY_RX;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 1U;

#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			(void) Base_Drv_Timer_GetCounter(&timeStart);
#endif
            while ((I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt < I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num)||
                  (Status & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) == 0)
            {
                Status = I2c_Hw_PriMasterClearIntr(HwUnit);
#ifdef A8V2E
                Ret = I2c_Hw_PriUnlockDeadlock(HwUnit,Status);
                if(Ret != TT_RET_SUCCESS)
                {
                	Ret = TT_RET_IO_RX_ERR;
                	break;
                }
                else
                {

                }
#else
                if((Status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0)
                {
                    Ret = TT_RET_IO_RX_ERR;
                    break;
                }
                else
                {
                    /* do nothing */
                }
#endif
                if (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->ncnt > 0 && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_TFNF_Msk) != 0UL))
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD = TT_I2C0_DATA_CMD_CMD_Msk;
                    I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->ncnt--;
                }
                else
                {
                    /* do nothing */
                }

                if((I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_RFNE_Msk) != 0UL)
                {
                    I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->data[I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt] = (uint8)I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD;
                    I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt++;
                }
                else
                {

                }
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
				(void) Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
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
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0U;
        }
        else if (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) == 0UL)
            && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_SLAVE_DISABLE_Msk) == 0UL)) /* slave mode */
        {

            /* Set control variables */
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY_RX;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->sdata = RxBuf;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->snum = Length;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = 0U;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 1U;
            Ret = I2c_Hw_PriSyncSlaReceive(HwUnit);
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0U;

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
* @brief      :  Service for I2C Status .
* @details    :  Gets the status of the current I2C
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  Status ：Store the status of I2c
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Get status command accepted
*             :  Other: Transmit command not accepted
*
**/
TT_RetType I2c_Hw_GetStatus(TT_CONST uint8 HwUnit, I2c_StatusType* Status)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((HwUnit >= I2C_CONTROLLER_COUNT), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((Status == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Ret ==TT_RET_SUCCESS && ((I2c_PubMap[HwUnit] == 0xFFU) || (NULL_PTR == I2C_PubResources[I2c_PubMap[HwUnit]].ctrl))), TT_RET_PARAM_ERR, &Ret);


    if(TT_RET_SUCCESS == Ret)
    {
        *Status =I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief      :  Serves the I2C0 interrupt function.
* @details    :  Response I2C0 interrupt
* @param[in]  :  None
* @param[out] :  None
* @return     :  None
* @retval     :  None
*
**/
ISR(I2C0_IRQHandler);
ISR(I2C0_IRQHandler)
{
    I2c_Hw_PriIrqHandler(0);
}
/**
* @brief      :  Serves the I2C1 interrupt function.
* @details    :  Response I2C1 interrupt
* @param[in]  :  None
* @param[out] :  None
* @return     :  None
* @retval     :  None
*
**/
ISR(I2C1_IRQHandler);
ISR(I2C1_IRQHandler)
{
    I2c_Hw_PriIrqHandler(1);
}

#define I2C_STOP_SEC_CODE_FAST
#include "I2c_MemMap.h"

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
/**
* @brief      :  Set Master Target adder.
* @details    :  Set the target address of the host.
*                This parameter is available only to the host
* @param[in]  :  HwUnit :Select an I2C module
*             :  Adder  :Set address
* @param[out] :  None
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: Complete set master adder successfully
*             :  Other: Failed to set master adder successfully
**/
TT_RetType I2c_Hw_SetTargetAdderss(uint8 HwUnit, uint16 Adder)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    (void) Base_Drv_Timer_MicrosToTicks(I2C_TIMEOUT_DURATION, &uS2Ticks);
#endif

    TT_ParaCheck((I2c_PubMap[HwUnit] == 0xFFU), TT_RET_STATUS_UNINIT_ERR, &Ret);
    TT_ParaCheck((TT_RET_SUCCESS == Ret) && (NULL_PTR == I2C_PubResources[I2c_PubMap[HwUnit]].ctrl), TT_RET_STATUS_UNINIT_ERR, &Ret);
    TT_ParaCheck((TT_RET_SUCCESS == Ret) && (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status != TT_I2C_STATE_IDLE), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((TT_RET_SUCCESS == Ret) && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) == 0), TT_RET_STATUS_ERR, &Ret);

    if(TT_RET_SUCCESS == Ret)
    {
        /* Register failure, write TAR register */
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_BUSY;

#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
           (void) Base_Drv_Timer_GetCounter(&timeStart);
#endif

        /* Wait for I2c to be active */
        while(((I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_MST_ACTIVITY_Msk) != 0) ||
               (I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_TFE_Msk) == 0 )
        {
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
            (void) Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
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

#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
        if(TT_RET_SUCCESS == Ret)
        {
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->TAR &= ~(TT_I2C0_TAR_TAR_Msk);
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->TAR |= (Adder & TT_I2C0_TAR_TAR_Msk);
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->addr = Adder;
        }
        else
        {
            /* do nothing */
        }
#else
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->TAR &= ~(TT_I2C0_TAR_TAR_Msk);
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->TAR |= (Adder & TT_I2C0_TAR_TAR_Msk);
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->addr = Adder;
#endif

    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/
#define I2C_START_SEC_CODE_SLOW
#include "I2c_MemMap.h"
/**
 * @brief      :  Map I2c_PubMap to I2c_Hw_PbResources
 * @details    :  The subscript of the I2c_PubMap array indicates the corresponding I2c0 to I2c1,
 *                and the member value of the I2c_PubMap array is the array subscript of I2c_Hw_PbResources.
 *                Uart_Hw_PbResources[Uart_Map[Uart_0]] Indirectly accesses hardware resources corresponding to the serial port
 * @param[in]  :  CfgPtr - Pointer to configtype structure
 * @param[out] :  None
 * @return     :  TT_RetType
 * @retval     :  TT_RET_SUCCESS: Map command accepted
 *             :  Other: Map command not accepted
 *
 **/
static TT_RetType I2c_Hw_PriMapsort(TT_CONST I2c_ConfigType* CfgPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 HwUnit = 0;
    uint8 i = 0;
    uint8 Map_Sort = 0;
    uint16 Adder = 0;

    if(NULL_PTR != CfgPtr)
    {
        for(i = 0;i < I2C_CONFIGED_COUNT; i++)
        {
            HwUnit = CfgPtr->CtrlCfgPtr[i].HwUnit;
            Adder = CfgPtr->CtrlCfgPtr[i].Address;

            if(((uint8)I2C_HW_ADDER_MAX < Adder)||
              ((HIGH_SPEED_MASTER_CODE_MIN <= Adder)&& (SMBUS_HOST >= Adder))||
              ((RESERVED_ADDERSS_MIN <= Adder)&& (RESERVED_ADDERSS_MAX >= Adder))||
              (Adder == SMBUS_ALERT_RESPONSE_ADDERSS)||
              (SMBUS_DEVICE_DEFAULT_ADDERSS == Adder))
            {
                Ret = TT_RET_PARAM_ADDR_ERR;
                break;
            }
            else
            {
                /* do nothing*/
            }


            if(I2C_CONTROLLER_COUNT > HwUnit)
            {
              I2c_PubMap[HwUnit] = i;
            }
            else
            {
              Ret = TT_RET_PARAM_INVALID_DATA_ERR;
              break;
            }

        }

        if(TT_RET_SUCCESS ==  Ret)
        {
            for(i = 0;i < I2C_CONTROLLER_COUNT; i++)
            {
              if(I2c_PubMap[i] != 0xFFU)
              {
                  I2c_PubMap[i] = Map_Sort;
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
* @brief      :  Set speed-related configurations
* @details    :  Set speed-related configurations
* @param[in]  :  HwUnit :Select an I2C module
*                I2c_ChannelMode : I2c Indicates the Master/slaver mode
*                I2C_Speed ：I2c Speed mode
* @param[out] :  None
* @return     :  uint32
* @retval     :  TT_RET_SUCCESS: Mode setting succeeded
*             :  Other: Failed to set the mode
*
**/
static TT_RetType I2c_Hw_PriSetMode(uint8  HwUnit,I2c_WorkChannelType I2c_ChannelMode,I2c_SpeedType I2C_Speed)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 cntl = 0, hcnt = 0, lcnt = 0;
    Mcu_PeripheralClockValType I2CSysClk = I2C_PubResources[I2c_PubMap[HwUnit]].base_clk;

    switch (I2c_ChannelMode)
    {
    case WORK_MODE_SLAVE:
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->SAR &= ~(TT_I2C0_SAR_SAR_Msk);
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->SAR |= (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->addr & TT_I2C0_SAR_SAR_Msk);
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON = 0;
        break;

    case WORK_MODE_MASTER:
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->TAR &= ~(TT_I2C0_TAR_TAR_Msk);
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->TAR |= (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->addr & TT_I2C0_TAR_TAR_Msk);
        cntl = I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & (~TT_I2C0_CON_SPEED_Msk);

        switch (I2C_Speed)
        {
        case I2C_BUS_SPEED_STANDARD:
            cntl |= (uint32)IC_CON_SPD_SS;
            I2CSysClk = I2CSysClk / 1000 / 1000;
            hcnt = (I2CSysClk * MIN_SS_SCL_HIGHTIME) / NANO_TO_MICRO;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->SS_SCL_HCNT = hcnt;
            lcnt = (I2CSysClk * MIN_SS_SCL_LOWTIME) / NANO_TO_MICRO;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->SS_SCL_LCNT = lcnt;
            break;

        case I2C_BUS_SPEED_FAST:
            cntl |= (uint32)IC_CON_SPD_FS;
            I2CSysClk = I2CSysClk / 1000 / 1000;
            hcnt = (I2CSysClk * MIN_FS_SCL_HIGHTIME) / NANO_TO_MICRO;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->FS_SCL_HCNT = hcnt;
            lcnt = (I2CSysClk * MIN_FS_SCL_LOWTIME) / NANO_TO_MICRO;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->FS_SCL_LCNT = lcnt;
            break;

        case I2C_BUS_SPEED_HIGH:
            cntl |= (uint32)IC_CON_SPD_HS;
            I2CSysClk = I2CSysClk / 1000 / 1000;
            hcnt = (I2CSysClk * MIN_HS_SCL_HIGHTIME) / NANO_TO_MICRO;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->HS_SCL_HCNT = hcnt;
            lcnt = (I2CSysClk * MIN_HS_SCL_LOWTIME) / NANO_TO_MICRO;
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->HS_SCL_LCNT = lcnt;
            break;
        default:
            Ret = TT_RET_PARAM_ENUM_ERR;
            break;
        }
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK = 0;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON = cntl | TT_I2C0_CON_MASTER_Msk | TT_I2C0_CON_SLAVE_DISABLE_Msk;

        break;
    default:
        Ret = TT_RET_PARAM_ENUM_ERR;
        break;
    }
#ifdef A8V2E
    I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON &=~(TT_I2C0_CON_BUS_CLEAR_FEATURE_CTRL_Msk);
    I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON |=(TT_I2C0_CON_BUS_CLEAR_FEATURE_CTRL_Msk);

    I2C_PubResources[I2c_PubMap[HwUnit]].reg->SCL_STUCK_AT_LOW_TIMEOUT = 0x2c00;
    I2C_PubResources[I2c_PubMap[HwUnit]].reg->SDA_STUCK_AT_LOW_TIMEOUT = 0x2c00;
#endif
    return Ret;
}

/**
* @brief      :  Start the clock and obtain the corresponding clock frequency.
* @details    :  Initializing I2C includes: speed, master/slave mode, address, and so on
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  I2CSysClk :Save clock frequency
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS:  Starting and obtaining the clock command succeeded. Procedure
*             :  Other: Failure
*
**/
static TT_RetType I2c_Hw_PriClk(uint8 HwUnit,Mcu_PeripheralClockValType* I2CSysClk)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    if(HwUnit < (uint8)I2C_CONTROLLER_COUNT)
    {
        Ret = Mcu_Drv_Clk_StartModules(I2c_PubStartClk[HwUnit]);

        if(TT_RET_SUCCESS == Ret )
        {
            Ret = Mcu_Drv_Clk_GetPeriph(I2c_PubGetClk[HwUnit], I2CSysClk);
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        Ret = TT_RET_PARAM_ERR;
    }
    return Ret;
}

#if defined(I2C0_DMA_ENABLE) || defined(I2C1_DMA_ENABLE)
/**
 * @brief      : I2c sends DMA mode event callback result function.
 * @details    : I2c sends DMA mode event callback result function.
 * @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
 *               event - DMA_EVENT_TERMINAL_COUNT_REQUEST / Other
 * @param[out] : None
 * @return     : void
 * @retval     : None
 *
 **/
static void I2c_Hw_PriDmaTxEvent(uint8 HwUnit, uint32 event)
{
    if(DMA_EVENT_TERMINAL_COUNT_REQUEST == event)
    {
        /* Diabled Transmit DMA request */
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->DMA_CR &= ~TT_I2C0_DMA_CR_TDMAE_Msk;

        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num;
        /* Clear TX busy flag */
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;

        /* Set Send Complete event for asynchronous transfers */
        if (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event != NULL_PTR)
        {
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event(TT_I2C_EVENT_TRANSFER_DONE);
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;

        /* Set Send Complete event for asynchronous transfers */
        if (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event != NULL_PTR)
        {
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event(TT_I2C_EVENT_TRANSFER_INCOMPLETE);
        }
        else
        {
            /* do nothing */
        }
    }

}

/**
 * @brief      : I2c receive DMA mode event callback result function.
 * @details    : I2c receive DMA mode event callback result function.
 * @param[in]  : HwUnit - Module ID of the Hardware unit to receive
 *               event - GPDMA_EVENT_TERMINAL_COUNT_REQUEST / Other
 * @param[out] : None
 * @return     : void
 * @retval     : None
 *
 **/
static void I2c_Hw_PriDmaRxEvent(uint8 HwUnit, uint32 event)
{
    if(DMA_EVENT_TERMINAL_COUNT_REQUEST == event)
    {
        /* Diabled Receive DMA request */
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->DMA_CR &= ~TT_I2C0_DMA_CR_RDMAE_Msk;
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt = I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num;
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;


        /* Set Receive Complete event for asynchronous transfers */
        if (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event != NULL_PTR)
        {
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event(TT_I2C_EVENT_TRANSFER_DONE);
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;

        /* Set Send Complete event for asynchronous transfers */
        if (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event != NULL_PTR)
        {
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event(TT_I2C_EVENT_TRANSFER_INCOMPLETE);
        }
        else
        {
            /* do nothing */
        }
    }
}

#ifdef I2C0_DMA_ENABLE

/**
 * @brief      : I2c0 send DMA handler function.
 * @details    : I2c0 send DMA handler function.
 * @param[in]  : HwUnit - Module ID of the Hardware unit to transmit
 * @param[out] : None
 * @return     : void
 * @retval     : None
 *
 **/
void I2c_Hw_PriDmaTx0(uint32 event)
{
    I2c_Hw_PriDmaTxEvent(0, event);
}
/**
 * @brief      : I2c0 receive DMA handler function
 * @details    : I2c0 receive DMA handler function
 * @param[in]  : HwUnit - Module ID of the Hardware unit to receive
 * @param[out] : None
 * @return     : void
 * @retval     : None
 *
 **/
void I2c_Hw_PriDmaRx0(uint32 event)
{
    I2c_Hw_PriDmaRxEvent(0, event);
}
#endif

#ifdef I2C1_DMA_ENABLE
void I2c_Hw_PriDmaTx1(uint32 event)
{
    I2c_Hw_PriDmaTxEvent(1, event);
}
void I2c_Hw_PriDmaRx1(uint32 event)
{
    I2c_Hw_PriDmaRxEvent(1, event);
}
#endif
#endif

#define I2C_STOP_SEC_CODE_SLOW
#include "I2c_MemMap.h"

#define I2C_START_SEC_CODE_FAST
#include "I2c_MemMap.h"
/**
* @brief      :  Service for I2c Slave Poll Transmission.
* @details    :  Service for I2c Slave Poll Transmission.
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
static TT_RetType I2c_Hw_PriSlaveSyncTransmit(uint8 HwUnit)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Status = 0;
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    (void) Base_Drv_Timer_MicrosToTicks(I2C_TIMEOUT_DURATION, &uS2Ticks);
    (void) Base_Drv_Timer_GetCounter(&timeStart);
#endif
    while((I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt < I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->snum) ||
         (Status & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) == 0 )
    {
        Status = I2c_Hw_PriSlaveClearIntr(HwUnit);
#ifdef A8V2E
        if((Status & TT_I2C0_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Msk) != 0)
        {
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
            Ret = TT_RET_IO_TX_ERR;
            break;
        }
        else
        {
            /* do nothing */
        }
#endif
        /* An error occurred to exit the loop */
        if((Status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0)
        {
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
            I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
            Ret = TT_RET_IO_TX_ERR;
            break;
        }
        else if((Status & TT_I2C0_RAW_INTR_STAT_RD_REQ_Msk) != 0)
        {
            if (((I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_TFNF_Msk) != 0) &&
                ((I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt < I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->snum)))
            {
                I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD = I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->sdata[I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt];
                I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt++;
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
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    (void) Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
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

    return Ret;
}
/**
* @brief      :  Service for I2C Interrupt .
* @details    :  Read the status of the I2C and reset the corresponding interrupt status
* @param[in]  :  HwUnit :Select an I2C module
*                status :Record the host interrupt status
* @param[out] :  None
* @return     :  uint32
* @retval     :  The return value requires the specific status reference register INTR_STAT
*
**/
static void I2c_Hw_PriMclearIntrHbits(uint8 HwUnit,uint32 status)
{
    if ((status & TT_I2C0_RAW_INTR_STAT_RX_DONE_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_RX_DONE;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_ACTIVITY_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_ACTIVITY;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_STOP_DET;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_START_DET_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_START_DET;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_GEN_CALL_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_GEN_CALL;
    }
    else
    {
        /* do nothing */
    }
}

/**
* @brief      :  Service for I2C Interrupt .
* @details    :  Read the status of the I2C and reset the corresponding interrupt status
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  uint32
* @retval     :  The return value requires the specific status reference register INTR_STAT
*
**/
static uint32 I2c_Hw_PriMasterClearIntr(uint8 HwUnit)
{
    uint32 status = 0;

    status = I2C_PubResources[I2c_PubMap[HwUnit]].reg->RAW_INTR_STAT;

    if ((status & TT_I2C0_RAW_INTR_STAT_RX_UNDER_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_RX_UNDER;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_RX_OVER_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_RX_OVER;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_TX_OVER_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_TX_OVER;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_RD_REQ_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_RD_REQ;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_TX_ABRT;
    }
    else
    {
        /* do nothing */
    }
    I2c_Hw_PriMclearIntrHbits(HwUnit,status);

    return status;
}

/**
* @brief      :  Serves the I2C host interrupt function.
* @details    :  The corresponding interrupt is used to receive or send data
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  uint32
* @retval     :  Return the status of the I2C
*
**/
static uint32 I2c_Hw_PriMasterHandler(uint8  HwUnit)
{
    uint32 Ret = 0;
    uint32 status = 0;
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    (void) Base_Drv_Timer_MicrosToTicks(I2C_TIMEOUT_DURATION, &uS2Ticks);
#endif
    status = I2c_Hw_PriMasterClearIntr(HwUnit);

#ifdef A8V2E
    Ret = I2c_Hw_PriUnlockDeadlock(HwUnit,status);
#else
    if ((status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0UL)
    {
        Ret = TT_I2C_EVENT_TRANSFER_INCOMPLETE;
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK = 0;
    }
    else
    {

    }
#endif

    if ((Ret == 0) && ((status & TT_I2C0_INTR_MASK_M_TX_EMPTY_Msk) != 0UL))
    {
        /*Data transmitted, ACK received Send a byte */
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD = I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->data[I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt];
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt++;

    }
    else if ((Ret == 0) && ((status & TT_I2C0_INTR_MASK_M_RX_FULL_Msk) != 0UL))
    {
       /* Data received, ACK returned */
       I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->data[I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt] = (uint8)(I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD);
       I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt++;

       /* Send a read request */
       while (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->ncnt > 0 && ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_TFNF_Msk) != 0UL))
       {
           I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD = TT_I2C0_DATA_CMD_CMD_Msk;
           I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->ncnt--;
       }
    }
    else
    {
        /* do nothing */
    }

    if (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt >= (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->num))
    {
        /* Update completion mark */
    	Ret = TT_I2C_EVENT_TRANSFER_DONE;
        #if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
            (void) Base_Drv_Timer_GetCounter(&timeStart);
        #endif
        while((I2C_PubResources[I2c_PubMap[HwUnit]].reg->RAW_INTR_STAT & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) == 0)
        {
            #if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
                (void)Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);

                if (timeElapsed >= uS2Ticks)
                {
                	Ret = TT_I2C_EVENT_TRANSFER_INCOMPLETE;
                    break;
                }
                else
                {
                    /* do nothing */
                }
            #endif
        }
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK = 0;
    }
    else
    {
    	/* do nothing */
    }



    return (Ret);
}

/**
* @brief      :  Service for I2C slave Interrupt .
* @details    :  Read the Slaver interrupt status and clear the hight interrupt flag
* @param[in]  :  HwUnit :Select an I2C module
*                status   ：Records the interrupt status of the slave
* @param[out] :  None
* @return     :  uint32
* @retval     :  The return value requires the specific status reference register INTR_STAT
*
**/
static void I2c_Hw_PriSclearIntrHbits(uint8 HwUnit,uint32 status)
{
    if ((status & TT_I2C0_RAW_INTR_STAT_RX_DONE_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_RX_DONE;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_ACTIVITY_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_ACTIVITY;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_STOP_DET;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_START_DET_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_START_DET;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_GEN_CALL_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_GEN_CALL;
    }
    else
    {
        /* do nothing */
    }

}

/**
* @brief      :  Service for I2C slave Interrupt .
* @details    :  Read the Slaver interrupt status and clear the hight interrupt flag
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  uint32
* @retval     :  The return value requires the specific status reference register INTR_STAT
*
**/
static uint32 I2c_Hw_PriSlaveClearIntr(uint8 HwUnit)
{
    uint32 status = 0;
    status = I2C_PubResources[I2c_PubMap[HwUnit]].reg->RAW_INTR_STAT;

    if ((status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_TX_ABRT;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_RX_UNDER_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_RX_UNDER;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_RX_OVER_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_RX_OVER;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_RD_REQ_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_RD_REQ;
    }
    else
    {
        /* do nothing */
    }
    if ((status & TT_I2C0_RAW_INTR_STAT_TX_OVER_Msk) != 0UL)
    {
        (void)I2C_PubResources[I2c_PubMap[HwUnit]].reg->CLR_TX_OVER;
    }
    else
    {
        /* do nothing */
    }

    /* Clear a high bit interrupt */
    I2c_Hw_PriSclearIntrHbits(HwUnit, status);

    return status;
}

/**
* @brief      :  Serves the I2C Slave interrupt function.
* @details    :  The corresponding interrupt is used to receive or send data
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  uint32
* @retval     :  Return the status of the I2C
*
**/
static uint32 I2c_Hw_PriSlaveHandler(uint8  HwUnit)
{
    uint32 event = 0;
    uint32 status = 0;
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    (void) Base_Drv_Timer_MicrosToTicks(I2C_TIMEOUT_DURATION, &uS2Ticks);
#endif
    status = I2c_Hw_PriSlaveClearIntr(HwUnit);

    if ((status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0UL)
    {
        event = TT_I2C_EVENT_TRANSFER_INCOMPLETE;
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK = 0;
    }
    else if ((status & TT_I2C0_INTR_MASK_M_RD_REQ_Msk) != 0UL)
    {
        /* Send a byte */
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD = I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->sdata[I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt];
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt++;

    }
    else if ((status & TT_I2C0_INTR_MASK_M_RX_FULL_Msk) != 0UL)
    {   /* Rx */
        /* Data received, read a byte */
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->sdata[I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt] = (uint8)I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD;
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt++;
    }
    else
    {
            /* do nothing */
    }
    /*Whether receiving or sending data is complete */
    if ((uint32)I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt >= (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->snum))
    {
        /* Update completion mark */
        event = TT_I2C_EVENT_TRANSFER_DONE;
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
		(void) Base_Drv_Timer_GetCounter(&timeStart);
#endif
		while((I2C_PubResources[I2c_PubMap[HwUnit]].reg->RAW_INTR_STAT & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) == 0)
		{
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
			(void) Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
			if (timeElapsed >= uS2Ticks)
			{
				event = TT_I2C_EVENT_TRANSFER_INCOMPLETE;
				break;
			}
			else
			{
				/* do nothing */
			}
#endif
		}
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK = 0;
    }
    else
    {
    	/* do nothing */
    }


    return (event);
}

/**
* @brief      :  Serves the I2C interrupt function.
* @details    :  Determine whether the interrupt is from the machine or the host,
*                and call the callback function to set the status value to.
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
* @return     :  void
* @retval     :  void
*
**/
static void I2c_Hw_PriIrqHandler(uint8 HwUnit)
{
    uint32 event = 0;
    if ((I2C_PubResources[I2c_PubMap[HwUnit]].reg->CON & TT_I2C0_CON_MASTER_Msk) != 0UL)
    {
        event = I2c_Hw_PriMasterHandler(HwUnit);
    }
    else
    {
        event = I2c_Hw_PriSlaveHandler(HwUnit);
    }

    /* The interrupt completes calling the callback function */
    if ((event != 0) && (I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event != NULL_PTR))
    {
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cb_event(event);
    }
    else
    {

    }

}
#ifdef A8V2E
/**
* @brief      :  I2c_Hw_PriUnlockDeadlock.
* @details    :  Remove the host deadlock condition
* @param[in]  :  HwUnit :Select an I2C module
* 				 status :Interrupt send message
* @param[out] :  None
* @return     :  TT_RetType
* @retval     :  TT_RET_SUCCESS: The initialization is complete
*             :  Other: Initialization is not complete
*
**/
static uint32 I2c_Hw_PriUnlockDeadlock(uint8  HwUnit,uint32 status)
{
	uint32 Ret = TT_RET_SUCCESS;
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    (void) Base_Drv_Timer_MicrosToTicks(I2C_TIMEOUT_DURATION, &uS2Ticks);
#endif

    if((status & TT_I2C0_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Msk) != 0)
    {
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
        Ret = TT_I2C_EVENT_TRANSFER_INCOMPLETE;
    }
    else
    {
    	/* do nothing */
    }

    if ((Ret == TT_RET_SUCCESS) && (status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0UL)
    {
        Ret = TT_I2C_EVENT_TRANSFER_INCOMPLETE;
        if((I2C_PubResources[I2c_PubMap[HwUnit]].reg->TX_ABRT_SOURCE & TT_I2C0_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Msk) != 0)
        {
            I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE |= TT_I2C0_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Msk;
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
            (void) Base_Drv_Timer_GetCounter(&timeStart);
#endif
            while((I2C_PubResources[I2c_PubMap[HwUnit]].reg->RAW_INTR_STAT & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) == 0)
            {
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
				Ret = Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
				if (timeElapsed >= uS2Ticks)
				{
					break;
				}
				else
				{
					/* do nothing */
				}
#endif

            }
        }

        I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
        I2C_PubResources[I2c_PubMap[HwUnit]].reg->INTR_MASK = 0;
    }
    else
    {
    	/* do nothing */
    }

    return Ret;
}
#endif
/**
* @brief      :  I2c_Hw_PriSyncSlaReceive
* @details    :  I2c receives processing functions from the slave
*
* @param[in]  :  HwUnit :Select an I2C module
* @param[out] :  None
*
* @return     :  Std_ReturnType
* @retval     :  TT_RET_SUCCESS: Complete data received successfully
*             :  Other: Failed to receive completion data
*
**/
static TT_RetType I2c_Hw_PriSyncSlaReceive(TT_CONST uint8 HwUnit)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Status = 0;

#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = 0;
    (void) Base_Drv_Timer_MicrosToTicks(I2C_TIMEOUT_DURATION, &uS2Ticks);
	(void) Base_Drv_Timer_GetCounter(&timeStart);
#endif
	while ((I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt < I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->snum) ||\
		   (Status & TT_I2C0_RAW_INTR_STAT_STOP_DET_Msk) == 0)
	{
		Status = I2c_Hw_PriSlaveClearIntr(HwUnit);

		if((Status & TT_I2C0_RAW_INTR_STAT_TX_ABRT_Msk) != 0)
		{
			Ret = TT_RET_IO_RX_ERR;
			break;
		}
		else if((I2C_PubResources[I2c_PubMap[HwUnit]].reg->STATUS & TT_I2C0_STATUS_RFNE_Msk) != 0)
		{
			/* Data received, read a byte */
			I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->sdata[I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt] = (uint8)I2C_PubResources[I2c_PubMap[HwUnit]].reg->DATA_CMD;
			I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->cnt++;

		}
		else
		{
			/*do nothing */
		}
#if defined(I2C_TIMEOUT_SUPERVISION_ENABLE) && (I2C_TIMEOUT_SUPERVISION_ENABLE == STD_ON)
		 (void) Base_Drv_Timer_GetElapsed(&timeStart, &timeElapsed);
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

	I2C_PubResources[I2c_PubMap[HwUnit]].ctrl->status = TT_I2C_STATE_IDLE;
	I2C_PubResources[I2c_PubMap[HwUnit]].reg->ENABLE = 0;
	return Ret;

}

#define I2C_STOP_SEC_CODE_FAST
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif
