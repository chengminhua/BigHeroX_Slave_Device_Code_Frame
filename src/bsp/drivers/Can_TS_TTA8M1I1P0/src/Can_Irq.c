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
**  FILENAME     : Can_Irq.c                                                  **
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
#include "Can_Irq.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define CAN_IRQ_VENDOR_ID_C                    1541
#define CAN_IRQ_MODULE_ID_C                    80
#define CAN_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
#define CAN_IRQ_AR_RELEASE_MINOR_VERSION_C     4
#define CAN_IRQ_AR_RELEASE_PATCH_VERSION_C     0
#define CAN_IRQ_SW_MAJOR_VERSION_C             1
#define CAN_IRQ_SW_MINOR_VERSION_C             1
#define CAN_IRQ_SW_PATCH_VERSION_C             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if current file and Can_Irq header file are of the same vendor */
#if (CAN_IRQ_VENDOR_ID_C != CAN_IRQ_VENDOR_ID_H)
    #error "Can_Irq.c and Can_Irq.h have different vendor ids"
#endif
#if (CAN_IRQ_MODULE_ID_C != CAN_IRQ_MODULE_ID_H)
    #error "Can_Irq.c and Can_Irq.h have different module ids"
#endif
/* Check if current file and Can_Irq header file are of the same Autosar version */
#if ((CAN_IRQ_AR_RELEASE_MAJOR_VERSION_C    != CAN_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IRQ_AR_RELEASE_MINOR_VERSION_C    != CAN_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IRQ_AR_RELEASE_PATCH_VERSION_C != CAN_IRQ_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_Irq.c and Can_Irq.h are different"
#endif
/* Check if current file and Can_Irq header file are of the same Software version */
#if ((CAN_IRQ_SW_MAJOR_VERSION_C != CAN_IRQ_SW_MAJOR_VERSION_H) || \
     (CAN_IRQ_SW_MINOR_VERSION_C != CAN_IRQ_SW_MINOR_VERSION_H) || \
     (CAN_IRQ_SW_PATCH_VERSION_C != CAN_IRQ_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_Irq.c and Can_Irq.h are different"
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
#define CAN_START_SEC_VAR_FAST_CLEARED_PTR
#include "Can_MemMap.h"

/* Saving configuration data */
TT_CONST Can_ConfigType * Can_apxConfig;

#define CAN_STOP_SEC_VAR_FAST_CLEARED_PTR
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

/* Saving Controller State */
Can_ControllerStateType Can_eControllerState[CAN_CONTROLLER_CONFIG_COUNT];

#define CAN_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"
/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define CAN_START_SEC_CODE_FAST
#include "Can_MemMap.h"
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)

/******************************************************************************
*  Service name     : Can_ProcessMesgBufferCommonInterrupt
*  Syntax           : void Can_ProcessMesgBufferCommonInterrupt(uint8 u8CtrlOffset, uint8 u8MbIdx, Can_MbType mbType)     
*  Service ID       : None                                                  
*  Sync/Async       : Synchronous                                               
*  Reentrancy       : Non reentrant                                             
*  Parameters (in)  : u8CtrlOffset - The hardware offset of Controller
                      u8MbIdx - The index of Message Buffer
                      mbType
*  Parameters (out) : None                                                     
*  Return value     : None                                                    
*  Description      : Function process Message Buffer Interrupt                    
******************************************************************************/
void Can_ProcessMesgBufferCommonInterrupt
(
    uint8 u8CtrlOffset,
    uint8 u8MbIdx,
    Can_MbType mbType
)
{
    uint8 u8ControllerID = 0U;
    TT_CONST Can_ControllerConfigType * Can_pController = NULL_PTR;

    if (NULL_PTR != Can_apxConfig)
    {
        u8ControllerID = Can_apxConfig->Can_pCtrlOffsetToCtrlIDMap[u8CtrlOffset];
        Can_pController = Can_apxConfig->Can_ppController[u8ControllerID];
        if (NULL_PTR != Can_pController)
        {
            switch (mbType)
            {
                case CAN_TX_NORMAL:
                {
                    (void)Can_Drv_ProcessTxMesgBuffer(Can_pController, Can_apxConfig->Can_pHwObjectConfig, u8MbIdx);
                    break;
                }
                case CAN_RX_NORMAL:
                {
                    (void)Can_Drv_ProcessRxMesgBuffer(Can_pController, Can_apxConfig->Can_pHwObjectConfig, u8MbIdx);
                    break;
                }
                case CAN_RX_LEGACY_FIFO:
                {
                #if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
                    if (u8MbIdx > 7U)
                    {
                        (void)Can_Drv_ProcessRxLegacyDma(Can_pController, Can_apxConfig->Can_pHwObjectConfig, u8MbIdx);
                    }
                    else
                #endif
                    {
                        (void)Can_Drv_ProcessRxMesgBuffer(Can_pController, Can_apxConfig->Can_pHwObjectConfig, u8MbIdx);
                    }
                    break;
                }
            #if (CAN_ENHANCED_FIFO_ENABLED == STD_ON)
                case CAN_RX_ENHANCED_FIFO:
                {
                    (void)Can_Drv_ProcessRxEnhance(Can_pController, Can_pController->Can_ppHwObject[0U], u8MbIdx);
                    break;
                }
            #endif
                default:
                {
                    /* prevent misra */
                    break;
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
#endif /* CAN_MB_INTERRUPT_SUPPORT == STD_ON */

/******************************************************************************
*  Service name     : Can_ProcessBusOffInterrupt                                              
*  Syntax           : void Can_ProcessBusOffInterrupt(uint8 u8CtrlOffset)    
*  Service ID       : None                                                  
*  Sync/Async       : Synchronous                                               
*  Reentrancy       : Non reentrant                                             
*  Parameters (in)  : u8CtrlOffset - The hardware offset of Controller
*  Parameters (out) : None                                                     
*  Return value     : None                                                    
*  Description      : Function process Bus Off Interrupt/Polling. This function is invoked when busOff occurred.                    
******************************************************************************/
void Can_ProcessBusOffInterrupt(uint8 u8CtrlOffset)
{
    uint8 u8ControllerID = 0U;
    TT_CONST Can_ControllerConfigType * Can_pController = NULL_PTR;

    if (NULL_PTR != Can_apxConfig)
    {
        u8ControllerID = Can_apxConfig->Can_pCtrlOffsetToCtrlIDMap[u8CtrlOffset];
        Can_pController = Can_apxConfig->Can_ppController[u8ControllerID];
        if (NULL_PTR != Can_pController)
        {
            if ((Std_ReturnType)E_OK == Can_Drv_SetControllerToStopMode(Can_pController))
            {
                Can_eControllerState[u8ControllerID] = CAN_CS_STOPPED;
#ifdef USING_OS_AUTOSAROS               
                CanIf_ControllerBusOff(Can_pController->Can_u8AbstControllerID);
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
}

#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)

/******************************************************************************
*  Service name     : Can_ProcessErrorInterrupt                                              
*  Syntax           : void Can_ProcessErrorInterrupt(uint8 u8CtrlOffset, boolean bIsErrFast)    
*  Service ID       : None                                                  
*  Sync/Async       : Synchronous                                               
*  Reentrancy       : Non reentrant                                             
*  Parameters (in)  : u8CtrlOffset - The hardware offset of Controller
                      bIsErrFast - whether to enable/disable CANFD error notify
*  Parameters (out) : None                                                     
*  Return value     : None                                                    
*  Description      : unction process Error Interrupt                    
******************************************************************************/
void Can_ProcessErrorInterrupt(uint8 u8CtrlOffset, boolean bIsErrFast)
{
    uint8 u8ControllerID = 0U;
    TT_CONST Can_ControllerConfigType * Can_pController = NULL_PTR;

    if (NULL_PTR != Can_apxConfig)
    {
        u8ControllerID = Can_apxConfig->Can_pCtrlOffsetToCtrlIDMap[u8CtrlOffset];

        Can_pController = Can_apxConfig->Can_ppController[u8ControllerID];
        if (NULL_PTR != Can_pController)
        {
            if (TRUE == bIsErrFast)
            {
                if (NULL_PTR != Can_pController->Can_pFDErrNotif)
                {
                    Can_pController->Can_pFDErrNotif();
                }
                else
                {

                }
            }
            else
            {
                if (NULL_PTR != Can_pController->Can_pErrNotif)
                {
                    Can_pController->Can_pErrNotif();
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
#endif
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/******************************************************************************
*  Service name     : Can_ProcessPNInterrupt
*  Syntax           : void Can_ProcessPNInterrupt(uint8 u8CtrlOffset)
*  Service ID       : None
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : u8CtrlOffset
*  Parameters (out) : None
*  Return value     : None
*  Description      :
******************************************************************************/
void Can_ProcessPNInterrupt(uint8 u8CtrlOffset)
{
    uint8 u8ControllerID = 0U;
    TT_CONST Can_ControllerConfigType * Can_pController = NULL_PTR;
    if(NULL_PTR != Can_apxConfig)
    {
        u8ControllerID = Can_apxConfig->Can_pCtrlOffsetToCtrlIDMap[u8CtrlOffset];
        Can_pController = Can_apxConfig->Can_ppController[u8ControllerID];
        /* Check if the configuration assigned for controller is valid */
        if ((NULL_PTR != Can_pController) && (Can_apxCtrlConfigIcomIndex[u8ControllerID] != NULL_PTR))
        {
            (void)Can_Drv_ProcessPN(Can_pController, Can_apxCtrlConfigIcomIndex[u8ControllerID]);
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
    return;
}
#endif


#if ((CAN_MB_INTERRUPT_SUPPORT == STD_ON) || (CAN_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON))
void Can_CommonIrqCallback(uint8 u8Instance,
                           Flexcan_Hw_EventType event,
                           uint32 u32buffIdx,
                           TT_CONST Flexcan_Hw_StateType *driverState)
{
#if (CAN_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    if (FLEXCAN_HW_MB_ENHANCED_RXFIFO == u32buffIdx)
    {
        if (FALSE == driverState->enhancedFifoOutput.isPolling)
        {
            switch (event)
            {
                case FLEXCAN_EVENT_ENHANCED_RXFIFO_COMPLETE:
                /*case FLEXCAN_EVENT_ENHANCED_RXFIFO_WATERMARK: not supported on HLD yet */
                case FLEXCAN_EVENT_ENHANCED_RXFIFO_OVERFLOW:
                /* case FLEXCAN_EVENT_ENHANCED_RXFIFO_UNDERFLOW: not supported on HLD yet */
                {
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
                    Can_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)event, CAN_RX_ENHANCED_FIFO);
#endif/* (CAN_MB_INTERRUPT_SUPPORT == STD_ON) */
                    break;
                }
                default:
                {
                    /* nothing to do */
                    break;
                }
            }
        }
    #if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if ((FLEXCAN_EVENT_DMA_COMPLETE == event) || (FLEXCAN_EVENT_DMA_ERROR == event))
        {
            Can_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)event, CAN_RX_ENHANCED_FIFO);
        }
    #endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        else
        {
            /* prevent misra */
        }
    }
    else
    {
#endif /* CAN_FEATURE_HAS_ENHANCED_RX_FIFO */
    #if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
        /* This callback is just used for interrupt buffter */
        if (FALSE == (driverState->mbs[u32buffIdx].isPolling))
        {
            switch (event)
            {
                case FLEXCAN_EVENT_TX_COMPLETE:
                {
                    Can_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)u32buffIdx, CAN_TX_NORMAL);
                    break;
                }
                case FLEXCAN_EVENT_RX_COMPLETE:
                {
                    Can_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)u32buffIdx, CAN_RX_NORMAL);
                    break;
                }
                case FLEXCAN_EVENT_RXFIFO_COMPLETE:
                {
                    Can_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)u32buffIdx, CAN_RX_LEGACY_FIFO);
                    break;
                }
                case FLEXCAN_EVENT_RXFIFO_WARNING:
                {
                    Can_ProcessMesgBufferCommonInterrupt(u8Instance, 6U, CAN_RX_LEGACY_FIFO);
                    break;
                }
                case FLEXCAN_EVENT_RXFIFO_OVERFLOW:
                {
                    Can_ProcessMesgBufferCommonInterrupt(u8Instance, 7U, CAN_RX_LEGACY_FIFO);
                    break;
                }
                default:
                {
                    /* nothing to do */
                    break;
                }
            }
        }
    #endif /* (CAN_MB_INTERRUPT_SUPPORT == STD_ON) */
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if ((FLEXCAN_EVENT_DMA_COMPLETE == event) || (FLEXCAN_EVENT_DMA_ERROR == event))
        {
            Can_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)event, CAN_RX_LEGACY_FIFO);
        }
#endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)*/
#if ((CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) || (CAN_MB_INTERRUPT_SUPPORT == STD_ON))
        else
        {
            /* prevent misra */
        }
#endif      
#if (CAN_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    }
#endif /* (CAN_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

#if (CAN_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
    if (FLEXCAN_EVENT_WAKEUP_MATCH == event)
    {
        Can_ProcessPNInterrupt(u8Instance);
    }
    else
    {

    }
#endif /* (CAN_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */
    (void)u32buffIdx;
    (void)driverState;
}
#endif

void Can_ErrorIrqCallback(uint8 u8Instance,
                          Flexcan_Hw_EventType event,
                          uint32 u32ErrStatus,
                          TT_CONST Flexcan_Hw_StateType * flexcanState)
{
    (void) u32ErrStatus; /* not used yet */
    (void) flexcanState; /* not used yet */
    
    switch (event)
    {
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
        case FLEXCAN_EVENT_ERROR:
        {
            Can_ProcessErrorInterrupt(u8Instance, FALSE);
            break;
        }
    #if (CAN_FEATURE_HAS_FD == STD_ON)
        case FLEXCAN_EVENT_ERROR_FAST:
        {
            Can_ProcessErrorInterrupt(u8Instance, TRUE);
            break;
        }
    #endif /* CAN_FEATURE_HAS_FD */
#endif /* (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON) */
        /* this function is called for both interrupt & polling */
        case FLEXCAN_EVENT_BUSOFF:
        {
            Can_ProcessBusOffInterrupt(u8Instance);
            break;
        }
        default:
        {
            /* nothing to do */
            break;
        }
    }
}   

#define CAN_STOP_SEC_CODE_FAST
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
