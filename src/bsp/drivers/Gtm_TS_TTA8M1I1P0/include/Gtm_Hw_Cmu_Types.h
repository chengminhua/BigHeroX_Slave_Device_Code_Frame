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
**  FILENAME     : Gtm_Hw_Cmu_Types.h                                         **
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
#ifndef GTM_HW_CMU_TYPES_H
#define GTM_HW_CMU_TYPES_H

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
#define GTM_HW_CMU_TYPES_VENDOR_ID_H                      1541
#define GTM_HW_CMU_TYPES_MODULE_ID_H                      221
#define GTM_HW_CMU_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_CMU_TYPES_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_CMU_TYPES_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_CMU_TYPES_SW_MAJOR_VERSION_H               1
#define GTM_HW_CMU_TYPES_SW_MINOR_VERSION_H               1
#define GTM_HW_CMU_TYPES_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Base.h Gtm_Hw_Cmu_Types.h file version check */
#if (GTM_HW_BASE_VENDOR_ID_H != GTM_HW_CMU_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Cmu_Types.h have different vendor ids"
#endif

#if (GTM_HW_BASE_MODULE_ID_H != GTM_HW_CMU_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Cmu_Types.h have different module ids"
#endif

#if ((GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_CMU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H != GTM_HW_CMU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H != GTM_HW_CMU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Cmu_Types.h are different"
#endif

#if ((GTM_HW_BASE_SW_MAJOR_VERSION_H != GTM_HW_CMU_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_SW_MINOR_VERSION_H != GTM_HW_CMU_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_BASE_SW_PATCH_VERSION_H != GTM_HW_CMU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Cmu_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* CMU clock enabled value */
#define CLK_ENABLE                      2U

/* The register bit for CMU configuration clock enable */
#define CMU_EN_CLK0                     0U
#define CMU_EN_CLK1                     2U
#define CMU_EN_CLK2                     4U
#define CMU_EN_CLK3                     6U
#define CMU_EN_CLK4                     8U
#define CMU_EN_CLK5                     10U
#define CMU_EN_CLK6                     12U
#define CMU_EN_CLK7                     14U

/* The register bit for CMU external clock enable */
#define CMU_EN_ECLK0                    16U
#define CMU_EN_ECLK1                    18U
#define CMU_EN_ECLK2                    20U

/* The register bit for CMU fix clock enable */
#define CMU_EN_FXCLK                    22U

/* Clock enable values for each configuration clock */
#define CMU_CLK0_ENABLED                (CLK_ENABLE << CMU_EN_CLK0)
#define CMU_CLK1_ENABLED                (CLK_ENABLE << CMU_EN_CLK1)
#define CMU_CLK2_ENABLED                (CLK_ENABLE << CMU_EN_CLK2)
#define CMU_CLK3_ENABLED                (CLK_ENABLE << CMU_EN_CLK3)
#define CMU_CLK4_ENABLED                (CLK_ENABLE << CMU_EN_CLK4)
#define CMU_CLK5_ENABLED                (CLK_ENABLE << CMU_EN_CLK5)
#define CMU_CLK6_ENABLED                (CLK_ENABLE << CMU_EN_CLK6)
#define CMU_CLK7_ENABLED                (CLK_ENABLE << CMU_EN_CLK7)

/* Clock enable values for each external clock */
#define CMU_ECLK0_ENABLED               (CLK_ENABLE << CMU_EN_ECLK0)
#define CMU_ECLK1_ENABLED               (CLK_ENABLE << CMU_EN_ECLK1)
#define CMU_ECLK2_ENABLED               (CLK_ENABLE << CMU_EN_ECLK2)

/* Clock enable values for each fix clock */
#define CMU_FXCLK_ENABLED               (CLK_ENABLE << CMU_EN_FXCLK)

/* GTM CMU FIXED CLOCK DIV LSB*/
#define CMU_FXCLK_DIV_LSB               16.0f
/* GTM CMU FIXED CLOCK source SEL MAX*/
#define CMU_FXCLK_SEL_MAX               9U

/* GTM Cluster clock max number*/
#define CMU_CLS_CLK_MAX_NUM                 3
/* GTM Cluster clock max DIV*/
#define CMU_CLS_CLK_MAX_DIV                 2U

/* GTM Cluster clock max frequency*/
#define CMU_CLS_CLK_MAX_FRQ                 120000000U

/* Cmu clock enable/disable write value */
#define CMU_CLK_W_ENABLE                     2U
#define CMU_CLK_W_DISABLE                    1U

/* Cmu clock enable/disable read value */
#define CMU_CLK_R_ENABLE                     3U
#define CMU_CLK_R_DISABLE                    0U

/* Cluster clock index maximum and minimum value */
#define GTM_CLUSTER_CLK_INDEX_MIN 0
#define GTM_CLUSTER_CLK_INDEX_MAX 3

/* Global clock index maximum and minimum value */
#define CMU_GLOBAL_CLK_INDEX_MIN 0
#define CMU_GLOBAL_CLK_INDEX_MAX 0

/* Configurable clock index maximum and minimum value */
#define CMU_CFGU_CLK_INDEX_MIN 0
#define CMU_CFGU_CLK_INDEX_MAX 7

/* Fix clock index maximum and minimum value */
#define CMU_FXU_CLK_INDEX_MIN 0
#define CMU_FXU_CLK_INDEX_MAX 4

/* External clock index maximum and minimum value */
#define CMU_EGU_CLK_INDEX_MIN 0
#define CMU_EGU_CLK_INDEX_MAX 2

/******************************************************************************
*                            Enums
*******************************************************************************/
/* Cluster Clock type*/
typedef enum
{
    GTM_CLUSTER_CLK_0 = 0u,
    GTM_CLUSTER_CLK_1,
    GTM_CLUSTER_CLK_2,
    GTM_CLUSTER_CLK_3
}ClusterClockType;

/* CMU Clock type*/
typedef enum
{
    GTM_CLUSTER_CLK = 0u,
    CMU_GLOBAL_CLK,
    CMU_CFGU_CLK,
    CMU_FXU_CLK,
    CMU_EGU_CLK
}CmuClkSourceType;

/* FIX Clock select*/
typedef enum
{
    GTM_GLOBAL_CLOCK = 0,
    CMU_CLOCK_0_DIVIDER,
    CMU_CLOCK_1_DIVIDER,
    CMU_CLOCK_2_DIVIDER,
    CMU_CLOCK_3_DIVIDER,
    CMU_CLOCK_4_DIVIDER,
    CMU_CLOCK_5_DIVIDER,
    CMU_CLOCK_6_DIVIDER,
    CMU_CLOCK_7_DIVIDER
}Cmu_FxdClkSourceSelectType;

/* Configurable Clock6 Source select */
typedef enum
{
    CMU_CLK_6_DIVIDER = 0,
    CMU_SUB_INC2_SIGNAL,
    CMU_SUB_INC1C_SIGNAL
}CmuClk6SourceSelectType;

/* Configurable Clock7 Source select */
typedef enum
{
    CMU_CLK_7_DIVIDER = 0,
    CMU_SUB_INC1_SIGNAL,
    CMU_SUB_INC2C_SIGNAL
}CmuClk7SourceSelectType;

/* Configurable clock type */
typedef enum
{
    CMU_CLK_0 = 0U,
    CMU_CLK_1,
    CMU_CLK_2,
    CMU_CLK_3,
    CMU_CLK_4,
    CMU_CLK_5,
    CMU_CLK_6,
    CMU_CLK_7
} CmuClkType;

/* External Clock type */
typedef enum
{
    CMU_ECLK_0 = 0,
    CMU_ECLK_1 = 0,
    CMU_ECLK_2,
} CmuEclkType;

/* Fix Clock type */
typedef enum
{
    CMU_FXCLK_0 = 0,
    CMU_FXCLK_1,
    CMU_FXCLK_2,
    CMU_FXCLK_3,
    CMU_FXCLK_4
} Cmu_FxClkType;

/* Tim Filter counter clock source select */
typedef enum
{
    CMU_TIM_FILTER_CLK_0,      /* FLT_CNT counts with CMU_CLK0 */
    CMU_TIM_FILTER_CLK_1,      /* FLT_CNT counts with CMU_CLK1 */
    CMU_TIM_FILTER_CLK_6,      /* FLT_CNT counts with CMU_CLK6 */
    CMU_TIM_FILTER_CLK_7       /* FLT_CNT counts with CMU_CLK7 */
} Cmu_TimFilterClkType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* Global clock Frequency division coefficient type */
typedef uint32 Gtm_GlobalClkDivType;

/* Configurable clock Frequency division coefficient type */
typedef uint32 Cmu_ConfigurableClkDivType;

/* External clock Frequency division coefficient type */
typedef uint32 Cmu_ExternalClkNumeratorType;
typedef uint32 Cmu_ExternalClkDenominatorType;

/**
* @brief   The structure contains the Configurable Clock Configuration for GTM
*
* @implements Cmu_ConfigurableClockType_struct
*/
typedef struct
{
    /* Configurable clock 0 enable control */
    boolean                    CmuEnableConfigurableClk0;
    /* configurable clock 0 frequency division  */
    Cmu_ConfigurableClkDivType CmuConfigurableClk0Div;
    /* Configurable clock 1 enable control */
    boolean                    CmuEnableConfigurableClk1;
    /* configurable clock 1 frequency division  */
    Cmu_ConfigurableClkDivType CmuConfigurableClk1Div;
    /* Configurable clock 2 enable control */
    boolean                    CmuEnableConfigurableClk2;
    /* configurable clock 2 frequency division  */
    Cmu_ConfigurableClkDivType CmuConfigurableClk2Div;
    /* Configurable clock 3 enable control */
    boolean                    CmuEnableConfigurableClk3;
    /* configurable clock 3 frequency division  */
    Cmu_ConfigurableClkDivType CmuConfigurableClk3Div;
    /* Configurable clock 4 enable control */
    boolean                    CmuEnableConfigurableClk4;
    /* configurable clock 4 frequency division  */
    Cmu_ConfigurableClkDivType CmuConfigurableClk4Div;
    /* Configurable clock 5 enable control */
    boolean                    CmuEnableConfigurableClk5;
    /* configurable clock 5 frequency division  */
    Cmu_ConfigurableClkDivType CmuConfigurableClk5Div;
    /* Configurable clock 6 enable control */
    boolean                    CmuEnableConfigurableClk6;
    /* Configurable clock 6 clock source select */
    CmuClk6SourceSelectType    CmuClk6SourceSelect;
    /* configurable clock 6 frequency division  */
    Cmu_ConfigurableClkDivType CmuConfigurableClk6Div;
    /* Configurable clock 7 enable control */
    boolean                    CmuEnableConfigurableClk7;
    /* Configurable clock 7 clock source select */
    CmuClk7SourceSelectType    CmuClk7SourceSelect;
    /* configurable clock 7 frequency division  */
    Cmu_ConfigurableClkDivType CmuConfigurableClk7Div;
}Cmu_ConfigurableClockType;

/**
* @brief   The structure contains the External Clock Configuration for GTM.
*
* @implements Cmu_ExternalClockType_struct
*/
typedef struct
{
    /* External clock 0 enable */
    boolean                        CmuEnableExternalClk0;
    /* External clock 0 division numerator */
    Cmu_ExternalClkNumeratorType   CmuExternalClk0Numerator;
    /* External clock 0 division denominator */
    Cmu_ExternalClkDenominatorType CmuExternalClk0Denominator;
    /* External clock 1 enable */
    boolean                        CmuEnableExternalClk1;
    /* External clock 1 division numerator */
    Cmu_ExternalClkNumeratorType   CmuExternalClk1Numerator;
    /* External clock 1 division denominator */
    Cmu_ExternalClkDenominatorType CmuExternalClk1Denominator;
    /* External clock 2 enable */
    boolean                        CmuEnableExternalClk2;
    /* External clock 1 division numerator */
    Cmu_ExternalClkNumeratorType   CmuExternalClk2Numerator;
    /* External clock 2 division denominator */
    Cmu_ExternalClkDenominatorType CmuExternalClk2Denominator;
}Cmu_ExternalClockType;

/**
* @brief   The structure contains the cmu config.
*
* @implements Gtm_CmuConfigType_struct
*/
typedef struct
{
    /* All fixed clocks Enable */
    boolean                    CmuEnableAllFixedClocks;
    /* Fixed clock source select */
    Cmu_FxdClkSourceSelectType CmuFxdClkSourceSelect;
    /* Configurable clock poniter */
    Cmu_ConfigurableClockType* CmuConfigurableClock;
    /* External clock poniter */
    Cmu_ExternalClockType*     CmuExternalClock;
}Cmu_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* Alioth_GTM_HW_CMU_TYPES_H */
