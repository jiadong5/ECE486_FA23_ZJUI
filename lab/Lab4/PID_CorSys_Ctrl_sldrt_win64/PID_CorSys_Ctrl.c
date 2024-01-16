/*
 * PID_CorSys_Ctrl.c
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
#include "PID_CorSys_Ctrl_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_PID_CorSys_Ctrl_T PID_CorSys_Ctrl_B;

/* Continuous states */
X_PID_CorSys_Ctrl_T PID_CorSys_Ctrl_X;

/* Block states (default storage) */
DW_PID_CorSys_Ctrl_T PID_CorSys_Ctrl_DW;

/* Real-time model */
RT_MODEL_PID_CorSys_Ctrl_T PID_CorSys_Ctrl_M_;
RT_MODEL_PID_CorSys_Ctrl_T *const PID_CorSys_Ctrl_M = &PID_CorSys_Ctrl_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  PID_CorSys_Ctrl_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void PID_CorSys_Ctrl_output(void)
{
  real_T *lastU;
  real_T rtb_Saturation;
  real_T rtb_Derivative;
  real_T u0;
  if (rtmIsMajorTimeStep(PID_CorSys_Ctrl_M)) {
    /* set solver stop time */
    if (!(PID_CorSys_Ctrl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PID_CorSys_Ctrl_M->solverInfo,
                            ((PID_CorSys_Ctrl_M->Timing.clockTickH0 + 1) *
        PID_CorSys_Ctrl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PID_CorSys_Ctrl_M->solverInfo,
                            ((PID_CorSys_Ctrl_M->Timing.clockTick0 + 1) *
        PID_CorSys_Ctrl_M->Timing.stepSize0 +
        PID_CorSys_Ctrl_M->Timing.clockTickH0 *
        PID_CorSys_Ctrl_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PID_CorSys_Ctrl_M)) {
    PID_CorSys_Ctrl_M->Timing.t[0] = rtsiGetT(&PID_CorSys_Ctrl_M->solverInfo);
  }

  /* S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */

  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (gts_getpos): '<S2>/GTS GetPos' */

  /* Level2 S-Function Block: '<S2>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S2>/Gain' */
  PID_CorSys_Ctrl_B.Gain = PID_CorSys_Ctrl_P.Gain_Gain *
    PID_CorSys_Ctrl_B.GTSGetPos;

  /* Derivative: '<S2>/Derivative' incorporates:
   *  Derivative: '<S1>/Derivative'
   */
  u0 = PID_CorSys_Ctrl_M->Timing.t[0];
  if ((PID_CorSys_Ctrl_DW.TimeStampA >= u0) && (PID_CorSys_Ctrl_DW.TimeStampB >=
       u0)) {
    PID_CorSys_Ctrl_B.Derivative = 0.0;
  } else {
    rtb_Derivative = PID_CorSys_Ctrl_DW.TimeStampA;
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeA;
    if (PID_CorSys_Ctrl_DW.TimeStampA < PID_CorSys_Ctrl_DW.TimeStampB) {
      if (PID_CorSys_Ctrl_DW.TimeStampB < u0) {
        rtb_Derivative = PID_CorSys_Ctrl_DW.TimeStampB;
        lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeB;
      }
    } else {
      if (PID_CorSys_Ctrl_DW.TimeStampA >= u0) {
        rtb_Derivative = PID_CorSys_Ctrl_DW.TimeStampB;
        lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeB;
      }
    }

    PID_CorSys_Ctrl_B.Derivative = (PID_CorSys_Ctrl_B.Gain - *lastU) / (u0 -
      rtb_Derivative);
  }

  /* End of Derivative: '<S2>/Derivative' */
  if (rtmIsMajorTimeStep(PID_CorSys_Ctrl_M)) {
  }

  /* Step: '<Root>/Step' */
  if (PID_CorSys_Ctrl_M->Timing.t[0] < PID_CorSys_Ctrl_P.Step_Time) {
    rtb_Derivative = PID_CorSys_Ctrl_P.Step_Y0;
  } else {
    rtb_Derivative = PID_CorSys_Ctrl_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Sum: '<Root>/Sum' */
  rtb_Saturation = rtb_Derivative - PID_CorSys_Ctrl_B.Derivative;

  /* Gain: '<S1>/Gain2' */
  PID_CorSys_Ctrl_B.Gain2 = PID_CorSys_Ctrl_P.PIDController_Kd * rtb_Saturation;

  /* Derivative: '<S1>/Derivative' */
  if ((PID_CorSys_Ctrl_DW.TimeStampA_j >= u0) &&
      (PID_CorSys_Ctrl_DW.TimeStampB_m >= u0)) {
    rtb_Derivative = 0.0;
  } else {
    rtb_Derivative = PID_CorSys_Ctrl_DW.TimeStampA_j;
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeA_b;
    if (PID_CorSys_Ctrl_DW.TimeStampA_j < PID_CorSys_Ctrl_DW.TimeStampB_m) {
      if (PID_CorSys_Ctrl_DW.TimeStampB_m < u0) {
        rtb_Derivative = PID_CorSys_Ctrl_DW.TimeStampB_m;
        lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeB_c;
      }
    } else {
      if (PID_CorSys_Ctrl_DW.TimeStampA_j >= u0) {
        rtb_Derivative = PID_CorSys_Ctrl_DW.TimeStampB_m;
        lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeB_c;
      }
    }

    rtb_Derivative = (PID_CorSys_Ctrl_B.Gain2 - *lastU) / (u0 - rtb_Derivative);
  }

  /* Gain: '<S1>/Gain1' */
  PID_CorSys_Ctrl_B.Gain1 = PID_CorSys_Ctrl_P.PIDController_Ki * rtb_Saturation;

  /* S-Function (gts_setaccvel): '<S2>/GTS SetAccVel' */

  /* Level2 S-Function Block: '<S2>/GTS SetAccVel' (gts_setaccvel) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  if (rtmIsMajorTimeStep(PID_CorSys_Ctrl_M)) {
    /* Constant: '<S2>/Constant' */
    PID_CorSys_Ctrl_B.Constant = PID_CorSys_Ctrl_P.Constant_Value;
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Gain'
   *  Integrator: '<S1>/Integrator'
   */
  u0 = (PID_CorSys_Ctrl_P.PIDController_Kp * rtb_Saturation +
        PID_CorSys_Ctrl_X.Integrator_CSTATE) + rtb_Derivative;

  /* Saturate: '<S2>/Saturation' */
  if (u0 > PID_CorSys_Ctrl_P.Saturation_UpperSat) {
    u0 = PID_CorSys_Ctrl_P.Saturation_UpperSat;
  } else {
    if (u0 < PID_CorSys_Ctrl_P.Saturation_LowerSat) {
      u0 = PID_CorSys_Ctrl_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Gain: '<S2>/Gain1' */
  PID_CorSys_Ctrl_B.Gain1_f = PID_CorSys_Ctrl_P.Gain1_Gain * u0;
}

/* Model update function */
void PID_CorSys_Ctrl_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S2>/Derivative' */
  if (PID_CorSys_Ctrl_DW.TimeStampA == (rtInf)) {
    PID_CorSys_Ctrl_DW.TimeStampA = PID_CorSys_Ctrl_M->Timing.t[0];
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeA;
  } else if (PID_CorSys_Ctrl_DW.TimeStampB == (rtInf)) {
    PID_CorSys_Ctrl_DW.TimeStampB = PID_CorSys_Ctrl_M->Timing.t[0];
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeB;
  } else if (PID_CorSys_Ctrl_DW.TimeStampA < PID_CorSys_Ctrl_DW.TimeStampB) {
    PID_CorSys_Ctrl_DW.TimeStampA = PID_CorSys_Ctrl_M->Timing.t[0];
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeA;
  } else {
    PID_CorSys_Ctrl_DW.TimeStampB = PID_CorSys_Ctrl_M->Timing.t[0];
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeB;
  }

  *lastU = PID_CorSys_Ctrl_B.Gain;

  /* End of Update for Derivative: '<S2>/Derivative' */

  /* Update for Derivative: '<S1>/Derivative' */
  if (PID_CorSys_Ctrl_DW.TimeStampA_j == (rtInf)) {
    PID_CorSys_Ctrl_DW.TimeStampA_j = PID_CorSys_Ctrl_M->Timing.t[0];
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeA_b;
  } else if (PID_CorSys_Ctrl_DW.TimeStampB_m == (rtInf)) {
    PID_CorSys_Ctrl_DW.TimeStampB_m = PID_CorSys_Ctrl_M->Timing.t[0];
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeB_c;
  } else if (PID_CorSys_Ctrl_DW.TimeStampA_j < PID_CorSys_Ctrl_DW.TimeStampB_m)
  {
    PID_CorSys_Ctrl_DW.TimeStampA_j = PID_CorSys_Ctrl_M->Timing.t[0];
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeA_b;
  } else {
    PID_CorSys_Ctrl_DW.TimeStampB_m = PID_CorSys_Ctrl_M->Timing.t[0];
    lastU = &PID_CorSys_Ctrl_DW.LastUAtTimeB_c;
  }

  *lastU = PID_CorSys_Ctrl_B.Gain2;

  /* End of Update for Derivative: '<S1>/Derivative' */
  if (rtmIsMajorTimeStep(PID_CorSys_Ctrl_M)) {
    rt_ertODEUpdateContinuousStates(&PID_CorSys_Ctrl_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PID_CorSys_Ctrl_M->Timing.clockTick0)) {
    ++PID_CorSys_Ctrl_M->Timing.clockTickH0;
  }

  PID_CorSys_Ctrl_M->Timing.t[0] = rtsiGetSolverStopTime
    (&PID_CorSys_Ctrl_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PID_CorSys_Ctrl_M->Timing.clockTick1)) {
      ++PID_CorSys_Ctrl_M->Timing.clockTickH1;
    }

    PID_CorSys_Ctrl_M->Timing.t[1] = PID_CorSys_Ctrl_M->Timing.clockTick1 *
      PID_CorSys_Ctrl_M->Timing.stepSize1 +
      PID_CorSys_Ctrl_M->Timing.clockTickH1 *
      PID_CorSys_Ctrl_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void PID_CorSys_Ctrl_derivatives(void)
{
  XDot_PID_CorSys_Ctrl_T *_rtXdot;
  _rtXdot = ((XDot_PID_CorSys_Ctrl_T *) PID_CorSys_Ctrl_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = PID_CorSys_Ctrl_B.Gain1;
}

/* Model initialize function */
void PID_CorSys_Ctrl_initialize(void)
{
  /* Start for S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */
  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (gts_getpos): '<S2>/GTS GetPos' */
  /* Level2 S-Function Block: '<S2>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (gts_setaccvel): '<S2>/GTS SetAccVel' */
  /* Level2 S-Function Block: '<S2>/GTS SetAccVel' (gts_setaccvel) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S2>/Constant' */
  PID_CorSys_Ctrl_B.Constant = PID_CorSys_Ctrl_P.Constant_Value;

  /* InitializeConditions for Derivative: '<S2>/Derivative' */
  PID_CorSys_Ctrl_DW.TimeStampA = (rtInf);
  PID_CorSys_Ctrl_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S1>/Derivative' */
  PID_CorSys_Ctrl_DW.TimeStampA_j = (rtInf);
  PID_CorSys_Ctrl_DW.TimeStampB_m = (rtInf);

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  PID_CorSys_Ctrl_X.Integrator_CSTATE = PID_CorSys_Ctrl_P.Integrator_IC;
}

/* Model terminate function */
void PID_CorSys_Ctrl_terminate(void)
{
  /* Terminate for S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */
  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (gts_getpos): '<S2>/GTS GetPos' */
  /* Level2 S-Function Block: '<S2>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (gts_setaccvel): '<S2>/GTS SetAccVel' */
  /* Level2 S-Function Block: '<S2>/GTS SetAccVel' (gts_setaccvel) */
  {
    SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  PID_CorSys_Ctrl_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  PID_CorSys_Ctrl_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  PID_CorSys_Ctrl_initialize();
}

void MdlTerminate(void)
{
  PID_CorSys_Ctrl_terminate();
}

/* Registration function */
RT_MODEL_PID_CorSys_Ctrl_T *PID_CorSys_Ctrl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PID_CorSys_Ctrl_M, 0,
                sizeof(RT_MODEL_PID_CorSys_Ctrl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PID_CorSys_Ctrl_M->solverInfo,
                          &PID_CorSys_Ctrl_M->Timing.simTimeStep);
    rtsiSetTPtr(&PID_CorSys_Ctrl_M->solverInfo, &rtmGetTPtr(PID_CorSys_Ctrl_M));
    rtsiSetStepSizePtr(&PID_CorSys_Ctrl_M->solverInfo,
                       &PID_CorSys_Ctrl_M->Timing.stepSize0);
    rtsiSetdXPtr(&PID_CorSys_Ctrl_M->solverInfo, &PID_CorSys_Ctrl_M->derivs);
    rtsiSetContStatesPtr(&PID_CorSys_Ctrl_M->solverInfo, (real_T **)
                         &PID_CorSys_Ctrl_M->contStates);
    rtsiSetNumContStatesPtr(&PID_CorSys_Ctrl_M->solverInfo,
      &PID_CorSys_Ctrl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PID_CorSys_Ctrl_M->solverInfo,
      &PID_CorSys_Ctrl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PID_CorSys_Ctrl_M->solverInfo,
      &PID_CorSys_Ctrl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PID_CorSys_Ctrl_M->solverInfo,
      &PID_CorSys_Ctrl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PID_CorSys_Ctrl_M->solverInfo, (&rtmGetErrorStatus
      (PID_CorSys_Ctrl_M)));
    rtsiSetRTModelPtr(&PID_CorSys_Ctrl_M->solverInfo, PID_CorSys_Ctrl_M);
  }

  rtsiSetSimTimeStep(&PID_CorSys_Ctrl_M->solverInfo, MAJOR_TIME_STEP);
  PID_CorSys_Ctrl_M->intgData.f[0] = PID_CorSys_Ctrl_M->odeF[0];
  PID_CorSys_Ctrl_M->contStates = ((real_T *) &PID_CorSys_Ctrl_X);
  rtsiSetSolverData(&PID_CorSys_Ctrl_M->solverInfo, (void *)
                    &PID_CorSys_Ctrl_M->intgData);
  rtsiSetSolverName(&PID_CorSys_Ctrl_M->solverInfo,"ode1");
  PID_CorSys_Ctrl_M->solverInfoPtr = (&PID_CorSys_Ctrl_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PID_CorSys_Ctrl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    PID_CorSys_Ctrl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PID_CorSys_Ctrl_M->Timing.sampleTimes =
      (&PID_CorSys_Ctrl_M->Timing.sampleTimesArray[0]);
    PID_CorSys_Ctrl_M->Timing.offsetTimes =
      (&PID_CorSys_Ctrl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PID_CorSys_Ctrl_M->Timing.sampleTimes[0] = (0.0);
    PID_CorSys_Ctrl_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    PID_CorSys_Ctrl_M->Timing.offsetTimes[0] = (0.0);
    PID_CorSys_Ctrl_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(PID_CorSys_Ctrl_M, &PID_CorSys_Ctrl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PID_CorSys_Ctrl_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    PID_CorSys_Ctrl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PID_CorSys_Ctrl_M, -1);
  PID_CorSys_Ctrl_M->Timing.stepSize0 = 0.01;
  PID_CorSys_Ctrl_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  PID_CorSys_Ctrl_M->Sizes.checksums[0] = (3405305128U);
  PID_CorSys_Ctrl_M->Sizes.checksums[1] = (1596715626U);
  PID_CorSys_Ctrl_M->Sizes.checksums[2] = (2076536340U);
  PID_CorSys_Ctrl_M->Sizes.checksums[3] = (1113548829U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    PID_CorSys_Ctrl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PID_CorSys_Ctrl_M->extModeInfo,
      &PID_CorSys_Ctrl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PID_CorSys_Ctrl_M->extModeInfo,
                        PID_CorSys_Ctrl_M->Sizes.checksums);
    rteiSetTPtr(PID_CorSys_Ctrl_M->extModeInfo, rtmGetTPtr(PID_CorSys_Ctrl_M));
  }

  PID_CorSys_Ctrl_M->solverInfoPtr = (&PID_CorSys_Ctrl_M->solverInfo);
  PID_CorSys_Ctrl_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&PID_CorSys_Ctrl_M->solverInfo, 0.01);
  rtsiSetSolverMode(&PID_CorSys_Ctrl_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PID_CorSys_Ctrl_M->blockIO = ((void *) &PID_CorSys_Ctrl_B);
  (void) memset(((void *) &PID_CorSys_Ctrl_B), 0,
                sizeof(B_PID_CorSys_Ctrl_T));

  /* parameters */
  PID_CorSys_Ctrl_M->defaultParam = ((real_T *)&PID_CorSys_Ctrl_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PID_CorSys_Ctrl_X;
    PID_CorSys_Ctrl_M->contStates = (x);
    (void) memset((void *)&PID_CorSys_Ctrl_X, 0,
                  sizeof(X_PID_CorSys_Ctrl_T));
  }

  /* states (dwork) */
  PID_CorSys_Ctrl_M->dwork = ((void *) &PID_CorSys_Ctrl_DW);
  (void) memset((void *)&PID_CorSys_Ctrl_DW, 0,
                sizeof(DW_PID_CorSys_Ctrl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PID_CorSys_Ctrl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &PID_CorSys_Ctrl_M->NonInlinedSFcns.sfcnInfo;
    PID_CorSys_Ctrl_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(PID_CorSys_Ctrl_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &PID_CorSys_Ctrl_M->Sizes.numSampTimes);
    PID_CorSys_Ctrl_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (PID_CorSys_Ctrl_M)[0]);
    PID_CorSys_Ctrl_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (PID_CorSys_Ctrl_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,PID_CorSys_Ctrl_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(PID_CorSys_Ctrl_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(PID_CorSys_Ctrl_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (PID_CorSys_Ctrl_M));
    rtssSetStepSizePtr(sfcnInfo, &PID_CorSys_Ctrl_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(PID_CorSys_Ctrl_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &PID_CorSys_Ctrl_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &PID_CorSys_Ctrl_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &PID_CorSys_Ctrl_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &PID_CorSys_Ctrl_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &PID_CorSys_Ctrl_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &PID_CorSys_Ctrl_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &PID_CorSys_Ctrl_M->solverInfoPtr);
  }

  PID_CorSys_Ctrl_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)&PID_CorSys_Ctrl_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  3*sizeof(SimStruct));
    PID_CorSys_Ctrl_M->childSfunctions =
      (&PID_CorSys_Ctrl_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    PID_CorSys_Ctrl_M->childSfunctions[0] =
      (&PID_CorSys_Ctrl_M->NonInlinedSFcns.childSFunctions[0]);
    PID_CorSys_Ctrl_M->childSfunctions[1] =
      (&PID_CorSys_Ctrl_M->NonInlinedSFcns.childSFunctions[1]);
    PID_CorSys_Ctrl_M->childSfunctions[2] =
      (&PID_CorSys_Ctrl_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: PID_CorSys_Ctrl/<Root>/GTS400-PVs Initialization (gts_initialize_m) */
    {
      SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &PID_CorSys_Ctrl_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, PID_CorSys_Ctrl_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "GTS400-PVs Initialization");
      ssSetPath(rts, "PID_CorSys_Ctrl/GTS400-PVs Initialization");
      ssSetRTModel(rts,PID_CorSys_Ctrl_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 17);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       PID_CorSys_Ctrl_P.GTS400PVsInitialization_P17_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &PID_CorSys_Ctrl_DW.GTS400PVsInitialization_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &PID_CorSys_Ctrl_DW.GTS400PVsInitialization_PWORK);
      }

      /* registration */
      gts_initialize_m(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: PID_CorSys_Ctrl/<S2>/GTS GetPos (gts_getpos) */
    {
      SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &PID_CorSys_Ctrl_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, PID_CorSys_Ctrl_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &PID_CorSys_Ctrl_B.GTSGetPos));
        }
      }

      /* path info */
      ssSetModelName(rts, "GTS GetPos");
      ssSetPath(rts, "PID_CorSys_Ctrl/RealControl/GTS GetPos");
      ssSetRTModel(rts,PID_CorSys_Ctrl_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)PID_CorSys_Ctrl_P.GTSGetPos_P1_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &PID_CorSys_Ctrl_DW.GTSGetPos_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &PID_CorSys_Ctrl_DW.GTSGetPos_PWORK);
      }

      /* registration */
      gts_getpos(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: PID_CorSys_Ctrl/<S2>/GTS SetAccVel (gts_setaccvel) */
    {
      SimStruct *rts = PID_CorSys_Ctrl_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &PID_CorSys_Ctrl_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, PID_CorSys_Ctrl_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &PID_CorSys_Ctrl_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &PID_CorSys_Ctrl_B.Gain1_f;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &PID_CorSys_Ctrl_B.Constant;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "GTS SetAccVel");
      ssSetPath(rts, "PID_CorSys_Ctrl/RealControl/GTS SetAccVel");
      ssSetRTModel(rts,PID_CorSys_Ctrl_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)PID_CorSys_Ctrl_P.GTSSetAccVel_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)PID_CorSys_Ctrl_P.GTSSetAccVel_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)PID_CorSys_Ctrl_P.GTSSetAccVel_P3_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &PID_CorSys_Ctrl_DW.GTSSetAccVel_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &PID_CorSys_Ctrl_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &PID_CorSys_Ctrl_DW.GTSSetAccVel_PWORK);
      }

      /* registration */
      gts_setaccvel(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  PID_CorSys_Ctrl_M->Sizes.numContStates = (1);/* Number of continuous states */
  PID_CorSys_Ctrl_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  PID_CorSys_Ctrl_M->Sizes.numY = (0); /* Number of model outputs */
  PID_CorSys_Ctrl_M->Sizes.numU = (0); /* Number of model inputs */
  PID_CorSys_Ctrl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PID_CorSys_Ctrl_M->Sizes.numSampTimes = (2);/* Number of sample times */
  PID_CorSys_Ctrl_M->Sizes.numBlocks = (17);/* Number of blocks */
  PID_CorSys_Ctrl_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  PID_CorSys_Ctrl_M->Sizes.numBlockPrms = (89);/* Sum of parameter "widths" */
  return PID_CorSys_Ctrl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
