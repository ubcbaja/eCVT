/*
 * ArduinoTest.c
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "ArduinoTest".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Sun Jan 19 22:06:20 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ArduinoTest.h"
#include "ArduinoTest_private.h"

/* Block states (default storage) */
DW_ArduinoTest_T ArduinoTest_DW;

/* Real-time model */
RT_MODEL_ArduinoTest_T ArduinoTest_M_;
RT_MODEL_ArduinoTest_T *const ArduinoTest_M = &ArduinoTest_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void ArduinoTest_step(void)
{
  /* local block i/o variables */
  real_T rtb_DiscretePulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */
  rtb_DiscretePulseGenerator = (ArduinoTest_DW.clockTickCounter <
    ArduinoTest_P.DiscretePulseGenerator_Duty) &&
    (ArduinoTest_DW.clockTickCounter >= 0) ?
    ArduinoTest_P.DiscretePulseGenerator_Amp : 0.0;
  if (ArduinoTest_DW.clockTickCounter >=
      ArduinoTest_P.DiscretePulseGenerator_Period - 1.0) {
    ArduinoTest_DW.clockTickCounter = 0;
  } else {
    ArduinoTest_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */

  /* MATLABSystem: '<S1>/Digital Output' */
  if (ArduinoTest_DW.obj.Protocol != ArduinoTest_P.DigitalOutput_Protocol) {
    ArduinoTest_DW.obj.Protocol = ArduinoTest_P.DigitalOutput_Protocol;
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtb_DiscretePulseGenerator < 256.0) {
    if (rtb_DiscretePulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_DiscretePulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* MATLABSystem: '<S1>/Digital Output' */
  writeDigitalPin(2, tmp);

  /* Matfile logging */
  rt_UpdateTXYLogVars(ArduinoTest_M->rtwLogInfo,
                      (&ArduinoTest_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.5s, 0.0s] */
    if ((rtmGetTFinal(ArduinoTest_M)!=-1) &&
        !((rtmGetTFinal(ArduinoTest_M)-ArduinoTest_M->Timing.taskTime0) >
          ArduinoTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ArduinoTest_M, "Simulation finished");
    }
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
  if (!(++ArduinoTest_M->Timing.clockTick0)) {
    ++ArduinoTest_M->Timing.clockTickH0;
  }

  ArduinoTest_M->Timing.taskTime0 = ArduinoTest_M->Timing.clockTick0 *
    ArduinoTest_M->Timing.stepSize0 + ArduinoTest_M->Timing.clockTickH0 *
    ArduinoTest_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void ArduinoTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ArduinoTest_M, 0,
                sizeof(RT_MODEL_ArduinoTest_T));
  rtmSetTFinal(ArduinoTest_M, 10.0);
  ArduinoTest_M->Timing.stepSize0 = 0.5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ArduinoTest_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ArduinoTest_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ArduinoTest_M->rtwLogInfo, (NULL));
    rtliSetLogT(ArduinoTest_M->rtwLogInfo, "tout");
    rtliSetLogX(ArduinoTest_M->rtwLogInfo, "");
    rtliSetLogXFinal(ArduinoTest_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ArduinoTest_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ArduinoTest_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(ArduinoTest_M->rtwLogInfo, 0);
    rtliSetLogDecimation(ArduinoTest_M->rtwLogInfo, 1);
    rtliSetLogY(ArduinoTest_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ArduinoTest_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ArduinoTest_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&ArduinoTest_DW, 0,
                sizeof(DW_ArduinoTest_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(ArduinoTest_M->rtwLogInfo, 0.0, rtmGetTFinal
    (ArduinoTest_M), ArduinoTest_M->Timing.stepSize0, (&rtmGetErrorStatus
    (ArduinoTest_M)));

  /* Start for DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */
  ArduinoTest_DW.clockTickCounter = 0;

  /* Start for MATLABSystem: '<S1>/Digital Output' */
  ArduinoTest_DW.obj.matlabCodegenIsDeleted = true;
  ArduinoTest_DW.obj.isInitialized = 0;
  ArduinoTest_DW.obj.matlabCodegenIsDeleted = false;
  ArduinoTest_DW.objisempty = true;
  ArduinoTest_DW.obj.Protocol = ArduinoTest_P.DigitalOutput_Protocol;
  ArduinoTest_DW.obj.isSetupComplete = false;
  ArduinoTest_DW.obj.isInitialized = 1;
  digitalIOSetup(2, true);
  ArduinoTest_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void ArduinoTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&ArduinoTest_DW.obj);
}
