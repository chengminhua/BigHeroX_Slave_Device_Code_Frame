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
**  FILENAME     : Base_Drv.h                                                 **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Base Driver Source File                                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef BASE_DRV_H
#define BASE_DRV_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/

#include "Base_Internal.h"
#include "Base_Drv_Types.h"
#include "Base_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define BASE_DRV_VENDOR_ID_H                     1541
#define BASE_DRV_MODULE_ID_H                     218
#define BASE_DRV_AR_RELEASE_MAJOR_VERSION_H      4
#define BASE_DRV_AR_RELEASE_MINOR_VERSION_H      4
#define BASE_DRV_AR_RELEASE_PATCH_VERSION_H      0
#define BASE_DRV_SW_MAJOR_VERSION_H              1
#define BASE_DRV_SW_MINOR_VERSION_H              1
#define BASE_DRV_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Base_Drv.h and Base_Internal.h file version check */
#if (BASE_DRV_VENDOR_ID_H != BASE_INTERNAL_VENDOR_ID_H)
    #error "Base_Drv.h and Base_Internal.h have different vendor id"
#endif
#if (BASE_DRV_MODULE_ID_H != BASE_INTERNAL_MODULE_ID_H)
    #error "Base_Drv.h and Base_Internal.h have different module id"
#endif
#if ((BASE_DRV_AR_RELEASE_MAJOR_VERSION_H != BASE_INTERNAL_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_MINOR_VERSION_H != BASE_INTERNAL_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_PATCH_VERSION_H != BASE_INTERNAL_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Drv.h and Base_Internal.h are different"
#endif
#if ((BASE_DRV_SW_MAJOR_VERSION_H != BASE_INTERNAL_SW_MAJOR_VERSION_H) || \
     (BASE_DRV_SW_MINOR_VERSION_H != BASE_INTERNAL_SW_MINOR_VERSION_H) || \
     (BASE_DRV_SW_PATCH_VERSION_H != BASE_INTERNAL_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Drv.h and Base_Internal.h are different"
#endif

/* Base_Drv.h and Base_Drv_Types.h file version check */
#if (BASE_DRV_VENDOR_ID_H != BASE_DRV_TYPES_VENDOR_ID_H)
    #error "Base_Drv.h and Base_Drv_Types.h have different vendor id"
#endif
#if (BASE_DRV_MODULE_ID_H != BASE_DRV_TYPES_MODULE_ID_H)
    #error "Base_Drv.h and Base_Drv_Types.h have different module id"
#endif
#if ((BASE_DRV_AR_RELEASE_MAJOR_VERSION_H != BASE_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_MINOR_VERSION_H != BASE_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_PATCH_VERSION_H != BASE_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Drv.h and Base_Drv_Types.h are different"
#endif
#if ((BASE_DRV_SW_MAJOR_VERSION_H != BASE_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (BASE_DRV_SW_MINOR_VERSION_H != BASE_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (BASE_DRV_SW_PATCH_VERSION_H != BASE_DRV_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Drv.h and Base_Drv_Types.h are different"
#endif

/* Base_Drv.h and Base_Cfg.h file version check */
#if (BASE_DRV_VENDOR_ID_H != BASE_CFG_VENDOR_ID_H)
    #error "Base_Drv.h and Base_Cfg.h have different vendor id"
#endif
#if (BASE_DRV_MODULE_ID_H != BASE_CFG_MODULE_ID_H)
    #error "Base_Drv.h and Base_Cfg.h have different module id"
#endif
#if ((BASE_DRV_AR_RELEASE_MAJOR_VERSION_H != BASE_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_MINOR_VERSION_H != BASE_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (BASE_DRV_AR_RELEASE_PATCH_VERSION_H != BASE_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Base_Drv.h and Base_Cfg.h are different"
#endif
#if ((BASE_DRV_SW_MAJOR_VERSION_H != BASE_CFG_SW_MAJOR_VERSION_H) || \
     (BASE_DRV_SW_MINOR_VERSION_H != BASE_CFG_SW_MINOR_VERSION_H) || \
     (BASE_DRV_SW_PATCH_VERSION_H != BASE_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Base_Drv.h and Base_Cfg.h are different"
#endif


/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/

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
#define BASE_START_SEC_CODE_SLOW
#include "Base_MemMap.h"
/*****************************************************************************
*  Service name    : Base_Drv_Init
*  Syntax          : TT_RetType Base_Drv_Init(void)
*  Service ID      : 100
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This function initializes the Base module and should be called during startup, before every
*                    other intialization other than Mcu..
******************************************************************************/
extern TT_RetType Base_Drv_Init(void);
/*****************************************************************************
*  Service name    : Base_Drv_Uninit
*  Syntax          : TT_RetType Base_Drv_Uninit(void)
*  Service ID      : 101
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Base Module UnInit function
******************************************************************************/
extern TT_RetType Base_Drv_Uninit(void);
#define BASE_STOP_SEC_CODE_SLOW
#include "Base_MemMap.h"
/*****************************************************************************
*  Service name    : Base_Drv_Timer_GetCounter
*  Syntax          : TT_RetType Base_Drv_Timer_GetCounter(uint32 * TT_CONST Counter)
*  Service ID      : 102
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This function returns the current value of the counter.
******************************************************************************/
 #define BASE_START_SEC_CODE
#include "Base_MemMap.h"
extern TT_RetType Base_Drv_Timer_GetCounter(uint32 * TT_CONST Counter);

/*****************************************************************************
*  Service name    : Base_Drv_Timer_GetElapsed
*  Syntax          : TT_RetType Base_Drv_Timer_GetElapsed(uint32 * TT_CONST CurrentRef, uint32 * TT_CONST Elapsed)
*  Service ID      : 103
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): Elapsed  Elapsed time
*  Parameters (inout): CurrentRef  Reference counter value, updated to current counter value
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Function returns the delta time in ticks compared to a reference, and updates the reference.
******************************************************************************/
extern TT_RetType Base_Drv_Timer_GetElapsed(uint32 * TT_CONST CurrentRef, uint32 * TT_CONST Elapsed);

/*****************************************************************************
*  Service name    : Base_Drv_Timer_MicrosToTicks
*  Syntax          : TT_RetType Base_Drv_Timer_MicrosToTicks(TT_CONST uint32 Micros, uint32 * TT_CONST Ticks)
*  Service ID      : 104
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Micros  microseconds value
*  Parameters (out): Ticks  equivalent value in ticks
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This function converts a value from microsecond units to ticks units.
******************************************************************************/
extern TT_RetType Base_Drv_Timer_MicrosToTicks(TT_CONST uint32 Micros, uint32 * TT_CONST Ticks);

/*****************************************************************************
*  Service name    : Base_Drv_Usdelay
*  Syntax          : TT_RetType Base_Drv_Usdelay(TT_CONST uint32 Us)
*  Service ID      : 105
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : us  Microsecond value
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Delay us by timer
******************************************************************************/
extern TT_RetType Base_Drv_Usdelay(TT_CONST uint32 Us);

/*****************************************************************************
*  Service name    : Base_Drv_Msdelay
*  Syntax          : TT_RetType Base_Drv_Msdelay(TT_CONST uint32 Ms)
*  Service ID      : 106
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : ms  Microsecond value
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Delay ms by timer
******************************************************************************/
extern TT_RetType Base_Drv_Msdelay(TT_CONST uint32 Ms);


/*****************************************************************************
*  Service name    : Base_Drv_UnlockProtReg
*  Syntax          : TT_RetType Base_Drv_UnlockProtReg(void)
*  Service ID      : 107
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : unlock endinit
******************************************************************************/
extern TT_RetType Base_Drv_UnlockProtReg(void);

/*****************************************************************************
*  Service name    : Base_Drv_LockProtReg
*  Syntax          : TT_RetType Base_Drv_LockProtReg(void)
*  Service ID      : 108
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : lock endinit
******************************************************************************/
extern TT_RetType Base_Drv_LockProtReg(void);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* BASE_DRV_H */
