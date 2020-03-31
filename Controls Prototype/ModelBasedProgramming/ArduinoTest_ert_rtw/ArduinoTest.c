/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ArduinoTest.c
 *
 * Code generated for Simulink model 'ArduinoTest'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Feb 25 15:35:53 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
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
  uint16_T rtb_AnalogInput1_0;
  boolean_T rtb_AnalogInput1_1;
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
    &rtb_AnalogInput1_0, 3);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  MATLABSystem: '<Root>/Analog Input1'
   */
  rtb_AnalogInput1_1 = (rtb_AnalogInput1_0 > 200U);
  if (rtb_AnalogInput1_0 > 800U) {
    rtb_y_idx_0 = 0;
    rtb_y_idx_1 = 0;
    rtb_y_idx_2 = 0;
    rtb_y_idx_3 = 1;
  } else if (rtb_AnalogInput1_0 > 600U) {
    rtb_y_idx_0 = 0;
    rtb_y_idx_1 = 0;
    rtb_y_idx_2 = 1;
    rtb_y_idx_3 = 1;
  } else if (rtb_AnalogInput1_0 > 400U) {
    rtb_y_idx_0 = 0;
    rtb_y_idx_1 = 1;
    rtb_y_idx_2 = 1;
    rtb_y_idx_3 = 1;
  } else {
    rtb_y_idx_0 = rtb_AnalogInput1_1;
    rtb_y_idx_1 = rtb_AnalogInput1_1;
    rtb_y_idx_2 = rtb_AnalogInput1_1;
    rtb_y_idx_3 = rtb_AnalogInput1_1;
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
    &rtb_AnalogInput1_0, 3);

  /* End of MATLABSystem: '<Root>/Analog Input' */
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
}

/* Model initialize function */
void ArduinoTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ArduinoTest_M, 0,
                sizeof(RT_MODEL_ArduinoTest_T));

  /* states (dwork) */
  (void) memset((void *)&ArduinoTest_DW, 0,
                sizeof(DW_ArduinoTest_T));

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
