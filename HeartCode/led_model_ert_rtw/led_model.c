/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_model.c
 *
 * Code generated for Simulink model 'led_model'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Nov  1 16:13:22 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "led_model.h"
#include "led_model_private.h"
#include "led_model_dt.h"

/* Named constants for Chart: '<Root>/Modes' */
#define led_model_IN_AAI               (1U)
#define led_model_IN_AOO_Charging      (2U)
#define led_model_IN_AOO_Pacing        (3U)
#define led_model_IN_Main              (4U)
#define led_model_IN_VOO_Charging      (5U)
#define led_model_IN_VOO_Pacing        (6U)
#define led_model_IN_VVI               (7U)

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

/* Function for Chart: '<Root>/Modes' */
static void led_m_enter_atomic_VOO_Charging(void)
{
  led_model_B.ATR_PACE_CTRL = false;
  led_model_B.VENT_PACE_CTRL = false;
  led_model_B.PACING_REF_PWM = led_model_B.V_AmplitudemV;
  led_model_B.PACE_CHARGE_CTRL = true;
  led_model_B.PACE_GND_CTRL = true;
  led_model_B.Z_ATR_CTRL = false;
  led_model_B.Z_VENT_CTRL = false;
  led_model_B.ATR_GND_CTRL = false;
  led_model_B.VENT_GND_CTRL = true;
  led_model_B.GREEN_LED = false;
  led_model_B.VENT_CMP_REF_PWM = led_model_B.V_SensmV;
}

/* Function for Chart: '<Root>/Modes' */
static void led_m_enter_atomic_AOO_Charging(void)
{
  led_model_B.ATR_PACE_CTRL = false;
  led_model_B.VENT_PACE_CTRL = false;
  led_model_B.PACING_REF_PWM = led_model_B.A_AmplitudemV;
  led_model_B.PACE_CHARGE_CTRL = true;
  led_model_B.PACE_GND_CTRL = true;
  led_model_B.Z_ATR_CTRL = false;
  led_model_B.Z_VENT_CTRL = false;
  led_model_B.ATR_GND_CTRL = true;
  led_model_B.VENT_GND_CTRL = false;
  led_model_B.BLUE_LED = false;
  led_model_B.RED_LED = false;
  led_model_B.ATR_CMP_REF_PWM = led_model_B.A_SensmV;
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

/* Model step function */
void led_model_step(void)
{
  /* Constant: '<S1>/LRL (ppm)' */
  led_model_B.LRLppm = led_model_P.LRLppm_Value;

  /* Constant: '<S1>/URL (ppm)' */
  led_model_B.URLppm = led_model_P.URLppm_Value;

  /* Constant: '<S1>/A_Amplitude (mV)' */
  led_model_B.A_AmplitudemV = led_model_P.A_AmplitudemV_Value;

  /* Constant: '<S1>/A_Pulse_Width (ms)' */
  led_model_B.A_Pulse_Widthms = led_model_P.A_Pulse_Widthms_Value;

  /* Constant: '<S1>/V_Amplitude (mV)' */
  led_model_B.V_AmplitudemV = led_model_P.V_AmplitudemV_Value;

  /* Constant: '<S1>/V_Pulse_Width (ms)' */
  led_model_B.V_Pulse_Widthms = led_model_P.V_Pulse_Widthms_Value;

  /* Constant: '<S1>/A_RefractoryPeriod (ms)' */
  led_model_B.A_RefractoryPeriodms = led_model_P.A_RefractoryPeriodms_Value;

  /* Constant: '<S1>/V_RefractoryPeriod (ms)' */
  led_model_B.V_RefractoryPeriodms = led_model_P.V_RefractoryPeriodms_Value;

  /* Constant: '<S1>/A_Sens (mV)' */
  led_model_B.A_SensmV = led_model_P.A_SensmV_Value;

  /* Constant: '<S1>/V_Sens (mV)' */
  led_model_B.V_SensmV = led_model_P.V_SensmV_Value;

  /* Constant: '<S1>/Rate_Smoothing (%)' */
  led_model_B.Rate_Smoothing = led_model_P.Rate_Smoothing_Value;

  /* Constant: '<S1>/Hysterisis (On // Off) (Off - 0, On - 1)' */
  led_model_B.HysterisisOnOffOff0On1 = led_model_P.HysterisisOnOffOff0On1_Value;

  /* Constant: '<S1>/PVARP (ms)' */
  led_model_B.PVARPms = led_model_P.PVARPms_Value;

  /* Constant: '<S1>/Mode (VOO - 0, VVI - 1, AOO - 2, AAI - 3)' */
  led_model_B.ModeVOO0VVI1AOO2AAI3 = led_model_P.ModeVOO0VVI1AOO2AAI3_Value;

  /* MATLABSystem: '<S1>/ATR_CMP_DETECT (ON // OFF)' */
  if (led_model_DW.obj.SampleTime != led_model_P.ATR_CMP_DETECTONOFF_SampleTime)
  {
    led_model_DW.obj.SampleTime = led_model_P.ATR_CMP_DETECTONOFF_SampleTime;
  }

  led_model_B.ATR_CMP_DETECTONOFF = MW_digitalIO_read
    (led_model_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/ATR_CMP_DETECT (ON // OFF)' */

  /* MATLABSystem: '<S1>/VENT_CMP_DETECT (ON // OFF)' */
  if (led_model_DW.obj_g.SampleTime !=
      led_model_P.VENT_CMP_DETECTONOFF_SampleTime) {
    led_model_DW.obj_g.SampleTime = led_model_P.VENT_CMP_DETECTONOFF_SampleTime;
  }

  led_model_B.VENT_CMP_DETECTONOFF = MW_digitalIO_read
    (led_model_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/VENT_CMP_DETECT (ON // OFF)' */

  /* Chart: '<Root>/Modes' */
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
      led_model_B.RED_LED = false;
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 /
           led_model_B.LRLppm - led_model_B.A_Pulse_Widthms)) {
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
      } else {
        if ((led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
             (led_model_B.A_RefractoryPeriodms)) &&
            ((led_model_B.ModeVOO0VVI1AOO2AAI3 == 3.0) &&
             led_model_B.ATR_CMP_DETECTONOFF)) {
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
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
          (led_model_B.A_Pulse_Widthms)) {
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
      if ((led_model_B.ModeVOO0VVI1AOO2AAI3 == 2.0) ||
          (led_model_B.ModeVOO0VVI1AOO2AAI3 == 3.0)) {
        led_model_DW.is_c3_led_model = led_model_IN_AOO_Charging;
        led_model_DW.temporalCounter_i1 = 0U;
        led_m_enter_atomic_AOO_Charging();
      } else {
        if ((led_model_B.ModeVOO0VVI1AOO2AAI3 == 0.0) ||
            (led_model_B.ModeVOO0VVI1AOO2AAI3 == 1.0)) {
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
           led_model_B.LRLppm - led_model_B.V_Pulse_Widthms)) {
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
      } else {
        if ((led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
             (led_model_B.V_RefractoryPeriodms)) &&
            ((led_model_B.ModeVOO0VVI1AOO2AAI3 == 1.0) &&
             led_model_B.VENT_CMP_DETECTONOFF)) {
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
      if (led_model_DW.temporalCounter_i1 >= (uint32_T)ceil
          (led_model_B.V_Pulse_Widthms)) {
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

  /* MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
  MW_digitalIO_write(led_model_DW.obj_l.MW_DIGITALIO_HANDLE,
                     led_model_B.ATR_CMP_REF_PWM != 0.0);

  /* MATLABSystem: '<S3>/Z_VENT_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_nv.MW_DIGITALIO_HANDLE,
                     led_model_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S3>/ATR_PACE_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_h.MW_DIGITALIO_HANDLE,
                     led_model_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S3>/VENT_PACE_CTRL' */
  MW_digitalIO_write(led_model_DW.obj_l5.MW_DIGITALIO_HANDLE,
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

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)led_model_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(led_model_M)!=-1) &&
        !((rtmGetTFinal(led_model_M)-led_model_M->Timing.taskTime0) >
          led_model_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(led_model_M, "Simulation finished");
    }

    if (rtmGetStopRequested(led_model_M)) {
      rtmSetErrorStatus(led_model_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  led_model_M->Timing.taskTime0 =
    ((time_T)(++led_model_M->Timing.clockTick0)) * led_model_M->Timing.stepSize0;
}

/* Model initialize function */
void led_model_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(led_model_M, 10.0);
  led_model_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  led_model_M->Sizes.checksums[0] = (558691100U);
  led_model_M->Sizes.checksums[1] = (3335803485U);
  led_model_M->Sizes.checksums[2] = (2604318023U);
  led_model_M->Sizes.checksums[3] = (1904522051U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[19];
    led_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(led_model_M->extModeInfo,
      &led_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(led_model_M->extModeInfo, led_model_M->Sizes.checksums);
    rteiSetTPtr(led_model_M->extModeInfo, rtmGetTPtr(led_model_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    led_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    freedomk64f_DigitalRead_led_m_T *obj;
    freedomk64f_DigitalWrite_led__T *obj_0;

    /* Start for Constant: '<S1>/LRL (ppm)' */
    led_model_B.LRLppm = led_model_P.LRLppm_Value;

    /* Start for Constant: '<S1>/URL (ppm)' */
    led_model_B.URLppm = led_model_P.URLppm_Value;

    /* Start for Constant: '<S1>/A_Amplitude (mV)' */
    led_model_B.A_AmplitudemV = led_model_P.A_AmplitudemV_Value;

    /* Start for Constant: '<S1>/A_Pulse_Width (ms)' */
    led_model_B.A_Pulse_Widthms = led_model_P.A_Pulse_Widthms_Value;

    /* Start for Constant: '<S1>/V_Amplitude (mV)' */
    led_model_B.V_AmplitudemV = led_model_P.V_AmplitudemV_Value;

    /* Start for Constant: '<S1>/V_Pulse_Width (ms)' */
    led_model_B.V_Pulse_Widthms = led_model_P.V_Pulse_Widthms_Value;

    /* Start for Constant: '<S1>/A_RefractoryPeriod (ms)' */
    led_model_B.A_RefractoryPeriodms = led_model_P.A_RefractoryPeriodms_Value;

    /* Start for Constant: '<S1>/V_RefractoryPeriod (ms)' */
    led_model_B.V_RefractoryPeriodms = led_model_P.V_RefractoryPeriodms_Value;

    /* Start for Constant: '<S1>/A_Sens (mV)' */
    led_model_B.A_SensmV = led_model_P.A_SensmV_Value;

    /* Start for Constant: '<S1>/V_Sens (mV)' */
    led_model_B.V_SensmV = led_model_P.V_SensmV_Value;

    /* Start for Constant: '<S1>/Rate_Smoothing (%)' */
    led_model_B.Rate_Smoothing = led_model_P.Rate_Smoothing_Value;

    /* Start for Constant: '<S1>/Hysterisis (On // Off) (Off - 0, On - 1)' */
    led_model_B.HysterisisOnOffOff0On1 =
      led_model_P.HysterisisOnOffOff0On1_Value;

    /* Start for Constant: '<S1>/PVARP (ms)' */
    led_model_B.PVARPms = led_model_P.PVARPms_Value;

    /* Start for Constant: '<S1>/Mode (VOO - 0, VVI - 1, AOO - 2, AAI - 3)' */
    led_model_B.ModeVOO0VVI1AOO2AAI3 = led_model_P.ModeVOO0VVI1AOO2AAI3_Value;

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

    /* Start for MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
    led_model_DW.obj_l.matlabCodegenIsDeleted = true;
    led_model_DW.obj_l.isInitialized = 0;
    led_model_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_l;
    led_model_DW.obj_l.isSetupComplete = false;
    led_model_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(6U, 1);
    led_model_DW.obj_l.isSetupComplete = true;

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
    led_model_DW.obj_l5.matlabCodegenIsDeleted = true;
    led_model_DW.obj_l5.isInitialized = 0;
    led_model_DW.obj_l5.matlabCodegenIsDeleted = false;
    obj_0 = &led_model_DW.obj_l5;
    led_model_DW.obj_l5.isSetupComplete = false;
    led_model_DW.obj_l5.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    led_model_DW.obj_l5.isSetupComplete = true;

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

  /* Terminate for MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/Z_VENT_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_nv);

  /* Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_h);

  /* Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRL' */
  matlabCodegenHandle_matlabCo_kb(&led_model_DW.obj_l5);

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
