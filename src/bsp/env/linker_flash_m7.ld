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
**  FILENAME     : linker_flash_m7.ld                                         **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : linker flash Driver Source File                            **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.0.0]:                                                                    **
*******************************************************************************/
HEAP_SIZE  = DEFINED(__heap_size__)  ? __heap_size__  : 0x00004000;
STACK_SIZE  = DEFINED(__stack_size__)  ? __stack_size__  : 0x00004000;

ENTRY(Reset_IRQHandler)

MEMORY 
{         
    int_flash               : ORIGIN = 0x01000000, LENGTH = 0x00400000    /* 4MB */
    int_itcm                : ORIGIN = 0x00000000, LENGTH = 0x00010000    /* 64K */
    int_dtcm                : ORIGIN = 0x20000000, LENGTH = 0x00040000    /* 256K（Stack in DTCM） */
    int_sram                : ORIGIN = 0x20100000, LENGTH = 0x3C000    	  /* 240K */
    int_sram_no_cacheable   : ORIGIN = 0x2013C000, LENGTH = 0x00004000    /* 16KB, needs to include int_results  */  
    ram_end                 : ORIGIN = 0x20140000, LENGTH = 0             /* End of SRAM */
}

SECTIONS
{
    /* text sections, store in PFlash */
    .text :
    {
        __text_start = .;
        __interrupts_rom_start = .;
        KEEP(*(.isr_vector))    
        . = ALIGN(4);
        __interrupts_rom_end = .;
        
        . = ALIGN(4);
        *(.startup) 
        . = ALIGN(4);
        *(.text)
        *(.text*) 
        . = ALIGN(4);
        *(.mcal_text) 
        . = ALIGN(4);
		*(.saf_text) 
        . = ALIGN(4);
        *(.acmcu_code_rom)
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        KEEP(*(.fini)) 
		
		/* ADD BEGIN */
        . = ALIGN(4);
        *(.mcal_text_normal.*)
        . = ALIGN(4);
        *(.mcal_text_slow.*)
		. = ALIGN(4);
        /* ADD END */

        . = ALIGN(4);
        *(.rodata)  
        *(.rodata*)  
        . = ALIGN(4);
        *(.mcal_const_cfg)  
        . = ALIGN(4);
        *(.mcal_const)  
		. = ALIGN(4);
        *(.saf_const_cfg)  
        . = ALIGN(4);
        *(.saf_const) 
		
		/* ADD BEGIN */
        . = ALIGN(4);
        *(.mcal_const_boolean.*)
        . = ALIGN(4);
        *(.mcal_const_8.*)
        . = ALIGN(4);
        *(.mcal_const_16.*)
        . = ALIGN(4);
        *(.mcal_const_32.*)
        . = ALIGN(4);
        *(.mcal_const_ptr.*)
        . = ALIGN(4);
        *(.mcal_const_unspecified.*)

        . = ALIGN(4);
        *(.mcal_config_data_boolean.*)
        . = ALIGN(4);
        *(.mcal_config_data_8.*)
        . = ALIGN(4);
        *(.mcal_config_data_16.*)
        . = ALIGN(4);
        *(.mcal_config_data_32.*)
        . = ALIGN(4);
        *(.mcal_config_data_ptr.*)
        . = ALIGN(4);
        *(.mcal_config_data_unspecified.*)
		. = ALIGN(4);
        /* ADD END */
		
    } > int_flash
    
	.ARM.extab   : { 
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} >int_flash
	
	.ARM : {
		__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
	} >int_flash

	.tt_table :{
		. = ALIGN(4);
		__tt_init_table = .;
		KEEP(*(.tt_init_table))    	/* store init_table address */
		. = ALIGN(4);
		__tt_zero_table = .;
		KEEP(*(.tt_zero_table)) 	/* store zero_table address */	
		. = ALIGN(4);
	} >int_flash
	
	. = ALIGN(4);
    __text_end = .;
    __sram_data_rom = __text_end;

    .sram_data : AT(__sram_data_rom)
    {
        . = ALIGN(4);
        __sram_data_begin__ = .; 
		__retention_sram_begin__ = .; 
		*(.retention_sram_data);
		__retention_sram_end__ = .; 
        . = ALIGN(4);
        *(.ramcode)    
        . = ALIGN(4);
        *(.data)  
        *(.data*)        
        . = ALIGN(4);
        *(.mcal_data)           
        . = ALIGN(4);
		*(.saf_data)
		
		/* ADD BEGIN */
        . = ALIGN(4);
        *(.mcal_data_init_boolean.*)
        . = ALIGN(4);
        *(.mcal_data_init_8.*)
        . = ALIGN(4);
        *(.mcal_data_init_16.*)
        . = ALIGN(4);
        *(.mcal_data_init_32.*)
        . = ALIGN(4);
        *(.mcal_data_init_ptr.*)
        . = ALIGN(4);
        *(.mcal_data_init_unspecified.*)
        . = ALIGN(4);
        /* ADD END */
		
 		_GOT_START_ = ABSOLUTE (.);
		*(.got)
		_GOT_END_ = ABSOLUTE (.);

	    __sram_data_end__ = .;
    } > int_sram

    __sram_data_rom_end = __sram_data_rom + (__sram_data_end__ - __sram_data_begin__);
    	
    .sram_bss (NOLOAD) :
    {
        . = ALIGN(16);
        __sram_bss_start = .;
        *(.bss)
        *(.bss*)       
        . = ALIGN(16);
        *(.mcal_bss)       
        . = ALIGN(4);  
		*(.saf_bss)
		
		/* ADD BEGIN */
		. = ALIGN(4);
        *(.mcal_data_cleared_boolean.*)
        . = ALIGN(4);
        *(.mcal_data_cleared_8.*)
        . = ALIGN(4);
        *(.mcal_data_cleared_16.*)
        . = ALIGN(4);
        *(.mcal_data_cleared_32.*)
        . = ALIGN(4);
        *(.mcal_data_cleared_ptr.*)
        . = ALIGN(4);
        *(.mcal_data_cleared_unspecified.*)
		. = ALIGN(4);
        /* ADD END */
		
        __sram_bss_end = .;
    } >int_sram AT>int_sram
   
    __non_cacheable_data_rom = __sram_data_rom_end;

    .non_cacheable_data : AT(__non_cacheable_data_rom)
    {
        . = ALIGN(4);
        __non_cacheable_data_start__ = .;
        *(.mcal_data_no_cacheable)        
        . = ALIGN(4);
        *(.mcal_const_no_cacheable)
		. = ALIGN(4);
        *(.saf_data_no_cacheable)        
        . = ALIGN(4);
        *(.saf_const_no_cacheable)      

        __non_cacheable_data_end__ = .;  
    } > int_sram_no_cacheable
    
    __non_cacheable_data_rom_end = __non_cacheable_data_rom + (__non_cacheable_data_end__ - __non_cacheable_data_start__);

    .non_cacheable_bss (NOLOAD) :
    {  
        . = ALIGN(16);
        __non_cacheable_bss_start = .;
        *(.mcal_bss_no_cacheable)      
        . = ALIGN(4);
		*(.saf_bss_no_cacheable)      
        . = ALIGN(4);
        __non_cacheable_bss_end = .;       
    } > int_sram_no_cacheable AT>int_sram_no_cacheable
	
	__itcm_text_rom_start = __non_cacheable_data_rom_end ;
	
    .itcm_text : AT(__itcm_text_rom_start)
    {
        . = ALIGN(4);
        __interrupts_ram_start = .;
        . += __interrupts_rom_end - __interrupts_rom_start;    
        . = ALIGN(4);
        __interrupts_ram_end = .;
		
		__itcm_text_ram_start__ = .;
        *(.mcal_text_itcm)  
        . = ALIGN(4);
        *(.saf_text_itcm) 	

		/* ADD BEGIN */
		. = ALIGN(4);
        *(.mcal_text_fast.*)
		. = ALIGN(4);
        /* ADD END */
		
        __itcm_text_ram_end__ = .;  
    } > int_itcm
	
	__itcm_text_rom_end = __itcm_text_rom_start + (__itcm_text_ram_end__ - __itcm_text_ram_start__) + (__interrupts_ram_end - __interrupts_ram_start) ;
    __dtcm_data_rom_start = __itcm_text_rom_end ;
	
    .dtcm_data : AT(__dtcm_data_rom_start)
    {
        . = ALIGN(4);
        __dtcm_data_ram_start__ = .;
        *(.mcal_data_dtcm)  
        . = ALIGN(4);
        *(.saf_data_dtcm) 		
		
		/* ADD BEGIN */
		. = ALIGN(4);
        *(.mcal_data_fast_init_boolean.*)
        . = ALIGN(4);
        *(.mcal_data_fast_init_8.*)
        . = ALIGN(4);
        *(.mcal_data_fast_init_16.*)
        . = ALIGN(4);
        *(.mcal_data_fast_init_32.*)
        . = ALIGN(4);
        *(.mcal_data_fast_init_ptr.*)
        . = ALIGN(4);
        *(.mcal_data_fast_init_unspecified.*)
        . = ALIGN(4);
        /* ADD END */

        /* ADD BEGIN */
		. = ALIGN(4);
        *(.mcal_const_fast_boolean.*)
        . = ALIGN(4);
        *(.mcal_const_fast_8.*)
        . = ALIGN(4);
        *(.mcal_const_fast_16.*)
        . = ALIGN(4);
        *(.mcal_const_fast_32.*)
        . = ALIGN(4);
        *(.mcal_const_fast_ptr.*)
        . = ALIGN(4);
        *(.mcal_const_fast_unspecified.*)
		. = ALIGN(4);
        /* ADD END */
		
        __dtcm_data_ram_end__ = .;  
    } > int_dtcm 
	
    __dtcm_data_rom_end = __dtcm_data_rom_start + (__dtcm_data_ram_end__ - __dtcm_data_ram_start__) ;
	
	.dtcm_bss (NOLOAD) :
    {
        . = ALIGN(16);
        __dtcm_bss_start = .;
        *(.mcal_bss_dtcm)
        . = ALIGN(4);
        *(.saf_bss_dtcm)

        /* ADD BEGIN */
		. = ALIGN(4);
        *(.mcal_data_fast_cleared_boolean.*)
        . = ALIGN(4);
        *(.mcal_data_fast_cleared_8.*)
        . = ALIGN(4);
        *(.mcal_data_fast_cleared_16.*)
        . = ALIGN(4);
        *(.mcal_data_fast_cleared_32.*)
        . = ALIGN(4);
        *(.mcal_data_fast_cleared_ptr.*)
        . = ALIGN(4);
        *(.mcal_data_fast_cleared_unspecified.*)
        . = ALIGN(4);
        /* ADD END */

        __dtcm_bss_end = .;
    } >int_dtcm AT>int_dtcm
	
	/* User_heap_stack section, used to check that there is enough RAM left */
	.heap_stack (NOLOAD):
	{
		. = ALIGN(8);
		PROVIDE ( end = . );
		PROVIDE ( _end = . );
		PROVIDE ( _heap_start = . );
		PROVIDE ( __HEAP = . );
		. = . + HEAP_SIZE;
		PROVIDE ( _heap_end = . );
		PROVIDE ( _Heap_Limit = . );
		PROVIDE ( _sstack = . );
		. = . + STACK_SIZE;
		. = ALIGN(8);
   		__Stack_start_c = .;
   		PROVIDE ( _estack = . );
	} >int_dtcm AT>int_dtcm

    __INT_SRAM_START         = ORIGIN(int_sram);
    __INT_SRAM_END           = ORIGIN(ram_end);
    
    __INT_ITCM_START         = ORIGIN(int_itcm);
    __INT_ITCM_END           = ORIGIN(int_itcm) + LENGTH(int_itcm);
    
    __INT_DTCM_START         = ORIGIN(int_dtcm);
    __INT_DTCM_END           = ORIGIN(int_dtcm) + LENGTH(int_dtcm);
     
    __RAM_CACHEABLE_START    = ORIGIN(int_sram);
    __RAM_CACHEABLE_END      = ORIGIN(int_sram_no_cacheable)-1;
    __RAM_CACHEABLE_SIZE     = __RAM_CACHEABLE_END - __RAM_CACHEABLE_START + 1;
    __ROM_CACHEABLE_START    = __sram_data_rom;
    __ROM_CACHEABLE_END      = __sram_data_rom_end;
    
    __RAM_NO_CACHEABLE_START = ORIGIN(int_sram_no_cacheable);
    __RAM_NO_CACHEABLE_END   = ORIGIN(ram_end)-1;
    __RAM_NO_CACHEABLE_SIZE  = __RAM_NO_CACHEABLE_END - __RAM_NO_CACHEABLE_START + 1;
    __ROM_NO_CACHEABLE_START = __non_cacheable_data_rom;
    __ROM_NO_CACHEABLE_END   = __non_cacheable_data_rom_end;

    __RAM_ITCM_START    	 = ORIGIN(int_itcm); 
    __RAM_ITCM_END      	 = ORIGIN(int_itcm) + LENGTH(int_itcm);
    __RAM_ITCM_SIZE          = __RAM_ITCM_END - __RAM_ITCM_START;
    __ROM_ITCM_START    	 = __itcm_text_rom_start;
    __ROM_ITCM_END      	 = __itcm_text_rom_end;
	
    __RAM_DTCM_START    	 = ORIGIN(int_dtcm);
    __RAM_DTCM_END      	 = ORIGIN(int_dtcm) + LENGTH(int_dtcm);
    __RAM_DTCM_SIZE          = __RAM_DTCM_END - __RAM_DTCM_START;
    __ROM_DTCM_START    	 = __dtcm_data_rom_start;
    __ROM_DTCM_END      	 = __dtcm_data_rom_end;
    
    __ROM_CODE_START         = ORIGIN(int_flash);
	__ROM_CODE_END         	 = ORIGIN(int_flash) + LENGTH(int_flash);
	__ROM_CODE_SIZE 		 = __ROM_CODE_END - __ROM_CODE_START;
    __ROM_DATA_START         = 0x01500000; /* DFlash */
	__ROM_DATA_END           = 0x01540000; /* DFlash */
	__ROM_DATA_SIZE 		 = __ROM_DATA_END - __ROM_DATA_START;
    
    PROVIDE ( _stext = ORIGIN(int_flash) );
    PROVIDE ( _etext = ORIGIN(int_flash) + LENGTH(int_flash));
      
    __BSS_SRAM_START         = __sram_bss_start;
    __BSS_SRAM_END           = __sram_bss_end;
    __BSS_SRAM_SIZE          = __sram_bss_end - __sram_bss_start;
    
    __BSS_SRAM_NC_START      = __non_cacheable_bss_start;
    __BSS_SRAM_NC_END        = __non_cacheable_bss_end;
    __BSS_SRAM_NC_SIZE       = __non_cacheable_bss_end - __non_cacheable_bss_start;
	
	__BSS_DTCM_START         = __dtcm_bss_start;
    __BSS_DTCM_END           = __dtcm_bss_end;
    __BSS_DTCM_SIZE          = __dtcm_bss_end - __dtcm_bss_start;
    
    __RAM_INTERRUPT_START    = __interrupts_ram_start;
    __ROM_INTERRUPT_START    = __interrupts_rom_start;
    __ROM_INTERRUPT_END      = __interrupts_rom_end;

	__RETENTION_SIZE_START	 = __retention_sram_begin__;
	__RETENTION_SIZE_END	 = __retention_sram_end__;
	__RETENTION_SIZE		 = __retention_sram_end__ - __retention_sram_begin__;

    __TT_INIT_TABLE          = __tt_init_table;
    __TT_ZERO_TABLE          = __tt_zero_table;
}
