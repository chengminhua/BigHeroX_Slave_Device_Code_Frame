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
**  FILENAME     : Gtm_Hw_Base.h                                              **
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
#ifndef GTM_HW_BASE_H
#define GTM_HW_BASE_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gtm_Drv_Cfg.h"
#include "Gtm_Hw_Bf.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GTM_HW_BASE_VENDOR_ID_H                      1541
#define GTM_HW_BASE_MODULE_ID_H                      221
#define GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H       4
#define GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H       4
#define GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H       0
#define GTM_HW_BASE_SW_MAJOR_VERSION_H               1
#define GTM_HW_BASE_SW_MINOR_VERSION_H               1
#define GTM_HW_BASE_SW_PATCH_VERSION_H               0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gtm_Hw_Bf.h Gtm_Base.h file version check */
#if (GTM_HW_BF_VENDOR_ID_H != GTM_HW_BASE_VENDOR_ID_H)
    #error "Gtm_Hw_Bf.h and Gtm_Base.h have different vendor ids"
#endif

#if (GTM_HW_BF_MODULE_ID_H != GTM_HW_BASE_MODULE_ID_H)
    #error "Gtm_Hw_Bf.h and Gtm_Base.h have different module ids"
#endif

#if ((GTM_HW_BF_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_HW_BF_AR_RELEASE_MINOR_VERSION_H != GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_HW_BF_AR_RELEASE_PATCH_VERSION_H != GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Hw_Bf.h and Gtm_Base.h are different"
#endif

#if ((GTM_HW_BF_SW_MAJOR_VERSION_H != GTM_HW_BASE_SW_MAJOR_VERSION_H) || \
     (GTM_HW_BF_SW_MINOR_VERSION_H != GTM_HW_BASE_SW_MINOR_VERSION_H) || \
     (GTM_BF_SW_PATCH_VERSION_H != GTM_HW_BASE_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Hw_Bf.h and Gtm_Base.h are different"
#endif

/* Gtm_Drv_Cfg.h Gtm_Base.h file version check */
#if (GTM_DRV_CFG_VENDOR_ID_H != GTM_HW_BASE_VENDOR_ID_H)
    #error "Gtm_Drv_Cfg.h and Gtm_Base.h have different vendor ids"
#endif

#if (GTM_DRV_CFG_MODULE_ID_H != GTM_HW_BASE_MODULE_ID_H)
    #error "Gtm_Drv_Cfg.h and Gtm_Base.h have different module ids"
#endif

#if ((GTM_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H != GTM_HW_BASE_AR_RELEASE_MAJOR_VERSION_H) || \
     (GTM_DRV_CFG_AR_RELEASE_MINOR_VERSION_H != GTM_HW_BASE_AR_RELEASE_MINOR_VERSION_H) || \
     (GTM_DRV_CFG_AR_RELEASE_PATCH_VERSION_H != GTM_HW_BASE_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gtm_Drv_Cfg.h and Gtm_Base.h are different"
#endif

#if ((GTM_DRV_CFG_SW_MAJOR_VERSION_H != GTM_HW_BASE_SW_MAJOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_MINOR_VERSION_H != GTM_HW_BASE_SW_MINOR_VERSION_H) || \
     (GTM_DRV_CFG_SW_PATCH_VERSION_H != GTM_HW_BASE_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gtm_Drv_Cfg.h and Gtm_Base.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/**
* @brief        GTM_REG_CHECK
* @details      Register read back check (using the existing Ret variable, you need to define the Ret variable first).
* @param[in]    value          : Register value
* @param[in]    expected_value : Expected register value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define GTM_REG_CHECK(value, expected_value) \
    TT_ParaCheck((uint32)(value) != (uint32)(expected_value), TT_RET_OPT_REG_ERR, &Ret)

/**
* @brief        GTM_REG_CHECK_RET_PTR
* @details      Register read back check (using the existing Ret poniter, you need to define the Ret poniter first).
* @param[in]    value          : Register value
* @param[in]    expected_value : Expected register value
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define GTM_REG_CHECK_RET_PTR(value, expected_value) \
    TT_ParaCheck((value) != (expected_value), TT_RET_OPT_REG_ERR, Ret)

/**
* @brief        GTM_DATA_RANGE_CHECK
* @details      Data range judgment.
* @param[in]    Eexpression : Expression for range comparison
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define GTM_DATA_RANGE_CHECK(Eexpression) \
    TT_ParaCheck((Eexpression), TT_RET_PARAM_INVALID_DATA_ERR, &Ret)

/**
* @brief        GTM_GET_EN_READ_VAL
* @details      Get register enables reading and writing inconsistent bits.
* @param[in]    data : The contents of the register are written
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define GTM_GET_EN_READ_VAL(data)     (((data) == 2)? 3 : 0)

/**
* @brief        GTM_REG_READ_2_WRITE
* @details      Write register operation(clear and write values at the same time).
* @param[in]    reg  : Register address.
* @param[in]    val  : The value to be written.
* @param[in]    mask : Write bit-width mask.
* @param[in]    bit  : Write bit.
* @param[out]   None
* @return       None
* @retval       None
* @pre
*/
#define GTM_REG_READ_2_WRITE(reg, val, mask, bit)\
    (reg) = \
       ((reg) & ~((mask) << (bit)))\
    | (((val) & (mask)) << (bit))\

#define GTM_DBG(fmt, ...) \
    printf("file[%s]line[%d]func[%s]\r\n"fmt"\r\n", \
            __FILE__, __LINE__,  __func__, __VA_ARGS__)

/**
 * @brief   GTM module types TAGs
 *
 * @{
 */
#define GTM_TAG                             GTM_bf_type
#define GTM_CFG_TAG                         GTM_CFG_bf_type
#define GTM_TBU_TAG                         GTM_TBU_bf_type
#define GTM_MON_TAG                         GTM_MON_bf_type
#define GTM_CMP_TAG                         GTM_CMP_bf_type
#define GTM_ARU_TAG                         GTM_ARU_bf_type
#define GTM_CMU_TAG                         GTM_CMU_bf_type
#define GTM_ICM_TAG                         GTM_ICM_bf_type
#define GTM_SPE_TAG                         GTM_SPE_bf_type
#define GTM_MAP_TAG                         GTM_MAP_bf_type
#define GTM_MCFG_TAG                        GTM_MCFG_bf_type
#define GTM_TIM_TAG                         GTM_TIM_bf_type
#define GTM_TOM_TAG                         GTM_TOM_bf_type
#define GTM_ATOM_TAG                        GTM_ATOM_bf_type
#define GTM_F2A_TAG                         GTM_PSM_F2A_bf_type
#define GTM_AFD_TAG                         GTM_PSM_AFD_bf_type
#define GTM_FIFO_TAG                        GTM_PSM_FIFO_bf_type
#define GTM_DPLL_TAG                        GTM_DPLL_bf_type
#define GTM_MCS_TAG                         GTM_MCS_bf_type
#define GTM_DTM_TAG                         GTM_CDTM_DTM_bf_type
#define GTM_BRC_TAG                         GTM_BRC_bf_type
#define GTM_CCM_TAG                         GTM_CCM_bf_type

/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Public Function Declaration
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* ALIOTH_GTM_BASE_H */
