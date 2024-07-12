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
**  FILENAME     : Dio_Hw_Irq.h                                               **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Dio Driver Source File                                     **
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
#include "Dio_Hw_Irq.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_HW_IRQ_VENDOR_ID_C                      (1541)
#define DIO_HW_IRQ_MODULE_ID_C                      (120)
#define DIO_HW_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define DIO_HW_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define DIO_HW_IRQ_AR_RELEASE_PATCH_VERSION_C       (0)
#define DIO_HW_IRQ_SW_MAJOR_VERSION_C               (1)
#define DIO_HW_IRQ_SW_MINOR_VERSION_C               (1)
#define DIO_HW_IRQ_SW_PATCH_VERSION_C               (0)
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dio_Hw_Irq.h Dio_Hw_Irq.c file version check */
#if (DIO_HW_IRQ_VENDOR_ID_C != DIO_HW_IRQ_VENDOR_ID_H)
    #error "Dio_Hw_Irq.h and Dio_Hw_Irq.c have different vendor id"
#endif

#if (DIO_HW_IRQ_MODULE_ID_C != DIO_HW_IRQ_MODULE_ID_H)
    #error "Dio_Hw_Irq.h and Dio_Hw_Irq.c have different module id"
#endif

#if ((DIO_HW_IRQ_AR_RELEASE_MAJOR_VERSION_C != DIO_HW_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_HW_IRQ_AR_RELEASE_MINOR_VERSION_C != DIO_HW_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_HW_IRQ_AR_RELEASE_PATCH_VERSION_C != DIO_HW_IRQ_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Hw_Irq.h and Dio_Hw_Irq.c are different"
#endif

#if ((DIO_HW_IRQ_SW_MAJOR_VERSION_C != DIO_HW_IRQ_SW_MAJOR_VERSION_H) || \
     (DIO_HW_IRQ_SW_MINOR_VERSION_C != DIO_HW_IRQ_SW_MINOR_VERSION_H) || \
     (DIO_HW_IRQ_SW_PATCH_VERSION_C != DIO_HW_IRQ_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Hw_Irq.h and Dio_Hw_Irq.c are different"
#endif

#ifndef USING_OS_AUTOSAROS
#if(GPIO0_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOA_IRQHandler);
#endif

#if(GPIO1_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOB_IRQHandler);
#endif

#if(GPIO2_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOC_IRQHandler);
#endif

#if(GPIO3_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOD_IRQHandler);
#endif

#if(GPIO4_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOE_IRQHandler);
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
#define DIO_START_SEC_VAR_INIT_PTR
#include "Dio_MemMap.h"
/* An array of Pointers to store the base address of the Dio register */
static Dio_RegType *DioIrqHwReg[] = TT_GPIO_BASE_PTRS; 

#define DIO_STOP_SEC_VAR_INIT_PTR
#include "Dio_MemMap.h"

#define DIO_START_SEC_VAR_CLEARED_PTR
#include "Dio_MemMap.h"
/* Pointer to Dio configuration data */
static TT_CONST Dio_GlobalType* Dio_GlobalPtr = NULL_PTR; 

#define DIO_STOP_SEC_VAR_CLEARED_PTR
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE_SLOW
#include "Dio_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/

/******************************************************************************
*                            Public Functions                                     
******************************************************************************/
/**
* @brief        Dio_Hw_Interrupt_init
* @details      Initializes the Dio Interrupt.
* @param[in]    ChannelId - Id of DIO channel
*               TriggerMode - Dio Exit Trigger Type
* @return
* @retval
* @pre
*/
TT_RetType Dio_Hw_Interrupt_Init(TT_CONST Dio_ChannelType ChannelId,
                                 TT_CONST Dio_ExitTriggerType  TriggerMode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 IrqNum = 0;

    Dio_PortType TT_CONST PortId   = DIO_GET_PORT_FROM_CHANNEL_ID(ChannelId);
    Dio_PortLevelType TT_CONST Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_CHANNEL_ID(ChannelId);

    TT_ParaCheck((ChannelId >= DIO_ALL_CHANNEL), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((TriggerMode > DIO_TRIGGER_LOW), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Dio_GlobalPtr = &Dio_GlobalData;
        DioIrqHwReg[PortId]->DIR &= ~(uint32)(0x1UL << Bit);
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00();
#endif
        switch(TriggerMode)
        {
            case DIO_TRIGGER_RISING:
                DioIrqHwReg[PortId]->IBE &= ~(uint32)(0x1UL << Bit);
                DioIrqHwReg[PortId]->IEV |= (uint32)(0x1UL << Bit);
                DioIrqHwReg[PortId]->IS &= ~(uint32)(0x1UL << Bit);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                TT_ParaCheck((DioIrqHwReg[PortId]->IBE & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
                TT_ParaCheck((0 == (DioIrqHwReg[PortId]->IEV & (uint32)(0x1UL << Bit))), TT_RET_OPT_REG_ERR, &Ret);
                TT_ParaCheck((DioIrqHwReg[PortId]->IS  & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
#endif
                break;
            case DIO_TRIGGER_FALLING:
                DioIrqHwReg[PortId]->IBE &= ~(uint32)(0x1UL << Bit);
                DioIrqHwReg[PortId]->IEV &= ~(uint32)(0x1UL << Bit);
                DioIrqHwReg[PortId]->IS &= ~(uint32)(0x1UL << Bit);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                TT_ParaCheck((DioIrqHwReg[PortId]->IBE & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
                TT_ParaCheck((DioIrqHwReg[PortId]->IEV & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
                TT_ParaCheck((DioIrqHwReg[PortId]->IS  & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
#endif
                break;
            case DIO_TRIGGER_BOTH:
                DioIrqHwReg[PortId]->IBE |= (uint32)(0x1UL << Bit);
                DioIrqHwReg[PortId]->IS &= ~(uint32)(0x1UL << Bit);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                TT_ParaCheck((0 == (DioIrqHwReg[PortId]->IBE & (uint32)(0x1UL << Bit))), TT_RET_OPT_REG_ERR, &Ret);
                TT_ParaCheck((DioIrqHwReg[PortId]->IS & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
#endif
                break;
            case DIO_TRIGGER_HIGH:
                DioIrqHwReg[PortId]->IS |= (uint32)(0x1UL << Bit);
                DioIrqHwReg[PortId]->IEV |= (uint32)(0x1UL << Bit);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                TT_ParaCheck(0 == (DioIrqHwReg[PortId]->IS & (uint32)(0x1UL << Bit)), TT_RET_OPT_REG_ERR, &Ret);
                TT_ParaCheck(0 == (DioIrqHwReg[PortId]->IEV & (uint32)(0x1UL << Bit)), TT_RET_OPT_REG_ERR, &Ret);
#endif
                break;
            default:
                DioIrqHwReg[PortId]->IS |= (uint32)(0x1UL << Bit);
                DioIrqHwReg[PortId]->IEV &= ~(uint32)(0x1UL << Bit);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                TT_ParaCheck((0 == (DioIrqHwReg[PortId]->IS & (uint32)(0x1UL << Bit))), TT_RET_OPT_REG_ERR, &Ret);
                TT_ParaCheck((DioIrqHwReg[PortId]->IEV & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
#endif
                break;
        }
        IrqNum = DioIrqHwReg[PortId]->RIS;
        DioIrqHwReg[PortId]->IC = IrqNum;
        DioIrqHwReg[PortId]->IE |= (uint32)(0x1UL << Bit);
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00();
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck(0 == (DioIrqHwReg[PortId]->IE & (uint32)(0x1UL << Bit)), TT_RET_OPT_REG_ERR, &Ret);
#endif
    }
    else
    {
        /* do nothing */
    }
    
    return Ret;
}

/**
* @brief        Dio_Hw_Interrupt_Deinit
* @details      Initializes the Dio Interrupt.
* @param[in]    ChannelId - Id of DIO channel
* @return
* @retval
* @pre
*/
TT_RetType Dio_Hw_Interrupt_DeInit(TT_CONST Dio_ChannelType ChannelId)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Dio_PortType TT_CONST PortId   = DIO_GET_PORT_FROM_CHANNEL_ID(ChannelId);
    Dio_PortLevelType TT_CONST Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_CHANNEL_ID(ChannelId);

    TT_ParaCheck((ChannelId >= DIO_ALL_CHANNEL), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01();
#endif
        DioIrqHwReg[PortId]->IBE &= ~(uint32)(0x1UL << Bit);
        DioIrqHwReg[PortId]->IEV &= ~(uint32)(0x1UL << Bit);
        DioIrqHwReg[PortId]->IS &= ~(uint32)(0x1UL << Bit);
        DioIrqHwReg[PortId]->IE &= ~(uint32)(0x1UL << Bit);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck((DioIrqHwReg[PortId]->IBE & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
        TT_ParaCheck((DioIrqHwReg[PortId]->IEV & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
        TT_ParaCheck((DioIrqHwReg[PortId]->IS  & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
        TT_ParaCheck((DioIrqHwReg[PortId]->IE  & (uint32)(0x1UL << Bit))>0, TT_RET_OPT_REG_ERR, &Ret);
#endif
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01();
#endif
    }

    return Ret;
}
#define DIO_STOP_SEC_CODE_SLOW
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE_FAST
#include "Dio_MemMap.h"
#ifndef USING_OS_AUTOSAROS
#if(GPIO0_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOA_IRQHandler)
{
    uint32 IrqNum = TT_GPIO0->RIS;
    TT_GPIO0->IC = IrqNum;

    if(Dio_GlobalPtr->Config->GPIO0Notification != NULL_PTR)
    {
        Dio_GlobalPtr->Config->GPIO0Notification(IrqNum);
    }
    else
    {
        /* do nothing */
    }
}
#endif

#if(GPIO1_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOB_IRQHandler)
{
    uint32 IrqNum = TT_GPIO1->RIS;
    TT_GPIO1->IC = IrqNum;

    if(Dio_GlobalPtr->Config->GPIO1Notification != NULL_PTR)
    {
        Dio_GlobalPtr->Config->GPIO1Notification(IrqNum);
    }
    else
    {
        /* do nothing */
    }
}
#endif

#if(GPIO2_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOC_IRQHandler)
{
    uint32 IrqNum = TT_GPIO2->RIS;
    TT_GPIO2->IC = IrqNum;

    if(Dio_GlobalPtr->Config->GPIO2Notification != NULL_PTR)
    {
        Dio_GlobalPtr->Config->GPIO2Notification(IrqNum);
    }
    else
    {
        /* do nothing */
    }
}
#endif

#if(GPIO3_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOD_IRQHandler)
{
    uint32 IrqNum = TT_GPIO3->RIS;
    TT_GPIO3->IC = IrqNum;

    if(Dio_GlobalPtr->Config->GPIO3Notification != NULL_PTR)
    {
        Dio_GlobalPtr->Config->GPIO3Notification(IrqNum);
    }
    else
    {
        /* do nothing */
    }
}
#endif

#if(GPIO4_INTERRUPT_ENABLE == STD_ON)
ISR(GPIOE_IRQHandler)
{
    uint32 IrqNum = TT_GPIO4->RIS;
    TT_GPIO4->IC = IrqNum;

    if(Dio_GlobalPtr->Config->GPIO4Notification != NULL_PTR)
    {
        Dio_GlobalPtr->Config->GPIO4Notification(IrqNum);
    }
    else
    {
        /* do nothing */
    }
}
#endif
#endif
#define DIO_STOP_SEC_CODE_FAST
#include "Dio_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif
