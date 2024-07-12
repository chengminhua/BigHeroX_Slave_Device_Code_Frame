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
**  FILENAME     : Dio_Drv.c                                                  **
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
#include "Dio_Drv.h"
#include "Dio_Hw.h"
#include "Dio_Hw_Irq.h"
#include "Mcu_Drv.h"

#if(defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#include "Base_Tools.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_DRV_VENDOR_ID_C                      (1541)
#define DIO_DRV_MODULE_ID_C                      (120)
#define DIO_DRV_AR_RELEASE_MAJOR_VERSION_C       (4)
#define DIO_DRV_AR_RELEASE_MINOR_VERSION_C       (4)
#define DIO_DRV_AR_RELEASE_PATCH_VERSION_C       (0)
#define DIO_DRV_SW_MAJOR_VERSION_C               (1)
#define DIO_DRV_SW_MINOR_VERSION_C               (1)
#define DIO_DRV_SW_PATCH_VERSION_C               (0)
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dio_Drv.h Dio_Drv.c file version check */
#if (DIO_DRV_VENDOR_ID_C != DIO_DRV_VENDOR_ID_H)
    #error "Dio_Drv.h and Dio_Drv.c have different vendor id"
#endif

#if (DIO_DRV_MODULE_ID_C != DIO_DRV_MODULE_ID_H)
    #error "Dio_Drv.h and Dio_Drv.c have different module id"
#endif

#if ((DIO_DRV_AR_RELEASE_MAJOR_VERSION_C != DIO_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_DRV_AR_RELEASE_MINOR_VERSION_C != DIO_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_DRV_AR_RELEASE_PATCH_VERSION_C != DIO_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Drv.h and Dio_Drv.c are different"
#endif

#if ((DIO_DRV_SW_MAJOR_VERSION_C != DIO_DRV_SW_MAJOR_VERSION_H) || \
     (DIO_DRV_SW_MINOR_VERSION_C != DIO_DRV_SW_MINOR_VERSION_H) || \
     (DIO_DRV_SW_PATCH_VERSION_C != DIO_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Drv.h and Dio_Drv.c are different"
#endif

/* Dio_Hw.h Dio_Drv.c file version check */
#if (DIO_DRV_VENDOR_ID_C != DIO_HW_VENDOR_ID_H)
    #error "Dio_Hw.h and Dio_Drv.c have different vendor id"
#endif

#if (DIO_DRV_MODULE_ID_C != DIO_HW_MODULE_ID_H)
    #error "Dio_Hw.h and Dio_Drv.c have different module id"
#endif

#if ((DIO_DRV_AR_RELEASE_MAJOR_VERSION_C != DIO_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_DRV_AR_RELEASE_MINOR_VERSION_C != DIO_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_DRV_AR_RELEASE_PATCH_VERSION_C != DIO_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Hw.h and Dio_Drv.c are different"
#endif

#if ((DIO_DRV_SW_MAJOR_VERSION_C != DIO_HW_SW_MAJOR_VERSION_H) || \
     (DIO_DRV_SW_MINOR_VERSION_C != DIO_HW_SW_MINOR_VERSION_H) || \
     (DIO_DRV_SW_PATCH_VERSION_C != DIO_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Hw.h and Dio_Drv.c are different"
#endif

/* Dio_Hw_Irq.h Dio_Drv.c file version check */
#if (DIO_DRV_VENDOR_ID_C != DIO_HW_IRQ_VENDOR_ID_H)
    #error "Dio_Hw_Irq.h and Dio_Drv.c have different vendor id"
#endif

#if (DIO_DRV_MODULE_ID_C != DIO_HW_IRQ_MODULE_ID_H)
    #error "Dio_Hw_Irq.h and Dio_Drv.c have different module id"
#endif

#if ((DIO_DRV_AR_RELEASE_MAJOR_VERSION_C != DIO_HW_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_DRV_AR_RELEASE_MINOR_VERSION_C != DIO_HW_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_DRV_AR_RELEASE_PATCH_VERSION_C != DIO_HW_IRQ_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Hw_Irq.h and Dio_Drv.c are different"
#endif

#if ((DIO_DRV_SW_MAJOR_VERSION_C != DIO_HW_IRQ_SW_MAJOR_VERSION_H) || \
     (DIO_DRV_SW_MINOR_VERSION_C != DIO_HW_IRQ_SW_MINOR_VERSION_H) || \
     (DIO_DRV_SW_PATCH_VERSION_C != DIO_HW_IRQ_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Hw_Irq.h and Dio_Drv.c are different"
#endif

/* Mcu_Drv.h Dio_Drv.c file version check */
#if (DIO_DRV_VENDOR_ID_C != MCU_DRV_VENDOR_ID_H)
    #error "Mcu_Drv.h and Dio_Drv.c have different vendor id"
#endif

#if ((DIO_DRV_AR_RELEASE_MAJOR_VERSION_C != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_DRV_AR_RELEASE_MINOR_VERSION_C != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_DRV_AR_RELEASE_PATCH_VERSION_C != MCU_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Drv.h and Dio_Drv.c are different"
#endif

#if ((DIO_DRV_SW_MAJOR_VERSION_C != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (DIO_DRV_SW_MINOR_VERSION_C != MCU_DRV_SW_MINOR_VERSION_H) || \
     (DIO_DRV_SW_PATCH_VERSION_C != MCU_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Drv.h and Dio_Drv.c are different"
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

/******************************************************************************
*                            Private Function Declaration                             
******************************************************************************/
/**
* @brief                Dio_Drv_PriParaCheck
* @details              Dio para check
* @param[in]            Expr - boolean expression to check API conditions
* @param[in]            ApiId - ServiceApiId -Service Id of API
* @param[in]            ErrId - Error Id of Conditionl
* @param[out]           RetVal - variable to check return type
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Dio_Drv_PriParaCheck(boolean Expr, uint32 ApiId, TT_RetType ErrId, TT_RetType *RetVal);
/**
* @brief            Dio_Drv_PriRetCheck
* @details          Dio return value check
* @param[in]        ApiId - ServiceApiId -Service Id of API
* @param[out]       ErrId - Error Id of Conditionl
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Dio_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId);

/******************************************************************************
*                            Public Functions                          
*******************************************************************************/
#define DIO_START_SEC_CODE_FAST
#include "Dio_MemMap.h"
/******************************************************************************
*  Service name     : Dio_Drv_ReadChannel
*  Syntax           : TT_RetType Dio_Drv_ReadChannel(TT_CONST Dio_ChannelType ChannelId, Dio_LevelType *Level)
*  Service ID       : 100
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : ChannelId - Id of DIO channel
*  Parameters (out) : Level - Current Channel level
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_CHANNEL_ERR - Channel not configured
*                     TT_RET_PARAM_NULL_PTR_ERR - Parameter is NULL.
*  Description      : Returns the value of the specified DIO channel.
******************************************************************************/
TT_RetType Dio_Drv_ReadChannel(TT_CONST Dio_ChannelType ChannelId,
                               Dio_LevelType *Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    boolean Status = FALSE;
    uint8 Type = (uint8)TT_SCU_CLK_CONTROL_GPIO0+(uint8)(ChannelId>>5);

    Ret = Mcu_Drv_Clk_StatusModules((TT_SCU_CLK_CONTROL_Type)Type, &Status);
    Dio_Drv_PriParaCheck(FALSE == Status,
                         DIO_DRV_SI_READCHANNEL,
                        TT_RET_STATUS_INIT_ERR, &Ret);
    if(TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_Hw_ReadChannel(ChannelId, Level);
        Dio_Drv_PriRetCheck(DIO_DRV_SI_READCHANNEL, &Ret);
    }
    else
    {
        *Level = 0;
    }

    return Ret;
}
/******************************************************************************
*  Service name     : Dio_Drv_WriteChannel
*  Syntax           : TT_RetType Dio_Drv_WriteChannel(TT_CONST Dio_ChannelType ChannelId, TT_CONST Dio_LevelType Level)
*  Service ID       : 101
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : ChannelId - Id of DIO channel
*  Parameters (in)  : Level - Current Channel level
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_CHANNEL_ERR - Channel not configured.
*                     TT_RET_PARAM_INVALID_DATA_ERR - Parameter error.
*                     TT_RET_STATUS_INIT_ERR - Initialization error.
*  Description      : Service to set a level of a channel.
******************************************************************************/
TT_RetType Dio_Drv_WriteChannel(TT_CONST Dio_ChannelType ChannelId,
                                TT_CONST Dio_LevelType Level)
{
    TT_RetType Ret = 0;
    boolean Status = FALSE;
    uint8 Type = (uint8)TT_SCU_CLK_CONTROL_GPIO0+(uint8)(ChannelId>>5);

    Ret = Mcu_Drv_Clk_StatusModules((TT_SCU_CLK_CONTROL_Type)Type, &Status);
//    Dio_Drv_PriParaCheck(FALSE == Status,
//                        DIO_DRV_SI_WRITECHANNEL,
//                        TT_RET_STATUS_INIT_ERR, &Ret);
    if(TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_Hw_WriteChannel(ChannelId, Level);
//        Dio_Drv_PriRetCheck(DIO_DRV_SI_WRITECHANNEL, &Ret);
    }
    else
    {
         /* do nothing */
    }

    return Ret;
}
/******************************************************************************
*  Service name     : Dio_Drv_ReadPort
*  Syntax           : TT_RetType Dio_Drv_ReadPort(TT_CONST Dio_PortType PortId, Dio_PortLevelType *Level)
*  Service ID       : 102
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : PortId - ID of DIO Port
*  Parameters (out) : Level - Current Port level
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Port not configured
*                     TT_RET_PARAM_NULL_PTR_ERR - Parameter is NULL.
*  Description      : Returns the level of all channels of that port.
******************************************************************************/
TT_RetType Dio_Drv_ReadPort(TT_CONST Dio_PortType PortId,
                            Dio_PortLevelType *Level)
{
    TT_RetType Ret = 0;
    boolean Status = FALSE;
    uint8 Type = (uint8)TT_SCU_CLK_CONTROL_GPIO0+(uint8)PortId;

    Ret = Mcu_Drv_Clk_StatusModules((TT_SCU_CLK_CONTROL_Type)Type, &Status);
    Dio_Drv_PriParaCheck(FALSE == Status,
                         DIO_DRV_SI_READPORT,
                        TT_RET_STATUS_INIT_ERR, &Ret);
    if(TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_Hw_ReadPort(PortId, Level);
        Dio_Drv_PriRetCheck(DIO_DRV_SI_READPORT, &Ret);
    }
    else
    {
        *Level = 0;
    }
    return Ret;
}
/******************************************************************************
*  Service name     : Dio_Drv_WritePort
*  Syntax           : TT_RetType Dio_Drv_WritePort(TT_CONST Dio_PortType PortId, TT_CONST Dio_PortLevelType Level)
*  Service ID       : 103
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : PortId - ID of DIO Port
*  Parameters (in)  : Level - Current Port level
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_ERR - Port not configured.
*                     TT_RET_STATUS_INIT_ERR - Initialization error.
*  Description      : Service to set a level of a Port.
******************************************************************************/
TT_RetType Dio_Drv_WritePort(TT_CONST Dio_PortType PortId,
                             TT_CONST Dio_PortLevelType Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    boolean Status = FALSE;
    uint8 Type = (uint8)TT_SCU_CLK_CONTROL_GPIO0+(uint8)PortId;

    Ret = Mcu_Drv_Clk_StatusModules((TT_SCU_CLK_CONTROL_Type)Type, &Status);
    Dio_Drv_PriParaCheck(FALSE == Status,
                        DIO_DRV_SI_WRITECHANNEL,
                        TT_RET_STATUS_INIT_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_Hw_WritePort(PortId, Level);
        Dio_Drv_PriRetCheck(DIO_DRV_SI_WRITEPORT, &Ret);
    }
    else
    {
         /* do nothing */
    }

    return Ret;
}
/******************************************************************************
*  Service name     : Dio_Drv_ReadChannelGroup
*  Syntax           : TT_RetType Dio_Drv_ReadChannelGroup(TT_CONST Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType* Level)
*  Service ID       : 104
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : ChannelGroupIdPtr - Configuration of ChannelGroup
*  Parameters (out) : Level - Current ChannelGroup level
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_NULL_PTR_ERR - Parameter is NULL.
*  Description      : This Service reads a subset of the adjoining bits of a port.
******************************************************************************/
TT_RetType Dio_Drv_ReadChannelGroup(TT_CONST Dio_ChannelGroupType* ChannelGroupIdPtr,
                                    Dio_PortLevelType* Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    boolean Status = FALSE;
//    Dio_Drv_PriParaCheck(NULL_PTR == ChannelGroupIdPtr,
//                         DIO_DRV_SI_READCHANNELGROUP,
//                         TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        uint8 Type = (uint8)TT_SCU_CLK_CONTROL_GPIO0+(uint8)(ChannelGroupIdPtr->DioPortId);

        Ret = Mcu_Drv_Clk_StatusModules((TT_SCU_CLK_CONTROL_Type)Type, &Status);
//        Dio_Drv_PriParaCheck(FALSE == Status,
//                             DIO_DRV_SI_READCHANNELGROUP,
//                             TT_RET_STATUS_INIT_ERR, &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
            Ret = Dio_Hw_ReadChannelGroup(ChannelGroupIdPtr, Level);
//            Dio_Drv_PriRetCheck(DIO_DRV_SI_READCHANNELGROUP, &Ret);
        }
        else
        {
            *Level = 0;
        }
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/******************************************************************************
*  Service name     : Dio_Drv_WriteChannelGroup
*  Syntax           : TT_RetType Dio_Drv_WriteChannelGroup(TT_CONST Dio_ChannelGroupType *ChannelGroupIdPtr, TT_CONST Dio_PortLevelType Level)
*  Service ID       : 105
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : ChannelGroupIdPtr - Configuration of ChannelGroup
*  Parameters (in)  : Level - Current ChannelGroup level
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_NULL_PTR_ERR - ChannelGroup not configured.
*                     TT_RET_STATUS_INIT_ERR - Initialization error.
*  Description      : Service to set a subset of the adjoining bits of a port to a specified level.
******************************************************************************/
TT_RetType Dio_Drv_WriteChannelGroup(TT_CONST Dio_ChannelGroupType *ChannelGroupIdPtr,
                                     TT_CONST Dio_PortLevelType Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    boolean Status = FALSE;
    Dio_Drv_PriParaCheck(NULL_PTR == ChannelGroupIdPtr,
                         DIO_DRV_SI_READCHANNELGROUP,
                         TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        uint8 Type = (uint8)TT_SCU_CLK_CONTROL_GPIO0+(uint8)(ChannelGroupIdPtr->DioPortId);

        Ret = Mcu_Drv_Clk_StatusModules((TT_SCU_CLK_CONTROL_Type)Type, &Status);
        Dio_Drv_PriParaCheck(FALSE == Status,
                            DIO_DRV_SI_WRITECHANNEL,
                            TT_RET_STATUS_INIT_ERR, &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
            Ret = Dio_Hw_WriteChannelGroup(ChannelGroupIdPtr, Level);
            Dio_Drv_PriRetCheck(DIO_DRV_SI_WRITECHANNELGROUP, &Ret);
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

#if (DIO_FLIP_CHANNEL_API  == STD_ON)
/******************************************************************************
*  Service name     : Dio_Drv_FlipChannel
*  Syntax           : TT_RetType Dio_Drv_FlipChannel(TT_CONST Dio_ChannelType ChannelId, Dio_LevelType *TT_CONST Level)
*  Service ID       : 107
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : ChannelId - Id of DIO channel
*  Parameters (out) : Level - Current Channel level
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_CHANNEL_ERR - Channel not configured.
*                     TT_RET_PARAM_NULL_PTR_ERR - Parameter is NULL.
*                     TT_RET_STATUS_INIT_ERR - Initialization error.
*  Description      : Service to flip (change 1 to 0 or 0 to 1) the level of
*                    the channel and return the level of the channel after flip.
******************************************************************************/
TT_RetType Dio_Drv_FlipChannel(TT_CONST Dio_ChannelType ChannelId,
                               Dio_LevelType* Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    boolean Status = FALSE;
    uint8 Type = (uint8)TT_SCU_CLK_CONTROL_GPIO0+(uint8)(ChannelId>>5);

    Ret = Mcu_Drv_Clk_StatusModules((TT_SCU_CLK_CONTROL_Type)Type, &Status);
    Dio_Drv_PriParaCheck(FALSE == Status,
                        DIO_DRV_SI_WRITECHANNEL,
                        TT_RET_STATUS_INIT_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_Hw_FlipChannel(ChannelId, Level);
        Dio_Drv_PriRetCheck(DIO_DRV_SI_FILPCHANNEL, &Ret);
    }
    else
    {
        *Level = 0;
    }

    return Ret;
}
#endif

#if (DIO_MASKED_WRITE_PORT_API  == STD_ON)
/******************************************************************************
*  Service name     : Dio_Drv_MaskedWritePort
*  Syntax           : TT_RetType Dio_Drv_MaskedWritePort(TT_CONST Dio_PortType PortId,
*                                                        TT_CONST Dio_PortLevelType Level,
*                                                        TT_CONST Dio_PortLevelType Mask)
*  Service ID       : 108
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : PortId - Id of DIO channel
*  Parameters (in)  : Level - Current Channel level
*  Parameters (in)  : Mask - Channels to be masked in the port
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_CHANNEL_ERR - Channel not configured.
*                     TT_RET_STATUS_INIT_ERR - Initialization error.
*  Description      : Service to set the value of a given port with required mask.
******************************************************************************/
TT_RetType Dio_Drv_MaskedWritePort(TT_CONST Dio_PortType PortId,
                                   TT_CONST Dio_PortLevelType Level,
                                   TT_CONST Dio_PortLevelType Mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    boolean Status = FALSE;
    uint8 Type = (uint8)TT_SCU_CLK_CONTROL_GPIO0+(uint8)PortId;

    Ret = Mcu_Drv_Clk_StatusModules((TT_SCU_CLK_CONTROL_Type)Type, &Status);
    Dio_Drv_PriParaCheck(FALSE == Status,
                        DIO_DRV_SI_WRITECHANNEL,
                        TT_RET_STATUS_INIT_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_Hw_MaskedWritePort(PortId, Level, Mask);
        Dio_Drv_PriRetCheck(DIO_DRV_SI_MASKEDWRITEPORT, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
#endif
#define DIO_STOP_SEC_CODE_FAST
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE_SLOW
#include "Dio_MemMap.h"
#if (DIO_VERSION_INFO_API == STD_ON)
/*****************************************************************************
*  service name    : Dio_GetVersionInfo                                         
*  Syntax          : void Dio_Drv_GetVersionInfo(Std_VersionInfoType *TT_CONST VersionInfo)
*  service ID      : 106                                                      
*  Sync/Async      : Synchronous                                                
*  Reentrancy      : Reentrant                                                  
*  Parameters (in) : None                                                       
*  Parameters (out): VersionInfo -  Pointer to where to store the version       
*                                   information of this module.                 
*  Return value    : None                                                       
*  Description     : This service returns the version information of this
*                    module.
******************************************************************************/
TT_RetType Dio_Drv_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{   
    TT_RetType Ret = TT_RET_SUCCESS;
        
    Dio_Drv_PriParaCheck(TRUE == (VersionInfo == NULL_PTR),
                        DIO_DRV_SI_GETVERSIONINFO,
                        TT_RET_PARAM_NULL_PTR_ERR, &Ret);
                        
    if (Ret == TT_RET_SUCCESS)
    {
        VersionInfo->vendorID         = DIO_DRV_VENDOR_ID_H;
        VersionInfo->moduleID         = DIO_DRV_MODULE_ID_H;
        VersionInfo->sw_major_version = DIO_DRV_SW_MAJOR_VERSION_H;
        VersionInfo->sw_minor_version = DIO_DRV_SW_MINOR_VERSION_H;
        VersionInfo->sw_patch_version = DIO_DRV_SW_PATCH_VERSION_H;
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}
#endif
/******************************************************************************
*  Service name     : Dio_Drv_Interrupt_DeInit
*  Syntax           : TT_RetType Dio_Drv_Interrupt_DeInit(TT_CONST Dio_ChannelType ChannelId)
*  Service ID       : 110
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : ChannelId - Id of DIO channel
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_CHANNEL_ERR - Channel not configured.
*  Description      : Deinitializes the Dio Interrupt.
******************************************************************************/
TT_RetType Dio_Drv_Interrupt_DeInit(TT_CONST Dio_ChannelType ChannelId)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Dio_Drv_PriParaCheck(FALSE == DIO_IS_CHANNEL_USED(ChannelId),
                         DIO_DRV_SI_INTERRUPTDEINIT,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_Hw_Interrupt_DeInit(ChannelId);
        Dio_Drv_PriRetCheck(DIO_DRV_SI_INTERRUPTDEINIT, &Ret);
    }
    else
    {
         /* do nothing */
    }

    return Ret;
}
/******************************************************************************
*  Service name     : Dio_Drv_Interrupt_Init
*  Syntax           : TT_RetType Dio_Drv_Interrupt_Init(TT_CONST Dio_ChannelType ChannelId, TT_CONST Dio_ExitTriggerType  TriggerMode)
*  Service ID       : 109
*  Sync/Async       : Asynchronous
*  Reentrancy       : reentrant
*  Parameters (in)  : ChannelId - Id of DIO channel
*  Parameters (in)  : TriggerMode - Dio Exit Trigger Type
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_CHANNEL_ERR - Channel not configured.
*                     TT_RET_PARAM_ENUM_ERR - Parameter error.
*  Description      : Initializes the Dio Interrupt.
******************************************************************************/
TT_RetType Dio_Drv_Interrupt_Init(TT_CONST Dio_ChannelType ChannelId,
                                  TT_CONST Dio_ExitTriggerType TriggerMode)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Dio_Drv_PriParaCheck(FALSE == DIO_IS_CHANNEL_USED(ChannelId),
                          DIO_DRV_SI_INTERRUPTINIT,
                          TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        Ret = Dio_Hw_Interrupt_Init(ChannelId, TriggerMode);
        Dio_Drv_PriRetCheck(DIO_DRV_SI_INTERRUPTINIT, &Ret);
    }
    else
    {
         /* do nothing */
    }

    return Ret;
}
#define DIO_STOP_SEC_CODE_SLOW
#include "Dio_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
#define Dio_START_SEC_CODE_FAST
#include "Dio_MemMap.h"
/**
* @brief                Dio_Drv_PriParaCheck
* @details              Dio para check
* @param[in]            Expr - boolean expression to check API conditions
* @param[in]            ApiId - ServiceApiId -Service Id of API
* @param[in]            ErrId - Error Id of Conditionl
* @param[out]           RetVal - variable to check return type
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Dio_Drv_PriParaCheck(boolean Expr, uint32 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != RetVal)
    {
        if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(DIO_DRV_TT_STATUS_DEFAULT(ApiId), ErrId);;
#if defined(DIO_DEV_ERROR_DETECT) && (DIO_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(DIO_MODULE_ID, ApiId, ErrId);
            ModuleDet_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, (uint8)ApiId, (uint8)ErrId);
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
* @brief            Dio_Drv_PriRetCheck
* @details          Dio return value check
* @param[in]        ApiId - ServiceApiId -Service Id of API
* @param[out]       ErrId - Error Id of Conditionl
* @return
* @retval
* @pre
*/
LOCAL_INLINE void Dio_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
#if defined(DIO_DEV_ERROR_DETECT) && (DIO_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(DIO_MODULE_ID, ApiId, *ErrId);
            ModuleDet_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, (uint8)ApiId, (uint8)*ErrId);
#endif
            *ErrId = TT_SET_STATUS_TYPE(DIO_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
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
    (void)ApiId;
    (void)ErrId;
}
#define Dio_STOP_SEC_CODE_FAST
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif
