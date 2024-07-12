/*************************************************************************************
**                                                                                  **
** Copyright (c) ThinkTech Technologies (2023)                                      **
**                                                                                  **
** All rights reserved.                                                             **
**                                                                                  **
** This document contains proprietary information beloging to ThinkTech             **
** Technologies. Passing on and copying of this document, and communication         **
** of its contents is not permitted without prior written authorization.            **
**                                                                                  **
**************************************************************************************
**                                                                                  **
**  FILENAME     : I2c_Hw_Types.h                                                   **
**                                                                                  **
**  VERSION      : 1.1.0                                                            **
**                                                                                  **
**  PLATFORM     : ThinkTech Alioth Series                                          **
**                                                                                  **
**  VENDOR       : ThinkTech Technologies                                           **
**                                                                                  **
**  DESCRIPTION  : I2C Driver Source File                                           **
**                                                                                  **
**  MAY BE CHANGED BY USER : No                                                     **
**                                                                                  **
*************************************************************************************/
/*************************************************************************************
*                           History                                                 **
*[V1.1.0]:                                                                          **
*************************************************************************************/
#ifndef I2C_HW_TYPES_H
#define I2C_HW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "I2c_Drv_Cfg.h"
/**************************************************************************************************
*                                 Source File Version Information
***************************************************************************************************/
#define I2C_HW_TYPES_VENDOR_ID_H                    1541
#define I2C_HW_TYPES_MODULE_ID_H                    222
#define I2C_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define I2C_HW_TYPES_AR_RELEASE_MINOR_VERSION_H     4
#define I2C_HW_TYPES_AR_RELEASE_PATCH_VERSION_H     0
#define I2C_HW_TYPES_SW_MAJOR_VERSION_H             1
#define I2C_HW_TYPES_SW_MINOR_VERSION_H             1
#define I2C_HW_TYPES_SW_PATCH_VERSION_H             0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* I2c_Hw_Types.h I2c_Drv_Cfg.h file version check */
#if (I2C_HW_TYPES_VENDOR_ID_H != I2C_DRV_CFG_VENDOR_ID_H)
    #error "I2c_Hw_Types.h and I2c_Drv_Cfg.h have different vendor ids"
#endif

#if (I2C_HW_TYPES_MODULE_ID_H != I2C_DRV_CFG_MODULE_ID_H)
    #error "I2c_Hw_Types.h and I2c_Drv_Cfg.h have different module ids"
#endif

#if ((I2C_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != I2C_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (I2C_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != I2C_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (I2C_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != I2C_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of I2c_Hw_Types.h and I2c_Drv_Cfg.h are different"
#endif

#if ((I2C_HW_TYPES_SW_MAJOR_VERSION_H != I2C_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (I2C_HW_TYPES_SW_MINOR_VERSION_H != I2C_DRV_CFG_SW_MINOR_VERSION_H) || \
     (I2C_HW_TYPES_SW_PATCH_VERSION_H != I2C_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of I2c_Hw_Types.h and I2c_Drv_Cfg.h are different"
#endif

/******************************************************************************
*                            Public Macros
*******************************************************************************/
/* High and low times in different speed modes (in ns) */
#define MIN_SS_SCL_HIGHTIME   (4000U)
#define MIN_SS_SCL_LOWTIME    (4700U)
#define MIN_FS_SCL_HIGHTIME   (600U)
#define MIN_FS_SCL_LOWTIME    (1300U)
#define MIN_HS_SCL_HIGHTIME   (60U)
#define MIN_HS_SCL_LOWTIME    (160U)

/* I2C Control Register Definitions */
#define IC_CON_SPD_SS         0x0002
#define IC_CON_SPD_FS         0x0004
#define IC_CON_SPD_HS         0x0006

/* I2C Event */
/* Master/Slave Transmit/Receive finished */
#define TT_I2C_EVENT_TRANSFER_DONE       (1UL << 0)
/* Master/Slave Transmit/Receive incomplete transfer */
#define TT_I2C_EVENT_TRANSFER_INCOMPLETE (1UL << 1)
/* Slave Transmit operation requested */
#define TT_I2C_EVENT_SLAVE_TRANSMIT      (1UL << 2)
/* Slave Receive operation requested */
#define TT_I2C_EVENT_SLAVE_RECEIVE       (1UL << 3)
/* Address not acknowledged from Slave */
#define TT_I2C_EVENT_ADDRESS_NACK        (1UL << 4)
/* Master lost arbitration */
#define TT_I2C_EVENT_ARBITRATION_LOST    (1UL << 5)
/* Bus error detected (START/STOP at illegal position) */
#define TT_I2C_EVENT_BUS_ERROR           (1UL << 6)
/* Bus clear finished */
#define TT_I2C_EVENT_BUS_CLEAR           (1UL << 7)


/* The maximum number of slave IP addresses */
#define I2C_HW_ADDER_MAX                 (uint8)0x7F

/* Time conversion */
#define NANO_TO_MICRO                    1000

/* illegal address */
#define HIGH_SPEED_MASTER_CODE_MIN       (uint8)0x4
#define HIGH_SPEED_MASTER_CODE_MAX       (uint8)0x7
#define SMBUS_HOST                       (uint8)0x8
#define RESERVED_ADDERSS_MIN             (uint8)0x78
#define RESERVED_ADDERSS_MAX             (uint8)0x7c
#define SMBUS_ALERT_RESPONSE_ADDERSS     (uint8)0xC
#define SMBUS_DEVICE_DEFAULT_ADDERSS     (uint8)0x61

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Public Typedefs
*******************************************************************************/
/**
* @brief         I2c Callback Event
* @details       Flag used to set the serial port callback function.
*/
typedef void (*TT_I2C_SignalEvent_t) (uint32 event);
   
/**
* @brief         I2C Status enum
* @details       Refer to the comments in the structure for details
*/
typedef enum _I2C_STATUS {
    /**!< I2c not yet initialized */
    TT_I2C_STATE_UNINIT,
    /**!< I2c initialized and ready use*/
    TT_I2C_STATE_IDLE,
    /**!< I2c internal process is ongoing */
    TT_I2C_STATE_BUSY,
    /**!< I2c data Transmission process is ongoing */
    TT_I2C_STATE_BUSY_TX,
    /**!< I2c data Reception process is ongoing */
    TT_I2C_STATE_BUSY_RX,
    /**!< I2c timeout state */
    TT_I2C_STATE_TIMEOUT,
    /**!< I2c Error state */
    TT_I2C_STATE_ERROR
} I2c_StatusType;


/**
* @brief         I2C Control Information Structure
* @details       Refer to the comments in the structure for details
*/
typedef struct
{
    /**!< Event callback */
  TT_I2C_SignalEvent_t      cb_event;
  /**!< Status flags */
  I2c_StatusType            status;
  /**!< Master/Slave address and RW bit */
  uint16                    addr;
  /**!<count */
  uint32                    cnt;
  /**!< Master NACK position */
  uint32                    nack;
  /**!< Master data to transfer */
  uint8*                    data;
  /**!< Number of bytes to transfer */
  uint32                    num;
  /**!< Number of bytes to transfer */
  uint32                    ncnt;
  /**!< Slave data to transfer */
  uint8*                    sdata;
  /**!< Number of bytes to transfer */
  uint32                    snum;
} I2c_CtrlType;

#if (I2C_DMA_ENABLE == STD_ON)
/**
* @brief         I2C DMA Configuration
* @details       Refer to the comments in the structure for details
*/
typedef struct _I2C_DMA {
/*  boolean I2CDmaModeEnable; */
  uint32 I2cDmaConfigId;
  /* DMA Event callback */
  TT_I2C_SignalEvent_t cb_event;
} I2c_DmaType;
#endif
/**
\brief I2C Communication Modem Control
*/
typedef enum _ARM_I2C_WORK_MODE {
  /*!< work in poll */
  TT_I2C_WORK_POLL,
  /*!< work in irq */
  TT_I2C_WORK_IRQ,
  /*!< work in dma */
  TT_I2C_WORK_DMA
} I2c_WorkModeType;


/**
* @brief         I2C Resource Configuration
* @details       Refer to the comments in the structure for details
*/
typedef struct
{
    /**!< I2C register interface */
  I2c_RegType*           reg;
  /**!< Run-Time control information */
  I2c_CtrlType*          ctrl;
  I2c_WorkModeType       work_mode;
#if (I2C_DMA_ENABLE == STD_ON)
  I2c_DmaType*           dma_tx;
  I2c_DmaType*           dma_rx;
#endif
  /**!< I2C clocks frequency */
  uint32                base_clk;
} I2C_ResourcesType;

/**
* @brief        Enum for speed the I2C operates
* @details      Refer to the comments in the structure for details
*/
typedef enum
{
    I2C_BUS_SPEED_STANDARD   = 0x01u,
    I2C_BUS_SPEED_FAST     = 0x02u,
    I2C_BUS_SPEED_HIGH       = 0X03U
}I2c_SpeedType;

/**
* @brief        Enum for mode the I2C operates
* @details      Refer to the comments in the structure for details
*/
typedef enum
{
  WORK_MODE_MASTER   = 0x00u ,
  WORK_MODE_SLAVE   = 0x01u
}I2c_WorkChannelType;

/**
* @brief        Enum for address mode the I2C operates
* @details      Refer to the comments in the structure for details
*/
typedef enum
{
  WORK_7BIT_ADDR     = 0x00u ,
  WORK_10BIT_ADDR   = 0x01u
}I2c_AddrModeType;

/**
* @brief        Cofiguration Structure for I2C
* @details      Refer to the comments in the structure for details
*/
typedef struct
{
  uint8               HwUnit;
  I2c_SpeedType       I2C_Speed;
  I2c_WorkChannelType I2C_WorkChannel;
  I2c_WorkModeType    I2C_WorkMode;
    /**!< I2C Adder */
  uint16          Address;
#if (I2C_DMA_ENABLE == STD_ON)
    uint32 I2cTxDmaConfigId;
    uint32 I2cRxDmaConfigId;
#endif
    /**!< Event callback  */
  TT_I2C_SignalEvent_t cb_event;
}I2c_CtrlConfigType;

/**
* @brief        Cofiguration Structure for I2C
* @details      Refer to the comments in the structure for details
*/
typedef struct
{
    TT_CONST I2c_CtrlConfigType* CtrlCfgPtr;
}I2c_ConfigType;



extern TT_CONST I2c_ConfigType I2C_CfgData;


#ifdef __cplusplus
}
#endif

#endif
