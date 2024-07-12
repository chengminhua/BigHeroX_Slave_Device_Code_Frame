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
**  FILENAME     : TT_BasicTypes.h                                            **
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
*[V1.0.1]:                                                                    **
*******************************************************************************/
#ifndef TT_BASICTYPES_H
#define TT_BASICTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                       File Version Checks
******************************************************************************/

#include "TT_PlatformTypes.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_BASIC_TYPES_VENDOR_ID_H                     1541
#define TT_BASIC_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_BASIC_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define TT_BASIC_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define TT_BASIC_TYPES_SW_MAJOR_VERSION_H              1
#define TT_BASIC_TYPES_SW_MINOR_VERSION_H              1
#define TT_BASIC_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* TT_BasicTypes.h and TT_PlatformTypes.h file version check */
#if (TT_BASIC_TYPES_VENDOR_ID_H != TT_PLATFORM_TYPES_VENDOR_ID_H)
    #error "TT_BasicTypes.h and TT_PlatformTypes.h have different vendor id"
#endif
#if ((TT_BASIC_TYPES_AR_RELEASE_MAJOR_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_BASIC_TYPES_AR_RELEASE_MINOR_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_BASIC_TYPES_AR_RELEASE_PATCH_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_BasicTypes.h and TT_PlatformTypes.h are different"
#endif
#if ((TT_BASIC_TYPES_SW_MAJOR_VERSION_H != TT_PLATFORM_TYPES_SW_MAJOR_VERSION_H) || \
     (TT_BASIC_TYPES_SW_MINOR_VERSION_H != TT_PLATFORM_TYPES_SW_MINOR_VERSION_H) || \
     (TT_BASIC_TYPES_SW_PATCH_VERSION_H != TT_PLATFORM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_BasicTypes.h and TT_PlatformTypes.h are different"
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
#ifdef _GCC_C_ALIOTHXX_
#include "stdint.h"

#else
/* define stdint.h-like types over PlatformTypes.h */

/**
@brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) -
       8 bit
*/
typedef uint8 uint8_t;

/**
@brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) -
       16 bit
*/
typedef uint16 uint16_t;

/**
@brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) -
       32 bit
*/
typedef uint32 uint32_t;

/**
@brief Unsigned 64 bit integer with range of 0 ..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF) -
       64 bit
*/
typedef uint64 uint64_t;

/**
@brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) -
       7 bit + 1 sign bit
*/
typedef sint8 sint8_t;

/**
@brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) -
       15 bit + 1 sign bit
*/
typedef sint16 sint16_t;

/**
@brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) -
       31 bit + 1 sign bit
*/
typedef sint32 sint32_t;

/**
@brief Signed 64 bit integer with range of -9223372036854775808.. +9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF) -
       63 bit + 1 sign bit
*/
typedef sint64 sint64_t;

/**
@brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) -
       7 bit + 1 sign bit
*/
typedef sint8 int8_t;

/**
@brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) -
       15 bit + 1 sign bit
*/
typedef sint16 int16_t;

/**
@brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) -
       31 bit + 1 sign bit
*/
typedef sint32 int32_t;

/**
@brief Signed 64 bit integer with range of -9223372036854775808.. +9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF) -
       63 bit + 1 sign bit
*/
typedef sint64 int64_t;

/**
@brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) -
       8 bit
*/
typedef uint8_least uint8_least_t;

/**
@brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) -
        16 bit
*/
typedef uint16_least uint16_least_t;

/**
@brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295 (0x00000000..0xFFFFFFFF) -
       32 bit
*/
typedef uint32_least uint32_least_t;

/**
@brief Unsigned integer at least 64 bit long. Range of at least 0 ..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF) -
       64 bit
*/
typedef unsigned long long uint64_least_t;

/**
@brief Signed integer at least 8 bit long. Range - at least -128 ..+127.
       At least 7 bit + 1 bit sign
*/
typedef sint8_least sint8_least_t;

/**
@brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767.
       At least 15 bit + 1 bit sign
*/
typedef sint16_least sint16_least_t;

/**
@brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647.
       At least 31 bit + 1 bit sign
*/
typedef sint32_least sint32_least_t;

/**
@brief Signed 64 bit integer with range of -9223372036854775808.. +9223372036854775807.
       At least 63 bit + 1 bit sign
*/
typedef sint64 sint64_least_t;

/**
@brief Signed integer at least 8 bit long. Range - at least -128 ..+127.
       At least 7 bit + 1 bit sign
*/
typedef sint8_least int8_least_t;

/**
@brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767.
       At least 15 bit + 1 bit sign
*/
typedef sint16_least int16_least_t;

/**
@brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647.
       At least 31 bit + 1 bit sign
*/
typedef sint32_least int32_least_t;

/**
@brief Signed integer at least 64 bit long. Range - at least -9223372036854775808.. +9223372036854775807.
       At least 63 bit + 1 bit sign
*/
typedef sint64 int64_least_t;

#endif /* _GCC_C_ALIOTHXX_ */

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

#ifdef __cplusplus
}
#endif

#endif /* BASICTYPES_H */
