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
**  FILENAME     : Dio_Drv_Types.h                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Dio Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef DIO_DRV_TYPES_H
#define DIO_DRV_TYPES_H
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Dio_Hw_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_DRV_TYPES_VENDOR_ID_H                    (1541)
#define DIO_DRV_TYPES_MODULE_ID_H                    (120)
#define DIO_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H     (4)
#define DIO_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H     (4)
#define DIO_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H     (0)
#define DIO_DRV_TYPES_SW_MAJOR_VERSION_H             (1)
#define DIO_DRV_TYPES_SW_MINOR_VERSION_H             (1)
#define DIO_DRV_TYPES_SW_PATCH_VERSION_H             (0)
/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Dio_Hw_Types.h Dio_Drv_Types.h file version check */
#if (DIO_HW_TYPES_VENDOR_ID_H != DIO_DRV_TYPES_VENDOR_ID_H)
    #error "Dio_Hw_Types.h and Dio_Drv_Types.h have different vendor ids"
#endif

#if (DIO_HW_TYPES_MODULE_ID_H != DIO_DRV_TYPES_MODULE_ID_H)
    #error "Dio_Hw_Types.h and Dio_Drv_Types.h have different module ids"
#endif

#if ((DIO_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != DIO_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != DIO_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != DIO_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Hw_Types.h and Dio_Drv_Types.h are different"
#endif

#if ((DIO_HW_TYPES_SW_MAJOR_VERSION_H != DIO_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (DIO_HW_TYPES_SW_MINOR_VERSION_H != DIO_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (DIO_HW_TYPES_SW_PATCH_VERSION_H != DIO_DRV_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Hw_Types.h and Dio_Drv_Types.h are different"
#endif
/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Service ID For Dio_Drv_ReadChannel API */
#define DIO_DRV_SI_READCHANNEL                   (100U)
/* Service ID For Dio_Drv_WriteChannel API */
#define DIO_DRV_SI_WRITECHANNEL                  (101U)
/* Service ID For Dio_Drv_ReadPort API */
#define DIO_DRV_SI_READPORT                      (102U)
/* Service ID For Dio_Drv_WritePort API */
#define DIO_DRV_SI_WRITEPORT                     (103U)
/* Service ID For Dio_Drv_ReadChannelGroup API */
#define DIO_DRV_SI_READCHANNELGROUP              (104U)
/* Service ID For Dio_Drv_WriteChannelGroup */
#define DIO_DRV_SI_WRITECHANNELGROUP             (105U)
/* Service ID For Dio_Drv_GetVersionInfo API */
#define DIO_DRV_SI_GETVERSIONINFO                (106U)
/* Service ID For Dio_Drv_FlipChannel */
#define DIO_DRV_SI_FILPCHANNEL                   (107U)
/* Service ID For Dio_Drv_MaskedWritePort API */
#define DIO_DRV_SI_MASKEDWRITEPORT               (108U)
/* Service ID For Dio_Drv_Interrupt_Init API */
#define DIO_DRV_SI_INTERRUPTINIT                 (109U)
/* Service ID For Dio_Drv_Interrupt_DeInit API */
#define DIO_DRV_SI_INTERRUPTDEINIT               (110U)

/* Default state value */
#define DIO_DRV_TT_STATUS_DEFAULT(ApiID)       (TT_RetType)((TT_RET_SUCCESS << TT_STATUSID_OFFSET) | \
                                                        ((ApiID) << TT_APIID_OFFSET) | \
                                                        (DIO_MODULE_ID << TT_MODULEID_OFFSET))
                                                        
/******************************************************************************
*                            Enums
*******************************************************************************/

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/

/******************************************************************************
*                            Global Variable Declarations
*******************************************************************************/

#endif /* end of DIO_DRV_TYPES_H */
