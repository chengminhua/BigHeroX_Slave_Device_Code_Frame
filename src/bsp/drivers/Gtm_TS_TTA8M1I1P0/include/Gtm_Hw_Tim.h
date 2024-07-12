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
**  FILENAME     : Gtm_Hw_Tim.h                                               **
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

#ifndef GTM_HW_TIM_H
#define GTM_HW_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Tim_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_TIM_VENDOR_ID_H                      1541
#define GTM_HW_TIM_MODULE_ID_H                      221
#define GTM_HW_TIM_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_TIM_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_TIM_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_TIM_SW_MAJOR_VERSION_H               1
#define GTM_HW_TIM_SW_MINOR_VERSION_H               1
#define GTM_HW_TIM_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Tim.h Gtm_Hw_Tim_Types.h file version check */
#if (GTM_HW_TIM_VENDOR_ID_H != GTM_HW_TIM_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Tim.h and Gtm_Hw_Tim_Types.h have different vendor ids"
#endif

#if (GTM_HW_TIM_MODULE_ID_H != GTM_HW_TIM_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Tim.h and Gtm_Hw_Tim_Types.h have different module ids"
#endif

#if ((GTM_HW_TIM_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_TIM_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_TIM_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TIM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tim.h and Gtm_Hw_Tim_Types.h are different"
#endif

#if ((GTM_HW_TIM_SW_MAJOR_VERSION_H != GTM_HW_TIM_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_TIM_SW_MINOR_VERSION_H != GTM_HW_TIM_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_TIM_SW_PATCH_VERSION_H != GTM_HW_TIM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tim.h and Gtm_Hw_Tim_Types.h are different"
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
/**
* @brief        Gtm_Hw_Tim_PriSetCnts
* @details      Set shadow cnts value
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum Tim channel number
* @param[in]    CntsValue enable or disable
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetCnts(uint8 TimNum,
                                     uint8 ChNum,
                                     uint32 CntsValue)
{
    Tim_PubReg[TimNum]->CH[ChNum].CNTS.R = CntsValue & 0xFFFFU;
}

/**
* @brief        Gtm_Hw_Tim_PriGetCnts
* @details      Get shadow cnts value
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum Tim channel number
* @param[out]   None
* @return       uint32
* @retval       CNTS value
* @pre
*/
LOCAL_INLINE uint32 Gtm_Hw_Tim_PriGetCnts(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].CNTS.R;
}

/**
* @brief        Gtm_Hw_Tim_PriGetCnt
* @details      Get cnt value
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum Tim channel number
* @param[out]   None
* @return       uint32
* @retval       CNT value
* @pre
*/
LOCAL_INLINE uint32 Gtm_Hw_Tim_PriGetCnt(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].CNT.R;
}

/**
* @brief        Gtm_Hw_Tim_PriGetGpr0
* @details      Get gpr0 value
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum Tim channel number
* @param[out]   None
* @return       uint32
* @retval       Gpro value
* @pre
*/
LOCAL_INLINE uint32 Gtm_Hw_Tim_PriGetGpr0(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].GPR0.R;
}

/**
* @brief        Gtm_Hw_Tim_PriGetGpr1
* @details      Get gpr1 value
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum Tim channel number
* @param[out]   None
* @return       uint32
* @retval       Gpr1 value
* @pre
*/
LOCAL_INLINE uint32 Gtm_Hw_Tim_PriGetGpr1(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].GPR1.R;
}

/**
* @brief        Gtm_Hw_Tim_PriSetFilterThreshold
* @details      set tim filter threshold
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum Tim channel number
* @param[in]    FltRisingEdge rising edge threshod
* @param[in]    FltFallingEdge falling edge threshod
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetFilterThreshold (uint8 TimNum,
                                                    uint8 ChNum,
                                                    uint32 FltRisingEdge,
                                                    uint32 FltFallingEdge)
{
    Tim_PubReg[TimNum]->CH[ChNum].FLT_FE.R = FltFallingEdge;
    Tim_PubReg[TimNum]->CH[ChNum].FLT_RE.R = FltRisingEdge;
}

/**
* @brief        Gtm_Hw_Tim_PriGetInstance
* @details      set tim hardware unit
* @param[in]    TimHwUnit The Tim instance id
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Tim_PriGetInstance(uint8 TimHwUnit)
{
    return (TimHwUnit >> 3U);
}

/**
* @brief        Gtm_Hw_Tim_PriGetChannel
* @details      set tim channel id
* @param[in]    TimHwUnit The Tim instance id
* @param[out]   None
* @return       uint8
* @retval       TimHwUnit number
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Tim_PriGetChannel(uint8 TimHwUnit)
{
    return (TimHwUnit & 0x7U);
}

/**
* @brief        Gtm_Hw_Tim_PriSetValx
* @details      set tim hardware unit
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    val input stat
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetValx(uint8 TimNum, uint8 ChNum, Tim_ChannelValInitSignalType val)
{
    Tim_PubReg[TimNum]->GC.IN_SRC.R = (Tim_PubReg[TimNum]->GC.IN_SRC.R & ~(0x3U << (ChNum << 2U))) | (val & 0x3U) << (ChNum << 2U);
}

/**
* @brief        Gtm_Hw_Tim_PriSetGpr0Sel
* @details      set gpr0 input select
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    inputSrc input source
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetGpr0Sel(uint8 TimNum, uint8 ChNum, uint8 inputSrc)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.GPR0_SEL = inputSrc;
}

/**
* @brief        Gtm_Hw_Tim_PriSetGpr1Sel
* @details      set gpr1 input select
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    inputSrc input source
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetGpr1Sel(uint8 TimNum, uint8 ChNum, uint8 inputSrc)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.GPR1_SEL = inputSrc;
}

/**
* @brief        Gtm_Hw_Tim_PriSetEgpr0Sel
* @details      set gpr0 extension input select
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetEgpr0Sel(uint8 TimNum, uint8 ChNum, boolean enable)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.EGPR0_SEL = enable;
}

/**
* @brief        Gtm_Hw_Tim_PriSetEgpr1Sel
* @details      set gpr1 extension input select
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetEgpr1Sel(uint8 TimNum, uint8 ChNum, boolean enable)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.EGPR1_SEL = enable;
}

/**
* @brief        Gtm_Hw_Tim_PriSetCntsInputSource
* @details      set cnts input source
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    source input source
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetCntsInputSource(uint8 TimNum, uint8 ChNum, Tim_ChannelCntsInputSelectType source)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.CNTS_SEL = source;
}

/**
* @brief        Gtm_Hw_Tim_PriSelectClock
* @details      select work clock
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    clock work clock
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSelectClock(uint8 TimNum, uint8 ChNum, Tim_ChannelClockSelectType clock)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.CLK_SEL = clock;
}

/**
* @brief        Gtm_Hw_Tim_PriSetSignalEdge
* @details      set signal vaild edge
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    edge vaild edge
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetSignalEdge(uint8 TimNum, uint8 ChNum, Tim_ChannelSignalEdgeSelectType edge)
{
    if(TIM_BOTH_EDGES == edge)
    {
        Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.ISL = 1U;
    }
    else
    {
        Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.ISL = 0U;
        Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.DSL = edge;
    }
}

/**
* @brief        Gtm_Hw_Tim_PriSelectMode
* @details      select channle mode
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    mode channel mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSelectMode(uint8 TimNum, uint8 ChNum, Tim_ChannelModeSelectType mode)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.TIM_MODE = mode;
}

/**
* @brief        Gtm_Hw_Tim_PriSetTbuBits
* @details      set tbu bit
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    bits tbu bit
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetTbuBits(uint8 TimNum, uint8 ChNum, uint8 bits)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.TBU0_SEL = bits;
}

/**
* @brief        Gtm_Hw_Tim_PriOsmEnable
* @details      set one shot mode
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriOsmEnable(uint8 TimNum, uint8 ChNum, boolean enable)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.OSM = enable;
}

/**
* @brief        Gtm_Hw_Tim_PriExtCaptureEnable
* @details      enable external capture enable
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriExtCaptureEnable(uint8 TimNum, uint8 ChNum, boolean enable)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.EXT_CAP_EN = enable;
}

/**
* @brief        Gtm_Hw_Tim_PriSelExtCaptureSrc
* @details      Select external capture source
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    mdoe external capture source
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSelExtCaptureSrc(uint8 TimNum, uint8 ChNum, Tim_ChannelExtCaptureSrcType mdoe)
{
    Tim_PubReg[TimNum]->CH[ChNum].ECTRL.B.EXT_CAP_SRC = mdoe;
}

/**
* @brief        Gtm_Hw_Tim_PriSetEcntReset
* @details      set ecnt reset mode
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    mdoe ecnt reset mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetEcntReset(uint8 TimNum, uint8 ChNum, Tim_ChannelEcntResetSettingType mdoe)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.ECNT_RESET = mdoe;
}

/**
* @brief        Gtm_Hw_Tim_PriSetEcntOverFlow
* @details      set ecnt reset mode
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    mdoe ecnt over flow mode
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetEcntOverFlow(uint8 TimNum, uint8 ChNum, Tim_ChannelEcntOvflwSettingType mdoe)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.FR_ECNT_OFL = mdoe;
}

/**
* @brief        Gtm_Hw_Tim_PriSelectFilterClock
* @details      selec filter clock
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    clock clock source
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSelectFilterClock(uint8 TimNum, uint8 ChNum, Tim_ChFirCounterFreqSelectType clock)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.FLT_CNT_FRQ = clock;
}

/**
* @brief        Gtm_Hw_Tim_PriSetFilterForRising
* @details      set filter rising value
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    time filter value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetRisingFilter(uint8 TimNum, uint8 ChNum, uint32 time)
{
    Tim_PubReg[TimNum]->CH[ChNum].FLT_RE.B.FLT_RE = time;
}

/**
* @brief        Gtm_Hw_Tim_PriSetFallingFilter
* @details      set filter falling value
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    time filter value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSetFallingFilter(uint8 TimNum, uint8 ChNum, uint32 time)
{
    Tim_PubReg[TimNum]->CH[ChNum].FLT_FE.B.FLT_FE = time;
}

/**
* @brief        Gtm_Hw_Tim_PriEnableFilter
* @details      enable filter
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriEnableFilter(uint8 TimNum, uint8 ChNum, boolean enable)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.FLT_EN = enable;
}

/**
* @brief        Gtm_Hw_Tim_PriIsNEWVAL
* @details      Get New measurement value detected event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE boolean Gtm_Hw_Tim_PriIsNEWVAL(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.NEWVAL == 1;
}

/**
* @brief        Gtm_Hw_Tim_PriIsECNTOFL
* @details      Get ECNT counter overflow  event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE boolean Gtm_Hw_Tim_PriIsECNTOFL(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.ECNTOFL == 1;
}

/**
* @brief        Gtm_Hw_Tim_PriIsECNTOFL
* @details      Get CNT counter overflow  event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE boolean Gtm_Hw_Tim_PriIsCNTOFL(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.CNTOFL == 1;
}

/**
* @brief        Gtm_Hw_Tim_PriIsGPROFL
* @details      Get TIM[i]_CH[x]_GPR0 and TIM[i]_CH[x]_GPR1 data overflow event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE boolean Gtm_Hw_Tim_PriIsGPROFL(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.GPROFL == 1;
}

/**
* @brief        Gtm_Hw_Tim_PriIsTODET
* @details      Get timeout reached for input signal of channel [x] event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE boolean Gtm_Hw_Tim_PriIsTODET(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.TODET == 1;
}

/**
* @brief        Gtm_Hw_Tim_PriIsTODET
* @details      Get glitch detected on channel [x] event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE boolean Gtm_Hw_Tim_PriIsGLITCHDET(uint8 TimNum, uint8 ChNum)
{
    return Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.GLITCHDET == 1;
}

/**
* @brief        Gtm_Hw_Tim_PriClearNEWVAL
* @details      Clear new measurement value detected event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriClearNEWVAL(uint8 TimNum, uint8 ChNum)
{
    Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.NEWVAL = 0x1U;
}

/**
* @brief        Gtm_Hw_Tim_PriClearECNTOFL
* @details      Clear ECNT counter overflow event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriClearECNTOFL(uint8 TimNum, uint8 ChNum)
{
    Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.ECNTOFL = 0x1U;
}

/**
* @brief        Gtm_Hw_Tim_PriClearCNTOFL
* @details      Clear CNT counter overflow event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriClearCNTOFL(uint8 TimNum, uint8 ChNum)
{
    Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.CNTOFL = 0x1U;
}

/**
* @brief        Gtm_Hw_Tim_PriClearGPROFL
* @details      Clear TIM[i]_CH[x]_GPR0 and TIM[i]_CH[x]_GPR1 data overflow event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriClearGPROFL(uint8 TimNum, uint8 ChNum)
{
    Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.GPROFL = 0x1U;
}

/**
* @brief        Gtm_Hw_Tim_PriClearTODET
* @details      Clear timeout reached for input signal of channel [x] event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriClearTODET(uint8 TimNum, uint8 ChNum)
{
    Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.TODET = 0x1U;
}

/**
* @brief        Gtm_Hw_Tim_PriClearGLITCHDET
* @details      Clear Glitch detected on channel [x] event
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriClearGLITCHDET(uint8 TimNum, uint8 ChNum)
{
    Tim_PubReg[TimNum]->CH[ChNum].IRQ_NOTIFY.B.GLITCHDET = 0x1U;
}

/**
* @brief        Gtm_Hw_Tim_PriSelectSlicing
* @details      set tdu mode
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    slicing tdu work mode
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriSelectSlicing(uint8 TimNum, uint8 ChNum, uint8 slicing)
{
    Tim_PubReg[TimNum]->CH[ChNum].TDUV.B.SLICING = slicing;
}

/**
* @brief        Gtm_Hw_Tim_PriTduUseSample
* @details      set tdu sample
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriTduUseSample(uint8 TimNum, uint8 ChNum, boolean enable)
{
    Tim_PubReg[TimNum]->CH[ChNum].TDUV.B.TCS_USE_SAMPLE_EVT = enable;
}

/**
* @brief        Gtm_Hw_Tim_PriTduSameCntClk
* @details      set tdu same cnt clock
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    enable enable or disable
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriTduSameCntClk(uint8 TimNum, uint8 ChNum, boolean enable)
{
    Tim_PubReg[TimNum]->CH[ChNum].TDUV.B.TDU_SAME_CNT_CLK = enable;
}

/**
* @brief        Gtm_Hw_Tim_PriTduClk
* @details      set tdu clock
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    clock clock source
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriTduClk(uint8 TimNum, uint8 ChNum, Tim_ChTimeoutClockSelectType clock)
{
    Tim_PubReg[TimNum]->CH[ChNum].TDUV.B.TCS = clock;
}

/**
* @brief        Gtm_Hw_Tim_PriTduSetTov
* @details      set tdu tov
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    value tov value
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriTduSetTov(uint8 TimNum, uint8 ChNum, uint8 value)
{
    Tim_PubReg[TimNum]->CH[ChNum].TDUV.B.TOV = value;
}

/**
* @brief        Gtm_Hw_Tim_PriTduSetTov1
* @details      set tdu tov1
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    value tov1 value
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriTduSetTov1(uint8 TimNum, uint8 ChNum, uint8 value)
{
    Tim_PubReg[TimNum]->CH[ChNum].TDUV.B.TOV1 = value;
}

/**
* @brief        Gtm_Hw_Tim_PriTduSetTov2
* @details      set tdu tov2
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    value tov2 value
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriTduSetTov2(uint8 TimNum, uint8 ChNum, uint8 value)
{
    Tim_PubReg[TimNum]->CH[ChNum].TDUV.B.TOV2 = value;
}

/**
* @brief        Gtm_Hw_Tim_PriTduDetectionEnable
* @details      set tdu enable mode
* @param[in]    TimNum The Tim instance id
* @param[in]    ChNum channel number
* @param[in]    mode tdu enable mode
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriTduDetectionEnable(uint8 TimNum, uint8 ChNum, Tim_ChTimeoutDetectionEnType mode)
{
    Tim_PubReg[TimNum]->CH[ChNum].CTRL.B.TOCTRL = mode;
}

/**
* @brief        Gtm_Hw_Tim_PriTduDetectionEnable
* @details      set connect second input
* @param[in]    enable enable or disable
* @param[out]   None
* @return       boolean
* @retval       true  : event occur
                false : event not occur
* @pre
*/
LOCAL_INLINE void Gtm_Hw_Tim_PriConnectSecondGroup(boolean enable)
{
    GTM.CFG.B.SRC_IN_MUX = enable;
}

