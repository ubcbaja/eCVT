/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: ArduinoTest.c
 *
 * Code generated for Simulink model 'ArduinoTest'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Sun Jan 19 22:37:41 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ArduinoTest.h"
#include "ArduinoTest_private.h"
#include "ArduinoTest_dt.h"

/* Block signals (default storage) */
B_ArduinoTest_T ArduinoTest_B;

/* Block states (default storage) */
DW_ArduinoTest_T ArduinoTest_DW;

/* Real-time model */
RT_MODEL_ArduinoTest_T ArduinoTest_M_;
RT_MODEL_ArduinoTest_T *const ArduinoTest_M = &ArduinoTest_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCod_k(codertarget_arduinobase_block_T *obj);
static void arduino_AnalogInput_set_pinNumb(codertarget_arduinobase_inter_T *obj,
  e_codertarget_arduinobase_int_T *iobj_0);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ArduinoTest_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ArduinoTest_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ArduinoTest_M->Timing.TaskCounters.TID[1])++;
  if ((ArduinoTest_M->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [0.5s, 0.0s] */
    ArduinoTest_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCod_k(codertarget_arduinobase_block_T *obj)
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

/* Model step function for TID0 */
void ArduinoTest_step0(void)           /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  if (ArduinoTest_DW.obj.SampleTime != ArduinoTest_P.AnalogInput_SampleTime) {
    ArduinoTest_DW.obj.SampleTime = ArduinoTest_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(ArduinoTest_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(ArduinoTest_DW.obj.MW_ANALOGIN_HANDLE,
    &ArduinoTest_B.AnalogInput, 3);

  /* End of MATLABSystem: '<Root>/Analog Input' */

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)ArduinoTest_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(ArduinoTest_M)!=-1) &&
        !((rtmGetTFinal(ArduinoTest_M)-ArduinoTest_M->Timing.taskTime0) >
          ArduinoTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ArduinoTest_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ArduinoTest_M)) {
      rtmSetErrorStatus(ArduinoTest_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ArduinoTest_M->Timing.taskTime0 =
    (++ArduinoTest_M->Timing.clockTick0) * ArduinoTest_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void ArduinoTest_step1(void)           /* Sample time: [0.5s, 0.0s] */
{
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */
  ArduinoTest_B.DiscretePulseGenerator = (ArduinoTest_DW.clockTickCounter <
    ArduinoTest_P.DiscretePulseGenerator_Duty) &&
    (ArduinoTest_DW.clockTickCounter >= 0L) ?
    ArduinoTest_P.DiscretePulseGenerator_Amp : 0.0;
  if (ArduinoTest_DW.clockTickCounter >=
      ArduinoTest_P.DiscretePulseGenerator_Period - 1.0) {
    ArduinoTest_DW.clockTickCounter = 0L;
  } else {
    ArduinoTest_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */

  /* MATLABSystem: '<S1>/Digital Output' */
  if (ArduinoTest_DW.obj_j.Protocol != ArduinoTest_P.DigitalOutput_Protocol) {
    ArduinoTest_DW.obj_j.Protocol = ArduinoTest_P.DigitalOutput_Protocol;
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (ArduinoTest_B.DiscretePulseGenerator < 256.0) {
    if (ArduinoTest_B.DiscretePulseGenerator >= 0.0) {
      tmp = (uint8_T)ArduinoTest_B.DiscretePulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* MATLABSystem: '<S1>/Digital Output' */
  writeDigitalPin(2, tmp);
  rtExtModeUpload(1, (real_T)((ArduinoTest_M->Timing.clockTick1) * 0.5));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ArduinoTest_M->Timing.clockTick1++;
}

/* Model initialize function */
void ArduinoTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ArduinoTest_M, 0,
                sizeof(RT_MODEL_ArduinoTest_T));
  rtmSetTFinal(ArduinoTest_M, 10.0);
  ArduinoTest_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ArduinoTest_M->Sizes.checksums[0] = (1447206595U);
  ArduinoTest_M->Sizes.checksums[1] = (2386090648U);
  ArduinoTest_M->Sizes.checksums[2] = (4210088776U);
  ArduinoTest_M->Sizes.checksums[3] = (2701517635U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    ArduinoTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ArduinoTest_M->extModeInfo,
      &ArduinoTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ArduinoTest_M->extModeInfo,
                        ArduinoTest_M->Sizes.checksums);
    rteiSetTPtr(ArduinoTest_M->extModeInfo, rtmGetTPtr(ArduinoTest_M));
  }

  /* block I/O */
  (void) memset(((void *) &ArduinoTest_B), 0,
                sizeof(B_ArduinoTest_T));

  /* states (dwork) */
  (void) memset((void *)&ArduinoTest_DW, 0,
                sizeof(DW_ArduinoTest_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ArduinoTest_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
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
    ArduinoTest_DW.obj.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj.isInitialized = 0L;
    ArduinoTest_DW.obj.SampleTime = -1.0;
    ArduinoTest_DW.obj.matlabCodegenIsDeleted = false;
    arduino_AnalogInput_set_pinNumb(&ArduinoTest_DW.obj, &ArduinoTest_DW.gobj_0);
    ArduinoTest_DW.obj.SampleTime = ArduinoTest_P.AnalogInput_SampleTime;
    obj = &ArduinoTest_DW.obj;
    ArduinoTest_DW.obj.isSetupComplete = false;
    ArduinoTest_DW.obj.isInitialized = 1L;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(0UL);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(ArduinoTest_DW.obj.MW_ANALOGIN_HANDLE,
      trigger_val, 0UL);
    ArduinoTest_DW.obj.isSetupComplete = true;

    /* Start for DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */
    ArduinoTest_DW.clockTickCounter = 0L;

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    ArduinoTest_DW.obj_j.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj_j.isInitialized = 0L;
    ArduinoTest_DW.obj_j.matlabCodegenIsDeleted = false;
    ArduinoTest_DW.obj_j.Protocol = ArduinoTest_P.DigitalOutput_Protocol;
    ArduinoTest_DW.obj_j.isSetupComplete = false;
    ArduinoTest_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(2, true);
    ArduinoTest_DW.obj_j.isSetupComplete = true;
  }
}

/* Model terminate function */
void ArduinoTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlabCodeg(&ArduinoTest_DW.obj);

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  matlabCodegenHandle_matlabCod_k(&ArduinoTest_DW.obj_j);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
