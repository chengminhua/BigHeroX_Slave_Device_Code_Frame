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
**  FILENAME     : Gtm_Hw_Dtm.c                                               **
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
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                              Include Files
 ******************************************************************************/
#include "Gtm_Hw_Dtm.h"
#ifdef USING_OS_AUTOSAROS
#include "SchM_Gtm.h"
#endif

/******************************************************************************
 *                       Source File Version Information
 ******************************************************************************/
#define GTM_HW_DTM_VENDOR_ID_C                      1541
#define GTM_HW_DTM_MODULE_ID_C                      221
#define GTM_HW_DTM_AR_RELEASE_MAJOR_VERSION_C       4
#define GTM_HW_DTM_AR_RELEASE_MINOR_VERSION_C       4
#define GTM_HW_DTM_AR_RELEASE_PATCH_VERSION_C       0
#define GTM_HW_DTM_SW_MAJOR_VERSION_C               1
#define GTM_HW_DTM_SW_MINOR_VERSION_C               1
#define GTM_HW_DTM_SW_PATCH_VERSION_C               0
/******************************************************************************
 *                       File Version Checks
 ******************************************************************************/
/* Gtm_Hw_Dtm.h Gtm_Hw_Dtm.c file version check */
#if (GTM_HW_DTM_VENDOR_ID_H != GTM_HW_DTM_VENDOR_ID_C)
    #error "Gtm_Hw_Dtm.h and Gtm_Hw_Dtm.c have different vendor ids"
#endif
#if (GTM_HW_DTM_MODULE_ID_H != GTM_HW_DTM_MODULE_ID_C)
    #error "Gtm_Hw_Dtm.h and Gtm_Hw_Dtm.c have different module ids"
#endif
#if ((GTM_HW_DTM_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_DTM_AR_RELEASE_MAJOR_VERSION_C) || \
     (GTM_HW_DTM_AR_RELEASE_MINOR_VERSION_H != GTM_HW_DTM_AR_RELEASE_MINOR_VERSION_C) || \
     (GTM_HW_DTM_AR_RELEASE_PATCH_VERSION_H != GTM_HW_DTM_AR_RELEASE_PATCH_VERSION_C))
    #error "AutoSar Version Numbers of Gtm_Hw_Dtm.h and Gtm_Hw_Dtm.c are different"