/**
* @brief        Gtm_Hw_Tim_Configure
* @details      Configure channel.
* @param[in]    TimConfig:    Configuration contions pointer
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_Configure(TT_CONST Tim_ConfigType* TimConfig);

/**
* @brief        Gtm_Hw_Tim_DeInit
* @details      Reset specified channel
* @param[in]    TimChannel: Tim channel
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_DeInit(TT_CONST Tim_ChnnelType TimChannel);

/**
* @brief        Gtm_Hw_Tim_StartMeasure
* @details      Start pwm measure.
* @param[in]    TimChannel:    Tim channel id
* @param[in]    immediate:     at or wait for vaild edge
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_StartMeasure(Tim_ChnnelType TimChannel, uint8 immediate);

/**
* @brief        Gtm_Hw_Tim_StopMeasure
* @details      Stop pwm measure.
* @param[in]    TimChannel : Tim channel id
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_StopMeasure(Tim_ChnnelType TimChannel);

/**
* @brief        Gtm_Hw_Tim_GetStatusFlags
* @details      get channel status.
* @param[in]    TimChannel  : Tim channel id
* @param[out]   statusFlags : channel status
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_GetStatusFlags(Tim_ChnnelType TimChannel,
                                     uint8* statusFlags);

/**
* @brief        Gtm_Hw_Tim_ClearStatusFlags
* @details      clear channel status.
* @param[in]    TimChannel       : Tim channel id
* @param[in]    flag_ClearStatus : status flag
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_ClearStatusFlag(Tim_ChnnelType TimChannel,
                                      Tim_StatusFlagType flag_ClearStatus);


/**
* @brief        Gtm_Hw_Tim_SetTimValx
* @details      Set input level.
* @param[in]    timCh : Tim channel id
* @param[in]    val   : input level
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_SetTimValx(Tim_ChnnelType TimChannel,
                                 Tim_ChannelValInitSignalType val);

/**
* @brief        Gtm_Hw_Tim_SetInput
* @details      Set input level.
* @param[in]    TimIndex : Tim Index (0:TIMch0,...,7:TIMch7)
* @param[in]    InputSel : input Sel (0:pad,1:osc,2:eclk0,3:eclk1,4:eclk)
* @param[in]    Osc_Div  : OSC frequency division value
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_SetInput(uint8 TimIndex,uint8 InputSel,uint8 Osc_Div);

/**
* @brief        Gtm_Hw_Interrupt_SetTimInt
* @details      Enable or disable a specified interrupt
* @param[in]    TimChannel: Tim channel
* @param[in]    Irq_Mask: bit0:NEWVAL_IRQ enable/disable,bit1:ECNTOFL_IRQ enable/disable
*                         bit2:CNTOFL_IRQ enable/disable,bit3:GPROFL_IRQ enable/disable
*                         bit4:TODET_IRQ enable/disable,bit5:GLITCHDET_IRQ enable/disable
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_SetTimInt(TT_CONST Tim_ChnnelType TimChannel,TT_CONST uint8 Irq_Mask);

/**
* @brief        Gtm_Hw_Tim_GetPwmInformation
* @details      Get pwm Information data.
* @param[in]    TimChannel:  Tim channel id
* @param[out]   pwmInfor:    pwm information data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_GetPwmInformation(Tim_ChnnelType TimChannel,
                                        Tim_PwmInfor * TT_CONST pwmInfor);

/**
* @brief        Gtm_Hw_Tim_GetMeasureInformation
* @details      get measure information.
* @param[in]    TimChannel:   Tim channel id
* @param[out]   infor:        Tom channel id
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_GetMeasureInformation(Tim_ChnnelType TimChannel,
                                            Tim_MeasureInfor * TT_CONST infor);

/**
* @brief        Gtm_Hw_Tim_GetPulseTime
* @details      get pulse time.
* @param[in]    TimChannel:    Tim channel id
* @param[out]   sumTime   :    Time data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tim_GetPulseTime(Tim_ChnnelType TimChannel,
                                   float64* sumTime);


#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */
