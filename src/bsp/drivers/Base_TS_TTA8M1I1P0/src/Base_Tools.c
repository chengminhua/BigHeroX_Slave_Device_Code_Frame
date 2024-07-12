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
**  FILENAME     : Base_Tools.c                                               **
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
*                            Includes
******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Base_Tools.h"
#include "TT_DrvError.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_TOOLS_VENDOR_ID_C                     1541
#define BASE_TOOLS_MODULE_ID_C                     218
#define BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_C      4
#define BASE_TOOLS_AR_RELEASE_MINOR_VERSION_C      4
#define BASE_TOOLS_AR_RELEASE_PATCH_VERSION_C      0
#define BASE_TOOLS_SW_MAJOR_VERSION_C              1
#define BASE_TOOLS_SW_MINOR_VERSION_C              1
#define BASE_TOOLS_SW_PATCH_VERSION_C              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Tools.c and Base_Tools.h file version check */
#if (BASE_TOOLS_VENDOR_ID_C != BASE_TOOLS_VENDOR_ID_H)
    #error "Base_Tools.c and Base_Tools.h have different vendor id"
#endif
#if (BASE_TOOLS_MODULE_ID_C != BASE_TOOLS_MODULE_ID_H)
    #error "Base_Tools.c and Base_Tools.h have different module id"
#endif
#if ((BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TOOLS_AR_RELEASE_MINOR_VERSION_C != BASE_TOOLS_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TOOLS_AR_RELEASE_PATCH_VERSION_C != BASE_TOOLS_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Tools.c and Base_Tools.h are different"
#endif
#if ((BASE_TOOLS_SW_MAJOR_VERSION_C != BASE_TOOLS_SW_MAJOR_VERSION_H) || \
     (BASE_TOOLS_SW_MINOR_VERSION_C != BASE_TOOLS_SW_MINOR_VERSION_H) || \
     (BASE_TOOLS_SW_PATCH_VERSION_C != BASE_TOOLS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Tools.c and Base_Tools.h are different"
#endif

/* Base_Tools.c and TT_DrvError.h file version check */
#if (BASE_TOOLS_VENDOR_ID_C != TT_DRVERROR_VENDOR_ID_H)
    #error "Base_Tools.c and TT_DrvError.h have different vendor id"
#endif
#if ((BASE_TOOLS_AR_RELEASE_MAJOR_VERSION_C != TT_DRVERROR_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_TOOLS_AR_RELEASE_MINOR_VERSION_C != TT_DRVERROR_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_TOOLS_AR_RELEASE_PATCH_VERSION_C != TT_DRVERROR_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Tools.c and TT_DrvError.h are different"
#endif
#if ((BASE_TOOLS_SW_MAJOR_VERSION_C != TT_DRVERROR_SW_MAJOR_VERSION_H) || \
     (BASE_TOOLS_SW_MINOR_VERSION_C != TT_DRVERROR_SW_MINOR_VERSION_H) || \
     (BASE_TOOLS_SW_PATCH_VERSION_C != TT_DRVERROR_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Tools.c and TT_DrvError.h are different"
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
#define BASE_START_SEC_VAR_INIT_8
#include "Base_MemMap.h"

#if defined(TT_ERR_MSG)

uint8 TT_ModuleIdNameMap[256][10] =
{
        " ",         /*0  */
        " ",         /*1  */
        " ",         /*2  */
        " ",         /*3  */
        " ",         /*4  */
        " ",         /*5  */
        " ",         /*6  */
        " ",         /*7  */
        " ",         /*8  */
        " ",         /*9  */
        " ",         /*10 */
        " ",         /*11 */
        " ",         /*12 */
        " ",         /*13 */
        " ",         /*14 */
        " ",         /*15 */
        " ",         /*16 */
        " ",         /*17 */
        " ",         /*18 */
        " ",         /*19 */
        " ",         /*20 */
        " ",         /*21 */
        " ",         /*22 */
        " ",         /*23 */
        " ",         /*24 */
        " ",         /*25 */
        " ",         /*26 */
        " ",         /*27 */
        " ",         /*28 */
        " ",         /*29 */
        " ",         /*30 */
        " ",         /*31 */
        " ",         /*32 */
        " ",         /*33 */
        " ",         /*34 */
        " ",         /*35 */
        " ",         /*36 */
        " ",         /*37 */
        " ",         /*38 */
        " ",         /*39 */
        " ",         /*40 */
        " ",         /*41 */
        " ",         /*42 */
        " ",         /*43 */
        " ",         /*44 */
        " ",         /*45 */
        " ",         /*46 */
        " ",         /*47 */
        " ",         /*48 */
        " ",         /*49 */
        " ",         /*50 */
        " ",         /*51 */
        " ",         /*52 */
        " ",         /*53 */
        " ",         /*54 */
        " ",         /*55 */
        " ",         /*56 */
        " ",         /*57 */
        " ",         /*58 */
        " ",         /*59 */
        " ",         /*60 */
        " ",         /*61 */
        " ",         /*62 */
        " ",         /*63 */
        " ",         /*64 */
        " ",         /*65 */
        " ",         /*66 */
        " ",         /*67 */
        " ",         /*68 */
        " ",         /*69 */
        " ",         /*70 */
        " ",         /*71 */
        " ",         /*72 */
        " ",         /*73 */
        " ",         /*74 */
        " ",         /*75 */
        " ",         /*76 */
        " ",         /*77 */
        " ",         /*78 */
        " ",         /*79 */
        " ",         /*80 */
        " ",         /*81 */
        " ",         /*82 */
        "Spi",       /*83 */
        "Can",       /*84 */
        " ",         /*85 */
        " ",         /*86 */
        " ",         /*87 */
        " ",         /*88 */
        " ",         /*89 */
        " ",         /*90 */
        " ",         /*91 */
        " ",         /*92 */
        "Ram",       /*93 */
        " ",         /*94 */
        " ",         /*95 */
        " ",         /*96 */
        " ",         /*97 */
        " ",         /*98 */
        " ",         /*99 */
        " ",         /*100*/
        "Mcu",       /*101*/
        "Wdg",       /*102*/
        " ",         /*103*/
        " ",         /*104*/
        " ",         /*105*/
        " ",         /*106*/
        " ",         /*107*/
        " ",         /*108*/
        " ",         /*109*/
        " ",         /*110*/
        " ",         /*111*/
        " ",         /*112*/
        " ",         /*113*/
        " ",         /*114*/
        " ",         /*115*/
        " ",         /*116*/
        " ",         /*117*/
        " ",         /*118*/
        " ",         /*119*/
        " ",         /*120*/
        "Pwm",       /*121*/
        " ",         /*122*/
        " ",         /*123*/
        "Port",      /*124*/
        "Ocu",       /*125*/
        " ",         /*126*/
        " ",         /*127*/
        " ",         /*128*/
        " ",         /*129*/
        " ",         /*130*/
        " ",         /*131*/
        " ",         /*132*/
        " ",         /*133*/
        " ",         /*134*/
        " ",         /*135*/
        " ",         /*136*/
        " ",         /*137*/
        " ",         /*138*/
        " ",         /*139*/
        " ",         /*140*/
        " ",         /*141*/
        " ",         /*142*/
        " ",         /*143*/
        " ",         /*144*/
        " ",         /*145*/
        " ",         /*146*/
        " ",         /*147*/
        " ",         /*148*/
        " ",         /*149*/
        " ",         /*150*/
        " ",         /*151*/
        " ",         /*152*/
        " ",         /*153*/
        " ",         /*154*/
        " ",         /*155*/
        " ",         /*156*/
        " ",         /*157*/
        " ",         /*158*/
        " ",         /*159*/
        " ",         /*160*/
        " ",         /*161*/
        " ",         /*162*/
        " ",         /*163*/
        " ",         /*164*/
        " ",         /*165*/
        " ",         /*166*/
        " ",         /*167*/
        " ",         /*168*/
        " ",         /*169*/
        " ",         /*170*/
        " ",         /*171*/
        " ",         /*172*/
        " ",         /*173*/
        " ",         /*174*/
        " ",         /*175*/
        " ",         /*176*/
        " ",         /*177*/
        " ",         /*178*/
        " ",         /*179*/
        " ",         /*180*/
        " ",         /*181*/
        " ",         /*182*/
        " ",         /*183*/
        " ",         /*184*/
        " ",         /*185*/
        " ",         /*186*/
        " ",         /*187*/
        " ",         /*188*/
        " ",         /*189*/
        " ",         /*190*/
        " ",         /*191*/
        " ",         /*192*/
        " ",         /*193*/
        " ",         /*194*/
        " ",         /*195*/
        " ",         /*196*/
        " ",         /*197*/
        " ",         /*198*/
        " ",         /*199*/
        " ",         /*200*/
        "Crc",       /*201*/
        " ",         /*202*/
        " ",         /*203*/
        " ",         /*204*/
        " ",         /*205*/
        " ",         /*206*/
        " ",         /*207*/
        " ",         /*208*/
        " ",         /*209*/
        " ",         /*210*/
        " ",         /*211*/
        " ",         /*212*/
        " ",         /*213*/
        " ",         /*214*/
        " ",         /*215*/
        " ",         /*216*/
        " ",         /*217*/
        "Base",      /*218*/
        "Platform",  /*219*/
        "Dma",       /*220*/
        "Gtm",       /*221*/
        "I2c",       /*222*/
        "I3c",       /*223*/
        "Mcl",       /*224*/
        "Sai",       /*225*/
        "Sent",      /*226*/
        "Uart",      /*227*/
        "Stm",       /*228*/
        " ",         /*229*/
        " ",         /*230*/
        " ",         /*231*/
        " ",         /*232*/
        " ",         /*233*/
        "SafetyBase",/*234*/
        "AdcSensor", /*235*/
        "Eim",       /*236*/
        "Intm",      /*237*/
        "Iom",       /*238*/
        "Smu",       /*239*/
        "Stcu",      /*240*/
        " ",         /*241*/
        " ",         /*242*/
        " ",         /*243*/
        " ",         /*244*/
        " ",         /*245*/
        " ",         /*246*/
        " ",         /*247*/
        " ",         /*248*/
        " ",         /*249*/
        " ",         /*250*/
        " ",         /*251*/
        " ",         /*252*/
        " ",         /*253*/
        " ",         /*254*/
        " "          /*255*/
};

uint8 TT_StatusNameMap[256][40] =
{
        "TT_STATUS_SUCCESS",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        "TT_RET_STATUS_ERR",/* 0x10 */
        "TT_RET_STATUS_TIMEOUT_ERR",
        "TT_RET_STATUS_INIT_ERR",
        "TT_RET_STATUS_UNINIT_ERR",
        "TT_RET_STATUS_LOCKED_ERR",
        "TT_RET_STATUS_UNLOCKED_ERR",
        "TT_RET_STATUS_CLK_ERR",
        "TT_RET_STATUS_TRANSITION_ERR",
        "TT_RET_STATUS_PFLASH_SECURE",
        "TT_RET_STATUS_PFLASH_NO_SECURE",
        "TT_RET_STATUS_RESET_ERR",
        "TT_RET_STATUS_DMAC_ERR",
        "TT_RET_STATUS_DMAC_COMPLETE",
        "TT_RET_STATUS_INITCHECK_ERR",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        "TT_RET_PARAM_ERR", /* 0x30 */
        "TT_RET_PARAM_LEN_ERR",
        "TT_RET_PARAM_ENUM_ERR",
        "TT_RET_PARAM_NULL_PTR_ERR",
        "TT_RET_PARAM_INVALID_PTR_ERR",
        "TT_RET_PARAM_INVALID_DATA_ERR",
        "TT_RET_PARAM_ADDR_ERR",
        "TT_RET_PARAM_MODE_ERR",
        "TT_RET_PARAM_CONFIG_ERR",
        "TT_RET_PARAM_COUNT_ERR",
        "TT_RET_PARAM_INDEX_ERR",
        "TT_RET_PARAM_CHANNEL_ERR",
        "TT_RET_PARAM_TYPE_ERR",
        "TT_RET_PARAM_VALUE_ERR",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        "TT_RET_MEMORY_READ_ERR",
        "TT_RET_MEMORY_WRITE_ERR",
        "TT_RET_MEMORY_ERASE_ERR",
        "TT_RET_MEMORY_COMPARE_ERR",
        "TT_RET_MEMORY_BLANK_CHECK_ERR",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        "TT_RET_IO_JOB_ERR", /* 0x60 */
        "TT_RET_IO_SEQ_ERR",
        "TT_RET_IO_RX_ERR",
        "TT_RET_IO_TX_ERR",
        "TT_RET_IO_BUSY_ERR",
        "TT_RET_IO_DMA_ERR",
        "TT_RET_IO_ABORT_ERR",
        "TT_RET_IO_COMM_ERR",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        "TT_RET_CRYPT_KEY_INVALID_ERR",/*0x70*/
        "TT_RET_CRYPT_ALG_INVALID_ERR",
        "TT_RET_CRYPT_DATA_INVALID_ERR",
        "TT_RET_CRYPT_SIG_INVALID_ERR",
        "TT_RET_CRYPT_AUTH_FAIL_ERR",
        "TT_RET_CRYPT_RND_ERR",
        "TT_RET_CRYPT_ALREADY_DONE_ERR",
        "TT_RET_CRYPT_KEY_INACTIVE_ERR",
        "TT_RET_CRYPT_KEY_ELE_INVALID_ERR",
        "TT_RET_CRYPT_OPT_DENY_ERR",
        "TT_RET_CRYPT_CMD_INVALID_ERR",
        "TT_RET_CRYPT_FLASH_CHECK_ERR",
        "TT_RET_CRYPT_PIN_LOCK_ERR",
        "TT_RET_CRYPT_ACCESS_DENY_ERR",
        " ",
        " ",
        "TT_RET_OPT_MEM_ERR", /* 0x80 */
        "TT_RET_OPT_REG_ERR",
        "TT_RET_OPT_CALC_ERR",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        "TT_RET_MSG_CHECK_ERR", /* 0x90 */
        "TT_RET_VERSION_ERR",
        "TT_RET_UNSUPPORT_ERR",
        "TT_RET_SYSTEM_ERR",
        "TT_RET_NOT_FOUND_ERR",
        "TT_RET_FULL_ERR",
        "TT_RET_NOT_STARTED",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " ",
        " "
};
#endif
#define BASE_STOP_SEC_VAR_INIT_8
#include "Base_MemMap.h"
/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
/**
 * @brief        Function to perform CRC calculation over input 32-bit data.
 * @details      Process 32-bit data to 16-bit reminder.
 * @param[in]    DataSize  {CRC_8_BITS, CRC_16_BITS}
 * @param[out]   u32AccCRCremainder   CRC calculation num
 * @return       void
 * @pre          Can be called only from Base_AccumulateCRC().
 */

static void Base_PriUpdateCRCreminder(TT_CONST CrcDataSizeType DataSize,uint32 *u32AccCRCremainder);
/**
 * @brief        Copy memory values by half word.
 * @param[in]    dest  Destination address to copy to
 * @param[in]    cnt  The number of bytes to copy
 * @param[out]   src  Source address to copy from
 * @return       uint32
 * @retval       the count of copied half word
 */
static void Base_PriMemCpyByHalfWord(uint16 * dest, TT_CONST uint16 * src, uint32 cnt);

/**
 * @brief        Copy memory values by word.
 * @param[in]    dest  Destination address to copy to
 * @param[in]    cnt  The number of bytes to copy
 * @param[out]   src  Source address to copy from
 * @return       uint32
 * @retval       the count of copied word
 */
static void Base_PriMemCpyByWord(uint32 * dest, TT_CONST uint32 * src, uint32 cnt);

/**
 * @brief        Copy memory values by double word.
 * @param[in]    dest  Destination address to copy to
 * @param[in]    cnt  The number of bytes to copy
 * @param[out]   src  Source address to copy from
 * @return       uint32
 * @retval       the count of copied double word
 */
static void Base_PriMemCpyByDoubleWord(uint64 * dest, TT_CONST uint64 * src, uint32 cnt);

/**
 * @brief        Compare memory values by half word.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of half word to compare
 * @return       uint32
 * @retval       the count of compare half word
 */
static uint32 Base_PriCmp(uint8 *tmpDest, TT_CONST uint8 *tmpSrc, uint32 alignByte ,uint32 remind ,uint8 ineqFlag);
/**
 * @brief        Compare memory values by half word.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of half word to compare
 * @return       uint32
 * @retval       the count of compare half word
 */
static uint32 Base_PriCmpBy(uint8 *tmpDest, uint8 value ,uint32 remind);

/**
 * @brief        Compare memory values by half word.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of half word to compare
 * @return       uint32
 * @retval       the count of compare half word
 */
static uint32 Base_PriMemCmpByHalfWord(uint16 * dest, TT_CONST uint16 * src, uint32 cnt);

/**
 * @brief        Compare memory values by word.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of word to compare
 * @return       uint32
 * @retval       the count of compare word
 */
static uint32 Base_PriMemCmpByWord(uint32 * dest, TT_CONST uint32 * src, uint32 cnt);

/**
 * @brief        Compare memory values by double word.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of double word to compare
 * @return       uint32
 * @retval       the count of compare double word
 */
static uint32 Base_PriMemCmpByDoubleWord(uint64 * dest, TT_CONST uint64 * src, uint32 cnt);

/**
 * @brief        Get Align Bytes.
 * @param[in]    Tmp bytes
 * @return       uint32
 * @retval       the count of Align Bytes
 */
static uint32 Base_PriGetAlignBytes(uint32 Tmp);
/**
* @brief         Base_Tools_Check_PriRetCheck.
* @details       Base_Tools_Check_PriRetCheck
* @param[in]     ApiId - ServiceApiId -Service Id of API
* @param[out]    ErrId - Error Id of Conditionl
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Base_Tools_Check_PriRetCheck(uint32 ApiId, TT_RetType *ErrId);

/******************************************************************************
*                            Public Functions
*******************************************************************************/
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
uint32 Base_MemCpy(void * TT_CONST dest, TT_CONST void * TT_CONST src, TT_CONST uint32 n_bytes)
{
    uint8 *tmpDest = (uint8 *)dest;
    TT_CONST uint8 *tmpSrc = src;
    uint32 remind = n_bytes, u64Count = 0;
    uint32 alignByte = 0, Tmp = 0;
    TT_RetType     TTRetVal    = TT_RET_SUCCESS;
    if((dest != NULL_PTR) && (src != NULL_PTR))
    {
        Tmp = (((uint32)(uint32 *)dest) ^ ((uint32)src)) & 7U;

        if ((remind >= 8) && ((Tmp & 1UL) == 0UL))
        {
            alignByte = Base_PriGetAlignBytes(Tmp);
            while ((((uint32)tmpDest) & (alignByte - 1)) != 0U)
            {
                *tmpDest = *tmpSrc;
                tmpDest++;
                tmpSrc++;
                remind--;
            }

            if(remind >= alignByte)
            {
                u64Count = remind / alignByte;
                if(alignByte == 8)
                {
                    Base_PriMemCpyByDoubleWord((uint64 *)(uint32)tmpDest, (TT_CONST uint64 *)(uint32)tmpSrc, u64Count);
                }
                if(alignByte == 4)
                {
                    Base_PriMemCpyByWord((uint32 *)(uint32)tmpDest, (TT_CONST uint32 *)(uint32)tmpSrc, u64Count);
                }
                if(alignByte == 2)
                {
                    Base_PriMemCpyByHalfWord((uint16 *)(uint32)tmpDest, (TT_CONST uint16 *)(uint32)tmpSrc, u64Count);
                }
                remind &= (alignByte - 1);
                tmpDest += u64Count * alignByte;
                tmpSrc += u64Count * alignByte;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        /* if byte align, need ldrb/strb */
        while (remind > 0)
        {
            *tmpDest = *tmpSrc;
            tmpDest++;
            tmpSrc++;
            remind--;
        }
    }
    else
    {
        TTRetVal = TT_RET_PARAM_NULL_PTR_ERR;
        Base_Tools_Check_PriRetCheck(BASE_TOOLS_SI_MEMCPY,&TTRetVal);
    }

    return (n_bytes - remind);
}
/******************************************************************************
*  Service name     : Base_MemCmp
*  Syntax           : Base_MemCmp(void * TT_CONST dest,
*                                TT_CONST void * TT_CONST src,
*                                TT_CONST uint32 n_bytes);
*  Service ID       : 110
*  Sync/Async       : Synchronous
*  Reentrancy       : no reentrant
*  Parameters (in)  : src       Compare Source address
*                     n_bytes   The number of bytes to compare
*  Parameters (out) : dest      Compare Destination address
*  Return value     : uint32    the count of compare bytes.
*  Description      : Compare memory values fast.
******************************************************************************/
uint32 Base_MemCmp(void * TT_CONST dest, TT_CONST void * TT_CONST src, TT_CONST uint32 n_bytes)
{
    uint8 *tmpDest = (uint8 *)dest;
    TT_CONST uint8 *tmpSrc = src;
    uint32 remind = n_bytes;
    uint32 alignByte = 0, Tmp = 0;
    uint8 ineqFlag = 0U;
    uint32  u64Count = 0;
    TT_RetType     TTRetVal    = TT_RET_SUCCESS;
    if((dest != NULL_PTR) && (src != NULL_PTR))
    {
        Tmp = (((uint32)(uint32 *)dest) ^ ((uint32)src)) & 7U;
        if ((remind >= 8) && ((Tmp & 1UL) == 0UL))
        {
            alignByte = Base_PriGetAlignBytes(Tmp);
            while ((((uint32)tmpDest) & (alignByte - 1)) != 0U)
            {
                if(*tmpDest == *tmpSrc)
                {
                    tmpDest++;
                    tmpSrc++;
                    remind--;
                }
                else
                {
                    ineqFlag = 1;
                    break;
                }
            }
            u64Count= Base_PriCmp(tmpDest,tmpSrc,alignByte,remind,ineqFlag);
            remind &= (alignByte - 1);
            if(u64Count != 0)
            {
                ineqFlag = 1;
                remind += u64Count * alignByte;
            }
            else
            {
                tmpDest += u64Count * alignByte;
                tmpSrc += u64Count * alignByte;
            }
        }
        else
        {
            /* do nothing */
        }

        if(ineqFlag == 0)
        {
            /* if byte align, need ldrb/strb */
            while (remind > 0)
            {
                if(*tmpDest == *tmpSrc)
                {
                    tmpDest++;
                    tmpSrc++;
                    remind--;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        TTRetVal = TT_RET_PARAM_NULL_PTR_ERR;
        Base_Tools_Check_PriRetCheck(BASE_TOOLS_SI_MEMCMP,&TTRetVal);
    }

    return (n_bytes - remind);
}

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
uint32 Base_MemSet(void * TT_CONST dest, TT_CONST uint8 value, TT_CONST uint32 n_bytes)
{
    uint8 *tmpDest = dest;
    TT_CONST uint8   tmpValue8 = value;
    TT_CONST uint64  tmpValue64 = ((uint64)value << 56U) | ((uint64)value << 48U) | ((uint64)value << 40U) | ((uint64)value << 32U) | \
                                   ((uint64)value << 24U) | ((uint64)value << 16U) | ((uint64)value << 8U) | value;
    TT_RetType     TTRetVal    = TT_RET_SUCCESS;
    uint32 remind = n_bytes, u64Count = 0;

    if (dest != NULL_PTR)
    {
        /* if byte align, need ldrb/strb */
        if ((remind < 8))
        {
            while (remind > 0)
            {
                *tmpDest = tmpValue8;
                tmpDest++;
                remind--;
            }
        }
        else
        {
            while ((((uint32)tmpDest) & 7UL) != 0UL)
            {
                *tmpDest = tmpValue8;
                tmpDest++;
                remind--;
            }

            if(remind >= 8)
            {
                /* if Word align, ldrd/strd more fast */
                u64Count = remind >> 3;
                while(u64Count > 0)
                {
                    *(uint64 *)(uint32)tmpDest = tmpValue64;
                    tmpDest += 8;
                    u64Count--;
                }
                remind &= 7U;
            }
            else
            {
                /* do nothing */
            }

            while (remind > 0)
            {
                *tmpDest = tmpValue8;
                tmpDest++;
                remind--;
            }
        }
    }
    else
    {
        TTRetVal = TT_RET_PARAM_NULL_PTR_ERR;
        Base_Tools_Check_PriRetCheck(BASE_TOOLS_SI_MEMSET,&TTRetVal);
    }

    return (n_bytes - remind);
}
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
uint32 Base_MemCmpByte(void * TT_CONST dest, TT_CONST uint8 value, TT_CONST uint32 n_bytes)
{
    uint8 *tmpDest = dest;
    TT_CONST uint8   tmpValue8 = value;
    TT_RetType     TTRetVal    = TT_RET_SUCCESS;
    uint32 remind = n_bytes;

    if (dest != NULL_PTR)
    {
        /* if byte align, need ldrb/strb */
        if ((remind < 8))
        {
            while (remind > 0)
            {
                if(*tmpDest == tmpValue8)
                {
                    tmpDest++;
                    remind--;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            remind = Base_PriCmpBy(tmpDest,value,remind);
        }
    }
    else
    {
        TTRetVal = TT_RET_PARAM_NULL_PTR_ERR;
        Base_Tools_Check_PriRetCheck(BASE_TOOLS_SI_MEMCMPBYTE,&TTRetVal);
    }

    return (n_bytes - remind);
}

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
void Base_AccumulateCRC(TT_CONST uint32 inputData,uint32 *u32AccCRCremainder)
{
    if(u32AccCRCremainder != NULL_PTR)
    {
        if (0xFFFFU < inputData)
        {
            /* preparation for accumulation of higher 16 bits of the inputData */
            *u32AccCRCremainder = (*u32AccCRCremainder << 16U) | ((inputData) >> 16U);
            /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
            Base_PriUpdateCRCreminder(CRC_16_BITS,u32AccCRCremainder);
        }

        if (0xFFU < inputData)
        {
            /* preparation for accumulation of lower 16 bits of the inputData */
            *u32AccCRCremainder = (*u32AccCRCremainder << 16U) | (inputData & 0x0000FFFFU);
            /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
            Base_PriUpdateCRCreminder(CRC_16_BITS,u32AccCRCremainder);
        }
        else
        {
            /* optimization: only 8 LSB bits are processed */
            /* preparation for accumulation of lower 8 bits of the inputData */
            *u32AccCRCremainder = (*u32AccCRCremainder << 8U) | inputData;
            /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
            Base_PriUpdateCRCreminder(CRC_8_BITS,u32AccCRCremainder);
        }
    }
    

    return;
}

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
uint32 Base_FinalizeCRC( uint32 *u32AccCRCremainder )
{
    /* add the final 0x0000 to the remainder */
    *u32AccCRCremainder = (*u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */
    Base_PriUpdateCRCreminder(CRC_16_BITS,u32AccCRCremainder);

    return (*u32AccCRCremainder)^1U;
}
/******************************************************************************
*                       Private Function
******************************************************************************/

/**
 * @brief        Function to perform CRC calculation over input 32-bit data.
 * @details      Process 32-bit data to 16-bit reminder.
 * @param[in]    DataSize  {CRC_8_BITS, CRC_16_BITS}
 * @param[out]   u32AccCRCremainder   CRC calculation num
 * @return       void
 * @pre          Can be called only from Base_AccumulateCRC().
 */

static void Base_PriUpdateCRCreminder(TT_CONST CrcDataSizeType DataSize,uint32 *u32AccCRCremainder)
{
    uint32 CrcPolynomSft = 0U;
    uint32 LeadingOne = 0U;
    uint32 AccDataLoc = 0U;
    uint32 LeadingOneInitial = 0U;

    switch (DataSize)
    {
        case CRC_8_BITS:
            CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 7U;
            break;
        case CRC_16_BITS:
        default:
            CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    AccDataLoc = *u32AccCRCremainder;

    /* CRC computation */
    for (LeadingOne = LeadingOneInitial; LeadingOne >= 0x00010000U; LeadingOne >>= 1U)
    {
        if (0U != (AccDataLoc & LeadingOne))
        {
            AccDataLoc ^= CrcPolynomSft;
        }
        CrcPolynomSft >>= 1U;
    }

    /* copy back to static variable */
    *u32AccCRCremainder = AccDataLoc;

    return;
}

/**
 * @brief        Copy memory values by half word.
 * @param[in]    dest  Destination address to copy to
 * @param[in]    cnt  The number of bytes to copy
 * @param[out]   src  Source address to copy from
 * @return       uint32
 * @retval       the count of copied half word
 */
static void Base_PriMemCpyByHalfWord(uint16 * dest, TT_CONST uint16 * src, uint32 cnt)
{
    while(cnt > 0)
    {
        /* if half Word align, ldrh/strh more fast */
        *dest = *src;
        dest++;
        src++;
        cnt--;
    }
}
/**
 * @brief        Copy memory values by word.
 * @param[in]    dest  Destination address to copy to
 * @param[in]    cnt  The number of bytes to copy
 * @param[out]   src  Source address to copy from
 * @return       uint32
 * @retval       the count of copied word
 */
static void Base_PriMemCpyByWord(uint32 * dest, TT_CONST uint32 * src, uint32 cnt)
{
    while(cnt > 0)
    {
        /* if Word align, ldr/str more fast */
        *dest = *src;
        dest++;
        src++;
        cnt--;
    }
}
/**
 * @brief        Copy memory values by double word.
 * @param[in]    dest  Destination address to copy to
 * @param[in]    cnt  The number of bytes to copy
 * @param[out]   src  Source address to copy from
 * @return       uint32
 * @retval       the count of copied double word
 */
static void Base_PriMemCpyByDoubleWord(uint64 * dest, TT_CONST uint64 * src, uint32 cnt)
{
    while(cnt > 0)
    {
        /* if double Word align, ldrd/strd more fast */
        *dest = *src;
        dest++;
        src++;
        cnt--;
    }
}
/**
 * @brief        Compare memory values .
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of half word to compare
 * @return       uint32
 * @retval       the count of compare half word
 */
static uint32 Base_PriCmp(uint8 *tmpDest, TT_CONST uint8 *tmpSrc, uint32 alignByte ,uint32 remind ,uint8 ineqFlag)
{
    uint32  u64Count = 0;
    if((remind >= alignByte) && (0U == ineqFlag))
    {
        u64Count = remind / alignByte;
        if(alignByte == 8)
        {
            u64Count = Base_PriMemCmpByDoubleWord((uint64 *)(uint32)tmpDest, (TT_CONST uint64 *)(uint32)tmpSrc, u64Count);
        }
        else if(alignByte == 4)
        {
            u64Count = Base_PriMemCmpByWord((uint32 *)(uint32)tmpDest, (TT_CONST uint32 *)(uint32)tmpSrc, u64Count);
        }
        else
        {
            u64Count = Base_PriMemCmpByHalfWord((uint16 *)(uint32)tmpDest, (TT_CONST uint16 *)(uint32)tmpSrc, u64Count);
        }
    }
    else
    {
        /* do nothing */
    }
    return u64Count;
}
/**
 * @brief        Compare memory values.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of half word to compare
 * @return       uint32
 * @retval       the count of compare half word
 */
static uint32 Base_PriCmpBy(uint8 *tmpDest, uint8 value ,uint32 remind)
{
    TT_CONST uint8   tmpValue8 = value;
    uint8 ineqFlag = 0U;
    TT_CONST uint64  tmpValue64 = ((uint64)value << 56U) | ((uint64)value << 48U) | ((uint64)value << 40U) | ((uint64)value << 32U) | \
                                   ((uint64)value << 24U) | ((uint64)value << 16U) | ((uint64)value << 8U) | value;

    uint32 u64Count = 0;
    while ((((uint32)tmpDest) & 7UL) != 0UL)
    {
        if(*tmpDest == tmpValue8)
        {
            tmpDest++;
            remind--;
        }
        else
        {
            ineqFlag = 1;
            break;
        }
    }

    if((remind >= 8) && (0U == ineqFlag))
    {
        /* if Word align, ldrd/strd more fast */
        u64Count = remind >> 3;
        while(u64Count > 0)
                {
                    if(*(uint64 *)(uint32)tmpDest == tmpValue64)
                    {
                        tmpDest += 8;
                        u64Count--;
                    }
                    else
                    {
                        ineqFlag = 1;
                        break;
                    }
                }
        remind &= 7U;
        if(0U != ineqFlag)
        {
            remind += u64Count << 3;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    if(0U == ineqFlag)
    {
        while (remind > 0)
        {
            if(*tmpDest == tmpValue8)
            {
                tmpDest++;
                remind--;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        /* do nothing */
    }

    return remind;
}
/**
 * @brief        Compare memory values by half word.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of half word to compare
 * @return       uint32
 * @retval       the count of compare half word
 */
static uint32 Base_PriMemCmpByHalfWord(uint16 * dest, TT_CONST uint16 * src, uint32 cnt)
{
    while(cnt > 0)
    {
        /* if half Word align, ldrh more fast */
        if(*dest == *src)
        {
            dest++;
            src++;
            cnt--;
        }
        else
        {
            break;
        }
    }
    return cnt;
}

/**
 * @brief        Compare memory values by word.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of word to compare
 * @return       uint32
 * @retval       the count of compare word
 */
static uint32 Base_PriMemCmpByWord(uint32 * dest, TT_CONST uint32 * src, uint32 cnt)
{
    while(cnt > 0)
    {
        /* if Word align, ldr more fast */
        if(*dest == *src)
        {
            dest++;
            src++;
            cnt--;
        }
        else
        {
            break;
        }
    }
    return cnt;
}

/**
 * @brief        Compare memory values by double word.
 * @param[in]    dest   Compare Destination address
 * @param[in]    src  Compare Source address
 * @param[in]    n_bytes  The number of double word to compare
 * @return       uint32
 * @retval       the count of compare double word
 */
static uint32 Base_PriMemCmpByDoubleWord(uint64 * dest, TT_CONST uint64 * src, uint32 cnt)
{
    while(cnt > 0)
    {
        /* if double Word align, ldrd more fast */
        if(*dest == *src)
        {
            dest++;
            src++;
            cnt--;
        }
        else
        {
            break;
        }
    }
    return cnt;
}

/**
 * @brief        Get Align Bytes.
 * @param[in]    Tmp bytes
 * @return       uint32
 * @retval       the count of Align Bytes
 */
static uint32 Base_PriGetAlignBytes(uint32 Tmp)
{
    uint32 Ret = 0;

    if ((Tmp & 7U) == 0U)
    {
        Ret = 8U;
    }
    else if ((Tmp & 3U) == 0U)
    {
        Ret = 4U;
    }
    else
    {
        Ret = 2U;
    }

    return Ret;
}

/**
* @brief         Base_Tools_Check_PriRetCheck.
* @details       Base_Tools_Check_PriRetCheck
* @param[in]     ApiId - ServiceApiId -Service Id of API
* @param[out]    ErrId - Error Id of Conditionl
* @return        TT_RetType
* @retval        TT_RET_SUCCESS - success
                 Others - fail
* @pre
*/
LOCAL_INLINE void Base_Tools_Check_PriRetCheck(uint32 ApiId, TT_RetType *ErrId)
{
    if (NULL_PTR != ErrId)
    {
        if ((*ErrId != TT_RET_SUCCESS))
        {
            TT_DRV_REPORT_ERR(BASE_TOOLS_MODULE_ID_C, ApiId, *ErrId);
#if defined(BASE_DEV_ERROR_DETECT) && (BASE_DEV_ERROR_DETECT == STD_ON)
            ModuleDet_ReportError(BASE_MODULE_ID, BASE_INSTANCE_ID, ApiId, *ErrId);
            *ErrId = TT_SET_STATUS_TYPE(BASE_CHECK_TT_STATUS_DEFAULT(ApiId), *ErrId);
#endif
        }
        else
        {
            /* nothing */
        }
    }
    else
    {
        /* nothing */
    }

}

#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#ifdef __cplusplus
}
#endif
