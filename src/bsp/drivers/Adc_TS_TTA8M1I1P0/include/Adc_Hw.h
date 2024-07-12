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
**  FILENAME     : Adc_Hw.h                                                   **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Alioth Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef ADC_Hw_H
#define ADC_Hw_H

/******************************************************************************
*                            Includes
******************************************************************************/

#include "Adc_Hw_Types.h"
#include "Mcu_Drv.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define ADC_HW_VENDOR_ID_H                    1541
#define ADC_HW_MODULE_ID_H                    123
#define ADC_HW_INSTANCE_ID_H                  0
#define ADC_HW_AR_RELEASE_MAJOR_VERSION_H     4
#define ADC_HW_AR_RELEASE_MINOR_VERSION_H     4
#define ADC_HW_AR_RELEASE_PATCH_VERSION_H     0
#define ADC_HW_SW_MAJOR_VERSION_H             1
#define ADC_HW_SW_MINOR_VERSION_H             1
#define ADC_HW_SW_PATCH_VERSION_H             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Adc_Hw.h Adc_Hw_Types.h file version check */
#if (ADC_HW_VENDOR_ID_H != ADC_HW_TYPES_VENDOR_ID_H)
    #error "Adc_Hw.h and Adc_Hw_Types.h have different vendor ids"
#endif

#if (ADC_HW_MODULE_ID_H != ADC_HW_TYPES_MODULE_ID_H)
    #error "Adc_Hw.h and Adc_Hw_Types.h have different module ids"
#endif

#if ((ADC_HW_AR_RELEASE_MAJOR_VERSION_H != ADC_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_HW_AR_RELEASE_MINOR_VERSION_H != ADC_HW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_HW_AR_RELEASE_PATCH_VERSION_H != ADC_HW_TYPES_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Hw.h and Adc_Hw_Types.h are different"
#endif

