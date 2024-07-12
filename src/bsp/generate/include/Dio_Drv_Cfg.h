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
**  FILENAME     : Dio_Drv_Cfg.h                                              **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Dio Driver Configuration Generated File                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef DIO_DRV_CFG_H
#define DIO_DRV_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                                 Includes                                      
*******************************************************************************/
#include "A8V2E_GPIO.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_DRV_CFG_VENDOR_ID_H                       (1541U)
#define DIO_DRV_CFG_MODULE_ID_H                       (120U)
#define DIO_DRV_CFG_INSTANCE_ID_H                     (0U)
#define DIO_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H        (4U)
#define DIO_DRV_CFG_AR_RELEASE_MINOR_VERSION_H        (4U)
#define DIO_DRV_CFG_AR_RELEASE_PATCH_VERSION_H        (0U)
#define DIO_DRV_CFG_SW_MAJOR_VERSION_H                (1U)
#define DIO_DRV_CFG_SW_MINOR_VERSION_H                (1U)
#define DIO_DRV_CFG_SW_PATCH_VERSION_H                (0U)
/******************************************************************************
*                           File Version Checks
******************************************************************************/
#if (A8V2E_GPIO_VENDOR_ID_H !=DIO_DRV_CFG_VENDOR_ID_H)
    #error "A8V2E.h and Dio_Cfg.h have different vendor ids"
#endif

#if ((A8V2E_GPIO_AR_RELEASE_MAJOR_VERSION_H !=DIO_DRV_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (A8V2E_GPIO_AR_RELEASE_MINOR_VERSION_H !=DIO_DRV_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (A8V2E_GPIO_AR_RELEASE_PATCH_VERSION_H !=DIO_DRV_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of A8V2E.h and Dio_Cfg.c are different"
#endif

#if ((A8V2E_GPIO_SW_MAJOR_VERSION_H !=DIO_DRV_CFG_SW_MAJOR_VERSION_H) || \
     (A8V2E_GPIO_SW_MINOR_VERSION_H !=DIO_DRV_CFG_SW_MINOR_VERSION_H) || \
     (A8V2E_GPIO_SW_PATCH_VERSION_H !=DIO_DRV_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of A8V2E.h and Dio_Cfg.c are different"
#endif
/******************************************************************************
*                                  Constants
******************************************************************************/

/******************************************************************************
*                              Defines and Macros
******************************************************************************/
#define DIO_MODULE_ID                      (DIO_DRV_CFG_MODULE_ID_H)

#define DIO_END_OF_LIST                    (0xFF)

#define DIO_INSTANCE_ID                    (DIO_DRV_CFG_INSTANCE_ID_H)

#define DIO_VERSION_INFO_API               (STD_OFF)

#define DIO_DEV_ERROR_DETECT               (STD_OFF)

#define DIO_FLIP_CHANNEL_API               (STD_ON)

#define DIO_MASKED_WRITE_PORT_API          (STD_OFF)

#define GPIO0_INTERRUPT_ENABLE             (STD_OFF)

#define GPIO1_INTERRUPT_ENABLE             (STD_OFF)

#define GPIO2_INTERRUPT_ENABLE             (STD_OFF)

#define GPIO3_INTERRUPT_ENABLE             (STD_OFF)

#define GPIO4_INTERRUPT_ENABLE             (STD_OFF)

#define DIO_PORT_CONFIG_COUNT              (1U)

typedef enum
{
DioMode0_DioChannel0 = 44u,
                         
DioMode0_DioChannel1 = 45u,
                         
DioMode0_DioChannel2 = 46u,
                         
DioMode0_DioChannel3 = 47u,
                         
DioMode0_DioChannel4 = 114u,
                         
DioMode0_DioChannel5 = 57u,
                         
DioPort_End_DioChannel_End = DIO_END_OF_LIST
}DioChannelType;

/******************************************************************************
*                            Defines Check
*******************************************************************************/
#if(DIO_MODULE_ID != DIO_DRV_CFG_MODULE_ID_H)
    #error "DIO MODULE ID Defines Error"
#endif

#if(DIO_END_OF_LIST != 0xFF)
    #error "DIO END OF LIST Defines Error"
#endif

#if(DIO_INSTANCE_ID != DIO_DRV_CFG_INSTANCE_ID_H)
    #error "DIO INSTANCE ID Defines Error"
#endif

#if(DIO_PORT_CONFIG_COUNT != 1U)
    #error "DIO PORT CONFIG COUNT Defines Error"
#endif

#if((DIO_VERSION_INFO_API != STD_OFF) && (DIO_VERSION_INFO_API != STD_ON))
    #error "VERSION INFO API Defines Error"
#endif

#if((DIO_DEV_ERROR_DETECT != STD_OFF) && (DIO_DEV_ERROR_DETECT != STD_ON))
    #error "ERROR DETECT Defines Error"
#endif

#if((DIO_FLIP_CHANNEL_API != STD_OFF) && (DIO_FLIP_CHANNEL_API != STD_ON))
    #error "FLIP CHANNEL API Defines Error"
#endif

#if((DIO_MASKED_WRITE_PORT_API != STD_OFF) && (DIO_MASKED_WRITE_PORT_API != STD_ON))
    #error "MASKED WRITE PORT API Defines Error"
#endif

#if((GPIO0_INTERRUPT_ENABLE != STD_OFF) && (GPIO0_INTERRUPT_ENABLE != STD_ON))
    #error "GPIO0 INTERRUPT ENABLE Defines Error"
#endif

#if((GPIO1_INTERRUPT_ENABLE != STD_OFF) && (GPIO1_INTERRUPT_ENABLE != STD_ON))
    #error "GPIO1 INTERRUPT ENABLE Defines Error"
#endif

#if((GPIO2_INTERRUPT_ENABLE != STD_OFF) && (GPIO2_INTERRUPT_ENABLE != STD_ON))
    #error "GPIO2 INTERRUPT ENABLE Defines Error"
#endif

#if((GPIO3_INTERRUPT_ENABLE != STD_OFF) && (GPIO3_INTERRUPT_ENABLE != STD_ON))
    #error "GPIO3 INTERRUPT ENABLE Defines Error"
#endif

#if((GPIO4_INTERRUPT_ENABLE != STD_OFF) && (GPIO4_INTERRUPT_ENABLE != STD_ON))
    #error "GPIO4 INTERRUPT ENABLE Defines Error"
#endif
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
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */   
#endif /* DIO_CFG_H */
