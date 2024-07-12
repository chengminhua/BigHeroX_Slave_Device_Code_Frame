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
**  FILENAME     : Gtm_Hw_Interrupt.c                                         **
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
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                              Include Files
 ******************************************************************************/
#include "Gtm_Hw_Interrupt.h"

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define GTM_HW_INTERRUPT_VENDOR_ID_C                      1541
#define GTM_HW_INTERRUPT_MODULE_ID_C                      221
#define GTM_HW_INTERRUPT_AR_RELEASE_MAJOR_VERSION_C       4
#define GTM_HW_INTERRUPT_AR_RELEASE_MINOR_VERSION_C       4
#define GTM_HW_INTERRUPT_AR_RELEASE_PATCH_VERSION_C       0
#define GTM_HW_INTERRUPT_SW_MAJOR_VERSION_C               1
#define GTM_HW_INTERRUPT_SW_MINOR_VERSION_C               1
#define GTM_HW_INTERRUPT_SW_PATCH_VERSION_C               0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Gtm_Hw_Interrupt.c Gtm_Hw_Interrupt.h file version check */
#if (GTM_HW_INTERRUPT_VENDOR_ID_C != GTM_HW_INTERRUPT_VENDOR_ID_H)
    #error "Gtm_Hw_Interrupt.c and Gtm_Hw_Interrupt.h have different vendor ids"
#endif
#if (GTM_HW_INTERRUPT_MODULE_ID_C != GTM_HW_INTERRUPT_MODULE_ID_H)
    #error "Gtm_Hw_Interrupt.c and Gtm_Hw_Interrupt.h have different module ids"
#endif
#if ((GTM_HW_INTERRUPT_AR_RELEASE_MAJOR_VERSION_C != GTM_HW_INTERRUPT_AR_RELEASE_MAJOR_VERSION_H) || \
      (GTM_HW_INTERRUPT_AR_RELEASE_MINOR_VERSION_C != GTM_HW_INTERRUPT_AR_RELEASE_MINOR_VERSION_H) || \
      (GTM_HW_INTERRUPT_AR_RELEASE_PATCH_VERSION_C != GTM_HW_INTERRUPT_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Interrupt.c and Gtm_Hw_Interrupt.h are different"
#endif
#if ((GTM_HW_INTERRUPT_SW_MAJOR_VERSION_C != GTM_HW_INTERRUPT_SW_MAJOR_VERSION_H) || \
      (GTM_HW_INTERRUPT_SW_MINOR_VERSION_C != GTM_HW_INTERRUPT_SW_MINOR_VERSION_H) || \
      (GTM_HW_INTERRUPT_SW_PATCH_VERSION_C != GTM_HW_INTERRUPT_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Interrupt.c and Gtm_Hw_Interrupt.h are different"
#endif

/******************************************************************************
 *                          Defines And Macros.
 ******************************************************************************/

/******************************** TIM module  ********************************/
/**
* @brief        TIM_DEFINE
* @details      Tim configuration link macro
* @param[in]    instance : instance number
* @param[in]    ch       : Channel number
* @param[in]    field    : Bit-band name
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define TIM_DEFINE(instance, ch, field) TT_GTM_TIM##instance##_CH##ch##_##field

/**
* @brief        TIM_IRQ_DEFINE
* @details      Tim interrupt configuration link macro
* @param[in]    instance : instance number
* @param[in]    ch       : Channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define TIM_IRQ_DEFINE(instance, ch) TT_GTM_TIM##instance##_CH##ch##_IRQ_MODE

/**
* @brief        TIM_INTERRUPT_CONFIG
* @details      Tim interrupt configuration macro
* @param[in]    base     : Tim parameter structure pointer
* @param[in]    instance : instance number
* @param[in]    ch       : Channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define TIM_INTERRUPT_CONFIG(base, instance, ch) \
do{ \
    /* Set new value interrupt.*/ \
    base->timChannel->EIRQ_EN.B.NEWVAL_EIRQ_EN    = TIM_DEFINE(instance, ch, NEWVAL_IRQ_EN); \
    base->timChannel->IRQ_EN.B.NEWVAL_IRQ_EN      = TIM_DEFINE(instance, ch, NEWVAL_IRQ_EN); \
    /* Set ecnt overflow interrupt.*/ \
    base->timChannel->EIRQ_EN.B.ECNTOFL_EIRQ_EN   = TIM_DEFINE(instance, ch, ECNTOFL_IRQ_EN); \
    base->timChannel->IRQ_EN.B.ECNTOFL_IRQ_EN     = TIM_DEFINE(instance, ch, ECNTOFL_IRQ_EN); \
    /* Set cnt overflow interrupt.*/ \
    base->timChannel->EIRQ_EN.B.CNTOFL_EIRQ_EN    = TIM_DEFINE(instance, ch, CNTOFL_IRQ_EN);  \
    base->timChannel->IRQ_EN.B.CNTOFL_IRQ_EN      = TIM_DEFINE(instance, ch, CNTOFL_IRQ_EN);  \
    /* Set gpr0 overflow interrupt.*/ \
    base->timChannel->EIRQ_EN.B.GPROFL_EIRQ_EN    = TIM_DEFINE(instance, ch, GPROFL_IRQ_EN);  \
    base->timChannel->IRQ_EN.B.GPROFL_IRQ_EN      = TIM_DEFINE(instance, ch, GPROFL_IRQ_EN);  \
    /* Set todet overflow interrupt.*/ \
    base->timChannel->EIRQ_EN.B.TODET_EIRQ_EN     = TIM_DEFINE(instance, ch, TODET_IRQ_EN);   \
    base->timChannel->IRQ_EN.B.TODET_IRQ_EN       = TIM_DEFINE(instance, ch, TODET_IRQ_EN);   \
    /* Set glitch overflow interrupt.*/ \
    base->timChannel->EIRQ_EN.B.GLITCHDET_EIRQ_EN = TIM_DEFINE(instance, ch, GLITCHDET_IRQ_EN); \
    base->timChannel->IRQ_EN.B.GLITCHDET_IRQ_EN   = TIM_DEFINE(instance, ch, GLITCHDET_IRQ_EN); \
    /* Set interrupt mode.*/ \
    base->timChannel->IRQ_MODE.B.IRQ_MODE           = TIM_IRQ_DEFINE(instance,ch);\
}while(FALSE);

/**
* @brief        TIM_INTERRUPT_CONFIG_CHECK
* @details      Tim interrupt configuration check macro 
* @param[in]    base     : Tim parameter structure pointer
* @param[in]    instance : instance number
* @param[in]    ch       : Channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define TIM_INTERRUPT_CONFIG_CHECK(base, instance, ch) \
do{ \
    GTM_REG_CHECK(base->timChannel->EIRQ_EN.B.NEWVAL_EIRQ_EN   , TIM_DEFINE(instance, ch, NEWVAL_IRQ_EN)); \
    GTM_REG_CHECK(base->timChannel->IRQ_EN.B.NEWVAL_IRQ_EN     , TIM_DEFINE(instance, ch, NEWVAL_IRQ_EN)); \
    GTM_REG_CHECK(base->timChannel->EIRQ_EN.B.ECNTOFL_EIRQ_EN  , TIM_DEFINE(instance, ch, ECNTOFL_IRQ_EN)); \
    GTM_REG_CHECK(base->timChannel->IRQ_EN.B.ECNTOFL_IRQ_EN    , TIM_DEFINE(instance, ch, ECNTOFL_IRQ_EN)); \
    GTM_REG_CHECK(base->timChannel->EIRQ_EN.B.CNTOFL_EIRQ_EN   , TIM_DEFINE(instance, ch, CNTOFL_IRQ_EN));  \
    GTM_REG_CHECK(base->timChannel->IRQ_EN.B.CNTOFL_IRQ_EN     , TIM_DEFINE(instance, ch, CNTOFL_IRQ_EN));  \
    GTM_REG_CHECK(base->timChannel->EIRQ_EN.B.GPROFL_EIRQ_EN   , TIM_DEFINE(instance, ch, GPROFL_IRQ_EN));  \
    GTM_REG_CHECK(base->timChannel->IRQ_EN.B.GPROFL_IRQ_EN     , TIM_DEFINE(instance, ch, GPROFL_IRQ_EN));  \
    GTM_REG_CHECK(base->timChannel->EIRQ_EN.B.TODET_EIRQ_EN    , TIM_DEFINE(instance, ch, TODET_IRQ_EN));   \
    GTM_REG_CHECK(base->timChannel->IRQ_EN.B.TODET_IRQ_EN      , TIM_DEFINE(instance, ch, TODET_IRQ_EN));   \
    GTM_REG_CHECK(base->timChannel->EIRQ_EN.B.GLITCHDET_EIRQ_EN, TIM_DEFINE(instance, ch, GLITCHDET_IRQ_EN)); \
    GTM_REG_CHECK(base->timChannel->IRQ_EN.B.GLITCHDET_IRQ_EN  , TIM_DEFINE(instance, ch, GLITCHDET_IRQ_EN)); \
    GTM_REG_CHECK(base->timChannel->IRQ_MODE.B.IRQ_MODE        , TIM_IRQ_DEFINE(instance,ch));\
}while(FALSE);

/******************************** TOM module  ********************************/
/**
* @brief        TOM_DEFINE
* @details      Tom configuration link macro
* @param[in]    instance : instance number
* @param[in]    ch       : Channel number
* @param[in]    field    : Bit-band name
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define TOM_DEFINE(instance, ch, field) TT_GTM_TOM##instance##_CH##ch##_##field

/**
* @brief        TOM_IRQ_DEFINE
* @details      Tom interrupt configuration link macro
* @param[in]    instance : instance number
* @param[in]    ch       : Channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define TOM_IRQ_DEFINE(instance, ch) TT_GTM_TOM##instance##_CH##ch##_IRQ_MODE

/**
* @brief        TOM_INTERRUPT_CONFIG
* @details      Tom interrupt configuration macro
* @param[in]    base     : Tim parameter structure pointer
* @param[in]    instance : instance number
* @param[in]    ch       : Channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define TOM_INTERRUPT_CONFIG(base, instance, ch) \
do{ \
    /* Set ccu0 interrupt.*/ \
    base->tomChannel->IRQ_EN.B.CCU0TC_IRQ_EN = TOM_DEFINE(instance, ch, CCU0TC_IRQ_EN); \
    /* Set ccu1 interrupt.*/ \
    base->tomChannel->IRQ_EN.B.CCU1TC_IRQ_EN = TOM_DEFINE(instance, ch, CCU1TC_IRQ_EN); \
    /* Set interrupt mode.*/ \
    base->tomChannel->IRQ_MODE.B.IRQ_MODE    = TOM_IRQ_DEFINE(instance, ch);\
}while(FALSE);

/**
* @brief        TOM_INTERRUPT_CONFIG_CHECK
* @details      Tom interrupt configuration check macro 
* @param[in]    base     : Tim parameter structure pointer
* @param[in]    instance : instance number
* @param[in]    ch       : Channel number
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define TOM_INTERRUPT_CONFIG_CHECK(base, instance, ch) \
do{ \
    GTM_REG_CHECK(base->tomChannel->IRQ_EN.B.CCU0TC_IRQ_EN, TOM_DEFINE(instance, ch, CCU0TC_IRQ_EN)); \
    GTM_REG_CHECK(base->tomChannel->IRQ_EN.B.CCU1TC_IRQ_EN, TOM_DEFINE(instance, ch, CCU1TC_IRQ_EN)); \
    GTM_REG_CHECK(base->tomChannel->IRQ_MODE.B.IRQ_MODE   , TOM_IRQ_DEFINE(instance, ch));\
}while(FALSE);

/******************************************************************************
 *                       Global Variables Declaration
 ******************************************************************************/
/* Tim interrupt flag back */
extern GTM_TIM_CH_IRQ_NOTIFY_bf_type Tim_PubNotifyFlag;

#define GTM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"

/***************** TIM0 channel 0-3 Global Variable  *****************/
/**
 * @brief   Tim0 channel 0 driver identifier.
 */
#if (defined(TT_GTM_TIM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH0_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM0CH0INT =
{
    .timChannel = &TT_GTM->TIM0.CH[0],
    .timNotifacation = TT_GTM_TIM0_CH0_NOTIFICATION
};
#endif

/**
 * @brief   Tim0 channel 1 driver identifier.
 */
#if (defined(TT_GTM_TIM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH1_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM0CH1INT =
{
    .timChannel = &TT_GTM->TIM0.CH[1],
    .timNotifacation = TT_GTM_TIM0_CH1_NOTIFICATION
};
#endif

/**
 * @brief   Tim0 channel 2 driver identifier.
 */
#if (defined(TT_GTM_TIM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH2_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM0CH2INT =
{
    .timChannel = &TT_GTM->TIM0.CH[2],
    .timNotifacation = TT_GTM_TIM0_CH2_NOTIFICATION
};
#endif

/**
 * @brief   Tim0 channel 3 driver identifier.
 */
#if (defined(TT_GTM_TIM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH3_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM0CH3INT =
{
    .timChannel = &TT_GTM->TIM0.CH[3],
    .timNotifacation = TT_GTM_TIM0_CH3_NOTIFICATION
};
#endif
/***************** TIM0 channel 4-7 Global Variable  *****************/
/**
 * @brief   Tim0 channel 4 driver identifier.
 */
#if (defined(TT_GTM_TIM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH4_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM0CH4INT =
{
    .timChannel = &TT_GTM->TIM0.CH[4],
    .timNotifacation = TT_GTM_TIM0_CH4_NOTIFICATION
};
#endif

/**
 * @brief   Tim0 channel 5 driver identifier.
 */
#if (defined(TT_GTM_TIM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH5_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM0CH5INT =
{
    .timChannel = &TT_GTM->TIM0.CH[5],
    .timNotifacation = TT_GTM_TIM0_CH5_NOTIFICATION
};
#endif

/**
 * @brief   Tim0 channel 6 driver identifier.
 */
#if (defined(TT_GTM_TIM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH6_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM0CH6INT =
{
    .timChannel = &TT_GTM->TIM0.CH[6],
    .timNotifacation = TT_GTM_TIM0_CH6_NOTIFICATION
};
#endif

/**
 * @brief   Tim0 channel 7 driver identifier.
 */
#if (defined(TT_GTM_TIM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH7_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM0CH7INT =
{
    .timChannel = &TT_GTM->TIM0.CH[7],
    .timNotifacation = TT_GTM_TIM0_CH7_NOTIFICATION
};
#endif

/***************** TIM1 channel 0-3 Global Variable  *****************/
/**
 * @brief   Tim1 channel 0 driver identifier.
 */
#if (defined(TT_GTM_TIM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH0_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM1CH0INT =
{
    .timChannel = &TT_GTM->TIM1.CH[0],
    .timNotifacation = TT_GTM_TIM1_CH0_NOTIFICATION
};
#endif

/**
 * @brief   Tim1 channel 1 driver identifier.
 */
#if (defined(TT_GTM_TIM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH1_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM1CH1INT =
{
    .timChannel = &TT_GTM->TIM1.CH[1],
    .timNotifacation = TT_GTM_TIM1_CH1_NOTIFICATION
};
#endif

/**
 * @brief   Tim1 channel 2 driver identifier.
 */
#if (defined(TT_GTM_TIM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH2_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM1CH2INT =
{
    .timChannel = &TT_GTM->TIM1.CH[2],
    .timNotifacation = TT_GTM_TIM1_CH2_NOTIFICATION
};
#endif

/**
 * @brief   Tim1 channel 3 driver identifier.
 */
#if (defined(TT_GTM_TIM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH3_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM1CH3INT =
{
    .timChannel = &TT_GTM->TIM1.CH[3],
    .timNotifacation = TT_GTM_TIM1_CH3_NOTIFICATION
};
#endif

/***************** TIM1 channel 4-7 Global Variable  *****************/
/**
 * @brief   Tim1 channel 4 driver identifier.
 */
#if (defined(TT_GTM_TIM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH4_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM1CH4INT =
{
    .timChannel = &TT_GTM->TIM1.CH[4],
    .timNotifacation = TT_GTM_TIM1_CH4_NOTIFICATION
};
#endif

/**
 * @brief   Tim1 channel 5 driver identifier.
 */
#if (defined(TT_GTM_TIM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH5_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM1CH5INT =
{
    .timChannel = &TT_GTM->TIM1.CH[5],
    .timNotifacation = TT_GTM_TIM1_CH5_NOTIFICATION
};
#endif

/**
 * @brief   Tim1 channel 6 driver identifier.
 */
#if (defined(TT_GTM_TIM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH6_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM1CH6INT =
{
    .timChannel = &TT_GTM->TIM1.CH[6],
    .timNotifacation = TT_GTM_TIM1_CH6_NOTIFICATION
};
#endif

/**
 * @brief   Tim1 channel 7 driver identifier.
 */
#if (defined(TT_GTM_TIM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH7_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM1CH7INT =
{
    .timChannel = &TT_GTM->TIM1.CH[7],
    .timNotifacation = TT_GTM_TIM1_CH7_NOTIFICATION
};
#endif

/***************** TIM2 channel 0-3 Global Variable  *****************/
/**
 * @brief   Tim2 channel 0 driver identifier.
 */
#if (defined(TT_GTM_TIM2_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH0_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM2CH0INT =
{
    .timChannel = &TT_GTM->TIM2.CH[0],
    .timNotifacation = TT_GTM_TIM2_CH0_NOTIFICATION
};
#endif

/**
 * @brief   Tim2 channel 1 driver identifier.
 */
#if (defined(TT_GTM_TIM2_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH1_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM2CH1INT =
{
    .timChannel = &TT_GTM->TIM2.CH[1],
    .timNotifacation = TT_GTM_TIM2_CH1_NOTIFICATION
};
#endif

/**
 * @brief   Tim2 channel 2 driver identifier.
 */
#if (defined(TT_GTM_TIM2_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH2_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM2CH2INT =
{
    .timChannel = &TT_GTM->TIM2.CH[2],
    .timNotifacation = TT_GTM_TIM2_CH2_NOTIFICATION
};
#endif

/**
 * @brief   Tim2 channel 3 driver identifier.
 */
#if (defined(TT_GTM_TIM2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH3_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM2CH3INT =
{
    .timChannel = &TT_GTM->TIM2.CH[3],
    .timNotifacation = TT_GTM_TIM2_CH3_NOTIFICATION
};
#endif

/***************** TIM2 channel 4-7 Global Variable  *****************/
/**
 * @brief   Tim2 channel 4 driver identifier.
 */
#if (defined(TT_GTM_TIM2_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH4_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM2CH4INT =
{
    .timChannel = &TT_GTM->TIM2.CH[4],
    .timNotifacation = TT_GTM_TIM2_CH4_NOTIFICATION
};
#endif

/**
 * @brief   Tim2 channel 5 driver identifier.
 */
#if (defined(TT_GTM_TIM2_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH5_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM2CH5INT =
{
    .timChannel = &TT_GTM->TIM2.CH[5],
    .timNotifacation = TT_GTM_TIM2_CH5_NOTIFICATION
};
#endif

/**
 * @brief   Tim2 channel 6 driver identifier.
 */
#if (defined(TT_GTM_TIM2_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH6_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM2CH6INT =
{
    .timChannel = &TT_GTM->TIM2.CH[6],
    .timNotifacation = TT_GTM_TIM2_CH6_NOTIFICATION
};
#endif

/**
 * @brief   Tim2 channel 7 driver identifier.
 */
#if (defined(TT_GTM_TIM2_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH7_INTERRUPT_ENABLE == TRUE))
static Gtm_TimIntInfoType TIM2CH7INT =
{
    .timChannel = &TT_GTM->TIM2.CH[7],
    .timNotifacation = TT_GTM_TIM2_CH7_NOTIFICATION
};
#endif

/***************** TOM0 channel 0-7 Global Variable  *****************/
#if (defined(TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom0 channel 0 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH0INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[0],
    .tomNotifacation = TT_GTM_TOM0_CH0_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH0_INTERRUPT_ENABLE */

/**
 * @brief   Tom0 channel 1 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH1_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH1INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[1],
    .tomNotifacation = TT_GTM_TOM0_CH1_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH1_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE) &&  (TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom0 channel 2 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH2INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[2],
    .tomNotifacation = TT_GTM_TOM0_CH2_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH2_INTERRUPT_ENABLE */

/**
 * @brief   Tim0 channel 3 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH3_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH3INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[3],
    .tomNotifacation = TT_GTM_TOM0_CH3_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH3_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE) &&  (TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE  == TRUE))
/**
 * @brief   Tom0 channel 4 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH4INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[4],
    .tomNotifacation = TT_GTM_TOM0_CH4_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH4_INTERRUPT_ENABLE */

/**
 * @brief   Tom0 channel 5 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH5_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH5INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[5],
    .tomNotifacation = TT_GTM_TOM0_CH5_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH5_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE) &&  (TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom0 channel 6 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH6INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[6],
    .tomNotifacation = TT_GTM_TOM0_CH6_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH6_INTERRUPT_ENABLE */

/**
 * @brief   Tim0 channel 7 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH7_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH7INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[7],
    .tomNotifacation = TT_GTM_TOM0_CH7_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH7_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE */

/***************** TOM0 channel 8-15 Global Variable *****************/
#if (defined(TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE) &&  (TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom0 channel 8 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH8INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[8],
    .tomNotifacation = TT_GTM_TOM0_CH8_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH8_INTERRUPT_ENABLE */

/**
 * @brief   Tom0 channel 9 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH9_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH9INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[9],
    .tomNotifacation = TT_GTM_TOM0_CH9_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH9_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE) &&  (TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom0 channel 10 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH10INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[10],
    .tomNotifacation = TT_GTM_TOM0_CH10_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH10_INTERRUPT_ENABLE */

/**
 * @brief   Tim0 channel 11 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH11_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH11INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[11],
    .tomNotifacation = TT_GTM_TOM0_CH11_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH11_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE) &&  (TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom0 channel 12 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH12INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[12],
    .tomNotifacation = TT_GTM_TOM0_CH12_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH12_INTERRUPT_ENABLE */

/**
 * @brief   Tom0 channel 13 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH13_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH13INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[13],
    .tomNotifacation = TT_GTM_TOM0_CH13_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH13_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE) &&  (TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom0 channel 14 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH14INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[14],
    .tomNotifacation = TT_GTM_TOM0_CH14_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH14_INTERRUPT_ENABLE */

/**
 * @brief   Tim0 channel 15 driver identifier.
 */
#if (defined(TT_GTM_TOM0_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH15_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM0CH15INT =
{
    .tomChannel = &TT_GTM->TOM0.CH[15],
    .tomNotifacation = TT_GTM_TOM0_CH15_NOTIFICATION
};
#endif /* TT_GTM_TOM0_CH15_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE */

/***************** TOM1 channel 0-7 Global Variable  *****************/
#if (defined(TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE) &&  (TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom1 channel 0 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH0INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[0],
    .tomNotifacation = TT_GTM_TOM1_CH0_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH0_INTERRUPT_ENABLE */

/**
 * @brief   Tom1 channel 1 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH1_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH1INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[1],
    .tomNotifacation = TT_GTM_TOM1_CH1_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH1_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE) &&  (TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom1 channel 2 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH2INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[2],
    .tomNotifacation = TT_GTM_TOM1_CH2_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH2_INTERRUPT_ENABLE */

/**
 * @brief   Tom1 channel 3 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH3_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH3INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[3],
    .tomNotifacation = TT_GTM_TOM1_CH3_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH3_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE) &&  (TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom1 channel 4 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH4INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[4],
    .tomNotifacation = TT_GTM_TOM1_CH4_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH4_INTERRUPT_ENABLE */

/**
 * @brief   Tom1 channel 5 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH5_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH5INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[5],
    .tomNotifacation = TT_GTM_TOM1_CH5_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH5_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE) &&  (TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom1 channel 6 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH6INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[6],
    .tomNotifacation = TT_GTM_TOM1_CH6_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH6_INTERRUPT_ENABLE */

/**
 * @brief   Tom1 channel 7 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH7_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH7INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[7],
    .tomNotifacation = TT_GTM_TOM1_CH7_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH7_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE */

/***************** TOM1 channel 8-15 Global Variable *****************/
#if (defined(TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE) &&  (TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom1 channel 8 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH8INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[8],
    .tomNotifacation = TT_GTM_TOM1_CH8_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH8_INTERRUPT_ENABLE */

/**
 * @brief   Tom1 channel 9 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH9_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH9INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[9],
    .tomNotifacation = TT_GTM_TOM1_CH9_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH9_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE) &&  (TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom1 channel 10 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH10INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[10],
    .tomNotifacation = TT_GTM_TOM1_CH10_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH10_INTERRUPT_ENABLE */

/**
 * @brief   Tom1 channel 11 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH11_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH11INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[11],
    .tomNotifacation = TT_GTM_TOM1_CH11_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH11_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE) &&  (TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom1 channel 12 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH12INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[12],
    .tomNotifacation = TT_GTM_TOM1_CH12_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH12_INTERRUPT_ENABLE */

/**
 * @brief   Tom1 channel 13 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH13_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH13INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[13],
    .tomNotifacation = TT_GTM_TOM1_CH13_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH13_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE) &&  (TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE == TRUE))
/**
 * @brief   Tom1 channel 14 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH14INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[14],
    .tomNotifacation = TT_GTM_TOM1_CH14_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH14_INTERRUPT_ENABLE */

/**
 * @brief   Tom1 channel 15 driver identifier.
 */
#if (defined(TT_GTM_TOM1_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH15_INTERRUPT_ENABLE == TRUE))
static Gtm_TomIntInfoType TOM1CH15INT =
{
    .tomChannel = &TT_GTM->TOM1.CH[15],
    .tomNotifacation = TT_GTM_TOM1_CH15_NOTIFICATION
};
#endif /* TT_GTM_TOM1_CH15_INTERRUPT_ENABLE */
#endif /* TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE */

#define GTM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"

/******************************************************************************
 *                             Private Variables
 ******************************************************************************/

/******************************************************************************
 *                        Private Function Declaration
 ******************************************************************************/
/**
* @brief        Gtm_Hw_Interrupt_TimIntInitCheck
* @details      Tim channel interrupt initialization check. 
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_PriTimIntInitCheck(void);

/**
* @brief        Gtm_Hw_Interrupt_TomIntInitCheck
* @details      Tom channel interrupt initialization check. 
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_PriTomIntInitCheck(void);

/******************************************************************************
 *                             Private Function
 ******************************************************************************/

#define GTM_START_SEC_CODE_FAST
#include "Gtm_MemMap.h"

#if (defined(TT_GTM_TIM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH0_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH1_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH2_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH3_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH4_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH5_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH6_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH7_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH0_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH1_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH2_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH3_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH4_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH5_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH6_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH7_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM2_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH0_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM2_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH1_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM2_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH2_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH3_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM2_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH4_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM2_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH5_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM2_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH6_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TIM2_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH7_INTERRUPT_ENABLE == TRUE))

/**
* @brief        Gtm_TimChannelIntHandler
* @details      Tim channel interrupt service function. 
* @param[in]    timInt : Tim parameter structure pointer
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_TimChannelIntHandler(TT_CONST Gtm_TimIntInfoType* timInt)
{
    uint8 event = 0;

    /* Back up the Tim notify flag */
    Tim_PubNotifyFlag.R = timInt->timChannel->IRQ_NOTIFY.R;

    if((timInt->timChannel->IRQ_EN.B.NEWVAL_IRQ_EN == TIM_INTTERRUPT_ENABLE) &&
       (timInt->timChannel->IRQ_NOTIFY.B.NEWVAL == 0x1U))
    {
        event |= TIM_NEWVAL_EVENT;
    }
    else
    {
        /* do nothing */
    }

    if((timInt->timChannel->IRQ_EN.B.ECNTOFL_IRQ_EN == TIM_INTTERRUPT_ENABLE) &&
       (timInt->timChannel->IRQ_NOTIFY.B.ECNTOFL == 0x1U))
    {
        event |= TIM_ECNTOFL_EVENT;
    }
    else
    {
        /* do nothing */
    }

    if((timInt->timChannel->IRQ_EN.B.CNTOFL_IRQ_EN == TIM_INTTERRUPT_ENABLE) &&
       (timInt->timChannel->IRQ_NOTIFY.B.CNTOFL == 0x1U))
    {
        event |= TIM_CNTOFL_EVENT;
    }
    else
    {
        /* do nothing */
    }

    if((timInt->timChannel->IRQ_EN.B.GPROFL_IRQ_EN == TIM_INTTERRUPT_ENABLE) &&
       (timInt->timChannel->IRQ_NOTIFY.B.GPROFL == 0x1U))
    {
        event |= TIM_GPROFL_EVENT;
    }
    else
    {
        /* do nothing */
    }

    if((timInt->timChannel->IRQ_EN.B.TODET_IRQ_EN == TIM_INTTERRUPT_ENABLE) &&
       (timInt->timChannel->IRQ_NOTIFY.B.TODET == 0x1U))
    {
        event |= TIM_TODET_EVENT;
    }
    else
    {
        /* do nothing */
    }

    if((timInt->timChannel->IRQ_EN.B.GLITCHDET_IRQ_EN == TIM_INTTERRUPT_ENABLE) &&
       (timInt->timChannel->IRQ_NOTIFY.B.GLITCHDET == 0x1U))
    {
        event |= TIM_GLITCHDET_EVENT;
    }
    else
    {
        /* do nothing */
    }

    if(0 != event)
    {
        /* Clear interrupt flags */
        timInt->timChannel->IRQ_NOTIFY.R = event;

        if((NULL_PTR != timInt->timNotifacation))
        {
            timInt->timNotifacation(event);
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
}
#endif

#if (defined(TT_GTM_TOM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH1_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH3_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH5_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH7_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH9_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH11_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH13_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM0_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH15_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH1_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH3_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH5_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH7_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH9_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH11_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH13_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_INTERRUPT_ENABLE == TRUE)) || \
    (defined(TT_GTM_TOM1_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH15_INTERRUPT_ENABLE == TRUE))

/**
* @brief        Gtm_TomChannelIntHandler
* @details      Tom channel interrupt service function. 
* @param[in]    tomInt : Tim parameter structure pointer
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_TomChannelIntHandler(TT_CONST Gtm_TomIntInfoType* tomInt)
{
    uint8 event = 0;

    if((tomInt->tomChannel->IRQ_EN.B.CCU0TC_IRQ_EN == TOM_INTTERRUPT_ENABLE) &&
       (tomInt->tomChannel->IRQ_NOTIFY.B.CCU0TC == 0x1U))
    {
        event |= TOM_CCU0TC_EVENT;
    }
    else
    {

    }

    if((tomInt->tomChannel->IRQ_EN.B.CCU1TC_IRQ_EN == TOM_INTTERRUPT_ENABLE) &&
       (tomInt->tomChannel->IRQ_NOTIFY.B.CCU1TC == 0x1U))
    {
        event |= TOM_CCU1TC_EVENT;
    }
    else
    {
        /* do nothing */
    }

    if((0 != event))
    {
        /* Clear interrupt flags */
        tomInt->tomChannel->IRQ_NOTIFY.R = event;

        if(NULL_PTR != tomInt->tomNotifacation)
        {
            tomInt->tomNotifacation(event);
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

}
#endif
/******************************************************************************
 *                            Public Functions
 ******************************************************************************/

/************************ TIM Interrupt Function  ****************************/

/**
* @brief        Gtm_Hw_Interrupt_TimIntInit
* @details      Tim channel interrupt initialization. 
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_TimIntInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /***************** TIM0 channel 0-3 interrupt set  *******************/
#if (defined(TT_GTM_TIM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH0_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM0CH0INT), 0, 0);
#endif

#if (defined(TT_GTM_TIM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH1_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM0CH1INT), 0, 1);
#endif

#if (defined(TT_GTM_TIM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH2_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM0CH2INT), 0, 2);
#endif

#if (defined(TT_GTM_TIM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH3_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM0CH3INT), 0, 3);
#endif

    /***************** TIM0 channel 4-7 interrupt set  *******************/
#if (defined(TT_GTM_TIM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH4_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM0CH4INT), 0, 4);
#endif

#if (defined(TT_GTM_TIM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH5_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM0CH5INT), 0, 5);
#endif

#if (defined(TT_GTM_TIM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH6_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM0CH6INT), 0, 6);
#endif

#if (defined(TT_GTM_TIM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH7_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM0CH7INT), 0, 7);
#endif

    /***************** TIM1 channel 0-3 interrupt set  *******************/
#if (defined(TT_GTM_TIM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH0_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM1CH0INT), 1, 0);
#endif

#if (defined(TT_GTM_TIM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH1_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM1CH1INT), 1, 1);
#endif

#if (defined(TT_GTM_TIM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH2_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM1CH2INT), 1, 2);
#endif

#if (defined(TT_GTM_TIM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH3_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM1CH3INT), 1, 3);
#endif

    /***************** TIM1 channel 4-7 interrupt set  *******************/
#if (defined(TT_GTM_TIM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH4_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM1CH4INT), 1, 4);
#endif

#if (defined(TT_GTM_TIM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH5_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM1CH5INT), 1, 5);
#endif

#if (defined(TT_GTM_TIM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH6_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM1CH6INT), 1, 6);
#endif

#if (defined(TT_GTM_TIM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH7_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM1CH7INT), 1, 7);
#endif

    /***************** TIM2 channel 0-3 interrupt set  *******************/
#if (defined(TT_GTM_TIM2_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH0_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM2CH0INT), 2, 0);
#endif

#if (defined(TT_GTM_TIM2_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH1_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM2CH1INT), 2, 1);
#endif

#if (defined(TT_GTM_TIM2_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH2_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM2CH2INT), 2, 2);
#endif

#if (defined(TT_GTM_TIM2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH3_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM2CH3INT), 2, 3);
#endif

    /***************** TIM2 channel 4-7 interrupt set  *******************/
#if (defined(TT_GTM_TIM2_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH4_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM2CH4INT), 2, 4);
#endif

#if (defined(TT_GTM_TIM2_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH5_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM2CH5INT), 2, 5);
#endif

#if (defined(TT_GTM_TIM2_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH6_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM2CH6INT), 2, 6);
#endif

#if (defined(TT_GTM_TIM2_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH7_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG((&TIM2CH7INT), 2, 7);
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    Ret = Gtm_Hw_Interrupt_PriTimIntInitCheck();
#else
    (void)Ret;
#endif

    return Ret;
}

