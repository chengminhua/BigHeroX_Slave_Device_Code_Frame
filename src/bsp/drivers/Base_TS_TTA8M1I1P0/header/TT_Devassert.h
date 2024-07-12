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
**  FILENAME     : TT_Devassert.h                                             **
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
*                            History                                          ** 
*[V1.1.0]:                                                                    ** 
*******************************************************************************/
#ifndef TT_DEVASSERT_H
#define TT_DEVASSERT_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                       File Version Checks
******************************************************************************/
#if defined(USING_OS_AUTOSAROS)
#include "Det.h"
#endif /* defined(USING_OS_AUTOSAROS) */

#include "TT_DrvError.h"
#include "TT_Compiler.h"
#if defined(UART0_PRINTF) || defined(UART1_PRINTF)
#include <stdio.h>
#endif

/******************************************************************************
*                       Source File Version Information
******************************************************************************/
#define TT_DEVASSERT_VENDOR_ID_H                     1541
#define TT_DEVASSERT_AR_RELEASE_MAJOR_VERSION_H      4
#define TT_DEVASSERT_AR_RELEASE_MINOR_VERSION_H      4
#define TT_DEVASSERT_AR_RELEASE_PATCH_VERSION_H      0
#define TT_DEVASSERT_SW_MAJOR_VERSION_H              1
#define TT_DEVASSERT_SW_MINOR_VERSION_H              1
#define TT_DEVASSERT_SW_PATCH_VERSION_H              0

/******************************************************************************
*                       File Version Checks
******************************************************************************/
/* TT_Devassert.h and TT_DrvError.h file version check */
#if (TT_DEVASSERT_VENDOR_ID_H != TT_DRVERROR_VENDOR_ID_H)
    #error "TT_Devassert.h and TT_DrvError.h have different vendor id"
#endif
#if ((TT_DEVASSERT_AR_RELEASE_MAJOR_VERSION_H != TT_DRVERROR_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_DEVASSERT_AR_RELEASE_MINOR_VERSION_H != TT_DRVERROR_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_DEVASSERT_AR_RELEASE_PATCH_VERSION_H != TT_DRVERROR_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Devassert.h and TT_DrvError.h are different"
#endif
#if ((TT_DEVASSERT_SW_MAJOR_VERSION_H != TT_DRVERROR_SW_MAJOR_VERSION_H) || \
     (TT_DEVASSERT_SW_MINOR_VERSION_H != TT_DRVERROR_SW_MINOR_VERSION_H) || \
     (TT_DEVASSERT_SW_PATCH_VERSION_H != TT_DRVERROR_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Devassert.h and TT_DrvError.h are different"
#endif

/* TT_Devassert.h and TT_Compiler.h file version check */
#if (TT_DEVASSERT_VENDOR_ID_H != TT_COMPILER_VENDOR_ID_H)
    #error "TT_Devassert.h and TT_Compiler.h have different vendor id"
#endif
#if ((TT_DEVASSERT_AR_RELEASE_MAJOR_VERSION_H != TT_COMPILER_AR_RELEASE_MAJOR_VERSION_H) || \
     (TT_DEVASSERT_AR_RELEASE_MINOR_VERSION_H != TT_COMPILER_AR_RELEASE_MINOR_VERSION_H) || \
     (TT_DEVASSERT_AR_RELEASE_PATCH_VERSION_H != TT_COMPILER_AR_RELEASE_PATCH_VERSION_H))
    #error "AutoSar Version Numbers of TT_Devassert.h and TT_Compiler.h are different"
#endif
#if ((TT_DEVASSERT_SW_MAJOR_VERSION_H != TT_COMPILER_SW_MAJOR_VERSION_H) || \
     (TT_DEVASSERT_SW_MINOR_VERSION_H != TT_COMPILER_SW_MINOR_VERSION_H) || \
     (TT_DEVASSERT_SW_PATCH_VERSION_H != TT_COMPILER_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of TT_Devassert.h and TT_Compiler.h are different"
#endif

/******************************************************************************
*                            Defines And Macros
*******************************************************************************/
#if defined(UART0_PRINTF) || defined(UART1_PRINTF)
#if defined(TT_ERR_MSG)
/* Drv err report */
#define TT_DRV_REPORT_ERR(ModuleId, ApiId, Status)                                                      \
        do{                                                                                             \
            (void)printf("Module:%s,ApiId:%d,ErrStatus:%s\r\n",                                         \
                   TT_ModuleIdNameMap[ModuleId],                                                        \
                   ApiId,TT_StatusNameMap[Status]);                                                     \
        }while(0)
/* Drv err report */
#define TT_HW_ERR_REPORT(func, line, ErrId)                                                             \
        do{                                                                                             \
            (void)printf("Func:%s,Line:%d,ErrId:%s\r\n", TT_FUNCTION, line, TT_StatusNameMap[ErrId]);   \
        }while(0)

#else
/* Hw err report */
#define TT_DRV_REPORT_ERR(ModuleId, ApiId, Status)                                                      \
        do{                                                                                             \
            (void)printf("Module:%d,ApiId:%u,ErrStatus:0x%x\r\n", ModuleId, (uint32)ApiId,Status);      \
        }while(0)
#define TT_HW_ERR_REPORT(func, line, ErrId)                                                             \
        do{                                                                                             \
            (void)printf("Func:%s,Line:%d,ErrId:0x%x\r\n", func, line,ErrId);                           \
        }while(0)

#endif
/* Det err report */
#define TT_DET_REPORT_ERR(ModuleId, InstanceId, ApiId, ErrorId)                                         \
        do{                                                                                             \
                (void)printf("Func:%s,Line:%d,ModuleId:%d, InstanceId:%u,ApiId:%u, ErrorId:0x%x\r\n",   \
                        TT_FUNCTION, __LINE__,ModuleId,InstanceId, (uint32)ApiId,ErrorId);              \
                ModuleDet_ReportError(ModuleId, InstanceId, ApiId, ErrorId);                            \
        }while(0)
/* Det err report */
#define TT_DET_REPORT_RUNTIME_ERR(ModuleId, InstanceId, ApiId, ErrorId)                                 \
        do{                                                                                             \
            (void)printf("Func:%s,Line:%d,ModuleId:%d, InstanceId:%d,ApiId:%d, ErrorId:0x%x\r\n",       \
                    TT_FUNCTION, __LINE__,ModuleId,InstanceId, ApiId,ErrorId);                          \
                ModuleDet_ReportRuntimeError(ModuleId, InstanceId, ApiId, ErrorId);                     \
        }while(0)

#define TT_DET_REPORT_TRANS_FAULT(ModuleId, InstanceId, ApiId, ErrorId)                                 \
        do{                                                                                             \
            (void)printf("Func:%s,Line:%d,ModuleId:%d, InstanceId:%d,ApiId:%d, ErrorId:0x%x\r\n",       \
                    TT_FUNCTION, __LINE__,ModuleId,InstanceId, ApiId,ErrorId);                          \
                ModuleDet_ReportTransientFault(ModuleId, InstanceId, ApiId, ErrorId);                   \
        }while(0)

#define TT_ERR_REPORT(ModuleId, ApiId, Condition, ErrorId)                                              \
        do{                                                                                             \
            (void)printf("Func:%s,Line:%d,ModuleId:%d, ApiId:%d,Condition:%d, ErrorId:0x%x\r\n",        \
                    TT_FUNCTION, __LINE__,ModuleId,ApiId, Condition,ErrorId);                           \
                ModuleDet_ReportError(ModuleId, SubModuleId, Condition, ErrorId);                       \
        }while(0)


#else

#define TT_DRV_REPORT_ERR(ModuleId, ApiId, Status)                         {(void)(ModuleId);(void)(ApiId);(void)(Status);}

#define TT_DET_REPORT_ERR(ModuleId, InstanceId, ApiId, ErrorId)             ModuleDet_ReportError(ModuleId, InstanceId, ApiId, ErrorId)

#define TT_DET_REPORT_RUNTIME_ERR(ModuleId, InstanceId, ApiId, ErrorId)     ModuleDet_ReportRuntimeError(ModuleId, InstanceId, ApiId, ErrorId)

#define TT_DET_REPORT_TRANS_FAULT(ModuleId, InstanceId, ApiId, ErrorId)     ModuleDet_ReportTransientFault(ModuleId, InstanceId, ApiId, ErrorId)

#define TT_HW_ERR_REPORT(func, line, ErrId)                                 {(void)(func);(void)(line);(void)(ErrId);}

#endif
#if defined(TT_PERF) && (TT_PERF == STD_OFF)
#define TT_ParaCheck(Expr, ErrId, RetVal)                                   TT_ParaCheckExec(TT_FUNCTION, TT_LINE, (Expr), (ErrId), (RetVal))
#endif
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
*                            Public Prototypes
*******************************************************************************/
#define BASE_START_SEC_CODE_FAST
#include "Base_MemMap.h"

LOCAL_INLINE void ModuleDet_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
#if defined(USING_OS_AUTOSAROS)
    (void)Det_ReportError(ModuleId, InstanceId, ApiId, ErrorId);
#else
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
#endif
}

LOCAL_INLINE void ModuleDet_ReportRuntimeError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId)
{
#if defined(USING_OS_AUTOSAROS)
    (void)Det_ReportRuntimeError(ModuleId,InstanceId,ApiId,ErrorId);
#else
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
#endif
}

LOCAL_INLINE void ModuleDet_ReportTransientFault(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 FaultId)
{
#if defined(USING_OS_AUTOSAROS)
    (void)Det_ReportRuntimeError(ModuleId,InstanceId,ApiId,FaultId);
#else
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)FaultId;
#endif

}


#if defined(TT_PERF) && (TT_PERF == STD_OFF)
LOCAL_INLINE void TT_ParaCheckExec(TT_CONST char *Func, TT_CONST uint32 Line, bool Expr, TT_RetType ErrId, TT_RetType *RetVal)
{
    if ((*RetVal == TT_RET_SUCCESS) && (TRUE == Expr))
    {
#ifdef TT_PCHECK
        TT_HW_ERR_REPORT(Func, Line, ErrId);
#else
        (void)Line;
#endif
        (void)Func;
        *RetVal = ErrId;
    }
    else
    {
        /* nothing */
    }
}
#else
LOCAL_INLINE void TT_ParaCheck(boolean Expr, TT_RetType ErrId, TT_RetType *RetVal)
{
    (void)(Expr);
    (void)(ErrId);
    *(RetVal) = ((uint32)(RetVal) > 1) ? 0U: 1U;
}
#endif

#define BASE_STOP_SEC_CODE_FAST
#include "Base_MemMap.h"

/******************************************************************************
*                            Private Functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* TT_DEVASSERT_H */
