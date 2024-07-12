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
**  FILENAME     : Dma_Hw.c                                                   **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Dma Driver Source File                                     **
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
#include "Dma_Hw.h"
#include "Mcu_Drv.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DMA_HW_VENDOR_ID_C                                   (1541U)
#define DMA_HW_MODULE_ID_C                                   (220U)
#define DMA_HW_AR_RELEASE_MAJOR_VERSION_C                    (4U)
#define DMA_HW_AR_RELEASE_MINOR_VERSION_C                    (4U)
#define DMA_HW_AR_RELEASE_PATCH_VERSION_C                    (0U)
#define DMA_HW_SW_MAJOR_VERSION_C                            (1U)
#define DMA_HW_SW_MINOR_VERSION_C                            (1U)
#define DMA_HW_SW_PATCH_VERSION_C                            (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dma_Hw.c Dma_Hw.h file version check */
#if (DMA_HW_VENDOR_ID_C != DMA_HW_VENDOR_ID_H)
    #error "Dma_Hw.h and Dma_Hw.c have different vendor ids"
#endif

#if (DMA_HW_MODULE_ID_C != DMA_HW_MODULE_ID_H)
    #error "Dma_Hw.h and Dma_Hw.c have different module ids"
#endif

#if ((DMA_HW_AR_RELEASE_MAJOR_VERSION_C != DMA_HW_AR_RELEASE_MAJOR_VERSION_H) || \
     (DMA_HW_AR_RELEASE_MINOR_VERSION_C != DMA_HW_AR_RELEASE_MINOR_VERSION_H) || \
     (DMA_HW_AR_RELEASE_PATCH_VERSION_C != DMA_HW_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dma_Hw.h and Dma_Hw.c are different"
#endif

#if ((DMA_HW_SW_MAJOR_VERSION_C != DMA_HW_SW_MAJOR_VERSION_H) || \
     (DMA_HW_SW_MINOR_VERSION_C != DMA_HW_SW_MINOR_VERSION_H) || \
     (DMA_HW_SW_PATCH_VERSION_C != DMA_HW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dma_Hw.h and Dma_Hw.c are different"
#endif

/* Dma_Hw.c Mcu_Drv.h file version check */
#if (MCU_DRV_VENDOR_ID_H != DMA_HW_VENDOR_ID_C)
    #error "Mcu_Drv.h and Dma_Hw.c have different vendor ids"
#endif

#if ((MCU_DRV_AR_RELEASE_MAJOR_VERSION_H != DMA_HW_AR_RELEASE_MAJOR_VERSION_C) || \
     (MCU_DRV_AR_RELEASE_MINOR_VERSION_H != DMA_HW_AR_RELEASE_MINOR_VERSION_C) || \
     (MCU_DRV_AR_RELEASE_PATCH_VERSION_H != DMA_HW_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of Dma_Hw.c and Mcu_Drv.h are different"
#endif

#if ((MCU_DRV_SW_MAJOR_VERSION_H != DMA_HW_SW_MAJOR_VERSION_C) || \
     (MCU_DRV_SW_MINOR_VERSION_H != DMA_HW_SW_MINOR_VERSION_C) || \
     (MCU_DRV_SW_PATCH_VERSION_H != DMA_HW_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Dma_Hw.c and Mcu_Drv.h are different"
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
#define DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/* Channel free flag bit */
static volatile uint32 Channel_active = 0U;
/* Channel information recording */
static volatile Dma_Hw_Channel_Info Channel_info[DMA_NUMBERS][DMA_NUMBER_OF_CHANNEL];
#define DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_START_SEC_CONST_FAST_UNSPECIFIED
#include "Dma_MemMap.h"
/* An array of Pointers to the base address of the DMA register */
static Dma_RegType* TT_CONST g_gpdmaBase[DMA_NUMBERS] = {TT_DMA0,TT_DMA1,TT_DMA2,TT_DMA3};
#define DMA_STOP_SEC_CONST_FAST_UNSPECIFIED
#include "Dma_MemMap.h"
/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#define DMA_START_SEC_CODE_FAST
#include "Dma_MemMap.h"
/**
* @brief         Dma_Hw_SetChActiveFlag.
* @details       Set channel active flag
* @param[in]     Ch - Dma channel id
* @param[out]    None
* @return        0 - Funcation success
*                1 - Channel already active
*/
LOCAL_INLINE uint32 Dma_Hw_SetChActiveFlag (uint32 Ch);
/**
* @brief         Dma_Hw_ClearChActiveFlag
* @details       Protected clear of channel active flag.
* @param[in]     Ch - Dma channel id
* @param[out]    None
* @return        None
*/
LOCAL_INLINE void Dma_Hw_ClearChActiveFlag (uint32 Ch);

/**
* @brief        Dma_Hw_PriChannel
* @details      Get Dma Channel Base Address 
* @param[in]    Ch - Dma Channel Index
* @return       TT_GPDMA0_ChannelConfig_Type *
* @retval       
* @pre          
*/
static volatile TT_GPDMA0_ChannelConfig_Type * Dma_Hw_PriChannel(uint32 Ch);

/**
* @brief        Dma_Hw_PriChConfigSrcPe
* @details      Set Dma Channel Source Peripheral Id 
* @param[in]    Ch - Dma Channel Index
* @return       uint32
* @retval       
* @pre          
*/
LOCAL_INLINE uint32 Dma_Hw_PriChConfigSrcPe(uint32 Ch);

/**
* @brief        Dma_Hw_PriChConfigDestPe
* @details      Set Dma Channel Dest Peripheral Id 
* @param[in]    Ch - Dma Channel Index
* @return       uint32
* @retval       
* @pre          
*/
LOCAL_INLINE uint32 Dma_Hw_PriChConfigDestPe(uint32 Ch);

/**
* @brief        Dma_Hw_PriChConfigFlow
* @details      Set Dma Channel Flowcntrl 
* @param[in]    Ch - Dma Channel Index
* @return       uint32
* @retval       
* @pre          
*/
LOCAL_INLINE uint32 Dma_Hw_PriChConfigFlow(uint32 Ch);

/**
* @brief        Dma_Hw_PriChControlTransferSize
* @details      Set Dma Channel Transfersize 
* @param[in]    Ch - Dma Channel Index
* @return       uint32
* @retval       
* @pre          
*/
LOCAL_INLINE uint32 Dma_Hw_PriChControlTransferSize(uint32 Size);

/**
* @brief        Dma_Hw_Inner_Initialize.
* @details      Initialize Dma unit
* @param[in]    instance - Dma unit id
* @return       None
* @retval
* @pre
*/
static void Dma_Hw_PriInit (TT_CONST uint32 Instance);

/**
* @brief        Dma_Hw_PriAddressValid.
* @details      Check whether the IP address is within the configured range.
* @param[in]    DmaChannelCfg - Config data
* @param[in]    srcaddr - Source address
* @param[in]    destaddr - Destination address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
LOCAL_INLINE TT_RetType Dma_Hw_PriAddressValid (TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg,
                                                TT_CONST uint32 SrcAddr,
                                                TT_CONST uint32 DestAddr);

/**
* @brief        Dma_Hw_PriSetDmaMode.
* @details      Set dma single/continuous mode.
* @param[in]    DmaChannelCfg - Config data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Dma_Hw_PriSetDmaMode(TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg);

/**
* @brief         Dma_Hw_PriSetControl.
* @details       Configure the control register.
* @param[in]     DmaChannelCfg - Config data
* @param[in]     DmaTranferSize - transfer size
* @param[in]     DmaSourceAddress - Source address
* @param[in]     DmaDestAddress - Destination address
* @param[in]     DmaChannel - Dma Channel
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Dma_Hw_PriSetControl(TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg,
                                       TT_CONST uint32          DmaTranferSize,
                                       TT_CONST uint32          DmaSourceAddress,
                                       TT_CONST uint32          DmaDestAddress,
                                       TT_CONST uint32          DmaChannel);

/**
* @brief         Dma_Hw_PriSetConfig.
* @details       Configure the config register.
* @param[in]     DmaChannelCfg - Config data
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Dma_Hw_PriSetConfig(TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg);

/******************************************************************************
*                            Public Functions
******************************************************************************/
/**
* @brief        Dma_Hw_Init.
* @details      Initialize Dma unit
* @param[in]    Ch - Dma channel id
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Dma_Hw_Init (TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_CONST uint32 instance = Ch >> 3;

    TT_ParaCheck((Ch >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        /*Turn on the corresponding clock according to different hardware units*/
        switch(instance)
        {
            case 0:
                /*Enable dmac0 clock*/
                Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_DMAC0);
                break;
            case 1:
                /*Enable dmac1 clock*/
                Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_DMAC1);
                break;
            case 2:
                /*Enable dmac2 clock*/
                Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_DMAC2);
                break;
            default:
                /*Enable dmac3 clock*/
                Ret = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_DMAC3);
                break;
        }
        /*Init dmac information*/
        Dma_Hw_PriInit(instance);
    }
    else 
    {
        /*do nothing*/
    }

    return Ret;
}
#define DMA_STOP_SEC_CODE_FAST
#include "Dma_MemMap.h"
/**
* @brief        Dma_Hw_DeInit.
* @details      De-initialize Dma unit
* @param[in]    Hardware - Dma Hardware Unit
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
#define DMA_START_SEC_CODE_SLOW
#include "Dma_MemMap.h"
TT_RetType Dma_Hw_DeInit (TT_CONST uint32 Hardware)
{
    uint32 i = 0;
    TT_RetType Ret = TT_RET_SUCCESS;
        /*Turn off the corresponding clock according to different hardware units*/
    switch(Hardware)
    {
        case 0:
            TT_ParaCheck(TT_RET_SUCCESS != Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_DMAC0), TT_RET_STATUS_INIT_ERR, &Ret);
            TT_ParaCheck(TT_RET_SUCCESS != Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_DMAC0), TT_RET_STATUS_INIT_ERR, &Ret);
            break;
        case 1:
            TT_ParaCheck(TT_RET_SUCCESS != Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_DMAC1), TT_RET_STATUS_INIT_ERR, &Ret);
            TT_ParaCheck(TT_RET_SUCCESS != Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_DMAC1), TT_RET_STATUS_INIT_ERR, &Ret);
            break;
        case 2:
            TT_ParaCheck(TT_RET_SUCCESS != Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_DMAC2), TT_RET_STATUS_INIT_ERR, &Ret);
            TT_ParaCheck(TT_RET_SUCCESS != Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_DMAC2), TT_RET_STATUS_INIT_ERR, &Ret);
            break;
        case 3:
            TT_ParaCheck(TT_RET_SUCCESS != Mcu_Drv_Misc_LocalResetModules(TT_SCU_LOCAL_RST_DMAC3), TT_RET_STATUS_INIT_ERR, &Ret);
            TT_ParaCheck(TT_RET_SUCCESS != Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_DMAC3), TT_RET_STATUS_INIT_ERR, &Ret);
            break;
        default:
            Ret = TT_RET_PARAM_ERR;
            break;
    }
    if(TT_RET_SUCCESS == Ret)
    {
        for(i = Hardware<<3;i<((Hardware<<3)+8);i++)
        {
            Dma_Hw_ClearChActiveFlag (i);
        }
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}
#define DMA_STOP_SEC_CODE_SLOW
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE_FAST
#include "Dma_MemMap.h"
/**
* @brief         Dma_Hw_ChannelConfigure
* @details       Configure DMA channel for next transfer
* @param[in]     DmaChannelCfg - Config data
* @param[in]     DmaTranferSize - transfer size
* @param[in]     DmaSourceAddress - Source address
* @param[in]     DmaDestAddress - Destination address
* @param[in]     Cb_Event - Channel callback pointer
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_ChannelConfigure (TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg,
                                    TT_CONST uint32            DmaTranferSize,
                                    TT_CONST uint32            DmaSourceAddress,
                                    TT_CONST uint32            DmaDestAddress,
                                    Dma_SignalEvent_t          Cb_Event)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    uint32 channel_msk = 0;
    uint32 size = DmaTranferSize;
    uint32 Srctmp = 0;
    uint32 Desttmp = 0;
    uint32 ChActive = 0;
    TT_ParaCheck((DmaChannelCfg == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        TT_ParaCheck((((DmaChannelCfg->DmaAccessMode != DMA_USER_MODE) && (DmaChannelCfg->DmaAccessMode != DMA_PRIVILEGE_MODE))), TT_RET_PARAM_ENUM_ERR, &Ret);
        TT_ParaCheck((((DmaChannelCfg->DmaDMaster != DMA_MASTER1) && (DmaChannelCfg->DmaDMaster != DMA_MASTER2))), TT_RET_PARAM_ENUM_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaFlowControl > DMA_CONTROL_PERIPHERAL_TO_PERIPHERAL)), TT_RET_PARAM_ENUM_ERR, &Ret);
        TT_ParaCheck((((DmaChannelCfg->DmaSMaster != DMA_MASTER1) && (DmaChannelCfg->DmaSMaster != DMA_MASTER2))), TT_RET_PARAM_ENUM_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaDestBurstSize > DMA_256_BURST)), TT_RET_PARAM_ENUM_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaSourceBurstSize > DMA_256_BURST)), TT_RET_PARAM_ENUM_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaDestDataWidth > DMA_64_BIT_DATA)), TT_RET_PARAM_ENUM_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaSourceDataWidth > DMA_64_BIT_DATA)), TT_RET_PARAM_ENUM_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaContinuousMode != FALSE) && (DmaChannelCfg->DmaContinuousMode != TRUE)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaAllInOne != FALSE) && (DmaChannelCfg->DmaAllInOne != TRUE)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaDestIncrease != FALSE) && (DmaChannelCfg->DmaDestIncrease != TRUE)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaSourceIncrease != FALSE) && (DmaChannelCfg->DmaSourceIncrease != TRUE)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaIntTtrg != FALSE) && (DmaChannelCfg->DmaIntTtrg != TRUE)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
        TT_ParaCheck(((DmaChannelCfg->DmaIrqEn != FALSE) && (DmaChannelCfg->DmaIrqEn != TRUE)), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
        TT_ParaCheck((DmaChannelCfg->DmaChannelId >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_VALUE_ERR, &Ret);
        TT_ParaCheck((DmaChannelCfg->DmaDestPeripheralId >= DMA_NUMBER_OF_PERIPHERALID), TT_RET_PARAM_VALUE_ERR, &Ret);
        TT_ParaCheck((DmaChannelCfg->DmaSrcPeripheralId >= DMA_NUMBER_OF_PERIPHERALID), TT_RET_PARAM_VALUE_ERR, &Ret);
        TT_ParaCheck((Dma_Hw_PriAddressValid(DmaChannelCfg,DmaSourceAddress,DmaDestAddress) == TT_RET_PARAM_ADDR_ERR), TT_RET_PARAM_ADDR_ERR, &Ret);
        if (TT_RET_SUCCESS == Ret)
        {
            TT_CONST uint32 channel = DmaChannelCfg->DmaChannelId;
            /* Save callback pointer */
            Channel_info[channel/8][channel%8].cb_event = Cb_Event;

            /* Clear DMA interrupts */
            channel_msk = channel & 0x7U;
            g_gpdmaBase[channel/8]->INTTCCLEAR = (uint32)(1UL << channel_msk);
            g_gpdmaBase[channel/8]->INTERRCLR  = (uint32)(1UL << channel_msk);
            /* Enable DMA Channels, little endian */
            g_gpdmaBase[channel/8]->CONFIG = (uint32)TT_DMA_CONFIG_E_Msk;
            Channel_info[channel/8][channel%8].Size = size;
            /*Judge whether 0xFFFU is exceeded*/
            if (size > 0xFFFU)
            {
                /* Max DMA transfer number 4096 */
                size = 0xFFFU;
            }
            else
            {
                /*do nothing*/
            }

            /* Set dma request signal */
            Srctmp  = DmaChannelCfg->DmaSrcPeripheralId % 16;
            Desttmp = DmaChannelCfg->DmaDestPeripheralId % 16;
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
#endif
            if (((uint32)DmaChannelCfg->DmaFlowControl == (uint32)DMA_CONTROL_PERIPHERAL_TO_PERIPHERAL) || ((uint32)DmaChannelCfg->DmaFlowControl == (uint32)DMA_CONTROL_PERIPHERAL_TO_MEMERY))
            {
                g_gpdmaBase[channel/8]->DMACREGSEL[Srctmp/4] &= ~(uint32)(0x3FUL << (8*(Srctmp % 4)));
            }
            else
            {
                g_gpdmaBase[channel/8]->DMACREGSEL[Desttmp/4] &= ~(uint32)(0x3FUL << (8*(Desttmp % 4)));
            }
            g_gpdmaBase[channel/8]->DMACREGSEL[Srctmp/4] |= DmaChannelCfg->DmaSrcPeripheralId << (8*(Srctmp % 4));
            g_gpdmaBase[channel/8]->DMACREGSEL[Desttmp/4] |= DmaChannelCfg->DmaDestPeripheralId << (8*(Desttmp % 4));