/*************** Tim0 channel 0 interrupt handler ***************/
#if (defined(TT_GTM_TIM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH0_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_0_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM0CH0INT);
}
#endif /* TT_GTM_TIM0_CH0_INTERRUPT_ENABLE */

/*************** Tim0 channel 1 interrupt handler ***************/
#if (defined(TT_GTM_TIM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_1_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM0CH1INT);
}
#endif /* TT_GTM_TIM0_CH1_INTERRUPT_ENABLE */

/*************** Tim0 channel 2 interrupt handler ***************/
#if (defined(TT_GTM_TIM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH2_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_2_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM0CH2INT);
}
#endif /* TT_GTM_TIM0_CH2_INTERRUPT_ENABLE */

/*************** Tim0 channel 3 interrupt handler ***************/
#if (defined(TT_GTM_TIM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_3_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM0CH3INT);
}
#endif /* TT_GTM_TIM0_CH3_INTERRUPT_ENABLE */

/*************** Tim0 channel 4 interrupt handler ***************/
#if (defined(TT_GTM_TIM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH4_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_4_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM0CH4INT);
}
#endif /* TT_GTM_TIM0_CH4_INTERRUPT_ENABLE */

/*************** Tim0 channel 5 interrupt handler ***************/
#if (defined(TT_GTM_TIM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_5_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM0CH5INT);
}
#endif /* TT_GTM_TIM0_CH5_INTERRUPT_ENABLE */

/*************** Tim0 channel 6 interrupt handler ***************/
#if (defined(TT_GTM_TIM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH6_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_6_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM0CH6INT);
}
#endif /* TT_GTM_TIM0_CH6_INTERRUPT_ENABLE */

/*************** Tim0 channel 7 interrupt handler ***************/
#if (defined(TT_GTM_TIM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM0_7_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM0CH7INT);
}
#endif /* TT_GTM_TIM0_CH7_INTERRUPT_ENABLE */

/*************** Tim1 channel 0 interrupt handler ***************/
#if (defined(TT_GTM_TIM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH0_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_0_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM1CH0INT);
}
#endif /* TT_GTM_TIM1_CH0_INTERRUPT_ENABLE */

/*************** Tim1 channel 1 interrupt handler ***************/
#if (defined(TT_GTM_TIM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_1_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM1CH1INT);
}
#endif /* TT_GTM_TIM1_CH1_INTERRUPT_ENABLE */

/*************** Tim1 channel 2 interrupt handler ***************/
#if (defined(TT_GTM_TIM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH2_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_2_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM1CH2INT);
}
#endif /* TT_GTM_TIM1_CH2_INTERRUPT_ENABLE */

/*************** Tim1 channel 3 interrupt handler ***************/
#if (defined(TT_GTM_TIM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_3_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM1CH3INT);
}
#endif /* TT_GTM_TIM1_CH3_INTERRUPT_ENABLE */

/*************** Tim1 channel 4 interrupt handler ***************/
#if (defined(TT_GTM_TIM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH4_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_4_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM1CH4INT);
}
#endif /* TT_GTM_TIM1_CH4_INTERRUPT_ENABLE */

/*************** Tim1 channel 5 interrupt handler ***************/
#if (defined(TT_GTM_TIM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_5_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM1CH5INT);
}
#endif /* TT_GTM_TIM1_CH5_INTERRUPT_ENABLE */

/*************** Tim1 channel 6 interrupt handler ***************/
#if (defined(TT_GTM_TIM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH6_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_6_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM1CH6INT);
}
#endif /* TT_GTM_TIM1_CH6_INTERRUPT_ENABLE */

/*************** Tim1 channel 7 interrupt handler ***************/
#if (defined(TT_GTM_TIM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM1_7_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM1CH7INT);
}
#endif /* TT_GTM_TIM1_CH7_INTERRUPT_ENABLE */

/*************** Tim2 channel 0 interrupt handler ***************/
#if (defined(TT_GTM_TIM2_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH0_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_0_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM2CH0INT);
}
#endif /* TT_GTM_TIM2_CH0_INTERRUPT_ENABLE */

/*************** Tim2 channel 1 interrupt handler ***************/
#if (defined(TT_GTM_TIM2_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_1_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM2CH1INT);
}
#endif /* TT_GTM_TIM2_CH1_INTERRUPT_ENABLE */

/*************** Tim2 channel 2 interrupt handler ***************/
#if (defined(TT_GTM_TIM2_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH2_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_2_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM2CH2INT);
}
#endif /* TT_GTM_TIM2_CH2_INTERRUPT_ENABLE */

/*************** Tim2 channel 3 interrupt handler ***************/
#if (defined(TT_GTM_TIM2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_3_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM2CH3INT);
}
#endif /* TT_GTM_TIM2_CH3_INTERRUPT_ENABLE */

/*************** Tim2 channel 4 interrupt handler ***************/
#if (defined(TT_GTM_TIM2_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH4_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_4_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM2CH4INT);
}
#endif /* TT_GTM_TIM2_CH4_INTERRUPT_ENABLE */

/*************** Tim2 channel 5 interrupt handler ***************/
#if (defined(TT_GTM_TIM2_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_5_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM2CH5INT);
}
#endif /* TT_GTM_TIM2_CH5_INTERRUPT_ENABLE */

/*************** Tim2 channel 6 interrupt handler ***************/
#if (defined(TT_GTM_TIM2_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH6_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_6_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM2CH6INT);
}
#endif /* TT_GTM_TIM2_CH6_INTERRUPT_ENABLE */

/*************** Tim2 channel 7 interrupt handler ***************/
#if (defined(TT_GTM_TIM2_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TIM2_7_IRQHandler)
{
    Gtm_TimChannelIntHandler(&TIM2CH7INT);
}
#endif /* TT_GTM_TIM2_CH7_INTERRUPT_ENABLE */

/************************ TOM Interrupt Function  ****************************/

/**
* @brief        Gtm_Hw_Interrupt_TomIntInit
* @details      Tom channel interrupt initialization. 
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_TomIntInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /***************** TOM0 channel 0-7 interrupt set  *******************/
#if (defined(TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH0INT), 0, 0);
#endif

#if (defined(TT_GTM_TOM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH1_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH1INT), 0, 1);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH2INT), 0, 2);
#endif

#if (defined(TT_GTM_TOM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH3_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH3INT), 0, 3);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH4INT), 0, 4);
#endif

#if (defined(TT_GTM_TOM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH5_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH5INT), 0, 5);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH6INT), 0, 6);
#endif

#if (defined(TT_GTM_TOM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH7_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH7INT), 0, 7);
#endif
#endif

    /***************** TOM0 channel 8-15 interrupt set  *******************/
#if (defined(TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH8INT), 0, 8);
#endif

#if (defined(TT_GTM_TOM0_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH9_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH9INT), 0, 9);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH10INT), 0, 10);
#endif

#if (defined(TT_GTM_TOM0_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH11_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH11INT), 0, 11);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH12INT), 0, 12);
#endif

#if (defined(TT_GTM_TOM0_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH13_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH13INT), 0, 13);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH14INT), 0, 14);
#endif

