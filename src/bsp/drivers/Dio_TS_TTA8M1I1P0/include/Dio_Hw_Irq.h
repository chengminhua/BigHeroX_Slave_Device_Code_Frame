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
**  FILENAME     : Dio_Hw_Irq.h                                               **
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
#ifndef DIO_HW_IRQ_H
#define DIO_HW_IRQ_H
/******************************************************************************
*                                  Includes
******************************************************************************/
#include "Dio_Hw_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define DIO_HW_IRQ_VENDOR_ID_H                    (1541U)
#define DIO_HW_IRQ_MODULE_ID_H                    (120U)
#define DIO_HW_IRQ_AR_RELEASE_MAJOR_VERSION_H     (4U)
#define DIO_HW_IRQ_AR_RELEASE_MINOR_VERSION_H     (4U)
#define DIO_HW_IRQ_AR_RELEASE_PATCH_VERSION_H     (0U)
#define DIO_HW_IRQ_SW_MAJOR_VERSION_H             (1U)
#define DIO_HW_IRQ_SW_MINOR_VERSION_H             (1U)
#define DIO_HW_IRQ_SW_PATCH_VERSION_H             (0U)

/******************************************************************************
*                           File Version Checks
******************************************************************************/
/* Dio_Hw_Types.h Dio_Hw_Irq.h file version check */
#if (DIO_HW_TYPES_VENDOR_ID_H != DIO_HW_IRQ_VENDOR_ID_H)
    #error "Dio_Hw_Types.h and Dio_Hw_Irq.h have different vendor id"
#endif

#if (DIO_HW_TYPES_MODULE_ID_H != DIO_HW_IRQ_MODULE_ID_H)
    #error "Dio_Hw_Types.h and Dio_Hw_Irq.h have different module id"
#endif

#if ((DIO_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != DIO_HW_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != DIO_HW_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != DIO_HW_IRQ_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Dio_Hw_Types.h and Dio_Hw_Irq.h are different"
#endif

#if ((DIO_HW_TYPES_SW_MAJOR_VERSION_H != DIO_HW_IRQ_SW_MAJOR_VERSION_H) || \
     (DIO_HW_TYPES_SW_MINOR_VERSION_H != DIO_HW_IRQ_SW_MINOR_VERSION_H) || \
     (DIO_HW_TYPES_SW_PATCH_VERSION_H != DIO_HW_IRQ_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Dio_Hw_Types.h and Dio_Hw_Irq.h are different"
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
#define DIO_START_SEC_CODE_SLOW
#include "Dio_MemMap.h"
/******************************************************************************
*                            Public Prototypes
*******************************************************************************/
/**
* @brief        Dio_Interrupt_init
* @details      Initializes the Dio Interrupt.
* @param[in]    ChannelId - Id of DIO channel
*               TriggerMode - Dio Exit Trigger Type
* @return
* @retval
* @pre
*/
TT_RetType Dio_Hw_Interrupt_Init(TT_CONST Dio_ChannelType ChannelId,
                                 TT_CONST Dio_ExitTriggerType  TriggerMode);
/**
* @brief        Dio_Hw_Interrupt_Deinit
* @details      Dio Interrupt Deinit.
* @param[in]    ChannelId - Id of DIO channel
* @return
* @retval
* @pre
*/
TT_RetType Dio_Hw_Interrupt_DeInit(TT_CONST Dio_ChannelType ChannelId);

#define DIO_STOP_SEC_CODE_SLOW
#include "Dio_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#endif /* end of DIO_HW_IRQ_H */

