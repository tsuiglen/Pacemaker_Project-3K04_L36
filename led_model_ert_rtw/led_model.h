/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_model.h
 *
 * Code generated for Simulink model 'led_model'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Oct 24 17:20:59 2020
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

/* Block signals (default storage) */
typedef struct {
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Modes' */
  real_T PACING_REF_PWM;               /* '<Root>/Modes' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Modes' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/Modes' */
  boolean_T Z_ATR_CTRL;                /* '<Root>/Modes' */
  boolean_T Z_VENT_CTRL;               /* '<Root>/Modes' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/Modes' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/Modes' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/Modes' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/Modes' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/Modes' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/Modes' */
  boolean_T RED_LED;                   /* '<Root>/Modes' */
  boolean_T GREEN_LED;                 /* '<Root>/Modes' */
  boolean_T BLUE_LED;                  /* '<Root>/Modes' */
} B_led_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_led_m_T obj; /* '<Root>/Digital Read' */
  freedomk64f_DigitalRead_led_m_T obj_g;/* '<Root>/Digital Read1' */
  freedomk64f_DigitalWrite_led__T obj_l;/* '<Root>/Digital Write' */
  freedomk64f_DigitalWrite_led__T obj_i;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_led__T obj_m;/* '<Root>/Digital Write10' */
  freedomk64f_DigitalWrite_led__T obj_n;/* '<Root>/Digital Write11' */
  freedomk64f_DigitalWrite_led__T obj_f;/* '<Root>/Digital Write12' */
  freedomk64f_DigitalWrite_led__T obj_lm;/* '<Root>/Digital Write13' */
  freedomk64f_DigitalWrite_led__T obj_nv;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_led__T obj_b;/* '<Root>/Digital Write20' */
  freedomk64f_DigitalWrite_led__T obj_l0;/* '<Root>/Digital Write3' */
  freedomk64f_DigitalWrite_led__T obj_k;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_led__T obj_l5;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_led__T obj_e;/* '<Root>/Digital Write6' */
  freedomk64f_DigitalWrite_led__T obj_h;/* '<Root>/Digital Write7' */
  freedomk64f_DigitalWrite_led__T obj_lh;/* '<Root>/Digital Write8' */
  freedomk64f_DigitalWrite_led__T obj_o;/* '<Root>/Digital Write9' */
  uint32_T temporalCounter_i1;         /* '<Root>/Modes' */
  uint8_T is_active_c3_led_model;      /* '<Root>/Modes' */
  uint8_T is_c3_led_model;             /* '<Root>/Modes' */
} DW_led_model_T;

/* Parameters (default storage) */
struct P_led_model_T_ {
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read1'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 120
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 4000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 4000
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_led_model_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_led_model_T led_model_P;

/* Block signals (default storage) */
extern B_led_model_T led_model_B;

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
 * '<S1>'   : 'led_model/Modes'
 */
#endif                                 /* RTW_HEADER_led_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
