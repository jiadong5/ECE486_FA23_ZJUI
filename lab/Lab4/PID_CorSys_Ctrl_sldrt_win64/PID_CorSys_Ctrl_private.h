/*
 * PID_CorSys_Ctrl_private.h
 *
 * Code generation for model "PID_CorSys_Ctrl".
 *
 * Model version              : 1.108
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Tue Nov 21 10:12:12 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PID_CorSys_Ctrl_private_h_
#define RTW_HEADER_PID_CorSys_Ctrl_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void gts_initialize_m(SimStruct *rts);
extern void gts_getpos(SimStruct *rts);
extern void gts_setaccvel(SimStruct *rts);

/* private model entry point functions */
extern void PID_CorSys_Ctrl_derivatives(void);

#endif                                 /* RTW_HEADER_PID_CorSys_Ctrl_private_h_ */
