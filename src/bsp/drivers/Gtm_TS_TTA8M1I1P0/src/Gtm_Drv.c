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
**  FILENAME     : Gtm_Drv.c                                                  **
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
 *                            Includes
 ******************************************************************************/
#include "Gtm_Drv.h"
#include "Mcu_Drv.h"
#include "Gtm_Hw_Dtm.h"
#include "Gtm_Hw_Tbu.h"
#include "Gtm_Hw_Cmu.h"
#include "Gtm_Hw_Tim.h"
#include "Gtm_Hw_Tom.h"
#include "Gtm_Hw_Interrupt.h"
#include "Base_Tools.h"

#ifdef USING_OS_AUTOSAROS
#include "SchM_Gtm.h"
#endif


/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define GTM_DRV_VENDOR_ID_C                      1541
#define GTM_DRV_MODULE_ID_C                      221
#define GTM_DRV_AR_RELEASE_MAJOR_VERSION_C       4
#define GTM_DRV_AR_RELEASE_MINOR_VERSION_C       4
#define GTM_DRV_AR_RELEASE_PATCH_VERSION_C       0
#define GTM_DRV_SW_MAJOR_VERSION_C               1
#define GTM_DRV_SW_MINOR_VERSION_C               1
#define GTM_DRV_SW_PATCH_VERSION_C               0

/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Gtm_Drv.h Gtm_Drv.c file version check */
#if (GTM_DRV_VENDOR_ID_C != GTM_DRV_VENDOR_ID_H)
    #error "Gtm_Drv.h and Gtm_Drv.c have different vendor ids"
#endif
#if (GTM_DRV_MODULE_ID_C != GTM_DRV_MODULE_ID_H)
    #error "Gtm_Drv.h and Gtm_Drv.c have different module ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != GTM_DRV_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != GTM_DRV_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != GTM_DRV_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.h and Gtm_Drv.c are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != GTM_DRV_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != GTM_DRV_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != GTM_DRV_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.h and Gtm_Drv.c are different"
#endif

/* Gtm_Drv.c Gtm_Hw_Dtm.h file version check */
#if (GTM_DRV_VENDOR_ID_C != GTM_HW_DTM_VENDOR_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Dtm.h have different vendor ids"
#endif
#if (GTM_DRV_MODULE_ID_C != GTM_HW_DTM_MODULE_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Dtm.h have different module ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != GTM_HW_DTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != GTM_HW_DTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != GTM_HW_DTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and Gtm_Hw_Dtm.h are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != GTM_HW_DTM_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != GTM_HW_DTM_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != GTM_HW_DTM_SW_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and Gtm_Hw_Dtm.h are different"
#endif

/* Gtm_Drv.c Gtm_Hw_Tbu.h file version check */
#if (GTM_DRV_VENDOR_ID_C != GTM_HW_TBU_VENDOR_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Tbu.h have different vendor ids"
#endif
#if (GTM_DRV_MODULE_ID_C != GTM_HW_TBU_MODULE_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Tbu.h have different module ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != GTM_HW_TBU_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != GTM_HW_TBU_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != GTM_HW_TBU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and Gtm_Hw_Tbu.h are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != GTM_HW_TBU_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != GTM_HW_TBU_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != GTM_HW_TBU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.c and Gtm_Hw_Tbu.h are different"
#endif

/* Gtm_Drv.c Gtm_Hw_Cmu.h file version check */
#if (GTM_DRV_VENDOR_ID_C != GTM_HW_CMU_VENDOR_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Cmu.h have different vendor ids"
#endif
#if (GTM_DRV_MODULE_ID_C != GTM_HW_CMU_MODULE_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Cmu.h have different module ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and Gtm_Hw_Cmu.h are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != GTM_HW_CMU_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != GTM_HW_CMU_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != GTM_HW_CMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.c and Gtm_Hw_Cmu.h are different"
#endif

/* Gtm_Drv.c Gtm_Hw_Tim.h file version check */
#if (GTM_DRV_VENDOR_ID_C != GTM_HW_TIM_VENDOR_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Tim.h have different vendor ids"
#endif
#if (GTM_DRV_MODULE_ID_C != GTM_HW_TIM_MODULE_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Tim.h have different module ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != GTM_HW_TIM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != GTM_HW_TIM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != GTM_HW_TIM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and Gtm_Hw_Tim.h are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != GTM_HW_TIM_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != GTM_HW_TIM_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != GTM_HW_TIM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.c and Gtm_Hw_Tim.h are different"
#endif

/* Gtm_Drv.c Gtm_Hw_Tom.h file version check */
#if (GTM_DRV_VENDOR_ID_C != GTM_HW_TOM_VENDOR_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Tom.h have different vendor ids"
#endif
#if (GTM_DRV_MODULE_ID_C != GTM_HW_TOM_MODULE_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Tom.h have different module ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != GTM_HW_TOM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != GTM_HW_TOM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != GTM_HW_TOM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and Gtm_Hw_Tom.h are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != GTM_HW_TOM_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != GTM_HW_TOM_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != GTM_HW_TOM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.c and Gtm_Hw_Tom.h are different"
#endif

/* Gtm_Drv.c Gtm_Hw_Interrupt.h file version check */
#if (GTM_DRV_VENDOR_ID_C != GTM_HW_INTERRUPT_VENDOR_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Interrupt.h have different vendor ids"
#endif
#if (GTM_DRV_MODULE_ID_C != GTM_HW_INTERRUPT_MODULE_ID_H)
    #error "Gtm_Drv.c and Gtm_Hw_Interrupt.h have different module ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != GTM_HW_INTERRUPT_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != GTM_HW_INTERRUPT_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != GTM_HW_INTERRUPT_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and Gtm_Hw_Interrupt.h are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != GTM_HW_INTERRUPT_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != GTM_HW_INTERRUPT_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != GTM_HW_INTERRUPT_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.c and Gtm_Hw_Interrupt.h are different"
#endif

/* Gtm_Drv.c Base_Tools.h file version check */
#if (GTM_DRV_VENDOR_ID_C != BASE_TOOLS_VENDOR_ID_H)
    #error "Gtm_Drv.c and Base_Tools.h have different vendor ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and Base_Tools.h are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != BASE_TOOLS_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != BASE_TOOLS_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != BASE_TOOLS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.c and Base_Tools.h are different"
#endif

#ifdef USING_OS_AUTOSAROS
/* Gtm_Drv.c SchM_Gtm.h file version check */
#if (GTM_DRV_VENDOR_ID_C != SCHM_GTM_VENDOR_ID_H)
    #error "Gtm_Drv.c and SchM_Gtm.h have different vendor ids"
#endif
#if ((GTM_DRV_AR_RELEASE_MAJOR_VERSION_C != SCHM_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_MINOR_VERSION_C != SCHM_GTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_AR_RELEASE_PATCH_VERSION_C != SCHM_GTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv.c and SchM_Gtm.h are different"
#endif
#if ((GTM_DRV_SW_MAJOR_VERSION_C != SCHM_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_SW_MINOR_VERSION_C != SCHM_GTM_SW_MINOR_VERSION_H) || \
     (GTM_DRV_SW_PATCH_VERSION_C != SCHM_GTM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv.c and SchM_Gtm.h are different"
#endif
#endif

/******************************************************************************
 *                            Private Typedefs
 *******************************************************************************/

/******************************************************************************
 *                            Private Macros
 *******************************************************************************/
#define GTM_MODULE_ID                           GTM_DRV_MODULE_ID_C
#define GTM_DRV_TT_STATUS_DEFAULT(ApiID)        (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET) | \
                                                             (ApiID << TT_APIID_OFFSET) | \
                                                             (GTM_MODULE_ID << TT_MODULEID_OFFSET))

/******************************************************************************
 *                            Private Constants
 *******************************************************************************/

/******************************************************************************
 *                            Private Variables
 *******************************************************************************/
#define GTM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"

/* GTM submodule status flags */
static Gtm_FlagTypeDef Gtm_PbuFlag = {0};

/* The status flag pointer of the Cmu module */
static Gtm_CmuFlagTypeDef *Cmu_PubFlagPtr = &Gtm_PbuFlag.CmuFlag;

/* The status flag pointer of the Tbu module */
static Gtm_TbuFlagTypeDef *Tbu_PubFlagPtr = &Gtm_PbuFlag.TbuFlag;

/* The status flag pointer of the Tom module */
static Gtm_TomFlagTypeDef *Tom_PubFlagPtr = &Gtm_PbuFlag.TomFlag;

/* The status flag pointer of the Tim module */
static Gtm_TimFlagTypeDef *Tim_PubFlagPtr = &Gtm_PbuFlag.TimFlag;

/* The status flag pointer of the Cdtm module */
static Gtm_CdtmFlagTypeDef *Cdtm_PubFlagPtr = &Gtm_PbuFlag.CdtmFlag[0];

#define GTM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gtm_MemMap.h"
/******************************************************************************
 *                            Public Constants
 *******************************************************************************/

/******************************************************************************
 *                            Public Variables
 *******************************************************************************/

/******************************************************************************
 *                            Private Function Declaration
 ******************************************************************************/
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Drv_PriConfigPtrNullJudge
* @details      Check whether the configuration pointer is empty
* @param[in]    ConfigPtr   Configuration data pointer
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others         - fail
* @pre
*/
static TT_RetType Gtm_Drv_PriConfigPtrNullJudge(TT_CONST Gtm_ConfigType *ConfigPtr);

/**
* @brief        Gtm_Drv_PriCrcCheck
* @details      Configure data CRC check.
* @param[in]    ConfigPtr   Configuration data pointer
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others         - fail
* @pre
*/
static TT_RetType Gtm_Drv_PriCrcCheck(TT_CONST Gtm_ConfigType *ConfigPtr);
#endif

/**
* @brief        Gtm_Drv_PriInitStatusUpdate
* @details      Update gtm and submodule initialization status.
* @param[in]    ConfigPtr   Configuration data pointer
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Drv_PriInitStatusUpdate(TT_CONST Gtm_ConfigType *ConfigPtr);

/**
* @brief        Gtm_Drv_PriArchCmuInit
* @details      Initialize the Arch and Cmu of Gtm and start the Cmu.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Drv_PriArchCmuInit(void);

/**
* @brief        Gtm_Drv_PriParaCheck
* @details      Report the detected error if TEMPLATE_DEV_ERROR_DETECT == STD_ON.The error code contains the GTM function id.
* @param[in]    Expr - boolean expression to check API conditions
* @param[in]    ApiId - Service Id of API
* @param[in]    ErrId - Error Id of Condition
* @param[out]   RetVal - variable to check return type
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Drv_PriParaCheck(boolean Expr, uint32 ApiId, TT_RetType ErrId, TT_RetType *RetVal);

/**
* @brief        Gtm_Drv_PriParaCheck
* @details      Report the detected error if TEMPLATE_DEV_ERROR_DETECT == STD_ON.
* @param[in]    ApiId - Service Id of API
* @param[in]    ErrId - Error Id of Condition
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId);

/**
* @brief        Gtm_Drv_PriRetArrayCheck
* @details      Report an error in the detection array if TEMPLATE_DEV_ERROR_DETECT == STD_ON.
* @param[in]    ApiId - Service Id of API
* @param[in]    ErrId - Error Id of Condition
* @param[in]    Asize - array size
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Drv_PriRetArrayCheck(uint32 ApiId, TT_RetType *ErrId, uint32 Asize);

/******************************************************************************
 *                            Public Functions
 *******************************************************************************/
#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

/******************************************************************************
*  Service name     : Gtm_Drv_Init
*  Syntax           : TT_RetType Gtm_Drv_Init(TT_CONST Gtm_ConfigType *ConfigPtr)
*  Service ID       : 100
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : ConfigPtr : Configuration data pointer
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : This service is used to initialize the GTM module.
******************************************************************************/
TT_RetType Gtm_Drv_Init(TT_CONST Gtm_ConfigType *ConfigPtr)
{
    TT_RetType Ret[8] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS,
                         TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_INITIALIZED), GTM_INIT_ID,
                         TT_RET_STATUS_INIT_ERR, &Ret[0]);
#ifdef GTM_PRECOMPILE_SUPPORT
    Gtm_Drv_PriParaCheck((NULL_PTR != ConfigPtr), GTM_INIT_ID,
                         TT_RET_PARAM_INVALID_DATA_ERR, &Ret[0]);
#else
    Gtm_Drv_PriParaCheck((NULL_PTR == ConfigPtr), GTM_INIT_ID,
                         TT_RET_PARAM_NULL_PTR_ERR, &Ret[0]);
#endif /* GTM_PRECOMPILE_SUPPORT */

    if(Ret[0] == TT_RET_SUCCESS)
    {
#ifdef GTM_PRECOMPILE_SUPPORT
        ConfigPtr = &GtmConfigData;
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        Gtm_Drv_PriParaCheck((Gtm_Drv_PriCrcCheck(ConfigPtr) != TT_RET_SUCCESS),
                             GTM_INIT_ID, TT_RET_PARAM_INVALID_DATA_ERR, &Ret[0]);
        if(Ret[0] == TT_RET_SUCCESS)
        {
#endif
            /****************** Enable GTM clock ******************/
            Ret[0] = Mcu_Drv_Clk_StartModules(TT_SCU_CLK_CONTROL_GTM);
            if(Ret[0] == TT_RET_SUCCESS)
            {
                /****************** ARCH CMU Initialization ****************/
                Ret[0] = Gtm_Drv_PriArchCmuInit();

                /****************** TBU Initialization ****************/
#if (TT_GTM_USED_TBU == TRUE)
                Ret[1] = Gtm_Hw_Tbu_Init(ConfigPtr->TbuConfig);
#endif

                /****************** TIM Initialization ******************/
#if defined(TIM_MAX) && (TIM_MAX != 0)
                Ret[2] = Gtm_Hw_Tim_Configure(ConfigPtr->TimConfig);
                Ret[3] = Gtm_Hw_Interrupt_TimIntInit();
#endif

                /****************** DTM Initialization ******************/
#if (TT_GTM_USE_DTM == TRUE)
                Ret[4] = Gtm_Hw_Dtm_Init();
#endif

                /****************** TOM Initialization ******************/
#if defined(TOM_MAX) && (TOM_MAX != 0)
                Ret[5] = Gtm_Hw_Tom_Configure(ConfigPtr->TomConfig);
                Ret[6] = Gtm_Hw_Interrupt_TomIntInit();
#if (GTM_CONNECTION == TRUE)
                Ret[7] = Gtm_Hw_Tom_SetAllTrigerIn(ConfigPtr->GtmConnectionsConfig);
#endif
#endif

                /****************** Return value check ******************/
                Gtm_Drv_PriRetArrayCheck(GTM_INIT_ID, Ret, 8);

                if(Ret[0] == TT_RET_SUCCESS)
                {
                    Gtm_Drv_PriInitStatusUpdate(ConfigPtr);
                }
                else
                {
                    Gtm_PbuFlag.GtmInitState = GTM_STATE_UNINITIALIZED;
                }
            }
            else
            {
                /* do nothing */
            }
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        }
#endif
    }
    else
    {
        /* do nothing */
    }

    return Ret[0];
}

/******************************************************************************
 *  Service name     : Gtm_Drv_DeInit
 *  Syntax           : TT_RetType Gtm_Drv_DeInit(void)
 *  Service ID       : 101
 *  Sync/Async       : Synchronous
 *  Reentrancy       : Non reentrant
 *  Parameters (in)  : ConfigPtr : Configuration data pointer
 *  Parameters (out) : None
 *  Return value     : TT_RET_SUCCESS: accepted
 *                     Other         : not been accepted
 *  Description      : This service shall de-initialize GTM hardware peripheral and global variables
 ******************************************************************************/
TT_RetType Gtm_Drv_DeInit(void)
{
    TT_RetType Ret[5] = {TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS, TT_RET_SUCCESS};
    uint8 channelIndex = 0;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_INIT_ID,TT_RET_STATUS_INIT_ERR, &Ret[0]);

    if(Ret[0] == TT_RET_SUCCESS)
    {
#if defined(TIM_MAX) && (TIM_MAX != 0)
        for(channelIndex = 0; channelIndex < TIM_MAX; channelIndex++)
        {
            Ret[0] = Gtm_Hw_Tim_DeInit(channelIndex);
            if(Ret[0] != TT_RET_SUCCESS)
            {
                break;
            }
            else
            {
                /* do nothing */
            }
        }
#else
        (void)channelIndex;
#endif

#if defined(TOM_MAX) && (TOM_MAX != 0)
        for(channelIndex = 0; channelIndex < TOM_MAX; channelIndex++)
        {
            Ret[1] = Gtm_Hw_Tom_DeInit(channelIndex);
            if(Ret[1] != TT_RET_SUCCESS)
            {
                break;
            }
            else
            {
                /* do nothing */
            }
        }
#endif

#if (TT_GTM_USED_TBU == TRUE)
        Ret[2] =  Gtm_Hw_Tbu_Stop();
#endif

        Ret[3] = Gtm_Hw_Cmu_Stop();
        Ret[4] = Gtm_Hw_Cmu_DeInit();

        /****************** Return value check ******************/
        Gtm_Drv_PriRetArrayCheck(GTM_INIT_ID, Ret, 5);

        if(Ret[0] == TT_RET_SUCCESS)
        {
            Gtm_PbuFlag.GtmInitState = GTM_STATE_UNINITIALIZED;
            Ret[0] = Mcu_Drv_Clk_StopModules(TT_SCU_CLK_CONTROL_GTM);
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

    return Ret[0];
}

/******************************************************************************
*  service name     : Gtm_Drv_CmuStart
*  Syntax           : TT_RetType Gtm_Drv_CmuStart(void)
*  Service ID       : 102
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Start the Cmu clock.
******************************************************************************/
TT_RetType Gtm_Drv_CmuStart(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_CMU_START_ID,
                         TT_RET_STATUS_INIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Cmu_PubFlagPtr->cmuStatus == GTM_STATUS_RUNNING), GTM_CMU_START_ID,
                         TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Cmu_Start();

        if(Ret == TT_RET_SUCCESS)
        {
            Cmu_PubFlagPtr->cmuStatus = GTM_STATUS_RUNNING;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_CMU_START_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }



    return Ret;
}

/******************************************************************************
*  service name     : Gtm_Drv_CmuStop
*  Syntax           : TT_RetType Gtm_Drv_CmuStop(void)
*  Service ID       : 103
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Stop the Cmu clock.
******************************************************************************/
TT_RetType Gtm_Drv_CmuStop(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_CMU_STOP_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Cmu_PubFlagPtr->cmuStatus == GTM_STATUS_STOPPED), GTM_CMU_STOP_ID,
                         TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Cmu_Stop();

        if(Ret == TT_RET_SUCCESS)
        {
            Cmu_PubFlagPtr->cmuStatus = GTM_STATUS_STOPPED;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_CMU_STOP_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  service name     : Gtm_Drv_CmuGetClock
*  Syntax           : TT_RetType Gtm_Drv_CmuGetClock( Gtm_CmuClkSourceType ClockSource, uint8 ClockIndex, float64 *Clk)
*  Service ID       : 104
*  Reentrancy       : Reentrant
*  Parameters (in)  : clock_source : GTM CMU clock source type (cluster cfgu, fixed and external clock subunit)
*  Parameters (in)  : clock_index  : GTM CMU clock index (index of the subunit clock)
*  Parameters (out) : Clk          : Save the read clock frequency
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the clock frequency of the specified clock source.
******************************************************************************/
TT_RetType Gtm_Drv_CmuGetClock(CmuClkSourceType ClockSource,
                               uint8 ClockIndex,
                               float64 *Clk)
{

    TT_RetType Ret = TT_RET_SUCCESS;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_CMU_GET_CLOCK_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Cmu_GetClock(ClockSource, ClockIndex, Clk);
        Gtm_Drv_PriRetCheck(GTM_CMU_GET_CLOCK_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  service name     : Gtm_Drv_CmuSetClock
*  Syntax           : TT_RetType Gtm_Drv_CmuSetClock(Gtm_CmuClkSourceType ClockSource,uint8 ClockIndex, uint32 ClockFreqOrDiv)
*  Service ID       : 105
*  Reentrancy       : Reentrant
*  Parameters (in)  : ClockSource    : GTM CMU clock source type (cluster cfgu, fixed and external clock subunit)
*  Parameters (in)  : ClockIndex     : GTM CMU clock index (index of the subunit clock)
*  Parameters (in)  : ClockFreqOrDiv : Clock frequency of the clock source to be set
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the clock frequency of the specified clock source.
******************************************************************************/
TT_RetType Gtm_Drv_CmuSetClock(CmuClkSourceType ClockSource,
                               uint8 ClockIndex,
                               uint32 ClockFreqOrDiv)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_CMU_SET_CLOCK_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Cmu_PubFlagPtr->cmuStatus == GTM_STATUS_RUNNING), GTM_CMU_SET_CLOCK_ID,
                         TT_RET_STATUS_INIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Cmu_SetClock(ClockSource, ClockIndex, ClockFreqOrDiv);
        Gtm_Drv_PriRetCheck(GTM_CMU_SET_CLOCK_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}


/******************************************************************************
*  Service name     : Gtm_Drv_TbuStart
*  Syntax           : TT_RetType Gtm_Drv_TbuStart(void)
*  Service ID       : 106
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Start all configured channels of the TBU.
******************************************************************************/
TT_RetType Gtm_Drv_TbuStart(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_SATRT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
#if(GTM_TBU0_USE_CHANNEL0 == TRUE)
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[0] == GTM_STATUS_RUNNING), GTM_TBU_SATRT_ID, TT_RET_STATUS_ERR, &Ret);
#endif
#if(GTM_TBU0_USE_CHANNEL1 == TRUE)
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[1] == GTM_STATUS_RUNNING), GTM_TBU_SATRT_ID, TT_RET_STATUS_ERR, &Ret);
#endif
#if(GTM_TBU0_USE_CHANNEL2 == TRUE)
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[2] == GTM_STATUS_RUNNING), GTM_TBU_SATRT_ID, TT_RET_STATUS_ERR, &Ret);
#endif
#if(GTM_TBU0_USE_CHANNEL3 == TRUE)
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[3] == GTM_STATUS_RUNNING), GTM_TBU_SATRT_ID, TT_RET_STATUS_ERR, &Ret);
#endif

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_Start();
        if(Ret == TT_RET_SUCCESS)
        {
#if(GTM_TBU0_USE_CHANNEL0 == TRUE)
            Tbu_PubFlagPtr->TbuChannelStatus[0] = GTM_STATUS_RUNNING;
#endif
#if(GTM_TBU0_USE_CHANNEL1 == TRUE)
            Tbu_PubFlagPtr->TbuChannelStatus[1] = GTM_STATUS_RUNNING;
#endif
#if(GTM_TBU0_USE_CHANNEL2 == TRUE)
            Tbu_PubFlagPtr->TbuChannelStatus[2] = GTM_STATUS_RUNNING;
#endif
#if(GTM_TBU0_USE_CHANNEL3 == TRUE)
            Tbu_PubFlagPtr->TbuChannelStatus[3] = GTM_STATUS_RUNNING;
#endif
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_TBU_SATRT_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }
#else
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuStop
*  Syntax           : TT_RetType Gtm_Drv_TbuStop(void)
*  Service ID       : 107
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : None
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Stop all channels of the TBU.
******************************************************************************/
TT_RetType Gtm_Drv_TbuStop(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_STOP_ID, TT_RET_STATUS_UNINIT_ERR, &Ret);
#if(GTM_TBU0_USE_CHANNEL0 == TRUE)
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[0] == GTM_STATUS_STOPPED), GTM_TBU_STOP_ID, TT_RET_STATUS_ERR, &Ret);
#endif
#if(GTM_TBU0_USE_CHANNEL1 == TRUE)
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[1] == GTM_STATUS_STOPPED), GTM_TBU_STOP_ID, TT_RET_STATUS_ERR, &Ret);
#endif
#if(GTM_TBU0_USE_CHANNEL2 == TRUE)
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[2] == GTM_STATUS_STOPPED), GTM_TBU_STOP_ID, TT_RET_STATUS_ERR, &Ret);
#endif
#if(GTM_TBU0_USE_CHANNEL3 == TRUE)
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[3] == GTM_STATUS_STOPPED), GTM_TBU_STOP_ID, TT_RET_STATUS_ERR, &Ret);
#endif

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_Stop();
        if(Ret == TT_RET_SUCCESS)
        {
#if(GTM_TBU0_USE_CHANNEL0 == TRUE)
            Tbu_PubFlagPtr->TbuChannelStatus[0] = GTM_STATUS_STOPPED;
#endif
#if(GTM_TBU0_USE_CHANNEL1 == TRUE)
            Tbu_PubFlagPtr->TbuChannelStatus[1] = GTM_STATUS_STOPPED;
#endif
#if(GTM_TBU0_USE_CHANNEL2 == TRUE)
            Tbu_PubFlagPtr->TbuChannelStatus[2] = GTM_STATUS_STOPPED;
#endif
#if(GTM_TBU0_USE_CHANNEL3 == TRUE)
            Tbu_PubFlagPtr->TbuChannelStatus[3] = GTM_STATUS_STOPPED;
#endif
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_TBU_STOP_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }
#else
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
 *  Service name     : Gtm_Drv_TbuStartChannel
 *  Syntax           : TT_RetType Gtm_Drv_TbuStartChannel(uint8 channel)
 *  Service ID       : 108
 *  Sync/Async       : Synchronous
 *  Reentrancy       : Reentrant (but not for the same channel).
 *  Parameters (in)  : channel : Specifies the number of the Tbu channel to be started
 *  Parameters (out) : None
 *  Return value     : TT_RET_SUCCESS: accepted
 *                     Other         : not been accepted
 *  Description      : Start TBU specified channel
 ******************************************************************************/
TT_RetType Gtm_Drv_TbuStartChannel(uint8 channel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_START_CHANNEL_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((channel > TBU_CHANNEL3), GTM_TBU_START_CHANNEL_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tbu_PubFlagPtr->TbuChannelStatus[channel] == GTM_STATUS_RUNNING),
                         GTM_TBU_START_CHANNEL_ID, TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_StartChannel(channel);
        if(Ret == TT_RET_SUCCESS)
        {
            Tbu_PubFlagPtr->TbuChannelStatus[channel] = GTM_STATUS_RUNNING;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_TBU_START_CHANNEL_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)channel;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
 *  Service name     : Gtm_Drv_TbuStopChannel
 *  Syntax           : TT_RetType Gtm_Drv_TbuStopChannel(uint8 channel)
 *  Service ID       : 109
 *  Sync/Async       : Synchronous
 *  Reentrancy       : Reentrant (but not for the same channel).
 *  Parameters (in)  : channel : Specifies the number of the Tbu channel to be started
 *  Parameters (out) : None
 *  Return value     : TT_RET_SUCCESS: accepted
 *                     Other         : not been accepted
 *  Description      : Stop TBU specified channel
 ******************************************************************************/
TT_RetType Gtm_Drv_TbuStopChannel(uint8 channel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_STOP_CHANNEL_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((channel > TBU_CHANNEL2), GTM_TBU_STOP_CHANNEL_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tbu_PubFlagPtr->TbuChannelStatus[channel] == GTM_STATUS_STOPPED),
                         GTM_TBU_STOP_CHANNEL_ID, TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_StopChannel(channel);
        if(Ret == TT_RET_SUCCESS)
        {
            Tbu_PubFlagPtr->TbuChannelStatus[channel] = GTM_STATUS_STOPPED;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_TBU_STOP_CHANNEL_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)channel;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuSetClockChannel
*  Syntax           : TT_RetType Gtm_Drv_TbuSetClockChannel(uint8 channel, uint8 clock_source)
*  Service ID       : 110
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel      : Specifies the number of the Tbu channel to be started
*  Parameters (in)  : clock_source : Tbu clock source type to be set
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the clock source type of the channel specified by the Tbu
******************************************************************************/
TT_RetType Gtm_Drv_TbuSetClockChannel(uint8 channel, uint8 clock_source)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_SET_CLOCK_CHANNEL_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((channel > TBU_CHANNEL2), GTM_TBU_SET_CLOCK_CHANNEL_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tbu_PubFlagPtr->TbuChannelStatus[channel] == GTM_STATUS_RUNNING),
                         GTM_TBU_SET_CLOCK_CHANNEL_ID, TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_SetClockChannel(channel, clock_source);
        Gtm_Drv_PriRetCheck(GTM_TBU_SET_CLOCK_CHANNEL_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)channel;
    (void)clock_source;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuGetClockChannel
*  Syntax           : TT_RetType Gtm_Drv_TbuGetClockChannel(uint8 channel,uint32* clock_source)
*  Service ID       : 111
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel      : Specifies the number of the Tbu channel to be started
*  Parameters (out) : clock_source : Save the read Tbu clock source type
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the clock source type of the channel specified by the Tbu.
******************************************************************************/
TT_RetType Gtm_Drv_TbuGetClockChannel(uint8 channel, uint8 *clock_source)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_GET_CLOCK_CHANNEL_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_GetClockChannel(channel, clock_source);
        Gtm_Drv_PriRetCheck(GTM_TBU_GET_CLOCK_CHANNEL_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)channel;
    (void)clock_source;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuSetTimeBaseChannel
*  Syntax           : TT_RetType Gtm_Drv_TbuSetTimeBaseChannel(uint8 channel, uint32 time_base)
*  Service ID       : 112
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel       Specifies the number of the Tbu channel to be started
*  Parameters (in)  : time_base     Time base value of the Tbu channel
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the time base of the channel specified by the Tbu
*                     The value of TBU_CHx_BASE.BASE can only be written if the TBU channel 0 is disabled
******************************************************************************/
TT_RetType Gtm_Drv_TbuSetTimeBaseChannel(uint8 channel, uint32 time_base)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_SET_TIME_BASE_CHANNEL_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((channel > TBU_CHANNEL3), GTM_TBU_START_CHANNEL_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tbu_PubFlagPtr->TbuChannelStatus[channel] == GTM_STATUS_RUNNING),
                         GTM_TBU_START_CHANNEL_ID, TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_SetTimeBaseChannel(channel, time_base);
        Gtm_Drv_PriRetCheck(GTM_TBU_SET_TIME_BASE_CHANNEL_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)channel;
    (void)time_base;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuGetTimeBaseChannel
*  Syntax           : TT_RetType Gtm_Drv_TbuGetTimeBaseChannel(uint8 channel,uint32 *time_base)
*  Service ID       : 113
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel       Specifies the number of the Tbu channel to be started
*  Parameters (out) : time_base     Save the time base value of the Tbu channel
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the time base of the channel specified by the Tbu
******************************************************************************/
TT_RetType Gtm_Drv_TbuGetTimeBaseChannel(uint8 channel, uint32 *time_base)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_SET_TIME_BASE_CHANNEL_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_GetTimeBaseChannel(channel, time_base);
        Gtm_Drv_PriRetCheck(GTM_TBU_GET_TIME_BASE_CHANNEL_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)channel;
    (void)time_base;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuSetLowResChannel_0
*  Syntax           : TT_RetType Gtm_Drv_TbuSetLowResChannel_0( uint32 low_res)
*  Service ID       : 114
*  Sync/Async       : Synchronous
*  Reentrancy       : Non reentrant
*  Parameters (in)  : low_res : Resolution of the Tbu channel.
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the count resolution of Tbu channel 0.
******************************************************************************/
TT_RetType Gtm_Drv_TbuSetLowResChannel_0(uint8 low_res)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_SET_LOW_RES_CHANNEL0_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Tbu_PubFlagPtr->TbuChannelStatus[0] == GTM_STATUS_RUNNING),
                         GTM_TBU_SET_CLOCK_CHANNEL_ID, TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_SetLowResChannel_0(low_res);
        Gtm_Drv_PriRetCheck(GTM_TBU_SET_LOW_RES_CHANNEL0_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)low_res;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuGetLowResChannel_0
*  Syntax           : TT_RetType Gtm_Drv_TbuGetLowResChannel_0(uint8 *low_res)
*  Service ID       : 115
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : None
*  Parameters (out) : low_res: Save the resolution of the Tbu channel.
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the count resolution of Tbu channel 0.
******************************************************************************/
TT_RetType Gtm_Drv_TbuGetLowResChannel_0(uint8 *low_res)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_GET_LOW_RES_CHANNEL0_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_GetLowResChannel_0(low_res);
        Gtm_Drv_PriRetCheck(GTM_TBU_GET_LOW_RES_CHANNEL0_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)low_res;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuSetRunningModeChannel_12
*  Syntax           : TT_RetType Gtm_Drv_TbuSetRunningModeChannel_12(uint8 channel, Tbu_ChannelModeSelectType running_mode)
*  Service ID       : 116
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel      : Specifies the number of the Tbu channel to be started
*  Parameters (in)  : running_mode : Counting mode of the Tbu channel.
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counting mode of Tbu channel 0 and 1.
******************************************************************************/
TT_RetType Gtm_Drv_TbuSetRunningModeChannel_12(uint8 channel,
                                               Tbu_ChannelModeSelectType running_mode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_SET_RUNNING_MODE_CHANNEL12_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck(((channel != 1) && (channel != 2)), GTM_TBU_SET_RUNNING_MODE_CHANNEL12_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tbu_PubFlagPtr->TbuChannelStatus[channel] == GTM_STATUS_RUNNING), GTM_TBU_SET_CLOCK_CHANNEL_ID,
                         TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_SetRunningModeChannel_12(channel, running_mode);
        Gtm_Drv_PriRetCheck(GTM_TBU_SET_RUNNING_MODE_CHANNEL12_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)channel;
    (void)running_mode;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TbuGetRunningModeChannel_12
*  Syntax           : TT_RetType Gtm_Drv_TbuGetRunningModeChannel_12(uint8 channel, Tbu_ChannelModeSelectType *mode)
*  Service ID       : 117
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : channel : Specifies the number of the Tbu channel to be started
*  Parameters (out) : mode    : Save the counting mode of the Tbu channel.
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counting mode of Tbu channel 0 and 1.
******************************************************************************/
TT_RetType Gtm_Drv_TbuGetRunningModeChannel_12(uint8 channel,
                                               Tbu_ChannelModeSelectType *mode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TBU_GET_RUNNING_MODE_CHANNEL12_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tbu_GetRunningModeChannel_12(channel, mode);
        Gtm_Drv_PriRetCheck(GTM_TBU_GET_RUNNING_MODE_CHANNEL12_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)channel;
    (void)mode;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomChanelEnable
*  Syntax           : TT_RetType Gtm_Drv_TomChanelEnable(Tom_ChannelType tomChannel,
                                                         Tom_ChannelEnableType enableMode,
                                                         Tom_ChannelOutputControlType outputEnableMode)
*  Service ID       : 118
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : tomChannel       : Tom channel
*  Parameters (in)  : enableMode       : Channel enable mode (Enable it immediately or wait for the trigger signal)
*  Parameters (in)  : outputEnableMode : Channel output enable mode (Enable it immediately or wait for the trigger signal)
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Enable the specified Tom channel output.
******************************************************************************/
TT_RetType Gtm_Drv_TomChanelEnable(Tom_ChannelType tomChannel,
                                   Tom_ChannelEnableType enableMode,
                                   Tom_ChannelOutputControlType outputEnableMode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_CHANNEL_ENABLE_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((tomChannel >= TOM_MAX), GTM_TOM_CHANNEL_ENABLE_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tom_PubFlagPtr->TomChannelStatus[tomChannel] == GTM_STATUS_RUNNING), GTM_TOM_CHANNEL_ENABLE_ID,
                         TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_ChanelEnable(tomChannel, enableMode, outputEnableMode);
        if(Ret == TT_RET_SUCCESS)
        {
            Tom_PubFlagPtr->TomChannelStatus[tomChannel] = GTM_STATUS_RUNNING;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_TOM_CHANNEL_ENABLE_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)enableMode;
    (void)outputEnableMode;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomChanelDisable
*  Syntax           : TT_RetType Gtm_Drv_TomChanelDisable(Tom_ChannelType tomChannel,
                                                          Tom_ChannelEnableType disableMode,
                                                          Tom_ChannelOutputControlType outputDisableMode)
*  Service ID       : 119
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : tomChannel        : Tom channel
*  Parameters (in)  : disableMode       : Channel disable mode (Disable it immediately or wait for the trigger signal)
*  Parameters (in)  : outputDisableMode : Channel output disable mode (Disable it immediately or wait for the trigger signal)
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Disable the specified Tom channel output.
******************************************************************************/
TT_RetType Gtm_Drv_TomChanelDisable(Tom_ChannelType tomChannel,
                                    Tom_ChannelEnableType disableMode,
                                    Tom_ChannelOutputControlType outputDisableMode)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_CHANNEL_DISABLE_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((tomChannel >= TOM_MAX),
                         GTM_TOM_CHANNEL_DISABLE_ID, TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tom_PubFlagPtr->TomChannelStatus[tomChannel] == GTM_STATUS_STOPPED),
                         GTM_TOM_CHANNEL_DISABLE_ID, TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_ChanelDisable(tomChannel, disableMode, outputDisableMode);

        if(Ret == TT_RET_SUCCESS)
        {
            Tom_PubFlagPtr->TomChannelStatus[tomChannel] = GTM_STATUS_STOPPED;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_TOM_CHANNEL_DISABLE_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)disableMode;
    (void)outputDisableMode;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetHostTrigger
*  Syntax           : TT_RetType Gtm_Drv_TomSetHostTrigger(uint8 tomInstance, uint8 tgcIndex)
*  Service ID       : 120
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomInstance : Tom instance
*  Parameters (in)  : tgcIndex    : Tgc number
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Generates a host trig signal for the specified TGC of the specified Tom instance
******************************************************************************/
TT_RetType Gtm_Drv_TomSetHostTrigger(uint8 tomInstance, uint8 tgcIndex)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_SET_HOST_TRIGGER_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_SetHostTrigger(tomInstance, tgcIndex);
        Gtm_Drv_PriRetCheck(GTM_TOM_SET_HOST_TRIGGER_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomInstance;
    (void)tgcIndex;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_Tom_SetUpdateCtrl
*  Syntax           : TT_RetType Gtm_Drv_TomSetUpdateCtrl(uint8 tomInstance, uint8 tgcIndex, uint8 mask)
*  Service ID       : 121
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomInstance : Tom instance
*  Parameters (in)  : tgcIndex    : tgc number
*  Parameters (in)  : mask        : Data mask, 1 indicates that the corresponding channel is enabled
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Generates an update signal for the specified TGC of the specified Tom based on the mask
******************************************************************************/
TT_RetType Gtm_Drv_TomSetUpdateCtrl(uint8 tomInstance, uint8 tgcIndex,uint8 mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_SET_UPDATE_CTRL_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_SetUpdateCtrl(tomInstance, tgcIndex, mask);
        Gtm_Drv_PriRetCheck(GTM_TOM_SET_UPDATE_CTRL_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomInstance;
    (void)tgcIndex;
    (void)mask;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterCn0
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterCn0(Tom_ChannelType tomChannel, uint16 Cn0Value)
*  Service ID       : 122
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : Cn0 counter
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter cn0 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterCn0(Tom_ChannelType tomChannel,uint16 Cn0Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_SET_COUNTER_CN0_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_SetCounterCn0(tomChannel, Cn0Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_SET_COUNTER_CN0_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Cn0Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterCn0
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterCn0(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 123
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (out) : Value      : Cn0 counter
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counter cn0 for the channel specified by Tom..
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterCn0(Tom_ChannelType tomChannel, uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_GET_COUNTER_CN0_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_GetCounterCn0(tomChannel, Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_GET_COUNTER_CN0_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterCm0
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterCm0(Tom_ChannelType tomChannel, uint16 Cm0Value)
*  Service ID       : 124
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : Cm0 counter
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter cm0 for the channel specified by Tom..
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterCm0(Tom_ChannelType tomChannel, uint16 Cm0Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_SET_COUNTER_CM0_ID,
                          TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_SetCounterCm0(tomChannel, Cm0Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_SET_COUNTER_CM0_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Cm0Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterCm0
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterCm0(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 125
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (out) : Value      : Cm0 counter
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counter cm0 for the channel specified by Tom..
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterCm0(Tom_ChannelType tomChannel, uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_GET_COUNTER_CM0_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_GetCounterCm0(tomChannel, Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_GET_COUNTER_CM0_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }

#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterCm1
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterCm1(Tom_ChannelType tomChannel, uint16 Cm1Value)
*  Service ID       : 126
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : Cm1 counter
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter cm1 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterCm1(Tom_ChannelType tomChannel, uint16 Cm1Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_SET_COUNTER_CM1_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_SetCounterCm1(tomChannel, Cm1Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_SET_COUNTER_CM1_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Cm1Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterCm1
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterCm1(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 127
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel:Tom channel
*  Parameters (out) : Value:Cm1 counter
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counter cm1 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterCm1(Tom_ChannelType tomChannel, uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_GET_COUNTER_CM1_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_GetCounterCm1(tomChannel, Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_GET_COUNTER_CM1_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterSr0
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterSr0(Tom_ChannelType tomChannel, uint16 Sr0Value)
*  Service ID       : 128
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : Sr0 counter
*  Parameters (out) : None 
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter SR0 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterSr0(Tom_ChannelType tomChannel, uint16 Sr0Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_SET_COUNTER_SR0_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_SetCounterSr0(tomChannel, Sr0Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_SET_COUNTER_SR0_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Sr0Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterSr0
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterSr0(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 129
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (out) : Value      : Sr0 counter
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get the counter SR0 for the channel specified by Tom..
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterSr0(Tom_ChannelType tomChannel, uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_GET_COUNTER_SR0_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_GetCounterSr0(tomChannel, Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_GET_COUNTER_SR0_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetCounterSr1
*  Syntax           : TT_RetType Gtm_Drv_TomSetCounterSr1(Tom_ChannelType tomChannel, uint16 Sr1Value)
*  Service ID       : 130
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (in)  : Cn0Value   : sr1 counter
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the counter SR1 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomSetCounterSr1(Tom_ChannelType tomChannel, uint16 Sr1Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_SET_COUNTER_SR1_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_SetCounterSr1(tomChannel, Sr1Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_SET_COUNTER_SR1_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Sr1Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomGetCounterSr1
*  Syntax           : TT_RetType Gtm_Drv_TomGetCounterSr1(Tom_ChannelType tomChannel,uint16* Value)
*  Service ID       : 131
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel : Tom channel
*  Parameters (out) : Value      : Sr1 counter
*  Return value     : TT_RET_SUCCESS : accepted
*                     Other          : not been accepted
*  Description      : Get the counter SR1 for the channel specified by Tom.
******************************************************************************/
TT_RetType Gtm_Drv_TomGetCounterSr1(Tom_ChannelType tomChannel, uint16 *Value)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_GET_COUNTER_SR1_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_GetCounterSr1(tomChannel, Value);
        Gtm_Drv_PriRetCheck(GTM_TOM_GET_COUNTER_SR1_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Value;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TomSetInt
*  Syntax           : TT_RetType Gtm_Drv_TomSetInt(TT_CONST Tom_ChannelType tomChannel,TT_CONST uint8 Irq_Mask)
*  Service ID       : 132
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : tomChannel: Tom channel
*                     Irq_Mask: bit0:CCU0_IRQ enable/disable,bit1:CCU1_IRQ enable/disable
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCRESS : accepted
*                     Other           : not been accepted
*  Description      : Set the channel interrupt specified by Tom according to Irq_Mask
******************************************************************************/
TT_RetType Gtm_Drv_TomSetInt(TT_CONST Tom_ChannelType tomChannel,
                             TT_CONST uint8 Irq_Mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TOM_SET_INT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((tomChannel >= TOM_MAX), GTM_TOM_SET_INT_ID,
                         TT_RET_PARAM_CHANNEL_ERR,&Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tom_PubFlagPtr->TomChannelStatus[tomChannel] == GTM_STATUS_RUNNING), GTM_TOM_SET_INT_ID,
                         TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tom_SetTomInt(tomChannel, Irq_Mask);
        Gtm_Drv_PriRetCheck(GTM_TOM_SET_INT_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)tomChannel;
    (void)Irq_Mask;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;

}

/******************************************************************************
*  Service name     : Gtm_Drv_TimStartMeasure
*  Syntax           : TT_RetType Gtm_Drv_TimStartMeasure(Tim_ChnnelType TimChannel, boolean immediate)
*  Service ID       : 133
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (in)  : immediate  : at or wait for vaild edge
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Start measuring the specified Tim channel
******************************************************************************/
TT_RetType Gtm_Drv_TimStartMeasure(Tim_ChnnelType TimChannel, uint8 immediate)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    /* params check */
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_START_MEASURE_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((TimChannel >= TIM_MAX), GTM_TIM_START_MEASURE_ID, TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelStatus[TimChannel] == GTM_STATUS_RUNNING), GTM_TIM_START_MEASURE_ID,
                         TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_StartMeasure(TimChannel, immediate);
        if(Ret == TT_RET_SUCCESS)
        {
            Tim_PubFlagPtr->TimChannelStatus[TimChannel] = GTM_STATUS_RUNNING;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_TIM_START_MEASURE_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    (void)immediate;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TimStopMeasure
*  Syntax           : TT_RetType Gtm_Drv_TimStopMeasure(Tim_ChnnelType TimChannel)
*  Service ID       : 134
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Stop measuring the specified Tim channel
******************************************************************************/
TT_RetType Gtm_Drv_TimStopMeasure(Tim_ChnnelType TimChannel)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    /* params check */
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_STOP_MEASURE_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((TimChannel >= TIM_MAX), GTM_TIM_STOP_MEASURE_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelStatus[TimChannel] == GTM_STATUS_STOPPED), GTM_TIM_START_MEASURE_ID,
                         TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_StopMeasure(TimChannel);
        if(Ret == TT_RET_SUCCESS)
        {
            Tim_PubFlagPtr->TimChannelStatus[TimChannel] = GTM_STATUS_STOPPED;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_TIM_STOP_MEASURE_ID, &Ret);
        }
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

#define GTM_START_SEC_CODE_FAST
#include "Gtm_MemMap.h"

/******************************************************************************
*  Service name     : Gtm_Drv_TimGetPwmInformation
*  Syntax           : TT_RetType Gtm_Drv_TimGetPwmInformation(Tim_ChnnelType TimChannel, Tim_PwmInfor * TT_CONST pwmInfor)
*  Service ID       : 135
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (out) : pwmInfor   : Save PWM data 
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get PWM data for a specified Tim channel measurement.
******************************************************************************/
TT_RetType Gtm_Drv_TimGetPwmInformation(Tim_ChnnelType TimChannel,
                                        Tim_PwmInfor *TT_CONST pwmInfor)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    /* params check */
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_GET_PWM_INFORMATION_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((TimChannel >= TIM_MAX), GTM_TIM_GET_PWM_INFORMATION_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelStatus[TimChannel] == GTM_STATUS_STOPPED), GTM_TIM_GET_PWM_INFORMATION_ID,
                         TT_RET_STATUS_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelMode[TimChannel] != TIM_TPWM_MODE), GTM_TIM_GET_PWM_INFORMATION_ID,
                         TT_RET_PARAM_MODE_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_GetPwmInformation(TimChannel, pwmInfor);
        Gtm_Drv_PriRetCheck(GTM_TIM_GET_PWM_INFORMATION_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    (void)pwmInfor;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TimGetMeasureInformation
*  Syntax           : TT_RetType Gtm_Drv_TimGetMeasureInformation(Tim_ChnnelType TimChannel, Tim_MeasureInfor * TT_CONST infor)
*  Service ID       : 136
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (out) : infor      : Save measurement  data
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get measurement data for a specified Tim channel measurement.
******************************************************************************/
TT_RetType Gtm_Drv_TimGetMeasureInformation(Tim_ChnnelType TimChannel,
                                            Tim_MeasureInfor *TT_CONST infor)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_GET_MEASURE_INFORMATION_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((TimChannel >= TIM_MAX), GTM_TIM_GET_MEASURE_INFORMATION_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelStatus[TimChannel] == GTM_STATUS_STOPPED),
                         GTM_TIM_GET_MEASURE_INFORMATION_ID, TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_GetMeasureInformation(TimChannel, infor);
        Gtm_Drv_PriRetCheck(GTM_TIM_GET_MEASURE_INFORMATION_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    (void)infor;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TimGetPulseTime
*  Syntax           : TT_RetType Gtm_Drv_TimGetPulseTime(Tim_ChnnelType TimChannel,float *sumTime)
*  Service ID       : 137
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Get pulse data for a specified Tim channel measurement.
******************************************************************************/
TT_RetType Gtm_Drv_TimGetPulseTime(Tim_ChnnelType TimChannel, float64 *sumTime)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    /* params check */
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_GET_PULSE_TIME_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((TimChannel >= TIM_MAX), GTM_TIM_GET_PULSE_TIME_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelStatus[TimChannel] == GTM_STATUS_STOPPED), GTM_TIM_GET_PULSE_TIME_ID,
                         TT_RET_STATUS_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelMode[TimChannel] != TIM_TPIM_MODE), GTM_TIM_GET_PULSE_TIME_ID,
                         TT_RET_PARAM_MODE_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_GetPulseTime(TimChannel, sumTime);
        Gtm_Drv_PriRetCheck(GTM_TIM_GET_PULSE_TIME_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    (void)sumTime;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

#define GTM_STOP_SEC_CODE_FAST
#include "Gtm_MemMap.h"

#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

/******************************************************************************
*  Service name     : Gtm_Drv_TimGetStatusFlags
*  Syntax           : TT_RetType_t Gtm_Drv_TimGetStatusFlags(Tim_ChnnelType TimChannel,uint8* statusFlags)
*  Service ID       : 138
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel  : Tim channel id
*  Parameters (out) : statusFlags : Save channel status
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Gets the status flag for the specified Tim channel
******************************************************************************/
TT_RetType Gtm_Drv_TimGetStatusFlags(Tim_ChnnelType TimChannel, uint8 *statusFlags)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    /* params check */
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_GET_STATUS_FLAGS_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((TimChannel >= TIM_MAX), GTM_TIM_GET_STATUS_FLAGS_ID,
                         TT_RET_PARAM_CHANNEL_ERR,&Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelStatus[TimChannel] == GTM_STATUS_STOPPED), GTM_TIM_GET_STATUS_FLAGS_ID,
                         TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_GetStatusFlags(TimChannel, statusFlags);
        Gtm_Drv_PriRetCheck(GTM_TIM_GET_STATUS_FLAGS_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    (void)statusFlags;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TimClearStatusFlag
*  Syntax           : TT_RetType Gtm_Drv_TimClearStatusFlag(Tim_ChnnelType TimChannel, uint8 flag_DrvCS)
*  Service ID       : 139
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (in)  : flag_DrvCS : status flag
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                       Other         : not been accepted
*  Description      : Clears the flag specified by the Tim channel
******************************************************************************/
TT_RetType Gtm_Drv_TimClearStatusFlag(Tim_ChnnelType TimChannel, Tim_StatusFlagType flag_DrvCS)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_CLEAR_STATUS_FLAGS_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_ClearStatusFlag(TimChannel, flag_DrvCS);
        Gtm_Drv_PriRetCheck(GTM_TIM_CLEAR_STATUS_FLAGS_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    (void)flag_DrvCS;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TimSetValue
*  Syntax           : TT_RetType Gtm_Drv_TimSetValue(Tim_ChnnelType TimChannel, Gtm_TimChannelValInitSignalType val)
*  Service ID       : 140
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel : Tim channel id
*  Parameters (in)  : val        : Level value
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the Tim channel input level value
******************************************************************************/
TT_RetType Gtm_Drv_TimSetValue(Tim_ChnnelType TimChannel,
                               Tim_ChannelValInitSignalType val)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    /* params check */
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_SET_VALUE_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_SetTimValx(TimChannel, val);
        Gtm_Drv_PriRetCheck(GTM_TIM_SET_VALUE_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    (void)val;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_TimSetInt
*  Syntax           : TT_RetType Gtm_Drv_TimSetInt(TT_CONST Tim_ChnnelType TimChannel,TT_CONST uint8 Irq_Mask)
*  Service ID       : 141
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : TimChannel: Tim channel
*  Parameters (in)  : Irq_Mask: bit0:NEWVAL_IRQ enable/disable,bit1:ECNTOFL_IRQ enable/disable
*                               bit2:CNTOFL_IRQ enable/disable,bit3:GPROFL_IRQ enable/disable
*                               bit4:TODET_IRQ enable/disable,bit5:GLITCHDET_IRQ enable/disable
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Set the interrupt of Tim channel according to Irq_Mask
******************************************************************************/
TT_RetType Gtm_Drv_TimSetInt(TT_CONST Tim_ChnnelType TimChannel,TT_CONST uint8 Irq_Mask)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if defined(TIM_MAX) && (TIM_MAX != 0)
    /* params check */
    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_TIM_SET_INT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((TimChannel >= TIM_MAX), GTM_TIM_SET_INT_ID,
                         TT_RET_PARAM_CHANNEL_ERR, &Ret);
    Gtm_Drv_PriParaCheck((Ret != TT_RET_SUCCESS) || (Tim_PubFlagPtr->TimChannelStatus[TimChannel] == GTM_STATUS_RUNNING),
                         GTM_TIM_SET_INT_ID, TT_RET_STATUS_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_SetTimInt(TimChannel, Irq_Mask);
        Gtm_Drv_PriRetCheck(GTM_TIM_SET_INT_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }
#else
    (void)TimChannel;
    (void)Irq_Mask;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_DtmStart
*  Syntax           : TT_RetType Gtm_Drv_DtmStart(Cdtm_DtmChannelIndexType CdtmDtmChIndex)
*  Service ID       : 142
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : CdtmDtmIndex : GTM DTM Index
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Start all channel outputs of Cdtm's Dtm.
******************************************************************************/
TT_RetType Gtm_Drv_DtmStart(Cdtm_DtmIndexType CdtmDtmIndex)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#if (TT_GTM_USE_DTM == TRUE)
    uint32 Cdtm = 0;
    uint32 Dtm = 0;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_DTM_START_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck(CdtmDtmIndex > CDTM3_DTM5, TT_RET_PARAM_INDEX_ERR,
                         TT_RET_PARAM_LEN_ERR, &Ret);
    if(Ret == TT_RET_SUCCESS)
    {
        Cdtm = Gtm_Hw_Dtm_PriGetCdtmIndex(CdtmDtmIndex);
        Dtm = Gtm_Hw_Dtm_PrinGetDtmIndex(CdtmDtmIndex);

        Gtm_Drv_PriParaCheck((Cdtm_PubFlagPtr[Cdtm].CdtmChannelStatus[Dtm] == GTM_STATUS_RUNNING) , GTM_DTM_START_ID,
                              TT_RET_STATUS_UNINIT_ERR, &Ret);

        if(Cdtm <= CDTM_TOM_MAX_INSTANCE)
        {
            Gtm_Drv_PriParaCheck((Dtm > CDTM_DTM_MAX_NUM), GTM_DTM_START_ID,
                                 TT_RET_PARAM_CHANNEL_ERR, &Ret);
        }else
        {
            Gtm_Drv_PriParaCheck((Dtm < CDTM2_3_DTM_MIN_NUM) || (Dtm > CDTM_DTM_MAX_NUM),
                                 GTM_DTM_START_ID, TT_RET_PARAM_CHANNEL_ERR, &Ret);
        }
    }
    if(Ret == TT_RET_SUCCESS)
    {

        Ret = Gtm_Hw_Dtm_Start(CdtmDtmIndex);
        if(Ret == TT_RET_SUCCESS)
        {
            Cdtm_PubFlagPtr[Cdtm].CdtmChannelStatus[Dtm] = GTM_STATUS_RUNNING;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_DTM_START_ID, &Ret);
        }
    }else
    {
        /* do nothing */
    }
#else
    (void)CdtmDtmIndex;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif

    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_DtmStop
*  Syntax           : TT_RetType Gtm_Drv_DtmStop(Cdtm_DtmChannelIndexType CdtmDtmChIndex)
*  Service ID       : 143
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant (but not for the same channel).
*  Parameters (in)  : CdtmDtmIndex  : GTM DTM Index
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : Stop all channel outputs of Cdtm's Dtm
******************************************************************************/
TT_RetType Gtm_Drv_DtmStop(Cdtm_DtmIndexType CdtmDtmIndex)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#if (TT_GTM_USE_DTM == TRUE)
    uint32 Cdtm = 0;
    uint32 Dtm = 0;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_DTM_STOP_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck(CdtmDtmIndex > CDTM3_DTM5, TT_RET_PARAM_INDEX_ERR,
                         TT_RET_PARAM_LEN_ERR, &Ret);
   if(Ret == TT_RET_SUCCESS)
   {
       Cdtm = Gtm_Hw_Dtm_PriGetCdtmIndex(CdtmDtmIndex);
       Dtm = Gtm_Hw_Dtm_PrinGetDtmIndex(CdtmDtmIndex);

       Gtm_Drv_PriParaCheck((Cdtm_PubFlagPtr[Cdtm].CdtmChannelStatus[Dtm] == GTM_STATUS_STOPPED) , GTM_DTM_START_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

       if(Cdtm <= CDTM_TOM_MAX_INSTANCE)
       {
           Gtm_Drv_PriParaCheck((Dtm > CDTM_DTM_MAX_NUM), GTM_DTM_START_ID,
                                TT_RET_PARAM_CHANNEL_ERR, &Ret);
       }else
       {
           Gtm_Drv_PriParaCheck((Dtm < CDTM2_3_DTM_MIN_NUM) || (Dtm > CDTM_DTM_MAX_NUM),
                                GTM_DTM_START_ID, TT_RET_PARAM_CHANNEL_ERR, &Ret);
       }
   }

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Dtm_Stop(CdtmDtmIndex);
        if(Ret == TT_RET_SUCCESS)
        {
            Cdtm_PubFlagPtr[Cdtm].CdtmChannelStatus[Dtm] = GTM_STATUS_STOPPED;
        }
        else
        {
            Gtm_Drv_PriRetCheck(GTM_DTM_STOP_ID, &Ret);
        }
    }else
    {
        /* do nothing */
    }
#else
    (void)CdtmDtmIndex;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_DtmSetDeadTime
*  Syntax           : TT_RetType Gtm_Drv_DtmSetDeadTime(Cdtm_DtmChannelIndexType CdtmDtmChIndex,
                                                        TT_CONST uint16 riseEdgeTime, 
                                                        TT_CONST uint16 fallEdgeTime)
*  Service ID       : 147
*  Sync/Async       : Synchronous
*  Reentrancy       : Reentrant
*  Parameters (in)  : CdtmDtmChIndex : GTM DTM channel Index
*  Parameters (in)  : riseEdgeTime   : Rise Edge dead time
*  Parameters (in)  : fallEdgeTime   : fall Edge dead time
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS : accepted
*                     Other          : not been accepted
*  Description      : Set the specified channel dead zone time of the Dtm of Cdtm
******************************************************************************/
TT_RetType Gtm_Drv_DtmSetDeadTime(Cdtm_DtmChannelIndexType CdtmDtmChIndex,
                                  uint16 RiseEdgeTime, 
                                  uint16 FallEdgeTime)
{
    TT_RetType Ret = TT_RET_SUCCESS;

#if (TT_GTM_USE_DTM == TRUE)
    uint32 Cdtm = 0;
    uint32 Dtm = 0;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_DTM_SETDEADTIME_ID,
                          TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck(CdtmDtmChIndex > CDTM3_DTM5_CH3, TT_RET_PARAM_INDEX_ERR,
                          TT_RET_PARAM_LEN_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Cdtm = (uint32)CdtmDtmChIndex / ((uint32)CDTM0_DTM5_CH3 + 1U);
        Dtm = (uint32)CdtmDtmChIndex % ((uint32)CDTM0_DTM5_CH3 + 1U);

        if(Cdtm <= CDTM_TOM_MAX_INSTANCE)
        {
            Gtm_Drv_PriParaCheck((Dtm > CDTM_DTM_MAX_NUM), GTM_DTM_SETDEADTIME_ID,
                                 TT_RET_PARAM_CHANNEL_ERR, &Ret);
        }else
        {
            Gtm_Drv_PriParaCheck((Dtm < CDTM2_3_DTM_MIN_NUM) || (Dtm > CDTM_DTM_MAX_NUM),
                                 GTM_DTM_SETDEADTIME_ID, TT_RET_PARAM_CHANNEL_ERR, &Ret);
        }
    }

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Dtm_SetDeadTime(CdtmDtmChIndex, RiseEdgeTime, FallEdgeTime);
        Gtm_Drv_PriRetCheck(GTM_DTM_STOP_ID, &Ret);
    }else
    {
        /* do nothing */
    }
#else
    (void)CdtmDtmChIndex;
    (void)RiseEdgeTime;
    (void)FallEdgeTime;
    Ret = TT_RET_STATUS_UNINIT_ERR;
#endif
    return Ret;
}

/******************************************************************************
*  service name     : Gtm_Drv_SetMonitorClsClock
*  Syntax           : TT_RetType Gtm_Drv_SetMonitorClsClock(TT_CONST uint8 ClsIndex,TT_CONST uint8 ClockDiv)
*  Service ID       : 144
*  Reentrancy       : No reentrant
*  Parameters (in)  : ClsIndex : GTM monitor cluster clock source type (0-3)
*  Parameters (in)  : ClockDiv : GTM monitor cluster clock Div
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS: accepted
*                     Other         : not been accepted
*  Description      : The clock monitoring function of a specified cluster was enabled and clock frequency division was set.
******************************************************************************/
TT_RetType Gtm_Drv_SetMonitorClsClock(TT_CONST ClusterClockType ClsIndex, TT_CONST uint8 ClockDiv)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_Monitor_ClSCLK_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Cmu_SetClsClockMonitor(ClsIndex, ClockDiv);
        Gtm_Drv_PriRetCheck(GTM_Monitor_ClSCLK_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
*  Service name     : Gtm_Drv_SetMonitorTimInput
*  Syntax           : TT_RetType Gtm_Drv_SetMonitorTimInput(uint8 TimIndex,uint8 InputSel,uint8 Osc_Div)
*  Service ID       : 145
*  Sync/Async       : Synchronous
*  Reentrancy       : No reentrant
*  Parameters (in)  : TimIndex: Tim Index (0:TIMch0,...,7:TIMch7)
*                     InputSel: input Sel (0:pad,1:osc,2:eclk0,3:eclk1,4:eclk)
*  Parameters (out) : None
*  Return value     : TT_RET_SUCCESS       set command has been accepted
*                     E_NOT_OK   set command has not been accepted
*  Description      : Set input level
******************************************************************************/
TT_RetType Gtm_Drv_SetMonitorTimInput(uint8 TimIndex,
                                      uint8 InputSel,
                                      uint8 Osc_Div)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    Gtm_Drv_PriParaCheck((Gtm_PbuFlag.GtmInitState == GTM_STATE_UNINITIALIZED), GTM_Monitor_TIMINPUT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Tim_SetInput(TimIndex, InputSel, Osc_Div);
        Gtm_Drv_PriRetCheck(GTM_Monitor_TIMINPUT_ID, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/*****************************************************************************
*  Service name    : Gtm_Drv_GetVersionInfo
*  Syntax          : Gtm_Drv_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
*  Service ID      : 146
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): VersionInfoPtr :Pointer to where to store the version
                     information of this module
*  Return value    : None
*  Description     : Returns the version information of this module.
******************************************************************************/
void Gtm_Drv_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
    TT_RetType RetVal = TT_RET_SUCCESS;

    Gtm_Drv_PriParaCheck(NULL_PTR == VersionInfoPtr, GTM_GETVERSIONINFO_ID, TT_RET_PARAM_NULL_PTR_ERR, &RetVal);

    if(E_OK == RetVal)
    {
        VersionInfoPtr->vendorID = GTM_DRV_VENDOR_ID_C;
        VersionInfoPtr->moduleID = GTM_DRV_MODULE_ID_C;
        VersionInfoPtr->sw_major_version = GTM_DRV_SW_MAJOR_VERSION_C;
        VersionInfoPtr->sw_minor_version = GTM_DRV_SW_MINOR_VERSION_C;
        VersionInfoPtr->sw_patch_version = GTM_DRV_SW_PATCH_VERSION_C;
    }
    else
    {
        /* do nothing */
    }
}

#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

/******************************************************************************
 *                       Private Function
 ******************************************************************************/
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))

#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

/**
* @brief        Gtm_Drv_PriConfigPtrNullJudge
* @details      Check whether the configuration pointer is empty
* @param[in]    ConfigPtr   Configuration data pointer
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others         - fail
* @pre
*/
static TT_RetType Gtm_Drv_PriConfigPtrNullJudge(TT_CONST Gtm_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
#if (TT_GTM_USED_TBU == TRUE)
    Gtm_Drv_PriParaCheck((ConfigPtr->TbuConfig == NULL_PTR), GTM_INIT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
#endif
#if defined(TOM_MAX) && (TOM_MAX != 0)
    Gtm_Drv_PriParaCheck((ConfigPtr->TomConfig->TomChannelConfig == NULL_PTR), GTM_INIT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
    Gtm_Drv_PriParaCheck((ConfigPtr->TomConfig->TomTriggersForTgc == NULL_PTR), GTM_INIT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
#endif
#if defined(TIM_MAX) && (TIM_MAX != 0)
    Gtm_Drv_PriParaCheck((ConfigPtr->TimConfig == NULL_PTR), GTM_INIT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
#endif
#if (GTM_CONNECTION == TRUE)
    Gtm_Drv_PriParaCheck((ConfigPtr->GtmConnectionsConfig == NULL_PTR), GTM_INIT_ID,
                         TT_RET_STATUS_UNINIT_ERR, &Ret);
#endif
    return Ret;
}

/**
* @brief        Gtm_Drv_PriCrcCheck
* @details      Configure data CRC check.
* @param[in]    ConfigPtr   Configuration data pointer
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others         - fail
* @pre
*/
static TT_RetType Gtm_Drv_PriCrcCheck(TT_CONST Gtm_ConfigType *ConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 i = 0;
    uint32 u32AccCRCremainder = 0;
    TT_CONST Gtm_ConnectionsType *ConnectionPtr = NULL_PTR;

    /* Check whether each configuration pointer is empty */
    Gtm_Drv_PriParaCheck((Gtm_Drv_PriConfigPtrNullJudge(ConfigPtr) != TT_RET_SUCCESS),
                          GTM_INIT_ID, TT_RET_STATUS_UNINIT_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
#if (TT_GTM_USED_TBU == TRUE)
        for(i = 0; i < 4; i++)
        {
            Base_AccumulateCRC((uint32)ConfigPtr->TbuConfig[i].TbuChannelModeSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TbuConfig[i].TbuChannelClockSource, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TbuConfig[i].TbuChannelResolution, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TbuConfig[i].TbuEnableChannel, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TbuConfig[i].TbuTimebaseValue, &u32AccCRCremainder);
        }
#endif

#if defined(TOM_MAX) && (TOM_MAX != 0)
        for(i = 0; i < TOM_MAX; i++)
        {
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomHwUnit, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelOutputSignalLevel, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelCounterValCn0, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelPeriodCompareValCm0, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelDutyCycleCompareValCm1, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChPeriodCompareShadowValSr0, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChDCycCompareShadowValSr1, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChUpdateEnableOnCn0Reset, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChEnableForceUpdate, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChResetCn0OnForceUpdate, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelClockSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelCounterCn0Reset, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelExtCounterCn0Reset, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelTriggerOutput, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelExtTriggerOutput, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomUpdownMode, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelOneShotMode, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelTrigOneShotMode, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelSr0Trigger, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomChannelConfig[i].TomChannelBitReversalMode, &u32AccCRCremainder);
        }

        for(i = 0; i < 4; i++)
        {
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcTimeBaseTriggerEnable, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcIntTriggerFromChannel0, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcIntTriggerFromChannel1, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcIntTriggerFromChannel2, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcIntTriggerFromChannel3, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcIntTriggerFromChannel4, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcIntTriggerFromChannel5, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcIntTriggerFromChannel6, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcIntTriggerFromChannel7, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcTbuTimebaseSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TomConfig->TomTriggersForTgc[i].TomTgcTimebaseMatchValue, &u32AccCRCremainder);
        }
#endif

#if defined(TIM_MAX) && (TIM_MAX != 0)
        for(i = 0; i < TIM_MAX; i++)
        {
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimHwUnit, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimAuxInInput, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelInputSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelValInitSignal, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelSignalEdgeSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelClockSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelGpr0InputSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelGpr1InputSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelCntsInputSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelCntsValue, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelTbu0Ts0BitsSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelModeSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelOneShotMode, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelExtCaptureModeEnable, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelExtCaptureSrc, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelEcntResetSetting, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelEcntOvflwSetting, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChannelFilterEnable, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChFilterCounterFreqSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChFilterModeForRisingEdge, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChFilterModeForFallingEdge, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChFilterTimeForRisingEdge, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChFilterTimeForFallingEdge, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChTimeoutDetectionEnable, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChTimeoutClockSelect, &u32AccCRCremainder);
            Base_AccumulateCRC((uint32)ConfigPtr->TimConfig[i].TimChTimeoutDuration, &u32AccCRCremainder);
        }
#endif

#if (GTM_CONNECTION == TRUE)
        ConnectionPtr = &ConfigPtr->GtmConnectionsConfig->GtmTrigger0[0];

        for(i = 0; i < 48; i++)
        {
            Base_AccumulateCRC((uint32)ConnectionPtr[i], &u32AccCRCremainder);
        }
#else
        (void)ConnectionPtr;
#endif

        (void)Base_FinalizeCRC(&u32AccCRCremainder);

        if(u32AccCRCremainder != ConfigPtr->Crc)
        {
            Ret = TT_RET_PARAM_CONFIG_ERR;
        }else
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
#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"
#endif

#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"


/**
* @brief        Gtm_Drv_PriInitStatusUpdate
* @details      Update gtm and submodule initialization status.
* @param[in]    ConfigPtr   Configuration data pointer
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static void Gtm_Drv_PriInitStatusUpdate(TT_CONST Gtm_ConfigType *ConfigPtr)
{
    uint8 ch = 0;
    uint8 instance = 0;

    /* Update module status */
    Gtm_PbuFlag.GtmInitState = GTM_STATE_INITIALIZED;

    /* Update cmu status */
    Cmu_PubFlagPtr->cmuStatus = GTM_STATUS_RUNNING;

#if (TT_GTM_USED_TBU == TRUE)
    /* Update tbu status */
#if(GTM_TBU0_USE_CHANNEL0 == TRUE)
    Tbu_PubFlagPtr->TbuChannelStatus[0] = GTM_STATUS_STOPPED;
#endif /* GTM_TBU0_USE_CHANNEL0 */
#if(GTM_TBU0_USE_CHANNEL1 == TRUE)
    Tbu_PubFlagPtr->TbuChannelStatus[1] = GTM_STATUS_STOPPED;
#endif /* GTM_TBU0_USE_CHANNEL0 */
#if(GTM_TBU0_USE_CHANNEL2 == TRUE)
    Tbu_PubFlagPtr->TbuChannelStatus[2] = GTM_STATUS_STOPPED;
#endif /* GTM_TBU0_USE_CHANNEL0 */
#if(GTM_TBU0_USE_CHANNEL3 == TRUE)
    Tbu_PubFlagPtr->TbuChannelStatus[3] = GTM_STATUS_STOPPED;
#endif /* GTM_TBU0_USE_CHANNEL0 */
#else
    (void)Tbu_PubFlagPtr;
#endif


#if defined(TIM_MAX) && (TIM_MAX != 0)
    /* Update tim status */
    for(ch = 0; ch < TIM_MAX; ch++)
    {
        Tim_PubFlagPtr->TimChannelStatus[ch] = GTM_STATUS_STOPPED;
        Tim_PubFlagPtr->TimChannelMode[ch] = ConfigPtr->TimConfig[ch].TimChannelModeSelect;
    }
#else
    (void)ConfigPtr;
    (void)ch;
    (void)Tim_PubFlagPtr;
#endif

#if defined(TOM_MAX) && (TOM_MAX != 0)
    /* Update tom status */
    for(ch = 0; ch < TOM_MAX; ch++)
    {
        Tom_PubFlagPtr->TomChannelStatus[ch] = GTM_STATUS_STOPPED;
    }
#else
    (void)Tom_PubFlagPtr;
#endif

#if (TT_GTM_USE_DTM == TRUE)
    /* Update dtm status */
    for(instance = 0; instance < 4; instance++)
    {
        for(ch = 0; ch < 6; ch++)
        {
            Cdtm_PubFlagPtr[instance].CdtmChannelStatus[ch] = GTM_STATUS_STOPPED;
        }
    }
#else
    (void)instance;
    (void)Cdtm_PubFlagPtr;
#endif
}

/**
* @brief        Gtm_Drv_PriArchCmuInit
* @details      Initialize the Arch and Cmu of Gtm and start the Cmu.
* @param[in]    None
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Drv_PriArchCmuInit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /****************** GTM ARCH and CMU init ******************/
    Ret = Gtm_Hw_Arch_Cmu_Init();

    if(Ret == TT_RET_SUCCESS)
    {
        Ret = Gtm_Hw_Cmu_Start();
    }
    else
    {
        /* do nothing */
    }


    return Ret;
}

#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

#define GTM_START_SEC_CODE_FAST
#include "Gtm_MemMap.h"
/**
* @brief        Gtm_Drv_PriParaCheck
* @details      Report the detected error if TEMPLATE_DEV_ERROR_DETECT == STD_ON.The error code contains the GTM function id.
* @param[in]    Expr - boolean expression to check API conditions
* @param[in]    ApiId - Service Id of API
* @param[in]    ErrId - Error Id of Condition
* @param[out]   RetVal - variable to check return type
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Drv_PriParaCheck(boolean Expr, uint32 ApiId, TT_RetType ErrId, TT_RetType *RetVal)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if(NULL_PTR != RetVal)
    {
        if((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
        {
            *RetVal = TT_SET_STATUS_TYPE(GTM_DRV_TT_STATUS_DEFAULT(ApiId), ErrId);
#if defined(GTM_DEV_ERROR_DETECT) && (GTM_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(GTM_MODULE_ID, ApiId, ErrId);
            ModuleDet_ReportError(GTM_MODULE_ID,
                                  (uint8)GTM_INSTANCE_ID,
                                  (uint8)ApiId,
                                  (uint8)ErrId);
#endif
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
#else
    (void)Expr;
    (void)ApiId;
    (void)ErrId;
    *(RetVal) = (((uint32)(RetVal) > 1) ? 0U: 1U);
#endif
}

/**
* @brief        Gtm_Drv_PriParaCheck
* @details      Report the detected error if TEMPLATE_DEV_ERROR_DETECT == STD_ON.
* @param[in]    ApiId - Service Id of API
* @param[in]    ErrId - Error Id of Condition
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Drv_PriRetCheck(uint32 ApiId, TT_RetType *ErrId)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    if(NULL_PTR != ErrId)
    {
        if((*ErrId != TT_RET_SUCCESS))
        {
#if defined(GTM_DEV_ERROR_DETECT) && (GTM_DEV_ERROR_DETECT == STD_ON)
            TT_DRV_REPORT_ERR(GTM_MODULE_ID, ApiId, *ErrId);
            ModuleDet_ReportError(GTM_MODULE_ID,
                                  GTM_INSTANCE_ID,
                                  (uint8)ApiId,
                                  (uint8)((*ErrId) & 0xFF));
#endif
            *ErrId = TT_SET_STATUS_TYPE(GTM_DRV_TT_STATUS_DEFAULT(ApiId), *ErrId);
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
#else
    (void)ApiId;
    (void)ErrId;
#endif
}

/**
* @brief        Gtm_Drv_PriRetArrayCheck
* @details      Report an error in the detection array if TEMPLATE_DEV_ERROR_DETECT == STD_ON.
* @param[in]    ApiId - Service Id of API
* @param[in]    ErrId - Error Id of Condition
* @param[in]    Asize - array size
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
LOCAL_INLINE void Gtm_Drv_PriRetArrayCheck(uint32 ApiId, TT_RetType *ErrId, uint32 Asize)
{
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
    uint32 i = 0;

    for(i = 0; i < Asize; i++)
    {
        if(ErrId[i] != TT_RET_SUCCESS)
        {
            Gtm_Drv_PriRetCheck(ApiId, &ErrId[i]);
            ErrId[0] = ErrId[i];
            break;
        }else
        {
            /* do nothing */
        }
    }
#else
    (void)ApiId;
    (void)ErrId;
    (void)Asize;
#endif
}

#define GTM_STOP_SEC_CODE_FAST
#include "Gtm_MemMap.h"

#ifdef __cplusplus
}
#endif
