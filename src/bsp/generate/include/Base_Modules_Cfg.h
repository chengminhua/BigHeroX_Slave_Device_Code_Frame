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
**  FILENAME     : Base_Modules_Cfg.h                                         **
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
#ifndef BASE_MODULES_CFG_H
#define BASE_MODULES_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Base_Chips_Cfg.h"
#include "TT_StandardTypes.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_MODULES_CFG_VENDOR_ID_H                     (1541U)
#define BASE_MODULES_CFG_MODULE_ID_H                     (218U)
#define BASE_MODULES_CFG_AR_RELEASE_MAJOR_VERSION_H      (4U)
#define BASE_MODULES_CFG_AR_RELEASE_MINOR_VERSION_H      (4U)
#define BASE_MODULES_CFG_AR_RELEASE_PATCH_VERSION_H      (0U)
#define BASE_MODULES_CFG_SW_MAJOR_VERSION_H              (1U)
#define BASE_MODULES_CFG_SW_MINOR_VERSION_H              (1U)
#define BASE_MODULES_CFG_SW_PATCH_VERSION_H              (0U)

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Modules_Cfg.h and Base_Chips_Cfg.h file version check */
#if (BASE_MODULES_CFG_VENDOR_ID_H != BASE_CHIPS_CFG_VENDOR_ID_H)
    #error "Base_Modules_Cfg.h and Base_Chips_Cfg.h have different vendor ids"
#endif
#if (BASE_MODULES_CFG_MODULE_ID_H != BASE_CHIPS_CFG_MODULE_ID_H)
    #error "Base_Modules_Cfg.h and Base_Chips_Cfg.h have different module ids"
#endif
#if ((BASE_MODULES_CFG_AR_RELEASE_MAJOR_VERSION_H != BASE_CHIPS_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_MODULES_CFG_AR_RELEASE_MINOR_VERSION_H != BASE_CHIPS_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_MODULES_CFG_AR_RELEASE_PATCH_VERSION_H != BASE_CHIPS_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Modules_Cfg.h and Base_Chips_Cfg.h are different"
#endif
#if ((BASE_MODULES_CFG_SW_MAJOR_VERSION_H != BASE_CHIPS_CFG_SW_MAJOR_VERSION_H) || \
     (BASE_MODULES_CFG_SW_MINOR_VERSION_H != BASE_CHIPS_CFG_SW_MINOR_VERSION_H) || \
     (BASE_MODULES_CFG_SW_PATCH_VERSION_H != BASE_CHIPS_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Modules_Cfg.h and Base_Chips_Cfg.h are different"
#endif

/* Base_Modules_Cfg.h and TT_StandardTypes.h file version check */
#if (BASE_MODULES_CFG_VENDOR_ID_H != TT_STANDARD_TYPES_VENDOR_ID_H)
    #error "Base_Modules_Cfg.h and TT_StandardTypes.h have different vendor ids"
#endif
#if ((BASE_MODULES_CFG_AR_RELEASE_MAJOR_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_MODULES_CFG_AR_RELEASE_MINOR_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_MODULES_CFG_AR_RELEASE_PATCH_VERSION_H != TT_STANDARD_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Modules_Cfg.h and TT_StandardTypes.h are different"
#endif
#if ((BASE_MODULES_CFG_SW_MAJOR_VERSION_H != TT_STANDARD_TYPES_SW_MAJOR_VERSION_H) || \
     (BASE_MODULES_CFG_SW_MINOR_VERSION_H != TT_STANDARD_TYPES_SW_MINOR_VERSION_H) || \
     (BASE_MODULES_CFG_SW_PATCH_VERSION_H != TT_STANDARD_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Modules_Cfg.h and TT_StandardTypes.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/** 
* @brief This CONSTant used for other modules to check if ADC is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_ADC_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if CAN is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_CAN_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if CRCU is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_CRC_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if CRYPTO is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_CRYPTO_MODULE         (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if DIO is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_DIO_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if Dma is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_DMA_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if ETH is present in the project.
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_ETH_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if FEE is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_EEP_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if FLS is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_FLS_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if GPT is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_GPT_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if GTM is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_GTM_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if I2C is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_I2C_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if I3C is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_I3C_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if ICU is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_ICU_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if LIN is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_LIN_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if MCL is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_MCL_MODULE            (STD_OFF)

 /** 
* @brief This CONSTant used for other modules to check if SMPU is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_SMPU_MODULE           (STD_OFF)
 
/** 
* @brief This CONSTant used for other modules to check if MCU is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_MCU_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if PPU is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_PPU_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if OCU is present in the project.
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_OCU_MODULE            (STD_OFF)

/**
* @brief This CONSTant used for other modules to check if PLATFORM is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_PLATFORM_MODULE       (STD_ON)

/**
* @brief This CONSTant used for other modules to check if PORT is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_PORT_MODULE           (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if PWM is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_PWM_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if SAI is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_SAI_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if SENT is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_SENT_MODULE           (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if SPI is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_SPI_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if STM is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_STM_MODULE            (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if UART is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_UART_MODULE           (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if Smu is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_CMU_MODULE            (STD_ON)

/** 
* @brief This CONSTant used for other modules to check if WDG is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_WDG_MODULE                              (STD_OFF)

/** 
* @brief This CONSTant used for other modules to check if SAFETYMTL is present in the project.  
* @violates @ref modules_h_REF_1 MISRA 2012 Advisory Rule 2.5, unused macro. 
*/
#define USE_SAFETYMTL_MODULE                        (STD_OFF)

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

#endif /* BASE_MODULES_CFG_H */
