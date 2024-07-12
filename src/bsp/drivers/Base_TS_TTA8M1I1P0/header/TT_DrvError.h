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
**  FILENAME     : TT_DrvError.h                                              **
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
#ifndef TT_DRVERROR_H
#define TT_DRVERROR_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#include "TT_PlatformTypes.h"
#include "TT_StandardTypes.h"

#if defined(UART0_PRINTF) || defined(UART1_PRINTF)
#include <stdio.h>
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_DRVERROR_VENDOR_ID_H                     1541
#define TT_DRVERROR_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_DRVERROR_AR_RELEASE_MINOR_VERSION_H      4
#define TT_DRVERROR_AR_RELEASE_PATCH_VERSION_H      0
#define TT_DRVERROR_SW_MAJOR_VERSION_H              1
#define TT_DRVERROR_SW_MINOR_VERSION_H              1
#define TT_DRVERROR_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* TT_DrvError.h and TT_PlatformTypes.h file version check */
#if (TT_DRVERROR_VENDOR_ID_H != TT_PLATFORM_TYPES_VENDOR_ID_H)
    #error "TT_DrvError.h and TT_PlatformTypes.h have different vendor id"
#endif
#if ((TT_DRVERROR_AR_RELEASE_MAJOR_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_DRVERROR_AR_RELEASE_MINOR_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_DRVERROR_AR_RELEASE_PATCH_VERSION_H != TT_PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_DrvError.h and TT_PlatformTypes.h are different"
#endif
#if ((TT_DRVERROR_SW_MAJOR_VERSION_H != TT_PLATFORM_TYPES_SW_MAJOR_VERSION_H) || \
     (TT_DRVERROR_SW_MINOR_VERSION_H != TT_PLATFORM_TYPES_SW_MINOR_VERSION_H) || \
     (TT_DRVERROR_SW_PATCH_VERSION_H != TT_PLATFORM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_DrvError.h and TT_PlatformTypes.h are different"
#endif

/* TT_DrvError.h and TT_StandardTypes.h file version check */
#if (TT_DRVERROR_VENDOR_ID_H != TT_STANDARD_TYPES_VENDOR_ID_H)
    #error "TT_DrvError.h and TT_StandardTypes.h have different vendor id"
#endif
#if ((TT_DRVERROR_AR_RELEASE_MAJOR_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_DRVERROR_AR_RELEASE_MINOR_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_DRVERROR_AR_RELEASE_PATCH_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_DrvError.h and TT_StandardTypes.h are different"
#endif
#if ((TT_DRVERROR_SW_MAJOR_VERSION_H != TT_STANDARD_TYPES_SW_MAJOR_VERSION_H) || \
     (TT_DRVERROR_SW_MINOR_VERSION_H != TT_STANDARD_TYPES_SW_MINOR_VERSION_H) || \
     (TT_DRVERROR_SW_PATCH_VERSION_H != TT_STANDARD_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_DrvError.h and TT_StandardTypes.h are different"
#endif

#if defined(TT_ERR_MSG)
extern uint8 TT_ModuleIdNameMap[256][10];
extern uint8 TT_StatusNameMap[256][40];
#endif

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
/* TT error code SUCCESS */
#define   TT_RET_SUCCESS                           (0x0U)

/* TT status error code */
#define   TT_RET_STATUS_ERR                        (0x10U)
#define   TT_RET_STATUS_TIMEOUT_ERR                (0x11U)
#define   TT_RET_STATUS_INIT_ERR                   (0x12U)
#define   TT_RET_STATUS_UNINIT_ERR                 (0x13U)
#define   TT_RET_STATUS_LOCKED_ERR                 (0x14U)
#define   TT_RET_STATUS_UNLOCKED_ERR               (0x15U)
#define   TT_RET_STATUS_CLK_ERR                    (0x16U)
#define   TT_RET_STATUS_TRANSITION_ERR             (0x17U)
#define   TT_RET_STATUS_PFLASH_SECURE              (0x18U)
#define   TT_RET_STATUS_PFLASH_NO_SECURE           (0x19U)
#define   TT_RET_STATUS_RESET_ERR                  (0x20U)
#define   TT_RET_STATUS_DMAC_ERR                   (0x21U)
#define   TT_RET_STATUS_DMAC_COMPLETE              (0x22U)
#define   TT_RET_STATUS_INITCHECK_ERR              (0x23U)

/* TT param error code */
#define   TT_RET_PARAM_ERR                         (0x30U)
#define   TT_RET_PARAM_LEN_ERR                     (0x31U)
#define   TT_RET_PARAM_ENUM_ERR                    (0x32U)
#define   TT_RET_PARAM_NULL_PTR_ERR                (0x33U)
#define   TT_RET_PARAM_INVALID_PTR_ERR             (0x34U)
#define   TT_RET_PARAM_INVALID_DATA_ERR            (0x35U)
#define   TT_RET_PARAM_ADDR_ERR                    (0x36U)
#define   TT_RET_PARAM_MODE_ERR                    (0x37U)
#define   TT_RET_PARAM_CONFIG_ERR                  (0x38U)
#define   TT_RET_PARAM_COUNT_ERR                   (0x39U)
#define   TT_RET_PARAM_INDEX_ERR                   (0x3AU)
#define   TT_RET_PARAM_CHANNEL_ERR                 (0x3BU)
#define   TT_RET_PARAM_TYPE_ERR                    (0x3CU)
#define   TT_RET_PARAM_VALUE_ERR                   (0x3DU)

/* TT memory error code */
#define   TT_RET_MEMORY_READ_ERR                   (0x50U)
#define   TT_RET_MEMORY_WRITE_ERR                  (0x51U)
#define   TT_RET_MEMORY_ERASE_ERR                  (0x52U)
#define   TT_RET_MEMORY_COMPARE_ERR                (0x53U)
#define   TT_RET_MEMORY_BLANK_CHECK_ERR            (0x54U)

/* TT io error code */
#define   TT_RET_IO_JOB_ERR                        (0x60U)
#define   TT_RET_IO_SEQ_ERR                        (0x61U)
#define   TT_RET_IO_RX_ERR                         (0x62U)
#define   TT_RET_IO_TX_ERR                         (0x63U)
#define   TT_RET_IO_BUSY_ERR                       (0x64U)
#define   TT_RET_IO_DMA_ERR                        (0x65U)
#define   TT_RET_IO_ABORT_ERR                      (0x66U)
#define   TT_RET_IO_COMM_ERR                       (0x67U)

/* TT crpypt error code */
#define   TT_RET_CRYPT_KEY_INVALID_ERR             (0x70U)
#define   TT_RET_CRYPT_ALG_INVALID_ERR             (0x71U)
#define   TT_RET_CRYPT_DATA_INVALID_ERR            (0x72U)
#define   TT_RET_CRYPT_SIG_INVALID_ERR             (0x73U)
#define   TT_RET_CRYPT_AUTH_FAIL_ERR               (0x74U)
#define   TT_RET_CRYPT_RND_ERR                     (0x75U)
#define   TT_RET_CRYPT_ALREADY_DONE_ERR            (0x76U)
#define   TT_RET_CRYPT_KEY_INACTIVE_ERR            (0x77U)
#define   TT_RET_CRYPT_KEY_ELE_INVALID_ERR         (0x78U)
#define   TT_RET_CRYPT_OPT_DENY_ERR                (0x79U)
#define   TT_RET_CRYPT_CMD_INVALID_ERR             (0x7AU)
#define   TT_RET_CRYPT_FLASH_CHECK_ERR             (0x7BU)
#define   TT_RET_CRYPT_PIN_LOCK_ERR                (0x7CU)
#define   TT_RET_CRYPT_ACCESS_DENY_ERR             (0x7DU)

/* TT opt error code */
#define   TT_RET_OPT_MEM_ERR                       (0x80U)
#define   TT_RET_OPT_REG_ERR                       (0x81U)
#define   TT_RET_OPT_CALC_ERR                      (0x82U)

/* TT error code */
#define   TT_RET_MSG_CHECK_ERR                     (0x90U)
#define   TT_RET_VERSION_ERR                       (0x91U)
#define   TT_RET_UNSUPPORT_ERR                     (0x92U)
#define   TT_RET_SYSTEM_ERR                        (0x93U)
#define   TT_RET_NOT_FOUND_ERR                     (0x94U)
#define   TT_RET_FULL_ERR		                   (0x95U)
#define   TT_RET_NOT_STARTED					   (0x96U)

/* TT status ID offset  */
#define TT_STATUSID_OFFSET          0U
/* TT Api ID offset */
#define TT_APIID_OFFSET             16U
/* TT module ID offset */
#define TT_MODULEID_OFFSET          24U
/* TT status ID mask */
#define TT_STATUSID_MSK             0xFFFFU
/* TT Api ID mask */
#define TT_APIID_MSK                0xFFU
/* TT module ID mask */
#define TT_MODULEID_MSK             0xFFU

/* TT get status Macros */
#define TT_GET_STATUS_TYPE(status)              (uint8)((status) & TT_STATUSID_MSK)
/* TT set status Macros */
#define TT_SET_STATUS_TYPE(status, id)          (TT_RetType)(((status) & ((uint32)~TT_STATUSID_MSK)) | (uint32)(id))
/* TT  status  */
#define TT_STATUS_TO_STDTYPE(status)            (((status)) ? E_NOT_OK : E_OK)

/* TT get status and module ID Macros */
#define TT_GET_STATUS_MODULEID(status)          (((status) >> TT_MODULEID_OFFSET) & TT_MODULEID_MSK)
/* TT get status and Api ID Macros */
#define TT_GET_STATUS_APIID(status)             (((status) >> TT_APIID_OFFSET) & TT_APIID_MSK)
/* TT get status and error ID Macros */
#define TT_GET_STATUS_ERRID(status)             (((status) >> TT_STATUSID_OFFSET) & TT_STATUSID_MSK)

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

#endif /* TT_DRVERROR_H */
