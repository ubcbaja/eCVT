/*
 * PotTest.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PotTest".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Tue Feb 25 15:35:22 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PotTest.h"
#include "PotTest_private.h"

/* Block states (default storage) */
DW_PotTest_T PotTest_DW;

/* Real-time model */
RT_MODEL_PotTest_T PotTest_M_;
RT_MODEL_PotTest_T *const PotTest_M = &PotTest_M_;

/* Forward declaration for local functions */
static void arduino_AnalogInput_set_pinNumb(codertarget_arduinobase_inter_T *obj,
  e_codertarget_arduinobase_int_T *iobj_0);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj);
static void arduino_AnalogInput_set_pinNumb(codertarget_arduinobase_inter_T *obj,
  e_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void PotTest_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_AnalogInput;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (PotTest_DW.obj.SampleTime != PotTest_P.AnalogInput_SampleTime) {
    PotTest_DW.obj.SampleTime = PotTest_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(PotTest_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(PotTest_DW.obj.MW_ANALOGIN_HANDLE,
    &rtb_AnalogInput, 3);

  /* End of MATLABSystem: '<Root>/Analog Input' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(PotTest_M->rtwLogInfo, (&PotTest_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(PotTest_M)!=-1) &&
        !((rtmGetTFinal(PotTest_M)-PotTest_M->Timing.taskTime0) >
          PotTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PotTest_M, "Simulation finished");
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
  if (!(++PotTest_M->Timing.clockTick0)) {
    ++PotTest_M->Timing.clockTickH0;
  }

  PotTest_M->Timing.taskTime0 = PotTest_M->Timing.clockTick0 *
    PotTest_M->Timing.stepSize0 + PotTest_M->Timing.clockTickH0 *
    PotTest_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void PotTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PotTest_M, 0,
                sizeof(RT_MODEL_PotTest_T));
  rtmSetTFinal(PotTest_M, -1);
  PotTest_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    PotTest_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PotTest_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PotTest_M->rtwLogInfo, (NULL));
    rtliSetLogT(PotTest_M->rtwLogInfo, "tout");
    rtliSetLogX(PotTest_M->rtwLogInfo, "");
    rtliSetLogXFinal(PotTest_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(PotTest_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(PotTest_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(PotTest_M->rtwLogInfo, 0);
    rtliSetLogDecimation(PotTest_M->rtwLogInfo, 1);
    rtliSetLogY(PotTest_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(PotTest_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(PotTest_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&PotTest_DW, 0,
                sizeof(DW_PotTest_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(PotTest_M->rtwLogInfo, 0.0, rtmGetTFinal
    (PotTest_M), PotTest_M->Timing.stepSize0, (&rtmGetErrorStatus(PotTest_M)));

  {
    codertarget_arduinobase_inter_T *obj;
    MW_AnalogIn_TriggerSource_Type trigger_val;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    PotTest_DW.obj.matlabCodegenIsDeleted = true;
    PotTest_DW.obj.isInitialized = 0;
    PotTest_DW.obj.SampleTime = -1.0;
    PotTest_DW.obj.matlabCodegenIsDeleted = false;
    PotTest_DW.objisempty = true;
    arduino_AnalogInput_set_pinNumb(&PotTest_DW.obj, &PotTest_DW.gobj_0);
    PotTest_DW.obj.SampleTime = PotTest_P.AnalogInput_SampleTime;
    obj = &PotTest_DW.obj;
    PotTest_DW.obj.isSetupComplete = false;
    PotTest_DW.obj.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(2U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(PotTest_DW.obj.MW_ANALOGIN_HANDLE, trigger_val,
      0U);
    PotTest_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void PotTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlabCodeg(&PotTest_DW.obj);
}
