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
**  FILENAME     : exceptions_m7.c                                            **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : exceptions Driver Source File                              **
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
#if defined(UART1_PRINTF)
#include <stdio.h>
#endif

#include "TT_Common.h"
#include "Base_Tools.h"

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
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

void NMI_IRQHandler(void)              										__attribute__ ((weak));		/* NMI Handler */
void HardFault_IRQHandler_c(uint32* hardfault_agrs, uint32 lr_value)        __attribute__ ((weak));     /* Hard Fault Handler c*/
void MemManage_IRQHandler(void)            									__attribute__ ((weak));     /* MemManage Fault Handler */
void BusFault_IRQHandler(void)             									__attribute__ ((weak));     /* Bus Fault Handler */
void UsageFault_IRQHandler(void)           									__attribute__ ((weak));		/* Usage Fault Handler */
void SVC_IRQHandler(void) 													__attribute__ ((weak));		/* SVC Handler */
void DebugMon_IRQHandler(void)           									__attribute__ ((weak));		/* DebugMon Handler */
void PendSV_IRQHandler(void)           										__attribute__ ((weak));		/* PendSV Handler */
void SysTick_IRQHandler(void)           									__attribute__ ((weak));		/* SysTick Handler */

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
void SVCHandler_main(uint32 * svc_args);
void Suspend_Interrupts(void);
void Resume_Interrupts(void);
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
void SVC_IRQHandler(void)
{
    ASM_KEYWORD("tst lr, #4\n"\
                "ite eq\n" \
                "mrseq   r0, MSP\n" \
                "mrsne   r0, PSP\n");
    /* stack pointer is passed to SVCHandler_main, it will be used to extract the parameter given to svc call*/
    ASM_KEYWORD("ldr r1,=SVCHandler_main");
    ASM_KEYWORD("bx r1");
}

void SVCHandler_main(uint32 * svc_args)
{
	uint32 svc_number;
	/* Stack contains:    * r0, r1, r2, r3, r12, r14, the return address and xPSR   */
    /* First argument (r0) is svc_args[0]  */
    /* svc_args[6] =  SP + 0x18  PC(r15) */
    /* ((char *)svc_args[6])[-2]; = first two bytes, lsb, of the instruction which caused the SVC */
    /* this will nto work if optimization compiler options are changed*/
    svc_number = ((uint8 *)svc_args[6])[-2];

    switch(svc_number)
    {
        case 1:
            /* Handle SVC 01*/
            ASM_KEYWORD("mov   r0, #0x1");   /* Set User mode for Thread mode */
            ASM_KEYWORD("msr   CONTROL, r0");
            break;
        case 0:
            /* Handle SVC 00*/
            ASM_KEYWORD("mov   r0, #0x0");   /* Set Supervisor mode for Thread mode */
            ASM_KEYWORD("msr   CONTROL, r0");
            break;
        case 2:
            /* Handle SVC 02*/
            Resume_Interrupts(); /* Resume all interrupts */
            break;
        case 3:
            /* Handle SVC 03*/
            Suspend_Interrupts();  /* Suspend all interrupts */
            break;
        default:
            /* Unknown SVC*/
            break;
    }
}

void Suspend_Interrupts(void)
{
    ASM_KEYWORD("cpsid i");
}

void Resume_Interrupts(void)
{
    ASM_KEYWORD("cpsie i");
}

uint32 startup_getControlRegisterValue(void)
{
	uint32 u32Reg;

	ASM_KEYWORD("mrs %0,control":"=r"(u32Reg)::);

	return u32Reg;
}

uint32 startup_getAipsRegisterValue(void)
{
	uint32 u32Reg;

	ASM_KEYWORD("mrs %0,ipsr":"=r"(u32Reg)::);

	return u32Reg;
}
#endif

void NMI_IRQHandler(void)
{
#if defined(UART1_PRINTF)
	(void)printf("NMI_IRQHandler \r\n");
#endif
	while(1);
}

uint32 hardfault_sp = 0;

