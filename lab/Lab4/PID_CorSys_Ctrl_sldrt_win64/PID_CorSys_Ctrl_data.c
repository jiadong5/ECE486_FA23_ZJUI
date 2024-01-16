/*
 * PID_CorSys_Ctrl_data.c
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

#include "PID_CorSys_Ctrl.h"
#include "PID_CorSys_Ctrl_private.h"

/* Block parameters (default storage) */
P_PID_CorSys_Ctrl_T PID_CorSys_Ctrl_P = {
  /* Mask Parameter: PIDController_Kd
   * Referenced by: '<S1>/Gain2'
   */
  0.0,

  /* Mask Parameter: PIDController_Ki
   * Referenced by: '<S1>/Gain1'
   */
  4.5,

  /* Mask Parameter: PIDController_Kp
   * Referenced by: '<S1>/Gain'
   */
  0.4,

  /* Computed Parameter: GTS400PVsInitialization_P1_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: open
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P2_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: mode
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P3_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 4.0 },

  /* Expression: servo
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 0.0, 1.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P4_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 4.0 },

  /* Expression: aft
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P5_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 3.0 },

  /* Expression: pid1
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P6_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 3.0 },

  /* Expression: pid2
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P7_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 3.0 },

  /* Expression: pid3
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P8_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 3.0 },

  /* Expression: pid4
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: GTS400PVsInitialization_P9_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: enc1
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P10_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: enc2
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  1.0,

  /* Computed Parameter: GTS400PVsInitialization_P11_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: enc3
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P12_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: enc4
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P13_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: lmt1
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P14_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: lmt2
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P15_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: lmt3
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P16_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: lmt4
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P17_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: cdno
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  2.0,

  /* Computed Parameter: GTSGetPos_P1_Size
   * Referenced by: '<S2>/GTS GetPos'
   */
  { 1.0, 1.0 },

  /* Expression: axis
   * Referenced by: '<S2>/GTS GetPos'
   */
  2.0,

  /* Expression: 1/4000*60
   * Referenced by: '<S2>/Gain'
   */
  0.015,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<Root>/Step'
   */
  2000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Computed Parameter: GTSSetAccVel_P1_Size
   * Referenced by: '<S2>/GTS SetAccVel'
   */
  { 1.0, 1.0 },

  /* Expression: Axis
   * Referenced by: '<S2>/GTS SetAccVel'
   */
  2.0,

  /* Computed Parameter: GTSSetAccVel_P2_Size
   * Referenced by: '<S2>/GTS SetAccVel'
   */
  { 1.0, 1.0 },

  /* Expression: vel
   * Referenced by: '<S2>/GTS SetAccVel'
   */
  0.1,

  /* Computed Parameter: GTSSetAccVel_P3_Size
   * Referenced by: '<S2>/GTS SetAccVel'
   */
  { 1.0, 1.0 },

  /* Expression: pos
   * Referenced by: '<S2>/GTS SetAccVel'
   */
  2.5E+11,

  /* Expression: 100
   * Referenced by: '<S2>/Constant'
   */
  100.0,

  /* Expression: 3000
   * Referenced by: '<S2>/Saturation'
   */
  3000.0,

  /* Expression: -3000
   * Referenced by: '<S2>/Saturation'
   */
  -3000.0,

  /* Expression: 1/3000*40*5
   * Referenced by: '<S2>/Gain1'
   */
  0.066666666666666666
};
