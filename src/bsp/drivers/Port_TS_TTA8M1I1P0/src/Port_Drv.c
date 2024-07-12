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
**  FILENAME     : Port_Drv.c                                                 **
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
#include "Port_Drv.h"
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#include "Base_Tools.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PORT_DRV_VENDOR_ID_C                     1541
#define PORT_DRV_MODULE_ID_C                     124
#define PORT_DRV_AR_RELEASE_MAJOR_VERSION_C      4
#define PORT_DRV_AR_RELEASE_MINOR_VERSION_C      4
#define PORT_DRV_AR_RELEASE_PATCH_VERSION_C      0
#define PORT_DRV_SW_MAJOR_VERSION_C              1
#define PORT_DRV_SW_MINOR_VERSION_C              1
#define PORT_DRV_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Port_Drv.c and Port_Drv.h file version check */
#if (PORT_DRV_VENDOR_ID_C != PORT_DRV_VENDOR_ID_H)
    #error "Port_Drv.c and Port_Drv.h have different vendor id"
#endif
#if (PORT_DRV_MODULE_ID_C != PORT_DRV_MODULE_ID_H)
    #error "Port_Drv.c and Port_Drv.h have different module id"
#endif
#if ((PORT_DRV_AR_RELEASE_MAJOR_VERSION_C != PORT_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_DRV_AR_RELEASE_MINOR_VERSION_C != PORT_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_DRV_AR_RELEASE_PATCH_VERSION_C != PORT_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Port_Drv.c and Port_Drv.h are different"
#endif
#if ((PORT_DRV_SW_MAJOR_VERSION_C != PORT_DRV_SW_MAJOR_VERSION_H) || \
     (PORT_DRV_SW_MINOR_VERSION_C != PORT_DRV_SW_MINOR_VERSION_H) || \
     (PORT_DRV_SW_PATCH_VERSION_C != PORT_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Port_Drv.c and Port_Drv.h are different"
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    /* Port_Drv.c and Base_Tools.h file version check */
    #if (PORT_DRV_VENDOR_ID_C != BASE_TOOLS_VENDOR_ID_H)
        #error "Port_Drv.c and Base_Tools.h have different vendor id"
    #endif
    #if ((PORT_DRV_AR_RELEASE_MAJOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H) || \
         (PORT_DRV_AR_RELEASE_MINOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H) || \
         (PORT_DRV_AR_RELEASE_PATCH_VERSION_C != BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H))
        #error "AutoSar Version Numbers of Port_Drv.c and Base_Tools.h are different"
    #endif
    #if ((PORT_DRV_SW_MAJOR_VERSION_C != BASE_TOOLS_SW_MAJOR_VERSION_H) || \
         (PORT_DRV_SW_MINOR_VERSION_C != BASE_TOOLS_SW_MINOR_VERSION_H) || \
         (PORT_DRV_SW_PATCH_VERSION_C != BASE_TOOLS_SW_PATCH_VERSION_H))
        #error "Software Version Numbers of Port_Drv.c and Base_Tools.h are different"
    #endif
#endif
/******************************************************************************
*                       Private Variable Definitions
******************************************************************************/
#define PORT_START_SEC_VAR_CLEARED_PTR
#include "Port_MemMap.h"
/* Port Configuring the data array  */
static TT_CONST Port_ConfigType * Port_Config[PORTMUXNUM];
#define PORT_STOP_SEC_VAR_CLEARED_PTR
#include "Port_MemMap.h"  


#define PORT_START_SEC_CONST_PTR
#include "Port_MemMap.h"

#if (TT_SAFETY == STD_ON) && (USE_DIO_MODULE == STD_ON)
/* Dio Register base address */
static Dio_RegType * const DioReg[] = TT_GPIO_BASE_PTRS;
#endif

#define PORT_STOP_SEC_CONST_PTR
#include "Port_MemMap.h"

#define PORT_START_SEC_VAR_CLEARED_BOOLEAN
#include "Port_MemMap.h"
/* Port Drv init */
static boolean Port_Drv_PubInitialized = FALSE;
#define PORT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Port_MemMap.h"   
/******************************************************************************
*                    Private Function Declaration
******************************************************************************/

#define PORT_START_SEC_CODE_SLOW
#include "Port_MemMap.h" 
#if (TT_SAFETY == STD_ON)
/**
* @brief        Mtl_Port_PriLogicCheck
* @details      Check Port Config
* @param[in]    ConfigPtr : Const Ptr to Port Module
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Port_PriLogicCheck(TT_CONST Port_ConfigType *ConfigPtr);
/**
* @brief        Mtl_Port_InitCheck
* @details      InitCheck For Port After PortInit
* @param[in]    no
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Port_Drv_InitCheck(TT_CONST void *ConfigPtr);
#if (USE_DIO_MODULE == STD_ON)
/**
* @brief        Mtl_Dio_InitCheck
* @details      InitCheck For Dio After DioInit
* @param[in]    no
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Dio_Drv_InitCheck(TT_CONST void *ConfigPtr);

/**
* @brief        Mtl_Dio_PriLogicCheck
* @details      Check Dio Config
* @param[in]    ConfigPtr : Const Ptr to Dio Module
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Dio_PriLogicCheck(TT_CONST Port_ConfigType *ConfigPtr);
#endif
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifndef USING_OS_AUTOSAROS
static uint32 Port_Drv_PriCalcCustomCfgCrc(void);
#if (USE_DIO_MODULE == STD_ON)
/**
* @brief         Dio_Drv_PriCalcCfgCrc.
* @details       Calculates the crc value of the configuration parameter.
* @param[in]
* @param[out]    u32AccCRCremainder - crc value
* @return        uint32
* @retval
* @pre
*/
static uint32 Dio_Drv_PriCalcCfgCrc(void);
#endif
#endif
#endif

/**
* @brief                Port_Drv_PriParaCheck
* @details              Reports Det error if PORT_DEV_ERROR_DETECT == STD_ON
* @param[in]            Expr - boolean expression to check API conditions
* @param[in]            ApiId - ServiceApiId -Service Id of API
* @param[in]            ErrId - Error Id of Conditionl
* @param[out]           RetVal - variable to check return type
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Port_Drv_PriParaCheck(boolean Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal);

/**
* @brief            Port_Drv_PriRetCheck
* @details          Reports Det error if PORT_DEV_ERROR_DETECT == STD_ON
* @param[in]        ApiId - ServiceApiId -Service Id of API
* @param[out]       ErrId - Error Id of Conditionl
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Port_Drv_PriRetCheck(uint8 ApiId, TT_RetType *ErrId);

/******************************************************************************
*                         Public Functions                                     
******************************************************************************/

/******************************************************************************
*  Service name     : Port_Drv_Init
*  Syntax           : TT_RetType Port_Drv_Init(TT_CONST Port_ConfigType *ConfigPtr)
*  Service ID       : 100
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : ConfigPtr - Pointer to configuration set
*  Parameters (out) : None
*  Return value     : None
*  Description      : Initializes the Port Driver module.
******************************************************************************/
TT_RetType Port_Drv_Init(TT_CONST Port_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Port_Drv_PriParaCheck((boolean)(ConfigPtr == NULL_PTR), PORT_DRV_SI_INIT, TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    Port_Drv_PriParaCheck((boolean)(Port_Drv_PubInitialized == TRUE),
                            PORT_DRV_SI_INIT,
                            TT_RET_STATUS_UNINIT_ERR, &Ret);
    Port_Config[PORTNUM] = ConfigPtr;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifndef USING_OS_AUTOSAROS
    if(TT_RET_SUCCESS == Ret)
    {
        Port_Drv_PriParaCheck((boolean)(Port_Drv_PriCalcCustomCfgCrc() != Port_Config[PORTNUM]->Crc),
                              PORT_DRV_SI_INIT, TT_RET_PARAM_CONFIG_ERR, &Ret);
    }
#if (USE_DIO_MODULE == STD_ON)
    Port_Drv_PriParaCheck((boolean)(Dio_Drv_PriCalcCfgCrc() != Dio_GlobalData.DioCrc),
                          PORT_DRV_SI_INIT, TT_RET_PARAM_CONFIG_ERR, &Ret);
#endif
#endif
#endif
    if (TT_RET_SUCCESS == Ret)
    {
        /*  Save configuration pointer in global variable */

        Ret = Port_Hw_Init(ConfigPtr);
        Port_Drv_PriRetCheck(PORT_DRV_SI_INIT, &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
            Port_Drv_PubInitialized = TRUE;
        }
    }
    else
    {
         /* do nothing */
    }
#if (TT_SAFETY == STD_ON)
        if (TT_RET_SUCCESS == Ret)
        {
            Ret = Port_Drv_InitCheck(ConfigPtr);
            Port_Drv_PriRetCheck(PORT_DRV_SI_INIT, &Ret);
        }
#if (USE_DIO_MODULE == STD_ON)
        if (TT_RET_SUCCESS == Ret)
        {
            Ret = Dio_Drv_InitCheck(ConfigPtr);
            Port_Drv_PriRetCheck(PORT_DRV_SI_INIT, &Ret);
        }
#endif
#endif


    return Ret;
}

#define PORT_STOP_SEC_CODE_SLOW
#include "Port_MemMap.h" 

#define PORT_START_SEC_CODE
#include "Port_MemMap.h" 
/******************************************************************************
*  Service name     : Port_Hw_SetPinDirection
*  Syntax           : TT_RetType Port_Drv_SetPinDirection(
*                       TT_CONST Port_PinType Pin,
*                       TT_CONST Port_PinDirectionType Direction)
*  Service ID       : 101
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Pin - Pin ID
*                     Direction - Pin Direction
*  Parameters (out) : None
*  Return value     : None
*  Description      : Sets the port pin direction.
******************************************************************************/
TT_RetType Port_Drv_SetPinDirection(TT_CONST Port_PinType Pin, TT_CONST Port_PinDirectionType Direction)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Port_Drv_PriParaCheck((boolean)(Port_Drv_PubInitialized == FALSE),
                            PORT_DRV_SI_SETPINDIRECTION,
                            TT_RET_STATUS_UNINIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Port_Hw_SetPinDirection(Pin, Direction, Port_Config[PORTNUM]);
        Port_Drv_PriRetCheck(PORT_DRV_SI_SETPINDIRECTION, &Ret);
    }
    else
    {
         /* do nothing */
    }

    return Ret;
}
/******************************************************************************
*  Service name     : Port_Drv_SetPinMode
*  Syntax           : TT_RetType Port_Drv_SetPinMode(
*                     TT_CONST Port_PinType Pin,
*                     TT_CONST Port_PinModeType Mode)
*  Service ID       : 102
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Pin - Pin ID
*                      Mode - Pin Mode
*  Parameters (out) : None
*  Return value     : None
*  Description      : Sets the PORT pin mode.
******************************************************************************/
TT_RetType Port_Drv_SetPinMode(TT_CONST Port_PinType Pin, TT_CONST Port_PinModeType Mode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Port_Drv_PriParaCheck((boolean)(Port_Drv_PubInitialized == FALSE),
                            PORT_DRV_SI_SETPINMODE,
                            TT_RET_STATUS_UNINIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Port_Hw_SetPinMode(Pin, Mode, Port_Config[PORTNUM]);
        Port_Drv_PriRetCheck(PORT_DRV_SI_SETPINMODE, &Ret);
    }
    else
    {
         /* do nothing */
    }

    return Ret;
}
/******************************************************************************
*  Service name     : Port_Drv_SetPinAllCfg
*  Syntax           : TT_RetType Port_Drv_SetPinAllCfg(
*                     TT_CONST Port_PinType Pin,
*                     TT_CONST Port_PinAllCfgType *PinAllCfg)
*  Service ID       : 103
*  Sync/Async       : Synchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : Pin - Pin ID
*                     PinAllCfg - Pin configuration
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Sets the PORT pin all configurations.
******************************************************************************/
TT_RetType Port_Drv_SetPinAllCfg(TT_CONST Port_PinType Pin, TT_CONST Port_PinAllCfgType *PinAllCfg)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Port_Drv_PriParaCheck((boolean)(Port_Drv_PubInitialized == FALSE),
                            PORT_DRV_SI_SETPINALLCFG,
                            TT_RET_STATUS_UNINIT_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Port_Hw_SetPinAllCfg(Pin, PinAllCfg);
        Port_Drv_PriRetCheck(PORT_DRV_SI_SETPINALLCFG, &Ret);
    }
    else
    {
         /* do nothing */
    }


    return Ret;
}

/******************************************************************************
*  Service name     : Port_Drv_GetVersionInfo
*  Syntax           : TT_RetType Port_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo)
*  Service ID       : 104
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : VersionInfo: Pointer to where to store the version
                      information of this module
*  Parameters (out) : None
*  Return value     : TT_RetType
*  Description      : Returns the version information of this module.
******************************************************************************/
TT_RetType Port_Drv_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Port_Drv_PriParaCheck((boolean)(NULL_PTR == VersionInfo),
                          PORT_DRV_SI_SETPINALLCFG,
                          TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        VersionInfo->vendorID         = PORT_DRV_VENDOR_ID_H;
        VersionInfo->moduleID         = PORT_DRV_MODULE_ID_H;
        VersionInfo->sw_major_version = PORT_DRV_SW_MAJOR_VERSION_H;
        VersionInfo->sw_minor_version = PORT_DRV_SW_MINOR_VERSION_H;
        VersionInfo->sw_patch_version = PORT_DRV_SW_PATCH_VERSION_H;
    }
    else
    {
         /* do nothing */
    }
    return Ret;
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h" 
/******************************************************************************
*                               Private Function
******************************************************************************/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h" 
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifndef USING_OS_AUTOSAROS
/**
* @brief        Port_Drv_PriCalcCustomCfgCrc
* @details      Checks whether the Pin Crc is valid or not
* @param[in]    no
* @return       uint32
* @retval       uint32 Crc
* @pre
*/
static uint32 Port_Drv_PriCalcCustomCfgCrc(void)
{
    /* Reset the accumulated CRC value */
    uint32 u32AccPort_CRCremainder=0;
    uint32 i=0;
    uint32 j=0;
    for(i=0;i < Port_ConfigData.Port_NumberOfContainers;i++)
    {
        for(j=0;j < Port_ConfigData.Containers[i].Port_NumberOfPortPins;j++)
        {
            if(Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDirection == PORT_PIN_IN)
            {
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDirection,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinInputEnable,&u32AccPort_CRCremainder);
#if (USE_DIO_MODULE == STD_ON)
                if(Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinInputInterruptUsed==TRUE){
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinInputInterruptUsed,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinExitTrigger,&u32AccPort_CRCremainder);
                }
#endif
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinInputConfigLock,&u32AccPort_CRCremainder);
            }

            if(Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDirection == PORT_PIN_OUT)
            {
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDirection,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinOutputEnable,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinOutputFuncLock,&u32AccPort_CRCremainder);
            }
            if(Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDirection == PORT_PIN_IN_OUT)
            {
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDirection,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinInputEnable,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinOutputEnable,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinInputConfigLock,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinOutputFuncLock,&u32AccPort_CRCremainder);

            }
            if(Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDirection != PORT_PIN_IN)
            {
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDriverLevel,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinModeOutputFunction,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinOutputModeValue,&u32AccPort_CRCremainder);
                if(Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinModeGtmOut == TRUE)
                {
                    Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinModeGtmOut,&u32AccPort_CRCremainder);
                    Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinGtmOutSelect,&u32AccPort_CRCremainder);
                    Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinGtmOutSelectFunc,&u32AccPort_CRCremainder);
                }
                else
                {
                  Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinModeGtmOut,&u32AccPort_CRCremainder);
                }
            }
            if(Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinDirection != PORT_PIN_OUT)
            {
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinModeInputFunction,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinInputPullDownEnable,&u32AccPort_CRCremainder);
                Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinDetailCfg->PinInputPullUpEnable,&u32AccPort_CRCremainder);
            }

        }
        for(j=0;j < Port_ConfigData.Containers[i].Port_NumberOfPortPins;j++)
        {
            Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinInitialSelectNumber,&u32AccPort_CRCremainder);
            Base_AccumulateCRC((TT_CONST uint32)Port_ConfigData.Containers[i].PinTotalCfg[j].PinID,&u32AccPort_CRCremainder);
        }
    }



    for(i=0;i < Port_ConfigData.Port_NumberOfContainers;i++)
    {
        Base_AccumulateCRC(Port_ConfigData.Containers[i].Port_NumberOfPortPins,&u32AccPort_CRCremainder);
    }
    Base_AccumulateCRC(Port_ConfigData.Port_NumberOfContainers,&u32AccPort_CRCremainder);


    return ((uint32)Base_FinalizeCRC(&u32AccPort_CRCremainder));
}

