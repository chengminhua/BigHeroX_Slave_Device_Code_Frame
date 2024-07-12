
/************************************************************************************
*  Copyright (c) 2023, ThinkTech, Inc. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without modification,
*  are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice, this
*     list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice, this
*     list of conditions and the following disclaimer in the documentation and/or
*     other materials provided with the distribution.
*
*  3) Neither the name of the ThinkTech, Inc., nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
*  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
*  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
*  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
*  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
*  OF THE POSSIBILITY OF SUCH DAMAGE.
*************************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

#define I2C_MEMMAP_VENDOR_ID_H                    1541
#define I2C_MEMMAP_AR_RELEASE_MAJOR_VERSION_H     4
#define I2C_MEMMAP_AR_RELEASE_MINOR_VERSION_H     4
#define I2C_MEMMAP_AR_RELEASE_PATCH_VERSION_H     0
#define I2C_MEMMAP_SW_MAJOR_VERSION_H             1
#define I2C_MEMMAP_SW_MINOR_VERSION_H             1
#define I2C_MEMMAP_SW_PATCH_VERSION_H             0

/**
* @brief Symbol used for checking correctness of the includes
*/
#define MEMMAP_ERROR


#if defined (_HITECH_C_ALIOTHXX_) || (_LLVM_C_ALIOTHXX_)

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_I2C_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_init_boolean.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_I2C_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    #define ENTERED_I2C_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_init_8.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_INIT_8
        #undef ENTERED_I2C_START_SEC_VAR_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    #define ENTERED_I2C_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_init_16.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_INIT_16
        #undef ENTERED_I2C_START_SEC_VAR_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    #define ENTERED_I2C_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_init_32.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_INIT_32
        #undef ENTERED_I2C_START_SEC_VAR_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_INIT_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_PTR
    #define ENTERED_I2C_START_SEC_VAR_INIT_PTR
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_INIT_PTR
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_init_ptr.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_INIT_PTR
        #undef ENTERED_I2C_START_SEC_VAR_INIT_PTR
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_INIT_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_I2C_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_init_unspecified.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_I2C_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_CLEARED_BOOLEAN
    #define ENTERED_I2C_START_SEC_VAR_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_cleared_boolean.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ENTERED_I2C_START_SEC_VAR_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_CLEARED_8
    #define ENTERED_I2C_START_SEC_VAR_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_cleared_8.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_CLEARED_8
        #undef ENTERED_I2C_START_SEC_VAR_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_CLEARED_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_CLEARED_16
    #define ENTERED_I2C_START_SEC_VAR_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_cleared_16.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_CLEARED_16
        #undef ENTERED_I2C_START_SEC_VAR_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_CLEARED_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_CLEARED_32
    #define ENTERED_I2C_START_SEC_VAR_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_cleared_32.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_CLEARED_32
        #undef ENTERED_I2C_START_SEC_VAR_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_CLEARED_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_CLEARED_PTR
    #define ENTERED_I2C_START_SEC_VAR_CLEARED_PTR
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_CLEARED_PTR
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_cleared_ptr.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_CLEARED_PTR
        #undef ENTERED_I2C_START_SEC_VAR_CLEARED_PTR
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_CLEARED_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define ENTERED_I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_cleared_unspecified.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ENTERED_I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_INIT_BOOLEAN
    #define ENTERED_I2C_START_SEC_VAR_FAST_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_fast_init_boolean.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_INIT_BOOLEAN
        #undef ENTERED_I2C_START_SEC_VAR_FAST_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_INIT_8
    #define ENTERED_I2C_START_SEC_VAR_FAST_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_fast_init_8.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_INIT_8
        #undef ENTERED_I2C_START_SEC_VAR_FAST_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_INIT_16
    #define ENTERED_I2C_START_SEC_VAR_FAST_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_fast_init_16.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_INIT_16
        #undef ENTERED_I2C_START_SEC_VAR_FAST_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_INIT_32
    #define ENTERED_I2C_START_SEC_VAR_FAST_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_fast_init_32.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_INIT_32
        #undef ENTERED_I2C_START_SEC_VAR_FAST_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_INIT_PTR
    #define ENTERED_I2C_START_SEC_VAR_FAST_INIT_PTR
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_INIT_PTR
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_fast_init_ptr.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_INIT_PTR
        #undef ENTERED_I2C_START_SEC_VAR_FAST_INIT_PTR
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_INIT_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define ENTERED_I2C_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data=".mcal_data_fast_init_unspecified.i2c" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_INIT_UNSPECIFIED
        #undef ENTERED_I2C_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_CLEARED_BOOLEAN
    #define ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_fast_cleared_boolean.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_BOOLEAN
        #undef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_CLEARED_8
    #define ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_fast_cleared_8.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_8
        #undef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_CLEARED_16
    #define ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_fast_cleared_16.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_16
        #undef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_CLEARED_32
    #define ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_fast_cleared_32.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_32
        #undef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_CLEARED_PTR
    #define ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_PTR
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_CLEARED_PTR
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_fast_cleared_ptr.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_PTR
        #undef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_PTR
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #define ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mcal_data_fast_cleared_unspecified.i2c" data="" rodata="" text=""
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
        #undef ENTERED_I2C_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    #define ENTERED_I2C_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_boolean.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_BOOLEAN
        #undef ENTERED_I2C_START_SEC_CONST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    #define ENTERED_I2C_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_8.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_8
        #undef ENTERED_I2C_START_SEC_CONST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    #define ENTERED_I2C_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_16.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_16
        #undef ENTERED_I2C_START_SEC_CONST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    #define ENTERED_I2C_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_32.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_32
        #undef ENTERED_I2C_START_SEC_CONST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_PTR
    #define ENTERED_I2C_START_SEC_CONST_PTR
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_PTR
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_ptr.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_PTR
        #undef ENTERED_I2C_START_SEC_CONST_PTR
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_I2C_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_unspecified.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_I2C_START_SEC_CONST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_FAST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_FAST_BOOLEAN
    #define ENTERED_I2C_START_SEC_CONST_FAST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_FAST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_fast_boolean.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_FAST_BOOLEAN
        #undef ENTERED_I2C_START_SEC_CONST_FAST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_FAST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_FAST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_FAST_8
    #define ENTERED_I2C_START_SEC_CONST_FAST_8
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_FAST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_fast_8.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_FAST_8
        #undef ENTERED_I2C_START_SEC_CONST_FAST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_FAST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_FAST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_FAST_16
    #define ENTERED_I2C_START_SEC_CONST_FAST_16
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_FAST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_fast_16.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_FAST_16
        #undef ENTERED_I2C_START_SEC_CONST_FAST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_FAST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_FAST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_FAST_32
    #define ENTERED_I2C_START_SEC_CONST_FAST_32
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_FAST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_fast_32.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_FAST_32
        #undef ENTERED_I2C_START_SEC_CONST_FAST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_FAST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_FAST_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_FAST_PTR
    #define ENTERED_I2C_START_SEC_CONST_FAST_PTR
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_FAST_PTR
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_fast_ptr.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_FAST_PTR
        #undef ENTERED_I2C_START_SEC_CONST_FAST_PTR
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_FAST_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONST_FAST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_FAST_UNSPECIFIED
    #define ENTERED_I2C_START_SEC_CONST_FAST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONST_FAST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_const_fast_unspecified.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONST_FAST_UNSPECIFIED
        #undef ENTERED_I2C_START_SEC_CONST_FAST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONST_FAST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_BOOLEAN
    #define ENTERED_I2C_START_SEC_CONFIG_DATA_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONFIG_DATA_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_config_data_boolean.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONFIG_DATA_BOOLEAN
        #undef ENTERED_I2C_START_SEC_CONFIG_DATA_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONFIG_DATA_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    #define ENTERED_I2C_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONFIG_DATA_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_config_data_8.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONFIG_DATA_8
        #undef ENTERED_I2C_START_SEC_CONFIG_DATA_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    #define ENTERED_I2C_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONFIG_DATA_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_config_data_16.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONFIG_DATA_16
        #undef ENTERED_I2C_START_SEC_CONFIG_DATA_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    #define ENTERED_I2C_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONFIG_DATA_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_config_data_32.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONFIG_DATA_32
        #undef ENTERED_I2C_START_SEC_CONFIG_DATA_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_PTR
    #define ENTERED_I2C_START_SEC_CONFIG_DATA_PTR
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONFIG_DATA_PTR
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_config_data_ptr.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONFIG_DATA_PTR
        #undef ENTERED_I2C_START_SEC_CONFIG_DATA_PTR
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONFIG_DATA_PTR
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata=".mcal_config_data_unspecified.i2c" text=""
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    #define ENTERED_I2C_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=".mcal_text_normal.i2c"
#endif
#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CODE
        #undef ENTERED_I2C_START_SEC_CODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CODE_FAST
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_FAST
    #define ENTERED_I2C_START_SEC_CODE_FAST
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CODE_FAST
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=".mcal_text_fast.i2c"
#endif
#ifdef I2C_STOP_SEC_CODE_FAST
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CODE_FAST
        #undef ENTERED_I2C_START_SEC_CODE_FAST
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CODE_FAST
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif

#ifdef I2C_START_SEC_CODE_SLOW
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_SLOW
    #define ENTERED_I2C_START_SEC_CODE_SLOW
    #ifndef MEMMAP_MATCH_ERROR
       #define MEMMAP_MATCH_ERROR
    #else
        #ifndef I2C_STOP_SEC_CODE_SLOW
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=".mcal_text_slow.i2c"
#endif
#ifdef I2C_STOP_SEC_CODE_SLOW
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef ENTERED_I2C_START_SEC_CODE_SLOW
        #undef ENTERED_I2C_START_SEC_CODE_SLOW
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef I2C_STOP_SEC_CODE_SLOW
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap.h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss="" data="" rodata="" text=""
#endif


#else

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    #undef I2C_START_SEC_VAR_INIT_8
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_8
    #undef I2C_STOP_SEC_VAR_INIT_8
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    #undef I2C_START_SEC_VAR_INIT_16
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_16
    #undef I2C_STOP_SEC_VAR_INIT_16
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    #undef I2C_START_SEC_VAR_INIT_32
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_32
    #undef I2C_STOP_SEC_VAR_INIT_32
#endif

#ifdef I2C_START_SEC_VAR_INIT_PTR
    #undef I2C_START_SEC_VAR_INIT_PTR
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_PTR
    #undef I2C_STOP_SEC_VAR_INIT_PTR
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_BOOLEAN
    #undef I2C_START_SEC_VAR_CLEARED_BOOLEAN
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef I2C_STOP_SEC_VAR_CLEARED_BOOLEAN
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_8
    #undef I2C_START_SEC_VAR_CLEARED_8
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_8
    #undef I2C_STOP_SEC_VAR_CLEARED_8
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_16
    #undef I2C_START_SEC_VAR_CLEARED_16
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_16
    #undef I2C_STOP_SEC_VAR_CLEARED_16
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_32
    #undef I2C_START_SEC_VAR_CLEARED_32
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_32
    #undef I2C_STOP_SEC_VAR_CLEARED_32
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_PTR
    #undef I2C_START_SEC_VAR_CLEARED_PTR
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_PTR
    #undef I2C_STOP_SEC_VAR_CLEARED_PTR
