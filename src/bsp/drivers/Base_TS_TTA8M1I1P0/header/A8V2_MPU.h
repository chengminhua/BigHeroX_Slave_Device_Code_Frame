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

#ifndef A8V2_MPU_H
#define A8V2_MPU_H

#include "TT_Common.h"

#ifdef __cplusplus
 extern "C" {
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2_MPU_VENDOR_ID_H                     1541
#define A8V2_MPU_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2_MPU_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2_MPU_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2_MPU_SW_MAJOR_VERSION_H              1
#define A8V2_MPU_SW_MINOR_VERSION_H              1
#define A8V2_MPU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2_MPU.h and TT_Common.h file version check */
#if (A8V2_MPU_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2_MPU.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2_MPU_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2_MPU_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2_MPU_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2_MPU.h and TT_Common.h are different"
#endif
#if ((A8V2_MPU_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2_MPU_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2_MPU_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2_MPU.h and TT_Common.h are different"
#endif


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_MPU     Memory Protection Unit (MPU)
  \brief    Type definitions for the Memory Protection Unit (MPU)
  @{
 */

/**
  \brief  Structure type to access the Memory Protection Unit (MPU).
 */
typedef struct
{
  __IM  uint32 TYPE;                   /*!< Offset: 0x000 (R/ )  MPU Type Register */
  __IOM uint32 CTRL;                   /*!< Offset: 0x004 (R/W)  MPU Control Register */
  __IOM uint32 RNR;                    /*!< Offset: 0x008 (R/W)  MPU Region RNRber Register */
  __IOM uint32 RBAR;                   /*!< Offset: 0x00C (R/W)  MPU Region Base Address Register */
  __IOM uint32 RASR;                   /*!< Offset: 0x010 (R/W)  MPU Region Attribute and Size Register */
  __IOM uint32 RBAR_A1;                /*!< Offset: 0x014 (R/W)  MPU Alias 1 Region Base Address Register */
  __IOM uint32 RASR_A1;                /*!< Offset: 0x018 (R/W)  MPU Alias 1 Region Attribute and Size Register */
  __IOM uint32 RBAR_A2;                /*!< Offset: 0x01C (R/W)  MPU Alias 2 Region Base Address Register */
  __IOM uint32 RASR_A2;                /*!< Offset: 0x020 (R/W)  MPU Alias 2 Region Attribute and Size Register */
  __IOM uint32 RBAR_A3;                /*!< Offset: 0x024 (R/W)  MPU Alias 3 Region Base Address Register */
  __IOM uint32 RASR_A3;                /*!< Offset: 0x028 (R/W)  MPU Alias 3 Region Attribute and Size Register */
} MPU_RegType;

#define TT_MPU_TYPE_RALIASES                  (4U)

/* MPU Type Register Definitions */
#define TT_MPU_TYPE_IREGION_Pos               16U                                            /*!< MPU TYPE: IREGION Position */
#define TT_MPU_TYPE_IREGION_Msk               (0xFFUL << TT_MPU_TYPE_IREGION_Pos)               /*!< MPU TYPE: IREGION Mask */

#define TT_MPU_TYPE_DREGION_Pos                8U                                            /*!< MPU TYPE: DREGION Position */
#define TT_MPU_TYPE_DREGION_Msk               (0xFFUL << TT_MPU_TYPE_DREGION_Pos)               /*!< MPU TYPE: DREGION Mask */

#define TT_MPU_TYPE_SEPARATE_Pos               0U                                            /*!< MPU TYPE: SEPARATE Position */
#define TT_MPU_TYPE_SEPARATE_Msk              (1UL /*<< MPU_TYPE_SEPARATE_Pos*/)             /*!< MPU TYPE: SEPARATE Mask */

/* MPU Control Register Definitions */
#define TT_MPU_CTRL_PRIVDEFENA_Pos             2U                                            /*!< MPU CTRL: PRIVDEFENA Position */
#define TT_MPU_CTRL_PRIVDEFENA_Msk            (1UL << TT_MPU_CTRL_PRIVDEFENA_Pos)               /*!< MPU CTRL: PRIVDEFENA Mask */

#define TT_MPU_CTRL_HFNMIENA_Pos               1U                                            /*!< MPU CTRL: HFNMIENA Position */
#define TT_MPU_CTRL_HFNMIENA_Msk              (1UL << TT_MPU_CTRL_HFNMIENA_Pos)                 /*!< MPU CTRL: HFNMIENA Mask */

#define TT_MPU_CTRL_ENABLE_Pos                 0U                                            /*!< MPU CTRL: ENABLE Position */
#define TT_MPU_CTRL_ENABLE_Msk                (1UL /*<< MPU_CTRL_ENABLE_Pos*/)               /*!< MPU CTRL: ENABLE Mask */

/* MPU Region Number Register Definitions */
#define TT_MPU_RNR_REGION_Pos                  0U                                            /*!< MPU RNR: REGION Position */
#define TT_MPU_RNR_REGION_Msk                 (0xFFUL /*<< MPU_RNR_REGION_Pos*/)             /*!< MPU RNR: REGION Mask */

/* MPU Region Base Address Register Definitions */
#define TT_MPU_RBAR_ADDR_Pos                   5U                                            /*!< MPU RBAR: ADDR Position */
#define TT_MPU_RBAR_ADDR_Msk                  (0x7FFFFFFUL << TT_MPU_RBAR_ADDR_Pos)             /*!< MPU RBAR: ADDR Mask */

#define TT_MPU_RBAR_VALID_Pos                  4U                                            /*!< MPU RBAR: VALID Position */
#define TT_MPU_RBAR_VALID_Msk                 (1UL << TT_MPU_RBAR_VALID_Pos)                    /*!< MPU RBAR: VALID Mask */

#define TT_MPU_RBAR_REGION_Pos                 0U                                            /*!< MPU RBAR: REGION Position */
#define TT_MPU_RBAR_REGION_Msk                (0xFUL /*<< MPU_RBAR_REGION_Pos*/)             /*!< MPU RBAR: REGION Mask */

/* MPU Region Attribute and Size Register Definitions */
#define TT_MPU_RASR_ATTRS_Pos                 16U                                            /*!< MPU RASR: MPU Region Attribute field Position */
#define TT_MPU_RASR_ATTRS_Msk                 (0xFFFFUL << TT_MPU_RASR_ATTRS_Pos)               /*!< MPU RASR: MPU Region Attribute field Mask */

#define TT_MPU_RASR_XN_Pos                    28U                                            /*!< MPU RASR: ATTRS.XN Position */
#define TT_MPU_RASR_XN_Msk                    (1UL << TT_MPU_RASR_XN_Pos)                       /*!< MPU RASR: ATTRS.XN Mask */

#define TT_MPU_RASR_AP_Pos                    24U                                            /*!< MPU RASR: ATTRS.AP Position */
#define TT_MPU_RASR_AP_Msk                    (0x7UL << TT_MPU_RASR_AP_Pos)                     /*!< MPU RASR: ATTRS.AP Mask */

#define TT_MPU_RASR_TEX_Pos                   19U                                            /*!< MPU RASR: ATTRS.TEX Position */
#define TT_MPU_RASR_TEX_Msk                   (0x7UL << TT_MPU_RASR_TEX_Pos)                    /*!< MPU RASR: ATTRS.TEX Mask */

#define TT_MPU_RASR_S_Pos                     18U                                            /*!< MPU RASR: ATTRS.S Position */
#define TT_MPU_RASR_S_Msk                     (1UL << TT_MPU_RASR_S_Pos)                        /*!< MPU RASR: ATTRS.S Mask */

#define TT_MPU_RASR_C_Pos                     17U                                            /*!< MPU RASR: ATTRS.C Position */
#define TT_MPU_RASR_C_Msk                     (1UL << TT_MPU_RASR_C_Pos)                        /*!< MPU RASR: ATTRS.C Mask */

#define TT_MPU_RASR_B_Pos                     16U                                            /*!< MPU RASR: ATTRS.B Position */
#define TT_MPU_RASR_B_Msk                     (1UL << TT_MPU_RASR_B_Pos)                        /*!< MPU RASR: ATTRS.B Mask */

#define TT_MPU_RASR_SRD_Pos                    8U                                            /*!< MPU RASR: Sub-Region Disable Position */
#define TT_MPU_RASR_SRD_Msk                   (0xFFUL << TT_MPU_RASR_SRD_Pos)                   /*!< MPU RASR: Sub-Region Disable Mask */

#define TT_MPU_RASR_SIZE_Pos                   1U                                            /*!< MPU RASR: Region Size Field Position */
#define TT_MPU_RASR_SIZE_Msk                  (0x1FUL << TT_MPU_RASR_SIZE_Pos)                  /*!< MPU RASR: Region Size Field Mask */

#define TT_MPU_RASR_ENABLE_Pos                 0U                                            /*!< MPU RASR: Region enable bit Position */
#define TT_MPU_RASR_ENABLE_Msk                (1UL /*<< MPU_RASR_ENABLE_Pos*/)               /*!< MPU RASR: Region enable bit Disable Mask */

/* TYPE Bit Fields */
#define TT_MPU_TYPE_SEPARATE_MASK               0x1u
#define TT_MPU_TYPE_SEPARATE_SHIFT              0u
#define TT_MPU_TYPE_SEPARATE_WIDTH              1u
#define TT_MPU_TYPE_SEPARATE(x)                 (((uint32_t)(((uint32_t)(x))<<TT_MPU_TYPE_SEPARATE_SHIFT))&TT_MPU_TYPE_SEPARATE_MASK)
#define TT_MPU_TYPE_DREGION_MASK                0xFF00u
#define TT_MPU_TYPE_DREGION_SHIFT               8u
#define TT_MPU_TYPE_DREGION_WIDTH               8u
#define TT_MPU_TYPE_DREGION(x)                  (((uint32_t)(((uint32_t)(x))<<TT_MPU_TYPE_DREGION_SHIFT))&TT_MPU_TYPE_DREGION_MASK)
#define TT_MPU_TYPE_IREGION_MASK                0xFF0000u
#define TT_MPU_TYPE_IREGION_SHIFT               16u
#define TT_MPU_TYPE_IREGION_WIDTH               8u
#define TT_MPU_TYPE_IREGION(x)                  (((uint32_t)(((uint32_t)(x))<<TT_MPU_TYPE_IREGION_SHIFT))&TT_MPU_TYPE_IREGION_MASK)
/* CTRL Bit Fields */
#define TT_MPU_CTRL_ENABLE_MASK                 0x1u
#define TT_MPU_CTRL_ENABLE_SHIFT                0u
#define TT_MPU_CTRL_ENABLE_WIDTH                1u
#define TT_MPU_CTRL_ENABLE(x)                   (((uint32_t)(((uint32_t)(x))<<TT_MPU_CTRL_ENABLE_SHIFT))&TT_MPU_CTRL_ENABLE_MASK)
#define TT_MPU_CTRL_HFNMIENA_MASK               0x2u
#define TT_MPU_CTRL_HFNMIENA_SHIFT              1u
#define TT_MPU_CTRL_HFNMIENA_WIDTH              1u
#define TT_MPU_CTRL_HFNMIENA(x)                 (((uint32_t)(((uint32_t)(x))<<TT_MPU_CTRL_HFNMIENA_SHIFT))&TT_MPU_CTRL_HFNMIENA_MASK)
#define TT_MPU_CTRL_PRIVDEFENA_MASK             0x4u
#define TT_MPU_CTRL_PRIVDEFENA_SHIFT            2u
#define TT_MPU_CTRL_PRIVDEFENA_WIDTH            1u
#define TT_MPU_CTRL_PRIVDEFENA(x)               (((uint32_t)(((uint32_t)(x))<<TT_MPU_CTRL_PRIVDEFENA_SHIFT))&TT_MPU_CTRL_PRIVDEFENA_MASK)
/* RNR Bit Fields */
#define TT_MPU_RNR_REGION_MASK                  0xFFu
#define TT_MPU_RNR_REGION_SHIFT                 0u
#define TT_MPU_RNR_REGION_WIDTH                 8u
#define TT_MPU_RNR_REGION(x)                    (((uint32_t)(((uint32_t)(x))<<TT_MPU_RNR_REGION_SHIFT))&TT_MPU_RNR_REGION_MASK)
/* RBAR Bit Fields */
#define TT_MPU_RBAR_REGION_MASK                 0xFu
#define TT_MPU_RBAR_REGION_SHIFT                0u
#define TT_MPU_RBAR_REGION_WIDTH                4u
#define TT_MPU_RBAR_REGION(x)                   (((uint32_t)(((uint32_t)(x))<<TT_MPU_RBAR_REGION_SHIFT))&TT_MPU_RBAR_REGION_MASK)
#define TT_MPU_RBAR_VALID_MASK                  0x10u
#define TT_MPU_RBAR_VALID_SHIFT                 4u
#define TT_MPU_RBAR_VALID_WIDTH                 1u
#define TT_MPU_RBAR_VALID(x)                    (((uint32_t)(((uint32_t)(x))<<TT_MPU_RBAR_VALID_SHIFT))&TT_MPU_RBAR_VALID_MASK)
#define TT_MPU_RBAR_ADDR_MASK                   0xFFFFFFE0u
#define TT_MPU_RBAR_ADDR_SHIFT                  5u
#define TT_MPU_RBAR_ADDR_WIDTH                  27u
#define TT_MPU_RBAR_ADDR(x)                     (((uint32_t)(((uint32_t)(x))<<TT_MPU_RBAR_ADDR_SHIFT))&TT_MPU_RBAR_ADDR_MASK)
/* RASR Bit Fields */
#define TT_MPU_RASR_ENABLE_MASK                 0x1u
#define TT_MPU_RASR_ENABLE_SHIFT                0u
#define TT_MPU_RASR_ENABLE_WIDTH                1u
#define TT_MPU_RASR_ENABLE(x)                   (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_ENABLE_SHIFT))&TT_MPU_RASR_ENABLE_MASK)
#define TT_MPU_RASR_SIZE_MASK                   0x3Eu
#define TT_MPU_RASR_SIZE_SHIFT                  1u
#define TT_MPU_RASR_SIZE_WIDTH                  5u
#define TT_MPU_RASR_SIZE(x)                     (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_SIZE_SHIFT))&TT_MPU_RASR_SIZE_MASK)
#define TT_MPU_RASR_SRD_MASK                    0xFF00u
#define TT_MPU_RASR_SRD_SHIFT                   8u
#define TT_MPU_RASR_SRD_WIDTH                   8u
#define TT_MPU_RASR_SRD(x)                      (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_SRD_SHIFT))&TT_MPU_RASR_SRD_MASK)
#define TT_MPU_RASR_B_MASK                      0x10000u
#define TT_MPU_RASR_B_SHIFT                     16u
#define TT_MPU_RASR_B_WIDTH                     1u
#define TT_MPU_RASR_B(x)                        (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_B_SHIFT))&TT_MPU_RASR_B_MASK)
#define TT_MPU_RASR_C_MASK                      0x20000u
#define TT_MPU_RASR_C_SHIFT                     17u
#define TT_MPU_RASR_C_WIDTH                     1u
#define TT_MPU_RASR_C(x)                        (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_C_SHIFT))&TT_MPU_RASR_C_MASK)
#define TT_MPU_RASR_S_MASK                      0x40000u
#define TT_MPU_RASR_S_SHIFT                     18u
#define TT_MPU_RASR_S_WIDTH                     1u
#define TT_MPU_RASR_S(x)                        (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_S_SHIFT))&TT_MPU_RASR_S_MASK)
#define TT_MPU_RASR_TEX_MASK                    0x380000u
#define TT_MPU_RASR_TEX_SHIFT                   19u
#define TT_MPU_RASR_TEX_WIDTH                   3u
#define TT_MPU_RASR_TEX(x)                      (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_TEX_SHIFT))&TT_MPU_RASR_TEX_MASK)
#define TT_MPU_RASR_AP_MASK                     0x7000000u
#define TT_MPU_RASR_AP_SHIFT                    24u
#define TT_MPU_RASR_AP_WIDTH                    3u
#define TT_MPU_RASR_AP(x)                       (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_AP_SHIFT))&TT_MPU_RASR_AP_MASK)
#define TT_MPU_RASR_XN_MASK                     0x10000000u
#define TT_MPU_RASR_XN_SHIFT                    28u
#define TT_MPU_RASR_XN_WIDTH                    1u
#define TT_MPU_RASR_XN(x)                       (((uint32_t)(((uint32_t)(x))<<TT_MPU_RASR_XN_SHIFT))&TT_MPU_RASR_XN_MASK)
/* A_RBAR Bit Fields */
#define TT_MPU_A_RBAR_REGION_MASK               0xFu
#define TT_MPU_A_RBAR_REGION_SHIFT              0u
#define TT_MPU_A_RBAR_REGION_WIDTH              4u
#define TT_MPU_A_RBAR_REGION(x)                 (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RBAR_REGION_SHIFT))&TT_MPU_A_RBAR_REGION_MASK)
#define TT_MPU_A_RBAR_VALID_MASK                0x10u
#define TT_MPU_A_RBAR_VALID_SHIFT               4u
#define TT_MPU_A_RBAR_VALID_WIDTH               1u
#define TT_MPU_A_RBAR_VALID(x)                  (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RBAR_VALID_SHIFT))&TT_MPU_A_RBAR_VALID_MASK)
#define TT_MPU_A_RBAR_ADDR_MASK                 0xFFFFFFE0u
#define TT_MPU_A_RBAR_ADDR_SHIFT                5u
#define TT_MPU_A_RBAR_ADDR_WIDTH                27u
#define TT_MPU_A_RBAR_ADDR(x)                   (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RBAR_ADDR_SHIFT))&TT_MPU_A_RBAR_ADDR_MASK)
/* A_RASR Bit Fields */
#define TT_MPU_A_RASR_ENABLE_MASK               0x1u
#define TT_MPU_A_RASR_ENABLE_SHIFT              0u
#define TT_MPU_A_RASR_ENABLE_WIDTH              1u
#define TT_MPU_A_RASR_ENABLE(x)                 (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_ENABLE_SHIFT))&TT_MPU_A_RASR_ENABLE_MASK)
#define TT_MPU_A_RASR_SIZE_MASK                 0x3Eu
#define TT_MPU_A_RASR_SIZE_SHIFT                1u
#define TT_MPU_A_RASR_SIZE_WIDTH                5u
#define TT_MPU_A_RASR_SIZE(x)                   (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_SIZE_SHIFT))&TT_MPU_A_RASR_SIZE_MASK)
#define TT_MPU_A_RASR_SRD_MASK                  0xFF00u
#define TT_MPU_A_RASR_SRD_SHIFT                 8u
#define TT_MPU_A_RASR_SRD_WIDTH                 8u
#define TT_MPU_A_RASR_SRD(x)                    (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_SRD_SHIFT))&TT_MPU_A_RASR_SRD_MASK)
#define TT_MPU_A_RASR_B_MASK                    0x10000u
#define TT_MPU_A_RASR_B_SHIFT                   16u
#define TT_MPU_A_RASR_B_WIDTH                   1u
#define TT_MPU_A_RASR_B(x)                      (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_B_SHIFT))&TT_MPU_A_RASR_B_MASK)
#define TT_MPU_A_RASR_C_MASK                    0x20000u
#define TT_MPU_A_RASR_C_SHIFT                   17u
#define TT_MPU_A_RASR_C_WIDTH                   1u
#define TT_MPU_A_RASR_C(x)                      (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_C_SHIFT))&TT_MPU_A_RASR_C_MASK)
#define TT_MPU_A_RASR_S_MASK                    0x40000u
#define TT_MPU_A_RASR_S_SHIFT                   18u
#define TT_MPU_A_RASR_S_WIDTH                   1u
#define TT_MPU_A_RASR_S(x)                      (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_S_SHIFT))&TT_MPU_A_RASR_S_MASK)
#define TT_MPU_A_RASR_TEX_MASK                  0x380000u
#define TT_MPU_A_RASR_TEX_SHIFT                 19u
#define TT_MPU_A_RASR_TEX_WIDTH                 3u
#define TT_MPU_A_RASR_TEX(x)                    (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_TEX_SHIFT))&TT_MPU_A_RASR_TEX_MASK)
#define TT_MPU_A_RASR_AP_MASK                   0x7000000u
#define TT_MPU_A_RASR_AP_SHIFT                  24u
#define TT_MPU_A_RASR_AP_WIDTH                  3u
#define TT_MPU_A_RASR_AP(x)                     (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_AP_SHIFT))&TT_MPU_A_RASR_AP_MASK)
#define TT_MPU_A_RASR_XN_MASK                   0x10000000u
#define TT_MPU_A_RASR_XN_SHIFT                  28u
#define TT_MPU_A_RASR_XN_WIDTH                  1u
#define TT_MPU_A_RASR_XN(x)                     (((uint32_t)(((uint32_t)(x))<<TT_MPU_A_RASR_XN_SHIFT))&TT_MPU_A_RASR_XN_MASK)

/* Memory mapping of Core Hardware */
#define TT_MPU_BASE          (0xE000E000UL +  0x0D90UL)                    /*!< Memory Protection Unit */
#define TT_MPU               ((MPU_RegType       *)         TT_MPU_BASE      )   /*!< Memory Protection Unit */

#ifdef __cplusplus
}
#endif

#endif

