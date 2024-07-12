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
**  FILENAME     : Platform_Hw_Mpu.h                                          **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Platform Driver Source File                                **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef PLATFORM_HW_MPU_H
#define PLATFORM_HW_MPU_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Hw_Mpu_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_MPU_VENDOR_ID_H                     1541
#define PLATFORM_HW_MPU_MODULE_ID_H                     219
#define PLATFORM_HW_MPU_AR_RELEASE_MAJOR_VERSION_H      4
#define PLATFORM_HW_MPU_AR_RELEASE_MINOR_VERSION_H      4
#define PLATFORM_HW_MPU_AR_RELEASE_PATCH_VERSION_H      0
#define PLATFORM_HW_MPU_SW_MAJOR_VERSION_H              1
#define PLATFORM_HW_MPU_SW_MINOR_VERSION_H              1
#define PLATFORM_HW_MPU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_Mpu.h and Platform_Hw_Mpu_Types.h file version check */
#if (PLATFORM_HW_MPU_VENDOR_ID_H != PLATFORM_HW_MPU_TYPES_VENDOR_ID_H)
    #error "Platform_Hw_Mpu.h and Platform_Hw_Mpu_Types.h have different vendor id"
#endif
#if (PLATFORM_HW_MPU_MODULE_ID_H != PLATFORM_HW_MPU_TYPES_MODULE_ID_H)
    #error "Platform_Hw_Mpu.h and Platform_Hw_Mpu_Types.h have different module id"
#endif
#if ((PLATFORM_HW_MPU_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MPU_AR_RELEASE_MINOR_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_MPU_AR_RELEASE_PATCH_VERSION_H != PLATFORM_HW_MPU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_Mpu.h and Platform_Hw_Mpu_Types.h are different"
#endif
#if ((PLATFORM_HW_MPU_SW_MAJOR_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MPU_SW_MINOR_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_MPU_SW_PATCH_VERSION_H != PLATFORM_HW_MPU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_Mpu.h and Platform_Hw_Mpu_Types.h are different"
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
*                            Global Variable Declarations
*******************************************************************************/

/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
#define PLATFORM_START_SEC_CODE_SLOW
#include "Platform_MemMap.h"
/**
 * @brief       Initializes the Memory Protection Unit general parameters and
 *              region configurations.
 * @details     This function is non-reentrant.
 * @param[in]   pConfig  Pointer to configuration structure for MPU M7.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @api
 */
extern TT_RetType Platform_Hw_Mpu_Init(TT_CONST Platform_Hw_MpuConfigType * TT_CONST pConfig);

/**
 * @brief       Disables the module and resets all region configurations.
 * @details     This function is Reentrant.
 * @param       void
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
extern TT_RetType Platform_Hw_Mpu_Deinit(void);

#define PLATFORM_STOP_SEC_CODE_SLOW
#include "Platform_MemMap.h"

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/**
 * @brief       Get D region value.
 * @details     This function is non-reentrant.
 * @param[out]  RetVal  D region value.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @api
 */
extern TT_RetType Platform_Hw_Mpu_GetDRegion(uint8 * TT_CONST RetVal);

/**
 * @brief       Configures the region selected by u8RegionNum with the data from pUserConfigPtr.
 * @details     This function is Reentrant.
 * @param[in]   u8RegionNum  Region number.
 * @param[in]   pUserConfigPtr  Pointer to the region configuration structure for MPU M7.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
extern TT_RetType Platform_Hw_Mpu_SetRegionConfig(
    TT_CONST uint8 u8RegionNum,
    TT_CONST Platform_Hw_MpuRegionConfigType * TT_CONST pUserConfigPtr);


/**
 * @brief       Enables or disabled a specific region.
 * @details     This function is Reentrant.
 * @param[in]   u8RegionNum  Region to be modified.
 * @param[in]   bEnable  Specifies whether the region is enabled or disabled.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
extern TT_RetType Platform_Hw_Mpu_EnableRegion(TT_CONST uint8 u8RegionNum, TT_CONST boolean bEnable);

/**
 * @brief       Modify the access rights for a specific region.
 * @details     This function is Reentrant.
 * @param[in]   u8RegionNum  Region to be modified.
 * @param[in]   eRights  Specifies the new access rights.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
extern TT_RetType Platform_Hw_Mpu_SetAccessRight(
    TT_CONST uint8 u8RegionNum,
    TT_CONST Platform_Hw_MpuAccessRightsType eRights);

/**
 * @brief       Retrieve error details
 * @details     This function is Reentrant
 * @param[out]  pErrorDetails  Storage where the data will be saved.
 * @param[out]  RetVal
 * - \b         TRUE  If an error was present.
 * - \b         FALSE  Otherwise.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * @api
 */
extern TT_RetType Platform_Hw_Mpu_GetErrorDetails(Platform_Hw_MpuErrorDetailsType * TT_CONST pErrorDetails, boolean * TT_CONST RetVal);

/**
 * @brief       Enable the MPU.
 * @param       MPU_Control Default access permissions for unconfigured regions.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 * MPU_PRIVILEGED_DEFAULT
 */
extern TT_RetType Platform_Hw_Mpu_Enable(TT_CONST uint32 MPU_Control);

/**
 * @brief       Disable the MPU, must disable MPU first before config MPU.
 * @return      TT_RetType
 * @param       void
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_Mpu_Disable(void);

/**
 * @brief       Clear and disable the given MPU region.
 * @param[in]   rnr  Region number to be cleared.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_Mpu_ClrRegion(TT_CONST uint32 rnr);

/**
 * @brief       Configure an MPU region.
 * @param[in]   rbar  Value for RBAR register.
 * @param[in]   rasr  Value for RASR register.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_Mpu_SetRegion(TT_CONST uint32 rbar, TT_CONST uint32 rasr);

/**
 * @brief       Configure the given MPU region.
 * @param[in]   rnr  Region number to be configured.
 * @param[in]   rbar  Value for RBAR register.
 * @param[in]   rasr  Value for RASR register.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_Mpu_SetRegionEx(TT_CONST uint32 rnr, TT_CONST uint32 rbar, TT_CONST uint32 rasr);

/**
 * @brief       Load the given number of MPU regions from a table.
 * @param[in]   table  Pointer to the MPU configuration table.
 * @param[in]   cnt  Amount of regions to be configured.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_Mpu_Load(TT_CONST MPU_Region_t * TT_CONST table, TT_CONST uint32 cnt);

/**
 * @brief       Initializes and configures the Region and the memory to be protected.
 * @param[in]   MPU_Init  Pointer to a Platform_Hw_MpuRegionInitTypeDef structure that contains
 *                        the initialization and configuration information.
 * @return      TT_RetType
 * @retval      Status whether function executes successfully or causes faults.
 * @pre         MPU layer in Platform module must be initialized.
 */
extern TT_RetType Platform_Hw_Mpu_ConfigRegion(TT_CONST Platform_Hw_MpuRegionInitTypeDef * TT_CONST MPU_Init);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/******************************************************************************
*                            Private Functions
*******************************************************************************/
#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* PLATFORM_HW_MPU_H */
