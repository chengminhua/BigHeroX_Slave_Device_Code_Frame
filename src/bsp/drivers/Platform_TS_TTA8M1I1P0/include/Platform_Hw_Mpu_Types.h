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
**  FILENAME     : Platform_Hw_Mpu_Types.h                                    **
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
#ifndef PLATFORM_HW_MPU_TYPES_H
#define PLATFORM_HW_MPU_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Mpu_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_HW_MPU_TYPES_VENDOR_ID_H                     1541
#define PLATFORM_HW_MPU_TYPES_MODULE_ID_H                     219
#define PLATFORM_HW_MPU_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define PLATFORM_HW_MPU_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define PLATFORM_HW_MPU_TYPES_AR_RELEASE_PATCH_VERSION_H      0
#define PLATFORM_HW_MPU_TYPES_SW_MAJOR_VERSION_H              1
#define PLATFORM_HW_MPU_TYPES_SW_MINOR_VERSION_H              1
#define PLATFORM_HW_MPU_TYPES_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Hw_Mpu_Types.h and Base_TT_Cfg.h file version check */
#if (PLATFORM_HW_MPU_TYPES_VENDOR_ID_H != PLATFORM_MPU_CFG_VENDOR_ID_H)
    #error "Platform_Hw_Mpu_Types.h and Platform_Mpu_Cfg.h have different vendor id"
#endif
#if (PLATFORM_HW_MPU_TYPES_MODULE_ID_H != PLATFORM_MPU_CFG_MODULE_ID_H)
    #error "Platform_Hw_Mpu_Types.h and Platform_Mpu_Cfg.h have different module id"
#endif
#if ((PLATFORM_HW_MPU_TYPES_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_MPU_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MPU_TYPES_AR_RELEASE_MINOR_VERSION_H != PLATFORM_MPU_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_HW_MPU_TYPES_AR_RELEASE_PATCH_VERSION_H != PLATFORM_MPU_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Hw_Mpu_Types.h and Platform_Mpu_Cfg.h are different"
#endif
#if ((PLATFORM_HW_MPU_TYPES_SW_MAJOR_VERSION_H != PLATFORM_MPU_CFG_SW_MAJOR_VERSION_H) || \
     (PLATFORM_HW_MPU_TYPES_SW_MINOR_VERSION_H != PLATFORM_MPU_CFG_SW_MINOR_VERSION_H) || \
     (PLATFORM_HW_MPU_TYPES_SW_PATCH_VERSION_H != PLATFORM_MPU_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Hw_Mpu_Types.h and Platform_Mpu_Cfg.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define TT_MPU_REGION_SIZE_32B      ((uint8)0x04U) /* MPU Region Size 32 Bytes    */
#define TT_MPU_REGION_SIZE_64B      ((uint8)0x05U) /* MPU Region Size 64 Bytes    */
#define TT_MPU_REGION_SIZE_128B     ((uint8)0x06U) /* MPU Region Size 128 Bytes   */
#define TT_MPU_REGION_SIZE_256B     ((uint8)0x07U) /* MPU Region Size 256 Bytes   */
#define TT_MPU_REGION_SIZE_512B     ((uint8)0x08U) /* MPU Region Size 512 Bytes   */
#define TT_MPU_REGION_SIZE_1KB      ((uint8)0x09U) /* MPU Region Size 1 KByte     */
#define TT_MPU_REGION_SIZE_2KB      ((uint8)0x0AU) /* MPU Region Size 2 KBytes    */
#define TT_MPU_REGION_SIZE_4KB      ((uint8)0x0BU) /* MPU Region Size 4 KBytes    */
#define TT_MPU_REGION_SIZE_8KB      ((uint8)0x0CU) /* MPU Region Size 8 KBytes    */
#define TT_MPU_REGION_SIZE_16KB     ((uint8)0x0DU) /* MPU Region Size 16 KBytes   */
#define TT_MPU_REGION_SIZE_32KB     ((uint8)0x0EU) /* MPU Region Size 32 KBytes   */
#define TT_MPU_REGION_SIZE_64KB     ((uint8)0x0FU) /* MPU Region Size 64 KBytes   */
#define TT_MPU_REGION_SIZE_128KB    ((uint8)0x10U) /* MPU Region Size 128 KBytes  */
#define TT_MPU_REGION_SIZE_256KB    ((uint8)0x11U) /* MPU Region Size 256 KBytes  */
#define TT_MPU_REGION_SIZE_512KB    ((uint8)0x12U) /* MPU Region Size 512 KBytes  */
#define TT_MPU_REGION_SIZE_1MB      ((uint8)0x13U) /* MPU Region Size 1 MByte     */
#define TT_MPU_REGION_SIZE_2MB      ((uint8)0x14U) /* MPU Region Size 2 MBytes    */
#define TT_MPU_REGION_SIZE_4MB      ((uint8)0x15U) /* MPU Region Size 4 MBytes    */
#define TT_MPU_REGION_SIZE_8MB      ((uint8)0x16U) /* MPU Region Size 8 MBytes    */
#define TT_MPU_REGION_SIZE_16MB     ((uint8)0x17U) /* MPU Region Size 16 MBytes   */
#define TT_MPU_REGION_SIZE_32MB     ((uint8)0x18U) /* MPU Region Size 32 MBytes   */
#define TT_MPU_REGION_SIZE_64MB     ((uint8)0x19U) /* MPU Region Size 64 MBytes   */
#define TT_MPU_REGION_SIZE_128MB    ((uint8)0x1AU) /* MPU Region Size 128 MBytes  */
#define TT_MPU_REGION_SIZE_256MB    ((uint8)0x1BU) /* MPU Region Size 256 MBytes  */
#define TT_MPU_REGION_SIZE_512MB    ((uint8)0x1CU) /* MPU Region Size 512 MBytes  */
#define TT_MPU_REGION_SIZE_1GB      ((uint8)0x1DU) /* MPU Region Size 1 GByte     */
#define TT_MPU_REGION_SIZE_2GB      ((uint8)0x1EU) /* MPU Region Size 2 GBytes    */
#define TT_MPU_REGION_SIZE_4GB      ((uint8)0x1FU) /* MPU Region Size 4 GBytes    */

/** MPU Region Base Address Register Value
*
* \param Region The region to be configured, number 0 to 15.
* \param BaseAddress The base address for the region.
*/
#define TT_MPU_RBAR(Region, BaseAddress) \
  (((BaseAddress) & TT_MPU_RBAR_ADDR_Msk) |  \
   ((Region) & TT_MPU_RBAR_REGION_Msk)    |  \
   (TT_MPU_RBAR_VALID_Msk))

/**
* MPU Memory Access Attributes
*
* \param TypeExtField      Type extension field, allows you to configure memory access type, for example strongly ordered, peripheral.
* \param IsShareable       Region is shareable between multiple bus masters.
* \param IsCacheable       Region is cacheable, i.e. its value may be kept in cache.
* \param IsBufferable      Region is bufferable, i.e. using write-back caching. Cacheable but non-bufferable regions use write-through policy.
*/
#define TT_MPU_ACCESS_(TypeExtField, IsShareable, IsCacheable, IsBufferable)   \
  ((((TypeExtField) << TT_MPU_RASR_TEX_Pos) & TT_MPU_RASR_TEX_Msk)                  | \
   (((IsShareable)  << TT_MPU_RASR_S_Pos)   & TT_MPU_RASR_S_Msk)                    | \
   (((IsCacheable)  << TT_MPU_RASR_C_Pos)   & TT_MPU_RASR_C_Msk)                    | \
   (((IsBufferable) << TT_MPU_RASR_B_Pos)   & TT_MPU_RASR_B_Msk))

/**
* MPU Region Attribute and Size Register Value
*
* \param DisableExec       Instruction access disable bit, 1= disable instruction fetches.
* \param AccessPermission  Data access permissions, allows you to configure read/write access for User and Privileged mode.
* \param AccessAttributes  Memory access attribution, see \ref MPU_ACCESS_.
* \param SubRegionDisable  Sub-region disable field.
* \param Size              Region size of the region to be configured, for example 4K, 8K.
*/
#define TT_MPU_RASR_EX(DisableExec, AccessPermission, AccessAttributes, SubRegionDisable, Size)    \
  ((((DisableExec)      << TT_MPU_RASR_XN_Pos)   & TT_MPU_RASR_XN_Msk)                                  | \
   (((AccessPermission) << TT_MPU_RASR_AP_Pos)   & TT_MPU_RASR_AP_Msk)                                  | \
   (((AccessAttributes) & (TT_MPU_RASR_TEX_Msk | TT_ MPU_RASR_S_Msk | TT_MPU_RASR_C_Msk | TT_MPU_RASR_B_Msk))) | \
   (((SubRegionDisable) << TT_MPU_RASR_SRD_Pos)  & TT_MPU_RASR_SRD_Msk)                                 | \
   (((Size)             << TT_MPU_RASR_SIZE_Pos) & TT_MPU_RASR_SIZE_Msk)                                | \
   (((TT_MPU_RASR_ENABLE_Msk))))

/**
* MPU Region Attribute and Size Register Value
*
* \param DisableExec       Instruction access disable bit, 1= disable instruction fetches.
* \param AccessPermission  Data access permissions, allows you to configure read/write access for User and Privileged mode.
* \param TypeExtField      Type extension field, allows you to configure memory access type, for example strongly ordered, peripheral.
* \param IsShareable       Region is shareable between multiple bus masters.
* \param IsCacheable       Region is cacheable, i.e. its value may be kept in cache.
* \param IsBufferable      Region is bufferable, i.e. using write-back caching. Cacheable but non-bufferable regions use write-through policy.
* \param SubRegionDisable  Sub-region disable field.
* \param Size              Region size of the region to be configured, for example 4K, 8K.
*/
#define TT_MPU_RASR(DisableExec, AccessPermission, TypeExtField, IsShareable, IsCacheable, IsBufferable, SubRegionDisable, Size) \
        TT_MPU_RASR_EX(DisableExec, AccessPermission, TT_MPU_ACCESS_(TypeExtField, IsShareable, IsCacheable, IsBufferable), SubRegionDisable, Size)

/**
* MPU Memory Access Attribute for strongly ordered memory.
*  - TEX: 000b
*  - Shareable
*  - Non-cacheable
*  - Non-bufferable
*/
#define TT_MPU_ACCESS_ORDERED TT_MPU_ACCESS_(0U, 1U, 0U, 0U)

/**
* MPU Memory Access Attribute for device memory.
*  - TEX: 000b (if shareable) or 010b (if non-shareable)
*  - Shareable or non-shareable
*  - Non-cacheable
*  - Bufferable (if shareable) or non-bufferable (if non-shareable)
*
* \param IsShareable Configures the device memory as shareable or non-shareable.
*/
#define TT_MPU_ACCESS_DEVICE(IsShareable) ((IsShareable) ? TT_MPU_ACCESS_(0U, 1U, 0U, 1U) : TT_MPU_ACCESS_(2U, 0U, 0U, 0U))

/**
* MPU Memory Access Attribute for normal memory.
*  - TEX: 1BBb (reflecting outer cacheability rules)
*  - Shareable or non-shareable
*  - Cacheable or non-cacheable (reflecting inner cacheability rules)
*  - Bufferable or non-bufferable (reflecting inner cacheability rules)
*
* \param OuterCp Configures the outer cache policy.
* \param InnerCp Configures the inner cache policy.
* \param IsShareable Configures the memory as shareable or non-shareable.
*/
#define TT_MPU_ACCESS_NORMAL(OuterCp, InnerCp, IsShareable) TT_MPU_ACCESS_((4U | (OuterCp)), IsShareable, ((InnerCp) >> 1U), ((InnerCp) & 1U))

/**
* MPU Memory Access Attribute non-cacheable policy.
*/
#define TT_MPU_CACHEP_NOCACHE (0U)

/**
* MPU Memory Access Attribute write-back, write and read allocate policy.
*/
#define TT_MPU_CACHEP_WB_WRA  (1U)

/**
* MPU Memory Access Attribute write-through, no write allocate policy.
*/
#define TT_MPU_CACHEP_WT_NWA  (2U)

/**
* MPU Memory Access Attribute write-back, no write allocate policy.
*/
#define TT_MPU_CACHEP_WB_NWA  (3U)

#define  TT_MPU_REGION_ENABLE           ((uint8)0x01)   /*!< Region enable  */
#define  TT_MPU_REGION_DISABLE          ((uint8)0x00)   /*!< Region disable  */

/** @defgroup CORTEX_MPU_Region_Permission_Attributes CORTEX MPU Region Permission Attributes
  * @{
  */
#define  TT_MPU_REGION_NO_ACCESS        ((uint8)0x00)
#define  TT_MPU_REGION_PRIV_RW          ((uint8)0x01)
#define  TT_MPU_REGION_PRIV_RW_URO      ((uint8)0x02)
#define  TT_MPU_REGION_FULL_ACCESS      ((uint8)0x03)
#define  TT_MPU_REGION_PRIV_RO          ((uint8)0x05)
#define  TT_MPU_REGION_PRIV_RO_URO      ((uint8)0x06)

/** @defgroup CORTEX_MPU_Access_Bufferable CORTEX MPU Instruction Access Bufferable
  * @{
  */
#define  TT_MPU_ACCESS_BUFFERABLE        ((uint8)0x01)
#define  TT_MPU_ACCESS_NOT_BUFFERABLE    ((uint8)0x00)

/** @defgroup CORTEX_MPU_Access_Shareable CORTEX MPU Instruction Access Shareable
  * @{
  */
#define  TT_MPU_ACCESS_SHAREABLE         ((uint8)0x01)
#define  TT_MPU_ACCESS_NOT_SHAREABLE     ((uint8)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Number CORTEX MPU Region Number
  * @{
  */
#define  TT_MPU_REGION_NUMBER0          ((uint8)0x00)
#define  TT_MPU_REGION_NUMBER1          ((uint8)0x01)
#define  TT_MPU_REGION_NUMBER2          ((uint8)0x02)
#define  TT_MPU_REGION_NUMBER3          ((uint8)0x03)
#define  TT_MPU_REGION_NUMBER4          ((uint8)0x04)
#define  TT_MPU_REGION_NUMBER5          ((uint8)0x05)
#define  TT_MPU_REGION_NUMBER6          ((uint8)0x06)
#define  TT_MPU_REGION_NUMBER7          ((uint8)0x07)
#define  TT_MPU_REGION_NUMBER8          ((uint8)0x08)
#define  TT_MPU_REGION_NUMBER9          ((uint8)0x09)
#define  TT_MPU_REGION_NUMBER10         ((uint8)0x0A)
#define  TT_MPU_REGION_NUMBER11         ((uint8)0x0B)
#define  TT_MPU_REGION_NUMBER12         ((uint8)0x0C)
#define  TT_MPU_REGION_NUMBER13         ((uint8)0x0D)
#define  TT_MPU_REGION_NUMBER14         ((uint8)0x0E)
#define  TT_MPU_REGION_NUMBER15         ((uint8)0x0F)

/** @defgroup CORTEX_MPU_TEX_Levels MPU TEX Levels
  * @{
  */
#define  TT_MPU_TEX_LEVEL0              ((uint8)0x00)
#define  TT_MPU_TEX_LEVEL1              ((uint8)0x01)
#define  TT_MPU_TEX_LEVEL2              ((uint8)0x02)

/** @defgroup CORTEX_MPU_Access_Cacheable CORTEX MPU Instruction Access Cacheable
  * @{
  */
#define  TT_MPU_ACCESS_CACHEABLE        ((uint8)0x01)
#define  TT_MPU_ACCESS_NOT_CACHEABLE    ((uint8)0x00)

/** @defgroup CORTEX_MPU_Instruction_Access CORTEX MPU Instruction Access
  * @{
  */
#define  TT_MPU_INSTRUCTION_ACCESS_ENABLE       ((uint8)0x00)
#define  TT_MPU_INSTRUCTION_ACCESS_DISABLE      ((uint8)0x01)

/* Mpu Region enable Assert */
#define IS_NOT_MPU_REGION_ENABLE(STATE)               ((STATE) > TT_MPU_REGION_ENABLE)

/* Mpu Instruction Access Assert */
#define IS_NOT_MPU_INSTRUCTION_ACCESS(STATE)          ((STATE) > TT_MPU_INSTRUCTION_ACCESS_DISABLE)

/* Mpu Access Shareable Assert */
#define IS_NOT_MPU_ACCESS_SHAREABLE(STATE)            ((STATE) > TT_MPU_ACCESS_SHAREABLE)

/* Mpu Access Cacheable Assert */
#define IS_NOT_MPU_ACCESS_CACHEABLE(STATE)            ((STATE) > TT_MPU_ACCESS_CACHEABLE)

/* Mpu Access Bufferable Assert */
#define IS_NOT_MPU_ACCESS_BUFFERABLE(STATE)           ((STATE) > TT_MPU_ACCESS_BUFFERABLE)

/* Mpu Tex Level Assert */
#define IS_NOT_MPU_TEX_LEVEL(TYPE)                    ((TYPE) > TT_MPU_TEX_LEVEL2)

/* Mpu Region Permission Attribute Assert */
#define IS_NOT_MPU_REGION_PERMISSION_ATTRIBUTE(TYPE)  ((TYPE) > TT_MPU_REGION_PRIV_RO_URO)

/* Mpu Region Number Assert */
#define IS_NOT_MPU_REGION_NUMBER(NUMBER)     ((NUMBER) > TT_MPU_REGION_NUMBER15)

/* Mpu Region Size Assert */
#define IS_NOT_MPU_REGION_SIZE(SIZE)    (((SIZE) < TT_MPU_REGION_SIZE_32B)  || \
                                    ((SIZE) > TT_MPU_REGION_SIZE_4GB))

/* Mpu Region Access Assert */
#define IS_MPU_REGION_ACCESS_RIGHTS(RIGHT)  (((RIGHT) == TT_MPU_PRIV_UNPRIV_NONE)        || \
                                             ((RIGHT) == TT_MPU_PRIV_RW_UNPRIV_NONE)     || \
                                             ((RIGHT) == TT_MPU_PRIV_RWX_UNPRIV_NONE)    || \
                                             ((RIGHT) == TT_MPU_PRIV_RW_UNPRIV_R)        || \
                                             ((RIGHT) == TT_MPU_PRIV_RWX_UNPRIV_RX)      || \
                                             ((RIGHT) == TT_MPU_PRIV_RW_UNPRIV_RW)       || \
                                             ((RIGHT) == TT_MPU_PRIV_RWX_UNPRIV_RWX)     || \
                                             ((RIGHT) == TT_MPU_PRIV_R_UNPRIV_NONE)      || \
                                             ((RIGHT) == TT_MPU_PRIV_RX_UNPRIV_NONE)     || \
                                             ((RIGHT) == TT_MPU_PRIV_R_UNPRIV_R)         || \
                                             ((RIGHT) == TT_MPU_PRIV_RX_UNPRIV_RX))

