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
**  FILENAME     : system_m7.h                                                **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : system Driver Source File                                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#include "TT_Common.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#define DEFAULT_REGION_NUM		 	(15U)

#define CM7_MPU_RASR_SIZE_32B       (4U)
#define CM7_MPU_RASR_SIZE_64B       (5U)
#define CM7_MPU_RASR_SIZE_128B      (6U)
#define CM7_MPU_RASR_SIZE_256B      (7U)
#define CM7_MPU_RASR_SIZE_512B      (8U)
#define CM7_MPU_RASR_SIZE_1KB       (9U)
#define CM7_MPU_RASR_SIZE_2KB       (10U)
#define CM7_MPU_RASR_SIZE_4KB       (11U)
#define CM7_MPU_RASR_SIZE_8KB       (12U)
#define CM7_MPU_RASR_SIZE_16KB      (13U)
#define CM7_MPU_RASR_SIZE_32KB      (14U)
#define CM7_MPU_RASR_SIZE_64KB      (15U)
#define CM7_MPU_RASR_SIZE_128KB     (16U)
#define CM7_MPU_RASR_SIZE_256KB     (17U)
#define CM7_MPU_RASR_SIZE_512KB     (18U)
#define CM7_MPU_RASR_SIZE_1MB       (19U)
#define CM7_MPU_RASR_SIZE_2MB       (20U)
#define CM7_MPU_RASR_SIZE_4MB       (21U)
#define CM7_MPU_RASR_SIZE_8MB       (22U)
#define CM7_MPU_RASR_SIZE_16MB      (23U)
#define CM7_MPU_RASR_SIZE_32MB      (24U)
#define CM7_MPU_RASR_SIZE_64MB      (25U)
#define CM7_MPU_RASR_SIZE_128MB     (26U)
#define CM7_MPU_RASR_SIZE_256MB     (27U)
#define CM7_MPU_RASR_SIZE_512MB     (28U)
#define CM7_MPU_RASR_SIZE_1GB       (29U)
#define CM7_MPU_RASR_SIZE_2GB       (30U)
#define CM7_MPU_RASR_SIZE_4GB       (31U)

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
*                            Public Functions
*******************************************************************************/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief SystemInit
 * @details function used to system initialization
 */
void SystemInit(void);

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
/*
 * @brief Switch to user mode and return the value passed by u32returnValue
 * @param: [in] u8SwitchToSupervisor - if 0, the function will return the value without switching to user mode,
 *                                     if 1, the function will go to user mode before returning the value
 * @param: [in] u32returnValue       - value to be returned
 *
 * @return: u32returnValue
 */
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue);

/*
 * @brief Switch to supervisor mode
 * @param: None
 *
 * @return: operation result, 1 if switch was done, 0 if the CPU was already in supervisor mode or in handler mode
 */
uint32 Sys_GoToSupervisor(void);

/*
 * @brief Switch to user mode
 * @param: None
 *
 * @return: 0
 */
uint32 Sys_GoToUser(void);

/*
 * @brief Sys_SuspendInterrupts
 * @param: None
 *
 * @return: none
 */
void Sys_SuspendInterrupts(void);
void Sys_ResumeInterrupts(void);
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H */
