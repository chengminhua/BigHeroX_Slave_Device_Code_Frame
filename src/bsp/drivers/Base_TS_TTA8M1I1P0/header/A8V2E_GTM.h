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
#ifndef A8V2E_GTM_H
#define A8V2E_GTM_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define A8V2E_GTM_VENDOR_ID_H                     1541
#define A8V2E_GTM_AR_RELEASE_MAJOR_VERSION_H      4
#define A8V2E_GTM_AR_RELEASE_MINOR_VERSION_H      4
#define A8V2E_GTM_AR_RELEASE_PATCH_VERSION_H      0
#define A8V2E_GTM_SW_MAJOR_VERSION_H              1
#define A8V2E_GTM_SW_MINOR_VERSION_H              1
#define A8V2E_GTM_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* A8V2E_GTM.h and TT_Common.h file version check */
#if (A8V2E_GTM_VENDOR_ID_H != TT_COMMON_VENDOR_ID_H)
    #error "A8V2E_GTM.h and TT_Common.h have different vendor id"
#endif
#if ((A8V2E_GTM_AR_RELEASE_MAJOR_VERSION_H != TT_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_GTM_AR_RELEASE_MINOR_VERSION_H != TT_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_GTM_AR_RELEASE_PATCH_VERSION_H != TT_COMMON_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E_GTM.h and TT_Common.h are different"
#endif
#if ((A8V2E_GTM_SW_MAJOR_VERSION_H != TT_COMMON_SW_MAJOR_VERSION_H) || \
     (A8V2E_GTM_SW_MINOR_VERSION_H != TT_COMMON_SW_MINOR_VERSION_H) || \
     (A8V2E_GTM_SW_PATCH_VERSION_H != TT_COMMON_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E_GTM.h and TT_Common.h are different"
#endif


/*************************************************************************
 * module GTM.TBU
 *************************************************************************/

typedef struct {
    volatile uint32 ENDIS_CH0:2;
    volatile uint32 ENDIS_CH1:2;
    volatile uint32 ENDIS_CH2:2;
    volatile uint32 ENDIS_CH3:2;
    volatile uint32 reserved_8:24;
}  bf_GTM_TBU_CHEN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CHEN_bf_type B;
} GTM_TBU_CHEN_bf_type;

typedef struct {
    volatile uint32 LOW_RES:1;
    volatile uint32 CH_CLK_SRC:3;
    uint32 reserved_0:28;
}  bf_GTM_TBU_CH0_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH0_CTRL_bf_type B;
} GTM_TBU_CH0_CTRL_bf_type;

typedef struct {
    volatile uint32 BASE:27;
    uint32 reserved_0:5;
}  bf_GTM_TBU_CH0_BASE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH0_BASE_bf_type B;
} GTM_TBU_CH0_BASE_bf_type;

typedef struct {
    volatile uint32 CH_MODE:1;
    volatile uint32 CH_CLK_SRC:3;
    uint32 reserved_0:28;
}  bf_GTM_TBU_CH1_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH1_CTRL_bf_type B;
} GTM_TBU_CH1_CTRL_bf_type;

typedef struct {
    volatile uint32 BASE:24;
    uint32 reserved_0:8;
}  bf_GTM_TBU_CH1_BASE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH1_BASE_bf_type B;
} GTM_TBU_CH1_BASE_bf_type;

typedef struct {
    volatile uint32 CH_MODE:1;
    volatile uint32 CH_CLK_SRC:3;
    uint32 reserved_0:28;
}  bf_GTM_TBU_CH2_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH2_CTRL_bf_type B;
} GTM_TBU_CH2_CTRL_bf_type;

typedef struct {
    volatile uint32 BASE:24;
    uint32 reserved_0:8;
}  bf_GTM_TBU_CH2_BASE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH2_BASE_bf_type B;
} GTM_TBU_CH2_BASE_bf_type;

typedef struct {
    volatile uint32 CH_MODE:1;
    volatile uint32 reserved_1:3;
    volatile uint32 USE_CH2:1;
    volatile uint32 reserved_5:27;
}  bf_GTM_TBU_CH3_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH3_CTRL_bf_type B;
} GTM_TBU_CH3_CTRL_bf_type;

typedef struct {
    volatile uint32 BASE:24;
    uint32 reserved_0:8;
}  bf_GTM_TBU_CH3_BASE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH3_BASE_bf_type B;
} GTM_TBU_CH3_BASE_bf_type;

typedef struct {
    volatile uint32 BASE_MARK:24;
    uint32 reserved_0:8;
}  bf_GTM_TBU_CH3_BASE_MARK_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH3_BASE_MARK_bf_type B;
} GTM_TBU_CH3_BASE_MARK_bf_type;

typedef struct {
    volatile uint32 BASE_CAPTURE:24;
    uint32 reserved_0:8;
}  bf_GTM_TBU_CH3_BASE_CAPTURE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TBU_CH3_BASE_CAPTURE_bf_type B;
} GTM_TBU_CH3_BASE_CAPTURE_bf_type;

typedef struct {
    GTM_TBU_CHEN_bf_type CHEN; 
    GTM_TBU_CH0_CTRL_bf_type CH0_CTRL; 
    GTM_TBU_CH0_BASE_bf_type CH0_BASE; 
    GTM_TBU_CH1_CTRL_bf_type CH1_CTRL; 
    GTM_TBU_CH1_BASE_bf_type CH1_BASE; 
    GTM_TBU_CH2_CTRL_bf_type CH2_CTRL; 
    GTM_TBU_CH2_BASE_bf_type CH2_BASE; 
    GTM_TBU_CH3_CTRL_bf_type CH3_CTRL; 
    GTM_TBU_CH3_BASE_bf_type CH3_BASE; 
    GTM_TBU_CH3_BASE_MARK_bf_type CH3_BASE_MARK; 
    GTM_TBU_CH3_BASE_CAPTURE_bf_type CH3_BASE_CAPTURE; 
    volatile uint32 reserved_0[21];
} GTM_TBU_bf_type;

/*************************************************************************
 * module GTM.MON
 *************************************************************************/

typedef struct {
    volatile uint32 ACT_CMU0:1;
    volatile uint32 ACT_CMU1:1;
    volatile uint32 ACT_CMU2:1;
    volatile uint32 ACT_CMU3:1;
    volatile uint32 ACT_CMU4:1;
    volatile uint32 ACT_CMU5:1;
    volatile uint32 ACT_CMU6:1;
    volatile uint32 ACT_CMU7:1;
    volatile uint32 ACT_CMUFX0:1;
    volatile uint32 ACT_CMUFX1:1;
    volatile uint32 ACT_CMUFX2:1;
    volatile uint32 ACT_CMUFX3:1;
    volatile uint32 ACT_CMUFX4:1;
    uint32 reserved_3:1;
    volatile uint32 ACT_CMU8:1;
    uint32 reserved_2:1;
    volatile uint32 CMP_ERR:1;
     uint32 reserved_1:3;
    volatile uint32 MCS0_ERR:1;
    volatile uint32 MCS1_ERR:1;
    volatile uint32 MCS2_ERR:1;
    volatile uint32 MCS3_ERR:1;
    volatile uint32 MCS4_ERR:1;
    volatile uint32 MCS5_ERR:1;
    volatile uint32 MCS6_ERR:1;
    volatile uint32 MCS7_ERR:1;
    volatile uint32 MCS8_ERR:1;
    volatile uint32 MCS9_ERR:1;
    uint32 reserved_0:2;
}  bf_GTM_MON_STATUS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MON_STATUS_bf_type B;
} GTM_MON_STATUS_bf_type;

typedef struct {
    volatile uint32 MCA_0_0:1;
    volatile uint32 MCA_0_1:1;
    volatile uint32 MCA_0_2:1;
    volatile uint32 MCA_0_3:1;
    volatile uint32 MCA_0_4:1;
    volatile uint32 MCA_0_5:1;
    volatile uint32 MCA_0_6:1;
    volatile uint32 MCA_0_7:1;
    volatile uint32 MCA_1_0:1;
    volatile uint32 MCA_1_1:1;
    volatile uint32 MCA_1_2:1;
    volatile uint32 MCA_1_3:1;
    volatile uint32 MCA_1_4:1;
    volatile uint32 MCA_1_5:1;
    volatile uint32 MCA_1_6:1;
    volatile uint32 MCA_1_7:1;
    volatile uint32 MCA_2_0:1;
    volatile uint32 MCA_2_1:1;
    volatile uint32 MCA_2_2:1;
    volatile uint32 MCA_2_3:1;
    volatile uint32 MCA_2_4:1;
    volatile uint32 MCA_2_5:1;
    volatile uint32 MCA_2_6:1;
    volatile uint32 MCA_2_7:1;
    volatile uint32 MCA_3_0:1;
    volatile uint32 MCA_3_1:1;
    volatile uint32 MCA_3_2:1;
    volatile uint32 MCA_3_3:1;
    volatile uint32 MCA_3_4:1;
    volatile uint32 MCA_3_5:1;
    volatile uint32 MCA_3_6:1;
    volatile uint32 MCA_3_7:1;
}  bf_GTM_MON_ACTIVITY_0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MON_ACTIVITY_0_bf_type B;
} GTM_MON_ACTIVITY_0_bf_type;

typedef struct {
    volatile uint32 MCA_4_0:1;
    volatile uint32 MCA_4_1:1;
    volatile uint32 MCA_4_2:1;
    volatile uint32 MCA_4_3:1;
    volatile uint32 MCA_4_4:1;
    volatile uint32 MCA_4_5:1;
    volatile uint32 MCA_4_6:1;
    volatile uint32 MCA_4_7:1;
    volatile uint32 MCA_5_0:1;
    volatile uint32 MCA_5_1:1;
    volatile uint32 MCA_5_2:1;
    volatile uint32 MCA_5_3:1;
    volatile uint32 MCA_5_4:1;
    volatile uint32 MCA_5_5:1;
    volatile uint32 MCA_5_6:1;
    volatile uint32 MCA_5_7:1;
    volatile uint32 MCA_6_0:1;
    volatile uint32 MCA_6_1:1;
    volatile uint32 MCA_6_2:1;
    volatile uint32 MCA_6_3:1;
    volatile uint32 MCA_6_4:1;
    volatile uint32 MCA_6_5:1;
    volatile uint32 MCA_6_6:1;
    volatile uint32 MCA_6_7:1;
    volatile uint32 MCA_7_0:1;
    volatile uint32 MCA_7_1:1;
    volatile uint32 MCA_7_2:1;
    volatile uint32 MCA_7_3:1;
    volatile uint32 MCA_7_4:1;
    volatile uint32 MCA_7_5:1;
    volatile uint32 MCA_7_6:1;
    volatile uint32 MCA_7_7:1;
}  bf_GTM_MON_ACTIVITY_1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MON_ACTIVITY_1_bf_type B;
} GTM_MON_ACTIVITY_1_bf_type;

typedef struct {
    volatile uint32 MCA_0:1;
    volatile uint32 MCA_1:1;
    volatile uint32 MCA_2:1;
    volatile uint32 MCA_3:1;
    volatile uint32 MCA_4:1;
    volatile uint32 MCA_5:1;
    volatile uint32 MCA_6:1;
    volatile uint32 MCA_7:1;
    uint32 reserved_0:24;
}  bf_GTM_MON_ACTIVITY_MCS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MON_ACTIVITY_MCS_bf_type B;
} GTM_MON_ACTIVITY_MCS_bf_type;

typedef struct {
    GTM_MON_STATUS_bf_type STATUS; 
    GTM_MON_ACTIVITY_0_bf_type ACTIVITY_0; 
    GTM_MON_ACTIVITY_1_bf_type ACTIVITY_1; 
    GTM_MON_ACTIVITY_MCS_bf_type ACTIVITY_MCS[10]; 
    volatile uint32 reserved_0[3];
} GTM_MON_bf_type;

/*************************************************************************
 * module GTM.CMP
 *************************************************************************/

typedef struct {
    volatile uint32 ABWC0_EN:1;
    volatile uint32 ABWC1_EN:1;
    volatile uint32 ABWC2_EN:1;
    volatile uint32 ABWC3_EN:1;
    volatile uint32 ABWC4_EN:1;
    volatile uint32 ABWC5_EN:1;
    volatile uint32 ABWC6_EN:1;
    volatile uint32 ABWC7_EN:1;
    volatile uint32 ABWC8_EN:1;
    volatile uint32 ABWC9_EN:1;
    volatile uint32 ABWC10_EN:1;
    volatile uint32 ABWC11_EN:1;
    volatile uint32 TBWC0_EN:1;
    volatile uint32 TBWC1_EN:1;
    volatile uint32 TBWC2_EN:1;
    volatile uint32 TBWC3_EN:1;
    volatile uint32 TBWC4_EN:1;
    volatile uint32 TBWC5_EN:1;
    volatile uint32 TBWC6_EN:1;
    volatile uint32 TBWC7_EN:1;
    volatile uint32 TBWC8_EN:1;
    volatile uint32 TBWC9_EN:1;
    volatile uint32 TBWC10_EN:1;
    volatile uint32 TBWC11_EN:1;
    uint32 reserved_0:8;
}  bf_GTM_CMP_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMP_EN_bf_type B;
} GTM_CMP_EN_bf_type;

typedef struct {
    volatile uint32 ABWC0:1;
    volatile uint32 ABWC1:1;
    volatile uint32 ABWC2:1;
    volatile uint32 ABWC3:1;
    volatile uint32 ABWC4:1;
    volatile uint32 ABWC5:1;
    volatile uint32 ABWC6:1;
    volatile uint32 ABWC7:1;
    volatile uint32 ABWC8:1;
    volatile uint32 ABWC9:1;
    volatile uint32 ABWC10:1;
    volatile uint32 ABWC11:1;
    volatile uint32 TBWC0:1;
    volatile uint32 TBWC1:1;
    volatile uint32 TBWC2:1;
    volatile uint32 TBWC3:1;
    volatile uint32 TBWC4:1;
    volatile uint32 TBWC5:1;
    volatile uint32 TBWC6:1;
    volatile uint32 TBWC7:1;
    volatile uint32 TBWC8:1;
    volatile uint32 TBWC9:1;
    volatile uint32 TBWC10:1;
    volatile uint32 TBWC11:1;
    uint32 reserved_0:8;
}  bf_GTM_CMP_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMP_IRQ_NOTIFY_bf_type B;
} GTM_CMP_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 ABWC0_EN_IRQ:1;
    volatile uint32 ABWC1_EN_IRQ:1;
    volatile uint32 ABWC2_EN_IRQ:1;
    volatile uint32 ABWC3_EN_IRQ:1;
    volatile uint32 ABWC4_EN_IRQ:1;
    volatile uint32 ABWC5_EN_IRQ:1;
    volatile uint32 ABWC6_EN_IRQ:1;
    volatile uint32 ABWC7_EN_IRQ:1;
    volatile uint32 ABWC8_EN_IRQ:1;
    volatile uint32 ABWC9_EN_IRQ:1;
    volatile uint32 ABWC10_EN_IRQ:1;
    volatile uint32 ABWC11_EN_IRQ:1;
    volatile uint32 TBWC0_EN_IRQ:1;
    volatile uint32 TBWC1_EN_IRQ:1;
    volatile uint32 TBWC2_EN_IRQ:1;
    volatile uint32 TBWC3_EN_IRQ:1;
    volatile uint32 TBWC4_EN_IRQ:1;
    volatile uint32 TBWC5_EN_IRQ:1;
    volatile uint32 TBWC6_EN_IRQ:1;
    volatile uint32 TBWC7_EN_IRQ:1;
    volatile uint32 TBWC8_EN_IRQ:1;
    volatile uint32 TBWC9_EN_IRQ:1;
    volatile uint32 TBWC10_EN_IRQ:1;
    volatile uint32 TBWC11_EN_IRQ:1;
    uint32 reserved_0:8;
}  bf_GTM_CMP_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMP_IRQ_EN_bf_type B;
} GTM_CMP_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_ABWC0:1;
    volatile uint32 TRG_ABWC1:1;
    volatile uint32 TRG_ABWC2:1;
    volatile uint32 TRG_ABWC3:1;
    volatile uint32 TRG_ABWC4:1;
    volatile uint32 TRG_ABWC5:1;
    volatile uint32 TRG_ABWC6:1;
    volatile uint32 TRG_ABWC7:1;
    volatile uint32 TRG_ABWC8:1;
    volatile uint32 TRG_ABWC9:1;
    volatile uint32 TRG_ABWC10:1;
    volatile uint32 TRG_ABWC11:1;
    volatile uint32 TRG_TBWC0:1;
    volatile uint32 TRG_TBWC1:1;
    volatile uint32 TRG_TBWC2:1;
    volatile uint32 TRG_TBWC3:1;
    volatile uint32 TRG_TBWC4:1;
    volatile uint32 TRG_TBWC5:1;
    volatile uint32 TRG_TBWC6:1;
    volatile uint32 TRG_TBWC7:1;
    volatile uint32 TRG_TBWC8:1;
    volatile uint32 TRG_TBWC9:1;
    volatile uint32 TRG_TBWC10:1;
    volatile uint32 TRG_TBWC11:1;
    uint32 reserved_0:8;
}  bf_GTM_CMP_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMP_IRQ_FORCINT_bf_type B;
} GTM_CMP_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_CMP_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMP_IRQ_MODE_bf_type B;
} GTM_CMP_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 ABWC0_EN_EIRQ:1;
    volatile uint32 ABWC1_EN_EIRQ:1;
    volatile uint32 ABWC2_EN_EIRQ:1;
    volatile uint32 ABWC3_EN_EIRQ:1;
    volatile uint32 ABWC4_EN_EIRQ:1;
    volatile uint32 ABWC5_EN_EIRQ:1;
    volatile uint32 ABWC6_EN_EIRQ:1;
    volatile uint32 ABWC7_EN_EIRQ:1;
    volatile uint32 ABWC8_EN_EIRQ:1;
    volatile uint32 ABWC9_EN_EIRQ:1;
    volatile uint32 ABWC10_EN_EIRQ:1;
    volatile uint32 ABWC11_EN_EIRQ:1;
    volatile uint32 TBWC0_EN_EIRQ:1;
    volatile uint32 TBWC1_EN_EIRQ:1;
    volatile uint32 TBWC2_EN_EIRQ:1;
    volatile uint32 TBWC3_EN_EIRQ:1;
    volatile uint32 TBWC4_EN_EIRQ:1;
    volatile uint32 TBWC5_EN_EIRQ:1;
    volatile uint32 TBWC6_EN_EIRQ:1;
    volatile uint32 TBWC7_EN_EIRQ:1;
    volatile uint32 TBWC8_EN_EIRQ:1;
    volatile uint32 TBWC9_EN_EIRQ:1;
    volatile uint32 TBWC10_EN_EIRQ:1;
    volatile uint32 TBWC11_EN_EIRQ:1;
    uint32 reserved_0:8;
}  bf_GTM_CMP_EIRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMP_EIRQ_EN_bf_type B;
} GTM_CMP_EIRQ_EN_bf_type;

typedef struct {
    GTM_CMP_EN_bf_type EN; 
    GTM_CMP_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_CMP_IRQ_EN_bf_type IRQ_EN; 
    GTM_CMP_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_CMP_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_CMP_EIRQ_EN_bf_type EIRQ_EN; 
    volatile uint32 reserved_0[10];
} GTM_CMP_bf_type;

/*************************************************************************
 * module GTM.ARU
 *************************************************************************/

typedef struct {
    volatile uint32 ADDR:9;
    uint32 reserved_1:3;
    volatile uint32 RREQ:1;
    volatile uint32 WREQ:1;
    uint32 reserved_0:18;
}  bf_GTM_ARU_ACCESS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_ACCESS_bf_type B;
} GTM_ARU_ACCESS_bf_type;

typedef struct {
    volatile uint32 DATA:29;
    uint32 reserved_0:3;
}  bf_GTM_ARU_DATA_H_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DATA_H_bf_type B;
} GTM_ARU_DATA_H_bf_type;

typedef struct {
    volatile uint32 DATA:29;
    uint32 reserved_0:3;
}  bf_GTM_ARU_DATA_L_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DATA_L_bf_type B;
} GTM_ARU_DATA_L_bf_type;

typedef struct {
    volatile uint32 ADDR:9;
    uint32 reserved_0:23;
}  bf_GTM_ARU_DBG_ACCESS0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DBG_ACCESS0_bf_type B;
} GTM_ARU_DBG_ACCESS0_bf_type;

typedef struct {
    volatile uint32 DATA:29;
    uint32 reserved_0:3;
}  bf_GTM_ARU_DBG_DATA0_H_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DBG_DATA0_H_bf_type B;
} GTM_ARU_DBG_DATA0_H_bf_type;

typedef struct {
    volatile uint32 DATA:29;
    uint32 reserved_0:3;
}  bf_GTM_ARU_DBG_DATA0_L_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DBG_DATA0_L_bf_type B;
} GTM_ARU_DBG_DATA0_L_bf_type;

typedef struct {
    volatile uint32 ADDR:9;
    uint32 reserved_0:23;
}  bf_GTM_ARU_DBG_ACCESS1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DBG_ACCESS1_bf_type B;
} GTM_ARU_DBG_ACCESS1_bf_type;

typedef struct {
    volatile uint32 DATA:29;
    uint32 reserved_0:3;
}  bf_GTM_ARU_DBG_DATA1_H_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DBG_DATA1_H_bf_type B;
} GTM_ARU_DBG_DATA1_H_bf_type;

typedef struct {
    volatile uint32 DATA:29;
    uint32 reserved_0:3;
}  bf_GTM_ARU_DBG_DATA1_L_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DBG_DATA1_L_bf_type B;
} GTM_ARU_DBG_DATA1_L_bf_type;

typedef struct {
    volatile uint32 NEW_DATA0:1;
    volatile uint32 NEW_DATA1:1;
    volatile uint32 ACC_ACK:1;
    uint32 reserved_0:29;
}  bf_GTM_ARU_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_IRQ_NOTIFY_bf_type B;
} GTM_ARU_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 NEW_DATA0_IRQ_EN:1;
    volatile uint32 NEW_DATA1_IRQ_EN:1;
    volatile uint32 ACC_ACK_IRQ_EN:1;
    uint32 reserved_0:29;
}  bf_GTM_ARU_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_IRQ_EN_bf_type B;
} GTM_ARU_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_NEW_DATA0:1;
    volatile uint32 TRG_NEW_DATA1:1;
    volatile uint32 TRG_ACC_ACK:1;
    uint32 reserved_0:29;
}  bf_GTM_ARU_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_IRQ_FORCINT_bf_type B;
} GTM_ARU_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_ARU_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_IRQ_MODE_bf_type B;
} GTM_ARU_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 CADDR_END:7;
    uint32 reserved_0:25;
}  bf_GTM_ARU_CADDR_END_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_CADDR_END_bf_type B;
} GTM_ARU_CADDR_END_bf_type;

typedef struct {
    volatile uint32 ARU_0_DYN_EN:2;
    volatile uint32 ARU_1_DYN_EN:2;
    volatile uint32 ARU_DYN_RING_MODE:1;
    uint32 reserved_0:27;
}  bf_GTM_ARU_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_CTRL_bf_type B;
} GTM_ARU_CTRL_bf_type;

typedef struct {
    volatile uint32 DYN_ARU_UPDATE_EN:1;
    volatile uint32 DYN_ROUTE_SWAP:1;
    uint32 reserved_0:30;
}  bf_GTM_ARU_DYN_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DYN_CTRL_bf_type B;
} GTM_ARU_DYN_CTRL_bf_type;

typedef struct {
    volatile uint32 DYN_READ_ID0:8;
    volatile uint32 DYN_READ_ID1:8;
    volatile uint32 DYN_READ_ID2:8;
    uint32 reserved_0:8;
}  bf_GTM_ARU_DYN_ROUTE_LOW_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DYN_ROUTE_LOW_bf_type B;
} GTM_ARU_DYN_ROUTE_LOW_bf_type;

typedef struct {
    volatile uint32 DYN_READ_ID3:8;
    volatile uint32 DYN_READ_ID4:8;
    volatile uint32 DYN_READ_ID5:8;
    volatile uint32 DYN_CLK_WAIT:4;
    uint32 reserved_0:4;
}  bf_GTM_ARU_DYN_ROUTE_HIGH_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DYN_ROUTE_HIGH_bf_type B;
} GTM_ARU_DYN_ROUTE_HIGH_bf_type;

typedef struct {
    volatile uint32 DYN_READ_ID6:8;
    volatile uint32 DYN_READ_ID7:8;
    volatile uint32 DYN_READ_ID8:8;
    uint32 reserved_0:8;
}  bf_GTM_ARU_DYN_ROUTE_SR_LOW_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DYN_ROUTE_SR_LOW_bf_type B;
} GTM_ARU_DYN_ROUTE_SR_LOW_bf_type;

typedef struct {
    volatile uint32 DYN_READ_ID9:8;
    volatile uint32 DYN_READ_ID10:8;
    volatile uint32 DYN_READ_ID11:8;
    volatile uint32 DYN_CLK_WAIT:4;
    volatile uint32 DYN_UPDATE_EN:1;
    uint32 reserved_0:3;
}  bf_GTM_ARU_DYN_ROUTE_SR_HIGH_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DYN_ROUTE_SR_HIGH_bf_type B;
} GTM_ARU_DYN_ROUTE_SR_HIGH_bf_type;

typedef struct {
    volatile uint32 DYN_ARU_RDADDR:9;
    uint32 reserved_0:23;
}  bf_GTM_ARU_DYN_RDADDR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_DYN_RDADDR_bf_type B;
} GTM_ARU_DYN_RDADDR_bf_type;

typedef struct {
    volatile uint32 CADDR_0:7;
    uint32 reserved_1:9;
    volatile uint32 CADDR_1:7;
    uint32 reserved_0:9;
}  bf_GTM_ARU_CADDR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_CADDR_bf_type B;
} GTM_ARU_CADDR_bf_type;

typedef struct {
    GTM_ARU_ACCESS_bf_type ACCESS; 
    GTM_ARU_DATA_H_bf_type DATA_H; 
    GTM_ARU_DATA_L_bf_type DATA_L; 
    GTM_ARU_DBG_ACCESS0_bf_type DBG_ACCESS0; 
    GTM_ARU_DBG_DATA0_H_bf_type DBG_DATA0_H; 
    GTM_ARU_DBG_DATA0_L_bf_type DBG_DATA0_L; 
    GTM_ARU_DBG_ACCESS1_bf_type DBG_ACCESS1; 
    GTM_ARU_DBG_DATA1_H_bf_type DBG_DATA1_H; 
    GTM_ARU_DBG_DATA1_L_bf_type DBG_DATA1_L; 
    GTM_ARU_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_ARU_IRQ_EN_bf_type IRQ_EN; 
    GTM_ARU_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_ARU_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_ARU_CADDR_END_bf_type CADDR_END; 
    volatile uint32 reserved_0;
    GTM_ARU_CTRL_bf_type CTRL; 
    GTM_ARU_DYN_CTRL_bf_type DYN_CTRL[2]; 
    GTM_ARU_DYN_ROUTE_LOW_bf_type DYN_ROUTE_LOW[2]; 
    GTM_ARU_DYN_ROUTE_HIGH_bf_type DYN_ROUTE_HIGH[2]; 
    GTM_ARU_DYN_ROUTE_SR_LOW_bf_type DYN_ROUTE_SR_LOW[2]; 
    GTM_ARU_DYN_ROUTE_SR_HIGH_bf_type DYN_ROUTE_SR_HIGH[2]; 
    GTM_ARU_DYN_RDADDR_bf_type DYN_RDADDR[2]; 
    volatile uint32 reserved_1[3];
    GTM_ARU_CADDR_bf_type CADDR; 
} GTM_ARU_bf_type;

/*************************************************************************
 * module GTM.CMU
 *************************************************************************/

typedef struct {
    volatile uint32 EN_CLK0:2;
    volatile uint32 EN_CLK1:2;
    volatile uint32 EN_CLK2:2;
    volatile uint32 EN_CLK3:2;
    volatile uint32 EN_CLK4:2;
    volatile uint32 EN_CLK5:2;
    volatile uint32 EN_CLK6:2;
    volatile uint32 EN_CLK7:2;
    volatile uint32 EN_ECLK0:2;
    volatile uint32 EN_ECLK1:2;
    volatile uint32 EN_ECLK2:2;
    volatile uint32 EN_FXCLK:2;
    uint32 reserved_0:8;
}  bf_GTM_CMU_CLK_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_EN_bf_type B;
} GTM_CMU_CLK_EN_bf_type;

typedef struct {
    volatile uint32 GCLK_NUM:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_GCLK_NUM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_GCLK_NUM_bf_type B;
} GTM_CMU_GCLK_NUM_bf_type;

typedef struct {
    volatile uint32 GCLK_DEN:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_GCLK_DEN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_GCLK_DEN_bf_type B;
} GTM_CMU_GCLK_DEN_bf_type;

typedef struct {
    volatile uint32 CLK_CNT:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_CLK_0_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_0_CTRL_bf_type B;
} GTM_CMU_CLK_0_CTRL_bf_type;

typedef struct {
    volatile uint32 CLK_CNT:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_CLK_1_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_1_CTRL_bf_type B;
} GTM_CMU_CLK_1_CTRL_bf_type;

typedef struct {
    volatile uint32 CLK_CNT:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_CLK_2_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_2_CTRL_bf_type B;
} GTM_CMU_CLK_2_CTRL_bf_type;

typedef struct {
    volatile uint32 CLK_CNT:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_CLK_3_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_3_CTRL_bf_type B;
} GTM_CMU_CLK_3_CTRL_bf_type;

typedef struct {
    volatile uint32 CLK_CNT:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_CLK_4_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_4_CTRL_bf_type B;
} GTM_CMU_CLK_4_CTRL_bf_type;

typedef struct {
    volatile uint32 CLK_CNT:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_CLK_5_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_5_CTRL_bf_type B;
} GTM_CMU_CLK_5_CTRL_bf_type;

typedef struct {
    volatile uint32 CLK_CNT:24;
    volatile uint32 CLK6_SEL:2;
    uint32 reserved_0:6;
}  bf_GTM_CMU_CLK_6_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_6_CTRL_bf_type B;
} GTM_CMU_CLK_6_CTRL_bf_type;

typedef struct {
    volatile uint32 CLK_CNT:24;
    volatile uint32 CLK7_SEL:2;
    uint32 reserved_0:6;
}  bf_GTM_CMU_CLK_7_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_7_CTRL_bf_type B;
} GTM_CMU_CLK_7_CTRL_bf_type;

typedef struct {
    volatile uint32 ECLK_NUM:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_ECLK_0_NUM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_ECLK_0_NUM_bf_type B;
} GTM_CMU_ECLK_0_NUM_bf_type;

typedef struct {
    volatile uint32 ECLK_DEN:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_ECLK_0_DEN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_ECLK_0_DEN_bf_type B;
} GTM_CMU_ECLK_0_DEN_bf_type;

typedef struct {
    volatile uint32 ECLK_NUM:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_ECLK_1_NUM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_ECLK_1_NUM_bf_type B;
} GTM_CMU_ECLK_1_NUM_bf_type;

typedef struct {
    volatile uint32 ECLK_DEN:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_ECLK_1_DEN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_ECLK_1_DEN_bf_type B;
} GTM_CMU_ECLK_1_DEN_bf_type;

typedef struct {
    volatile uint32 ECLK_NUM:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_ECLK_2_NUM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_ECLK_2_NUM_bf_type B;
} GTM_CMU_ECLK_2_NUM_bf_type;

typedef struct {
    volatile uint32 ECLK_DEN:24;
    uint32 reserved_0:8;
}  bf_GTM_CMU_ECLK_2_DEN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_ECLK_2_DEN_bf_type B;
} GTM_CMU_ECLK_2_DEN_bf_type;

typedef struct {
    volatile uint32 FXCLK_SEL:4;
    uint32 reserved_0:28;
}  bf_GTM_CMU_FXCLK_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_FXCLK_CTRL_bf_type B;
} GTM_CMU_FXCLK_CTRL_bf_type;

typedef struct {
    volatile uint32 ARU_ADDR_RSTGLB:1;
    uint32 reserved_0:31;
}  bf_GTM_CMU_GLB_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_GLB_CTRL_bf_type B;
} GTM_CMU_GLB_CTRL_bf_type;

typedef struct {
    volatile uint32 CLK0_EXT_DIVIDER:1;
    volatile uint32 CLK1_EXT_DIVIDER:1;
    volatile uint32 CLK2_EXT_DIVIDER:1;
    volatile uint32 CLK3_EXT_DIVIDER:1;
    volatile uint32 CLK4_EXT_DIVIDER:1;
    volatile uint32 CLK5_EXT_DIVIDER:1;
    volatile uint32 CLK6_EXT_DIVIDER:1;
    volatile uint32 CLK7_EXT_DIVIDER:1;
    volatile uint32 CLK8_EXT_DIVIDER:1;
    uint32 reserved_0:23;
}  bf_GTM_CMU_CLK_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CMU_CLK_CTRL_bf_type B;
} GTM_CMU_CLK_CTRL_bf_type;

typedef struct {
    GTM_CMU_CLK_EN_bf_type CLK_EN; 
    GTM_CMU_GCLK_NUM_bf_type GCLK_NUM; 
    GTM_CMU_GCLK_DEN_bf_type GCLK_DEN; 
    GTM_CMU_CLK_0_CTRL_bf_type CLK_0_CTRL; 
    GTM_CMU_CLK_1_CTRL_bf_type CLK_1_CTRL; 
    GTM_CMU_CLK_2_CTRL_bf_type CLK_2_CTRL; 
    GTM_CMU_CLK_3_CTRL_bf_type CLK_3_CTRL; 
    GTM_CMU_CLK_4_CTRL_bf_type CLK_4_CTRL; 
    GTM_CMU_CLK_5_CTRL_bf_type CLK_5_CTRL; 
    GTM_CMU_CLK_6_CTRL_bf_type CLK_6_CTRL; 
    GTM_CMU_CLK_7_CTRL_bf_type CLK_7_CTRL; 
    GTM_CMU_ECLK_0_NUM_bf_type ECLK_0_NUM; 
    GTM_CMU_ECLK_0_DEN_bf_type ECLK_0_DEN; 
    GTM_CMU_ECLK_1_NUM_bf_type ECLK_1_NUM; 
    GTM_CMU_ECLK_1_DEN_bf_type ECLK_1_DEN; 
    GTM_CMU_ECLK_2_NUM_bf_type ECLK_2_NUM; 
    GTM_CMU_ECLK_2_DEN_bf_type ECLK_2_DEN; 
    GTM_CMU_FXCLK_CTRL_bf_type FXCLK_CTRL; 
    GTM_CMU_GLB_CTRL_bf_type GLB_CTRL; 
    GTM_CMU_CLK_CTRL_bf_type CLK_CTRL; 
    volatile uint32 reserved_0[12];
} GTM_CMU_bf_type;

/*************************************************************************
 * module GTM.BRC.SRC
 *************************************************************************/

typedef struct {
    volatile uint32 ADDR:9;
    uint32 reserved_1:3;
    volatile uint32 BRC_MODE:1;
    uint32 reserved_0:19;
}  bf_GTM_BRC_SRC_ADDR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRC_SRC_ADDR_bf_type B;
} GTM_BRC_SRC_ADDR_bf_type;

typedef struct {
    volatile uint32 EN_DEST0:1;
    volatile uint32 EN_DEST1:1;
    volatile uint32 EN_DEST2:1;
    volatile uint32 EN_DEST3:1;
    volatile uint32 EN_DEST4:1;
    volatile uint32 EN_DEST5:1;
    volatile uint32 EN_DEST6:1;
    volatile uint32 EN_DEST7:1;
    volatile uint32 EN_DEST8:1;
    volatile uint32 EN_DEST9:1;
    volatile uint32 EN_DEST10:1;
    volatile uint32 EN_DEST11:1;
    volatile uint32 EN_DEST12:1;
    volatile uint32 EN_DEST13:1;
    volatile uint32 EN_DEST14:1;
    volatile uint32 EN_DEST15:1;
    volatile uint32 EN_DEST16:1;
    volatile uint32 EN_DEST17:1;
    volatile uint32 EN_DEST18:1;
    volatile uint32 EN_DEST19:1;
    volatile uint32 EN_DEST20:1;
    volatile uint32 EN_DEST21:1;
    volatile uint32 EN_TRASHBIN:1;
    uint32 reserved_0:9;
}  bf_GTM_BRC_SRC_DEST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRC_SRC_DEST_bf_type B;
} GTM_BRC_SRC_DEST_bf_type;

