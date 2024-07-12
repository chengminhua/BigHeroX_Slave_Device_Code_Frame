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
**  FILENAME     : Mcu_Hw_Cmu.c                                               **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Mcu Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcu_Hw_Cmu.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_CMU_VENDOR_ID_C                     1541
#define MCU_HW_CMU_MODULE_ID_C                     101
#define MCU_HW_CMU_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_HW_CMU_AR_RELEASE_MINOR_VERSION_C      4
#define MCU_HW_CMU_AR_RELEASE_PATCH_VERSION_C      0
#define MCU_HW_CMU_SW_MAJOR_VERSION_C              1
#define MCU_HW_CMU_SW_MINOR_VERSION_C              1
#define MCU_HW_CMU_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Cmu.c and Mcu_Hw_Cmu.h file version check */
#if (MCU_HW_CMU_VENDOR_ID_C != MCU_HW_CMU_VENDOR_ID_H)
    #error "Mcu_Hw_Cmu.c and Mcu_Hw_Cmu.h have different vendor id"
#endif
#if (MCU_HW_CMU_MODULE_ID_C != MCU_HW_CMU_MODULE_ID_H)
    #error "Mcu_Hw_Cmu.c and Mcu_Hw_Cmu.h have different module id"
#endif
#if ((MCU_HW_CMU_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_CMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_CMU_AR_RELEASE_MINOR_VERSION_C != MCU_HW_CMU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_CMU_AR_RELEASE_PATCH_VERSION_C != MCU_HW_CMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Cmu.c and Mcu_Hw_Cmu.h are different"
#endif
#if ((MCU_HW_CMU_SW_MAJOR_VERSION_C != MCU_HW_CMU_SW_MAJOR_VERSION_H) || \
     (MCU_HW_CMU_SW_MINOR_VERSION_C != MCU_HW_CMU_SW_MINOR_VERSION_H) || \
     (MCU_HW_CMU_SW_PATCH_VERSION_C != MCU_HW_CMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Cmu.c and Mcu_Hw_Cmu.h are different"
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
#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

/* Save Cmu Status*/
static uint32 Mcu_PubCmuStatus[MCU_CMU_NUMS] = {0};

#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                         Private Function Declaration
******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if defined(MCU_CMU_ITEM_COUNTS) & (MCU_CMU_ITEM_COUNTS > 0U)
/**
* @brief         Mcu_Hw_Cmu_PriItemConfig
* @details       Cmu configuration
* @param[in]     CmuItem - The pointer of cmu configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Cmu_PriItemConfig(TT_CONST Mcu_Hw_CmuConfigType *CmuItem);

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Cmu_PriItemConfigCheck
* @details       Cmu configuration Check
* @param[in]     CmuItem - The pointer of cmu configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Cmu_PriItemConfigCheck(TT_CONST Mcu_Hw_CmuConfigType *CmuItem);
#endif
#endif

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Cmu_InitCheck
* @details       Service to initialize Check Cmu
* @param[in]     CmuConfig - Cmu configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Cmu_PriInitCheck(TT_CONST Mcu_Hw_CmuConfigType *CmuConfig);
#endif

/******************************************************************************
*                         Public Functions
******************************************************************************/

/**
* @brief         Mcu_Hw_Cmu_Start
* @details       Service to start MCU Cmu
* @param[in]     num - The number of Cmu
* @param[in]     AlarmType - Cmu alarm type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Cmu_Start(TT_CONST uint8 num, TT_CONST uint32 AlarmType)
{
    TT_RetType Ret = 0U;

    TT_ParaCheck((num >= MCU_CMU_NUMS), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck(!(MCU_CMU_ALARM_TYPE_ASSERT(AlarmType)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        TT_SCU->CMUX[num].CMUX_CR |= TT_SCU_CMUX_CMUX_CR_EN_Msk | (uint32)AlarmType;
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((TT_SCU->CMUX[num].CMUX_CR & (TT_SCU_CMUX_CMUX_CR_EN_Msk | (uint32)AlarmType)) != (TT_SCU_CMUX_CMUX_CR_EN_Msk | (uint32)AlarmType), TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Cmu_Stop
* @details       Service to stop  Cmu
* @param[in]     num - The number of Cmu
* @param[in]     AlarmType - Cmu alarm type
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Cmu_Stop(TT_CONST uint8 num, uint32 AlarmType)
{
    TT_RetType Ret = 0U;
    uint32 TmpType = 0U;

    TT_ParaCheck((num >= MCU_CMU_NUMS), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck(!(MCU_CMU_ALARM_TYPE_ASSERT(AlarmType)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        TmpType = AlarmType;
        /* disable all */
        if (((~AlarmType) & ((uint32)MCU_CMU_TYPE_LTH | (uint32)MCU_CMU_TYPE_HTH | (uint32)MCU_CMU_TYPE_TIMEOUT)) == 0)
        {
            TmpType |= 1U;
            TT_SCU->CMUX[num].CMUX_CR &= ~(uint32)TmpType;
        }
        else
        {
            TT_SCU->CMUX[num].CMUX_CR &= ~(uint32)TmpType;
        }
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((TT_SCU->CMUX[num].CMUX_CR & TmpType) > 0, TT_RET_OPT_REG_ERR, &Ret);
    #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE_SLOW
#include "Mcu_MemMap.h"
/**
* @brief         Mcu_Hw_Cmu_Init
* @details       Service to initialize Cmu
* @param[in]     CmuConfig - Cmu configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Cmu_Init(TT_CONST Mcu_Hw_CmuConfigType * TT_CONST CmuConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(MCU_CMU_ITEM_COUNTS) & (MCU_CMU_ITEM_COUNTS > 0U)
    uint32 i = 0;
#endif

    TT_ParaCheck((CmuConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

   if (TT_RET_SUCCESS == Ret)
    {
    #if defined(MCU_CMU5_USED) && (MCU_CMU5_USED == STD_ON)
        TT_SCU->CMUX[5].CMUX_CR = TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk | TT_SCU_CMUX_CMUX_CR_EN_Msk;
    #endif
    #if defined(MCU_CMU6_USED) && (MCU_CMU6_USED == STD_ON)
        TT_SCU->CMUX[6].CMUX_CR = TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk | TT_SCU_CMUX_CMUX_CR_EN_Msk;
    #endif
    #if defined(MCU_CMU7_USED) && (MCU_CMU7_USED == STD_ON)
        TT_SCU->CMUX[7].CMUX_CR = TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk | TT_SCU_CMUX_CMUX_CR_EN_Msk;
    #endif
    #if defined(MCU_CMU8_USED) && (MCU_CMU8_USED == STD_ON)
        TT_SCU->CMUX[8].CMUX_CR = TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk | TT_SCU_CMUX_CMUX_CR_EN_Msk;
    #endif
    #if defined(MCU_CMU9_USED) && (MCU_CMU9_USED == STD_ON)
        TT_SCU->CMUX[9].CMUX_CR = TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk | TT_SCU_CMUX_CMUX_CR_EN_Msk;
    #endif

    #if defined(MCU_CMU_ITEM_COUNTS) & (MCU_CMU_ITEM_COUNTS > 0U)
        for (i = 0; i < MCU_CMU_ITEM_COUNTS; i++)
        {
            Ret = Mcu_Hw_Cmu_PriItemConfig((TT_CONST Mcu_Hw_CmuConfigType *)&CmuConfig[i]);
            if (TT_RET_SUCCESS != Ret)
            {
                break;
            }
        }
    #endif
   }
   else
   {
       /* do nothing */
   }

#if (TT_SAFETY == STD_ON)
   if(Ret == TT_RET_SUCCESS)
   {
       Ret = Mcu_Hw_Cmu_PriInitCheck(CmuConfig);
   }
#endif

   return Ret;
}
#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
* @brief         Mcu_Hw_Cmu_StopStore
* @details       Service to Store Cmu
* @param[out]     CmuFlag - Cmu enable Flag
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Cmu_StoreStop(uint32 *CmuFlag)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 CmuIndex = 0U;
    uint32 Tmp = 0U;

    TT_ParaCheck((CmuFlag == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        /* Stop all CMU */
        for (CmuIndex = 0; CmuIndex < MCU_CMU_NUMS; CmuIndex++)
        {
            Mcu_PubCmuStatus[CmuIndex] = TT_SCU->CMUX[CmuIndex].CMUX_CR & TT_SCU_CMUX_CMUX_CR_EN_Msk;
            /* stop it */
            TT_SCU->CMUX[CmuIndex].CMUX_CR &= ~TT_SCU_CMUX_CMUX_CR_EN_Msk;
            Tmp += Mcu_PubCmuStatus[CmuIndex];
        }
        *CmuFlag = Tmp;
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Cmu_LoadStart
* @details       Service to Load Cmu
* @param[in]     CmuFlag - Cmu enable Flag
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Cmu_LoadStart(uint32 *CmuFlag)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 CmuIndex = 0U;

    TT_ParaCheck((CmuFlag == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        /* Restore all CMU */
        if (*CmuFlag > 0U)
        {
            for (CmuIndex = 0U; CmuIndex < MCU_CMU_NUMS; CmuIndex++)
            {
                TT_SCU->CMUX[CmuIndex].CMUX_CR |= (Mcu_PubCmuStatus[CmuIndex] > 0U) ? TT_SCU_CMUX_CMUX_CR_EN_Msk : 0U;
            }
        }
    }

    return Ret;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/******************************************************************************
*                         Private Function 
******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if defined(MCU_CMU_ITEM_COUNTS) & (MCU_CMU_ITEM_COUNTS > 0U)
/**
* @brief         Mcu_Hw_Cmu_PriItemConfig
* @details       Cmu configuration
* @param[in]     CmuItem - The pointer of cmu configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Cmu_PriItemConfig(TT_CONST Mcu_Hw_CmuConfigType *CmuItem)
{
    uint32 CmuCr = 0U;
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((CmuItem == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck(((CmuItem != NULL_PTR)&&(CmuItem->CmuTimeoutAlarmEn != TRUE)&&(CmuItem->CmuTimeoutAlarmEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((CmuItem != NULL_PTR)&&(CmuItem->CmuLthdAlarmEn != TRUE)&&(CmuItem->CmuLthdAlarmEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((CmuItem != NULL_PTR)&&(CmuItem->CmuHthdAlarmEn != TRUE)&&(CmuItem->CmuHthdAlarmEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        CmuCr = ((uint32)CmuItem->CmuTimeoutAlarmEn << TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Pos) | \
                ((uint32)CmuItem->CmuLthdAlarmEn << TT_SCU_CMUX_CMUX_CR_LTHD_ALARM_EN_Pos)  | \
                ((uint32)CmuItem->CmuHthdAlarmEn << TT_SCU_CMUX_CMUX_CR_HTHD_ALARM_EN_Pos);

        if (CmuCr > 0U)
        {
            CmuCr |= TT_SCU_CMUX_CMUX_CR_EN_Msk;
            TT_SCU->CMUX[CmuItem->CmuIndex].CMUX_CHKW = CmuItem->CmuChkwAlarmVal;
            TT_SCU->CMUX[CmuItem->CmuIndex].CMUX_THD = (CmuItem->CmuHthdAlarmVal << TT_SCU_CMUX_CMUX_THD_HTHD_Pos) | (CmuItem->CmuLthdAlarmVal << TT_SCU_CMUX_CMUX_THD_LTHD_Pos);
            TT_SCU->CMUX[CmuItem->CmuIndex].CMUX_CR = CmuCr;
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

    return Ret;
}

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Cmu_PriItemConfigCheck
* @details       Cmu configuration Check
* @param[in]     CmuItem - The pointer of cmu configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Cmu_PriItemConfigCheck(TT_CONST Mcu_Hw_CmuConfigType *CmuItem)
{
    uint32 CmuCr = 0U;
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((CmuItem == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        CmuCr = ((uint32)CmuItem->CmuTimeoutAlarmEn << TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Pos) | \
                ((uint32)CmuItem->CmuLthdAlarmEn << TT_SCU_CMUX_CMUX_CR_LTHD_ALARM_EN_Pos)  | \
                ((uint32)CmuItem->CmuHthdAlarmEn << TT_SCU_CMUX_CMUX_CR_HTHD_ALARM_EN_Pos);

        if (CmuCr > 0U)
        {
            CmuCr |= TT_SCU_CMUX_CMUX_CR_EN_Msk;
            if((TT_SCU->CMUX[CmuItem->CmuIndex].CMUX_CHKW != CmuItem->CmuChkwAlarmVal)
                ||(TT_SCU->CMUX[CmuItem->CmuIndex].CMUX_THD != ((CmuItem->CmuHthdAlarmVal << TT_SCU_CMUX_CMUX_THD_HTHD_Pos) | (CmuItem->CmuLthdAlarmVal << TT_SCU_CMUX_CMUX_THD_LTHD_Pos)))
                ||(TT_SCU->CMUX[CmuItem->CmuIndex].CMUX_CR != CmuCr))
            {
                Ret = TT_RET_STATUS_INITCHECK_ERR;
            }
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

    return Ret;
}
#endif
#endif

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Cmu_PriInitCheck
* @details       Service to initialize Check Cmu
* @param[in]     CmuConfig - Cmu configuration
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Cmu_PriInitCheck(TT_CONST Mcu_Hw_CmuConfigType *CmuConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_RetType Ret1 = TT_RET_SUCCESS;
    TT_RetType Ret2 = TT_RET_SUCCESS;
#if defined(MCU_CMU_ITEM_COUNTS) & (MCU_CMU_ITEM_COUNTS > 0U)
    uint32 i = 0;
#endif

    TT_ParaCheck((CmuConfig == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

   if (TT_RET_SUCCESS == Ret)
    {
    #if defined(MCU_CMU5_USED) && (MCU_CMU5_USED == STD_ON)
        if(((TT_SCU->CMUX[5].CMUX_CR & TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk) != TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk)
            ||((TT_SCU->CMUX[5].CMUX_CR & TT_SCU_CMUX_CMUX_CR_EN_Msk) != TT_SCU_CMUX_CMUX_CR_EN_Msk))
        {
            Ret1 = TT_RET_STATUS_INITCHECK_ERR;
        }
    #endif
    #if defined(MCU_CMU6_USED) && (MCU_CMU6_USED == STD_ON)
        if(((TT_SCU->CMUX[6].CMUX_CR & TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk) != TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk)
            ||((TT_SCU->CMUX[6].CMUX_CR & TT_SCU_CMUX_CMUX_CR_EN_Msk) != TT_SCU_CMUX_CMUX_CR_EN_Msk))
        {
            Ret1 = TT_RET_STATUS_INITCHECK_ERR;
        }
    #endif
    #if defined(MCU_CMU7_USED) && (MCU_CMU7_USED == STD_ON)
        if(((TT_SCU->CMUX[7].CMUX_CR & TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk) != TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk)
            ||((TT_SCU->CMUX[7].CMUX_CR & TT_SCU_CMUX_CMUX_CR_EN_Msk) != TT_SCU_CMUX_CMUX_CR_EN_Msk))
        {
            Ret1 = TT_RET_STATUS_INITCHECK_ERR;
        }
    #endif
    #if defined(MCU_CMU8_USED) && (MCU_CMU8_USED == STD_ON)
        if(((TT_SCU->CMUX[8].CMUX_CR & TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk) != TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk)
            ||((TT_SCU->CMUX[8].CMUX_CR & TT_SCU_CMUX_CMUX_CR_EN_Msk) != TT_SCU_CMUX_CMUX_CR_EN_Msk))
        {
            Ret1 = TT_RET_STATUS_INITCHECK_ERR;
        }
    #endif
    #if defined(MCU_CMU9_USED) && (MCU_CMU9_USED == STD_ON)
        if(((TT_SCU->CMUX[9].CMUX_CR & TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk) != TT_SCU_CMUX_CMUX_CR_TIMEOUT_ALARM_EN_Msk)
            ||((TT_SCU->CMUX[9].CMUX_CR & TT_SCU_CMUX_CMUX_CR_EN_Msk) != TT_SCU_CMUX_CMUX_CR_EN_Msk))
        {
            Ret1 = TT_RET_STATUS_INITCHECK_ERR;
        }
    #endif

#if defined(MCU_CMU_ITEM_COUNTS) & (MCU_CMU_ITEM_COUNTS > 0U)
        for (i = 0; i < MCU_CMU_ITEM_COUNTS; i++)
        {
            Ret2 = Mcu_Hw_Cmu_PriItemConfigCheck((TT_CONST Mcu_Hw_CmuConfigType *)&CmuConfig[i]);
            if (TT_RET_SUCCESS != Ret2)
            {
                break;
            }
        }
#endif
   }
   else
   {
       /* do nothing */
   }

   if((Ret1 != TT_RET_SUCCESS)||(Ret2 != TT_RET_SUCCESS))
   {
       Ret = TT_RET_STATUS_INITCHECK_ERR;
   }

   return Ret;
}
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
