/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HeartCode.h
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

#ifndef RTW_HEADER_HeartCode_h_
#define RTW_HEADER_HeartCode_h_
#include <string.h>
#include <stddef.h>
#ifndef HeartCode_COMMON_INCLUDES_
# define HeartCode_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* HeartCode_COMMON_INCLUDES_ */

#include "HeartCode_types.h"

/* Child system includes */
#include "send_params_private.h"
#include "send_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[33];
  uint8_T RxDataLocChar[33];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Modes' */
  real_T PACING_REF_PWM;               /* '<Root>/Modes' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Modes' */
  real_T Divide1;
  real_T Divide2;
  real_T Divide3;
  real_T Divide;
  real_T d;
  real32_T in_A_Sens;
  real32_T in_V_Sens;
  real32_T in_A_Sens_i;                /* '<Root>/COM_IN' */
  real32_T in_V_Sens_e;                /* '<Root>/COM_IN' */
  uint32_T qY;
  uint32_T qY_m;
  uint32_T u;
  uint16_T in_A_Amplitude;
  uint16_T in_V_Amplitude;
  uint16_T in_A_RefractoryPeriod;
  uint16_T in_V_RefractoryPeriod;
  uint16_T in_PVARP;
  uint16_T in_fixedAVDelay;
  uint16_T in_A_Amplitude_k;           /* '<Root>/COM_IN' */
  uint16_T in_V_Amplitude_a;           /* '<Root>/COM_IN' */
  uint16_T in_A_RefractoryPeriod_n;    /* '<Root>/COM_IN' */
  uint16_T in_V_RefractoryPeriod_p;    /* '<Root>/COM_IN' */
  uint16_T in_PVARP_j;                 /* '<Root>/COM_IN' */
  uint16_T in_fixedAVDelay_d;          /* '<Root>/COM_IN' */
  uint16_T u1;
  uint16_T u2;
  uint8_T BytePack[2];                 /* '<S2>/Byte Pack' */
  uint8_T BytePack1[2];                /* '<S2>/Byte Pack1' */
  uint8_T BytePack2[2];                /* '<S2>/Byte Pack2' */
  uint8_T BytePack3[2];                /* '<S2>/Byte Pack3' */
  uint8_T BytePack4[4];                /* '<S2>/Byte Pack4' */
  uint8_T BytePack5[4];                /* '<S2>/Byte Pack5' */
  uint8_T BytePack6[2];                /* '<S2>/Byte Pack6' */
  uint8_T BytePack7[2];                /* '<S2>/Byte Pack7' */
  uint8_T in_Mode;                     /* '<Root>/COM_IN' */
  uint8_T in_LRL;                      /* '<Root>/COM_IN' */
  uint8_T in_URL;                      /* '<Root>/COM_IN' */
  uint8_T in_A_Pulse_Width;            /* '<Root>/COM_IN' */
  uint8_T in_V_Pulse_Width;            /* '<Root>/COM_IN' */
  uint8_T in_Rate_Smoothing;           /* '<Root>/COM_IN' */
  uint8_T in_maxSensRate;              /* '<Root>/COM_IN' */
  uint8_T in_ActivityThreshold;        /* '<Root>/COM_IN' */
  uint8_T in_ReactionTime;             /* '<Root>/COM_IN' */
  uint8_T in_ResponseFactor;           /* '<Root>/COM_IN' */
  uint8_T in_RecoveryTime;             /* '<Root>/COM_IN' */
  uint8_T status;
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
  boolean_T b;
} B_HeartCode_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Heart_T obj; /* '<S3>/ATR_CMP_DETECT (ON // OFF)' */
  freedomk64f_DigitalRead_Heart_T obj_g;/* '<S3>/VENT_CMP_DETECT (ON // OFF)' */
  freedomk64f_SCIRead_HeartCode_T obj_d;/* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_HeartCod_T obj_c;/* '<S2>/Serial Transmit' */
  freedomk64f_PWMOutput_HeartCo_T obj_f;/* '<S5>/VENT_CMP_REF_PWM' */
  freedomk64f_PWMOutput_HeartCo_T obj_p;/* '<S5>/PACING_REF_PWM' */
  freedomk64f_PWMOutput_HeartCo_T obj_m;/* '<S5>/ATR_CMP_REF_PWM' */
  freedomk64f_DigitalWrite_Hear_T obj_e;/* '<S5>/PACE_CHARGE_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_i;/* '<S5>/Z_ATR_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_n;/* '<S5>/Z_VENT_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_h;/* '<S5>/ATR_PACE_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_l;/* '<S5>/VENT_PACE_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_lf;/* '<S5>/PACE_GND_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_k;/* '<S5>/ATR_GND_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_l0;/* '<S5>/VENT_GND_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_b;/* '<S5>/FRONTEND_CTRL' */
  freedomk64f_DigitalWrite_Hear_T obj_lh;/* '<S5>/RED_LED' */
  freedomk64f_DigitalWrite_Hear_T obj_o;/* '<S5>/GREEN_LED' */
  freedomk64f_DigitalWrite_Hear_T obj_m1;/* '<S5>/BLUE_LED' */
  uint32_T temporalCounter_i1;         /* '<Root>/Modes' */
  uint16_T AdeltaT;                    /* '<Root>/Modes' */
  uint16_T VdeltaT;                    /* '<Root>/Modes' */
  uint8_T is_active_c3_HeartCode;      /* '<Root>/Modes' */
  uint8_T is_c3_HeartCode;             /* '<Root>/Modes' */
  uint8_T is_c1_HeartCode;             /* '<Root>/COM_IN' */
} DW_HeartCode_T;

/* Parameters (default storage) */
struct P_HeartCode_T_ {
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T VENT_CMP_DETECTONOFF_SampleTime;/* Expression: SampleTime
                                          * Referenced by: '<S3>/VENT_CMP_DETECT (ON // OFF)'
                                          */
  real_T ATR_CMP_DETECTONOFF_SampleTime;/* Expression: SampleTime
                                         * Referenced by: '<S3>/ATR_CMP_DETECT (ON // OFF)'
                                         */
  real_T u0mVtoAtrialDutyCycle_Value;  /* Expression: 50
                                        * Referenced by: '<S3>/50mV to Atrial Duty Cycle'
                                        */
  real_T u0mVtoVentricleDutyCycle_Value;/* Expression: 50
                                         * Referenced by: '<S3>/50mV to Ventricle Duty Cycle'
                                         */
  real_T u0mVtoAtrDutyCycle1_Value;    /* Expression: 50
                                        * Referenced by: '<S3>/50mV to Atr Duty Cycle1'
                                        */
  real_T u0mVtoVentDutyCycle_Value;    /* Expression: 50
                                        * Referenced by: '<S3>/50mV to Vent Duty Cycle'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_HeartCode_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_HeartCode_T HeartCode_P;

/* Block signals (default storage) */
extern B_HeartCode_T HeartCode_B;

/* Block states (default storage) */
extern DW_HeartCode_T HeartCode_DW;

/* Model entry point functions */
extern void HeartCode_initialize(void);
extern void HeartCode_step(void);
extern void HeartCode_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HeartCode_T *const HeartCode_M;

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
 * '<Root>' : 'HeartCode'
 * '<S1>'   : 'HeartCode/COM_IN'
 * '<S2>'   : 'HeartCode/COM_OUT'
 * '<S3>'   : 'HeartCode/Input Subsystem'
 * '<S4>'   : 'HeartCode/Modes'
 * '<S5>'   : 'HeartCode/Output Subsystem'
 */
#endif                                 /* RTW_HEADER_HeartCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