typedef struct {
    GTM_BRC_SRC_ADDR_bf_type ADDR; 
    GTM_BRC_SRC_DEST_bf_type DEST; 
} GTM_BRC_SRC_bf_type;

/*************************************************************************
 * module GTM.BRC
 *************************************************************************/

typedef struct {
    volatile uint32 DEST_ERR:1;
    volatile uint32 DID0:1;
    volatile uint32 DID1:1;
    volatile uint32 DID2:1;
    volatile uint32 DID3:1;
    volatile uint32 DID4:1;
    volatile uint32 DID5:1;
    volatile uint32 DID6:1;
    volatile uint32 DID7:1;
    volatile uint32 DID8:1;
    volatile uint32 DID9:1;
    volatile uint32 DID10:1;
    volatile uint32 DID11:1;
    uint32 reserved_0:19;
}  bf_GTM_BRC_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRC_IRQ_NOTIFY_bf_type B;
} GTM_BRC_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 DEST_ERR_IRQ_EN:1;
    volatile uint32 DID_IRQ_EN0:1;
    volatile uint32 DID_IRQ_EN1:1;
    volatile uint32 DID_IRQ_EN2:1;
    volatile uint32 DID_IRQ_EN3:1;
    volatile uint32 DID_IRQ_EN4:1;
    volatile uint32 DID_IRQ_EN5:1;
    volatile uint32 DID_IRQ_EN6:1;
    volatile uint32 DID_IRQ_EN7:1;
    volatile uint32 DID_IRQ_EN8:1;
    volatile uint32 DID_IRQ_EN9:1;
    volatile uint32 DID_IRQ_EN10:1;
    volatile uint32 DID_IRQ_EN11:1;
    uint32 reserved_0:19;
}  bf_GTM_BRC_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRC_IRQ_EN_bf_type B;
} GTM_BRC_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_DEST_ERR:1;
    volatile uint32 TRG_DID0:1;
    volatile uint32 TRG_DID1:1;
    volatile uint32 TRG_DID2:1;
    volatile uint32 TRG_DID3:1;
    volatile uint32 TRG_DID4:1;
    volatile uint32 TRG_DID5:1;
    volatile uint32 TRG_DID6:1;
    volatile uint32 TRG_DID7:1;
    volatile uint32 TRG_DID8:1;
    volatile uint32 TRG_DID9:1;
    volatile uint32 TRG_DID10:1;
    volatile uint32 TRG_DID11:1;
    uint32 reserved_0:19;
}  bf_GTM_BRC_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRC_IRQ_FORCINT_bf_type B;
} GTM_BRC_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_BRC_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRC_IRQ_MODE_bf_type B;
} GTM_BRC_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 RST:1;
    uint32 reserved_0:31;
}  bf_GTM_BRC_RST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRC_RST_bf_type B;
} GTM_BRC_RST_bf_type;

typedef struct {
    volatile uint32 DEST_ERR_EIRQ_EN:1;
    volatile uint32 DID_EIRQ_EN0:1;
    volatile uint32 DID_EIRQ_EN1:1;
    volatile uint32 DID_EIRQ_EN2:1;
    volatile uint32 DID_EIRQ_EN3:1;
    volatile uint32 DID_EIRQ_EN4:1;
    volatile uint32 DID_EIRQ_EN5:1;
    volatile uint32 DID_EIRQ_EN6:1;
    volatile uint32 DID_EIRQ_EN7:1;
    volatile uint32 DID_EIRQ_EN8:1;
    volatile uint32 DID_EIRQ_EN9:1;
    volatile uint32 DID_EIRQ_EN10:1;
    volatile uint32 DID_EIRQ_EN11:1;
    uint32 reserved_0:19;
}  bf_GTM_BRC_EIRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRC_EIRQ_EN_bf_type B;
} GTM_BRC_EIRQ_EN_bf_type;

typedef struct {
    GTM_BRC_SRC_bf_type SRC[12]; 
    GTM_BRC_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_BRC_IRQ_EN_bf_type IRQ_EN; 
    GTM_BRC_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_BRC_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_BRC_RST_bf_type RST; 
    GTM_BRC_EIRQ_EN_bf_type EIRQ_EN; 
    volatile uint32 reserved_0[2];
} GTM_BRC_bf_type;

/*************************************************************************
 * module GTM.ICM
 *************************************************************************/

typedef struct {
    volatile uint32 ARU_NEW_DATA0_IRQ:1;
    volatile uint32 ARU_NEW_DATA1_IRQ:1;
    volatile uint32 ARU_ACC_ACK_IRQ:1;
    volatile uint32 BRC_IRQ:1;
    volatile uint32 AEI_IRQ:1;
    volatile uint32 CMP_IRQ:1;
    volatile uint32 SPE0_IRQ:1;
    volatile uint32 SPE1_IRQ:1;
    volatile uint32 SPE2_IRQ:1;
    volatile uint32 SPE3_IRQ:1;
    volatile uint32 SPE4_IRQ:1;
    volatile uint32 SPE5_IRQ:1;
    uint32 reserved_0:4;
    volatile uint32 PSM0_CH0_IRQ:1;
    volatile uint32 PSM0_CH1_IRQ:1;
    volatile uint32 PSM0_CH2_IRQ:1;
    volatile uint32 PSM0_CH3_IRQ:1;
    volatile uint32 PSM0_CH4_IRQ:1;
    volatile uint32 PSM0_CH5_IRQ:1;
    volatile uint32 PSM0_CH6_IRQ:1;
    volatile uint32 PSM0_CH7_IRQ:1;
    volatile uint32 PSM1_CH0_IRQ:1;
    volatile uint32 PSM1_CH1_IRQ:1;
    volatile uint32 PSM1_CH2_IRQ:1;
    volatile uint32 PSM1_CH3_IRQ:1;
    volatile uint32 PSM1_CH4_IRQ:1;
    volatile uint32 PSM1_CH5_IRQ:1;
    volatile uint32 PSM1_CH6_IRQ:1;
    volatile uint32 PSM1_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_0_bf_type B;
} GTM_ICM_IRQG_0_bf_type;

typedef struct {
    volatile uint32 DPLL_DCGI_IRQ:1;
    volatile uint32 DPLL_EDI_IRQ:1;
    volatile uint32 DPLL_TINI_IRQ:1;
    volatile uint32 DPLL_TAXI_IRQ:1;
    volatile uint32 DPLL_SISI_IRQ:1;
    volatile uint32 DPLL_TISI_IRQ:1;
    volatile uint32 DPLL_MSI_IRQ:1;
    volatile uint32 DPLL_MTI_IRQ:1;
    volatile uint32 DPLL_SASI_IRQ:1;
    volatile uint32 DPLL_TASI_IRQ:1;
    volatile uint32 DPLL_PWI_IRQ:1;
    volatile uint32 DPLL_W2I_IRQ:1;
    volatile uint32 DPLL_W1I_IRQ:1;
    volatile uint32 DPLL_GL1I_IRQ:1;
    volatile uint32 DPLL_LL1I_IRQ:1;
    volatile uint32 DPLL_EI_IRQ:1;
    volatile uint32 DPLL_GL2I_IRQ:1;
    volatile uint32 DPLL_LL2I_IRQ:1;
    volatile uint32 DPLL_TE0I_IRQ:1;
    volatile uint32 DPLL_TE1I_IRQ:1;
    volatile uint32 DPLL_TE2I_IRQ:1;
    volatile uint32 DPLL_TE3I_IRQ:1;
    volatile uint32 DPLL_TE4I_IRQ:1;
    volatile uint32 DPLL_CDTI_IRQ:1;
    volatile uint32 DPLL_CDSI_IRQ:1;
    volatile uint32 DPLL_TORI_IRQ:1;
    volatile uint32 DPLL_SORI_IRQ:1;
    uint32 reserved_0:5;
}  bf_GTM_ICM_IRQG_1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_1_bf_type B;
} GTM_ICM_IRQG_1_bf_type;

typedef struct {
    volatile uint32 TIM0_CH0_IRQ:1;
    volatile uint32 TIM0_CH1_IRQ:1;
    volatile uint32 TIM0_CH2_IRQ:1;
    volatile uint32 TIM0_CH3_IRQ:1;
    volatile uint32 TIM0_CH4_IRQ:1;
    volatile uint32 TIM0_CH5_IRQ:1;
    volatile uint32 TIM0_CH6_IRQ:1;
    volatile uint32 TIM0_CH7_IRQ:1;
    volatile uint32 TIM1_CH0_IRQ:1;
    volatile uint32 TIM1_CH1_IRQ:1;
    volatile uint32 TIM1_CH2_IRQ:1;
    volatile uint32 TIM1_CH3_IRQ:1;
    volatile uint32 TIM1_CH4_IRQ:1;
    volatile uint32 TIM1_CH5_IRQ:1;
    volatile uint32 TIM1_CH6_IRQ:1;
    volatile uint32 TIM1_CH7_IRQ:1;
    volatile uint32 TIM2_CH0_IRQ:1;
    volatile uint32 TIM2_CH1_IRQ:1;
    volatile uint32 TIM2_CH2_IRQ:1;
    volatile uint32 TIM2_CH3_IRQ:1;
    volatile uint32 TIM2_CH4_IRQ:1;
    volatile uint32 TIM2_CH5_IRQ:1;
    volatile uint32 TIM2_CH6_IRQ:1;
    volatile uint32 TIM2_CH7_IRQ:1;
    volatile uint32 TIM3_CH0_IRQ:1;
    volatile uint32 TIM3_CH1_IRQ:1;
    volatile uint32 TIM3_CH2_IRQ:1;
    volatile uint32 TIM3_CH3_IRQ:1;
    volatile uint32 TIM3_CH4_IRQ:1;
    volatile uint32 TIM3_CH5_IRQ:1;
    volatile uint32 TIM3_CH6_IRQ:1;
    volatile uint32 TIM3_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_2_bf_type B;
} GTM_ICM_IRQG_2_bf_type;

typedef struct {
    volatile uint32 TIM4_CH0_IRQ:1;
    volatile uint32 TIM4_CH1_IRQ:1;
    volatile uint32 TIM4_CH2_IRQ:1;
    volatile uint32 TIM4_CH3_IRQ:1;
    volatile uint32 TIM4_CH4_IRQ:1;
    volatile uint32 TIM4_CH5_IRQ:1;
    volatile uint32 TIM4_CH6_IRQ:1;
    volatile uint32 TIM4_CH7_IRQ:1;
    volatile uint32 TIM5_CH0_IRQ:1;
    volatile uint32 TIM5_CH1_IRQ:1;
    volatile uint32 TIM5_CH2_IRQ:1;
    volatile uint32 TIM5_CH3_IRQ:1;
    volatile uint32 TIM5_CH4_IRQ:1;
    volatile uint32 TIM5_CH5_IRQ:1;
    volatile uint32 TIM5_CH6_IRQ:1;
    volatile uint32 TIM5_CH7_IRQ:1;
    volatile uint32 TIM6_CH0_IRQ:1;
    volatile uint32 TIM6_CH1_IRQ:1;
    volatile uint32 TIM6_CH2_IRQ:1;
    volatile uint32 TIM6_CH3_IRQ:1;
    volatile uint32 TIM6_CH4_IRQ:1;
    volatile uint32 TIM6_CH5_IRQ:1;
    volatile uint32 TIM6_CH6_IRQ:1;
    volatile uint32 TIM6_CH7_IRQ:1;
    volatile uint32 TIM7_CH0_IRQ:1;
    volatile uint32 TIM7_CH1_IRQ:1;
    volatile uint32 TIM7_CH2_IRQ:1;
    volatile uint32 TIM7_CH3_IRQ:1;
    volatile uint32 TIM7_CH4_IRQ:1;
    volatile uint32 TIM7_CH5_IRQ:1;
    volatile uint32 TIM7_CH6_IRQ:1;
    volatile uint32 TIM7_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_3_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_3_bf_type B;
} GTM_ICM_IRQG_3_bf_type;

typedef struct {
    volatile uint32 MCS0_CH0_IRQ:1;
    volatile uint32 MCS0_CH1_IRQ:1;
    volatile uint32 MCS0_CH2_IRQ:1;
    volatile uint32 MCS0_CH3_IRQ:1;
    volatile uint32 MCS0_CH4_IRQ:1;
    volatile uint32 MCS0_CH5_IRQ:1;
    volatile uint32 MCS0_CH6_IRQ:1;
    volatile uint32 MCS0_CH7_IRQ:1;
    volatile uint32 MCS1_CH0_IRQ:1;
    volatile uint32 MCS1_CH1_IRQ:1;
    volatile uint32 MCS1_CH2_IRQ:1;
    volatile uint32 MCS1_CH3_IRQ:1;
    volatile uint32 MCS1_CH4_IRQ:1;
    volatile uint32 MCS1_CH5_IRQ:1;
    volatile uint32 MCS1_CH6_IRQ:1;
    volatile uint32 MCS1_CH7_IRQ:1;
    volatile uint32 MCS2_CH0_IRQ:1;
    volatile uint32 MCS2_CH1_IRQ:1;
    volatile uint32 MCS2_CH2_IRQ:1;
    volatile uint32 MCS2_CH3_IRQ:1;
    volatile uint32 MCS2_CH4_IRQ:1;
    volatile uint32 MCS2_CH5_IRQ:1;
    volatile uint32 MCS2_CH6_IRQ:1;
    volatile uint32 MCS2_CH7_IRQ:1;
    volatile uint32 MCS3_CH0_IRQ:1;
    volatile uint32 MCS3_CH1_IRQ:1;
    volatile uint32 MCS3_CH2_IRQ:1;
    volatile uint32 MCS3_CH3_IRQ:1;
    volatile uint32 MCS3_CH4_IRQ:1;
    volatile uint32 MCS3_CH5_IRQ:1;
    volatile uint32 MCS3_CH6_IRQ:1;
    volatile uint32 MCS3_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_4_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_4_bf_type B;
} GTM_ICM_IRQG_4_bf_type;

typedef struct {
    volatile uint32 MCS4_CH0_IRQ:1;
    volatile uint32 MCS4_CH1_IRQ:1;
    volatile uint32 MCS4_CH2_IRQ:1;
    volatile uint32 MCS4_CH3_IRQ:1;
    volatile uint32 MCS4_CH4_IRQ:1;
    volatile uint32 MCS4_CH5_IRQ:1;
    volatile uint32 MCS4_CH6_IRQ:1;
    volatile uint32 MCS4_CH7_IRQ:1;
    volatile uint32 MCS5_CH0_IRQ:1;
    volatile uint32 MCS5_CH1_IRQ:1;
    volatile uint32 MCS5_CH2_IRQ:1;
    volatile uint32 MCS5_CH3_IRQ:1;
    volatile uint32 MCS5_CH4_IRQ:1;
    volatile uint32 MCS5_CH5_IRQ:1;
    volatile uint32 MCS5_CH6_IRQ:1;
    volatile uint32 MCS5_CH7_IRQ:1;
    volatile uint32 MCS6_CH0_IRQ:1;
    volatile uint32 MCS6_CH1_IRQ:1;
    volatile uint32 MCS6_CH2_IRQ:1;
    volatile uint32 MCS6_CH3_IRQ:1;
    volatile uint32 MCS6_CH4_IRQ:1;
    volatile uint32 MCS6_CH5_IRQ:1;
    volatile uint32 MCS6_CH6_IRQ:1;
    volatile uint32 MCS6_CH7_IRQ:1;
    volatile uint32 MCS7_CH0_IRQ:1;
    volatile uint32 MCS7_CH1_IRQ:1;
    volatile uint32 MCS7_CH2_IRQ:1;
    volatile uint32 MCS7_CH3_IRQ:1;
    volatile uint32 MCS7_CH4_IRQ:1;
    volatile uint32 MCS7_CH5_IRQ:1;
    volatile uint32 MCS7_CH6_IRQ:1;
    volatile uint32 MCS7_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_5_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_5_bf_type B;
} GTM_ICM_IRQG_5_bf_type;

typedef struct {
    volatile uint32 TOM0_CH0_IRQ:1;
    volatile uint32 TOM0_CH1_IRQ:1;
    volatile uint32 TOM0_CH2_IRQ:1;
    volatile uint32 TOM0_CH3_IRQ:1;
    volatile uint32 TOM0_CH4_IRQ:1;
    volatile uint32 TOM0_CH5_IRQ:1;
    volatile uint32 TOM0_CH6_IRQ:1;
    volatile uint32 TOM0_CH7_IRQ:1;
    volatile uint32 TOM0_CH8_IRQ:1;
    volatile uint32 TOM0_CH9_IRQ:1;
    volatile uint32 TOM0_CH10_IRQ:1;
    volatile uint32 TOM0_CH11_IRQ:1;
    volatile uint32 TOM0_CH12_IRQ:1;
    volatile uint32 TOM0_CH13_IRQ:1;
    volatile uint32 TOM0_CH14_IRQ:1;
    volatile uint32 TOM0_CH15_IRQ:1;
    volatile uint32 TOM1_CH0_IRQ:1;
    volatile uint32 TOM1_CH1_IRQ:1;
    volatile uint32 TOM1_CH2_IRQ:1;
    volatile uint32 TOM1_CH3_IRQ:1;
    volatile uint32 TOM1_CH4_IRQ:1;
    volatile uint32 TOM1_CH5_IRQ:1;
    volatile uint32 TOM1_CH6_IRQ:1;
    volatile uint32 TOM1_CH7_IRQ:1;
    volatile uint32 TOM1_CH8_IRQ:1;
    volatile uint32 TOM1_CH9_IRQ:1;
    volatile uint32 TOM1_CH10_IRQ:1;
    volatile uint32 TOM1_CH11_IRQ:1;
    volatile uint32 TOM1_CH12_IRQ:1;
    volatile uint32 TOM1_CH13_IRQ:1;
    volatile uint32 TOM1_CH14_IRQ:1;
    volatile uint32 TOM1_CH15_IRQ:1;
}  bf_GTM_ICM_IRQG_6_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_6_bf_type B;
} GTM_ICM_IRQG_6_bf_type;

typedef struct {
    volatile uint32 TOM2_CH0_IRQ:1;
    volatile uint32 TOM2_CH1_IRQ:1;
    volatile uint32 TOM2_CH2_IRQ:1;
    volatile uint32 TOM2_CH3_IRQ:1;
    volatile uint32 TOM2_CH4_IRQ:1;
    volatile uint32 TOM2_CH5_IRQ:1;
    volatile uint32 TOM2_CH6_IRQ:1;
    volatile uint32 TOM2_CH7_IRQ:1;
    volatile uint32 TOM2_CH8_IRQ:1;
    volatile uint32 TOM2_CH9_IRQ:1;
    volatile uint32 TOM2_CH10_IRQ:1;
    volatile uint32 TOM2_CH11_IRQ:1;
    volatile uint32 TOM2_CH12_IRQ:1;
    volatile uint32 TOM2_CH13_IRQ:1;
    volatile uint32 TOM2_CH14_IRQ:1;
    volatile uint32 TOM2_CH15_IRQ:1;
    volatile uint32 TOM3_CH0_IRQ:1;
    volatile uint32 TOM3_CH1_IRQ:1;
    volatile uint32 TOM3_CH2_IRQ:1;
    volatile uint32 TOM3_CH3_IRQ:1;
    volatile uint32 TOM3_CH4_IRQ:1;
    volatile uint32 TOM3_CH5_IRQ:1;
    volatile uint32 TOM3_CH6_IRQ:1;
    volatile uint32 TOM3_CH7_IRQ:1;
    volatile uint32 TOM3_CH8_IRQ:1;
    volatile uint32 TOM3_CH9_IRQ:1;
    volatile uint32 TOM3_CH10_IRQ:1;
    volatile uint32 TOM3_CH11_IRQ:1;
    volatile uint32 TOM3_CH12_IRQ:1;
    volatile uint32 TOM3_CH13_IRQ:1;
    volatile uint32 TOM3_CH14_IRQ:1;
    volatile uint32 TOM3_CH15_IRQ:1;
}  bf_GTM_ICM_IRQG_7_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_7_bf_type B;
} GTM_ICM_IRQG_7_bf_type;

typedef struct {
    volatile uint32 TOM4_CH0_IRQ:1;
    volatile uint32 TOM4_CH1_IRQ:1;
    volatile uint32 TOM4_CH2_IRQ:1;
    volatile uint32 TOM4_CH3_IRQ:1;
    volatile uint32 TOM4_CH4_IRQ:1;
    volatile uint32 TOM4_CH5_IRQ:1;
    volatile uint32 TOM4_CH6_IRQ:1;
    volatile uint32 TOM4_CH7_IRQ:1;
    volatile uint32 TOM4_CH8_IRQ:1;
    volatile uint32 TOM4_CH9_IRQ:1;
    volatile uint32 TOM4_CH10_IRQ:1;
    volatile uint32 TOM4_CH11_IRQ:1;
    volatile uint32 TOM4_CH12_IRQ:1;
    volatile uint32 TOM4_CH13_IRQ:1;
    volatile uint32 TOM4_CH14_IRQ:1;
    volatile uint32 TOM4_CH15_IRQ:1;
    volatile uint32 TOM5_CH0_IRQ:1;
    volatile uint32 TOM5_CH1_IRQ:1;
    volatile uint32 TOM5_CH2_IRQ:1;
    volatile uint32 TOM5_CH3_IRQ:1;
    volatile uint32 TOM5_CH4_IRQ:1;
    volatile uint32 TOM5_CH5_IRQ:1;
    volatile uint32 TOM5_CH6_IRQ:1;
    volatile uint32 TOM5_CH7_IRQ:1;
    volatile uint32 TOM5_CH8_IRQ:1;
    volatile uint32 TOM5_CH9_IRQ:1;
    volatile uint32 TOM5_CH10_IRQ:1;
    volatile uint32 TOM5_CH11_IRQ:1;
    volatile uint32 TOM5_CH12_IRQ:1;
    volatile uint32 TOM5_CH13_IRQ:1;
    volatile uint32 TOM5_CH14_IRQ:1;
    volatile uint32 TOM5_CH15_IRQ:1;
}  bf_GTM_ICM_IRQG_8_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_8_bf_type B;
} GTM_ICM_IRQG_8_bf_type;

typedef struct {
    volatile uint32 ATOM0_CH0_IRQ:1;
    volatile uint32 ATOM0_CH1_IRQ:1;
    volatile uint32 ATOM0_CH2_IRQ:1;
    volatile uint32 ATOM0_CH3_IRQ:1;
    volatile uint32 ATOM0_CH4_IRQ:1;
    volatile uint32 ATOM0_CH5_IRQ:1;
    volatile uint32 ATOM0_CH6_IRQ:1;
    volatile uint32 ATOM0_CH7_IRQ:1;
    volatile uint32 ATOM1_CH0_IRQ:1;
    volatile uint32 ATOM1_CH1_IRQ:1;
    volatile uint32 ATOM1_CH2_IRQ:1;
    volatile uint32 ATOM1_CH3_IRQ:1;
    volatile uint32 ATOM1_CH4_IRQ:1;
    volatile uint32 ATOM1_CH5_IRQ:1;
    volatile uint32 ATOM1_CH6_IRQ:1;
    volatile uint32 ATOM1_CH7_IRQ:1;
    volatile uint32 ATOM2_CH0_IRQ:1;
    volatile uint32 ATOM2_CH1_IRQ:1;
    volatile uint32 ATOM2_CH2_IRQ:1;
    volatile uint32 ATOM2_CH3_IRQ:1;
    volatile uint32 ATOM2_CH4_IRQ:1;
    volatile uint32 ATOM2_CH5_IRQ:1;
    volatile uint32 ATOM2_CH6_IRQ:1;
    volatile uint32 ATOM2_CH7_IRQ:1;
    volatile uint32 ATOM3_CH0_IRQ:1;
    volatile uint32 ATOM3_CH1_IRQ:1;
    volatile uint32 ATOM3_CH2_IRQ:1;
    volatile uint32 ATOM3_CH3_IRQ:1;
    volatile uint32 ATOM3_CH4_IRQ:1;
    volatile uint32 ATOM3_CH5_IRQ:1;
    volatile uint32 ATOM3_CH6_IRQ:1;
    volatile uint32 ATOM3_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_9_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_9_bf_type B;
} GTM_ICM_IRQG_9_bf_type;

typedef struct {
    volatile uint32 ATOM4_CH0_IRQ:1;
    volatile uint32 ATOM4_CH1_IRQ:1;
    volatile uint32 ATOM4_CH2_IRQ:1;
    volatile uint32 ATOM4_CH3_IRQ:1;
    volatile uint32 ATOM4_CH4_IRQ:1;
    volatile uint32 ATOM4_CH5_IRQ:1;
    volatile uint32 ATOM4_CH6_IRQ:1;
    volatile uint32 ATOM4_CH7_IRQ:1;
    volatile uint32 ATOM5_CH0_IRQ:1;
    volatile uint32 ATOM5_CH1_IRQ:1;
    volatile uint32 ATOM5_CH2_IRQ:1;
    volatile uint32 ATOM5_CH3_IRQ:1;
    volatile uint32 ATOM5_CH4_IRQ:1;
    volatile uint32 ATOM5_CH5_IRQ:1;
    volatile uint32 ATOM5_CH6_IRQ:1;
    volatile uint32 ATOM5_CH7_IRQ:1;
    volatile uint32 ATOM6_CH0_IRQ:1;
    volatile uint32 ATOM6_CH1_IRQ:1;
    volatile uint32 ATOM6_CH2_IRQ:1;
    volatile uint32 ATOM6_CH3_IRQ:1;
    volatile uint32 ATOM6_CH4_IRQ:1;
    volatile uint32 ATOM6_CH5_IRQ:1;
    volatile uint32 ATOM6_CH6_IRQ:1;
    volatile uint32 ATOM6_CH7_IRQ:1;
    volatile uint32 ATOM7_CH0_IRQ:1;
    volatile uint32 ATOM7_CH1_IRQ:1;
    volatile uint32 ATOM7_CH2_IRQ:1;
    volatile uint32 ATOM7_CH3_IRQ:1;
    volatile uint32 ATOM7_CH4_IRQ:1;
    volatile uint32 ATOM7_CH5_IRQ:1;
    volatile uint32 ATOM7_CH6_IRQ:1;
    volatile uint32 ATOM7_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_10_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_10_bf_type B;
} GTM_ICM_IRQG_10_bf_type;

typedef struct {
    volatile uint32 ATOM8_CH0_IRQ:1;
    volatile uint32 ATOM8_CH1_IRQ:1;
    volatile uint32 ATOM8_CH2_IRQ:1;
    volatile uint32 ATOM8_CH3_IRQ:1;
    volatile uint32 ATOM8_CH4_IRQ:1;
    volatile uint32 ATOM8_CH5_IRQ:1;
    volatile uint32 ATOM8_CH6_IRQ:1;
    volatile uint32 ATOM8_CH7_IRQ:1;
    volatile uint32 ATOM9_CH0_IRQ:1;
    volatile uint32 ATOM9_CH1_IRQ:1;
    volatile uint32 ATOM9_CH2_IRQ:1;
    volatile uint32 ATOM9_CH3_IRQ:1;
    volatile uint32 ATOM9_CH4_IRQ:1;
    volatile uint32 ATOM9_CH5_IRQ:1;
    volatile uint32 ATOM9_CH6_IRQ:1;
    volatile uint32 ATOM9_CH7_IRQ:1;
    volatile uint32 ATOM10_CH0_IRQ:1;
    volatile uint32 ATOM10_CH1_IRQ:1;
    volatile uint32 ATOM10_CH2_IRQ:1;
    volatile uint32 ATOM10_CH3_IRQ:1;
    volatile uint32 ATOM10_CH4_IRQ:1;
    volatile uint32 ATOM10_CH5_IRQ:1;
    volatile uint32 ATOM10_CH6_IRQ:1;
    volatile uint32 ATOM10_CH7_IRQ:1;
    volatile uint32 ATOM11_CH0_IRQ:1;
    volatile uint32 ATOM11_CH1_IRQ:1;
    volatile uint32 ATOM11_CH2_IRQ:1;
    volatile uint32 ATOM11_CH3_IRQ:1;
    volatile uint32 ATOM11_CH4_IRQ:1;
    volatile uint32 ATOM11_CH5_IRQ:1;
    volatile uint32 ATOM11_CH6_IRQ:1;
    volatile uint32 ATOM11_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_11_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_11_bf_type B;
} GTM_ICM_IRQG_11_bf_type;

typedef struct {
    volatile uint32 GTM_EIRQ:1;
    volatile uint32 BRC_EIRQ:1;
    volatile uint32 FIFO0_EIRQ:1;
    volatile uint32 FIFO1_EIRQ:1;
    volatile uint32 TIM0_EIRQ:1;
    volatile uint32 TIM1_EIRQ:1;
    volatile uint32 TIM2_EIRQ:1;
    volatile uint32 TIM3_EIRQ:1;
    volatile uint32 TIM4_EIRQ:1;
    volatile uint32 TIM5_EIRQ:1;
    volatile uint32 TIM6_EIRQ:1;
    volatile uint32 TIM7_EIRQ:1;
    volatile uint32 MCS0_EIRQ:1;
    volatile uint32 MCS1_EIRQ:1;
    volatile uint32 MCS2_EIRQ:1;
    volatile uint32 MCS3_EIRQ:1;
    volatile uint32 MCS4_EIRQ:1;
    volatile uint32 MCS5_EIRQ:1;
    volatile uint32 MCS6_EIRQ:1;
    volatile uint32 MCS7_EIRQ:1;
    volatile uint32 SPE0_EIRQ:1;
    volatile uint32 SPE1_EIRQ:1;
    volatile uint32 SPE2_EIRQ:1;
    volatile uint32 SPE3_EIRQ:1;
    volatile uint32 CMP_EIRQ:1;
    volatile uint32 DPLL_EIRQ:1;
    uint32 reserved_0:6;
}  bf_GTM_ICM_IRQG_MEI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_MEI_bf_type B;
} GTM_ICM_IRQG_MEI_bf_type;

typedef struct {
    volatile uint32 FIFO0_CH0_EIRQ:1;
    volatile uint32 FIFO0_CH1_EIRQ:1;
    volatile uint32 FIFO0_CH2_EIRQ:1;
    volatile uint32 FIFO0_CH3_EIRQ:1;
    volatile uint32 FIFO0_CH4_EIRQ:1;
    volatile uint32 FIFO0_CH5_EIRQ:1;
    volatile uint32 FIFO0_CH6_EIRQ:1;
    volatile uint32 FIFO0_CH7_EIRQ:1;
    volatile uint32 FIFO1_CH0_EIRQ:1;
    volatile uint32 FIFO1_CH1_EIRQ:1;
    volatile uint32 FIFO1_CH2_EIRQ:1;
    volatile uint32 FIFO1_CH3_EIRQ:1;
    volatile uint32 FIFO1_CH4_EIRQ:1;
    volatile uint32 FIFO1_CH5_EIRQ:1;
    volatile uint32 FIFO1_CH6_EIRQ:1;
    volatile uint32 FIFO1_CH7_EIRQ:1;
    volatile uint32 FIFO2_CH0_EIRQ:1;
    volatile uint32 FIFO2_CH1_EIRQ:1;
    volatile uint32 FIFO2_CH2_EIRQ:1;
    volatile uint32 FIFO2_CH3_EIRQ:1;
    volatile uint32 FIFO2_CH4_EIRQ:1;
    volatile uint32 FIFO2_CH5_EIRQ:1;
    volatile uint32 FIFO2_CH6_EIRQ:1;
    volatile uint32 FIFO2_CH7_EIRQ:1;
    uint32 reserved_0:8;
}  bf_GTM_ICM_IRQG_CEI0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_CEI0_bf_type B;
} GTM_ICM_IRQG_CEI0_bf_type;

typedef struct {
    volatile uint32 TIM0_CH0_EIRQ:1;
    volatile uint32 TIM0_CH1_EIRQ:1;
    volatile uint32 TIM0_CH2_EIRQ:1;
    volatile uint32 TIM0_CH3_EIRQ:1;
    volatile uint32 TIM0_CH4_EIRQ:1;
    volatile uint32 TIM0_CH5_EIRQ:1;
    volatile uint32 TIM0_CH6_EIRQ:1;
    volatile uint32 TIM0_CH7_EIRQ:1;
    volatile uint32 TIM1_CH0_EIRQ:1;
    volatile uint32 TIM1_CH1_EIRQ:1;
    volatile uint32 TIM1_CH2_EIRQ:1;
    volatile uint32 TIM1_CH3_EIRQ:1;
    volatile uint32 TIM1_CH4_EIRQ:1;
    volatile uint32 TIM1_CH5_EIRQ:1;
    volatile uint32 TIM1_CH6_EIRQ:1;
    volatile uint32 TIM1_CH7_EIRQ:1;
    volatile uint32 TIM2_CH0_EIRQ:1;
    volatile uint32 TIM2_CH1_EIRQ:1;
    volatile uint32 TIM2_CH2_EIRQ:1;
    volatile uint32 TIM2_CH3_EIRQ:1;
    volatile uint32 TIM2_CH4_EIRQ:1;
    volatile uint32 TIM2_CH5_EIRQ:1;
    volatile uint32 TIM2_CH6_EIRQ:1;
    volatile uint32 TIM2_CH7_EIRQ:1;
    volatile uint32 TIM3_CH0_EIRQ:1;
    volatile uint32 TIM3_CH1_EIRQ:1;
    volatile uint32 TIM3_CH2_EIRQ:1;
    volatile uint32 TIM3_CH3_EIRQ:1;
    volatile uint32 TIM3_CH4_EIRQ:1;
    volatile uint32 TIM3_CH5_EIRQ:1;
    volatile uint32 TIM3_CH6_EIRQ:1;
    volatile uint32 TIM3_CH7_EIRQ:1;
}  bf_GTM_ICM_IRQG_CEI1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_CEI1_bf_type B;
} GTM_ICM_IRQG_CEI1_bf_type;

typedef struct {
    volatile uint32 TIM4_CH0_EIRQ:1;
    volatile uint32 TIM4_CH1_EIRQ:1;
    volatile uint32 TIM4_CH2_EIRQ:1;
    volatile uint32 TIM4_CH3_EIRQ:1;
    volatile uint32 TIM4_CH4_EIRQ:1;
    volatile uint32 TIM4_CH5_EIRQ:1;
    volatile uint32 TIM4_CH6_EIRQ:1;
    volatile uint32 TIM4_CH7_EIRQ:1;
    volatile uint32 TIM5_CH0_EIRQ:1;
    volatile uint32 TIM5_CH1_EIRQ:1;
    volatile uint32 TIM5_CH2_EIRQ:1;
    volatile uint32 TIM5_CH3_EIRQ:1;
    volatile uint32 TIM5_CH4_EIRQ:1;
    volatile uint32 TIM5_CH5_EIRQ:1;
    volatile uint32 TIM5_CH6_EIRQ:1;
    volatile uint32 TIM5_CH7_EIRQ:1;
    volatile uint32 TIM6_CH0_EIRQ:1;
    volatile uint32 TIM6_CH1_EIRQ:1;
    volatile uint32 TIM6_CH2_EIRQ:1;
    volatile uint32 TIM6_CH3_EIRQ:1;
    volatile uint32 TIM6_CH4_EIRQ:1;
    volatile uint32 TIM6_CH5_EIRQ:1;
    volatile uint32 TIM6_CH6_EIRQ:1;
    volatile uint32 TIM6_CH7_EIRQ:1;
    volatile uint32 TIM7_CH0_EIRQ:1;
    volatile uint32 TIM7_CH1_EIRQ:1;
    volatile uint32 TIM7_CH2_EIRQ:1;
    volatile uint32 TIM7_CH3_EIRQ:1;
    volatile uint32 TIM7_CH4_EIRQ:1;
    volatile uint32 TIM7_CH5_EIRQ:1;
    volatile uint32 TIM7_CH6_EIRQ:1;
    volatile uint32 TIM7_CH7_EIRQ:1;
}  bf_GTM_ICM_IRQG_CEI2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_CEI2_bf_type B;
} GTM_ICM_IRQG_CEI2_bf_type;