#if (defined(TT_GTM_TOM0_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH15_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM0CH15INT), 0, 15);
#endif
#endif

    /***************** TOM1 channel 0-7 interrupt set  *******************/
#if (defined(TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH0INT), 1, 0);
#endif

#if (defined(TT_GTM_TOM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH1_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH1INT), 1, 1);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH2INT), 1, 2);
#endif

#if (defined(TT_GTM_TOM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH3_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH3INT), 1, 3);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH4INT), 1, 4);
#endif

#if (defined(TT_GTM_TOM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH5_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH5INT), 1, 5);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH6INT), 1, 6);
#endif

#if (defined(TT_GTM_TOM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH7_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH7INT), 1, 7);
#endif
#endif

    /***************** TOM1 channel 8-15 interrupt set  *******************/
#if (defined(TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH8INT), 1, 8);
#endif

#if (defined(TT_GTM_TOM1_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH9_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH9INT), 1, 9);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH10INT), 1, 10);
#endif

#if (defined(TT_GTM_TOM1_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH11_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH11INT), 1, 11);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH12INT), 1, 12);
#endif

#if (defined(TT_GTM_TOM1_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH13_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH13INT), 1, 13);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH14INT), 1, 14);
#endif

#if (defined(TT_GTM_TOM1_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH15_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG((&TOM1CH15INT), 1, 15);
#endif
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    Ret = Gtm_Hw_Interrupt_PriTomIntInitCheck();
#else
    (void)Ret;
#endif

    return Ret;
}

