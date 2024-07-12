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
**  FILENAME     : Base_Chips_Cfg.h                                           **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Base Driver Configuration Generated File                   **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef BASE_CHIP_CFG_H
#define BASE_CHIP_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_CHIPS_CFG_VENDOR_ID_H                     (1541U)
#define BASE_CHIPS_CFG_MODULE_ID_H                     (218U)
#define BASE_CHIPS_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define BASE_CHIPS_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define BASE_CHIPS_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define BASE_CHIPS_CFG_SW_MAJOR_VERSION_H              (1U)
#define BASE_CHIPS_CFG_SW_MINOR_VERSION_H              (1U)
#define BASE_CHIPS_CFG_SW_PATCH_VERSION_H              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

#define A8V2E

#define TT_SAFETY             (STD_OFF)
#define TT_PERF               (STD_OFF)

#define TT_CHIP_NAME          A8V2E
#define TT_CHIP_PREFIX(name)  A8V2E##name

#define TT_ADC_HEADER         "A8V2E_ADC.h"
#define TT_CAN_HEADER         "A8V2E_CAN.h"
#define TT_CRC_HEADER         "A8V2E_CRC.h"
#define TT_DEBUG_HEADER       "A8V2E_DEBUG.h"
#define TT_DFCU_HEADER        "A8V2E_DFCU.h"
#define TT_DMA_HEADER         "A8V2E_DMA.h"
#define TT_EMAC_HEADER        "A8V2E_EMAC.h"
#define TT_FPU_HEADER         "A8V2E_FPU.h"
#define TT_FTM_HEADER         "A8V2E_FTM.h"
#define TT_GPIO_HEADER        "A8V2E_GPIO.h"
#define TT_GTM_HEADER         "A8V2E_GTM.h"
#define TT_I2C_HEADER         "A8V2E_I2C.h"
#define TT_I3C_HEADER         "A8V2E_I3C.h"
#define TT_LASER_HEADER       "A8V2E_LASER.h"
#define TT_LIN_HEADER         "A8V2E_LIN.h"
#define TT_MAILBOX_HEADER     "A8V2E_MAILBOX.h"
#define TT_MPU_HEADER         "A8V2E_MPU.h"
#define TT_NVIC_HEADER        "A8V2E_NVIC.h"
#define TT_OTP_HEADER         "A8V2E_OTP.h"
#define TT_PDB_HEADER         "A8V2E_PDB.h"
#define TT_PFCU_HEADER        "A8V2E_PFCU.h"
#define TT_PMU_HEADER         "A8V2E_PMU.h"
#define TT_PPU_HEADER         "A8V2E_PPU.h"
#define TT_QSPI_HEADER        "A8V2E_QSPI.h"
#define TT_RTC_HEADER         "A8V2E_RTC.h"
#define TT_SAI_HEADER         "A8V2E_SAI.h"
#define TT_SCB_HEADER         "A8V2E_SCB.h"
#define TT_SCU_HEADER         "A8V2E_SCU.h"
#define TT_SENT_HEADER        "A8V2E_SENT.h"
#define TT_SHIELD_HEADER      "A8V2E_SHIELD.h"
#define TT_SMPU_HEADER        "A8V2E_SMPU.h"
#define TT_SSP_HEADER         "A8V2E_SSP.h"
#define TT_STM_HEADER         "A8V2E_STM.h"
#define TT_SYSTICK_HEADER     "A8V2E_SYSTICK.h"
#define TT_TRGMUX_HEADER      "A8V2E_TRGMUX.h"
#define TT_TRNG_HEADER        "A8V2E_TRNG.h"
#define TT_UART_HEADER        "A8V2E_UART.h"
#define TT_WDG_HEADER         "A8V2E_WDG.h"

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
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#endif /* BASE_CHIP_CFG_H */
