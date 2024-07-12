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
**  FILENAME     : startup_m7.S                                               **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : startup Driver Source File                       		  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
.syntax unified
.thumb

#ifdef __ARMCC_VERSION

.set __RAM_CACHEABLE_START,		Image$$int_retention_sram_data$$Base
.set __ROM_CACHEABLE_START,		Load$$int_retention_sram_data$$Base
.set __ROM_CACHEABLE_END,		Load$$int_sram_data$$Limit
.set __RAM_NO_CACHEABLE_START,	Image$$int_sram_no_cacheable_data$$Base
.set __ROM_NO_CACHEABLE_START,	Load$$int_sram_no_cacheable_data$$Base
.set __ROM_NO_CACHEABLE_END,	Load$$int_sram_no_cacheable_data$$Limit
.set __RAM_ITCM_START,			Image$$int_itcm$$Base
.set __ROM_ITCM_START,			Load$$int_itcm$$Base
.set __ROM_ITCM_END,			Load$$int_itcm$$Limit
.set __RAM_INTERRUPT_START,		Image$$int_itcm_vector$$Base
.set __ROM_INTERRUPT_START,		Image$$int_flash1$$Base
.set __ROM_INTERRUPT_END,		Image$$int_flash1$$Limit
.set __RAM_DTCM_START,			Image$$int_dtcm_data$$Base
.set __ROM_DTCM_START,			Load$$int_dtcm_data$$Base
.set __ROM_DTCM_END,			Load$$int_dtcm_data$$Limit

.set __BSS_SRAM_START,			Image$$int_sram_bss$$Base
.set __BSS_SRAM_END,			Image$$int_sram_bss$$ZI$$Limit
.set __BSS_SRAM_NC_START,		Image$$int_sram_no_cacheable_bss$$Base
.set __BSS_SRAM_NC_END,			Image$$int_sram_no_cacheable_bss$$ZI$$Limit
.set __BSS_DTCM_START,			Image$$int_dtcm_bss$$Base
.set __BSS_DTCM_END,			Image$$int_dtcm_bss$$ZI$$Limit

.set _sstack,					Image$$__Stack_start_c$$Base
.set _estack,					Image$$__Stack_start_c$$ZI$$Limit
.set __Stack_start_c,			Image$$__Stack_start_c$$ZI$$Limit

.globl __RETENTION_SIZE_START
.section ".retention_sram_data_start", "a"
__RETENTION_SIZE_START:

.globl __RETENTION_SIZE_END
.section ".retention_sram_data_end", "a"
__RETENTION_SIZE_END:

.globl __RAM_NO_CACHEABLE_START
.section ".int_sram_no_cacheable_data_start", "a"
__RAM_NO_CACHEABLE_START:

.globl __RAM_NO_CACHEABLE_END
.section ".int_sram_end", "a"
__RAM_NO_CACHEABLE_END:

#endif

/* Copy table:
*  - Table entries count
*  - entry one ram start
*  - entry one rom start
*  - entry one rom end
*  ...
*  - entry n ram start
*  - entry n rom start
*  - entry n rom end
*  Zero Table:
*  - Table entries count
*  - entry one ram start
*  - entry one ram end
*/
.globl __TT_INIT_TABLE
.section ".tt_init_table", "a"
__TT_INIT_TABLE:
  .long 5
  .long __RAM_CACHEABLE_START
  .long __ROM_CACHEABLE_START
  .long __ROM_CACHEABLE_END
  .long __RAM_NO_CACHEABLE_START
  .long __ROM_NO_CACHEABLE_START
  .long __ROM_NO_CACHEABLE_END
  .long __RAM_ITCM_START
  .long __ROM_ITCM_START
  .long __ROM_ITCM_END
  .long __RAM_INTERRUPT_START
  .long __ROM_INTERRUPT_START
  .long __ROM_INTERRUPT_END
  .long __RAM_DTCM_START
  .long __ROM_DTCM_START
  .long __ROM_DTCM_END

.globl __TT_ZERO_TABLE
.section ".tt_zero_table", "a"
__TT_ZERO_TABLE:
  .long 3
  .long __BSS_SRAM_START
  .long __BSS_SRAM_END
  .long __BSS_SRAM_NC_START
  .long __BSS_SRAM_NC_END
  .long __BSS_DTCM_START
  .long __BSS_DTCM_END

.section ".startup","ax"
.thumb

.set VTOR_REG, 0xE000ED08
.thumb
.thumb_func
  .globl Reset_IRQHandler
  .type  Reset_IRQHandler, %function
Reset_IRQHandler:
/*****************************************************/
/* Skip normal entry point as nothing is initialized */
/*****************************************************/
 cpsid i
 mov   r0, #0
 mov   r1, #0
 mov   r2, #0
 mov   r3, #0
 mov   r4, #0
 mov   r5, #0
 mov   r6, #0
 mov   r7, #0

SetVTOR:
  /* relocate vector table to RAM */
  ldr  r0, =VTOR_REG
  ldr  r1, =__RAM_INTERRUPT_START
  str  r1,[r0]

SetCoreStack:
  /* set up stack; r13 SP*/
  ldr  r0, =__Stack_start_c
  msr MSP, r0

/************************/
/* Erase ".bss Section" */
/************************/
_DATA_INIT:

  ldr r2, = _sstack
  ldr r4, = _estack
  ldr r3, = 0xCDCDCDCD
  b LoopFill

Fill:
  str  r3, [r2]
  adds r2, r2, #4

LoopFill:
  cmp r2, r4
  bcc Fill

  b	 __INIT_DATA_BSS
  b  __SYSTEM_INIT

__INIT_DATA_BSS:
  bl init_data_bss

__SYSTEM_INIT:
  bl SystemInit

/******************************************************************/
/* Call Main Routine                                              */
/******************************************************************/
__MAIN:
  cpsie i
  bl main
  bl _exit

#ifndef __ARMCC_VERSION
.align 4
.ltorg
#endif
