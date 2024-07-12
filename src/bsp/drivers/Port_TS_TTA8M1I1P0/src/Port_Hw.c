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
**  FILENAME     : Port_Hw.c                                                  **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Port Driver Source File                                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif


/******************************************************************************
*                            Includes                                          
******************************************************************************/
#include "Port_Hw.h"
#include "Mcu_Drv.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Port.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PORT_HW_VENDOR_ID_C                     1541
#define PORT_HW_MODULE_ID_C                     124
#define PORT_HW_AR_RELEASE_MAJOR_VERSION_C      4
#define PORT_HW_AR_RELEASE_MINOR_VERSION_C      4
#define PORT_HW_AR_RELEASE_PATCH_VERSION_C      0
#define PORT_HW_SW_MAJOR_VERSION_C              1
#define PORT_HW_SW_MINOR_VERSION_C              1
#define PORT_HW_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Port_Hw.c and Port_Hw.h file version check */
#if (PORT_HW_VENDOR_ID_C != PORT_HW_VENDOR_ID_H)
    #error "Port_Hw.c and Port_Hw.h have different vendor id"
#endif
#if (PORT_HW_MODULE_ID_C != PORT_HW_MODULE_ID_H)
    #error "Port_Hw.c and Port_Hw.h have different module id"
#endif
#if ((PORT_HW_AR_RELEASE_MAJOR_VERSION_C != PORT_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_HW_AR_RELEASE_MINOR_VERSION_C != PORT_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_HW_AR_RELEASE_PATCH_VERSION_C != PORT_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Hw.c and Port_Hw.h are different"
#endif
#if ((PORT_HW_SW_MAJOR_VERSION_C != PORT_HW_SW_MAJOR_VERSION_H) || \
     (PORT_HW_SW_MINOR_VERSION_C != PORT_HW_SW_MINOR_VERSION_H) || \
     (PORT_HW_SW_PATCH_VERSION_C != PORT_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Hw.c and Port_Hw.h are different"
#endif

/* Port_Hw.c and Mcu_Drv.h file version check */
#if (PORT_HW_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Port_Hw.c and Mcu_Drv.h have different vendor id"
#endif
#if ((PORT_HW_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_HW_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_HW_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Hw.c and Mcu_Drv.h are different"
#endif
#if ((PORT_HW_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (PORT_HW_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (PORT_HW_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Hw.c and Mcu_Drv.h are different"
#endif

#if defined(USE_DIO_MODULE) && (USE_DIO_MODULE == STD_ON)
/* Port_Hw.c and Dio_Hw.h file version check */
#if (PORT_HW_VENDOR_ID_C != DIO_HW_VENDOR_ID_H)
    #error "Port_Hw.c and Dio_Hw.h have different vendor id"
#endif
#if ((PORT_HW_AR_RELEASE_MAJOR_VERSION_C != DIO_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_HW_AR_RELEASE_MINOR_VERSION_C != DIO_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_HW_AR_RELEASE_PATCH_VERSION_C != DIO_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Hw.c and Dio_Hw.h are different"
#endif
#if ((PORT_HW_SW_MAJOR_VERSION_C != DIO_HW_SW_MAJOR_VERSION_H) || \
     (PORT_HW_SW_MINOR_VERSION_C != DIO_HW_SW_MINOR_VERSION_H) || \
     (PORT_HW_SW_PATCH_VERSION_C != DIO_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Hw.c and Dio_Hw.h are different"
#endif
#endif

/******************************************************************************
*                       Private Variables                                      
******************************************************************************/
#define PORT_START_SEC_VAR_INIT_PTR
#include "Port_MemMap.h"
/* Port Input and output function selection */
static TT_PAD_INFUNC_Type *Port_RegInput = TT_PAD_INFUNC;
static TT_PAD_OUTFUNC_Type *Port_RegOutput = TT_PAD_OUTFUNC;

#define PORT_STOP_SEC_VAR_INIT_PTR
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_PTR
#include "Port_MemMap.h"

#if (USE_DIO_MODULE == STD_ON)
/* Dio Register base address*/
static Dio_RegType * const DioHwReg[] = TT_GPIO_BASE_PTRS;
#endif

#define PORT_STOP_SEC_CONST_PTR
#include "Port_MemMap.h"

/******************************************************************************
*                         Private Functions Prototype
******************************************************************************/
#define PORT_START_SEC_CODE_FAST
#include "Port_MemMap.h"
/**
* @brief        Port_Hw_PriPinNotValidation
* @details      Checks whether the Pin Id is valid or not.
* @param[in]    Pin - Pin ID
*
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static boolean Port_Hw_PriPinNotValidation(Port_PinType Pin);
#define PORT_STOP_SEC_CODE_FAST
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
* @brief        Port_Hw_PriSetInPinCfg
* @details      Sets the PORT pin all configurations.
* @param[in]    Pin - Pin ID
*               TotalCfgPtr - Pin configuration
*               PinInitSelectIndex - Pin Select
*               Mode      - Pin Mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriSetInPinCfg(TT_CONST Port_PinTotalCfgType *TotalCfgPtr, uint32 PinInitSelectIndex,
                                      Port_PinModeType Mode);
/**
* @brief        Port_Hw_PriSetOutPinCfg
* @details      Sets the PORT pin all configurations.
* @param[in]    Pin - Pin ID
*               TotalCfgPtr - Pin configuration
*               PinInitSelectIndex - Pin Select
*               Mode      - Pin Mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriSetOutPinCfg(TT_CONST Port_PinTotalCfgType *TotalCfgPtr, uint32 PinInitSelectIndex,
                                       Port_PinModeType Mode);
/**
* @brief        Port_Hw_PriSetInOutPinCfg
* @details      Sets the PORT pin all configurations.
* @param[in]    Pin - Pin ID
*               TotalCfgPtr - Pin configuration
*               PinInitSelectIndex - Pin Select
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriSetInOutPinCfg(TT_CONST Port_PinTotalCfgType *TotalCfgPtr, uint32 PinInitSelectIndex);
/**
* @brief        Port_Hw_PriSetPinCfg
* @details      Set the PORT pin all configurations.
* @param[in]    NumberOfContainers - Pin ID Number
*               ConfigPtr - Pin configuration
*               Direction - Pin Direction
*               Mode      - Pin Mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriSetPinCfg(TT_CONST Port_ConfigType *ConfigPtr, uint32 NumberOfContainers, uint32 NumberOfPortPins,
                                    Port_PinDirectionType Direction, Port_PinModeType Mode);
/**
* @brief        Port_Hw_PriRegReadBack
* @details      Sets the PORT pin all configurations.
* @param[in]    ActualValue - Register the actual value
*               TargetValue - correct value of the register
* @param[out]   Ret - TT_RetType
* @return       void
* @pre
*/
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
LOCAL_INLINE void Port_Hw_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret);
#endif
#if defined(USE_DIO_MODULE) && (USE_DIO_MODULE == STD_ON)
/**
* @brief        Port_Hw_PirDioInDir
* @details      control Dio Dir status
*
* @param[in]    PortId - ID of DIO Port
*               Bit    - Dio Dir register bit
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PirDioInDir(Dio_PortType PortId,Dio_PortLevelType Bit);
/**
* @brief        Port_Hw_PriDioOutDir
* @details      control Dio Dir status
* @param[in]    PortId - ID of DIO Port
*               Bit    - Dio Dir register bit
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriDioOutDir(Dio_PortType PortId,Dio_PortLevelType Bit);
/**
* @brief        Port_Hw_PriDiolclClkControl
* @details      Mcu control module clk status
* @param[in]    PortId - ID of DIO Port
* @return
* @retval
* @pre
*/
static TT_RetType Port_Hw_PriDiolclClkControl(Dio_PortType PortId);
#endif
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
/******************************************************************************
*                         Public Functions                                     
******************************************************************************/
#define PORT_START_SEC_CODE_SLOW
#include "Port_MemMap.h"
/**
* @brief        Port_Hw_Init
* @details      Initializes the Port Driver module.
* @param[in]    ConfigPtr - Pointer to configuration set
* @return
* @retval
* @pre
*/
TT_RetType Port_Hw_Init(TT_CONST Port_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    uint32 i = 0U;
    uint32 j = 0U;
    Port_PinDirectionType PinDir = PORT_PIN_IN;
    Port_PinModeType Mode = 0U;

    TT_CONST Port_ContainerType *ContainerPtr = NULL_PTR;

    TT_ParaCheck((ConfigPtr == NULL_PTR) || (ConfigPtr->Containers == NULL_PTR) ||\
                 (ConfigPtr->Containers->PinTotalCfg == NULL_PTR) || \
                 (ConfigPtr->Containers->PinTotalCfg->PinDetailCfg == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        /* Init Every container */
        for (j = 0; j < ConfigPtr->Port_NumberOfContainers; j++)
        {
            /* get dest container */
            ContainerPtr = &(ConfigPtr->Containers[j]);
            for (i = 0; i < ContainerPtr->Port_NumberOfPortPins; i++)
            {
                PinDir = ConfigPtr->Containers[j].PinTotalCfg[i].PinDetailCfg->PinDirection;
                if(PinDir == PORT_PIN_IN)
                {
                    Mode = (uint32)ConfigPtr->Containers[j].PinTotalCfg[i].PinDetailCfg->PinModeInputFunction;
                }
                else
                {
                    Mode = (uint32)ConfigPtr->Containers[j].PinTotalCfg[i].PinDetailCfg->PinModeOutputFunction;
                }
                Ret = Port_Hw_PriSetPinCfg(ConfigPtr, j, i, PinDir, Mode);
            }
        }
    }
    else
    {
        /* do nothing */
    }
    
    return Ret;
}
#define PORT_STOP_SEC_CODE_SLOW
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
* @brief        Port_SetPinDirection
* @details      Sets the port pin direction.
* @param[in]    Pin - Pin ID
*               Direction - Pin Direction
*               ConfigPtr - Pointer to configuration set
* @return
* @retval
* @pre
*/
TT_RetType Port_Hw_SetPinDirection(TT_CONST Port_PinType Pin, TT_CONST Port_PinDirectionType Direction, TT_CONST Port_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    uint32 i = 0U;
    uint32 j = 0U;
    uint32 Port_Containers = 0U;
    uint32 Port_PortPins = 0U;
    uint32 PinInitSelectIndex = 0U;
    Port_PinDirectionType PinDir = PORT_PIN_IN;
    Port_PinModeType Mode = 0U;

    TT_ParaCheck(((ConfigPtr == NULL_PTR) || ((ConfigPtr->Containers->PinTotalCfg)== NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Pin > PORT_PIN_NUM_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((Direction > PORT_PIN_IN_OUT), TT_RET_PARAM_ENUM_ERR, &Ret);
   if (TT_RET_SUCCESS == Ret)
    {
        PinInitSelectIndex = ConfigPtr->Containers->PinTotalCfg->PinInitialSelectNumber;

        for (j = 0; j < ConfigPtr->Port_NumberOfContainers; j++)
        {
            for (i = 0; i < ConfigPtr->Containers[j].Port_NumberOfPortPins; i++)
            {
                if(Pin == ConfigPtr->Containers[j].PinTotalCfg[i].PinID)
                {
                    Port_Containers = j;
                    Port_PortPins = i;
                    break;
                }
                else
                {
                     /* do nothing */
                }
            }
        }

        PinDir = ConfigPtr->Containers[Port_Containers].PinTotalCfg[Port_PortPins].PinDetailCfg[PinInitSelectIndex].PinDirection;

        if(PinDir != Direction)
        {
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();
#endif
            if(Direction == PORT_PIN_IN)
            {
                Mode = (uint32)ConfigPtr->Containers[Port_Containers].PinTotalCfg[Port_PortPins].PinDetailCfg->PinModeInputFunction;
                Ret = Port_Hw_PriSetPinCfg(ConfigPtr, Port_Containers, Port_PortPins, Direction, Mode);
                Port_RegInput->Pad_InFunc[PAD_GET_REG_INDEX(Pin)] |= (uint32)TT_SCU_PAD_INFUN_PAD0_INPUT_EN_Msk << (uint32)PAD_GET_REG_INNER_OFFSET(Pin);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                Port_Hw_PriRegReadBack((Port_RegInput->Pad_InFunc[PAD_GET_REG_INDEX(Pin)] & (TT_SCU_PAD_INFUN_PAD0_INPUT_EN_Msk << (uint32)PAD_GET_REG_INNER_OFFSET(Pin))) , \
                                       (TT_SCU_PAD_INFUN_PAD0_INPUT_EN_Msk << (uint32)PAD_GET_REG_INNER_OFFSET(Pin)),
                                        &Ret);
#endif
            }
            else
            {
                Mode = (uint32)ConfigPtr->Containers[Port_Containers].PinTotalCfg[Port_PortPins].PinDetailCfg->PinModeOutputFunction;
                Ret = Port_Hw_PriSetPinCfg(ConfigPtr, Port_Containers, Port_PortPins, Direction, Mode);
                Port_RegOutput->Pad_OutFunc[PAD_GET_REG_INDEX(Pin)] |= (uint32)TT_SCU_PAD_FUNC_PAD0_OUTPUT_Msk << (uint32)PAD_GET_REG_INNER_OFFSET(Pin);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                Port_Hw_PriRegReadBack((Port_RegOutput->Pad_OutFunc[PAD_GET_REG_INDEX(Pin)] & (TT_SCU_PAD_FUNC_PAD0_OUTPUT_Msk << (uint32)PAD_GET_REG_INNER_OFFSET(Pin))), \
                                       TT_SCU_PAD_FUNC_PAD0_OUTPUT_Msk << (uint32)PAD_GET_REG_INNER_OFFSET(Pin),
                                        &Ret);
#endif
            }


#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
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
    
    return Ret;
}

/**
* @brief        Port_Hw_SetPinMode
* @details      Sets the PORT pin mode.
* @param[in]    Pin - Pin ID
*               Mode - Pin Mode
*               ConfigPtr - Pointer to configuration set
* @return       TT_RetType - Sets the PORT pin mode successfully
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
*/
TT_RetType Port_Hw_SetPinMode(TT_CONST Port_PinType Pin, TT_CONST Port_PinModeType Mode,  TT_CONST Port_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 i = 0U;
    uint32 j = 0U;
    uint32 Port_Containers = 0U;
    uint32 Port_PortPins = 0U;
    Port_PinDirectionType PinDir = PORT_PIN_IN;

    TT_ParaCheck(((ConfigPtr == NULL_PTR) || ((ConfigPtr->Containers->PinTotalCfg)== NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((Pin > PORT_PIN_NUM_MAX), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((Mode > (uint32)PORT_PIN_MODE_INPUT_FUNC15), TT_RET_PARAM_ENUM_ERR, &Ret);
   if (TT_RET_SUCCESS == Ret)
    {
        for (j = 0; j < ConfigPtr->Port_NumberOfContainers; j++)
        {
            for (i = 0; i < ConfigPtr->Containers[j].Port_NumberOfPortPins; i++)
            {
                if(Pin == ConfigPtr->Containers[j].PinTotalCfg[i].PinID)
                {
                    Port_Containers = j;
                    Port_PortPins = i;
                }
                else
                {
                     /* do nothing */
                }
            }
        }

        PinDir = ConfigPtr->Containers[Port_Containers].PinTotalCfg[Port_PortPins].PinDetailCfg->PinDirection;
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
#endif
     Ret = Port_Hw_PriSetPinCfg(ConfigPtr, Port_Containers, Port_PortPins, PinDir, Mode);

#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    Port_Hw_PriRegReadBack((Port_RegInput->Pad_InFunc[PAD_GET_REG_INDEX(Pin)] & (Mode << (uint32)PAD_GET_REG_INNER_OFFSET(Pin))) , \
            (Mode << (uint32)PAD_GET_REG_INNER_OFFSET(Pin)),&Ret);
    Port_Hw_PriRegReadBack((Port_RegOutput->Pad_OutFunc[PAD_GET_REG_INDEX(Pin)] & (Mode << (uint32)PAD_GET_REG_INNER_OFFSET(Pin))), \
                           (Mode << (uint32)PAD_GET_REG_INNER_OFFSET(Pin)),&Ret);
#endif
    }
    else
    {
        /* do nothing */
    }
    
    return Ret;
}

/**
* @brief        Port_Hw_SetPinAllCfg
* @details      Sets the PORT pin all configurations.
* @param[in]    Pin - Pin ID
*               PinAllCfg - Pin configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
TT_RetType Port_Hw_SetPinAllCfg(TT_CONST Port_PinType Pin, TT_CONST Port_PinAllCfgType *PinAllCfg)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 TmpIn = 0U;
    uint32 TmpOut = 0U;
    TT_CONST Port_PinAllCfgType  *TT_CONST PinAllCfgRtr = PinAllCfg;

#if (USE_DIO_MODULE == STD_ON)
    Port_PinModeInputFunctionType InputFunction = PORT_PIN_MODE_INPUT_FUNC00;
    Port_PinModeOutputFunctionType OutputFunction = PORT_PIN_MODE_OUTPUT_FUNC00;
    uint32 PinID = 0u;
    Dio_PortType PortId = 0u;
    Dio_PortLevelType Bit = 0u;
#endif

    TT_ParaCheck((Port_Hw_PriPinNotValidation(Pin) == TRUE), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((PinAllCfg == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
   if (TT_RET_SUCCESS == Ret)
    {

       TmpIn = PORT_GET_INFUNCTION_CFG(PinAllCfgRtr->PinInputMode, \
                       PinAllCfgRtr->PinInputPullDownEnable, \
                       PinAllCfgRtr->PinInputConfigLock, \
                       PinAllCfgRtr->PinInputPullUpEnable, \
                       PinAllCfgRtr->PinInputEnable);

       TmpOut = PORT_GET_OUTFUNCTION_CFG(PinAllCfgRtr->PinOutputMode, \
                         PinAllCfgRtr->PinOutputEnable, \
                         PinAllCfgRtr->PinOutputFuncLock, \
                         PinAllCfgRtr->PinOutputModeValue, \
                         PinAllCfgRtr->DriverLevel);
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02();
#endif
         Port_RegInput->Pad_InFunc[PAD_GET_REG_INDEX(Pin)] &= ~(uint32)(0xffUL << (uint32)PAD_GET_REG_INNER_OFFSET(Pin));
         Port_RegInput->Pad_InFunc[PAD_GET_REG_INDEX(Pin)] |= TmpIn << (uint32)PAD_GET_REG_INNER_OFFSET(Pin);
         Port_RegOutput->Pad_OutFunc[PAD_GET_REG_INDEX(Pin)] &= ~(uint32)(0xffUL << (uint32)PAD_GET_REG_INNER_OFFSET(Pin));
         Port_RegOutput->Pad_OutFunc[PAD_GET_REG_INDEX(Pin)] |= TmpOut << (uint32)PAD_GET_REG_INNER_OFFSET(Pin);
#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02();
#endif
#if (USE_DIO_MODULE == STD_ON)
       if (PinAllCfgRtr->Direction == PORT_PIN_IN)
       {
           InputFunction = PinAllCfgRtr->PinInputMode;
           PinID = Pin;
           if(DIO_INFUNCTION_SELECT(PinID, InputFunction))
           {
               PortId = DIO_GET_PORT_FROM_PIN_ID(Pin);
               Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_PIN_ID(Pin);
               Ret = Port_Hw_PirDioInDir(PortId,Bit);
               if(PinAllCfgRtr->PinInputInterruptUsed == TRUE && TT_RET_SUCCESS == Ret)
               {
                   Ret = Dio_Hw_Interrupt_Init(Pin, PinAllCfgRtr->PinExitTrigger);
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
       else if(PinAllCfgRtr->Direction == PORT_PIN_OUT)
       {
           OutputFunction = PinAllCfgRtr->PinOutputMode;
           PinID = Pin;
           if(DIO_OUTFUNCTION_SELECT(PinID, OutputFunction))
           {
               PortId   = DIO_GET_PORT_FROM_PIN_ID(Pin);
               Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_PIN_ID(Pin);
               Ret = Port_Hw_PriDioOutDir(PortId,Bit);
           }
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

    return Ret;
}

#if defined(USE_DIO_MODULE) && (USE_DIO_MODULE == STD_ON)
/**
* @brief        Port_Hw_PirDioInDir
* @details      control Dio Dir status
*
* @param[in]    PortId - ID of DIO Port
*               Bit    - Dio Dir register bit
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PirDioInDir(Dio_PortType PortId,Dio_PortLevelType Bit)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Port_Hw_PriDiolclClkControl(PortId);
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_03();
#endif
               DioHwReg[PortId]->DIR &= ~(uint32)(0x1UL << Bit);
#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_03();
#endif
    return Ret;
}
/**
* @brief        Port_Hw_PriDioOutDir
* @details      control Dio Dir status
* @param[in]    PortId - ID of DIO Port
*               Bit    - Dio Dir register bit
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriDioOutDir(Dio_PortType PortId,Dio_PortLevelType Bit)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Port_Hw_PriDiolclClkControl(PortId);
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_03();
#endif
    DioHwReg[PortId]->DIR |= (uint32)(0x1UL << Bit);
#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_03();
#endif
    return Ret;
}

/**
* @brief        Port_Hw_PriDiolclClkControl
* @details      Mcu control module clk status
* @param[in]    PortId - ID of DIO Port
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriDiolclClkControl(Dio_PortType PortId)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    switch (PortId)
    {
    case 0:
        Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_GPIO0);
        break;
    case 1:
        Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_GPIO1);
        break;
    case 2:
        Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_GPIO2);
        break;
    case 3:
        Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_GPIO3);
        break;
    case 4:
        Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_GPIO4);
        break;
    default:
        Ret = TT_RET_STATUS_ERR;
        break;
    }
    return Ret;
}
#endif

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE_FAST
#include "Port_MemMap.h"
/**
* @brief        Port_Hw_PriPinNotValidation
* @details      Checks whether the Pin Id is valid or not.
* @param[in]    Pin     Pin ID
* @return       boolean
* @retval       TRUE    Success
*               FALSE   Pin Id is invalid
* @pre
*/
static boolean Port_Hw_PriPinNotValidation(Port_PinType Pin)
{
    uint8 i = 0U;
    uint8 j = 0U;
    boolean RetVal = TRUE;

    for (j = 0; j < Port_ConfigData.Port_NumberOfContainers; j++)
    {
        for (i = 0; i < Port_ConfigData.Containers[j].Port_NumberOfPortPins; i++)
        {
            if(Pin == Port_ConfigData.Containers[j].PinTotalCfg[i].PinID)
            {
                RetVal = FALSE;
                break;
            }
            else
            {
                 /* do nothing */
            }
        }
    }
    return RetVal;
}
#define PORT_STOP_SEC_CODE_FAST
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/**
* @brief        Port_Hw_PriSetInPinCfg
* @details      Sets the PORT pin all configurations.
* @param[in]    Pin - Pin ID
*               ConfigPtr - Pin configuration
*               Direction - Pin Direction
*               Mode      - Pin Mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriSetInPinCfg(TT_CONST Port_PinTotalCfgType *TotalCfgPtr, uint32 PinInitSelectIndex,
                                      Port_PinModeType Mode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Tmp = 0U;
#if (USE_DIO_MODULE == STD_ON)
    Port_PinModeType InputFunction = 0U;
    uint32 PinID = 0U;
    Dio_PortType PortId = 0U;
    Dio_PortLevelType Bit = 0U;
#endif
    TT_ParaCheck((TotalCfgPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        Tmp |= PORT_GET_INFUNCTION_CFG(Mode, \
                        TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputConfigLock, \
                        TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputPullDownEnable, \
                        TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputPullUpEnable, \
                        TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputEnable);
        Port_RegInput->Pad_InFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)] |= Tmp << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID);

#if (USE_DIO_MODULE == STD_ON)
        InputFunction = Mode;
        PinID = TotalCfgPtr->PinID;
        if(DIO_INFUNCTION_SELECT(PinID, InputFunction))
        {
            PortId = DIO_GET_PORT_FROM_PIN_ID(TotalCfgPtr->PinID);
            Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_PIN_ID(TotalCfgPtr->PinID);
            (void)Port_Hw_PriDiolclClkControl(PortId);
            DioHwReg[PortId]->DIR &= ~(uint32)(0x1UL << Bit);
            if(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputInterruptUsed == TRUE)
            {
                Ret = Dio_Hw_Interrupt_Init(TotalCfgPtr->PinID, TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinExitTrigger);
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
#endif
    }
    return Ret;
}

/**
* @brief        Port_Hw_PriSetOutPinCfg
* @details      Sets the PORT pin all configurations.
* @param[in]    Pin - Pin ID
*               ConfigPtr - Pin configuration
*               PinInitSelectIndex - Pin Select
*               Mode      - Pin Mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriSetOutPinCfg(TT_CONST Port_PinTotalCfgType *TotalCfgPtr, uint32 PinInitSelectIndex,
                                       Port_PinModeType Mode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Tmp = 0U;
#if (USE_DIO_MODULE == STD_ON)
    Port_PinModeType OutputFunction = 0U;
    uint32 PinID = 0U;
    Dio_PortType PortId = 0U;
    Dio_PortLevelType Bit = 0U;
#endif
#if (USE_GTM_MODULE == STD_ON)
    uint8 GtmFuncTmp = 0U;
    uint16 GtmPadTmp = 0U;
#endif
    TT_ParaCheck((TotalCfgPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        Tmp |= PORT_GET_OUTFUNCTION_CFG(Mode, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputFuncLock, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputModeValue, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDriverLevel, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputEnable);
                    Port_RegOutput->Pad_OutFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)] |= Tmp << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID);
#if (USE_DIO_MODULE == STD_ON)

                    OutputFunction = Mode;
                    PinID = TotalCfgPtr->PinID;
                    if(DIO_OUTFUNCTION_SELECT(PinID, OutputFunction))
                    {
                        PortId = DIO_GET_PORT_FROM_PIN_ID(TotalCfgPtr->PinID);
                        Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_PIN_ID(TotalCfgPtr->PinID);
                        (void)Port_Hw_PriDiolclClkControl(PortId);
                        DioHwReg[PortId]->DIR |= (uint32)(0x1UL << Bit);
                    }
                    else
                    {
                         /* do nothing */
                    }
#endif

#if (USE_GTM_MODULE == STD_ON)
                    /* config GTM pad func select */
                    if (TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeGtmOut)
                    {
                        (void)Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_GTM);
                        GtmPadTmp = TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinGtmOutSelect >> 3;
                        GtmFuncTmp = (uint8)(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinGtmOutSelect - (GtmPadTmp << 3));

                        /* clear first */
                        GTM_WRAPPER->TOUTSEL[GtmPadTmp].R &= ~((uint32)0xF << (GtmFuncTmp << 2));

                        /* config dest */
                        GTM_WRAPPER->TOUTSEL[GtmPadTmp].R |= (uint32)TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinGtmOutSelectFunc << (GtmFuncTmp << 2);
                        (void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_GTM);
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
* @brief        Port_Hw_PriSetInOutPinCfg
* @details      Sets the PORT pin all configurations.
* @param[in]    Pin - Pin ID
*               ConfigPtr - Pin configuration
*               Direction - Pin Direction
*               Mode      - Pin Mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriSetInOutPinCfg(TT_CONST Port_PinTotalCfgType *TotalCfgPtr, uint32 PinInitSelectIndex)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Tmp = 0U;
#if (USE_GTM_MODULE == STD_ON)
    uint8 GtmFuncTmp = 0U;
    uint16 GtmPadTmp = 0U;
#endif
    TT_ParaCheck((TotalCfgPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        Tmp |= PORT_GET_INFUNCTION_CFG(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeInputFunction, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputConfigLock, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputPullDownEnable, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputPullUpEnable, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputEnable);

                    Port_RegInput->Pad_InFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)] |= Tmp << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID);

                    Tmp = 0;
                    Tmp |= PORT_GET_OUTFUNCTION_CFG(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeOutputFunction, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputFuncLock, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputModeValue, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDriverLevel, \
                                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputEnable);

                    Port_RegOutput->Pad_OutFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)] |= Tmp << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID);

        #if (USE_GTM_MODULE == STD_ON)
                   /* config GTM pad func select */
                    if (TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeGtmOut)
                    {
                        (void)Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_GTM);
                        GtmPadTmp = TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinGtmOutSelect >> 3;
                        GtmFuncTmp = (uint8)(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinGtmOutSelect - (GtmPadTmp << 3));

                        /* clear first */
                        GTM_WRAPPER->TOUTSEL[GtmPadTmp].R &= ~((uint32)0xF << (GtmFuncTmp << 2));

                        /* config dest */
                        GTM_WRAPPER->TOUTSEL[GtmPadTmp].R |= (uint32)TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinGtmOutSelectFunc << (GtmFuncTmp << 2);
                        (void)Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_GTM);
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
* @brief        Port_Hw_SetPinAllCfg
* @details      Sets the PORT pin all configurations.
* @param[in]    Pin - Pin ID
*               ConfigPtr - Pin configuration
*               Direction - Pin Direction
*               Mode      - Pin Mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - Success
* @retval       Other - Error types
* @pre
*/
static TT_RetType Port_Hw_PriSetPinCfg(TT_CONST Port_ConfigType *ConfigPtr, uint32 NumberOfContainers, uint32 NumberOfPortPins,
                                    Port_PinDirectionType Direction, Port_PinModeType Mode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 PinInitSelectIndex = 0U;
    TT_CONST Port_PinTotalCfgType *TotalCfgPtr = NULL_PTR;

#if (USE_DIO_MODULE == STD_ON)
    if(ConfigPtr->Containers[NumberOfContainers].PinTotalCfg[NumberOfPortPins].PinDetailCfg[PinInitSelectIndex].PinInputInterruptUsed == TRUE)
    {
    TT_ParaCheck((ConfigPtr->Containers->PinTotalCfg->PinDetailCfg->PinExitTrigger > DIO_TRIGGER_LOW), TT_RET_PARAM_ERR, &Ret);
    }
#endif

    TT_ParaCheck((ConfigPtr->Containers->PinTotalCfg->PinDetailCfg->PinDirection > PORT_PIN_IN_OUT), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((ConfigPtr->Containers->PinTotalCfg->PinDetailCfg->PinOutputModeValue > PORT_PIN_OUTPUT_MODE_OD), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((ConfigPtr->Containers->PinTotalCfg->PinDetailCfg->PinDriverLevel > PORT_PIN_DRIVER_LEVEL_1), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((ConfigPtr->Containers->PinTotalCfg->PinDetailCfg->PinModeInputFunction > PORT_PIN_MODE_INPUT_FUNC15), TT_RET_PARAM_ERR, &Ret);
    TT_ParaCheck((ConfigPtr->Containers->PinTotalCfg->PinDetailCfg->PinModeOutputFunction > PORT_PIN_MODE_OUTPUT_FUNC07), TT_RET_PARAM_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {

        TotalCfgPtr =  &(ConfigPtr->Containers[NumberOfContainers].PinTotalCfg[NumberOfPortPins]);
        PinInitSelectIndex = TotalCfgPtr->PinInitialSelectNumber;
        Port_RegOutput->Pad_OutFunc[PAD_GET_REG_INDEX((TotalCfgPtr->PinID))] &= ~(uint32)(0xffUL << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID));
        Port_RegInput->Pad_InFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)] &= ~(uint32)(0xffUL << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID));
        /* config pad Input */
        if (Direction == PORT_PIN_IN)
        {
            Ret = Port_Hw_PriSetInPinCfg(TotalCfgPtr,PinInitSelectIndex,Mode);
        }
        /* config pad Output */
        else if (Direction == PORT_PIN_OUT)
        {
            Ret = Port_Hw_PriSetOutPinCfg(TotalCfgPtr,PinInitSelectIndex,Mode);
        }
        // config pad in and Output
        else if (Direction == PORT_PIN_IN_OUT)
        {
            Ret = Port_Hw_PriSetInOutPinCfg(TotalCfgPtr,PinInitSelectIndex);
        }
        else
        {
             /* do nothing */
        }
    }
    else
    {

    }
    return Ret;
}
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Port_Hw_PriRegReadBack
* @details      Sets the PORT pin all configurations.
* @param[in]    ActualValue - Register the actual value
*               TargetValue - correct value of the register
* @param[out]   Ret - TT_RetType
* @return       void
* @pre
*/
LOCAL_INLINE void Port_Hw_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret)
{
    if(TT_RET_SUCCESS != *Ret)
    {
        if(ActualValue != TargetValue)
        {
            *Ret = TT_RET_OPT_REG_ERR;
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
#endif
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"



#ifdef __cplusplus
}
#endif