void HardFault_IRQHandler_c(uint32* hardfault_agrs, uint32 lr_value)
{
	hardfault_sp = (uint32)hardfault_agrs;
	
#if defined(UART1_PRINTF)
	uint32 stacked_r0;
	uint32 stacked_r1;
	uint32 stacked_r2;
	uint32 stacked_r3;
	uint32 stacked_r12;
	uint32 stacked_lr;
	uint32 stacked_pc;
	uint32 stacked_psr;

	uint32 cfsr;
	uint32 bus_fault_address;
	uint32 memmanage_fault_address;

	bus_fault_address = TT_SCB->BFAR;
	memmanage_fault_address = TT_SCB->MMFAR;
	cfsr = TT_SCB->CFSR;

	stacked_r0 = (uint32)hardfault_agrs[0];
	stacked_r1 = (uint32)hardfault_agrs[1];
	stacked_r2 = (uint32)hardfault_agrs[2];
	stacked_r3 = (uint32)hardfault_agrs[3];
	stacked_r12 = (uint32)hardfault_agrs[4];
	stacked_lr = (uint32)hardfault_agrs[5];
	stacked_pc = (uint32)hardfault_agrs[6];
	stacked_psr = (uint32)hardfault_agrs[7];

	(void)printf("HardFault_IRQHandler \r\n");
	(void)printf("- Stack frame:\r\n");
	(void)printf("R0 = 0x%x:\r\n", stacked_r0);
	(void)printf("R1 = 0x%x:\r\n", stacked_r1);
	(void)printf("R2 = 0x%x:\r\n", stacked_r2);
	(void)printf("R3 = 0x%x:\r\n", stacked_r3);
	(void)printf("R12 = 0x%x:\r\n", stacked_r12);
	(void)printf("LR = 0x%x:\r\n", stacked_lr);
	(void)printf("PC = 0x%x:\r\n", stacked_pc);
	(void)printf("PSR = 0x%x:\r\n", stacked_psr);
	(void)printf("- FSR/FAR:\r\n");
	(void)printf("CFSR = 0x%x:\r\n", cfsr);
	(void)printf("HFSR = 0x%x:\r\n", TT_SCB->HFSR);
	(void)printf("DFSR = 0x%x:\r\n", TT_SCB->DFSR);
	(void)printf("AFSR = 0x%x:\r\n", TT_SCB->AFSR);

	if (cfsr & 0x0080)
	{
		(void)printf("MMFAR = 0x%x:\r\n", memmanage_fault_address);
	}
	else
	{

	}

	if (cfsr & 0x8000)
	{
		(void)printf("BFAR = 0x%x:\r\n", bus_fault_address);
	}
	else
	{

	}

	(void)printf("- Misc:\r\n");
	(void)printf("LR/EXC_RETURN = 0x%x:\r\n", lr_value);
#else
	(void)hardfault_agrs;
	(void)lr_value;
#endif
	while(1);
}

void MemManage_IRQHandler(void)
{
#if defined(UART1_PRINTF)
	(void)printf("MemManage_IRQHandler \r\n");
#endif
	while(1);
}

void BusFault_IRQHandler(void)
{
#if defined(UART1_PRINTF)
	(void)printf("BusFault_IRQHandler \r\n");
#endif
	while(1);
}

void UsageFault_IRQHandler(void)
{
#if defined(UART1_PRINTF)
	(void)printf("UsageFault_IRQHandler \r\n");
#endif
	while(1);
}

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
void SVC_IRQHandler(void)
{
#if defined(UART1_PRINTF)
	(void)printf("SVC_IRQHandler \r\n");
#endif
	while(1);
}
#endif

void DebugMon_IRQHandler(void)
{
#if defined(UART1_PRINTF)
	(void)printf("DebugMon_IRQHandler \r\n");
#endif
	while(1);
}

void PendSV_IRQHandler(void)
{
#if defined(UART1_PRINTF)
	(void)printf("PendSV_IRQHandler \r\n");
#endif
	while(1);
}

void SysTick_IRQHandler(void)
{
#if defined(UART1_PRINTF)
	(void)printf("SysTick_IRQHandler \r\n");
#endif
	while(1);
}

void Default_IRQHandler_c(void)
{
#if defined(UART1_PRINTF)
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if ((TT_NVIC->IABR[i] >> j) & 0x1)
			{
				(void)printf("Default_Handler: %d, need to implement interrupt handlers\r\n", (i*32) + j);
			}
		}
	}
#endif
	while(1);
}

void SHDN_IRQHandler(void)
{
	uint32 Tmp = 0U;

	Tmp = TT_SCU->INT_STATUS;
	if(TT_SCU->INT_STATUS > 0)
	{
		TT_SCU->INT_STATUS = Tmp;
	}
	TT_SCU->CLK_SLEEP2 &= ~TT_SCU_CLK_SLEEP2_SCU_Msk;
	MCAL_DATA_SYNC_BARRIER();
	MCAL_INSTRUCTION_SYNC_BARRIER();
	MCAL_WFI();
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif
