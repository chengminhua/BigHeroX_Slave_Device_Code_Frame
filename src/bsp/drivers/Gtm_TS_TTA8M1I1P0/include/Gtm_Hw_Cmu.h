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
**  FILENAME     : Gtm_Hw_Cmu.h                                               **
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
#ifndef Gtm_HW_CMU_H
#define Gtm_HW_CMU_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Cmu_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_CMU_VENDOR_ID_H                      1541
#define GTM_HW_CMU_MODULE_ID_H                      221
#define GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_CMU_SW_MAJOR_VERSION_H               1
#define GTM_HW_CMU_SW_MINOR_VERSION_H               1
#define GTM_HW_CMU_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Cmu_Types.h Gtm_Hw_Cmu_.h file version check */
#if (GTM_HW_CMU_TYPES_VENDOR_ID_H != GTM_HW_CMU_VENDOR_ID_H)
    #error "Gtm_Hw_Cmu_Types.h and Gtm_Hw_Cmu_.h have different vendor ids"
#endif

#if (GTM_HW_CMU_TYPES_MODULE_ID_H != GTM_HW_CMU_MODULE_ID_H)
    #error "Gtm_Hw_Cmu_Types.h and Gtm_Hw_Cmu_.h have different module ids"
#endif

#if ((GTM_HW_CMU_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_CMU_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_CMU_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_CMU_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_CMU_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_CMU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Cmu_Types.h and Gtm_Hw_Cmu_.h are different"
#endif

#if ((GTM_HW_CMU_TYPES_SW_MAJOR_VERSION_H != GTM_HW_CMU_SW_MAJOR_VERSION_H) || \
     (GTM_HW_CMU_TYPES_SW_MINOR_VERSION_H != GTM_HW_CMU_SW_MINOR_VERSION_H) || \
     (GTM_HW_CMU_TYPES_SW_PATCH_VERSION_H != GTM_HW_CMU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Cmu_Types.h and Gtm_Hw_Cmu_.h are different"
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

/******************************************************************************
*                    Public Function Declaration
******************************************************************************/
/**
* @brief        Gtm_Hw_Cmu_PriIsIndexValid
* @details      Check that ClockIndex is within the valid range of a particular ClockSource.
* @param[in]    ClockSource:clock source
* @param[in]    ClockIndex:clock index
* @return       boolean
* @retval       TRUE - success
                Others - fail
* @pre
*/
LOCAL_INLINE boolean Gtm_Hw_Cmu_PriIsIndexValid(CmuClkSourceType ClockSource, uint8_t ClockIndex)
{
    boolean isIndexValid = FALSE;

    switch (ClockSource) {
        case GTM_CLUSTER_CLK:
            isIndexValid = ClockIndex <= GTM_CLUSTER_CLK_INDEX_MAX;
            break;

        case CMU_GLOBAL_CLK:
            isIndexValid = ClockIndex <= CMU_GLOBAL_CLK_INDEX_MAX;
            break;

        case CMU_CFGU_CLK:
            isIndexValid = ClockIndex <= CMU_CFGU_CLK_INDEX_MAX;
            break;

        case CMU_FXU_CLK:
            isIndexValid = ClockIndex <= CMU_FXU_CLK_INDEX_MAX;
            break;

        case CMU_EGU_CLK:
            isIndexValid = ClockIndex <= CMU_EGU_CLK_INDEX_MAX;
            break;

        default:
            /* do nothing */
            break;
    }

    return isIndexValid;
}

/**
* @brief        Gtm_Hw_Arch_Cmu_Init
* @details      Initialize the GTM architecture and CMU submodules.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Arch_Cmu_Init(void);

/**
* @brief        Gtm_Hw_Cmu_DeInit
* @details      Deinitialization the Cmu sub module.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_DeInit(void);

/**
* @brief        Gtm_Hw_Cmu_Start
* @details      Start all configured clocks.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_Start(void);

/**
* @brief        Gtm_Hw_Cmu_Stop
* @details      Stop all cmu clocks.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_Stop(void);


/**
* @brief        Gtm_Hw_Cmu_GetClock
* @details      Return a Clock Frequency
* @param[in]    ClockSource : GTM CMU clock source type (cluster cfgu, fixed and external clock subunit)
* @param[in]    ClockIndex  : GTM CMU clock index (index of the subunit clock)
* @param[out]   Value       : Save the read clock frequency
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_GetClock(CmuClkSourceType ClockSource,
                               uint8 ClockIndex,
                               float64* Value);

/**
* @brief        Gtm_Hw_Cmu_SetClock
* @details      Set the clock frequency of the specified clock source
* @param[in]    ClockSource    : GTM CMU clock source type (cluster cfgu, fixed and external clock subunit)
* @param[in]    ClockIndex     : GTM CMU clock index (index of the subunit clock)
* @param[in]    ClockFreqOrDiv : Clock frequency of the clock source to be set
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_SetClock(CmuClkSourceType ClockSource,
                               uint8 ClockIndex,
                               uint32 ClockFreqOrDiv);

/**
* @brief        Gtm_Hw_Cmu_SetClockMonitor
* @details      Set a Clock Monitor.
* @param[in]    ClsIndex : GTM monitor cluster clock source type (0-3)
* @param[in]    ClockDiv : GTM monitor cluster clock Div
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_SetClsClockMonitor(ClusterClockType ClsIndex,uint8 ClockDiv);

/**
* @brief        Gtm_Hw_Cmu_InitCheck
* @details      Cmu initialization check.
* @param[in]    CmuConfig:  Cmu Configuration pointer
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Cmu_InitCheck(TT_CONST Cmu_ConfigType *CmuConfig);


#ifdef __cplusplus
}
#endif

#endif /* Alioth_Gtm_CMU_H */
