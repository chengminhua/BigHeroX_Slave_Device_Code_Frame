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
**  FILENAME     : Base_Tools.h                                               **
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
#ifndef BASE_TOOLS_H
#define BASE_TOOLS_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "TT.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_TOOLS_VENDOR_ID_H                     1541
#define BASE_TOOLS_MODULE_ID_H                     218
#define BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H      4
#define BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H      4
#define BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H      0
#define BASE_TOOLS_SW_MAJOR_VERSION_H              1
#define BASE_TOOLS_SW_MINOR_VERSION_H              1
#define BASE_TOOLS_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Tools.h and TT.h file version check */
#if (BASE_TOOLS_VENDOR_ID_H != TT_VENDOR_ID_H)
    #error "Base_Tools.h and TT.h have different vendor id"
#endif
#if ((BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H != TT_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H != TT_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H != TT_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Tools.h and TT.h are different"
#endif
#if ((BASE_TOOLS_SW_MAJOR_VERSION_H != TT_SW_MAJOR_VERSION_H) || \
     (BASE_TOOLS_SW_MINOR_VERSION_H != TT_SW_MINOR_VERSION_H) || \
     (BASE_TOOLS_SW_PATCH_VERSION_H != TT_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Tools.h and TT.h are different"
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

/* Base Tools Service IDs */
#define BASE_TOOLS_SI_MEMCPY                ((uint8)109U)
#define BASE_TOOLS_SI_MEMCMP                ((uint8)110U)
#define BASE_TOOLS_SI_MEMSET                ((uint8)111U)
#define BASE_TOOLS_SI_MEMCMPBYTE            ((uint8)112U)
#define BASE_TOOLS_SI_RESET_CRC             ((uint8)113U)
#define BASE_TOOLS_SI_ACCUMULATE_CRC        ((uint8)114U)

/**
* @brief          Size of data to be processeed by CRC.
*
* @implements     Fls_CrcDataSizeType_enumeration
*/
typedef enum
{
    /**
    * @brief crc 8 bits
    */
    CRC_8_BITS = 0,
    /**
    * @brief crc 16 bits
    */
    CRC_16_BITS
} CrcDataSizeType; 

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
#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
/******************************************************************************
*  Service name     : Base_MemCpy
*  Syntax           : uint32 Base_MemCpy(void * TT_CONST dest,
*                                       TT_CONST void * TT_CONST src,
*                                       TT_CONST uint32 n_bytes)
*  Service ID       : 109
*  Sync/Async       : Synchronous
*  Reentrancy       : no reentrant
*  Parameters (in)  : src   - Source address to copy from
*                     count - The number of bytes to copy
*  Parameters (out) : dest  - Destination address to copy to
*  Return value     : uint32
*  Description      : Copy memory values fast.
******************************************************************************/
extern uint32 Base_MemCpy(void * TT_CONST dest, TT_CONST void * TT_CONST src, TT_CONST uint32 n_bytes);
/******************************************************************************
*  Service name     : Base_MemCmp
*  Syntax           : uint32 Base_MemCmp(void * TT_CONST dest,
*                                TT_CONST void * TT_CONST src,
*                                TT_CONST uint32 n_bytes);
*  Service ID       : 110
*  Sync/Async       : Synchronous
*  Reentrancy       : no reentrant
*  Parameters (in)  : src       Compare Source address
*                     n_bytes   The number of bytes to compare
*                     dest      Compare Destination address
*  Parameters (out) : None
*  Return value     : uint32    the count of compare bytes.
*  Description      : Compare memory values fast.
******************************************************************************/
uint32 Base_MemCmp(void * TT_CONST dest, TT_CONST void * TT_CONST src, TT_CONST uint32 n_bytes);
/******************************************************************************
*  Service name     : Base_MemSet
*  Syntax           : uint32 Base_MemSet(void * TT_CONST dest,
*                     TT_CONST uint8 value,
*                     TT_CONST uint32 n_bytes);
*  Service ID       : 111
*  Sync/Async       : Synchronous
*  Reentrancy       : no reentrant
*  Parameters (in)  : count  Number of bytes
*                     value  Byte value to set
*  Parameters (out) : dest      dest  Destination address to copy to
*  Return value     : uint32    the count of set bytes
*  Description      : Set memory value fast
******************************************************************************/
extern uint32 Base_MemSet(void * TT_CONST dest, TT_CONST uint8 value, TT_CONST uint32 n_bytes);
/******************************************************************************
*  Service name     : Base_MemCmpByte
*  Syntax           : uint32 Base_MemCmpByte(void * TT_CONST dest,
*                                           TT_CONST uint8 value,
*                                           TT_CONST uint32 n_bytes);
*  Service ID       : 112
*  Sync/Async       : Synchronous
*  Reentrancy       : no reentrant
*  Parameters (in)  : n_bytes  compare Number of bytes
*                     value  compare value
*  Parameters (out) : dest  compare address
*  Return value     : uint32    the count of compare bytes
*  Description      : compare memory value fast.
******************************************************************************/
uint32 Base_MemCmpByte(void * TT_CONST dest, TT_CONST uint8 value, TT_CONST uint32 n_bytes);
/******************************************************************************
*  Service name     : Base_AccumulateCRC
*  Syntax           : void Base_AccumulateCRC(TT_CONST uint32 inputData,
*                                             uint32 *u32AccCRCremainder);
*  Service ID       : 113
*  Sync/Async       : Synchronous
*  Reentrancy       : no reentrant
*  Parameters (in)  : inputData  data to be CRC-ed
*  Parameters (out) : u32AccCRCremainder cumulative CRC calculation data
*  Return value     : None
*  Description      : Function to handle cumulative CRC calculation over input data.
******************************************************************************/
void Base_AccumulateCRC(TT_CONST uint32 inputData,uint32 *u32AccCRCremainder);
/******************************************************************************
*  Service name     : Base_FinalizeCRC
*  Syntax           : uint32 Base_FinalizeCRC( uint32 *u32AccCRCremainder );
*  Service ID       : 114
*  Sync/Async       : Synchronous
*  Reentrancy       : no reentrant
*  Parameters (in)  : None
*  Parameters (out) : u32AccCRCremainder cumulative CRC calculation data
*  Return value     : uint32  The final CRC checksum in the lower 16 bits.
*  Description      : Function to finalize CRC calculation.
******************************************************************************/
uint32 Base_FinalizeCRC( uint32 *u32AccCRCremainder );
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* BASE_TOOLS_H */
