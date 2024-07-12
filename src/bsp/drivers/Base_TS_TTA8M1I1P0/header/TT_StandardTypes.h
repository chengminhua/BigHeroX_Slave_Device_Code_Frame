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
**  FILENAME     : TT_StandardTypes.h                                         **
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
#ifndef TT_STANDARDTYPES_H
#define TT_STANDARDTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#ifdef USING_OS_AUTOSAROS
#include "Std_Types.h"
#else
#include "TT_PlatformTypes.h"
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_STANDARD_TYPES_VENDOR_ID_H                     1541
#define TT_STANDARD_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_STANDARD_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define TT_STANDARD_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define TT_STANDARD_TYPES_SW_MAJOR_VERSION_H              1
#define TT_STANDARD_TYPES_SW_MINOR_VERSION_H              1
#define TT_STANDARD_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#ifdef USING_OS_AUTOSAROS
#else
/* TT_StandardTypes.h and TT_PlatformTypes.h file version check */
#if (TT_STANDARD_TYPES_VENDOR_ID_H != TT_PLATFORM_TYPES_VENDOR_ID_H)
    #error "TT_StandardTypes.h and TT_PlatformTypes.h have different vendor id"
#endif
#if ((TT_STANDARD_TYPES_AR_RELEASE_MAJOR_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_STANDARD_TYPES_AR_RELEASE_MINOR_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_STANDARD_TYPES_AR_RELEASE_PATCH_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_StandardTypes.h and TT_PlatformTypes.h are different"
#endif
#if ((TT_STANDARD_TYPES_SW_MAJOR_VERSION_H != TT_PLATFORM_TYPES_SW_MAJOR_VERSION_H) || \
     (TT_STANDARD_TYPES_SW_MINOR_VERSION_H != TT_PLATFORM_TYPES_SW_MINOR_VERSION_H) || \
     (TT_STANDARD_TYPES_SW_PATCH_VERSION_H != TT_PLATFORM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_StandardTypes.h and TT_PlatformTypes.h are different"
#endif
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
#ifdef USING_OS_AUTOSAROS
#else
/* Function return */
#define E_OK 			0u
#define E_NOT_OK 		1u
#define E_TMOUT			2u

/* Physical state 5V or 3.3V  */
#define STD_HIGH 		0x01u
/* Physical state 0V          */
#define STD_LOW 		0x00u

/* on/off switch */
#define STD_ON			0x01u
#define STD_OFF 		0x00u

/* Logical state active       */
#define STD_ACTIVE      0x01u
/* Logical state idle         */
#define STD_IDLE        0x00u

typedef struct {
    uint16 vendorID;
    uint16 moduleID;

    uint8 sw_major_version;    /*Vendor numbers */
    uint8 sw_minor_version;    /* Vendor numbers */
    uint8 sw_patch_version;    /* Vendor numbers */
} Std_VersionInfoType;

#define ISR(x) void x(void)

#endif

/*
 * uint32 StatusId      : 16;
 * uint32 ApiId         : 8;
 * uint32 ModuleId      : 8;
 * */
typedef uint32 TT_RetType;

#define TT_U64_BITS     64
#define TT_U32_BITS     32
#define TT_U16_BITS     16
#define TT_U8_BITS      8

typedef void (*TT_CallBackEvent) (uint32 event);

typedef void (*TT_Notification) (void);

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

#endif /* STANDARD_TYPES_H */