/**
* @brief         Dio_Drv_PriCalcCfgCrc.
* @details       Calculates the crc value of the configuration parameter.
* @param[in]
* @param[out]    u32AccCRCremainder - crc value
* @return        uint32
* @retval
* @pre
*/
#if (USE_DIO_MODULE == STD_ON)
static uint32 Dio_Drv_PriCalcCfgCrc(void)
{
    /* Reset the accumulated CRC value */
    uint32 u32AccCRCremainder=0;
    uint32 i = 0;
    while(Dio_GlobalData.Config->DioChannelConfigData[i] != DIO_END_OF_LIST)
    {
        Base_AccumulateCRC(Dio_GlobalData.Config->DioChannelConfigData[i], &u32AccCRCremainder);
        i++;
    }
    Base_AccumulateCRC(DIO_END_OF_LIST, &u32AccCRCremainder);
    i = 0;
    while(Dio_GlobalData.Config->DioChannelGroupConfigData[i].DioPortId != DIO_END_OF_LIST)
    {
        Base_AccumulateCRC(Dio_GlobalData.Config->DioChannelGroupConfigData[i].DioPortId, &u32AccCRCremainder);
        Base_AccumulateCRC(Dio_GlobalData.Config->DioChannelGroupConfigData[i].DioPortOffset, &u32AccCRCremainder);
        Base_AccumulateCRC(Dio_GlobalData.Config->DioChannelGroupConfigData[i].DioPortMask, &u32AccCRCremainder);
        i++;
    }
    Base_AccumulateCRC(DIO_END_OF_LIST, &u32AccCRCremainder);
    i = 0;
    while(Dio_GlobalData.Config->Dio_PortConfigData[i] != DIO_END_OF_LIST)
    {
        Base_AccumulateCRC(Dio_GlobalData.Config->Dio_PortConfigData[i], &u32AccCRCremainder);
        i++;
    }
    Base_AccumulateCRC(DIO_END_OF_LIST, &u32AccCRCremainder);
    Base_AccumulateCRC(Dio_GlobalData.UsedPortsMap, &u32AccCRCremainder);
    for(i=0;i<5;i++)
    {
        Base_AccumulateCRC(Dio_GlobalData.UsedChannelsMap[i], &u32AccCRCremainder);
    }


    return ((uint32)Base_FinalizeCRC(&u32AccCRCremainder));
}
#endif
#endif
#endif
#if (TT_SAFETY == STD_ON)
/**
* @brief        Port_Drv_InitCheck
* @details      InitCheck For Port After PortInit
* @param[in]    no
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Port_Drv_InitCheck(TT_CONST void *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Ret = Port_PriLogicCheck(ConfigPtr);
    if (TT_RET_SUCCESS != Ret)
    {
        Ret = TT_RET_STATUS_INIT_ERR;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Mtl_Port_PriLogicCheck
* @details      Check Port Config
* @param[in]    ConfigPtr : Const Ptr to Port Module
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Port_PriLogicCheck(TT_CONST Port_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 InputCfg = 0;
    uint32 OutputCfg = 0;
    uint32 i = 0, j = 0;
    uint32 PinInitSelectIndex = 0;
    uint32 InFunc = 0;
    uint32 OutFunc = 0;

    TT_CONST Port_PinTotalCfgType *TotalCfgPtr = NULL_PTR;
    TT_CONST Port_ContainerType *ContainerPtr = NULL_PTR;

        /* Init Every container */
    for (j = 0; j < ConfigPtr->Port_NumberOfContainers; j++)
    {
        /* get dest container */
        ContainerPtr = &(ConfigPtr->Containers[j]);

        for (i = 0; i < ContainerPtr->Port_NumberOfPortPins; i++)
        {
            TotalCfgPtr = &(ContainerPtr->PinTotalCfg[i]);
            PinInitSelectIndex = TotalCfgPtr->PinInitialSelectNumber;

            /* config pad Input */
            if (TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDirection == PORT_PIN_IN)
            {
                InputCfg = 0u;
                InputCfg |= PORT_GET_INFUNCTION_CFG(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeInputFunction, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputConfigLock, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputPullDownEnable, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputPullUpEnable, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputEnable);
                InFunc = TT_PAD_INFUNC->Pad_InFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)];

                if((InFunc & ((uint32)0xff << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID))) != (InputCfg << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID)))
                {
                    Ret = TT_RET_STATUS_ERR;
                }
                else
                {
                    /* do nothing */
                }
            }
            /* config pad Output */
            if (TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDirection == PORT_PIN_OUT)
            {
                OutputCfg = 0u;
                OutputCfg |= PORT_GET_OUTFUNCTION_CFG(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeOutputFunction, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputFuncLock, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputModeValue, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDriverLevel, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputEnable);
                OutFunc = TT_PAD_OUTFUNC->Pad_OutFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)];

                if((OutFunc & ((uint32)0xff << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID))) != (OutputCfg << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID)))
                {
                    Ret = TT_RET_STATUS_ERR;
                }
                else
                {
                    /* do nothing */
                }
            }
            // config pad in and Output
            if (TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDirection == PORT_PIN_IN_OUT)
            {
                InputCfg = 0u;
                OutputCfg = 0u;
                InputCfg |= PORT_GET_INFUNCTION_CFG(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeInputFunction, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputConfigLock, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputPullDownEnable, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputPullUpEnable, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinInputEnable);
                InFunc = TT_PAD_INFUNC->Pad_InFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)];

                OutputCfg |= PORT_GET_OUTFUNCTION_CFG(TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeOutputFunction, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputFuncLock, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputModeValue, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDriverLevel, \
                                TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinOutputEnable);
                OutFunc = TT_PAD_OUTFUNC->Pad_OutFunc[PAD_GET_REG_INDEX(TotalCfgPtr->PinID)];
                if(((InFunc & ((uint32)0xff << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID))) != \
                        (InputCfg << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID))) || \
                        (OutFunc & ((uint32)0xff << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID))) != \
                        (OutputCfg << (uint32)PAD_GET_REG_INNER_OFFSET(TotalCfgPtr->PinID)))
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
                 /* do nothing */
            }
        }
    }
    return Ret;
}
#if (USE_DIO_MODULE == STD_ON)
/**
* @brief        Mtl_Dio_InitCheck
* @details      InitCheck For Dio After DioInit
* @param[in]    no
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Dio_Drv_InitCheck(TT_CONST void *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST Port_ConfigType *TmpPtr = NULL_PTR;
    TT_ParaCheck(ConfigPtr == NULL_PTR, TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TmpPtr = ConfigPtr;
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_PriLogicCheck(TmpPtr);
        if (TT_RET_SUCCESS != Ret)
        {
            Ret = TT_RET_STATUS_INIT_ERR;
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
* @brief        Mtl_Dio_PriLogicCheck
* @details      Check Dio Config
* @param[in]    ConfigPtr : Const Ptr to Dio Module
* @return       uint32
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Dio_PriLogicCheck(TT_CONST Port_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 i = 0, j = 0;
    uint32 Mask = 0;
    uint32 PinInitSelectIndex = 0;
    TT_CONST Port_PinTotalCfgType *TotalCfgPtr = NULL_PTR;
    TT_CONST Port_ContainerType *ContainerPtr = NULL_PTR;

    for (j = 0; j < ConfigPtr->Port_NumberOfContainers; j++)
    {
        /* get dest container */
        ContainerPtr = &(ConfigPtr->Containers[j]);

        for (i = 0; i < ContainerPtr->Port_NumberOfPortPins; i++)
        {
            TotalCfgPtr = &(ContainerPtr->PinTotalCfg[i]);
            PinInitSelectIndex = TotalCfgPtr->PinInitialSelectNumber;

            /* config pad Input */
            if (TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDirection == PORT_PIN_IN && \
                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeInputFunction == PORT_PIN_MODE_INPUT_GPIO)
            {
                Dio_PortType TT_CONST PortId   = DIO_GET_PORT_FROM_PIN_ID(TotalCfgPtr->PinID);
                Dio_PortLevelType TT_CONST Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_PIN_ID(TotalCfgPtr->PinID);
                Mask = DioReg[PortId]->DIR;
                if((Mask & (0x1UL << Bit)) != ((~(0x1UL << Bit)) & (0x1UL << Bit)))
                {
                    Ret = TT_RET_STATUS_INITCHECK_ERR;
                }

            }
            /* config pad Output */
            if (TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinDirection == PORT_PIN_OUT && \
                    TotalCfgPtr->PinDetailCfg[PinInitSelectIndex].PinModeOutputFunction == PORT_PIN_MODE_OUTPUT_GPIO)
            {
                Dio_PortType TT_CONST PortId   = DIO_GET_PORT_FROM_PIN_ID(TotalCfgPtr->PinID);
                Dio_PortLevelType TT_CONST Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_PIN_ID(TotalCfgPtr->PinID);
                Mask = DioReg[PortId]->DIR;
                if((Mask & (0x1UL << Bit)) != ((0x1UL << Bit) & (0x1UL << Bit)))
                {
                    Ret = TT_RET_STATUS_INITCHECK_ERR;
                }
            }
            else
            {
                /* do nothing */
            }
        }
    }

    return Ret;
}
#endif
#endif
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h" 

#define PORT_START_SEC_CODE_FAST
#include "Port_MemMap.h"
/**
* @brief                Port_Drv_PriParaCheck
* @details              Reports Det error if PORT_DEV_ERROR_DETECT == STD_ON
* @param[in]            Expr - boolean expression to check API conditions
* @param[in]            ApiId - ServiceApiId -Service Id of API
* @param[in]            ErrId - Error Id of Conditionl
* @param[out]           RetVal - variable to check return type
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Port_Drv_PriParaCheck(boolean Expr, uint8 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(PORT_DRV_TT_STATUS_DEFAULT(ApiId),ErrId);
#if defined(PORT_DEV_ERROR_DETECT) && (PORT_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(PORT_MODULE_ID, ApiId, ErrId);
            ModuleDet_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, (uint8)ApiId, (uint8)ErrId);
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
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    (void)RetVal;
}
/**
* @brief            Port_Drv_PriRetCheck
* @details          Reports Det error if PORT_DEV_ERROR_DETECT == STD_ON
* @param[in]        ApiId - ServiceApiId -Service Id of API
* @param[out]       ErrId - Error Id of Conditionl
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Port_Drv_PriRetCheck(uint8 ApiId, TT_RetType *ErrId)
{
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
#if defined(PORT_DEV_ERROR_DETECT) && (PORT_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(PORT_MODULE_ID, ApiId, *ErrId);
            ModuleDet_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, (uint8)ApiId, (uint8)(*ErrId & 0xFFU));
#endif
            *ErrId = TT_SET_STATUS_TYPE(PORT_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
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
    (void)ApiId;
    (void)ErrId;
}

#define PORT_STOP_SEC_CODE_FAST
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif


