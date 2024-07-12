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
**  FILENAME     : Dio_Drv.h                                                  **
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
#ifndef DIO_DRV_H
#define DIO_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dio_Drv_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_DRV_VENDOR_ID_H                         (1541)
#define DIO_DRV_MODULE_ID_H                         (120)
#define DIO_DRV_AR_RELEASE_MAJOR_VERSION_H          (4)
#define DIO_DRV_AR_RELEASE_MINOR_VERSION_H          (4)
#define DIO_DRV_AR_RELEASE_PATCH_VERSION_H          (0)
#define DIO_DRV_SW_MAJOR_VERSION_H                  (1)
#define DIO_DRV_SW_MINOR_VERSION_H                  (1)
#define DIO_DRV_SW_PATCH_VERSION_H                  (0)
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dio_Drv.h Dio_Drv_Types.h file version check */
#if (DIO_DRV_TYPES_VENDOR_ID_H != DIO_DRV_VENDOR_ID_H)
    #error "Dio_Drv_Types.h and Dio_Drv.c have different vendor ids"
#endif

#if (DIO_DRV_TYPES_MODULE_ID_H != DIO_DRV_MODULE_ID_H)
    #error "Dio_Drv_Types.h and Dio_Drv.c have different module ids"
#endif

#if ((DIO_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H != DIO_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H != DIO_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H != DIO_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Drv_Types.h and Dio_Drv.c are different"
#endif

#if ((DIO_DRV_TYPES_SW_MAJOR_VERSION_H != DIO_DRV_SW_MAJOR_VERSION_H) || \
     (DIO_DRV_TYPES_SW_MINOR_VERSION_H != DIO_DRV_SW_MINOR_VERSION_H) || \
     (DIO_DRV_TYPES_SW_PATCH_VERSION_H != DIO_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Drv_Types.h and Dio_Drv.c are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
#define DIO_START_SEC_CODE_FAST
#include "Dio_MemMap.h"
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
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
                               Dio_LevelType *Level);

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
                                TT_CONST Dio_LevelType Level);

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
                            Dio_PortLevelType *Level);

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
                             TT_CONST Dio_PortLevelType Level);

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
                                    Dio_PortLevelType* Level);

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
                                     TT_CONST Dio_PortLevelType Level);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/******************************************************************************
*  Service name     : Dio_Drv_FlipChannel
*  Syntax           : TT_RetType Dio_Drv_FlipChannel(TT_CONST Dio_ChannelType ChannelId, Dio_LevelType *Level)
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
                               Dio_LevelType*Level);
#endif

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
                                   TT_CONST Dio_PortLevelType Mask);
#define DIO_STOP_SEC_CODE_FAST
#include "Dio_MemMap.h"
#if (DIO_VERSION_INFO_API == STD_ON)
/*****************************************************************************
*  service name    : Dio_GetVersionInfo
*  Syntax          : void Dio_Drv_GetVersionInfo(Std_VersionInfoType *versioninfo)
*  service ID      : 106
*  Sync/Async      : Synchronous                                                
*  Reentrancy      : Reentrant                                                  
*  Parameters (in) : None                                                       
*  Parameters (out): versioninfo -  Pointer to where to store the version
*                                   information of this module.                 
*  Return value    : None                                                       
*  Description     : This service returns the version information of this
*                    module.
******************************************************************************/
TT_RetType Dio_Drv_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif

/******************************************************************************
*  Service name     : Dio_Drv_Interrupt_Init
*  Syntax           : TT_RetType Dio_Drv_Interrupt_Init(TT_CONST Dio_ChannelType ChannelId, TT_CONST Dio_ExitTriggerType  TriggerMode)
*  Service ID       : 109
*  Sync/Async       : Asynchronous
*  Reentrancy       : non reentrant
*  Parameters (in)  : ChannelId - Id of DIO channel
*  Parameters (in)  : TriggerMode - Dio Exit Trigger Type
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_CHANNEL_ERR - Channel not configured.
*                     TT_RET_PARAM_ENUM_ERR - Parameter error.
*  Description      : Initializes the Dio Interrupt.
******************************************************************************/
#define DIO_START_SEC_CODE_SLOW
#include "Dio_MemMap.h"
TT_RetType Dio_Drv_Interrupt_Init(TT_CONST Dio_ChannelType ChannelId,
                                  TT_CONST Dio_ExitTriggerType  TriggerMode);
/******************************************************************************
*  Service name     : Dio_Drv_Interrupt_DeInit
*  Syntax           : TT_RetType Dio_Drv_Interrupt_DeInit(TT_CONST Dio_ChannelType ChannelId)
*  Service ID       : 110
*  Sync/Async       : Asynchronous
*  Reentrancy       : non reentrant
*  Parameters (in)  : ChannelId - Id of DIO channel
*  Return value     : TT_RET_SUCCESS - Funcation success
*                     TT_RET_PARAM_CHANNEL_ERR - Channel not configured.
*  Description      : Deinitializes the Dio Interrupt.
******************************************************************************/
TT_RetType Dio_Drv_Interrupt_DeInit(TT_CONST Dio_ChannelType ChannelId);

#define DIO_STOP_SEC_CODE_SLOW
#include "Dio_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */   
#endif /* DIO_DRV_H */