/*************** Tom0 channel 0-1 interrupt handler ***************/
#if (defined(TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_0_IRQHandler)
{
#if (defined(TT_GTM_TOM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH0INT);
#endif  /* TT_GTM_TOM0_CH0_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH1_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH1INT);
#endif  /* TT_GTM_TOM0_CH1_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE */

/*************** Tom0 channel 2-3 interrupt handler ***************/
#if (defined(TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_1_IRQHandler)
{
#if (defined(TT_GTM_TOM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH2INT);
#endif  /* TT_GTM_TOM0_CH2_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH3_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH3INT);
#endif  /* TT_GTM_TOM0_CH3_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE */

/*************** Tom0 channel 4-5 interrupt handler ***************/
#if (defined(TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_2_IRQHandler)
{
#if (defined(TT_GTM_TOM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH4INT);
#endif  /* TT_GTM_TOM0_CH4_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH5_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH5INT);
#endif  /* TT_GTM_TOM0_CH5_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE */

/*************** Tom0 channel 6-7 interrupt handler ***************/
#if (defined(TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_3_IRQHandler)
{
#if (defined(TT_GTM_TOM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH6INT);
#endif  /* TT_GTM_TOM0_CH6_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH7_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH7INT);
#endif  /* TT_GTM_TOM0_CH7_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE */

/*************** Tom0 channel 8-9 interrupt handler ***************/
#if (defined(TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_4_IRQHandler)
{
#if (defined(TT_GTM_TOM0_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH8INT);
#endif  /* TT_GTM_TOM0_CH8_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH9_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH9INT);
#endif  /* TT_GTM_TOM0_CH9_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE */

/*************** Tom0 channel 10-11 interrupt handler ***************/
#if (defined(TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_5_IRQHandler)
{
#if (defined(TT_GTM_TOM0_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH10INT);
#endif  /* TT_GTM_TOM0_CH10_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH11_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH11INT);
#endif  /* TT_GTM_TOM0_CH11_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE */

/*************** Tom0 channel 12-13 interrupt handler ***************/
#if (defined(TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_6_IRQHandler)
{
#if (defined(TT_GTM_TOM0_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH12INT);
#endif  /* TT_GTM_TOM0_CH12_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH13_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH13INT);
#endif  /* TT_GTM_TOM0_CH13_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE */

/*************** Tom0 channel 14-15 interrupt handler ***************/
#if (defined(TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM0_7_IRQHandler)
{
#if (defined(TT_GTM_TOM0_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH14INT);
#endif  /* TT_GTM_TOM0_CH14_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM0_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH15_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM0CH15INT);
#endif  /* TT_GTM_TOM0_CH15_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE */

/*************** Tom1 channel 0-1 interrupt handler ***************/
#if (defined(TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_0_IRQHandler)
{
#if (defined(TT_GTM_TOM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH0INT);
#endif  /* TT_GTM_TOM1_CH0_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH1_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH1INT);
#endif  /* TT_GTM_TOM1_CH1_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE */

/*************** Tom1 channel 2-3 interrupt handler ***************/
#if (defined(TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_1_IRQHandler)
{
#if (defined(TT_GTM_TOM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH2INT);
#endif  /* TT_GTM_TOM1_CH2_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH3_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH3INT);
#endif  /* TT_GTM_TOM1_CH3_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE */

/*************** Tom1 channel 4-5 interrupt handler ***************/
#if (defined(TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_2_IRQHandler)
{
#if (defined(TT_GTM_TOM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH4INT);
#endif  /* TT_GTM_TOM1_CH4_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH5_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH5INT);
#endif  /* TT_GTM_TOM1_CH5_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM1_CH2_INTERRUPT_ENABLE */

/*************** Tom1 channel 6-7 interrupt handler ***************/
#if (defined(TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_3_IRQHandler)
{
#if (defined(TT_GTM_TOM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH6INT);
#endif  /* TT_GTM_TOM1_CH6_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH7_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH7INT);
#endif  /* TT_GTM_TOM1_CH7_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE */

/*************** Tom1 channel 8-9 interrupt handler ***************/
#if (defined(TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_4_IRQHandler)
{
#if (defined(TT_GTM_TOM1_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH8INT);
#endif  /* TT_GTM_TOM1_CH8_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH9_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH9INT);
#endif  /* TT_GTM_TOM1_CH9_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE */

/*************** Tom1 channel 10-11 interrupt handler ***************/
#if (defined(TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_5_IRQHandler)
{
#if (defined(TT_GTM_TOM1_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH10INT);
#endif  /* TT_GTM_TOM1_CH10_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH11_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH11INT);
#endif  /* TT_GTM_TOM1_CH11_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE */

/*************** Tom1 channel 12-13 interrupt handler ***************/
#if (defined(TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_6_IRQHandler)
{
#if (defined(TT_GTM_TOM1_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH12INT);
#endif  /* TT_GTM_TOM1_CH12_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH13_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH13INT);
#endif  /* TT_GTM_TOM1_CH13_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE */

/*************** Tom1 channel 14-15 interrupt handler ***************/
#if (defined(TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE == TRUE))
ISR(GTM_TOM1_7_IRQHandler)
{
#if (defined(TT_GTM_TOM1_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH14INT);
#endif  /* TT_GTM_TOM1_CH14_INTERRUPT_ENABLE */

#if (defined(TT_GTM_TOM1_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH15_INTERRUPT_ENABLE == TRUE))
    Gtm_TomChannelIntHandler(&TOM1CH15INT);
#endif  /* TT_GTM_TOM1_CH15_INTERRUPT_ENABLE */
}
#endif /* TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE */

#define GTM_STOP_SEC_CODE_FAST
#include "Gtm_MemMap.h"

/******************************************************************************
 *                       Private Function
 ******************************************************************************/
/**
* @brief        Gtm_Hw_Interrupt_TimIntInitCheck
* @details      Tim channel interrupt initialization check. 
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_PriTimIntInitCheck(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /***************** TIM0 channel 0-3 interrupt set  *******************/
#if (defined(TT_GTM_TIM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH0_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM0CH0INT), 0, 0);
#endif

#if (defined(TT_GTM_TIM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH1_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM0CH1INT), 0, 1);
#endif

#if (defined(TT_GTM_TIM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH2_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM0CH2INT), 0, 2);
#endif

#if (defined(TT_GTM_TIM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH3_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM0CH3INT), 0, 3);
#endif

    /***************** TIM0 channel 4-7 interrupt set  *******************/
#if (defined(TT_GTM_TIM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH4_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM0CH4INT), 0, 4);
#endif

#if (defined(TT_GTM_TIM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH5_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM0CH5INT), 0, 5);
#endif

#if (defined(TT_GTM_TIM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH6_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM0CH6INT), 0, 6);
#endif

#if (defined(TT_GTM_TIM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM0_CH7_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM0CH7INT), 0, 7);
#endif

    /***************** TIM1 channel 0-3 interrupt set  *******************/
#if (defined(TT_GTM_TIM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH0_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM1CH0INT), 1, 0);
#endif

#if (defined(TT_GTM_TIM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH1_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM1CH1INT), 1, 1);
#endif

#if (defined(TT_GTM_TIM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH2_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM1CH2INT), 1, 2);
#endif

#if (defined(TT_GTM_TIM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH3_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM1CH3INT), 1, 3);
#endif

    /***************** TIM1 channel 4-7 interrupt set  *******************/
#if (defined(TT_GTM_TIM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH4_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM1CH4INT), 1, 4);
#endif

#if (defined(TT_GTM_TIM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH5_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM1CH5INT), 1, 5);
#endif

#if (defined(TT_GTM_TIM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH6_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM1CH6INT), 1, 6);
#endif

#if (defined(TT_GTM_TIM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM1_CH7_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM1CH7INT), 1, 7);
#endif

    /***************** TIM2 channel 0-3 interrupt set  *******************/
#if (defined(TT_GTM_TIM2_CH0_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH0_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM2CH0INT), 2, 0);
#endif

#if (defined(TT_GTM_TIM2_CH1_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH1_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM2CH1INT), 2, 1);
#endif

#if (defined(TT_GTM_TIM2_CH2_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH2_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM2CH2INT), 2, 2);
#endif

#if (defined(TT_GTM_TIM2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH3_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM2CH3INT), 2, 3);
#endif

    /***************** TIM2 channel 4-7 interrupt set  *******************/
#if (defined(TT_GTM_TIM2_CH4_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH4_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM2CH4INT), 2, 4);
#endif

#if (defined(TT_GTM_TIM2_CH5_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH5_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM2CH5INT), 2, 5);
#endif

#if (defined(TT_GTM_TIM2_CH6_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH6_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM2CH6INT), 2, 6);
#endif

#if (defined(TT_GTM_TIM2_CH7_INTERRUPT_ENABLE) && (TT_GTM_TIM2_CH7_INTERRUPT_ENABLE == TRUE))
    TIM_INTERRUPT_CONFIG_CHECK((&TIM2CH7INT), 2, 7);
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Interrupt_TomIntInitCheck
* @details      Tom channel interrupt initialization check. 
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
TT_RetType Gtm_Hw_Interrupt_PriTomIntInitCheck(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /***************** TOM0 channel 0-7 interrupt set  *******************/
#if (defined(TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_CH1_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH0_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH0INT), 0, 0);
#endif

#if (defined(TT_GTM_TOM0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH1_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH1INT), 0, 1);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_CH3_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH2_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH2INT), 0, 2);
#endif

#if (defined(TT_GTM_TOM0_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH3_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH3INT), 0, 3);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_CH5_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH4_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH4INT), 0, 4);
#endif

#if (defined(TT_GTM_TOM0_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH5_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH5INT), 0, 5);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_CH7_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH6_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH6INT), 0, 6);
#endif

#if (defined(TT_GTM_TOM0_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH7_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH7INT), 0, 7);
#endif
#endif

    /***************** TOM0 channel 8-15 interrupt set  *******************/
#if (defined(TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_CH9_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH8_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH8INT), 0, 8);
#endif

#if (defined(TT_GTM_TOM0_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH9_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH9INT), 0, 9);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_CH11_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH10_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH10INT), 0, 10);
#endif

#if (defined(TT_GTM_TOM0_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH11_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH11INT), 0, 11);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_CH13_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH12_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH12INT), 0, 12);
#endif

#if (defined(TT_GTM_TOM0_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH13_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH13INT), 0, 13);
#endif
#endif

#if (defined(TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_CH15_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM0_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH14_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH14INT), 0, 14);
#endif

#if (defined(TT_GTM_TOM0_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM0_CH15_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM0CH15INT), 0, 15);
#endif
#endif

    /***************** TOM1 channel 0-7 interrupt set  *******************/
#if (defined(TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_CH1_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH0_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH0_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH0INT), 1, 0);
#endif

#if (defined(TT_GTM_TOM1_CH1_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH1_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH1INT), 1, 1);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_CH3_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH2_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH2_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH2INT), 1, 2);
#endif

#if (defined(TT_GTM_TOM1_CH3_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH3_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH3INT), 1, 3);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_CH5_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH4_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH4_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH4INT), 1, 4);
#endif

#if (defined(TT_GTM_TOM1_CH5_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH5_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH5INT), 1, 5);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_CH7_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH6_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH6_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH6INT), 1, 6);
#endif

#if (defined(TT_GTM_TOM1_CH7_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH7_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH7INT), 1, 7);
#endif
#endif

    /***************** TOM1 channel 8-15 interrupt set  *******************/
#if (defined(TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_CH9_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH8_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH8_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH8INT), 1, 8);
#endif

#if (defined(TT_GTM_TOM1_CH9_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH9_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH9INT), 1, 9);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_CH11_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH10_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH10_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH10INT), 1, 10);
#endif

#if (defined(TT_GTM_TOM1_CH11_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH11_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH11INT), 1, 11);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_CH13_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH12_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH12_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH12INT), 1, 12);
#endif

#if (defined(TT_GTM_TOM1_CH13_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH13_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH13INT), 1, 13);
#endif
#endif

#if (defined(TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_CH15_INTERRUPT_ENABLE == TRUE))
#if (defined(TT_GTM_TOM1_CH14_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH14_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH14INT), 1, 14);
#endif

#if (defined(TT_GTM_TOM1_CH15_INTERRUPT_ENABLE) && (TT_GTM_TOM1_CH15_INTERRUPT_ENABLE == TRUE))
    TOM_INTERRUPT_CONFIG_CHECK((&TOM1CH15INT), 1, 15);
#endif
#endif

    return Ret;
}


#ifdef __cplusplus
}
#endif
