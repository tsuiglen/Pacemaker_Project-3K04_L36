/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_model.c
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

#include "led_model.h"
#include "led_model_private.h"

/* Named constants for Chart: '<Root>/LED_LOGIC' */
#define led_model_IN_LED_OFF           ((uint8_T)1U)
#define led_model_IN_LED_ON            ((uint8_T)2U)

/* Block states (default storage) */
DW_led_model_T led_model_DW;

/* Real-time model */
RT_MODEL_led_model_T led_model_M_;
RT_MODEL_led_model_T *const led_model_M = &led_model_M_;

/* Forward declaration for local functions */
static void led_model_SystemCore_release(const freedomk64f_DigitalWrite_led__T
  *obj);
static void led_model_SystemCore_delete(const freedomk64f_DigitalWrite_led__T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_led__T *obj);
static void led_model_SystemCore_release(const freedomk64f_DigitalWrite_led__T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void led_model_SystemCore_delete(const freedomk64f_DigitalWrite_led__T
  *obj)
{
  led_model_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_led__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    led_model_SystemCore_delete(obj);
  }
}

/* Model step function */
void led_model_step(void)
{
  int32_T rtb_LED_STATE;

  /* Chart: '<Root>/LED_LOGIC' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (led_model_DW.temporalCounter_i1 < MAX_uint32_T) {
    led_model_DW.temporalCounter_i1++;
  }

  if (led_model_DW.is_active_c3_led_model == 0U) {
    led_model_DW.is_active_c3_led_model = 1U;
    led_model_DW.is_c3_led_model = led_model_IN_LED_OFF;
    led_model_DW.temporalCounter_i1 = 0U;
    rtb_LED_STATE = 0;
  } else if (led_model_DW.is_c3_led_model == led_model_IN_LED_OFF) {
    rtb_LED_STATE = 0;
    if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
        (led_model_P.Constant_Value)) {
      led_model_DW.is_c3_led_model = led_model_IN_LED_ON;
      led_model_DW.temporalCounter_i1 = 0U;
      rtb_LED_STATE = 1;
    }
  } else {
    /* case IN_LED_ON: */
    rtb_LED_STATE = 1;
    if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
        (led_model_P.Constant1_Value)) {
      led_model_DW.is_c3_led_model = led_model_IN_LED_OFF;
      led_model_DW.temporalCounter_i1 = 0U;
      rtb_LED_STATE = 0;
    }
  }

  /* End of Chart: '<Root>/LED_LOGIC' */

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(led_model_DW.obj.MW_DIGITALIO_HANDLE, rtb_LED_STATE != 0);
}

/* Model initialize function */
void led_model_initialize(void)
{
  {
    freedomk64f_DigitalWrite_led__T *obj;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    led_model_DW.obj.matlabCodegenIsDeleted = true;
    led_model_DW.obj.isInitialized = 0;
    led_model_DW.obj.matlabCodegenIsDeleted = false;
    obj = &led_model_DW.obj;
    led_model_DW.obj.isSetupComplete = false;
    led_model_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    led_model_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void led_model_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&led_model_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
