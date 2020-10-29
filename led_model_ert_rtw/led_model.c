/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_model.c
 *
 * Code generated for Simulink model 'led_model'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct 29 16:59:16 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "led_model.h"
#include "led_model_private.h"

/* Named constants for Chart: '<Root>/Modes' */
#define led_model_IN_AAI               ((uint8_T)1U)
#define led_model_IN_AOO_Charging      ((uint8_T)2U)
#define led_model_IN_AOO_Pacing        ((uint8_T)3U)
#define led_model_IN_Main              ((uint8_T)4U)
#define led_model_IN_VOO_Charging      ((uint8_T)5U)
#define led_model_IN_VOO_Pacing        ((uint8_T)6U)
#define led_model_IN_VVI               ((uint8_T)7U)

/* Block signals (default storage) */
B_led_model_T led_model_B;

/* Block states (default storage) */
DW_led_model_T led_model_DW;

/* Real-time model */
RT_MODEL_led_model_T led_model_M_;
RT_MODEL_led_model_T *const led_model_M = &led_model_M_;

/* Forward declaration for local functions */
static void led_m_enter_atomic_VOO_Charging(void);
static void led_m_enter_atomic_AOO_Charging(void);
static void led_model_SystemCore_release(const freedomk64f_DigitalRead_led_m_T
  *obj);
static void led_model_SystemCore_delete(const freedomk64f_DigitalRead_led_m_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalRead_led_m_T *obj);
static void led_model_SystemCore_release_kb(const
  freedomk64f_DigitalWrite_led__T *obj);
static void led_model_SystemCore_delete_kb(const freedomk64f_DigitalWrite_led__T
  *obj);
static void matlabCodegenHandle_matlabCo_kb(freedomk64f_DigitalWrite_led__T *obj);
static void SystemCore_release_kbdg5qoxdrh4(const
  freedomk64f_PWMOutput_led_mod_T *obj);
static void SystemCore_delete_kbdg5qoxdrh4(const freedomk64f_PWMOutput_led_mod_T
  *obj);
static void matlabCodegenHandl_kbdg5qoxdrh4(freedomk64f_PWMOutput_led_mod_T *obj);

/* Function for Chart: '<Root>/Modes' */
static void led_m_enter_atomic_VOO_Charging(void)
{
  led_model_B.ATR_PACE_CTRL = false;
  led_model_B.VENT_PACE_CTRL = false;

  /* Constant: '<S1>/V_Amplitude (mV)' */
  led_model_B.PACING_REF_PWM = led_model_P.V_AmplitudemV_Value;
  led_model_B.PACE_CHARGE_CTRL = true;
  led_model_B.PACE_GND_CTRL = true;
  led_model_B.Z_ATR_CTRL = false;
  led_model_B.Z_VENT_CTRL = false;
  led_model_B.ATR_GND_CTRL = false;
  led_model_B.VENT_GND_CTRL = true;
  led_model_B.GREEN_LED = false;

  /* Constant: '<S1>/V_Sens (mV)' */
  led_model_B.VENT_CMP_REF_PWM = led_model_P.V_SensmV_Value;
}

/* Function for Chart: '<Root>/Modes' */
static void led_m_enter_atomic_AOO_Charging(void)
{
  led_model_B.ATR_PACE_CTRL = false;
  led_model_B.VENT_PACE_CTRL = false;

  /* Constant: '<S1>/A_Amplitude (mV)' */
  led_model_B.PACING_REF_PWM = led_model_P.A_AmplitudemV_Value;
  led_model_B.PACE_CHARGE_CTRL = true;
  led_model_B.PACE_GND_CTRL = true;
  led_model_B.Z_ATR_CTRL = false;
  led_model_B.Z_VENT_CTRL = false;
  led_model_B.ATR_GND_CTRL = true;
  led_model_B.VENT_GND_CTRL = false;
  led_model_B.BLUE_LED = false;

  /* Constant: '<S1>/A_Sens (mV)' */
  led_model_B.ATR_CMP_REF_PWM = led_model_P.A_SensmV_Value;
}

static void led_model_SystemCore_release(const freedomk64f_DigitalRead_led_m_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void led_model_SystemCore_delete(const freedomk64f_DigitalRead_led_m_T
  *obj)
{
  led_model_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalRead_led_m_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    led_model_SystemCore_delete(obj);
  }
}

static void led_model_SystemCore_release_kb(const
  freedomk64f_DigitalWrite_led__T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void led_model_SystemCore_delete_kb(const freedomk64f_DigitalWrite_led__T
  *obj)
{
  led_model_SystemCore_release_kb(obj);
}

static void matlabCodegenHandle_matlabCo_kb(freedomk64f_DigitalWrite_led__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    led_model_SystemCore_delete_kb(obj);
  }
}

static void SystemCore_release_kbdg5qoxdrh4(const
  freedomk64f_PWMOutput_led_mod_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void SystemCore_delete_kbdg5qoxdrh4(const freedomk64f_PWMOutput_led_mod_T
  *obj)
{
  SystemCore_release_kbdg5qoxdrh4(obj);
}

static void matlabCodegenHandl_kbdg5qoxdrh4(freedomk64f_PWMOutput_led_mod_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete_kbdg5qoxdrh4(obj);
  }
}

/* Model step function */
void led_model_step(void)
{
  boolean_T tmp;
  boolean_T tmp_0;

  /* MATLABSystem: '<S1>/ATR_CMP_DETECT (ON // OFF)' */
  if (led_model_DW.obj.SampleTime != led_model_P.ATR_CMP_DETECTONOFF_SampleTime)
  {
    led_model_DW.obj.SampleTime = led_model_P.ATR_CMP_DETECTONOFF_SampleTime;
  }

  tmp = MW_digitalIO_read(led_model_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S1>/VENT_CMP_DETECT (ON // OFF)' */
  if (led_model_DW.obj_g.SampleTime !=
      led_model_P.VENT_CMP_DETECTONOFF_SampleTime) {
    led_model_DW.obj_g.SampleTime = led_model_P.VENT_CMP_DETECTONOFF_SampleTime;
  }

  tmp_0 = MW_digitalIO_read(led_model_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Modes' incorporates:
   *  Constant: '<S1>/A_Pulse_Width (ms)'
   *  Constant: '<S1>/A_RefractoryPeriod (ms)'
   *  Constant: '<S1>/LRL (ppm)'
   *  Constant: '<S1>/Mode (VOO - 0, VVI - 1, AOO - 2, AAI - 3)'
   *  Constant: '<S1>/V_Pulse_Width (ms)'
   *  Constant: '<S1>/V_RefractoryPeriod (ms)'
   *  MATLABSystem: '<S1>/ATR_CMP_DETECT (ON // OFF)'
   *  MATLABSystem: '<S1>/VENT_CMP_DETECT (ON // OFF)'
   */
  if (led_model_DW.temporalCounter_i1 < MAX_uint32_T) {
    led_model_DW.temporalCounter_i1++;
  }

  if (led_model_DW.is_active_c3_led_model == 0U) {
    led_model_DW.is_active_c3_led_model = 1U;
    led_model_DW.is_c3_led_model = led_model_IN_Main;
    led_model_B.BLUE_LED = false;
    led_model_B.RED_LED = false;
    led_model_B.GREEN_LED = false;
    led_model_B.PACING_REF_PWM = 0.0;
    led_model_B.FRONTEND_CTRL = true;
  } else {
    switch (led_model_DW.is_c3_led_model) {
     case led_model_IN_AAI:
      led_model_B.RED_LED = true;
      led_model_DW.is_c3_led_model = led_model_IN_AOO_Charging;
      led_model_DW.temporalCounter_i1 = 0U;
      led_m_enter_atomic_AOO_Charging();
      break;

     case led_model_IN_AOO_Charging:
      led_model_B.ATR_PACE_CTRL = false;
      led_model_B.VENT_PACE_CTRL = false;
      led_model_B.PACE_CHARGE_CTRL = true;
      led_model_B.PACE_GND_CTRL = true;
      led_model_B.Z_ATR_CTRL = false;
      led_model_B.Z_VENT_CTRL = false;
      led_model_B.ATR_GND_CTRL = true;
      led_model_B.VENT_GND_CTRL = false;
      led_model_B.BLUE_LED = false;
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 /
           led_model_P.LRLppm_Value - led_model_P.A_Pulse_Widthms_Value)) {
        led_model_DW.is_c3_led_model = led_model_IN_AOO_Pacing;
        led_model_DW.temporalCounter_i1 = 0U;
        led_model_B.PACE_CHARGE_CTRL = false;
        led_model_B.PACE_GND_CTRL = true;
        led_model_B.ATR_PACE_CTRL = true;
        led_model_B.ATR_GND_CTRL = false;
        led_model_B.Z_ATR_CTRL = false;
        led_model_B.Z_VENT_CTRL = false;
        led_model_B.VENT_GND_CTRL = false;
        led_model_B.VENT_PACE_CTRL = false;
        led_model_B.BLUE_LED = true;
        led_model_B.RED_LED = false;
      } else {
        if ((led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
             (led_model_P.A_RefractoryPeriodms_Value)) &&
            ((led_model_P.ModeVOO0VVI1AOO2AAI3_Value == 3.0) && tmp)) {
          led_model_DW.is_c3_led_model = led_model_IN_AAI;
          led_model_B.RED_LED = true;
        }
      }
      break;

     case led_model_IN_AOO_Pacing:
      led_model_B.PACE_CHARGE_CTRL = false;
      led_model_B.PACE_GND_CTRL = true;
      led_model_B.ATR_PACE_CTRL = true;
      led_model_B.ATR_GND_CTRL = false;
      led_model_B.Z_ATR_CTRL = false;
      led_model_B.Z_VENT_CTRL = false;
      led_model_B.VENT_GND_CTRL = false;
      led_model_B.VENT_PACE_CTRL = false;
      led_model_B.BLUE_LED = true;
      led_model_B.RED_LED = false;
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
          (led_model_P.A_Pulse_Widthms_Value)) {
        led_model_DW.is_c3_led_model = led_model_IN_AOO_Charging;
        led_model_DW.temporalCounter_i1 = 0U;
        led_m_enter_atomic_AOO_Charging();
      }
      break;

     case led_model_IN_Main:
      led_model_B.BLUE_LED = false;
      led_model_B.RED_LED = false;
      led_model_B.GREEN_LED = false;
      led_model_B.FRONTEND_CTRL = true;
      if ((led_model_P.ModeVOO0VVI1AOO2AAI3_Value == 2.0) ||
          (led_model_P.ModeVOO0VVI1AOO2AAI3_Value == 3.0)) {
        led_model_DW.is_c3_led_model = led_model_IN_AOO_Charging;
        led_model_DW.temporalCounter_i1 = 0U;
        led_m_enter_atomic_AOO_Charging();
      } else {
        if ((led_model_P.ModeVOO0VVI1AOO2AAI3_Value == 0.0) ||
            (led_model_P.ModeVOO0VVI1AOO2AAI3_Value == 1.0)) {
          led_model_DW.is_c3_led_model = led_model_IN_VOO_Charging;
          led_model_DW.temporalCounter_i1 = 0U;
          led_m_enter_atomic_VOO_Charging();
        }
      }
      break;

     case led_model_IN_VOO_Charging:
      led_model_B.ATR_PACE_CTRL = false;
      led_model_B.VENT_PACE_CTRL = false;
      led_model_B.PACE_CHARGE_CTRL = true;
      led_model_B.PACE_GND_CTRL = true;
      led_model_B.Z_ATR_CTRL = false;
      led_model_B.Z_VENT_CTRL = false;
      led_model_B.ATR_GND_CTRL = false;
      led_model_B.VENT_GND_CTRL = true;
      led_model_B.GREEN_LED = false;
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 /
           led_model_P.LRLppm_Value - led_model_P.V_Pulse_Widthms_Value)) {
        led_model_DW.is_c3_led_model = led_model_IN_VOO_Pacing;
        led_model_DW.temporalCounter_i1 = 0U;
        led_model_B.PACE_CHARGE_CTRL = false;
        led_model_B.PACE_GND_CTRL = true;
        led_model_B.ATR_PACE_CTRL = false;
        led_model_B.ATR_GND_CTRL = false;
        led_model_B.Z_ATR_CTRL = false;
        led_model_B.Z_VENT_CTRL = false;
        led_model_B.VENT_GND_CTRL = false;
        led_model_B.VENT_PACE_CTRL = true;
        led_model_B.GREEN_LED = true;
        led_model_B.RED_LED = false;
      } else {
        if ((led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
             (led_model_P.V_RefractoryPeriodms_Value)) &&
            ((led_model_P.ModeVOO0VVI1AOO2AAI3_Value == 1.0) && tmp_0)) {
          led_model_DW.is_c3_led_model = led_model_IN_VVI;
          led_model_B.RED_LED = true;
        }
      }
      break;

     case led_model_IN_VOO_Pacing:
      led_model_B.PACE_CHARGE_CTRL = false;
      led_model_B.PACE_GND_CTRL = true;
      led_model_B.ATR_PACE_CTRL = false;
      led_model_B.ATR_GND_CTRL = false;
      led_model_B.Z_ATR_CTRL = false;
      led_model_B.Z_VENT_CTRL = false;
      led_model_B.VENT_GND_CTRL = false;
      led_model_B.VENT_PACE_CTRL = true;
      led_model_B.GREEN_LED = true;
      led_model_B.RED_LED = false;
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
          (led_model_P.V_Pulse_Widthms_Value)) {
        led_model_DW.is_c3_led_model = led_model_IN_VOO_Charging;
        led_model_DW.temporalCounter_i1 = 0U;
        led_m_enter_atomic_VOO_Charging();
      }
      break;

     default:
      /* case IN_VVI: */
      led_model_B.RED_LED = true;
      led_model_DW.is_c3_led_model = led_model_IN_VOO_Charging;
      led_model_DW.temporalCounter_i1 = 0U;
      led_m_enter_atomic_VOO_Charging();
      break;
    }
  }

  /* End of Chart: '<Root>/Modes' */

  /* MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_e.MW_DIGITALIO_HANDLE,
                     led_model_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
  MW_digitalIO_write(led_model_DW.obj_n.MW_DIGITALIO_HANDLE,
                     led_model_B.VENT_CMP_REF_PWM != 0.0);

  /* MATLABSystem: '<S3>/Z_ATR_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_i.MW_DIGITALIO_HANDLE,
                     led_model_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S3>/PACING_REF_PWM' */
  MW_digitalIO_write(led_model_DW.obj_f.MW_DIGITALIO_HANDLE,
                     led_model_B.PACING_REF_PWM != 0.0);

  /* MATLABSystem: '<S3>/PWM Output' */
  MW_PWM_SetDutyCycle(led_model_DW.obj_f2.MW_PWM_HANDLE,
                      led_model_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Z_VENT_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_nv.MW_DIGITALIO_HANDLE,
                     led_model_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S3>/ATR_PACE_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_h.MW_DIGITALIO_HANDLE,
                     led_model_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S3>/VENT_PACE_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_l.MW_DIGITALIO_HANDLE,
                     led_model_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S3>/PACE_GND_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_lf.MW_DIGITALIO_HANDLE,
                     led_model_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S3>/ATR_GND_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_k.MW_DIGITALIO_HANDLE,
                     led_model_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S3>/VENT_GND_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_l0.MW_DIGITALIO_HANDLE,
                     led_model_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S3>/FRONTEND_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_b.MW_DIGITALIO_HANDLE,
                     led_model_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S3>/RED_LED' */
  MW_digitalIO_write(led_model_DW.obj_lh.MW_DIGITALIO_HANDLE,
                     led_model_B.RED_LED);

  /* MATLABSystem: '<S3>/GREEN_LED' */
  MW_digitalIO_write(led_model_DW.obj_o.MW_DIGITALIO_HANDLE,
                     led_model_B.GREEN_LED);

  /* MATLABSystem: '<S3>/BLUE_LED' */
  MW_digitalIO_write(led_model_DW.obj_m.MW_DIGITALIO_HANDLE,
                     led_model_B.BLUE_LED);
}

/* Model initialize function */
void led_model_initialize(void)
{
  {
    freedomk64f_DigitalRead_led_m_T *obj;
    freedomk64f_DigitalWrite_led__T *obj_0;
    freedomk64f_PWMOutput_led_mod_T *obj_1;

    /* Start for MATLABSystem: '<S1>/ATR_CMP_DETECT (ON // OFF)' */
    led_model_DW.obj.matlabCodegenIsDeleted = true;
    led_model_DW.obj.isInitialized = 0;
    led_model_DW.obj.SampleTime = -1.0;
    led_model_DW.obj.matlabCodegenIsDeleted = false;
    led_model_DW.obj.SampleTime = led_model_P.ATR_CMP_DETECTONOFF_SampleTime;
    obj = &led_model_DW.obj;
    led_model_DW.obj.isSetupComplete = false;
    led_model_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    led_model_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_CMP_DETECT (ON // OFF)' */
    led_model_DW.obj_g.matlabCodegenIsDeleted = true;
    led_model_DW.obj_g.isInitialized = 0;
    led_model_DW.obj_g.SampleTime = -1.0;
    led_model_DW.obj_g.matlabCodegenIsDeleted = false;
    led_model_DW.obj_g.SampleTime = led_model_P.VENT_CMP_DETECTONOFF_SampleTime;
    obj = &led_model_DW.obj_g;
    led_model_DW.obj_g.isSetupComplete = false;
    led_model_DW.obj_g.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    led_model_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
    led_model_DW.obj_e.matlabCodegenIsDeleted = true;
    led_model_DW.obj_e.isInitialized = 0;
    led_model_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_e;
    led_model_DW.obj_e.isSetupComplete = false;
    led_model_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    led_model_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
    led_model_DW.obj_n.matlabCodegenIsDeleted = true;
    led_model_DW.obj_n.isInitialized = 0;
    led_model_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_n;
    led_model_DW.obj_n.isSetupComplete = false;
    led_model_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(3U, 1);
    led_model_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_ATR_CTRL' */
    led_model_DW.obj_i.matlabCodegenIsDeleted = true;
    led_model_DW.obj_i.isInitialized = 0;
    led_model_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_i;
    led_model_DW.obj_i.isSetupComplete = false;
    led_model_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    led_model_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACING_REF_PWM' */
    led_model_DW.obj_f.matlabCodegenIsDeleted = true;
    led_model_DW.obj_f.isInitialized = 0;
    led_model_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_f;
    led_model_DW.obj_f.isSetupComplete = false;
    led_model_DW.obj_f.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(5U, 1);
    led_model_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    led_model_DW.obj_f2.matlabCodegenIsDeleted = true;
    led_model_DW.obj_f2.isInitialized = 0;
    led_model_DW.obj_f2.matlabCodegenIsDeleted = false;
    obj_1 = &led_model_DW.obj_f2;
    led_model_DW.obj_f2.isSetupComplete = false;
    led_model_DW.obj_f2.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(led_model_DW.obj_f2.MW_PWM_HANDLE);
    led_model_DW.obj_f2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_VENT_CTRL' */
    led_model_DW.obj_nv.matlabCodegenIsDeleted = true;
    led_model_DW.obj_nv.isInitialized = 0;
    led_model_DW.obj_nv.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_nv;
    led_model_DW.obj_nv.isSetupComplete = false;
    led_model_DW.obj_nv.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    led_model_DW.obj_nv.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_PACE_CTRL' */
    led_model_DW.obj_h.matlabCodegenIsDeleted = true;
    led_model_DW.obj_h.isInitialized = 0;
    led_model_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_h;
    led_model_DW.obj_h.isSetupComplete = false;
    led_model_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    led_model_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_PACE_CTRL' */
    led_model_DW.obj_l.matlabCodegenIsDeleted = true;
    led_model_DW.obj_l.isInitialized = 0;
    led_model_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_l;
    led_model_DW.obj_l.isSetupComplete = false;
    led_model_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    led_model_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_GND_CTRL' */
    led_model_DW.obj_lf.matlabCodegenIsDeleted = true;
    led_model_DW.obj_lf.isInitialized = 0;
    led_model_DW.obj_lf.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_lf;
    led_model_DW.obj_lf.isSetupComplete = false;
    led_model_DW.obj_lf.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    led_model_DW.obj_lf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_GND_CTRL' */
    led_model_DW.obj_k.matlabCodegenIsDeleted = true;
    led_model_DW.obj_k.isInitialized = 0;
    led_model_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_k;
    led_model_DW.obj_k.isSetupComplete = false;
    led_model_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    led_model_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_GND_CTRL' */
    led_model_DW.obj_l0.matlabCodegenIsDeleted = true;
    led_model_DW.obj_l0.isInitialized = 0;
    led_model_DW.obj_l0.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_l0;
    led_model_DW.obj_l0.isSetupComplete = false;
    led_model_DW.obj_l0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    led_model_DW.obj_l0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/FRONTEND_CTRL' */
    led_model_DW.obj_b.matlabCodegenIsDeleted = true;
    led_model_DW.obj_b.isInitialized = 0;
    led_model_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_b;
    led_model_DW.obj_b.isSetupComplete = false;
    led_model_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    led_model_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/RED_LED' */
    led_model_DW.obj_lh.matlabCodegenIsDeleted = true;
    led_model_DW.obj_lh.isInitialized = 0;
    led_model_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_lh;
    led_model_DW.obj_lh.isSetupComplete = false;
    led_model_DW.obj_lh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    led_model_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/GREEN_LED' */
    led_model_DW.obj_o.matlabCodegenIsDeleted = true;
    led_model_DW.obj_o.isInitialized = 0;
    led_model_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_o;
    led_model_DW.obj_o.isSetupComplete = false;
    led_model_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    led_model_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/BLUE_LED' */
    led_model_DW.obj_m.matlabCodegenIsDeleted = true;
    led_model_DW.obj_m.isInitialized = 0;
    led_model_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_m;
    led_model_DW.obj_m.isSetupComplete = false;
    led_model_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    led_model_DW.obj_m.isSetupComplete = true;
  }
}

/* Model terminate function */
void led_model_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/ATR_CMP_DETECT (ON // OFF)' */
  matlabCodegenHandle_matlabCodeg(&led_model_DW.obj);

  /* Terminate for MATLABSystem: '<S1>/VENT_CMP_DETECT (ON // OFF)' */
  matlabCodegenHandle_matlabCodeg(&led_model_DW.obj_g);

  /* Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_e);

  /* Terminate for MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_n);

  /* Terminate for MATLABSystem: '<S3>/Z_ATR_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_i);

  /* Terminate for MATLABSystem: '<S3>/PACING_REF_PWM' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_f);

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  matlabCodegenHandl_kbdg5qoxdrh4(&led_model_DW.obj_f2);

  /* Terminate for MATLABSystem: '<S3>/Z_VENT_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_nv);

  /* Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_h);

  /* Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/PACE_GND_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_lf);

  /* Terminate for MATLABSystem: '<S3>/ATR_GND_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_k);

  /* Terminate for MATLABSystem: '<S3>/VENT_GND_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_l0);

  /* Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/RED_LED' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_lh);

  /* Terminate for MATLABSystem: '<S3>/GREEN_LED' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/BLUE_LED' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_m);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
