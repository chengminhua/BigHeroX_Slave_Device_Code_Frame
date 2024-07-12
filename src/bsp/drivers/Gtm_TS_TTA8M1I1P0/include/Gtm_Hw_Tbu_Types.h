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
**  FILENAME     : Gtm_Hw_Tbu_Types.h                                         **
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
#ifndef GTM_HW_TBU_TYPES_H
#define GTM_HW_TBU_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Base.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_TBU_TYPES_VENDOR_ID_H                      1541
#define GTM_HW_TBU_TYPES_MODULE_ID_H                      221
#define GTM_HW_TBU_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_TBU_TYPES_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_TBU_TYPES_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_TBU_TYPES_SW_MAJOR_VERSION_H               1
#define GTM_HW_TBU_TYPES_SW_MINOR_VERSION_H               1
#define GTM_HW_TBU_TYPES_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Base.h Gtm_Hw_Tbu_Types.h file version check */
#if (GTM_HW_BASE_VENDOR_ID_H != GTM_HW_TBU_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Tbu_Types.h have different vendor ids"
#endif

#if (GTM_HW_BASE_MODULE_ID_H != GTM_HW_TBU_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Tbu_Types.h have different module ids"
#endif

#if ((GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Tbu_Types.h are different"
#endif

#if ((GTM_HW_BASE_SW_MAJOR_VERSION_H != GTM_HW_TBU_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_SW_MINOR_VERSION_H != GTM_HW_TBU_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_BASE_SW_PATCH_VERSION_H != GTM_HW_TBU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Tbu_Types.h are different"
#endif


/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/** TBU channel 0 identifier */
#define TBU_CHANNEL0                        0U
/** TBU channel 1 identifier */
#define TBU_CHANNEL1                        1U
/** TBU channel 2 identifier */
#define TBU_CHANNEL2                        2U
/** TBU channel 3 identifier */
#define TBU_CHANNEL3                        3U

/* Whether to enable or disable the status of a specified Tbu channel */
#define TBU_GET_CHANNEL_ENDIS(channel) \
    (TT_GTM->TBU.CHEN.R & (0x03UL << (channel << 1UL))) >> (channel << 1UL)


/******************************************************************************
*                            Enums
*******************************************************************************/
/* Tbu channel counting mode type */
typedef enum
{
    TBU_FREE_RUNNING_COUNTER = 0,
    TBU_FORWARD_BACKWARD_COUNTER
}Tbu_ChannelModeSelectType;

/* Tbu counting indicates the optional channel type */
typedef enum
{
    TBU_CH1 = 0,
    TBU_CH2
}Tbu_ChSelectModuleCntType;

/* Tbu channel clock source type */
typedef enum
{
    TBU_CONFIGURABLE_CLOCK_0 = 0,
    TBU_CONFIGURABLE_CLOCK_1,
    TBU_CONFIGURABLE_CLOCK_2,
    TBU_CONFIGURABLE_CLOCK_3,
    TBU_CONFIGURABLE_CLOCK_4,
    TBU_CONFIGURABLE_CLOCK_5,
    TBU_CONFIGURABLE_CLOCK_6,
    TBU_CONFIGURABLE_CLOCK_7
}Tbu_ChannelClockSourceType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* The structure contains provides the TBU Channel configuration. */
typedef struct
{
    /* Select the Tbu channel mode (for channel 1/2 only) */
    Tbu_ChannelModeSelectType  TbuChannelModeSelect;
    /* Select the clock source for the Tbu channel */
    Tbu_ChannelClockSourceType TbuChannelClockSource;
    /* Tbu channel resolution selection (for channel 0 only) */
    uint8                      TbuChannelResolution;
    /* Enable the Tbu channel */
    boolean                    TbuEnableChannel;
    /* Tbu channel time base value */
    uint32                     TbuTimebaseValue;
}Tbu_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* _Alioth_Gtm_Tbu_H_ */
/** @} */
