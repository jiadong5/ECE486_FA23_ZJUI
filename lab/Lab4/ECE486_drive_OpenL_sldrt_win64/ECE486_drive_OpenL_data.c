/*
 * ECE486_drive_OpenL_data.c
 *
 * Code generation for model "ECE486_drive_OpenL".
 *
 * Model version              : 1.133
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Tue Nov 21 10:00:52 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ECE486_drive_OpenL.h"
#include "ECE486_drive_OpenL_private.h"

/* Block parameters (default storage) */
P_ECE486_drive_OpenL_T ECE486_drive_OpenL_P = {
  /* Mask Parameter: Ramp_InitialOutput
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Mask Parameter: SliderGain1_gain
   * Referenced by: '<S4>/Slider Gain'
   */
  -0.6,

  /* Mask Parameter: Ramp_slope
   * Referenced by: '<S1>/Step'
   */
  0.1,

  /* Mask Parameter: Ramp_start
   * Referenced by:
   *   '<S1>/Constant'
   *   '<S1>/Step'
   */
  0.0,

  /* Computed Parameter: GTS400PVsInitialization_P1_Size
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  { 1.0, 1.0 },

  /* Expression: open
   * Referenced by: '<Root>/GTS400-PVs Initialization'
   */
  1.0,

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

  /* Computed Parameter: GTSSetDAC_P1_Size
   * Referenced by: '<Root>/GTS SetDAC'
   */
  { 1.0, 1.0 },

  /* Expression: port
   * Referenced by: '<Root>/GTS SetDAC'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Computed Parameter: GTSGetPos_P1_Size
   * Referenced by: '<Root>/GTS GetPos'
   */
  { 1.0, 1.0 },

  /* Expression: axis
   * Referenced by: '<Root>/GTS GetPos'
   */
  2.0,

  /* Expression: 1/4000*60
   * Referenced by: '<Root>/Gain'
   */
  0.015,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U
};