typedef struct {
    volatile uint32 MCS0_CH0_EIRQ:1;
    volatile uint32 MCS0_CH1_EIRQ:1;
    volatile uint32 MCS0_CH2_EIRQ:1;
    volatile uint32 MCS0_CH3_EIRQ:1;
    volatile uint32 MCS0_CH4_EIRQ:1;
    volatile uint32 MCS0_CH5_EIRQ:1;
    volatile uint32 MCS0_CH6_EIRQ:1;
    volatile uint32 MCS0_CH7_EIRQ:1;
    volatile uint32 MCS1_CH0_EIRQ:1;
    volatile uint32 MCS1_CH1_EIRQ:1;
    volatile uint32 MCS1_CH2_EIRQ:1;
    volatile uint32 MCS1_CH3_EIRQ:1;
    volatile uint32 MCS1_CH4_EIRQ:1;
    volatile uint32 MCS1_CH5_EIRQ:1;
    volatile uint32 MCS1_CH6_EIRQ:1;
    volatile uint32 MCS1_CH7_EIRQ:1;
    volatile uint32 MCS2_CH0_EIRQ:1;
    volatile uint32 MCS2_CH1_EIRQ:1;
    volatile uint32 MCS2_CH2_EIRQ:1;
    volatile uint32 MCS2_CH3_EIRQ:1;
    volatile uint32 MCS2_CH4_EIRQ:1;
    volatile uint32 MCS2_CH5_EIRQ:1;
    volatile uint32 MCS2_CH6_EIRQ:1;
    volatile uint32 MCS2_CH7_EIRQ:1;
    volatile uint32 MCS3_CH0_EIRQ:1;
    volatile uint32 MCS3_CH1_EIRQ:1;
    volatile uint32 MCS3_CH2_EIRQ:1;
    volatile uint32 MCS3_CH3_EIRQ:1;
    volatile uint32 MCS3_CH4_EIRQ:1;
    volatile uint32 MCS3_CH5_EIRQ:1;
    volatile uint32 MCS3_CH6_EIRQ:1;
    volatile uint32 MCS3_CH7_EIRQ:1;
}  bf_GTM_ICM_IRQG_CEI3_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_CEI3_bf_type B;
} GTM_ICM_IRQG_CEI3_bf_type;

typedef struct {
    volatile uint32 MCS4_CH0_EIRQ:1;
    volatile uint32 MCS4_CH1_EIRQ:1;
    volatile uint32 MCS4_CH2_EIRQ:1;
    volatile uint32 MCS4_CH3_EIRQ:1;
    volatile uint32 MCS4_CH4_EIRQ:1;
    volatile uint32 MCS4_CH5_EIRQ:1;
    volatile uint32 MCS4_CH6_EIRQ:1;
    volatile uint32 MCS4_CH7_EIRQ:1;
    volatile uint32 MCS5_CH0_EIRQ:1;
    volatile uint32 MCS5_CH1_EIRQ:1;
    volatile uint32 MCS5_CH2_EIRQ:1;
    volatile uint32 MCS5_CH3_EIRQ:1;
    volatile uint32 MCS5_CH4_EIRQ:1;
    volatile uint32 MCS5_CH5_EIRQ:1;
    volatile uint32 MCS5_CH6_EIRQ:1;
    volatile uint32 MCS5_CH7_EIRQ:1;
    volatile uint32 MCS6_CH0_EIRQ:1;
    volatile uint32 MCS6_CH1_EIRQ:1;
    volatile uint32 MCS6_CH2_EIRQ:1;
    volatile uint32 MCS6_CH3_EIRQ:1;
    volatile uint32 MCS6_CH4_EIRQ:1;
    volatile uint32 MCS6_CH5_EIRQ:1;
    volatile uint32 MCS6_CH6_EIRQ:1;
    volatile uint32 MCS6_CH7_EIRQ:1;
    volatile uint32 MCS7_CH0_EIRQ:1;
    volatile uint32 MCS7_CH1_EIRQ:1;
    volatile uint32 MCS7_CH2_EIRQ:1;
    volatile uint32 MCS7_CH3_EIRQ:1;
    volatile uint32 MCS7_CH4_EIRQ:1;
    volatile uint32 MCS7_CH5_EIRQ:1;
    volatile uint32 MCS7_CH6_EIRQ:1;
    volatile uint32 MCS7_CH7_EIRQ:1;
}  bf_GTM_ICM_IRQG_CEI4_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_CEI4_bf_type B;
} GTM_ICM_IRQG_CEI4_bf_type;

typedef struct {
    volatile uint32 MCS_CH0_EIRQ:1;
    volatile uint32 MCS_CH1_EIRQ:1;
    volatile uint32 MCS_CH2_EIRQ:1;
    volatile uint32 MCS_CH3_EIRQ:1;
    volatile uint32 MCS_CH4_EIRQ:1;
    volatile uint32 MCS_CH5_EIRQ:1;
    volatile uint32 MCS_CH6_EIRQ:1;
    volatile uint32 MCS_CH7_EIRQ:1;
    uint32 reserved_0:24;
}  bf_GTM_ICM_IRQG_MCS_CEI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_MCS_CEI_bf_type B;
} GTM_ICM_IRQG_MCS_CEI_bf_type;

typedef struct {
    volatile uint32 PSM_M0_CH0_EIRQ:1;
    volatile uint32 PSM_M0_CH1_EIRQ:1;
    volatile uint32 PSM_M0_CH2_EIRQ:1;
    volatile uint32 PSM_M0_CH3_EIRQ:1;
    volatile uint32 PSM_M0_CH4_EIRQ:1;
    volatile uint32 PSM_M0_CH5_EIRQ:1;
    volatile uint32 PSM_M0_CH6_EIRQ:1;
    volatile uint32 PSM_M0_CH7_EIRQ:1;
    volatile uint32 PSM_M1_CH0_EIRQ:1;
    volatile uint32 PSM_M1_CH1_EIRQ:1;
    volatile uint32 PSM_M1_CH2_EIRQ:1;
    volatile uint32 PSM_M1_CH3_EIRQ:1;
    volatile uint32 PSM_M1_CH4_EIRQ:1;
    volatile uint32 PSM_M1_CH5_EIRQ:1;
    volatile uint32 PSM_M1_CH6_EIRQ:1;
    volatile uint32 PSM_M1_CH7_EIRQ:1;
    volatile uint32 PSM_M2_CH0_EIRQ:1;
    volatile uint32 PSM_M2_CH1_EIRQ:1;
    volatile uint32 PSM_M2_CH2_EIRQ:1;
    volatile uint32 PSM_M2_CH3_EIRQ:1;
    volatile uint32 PSM_M2_CH4_EIRQ:1;
    volatile uint32 PSM_M2_CH5_EIRQ:1;
    volatile uint32 PSM_M2_CH6_EIRQ:1;
    volatile uint32 PSM_M2_CH7_EIRQ:1;
    uint32 reserved_0:8;
}  bf_GTM_ICM_IRQG_PSM_0_CEI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_PSM_0_CEI_bf_type B;
} GTM_ICM_IRQG_PSM_0_CEI_bf_type;

typedef struct {
    volatile uint32 SPE0_EIRQ:1;
    volatile uint32 SPE1_EIRQ:1;
    volatile uint32 SPE2_EIRQ:1;
    volatile uint32 SPE3_EIRQ:1;
    volatile uint32 SPE4_EIRQ:1;
    volatile uint32 SPE5_EIRQ:1;
    uint32 reserved_0:26;
}  bf_GTM_ICM_IRQG_SPE_CEI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_SPE_CEI_bf_type B;
} GTM_ICM_IRQG_SPE_CEI_bf_type;

typedef struct {
    volatile uint32 TIM_M0_EIRQ:1;
    volatile uint32 MCS_M0_EIRQ:1;
    volatile uint32 SPE_M0_EIRQ:1;
    volatile uint32 FIFO_M0_EIRQ:1;
    uint32 reserved_3:4;
    volatile uint32 TIM_M1_EIRQ:1;
    volatile uint32 MCS_M1_EIRQ:1;
    volatile uint32 SPE_M1_EIRQ:1;
    volatile uint32 FIFO_M1_EIRQ:1;
    uint32 reserved_2:4;
    volatile uint32 TIM_M2_EIRQ:1;
    volatile uint32 MCS_M2_EIRQ:1;
    volatile uint32 SPE_M2_EIRQ:1;
    volatile uint32 FIFO_M2_EIRQ:1;
    uint32 reserved_1:4;
    volatile uint32 TIM_M3_EIRQ:1;
    volatile uint32 MCS_M3_EIRQ:1;
    volatile uint32 SPE_M3_EIRQ:1;
    volatile uint32 FIFO_M3_EIRQ:1;
    uint32 reserved_0:4;
}  bf_GTM_ICM_IRQG_CLS_0_MEI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_CLS_0_MEI_bf_type B;
} GTM_ICM_IRQG_CLS_0_MEI_bf_type;

typedef struct {
    volatile uint32 TIM_M0_EIRQ:1;
    volatile uint32 MCS_M0_EIRQ:1;
    volatile uint32 SPE_M0_EIRQ:1;
    volatile uint32 FIFO_M0_EIRQ:1;
    uint32 reserved_3:4;
    volatile uint32 TIM_M1_EIRQ:1;
    volatile uint32 MCS_M1_EIRQ:1;
    volatile uint32 SPE_M1_EIRQ:1;
    volatile uint32 FIFO_M1_EIRQ:1;
    uint32 reserved_2:4;
    volatile uint32 TIM_M2_EIRQ:1;
    volatile uint32 MCS_M2_EIRQ:1;
    volatile uint32 SPE_M2_EIRQ:1;
    volatile uint32 FIFO_M2_EIRQ:1;
    uint32 reserved_1:4;
    volatile uint32 TIM_M3_EIRQ:1;
    volatile uint32 MCS_M3_EIRQ:1;
    volatile uint32 SPE_M3_EIRQ:1;
    volatile uint32 FIFO_M3_EIRQ:1;
    uint32 reserved_0:4;
}  bf_GTM_ICM_IRQG_CLS_1_MEI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_CLS_1_MEI_bf_type B;
} GTM_ICM_IRQG_CLS_1_MEI_bf_type;

typedef struct {
    volatile uint32 TIM_M0_EIRQ:1;
    volatile uint32 MCS_M0_EIRQ:1;
    volatile uint32 SPE_M0_EIRQ:1;
    volatile uint32 FIFO_M0_EIRQ:1;
    uint32 reserved_3:4;
    volatile uint32 TIM_M1_EIRQ:1;
    volatile uint32 MCS_M1_EIRQ:1;
    volatile uint32 SPE_M1_EIRQ:1;
    volatile uint32 FIFO_M1_EIRQ:1;
    uint32 reserved_2:4;
    volatile uint32 TIM_M2_EIRQ:1;
    volatile uint32 MCS_M2_EIRQ:1;
    volatile uint32 SPE_M2_EIRQ:1;
    volatile uint32 FIFO_M2_EIRQ:1;
    uint32 reserved_1:4;
    volatile uint32 TIM_M3_EIRQ:1;
    volatile uint32 MCS_M3_EIRQ:1;
    volatile uint32 SPE_M3_EIRQ:1;
    volatile uint32 FIFO_M3_EIRQ:1;
    uint32 reserved_0:4;
}  bf_GTM_ICM_IRQG_CLS_2_MEI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_CLS_2_MEI_bf_type B;
} GTM_ICM_IRQG_CLS_2_MEI_bf_type;

typedef struct {
    volatile uint32 MCS_CH0_IRQ:1;
    volatile uint32 MCS_CH1_IRQ:1;
    volatile uint32 MCS_CH2_IRQ:1;
    volatile uint32 MCS_CH3_IRQ:1;
    volatile uint32 MCS_CH4_IRQ:1;
    volatile uint32 MCS_CH5_IRQ:1;
    volatile uint32 MCS_CH6_IRQ:1;
    volatile uint32 MCS_CH7_IRQ:1;
    uint32 reserved_0:24;
}  bf_GTM_ICM_IRQG_MCS_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_MCS_CI_bf_type B;
} GTM_ICM_IRQG_MCS_CI_bf_type;

typedef struct {
    volatile uint32 PSM_M0_CH0_IRQ:1;
    volatile uint32 PSM_M0_CH1_IRQ:1;
    volatile uint32 PSM_M0_CH2_IRQ:1;
    volatile uint32 PSM_M0_CH3_IRQ:1;
    volatile uint32 PSM_M0_CH4_IRQ:1;
    volatile uint32 PSM_M0_CH5_IRQ:1;
    volatile uint32 PSM_M0_CH6_IRQ:1;
    volatile uint32 PSM_M0_CH7_IRQ:1;
    volatile uint32 PSM_M1_CH0_IRQ:1;
    volatile uint32 PSM_M1_CH1_IRQ:1;
    volatile uint32 PSM_M1_CH2_IRQ:1;
    volatile uint32 PSM_M1_CH3_IRQ:1;
    volatile uint32 PSM_M1_CH4_IRQ:1;
    volatile uint32 PSM_M1_CH5_IRQ:1;
    volatile uint32 PSM_M1_CH6_IRQ:1;
    volatile uint32 PSM_M1_CH7_IRQ:1;
    volatile uint32 PSM_M2_CH0_IRQ:1;
    volatile uint32 PSM_M2_CH1_IRQ:1;
    volatile uint32 PSM_M2_CH2_IRQ:1;
    volatile uint32 PSM_M2_CH3_IRQ:1;
    volatile uint32 PSM_M2_CH4_IRQ:1;
    volatile uint32 PSM_M2_CH5_IRQ:1;
    volatile uint32 PSM_M2_CH6_IRQ:1;
    volatile uint32 PSM_M2_CH7_IRQ:1;
    uint32 reserved_0:8;
}  bf_GTM_ICM_IRQG_PSM_0_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_PSM_0_CI_bf_type B;
} GTM_ICM_IRQG_PSM_0_CI_bf_type;

typedef struct {
    volatile uint32 SPE0_IRQ:1;
    volatile uint32 SPE1_IRQ:1;
    volatile uint32 SPE2_IRQ:1;
    volatile uint32 SPE3_IRQ:1;
    volatile uint32 SPE4_IRQ:1;
    volatile uint32 SPE5_IRQ:1;
    uint32 reserved_0:26;
}  bf_GTM_ICM_IRQG_SPE_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_SPE_CI_bf_type B;
} GTM_ICM_IRQG_SPE_CI_bf_type;

typedef struct {
    volatile uint32 ATOM_M0_CH0_IRQ:1;
    volatile uint32 ATOM_M0_CH1_IRQ:1;
    volatile uint32 ATOM_M0_CH2_IRQ:1;
    volatile uint32 ATOM_M0_CH3_IRQ:1;
    volatile uint32 ATOM_M0_CH4_IRQ:1;
    volatile uint32 ATOM_M0_CH5_IRQ:1;
    volatile uint32 ATOM_M0_CH6_IRQ:1;
    volatile uint32 ATOM_M0_CH7_IRQ:1;
    volatile uint32 ATOM_M1_CH0_IRQ:1;
    volatile uint32 ATOM_M1_CH1_IRQ:1;
    volatile uint32 ATOM_M1_CH2_IRQ:1;
    volatile uint32 ATOM_M1_CH3_IRQ:1;
    volatile uint32 ATOM_M1_CH4_IRQ:1;
    volatile uint32 ATOM_M1_CH5_IRQ:1;
    volatile uint32 ATOM_M1_CH6_IRQ:1;
    volatile uint32 ATOM_M1_CH7_IRQ:1;
    volatile uint32 ATOM_M2_CH0_IRQ:1;
    volatile uint32 ATOM_M2_CH1_IRQ:1;
    volatile uint32 ATOM_M2_CH2_IRQ:1;
    volatile uint32 ATOM_M2_CH3_IRQ:1;
    volatile uint32 ATOM_M2_CH4_IRQ:1;
    volatile uint32 ATOM_M2_CH5_IRQ:1;
    volatile uint32 ATOM_M2_CH6_IRQ:1;
    volatile uint32 ATOM_M2_CH7_IRQ:1;
    volatile uint32 ATOM_M3_CH0_IRQ:1;
    volatile uint32 ATOM_M3_CH1_IRQ:1;
    volatile uint32 ATOM_M3_CH2_IRQ:1;
    volatile uint32 ATOM_M3_CH3_IRQ:1;
    volatile uint32 ATOM_M3_CH4_IRQ:1;
    volatile uint32 ATOM_M3_CH5_IRQ:1;
    volatile uint32 ATOM_M3_CH6_IRQ:1;
    volatile uint32 ATOM_M3_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_ATOM_0_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_ATOM_0_CI_bf_type B;
} GTM_ICM_IRQG_ATOM_0_CI_bf_type;

typedef struct {
    volatile uint32 ATOM_M0_CH0_IRQ:1;
    volatile uint32 ATOM_M0_CH1_IRQ:1;
    volatile uint32 ATOM_M0_CH2_IRQ:1;
    volatile uint32 ATOM_M0_CH3_IRQ:1;
    volatile uint32 ATOM_M0_CH4_IRQ:1;
    volatile uint32 ATOM_M0_CH5_IRQ:1;
    volatile uint32 ATOM_M0_CH6_IRQ:1;
    volatile uint32 ATOM_M0_CH7_IRQ:1;
    volatile uint32 ATOM_M1_CH0_IRQ:1;
    volatile uint32 ATOM_M1_CH1_IRQ:1;
    volatile uint32 ATOM_M1_CH2_IRQ:1;
    volatile uint32 ATOM_M1_CH3_IRQ:1;
    volatile uint32 ATOM_M1_CH4_IRQ:1;
    volatile uint32 ATOM_M1_CH5_IRQ:1;
    volatile uint32 ATOM_M1_CH6_IRQ:1;
    volatile uint32 ATOM_M1_CH7_IRQ:1;
    volatile uint32 ATOM_M2_CH0_IRQ:1;
    volatile uint32 ATOM_M2_CH1_IRQ:1;
    volatile uint32 ATOM_M2_CH2_IRQ:1;
    volatile uint32 ATOM_M2_CH3_IRQ:1;
    volatile uint32 ATOM_M2_CH4_IRQ:1;
    volatile uint32 ATOM_M2_CH5_IRQ:1;
    volatile uint32 ATOM_M2_CH6_IRQ:1;
    volatile uint32 ATOM_M2_CH7_IRQ:1;
    volatile uint32 ATOM_M3_CH0_IRQ:1;
    volatile uint32 ATOM_M3_CH1_IRQ:1;
    volatile uint32 ATOM_M3_CH2_IRQ:1;
    volatile uint32 ATOM_M3_CH3_IRQ:1;
    volatile uint32 ATOM_M3_CH4_IRQ:1;
    volatile uint32 ATOM_M3_CH5_IRQ:1;
    volatile uint32 ATOM_M3_CH6_IRQ:1;
    volatile uint32 ATOM_M3_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_ATOM_1_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_ATOM_1_CI_bf_type B;
} GTM_ICM_IRQG_ATOM_1_CI_bf_type;

typedef struct {
    volatile uint32 ATOM_M0_CH0_IRQ:1;
    volatile uint32 ATOM_M0_CH1_IRQ:1;
    volatile uint32 ATOM_M0_CH2_IRQ:1;
    volatile uint32 ATOM_M0_CH3_IRQ:1;
    volatile uint32 ATOM_M0_CH4_IRQ:1;
    volatile uint32 ATOM_M0_CH5_IRQ:1;
    volatile uint32 ATOM_M0_CH6_IRQ:1;
    volatile uint32 ATOM_M0_CH7_IRQ:1;
    volatile uint32 ATOM_M1_CH0_IRQ:1;
    volatile uint32 ATOM_M1_CH1_IRQ:1;
    volatile uint32 ATOM_M1_CH2_IRQ:1;
    volatile uint32 ATOM_M1_CH3_IRQ:1;
    volatile uint32 ATOM_M1_CH4_IRQ:1;
    volatile uint32 ATOM_M1_CH5_IRQ:1;
    volatile uint32 ATOM_M1_CH6_IRQ:1;
    volatile uint32 ATOM_M1_CH7_IRQ:1;
    volatile uint32 ATOM_M2_CH0_IRQ:1;
    volatile uint32 ATOM_M2_CH1_IRQ:1;
    volatile uint32 ATOM_M2_CH2_IRQ:1;
    volatile uint32 ATOM_M2_CH3_IRQ:1;
    volatile uint32 ATOM_M2_CH4_IRQ:1;
    volatile uint32 ATOM_M2_CH5_IRQ:1;
    volatile uint32 ATOM_M2_CH6_IRQ:1;
    volatile uint32 ATOM_M2_CH7_IRQ:1;
    volatile uint32 ATOM_M3_CH0_IRQ:1;
    volatile uint32 ATOM_M3_CH1_IRQ:1;
    volatile uint32 ATOM_M3_CH2_IRQ:1;
    volatile uint32 ATOM_M3_CH3_IRQ:1;
    volatile uint32 ATOM_M3_CH4_IRQ:1;
    volatile uint32 ATOM_M3_CH5_IRQ:1;
    volatile uint32 ATOM_M3_CH6_IRQ:1;
    volatile uint32 ATOM_M3_CH7_IRQ:1;
}  bf_GTM_ICM_IRQG_ATOM_2_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_ATOM_2_CI_bf_type B;
} GTM_ICM_IRQG_ATOM_2_CI_bf_type;

typedef struct {
    volatile uint32 TOM_M0_CH0_IRQ:1;
    volatile uint32 TOM_M0_CH1_IRQ:1;
    volatile uint32 TOM_M0_CH2_IRQ:1;
    volatile uint32 TOM_M0_CH3_IRQ:1;
    volatile uint32 TOM_M0_CH4_IRQ:1;
    volatile uint32 TOM_M0_CH5_IRQ:1;
    volatile uint32 TOM_M0_CH6_IRQ:1;
    volatile uint32 TOM_M0_CH7_IRQ:1;
    volatile uint32 TOM_M0_CH8_IRQ:1;
    volatile uint32 TOM_M0_CH9_IRQ:1;
    volatile uint32 TOM_M0_CH10_IRQ:1;
    volatile uint32 TOM_M0_CH11_IRQ:1;
    volatile uint32 TOM_M0_CH12_IRQ:1;
    volatile uint32 TOM_M0_CH13_IRQ:1;
    volatile uint32 TOM_M0_CH14_IRQ:1;
    volatile uint32 TOM_M0_CH15_IRQ:1;
    volatile uint32 TOM_M1_CH0_IRQ:1;
    volatile uint32 TOM_M1_CH1_IRQ:1;
    volatile uint32 TOM_M1_CH2_IRQ:1;
    volatile uint32 TOM_M1_CH3_IRQ:1;
    volatile uint32 TOM_M1_CH4_IRQ:1;
    volatile uint32 TOM_M1_CH5_IRQ:1;
    volatile uint32 TOM_M1_CH6_IRQ:1;
    volatile uint32 TOM_M1_CH7_IRQ:1;
    volatile uint32 TOM_M1_CH8_IRQ:1;
    volatile uint32 TOM_M1_CH9_IRQ:1;
    volatile uint32 TOM_M1_CH10_IRQ:1;
    volatile uint32 TOM_M1_CH11_IRQ:1;
    volatile uint32 TOM_M1_CH12_IRQ:1;
    volatile uint32 TOM_M1_CH13_IRQ:1;
    volatile uint32 TOM_M1_CH14_IRQ:1;
    volatile uint32 TOM_M1_CH15_IRQ:1;
}  bf_GTM_ICM_IRQG_TOM_0_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_TOM_0_CI_bf_type B;
} GTM_ICM_IRQG_TOM_0_CI_bf_type;

typedef struct {
    volatile uint32 TOM_M0_CH0_IRQ:1;
    volatile uint32 TOM_M0_CH1_IRQ:1;
    volatile uint32 TOM_M0_CH2_IRQ:1;
    volatile uint32 TOM_M0_CH3_IRQ:1;
    volatile uint32 TOM_M0_CH4_IRQ:1;
    volatile uint32 TOM_M0_CH5_IRQ:1;
    volatile uint32 TOM_M0_CH6_IRQ:1;
    volatile uint32 TOM_M0_CH7_IRQ:1;
    volatile uint32 TOM_M0_CH8_IRQ:1;
    volatile uint32 TOM_M0_CH9_IRQ:1;
    volatile uint32 TOM_M0_CH10_IRQ:1;
    volatile uint32 TOM_M0_CH11_IRQ:1;
    volatile uint32 TOM_M0_CH12_IRQ:1;
    volatile uint32 TOM_M0_CH13_IRQ:1;
    volatile uint32 TOM_M0_CH14_IRQ:1;
    volatile uint32 TOM_M0_CH15_IRQ:1;
    volatile uint32 TOM_M1_CH0_IRQ:1;
    volatile uint32 TOM_M1_CH1_IRQ:1;
    volatile uint32 TOM_M1_CH2_IRQ:1;
    volatile uint32 TOM_M1_CH3_IRQ:1;
    volatile uint32 TOM_M1_CH4_IRQ:1;
    volatile uint32 TOM_M1_CH5_IRQ:1;
    volatile uint32 TOM_M1_CH6_IRQ:1;
    volatile uint32 TOM_M1_CH7_IRQ:1;
    volatile uint32 TOM_M1_CH8_IRQ:1;
    volatile uint32 TOM_M1_CH9_IRQ:1;
    volatile uint32 TOM_M1_CH10_IRQ:1;
    volatile uint32 TOM_M1_CH11_IRQ:1;
    volatile uint32 TOM_M1_CH12_IRQ:1;
    volatile uint32 TOM_M1_CH13_IRQ:1;
    volatile uint32 TOM_M1_CH14_IRQ:1;
    volatile uint32 TOM_M1_CH15_IRQ:1;
}  bf_GTM_ICM_IRQG_TOM_1_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_TOM_1_CI_bf_type B;
} GTM_ICM_IRQG_TOM_1_CI_bf_type;

typedef struct {
    volatile uint32 TOM_M0_CH0_IRQ:1;
    volatile uint32 TOM_M0_CH1_IRQ:1;
    volatile uint32 TOM_M0_CH2_IRQ:1;
    volatile uint32 TOM_M0_CH3_IRQ:1;
    volatile uint32 TOM_M0_CH4_IRQ:1;
    volatile uint32 TOM_M0_CH5_IRQ:1;
    volatile uint32 TOM_M0_CH6_IRQ:1;
    volatile uint32 TOM_M0_CH7_IRQ:1;
    volatile uint32 TOM_M0_CH8_IRQ:1;
    volatile uint32 TOM_M0_CH9_IRQ:1;
    volatile uint32 TOM_M0_CH10_IRQ:1;
    volatile uint32 TOM_M0_CH11_IRQ:1;
    volatile uint32 TOM_M0_CH12_IRQ:1;
    volatile uint32 TOM_M0_CH13_IRQ:1;
    volatile uint32 TOM_M0_CH14_IRQ:1;
    volatile uint32 TOM_M0_CH15_IRQ:1;
    volatile uint32 TOM_M1_CH0_IRQ:1;
    volatile uint32 TOM_M1_CH1_IRQ:1;
    volatile uint32 TOM_M1_CH2_IRQ:1;
    volatile uint32 TOM_M1_CH3_IRQ:1;
    volatile uint32 TOM_M1_CH4_IRQ:1;
    volatile uint32 TOM_M1_CH5_IRQ:1;
    volatile uint32 TOM_M1_CH6_IRQ:1;
    volatile uint32 TOM_M1_CH7_IRQ:1;
    volatile uint32 TOM_M1_CH8_IRQ:1;
    volatile uint32 TOM_M1_CH9_IRQ:1;
    volatile uint32 TOM_M1_CH10_IRQ:1;
    volatile uint32 TOM_M1_CH11_IRQ:1;
    volatile uint32 TOM_M1_CH12_IRQ:1;
    volatile uint32 TOM_M1_CH13_IRQ:1;
    volatile uint32 TOM_M1_CH14_IRQ:1;
    volatile uint32 TOM_M1_CH15_IRQ:1;
}  bf_GTM_ICM_IRQG_TOM_2_CI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ICM_IRQG_TOM_2_CI_bf_type B;
} GTM_ICM_IRQG_TOM_2_CI_bf_type;

typedef struct {
    GTM_ICM_IRQG_0_bf_type IRQG_0; 
    GTM_ICM_IRQG_1_bf_type IRQG_1; 
    GTM_ICM_IRQG_2_bf_type IRQG_2; 
    GTM_ICM_IRQG_3_bf_type IRQG_3; 
    GTM_ICM_IRQG_4_bf_type IRQG_4; 
    GTM_ICM_IRQG_5_bf_type IRQG_5; 
    GTM_ICM_IRQG_6_bf_type IRQG_6; 
    GTM_ICM_IRQG_7_bf_type IRQG_7; 
    GTM_ICM_IRQG_8_bf_type IRQG_8; 
    GTM_ICM_IRQG_9_bf_type IRQG_9; 
    GTM_ICM_IRQG_10_bf_type IRQG_10; 
    GTM_ICM_IRQG_11_bf_type IRQG_11; 
    GTM_ICM_IRQG_MEI_bf_type IRQG_MEI; 
    GTM_ICM_IRQG_CEI0_bf_type IRQG_CEI0; 
    GTM_ICM_IRQG_CEI1_bf_type IRQG_CEI1; 
    GTM_ICM_IRQG_CEI2_bf_type IRQG_CEI2; 
    GTM_ICM_IRQG_CEI3_bf_type IRQG_CEI3; 
    GTM_ICM_IRQG_CEI4_bf_type IRQG_CEI4; 
    volatile uint32 reserved_0[7];
    GTM_ICM_IRQG_MCS_CEI_bf_type IRQG_MCS_CEI[10]; 
    volatile uint32 reserved_1[6];
    GTM_ICM_IRQG_PSM_0_CEI_bf_type IRQG_PSM_0_CEI; 
    volatile uint32 reserved_2[3];
    GTM_ICM_IRQG_SPE_CEI_bf_type IRQG_SPE_CEI; 
    volatile uint32 reserved_3[22];
    GTM_ICM_IRQG_CLS_0_MEI_bf_type IRQG_CLS_0_MEI; 
    GTM_ICM_IRQG_CLS_1_MEI_bf_type IRQG_CLS_1_MEI; 
    GTM_ICM_IRQG_CLS_2_MEI_bf_type IRQG_CLS_2_MEI; 
    volatile uint32 reserved_4;
    GTM_ICM_IRQG_MCS_CI_bf_type IRQG_MCS_CI[10]; 
    volatile uint32 reserved_5[6];
    GTM_ICM_IRQG_PSM_0_CI_bf_type IRQG_PSM_0_CI; 
    volatile uint32 reserved_6[3];
    GTM_ICM_IRQG_SPE_CI_bf_type IRQG_SPE_CI; 
    volatile uint32 reserved_7[7];
    GTM_ICM_IRQG_ATOM_0_CI_bf_type IRQG_ATOM_0_CI; 
    GTM_ICM_IRQG_ATOM_1_CI_bf_type IRQG_ATOM_1_CI; 
    GTM_ICM_IRQG_ATOM_2_CI_bf_type IRQG_ATOM_2_CI; 
    volatile uint32 reserved_8;
    GTM_ICM_IRQG_TOM_0_CI_bf_type IRQG_TOM_0_CI; 
    GTM_ICM_IRQG_TOM_1_CI_bf_type IRQG_TOM_1_CI; 
    GTM_ICM_IRQG_TOM_2_CI_bf_type IRQG_TOM_2_CI; 
    volatile uint32 reserved_9[21];
} GTM_ICM_bf_type;

/*************************************************************************
 * module GTM.SPE
 *************************************************************************/

typedef struct {
    volatile uint32 EN:1;
    volatile uint32 SIE0:1;
    volatile uint32 SIE1:1;
    volatile uint32 SIE2:1;
    volatile uint32 TRIG_SEL:2;
    volatile uint32 TIM_SEL:1;
    volatile uint32 FSOM:1;
    volatile uint32 SPE_PAT_PTR:3;
    uint32 reserved_0:1;
    volatile uint32 AIP:3;
    volatile uint32 ADIR:1;
    volatile uint32 PIP:3;
    volatile uint32 PDIR:1;
    volatile uint32 NIP:3;
    volatile uint32 ETRIG_SEL:1;
    volatile uint32 FSOL:8;
}  bf_GTM_SPE_CTRL_STAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_CTRL_STAT_bf_type B;
} GTM_SPE_CTRL_STAT_bf_type;

typedef struct {
    volatile uint32 IP0_VAL:1;
    volatile uint32 IP0_PAT:3;
    volatile uint32 IP1_VAL:1;
    volatile uint32 IP1_PAT:3;
    volatile uint32 IP2_VAL:1;
    volatile uint32 IP2_PAT:3;
    volatile uint32 IP3_VAL:1;
    volatile uint32 IP3_PAT:3;
    volatile uint32 IP4_VAL:1;
    volatile uint32 IP4_PAT:3;
    volatile uint32 IP5_VAL:1;
    volatile uint32 IP5_PAT:3;
    volatile uint32 IP6_VAL:1;
    volatile uint32 IP6_PAT:3;
    volatile uint32 IP7_VAL:1;
    volatile uint32 IP7_PAT:3;
}  bf_GTM_SPE_PAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_PAT_bf_type B;
} GTM_SPE_PAT_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_PAT:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_PAT0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_PAT0_bf_type B;
} GTM_SPE_OUT_PAT0_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_PAT:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_PAT1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_PAT1_bf_type B;
} GTM_SPE_OUT_PAT1_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_PAT:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_PAT2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_PAT2_bf_type B;
} GTM_SPE_OUT_PAT2_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_PAT:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_PAT3_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_PAT3_bf_type B;
} GTM_SPE_OUT_PAT3_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_PAT:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_PAT4_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_PAT4_bf_type B;
} GTM_SPE_OUT_PAT4_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_PAT:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_PAT5_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_PAT5_bf_type B;
} GTM_SPE_OUT_PAT5_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_PAT:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_PAT6_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_PAT6_bf_type B;
} GTM_SPE_OUT_PAT6_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_PAT:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_PAT7_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_PAT7_bf_type B;
} GTM_SPE_OUT_PAT7_bf_type;

typedef struct {
    volatile uint32 SPE_OUT_CTRL:16;
    uint32 reserved_0:16;
}  bf_GTM_SPE_OUT_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_OUT_CTRL_bf_type B;
} GTM_SPE_OUT_CTRL_bf_type;

typedef struct {
    volatile uint32 SPE_NIPD:1;
    volatile uint32 SPE_DCHG:1;
    volatile uint32 SPE_PERR:1;
    volatile uint32 SPE_BIS:1;
    volatile uint32 SPE_RCMP:1;
    uint32 reserved_0:27;
}  bf_GTM_SPE_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_IRQ_NOTIFY_bf_type B;
} GTM_SPE_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 SPE_NIPD_IRQ_EN:1;
    volatile uint32 SPE_DCHG_IRQ_EN:1;
    volatile uint32 SPE_PERR_IRQ_EN:1;
    volatile uint32 SPE_BIS_IRQ_EN:1;
    volatile uint32 SPE_RCMP_IRQ_EN:1;
    uint32 reserved_0:27;
}  bf_GTM_SPE_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_IRQ_EN_bf_type B;
} GTM_SPE_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_SPE_NIPD:1;
    volatile uint32 TRG_SPE_DCHG:1;
    volatile uint32 TRG_SPE_PERR:1;
    volatile uint32 TRG_SPE_BIS:1;
    volatile uint32 TRG_SPE_RCMP:1;
    uint32 reserved_0:27;
}  bf_GTM_SPE_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_IRQ_FORCINT_bf_type B;
} GTM_SPE_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_SPE_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_IRQ_MODE_bf_type B;
} GTM_SPE_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 SPE_NIPD_EIRQ_EN:1;
    volatile uint32 SPE_DCHG_EIRQ_EN:1;
    volatile uint32 SPE_PERR_EIRQ_EN:1;
    volatile uint32 SPE_BIS_EIRQ_EN:1;
    volatile uint32 SPE_RCMP_EIRQ_EN:1;
    uint32 reserved_0:27;
}  bf_GTM_SPE_EIRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_EIRQ_EN_bf_type B;
} GTM_SPE_EIRQ_EN_bf_type;

typedef struct {
    volatile uint32 REV_CNT:24;
    uint32 reserved_0:8;
}  bf_GTM_SPE_REV_CNT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_REV_CNT_bf_type B;
} GTM_SPE_REV_CNT_bf_type;

typedef struct {
    volatile uint32 REV_CMP:24;
    uint32 reserved_0:8;
}  bf_GTM_SPE_REV_CMP_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_REV_CMP_bf_type B;
} GTM_SPE_REV_CMP_bf_type;

typedef struct {
    uint32 reserved_1:8;
    volatile uint32 SPE_PAT_PTR_BWD:3;
    uint32 reserved_0:21;
}  bf_GTM_SPE_CTRL_STAT2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_CTRL_STAT2_bf_type B;
} GTM_SPE_CTRL_STAT2_bf_type;

typedef struct {
    volatile uint32 SPE_CTRL_CMD:2;
    uint32 reserved_1:14;
    volatile uint32 SPE_UPD_TRIG:1;
    uint32 reserved_0:15;
}  bf_GTM_SPE_CMD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SPE_CMD_bf_type B;
} GTM_SPE_CMD_bf_type;

typedef struct {
    GTM_SPE_CTRL_STAT_bf_type CTRL_STAT; 
    GTM_SPE_PAT_bf_type PAT; 
    GTM_SPE_OUT_PAT0_bf_type OUT_PAT0; 
    GTM_SPE_OUT_PAT1_bf_type OUT_PAT1; 
    GTM_SPE_OUT_PAT2_bf_type OUT_PAT2; 
    GTM_SPE_OUT_PAT3_bf_type OUT_PAT3; 
    GTM_SPE_OUT_PAT4_bf_type OUT_PAT4; 
    GTM_SPE_OUT_PAT5_bf_type OUT_PAT5; 
    GTM_SPE_OUT_PAT6_bf_type OUT_PAT6; 
    GTM_SPE_OUT_PAT7_bf_type OUT_PAT7; 
    GTM_SPE_OUT_CTRL_bf_type OUT_CTRL; 
    GTM_SPE_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_SPE_IRQ_EN_bf_type IRQ_EN; 
    GTM_SPE_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_SPE_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_SPE_EIRQ_EN_bf_type EIRQ_EN; 
    GTM_SPE_REV_CNT_bf_type REV_CNT; 
    GTM_SPE_REV_CMP_bf_type REV_CMP; 
    GTM_SPE_CTRL_STAT2_bf_type CTRL_STAT2; 
    GTM_SPE_CMD_bf_type CMD; 
    volatile uint32 reserved_0[12];
} GTM_SPE_bf_type;

/*************************************************************************
 * module GTM.MAP
 *************************************************************************/

typedef struct {
    volatile uint32 TSEL:1;
    volatile uint32 SSL:3;
    volatile uint32 LSEL:1;
    uint32 reserved_4:11;
    volatile uint32 TSPP0_EN:1;
    volatile uint32 TSPP0_DLD:1;
    uint32 reserved_3:2;
    volatile uint32 TSPP0_I0V:1;
    volatile uint32 TSPP0_I1V:1;
    volatile uint32 TSPP0_I2V:1;
    uint32 reserved_2:1;
    volatile uint32 TSPP1_EN:1;
    volatile uint32 TSPP1_DLD:1;
    uint32 reserved_1:2;
    volatile uint32 TSPP1_I0V:1;
    volatile uint32 TSPP1_I1V:1;
    volatile uint32 TSPP1_I2V:1;
    uint32 reserved_0:1;
}  bf_GTM_MAP_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MAP_CTRL_bf_type B;
} GTM_MAP_CTRL_bf_type;

typedef struct {
    GTM_MAP_CTRL_bf_type CTRL; 
    volatile uint32 reserved_0[15];
} GTM_MAP_bf_type;

/*************************************************************************
 * module GTM.MCFG
 *************************************************************************/

typedef struct {
    volatile uint32 MEM0:2;
    volatile uint32 MEM1:2;
    volatile uint32 MEM2:2;
    volatile uint32 MEM3:2;
    volatile uint32 MEM4:2;
    volatile uint32 MEM5:2;
    volatile uint32 MEM6:2;
    volatile uint32 MEM7:2;
    volatile uint32 MEM8:2;
    volatile uint32 MEM9:2;
    uint32 reserved_0:12;
}  bf_GTM_MCFG_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCFG_CTRL_bf_type B;
} GTM_MCFG_CTRL_bf_type;

typedef struct {
    GTM_MCFG_CTRL_bf_type CTRL; 
    volatile uint32 reserved_0[15];
} GTM_MCFG_bf_type;

/*************************************************************************
 * module GTM.TIM.CH
 *************************************************************************/

typedef struct {
    volatile uint32 GPR0:24;
    volatile uint32 ECNT:8;
}  bf_GTM_TIM_CH_GPR0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_GPR0_bf_type B;
} GTM_TIM_CH_GPR0_bf_type;

typedef struct {
    volatile uint32 GPR1:24;
    volatile uint32 ECNT:8;
}  bf_GTM_TIM_CH_GPR1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_GPR1_bf_type B;
} GTM_TIM_CH_GPR1_bf_type;

typedef struct {
    volatile uint32 CNT:24;
    uint32 reserved_0:8;
}  bf_GTM_TIM_CH_CNT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_CNT_bf_type B;
} GTM_TIM_CH_CNT_bf_type;

typedef struct {
    volatile uint32 ECNT:16;
    uint32 reserved_0:16;
}  bf_GTM_TIM_CH_ECNT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_ECNT_bf_type B;
} GTM_TIM_CH_ECNT_bf_type;

typedef struct {
    volatile uint32 CNTS:24;
    volatile uint32 ECNT:8;
}  bf_GTM_TIM_CH_CNTS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_CNTS_bf_type B;
} GTM_TIM_CH_CNTS_bf_type;

typedef struct {
    volatile uint32 TO_CNT:8;
    volatile uint32 TO_CNT1:8;
    volatile uint32 TO_CNT2:8;
    uint32 reserved_0:8;
}  bf_GTM_TIM_CH_TDUC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_TDUC_bf_type B;
} GTM_TIM_CH_TDUC_bf_type;

typedef struct {
    volatile uint32 TOV:8;
    volatile uint32 TOV1:8;
    volatile uint32 TOV2:8;
    volatile uint32 SLICING:2;
    volatile uint32 TCS_USE_SAMPLE_EVT:1;
    volatile uint32 TDU_SAME_CNT_CLK:1;
    volatile uint32 TCS:3;
    uint32 reserved_0:1;
}  bf_GTM_TIM_CH_TDUV_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_TDUV_bf_type B;
} GTM_TIM_CH_TDUV_bf_type;

typedef struct {
    volatile uint32 FLT_RE:24;
    uint32 reserved_0:8;
}  bf_GTM_TIM_CH_FLT_RE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_FLT_RE_bf_type B;
} GTM_TIM_CH_FLT_RE_bf_type;

typedef struct {
    volatile uint32 FLT_FE:24;
    uint32 reserved_0:8;
}  bf_GTM_TIM_CH_FLT_FE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_FLT_FE_bf_type B;
} GTM_TIM_CH_FLT_FE_bf_type;

typedef struct {
    volatile uint32 TIM_EN:1;
    volatile uint32 TIM_MODE:3;
    volatile uint32 OSM:1;
    volatile uint32 ARU_EN:1;
    volatile uint32 CICTRL:1;
    volatile uint32 TBU0_SEL:1;
    volatile uint32 GPR0_SEL:2;
    volatile uint32 GPR1_SEL:2;
    volatile uint32 CNTS_SEL:1;
    volatile uint32 DSL:1;
    volatile uint32 ISL:1;
    volatile uint32 ECNT_RESET:1;
    volatile uint32 FLT_EN:1;
    volatile uint32 FLT_CNT_FRQ:2;
    volatile uint32 EXT_CAP_EN:1;
    volatile uint32 FLT_MODE_RE:1;
    volatile uint32 FLT_CTR_RE:1;
    volatile uint32 FLT_MODE_FE:1;
    volatile uint32 FLT_CTR_FE:1;
    volatile uint32 CLK_SEL:3;
    volatile uint32 FR_ECNT_OFL:1;
    volatile uint32 EGPR0_SEL:1;
    volatile uint32 EGPR1_SEL:1;
    volatile uint32 TOCTRL:2;
}  bf_GTM_TIM_CH_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_CTRL_bf_type B;
} GTM_TIM_CH_CTRL_bf_type;

typedef struct {
    volatile uint32 EXT_CAP_SRC:4;
    uint32 reserved_4:1;
    volatile uint32 USE_PREV_TDU_IN:1;
    volatile uint32 TODET_IRQ_SRC:2;
    volatile uint32 TDU_START:3;
    uint32 reserved_3:1;
    volatile uint32 TDU_STOP:3;
    uint32 reserved_2:1;
    volatile uint32 TDU_RESYNC:4;
    uint32 reserved_1:2;
    volatile uint32 USE_LUT:2;
    volatile uint32 EFLT_CTR_RE:1;
    volatile uint32 EFLT_CTR_FE:1;
    uint32 reserved_0:2;
    volatile uint32 SWAP_CAPTURE:1;
    volatile uint32 IMM_START:1;
    volatile uint32 ECLK_SEL:1;
    volatile uint32 USE_PREV_CH_IN:1;
}  bf_GTM_TIM_CH_ECTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_ECTRL_bf_type B;
} GTM_TIM_CH_ECTRL_bf_type;

typedef struct {
    volatile uint32 NEWVAL:1;
    volatile uint32 ECNTOFL:1;
    volatile uint32 CNTOFL:1;
    volatile uint32 GPROFL:1;
    volatile uint32 TODET:1;
    volatile uint32 GLITCHDET:1;
    uint32 reserved_0:26;
}  bf_GTM_TIM_CH_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_IRQ_NOTIFY_bf_type B;
} GTM_TIM_CH_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 NEWVAL_IRQ_EN:1;
    volatile uint32 ECNTOFL_IRQ_EN:1;
    volatile uint32 CNTOFL_IRQ_EN:1;
    volatile uint32 GPROFL_IRQ_EN:1;
    volatile uint32 TODET_IRQ_EN:1;
    volatile uint32 GLITCHDET_IRQ_EN:1;
    uint32 reserved_0:26;
}  bf_GTM_TIM_CH_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_IRQ_EN_bf_type B;
} GTM_TIM_CH_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_NEWVAL:1;
    volatile uint32 TRG_ECNTOFL:1;
    volatile uint32 TRG_CNTOFL:1;
    volatile uint32 TRG_GPROFL:1;
    volatile uint32 TRG_TODET:1;
    volatile uint32 TRG_GLITCHDET:1;
    uint32 reserved_0:26;
}  bf_GTM_TIM_CH_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_IRQ_FORCINT_bf_type B;
} GTM_TIM_CH_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_TIM_CH_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_IRQ_MODE_bf_type B;
} GTM_TIM_CH_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 NEWVAL_EIRQ_EN:1;
    volatile uint32 ECNTOFL_EIRQ_EN:1;
    volatile uint32 CNTOFL_EIRQ_EN:1;
    volatile uint32 GPROFL_EIRQ_EN:1;
    volatile uint32 TODET_EIRQ_EN:1;
    volatile uint32 GLITCHDET_EIRQ_EN:1;
    uint32 reserved_0:26;
}  bf_GTM_TIM_CH_EIRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_CH_EIRQ_EN_bf_type B;
} GTM_TIM_CH_EIRQ_EN_bf_type;

typedef struct {
    GTM_TIM_CH_GPR0_bf_type GPR0; 
    GTM_TIM_CH_GPR1_bf_type GPR1; 
    GTM_TIM_CH_CNT_bf_type CNT; 
    GTM_TIM_CH_ECNT_bf_type ECNT; 
    GTM_TIM_CH_CNTS_bf_type CNTS; 
    GTM_TIM_CH_TDUC_bf_type TDUC; 
    GTM_TIM_CH_TDUV_bf_type TDUV; 
    GTM_TIM_CH_FLT_RE_bf_type FLT_RE; 
    GTM_TIM_CH_FLT_FE_bf_type FLT_FE; 
    GTM_TIM_CH_CTRL_bf_type CTRL; 
    GTM_TIM_CH_ECTRL_bf_type ECTRL; 
    GTM_TIM_CH_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_TIM_CH_IRQ_EN_bf_type IRQ_EN; 
    GTM_TIM_CH_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_TIM_CH_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_TIM_CH_EIRQ_EN_bf_type EIRQ_EN; 
    volatile uint32 reserved_0[16];
} GTM_TIM_CH_bf_type;

/*************************************************************************
 * module GTM.TIM.GC
 *************************************************************************/

typedef struct {
    volatile uint32 F_OUT:8;
    volatile uint32 F_IN:8;
    volatile uint32 TIM_IN:8;
    uint32 reserved_0:8;
}  bf_GTM_TIM_GC_INP_VAL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_GC_INP_VAL_bf_type B;
} GTM_TIM_GC_INP_VAL_bf_type;

typedef struct {
    volatile uint32 VAL_0:2;
    volatile uint32 MODE_0:2;
    volatile uint32 VAL_1:2;
    volatile uint32 MODE_1:2;
    volatile uint32 VAL_2:2;
    volatile uint32 MODE_2:2;
    volatile uint32 VAL_3:2;
    volatile uint32 MODE_3:2;
    volatile uint32 VAL_4:2;
    volatile uint32 MODE_4:2;
    volatile uint32 VAL_5:2;
    volatile uint32 MODE_5:2;
    volatile uint32 VAL_6:2;
    volatile uint32 MODE_6:2;
    volatile uint32 VAL_7:2;
    volatile uint32 MODE_7:2;
}  bf_GTM_TIM_GC_IN_SRC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_GC_IN_SRC_bf_type B;
} GTM_TIM_GC_IN_SRC_bf_type;

typedef struct {
    volatile uint32 RST_CH0:1;
    volatile uint32 RST_CH1:1;
    volatile uint32 RST_CH2:1;
    volatile uint32 RST_CH3:1;
    volatile uint32 RST_CH4:1;
    volatile uint32 RST_CH5:1;
    volatile uint32 RST_CH6:1;
    volatile uint32 RST_CH7:1;
    uint32 reserved_0:24;
}  bf_GTM_TIM_GC_RST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIM_GC_RST_bf_type B;
} GTM_TIM_GC_RST_bf_type;

typedef struct {
    volatile uint32 reserved_0[256];
    GTM_TIM_GC_INP_VAL_bf_type INP_VAL; 
    GTM_TIM_GC_IN_SRC_bf_type IN_SRC; 
    GTM_TIM_GC_RST_bf_type RST; 
} GTM_TIM_GC_bf_type;

/*************************************************************************
 * union GTM.TIM
 *************************************************************************/

typedef union {
    GTM_TIM_CH_bf_type CH[8]; 
    GTM_TIM_GC_bf_type GC; 
    volatile uint32 reserved[512];
} GTM_TIM_bf_type;

/*************************************************************************
 * module GTM.TOM.CH
 *************************************************************************/

typedef struct {
    uint32 reserved_3:7;
    volatile uint32 SR0_TRIG:1;
    uint32 reserved_2:3;
    volatile uint32 SL:1;
    volatile uint32 CLK_SRC_SR:4;
    //volatile uint32 ECLK_SRC:1;
    uint32 reserved_1:1;
    volatile uint32 TRIG_PULSE:1;
    volatile uint32 UDMODE:2;
    volatile uint32 RST_CCU0:1;
    volatile uint32 OSM_TRIG:1;
    volatile uint32 EXT_TRIG:1;
    volatile uint32 EXTTRIGOUT:1;
    volatile uint32 TRIGOUT:1;
    volatile uint32 SPE_TRIG:1;
    volatile uint32 OSM:1;
    volatile uint32 BITREV:1;
    volatile uint32 SPEM:1;
    volatile uint32 GCM:1;
    uint32 reserved_0:1;
    volatile uint32 FREEZE:1;
}  bf_GTM_TOM_CH_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_CTRL_bf_type B;
} GTM_TOM_CH_CTRL_bf_type;


typedef struct {
    uint32 reserved_3:11;
    volatile uint32 SL_SR:1;
    volatile uint32 CLK_SRC_SR:4;
    uint32 reserved_1:16;
}  bf_GTM_TOM_CH_CTRL_SR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_CTRL_bf_type B;
} GTM_TOM_CH_CTRL_SR_bf_type;

typedef struct {
    volatile uint32 HRES:1;
    uint32 reserved_0:31;
}  bf_GTM_TOM_CH_CTRL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_CTRL2_bf_type B;
} GTM_TOM_CH_CTRL2_bf_type;

typedef struct {
    volatile uint32 SR0:16;
    uint32 reserved_0:16;
}  bf_GTM_TOM_CH_SR0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_SR0_bf_type B;
} GTM_TOM_CH_SR0_bf_type;

typedef struct {
    volatile uint32 SR1:16;
    uint32 reserved_0:16;
}  bf_GTM_TOM_CH_SR1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_SR1_bf_type B;
} GTM_TOM_CH_SR1_bf_type;

typedef struct {
    volatile uint32 CM0:16;
    uint32 reserved_0:16;
}  bf_GTM_TOM_CH_CM0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_CM0_bf_type B;
} GTM_TOM_CH_CM0_bf_type;

typedef struct {
    volatile uint32 CM1:16;
    uint32 reserved_0:16;
}  bf_GTM_TOM_CH_CM1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_CM1_bf_type B;
} GTM_TOM_CH_CM1_bf_type;

typedef struct {
    volatile uint32 CN0:16;
    uint32 reserved_0:16;
}  bf_GTM_TOM_CH_CN0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_CN0_bf_type B;
} GTM_TOM_CH_CN0_bf_type;

typedef struct {
    volatile uint32 OL:1;
    uint32 reserved_0:28;
    volatile uint32 OSM_RTF:1;
    uint32 reserved_1:2;
}  bf_GTM_TOM_CH_STAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_STAT_bf_type B;
} GTM_TOM_CH_STAT_bf_type;

typedef struct {
    volatile uint32 CCU0TC:1;
    volatile uint32 CCU1TC:1;
    uint32 reserved_0:30;
}  bf_GTM_TOM_CH_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_IRQ_NOTIFY_bf_type B;
} GTM_TOM_CH_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 CCU0TC_IRQ_EN:1;
    volatile uint32 CCU1TC_IRQ_EN:1;
    uint32 reserved_0:30;
}  bf_GTM_TOM_CH_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_IRQ_EN_bf_type B;
} GTM_TOM_CH_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_CCU0TC0:1;
    volatile uint32 TRG_CCU1TC0:1;
    uint32 reserved_0:30;
}  bf_GTM_TOM_CH_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_IRQ_FORCINT_bf_type B;
} GTM_TOM_CH_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_TOM_CH_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_CH_IRQ_MODE_bf_type B;
} GTM_TOM_CH_IRQ_MODE_bf_type;

typedef struct {
    GTM_TOM_CH_CTRL_bf_type CTRL; 
    GTM_TOM_CH_SR0_bf_type SR0; 
    GTM_TOM_CH_SR1_bf_type SR1; 
    GTM_TOM_CH_CM0_bf_type CM0; 
    GTM_TOM_CH_CM1_bf_type CM1; 
    GTM_TOM_CH_CN0_bf_type CN0; 
    GTM_TOM_CH_STAT_bf_type STAT; 
    GTM_TOM_CH_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_TOM_CH_IRQ_EN_bf_type IRQ_EN; 
    GTM_TOM_CH_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_TOM_CH_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_TOM_CH_CTRL2_bf_type CTRL2;
    GTM_TOM_CH_CTRL_SR_bf_type CTRL_SR;
    volatile uint32 reserved_1[3];
} GTM_TOM_CH_bf_type;

/*************************************************************************
 * module GTM.TOM.TGC
 *************************************************************************/

typedef struct {
    volatile uint32 HOST_TRIG:1;
    uint32 reserved_0:7;
    volatile uint32 RST_CH0:1;
    volatile uint32 RST_CH1:1;
    volatile uint32 RST_CH2:1;
    volatile uint32 RST_CH3:1;
    volatile uint32 RST_CH4:1;
    volatile uint32 RST_CH5:1;
    volatile uint32 RST_CH6:1;
    volatile uint32 RST_CH7:1;
    volatile uint32 UPEN_CTRL0:2;
    volatile uint32 UPEN_CTRL1:2;
    volatile uint32 UPEN_CTRL2:2;
    volatile uint32 UPEN_CTRL3:2;
    volatile uint32 UPEN_CTRL4:2;
    volatile uint32 UPEN_CTRL5:2;
    volatile uint32 UPEN_CTRL6:2;
    volatile uint32 UPEN_CTRL7:2;
}  bf_GTM_TOM_TGC_GLB_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_TGC_GLB_CTRL_bf_type B;
} GTM_TOM_TGC_GLB_CTRL_bf_type;

typedef struct {
    volatile uint32 ACT_TB:24;
    volatile uint32 TB_TRIG:1;
    volatile uint32 TBU_SEL:2;
    uint32 reserved_0:5;
}  bf_GTM_TOM_TGC_ACT_TB_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_TGC_ACT_TB_bf_type B;
} GTM_TOM_TGC_ACT_TB_bf_type;

typedef struct {
    volatile uint32 FUPD_CTRL0:2;
    volatile uint32 FUPD_CTRL1:2;
    volatile uint32 FUPD_CTRL2:2;
    volatile uint32 FUPD_CTRL3:2;
    volatile uint32 FUPD_CTRL4:2;
    volatile uint32 FUPD_CTRL5:2;
    volatile uint32 FUPD_CTRL6:2;
    volatile uint32 FUPD_CTRL7:2;
    volatile uint32 RSTCN0_CH0:2;
    volatile uint32 RSTCN0_CH1:2;
    volatile uint32 RSTCN0_CH2:2;
    volatile uint32 RSTCN0_CH3:2;
    volatile uint32 RSTCN0_CH4:2;
    volatile uint32 RSTCN0_CH5:2;
    volatile uint32 RSTCN0_CH6:2;
    volatile uint32 RSTCN0_CH7:2;
}  bf_GTM_TOM_TGC_FUPD_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_TGC_FUPD_CTRL_bf_type B;
} GTM_TOM_TGC_FUPD_CTRL_bf_type;

typedef struct {
    volatile uint32 INT_TRIG0:2;
    volatile uint32 INT_TRIG1:2;
    volatile uint32 INT_TRIG2:2;
    volatile uint32 INT_TRIG3:2;
    volatile uint32 INT_TRIG4:2;
    volatile uint32 INT_TRIG5:2;
    volatile uint32 INT_TRIG6:2;
    volatile uint32 INT_TRIG7:2;
    uint32 reserved_0:16;
}  bf_GTM_TOM_TGC_INT_TRIG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_TGC_INT_TRIG_bf_type B;
} GTM_TOM_TGC_INT_TRIG_bf_type;

typedef struct {
    volatile uint32 ENDIS_CTRL0:2;
    volatile uint32 ENDIS_CTRL1:2;
    volatile uint32 ENDIS_CTRL2:2;
    volatile uint32 ENDIS_CTRL3:2;
    volatile uint32 ENDIS_CTRL4:2;
    volatile uint32 ENDIS_CTRL5:2;
    volatile uint32 ENDIS_CTRL6:2;
    volatile uint32 ENDIS_CTRL7:2;
    uint32 reserved_0:16;
}  bf_GTM_TOM_TGC_ENDIS_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_TGC_ENDIS_CTRL_bf_type B;
} GTM_TOM_TGC_ENDIS_CTRL_bf_type;

typedef struct {
    volatile uint32 ENDIS_STAT0:2;
    volatile uint32 ENDIS_STAT1:2;
    volatile uint32 ENDIS_STAT2:2;
    volatile uint32 ENDIS_STAT3:2;
    volatile uint32 ENDIS_STAT4:2;
    volatile uint32 ENDIS_STAT5:2;
    volatile uint32 ENDIS_STAT6:2;
    volatile uint32 ENDIS_STAT7:2;
    uint32 reserved_0:16;
}  bf_GTM_TOM_TGC_ENDIS_STAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_TGC_ENDIS_STAT_bf_type B;
} GTM_TOM_TGC_ENDIS_STAT_bf_type;

typedef struct {
    volatile uint32 OUTEN_CTRL0:2;
    volatile uint32 OUTEN_CTRL1:2;
    volatile uint32 OUTEN_CTRL2:2;
    volatile uint32 OUTEN_CTRL3:2;
    volatile uint32 OUTEN_CTRL4:2;
    volatile uint32 OUTEN_CTRL5:2;
    volatile uint32 OUTEN_CTRL6:2;
    volatile uint32 OUTEN_CTRL7:2;
    uint32 reserved_0:16;
}  bf_GTM_TOM_TGC_OUTEN_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_TGC_OUTEN_CTRL_bf_type B;
} GTM_TOM_TGC_OUTEN_CTRL_bf_type;

typedef struct {
    volatile uint32 OUTEN_STAT0:2;
    volatile uint32 OUTEN_STAT1:2;
    volatile uint32 OUTEN_STAT2:2;
    volatile uint32 OUTEN_STAT3:2;
    volatile uint32 OUTEN_STAT4:2;
    volatile uint32 OUTEN_STAT5:2;
    volatile uint32 OUTEN_STAT6:2;
    volatile uint32 OUTEN_STAT7:2;
    uint32 reserved_0:16;
}  bf_GTM_TOM_TGC_OUTEN_STAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TOM_TGC_OUTEN_STAT_bf_type B;
} GTM_TOM_TGC_OUTEN_STAT_bf_type;

typedef struct {
    volatile uint32 reserved_1[12];
    GTM_TOM_TGC_GLB_CTRL_bf_type GLB_CTRL; 
    GTM_TOM_TGC_ACT_TB_bf_type ACT_TB; 
    GTM_TOM_TGC_FUPD_CTRL_bf_type FUPD_CTRL; 
    GTM_TOM_TGC_INT_TRIG_bf_type INT_TRIG; 
    volatile uint32 reserved_2[12];
    GTM_TOM_TGC_ENDIS_CTRL_bf_type ENDIS_CTRL; 
    GTM_TOM_TGC_ENDIS_STAT_bf_type ENDIS_STAT; 
    GTM_TOM_TGC_OUTEN_CTRL_bf_type OUTEN_CTRL; 
    GTM_TOM_TGC_OUTEN_STAT_bf_type OUTEN_STAT; 
} GTM_TOM_TGC_bf_type;



/*************************************************************************
 * union GTM.TOM
 *************************************************************************/

typedef struct {
    GTM_TOM_CH_bf_type CH[16]; 
    GTM_TOM_TGC_bf_type TGC[2]; 
    volatile uint32 reserved_0[192];
} GTM_TOM_bf_type;

/*************************************************************************
 * module GTM.PSM.F2A
 *************************************************************************/

typedef struct {
    volatile uint32 ADDR:9;
    uint32 reserved_0:23;
}  bf_GTM_PSM_F2A_CH_ARU_RD_FIFO_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_F2A_CH_ARU_RD_FIFO_bf_type B;
} GTM_PSM_F2A_CH_ARU_RD_FIFO_bf_type;

typedef struct {
    uint32 reserved_1:16;
    volatile uint32 TMODE:2;
    volatile uint32 DIR:1;
    uint32 reserved_0:13;
}  bf_GTM_PSM_F2A_CH_STR_CFG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_F2A_CH_STR_CFG_bf_type B;
} GTM_PSM_F2A_CH_STR_CFG_bf_type;

typedef struct {
    volatile uint32 STR0_EN:2;
    volatile uint32 STR1_EN:2;
    volatile uint32 STR2_EN:2;
    volatile uint32 STR3_EN:2;
    volatile uint32 STR4_EN:2;
    volatile uint32 STR5_EN:2;
    volatile uint32 STR6_EN:2;
    volatile uint32 STR7_EN:2;
    uint32 reserved_0:16;
}  bf_GTM_PSM_F2A_ENABLE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_F2A_ENABLE_bf_type B;
} GTM_PSM_F2A_ENABLE_bf_type;

typedef struct {
    volatile uint32 STR4_CONF:2;
    volatile uint32 STR5_CONF:2;
    volatile uint32 STR6_CONF:2;
    volatile uint32 STR7_CONF:2;
    uint32 reserved_0:24;
}  bf_GTM_PSM_F2A_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_F2A_CTRL_bf_type B;
} GTM_PSM_F2A_CTRL_bf_type;

typedef struct {
    GTM_PSM_F2A_CH_ARU_RD_FIFO_bf_type CH_ARU_RD_FIFO[8]; 
    GTM_PSM_F2A_CH_STR_CFG_bf_type CH_STR_CFG[8]; 
    GTM_PSM_F2A_ENABLE_bf_type ENABLE; 
    GTM_PSM_F2A_CTRL_bf_type CTRL; 
    volatile uint32 reserved_0[14];
} GTM_PSM_F2A_bf_type;

/*************************************************************************
 * module GTM.PSM.AFD.CH
 *************************************************************************/

typedef struct {
    volatile uint32 DATA:29;
    uint32 reserved_0:3;
}  bf_GTM_PSM_AFD_CH_BUF_ACC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_AFD_CH_BUF_ACC_bf_type B;
} GTM_PSM_AFD_CH_BUF_ACC_bf_type;

typedef struct {
    GTM_PSM_AFD_CH_BUF_ACC_bf_type BUF_ACC; 
    volatile uint32 reserved_0[3];
} GTM_PSM_AFD_CH_bf_type;

/*************************************************************************
 * module GTM.PSM.AFD
 *************************************************************************/

typedef struct {
    GTM_PSM_AFD_CH_bf_type CH[8]; 
} GTM_PSM_AFD_bf_type;

/*************************************************************************
 * module GTM.PSM.FIFO.CH
 *************************************************************************/

typedef struct {
    volatile uint32 RBM:1;
    volatile uint32 RAP:1;
    volatile uint32 FLUSH:1;
    volatile uint32 WULOCK:1;
    uint32 reserved_0:28;
}  bf_GTM_PSM_FIFO_CH_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_CTRL_bf_type B;
} GTM_PSM_FIFO_CH_CTRL_bf_type;

typedef struct {
    volatile uint32 ADDR:10;
    uint32 reserved_0:22;
}  bf_GTM_PSM_FIFO_CH_END_ADDR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_END_ADDR_bf_type B;
} GTM_PSM_FIFO_CH_END_ADDR_bf_type;

typedef struct {
    volatile uint32 ADDR:10;
    uint32 reserved_0:22;
}  bf_GTM_PSM_FIFO_CH_START_ADDR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_START_ADDR_bf_type B;
} GTM_PSM_FIFO_CH_START_ADDR_bf_type;

typedef struct {
    volatile uint32 ADDR:10;
    uint32 reserved_0:22;
}  bf_GTM_PSM_FIFO_CH_UPPER_WM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_UPPER_WM_bf_type B;
} GTM_PSM_FIFO_CH_UPPER_WM_bf_type;

typedef struct {
    volatile uint32 ADDR:10;
    uint32 reserved_0:22;
}  bf_GTM_PSM_FIFO_CH_LOWER_WM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_LOWER_WM_bf_type B;
} GTM_PSM_FIFO_CH_LOWER_WM_bf_type;

typedef struct {
    volatile uint32 EMPTY:1;
    volatile uint32 FULL:1;
    volatile uint32 LOW_WM:1;
    volatile uint32 UP_WM:1;
    uint32 reserved_0:28;
}  bf_GTM_PSM_FIFO_CH_STATUS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_STATUS_bf_type B;
} GTM_PSM_FIFO_CH_STATUS_bf_type;

typedef struct {
    volatile uint32 LEVEL:11;
    uint32 reserved_0:21;
}  bf_GTM_PSM_FIFO_CH_FILL_LEVEL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_FILL_LEVEL_bf_type B;
} GTM_PSM_FIFO_CH_FILL_LEVEL_bf_type;

typedef struct {
    volatile uint32 ADDR:10;
    uint32 reserved_0:22;
}  bf_GTM_PSM_FIFO_CH_WR_PTR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_WR_PTR_bf_type B;
} GTM_PSM_FIFO_CH_WR_PTR_bf_type;

typedef struct {
    volatile uint32 ADDR:10;
    uint32 reserved_0:22;
}  bf_GTM_PSM_FIFO_CH_RD_PTR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_RD_PTR_bf_type B;
} GTM_PSM_FIFO_CH_RD_PTR_bf_type;

typedef struct {
    volatile uint32 FIFO_EMPTY:1;
    volatile uint32 FIFO_FULL:1;
    volatile uint32 FIFO_LWM:1;
    volatile uint32 FIFO_UWM:1;
    uint32 reserved_0:28;
}  bf_GTM_PSM_FIFO_CH_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_IRQ_NOTIFY_bf_type B;
} GTM_PSM_FIFO_CH_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 FIFO_EMPTY_IRQ_EN:1;
    volatile uint32 FIFO_FULL_IRQ_EN:1;
    volatile uint32 FIFO_LWM_IRQ_EN:1;
    volatile uint32 FIFO_UWM_IRQ_EN:1;
    uint32 reserved_0:28;
}  bf_GTM_PSM_FIFO_CH_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_IRQ_EN_bf_type B;
} GTM_PSM_FIFO_CH_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_FIFO_EMPTY:1;
    volatile uint32 TRG_FIFO_FULL:1;
    volatile uint32 TRG_FIFO_LWM:1;
    volatile uint32 TRG_FIFO_UWM:1;
    uint32 reserved_0:28;
}  bf_GTM_PSM_FIFO_CH_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_IRQ_FORCINT_bf_type B;
} GTM_PSM_FIFO_CH_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    volatile uint32 DMA_HYSTERESIS:1;
    volatile uint32 DMA_HYST_DIR:1;
    uint32 reserved_0:28;
}  bf_GTM_PSM_FIFO_CH_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_IRQ_MODE_bf_type B;
} GTM_PSM_FIFO_CH_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 FIFO_EMPTY_EIRQ_EN:1;
    volatile uint32 FIFO_FULL_EIRQ_EN:1;
    volatile uint32 FIFO_LWM_EIRQ_EN:1;
    volatile uint32 FIFO_UWM_EIRQ_EN:1;
    uint32 reserved_0:28;
}  bf_GTM_PSM_FIFO_CH_EIRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_CH_EIRQ_EN_bf_type B;
} GTM_PSM_FIFO_CH_EIRQ_EN_bf_type;

typedef struct {
    GTM_PSM_FIFO_CH_CTRL_bf_type CTRL; 
    GTM_PSM_FIFO_CH_END_ADDR_bf_type END_ADDR; 
    GTM_PSM_FIFO_CH_START_ADDR_bf_type START_ADDR; 
    GTM_PSM_FIFO_CH_UPPER_WM_bf_type UPPER_WM; 
    GTM_PSM_FIFO_CH_LOWER_WM_bf_type LOWER_WM; 
    GTM_PSM_FIFO_CH_STATUS_bf_type STATUS; 
    GTM_PSM_FIFO_CH_FILL_LEVEL_bf_type FILL_LEVEL; 
    GTM_PSM_FIFO_CH_WR_PTR_bf_type WR_PTR; 
    GTM_PSM_FIFO_CH_RD_PTR_bf_type RD_PTR; 
    GTM_PSM_FIFO_CH_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_PSM_FIFO_CH_IRQ_EN_bf_type IRQ_EN; 
    GTM_PSM_FIFO_CH_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_PSM_FIFO_CH_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_PSM_FIFO_CH_EIRQ_EN_bf_type EIRQ_EN; 
    volatile uint32 reserved_0[2];
} GTM_PSM_FIFO_CH_bf_type;

/*************************************************************************
 * module GTM.PSM.FIFO
 *************************************************************************/

typedef struct {
    GTM_PSM_FIFO_CH_bf_type CH[8]; 
//    volatile uint32 reserved_0[128];
} GTM_PSM_FIFO_bf_type;

/*************************************************************************
 * module GTM.PSM
 *************************************************************************/

typedef struct {
    volatile uint32 DATA:32;
}  bf_GTM_PSM_FIFO_MEMORY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_PSM_FIFO_MEMORY_bf_type B;
} GTM_PSM_FIFO_MEMORY_bf_type;

typedef struct {
    GTM_PSM_F2A_bf_type F2A; 
    GTM_PSM_AFD_bf_type AFD; 
    volatile uint32 reserved_0[64];
    GTM_PSM_FIFO_bf_type FIFO; 
//    volatile uint32 reserved_1[512];
//    GTM_PSM_FIFO_MEMORY_bf_type FIFO_MEMORY[1024]; 
//    volatile uint32 reserved_2[2048];
} GTM_PSM_bf_type;

/*************************************************************************
 * module GTM.DPLL
 *************************************************************************/

typedef struct {
    volatile uint32 MLT:10;
    volatile uint32 IFP:1;
    volatile uint32 SNU:5;
    volatile uint32 TNU:9;
    volatile uint32 AMS:1;
    volatile uint32 AMT:1;
    volatile uint32 IDS:1;
    volatile uint32 IDT:1;
    volatile uint32 SEN:1;
    volatile uint32 TEN:1;
    volatile uint32 RMO:1;
}  bf_GTM_DPLL_CTRL_0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_0_bf_type B;
} GTM_DPLL_CTRL_0_bf_type;

typedef struct {
    volatile uint32 DMO:1;
    volatile uint32 DEN:1;
    volatile uint32 IDDS:1;
    volatile uint32 COA:1;
    volatile uint32 PIT:1;
    volatile uint32 SGE1:1;
    volatile uint32 DLM1:1;
    volatile uint32 PCM1:1;
    volatile uint32 SGE2:1;
    volatile uint32 DLM2:1;
    volatile uint32 PCM2:1;
    volatile uint32 SYN_NS:5;
    volatile uint32 SYN_NT:6;
    volatile uint32 LCD:1;
    volatile uint32 SWR:1;
    volatile uint32 SYSF:1;
    volatile uint32 TS0_HRS:1;
    volatile uint32 TS0_HRT:1;
    volatile uint32 SMC:1;
    volatile uint32 SSL:2;
    volatile uint32 TSL:2;
}  bf_GTM_DPLL_CTRL_1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_1_bf_type B;
} GTM_DPLL_CTRL_1_bf_type;

typedef struct {
    uint32 reserved_1:8;
    volatile uint32 AEN0:1;
    volatile uint32 AEN1:1;
    volatile uint32 AEN2:1;
    volatile uint32 AEN3:1;
    volatile uint32 AEN4:1;
    volatile uint32 AEN5:1;
    volatile uint32 AEN6:1;
    volatile uint32 AEN7:1;
    volatile uint32 WAD0:1;
    volatile uint32 WAD1:1;
    volatile uint32 WAD2:1;
    volatile uint32 WAD3:1;
    volatile uint32 WAD4:1;
    volatile uint32 WAD5:1;
    volatile uint32 WAD6:1;
    volatile uint32 WAD7:1;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CTRL_2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_2_bf_type B;
} GTM_DPLL_CTRL_2_bf_type;

typedef struct {
    uint32 reserved_1:8;
    volatile uint32 AEN8:1;
    volatile uint32 AEN9:1;
    volatile uint32 AEN10:1;
    volatile uint32 AEN11:1;
    volatile uint32 AEN12:1;
    volatile uint32 AEN13:1;
    volatile uint32 AEN14:1;
    volatile uint32 AEN15:1;
    volatile uint32 WAD8:1;
    volatile uint32 WAD9:1;
    volatile uint32 WAD10:1;
    volatile uint32 WAD11:1;
    volatile uint32 WAD12:1;
    volatile uint32 WAD13:1;
    volatile uint32 WAD14:1;
    volatile uint32 WAD15:1;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CTRL_3_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_3_bf_type B;
} GTM_DPLL_CTRL_3_bf_type;

typedef struct {
    uint32 reserved_1:8;
    volatile uint32 AEN16:1;
    volatile uint32 AEN17:1;
    volatile uint32 AEN18:1;
    volatile uint32 AEN19:1;
    volatile uint32 AEN20:1;
    volatile uint32 AEN21:1;
    volatile uint32 AEN22:1;
    volatile uint32 AEN23:1;
    volatile uint32 WAD16:1;
    volatile uint32 WAD17:1;
    volatile uint32 WAD18:1;
    volatile uint32 WAD19:1;
    volatile uint32 WAD20:1;
    volatile uint32 WAD21:1;
    volatile uint32 WAD22:1;
    volatile uint32 WAD23:1;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CTRL_4_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_4_bf_type B;
} GTM_DPLL_CTRL_4_bf_type;

typedef struct {
    uint32 reserved_1:8;
    volatile uint32 AEN24:1;
    volatile uint32 AEN25:1;
    volatile uint32 AEN26:1;
    volatile uint32 AEN27:1;
    volatile uint32 AEN28:1;
    volatile uint32 AEN29:1;
    volatile uint32 AEN30:1;
    volatile uint32 AEN31:1;
    volatile uint32 WAD24:1;
    volatile uint32 WAD25:1;
    volatile uint32 WAD26:1;
    volatile uint32 WAD27:1;
    volatile uint32 WAD28:1;
    volatile uint32 WAD29:1;
    volatile uint32 WAD30:1;
    volatile uint32 WAD31:1;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CTRL_5_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_5_bf_type B;
} GTM_DPLL_CTRL_5_bf_type;

typedef struct {
    volatile uint32 ACT_N:32;
}  bf_GTM_DPLL_ACT_STA_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_ACT_STA_bf_type B;
} GTM_DPLL_ACT_STA_bf_type;

typedef struct {
    volatile uint32 SWON_S:1;
    volatile uint32 SWON_T:1;
    uint32 reserved_1:6;
    volatile uint32 OSS:2;
    uint32 reserved_0:22;
}  bf_GTM_DPLL_OSW_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_OSW_bf_type B;
} GTM_DPLL_OSW_bf_type;

typedef struct {
    volatile uint32 AOSV_2A:8;
    volatile uint32 AOSV_2B:8;
    volatile uint32 AOSV_2C:8;
    volatile uint32 AOSV_2D:8;
}  bf_GTM_DPLL_AOSV_2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_AOSV_2_bf_type B;
} GTM_DPLL_AOSV_2_bf_type;

typedef struct {
    uint32 reserved_2:1;
    volatile uint32 WAPT:1;
    volatile uint32 APT:10;
    uint32 reserved_1:1;
    volatile uint32 WAPT_2B:1;
    volatile uint32 APT_2B:10;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_APT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APT_bf_type B;
} GTM_DPLL_APT_bf_type;

typedef struct {
    uint32 reserved_2:1;
    volatile uint32 WAPS:1;
    volatile uint32 APS:6;
    uint32 reserved_1:5;
    volatile uint32 WAPS_1C2:1;
    volatile uint32 APS_1C2:6;
    uint32 reserved_0:12;
}  bf_GTM_DPLL_APS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APS_bf_type B;
} GTM_DPLL_APS_bf_type;

typedef struct {
    uint32 reserved_1:2;
    volatile uint32 APT_2C:10;
    uint32 reserved_0:20;
}  bf_GTM_DPLL_APT_2C_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APT_2C_bf_type B;
} GTM_DPLL_APT_2C_bf_type;

typedef struct {
    uint32 reserved_1:2;
    volatile uint32 APS_1C3:6;
    uint32 reserved_0:24;
}  bf_GTM_DPLL_APS_1C3_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APS_1C3_bf_type B;
} GTM_DPLL_APS_1C3_bf_type;

typedef struct {
    volatile uint32 NUTE:10;
    volatile uint32 FST:1;
    uint32 reserved_1:2;
    volatile uint32 SYN_T:3;
    volatile uint32 SYN_T_OLD:3;
    volatile uint32 VTN:6;
    uint32 reserved_0:4;
    volatile uint32 WNUT:1;
    volatile uint32 WSYN:1;
    volatile uint32 WVTN:1;
}  bf_GTM_DPLL_NUTC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NUTC_bf_type B;
} GTM_DPLL_NUTC_bf_type;

typedef struct {
    volatile uint32 NUSE:6;
    volatile uint32 FSS:1;
    volatile uint32 SYN_S:6;
    volatile uint32 SYN_S_OLD:6;
    volatile uint32 VSN:6;
    uint32 reserved_0:4;
    volatile uint32 WNUS:1;
    volatile uint32 WSYN:1;
    volatile uint32 WVSN:1;
}  bf_GTM_DPLL_NUSC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NUSC_bf_type B;
} GTM_DPLL_NUSC_bf_type;

typedef struct {
    volatile uint32 NTI_CNT:10;
    uint32 reserved_0:22;
}  bf_GTM_DPLL_NTI_CNT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NTI_CNT_bf_type B;
} GTM_DPLL_NTI_CNT_bf_type;

typedef struct {
    volatile uint32 PDI:1;
    volatile uint32 PEI:1;
    volatile uint32 TINI:1;
    volatile uint32 TAXI:1;
    volatile uint32 SISI:1;
    volatile uint32 TISI:1;
    volatile uint32 MSI:1;
    volatile uint32 MTI:1;
    volatile uint32 SASI:1;
    volatile uint32 TASI:1;
    volatile uint32 PWI:1;
    volatile uint32 W2I:1;
    volatile uint32 W1I:1;
    volatile uint32 GL1I:1;
    volatile uint32 LL1I:1;
    volatile uint32 EI:1;
    volatile uint32 GL2I:1;
    volatile uint32 LL2I:1;
    volatile uint32 TE0I:1;
    volatile uint32 TE1I:1;
    volatile uint32 TE2I:1;
    volatile uint32 TE3I:1;
    volatile uint32 TE4I:1;
    volatile uint32 CDTI:1;
    volatile uint32 CDSI:1;
    volatile uint32 TORI:1;
    volatile uint32 SORI:1;
    volatile uint32 DCGI:1;
    uint32 reserved_0:4;
}  bf_GTM_DPLL_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_IRQ_NOTIFY_bf_type B;
} GTM_DPLL_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 PDI_IRQ_EN:1;
    volatile uint32 PEI_IRQ_EN:1;
    volatile uint32 TINI_IRQ_EN:1;
    volatile uint32 TAXI_IRQ_EN:1;
    volatile uint32 SISI_IRQ_EN:1;
    volatile uint32 TISI_IRQ_EN:1;
    volatile uint32 MSI_IRQ_EN:1;
    volatile uint32 MTI_IRQ_EN:1;
    volatile uint32 SASI_IRQ_EN:1;
    volatile uint32 TASI_IRQ_EN:1;
    volatile uint32 PWI_IRQ_EN:1;
    volatile uint32 W2I_IRQ_EN:1;
    volatile uint32 W1I_IRQ_EN:1;
    volatile uint32 GL1I_IRQ_EN:1;
    volatile uint32 LL1I_IRQ_EN:1;
    volatile uint32 EI_IRQ_EN:1;
    volatile uint32 GL2I_IRQ_EN:1;
    volatile uint32 LL2I_IRQ_EN:1;
    volatile uint32 TE0I_IRQ_EN:1;
    volatile uint32 TE1I_IRQ_EN:1;
    volatile uint32 TE2I_IRQ_EN:1;
    volatile uint32 TE3I_IRQ_EN:1;
    volatile uint32 TE4I_IRQ_EN:1;
    volatile uint32 CDTI_IRQ_EN:1;
    volatile uint32 CDSI_IRQ_EN:1;
    volatile uint32 TORI_IRQ_EN:1;
    volatile uint32 SORI_IRQ_EN:1;
    volatile uint32 DCGI_IRQ_EN:1;
    uint32 reserved_0:4;
}  bf_GTM_DPLL_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_IRQ_EN_bf_type B;
} GTM_DPLL_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_PDI:1;
    volatile uint32 TRG_PEI:1;
    volatile uint32 TRG_TINI:1;
    volatile uint32 TRG_TAXI:1;
    volatile uint32 TRG_SISI:1;
    volatile uint32 TRG_TISI:1;
    volatile uint32 TRG_MSI:1;
    volatile uint32 TRG_MTI:1;
    volatile uint32 TRG_SASI:1;
    volatile uint32 TRG_TASI:1;
    volatile uint32 TRG_PWI:1;
    volatile uint32 TRG_W2I:1;
    volatile uint32 TRG_W1I:1;
    volatile uint32 TRG_GL1I:1;
    volatile uint32 TRG_LL1I:1;
    volatile uint32 TRG_EI:1;
    volatile uint32 TRG_GL2I:1;
    volatile uint32 TRG_LL2I:1;
    volatile uint32 TRG_TE0I:1;
    volatile uint32 TRG_TE1I:1;
    volatile uint32 TRG_TE2I:1;
    volatile uint32 TRG_TE3I:1;
    volatile uint32 TRG_TE4I:1;
    volatile uint32 TRG_CDTI:1;
    volatile uint32 TRG_CDSI:1;
    volatile uint32 TRG_TORI:1;
    volatile uint32 TRG_SORI:1;
    volatile uint32 TRG_DCGI:1;
    uint32 reserved_0:4;
}  bf_GTM_DPLL_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_IRQ_FORCINT_bf_type B;
} GTM_DPLL_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_DPLL_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_IRQ_MODE_bf_type B;
} GTM_DPLL_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 PDI_EIRQ_EN:1;
    volatile uint32 PEI_EIRQ_EN:1;
    volatile uint32 TINI_EIRQ_EN:1;
    volatile uint32 TAXI_EIRQ_EN:1;
    volatile uint32 SISI_EIRQ_EN:1;
    volatile uint32 TISI_EIRQ_EN:1;
    volatile uint32 MSI_EIRQ_EN:1;
    volatile uint32 MTI_EIRQ_EN:1;
    volatile uint32 SASI_EIRQ_EN:1;
    volatile uint32 TASI_EIRQ_EN:1;
    volatile uint32 PWI_EIRQ_EN:1;
    volatile uint32 W2I_EIRQ_EN:1;
    volatile uint32 W1I_EIRQ_EN:1;
    volatile uint32 GL1I_EIRQ_EN:1;
    volatile uint32 LL1I_EIRQ_EN:1;
    volatile uint32 EI_EIRQ_EN:1;
    volatile uint32 GL2I_EIRQ_EN:1;
    volatile uint32 LL2I_EIRQ_EN:1;
    volatile uint32 TE0I_EIRQ_EN:1;
    volatile uint32 TE1I_EIRQ_EN:1;
    volatile uint32 TE2I_EIRQ_EN:1;
    volatile uint32 TE3I_EIRQ_EN:1;
    volatile uint32 TE4I_EIRQ_EN:1;
    volatile uint32 CDTI_EIRQ_EN:1;
    volatile uint32 CDSI_EIRQ_EN:1;
    volatile uint32 TORI_EIRQ_EN:1;
    volatile uint32 SORI_EIRQ_EN:1;
    volatile uint32 DCGI_EIRQ_EN:1;
    uint32 reserved_0:4;
}  bf_GTM_DPLL_EIRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_EIRQ_EN_bf_type B;
} GTM_DPLL_EIRQ_EN_bf_type;

typedef struct {
    volatile uint32 INC_CNT1:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_INC_CNT1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_INC_CNT1_bf_type B;
} GTM_DPLL_INC_CNT1_bf_type;

typedef struct {
    volatile uint32 INC_CNT2:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_INC_CNT2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_INC_CNT2_bf_type B;
} GTM_DPLL_INC_CNT2_bf_type;

typedef struct {
    volatile uint32 APT_2B_EXT:6;
    volatile uint32 APT_2B_STATUS:1;
    uint32 reserved_1:7;
    volatile uint32 APT_2B_OLD:10;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_APT_SYNC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APT_SYNC_bf_type B;
} GTM_DPLL_APT_SYNC_bf_type;

typedef struct {
    volatile uint32 APS_1C2_EXT:6;
    volatile uint32 APS_1C2_STATUS:1;
    uint32 reserved_1:7;
    volatile uint32 APS_1C2_OLD:6;
    uint32 reserved_0:12;
}  bf_GTM_DPLL_APS_SYNC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APS_SYNC_bf_type B;
} GTM_DPLL_APS_SYNC_bf_type;

typedef struct {
    volatile uint32 TBU_TS0_T:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TBU_TS0_T_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TBU_TS0_T_bf_type B;
} GTM_DPLL_TBU_TS0_T_bf_type;

typedef struct {
    volatile uint32 TBU_TS0_S:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TBU_TS0_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TBU_TS0_S_bf_type B;
} GTM_DPLL_TBU_TS0_S_bf_type;

typedef struct {
    volatile uint32 ADD_IN_LD1:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_ADD_IN_LD1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_ADD_IN_LD1_bf_type B;
} GTM_DPLL_ADD_IN_LD1_bf_type;

typedef struct {
    volatile uint32 ADD_IN_LD2:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_ADD_IN_LD2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_ADD_IN_LD2_bf_type B;
} GTM_DPLL_ADD_IN_LD2_bf_type;

typedef struct {
    volatile uint32 FPCE:1;
    volatile uint32 CSO:1;
    uint32 reserved_2:1;
    volatile uint32 CTO:1;
    volatile uint32 CRO:1;
    volatile uint32 RCS:1;
    volatile uint32 RCT:1;
    volatile uint32 PSE:1;
    volatile uint32 SOR:1;
    volatile uint32 MS:1;
    volatile uint32 TOR:1;
    volatile uint32 MT:1;
    volatile uint32 RAM2_ERR:1;
    uint32 reserved_1:2;
    volatile uint32 LOW_RES:1;
    volatile uint32 CSVS:1;
    volatile uint32 CSVT:1;
    volatile uint32 CAIP2:1;
    volatile uint32 CAIP1:1;
    volatile uint32 ISN:1;
    volatile uint32 ITN:1;
    volatile uint32 BWD2:1;
    volatile uint32 BWD1:1;
    uint32 reserved_0:1;
    volatile uint32 LOCK2:1;
    volatile uint32 SYS:1;
    volatile uint32 SYT:1;
    volatile uint32 FSD:1;
    volatile uint32 FTD:1;
    volatile uint32 LOCK1:1;
    volatile uint32 ERR:1;
}  bf_GTM_DPLL_STATUS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_STATUS_bf_type B;
} GTM_DPLL_STATUS_bf_type;

typedef struct {
    volatile uint32 ID_PMTR_X:9;
    uint32 reserved_0:23;
}  bf_GTM_DPLL_ID_PMTR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_ID_PMTR_bf_type B;
} GTM_DPLL_ID_PMTR_bf_type;

typedef struct {
    volatile uint32 MLT:10;
    volatile uint32 IFP:1;
    uint32 reserved_2:15;
    volatile uint32 AMT:1;
    uint32 reserved_1:1;
    volatile uint32 IDT:1;
    uint32 reserved_0:2;
    volatile uint32 RMO:1;
}  bf_GTM_DPLL_CTRL_0_SHADOW_TRIGGER_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_0_SHADOW_TRIGGER_bf_type B;
} GTM_DPLL_CTRL_0_SHADOW_TRIGGER_bf_type;

typedef struct {
    uint32 reserved_3:10;
    volatile uint32 IFP:1;
    uint32 reserved_2:14;
    volatile uint32 AMS:1;
    uint32 reserved_1:1;
    volatile uint32 IDS:1;
    uint32 reserved_0:3;
    volatile uint32 RMO:1;
}  bf_GTM_DPLL_CTRL_0_SHADOW_STATE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_0_SHADOW_STATE_bf_type B;
} GTM_DPLL_CTRL_0_SHADOW_STATE_bf_type;

typedef struct {
    volatile uint32 DMO:1;
    uint32 reserved_1:2;
    volatile uint32 COA:1;
    volatile uint32 PIT:1;
    volatile uint32 SGE1:1;
    volatile uint32 DLM1:1;
    volatile uint32 PCM1:1;
    uint32 reserved_0:24;
}  bf_GTM_DPLL_CTRL_1_SHADOW_TRIGGER_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_1_SHADOW_TRIGGER_bf_type B;
} GTM_DPLL_CTRL_1_SHADOW_TRIGGER_bf_type;

typedef struct {
    volatile uint32 DMO:1;
    uint32 reserved_2:2;
    volatile uint32 COA:1;
    uint32 reserved_1:1;
    volatile uint32 SGE1:1;
    volatile uint32 DLM1:1;
    volatile uint32 PCM1:1;
    volatile uint32 SGE2:1;
    volatile uint32 DLM2:1;
    volatile uint32 PCM2:1;
    uint32 reserved_0:21;
}  bf_GTM_DPLL_CTRL_1_SHADOW_STATE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_1_SHADOW_STATE_bf_type B;
} GTM_DPLL_CTRL_1_SHADOW_STATE_bf_type;

typedef struct {
    volatile uint32 INIT_1A:1;
    volatile uint32 INIT_1BC:1;
    volatile uint32 INIT_2:1;
    uint32 reserved_1:1;
    volatile uint32 INIT_RAM:1;
    uint32 reserved_0:27;
}  bf_GTM_DPLL_RAM_INI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RAM_INI_bf_type B;
} GTM_DPLL_RAM_INI_bf_type;

typedef struct {
    volatile uint32 DATA:32;
}  bf_GTM_DPLL_RR1A_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RR1A_bf_type B;
} GTM_DPLL_RR1A_bf_type;

typedef struct {
    volatile uint32 TRIGGER_TS:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TS_T_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TS_T_bf_type B;
} GTM_DPLL_TS_T_bf_type;

typedef struct {
    volatile uint32 TRIGGER_TS_OLD:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TS_T_OLD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TS_T_OLD_bf_type B;
} GTM_DPLL_TS_T_OLD_bf_type;

typedef struct {
    volatile uint32 TRIGGER_FT:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_FTV_T_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_FTV_T_bf_type B;
} GTM_DPLL_FTV_T_bf_type;

typedef struct {
    volatile uint32 STATE_TS:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TS_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TS_S_bf_type B;
} GTM_DPLL_TS_S_bf_type;

typedef struct {
    volatile uint32 STATE_TS_OLD:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TS_S_OLD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TS_S_OLD_bf_type B;
} GTM_DPLL_TS_S_OLD_bf_type;

typedef struct {
    volatile uint32 STATE_FT:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_FTV_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_FTV_S_bf_type B;
} GTM_DPLL_FTV_S_bf_type;

typedef struct {
    volatile uint32 THMI:16;
    volatile uint32 NOT_USED:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_THMI_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_THMI_bf_type B;
} GTM_DPLL_THMI_bf_type;

typedef struct {
    volatile uint32 THMA:16;
    volatile uint32 NOT_USED:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_THMA_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_THMA_bf_type B;
} GTM_DPLL_THMA_bf_type;

typedef struct {
    volatile uint32 THVAL:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_THVAL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_THVAL_bf_type B;
} GTM_DPLL_THVAL_bf_type;

typedef struct {
    volatile uint32 TOV_DB:10;
    volatile uint32 TOV_DW:6;
    volatile uint32 NOT_USED:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TOV_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TOV_bf_type B;
} GTM_DPLL_TOV_bf_type;

typedef struct {
    volatile uint32 DB:10;
    volatile uint32 DW:6;
    volatile uint32 NOT_USED:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TOV_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TOV_S_bf_type B;
} GTM_DPLL_TOV_S_bf_type;

typedef struct {
    volatile uint32 ADD_IN_CAL1:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_ADD_IN_CAL1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_ADD_IN_CAL1_bf_type B;
} GTM_DPLL_ADD_IN_CAL1_bf_type;

typedef struct {
    volatile uint32 ADD_IN_CAL2:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_ADD_IN_CAL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_ADD_IN_CAL2_bf_type B;
} GTM_DPLL_ADD_IN_CAL2_bf_type;

typedef struct {
    volatile uint32 MPVAL1:16;
    volatile uint32 SIX1:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_MPVAL1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_MPVAL1_bf_type B;
} GTM_DPLL_MPVAL1_bf_type;

typedef struct {
    volatile uint32 MPVAL2:16;
    volatile uint32 SIX2:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_MPVAL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_MPVAL2_bf_type B;
} GTM_DPLL_MPVAL2_bf_type;

typedef struct {
    volatile uint32 NMB_T_TAR:16;
    volatile uint32 NOT_USED:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_NMB_T_TAR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NMB_T_TAR_bf_type B;
} GTM_DPLL_NMB_T_TAR_bf_type;

typedef struct {
    volatile uint32 NMB_T_TAR_OLD:16;
    volatile uint32 NOT_USED:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_NMB_T_TAR_OLD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NMB_T_TAR_OLD_bf_type B;
} GTM_DPLL_NMB_T_TAR_OLD_bf_type;

typedef struct {
    volatile uint32 NMB_S_TAR:20;
    volatile uint32 NOT_USED:4;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_NMB_S_TAR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NMB_S_TAR_bf_type B;
} GTM_DPLL_NMB_S_TAR_bf_type;

typedef struct {
    volatile uint32 NMB_S_TAR_OLD:20;
    volatile uint32 NOT_USED:4;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_NMB_S_TAR_OLD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NMB_S_TAR_OLD_bf_type B;
} GTM_DPLL_NMB_S_TAR_OLD_bf_type;

typedef struct {
    volatile uint32 RCDT_TX:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_RCDT_TX_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RCDT_TX_bf_type B;
} GTM_DPLL_RCDT_TX_bf_type;

typedef struct {
    volatile uint32 RCDT_SX:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_RCDT_SX_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RCDT_SX_bf_type B;
} GTM_DPLL_RCDT_SX_bf_type;

typedef struct {
    volatile uint32 RCDT_TX_NOM:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_RCDT_TX_NOM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RCDT_TX_NOM_bf_type B;
} GTM_DPLL_RCDT_TX_NOM_bf_type;

typedef struct {
    volatile uint32 RCDT_SX_NOM:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_RCDT_SX_NOM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RCDT_SX_NOM_bf_type B;
} GTM_DPLL_RCDT_SX_NOM_bf_type;

typedef struct {
    volatile uint32 RDT_T_ACT:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_RDT_T_ACT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RDT_T_ACT_bf_type B;
} GTM_DPLL_RDT_T_ACT_bf_type;

typedef struct {
    volatile uint32 RDT_S_ACT:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_RDT_S_ACT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RDT_S_ACT_bf_type B;
} GTM_DPLL_RDT_S_ACT_bf_type;

typedef struct {
    volatile uint32 DT_T_ACT:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_DT_T_ACT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_DT_T_ACT_bf_type B;
} GTM_DPLL_DT_T_ACT_bf_type;

typedef struct {
    volatile uint32 DT_S_ACT:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_DT_S_ACT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_DT_S_ACT_bf_type B;
} GTM_DPLL_DT_S_ACT_bf_type;

typedef struct {
    volatile uint32 EDT_T:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_EDT_T_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_EDT_T_bf_type B;
} GTM_DPLL_EDT_T_bf_type;

typedef struct {
    volatile uint32 MEDT_T:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_MEDT_T_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_MEDT_T_bf_type B;
} GTM_DPLL_MEDT_T_bf_type;

typedef struct {
    volatile uint32 EDT_S:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_EDT_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_EDT_S_bf_type B;
} GTM_DPLL_EDT_S_bf_type;

typedef struct {
    volatile uint32 MEDT_S:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_MEDT_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_MEDT_S_bf_type B;
} GTM_DPLL_MEDT_S_bf_type;

typedef struct {
    volatile uint32 CDT_TX:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CDT_TX_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CDT_TX_bf_type B;
} GTM_DPLL_CDT_TX_bf_type;

typedef struct {
    volatile uint32 CDT_SX:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CDT_SX_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CDT_SX_bf_type B;
} GTM_DPLL_CDT_SX_bf_type;

typedef struct {
    volatile uint32 CDT_TX_NOM:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CDT_TX_NOM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CDT_TX_NOM_bf_type B;
} GTM_DPLL_CDT_TX_NOM_bf_type;

typedef struct {
    volatile uint32 CDT_SX_NOM:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CDT_SX_NOM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CDT_SX_NOM_bf_type B;
} GTM_DPLL_CDT_SX_NOM_bf_type;

typedef struct {
    volatile uint32 TLR:8;
    volatile uint32 NOT_USED:16;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TLR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TLR_bf_type B;
} GTM_DPLL_TLR_bf_type;

typedef struct {
    volatile uint32 SLR:8;
    volatile uint32 NOT_USED:16;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_SLR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_SLR_bf_type B;
} GTM_DPLL_SLR_bf_type;

typedef struct {
    volatile uint32 DB:14;
    volatile uint32 DW:10;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PDT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PDT_bf_type B;
} GTM_DPLL_PDT_bf_type;

typedef struct {
    volatile uint32 MLS1:18;
    volatile uint32 NOT_USED:6;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_MLS1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_MLS1_bf_type B;
} GTM_DPLL_MLS1_bf_type;

typedef struct {
    volatile uint32 MLS2:18;
    volatile uint32 NOT_USED:6;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_MLS2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_MLS2_bf_type B;
} GTM_DPLL_MLS2_bf_type;

typedef struct {
    volatile uint32 CNT_NUM_1:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CNT_NUM_1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CNT_NUM_1_bf_type B;
} GTM_DPLL_CNT_NUM_1_bf_type;

typedef struct {
    volatile uint32 CNT_NUM_2:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CNT_NUM_2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CNT_NUM_2_bf_type B;
} GTM_DPLL_CNT_NUM_2_bf_type;

typedef struct {
    volatile uint32 PVT:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PVT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PVT_bf_type B;
} GTM_DPLL_PVT_bf_type;

typedef struct {
    volatile uint32 PSTC:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PSTC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PSTC_bf_type B;
} GTM_DPLL_PSTC_bf_type;

typedef struct {
    volatile uint32 PSSC:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PSSC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PSSC_bf_type B;
} GTM_DPLL_PSSC_bf_type;

typedef struct {
    volatile uint32 PSTM:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PSTM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PSTM_bf_type B;
} GTM_DPLL_PSTM_bf_type;

typedef struct {
    volatile uint32 PSTM_OLD:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PSTM_OLD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PSTM_OLD_bf_type B;
} GTM_DPLL_PSTM_OLD_bf_type;

typedef struct {
    volatile uint32 PSSM:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PSSM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PSSM_bf_type B;
} GTM_DPLL_PSSM_bf_type;

typedef struct {
    volatile uint32 PSSM_OLD:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PSSM_OLD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PSSM_OLD_bf_type B;
} GTM_DPLL_PSSM_OLD_bf_type;

typedef struct {
    volatile uint32 NMB_T:16;
    volatile uint32 NOT_USED:8;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_NMB_T_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NMB_T_bf_type B;
} GTM_DPLL_NMB_T_bf_type;

typedef struct {
    volatile uint32 NMB_S:20;
    volatile uint32 NOT_USED:4;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_NMB_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NMB_S_bf_type B;
} GTM_DPLL_NMB_S_bf_type;

typedef struct {
    volatile uint32 RDT_S:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_RDT_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RDT_S_bf_type B;
} GTM_DPLL_RDT_S_bf_type;

typedef struct {
    volatile uint32 TSF_S:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TSF_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TSF_S_bf_type B;
} GTM_DPLL_TSF_S_bf_type;

typedef struct {
    volatile uint32 PD_S:16;
    volatile uint32 NS:6;
    volatile uint32 NOT_USED:2;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_ADT_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_ADT_S_bf_type B;
} GTM_DPLL_ADT_S_bf_type;

typedef struct {
    volatile uint32 DT_S:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_DT_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_DT_S_bf_type B;
} GTM_DPLL_DT_S_bf_type;

typedef struct {
    volatile uint32 TSAC:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TSAC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TSAC_bf_type B;
} GTM_DPLL_TSAC_bf_type;

typedef struct {
    volatile uint32 PSAC:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_PSAC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_PSAC_bf_type B;
} GTM_DPLL_PSAC_bf_type;

typedef struct {
    volatile uint32 ACB_0:5;
    uint32 reserved_3:3;
    volatile uint32 ACB_1:5;
    uint32 reserved_2:3;
    volatile uint32 ACB_2:5;
    uint32 reserved_1:3;
    volatile uint32 ACB_3:5;
    uint32 reserved_0:3;
}  bf_GTM_DPLL_ACB_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_ACB_bf_type B;
} GTM_DPLL_ACB_bf_type;

typedef struct {
    volatile uint32 SIP1:1;
    volatile uint32 ERZ1:1;
    volatile uint32 PCMF1:1;
    volatile uint32 FSYL1:1;
    volatile uint32 INCF1:1;
    volatile uint32 PCMF1_INCCNT_B:1;
    volatile uint32 ADT:1;
    volatile uint32 ADS:1;
    volatile uint32 SIP2:1;
    volatile uint32 ERZ2:1;
    volatile uint32 PCMF2:1;
    volatile uint32 FSYL2:1;
    volatile uint32 INCF2:1;
    volatile uint32 PCMF2_INCCNT_B:1;
    volatile uint32 STATE_EXT:1;
    volatile uint32 ACBU:1;
    volatile uint32 WSIP1:1;
    volatile uint32 WERZ1:1;
    volatile uint32 WPCMF1:1;
    volatile uint32 WFSYL1:1;
    volatile uint32 WINCF1:1;
    volatile uint32 WPCMF1_INCCNT_B:1;
    volatile uint32 WADT:1;
    volatile uint32 WADS:1;
    volatile uint32 WSIP2:1;
    volatile uint32 WERZ2:1;
    volatile uint32 WPCMF2:1;
    volatile uint32 WFSYL2:1;
    volatile uint32 WINCF2:1;
    volatile uint32 WPCMF2_INCCNT_B:1;
    volatile uint32 WSTATE_EXT:1;
    volatile uint32 WACBU:1;
}  bf_GTM_DPLL_CTRL_11_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_11_bf_type B;
} GTM_DPLL_CTRL_11_bf_type;

typedef struct {
    volatile uint32 THVAL:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_THVAL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_THVAL2_bf_type B;
} GTM_DPLL_THVAL2_bf_type;

typedef struct {
    volatile uint32 TIDEL:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_TIDEL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_TIDEL_bf_type B;
} GTM_DPLL_TIDEL_bf_type;

typedef struct {
    volatile uint32 SIDEL:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_SIDEL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_SIDEL_bf_type B;
} GTM_DPLL_SIDEL_bf_type;

typedef struct {
    volatile uint32 APS_1C2_EXT:7;
    uint32 reserved_1:8;
    volatile uint32 APS_1C2_STATUS:1;
    volatile uint32 APS_1C2_OLD:7;
    uint32 reserved_0:9;
}  bf_GTM_DPLL_APS_SYNC_EXT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APS_SYNC_EXT_bf_type B;
} GTM_DPLL_APS_SYNC_EXT_bf_type;

typedef struct {
    volatile uint32 SNU:6;
    uint32 reserved_1:10;
    volatile uint32 SYN_NS:6;
    uint32 reserved_0:10;
}  bf_GTM_DPLL_CTRL_EXT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTRL_EXT_bf_type B;
} GTM_DPLL_CTRL_EXT_bf_type;

typedef struct {
    uint32 reserved_2:1;
    volatile uint32 WAPS:1;
    volatile uint32 APS:7;
    uint32 reserved_1:4;
    volatile uint32 WAPS_1C2:1;
    volatile uint32 APS_1C2:7;
    uint32 reserved_0:11;
}  bf_GTM_DPLL_APS_EXT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APS_EXT_bf_type B;
} GTM_DPLL_APS_EXT_bf_type;

typedef struct {
    uint32 reserved_1:2;
    volatile uint32 APS_1C3:7;
    uint32 reserved_0:23;
}  bf_GTM_DPLL_APS_1C3_EXT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_APS_1C3_EXT_bf_type B;
} GTM_DPLL_APS_1C3_EXT_bf_type;

typedef struct {
    volatile uint32 STA_T:8;
    uint32 reserved_2:1;
    volatile uint32 CNT_T:3;
    volatile uint32 STA_S:8;
    uint32 reserved_1:1;
    volatile uint32 CNT_S:3;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_STA_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_STA_bf_type B;
} GTM_DPLL_STA_bf_type;

typedef struct {
    volatile uint32 DPLL_INCF1_OFFSET:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_INCF1_OFFSET_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_INCF1_OFFSET_bf_type B;
} GTM_DPLL_INCF1_OFFSET_bf_type;

typedef struct {
    volatile uint32 DPLL_INCF2_OFFSET:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_INCF2_OFFSET_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_INCF2_OFFSET_bf_type B;
} GTM_DPLL_INCF2_OFFSET_bf_type;

typedef struct {
    volatile uint32 DPLL_DT_T_START:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_DT_T_START_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_DT_T_START_bf_type B;
} GTM_DPLL_DT_T_START_bf_type;

typedef struct {
    volatile uint32 DPLL_DT_S_START:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_DT_S_START_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_DT_S_START_bf_type B;
} GTM_DPLL_DT_S_START_bf_type;

typedef struct {
    volatile uint32 STA_NOTIFY_T:8;
    volatile uint32 STA_NOTIFY_S:8;
    uint32 reserved_0:16;
}  bf_GTM_DPLL_STA_MASK_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_STA_MASK_bf_type B;
} GTM_DPLL_STA_MASK_bf_type;

typedef struct {
    volatile uint32 STA_FLAG_T:1;
    uint32 reserved_1:7;
    volatile uint32 STA_FLAG_S:1;
    volatile uint32 INC_CNT1_FLAG:1;
    volatile uint32 INC_CNT2_FLAG:1;
    uint32 reserved_0:21;
}  bf_GTM_DPLL_STA_FLAG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_STA_FLAG_bf_type B;
} GTM_DPLL_STA_FLAG_bf_type;

typedef struct {
    volatile uint32 INC_CNT1_NOTIFY:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_INC_CNT1_MASK_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_INC_CNT1_MASK_bf_type B;
} GTM_DPLL_INC_CNT1_MASK_bf_type;

typedef struct {
    volatile uint32 INC_CNT2_NOTIFY:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_INC_CNT2_MASK_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_INC_CNT2_MASK_bf_type B;
} GTM_DPLL_INC_CNT2_MASK_bf_type;

typedef struct {
    volatile uint32 SYN_S:7;
    uint32 reserved_2:9;
    volatile uint32 SYN_S_OLD:7;
    uint32 reserved_1:7;
    volatile uint32 WSYN:1;
    uint32 reserved_0:1;
}  bf_GTM_DPLL_NUSC_EXT1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NUSC_EXT1_bf_type B;
} GTM_DPLL_NUSC_EXT1_bf_type;

typedef struct {
    volatile uint32 NUSE:7;
    uint32 reserved_2:8;
    volatile uint32 FSS:1;
    volatile uint32 VSN:7;
    uint32 reserved_1:6;
    volatile uint32 WNUS:1;
    uint32 reserved_0:1;
    volatile uint32 WVSN:1;
}  bf_GTM_DPLL_NUSC_EXT2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_NUSC_EXT2_bf_type B;
} GTM_DPLL_NUSC_EXT2_bf_type;

typedef struct {
    volatile uint32 CTN_MIN:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CTN_MIN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTN_MIN_bf_type B;
} GTM_DPLL_CTN_MIN_bf_type;

typedef struct {
    volatile uint32 CTN_MAX:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CTN_MAX_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CTN_MAX_bf_type B;
} GTM_DPLL_CTN_MAX_bf_type;

typedef struct {
    volatile uint32 CSN_MIN:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CSN_MIN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CSN_MIN_bf_type B;
} GTM_DPLL_CSN_MIN_bf_type;

typedef struct {
    volatile uint32 CSN_MAX:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_CSN_MAX_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_CSN_MAX_bf_type B;
} GTM_DPLL_CSN_MAX_bf_type;

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_DPLL_RR2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_DPLL_RR2_bf_type B;
} GTM_DPLL_RR2_bf_type;

typedef struct {
    GTM_DPLL_CTRL_0_bf_type CTRL_0; 
    GTM_DPLL_CTRL_1_bf_type CTRL_1; 
    GTM_DPLL_CTRL_2_bf_type CTRL_2; 
    GTM_DPLL_CTRL_3_bf_type CTRL_3; 
    GTM_DPLL_CTRL_4_bf_type CTRL_4; 
    GTM_DPLL_CTRL_5_bf_type CTRL_5; 
    GTM_DPLL_ACT_STA_bf_type ACT_STA; 
    GTM_DPLL_OSW_bf_type OSW; 
    GTM_DPLL_AOSV_2_bf_type AOSV_2; 
    GTM_DPLL_APT_bf_type APT; 
    GTM_DPLL_APS_bf_type APS; 
    GTM_DPLL_APT_2C_bf_type APT_2C; 
    GTM_DPLL_APS_1C3_bf_type APS_1C3; 
    GTM_DPLL_NUTC_bf_type NUTC; 
    GTM_DPLL_NUSC_bf_type NUSC; 
    GTM_DPLL_NTI_CNT_bf_type NTI_CNT; 
    GTM_DPLL_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_DPLL_IRQ_EN_bf_type IRQ_EN; 
    GTM_DPLL_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_DPLL_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_DPLL_EIRQ_EN_bf_type EIRQ_EN; 
    volatile uint32 reserved_0[23];
    GTM_DPLL_INC_CNT1_bf_type INC_CNT1; 
    GTM_DPLL_INC_CNT2_bf_type INC_CNT2; 
    GTM_DPLL_APT_SYNC_bf_type APT_SYNC; 
    GTM_DPLL_APS_SYNC_bf_type APS_SYNC; 
    GTM_DPLL_TBU_TS0_T_bf_type TBU_TS0_T; 
    GTM_DPLL_TBU_TS0_S_bf_type TBU_TS0_S; 
    GTM_DPLL_ADD_IN_LD1_bf_type ADD_IN_LD1; 
    GTM_DPLL_ADD_IN_LD2_bf_type ADD_IN_LD2; 
    volatile uint32 reserved_1[11];
    GTM_DPLL_STATUS_bf_type STATUS; 
    GTM_DPLL_ID_PMTR_bf_type ID_PMTR[32]; 
    volatile uint32 reserved_2[24];
    GTM_DPLL_CTRL_0_SHADOW_TRIGGER_bf_type CTRL_0_SHADOW_TRIGGER; 
    GTM_DPLL_CTRL_0_SHADOW_STATE_bf_type CTRL_0_SHADOW_STATE; 
    GTM_DPLL_CTRL_1_SHADOW_TRIGGER_bf_type CTRL_1_SHADOW_TRIGGER; 
    GTM_DPLL_CTRL_1_SHADOW_STATE_bf_type CTRL_1_SHADOW_STATE; 
    volatile uint32 reserved_3[3];
    GTM_DPLL_RAM_INI_bf_type RAM_INI; 
    GTM_DPLL_RR1A_bf_type RR1A[128]; 
    GTM_DPLL_TS_T_bf_type TS_T; 
    GTM_DPLL_TS_T_OLD_bf_type TS_T_OLD; 
    GTM_DPLL_FTV_T_bf_type FTV_T; 
    volatile uint32 reserved_4;
    GTM_DPLL_TS_S_bf_type TS_S; 
    GTM_DPLL_TS_S_OLD_bf_type TS_S_OLD; 
    GTM_DPLL_FTV_S_bf_type FTV_S; 
    volatile uint32 reserved_5;
    GTM_DPLL_THMI_bf_type THMI; 
    GTM_DPLL_THMA_bf_type THMA; 
    GTM_DPLL_THVAL_bf_type THVAL; 
    volatile uint32 reserved_6;
    GTM_DPLL_TOV_bf_type TOV; 
    GTM_DPLL_TOV_S_bf_type TOV_S; 
    GTM_DPLL_ADD_IN_CAL1_bf_type ADD_IN_CAL1; 
    GTM_DPLL_ADD_IN_CAL2_bf_type ADD_IN_CAL2; 
    GTM_DPLL_MPVAL1_bf_type MPVAL1; 
    GTM_DPLL_MPVAL2_bf_type MPVAL2; 
    GTM_DPLL_NMB_T_TAR_bf_type NMB_T_TAR; 
    GTM_DPLL_NMB_T_TAR_OLD_bf_type NMB_T_TAR_OLD; 
    GTM_DPLL_NMB_S_TAR_bf_type NMB_S_TAR; 
    GTM_DPLL_NMB_S_TAR_OLD_bf_type NMB_S_TAR_OLD; 
    volatile uint32 reserved_7[2];
    GTM_DPLL_RCDT_TX_bf_type RCDT_TX; 
    GTM_DPLL_RCDT_SX_bf_type RCDT_SX; 
    GTM_DPLL_RCDT_TX_NOM_bf_type RCDT_TX_NOM; 
    GTM_DPLL_RCDT_SX_NOM_bf_type RCDT_SX_NOM; 
    GTM_DPLL_RDT_T_ACT_bf_type RDT_T_ACT; 
    GTM_DPLL_RDT_S_ACT_bf_type RDT_S_ACT; 
    GTM_DPLL_DT_T_ACT_bf_type DT_T_ACT; 
    GTM_DPLL_DT_S_ACT_bf_type DT_S_ACT; 
    GTM_DPLL_EDT_T_bf_type EDT_T; 
    GTM_DPLL_MEDT_T_bf_type MEDT_T; 
    GTM_DPLL_EDT_S_bf_type EDT_S; 
    GTM_DPLL_MEDT_S_bf_type MEDT_S; 
    GTM_DPLL_CDT_TX_bf_type CDT_TX; 
    GTM_DPLL_CDT_SX_bf_type CDT_SX; 
    GTM_DPLL_CDT_TX_NOM_bf_type CDT_TX_NOM; 
    GTM_DPLL_CDT_SX_NOM_bf_type CDT_SX_NOM; 
    GTM_DPLL_TLR_bf_type TLR; 
    GTM_DPLL_SLR_bf_type SLR; 
    volatile uint32 reserved_8[22];
    GTM_DPLL_PDT_bf_type PDT[32]; 
    volatile uint32 reserved_9[16];
    GTM_DPLL_MLS1_bf_type MLS1; 
    GTM_DPLL_MLS2_bf_type MLS2; 
    GTM_DPLL_CNT_NUM_1_bf_type CNT_NUM_1; 
    GTM_DPLL_CNT_NUM_2_bf_type CNT_NUM_2; 
    GTM_DPLL_PVT_bf_type PVT; 
    volatile uint32 reserved_10[3];
    GTM_DPLL_PSTC_bf_type PSTC; 
    GTM_DPLL_PSSC_bf_type PSSC; 
    GTM_DPLL_PSTM_bf_type PSTM; 
    GTM_DPLL_PSTM_OLD_bf_type PSTM_OLD; 
    GTM_DPLL_PSSM_bf_type PSSM; 
    GTM_DPLL_PSSM_OLD_bf_type PSSM_OLD; 
    GTM_DPLL_NMB_T_bf_type NMB_T; 
    GTM_DPLL_NMB_S_bf_type NMB_S; 
    GTM_DPLL_RDT_S_bf_type RDT_S[64]; 
    GTM_DPLL_TSF_S_bf_type TSF_S[64]; 
    GTM_DPLL_ADT_S_bf_type ADT_S[64]; 
    GTM_DPLL_DT_S_bf_type DT_S[64]; 
    volatile uint32 reserved_11[256];
    GTM_DPLL_TSAC_bf_type TSAC[32]; 
    GTM_DPLL_PSAC_bf_type PSAC[32]; 
    GTM_DPLL_ACB_bf_type ACB[8]; 
    GTM_DPLL_CTRL_11_bf_type CTRL_11; 
    GTM_DPLL_THVAL2_bf_type THVAL2; 
    GTM_DPLL_TIDEL_bf_type TIDEL; 
    GTM_DPLL_SIDEL_bf_type SIDEL; 
    GTM_DPLL_APS_SYNC_EXT_bf_type APS_SYNC_EXT; 
    GTM_DPLL_CTRL_EXT_bf_type CTRL_EXT; 
    GTM_DPLL_APS_EXT_bf_type APS_EXT; 
    GTM_DPLL_APS_1C3_EXT_bf_type APS_1C3_EXT; 
    GTM_DPLL_STA_bf_type STA; 
    GTM_DPLL_INCF1_OFFSET_bf_type INCF1_OFFSET; 
    GTM_DPLL_INCF2_OFFSET_bf_type INCF2_OFFSET; 
    GTM_DPLL_DT_T_START_bf_type DT_T_START; 
    GTM_DPLL_DT_S_START_bf_type DT_S_START; 
    GTM_DPLL_STA_MASK_bf_type STA_MASK; 
    GTM_DPLL_STA_FLAG_bf_type STA_FLAG; 
    GTM_DPLL_INC_CNT1_MASK_bf_type INC_CNT1_MASK; 
    GTM_DPLL_INC_CNT2_MASK_bf_type INC_CNT2_MASK; 
    GTM_DPLL_NUSC_EXT1_bf_type NUSC_EXT1; 
    GTM_DPLL_NUSC_EXT2_bf_type NUSC_EXT2; 
    GTM_DPLL_CTN_MIN_bf_type CTN_MIN; 
    GTM_DPLL_CTN_MAX_bf_type CTN_MAX; 
    GTM_DPLL_CSN_MIN_bf_type CSN_MIN; 
    GTM_DPLL_CSN_MAX_bf_type CSN_MAX; 
    volatile uint32 reserved_12[3105];
    GTM_DPLL_RR2_bf_type RR2[4096]; 
} GTM_DPLL_bf_type;

/*************************************************************************
 * module GTM.CCM.ARP
 *************************************************************************/

typedef struct {
    volatile uint32 ADDR:16;
    volatile uint32 SIZE:4;
    uint32 reserved_1:4;
    volatile uint32 DIS_PROT:1;
    uint32 reserved_0:6;
    volatile uint32 WPROT_AEI:1;
}  bf_GTM_CCM_ARP_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_ARP_CTRL_bf_type B;
} GTM_CCM_ARP_CTRL_bf_type;

typedef struct {
    volatile uint32 WPROT0:1;
    volatile uint32 WPROT1:1;
    volatile uint32 WPROT2:1;
    volatile uint32 WPROT3:1;
    volatile uint32 WPROT4:1;
    volatile uint32 WPROT5:1;
    volatile uint32 WPROT6:1;
    volatile uint32 WPROT7:1;
    uint32 reserved_0:24;
}  bf_GTM_CCM_ARP_PROT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_ARP_PROT_bf_type B;
} GTM_CCM_ARP_PROT_bf_type;

typedef struct {
    GTM_CCM_ARP_CTRL_bf_type CTRL; 
    GTM_CCM_ARP_PROT_bf_type PROT; 
} GTM_CCM_ARP_bf_type;

/*************************************************************************
 * module GTM.CCM
 *************************************************************************/

typedef struct {
    volatile uint32 AEIM_XPT_ADDR:16;
    uint32 reserved_1:8;
    volatile uint32 AEIM_XPT_STA:2;
    uint32 reserved_0:6;
}  bf_GTM_CCM_AEIM_STA_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_AEIM_STA_bf_type B;
} GTM_CCM_AEIM_STA_bf_type;

typedef struct {
    volatile uint32 GRSTEN:1;
    volatile uint32 BRIDGE_MODE_RST:1;
    volatile uint32 SYNC_INPUT_REG:1;
    volatile uint32 CFG_CLOCK_RATE:1;
    volatile uint32 ATOM_OUT_RST:1;
    volatile uint32 ATOM_TRIG_CHAIN:3;
    volatile uint32 TOM_OUT_RST:1;
    volatile uint32 TOM_TRIG_CHAIN:3;
    volatile uint32 RAM_INIT_RST:1;
    volatile uint32 ERM:1;
    volatile uint32 ARU_CONNECT_CONFIG:1;
    uint32 reserved_1:1;
    volatile uint32 IRQ_MODE_LEVEL:1;
    volatile uint32 IRQ_MODE_PULSE:1;
    volatile uint32 IRQ_MODE_PULSE_NOTIFY:1;
    volatile uint32 IRQ_MODE_SINGLE_PULSE:1;
    volatile uint32 ATOM_TRIG_INTCHAIN:4;
    volatile uint32 TOM_TRIG_INTCHAIN:5;
    volatile uint32 INT_CLK_EN_GEN:1;
    uint32 reserved_0:2;
}  bf_GTM_CCM_HW_CONF_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_HW_CONF_bf_type B;
} GTM_CCM_HW_CONF_bf_type;

typedef struct {
    volatile uint32 SRC_CH0:1;
    volatile uint32 SRC_CH1:1;
    volatile uint32 SRC_CH2:1;
    volatile uint32 SRC_CH3:1;
    volatile uint32 SRC_CH4:1;
    volatile uint32 SRC_CH5:1;
    volatile uint32 SRC_CH6:1;
    volatile uint32 SRC_CH7:1;
    uint32 reserved_1:8;
    volatile uint32 SEL_OUT_N_CH0:1;
    volatile uint32 SEL_OUT_N_CH1:1;
    volatile uint32 SEL_OUT_N_CH2:1;
    volatile uint32 SEL_OUT_N_CH3:1;
    volatile uint32 SEL_OUT_N_CH4:1;
    volatile uint32 SEL_OUT_N_CH5:1;
    volatile uint32 SEL_OUT_N_CH6:1;
    volatile uint32 SEL_OUT_N_CH7:1;
    uint32 reserved_0:8;
}  bf_GTM_CCM_TIM_AUX_IN_SRC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_TIM_AUX_IN_SRC_bf_type B;
} GTM_CCM_TIM_AUX_IN_SRC_bf_type;

typedef struct {
    volatile uint32 TIM_I_EXT_CAP_EN:8;
    volatile uint32 TIM_IP1_EXT_CAP_EN:8;
    uint32 reserved_0:16;
}  bf_GTM_CCM_EXT_CAP_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_EXT_CAP_EN_bf_type B;
} GTM_CCM_EXT_CAP_EN_bf_type;

typedef struct {
    volatile uint32 TOM_OUT:16;
    volatile uint32 TOM_OUT_N:16;
}  bf_GTM_CCM_TOM_OUT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_TOM_OUT_bf_type B;
} GTM_CCM_TOM_OUT_bf_type;

typedef struct {
    volatile uint32 ATOM_I_OUT:8;
    volatile uint32 ATOM_I_OUT_N:8;
    volatile uint32 ATOM_IP1_OUT:8;
    volatile uint32 ATOM_IP1_OUT_N:8;
}  bf_GTM_CCM_ATOM_OUT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_ATOM_OUT_bf_type B;
} GTM_CCM_ATOM_OUT_bf_type;

typedef struct {
    volatile uint32 CLK0_SRC:2;
    uint32 reserved_7:2;
    volatile uint32 CLK1_SRC:2;
    uint32 reserved_6:2;
    volatile uint32 CLK2_SRC:2;
    uint32 reserved_5:2;
    volatile uint32 CLK3_SRC:2;
    uint32 reserved_4:2;
    volatile uint32 CLK4_SRC:2;
    uint32 reserved_3:2;
    volatile uint32 CLK5_SRC:2;
    uint32 reserved_2:2;
    volatile uint32 CLK6_SRC:2;
    uint32 reserved_1:2;
    volatile uint32 CLK7_SRC:2;
    uint32 reserved_0:2;
}  bf_GTM_CCM_CMU_CLK_CFG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_CMU_CLK_CFG_bf_type B;
} GTM_CCM_CMU_CLK_CFG_bf_type;

typedef struct {
    volatile uint32 FXCLK0_SRC:4;
    uint32 reserved_0:28;
}  bf_GTM_CCM_CMU_FXCLK_CFG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_CMU_FXCLK_CFG_bf_type B;
} GTM_CCM_CMU_FXCLK_CFG_bf_type;

typedef struct {
    volatile uint32 EN_TIM:1;
    volatile uint32 EN_TOM_SPE_TDTM:1;
    volatile uint32 EN_ATOM_ADTM:1;
    volatile uint32 EN_MCS:1;
    volatile uint32 EN_DPLL_MAP:1;
    volatile uint32 EN_BRC:1;
    volatile uint32 EN_PSM:1;
    volatile uint32 EN_CMP_MON:1;
    uint32 reserved_1:8;
    volatile uint32 CLS_CLK_DIV:2;
    uint32 reserved_0:12;
    volatile uint32 TBU_DIR1:1;
    volatile uint32 TBU_DIR2:1;
}  bf_GTM_CCM_CFG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_CFG_bf_type B;
} GTM_CCM_CFG_bf_type;

typedef struct {
    volatile uint32 CLS_PROT:1;
    uint32 reserved_0:31;
}  bf_GTM_CCM_PROT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CCM_PROT_bf_type B;
} GTM_CCM_PROT_bf_type;

typedef struct {
    GTM_CCM_ARP_bf_type ARP[10]; 
    volatile uint32 reserved_0[98];
    GTM_CCM_AEIM_STA_bf_type AEIM_STA; 
    GTM_CCM_HW_CONF_bf_type HW_CONF; 
    GTM_CCM_TIM_AUX_IN_SRC_bf_type TIM_AUX_IN_SRC; 
    GTM_CCM_EXT_CAP_EN_bf_type EXT_CAP_EN; 
    GTM_CCM_TOM_OUT_bf_type TOM_OUT; 
    GTM_CCM_ATOM_OUT_bf_type ATOM_OUT; 
    GTM_CCM_CMU_CLK_CFG_bf_type CMU_CLK_CFG; 
    GTM_CCM_CMU_FXCLK_CFG_bf_type CMU_FXCLK_CFG; 
    GTM_CCM_CFG_bf_type CFG; 
    GTM_CCM_PROT_bf_type PROT; 
} GTM_CCM_bf_type;

/*************************************************************************
 * module GTM.CDTM.DTM
 *************************************************************************/

typedef struct {
    volatile uint32 CLK_SEL:2;
    volatile uint32 DTM_SEL:2;
    volatile uint32 UPD_MODE:3;
    uint32 reserved_2:1;
    volatile uint32 SR_UPD_EN:1;
    uint32 reserved_1:7;
    volatile uint32 SHUT_OFF_RST:1;
    uint32 reserved_0:15;
}  bf_GTM_CDTM_DTM_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CTRL_bf_type B;
} GTM_CDTM_DTM_CTRL_bf_type;

typedef struct {
    volatile uint32 O1SEL_0:1;
    volatile uint32 I1SEL_0:1;
    uint32 reserved_4:1;
    volatile uint32 SWAP_0:1;
    volatile uint32 O1F_0:2;
    volatile uint32 XDT_EN_0_1:1;
    uint32 reserved_3:1;
    volatile uint32 O1SEL_1:1;
    volatile uint32 I1SEL_1:1;
    volatile uint32 SH_EN_1:1;
    volatile uint32 SWAP_1:1;
    volatile uint32 O1F_1:2;
    uint32 reserved_2:2;
    volatile uint32 O1SEL_2:1;
    volatile uint32 I1SEL_2:1;
    volatile uint32 SH_EN_2:1;
    volatile uint32 SWAP_2:1;
    volatile uint32 O1F_2:2;
    volatile uint32 XDT_EN_2_3:1;
    uint32 reserved_1:1;
    volatile uint32 O1SEL_3:1;
    volatile uint32 I1SEL_3:1;
    volatile uint32 SH_EN_3:1;
    volatile uint32 SWAP_3:1;
    volatile uint32 O1F_3:2;
    uint32 reserved_0:2;
}  bf_GTM_CDTM_DTM_CH_CTRL1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CH_CTRL1_bf_type B;
} GTM_CDTM_DTM_CH_CTRL1_bf_type;

typedef struct {
    volatile uint32 POL0_0:1;
    volatile uint32 OC0_0:1;
    volatile uint32 SL0_0:1;
    volatile uint32 DT0_0:1;
    volatile uint32 POL1_0:1;
    volatile uint32 OC1_0:1;
    volatile uint32 SL1_0:1;
    volatile uint32 DT1_0:1;
    volatile uint32 POL0_1:1;
    volatile uint32 OC0_1:1;
    volatile uint32 SL0_1:1;
    volatile uint32 DT0_1:1;
    volatile uint32 POL1_1:1;
    volatile uint32 OC1_1:1;
    volatile uint32 SL1_1:1;
    volatile uint32 DT1_1:1;
    volatile uint32 POL0_2:1;
    volatile uint32 OC0_2:1;
    volatile uint32 SL0_2:1;
    volatile uint32 DT0_2:1;
    volatile uint32 POL1_2:1;
    volatile uint32 OC1_2:1;
    volatile uint32 SL1_2:1;
    volatile uint32 DT1_2:1;
    volatile uint32 POL0_3:1;
    volatile uint32 OC0_3:1;
    volatile uint32 SL0_3:1;
    volatile uint32 DT0_3:1;
    volatile uint32 POL1_3:1;
    volatile uint32 OC1_3:1;
    volatile uint32 SL1_3:1;
    volatile uint32 DT1_3:1;
}  bf_GTM_CDTM_DTM_CH_CTRL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CH_CTRL2_bf_type B;
} GTM_CDTM_DTM_CH_CTRL2_bf_type;

typedef struct {
    volatile uint32 POL0_0_SR:1;
    volatile uint32 OC0_0_SR:1;
    volatile uint32 SL0_0_SR:1;
    volatile uint32 DT0_0_SR:1;
    volatile uint32 POL1_0_SR:1;
    volatile uint32 OC1_0_SR:1;
    volatile uint32 SL1_0_SR:1;
    volatile uint32 DT1_0_SR:1;
    volatile uint32 POL0_1_SR:1;
    volatile uint32 OC0_1_SR:1;
    volatile uint32 SL0_1_SR:1;
    volatile uint32 DT0_1_SR:1;
    volatile uint32 POL1_1_SR:1;
    volatile uint32 OC1_1_SR:1;
    volatile uint32 SL1_1_SR:1;
    volatile uint32 DT1_1_SR:1;
    volatile uint32 POL0_2_SR:1;
    volatile uint32 OC0_2_SR:1;
    volatile uint32 SL0_2_SR:1;
    volatile uint32 DT0_2_SR:1;
    volatile uint32 POL1_2_SR:1;
    volatile uint32 OC1_2_SR:1;
    volatile uint32 SL1_2_SR:1;
    volatile uint32 DT1_2_SR:1;
    volatile uint32 POL0_3_SR:1;
    volatile uint32 OC0_3_SR:1;
    volatile uint32 SL0_3_SR:1;
    volatile uint32 DT0_3_SR:1;
    volatile uint32 POL1_3_SR:1;
    volatile uint32 OC1_3_SR:1;
    volatile uint32 SL1_3_SR:1;
    volatile uint32 DT1_3_SR:1;
}  bf_GTM_CDTM_DTM_CH_CTRL2_SR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CH_CTRL2_SR_bf_type B;
} GTM_CDTM_DTM_CH_CTRL2_SR_bf_type;

typedef struct {
    volatile uint32 RELBLK:10;
    uint32 reserved_2:6;
    volatile uint32 PSU_IN_SEL:1;
    volatile uint32 IN_POL:1;
    volatile uint32 TIM_SEL:1;
    uint32 reserved_1:1;
    volatile uint32 SHIFT_SEL:2;
    uint32 reserved_0:10;
}  bf_GTM_CDTM_DTM_PS_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_PS_CTRL_bf_type B;
} GTM_CDTM_DTM_PS_CTRL_bf_type;

typedef struct {
    volatile uint32 RELRISE:13;
    uint32 reserved_1:3;
    volatile uint32 RELFALL:13;
    uint32 reserved_0:2;
    volatile uint32 HRES:1;
}  bf_GTM_CDTM_DTM_CH_DTV_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CH_DTV_bf_type B;
} GTM_CDTM_DTM_CH_DTV_bf_type;

typedef struct {
    volatile uint32 SL0_0_SR_SR:1;
    volatile uint32 SL1_0_SR_SR:1;
    volatile uint32 SL0_1_SR_SR:1;
    volatile uint32 SL1_1_SR_SR:1;
    volatile uint32 SL0_2_SR_SR:1;
    volatile uint32 SL1_2_SR_SR:1;
    volatile uint32 SL0_3_SR_SR:1;
    volatile uint32 SL1_3_SR_SR:1;
    uint32 reserved_0:24;
}  bf_GTM_CDTM_DTM_CH_SR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CH_SR_bf_type B;
} GTM_CDTM_DTM_CH_SR_bf_type;

typedef struct {
    volatile uint32 CII0:1;
    volatile uint32 CIS0:1;
    volatile uint32 TSEL0_0:1;
    volatile uint32 TSEL1_0:1;
    uint32 reserved_3:4;
    volatile uint32 CII1:1;
    volatile uint32 CIS1:1;
    volatile uint32 TSEL0_1:1;
    volatile uint32 TSEL1_1:1;
    uint32 reserved_2:4;
    volatile uint32 CII2:1;
    volatile uint32 CIS2:1;
    volatile uint32 TSEL0_2:1;
    volatile uint32 TSEL1_2:1;
    uint32 reserved_1:4;
    volatile uint32 CII3:1;
    volatile uint32 CIS3:1;
    volatile uint32 TSEL0_3:1;
    volatile uint32 TSEL1_3:1;
    uint32 reserved_0:4;
}  bf_GTM_CDTM_DTM_CH_CTRL3_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CH_CTRL3_bf_type B;
} GTM_CDTM_DTM_CH_CTRL3_bf_type;

typedef struct {
    volatile uint32 SHUTOFF_SEL_0:3;
    volatile uint32 SHUTOFF_POL_0:1;
    volatile uint32 UPD_MODE_0:2;
    volatile uint32 SHUT_OFF_RST_0:1;
    volatile uint32 WR_EN_0:1;
    volatile uint32 SHUTOFF_SEL_1:3;
    volatile uint32 SHUTOFF_POL_1:1;
    volatile uint32 UPD_MODE_1:2;
    volatile uint32 SHUT_OFF_RST_1:1;
    volatile uint32 WR_EN_1:1;
    volatile uint32 SHUTOFF_SEL_2:3;
    volatile uint32 SHUTOFF_POL_2:1;
    volatile uint32 UPD_MODE_2:2;
    volatile uint32 SHUT_OFF_RST_2:1;
    volatile uint32 WR_EN_2:1;
    volatile uint32 SHUTOFF_SEL_3:3;
    volatile uint32 SHUTOFF_POL_3:1;
    volatile uint32 UPD_MODE_3:2;
    volatile uint32 SHUT_OFF_RST_3:1;
    volatile uint32 WR_EN_3:1;
}  bf_GTM_CDTM_DTM_CTRL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CTRL2_bf_type B;
} GTM_CDTM_DTM_CTRL2_bf_type;

typedef struct {
    volatile uint32 RELRISE_SR:13;
    uint32 reserved_2:1;
    volatile uint32 RELRISE_UPD_FE0RE1:1;
    volatile uint32 RELRISE_UPD_EN:1;
    volatile uint32 RELFALL_SR:13;
    uint32 reserved_0:1;
    volatile uint32 RELFALL_UPD_FE0RE1:1;
    volatile uint32 RELFALL_UPD_EN:1;
}  bf_GTM_CDTM_DTM_CH_DTV_SR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CDTM_DTM_CH_DTV_SR_bf_type B;
} GTM_CDTM_DTM_CH_DTV_SR_bf_type;

typedef struct {
    GTM_CDTM_DTM_CTRL_bf_type CTRL; 
    GTM_CDTM_DTM_CH_CTRL1_bf_type CH_CTRL1; 
    GTM_CDTM_DTM_CH_CTRL2_bf_type CH_CTRL2; 
    GTM_CDTM_DTM_CH_CTRL2_SR_bf_type CH_CTRL2_SR; 
    GTM_CDTM_DTM_PS_CTRL_bf_type PS_CTRL; 
    GTM_CDTM_DTM_CH_DTV_bf_type CH_DTV[4]; 
    GTM_CDTM_DTM_CH_SR_bf_type CH_SR; 
    GTM_CDTM_DTM_CH_CTRL3_bf_type CH_CTRL3; 
    GTM_CDTM_DTM_CTRL2_bf_type CTRL2;
    GTM_CDTM_DTM_CH_DTV_SR_bf_type CH_DTV_SR[4];
} GTM_CDTM_DTM_bf_type;

/*************************************************************************
 * module GTM.CDTM
 *************************************************************************/

typedef struct {
    GTM_CDTM_DTM_bf_type DTM[6]; 
    volatile uint32 reserved_0[160];
} GTM_CDTM_bf_type;

/*************************************************************************
 * module GTM.ATOM.CH
 *************************************************************************/

typedef struct {
    volatile uint32 RDADDR0:9;
    uint32 reserved_1:7;
    volatile uint32 RDADDR1:9;
    uint32 reserved_0:7;
}  bf_GTM_ATOM_CH_RDADDR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_RDADDR_bf_type B;
} GTM_ATOM_CH_RDADDR_bf_type;

typedef struct {
    volatile uint32 MODE:2;
    volatile uint32 TB12_SEL:1;
    volatile uint32 ARU_EN:1;
    volatile uint32 ACB:5;
    volatile uint32 CMP_CTRL:1;
    volatile uint32 EUPM:1;
    volatile uint32 SL:1;
    volatile uint32 CLK_SRC_SR:4;
    volatile uint32 WR_REQ:1;
    volatile uint32 TRIG_PULSE:1;
    volatile uint32 UDMODE:2;
    volatile uint32 RST_CCU0:1;
    volatile uint32 OSM_TRIG:1;
    volatile uint32 EXT_TRIG:1;
    volatile uint32 EXTTRIGOUT:1;
    volatile uint32 TRIGOUT:1;
    volatile uint32 SLA:1;
    volatile uint32 OSM:1;
    volatile uint32 ABM:1;
    uint32 reserved_0:1;
    volatile uint32 EXT_FUPD:1;
    volatile uint32 SOMB:1;
    volatile uint32 FREEZE:1;
}  bf_GTM_ATOM_CH_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_CTRL_bf_type B;
} GTM_ATOM_CH_CTRL_bf_type;

typedef struct {
    uint32 reserved_0:11;
    volatile uint32 SL:1;
    volatile uint32 CLK_SRC_SR:4;
    uint32 reserved_1:16;
}  bf_GTM_ATOM_CH_CTRL_SR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_CTRL_bf_type B;
} GTM_ATOM_CH_CTRL_SR_bf_type;

typedef struct {
    volatile uint32 SR0:24;
    uint32 reserved_0:8;
}  bf_GTM_ATOM_CH_SR0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_SR0_bf_type B;
} GTM_ATOM_CH_SR0_bf_type;

typedef struct {
    volatile uint32 SR1:24;
    uint32 reserved_0:8;
}  bf_GTM_ATOM_CH_SR1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_SR1_bf_type B;
} GTM_ATOM_CH_SR1_bf_type;

typedef struct {
    volatile uint32 CM0:24;
    uint32 reserved_0:8;
}  bf_GTM_ATOM_CH_CM0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_CM0_bf_type B;
} GTM_ATOM_CH_CM0_bf_type;

typedef struct {
    volatile uint32 CM1:24;
    uint32 reserved_0:8;
}  bf_GTM_ATOM_CH_CM1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_CM1_bf_type B;
} GTM_ATOM_CH_CM1_bf_type;

typedef struct {
    volatile uint32 CN0:24;
    uint32 reserved_0:8;
}  bf_GTM_ATOM_CH_CN0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_CN0_bf_type B;
} GTM_ATOM_CH_CN0_bf_type;

typedef struct {
    volatile uint32 OL:1;
    uint32 reserved_1:15;
    volatile uint32 ACBI:5;
    volatile uint32 DV:1;
    volatile uint32 WRF:1;
    volatile uint32 DR:1;
    volatile uint32 ACBO:5;
    uint32 reserved_0:3;
}  bf_GTM_ATOM_CH_STAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_STAT_bf_type B;
} GTM_ATOM_CH_STAT_bf_type;

typedef struct {
    volatile uint32 CCU0TC:1;
    volatile uint32 CCU1TC:1;
    uint32 reserved_0:30;
}  bf_GTM_ATOM_CH_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_IRQ_NOTIFY_bf_type B;
} GTM_ATOM_CH_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 CCU0TC_IRQ_EN:1;
    volatile uint32 CCU1TC_IRQ_EN:1;
    uint32 reserved_0:30;
}  bf_GTM_ATOM_CH_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_IRQ_EN_bf_type B;
} GTM_ATOM_CH_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_CCU0TC:1;
    volatile uint32 TRG_CCU1TC:1;
    uint32 reserved_0:30;
}  bf_GTM_ATOM_CH_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_IRQ_FORCINT_bf_type B;
} GTM_ATOM_CH_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_ATOM_CH_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_CH_IRQ_MODE_bf_type B;
} GTM_ATOM_CH_IRQ_MODE_bf_type;

typedef struct {
    GTM_ATOM_CH_RDADDR_bf_type RDADDR; 
    GTM_ATOM_CH_CTRL_bf_type CTRL; 
    GTM_ATOM_CH_SR0_bf_type SR0; 
    GTM_ATOM_CH_SR1_bf_type SR1; 
    GTM_ATOM_CH_CM0_bf_type CM0; 
    GTM_ATOM_CH_CM1_bf_type CM1; 
    GTM_ATOM_CH_CN0_bf_type CN0; 
    GTM_ATOM_CH_STAT_bf_type STAT; 
    GTM_ATOM_CH_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_ATOM_CH_IRQ_EN_bf_type IRQ_EN; 
    GTM_ATOM_CH_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_ATOM_CH_IRQ_MODE_bf_type IRQ_MODE; 
    volatile uint32 reserved_0[1];
    GTM_ATOM_CH_CTRL_SR_bf_type CTRL_SR;
    volatile uint32 reserved_1[18];
} GTM_ATOM_CH_bf_type;

/*************************************************************************
 * module GTM.ATOM.AGC
 *************************************************************************/

typedef struct {
    volatile uint32 HOST_TRIG:1;
    uint32 reserved_0:7;
    volatile uint32 RST_CH0:1;
    volatile uint32 RST_CH1:1;
    volatile uint32 RST_CH2:1;
    volatile uint32 RST_CH3:1;
    volatile uint32 RST_CH4:1;
    volatile uint32 RST_CH5:1;
    volatile uint32 RST_CH6:1;
    volatile uint32 RST_CH7:1;
    volatile uint32 UPEN_CTRL0:2;
    volatile uint32 UPEN_CTRL1:2;
    volatile uint32 UPEN_CTRL2:2;
    volatile uint32 UPEN_CTRL3:2;
    volatile uint32 UPEN_CTRL4:2;
    volatile uint32 UPEN_CTRL5:2;
    volatile uint32 UPEN_CTRL6:2;
    volatile uint32 UPEN_CTRL7:2;
}  bf_GTM_ATOM_AGC_GLB_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_AGC_GLB_CTRL_bf_type B;
} GTM_ATOM_AGC_GLB_CTRL_bf_type;

typedef struct {
    volatile uint32 ENDIS_CTRL0:2;
    volatile uint32 ENDIS_CTRL1:2;
    volatile uint32 ENDIS_CTRL2:2;
    volatile uint32 ENDIS_CTRL3:2;
    volatile uint32 ENDIS_CTRL4:2;
    volatile uint32 ENDIS_CTRL5:2;
    volatile uint32 ENDIS_CTRL6:2;
    volatile uint32 ENDIS_CTRL7:2;
    uint32 reserved_0:16;
}  bf_GTM_ATOM_AGC_ENDIS_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_AGC_ENDIS_CTRL_bf_type B;
} GTM_ATOM_AGC_ENDIS_CTRL_bf_type;

typedef struct {
    volatile uint32 ENDIS_STAT0:2;
    volatile uint32 ENDIS_STAT1:2;
    volatile uint32 ENDIS_STAT2:2;
    volatile uint32 ENDIS_STAT3:2;
    volatile uint32 ENDIS_STAT4:2;
    volatile uint32 ENDIS_STAT5:2;
    volatile uint32 ENDIS_STAT6:2;
    volatile uint32 ENDIS_STAT7:2;
    uint32 reserved_0:16;
}  bf_GTM_ATOM_AGC_ENDIS_STAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_AGC_ENDIS_STAT_bf_type B;
} GTM_ATOM_AGC_ENDIS_STAT_bf_type;

typedef struct {
    volatile uint32 ACT_TB:24;
    volatile uint32 TB_TRIG:1;
    volatile uint32 TBU_SEL:2;
    uint32 reserved_0:5;
}  bf_GTM_ATOM_AGC_ACT_TB_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_AGC_ACT_TB_bf_type B;
} GTM_ATOM_AGC_ACT_TB_bf_type;

typedef struct {
    volatile uint32 OUTEN_CTRL0:2;
    volatile uint32 OUTEN_CTRL1:2;
    volatile uint32 OUTEN_CTRL2:2;
    volatile uint32 OUTEN_CTRL3:2;
    volatile uint32 OUTEN_CTRL4:2;
    volatile uint32 OUTEN_CTRL5:2;
    volatile uint32 OUTEN_CTRL6:2;
    volatile uint32 OUTEN_CTRL7:2;
    uint32 reserved_0:16;
}  bf_GTM_ATOM_AGC_OUTEN_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_AGC_OUTEN_CTRL_bf_type B;
} GTM_ATOM_AGC_OUTEN_CTRL_bf_type;

typedef struct {
    volatile uint32 OUTEN_STAT0:2;
    volatile uint32 OUTEN_STAT1:2;
    volatile uint32 OUTEN_STAT2:2;
    volatile uint32 OUTEN_STAT3:2;
    volatile uint32 OUTEN_STAT4:2;
    volatile uint32 OUTEN_STAT5:2;
    volatile uint32 OUTEN_STAT6:2;
    volatile uint32 OUTEN_STAT7:2;
    uint32 reserved_0:16;
}  bf_GTM_ATOM_AGC_OUTEN_STAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_AGC_OUTEN_STAT_bf_type B;
} GTM_ATOM_AGC_OUTEN_STAT_bf_type;

typedef struct {
    volatile uint32 FUPD_CTRL0:2;
    volatile uint32 FUPD_CTRL1:2;
    volatile uint32 FUPD_CTRL2:2;
    volatile uint32 FUPD_CTRL3:2;
    volatile uint32 FUPD_CTRL4:2;
    volatile uint32 FUPD_CTRL5:2;
    volatile uint32 FUPD_CTRL6:2;
    volatile uint32 FUPD_CTRL7:2;
    volatile uint32 RSTCN0_CH0:2;
    volatile uint32 RSTCN0_CH1:2;
    volatile uint32 RSTCN0_CH2:2;
    volatile uint32 RSTCN0_CH3:2;
    volatile uint32 RSTCN0_CH4:2;
    volatile uint32 RSTCN0_CH5:2;
    volatile uint32 RSTCN0_CH6:2;
    volatile uint32 RSTCN0_CH7:2;
}  bf_GTM_ATOM_AGC_FUPD_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_AGC_FUPD_CTRL_bf_type B;
} GTM_ATOM_AGC_FUPD_CTRL_bf_type;

typedef struct {
    volatile uint32 INT_TRIG0:2;
    volatile uint32 INT_TRIG1:2;
    volatile uint32 INT_TRIG2:2;
    volatile uint32 INT_TRIG3:2;
    volatile uint32 INT_TRIG4:2;
    volatile uint32 INT_TRIG5:2;
    volatile uint32 INT_TRIG6:2;
    volatile uint32 INT_TRIG7:2;
    uint32 reserved_0:16;
}  bf_GTM_ATOM_AGC_INT_TRIG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ATOM_AGC_INT_TRIG_bf_type B;
} GTM_ATOM_AGC_INT_TRIG_bf_type;

typedef struct {
    volatile uint32 reserved_0[256];
    volatile uint32 reserved_1[16];
    GTM_ATOM_AGC_GLB_CTRL_bf_type GLB_CTRL; 
    GTM_ATOM_AGC_ENDIS_CTRL_bf_type ENDIS_CTRL; 
    GTM_ATOM_AGC_ENDIS_STAT_bf_type ENDIS_STAT; 
    GTM_ATOM_AGC_ACT_TB_bf_type ACT_TB; 
    GTM_ATOM_AGC_OUTEN_CTRL_bf_type OUTEN_CTRL; 
    GTM_ATOM_AGC_OUTEN_STAT_bf_type OUTEN_STAT; 
    GTM_ATOM_AGC_FUPD_CTRL_bf_type FUPD_CTRL; 
    GTM_ATOM_AGC_INT_TRIG_bf_type INT_TRIG; 
    volatile uint32 reserved_2[8];
} GTM_ATOM_AGC_bf_type;

/*************************************************************************
 * union GTM.ATOM
 *************************************************************************/

typedef union {
    GTM_ATOM_CH_bf_type CH[8]; 
    GTM_ATOM_AGC_bf_type AGC; 
    volatile uint32 reserved[512];
} GTM_ATOM_bf_type;

/*************************************************************************
 * module GTM.MCS.CH
 *************************************************************************/

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_MCS_CH_R0_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_R0_bf_type B;
} GTM_MCS_CH_R0_bf_type;

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_MCS_CH_R1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_R1_bf_type B;
} GTM_MCS_CH_R1_bf_type;

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_MCS_CH_R2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_R2_bf_type B;
} GTM_MCS_CH_R2_bf_type;

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_MCS_CH_R3_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_R3_bf_type B;
} GTM_MCS_CH_R3_bf_type;

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_MCS_CH_R4_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_R4_bf_type B;
} GTM_MCS_CH_R4_bf_type;

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_MCS_CH_R5_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_R5_bf_type B;
} GTM_MCS_CH_R5_bf_type;

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_MCS_CH_R6_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_R6_bf_type B;
} GTM_MCS_CH_R6_bf_type;

typedef struct {
    volatile uint32 DATA:24;
    uint32 reserved_0:8;
}  bf_GTM_MCS_CH_R7_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_R7_bf_type B;
} GTM_MCS_CH_R7_bf_type;

typedef struct {
    volatile uint32 EN:1;
    volatile uint32 IRQ:1;
    volatile uint32 ERR:1;
    uint32 reserved_2:1;
    volatile uint32 CY:1;
    volatile uint32 Z:1;
    volatile uint32 V:1;
    volatile uint32 N:1;
    volatile uint32 CAT:1;
    volatile uint32 CWT:1;
    volatile uint32 SAT:1;
    uint32 reserved_1:8;
    //volatile uint32 SP_CNT:3;
    uint32 reserved_0:13;
}  bf_GTM_MCS_CH_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_CTRL_bf_type B;
} GTM_MCS_CH_CTRL_bf_type;

typedef struct {
    volatile uint32 ACB0:1;
    volatile uint32 ACB1:1;
    volatile uint32 ACB2:1;
    volatile uint32 ACB3:1;
    volatile uint32 ACB4:1;
    uint32 reserved_0:27;
}  bf_GTM_MCS_CH_ACB_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_ACB_bf_type B;
} GTM_MCS_CH_ACB_bf_type;

typedef struct {
    volatile uint32 DATA:8;
    uint32 reserved_0:24;
}  bf_GTM_MCS_CH_MHB_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_MHB_bf_type B;
} GTM_MCS_CH_MHB_bf_type;

typedef struct {
    volatile uint32 PC:16;
    uint32 reserved_0:16;
}  bf_GTM_MCS_CH_PC_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_PC_bf_type B;
} GTM_MCS_CH_PC_bf_type;

typedef struct {
    volatile uint32 MCS_IRQ:1;
    volatile uint32 STK_ERR_IRQ:1;
    volatile uint32 ERR_IRQ:1;
    uint32 reserved_0:29;
}  bf_GTM_MCS_CH_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_IRQ_NOTIFY_bf_type B;
} GTM_MCS_CH_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 MCS_IRQ_EN:1;
    volatile uint32 STK_ERR_IRQ_EN:1;
    volatile uint32 ERR_IRQ_EN:1;
    uint32 reserved_0:29;
}  bf_GTM_MCS_CH_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_IRQ_EN_bf_type B;
} GTM_MCS_CH_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_MCS_IRQ:1;
    volatile uint32 TRG_STK_ERR_IRQ:1;
    volatile uint32 TRG_ERR_IRQ:1;
    uint32 reserved_0:29;
}  bf_GTM_MCS_CH_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_IRQ_FORCINT_bf_type B;
} GTM_MCS_CH_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_MCS_CH_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_IRQ_MODE_bf_type B;
} GTM_MCS_CH_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 MCS_EIRQ_EN0:1;
    volatile uint32 STK_ERR_EIRQ_EN:1;
    volatile uint32 ERR_EIRQ_EN:1;
    uint32 reserved_0:29;
}  bf_GTM_MCS_CH_EIRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_CH_EIRQ_EN_bf_type B;
} GTM_MCS_CH_EIRQ_EN_bf_type;

typedef struct {
    GTM_MCS_CH_R0_bf_type R0; 
    GTM_MCS_CH_R1_bf_type R1; 
    GTM_MCS_CH_R2_bf_type R2; 
    GTM_MCS_CH_R3_bf_type R3; 
    GTM_MCS_CH_R4_bf_type R4; 
    GTM_MCS_CH_R5_bf_type R5; 
    GTM_MCS_CH_R6_bf_type R6; 
    GTM_MCS_CH_R7_bf_type R7; 
    GTM_MCS_CH_CTRL_bf_type CTRL; 
    GTM_MCS_CH_ACB_bf_type ACB; 
    volatile uint32 reserved_0[5];
    GTM_MCS_CH_MHB_bf_type MHB; 
    volatile uint32 reserved_2[40];
    GTM_MCS_CH_PC_bf_type PC; 
    GTM_MCS_CH_IRQ_NOTIFY_bf_type IRQ_NOTIFY; 
    GTM_MCS_CH_IRQ_EN_bf_type IRQ_EN; 
    GTM_MCS_CH_IRQ_FORCINT_bf_type IRQ_FORCINT; 
    GTM_MCS_CH_IRQ_MODE_bf_type IRQ_MODE; 
    GTM_MCS_CH_EIRQ_EN_bf_type EIRQ_EN; 
    volatile uint32 reserved_1[2];
} GTM_MCS_CH_bf_type;

/*************************************************************************
 * module GTM.MCS.GC
 *************************************************************************/

typedef struct {
    volatile uint32 TRG0:1;
    volatile uint32 TRG1:1;
    volatile uint32 TRG2:1;
    volatile uint32 TRG3:1;
    volatile uint32 TRG4:1;
    volatile uint32 TRG5:1;
    volatile uint32 TRG6:1;
    volatile uint32 TRG7:1;
    volatile uint32 TRG8:1;
    volatile uint32 TRG9:1;
    volatile uint32 TRG10:1;
    volatile uint32 TRG11:1;
    volatile uint32 TRG12:1;
    volatile uint32 TRG13:1;
    volatile uint32 TRG14:1;
    volatile uint32 TRG15:1;
    volatile uint32 TRG16:1;
    volatile uint32 TRG17:1;
    volatile uint32 TRG18:1;
    volatile uint32 TRG19:1;
    volatile uint32 TRG20:1;
    volatile uint32 TRG21:1;
    volatile uint32 TRG22:1;
    volatile uint32 TRG23:1;
    uint32 reserved_0:8;
}  bf_GTM_MCS_GC_CTRG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_GC_CTRG_bf_type B;
} GTM_MCS_GC_CTRG_bf_type;

typedef struct {
    volatile uint32 TRG0:1;
    volatile uint32 TRG1:1;
    volatile uint32 TRG2:1;
    volatile uint32 TRG3:1;
    volatile uint32 TRG4:1;
    volatile uint32 TRG5:1;
    volatile uint32 TRG6:1;
    volatile uint32 TRG7:1;
    volatile uint32 TRG8:1;
    volatile uint32 TRG9:1;
    volatile uint32 TRG10:1;
    volatile uint32 TRG11:1;
    volatile uint32 TRG12:1;
    volatile uint32 TRG13:1;
    volatile uint32 TRG14:1;
    volatile uint32 TRG15:1;
    volatile uint32 TRG16:1;
    volatile uint32 TRG17:1;
    volatile uint32 TRG18:1;
    volatile uint32 TRG19:1;
    volatile uint32 TRG20:1;
    volatile uint32 TRG21:1;
    volatile uint32 TRG22:1;
    volatile uint32 TRG23:1;
    uint32 reserved_0:8;
}  bf_GTM_MCS_GC_STRG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_GC_STRG_bf_type B;
} GTM_MCS_GC_STRG_bf_type;

typedef struct {
    volatile uint32 WPROT0:2;
    volatile uint32 WPROT1:2;
    volatile uint32 WPROT2:2;
    volatile uint32 WPROT3:2;
    volatile uint32 WPROT4:2;
    volatile uint32 WPROT5:2;
    volatile uint32 WPROT6:2;
    volatile uint32 WPROT7:2;
    uint32 reserved_0:16;
}  bf_GTM_MCS_GC_REG_PROT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_GC_REG_PROT_bf_type B;
} GTM_MCS_GC_REG_PROT_bf_type;

typedef struct {
    volatile uint32 SCD_MODE:2;
    uint32 reserved_4:6;
    volatile uint32 SCD_CH:4;
    uint32 reserved_3:4;
    volatile uint32 RAM_RST:1;
    volatile uint32 HLT_SP_OFL:1;
    uint32 reserved_2:2;
    volatile uint32 ERR_SRC_ID:3;
    uint32 reserved_1:1;
    volatile uint32 EN_TIM_FOUT:1;
    volatile uint32 EN_XOREG:1;
    volatile uint32 HLT_AEIM_ERR:1;
    uint32 reserved_0:5;
}  bf_GTM_MCS_GC_CTRL_STAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_GC_CTRL_STAT_bf_type B;
} GTM_MCS_GC_CTRL_STAT_bf_type;

typedef struct {
    volatile uint32 RST0:1;
    volatile uint32 RST1:1;
    volatile uint32 RST2:1;
    volatile uint32 RST3:1;
    volatile uint32 RST4:1;
    volatile uint32 RST5:1;
    volatile uint32 RST6:1;
    volatile uint32 RST7:1;
    uint32 reserved_0:24;
}  bf_GTM_MCS_GC_RESET_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_GC_RESET_bf_type B;
} GTM_MCS_GC_RESET_bf_type;

typedef struct {
    volatile uint32 CAT0:1;
    volatile uint32 CAT1:1;
    volatile uint32 CAT2:1;
    volatile uint32 CAT3:1;
    volatile uint32 CAT4:1;
    volatile uint32 CAT5:1;
    volatile uint32 CAT6:1;
    volatile uint32 CAT7:1;
    uint32 reserved_0:24;
}  bf_GTM_MCS_GC_CAT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_GC_CAT_bf_type B;
} GTM_MCS_GC_CAT_bf_type;

typedef struct {
    volatile uint32 CWT0:1;
    volatile uint32 CWT1:1;
    volatile uint32 CWT2:1;
    volatile uint32 CWT3:1;
    volatile uint32 CWT4:1;
    volatile uint32 CWT5:1;
    volatile uint32 CWT6:1;
    volatile uint32 CWT7:1;
    uint32 reserved_0:24;
}  bf_GTM_MCS_GC_CWT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_GC_CWT_bf_type B;
} GTM_MCS_GC_CWT_bf_type;

typedef struct {
    volatile uint32 ERR0:1;
    volatile uint32 ERR1:1;
    volatile uint32 ERR2:1;
    volatile uint32 ERR3:1;
    volatile uint32 ERR4:1;
    volatile uint32 ERR5:1;
    volatile uint32 ERR6:1;
    volatile uint32 ERR7:1;
    uint32 reserved_0:24;
}  bf_GTM_MCS_GC_ERR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_GC_ERR_bf_type B;
} GTM_MCS_GC_ERR_bf_type;


typedef struct {
    volatile uint32 S_IRQ0:1;
    volatile uint32 S_IRQ1:1;
    volatile uint32 S_IRQ2:1;
    volatile uint32 S_IRQ3:1;
    volatile uint32 S_IRQ4:1;
    volatile uint32 S_IRQ5:1;
    volatile uint32 S_IRQ6:1;
    volatile uint32 S_IRQ7:1;
    uint32 reserved_0:24;
}  bf_GTM_MCS_SINT_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_SINT_IRQ_NOTIFY_bf_type B;
} GTM_MCS_SINT_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 S_IRQ0_EN:1;
    volatile uint32 S_IRQ1_EN:1;
    volatile uint32 S_IRQ2_EN:1;
    volatile uint32 S_IRQ3_EN:1;
    volatile uint32 S_IRQ4_EN:1;
    volatile uint32 S_IRQ5_EN:1;
    volatile uint32 S_IRQ6_EN:1;
    volatile uint32 S_IRQ7_EN:1;
    uint32 reserved_0:24;
}  bf_GTM_MCS_SINT_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_SINT_IRQ_EN_bf_type B;
} GTM_MCS_SINT_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_S_IRQ0:1;
    volatile uint32 TRG_S_IRQ1:1;
    volatile uint32 TRG_S_IRQ2:1;
    volatile uint32 TRG_S_IRQ3:1;
    volatile uint32 TRG_S_IRQ4:1;
    volatile uint32 TRG_S_IRQ5:1;
    volatile uint32 TRG_S_IRQ6:1;
    volatile uint32 TRG_S_IRQ7:1;
    uint32 reserved_0:24;
}  bf_GTM_MCS_SINT_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_SINT_IRQ_FORCINT_bf_type B;
} GTM_MCS_SINT_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_MCS_SINT_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_SINT_IRQ_MODE_bf_type B;
} GTM_MCS_SINT_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 EN_CH0:1;
    volatile uint32 EN_CH1:1;
    volatile uint32 EN_CH2:1;
    volatile uint32 EN_CH3:1;
    volatile uint32 EN_CH4:1;
    volatile uint32 EN_CH5:1;
    volatile uint32 EN_CH6:1;
    volatile uint32 EN_CH7:1;
    volatile uint32 SCOPE:2;
    uint32 reserved_0:2;
    volatile uint32 TYPE:3;
    uint32 reserved_1:1;
    volatile uint32 AND:1;
    volatile uint32 NOT:1;
    uint32 reserved_2:14;
}  bf_GTM_MCS_HBP_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_HBP_CTRL_bf_type B;
} GTM_MCS_HBP_CTRL_bf_type;

typedef struct {
    volatile uint32 DATA:32;
}  bf_GTM_MCS_HBP_PATTERN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_HBP_PATTERN_bf_type B;
} GTM_MCS_HBP_PATTERN_bf_type;

typedef struct {
    volatile uint32 HALT_CH0:1;
    volatile uint32 HALT_CH1:1;
    volatile uint32 HALT_CH2:1;
    volatile uint32 HALT_CH3:1;
    volatile uint32 HALT_CH4:1;
    volatile uint32 HALT_CH5:1;
    volatile uint32 HALT_CH6:1;
    volatile uint32 HALT_CH7:1;
    uint32 reserved_0:24;
}  bf_GTM_MCS_HBP_STATUS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_HBP_STATUS_bf_type B;
} GTM_MCS_HBP_STATUS_bf_type;


typedef struct {
    volatile uint32 HBP_IRQ:1;
    uint32 reserved_0:31;
}  bf_GTM_MCS_HBP_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_HBP_IRQ_NOTIFY_bf_type B;
} GTM_MCS_HBP_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 HBP_IRQ_EN:1;
    uint32 reserved_0:31;
}  bf_GTM_MCS_HBP_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_HBP_IRQ_EN_bf_type B;
} GTM_MCS_HBP_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_S_IRQ:1;
    uint32 reserved_0:31;
}  bf_GTM_MCS_HBP_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_HBP_IRQ_FORCINT_bf_type B;
} GTM_MCS_HBP_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_MCS_HBP_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_HBP_IRQ_MODE_bf_type B;
} GTM_MCS_HBP_IRQ_MODE_bf_type;

typedef struct {
    GTM_MCS_HBP_CTRL_bf_type CTRL;
    GTM_MCS_HBP_PATTERN_bf_type PATTERN;
    GTM_MCS_HBP_STATUS_bf_type STATUS;
    GTM_MCS_HBP_IRQ_NOTIFY_bf_type HBP_IRQ_NOTIFY;
    GTM_MCS_HBP_IRQ_EN_bf_type  HBP_IRQ_EN;
    GTM_MCS_HBP_IRQ_FORCINT_bf_type HBP_IRQ_FORCINT;
    GTM_MCS_HBP_IRQ_MODE_bf_type  HBP_IRQ_MODE;
    volatile uint32 reserved_0;
}GTM_MCS_HBP_bf_type;

typedef struct {
    volatile uint32 reserved_0[896];
    volatile uint32 reserved_1[10];
    GTM_MCS_GC_CTRG_bf_type CTRG; 
    GTM_MCS_GC_STRG_bf_type STRG; 
    volatile uint32 reserved_2[52];
    GTM_MCS_GC_CTRL_STAT_bf_type CTRL_STAT;
    GTM_MCS_GC_RESET_bf_type RESET;
    GTM_MCS_GC_CAT_bf_type CAT; 
    GTM_MCS_GC_CWT_bf_type CWT; 
    GTM_MCS_GC_ERR_bf_type ERR; 
    volatile uint32 reserved_3[2];
    GTM_MCS_GC_REG_PROT_bf_type REG_PROT; 
    GTM_MCS_SINT_IRQ_NOTIFY_bf_type SINT_IRQ_NOTIFY;
    GTM_MCS_SINT_IRQ_EN_bf_type  SINT_IRQ_EN;
    GTM_MCS_SINT_IRQ_FORCINT_bf_type SINT_IRQ_FORCINT;
    GTM_MCS_SINT_IRQ_MODE_bf_type  SINT_IRQ_MODE;
    volatile uint32 reserved_4[4];
    GTM_MCS_HBP_bf_type HBP[2];
    volatile uint32 reserved_5[32];
} GTM_MCS_GC_bf_type;

/*************************************************************************
 * union GTM.MCS
 *************************************************************************/

typedef union {
    GTM_MCS_CH_bf_type CH[8]; 
    GTM_MCS_GC_bf_type GC; 
    volatile uint32 reserved[1024];
} GTM_MCS_bf_type;

/*************************************************************************
 * module GTM
 *************************************************************************/

typedef struct {
    volatile uint32 NO:4;
    volatile uint32 STEP:8;
    uint32 reserved_0:4;
    volatile uint32 DEV_CODE1:4;
    volatile uint32 DEV_CODE0:4;
    volatile uint32 MINOR:4;
    volatile uint32 MAJOR:4;
}  bf_GTM_REV_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_REV_bf_type B;
} GTM_REV_bf_type;

typedef struct {
    volatile uint32 RST:1;
    uint32 reserved_1:26;
    volatile uint32 BRIDGE_MODE_WRDIS:1;
    uint32 reserved_0:4;
}  bf_GTM_RST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_RST_bf_type B;
} GTM_RST_bf_type;

typedef struct {
    volatile uint32 RF_PROT:1;
    volatile uint32 TO_MODE:2;
    uint32 reserved_2:1;
    volatile uint32 TO_VAL:8;
    volatile uint32 AEIM_CLUSTER:4;
    uint32 reserved_0:16;
}  bf_GTM_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CTRL_bf_type B;
} GTM_CTRL_bf_type;

typedef struct {
    volatile uint32 TO_ADDR:21;
    uint32 reserved_0:3;
    volatile uint32 TO_W1R0:1;
    uint32 reserved_1:7;
}  bf_GTM_AEI_ADDR_XPT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AEI_ADDR_XPT_bf_type B;
} GTM_AEI_ADDR_XPT_bf_type;


typedef struct {
    volatile uint32 AEI_TO_XPT:1;
    volatile uint32 AEI_USP_ADDR:1;
    volatile uint32 AEI_IM_ADDR:1;
    volatile uint32 AEI_USP_BE:1;
    volatile uint32 AEIM_USP_ADDR:1;
    volatile uint32 AEIM_IM_ADDR:1;
    volatile uint32 AEIM_USP_BE:1;
    volatile uint32 CLK_EN_ERR:1;
    volatile uint32 CLK_PER_ERR:1;
    uint32 reserved_0:15;
    volatile uint32 CLK_EN_ERR_STATE:2;
    uint32 reserved_1:2;
    volatile uint32 CLK_EN_EXP_STATE:2;
    uint32 reserved_2:2;
}  bf_GTM_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_IRQ_NOTIFY_bf_type B;
} GTM_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 AEI_TO_XPT_IRQ_EN:1;
    volatile uint32 AEI_USP_ADDR_IRQ_EN:1;
    volatile uint32 AEI_IM_ADDR_IRQ_EN:1;
    volatile uint32 AEI_USP_BE_IRQ_EN:1;
    volatile uint32 AEIM_USP_ADDR_IRQ_EN:1;
    volatile uint32 AEIM_IM_ADDR_IRQ_EN:1;
    volatile uint32 AEIM_USP_BE_IRQ_EN:1;
    volatile uint32 CLK_EN_ERR_IRQ_EN:1;
    volatile uint32 CLK_PER_ERR_IRQ_EN:1;
    uint32 reserved_0:23;
}  bf_GTM_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_IRQ_EN_bf_type B;
} GTM_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_AEI_TO_XPT:1;
    volatile uint32 TRG_AEI_USP_ADDR:1;
    volatile uint32 TRG_AEI_IM_ADDR:1;
    volatile uint32 TRG_AEI_USP_BE:1;
    volatile uint32 TRG_AEIM_USP_ADDR:1;
    volatile uint32 TRG_AEIM_IM_ADDR:1;
    volatile uint32 TRG_AEIM_USP_BE:1;
    volatile uint32 TRG_CLK_EN_ERR:1;
    volatile uint32 TRG_CLK_PER_ERR:1;
    uint32 reserved_0:23;
}  bf_GTM_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_IRQ_FORCINT_bf_type B;
} GTM_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_IRQ_MODE_bf_type B;
} GTM_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 AEI_TO_XPT_EIRQ_EN:1;
    volatile uint32 AEI_USP_ADDR_EIRQ_EN:1;
    volatile uint32 AEI_IM_ADDR_EIRQ_EN:1;
    volatile uint32 AEI_USP_BE_EIRQ_EN:1;
    volatile uint32 AEIM_USP_ADDR_EIRQ_EN:1;
    volatile uint32 AEIM_IM_ADDR_EIRQ_EN:1;
    volatile uint32 AEIM_USP_BE_EIRQ_EN:1;
    volatile uint32 CLK_EN_ERR_EIRQ_EN:1;
    volatile uint32 CLK_PER_ERR_EIRQ_EN:1;
    uint32 reserved_0:23;
}  bf_GTM_EIRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_EIRQ_EN_bf_type B;
} GTM_EIRQ_EN_bf_type;

typedef struct {
    volatile uint32 SRC_IN_MUX:1;
    uint32 reserved_0:31;
}  bf_GTM_CFG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CFG_bf_type B;
} GTM_CFG_bf_type;

typedef struct {
    volatile uint32 TO_ADDR:21;
    uint32 reserved_0:3;
    volatile uint32 TO_W1R0:1;
    uint32 reserved_1:7;
}  bf_GTM_AEI_STA_XPT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AEI_STA_XPT_bf_type B;
} GTM_AEI_STA_XPT_bf_type;

typedef struct {
    volatile uint32 BRG_MODE:1;
    volatile uint32 MSK_WR_RSP:1;
    volatile uint32 BYPASS_SYNC:1;
    uint32 reserved_3:5;
    volatile uint32 MODE_UP_PGR:1;
    volatile uint32 BUFF_OVL:1;
    uint32 reserved_2:2;
    volatile uint32 SYNC_INPUT_REG:1;
    uint32 reserved_1:3;
    volatile uint32 BRG_RST:1;
    uint32 reserved_0:7;
    volatile uint32 BUFF_DPT:8;
}  bf_GTM_BRIDGE_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRIDGE_MODE_bf_type B;
} GTM_BRIDGE_MODE_bf_type;

typedef struct {
    volatile uint32 NEW_TRAN_PTR:5;
    volatile uint32 FIRST_RSP_PTR:5;
    volatile uint32 TRAN_IN_PGR:5;
    volatile uint32 ABT_TRAN_PGR:5;
    volatile uint32 FBC:6;
    volatile uint32 RSP_TRAN_RDY:6;
}  bf_GTM_BRIDGE_PTR1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRIDGE_PTR1_bf_type B;
} GTM_BRIDGE_PTR1_bf_type;

typedef struct {
    volatile uint32 TRAN_IN_PGR2:5;
    uint32 reserved_0:27;
}  bf_GTM_BRIDGE_PTR2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_BRIDGE_PTR2_bf_type B;
} GTM_BRIDGE_PTR2_bf_type;

typedef struct {
    volatile uint32 DIS_CLS0:2;
    volatile uint32 DIS_CLS1:2;
    volatile uint32 DIS_CLS2:2;
    volatile uint32 DIS_CLS3:2;
    uint32 reserved_0:24;
}  bf_GTM_MCS_AEM_DIS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_AEM_DIS_bf_type B;
} GTM_MCS_AEM_DIS_bf_type;

typedef struct {
    volatile uint32 CLS0_CLK_DIV:2;
    volatile uint32 CLS1_CLK_DIV:2;
    volatile uint32 CLS2_CLK_DIV:2;
    volatile uint32 CLS3_CLK_DIV:2;
    volatile uint32 CLS4_CLK_DIV:2;
    volatile uint32 CLS5_CLK_DIV:2;
    volatile uint32 CLS6_CLK_DIV:2;
    volatile uint32 CLS7_CLK_DIV:2;
    volatile uint32 CLS8_CLK_DIV:2;
    volatile uint32 CLS9_CLK_DIV:2;
    volatile uint32 CLS10_CLK_DIV:2;
    volatile uint32 CLS11_CLK_DIV:2;
    uint32 reserved_0:8;
}  bf_GTM_CLS_CLK_CFG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_CLS_CLK_CFG_bf_type B;
} GTM_CLS_CLK_CFG_bf_type;


typedef struct {
    volatile uint32 CLS0_COM_DIS:1;
    volatile uint32 CLS1_COM_DIS:1;
    volatile uint32 CLS2_COM_DIS:1;
    volatile uint32 CLS3_COM_DIS:1;
    uint32 reserved_0:28;
}  bf_GTM_ARU_COM_DIS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_ARU_COM_DIS_bf_type B;
} GTM_ARU_COM_DIS_bf_type;

typedef struct {
    volatile uint32 DUMMY_BF:32;
}  bf_GTM_SVM_RESERVED_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_SVM_RESERVED_bf_type B;
} GTM_SVM_RESERVED_bf_type;

typedef struct {
    volatile uint32 DATA:32;
}  bf_GTM_MCS_MEM_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_MCS_MEM_bf_type B;
} GTM_MCS_MEM_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_S_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_S_bf_type B;
} GTM_TIO_S_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CS_bf_type B;
} GTM_TIO_CS_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_SS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_SS_bf_type B;
} GTM_TIO_SS_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_IS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_IS_bf_type B;
} GTM_TIO_IS_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_O_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_O_bf_type B;
} GTM_TIO_O_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CO_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CO_bf_type B;
} GTM_TIO_CO_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_SO_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_SO_bf_type B;
} GTM_TIO_SO_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_IO_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_IO_bf_type B;
} GTM_TIO_IO_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_ENDIS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_ENDIS_bf_type B;
} GTM_TIO_ENDIS_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CENDIS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CENDIS_bf_type B;
} GTM_TIO_CENDIS_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_SENDIS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_SENDIS_bf_type B;
} GTM_TIO_SENDIS_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_IENDIS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_IENDIS_bf_type B;
} GTM_TIO_IENDIS_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_INVERT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_INVERT_bf_type B;
} GTM_TIO_INVERT_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CINVERT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CINVERT_bf_type B;
} GTM_TIO_CINVERT_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_SINVERT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_SINVERT_bf_type B;
} GTM_TIO_SINVERT_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_IINVERT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_IINVERT_bf_type B;
} GTM_TIO_IINVERT_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_INPUT_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_INPUT_MODE_bf_type B;
} GTM_TIO_INPUT_MODE_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CINPUT_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CINPUT_MODE_bf_type B;
} GTM_TIO_CINPUT_MODE_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_SINPUT_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_SINPUT_MODE_bf_type B;
} GTM_TIO_SINPUT_MODE_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_IINPUT_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_IINPUT_MODE_bf_type B;
} GTM_TIO_IINPUT_MODE_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CYCLIC_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CYCLIC_MODE_bf_type B;
} GTM_TIO_CYCLIC_MODE_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CCYCLIC_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CCYCLIC_MODE_bf_type B;
} GTM_TIO_CCYCLIC_MODE_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_SCYCLIC_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_SCYCLIC_MODE_bf_type B;
} GTM_TIO_SCYCLIC_MODE_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_ICYCLIC_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_ICYCLIC_MODE_bf_type B;
} GTM_TIO_ICYCLIC_MODE_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_FUPD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_FUPD_bf_type B;
} GTM_TIO_FUPD_bf_type;

typedef struct {
    volatile uint32 NTIO_CH8:2;
    uint32 reserved_0:2;
    volatile uint32 TIO_PLUS:1;
    uint32 reserved_1:27;
}  bf_GTM_TIO_HW_CONF_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_HW_CONF_bf_type B;
} GTM_TIO_HW_CONF_bf_type;

typedef struct {
    uint32 reserved_0:24;
    volatile uint32 SEL_CLKEN6_G0:1;
    volatile uint32 SEL_CLKEN6_G1:1;
    uint32 reserved_1:2;
    volatile uint32 SEL_CLKEN7_G0:1;
    volatile uint32 SEL_CLKEN7_G1:1;
    uint32 reserved_2:2;
}  bf_GTM_TIO_RSEL_CTRL1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_RSEL_CTRL1_bf_type B;
} GTM_TIO_RSEL_CTRL1_bf_type;

typedef struct {
    uint32 reserved_0:4;
    volatile uint32 SEL_TB1_G0:1;
    volatile uint32 SEL_TB1_G1:1;
    uint32 reserved_1:2;
    volatile uint32 SEL_TB2_G0:1;
    volatile uint32 SEL_TB2_G1:1;
    uint32 reserved_2:22;
}  bf_GTM_TIO_RSEL_CTRL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_RSEL_CTRL2_bf_type B;
} GTM_TIO_RSEL_CTRL2_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_PL_SWRST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_PL_SWRST_bf_type B;
} GTM_TIO_PL_SWRST_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_TRIG_OUT_GATE_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_TRIG_OUT_GATE_EN_bf_type B;
} GTM_TIO_TRIG_OUT_GATE_EN_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CTRIG_OUT_GATE_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CTRIG_OUT_GATE_EN_bf_type B;
} GTM_TIO_CTRIG_OUT_GATE_EN_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_STRIG_OUT_GATE_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_STRIG_OUT_GATE_EN_bf_type B;
} GTM_TIO_STRIG_OUT_GATE_EN_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_PLTRIG_OUT_GATE_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_PLTRIG_OUT_GATE_EN_bf_type B;
} GTM_TIO_PLTRIG_OUT_GATE_EN_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_CPLTRIG_OUT_GATE_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_CPLTRIG_OUT_GATE_EN_bf_type B;
} GTM_TIO_CPLTRIG_OUT_GATE_EN_bf_type;

typedef struct {
    volatile uint32 CH0:1;
    volatile uint32 CH1:1;
    volatile uint32 CH2:1;
    volatile uint32 CH3:1;
    volatile uint32 CH4:1;
    volatile uint32 CH5:1;
    volatile uint32 CH6:1;
    volatile uint32 CH7:1;
    volatile uint32 CH8:1;
    volatile uint32 CH9:1;
    volatile uint32 CH10:1;
    volatile uint32 CH11:1;
    volatile uint32 CH12:1;
    volatile uint32 CH13:1;
    volatile uint32 CH14:1;
    volatile uint32 CH15:1;
    uint32 reserved_0:16;
}  bf_GTM_TIO_SPLTRIG_OUT_GATE_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_SPLTRIG_OUT_GATE_EN_bf_type B;
} GTM_TIO_SPLTRIG_OUT_GATE_EN_bf_type;


typedef struct {
    volatile uint32 TRIG_OUT_EN_S_RE:1;
    volatile uint32 TRIG_OUT_EN_S_FE:1;
    volatile uint32 TRIG_OUT_EN_O_RE:1;
    volatile uint32 TRIG_OUT_EN_O_FE:1;
    volatile uint32 TRIG_OUT_EN_PREV_TRIG:1;
    volatile uint32 TRIG_OUT_EN_PL_EVT:1;
    volatile uint32 TRIG_OUT_EN_PREV_PL_TRIG:1;
    volatile uint32 PL_CYCLIC_INIT_TRIG_EN:1;
    volatile uint32 UPDATE_SRC:4;
    volatile uint32 PL_S_MODE:2;
    volatile uint32 PL_FREEZE_S_EN:1;
    volatile uint32 PL_CYCLIC_BUFF:1;
    volatile uint32 PL_O_MODE:3;
    volatile uint32 PL_FREEZE_O_EN:1;
    volatile uint32 PL_ODIS:1;
    volatile uint32 PL_SEL_IN:1;
    volatile uint32 PL_O_TRIG_OUT_EN:1;
    volatile uint32 PL_S_TRIG_OUT_EN:1;
    volatile uint32 PL_TRIG_OUT_EN_S_RE:1;
    volatile uint32 PL_TRIG_OUT_EN_S_FE:1;
    volatile uint32 PL_TRIG_OUT_EN_O_RE:1;
    volatile uint32 PL_TRIG_OUT_EN_O_FE:1;
    volatile uint32 PL_TRIG_OUT_EN_PREV_TRIG:1;
    volatile uint32 PL_TRIG_OUT_EN_PL_EVT:1;
    volatile uint32 PL_TRIG_OUT_EN_PREV_PL_TRIG:1;
    volatile uint32 PL_TRIG_OUT_UPD_EN:1;
}  bf_GTM_TIO_GROUP_CH_CTRL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_CTRL_bf_type B;
} GTM_TIO_GROUP_CH_CTRL_bf_type;

typedef struct {
    volatile uint32 DUAL_CMP_EN:1;
    volatile uint32 DUAL_CMP_MST_EN:1;
    uint32 reserved_0:30;
}  bf_GTM_TIO_GROUP_CH_CTRL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_CTRL2_bf_type B;
} GTM_TIO_GROUP_CH_CTRL2_bf_type;

typedef struct {
    volatile uint32 S_RE_IRQ:1;
    volatile uint32 S_FE_IRQ:1;
    volatile uint32 O_RE_IRQ:1;
    volatile uint32 O_FE_IRQ:1;
    volatile uint32 UPDATE_IRQ:1;
    volatile uint32 PL_EVT_IRQ:1;
    uint32 reserved_0:26;
}  bf_GTM_TIO_GROUP_CH_IRQ_NOTIFY_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_IRQ_NOTIFY_bf_type B;
} GTM_TIO_GROUP_CH_IRQ_NOTIFY_bf_type;

typedef struct {
    volatile uint32 S_RE_IRQ_EN:1;
    volatile uint32 S_FE_IRQ_EN:1;
    volatile uint32 O_RE_IRQ_EN:1;
    volatile uint32 O_FE_IRQ_EN:1;
    volatile uint32 UPDATE_IRQ_EN:1;
    volatile uint32 PL_EVT_IRQ_EN:1;
    uint32 reserved_0:26;
}  bf_GTM_TIO_GROUP_CH_IRQ_EN_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_IRQ_EN_bf_type B;
} GTM_TIO_GROUP_CH_IRQ_EN_bf_type;

typedef struct {
    volatile uint32 TRG_S_RE_IRQ:1;
    volatile uint32 TRG_S_FE_IRQ:1;
    volatile uint32 TRG_O_RE_IRQ:1;
    volatile uint32 TRG_O_FE_IRQ:1;
    volatile uint32 TRG_UPDATE_IRQ:1;
    volatile uint32 TRG_PL_EVT_IRQ:1;
    uint32 reserved_0:26;
}  bf_GTM_TIO_GROUP_CH_IRQ_FORCINT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_IRQ_FORCINT_bf_type B;
} GTM_TIO_GROUP_CH_IRQ_FORCINT_bf_type;

typedef struct {
    volatile uint32 IRQ_MODE:2;
    uint32 reserved_0:30;
}  bf_GTM_TIO_GROUP_CH_IRQ_MODE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_IRQ_MODE_bf_type B;
} GTM_TIO_GROUP_CH_IRQ_MODE_bf_type;

typedef struct {
    volatile uint32 OP:24;
    volatile uint32 CMD:6;
    volatile uint32 DATA_PUSH_EN:1;
    volatile uint32 INSTR_PULL_EN:1;
}  bf_GTM_TIO_GROUP_CH_SINST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_SINST_bf_type B;
} GTM_TIO_GROUP_CH_SINST_bf_type;

typedef struct {
    uint32 reserved_0:24;
    volatile uint32 CMD:6;
    volatile uint32 DATA_PUSH_EN:1;
    volatile uint32 INSTR_PULL_EN:1;
}  bf_GTM_TIO_GROUP_CH_SCMD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_SCMD_bf_type B;
} GTM_TIO_GROUP_CH_SCMD_bf_type;

typedef struct {
    volatile uint32 OP:24;
    uint32 reserved_0:8;
}  bf_GTM_TIO_GROUP_CH_SOP_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_SOP_bf_type B;
} GTM_TIO_GROUP_CH_SOP_bf_type;


typedef struct {
    volatile uint32 OP:24;
    volatile uint32 CMD:6;
    volatile uint32 DATA_PUSH_EN:1;
    volatile uint32 INSTR_PULL_EN:1;
}  bf_GTM_TIO_GROUP_CH_OINST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_OINST_bf_type B;
} GTM_TIO_GROUP_CH_OINST_bf_type;

typedef struct {
    uint32 reserved_0:24;
    volatile uint32 CMD:6;
    volatile uint32 DATA_PUSH_EN:1;
    volatile uint32 INSTR_PULL_EN:1;
}  bf_GTM_TIO_GROUP_CH_OCMD_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_OCMD_bf_type B;
} GTM_TIO_GROUP_CH_OCMD_bf_type;

typedef struct {
    volatile uint32 OP:24;
    uint32 reserved_0:8;
}  bf_GTM_TIO_GROUP_CH_OOP_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_OOP_bf_type B;
} GTM_TIO_GROUP_CH_OOP_bf_type;

typedef struct {
    volatile uint32 CNT:5;
    uint32 reserved_0:27;
}  bf_GTM_TIO_GROUP_CH_SHIFTCNT_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_CH_SHIFTCNT_bf_type B;
} GTM_TIO_GROUP_CH_SHIFTCNT_bf_type;

typedef struct {
    GTM_TIO_GROUP_CH_CTRL_bf_type CTRL;
    GTM_TIO_GROUP_CH_IRQ_NOTIFY_bf_type IRQ_NOTIFY;
    GTM_TIO_GROUP_CH_IRQ_EN_bf_type IRQ_EN;
    GTM_TIO_GROUP_CH_IRQ_FORCINT_bf_type IRQ_FORCINT;
    GTM_TIO_GROUP_CH_IRQ_MODE_bf_type IRQ_MODE;
    GTM_TIO_GROUP_CH_CTRL2_bf_type CTRL2;
    volatile uint32 reserved_0[2];
    GTM_TIO_GROUP_CH_SINST_bf_type SINST;
    GTM_TIO_GROUP_CH_SCMD_bf_type SCMD;
    GTM_TIO_GROUP_CH_SOP_bf_type SOP;
    volatile uint32 reserved_1;
    GTM_TIO_GROUP_CH_OINST_bf_type OINST;
    GTM_TIO_GROUP_CH_OCMD_bf_type OCMD;
    GTM_TIO_GROUP_CH_OOP_bf_type OOP;
    GTM_TIO_GROUP_CH_SHIFTCNT_bf_type SHIFTCNT;
}GTM_TIO_GROUP_CH_bf_type;

typedef struct {
    volatile uint32 LUT2_0:4;
    volatile uint32 LUT2_1:4;
    volatile uint32 LUT2_2:4;
    volatile uint32 LUT2_3:4;
    volatile uint32 OUT_SEL0:1;
    volatile uint32 OUT_SEL1:1;
    volatile uint32 OUT_SEL2:1;
    volatile uint32 OUT_SEL3:1;
    uint32 reserved_0:4;
    volatile uint32 WRITE_EN0:1;
    volatile uint32 WRITE_EN1:1;
    volatile uint32 WRITE_EN2:1;
    volatile uint32 WRITE_EN3:1;
    uint32 reserved_1:4;
}  bf_GTM_TIO_GROUP_ISEL_CTRL1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_ISEL_CTRL1_bf_type B;
} GTM_TIO_GROUP_ISEL_CTRL1_bf_type;

typedef struct {
    volatile uint32 LUT3:8;
    uint32 reserved_0:8;
    volatile uint32 QOUT_SEL:2;
    uint32 reserved_1:2;
    volatile uint32 LUT3IN_SEL0:1;
    volatile uint32 LUT3IN_SEL1:1;
    volatile uint32 LUT3IN_SEL2:1;
    uint32 reserved_2:9;
}  bf_GTM_TIO_GROUP_ISEL_CTRL2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_ISEL_CTRL2_bf_type B;
} GTM_TIO_GROUP_ISEL_CTRL2_bf_type;

typedef struct {
    volatile uint32 MODE0:3;
    volatile uint32 MODE1:3;
    volatile uint32 MODE2:3;
    volatile uint32 MODE3:3;
    volatile uint32 MODE4:3;
    volatile uint32 MODE5:3;
    volatile uint32 MODE6:3;
    volatile uint32 MODE7:3;
    volatile uint32 WRITE_EN0:1;
    volatile uint32 WRITE_EN1:1;
    volatile uint32 WRITE_EN2:1;
    volatile uint32 WRITE_EN3:1;
    volatile uint32 WRITE_EN4:1;
    volatile uint32 WRITE_EN5:1;
    volatile uint32 WRITE_EN6:1;
    volatile uint32 WRITE_EN7:1;
}  bf_GTM_TIO_GROUP_OP_USAGE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_TIO_GROUP_OP_USAGE_bf_type B;
} GTM_TIO_GROUP_OP_USAGE_bf_type;

typedef struct {
    GTM_TIO_GROUP_CH_bf_type CH[8];
    GTM_TIO_GROUP_ISEL_CTRL1_bf_type ISEL0_CTRL1;
    GTM_TIO_GROUP_ISEL_CTRL2_bf_type ISEL0_CTRL2;
    volatile uint32 reserved_0[6];
    GTM_TIO_GROUP_ISEL_CTRL1_bf_type ISEL1_CTRL1;
    GTM_TIO_GROUP_ISEL_CTRL2_bf_type ISEL1_CTRL2;
    volatile uint32 reserved_1[6];
    GTM_TIO_GROUP_OP_USAGE_bf_type OP_USAGE;
    volatile uint32 reserved_2[111];
}GTM_TIO_GROUP_bf_type;

typedef struct {
    GTM_TIO_GROUP_bf_type G[2]; 
    volatile uint32 reserved_0[256];
    GTM_TIO_S_bf_type S; 
    GTM_TIO_O_bf_type O;
    GTM_TIO_ENDIS_bf_type ENDIS;
    GTM_TIO_INVERT_bf_type INVERT;
    GTM_TIO_INPUT_MODE_bf_type INPUT_MODE;
    GTM_TIO_CYCLIC_MODE_bf_type CYCLIC_MODE;
    GTM_TIO_TRIG_OUT_GATE_EN_bf_type TRIG_OUT_GATE_EN;
    GTM_TIO_PLTRIG_OUT_GATE_EN_bf_type PLTRIG_OUT_GATE_EN;
    volatile uint32 reserved_1[8];
    GTM_TIO_CS_bf_type CS;
    GTM_TIO_CO_bf_type CO;
    GTM_TIO_CENDIS_bf_type CENDIS;
    GTM_TIO_CINVERT_bf_type CINVERT;
    GTM_TIO_CINPUT_MODE_bf_type CINPUT_MODE;
    GTM_TIO_CCYCLIC_MODE_bf_type CCYCLIC_MODE;
    GTM_TIO_CTRIG_OUT_GATE_EN_bf_type CTRIG_OUT_GATE_EN;
    GTM_TIO_CPLTRIG_OUT_GATE_EN_bf_type CPLTRIG_OUT_GATE_EN;
    volatile uint32 reserved_2[8];
    GTM_TIO_SS_bf_type SS;
    GTM_TIO_SO_bf_type SO;
    GTM_TIO_SENDIS_bf_type SENDIS;
    GTM_TIO_SINVERT_bf_type SINVERT;
    GTM_TIO_SINPUT_MODE_bf_type SINPUT_MODE;
    GTM_TIO_SCYCLIC_MODE_bf_type SCYCLIC_MODE;
    GTM_TIO_STRIG_OUT_GATE_EN_bf_type STRIG_OUT_GATE_EN;
    GTM_TIO_SPLTRIG_OUT_GATE_EN_bf_type SPLTRIG_OUT_GATE_EN;
    volatile uint32 reserved_3[8];
    GTM_TIO_IS_bf_type IS;
    GTM_TIO_IO_bf_type IO;
    GTM_TIO_IENDIS_bf_type IENDIS;
    GTM_TIO_IINVERT_bf_type IINVERT;
    GTM_TIO_IINPUT_MODE_bf_type IINPUT_MODE;
    GTM_TIO_ICYCLIC_MODE_bf_type ICYCLIC_MODE;
    volatile uint32 reserved_4[10];
    GTM_TIO_FUPD_bf_type FUPD;
    GTM_TIO_HW_CONF_bf_type HW_CONF;
    GTM_TIO_RSEL_CTRL1_bf_type RSEL_CTRL1;
    GTM_TIO_RSEL_CTRL2_bf_type RSEL_CTRL2;
    GTM_TIO_PL_SWRST_bf_type PL_SWRST;
} GTM_TIO_G_bf_type;

/*************************************************************************
 * union GTM.TIO
 *************************************************************************/

typedef union {
    GTM_TIO_G_bf_type REG; 
    volatile uint32 reserved_0[1024];
} GTM_TIO_bf_type;


typedef struct {
    volatile uint32 SLOT0:1;
    volatile uint32 SLOT1:1;
    volatile uint32 SLOT2:1;
    volatile uint32 SLOT3:1;
    uint32 reserved_0:28;
}  bf_GTM_AXIM_FREE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AXIM_FREE_bf_type B;
} GTM_AXIM_FREE_bf_type;

typedef struct {
    volatile uint32 REQ_SLOT0:1;
    volatile uint32 REQ_SLOT1:1;
    volatile uint32 REQ_SLOT2:1;
    volatile uint32 REQ_SLOT3:1;
    uint32 reserved_0:20;
    volatile uint32 REQID:8;
}  bf_GTM_AXIM_REQUEST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AXIM_REQUEST_bf_type B;
} GTM_AXIM_REQUEST_bf_type;

typedef struct {
    volatile uint32 REL_SLOT0:1;
    volatile uint32 REL_SLOT1:1;
    volatile uint32 REL_SLOT2:1;
    volatile uint32 REL_SLOT3:1;
    uint32 reserved_0:28;
}  bf_GTM_AXIM_RELEASE_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AXIM_RELEASE_bf_type B;
} GTM_AXIM_RELEASE_bf_type;

typedef struct {
    GTM_AXIM_FREE_bf_type FREE;
    GTM_AXIM_REQUEST_bf_type REQUEST;
    GTM_AXIM_RELEASE_bf_type RELEASE;
    volatile uint32 reserved_0[5];
} GTM_AXIM_GC_bf_type;

typedef struct {
    volatile uint32 AXI_ADDR;
}  bf_GTM_AXIM_ADDR_LOW_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AXIM_ADDR_LOW_bf_type B;
} GTM_AXIM_ADDR_LOW_bf_type;

typedef struct {
    volatile uint32 AXI_DATA;
}  bf_GTM_AXIM_DATA_LOW_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AXIM_DATA_LOW_bf_type B;
} GTM_AXIM_DATA_LOW_bf_type;

typedef struct {
    volatile uint32 INCR:4;
    volatile uint32 AUTO_INCR:1;
    volatile uint32 PRIO:2;
    uint32 reserved_0:4;
    volatile uint32 AXI_PROT:3;
    volatile uint32 AXI_CACHE:4;
    volatile uint32 AXI_LOCK:2;
    uint32 reserved_1:2;
    volatile uint32 AXI_SIZE:3;
    volatile uint32 AXI_RW:1;
    uint32 reserved_2:6;
}  bf_GTM_AXIM_CFG1_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AXIM_CFG1_bf_type B;
} GTM_AXIM_CFG1_bf_type;

typedef struct {
    volatile uint32 AXI_ID:16;
    uint32 reserved_0:16;
}  bf_GTM_AXIM_CFG2_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AXIM_CFG2_bf_type B;
} GTM_AXIM_CFG2_bf_type;

typedef struct {
    volatile uint32 ALLOC:1;
    volatile uint32 QUEUED:1;
    volatile uint32 STARTED:1;
    volatile uint32 READY:1;
    volatile uint32 RESP:2;
    uint32 reserved_0:26;
}  bf_GTM_AXIM_STATUS_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_AXIM_STATUS_bf_type B;
} GTM_AXIM_STATUS_bf_type;

typedef struct {
    GTM_AXIM_ADDR_LOW_bf_type ADDR_LOW;
    volatile uint32 reserved_0;
    GTM_AXIM_DATA_LOW_bf_type DATA_LOW;
    volatile uint32 reserved_1;
    GTM_AXIM_CFG1_bf_type CFG1;
    GTM_AXIM_CFG2_bf_type CFG2;
    GTM_AXIM_STATUS_bf_type STATUS;
    volatile uint32 reserved_2;
} GTM_AXIM_SLOT_bf_type;

typedef struct {
    GTM_AXIM_GC_bf_type GC;
    GTM_AXIM_SLOT_bf_type SLOT[4];
    volatile uint32 reserved_0[216];
} GTM_AXIM_bf_type;

typedef struct {
    //cluster 0
    //ARCH 0x000000 - 0x00003C
    GTM_REV_bf_type REV;
    GTM_RST_bf_type RST;
    GTM_CTRL_bf_type CTRL;
    GTM_CFG_bf_type CFG;
    GTM_AEI_ADDR_XPT_bf_type AEI_ADDR_XPT;
    GTM_AEI_STA_XPT_bf_type AEI_STA_XPT;
    GTM_IRQ_NOTIFY_bf_type IRQ_NOTIFY;
    GTM_IRQ_EN_bf_type IRQ_EN;
    GTM_EIRQ_EN_bf_type EIRQ_EN;
    GTM_IRQ_FORCINT_bf_type IRQ_FORCINT;
    GTM_IRQ_MODE_bf_type IRQ_MODE;
    GTM_CLS_CLK_CFG_bf_type CLS_CLK_CFG;
    GTM_ARU_COM_DIS_bf_type ARU_COM_DIS; //0x30
    volatile uint32 reserved_0[3];

    //AEI 0x000040 - 0x00004C
    GTM_BRIDGE_MODE_bf_type BRIDGE_MODE;
    GTM_BRIDGE_PTR1_bf_type BRIDGE_PTR1;
    GTM_BRIDGE_PTR2_bf_type BRIDGE_PTR2;
    GTM_MCS_AEM_DIS_bf_type MCS_AEM_DIS;

    //reserved 0x000050 - 0x00007C
    volatile uint32 reserved_1[12];

    //CMU 0x000080 - 0x0000FC
    GTM_CMU_bf_type CMU;

    //TBU 0x000100 - 0x00017C
    GTM_TBU_bf_type TBU;

    //ARU 0x000180 - 0x0001FC
    GTM_ARU_bf_type ARU;

    //BRC 0x000200 - 0x00027C
    GTM_BRC_bf_type BRC;

    //reserved 0x000280 - 0x0003FC
    volatile uint32 reserved_2[96];

    //ICM 0x000400 - 0x0005FC
    GTM_ICM_bf_type ICM;

    //MCFG 0x000600 - 0x00063C
    GTM_MCFG_bf_type MCFG;

    //MAP 0x000640 - 0x00067C
    GTM_MAP_bf_type MAP;

    //reserved 0x000680 - 0x0007FC
    volatile uint32 reserved_11[96];

    //TIM0 0x000800 - 0x000FFC
    GTM_TIM_bf_type TIM0;                 // CAu

    //TOM0 0x001000 - 0x0017FC
    GTM_TOM_bf_type TOM0;                 // CAu

    //ATOM0 0x001800 - 0x001FFC
    GTM_ATOM_bf_type ATOM0;

    //MCS0 0x002000 - 0x002FFC
    GTM_MCS_bf_type MCS0;

    //TIO0 0x003000 - 0x003FFC
    GTM_TIO_bf_type TIO0;

    //CCM0 0x004000 - 0x0041FC
    GTM_CCM_bf_type CCM0;

    //reserved 0x004200 - 0x0043FC
    volatile uint32 reserved_5[128];

    //CDTM0 0x004400 - 0x0047FC
    GTM_CDTM_bf_type CDTM0;

    //PSM0 0x004800 - 0x004BFC
    GTM_PSM_bf_type PSM0;

    //SPE0 0x004C00 - 0x004C7C
    GTM_SPE_bf_type SPE0;

    //reserved 0x004C80 - 0x004FFC
    volatile uint32 reserved_6[224];

    //AXIM0 0x005000 - 0x0053FC
    GTM_AXIM_bf_type AXIM0;

    //ADC0 & MCS2DPLL 0x005400 - 0x006000
    volatile uint32 reserved_8[768];

    //FIFO0_MEM 0x006000 - 0x006FFC
    GTM_PSM_FIFO_MEMORY_bf_type FIFO0_MEMORY[1024];

    //reserved 0x007000 - 0x008FFC
    volatile uint32 reserved_9[1024];

    //DPLL 0x008000 - 0x00FFFC
    GTM_DPLL_bf_type DPLL;

    //MCS0_MEM 0x010000 - 0x01FFFC
    GTM_MCS_MEM_bf_type MCS_MEM0[16384];

    //cluster 1
    //ARCH 0x000000 - 0x000680
    volatile uint32 reserved_10[416];

    //MON 0x000680 - 0x0006BC
    GTM_MON_bf_type MON;

    //CMP 0x0006C0 - 0x0006FC
    GTM_CMP_bf_type CMP;

    //reserved 0x000700 - 0x0007FC
    volatile uint32 reserved_3[64];

    //TIM1 0x000800 - 0x000FFC
    GTM_TIM_bf_type TIM1;                 // CAu

    //TOM1 0x001000 - 0x0017FC
    GTM_TOM_bf_type TOM1;                 // CAu

    //ATOM1 0x001800 - 0x001FFC
    GTM_ATOM_bf_type ATOM1;

    //MCS1 0x002000 - 0x002FFC
    GTM_MCS_bf_type MCS1;

    //TIO1 0x003000 - 0x003FFC
    GTM_TIO_bf_type TIO1;

    //CCM1 0x004000 - 0x0041FC
    GTM_CCM_bf_type CCM1;

    //reserved 0x004200 - 0x0043FC
    volatile uint32 reserved_13[128];

    //CDTM1 0x004400 - 0x0047FC
    GTM_CDTM_bf_type CDTM1;

    //PSM1 0x004800 - 0x004BFC
    volatile uint32 reserved_35[256];

    //SPE1 0x004C00 - 0x004C7C
    GTM_SPE_bf_type SPE1;

    //reserved 0x004C80 - 0x004FFC
    volatile uint32 reserved_14[224];

    //AXIM0 0x005000 - 0x0053FC
    GTM_AXIM_bf_type AXIM1;

    //ADC0 & MCS2DPLL 0x005400 - 0x006000
    volatile uint32 reserved_16[768];

    //FIFO1_MEM 0x006000 - 0x006FFC
    volatile uint32 reserved_36[1024];

    //reserved 0x007000 - 0x008FFC
    volatile uint32 reserved_17[1024];

    //DPLL 0x008000 - 0x00FFFC
    volatile uint32 reserved_18[8192];

    //MCS1_MEM 0x010000 - 0x01FFFC
    GTM_MCS_MEM_bf_type MCS_MEM1[16384];

    //cluster 2
    //ARCH 0x000000 - 0x0007FC
    volatile uint32 reserved_19[512];

    //TIM2 0x000800 - 0x000FFC
    GTM_TIM_bf_type TIM2;                 // CAu

    //TOM2 0x001000 - 0x0017FC
    volatile uint32 reserved_37[512];

    //ATOM2 0x001800 - 0x001FFC
    GTM_ATOM_bf_type ATOM2;

    //MCS2 0x002000 - 0x002FFC
    GTM_MCS_bf_type MCS2;

    //TIO2 0x003000 - 0x003FFC
    GTM_TIO_bf_type TIO2;

    //CCM2 0x004000 - 0x0041FC
    GTM_CCM_bf_type CCM2;

    //reserved 0x004200 - 0x0043FC
    volatile uint32 reserved_21[128];

    //CDTM2 0x004400 - 0x0047FC
    GTM_CDTM_bf_type CDTM2;

    //PSM2 0x004800 - 0x004BFC
    volatile uint32 reserved_38[256];

    //SPE2 0x004C00 - 0x004C7C
    volatile uint32 reserved_39[32];

    //reserved 0x004C80 - 0x004FFC
    volatile uint32 reserved_22[224];

    //AXIM0 0x005000 - 0x0053FC
    GTM_AXIM_bf_type AXIM2;

    //ADC0 & MCS2DPLL 0x005400 - 0x006000
    volatile uint32 reserved_24[768];

    //FIFO2_MEM 0x006000 - 0x006FFC
    volatile uint32 reserved_40[1024];

    //reserved 0x007000 - 0x008FFC
    volatile uint32 reserved_25[1024];

    //DPLL 0x008000 - 0x00FFFC
    volatile uint32 reserved_26[8192];

    //MCS2_MEM 0x010000 - 0x01FFFC
    GTM_MCS_MEM_bf_type MCS_MEM2[16384];

    //cluster 3
    //ARCH 0x000000 - 0x0007FC
    volatile uint32 reserved_27[512];

    //TIM3 0x000800 - 0x000FFC
    volatile uint32 reserved_41[512];

    //TOM3 0x001000 - 0x0017FC
    volatile uint32 reserved_42[512];

    //ATOM3 0x001800 - 0x001FFC
    GTM_ATOM_bf_type ATOM3;

    //MCS3 0x002000 - 0x002FFC
    volatile uint32 reserved_43[1024];

    //TIO3 0x003000 - 0x003FFC
    GTM_TIO_bf_type TIO3;

    //CCM2 0x004000 - 0x0041FC
    GTM_CCM_bf_type CCM3;

    //reserved 0x004200 - 0x0043FC
    volatile uint32 reserved_29[128];

    //CDTM3 0x004400 - 0x0047FC
    GTM_CDTM_bf_type CDTM3;

    //PSM3 0x004800 - 0x004BFC
    volatile uint32 reserved_44[256];

    //SPE3 0x004C00 - 0x004C7C
    volatile uint32 reserved_45[32];

    //reserved 0x004C80 - 0x004FFC
    volatile uint32 reserved_30[224];

    //AXIM0 0x005000 - 0x0053FC
    volatile uint32 reserved_31[256];

    //ADC0 & MCS2DPLL 0x005400 - 0x006000
    volatile uint32 reserved_32[768];

    //FIFO3_MEM 0x006000 - 0x006FFC
    volatile uint32 reserved_46[1024];

    //reserved 0x007000 - 0x008FFC
    volatile uint32 reserved_33[1024];

    //DPLL 0x008000 - 0x00FFFC
    volatile uint32 reserved_34[8192];

    //MCS3_MEM 0x010000 - 0x01FFFC
    volatile uint32 reserved_47[16384];

} GTM_bf_type;

#define GTM             (*(volatile GTM_bf_type *)0x50000000UL)
#define TT_GTM          ((volatile GTM_bf_type *)0x50000000UL)

typedef struct {
    volatile uint32 INTCLR:22;
    uint32 reserved_0:10;
}  bf_GTM_WRAPPER_INTCLR_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_INTCLR_bf_type B;
} GTM_WRAPPER_INTCLR_bf_type;

typedef struct {
    volatile uint32 INTSET:5;
    uint32 reserved_0:27;
}  bf_GTM_WRAPPER_INTSET_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_INTSET_bf_type B;
} GTM_WRAPPER_INTSET_bf_type;

typedef struct {
    volatile uint32 SEL0:4;
    volatile uint32 SEL1:4;
    volatile uint32 SEL2:4;
    volatile uint32 SEL3:4;
    volatile uint32 SEL4:4;
    volatile uint32 SEL5:4;
    volatile uint32 SEL6:4;
    volatile uint32 SEL7:4;
}  bf_GTM_WRAPPER_TOUTSEL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_TOUTSEL_bf_type B;
} GTM_WRAPPER_TOUTSEL_bf_type;

typedef struct {
    volatile uint32 SEL0:4;
    volatile uint32 SEL1:4;
    volatile uint32 SEL2:4;
    volatile uint32 SEL3:4;
    uint32 reserved_0:16;
}  bf_GTM_WRAPPER_ADCTSEL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_ADCTSEL_bf_type B;
} GTM_WRAPPER_ADCTSEL_bf_type;

typedef struct {
    volatile uint32 ST:8;
    uint32 reserved_0:24;
}  bf_GTM_WRAPPER_INTST_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_INTST_bf_type B;
} GTM_WRAPPER_INTST_bf_type;

typedef struct {
    volatile uint32 SEL0:4;
    volatile uint32 SEL1:4;
    volatile uint32 SEL2:4;
    volatile uint32 SEL3:4;
    volatile uint32 SEL4:4;
    volatile uint32 SEL5:4;
    volatile uint32 SEL6:4;
    volatile uint32 SEL7:4;
}  bf_GTM_WRAPPER_ADCTRIG_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_ADCTRIG_bf_type B;
} GTM_WRAPPER_ADCTRIG_bf_type;

typedef struct {
    volatile uint32 CFG:2;
    uint32 reserved_0:2;
    volatile uint32 EN:1;
    uint32 reserved_1:27;
}  bf_GTM_WRAPPER_CMU_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_CMU_bf_type B;
} GTM_WRAPPER_CMU_bf_type;

typedef struct {
    volatile uint32 DIV:8;
    uint32 reserved_0:24;
}  bf_GTM_WRAPPER_OSCDIV_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_OSCDIV_bf_type B;
} GTM_WRAPPER_OSCDIV_bf_type;

typedef struct {
    volatile uint32 TIM0_SEL  :3;
    uint32 reserved_0         :1;
    volatile uint32 TIM1_SEL  :3;
    uint32 reserved_1         :1;
    volatile uint32 TIM2_SEL  :3;
    uint32 reserved_2         :1;
    volatile uint32 TIM3_SEL  :3;
    uint32 reserved_3         :1;
    volatile uint32 TIM4_SEL  :3;
    uint32 reserved_4         :1;
    volatile uint32 TIM5_SEL  :3;
    uint32 reserved_5         :1;
    volatile uint32 TIM6_SEL  :3;
    uint32 reserved_6         :1;
    volatile uint32 TIM7_SEL  :3;
    uint32 reserved_7         :1;
}  bf_GTM_WRAPPER_TIMSEL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_TIMSEL_bf_type B;
} GTM_WRAPPER_TIMSEL_bf_type;

typedef struct {
    volatile uint32 SEL0:4;
    volatile uint32 SEL1:4;
    volatile uint32 SEL2:4;
    uint32 reserved_0:20;
}  bf_GTM_WRAPPER_ADCISEL_bf_type;

typedef union {
    volatile uint32 R;
    volatile int32_t I;
    bf_GTM_WRAPPER_TOUTSEL_bf_type B;
} GTM_WRAPPER_ADCISEL_bf_type;

typedef struct {
    GTM_WRAPPER_INTCLR_bf_type INTCLR;
    GTM_WRAPPER_INTSET_bf_type INTSET;
    volatile uint32 reserved_0[14];
    GTM_WRAPPER_TOUTSEL_bf_type TOUTSEL[17];
    volatile uint32 reserved_1[3];
    GTM_WRAPPER_OSCDIV_bf_type OSCDIV; /* 0x90 */
    GTM_WRAPPER_TIMSEL_bf_type TIMSEL; /* 0x94 */
    volatile uint32 reserved_2[6];
    GTM_WRAPPER_ADCTSEL_bf_type ADCTSEL;
    volatile uint32 reserved_3[3];
    GTM_WRAPPER_INTST_bf_type INTST[8];
    GTM_WRAPPER_ADCTRIG_bf_type ADCTRIG[10];
    volatile uint32 reserved_4[2];
    GTM_WRAPPER_CMU_bf_type CMU[4];
}GTM_WRAPPER_bf_type;

#define GTM_WRAPPER                ((volatile GTM_WRAPPER_bf_type *)0x400DA000UL)


#define TT_GTM_ATOM_CH_CTRL         GTM_ATOM_CH_CTRL_bf_type
#define TT_GTM_ATOM_AGC_ACT_TB         GTM_ATOM_AGC_ACT_TB_bf_type
#define TT_GTM_ATOM_AGC             GTM_ATOM_AGC_bf_type
#define TT_GTM_ATOM                 GTM_ATOM_bf_type
#define TT_GTM_ATOM_CH                 GTM_ATOM_CH_bf_type
#define TT_GTM_ATOM_CH_IRQ_EN        GTM_ATOM_CH_IRQ_EN_bf_type
#define TT_GTM_CDTM_DTM             GTM_CDTM_DTM_bf_type
#define TT_GTM_PSM_FIFO             GTM_PSM_FIFO_bf_type
#define TT_GTM_PSM_FIFO_CH             GTM_PSM_FIFO_CH_bf_type
#define TT_GTM_PSM_AFD_CH             GTM_PSM_AFD_CH_bf_type
#define TT_GTM_PSM_F2A                 GTM_PSM_F2A_bf_type
#define TT_GTM_SPE                     GTM_SPE_bf_type
#define TT_GTM_SPE_CTRL_STAT         GTM_SPE_CTRL_STAT_bf_type
#define TT_GTM_TIM_CH                 GTM_TIM_CH_bf_type
#define TT_GTM_TIM                     GTM_TIM_bf_type
#define TT_GTM_AUX_IN_SRC             GTM_CCM_TIM_AUX_IN_SRC_bf_type
#define TT_GTM_TIM_CH_IRQ_EN         GTM_TIM_CH_IRQ_EN_bf_type
#define TT_GTM_TIM_CH_CTRL             GTM_TIM_CH_CTRL_bf_type
#define TT_GTM_TOM_CH                  GTM_TOM_CH_bf_type
#define TT_GTM_TOM                     GTM_TOM_bf_type
#define TT_GTM_TOM_CH_IRQ_EN         GTM_TOM_CH_IRQ_EN_bf_type
#define TT_GTM_TOM_TGC                 GTM_TOM_TGC_bf_type
#define TT_GTM_TOM_TGC_ACT_TB         GTM_TOM_TGC_ACT_TB_bf_type
#define TT_GTM_TIM_CH_GPR0             GTM_TIM_CH_GPR0_bf_type
#define TT_GTM_TIM_CH_GPR1             GTM_TIM_CH_GPR1_bf_type
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
