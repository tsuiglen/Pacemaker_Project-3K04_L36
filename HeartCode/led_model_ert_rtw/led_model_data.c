/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_model_data.c
 *
 * Code generated for Simulink model 'led_model'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct 29 14:59:55 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "led_model.h"
#include "led_model_private.h"

/* Block parameters (default storage) */
P_led_model_T led_model_P = {
  /* Expression: SampleTime
   * Referenced by: '<S1>/VENT_CMP_DETECT (ON // OFF)'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S1>/ATR_CMP_DETECT (ON // OFF)'
   */
  -1.0,

  /* Expression: 60
   * Referenced by: '<S1>/LRL (ppm)'
   */
  60.0,

  /* Expression: 120
   * Referenced by: '<S1>/URL (ppm)'
   */
  120.0,

  /* Expression: 4000
   * Referenced by: '<S1>/A_Amplitude (mV)'
   */
  4000.0,

  /* Expression: 10
   * Referenced by: '<S1>/A_Pulse_Width (ms)'
   */
  10.0,

  /* Expression: 4000
   * Referenced by: '<S1>/V_Amplitude (mV)'
   */
  4000.0,

  /* Expression: 10
   * Referenced by: '<S1>/V_Pulse_Width (ms)'
   */
  10.0,

  /* Expression: 100
   * Referenced by: '<S1>/A_RefractoryPeriod (ms)'
   */
  100.0,

  /* Expression: 320
   * Referenced by: '<S1>/V_RefractoryPeriod (ms)'
   */
  320.0,

  /* Expression: 0.75
   * Referenced by: '<S1>/A_Sens (mV)'
   */
  0.75,

  /* Expression: 2.5
   * Referenced by: '<S1>/V_Sens (mV)'
   */
  2.5,

  /* Expression: 0
   * Referenced by: '<S1>/Rate_Smoothing (%)'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Hysterisis (On // Off) (Off - 0, On - 1)'
   */
  0.0,

  /* Expression: 250
   * Referenced by: '<S1>/PVARP (ms)'
   */
  250.0,

  /* Expression: 3
   * Referenced by: '<S1>/Mode (VOO - 0, VVI - 1, AOO - 2, AAI - 3)'
   */
  3.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
