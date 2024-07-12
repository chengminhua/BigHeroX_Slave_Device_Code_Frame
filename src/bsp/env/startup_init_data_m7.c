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
**  FILENAME     : startup_init_data_m7.c                                     **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : startup init data Driver Source File                       **
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
/*!
 * @brief Defines the init table layout
 */
typedef struct
{
	uint8 *ram_start; /*!< Start address of section in RAM */
	uint8 *rom_start; /*!< Start address of section in ROM */
	uint8 *rom_end; /*!< End address of section in ROM */
} Sys_CopyLayoutType;

/*!
 * @brief Defines the zero table layout
 */
typedef struct
{
	uint8 *ram_start; /*!< Start address of section in RAM */
	uint8 *ram_end; /*!< End address of section in RAM */
} Sys_ZeroLayoutType;

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
extern uint32 __TT_INIT_TABLE[];
extern uint32 __TT_ZERO_TABLE[];

extern uint32 __RETENTION_SIZE_START[];
extern uint32 __RETENTION_SIZE_END[];

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : init_data_bss
 * Description   : Make necessary initializations for RAM.
 * - Copy the vector table from ROM to RAM.
 * - Copy initialized data from ROM to RAM.
 * - Copy code that should reside in RAM from ROM
 * - Clear the zero-initialized data section.
 *
 * Implements    : init_data_bss_Activity
 *END**************************************************************************/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

void init_data_bss(void)
{
	const Sys_CopyLayoutType *copy_layout;
	const Sys_ZeroLayoutType *zero_layout;
	const uint8 *rom;
	uint8 *ram;
	uint32 len = 0U;
	uint32 retention_size = 0U;
	uint32 size = 0U;
	uint32 i = 0U;
	uint32 j = 0U;

	const uint32 *initTable_Ptr = (uint32*) __TT_INIT_TABLE;
	const uint32 *zeroTable_Ptr = (uint32*) __TT_ZERO_TABLE;

	/* Copy initialized table */
	len = *initTable_Ptr;
	initTable_Ptr++;

	retention_size = (uint32)__RETENTION_SIZE_END - (uint32)__RETENTION_SIZE_START;

	copy_layout = (const Sys_CopyLayoutType*) initTable_Ptr;
	for (i = 0; i < len; i++)
	{
		if (i == 0)
		{
			/* Check whether it is a low power reset */
			if (TT_SCU->RESET_SOURCE & TT_SCU_RESET_SOURCE_LOW_POWER_Msk)
			{
				rom = copy_layout[i].rom_start + retention_size;
				ram = copy_layout[i].ram_start + retention_size;
				size = (uint32) copy_layout[i].rom_end - (uint32) copy_layout[i].rom_start - retention_size;
			}
			else
			{
				rom = copy_layout[i].rom_start;
				ram = copy_layout[i].ram_start;
				size = (uint32) copy_layout[i].rom_end - (uint32) copy_layout[i].rom_start;
			}
		}
		else
		{
			rom = copy_layout[i].rom_start;
			ram = copy_layout[i].ram_start;
			size = (uint32) copy_layout[i].rom_end - (uint32) copy_layout[i].rom_start;
		}

		for (j = 0UL; j < size; j++)
		{
			ram[j] = rom[j];
		}
	}

	/* Clear zero table */
	len = *zeroTable_Ptr;
	zeroTable_Ptr++;
	zero_layout = (const Sys_ZeroLayoutType*) zeroTable_Ptr;
	for (i = 0; i < len; i++)
	{
		ram = zero_layout[i].ram_start;
		size = (uint32) zero_layout[i].ram_end - (uint32) zero_layout[i].ram_start;

		for (j = 0UL; j < size; j++)
		{
			ram[j] = 0U;
		}		
	}
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif
