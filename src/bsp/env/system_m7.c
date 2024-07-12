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
**  FILENAME     : system_m7.c                                                **
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
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*                            Includes
******************************************************************************/
#if defined (_HITECH_C_ALIOTHXX_)
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#endif

#include "system_m7.h"
#include "Base_Tools.h"
#include "Platform_Drv.h"

#ifdef BACK_TRACE_FUALT
#include "cm_backtrace.h"

#define HARDWARE_VERSION               "V2.0.0"
#define SOFTWARE_VERSION               "V1.1.0"
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/

/******************************************************************************
*                       File Version Checks
******************************************************************************/

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
#define SVC_GoToSupervisor()                		ASM_KEYWORD("svc 0x0")
#define SVC_GoToUser()                           	ASM_KEYWORD("svc 0x1")

#define TT_SCB_CPACR_CPx_MASK(CpNum)                (0x3U << TT_SCB_CPACR_CPx_SHIFT(CpNum))
#define TT_SCB_CPACR_CPx_SHIFT(CpNum)               (2U*((uint32)CpNum))
#define TT_SCB_CPACR_CPx(CpNum, x)                  (((uint32)(((uint32)(x))<<TT_SCB_CPACR_CPx_SHIFT((CpNum))))&TT_SCB_CPACR_CPx_MASK((CpNum)))

#ifdef MPU_ENABLE
#define CONFIG_MPU_MEMORY_COUNT                     (11U)
#define DEFAULT_SRAM_NC_REGION_NUM         			(15U)
#endif

/******************************************************************************
*                            Private Constants
*******************************************************************************/

/******************************************************************************
*                            Private Variables
*******************************************************************************/
#ifdef MPU_ENABLE
extern uint32 __RAM_NO_CACHEABLE_START[];
extern uint32 __RAM_NO_CACHEABLE_END[];

/*
 Region    Description     Start                         End                      Size                            Type              Inner Cache Policy    Outer Cache Policy    Shareable    Executable    Privileged Access    Unprivileged Access
 --------  -------------   ----------                    ----------               ----------                      ----------------  --------------------  --------------------  -----------  ------------  -------------------  ---------------------
 0         ITCM            0x0                      	 0xFFFF                   64[KB]                          Normal            None                  None                  No           Yes           Read/Write           Read/Write
 1         Program Flash   0x01000000                	 0x013FFFFF               4[MB]                           Normal            Write-through         Write-through         No           Yes           Read/Write           Read/Write
 2         POTP            0x01400000                    0x01407FFF               32[KB]                          Normal            None                  None                  No           Yes           Read/Write           Read/Write
 3         Data Flash      0x01500000                    0x0153FFFF               256[KB]                      	  Normal            Write-through         Write-through         No           Yes           Read/Write           Read/Write
 4         DOTP            0x01540000                    0x01541FFF               8[KB]                           Normal            None                  None                  No           Yes           Read/Write           Read/Write
 5         DTCM + STACK    0x20000000                    0x2003FFFF               256[KB]                      	  Normal            None                  None                  No           Yes           Read/Write           Read/Write
 6         SRAM     	   0x20100000                    0x2013FFFF               256[KB]                      	  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
 7         pripheral       0x40000000                	 0x5FFFFFFF               512[MB]                      	  Device            None                  None                  No           No            Read/Write           Read/Write
 8         Ext Flash       0x60000000                    0x6FFFFFFF               256[MB]                      	  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
 9         QSPI reg        0xA0000000                    0xA0000FFF               4[KB]                           Device            None                  None                  Yes          No            Read/Write           Read/Write
 10        PPB             0xE0000000                	 0xE00FFFFF               1[MB]                           Strongly Ordered  None                  None                  Yes          No            Read/Write           Read/Write

 ** 15会覆盖6的部分地址的配置 **
 15        SRAM NC         __RAM_NO_CACHEABLE_START  	 __RAM_NO_CACHEABLE_END   __RAM_NO_CACHEABLE_SIZE[B]  	  Normal            None                  None                  No           Yes           Read/Write           Read/Write
 */

volatile uint32 rbar[CONFIG_MPU_MEMORY_COUNT] = {0x0UL};
volatile uint32 rasr[CONFIG_MPU_MEMORY_COUNT] = {0x0UL};
#endif

/******************************************************************************
*                            Public Constants
*******************************************************************************/

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#ifdef MPU_ENABLE
static uint8 Calculate_size(uint32 size);
#endif

#if (defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)) || (defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON))
LOCAL_INLINE void sys_m7_cache_init(void);
LOCAL_INLINE void sys_m7_cache_disable(void);
LOCAL_INLINE void sys_m7_cache_clean(void);
#endif

/******************************************************************************
*                            Public Functions
*******************************************************************************/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void);
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("ldr r0, =0x1");
    ASM_KEYWORD("msr CONTROL, r0");
    ASM_KEYWORD("pop {r0}");
}
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    extern uint32 startup_getControlRegisterValue(void);
    extern uint32 startup_getAipsRegisterValue(void);
    extern void Suspend_Interrupts(void);
    extern void Resume_Interrupts(void);
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/

/*================================================================================================*/
/**
 * @brief Sys_GoToSupervisor
 * @details function used to enter to supervisor mode.
 *           check if it's needed to switch to supervisor mode and make the switch.
 *           Return 1 if switch was done
 */
/*================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
uint32 Sys_GoToSupervisor(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;
    uint32 u32SwitchToSupervisor;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is no need to make the switch */
    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        u32SwitchToSupervisor = 0U;
    }
    else
    {
        u32SwitchToSupervisor = 1U;
        SVC_GoToSupervisor();
    }

    return u32SwitchToSupervisor;
}

/*================================================================================================*/
/**
* @brief Sys_GoToUser_Return
* @details function used to switch back to user mode for Thread mode, return a uint32 value passed as parameter
*/
/*================================================================================================*/
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue)
{
    if (1UL == u32SwitchToSupervisor)
    {
        Direct_GoToUser();
    }

    return u32returnValue;
}

uint32 Sys_GoToUser(void)
{
    Direct_GoToUser();
    return 0UL;
}

/*================================================================================================*/
/**
* @brief Sys_SuspendInterrupts
* @details Suspend Interrupts
*/
/*================================================================================================*/
void Sys_SuspendInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Suspend_Interrupts();
    }
    else
    {
        ASM_KEYWORD(" svc 0x3");
    }
}

/*================================================================================================*/
/**
* @brief Sys_ResumeInterrupts
* @details Resume Interrupts
*/
/*================================================================================================*/
void Sys_ResumeInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Resume_Interrupts();
    }
    else
    {
        ASM_KEYWORD(" svc 0x2");
    }
}
#endif

/**
 * @brief SystemInit
 * @details function used to system initialization
 */
void SystemInit(void)
{
#ifdef MPU_ENABLE
    uint8 index = 0U;
    uint8 regionNum = 0U;

    uint32 __RAM_NO_CACHEABLE_SIZE = __RAM_NO_CACHEABLE_END - __RAM_NO_CACHEABLE_START;
#endif

    /*High enable printf to write to uart */
#ifdef _HITECH_C_ALIOTHXX_

#if (USE_UART_MODULE == STD_ON) && defined(UART1_PRINTF)

    (void)setvbuf(stdout,NULL_PTR, _IOLBF, 0);
#endif

#endif

    /* clear shutdown status */
    TT_SCU->INT_STATUS |= TT_SCU_INT_STATUS_RSTB_RESET_Msk 			 | \
                	      TT_SCU_INT_STATUS_SMU_RST_SHDN_STATUS_Msk  | \
						  TT_SCU_INT_STATUS_SOFT_RST_SHDN_STATUS_Msk | \
						  TT_SCU_INT_STATUS_SMU_CPU0_RST_SHDN_STATUS_Msk;

    /* reset source check */
    if ((TT_SCU->RESET_SOURCE & TT_SCU_RESET_SOURCE_SYS_STABLE_Msk) == 0)
    {
        /* user code: handling when the reset process is incorrect*/
    }

    /* When the CMU alarm is high, it needs to clear the alarm state */
    if(((*(uint32 *)0x400D91B0) & 0xC0) != 0x0)
    {
        (*(uint32 *)(0x400D9000)) = (uint32)0x5U;
        (*(uint32 *)(0x400D9120)) = 0xC0;
    }

    /* Clear alarm execution status */
    (*(uint32 *)(0x400D9038)) = 0xFFF;

/**************************************************************************/
                    /* FPU DISABLE */
/**************************************************************************/
#if defined(PLATFORM_DISABLE_FPU) && (PLATFORM_DISABLE_FPU == STD_ON)
    /* Disable CP10 and CP11 coprocessors */
    TT_SCB->CPACR = (TT_SCB_CPACR_CPx(10U, 0U) | TT_SCB_CPACR_CPx(11U, 0U));

    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#elif defined(PLATFORM_DISABLE_FPU) && (PLATFORM_DISABLE_FPU == STD_OFF)
/**************************************************************************/
                    /* FPU ENABLE */
/**************************************************************************/
    /* Enable CP10 and CP11 coprocessors */
    TT_SCB->CPACR |= (TT_SCB_CPACR_CPx(10U, 3U) | TT_SCB_CPACR_CPx(11U, 3U));

    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#endif /* PLATFORM_DISABLE_FPU */

/**************************************************************************/
                    /* Div 0 HardFault ENABLE */
/**************************************************************************/
#if defined(PLATFORM_DIVZEROHARDFAULTENABLE) && (PLATFORM_DIVZEROHARDFAULTENABLE == STD_ON)
    TT_SCB->CCR |= TT_SCB_CCR_DIV_0_TRP_Msk;
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#endif

/**************************************************************************/
                    /* BACK TRACE FUALT ENABLE */
/**************************************************************************/
#ifdef BACK_TRACE_FUALT
    /* CmBacktrace initialize */
    cm_backtrace_init("CmBacktrace", HARDWARE_VERSION, SOFTWARE_VERSION);
#endif

/**************************************************************************/
					/* MPU ENABLE */
/**************************************************************************/
#ifdef MPU_ENABLE
/**************************************************************************/
                    /* DEFAULT MEMORY ENABLE */
/**************************************************************************/
    /* ITCM */
    rbar[0] = 0x0UL;
    rasr[0] = 0x03080001UL | (CM7_MPU_RASR_SIZE_64KB << 1);

    /* Program flash */
    rbar[1] = 0x01000000UL;
    rasr[1] = 0x03020001UL | (CM7_MPU_RASR_SIZE_4MB << 1);

    /* POTP */
    rbar[2] = 0x01400000UL;
    rasr[2] = 0x03080001UL | (CM7_MPU_RASR_SIZE_32KB << 1);

    /* Data flash */
    rbar[3] = 0x01500000UL;
    rasr[3] = 0x03020001UL | (CM7_MPU_RASR_SIZE_256KB << 1);

    /* DOTP */
    rbar[4] = 0x01540000UL;
    rasr[4] = 0x03080001UL | (CM7_MPU_RASR_SIZE_16KB << 1);

    /* DTCM */
    rbar[5] = 0x20000000UL;
    rasr[5] = 0x03080001UL | (CM7_MPU_RASR_SIZE_256KB << 1);

    /* Ram unified section + stack */
    rbar[6] = 0x20100000UL;
    rasr[6] = 0x030B0001UL | (CM7_MPU_RASR_SIZE_256KB << 1);

    /* pripheral */
    rbar[7] = 0x40000000UL;
    rasr[7] = 0x13100001UL | (CM7_MPU_RASR_SIZE_512MB << 1);

    /* Ext Flash */
    rbar[8] = 0x60000000UL;
    rasr[8] = 0x030B0001UL | (CM7_MPU_RASR_SIZE_256MB << 1);

    /* QSPI reg */
    rbar[9] = 0xA0000000UL;
    rasr[9] = 0x13010001UL | (CM7_MPU_RASR_SIZE_4KB << 1);

    /* PPB */
    rbar[10] = 0xE0000000UL;
    rasr[10] = 0x13000001UL | (CM7_MPU_RASR_SIZE_1MB << 1);

    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");

    /*Checking if cache is enable before*/
    if (((((uint32) 1U << (uint32) 17U) & TT_SCB->CCR) != (uint32) 0)
            || ((((uint32) 1U << (uint32) 16U) & TT_SCB->CCR) != (uint32) 0))
    {
        /*synchronize cache before update mpu */
    #if (defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)) || (defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON))
        sys_m7_cache_clean();
        sys_m7_cache_disable();
    #endif
    }

    /* Set default memory regions */
    for (index = 0U; index < CONFIG_MPU_MEMORY_COUNT; index++)
    {
        if ((rasr[index]&(uint32)0x1) == (uint32)0x1)
        {
            TT_MPU->RNR  = regionNum;
            TT_MPU->RBAR = rbar[index];
            TT_MPU->RASR = rasr[index];
            regionNum++;
        }
    }

    /* Ram non-cache which would extract from linker symbol */
    TT_MPU->RNR  = DEFAULT_SRAM_NC_REGION_NUM;
    TT_MPU->RBAR = (uint32)__RAM_NO_CACHEABLE_START;
    TT_MPU->RASR = ((uint32)0x03080001UL) | (((uint8)Calculate_size((uint32) __RAM_NO_CACHEABLE_SIZE) - 1) << 1);

    /* Enable MPU */
    TT_MPU->CTRL |= TT_MPU_CTRL_ENABLE_MASK;

    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");

#endif /* MPU_ENABLE */

/**************************************************************************/
                    /* ENABLE CACHE */
/**************************************************************************/
#if (defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)) || (defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON))
    sys_m7_cache_init();
#endif
}

/******************************************************************************
*                            Private Functions
******************************************************************************/
#ifdef MPU_ENABLE
static uint8 Calculate_size(uint32 size)
{
    uint32 finalSize = 0UL;

    while (size > 1U)
    {
        finalSize++;
        size >>= 1U;
    }

    return finalSize;
}
#endif

#if (defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)) || (defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON))
LOCAL_INLINE void sys_m7_cache_init(void)
{
#if defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    /*init Data caches*/
    TT_SCB->CSSELR = 0U; /* select Level 1 data cache */
    ASM_KEYWORD("dsb");
    ccsidr = TT_SCB->CCSIDR;
    sets = (uint32) (TT_CCSIDR_SETS(ccsidr));
    do
    {
        ways = (uint32) (TT_CCSIDR_WAYS(ccsidr));
        do
        {
            TT_SCB->DCISW = (((sets << TT_SCB_DCISW_SET_Pos) & TT_SCB_DCISW_SET_Msk) |
                              ((ways << TT_SCB_DCISW_WAY_Pos) & TT_SCB_DCISW_WAY_Msk));

            ASM_KEYWORD("dsb");
        } while (ways-- != 0U);
    } while (sets-- != 0U);
    ASM_KEYWORD("dsb");
    TT_SCB->CCR |= (uint32) TT_SCB_CCR_DC_Msk; /* enable D-Cache */
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#endif

#if defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON)
    /*init Code caches*/
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
    TT_SCB->ICIALLU = 0UL; /* invalidate I-Cache */
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
    TT_SCB->CCR |= (uint32) TT_SCB_CCR_IC_Msk; /* enable I-Cache */
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#endif
    sys_m7_cache_clean();
}

LOCAL_INLINE void sys_m7_cache_disable(void)
{
    sys_m7_cache_clean();
    TT_SCB->CCR &= ~((uint32) TT_SCB_CCR_IC_Msk);
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
    TT_SCB->CCR &= ~((uint32) TT_SCB_CCR_DC_Msk);
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
}

LOCAL_INLINE void sys_m7_cache_clean(void)
{
#if defined(PLATFORM_D_CACHE_ENABLE) && (PLATFORM_D_CACHE_ENABLE == STD_ON)
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    TT_SCB->CSSELR = 0U; /* select Level 1 data cache */
    ASM_KEYWORD("dsb");
    ccsidr = TT_SCB->CCSIDR;
    sets = (uint32) (TT_CCSIDR_SETS(ccsidr));
    do
    {
        ways = (uint32) (TT_CCSIDR_WAYS(ccsidr));
        do
        {
            TT_SCB->DCCISW = (((sets << TT_SCB_DCCISW_SET_Pos) & TT_SCB_DCCISW_SET_Msk) |
                              ((ways << TT_SCB_DCCISW_WAY_Pos) & TT_SCB_DCCISW_WAY_Msk));

            ASM_KEYWORD("dsb");
        } while (ways-- != 0U);
    } while (sets-- != 0U);

    TT_SCB->CSSELR = (uint32) ((TT_SCB->CSSELR) | 1U);
#endif

#if defined(PLATFORM_I_CACHE_ENABLE) && (PLATFORM_I_CACHE_ENABLE == STD_ON)
    TT_SCB->ICIALLU = 0UL;
#endif
    ASM_KEYWORD("dsb");
}
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
