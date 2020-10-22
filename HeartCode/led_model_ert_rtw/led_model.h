/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_model.h
 *
 * Code generated for Simulink model 'led_model'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct  1 16:56:01 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_led_model_h_
#define RTW_HEADER_led_model_h_
#include <math.h>
#include <stddef.h>
#ifndef led_model_COMMON_INCLUDES_
# define led_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#endif                                 /* led_model_COMMON_INCLUDES_ */

#include "led_model_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalWrite_led__T obj; /* '<Root>/Digital Write1' */
  uint32_T temporalCounter_i1;         /* '<Root>/LED_LOGIC' */
  uint8_T is_active_c3_led_model;      /* '<Root>/LED_LOGIC' */
  uint8_T is_c3_led_model;             /* '<Root>/LED_LOGIC' */
} DW_led_model_T;

/* Parameters (default storage) */
struct P_led_model_T_ {
  real_T Constant_Value;               /* Expression: 200
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 500
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_led_model_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_led_model_T led_model_P;

/* Block states (default storage) */
extern DW_led_model_T led_model_DW;

/* Model entry point functions */
extern void led_model_initialize(void);
extern void led_model_step(void);
extern void led_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_led_model_T *const led_model_M;

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
 * '<Root>' : 'led_model'
 * '<S1>'   : 'led_model/LED_LOGIC'
 */
#endif                                 /* RTW_HEADER_led_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
