/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HeartCode_data.c
 *
 * Code generated for Simulink model 'HeartCode'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Nov 27 17:46:53 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HeartCode.h"
#include "HeartCode_private.h"

/* Block parameters (default storage) */
P_HeartCode_T HeartCode_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Serial Receive'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S3>/VENT_CMP_DETECT (ON // OFF)'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S3>/ATR_CMP_DETECT (ON // OFF)'
   */
  -1.0,

  /* Expression: 50
   * Referenced by: '<S3>/50mV to Atrial Duty Cycle'
   */
  50.0,

  /* Expression: 50
   * Referenced by: '<S3>/50mV to Ventricle Duty Cycle'
   */
  50.0,

  /* Expression: 50
   * Referenced by: '<S3>/50mV to Atr Duty Cycle1'
   */
  50.0,

  /* Expression: 50
   * Referenced by: '<S3>/50mV to Vent Duty Cycle'
   */
  50.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
