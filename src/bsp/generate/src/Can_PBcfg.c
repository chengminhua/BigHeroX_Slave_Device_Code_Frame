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
**  FILENAME     : Can_PBcfg.c                                                **
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
#ifdef USING_AUTOSAROS
#include "Can.h"
#else
#include "Can_Drv.h"
#endif
#include "Can_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_PBCFG_VENDOR_ID_C                      1541
#define CAN_PBCFG_MODULE_ID_C                      80
#define CAN_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CAN_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define CAN_PBCFG_AR_RELEASE_PATCH_VERSION_C       0
#define CAN_PBCFG_SW_MAJOR_VERSION_C               1
#define CAN_PBCFG_SW_MINOR_VERSION_C               1
#define CAN_PBCFG_SW_PATCH_VERSION_C               0
/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifdef USING_AUTOSAROS
/* Check if current file and Can.h are of the same vendor */
#if (CAN_PBCFG_VENDOR_ID_C != CAN_VENDOR_ID_H)
    #error "Can_PBcfg.c and Can.h have different vendor ids"
#endif
#if (CAN_PBCFG_MODULE_ID_C != CAN_MODULE_ID_H)
    #error "Can_PBcfg.c and Can.h have different module ids"
#endif
/* Check if current file and Can.h are of the same Autosar version */
#if ((CAN_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CAN_AR_RELEASE_MAJOR_VERSION_H) || \
    (CAN_PBCFG_AR_RELEASE_MINOR_VERSION_C != CAN_AR_RELEASE_MINOR_VERSION_H) || \
    (CAN_PBCFG_AR_RELEASE_PATCH_VERSION_C != CAN_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Can_PBcfg.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Software version */
#if ((CAN_PBCFG_SW_MAJOR_VERSION_C != CAN_SW_MAJOR_VERSION_H) || \
    (CAN_PBCFG_SW_MINOR_VERSION_C != CAN_SW_MINOR_VERSION_H) || \
    (CAN_PBCFG_SW_PATCH_VERSION_C != CAN_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_PBcfg.c and Can.h are different"
#endif
#else
/* Check if current file and Can_Drv.h are of the same vendor */
#if (CAN_PBCFG_VENDOR_ID_C != CAN_DRV_VENDOR_ID_H)
    #error "Can_PBcfg.c and Can_Drv.h have different vendor ids"
#endif
#if (CAN_PBCFG_MODULE_ID_C != CAN_DRV_MODULE_ID_H)
    #error "Can_PBcfg.c and Can_Drv.h have different module ids"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CAN_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
    (CAN_PBCFG_AR_RELEASE_MINOR_VERSION_C != CAN_DRV_AR_RELEASE_MINOR_VERSION_H) || \
    (CAN_PBCFG_AR_RELEASE_PATCH_VERSION_C != CAN_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Can_PBcfg.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Software version */
#if ((CAN_PBCFG_SW_MAJOR_VERSION_C != CAN_DRV_SW_MAJOR_VERSION_H) || \
    (CAN_PBCFG_SW_MINOR_VERSION_C != CAN_DRV_SW_MINOR_VERSION_H) || \
    (CAN_PBCFG_SW_PATCH_VERSION_C != CAN_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_PBcfg.c and Can_Drv.h are different"
#endif
#endif
/* Check if current file and Can_Types.h are of the same vendor */
#if (CAN_PBCFG_VENDOR_ID_C != CAN_FLEXCAN_TYPES_VENDOR_ID_H)
    #error "Can_PBcfg.c and Can_Types.h have different vendor ids"
#endif
#if (CAN_PBCFG_MODULE_ID_C != CAN_FLEXCAN_TYPES_MODULE_ID_H)
        #error "Can_PBcfg.c and Can_Types.h have different module ids"
    #endif
/* Check if current file and Can_Types.h are of the same Autosar version */
#if ((CAN_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
    (CAN_PBCFG_AR_RELEASE_MINOR_VERSION_C != CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
    (CAN_PBCFG_AR_RELEASE_PATCH_VERSION_C != CAN_FLEXCAN_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Can_PBcfg.c and Can_Types.h are different"
#endif
/* Check if current file and Can_Drv_Types.h are of the same Software version */
#if ((CAN_PBCFG_SW_MAJOR_VERSION_C != CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H) || \
    (CAN_PBCFG_SW_MINOR_VERSION_C != CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H) || \
    (CAN_PBCFG_SW_PATCH_VERSION_C != CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_PBcfg.c and Can_Types.h are different"
#endif

/******************************************************************************
*                            Public Variables
*******************************************************************************/
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
#endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Constants
*******************************************************************************/

#define CAN_START_SEC_CONFIG_DATA_32
#include "Can_MemMap.h"

/**
*   @brief  Hardware Buffer Address of CanController_0
*/
static TT_CONST uint32 Can_au32HwBufferAddr_Ctrl0[2U]=
    {
    (TT_CAN2_BASE + (uint32)0x0680U),
    (TT_CAN2_BASE + (uint32)0x06c8U)
    };
/**
*   @brief  Hardware Buffer Address of CanController_1
*/
static TT_CONST uint32 Can_au32HwBufferAddr_Ctrl1[2U]=
    {
    (TT_CAN1_BASE + (uint32)0x0680U),
    (TT_CAN1_BASE + (uint32)0x0690U)
    };
/**
*   @brief  Hardware Buffer Address of CanController_2
*/
static TT_CONST uint32 Can_au32HwBufferAddr_Ctrl2[2U]=
    {
    (TT_CAN4_BASE + (uint32)0x0680U),
    (TT_CAN4_BASE + (uint32)0x06c8U)
    };

/**
*   @brief  Hardware Filter of CanHardwareObject0
*/
static TT_CONST Can_HwFilterType Can_aHwFilter_Object0=
{
    .Can_u32HwFilterCode = (uint32)0x00000008U,
    .Can_u32HwFilterMask = (uint32)0xc0000000U,
};
/**
*   @brief  Hardware Filter of CanHardwareObject1
*/
static TT_CONST Can_HwFilterType Can_aHwFilter_Object1=
{
    .Can_u32HwFilterCode = (uint32)0x00000000U,
    .Can_u32HwFilterMask = (uint32)0xc0000000U,
};
/**
*   @brief  Hardware Filter of CanHardwareObject2
*/
static TT_CONST Can_HwFilterType Can_aHwFilter_Object2=
{
    .Can_u32HwFilterCode = (uint32)0x00000000U,
    .Can_u32HwFilterMask = (uint32)0xc0000000U,
};


#define CAN_STOP_SEC_CONFIG_DATA_32
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"

/**
*   @brief  Mapping Controller ID to Controller hardware offset
*/
static TT_CONST uint8 Can_aCtrlOffsetToCtrlIDMap[CAN_HWCONTROLLER_SUPPORT]=
{
    (uint8)CAN_CONTROLLER_UNUSED,
    (uint8)1,
    (uint8)0,
    (uint8)CAN_CONTROLLER_UNUSED,
    (uint8)2,
    (uint8)CAN_CONTROLLER_UNUSED,
    (uint8)CAN_CONTROLLER_UNUSED,
    (uint8)CAN_CONTROLLER_UNUSED
};

/**
*   @brief  Mapping Controller ID to Hardware Object ID
*/
static TT_CONST uint8 Can_aHwObjIDToCtrlIDMap[CAN_HWOBJECT_CONFIG_COUNT]=
{
    (uint8)0U,
    (uint8)1U,
    (uint8)2U,
    (uint8)0U,
    (uint8)1U,
    (uint8)2U
};

#define CAN_STOP_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_PBcfg_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"

/**
*   @brief  Can Hardware Object Config
*/
/* @violates @ref Can_PBcfg_c_REF_5 MISRA 2012 Required Rule 8.4*/
TT_CONST Can_HwObjectConfigType Can_aHwObjectConfig[CAN_HWOBJECT_CONFIG_COUNT]=
{
    /* CanHardwareObject0 of CanController_0*/
    {
        /* Hardware Object ID */
        .Can_HwObjectID = (Can_HwHandleType)0U,
        /* Hardware Object handle type */
        .Can_HohType = CAN_RECEIVE,
        /* ID Message type */
        .Can_IdMessage = CAN_STANDARD,
        /* Object uses polling */
        .Can_bHwObjectUsesPolling = (boolean)FALSE,
        /* Object enable trigger transmit */
        .Can_bTriggerTransmit = (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        .Can_u8ObjectCount = (uint8)1U,
        /* MainFunction RW period reference */
        .Can_MainFuncPeriodIndex = (uint8)0xFFU,
        /* Data Payload length */
        .Can_u8PayloadLength = (uint8)64U,
        /* Padding value */
        .Can_u8PaddingValue = (uint8)0U,
        /* Hardware Filter Count */
        .Can_u8HwFilterCount = (uint8)1U,
        /* Hw Filter Config */
        .Can_pHwFilterConfig = &Can_aHwFilter_Object0,
        /* Message Buffer is Rx normal */
        .Can_eReceiveType = CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        .Can_u8HwBufferIndex = (uint8)65U,
        /* Message buffer address */
        .Can_pHwBufferAddr = &Can_au32HwBufferAddr_Ctrl0[0U],
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        .CanTimestampEnable = (boolean) FALSE
        #endif
    },
    /* CanHardwareObject1 of CanController_1*/
    {
        /* Hardware Object ID */
        .Can_HwObjectID = (Can_HwHandleType)1U,
        /* Hardware Object handle type */
        .Can_HohType = CAN_RECEIVE,
        /* ID Message type */
        .Can_IdMessage = CAN_STANDARD,
        /* Object uses polling */
        .Can_bHwObjectUsesPolling = (boolean)FALSE,
        /* Object enable trigger transmit */
        .Can_bTriggerTransmit = (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        .Can_u8ObjectCount = (uint8)1U,
        /* MainFunction RW period reference */
        .Can_MainFuncPeriodIndex = (uint8)0xFFU,
        /* Data Payload length */
        .Can_u8PayloadLength = (uint8)8U,
        /* Padding value */
        .Can_u8PaddingValue = (uint8)0U,
        /* Hardware Filter Count */
        .Can_u8HwFilterCount = (uint8)1U,
        /* Hw Filter Config */
        .Can_pHwFilterConfig = &Can_aHwFilter_Object1,
        /* Message Buffer is Rx normal */
        .Can_eReceiveType = CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        .Can_u8HwBufferIndex = (uint8)96U,
        /* Message buffer address */
        .Can_pHwBufferAddr = &Can_au32HwBufferAddr_Ctrl1[0U],
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        .CanTimestampEnable = (boolean) FALSE
        #endif
    },
    /* CanHardwareObject2 of CanController_2*/
    {
        /* Hardware Object ID */
        .Can_HwObjectID = (Can_HwHandleType)2U,
        /* Hardware Object handle type */
        .Can_HohType = CAN_RECEIVE,
        /* ID Message type */
        .Can_IdMessage = CAN_STANDARD,
        /* Object uses polling */
        .Can_bHwObjectUsesPolling = (boolean)FALSE,
        /* Object enable trigger transmit */
        .Can_bTriggerTransmit = (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        .Can_u8ObjectCount = (uint8)1U,
        /* MainFunction RW period reference */
        .Can_MainFuncPeriodIndex = (uint8)0xFFU,
        /* Data Payload length */
        .Can_u8PayloadLength = (uint8)64U,
        /* Padding value */
        .Can_u8PaddingValue = (uint8)0U,
        /* Hardware Filter Count */
        .Can_u8HwFilterCount = (uint8)1U,
        /* Hw Filter Config */
        .Can_pHwFilterConfig = &Can_aHwFilter_Object2,
        /* Message Buffer is Rx normal */
        .Can_eReceiveType = CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        .Can_u8HwBufferIndex = (uint8)65U,
        /* Message buffer address */
        .Can_pHwBufferAddr = &Can_au32HwBufferAddr_Ctrl2[0U],
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        .CanTimestampEnable = (boolean) FALSE
        #endif
    },
    /* CanHardwareObject3 of CanController_0*/
    {
        /* Hardware Object ID */
        .Can_HwObjectID = (Can_HwHandleType)3U,
        /* Hardware Object handle type */
        .Can_HohType = CAN_TRANSMIT,
        /* ID Message type */
        .Can_IdMessage = CAN_STANDARD,
        /* Object uses polling */
        .Can_bHwObjectUsesPolling = (boolean)TRUE,
        /* Object enable trigger transmit */
        .Can_bTriggerTransmit = (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        .Can_u8ObjectCount = (uint8)1U,
        /* MainFunction RW period reference */
        .Can_MainFuncPeriodIndex = (uint8)0xFFU,
        /* Data Payload length */
        .Can_u8PayloadLength = (uint8)64U,
        /* Padding value */
        .Can_u8PaddingValue = (uint8)0U,
        /* Hardware Filter Count */
        .Can_u8HwFilterCount = (uint8)0U,
        /* Hw Filter Config */
        .Can_pHwFilterConfig = NULL_PTR,
        /* Message Buffer is Tx normal */
        .Can_eReceiveType = CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        .Can_u8HwBufferIndex = (uint8)66U,
        /* Message buffer address */
        .Can_pHwBufferAddr = &Can_au32HwBufferAddr_Ctrl0[1U],
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        .CanTimestampEnable = (boolean) FALSE
        #endif
    },
    /* CanHardwareObject4 of CanController_1*/
    {
        /* Hardware Object ID */
        .Can_HwObjectID = (Can_HwHandleType)4U,
        /* Hardware Object handle type */
        .Can_HohType = CAN_TRANSMIT,
        /* ID Message type */
        .Can_IdMessage = CAN_STANDARD,
        /* Object uses polling */
        .Can_bHwObjectUsesPolling = (boolean)FALSE,
        /* Object enable trigger transmit */
        .Can_bTriggerTransmit = (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        .Can_u8ObjectCount = (uint8)1U,
        /* MainFunction RW period reference */
        .Can_MainFuncPeriodIndex = (uint8)0xFFU,
        /* Data Payload length */
        .Can_u8PayloadLength = (uint8)8U,
        /* Padding value */
        .Can_u8PaddingValue = (uint8)0U,
        /* Hardware Filter Count */
        .Can_u8HwFilterCount = (uint8)0U,
        /* Hw Filter Config */
        .Can_pHwFilterConfig = NULL_PTR,
        /* Message Buffer is Tx normal */
        .Can_eReceiveType = CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        .Can_u8HwBufferIndex = (uint8)97U,
        /* Message buffer address */
        .Can_pHwBufferAddr = &Can_au32HwBufferAddr_Ctrl1[1U],
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        .CanTimestampEnable = (boolean) FALSE
        #endif
    },
    /* CanHardwareObject5 of CanController_2*/
    {
        /* Hardware Object ID */
        .Can_HwObjectID = (Can_HwHandleType)5U,
        /* Hardware Object handle type */
        .Can_HohType = CAN_TRANSMIT,
        /* ID Message type */
        .Can_IdMessage = CAN_STANDARD,
        /* Object uses polling */
        .Can_bHwObjectUsesPolling = (boolean)TRUE,
        /* Object enable trigger transmit */
        .Can_bTriggerTransmit = (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        .Can_u8ObjectCount = (uint8)1U,
        /* MainFunction RW period reference */
        .Can_MainFuncPeriodIndex = (uint8)0xFFU,
        /* Data Payload length */
        .Can_u8PayloadLength = (uint8)64U,
        /* Padding value */
        .Can_u8PaddingValue = (uint8)0U,
        /* Hardware Filter Count */
        .Can_u8HwFilterCount = (uint8)0U,
        /* Hw Filter Config */
        .Can_pHwFilterConfig = NULL_PTR,
        /* Message Buffer is Tx normal */
        .Can_eReceiveType = CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        .Can_u8HwBufferIndex = (uint8)66U,
        /* Message buffer address */
        .Can_pHwBufferAddr = &Can_au32HwBufferAddr_Ctrl2[1U],
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        .CanTimestampEnable = (boolean) FALSE
        #endif
    }
};


/**
*   @brief  Can Baudrate Config of CanController_0
*/
static TT_CONST Can_BaudrateConfigType Can_aBaudrateConfig_Ctrl0[1U]=
{
    {
        /*Can_bEnhanceCBTEnable*/
        .Can_bEnhanceCBTEnable = (boolean)FALSE,
        /* Tx Bit Rate Switch */
        .Can_bBitRateSwitch = (boolean)TRUE,
        /* FD enable */
        .Can_bFDFrame = (boolean)TRUE,
        /* Tx Arbitration Start delay */
        .Can_u8TxArbitrationStartDelay = (uint8)2U,              
        /* Nominal bit rate */
        .Can_NominalBitRate = {
                                .Can_u8PropSeg = (uint8)3U,
                                .Can_u8PhaseSeg1 = (uint8)2U,
                                .Can_u16Prescaler = (uint16)3U,
                                .Can_u8PhaseSeg2 = (uint8)1U,         
                                .Can_u8ResyncJumpWidth = (uint8)1U
                              },
        /* Data bit rate */
        .Can_DataBitRate = {
                            .Can_u8PropSeg = (uint8)3U,
                            .Can_u8PhaseSeg1 = (uint8)2U,
                            .Can_u16Prescaler = (uint16)1U,
                            .Can_u8PhaseSeg2 = (uint8)2U,         
                            .Can_u8ResyncJumpWidth = (uint8)1U
                           },
        .Can_bTrcvDelayEnable = (boolean)FALSE,
        .Can_u8TrcvDelayCompOffset = (uint8)0U
    }
};
/**
*   @brief  HwObject's pointer structure of CanController_0
*/
static TT_CONST Can_HwObjectConfigType * TT_CONST Can_apHwObject_Ctrl0[2U]=
{
    &Can_aHwObjectConfig[0U],
    &Can_aHwObjectConfig[3U]
};
/**
*   @brief  Can Baudrate Config of CanController_1
*/
static TT_CONST Can_BaudrateConfigType Can_aBaudrateConfig_Ctrl1[1U]=
{
    {
        /*Can_bEnhanceCBTEnable*/
        .Can_bEnhanceCBTEnable = (boolean)FALSE,
        /* Tx Bit Rate Switch */
        .Can_bBitRateSwitch = (boolean)FALSE,
        /* FD enable */
        .Can_bFDFrame = (boolean)TRUE,
        /* Tx Arbitration Start delay */
        .Can_u8TxArbitrationStartDelay = (uint8)2U,              
        /* Nominal bit rate */
        .Can_NominalBitRate = {
                                .Can_u8PropSeg = (uint8)3U,
                                .Can_u8PhaseSeg1 = (uint8)2U,
                                .Can_u16Prescaler = (uint16)3U,
                                .Can_u8PhaseSeg2 = (uint8)1U,         
                                .Can_u8ResyncJumpWidth = (uint8)1U
                              },
        /* Data bit rate */
        .Can_DataBitRate = {
                            .Can_u8PropSeg = (uint8)3U,
                            .Can_u8PhaseSeg1 = (uint8)2U,
                            .Can_u16Prescaler = (uint16)3U,
                            .Can_u8PhaseSeg2 = (uint8)1U,         
                            .Can_u8ResyncJumpWidth = (uint8)1U
                           },
        .Can_bTrcvDelayEnable = (boolean)FALSE,
        .Can_u8TrcvDelayCompOffset = (uint8)0U
    }
};
/**
*   @brief  HwObject's pointer structure of CanController_1
*/
static TT_CONST Can_HwObjectConfigType * TT_CONST Can_apHwObject_Ctrl1[2U]=
{
    &Can_aHwObjectConfig[1U],
    &Can_aHwObjectConfig[4U]
};
/**
*   @brief  Can Baudrate Config of CanController_2
*/
static TT_CONST Can_BaudrateConfigType Can_aBaudrateConfig_Ctrl2[1U]=
{
    {
        /*Can_bEnhanceCBTEnable*/
        .Can_bEnhanceCBTEnable = (boolean)FALSE,
        /* Tx Bit Rate Switch */
        .Can_bBitRateSwitch = (boolean)FALSE,
        /* FD enable */
        .Can_bFDFrame = (boolean)TRUE,
        /* Tx Arbitration Start delay */
        .Can_u8TxArbitrationStartDelay = (uint8)2U,              
        /* Nominal bit rate */
        .Can_NominalBitRate = {
                                .Can_u8PropSeg = (uint8)3U,
                                .Can_u8PhaseSeg1 = (uint8)2U,
                                .Can_u16Prescaler = (uint16)3U,
                                .Can_u8PhaseSeg2 = (uint8)1U,         
                                .Can_u8ResyncJumpWidth = (uint8)1U
                              },
        /* Data bit rate */
        .Can_DataBitRate = {
                            .Can_u8PropSeg = (uint8)3U,
                            .Can_u8PhaseSeg1 = (uint8)2U,
                            .Can_u16Prescaler = (uint16)3U,
                            .Can_u8PhaseSeg2 = (uint8)1U,         
                            .Can_u8ResyncJumpWidth = (uint8)1U
                           },
        .Can_bTrcvDelayEnable = (boolean)FALSE,
        .Can_u8TrcvDelayCompOffset = (uint8)0U
    }
};
/**
*   @brief  HwObject's pointer structure of CanController_2
*/
static TT_CONST Can_HwObjectConfigType * TT_CONST Can_apHwObject_Ctrl2[2U]=
{
    &Can_aHwObjectConfig[2U],
    &Can_aHwObjectConfig[5U]
};

/**
*   @brief  Can Controller Config
*/
TT_CONST Can_ControllerConfigType Can_aControllerConfig[CAN_CONTROLLER_CONFIG_COUNT]=
{
    {
        /* Abstracted CanIf Controller ID */
        .Can_u8AbstControllerID = (uint8)0U,
        /* Controller ID */
        .Can_u8ControllerID = (uint8)0U,
        /* Controller Offset */
        .Can_u8ControllerOffset = (uint8)2U,
        /* Controller Activation */
        .Can_bActivation = (boolean)TRUE,
        /* Bus Off uses polling */
        .Can_bBusOffUsesPolling = (boolean)FALSE,
        /** @brief Tx Priority */
        .Tx_Priority = CAN_TX_PRIORITY_LOW_NUMBER,
        /** @brief Rx Priority */
        .Rx_Priority = CAN_RX_PRIORITY_RXFIFO_TO_MB,
        /* --- Default values when Legacy FIFO is not available --- */
        /* Global mask of Legacy FIFO */
        .Can_u32LegacyGlobalMask = (uint32)0xFFFFFFFFU,
        /* ID Acceptance Mode */
        .Can_eLegacyAcceptanceMode = CAN_LEGACY_FIFO_FORMAT_A,
        /* Legacy FIFO Warning Notification */
        .Can_pLegacyFiFoWarnNotif = NULL_PTR,
        /* Legacy FIFO Overflow Notification */
        .Can_pLegacyFiFoOvfNotif = NULL_PTR,
        /* Enhanced FIFO Overflow Notification */
        .Can_pEnhanceFiFoOvfNotif = NULL_PTR,
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* Enhance FIFO Dma Error Notification */
        .Can_pDmaErrorNotif = NULL_PTR,
        /* DMA is not enabled */
        .pDmaDstAddr = NULL_PTR,
#endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        /* Error interrupt enable */
        .bErrEn = (boolean)TRUE,
        /* Error Notification */
        .Can_pErrNotif = Can0_ErrorNotify,
        /* Error FD Notification */
        .Can_pFDErrNotif = NULL_PTR,
        /* Default Baudrate ID */
        .Can_u16DefaultBaudrateID = (uint16)0U,
        /* Baudrate config Count*/
        .Can_u16BaudrateConfigCount = (uint16)1U,
        /* Baudrate config Pointer Structure */
        .Can_pBaudrateConfig = Can_aBaudrateConfig_Ctrl0,
        /* Pointer to DRV structure to HW config */
        .HwChannelIpConfig = &CanIpwHwChannelConfig0,
        /* Hw Object reference count */
        .Can_u8HwObjectRefCount = (uint8)2U,
        /* Pointer point to Group of Hw Object that refer to Controller */
        .Can_ppHwObject = Can_apHwObject_Ctrl0
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
            ,.CanTxTimestampNotification = NULL_PTR,
            .CanRxTimestampNotification = NULL_PTR
        #endif
    },
    {
        /* Abstracted CanIf Controller ID */
        .Can_u8AbstControllerID = (uint8)1U,
        /* Controller ID */
        .Can_u8ControllerID = (uint8)1U,
        /* Controller Offset */
        .Can_u8ControllerOffset = (uint8)1U,
        /* Controller Activation */
        .Can_bActivation = (boolean)TRUE,
        /* Bus Off uses polling */
        .Can_bBusOffUsesPolling = (boolean)FALSE,
        /** @brief Tx Priority */
        .Tx_Priority = CAN_TX_PRIORITY_LOW_NUMBER,
        /** @brief Rx Priority */
        .Rx_Priority = CAN_RX_PRIORITY_RXFIFO_TO_MB,
        /* --- Default values when Legacy FIFO is not available --- */
        /* Global mask of Legacy FIFO */
        .Can_u32LegacyGlobalMask = (uint32)0xFFFFFFFFU,
        /* ID Acceptance Mode */
        .Can_eLegacyAcceptanceMode = CAN_LEGACY_FIFO_FORMAT_A,
        /* Legacy FIFO Warning Notification */
        .Can_pLegacyFiFoWarnNotif = NULL_PTR,
        /* Legacy FIFO Overflow Notification */
        .Can_pLegacyFiFoOvfNotif = NULL_PTR,
        /* Enhanced FIFO Overflow Notification */
        .Can_pEnhanceFiFoOvfNotif = NULL_PTR,
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* Enhance FIFO Dma Error Notification */
        .Can_pDmaErrorNotif = NULL_PTR,
        /* DMA is not enabled */
        .pDmaDstAddr = NULL_PTR,
#endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        /* Error interrupt enable */
        .bErrEn = (boolean)TRUE,
        /* Error Notification */
        .Can_pErrNotif = Can1_ErrorNotify,
        /* Error FD Notification */
        .Can_pFDErrNotif = NULL_PTR,
        /* Default Baudrate ID */
        .Can_u16DefaultBaudrateID = (uint16)0U,
        /* Baudrate config Count*/
        .Can_u16BaudrateConfigCount = (uint16)1U,
        /* Baudrate config Pointer Structure */
        .Can_pBaudrateConfig = Can_aBaudrateConfig_Ctrl1,
        /* Pointer to DRV structure to HW config */
        .HwChannelIpConfig = &CanIpwHwChannelConfig1,
        /* Hw Object reference count */
        .Can_u8HwObjectRefCount = (uint8)2U,
        /* Pointer point to Group of Hw Object that refer to Controller */
        .Can_ppHwObject = Can_apHwObject_Ctrl1
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
            ,.CanTxTimestampNotification = NULL_PTR,
            .CanRxTimestampNotification = NULL_PTR
        #endif
    },
    {
        /* Abstracted CanIf Controller ID */
        .Can_u8AbstControllerID = (uint8)2U,
        /* Controller ID */
        .Can_u8ControllerID = (uint8)2U,
        /* Controller Offset */
        .Can_u8ControllerOffset = (uint8)4U,
        /* Controller Activation */
        .Can_bActivation = (boolean)TRUE,
        /* Bus Off uses polling */
        .Can_bBusOffUsesPolling = (boolean)FALSE,
        /** @brief Tx Priority */
        .Tx_Priority = CAN_TX_PRIORITY_LOW_NUMBER,
        /** @brief Rx Priority */
        .Rx_Priority = CAN_RX_PRIORITY_RXFIFO_TO_MB,
        /* --- Default values when Legacy FIFO is not available --- */
        /* Global mask of Legacy FIFO */
        .Can_u32LegacyGlobalMask = (uint32)0xFFFFFFFFU,
        /* ID Acceptance Mode */
        .Can_eLegacyAcceptanceMode = CAN_LEGACY_FIFO_FORMAT_A,
        /* Legacy FIFO Warning Notification */
        .Can_pLegacyFiFoWarnNotif = NULL_PTR,
        /* Legacy FIFO Overflow Notification */
        .Can_pLegacyFiFoOvfNotif = NULL_PTR,
        /* Enhanced FIFO Overflow Notification */
        .Can_pEnhanceFiFoOvfNotif = NULL_PTR,
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* Enhance FIFO Dma Error Notification */
        .Can_pDmaErrorNotif = NULL_PTR,
        /* DMA is not enabled */
        .pDmaDstAddr = NULL_PTR,
#endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        /* Error interrupt enable */
        .bErrEn = (boolean)TRUE,
        /* Error Notification */
        .Can_pErrNotif = Can6_ErrorNotify,
        /* Error FD Notification */
        .Can_pFDErrNotif = NULL_PTR,
        /* Default Baudrate ID */
        .Can_u16DefaultBaudrateID = (uint16)0U,
        /* Baudrate config Count*/
        .Can_u16BaudrateConfigCount = (uint16)1U,
        /* Baudrate config Pointer Structure */
        .Can_pBaudrateConfig = Can_aBaudrateConfig_Ctrl2,
        /* Pointer to DRV structure to HW config */
        .HwChannelIpConfig = &CanIpwHwChannelConfig2,
        /* Hw Object reference count */
        .Can_u8HwObjectRefCount = (uint8)2U,
        /* Pointer point to Group of Hw Object that refer to Controller */
        .Can_ppHwObject = Can_apHwObject_Ctrl2
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
            ,.CanTxTimestampNotification = NULL_PTR,
            .CanRxTimestampNotification = NULL_PTR
        #endif
    }
};


static TT_CONST Can_ControllerConfigType * TT_CONST Can_apController[CAN_CONTROLLER_CONFIG_COUNT]=
{
    &Can_aControllerConfig[0U],
    &Can_aControllerConfig[1U],
    &Can_aControllerConfig[2U]
};


/******************************************************************************
*                            Public Constants
*******************************************************************************/
/**
*   @brief  Top level structure contain all Can driver Config
*/
/* @violates @ref Can_PBcfg_c_REF_3 MISRA 2012 Advisory Rule 8.7 */
/* @violates @ref Can_PBcfg_c_REF_4 MISRA 2012 Advisory Rule 8.9 */
/* @violates @ref Can_PBcfg_c_REF_5 MISRA 2012 Required Rule 8.4 */
TT_CONST Can_ConfigType Can_Config =
{
    /* Configuration Core ID */
    .Can_u32CoreID = (uint32)0U,
    /* The HTH first Index after HRH consecutive */
    .Can_uHthFirstIndex = (Can_HwHandleType)3U,
    /* Mapping Controller ID to Controller Hw Offset */
    .Can_pCtrlOffsetToCtrlIDMap = Can_aCtrlOffsetToCtrlIDMap,
    /* Mapping Controller ID to Hardware Object ID */
    .Can_pHwObjIDToCtrlIDMap = Can_aHwObjIDToCtrlIDMap,
    /* Pointer point to Can Hw Object Con fig */
    .Can_pHwObjectConfig = Can_aHwObjectConfig,
    /* Array of Pointer to Controller infomation have aligned by Controller ID */
    .Can_ppController = Can_apController
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_PBcfg_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

