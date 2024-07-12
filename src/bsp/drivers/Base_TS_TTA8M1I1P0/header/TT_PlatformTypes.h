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
**  FILENAME     : TT_PlatformTypes.h                                         **
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
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef TT_PLATFORMTYPES_H
#define TT_PLATFORMTYPES_H

/******************************************************************************
*                            Includes
******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#ifdef USING_OS_AUTOSAROS
#include "Platform_Types.h"
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_PLATFORM_TYPES_VENDOR_ID_H                     1541
#define TT_PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define TT_PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define TT_PLATFORM_TYPES_SW_MAJOR_VERSION_H              1
#define TT_PLATFORM_TYPES_SW_MINOR_VERSION_H              1
#define TT_PLATFORM_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
/**
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long
*        unsigned integer.
* @implements boolean_type
*/

#ifdef USING_OS_AUTOSAROS
/* c90 */
#ifndef __STDC_VERSION__
    typedef unsigned char bool;
#endif
#else
/* c90 */

#ifndef __STDC_VERSION__
    typedef unsigned char boolean;
#else
/* c99 */
#ifndef _VCAST_MINGW_C
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199901L)
    typedef bool boolean;
#endif
#else
    typedef unsigned char boolean;
#endif
#endif

/**
* @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) -
*        8 bit
* @implements uint8_type
*/
typedef unsigned char uint8;

/**
* @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) -
*        16 bit
* @implements uint16_type
*/
typedef unsigned short uint16;

/**
* @brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) -
*        32 bit
* @implements uint32_type
*/
typedef unsigned int uint32;

/**
* @brief Unsigned 64 bit integer with range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF)-
*        64 bit
*
*/
typedef unsigned long long uint64;

/**
* @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) -
*        7 bit + 1 sign bit
* @implements sint8_type
*/
typedef signed char sint8;

/**
* @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) -
*        15 bit + 1 sign bit
* @implements sint16_type
*/
typedef signed short sint16;

/**
* @brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) -
*        31 bit + 1 sign bit
* @implements sint32_type
*/
typedef signed int sint32;

/**
* @brief Signed 64 bit integer with range of -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF )-
*        63 bit + 1 sign bit
*
*/
typedef signed long long sint64;

/**
* @brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) -
*        8 bit
* @implements uint8_least_type
*/
typedef unsigned long uint8_least;

/**
* @brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) -
*         16 bit
* @implements uint16_least_type
*/
typedef unsigned long uint16_least;

/**
* @brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295
*       (0x00000000..0xFFFFFFFF) - 32 bit
* @implements uint32_least_type
*/
typedef unsigned long uint32_least;

/**
* @brief Signed integer at least 8 bit long. Range - at least -128 ..+127.
*        At least 7 bit + 1 bit sign
* @implements sint8_least_type
*/
typedef signed long sint8_least;

/**
* @brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767.
*        At least 15 bit + 1 bit sign
* @implements sint16_least_type
*/
typedef signed long sint16_least;

/**
* @brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647.
*       At least 31 bit + 1 bit sign
* @implements sint32_least_type
*/
typedef signed long sint32_least;

/**
* @brief 32bit long floating point data type
* @implements float32_type
*/
typedef float float32;

/**
* @brief 64bit long floating point data type
* @implements float64_type
*/
typedef double float64;

/**
* @brief 64bit long floating point data type
* @implements float64_type
*/
typedef uint8 Std_ReturnType;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

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

/******************************************************************************
*                            Private Functions
******************************************************************************/

#endif

#endif /* PLATFORM_TYPES_H */

