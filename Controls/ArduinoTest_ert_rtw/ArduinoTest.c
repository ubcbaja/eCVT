/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: ArduinoTest.c
 *
 * Code generated for Simulink model 'ArduinoTest'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Sun Jan 19 23:59:09 2020
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
static void matlabCodegenHandle_matlabCo_ky(codertarget_arduinobase_block_T *obj);
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

static void matlabCodegenHandle_matlabCo_ky(codertarget_arduinobase_block_T *obj)
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
  boolean_T tmp;
  int16_T rtb_y_idx_0;
  int16_T rtb_y_idx_1;
  int16_T rtb_y_idx_2;
  int16_T rtb_y_idx_3;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (ArduinoTest_DW.obj.SampleTime != ArduinoTest_P.AnalogInput1_SampleTime) {
    ArduinoTest_DW.obj.SampleTime = ArduinoTest_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(ArduinoTest_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(ArduinoTest_DW.obj.MW_ANALOGIN_HANDLE,
    &ArduinoTest_B.AnalogInput1, 3);

  /* End of MATLABSystem: '<Root>/Analog Input1' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  tmp = (ArduinoTest_B.AnalogInput1 > 200U);
  if (ArduinoTest_B.AnalogInput1 > 800U) {
    rtb_y_idx_0 = 0;
    rtb_y_idx_1 = 0;
    rtb_y_idx_2 = 0;
    rtb_y_idx_3 = 1;
  } else if (ArduinoTest_B.AnalogInput1 > 600U) {
    rtb_y_idx_0 = 0;
    rtb_y_idx_1 = 0;
    rtb_y_idx_2 = 1;
    rtb_y_idx_3 = 1;
  } else if (ArduinoTest_B.AnalogInput1 > 400U) {
    rtb_y_idx_0 = 0;
    rtb_y_idx_1 = 1;
    rtb_y_idx_2 = 1;
    rtb_y_idx_3 = 1;
  } else {
    rtb_y_idx_0 = tmp;
    rtb_y_idx_1 = tmp;
    rtb_y_idx_2 = tmp;
    rtb_y_idx_3 = tmp;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLABSystem: '<S2>/Digital Output' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  if (ArduinoTest_DW.obj_i.Protocol != ArduinoTest_P.DigitalOutput_Protocol_l) {
    ArduinoTest_DW.obj_i.Protocol = ArduinoTest_P.DigitalOutput_Protocol_l;
  }

  writeDigitalPin(2, (uint8_T)rtb_y_idx_0);

  /* End of MATLABSystem: '<S2>/Digital Output' */

  /* MATLABSystem: '<S3>/Digital Output' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  if (ArduinoTest_DW.obj_d.Protocol != ArduinoTest_P.DigitalOutput_Protocol_a) {
    ArduinoTest_DW.obj_d.Protocol = ArduinoTest_P.DigitalOutput_Protocol_a;
  }

  writeDigitalPin(3, (uint8_T)rtb_y_idx_1);

  /* End of MATLABSystem: '<S3>/Digital Output' */

  /* MATLABSystem: '<S4>/Digital Output' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   */
  if (ArduinoTest_DW.obj_g.Protocol != ArduinoTest_P.DigitalOutput_Protocol_h) {
    ArduinoTest_DW.obj_g.Protocol = ArduinoTest_P.DigitalOutput_Protocol_h;
  }

  writeDigitalPin(4, (uint8_T)rtb_y_idx_2);

  /* End of MATLABSystem: '<S4>/Digital Output' */

  /* MATLABSystem: '<S5>/Digital Output' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  if (ArduinoTest_DW.obj_n.Protocol != ArduinoTest_P.DigitalOutput_Protocol_o) {
    ArduinoTest_DW.obj_n.Protocol = ArduinoTest_P.DigitalOutput_Protocol_o;
  }

  writeDigitalPin(5, (uint8_T)rtb_y_idx_3);

  /* End of MATLABSystem: '<S5>/Digital Output' */

  /* MATLABSystem: '<Root>/Analog Input' */
  if (ArduinoTest_DW.obj_l.SampleTime != ArduinoTest_P.AnalogInput_SampleTime) {
    ArduinoTest_DW.obj_l.SampleTime = ArduinoTest_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(ArduinoTest_DW.obj_l.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(ArduinoTest_DW.obj_l.MW_ANALOGIN_HANDLE,
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
  real_T rtb_DiscretePulseGenerator;
  uint8_T rtb_DiscretePulseGenerator_0;

  /* DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */
  rtb_DiscretePulseGenerator = (ArduinoTest_DW.clockTickCounter <
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
  if (rtb_DiscretePulseGenerator < 256.0) {
    if (rtb_DiscretePulseGenerator >= 0.0) {
      rtb_DiscretePulseGenerator_0 = (uint8_T)rtb_DiscretePulseGenerator;
    } else {
      rtb_DiscretePulseGenerator_0 = 0U;
    }
  } else {
    rtb_DiscretePulseGenerator_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* MATLABSystem: '<S1>/Digital Output' */
  writeDigitalPin(6, rtb_DiscretePulseGenerator_0);
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
  rtmSetTFinal(ArduinoTest_M, -1);
  ArduinoTest_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ArduinoTest_M->Sizes.checksums[0] = (2800686061U);
  ArduinoTest_M->Sizes.checksums[1] = (1376655369U);
  ArduinoTest_M->Sizes.checksums[2] = (2550940591U);
  ArduinoTest_M->Sizes.checksums[3] = (3288274118U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    ArduinoTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
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

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    ArduinoTest_DW.obj.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj.isInitialized = 0L;
    ArduinoTest_DW.obj.SampleTime = -1.0;
    ArduinoTest_DW.obj.matlabCodegenIsDeleted = false;
    arduino_AnalogInput_set_pinNumb(&ArduinoTest_DW.obj, &ArduinoTest_DW.gobj_0);
    ArduinoTest_DW.obj.SampleTime = ArduinoTest_P.AnalogInput1_SampleTime;
    obj = &ArduinoTest_DW.obj;
    ArduinoTest_DW.obj.isSetupComplete = false;
    ArduinoTest_DW.obj.isInitialized = 1L;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(2UL);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(ArduinoTest_DW.obj.MW_ANALOGIN_HANDLE,
      trigger_val, 0UL);
    ArduinoTest_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Output' */
    ArduinoTest_DW.obj_i.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj_i.isInitialized = 0L;
    ArduinoTest_DW.obj_i.matlabCodegenIsDeleted = false;
    ArduinoTest_DW.obj_i.Protocol = ArduinoTest_P.DigitalOutput_Protocol_l;
    ArduinoTest_DW.obj_i.isSetupComplete = false;
    ArduinoTest_DW.obj_i.isInitialized = 1L;
    digitalIOSetup(2, true);
    ArduinoTest_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    ArduinoTest_DW.obj_d.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj_d.isInitialized = 0L;
    ArduinoTest_DW.obj_d.matlabCodegenIsDeleted = false;
    ArduinoTest_DW.obj_d.Protocol = ArduinoTest_P.DigitalOutput_Protocol_a;
    ArduinoTest_DW.obj_d.isSetupComplete = false;
    ArduinoTest_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(3, true);
    ArduinoTest_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    ArduinoTest_DW.obj_g.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj_g.isInitialized = 0L;
    ArduinoTest_DW.obj_g.matlabCodegenIsDeleted = false;
    ArduinoTest_DW.obj_g.Protocol = ArduinoTest_P.DigitalOutput_Protocol_h;
    ArduinoTest_DW.obj_g.isSetupComplete = false;
    ArduinoTest_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(4, true);
    ArduinoTest_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    ArduinoTest_DW.obj_n.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj_n.isInitialized = 0L;
    ArduinoTest_DW.obj_n.matlabCodegenIsDeleted = false;
    ArduinoTest_DW.obj_n.Protocol = ArduinoTest_P.DigitalOutput_Protocol_o;
    ArduinoTest_DW.obj_n.isSetupComplete = false;
    ArduinoTest_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(5, true);
    ArduinoTest_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    ArduinoTest_DW.obj_l.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj_l.isInitialized = 0L;
    ArduinoTest_DW.obj_l.SampleTime = -1.0;
    ArduinoTest_DW.obj_l.matlabCodegenIsDeleted = false;
    arduino_AnalogInput_set_pinNumb(&ArduinoTest_DW.obj_l,
      &ArduinoTest_DW.gobj_0_n);
    ArduinoTest_DW.obj_l.SampleTime = ArduinoTest_P.AnalogInput_SampleTime;
    obj = &ArduinoTest_DW.obj_l;
    ArduinoTest_DW.obj_l.isSetupComplete = false;
    ArduinoTest_DW.obj_l.isInitialized = 1L;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(0UL);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(ArduinoTest_DW.obj_l.MW_ANALOGIN_HANDLE,
      trigger_val, 0UL);
    ArduinoTest_DW.obj_l.isSetupComplete = true;

    /* Start for DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */
    ArduinoTest_DW.clockTickCounter = 0L;

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    ArduinoTest_DW.obj_j.matlabCodegenIsDeleted = true;
    ArduinoTest_DW.obj_j.isInitialized = 0L;
    ArduinoTest_DW.obj_j.matlabCodegenIsDeleted = false;
    ArduinoTest_DW.obj_j.Protocol = ArduinoTest_P.DigitalOutput_Protocol;
    ArduinoTest_DW.obj_j.isSetupComplete = false;
    ArduinoTest_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(6, true);
    ArduinoTest_DW.obj_j.isSetupComplete = true;
  }
}

/* Model terminate function */
void ArduinoTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  matlabCodegenHandle_matlabCodeg(&ArduinoTest_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  matlabCodegenHandle_matlabCo_ky(&ArduinoTest_DW.obj_i);

  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  matlabCodegenHandle_matlabCo_ky(&ArduinoTest_DW.obj_d);

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  matlabCodegenHandle_matlabCo_ky(&ArduinoTest_DW.obj_g);

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  matlabCodegenHandle_matlabCo_ky(&ArduinoTest_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlabCodeg(&ArduinoTest_DW.obj_l);

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  matlabCodegenHandle_matlabCo_ky(&ArduinoTest_DW.obj_j);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
