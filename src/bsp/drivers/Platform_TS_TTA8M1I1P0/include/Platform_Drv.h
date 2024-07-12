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
**  FILENAME     : Platform_Drv.h                                             **
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
#ifndef PLATFORM_DRV_H
#define PLATFORM_DRV_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "Platform_Drv_Types.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PLATFORM_DRV_VENDOR_ID_H                     1541
#define PLATFORM_DRV_MODULE_ID_H                     219
#define PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_H      4
#define PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_H      4
#define PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_H      0
#define PLATFORM_DRV_SW_MAJOR_VERSION_H              1
#define PLATFORM_DRV_SW_MINOR_VERSION_H              1
#define PLATFORM_DRV_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Platform_Drv.h and Platform_Drv_Types.h file version check */
#if (PLATFORM_DRV_VENDOR_ID_H != PLATFORM_DRV_TYPES_VENDOR_ID_H)
    #error "Platform_Drv.h and Platform_Drv_Types.h have different vendor id"
#endif
#if (PLATFORM_DRV_MODULE_ID_H != PLATFORM_DRV_TYPES_MODULE_ID_H)
    #error "Platform_Drv.h and Platform_Drv_Types.h have different module id"
#endif
#if ((PLATFORM_DRV_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_DRV_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_MINOR_VERSION_H != PLATFORM_DRV_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PLATFORM_DRV_AR_RELEASE_PATCH_VERSION_H != PLATFORM_DRV_TYPES_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Platform_Drv.h and Platform_Drv_Types.h are different"
#endif
#if ((PLATFORM_DRV_SW_MAJOR_VERSION_H != PLATFORM_DRV_TYPES_SW_MAJOR_VERSION_H) || \
     (PLATFORM_DRV_SW_MINOR_VERSION_H != PLATFORM_DRV_TYPES_SW_MINOR_VERSION_H) || \
     (PLATFORM_DRV_SW_PATCH_VERSION_H != PLATFORM_DRV_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Platform_Drv.h and Platform_Drv_Types.h are different"
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

/*****************************************************************************
*  Service name    : Platform_Drv_Init
*  Syntax          : TT_RetType Platform_Drv_Init(TT_CONST Platform_Drv_ConfigType * TT_CONST pConfig)
*  Service ID      : 100
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : pConfig  Pointer to a CONSTant Platform module setting
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes the platform settings based on user configuration.
******************************************************************************/
extern TT_RetType Platform_Drv_Init(TT_CONST Platform_Drv_ConfigType * TT_CONST pConfig);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_Init
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_Init(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig)
*  Service ID      : 101
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : pIntCtrlCtrlConfig  Pointer to a CONSTant Platform interrupt control setting.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes the configured interrupts at interrupt controller level.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_Init(TT_CONST Platform_Hw_IntCtrlConfigType * TT_CONST pIntCtrlCtrlConfig);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Init
*  Syntax          : TT_RetType Platform_Drv_Mpu_Init(TT_CONST Platform_Hw_MpuConfigType * TT_CONST pConfig)
*  Service ID      : 130
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : pConfig  Pointer to configuration structure for MPU M7.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes the Memory Protection Unit general parameters and
*                    region configurations.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_Init(TT_CONST Platform_Hw_MpuConfigType * TT_CONST pConfig);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Deinit
*  Syntax          : TT_RetType Platform_Drv_Mpu_Deinit(void)
*  Service ID      : 132
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Disables the module and resets all region configurations.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_Deinit(void);

#if (PLATFORM_VERSION_INFO_API == STD_ON)
/******************************************************************************
*  Service name    : Platform_Drv_GetVersionInfo
*  Syntax          : TT_RetType Platform_Drv_GetVersionInfo(Std_VersionInfoType* versioninfo)
*  Service ID      : 145
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): versioninfo : Pointer to where to store the version
                     information of this module.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : This service returns the version information of this module.
********************************************************************************/
extern TT_RetType Platform_Drv_GetVersionInfo(Std_VersionInfoType *Versioninfo);
#endif

#define PLATFORM_STOP_SEC_CODE_SLOW
#include "Platform_MemMap.h"

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_SetPriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_SetPriority(TT_CONST IRQn_Type eIrqNumber, TT_CONST uint8 preemptionPriority, TT_CONST uint8 subPriority)
*  Service ID      : 102
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : eIrqNumber  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (in) : preemptionPriority  Preemptive priority value in range [0, 2^{7-priorityGroup}-1].
*  Parameters (in) : subPriority  Subpriority value in range [0, 2^{priorityGroup+1}-1].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : The range of preemption priority and sub priority depends on the value of priorityGroup
*                    which you may obtain with SetPriorityGrouping().
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_SetPriority(TT_CONST IRQn_Type eIrqNumber, TT_CONST uint8 preemptionPriority, TT_CONST uint8 subPriority);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GetPriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GetPriority(TT_CONST IRQn_Type eIrqNumber, uint8 * TT_CONST RetVal)
*  Service ID      : 103
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : eIrqNumber  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): RetVal  Grouped priority value of specific interrupt.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get an interrupt priority value.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_GetPriority(TT_CONST IRQn_Type eIrqNumber, uint8 * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GroupingSetPriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GroupingSetPriority(TT_CONST uint32 PriorityGroup)
*  Service ID      : 104
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : PriorityGroup  Priority grouping field.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Sets the priority grouping field using the required unlock sequence.
*                    The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
*                    Only values from 0..7 are used.
*                    In case of a conflict between priority grouping and available
*                    priority bits (PLATFORM_INT_CTRL_GROUP_BITS), the smallest possible priority group is set.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_GroupingSetPriority(TT_CONST uint32 PriorityGroup);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GroupingGetPriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GroupingGetPriority(uint32 * TT_CONST RetVal)
*  Service ID      : 105
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): RetVal  Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Reads the priority grouping field from the NVIC Interrupt Controller.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_GroupingGetPriority(uint32 * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_EnableIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_EnableIRQ(TT_CONST IRQn_Type IRQn)
*  Service ID      : 106
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Enables a device specific interrupt in the NVIC interrupt controller.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_EnableIRQ(TT_CONST IRQn_Type IRQn);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GetEnableIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GetEnableIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
*  Service ID      : 107
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): RetVal  Interrupt enable status.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Returns a device specific interrupt enable status from the NVIC interrupt controller.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_GetEnableIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_DisableIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_DisableIRQ(TT_CONST IRQn_Type IRQn)
*  Service ID      : 108
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Disables a device specific interrupt in the NVIC interrupt controller.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_DisableIRQ(TT_CONST IRQn_Type IRQn);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GetPendingIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GetPendingIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
*  Service ID      : 109
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): Interrupt status is pending or not.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Reads the NVIC pending register and returns the pending bit for the specified device specific interrupt.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_GetPendingIRQ(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_SetPendingIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_SetPendingIRQ(TT_CONST IRQn_Type IRQn)
*  Service ID      : 110
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Sets the pending bit of a device specific interrupt in the NVIC pending register.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_SetPendingIRQ(TT_CONST IRQn_Type IRQn);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_ClearPendingIRQ
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_ClearPendingIRQ(TT_CONST IRQn_Type IRQn)
*  Service ID      : 111
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Clears the pending bit of a device specific interrupt in the NVIC pending register.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_ClearPendingIRQ(TT_CONST IRQn_Type IRQn);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_GetActive
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_GetActive(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
*  Service ID      : 112
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): RetVal  Interrupt active status.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Reads the active register in the NVIC and returns the active bit for the device specific interrupt.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_GetActive(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_SoftTrig
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_SoftTrig(TT_CONST IRQn_Type IRQn)
*  Service ID      : 143
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : IRQn  Device specific interrupt number in range [0, MAX_IRQn].
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Trigger a interrupt by means of software trigger.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_SoftTrig(TT_CONST IRQn_Type IRQn);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_EncodePriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_EncodePriority(TT_CONST uint32 PriorityGroup,TT_CONST uint32 PreemptPriority,
*                                                                   TT_CONST uint32 SubPriority,uint32 * TT_CONST RetVal)
*  Service ID      : 113
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : PriorityGroup  Used priority group.
*  Parameters (in) : PreemptPriority  Preemptive priority value (starting from 0).
*  Parameters (in) : SubPriority  Subpriority value (starting from 0).
*  Parameters (out): RetVal  Encoded priority. Value can be used in the function
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Encodes the priority for an interrupt with the given priority group,
*                    preemptive priority value, and subpriority value.
*                    In case of a conflict between priority grouping and available
*                    priority bits (PLATFORM_INT_CTRL_GROUP_BITS), the smallest possible priority group is set.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_EncodePriority(TT_CONST uint32 PriorityGroup,TT_CONST uint32 PreemptPriority,
											   TT_CONST uint32 SubPriority,uint32 * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_IntCtrl_DecodePriority
*  Syntax          : TT_RetType Platform_Drv_IntCtrl_DecodePriority(TT_CONST uint32 Priority,TT_CONST uint32 PriorityGroup,
*                                                                   uint32* TT_CONST pPreemptPriority,uint32* TT_CONST pSubPriority)
*  Service ID      : 114
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : Priority   Priority value, which can be retrieved with the function \ref Platform_Drv_IntCtrl_GetPriority().
*  Parameters (in) : PriorityGroup  Used priority group.
*  Parameters (out): pPreemptPriority  Preemptive priority value (starting from 0).
*  Parameters (out): pSubPriority  Subpriority value (starting from 0).
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes the platform settings based on user configuration.
******************************************************************************/
extern TT_RetType Platform_Drv_IntCtrl_DecodePriority(TT_CONST uint32 Priority,TT_CONST uint32 PriorityGroup,
												uint32* TT_CONST pPreemptPriority,uint32* TT_CONST pSubPriority);

/*****************************************************************************
*  Service name    : Platform_Drv_Misc_GetFPUType
*  Syntax          : TT_RetType Platform_Drv_Misc_GetFPUType(uint32 * TT_CONST RetVal)
*  Service ID      : 115
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): RetVal  FPU type.
*                       0  No FPU.
*                       1  Single precision FPU.
*                       2  Double + Single precision FPU.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get FPU type.
******************************************************************************/
extern TT_RetType Platform_Drv_Misc_GetFPUType(uint32 * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_Misc_SetVector
*  Syntax          : TT_RetType Platform_Drv_Misc_SetVector(TT_CONST IRQn_Type IRQn, TT_CONST uint32 vector)
*  Service ID      : 117
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Interrupt number in range [0, MAX_IRQn].
*  Parameters (in) : vector  Address of interrupt handler function.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Set interrupt vector.
******************************************************************************/
extern TT_RetType Platform_Drv_Misc_SetVector(TT_CONST IRQn_Type IRQn, TT_CONST uint32 vector);

/*****************************************************************************
*  Service name    : Platform_Drv_Misc_GetVector
*  Syntax          : TT_RetType Platform_Drv_Misc_GetVector(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal)
*  Service ID      : 118
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : IRQn  Interrupt number in range [0, MAX_IRQn].
*  Parameters (out): RetVal  Address of interrupt handler function stored in uint32.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Get Interrupt Vector.
******************************************************************************/
extern TT_RetType Platform_Drv_Misc_GetVector(TT_CONST IRQn_Type IRQn, uint32 * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_EnableICache
*  Syntax          : TT_RetType Platform_Drv_Cache_EnableICache(void)
*  Service ID      : 119
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Turns on I-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_EnableICache(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_DisableICache
*  Syntax          : TT_RetType Platform_Drv_Cache_DisableICache(void)
*  Service ID      : 120
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Turns off I-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_DisableICache(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_InvalidateICache
*  Syntax          : TT_RetType Platform_Drv_Cache_InvalidateICache(void)
*  Service ID      : 121
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Invalidate I-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_InvalidateICache(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_AddrInvalidateICache
*  Syntax          : TT_RetType Platform_Drv_Cache_AddrInvalidateICache(void * TT_CONST addr, TT_CONST uint32 isize)
*  Service ID      : 144
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : addr    address
*  Parameters (in) : isize   size of memory block (in number of bytes)
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Invalidate I-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_AddrInvalidICache(void * TT_CONST addr, TT_CONST uint32 isize);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_EnableDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_EnableDCache(void)
*  Service ID      : 122
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Turns on D-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_EnableDCache(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_DisableDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_DisableDCache(void)
*  Service ID      : 123
*  Sync/Async      : Synchronous
*  Reentrancy      : Non reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Turns off D-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_DisableDCache(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_InvalidateDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_InvalidateDCache(void)
*  Service ID      : 124
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Invalidate D-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_InvalidateDCache(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_CleanDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_CleanDCache(void)
*  Service ID      : 125
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Cleans D-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_CleanDCache(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_CleanInvalidateDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_CleanInvalidateDCache(void)
*  Service ID      : 126
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Cleans & Invalidate D-Cache.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_CleanInvalidateDCache(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_AddrInvalidateDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_AddrInvalidateDCache(void)
*  Service ID      : 127
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : addr  Address
*  Parameters (in) : dsize  Size of memory block (in number of bytes)
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Invalidates D-Cache for the given address.
*                    D-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
*                    D-Cache memory blocks which are part of given address + given size are invalidated.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_AddrInvalidateDCache(void * TT_CONST addr, TT_CONST uint32 dsize);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_AddrCleanDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_AddrCleanDCache(void)
*  Service ID      : 128
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : addr  Address
*  Parameters (in) : dsize  Size of memory block (in number of bytes)
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Cleans D-Cache for the given address.
*                    D-Cache is Cleaned starting from a 32 byte aligned address in 32 byte granularity.
*                    D-Cache memory blocks which are part of given address + given size are invalidated.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_AddrCleanDCache(uint32 * TT_CONST addr, TT_CONST uint32 dsize);

/*****************************************************************************
*  Service name    : Platform_Drv_Cache_AddrCleanInvalidateDCache
*  Syntax          : TT_RetType Platform_Drv_Cache_AddrCleanInvalidateDCache(void)
*  Service ID      : 129
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : addr  Address
*  Parameters (in) : dsize  Size of memory block (in number of bytes)
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Cleans and invalidates D-Cache for the given address.
*                    D-Cache is Cleaned and invalidated starting from a 32 byte aligned address in 32 byte granularity.
*                    D-Cache memory blocks which are part of given address + given size are invalidated.
******************************************************************************/
extern TT_RetType Platform_Drv_Cache_AddrCleanInvalidateDCache(uint32 * TT_CONST addr, TT_CONST uint32 dsize);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_SetRegionConfig
*  Syntax          : TT_RetType Platform_Drv_Mpu_SetRegionConfig(TT_CONST uint8 RegionNum, TT_CONST Platform_Hw_MpuRegionConfigType * TT_CONST pUserConfigPtr)
*  Service ID      : 131
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : u8RegionNum  Region number.
*  Parameters (in) : pUserConfigPtr  Pointer to the region configuration structure for MPU M7.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Configures the region selected by u8RegionNum with the data from pUserConfigPtr.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_SetRegionConfig(TT_CONST uint8 RegionNum, TT_CONST Platform_Hw_MpuRegionConfigType * TT_CONST pUserConfigPtr);
/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_EnableRegion
*  Syntax          : TT_RetType Platform_Drv_Mpu_EnableRegion(TT_CONST uint8 u8RegionNum, TT_CONST boolean bEnable)
*  Service ID      : 133
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : u8RegionNum  Region to be modified.
*  Parameters (in) : bEnable  Specifies whether the region is enabled or disabled.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Enables or disabled a specific region.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_EnableRegion(TT_CONST uint8 u8RegionNum, TT_CONST boolean bEnable);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_SetAccessRight
*  Syntax          : TT_RetType Platform_Drv_Mpu_SetAccessRight(TT_CONST uint8 u8RegionNum, TT_CONST Platform_Hw_MpuAccessRightsType eRights)
*  Service ID      : 134
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : u8RegionNum  Region to be modified.
*  Parameters (in) : eRights  Specifies the new access rights.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Modify the access rights for a specific region
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_SetAccessRight(TT_CONST uint8 u8RegionNum, TT_CONST Platform_Hw_MpuAccessRightsType eRights);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_GetErrorDetails
*  Syntax          : TT_RetType Platform_Drv_Mpu_GetErrorDetails(Platform_Hw_MpuErrorDetailsType * TT_CONST pErrorDetails, boolean * TT_CONST RetVal)
*  Service ID      : 135
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): pErrorDetails  Storage where the data will be saved.
*  Parameters (out): RetVal
*                     TRUE  If an error was present.
*                     FALSE  Otherwise.
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Retrieve error details
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_GetErrorDetails(Platform_Hw_MpuErrorDetailsType * TT_CONST pErrorDetails, boolean * TT_CONST RetVal);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Enable
*  Syntax          : TT_RetType Platform_Drv_Mpu_Enable(TT_CONST uint32 MPU_Control)
*  Service ID      : 136
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : MPU_Control Default access permissions for unconfigured regions
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Enable the MPU.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_Enable(TT_CONST uint32 MPU_Control);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Disable
*  Syntax          : TT_RetType Platform_Drv_Mpu_Disable(void)
*  Service ID      : 137
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : None
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Disable the MPU, must disable MPU first before config MPU.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_Disable(void);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_ClrRegion
*  Syntax          : TT_RetType Platform_Drv_Mpu_ClrRegion(TT_CONST uint32 rnr)
*  Service ID      : 138
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : rnr  Region number to be cleared.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Clear and disable the given MPU region.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_ClrRegion(TT_CONST uint32 rnr);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_SetRegion
*  Syntax          : TT_RetType Platform_Drv_Mpu_SetRegion(TT_CONST uint32 rbar, TT_CONST uint32 rasr)
*  Service ID      : 139
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : rbar  Value for RBAR register.
*  Parameters (in) : rasr  Value for RASR register.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Configure an MPU region.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_SetRegion(TT_CONST uint32 rbar, TT_CONST uint32 rasr);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_SetRegionEx
*  Syntax          : TT_RetType Platform_Drv_Mpu_SetRegionEx(TT_CONST uint32 rnr,TT_CONST uint32 rbar,TT_CONST uint32 rasr)
*  Service ID      : 140
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : rnr  Region number to be configured.
*  Parameters (in) : rbar  Value for RBAR register.
*  Parameters (in) : rasr  Value for RASR register.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Configure the given MPU region.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_SetRegionEx(TT_CONST uint32 rnr,TT_CONST uint32 rbar,TT_CONST uint32 rasr);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_Load
*  Syntax          : TT_RetType Platform_Drv_Mpu_Load(TT_CONST MPU_Region_t * TT_CONST table, TT_CONST uint32 cnt)
*  Service ID      : 141
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : table  Pointer to the MPU configuration table.
*  Parameters (in) : cnt  Amount of regions to be configured.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Load the given number of MPU regions from a table.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_Load(TT_CONST MPU_Region_t * TT_CONST table, TT_CONST uint32 cnt);

/*****************************************************************************
*  Service name    : Platform_Drv_Mpu_ConfigRegion
*  Syntax          : TT_RetType Platform_Drv_Mpu_ConfigRegion(TT_CONST Platform_Hw_MpuRegionInitTypeDef * TT_CONST MPU_Init)
*  Service ID      : 142
*  Sync/Async      : Synchronous
*  Reentrancy      : Reentrant
*  Parameters (in) : MPU_Init  Pointer to a Platform_Hw_MpuRegionInitTypeDef structure that contains
*                    the initialization and configuration information.
*  Parameters (out): None
*  Return value    : TT_RET_SUCCESS: command has been accepted
*                    others: command has not been accepted
*  Description     : Initializes and configures the Region and the memory to be protected.
******************************************************************************/
extern TT_RetType Platform_Drv_Mpu_ConfigRegion(TT_CONST Platform_Hw_MpuRegionInitTypeDef * TT_CONST MPU_Init);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/******************************************************************************
*                            Private Functions
******************************************************************************/
#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* PLATFORM_DRV_H */
