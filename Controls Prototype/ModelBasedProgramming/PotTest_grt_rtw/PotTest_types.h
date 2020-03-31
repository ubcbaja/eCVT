/*
 * PotTest_types.h
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

#ifndef RTW_HEADER_PotTest_types_h_
#define RTW_HEADER_PotTest_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Custom Type definition for MATLABSystem: '<Root>/Analog Input' */
#include "MW_SVD.h"
#ifndef typedef_c_cell_PotTest_T
#define typedef_c_cell_PotTest_T

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
} c_cell_PotTest_T;

#endif                                 /*typedef_c_cell_PotTest_T*/

#ifndef typedef_e_codertarget_arduinobase_int_T
#define typedef_e_codertarget_arduinobase_int_T

typedef struct {
  c_cell_PotTest_T AvailablePwmPinNames;
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
typedef struct P_PotTest_T_ P_PotTest_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_PotTest_T RT_MODEL_PotTest_T;

#endif                                 /* RTW_HEADER_PotTest_types_h_ */