#endif

#ifdef I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_BOOLEAN
    #undef I2C_START_SEC_VAR_FAST_INIT_BOOLEAN
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_BOOLEAN
    #undef I2C_STOP_SEC_VAR_FAST_INIT_BOOLEAN
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_8
    #undef I2C_START_SEC_VAR_FAST_INIT_8
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_8
    #undef I2C_STOP_SEC_VAR_FAST_INIT_8
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_16
    #undef I2C_START_SEC_VAR_FAST_INIT_16
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_16
    #undef I2C_STOP_SEC_VAR_FAST_INIT_16
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_32
    #undef I2C_START_SEC_VAR_FAST_INIT_32
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_32
    #undef I2C_STOP_SEC_VAR_FAST_INIT_32
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_PTR
    #undef I2C_START_SEC_VAR_FAST_INIT_PTR
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_PTR
    #undef I2C_STOP_SEC_VAR_FAST_INIT_PTR
#endif

#ifdef I2C_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef I2C_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_BOOLEAN
    #undef I2C_START_SEC_VAR_FAST_CLEARED_BOOLEAN
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_8
    #undef I2C_START_SEC_VAR_FAST_CLEARED_8
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_8
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_8
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_16
    #undef I2C_START_SEC_VAR_FAST_CLEARED_16
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_16
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_16
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_32
    #undef I2C_START_SEC_VAR_FAST_CLEARED_32
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_32
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_32
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_PTR
    #undef I2C_START_SEC_VAR_FAST_CLEARED_PTR
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_PTR
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_PTR
#endif

#ifdef I2C_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #undef I2C_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#endif
#ifdef I2C_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    #undef I2C_START_SEC_CONST_BOOLEAN
#endif
#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    #undef I2C_STOP_SEC_CONST_BOOLEAN
#endif

#ifdef I2C_START_SEC_CONST_8
    #undef I2C_START_SEC_CONST_8
#endif
#ifdef I2C_STOP_SEC_CONST_8
    #undef I2C_STOP_SEC_CONST_8
#endif

#ifdef I2C_START_SEC_CONST_16
    #undef I2C_START_SEC_CONST_16
#endif
#ifdef I2C_STOP_SEC_CONST_16
    #undef I2C_STOP_SEC_CONST_16
#endif

#ifdef I2C_START_SEC_CONST_32
    #undef I2C_START_SEC_CONST_32
#endif
#ifdef I2C_STOP_SEC_CONST_32
    #undef I2C_STOP_SEC_CONST_32
#endif

#ifdef I2C_START_SEC_CONST_PTR
    #undef I2C_START_SEC_CONST_PTR
#endif
#ifdef I2C_STOP_SEC_CONST_PTR
    #undef I2C_STOP_SEC_CONST_PTR
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    #undef I2C_START_SEC_CONST_UNSPECIFIED
#endif
#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
#endif

#ifdef I2C_START_SEC_CONST_FAST_BOOLEAN
    #undef I2C_START_SEC_CONST_FAST_BOOLEAN
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_BOOLEAN
    #undef I2C_STOP_SEC_CONST_FAST_BOOLEAN
#endif

#ifdef I2C_START_SEC_CONST_FAST_8
    #undef I2C_START_SEC_CONST_FAST_8
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_8
    #undef I2C_STOP_SEC_CONST_FAST_8
#endif

#ifdef I2C_START_SEC_CONST_FAST_16
    #undef I2C_START_SEC_CONST_FAST_16
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_16
    #undef I2C_STOP_SEC_CONST_FAST_16
#endif

#ifdef I2C_START_SEC_CONST_FAST_32
    #undef I2C_START_SEC_CONST_FAST_32
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_32
    #undef I2C_STOP_SEC_CONST_FAST_32
#endif

#ifdef I2C_START_SEC_CONST_FAST_PTR
    #undef I2C_START_SEC_CONST_FAST_PTR
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_PTR
    #undef I2C_STOP_SEC_CONST_FAST_PTR
#endif

#ifdef I2C_START_SEC_CONST_FAST_UNSPECIFIED
    #undef I2C_START_SEC_CONST_FAST_UNSPECIFIED
#endif
#ifdef I2C_STOP_SEC_CONST_FAST_UNSPECIFIED
    #undef I2C_STOP_SEC_CONST_FAST_UNSPECIFIED
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_BOOLEAN
    #undef I2C_START_SEC_CONFIG_DATA_BOOLEAN
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_BOOLEAN
    #undef I2C_STOP_SEC_CONFIG_DATA_BOOLEAN
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_8
    #undef I2C_START_SEC_CONFIG_DATA_8
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    #undef I2C_STOP_SEC_CONFIG_DATA_8
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    #undef I2C_START_SEC_CONFIG_DATA_16
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    #undef I2C_STOP_SEC_CONFIG_DATA_16
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    #undef I2C_START_SEC_CONFIG_DATA_32
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    #undef I2C_STOP_SEC_CONFIG_DATA_32
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_PTR
    #undef I2C_START_SEC_CONFIG_DATA_PTR
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_PTR
    #undef I2C_STOP_SEC_CONFIG_DATA_PTR
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif
#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#ifdef I2C_START_SEC_CODE
    #undef I2C_START_SEC_CODE
#endif
#ifdef I2C_STOP_SEC_CODE
    #undef I2C_STOP_SEC_CODE
#endif

#ifdef I2C_START_SEC_CODE_FAST
    #undef I2C_START_SEC_CODE_FAST
#endif
#ifdef I2C_STOP_SEC_CODE_FAST
    #undef I2C_STOP_SEC_CODE_FAST
#endif

#ifdef I2C_START_SEC_CODE_SLOW
    #undef I2C_START_SEC_CODE_SLOW
#endif
#ifdef I2C_STOP_SEC_CODE_SLOW
    #undef I2C_STOP_SEC_CODE_SLOW
#endif


#endif /* compile end */

#ifdef __cplusplus
}
#endif

