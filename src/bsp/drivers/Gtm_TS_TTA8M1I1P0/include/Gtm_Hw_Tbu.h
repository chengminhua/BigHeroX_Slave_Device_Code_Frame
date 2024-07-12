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
**  FILENAME     : Gtm_Hw_Tbu.h                                               **
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
#ifndef GTM_HW_TBU_H
#define GTM_HW_TBU_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Tbu_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_TBU_VENDOR_ID_H                      1541
#define GTM_HW_TBU_MODULE_ID_H                      221
#define GTM_HW_TBU_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_TBU_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_TBU_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_TBU_SW_MAJOR_VERSION_H               1
#define GTM_HW_TBU_SW_MINOR_VERSION_H               1
#define GTM_HW_TBU_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Tbu.h Gtm_Hw_Tbu_Types.h file version check */
#if (GTM_HW_TBU_VENDOR_ID_H != GTM_HW_TBU_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Tbu.h and Gtm_Hw_Tbu_Types.h have different vendor ids"
#endif

#if (GTM_HW_TBU_MODULE_ID_H != GTM_HW_TBU_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Tbu.h and Gtm_Hw_Tbu_Types.h have different module ids"
#endif

#if ((GTM_HW_TBU_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_TBU_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_TBU_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TBU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tbu.h and Gtm_Hw_Tbu_Types.h are different"
#endif

#if ((GTM_HW_TBU_SW_MAJOR_VERSION_H != GTM_HW_TBU_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_TBU_SW_MINOR_VERSION_H != GTM_HW_TBU_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_TBU_SW_PATCH_VERSION_H != GTM_HW_TBU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tbu.h and Gtm_Hw_Tbu_Types.h are different"
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
#if (TT_GTM_USED_TBU == TRUE)
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
/**
* @brief        Gtm_Hw_Tbu_Init
* @details      GTM TBU driver initialization.
* @param[in]    TbuConfig : TBU configuration data pointer
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_Init(TT_CONST Tbu_ConfigType *TbuConfig);

/**
* @brief        Gtm_Hw_Tbu_InitCheck
* @details      TBU initialization check.
* @param[in]    GtmTbuConfig:  TBU Configuration pointer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_InitCheck(TT_CONST Tbu_ConfigType *TbuConfig);


/**
* @brief        Gtm_Hw_Tbu_Start
* @details      Start TBU configured channels.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_Start(void);

/**
* @brief        Gtm_Hw_Tbu_Stop
* @details      Stop TBU all enabled channels.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_Stop(void);

/**
* @brief        Gtm_Hw_Tbu_StartChannel
* @details      Start TBU specified channel.
* @param[in]    channel:    GTM TBU channel number
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_StartChannel(uint8 channel);

/**
* @brief        Gtm_Hw_Tbu_StopChannel
* @details      Stop TBU specified channel.
* @param[in]    channel:  GTM TBU channel number
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_StopChannel(uint8 channel);

/**
* @brief        Gtm_Hw_Tbu_SetClockChannel
* @details      Set TBU clock channel.
* @param[in]    channel     : GTM TBU channel number
* @param[in]    clock_source: GTM TBU clock source
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_SetClockChannel(uint8 channel, uint8 clock_source);

/**
* @brief        Gtm_Hw_Tbu_GetClockChannel
* @details      Get TBU clock channel.
* @param[in]    channel:      GTM TBU channel number
* @param[out]   clock_source: Clock source
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_GetClockChannel(uint8 channel,uint8* clock_source);

/**
* @brief        Gtm_Hw_Tbu_SetTimeBaseChannel
* @details      Set TBU Time Base channel.
* @param[in]    channel:      GTM TBU channel number
* @param[in]    time_base:    GTM TBU time base
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_SetTimeBaseChannel(uint8 channel, uint32 time_base);

/**
* @brief        Gtm_Hw_Tbu_GetTimeBaseChannel
* @details      Get TBU Time Base for the channel.
* @param[in]    channel   : GTM TBU channel number
* @param[out]   time_base : Time Base
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_GetTimeBaseChannel(uint8 channel,uint32* time_base);

/**
* @brief        Gtm_TbuSetLowResChannel_0
* @details      Set TBU counting resolution for channel0.
* @param[in]    resolution : GTM TBU counting resolution setting
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_SetLowResChannel_0(uint8 resolution);

/**
* @brief        Gtm_Hw_Tbu_GetLowResChannel_0
* @details      Get TBU Low Res for the channel0.
* @param[in]    None
* @param[out]   low_res : Save TBU counting resolution
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_GetLowResChannel_0(uint8* low_res);

/**
* @brief        Gtm_Hw_Tbu_SetRunningModeChannel_12
* @details      Set TBU Running Mode for channel1 and channel2.
* @param[in]    channel      : GTM TBU channel number
* @param[in]    running_mode : GTM TBU running mode
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_SetRunningModeChannel_12(uint8 channel,
                                               Tbu_ChannelModeSelectType running_mode);

/**
* @brief        Gtm_Hw_Tbu_GetRunningModeChannel_12
* @details      Get TBU Running Mode for channel1 and channel2.
* @param[in]    channel:      GTM TBU channel number
* @param[out]   mode:         Running_mode
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_GetRunningModeChannel_12(uint8 channel,
                                               Tbu_ChannelModeSelectType* mode);

#endif

#ifdef __cplusplus
}
#endif

#endif /* _Alioth_Gtm_Tbu_H_ */
/** @} */
