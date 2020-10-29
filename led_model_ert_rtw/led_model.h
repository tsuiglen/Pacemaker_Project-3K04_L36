/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_model.h
 *
 * Code generated for Simulink model 'led_model'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct 29 15:00:50 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_led_model_h_
#define RTW_HEADER_led_model_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef led_model_COMMON_INCLUDES_
# define led_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#endif                                 /* led_model_COMMON_INCLUDES_ */

#include "led_model_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
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

/* Block signals (default storage) */
typedef struct {
  real_T LRLppm;                       /* '<S1>/LRL (ppm)' */
  real_T URLppm;                       /* '<S1>/URL (ppm)' */
  real_T A_AmplitudemV;                /* '<S1>/A_Amplitude (mV)' */
  real_T A_Pulse_Widthms;              /* '<S1>/A_Pulse_Width (ms)' */
  real_T V_AmplitudemV;                /* '<S1>/V_Amplitude (mV)' */
  real_T V_Pulse_Widthms;              /* '<S1>/V_Pulse_Width (ms)' */
  real_T A_RefractoryPeriodms;         /* '<S1>/A_RefractoryPeriod (ms)' */
  real_T V_RefractoryPeriodms;         /* '<S1>/V_RefractoryPeriod (ms)' */
  real_T A_SensmV;                     /* '<S1>/A_Sens (mV)' */
  real_T V_SensmV;                     /* '<S1>/V_Sens (mV)' */
  real_T Rate_Smoothing;               /* '<S1>/Rate_Smoothing (%)' */
  real_T HysterisisOnOffOff0On1;
                           /* '<S1>/Hysterisis (On // Off) (Off - 0, On - 1)' */
  real_T PVARPms;                      /* '<S1>/PVARP (ms)' */
  real_T ModeVOO0VVI1AOO2AAI3;
                          /* '<S1>/Mode (VOO - 0, VVI - 1, AOO - 2, AAI - 3)' */
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
  boolean_T ATR_CMP_DETECTONOFF;       /* '<S1>/ATR_CMP_DETECT (ON // OFF)' */
  boolean_T VENT_CMP_DETECTONOFF;      /* '<S1>/VENT_CMP_DETECT (ON // OFF)' */
} B_led_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_led_m_T obj; /* '<S1>/ATR_CMP_DETECT (ON // OFF)' */
  freedomk64f_DigitalRead_led_m_T obj_g;/* '<S1>/VENT_CMP_DETECT (ON // OFF)' */
  freedomk64f_DigitalWrite_led__T obj_e;/* '<S3>/PACE_CHARGE_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_n;/* '<S3>/VENT_CMP_REF_PWM' */
  freedomk64f_DigitalWrite_led__T obj_i;/* '<S3>/Z_ATR_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_f;/* '<S3>/PACING_REF_PWM' */
  freedomk64f_DigitalWrite_led__T obj_l;/* '<S3>/ATR_CMP_REF_PWM' */
  freedomk64f_DigitalWrite_led__T obj_nv;/* '<S3>/Z_VENT_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_h;/* '<S3>/ATR_PACE_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_l5;/* '<S3>/VENT_PACE_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_lf;/* '<S3>/PACE_GND_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_k;/* '<S3>/ATR_GND_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_l0;/* '<S3>/VENT_GND_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_b;/* '<S3>/FRONTEND_CTRL' */
  freedomk64f_DigitalWrite_led__T obj_lh;/* '<S3>/RED_LED' */
  freedomk64f_DigitalWrite_led__T obj_o;/* '<S3>/GREEN_LED' */
  freedomk64f_DigitalWrite_led__T obj_m;/* '<S3>/BLUE_LED' */
  uint32_T is_c3_led_model;            /* '<Root>/Modes' */
  uint32_T temporalCounter_i1;         /* '<Root>/Modes' */
  uint8_T is_active_c3_led_model;      /* '<Root>/Modes' */
} DW_led_model_T;

/* Parameters (default storage) */
struct P_led_model_T_ {
  real_T VENT_CMP_DETECTONOFF_SampleTime;/* Expression: SampleTime
                                          * Referenced by: '<S1>/VENT_CMP_DETECT (ON // OFF)'
                                          */
  real_T ATR_CMP_DETECTONOFF_SampleTime;/* Expression: SampleTime
                                         * Referenced by: '<S1>/ATR_CMP_DETECT (ON // OFF)'
                                         */
  real_T LRLppm_Value;                 /* Expression: 60
                                        * Referenced by: '<S1>/LRL (ppm)'
                                        */
  real_T URLppm_Value;                 /* Expression: 120
                                        * Referenced by: '<S1>/URL (ppm)'
                                        */
  real_T A_AmplitudemV_Value;          /* Expression: 4000
                                        * Referenced by: '<S1>/A_Amplitude (mV)'
                                        */
  real_T A_Pulse_Widthms_Value;        /* Expression: 10
                                        * Referenced by: '<S1>/A_Pulse_Width (ms)'
                                        */
  real_T V_AmplitudemV_Value;          /* Expression: 4000
                                        * Referenced by: '<S1>/V_Amplitude (mV)'
                                        */
  real_T V_Pulse_Widthms_Value;        /* Expression: 10
                                        * Referenced by: '<S1>/V_Pulse_Width (ms)'
                                        */
  real_T A_RefractoryPeriodms_Value;   /* Expression: 100
                                        * Referenced by: '<S1>/A_RefractoryPeriod (ms)'
                                        */
  real_T V_RefractoryPeriodms_Value;   /* Expression: 320
                                        * Referenced by: '<S1>/V_RefractoryPeriod (ms)'
                                        */
  real_T A_SensmV_Value;               /* Expression: 0.75
                                        * Referenced by: '<S1>/A_Sens (mV)'
                                        */
  real_T V_SensmV_Value;               /* Expression: 2.5
                                        * Referenced by: '<S1>/V_Sens (mV)'
                                        */
  real_T Rate_Smoothing_Value;         /* Expression: 0
                                        * Referenced by: '<S1>/Rate_Smoothing (%)'
                                        */
  real_T HysterisisOnOffOff0On1_Value; /* Expression: 0
                                        * Referenced by: '<S1>/Hysterisis (On // Off) (Off - 0, On - 1)'
                                        */
  real_T PVARPms_Value;                /* Expression: 250
                                        * Referenced by: '<S1>/PVARP (ms)'
                                        */
  real_T ModeVOO0VVI1AOO2AAI3_Value;   /* Expression: 3
                                        * Referenced by: '<S1>/Mode (VOO - 0, VVI - 1, AOO - 2, AAI - 3)'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_led_model_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
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
 * '<S1>'   : 'led_model/Input Subsystem'
 * '<S2>'   : 'led_model/Modes'
 * '<S3>'   : 'led_model/Output Subsystem'
 */
#endif                                 /* RTW_HEADER_led_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
