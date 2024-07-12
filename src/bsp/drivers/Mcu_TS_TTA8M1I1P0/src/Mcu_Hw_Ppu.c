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
**  FILENAME     : Mcu_Hw_Ppu.c                                               **
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
extern "C"{
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Hw_Ppu.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_HW_PPU_VENDOR_ID_C                     1541
#define MCU_HW_PPU_MODULE_ID_C                     101
#define MCU_HW_PPU_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_HW_PPU_AR_RELEASE_MINOR_VERSION_C      4
#define MCU_HW_PPU_AR_RELEASE_PATCH_VERSION_C      0
#define MCU_HW_PPU_SW_MAJOR_VERSION_C              1
#define MCU_HW_PPU_SW_MINOR_VERSION_C              1
#define MCU_HW_PPU_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu_Hw_Ppu.c and Mcu_Hw_Ppu.h file version check */
#if (MCU_HW_PPU_VENDOR_ID_C != MCU_HW_PPU_VENDOR_ID_H)
    #error "Mcu_Hw_Ppu.c and Mcu_Hw_Ppu.h have different vendor id"
#endif
#if (MCU_HW_PPU_MODULE_ID_C != MCU_HW_PPU_MODULE_ID_H)
    #error "Mcu_Hw_Ppu.c and Mcu_Hw_Ppu.h have different module id"
#endif
#if ((MCU_HW_PPU_AR_RELEASE_MAJOR_VERSION_C != MCU_HW_PPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_HW_PPU_AR_RELEASE_MINOR_VERSION_C != MCU_HW_PPU_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_HW_PPU_AR_RELEASE_PATCH_VERSION_C != MCU_HW_PPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu_Hw_Ppu.c and Mcu_Hw_Ppu.h are different"
#endif
#if ((MCU_HW_PPU_SW_MAJOR_VERSION_C != MCU_HW_PPU_SW_MAJOR_VERSION_H) || \
     (MCU_HW_PPU_SW_MINOR_VERSION_C != MCU_HW_PPU_SW_MINOR_VERSION_H) || \
     (MCU_HW_PPU_SW_PATCH_VERSION_C != MCU_HW_PPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu_Hw_Ppu.c and Mcu_Hw_Ppu.h are different"
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

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#define ACCESS_APB_MASK     (0xFFFFU)     /* Access Apb mask  */
#define ACCESS_AHB0_MASK    (0x3FFU)      /* Access Ahb0 mask  */
#define ACCESS_AHB1_MASK    (0x3FFU)      /* Access Ahb1 mask  */
#define ACCESS_AHB4_MASK    (0x1U)        /* Access Ahb4 mask  */

/**
* @brief         Mcu_Hw_Ppu_PriEnUserAccessAhb
* @details       Ppu control all modules enable user access permision
* @param[in]     Type - the moudle will be enable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriEnUserAccessAhb(TT_CONST PPU_CONTROL_Type Type);
/**
* @brief         Mcu_Hw_Ppu_PriDisAccessControlAhb
* @details       Ppu control all modules disenable access permision
* @param[in]     Type - the moudle will be disenable access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriDisAccessControlAhb(TT_CONST PPU_CONTROL_Type Type);

/**
* @brief         Mcu_Hw_Ppu_PriEnAccessControlAhb
* @details       Ppu control all modules enable access permision
* @param[in]     Type - the moudle will be enable access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriEnAccessControlAhb(TT_CONST PPU_CONTROL_Type Type);
/**
* @brief         Mcu_Hw_Ppu_PriDisUserAccessAhb
* @details       Ppu control all modules disenable user access permision
* @param[in]     Type - the moudle will be disenable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriDisUserAccessAhb(TT_CONST PPU_CONTROL_Type Type);

/**
* @brief         Mcu_Hw_Ppu_PriClearAhbErrStatus
* @details       Ppu Clear error Status
* @param[in]     Type - the moudle will be enable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriClearAhbErrStatus(TT_CONST PPU_CONTROL_Type Type);

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Ppu_PriRegReadBack
* @details       Ppu Register Read Back
* @param[in]     ActualValue - Actual Value
* @param[in]     TargetValue - Target Value
* @param[out]    Ret - TT_RET_SUCCESS - success
                 Others - fail
* @return        void
* @retval
* @pre
*/
LOCAL_INLINE void Mcu_Hw_Ppu_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret);
#endif
/******************************************************************************
*                       Public Function
******************************************************************************/
/**
* @brief         Mcu_Hw_Ppu_DisAccessControl
* @details       Ppu control all modules disenable access permision
* @param[in]     Type - the moudle will be disenable access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Ppu_DisAccessControl(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(!MCU_PPU_CONTROL_TYPE_ASSERT(Type), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        MCAL_INSTRUCTION_SYNC_BARRIER();
        if (((uint32)Type >= (uint32)PPU_APB1_START) && ((uint32)Type <= (uint32)PPU_APB1_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB1_LOCKED_Msk) == 0))
        {
            TT_PPU->APB1_EN &= ~(uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB1_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START))), 0, &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB2_START) && ((uint32)Type <= (uint32)PPU_APB2_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB2_LOCKED_Msk) == 0))
        {
            TT_PPU->APB2_EN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB2_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB2_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB2_START))), 0, &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB3_START) && ((uint32)Type <= (uint32)PPU_APB3_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB3_LOCKED_Msk) == 0))
        {
            TT_PPU->APB3_EN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB3_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB3_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB3_START))), 0, &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB4_START) && ((uint32)Type <= (uint32)PPU_APB4_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB4_LOCKED_Msk) == 0))
        {
            TT_PPU->APB4_EN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB4_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB4_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB4_START))), 0, &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB5_START) && ((uint32)Type <= (uint32)PPU_APB5_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB5_LOCKED_Msk) == 0))
        {
            TT_PPU->APB5_EN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB5_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB5_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB5_START))), 0, &Ret);
        #endif
        }
        else
        {
            Ret = Mcu_Hw_Ppu_PriDisAccessControlAhb(Type);
        }

        MCAL_INSTRUCTION_SYNC_BARRIER();
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_EnAccessControl
* @details       Ppu control all modules enable access permision
* @param[in]     Type - the moudle will be enable access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Ppu_EnAccessControl(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((!MCU_PPU_CONTROL_TYPE_ASSERT(Type)), TT_RET_PARAM_ENUM_ERR, &Ret);

    MCAL_INSTRUCTION_SYNC_BARRIER();

    if (TT_RET_SUCCESS == Ret)
    {
        if (((uint32)Type >= (uint32)PPU_APB1_START) && ((uint32)Type <= (uint32)PPU_APB1_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB1_LOCKED_Msk) == 0))
        {
            TT_PPU->APB1_EN |= (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB1_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START))), (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START)), &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB2_START) && ((uint32)Type <= (uint32)PPU_APB2_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB2_LOCKED_Msk) == 0))
        {
            TT_PPU->APB2_EN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB2_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB2_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB2_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB2_START)), &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB3_START) && ((uint32)Type <= (uint32)PPU_APB3_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB3_LOCKED_Msk) == 0))
        {
            TT_PPU->APB3_EN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB3_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB3_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB3_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB3_START)), &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB4_START) && ((uint32)Type <= (uint32)PPU_APB4_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB4_LOCKED_Msk) == 0))
        {
            TT_PPU->APB4_EN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB4_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB4_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB4_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB4_START)), &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB5_START) && ((uint32)Type <= (uint32)PPU_APB5_END) && \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB5_LOCKED_Msk) == 0))
        {
            TT_PPU->APB5_EN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB5_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB5_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB5_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB5_START)), &Ret);
        #endif
        }
        else
        {
            Ret = Mcu_Hw_Ppu_PriEnAccessControlAhb(Type);
        }
        MCAL_INSTRUCTION_SYNC_BARRIER();
    }
    else
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_DisUserAccess
* @details       Ppu control all modules disenable user access permision
* @param[in]     Type - the moudle will be disenable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Ppu_DisUserAccess(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck(((!MCU_PPU_CONTROL_TYPE_ASSERT(Type))), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        (void)Type;
        MCAL_INSTRUCTION_SYNC_BARRIER();
        if (((uint32)Type >= (uint32)PPU_APB1_START) && ((uint32)Type <= (uint32)PPU_APB1_END))
        {
            TT_PPU->APB1_PEN |= (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB1_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START))), (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START)), &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB2_START) && ((uint32)Type <= (uint32)PPU_APB2_END))
        {
            TT_PPU->APB2_PEN = TT_PPU->APB2_PEN | (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB2_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB2_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB2_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB2_START)), &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB3_START) && ((uint32)Type <= (uint32)PPU_APB3_END))
        {
            TT_PPU->APB3_PEN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB3_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB3_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB3_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB3_START)), &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB4_START) && ((uint32)Type <= (uint32)PPU_APB4_END))
        {
            TT_PPU->APB4_PEN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB4_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB4_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB4_START))), (uint32)((uint32)1U <<  ((uint32)Type -(uint32)PPU_APB4_START)), &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB5_START) && ((uint32)Type <= (uint32)PPU_APB5_END))
        {
            TT_PPU->APB5_PEN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB5_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB5_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB5_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB5_START)), &Ret);
        #endif
        }
        else
        {
            Ret = Mcu_Hw_Ppu_PriDisUserAccessAhb(Type);
        }
        MCAL_INSTRUCTION_SYNC_BARRIER();
    }
    else
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_DisUserAccess
* @details       Ppu control all modules enable user access permision
* @param[in]     Type - the moudle will be enable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Ppu_EnUserAccess(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((!MCU_PPU_CONTROL_TYPE_ASSERT(Type)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        (void)Type;
        MCAL_INSTRUCTION_SYNC_BARRIER();
        if (((uint32)Type >= (uint32)PPU_APB1_START) && ((uint32)Type <= (uint32)PPU_APB1_END)&& \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB1_LOCKED_Msk) == 0))
        {
            TT_PPU->APB1_PEN &= ~(uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB1_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START))), 0, &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB2_START) && ((uint32)Type <= (uint32)PPU_APB2_END)&& \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB2_LOCKED_Msk) == 0))
        {
            TT_PPU->APB2_PEN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB2_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB2_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB2_START))), 0, &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB3_START) && ((uint32)Type <= (uint32)PPU_APB3_END)&& \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB3_LOCKED_Msk) == 0))
        {
            TT_PPU->APB3_PEN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)(uint32)PPU_APB3_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB3_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB3_START))), 0, &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB4_START) && ((uint32)Type <= (uint32)PPU_APB4_END)&& \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB4_LOCKED_Msk) == 0))
        {
            TT_PPU->APB4_PEN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB4_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB4_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB4_START))), 0, &Ret);
        #endif
        }
        else if (((uint32)Type >= (uint32)PPU_APB5_START) && ((uint32)Type <= (uint32)PPU_APB5_END)&& \
                ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_APB5_LOCKED_Msk) == 0))
        {
            TT_PPU->APB5_PEN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_APB5_START));
        #if (TT_SAFETY == STD_ON)
            Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->APB5_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_APB5_START))), 0, &Ret);
        #endif
        }
        else
        {
            Ret = Mcu_Hw_Ppu_PriEnUserAccessAhb(Type);
        }
        MCAL_INSTRUCTION_SYNC_BARRIER();
    }
    else
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }

    return Ret;
}

/**
* @brief        Mcu_Hw_Ppu_Config
* @details      Service to Set PPU Config
* @param[in]    McuPpuSettingConfig - PPU setting configuration
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
                Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Ppu_Config(TT_CONST Mcu_Hw_PpuSettingConfigType *McuPpuSettingConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 LockValue = 0U;

    TT_ParaCheck(((McuPpuSettingConfig == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck(((McuPpuSettingConfig != NULL_PTR)&&(McuPpuSettingConfig->McuPpuAPB1ConfigLock != TRUE) && \
                            (McuPpuSettingConfig->McuPpuAPB1ConfigLock != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuPpuSettingConfig != NULL_PTR)&&(McuPpuSettingConfig->McuPpuAPB2ConfigLock != TRUE) && \
                            (McuPpuSettingConfig->McuPpuAPB2ConfigLock != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuPpuSettingConfig != NULL_PTR)&&(McuPpuSettingConfig->McuPpuAPB3ConfigLock != TRUE) && \
                            (McuPpuSettingConfig->McuPpuAPB3ConfigLock != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuPpuSettingConfig != NULL_PTR)&&(McuPpuSettingConfig->McuPpuAPB4ConfigLock != TRUE) && \
                            (McuPpuSettingConfig->McuPpuAPB4ConfigLock != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuPpuSettingConfig != NULL_PTR)&&(McuPpuSettingConfig->McuPpuAPB5ConfigLock != TRUE) && \
                            (McuPpuSettingConfig->McuPpuAPB5ConfigLock != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuPpuSettingConfig != NULL_PTR)&&(McuPpuSettingConfig->McuPpuAHB0ConfigLock != TRUE) && \
                            (McuPpuSettingConfig->McuPpuAHB0ConfigLock != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuPpuSettingConfig != NULL_PTR)&&(McuPpuSettingConfig->McuPpuAHB1ConfigLock != TRUE) && \
                            (McuPpuSettingConfig->McuPpuAHB1ConfigLock != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck(((McuPpuSettingConfig != NULL_PTR)&&(McuPpuSettingConfig->McuPpuAHB4ConfigLock != TRUE) && \
                            (McuPpuSettingConfig->McuPpuAHB4ConfigLock != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        MCAL_INSTRUCTION_SYNC_BARRIER();

        TT_PPU->APB1_EN = (McuPpuSettingConfig->McuPpuAPB1 & ACCESS_APB_MASK);
        TT_PPU->APB2_EN = (McuPpuSettingConfig->McuPpuAPB2 & ACCESS_APB_MASK);
        TT_PPU->APB3_EN = (McuPpuSettingConfig->McuPpuAPB3 & ACCESS_APB_MASK);
        TT_PPU->APB4_EN = (McuPpuSettingConfig->McuPpuAPB4 & ACCESS_APB_MASK);
        TT_PPU->APB5_EN = (McuPpuSettingConfig->McuPpuAPB5 & ACCESS_APB_MASK);
        TT_PPU->AHB0_EN = (McuPpuSettingConfig->McuPpuAHB0 & ACCESS_AHB0_MASK);
        TT_PPU->AHB1_EN = (McuPpuSettingConfig->McuPpuAHB1 & ACCESS_AHB1_MASK);
        TT_PPU->AHB4_EN = (McuPpuSettingConfig->McuPpuAHB4 & ACCESS_AHB4_MASK);

        /* lock config */
        LockValue = ((uint32)McuPpuSettingConfig->McuPpuAPB1ConfigLock << TT_PPU_PLR1_EN_APB1_LOCKED_Pos) | \
                ((uint32)McuPpuSettingConfig->McuPpuAPB2ConfigLock << TT_PPU_PLR1_EN_APB2_LOCKED_Pos) | \
                ((uint32)McuPpuSettingConfig->McuPpuAPB3ConfigLock << TT_PPU_PLR1_EN_APB3_LOCKED_Pos) | \
                ((uint32)McuPpuSettingConfig->McuPpuAPB4ConfigLock << TT_PPU_PLR1_EN_APB4_LOCKED_Pos) | \
                ((uint32)McuPpuSettingConfig->McuPpuAPB5ConfigLock << TT_PPU_PLR1_EN_APB5_LOCKED_Pos) | \
                ((uint32)McuPpuSettingConfig->McuPpuAHB0ConfigLock << TT_PPU_PLR1_EN_AHB0_LOCKED_Pos) | \
                ((uint32)McuPpuSettingConfig->McuPpuAHB1ConfigLock << TT_PPU_PLR1_EN_AHB1_LOCKED_Pos) | \
                ((uint32)McuPpuSettingConfig->McuPpuAHB4ConfigLock << TT_PPU_PLR1_EN_AHB4_LOCKED_Pos);

        TT_PPU->PLR1_EN |= LockValue;
        MCAL_INSTRUCTION_SYNC_BARRIER();

#if (TT_SAFETY == STD_ON)
    if ((TT_PPU->APB1_EN == (McuPpuSettingConfig->McuPpuAPB1 & ACCESS_APB_MASK)) && \
        (TT_PPU->APB2_EN == (McuPpuSettingConfig->McuPpuAPB2 & ACCESS_APB_MASK)) && \
        (TT_PPU->APB3_EN == (McuPpuSettingConfig->McuPpuAPB3 & ACCESS_APB_MASK)) && \
        (TT_PPU->APB4_EN == (McuPpuSettingConfig->McuPpuAPB4 & ACCESS_APB_MASK)) && \
        (TT_PPU->APB5_EN == (McuPpuSettingConfig->McuPpuAPB5 & ACCESS_APB_MASK)) && \
        (TT_PPU->AHB0_EN == (McuPpuSettingConfig->McuPpuAHB0 & ACCESS_AHB0_MASK)) && \
        (TT_PPU->AHB1_EN == (McuPpuSettingConfig->McuPpuAHB1 & ACCESS_AHB1_MASK)) && \
        (TT_PPU->AHB4_EN == (McuPpuSettingConfig->McuPpuAHB4 & ACCESS_AHB4_MASK)) && \
        (TT_PPU->PLR1_EN == LockValue))
        {
            Ret = TT_RET_SUCCESS;
        }
        else
        {
            Ret = TT_RET_STATUS_ERR;
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_GetErrStatus
* @details       Ppu get error Status
* @param[in]     Type - the moudle will be enable user access
* @param[out]    Status - error status
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Ppu_GetErrStatus(TT_CONST PPU_CONTROL_Type Type,uint32 *Status)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((!MCU_PPU_CONTROL_TYPE_ASSERT(Type)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck(((Status == NULL_PTR)), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if (((uint32)Type >= (uint32)PPU_APB1_START) && ((uint32)Type <= (uint32)PPU_APB1_END))
        {
            *Status = (TT_PPU->APB1_ERR >> ((uint32)Type - (uint32)PPU_APB1_START))&0x01U;
        }
        else if (((uint32)Type >= (uint32)PPU_APB2_START) && ((uint32)Type <= (uint32)PPU_APB2_END))
        {
            *Status = (TT_PPU->APB2_ERR >> ((uint32)Type - (uint32)PPU_APB2_START))&0x01U;
        }
        else if (((uint32)Type >= (uint32)PPU_APB3_START) && ((uint32)Type <= (uint32)PPU_APB3_END))
        {
            *Status = (TT_PPU->APB3_ERR >> ((uint32)Type - (uint32)PPU_APB3_START))&0x01U;
        }
        else if (((uint32)Type >= (uint32)PPU_APB4_START) && ((uint32)Type <= (uint32)PPU_APB4_END))
        {
            *Status = (TT_PPU->APB4_ERR >> ((uint32)Type - (uint32)PPU_APB4_START))&0x01U;
        }
        else if (((uint32)Type >= (uint32)PPU_APB5_START) && ((uint32)Type <= (uint32)PPU_APB5_END))
        {
            *Status = (TT_PPU->APB5_ERR >> ((uint32)Type - (uint32)PPU_APB5_START))&0x01U;
        }
        else if (((uint32)Type >= (uint32)PPU_AHB0_START) && ((uint32)Type <= (uint32)PPU_AHB0_END))
        {
            *Status = (TT_PPU->AHB0_ERR >> ((uint32)Type - (uint32)PPU_AHB0_START))&0x01U;
        }
        else if (((uint32)Type >= (uint32)PPU_AHB1_START) && ((uint32)Type <= (uint32)PPU_AHB1_END))
        {
            *Status = (TT_PPU->AHB1_ERR >> ((uint32)Type - (uint32)PPU_AHB1_START))&0x01U;
        }
        else if (((uint32)Type >= (uint32)PPU_AHB4_START) && ((uint32)Type <= (uint32)PPU_AHB4_END))
        {
            *Status = (TT_PPU->AHB4_ERR >> ((uint32)Type - (uint32)PPU_AHB4_START))&0x01U;
        }
        else
        {
            Ret = TT_RET_PARAM_CONFIG_ERR;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_ClearErrStatus
* @details       Ppu Clear error Status
* @param[in]     Type - the moudle will be enable user access
* @param[out]    Status - error status
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
TT_RetType Mcu_Hw_Ppu_ClearErrStatus(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((!MCU_PPU_CONTROL_TYPE_ASSERT(Type)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (TT_RET_SUCCESS == Ret)
    {
        if (((uint32)Type >= (uint32)PPU_APB1_START) && ((uint32)Type <= (uint32)PPU_APB1_END))
        {
            TT_PPU->APB1_ERR = (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB1_START));
        }
        else if (((uint32)Type >= (uint32)PPU_APB2_START) && ((uint32)Type <= (uint32)PPU_APB2_END))
        {
            TT_PPU->APB2_ERR = (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB2_START));
        }
        else if (((uint32)Type >= (uint32)PPU_APB3_START) && ((uint32)Type <= (uint32)PPU_APB3_END))
        {
            TT_PPU->APB3_ERR = (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB3_START));
        }
        else if (((uint32)Type >= (uint32)PPU_APB4_START) && ((uint32)Type <= (uint32)PPU_APB4_END))
        {
            TT_PPU->APB4_ERR = (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB4_START));
        }
        else if (((uint32)Type >= (uint32)PPU_APB5_START) && ((uint32)Type <= (uint32)PPU_APB5_END))
        {
            TT_PPU->APB5_ERR = (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_APB5_START));
        }
        else
        {
            Ret = Mcu_Hw_Ppu_PriClearAhbErrStatus(Type);
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*                            Private Functions
******************************************************************************/
/**
* @brief         Mcu_Hw_Ppu_PriEnUserAccessAhb
* @details       Ppu control all modules enable user access permision
* @param[in]     Type - the moudle will be enable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriEnUserAccessAhb(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (((uint32)Type >= (uint32)PPU_AHB0_START) && ((uint32)Type <= (uint32)PPU_AHB0_END)&& \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB0_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB0_PEN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB0_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB0_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB0_START))), 0, &Ret);
    #endif
    }
    else if (((uint32)Type >= (uint32)PPU_AHB1_START) && ((uint32)Type <= (uint32)PPU_AHB1_END)&& \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB1_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB1_PEN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB1_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB1_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB1_START))), 0, &Ret);
    #endif
    }
    else if (((uint32)Type >= (uint32)PPU_AHB4_START) && ((uint32)Type <= (uint32)PPU_AHB4_END)&& \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB4_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB4_PEN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB4_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB4_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB4_START))), 0, &Ret);
    #endif
    }
    else if (Type == PPU_CONTROL_ALL)
    {
        TT_PPU->APB1_PEN = 0U;
        TT_PPU->APB2_PEN = 0U;
        TT_PPU->APB3_PEN = 0U;
        TT_PPU->APB4_PEN = 0U;
        TT_PPU->APB5_PEN = 0U;
        TT_PPU->AHB0_PEN = 0U;
        TT_PPU->AHB1_PEN = 0U;
        TT_PPU->AHB4_PEN = 0U;
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB1_PEN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB2_PEN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB3_PEN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB4_PEN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB5_PEN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB0_PEN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB1_PEN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB4_PEN, 0, &Ret);
    #endif
    }
    else
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_PriDisAccessControlAhb
* @details       Ppu control all modules disenable access permision
* @param[in]     Type - the moudle will be disenable access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriDisAccessControlAhb(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (((uint32)Type >= (uint32)PPU_AHB0_START) && ((uint32)Type <= (uint32)PPU_AHB0_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB0_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB0_EN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB0_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB0_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB0_START))), 0, &Ret);
    #endif
    }
    else if (((uint32)Type >= (uint32)PPU_AHB1_START) && ((uint32)Type <= (uint32)PPU_AHB1_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB1_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB1_EN &= (uint32)~((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB1_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB1_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB1_START))), 0, &Ret);
    #endif
    }
    else if (((uint32)Type >= (uint32)PPU_AHB4_START) && ((uint32)Type <= (uint32)PPU_AHB4_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB4_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB4_EN &= ~(uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB4_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB4_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB4_START))), 0, &Ret);
    #endif
    }
    else if ((Type == PPU_CONTROL_ALL) && (TT_PPU->PLR1_EN == 0))
    {
        TT_PPU->APB1_EN = 0U;
        TT_PPU->APB2_EN = 0U;
        TT_PPU->APB3_EN = 0U;
        TT_PPU->APB4_EN = 0U;
        TT_PPU->APB5_EN = 0U;
        TT_PPU->AHB0_EN = 0U;
        TT_PPU->AHB1_EN = 0U;
        TT_PPU->AHB4_EN = 0U;
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB1_EN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB2_EN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB3_EN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB4_EN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB5_EN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB0_EN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB1_EN, 0, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB4_EN, 0, &Ret);
    #endif
    }
    else
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_PriEnAccessControlAhb
* @details       Ppu control all modules enable access permision
* @param[in]     Type - the moudle will be enable access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriEnAccessControlAhb(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (((uint32)Type >= (uint32)PPU_AHB0_START) && ((uint32)Type <= (uint32)PPU_AHB0_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB0_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB0_EN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB0_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB0_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB0_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB0_START)), &Ret);
    #endif
    }
    else if (((uint32)Type >= (uint32)PPU_AHB1_START) && ((uint32)Type <= (uint32)PPU_AHB1_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB1_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB1_EN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB1_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB1_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB1_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB1_START)), &Ret);
    #endif
    }
    else if (((uint32)Type >= (uint32)PPU_AHB4_START) && ((uint32)Type <= (uint32)PPU_AHB4_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB4_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB4_EN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB4_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB4_EN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB4_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB4_START)), &Ret);
    #endif
    }
    else if ((Type == PPU_CONTROL_ALL) && (TT_PPU->PLR1_EN == 0))
    {
        TT_PPU->APB1_EN = ACCESS_APB_MASK;
        TT_PPU->APB2_EN = ACCESS_APB_MASK;
        TT_PPU->APB3_EN = ACCESS_APB_MASK;
        TT_PPU->APB4_EN = ACCESS_APB_MASK;
        TT_PPU->APB5_EN = ACCESS_APB_MASK;
        TT_PPU->AHB0_EN = ACCESS_AHB0_MASK;
        TT_PPU->AHB1_EN = ACCESS_AHB1_MASK;
        TT_PPU->AHB4_EN = ACCESS_AHB4_MASK;
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB1_EN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB2_EN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB3_EN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB4_EN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB5_EN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB0_EN, ACCESS_AHB0_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB1_EN, ACCESS_AHB1_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB4_EN, ACCESS_AHB4_MASK, &Ret);
    #endif
    }
    else
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_PriDisUserAccessAhb
* @details       Ppu control all modules disenable user access permision
* @param[in]     Type - the moudle will be disenable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriDisUserAccessAhb(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (((uint32)Type >= (uint32)PPU_AHB0_START) && ((uint32)Type <= (uint32)PPU_AHB0_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB0_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB0_PEN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB0_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB0_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB0_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB0_START)), &Ret);
    #endif
    }
    else if (((uint32)Type >= (uint32)PPU_AHB1_START) && ((uint32)Type <= (uint32)PPU_AHB1_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB1_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB1_PEN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB1_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB1_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB1_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB1_START)), &Ret);
    #endif
    }
    else if (((uint32)Type >= (uint32)PPU_AHB4_START) && ((uint32)Type <= (uint32)PPU_AHB4_END) && \
            ((TT_PPU->PLR1_EN&TT_PPU_PLR1_EN_AHB4_LOCKED_Msk) == 0))
    {
        TT_PPU->AHB4_PEN |= (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB4_START));
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack((TT_PPU->AHB4_PEN & ((uint32)1U << ((uint32)Type - (uint32)PPU_AHB4_START))), (uint32)((uint32)1U <<  ((uint32)Type - (uint32)PPU_AHB4_START)), &Ret);
    #endif
    }
    else if ((Type == PPU_CONTROL_ALL) && (TT_PPU->PLR1_EN == 0))
    {
        TT_PPU->APB1_PEN = ACCESS_APB_MASK;
        TT_PPU->APB2_PEN = ACCESS_APB_MASK;
        TT_PPU->APB3_PEN = ACCESS_APB_MASK;
        TT_PPU->APB4_PEN = ACCESS_APB_MASK;
        TT_PPU->APB5_PEN = ACCESS_APB_MASK;
        TT_PPU->AHB0_PEN = ACCESS_AHB0_MASK;
        TT_PPU->AHB1_PEN = ACCESS_AHB0_MASK;
        TT_PPU->AHB4_PEN = ACCESS_AHB4_MASK;
    #if (TT_SAFETY == STD_ON)
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB1_PEN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB2_PEN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB3_PEN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB4_PEN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->APB5_PEN, ACCESS_APB_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB0_PEN, ACCESS_AHB0_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB1_PEN, ACCESS_AHB1_MASK, &Ret);
        Mcu_Hw_Ppu_PriRegReadBack(TT_PPU->AHB4_PEN, ACCESS_AHB4_MASK, &Ret);
    #endif
    }
    else
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }

    return Ret;
}

/**
* @brief         Mcu_Hw_Ppu_PriClearAhbErrStatus
* @details       Ppu Clear error Status
* @param[in]     Type - the moudle will be enable user access
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
static TT_RetType Mcu_Hw_Ppu_PriClearAhbErrStatus(TT_CONST PPU_CONTROL_Type Type)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if (((uint32)Type >= (uint32)PPU_AHB0_START) && ((uint32)Type <= (uint32)PPU_AHB0_END))
    {
        TT_PPU->AHB0_ERR = (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_AHB0_START));
    }
    else if (((uint32)Type >= (uint32)PPU_AHB1_START) && ((uint32)Type <= (uint32)PPU_AHB1_END))
    {
        TT_PPU->AHB1_ERR = (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_AHB1_START));
    }
    else if (((uint32)Type >= (uint32)PPU_AHB4_START) && ((uint32)Type <= (uint32)PPU_AHB4_END))
    {
        TT_PPU->AHB4_ERR = (uint32)((uint32)1U << ((uint32)Type - (uint32)PPU_AHB4_START));
    }
    else if (Type == PPU_CONTROL_ALL)
    {
        TT_PPU->APB5_ERR = ACCESS_APB_MASK;
        TT_PPU->APB1_ERR = ACCESS_APB_MASK;
        TT_PPU->APB2_ERR = ACCESS_APB_MASK;
        TT_PPU->APB3_ERR = ACCESS_APB_MASK;
        TT_PPU->APB4_ERR = ACCESS_APB_MASK;
        TT_PPU->AHB0_ERR = ACCESS_AHB0_MASK;
        TT_PPU->AHB1_ERR = ACCESS_AHB1_MASK;
        TT_PPU->AHB4_ERR = ACCESS_AHB4_MASK;
    }
    else
    {
        Ret = TT_RET_PARAM_CONFIG_ERR;
    }

    return Ret;
}

#if (TT_SAFETY == STD_ON)
/**
* @brief         Mcu_Hw_Ppu_PriRegReadBack
* @details       Ppu Register Read Back
* @param[in]     ActualValue - Actual Value
* @param[in]     TargetValue - Target Value
* @param[out]    Ret - TT_RET_SUCCESS - success
                 Others - fail
* @return        void
* @retval
* @pre
*/
LOCAL_INLINE void Mcu_Hw_Ppu_PriRegReadBack(uint32 ActualValue,uint32 TargetValue,TT_RetType *Ret)
{
    if(TT_RET_SUCCESS == *Ret)
    {
        if(ActualValue != TargetValue)
        {
            *Ret = TT_RET_OPT_REG_ERR;
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

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
