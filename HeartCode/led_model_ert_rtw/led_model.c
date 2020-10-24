/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_model.c
 *
 * Code generated for Simulink model 'led_model'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Oct 24 14:54:16 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "led_model.h"
#include "led_model_private.h"

/* Named constants for Chart: '<Root>/Modes' */
#define led_model_IN_AOO_Charging      ((uint8_T)1U)
#define led_model_IN_AOO_Pacing        ((uint8_T)2U)
#define led_model_IN_Main              ((uint8_T)3U)
#define led_model_IN_VOO_Charging      ((uint8_T)4U)
#define led_model_IN_VOO_Pacing        ((uint8_T)5U)

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
static void SystemCore_rele_kbdg5qoxdrh4kbz(const
  freedomk64f_DigitalRead_led_m_T *obj);
static void SystemCore_dele_kbdg5qoxdrh4kbz(const
  freedomk64f_DigitalRead_led_m_T *obj);
static void matlabCodegenHa_kbdg5qoxdrh4kbz(freedomk64f_DigitalRead_led_m_T *obj);
static void led_mode_SystemCore_release_kbd(const
  freedomk64f_DigitalWrite_led__T *obj);
static void led_model_SystemCore_delete_kbd(const
  freedomk64f_DigitalWrite_led__T *obj);
static void matlabCodegenHandle_matlabC_kbd(freedomk64f_DigitalWrite_led__T *obj);
static void led_model_SystemCore_release(const freedomk64f_PWMOutput_led_mod_T
  *obj);
static void led_model_SystemCore_delete(const freedomk64f_PWMOutput_led_mod_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_PWMOutput_led_mod_T *obj);

/* Function for Chart: '<Root>/Modes' */
static void led_m_enter_atomic_VOO_Charging(void)
{
  led_model_B.ATR_PACE_CTRL = false;
  led_model_B.VENT_PACE_CTRL = false;

  /* Constant: '<Root>/Constant4' */
  led_model_B.PACING_REF_PWM = led_model_P.Constant4_Value;

  /* Constant: '<Root>/Constant9' */
  led_model_B.VENT_CMP_REF_PWM = led_model_P.Constant9_Value;
  led_model_B.PACE_CHARGE_CTRL = true;
  led_model_B.PACE_GND_CTRL = true;
  led_model_B.Z_ATR_CTRL = false;
  led_model_B.Z_VENT_CTRL = false;
  led_model_B.ATR_GND_CTRL = false;
  led_model_B.VENT_GND_CTRL = true;
  led_model_B.GREEN_LED = false;
}

/* Function for Chart: '<Root>/Modes' */
static void led_m_enter_atomic_AOO_Charging(void)
{
  led_model_B.ATR_PACE_CTRL = false;
  led_model_B.VENT_PACE_CTRL = false;

  /* Constant: '<Root>/Constant2' */
  led_model_B.PACING_REF_PWM = led_model_P.Constant2_Value;

  /* Constant: '<Root>/Constant10' */
  led_model_B.ATR_CMP_REF_PWM = led_model_P.Constant10_Value;
  led_model_B.PACE_CHARGE_CTRL = true;
  led_model_B.PACE_GND_CTRL = true;
  led_model_B.Z_ATR_CTRL = false;
  led_model_B.Z_VENT_CTRL = false;
  led_model_B.ATR_GND_CTRL = true;
  led_model_B.VENT_GND_CTRL = false;
  led_model_B.BLUE_LED = false;
}

static void SystemCore_rele_kbdg5qoxdrh4kbz(const
  freedomk64f_DigitalRead_led_m_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void SystemCore_dele_kbdg5qoxdrh4kbz(const
  freedomk64f_DigitalRead_led_m_T *obj)
{
  SystemCore_rele_kbdg5qoxdrh4kbz(obj);
}

static void matlabCodegenHa_kbdg5qoxdrh4kbz(freedomk64f_DigitalRead_led_m_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_dele_kbdg5qoxdrh4kbz(obj);
  }
}

static void led_mode_SystemCore_release_kbd(const
  freedomk64f_DigitalWrite_led__T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void led_model_SystemCore_delete_kbd(const
  freedomk64f_DigitalWrite_led__T *obj)
{
  led_mode_SystemCore_release_kbd(obj);
}

static void matlabCodegenHandle_matlabC_kbd(freedomk64f_DigitalWrite_led__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    led_model_SystemCore_delete_kbd(obj);
  }
}

static void led_model_SystemCore_release(const freedomk64f_PWMOutput_led_mod_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void led_model_SystemCore_delete(const freedomk64f_PWMOutput_led_mod_T
  *obj)
{
  led_model_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_PWMOutput_led_mod_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    led_model_SystemCore_delete(obj);
  }
}

/* Model step function */
void led_model_step(void)
{
  /* MATLABSystem: '<Root>/Digital Read' */
  if (led_model_DW.obj.SampleTime != led_model_P.DigitalRead_SampleTime) {
    led_model_DW.obj.SampleTime = led_model_P.DigitalRead_SampleTime;
  }

  MW_digitalIO_read(led_model_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<Root>/Digital Read' */

  /* MATLABSystem: '<Root>/Digital Read1' */
  if (led_model_DW.obj_g.SampleTime != led_model_P.DigitalRead1_SampleTime) {
    led_model_DW.obj_g.SampleTime = led_model_P.DigitalRead1_SampleTime;
  }

  MW_digitalIO_read(led_model_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<Root>/Digital Read1' */

  /* Chart: '<Root>/Modes' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
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
           led_model_P.Constant_Value - led_model_P.Constant3_Value)) {
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
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
          (led_model_P.Constant3_Value)) {
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
      if (led_model_P.Constant6_Value == 1.0) {
        led_model_DW.is_c3_led_model = led_model_IN_AOO_Charging;
        led_model_DW.temporalCounter_i1 = 0U;
        led_m_enter_atomic_AOO_Charging();
      } else {
        if (led_model_P.Constant6_Value == 0.0) {
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
           led_model_P.Constant_Value - led_model_P.Constant5_Value)) {
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
      }
      break;

     default:
      /* case IN_VOO_Pacing: */
      led_model_B.PACE_CHARGE_CTRL = false;
      led_model_B.PACE_GND_CTRL = true;
      led_model_B.ATR_PACE_CTRL = false;
      led_model_B.ATR_GND_CTRL = false;
      led_model_B.Z_ATR_CTRL = false;
      led_model_B.Z_VENT_CTRL = false;
      led_model_B.VENT_GND_CTRL = false;
      led_model_B.VENT_PACE_CTRL = true;
      led_model_B.GREEN_LED = true;
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
          (led_model_P.Constant5_Value)) {
        led_model_DW.is_c3_led_model = led_model_IN_VOO_Charging;
        led_model_DW.temporalCounter_i1 = 0U;
        led_m_enter_atomic_VOO_Charging();
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Modes' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(led_model_DW.obj_l.MW_DIGITALIO_HANDLE,
                     led_model_B.PACE_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(led_model_DW.obj_i.MW_DIGITALIO_HANDLE,
                     led_model_B.Z_ATR_CTRL);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(led_model_DW.obj_m.MW_DIGITALIO_HANDLE,
                     led_model_B.BLUE_LED);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(led_model_DW.obj_n.MW_DIGITALIO_HANDLE,
                     led_model_B.Z_VENT_CTRL);

  /* MATLABSystem: '<Root>/Digital Write20' */
  MW_digitalIO_write(led_model_DW.obj_b.MW_DIGITALIO_HANDLE,
                     led_model_B.FRONTEND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(led_model_DW.obj_l0.MW_DIGITALIO_HANDLE,
                     led_model_B.VENT_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(led_model_DW.obj_k.MW_DIGITALIO_HANDLE,
                     led_model_B.ATR_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(led_model_DW.obj_l5.MW_DIGITALIO_HANDLE,
                     led_model_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(led_model_DW.obj_e.MW_DIGITALIO_HANDLE,
                     led_model_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(led_model_DW.obj_h.MW_DIGITALIO_HANDLE,
                     led_model_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(led_model_DW.obj_lh.MW_DIGITALIO_HANDLE,
                     led_model_B.RED_LED);

  /* MATLABSystem: '<Root>/Digital Write9' */
  MW_digitalIO_write(led_model_DW.obj_o.MW_DIGITALIO_HANDLE,
                     led_model_B.GREEN_LED);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(led_model_DW.obj_j.MW_PWM_HANDLE,
                      led_model_B.PACING_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(led_model_DW.obj_ea.MW_PWM_HANDLE,
                      led_model_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output2' */
  MW_PWM_SetDutyCycle(led_model_DW.obj_a.MW_PWM_HANDLE,
                      led_model_B.ATR_CMP_REF_PWM);
}

/* Model initialize function */
void led_model_initialize(void)
{
  {
    freedomk64f_DigitalRead_led_m_T *obj;
    freedomk64f_DigitalWrite_led__T *obj_0;
    freedomk64f_PWMOutput_led_mod_T *obj_1;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    led_model_DW.obj.matlabCodegenIsDeleted = true;
    led_model_DW.obj.isInitialized = 0;
    led_model_DW.obj.SampleTime = -1.0;
    led_model_DW.obj.matlabCodegenIsDeleted = false;
    led_model_DW.obj.SampleTime = led_model_P.DigitalRead_SampleTime;
    obj = &led_model_DW.obj;
    led_model_DW.obj.isSetupComplete = false;
    led_model_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    led_model_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    led_model_DW.obj_g.matlabCodegenIsDeleted = true;
    led_model_DW.obj_g.isInitialized = 0;
    led_model_DW.obj_g.SampleTime = -1.0;
    led_model_DW.obj_g.matlabCodegenIsDeleted = false;
    led_model_DW.obj_g.SampleTime = led_model_P.DigitalRead1_SampleTime;
    obj = &led_model_DW.obj_g;
    led_model_DW.obj_g.isSetupComplete = false;
    led_model_DW.obj_g.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    led_model_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    led_model_DW.obj_l.matlabCodegenIsDeleted = true;
    led_model_DW.obj_l.isInitialized = 0;
    led_model_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_l;
    led_model_DW.obj_l.isSetupComplete = false;
    led_model_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    led_model_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    led_model_DW.obj_i.matlabCodegenIsDeleted = true;
    led_model_DW.obj_i.isInitialized = 0;
    led_model_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_i;
    led_model_DW.obj_i.isSetupComplete = false;
    led_model_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    led_model_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write10' */
    led_model_DW.obj_m.matlabCodegenIsDeleted = true;
    led_model_DW.obj_m.isInitialized = 0;
    led_model_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_m;
    led_model_DW.obj_m.isSetupComplete = false;
    led_model_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    led_model_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    led_model_DW.obj_n.matlabCodegenIsDeleted = true;
    led_model_DW.obj_n.isInitialized = 0;
    led_model_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_n;
    led_model_DW.obj_n.isSetupComplete = false;
    led_model_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    led_model_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write20' */
    led_model_DW.obj_b.matlabCodegenIsDeleted = true;
    led_model_DW.obj_b.isInitialized = 0;
    led_model_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_b;
    led_model_DW.obj_b.isSetupComplete = false;
    led_model_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    led_model_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    led_model_DW.obj_l0.matlabCodegenIsDeleted = true;
    led_model_DW.obj_l0.isInitialized = 0;
    led_model_DW.obj_l0.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_l0;
    led_model_DW.obj_l0.isSetupComplete = false;
    led_model_DW.obj_l0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    led_model_DW.obj_l0.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    led_model_DW.obj_k.matlabCodegenIsDeleted = true;
    led_model_DW.obj_k.isInitialized = 0;
    led_model_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_k;
    led_model_DW.obj_k.isSetupComplete = false;
    led_model_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    led_model_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    led_model_DW.obj_l5.matlabCodegenIsDeleted = true;
    led_model_DW.obj_l5.isInitialized = 0;
    led_model_DW.obj_l5.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_l5;
    led_model_DW.obj_l5.isSetupComplete = false;
    led_model_DW.obj_l5.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    led_model_DW.obj_l5.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write6' */
    led_model_DW.obj_e.matlabCodegenIsDeleted = true;
    led_model_DW.obj_e.isInitialized = 0;
    led_model_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_e;
    led_model_DW.obj_e.isSetupComplete = false;
    led_model_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    led_model_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    led_model_DW.obj_h.matlabCodegenIsDeleted = true;
    led_model_DW.obj_h.isInitialized = 0;
    led_model_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_h;
    led_model_DW.obj_h.isSetupComplete = false;
    led_model_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    led_model_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write8' */
    led_model_DW.obj_lh.matlabCodegenIsDeleted = true;
    led_model_DW.obj_lh.isInitialized = 0;
    led_model_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_lh;
    led_model_DW.obj_lh.isSetupComplete = false;
    led_model_DW.obj_lh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    led_model_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write9' */
    led_model_DW.obj_o.matlabCodegenIsDeleted = true;
    led_model_DW.obj_o.isInitialized = 0;
    led_model_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_o;
    led_model_DW.obj_o.isSetupComplete = false;
    led_model_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    led_model_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    led_model_DW.obj_j.matlabCodegenIsDeleted = true;
    led_model_DW.obj_j.isInitialized = 0;
    led_model_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_1 = &led_model_DW.obj_j;
    led_model_DW.obj_j.isSetupComplete = false;
    led_model_DW.obj_j.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(led_model_DW.obj_j.MW_PWM_HANDLE);
    led_model_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output1' */
    led_model_DW.obj_ea.matlabCodegenIsDeleted = true;
    led_model_DW.obj_ea.isInitialized = 0;
    led_model_DW.obj_ea.matlabCodegenIsDeleted = false;
    obj_1 = &led_model_DW.obj_ea;
    led_model_DW.obj_ea.isSetupComplete = false;
    led_model_DW.obj_ea.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 100.0);
    MW_PWM_Start(led_model_DW.obj_ea.MW_PWM_HANDLE);
    led_model_DW.obj_ea.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output2' */
    led_model_DW.obj_a.matlabCodegenIsDeleted = true;
    led_model_DW.obj_a.isInitialized = 0;
    led_model_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &led_model_DW.obj_a;
    led_model_DW.obj_a.isSetupComplete = false;
    led_model_DW.obj_a.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 100.0);
    MW_PWM_Start(led_model_DW.obj_a.MW_PWM_HANDLE);
    led_model_DW.obj_a.isSetupComplete = true;
  }
}

/* Model terminate function */
void led_model_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  matlabCodegenHa_kbdg5qoxdrh4kbz(&led_model_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Read1' */
  matlabCodegenHa_kbdg5qoxdrh4kbz(&led_model_DW.obj_g);

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_l);

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_i);

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_m);

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/Digital Write20' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_b);

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_l0);

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_k);

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_l5);

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_e);

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_h);

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_lh);

  /* Terminate for MATLABSystem: '<Root>/Digital Write9' */
  matlabCodegenHandle_matlabC_kbd(&led_model_DW.obj_o);

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  matlabCodegenHandle_matlabCodeg(&led_model_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  matlabCodegenHandle_matlabCodeg(&led_model_DW.obj_ea);

  /* Terminate for MATLABSystem: '<Root>/PWM Output2' */
  matlabCodegenHandle_matlabCodeg(&led_model_DW.obj_a);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