#if ((ADC_HW_SW_MAJOR_VERSION_H != ADC_HW_TYPES_SW_MAJOR_VERSION_H) || \
     (ADC_HW_SW_MINOR_VERSION_H != ADC_HW_TYPES_SW_MINOR_VERSION_H) || \
     (ADC_HW_SW_PATCH_VERSION_H != ADC_HW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Hw.h and Adc_Hw_Types.h are different"
#endif

/* Adc_Hw.h Mcu_Drv.h file version check */
#if (ADC_HW_VENDOR_ID_H != MCU_DRV_VENDOR_ID_H)
    #error "Adc_Hw.h and Mcu_Drv.h have the same vendor ids"
#endif

#if (ADC_HW_MODULE_ID_H == MCU_DRV_MODULE_ID_H)
    #error "Adc_Hw.h and Mcu_Drv.h have different module ids"
#endif

#if ((ADC_HW_AR_RELEASE_MAJOR_VERSION_H != MCU_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (ADC_HW_AR_RELEASE_MINOR_VERSION_H != MCU_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (ADC_HW_AR_RELEASE_PATCH_VERSION_H != MCU_DRV_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_Hw.h and Mcu_Drv.h are different"
#endif

#if ((ADC_HW_SW_MAJOR_VERSION_H != MCU_DRV_SW_MAJOR_VERSION_H) || \
     (ADC_HW_SW_MINOR_VERSION_H != MCU_DRV_SW_MINOR_VERSION_H) || \
     (ADC_HW_SW_PATCH_VERSION_H != MCU_DRV_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_Hw.h and Mcu_Drv.h are different"
#endif
/******************************************************************************
*                            Private Functions
******************************************************************************/
/*Global variable declaration of configuration information*/

#ifndef USING_OS_AUTOSAROS
extern TT_CONST Adc_Hw_HwUnitConfigType *AdcHw_PubConfigSet;
#endif

/*Interrupt the service function declaration*/
#ifndef USING_OS_AUTOSAROS
ISR(ADC0_IRQHandler);
ISR(ADC1_IRQHandler);
ISR(ADC2_IRQHandler);
ISR(ADC3_IRQHandler);
ISR(ADC4_IRQHandler);
ISR(ADC5_IRQHandler);
#endif

#define ADC_START_SEC_CODE_FAST
#include "Adc_MemMap.h"

/**
 *@brief          Get Adc instance
 *
 *@param[in]      Channel - Adc Hw_Channel ID
 *@return         Adc instance
 *@retval         NON
 *@retval         NON
 */
LOCAL_INLINE uint8 Adc_Hw_GetInstance (Adc_Hw_ChannelType Channel)
{
    return (Channel >> (uint8) 4);
}

/**
 *@brief          Get Adc channel id
 *
 *@param[in]      Channel - Adc Hw_Channel ID
 *@return         Adc instance
 *@retval         NON
 *@retval         NON
 */
LOCAL_INLINE uint8 Adc_Hw_GetChannel (Adc_Hw_ChannelType Channel)
{
    return (Channel & (uint8) 0xF);
}

/**
 *@brief          Get Adc Channel State
 *
 *@param[in]      HwUnit - Adc Hw ID
 *@param[in]      Ch - Channel ID
 *@return         Channel State
 *@retval         NON
 *@retval         NON
 */
LOCAL_INLINE uint32 Adc_Hw_IrqGetChannelState (uint32 HwUnit, uint32 Ch)
{
    return TT_ADC->AXCHREGT[HwUnit].AXCYREGT[Ch].AxCySTR;
}

/**
@brief          Adc Clear State
@param[in]      HwUnit: Adc Hw ID
                C_Flags    : State flags
@return         void
@retval         NON
@retval         NON
*/
LOCAL_INLINE void Adc_Hw_IrqAdcxClearState(uint32 HwUnit,TT_CONST uint32 C_Flags)
{
    TT_ADC->GSTR[HwUnit] = C_Flags;
    MCAL_DATA_SYNC_BARRIER();
}

/**
 *@brief          Adc common config
 *
 *@param[in]      config - Adc Common Config
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */

#define ADC_STOP_SEC_CODE_FAST
#include "Adc_MemMap.h"

TT_RetType Adc_Hw_CommonInit (TT_CONST Adc_Hw_CommonConfigType *Config);

/**
 *@brief          ADC hardware unit configuration
 *
 *@param[in]      Config - Adc HwUnit Config Channel
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_AdcxConfig (TT_CONST Adc_Hw_HwUnitConfigType *Config);

/**
 *@brief          ADC disable hardware unit
 *
 *@param[in]      UintId - Adc HwUnit ID
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_AdcxDisable (TT_CONST Adc_Hw_HwUnitType UnitId);

/**
 *@brief          ADC Channel configuration
 *
 *@param[in]      Config - Adc Channel Configuration information
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_ChannelConfig (TT_CONST Adc_Hw_ChannelConfigType *Config);

/**
 *@brief          ADC start conversion
 *
 *@param[in]      ChannelI - Adc Channel Id
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_StartConvert (TT_CONST Adc_Hw_ChannelType ChannelId);

/**
 *@brief          This function stops the current conversion of a group.
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]		 Stop - Stop mode
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_StopConversion (TT_CONST Adc_Hw_HwUnitType HwUnit,
                                  TT_CONST Adc_Hw_StopModeType Stop);

/**
 *@brief          ADC DMA Buffer configuration
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      result - Result buffer
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetDmaBuff (TT_CONST Adc_Hw_ChannelType ChannelId,
                              TT_CONST uint16 *result);

/**
 *@brief          Configure the number of dma transfers
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      Count - Number of dma transfers
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetDmaTransCount (TT_CONST Adc_Hw_ChannelType ChannelId,
                                    TT_CONST uint32 Count);

/**
 *@brief          Configure the dma incremental address
 *
 *@param[in]      AdcChannel - Adc Channel Id
 *@param[in]      Incraddr - Address accumulation value
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_Set_DmaIncraddr (TT_CONST Adc_Hw_ChannelType ChannelId,
                                   TT_CONST uint32 Incraddr);

/**
 *@brief          Get ADC Global status
 *
 *@param[in]      HwUnit - Adc Unit Id
 *@param[out]     Value -  ADC Global status
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_GetGlobalState (TT_CONST Adc_Hw_HwUnitType HwUnit, uint32 *Value);

/**
 *@brief          Get ADC Current state
 *
 *@param[in]      HwUnit - Adc Unit Id
 *@param[out]     Value - ADC Current status
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_GetCurrentState (TT_CONST Adc_Hw_HwUnitType HwUnit,
                                   uint32 *Value);

/**
 *@brief          Get ADC Channel status
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[out]     Value - channel state
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_GetChannelState (TT_CONST Adc_Hw_ChannelType ChannelId,
                                   uint32 *Value);

/**
@brief          Clear ADC Global status
@param[in]      ChannelId: Adc Channel Id
                DmaClear : clear the DMA flag
@return         TT_RetType
@retval         E_OK            Succeed
@retval         E_NOT_OK        failure
*/
TT_RetType Adc_Hw_ClearGlobalState(TT_CONST Adc_Hw_ChannelType ChannelId,TT_CONST boolean DmaClear);

/**
 *@brief          Get ADC conversion data
 *
 *@param[in]      AdcChannel - Adc Channel Id
 *@param[out]     Value -  ADC Value
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_GetValue (TT_CONST Adc_Hw_ChannelType ChannelId, uint16 *Value);

/**
 *@brief          ADC Enable Hw Trig
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_EnableHwTrig (TT_CONST Adc_Hw_ChannelType ChannelId);

/**
 *@brief          ADC Disable Hw Trig
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_DisableHwTrig (TT_CONST Adc_Hw_ChannelType ChannelId);

/**
 *@brief          ADC set Squence
 *
 *@param[in]      HwUnit - Adc unit Id
 *@param[in]      Queue - Queue data, four bits representing a channel, low transmission first
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetSquence (TT_CONST Adc_Hw_HwUnitType HwUnit,
                              TT_CONST uint32 Queue);

/**
 *@brief          ADC set cascade trigger
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      NextChannel - Cascade triggered channels
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetCTrigger (TT_CONST Adc_Hw_ChannelType ChannelId,
                               TT_CONST Adc_Hw_CTrigType NextChannel);

/**
 *@brief          Adc_Hw_SetTrigger
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]		 TrigSrc - Trigger source
 *@param[in]      TrigSig - Trigger Edge
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetTrigger (TT_CONST Adc_Hw_ChannelType ChannelId,
                              TT_CONST Adc_Hw_TrigSrcType TrigSrc,
                              TT_CONST Adc_Hw_HwTrigSigType TrigSig);

/**
 *@brief          Adc_Hw_SetReadyIntEn
 *
 *@param[in]      ChannelId - Channel Id
 *@param[in]      Enable - Ready interrupt enable
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetReadyIntEn (TT_CONST Adc_Hw_ChannelType ChannelId,
                                 TT_CONST uint8 Enable);

/**
 *@brief          ADC set channel priority
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      Pri - channel priority
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetCPriority (TT_CONST Adc_Hw_ChannelType ChannelId,
                                TT_CONST Adc_Hw_PriorityType Pri);

/**
 *@brief          ADC set DMA enable
 *
 *@param[in]      ChannelId - Adc Channel Id
 *@param[in]      Enable - DMA enable
 *@param[in]      IntEnable DMA Int enable
 *@return         TT_RetType
 *@retval         TT_RET_SUCCESS - Succeed
 *@retval         Other - Failure
 */
TT_RetType Adc_Hw_SetDmaEn (TT_CONST Adc_Hw_ChannelType ChannelId,
                            TT_CONST boolean Enable, TT_CONST boolean IntEnable);

/**
* @brief        Adc_Hw_InitCheck
* @details      InitCheck For Adc After McuInit
* @param[in]    HwUnit      Adc unit Id
* @param[in]    AGC0_Mask   AGC data
* @param[in]    AxCfr       AxCFR data
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Adc_Hw_InitCheck(TT_CONST Adc_Hw_HwUnitType HwUnit,
                            TT_CONST uint32 AGC0_Mask,
                            TT_CONST uint32 AxCfr);

/**
* @brief        Adc_Hw_SelfCorrecting
* @details      Software calibrates adc parameters
* @param[in]    HwUnit      Adc unit Id
* @param[in]    PowerMode   Adc VREF power mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Adc_Hw_SelfCorrecting(TT_CONST Adc_Hw_HwUnitType HwUnit,
                                 TT_CONST Adc_Hw_PowerModeType PowerMode);

#endif
