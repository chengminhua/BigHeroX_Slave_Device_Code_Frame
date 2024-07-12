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
**  FILENAME     : Can_Drv.c                                                  **
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

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Can_Drv.h"
#include "Can_Irq.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_DRV_VENDOR_ID_C                    1541
#define CAN_DRV_MODULE_ID_C                    80
#define CAN_DRV_AR_RELEASE_MAJOR_VERSION_C     4
#define CAN_DRV_AR_RELEASE_MINOR_VERSION_C     4
#define CAN_DRV_AR_RELEASE_PATCH_VERSION_C     0
#define CAN_DRV_SW_MAJOR_VERSION_C             1
#define CAN_DRV_SW_MINOR_VERSION_C             1
#define CAN_DRV_SW_PATCH_VERSION_C             0
/**@}*/

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and Can_Drv.h are of the same vendor */
#if (CAN_DRV_VENDOR_ID_C != CAN_DRV_VENDOR_ID_H)
#error "Can_DRV.c and Can_DRV.h have different vendor ids"
#endif
#if (CAN_DRV_MODULE_ID_C != CAN_DRV_MODULE_ID_H)
    #error "Can_DRV.c and Can_DRV.h have different module ids"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_DRV_AR_RELEASE_MAJOR_VERSION_C != CAN_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_DRV_AR_RELEASE_MINOR_VERSION_C != CAN_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_DRV_AR_RELEASE_PATCH_VERSION_C != CAN_DRV_AR_RELEASE_PATCH_VERSION_H) \
    )
#error "AutoSar Version Numbers of Can_DRV.c and Can_DRV.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same software version */
#if ((CAN_DRV_SW_MAJOR_VERSION_C != CAN_DRV_SW_MAJOR_VERSION_H) || \
     (CAN_DRV_SW_MINOR_VERSION_C != CAN_DRV_SW_MINOR_VERSION_H) || \
     (CAN_DRV_SW_PATCH_VERSION_C != CAN_DRV_SW_PATCH_VERSION_H) \
    )
#error "Software Version Numbers of Can_DRV.c and Can_DRV.h are different"
#endif

/* Check if current file and Can_Irq.h are of the same vendor */
#if (CAN_DRV_VENDOR_ID_C != CAN_IRQ_VENDOR_ID_H)
#error "Can_DRV.c and Can_Irq.h have different vendor ids"
#endif
#if (CAN_DRV_MODULE_ID_C != CAN_IRQ_MODULE_ID_H)
    #error "Can_DRV.c and Can_Irq.h have different module ids"
#endif
/* Check if current file and Can_Irq.h are of the same Autosar version */
#if ((CAN_DRV_AR_RELEASE_MAJOR_VERSION_C != CAN_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_DRV_AR_RELEASE_MINOR_VERSION_C != CAN_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_DRV_AR_RELEASE_PATCH_VERSION_C != CAN_IRQ_AR_RELEASE_PATCH_VERSION_H) \
    )
#error "AutoSar Version Numbers of Can_DRV.c and Can_Irq.h are different"
#endif
/* Check if current file and Can_Irq.h are of the same software version */
#if ((CAN_DRV_SW_MAJOR_VERSION_C != CAN_IRQ_SW_MAJOR_VERSION_H) || \
     (CAN_DRV_SW_MINOR_VERSION_C != CAN_IRQ_SW_MINOR_VERSION_H) || \
     (CAN_DRV_SW_PATCH_VERSION_C != CAN_IRQ_SW_PATCH_VERSION_H) \
    )
#error "Software Version Numbers of Can_DRV.c and Can_Irq.h are different"
#endif

/******************************************************************************
*                            Private Macros
*******************************************************************************/
/* IDE Bit Mask */
#define CAN_DRV_CS_IDE_MASK                                 (0x00200000UL)
/* EDL Bit Mask */
#define CAN_DRV_CS_EDL_MASK                                 (0x80000000UL)
/* CODE Bit Mask */
#define CAN_DRV_CS_CODE_MASK                                (0x0F000000UL)
/* RXFIFO format A extended ID offset */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATA_EXT_SHIFT       (1U)
/* RXFIFO format A standard ID offset */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATA_STD_SHIFT       (19U)
/* RXFIFO format B extended ID offset1 */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATB_EXT_SHIFT1      (16U)
/* RXFIFO format B extended ID offset2 */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATB_EXT_SHIFT2      (0U)
/* RXFIFO format B standard ID offset1 */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATB_STD_SHIFT1      (19U)
/* RXFIFO format B standard ID offset2 */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATB_STD_SHIFT2      (3U)
/* RXFIFO format B extended ID CMP offset */
#define CAN_DRV_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT     (15U)
/* RXFIFO format C extended/standard ID offset1 */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT1  (24U)
/* RXFIFO format C extended/standard ID offset2 */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT2  (16U)
/* RXFIFO format C extended/standard ID offset3 */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT3  (8U)
/* RXFIFO format C extended/standard ID offset4 */
#define CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT4  (0U)
/* RXFIFO format C standard ID CMP offset */
#define CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT     (3U)
/* RXFIFO format C extended ID CMP offset */
#define CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT     (21U)
/* LEGACY RXFIFO MB HANDLER */
#define CAN_DRV_RX_LEGACY_FIFO_MB_HANDLER                   (0U)
/******************************************************************************
*                            Private Variables
*******************************************************************************/
#define CAN_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"
/**
*   @brief      Saving hardware state
*/
#if (CAN_CONTROLLER_CONFIG_COUNT >= 1U)
    static Flexcan_Hw_StateType Can_Drv_xStatus0;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 1U) */

#if (CAN_CONTROLLER_CONFIG_COUNT >= 2U)
    static Flexcan_Hw_StateType Can_Drv_xStatus1;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 2U) */

#if (CAN_CONTROLLER_CONFIG_COUNT >= 3U)
    static Flexcan_Hw_StateType Can_Drv_xStatus2;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 3U) */

#if (CAN_CONTROLLER_CONFIG_COUNT >= 4U)
    static Flexcan_Hw_StateType Can_Drv_xStatus3;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 4U) */

#if (CAN_CONTROLLER_CONFIG_COUNT >= 5U)
    static Flexcan_Hw_StateType Can_Drv_xStatus4;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 5U) */

#if (CAN_CONTROLLER_CONFIG_COUNT >= 6U)
    static Flexcan_Hw_StateType Can_Drv_xStatus5;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 6U) */

#if (CAN_CONTROLLER_CONFIG_COUNT >= 7U)
    static Flexcan_Hw_StateType Can_Drv_xStatus6;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 7U) */

#if (CAN_CONTROLLER_CONFIG_COUNT >= 8U)
    static Flexcan_Hw_StateType Can_Drv_xStatus7;
#endif
    
#define CAN_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"
    
#define CAN_START_SEC_CONST_FAST_UNSPECIFIED
#include "Can_MemMap.h"
/**
*   @brief      Saving hardware state
*/
#if (CAN_CONTROLLER_CONFIG_COUNT >= 1U)
    static Flexcan_Hw_StateType * TT_CONST Can_Drv_apxStatus[CAN_CONTROLLER_CONFIG_COUNT] =
    {
            &Can_Drv_xStatus0
#if (CAN_CONTROLLER_CONFIG_COUNT >= 2U)
            ,&Can_Drv_xStatus1
#endif
#if (CAN_CONTROLLER_CONFIG_COUNT >= 3U)
            ,&Can_Drv_xStatus2
#endif
#if (CAN_CONTROLLER_CONFIG_COUNT >= 4U)
            ,&Can_Drv_xStatus3
#endif
#if (CAN_CONTROLLER_CONFIG_COUNT >= 5U)
            ,&Can_Drv_xStatus4
#endif
#if (CAN_CONTROLLER_CONFIG_COUNT >= 6U)
            ,&Can_Drv_xStatus5
#endif
#if (CAN_CONTROLLER_CONFIG_COUNT >= 7U)
            ,&Can_Drv_xStatus6
#endif
#if (CAN_CONTROLLER_CONFIG_COUNT >= 8U)
            ,&Can_Drv_xStatus7
#endif
    };
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 1U) */

#define CAN_STOP_SEC_CONST_FAST_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_FAST_CLEARED_16
#include "Can_MemMap.h"

#if ((CAN_TX_POLLING_SUPPORT == STD_ON) || (CAN_MB_INTERRUPT_SUPPORT == STD_ON))
/**
* @brief     Store the the swPduHandle that is given inside the parameter PduInfo
*/
static PduIdType Can_Drv_au16TxPduId[CAN_CONTROLLER_CONFIG_COUNT][CAN_HWMB_COUNT];
#endif

#define CAN_STOP_SEC_VAR_FAST_CLEARED_16
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
/**
* @brief     Save mode state
*/
static Can_ListenOnlyType  Can_Drv_eListenOnlyMode[CAN_CONTROLLER_CONFIG_COUNT];
#endif /* #if (CAN_LISTEN_ONLY_MODE == STD_ON) */

#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_FAST_CLEARED_16
#include "Can_MemMap.h"
/**
* @brief     Mapping of mailbox indexes to hardware objects ID
*/
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    static Can_HwHandleType Can_Drv_au16MbIdxToObjIDMap[CAN_CONTROLLER_CONFIG_COUNT][CAN_HWMB_COUNT];
#endif

#define CAN_STOP_SEC_VAR_FAST_CLEARED_16
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_BOOLEAN
#include "Can_MemMap.h"
/**
* @brief     Save the interrupt enabled state
*/
static boolean Can_Drv_abIsInterruptEnabled[CAN_CONTROLLER_CONFIG_COUNT];
    
#define CAN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_16
#include "Can_MemMap.h"
/**
* @brief     Need to alocate a filter array with elemnets no as defined in HwObject
*/
static Flexcan_Hw_IdTableType RxFifoFilters[512];
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
static Flexcan_Hw_EnhancedIdTableType RxFifoFiltersEnhanced[128];
#endif

#define CAN_STOP_SEC_VAR_CLEARED_16
#include "Can_MemMap.h"
/******************************************************************************
*                            Public Constants
*******************************************************************************/
#define CAN_START_SEC_VAR_CLEARED_16
#include "Can_MemMap.h"
/**
* @brief     Save BaudrateID
*/
uint16 Can_au16BaudrateIDConfig[CAN_CONTROLLER_CONFIG_COUNT];

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/**
* @brief     Save Icom Index
*/
TT_CONST Can_IcomConfigsType * Can_apxCtrlConfigIcomIndex[CAN_CONTROLLER_CONFIG_COUNT];
#endif

#define CAN_STOP_SEC_VAR_CLEARED_16
#include "Can_MemMap.h"
/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
/**
* @brief        Can_Drv_PriParseData
* @details      Parse the received data
* @param[out]   CanIf_Mailbox - Contains the can controller and hardware object ID and CanID
* @param[out]   CanIf_PduInfo - Pdu information
* @param[in]    pReceivedDataBuffer - Can Received Data Buffer
* @param[in]    Can_pControllerConfig - Can Controller Config
* @param[in]    Can_pHwObjectConfig - Can Hardware Object Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriParseData
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Hw_MsgBuffType * pReceivedDataBuffer,
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,
    uint8 u8Sid
);

/**
* @brief        Can_Drv_PriSetControlerErrInit
* @details      Set Error Initialization and set Controller to start Mode
* @param[in]    Can_pControllerConfig - Can Controller Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriSetControlerErrInit(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);

/**
* @brief        Can_Drv_PriInitLegacyFifoFilter
* @details      Initialize Legacy RXFifo Filter
* @param[in]    Can_pController - Can Controller Config
* @param[in]    Can_pHwObject - Can Hardware Object Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriInitLegacyFifoFilter(TT_CONST Can_ControllerConfigType * Can_pController, TT_CONST Can_HwObjectConfigType * Can_pHwObject);

/**
* @brief        Can_Drv_PriProcessLegFifoPolling
* @details      Process Legacy RXFifo In Polling Mode
* @param[in]    CanIf_Mailbox - Contains the can controller and hardware object ID and CanID
* @param[in]    CanIf_PduInfo - Pdu information
* @param[in]    pReceivedDataBuffer - Can Received Data Buffer
* @param[in]    Can_pControllerConfig - Can Controller Config
* @param[in]    Can_pHwObjectConfig - Can Hardware Object Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
#if (CAN_RX_POLLING_SUPPORT == STD_ON)
static TT_RetType Can_Drv_PriProcessLegFifoPolling
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Hw_MsgBuffType * pReceivedDataBuffer,
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig
);

/**
* @brief        Can_Drv_PriProcessEnhFifoPolling
* @details      Process Enhanced RXFifo In Polling Mode
* @param[in]    CanIf_Mailbox - Contains the can controller and hardware object ID and CanID
* @param[in]    CanIf_PduInfo - Pdu information
* @param[in]    pReceivedDataBuffer - Can Received Data Buffer
* @param[in]    Can_pControllerConfig - Can Controller Config
* @param[in]    Can_pHwObjectConfig - Can Hardware Object Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
static TT_RetType Can_Drv_PriProcessEnhFifoPolling
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Hw_MsgBuffType * pReceivedDataBuffer,
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig
);
#endif /* (CAN_ENHANCED_FIFO_ENABLED == STD_ON) */
#endif /* (CAN_RX_POLLING_SUPPORT == STD_ON) */

/**
* @brief        Can_Drv_PriInitRx
* @details      Init all Rx objects
* @param[in]    Can_pController - Can Controller Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriInitRx(TT_CONST Can_ControllerConfigType * Can_pController);

/**
* @brief         Reports error if CAN_DEV_ERROR_DETECT == STD_ON.
* @details       Reports error if CAN_DEV_ERROR_DETECT == STD_ON
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        void
* @retval        None
*/
static void Can_Drv_PriParaCheck(bool Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal);
/**
* @brief         Reports Return Value error if CAN_DEV_ERROR_DETECT == STD_ON.
* @details       Reports Return Value error if CAN_DEV_ERROR_DETECT == STD_ON
* @param[in]     ApiId - Service Id of API
* @param[out]    ErrId - Error Id of Condition
* @return        void
* @retval        None
*/
static void Can_Drv_PriRetCheck(uint8 ApiId, TT_RetType *ErrId);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Init Check
* @details      InitCheck For Can After Can Init
* @param[in]    ConfigPtr - Pointing to configuration data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
*/
static TT_RetType Can_Drv_PriInitCheck(TT_CONST Can_ConfigType *ConfigPtr);
#endif

/**
* @brief         Determines if the controller is busy
* @details       Determines if the controller is busy
* @param[out]    bCtrlBusy - Save the controller busy result
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Other - fail
*/
static TT_RetType Can_Drv_PriIsControllersBusy(boolean *bCtrlBusy);

#ifndef USING_OS_AUTOSAROS
/**
* @brief         Determine the legitimacy of PDU
* @details       Determine the legitimacy of PDU
* @param[in]     Can_pController - Points to controller configuration data
* @param[in]     Can_pHwObject - Points to hardware object configuration data
* @param[in]     PduInfo - Pointer to SDU user memory, DLC and Identifier
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Other - fail
*/
static TT_RetType Can_Drv_PriValidatePdu(TT_CONST Can_ControllerConfigType * Can_pController, \
        TT_CONST Can_HwObjectConfigType * Can_pHwObject, \
        TT_CONST Can_PduType * PduInfo);
#endif

/**
* @brief        Can_Drv_PriInitControllers
* @details      Initialize Controller
* @param[in]    Can_pControllerConfig - Can Controller Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriInitControllers(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);

/**
* @brief        Can_Drv_PriDeInitControllers
* @details      De-Initialize Controller
* @param[in]    Can_pControllerConfig - Can Controller Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriDeInitControllers(TT_CONST Can_ControllerConfigType * Can_pControllerConfig);


/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"

/******************************************************************************
*  Service name     : Can_Drv_Init
*  Syntax           : TT_RetType Can_Drv_Init(TT_CONST Can_ConfigType * Config)
*  Service ID       : 100
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Config - Pointer to driver configuration
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Initialize the CAN driver
******************************************************************************/
TT_RetType Can_Drv_Init(TT_CONST Can_ConfigType * Config)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    boolean bCtrlBusy = FALSE;
    uint8 u8ControllerID = 0U;
    TT_CONST Can_ControllerConfigType * Can_pController = NULL_PTR;
#ifndef USING_OS_AUTOSAROS
#if (CAN_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != Config)
#else
    if (NULL_PTR == Config)
#endif
    {
        Can_Drv_PriParaCheck((TRUE), CAN_DRV_SI_INIT, TT_RET_PARAM_INVALID_PTR_ERR,&TTRetVal);
    }
    else
    {
#if (CAN_PRECOMPILE_SUPPORT == STD_ON)
        /* Update config pointer with default configuration if precompile support on. */
        Can_apxConfig = &Can_Config;
        (void)Config; /* Prevent compiler warning */
#else
        /* Copy pointer to current Can Driver configuration. */
        Can_apxConfig = Config;
#endif /* (CAN_PRECOMPILE_SUPPORT == STD_ON) */
#else
        (void)Config; /* Prevent compiler warning */
#endif

        TTRetVal = Can_Drv_PriIsControllersBusy(&bCtrlBusy);

        if((TT_RET_SUCCESS == TTRetVal) && (FALSE == bCtrlBusy))
        {
            /* Loop through all Can controllers configured based CanControllerId parameter. */
            for(u8ControllerID = 0U; u8ControllerID < CAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
            {
                Can_pController = Can_apxConfig->Can_ppController[u8ControllerID];
                /* The initialization is skipped for the controllers that are not enabled. */
                if(TRUE == Can_pController->Can_bActivation)
                {
                    /*
                     *   [SWS_Can_00250] The function Can_Init shall initialize: static variables, including flags,
                     *   Common setting for the complete CAN HW unit, CAN controller specific settings for each CAN controller.
                     *
                     *   [SWS_Can_00245] The function Can_Init shall initialize all CAN controllers according to their configuration.
                     *
                     *   [SWS_Can_00053] Can_Init shall not change registers of CAN controller Hardware resources that are not used.
                     */
                    /* Init the controller */
                    TTRetVal = Can_Drv_PriInitControllers(Can_pController);
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                        Can_apxCtrlConfigIcomIndex[u8ControllerID] = NULL_PTR;
#endif
                        Can_eControllerState[u8ControllerID] = CAN_CS_STOPPED;
#ifndef USING_OS_AUTOSAROS
                        TTRetVal = Can_Drv_SetControllerToStartMode(Can_pController);
                        if(TT_RET_SUCCESS != TTRetVal)
                        {
                            bCtrlBusy = TRUE;
                            break;
                        }
                        else
                        {

                        }
#endif
                    }
                    else
                    {
                        bCtrlBusy = TRUE;
                        break;
                    }
                }
                else
                {
                    /* do nothing */
                }
            }

            /*
             *  [SWS_Can_00246] After initializing all controllers inside the HW Unit, the function Can_Init
             *   shall change the module state to CAN_READY.
             */
            if(TRUE == bCtrlBusy)
            {
                /* Init failed due to one or more controllers failed, reset status of all  core's current controllers */
                for (u8ControllerID = 0U; u8ControllerID < CAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
                {
                    if((NULL_PTR != Can_apxConfig) \
                            &&(NULL_PTR != Can_apxConfig->Can_ppController[u8ControllerID]))
                    {
                        Can_eControllerState[u8ControllerID] = CAN_CS_UNINIT;
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

        }
#ifndef USING_OS_AUTOSAROS
    }
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    if(E_OK == TTRetVal)
    {
        TTRetVal = Can_Drv_PriInitCheck(Can_apxConfig);
    }
    else
    {
        /* do nothing */
    }
#endif

    return TTRetVal;
}

/******************************************************************************
*  Service name     : Can_Drv_DeInit
*  Syntax           : TT_RetType Can_Drv_DeInit(void)
*  Service ID       : 101
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Can_DeInit_Activity
******************************************************************************/
TT_RetType Can_Drv_DeInit(void)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    uint8 u8ControllerID = 0U;
    TT_CONST Can_ControllerConfigType * Can_pController = NULL_PTR;
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_DEINIT, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);
#ifndef USING_OS_AUTOSAROS
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* Loop through all Can controllers configured based CanControllerId parameter. */
        for (u8ControllerID = 0U; u8ControllerID < CAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
        {
            if(NULL_PTR != Can_apxConfig->Can_ppController[u8ControllerID])
            {
                if(CAN_CS_STARTED == Can_eControllerState[u8ControllerID])
                {
                    TTRetVal = TT_RET_STATUS_TRANSITION_ERR;
                    /* Skipping the loop if any of Can Controller is in state STARTED */
                    break;
                }
                else
                {

                }
            }
            else
            {

            }
        }
#endif
        /* Loop through all Can controllers configured based CanControllerId parameter. */
        for(u8ControllerID = 0U; ((u8ControllerID < CAN_CONTROLLER_CONFIG_COUNT) && (TT_RET_SUCCESS == TTRetVal)); u8ControllerID++)
        {
            if(NULL_PTR != Can_apxConfig->Can_ppController[u8ControllerID])
            {
                Can_pController = Can_apxConfig->Can_ppController[u8ControllerID];
                /* The initialization is skipped for the controllers that are not enabled. */
                if(TRUE == Can_pController->Can_bActivation)
                {
                    Can_eControllerState[u8ControllerID] = CAN_CS_UNINIT;
                    TTRetVal = Can_Drv_PriDeInitControllers(Can_pController);
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
#ifndef USING_OS_AUTOSAROS
        if(TT_RET_SUCCESS == TTRetVal)
        {
            Can_apxConfig = NULL_PTR;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {

    }
#endif

    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (CAN_ABORT_MB_API == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_AbortMb
*  Syntax           : TT_RetType Can_Drv_AbortMb(Can_HwHandleType Hth)
*  Service ID       : 120
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Hth - HW-transmit handler
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Abort outstanding transmissions
******************************************************************************/
TT_RetType Can_Drv_AbortMb(Can_HwHandleType Hth)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig = NULL_PTR;
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig = NULL_PTR;
    uint8 u8ControllerID = 0U;
    uint8 u8Idx=0U;

#ifndef USING_OS_AUTOSAROS
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_ABORT_MB, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);
    Can_Drv_PriParaCheck(((Hth >= ((Can_HwHandleType)CAN_HWOBJECT_CONFIG_COUNT))
            || (Hth < Can_apxConfig->Can_uHthFirstIndex)), CAN_DRV_SI_ABORT_MB, TT_RET_PARAM_INDEX_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {

        u8ControllerID = Can_apxConfig->Can_pHwObjIDToCtrlIDMap[Hth];
        Can_pControllerConfig = Can_apxConfig->Can_ppController[u8ControllerID];
        Can_pHwObjectConfig = &(Can_apxConfig->Can_pHwObjectConfig[Hth]);

        Can_Drv_PriParaCheck((CAN_CS_STARTED != Can_eControllerState[u8ControllerID]), CAN_DRV_SI_ABORT_MB, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

        if(TT_RET_SUCCESS == TTRetVal)
        {
#else
            u8ControllerID = Can_apxConfig->Can_pHwObjIDToCtrlIDMap[Hth];
            Can_pControllerConfig = Can_apxConfig->Can_ppController[u8ControllerID];
            Can_pHwObjectConfig = &(Can_apxConfig->Can_pHwObjectConfig[Hth]);
#endif
            Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
                    || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_ABORT_MB, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

            if(TT_RET_SUCCESS == TTRetVal)
            {
                do
                {
                    /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
                    TTRetVal = Can_Hw_AbortTransfer(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8Idx);
                    if(TT_RET_SUCCESS != TTRetVal)
                    {
                        break;
                    }
                    else
                    {
                        u8Idx++;
                    }

                }while (u8Idx < Can_pHwObjectConfig->Can_u8ObjectCount);
                Can_Drv_PriRetCheck(CAN_DRV_SI_ABORT_MB, &TTRetVal);
            }
            else
            {

            }
#ifndef USING_OS_AUTOSAROS
        }
        else
        {

        }
    }
    else
    {

    }
#endif
    return TTRetVal;
}
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/******************************************************************************
*  Service name     : Can_Drv_SetBaudrate
*  Syntax           : TT_RetType Can_Drv_SetBaudrate(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint16 BaudRateConfigID)
*  Service ID       : 102
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant (For the same controller)
*  Parameters (in)  : Can_pControllerConfig - Controller Config
*  Parameters (in)  : BaudRateConfigID - BaudRateConfig ID
*  Return value     : TT_RetType
*  Description      : This function set baudrate
******************************************************************************/
#if (CAN_SET_BAUDRATE_API == STD_ON)
TT_RetType Can_Drv_SetBaudrate(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint16 BaudRateConfigID)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_TimeSegmentType FlexCANTimeSeg = {0};

#ifndef USING_OS_AUTOSAROS
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_SET_BAUDRATE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        Can_Drv_PriParaCheck((BaudRateConfigID >= Can_pControllerConfig->Can_u16BaudrateConfigCount), CAN_DRV_SI_SET_BAUDRATE, TT_RET_PARAM_LEN_ERR, &TTRetVal);
    }
    else
    {
        /* do nothing */
    }

    if(TT_RET_SUCCESS == TTRetVal)
    {
        if (CAN_CS_STOPPED == Can_eControllerState[Can_pControllerConfig->Can_u8ControllerOffset])
        {
#endif
            Can_au16BaudrateIDConfig[Can_pControllerConfig->Can_u8ControllerID] = BaudRateConfigID;
            /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */

            TTRetVal = Can_Hw_EnterFrzMode(Can_pControllerConfig->Can_u8ControllerOffset);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                FlexCANTimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u16Prescaler;


                FlexCANTimeSeg.propSeg    = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PropSeg;
                FlexCANTimeSeg.phaseSeg1  = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PhaseSeg1;
                FlexCANTimeSeg.phaseSeg2  = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8PhaseSeg2;
                FlexCANTimeSeg.rJumpwidth = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_NominalBitRate.Can_u8ResyncJumpWidth;

                TTRetVal = Can_Hw_SetBitrate(Can_pControllerConfig->Can_u8ControllerOffset, &FlexCANTimeSeg, Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bEnhanceCBTEnable);

                if((TRUE == Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bFDFrame) && (TT_RET_SUCCESS == TTRetVal))
                {
                    FlexCANTimeSeg.preDivider = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u16Prescaler;

                    FlexCANTimeSeg.propSeg    = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PropSeg;
                    FlexCANTimeSeg.phaseSeg1  = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PhaseSeg1;
                    FlexCANTimeSeg.phaseSeg2  = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8PhaseSeg2;
                    FlexCANTimeSeg.rJumpwidth = Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_DataBitRate.Can_u8ResyncJumpWidth;

                    TTRetVal = Can_Hw_SetBitrateFD(Can_pControllerConfig->Can_u8ControllerOffset, &FlexCANTimeSeg, Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bBitRateSwitch);
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        TTRetVal = Can_Hw_SetTDCOffset(Can_pControllerConfig->Can_u8ControllerOffset, \
                                Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_bTrcvDelayEnable, \
                                Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_u8TrcvDelayCompOffset \
                        );
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
                    TTRetVal = Can_Hw_SetTxArbDelay(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->Can_pBaudrateConfig[BaudRateConfigID].Can_u8TxArbitrationStartDelay);
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        TTRetVal = Can_Hw_SetStopMode(Can_pControllerConfig->Can_u8ControllerOffset);
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
            Can_Drv_PriRetCheck(CAN_DRV_SI_SET_BAUDRATE, &TTRetVal);
#ifndef USING_OS_AUTOSAROS
        }
        else
        {
             TTRetVal = TT_RET_STATUS_UNINIT_ERR;
        }
    }
    else
    {

    }
#endif
    return TTRetVal;
}
#endif /* CAN_SET_BAUDRATE_API == STD_ON */

/******************************************************************************
*  Service name     : Can_Drv_SetControllerToStartMode
*  Syntax           : TT_RetType Can_Drv_SetControllerToStartMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 103
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Set Controller to participate the CAN network
******************************************************************************/
TT_RetType Can_Drv_SetControllerToStartMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    uint8 u8HwObjRefIdx = 0U;
    TT_CONST Can_HwObjectConfigType * Can_pHwObject = NULL_PTR;
#endif /* (CAN_MB_INTERRUPT_SUPPORT == STD_ON) */
    TT_RetType TTRetVal = TT_RET_SUCCESS;

    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_SET_CONTROLLER_TO_START_MODE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_SET_CONTROLLER_TO_START_MODE, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
#if (CAN_LISTEN_ONLY_MODE == STD_ON)
        if (LISTEN_ONLY_MODE == Can_Drv_eListenOnlyMode[Can_pControllerConfig->Can_u8ControllerID])
        {
            TTRetVal = Can_Hw_SetLisOnlyMode(Can_pControllerConfig->Can_u8ControllerOffset, TRUE);
        }
        else
        {

        }
        if(TT_RET_SUCCESS == TTRetVal)
        {
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
            for (u8HwObjRefIdx = 0U; ((u8HwObjRefIdx < Can_pControllerConfig->Can_u8HwObjectRefCount) && (TT_RET_SUCCESS == TTRetVal)); u8HwObjRefIdx++)
            {
                Can_pHwObject = (TT_CONST Can_HwObjectConfigType *)Can_pControllerConfig->Can_ppHwObject[u8HwObjRefIdx];

                if (FALSE == Can_pHwObject->Can_bHwObjectUsesPolling)
                {
                    switch (Can_pHwObject->Can_eReceiveType)
                    {
                    case CAN_RX_NORMAL:
                        TTRetVal = Can_Hw_Receive(Can_pControllerConfig->Can_u8ControllerOffset, \
                                Can_pHwObject->Can_u8HwBufferIndex, \
                                NULL_PTR, \
                                Can_pHwObject->Can_bHwObjectUsesPolling);
                        break;

                    case CAN_RX_ENHANCED_FIFO: /* Just like the legacy RX FIFO  */

                    case CAN_RX_LEGACY_FIFO:
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
                        if (FLEXCAN_RXFIFO_USING_DMA == Can_pControllerConfig->HwChannelIpConfig->pFlexcanIpHwConfig->transfer_type)
                        {
                            TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
                        }
                        else
#endif
                        {
                            TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, NULL_PTR);
                        }
                        break;

                    default:
                        /* do nothing */
                        break;
                    }
                }
                else
                {

                }
            }
            if(TT_RET_SUCCESS == TTRetVal)
            {
#endif /* CAN_MB_INTERRUPT_SUPPORT == STD_ON */
                TTRetVal = Can_Drv_PriSetControlerErrInit(Can_pControllerConfig);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    Can_eControllerState[Can_pControllerConfig->Can_u8ControllerID] = CAN_CS_STARTED;
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                    Can_apxCtrlConfigIcomIndex[Can_pControllerConfig->Can_u8ControllerID] = NULL_PTR;
#endif
                }
                else
                {

                }
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
            }
            else
            {
                Can_Drv_PriRetCheck(CAN_DRV_SI_SET_CONTROLLER_TO_START_MODE, &TTRetVal);
            }
#endif /* CAN_MB_INTERRUPT_SUPPORT == STD_ON */
#if (CAN_LISTEN_ONLY_MODE == STD_ON)
        }
        else
        {
            Can_Drv_PriRetCheck(CAN_DRV_SI_SET_CONTROLLER_TO_START_MODE, &TTRetVal);
        }
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */
    }
    else
    {

    }
    return TTRetVal;
}

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_ListenOnlyMode
*  Syntax           : TT_RetType Can_Drv_ListenOnlyMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_ListenOnlyType State)
*  Service ID       : 104
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : State - Listen Only Mode Or Normal Mode
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Enable or disable Listen Only Mode
******************************************************************************/
TT_RetType Can_Drv_ListenOnlyMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_ListenOnlyType State)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_SET_LISTEN_ONLY_MODE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        switch (State)
        {
        case NORMAL_MODE:
        {
            TTRetVal = Can_Hw_SetLisOnlyMode(Can_pControllerConfig->Can_u8ControllerOffset, FALSE);
            break;
        }
        case LISTEN_ONLY_MODE:
        {
            TTRetVal = Can_Hw_SetLisOnlyMode(Can_pControllerConfig->Can_u8ControllerOffset, TRUE);
            break;
        }
        default:
        {
            TTRetVal = TT_RET_PARAM_ENUM_ERR;
            break;
        }
        }
        if(TT_RET_SUCCESS == TTRetVal)
        {
            Can_Drv_eListenOnlyMode[Can_pControllerConfig->Can_u8ControllerID] = State;
        }
        else
        {
            Can_Drv_PriRetCheck(CAN_DRV_SI_SET_LISTEN_ONLY_MODE, &TTRetVal);
        }
    }
    else
    {

    }
    return TTRetVal;
}
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

/******************************************************************************
*  Service name     : Can_Drv_SetControllerToStopMode
*  Syntax           : TT_RetType Can_Drv_SetControllerToStopMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 105
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Set Controller to stop participating the CAN network
******************************************************************************/
TT_RetType Can_Drv_SetControllerToStopMode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
    /*
    * [SWS_Can_00197] 鈱� The function Can_SetControllerMode shall disable interrupts  鈱�
    * that are not allowed in the new state. 鈱�
    * [SWS_Can_00426] 鈱� Disabling of CAN interrupts shall not be executed, when CAN
    * interrupts have been disabled by function Can_DisableControllerInterrupts.鈱�
    */

    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType TTRetValArray[4] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};
    uint8 u8HwObjRefIdx = 0U;
    TT_CONST Can_HwObjectConfigType * Can_pHwObject;
    uint8 u8Idx = 0U;
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_SET_CONTROLLER_TO_STOP_MODE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_EnterFrzMode(Can_pControllerConfig->Can_u8ControllerOffset);
        if(TT_RET_SUCCESS == TTRetVal)
        {
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
            TTRetVal = Can_Hw_ConfigPN(Can_pControllerConfig->Can_u8ControllerOffset, FALSE, NULL_PTR);
            if((TRUE == Can_Drv_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID]) && (TT_RET_SUCCESS == TTRetVal))
#else
                if (TRUE == Can_Drv_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID])
#endif
                {
                    TTRetValArray[0] = Can_Hw_DisInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
                    if (Can_pControllerConfig->bErrEn)
                    {
                        TTRetValArray[1] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_ERR, FALSE);
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                        TTRetValArray[2] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_ERR_FAST, FALSE);
#endif  /* FLEXCAN_HW_FEATURE_HAS_FD */
                    }
                    else
                    {

                    }
#endif  /*  ERROR_INTERRUPT_SUPPORT */
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
                    if (FALSE == Can_pControllerConfig->Can_bBusOffUsesPolling)
                    {
                        TTRetValArray[3] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_BUSOFF, FALSE);
                    }
                    else
                    {

                    }
#endif /* BUSOFF_INTERRUPT_SUPPORT */
                }
                else
                {

                }
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) 
            if(TT_RET_SUCCESS != TTRetVal)
            {
                
            }
            else if((TT_RET_SUCCESS != TTRetValArray[0])
                    || (TT_RET_SUCCESS != TTRetValArray[1])
                    || (TT_RET_SUCCESS != TTRetValArray[2])
                    || (TT_RET_SUCCESS != TTRetValArray[3]))
            {
                TTRetVal = TT_RET_OPT_REG_ERR;
            }
#else   
            if((TT_RET_SUCCESS != TTRetValArray[0])
                    || (TT_RET_SUCCESS != TTRetValArray[1])
                    || (TT_RET_SUCCESS != TTRetValArray[2])
                    || (TT_RET_SUCCESS != TTRetValArray[3]))
            {
                TTRetVal = TT_RET_OPT_REG_ERR;
            }
#endif
            else
            {
                for (u8HwObjRefIdx = 0U; ((u8HwObjRefIdx < Can_pControllerConfig->Can_u8HwObjectRefCount) && (TT_RET_SUCCESS == TTRetVal)); u8HwObjRefIdx++)
                {
                    Can_pHwObject = (TT_CONST Can_HwObjectConfigType *)Can_pControllerConfig->Can_ppHwObject[u8HwObjRefIdx];

                    if (CAN_TX_NORMAL == Can_pHwObject->Can_eReceiveType)
                    {
                        u8Idx = 0U;
                        do
                        {
                            (void)Can_Hw_AbortTransfer(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObject->Can_u8HwBufferIndex + u8Idx);
                            u8Idx++;
                        }while(u8Idx < Can_pHwObject->Can_u8ObjectCount);
                    }
                    else
                    {
                        (void)Can_Hw_AbortTransfer(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObject->Can_u8HwBufferIndex);
                    }
                }
                
                TTRetVal = Can_Hw_SetStopMode(Can_pControllerConfig->Can_u8ControllerOffset);
                if(TT_RET_SUCCESS == TTRetVal)
                {
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                Can_apxCtrlConfigIcomIndex[Can_pControllerConfig->Can_u8ControllerID] = NULL_PTR;
#endif
                Can_eControllerState[Can_pControllerConfig->Can_u8ControllerID] = CAN_CS_STOPPED;
                }
                else
                {

                }                               
            }                       
        }
        else
        {

        }
        Can_Drv_PriRetCheck(CAN_DRV_SI_SET_CONTROLLER_TO_STOP_MODE, &TTRetVal);
    }
    else
    {

    }

    return TTRetVal;
}

/******************************************************************************
*  Service name     : Can_Drv_DisableControllerInterrupts
*  Syntax           : TT_RetType Can_Drv_DisableControllerInterrupts(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 106
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Disable Can Controller Interrupts
******************************************************************************/
TT_RetType Can_Drv_DisableControllerInterrupts(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType TTRetValArray[4] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_DISABLE_CONTROLLER_INTERRUPTS, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_DISABLE_CONTROLLER_INTERRUPTS, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        if (TRUE == Can_Drv_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID])
        {
            /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
            TTRetValArray[0] = Can_Hw_DisInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
            if (Can_pControllerConfig->bErrEn)
            {
                TTRetValArray[1] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_ERR, FALSE);
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                TTRetValArray[2] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_ERR_FAST, FALSE);
#endif  /* FLEXCAN_HW_FEATURE_HAS_FD */
            }
            else
            {

            }
#endif  /*  ERROR_INTERRUPT_SUPPORT */
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
            if (FALSE == Can_pControllerConfig->Can_bBusOffUsesPolling)
            {
                TTRetValArray[3] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_BUSOFF, FALSE);
            }
            else
            {

            }
#endif /* BUSOFF_INTERRUPT_SUPPORT */
            if((TT_RET_SUCCESS != TTRetValArray[0])
                    || (TT_RET_SUCCESS != TTRetValArray[1])
                    || (TT_RET_SUCCESS != TTRetValArray[2])
                    || (TT_RET_SUCCESS != TTRetValArray[3]))
            {
                TTRetVal = TT_RET_OPT_REG_ERR;
            }
            else
            {
                Can_Drv_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID] = FALSE;
            }

        }
        else
        {

        }
        Can_Drv_PriRetCheck(CAN_DRV_SI_DISABLE_CONTROLLER_INTERRUPTS, &TTRetVal);
    }
    else
    {

    }
    return TTRetVal;
}

/******************************************************************************
*  Service name     : Can_Drv_EnableControllerInterrupts
*  Syntax           : TT_RetType Can_Drv_EnableControllerInterrupts(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 107
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Enable Can Controller Interrupts
******************************************************************************/
TT_RetType Can_Drv_EnableControllerInterrupts(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType TTRetValArray[4] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_ENABLE_CONTROLLER_INTERRUPTS, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_ENABLE_CONTROLLER_INTERRUPTS, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        /*
         * [SWS_Can_00208] 鈱� The function Can_EnableControllerInterrupts shall perform no
         * action when Can_DisableControllerInterrupts has not been called before.鈱�
         */
        if (FALSE == Can_Drv_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID])
        {
            /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
            TTRetValArray[0] = Can_Hw_EnInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
            if (Can_pControllerConfig->bErrEn)
            {
                TTRetValArray[1] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_ERR, TRUE);
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                TTRetValArray[2] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_ERR_FAST, TRUE);
#endif /* FLEXCAN_HW_FEATURE_HAS_FD */
            }
            else
            {

            }
#endif /* ERROR_INTERRUPT_SUPPORT */
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
            if (FALSE == Can_pControllerConfig->Can_bBusOffUsesPolling)
            {
                TTRetValArray[3] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_BUSOFF, TRUE);
            }
            else
            {

            }
#endif  /* BUSOFF_INTERRUPT_SUPPORT */
            /* update status */
            if((TT_RET_SUCCESS != TTRetValArray[0])
                    || (TT_RET_SUCCESS != TTRetValArray[1])
                    || (TT_RET_SUCCESS != TTRetValArray[2])
                    || (TT_RET_SUCCESS != TTRetValArray[3]))
            {
                TTRetVal = TT_RET_OPT_REG_ERR;
            }
            else
            {
                Can_Drv_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID] = TRUE;
            }

        }
        else
        {

        }
        Can_Drv_PriRetCheck(CAN_DRV_SI_ENABLE_CONTROLLER_INTERRUPTS, &TTRetVal);
    }
    else
    {

    }
    return TTRetVal;
}

/******************************************************************************
*  Service name     : Can_Drv_CheckWakeup
*  Syntax           : TT_RetType Can_Drv_CheckWakeup(uint8 Controller,boolean *retval)
*  Service ID       : 121
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Controller - Can Controller
*  Parameters (out) : retval - wakeup value
*  Return value     : TT_RetType
*  Description      : Check WakeUp state
******************************************************************************/
TT_RetType Can_Drv_CheckWakeup(uint8 Controller,boolean *retval)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    boolean Wakeup_val = FALSE;
    Can_Drv_PriParaCheck(((NULL_PTR == retval)), CAN_DRV_SI_CHECK_WAKEUP, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_CHECK_WAKEUP, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_GetStopMode(Controller,&Wakeup_val);
        if(TT_RET_SUCCESS == TTRetVal)
        {
            *retval = Wakeup_val;
        }
        else
        {
            Can_Drv_PriRetCheck(CAN_DRV_SI_CHECK_WAKEUP, &TTRetVal);
        }
    }
    else
    {

    }

    return TTRetVal;

}

/******************************************************************************
*  Service name     : Can_Drv_GetControllerErrorState
*  Syntax           : TT_RetType Can_Drv_GetControllerErrorState(TT_CONST Can_ControllerConfigType * Can_pControllerConfig,uint8 *CanErrorState)
*  Service ID       : 108
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant (for the same controller)
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : CanErrorState - Error State
*  Return value     : TT_RetType
*  Description      : Get Controller Error State
******************************************************************************/
TT_RetType Can_Drv_GetControllerErrorState(TT_CONST Can_ControllerConfigType * Can_pControllerConfig,uint8 *CanErrorState)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    uint32 ErrStatus = 0U;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == CanErrorState)), CAN_DRV_SI_GET_CONTROLLER_ERROR_STATE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_GET_CONTROLLER_ERROR_STATE, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_GetErrorStatus(Can_pControllerConfig->Can_u8ControllerOffset, &ErrStatus);
        if(TT_RET_SUCCESS == TTRetVal)
        {
            *CanErrorState = (uint8)((ErrStatus & TT_CAN_FLEXCAN_ESR1_FLTCONF_Msk) >> TT_CAN_FLEXCAN_ESR1_FLTCONF_Pos);
        }
        else
        {
            Can_Drv_PriRetCheck(CAN_DRV_SI_GET_CONTROLLER_ERROR_STATE, &TTRetVal);
        }
    }
    else
    {

    }
    return TTRetVal;
}

/******************************************************************************
*  Service name     : Can_Drv_GetControllerTxErrorCounter
*  Syntax           : TT_RetType Can_Drv_GetControllerTxErrorCounter(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 * TxErrorCounter)
*  Service ID       : 109
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant (for the same controller)
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : TxErrorCounter - Error Counter
*  Return value     : TT_RetType
*  Description      : Get Controller Tx Error Counter
******************************************************************************/
TT_RetType Can_Drv_GetControllerTxErrorCounter(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 * TxErrorCounter)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
                || (NULL_PTR == TxErrorCounter)), CAN_DRV_SI_GET_CONTROLLER_TX_ERROR_COUNTER, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_GET_CONTROLLER_TX_ERROR_COUNTER, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_GetControllerTxErrCounter(Can_pControllerConfig->Can_u8ControllerOffset, TxErrorCounter);
        Can_Drv_PriRetCheck(CAN_DRV_SI_GET_CONTROLLER_TX_ERROR_COUNTER, &TTRetVal);
    }
    else
    {

    }
    return TTRetVal;
}

/******************************************************************************
*  Service name     : Can_Drv_GetControllerRxErrorCounter
*  Syntax           : TT_RetType Can_Drv_GetControllerRxErrorCounter(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 * RxErrorCounter)
*  Service ID       : 110
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant (for the same controller)
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : RxErrorCounter - Error Counter
*  Return value     : TT_RetType
*  Description      : Get Controller Rx Error Counter
******************************************************************************/
TT_RetType Can_Drv_GetControllerRxErrorCounter(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, uint8 * RxErrorCounter)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == RxErrorCounter)), CAN_DRV_SI_GET_CONTROLLER_RX_ERROR_COUNTER, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig), CAN_DRV_SI_GET_CONTROLLER_RX_ERROR_COUNTER, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {

        TTRetVal =  Can_Hw_GetControllerRxErrCounter(Can_pControllerConfig->Can_u8ControllerOffset, RxErrorCounter);
        Can_Drv_PriRetCheck(CAN_DRV_SI_GET_CONTROLLER_RX_ERROR_COUNTER, &TTRetVal);
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

/******************************************************************************
*  Service name     : Can_Drv_Write
*  Syntax           : TT_RetType Can_Drv_Write(Can_HwHandleType Hth,TT_CONST Can_PduType * PduInfo)
*  Service ID       : 111
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant (thread-safe)
*  Parameters (in)  : Hth - Tx Hardware Object
*  Parameters (in)  : PduInfo - Pdu information
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Write Pduinfo to Hw Buffer and request transmission
******************************************************************************/
TT_RetType Can_Drv_Write
(
    Can_HwHandleType Hth,
    TT_CONST Can_PduType * PduInfo
)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_StatusType status = FLEXCAN_STATUS_ERROR;
    Flexcan_Hw_DataInfoType DataInfo = {0};
    uint8 u8ObjIdx = 0U;
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig = NULL_PTR;
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig = NULL_PTR;
    uint8 u8ControllerID = 0U;
#if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
    PduInfoType CanIf_PduInfo = {NULL_PTR,0};
    uint8 Data[64U];
#endif

    Can_Drv_PriParaCheck(((NULL_PTR == Can_apxConfig)
            || (NULL_PTR == PduInfo)), CAN_DRV_SI_WRITE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
#ifndef USING_OS_AUTOSAROS
        Can_Drv_PriParaCheck(((Hth >= ((Can_HwHandleType)CAN_HWOBJECT_CONFIG_COUNT))
                || (Hth < Can_apxConfig->Can_uHthFirstIndex)), CAN_DRV_SI_WRITE, TT_RET_PARAM_INDEX_ERR, &TTRetVal);
        if(TT_RET_SUCCESS == TTRetVal)
        {

            u8ControllerID = Can_apxConfig->Can_pHwObjIDToCtrlIDMap[Hth];
            Can_pControllerConfig = Can_apxConfig->Can_ppController[u8ControllerID];
            Can_pHwObjectConfig = &(Can_apxConfig->Can_pHwObjectConfig[Hth]);

            TTRetVal = Can_Drv_PriValidatePdu(Can_pControllerConfig, Can_pHwObjectConfig, PduInfo);
            Can_Drv_PriParaCheck((CAN_CS_STARTED != Can_eControllerState[u8ControllerID]), CAN_DRV_SI_WRITE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

            if(TT_RET_SUCCESS == TTRetVal)
            {
#else
                u8ControllerID = Can_apxConfig->Can_pHwObjIDToCtrlIDMap[Hth];
                Can_pControllerConfig = Can_apxConfig->Can_ppController[u8ControllerID];
                Can_pHwObjectConfig = &(Can_apxConfig->Can_pHwObjectConfig[Hth]);
#endif
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                if (Can_apxCtrlConfigIcomIndex[u8ControllerID] != NULL_PTR)
                {
                    TTRetVal = CAN_BUSY;
                }
                else
                {
#endif
                    if(CAN_TX_NORMAL == Can_pHwObjectConfig->Can_eReceiveType)
                    {
                        DataInfo.msg_id_type = ((PduInfo->id & CAN_EXTENDED_ID_U32) != 0U) ? FLEXCAN_MSG_ID_EXT : FLEXCAN_MSG_ID_STD;
                        DataInfo.data_length = PduInfo->length;
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                        DataInfo.fd_padding = Can_pHwObjectConfig->Can_u8PaddingValue;
                        DataInfo.fd_enable = (boolean)(((PduInfo->id & CAN_FD_FRAME_U32) != 0U) ? TRUE : FALSE);
#if (CAN_SET_BAUDRATE_API == STD_ON)
                        DataInfo.enable_brs = Can_pControllerConfig->Can_pBaudrateConfig[Can_au16BaudrateIDConfig[Can_pControllerConfig->Can_u8ControllerID]].Can_bBitRateSwitch;
#else
                        DataInfo.enable_brs = Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_bBitRateSwitch;
#endif
#endif
                        DataInfo.is_remote = FALSE;
                        DataInfo.is_polling = Can_pHwObjectConfig->Can_bHwObjectUsesPolling;
                        do
                        {
                            TTRetVal = Can_Hw_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx, &status);
                            if((FLEXCAN_STATUS_SUCCESS == status) && (TT_RET_SUCCESS == TTRetVal))
                            {
#if ((CAN_TX_POLLING_SUPPORT == STD_ON) || (FLEXCAN_HW_MB_INTERRUPT_SUPPORT == STD_ON))
                                Can_Drv_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObjectConfig->Can_u8HwBufferIndex+u8ObjIdx] = PduInfo->swPduHandle;
#endif
#if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
                                if ((TRUE == Can_pHwObjectConfig->Can_bTriggerTransmit) &&  (NULL_PTR == PduInfo->sdu))
                                {
                                    CanIf_PduInfo.SduDataPtr = Data;
                                    CanIf_PduInfo.SduLength = (PduLengthType)Can_pHwObjectConfig->Can_u8PayloadLength;
                                    if ((Std_ReturnType)E_OK == CanIf_TriggerTransmit(PduInfo->swPduHandle, &CanIf_PduInfo))
                                    {
                                        DataInfo.data_length = CanIf_PduInfo.SduLength;
                                        TTRetVal = Can_Hw_Send(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx, &DataInfo, PduInfo->id, Data);
                                    }
                                    else
                                    {
                                        TTRetVal = TT_RET_STATUS_ERR;
                                    }
                                }
                                else
                                {
#endif
                                    TTRetVal = Can_Hw_Send(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx, &DataInfo, PduInfo->id, PduInfo->sdu);
#if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
                                }
#endif
                            }
                            else
                            {

                            }
                            u8ObjIdx++;
                        }while ((u8ObjIdx < Can_pHwObjectConfig->Can_u8ObjectCount) && (TT_RET_SUCCESS == TTRetVal));
                    }
                    else
                    {

                    }

                    if((TT_RET_SUCCESS != TTRetVal))
                    {
                        Can_Drv_PriRetCheck(CAN_DRV_SI_WRITE, &TTRetVal);
                    }
                    else if((FLEXCAN_STATUS_SUCCESS != status) && (FLEXCAN_STATUS_BUSY != status))
                    {
                        TTRetVal = TT_RET_STATUS_ERR;
                        Can_Drv_PriRetCheck(CAN_DRV_SI_WRITE, &TTRetVal);
                    }
                    else if(FLEXCAN_STATUS_BUSY == status)
                    {
                        TTRetVal = (TT_RetType)CAN_BUSY;
                    }
                    else
                    {

                    }
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                }
#endif
#ifndef USING_OS_AUTOSAROS
            }
            else
            {

            }
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


#if (CAN_TX_POLLING_SUPPORT == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_MainFunction_Write
*  Syntax           : TT_RetType Can_Drv_MainFunction_Write(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig)
*  Service ID       : 112
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Polling Tx Confirmation
******************************************************************************/
TT_RetType Can_Drv_MainFunction_Write(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig)
{
    uint8 u8ObjIdx = 0U;
    boolean TXErr_Flag = FALSE;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_StatusType status = FLEXCAN_STATUS_ERROR;

    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_MAIN_FUNCTION_WRITE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_TXWRNStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset,&TXErr_Flag);
        if((TT_RET_SUCCESS == TTRetVal) && (TXErr_Flag == FALSE))
        {
            do
            {
                if (FLEXCAN_MB_TX_BUSY == ((Can_Drv_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->mbs[Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx].state))
                {
                    /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
                    TTRetVal = Can_Hw_MainFunctionWrite(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx);
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        TTRetVal = Can_Hw_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx, &status);
                        if((FLEXCAN_STATUS_SUCCESS == status) && (TT_RET_SUCCESS == TTRetVal))
                        {
                            CanIf_TxConfirmation(Can_Drv_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx]);
    #if (CAN_TIMESTAMP_ENABLE == STD_ON)
                            if (TRUE == Can_pHwObjectConfig->CanTimestampEnable)
                            {
                                uint32 timestamp = Can_Drv_apxStatus[Can_pControllerConfig->Can_u8ControllerOffset]->mbs[Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx].time_stamp;

                                Can_pControllerConfig->CanTxTimestampNotification(Can_pHwObjectConfig->Can_HwObjectID,
                                        Can_Drv_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObjectConfig->Can_u8HwBufferIndex + u8ObjIdx],
                                        timestamp);
                            }
                            else
                            {

                            }
    #endif
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
                u8ObjIdx++;
            }while((u8ObjIdx < Can_pHwObjectConfig->Can_u8ObjectCount) && (TT_RET_SUCCESS == TTRetVal));
        }
        else
        {
            TTRetVal = TT_RET_STATUS_TRANSITION_ERR;
        }
        Can_Drv_PriRetCheck(CAN_DRV_SI_MAIN_FUNCTION_WRITE, &TTRetVal);
    }
    else
    {

    }
    return TTRetVal;
}
#endif

#if (CAN_RX_POLLING_SUPPORT == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_MainFunction_Read
*  Syntax           : TT_RetType Can_Drv_MainFunction_Read(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig)
*  Service ID       : 113
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Polling Rx Indication
******************************************************************************/
TT_RetType Can_Drv_MainFunction_Read(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig)
{
    /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_StatusType status = FLEXCAN_STATUS_ERROR;
    boolean bResult = FALSE;
    static Flexcan_Hw_MsgBuffType ReceivedDataBuffer = {0};
    static Can_HwType CanIf_Mailbox = {0};
    static PduInfoType CanIf_PduInfo = {NULL_PTR,0};

    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_MAIN_FUNCTION_READ, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_GetStopMode(Can_pControllerConfig->Can_u8ControllerOffset, &bResult);
        if ((FALSE == bResult) && (TT_RET_SUCCESS == TTRetVal))
        {
            if (CAN_RX_NORMAL == Can_pHwObjectConfig->Can_eReceiveType)
            {
                (void)Can_Hw_Receive(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex, &ReceivedDataBuffer, Can_pHwObjectConfig->Can_bHwObjectUsesPolling);
                TTRetVal = Can_Hw_MainFunctionRead(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    TTRetVal = Can_Hw_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex, &status);
                    if ((FLEXCAN_STATUS_SUCCESS == status) && (TT_RET_SUCCESS == TTRetVal))
                    {
                        TTRetVal = Can_Drv_PriParseData(&CanIf_Mailbox, \
                                &CanIf_PduInfo, \
                                &ReceivedDataBuffer, \
                                Can_pControllerConfig, \
                                Can_pHwObjectConfig, \
                                CAN_DRV_SI_MAIN_FUNCTION_READ);
                    }
                    else
                    {

                    }
                }
                else
                {

                }                
                Can_Drv_PriRetCheck(CAN_DRV_SI_MAIN_FUNCTION_READ, &TTRetVal);
            }
            else if (CAN_RX_LEGACY_FIFO == Can_pHwObjectConfig->Can_eReceiveType)
            {
                TTRetVal = Can_Drv_PriProcessLegFifoPolling(&CanIf_Mailbox, \
                        &CanIf_PduInfo, \
                        &ReceivedDataBuffer, \
                        Can_pControllerConfig, \
                        Can_pHwObjectConfig);
            }
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
            else if (CAN_RX_ENHANCED_FIFO == Can_pHwObjectConfig->Can_eReceiveType)
            {
                TTRetVal = Can_Drv_PriProcessEnhFifoPolling(&CanIf_Mailbox, \
                        &CanIf_PduInfo, \
                        &ReceivedDataBuffer, \
                        Can_pControllerConfig, \
                        Can_pHwObjectConfig);
            }
#endif /*(CAN_ENHANCED_FIFO_ENABLED == STD_ON) */
            else
            {
                /* prevent misra */
            }

        }
        else
        {
            Can_Drv_PriRetCheck(CAN_DRV_SI_MAIN_FUNCTION_READ, &TTRetVal);
        }
    }
    else
    {

    }
    return TTRetVal;
}
#endif

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (CAN_BUSOFF_POLLING_SUPPORT == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_MainFunction_BusOff
*  Syntax           : TT_RetType Can_Drv_MainFunction_BusOff(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 114
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Polling Bus Off
******************************************************************************/
TT_RetType Can_Drv_MainFunction_BusOff(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_MAIN_FUNCTION_BUSOFF, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_MainFuncBusOff(Can_pControllerConfig->Can_u8ControllerOffset);
    }
    else
    {

    }
    return TTRetVal;
}
#endif

/******************************************************************************
*  Service name     : Can_Drv_MainFunction_Mode
*  Syntax           : TT_RetType Can_Drv_MainFunction_Mode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, Can_ControllerStateType * Can_pControllerState)
*  Service ID       : 115
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : Can_pControllerState - Can Controller State
*  Return value     : TT_RetType
*  Description      : Polling Controller Mode Transitions
******************************************************************************/
TT_RetType Can_Drv_MainFunction_Mode(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, Can_ControllerStateType * Can_pControllerState)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    boolean bResult = FALSE;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pControllerState)), CAN_DRV_SI_MAIN_FUNCTION_MODE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
        if(CAN_CS_STARTED == *Can_pControllerState)
        {
            TTRetVal = Can_Hw_GetStartMode(Can_pControllerConfig->Can_u8ControllerOffset, &bResult);
            if((FALSE == bResult) && (TT_RET_SUCCESS == TTRetVal))
            {
                *Can_pControllerState = CAN_CS_STOPPED;
#ifdef USING_OS_AUTOSAROS
                CanIf_ControllerModeIndication(Can_pControllerConfig->Can_u8AbstControllerID, CAN_CS_STOPPED);
#endif
            }
            else
            {

            }
        }
        else if(CAN_CS_STOPPED == *Can_pControllerState)
        {
            TTRetVal = Can_Hw_GetStopMode(Can_pControllerConfig->Can_u8ControllerOffset, &bResult);
            if((FALSE == bResult) && (TT_RET_SUCCESS == TTRetVal))
            {
                *Can_pControllerState = CAN_CS_STARTED;
#ifdef USING_OS_AUTOSAROS
                CanIf_ControllerModeIndication(Can_pControllerConfig->Can_u8AbstControllerID, CAN_CS_STARTED);
#endif
            }
            else
            {

            }
        }
        else
        {
            /* nothing to do */
        }
        Can_Drv_PriRetCheck(CAN_DRV_SI_MAIN_FUNCTION_MODE, &TTRetVal);
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

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_ProcessTxMesgBuffer
*  Syntax           : TT_RetType Can_Drv_ProcessTxMesgBuffer(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8MbIdx)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (in)  : u8MbIdx - Can Mailbox Index
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process Tx Interrupt
******************************************************************************/
TT_RetType Can_Drv_ProcessTxMesgBuffer(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8MbIdx)
{
#if (CAN_TIMESTAMP_ENABLE == STD_ON)
    uint32 TimeStamp = 0U;
#endif /* (CAN_TIMESTAMP_ENABLE == STD_ON) */
    Can_HwHandleType u8HwObjectID = 0U;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_INTERRUPTS_WRITE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        u8HwObjectID = Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][u8MbIdx];
        if ((((Can_HwHandleType)CAN_HWOBJ_UNMAPPED) != u8HwObjectID) && (FALSE == Can_pHwObjectConfig[u8HwObjectID].Can_bHwObjectUsesPolling))
        {
            if (CAN_TX_NORMAL == Can_pHwObjectConfig[u8HwObjectID].Can_eReceiveType)
            {
                CanIf_TxConfirmation(Can_Drv_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][u8MbIdx]);
#if (CAN_TIMESTAMP_ENABLE == STD_ON)
                if (TRUE == Can_pHwObjectConfig[u8HwObjectID].CanTimestampEnable)
                {
                    TimeStamp = Can_Drv_apxStatus[Can_pControllerConfig->Can_u8ControllerOffset]->mbs[u8MbIdx].time_stamp;
                    Can_pControllerConfig->CanTxTimestampNotification(Can_pHwObjectConfig[u8HwObjectID].Can_HwObjectID,
                            Can_Drv_au16TxPduId[Can_pControllerConfig->Can_u8ControllerID][u8MbIdx],
                            TimeStamp
                    );
                }
                else
                {

                }
#endif /* (CAN_TIMESTAMP_ENABLE == STD_ON) */
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

/******************************************************************************
*  Service name     : Can_Drv_ProcessRxMesgBuffer
*  Syntax           : TT_RetType Can_Drv_ProcessRxMesgBuffer(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8MbIdx)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (in)  : u8MbIdx - Can Mailbox Index
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process Rx Interrupt
******************************************************************************/
TT_RetType Can_Drv_ProcessRxMesgBuffer(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8MbIdx)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_HwHandleType u8HwObjectID = 0U;
    Can_HwType CanIf_Mailbox = {0};
    PduInfoType CanIf_PduInfo = {NULL_PTR,0};
    TT_CONST Can_HwObjectConfigType * Can_pHwObject = NULL_PTR;
    Flexcan_Hw_MsgBuffType * pReceivedDataBuffer = NULL_PTR;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_INTERRUPTS_READ, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        u8HwObjectID = Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][u8MbIdx];
        if ((((Can_HwHandleType)CAN_HWOBJ_UNMAPPED) != u8HwObjectID) && (FALSE == Can_pHwObjectConfig[u8HwObjectID].Can_bHwObjectUsesPolling))
        {
            Can_pHwObject = &Can_pHwObjectConfig[u8HwObjectID];

            if (CAN_RX_NORMAL == Can_pHwObject->Can_eReceiveType)
            {
                if((Can_Drv_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->mbs[Can_pHwObject->Can_u8HwBufferIndex].state == FLEXCAN_MB_IDLE)
                {
                    pReceivedDataBuffer = (Can_Drv_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->mbs[Can_pHwObject->Can_u8HwBufferIndex].pMBmessage;
                    TTRetVal = Can_Drv_PriParseData(&CanIf_Mailbox, \
                            &CanIf_PduInfo, \
                            pReceivedDataBuffer, \
                            Can_pControllerConfig, \
                            Can_pHwObject, \
                            CAN_DRV_SI_INTERRUPTS_READ);
                    /* ready to receive in next time*/
                }
                else
                {

                }

                if(TT_RET_SUCCESS == TTRetVal)
                {
                    TTRetVal = Can_Hw_Receive(Can_pControllerConfig->Can_u8ControllerOffset, \
                            Can_pHwObject->Can_u8HwBufferIndex, \
                            NULL_PTR, \
                            Can_pHwObject->Can_bHwObjectUsesPolling);
                    Can_Drv_PriRetCheck(CAN_DRV_SI_INTERRUPTS_READ, &TTRetVal);
                }
                else
                {

                }
            }
            else if (CAN_RX_LEGACY_FIFO == Can_pHwObject->Can_eReceiveType)
            {
                if ((uint8)7U == u8MbIdx)
                {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    (void)ModuleDet_ReportRuntimeError((uint16)CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
#endif
                    if (NULL_PTR != Can_pControllerConfig->Can_pLegacyFiFoOvfNotif)
                    {
                        Can_pControllerConfig->Can_pLegacyFiFoOvfNotif();
                    }
                    else
                    {

                    }
                }
                else if ((uint8)6U == u8MbIdx)
                {
                    if (NULL_PTR != Can_pControllerConfig->Can_pLegacyFiFoWarnNotif)
                    {
                        Can_pControllerConfig->Can_pLegacyFiFoWarnNotif();
                    }
                    else
                    {

                    }
                }
                else
                {
                    pReceivedDataBuffer = (Can_Drv_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->mbs[Can_pHwObject->Can_u8HwBufferIndex].pMBmessage;
                    TTRetVal = Can_Drv_PriParseData(&CanIf_Mailbox, \
                            &CanIf_PduInfo, \
                            pReceivedDataBuffer, \
                            Can_pControllerConfig, \
                            Can_pHwObject, \
                            CAN_DRV_SI_INTERRUPTS_READ);

                    /* ready to receive in next time */
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, NULL_PTR);
                        Can_Drv_PriRetCheck(CAN_DRV_SI_INTERRUPTS_READ, &TTRetVal);
                    }
                    else
                    {

                    }
                }
            }
            else
            {
                /* prevent misra */
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
/******************************************************************************
*  Service name     : Can_Drv_ProcessRxLegacyDma
*  Syntax           : TT_RetType Can_Drv_ProcessRxLegacyDma(TT_CONST Can_ControllerConfigType * Can_pControllerConfig,TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,uint8 u8Event)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (in)  : u8Event - DMA Complete Or Error
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process Rx Interrupt
******************************************************************************/
TT_RetType Can_Drv_ProcessRxLegacyDma
(
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,
    uint8 u8Event
)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_HwHandleType u8HwObjectID = 0U;
    Can_HwType CanIf_Mailbox = {0};
    PduInfoType CanIf_PduInfo = {NULL_PTR,0};
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_ABORT_MB, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        u8HwObjectID = Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][CAN_DRV_RX_LEGACY_FIFO_MB_HANDLER];
        if ((((Can_HwHandleType)CAN_HWOBJ_UNMAPPED) != u8HwObjectID) && (FALSE == Can_pHwObjectConfig[u8HwObjectID].Can_bHwObjectUsesPolling))
        {
            if ((uint8)FLEXCAN_EVENT_DMA_COMPLETE == u8Event)
            {
                TTRetVal = Can_Drv_PriParseData(&CanIf_Mailbox, \
                        &CanIf_PduInfo, \
                        &Can_pControllerConfig->pDmaDstAddr[0], \
                        Can_pControllerConfig, \
                        &Can_pHwObjectConfig[u8HwObjectID], \
                        CAN_DRV_SI_INTERRUPTS_READ);
                /* ready to receive in next time */
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
                    Can_Drv_PriRetCheck(CAN_DRV_SI_INTERRUPTS_READ, &TTRetVal);
                }
                else
                {

                }
            }
            else if ((uint8)FLEXCAN_EVENT_DMA_ERROR == u8Event)
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)ModuleDet_ReportRuntimeError((uint16)CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
#endif
                if (NULL_PTR != Can_pControllerConfig->Can_pDmaErrorNotif)
                {
                    Can_pControllerConfig->Can_pDmaErrorNotif();
                }
                else
                {

                }

                /* although DMA errors occurred, expect to ready to receive in next time */
                TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
                Can_Drv_PriRetCheck(CAN_DRV_SI_INTERRUPTS_READ, &TTRetVal);
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
#endif /* End of (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON) */

#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_ProcessRxEnhance
*  Syntax           : TT_RetType Can_Drv_ProcessRxEnhance(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8Event)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : Can_pHwObjectConfig - Can Hardware Object Config
*  Parameters (in)  : u8Event - DMA Complete Or Error
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process Rx Enhance FIFO Interrupt
******************************************************************************/
TT_RetType Can_Drv_ProcessRxEnhance(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig, uint8 u8Event)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_HwType CanIf_Mailbox = {0};
    PduInfoType CanIf_PduInfo = {NULL_PTR,0};
    Flexcan_Hw_MsgBuffType * pReceivedDataBuffer = NULL_PTR;
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
    TT_CONST uint32 u32MbCnt = 0U;
#endif /* (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON) */
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_INTERRUPTS_READ, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        if ((uint8)FLEXCAN_EVENT_ENHANCED_RXFIFO_OVERFLOW == u8Event)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)ModuleDet_ReportRuntimeError((uint16)CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
#endif
            if (NULL_PTR != Can_pControllerConfig->Can_pEnhanceFiFoOvfNotif)
            {
                Can_pControllerConfig->Can_pEnhanceFiFoOvfNotif();
            }
            else
            {

            }
        }
        else if ((uint8)FLEXCAN_EVENT_ENHANCED_RXFIFO_COMPLETE == u8Event)
        {
            pReceivedDataBuffer = (Can_Drv_apxStatus[Can_pControllerConfig->Can_u8ControllerID])->enhancedFifoOutput.pMBmessage;

            TTRetVal = Can_Drv_PriParseData(&CanIf_Mailbox, \
                    &CanIf_PduInfo, \
                    pReceivedDataBuffer, \
                    Can_pControllerConfig, \
                    Can_pHwObjectConfig, \
                    CAN_DRV_SI_INTERRUPTS_READ);
            /* ready to receive in next time */
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, NULL_PTR);
                Can_Drv_PriRetCheck(CAN_DRV_SI_INTERRUPTS_READ, &TTRetVal);
            }
            else
            {

            }
        }
#if (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if ((uint8)FLEXCAN_EVENT_DMA_COMPLETE == u8Event)
        {
            TTRetVal = Can_Drv_PriParseData(&CanIf_Mailbox, \
                    &CanIf_PduInfo, \
                    &Can_pControllerConfig->pDmaDstAddr[u32MbCnt], \
                    Can_pControllerConfig, \
                    Can_pHwObjectConfig, \
                    CAN_DRV_SI_INTERRUPTS_READ);
            /* ready to receive in next time */
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
                Can_Drv_PriRetCheck(CAN_DRV_SI_INTERRUPTS_READ, &TTRetVal);
            }
            else
            {

            }
        }
        else if ((uint8)FLEXCAN_EVENT_DMA_ERROR == u8Event)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)ModuleDet_ReportRuntimeError((uint16)CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
#endif
            if (NULL_PTR != Can_pControllerConfig->Can_pDmaErrorNotif)
            {
                Can_pControllerConfig->Can_pDmaErrorNotif();
            }
            else
            {

            }

            /* although DMA errors occurred, expect to ready to receive in next time */
            TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->pDmaDstAddr);
            Can_Drv_PriRetCheck(CAN_DRV_SI_INTERRUPTS_READ, &TTRetVal);
        }
