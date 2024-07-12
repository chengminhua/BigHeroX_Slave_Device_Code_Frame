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
**  FILENAME     : Port_Drv_PBcfg.c                                           **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Port Driver Configuration Generated File                   **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.1.0]:                                                                    **
*******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/
/* Include module header file */
#include "Port_Drv.h"

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define PORT_PBCFG_VENDOR_ID_C                      1541
#define PORT_PBCFG_MODULE_ID_C                      124

#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define PORT_PBCFG_AR_RELEASE_REVISION_VERSION_C    0

#define PORT_PBCFG_SW_MAJOR_VERSION_C               1
#define PORT_PBCFG_SW_MINOR_VERSION_C               1
#define PORT_PBCFG_SW_PATCH_VERSION_C               0
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

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h" 
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GTM_TOUT26[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_1,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC01,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = TRUE,
        .PinGtmOutSelect = 26,
        .PinGtmOutSelectFunc = 0,
        .PinDirection = PORT_PIN_OUT
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GTM_TOUT27[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_1,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC01,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = TRUE,
        .PinGtmOutSelect = 27,
        .PinGtmOutSelectFunc = 0,
        .PinDirection = PORT_PIN_OUT
    }
};    


static TT_CONST Port_PinTotalCfgType Port_PinTotalCfg_GTM_TOUT[] =
{
    {
        .PinInitialSelectNumber = 0,
        .PinID = 112,
        .PinDetailCfg = Port_PinModeData_GTM_TOUT26
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 113,
        .PinDetailCfg = Port_PinModeData_GTM_TOUT27
    }
};
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GPIO44[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC00,
        .PinInputPullDownEnable = TRUE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GPIO45[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC00,
        .PinInputPullDownEnable = TRUE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GPIO46[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC00,
        .PinInputPullDownEnable = TRUE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GPIO47[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC00,
        .PinInputPullDownEnable = TRUE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GPIO52[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_1,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC00,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = FALSE,
        .PinDirection = PORT_PIN_OUT
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GPIO53[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_1,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC00,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = FALSE,
        .PinDirection = PORT_PIN_OUT
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GPIO57[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC00,
        .PinInputPullDownEnable = TRUE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_GPIO114[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_1,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC00,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = FALSE,
        .PinDirection = PORT_PIN_OUT
    }
};    


static TT_CONST Port_PinTotalCfgType Port_PinTotalCfg_GPIO[] =
{
    {
        .PinInitialSelectNumber = 0,
        .PinID = 44,
        .PinDetailCfg = Port_PinModeData_GPIO44
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 45,
        .PinDetailCfg = Port_PinModeData_GPIO45
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 46,
        .PinDetailCfg = Port_PinModeData_GPIO46
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 47,
        .PinDetailCfg = Port_PinModeData_GPIO47
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 52,
        .PinDetailCfg = Port_PinModeData_GPIO52
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 53,
        .PinDetailCfg = Port_PinModeData_GPIO53
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 57,
        .PinDetailCfg = Port_PinModeData_GPIO57
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 114,
        .PinDetailCfg = Port_PinModeData_GPIO114
    }
};
static TT_CONST Port_PinDetailCfgType Port_PinModeData_CAN01_RXD[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_CAN01_TXD[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_1,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC03,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = FALSE,
        .PinDirection = PORT_PIN_OUT
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_CAN02_RXD[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_CAN02_TXD[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_1,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC03,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = FALSE,
        .PinDirection = PORT_PIN_OUT
    }
};    


static TT_CONST Port_PinTotalCfgType Port_PinTotalCfg_CAN[] =
{
    {
        .PinInitialSelectNumber = 0,
        .PinID = 2,
        .PinDetailCfg = Port_PinModeData_CAN01_RXD
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 3,
        .PinDetailCfg = Port_PinModeData_CAN01_TXD
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 4,
        .PinDetailCfg = Port_PinModeData_CAN02_RXD
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 5,
        .PinDetailCfg = Port_PinModeData_CAN02_TXD
    }
};
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G1CH2[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G1CH3[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G1CH4[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G1CH5[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G2CH0[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G2CH1[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G2CH2[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G2CH3[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G2CH4[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G3CH3[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_EVADC_G3CH4[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC04,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    


static TT_CONST Port_PinTotalCfgType Port_PinTotalCfg_EVADC[] =
{
    {
        .PinInitialSelectNumber = 0,
        .PinID = 90,
        .PinDetailCfg = Port_PinModeData_EVADC_G1CH2
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 91,
        .PinDetailCfg = Port_PinModeData_EVADC_G1CH3
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 92,
        .PinDetailCfg = Port_PinModeData_EVADC_G1CH4
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 93,
        .PinDetailCfg = Port_PinModeData_EVADC_G1CH5
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 96,
        .PinDetailCfg = Port_PinModeData_EVADC_G2CH0
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 97,
        .PinDetailCfg = Port_PinModeData_EVADC_G2CH1
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 98,
        .PinDetailCfg = Port_PinModeData_EVADC_G2CH2
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 99,
        .PinDetailCfg = Port_PinModeData_EVADC_G2CH3
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 100,
        .PinDetailCfg = Port_PinModeData_EVADC_G2CH4
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 107,
        .PinDetailCfg = Port_PinModeData_EVADC_G3CH3
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 108,
        .PinDetailCfg = Port_PinModeData_EVADC_G3CH4
    }
};
static TT_CONST Port_PinDetailCfgType Port_PinModeData_UART_0_RX[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC07,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = FALSE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_UART_0_TX[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_1,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC06,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = FALSE,
        .PinDirection = PORT_PIN_OUT
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_UART_1_RX[] =
{
    {
        .PinInputEnable = TRUE,
        .PinInputConfigLock    = TRUE,
        .PinModeInputFunction = PORT_PIN_MODE_INPUT_FUNC07,
        .PinInputPullDownEnable = FALSE,
        .PinInputPullUpEnable = TRUE,
        .PinDirection = PORT_PIN_IN
    }
};    
static TT_CONST Port_PinDetailCfgType Port_PinModeData_UART_1_TX[] =
{
    {
        .PinOutputEnable = TRUE,
        .PinOutputFuncLock    = TRUE,
        .PinDriverLevel = PORT_PIN_DRIVER_LEVEL_0,
        .PinModeOutputFunction = PORT_PIN_MODE_OUTPUT_FUNC06,

        .PinOutputModeValue = PORT_PIN_OUTPUT_MODE_PP,
        .PinModeGtmOut = FALSE,
        .PinDirection = PORT_PIN_OUT
    }
};    


static TT_CONST Port_PinTotalCfgType Port_PinTotalCfg_UART[] =
{
    {
        .PinInitialSelectNumber = 0,
        .PinID = 80,
        .PinDetailCfg = Port_PinModeData_UART_0_RX
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 81,
        .PinDetailCfg = Port_PinModeData_UART_0_TX
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 84,
        .PinDetailCfg = Port_PinModeData_UART_1_RX
    },
    {
        .PinInitialSelectNumber = 0,
        .PinID = 85,
        .PinDetailCfg = Port_PinModeData_UART_1_TX
    }
};

static TT_CONST Port_ContainerType Port_ContainerData[] =
{
    {
        .Port_NumberOfPortPins = 2,
        .PinTotalCfg = Port_PinTotalCfg_GTM_TOUT
    },
    {
        .Port_NumberOfPortPins = 8,
        .PinTotalCfg = Port_PinTotalCfg_GPIO
    },
    {
        .Port_NumberOfPortPins = 4,
        .PinTotalCfg = Port_PinTotalCfg_CAN
    },
    {
        .Port_NumberOfPortPins = 11,
        .PinTotalCfg = Port_PinTotalCfg_EVADC
    },
    {
        .Port_NumberOfPortPins = 4,
        .PinTotalCfg = Port_PinTotalCfg_UART
    }
};

TT_CONST Port_ConfigType Port_ConfigData =
{
    .Port_NumberOfContainers = 5,
#if (defined(TT_SAFETY) && (TT_SAFETY == STD_ON))
    .Crc             = 46619U,
#endif
    .Containers = Port_ContainerData
};


#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h" 

/******************************************************************************
*                            Public Variables
*******************************************************************************/

/******************************************************************************
*                            Private Function Declaration
******************************************************************************/

/******************************************************************************
*                            Public Functions
*******************************************************************************/

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus 
}
#endif /* __cplusplus */ 
