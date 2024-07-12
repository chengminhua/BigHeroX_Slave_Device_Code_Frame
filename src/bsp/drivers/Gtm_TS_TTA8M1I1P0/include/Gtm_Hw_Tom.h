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
**  FILENAME     : Gtm_Hw_Tom.h                                               **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Gtm Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef GTM_HW_TOM_H
#define GTM_HW_TOM_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Tom_Types.h"


/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_TOM_VENDOR_ID_H                      1541
#define GTM_HW_TOM_MODULE_ID_H                      221
#define GTM_HW_TOM_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_TOM_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_TOM_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_TOM_SW_MAJOR_VERSION_H               1
#define GTM_HW_TOM_SW_MINOR_VERSION_H               1
#define GTM_HW_TOM_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Tom.h Gtm_Hw_Tom_Types.h file version check */
#if (GTM_HW_TOM_VENDOR_ID_H != GTM_HW_TOM_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Tom.h and Gtm_Hw_Tom_Types.h have different vendor ids"
#endif

#if (GTM_HW_TOM_MODULE_ID_H != GTM_HW_TOM_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Tom.h and Gtm_Hw_Tom_Types.h have different module ids"
#endif

#if ((GTM_HW_TOM_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_TOM_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_TOM_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TOM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tom.h and Gtm_Hw_Tom_Types.h are different"
#endif

#if ((GTM_HW_TOM_SW_MAJOR_VERSION_H != GTM_HW_TOM_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_TOM_SW_MINOR_VERSION_H != GTM_HW_TOM_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_TOM_SW_PATCH_VERSION_H != GTM_HW_TOM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tom.h and Gtm_Hw_Tom_Types.h are different"
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

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                              Public Function Declaration
******************************************************************************/
/**
* @brief        Gtm_Hw_Tom_PriSetTomHostTrigger
* @details      Set host trigger.
* @param[in]    TomNum The TOM instance id
* @param[in]    TgcNum Tgc number
* @param[out]   None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetTomHostTrigger(uint8 TomNum,uint8 TgcNum)
{
    Tom_PubReg[TomNum]->TGC[TgcNum].GLB_CTRL.B.HOST_TRIG = 1U;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCn0
* @details      Set cn0 value.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    Cn0Value cn0 value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCn0(uint8 TomNum, uint8 ChNum, uint16 Cn0Value)
{
    Tom_PubReg[TomNum]->CH[ChNum].CN0.R = Cn0Value;
}

/**
* @brief        Gtm_Hw_Tom_PriGetCn0
* @details      Get cn0 value.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[out]   None
* @return       uint16
* @retval       cn0 value
* @pre
*/
LOCAL_INLINE uint16 Gtm_Hw_Tom_PriGetCn0(uint8 TomNum, uint8 ChNum)
{
    return Tom_PubReg[TomNum]->CH[ChNum].CN0.R;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCm0
* @details      Set tom counter cm0.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    cm0Value cm0 value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCm0(uint8 TomNum, uint8 ChNum, uint16 Cm0Value)
{
    Tom_PubReg[TomNum]->CH[ChNum].CM0.R = Cm0Value;
}

/**
* @brief        Gtm_Hw_Tom_PriGetCm0
* @details      Get tom counter cm0.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[out]   None
* @return       uint16
* @retval       cm0 value
* @pre
*/
LOCAL_INLINE uint16 Gtm_Hw_Tom_PriGetCm0(uint8 TomNum, uint8 ChNum)
{
    return Tom_PubReg[TomNum]->CH[ChNum].CM0.R;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCm1
* @details      Set tom counter cm1.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    cm1Value cm1 value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCm1(uint8 TomNum, uint8 ChNum, uint16 Cm1Value)
{
    Tom_PubReg[TomNum]->CH[ChNum].CM1.R = Cm1Value;
}

/**
* @brief        Gtm_Hw_Tom_PriGetCm1
* @details      Get tom counter cm1.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[out]   None
* @return       uint16
* @retval       cm1 value
* @pre
*/
LOCAL_INLINE uint16 Gtm_Hw_Tom_PriGetCm1(uint8 TomNum, uint8 ChNum)
{
    return Tom_PubReg[TomNum]->CH[ChNum].CM1.R;
}

/**
* @brief        Gtm_Hw_Tom_PriSetSr0
* @details      Set tom counter Sr0.
* @param[in]    TomNum   The TOM instance id
* @param[in]    ChNum    Tom channel number
* @param[in]    sr0Value sr0 value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetSr0(uint8 TomNum,uint8 ChNum,uint16 Sr0Value)
{
    Tom_PubReg[TomNum]->CH[ChNum].SR0.R = Sr0Value;
}

/**
* @brief        Gtm_Hw_Tom_PriGetSr0
* @details      Get tom counter Sr0.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[out]   None
* @return       uint16
* @retval       Sr0 value
* @pre
*/
LOCAL_INLINE uint16 Gtm_Hw_Tom_PriGetSr0(uint8 TomNum,uint8 ChNum)
{
    return Tom_PubReg[TomNum]->CH[ChNum].SR0.R;
}

/**
* @brief        Gtm_Hw_Tom_PriSetSr1
* @details      Set tom counter Sr1.
* @param[in]    TomNum   The TOM instance id
* @param[in]    ChNum    Tom channel number
* @param[in]    sr1Value sr1 value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetSr1(uint8 TomNum,uint8 ChNum,uint16 Sr1Value)
{
    Tom_PubReg[TomNum]->CH[ChNum].SR1.R = Sr1Value;
}

/**
* @brief        Gtm_Hw_Tom_PriGetSr1
* @details      Get tom counter Sr1.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[out]   None
* @return       uint16
* @retval       Sr1 value
* @pre
*/
LOCAL_INLINE uint16 Gtm_Hw_Tom_PriGetSr1(uint8 TomNum,uint8 ChNum)
{
    return Tom_PubReg[TomNum]->CH[ChNum].SR1.R;
}

/**
* @brief        Gtm_Hw_Tom_PriEnableChannel
* @details      Enable tom channel.
* @param[in]    TomNum   The TOM instance id
* @param[in]    ChNum    Tom channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriEnableChannel(uint8 TomNum, uint8 ChNum)
{
    Tom_PubReg[TomNum]->TGC[ChNum >> 3].ENDIS_CTRL.R |= 1U << ((ChNum & 0x7) << 1U);
    Tom_PubReg[TomNum]->TGC[ChNum >> 3].ENDIS_STAT.R |= 1U << ((ChNum & 0x7) << 1U);
}

/**
* @brief        Gtm_Hw_Tom_PriDisableChannel
* @details      Disable tom channel.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriDisableChannel (uint8 TomNum, uint8 ChNum)
{
    Tom_PubReg[TomNum]->TGC[ChNum >> 3].ENDIS_CTRL.R &= ~(1U << ((ChNum & 0x7) << 1U));
    Tom_PubReg[TomNum]->TGC[ChNum >> 3].ENDIS_STAT.R &= ~(1U << ((ChNum & 0x7) << 1U));
}

/**
* @brief        Gtm_Hw_Tom_PriGetTomOutputState
* @details      Get channel level.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[out]   None
* @return       Tom_OutputLevelType
* @retval       channel level status
* @pre
*/
LOCAL_INLINE Tom_OutputLevelType Gtm_Hw_Tom_PriGetTomOutputState(uint8 TomNum,uint8 ChNum)
{
    return (Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_STAT.R & (1U << ((ChNum & 0x7) << 1U))) == 1U ? TOM_HIGH_LEVEL : TOM_LOW_LEVEL;
}

/**
* @brief        Gtm_Hw_Tom_PriSetOutSigLevel
* @details      Set channel level.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    GtmTomChannelOutputSignalLevel tom channel level
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetOutSigLevel(uint8 TomNum, uint8 ChNum, Tom_ChannelOutputSignalLevelType TomChannelOutputSignalLevel)
{
    Tom_PubReg[TomNum]->CH[ChNum].CTRL.B.SL = TomChannelOutputSignalLevel;
}

/**
* @brief        Gtm_Hw_Tom_PriSetOutShdSigLevel
* @details      Set channel shadow level.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    GtmTomChannelOutputSignalLevel tom channel level
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetOutShdSigLevel(uint8 TomNum, uint8 ChNum, Tom_ChannelOutputSignalLevelType TomChannelOutputSignalLevel)
{
    Tom_PubReg[TomNum]->CH[ChNum].CTRL_SR.B.SL = TomChannelOutputSignalLevel;
}

/**
* @brief        Gtm_Hw_Tom_PriSetOutputEnable
* @details      Enable tom output.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    immediate at or wait for host trigger
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetOutputEnable (uint8 TomNum, uint8 ChNum, boolean immediate)
{
    if(immediate)
    {
        Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_CTRL.R = (Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_CTRL.R & ~(0x3U << ((ChNum & 0x7U) << 1))) | (0x2U << ((ChNum & 0x7U) << 1U));
        Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_STAT.R = (Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_STAT.R & ~(0x3U << ((ChNum & 0x7U) << 1))) | (0x2U << ((ChNum & 0x7U) << 1U));
    }
    else
    {
        Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_CTRL.R = (Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_CTRL.R & ~(0x3U << ((ChNum & 0x7U) << 1))) | (0x2U << ((ChNum & 0x7U) << 1U));
    }

}

/**
* @brief        Gtm_Hw_Tom_PriSetOutputDisable
* @details      Disable tom output.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    immediate at or wait for host trigger
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetOutputDisable(uint8 TomNum, uint8 ChNum, boolean immediate)
{
    if(immediate)
    {
        Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_CTRL.R = (Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_CTRL.R & ~(0x3U << ((ChNum & 0x7U) << 1))) | (0x1U << ((ChNum & 0x7U) << 1U));
        Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_STAT.R = (Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_STAT.R & ~(0x3U << ((ChNum & 0x7U) << 1))) | (0x1U << ((ChNum & 0x7U) << 1U));
    }
    else
    {
        Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_CTRL.R = (Tom_PubReg[TomNum]->TGC[ChNum >> 3].OUTEN_CTRL.R & ~(0x3U << ((ChNum & 0x7U) << 1))) | (0x1U << ((ChNum & 0x7U) << 1U));
    }
}

/**
* @brief        Gtm_Hw_Tom_PriSetChannelEnable
* @details      Enable tom channel.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    immediate at or wait for host trigger
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetChannelEnable (uint8 TomNum, uint8 ChNum, boolean immediate)
{
    GTM_REG_READ_2_WRITE(Tom_PubReg[TomNum]->TGC[ChNum >> 3].ENDIS_CTRL.R, 0x2, 0x3, ((ChNum & 0x7U) << 1));

    if(immediate)
    {
        GTM_REG_READ_2_WRITE(Tom_PubReg[TomNum]->TGC[ChNum >> 3].ENDIS_STAT.R, 0x2, 0x3, ((ChNum & 0x7U) << 1));
    }
    else
    {
        /* do nothing */
    }
}

