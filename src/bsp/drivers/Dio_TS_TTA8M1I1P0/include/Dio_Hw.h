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
**  FILENAME     : Dio_Hw.h                                                   **
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
#ifndef DIO_HW_H
#define DIO_HW_H
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dio_Hw_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_HW_VENDOR_ID_H                    (1541)
#define DIO_HW_MODULE_ID_H                    (120)
#define DIO_HW_AR_RELEASE_MAJOR_VERSION_H     (4)
#define DIO_HW_AR_RELEASE_MINOR_VERSION_H     (4)
#define DIO_HW_AR_RELEASE_PATCH_VERSION_H     (0)
#define DIO_HW_SW_MAJOR_VERSION_H             (1)
#define DIO_HW_SW_MINOR_VERSION_H             (1)
#define DIO_HW_SW_PATCH_VERSION_H             (0)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dio_Hw.h Dio_Hw_Types.h file version check */
#if (DIO_HW_VENDOR_ID_H != DIO_HW_TYPES_VENDOR_ID_H)
    #error "Dio_Hw.h and Dio_Hw_Types.h have different vendor ids"
#endif

#if (DIO_HW_MODULE_ID_H != DIO_HW_TYPES_MODULE_ID_H)
    #error "Dio_Hw.h and Dio_Hw_Types.h have different module ids"
#endif

#if ((DIO_HW_AR_RELEASE_MAJOR_VERSION_H != DIO_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_HW_AR_RELEASE_MINOR_VERSION_H != DIO_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_HW_AR_RELEASE_PATCH_VERSION_H != DIO_HW_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Hw.h and Dio_Hw_Types.h are different"
#endif

#if ((DIO_HW_SW_MAJOR_VERSION_H != DIO_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (DIO_HW_SW_MINOR_VERSION_H != DIO_HW_TYPES_SW_MINOR_VERSION_H) || \
     (DIO_HW_SW_PATCH_VERSION_H != DIO_HW_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Hw.h and Dio_Hw_Types.h are different"
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
/**
* @brief        Dio_Hw_ReadChannel
* @details      Returns the value of the specified DIO channel.
* @param[in]    ChannelId - Id of DIO channel
* @return       Level
*               STD_HIGH: The physical level of the corresponding pin STD_HIGH
                STD_LOW : The physical level of the corresponding pin STD_LOW
* @retval
* @pre
*/
TT_RetType Dio_Hw_ReadChannel(TT_CONST Dio_ChannelType ChannelId,
                              Dio_LevelType * Level);

/**
* @brief        Dio_Hw_WriteChannel
* @details      Service to set a level of a channel.
* @param[in]    ChannelId - Id of DIO channel
*               Level   - value to be written.
* @return
* @retval
* @pre
*/
TT_RetType Dio_Hw_WriteChannel(TT_CONST Dio_ChannelType ChannelId,
                               TT_CONST Dio_LevelType Level);

/**
* @brief        Dio_Hw_ReadPort
* @details      Returns the level of all channels of that port.
* @param[in]    PortId - ID of DIO Port
* @return       Level
*               STD_HIGH: The physical level of the corresponding pin STD_HIGH
                STD_LOW : The physical level of the corresponding pin STD_LOW
* @retval
* @pre
*/
TT_RetType Dio_Hw_ReadPort(TT_CONST Dio_PortType PortId,
                           Dio_PortLevelType * Level);

/**
* @brief        Dio_Hw_WritePort
* @details      service to set a level of a Port.
* @param[in]    PortId - Port ID.
*               Level  - value to be written into the Port.
* @return
* @retval
* @pre
*/
TT_RetType Dio_Hw_WritePort(TT_CONST Dio_PortType PortId,
                            TT_CONST Dio_PortLevelType Level);

/**
* @brief        Dio_Hw_ReadChannelGroup
* @details      Returns the level of all channels of that port.
* @param[in]    ChannelGroupIdPtr - This structure contains Dio_PortType, Offset and Mask
* @return       Level
*               STD_HIGH: The physical level of the corresponding pin STD_HIGH
                STD_LOW : The physical level of the corresponding pin STD_LOW
* @retval
* @pre
*/
TT_RetType Dio_Hw_ReadChannelGroup(TT_CONST Dio_ChannelGroupType* ChannelGroupIdPtr,
                                   Dio_PortLevelType* Level);

/**
* @brief        Dio_Hw_WriteChannelGroup
* @details      Returns the level of all channels of that port.
* @param[in]    ChannelGroupIdPtr - This structure contains Dio_PortType, Offset and Mask
*               Level  - value to be written into the Port.
* @return
* @retval
* @pre
*/
TT_RetType Dio_Hw_WriteChannelGroup(TT_CONST Dio_ChannelGroupType *ChannelGroupIdPtr,
                                    TT_CONST Dio_PortLevelType Level);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/**
* @brief        Dio_Hw_FlipChannel
* @details      Service to flip (change from 1 to 0 or from 0 to 1) the level
                     of a channel and return the level of the channel after flip.
* @param[in]    ChannelId - ID of DIO channel
* @param[inout] Level - Whether to flip and return save the flipped value.
* @return       STD_HIGH: The physical level of the corresponding Pin is STD_HIGH.
                STD_LOW: The physical level of the corresponding Pin is STD_LOW
* @retval
* @pre
*/
TT_RetType Dio_Hw_FlipChannel(TT_CONST Dio_ChannelType ChannelId,
                              Dio_LevelType* Level);
#endif

/**
* @brief        Dio_Hw_MaskedWritePort
* @details      Service to set the value of a given port with required mask.
* @param[in]    PortId - ID of DIO Port
*               Level - Value to be written
*               Mask - Channels to be masked in the port
* @return
* @retval
* @pre
*/
TT_RetType Dio_Hw_MaskedWritePort(TT_CONST Dio_PortType PortId,
                                  TT_CONST Dio_PortLevelType Level,
                                  TT_CONST Dio_PortLevelType Mask);
#define DIO_STOP_SEC_CODE_FAST
#include "Dio_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#endif /* end of DIO_HW_H */

