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
**  FILENAME     : Mcu.h                                                      **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Mcu Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Mcu_Types.h"
/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define MCU_VENDOR_ID_H                     1541
#define MCU_MODULE_ID_H                     101
#define MCU_AR_RELEASE_MAJOR_VERSION_H      4
#define MCU_AR_RELEASE_MINOR_VERSION_H      4
#define MCU_AR_RELEASE_PATCH_VERSION_H      0
#define MCU_SW_MAJOR_VERSION_H              1
#define MCU_SW_MINOR_VERSION_H              1
#define MCU_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Mcu.h and Mcu_Types.h file version check */
#if (MCU_VENDOR_ID_H != MCU_TYPES_VENDOR_ID_H)
    #error "Mcu.h and Mcu_Types.h have different vendor id"
#endif
#if (MCU_MODULE_ID_H != MCU_TYPES_MODULE_ID_H)
    #error "Mcu.h and Mcu_Types.h have different module id"
#endif
#if ((MCU_AR_RELEASE_MAJOR_VERSION_H != MCU_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MCU_AR_RELEASE_MINOR_VERSION_H != MCU_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MCU_AR_RELEASE_PATCH_VERSION_H != MCU_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Mcu.h and Mcu_Types.h are different"
#endif
#if ((MCU_SW_MAJOR_VERSION_H != MCU_TYPES_SW_MAJOR_VERSION_H) || \
     (MCU_SW_MINOR_VERSION_H != MCU_TYPES_SW_MINOR_VERSION_H) || \
     (MCU_SW_PATCH_VERSION_H != MCU_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Mcu.h and Mcu_Types.h are different"
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
#define MCU_START_SEC_CODE_SLOW
#include "Mcu_MemMap.h"
/* Public Function Declarations */
/******************************************************************************
*  Service name    : Mcu_Init
*  Syntax          : void Mcu_Init( TT_CONST Mcu_ConfigType *ConfigPtr )
*  Service ID      : 0x00
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : ConfigPtr - Pointer to MCU driver configuration set
*  Parameters (out): None
*  Return value    : None
*  Description     : Service for MCU initialization
******************************************************************************/
extern void Mcu_Init(TT_CONST Mcu_ConfigType *ConfigPtr);

/******************************************************************************
*  Service name    : Mcu_InitRamSection
*  Syntax          : Std_ReturnType Mcu_InitRamSection(
                                            Mcu_RamSectionType RamSection)
*  Service ID      : 0x01
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : RamSection - Selects RAM memory section provided in
                                  configuration set.
*  Parameters (out): None
*  Return value    : E_OK: command has been accepted
*                    E_NOT_OK: command has not been accepted
*  Description     : Service to initalize the RAM section wise.
******************************************************************************/
extern Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection);

#if (MCU_INIT_CLOCK == STD_ON)
/******************************************************************************
*  Service name    : Mcu_InitClock
*  Syntax          : Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting )
*  Service ID      : 0x02
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : Clock Setting
*  Parameters (out): None
*  Return value    : E_OK: command has been accepted
*                    E_NOT_OK: command has not been accepted
*  Description     : Service to initalize the PLL & other MCU clock options
******************************************************************************/
extern Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);
#endif

#if (MCU_NO_PLL == STD_OFF)
/******************************************************************************
*  Service name    : Mcu_DistributePllClock
*  Syntax          : Std_ReturnType Mcu_DistributePllClock( void )
*  Service ID      : 0x03
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : E_OK: command has been accepted
*                    E_NOT_OK: command has not been accepted
*  Description     : Activates the PLL clock to the MCU clock distribution.
******************************************************************************/
extern Std_ReturnType Mcu_DistributePllClock(void);
#endif

#if (MCU_VERSION_INFO_API == STD_ON)
/******************************************************************************
*  Service name    : Mcu_GetVersionInfo
*  Syntax          : void Mcu_GetVersionInfo(Std_VersionInfoType* versioninfo)
*  Service ID      : 0x09
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): versioninfo : Pointer to where to store the version
                     information of this module.
*  Return value    : None
*  Description     : This service returns the version information of this module.
********************************************************************************/
extern void Mcu_GetVersionInfo(Std_VersionInfoType *Versioninfo);
#endif

#define MCU_STOP_SEC_CODE_SLOW
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*  Service name    : Mcu_GetPllStatus
*  Syntax          : Mcu_PllStatusType Mcu_GetPllStatus( void )
*  Service ID      : 0x04
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : Mcu_PllStatusType - PLL status
*  Description     : This service provides the lock status of the PLL.
******************************************************************************/
extern Mcu_PllStatusType Mcu_GetPllStatus(void);

/******************************************************************************
*  Service name    : Mcu_GetResetReason
*  Syntax          : Mcu_ResetType Mcu_GetResetReason( void )
*  Service ID      : 0x05
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : Mcu_ResetType
*  Description     : The service reads the reset type from the hardware.
******************************************************************************/
extern Mcu_ResetType Mcu_GetResetReason(void);

/******************************************************************************
*  Service name    : Mcu_GetResetRawValue
*  Syntax          : Mcu_RawResetType Mcu_GetResetRawValue( void )
*  Service ID      : 0x06
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : Mcu_RawResetType
*  Description     : The service reads the reset type from the hardware register.
********************************************************************************/
extern Mcu_RawResetType Mcu_GetResetRawValue(void);

#if (MCU_PERFORM_RESET_API == STD_ON)
/******************************************************************************
*  Service name    : Mcu_PerformReset
*  Syntax          : void Mcu_PerformReset( void )
*  Service ID      : 0x07
*  Sync/Async      : Synchronous
*  Reentrancy      : Non-reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : None
*  Description     : The service performs a microcontroller reset.
********************************************************************************/
void Mcu_PerformReset(void);
#endif

/******************************************************************************
*  Service name    : Mcu_SetMode
*  Syntax          : void Mcu_SetMode( Mcu_ModeType McuMode )
*  Service ID      : 0x08
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : McuMode : Set different MCU power modes configured.
*  Parameters (out): None
*  Return value    : None
*  Description     : This service activates the MCU power modes.
********************************************************************************/
extern void Mcu_SetMode(Mcu_ModeType McuMode);

#if defined(MCU_GET_RAM_STATE_API) && (MCU_GET_RAM_STATE_API == STD_ON)
/******************************************************************************
*  Service name    : Mcu_GetRamState
*  Syntax          : Mcu_RamStateType Mcu_GetRamState( void )
*  Service ID      : 0x0A
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : Mcu_RamStateType : Status of the Ram Content.
*  Description     : This service provides the actual status of the
                     microcontroller Ram. (if supported)
********************************************************************************/
extern Mcu_RamStateType Mcu_GetRamState(void);
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/******************************************************************************
*                            Private Functions
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* MCU_H */
