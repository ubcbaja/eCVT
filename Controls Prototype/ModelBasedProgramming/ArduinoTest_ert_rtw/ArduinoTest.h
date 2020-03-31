/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ArduinoTest.h
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

#ifndef RTW_HEADER_ArduinoTest_h_
#define RTW_HEADER_ArduinoTest_h_
#include <string.h>
#include <stddef.h>
#ifndef ArduinoTest_COMMON_INCLUDES_
# define ArduinoTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* ArduinoTest_COMMON_INCLUDES_ */

#include "ArduinoTest_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_n;/* '<S5>/Digital Output' */
  codertarget_arduinobase_block_T obj_g;/* '<S4>/Digital Output' */
  codertarget_arduinobase_block_T obj_d;/* '<S3>/Digital Output' */
  codertarget_arduinobase_block_T obj_i;/* '<S2>/Digital Output' */
  codertarget_arduinobase_block_T obj_j;/* '<S1>/Digital Output' */
  e_codertarget_arduinobase_int_T gobj_0;/* '<Root>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_1;/* '<Root>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_2;/* '<Root>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_3;/* '<Root>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_0_n;/* '<Root>/Analog Input' */
  e_codertarget_arduinobase_int_T gobj_1_i;/* '<Root>/Analog Input' */
  e_codertarget_arduinobase_int_T gobj_2_h;/* '<Root>/Analog Input' */
  e_codertarget_arduinobase_int_T gobj_3_j;/* '<Root>/Analog Input' */
  int32_T clockTickCounter;            /* '<Root>/Discrete Pulse Generator' */
} DW_ArduinoTest_T;

/* Parameters (default storage) */
struct P_ArduinoTest_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: 0.01
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T DigitalOutput_Protocol;       /* Expression: 0
                                        * Referenced by: '<S1>/Digital Output'
                                        */
  real_T DigitalOutput_Protocol_l;     /* Expression: 0
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  real_T DigitalOutput_Protocol_a;     /* Expression: 0
                                        * Referenced by: '<S3>/Digital Output'
                                        */
  real_T DigitalOutput_Protocol_h;     /* Expression: 0
                                        * Referenced by: '<S4>/Digital Output'
                                        */
  real_T DigitalOutput_Protocol_o;     /* Expression: 0
                                        * Referenced by: '<S5>/Digital Output'
                                        */
  real_T DiscretePulseGenerator_Amp;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete Pulse Generator'
                                        */
  real_T DiscretePulseGenerator_Period;
                            /* Computed Parameter: DiscretePulseGenerator_Period
                             * Referenced by: '<Root>/Discrete Pulse Generator'
                             */
  real_T DiscretePulseGenerator_Duty;
                              /* Computed Parameter: DiscretePulseGenerator_Duty
                               * Referenced by: '<Root>/Discrete Pulse Generator'
                               */
  real_T DiscretePulseGenerator_PhaseDel;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete Pulse Generator'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_ArduinoTest_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ArduinoTest_T ArduinoTest_P;

/* Block states (default storage) */
extern DW_ArduinoTest_T ArduinoTest_DW;

/* External function called from main */
extern void ArduinoTest_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ArduinoTest_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void ArduinoTest_initialize(void);
extern void ArduinoTest_step0(void);
extern void ArduinoTest_step1(void);
extern void ArduinoTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ArduinoTest_T *const ArduinoTest_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ArduinoTest'
 * '<S1>'   : 'ArduinoTest/Digital Output'
 * '<S2>'   : 'ArduinoTest/Digital Output1'
 * '<S3>'   : 'ArduinoTest/Digital Output2'
 * '<S4>'   : 'ArduinoTest/Digital Output3'
 * '<S5>'   : 'ArduinoTest/Digital Output4'
 * '<S6>'   : 'ArduinoTest/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_ArduinoTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