/* Mpu SubRegion Disable Assert */
#define IS_MPU_SUB_REGION_DISABLE(SUBREGION)  ((SUBREGION) < (uint16_t)0x00FF)

/******************************************************************************
*                            Enums
*******************************************************************************/
/**
* @brief          Enumeration listing the outer and inner cache policies when RASR[TEX] == 0x1XX
*/
/* @implements     Mpu_M7_Ip_CachePolicyType_enum */
typedef enum
{
    TT_MPU_CACHE_POLICY_NO_CACHE                = 0UL,  /*!< Non-cacheable */
    TT_MPU_CACHE_POLICY_W_BACK_WR_ALLOCATE      = 1UL,  /*!< Write-back, write and read allocate */
    TT_MPU_CACHE_POLICY_W_THROUGH_NO_W_ALLOCATE = 2UL,  /*!< Write-through, no write allocate */
    TT_MPU_CACHE_POLICY_W_BACK_NO_W_ALLOCATE    = 3UL   /*!< Write-back, no write allocate */
} Platform_Hw_MpuCachePolicyType;

/**
* @brief          Enumeration listing the memory and cache attributes when RASR[TEX] == 0x0XX
*/
/* @implements    Mpu_M7_Ip_MemoryType_enum */
typedef enum
{
    TT_MPU_MEM_STRONG_ORDER                 = 0U,  /*!< Strongly ordered */
    TT_MPU_MEM_DEVICE_SHARED                = 1U,  /*!< Shared device */
    TT_MPU_MEM_NORMAL_IO_WR_THROUGH         = 2U,  /*!< Outer and inner write-through, no write allocate */
    TT_MPU_MEM_NORMAL_IO_WR_BACK1           = 3U,  /*!< Outer and inner write-back, no write allocate */
    TT_MPU_MEM_NORMAL_IO_NO_CACHE           = 4U,  /*!< Outer and inner Non-cacheable */
    TT_MPU_MEM_NORMAL_IO_WR_BACK2           = 5U,  /*!< Outer and inner write-back; write and read allocate */
    TT_MPU_MEM_DEVICE_NOSHARE               = 6U,  /*!< Non-shared device */
    TT_MPU_MEM_NORMAL_CACHEABLE             = 7U,  /*!< Normal Memory Cache policy enabled */
    TT_MPU_MEM_NO
} Platform_Hw_MpuMemoryType;


/**
* @brief          Enumeration listing access permisions
*/
/* @implements    Mpu_M7_Ip_AccessRightsType_enum */
typedef enum
{
    /* Format: X_R_APP
     * X  = 1 bit : Execute Allow or not
     * R  = 1 bit : Reserved
     *APP = 3 bit : Define Privileged & Uprivileged Access Right
     */
    TT_MPU_PRIV_UNPRIV_NONE        = 0x00U,    /*!< 0b00000000U : ---|--- */
    TT_MPU_PRIV_RW_UNPRIV_NONE     = 0x01U,    /*!< 0b00000001U : rw-|--- */
    TT_MPU_PRIV_RWX_UNPRIV_NONE    = 0x11U,    /*!< 0b00010001U : rwx|--- */
    TT_MPU_PRIV_RW_UNPRIV_R        = 0x02U,    /*!< 0b00000010U : rw-|r-- */
    TT_MPU_PRIV_RWX_UNPRIV_RX      = 0x12U,    /*!< 0b00010010U : rwx|r-x */
    TT_MPU_PRIV_RW_UNPRIV_RW       = 0x03U,    /*!< 0b00000011U : rw-|rw- */
    TT_MPU_PRIV_RWX_UNPRIV_RWX     = 0x13U,    /*!< 0b00010011U : rwx|rwx */
    TT_MPU_PRIV_R_UNPRIV_NONE      = 0x05U,    /*!< 0b00000101U : r--|--- */
    TT_MPU_PRIV_RX_UNPRIV_NONE     = 0x15U,    /*!< 0b00010101U : r-x|--- */
    TT_MPU_PRIV_R_UNPRIV_R         = 0x06U,    /*!< 0b00000110U : r--|r-- */
    TT_MPU_PRIV_RX_UNPRIV_RX       = 0x16U     /*!< 0b00010110U : r-x|r-x */
} Platform_Hw_MpuAccessRightsType;

/**
* @brief          Enumeration listing the possible access errors
*/
/* @implements    Mpu_M7_Ip_ErrorType_enum */
typedef enum
{
    TT_MPU_MEMMAN_ERROR_INSTRUCTION_ACCESS,  /*! IACCVIOL  Instruction access violation */
    TT_MPU_MEMMAN_ERROR_DATA_ACCESS,         /*! DACCVIOL  Data access violation */
    TT_MPU_MEMMAN_ERROR_STACK,               /*! MUNSTKERR MemManage fault on unstacking for a return from exception */
    TT_MPU_MEMMAN_ERROR_UNSTACK,             /*! MSTKERR   MemManage fault on stacking for exception entry*/
    TT_MPU_MEMMAN_ERROR_FLOATING_POINT,      /*! MLSPERR   MemManage fault during floating point lazy state preservation*/
    TT_MPU_MEMMAN_ERROR_MULTIPLE,            /*! MemManage fault Multiple Errors detected */
    TT_MPU_MEMMAN_ERROR_NONE
} Platform_Hw_MpuErrorType;
/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/**
* Struct for a single MPU Region
*/
typedef struct {
  uint32 RBAR; //!< The region base address register value (RBAR)
  uint32 RASR; //!< The region attribute and size register value (RASR) \ref MPU_RASR
} MPU_Region_t;


/**
* @brief          Configuration structure containing the region configuration
*/
/* @implements    Mpu_M7_Ip_RegionConfigType_struct */
typedef struct
{
    uint8                               RegionNum;           /*!< Region number                    */
    uint32                              StartAddr;           /*!< Memory region start address      */
    uint32                              EndAddr;             /*!< Memory region end address        */
    Platform_Hw_MpuMemoryType           MemType;             /*!< Memory Type for region           */
    Platform_Hw_MpuAccessRightsType     AccessRight;         /*!< Access permission for region     */
    Platform_Hw_MpuCachePolicyType      OuterCachePolicy;    /*!< Outer Cache Policy               */
    Platform_Hw_MpuCachePolicyType      InnerCachePolicy;    /*!< Inner Cache Policy               */
    uint8                               SubRegMask;          /*!< SubRegion Disable Mask           */
    boolean                             Shareable;           /*!< Enables or disables shareability */
} Platform_Hw_MpuRegionConfigType;

/**
* @brief          IP configuration structure
*/
/* @implements     Mpu_M7_Ip_ConfigType_struct */
typedef struct
{
    boolean     DefaultMapEn;                                           /*!< Enables the default memory map background region */
    boolean     EnableRunHFNMI;                                         /*!< Enables use of the MPU when in the hard fault, non-maskable interrupt, and FAULTMASK escalated handlers  */
    boolean     EnMemManageInterrupt;                                   /*!< Enable Memory Manage Fault Exception Handler */
    uint8       RegionCnt;                                              /*!< Region Count */
    TT_CONST Platform_Hw_MpuRegionConfigType * RegionConfigArr;         /*!< Region configuration array */
} Platform_Hw_MpuConfigType;

/**
* @brief          Structure used to retrieve violation details
*/
/* @implements     Mpu_M7_Ip_ErrorDetailsType_struct */
typedef struct
{
    uint32 u32Address;               /*!< Violation address */
    Platform_Hw_MpuErrorType eType;  /*!< Type of violation */
} Platform_Hw_MpuErrorDetailsType;

typedef struct
{
  uint8                Enable;                /*!< Specifies the status of the region.
                                                     This parameter can be a value of @ref CORTEX_MPU_Region_Enable                 */
  uint8                Number;                /*!< Specifies the number of the region to protect.
                                                     This parameter can be a value of @ref CORTEX_MPU_Region_Number                 */
  uint32               BaseAddress;           /*!< Specifies the base address of the region to protect.                             */
  uint8                Size;                  /*!< Specifies the size of the region to protect.
                                                     This parameter can be a value of @ref CORTEX_MPU_Region_Size                   */
  uint8                SubRegionDisable;      /*!< Specifies the number of the subregion protection to disable.
                                                     This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF    */
  uint8                TypeExtField;          /*!< Specifies the TEX field level.
                                                     This parameter can be a value of @ref CORTEX_MPU_TEX_Levels                    */
  uint8                AccessPermission;      /*!< Specifies the region access permission type.
                                                     This parameter can be a value of @ref CORTEX_MPU_Region_Permission_Attributes  */
  uint8                DisableExec;           /*!< Specifies the instruction access status.
                                                     This parameter can be a value of @ref CORTEX_MPU_Instruction_Access            */
  uint8                IsShareable;           /*!< Specifies the shareability status of the protected region.
                                                     This parameter can be a value of @ref CORTEX_MPU_Access_Shareable              */
  uint8                IsCacheable;           /*!< Specifies the cacheable status of the region protected.
                                                     This parameter can be a value of @ref CORTEX_MPU_Access_Cacheable              */
  uint8                IsBufferable;          /*!< Specifies the bufferable status of the protected region.
                                                     This parameter can be a value of @ref CORTEX_MPU_Access_Bufferable             */
}Platform_Hw_MpuRegionInitTypeDef;
/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 

/** @brief    Declaration of the configuration structure for Mpu */
extern TT_CONST Platform_Hw_MpuConfigType PlatformMpu_ConfigData;

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h" 
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/

/******************************************************************************
*                            Private Functions
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_HW_MPU_TYPES_H */