#endif /* (FLEXCAN_HW_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        else
        {

        }
    }
    else
    {

    }
    return TTRetVal;
}
#endif /* (CAN_ENHANCED_FIFO_ENABLED == STD_ON) */
#endif /* (CAN_MB_INTERRUPT_SUPPORT == STD_ON) */

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/******************************************************************************
*  Service name     : Can_Drv_DeactivateIcomConfiguration
*  Syntax           : TT_RetType Can_Drv_DeactivateIcomConfiguration(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
*  Service ID       : 116
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Deactivate Icom  Configuration
******************************************************************************/
TT_RetType Can_Drv_DeactivateIcomConfiguration(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
    boolean IsStart = TRUE;
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_DEACTIVATE_ICOM_CONFIGURATION, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        Can_Drv_PriParaCheck((CAN_CS_UNINIT == Can_eControllerState[Can_pControllerConfig->Can_u8ControllerID]), CAN_DRV_SI_DEACTIVATE_ICOM_CONFIGURATION, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);
        if(TT_RET_SUCCESS == TTRetVal)
        {
            TTRetVal = Can_Hw_GetStartMode(Can_pControllerConfig->Can_u8ControllerOffset, &IsStart);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                TTRetVal = Can_Hw_EnterFrzMode(Can_pControllerConfig->Can_u8ControllerOffset);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    /* Deactivate PN */
                    TTRetVal = Can_Hw_ConfigPN(Can_pControllerConfig->Can_u8ControllerOffset, FALSE, NULL_PTR);
                    if((TRUE == IsStart) && (TT_RET_SUCCESS == TTRetVal))
                    {
                        /* back to start mode */
                        TTRetVal = Can_Hw_ExitFreezeMode(Can_pControllerConfig->Can_u8ControllerOffset);
                    }
                    else if(TT_RET_SUCCESS == TTRetVal)
                    {
                        /* back to stop mode */
                        TTRetVal = Can_Hw_SetStopMode(Can_pControllerConfig->Can_u8ControllerOffset);
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
                else
                {

                }
            }
            else
            {

            }
            Can_Drv_PriRetCheck(CAN_DRV_SI_DEACTIVATE_ICOM_CONFIGURATION, &TTRetVal);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                Can_apxCtrlConfigIcomIndex[Can_pControllerConfig->Can_u8ControllerID] = NULL_PTR;
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

/******************************************************************************
*  Service name     : Can_Drv_SetIcomConfiguration
*  Syntax           : TT_RetType Can_Drv_SetIcomConfiguration(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_IcomConfigsType * pIcomConfig)
*  Service ID       : 117
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : pIcomConfig - Icom Configuration
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Set Icom  Configuration
******************************************************************************/
TT_RetType Can_Drv_SetIcomConfiguration(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_IcomConfigsType * pIcomConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
                || (NULL_PTR == pIcomConfig)), CAN_DRV_SI_SET_ICOM_CONFIGURATION, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        Can_Drv_PriParaCheck((CAN_CS_UNINIT == Can_eControllerState[Can_pControllerConfig->Can_u8ControllerID]), CAN_DRV_SI_SET_ICOM_CONFIGURATION, TT_RET_STATUS_UNINIT_ERR, &TTRetVal);
        if(TT_RET_SUCCESS == TTRetVal)
        {
            TTRetVal = Can_Hw_EnterFrzMode(Can_pControllerConfig->Can_u8ControllerOffset);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                /* Activate PN */
                TTRetVal = Can_Hw_ConfigPN(Can_pControllerConfig->Can_u8ControllerOffset, TRUE, pIcomConfig->pCanIcomRxMessageConfigs->pFlexcanIpPnConfig);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    TTRetVal = Can_Hw_ExitFreezeMode(Can_pControllerConfig->Can_u8ControllerOffset);
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        Can_apxCtrlConfigIcomIndex[Can_pControllerConfig->Can_u8ControllerID] = pIcomConfig;
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
            Can_Drv_PriRetCheck(CAN_DRV_SI_SET_ICOM_CONFIGURATION, &TTRetVal);
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

/******************************************************************************
*  Service name     : Can_Drv_ProcessPN
*  Syntax           : TT_RetType Can_Drv_ProcessPN(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_IcomConfigsType * pIcomConfig)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : Can_pControllerConfig - Can Controller Config
*  Parameters (in)  : pIcomConfig - Icom Configuration
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Process PN Mode
******************************************************************************/
TT_RetType Can_Drv_ProcessPN(TT_CONST Can_ControllerConfigType * Can_pControllerConfig, TT_CONST Can_IcomConfigsType * pIcomConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_HwType CanIf_Mailbox = {0};
    PduInfoType CanIf_PduInfo = {NULL_PTR,0};
    Flexcan_Hw_MsgBuffType ReceivedDataBuffer = {0};
    uint8 u8WmbIndex = 0;
    uint8 u8NumOfWmb = 0U;

    Can_Drv_PriParaCheck(((NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == pIcomConfig)), CAN_DRV_SI_INTERRUPTS_PN, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        u8NumOfWmb = ((pIcomConfig->pCanIcomRxMessageConfigs->pFlexcanIpPnConfig->u16NumMatches) < 4U) ? ((uint8)pIcomConfig->pCanIcomRxMessageConfigs->pFlexcanIpPnConfig->u16NumMatches) : ((uint8)4U);

        for(u8WmbIndex = 0U; ((u8WmbIndex < u8NumOfWmb) && (TT_RET_SUCCESS == TTRetVal)); u8WmbIndex++)
        {
            TTRetVal = Can_Hw_GetWMB(Can_pControllerConfig->Can_u8ControllerOffset, u8WmbIndex, &ReceivedDataBuffer);
            CanIf_Mailbox.CanId = ReceivedDataBuffer.msgId;
            /*
             * [SWS_Can_00423] 鈱� In case of an Extended CAN frame, the Can module shall
             * convert the ID to a standardized format since the Upper layer (CANIF) does not know
             * whether the received CAN frame is a Standard CAN frame or Extended CAN frame.
             * In case of an Extended CAN frame, MSB of a received CAN frame ID needs to be
             * made as 鈥�1鈥� to mark the received CAN frame as Extended.鈱�
             */
            if(((ReceivedDataBuffer.cs) & CAN_DRV_CS_IDE_MASK) != 0U)
            {
                CanIf_Mailbox.CanId |= (uint32)0x80000000U;
            }
            else
            {

            }

#if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
            if(TRUE == CAN_LPDU_CALLOUT_FUNC_CALLED((uint8)pIcomConfig->u8CanIcomConfigId, \
                    CanIf_Mailbox.CanId, \
                    ReceivedDataBuffer.dataLen, \
                    &ReceivedDataBuffer.data[0]) \
            )
            {
#endif
            CanIf_Mailbox.Hoh = (uint8)pIcomConfig->u8CanIcomConfigId;
            CanIf_Mailbox.ControllerId = Can_pControllerConfig->Can_u8AbstControllerID;
            CanIf_PduInfo.SduLength = ReceivedDataBuffer.dataLen;
            CanIf_PduInfo.SduDataPtr = &ReceivedDataBuffer.data[0];
            CanIf_RxIndication(&CanIf_Mailbox, &CanIf_PduInfo);
#if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
            }
            else
            {

            }
#endif
        }
        Can_Drv_PriRetCheck(TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    }
    else
    {

    }
    return TTRetVal;
}
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/
#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief         Reports error if CAN_DEV_ERROR_DETECT == STD_ON.
* @details       Reports error if CAN_DEV_ERROR_DETECT == STD_ON
* @param[in]     Expr - boolean expression to check API conditions
* @param[in]     ApiId - Service Id of API
* @param[in]     ErrId - Error Id of Condition
* @param[out]    RetVal - variable to check return type
* @return        void
* @retval        None
*/
static void Can_Drv_PriParaCheck(bool Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(CAN_DRV_TT_STATUS_DEFAULT(ApiId), ErrId);
    #if defined(CAN_DEV_ERROR_DETECT) && (CAN_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(CAN_DRV_MODULE_ID_C, ApiId, ErrId);
            ModuleDet_ReportError(CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, ApiId, (uint8)ErrId);
    #endif
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
#else
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    *(RetVal) = ((uint32)(RetVal) > 1) ? 0U: 1U;
#endif
}

/**
* @brief         Reports Return Value error if CAN_DEV_ERROR_DETECT == STD_ON.
* @details       Reports Return Value error if CAN_DEV_ERROR_DETECT == STD_ON
* @param[in]     ApiId - Service Id of API
* @param[out]    ErrId - Error Id of Condition
* @return        void
* @retval        None
*/
static void Can_Drv_PriRetCheck(uint8 ApiId, TT_RetType *ErrId)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
    #if defined(CAN_DEV_ERROR_DETECT) && (CAN_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(CAN_DRV_MODULE_ID_C, ApiId, *ErrId);
            ModuleDet_ReportError(CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, ApiId, (uint8)*ErrId);
    #endif
            *ErrId = TT_SET_STATUS_TYPE(CAN_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
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
#else
    (void)ApiId;
    (void)ErrId;
#endif
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))

/**
* @brief        Init Check
* @details      InitCheck For Can After Can Init
* @param[in]    ConfigPtr - Pointing to configuration data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
*/
static TT_RetType Can_Drv_PriInitCheck(TT_CONST Can_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 u8ControllerID = 0U;
    Flexcan_Hw_ModesType CanMode = FLEXCAN_NORMAL_MODE;
    uint8 CanControllerOffset = 0;

    Can_Drv_PriParaCheck((NULL_PTR == ConfigPtr), CAN_DRV_SI_INIT, TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        for (u8ControllerID = 0U; u8ControllerID < CAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
        {
            if (NULL_PTR != ConfigPtr->Can_ppController[u8ControllerID])
            {
                CanMode = ConfigPtr->Can_ppController[u8ControllerID]->HwChannelIpConfig->pFlexcanIpHwConfig->flexcanMode;
                CanControllerOffset = ConfigPtr->Can_ppController[u8ControllerID]->Can_u8ControllerOffset;
                Ret = Can_Hw_LogicCheck(CanMode,CanControllerOffset);
            }
            else
            {

            }
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#endif /* INITCHECK_CAN */

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"

/**
* @brief         Determines if the controller is busy
* @details       Determines if the controller is busy
* @param[out]    bCtrlBusy - Save the controller busy result
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Other - fail
*/
static TT_RetType Can_Drv_PriIsControllersBusy(boolean *bCtrlBusy)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    uint8 u8ControllerID = 0U;
    Can_Drv_PriParaCheck(((NULL_PTR == bCtrlBusy)
            || (NULL_PTR == Can_apxConfig)), CAN_DRV_SI_INIT, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        for(u8ControllerID = 0U; u8ControllerID < CAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
        {
            Can_Drv_PriParaCheck((NULL_PTR == Can_apxConfig->Can_ppController[u8ControllerID]),
                    CAN_DRV_SI_INIT,
                    TT_RET_PARAM_INVALID_PTR_ERR,
                    &TTRetVal);

            if(TT_RET_SUCCESS == TTRetVal)
            {
                /*
                 *   [SWS_Can_00408] If development error detection for the Can module is enabled:
                 *   The function Can_Init shall raise the error CAN_E_TRANSITION if the CAN
                 *   controllers are not in state UNINIT.
                 */
                Can_Drv_PriParaCheck((CAN_CS_UNINIT != Can_eControllerState[u8ControllerID]),
                        CAN_DRV_SI_INIT,
                        TT_RET_STATUS_INIT_ERR,
                        &TTRetVal);
                if(TT_RET_SUCCESS != TTRetVal)
                {
                    *bCtrlBusy = TRUE;
                    break;
                }
                else
                {
                    /* do nothing */
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

    }
    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"

#ifndef USING_OS_AUTOSAROS
/**
* @brief         Determine the legitimacy of PDU
* @details       Determine the legitimacy of PDU
* @param[in]     Can_pController - Points to controller configuration data
* @param[in]     Can_pHwObject - Points to hardware object configuration data
* @param[in]     PduInfo - Pointer to SDU user memory, DLC and Identifier
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
*                Other - fail
*/
static TT_RetType Can_Drv_PriValidatePdu(TT_CONST Can_ControllerConfigType * Can_pController, \
        TT_CONST Can_HwObjectConfigType * Can_pHwObject, \
        TT_CONST Can_PduType * PduInfo)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    uint16 u16BaudrateID = 0U;
    boolean bInvalidDataLength = FALSE;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pController)
            || (NULL_PTR == Can_pHwObject)
            || (NULL_PTR == PduInfo)), CAN_DRV_SI_WRITE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        u16BaudrateID = Can_au16BaudrateIDConfig[Can_pController->Can_u8ControllerID];
        /*
         *   [SWS_Can_00218]: The function Can_Write shall return E_NOT_OK and if
         *   development error detection for the CAN module is enabled shall raise the error
         *   CAN_E_PARAM_DATA_LENGTH:
         *       - If the length is more than 64 byte.
         *       - If the length is more than 8 byte and the CAN controller is not in CAN FD
         *           mode (no CanControllerFdBaudrateConfig).
         *       - If the length is more than 8 byte and the CAN controller is in CAN FD mode
         *           (valid CanControllerFdBaudrateConfig), but the CAN FD flag in Can_PduType->id is not set.
         */
        if(TRUE == Can_pController->Can_pBaudrateConfig[u16BaudrateID].Can_bFDFrame)
        {
            if((PduInfo->length > Can_pHwObject->Can_u8PayloadLength) || ((PduInfo->length > 8U) && (CAN_FD_FRAME_U32 != (PduInfo->id & CAN_FD_FRAME_U32))))
            {
                bInvalidDataLength = TRUE;
            }
            else
            {

            }
        }
        else
        {
            if(PduInfo->length > 8U)
            {
                bInvalidDataLength = TRUE;
            }
            else
            {

            }
        }
        Can_Drv_PriParaCheck((TRUE == bInvalidDataLength), CAN_DRV_SI_WRITE, TT_RET_PARAM_LEN_ERR, &TTRetVal);
        Can_Drv_PriParaCheck(((NULL_PTR == PduInfo->sdu) && (FALSE == Can_pHwObject->Can_bTriggerTransmit)), CAN_DRV_SI_WRITE, TT_RET_PARAM_INVALID_PTR_ERR, &TTRetVal);
    }
    else
    {
        /* do nothing */
    }

    return TTRetVal;
}
#endif

/**
* @brief        Can_Drv_PriParseData
* @details      Parse the received data
* @param[out]   CanIf_Mailbox - Contains the can controller and hardware object ID and CanID
* @param[out]   CanIf_PduInfo - Pdu information
* @param[in]    pReceivedDataBuffer - Can Received Data Buffer
* @param[in]    Can_pControllerConfig - Can Controller Config
* @param[in]    Can_pHwObjectConfig - Can Hardware Object Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriParseData
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Hw_MsgBuffType * pReceivedDataBuffer,
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig,
    uint8 u8Sid
)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck(((NULL_PTR == CanIf_Mailbox)
            || (NULL_PTR == CanIf_PduInfo)
            || (NULL_PTR == pReceivedDataBuffer)
            || (NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pHwObjectConfig)), u8Sid, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        CanIf_Mailbox->CanId = pReceivedDataBuffer->msgId;
        /*
         * [SWS_Can_00423] 鈱� In case of an Extended CAN frame, the Can module shall
         * convert the ID to a standardized format since the Upper layer (CANIF) does not know
         * whether the received CAN frame is a Standard CAN frame or Extended CAN frame.
         * In case of an Extended CAN frame, MSB of a received CAN frame ID needs to be
         * made as 鈥�1鈥� to mark the received CAN frame as Extended.鈱�
         */
        if (((pReceivedDataBuffer->cs) & CAN_DRV_CS_IDE_MASK) != 0U)
        {
            CanIf_Mailbox->CanId |= (uint32)0x80000000U;
        }
        else
        {
            /* do nothing */
        }

        if (CAN_RX_NORMAL == Can_pHwObjectConfig->Can_eReceiveType)
        {
            /* Check if Mb Overrun */
            if ((uint32)(0x06000000U) == (pReceivedDataBuffer->cs & CAN_DRV_CS_CODE_MASK))
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)ModuleDet_ReportRuntimeError((uint16)CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, (uint8)u8Sid, (uint8)CAN_E_DATALOST);
#endif
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

        /* when legacy fifo enabled, FD must be disabled */
        if (CAN_RX_LEGACY_FIFO != Can_pHwObjectConfig->Can_eReceiveType)
        {
            /*
             * [SWS_Can_00501] 鈱� CanDrv shall indicate whether the received message is a
             * conventional CAN frame or a CAN FD frame as described in Can_IdType.鈱�
             */
            if (((pReceivedDataBuffer->cs) & CAN_DRV_CS_EDL_MASK) != 0U)
            {
                CanIf_Mailbox->CanId |= (uint32)0x40000000U;
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

#if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
        if (TRUE == CAN_LPDU_CALLOUT_FUNC_CALLED((uint8)Can_pHwObjectConfig->Can_HwObjectID, \
                CanIf_Mailbox->CanId, \
                pReceivedDataBuffer->dataLen, \
                &pReceivedDataBuffer->data[0]) \
        )
        {
#endif
            CanIf_Mailbox->Hoh = Can_pHwObjectConfig->Can_HwObjectID;
            CanIf_Mailbox->ControllerId = Can_pControllerConfig->Can_u8AbstControllerID;
            CanIf_PduInfo->SduLength = pReceivedDataBuffer->dataLen;
            CanIf_PduInfo->SduDataPtr = &pReceivedDataBuffer->data[0];
            CanIf_RxIndication(CanIf_Mailbox, CanIf_PduInfo);
#if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
        }
        else
        {
            /* do nothing */
        }
#endif

#if (CAN_TIMESTAMP_ENABLE == STD_ON)
        if (TRUE == Can_pHwObjectConfig->CanTimestampEnable)
        {
            Can_pControllerConfig->CanRxTimestampNotification(Can_pHwObjectConfig->Can_HwObjectID, pReceivedDataBuffer->time_stamp);
        }
        else
        {
            /* do nothing */
        }
#endif
    }
    else
    {
        /* do nothing */
    }
    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Can_Drv_PriInitLegacyFifoFilter
* @details      Initialize Legacy RXFifo Filter
* @param[in]    Can_pController - Can Controller Config
* @param[in]    Can_pHwObject - Can Hardware Object Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriInitLegacyFifoFilter(TT_CONST Can_ControllerConfigType * Can_pController, TT_CONST Can_HwObjectConfigType * Can_pHwObject)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    uint8 u8FilterIdx=0U;
    uint8 u8HwFilterCount = 0U;
    uint32 u32HwFilterMask = (uint32)0x00000000U;
    /* The max FIFO id filter affected by Rx individual masks*/
    uint8 u8FiFoFilterIndvCount = 0U;
    Flexcan_Hw_RxFifoIdElementFormatType eElementFormat = FLEXCAN_RX_FIFO_ID_FORMAT_A;
    Can_Drv_PriParaCheck(((NULL_PTR == Can_pController)
            || (NULL_PTR == Can_pHwObject)), CAN_DRV_SI_INIT, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        if (((Can_pHwObject->Can_u8HwFilterCount / 4U) + 6U) <= 32U)
        {
            u8FiFoFilterIndvCount = (Can_pHwObject->Can_u8HwFilterCount / 4U) + 6U;
        }
        else
        {
            u8FiFoFilterIndvCount = 32U;
        }
        for (u8FilterIdx=0U; ((u8FilterIdx < u8FiFoFilterIndvCount) && (u8FilterIdx < Can_pHwObject->Can_u8HwFilterCount) && (TT_RET_SUCCESS == TTRetVal)); u8FilterIdx++)
        {
            if (CAN_LEGACY_FIFO_FORMAT_A == Can_pController->Can_eLegacyAcceptanceMode)
            {
                u8HwFilterCount =  Can_pHwObject->Can_u8HwFilterCount;
                u32HwFilterMask = (uint32)0xC0000000U;
                eElementFormat = FLEXCAN_RX_FIFO_ID_FORMAT_A;
                if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                {
                    u32HwFilterMask |= Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATA_EXT_SHIFT;
                }
                else
                {
                    u32HwFilterMask |= Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATA_STD_SHIFT;
                }
            }
            else if (CAN_LEGACY_FIFO_FORMAT_B == Can_pController->Can_eLegacyAcceptanceMode)
            {
                u8HwFilterCount = Can_pHwObject->Can_u8HwFilterCount * 2U ;
                u32HwFilterMask = (uint32)0xC000C000U;
                eElementFormat = FLEXCAN_RX_FIFO_ID_FORMAT_B;
                if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                {
                    u32HwFilterMask |= (Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx * 2U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATB_EXT_SHIFT1;
                    u32HwFilterMask |= (Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 2U) + 1U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATB_EXT_SHIFT2;
                }
                else
                {
                    u32HwFilterMask |= Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx * 2U].Can_u32HwFilterMask << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATB_STD_SHIFT1;
                    u32HwFilterMask |= Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 2U) + 1U].Can_u32HwFilterMask << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATB_STD_SHIFT2;
                }
            }
            else /*CAN_LEGACY_FIFO_FORMAT_C == Can_pController->Can_eLegacyAcceptanceMode */
            {
                u8HwFilterCount =  Can_pHwObject->Can_u8HwFilterCount * 4U ;
                u32HwFilterMask = (uint32)0x00000000U;
                eElementFormat = FLEXCAN_RX_FIFO_ID_FORMAT_C;
                if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                {
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx * 4U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT1;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 1U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT2;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 2U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT3;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 3U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT4;
                }
                else
                {
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx * 4U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT1;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 1U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT2;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 2U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT3;
                    u32HwFilterMask |= (uint32)(Can_pHwObject->Can_pHwFilterConfig[(u8FilterIdx * 4U) + 3U].Can_u32HwFilterMask >> CAN_DRV_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT) << CAN_DRV_RX_FIFO_MASK_FILTER_FORMATC_STD_EXT_SHIFT4;
                }
            }
            /* Already in freeze mode */
            TTRetVal = Can_Hw_SetRxIndMask(Can_pController->Can_u8ControllerOffset, u8FilterIdx, u32HwFilterMask);
        }
        if(TT_RET_SUCCESS == TTRetVal)
        {
            TTRetVal = Can_Hw_SetRxFifoGlMsk(Can_pController->Can_u8ControllerOffset, Can_pController->Can_u32LegacyGlobalMask);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                for (u8FilterIdx=0U; u8FilterIdx < u8HwFilterCount; u8FilterIdx++)
                {
                    RxFifoFilters[u8FilterIdx].id = Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode;

                    if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                    {
                        RxFifoFilters[u8FilterIdx].isExtendedFrame = TRUE;
                    }
                    else
                    {
                        RxFifoFilters[u8FilterIdx].isExtendedFrame = FALSE;
                    }
                    RxFifoFilters[u8FilterIdx].isRemoteFrame = FALSE;
                }

                TTRetVal = Can_Hw_ConfigRxFifo(Can_pController->Can_u8ControllerOffset, eElementFormat, &RxFifoFilters[0]);
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

        Can_Drv_PriRetCheck(CAN_DRV_SI_INIT, &TTRetVal);
    }
    else
    {
        /* do nothing */
    }
    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
/**
* @brief        Can_Drv_PriProcessLegFifoPolling
* @details      Process Legacy RXFifo In Polling Mode
* @param[in]    CanIf_Mailbox - Contains the can controller and hardware object ID and CanID
* @param[in]    CanIf_PduInfo - Pdu information
* @param[in]    pReceivedDataBuffer - Can Received Data Buffer
* @param[in]    Can_pControllerConfig - Can Controller Config
* @param[in]    Can_pHwObjectConfig - Can Hardware Object Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
#if (CAN_RX_POLLING_SUPPORT == STD_ON)
static TT_RetType Can_Drv_PriProcessLegFifoPolling
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Hw_MsgBuffType * pReceivedDataBuffer,
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig
)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_StatusType status = FLEXCAN_STATUS_SUCCESS;
    uint8 u8ObjIdx = 0U;
    boolean returnResult = FALSE, bResult = FALSE;
    Can_Drv_PriParaCheck(((NULL_PTR == CanIf_Mailbox)
                || (NULL_PTR == CanIf_PduInfo)
                || (NULL_PTR == pReceivedDataBuffer)
                || (NULL_PTR == Can_pControllerConfig)
                || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_MAIN_FUNCTION_READ, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        TTRetVal = Can_Hw_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 5U, &returnResult);
        while ((u8ObjIdx < Can_pHwObjectConfig->Can_u8ObjectCount) && (TRUE == returnResult) && (TT_RET_SUCCESS == TTRetVal))
        {
            u8ObjIdx++;
            /* Check Legacy OverFlow */
            TTRetVal = Can_Hw_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 7U, &bResult);

            if ((TRUE == bResult) && (TT_RET_SUCCESS == TTRetVal))
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)ModuleDet_ReportRuntimeError((uint16)CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
#endif
                if (NULL_PTR != Can_pControllerConfig->Can_pLegacyFiFoOvfNotif)
                {
                    Can_pControllerConfig->Can_pLegacyFiFoOvfNotif();
                }
                else
                {
                    /* do nothing */
                }
                TTRetVal = Can_Hw_ClearBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 7U);
            }
            else
            {
                /* do nothing */
            }

            if(TT_RET_SUCCESS == TTRetVal)
            {
                /* Check Legacy FifoWarning */
                bResult = FALSE;
                TTRetVal = Can_Hw_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 6U, &bResult);

                if ((TRUE == bResult) && (TT_RET_SUCCESS == TTRetVal))
                {
                    if (NULL_PTR != Can_pControllerConfig->Can_pLegacyFiFoWarnNotif)
                    {
                        Can_pControllerConfig->Can_pLegacyFiFoWarnNotif();
                    }
                    else
                    {
                        /* do nothing */
                    }
                    TTRetVal = Can_Hw_ClearBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 6U);
                }
                else
                {
                    /* do nothing */
                }

                if(TT_RET_SUCCESS == TTRetVal)
                {
                    TTRetVal = Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, pReceivedDataBuffer);
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        TTRetVal = Can_Hw_MainFunctionRead(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex);
                        if(TT_RET_SUCCESS == TTRetVal)
                        {
                            TTRetVal =Can_Hw_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, Can_pHwObjectConfig->Can_u8HwBufferIndex, &status);
                            if ((FLEXCAN_STATUS_SUCCESS == status) && (TT_RET_SUCCESS == TTRetVal))
                            {
                                TTRetVal = Can_Drv_PriParseData(CanIf_Mailbox, \
                                        CanIf_PduInfo, \
                                        pReceivedDataBuffer, \
                                        Can_pControllerConfig, \
                                        Can_pHwObjectConfig, \
                                        CAN_DRV_SI_MAIN_FUNCTION_READ \
                                        );
                            }
                            else
                            {
                                /* do nothing */
                            }

                            if(TT_RET_SUCCESS == TTRetVal)
                            {
                                TTRetVal = Can_Hw_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 5U, &returnResult);
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
        Can_Drv_PriRetCheck(CAN_DRV_SI_MAIN_FUNCTION_READ, &TTRetVal);
    }
    else
    {
        /* do nothing */
    }
    return TTRetVal;
}

/**
* @brief        Can_Drv_PriProcessEnhFifoPolling
* @details      Process Enhanced RXFifo In Polling Mode
* @param[in]    CanIf_Mailbox - Contains the can controller and hardware object ID and CanID
* @param[in]    CanIf_PduInfo - Pdu information
* @param[in]    pReceivedDataBuffer - Can Received Data Buffer
* @param[in]    Can_pControllerConfig - Can Controller Config
* @param[in]    Can_pHwObjectConfig - Can Hardware Object Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
static TT_RetType Can_Drv_PriProcessEnhFifoPolling
(
    Can_HwType * CanIf_Mailbox,
    PduInfoType * CanIf_PduInfo,
    Flexcan_Hw_MsgBuffType * pReceivedDataBuffer,
    TT_CONST Can_ControllerConfigType * Can_pControllerConfig,
    TT_CONST Can_HwObjectConfigType * Can_pHwObjectConfig
)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Flexcan_Hw_StatusType status = FLEXCAN_STATUS_SUCCESS;
    uint8 u8ObjIdx = 0U;
    boolean bResult = FALSE;
    Can_Drv_PriParaCheck(((NULL_PTR == CanIf_Mailbox)
            || (NULL_PTR == CanIf_PduInfo)
            || (NULL_PTR == pReceivedDataBuffer)
            || (NULL_PTR == Can_pControllerConfig)
            || (NULL_PTR == Can_pHwObjectConfig)), CAN_DRV_SI_MAIN_FUNCTION_READ, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        while ((u8ObjIdx < Can_pHwObjectConfig->Can_u8ObjectCount) && (TT_RET_SUCCESS == TTRetVal))
        {
            u8ObjIdx++;
            /* Check Enhanced OverFlow */
            TTRetVal = Can_Hw_GetBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 255U, &bResult);
            if ((TRUE == bResult) && (TT_RET_SUCCESS == TTRetVal))
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)ModuleDet_ReportRuntimeError((uint16)CAN_DRV_MODULE_ID_C, (uint8)CAN_INSTANCE_ID, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
#endif
                if (NULL_PTR != Can_pControllerConfig->Can_pEnhanceFiFoOvfNotif)
                {
                    Can_pControllerConfig->Can_pEnhanceFiFoOvfNotif();
                }
                else
                {
                    /* do nothing */
                }
                TTRetVal = Can_Hw_ClearBuffStatusFlag(Can_pControllerConfig->Can_u8ControllerOffset, 255U);
            }
            else
            {
                /* do nothing */
            }

            if(TT_RET_SUCCESS == TTRetVal)
            {
                (void)Can_Hw_RxFifo(Can_pControllerConfig->Can_u8ControllerOffset, pReceivedDataBuffer);                   
                TTRetVal = Can_Hw_MainFunctionRead(Can_pControllerConfig->Can_u8ControllerOffset, 255U);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    TTRetVal =Can_Hw_GetTransferStatus(Can_pControllerConfig->Can_u8ControllerOffset, 255U, &status);
                    if((FLEXCAN_STATUS_SUCCESS == status) && (TT_RET_SUCCESS == TTRetVal))
                    {
                        TTRetVal = Can_Drv_PriParseData(CanIf_Mailbox, \
                                CanIf_PduInfo, \
                                pReceivedDataBuffer, \
                                Can_pControllerConfig, \
                                Can_pHwObjectConfig, \
                                CAN_DRV_SI_MAIN_FUNCTION_READ \
                        );
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
        }
        Can_Drv_PriRetCheck(CAN_DRV_SI_MAIN_FUNCTION_READ, &TTRetVal);
    }
    else
    {
        /* do nothing */
    }
    return TTRetVal;
}
#endif /* (CAN_ENHANCED_FIFO_ENABLED == STD_ON) */
#endif /* (CAN_RX_POLLING_SUPPORT == STD_ON) */

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Can_Drv_PriInitRx
* @details      Init all Rx objects
* @param[in]    Can_pController - Can Controller Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriInitRx(TT_CONST Can_ControllerConfigType * Can_pController)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    uint8 u8HwObjRefIdx = 0U;
    TT_CONST Can_HwObjectConfigType * Can_pHwObject;
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
    uint8 u8FilterIdx = 0U;
#endif
    Flexcan_Hw_DataInfoType DataInfo = {0};

    Can_Drv_PriParaCheck((NULL_PTR == Can_pController), CAN_DRV_SI_INIT, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* This function just is called only if controller is in freeze mode */
        /* Always enable individual mask , Already in freeze mode */
        TTRetVal = Can_Hw_SetRxMaskType(Can_pController->Can_u8ControllerOffset, FLEXCAN_RX_MASK_INDIVIDUAL);
        for (u8HwObjRefIdx = 0U; ((u8HwObjRefIdx < Can_pController->Can_u8HwObjectRefCount) && (TT_RET_SUCCESS == TTRetVal)); u8HwObjRefIdx++)
        {
            Can_pHwObject = (TT_CONST Can_HwObjectConfigType *)Can_pController->Can_ppHwObject[u8HwObjRefIdx];
            if (CAN_RX_NORMAL == Can_pHwObject->Can_eReceiveType)
            {
                DataInfo.fd_enable = FALSE;
                DataInfo.data_length = 0U;
                if (Can_pHwObject->Can_IdMessage != CAN_STANDARD)
                {
                    DataInfo.msg_id_type = FLEXCAN_MSG_ID_EXT;
                }
                else
                {
                    DataInfo.msg_id_type = FLEXCAN_MSG_ID_STD;
                }
                TTRetVal = Can_Hw_ConfigRxMb(Can_pController->Can_u8ControllerOffset, Can_pHwObject->Can_u8HwBufferIndex, &DataInfo, Can_pHwObject->Can_pHwFilterConfig->Can_u32HwFilterCode);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    /* Already in freeze mode */
                    TTRetVal = Can_Hw_SetRxIndMask(Can_pController->Can_u8ControllerOffset, Can_pHwObject->Can_u8HwBufferIndex, Can_pHwObject->Can_pHwFilterConfig->Can_u32HwFilterMask);
                }
                else
                {
                    /* do nothing */
                }
            }
            else if (CAN_RX_LEGACY_FIFO == Can_pHwObject->Can_eReceiveType)
            {
                TTRetVal = Can_Drv_PriInitLegacyFifoFilter(Can_pController, Can_pHwObject);
            }
#if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
            else if (CAN_RX_ENHANCED_FIFO == Can_pHwObject->Can_eReceiveType)
            {
                for (u8FilterIdx=0U; u8FilterIdx < Can_pHwObject->Can_u8HwFilterCount; u8FilterIdx++)
                {
                    /* The first 2 MSB bits are filter type encoding ! */
                    if ((uint32)FLEXCAN_HW_ENHANCED_RX_FIFO_TWO_ID_FILTER == ((Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode & 0xC0000000U) >> 30U))
                    {
                        RxFifoFiltersEnhanced[u8FilterIdx].filterType = FLEXCAN_HW_ENHANCED_RX_FIFO_TWO_ID_FILTER;
                    }
                    else if ((uint32)FLEXCAN_HW_ENHANCED_RX_FIFO_RANGE_ID_FILTER == ((Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode & 0xC0000000U) >> 30U))
                    {
                        RxFifoFiltersEnhanced[u8FilterIdx].filterType = FLEXCAN_HW_ENHANCED_RX_FIFO_RANGE_ID_FILTER;
                    }
                    else
                    {
                        RxFifoFiltersEnhanced[u8FilterIdx].filterType = FLEXCAN_HW_ENHANCED_RX_FIFO_ONE_ID_FILTER;
                    }
                    /* If less num_enhanced_ext_id_filters,config extended id */
                    if(u8FilterIdx < Can_pController->HwChannelIpConfig->pFlexcanIpHwConfig->num_enhanced_ext_id_filters)
                    {
                        if(((Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode >> 29U) & 0x1U) == 1)
                        {
                            RxFifoFiltersEnhanced[u8FilterIdx].rtr2 = TRUE;
                        }
                        else
                        {
                            /*Do nothing*/
                        }

                        if(((Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask >> 29U) & 0x1U) == 1)
                        {
                            RxFifoFiltersEnhanced[u8FilterIdx].rtr1 = TRUE;
                        }
                        else
                        {
                            /*Do nothing*/
                        }
                        RxFifoFiltersEnhanced[u8FilterIdx].isExtendedFrame = TRUE;
                        RxFifoFiltersEnhanced[u8FilterIdx].id1 = Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask & 0x1FFFFFFFU;
                        RxFifoFiltersEnhanced[u8FilterIdx].id2 = Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode & 0x1FFFFFFFU;
                    }
                    else
                    {
                        if(((Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode >> 11U) & 0x1U) == 1)
                        {
                            RxFifoFiltersEnhanced[u8FilterIdx].rtr2 = TRUE;
                        }
                        else
                        {
                            /*Do nothing*/
                        }

                        if(((Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask >> 11U) & 0x1U) == 1)
                        {
                            RxFifoFiltersEnhanced[u8FilterIdx].rtr1 = TRUE;
                        }
                        else
                        {
                            /*Do nothing*/
                        }
                        RxFifoFiltersEnhanced[u8FilterIdx].isExtendedFrame = FALSE;
                        RxFifoFiltersEnhanced[u8FilterIdx].id1 = Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterMask & 0x7FFU;
                        RxFifoFiltersEnhanced[u8FilterIdx].id2 = Can_pHwObject->Can_pHwFilterConfig[u8FilterIdx].Can_u32HwFilterCode & 0x7FFU;
                    }
                }

                TTRetVal = Can_Hw_ConfigEnhancedRxFifo(Can_pController->Can_u8ControllerOffset, &RxFifoFiltersEnhanced[0]);
            }
            else
            {
                /* do nothing */
            }
#else
            else
            {
                /* do nothing */
            }
#endif
        }
        Can_Drv_PriRetCheck(CAN_DRV_SI_INIT, &TTRetVal);
    }
    else
    {
        /* do nothing */
    }
    return TTRetVal;
}

#define CAN_STOP_SEC_CODE_SLOW
#include "Can_MemMap.h"


#define CAN_START_SEC_CODE_SLOW
#include "Can_MemMap.h"
/**
* @brief        Can_Drv_PriInitControllers
* @details      Initialize Controller
* @param[in]    Can_pControllerConfig - Can Controller Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriInitControllers(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    /* The Index of Hoh in a group that refer to a controller */
    uint8 u8HwObjRefIdx = 0U;
    uint8 u8ObjIdx = 0U;
    TT_CONST Can_HwObjectConfigType * Can_pHwObject = NULL_PTR;
    uint8 u8HwBufferCount = 0U;
#endif
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_INIT, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);

    if(TT_RET_SUCCESS == TTRetVal)
    {
        Can_au16BaudrateIDConfig[Can_pControllerConfig->Can_u8ControllerID] = Can_pControllerConfig->Can_u16DefaultBaudrateID;

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
        Can_Drv_eListenOnlyMode[Can_pControllerConfig->Can_u8ControllerID] = NORMAL_MODE;
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

        /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
        TTRetVal = (TT_RetType)Call_Can_FlexCan_Init(Can_pControllerConfig->Can_u8ControllerOffset, Can_Drv_apxStatus[Can_pControllerConfig->Can_u8ControllerID], Can_pControllerConfig->HwChannelIpConfig->pFlexcanIpHwConfig);
        if(TT_RET_SUCCESS == TTRetVal)
        {
            TTRetVal = Can_Hw_SetPriority(Can_pControllerConfig->Can_u8ControllerOffset, Can_pControllerConfig->Tx_Priority, Can_pControllerConfig->Rx_Priority);
            if(TT_RET_SUCCESS == TTRetVal)
            {
                /* by defaut, enable interrupt when setcontroller to start */
                Can_Drv_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID] = TRUE;
                /* disable all interrupts */
                TTRetVal = Can_Hw_DisInterrupts(Can_pControllerConfig->Can_u8ControllerOffset);
                if(TT_RET_SUCCESS == TTRetVal)
                {
                    /* If the FlexCAN_Init retuns SUCCESS then the module is already in freezemode, and Can_Hw_SetTDCOffset and Can_Hw_SetTxArbDelay will always retun success */
                    if (Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_bFDFrame)
                    {
                        TTRetVal = Can_Hw_SetTDCOffset(Can_pControllerConfig->Can_u8ControllerOffset, \
                                Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_bTrcvDelayEnable, \
                                Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_u8TrcvDelayCompOffset);
                    }
                    else
                    {

                    }
                    if(TT_RET_SUCCESS == TTRetVal)
                    {
                        TTRetVal = Can_Hw_SetTxArbDelay(Can_pControllerConfig->Can_u8ControllerOffset, \
                                Can_pControllerConfig->Can_pBaudrateConfig[Can_pControllerConfig->Can_u16DefaultBaudrateID].Can_u8TxArbitrationStartDelay);
                        if(TT_RET_SUCCESS == TTRetVal)
                        {
                            /* Init all Rx objects */
                            TTRetVal = Can_Drv_PriInitRx(Can_pControllerConfig);
                            if(TT_RET_SUCCESS == TTRetVal)
                            {
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
                                for (u8HwBufferCount = 0U; u8HwBufferCount < ((uint8)CAN_HWMB_COUNT); u8HwBufferCount++)
                                {
                                    Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][u8HwBufferCount] = (Can_HwHandleType)CAN_HWOBJ_UNMAPPED;
                                }
                                /* Map MB index to hardware object ID */
                                for (u8HwObjRefIdx = 0U; u8HwObjRefIdx < Can_pControllerConfig->Can_u8HwObjectRefCount; u8HwObjRefIdx++)
                                {
                                    Can_pHwObject = Can_pControllerConfig->Can_ppHwObject[u8HwObjRefIdx];
                                    switch (Can_pHwObject->Can_eReceiveType)
                                    {
                                    case CAN_TX_NORMAL:

                                        for (u8ObjIdx = 0U; u8ObjIdx < Can_pHwObject->Can_u8ObjectCount; u8ObjIdx++)
                                        {
                                            Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObject->Can_u8HwBufferIndex + u8ObjIdx] = Can_pHwObject->Can_HwObjectID;
                                        }
                                        break;

                                    case CAN_RX_NORMAL:

                                        Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObject->Can_u8HwBufferIndex] = Can_pHwObject->Can_HwObjectID;
                                        break;

                                    case CAN_RX_LEGACY_FIFO:

                                        Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][Can_pHwObject->Can_u8HwBufferIndex] = Can_pHwObject->Can_HwObjectID;
                                        Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][6U] = Can_pHwObject->Can_HwObjectID;
                                        Can_Drv_au16MbIdxToObjIDMap[Can_pControllerConfig->Can_u8ControllerID][7U] = Can_pHwObject->Can_HwObjectID;
                                        break;

                                    default:
                                        /* do nothing */
                                        break;

                                    }
                                }
#endif /* MB_INTERRUPT_SUPPORT */
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
        }
        else
        {

        }
        Can_Drv_PriRetCheck(CAN_DRV_SI_INIT, &TTRetVal);
    }
    else
    {

    }

    return TTRetVal;
}

/**
* @brief        Can_Drv_PriDeInitControllers
* @details      De-Initialize Controller
* @param[in]    Can_pControllerConfig - Can Controller Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriDeInitControllers(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_DEINIT, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        /* @violates @ref Can_Drv_c_REF_3 MISRA 2012 Advisory Rule 12.3 */
        TTRetVal = Can_Hw_Deinit(Can_pControllerConfig->Can_u8ControllerOffset);
        Can_Drv_PriRetCheck(CAN_DRV_SI_DEINIT, &TTRetVal);
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
* @brief        Can_Drv_PriSetControlerErrInit
* @details      Set Error Initialization and set Controller to start Mode
* @param[in]    Can_pControllerConfig - Can Controller Config
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Other - fail
*/
static TT_RetType Can_Drv_PriSetControlerErrInit(TT_CONST Can_ControllerConfigType * Can_pControllerConfig)
{
    TT_RetType TTRetVal = TT_RET_SUCCESS;
    TT_RetType TTRetValArray[6] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};
    Can_Drv_PriParaCheck((NULL_PTR == Can_pControllerConfig), CAN_DRV_SI_SET_CONTROLLER_TO_START_MODE, TT_RET_PARAM_NULL_PTR_ERR, &TTRetVal);
    if(TT_RET_SUCCESS == TTRetVal)
    {
        if (TRUE == Can_Drv_abIsInterruptEnabled[Can_pControllerConfig->Can_u8ControllerID])
        {
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
            if (Can_pControllerConfig->bErrEn)
            {
                TTRetValArray[0] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_ERR, TRUE);
#if (FLEXCAN_HW_FEATURE_HAS_FD == STD_ON)
                TTRetValArray[1] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_ERR_FAST, TRUE);
#endif /* FLEXCAN_HW_FEATURE_HAS_FD */
                TTRetValArray[2] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_TX_WARNING, TRUE);
                TTRetValArray[3] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_RX_WARNING, TRUE);
            }
            else
            {

            }
#endif /* ERROR_INTERRUPT_SUPPORT */
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
            if (FALSE == Can_pControllerConfig->Can_bBusOffUsesPolling)
            {
                TTRetValArray[4] = Can_Hw_SetErrorInt(Can_pControllerConfig->Can_u8ControllerOffset, FLEXCAN_HW_INT_BUSOFF, TRUE);
            }
            else
            {

            }
#endif  /* BUSOFF_INTERRUPT_SUPPORT */

#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
            if (FLEXCAN_RXFIFO_USING_DMA == Can_pControllerConfig->HwChannelIpConfig->pFlexcanIpHwConfig->transfer_type)
            {
                TTRetValArray[5] = Can_Hw_ConfigRxFifoDMAReqCount(Can_pControllerConfig->Can_u8ControllerOffset);
            }
            else
            {

            }
#endif
        }
        else
        {

        }
        if((TT_RET_SUCCESS != TTRetValArray[0])
                || (TT_RET_SUCCESS != TTRetValArray[1])
                || (TT_RET_SUCCESS != TTRetValArray[2])
                || (TT_RET_SUCCESS != TTRetValArray[3])
                || (TT_RET_SUCCESS != TTRetValArray[4])
                || (TT_RET_SUCCESS != TTRetValArray[5]))
        {
            TTRetVal = TT_RET_OPT_REG_ERR;
        }
        else
        {
            TTRetVal = Can_Hw_SetStartMode(Can_pControllerConfig->Can_u8ControllerOffset);
        }

        Can_Drv_PriRetCheck(CAN_DRV_SI_SET_CONTROLLER_TO_START_MODE, &TTRetVal);
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

/** @} */
