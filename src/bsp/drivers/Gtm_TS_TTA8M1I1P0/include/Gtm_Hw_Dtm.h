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
**  FILENAME     : Gtm_Hw_Dtm.h                                               **
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
#ifndef GTM_HW_DTM_H
#define GTM_HW_DTM_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Hw_Dtm_Types.h"


/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_DTM_VENDOR_ID_H                      1541
#define GTM_HW_DTM_MODULE_ID_H                      221
#define GTM_HW_DTM_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_DTM_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_DTM_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_DTM_SW_MAJOR_VERSION_H               1
#define GTM_HW_DTM_SW_MINOR_VERSION_H               1
#define GTM_HW_DTM_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Dtm_Types.h Gtm_Hw_Dtm.h file version check */
#if (GTM_HW_DTM_TYPES_VENDOR_ID_H != GTM_HW_DTM_VENDOR_ID_H)
    #error "Gtm_Hw_Dtm_Types.h and Gtm_Hw_Dtm.h have different vendor ids"
#endif

#if (GTM_HW_DTM_TYPES_MODULE_ID_H != GTM_HW_DTM_MODULE_ID_H)
    #error "Gtm_Hw_Dtm_Types.h and Gtm_Hw_Dtm.h have different module ids"
#endif

#if ((GTM_HW_DTM_TYPES_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_DTM_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_DTM_TYPES_AR_RELEASE_MINOR_VERSION_H != GTM_HW_DTM_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_DTM_TYPES_AR_RELEASE_PATCH_VERSION_H != GTM_HW_DTM_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Dtm_Types.h and Gtm_Hw_Dtm.h are different"
#endif

#if ((GTM_HW_DTM_TYPES_SW_MAJOR_VERSION_H != GTM_HW_DTM_SW_MAJOR_VERSION_H) || \
     (GTM_HW_DTM_TYPES_SW_MINOR_VERSION_H != GTM_HW_DTM_SW_MINOR_VERSION_H) || \
     (GTM_HW_DTM_TYPES_SW_PATCH_VERSION_H != GTM_HW_DTM_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Dtm_Types.h and Gtm_Hw_Dtm.h are different"
#endif


/******************************************************************************
*                            Defines And Macros
*******************************************************************************/

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Public Variable Declarations
*******************************************************************************/
#if (TT_GTM_USE_DTM == TRUE)

#if ((TT_GTM_USE_CDTM0 == FALSE) && (TT_GTM_USE_CDTM1 == FALSE) && \
     (TT_GTM_USE_CDTM2 == FALSE) && (TT_GTM_USE_CDTM3 == FALSE))
#error "DTM module enabled but no DTM selected"
#endif


/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
/**
* @brief        Gtm_Hw_Dtm_PriGetCdtmIndex
* @details      Gets the Cdtm instance number.
* @param[in]    CdtmDtmChIndex:    Cdtm instance
* @param[out]   None
* @return       uint8
* @retval       Cdtm instance
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Dtm_PriGetCdtmIndex(Cdtm_DtmIndexType CdtmDtmIndex)
{
    return ((CdtmDtmIndex / (CDTM0_DTM5+1))  & 0xF);
}

/**
* @brief        Gtm_Hw_Dtm_PrinGetDtmIndex
* @details      Gets the Cdtm's dtm instance number.
* @param[in]    CdtmDtmChIndex:    Cdtm instance
* @param[out]   None
* @return       uint8
* @retval       Dtm instance
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Dtm_PrinGetDtmIndex(Cdtm_DtmIndexType CdtmDtmIndex)
{
    return (CdtmDtmIndex % (CDTM0_DTM5+1));
}

/**
* @brief        Gtm_Hw_Dtm_PriGetCdtmIndexFromCh
* @details      Gets the Cdtm's dtm instance number .
* @param[in]    CdtmDtmChIndex:    Cdtm instance
* @param[out]   None
* @return       uint8
* @retval       Dtm's channnel instance
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Dtm_PriGetCdtmIndexFromCh(Cdtm_DtmChannelIndexType CdtmDtmChIndex)
{
    return (CdtmDtmChIndex  / (CDTM0_DTM5_CH3+1));
}

/**
* @brief        Gtm_Hw_Dtm_PriGetChannelIndex
* @details      Gets the Cdtm's dtm instance number .
* @param[in]    CdtmDtmChIndex:    Cdtm instance
* @param[out]   None
* @return       uint8
* @retval       Dtm's channnel instance
* @pre
*/
LOCAL_INLINE uint8 Gtm_Hw_Dtm_PriGetChannelIndex(Cdtm_DtmChannelIndexType CdtmDtmChIndex)
{
    return (CdtmDtmChIndex  % (CDTM0_DTM0_CH3+1));
}


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
TT_RetType Gtm_Hw_Dtm_Init(void);

/**
* @brief        Gtm_Hw_Dtm_Start
* @details      Start DTM channels.
* @param[in]    CdtmDtmChIndex : GTM DTM Index
* @param[out]   None
* @return       TT_RetType
* @retval       TT_RET_SUCCESS - success
*               Others - fail
* @pre
*/
TT_RetType Gtm_Hw_Dtm_Start(Cdtm_DtmIndexType CdtmDtmIndex);

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
TT_RetType Gtm_Hw_Dtm_Stop(Cdtm_DtmIndexType CdtmDtmIndex);

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
                                              uint16 RiseEdgeTime, uint16 FallEdgeTime);

#endif /* ALIOTH_GTM_USE_DTM */

#ifdef __cplusplus
}
#endif

#endif /* _GTM_DTM_H_ */
/** @} */
