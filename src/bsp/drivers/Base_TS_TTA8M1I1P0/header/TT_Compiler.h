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
**  FILENAME     : TT_Compiler.h                                              **
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
*[V1.1.0]:                                                                    ** 
*******************************************************************************/

#ifndef TT_COMPILER_H
#define TT_COMPILER_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#include "TT_PlatformTypes.h"
#ifdef USING_OS_AUTOSAROS
#include "Compiler.h"
#endif
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_COMPILER_VENDOR_ID_H                     1541
#define TT_COMPILER_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_COMPILER_AR_RELEASE_MINOR_VERSION_H      4
#define TT_COMPILER_AR_RELEASE_PATCH_VERSION_H      0
#define TT_COMPILER_SW_MAJOR_VERSION_H              1
#define TT_COMPILER_SW_MINOR_VERSION_H              1
#define TT_COMPILER_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* TT_Compiler.h and TT_PlatformTypes.h file version check */
#if (TT_COMPILER_VENDOR_ID_H != TT_PLATFORM_TYPES_VENDOR_ID_H)
    #error "TT_Compiler.h and TT_PlatformTypes.h have different vendor id"
#endif
#if ((TT_COMPILER_AR_RELEASE_MAJOR_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_COMPILER_AR_RELEASE_MINOR_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_COMPILER_AR_RELEASE_PATCH_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Compiler.h and TT_PlatformTypes.h are different"
#endif
#if ((TT_COMPILER_SW_MAJOR_VERSION_H != TT_PLATFORM_TYPES_SW_MAJOR_VERSION_H) || \
     (TT_COMPILER_SW_MINOR_VERSION_H != TT_PLATFORM_TYPES_SW_MINOR_VERSION_H) || \
     (TT_COMPILER_SW_PATCH_VERSION_H != TT_PLATFORM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Compiler.h and TT_PlatformTypes.h are different"
#endif

#ifndef USING_OS_AUTOSAROS

    #define NULL_PTR ((void*)0)

#endif


/**************************************** Green Hills *********************************************/
#ifdef _GREENHILLS_C_ALIOTHXX_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */    
    #define ASM_KEYWORD  __asm

    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define VAR_ALIGN(size) __attribute__(( aligned(size) ))
    /**
    * @brief Places data or code into a specified segment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define SECTION_DATA(sec)  __attribute__ ((section (sec)))
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define ALIGNED_VARS_STOP()
    
   /**
    * @brief Compiler abstraction for the packed qualifier
    */
    #define PACKED __packed 

   /**
    * @brief Compiler abstraction for the weak qualifier
    */
    #define TT_WEAK __attribute__((weak))

    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        #define MCAL_PUT_IN_QUOTES(x) #x
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        #define MCAL_FAULT_INJECTION_POINT(label) ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label::))
    #else
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif

#ifndef USING_OS_AUTOSAROS
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE              __inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static __inline
#endif

#endif 

/*************************************** HighTec **********************************************/
#if defined(_HITECH_C_ALIOTHXX_) || defined(_LLVM_C_ALIOTHXX_)
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define ASM_KEYWORD  __asm volatile

    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define VAR_ALIGN(size) __attribute__(( aligned(size) ))
    /**
    * @brief Places data or code into a specified segment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define SECTION_DATA(sec) __attribute__ ((section (sec)))
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define ALIGNED_VARS_STOP()
   /**
    * @brief Compiler abstraction for the weak qualifier
    */
    #define TT_WEAK __attribute__((weak))
    /**
     * @brief Compiler abstraction for the packed qualifier
     */
    #define PACKED __attribute__((__packed__))
#ifndef USING_OS_AUTOSAROS
    #define INLINE                              __inline
    #define LOCAL_INLINE                        static __inline
#endif

#endif /* #ifdef _HITECH_C_ALIOTHXX_ */

/**************************************** GCC *********************************************/
#ifdef _GCC_C_ALIOTHXX_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */    
    #define ASM_KEYWORD  __asm volatile

    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define VAR_ALIGN(size) __attribute__(( aligned(size) ))
     /**
    * @brief Places data or code into a specified segment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define SECTION_DATA(sec)  __attribute__ ((section (sec)))
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    #define ALIGNED_VARS_STOP()
    
    /**
     * @brief Compiler abstraction for the packed qualifier
     */
    #define PACKED __attribute__((__packed__))
   /**
    * @brief Compiler abstraction for the weak qualifier
    */
    #define TT_WEAK __attribute__((weak))

#ifndef USING_OS_AUTOSAROS
    #define INLINE                              inline
    #define LOCAL_INLINE                        static inline
#endif

#endif /* #ifdef _GCC_C_ALIOTHXX_ */

#ifdef __ARMCC_VERSION /* armclang */
/**
* @brief Data Synchronization Barrier (DSB) completes when all instructions before this instruction complete
*/
/*
* @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define ASM_KEYWORD  __asm volatile

#ifndef USING_OS_AUTOSAROS
#define INLINE                              __inline
#define LOCAL_INLINE                        static __inline
#endif
/**
* @brief Compiler abstraction for the data alignment
*/
/**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
#define ALIGNED_VARS_START(sec_name, align)
/**
* @brief Compiler abstraction for the data alignment
*/
/**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
#define VAR_ALIGN(size) __attribute__(( aligned(size) ))
/**
* @brief Places data or code into a specified segment
*/
/**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
#define SECTION_DATA(sec)  __attribute__ ((section (sec)))
/**
* @brief Compiler abstraction for the data alignment
*/
/**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
#define ALIGNED_VARS_STOP()
/**
* @brief Compiler abstraction for the packed qualifier
*/
#define PACKED __packed 
/**
* @brief Compiler abstraction for the weak qualifier
*/
#define TT_WEAK 
/**
* @brief  flushes the pipeline in the processor, so that all instructions following the ISB are fetched from cache or memory, after the ISB has been completed.
*/
/*
* @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro.
*/

#endif /* 0 */

#ifndef USING_OS_AUTOSAROS
#define CONST const
#endif

/* for vectorcast test */
#ifndef _VCAST_MINGW_C
/* const macro definition */
#define TT_CONST const
/* Data Synchronization Barrier */
#define MCAL_DATA_SYNC_BARRIER()            ASM_KEYWORD("DSB")
/* Data Memory Barrier */
#define MCAL_MEM_SYNC_BARRIER()             ASM_KEYWORD("DMB")
/* Instruction Synchronization Barrier */
#define MCAL_INSTRUCTION_SYNC_BARRIER()     ASM_KEYWORD("ISB")
/* Wait For Interrupt */
#define MCAL_WFI()                          ASM_KEYWORD("WFI")
#else
#define MCAL_DATA_SYNC_BARRIER()
#define MCAL_MEM_SYNC_BARRIER()
#define MCAL_INSTRUCTION_SYNC_BARRIER()
#define MCAL_WFI()
#define TT_CONST
#endif

#if defined(UART0_PRINTF) || defined(UART1_PRINTF)
/* Version number of the C standard supported by the current compiler */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199901L)
/* macro definition of the name of the current function */
#define TT_FUNCTION         __func__
#else
#define TT_FUNCTION         0
#endif
/* Macro definition of the current source code line number */
#define TT_LINE             __LINE__
#else

#define TT_FUNCTION         (void *)0
#define TT_LINE             0
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

#endif /* #ifndef TT_COMPILER_H */

/** @} */