/**
* @brief        Gtm_Hw_Tom_PriSetChannelDisable
* @details      Disable tom channel.
* @param[in]    TomNum The TOM instance id
* @param[in]    ChNum tom channel number
* @param[in]    immediate at or wait for host trigger
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetChannelDisable (uint8 TomNum, uint8 ChNum, boolean immediate)
{
    GTM_REG_READ_2_WRITE(Tom_PubReg[TomNum]->TGC[ChNum >> 3].ENDIS_CTRL.R, 0x1, 0x3, ((ChNum & 0x7U) << 1));

    if(immediate)
    {
        GTM_REG_READ_2_WRITE(Tom_PubReg[TomNum]->TGC[ChNum >> 3].ENDIS_STAT.R, 0x1, 0x3, ((ChNum & 0x7U) << 1));
    }
    else
    {
        /* do nothing */
    }
}

/**
* @brief        Gtm_Hw_Tom_PriSetTgcUpdateEnable
* @details      Enable register update.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enbale enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetTgcUpdateEnable(uint8 TomNum,uint8 channel, boolean enbale)
{
    GTM_REG_READ_2_WRITE(Tom_PubReg[TomNum]->TGC[channel >> 3].GLB_CTRL.R,
                         TOM_GET_EN_CFG_VAL(enbale),
                         0x3, (((channel & 0x7U) << 1) + 16));
}

/**
* @brief        Gtm_Hw_Tom_PriSetForceUPEnable
* @details      Enable register fource update.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enbale enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetForceUPEnable(uint8 TomNum,uint8 channel, boolean enbale)
{
    GTM_REG_READ_2_WRITE(Tom_PubReg[TomNum]->TGC[channel >> 3].FUPD_CTRL.R,
                         TOM_GET_EN_CFG_VAL(enbale),
                         0x3, ((channel & 0x7U) << 1));
}

/**
* @brief        Gtm_Hw_Tom_PriRstCn0ForceUP
* @details      Cn0 reset behavior on forced update
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enbale enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriRstCn0ForceUP(uint8 TomNum,uint8 channel, boolean enbale)
{
    GTM_REG_READ_2_WRITE(Tom_PubReg[TomNum]->TGC[channel >> 3].FUPD_CTRL.R,
                         TOM_GET_EN_CFG_VAL(enbale),
                         0x3, (((channel & 0x7U) << 1) + 16));
}

/**
* @brief        Gtm_Hw_Tom_PriSetChannelClockSrc
* @details      Set channel clock source
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    clock select clock source 
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetChannelClockSrc(uint8 TomNum,uint8 channel, Tom_ChannelClockSelectType clock)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.CLK_SRC_SR = clock;
}

/**
* @brief        Gtm_Hw_Tom_PriSetChShadowClkSrc
* @details      Set channel shadow clock source
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    clock select clock source 
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetChShadowClkSrc(uint8 TomNum,uint8 channel, Tom_ChannelClockSelectType clock)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL_SR.B.CLK_SRC_SR = clock;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCn0ResetMode
* @details      Set cn0 reset mode
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    mode reset mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCn0ResetMode(uint8 TomNum,uint8 channel, Tom_ChannelCounterCn0ResetType mode)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.RST_CCU0 = mode;
}

/**
* @brief        Gtm_Hw_Tom_PriSetExtTrigCn0Reset
* @details      Set external trigger cn0 reset mode
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    mode reset mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetExtTrigCn0Reset(uint8 TomNum,uint8 channel, Tom_ChExtCounterCn0ResetType mode)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.EXT_TRIG = mode;
}

/**
* @brief        Gtm_Hw_Tom_PriSetTriggerOut
* @details      Set trigger out
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    mode trigger mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetTriggerOut(uint8 TomNum,uint8 channel, Tom_ChannelTriggerOutputType mode)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.TRIGOUT = mode;
}

/**
* @brief        Gtm_Hw_Tom_PriSetExtTriggerOut
* @details      Set external trigger out
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    mode trigger mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetExtTriggerOut(uint8 TomNum,uint8 channel, Tom_ChannelExtTriggerOutputType mode)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.EXTTRIGOUT = mode;
}

/**
* @brief        Gtm_Hw_Tom_PriSetOSMEnable
* @details      Enable one shot mod
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetOSMEnable(uint8 TomNum,uint8 channel, boolean enable)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.OSM = enable;
}

/**
* @brief        Gtm_Hw_Tom_PriSetOSMTrigEnable
* @details      One−shot pulse generation enabled by the selected trigger signal
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetOSMTrigEnable(uint8 TomNum,uint8 channel, boolean enable)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.OSM_TRIG = enable;
}

/**
* @brief        Gtm_Hw_Tom_PriSetUpdownMdoe
* @details      Set Updown counter mode.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    mode select updown mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetUpdownMdoe(uint8 TomNum,uint8 channel, uint8 mode)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.UDMODE = mode;
}

/**
* @brief        Gtm_Hw_Tom_PriSetSr0Trigger
* @details      Set sr0 use for trigger.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetSr0Trigger(uint8 TomNum,uint8 channel, boolean enable)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL.B.SR0_TRIG = enable;
}

/**
* @brief        Gtm_Hw_Tom_PriSetBitRev
* @details      Set bit reversing of output of counter TOM[i]_CH[x]_CN0.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetBitRev(uint8 TomNum, boolean enable)
{
#if(defined(TOM_0_CHANNEL_15))
    Tom_PubReg[TomNum]->CH[TOM_CH_15].CTRL.B.BITREV = enable;
#else
	(void)TomNum;
	(void)enable;
#endif
}

/**
* @brief        Gtm_Hw_Tom_PriSetCcu0Tc
* @details      Set cc0 match.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCcu0Tc(uint8 TomNum,uint8 channel, boolean enable)
{
    Tom_PubReg[TomNum]->CH[channel].IRQ_NOTIFY.B.CCU0TC = enable;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCcu1Tc
* @details      Set cc1 match.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCcu1Tc(uint8 TomNum,uint8 channel, boolean enable)
{
    Tom_PubReg[TomNum]->CH[channel].IRQ_NOTIFY.B.CCU1TC = enable;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCcu0IrqEn
* @details      Set cc0 match interupt.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCcu0IrqEn(uint8 TomNum,uint8 channel, boolean enable)
{
    Tom_PubReg[TomNum]->CH[channel].IRQ_EN.B.CCU0TC_IRQ_EN = enable;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCcu1IrqEn
* @details      Set cc1 match interupt.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCcu1IrqEn(uint8 TomNum,uint8 channel, boolean enable)
{
    Tom_PubReg[TomNum]->CH[channel].IRQ_EN.B.CCU1TC_IRQ_EN = enable;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCcu0ForceInt
* @details      Set cc0 force interrupt interupt.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCcu0ForceInt(uint8 TomNum,uint8 channel)
{
    Tom_PubReg[TomNum]->CH[channel].IRQ_FORCINT.B.TRG_CCU0TC0 = TRUE;
}

/**
* @brief        Gtm_Hw_Tom_PriSetCcu1ForceInt
* @details      Set cc1 force interrupt interupt.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetCcu1ForceInt(uint8 TomNum,uint8 channel)
{
    Tom_PubReg[TomNum]->CH[channel].IRQ_FORCINT.B.TRG_CCU1TC0 = TRUE;
}

/**
* @brief        Gtm_Hw_Tom_PriSelectIntMode
* @details      Select interrupt mode.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    mode interupt mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSelectIntMode(uint8 TomNum,uint8 channel, Tom_InterruptModeType mode)
{
    Tom_PubReg[TomNum]->CH[channel].IRQ_MODE.B.IRQ_MODE = mode;
}

/**
* @brief        Gtm_Hw_Tom_PriSelectIntMode
* @details      Enable high resolution mode.
* @param[in]    TomNum The TOM instance id
* @param[in]    channel tom channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tom_PriSetHresMode(uint8 TomNum,uint8 channel, boolean enable)
{
    Tom_PubReg[TomNum]->CH[channel].CTRL2.B.HRES = enable;
}

/**
* @brief        Gtm_Hw_Tom_PriSelectIntMode
* @details      Get tom instance.
* @param[in]    TomHwUnit Tom hardware unit
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Tom_PriGetTomInstance(uint8 TomHwUnit)
{
    return (TomHwUnit >> (uint8)4);
}

/**
* @brief        Gtm_Hw_Tom_PriGetTomChannel
* @details      Get tom channel id.
* @param[in]    TomHwUnit Tom hardware unit
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Tom_PriGetTomChannel(uint8 TomHwUnit)
{
    return (TomHwUnit & (uint8)0xF);
}

/**
* @brief        Gtm_Hw_Tom_Configure
* @details      Initialize tom unit.
* @param[in]    TomConfig:    Tom configuration container
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_Configure(TT_CONST Tom_ConfigType *TomConfig);

/**
* @brief        Gtm_Hw_Tom_DeInit
* @details      Reset specified channel
* @param[in]    tomChannel: Tom channel
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_DeInit(TT_CONST Tom_ChannelType tomChannel);

/**
* @brief        Gtm_Hw_Tom_ChanelEnable
* @details      Enable tom channel.
* @param[in]    tomChannel       : Tom channel
* @param[in]    enableMode       : at or wait host trigger
* @param[in]    outputEnableMode : at or wait host trigger
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_ChanelEnable(Tom_ChannelType tomChannel,
                                   Tom_ChannelEnableType enableMode,
                                   Tom_ChannelOutputControlType outputEnableMode);

/**
* @brief        Gtm_Hw_Tom_ChanelDisable
* @details      Disable tom channel.
* @param[in]    tomChannel:        Tom channel
* @param[in]    disableMode:       at or wait host trigger
* @param[in]    outputDisableMode: at or wait host trigger
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_ChanelDisable(Tom_ChannelType tomChannel,
                                    Tom_ChannelEnableType disableMode,
                                    Tom_ChannelOutputControlType outputDisableMode);

/**
* @brief        Gtm_Hw_Tom_SetHostTrigger
* @details      Generate hosttrig signal.
* @param[in]    tomInstance: Tom instance
* @param[in]    tgcIndex:    tgc number
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetHostTrigger(uint8 tomInstance, uint8 tgcIndex);

/**
* @brief        Gtm_Hw_Tom_SetUpdateCtrl
* @details      Generate update signal.
* @param[in]    tomInstance: Tom instance
* @param[in]    tgcIndex:    tgc number
* @param[in]    mask:        Data mask, 1 indicates that the corresponding channel is enabled
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetUpdateCtrl(uint8 tomInstance,
                                    uint8 tgcIndex,
                                    uint8 mask);

/**
* @brief        Gtm_Hw_Tom_SetCounterCn0
* @details      Set tom counter cn0.
* @param[in]    tomChannel:    Tom channel
* @param[in]    Cn0Value:    Cn0 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterCn0(Tom_ChannelType tomChannel,
                                    uint16 Cn0Value);

/**
* @brief        Gtm_Hw_Tom_GetCounterCn0
* @details      Get tom counter cn0.
* @param[in]    tomChannel:    Tom channel
* @param[out]   Cn0Value:    Cn0 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterCn0(Tom_ChannelType tomChannel,
                                    uint16* Cn0Value);

/**
* @brief        Gtm_Hw_Tom_SetCounterCm0
* @details      Set tom counter cm0.
* @param[in]    tomChannel: Tom channel
* @param[in]    Cn0Value:   Cm0 counter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterCm0(Tom_ChannelType tomChannel,
                                    uint16 Cm0Value);

/**
* @brief        Gtm_Hw_Tom_GetCounterCm0
* @details      Get tom counter cm0.
* @param[in]    tomChannel:    Tom channel
* @param[out]   Value:        Cm0 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterCm0(Tom_ChannelType tomChannel,
                                    uint16* Value);

/**
* @brief        Gtm_Hw_Tom_SetCounterCm1
* @details      Set tom counter cm1.
* @param[in]    tomChannel:    Tom channel
* @param[in]    Cn0Value:    Cm1 counter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterCm1(Tom_ChannelType tomChannel,
                                    uint16 Cm1Value);

/**
* @brief        Gtm_Hw_Tom_GetCounterCm1
* @details      Get tom counter cm1.
* @param[in]    tomChannel:    Tom channel
* @param[out]   Value:        Cm1 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterCm1(Tom_ChannelType tomChannel,
                                    uint16* Value);

/**
* @brief        Gtm_Hw_Tom_SetCounterSr0
* @details      Set tom counter sr0.
* @param[in]    tomChannel:  Tom channel
* @param[in]    Cn0Value:    Sr0 counter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterSr0(Tom_ChannelType tomChannel,
                                    uint16 Sr0Value);

/**
* @brief        Gtm_Hw_Tom_GetCounterSr0
* @details      Get tom counter sr0.
* @param[in]    tomChannel:    Tom channel
* @param[out]   Value:        Sr0 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterSr0(Tom_ChannelType tomChannel,
                                    uint16* Value);

/**
* @brief        Gtm_Hw_Tom_SetCounterSr1
* @details      Set tom counter sr1.
* @param[in]    tomChannel:    Tom channel
* @param[in]    Cn0Value:      sr1 counter
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetCounterSr1(Tom_ChannelType tomChannel,
                                    uint16 Sr1Value);

/**
* @brief        Gtm_Hw_Tom_GetCounterSr1
* @details      Get tom counter sr1.
* @param[in]    tomChannel:   Tom channel
* @param[out]   Value:        sr1 counter
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_GetCounterSr1(Tom_ChannelType tomChannel,
                                    uint16* Value);

/**
* @brief        Gtm_Hw_Tom_SetAllTrigerIn
* @details      This service set trigger_mux connectSource.
* @param[in]    GtmConnectCfg:    Connections Config
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetAllTrigerIn(TT_CONST Gtm_ConnectionsConfigType *GtmConnectCfg);


/**
* @brief        Gtm_Hw_Tom_SetTomInt
* @details      Enable or disable a specified interrupt
* @param[in]    tomChannel: Tom channel
* @param[in]    Irq_Mask: bit0:CCU0_IRQ enable/disable,bit1:CCU1_IRQ enable/disable
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tom_SetTomInt(TT_CONST Tom_ChannelType tomChannel,
                                TT_CONST uint8 Irq_Mask);

#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */
