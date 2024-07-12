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
**  FILENAME     : Dio_Drv_PBCfg.c                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Dio Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                                 Includes                                      
*******************************************************************************/
/* Include module header file */
#include "Dio_Drv.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_DRV_PBCFG_VENDOR_ID_C                       (1541U)
#define DIO_DRV_PBCFG_MODULE_ID_C                       (120U)
#define DIO_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C        (4U)
#define DIO_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C        (4U)
#define DIO_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C        (0U)
#define DIO_DRV_PBCFG_SW_MAJOR_VERSION_C                (1U)
#define DIO_DRV_PBCFG_SW_MINOR_VERSION_C                (1U)
#define DIO_DRV_PBCFG_SW_PATCH_VERSION_C                (0U)

/******************************************************************************
*                           File Version Checks
******************************************************************************/
 /* Dio_Drv_PBcfg.c Dio_Drv.h file version check */
#if(DIO_DRV_VENDOR_ID_H != DIO_DRV_PBCFG_VENDOR_ID_C)
    #error "Dio_Drv.h and Dio_Drv_PBcfg.c have different vendor ids"
#endif

#if (DIO_DRV_MODULE_ID_H != DIO_DRV_PBCFG_MODULE_ID_C)
    #error "Dio_Drv.h and Dio_Drv_PBcfg.c have different module ids"
#endif

#if((DIO_DRV_AR_RELEASE_MAJOR_VERSION_H != DIO_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C) || \
     (DIO_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != DIO_DRV_PBCFG_AR_RELEASE_MINOR_VERSION_C) || \
     (DIO_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != DIO_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of Dio_Drv_PBcfg.c and Dio_Drv.h are different"
#endif

#if((DIO_DRV_SW_MAJOR_VERSION_H != DIO_DRV_PBCFG_SW_MAJOR_VERSION_C) || \
    (DIO_DRV_SW_MINOR_VERSION_H != DIO_DRV_PBCFG_SW_MINOR_VERSION_C) || \
    (DIO_DRV_SW_PATCH_VERSION_H != DIO_DRV_PBCFG_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Dio_Drv_PBcfg.c and Dio_Drv.h are different"
#endif

/******************************************************************************
*                                 Structure and other types
******************************************************************************/
TT_CONST Dio_ChannelType DioChannelConfigData[];
TT_CONST Dio_ChannelGroupType Dio_ChannelGroup[];
TT_CONST Dio_PortType DioPortConfigData[];
TT_CONST Dio_ConfigType Dio_ConfigData[];

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h" 

TT_CONST Dio_ChannelType DioChannelConfigData[]=
{
    44u,
    45u,
    46u,
    47u,
    114u,
    57u,
    
    // Should add DIO_END_OF_LIST in the list last, Use fo channelID Valid check
    DIO_END_OF_LIST
};

TT_CONST Dio_ChannelGroupType Dio_ChannelGroup[]=
{    
    {
        .DioPortId      = DIO_PORT_TYPE_ID_1,
        .DioPortOffset  = 12,
        .DioPortMask    = 0xf000
    },

    // Should add DIO_END_OF_LIST in the list last, Use for channelID Valid check
    {
        DIO_END_OF_LIST,
        0,
        0
    }
};

TT_CONST Dio_PortType DioPortConfigData[]=
{
    DIO_PORT_TYPE_ID_0,
    // Should add DIO_END_OF_LIST in the list last, Use for channelID Valid check
    DIO_END_OF_LIST
};

TT_CONST Dio_ConfigType Dio_ConfigData[]=
{
    {
        .DioChannelConfigData        = DioChannelConfigData,
        .Dio_PortConfigData          = DioPortConfigData,
        .DioChannelGroupConfigData   = Dio_ChannelGroup,
        .GPIO0Notification           = NULL_PTR,
        .GPIO1Notification           = NULL_PTR,
        .GPIO2Notification           = NULL_PTR,
        .GPIO3Notification           = NULL_PTR,
        .GPIO4Notification           = NULL_PTR
    },    
};

static TT_CONST Dio_ChannelType GlobalUsedChannelsMap[]=
{
    0x0u,
    0x200f000u,
    0x0u,
    0x40000u,
    0x0u
};

TT_CONST Dio_GlobalType Dio_GlobalData =
{
    .Config = Dio_ConfigData,
    .UsedPortsMap = 1,
    .UsedChannelsMap = GlobalUsedChannelsMap,
    .DioCrc = 2917U
};


#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h" 

#ifdef __cplusplus
}
#endif /* __cplusplus */   

