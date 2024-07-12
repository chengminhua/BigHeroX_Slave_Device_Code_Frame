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
**  FILENAME     : TT_BaseInterface.h                                         **
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
#ifndef TT_BASEINTERFACE_H
#define TT_BASEINTERFACE_H

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#include "TT_StandardTypes.h"
#include "TT_Compiler.h"

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_BASE_INTERFACE_VENDOR_ID_H                     1541
#define TT_BASE_INTERFACE_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_BASE_INTERFACE_AR_RELEASE_MINOR_VERSION_H      4
#define TT_BASE_INTERFACE_AR_RELEASE_PATCH_VERSION_H      0
#define TT_BASE_INTERFACE_SW_MAJOR_VERSION_H              1
#define TT_BASE_INTERFACE_SW_MINOR_VERSION_H              1
#define TT_BASE_INTERFACE_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* TT_BaseInterface.h and TT_StandardTypes.h file version check */
#if (TT_BASE_INTERFACE_VENDOR_ID_H != TT_STANDARD_TYPES_VENDOR_ID_H)
    #error "TT_BaseInterface.h and TT_StandardTypes.h have different vendor id"
#endif
#if ((TT_BASE_INTERFACE_AR_RELEASE_MAJOR_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_BASE_INTERFACE_AR_RELEASE_MINOR_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_BASE_INTERFACE_AR_RELEASE_PATCH_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_BaseInterface.h and TT_StandardTypes.h are different"
#endif
#if ((TT_BASE_INTERFACE_SW_MAJOR_VERSION_H != TT_STANDARD_TYPES_SW_MAJOR_VERSION_H) || \
     (TT_BASE_INTERFACE_SW_MINOR_VERSION_H != TT_STANDARD_TYPES_SW_MINOR_VERSION_H) || \
     (TT_BASE_INTERFACE_SW_PATCH_VERSION_H != TT_STANDARD_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_BaseInterface.h and TT_StandardTypes.h are different"
#endif

/* TT_BaseInterface.h and TT_Compiler.h file version check */
#if (TT_BASE_INTERFACE_VENDOR_ID_H != TT_COMPILER_VENDOR_ID_H)
    #error "TT_BaseInterface.h and TT_Compiler.h have different vendor id"
#endif
#if ((TT_BASE_INTERFACE_AR_RELEASE_MAJOR_VERSION_H != TT_COMPILER_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_BASE_INTERFACE_AR_RELEASE_MINOR_VERSION_H != TT_COMPILER_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_BASE_INTERFACE_AR_RELEASE_PATCH_VERSION_H != TT_COMPILER_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_BaseInterface.h and TT_Compiler.h are different"
#endif
#if ((TT_BASE_INTERFACE_SW_MAJOR_VERSION_H != TT_COMPILER_SW_MAJOR_VERSION_H) || \
     (TT_BASE_INTERFACE_SW_MINOR_VERSION_H != TT_COMPILER_SW_MINOR_VERSION_H) || \
     (TT_BASE_INTERFACE_SW_PATCH_VERSION_H != TT_COMPILER_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_BaseInterface.h and TT_Compiler.h are different"
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
/** Simple macro to supress the unused parameter warning by casting to void. */
#define TT_UNUSED_PARAMETER(x) ( (void)(x) )

/* TT set enum */
typedef enum
{
    TT_RESET = 0,
    TT_SET = !TT_RESET
}FlagStatus, ITStatus;
/* TT enable enum */
typedef enum
{
    TT_DISABLE = 0,
    TT_ENABLE = !TT_DISABLE
}FunctionalState;

/* TT success enum */
typedef enum
{
    TT_SUCCESS = 0,
    TT_ERROR = !TT_SUCCESS
}ErrorStatus;

/* The macro definition that erases the value of u8 */
#define ERASE_VALUE_U8           (0xFFUL)
/* The macro definition that erases the value of u16 */
#define ERASE_VALUE_U16          (0xFFFFUL)
/* The macro definition that erases the value of u32 */
#define ERASE_VALUE_U32          (0xFFFFFFFFUL)
/* The macro definition that erases the value of u64 */
#define ERASE_VALUE_U64          (0xFFFFFFFFFFFFFFFFUL)

/* The macro definition that module precompile */
#define MODULE_VARIANT_PRECOMPILE  (0x0U)
/* The macro definition that erases module linktime */
#define MODULE_VARIANT_LINKTIME    (0x1U)
/* The macro definition that erases module postbuild */
#define MODULE_VARIANT_POSTBUILD   (0x2U)

#if defined(UINT32_MAX)
#undef UINT32_MAX
#define UINT32_MAX 0xFFFFFFFF
#else
#define UINT32_MAX 0xFFFFFFFF
#endif

/* Halt the processor in the debug state*/
LOCAL_INLINE void TT_HALT(void)
{
#ifndef _VCAST_MINGW_C
    ASM_KEYWORD("    bkpt    1");
#endif
}

/*******************************************************************************
*  Data manipulation defines
*******************************************************************************/

#ifndef __IO
#ifdef __cplusplus 
/*!< Defines 'read only' permissions                 */
  #define   __I     volatile            
#else
/*!< Defines 'read only' permissions                 */
#define   __I     volatile TT_CONST       
#endif

/*!< Defines 'write only' permissions                */
#define     __O     volatile             
/*!< Defines 'read / write' permissions              */
#define     __IO    volatile             
#endif

/*!< Fallback for older CMSIS versions                                         */
#ifndef __IM                                    
  #define __IM   __I
#endif
/*!< Fallback for older CMSIS versions                                         */
#ifndef __OM                                    
  #define __OM   __O
#endif
/*!< Fallback for older CMSIS versions                                         */
#ifndef __IOM                                  
  #define __IOM  __IO
#endif
/* Macro definition of a BIT value */
#ifndef BIT31
    #define BIT31   ((uint32)0x80000000UL)
#else
      #if (BIT31 != 0x80000000UL)
             #error "BIT31 is defined outside MCAL and it is value is not 0x80000000UL".
       #endif
#endif

#ifndef BIT30
    #define BIT30   ((uint32)0x40000000UL)
#else
      #if (BIT30 != 0x40000000UL)
             #error "BIT30 is defined outside MCAL and it is value is not 0x40000000UL".
       #endif
#endif

#ifndef BIT29
    #define BIT29   ((uint32)0x20000000UL)
#else
      #if (BIT29 != 0x20000000UL)
             #error "BIT29 is defined outside MCAL and it is value is not 0x20000000UL".
       #endif
#endif

#ifndef BIT28
    #define BIT28   ((uint32)0x10000000UL)
#else
      #if (BIT28 != 0x10000000UL)
             #error "BIT28 is defined outside MCAL and it is value is not 0x10000000UL".
       #endif
#endif

#ifndef BIT27
    #define BIT27   ((uint32)0x08000000UL)
#else
      #if (BIT27 != 0x08000000UL)
             #error "BIT27 is defined outside MCAL and it is value is not 0x08000000UL".
       #endif
#endif

#ifndef BIT26
    #define BIT26   ((uint32)0x04000000UL)
#else
      #if (BIT26 != 0x04000000UL)
             #error "BIT26 is defined outside MCAL and it is value is not 0x04000000UL".
       #endif
#endif

#ifndef BIT25
    #define BIT25   ((uint32)0x02000000UL)
#else
      #if (BIT25 != 0x02000000UL)
             #error "BIT25 is defined outside MCAL and it is value is not 0x02000000UL".
       #endif
#endif

#ifndef BIT24
    #define BIT24   ((uint32)0x01000000UL)
#else
      #if (BIT24 != 0x01000000UL)
             #error "BIT24 is defined outside MCAL and it is value is not 0x01000000UL".
       #endif
#endif

#ifndef BIT23
    #define BIT23   ((uint32)0x00800000UL)
#else
      #if (BIT23 != 0x00800000UL)
             #error "BIT23 is defined outside MCAL and it is value is not 0x00800000UL".
       #endif
#endif

#ifndef BIT22
    #define BIT22   ((uint32)0x00400000UL)
#else
      #if (BIT22 != 0x00400000UL)
             #error "BIT22 is defined outside MCAL and it is value is not 0x00400000UL".
       #endif
#endif

#ifndef BIT21
    #define BIT21   ((uint32)0x00200000UL)
#else
      #if (BIT21 != 0x00200000UL)
             #error "BIT21 is defined outside MCAL and it is value is not 0x00200000UL".
       #endif
#endif

#ifndef BIT20
    #define BIT20   ((uint32)0x00100000UL)
#else
      #if (BIT20 != 0x00100000UL)
             #error "BIT20 is defined outside MCAL and it is value is not 0x00100000UL".
       #endif
#endif

#ifndef BIT19
    #define BIT19   ((uint32)0x00080000UL)
#else
      #if (BIT19 != 0x00080000UL)
             #error "BIT19 is defined outside MCAL and it is value is not 0x00080000UL".
       #endif
#endif

#ifndef BIT18
    #define BIT18   ((uint32)0x00040000UL)
#else
      #if (BIT18 != 0x00040000UL)
             #error "BIT18 is defined outside MCAL and it is value is not 0x00040000UL".
       #endif
#endif

#ifndef BIT17
    #define BIT17   ((uint32)0x00020000UL)
#else
      #if (BIT17 != 0x00020000UL)
             #error "BIT17 is defined outside MCAL and it is value is not 0x00020000UL".
       #endif
#endif

#ifndef BIT16
    #define BIT16   ((uint32)0x00010000UL)
#else
      #if (BIT16 != 0x00010000UL)
             #error "BIT16 is defined outside MCAL and it is value is not 0x00010000UL".
       #endif
#endif

#ifndef BIT15
    #define BIT15   ((uint32)0x00008000UL)
#else
      #if (BIT15 != 0x00008000UL)
             #error "BIT15 is defined outside MCAL and it is value is not 0x00008000UL".
       #endif
#endif

#ifndef BIT14
    #define BIT14   ((uint32)0x00004000UL)
#else
      #if (BIT14 != 0x00004000UL)
             #error "BIT14 is defined outside MCAL and it is value is not 0x00004000UL".
       #endif
#endif

#ifndef BIT13
    #define BIT13   ((uint32)0x00002000UL)
#else
      #if (BIT13 != 0x00002000UL)
             #error "BIT13 is defined outside MCAL and it is value is not 0x00002000UL".
       #endif
#endif

#ifndef BIT12
    #define BIT12   ((uint32)0x00001000UL)
#else
      #if (BIT12 != 0x00001000UL)
             #error "BIT12 is defined outside MCAL and it is value is not 0x00001000UL".
       #endif
#endif

#ifndef BIT11
    #define BIT11   ((uint32)0x00000800UL)
#else
      #if (BIT11 != 0x00000800UL)
             #error "BIT11 is defined outside MCAL and it is value is not 0x00000800UL".
       #endif
#endif

#ifndef BIT10
    #define BIT10   ((uint32)0x00000400UL)
#else
      #if (BIT10 != 0x00000400UL)
             #error "BIT10 is defined outside MCAL and it is value is not 0x00000400UL".
       #endif
#endif

#ifndef BIT9
    #define BIT9    ((uint32)0x00000200UL)
#else
      #if (BIT9 != 0x00000200UL)
             #error "BIT9 is defined outside MCAL and it is value is not 0x00000200UL".
       #endif
#endif

#ifndef BIT8
    #define BIT8    ((uint32)0x00000100UL)
#else
      #if (BIT8 != 0x00000100UL)
             #error "BIT8 is defined outside MCAL and it is value is not 0x00000100UL ".
       #endif
#endif

#ifndef BIT7
    #define BIT7    ((uint32)0x00000080UL)
#else
      #if (BIT7 != 0x00000080UL)
             #error "BIT7 is defined outside MCAL and it is value is not 0x00000080UL".
       #endif
#endif

#ifndef BIT6
    #define BIT6    ((uint32)0x00000040UL)
#else
      #if (BIT6 != 0x00000040UL)
             #error "BIT6 is defined outside MCAL and it is value is not 0x00000040UL".
       #endif
#endif

#ifndef BIT5
    #define BIT5    ((uint32)0x00000020UL)
#else
      #if (BIT5 != 0x00000020UL)
             #error "BIT5 is defined outside MCAL and it is value is not 0x00000020UL".
       #endif
#endif

#ifndef BIT4
    #define BIT4    ((uint32)0x00000010UL)
#else
      #if (BIT4 != 0x00000010UL)
             #error "BIT4 is defined outside MCAL and it is value is not 0x00000010UL".
       #endif
#endif

#ifndef BIT3
    #define BIT3    ((uint32)0x00000008UL)
#else
      #if (BIT3 != 0x00000008UL)
             #error "BIT3 is defined outside MCAL and it is value is not 0x00000008UL".
       #endif
#endif

#ifndef BIT2
    #define BIT2    ((uint32)0x00000004UL)
#else
      #if (BIT2 != 0x00000004UL)
             #error "BIT2 is defined outside MCAL and it is value is not 0x00000004UL".
       #endif
#endif

#ifndef BIT1
    #define BIT1    ((uint32)0x00000002UL)
#else
      #if (BIT1 != 0x00000002UL)
             #error "BIT1 is defined outside MCAL and it is value is not 0x00000002UL".
       #endif
#endif

#ifndef BIT0
    #define BIT0    ((uint32)0x00000001UL)
#else
      #if (BIT0 != 0x00000001UL)
             #error "BIT0 is defined outside MCAL and it is value is not 0x00000001UL".
       #endif
#endif

/** Get the lower 8 bits of a 16-bit value. */
#define TT_LO8(x)               ((uint8_t) ((x) & 0xFFU))

/** Get the upper 8 bits of a 16-bit value. */
#define TT_HI8(x)               ((uint8_t) ((uint16_t)(x) >> 8U))

/** Get the lower 16 bits of a 32-bit value. */
#define TT_LO16(x)              ((uint16_t) ((x) & 0xFFFFU))
/** Get the upper 16 bits of a 32-bit value. */
#define TT_HI16(x)              ((uint16_t) ((uint32_t)(x) >> 16U))

/** Swap the byte ordering of a 16-bit value */
#define TT_SWAP_ENDIAN16(x)     ((uint16_t)(((x) << 8U) | (((x) >> 8U) & 0x00FFU)))

/** Swap the byte ordering of a 32-bit value */
#define TT_SWAP_ENDIAN32(x)     ((uint32_t)((((x) >> 24U) & 0x000000FFU) | (((x) & 0x00FF0000U) >> 8U) | \
                                (((x) & 0x0000FF00U) << 8U) | ((x) << 24U)))

/** Swap the byte ordering of a 64-bit value */
#define TT_SWAP_ENDIAN64(x)     ((uint64_t) (((uint64_t) TT_SWAP_ENDIAN32((uint32_t)(x)) << 32U) | \
                                TT_SWAP_ENDIAN32((uint32_t)((x) >> 32U))))

/*******************************************************************************
* Macro Name: TT_GET_REG8(addr)
****************************************************************************//**
*
* Reads the 8-bit value from the specified address. This function can't be
* used to access the Core register, otherwise a fault occurs.
*
* \param addr  The register address.
*
* \return The read value.
*
*******************************************************************************/
#define TT_GET_REG8(addr)           (*((TT_CONST volatile uint8_t *)(addr)))

/*******************************************************************************
* Macro Name: TT_SET_REG8(addr, value)
****************************************************************************//**
*
* Writes an 8-bit value to the specified address. This function can't be
* used to access the Core register, otherwise a fault occurs.
*
* \param addr  The register address.
*
* \param value The value to write.
*
*******************************************************************************/
#define TT_SET_REG8(addr, value)    (*((volatile uint8_t *)(addr)) = (uint8_t)(value))

/*******************************************************************************
* Macro Name: TT_GET_REG16(addr)
****************************************************************************//**
*
* Reads the 16-bit value from the specified address.
*
* \param addr  The register address.
*
* \return The read value.
*
*******************************************************************************/
#define TT_GET_REG16(addr)          (*((TT_CONST volatile uint16_t *)(addr)))

