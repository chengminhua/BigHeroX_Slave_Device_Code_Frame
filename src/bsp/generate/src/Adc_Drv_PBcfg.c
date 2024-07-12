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
**  FILENAME     : Adc_Drv_PBCfg.c                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Adc Driver Configuration Generated File                    **
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
#include "Adc_Drv.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define ADC_DRV_PBCFG_VENDOR_ID_C                    1541
#define ADC_DRV_PBCFG_MODULE_ID_C                    123
/**
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
/**
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_DRV_PBCFG_AR_ERLEASE_MINOR_VERSION_C     4
/**
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C  0
#define ADC_DRV_PBCFG_SW_MAJOR_VERSION_C             1
#define ADC_DRV_PBCFG_SW_MINOR_VERSION_C             1
#define ADC_DRV_PBCFG_SW_PATCH_VERSION_C             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Check if source file and Adc_Drv header file are of the same vendor */
#if (ADC_DRV_PBCFG_VENDOR_ID_C != ADC_DRV_VENDOR_ID_H)
    #error "Adc_PBcfg.c and Adc_Drv.h have different vendor ids"
#endif

/* Check if source file and Adc_Drv header file are of the same vendor */
#if (ADC_DRV_PBCFG_MODULE_ID_C != ADC_DRV_MODULE_ID_H)
    #error "Adc_PBcfg.c and Adc_Drv.h have different module ids"
#endif

/* Check if source file and Adc_Drv header file are of the same Autosar version */
#if ((ADC_DRV_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ADC_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
    (ADC_DRV_PBCFG_AR_ERLEASE_MINOR_VERSION_C != ADC_DRV_AR_RELEASE_MINOR_VERSION_H) || \
    (ADC_DRV_PBCFG_AR_RELEASE_PATCH_VERSION_C != ADC_DRV_AR_RELEASE_PATCH_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc_Drv.h are different"
#endif

/* Check if source file and Adc_Drv header file are of the same Software version */
#if ((ADC_DRV_PBCFG_SW_MAJOR_VERSION_C != ADC_DRV_SW_MAJOR_VERSION_H) || \
    (ADC_DRV_PBCFG_SW_MINOR_VERSION_C != ADC_DRV_SW_MINOR_VERSION_H) || \
    (ADC_DRV_PBCFG_SW_PATCH_VERSION_C != ADC_DRV_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc_Drv.h are different"
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
#define ADC_START_SEC_CODE_FAST
#include "Adc_MemMap.h"

/* define notification*/
extern void CB1(TT_CONST Adc_Hw_ChannelType AdcChannel,TT_CONST uint32 Event);
/* define notification*/
extern void CB2(TT_CONST Adc_Hw_ChannelType AdcChannel,TT_CONST uint32 Event);

#define ADC_STOP_SEC_CODE_FAST
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/**
* @brief         Adc_Drv_FilterInfo.
* @details       Filter parameter configuration information.
*
*/
static TT_CONST Adc_Drv_FilterInfoType Adc_Drv_FilterInfo =
{
    /**< @brief Filter coefficient write protection */
    .Fir_Wp   = (boolean) STD_OFF,
    /**< @brief Filling filter coefficient */
    .filters  = {
                    /**< @brief filter[0]*/
                    (int32_t)0,
                    /**< @brief filter[1]*/
                    (int32_t)0,
                    /**< @brief filter[2]*/
                    (int32_t)0,
                    /**< @brief filter[3]*/
                    (int32_t)0,
                    /**< @brief filter[4]*/
                    (int32_t)0,
                    /**< @brief filter[5]*/
                    (int32_t)0,
                    /**< @brief filter[6]*/
                    (int32_t)0,
                    /**< @brief filter[7]*/
                    (int32_t)0,
                    /**< @brief filter[8]*/
                    (int32_t)0,
                    /**< @brief filter[9]*/
                    (int32_t)0,
                    /**< @brief filter[10]*/
                    (int32_t)0,
                    /**< @brief filter[11]*/
                    (int32_t)0,
                    /**< @brief filter[12]*/
                    (int32_t)0,
                    /**< @brief filter[13]*/
                    (int32_t)0,
                    /**< @brief filter[14]*/
                    (int32_t)0,
                    /**< @brief filter[15]*/
                    (int32_t)0,
                    /**< @brief filter[16]*/
                    (int32_t)0,
                    /**< @brief filter[17]*/
                    (int32_t)0,
                    /**< @brief filter[18]*/
                    (int32_t)0,
                    /**< @brief filter[19]*/
                    (int32_t)0,
                    /**< @brief filter[20]*/
                    (int32_t)0,
                    /**< @brief filter[21]*/
                    (int32_t)0,
                    /**< @brief filter[22]*/
                    (int32_t)0,
                    /**< @brief filter[23]*/
                    (int32_t)0,
                    /**< @brief filter[24]*/
                    (int32_t)0
                }
};
/**
* @brief         Adc_Drv_CommonConfigTypeData.
* @details       Definition of ADC Hw units common for Configuration variant.
*
*/
static TT_CONST Adc_Drv_CommonConfigType Adc_Drv_CommonConfigTypeData[] =
{
    {
        /**< @brief Adc Analog Clock Div */
        .Div       = (uint8)3,
        /**< @brief Adc Slow Scan Timing */
        .STSamp    = (uint8)20,
        /**< @brief Adc Fast Scan Timing */
        .FTSamp    = (uint8)10,
        /**< @brief The power supply scheme used by the ADC */
        .PowerMode = ADC_5V_MODE,
        /**< @brief Adc Sample Value Right Shift */
        .FirShift  = (uint8)0,
        /**< @brief Adc clock_stop Enable */
        .Clk_Stop  = (boolean) STD_OFF,
        /**< @brief Adc Register AGC0 Write Protection */
        .Acg0_Wp   = (boolean) STD_OFF,
        /**< @brief filter coefficient*/
        .Filter    = &Adc_Drv_FilterInfo
    }
};
/**
* @brief         Adc_Drv_HwConfigData
* @details       Definition of ADC Hw units for Configuration variant.
*/
static TT_CONST Adc_Drv_HwUnitConfigType Adc_Drv_HwConfigData[] =
{
    /**< @brief Hardware Unit ADC1 */
    {
        /**< @brief Hardware unit id */
        .AdcHwUnitId        = ADC1,
        /**< @brief Hardware unit enable */
        .Enable             = STD_ON,
        /**< @brief ADCx wait to read enable */
        .WaitRead	        = STD_OFF,
        /**< @brief The ADCx compensate enable */
        .CompenEn			= STD_OFF,
        /**< @brief The ADCx compensate value */
        .CompenData         = 0,
        /**< @brief The ADCx DMA enable */
        .DmaEn			    = STD_ON,
        /**< @brief The ADCx DMA interrupt enable */
        .DmaIntEn			= STD_ON,
        /**< @brief The ADCx DMA mode */
        .DmaMode            = ADC_DMA_MODE_NOMAL,
        /**< @brief The ADCx sequence*/
        .Queue              = 0x0,
        /**< @brief The ADCx mode configuration register */
        .CMode              = ADC_HW_WAIT_READY_START,
        /**< @brief The ADCx callback event */
        .Event              = CB1
    },

    /**< @brief Hardware Unit ADC2 */
    {
        /**< @brief Hardware unit id */
        .AdcHwUnitId        = ADC2,
        /**< @brief Hardware unit enable */
        .Enable             = STD_ON,
        /**< @brief ADCx wait to read enable */
        .WaitRead	        = STD_OFF,
        /**< @brief The ADCx compensate enable */
        .CompenEn			= STD_OFF,
        /**< @brief The ADCx compensate value */
        .CompenData         = 0,
        /**< @brief The ADCx DMA enable */
        .DmaEn			    = STD_ON,
        /**< @brief The ADCx DMA interrupt enable */
        .DmaIntEn			= STD_ON,
        /**< @brief The ADCx DMA mode */
        .DmaMode            = ADC_DMA_MODE_NOMAL,
        /**< @brief The ADCx sequence*/
        .Queue              = 0x0,
        /**< @brief The ADCx mode configuration register */
        .CMode              = ADC_HW_WAIT_READY_START,
        /**< @brief The ADCx callback event */
        .Event              = CB2
    }

};
/**
* @brief          Adc_Drv_ChannelConfigData.
* @details        Adc channel configuration.
*/
static TT_CONST Adc_Drv_ChannelConfigType Adc_Drv_ChannelConfigData[] =
{
    /**< @brief Hardware Unit ADC1  --   ADC1_CH_2 */
    {
        /**< @brief Adc physical channel */
        .ChId             = ADC1_CH_2,
        /**< @brief Adc righ shift num */
        .Shift            = 0,
        /**< @brief Adc over sample num */
        .SampNum          = 0,
        /**< @brief Adc channel ready interrupt enable */
        .ReadyIntEn       = STD_OFF,
        /**< @brief Adc channel fast sampling is enable */
        .FSampEn          = STD_OFF,
        /**< @brief Adc channel filtering enable */
        .FirEn            = STD_OFF,
        /**< @brief High threshold detection enabled */
        .HCompEn          = STD_OFF,
        /**< @brief Low threshold detection enabled */
        .LCompEn          = STD_OFF,
        /**< @brief High threshold detection interrupt enabled */
        .HCompIntEn       = STD_OFF,
        /**< @brief Low threshold detection interrupt enabled */
        .LCompIntEn       = STD_OFF,
        /**< @brief Adc channel high threshold */
        .ThresholdH       = 0,
        /**< @brief Adc channel low threshold */
        .ThresholdL       = 0,
        /**< @brief Adc channel trigger in dma interrupt enable */
        .TrgDmaIntEn      = STD_OFF,
         /**< @brief The Timeout error interrupt was enabled */
        .TimeoutIntEn     = STD_OFF,
        /**< @brief The comparison error interrupt was enabled */
        .CompIntEn        = STD_OFF,
        /**< @brief Adc channel  trigger in channel interrupt enable */
        .TrgIntEn         = STD_OFF,
        /**< @brief Adc channel trigger source select */
        .TrigSrc          = ADC_TRIG_SRC_SW,
        /**< @brief Adc channel trigger edge select */
        .TrigEdge         = ADC_HW_TRIG_RISING_EDGE,
        /**< @brief Adc channel cascade trigger select */
        .CTrig            = CTRIG_CHANNEL3,
        /**< @brief Adc channel priority select */
        .Priority         = ADC_PRIORITY_BEST_HIGH,
        /**< @brief Adc channel DMA configuration */
        .DmaConfig        =
        {
            /**< @brief DMA bus error enabled */
            STD_OFF,
            /**< @brief Adc DMA transfer count */
            1
        }
    },
    /**< @brief Hardware Unit ADC1  --   ADC1_CH_3 */
    {
        /**< @brief Adc physical channel */
        .ChId             = ADC1_CH_3,
        /**< @brief Adc righ shift num */
        .Shift            = 0,
        /**< @brief Adc over sample num */
        .SampNum          = 0,
        /**< @brief Adc channel ready interrupt enable */
        .ReadyIntEn       = STD_OFF,
        /**< @brief Adc channel fast sampling is enable */
        .FSampEn          = STD_OFF,
        /**< @brief Adc channel filtering enable */
        .FirEn            = STD_OFF,
        /**< @brief High threshold detection enabled */
        .HCompEn          = STD_OFF,
        /**< @brief Low threshold detection enabled */
        .LCompEn          = STD_OFF,
        /**< @brief High threshold detection interrupt enabled */
        .HCompIntEn       = STD_OFF,
        /**< @brief Low threshold detection interrupt enabled */
        .LCompIntEn       = STD_OFF,
        /**< @brief Adc channel high threshold */
        .ThresholdH       = 0,
        /**< @brief Adc channel low threshold */
        .ThresholdL       = 0,
        /**< @brief Adc channel trigger in dma interrupt enable */
        .TrgDmaIntEn      = STD_OFF,
         /**< @brief The Timeout error interrupt was enabled */
        .TimeoutIntEn     = STD_OFF,
        /**< @brief The comparison error interrupt was enabled */
        .CompIntEn        = STD_OFF,
        /**< @brief Adc channel  trigger in channel interrupt enable */
        .TrgIntEn         = STD_OFF,
        /**< @brief Adc channel trigger source select */
        .TrigSrc          = ADC_TRIG_SRC_SW,
        /**< @brief Adc channel trigger edge select */
        .TrigEdge         = ADC_HW_TRIG_RISING_EDGE,
        /**< @brief Adc channel cascade trigger select */
        .CTrig            = CTRIG_CHANNEL4,
        /**< @brief Adc channel priority select */
        .Priority         = ADC_PRIORITY_BEST_HIGH,
        /**< @brief Adc channel DMA configuration */
        .DmaConfig        =
        {
            /**< @brief DMA bus error enabled */
            STD_OFF,
            /**< @brief Adc DMA transfer count */
            1
        }
    },
    /**< @brief Hardware Unit ADC1  --   ADC1_CH_4 */
    {
        /**< @brief Adc physical channel */
        .ChId             = ADC1_CH_4,
        /**< @brief Adc righ shift num */
        .Shift            = 0,
        /**< @brief Adc over sample num */
        .SampNum          = 0,
        /**< @brief Adc channel ready interrupt enable */
        .ReadyIntEn       = STD_ON,
        /**< @brief Adc channel fast sampling is enable */
        .FSampEn          = STD_OFF,
        /**< @brief Adc channel filtering enable */
        .FirEn            = STD_OFF,
        /**< @brief High threshold detection enabled */
        .HCompEn          = STD_OFF,
        /**< @brief Low threshold detection enabled */
        .LCompEn          = STD_OFF,
        /**< @brief High threshold detection interrupt enabled */
        .HCompIntEn       = STD_OFF,
        /**< @brief Low threshold detection interrupt enabled */
        .LCompIntEn       = STD_OFF,
        /**< @brief Adc channel high threshold */
        .ThresholdH       = 0,
        /**< @brief Adc channel low threshold */
        .ThresholdL       = 0,
        /**< @brief Adc channel trigger in dma interrupt enable */
        .TrgDmaIntEn      = STD_OFF,
         /**< @brief The Timeout error interrupt was enabled */
        .TimeoutIntEn     = STD_OFF,
        /**< @brief The comparison error interrupt was enabled */
        .CompIntEn        = STD_OFF,
        /**< @brief Adc channel  trigger in channel interrupt enable */
        .TrgIntEn         = STD_OFF,
        /**< @brief Adc channel trigger source select */
        .TrigSrc          = ADC_TRIG_SRC_SW,
        /**< @brief Adc channel trigger edge select */
        .TrigEdge         = ADC_HW_TRIG_RISING_EDGE,
        /**< @brief Adc channel cascade trigger select */
        .CTrig            = 0,
        /**< @brief Adc channel priority select */
        .Priority         = ADC_PRIORITY_BEST_HIGH,
        /**< @brief Adc channel DMA configuration */
        .DmaConfig        =
        {
            /**< @brief DMA bus error enabled */
            STD_OFF,
            /**< @brief Adc DMA transfer count */
            1
        }
    },
    /**< @brief Hardware Unit ADC2  --   ADC2_CH_0 */
    {
        /**< @brief Adc physical channel */
        .ChId             = ADC2_CH_0,
        /**< @brief Adc righ shift num */
        .Shift            = 0,
        /**< @brief Adc over sample num */
        .SampNum          = 0,
        /**< @brief Adc channel ready interrupt enable */
        .ReadyIntEn       = STD_OFF,
        /**< @brief Adc channel fast sampling is enable */
        .FSampEn          = STD_OFF,
        /**< @brief Adc channel filtering enable */
        .FirEn            = STD_OFF,
        /**< @brief High threshold detection enabled */
        .HCompEn          = STD_OFF,
        /**< @brief Low threshold detection enabled */
        .LCompEn          = STD_OFF,
        /**< @brief High threshold detection interrupt enabled */
        .HCompIntEn       = STD_OFF,
        /**< @brief Low threshold detection interrupt enabled */
        .LCompIntEn       = STD_OFF,
        /**< @brief Adc channel high threshold */
        .ThresholdH       = 0,
        /**< @brief Adc channel low threshold */
        .ThresholdL       = 0,
        /**< @brief Adc channel trigger in dma interrupt enable */
        .TrgDmaIntEn      = STD_OFF,
         /**< @brief The Timeout error interrupt was enabled */
        .TimeoutIntEn     = STD_OFF,
        /**< @brief The comparison error interrupt was enabled */
        .CompIntEn        = STD_OFF,
        /**< @brief Adc channel  trigger in channel interrupt enable */
        .TrgIntEn         = STD_OFF,
        /**< @brief Adc channel trigger source select */
        .TrigSrc          = ADC_TRIG_SRC_SW,
        /**< @brief Adc channel trigger edge select */
        .TrigEdge         = ADC_HW_TRIG_RISING_EDGE,
        /**< @brief Adc channel cascade trigger select */
        .CTrig            = CTRIG_CHANNEL1,
        /**< @brief Adc channel priority select */
        .Priority         = ADC_PRIORITY_BEST_HIGH,
        /**< @brief Adc channel DMA configuration */
        .DmaConfig        =
        {
            /**< @brief DMA bus error enabled */
            STD_OFF,
            /**< @brief Adc DMA transfer count */
            1
        }
    },
    /**< @brief Hardware Unit ADC2  --   ADC2_CH_1 */
    {
        /**< @brief Adc physical channel */
        .ChId             = ADC2_CH_1,
        /**< @brief Adc righ shift num */
        .Shift            = 0,
        /**< @brief Adc over sample num */
        .SampNum          = 0,
        /**< @brief Adc channel ready interrupt enable */
        .ReadyIntEn       = STD_ON,
        /**< @brief Adc channel fast sampling is enable */
        .FSampEn          = STD_OFF,
        /**< @brief Adc channel filtering enable */
        .FirEn            = STD_OFF,
        /**< @brief High threshold detection enabled */
        .HCompEn          = STD_OFF,
        /**< @brief Low threshold detection enabled */
        .LCompEn          = STD_OFF,
        /**< @brief High threshold detection interrupt enabled */
        .HCompIntEn       = STD_OFF,
        /**< @brief Low threshold detection interrupt enabled */
        .LCompIntEn       = STD_OFF,
        /**< @brief Adc channel high threshold */
        .ThresholdH       = 0,
        /**< @brief Adc channel low threshold */
        .ThresholdL       = 0,
        /**< @brief Adc channel trigger in dma interrupt enable */
        .TrgDmaIntEn      = STD_OFF,
         /**< @brief The Timeout error interrupt was enabled */
        .TimeoutIntEn     = STD_OFF,
        /**< @brief The comparison error interrupt was enabled */
        .CompIntEn        = STD_OFF,
        /**< @brief Adc channel  trigger in channel interrupt enable */
        .TrgIntEn         = STD_OFF,
        /**< @brief Adc channel trigger source select */
        .TrigSrc          = ADC_TRIG_SRC_SW,
        /**< @brief Adc channel trigger edge select */
        .TrigEdge         = ADC_HW_TRIG_RISING_EDGE,
        /**< @brief Adc channel cascade trigger select */
        .CTrig            = 0,
        /**< @brief Adc channel priority select */
        .Priority         = ADC_PRIORITY_BEST_HIGH,
        /**< @brief Adc channel DMA configuration */
        .DmaConfig        =
        {
            /**< @brief DMA bus error enabled */
            STD_OFF,
            /**< @brief Adc DMA transfer count */
            1
        }
    }
};
/******************************************************************************
*                            Public Constants
*******************************************************************************/

/**
* @brief          AdcDrvConfigData.
* @details        Adc configuration.
*/
TT_CONST Adc_Drv_ConfigType AdcDrvConfigData =
{
    /**< @brief Adc Common configuration */
    .AdcCom = Adc_Drv_CommonConfigTypeData,
    /**< @brief Adc HW configuration */
    .AdcHwUinitConfig = Adc_Drv_HwConfigData,
    /**< @brief Adc channel configuration */
    .ChannelConfig = Adc_Drv_ChannelConfigData,
    /**< @brief Adc configuration crc check codes */
    .Crc             = 370U
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/


#ifdef __cplusplus
}
#endif

/** @} */

