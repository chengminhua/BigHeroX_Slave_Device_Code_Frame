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
**  FILENAME     : vector_table_m7.S                                          **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : vector table Driver Source File                            **
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
.eabi_attribute    		Tag_ABI_align_preserved, 1
.set __Stack_start_c,	Image$$__Stack_start_c$$ZI$$Limit
#endif

  .globl   g_pfnVectors

  .globl   Default_IRQHandler
  .globl   Default_IRQHandler_c
  .type    .text.Default_IRQHandler, %function
Default_IRQHandler:
  bl	   Default_IRQHandler_c

/******************************************************************************
*
* The minimal vector table for a Cortex M3. Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
* 
*******************************************************************************/
  .section .isr_vector,"a",%progbits
  .type    g_pfnVectors, %object
  .size    g_pfnVectors, .-g_pfnVectors
   
g_pfnVectors:
  .word    __Stack_start_c
  .word    Reset_IRQHandler

  .word    NMI_IRQHandler
  .word    HardFault_IRQHandler
  .word    MemManage_IRQHandler
  .word    BusFault_IRQHandler
  .word    UsageFault_IRQHandler
  .word    0
  .word    0
  .word    0
  .word    0
  .word    SVC_IRQHandler
  .word    DebugMon_IRQHandler
  .word    0
  .word    PendSV_IRQHandler
  .word	   SysTick_IRQHandler
  
  /* External Interrupts */
  .word    CTI0_IRQHandler                 	/*   0 */
  .word    CTI1_IRQHandler                 	/*   1 */
  .word    SMU0_IRQHandler                 	/*   2 */
  .word    SHDN_IRQHandler                 	/*   3 */
  .word    ENDINIT_IRQHandler              	/*   4 */
  .word    PMU_IRQHandler                  	/*   5 */
  .word    DFCU_IRQHandler                	/*   6 */
  .word    PFCU_IRQHandler               	/*   7 */
  .word    DEBUG_WAKEUP_IRQHandler         	/*   8 */
  .word    CRC_IRQHandler                  	/*   9 */
  .word    WWDT_IRQHandler                 	/*  10 */
  .word    ADCSENSOR_IRQHandler            	/*  11 */
  .word    MAILBOX_IRQHandler              	/*  12 */
  .word    PKI_IRQHandler                   /*  13 */
  .word    SM4_IRQHandler                   /*  14 */
  .word    HASH_IRQHandler                  /*  15 */
  .word    SKA_IRQHandler                   /*  16 */
  .word    TRNG_IRQHandler                  /*  17 */
  .word    GPDMA0_COMBINE_IRQHandler       	/*  18 */
  .word    GPDMA1_COMBINE_IRQHandler       	/*  19 */
  .word    GPDMA2_COMBINE_IRQHandler       	/*  20 */
  .word    GPDMA3_COMBINE_IRQHandler       	/*  21 */
  .word    PDB0_IRQHandler                 	/*  22 */
  .word    PDB0_ERR_IRQHandler             	/*  23 */
  .word    PDB1_IRQHandler                 	/*  24 */
  .word    PDB1_ERR_IRQHandler             	/*  25 */
  .word    ADC0_IRQHandler                 	/*  26 */
  .word    ADC1_IRQHandler                 	/*  27 */
  .word    ADC2_IRQHandler                 	/*  28 */
  .word    ADC3_IRQHandler                 	/*  29 */
  .word    ADC4_IRQHandler                 	/*  30 */
  .word    ADC5_IRQHandler                 	/*  31 */
  .word    SENT0_IRQHandler                	/*  32 */
  .word    SENT1_IRQHandler                	/*  33 */
  .word    SENT2_IRQHandler                	/*  34 */
  .word    SENT3_IRQHandler                	/*  35 */
  .word    SENT4_IRQHandler                	/*  36 */
  .word    SENT5_IRQHandler                	/*  37 */
  .word    SENT6_IRQHandler                	/*  38 */
  .word    SENT7_IRQHandler                	/*  39 */
  .word    QSPI0_IRQHandler                	/*  40 */
  .word    ENET_LPI_IRQHandler             	/*  41 */
  .word    ENET_SBD_IRQHandler             	/*  42 */
  .word    ENET_PMT_IRQHandler             	/*  43 */
  .word    UART0_COMBINE_IRQHandler       	/*  44 */
  .word    UART1_COMBINE_IRQHandler        	/*  45 */
  .word    UART2_COMBINE_IRQHandler        	/*  46 */
  .word    UART3_COMBINE_IRQHandler        	/*  47 */
  .word    LIN0_IRQHandler                 	/*  48 */
  .word    LIN1_IRQHandler                 	/*  49 */
  .word    LIN2_IRQHandler                 	/*  50 */
  .word    LIN3_IRQHandler                 	/*  51 */
  .word    LIN4_IRQHandler                 	/*  52 */
  .word    LIN5_IRQHandler                 	/*  53 */
  .word    LIN6_IRQHandler                 	/*  54 */
  .word    LIN7_IRQHandler                 	/*  55 */
  .word    LIN8_IRQHandler                 	/*  56 */
  .word    LIN9_IRQHandler                 	/*  57 */
  .word    LIN10_IRQHandler                	/*  58 */
  .word    LIN11_IRQHandler                	/*  59 */
  .word    LIN12_IRQHandler                	/*  60 */
  .word    LIN13_IRQHandler                	/*  61 */
  .word    LIN14_IRQHandler                	/*  62 */
  .word    LIN15_IRQHandler                	/*  63 */
  .word    I2C0_IRQHandler                 	/*  64 */
  .word    I2C1_IRQHandler                 	/*  65 */
  .word    I3C0_IRQHandler                 	/*  66 */
  .word    SSP0_COMBINE_IRQHandler         	/*  67 */
  .word    SSP1_COMBINE_IRQHandler         	/*  68 */
  .word    SSP2_COMBINE_IRQHandler         	/*  69 */
  .word    SSP3_COMBINE_IRQHandler         	/*  70 */
  .word    SSP4_COMBINE_IRQHandler         	/*  71 */
  .word    SSP5_COMBINE_IRQHandler         	/*  72 */
  .word    SSP6_COMBINE_IRQHandler         	/*  73 */
  .word    SSP7_COMBINE_IRQHandler         	/*  74 */
  .word    GPIOA_IRQHandler                	/*  75 */
  .word    GPIOB_IRQHandler                	/*  76 */
  .word    GPIOC_IRQHandler                	/*  77 */
  .word    GPIOD_IRQHandler                	/*  78 */
  .word    GPIOE_IRQHandler                	/*  79 */
  .word    I2S0_IRQHandler                 	/*  80 */
  .word    CAN_Busoff0_IRQHandler          	/*  81 */
  .word    CAN_Error0_IRQHandler           	/*  82 */
  .word    CAN_Mbor0_IRQHandler            	/*  83 */
  .word    CAN_EnhancedRxFifo0_IRQHandler  	/*  84 */
  .word    CAN_TXRX_Warnning0_IRQHandler   	/*  85 */
  .word    CAN_Wakeup0_IRQHandler          	/*  86 */
  .word    CAN_Busoff1_IRQHandler          	/*  87 */
  .word    CAN_Error1_IRQHandler           	/*  88 */
  .word    CAN_Mbor1_IRQHandler            	/*  89 */
  .word    CAN_EnhancedRxFifo1_IRQHandler  	/*  90 */
  .word    CAN_TXRX_Warnning1_IRQHandler   	/*  91 */
  .word    CAN_Wakeup1_IRQHandler          	/*  92 */
  .word    CAN_Busoff2_IRQHandler          	/*  93 */
  .word    CAN_Error2_IRQHandler           	/*  94 */
  .word    CAN_Mbor2_IRQHandler            	/*  95 */
  .word    CAN_EnhancedRxFifo2_IRQHandler  	/*  96 */
  .word    CAN_TXRX_Warnning2_IRQHandler   	/*  97 */
  .word    CAN_Wakeup2_IRQHandler          	/*  98 */
  .word    CAN_Busoff3_IRQHandler          	/*  99 */
  .word    CAN_Error3_IRQHandler           	/*  100 */
  .word    CAN_Mbor3_IRQHandler            	/*  101 */
  .word    CAN_EnhancedRxFifo3_IRQHandler  	/*  102 */
  .word    CAN_TXRX_Warnning3_IRQHandler   	/*  103 */
  .word    CAN_Wakeup3_IRQHandler          	/*  104 */
  .word    CAN_Busoff4_IRQHandler          	/*  105 */
  .word    CAN_Error4_IRQHandler           	/*  106 */
  .word    CAN_Mbor4_IRQHandler            	/*  107 */
  .word    CAN_EnhancedRxFifo4_IRQHandler  	/*  108 */
  .word    CAN_TXRX_Warnning4_IRQHandler   	/*  109 */
  .word    CAN_Wakeup4_IRQHandler          	/*  110 */
  .word    CAN_Busoff5_IRQHandler          	/*  111 */
  .word    CAN_Error5_IRQHandler           	/*  112 */
  .word    CAN_Mbor5_IRQHandler            	/*  113 */
  .word    CAN_EnhancedRxFifo5_IRQHandler  	/*  114 */
  .word    CAN_TXRX_Warnning5_IRQHandler   	/*  115 */
  .word    CAN_Wakeup5_IRQHandler          	/*  116 */
  .word    CAN_Busoff6_IRQHandler          	/*  117 */
  .word    CAN_Error6_IRQHandler           	/*  118 */
  .word    CAN_Mbor6_IRQHandler            	/*  119 */
  .word    CAN_EnhancedRxFifo6_IRQHandler  	/*  120 */
  .word    CAN_TXRX_Warnning6_IRQHandler   	/*  121 */
  .word    CAN_Wakeup6_IRQHandler          	/*  122 */
  .word    CAN_Busoff7_IRQHandler          	/*  123 */
  .word    CAN_Error7_IRQHandler           	/*  124 */
  .word    CAN_Mbor7_IRQHandler            	/*  125 */
  .word    CAN_EnhancedRxFifo7_IRQHandler  	/*  126 */
  .word    CAN_TXRX_Warnning7_IRQHandler   	/*  127 */
  .word    CAN_Wakeup7_IRQHandler          	/*  128 */
  .word    STM0_IRQHandler                  /*  129 */
  .word    STM1_IRQHandler                  /*  130 */
  .word    FTM0_IRQHandler                 	/*  131 */
  .word    FTM1_IRQHandler                 	/*  132 */
  .word    FTM2_IRQHandler                 	/*  133 */
  .word    FTM3_IRQHandler                 	/*  134 */
  .word    FTM4_IRQHandler                 	/*  135 */
  .word    FTM5_IRQHandler                 	/*  136 */
  .word    GTM_ATOM3_IRQHandler           	/*  137 */
  .word    GTM_ATOM2_IRQHandler            	/*  138 */
  .word    GTM_ATOM1_IRQHandler            	/*  139 */
  .word    GTM_ATOM0_IRQHandler            	/*  140 */
  .word    GTM_TIO3_G1_HO_IRQHandler       	/*  141 */
  .word    GTM_TIO3_G1_LO_IRQHandler       	/*  142 */
  .word    GTM_TIO2_G1_HO_IRQHandler      	/*  143 */
  .word    GTM_TIO2_G1_LO_IRQHandler       	/*  144 */
  .word    GTM_TIO1_G1_HO_IRQHandler       	/*  145 */
  .word    GTM_TIO1_G1_LO_IRQHandler       	/*  146 */
  .word    GTM_TIO0_G1_HO_IRQHandler       	/*  147 */
  .word    GTM_TIO0_G1_LO_IRQHandler       	/*  148 */
  .word    GTM_TIO3_G0_HO_IRQHandler       	/*  149 */
  .word    GTM_TIO3_G0_LO_IRQHandler       	/*  150 */
  .word    GTM_TIO2_G0_HO_IRQHandler       	/*  151 */
  .word    GTM_TIO2_G0_LO_IRQHandler       	/*  152 */
  .word    GTM_TIO1_G0_HO_IRQHandler       	/*  153 */
  .word    GTM_TIO1_G0_LO_IRQHandler       	/*  154 */
  .word    GTM_TIO0_G0_HO_IRQHandler       	/*  155 */
  .word    GTM_TIO0_G0_LO_IRQHandler       	/*  156 */
  .word	   GTM_MCS2_S_HO_IRQHandler			/*  157 */
  .word	   GTM_MCS2_S_LO_IRQHandler			/*  158 */
  .word	   GTM_MCS1_S_HO_IRQHandler			/*  159 */
  .word	   GTM_MCS1_S_LO_IRQHandler			/*  160 */
  .word	   GTM_MCS0_S_HO_IRQHandler			/*  161 */
  .word	   GTM_MCS0_S_LO_IRQHandler			/*  162 */
  .word	   GTM_MCS2_HO_IRQHandler			/*  163 */
  .word	   GTM_MCS2_LO_IRQHandler			/*  164 */
  .word	   GTM_MCS1_HO_IRQHandler			/*  165 */
  .word	   GTM_MCS1_LO_IRQHandler			/*  166 */
  .word	   GTM_MCS0_HO_IRQHandler			/*  167 */
  .word	   GTM_MCS0_LO_IRQHandler			/*  168 */
  .word    GTM_PSM0_HO_IRQHandler          	/*  169 */
  .word    GTM_PSM0_LO_IRQHandler          	/*  170 */
  .word    GTM_DPLL_HO_IRQHandler          	/*  171 */
  .word    GTM_DPLL_LO_IRQHandler          	/*  172 */
  .word    GTM_SPE1_IRQHandler             	/*  173 */
  .word    GTM_SPE0_IRQHandler             	/*  174 */
  .word    GTM_CMP_IRQHandler              	/*  175 */
  .word    GTM_BRC_IRQHandler              	/*  176 */
  .word    GTM_ARU_IRQHandler              	/*  177 */
  .word    GTM_AEI_IRQHandler              	/*  178 */
  .word    GTM_ERR_IRQHandler              	/*  179 */
  .word    GTM_TIM0_0_IRQHandler          	/*  180 */
  .word    GTM_TIM0_1_IRQHandler          	/*  181 */
  .word    GTM_TIM0_2_IRQHandler          	/*  182 */
  .word    GTM_TIM0_3_IRQHandler          	/*  183 */
  .word    GTM_TIM0_4_IRQHandler          	/*  184 */
  .word    GTM_TIM0_5_IRQHandler          	/*  185 */
  .word    GTM_TIM0_6_IRQHandler          	/*  186 */
  .word    GTM_TIM0_7_IRQHandler          	/*  187 */
  .word    GTM_TIM1_0_IRQHandler          	/*  188 */
  .word    GTM_TIM1_1_IRQHandler          	/*  189 */
  .word    GTM_TIM1_2_IRQHandler          	/*  190 */
  .word    GTM_TIM1_3_IRQHandler          	/*  191 */
  .word    GTM_TIM1_4_IRQHandler          	/*  192 */
  .word    GTM_TIM1_5_IRQHandler          	/*  193 */
  .word    GTM_TIM1_6_IRQHandler          	/*  194 */
  .word    GTM_TIM1_7_IRQHandler          	/*  195 */
  .word    GTM_TIM2_0_IRQHandler          	/*  196 */
  .word    GTM_TIM2_1_IRQHandler          	/*  197 */
  .word    GTM_TIM2_2_IRQHandler          	/*  198 */
  .word    GTM_TIM2_3_IRQHandler          	/*  199 */
  .word    GTM_TIM2_4_IRQHandler          	/*  200 */
  .word    GTM_TIM2_5_IRQHandler          	/*  201 */
  .word    GTM_TIM2_6_IRQHandler          	/*  202 */
  .word    GTM_TIM2_7_IRQHandler          	/*  203 */
  .word    GTM_TOM0_0_IRQHandler          	/*  204 */
  .word    GTM_TOM0_1_IRQHandler          	/*  205 */
  .word    GTM_TOM0_2_IRQHandler          	/*  206 */
  .word    GTM_TOM0_3_IRQHandler          	/*  207 */
  .word    GTM_TOM0_4_IRQHandler          	/*  208 */
  .word    GTM_TOM0_5_IRQHandler          	/*  209 */
  .word    GTM_TOM0_6_IRQHandler          	/*  210 */
  .word    GTM_TOM0_7_IRQHandler          	/*  211 */
  .word    GTM_TOM1_0_IRQHandler          	/*  212 */
  .word    GTM_TOM1_1_IRQHandler          	/*  213 */
  .word    GTM_TOM1_2_IRQHandler          	/*  214 */
  .word    GTM_TOM1_3_IRQHandler          	/*  215 */
  .word    GTM_TOM1_4_IRQHandler          	/*  216 */
  .word    GTM_TOM1_5_IRQHandler          	/*  217 */
  .word    GTM_TOM1_6_IRQHandler          	/*  218 */
  .word    GTM_TOM1_7_IRQHandler          	/*  219 */
  .word    Default_IRQHandler               /*  220 */
  .word    Default_IRQHandler               /*  221 */
  .word    Default_IRQHandler               /*  222 */
  .word    Default_IRQHandler               /*  223 */
  .word    Default_IRQHandler               /*  224 */
  .word    Default_IRQHandler               /*  225 */
  .word    Default_IRQHandler               /*  226 */
  .word    Default_IRQHandler               /*  227 */
  .word    Default_IRQHandler               /*  228 */
  .word    Default_IRQHandler               /*  229 */
  .word    Default_IRQHandler               /*  230 */
  .word    Default_IRQHandler               /*  231 */
  .word    Default_IRQHandler               /*  232 */
  .word    Default_IRQHandler               /*  233 */
  .word    Default_IRQHandler               /*  234 */
  .word    Default_IRQHandler               /*  235 */
  .word    Default_IRQHandler               /*  236 */
  .word    Default_IRQHandler               /*  237 */
  .word    Default_IRQHandler               /*  238 */
  .word    Default_IRQHandler               /*  239 */

/* Reserve 256 bytes to store the certificate */
  .rept    64
  .word    0xFFFFFFFF
  .endr
/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_IRQHandler.
* As they are weak aliases, any function with the same name will override 
* this definition.
* 
*******************************************************************************/
   .globl     HardFault_IRQHandler_c
   .type 	  HardFault_IRQHandler, %function
   .weak      HardFault_IRQHandler
HardFault_IRQHandler:
   tst		  lr, #4
   ite		  eq
   mrseq	  r0, msp
   mrsne	  r0, psp
   mov		  r1, lr
   ldr		  r2, = HardFault_IRQHandler_c
   bx		  r2

   .weak      CTI0_IRQHandler
   .thumb_set CTI0_IRQHandler,Default_IRQHandler
                  
   .weak      CTI1_IRQHandler
   .thumb_set CTI1_IRQHandler,Default_IRQHandler
               
   .weak      SMU0_IRQHandler
   .thumb_set SMU0_IRQHandler,Default_IRQHandler
            
   .weak      SHDN_IRQHandler
   .thumb_set SHDN_IRQHandler,Default_IRQHandler
            
   .weak      ENDINIT_IRQHandler
   .thumb_set ENDINIT_IRQHandler,Default_IRQHandler
                  
   .weak      PMU_IRQHandler
   .thumb_set PMU_IRQHandler,Default_IRQHandler
                  
   .weak      DFCU_IRQHandler
   .thumb_set DFCU_IRQHandler,Default_IRQHandler
                  
   .weak      PFCU_IRQHandler
   .thumb_set PFCU_IRQHandler,Default_IRQHandler
                     
   .weak      DEBUG_WAKEUP_IRQHandler
   .thumb_set DEBUG_WAKEUP_IRQHandler,Default_IRQHandler
                 
   .weak      CRC_IRQHandler
   .thumb_set CRC_IRQHandler,Default_IRQHandler
                        
   .weak      WWDT_IRQHandler
   .thumb_set WWDT_IRQHandler,Default_IRQHandler
                  
   .weak      ADCSENSOR_IRQHandler
   .thumb_set ADCSENSOR_IRQHandler,Default_IRQHandler
         
   .weak      MAILBOX_IRQHandler
   .thumb_set MAILBOX_IRQHandler,Default_IRQHandler
                  
   .weak      PKI_IRQHandler
   .thumb_set PKI_IRQHandler,Default_IRQHandler
                  
   .weak      SM4_IRQHandler
   .thumb_set SM4_IRQHandler,Default_IRQHandler
                 
   .weak      HASH_IRQHandler
   .thumb_set HASH_IRQHandler,Default_IRQHandler
                  
   .weak      SKA_IRQHandler
   .thumb_set SKA_IRQHandler,Default_IRQHandler
                  
   .weak      TRNG_IRQHandler
   .thumb_set TRNG_IRQHandler,Default_IRQHandler
                  
   .weak      GPDMA0_COMBINE_IRQHandler
   .thumb_set GPDMA0_COMBINE_IRQHandler,Default_IRQHandler
               
   .weak      GPDMA1_COMBINE_IRQHandler
   .thumb_set GPDMA1_COMBINE_IRQHandler,Default_IRQHandler
            
   .weak      GPDMA2_COMBINE_IRQHandler
   .thumb_set GPDMA2_COMBINE_IRQHandler,Default_IRQHandler
                           
   .weak      GPDMA3_COMBINE_IRQHandler
   .thumb_set GPDMA3_COMBINE_IRQHandler,Default_IRQHandler
            
   .weak      PDB0_IRQHandler
   .thumb_set PDB0_IRQHandler,Default_IRQHandler
            
   .weak      PDB0_ERR_IRQHandler
   .thumb_set PDB0_ERR_IRQHandler,Default_IRQHandler
            
   .weak      PDB1_IRQHandler
   .thumb_set PDB1_IRQHandler,Default_IRQHandler
            
   .weak      PDB1_ERR_IRQHandler
   .thumb_set PDB1_ERR_IRQHandler,Default_IRQHandler

   .weak      ADC0_IRQHandler
   .thumb_set ADC0_IRQHandler,Default_IRQHandler
      
   .weak      ADC1_IRQHandler
   .thumb_set ADC1_IRQHandler,Default_IRQHandler
                  
   .weak      ADC2_IRQHandler
   .thumb_set ADC2_IRQHandler,Default_IRQHandler
                  
   .weak      ADC3_IRQHandler
   .thumb_set ADC3_IRQHandler,Default_IRQHandler
                  
   .weak      ADC4_IRQHandler
   .thumb_set ADC4_IRQHandler,Default_IRQHandler
                  
   .weak      ADC5_IRQHandler
   .thumb_set ADC5_IRQHandler,Default_IRQHandler
                     
   .weak      SENT0_IRQHandler
   .thumb_set SENT0_IRQHandler,Default_IRQHandler
                     
   .weak      SENT1_IRQHandler
   .thumb_set SENT1_IRQHandler,Default_IRQHandler
                  
   .weak      SENT2_IRQHandler
   .thumb_set SENT2_IRQHandler,Default_IRQHandler
                           
   .weak      SENT3_IRQHandler
   .thumb_set SENT3_IRQHandler,Default_IRQHandler
                        
   .weak      SENT4_IRQHandler
   .thumb_set SENT4_IRQHandler,Default_IRQHandler
                  
   .weak      SENT5_IRQHandler
   .thumb_set SENT5_IRQHandler,Default_IRQHandler
                     
   .weak      SENT6_IRQHandler
   .thumb_set SENT6_IRQHandler,Default_IRQHandler
                     
   .weak      SENT7_IRQHandler
   .thumb_set SENT7_IRQHandler,Default_IRQHandler
                  
   .weak      QSPI0_IRQHandler
   .thumb_set QSPI0_IRQHandler,Default_IRQHandler
               
   .weak      ENET_LPI_IRQHandler
   .thumb_set ENET_LPI_IRQHandler,Default_IRQHandler
            
   .weak      ENET_SBD_IRQHandler
   .thumb_set ENET_SBD_IRQHandler,Default_IRQHandler
            
   .weak      ENET_PMT_IRQHandler
   .thumb_set ENET_PMT_IRQHandler,Default_IRQHandler
         
   .weak      UART0_COMBINE_IRQHandler
   .thumb_set UART0_COMBINE_IRQHandler,Default_IRQHandler
         
   .weak      UART1_COMBINE_IRQHandler
   .thumb_set UART1_COMBINE_IRQHandler,Default_IRQHandler
      
   .weak      UART2_COMBINE_IRQHandler
   .thumb_set UART2_COMBINE_IRQHandler,Default_IRQHandler
                  
   .weak      UART3_COMBINE_IRQHandler
   .thumb_set UART3_COMBINE_IRQHandler,Default_IRQHandler
                     
   .weak      LIN0_IRQHandler
   .thumb_set LIN0_IRQHandler,Default_IRQHandler
                     
   .weak      LIN1_IRQHandler
   .thumb_set LIN1_IRQHandler,Default_IRQHandler
                     
   .weak      LIN2_IRQHandler
   .thumb_set LIN2_IRQHandler,Default_IRQHandler
                     
   .weak      LIN3_IRQHandler
   .thumb_set LIN3_IRQHandler,Default_IRQHandler
                     
   .weak      LIN4_IRQHandler
   .thumb_set LIN4_IRQHandler,Default_IRQHandler
                  
   .weak      LIN5_IRQHandler
   .thumb_set LIN5_IRQHandler,Default_IRQHandler
                  
   .weak      LIN6_IRQHandler
   .thumb_set LIN6_IRQHandler,Default_IRQHandler
               
   .weak      LIN7_IRQHandler
   .thumb_set LIN7_IRQHandler,Default_IRQHandler
         
   .weak      LIN8_IRQHandler
   .thumb_set LIN8_IRQHandler,Default_IRQHandler
               
   .weak      LIN9_IRQHandler
   .thumb_set LIN9_IRQHandler,Default_IRQHandler
                  
   .weak      LIN10_IRQHandler
   .thumb_set LIN10_IRQHandler,Default_IRQHandler
            
   .weak      LIN11_IRQHandler
   .thumb_set LIN11_IRQHandler,Default_IRQHandler
            
   .weak      LIN12_IRQHandler
   .thumb_set LIN12_IRQHandler,Default_IRQHandler
   
   .weak      LIN13_IRQHandler
   .thumb_set LIN13_IRQHandler,Default_IRQHandler

   .weak      LIN14_IRQHandler
   .thumb_set LIN14_IRQHandler,Default_IRQHandler

   .weak      LIN15_IRQHandler
   .thumb_set LIN15_IRQHandler,Default_IRQHandler
                           
   .weak      I2C0_IRQHandler
   .thumb_set I2C0_IRQHandler,Default_IRQHandler
                           
   .weak      I2C1_IRQHandler
   .thumb_set I2C1_IRQHandler,Default_IRQHandler
                           
   .weak      I3C0_IRQHandler
   .thumb_set I3C0_IRQHandler,Default_IRQHandler
                     
   .weak      SSP0_COMBINE_IRQHandler
   .thumb_set SSP0_COMBINE_IRQHandler,Default_IRQHandler
                  
   .weak      SSP1_COMBINE_IRQHandler
   .thumb_set SSP1_COMBINE_IRQHandler,Default_IRQHandler
                  
   .weak      SSP2_COMBINE_IRQHandler
   .thumb_set SSP2_COMBINE_IRQHandler,Default_IRQHandler
                  
   .weak      SSP3_COMBINE_IRQHandler
   .thumb_set SSP3_COMBINE_IRQHandler,Default_IRQHandler
                        
   .weak      SSP4_COMBINE_IRQHandler
   .thumb_set SSP4_COMBINE_IRQHandler,Default_IRQHandler
                        
   .weak      SSP5_COMBINE_IRQHandler
   .thumb_set SSP5_COMBINE_IRQHandler,Default_IRQHandler
                        
   .weak      SSP6_COMBINE_IRQHandler
   .thumb_set SSP6_COMBINE_IRQHandler,Default_IRQHandler
               
   .weak      SSP7_COMBINE_IRQHandler
   .thumb_set SSP7_COMBINE_IRQHandler,Default_IRQHandler
               
   .weak      GPIOA_IRQHandler
   .thumb_set GPIOA_IRQHandler,Default_IRQHandler
            
   .weak      GPIOB_IRQHandler
   .thumb_set GPIOB_IRQHandler,Default_IRQHandler
                  
   .weak      GPIOC_IRQHandler
   .thumb_set GPIOC_IRQHandler,Default_IRQHandler
                                   
   .weak      GPIOD_IRQHandler
   .thumb_set GPIOD_IRQHandler,Default_IRQHandler

   .weak      GPIOE_IRQHandler
   .thumb_set GPIOE_IRQHandler,Default_IRQHandler

   .weak      I2S0_IRQHandler
   .thumb_set I2S0_IRQHandler,Default_IRQHandler
   
   .weak      CAN_Busoff0_IRQHandler
   .thumb_set CAN_Busoff0_IRQHandler,Default_IRQHandler

   .weak      CAN_Error0_IRQHandler
   .thumb_set CAN_Error0_IRQHandler,Default_IRQHandler

   .weak      CAN_Mbor0_IRQHandler
   .thumb_set CAN_Mbor0_IRQHandler,Default_IRQHandler

   .weak      CAN_EnhancedRxFifo0_IRQHandler
   .thumb_set CAN_EnhancedRxFifo0_IRQHandler,Default_IRQHandler

   .weak      CAN_TXRX_Warnning0_IRQHandler
   .thumb_set CAN_TXRX_Warnning0_IRQHandler,Default_IRQHandler

   .weak      CAN_Wakeup0_IRQHandler
   .thumb_set CAN_Wakeup0_IRQHandler,Default_IRQHandler
   
   .weak      CAN_Busoff1_IRQHandler
   .thumb_set CAN_Busoff1_IRQHandler,Default_IRQHandler

   .weak      CAN_Error1_IRQHandler
   .thumb_set CAN_Error1_IRQHandler,Default_IRQHandler

   .weak      CAN_Mbor1_IRQHandler
   .thumb_set CAN_Mbor1_IRQHandler,Default_IRQHandler

   .weak      CAN_EnhancedRxFifo1_IRQHandler
   .thumb_set CAN_EnhancedRxFifo1_IRQHandler,Default_IRQHandler

   .weak      CAN_TXRX_Warnning1_IRQHandler
   .thumb_set CAN_TXRX_Warnning1_IRQHandler,Default_IRQHandler

   .weak      CAN_Wakeup1_IRQHandler
   .thumb_set CAN_Wakeup1_IRQHandler,Default_IRQHandler

   .weak      CAN_Busoff2_IRQHandler
   .thumb_set CAN_Busoff2_IRQHandler,Default_IRQHandler

   .weak      CAN_Error2_IRQHandler
   .thumb_set CAN_Error2_IRQHandler,Default_IRQHandler

   .weak      CAN_Mbor2_IRQHandler
   .thumb_set CAN_Mbor2_IRQHandler,Default_IRQHandler

   .weak      CAN_EnhancedRxFifo2_IRQHandler
   .thumb_set CAN_EnhancedRxFifo2_IRQHandler,Default_IRQHandler

   .weak      CAN_TXRX_Warnning2_IRQHandler
   .thumb_set CAN_TXRX_Warnning2_IRQHandler,Default_IRQHandler

   .weak      CAN_Wakeup2_IRQHandler
   .thumb_set CAN_Wakeup2_IRQHandler,Default_IRQHandler

   .weak      CAN_Busoff3_IRQHandler
   .thumb_set CAN_Busoff3_IRQHandler,Default_IRQHandler

   .weak      CAN_Error3_IRQHandler
   .thumb_set CAN_Error3_IRQHandler,Default_IRQHandler

   .weak      CAN_Mbor3_IRQHandler
   .thumb_set CAN_Mbor3_IRQHandler,Default_IRQHandler

   .weak      CAN_EnhancedRxFifo3_IRQHandler
   .thumb_set CAN_EnhancedRxFifo3_IRQHandler,Default_IRQHandler

   .weak      CAN_TXRX_Warnning3_IRQHandler
   .thumb_set CAN_TXRX_Warnning3_IRQHandler,Default_IRQHandler

   .weak      CAN_Wakeup3_IRQHandler
   .thumb_set CAN_Wakeup3_IRQHandler,Default_IRQHandler

   .weak      CAN_Busoff4_IRQHandler
   .thumb_set CAN_Busoff4_IRQHandler,Default_IRQHandler

   .weak      CAN_Error4_IRQHandler
   .thumb_set CAN_Error4_IRQHandler,Default_IRQHandler

   .weak      CAN_Mbor4_IRQHandler
   .thumb_set CAN_Mbor4_IRQHandler,Default_IRQHandler

   .weak      CAN_EnhancedRxFifo4_IRQHandler
   .thumb_set CAN_EnhancedRxFifo4_IRQHandler,Default_IRQHandler

   .weak      CAN_TXRX_Warnning4_IRQHandler
   .thumb_set CAN_TXRX_Warnning4_IRQHandler,Default_IRQHandler

   .weak      CAN_Wakeup4_IRQHandler
   .thumb_set CAN_Wakeup4_IRQHandler,Default_IRQHandler

   .weak      CAN_Busoff5_IRQHandler
   .thumb_set CAN_Busoff5_IRQHandler,Default_IRQHandler

   .weak      CAN_Error5_IRQHandler
   .thumb_set CAN_Error5_IRQHandler,Default_IRQHandler

   .weak      CAN_Mbor5_IRQHandler
   .thumb_set CAN_Mbor5_IRQHandler,Default_IRQHandler

   .weak      CAN_EnhancedRxFifo5_IRQHandler
   .thumb_set CAN_EnhancedRxFifo5_IRQHandler,Default_IRQHandler

   .weak      CAN_TXRX_Warnning5_IRQHandler
   .thumb_set CAN_TXRX_Warnning5_IRQHandler,Default_IRQHandler

   .weak      CAN_Wakeup5_IRQHandler
   .thumb_set CAN_Wakeup5_IRQHandler,Default_IRQHandler

   .weak      CAN_Busoff6_IRQHandler
   .thumb_set CAN_Busoff6_IRQHandler,Default_IRQHandler

   .weak      CAN_Error6_IRQHandler
   .thumb_set CAN_Error6_IRQHandler,Default_IRQHandler

   .weak      CAN_Mbor6_IRQHandler
   .thumb_set CAN_Mbor6_IRQHandler,Default_IRQHandler

   .weak      CAN_EnhancedRxFifo6_IRQHandler
   .thumb_set CAN_EnhancedRxFifo6_IRQHandler,Default_IRQHandler

   .weak      CAN_TXRX_Warnning6_IRQHandler
   .thumb_set CAN_TXRX_Warnning6_IRQHandler,Default_IRQHandler

   .weak      CAN_Wakeup6_IRQHandler
   .thumb_set CAN_Wakeup6_IRQHandler,Default_IRQHandler

   .weak      CAN_Busoff7_IRQHandler
   .thumb_set CAN_Busoff7_IRQHandler,Default_IRQHandler

   .weak      CAN_Error7_IRQHandler
   .thumb_set CAN_Error7_IRQHandler,Default_IRQHandler

   .weak      CAN_Mbor7_IRQHandler
   .thumb_set CAN_Mbor7_IRQHandler,Default_IRQHandler

   .weak      CAN_EnhancedRxFifo7_IRQHandler
   .thumb_set CAN_EnhancedRxFifo7_IRQHandler,Default_IRQHandler

   .weak      CAN_TXRX_Warnning7_IRQHandler
   .thumb_set CAN_TXRX_Warnning7_IRQHandler,Default_IRQHandler

   .weak      CAN_Wakeup7_IRQHandler
   .thumb_set CAN_Wakeup7_IRQHandler,Default_IRQHandler

   .weak      STM0_IRQHandler
   .thumb_set STM0_IRQHandler,Default_IRQHandler

   .weak      STM1_IRQHandler
   .thumb_set STM1_IRQHandler,Default_IRQHandler

   .weak      FTM0_IRQHandler
   .thumb_set FTM0_IRQHandler,Default_IRQHandler

   .weak      FTM1_IRQHandler
   .thumb_set FTM1_IRQHandler,Default_IRQHandler

   .weak      FTM2_IRQHandler
   .thumb_set FTM2_IRQHandler,Default_IRQHandler

   .weak      FTM3_IRQHandler
   .thumb_set FTM3_IRQHandler,Default_IRQHandler

   .weak      FTM4_IRQHandler
   .thumb_set FTM4_IRQHandler,Default_IRQHandler

   .weak      FTM5_IRQHandler
   .thumb_set FTM5_IRQHandler,Default_IRQHandler
   
   .weak      GTM_ATOM3_IRQHandler
   .thumb_set GTM_ATOM3_IRQHandler,Default_IRQHandler

   .weak      GTM_ATOM2_IRQHandler
   .thumb_set GTM_ATOM2_IRQHandler,Default_IRQHandler

   .weak      GTM_ATOM1_IRQHandler
   .thumb_set GTM_ATOM1_IRQHandler,Default_IRQHandler

   .weak      GTM_ATOM0_IRQHandler
   .thumb_set GTM_ATOM0_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIO3_G1_HO_IRQHandler
   .thumb_set GTM_TIO3_G1_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO3_G1_LO_IRQHandler
   .thumb_set GTM_TIO3_G1_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO2_G1_HO_IRQHandler
   .thumb_set GTM_TIO2_G1_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO2_G1_LO_IRQHandler
   .thumb_set GTM_TIO2_G1_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO1_G1_HO_IRQHandler
   .thumb_set GTM_TIO1_G1_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO1_G1_LO_IRQHandler
   .thumb_set GTM_TIO1_G1_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO0_G1_HO_IRQHandler
   .thumb_set GTM_TIO0_G1_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO0_G1_LO_IRQHandler
   .thumb_set GTM_TIO0_G1_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO3_G0_HO_IRQHandler
   .thumb_set GTM_TIO3_G0_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO3_G0_LO_IRQHandler
   .thumb_set GTM_TIO3_G0_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO2_G0_HO_IRQHandler
   .thumb_set GTM_TIO2_G0_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO2_G0_LO_IRQHandler
   .thumb_set GTM_TIO2_G0_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO1_G0_HO_IRQHandler
   .thumb_set GTM_TIO1_G0_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO1_G0_LO_IRQHandler
   .thumb_set GTM_TIO1_G0_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO0_G0_HO_IRQHandler
   .thumb_set GTM_TIO0_G0_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_TIO0_G0_LO_IRQHandler
   .thumb_set GTM_TIO0_G0_LO_IRQHandler,Default_IRQHandler
   
   .weak      GTM_MCS2_S_HO_IRQHandler
   .thumb_set GTM_MCS2_S_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS2_S_LO_IRQHandler
   .thumb_set GTM_MCS2_S_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS1_S_HO_IRQHandler
   .thumb_set GTM_MCS1_S_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS1_S_LO_IRQHandler
   .thumb_set GTM_MCS1_S_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS0_S_HO_IRQHandler
   .thumb_set GTM_MCS0_S_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS0_S_LO_IRQHandler
   .thumb_set GTM_MCS0_S_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS2_HO_IRQHandler
   .thumb_set GTM_MCS2_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS2_LO_IRQHandler
   .thumb_set GTM_MCS2_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS1_HO_IRQHandler
   .thumb_set GTM_MCS1_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS1_LO_IRQHandler
   .thumb_set GTM_MCS1_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS0_HO_IRQHandler
   .thumb_set GTM_MCS0_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_MCS0_LO_IRQHandler
   .thumb_set GTM_MCS0_LO_IRQHandler,Default_IRQHandler
   
   .weak      GTM_PSM0_HO_IRQHandler
   .thumb_set GTM_PSM0_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_PSM0_LO_IRQHandler
   .thumb_set GTM_PSM0_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_DPLL_HO_IRQHandler
   .thumb_set GTM_DPLL_HO_IRQHandler,Default_IRQHandler

   .weak      GTM_DPLL_LO_IRQHandler
   .thumb_set GTM_DPLL_LO_IRQHandler,Default_IRQHandler

   .weak      GTM_SPE1_IRQHandler
   .thumb_set GTM_SPE1_IRQHandler,Default_IRQHandler

   .weak      GTM_SPE0_IRQHandler
   .thumb_set GTM_SPE0_IRQHandler,Default_IRQHandler

   .weak      GTM_CMP_IRQHandler
   .thumb_set GTM_CMP_IRQHandler,Default_IRQHandler

   .weak      GTM_BRC_IRQHandler
   .thumb_set GTM_BRC_IRQHandler,Default_IRQHandler

   .weak      GTM_ARU_IRQHandler
   .thumb_set GTM_ARU_IRQHandler,Default_IRQHandler

   .weak      GTM_AEI_IRQHandler
   .thumb_set GTM_AEI_IRQHandler,Default_IRQHandler

   .weak      GTM_ERR_IRQHandler
   .thumb_set GTM_ERR_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM0_0_IRQHandler
   .thumb_set GTM_TIM0_0_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM0_1_IRQHandler
   .thumb_set GTM_TIM0_1_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM0_2_IRQHandler
   .thumb_set GTM_TIM0_2_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM0_3_IRQHandler
   .thumb_set GTM_TIM0_3_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM0_4_IRQHandler
   .thumb_set GTM_TIM0_4_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM0_5_IRQHandler
   .thumb_set GTM_TIM0_5_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM0_6_IRQHandler
   .thumb_set GTM_TIM0_6_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM0_7_IRQHandler
   .thumb_set GTM_TIM0_7_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM1_0_IRQHandler
   .thumb_set GTM_TIM1_0_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM1_1_IRQHandler
   .thumb_set GTM_TIM1_1_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM1_2_IRQHandler
   .thumb_set GTM_TIM1_2_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM1_3_IRQHandler
   .thumb_set GTM_TIM1_3_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM1_4_IRQHandler
   .thumb_set GTM_TIM1_4_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM1_5_IRQHandler
   .thumb_set GTM_TIM1_5_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM1_6_IRQHandler
   .thumb_set GTM_TIM1_6_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM1_7_IRQHandler
   .thumb_set GTM_TIM1_7_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM2_0_IRQHandler
   .thumb_set GTM_TIM2_0_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM2_1_IRQHandler
   .thumb_set GTM_TIM2_1_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM2_2_IRQHandler
   .thumb_set GTM_TIM2_2_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM2_3_IRQHandler
   .thumb_set GTM_TIM2_3_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM2_4_IRQHandler
   .thumb_set GTM_TIM2_4_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TIM2_5_IRQHandler
   .thumb_set GTM_TIM2_5_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM2_6_IRQHandler
   .thumb_set GTM_TIM2_6_IRQHandler,Default_IRQHandler

   .weak      GTM_TIM2_7_IRQHandler
   .thumb_set GTM_TIM2_7_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM0_0_IRQHandler
   .thumb_set GTM_TOM0_0_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TOM0_1_IRQHandler
   .thumb_set GTM_TOM0_1_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM0_2_IRQHandler
   .thumb_set GTM_TOM0_2_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM0_3_IRQHandler
   .thumb_set GTM_TOM0_3_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TOM0_4_IRQHandler
   .thumb_set GTM_TOM0_4_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TOM0_5_IRQHandler
   .thumb_set GTM_TOM0_5_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM0_6_IRQHandler
   .thumb_set GTM_TOM0_6_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM0_7_IRQHandler
   .thumb_set GTM_TOM0_7_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TOM1_0_IRQHandler
   .thumb_set GTM_TOM1_0_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TOM1_1_IRQHandler
   .thumb_set GTM_TOM1_1_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM1_2_IRQHandler
   .thumb_set GTM_TOM1_2_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM1_3_IRQHandler
   .thumb_set GTM_TOM1_3_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TOM1_4_IRQHandler
   .thumb_set GTM_TOM1_4_IRQHandler,Default_IRQHandler
   
   .weak      GTM_TOM1_5_IRQHandler
   .thumb_set GTM_TOM1_5_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM1_6_IRQHandler
   .thumb_set GTM_TOM1_6_IRQHandler,Default_IRQHandler

   .weak      GTM_TOM1_7_IRQHandler
   .thumb_set GTM_TOM1_7_IRQHandler,Default_IRQHandler
