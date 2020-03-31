/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: ArduinoTest_types.h
 *
 * Code generated for Simulink model 'ArduinoTest'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Jan 21 09:32:19 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ArduinoTest_types_h_
#define RTW_HEADER_ArduinoTest_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Custom Type definition for MATLABSystem: '<Root>/Analog Input1' */
#include "MW_SVD.h"
#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T Protocol;
} codertarget_arduinobase_block_T;

#endif                               /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_c_cell_ArduinoTest_T
#define typedef_c_cell_ArduinoTest_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} c_cell_ArduinoTest_T;

#endif                                 /*typedef_c_cell_ArduinoTest_T*/

#ifndef typedef_e_codertarget_arduinobase_int_T
#define typedef_e_codertarget_arduinobase_int_T

typedef struct {
  c_cell_ArduinoTest_T AvailablePwmPinNames;
} e_codertarget_arduinobase_int_T;

#endif                               /*typedef_e_codertarget_arduinobase_int_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_codertarget_arduinobase_int_T *Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
} codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

/* Parameters (default storage) */
typedef struct P_ArduinoTest_T_ P_ArduinoTest_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ArduinoTest_T RT_MODEL_ArduinoTest_T;

#endif                                 /* RTW_HEADER_ArduinoTest_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
