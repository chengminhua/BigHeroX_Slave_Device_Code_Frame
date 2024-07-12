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
**  FILENAME     : Gtm_Hw_Cmu_Types.h                                         **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Gtm Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef GTM_HW_DTM_TYPES_H
#define GTM_HW_DTM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Base.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_DTM_TYPES_VENDOR_ID_H                      1541
#define GTM_HW_DTM_TYPES_MODULE_ID_H                      221
#define GTM_HW_DTM_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_DTM_TYPES_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_DTM_TYPES_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_DTM_TYPES_SW_MAJOR_VERSION_H               1
#define GTM_HW_DTM_TYPES_SW_MINOR_VERSION_H               1
#define GTM_HW_DTM_TYPES_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Base.h Gtm_Hw_Dtm_Types.h file version check */
#if (GTM_HW_BASE_VENDOR_ID_H != GTM_HW_DTM_TYPES_VENDOR_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Dtm_Types.h have different vendor ids"
#endif

#if (GTM_HW_BASE_MODULE_ID_H != GTM_HW_DTM_TYPES_MODULE_ID_H)
    #error "Gtm_Hw_Base.h and Gtm_Hw_Dtm_Types.h have different module ids"
#endif

#if ((GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_DTM_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H != GTM_HW_DTM_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H != GTM_HW_DTM_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Dtm_Types.h are different"
#endif

#if ((GTM_HW_BASE_SW_MAJOR_VERSION_H != GTM_HW_DTM_TYPES_SW_MAJOR_VERSION_H) || \
     (GTM_HW_BASE_SW_MINOR_VERSION_H != GTM_HW_DTM_TYPES_SW_MINOR_VERSION_H) || \
     (GTM_HW_BASE_SW_PATCH_VERSION_H != GTM_HW_DTM_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Base.h and Gtm_Hw_Dtm_Types.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* DTM Instance max number*/
#define CDTM_INSTANCE_MAX_NUM           (3U)

/* CDTM DTM max number*/
#define CDTM_DTM_MAX_NUM                (5U)

/* CDTM DTM 2/3 max number*/
#define CDTM2_3_DTM_MIN_NUM             (4U)

/* CDTM Maximum number of DTM channels */
#define CDTM_DTM_CH_MAX_NUM             (3U)

/* Maximum CDTM index of TOM */
#define CDTM_TOM_MAX_INSTANCE           (1U)

/******************************************************************************
*                            Enums
*******************************************************************************/
/* Cdtm's dtm number */
typedef enum
{
    CDTM0_DTM0 = 0x000U,
    CDTM0_DTM1 = 0x001U,
    CDTM0_DTM2 = 0x002U,
    CDTM0_DTM3 = 0x003U,
    CDTM0_DTM4 = 0x004U,
    CDTM0_DTM5 = 0x005U,

    CDTM1_DTM0 = 0x006U,
    CDTM1_DTM1 = 0x007U,
    CDTM1_DTM2 = 0x008U,
    CDTM1_DTM3 = 0x009U,
    CDTM1_DTM4 = 0x00AU,
    CDTM1_DTM5 = 0x00BU,

    CDTM2_DTM0 = 0x00CU,
    CDTM2_DTM1 = 0x00DU,
    CDTM2_DTM2 = 0x00EU,
    CDTM2_DTM3 = 0x00FU,
    CDTM2_DTM4 = 0x010U,
    CDTM2_DTM5 = 0x011U,

    CDTM3_DTM0 = 0x012U,
    CDTM3_DTM1 = 0x013U,
    CDTM3_DTM2 = 0x014U,
    CDTM3_DTM3 = 0x015U,
    CDTM3_DTM4 = 0x016U,
    CDTM3_DTM5 = 0x017U,
} Cdtm_DtmIndexType;

/* Cdtm's dtm channel number */
typedef enum {
    CDTM0_DTM0_CH0 = 0x000U,
    CDTM0_DTM0_CH1 = 0x001U,
    CDTM0_DTM0_CH2 = 0x002U,
    CDTM0_DTM0_CH3 = 0x003U,
    CDTM0_DTM1_CH0 = 0x004U,
    CDTM0_DTM1_CH1 = 0x005U,
    CDTM0_DTM1_CH2 = 0x006U,
    CDTM0_DTM1_CH3 = 0x007U,
    CDTM0_DTM2_CH0 = 0x008U,
    CDTM0_DTM2_CH1 = 0x009U,
    CDTM0_DTM2_CH2 = 0x00AU,
    CDTM0_DTM2_CH3 = 0x00BU,
    CDTM0_DTM3_CH0 = 0x00CU,
    CDTM0_DTM3_CH1 = 0x00DU,
    CDTM0_DTM3_CH2 = 0x00EU,
    CDTM0_DTM3_CH3 = 0x00FU,
    CDTM0_DTM4_CH0 = 0x010U,
    CDTM0_DTM4_CH1 = 0x011U,
    CDTM0_DTM4_CH2 = 0x012U,
    CDTM0_DTM4_CH3 = 0x013U,
    CDTM0_DTM5_CH0 = 0x014U,
    CDTM0_DTM5_CH1 = 0x015U,
    CDTM0_DTM5_CH2 = 0x016U,
    CDTM0_DTM5_CH3 = 0x017U,

    CDTM1_DTM0_CH0 = 0x018U,
    CDTM1_DTM0_CH1 = 0x019U,
    CDTM1_DTM0_CH2 = 0x01AU,
    CDTM1_DTM0_CH3 = 0x01BU,
    CDTM1_DTM1_CH0 = 0x01CU,
    CDTM1_DTM1_CH1 = 0x01DU,
    CDTM1_DTM1_CH2 = 0x01EU,
    CDTM1_DTM1_CH3 = 0x01FU,
    CDTM1_DTM2_CH0 = 0x020U,
    CDTM1_DTM2_CH1 = 0x021U,
    CDTM1_DTM2_CH2 = 0x022U,
    CDTM1_DTM2_CH3 = 0x023U,
    CDTM1_DTM3_CH0 = 0x024U,
    CDTM1_DTM3_CH1 = 0x025U,
    CDTM1_DTM3_CH2 = 0x026U,
    CDTM1_DTM3_CH3 = 0x027U,
    CDTM1_DTM4_CH0 = 0x028U,
    CDTM1_DTM4_CH1 = 0x029U,
    CDTM1_DTM4_CH2 = 0x02AU,
    CDTM1_DTM4_CH3 = 0x02BU,
    CDTM1_DTM5_CH0 = 0x02CU,
    CDTM1_DTM5_CH1 = 0x02DU,
    CDTM1_DTM5_CH2 = 0x02EU,
    CDTM1_DTM5_CH3 = 0x02FU,

    CDTM2_DTM0_CH0 = 0x030U,
    CDTM2_DTM0_CH1 = 0x031U,
    CDTM2_DTM0_CH2 = 0x032U,
    CDTM2_DTM0_CH3 = 0x033U,
    CDTM2_DTM1_CH0 = 0x034U,
    CDTM2_DTM1_CH1 = 0x035U,
    CDTM2_DTM1_CH2 = 0x036U,
    CDTM2_DTM1_CH3 = 0x037U,
    CDTM2_DTM2_CH0 = 0x038U,
    CDTM2_DTM2_CH1 = 0x039U,
    CDTM2_DTM2_CH2 = 0x03AU,
    CDTM2_DTM2_CH3 = 0x03BU,
    CDTM2_DTM3_CH0 = 0x03CU,
    CDTM2_DTM3_CH1 = 0x03DU,
    CDTM2_DTM3_CH2 = 0x03EU,
    CDTM2_DTM3_CH3 = 0x03FU,
    CDTM2_DTM4_CH0 = 0x040U,
    CDTM2_DTM4_CH1 = 0x041U,
    CDTM2_DTM4_CH2 = 0x042U,
    CDTM2_DTM4_CH3 = 0x043U,
    CDTM2_DTM5_CH0 = 0x044U,
    CDTM2_DTM5_CH1 = 0x045U,
    CDTM2_DTM5_CH2 = 0x046U,
    CDTM2_DTM5_CH3 = 0x047U,

    CDTM3_DTM0_CH0 = 0x048U,
    CDTM3_DTM0_CH1 = 0x049U,
    CDTM3_DTM0_CH2 = 0x04AU,
    CDTM3_DTM0_CH3 = 0x04BU,
    CDTM3_DTM1_CH0 = 0x04CU,
    CDTM3_DTM1_CH1 = 0x04DU,
    CDTM3_DTM1_CH2 = 0x04EU,
    CDTM3_DTM1_CH3 = 0x04FU,
    CDTM3_DTM2_CH0 = 0x050U,
    CDTM3_DTM2_CH1 = 0x051U,
    CDTM3_DTM2_CH2 = 0x052U,
    CDTM3_DTM2_CH3 = 0x053U,
    CDTM3_DTM3_CH0 = 0x054U,
    CDTM3_DTM3_CH1 = 0x055U,
    CDTM3_DTM3_CH2 = 0x056U,
    CDTM3_DTM3_CH3 = 0x057U,
    CDTM3_DTM4_CH0 = 0x058U,
    CDTM3_DTM4_CH1 = 0x059U,
    CDTM3_DTM4_CH2 = 0x05AU,
    CDTM3_DTM4_CH3 = 0x05BU,
    CDTM3_DTM5_CH0 = 0x05CU,
    CDTM3_DTM5_CH1 = 0x05DU,
    CDTM3_DTM5_CH2 = 0x05EU,
    CDTM3_DTM5_CH3 = 0x05FU,
} Cdtm_DtmChannelIndexType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* Type of a poninter of CDTM DTM start function. */
typedef TT_RetType (*Gtm_Dtm_StartFuncPtr)(TT_CONST uint8);


#ifdef __cplusplus
}
#endif

#endif /* _Alioth_Gtm_Dtm_H_ */
/** @} */
