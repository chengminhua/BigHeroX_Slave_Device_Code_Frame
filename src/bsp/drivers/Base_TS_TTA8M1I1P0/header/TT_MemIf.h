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
**  FILENAME     : TT_MemIf.h                                                 **
**                                                                            **
**  VERSION      : 1.1.0                                                      **
**                                                                            **
**  PLATFORM     : ThinkTech Alioth Series                                    **
**                                                                            **
**  VENDOR       : ThinkTech Technologies                                     **
**                                                                            **
**  DESCRIPTION  : Base Driver Source File                                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/******************************************************************************
*                            History                                          **
*[V1.0.1]:                                                                    **
*******************************************************************************/

#ifndef TT_MEMIF_H
#define TT_MEMIF_H

/******************************************************************************
*                            Private Typedefs
*******************************************************************************/

/******************************************************************************
*                            Private Macros
*******************************************************************************/
#ifdef USING_OS_AUTOSAROS
#include "MemIf.h"

#else


typedef enum
{
/* The underlying abstraction module or device driver has not been initialized  */
    MEMIF_UNINIT = 0,      
/* The underlying abstraction module or device driver is currently idle */
    MEMIF_IDLE,                 
/* The underlying abstraction module or device driver is currently busy */
    MEMIF_BUSY,                 
/* The underlying abstraction module is busy with internal management operations.*/
    MEMIF_BUSY_INTERNAL         
}MemIf_StatusType;

typedef enum
{
/*	The job has been finished successfully */
    MEMIF_JOB_OK = 0,              
/*	The job has not been finished successfully */
    MEMIF_JOB_FAILED,               
/*	The job has not yet been finished */
    MEMIF_JOB_PENDING,              
/*	The job has been canceled */
    MEMIF_JOB_CANCELED,             
/*	The requested block is inconsistent, it may contain corrupted data */
    MEMIF_BLOCK_INCONSISTENT,       
/*	The requested block has been marked as invalid, the requested operation can not be performed */
    MEMIF_BLOCK_INVALID             
}MemIf_JobResultType;


typedef enum
{
/* The underlying memory abstraction modules and drivers are working in slow mode */
    MEMIF_MODE_SLOW = 0,            
/* The underlying memory abstraction modules and drivers are working in fast mode */
    MEMIF_MODE_FAST                 
}MemIf_ModeType;

#endif /* TT_MEMIF_H */


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

/******************************************************************************
*                            Private Functions
******************************************************************************/
#endif
