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
**  FILENAME     : Base_Internal.h                                            **
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
#ifndef BASE_INTERNAL_H
#define BASE_INTERNAL_H

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_INTERNAL_VENDOR_ID_H                     1541
#define BASE_INTERNAL_MODULE_ID_H                     218
#define BASE_INTERNAL_AR_RELEASE_MAJOR_VERSION_H      4
#define BASE_INTERNAL_AR_RELEASE_MINOR_VERSION_H      4
#define BASE_INTERNAL_AR_RELEASE_PATCH_VERSION_H      0
#define BASE_INTERNAL_SW_MAJOR_VERSION_H              1
#define BASE_INTERNAL_SW_MINOR_VERSION_H              1
#define BASE_INTERNAL_SW_PATCH_VERSION_H              0

/******************************************************************************
*                            Includes
******************************************************************************/
#include "TT_StandardTypes.h"
#include "TT_Compiler.h"

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Internal.h and TT_StandardTypes.h file version check */
#if (BASE_INTERNAL_VENDOR_ID_H != TT_STANDARD_TYPES_VENDOR_ID_H)
    #error "Base_Internal.h and TT_StandardTypes.h have different vendor id"
#endif
#if ((BASE_INTERNAL_AR_RELEASE_MAJOR_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_INTERNAL_AR_RELEASE_MINOR_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_INTERNAL_AR_RELEASE_PATCH_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Internal.h and TT_StandardTypes.h are different"
#endif
#if ((BASE_INTERNAL_SW_MAJOR_VERSION_H != TT_STANDARD_TYPES_SW_MAJOR_VERSION_H) || \
     (BASE_INTERNAL_SW_MINOR_VERSION_H != TT_STANDARD_TYPES_SW_MINOR_VERSION_H) || \
     (BASE_INTERNAL_SW_PATCH_VERSION_H != TT_STANDARD_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Internal.h and TT_StandardTypes.h are different"
#endif


#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
/* prototypes defined in system.h*/
#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue);
uint32 Sys_GoToSupervisor(void);
uint32 Sys_GoToUser(void);
void Sys_SuspendInterrupts(void);
void Sys_ResumeInterrupts(void);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"
#endif /* def MCAL_ENABLE_USER_MODE_SUPPORT */


/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
/*
 * Base_Trusted_Call*
 */
#if defined(MCAL_ENABLE_USER_MODE_SUPPORT)
#define Base_Trusted_Set8(Addr, Value)	\
        ((1UL == Sys_GoToSupervisor()) ? (ALIOTH_SET_REG8(Addr, Value), (void)Sys_GoToUser()) : (ALIOTH_SET_REG8(Addr, Value),(void)0U))
#define Base_Trusted_Set16(Addr, Value)	\
        ((1UL == Sys_GoToSupervisor()) ? (ALIOTH_SET_REG16(Addr, Value), (void)Sys_GoToUser()) : (ALIOTH_SET_REG16(Addr, Value),(void)0U))
#define Base_Trusted_Set32(Addr, Value)	\
        ((1UL == Sys_GoToSupervisor()) ? (ALIOTH_SET_REG32(Addr, Value), (void)Sys_GoToUser()) : (ALIOTH_SET_REG32(Addr, Value),(void)0U))

#define Base_Trusted_Get8(Addr)	\
        ((1UL == Sys_GoToSupervisor()) ? Sys_GoToUser_Return(1U, ALIOTH_GET_REG8(Addr)) : Sys_GoToUser_Return(0U, ALIOTH_GET_REG8(Addr)))
#define Base_Trusted_Get16(Addr)	\
        ((1UL == Sys_GoToSupervisor()) ? Sys_GoToUser_Return(1U, ALIOTH_GET_REG16(Addr)) : Sys_GoToUser_Return(0U, ALIOTH_GET_REG16(Addr)))
#define Base_Trusted_Get32(Addr)	\
        ((1UL == Sys_GoToSupervisor()) ? Sys_GoToUser_Return(1U, ALIOTH_GET_REG32(Addr)) : Sys_GoToUser_Return(0U, ALIOTH_GET_REG32(Addr)))

#define Base_Trusted_Call(name)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(), (void)Sys_GoToUser()) : (name(),(void)0U))
#define Base_Trusted_Call1param(name,param)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param), (void)Sys_GoToUser()) : (name(param),(void)0U))
#define Base_Trusted_Call2params(name,param1,param2)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2), (void)Sys_GoToUser()) : (name(param1,param2),(void)0U))
#define Base_Trusted_Call3params(name,param1,param2,param3)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3), (void)Sys_GoToUser()) : (name(param1,param2,param3),(void)0U))
#define Base_Trusted_Call4params(name,param1,param2,param3,param4)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4),(void)0U))
#define Base_Trusted_Call5params(name,param1,param2,param3,param4,param5)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4,param5), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4,param5),(void)0U))
#define Base_Trusted_Call6params(name,param1,param2,param3,param4,param5,param6)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4,param5,param6), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4,param5,param6),(void)0U))

#define Base_Trusted_Call_Return(name)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name()) :  Sys_GoToUser_Return(0U, name()))
#define Base_Trusted_Call_Return1param(name,param)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param)) :  Sys_GoToUser_Return(0U, name(param)))
#define Base_Trusted_Call_Return2param(name,param1,param2)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2)) : Sys_GoToUser_Return(0U, name(param1,param2)))
#define Base_Trusted_Call_Return3param(name,param1,param2,param3)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3)))
#define Base_Trusted_Call_Return4param(name,param1,param2,param3,param4)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4)))
#define Base_Trusted_Call_Return5param(name,param1,param2,param3,param4,param5)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4,param5)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4,param5)))
#define Base_Trusted_Call_Return6param(name,param1,param2,param3,param4,param5,param6)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4,param5,param6)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4,param5,param6)))
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */


/*
 * Base_SuspendAllInterrupts
 * Base_ResumeAllInterrupts
 */
#if defined(MCAL_ENABLE_USER_MODE_SUPPORT)
    #define ResumeAllInterrupts()   Sys_ResumeInterrupts()  /* BASEPRI will be set to 0x0 from SVC handler */
    #define SuspendAllInterrupts()  Sys_SuspendInterrupts() /* BASEPRI will be set to 0x10 from SVC handler */
#else
    #define ResumeAllInterrupts()       ASM_KEYWORD(" cpsie i")
    #define SuspendAllInterrupts()      ASM_KEYWORD(" cpsid i")
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */

/* @implements Base_SuspendAllInterrupts_define */
#define Base_SuspendAllInterrupts()     SuspendAllInterrupts()
/* @implements Base_ResumeAllInterrupts_define */
#define Base_ResumeAllInterrupts()      ResumeAllInterrupts()

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

#endif /* BASE_INTERNAL_H */
