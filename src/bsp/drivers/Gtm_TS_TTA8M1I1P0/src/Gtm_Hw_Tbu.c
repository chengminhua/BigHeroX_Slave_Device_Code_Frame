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
**  FILENAME     : Gtm_Hw_Tbu.c                                               **
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
#include "Gtm_Hw_Tbu.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Gtm.h"
#endif

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define GTM_HW_TBU_VENDOR_ID_C                      1541
#define GTM_HW_TBU_MODULE_ID_C                      221
#define GTM_HW_TBU_AR_RELEASE_MAJOR_VERSION_C       4
#define GTM_HW_TBU_AR_RELEASE_MINOR_VERSION_C       4
#define GTM_HW_TBU_AR_RELEASE_PATCH_VERSION_C       0
#define GTM_HW_TBU_SW_MAJOR_VERSION_C               1
#define GTM_HW_TBU_SW_MINOR_VERSION_C               1
#define GTM_HW_TBU_SW_PATCH_VERSION_C               0
/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Gtm_Hw_Tbu.h Gtm_Hw_Tbu.c file version check */
#if (GTM_HW_TBU_VENDOR_ID_H != GTM_HW_TBU_VENDOR_ID_C)
    #error "Gtm_Hw_Tbu.h and Gtm_Hw_Tbu.c have different vendor ids"
#endif
#if (GTM_HW_TBU_MODULE_ID_H != GTM_HW_TBU_MODULE_ID_C)
    #error "Gtm_Hw_Tbu.h and Gtm_Hw_Tbu.c have different module ids"
#endif
#if ((GTM_HW_TBU_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_TBU_AR_RELEASE_MAJOR_VERSION_C) || \
     (GTM_HW_TBU_AR_RELEASE_MINOR_VERSION_H != GTM_HW_TBU_AR_RELEASE_MINOR_VERSION_C) || \
     (GTM_HW_TBU_AR_RELEASE_PATCH_VERSION_H != GTM_HW_TBU_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of Gtm_Hw_Tbu.h and Gtm_Hw_Tbu.c are different"
#endif
#if ((GTM_HW_TBU_SW_MAJOR_VERSION_H != GTM_HW_TBU_SW_MAJOR_VERSION_C) || \
     (GTM_HW_TBU_SW_MINOR_VERSION_H != GTM_HW_TBU_SW_MINOR_VERSION_C) || \
     (GTM_HW_TBU_SW_PATCH_VERSION_H != GTM_HW_TBU_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Gtm_Hw_Tbu.h and Gtm_Hw_Tbu.c are different"
#endif

#ifdef USING_OS_AUTOSAROS
/* Gtm_Hw_Tbu.c SchM_Gtm.h file version check */
#if (GTM_HW_TBU_VENDOR_ID_C != SCHM_GTM_VENDOR_ID_H)
    #error "Gtm_Hw_Tbu.c and SchM_Gtm.h have different vendor ids"
#endif
#if ((GTM_HW_TBU_AR_RELEASE_MAJOR_VERSION_C != SCHM_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_TBU_AR_RELEASE_MINOR_VERSION_C != SCHM_GTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_TBU_AR_RELEASE_PATCH_VERSION_C != SCHM_GTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Tbu.c and SchM_Gtm.h are different"
#endif
#if ((GTM_HW_TBU_SW_MAJOR_VERSION_C != SCHM_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_HW_TBU_SW_MINOR_VERSION_C != SCHM_GTM_SW_MINOR_VERSION_H) || \
     (GTM_HW_TBU_SW_PATCH_VERSION_C != SCHM_GTM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Tbu.c and SchM_Gtm.h are different"
#endif
#endif
/******************************************************************************
 *                       Global Variables Declaration
 ******************************************************************************/

/******************************************************************************
 *                       Private Variables
 ******************************************************************************/

/******************************************************************************
 *                       Private Function Declaration
 ******************************************************************************/
/**
* @brief        Gtm_Hw_Tbu_PriInitCheck
* @details      TBU initialization check.
* @param[in]    TbuConfig:  TBU Configuration pointer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_PriInitCheck(TT_CONST Tbu_ConfigType *TbuConfig);

/******************************************************************************
 *                       Public Functions
 ******************************************************************************/
#if (TT_GTM_USED_TBU == TRUE)

#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

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
TT_RetType Gtm_Hw_Tbu_Init(TT_CONST Tbu_ConfigType *TbuConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#if(GTM_TBU0_USE_CHANNEL0 == TRUE)
    TT_GTM->TBU.CH0_CTRL.B.CH_CLK_SRC = (uint8)GTM_TBU0_CHANNEL0_CLOCK_SOURCE;
    TT_GTM->TBU.CH0_BASE.R = GTM_TBU0_CHANNEL0_TIME_BASE;
    TT_GTM->TBU.CH0_CTRL.B.LOW_RES = (uint8)GTM_TBU0_CHANNEL0_RESOLUTION;
#endif /* GTM_TBU0_USE_CHANNEL0 */

#if(GTM_TBU0_USE_CHANNEL1 == TRUE)
    TT_GTM->TBU.CH1_CTRL.B.CH_CLK_SRC = (uint8)GTM_TBU0_CHANNEL1_CLOCK_SOURCE;
    TT_GTM->TBU.CH1_BASE.R = GTM_TBU0_CHANNEL1_TIME_BASE;
    TT_GTM->TBU.CH1_CTRL.B.CH_MODE = (uint8)GTM_TBU0_CHANNEL1_MODE;
#endif /* GTM_TBU0_USE_CHANNEL1 */

#if(GTM_TBU0_USE_CHANNEL2 == TRUE)
    TT_GTM->TBU.CH2_CTRL.B.CH_CLK_SRC = (uint8)GTM_TBU0_CHANNEL2_CLOCK_SOURCE;
    TT_GTM->TBU.CH2_BASE.R = GTM_TBU0_CHANNEL2_TIME_BASE;
    TT_GTM->TBU.CH2_CTRL.B.CH_MODE = (uint8)GTM_TBU0_CHANNEL2_MODE;
#endif /* GTM_TBU0_USE_CHANNEL2 */

#if(GTM_TBU0_USE_CHANNEL3 == TRUE)
    TT_GTM->TBU.CH3_BASE.R = GTM_TBU0_CHANNEL3_TIME_BASE;
    TT_GTM->TBU.CH3_BASE_MARK.R = GTM_TBU0_CHANNEL3_TIME_MSK;
    TT_GTM->TBU.CH3_CTRL.B.USE_CH2 = (uint8)GTM_TBU0_CHANNEL3_SELECT_MODULO_COUNTER;
#endif /* GTM_TBU0_USE_CHANNEL3 */

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    Ret = Gtm_Hw_Tbu_PriInitCheck(TbuConfig);
#else
    (void)Ret;
    (void)TbuConfig;
#endif

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_Start(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 value = 0;
    uint32 mask = 0;

#if(GTM_TBU0_USE_CHANNEL0 == TRUE)
    value |= 0x02UL;
    mask |= (0x3UL << 0);
#endif

#if(GTM_TBU0_USE_CHANNEL1 == TRUE)
    value |= 0x08UL;
    mask |= (0x3UL << 2);
#endif

#if(GTM_TBU0_USE_CHANNEL2 == TRUE)
    value |= 0x20UL;
    mask |= (0x3UL << 4);
#endif

#if(GTM_TBU0_USE_CHANNEL3 == TRUE)
    value |= 0x80UL;
    mask |= (0x3UL << 6);
#endif

    /* Enable TBU module and channels */
    TT_GTM->TBU.CHEN.R = value;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    GTM_REG_CHECK(TT_GTM->TBU.CHEN.R, mask);
#else
    (void)mask;
#endif

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_Stop(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* Disable all TBU channels */
    TT_GTM->TBU.CHEN.R = 0x5555;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    GTM_REG_CHECK(TT_GTM->TBU.CHEN.R, 0);
#endif

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_StartChannel(uint8 channel)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /*Check the validity of parameters*/
    TT_ParaCheck((channel > TBU_CHANNEL3), TT_RET_PARAM_INDEX_ERR, &Ret);

    /*Check the validity of parameters*/
    if(Ret == TT_RET_SUCCESS)
    {
        /* Enable TBU specific channel */
        GTM_REG_READ_2_WRITE(TT_GTM->TBU.CHEN.R, 0x02, 0x03, (channel << 1UL));

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(TBU_GET_CHANNEL_ENDIS(channel), 0x3U);
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_StopChannel(uint8 channel)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /*Check the validity of parameters*/
    TT_ParaCheck((channel > TBU_CHANNEL3), TT_RET_PARAM_INDEX_ERR, &Ret);

    /*Check the validity of parameters*/
    if(Ret == TT_RET_SUCCESS)
    {
        /* Disable TBU specific channel */
        GTM_REG_READ_2_WRITE(TT_GTM->TBU.CHEN.R, 0x01, 0x03, (channel << 1UL));

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(TBU_GET_CHANNEL_ENDIS(channel), 0x0U);
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_SetClockChannel(uint8 channel, uint8 clock_source)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /*Check the validity of parameters*/
    TT_ParaCheck((channel > TBU_CHANNEL2), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck(((clock_source >> 3) > 0), TT_RET_PARAM_CONFIG_ERR, &Ret);

    /*Check the validity of parameters*/
    if(Ret == TT_RET_SUCCESS)
    {
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_04();
#endif
        /*Set information according to subscripts*/
        switch(channel)
        {
            case TBU_CHANNEL0:
                TT_GTM->TBU.CH0_CTRL.B.CH_CLK_SRC = clock_source;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->TBU.CH0_CTRL.B.CH_CLK_SRC, clock_source);
#endif
                break;
            case TBU_CHANNEL1:
                TT_GTM->TBU.CH1_CTRL.B.CH_CLK_SRC = clock_source;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->TBU.CH1_CTRL.B.CH_CLK_SRC, clock_source);
#endif
                break;
            case TBU_CHANNEL2:
                TT_GTM->TBU.CH2_CTRL.B.CH_CLK_SRC = clock_source;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->TBU.CH2_CTRL.B.CH_CLK_SRC, clock_source);
#endif
                break;
            default:
                /* do nothing */
                break;
        }
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_04();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_GetClockChannel(uint8 channel, uint8 *clock_source)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /*Check the validity of parameters*/
    TT_ParaCheck((channel > TBU_CHANNEL2), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((clock_source == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    /*Check the validity of parameters*/
    if(Ret == TT_RET_SUCCESS)
    {
        /*Get information according to subscripts*/
        switch(channel)
        {
            case TBU_CHANNEL0:
                *clock_source = TT_GTM->TBU.CH0_CTRL.B.CH_CLK_SRC;
                break;
            case TBU_CHANNEL1:
                *clock_source = TT_GTM->TBU.CH1_CTRL.B.CH_CLK_SRC;
                break;
            case TBU_CHANNEL2:
                *clock_source = TT_GTM->TBU.CH2_CTRL.B.CH_CLK_SRC;
                break;
            default:
                *clock_source = 0;
                break;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_SetTimeBaseChannel(uint8 channel, uint32 time_base)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 baseWide = 0;

    TT_ParaCheck((channel > TBU_CHANNEL3), TT_RET_PARAM_INDEX_ERR, &Ret);
    (channel == 0)? (baseWide = 27): (baseWide = 24);
    TT_ParaCheck(((time_base >> baseWide) != 0), TT_RET_PARAM_LEN_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_05();
#endif
        /*Set time base according to subscript*/
        switch(channel)
        {
            case TBU_CHANNEL0:
                TT_GTM->TBU.CH0_BASE.R = time_base;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->TBU.CH0_BASE.R, time_base);
#endif
                break;
            case TBU_CHANNEL1:
                TT_GTM->TBU.CH1_BASE.R = time_base;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->TBU.CH1_BASE.R, time_base);
#endif
                break;
            case TBU_CHANNEL2:
                TT_GTM->TBU.CH2_BASE.R = time_base;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->TBU.CH2_BASE.R, time_base);
#endif
                break;
            case TBU_CHANNEL3:
                TT_GTM->TBU.CH3_BASE.R = time_base;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
                GTM_REG_CHECK(TT_GTM->TBU.CH3_BASE.R, time_base);
#endif
                break;
            default:
                /* MISRA check, do nothing*/
                break;
        }
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_05();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_GetTimeBaseChannel(uint8 channel, uint32 *time_base)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    /*Check the validity of parameters*/
    TT_ParaCheck((channel > TBU_CHANNEL3), TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck((time_base == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    /*Check the validity of parameters*/
    if(Ret == TT_RET_SUCCESS)
    {
        /*Get time base according to subscript*/
        switch(channel)
        {
            case TBU_CHANNEL0:
                *time_base = TT_GTM->TBU.CH0_BASE.R;
                break;
            case TBU_CHANNEL1:
                *time_base = TT_GTM->TBU.CH1_BASE.R;
                break;
            case TBU_CHANNEL2:
                *time_base = TT_GTM->TBU.CH2_BASE.R;
                break;
            case TBU_CHANNEL3:
                *time_base = TT_GTM->TBU.CH3_BASE.R;
                break;
            default:
                *time_base = 0;
                break;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_SetLowResChannel_0(uint8 resolution)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((resolution > 1), TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_06();
#endif
        TT_GTM->TBU.CH0_CTRL.B.LOW_RES = resolution;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(TT_GTM->TBU.CH0_CTRL.B.LOW_RES, resolution);
#endif
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_06();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
TT_RetType Gtm_Hw_Tbu_GetLowResChannel_0(uint8 *low_res)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /*Check the validity of parameters*/
    TT_ParaCheck((low_res == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    /*Check the validity of parameters*/
    if(Ret == TT_RET_SUCCESS)
    {
        *low_res = TT_GTM->TBU.CH0_CTRL.B.LOW_RES;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
                                               Tbu_ChannelModeSelectType running_mode)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /*Check the validity of parameters*/
    TT_ParaCheck(((channel != 1) && (channel != 2)),TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck(((running_mode != TBU_FREE_RUNNING_COUNTER) && (running_mode != TBU_FORWARD_BACKWARD_COUNTER)),
                 TT_RET_PARAM_INVALID_DATA_ERR, &Ret);

    /*Check the validity of parameters*/
    if(Ret == TT_RET_SUCCESS)
    {
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_07();
#endif
        /*Set running mode or not*/
        if(channel == 1U)
        {
            TT_GTM->TBU.CH1_CTRL.B.CH_MODE = (uint8)running_mode;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK(TT_GTM->TBU.CH1_CTRL.B.CH_MODE, running_mode);
#endif
        }
        else if(channel == 2U)
        {
            TT_GTM->TBU.CH2_CTRL.B.CH_MODE = (uint8)running_mode;
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            GTM_REG_CHECK(TT_GTM->TBU.CH2_CTRL.B.CH_MODE, running_mode);
#endif
        }
        else
        {
            /* do nothing */
        }
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_07();
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

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
                                               Tbu_ChannelModeSelectType *mode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    /*Check the validity of parameters*/
    TT_ParaCheck(((channel != 1) && (channel != 2)),TT_RET_PARAM_INVALID_DATA_ERR, &Ret);
    TT_ParaCheck((mode == NULL_PTR), TT_RET_PARAM_INVALID_PTR_ERR, &Ret);

    /*Check the validity of parameters*/
    if(Ret == TT_RET_SUCCESS)
    {
        /*Get running information according to channel*/
        switch(channel)
        {
            case 1: *mode = (TT_GTM->TBU.CH1_CTRL.B.CH_MODE == (uint32)TBU_FREE_RUNNING_COUNTER)? 
                            TBU_FREE_RUNNING_COUNTER: TBU_FORWARD_BACKWARD_COUNTER; 
                    break;
            case 2: *mode = (TT_GTM->TBU.CH2_CTRL.B.CH_MODE == (uint32)TBU_FREE_RUNNING_COUNTER)? 
                            TBU_FREE_RUNNING_COUNTER: TBU_FORWARD_BACKWARD_COUNTER; 
                    break;
            default: /* do nothing */ break;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *                       Private Function
 ******************************************************************************/
/**
* @brief        Gtm_Hw_Tbu_PriInitCheck
* @details      TBU initialization check.
* @param[in]    TbuConfig:  TBU Configuration pointer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS : success
*               Others         : fail
* @pre
*/
TT_RetType Gtm_Hw_Tbu_PriInitCheck(TT_CONST Tbu_ConfigType *TbuConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    (void)TbuConfig;

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))

#if (GTM_TBU0_USE_CHANNEL0 == TRUE)
    GTM_REG_CHECK(TT_GTM->TBU.CH0_CTRL.B.CH_CLK_SRC, (uint8)GTM_TBU0_CHANNEL0_CLOCK_SOURCE);
    GTM_REG_CHECK(TT_GTM->TBU.CH0_BASE.R, GTM_TBU0_CHANNEL0_TIME_BASE);
    GTM_REG_CHECK(TT_GTM->TBU.CH0_CTRL.B.LOW_RES, (uint8)GTM_TBU0_CHANNEL0_RESOLUTION);
#endif /* GTM_TBU0_USE_CHANNEL0 */

#if (GTM_TBU0_USE_CHANNEL1 == TRUE)
    GTM_REG_CHECK(TT_GTM->TBU.CH1_CTRL.B.CH_MODE, GTM_TBU0_CHANNEL1_MODE);
    GTM_REG_CHECK(TT_GTM->TBU.CH1_BASE.R, GTM_TBU0_CHANNEL1_TIME_BASE);
    GTM_REG_CHECK(TT_GTM->TBU.CH1_CTRL.B.CH_CLK_SRC, GTM_TBU0_CHANNEL1_CLOCK_SOURCE);
#endif /* GTM_TBU0_USE_CHANNEL1 */

#if (GTM_TBU0_USE_CHANNEL2 == TRUE)
    GTM_REG_CHECK(TT_GTM->TBU.CH2_CTRL.B.CH_MODE, GTM_TBU0_CHANNEL2_MODE);
    GTM_REG_CHECK(TT_GTM->TBU.CH2_BASE.R, GTM_TBU0_CHANNEL2_TIME_BASE);
    GTM_REG_CHECK(TT_GTM->TBU.CH2_CTRL.B.CH_CLK_SRC, GTM_TBU0_CHANNEL2_CLOCK_SOURCE);
#endif /* GTM_TBU0_USE_CHANNEL2 */

#if (GTM_TBU0_USE_CHANNEL3 == TRUE)
    GTM_REG_CHECK(TT_GTM->TBU.CH3_CTRL.B.USE_CH2, GTM_TBU0_CHANNEL3_SELECT_MODULO_COUNTER);
    GTM_REG_CHECK(TT_GTM->TBU.CH3_BASE.R, GTM_TBU0_CHANNEL3_TIME_BASE);
    GTM_REG_CHECK(TT_GTM->TBU.CH3_BASE_MARK.R, GTM_TBU0_CHANNEL3_TIME_MSK);
#endif /* GTM_TBU0_USE_CHANNEL3 */

#endif /* TT_SAFETY */

    return Ret;
}
#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

#endif

#ifdef __cplusplus
}
#endif
