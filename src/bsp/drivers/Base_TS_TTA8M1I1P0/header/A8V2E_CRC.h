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
#ifndef A8V2E_CRC_H
#define A8V2E_CRC_H
	
#ifdef __cplusplus
extern "C"{
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_CRC_VENDOR_ID_H                     1541
#define A8V2E_CRC_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_CRC_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_CRC_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_CRC_SW_MAJOR_VERSION_H              1
#define A8V2E_CRC_SW_MINOR_VERSION_H              1
#define A8V2E_CRC_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_CRC.h and TT_Common.h file version check */
#if (A8V2E_CRC_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_CRC.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_CRC_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_CRC_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_CRC_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_CRC.h and TT_Common.h are different"
#endif
#if ((A8V2E_CRC_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_CRC_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_CRC_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_CRC.h and TT_Common.h are different"
#endif


/* =========================================================================================================================== */
/* ================                                       TT_CRC                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief General Purpose CRC (CRC) 0 (TT_CRC)
  */

#define CRC_BASEADDR          0x400A4000UL
#define CRC_CNTRL_REG         (*((volatile uint32_t *)(CRC_BASEADDR+0x00)))
#define CRC_SELECT_REG        (*((volatile uint32_t *)(CRC_BASEADDR+0x04)))
#define CRC_DATA0_REG          (*((volatile uint32_t *)(CRC_BASEADDR+0x08)))
#define CRC_TRANSCOUN         (*((volatile uint32_t *)(CRC_BASEADDR+0x0C)))

#define CRC_DMA_READ          (*((volatile uint32_t *)(CRC_BASEADDR+0x10)))
#define CRC_DMA_START         (*((volatile uint32_t *)(CRC_BASEADDR+0x14)))
#define CRC_INT_EN            (*((volatile uint32_t *)(CRC_BASEADDR+0x18)))
#define CRC_INT_STATUS        (*((volatile uint32_t *)(CRC_BASEADDR+0x1C)))
#define CRC_INIT0_VALUE        (*((volatile uint32_t *)(CRC_BASEADDR+0x20)))
#define CRC_PRIVILEDGE        (*((volatile uint32_t *)(CRC_BASEADDR+0x24)))
#define CRC_DATA1_REG          (*((volatile uint32_t *)(CRC_BASEADDR+0x28)))
#define CRC_INIT1_VALUE        (*((volatile uint32_t *)(CRC_BASEADDR+0x2C)))

/* ======================================================  CRC_CNTRL_REG  ======================================================= */
#define CRC_CRC_CTRL_DATA_CTRL_Pos  (0UL)
#define CRC_CRC_CTRL_DATA_CTRL_Msk  (0x3UL)
#define CRC_CRC_CTRL_OUTPUT_CTRL_Pos (2UL)
#define CRC_CRC_CTRL_OUTPUT_CTRL_Msk (0xcUL)
#define CRC_CRC_CTRL_XOR_CTRL_Pos   (4UL)
#define CRC_CRC_CTRL_XOR_CTRL_Msk   (0x10UL)
#define CRC_CRC_CTRL_DMA_HSIZE_Pos  (7UL)
#define CRC_CRC_CTRL_DMA_HSIZE_Msk  (0x180UL)
#define CRC_CRC_CTRL_PRI_MODE_Pos   (9UL)
#define CRC_CRC_CTRL_PRI_MODE_Msk   (0x200UL)
/* ======================================================  CRC_SELECT  ======================================================= */
#define CRC_CRC_SELECT_CRC_SELECT_Pos (0UL)
#define CRC_CRC_SELECT_CRC_SELECT_Msk (0x7UL)
/* ====================================================  OUTPUT_CRC_DATA  ==================================================== */
#define CRC_OUTPUT_CRC_DATA_OUTPUT_CRC_DATA_Pos (0UL)
#define CRC_OUTPUT_CRC_DATA_OUTPUT_CRC_DATA_Msk (0xffffffffUL)
/* ====================================================  DMA_TRANS_COUNT  ==================================================== */
#define CRC_DMA_TRANS_COUNT_DMA_COUNT_Pos (0UL)
#define CRC_DMA_TRANS_COUNT_DMA_COUNT_Msk (0x7ffffUL)
/* =====================================================  DMA_READ_ADDR  ===================================================== */
#define CRC_DMA_READ_ADDR_READ_ADDR_Pos (0UL)
#define CRC_DMA_READ_ADDR_READ_ADDR_Msk (0xffffffffUL)
/* =======================================================  DMA_START  ======================================================= */
#define CRC_DMA_START_DMA_START_Pos (0UL)
#define CRC_DMA_START_DMA_START_Msk (0x1UL)
/* ========================================================  INT_EN  ========================================================= */
#define CRC_INT_EN_CALCULATION_OVER_EN_Pos (0UL)
#define CRC_INT_EN_CALCULATION_OVER_EN_Msk (0x1UL)
#define CRC_INT_EN_ERROR_EN_Pos     (1UL)
#define CRC_INT_EN_ERROR_EN_Msk     (0x2UL)
#define CRC_INT_EN_REG_ERROR_EN_Pos (2UL)
#define CRC_INT_EN_REG_ERROR_EN_Msk (0x4UL)
/* ======================================================  INT_STATUS  ======================================================= */
#define CRC_INT_STATUS_CALCULATION_OVER_Pos (0UL)
#define CRC_INT_STATUS_CALCULATION_OVER_Msk (0x1UL)
#define CRC_INT_STATUS_ERROR_Pos    (1UL)
#define CRC_INT_STATUS_ERROR_Msk    (0x2UL)
#define CRC_INT_STATUS_REG_ERROR_Pos (2UL)
#define CRC_INT_STATUS_REG_ERROR_Msk (0x4UL)
/* ======================================================  INIT_VALUE  ======================================================= */
#define CRC_INIT_VALUE_INIT_VALUE_Pos (0UL)
#define CRC_INIT_VALUE_INIT_VALUE_Msk (0xffffffffUL)
/* ======================================================  PRIVILEDGE  ======================================================= */
#define CRC_PRIVILEDGE_PRI_MASTER_Pos (0UL)
#define CRC_PRIVILEDGE_PRI_MASTER_Msk (0x1UL)
#define CRC_PRIVILEDGE_LOCK_EN_Pos  (1UL)
#define CRC_PRIVILEDGE_LOCK_EN_Msk  (0x2UL)

#ifdef __cplusplus
}
#endif

#endif /* A8V2E_CRC_H */
