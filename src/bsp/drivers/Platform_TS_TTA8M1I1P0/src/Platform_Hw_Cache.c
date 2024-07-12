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
**  FILENAME     : Platform_Hw_Cache.c                                        **
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
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Hw_Cache.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_CACHE_VENDOR_ID_C                     1541
#define PLATFORM_HW_CACHE_MODULE_ID_C                     219
#define PLATFORM_HW_CACHE_AR_RELEASE_MAJOR_VERSION_C      4
#define PLATFORM_HW_CACHE_AR_RELEASE_MINOR_VERSION_C      4
#define PLATFORM_HW_CACHE_AR_RELEASE_PATCH_VERSION_C      0
#define PLATFORM_HW_CACHE_SW_MAJOR_VERSION_C              1
#define PLATFORM_HW_CACHE_SW_MINOR_VERSION_C              1
#define PLATFORM_HW_CACHE_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_Cache.c and Platform_Hw_Cache.h file version check */
#if (PLATFORM_HW_CACHE_VENDOR_ID_C != PLATFORM_HW_CACHE_VENDOR_ID_H)
    #error "Platform_Hw_Cache.c and Platform_Hw_Cache.h have different vendor id"
#endif
#if (PLATFORM_HW_CACHE_MODULE_ID_C != PLATFORM_HW_CACHE_MODULE_ID_H)
    #error "Platform_Hw_Cache.c and Platform_Hw_Cache.h have different module id"
#endif
#if ((PLATFORM_HW_CACHE_AR_RELEASE_MAJOR_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_CACHE_AR_RELEASE_MINOR_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_CACHE_AR_RELEASE_PATCH_VERSION_C != PLATFORM_HW_CACHE_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_Cache.c and Platform_Hw_Cache.h are different"
#endif
#if ((PLATFORM_HW_CACHE_SW_MAJOR_VERSION_C != PLATFORM_HW_CACHE_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_CACHE_SW_MINOR_VERSION_C != PLATFORM_HW_CACHE_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_CACHE_SW_PATCH_VERSION_C != PLATFORM_HW_CACHE_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_Cache.c and Platform_Hw_Cache.h are different"
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

/* Cache Size ID Register Macros */
#define CCSIDR_WAYS(x)         (((x) & TT_SCB_CCSIDR_ASSOCIATIVITY_Msk) >> TT_SCB_CCSIDR_ASSOCIATIVITY_Pos)
#define CCSIDR_SETS(x)         (((x) & TT_SCB_CCSIDR_NUMSETS_Msk      ) >> TT_SCB_CCSIDR_NUMSETS_Pos      )

/* Cortex-M7 cache line size is fixed to 32 bytes (8 words). See also register SCB_CCSIDR */
#define SCB_DCACHE_LINE_SIZE   (32U)

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

/******************************************************************************
*                            Public Functions
*******************************************************************************/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief       Enable I-Cache.
 * @details     Turns on I-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_EnableICache (void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    if ((TT_SCB->CCR & TT_SCB_CCR_IC_Msk) > 0U)
    {
        /* ICache is already enabled */
    }
    else
    {
        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
        TT_SCB->ICIALLU = 0UL;                     /* invalidate I-Cache */
        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
        TT_SCB->CCR |=  (uint32)TT_SCB_CCR_IC_Msk;  /* enable I-Cache */
        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();

        if ((TT_SCB->CCR & TT_SCB_CCR_IC_Msk) == 0U)
        {
            Ret = TT_RET_STATUS_ERR;
        }
        else
        {

        }

    }

    return Ret;
}

/**
 * @brief       Disable I-Cache.
 * @details     Turns off I-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_DisableICache (void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    TT_SCB->CCR &= ~(uint32)TT_SCB_CCR_IC_Msk;  /* disable I-Cache */
    TT_SCB->ICIALLU = 0UL;                     /* invalidate I-Cache */
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    if ((TT_SCB->CCR & TT_SCB_CCR_IC_Msk) > 0U)
    {
        Ret = TT_RET_STATUS_ERR;
    }
    else
    {

    }

    return Ret;
}

/**
 * @brief       Invalidate I-Cache.
 * @details     Invalidates I-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_InvalidateICache (void)
{
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;

    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    TT_SCB->ICIALLU = 0UL;   /* write only */
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    return Ret;
}

/**
 * @brief       I-Cache Invalidate by address
 * @details     Invalidates I-Cache for the given address.
                I-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
                I-Cache memory blocks which are part of given address + given size are invalidated.
 * @param[in]   addr    address
 * @param[in]   isize   size of memory block (in number of bytes)
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_AddrInvalidICache(void * TT_CONST addr, TT_CONST uint32 isize)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    TT_ParaCheck((addr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((isize == 0), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck(((0xFFFFFFFFU - (uint32)(uint32 *)addr) < (isize - 1U)), TT_RET_PARAM_ADDR_ERR, &Ret);

    if ( Ret == TT_RET_SUCCESS )
    {
    	uint32 op_size = isize + (((uint32)(uint32 *)addr) & (SCB_DCACHE_LINE_SIZE - 1U));
    	uint32 op_addr = (uint32)(uint32 *)addr /* & ~(__SCB_ICACHE_LINE_SIZE - 1U) */;

        MCAL_DATA_SYNC_BARRIER();

        do
        {
            TT_SCB->ICIMVAU = op_addr;             /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            op_addr += SCB_DCACHE_LINE_SIZE;
            op_size -= SCB_DCACHE_LINE_SIZE;
        } while ( op_size > 0 );

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
    }

    return Ret;
}

/**
 * @brief       Enable D-Cache.
 * @details     Turns on D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_EnableDCache (void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    if ((TT_SCB->CCR & TT_SCB_CCR_DC_Msk) > 0U)
    {
        /* DCache is already enabled */
    }
    else
    {
        TT_SCB->CSSELR = 0U;                       /* select Level 1 data cache */
        MCAL_DATA_SYNC_BARRIER();

        ccsidr = TT_SCB->CCSIDR;

        /* invalidate D-Cache */
        sets = (uint32)(CCSIDR_SETS(ccsidr));
        while (TRUE)
        {
            ways = (uint32)(CCSIDR_WAYS(ccsidr));
            while (TRUE)
            {
                TT_SCB->DCISW = (((sets << TT_SCB_DCISW_SET_Pos) & TT_SCB_DCISW_SET_Msk) |
                                 ((ways << TT_SCB_DCISW_WAY_Pos) & TT_SCB_DCISW_WAY_Msk)  );
                if (ways == 0U)
                {
                    break;
                }
                ways--;
            }
            if (sets == 0U)
            {
                break;
            }
            sets--;
        }
        MCAL_DATA_SYNC_BARRIER();

        TT_SCB->CCR |=  (uint32)TT_SCB_CCR_DC_Msk;  /* enable D-Cache */

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
        
        if ((TT_SCB->CCR & TT_SCB_CCR_DC_Msk) == 0U)
        {
            Ret = TT_RET_STATUS_ERR;
        }
        else
        {
    
        }
    }

    return Ret;
}

/**
 * @brief       Disable D-Cache.
 * @details     Turns off D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_DisableDCache (void)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    TT_SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    MCAL_DATA_SYNC_BARRIER();

    TT_SCB->CCR &= ~(uint32)TT_SCB_CCR_DC_Msk;  /* disable D-Cache */
    MCAL_DATA_SYNC_BARRIER();

    ccsidr = TT_SCB->CCSIDR;

    /* clean & invalidate D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    while (TRUE)
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        while (TRUE)
        {
            TT_SCB->DCCISW = (((sets << TT_SCB_DCCISW_SET_Pos) & TT_SCB_DCCISW_SET_Msk) |
                              ((ways << TT_SCB_DCCISW_WAY_Pos) & TT_SCB_DCCISW_WAY_Msk)  );
            if (ways == 0U)
            {
                break;
            }
            ways--;
        }
        if (sets == 0U)
        {
            break;
        }
        sets--;
    }

    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    if ((TT_SCB->CCR & TT_SCB_CCR_DC_Msk) > 0U)
    {
        Ret = TT_RET_STATUS_ERR;
    }
    else
    {

    }

    return Ret;
}

/**
 * @brief       Invalidate D-Cache.
 * @details     Invalidates D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_InvalidateDCache (void)
{
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    TT_SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    MCAL_DATA_SYNC_BARRIER();

    ccsidr = TT_SCB->CCSIDR;

    /* invalidate D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    while (TRUE)
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        while (TRUE)
        {
            TT_SCB->DCISW = (((sets << TT_SCB_DCISW_SET_Pos) & TT_SCB_DCISW_SET_Msk) |
                             ((ways << TT_SCB_DCISW_WAY_Pos) & TT_SCB_DCISW_WAY_Msk)  );
            if (ways == 0U)
            {
                break;
            }
            ways--;
        }
        if (sets == 0U)
        {
            break;
        }
        sets--;
    }
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    return Ret;
}

/**
 * @brief       Clean D-Cache.
 * @details     Cleans D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_CleanDCache (void)
{
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    TT_SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    MCAL_DATA_SYNC_BARRIER();

    ccsidr = TT_SCB->CCSIDR;

    /* clean D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    while (TRUE)
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        while (TRUE)
        {
            TT_SCB->DCCSW = (((sets << TT_SCB_DCCSW_SET_Pos) & TT_SCB_DCCSW_SET_Msk) |
                             ((ways << TT_SCB_DCCSW_WAY_Pos) & TT_SCB_DCCSW_WAY_Msk)  );
            if (ways == 0U)
            {
                break;
            }
            ways--;
        }
        if (sets == 0U)
        {
            break;
        }
        sets--;
    }
    
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    return Ret;
}

/**
 * @brief       Clean & Invalidate D-Cache.
 * @details     Cleans and Invalidates D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_CleanInvalidateDCache (void)
{
    TT_CONST TT_RetType Ret = TT_RET_SUCCESS;
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    TT_SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    MCAL_DATA_SYNC_BARRIER();

    ccsidr = TT_SCB->CCSIDR;

    /* clean & invalidate D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    while (TRUE)
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        while (TRUE)
        {
            TT_SCB->DCCISW = (((sets << TT_SCB_DCCISW_SET_Pos) & TT_SCB_DCCISW_SET_Msk) |
                              ((ways << TT_SCB_DCCISW_WAY_Pos) & TT_SCB_DCCISW_WAY_Msk));
            if (ways == 0U)
            {
                break;
            }
            ways--;
        }
        if (sets == 0U)
        {
            break;
        }
        sets--;
    }

    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    return Ret;
}

/**
 * @brief       D-Cache Invalidate by address
 * @details     Invalidates D-Cache for the given address.
 *              D-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
 *              D-Cache memory blocks which are part of given address + given size are invalidated.
 * @param[in]   addr  Address
 * @param[in]   dsize  Size of memory block (in number of bytes)
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_AddrInvalidateDCache (void * TT_CONST addr, TT_CONST uint32 dsize)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 n_loops = 0;
    uint32 start = (uint32)(uint32 *)addr;
    uint32 end = (uint32)(uint32 *)addr + dsize;

    TT_ParaCheck((addr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((dsize == 0), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck(((0xFFFFFFFFU - (uint32)(uint32 *)addr) < (dsize - 1U)), TT_RET_PARAM_ADDR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        start = start & ~(SCB_DCACHE_LINE_SIZE-1);
        end = (end & ~(SCB_DCACHE_LINE_SIZE-1)) + (((end & (SCB_DCACHE_LINE_SIZE-1)) > 0) ? SCB_DCACHE_LINE_SIZE : 0);
        n_loops = ((end-start) / SCB_DCACHE_LINE_SIZE);
        MCAL_DATA_SYNC_BARRIER();

        do {
            TT_SCB->DCIMVAC = start;             /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            start += SCB_DCACHE_LINE_SIZE;
            n_loops--;
        } while ( n_loops > 0 );

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       D-Cache Clean by address
 * @details     Cleans D-Cache for the given address
 *              D-Cache is cleaned starting from a 32 byte aligned address in 32 byte granularity.
 *              D-Cache memory blocks which are part of given address + given size are cleaned.
 * @param[in]   addr  Address
 * @param[in]   dsize  Size of memory block (in number of bytes)
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_AddrCleanDCache (uint32 * TT_CONST addr, TT_CONST uint32 dsize)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 n_loops = 0;
    uint32 start = (uint32)(uint32 *)addr;
    uint32 end = (uint32)(uint32 *)addr + dsize;

    TT_ParaCheck((addr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((dsize == 0), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck(((0xFFFFFFFFU - (uint32)addr) < (dsize - 1)), TT_RET_PARAM_ADDR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        start = start & ~(SCB_DCACHE_LINE_SIZE-1);
        end = (end & ~(SCB_DCACHE_LINE_SIZE-1)) + (((end & (SCB_DCACHE_LINE_SIZE-1)) > 0)? SCB_DCACHE_LINE_SIZE : 0);
        n_loops = ((end-start) / SCB_DCACHE_LINE_SIZE);
        MCAL_DATA_SYNC_BARRIER();

        do
        {
            TT_SCB->DCCMVAC = start;             /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            start += SCB_DCACHE_LINE_SIZE;
            n_loops--;
        } while ( n_loops > 0 );

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief       D-Cache Clean and Invalidate by address.
 * @details     Cleans and invalidates D_Cache for the given address.
                D-Cache is cleaned and invalidated starting from a 32 byte aligned address in 32 byte granularity.
                D-Cache memory blocks which are part of given address + given size are cleaned and invalidated.
 * @param[in]   addr  Address (aligned to 32-byte boundary)
 * @param[in]   dsize  Size of memory block (in number of bytes)
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
TT_RetType Platform_Hw_Cache_AddrCleanInvalidateDCache (uint32 * TT_CONST addr, TT_CONST uint32 dsize)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 n_loops = 0;
    uint32 start = (uint32)(uint32 *)addr;
    uint32 end = (uint32)(uint32 *)addr + dsize;

    TT_ParaCheck((addr == NULL_PTR), TT_RET_PARAM_NULL_PTR_ERR, &Ret);
    TT_ParaCheck((dsize == 0), TT_RET_PARAM_LEN_ERR, &Ret);
    TT_ParaCheck(((0xFFFFFFFFU - (uint32)addr) < (dsize - 1)), TT_RET_PARAM_ADDR_ERR, &Ret);

    if (Ret == TT_RET_SUCCESS)
    {
        start = start & ~(SCB_DCACHE_LINE_SIZE-1);
        end = (end & ~(SCB_DCACHE_LINE_SIZE-1)) + (((end & (SCB_DCACHE_LINE_SIZE-1)) > 0) ? SCB_DCACHE_LINE_SIZE : 0);
        n_loops = ((end-start) / SCB_DCACHE_LINE_SIZE);
        MCAL_DATA_SYNC_BARRIER();

        do {
            TT_SCB->DCCIMVAC = start;            /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            start += SCB_DCACHE_LINE_SIZE;
            n_loops--;
        } while ( n_loops > 0 );

        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
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
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
