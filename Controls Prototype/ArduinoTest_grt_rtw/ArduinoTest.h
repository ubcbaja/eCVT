/*
 * ArduinoTest.h
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

#ifndef RTW_HEADER_ArduinoTest_h_
#define RTW_HEADER_ArduinoTest_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef ArduinoTest_COMMON_INCLUDES_
# define ArduinoTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* ArduinoTest_COMMON_INCLUDES_ */

#include "ArduinoTest_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S1>/Digital Output' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Discrete Pulse Generator' */
  boolean_T objisempty;                /* '<S1>/Digital Output' */
} DW_ArduinoTest_T;

/* Parameters (default storage) */
struct P_ArduinoTest_T_ {
  real_T DigitalOutput_Protocol;       /* Expression: 0
                                        * Referenced by: '<S1>/Digital Output'
                                        */
  real_T DiscretePulseGenerator_Amp;   /* Expression: 1
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
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ArduinoTest_T ArduinoTest_P;

/* Block states (default storage) */
extern DW_ArduinoTest_T ArduinoTest_DW;

/* Model entry point functions */
extern void ArduinoTest_initialize(void);
extern void ArduinoTest_step(void);
extern void ArduinoTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ArduinoTest_T *const ArduinoTest_M;

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
 */
#endif                                 /* RTW_HEADER_ArduinoTest_h_ */
