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
**  FILENAME     : Platform_Hw_Cache.h                                        **
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
#ifndef PLATFORM_HW_CACHE_H
#define PLATFORM_HW_CACHE_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Hw_IntCtrl_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_CACHE_VENDOR_ID_H                     1541
#define PLATFORM_HW_CACHE_MODULE_ID_H                     219
#define PLATFORM_HW_CACHE_AR_RELEASE_MAJOR_VERSION_H      4
#define PLATFORM_HW_CACHE_AR_RELEASE_MINOR_VERSION_H      4
#define PLATFORM_HW_CACHE_AR_RELEASE_PATCH_VERSION_H      0
#define PLATFORM_HW_CACHE_SW_MAJOR_VERSION_H              1
#define PLATFORM_HW_CACHE_SW_MINOR_VERSION_H              1
#define PLATFORM_HW_CACHE_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_Cache.h and Platform_Hw_IntCtrl_Types.h file version check */
#if (PLATFORM_HW_CACHE_VENDOR_ID_H != PLATFORM_HW_INTCTRL_TYPES_VENDOR_ID_H)
    #error "Platform_Hw_Cache.h and Platform_Hw_IntCtrl_Types.h have different vendor id"
#endif
#if (PLATFORM_HW_CACHE_MODULE_ID_H != PLATFORM_HW_INTCTRL_TYPES_MODULE_ID_H)
    #error "Platform_Hw_Cache.h and Platform_Hw_IntCtrl_Types.h have different module id"
#endif
#if ((PLATFORM_HW_CACHE_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_CACHE_AR_RELEASE_MINOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_CACHE_AR_RELEASE_PATCH_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_Cache.h and Platform_Hw_IntCtrl_Types.h are different"
#endif
#if ((PLATFORM_HW_CACHE_SW_MAJOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_CACHE_SW_MINOR_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_CACHE_SW_PATCH_VERSION_H != PLATFORM_HW_INTCTRL_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_Cache.h and Platform_Hw_IntCtrl_Types.h are different"
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
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief       Enable I-Cache.
 * @details     Turns on I-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Cache_EnableICache (void);


/**
 * @brief       Disable I-Cache.
 * @details     Turns off I-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Cache_DisableICache (void);


/**
 * @brief       Invalidate I-Cache.
 * @details     Invalidates I-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Cache_InvalidateICache (void);

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
extern TT_RetType Platform_Hw_Cache_AddrInvalidICache(void * TT_CONST addr, TT_CONST uint32 isize);

/**
 * @brief       Enable D-Cache.
 * @details     Turns on D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Cache_EnableDCache (void);


/**
 * @brief       Disable D-Cache.
 * @details     Turns off D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Cache_DisableDCache (void);


/**
 * @brief       Invalidate D-Cache.
 * @details     Invalidates D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Cache_InvalidateDCache (void);


/**
 * @brief       Clean D-Cache.
 * @details     Cleans D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Cache_CleanDCache (void);


/**
 * @brief       Clean & Invalidate D-Cache.
 * @details     Cleans and Invalidates D-Cache.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 */
extern TT_RetType Platform_Hw_Cache_CleanInvalidateDCache (void);


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
extern TT_RetType Platform_Hw_Cache_AddrInvalidateDCache(void * TT_CONST addr, TT_CONST uint32 dsize);


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
extern TT_RetType Platform_Hw_Cache_AddrCleanDCache(uint32 * TT_CONST addr, TT_CONST uint32 dsize);


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
extern TT_RetType Platform_Hw_Cache_AddrCleanInvalidateDCache (uint32 * TT_CONST addr, TT_CONST uint32 dsize);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* PLATFORM_HW_CACHE_H */
