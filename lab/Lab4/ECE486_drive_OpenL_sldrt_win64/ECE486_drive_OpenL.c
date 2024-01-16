/*
 * ECE486_drive_OpenL.c
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
#include "ECE486_drive_OpenL_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_ECE486_drive_OpenL_T ECE486_drive_OpenL_B;

/* Block states (default storage) */
DW_ECE486_drive_OpenL_T ECE486_drive_OpenL_DW;

/* Real-time model */
RT_MODEL_ECE486_drive_OpenL_T ECE486_drive_OpenL_M_;
RT_MODEL_ECE486_drive_OpenL_T *const ECE486_drive_OpenL_M =
  &ECE486_drive_OpenL_M_;

/* Model output function */
void ECE486_drive_OpenL_output(void)
{
  real_T *lastU;
  real_T currentTime_tmp;

  /* S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */

  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (gts_setdac): '<Root>/GTS SetDAC' */

  /* Level2 S-Function Block: '<Root>/GTS SetDAC' (gts_setdac) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Step: '<Root>/Step1' incorporates:
   *  Step: '<S1>/Step'
   */
  currentTime_tmp = ECE486_drive_OpenL_M->Timing.t[0];

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Clock: '<S1>/Clock'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Gain: '<S4>/Slider Gain'
   *  Product: '<S1>/Product'
   *  Step: '<S1>/Step'
   *  Sum: '<S1>/Output'
   *  Sum: '<S1>/Sum'
   */
  if (ECE486_drive_OpenL_P.ManualSwitch_CurrentSetting == 1) {
    /* Step: '<Root>/Step1' */
    if (currentTime_tmp < ECE486_drive_OpenL_P.Step1_Time) {
      currentTime_tmp = ECE486_drive_OpenL_P.Step1_Y0;
    } else {
      currentTime_tmp = ECE486_drive_OpenL_P.Step1_YFinal;
    }

    ECE486_drive_OpenL_B.ManualSwitch = ECE486_drive_OpenL_P.SliderGain1_gain *
      currentTime_tmp;
  } else {
    if (currentTime_tmp < ECE486_drive_OpenL_P.Ramp_start) {
      /* Step: '<S1>/Step' */
      currentTime_tmp = ECE486_drive_OpenL_P.Step_Y0;
    } else {
      /* Step: '<S1>/Step' */
      currentTime_tmp = ECE486_drive_OpenL_P.Ramp_slope;
    }

    ECE486_drive_OpenL_B.ManualSwitch = (ECE486_drive_OpenL_M->Timing.t[0] -
      ECE486_drive_OpenL_P.Ramp_start) * currentTime_tmp +
      ECE486_drive_OpenL_P.Ramp_InitialOutput;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  /* S-Function (gts_getpos): '<Root>/GTS GetPos' */

  /* Level2 S-Function Block: '<Root>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain' */
  ECE486_drive_OpenL_B.Gain = ECE486_drive_OpenL_P.Gain_Gain *
    ECE486_drive_OpenL_B.GTSGetPos;

  /* Derivative: '<Root>/Derivative' */
  if ((ECE486_drive_OpenL_DW.TimeStampA >= ECE486_drive_OpenL_M->Timing.t[0]) &&
      (ECE486_drive_OpenL_DW.TimeStampB >= ECE486_drive_OpenL_M->Timing.t[0])) {
    ECE486_drive_OpenL_B.Derivative = 0.0;
  } else {
    currentTime_tmp = ECE486_drive_OpenL_DW.TimeStampA;
    lastU = &ECE486_drive_OpenL_DW.LastUAtTimeA;
    if (ECE486_drive_OpenL_DW.TimeStampA < ECE486_drive_OpenL_DW.TimeStampB) {
      if (ECE486_drive_OpenL_DW.TimeStampB < ECE486_drive_OpenL_M->Timing.t[0])
      {
        currentTime_tmp = ECE486_drive_OpenL_DW.TimeStampB;
        lastU = &ECE486_drive_OpenL_DW.LastUAtTimeB;
      }
    } else {
      if (ECE486_drive_OpenL_DW.TimeStampA >= ECE486_drive_OpenL_M->Timing.t[0])
      {
        currentTime_tmp = ECE486_drive_OpenL_DW.TimeStampB;
        lastU = &ECE486_drive_OpenL_DW.LastUAtTimeB;
      }
    }

    ECE486_drive_OpenL_B.Derivative = (ECE486_drive_OpenL_B.Gain - *lastU) /
      (ECE486_drive_OpenL_M->Timing.t[0] - currentTime_tmp);
  }

  /* End of Derivative: '<Root>/Derivative' */
}

/* Model update function */
void ECE486_drive_OpenL_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (ECE486_drive_OpenL_DW.TimeStampA == (rtInf)) {
    ECE486_drive_OpenL_DW.TimeStampA = ECE486_drive_OpenL_M->Timing.t[0];
    lastU = &ECE486_drive_OpenL_DW.LastUAtTimeA;
  } else if (ECE486_drive_OpenL_DW.TimeStampB == (rtInf)) {
    ECE486_drive_OpenL_DW.TimeStampB = ECE486_drive_OpenL_M->Timing.t[0];
    lastU = &ECE486_drive_OpenL_DW.LastUAtTimeB;
  } else if (ECE486_drive_OpenL_DW.TimeStampA < ECE486_drive_OpenL_DW.TimeStampB)
  {
    ECE486_drive_OpenL_DW.TimeStampA = ECE486_drive_OpenL_M->Timing.t[0];
    lastU = &ECE486_drive_OpenL_DW.LastUAtTimeA;
  } else {
    ECE486_drive_OpenL_DW.TimeStampB = ECE486_drive_OpenL_M->Timing.t[0];
    lastU = &ECE486_drive_OpenL_DW.LastUAtTimeB;
  }

  *lastU = ECE486_drive_OpenL_B.Gain;

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ECE486_drive_OpenL_M->Timing.clockTick0)) {
    ++ECE486_drive_OpenL_M->Timing.clockTickH0;
  }

  ECE486_drive_OpenL_M->Timing.t[0] = ECE486_drive_OpenL_M->Timing.clockTick0 *
    ECE486_drive_OpenL_M->Timing.stepSize0 +
    ECE486_drive_OpenL_M->Timing.clockTickH0 *
    ECE486_drive_OpenL_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++ECE486_drive_OpenL_M->Timing.clockTick1)) {
      ++ECE486_drive_OpenL_M->Timing.clockTickH1;
    }

    ECE486_drive_OpenL_M->Timing.t[1] = ECE486_drive_OpenL_M->Timing.clockTick1 *
      ECE486_drive_OpenL_M->Timing.stepSize1 +
      ECE486_drive_OpenL_M->Timing.clockTickH1 *
      ECE486_drive_OpenL_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void ECE486_drive_OpenL_initialize(void)
{
  /* Start for S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */
  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (gts_setdac): '<Root>/GTS SetDAC' */
  /* Level2 S-Function Block: '<Root>/GTS SetDAC' (gts_setdac) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (gts_getpos): '<Root>/GTS GetPos' */
  /* Level2 S-Function Block: '<Root>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  ECE486_drive_OpenL_DW.TimeStampA = (rtInf);
  ECE486_drive_OpenL_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void ECE486_drive_OpenL_terminate(void)
{
  /* Terminate for S-Function (gts_initialize_m): '<Root>/GTS400-PVs Initialization' */
  /* Level2 S-Function Block: '<Root>/GTS400-PVs Initialization' (gts_initialize_m) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (gts_setdac): '<Root>/GTS SetDAC' */
  /* Level2 S-Function Block: '<Root>/GTS SetDAC' (gts_setdac) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (gts_getpos): '<Root>/GTS GetPos' */
  /* Level2 S-Function Block: '<Root>/GTS GetPos' (gts_getpos) */
  {
    SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ECE486_drive_OpenL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ECE486_drive_OpenL_update();
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
  ECE486_drive_OpenL_initialize();
}

void MdlTerminate(void)
{
  ECE486_drive_OpenL_terminate();
}

/* Registration function */
RT_MODEL_ECE486_drive_OpenL_T *ECE486_drive_OpenL(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ECE486_drive_OpenL_M, 0,
                sizeof(RT_MODEL_ECE486_drive_OpenL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ECE486_drive_OpenL_M->solverInfo,
                          &ECE486_drive_OpenL_M->Timing.simTimeStep);
    rtsiSetTPtr(&ECE486_drive_OpenL_M->solverInfo, &rtmGetTPtr
                (ECE486_drive_OpenL_M));
    rtsiSetStepSizePtr(&ECE486_drive_OpenL_M->solverInfo,
                       &ECE486_drive_OpenL_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ECE486_drive_OpenL_M->solverInfo, (&rtmGetErrorStatus
      (ECE486_drive_OpenL_M)));
    rtsiSetRTModelPtr(&ECE486_drive_OpenL_M->solverInfo, ECE486_drive_OpenL_M);
  }

  rtsiSetSimTimeStep(&ECE486_drive_OpenL_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ECE486_drive_OpenL_M->solverInfo,"FixedStepDiscrete");
  ECE486_drive_OpenL_M->solverInfoPtr = (&ECE486_drive_OpenL_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ECE486_drive_OpenL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ECE486_drive_OpenL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ECE486_drive_OpenL_M->Timing.sampleTimes =
      (&ECE486_drive_OpenL_M->Timing.sampleTimesArray[0]);
    ECE486_drive_OpenL_M->Timing.offsetTimes =
      (&ECE486_drive_OpenL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ECE486_drive_OpenL_M->Timing.sampleTimes[0] = (0.0);
    ECE486_drive_OpenL_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ECE486_drive_OpenL_M->Timing.offsetTimes[0] = (0.0);
    ECE486_drive_OpenL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ECE486_drive_OpenL_M, &ECE486_drive_OpenL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ECE486_drive_OpenL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ECE486_drive_OpenL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ECE486_drive_OpenL_M, 50.0);
  ECE486_drive_OpenL_M->Timing.stepSize0 = 0.01;
  ECE486_drive_OpenL_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  ECE486_drive_OpenL_M->Sizes.checksums[0] = (1102316243U);
  ECE486_drive_OpenL_M->Sizes.checksums[1] = (1035392534U);
  ECE486_drive_OpenL_M->Sizes.checksums[2] = (229541780U);
  ECE486_drive_OpenL_M->Sizes.checksums[3] = (1516516342U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ECE486_drive_OpenL_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ECE486_drive_OpenL_M->extModeInfo,
      &ECE486_drive_OpenL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ECE486_drive_OpenL_M->extModeInfo,
                        ECE486_drive_OpenL_M->Sizes.checksums);
    rteiSetTPtr(ECE486_drive_OpenL_M->extModeInfo, rtmGetTPtr
                (ECE486_drive_OpenL_M));
  }

  ECE486_drive_OpenL_M->solverInfoPtr = (&ECE486_drive_OpenL_M->solverInfo);
  ECE486_drive_OpenL_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ECE486_drive_OpenL_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ECE486_drive_OpenL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ECE486_drive_OpenL_M->blockIO = ((void *) &ECE486_drive_OpenL_B);
  (void) memset(((void *) &ECE486_drive_OpenL_B), 0,
                sizeof(B_ECE486_drive_OpenL_T));

  /* parameters */
  ECE486_drive_OpenL_M->defaultParam = ((real_T *)&ECE486_drive_OpenL_P);

  /* states (dwork) */
  ECE486_drive_OpenL_M->dwork = ((void *) &ECE486_drive_OpenL_DW);
  (void) memset((void *)&ECE486_drive_OpenL_DW, 0,
                sizeof(DW_ECE486_drive_OpenL_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ECE486_drive_OpenL_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &ECE486_drive_OpenL_M->NonInlinedSFcns.sfcnInfo;
    ECE486_drive_OpenL_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(ECE486_drive_OpenL_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &ECE486_drive_OpenL_M->Sizes.numSampTimes);
    ECE486_drive_OpenL_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (ECE486_drive_OpenL_M)[0]);
    ECE486_drive_OpenL_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (ECE486_drive_OpenL_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,ECE486_drive_OpenL_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(ECE486_drive_OpenL_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(ECE486_drive_OpenL_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (ECE486_drive_OpenL_M));
    rtssSetStepSizePtr(sfcnInfo, &ECE486_drive_OpenL_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(ECE486_drive_OpenL_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &ECE486_drive_OpenL_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &ECE486_drive_OpenL_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &ECE486_drive_OpenL_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &ECE486_drive_OpenL_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &ECE486_drive_OpenL_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &ECE486_drive_OpenL_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &ECE486_drive_OpenL_M->solverInfoPtr);
  }

  ECE486_drive_OpenL_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)&ECE486_drive_OpenL_M->
                  NonInlinedSFcns.childSFunctions[0], 0,
                  3*sizeof(SimStruct));
    ECE486_drive_OpenL_M->childSfunctions =
      (&ECE486_drive_OpenL_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    ECE486_drive_OpenL_M->childSfunctions[0] =
      (&ECE486_drive_OpenL_M->NonInlinedSFcns.childSFunctions[0]);
    ECE486_drive_OpenL_M->childSfunctions[1] =
      (&ECE486_drive_OpenL_M->NonInlinedSFcns.childSFunctions[1]);
    ECE486_drive_OpenL_M->childSfunctions[2] =
      (&ECE486_drive_OpenL_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: ECE486_drive_OpenL/<Root>/GTS400-PVs Initialization (gts_initialize_m) */
    {
      SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &ECE486_drive_OpenL_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, ECE486_drive_OpenL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ECE486_drive_OpenL_M->
                         NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "GTS400-PVs Initialization");
      ssSetPath(rts, "ECE486_drive_OpenL/GTS400-PVs Initialization");
      ssSetRTModel(rts,ECE486_drive_OpenL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 17);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       ECE486_drive_OpenL_P.GTS400PVsInitialization_P17_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &ECE486_drive_OpenL_DW.GTS400PVsInitialization_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ECE486_drive_OpenL_DW.GTS400PVsInitialization_PWORK);
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

    /* Level2 S-Function Block: ECE486_drive_OpenL/<Root>/GTS SetDAC (gts_setdac) */
    {
      SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &ECE486_drive_OpenL_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, ECE486_drive_OpenL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ECE486_drive_OpenL_M->
                         NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &ECE486_drive_OpenL_B.ManualSwitch;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "GTS SetDAC");
      ssSetPath(rts, "ECE486_drive_OpenL/GTS SetDAC");
      ssSetRTModel(rts,ECE486_drive_OpenL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ECE486_drive_OpenL_P.GTSSetDAC_P1_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &ECE486_drive_OpenL_DW.GTSSetDAC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ECE486_drive_OpenL_DW.GTSSetDAC_PWORK);
      }

      /* registration */
      gts_setdac(rts);
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

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ECE486_drive_OpenL/<Root>/GTS GetPos (gts_getpos) */
    {
      SimStruct *rts = ECE486_drive_OpenL_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &ECE486_drive_OpenL_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, ECE486_drive_OpenL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &ECE486_drive_OpenL_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ECE486_drive_OpenL_M->
                         NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &ECE486_drive_OpenL_B.GTSGetPos));
        }
      }

      /* path info */
      ssSetModelName(rts, "GTS GetPos");
      ssSetPath(rts, "ECE486_drive_OpenL/GTS GetPos");
      ssSetRTModel(rts,ECE486_drive_OpenL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ECE486_drive_OpenL_P.GTSGetPos_P1_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &ECE486_drive_OpenL_DW.GTSGetPos_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ECE486_drive_OpenL_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ECE486_drive_OpenL_DW.GTSGetPos_PWORK);
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
  }

  /* Initialize Sizes */
  ECE486_drive_OpenL_M->Sizes.numContStates = (0);/* Number of continuous states */
  ECE486_drive_OpenL_M->Sizes.numY = (0);/* Number of model outputs */
  ECE486_drive_OpenL_M->Sizes.numU = (0);/* Number of model inputs */
  ECE486_drive_OpenL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ECE486_drive_OpenL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ECE486_drive_OpenL_M->Sizes.numBlocks = (19);/* Number of blocks */
  ECE486_drive_OpenL_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  ECE486_drive_OpenL_M->Sizes.numBlockPrms = (81);/* Sum of parameter "widths" */
  return ECE486_drive_OpenL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