#endif
#if ((GTM_HW_DTM_SW_MAJOR_VERSION_H != GTM_HW_DTM_SW_MAJOR_VERSION_C) || \
     (GTM_HW_DTM_SW_MINOR_VERSION_H != GTM_HW_DTM_SW_MINOR_VERSION_C) || \
     (GTM_HW_DTM_SW_PATCH_VERSION_H != GTM_HW_DTM_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Gtm_Dtm.h and Gtm_Dtm.c are different"
#endif

#ifdef USING_OS_AUTOSAROS
/* Gtm_Hw_Dtm.c SchM_Gtm.h file version check */
#if (GTM_HW_DTM_VENDOR_ID_C != SCHM_GTM_VENDOR_ID_H)
    #error "Gtm_Hw_Dtm.c and SchM_Gtm.h have different vendor ids"
#endif
#if ((GTM_HW_DTM_AR_RELEASE_MAJOR_VERSION_C != SCHM_GTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_DTM_AR_RELEASE_MINOR_VERSION_C != SCHM_GTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_DTM_AR_RELEASE_PATCH_VERSION_C != SCHM_GTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Dtm.c and SchM_Gtm.h are different"
#endif
#if ((GTM_HW_DTM_SW_MAJOR_VERSION_C != SCHM_GTM_SW_MAJOR_VERSION_H) || \
     (GTM_HW_DTM_SW_MINOR_VERSION_C != SCHM_GTM_SW_MINOR_VERSION_H) || \
     (GTM_HW_DTM_SW_PATCH_VERSION_C != SCHM_GTM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Dtm.c and SchM_Gtm.h are different"
#endif
#endif
/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
#if (TT_GTM_USE_DTM == TRUE)
#define DTM_NAME_CONNECT(cdtm, dtm, field) CDTM##cdtm##_DTM##dtm##_##field

/**
* @brief        DTM_INIT
* @details      DTM initialization.
* @param[in]    cdtm : GTM CDTM number
* @param[in]    dtm : Cdtm's dtm number
* @return       None
* @retval       None
* @pre
*/
#define DTM_INIT(cdtm, dtm) \
do { \
    /* Select clock source.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CTRL.B.CLK_SEL = DTM_NAME_CONNECT(cdtm, dtm, CLK_SEL); \
    /* Set asynchronous update mode.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CTRL.B.UPD_MODE = 0U; \
    /* Set CH0-CH1 cross dead time.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.XDT_EN_0_1 = DTM_NAME_CONNECT(cdtm, dtm, CH0_CH1_DT_TYPE); \
    /* Set CH2-CH3 cross dead time.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.XDT_EN_2_3 = DTM_NAME_CONNECT(cdtm, dtm, CH2_CH3_DT_TYPE); \
    /* Disable input signal shift on channel 1.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.SH_EN_1 = 0; \
    /* Disable input signal shift on channel 2.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.SH_EN_2 = 0; \
    /* Disable input signal shift on channel 3.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.SH_EN_3 = 0; \
    /* Set output polarity.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL0_0 = DTM_NAME_CONNECT(cdtm, dtm, POL0_0); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL1_0 = DTM_NAME_CONNECT(cdtm, dtm, POL1_0); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL0_1 = DTM_NAME_CONNECT(cdtm, dtm, POL0_1); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL1_1 = DTM_NAME_CONNECT(cdtm, dtm, POL1_1); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL0_2 = DTM_NAME_CONNECT(cdtm, dtm, POL0_2); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL1_2 = DTM_NAME_CONNECT(cdtm, dtm, POL1_2); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL0_3 = DTM_NAME_CONNECT(cdtm, dtm, POL0_3); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL1_3 = DTM_NAME_CONNECT(cdtm, dtm, POL1_3); \
    /* Set dead time rising/falling edges.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[0].B.RELRISE = DTM_NAME_CONNECT(cdtm, dtm, CH0_RELRISE); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[0].B.RELFALL = DTM_NAME_CONNECT(cdtm, dtm, CH0_RELFALL); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[1].B.RELRISE = DTM_NAME_CONNECT(cdtm, dtm, CH1_RELRISE); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[1].B.RELFALL = DTM_NAME_CONNECT(cdtm, dtm, CH1_RELFALL); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[2].B.RELRISE = DTM_NAME_CONNECT(cdtm, dtm, CH2_RELRISE); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[2].B.RELFALL = DTM_NAME_CONNECT(cdtm, dtm, CH2_RELFALL); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[3].B.RELRISE = DTM_NAME_CONNECT(cdtm, dtm, CH3_RELRISE); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[3].B.RELFALL = DTM_NAME_CONNECT(cdtm, dtm, CH3_RELFALL); \
} while (FALSE)

/**
* @brief        DTM_INIT_CHECK
* @details      DTM initialization check.
* @param[in]    cdtm : GTM CDTM number
* @param[in]    dtm : Cdtm's dtm number
* @return       None
* @retval       None
* @pre
*/
#define DTM_INIT_CHECK(cdtm, dtm) \
do { \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CTRL.B.CLK_SEL, DTM_NAME_CONNECT(cdtm, dtm, CLK_SEL)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CTRL.B.UPD_MODE, 0U); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.XDT_EN_0_1, DTM_NAME_CONNECT(cdtm, dtm, CH0_CH1_DT_TYPE)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.XDT_EN_2_3, DTM_NAME_CONNECT(cdtm, dtm, CH2_CH3_DT_TYPE)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.SH_EN_1, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.SH_EN_2, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL1.B.SH_EN_3, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL0_0, DTM_NAME_CONNECT(cdtm, dtm, POL0_0)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL1_0, DTM_NAME_CONNECT(cdtm, dtm, POL1_0)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL0_1, DTM_NAME_CONNECT(cdtm, dtm, POL0_1)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL1_1, DTM_NAME_CONNECT(cdtm, dtm, POL1_1)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL0_2, DTM_NAME_CONNECT(cdtm, dtm, POL0_2)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL1_2, DTM_NAME_CONNECT(cdtm, dtm, POL1_2)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL0_3, DTM_NAME_CONNECT(cdtm, dtm, POL0_3)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.POL1_3, DTM_NAME_CONNECT(cdtm, dtm, POL1_3)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[0].B.RELRISE, DTM_NAME_CONNECT(cdtm, dtm, CH0_RELRISE)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[0].B.RELFALL, DTM_NAME_CONNECT(cdtm, dtm, CH0_RELFALL)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[1].B.RELRISE, DTM_NAME_CONNECT(cdtm, dtm, CH1_RELRISE)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[1].B.RELFALL, DTM_NAME_CONNECT(cdtm, dtm, CH1_RELFALL)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[2].B.RELRISE, DTM_NAME_CONNECT(cdtm, dtm, CH2_RELRISE)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[2].B.RELFALL, DTM_NAME_CONNECT(cdtm, dtm, CH2_RELFALL)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[3].B.RELRISE, DTM_NAME_CONNECT(cdtm, dtm, CH3_RELRISE)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_DTV[3].B.RELFALL, DTM_NAME_CONNECT(cdtm, dtm, CH3_RELFALL)); \
} while (FALSE)

/**
* @brief        DTM_ENABLE
* @details      CDTM's DTM enable.
* @param[in]    cdtm : GTM CDTM number
* @param[in]    dtm : Cdtm's dtm number
* @return       None
* @retval       None
* @pre
*/
#define DTM_ENABLE(cdtm, dtm) \
do { \
    /* Enable dead time path.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_0 = DTM_NAME_CONNECT(cdtm, dtm, DT0_0); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_0 = DTM_NAME_CONNECT(cdtm, dtm, DT1_0); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_1 = DTM_NAME_CONNECT(cdtm, dtm, DT0_1); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_1 = DTM_NAME_CONNECT(cdtm, dtm, DT1_1); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_2 = DTM_NAME_CONNECT(cdtm, dtm, DT0_2); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_2 = DTM_NAME_CONNECT(cdtm, dtm, DT1_2); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_3 = DTM_NAME_CONNECT(cdtm, dtm, DT0_3); \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_3 = DTM_NAME_CONNECT(cdtm, dtm, DT1_3); \
} while (FALSE)

/**
* @brief        DTM_ENABLE_CHECK
* @details      CDTM's DTM enable check.
* @param[in]    cdtm : GTM CDTM number
* @param[in]    dtm : Cdtm's dtm number
* @return       None
* @retval       None
* @pre
*/
#define DTM_ENABLE_CHECK(cdtm, dtm) \
do { \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_0, DTM_NAME_CONNECT(cdtm, dtm, DT0_0)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_0, DTM_NAME_CONNECT(cdtm, dtm, DT1_0)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_1, DTM_NAME_CONNECT(cdtm, dtm, DT0_1)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_1, DTM_NAME_CONNECT(cdtm, dtm, DT1_1)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_2, DTM_NAME_CONNECT(cdtm, dtm, DT0_2)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_2, DTM_NAME_CONNECT(cdtm, dtm, DT1_2)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_3, DTM_NAME_CONNECT(cdtm, dtm, DT0_3)); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_3, DTM_NAME_CONNECT(cdtm, dtm, DT1_3)); \
} while (FALSE)

/**
* @brief        DTM_DISABLE
* @details      CDTM's DTM disable.
* @param[in]    cdtm : GTM CDTM number
* @param[in]    dtm : Cdtm's dtm number
* @return       None
* @retval       None
* @pre
*/
#define DTM_DISABLE(cdtm, dtm) \
do { \
    /* Disable dead time path.*/ \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_0 = 0; \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_0 = 0; \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_1 = 0; \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_1 = 0; \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_2 = 0; \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_2 = 0; \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_3 = 0; \
    Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_3 = 0; \
} while (FALSE)

/**
* @brief        DTM_DISABLE_CHECK
* @details      CDTM's DTM disable check.
* @param[in]    cdtm : GTM CDTM number
* @param[in]    dtm : Cdtm's dtm number
* @return       None
* @retval       None
* @pre
*/
#define DTM_DISABLE_CHECK(cdtm, dtm) \
do { \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_0, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_0, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_1, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_1, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_2, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_2, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT0_3, 0); \
    GTM_REG_CHECK(Cdtm_PubReg[cdtm]->DTM[dtm].CH_CTRL2.B.DT1_3, 0); \
} while (FALSE)

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
 *                            Private Macros
 *******************************************************************************/

/******************************************************************************
 *                       Private Function Declaration
 ******************************************************************************/
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Hw_Dtm_PriInitCheck
* @details      Dtm init check.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriInitCheck(void);
#endif

#if (TT_GTM_USE_CDTM0 == TRUE)
/**
* @brief        Gtm_Hw_Dtm_PriStart0
* @details      Start DTM0 channels.
* @param[in]    dtm : Cdtm's dtm number
* @param[out]   None 
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriStart0(TT_CONST uint8 dtm);
#endif

#if (TT_GTM_USE_CDTM1 == TRUE)
/**
* @brief        Gtm_Hw_Dtm_PriStart1
* @details      Start DTM1 channels.
* @param[in]    dtm : Cdtm's dtm number
* @param[out]   None 
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriStart1(TT_CONST uint8 dtm);

#endif

#if (TT_GTM_USE_CDTM2 == TRUE)
/**
* @brief        Gtm_Hw_Dtm_PriStart2
* @details      Start DTM2 channels.
* @param[in]    dtm : Cdtm's dtm number
* @param[out]   None 
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriStart2(TT_CONST uint8 dtm);

#endif

#if (TT_GTM_USE_CDTM3 == TRUE)
/**
* @brief        Gtm_Hw_Dtm_PriStart3
* @details      Start DTM3 channels.
* @param[in]    dtm : Cdtm's dtm number
* @param[out]   None 
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriStart3(TT_CONST uint8 dtm);
#endif

/**
* @brief        Gtm_Hw_Dtm_PriGetDtmDriverPoint
* @details      Get Dtm driver struct point.
* @param[in]    Cdtm  : Cdtm Instance number.
* @param[in]    pFunc : Cdtm start function point.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
LOCAL_INLINE TT_RetType Gtm_Hw_Dtm_PriGetDtmStartFunc(uint32 Cdtm, Gtm_Dtm_StartFuncPtr *pFunc);

/******************************************************************************
 *                       Public Functions
 ******************************************************************************/
