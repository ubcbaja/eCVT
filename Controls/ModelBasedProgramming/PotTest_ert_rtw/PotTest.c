/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PotTest.c
 *
 * Code generated for Simulink model 'PotTest'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Feb 26 15:36:19 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PotTest.h"
#include "PotTest_private.h"
#include "PotTest_dt.h"

/* Block signals (default storage) */
B_PotTest_T PotTest_B;

/* Block states (default storage) */
DW_PotTest_T PotTest_DW;

/* Real-time model */
RT_MODEL_PotTest_T PotTest_M_;
RT_MODEL_PotTest_T *const PotTest_M = &PotTest_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj);
static void arduino_AnalogInput_set_pinNumb(codertarget_arduinobase_inter_T *obj,
  e_codertarget_arduinobase_int_T *iobj_0);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

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

/* Model step function */
void PotTest_step(void)
{
  /* MATLABSystem: '<Root>/Analog Input' */
  if (PotTest_DW.obj.SampleTime != PotTest_P.AnalogInput_SampleTime) {
    PotTest_DW.obj.SampleTime = PotTest_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(PotTest_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(PotTest_DW.obj.MW_ANALOGIN_HANDLE,
    &PotTest_B.AnalogInput, 3);

  /* End of MATLABSystem: '<Root>/Analog Input' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  PotTest_B.scaled = (uint16_T)rt_roundd_snf((real_T)PotTest_B.AnalogInput /
    773.0) * 24U;

  /* Gain: '<Root>/Gain' */
  PotTest_B.Gain = (uint32_T)PotTest_P.Gain_Gain * PotTest_B.AnalogInput;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)PotTest_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(PotTest_M)!=-1) &&
        !((rtmGetTFinal(PotTest_M)-PotTest_M->Timing.taskTime0) >
          PotTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PotTest_M, "Simulation finished");
    }

    if (rtmGetStopRequested(PotTest_M)) {
      rtmSetErrorStatus(PotTest_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PotTest_M->Timing.taskTime0 =
    (++PotTest_M->Timing.clockTick0) * PotTest_M->Timing.stepSize0;
}

/* Model initialize function */
void PotTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)PotTest_M, 0,
                sizeof(RT_MODEL_PotTest_T));
  rtmSetTFinal(PotTest_M, -1);
  PotTest_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  PotTest_M->Sizes.checksums[0] = (2427025948U);
  PotTest_M->Sizes.checksums[1] = (3746487163U);
  PotTest_M->Sizes.checksums[2] = (1374225887U);
  PotTest_M->Sizes.checksums[3] = (2196448037U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    PotTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PotTest_M->extModeInfo,
      &PotTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PotTest_M->extModeInfo, PotTest_M->Sizes.checksums);
    rteiSetTPtr(PotTest_M->extModeInfo, rtmGetTPtr(PotTest_M));
  }

  /* block I/O */
  (void) memset(((void *) &PotTest_B), 0,
                sizeof(B_PotTest_T));

  /* states (dwork) */
  (void) memset((void *)&PotTest_DW, 0,
                sizeof(DW_PotTest_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PotTest_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_inter_T *obj;
    MW_AnalogIn_TriggerSource_Type trigger_val;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    PotTest_DW.obj.matlabCodegenIsDeleted = true;
    PotTest_DW.obj.isInitialized = 0L;
    PotTest_DW.obj.SampleTime = -1.0;
    PotTest_DW.obj.matlabCodegenIsDeleted = false;
    arduino_AnalogInput_set_pinNumb(&PotTest_DW.obj, &PotTest_DW.gobj_0);
    PotTest_DW.obj.SampleTime = PotTest_P.AnalogInput_SampleTime;
    obj = &PotTest_DW.obj;
    PotTest_DW.obj.isSetupComplete = false;
    PotTest_DW.obj.isInitialized = 1L;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(2UL);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(PotTest_DW.obj.MW_ANALOGIN_HANDLE, trigger_val,
      0UL);
    PotTest_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void PotTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlabCodeg(&PotTest_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