#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
#endif
            /*Set control register*/
            Ret = Dma_Hw_PriSetControl(DmaChannelCfg,size,DmaSourceAddress,DmaDestAddress,channel);
            if (TT_RET_SUCCESS == Ret)
            {
                /*Set config register*/
                Ret = Dma_Hw_PriSetConfig(DmaChannelCfg);
                ChActive = Dma_Hw_SetChActiveFlag (channel);
                TT_ParaCheck((ChActive == 1),TT_RET_PARAM_CHANNEL_ERR,&Ret);
            }
            else
            {
                /*do nothing*/
            }
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}
#define DMA_STOP_SEC_CODE_FAST
#include "Dma_MemMap.h"
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/**
* @brief         Dma_Hw_OneShotTrigger
* @details       Trigger one shot mode
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_OneShotTrigger(TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 ChActive = 0;
    TT_ParaCheck((Ch >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        volatile TT_GPDMA0_ChannelConfig_Type *TT_CONST dma_ch = Dma_Hw_PriChannel(Ch);

        if (Channel_info[Ch/8][Ch%8].DmaMode == DMA_ONESHOT_MODE)
        {
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_05();
#endif
            dma_ch->ONEMODE_EN = (uint32)TT_DMA_C_ONEMODE_EN_ONE_MODE_EN_Msk;
            ChActive = Dma_Hw_SetChActiveFlag (Ch);
            TT_ParaCheck((ChActive == 1),TT_RET_PARAM_CHANNEL_ERR,&Ret);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck((dma_ch->ONEMODE_EN != TT_DMA_C_ONEMODE_EN_ONE_MODE_EN_Msk), TT_RET_OPT_REG_ERR, &Ret);
#endif
#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_05();
#endif
        }
        else
        {
            Ret = TT_RET_PARAM_MODE_ERR;
        }
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}

/**
* @brief         Dma_Hw_DisableContinuation
* @details       Disable continuation mode
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_DisableContinuation(TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((Ch >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_ERR, &Ret);

    TT_ParaCheck((Channel_active == 0x0UL), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        volatile TT_GPDMA0_ChannelConfig_Type *TT_CONST dma_ch = Dma_Hw_PriChannel(Ch);

        if (Channel_info[Ch/8][Ch%8].DmaMode == DMA_CONTINUOUS_MODE)
        {
            dma_ch->MODE_CLR = (uint32)TT_DMA_C_MODE_CLR_CONTINUE_MODE_CLR_Msk;
        }
        else
        {
            Ret = TT_RET_PARAM_MODE_ERR;
        }
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}

/**
* @brief         Dma_Hw_DisableOneShot
* @details       Disable one shot mode
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_DisableOneShot(TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((Ch >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_ERR, &Ret);

    TT_ParaCheck((Channel_active == 0x0UL), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {

        volatile TT_GPDMA0_ChannelConfig_Type * TT_CONST dma_ch = Dma_Hw_PriChannel(Ch);

        if (Channel_info[Ch/8][Ch%8].DmaMode == DMA_ONESHOT_MODE)
        {
            dma_ch->MODE_CLR = (uint32)TT_DMA_C_MODE_CLR_ONE_MODE_CNT_CLR_Msk;
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}

/**
* @brief         Dma_Hw_ChannelEnable
* @details       Enable GPDMA channel
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_ChannelEnable (TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 ChActive = 0;
    TT_ParaCheck((Ch >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret && \
       (Channel_info[Ch/8][Ch%8].DmaMode == DMA_ONESHOT_MODE || \
        Channel_info[Ch/8][Ch%8].DmaMode == DMA_CONTINUOUS_MODE))
    {
        Dma_Hw_PriChannel(Ch)->CONFIG |= (uint32)TT_DMA_CONFIG_E_Msk;
        ChActive = Dma_Hw_SetChActiveFlag (Ch);
        TT_ParaCheck((ChActive == 1),TT_RET_PARAM_CHANNEL_ERR,&Ret);
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}

/**
* @brief         Dma_Hw_ChannelDisable
* @details       Disable GPDMA channel
* @param[in]     Ch - Dma channel id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_ChannelDisable (TT_CONST uint32 Ch)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((Ch >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_ERR, &Ret);

    TT_ParaCheck((Channel_active == 0x0UL), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_02();
#endif
        Dma_Hw_PriChannel(Ch)->CONFIG &= ~(uint32)TT_DMA_CONFIG_E_Msk;
#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_02();
#endif
        Dma_Hw_ClearChActiveFlag(Ch);
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}

/**
* @brief         Dma_Hw_ChannelGetCount
* @details       Get number of transferred data
* @param[in]     Ch - Dma channel id
* @param[out]    Count - Number of transferred data
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_ChannelGetCount (TT_CONST uint32 Ch, uint32 *Count)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((Ch >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_ERR, &Ret);

    TT_ParaCheck((NULL_PTR == Count), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        *Count = (uint32)((Channel_info[Ch/8][Ch%8].Cnt - (Dma_Hw_PriChannel(Ch)->CONTROL & TT_DMA_CCONTROL_TRANSFERSIZE_Msk)));
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}

/**
* @brief         Dma_Hw_ChannelGetStatus
* @details       Get GPDMA active channel
* @param[in]     Ch - Dma channel id
* @param[out]    Busy - Dma channel status
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_ChannelGetStatus(TT_CONST uint32 Ch, uint32 *Busy)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    volatile TT_GPDMA0_ChannelConfig_Type * dma_ch = NULL_PTR;

    TT_ParaCheck((Ch >= DMA_NUMBER_OF_CHANNELS), TT_RET_PARAM_ERR, &Ret);

    TT_ParaCheck((NULL_PTR == Busy), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        dma_ch = Dma_Hw_PriChannel(Ch);

        *Busy  = (uint32)((dma_ch->ONEMODE_EN & TT_DMA_C_CH_BUSY_Msk) >> 0x10UL);
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}

/**
* @brief         Dma_Hw_Softwaretrigger
* @details       Provide a software trigger request for Dma channel
* @param[in]     DmaChannelCfg - config data
* @param[in]     BReq - Software trigger request group id
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Dma_Hw_Softwaretrigger(TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg, TT_CONST uint32 BReq)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 instance = 0;
    uint32 Ch = 0;
    uint32 Burst_Breq = BReq;

    TT_ParaCheck((NULL_PTR == DmaChannelCfg), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    TT_ParaCheck((Burst_Breq >= 64), TT_RET_PARAM_ERR, &Ret);
    if (TT_RET_SUCCESS == Ret)
    {
        Burst_Breq = (uint32)Burst_Breq % 16;
        Burst_Breq = (uint32)((0x1UL) << Burst_Breq);
        Ch = DmaChannelCfg->DmaChannelId;
        instance = (uint8)(Ch >> 3);
        switch(instance)
        {
            case 0:
                TT_DMA0->SOFTBREQ = Burst_Breq;
                break;
            case 1:
                TT_DMA1->SOFTBREQ = Burst_Breq;
                break;
            case 2:
                TT_DMA2->SOFTBREQ = Burst_Breq;
                break;
            default:
                TT_DMA3->SOFTBREQ = Burst_Breq;
                break;
        }    
    }
    else
    {
        /*do nothing*/
    }

    return Ret;
}
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

