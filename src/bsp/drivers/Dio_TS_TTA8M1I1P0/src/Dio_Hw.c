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
**  FILENAME     : Dio_Hw.c                                                   **
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
#include "Dio_Hw.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_HW_VENDOR_ID_C                      (1541)
#define DIO_HW_MODULE_ID_C                      (120)
#define DIO_HW_AR_RELEASE_MAJOR_VERSION_C       (4)
#define DIO_HW_AR_RELEASE_MINOR_VERSION_C       (4)
#define DIO_HW_AR_RELEASE_PATCH_VERSION_C       (0)
#define DIO_HW_SW_MAJOR_VERSION_C               (1)
#define DIO_HW_SW_MINOR_VERSION_C               (1)
#define DIO_HW_SW_PATCH_VERSION_C               (0)
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dio_Hw.h Dio_Hw.c file version check */
#if (DIO_HW_VENDOR_ID_C != DIO_HW_VENDOR_ID_H)
    #error "Dio.h and Dio_Hw.c have different vendor id"
#endif

#if (DIO_HW_MODULE_ID_C != DIO_HW_MODULE_ID_H)
    #error "Dio.h and Dio_Hw.c have different module id"
#endif

#if ((DIO_HW_AR_RELEASE_MAJOR_VERSION_C != DIO_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_HW_AR_RELEASE_MINOR_VERSION_C != DIO_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_HW_AR_RELEASE_PATCH_VERSION_C != DIO_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio.h and Dio_Hw.c are different"
#endif

#if ((DIO_HW_SW_MAJOR_VERSION_C != DIO_HW_SW_MAJOR_VERSION_H) || \
     (DIO_HW_SW_MINOR_VERSION_C != DIO_HW_SW_MINOR_VERSION_H) || \
     (DIO_HW_SW_PATCH_VERSION_C != DIO_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio.h and Dio_Hw.c are different"
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
static Dio_RegType *DioHwReg[] = TT_GPIO_BASE_PTRS; 

#define DIO_STOP_SEC_VAR_INIT_PTR
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE_FAST
#include "Dio_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/

/******************************************************************************
*                            Public Functions                                     
******************************************************************************/
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
                              Dio_LevelType *Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Dio_PortType  PortId = 0u;
    Dio_PortLevelType  Bit = 0u;

    TT_ParaCheck(ChannelId >= DIO_ALL_CHANNEL, TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck(FALSE == DIO_IS_CHANNEL_USED(ChannelId), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((Level == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        PortId = DIO_GET_PORT_FROM_CHANNEL_ID(ChannelId);
        Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_CHANNEL_ID(ChannelId);
        if((((DioHwReg[PortId]->DATA) >> Bit) & 0x1u) == TRUE)
        {
            *Level = STD_HIGH;
        }
        else
        {
            *Level = STD_LOW;
        }
    }
    
    return Ret;
}
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
                               TT_CONST Dio_LevelType Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Dio_PortType PortId = 0u;
    Dio_PortLevelType Bit = 0u;

//    TT_ParaCheck(ChannelId >= DIO_ALL_CHANNEL, TT_RET_PARAM_CHANNEL_ERR, &Ret);
//    TT_ParaCheck(FALSE == DIO_IS_CHANNEL_USED(ChannelId), TT_RET_PARAM_CHANNEL_ERR, &Ret);
//    TT_ParaCheck(!((Level == STD_HIGH) || (Level == STD_LOW)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        PortId = DIO_GET_PORT_FROM_CHANNEL_ID(ChannelId);
        Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_CHANNEL_ID(ChannelId);
        if (Level == STD_HIGH)
        {
            DioHwReg[PortId]->SOR = (uint32)(0x1UL << Bit);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            TT_ParaCheck((((DioHwReg[PortId]->DATA) >> Bit) & 0x1u) == FALSE, TT_RET_OPT_REG_ERR, &Ret);
#endif
        }
        else
        {
            DioHwReg[PortId]->COR = (uint32)(0x1UL << Bit);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            TT_ParaCheck(0 != (DioHwReg[PortId]->DATA & (0x1UL << Bit)), TT_RET_OPT_REG_ERR, &Ret);
#endif
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;

}
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
                           Dio_PortLevelType *Level)
{       
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(PortId > DIO_PORT_TYPE_ID_4, TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck(FALSE == DIO_IS_PORT_USED(PortId), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck((Level == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        *Level = DioHwReg[PortId]->DATA;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}   

/**
* @brief        Dio_Hw_ReadChannelGroup
* @details      Returns the level of all channels of that port.
* @param[in]    ChannelGroupIdPtr - This structure contains Dio_PortType, Offset and Mask
* @return       Level
* @retval
* @pre
*/
TT_RetType Dio_Hw_ReadChannelGroup(TT_CONST Dio_ChannelGroupType* ChannelGroupIdPtr,
                                   Dio_PortLevelType* Level)
{  
    TT_RetType Ret = TT_RET_SUCCESS;
    
    TT_ParaCheck((ChannelGroupIdPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck(((ChannelGroupIdPtr != NULL_PTR) &&
            ((ChannelGroupIdPtr->DioPortId > DIO_PORT_TYPE_ID_4) ||
            (ChannelGroupIdPtr->DioPortOffset >=  DIO_NUMBER_OF_CHANNEL))), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck((Level == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        *Level = (DioHwReg[ChannelGroupIdPtr->DioPortId]->DATA &(ChannelGroupIdPtr->DioPortMask))>>(ChannelGroupIdPtr->DioPortOffset);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}   
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
                            TT_CONST Dio_PortLevelType Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(PortId > DIO_PORT_TYPE_ID_4, TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck(FALSE == DIO_IS_PORT_USED(PortId), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        DioHwReg[PortId]->SOR = Level;
        DioHwReg[PortId]->COR = ~Level;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck(Level != (DioHwReg[PortId]->DATA & Level), TT_RET_OPT_REG_ERR, &Ret);
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}
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
                                    TT_CONST Dio_PortLevelType Level)
{       
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((ChannelGroupIdPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck(((ChannelGroupIdPtr != NULL_PTR) &&
                ((ChannelGroupIdPtr->DioPortId > DIO_PORT_TYPE_ID_4) ||
                (ChannelGroupIdPtr->DioPortOffset >=  DIO_NUMBER_OF_CHANNEL))), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        DioHwReg[ChannelGroupIdPtr->DioPortId]->SOR = (Level<<(ChannelGroupIdPtr->DioPortOffset))&(ChannelGroupIdPtr->DioPortMask);
        DioHwReg[ChannelGroupIdPtr->DioPortId]->COR = (~(Level<<(ChannelGroupIdPtr->DioPortOffset)))&(ChannelGroupIdPtr->DioPortMask);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck(((Level<<(ChannelGroupIdPtr->DioPortOffset))&(ChannelGroupIdPtr->DioPortMask)) !=
                      (DioHwReg[ChannelGroupIdPtr->DioPortId]->DATA &
                      ((Level<<(ChannelGroupIdPtr->DioPortOffset))&(ChannelGroupIdPtr->DioPortMask))), TT_RET_OPT_REG_ERR, &Ret);
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}   

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
                              Dio_LevelType* Level)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Dio_PortType PortId = 0u;
    Dio_PortLevelType Bit = 0u;

    TT_ParaCheck(ChannelId >= DIO_ALL_CHANNEL, TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck(FALSE == DIO_IS_CHANNEL_USED(ChannelId), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((Level == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        PortId = DIO_GET_PORT_FROM_CHANNEL_ID(ChannelId);
        Bit = (Dio_PortLevelType)DIO_GET_BIT_FROM_CHANNEL_ID(ChannelId);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        Dio_PortLevelType Date = DioHwReg[PortId]->DATA & (uint32)(0x1UL << Bit);
#endif
        DioHwReg[PortId]->TOR = (uint32)(0x1UL << Bit);

        if(0x1u == (((DioHwReg[PortId]->DATA) >> Bit) & 0x1u))
        {
           *Level = STD_HIGH;
        }
        else
        {
           *Level = STD_LOW;
        }
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        if(Date >= 1U)
        {
            TT_ParaCheck(0 < (DioHwReg[PortId]->DATA & (uint32)(0x1UL << Bit)), TT_RET_OPT_REG_ERR, &Ret);
        }
        else
        {
            TT_ParaCheck(0 == (DioHwReg[PortId]->DATA & (uint32)(0x1UL << Bit)), TT_RET_OPT_REG_ERR, &Ret);
        }
#endif
    }
    else
    {
        /* do nothing */
    }


    return Ret;
}
#endif

#if (DIO_MASKED_WRITE_PORT_API  == STD_ON)
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
                                  TT_CONST Dio_PortLevelType Mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(PortId > DIO_PORT_TYPE_ID_4, TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck(FALSE == DIO_IS_PORT_USED(PortId), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        DioHwReg[PortId]->SOR = Level & Mask;
        DioHwReg[PortId]->COR = (~Level) & Mask;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck(0 == (DioHwReg[PortId]->DATA & (Level & Mask)), TT_RET_OPT_REG_ERR, &Ret);
#endif
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
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif
