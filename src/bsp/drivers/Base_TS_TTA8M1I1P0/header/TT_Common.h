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
**  FILENAME     : TT_Common.h                                                **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Base Driver Source File                                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/****************************************************************************** 
*                            History                                          ** 
*[V1.1.0]:                                                                    ** 
*******************************************************************************/

#ifndef TT_COMMON_H
#define TT_COMMON_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#include "TT_BaseInterface.h"
#include "TT_Compiler.h"
#include "TT_BasicTypes.h"
#include "TT_MemIf.h"
#include "Base_Internal.h"
#include "Base_Modules_Cfg.h"
#include "TT_Devassert.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_COMMON_VENDOR_ID_H                     1541
#define TT_COMMON_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_COMMON_AR_RELEASE_MINOR_VERSION_H      4
#define TT_COMMON_AR_RELEASE_PATCH_VERSION_H      0
#define TT_COMMON_SW_MAJOR_VERSION_H              1
#define TT_COMMON_SW_MINOR_VERSION_H              1
#define TT_COMMON_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* TT_Common.h and TT_BaseInterface.h file version check */
#if (TT_COMMON_VENDOR_ID_H != TT_BASE_INTERFACE_VENDOR_ID_H)
    #error "TT_Common.h and TT_BaseInterface.h have different vendor id"
#endif
#if ((TT_COMMON_AR_RELEASE_MAJOR_VERSION_H != TT_BASE_INTERFACE_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_MINOR_VERSION_H != TT_BASE_INTERFACE_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_PATCH_VERSION_H != TT_BASE_INTERFACE_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Common.h and TT_BaseInterface.h are different"
#endif
#if ((TT_COMMON_SW_MAJOR_VERSION_H != TT_BASE_INTERFACE_SW_MAJOR_VERSION_H) || \
     (TT_COMMON_SW_MINOR_VERSION_H != TT_BASE_INTERFACE_SW_MINOR_VERSION_H) || \
     (TT_COMMON_SW_PATCH_VERSION_H != TT_BASE_INTERFACE_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Common.h and TT_BaseInterface.h are different"
#endif

/* TT_Common.h and TT_Compiler.h file version check */
#if (TT_COMMON_VENDOR_ID_H != TT_COMPILER_VENDOR_ID_H)
    #error "TT_Common.h and TT_Compiler.h have different vendor id"
#endif
#if ((TT_COMMON_AR_RELEASE_MAJOR_VERSION_H != TT_COMPILER_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_MINOR_VERSION_H != TT_COMPILER_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_PATCH_VERSION_H != TT_COMPILER_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Common.h and TT_Compiler.h are different"
#endif
#if ((TT_COMMON_SW_MAJOR_VERSION_H != TT_COMPILER_SW_MAJOR_VERSION_H) || \
     (TT_COMMON_SW_MINOR_VERSION_H != TT_COMPILER_SW_MINOR_VERSION_H) || \
     (TT_COMMON_SW_PATCH_VERSION_H != TT_COMPILER_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Common.h and TT_Compiler.h are different"
#endif

/* TT_Common.h and TT_BasicTypes.h file version check */
#if (TT_COMMON_VENDOR_ID_H != TT_BASIC_TYPES_VENDOR_ID_H)
    #error "TT_Common.h and TT_BasicTypes.h have different vendor id"
#endif
#if ((TT_COMMON_AR_RELEASE_MAJOR_VERSION_H != TT_BASIC_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_MINOR_VERSION_H != TT_BASIC_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_PATCH_VERSION_H != TT_BASIC_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Common.h and TT_BasicTypes.h are different"
#endif
#if ((TT_COMMON_SW_MAJOR_VERSION_H != TT_BASIC_TYPES_SW_MAJOR_VERSION_H) || \
     (TT_COMMON_SW_MINOR_VERSION_H != TT_BASIC_TYPES_SW_MINOR_VERSION_H) || \
     (TT_COMMON_SW_PATCH_VERSION_H != TT_BASIC_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Common.h and TT_BasicTypes.h are different"
#endif

/* TT_Common.h and Base_Internal.h file version check */
#if (TT_COMMON_VENDOR_ID_H != BASE_INTERNAL_VENDOR_ID_H)
    #error "TT_Common.h and Base_Internal.h have different vendor id"
#endif
#if ((TT_COMMON_AR_RELEASE_MAJOR_VERSION_H != BASE_INTERNAL_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_MINOR_VERSION_H != BASE_INTERNAL_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_PATCH_VERSION_H != BASE_INTERNAL_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Common.h and Base_Internal.h are different"
#endif
#if ((TT_COMMON_SW_MAJOR_VERSION_H != BASE_INTERNAL_SW_MAJOR_VERSION_H) || \
     (TT_COMMON_SW_MINOR_VERSION_H != BASE_INTERNAL_SW_MINOR_VERSION_H) || \
     (TT_COMMON_SW_PATCH_VERSION_H != BASE_INTERNAL_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Common.h and Base_Internal.h are different"
#endif

/* TT_Common.h and Base_Chips_Cfg.h file version check */
#if (TT_COMMON_VENDOR_ID_H != BASE_CHIPS_CFG_VENDOR_ID_H)
    #error "TT_Common.h and Base_Chips_Cfg.h have different vendor id"
#endif
#if ((TT_COMMON_AR_RELEASE_MAJOR_VERSION_H != BASE_CHIPS_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_MINOR_VERSION_H != BASE_CHIPS_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_PATCH_VERSION_H != BASE_CHIPS_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Common.h and Base_Chips_Cfg.h are different"
#endif
#if ((TT_COMMON_SW_MAJOR_VERSION_H != BASE_CHIPS_CFG_SW_MAJOR_VERSION_H) || \
     (TT_COMMON_SW_MINOR_VERSION_H != BASE_CHIPS_CFG_SW_MINOR_VERSION_H) || \
     (TT_COMMON_SW_PATCH_VERSION_H != BASE_CHIPS_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Common.h and Base_Chips_Cfg.h are different"
#endif

/* TT_Common.h and TT_DrvError.h file version check */
#if (TT_COMMON_VENDOR_ID_H != TT_DEVASSERT_VENDOR_ID_H)
    #error "TT_Common.h and TT_DrvError.h have different vendor id"
#endif
#if ((TT_COMMON_AR_RELEASE_MAJOR_VERSION_H != TT_DEVASSERT_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_MINOR_VERSION_H != TT_DEVASSERT_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_COMMON_AR_RELEASE_PATCH_VERSION_H != TT_DEVASSERT_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Common.h and TT_DrvError.h are different"
#endif
#if ((TT_COMMON_SW_MAJOR_VERSION_H != TT_DEVASSERT_SW_MAJOR_VERSION_H) || \
     (TT_COMMON_SW_MINOR_VERSION_H != TT_DEVASSERT_SW_MINOR_VERSION_H) || \
     (TT_COMMON_SW_PATCH_VERSION_H != TT_DEVASSERT_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Common.h and TT_DrvError.h are different"
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/
/**
* @brief Typedef for DEM error management implemented by MCAL drivers
*/
typedef struct
{
    uint32 state;   /**< enabling/disabling the DEM error: Active=STD_ON/ Inactive=STD_OFF */
    uint32 id;     /**< ID of DEM error (0 if STD_OFF)*/
}Mcal_DemErrorType; 


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

/******************************************************************************
*                            Public Functions
*******************************************************************************/
/**
 *@brief          LDREX-Exclusive read word
 *
 *@param[in]      addr - Get the address of the data
 *@return         data
 */
LOCAL_INLINE uint32 TT_LDREX(volatile uint32* addr)
{
    uint32 ldrData = 0;
#ifndef _VCAST_MINGW_C
    ASM_KEYWORD("LDREX %0,[%1]":"=r"(ldrData):"r"(addr):);
    MCAL_DATA_SYNC_BARRIER();
#endif
    return ldrData;
}

/**
 *@brief          LDREXH-Exclusive read half word
 *
 *@param[in]      addr - Get the address of the data
 *@return         data
 */
LOCAL_INLINE uint16 TT_LDREXH(volatile uint16* addr)
{
    uint16 ldrData = 0;
#ifndef _VCAST_MINGW_C
    ASM_KEYWORD("LDREXH %0,[%1]":"=r"(ldrData):"r"(addr):);
    MCAL_DATA_SYNC_BARRIER();
#endif
    return ldrData;
}

/**
 *@brief          LDREXB-Exclusive read half Byte
 *
 *@param[in]      addr - Get the address of the data
 *@return         data
 */
LOCAL_INLINE uint8 TT_LDREXB(volatile uint8* addr)
{
    uint8 ldrData = 0;
#ifndef _VCAST_MINGW_C
    ASM_KEYWORD("LDREXB %0,[%1]":"=r"(ldrData):"r"(addr):);
    MCAL_DATA_SYNC_BARRIER();
#endif
    return ldrData;
}

/**
 *@brief          STREX-Exclusive storage word
 *
 *@param[in]      data - Data that needs to be stored
 *@param[out]     addr - The address where the data needs to be stored
 *@return         0    : succeed
 *@return         other: failed
 */
LOCAL_INLINE uint32 TT_STREX(uint32 data, volatile uint32* addr)
{
    uint32 ret = 0;
#ifndef _VCAST_MINGW_C
    ASM_KEYWORD("STREX %0,%1,[%2]":"=&r"(ret):"r"(data),"r"(addr):);
    MCAL_DATA_SYNC_BARRIER();
#endif
    return ret;
}

/**
 *@brief          STREXH-Exclusive storage half word
 *
 *@param[in]      data - Data that needs to be stored
 *@param[out]     addr - The address where the data needs to be stored
 *@return         0    : succeed
 *@return         other: failed
 */
LOCAL_INLINE uint32 TT_STREXH(uint16 data, volatile uint16* addr)
{
    uint32 ret = 0;
#ifndef _VCAST_MINGW_C
    ASM_KEYWORD("STREXH %0,%1,[%2]":"=&r"(ret):"r"(data),"r"(addr):);
    MCAL_DATA_SYNC_BARRIER();
#endif
    return ret;
}

/**
 *@brief          STREXB-Exclusive storage Byte
 *
 *@param[in]      data - Data that needs to be stored
 *@param[out]     addr - The address where the data needs to be stored
 *@return         0    : succeed
 *@return         other: failed
 */
LOCAL_INLINE uint32 TT_STREXB(uint8 data, volatile uint8* addr)
{
    uint32 ret = 0;
#ifndef _VCAST_MINGW_C
    ASM_KEYWORD("STREXB %0,%1,[%2]":"=&r"(ret):"r"(data),"r"(addr):);
    MCAL_DATA_SYNC_BARRIER();
#endif
    return ret;
}

/**
 *@brief          CLREX-Force local exclusive access monitoring clear
 *
 *@param[in]      void
 *@param[out]     non
 *@return         non
 */
LOCAL_INLINE void TT_CLREX(void)
{
#ifndef _VCAST_MINGW_C
    ASM_KEYWORD("CLREX":::);
#endif
    MCAL_DATA_SYNC_BARRIER();
}

/**
 *@brief          Addition operation of word size data
 *                *original_val += target_val;
 *
 *@param[in]      target_val   - An addition in an addition operation
 *@param[out]     original_val - The value of the addition operation and
 *                               the address where the result is stored
 *@return         void
 */
LOCAL_INLINE void TT_ADD_ATOMIC_OPT(volatile uint32 *original_val, uint32 target_val)
{
    uint32 local_temp = 0;

    do {
        local_temp = TT_LDREX(original_val);
        local_temp = local_temp + target_val;
    } while(TT_STREX(local_temp,original_val) != 0);
}

/**
 *@brief          Subtraction operation of word size data
 *                *original_val -= target_val;
 *
 *@param[in]      target_val   - A reduction in a subtraction operation
 *@param[out]     original_val - The address where the result data is stored
 *@return         void
 */
LOCAL_INLINE void TT_MINUS_ATOMIC_OPT(volatile uint32 *original_val, uint32 target_val)
{
    uint32 local_temp = 0;

    do {
        local_temp = TT_LDREX(original_val);
        local_temp = local_temp - target_val;
    } while(TT_STREX(local_temp,original_val) != 0);
}

/**
 *@brief          Or-equal operation(Word)
 *                *original_val |= target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_OR_EQUAL_ATOMIC_OPT(volatile uint32 *original_val, uint32 target_val)
{
    uint32 local_temp = 0;

    do {
        local_temp = TT_LDREX(original_val);
        local_temp = local_temp | target_val;
    } while(TT_STREX(local_temp,original_val) != 0);
}

/**
 *@brief          And-equal operation(Word)
 *                *original_val &= target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_AND_EQUAL_ATOMIC_OPT(volatile uint32 *original_val, uint32 target_val)
{
    uint32 local_temp = 0;

    do {
        local_temp = TT_LDREX(original_val);
        local_temp = local_temp & target_val;
    } while(TT_STREX(local_temp,original_val) != 0);
}

/**
 *@brief          Assignment operation(Word)
 *                *original_val = target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_ASSIGN_ATOMIC_OPT(volatile uint32 *original_val, uint32 target_val)
{
    do {
        if(target_val == TT_LDREX(original_val))
        {
            TT_CLREX();
            break;
        }
    } while (TT_STREX(target_val,original_val) != 0);
}

/**
 *@brief          Addition operation of Half-word size data
 *                *original_val += target_val;
 *
 *@param[in]      target_val   - An addition in an addition operation
 *@param[out]     original_val - The value of the addition operation and
 *                               the address where the result is stored
 *@return         void
 */
LOCAL_INLINE void TT_ADD_ATOMIC_OPTH(volatile uint16 *original_val, uint16 target_val)
{
    uint16 local_temp = 0;

    do {
        local_temp = TT_LDREXH(original_val);
        local_temp = local_temp + target_val;
    } while(TT_STREXH(local_temp,original_val) != 0);
}

/**
 *@brief          Subtraction operation of Half-word size data
 *                *original_val -= target_val;
 *
 *@param[in]      target_val   - A reduction in a subtraction operation
 *@param[out]     original_val - The address where the result data is stored
 *@return         void
 */
LOCAL_INLINE void TT_MINUS_ATOMIC_OPTH(volatile uint16 *original_val, uint16 target_val)
{
    uint16 local_temp = 0;

    do {
        local_temp = TT_LDREXH(original_val);
        local_temp = local_temp - target_val;
    } while(TT_STREXH(local_temp,original_val) != 0);
}

/**
 *@brief          Or-equal operation(Half-Word)
 *                *original_val |= target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_OR_EQUAL_ATOMIC_OPTH(volatile uint16 *original_val, uint16 target_val)
{
    uint16 local_temp = 0;

    do {
        local_temp = TT_LDREXH(original_val);
        local_temp = local_temp | target_val;
    } while(TT_STREXH(local_temp,original_val) != 0);
}

/**
 *@brief          And-equal operation(Half-Word)
 *                *original_val &= target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_AND_EQUAL_ATOMIC_OPTH(volatile uint16 *original_val, uint16 target_val)
{
    uint16 local_temp = 0;

    do {
        local_temp = TT_LDREXH(original_val);
        local_temp = local_temp & target_val;
    } while(TT_STREXH(local_temp,original_val) != 0);
}

/**
 *@brief          Assignment operation(Half-Word)
 *                *original_val = target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_ASSIGN_ATOMIC_OPTH(volatile uint16 *original_val, uint16 target_val)
{
    do {
        if(target_val == TT_LDREXH(original_val))
        {
            TT_CLREX();
            break;
        }
    } while (TT_STREXH(target_val,original_val) != 0);
}

/**
 *@brief          Addition operation of Byte size data
 *                *original_val += target_val;
 *
 *@param[in]      target_val   - An addition in an addition operation
 *@param[out]     original_val - The value of the addition operation and
 *                               the address where the result is stored
 *@return         void
 */
LOCAL_INLINE void TT_ADD_ATOMIC_OPTB(volatile uint8 *original_val, uint8 target_val)
{
    uint8 local_temp = 0;

    do {
        local_temp = TT_LDREXB(original_val);
        local_temp = local_temp + target_val;
    } while(TT_STREXB(local_temp,original_val) != 0);
}

/**
 *@brief          Subtraction operation of Byte size data
 *                *original_val -= target_val;
 *
 *@param[in]      target_val   - A reduction in a subtraction operation
 *@param[out]     original_val - The address where the result data is stored
 *@return         void
 */
LOCAL_INLINE void TT_MINUS_ATOMIC_OPTB(volatile uint8 *original_val, uint8 target_val)
{
    uint8 local_temp = 0;

    do {
        local_temp = TT_LDREXB(original_val);
        local_temp = local_temp - target_val;
    } while(TT_STREXB(local_temp,original_val) != 0);
}

/**
 *@brief          Or-equal operation(Byte)
 *                *original_val |= target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_OR_EQUAL_ATOMIC_OPTB(volatile uint8 *original_val, uint8 target_val)
{
    uint8 local_temp = 0;

    do {
        local_temp = TT_LDREXB(original_val);
        local_temp = local_temp | target_val;
    } while(TT_STREXB(local_temp,original_val) != 0);
}

/**
 *@brief          And-equal operation(Byte)
 *                *original_val &= target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_AND_EQUAL_ATOMIC_OPTB(volatile uint8 *original_val, uint8 target_val)
{
    uint8 local_temp = 0;

    do {
        local_temp = TT_LDREXB(original_val);
        local_temp = local_temp & target_val;
    } while(TT_STREXB(local_temp,original_val) != 0);
}

/**
 *@brief          Assignment operation(Byte)
 *                *original_val = target_val;
 *
 *@param[in]      target_val   - Target value
 *@param[out]     original_val - Original value address
 *@return         void
 */
LOCAL_INLINE void TT_ASSIGN_ATOMIC_OPTB(volatile uint8 *original_val, uint8 target_val)
{
    do {
        if(target_val == TT_LDREXB(original_val))
        {
            TT_CLREX();
            break;
        }
    } while (TT_STREXB(target_val,original_val) != 0);
}


/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef TT_COMMON_H */