#define GTM_START_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

/**
* @brief        Gtm_Hw_Dtm_Init
* @details      Dtm initialization.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Dtm_Init(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* CDTM0 initialization */
#if (defined(CDTM0_DTM0_ENABLED) && (CDTM0_DTM0_ENABLED == TRUE))
    DTM_INIT(0, 0);
#endif
#if (defined(CDTM0_DTM1_ENABLED) && (CDTM0_DTM1_ENABLED == TRUE))
    DTM_INIT(0, 1);
#endif
#if (defined(CDTM0_DTM2_ENABLED) && (CDTM0_DTM2_ENABLED == TRUE))
    DTM_INIT(0, 2);
#endif
#if (defined(CDTM0_DTM3_ENABLED) && (CDTM0_DTM3_ENABLED == TRUE))
    DTM_INIT(0, 3);
#endif
#if (defined(CDTM0_DTM4_ENABLED) && (CDTM0_DTM4_ENABLED == TRUE))
    DTM_INIT(0, 4);
#endif
#if (defined(CDTM0_DTM5_ENABLED) && (CDTM0_DTM5_ENABLED == TRUE))
    DTM_INIT(0, 5);
#endif

    /* CDTM1 initialization */
#if (defined(CDTM1_DTM0_ENABLED) && (CDTM1_DTM0_ENABLED == TRUE))
    DTM_INIT(1, 0);
#endif
#if (defined(CDTM1_DTM1_ENABLED) && (CDTM1_DTM1_ENABLED == TRUE))
    DTM_INIT(1, 1);
#endif
#if (defined(CDTM1_DTM2_ENABLED) && (CDTM1_DTM2_ENABLED == TRUE))
    DTM_INIT(1, 2);
#endif
#if (defined(CDTM1_DTM3_ENABLED) && (CDTM1_DTM3_ENABLED == TRUE))
    DTM_INIT(1, 3);
#endif
#if (defined(CDTM1_DTM4_ENABLED) && (CDTM1_DTM4_ENABLED == TRUE))
    DTM_INIT(1, 4);
#endif
#if (defined(CDTM1_DTM5_ENABLED) && (CDTM1_DTM5_ENABLED == TRUE))
    DTM_INIT(1, 5);
#endif

    /* CDTM2 initialization */
#if (defined(CDTM2_DTM0_ENABLED) && (CDTM2_DTM0_ENABLED == TRUE))
    DTM_INIT(2, 0);
#endif
#if (defined(CDTM2_DTM1_ENABLED) && (CDTM2_DTM1_ENABLED == TRUE))
    DTM_INIT(2, 1);
#endif
#if (defined(CDTM2_DTM2_ENABLED) && (CDTM2_DTM2_ENABLED == TRUE))
    DTM_INIT(2, 2);
#endif
#if (defined(CDTM2_DTM3_ENABLED) && (CDTM2_DTM3_ENABLED == TRUE))
    DTM_INIT(2, 3);
#endif
#if (defined(CDTM2_DTM4_ENABLED) && (CDTM2_DTM4_ENABLED == TRUE))
    DTM_INIT(2, 4);
#endif
#if (defined(CDTM2_DTM5_ENABLED) && (CDTM2_DTM5_ENABLED == TRUE))
    DTM_INIT(2, 5);
#endif

    /* CDTM3 initialization */
#if (defined(CDTM3_DTM0_ENABLED) && (CDTM3_DTM0_ENABLED == TRUE))
    DTM_INIT(3, 0);
#endif
#if (defined(CDTM3_DTM1_ENABLED) && (CDTM3_DTM1_ENABLED == TRUE))
    DTM_INIT(3, 1);
#endif
#if (defined(CDTM3_DTM2_ENABLED) && (CDTM3_DTM2_ENABLED == TRUE))
    DTM_INIT(3, 2);
#endif
#if (defined(CDTM3_DTM3_ENABLED) && (CDTM3_DTM3_ENABLED == TRUE))
    DTM_INIT(3, 3);
#endif
#if (defined(CDTM3_DTM4_ENABLED) && (CDTM3_DTM4_ENABLED == TRUE))
    DTM_INIT(3, 4);
#endif
#if (defined(CDTM3_DTM5_ENABLED) && (CDTM3_DTM5_ENABLED == TRUE))
    DTM_INIT(3, 5);
#endif

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    Ret = Gtm_Hw_Dtm_PriInitCheck();
#else
    (void)Ret;
#endif

    return Ret;
}

/**
* @brief        Gtm_Hw_Dtm_Start
* @details      Start DTM channels.
* @param[in]    CdtmDtmIndex : GTM DTM Index
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Dtm_Start(Cdtm_DtmIndexType CdtmDtmIndex)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    Gtm_Dtm_StartFuncPtr Gtm_DtmStartFuncPtr = NULL_PTR;
    uint32 Cdtm = 0;
    uint32 Dtm = 0;

    TT_ParaCheck(CdtmDtmIndex > CDTM3_DTM5, TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Cdtm = Gtm_Hw_Dtm_PriGetCdtmIndex(CdtmDtmIndex);
        Dtm = Gtm_Hw_Dtm_PrinGetDtmIndex(CdtmDtmIndex);

        Ret = Gtm_Hw_Dtm_PriGetDtmStartFunc(Cdtm, &Gtm_DtmStartFuncPtr);

        if(Ret == TT_RET_SUCCESS)
        {
            Ret = Gtm_DtmStartFuncPtr(Dtm);
        }else
        {
            /* do nothing */
        }
    }else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Dtm_Stop
* @details      Stop DTM channels.
* @param[in]    CdtmDtmIndex : GTM DTM Index
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Dtm_Stop(Cdtm_DtmIndexType CdtmDtmIndex)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Cdtm = 0;
    uint32 Dtm = 0;

    TT_ParaCheck(CdtmDtmIndex > CDTM3_DTM5, TT_RET_PARAM_INDEX_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Cdtm = Gtm_Hw_Dtm_PriGetCdtmIndex(CdtmDtmIndex);
        Dtm = Gtm_Hw_Dtm_PrinGetDtmIndex(CdtmDtmIndex);

        DTM_DISABLE(Cdtm, Dtm);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        DTM_DISABLE_CHECK(Cdtm, Dtm);
#endif
    }else
    {
        /* do nothing */
    }

    return Ret;
}

/**
* @brief        Gtm_Hw_Dtm_SetDeadTime
* @details      Set the dead zone time.
* @param[in]    CdtmDtmChIndex : GTM DTM channel Index
* @param[in]    riseEdgeTime   : Rise edge dead zone time
* @param[in]    fallEdgeTime   : fall edge dead zone time
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Dtm_SetDeadTime(Cdtm_DtmChannelIndexType CdtmDtmChIndex,
                                  uint16 RiseEdgeTime, uint16 FallEdgeTime)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    uint32 Cdtm = 0;
    uint32 Dtm = 0;
    uint32 Ch = 0;

    TT_ParaCheck(CdtmDtmChIndex > CDTM3_DTM5_CH3, TT_RET_PARAM_INDEX_ERR, &Ret);
    TT_ParaCheck(((RiseEdgeTime >> 13U) > 0U) || ((FallEdgeTime >> 13U) > 0U), TT_RET_PARAM_LEN_ERR, &Ret);

    if(Ret == TT_RET_SUCCESS)
    {
        Cdtm = (uint32)CdtmDtmChIndex / ((uint32)CDTM0_DTM5_CH3 + 1U);
        Dtm = (uint32)CdtmDtmChIndex % ((uint32)CDTM0_DTM5_CH3 + 1U);
        Ch = Gtm_Hw_Dtm_PriGetChannelIndex(CdtmDtmChIndex);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Enter_Gtm_GTM_EXCLUSIVE_AREA_22();
#endif
#endif
        Cdtm_PubReg[Cdtm]->DTM[Dtm].CH_DTV[Ch].R = ((uint32)RiseEdgeTime & 0x1FFFU) | (((uint32)FallEdgeTime & 0x1FFFU) << 16U);

#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
        GTM_REG_CHECK(Cdtm_PubReg[Cdtm]->DTM[Dtm].CH_DTV[Ch].R, ((uint32)RiseEdgeTime & 0x1FFFU) | (((uint32)FallEdgeTime & 0x1FFFU) << 16U));
#endif
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
#ifdef USING_OS_AUTOSAROS
        SchM_Exit_Gtm_GTM_EXCLUSIVE_AREA_22();
#endif
#endif
    }else
    {
        /* do nothing */
    }

    return Ret;
}

/******************************************************************************
 *                       Private Function
 ******************************************************************************/
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
/**
* @brief        Gtm_Hw_Dtm_PriInitCheck
* @details      Dtm init check.
* @param[in]    None
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriInitCheck(void)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    /* CDTM0 initialization check */
#if (defined(CDTM0_DTM0_ENABLED) && (CDTM0_DTM0_ENABLED == TRUE))
    DTM_INIT_CHECK(0, 0);
#endif
#if (defined(CDTM0_DTM1_ENABLED) && (CDTM0_DTM1_ENABLED == TRUE))
    DTM_INIT_CHECK(0, 1);
#endif
#if (defined(CDTM0_DTM2_ENABLED) && (CDTM0_DTM2_ENABLED == TRUE))
    DTM_INIT_CHECK(0, 2);
#endif
#if (defined(CDTM0_DTM3_ENABLED) && (CDTM0_DTM3_ENABLED == TRUE))
    DTM_INIT_CHECK(0, 3);
#endif
#if (defined(CDTM0_DTM4_ENABLED) && (CDTM0_DTM4_ENABLED == TRUE))
    DTM_INIT_CHECK(0, 4);
#endif
#if (defined(CDTM0_DTM5_ENABLED) && (CDTM0_DTM5_ENABLED == TRUE))
    DTM_INIT_CHECK(0, 5);
#endif

    /* CDTM1 initialization check */
#if (defined(CDTM1_DTM0_ENABLED) && (CDTM1_DTM0_ENABLED == TRUE))
    DTM_INIT_CHECK(1, 0);
#endif
#if (defined(CDTM1_DTM1_ENABLED) && (CDTM1_DTM1_ENABLED == TRUE))
    DTM_INIT_CHECK(1, 1);
#endif
#if (defined(CDTM1_DTM2_ENABLED) && (CDTM1_DTM2_ENABLED == TRUE))
    DTM_INIT_CHECK(1, 2);
#endif
#if (defined(CDTM1_DTM3_ENABLED) && (CDTM1_DTM3_ENABLED == TRUE))
    DTM_INIT_CHECK(1, 3);
#endif
#if (defined(CDTM1_DTM4_ENABLED) && (CDTM1_DTM4_ENABLED == TRUE))
    DTM_INIT_CHECK(1, 4);
#endif
#if (defined(CDTM1_DTM5_ENABLED) && (CDTM1_DTM5_ENABLED == TRUE))
    DTM_INIT_CHECK(1, 5);
#endif

    /* CDTM2 initialization check */
#if (defined(CDTM2_DTM0_ENABLED) && (CDTM2_DTM0_ENABLED == TRUE))
    DTM_INIT_CHECK(2, 0);
#endif
#if (defined(CDTM2_DTM1_ENABLED) && (CDTM2_DTM1_ENABLED == TRUE))
    DTM_INIT_CHECK(2, 1);
#endif
#if (defined(CDTM2_DTM2_ENABLED) && (CDTM2_DTM2_ENABLED == TRUE))
    DTM_INIT_CHECK(2, 2);
#endif
#if (defined(CDTM2_DTM3_ENABLED) && (CDTM2_DTM3_ENABLED == TRUE))
    DTM_INIT_CHECK(2, 3);
#endif
#if (defined(CDTM2_DTM4_ENABLED) && (CDTM2_DTM4_ENABLED == TRUE))
    DTM_INIT_CHECK(2, 4);
#endif
#if (defined(CDTM2_DTM5_ENABLED) && (CDTM2_DTM5_ENABLED == TRUE))
    DTM_INIT_CHECK(2, 5);
#endif

    /* CDTM3 initialization check */
#if (defined(CDTM3_DTM0_ENABLED) && (CDTM3_DTM0_ENABLED == TRUE))
    DTM_INIT_CHECK(3, 0);
#endif
#if (defined(CDTM3_DTM1_ENABLED) && (CDTM3_DTM1_ENABLED == TRUE))
    DTM_INIT_CHECK(3, 1);
#endif
#if (defined(CDTM3_DTM2_ENABLED) && (CDTM3_DTM2_ENABLED == TRUE))
    DTM_INIT_CHECK(3, 2);
#endif
#if (defined(CDTM3_DTM3_ENABLED) && (CDTM3_DTM3_ENABLED == TRUE))
    DTM_INIT_CHECK(3, 3);
#endif
#if (defined(CDTM3_DTM4_ENABLED) && (CDTM3_DTM4_ENABLED == TRUE))
    DTM_INIT_CHECK(3, 4);
#endif
#if (defined(CDTM3_DTM5_ENABLED) && (CDTM3_DTM5_ENABLED == TRUE))
    DTM_INIT_CHECK(3, 5);
#endif

    return Ret;
}
#endif

#if (TT_GTM_USE_CDTM0 == TRUE)
/**
* @brief        Gtm_Hw_Dtm_PriStart0
* @details      Start DTM channels.
* @param[in]    dtm : Cdtm's dtm number
* @param[out]   None 
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriStart0(TT_CONST uint8 dtm)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    switch(dtm)
    {
#if (defined(CDTM0_DTM0_ENABLED) && (CDTM0_DTM0_ENABLED == TRUE))
        case 0:
            DTM_ENABLE(0, 0);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(0, 0);
#endif
        break;
#else
        case 0:  /* do nothing */break;        
#endif

#if (defined(CDTM0_DTM1_ENABLED) && (CDTM0_DTM1_ENABLED == TRUE))
        case 1:
            DTM_ENABLE(0, 1);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(0, 1);
#endif
        break;
#endif
#if (defined(CDTM0_DTM2_ENABLED) && (CDTM0_DTM2_ENABLED == TRUE))
        case 2:
            DTM_ENABLE(0, 2);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(0, 2);
#endif
        break;
#endif
#if (defined(CDTM0_DTM3_ENABLED) && (CDTM0_DTM3_ENABLED == TRUE))
        case 3:
            DTM_ENABLE(0, 3);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(0, 3);
#endif
            break;
#endif
#if (defined(CDTM0_DTM4_ENABLED) && (CDTM0_DTM4_ENABLED == TRUE))
        case 4:
            DTM_ENABLE(0, 4);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(0, 4);
#endif
            break;
#endif
#if (defined(CDTM0_DTM5_ENABLED) && (CDTM0_DTM5_ENABLED == TRUE))
        case 5:
            DTM_ENABLE(0, 5);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(0, 5);
#endif
            break;
#endif
        default: /* do nothing */break;
    }
    return Ret;
}
#endif

#if (TT_GTM_USE_CDTM1 == TRUE)
/**
* @brief        Gtm_Hw_Dtm_PriStart1
* @details      Start DTM1 channels.
* @param[in]    dtm : Cdtm's dtm number
* @param[out]   None 
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriStart1(TT_CONST uint8 dtm)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    switch(dtm)
    {
#if (defined(CDTM1_DTM0_ENABLED) && (CDTM1_DTM0_ENABLED == TRUE))
        case 0:
            DTM_ENABLE(1, 0);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(1, 0);
#endif
        break;
#endif
#if (defined(CDTM1_DTM1_ENABLED) && (CDTM1_DTM1_ENABLED == TRUE))
        case 1:
            DTM_ENABLE(1, 1);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(1, 1);
#endif
        break;
#endif
#if (defined(CDTM1_DTM2_ENABLED) && (CDTM1_DTM2_ENABLED == TRUE))
        case 2:
            DTM_ENABLE(1, 2);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(1, 2);
#endif
        break;
#else
        case 0:  /* do nothing */break;
#endif
#if (defined(CDTM1_DTM3_ENABLED) && (CDTM1_DTM3_ENABLED == TRUE))
        case 3:
            DTM_ENABLE(1, 3);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(1, 3);
#endif
            break;
#endif
#if (defined(CDTM1_DTM4_ENABLED) && (CDTM1_DTM4_ENABLED == TRUE))
        case 4:
            DTM_ENABLE(1, 4);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(1, 4);
#endif
            break;
#endif
#if (defined(CDTM1_DTM5_ENABLED) && (CDTM1_DTM5_ENABLED == TRUE))
        case 5:
            DTM_ENABLE(1, 5);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(1, 5);
#endif
            break;
#endif
        default: /* do nothing */break;
    }
    return Ret;
}
#endif

#if (TT_GTM_USE_CDTM2 == TRUE)
/**
* @brief        Gtm_Hw_Dtm_PriStart2
* @details      Start DTM2 channels.
* @param[in]    dtm : Cdtm's dtm number
* @param[out]   None 
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriStart2(TT_CONST uint8 dtm)
{
    TT_RetType Ret = TT_RET_SUCCESS;

        switch(dtm)
        {
#if (defined(CDTM2_DTM0_ENABLED) && (CDTM2_DTM0_ENABLED == TRUE))
        case 0:
            DTM_ENABLE(2, 0);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(2, 0);
#endif
        break;
#else
        case 0:  /* do nothing */break;
#endif
#if (defined(CDTM2_DTM1_ENABLED) && (CDTM2_DTM1_ENABLED == TRUE))
        case 1:
            DTM_ENABLE(2, 1);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(2, 1);
#endif
        break;
#endif
#if (defined(CDTM2_DTM2_ENABLED) && (CDTM2_DTM2_ENABLED == TRUE))
        case 2:
            DTM_ENABLE(2, 2);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(2, 2);
#endif
        break;
#endif
#if (defined(CDTM2_DTM3_ENABLED) && (CDTM2_DTM3_ENABLED == TRUE))
        case 3:
            DTM_ENABLE(2, 3);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(2, 3);
#endif
            break;
#endif
#if (defined(CDTM2_DTM4_ENABLED) && (CDTM2_DTM4_ENABLED == TRUE))
        case 4:
            DTM_ENABLE(2, 4);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(2, 4);
#endif
            break;
#endif
#if (defined(CDTM2_DTM5_ENABLED) && (CDTM2_DTM5_ENABLED == TRUE))
        case 5:
            DTM_ENABLE(2, 5);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(2, 5);
#endif
            break;
#endif
        default: /* do nothing */break;
    }
    return Ret;
}
#endif

#if (TT_GTM_USE_CDTM3 == TRUE)
/**
* @brief        Gtm_Hw_Dtm_PriStart3
* @details      Start DTM3 channels.
* @param[in]    dtm : Cdtm's dtm number
* @param[out]   None 
* @return       None
* @retval       None
* @pre
*/
static TT_RetType Gtm_Hw_Dtm_PriStart3(TT_CONST uint8 dtm)
{
    TT_RetType Ret = TT_RET_SUCCESS;

    switch(dtm)
    {
#if (defined(CDTM3_DTM0_ENABLED) && (CDTM3_DTM0_ENABLED == TRUE))
        case 0:
            DTM_ENABLE(3, 0);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(3, 0);
#endif
        break;
#else
        case 0:  /* do nothing */break;
#endif
#if (defined(CDTM3_DTM1_ENABLED) && (CDTM3_DTM1_ENABLED == TRUE))
        case 1:
            DTM_ENABLE(3, 1);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(3, 1);
#endif
        break;
#endif
#if (defined(CDTM3_DTM2_ENABLED) && (CDTM3_DTM2_ENABLED == TRUE))
        case 2:
            DTM_ENABLE(3, 2);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(3, 2);
#endif
        break;
#endif
#if (defined(CDTM3_DTM3_ENABLED) && (CDTM3_DTM3_ENABLED == TRUE))
        case 3:
            DTM_ENABLE(3, 3);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(3, 3);
#endif
            break;
#endif
#if (defined(CDTM3_DTM4_ENABLED) && (CDTM3_DTM4_ENABLED == TRUE))
        case 4:
            DTM_ENABLE(3, 4);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(3, 4);
#endif
            break;
#endif
#if (defined(CDTM3_DTM5_ENABLED) && (CDTM3_DTM5_ENABLED == TRUE))
        case 5:
            DTM_ENABLE(3, 5);
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
            DTM_ENABLE_CHECK(3, 5);
#endif
            break;
#endif
        default: /* do nothing */break;
    }
    return Ret;
}
#endif

/**
* @brief        Gtm_Hw_Dtm_PriGetDtmDriverPoint
* @details      Get Dtm driver struct point.
* @param[in]    Cdtm  : Cdtm Instance number.
* @param[in]    pFunc : Cdtm start function point.
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
LOCAL_INLINE TT_RetType Gtm_Hw_Dtm_PriGetDtmStartFunc(uint32 Cdtm, Gtm_Dtm_StartFuncPtr *pFunc)
{
    TT_RetType Ret = TT_RET_SUCCESS;
    TT_UNUSED_PARAMETER(pFunc);

    switch(Cdtm)
    {
        case 0:
#if (defined(TT_GTM_USE_CDTM0) && (TT_GTM_USE_CDTM0 == TRUE))
            *pFunc = Gtm_Hw_Dtm_PriStart0;
#else
            Ret = TT_RET_PARAM_INDEX_ERR;
#endif
            break;
        case 1:
#if (defined(TT_GTM_USE_CDTM1) && (TT_GTM_USE_CDTM1 == TRUE))
            *pFunc = Gtm_Hw_Dtm_PriStart1;
#else
            Ret = TT_RET_PARAM_INDEX_ERR;
#endif
            break;
        case 2:
#if (defined(TT_GTM_USE_CDTM2) && (TT_GTM_USE_CDTM2 == TRUE))
            *pFunc = Gtm_Hw_Dtm_PriStart2;
#else
            Ret = TT_RET_PARAM_INDEX_ERR;
#endif
            break;
        case 3:
#if (defined(TT_GTM_USE_CDTM3) && (TT_GTM_USE_CDTM3 == TRUE))
            *pFunc = Gtm_Hw_Dtm_PriStart3;
#else
            Ret = TT_RET_PARAM_INDEX_ERR;
#endif
            break;
        default:
            Ret = TT_RET_PARAM_INDEX_ERR;
            break;
    }

    return Ret;
}

#define GTM_STOP_SEC_CODE_SLOW
#include "Gtm_MemMap.h"

#endif /* TT_GTM_USE_DTM */

#ifdef __cplusplus
}
#endif

