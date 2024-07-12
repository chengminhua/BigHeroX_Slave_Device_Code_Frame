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
**  FILENAME     : Platform_Hw_Mpu.c                                          **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Source File                                **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Hw_Mpu.h"
#if (defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)) || (defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON))
#include "Platform_Hw_Cache.h"
#endif
#ifdef USING_OS_AUTOSAROS
#include "SchM_Platform.h" 
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_MPU_VENDOR_ID_C                     1541
#define PLATFORM_HW_MPU_MODULE_ID_C                     219
#define PLATFORM_HW_MPU_AR_RELEASE_MAJOR_VERSION_C      4
#define PLATFORM_HW_MPU_AR_RELEASE_MINOR_VERSION_C      4
#define PLATFORM_HW_MPU_AR_RELEASE_PATCH_VERSION_C      0
#define PLATFORM_HW_MPU_SW_MAJOR_VERSION_C              1
#define PLATFORM_HW_MPU_SW_MINOR_VERSION_C              1
#define PLATFORM_HW_MPU_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_Mpu.c and Platform_Hw_Mpu.h file version check */
#if (PLATFORM_HW_MPU_VENDOR_ID_C != PLATFORM_HW_MPU_VENDOR_ID_H)
    #error "Platform_Hw_Mpu.c and Platform_Hw_Mpu.h have different vendor id"
#endif
#if (PLATFORM_HW_MPU_MODULE_ID_C != PLATFORM_HW_MPU_MODULE_ID_H)
    #error "Platform_Hw_Mpu.c and Platform_Hw_Mpu.h have different module id"
#endif
#if ((PLATFORM_HW_MPU_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_MPU_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MPU_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_MPU_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_MPU_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_MPU_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_Mpu.c and Platform_Hw_Mpu.h are different"
#endif
#if ((PLATFORM_HW_MPU_SW_MAJOR_VERSION_C != PLATFORM_HW_MPU_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MPU_SW_MINOR_VERSION_C != PLATFORM_HW_MPU_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_MPU_SW_PATCH_VERSION_C != PLATFORM_HW_MPU_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_Mpu.c and Platform_Hw_Mpu.h are different"
#endif

#if (defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)) || (defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON))
/* Platform_Hw_Mpu.c and Platform_Hw_Cache.h file version check */
#if (PLATFORM_HW_MPU_VENDOR_ID_C != PLATFORM_HW_CACHE_VENDOR_ID_H)
    #error "Platform_Hw_Mpu.c and Platform_Hw_Cache.h have different vendor id"
#endif
#if (PLATFORM_HW_MPU_MODULE_ID_C != PLATFORM_HW_CACHE_MODULE_ID_H)
    #error "Platform_Hw_Mpu.c and Platform_Hw_Cache.h have different module id"
#endif
#if ((PLATFORM_HW_MPU_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MPU_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_MPU_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_Mpu.c and Platform_Hw_Cache.h are different"
#endif
#if ((PLATFORM_HW_MPU_SW_MAJOR_VERSION_C != PLATFORM_HW_CACHE_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MPU_SW_MINOR_VERSION_C != PLATFORM_HW_CACHE_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_MPU_SW_PATCH_VERSION_C != PLATFORM_HW_CACHE_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_Mpu.c and Platform_Hw_Cache.h are different"
#endif
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
#define PLATFORM_START_SEC_CONST_8
#include "Platform_MemMap.h"

static TT_CONST uint8 Platform_PubMemoryTypeValues[TT_MPU_MEM_NO] =
{
    /* 7-6, 5-3, 2, 1, 0 bit S always clear to not influence previous setting
     *      Res, TEX, S, C, B */
    0x00U, /*0b00000000,  MPU_M7_MEMORY_TYPE_STRONG_ORDER  */
    0x01U, /*0b00000001,  MPU_M7_MEMORY_TYPE_DEVICE_SHARED */
    0x02U, /*0b00000010,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_THROUGH */
    0x03U, /*0b00000011,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_BACK1 */
    0x08U, /*0b00001000,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_NO_CACHE */
    0x0BU, /*0b00001011,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_BACK2 */
    0x10U, /*0b00010000,  MPU_M7_MEMORY_TYPE_DEVICE_NOSHARE */
    0x20U  /*0b00100000   MPU_M7_MEMORY_TYPE_NORMAL_CACHEABLE */
};

#define PLATFORM_STOP_SEC_CONST_8
#include "Platform_MemMap.h"
/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/*!
 * @brief Calculate log2(n) size for a specific region
 *
 * @param[in] u32StartAddr Region Start address
 * @param[in] u32EndAddr   Region End address
 *
 * @return Region size as a power of 2
 */
static uint32 Platform_Hw_Mpu_PriCalculateRegionSize(TT_CONST uint32 u32StartAddr, TT_CONST uint32 u32EndAddr);

/*!
 * @brief Configure memory type
 *
 * @param[out] pRegionAttr RASR register where to save the attributes
 * @param[in]  eType       Memory type
 *
 * @return void
 */
static void Platform_Hw_Mpu_PriSetMemoryType(uint32 * TT_CONST pRegionAttr, TT_CONST Platform_Hw_MpuMemoryType eType);

/*!
 * @brief Set inner and outer cache policies
 *
 * @param[out] pRegionAttr   RASR register where to save the attributes
 * @param[in]  eInnerPolicy  Inner cache policy
 * @param[in]  eOuterPolicy  Outer cache policy
 *
 * @return void
 */
static void Platform_Hw_Mpu_PriSetCachePolicies(uint32 * TT_CONST pRegionAttr,
                                             TT_CONST Platform_Hw_MpuCachePolicyType eInnerPolicy,
                                             TT_CONST Platform_Hw_MpuCachePolicyType eOuterPolicy);

/*!
 * @brief Compute access rights
 *
 * @param[out] pRegionAttr   RASR register where to save the attributes
 * @param[in]  eAccessRights Region access rights
 *
 * @return void
 */
static void Platform_Hw_Mpu_PriComputeAccessRights(uint32 * TT_CONST pRegionAttr,
                                                TT_CONST Platform_Hw_MpuAccessRightsType eAccessRights);

/*!
 * @brief Retrieve fault information from SCB
 *
 * @param[out] pMmfsr   SCB->MMFSR register contents
 * @param[out] pAddress Address of the violation
 *
 * @return void
 */
static void Platform_Hw_Mpu_PriGetErrorRegisters(uint32 * TT_CONST pMmfsr, uint32 * TT_CONST pAddress);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define PLATFORM_START_SEC_CODE_SLOW
#include "Platform_MemMap.h"

/**
 * @brief       Initializes the Memory Protection Unit general parameters and
 *              region configurations.
 * @details     This function is non-reentrant.
 * @param[in]   pConfig  Pointer to configuration structure for MPU M7.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @api
 */
TT_RetType Platform_Hw_Mpu_Init(TT_CONST Platform_Hw_MpuConfigType * TT_CONST pConfig)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 d_region = 0;
    uint8 region = 0;
    TT_CONST Platform_Hw_MpuRegionConfigType * regionCfg = NULL_PTR;

    Ret = Platform_Hw_Mpu_GetDRegion(&d_region);
    TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck(((pConfig == NULL_PTR) || (pConfig->RegionConfigArr == NULL_PTR)),
                 TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((pConfig != NULL_PTR) && ((pConfig->RegionCnt >= d_region)), TT_RET_PARAM_COUNT_ERR, &Ret);
    TT_ParaCheck((pConfig != NULL_PTR) && ((pConfig->DefaultMapEn != TRUE)&&(pConfig->DefaultMapEn != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((pConfig != NULL_PTR) && ((pConfig->EnableRunHFNMI != TRUE)&&(pConfig->EnableRunHFNMI != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((pConfig != NULL_PTR) && ((pConfig->EnMemManageInterrupt != TRUE)&&(pConfig->EnMemManageInterrupt != FALSE)), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        /* Reset the peripheral to the default settings */
        Ret = Platform_Hw_Mpu_Deinit();
        TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);

        /* Configure MPU general settings */
        if (pConfig->DefaultMapEn == TRUE)
        {
            TT_MPU->CTRL |=TT_MPU_CTRL_PRIVDEFENA_MASK;
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(((TT_MPU->CTRL & TT_MPU_CTRL_PRIVDEFENA_MASK) == 0), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }
        else
        {
            TT_MPU->CTRL &= (~((uint32)TT_MPU_CTRL_PRIVDEFENA_MASK));
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(((TT_MPU->CTRL & TT_MPU_CTRL_PRIVDEFENA_MASK) != 0), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }

        if (pConfig->EnableRunHFNMI == TRUE)
        {
            TT_MPU->CTRL |=TT_MPU_CTRL_HFNMIENA_MASK;
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(((TT_MPU->CTRL & TT_MPU_CTRL_HFNMIENA_MASK) == 0), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }
        else
        {
            TT_MPU->CTRL &= (~((uint32)TT_MPU_CTRL_HFNMIENA_MASK));
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(((TT_MPU->CTRL & TT_MPU_CTRL_HFNMIENA_MASK) != 0), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }

        if (pConfig->EnMemManageInterrupt == TRUE)
        {
            TT_SCB->SHCSR |= TT_SCB_SHCSR_MEMFAULTENA_Msk;
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(((TT_SCB->SHCSR & TT_SCB_SHCSR_MEMFAULTENA_Msk) == 0), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }
        else
        {
            TT_SCB->SHCSR &= ~TT_SCB_SHCSR_MEMFAULTENA_Msk;
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(((TT_SCB->SHCSR & TT_SCB_SHCSR_MEMFAULTENA_Msk) != 0), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }

        for (region = 0U; ((Ret == TT_RET_SUCCESS)&&(region < pConfig->RegionCnt)) ; region++)
        {
            regionCfg = &pConfig->RegionConfigArr[region];
            Ret = Platform_Hw_Mpu_SetRegionConfig((pConfig->RegionConfigArr[region]).RegionNum, regionCfg);
        }

        /*Checking if cache is enable before*/
        if (((((uint32)1U << (uint32)17U) & TT_SCB->CCR) != (uint32)0) || ((((uint32)1U << (uint32)16U) & TT_SCB->CCR) != (uint32)0))
        {
        /*synchronize cache before update mpu */
        #if (defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)) || (defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON))
            (void)Platform_Hw_Cache_CleanDCache();
            (void)Platform_Hw_Cache_DisableDCache();
            (void)Platform_Hw_Cache_DisableICache();
        #endif
        }

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();

        TT_MPU->CTRL |= TT_MPU_CTRL_ENABLE(1U);

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();

    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck(((TT_MPU->CTRL & TT_MPU_CTRL_ENABLE_MASK) == 0), TT_RET_OPT_REG_ERR, &Ret);
    #endif
        
        /* ENABLE CACHE */
        #if (defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)) || (defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON))
            (void)Platform_Hw_Cache_InvalidateDCache();
            (void)Platform_Hw_Cache_InvalidateICache();
            (void)Platform_Hw_Cache_EnableICache();
            (void)Platform_Hw_Cache_EnableDCache();
        #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Disables the module and resets all region configurations.
 * @details     This function is Reentrant.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
TT_RetType Platform_Hw_Mpu_Deinit(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 region = 0;
    uint8 d_region = 0;

    Ret = Platform_Hw_Mpu_GetDRegion(&d_region);
    TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);

    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    TT_MPU->CTRL &= ~(TT_MPU_CTRL_PRIVDEFENA_MASK | TT_MPU_CTRL_HFNMIENA_MASK | TT_MPU_CTRL_ENABLE_MASK);

    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    /* region15 always use for uncacheable in systeminit */
    for (region = 0U; region < (d_region - 1); region++)
    {
        TT_MPU->RNR = (uint32)region;
        TT_MPU->RASR = 0UL;
        TT_MPU->RBAR = 0UL;
    }

    return Ret;
}

#define PLATFORM_STOP_SEC_CODE_SLOW
#include "Platform_MemMap.h"


#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/**
 * @brief       Initializes the Memory Protection Unit general parameters and
 *              region configurations.
 * @details     This function is non-reentrant.
 * @param[in]   pConfig  Pointer to configuration structure for MPU M7.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @api
 */
TT_RetType Platform_Hw_Mpu_GetDRegion(uint8 * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((RetVal == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *RetVal = (uint8)((TT_MPU->TYPE & TT_MPU_TYPE_DREGION_MASK)>>TT_MPU_TYPE_DREGION_SHIFT) & 0xFFU;
    }
    else
    {
        /* do nothing */
   }

    return Ret;
}

/**
 * @brief       Configures the region selected by u8RegionNum with the data from pUserConfigPtr.
 * @details     This function is Reentrant.
 * @param[in]   u8RegionNum  Region number.
 * @param[in]   pUserConfigPtr  Pointer to the region configuration structure for MPU M7.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
TT_RetType Platform_Hw_Mpu_SetRegionConfig(TT_CONST uint8 u8RegionNum,TT_CONST Platform_Hw_MpuRegionConfigType * TT_CONST pUserConfigPtr)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 d_region = 0;
    uint32 regionSize = 0;
    uint32 regionAttributes = 0;

    Ret = Platform_Hw_Mpu_GetDRegion(&d_region);
    TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
    TT_ParaCheck((u8RegionNum >= (d_region-1)), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((pUserConfigPtr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((pUserConfigPtr != NULL_PTR) && ((pUserConfigPtr->EndAddr - pUserConfigPtr->StartAddr) < MPU_M7_IP_MIN_REGION_SIZE), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck((pUserConfigPtr != NULL_PTR) && (pUserConfigPtr->MemType > TT_MPU_MEM_NORMAL_CACHEABLE), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck((pUserConfigPtr != NULL_PTR) && (!IS_MPU_REGION_ACCESS_RIGHTS(pUserConfigPtr->AccessRight)), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck((pUserConfigPtr != NULL_PTR) && (pUserConfigPtr->OuterCachePolicy > TT_MPU_CACHE_POLICY_W_BACK_NO_W_ALLOCATE), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck((pUserConfigPtr != NULL_PTR) && (pUserConfigPtr->InnerCachePolicy > TT_MPU_CACHE_POLICY_W_BACK_NO_W_ALLOCATE), TT_RET_PARAM_ENUM_ERR, &Ret);
    TT_ParaCheck((pUserConfigPtr != NULL_PTR) && (pUserConfigPtr->Shareable != TRUE)&&(pUserConfigPtr->Shareable != FALSE), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        /* Calculate log2(region) */
        regionSize = Platform_Hw_Mpu_PriCalculateRegionSize(pUserConfigPtr->StartAddr, pUserConfigPtr->EndAddr);

        if ((pUserConfigPtr->StartAddr & ((1UL << regionSize) - 1UL)) == 0UL)
        {
            /* Set the region number */
            TT_MPU->RNR = u8RegionNum;
            /* Set the region base address */
            TT_MPU->RBAR = pUserConfigPtr->StartAddr;

            /* Set the region size */
            regionAttributes |= TT_MPU_RASR_SIZE(regionSize - 1UL);

            /* Configure sub region disable mask */
            regionAttributes |= TT_MPU_RASR_SRD(pUserConfigPtr->SubRegMask);

            /* Configure shareability */
            if (pUserConfigPtr->Shareable == TRUE)
            {
                regionAttributes |= TT_MPU_RASR_S_MASK;
            }
            else
            {
                regionAttributes &= (~((uint32)TT_MPU_RASR_S_MASK));
            }

            /* Set memory attributes and cacheability options */
            if (pUserConfigPtr->MemType != TT_MPU_MEM_NORMAL_CACHEABLE)
            {
                Platform_Hw_Mpu_PriSetMemoryType(&regionAttributes, pUserConfigPtr->MemType);
            }
            else
            {
                Platform_Hw_Mpu_PriSetCachePolicies(&regionAttributes, pUserConfigPtr->InnerCachePolicy, pUserConfigPtr->OuterCachePolicy);
            }

            /* Compute access rights */
            Platform_Hw_Mpu_PriComputeAccessRights(&regionAttributes, pUserConfigPtr->AccessRight);

            /* Enable Region */
            regionAttributes |= TT_MPU_RASR_ENABLE(1UL);

            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();
            /* Write final values */
            TT_MPU->RASR = regionAttributes;
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();

        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck((TT_MPU->RNR != u8RegionNum), TT_RET_OPT_REG_ERR, &Ret);
            TT_ParaCheck((TT_MPU->RBAR != pUserConfigPtr->StartAddr), TT_RET_OPT_REG_ERR, &Ret);
            TT_ParaCheck((TT_MPU->RASR != regionAttributes), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }
        else
        {
            Ret = TT_RET_PARAM_ADDR_ERR;
        }
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Enables or disabled a specific region.
 * @details     This function is Reentrant.
 * @param[in]   u8RegionNum  Region to be modified.
 * @param[in]   bEnable  Specifies whether the region is enabled or disabled.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
TT_RetType Platform_Hw_Mpu_EnableRegion(TT_CONST uint8 u8RegionNum, TT_CONST boolean bEnable)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 d_region = 0;

    Ret = Platform_Hw_Mpu_GetDRegion(&d_region);
    TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);

    TT_ParaCheck((u8RegionNum >= (d_region-1)), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((bEnable != TRUE) && (bEnable != FALSE), TT_RET_PARAM_CHANNEL_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_00();
        #endif
        TT_MPU->RNR = (uint32)u8RegionNum;
    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((TT_MPU->RNR != u8RegionNum), TT_RET_OPT_REG_ERR, &Ret);
    #endif
        if (bEnable == TRUE)
        {
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();
            TT_MPU->RASR |= TT_MPU_RASR_ENABLE(1UL);
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();

        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(((TT_MPU->RASR & TT_MPU_RASR_ENABLE_MASK) == 0), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }
        else
        {
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();
            TT_MPU->RASR &= ~TT_MPU_RASR_ENABLE(1UL);
            MCAL_DATA_SYNC_BARRIER();
            MCAL_INSTRUCTION_SYNC_BARRIER();

        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck(((TT_MPU->RASR & TT_MPU_RASR_ENABLE_MASK) != 0), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }
        #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_00();
        #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Modify the access rights for a specific region.
 * @details     This function is Reentrant.
 * @param[in]   u8RegionNum  Region to be modified.
 * @param[in]   eRights  Specifies the new access rights.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
TT_RetType Platform_Hw_Mpu_SetAccessRight(TT_CONST uint8 u8RegionNum,TT_CONST Platform_Hw_MpuAccessRightsType eRights)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint8 d_region = 0;

    Ret = Platform_Hw_Mpu_GetDRegion(&d_region);
    TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);

    TT_ParaCheck((u8RegionNum >= (d_region-1)), TT_RET_PARAM_CHANNEL_ERR, &Ret);
    TT_ParaCheck((!IS_MPU_REGION_ACCESS_RIGHTS(eRights)), TT_RET_PARAM_ENUM_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        uint32 regionAttributes = 0;
        #ifdef USING_OS_AUTOSAROS
        SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_01();
        #endif
        TT_MPU->RNR = (uint32)u8RegionNum;

        regionAttributes = TT_MPU->RASR;
        Platform_Hw_Mpu_PriComputeAccessRights(&regionAttributes, eRights);

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();

        TT_MPU->RASR = regionAttributes;

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();

    #if (TT_SAFETY == STD_ON)
        TT_ParaCheck((TT_MPU->RNR != u8RegionNum), TT_RET_OPT_REG_ERR, &Ret);
        TT_ParaCheck((TT_MPU->RASR != regionAttributes), TT_RET_OPT_REG_ERR, &Ret);
    #endif

        #ifdef USING_OS_AUTOSAROS
        SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_01();
        #endif
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Retrieve error details
 * @details     This function is Reentrant
 * @param[out]  pErrorDetails  Storage where the data will be saved.
 * @param[out]  RetVal
 * - \b         TRUE  If an error was present.
 * - \b         FALSE  Otherwise.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
TT_RetType Platform_Hw_Mpu_GetErrorDetails(Platform_Hw_MpuErrorDetailsType * TT_CONST pErrorDetails, boolean * TT_CONST RetVal)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32  mmfsr = 0;
    uint32  mmfsrCopy = 0;
    uint32  errorAddress = 0;
    uint8   errorCount = 0U;
    
    TT_ParaCheck((RetVal == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((pErrorDetails == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        *RetVal = FALSE;
        Platform_Hw_Mpu_PriGetErrorRegisters(&mmfsr, &errorAddress);
        mmfsrCopy = mmfsr;
        while (mmfsr != 0U)
        {
            errorCount += (uint8)(mmfsr & 1UL);
            mmfsr >>= 1UL;
        }

        if (errorCount > 1U)
        {
            pErrorDetails->eType = TT_MPU_MEMMAN_ERROR_MULTIPLE;
        }
        else
        {
            mmfsr = mmfsrCopy;
            switch(mmfsr)
            {
                case (1U << TT_SCB_CFSR_IACCVIOL_Pos):
                    pErrorDetails->eType = TT_MPU_MEMMAN_ERROR_INSTRUCTION_ACCESS;
                    break;
                case (1U << TT_SCB_CFSR_DACCVIOL_Pos):
                    pErrorDetails->eType = TT_MPU_MEMMAN_ERROR_DATA_ACCESS;
                    break;
                case (1U << TT_SCB_CFSR_MUNSTKERR_Pos):
                    pErrorDetails->eType = TT_MPU_MEMMAN_ERROR_UNSTACK;
                    break;
                case (1U << TT_SCB_CFSR_MSTKERR_Pos):
                    pErrorDetails->eType = TT_MPU_MEMMAN_ERROR_STACK;
                    break;
                case (1U << TT_SCB_CFSR_MLSPERR_Pos):
                    pErrorDetails->eType = TT_MPU_MEMMAN_ERROR_FLOATING_POINT;
                    break;
                default:
                    pErrorDetails->eType = TT_MPU_MEMMAN_ERROR_NONE;
                    break;
            }
        }

        pErrorDetails->u32Address = errorAddress;

        if (errorCount > 0U)
        {
            *RetVal = TRUE;
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

/**
 * @brief       Enable the MPU.
 * @param       MPU_Control Default access permissions for unconfigured regions.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * MPU_PRIVILEGED_DEFAULT
 */
TT_RetType Platform_Hw_Mpu_Enable(TT_CONST uint32 MPU_Control)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    MCAL_MEM_SYNC_BARRIER();
    TT_MPU->CTRL = MPU_Control | TT_MPU_CTRL_ENABLE_MASK;
#ifdef SCB_SHCSR_MEMFAULTENA_Msk
    TT_SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
#endif
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

#if (TT_SAFETY == STD_ON)
    TT_ParaCheck((TT_MPU->CTRL != (MPU_Control | TT_MPU_CTRL_ENABLE_MASK)), TT_RET_OPT_REG_ERR, &Ret);
#endif
    return Ret;
}

/**
 * @brief       Disable the MPU, must disable MPU first before config MPU.
 * @return      TT_RetType
 * @param       void
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_Mpu_Disable(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    MCAL_MEM_SYNC_BARRIER();
#ifdef SCB_SHCSR_MEMFAULTENA_Msk
    TT_SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
#endif
    TT_MPU->CTRL  &= ~TT_MPU_CTRL_ENABLE_MASK;
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

#if (TT_SAFETY == STD_ON)
    TT_ParaCheck(((TT_MPU->CTRL & TT_MPU_CTRL_ENABLE_MASK) != 0), TT_RET_OPT_REG_ERR, &Ret);
#endif
    return Ret;
}

/**
 * @brief       Clear and disable the given MPU region.
 * @param[in]   rnr  Region number to be cleared.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_Mpu_ClrRegion(TT_CONST uint32 rnr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_MPU->RNR = rnr;
    TT_MPU->RASR = 0U;

#if (TT_SAFETY == STD_ON)
    TT_ParaCheck((TT_MPU->RNR != rnr), TT_RET_OPT_REG_ERR, &Ret);
    TT_ParaCheck((TT_MPU->RASR != 0), TT_RET_OPT_REG_ERR, &Ret);
#endif

    return Ret;
}

/**
 * @brief       Configure an MPU region.
 * @param[in]   rbar  Value for RBAR register.
 * @param[in]   rasr  Value for RASR register.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_Mpu_SetRegion(TT_CONST uint32 rbar, TT_CONST uint32 rasr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_MPU->RBAR = rbar;
    TT_MPU->RASR = rasr;

#if (TT_SAFETY == STD_ON)
    TT_ParaCheck((TT_MPU->RBAR != rbar), TT_RET_OPT_REG_ERR, &Ret);
    TT_ParaCheck((TT_MPU->RASR != rasr), TT_RET_OPT_REG_ERR, &Ret);
#endif

    return Ret;
}

/**
 * @brief       Configure the given MPU region.
 * @param[in]   rnr  Region number to be configured.
 * @param[in]   rbar  Value for RBAR register.
 * @param[in]   rasr  Value for RASR register.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_Mpu_SetRegionEx(TT_CONST uint32 rnr, TT_CONST uint32 rbar, TT_CONST uint32 rasr)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_MPU->RNR = rnr;
    TT_MPU->RBAR = rbar;
    TT_MPU->RASR = rasr;

#if (TT_SAFETY == STD_ON)
    TT_ParaCheck((TT_MPU->RNR != rnr), TT_RET_OPT_REG_ERR, &Ret);
    TT_ParaCheck((TT_MPU->RBAR != rbar), TT_RET_OPT_REG_ERR, &Ret);
    TT_ParaCheck((TT_MPU->RASR != rasr), TT_RET_OPT_REG_ERR, &Ret);
#endif

    return Ret;
}

/**
 * @brief       Memcpy with strictly ordered memory access, e.g. used by code in ARM_MPU_Load().
 * @param[in]   dst  Destination data is copied to.
 * @param[in]   src  Source data is copied from.
 * @param[in]   len  Amount of data words to be copied.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
static TT_RetType Platform_Hw_Mpu_OrderedMemcpy(volatile uint32 * TT_CONST dst, TT_CONST uint32 * TT_CONST src, TT_CONST uint32 len)
{
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
    uint32 i = 0;

    for (i = 0; i < len; ++i)
    {
        dst[i] = src[i];
    }

    return Ret;
}

/**
 * @brief       Load the given number of MPU regions from a table.
 * @param[in]   table  Pointer to the MPU configuration table.
 * @param[in]   cnt  Amount of regions to be configured.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_Mpu_Load(TT_CONST MPU_Region_t * TT_CONST table, TT_CONST uint32 cnt)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((table == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        TT_CONST uint32 rowWordSize = sizeof(MPU_Region_t) / 4U;
        uint32 count = cnt;
        TT_CONST MPU_Region_t * p_table = table;

        while (count > TT_MPU_TYPE_RALIASES)
        {
            Ret = Platform_Hw_Mpu_OrderedMemcpy((volatile uint32 *)&(TT_MPU->RBAR), (TT_CONST uint32 *)&(p_table->RBAR), TT_MPU_TYPE_RALIASES * rowWordSize);
            TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
            p_table += TT_MPU_TYPE_RALIASES;
            count -= TT_MPU_TYPE_RALIASES;
        }
        Ret = Platform_Hw_Mpu_OrderedMemcpy((volatile uint32 *)&(TT_MPU->RBAR), (TT_CONST uint32 *)&(p_table->RBAR), count * rowWordSize);
        TT_ParaCheck((Ret != TT_RET_SUCCESS), TT_RET_STATUS_ERR, &Ret);
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       Initializes and configures the Region and the memory to be protected.
 * @param[in]   MPU_Init  Pointer to a Platform_Hw_MpuRegionInitTypeDef structure that contains
 *                        the initialization and configuration information.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
TT_RetType Platform_Hw_Mpu_ConfigRegion(TT_CONST Platform_Hw_MpuRegionInitTypeDef * TT_CONST MPU_Init)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 rasr    = 0;

    TT_ParaCheck((MPU_Init == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((MPU_Init != NULL_PTR) && ((IS_NOT_MPU_REGION_NUMBER(MPU_Init->Number)) || \
                  (IS_NOT_MPU_REGION_ENABLE(MPU_Init->Enable))), TT_RET_PARAM_CONFIG_ERR, &Ret);
    TT_ParaCheck((MPU_Init != NULL_PTR) && (((boolean)(MPU_Init->Enable)) && \
                  ((IS_NOT_MPU_INSTRUCTION_ACCESS(MPU_Init->DisableExec)) || \
                   (IS_NOT_MPU_REGION_PERMISSION_ATTRIBUTE(MPU_Init->AccessPermission)) || \
                   (IS_NOT_MPU_TEX_LEVEL(MPU_Init->TypeExtField)) || \
                   (IS_NOT_MPU_ACCESS_SHAREABLE(MPU_Init->IsShareable)) || \
                   (IS_NOT_MPU_ACCESS_CACHEABLE(MPU_Init->IsCacheable)) || \
                   (IS_NOT_MPU_ACCESS_BUFFERABLE(MPU_Init->IsBufferable)) || \
                   (!IS_MPU_SUB_REGION_DISABLE(MPU_Init->SubRegionDisable)) || \
                   (IS_NOT_MPU_REGION_SIZE(MPU_Init->Size)))), TT_RET_PARAM_CONFIG_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        /* Set the Region number */
        TT_MPU->RNR = MPU_Init->Number;

        if (MPU_Init->Enable > 0)
        {
            TT_MPU->RBAR = MPU_Init->BaseAddress;
            rasr = ((uint32)MPU_Init->DisableExec << TT_MPU_RASR_XN_Pos) |
                           ((uint32)MPU_Init->AccessPermission << TT_MPU_RASR_AP_Pos) |
                           ((uint32)MPU_Init->TypeExtField << TT_MPU_RASR_TEX_Pos) |
                           ((uint32)MPU_Init->IsShareable << TT_MPU_RASR_S_Pos) |
                           ((uint32)MPU_Init->IsCacheable << TT_MPU_RASR_C_Pos) |
                           ((uint32)MPU_Init->IsBufferable << TT_MPU_RASR_B_Pos) |
                           ((uint32)MPU_Init->SubRegionDisable << TT_MPU_RASR_SRD_Pos) |
                           ((uint32)MPU_Init->Size << TT_MPU_RASR_SIZE_Pos) |
                           ((uint32)MPU_Init->Enable << TT_MPU_RASR_ENABLE_Pos);
            TT_MPU->RASR = rasr;
        #if (TT_SAFETY == STD_ON)
            TT_ParaCheck((TT_MPU->RNR != MPU_Init->Number), TT_RET_OPT_REG_ERR, &Ret);
            TT_ParaCheck((TT_MPU->RBAR != MPU_Init->BaseAddress), TT_RET_OPT_REG_ERR, &Ret);
            TT_ParaCheck((TT_MPU->RASR != rasr), TT_RET_OPT_REG_ERR, &Ret);
        #endif
        }
        else
        {
            TT_MPU->RBAR = 0x00;
            TT_MPU->RASR = 0x00;
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
/*!
 * @brief Calculate log2(n) size for a specific region
 *
 * @param[in] u32StartAddr Region Start address
 * @param[in] u32EndAddr   Region End address
 *
 * @return Region size as a power of 2
 */
static uint32 Platform_Hw_Mpu_PriCalculateRegionSize(TT_CONST uint32 u32StartAddr, TT_CONST uint32 u32EndAddr)
{
    uint32 finalSize = 0UL;
    uint32 u32Size = 0UL;

    u32Size = u32EndAddr - u32StartAddr;
    while (u32Size > 0U)
    {
        finalSize++;
        u32Size >>= 1U;
    }

    return finalSize;
}

/*!
 * @brief Configure memory type
 *
 * @param[out] pRegionAttr RASR register where to save the attributes
 * @param[in]  eType       Memory type
 *
 * @return void
 */
static void Platform_Hw_Mpu_PriSetMemoryType(uint32 * TT_CONST pRegionAttr, TT_CONST Platform_Hw_MpuMemoryType eType)
{
    *pRegionAttr |= ((uint32)Platform_PubMemoryTypeValues[eType] << TT_MPU_A_RASR_B_SHIFT);
}

/*!
 * @brief Set inner and outer cache policies
 *
 * @param[out] pRegionAttr   RASR register where to save the attributes
 * @param[in]  eInnerPolicy  Inner cache policy
 * @param[in]  eOuterPolicy  Outer cache policy
 *
 * @return void
 */
static void Platform_Hw_Mpu_PriSetCachePolicies(uint32 * TT_CONST pRegionAttr,
                                             TT_CONST Platform_Hw_MpuCachePolicyType eInnerPolicy,
                                             TT_CONST Platform_Hw_MpuCachePolicyType eOuterPolicy
                                      )
{
    *pRegionAttr |= TT_MPU_RASR_C((uint32)eInnerPolicy >> 1UL) | TT_MPU_RASR_B((uint32)eInnerPolicy);
    *pRegionAttr |= TT_MPU_RASR_TEX(0x4UL | (uint32)eOuterPolicy);
}

/*!
 * @brief Compute access rights
 *
 * @param[out] pRegionAttr   RASR register where to save the attributes
 * @param[in]  eAccessRights Region access rights
 *
 * @return void
 */
static void Platform_Hw_Mpu_PriComputeAccessRights(uint32 * TT_CONST pRegionAttr, TT_CONST Platform_Hw_MpuAccessRightsType eAccessRights)
{
    *pRegionAttr &= ~(TT_MPU_RASR_AP_MASK | TT_MPU_RASR_XN_MASK);
    *pRegionAttr |= TT_MPU_RASR_AP(eAccessRights);
    if (((uint8)eAccessRights & (uint8)MPU_M7_IP_EXECUTE_RIGHT_MASK) == (uint8)0U)
    {
        *pRegionAttr |= TT_MPU_RASR_XN(1UL);
    }
    else
    {
        *pRegionAttr &= ~TT_MPU_RASR_XN(1UL);
    }

}

/*!
 * @brief Retrieve fault information from SCB
 *
 * @param[out] pMmfsr   SCB->MMFSR register contents
 * @param[out] pAddress Address of the violation
 *
 * @return void
 */
static void Platform_Hw_Mpu_PriGetErrorRegisters(uint32 * TT_CONST pMmfsr, uint32 * TT_CONST pAddress)
{
    *pMmfsr = TT_SCB->CFSR & (uint32)MPU_SCB_CFSR_MMFSR_MASK_VALID;
    if (((TT_SCB->CFSR & (uint32)TT_SCB_CFSR_MMARVALID_Msk) >> (uint32)TT_SCB_CFSR_MMARVALID_Pos) == (uint32)1UL)
    {
        *pAddress = (uint32)TT_SCB->MMFAR;
    }
    else
    {
        *pAddress = 0xFFFFFFFFUL;
    }
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
