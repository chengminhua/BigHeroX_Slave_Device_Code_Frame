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
**  FILENAME     : Gpt_Hw_Types.h                                             **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : GPT Driver Source File                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/
#ifndef GPT_HW_TYPES_H
#define GPT_HW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                            Includes
******************************************************************************/
#include "Gpt_Cfg.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define GPT_HW_TYPES_VENDOR_ID_H                        1541
#define GPT_HW_TYPES_MODULE_ID_H                        100
#define GPT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H         4
#define GPT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H         4
#define GPT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H         0
#define GPT_HW_TYPES_SW_MAJOR_VERSION_H                 1
#define GPT_HW_TYPES_SW_MINOR_VERSION_H                 1
#define GPT_HW_TYPES_SW_PATCH_VERSION_H                 0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* Gpt_Hw_Types.h Gpt_Cfg.h  file version check */
#if (GPT_HW_TYPES_VENDOR_ID_H != GPT_CFG_VENDOR_ID_H)
    #error "Gpt_Hw_Types.h and Gpt_Cfg.h have different vendor id"
#endif

#if (GPT_HW_TYPES_MODULE_ID_H != GPT_CFG_MODULE_ID_H)
    #error "Gpt_Hw_Types.h and Gpt_Cfg.h have different module id"
#endif

#if ((GPT_HW_TYPES_AR_RELEASE_MAJOR_VERSION_H != GPT_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPT_HW_TYPES_AR_RELEASE_MINOR_VERSION_H != GPT_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (GPT_HW_TYPES_AR_RELEASE_PATCH_VERSION_H != GPT_CFG_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of Gpt_Hw_Types.h and Gpt_Cfg.h are different"
#endif

#if ((GPT_HW_TYPES_SW_MAJOR_VERSION_H != GPT_CFG_SW_MAJOR_VERSION_H) || \
     (GPT_HW_TYPES_SW_MINOR_VERSION_H != GPT_CFG_SW_MINOR_VERSION_H) || \
     (GPT_HW_TYPES_SW_PATCH_VERSION_H != GPT_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Gpt_Hw_Types.h and Gpt_Cfg.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
/* Numeric ID of a GPT channel. */
typedef uint8   Gpt_Hw_ChannelType;

/* Type for reading and setting the timer values (in number of ticks). */
typedef uint16  Gpt_Hw_ValueType;

/******************************************************************************
*                            Structures And Typedefs
*******************************************************************************/
/* GPT predef timer configuration for the FTM module */
typedef struct
{
    uint8                   GptFtmModule;           /* FTM module */
    uint16                  GptFtmModRegValue;      /* the MOD register value of the FTM module */
    TT_SCU_CLK_CONTROL_Type GptScuClkControl;       /* The FTM module dynamic clock value of the Scu module */
    TT_SCU_LOCAL_RST_Type   GptScuLocalRst;         /* The FTM module local reset value of the Scu module */
} Gpt_Hw_FtmPredefTimerConfigType;

/* FTM channel configuration for the GPT driver */
typedef struct
{
    uint8                   GptFtmHardwareChannel;   /* The hardware channel of the FTM module */
} Gpt_Hw_FtmChannelConfigType;

/* FTM module configuration for the GPT driver */
typedef struct
{
    uint8 		            GptFtmModule;           /* FTM module */
    uint32                  GptFtmConfRegValue;     /* the CONF register value of the FTM module */
    uint32                  GptFtmScRegValue;       /* the SC register value of the FTM module */
    TT_SCU_CLK_CONTROL_Type GptScuClkControl;       /* The FTM module dynamic clock value of the Scu module */
    TT_SCU_LOCAL_RST_Type   GptScuLocalRst;         /* The FTM module local reset value of the Scu module */
} Gpt_Hw_FtmModuleConfigType;

#ifdef __cplusplus
}
#endif

#endif