/*******************************************************************************
* Macro Name: TT_SET_REG16(addr, value)
****************************************************************************//**
*
* Writes the 16-bit value to the specified address.
*
* \param addr  The register address.
*
* \param value The value to write.
*
*******************************************************************************/
#define TT_SET_REG16(addr, value)   (*((volatile uint16_t *)(addr)) = (uint16_t)(value))

/*******************************************************************************
* Macro Name: TT_GET_REG24(addr)
****************************************************************************//**
*
* Reads the 24-bit value from the specified address.
*
* \param addr  The register address.
*
* \return The read value.
*
*******************************************************************************/
#define TT_GET_REG24(addr)          (((uint32_t) (*((TT_CONST volatile uint8_t *)(addr)))) | \
                                    (((uint32_t) (*((TT_CONST volatile uint8_t *)(addr) + 1))) << 8U) | \
                                    (((uint32_t) (*((TT_CONST volatile uint8_t *)(addr) + 2))) << 16U))

/*******************************************************************************
* Macro Name: TT_SET_REG24(addr, value)
****************************************************************************//**
*
* Writes the 24-bit value to the specified address.
*
* \param addr  The register address.
*
* \param value The value to write.
*
*******************************************************************************/
#define TT_SET_REG24(addr, value)   do  \
                                    {   \
                                        (*((volatile uint8_t *) (addr))) = (uint8_t)(value);                \
                                        (*((volatile uint8_t *) (addr) + 1)) = (uint8_t)((value) >> 8U);    \
                                        (*((volatile uint8_t *) (addr) + 2)) = (uint8_t)((value) >> 16U);   \
                                    }   \
                                    while(0)

/*******************************************************************************
* Macro Name: TT_GET_REG32(addr)
****************************************************************************//**
*
* Reads the 32-bit value from the specified register. The address is the little
* endian order (LSB in lowest address).
*
* \param addr  The register address.
*
* \return The read value.
*
*******************************************************************************/
#define TT_GET_REG32(addr)          (*((TT_CONST volatile uint32_t *)(addr)))

/*******************************************************************************
* Macro Name: TT_SET_REG32(addr, value)
****************************************************************************//**
*
* Writes the 32-bit value to the specified register. The address is the little
* endian order (LSB in lowest address).
*
* \param addr  The register address.
*
* \param value The value to write.
*
*******************************************************************************/
#define TT_SET_REG32(addr, value)   (*((volatile uint32_t *)(addr)) = (uint32_t)(value))

/**
  \brief   Mask and shift a bit field value for use in a register bit range.
  \param[in] field  Name of the register bit field.
  \param[in] value  Value of the bit field. This parameter is interpreted as an uint32_t type.
  \return           Masked and shifted value.
*/
#define TT_VAL2FLD(field, value)    (((uint32_t)(value) << field ## _Pos) & (uint32_t)field ## _Msk)

/**
  \brief     Mask and shift a register value to extract a bit filed value.
  \param[in] field  Name of the register bit field.
  \param[in] value  Value of register. This parameter is interpreted as an uint32_t type.
  \return           Masked and shifted bit field value.
*/
#define TT_FLD2VAL(field, value)    (((uint32_t)(value) & (uint32_t)field ## _Msk) >> field ## _Pos)

/*******************************************************************************
* Macro Name: TT_CLR_SET_FLD32U
****************************************************************************//**
*
*  The macro for setting a register with a name field and value for providing
*  get-clear-modify-write operations.
*  Returns a resulting value to be assigned to the register.
*
*******************************************************************************/
#define TT_CLR_SET_FLD32U(reg, field, value) (((reg) & ((uint32_t)(~(field ## _Msk)))) | (TT_VAL2FLD(field, value)))

/*******************************************************************************
* Macro Name: TT_REG32_CLR_SET
****************************************************************************//**
*
*  Uses TT_CLR_SET_FLD32U macro for providing get-clear-modify-write
*  operations with a name field and value and writes a resulting value
*  to the 32-bit register.
*
*******************************************************************************/
#define TT_REG32_CLR_SET(reg, field, value) ((reg) = TT_CLR_SET_FLD32U((reg), field, (value)))

#define TT_REG32_GET_FLD(reg, field) (((reg) & (uint32_t)field ## _Msk) >> field ## _Pos)

/*******************************************************************************
* Macro Name: TT_CLR_SET_FLD16U
****************************************************************************//**
*
*  The macro for setting a 16-bit register with a name field and value for providing
*  get-clear-modify-write operations.
*  Returns a resulting value to be assigned to the 16-bit register.
*
*******************************************************************************/
#define TT_CLR_SET_FLD16U(reg, field, value) ((uint16_t)(((reg) & ((uint16_t)(~(field ## _Msk)))) |   \
                                                       ((uint16_t)TT_VAL2FLD(field, value))))

/*******************************************************************************
* Macro Name: TT_REG16_CLR_SET
****************************************************************************//**
*
*  Uses TT_CLR_SET_FLD16U macro for providing get-clear-modify-write
*  operations with a name field and value and writes a resulting value
*  to the 16-bit register.
*
*******************************************************************************/
#define TT_REG16_CLR_SET(reg, field, value) ((reg) = TT_CLR_SET_FLD16U((reg), field, (value)))

/*******************************************************************************
* Macro Name: TT_CLR_SET_FLD8U
****************************************************************************//**
*
*  The macro for setting a 8-bit register with a name field and value for providing
*  get-clear-modify-write operations.
*  Returns a resulting value to be assigned to the 8-bit register.
*
*******************************************************************************/
#define TT_CLR_SET_FLD8U(reg, field, value) ((uint8_t)(((reg) & ((uint8_t)(~(field ## _Msk)))) |  \
                                                     ((uint8_t)TT_VAL2FLD(field, value))))
/*******************************************************************************
* Macro Name: TT_REG8_CLR_SET
****************************************************************************//**
*
*  Uses TT_CLR_SET_FLD8U macro for providing get-clear-modify-write
*  operations with a name field and value and writes a resulting value
*  to the 8-bit register.
*
*******************************************************************************/
#define TT_REG8_CLR_SET(reg, field, value) ((reg) = TT_CLR_SET_FLD8U((reg), field, (value)))

/*******************************************************************************
* Macro Name: _BOOL2FLD
****************************************************************************//**
*
*  Returns a field mask if the value is not false.
*  Returns 0, if the value is false.
*
*******************************************************************************/
#define TT_BOOL2FLD(field, value) (((value) != FALSE) ? (field ## _Msk) : 0UL)

/*******************************************************************************
* Macro Name: _FLD2BOOL
****************************************************************************//**
*
*  Returns true, if the value includes the field mask.
*  Returns false, if the value doesn't include the field mask.
*
*******************************************************************************/
#define TT_FLD2BOOL(field, value) (((value) & (field ## _Msk)) != 0UL)

/*******************************************************************************
* Macro Name: TT_SYSLIB_DIV_ROUND
****************************************************************************//**
*
*  Calculates a / b with rounding to the nearest integer,
*  a and b must have the same sign.
*
*******************************************************************************/
#define TT_SYSLIB_DIV_ROUND(a, b) (((a) + ((b) / 2U)) / (b))

/*******************************************************************************
* Macro Name: TT_SYSLIB_DIV_ROUNDUP
****************************************************************************//**
*
*  Calculates a / b with rounding up if remainder != 0,
*  both a and b must be positive.
*
*******************************************************************************/
#define TT_SYSLIB_DIV_ROUNDUP(a, b) ((((a) - 1U) / (b)) + 1U)

/**
* @brief 8 bits memory write macro
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_WRITE8(address, value)        ((*(volatile uint8*)(address))=  (value))
/**
* @brief 16 bits memory write macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_WRITE16(address, value)       ((*(volatile uint16*)(address))= (value))
/**
* @brief 32 bits memory write macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_WRITE32(address, value)       ((*(volatile uint32*)(address))= (value))

/**
* @brief 8 bits memory read macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_READ8(address)                (*(volatile uint8*)(address))
/**
* @brief 16 bits memory read macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_READ16(address)               (*(volatile uint16*)(address))
/**
* @brief 32 bits memory read macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_READ32(address)               (*(volatile uint32*)(address))

/**
* @brief 8 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AWRITE8(address, i, value)     (REG_WRITE8 ((address)+(i), (value)))
/**
* @brief 16 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AWRITE16(address, i, value)    (REG_WRITE16((address)+((uint32)((i)<<1U)), (value)))
/**
* @brief 32 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AWRITE32(address, i, value)    (REG_WRITE32((address)+((uint32)((i)<<2U)), (value)))

/**
* @brief 8 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AREAD8(address, i )            (REG_READ8 ((address)+(i)))
/**
* @brief 16 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AREAD16(address, i)            (REG_READ16((address)+((uint32)((i)<<1U))))
/**
* @brief 32 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AREAD32(address, i)            (REG_READ32((address)+((uint32)((i)<<2U))))

/**
* @brief 8 bits bits clearing macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_CLEAR8(address, mask)     ((*(volatile uint8*)(address))&= (~(mask)))
/**
* @brief 16 bits bits clearing macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_CLEAR16(address, mask)    ((*(volatile uint16*)(address))&= (~(mask)))
/**
* @brief 32 bits bits clearing macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32*)(address))&= (~(mask)))

/**
* @brief 8 bits bits getting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_GET8(address, mask)       ((*(volatile uint8*)(address))& (mask))
/**
* @brief 16 bits bits getting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_GET16(address, mask)      ((*(volatile uint16*)(address))& (mask))
/**
* @brief 32 bits bits getting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_GET32(address, mask)      ((*(volatile uint32*)(address))& (mask))

/**
* @brief 8 bits bits setting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_SET8(address, mask)       ((*(volatile uint8*)(address))|= (mask))
/**
* @brief 16 bits bits setting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_SET16(address, mask)      ((*(volatile uint16*)(address))|= (mask))
/**
* @brief 32 bits bits setting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_SET32(address, mask)      ((*(volatile uint32*)(address))|= (mask))

/**
* @brief 8 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_RMW8(address, mask, value)    (REG_WRITE8((address), ((REG_READ8(address)& ((uint8)~(mask)))| (value))))
/**
* @brief 16 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_RMW16(address, mask, value)   (REG_WRITE16((address), ((REG_READ16(address)& ((uint16)~(mask)))| (value))))
/**
* @brief 32 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32)~(mask)))| (value))))

/**
* @brief 32 bits memory read macro.
*/
#if !defined(REG_READ32)
  #define REG_READ32(address)               (*(volatile uint32_t*)(address))
#endif

/**
* @brief 32 bits memory write macro.
*/
#if !defined(REG_WRITE32)
  #define REG_WRITE32(address, value)       ((*(volatile uint32_t*)(address))= (uint32_t)(value))
#endif

/**
* @brief 32 bits bits setting macro.
*/
#if !defined(REG_BIT_SET32)
  #define REG_BIT_SET32(address, mask)      ((*(volatile uint32_t*)(address))|= (uint32_t)(mask))
#endif

/**
* @brief 32 bits bits clearing macro.
*/
#if !defined(REG_BIT_CLEAR32)
  #define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32_t*)(address))&= ((uint32_t)~((uint32_t)(mask))))
#endif

/**
* @brief 32 bit clear bits and set with new value
* @note It is user's responsability to make sure that value has only "mask" bits set - (value&~mask)==0
*/
#if !defined(REG_RMW32)
  #define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32_t)~((uint32_t)(mask))))| ((uint32_t)(value)))))
#endif

/* bool assert*/
#define BASE_BOOL_ASSERT(expr)  (((expr) == TRUE) || ((expr) == FALSE))
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

#endif /* TT_INTERFACE_H */
