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
**  FILENAME     : Can_Hw_Wrapper.h                                           **
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

#ifndef CAN_HW_WRAPPER_H_
#define CAN_HW_WRAPPER_H_

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Hw_Types.h"

#if defined(MCAL_ENABLE_USER_MODE_SUPPORT) && (FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT == STD_OFF)
#include "Base_Internal.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define FLEXCAN_HW_WRAPPER_VENDOR_ID_H                      1541
#define FLEXCAN_HW_WRAPPER_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_HW_WRAPPER_AR_RELEASE_MINOR_VERSION_H       4
#define FLEXCAN_HW_WRAPPER_AR_RELEASE_PATCH_VERSION_H       0
#define FLEXCAN_HW_WRAPPER_SW_MAJOR_VERSION_H               1
#define FLEXCAN_HW_WRAPPER_SW_MINOR_VERSION_H               1
#define FLEXCAN_HW_WRAPPER_SW_PATCH_VERSION_H               0
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and Can_Hw_Types header file are of the same vendor */
#if (FLEXCAN_HW_WRAPPER_VENDOR_ID_H != FLEXCAN_HW_TYPES_VENDOR_ID_H)
    #error "Can_Hw_Wrapper.h and Can_Hw_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Hw_Types header file are of the same Autosar version */
#if ((FLEXCAN_HW_WRAPPER_AR_RELEASE_MAJOR_VERSION_H != FLEXCAN_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_WRAPPER_AR_RELEASE_MINOR_VERSION_H != FLEXCAN_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_WRAPPER_AR_RELEASE_PATCH_VERSION_H != FLEXCAN_HW_TYPES_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw_Wrapper.h and Can_Hw_Types.h are different"
#endif
/* Check if current file and Can_Hw_Types header file are of the same Software version */
#if ((FLEXCAN_HW_WRAPPER_SW_MAJOR_VERSION_H != FLEXCAN_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_WRAPPER_SW_MINOR_VERSION_H != FLEXCAN_HW_TYPES_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_WRAPPER_SW_PATCH_VERSION_H != FLEXCAN_HW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw_Wrapper.h and Can_Hw_Types.h are different"
#endif

#if defined(MCAL_ENABLE_USER_MODE_SUPPORT) && (FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT == STD_OFF)
/* Check if current file and Base_Internal header file are of the same vendor */
#if (FLEXCAN_HW_WRAPPER_VENDOR_ID_H != BASE_INTERNAL_VENDOR_ID_H)
    #error "Can_Hw_Wrapper.h and Base_Internal.h have different vendor ids"
#endif
/* Check if current file and Base_Internal header file are of the same Autosar version */
#if ((FLEXCAN_HW_WRAPPER_AR_RELEASE_MAJOR_VERSION_H != BASE_INTERNAL_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_WRAPPER_AR_RELEASE_MINOR_VERSION_H != BASE_INTERNAL_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_HW_WRAPPER_AR_RELEASE_PATCH_VERSION_H != BASE_INTERNAL_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Hw_Wrapper.h and Base_Internal.h are different"
#endif
/* Check if current file and Base_Internal header file are of the same Software version */
#if ((FLEXCAN_HW_WRAPPER_SW_MAJOR_VERSION_H != BASE_INTERNAL_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_HW_WRAPPER_SW_MINOR_VERSION_H != BASE_INTERNAL_SW_MINOR_VERSION_H) || \
     (FLEXCAN_HW_WRAPPER_SW_PATCH_VERSION_H != BASE_INTERNAL_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Hw_Wrapper.h and Base_Internal.h are different"
#endif
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#if defined(MCAL_ENABLE_USER_MODE_SUPPORT) && (FLEXCAN_HW_ENABLE_USER_MODE_SUPPORT == STD_OFF)
        #define Call_Can_Hw_SetIpUserMode(Flexcan_Hw_u8Instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param(Can_Hw_SetIpUserMode, Flexcan_Hw_u8Instance))
        #define Call_Can_Hw_SetIpPrivilegeMode(Flexcan_Hw_u8Instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param(Can_Hw_SetIpPrivilegeMode, Flexcan_Hw_u8Instance))

        #define Call_FlexCAN_Hw_Init(Flexcan_Hw_u8Instance, Flexcan_Hw_pState, Flexcan_Hw_pData) \
                ((TT_RetType)Base_Trusted_Call_Return3param((uint32)Can_Hw_Init_Privileged, Flexcan_Hw_u8Instance, Flexcan_Hw_pState, Flexcan_Hw_pData))

        #define Call_Can_Hw_ConfigRxFifo(instance, id_format, id_filter_table) \
                ((TT_RetType)Base_Trusted_Call_Return3param((uint32)Can_Hw_ConfigRxFifo_Privileged, instance, id_format, id_filter_table))

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        #define Call_Can_Hw_ConfigEnhancedRxFifo(instance, id_filter_table) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_ConfigEnhancedRxFifo_Privileged, instance, id_filter_table))
#endif

        #define Call_Can_Hw_MainFuncBusOff(instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_MainFuncBusOff_Privileged, instance))

        #define Call_Can_Hw_GetStopMode(instance, result) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_GetStopMode_Privileged, instance, result))

        #define Call_Can_Hw_GetStartMode(instance, result) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_GetStartMode_Privileged, instance, result))

        #define Call_Can_Hw_EnterFrzMode(instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_EnterFrzMode_Privileged, instance))

        #define Call_Can_Hw_ExitFreezeMode(instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_ExitFreezeMode_Privileged, instance))

        #define Call_Can_Hw_SetRxFifoGlMsk(instance, mask) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_SetRxFifoGlMsk_Privileged, instance, mask))

        #define Call_Can_Hw_Deinit(instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_Deinit_Privileged, instance))

        #define Call_Can_Hw_SetStartMode(instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_SetStartMode_Privileged, instance))

        #define Call_Can_Hw_SetStopMode(instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_SetStopMode_Privileged, instance))

        #define Call_Can_Hw_SetRxMaskType(instance, type) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_SetRxMaskType_Privileged, instance, type))

        #define Call_Can_Hw_SetRxMb14Mask(instance, mask) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_SetRxMb14Mask_Privileged, instance, mask))

        #define Call_Can_Hw_SetRxMb15Mask(instance, mask) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_SetRxMb15Mask_Privileged, instance, mask))

        #define Call_Can_Hw_SetRxMbGlbMask(instance, mask) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_SetRxMbGlbMask_Privileged, instance, mask))

        #define Call_Can_Hw_SetRxIndMask(instance, mb_idx, mask) \
                ((TT_RetType)Base_Trusted_Call_Return3param((uint32)Can_Hw_SetRxIndMask_Privileged, instance, mb_idx, mask))

        #define Call_Can_Hw_SetBitrateFD(instance, bitrate, bitRateSwitch) \
                ((TT_RetType)Base_Trusted_Call_Return3param((uint32)Can_Hw_SetBitrateFD_Privileged, instance, bitrate, bitRateSwitch))

        #define Call_Can_Hw_SetBitrate(instance, bitrate, enhExt) \
                ((TT_RetType)Base_Trusted_Call_Return3param((uint32)Can_Hw_SetBitrate_Privileged, instance, bitrate, enhExt))

        #define Call_Can_Hw_SetTxArbDelay(instance, value) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_SetTxArbDelay_Privileged, instance, value))

        #define Call_Can_Hw_SetTDCOffset(instance, enable, offset) \
                ((TT_RetType)Base_Trusted_Call_Return3param((uint32)Can_Hw_SetTDCOffset_Privileged, instance, enable, offset))

        #define Call_Can_Hw_EnInterrupts(u8Instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_EnInterrupts_Privileged, u8Instance))

        #define Call_Can_Hw_DisInterrupts(u8Instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_DisInterrupts_Privileged, u8Instance))

        #define Call_Can_Hw_SetErrorInt(u8Instance, type, enable) \
                ((TT_RetType)Base_Trusted_Call_Return3param((uint32)Can_Hw_SetErrorInt_Privileged, u8Instance, type, enable))

#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
        #define Call_Can_Hw_ConfigPN(u8Instance, bEnable, pPnConfig) \
                ((TT_RetType)Base_Trusted_Call_Return3param((uint32)Can_Hw_ConfigPN_Privileged, u8Instance, bEnable, pPnConfig))
#endif

        #define Call_Can_Hw_SetLisOnlyMode(instance, value) \
                ((TT_RetType)Base_Trusted_Call_Return2param((uint32)Can_Hw_SetLisOnlyMode_Privileged, instance, value))
#if    (FLEXCAN_HW_FEATURE_HAS_TS_ENABLE == STD_ON)
        #define Call_Can_Hw_CfgTimeStamp(instance) \
                ((TT_RetType)Base_Trusted_Call_Return1param((uint32)Can_Hw_CfgTimeStamp_Privileged, instance))
#endif
#else
        #define Call_Can_Hw_SetIpUserMode(Flexcan_Hw_u8Instance)                      Can_Hw_SetIpUserMode(Flexcan_Hw_u8Instance)
        #define Call_Can_Hw_SetIpPrivilegeMode(Flexcan_Hw_u8Instance)                 Can_Hw_SetIpPrivilegeMode(Flexcan_Hw_u8Instance)

        #define Call_FlexCAN_Hw_Init(Flexcan_Hw_u8Instance, Flexcan_Hw_pState, Flexcan_Hw_pData) \
                Can_Hw_Init_Privileged(Flexcan_Hw_u8Instance, Flexcan_Hw_pState, Flexcan_Hw_pData)

        #define Call_Can_Hw_ConfigRxFifo(instance, id_format, id_filter_table) \
                Can_Hw_ConfigRxFifo_Privileged(instance, id_format, id_filter_table)

#if (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        #define Call_Can_Hw_ConfigEnhancedRxFifo(instance, id_filter_table) \
                Can_Hw_ConfigEnhancedRxFifo_Privileged(instance, id_filter_table)
#endif

        #define Call_Can_Hw_MainFuncBusOff(instance) \
                Can_Hw_MainFuncBusOff_Privileged(instance)

        #define Call_Can_Hw_GetStopMode(instance, result) \
                Can_Hw_GetStopMode_Privileged(instance, result)

        #define Call_Can_Hw_GetStartMode(instance, result) \
                Can_Hw_GetStartMode_Privileged(instance, result)

        #define Call_Can_Hw_EnterFrzMode(instance) \
                Can_Hw_EnterFrzMode_Privileged(instance)

        #define Call_Can_Hw_ExitFreezeMode(instance) \
                Can_Hw_ExitFreezeMode_Privileged(instance)

        #define Call_Can_Hw_SetRxFifoGlMsk(instance, mask) \
                Can_Hw_SetRxFifoGlMsk_Privileged(instance, mask)

        #define Call_Can_Hw_Deinit(instance) \
                Can_Hw_Deinit_Privileged(instance)

        #define Call_Can_Hw_SetStartMode(instance) \
                Can_Hw_SetStartMode_Privileged(instance)

        #define Call_Can_Hw_SetStopMode(instance) \
                Can_Hw_SetStopMode_Privileged(instance)

        #define Call_Can_Hw_SetRxMaskType(instance, type) \
                Can_Hw_SetRxMaskType_Privileged(instance, type)

        #define Call_Can_Hw_SetRxMb14Mask(instance, mask) \
                Can_Hw_SetRxMb14Mask_Privileged(instance, mask)

        #define Call_Can_Hw_SetRxMb15Mask(instance, mask) \
                Can_Hw_SetRxMb15Mask_Privileged(instance, mask)

        #define Call_Can_Hw_SetRxIndMask(instance, mb_idx, mask) \
                Can_Hw_SetRxIndMask_Privileged(instance, mb_idx, mask)

        #define Call_Can_Hw_SetRxMbGlbMask(instance, mask) \
                Can_Hw_SetRxMbGlbMask_Privileged(instance, mask)

        #define Call_Can_Hw_SetBitrateFD(instance, bitrate, bitRateSwitch) \
                Can_Hw_SetBitrateFD_Privileged(instance, bitrate, bitRateSwitch)

        #define Call_Can_Hw_SetBitrate(instance, bitrate, enhExt) \
                Can_Hw_SetBitrate_Privileged(instance, bitrate, enhExt)

        #define Call_Can_Hw_SetTxArbDelay(instance, value) \
                Can_Hw_SetTxArbDelay_Privileged(instance, value)

        #define Call_Can_Hw_SetTDCOffset(instance, enable, offset) \
                Can_Hw_SetTDCOffset_Privileged(instance, enable, offset)

        #define Call_Can_Hw_EnInterrupts(u8Instance) \
                Can_Hw_EnInterrupts_Privileged(u8Instance)

        #define Call_Can_Hw_DisInterrupts(u8Instance) \
                Can_Hw_DisInterrupts_Privileged(u8Instance)

        #define Call_Can_Hw_SetErrorInt(u8Instance, type, enable) \
                Can_Hw_SetErrorInt_Privileged(u8Instance, type, enable)
#if (FLEXCAN_HW_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
        #define Call_Can_Hw_ConfigPN(u8Instance, bEnable, pPnConfig) \
                Can_Hw_ConfigPN_Privileged(u8Instance, bEnable, pPnConfig)
#endif

        #define Call_Can_Hw_SetLisOnlyMode(instance, value) \
                Can_Hw_SetLisOnlyMode_Privileged(instance, value)
#if    (FLEXCAN_HW_FEATURE_HAS_TS_ENABLE == STD_ON)
        #define Call_Can_Hw_CfgTimeStamp(instance) \
                Can_Hw_CfgTimeStamp_Privileged(instance)
#endif
#endif 
/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            FUNCTION PROTOTYPES
*******************************************************************************/

/**
* @brief        Set User Mode
* @details      Set User Mode
* @param[in]    Flexcan_Hw_u8Instance - Can Instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetIpUserMode(uint8 Flexcan_Hw_u8Instance);

/**
* @brief        Set Privilege Mode
* @details      Set Privilege Mode
* @param[in]    Flexcan_Hw_u8Instance - Can Instance
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetIpPrivilegeMode(uint8 Flexcan_Hw_u8Instance);

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
                                                TT_CONST Flexcan_Hw_ConfigType * Flexcan_Hw_pData);

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
                                        TT_CONST Flexcan_Hw_IdTableType * id_filter_table);

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
TT_RetType Can_Hw_ConfigEnhancedRxFifo_Privileged(uint8 instance,
                                                 TT_CONST Flexcan_Hw_EnhancedIdTableType * id_filter_table);
#endif /* (FLEXCAN_HW_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

/**
* @brief        Check if BusOff occurred
* @details      Check if BusOff occurred
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_MainFuncBusOff_Privileged(uint8 instance);

/**
* @brief        Check if the FlexCAN instance is STOPPED
* @details      Check if the FlexCAN instance is STOPPED
* @param[in]    instance - A CAN instance number
* @param[out]   result - Stop Mode result
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetStopMode_Privileged(uint8 instance, boolean * result);

/**
* @brief        Check if the CAN instance is STARTED
* @details      Check if the CAN instance is STARTED
* @param[in]    instance - A CAN instance number
* @param[out]   result - Start Mode result
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_GetStartMode_Privileged(uint8 instance, boolean *result);

/**
* @brief        Enter Driver In freeze Mode
* @details      Enter Driver In freeze Mode
* @param[in]    instance - A FlexCAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_EnterFrzMode_Privileged(uint8 instance);

/**
* @brief        Exit Driver from freeze Mode
* @details      Exit Driver from freeze Mode
* @param[in]    instance - A FlexCAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_ExitFreezeMode_Privileged(uint8 instance);

/**
* @brief        Set RxFifo Global Mask
* @details      Set RxFifo Global Mask
* @param[in]    instance - A CAN instance number
* @param[in]    mask - RxFifo Global Mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxFifoGlMsk_Privileged(uint8 instance,
                                                      uint32 mask);

/**
* @brief        Shutdown a CAN module
* @details      Shutdown a CAN module
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_Deinit_Privileged(uint8 instance);

/**
* @brief        Set the CAN instance in START mode
* @details      Set the CAN instance in START mode
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetStartMode_Privileged(uint8 instance);

/**
* @brief        Set the CAN instance in STOP mode
* @details      Set the CAN instance in STOP mode
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetStopMode_Privileged(uint8 instance);

/**
* @brief        Set RX masking type
* @details      Set RX masking type
* @param[in]    instance - A CAN instance number
* @param[in]    type - mask type
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxMaskType_Privileged(uint8 instance,
                               Flexcan_Hw_RxMaskType type);

/**
* @brief        Set Rx14Mask filter for message buffer 14
* @details      Set Rx14Mask filter for message buffer 14
* @param[in]    instance - A CAN instance number
* @param[in]    mask - Rx mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxMb14Mask_Privileged(uint8 instance, uint32 mask);

/**
* @brief        Set Rx15Mask filter for message buffer 15
* @details      Set Rx15Mask filter for message buffer 15
* @param[in]    instance - A CAN instance number
* @param[in]    mask - Rx mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxMb15Mask_Privileged(uint8 instance, uint32 mask);

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
TT_RetType Can_Hw_SetRxIndMask_Privileged(uint8 instance, uint8 mb_idx, uint32 mask);

/**
* @brief        Set Rx Message Buffer global mask as the mask value provided
* @details      Set Rx Message Buffer global mask as the mask value provided
* @param[in]    instance - A FlexCAN instance number
* @param[in]    mask - global mask
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetRxMbGlbMask_Privileged(uint8 instance, uint32 mask);

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
TT_RetType Can_Hw_SetBitrate_Privileged(uint8 instance,
                                                        TT_CONST Flexcan_Hw_TimeSegmentType * bitrate,
                                                        boolean enhExt);
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
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
TT_RetType Can_Hw_SetBitrateFD_Privileged(uint8 instance,
                                                        TT_CONST Flexcan_Hw_TimeSegmentType * bitrate,
                                                        boolean bitRateSwitch);

/**
* @brief        Set FlexCAN Tx Arbitration Start Delay
* @details      Set FlexCAN Tx Arbitration Start Delay
* @param[in]    instance - A CAN instance number
* @param[in]    value - Tx Arbitration Start Delay
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetTxArbDelay_Privileged(uint8 instance, uint8 value);

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
TT_RetType Can_Hw_SetTDCOffset_Privileged(uint8 instance,
                                              boolean enable,
                                              uint8 offset);

#endif /* FLEXCAN_HW_FEATURE_HAS_FD == STD_ON */

/**
* @brief        Enable all mb interrupts configured
* @details      Enable all mb interrupts configured
* @param[in]    u8Instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_EnInterrupts_Privileged(uint8 u8Instance);

/**
* @brief        Disable all mb interrupts configured
* @details      Disable all mb interrupts configured
* @param[in]    u8Instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_DisInterrupts_Privileged(uint8 u8Instance);

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
TT_RetType Can_Hw_SetErrorInt_Privileged(uint8 u8Instance,
                                             Flexcan_Hw_ErrorIntType type,
                                             boolean enable);

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
                                          TT_CONST Flexcan_Hw_PnConfigType * pPnConfig);
#endif

/**
* @brief        Set FlexCAN Listen Only
* @details      Set FlexCAN Listen Only
* @param[in]    instance - A CAN instance number
* @param[in]    enable - enable or disable Listen Only mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_SetLisOnlyMode_Privileged(uint8 instance, TT_CONST boolean enable);

#if    (FLEXCAN_HW_FEATURE_HAS_TS_ENABLE == STD_ON)
/**
* @brief        Timestamp configuration
* @details      Timestamp configuration
* @param[in]    instance - A CAN instance number
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
TT_RetType Can_Hw_CfgTimeStamp_Privileged(uint8 instance);
#endif

#endif /* FLEXCAN_HW_WRAPPER_H_ */