#define DMA_START_SEC_CODE_FAST
#include "Dma_MemMap.h"
/**
* @brief        Dma_Hw_PriCombineIrqHandler
* @details      DMA combine interrupt handler
* @param[in]    gpdma_n - Dma unit id
* @param[in]    base_ch - Dma unit id
* @return       None
* @retval
* @pre
*/
static void Dma_Hw_PriCombineIrqHandler (Dma_RegType* Gpdma_n, TT_CONST uint32 Base_Ch)
{
    uint32 Ch = 0U;
    uint32 size = 0U;
    uint32 info_ch = 0U; 
    uint32 cnt_temp = 0U; 
    uint32 SrcAddr = 0U;
    uint32 DestAddr = 0U;

    volatile TT_GPDMA0_ChannelConfig_Type * dma_ch;

    for (Ch = 0; Ch < DMA_NUMBER_OF_CHANNEL; Ch++)
    {
        info_ch = Ch + Base_Ch;
        dma_ch = Dma_Hw_PriChannel(info_ch);
        /* Terminal count request interrupt */
        if ((Gpdma_n->INTTCSTAT & (1UL << Ch)) != 0 && (Gpdma_n->INTSTAT & (1UL << Ch)) != 0)
        {
            /* Clear interrupt flag */
            Gpdma_n->INTTCCLEAR = (uint32)(1UL << Ch);
            cnt_temp = Channel_info[info_ch/8][info_ch%8].Cnt;
            if (cnt_temp != Channel_info[info_ch/8][info_ch%8].Size)
            {
                /* Data waiting to transfer    */
                size = Channel_info[info_ch/8][info_ch%8].Size - cnt_temp;
                /* Max DMA transfer number 4096*/
                if (size > 0xFFFU)
                {
                    size = 0xFFFU;
                }
                else
                {
                    /*do nothing*/
                }

                Channel_info[info_ch/8][info_ch%8].Cnt = cnt_temp + size;

                SrcAddr = Channel_info[info_ch/8][info_ch%8].SrcAddr;
                DestAddr = Channel_info[info_ch/8][info_ch%8].DestAddr;
                (void)Dma_Hw_PriSetControl(NULL_PTR,size,SrcAddr,DestAddr,info_ch);

                /* Enable DMA Channel */
                dma_ch->CONFIG |= (uint32)TT_DMA_CCONFIG_E_Msk;
            }
            else
            {
                if (TRUE == Channel_info[info_ch/8][info_ch%8].LliMode)
                {
                    Channel_info[info_ch/8][info_ch%8].LliMode = FALSE;
                }

                /* Clear Channel active flag */
                Dma_Hw_ClearChActiveFlag (info_ch);
                /* Signal Event */
                if (Channel_info[info_ch/8][info_ch%8].cb_event != NULL)
                {
                    Channel_info[info_ch/8][info_ch%8].cb_event(DMA_EVENT_TERMINAL_COUNT_REQUEST);
                }
                else
                {
                    /*do nothing*/
                }
            }
        }
        else
        {
            /* DMA error interrupt */
            if ((Gpdma_n->INTERRSTAT & (1UL << Ch)) != 0)
            {
                dma_ch->CONFIG   = 0U;
                dma_ch->CONTROL  = 0U;
                dma_ch->LLI      = 0U;
                dma_ch->DESTADDR = 0U;
                dma_ch->SRCADDR  = 0U;
                /* Clear Channel active flag */
                Dma_Hw_ClearChActiveFlag (info_ch);

                /* Clear interrupt flag */
                Gpdma_n->INTERRCLR = (uint32)(1UL << Ch);

                /* Signal Event */
                if (Channel_info[info_ch/8][info_ch%8].cb_event != NULL)
                {
                    Channel_info[info_ch/8][info_ch%8].cb_event(DMA_EVENT_ERROR);
                }
                else
                {
                    /*do nothing*/
                }
            }
            else
            {
                /*do nothing*/
            }
        }
    }
}

/**
*@brief       void GPDMA0_COMBINE_IRQHandler (void)
*@brief       Dmac0 interrupt handler
*@param[in]   none
*@returns     none
*/
ISR(GPDMA0_COMBINE_IRQHandler)
{
    Dma_Hw_PriCombineIrqHandler (g_gpdmaBase[0], 0) ;
}

/**
*@fn          void GPDMA1_COMBINE_IRQHandler (void)
*@brief       Dmac1 interrupt handler
*@param[in]   none
*@returns     none
*/
ISR(GPDMA1_COMBINE_IRQHandler)
{
    Dma_Hw_PriCombineIrqHandler (g_gpdmaBase[1], 8) ;
}

/**
*@fn          void GPDMA2_COMBINE_IRQHandler (void)
*@brief       Dmac2 interrupt handler
*@param[in]   none
*@returns     none
*/
ISR(GPDMA2_COMBINE_IRQHandler)
{
    Dma_Hw_PriCombineIrqHandler (g_gpdmaBase[2], 16) ;
}

/**
*@fn          void GPDMA3_COMBINE_IRQHandler (void)
*@brief       Dmac3 interrupt handler
*@param[in]   none
*@returns     none
*/
ISR(GPDMA3_COMBINE_IRQHandler)
{
    Dma_Hw_PriCombineIrqHandler (g_gpdmaBase[3], 24) ;
}
/******************************************************************************
*                            Private Functions
******************************************************************************/
/**
* @brief         Dma_Hw_SetChActiveFlag.
* @details       Set channel active flag
* @param[in]     Ch - Dma channel id
* @param[out]    None
* @return        0 - Funcation success
*                1 - Channel already active
*/
LOCAL_INLINE uint32 Dma_Hw_SetChActiveFlag (uint32 Ch)
{
    uint32 Ret = 0;
#ifndef _VCAST_MINGW_C
    uint32 val = 0;
    do
    {
        val = TT_LDREX (&Channel_active);
        if ((val & (1UL << Ch)) != 0)
        {
            TT_CLREX ();
            Ret = 1;
            break;
        }
        else
        {
            /*do nothing*/
        }
    } while ((TT_STREX (val | (uint32)(1UL << Ch), &Channel_active)) == 1);
#else
    Channel_active |= 1UL << Ch;
#endif
    return Ret;
}

/**
* @brief         Dma_Hw_ClearChActiveFlag
* @details       Protected clear of channel active flag.
* @param[in]     Ch - Dma channel id
* @param[out]    None
* @return        None
*/
LOCAL_INLINE void Dma_Hw_ClearChActiveFlag (uint32 Ch)
{
#ifndef _VCAST_MINGW_C
    uint32 a = (uint32)(TT_LDREX(&Channel_active) & ~(1UL << Ch));
    uint32 b = (TT_STREX(a, &Channel_active));
    while(b == 1)
    {
        a = (uint32)(TT_LDREX(&Channel_active) & ~(1UL << Ch));
        b = (TT_STREX(a, &Channel_active));
    }
#else
    Channel_active &= ~(1UL << Ch);
#endif
}

/**
* @brief        Dma_Hw_PriChannel
* @details      Get Dma Channel Base Address 
* @param[in]    Ch - Dma Channel Index
* @return       TT_GPDMA0_ChannelConfig_Type *
* @retval       
* @pre          
*/
static volatile TT_GPDMA0_ChannelConfig_Type * Dma_Hw_PriChannel(uint32 Ch)
{
    return ((volatile TT_GPDMA0_ChannelConfig_Type *)(&(g_gpdmaBase[(Ch)/8]->ChannelConfig[(Ch)%8])));
}

/**
* @brief        Dma_Hw_PriChConfigSrcPe
* @details      Set Dma Channel Source Peripheral Id 
* @param[in]    Ch - Dma Channel Index
* @return       uint32
* @retval       
* @pre          
*/
LOCAL_INLINE uint32 Dma_Hw_PriChConfigSrcPe(uint32 Ch)
{
    return ((uint32)(((Ch)&0xFUL) << TT_DMA_CCONFIG_SRCPERIPHERAL_Pos) & (uint32)TT_DMA_CCONFIG_SRCPERIPHERAL_Msk);
}

/**
* @brief        Dma_Hw_PriChConfigDestPe
* @details      Set Dma Channel Dest Peripheral Id 
* @param[in]    Ch - Dma Channel Index
* @return       uint32
* @retval       
* @pre          
*/
LOCAL_INLINE uint32 Dma_Hw_PriChConfigDestPe(uint32 Ch)
{     
    return ((uint32)(((Ch)&0xFUL) << TT_DMA_CCONFIG_DESTPERIPHERAL_Pos) & (uint32)TT_DMA_CCONFIG_DESTPERIPHERAL_Msk);
}

/**
* @brief        Dma_Hw_PriChConfigFlow
* @details      Set Dma Channel Flowcntrl 
* @param[in]    Ch - Dma Channel Index
* @return       uint32
* @retval       
* @pre          
*/
LOCAL_INLINE uint32 Dma_Hw_PriChConfigFlow(uint32 Ch)
{
    return (((Ch)  << TT_DMA_CCONFIG_FLOWCNTRL_Pos) & (uint32)TT_DMA_CCONFIG_FLOWCNTRL_Msk);
}

/**
* @brief        Dma_Hw_PriChControlTransferSize
* @details      Set Dma Channel Transfersize 
* @param[in]    Ch - Dma Channel Index
* @return       uint32
* @retval       
* @pre          
*/
LOCAL_INLINE uint32 Dma_Hw_PriChControlTransferSize(uint32 Size)
{
    return (((Size)  << TT_DMA_CCONTROL_TRANSFERSIZE_Pos) & (uint32)TT_DMA_CCONTROL_TRANSFERSIZE_Msk);
}

/**
* @brief        Dma_Hw_Inner_Initialize.
* @details      Initialize Dma unit
* @param[in]    instance - Dma unit id
* @return       None
* @retval
* @pre
*/
static void Dma_Hw_PriInit (TT_CONST uint32 Instance)
{
    uint32 ch_num = 0;
    /* Reset DMA */
    g_gpdmaBase[Instance]->CONFIG = 0U;

    for(uint8 i = 0; i < 8; i++)
    {
        g_gpdmaBase[Instance]->ChannelConfig[i].CONFIG = 0U;
        g_gpdmaBase[Instance]->ChannelConfig[i].CONTROL = 0U;
    }

    /* Reset all DMA channels */
    for (ch_num = 0U; ch_num < DMA_NUMBER_OF_CHANNEL; ch_num++)
    {
        Channel_info[Instance][ch_num].SrcAddr  = 0U;
        Channel_info[Instance][ch_num].DestAddr = 0U;
        Channel_info[Instance][ch_num].Size     = 0U;
        Channel_info[Instance][ch_num].Cnt      = 0U;
        Channel_info[Instance][ch_num].LliMode  = FALSE;
    }
    /* Clear all DMA interrupt flags */
    g_gpdmaBase[Instance]->INTTCCLEAR = 0xFF;
    g_gpdmaBase[Instance]->INTERRCLR = 0xFF;
    /* Disable synchronization logic */
    g_gpdmaBase[Instance]->SYNC = 0xFFFF;
}

/**
* @brief        Dma_Hw_PriAddressValid.
* @details      Check whether the IP address is within the configured range.
* @param[in]    DmaChannelCfg - Config data
* @param[in]    SrcAddr - Source address
* @param[in]    DestAddr - Destination address
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
LOCAL_INLINE TT_RetType Dma_Hw_PriAddressValid (TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg,
                                                TT_CONST uint32 SrcAddr,
                                                TT_CONST uint32 DestAddr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    if ( (DmaChannelCfg ->DmaDestDataWidth == DMA_16_BIT_DATA) || (DmaChannelCfg ->DmaSourceDataWidth == DMA_16_BIT_DATA))
    {
        if ((SrcAddr % 2 == 0) && (DestAddr % 2 == 0))
        {
            Ret = TT_RET_SUCCESS;
        }
        else
        {
            Ret = TT_RET_PARAM_ADDR_ERR;
        }
    }
    else
    {
        /*do nothing*/
    }

    if ( (DmaChannelCfg ->DmaDestDataWidth == DMA_32_BIT_DATA) || (DmaChannelCfg ->DmaSourceDataWidth == DMA_32_BIT_DATA))
    {
        if ((SrcAddr % 4 == 0) && (DestAddr % 4 == 0))
        {
            Ret = TT_RET_SUCCESS;
        }
        else
        {
            Ret = TT_RET_PARAM_ADDR_ERR;
        }
    }
    else
    {
        /*do nothing*/
    }

    if ( (DmaChannelCfg ->DmaDestDataWidth == DMA_64_BIT_DATA) || (DmaChannelCfg ->DmaSourceDataWidth == DMA_64_BIT_DATA))
    {
        if ((SrcAddr % 8 == 0) && (DestAddr % 8 == 0))
        {
            Ret = TT_RET_SUCCESS;
        }
        else
        {
            Ret = TT_RET_PARAM_ADDR_ERR;
        }
    }
    else
    {
        /*do nothing*/
    }
    return Ret;
}
/**
* @brief        Dma_Hw_PriSetDmaMode.
* @details      Set dma single/continuous mode.
* @param[in]    DmaChannelCfg - Config data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
static TT_RetType Dma_Hw_PriSetDmaMode(TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    volatile TT_GPDMA0_ChannelConfig_Type * dma_ch = NULL_PTR;
    TT_CONST uint32 channel = DmaChannelCfg->DmaChannelId;

    /*Get the base address of the dma register*/
    dma_ch = Dma_Hw_PriChannel(channel);

    /*Does not coexist with linked list mode*/
    if (NULL_PTR == DmaChannelCfg->DmaLinkHead)
    {
        if ((DmaChannelCfg->DmaOneshotMode != 0) && (DmaChannelCfg->DmaContinuousMode == FALSE))
        {
            Channel_info[channel/8][channel%8].DmaMode = DMA_ONESHOT_MODE;
            dma_ch->MODE_EN = DmaChannelCfg->DmaOneshotMode;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            TT_ParaCheck((dma_ch->MODE_EN != DmaChannelCfg->DmaOneshotMode), TT_RET_OPT_REG_ERR, &Ret);
#endif
        }
        else if ((DmaChannelCfg->DmaOneshotMode == 0) && (DmaChannelCfg->DmaContinuousMode == TRUE))
        {
            Channel_info[channel/8][channel%8].DmaMode = DMA_CONTINUOUS_MODE;
            dma_ch->MODE_EN = (uint32)TT_DMA_CMODE_EN_CONTINUE_MODE_EN_TEMP_Msk;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            TT_ParaCheck(dma_ch->MODE_EN != TT_DMA_CMODE_EN_CONTINUE_MODE_EN_TEMP_Msk, TT_RET_OPT_REG_ERR, &Ret);
#endif
        }
        else
        {
            dma_ch->MODE_EN = DMA_NORMAL_MODE;
            Channel_info[channel/8][channel%8].DmaMode = DMA_NORMAL_MODE;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            TT_ParaCheck(dma_ch->MODE_EN != DMA_NORMAL_MODE, TT_RET_OPT_REG_ERR, &Ret);
#endif
        }
    }
    else
    {
        Channel_info[channel/8][channel%8].DmaMode = DMA_NORMAL_MODE;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck(dma_ch->MODE_EN != DMA_NORMAL_MODE, TT_RET_OPT_REG_ERR, &Ret);
#endif
    }
    return Ret;
}
/**
* @brief         Dma_Hw_PriSetControl.
* @details       Configure the control register.
* @param[in]     DmaChannelCfg - Config data
* @param[in]     DmaTranferSize - transfer size
* @param[in]     DmaSourceAddress - Source address
* @param[in]     DmaDestAddress - Destination address
* @param[in]     DmaChannel - Dma Channel
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Dma_Hw_PriSetControl(TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg,
                                       TT_CONST uint32          DmaTranferSize,
                                       TT_CONST uint32          DmaSourceAddress,
                                       TT_CONST uint32          DmaDestAddress,
                                       TT_CONST uint32          DmaChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    volatile TT_GPDMA0_ChannelConfig_Type * dma_ch = NULL_PTR;
    uint32 control = 0;
    uint32 DmaSAddress = DmaSourceAddress;
    uint32 DmaDAddress = DmaDestAddress;
    uint32 size = DmaTranferSize;
    
    if (DmaChannelCfg != NULL_PTR)
    {
        uint32 Allinone = (uint32)DmaChannelCfg->DmaAllInOne;
        TT_CONST uint32 channel = DmaChannelCfg->DmaChannelId;

        /*Get the base address of the dma register*/
        dma_ch = Dma_Hw_PriChannel(channel);

        /* Reset DMA Channel configuration */
        dma_ch->CONTROL = 0U;

        /*Check link list node,set lli register*/
        if ((NULL_PTR != DmaChannelCfg->DmaLinkHead) &&
        (DmaChannelCfg->DmaOneshotMode == 0)     &&
        (DmaChannelCfg->DmaContinuousMode == FALSE))
        {
            TT_ParaCheck((NULL_PTR == DmaChannelCfg->DmaLinkHead->DmaNode), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
            dma_ch->LLI = (uint32)DmaChannelCfg->DmaLinkHead->DmaLLI;
            Channel_info[channel/8][channel%8].LliMode = TRUE;
        }
        else
        {
            Channel_info[channel/8][channel%8].LliMode = FALSE;
            /*Open interrupt without using linked list mode*/
            control = (uint32)TT_DMA_CCONTROL_I_Msk;
        }

        Allinone = (size == 1?0:Allinone);

        /*Set control register*/
        control |= (((size)  << TT_DMA_CCONTROL_TRANSFERSIZE_Pos) & (uint32)TT_DMA_CCONTROL_TRANSFERSIZE_Msk)                       |
                ((((uint32)DmaChannelCfg->DmaSourceBurstSize)  << TT_DMA_CCONTROL_SBSIZE_Pos) & (uint32)TT_DMA_CCONTROL_SBSIZE_Msk) |
                ((((uint32)DmaChannelCfg->DmaDestBurstSize)  << TT_DMA_CCONTROL_DBSIZE_Pos) & (uint32)TT_DMA_CCONTROL_DBSIZE_Msk)   |
                ((((uint32)DmaChannelCfg->DmaSourceDataWidth)  << TT_DMA_CCONTROL_SWIDTH_Pos) & (uint32)TT_DMA_CCONTROL_SWIDTH_Msk) |
                ((((uint32)DmaChannelCfg->DmaIntTtrg)  << TT_DMA_CCONTROL_INT_TTRG_Pos) & (uint32)TT_DMA_CCONTROL_INT_TTRG_Msk)     |
                ((((uint32)DmaChannelCfg->DmaDestDataWidth)  << TT_DMA_CCONTROL_DWIDTH_Pos) & (uint32)TT_DMA_CCONTROL_DWIDTH_Msk)   |
                ((Allinone  << TT_DMA_CCONTROL_ALLINONE_Pos) & (uint32)TT_DMA_CCONTROL_ALLINONE_Msk)    |
                ((((uint32)DmaChannelCfg->DmaSMaster)  << TT_DMA_CCONTROL_S_Pos) & (uint32)TT_DMA_CCONTROL_S_Msk)                   |
                ((((uint32)DmaChannelCfg->DmaDMaster)  << TT_DMA_CCONTROL_D_Pos) & (uint32)TT_DMA_CCONTROL_D_Msk)                   |
                ((((uint32)DmaChannelCfg->DmaSourceIncrease)  << TT_DMA_CCONTROL_SI_Pos) & (uint32)TT_DMA_CCONTROL_SI_Msk)          |
                ((((uint32)DmaChannelCfg->DmaDestIncrease)  << TT_DMA_CCONTROL_DI_Pos) & (uint32)TT_DMA_CCONTROL_DI_Msk)            |
                ((((uint32)DmaChannelCfg->DmaAccessMode)  << TT_DMA_CCONTROL_PROT1_Pos) & (uint32)TT_DMA_CCONTROL_PROT1_Msk)        |
                ((((uint32)DmaChannelCfg->DmaIrqEn)  << TT_DMA_CCONTROL_I_Pos) & (uint32)TT_DMA_CCONTROL_I_Msk);

        /* Set Source and destination address */
        dma_ch->SRCADDR  = DmaSourceAddress;
        dma_ch->DESTADDR = DmaDestAddress;
        /*Determine whether the source address increases automatically*/
        if ((control & TT_DMA_CCONTROL_SI_Msk) != 0)
        {
            /* Source address increment */
            DmaSAddress = DmaSourceAddress + (size << ((control & TT_DMA_CCONTROL_SWIDTH_Msk) >> TT_DMA_CCONTROL_SWIDTH_Pos));
        }
        else
        {
            /*do nothing*/
        }
        /*Determine whether the dest address increases automatically*/
        if ((control & TT_DMA_CCONTROL_DI_Msk) != 0)
        {
            /* Destination address increment */
            DmaDAddress = DmaDestAddress + (size << ((control & TT_DMA_CCONTROL_SWIDTH_Msk) >> TT_DMA_CCONTROL_SWIDTH_Pos));
        }
        else
        {
            /*do nothing*/
        }
        /* Save channel information */
        Channel_info[channel/8][channel%8].SrcAddr  = DmaSAddress;
        Channel_info[channel/8][channel%8].DestAddr = DmaDAddress;
        Channel_info[channel/8][channel%8].Cnt      = size;
#ifdef USING_OS_AUTOSAROS
    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_04();
#endif
        /*write to register*/
        dma_ch->CONTROL = control;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck((dma_ch->CONTROL != (control & 0xFFFFF000U) || \
                (dma_ch->SRCADDR != DmaSourceAddress) || \
                (dma_ch->DESTADDR != DmaDestAddress)), TT_RET_OPT_REG_ERR, &Ret);
#endif
        if(Ret == TT_RET_SUCCESS)
        {

            Ret = Dma_Hw_PriSetDmaMode(DmaChannelCfg);
        }
        else
        {
            /*do nothing*/
        }
#ifdef USING_OS_AUTOSAROS
    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_04();
#endif
    }
    else
    {
        dma_ch = Dma_Hw_PriChannel(DmaChannel);

        if ((dma_ch->CONTROL & TT_DMA_CCONTROL_SI_Msk) != 0)
        {
            /* Source address increment */
            DmaSAddress = DmaSourceAddress + (size << ((dma_ch->CONTROL & TT_DMA_CCONTROL_SWIDTH_Msk) >> TT_DMA_CCONTROL_SWIDTH_Pos));
        }
        else
        {
            /*do nothing*/
        }
        /*Determine whether the dest address increases automatically*/
        if ((dma_ch->CONTROL & TT_DMA_CCONTROL_DI_Msk) != 0)
        {
            /* Destination address increment */
            DmaDAddress = DmaDestAddress + (size << ((dma_ch->CONTROL & TT_DMA_CCONTROL_SWIDTH_Msk) >> TT_DMA_CCONTROL_SWIDTH_Pos));
        }
        else
        {
            /*do nothing*/
        }
        /* Save channel information */
        Channel_info[DmaChannel/8][DmaChannel%8].SrcAddr  = DmaSAddress;
        Channel_info[DmaChannel/8][DmaChannel%8].DestAddr = DmaDAddress;
        /* Set Source and destination address */
        dma_ch->SRCADDR  = DmaSourceAddress;
        dma_ch->DESTADDR = DmaDestAddress;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck(((dma_ch->SRCADDR != DmaSourceAddress) || (dma_ch->DESTADDR != DmaDestAddress)), TT_RET_OPT_REG_ERR, &Ret);
        if(Ret == TT_RET_SUCCESS)
        {
#endif
        /* Set transfer size */
        dma_ch->CONTROL &= (uint32)(~TT_DMA_CCONTROL_TRANSFERSIZE_Msk);
        dma_ch->CONTROL |= Dma_Hw_PriChControlTransferSize(size);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        }
#endif
    }

    return Ret;
}
/**
* @brief         Dma_Hw_PriSetConfig.
* @details       Configure the config register.
* @param[in]     DmaChannelCfg - Config data
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Dma_Hw_PriSetConfig(TT_CONST Dma_Hw_ChannelConfigType* DmaChannelCfg)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    volatile TT_GPDMA0_ChannelConfig_Type * dma_ch = NULL_PTR;
    uint32 config = 0;
    TT_CONST uint32 channel = DmaChannelCfg->DmaChannelId;
    uint32 i = 0;
    /*Get the base address of the dma register*/
    dma_ch = Dma_Hw_PriChannel(channel);

    /* Reset DMA Channel configuration */
    dma_ch->CONFIG  = 0U;

    /*Set config register*/
    config = (uint32)(TT_DMA_CCONFIG_E_Msk |
            Dma_Hw_PriChConfigSrcPe((uint32)DmaChannelCfg->DmaSrcPeripheralId)   |
            Dma_Hw_PriChConfigDestPe((uint32)DmaChannelCfg->DmaDestPeripheralId) |
            Dma_Hw_PriChConfigFlow((uint32)DmaChannelCfg->DmaFlowControl)) ;

    /* Set Channel Irq*/
    if(DmaChannelCfg->DmaIrqEn != TRUE && DmaChannelCfg->DmaLinkHead != NULL_PTR)
    {
        for(i = 0; i < DmaChannelCfg->DmaLinkHead->DmaNodeCount; i++)
        {
            if(DmaChannelCfg->DmaLinkHead->DmaNode[i].DmaLliIrqEn == TRUE)
            {
                config |=  (uint32)(TT_DMA_CCONFIG_ITC_Msk | TT_DMA_CCONFIG_IE_Msk);
                break;
            }
            else
            {
                /*do nothing*/
            }
        }
    }
    else
    {
        config |=  (uint32)(TT_DMA_CCONFIG_ITC_Msk | TT_DMA_CCONFIG_IE_Msk);
    }

    dma_ch->CONFIG  = config;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        TT_ParaCheck((dma_ch->CONFIG & (uint32)0xFFFF) != config, TT_RET_OPT_REG_ERR, &Ret);
#endif
    return Ret;
}

#define DMA_STOP_SEC_CODE_FAST
#include "Dma_MemMap.h"

#ifdef __cplusplus
}
#endif
