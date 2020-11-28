/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HeartCode.c
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
#include "rt_roundd_snf.h"

/* Named constants for Chart: '<Root>/COM_IN' */
#define HeartCode_IN_ECHO_PARAM        ((uint8_T)1U)
#define HeartCode_IN_INITIAL           ((uint8_T)2U)
#define HeartCode_IN_SET_PARAM         ((uint8_T)3U)
#define HeartCode_IN_STANDBY           ((uint8_T)4U)

/* Named constants for Chart: '<Root>/Modes' */
#define HeartCode_IN_AAI               ((uint8_T)1U)
#define HeartCode_IN_AOO_Charging      ((uint8_T)2U)
#define HeartCode_IN_AOO_Pacing        ((uint8_T)3U)
#define HeartCode_IN_DOO_Charging      ((uint8_T)4U)
#define HeartCode_IN_DOO_Charging1     ((uint8_T)5U)
#define HeartCode_IN_DOO_Pacing        ((uint8_T)6U)
#define HeartCode_IN_DOO_Pacing1       ((uint8_T)7U)
#define HeartCode_IN_Main              ((uint8_T)8U)
#define HeartCode_IN_VOO_Charging      ((uint8_T)9U)
#define HeartCode_IN_VOO_Pacing        ((uint8_T)10U)
#define HeartCode_IN_VVI               ((uint8_T)11U)

/* Block signals (default storage) */
B_HeartCode_T HeartCode_B;

/* Block states (default storage) */
DW_HeartCode_T HeartCode_DW;

/* Real-time model */
RT_MODEL_HeartCode_T HeartCode_M_;
RT_MODEL_HeartCode_T *const HeartCode_M = &HeartCode_M_;

/* Forward declaration for local functions */
static void Heart_enter_atomic_VOO_Charging(const real_T *Divide1, const real_T *
  Divide2);
static void Heart_enter_atomic_AOO_Charging(const real_T *Divide3, const real_T *
  Divide);
static void HeartCode_AOO_Charging(const boolean_T *ATR_CMP_DETECTONOFF);
static void HeartCode_AOO_Pacing(const real_T *Divide3, const real_T *Divide);
static void Heart_enter_atomic_DOO_Charging(const real_T *Divide);
static void HeartCode_SystemCore_release_p(const freedomk64f_SCIRead_HeartCode_T
  *obj);
static void HeartCode_SystemCore_delete_p(const freedomk64f_SCIRead_HeartCode_T *
  obj);
static void matlabCodegenHandle_matlabCod_p(freedomk64f_SCIRead_HeartCode_T *obj);
static void HeartCode_SystemCore_release_p0(const
  freedomk64f_DigitalRead_Heart_T *obj);
static void HeartCode_SystemCore_delete_p0(const freedomk64f_DigitalRead_Heart_T
  *obj);
static void matlabCodegenHandle_matlabCo_p0(freedomk64f_DigitalRead_Heart_T *obj);
static void HeartCo_SystemCore_release_p02k(const
  freedomk64f_DigitalWrite_Hear_T *obj);
static void HeartCod_SystemCore_delete_p02k(const
  freedomk64f_DigitalWrite_Hear_T *obj);
static void matlabCodegenHandle_matlab_p02k(freedomk64f_DigitalWrite_Hear_T *obj);
static void SystemCore_relea_p02kby122gfybv(const
  freedomk64f_PWMOutput_HeartCo_T *obj);
static void SystemCore_delet_p02kby122gfybv(const
  freedomk64f_PWMOutput_HeartCo_T *obj);
static void matlabCodegenHan_p02kby122gfybv(freedomk64f_PWMOutput_HeartCo_T *obj);
static void HeartCode_SystemCore_setup_p(freedomk64f_SCIRead_HeartCode_T *obj);

/* Function for Chart: '<Root>/Modes' */
static void Heart_enter_atomic_VOO_Charging(const real_T *Divide1, const real_T *
  Divide2)
{
  HeartCode_B.ATR_PACE_CTRL = false;
  HeartCode_B.VENT_PACE_CTRL = false;
  HeartCode_B.PACING_REF_PWM = *Divide1;
  HeartCode_B.PACE_CHARGE_CTRL = true;
  HeartCode_B.PACE_GND_CTRL = true;
  HeartCode_B.Z_ATR_CTRL = false;
  HeartCode_B.Z_VENT_CTRL = false;
  HeartCode_B.ATR_GND_CTRL = false;
  HeartCode_B.VENT_GND_CTRL = true;
  HeartCode_B.GREEN_LED = false;
  HeartCode_B.VENT_CMP_REF_PWM = *Divide2;
}

/* Function for Chart: '<Root>/Modes' */
static void Heart_enter_atomic_AOO_Charging(const real_T *Divide3, const real_T *
  Divide)
{
  HeartCode_B.ATR_PACE_CTRL = false;
  HeartCode_B.VENT_PACE_CTRL = false;
  HeartCode_B.PACING_REF_PWM = *Divide;
  HeartCode_B.PACE_CHARGE_CTRL = true;
  HeartCode_B.PACE_GND_CTRL = true;
  HeartCode_B.Z_ATR_CTRL = false;
  HeartCode_B.Z_VENT_CTRL = false;
  HeartCode_B.ATR_GND_CTRL = true;
  HeartCode_B.VENT_GND_CTRL = false;
  HeartCode_B.BLUE_LED = false;
  HeartCode_B.RED_LED = false;
  HeartCode_B.ATR_CMP_REF_PWM = *Divide3;
}

/* Function for Chart: '<Root>/Modes' */
static void HeartCode_AOO_Charging(const boolean_T *ATR_CMP_DETECTONOFF)
{
  HeartCode_B.ATR_PACE_CTRL = false;
  HeartCode_B.VENT_PACE_CTRL = false;
  HeartCode_B.PACE_CHARGE_CTRL = true;
  HeartCode_B.PACE_GND_CTRL = true;
  HeartCode_B.Z_ATR_CTRL = false;
  HeartCode_B.Z_VENT_CTRL = false;
  HeartCode_B.ATR_GND_CTRL = true;
  HeartCode_B.VENT_GND_CTRL = false;
  HeartCode_B.BLUE_LED = false;
  HeartCode_B.RED_LED = false;
  HeartCode_B.d = rt_roundd_snf(60000.0 / (real_T)HeartCode_B.in_LRL);
  if (HeartCode_B.d < 65536.0) {
    HeartCode_B.u2 = (uint16_T)HeartCode_B.d;
  } else {
    HeartCode_B.u2 = MAX_uint16_T;
  }

  HeartCode_B.qY_m = (uint32_T)HeartCode_B.u2 - /*MW:OvSatOk*/
    HeartCode_DW.AdeltaT;
  if (HeartCode_B.qY_m > HeartCode_B.u2) {
    HeartCode_B.qY_m = 0U;
  }

  if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.qY_m) {
    HeartCode_DW.AdeltaT = 0U;
    HeartCode_DW.is_c3_HeartCode = HeartCode_IN_AOO_Pacing;
    HeartCode_DW.temporalCounter_i1 = 0U;
    HeartCode_B.PACE_CHARGE_CTRL = false;
    HeartCode_B.PACE_GND_CTRL = true;
    HeartCode_B.ATR_PACE_CTRL = true;
    HeartCode_B.ATR_GND_CTRL = false;
    HeartCode_B.Z_ATR_CTRL = false;
    HeartCode_B.Z_VENT_CTRL = false;
    HeartCode_B.VENT_GND_CTRL = false;
    HeartCode_B.VENT_PACE_CTRL = false;
    HeartCode_B.BLUE_LED = true;
  } else {
    if ((HeartCode_B.in_Mode == 3) && (*ATR_CMP_DETECTONOFF)) {
      HeartCode_DW.AdeltaT = 0U;
      HeartCode_DW.is_c3_HeartCode = HeartCode_IN_AAI;
      HeartCode_DW.temporalCounter_i1 = 0U;
      HeartCode_B.RED_LED = true;
    }
  }
}

/* Function for Chart: '<Root>/Modes' */
static void HeartCode_AOO_Pacing(const real_T *Divide3, const real_T *Divide)
{
  HeartCode_B.PACE_CHARGE_CTRL = false;
  HeartCode_B.PACE_GND_CTRL = true;
  HeartCode_B.ATR_PACE_CTRL = true;
  HeartCode_B.ATR_GND_CTRL = false;
  HeartCode_B.Z_ATR_CTRL = false;
  HeartCode_B.Z_VENT_CTRL = false;
  HeartCode_B.VENT_GND_CTRL = false;
  HeartCode_B.VENT_PACE_CTRL = false;
  HeartCode_B.BLUE_LED = true;
  if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.in_A_Pulse_Width) {
    HeartCode_B.u = (uint32_T)HeartCode_DW.AdeltaT +
      HeartCode_B.in_A_Pulse_Width;
    if (HeartCode_B.u > 65535U) {
      HeartCode_B.u = 65535U;
    }

    HeartCode_DW.AdeltaT = (uint16_T)HeartCode_B.u;
    switch (HeartCode_B.in_Mode) {
     case 2:
      HeartCode_DW.is_c3_HeartCode = HeartCode_IN_AOO_Charging;
      HeartCode_DW.temporalCounter_i1 = 0U;
      Heart_enter_atomic_AOO_Charging(Divide3, Divide);
      break;

     case 3:
      HeartCode_DW.is_c3_HeartCode = HeartCode_IN_AAI;
      HeartCode_DW.temporalCounter_i1 = 0U;
      HeartCode_B.RED_LED = true;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Modes' */
static void Heart_enter_atomic_DOO_Charging(const real_T *Divide)
{
  HeartCode_B.ATR_PACE_CTRL = false;
  HeartCode_B.VENT_PACE_CTRL = false;
  HeartCode_B.PACING_REF_PWM = *Divide;
  HeartCode_B.PACE_CHARGE_CTRL = true;
  HeartCode_B.PACE_GND_CTRL = true;
  HeartCode_B.Z_ATR_CTRL = false;
  HeartCode_B.Z_VENT_CTRL = false;
  HeartCode_B.ATR_GND_CTRL = false;
  HeartCode_B.VENT_GND_CTRL = true;
  HeartCode_B.BLUE_LED = false;
  HeartCode_B.GREEN_LED = false;
}

static void HeartCode_SystemCore_release_p(const freedomk64f_SCIRead_HeartCode_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void HeartCode_SystemCore_delete_p(const freedomk64f_SCIRead_HeartCode_T *
  obj)
{
  HeartCode_SystemCore_release_p(obj);
}

static void matlabCodegenHandle_matlabCod_p(freedomk64f_SCIRead_HeartCode_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    HeartCode_SystemCore_delete_p(obj);
  }
}

static void HeartCode_SystemCore_release_p0(const
  freedomk64f_DigitalRead_Heart_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void HeartCode_SystemCore_delete_p0(const freedomk64f_DigitalRead_Heart_T
  *obj)
{
  HeartCode_SystemCore_release_p0(obj);
}

static void matlabCodegenHandle_matlabCo_p0(freedomk64f_DigitalRead_Heart_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    HeartCode_SystemCore_delete_p0(obj);
  }
}

static void HeartCo_SystemCore_release_p02k(const
  freedomk64f_DigitalWrite_Hear_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void HeartCod_SystemCore_delete_p02k(const
  freedomk64f_DigitalWrite_Hear_T *obj)
{
  HeartCo_SystemCore_release_p02k(obj);
}

static void matlabCodegenHandle_matlab_p02k(freedomk64f_DigitalWrite_Hear_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    HeartCod_SystemCore_delete_p02k(obj);
  }
}

static void SystemCore_relea_p02kby122gfybv(const
  freedomk64f_PWMOutput_HeartCo_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void SystemCore_delet_p02kby122gfybv(const
  freedomk64f_PWMOutput_HeartCo_T *obj)
{
  SystemCore_relea_p02kby122gfybv(obj);
}

static void matlabCodegenHan_p02kby122gfybv(freedomk64f_PWMOutput_HeartCo_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delet_p02kby122gfybv(obj);
  }
}

static void HeartCode_SystemCore_setup_p(freedomk64f_SCIRead_HeartCode_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  HeartCode_B.TxPinLoc = MW_UNDEFINED_VALUE;
  HeartCode_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&HeartCode_B.SCIModuleLoc, false, 10U,
    HeartCode_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  HeartCode_B.StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        HeartCode_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void HeartCode_step(void)
{
  boolean_T ATR_CMP_DETECTONOFF;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (HeartCode_DW.obj_d.SampleTime != HeartCode_P.SerialReceive_SampleTime) {
    HeartCode_DW.obj_d.SampleTime = HeartCode_P.SerialReceive_SampleTime;
  }

  HeartCode_B.status = MW_SCI_Receive(HeartCode_DW.obj_d.MW_SCIHANDLE,
    HeartCode_B.RxDataLocChar, 33U);
  memcpy((void *)&HeartCode_B.RxData[0], (void *)&HeartCode_B.RxDataLocChar[0],
         (uint32_T)((size_t)33 * sizeof(uint8_T)));

  /* Chart: '<Root>/COM_IN' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  switch (HeartCode_DW.is_c1_HeartCode) {
   case HeartCode_IN_ECHO_PARAM:
    HeartCode_DW.is_c1_HeartCode = HeartCode_IN_STANDBY;
    break;

   case HeartCode_IN_INITIAL:
    HeartCode_DW.is_c1_HeartCode = HeartCode_IN_STANDBY;
    break;

   case HeartCode_IN_SET_PARAM:
    HeartCode_DW.is_c1_HeartCode = HeartCode_IN_STANDBY;
    break;

   default:
    /* case IN_STANDBY: */
    if (HeartCode_B.status == 0) {
      if (HeartCode_B.RxData[0] == 22) {
        switch (HeartCode_B.RxData[1]) {
         case 85:
          HeartCode_DW.is_c1_HeartCode = HeartCode_IN_SET_PARAM;
          HeartCode_B.in_Mode = HeartCode_B.RxData[2];
          HeartCode_B.in_LRL = HeartCode_B.RxData[3];
          HeartCode_B.in_URL = HeartCode_B.RxData[4];
          memcpy((void *)&HeartCode_B.in_A_Amplitude_k, (void *)
                 &HeartCode_B.RxData[5], (uint32_T)((size_t)1 * sizeof(uint16_T)));
          HeartCode_B.in_A_Pulse_Width = HeartCode_B.RxData[7];
          memcpy((void *)&HeartCode_B.in_V_Amplitude_a, (void *)
                 &HeartCode_B.RxData[8], (uint32_T)((size_t)1 * sizeof(uint16_T)));
          HeartCode_B.in_V_Pulse_Width = HeartCode_B.RxData[10];
          memcpy((void *)&HeartCode_B.in_A_RefractoryPeriod_n, (void *)
                 &HeartCode_B.RxData[11], (uint32_T)((size_t)1 * sizeof(uint16_T)));
          memcpy((void *)&HeartCode_B.in_V_RefractoryPeriod_p, (void *)
                 &HeartCode_B.RxData[13], (uint32_T)((size_t)1 * sizeof(uint16_T)));
          memcpy((void *)&HeartCode_B.in_A_Sens_i, (void *)&HeartCode_B.RxData
                 [15], (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&HeartCode_B.in_V_Sens_e, (void *)&HeartCode_B.RxData
                 [19], (uint32_T)((size_t)1 * sizeof(real32_T)));
          HeartCode_B.in_Rate_Smoothing = HeartCode_B.RxData[23];
          memcpy((void *)&HeartCode_B.in_PVARP_j, (void *)&HeartCode_B.RxData[24],
                 (uint32_T)((size_t)1 * sizeof(uint16_T)));
          memcpy((void *)&HeartCode_B.in_fixedAVDelay_d, (void *)
                 &HeartCode_B.RxData[26], (uint32_T)((size_t)1 * sizeof(uint16_T)));
          HeartCode_B.in_maxSensRate = HeartCode_B.RxData[28];
          HeartCode_B.in_ActivityThreshold = HeartCode_B.RxData[29];
          HeartCode_B.in_ReactionTime = HeartCode_B.RxData[30];
          HeartCode_B.in_ResponseFactor = HeartCode_B.RxData[31];
          HeartCode_B.in_RecoveryTime = HeartCode_B.RxData[32];
          break;

         case 34:
          HeartCode_DW.is_c1_HeartCode = HeartCode_IN_ECHO_PARAM;
          send_params();
          break;

         default:
          HeartCode_DW.is_c1_HeartCode = HeartCode_IN_STANDBY;
          break;
        }
      } else {
        HeartCode_DW.is_c1_HeartCode = HeartCode_IN_STANDBY;
      }
    }
    break;
  }

  /* End of Chart: '<Root>/COM_IN' */

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/50mV to Atrial Duty Cycle'
   */
  HeartCode_B.Divide = (real_T)HeartCode_B.in_A_Amplitude_k /
    HeartCode_P.u0mVtoAtrialDutyCycle_Value;

  /* Product: '<S3>/Divide1' incorporates:
   *  Constant: '<S3>/50mV to Ventricle Duty Cycle'
   */
  HeartCode_B.Divide1 = (real_T)HeartCode_B.in_V_Amplitude_a /
    HeartCode_P.u0mVtoVentricleDutyCycle_Value;

  /* Product: '<S3>/Divide3' incorporates:
   *  Constant: '<S3>/50mV to Atr Duty Cycle1'
   *  Product: '<S3>/Product'
   */
  HeartCode_B.Divide3 = HeartCode_B.in_A_Sens_i * (real32_T)
    HeartCode_B.in_A_Amplitude_k / HeartCode_P.u0mVtoAtrDutyCycle1_Value;

  /* Product: '<S3>/Divide2' incorporates:
   *  Constant: '<S3>/50mV to Vent Duty Cycle'
   *  Product: '<S3>/Product1'
   */
  HeartCode_B.Divide2 = HeartCode_B.in_V_Sens_e * (real32_T)
    HeartCode_B.in_V_Amplitude_a / HeartCode_P.u0mVtoVentDutyCycle_Value;

  /* MATLABSystem: '<S3>/ATR_CMP_DETECT (ON // OFF)' */
  if (HeartCode_DW.obj.SampleTime != HeartCode_P.ATR_CMP_DETECTONOFF_SampleTime)
  {
    HeartCode_DW.obj.SampleTime = HeartCode_P.ATR_CMP_DETECTONOFF_SampleTime;
  }

  ATR_CMP_DETECTONOFF = MW_digitalIO_read(HeartCode_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S3>/ATR_CMP_DETECT (ON // OFF)' */

  /* MATLABSystem: '<S3>/VENT_CMP_DETECT (ON // OFF)' */
  if (HeartCode_DW.obj_g.SampleTime !=
      HeartCode_P.VENT_CMP_DETECTONOFF_SampleTime) {
    HeartCode_DW.obj_g.SampleTime = HeartCode_P.VENT_CMP_DETECTONOFF_SampleTime;
  }

  HeartCode_B.b = MW_digitalIO_read(HeartCode_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Modes' incorporates:
   *  MATLABSystem: '<S3>/VENT_CMP_DETECT (ON // OFF)'
   */
  if (HeartCode_DW.temporalCounter_i1 < MAX_uint32_T) {
    HeartCode_DW.temporalCounter_i1++;
  }

  if (HeartCode_DW.is_active_c3_HeartCode == 0U) {
    HeartCode_DW.is_active_c3_HeartCode = 1U;
    HeartCode_DW.is_c3_HeartCode = HeartCode_IN_Main;
    HeartCode_B.BLUE_LED = false;
    HeartCode_B.RED_LED = false;
    HeartCode_B.GREEN_LED = false;
    HeartCode_B.PACING_REF_PWM = 0.0;
    HeartCode_B.FRONTEND_CTRL = true;
  } else {
    switch (HeartCode_DW.is_c3_HeartCode) {
     case HeartCode_IN_AAI:
      HeartCode_B.RED_LED = true;
      if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.in_A_RefractoryPeriod_n)
      {
        HeartCode_B.qY = (uint32_T)HeartCode_DW.AdeltaT +
          HeartCode_B.in_A_RefractoryPeriod_n;
        if (HeartCode_B.qY > 65535U) {
          HeartCode_B.qY = 65535U;
        }

        HeartCode_DW.AdeltaT = (uint16_T)HeartCode_B.qY;
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_AOO_Charging;
        HeartCode_DW.temporalCounter_i1 = 0U;
        Heart_enter_atomic_AOO_Charging(&HeartCode_B.Divide3,
          &HeartCode_B.Divide);
      }
      break;

     case HeartCode_IN_AOO_Charging:
      HeartCode_AOO_Charging(&ATR_CMP_DETECTONOFF);
      break;

     case HeartCode_IN_AOO_Pacing:
      HeartCode_AOO_Pacing(&HeartCode_B.Divide3, &HeartCode_B.Divide);
      break;

     case HeartCode_IN_DOO_Charging:
      HeartCode_B.ATR_PACE_CTRL = false;
      HeartCode_B.VENT_PACE_CTRL = false;
      HeartCode_B.PACE_CHARGE_CTRL = true;
      HeartCode_B.PACE_GND_CTRL = true;
      HeartCode_B.Z_ATR_CTRL = false;
      HeartCode_B.Z_VENT_CTRL = false;
      HeartCode_B.ATR_GND_CTRL = false;
      HeartCode_B.VENT_GND_CTRL = true;
      HeartCode_B.BLUE_LED = false;
      HeartCode_B.GREEN_LED = false;
      HeartCode_B.Divide = rt_roundd_snf(60000.0 / (real_T)HeartCode_B.in_LRL);
      if (HeartCode_B.Divide < 256.0) {
        HeartCode_B.status = (uint8_T)HeartCode_B.Divide;
      } else {
        HeartCode_B.status = MAX_uint8_T;
      }

      HeartCode_B.qY = (uint32_T)HeartCode_B.status - /*MW:OvSatOk*/
        HeartCode_B.in_A_Pulse_Width;
      if (HeartCode_B.qY > HeartCode_B.status) {
        HeartCode_B.qY = 0U;
      }

      if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.qY) {
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_DOO_Pacing;
        HeartCode_DW.temporalCounter_i1 = 0U;
        HeartCode_B.PACE_CHARGE_CTRL = false;
        HeartCode_B.PACE_GND_CTRL = true;
        HeartCode_B.ATR_PACE_CTRL = true;
        HeartCode_B.ATR_GND_CTRL = false;
        HeartCode_B.Z_ATR_CTRL = false;
        HeartCode_B.Z_VENT_CTRL = false;
        HeartCode_B.VENT_GND_CTRL = false;
        HeartCode_B.VENT_PACE_CTRL = false;
        HeartCode_B.BLUE_LED = true;
      }
      break;

     case HeartCode_IN_DOO_Charging1:
      HeartCode_B.ATR_PACE_CTRL = false;
      HeartCode_B.VENT_PACE_CTRL = false;
      HeartCode_B.PACE_CHARGE_CTRL = true;
      HeartCode_B.PACE_GND_CTRL = true;
      HeartCode_B.Z_ATR_CTRL = false;
      HeartCode_B.Z_VENT_CTRL = false;
      HeartCode_B.ATR_GND_CTRL = true;
      HeartCode_B.VENT_GND_CTRL = false;
      HeartCode_B.BLUE_LED = false;
      HeartCode_B.GREEN_LED = false;
      HeartCode_B.Divide = rt_roundd_snf(60000.0 / (real_T)HeartCode_B.in_LRL);
      if (HeartCode_B.Divide < 65536.0) {
        HeartCode_B.u1 = (uint16_T)HeartCode_B.Divide;
      } else {
        HeartCode_B.u1 = MAX_uint16_T;
      }

      HeartCode_B.qY = (uint32_T)HeartCode_B.u1 - /*MW:OvSatOk*/
        HeartCode_B.in_V_Pulse_Width;
      if (HeartCode_B.qY > HeartCode_B.u1) {
        HeartCode_B.qY = 0U;
      }

      HeartCode_B.qY += HeartCode_B.in_fixedAVDelay_d;
      if (HeartCode_B.qY > 65535U) {
        HeartCode_B.qY = 65535U;
      }

      if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.qY) {
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_DOO_Pacing1;
        HeartCode_DW.temporalCounter_i1 = 0U;
        HeartCode_B.PACE_CHARGE_CTRL = false;
        HeartCode_B.PACE_GND_CTRL = true;
        HeartCode_B.ATR_PACE_CTRL = false;
        HeartCode_B.ATR_GND_CTRL = false;
        HeartCode_B.Z_ATR_CTRL = false;
        HeartCode_B.Z_VENT_CTRL = false;
        HeartCode_B.VENT_GND_CTRL = false;
        HeartCode_B.VENT_PACE_CTRL = true;
        HeartCode_B.GREEN_LED = true;
      }
      break;

     case HeartCode_IN_DOO_Pacing:
      HeartCode_B.PACE_CHARGE_CTRL = false;
      HeartCode_B.PACE_GND_CTRL = true;
      HeartCode_B.ATR_PACE_CTRL = true;
      HeartCode_B.ATR_GND_CTRL = false;
      HeartCode_B.Z_ATR_CTRL = false;
      HeartCode_B.Z_VENT_CTRL = false;
      HeartCode_B.VENT_GND_CTRL = false;
      HeartCode_B.VENT_PACE_CTRL = false;
      HeartCode_B.BLUE_LED = true;
      if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.in_A_Pulse_Width) {
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_DOO_Charging1;
        HeartCode_DW.temporalCounter_i1 = 0U;
        HeartCode_B.ATR_PACE_CTRL = false;
        HeartCode_B.VENT_PACE_CTRL = false;
        HeartCode_B.PACING_REF_PWM = HeartCode_B.Divide1;
        HeartCode_B.PACE_CHARGE_CTRL = true;
        HeartCode_B.PACE_GND_CTRL = true;
        HeartCode_B.Z_ATR_CTRL = false;
        HeartCode_B.Z_VENT_CTRL = false;
        HeartCode_B.ATR_GND_CTRL = true;
        HeartCode_B.VENT_GND_CTRL = false;
        HeartCode_B.BLUE_LED = false;
        HeartCode_B.GREEN_LED = false;
      }
      break;

     case HeartCode_IN_DOO_Pacing1:
      HeartCode_B.PACE_CHARGE_CTRL = false;
      HeartCode_B.PACE_GND_CTRL = true;
      HeartCode_B.ATR_PACE_CTRL = false;
      HeartCode_B.ATR_GND_CTRL = false;
      HeartCode_B.Z_ATR_CTRL = false;
      HeartCode_B.Z_VENT_CTRL = false;
      HeartCode_B.VENT_GND_CTRL = false;
      HeartCode_B.VENT_PACE_CTRL = true;
      HeartCode_B.GREEN_LED = true;
      if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.in_V_Pulse_Width) {
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_DOO_Charging;
        HeartCode_DW.temporalCounter_i1 = 0U;
        Heart_enter_atomic_DOO_Charging(&HeartCode_B.Divide);
      }
      break;

     case HeartCode_IN_Main:
      HeartCode_B.BLUE_LED = false;
      HeartCode_B.RED_LED = false;
      HeartCode_B.GREEN_LED = false;
      HeartCode_B.FRONTEND_CTRL = true;
      if ((HeartCode_B.in_Mode == 2) || (HeartCode_B.in_Mode == 3)) {
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_AOO_Charging;
        HeartCode_DW.temporalCounter_i1 = 0U;
        Heart_enter_atomic_AOO_Charging(&HeartCode_B.Divide3,
          &HeartCode_B.Divide);
      } else if ((HeartCode_B.in_Mode == 0) || (HeartCode_B.in_Mode == 1)) {
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_VOO_Charging;
        HeartCode_DW.temporalCounter_i1 = 0U;
        Heart_enter_atomic_VOO_Charging(&HeartCode_B.Divide1,
          &HeartCode_B.Divide2);
      } else {
        if (HeartCode_B.in_Mode == 4) {
          HeartCode_DW.is_c3_HeartCode = HeartCode_IN_DOO_Charging;
          HeartCode_DW.temporalCounter_i1 = 0U;
          Heart_enter_atomic_DOO_Charging(&HeartCode_B.Divide);
        }
      }
      break;

     case HeartCode_IN_VOO_Charging:
      HeartCode_B.ATR_PACE_CTRL = false;
      HeartCode_B.VENT_PACE_CTRL = false;
      HeartCode_B.PACE_CHARGE_CTRL = true;
      HeartCode_B.PACE_GND_CTRL = true;
      HeartCode_B.Z_ATR_CTRL = false;
      HeartCode_B.Z_VENT_CTRL = false;
      HeartCode_B.ATR_GND_CTRL = false;
      HeartCode_B.VENT_GND_CTRL = true;
      HeartCode_B.GREEN_LED = false;
      HeartCode_B.Divide = rt_roundd_snf(60000.0 / (real_T)HeartCode_B.in_LRL);
      if (HeartCode_B.Divide < 65536.0) {
        HeartCode_B.u1 = (uint16_T)HeartCode_B.Divide;
      } else {
        HeartCode_B.u1 = MAX_uint16_T;
      }

      HeartCode_B.qY = (uint32_T)HeartCode_B.u1 - /*MW:OvSatOk*/
        HeartCode_DW.VdeltaT;
      if (HeartCode_B.qY > HeartCode_B.u1) {
        HeartCode_B.qY = 0U;
      }

      if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.qY) {
        HeartCode_DW.VdeltaT = 0U;
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_VOO_Pacing;
        HeartCode_DW.temporalCounter_i1 = 0U;
        HeartCode_B.PACE_CHARGE_CTRL = false;
        HeartCode_B.PACE_GND_CTRL = true;
        HeartCode_B.ATR_PACE_CTRL = false;
        HeartCode_B.ATR_GND_CTRL = false;
        HeartCode_B.Z_ATR_CTRL = false;
        HeartCode_B.Z_VENT_CTRL = false;
        HeartCode_B.VENT_GND_CTRL = false;
        HeartCode_B.VENT_PACE_CTRL = true;
        HeartCode_B.GREEN_LED = true;
      } else {
        if ((HeartCode_B.in_Mode == 1) && HeartCode_B.b) {
          HeartCode_DW.VdeltaT = 0U;
          HeartCode_DW.is_c3_HeartCode = HeartCode_IN_VVI;
          HeartCode_DW.temporalCounter_i1 = 0U;
          HeartCode_B.RED_LED = true;
        }
      }
      break;

     case HeartCode_IN_VOO_Pacing:
      HeartCode_B.PACE_CHARGE_CTRL = false;
      HeartCode_B.PACE_GND_CTRL = true;
      HeartCode_B.ATR_PACE_CTRL = false;
      HeartCode_B.ATR_GND_CTRL = false;
      HeartCode_B.Z_ATR_CTRL = false;
      HeartCode_B.Z_VENT_CTRL = false;
      HeartCode_B.VENT_GND_CTRL = false;
      HeartCode_B.VENT_PACE_CTRL = true;
      HeartCode_B.GREEN_LED = true;
      if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.in_V_Pulse_Width) {
        HeartCode_B.qY = (uint32_T)HeartCode_DW.VdeltaT +
          HeartCode_B.in_V_Pulse_Width;
        if (HeartCode_B.qY > 65535U) {
          HeartCode_B.qY = 65535U;
        }

        HeartCode_DW.VdeltaT = (uint16_T)HeartCode_B.qY;
        switch (HeartCode_B.in_Mode) {
         case 0:
          HeartCode_DW.is_c3_HeartCode = HeartCode_IN_VOO_Charging;
          HeartCode_DW.temporalCounter_i1 = 0U;
          Heart_enter_atomic_VOO_Charging(&HeartCode_B.Divide1,
            &HeartCode_B.Divide2);
          break;

         case 1:
          HeartCode_DW.is_c3_HeartCode = HeartCode_IN_VVI;
          HeartCode_DW.temporalCounter_i1 = 0U;
          HeartCode_B.RED_LED = true;
          break;
        }
      }
      break;

     default:
      /* case IN_VVI: */
      HeartCode_B.RED_LED = true;
      if (HeartCode_DW.temporalCounter_i1 >= HeartCode_B.in_V_RefractoryPeriod_p)
      {
        HeartCode_B.qY = (uint32_T)HeartCode_DW.VdeltaT +
          HeartCode_B.in_V_RefractoryPeriod_p;
        if (HeartCode_B.qY > 65535U) {
          HeartCode_B.qY = 65535U;
        }

        HeartCode_DW.VdeltaT = (uint16_T)HeartCode_B.qY;
        HeartCode_DW.is_c3_HeartCode = HeartCode_IN_VOO_Charging;
        HeartCode_DW.temporalCounter_i1 = 0U;
        Heart_enter_atomic_VOO_Charging(&HeartCode_B.Divide1,
          &HeartCode_B.Divide2);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Modes' */

  /* MATLABSystem: '<S5>/PACE_CHARGE_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_e.MW_DIGITALIO_HANDLE,
                     HeartCode_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S5>/VENT_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(HeartCode_DW.obj_f.MW_PWM_HANDLE,
                      HeartCode_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S5>/Z_ATR_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_i.MW_DIGITALIO_HANDLE,
                     HeartCode_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S5>/PACING_REF_PWM' */
  MW_PWM_SetDutyCycle(HeartCode_DW.obj_p.MW_PWM_HANDLE,
                      HeartCode_B.PACING_REF_PWM);

  /* MATLABSystem: '<S5>/ATR_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(HeartCode_DW.obj_m.MW_PWM_HANDLE,
                      HeartCode_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S5>/Z_VENT_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_n.MW_DIGITALIO_HANDLE,
                     HeartCode_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S5>/ATR_PACE_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_h.MW_DIGITALIO_HANDLE,
                     HeartCode_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S5>/VENT_PACE_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_l.MW_DIGITALIO_HANDLE,
                     HeartCode_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S5>/PACE_GND_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_lf.MW_DIGITALIO_HANDLE,
                     HeartCode_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S5>/ATR_GND_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_k.MW_DIGITALIO_HANDLE,
                     HeartCode_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S5>/VENT_GND_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_l0.MW_DIGITALIO_HANDLE,
                     HeartCode_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S5>/FRONTEND_CTRL' */
  MW_digitalIO_write(HeartCode_DW.obj_b.MW_DIGITALIO_HANDLE,
                     HeartCode_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S5>/RED_LED' */
  MW_digitalIO_write(HeartCode_DW.obj_lh.MW_DIGITALIO_HANDLE,
                     HeartCode_B.RED_LED);

  /* MATLABSystem: '<S5>/GREEN_LED' */
  MW_digitalIO_write(HeartCode_DW.obj_o.MW_DIGITALIO_HANDLE,
                     HeartCode_B.GREEN_LED);

  /* MATLABSystem: '<S5>/BLUE_LED' */
  MW_digitalIO_write(HeartCode_DW.obj_m1.MW_DIGITALIO_HANDLE,
                     HeartCode_B.BLUE_LED);
}

/* Model initialize function */
void HeartCode_initialize(void)
{
  {
    freedomk64f_DigitalRead_Heart_T *obj;
    freedomk64f_DigitalWrite_Hear_T *obj_0;
    freedomk64f_PWMOutput_HeartCo_T *obj_1;

    /* Chart: '<Root>/COM_IN' */
    HeartCode_DW.is_c1_HeartCode = HeartCode_IN_INITIAL;
    HeartCode_B.in_Mode = 4U;
    HeartCode_B.in_LRL = 120U;
    HeartCode_B.in_URL = 130U;
    HeartCode_B.in_A_Amplitude_k = 4000U;
    HeartCode_B.in_A_Pulse_Width = 10U;
    HeartCode_B.in_V_Amplitude_a = 3500U;
    HeartCode_B.in_V_Pulse_Width = 10U;
    HeartCode_B.in_A_RefractoryPeriod_n = 100U;
    HeartCode_B.in_V_RefractoryPeriod_p = 100U;
    HeartCode_B.in_A_Sens_i = 0.75F;
    HeartCode_B.in_V_Sens_e = 1.0F;
    HeartCode_B.in_PVARP_j = 250U;
    HeartCode_B.in_fixedAVDelay_d = 150U;
    HeartCode_B.in_maxSensRate = 120U;
    HeartCode_B.in_ActivityThreshold = 3U;
    HeartCode_B.in_ReactionTime = 30U;
    HeartCode_B.in_ResponseFactor = 8U;
    HeartCode_B.in_RecoveryTime = 5U;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT' incorporates:
     *  SubSystem: '<Root>/COM_OUT'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    HeartCode_DW.obj_d.isInitialized = 0;
    HeartCode_DW.obj_d.matlabCodegenIsDeleted = false;
    HeartCode_DW.obj_d.SampleTime = HeartCode_P.SerialReceive_SampleTime;
    HeartCode_SystemCore_setup_p(&HeartCode_DW.obj_d);

    /* Start for MATLABSystem: '<S3>/ATR_CMP_DETECT (ON // OFF)' */
    HeartCode_DW.obj.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj.isInitialized = 0;
    HeartCode_DW.obj.SampleTime = -1.0;
    HeartCode_DW.obj.matlabCodegenIsDeleted = false;
    HeartCode_DW.obj.SampleTime = HeartCode_P.ATR_CMP_DETECTONOFF_SampleTime;
    obj = &HeartCode_DW.obj;
    HeartCode_DW.obj.isSetupComplete = false;
    HeartCode_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    HeartCode_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_CMP_DETECT (ON // OFF)' */
    HeartCode_DW.obj_g.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_g.isInitialized = 0;
    HeartCode_DW.obj_g.SampleTime = -1.0;
    HeartCode_DW.obj_g.matlabCodegenIsDeleted = false;
    HeartCode_DW.obj_g.SampleTime = HeartCode_P.VENT_CMP_DETECTONOFF_SampleTime;
    obj = &HeartCode_DW.obj_g;
    HeartCode_DW.obj_g.isSetupComplete = false;
    HeartCode_DW.obj_g.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    HeartCode_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PACE_CHARGE_CTRL' */
    HeartCode_DW.obj_e.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_e.isInitialized = 0;
    HeartCode_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_e;
    HeartCode_DW.obj_e.isSetupComplete = false;
    HeartCode_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    HeartCode_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/VENT_CMP_REF_PWM' */
    HeartCode_DW.obj_f.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_f.isInitialized = 0;
    HeartCode_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &HeartCode_DW.obj_f;
    HeartCode_DW.obj_f.isSetupComplete = false;
    HeartCode_DW.obj_f.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 100.0);
    MW_PWM_Start(HeartCode_DW.obj_f.MW_PWM_HANDLE);
    HeartCode_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Z_ATR_CTRL' */
    HeartCode_DW.obj_i.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_i.isInitialized = 0;
    HeartCode_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_i;
    HeartCode_DW.obj_i.isSetupComplete = false;
    HeartCode_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    HeartCode_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PACING_REF_PWM' */
    HeartCode_DW.obj_p.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_p.isInitialized = 0;
    HeartCode_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &HeartCode_DW.obj_p;
    HeartCode_DW.obj_p.isSetupComplete = false;
    HeartCode_DW.obj_p.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 100.0);
    MW_PWM_Start(HeartCode_DW.obj_p.MW_PWM_HANDLE);
    HeartCode_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/ATR_CMP_REF_PWM' */
    HeartCode_DW.obj_m.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_m.isInitialized = 0;
    HeartCode_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_1 = &HeartCode_DW.obj_m;
    HeartCode_DW.obj_m.isSetupComplete = false;
    HeartCode_DW.obj_m.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 100.0);
    MW_PWM_Start(HeartCode_DW.obj_m.MW_PWM_HANDLE);
    HeartCode_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Z_VENT_CTRL' */
    HeartCode_DW.obj_n.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_n.isInitialized = 0;
    HeartCode_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_n;
    HeartCode_DW.obj_n.isSetupComplete = false;
    HeartCode_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    HeartCode_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/ATR_PACE_CTRL' */
    HeartCode_DW.obj_h.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_h.isInitialized = 0;
    HeartCode_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_h;
    HeartCode_DW.obj_h.isSetupComplete = false;
    HeartCode_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    HeartCode_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/VENT_PACE_CTRL' */
    HeartCode_DW.obj_l.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_l.isInitialized = 0;
    HeartCode_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_l;
    HeartCode_DW.obj_l.isSetupComplete = false;
    HeartCode_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    HeartCode_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PACE_GND_CTRL' */
    HeartCode_DW.obj_lf.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_lf.isInitialized = 0;
    HeartCode_DW.obj_lf.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_lf;
    HeartCode_DW.obj_lf.isSetupComplete = false;
    HeartCode_DW.obj_lf.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    HeartCode_DW.obj_lf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/ATR_GND_CTRL' */
    HeartCode_DW.obj_k.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_k.isInitialized = 0;
    HeartCode_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_k;
    HeartCode_DW.obj_k.isSetupComplete = false;
    HeartCode_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    HeartCode_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/VENT_GND_CTRL' */
    HeartCode_DW.obj_l0.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_l0.isInitialized = 0;
    HeartCode_DW.obj_l0.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_l0;
    HeartCode_DW.obj_l0.isSetupComplete = false;
    HeartCode_DW.obj_l0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    HeartCode_DW.obj_l0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/FRONTEND_CTRL' */
    HeartCode_DW.obj_b.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_b.isInitialized = 0;
    HeartCode_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_b;
    HeartCode_DW.obj_b.isSetupComplete = false;
    HeartCode_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    HeartCode_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/RED_LED' */
    HeartCode_DW.obj_lh.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_lh.isInitialized = 0;
    HeartCode_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_lh;
    HeartCode_DW.obj_lh.isSetupComplete = false;
    HeartCode_DW.obj_lh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    HeartCode_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/GREEN_LED' */
    HeartCode_DW.obj_o.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_o.isInitialized = 0;
    HeartCode_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_o;
    HeartCode_DW.obj_o.isSetupComplete = false;
    HeartCode_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    HeartCode_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/BLUE_LED' */
    HeartCode_DW.obj_m1.matlabCodegenIsDeleted = true;
    HeartCode_DW.obj_m1.isInitialized = 0;
    HeartCode_DW.obj_m1.matlabCodegenIsDeleted = false;
    obj_0 = &HeartCode_DW.obj_m1;
    HeartCode_DW.obj_m1.isSetupComplete = false;
    HeartCode_DW.obj_m1.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    HeartCode_DW.obj_m1.isSetupComplete = true;
  }
}

/* Model terminate function */
void HeartCode_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  matlabCodegenHandle_matlabCod_p(&HeartCode_DW.obj_d);

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT' incorporates:
   *  SubSystem: '<Root>/COM_OUT'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT' */

  /* Terminate for MATLABSystem: '<S3>/ATR_CMP_DETECT (ON // OFF)' */
  matlabCodegenHandle_matlabCo_p0(&HeartCode_DW.obj);

  /* Terminate for MATLABSystem: '<S3>/VENT_CMP_DETECT (ON // OFF)' */
  matlabCodegenHandle_matlabCo_p0(&HeartCode_DW.obj_g);

  /* Terminate for MATLABSystem: '<S5>/PACE_CHARGE_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_e);

  /* Terminate for MATLABSystem: '<S5>/VENT_CMP_REF_PWM' */
  matlabCodegenHan_p02kby122gfybv(&HeartCode_DW.obj_f);

  /* Terminate for MATLABSystem: '<S5>/Z_ATR_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_i);

  /* Terminate for MATLABSystem: '<S5>/PACING_REF_PWM' */
  matlabCodegenHan_p02kby122gfybv(&HeartCode_DW.obj_p);

  /* Terminate for MATLABSystem: '<S5>/ATR_CMP_REF_PWM' */
  matlabCodegenHan_p02kby122gfybv(&HeartCode_DW.obj_m);

  /* Terminate for MATLABSystem: '<S5>/Z_VENT_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_n);

  /* Terminate for MATLABSystem: '<S5>/ATR_PACE_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_h);

  /* Terminate for MATLABSystem: '<S5>/VENT_PACE_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_l);

  /* Terminate for MATLABSystem: '<S5>/PACE_GND_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_lf);

  /* Terminate for MATLABSystem: '<S5>/ATR_GND_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_k);

  /* Terminate for MATLABSystem: '<S5>/VENT_GND_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_l0);

  /* Terminate for MATLABSystem: '<S5>/FRONTEND_CTRL' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_b);

  /* Terminate for MATLABSystem: '<S5>/RED_LED' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_lh);

  /* Terminate for MATLABSystem: '<S5>/GREEN_LED' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_o);

  /* Terminate for MATLABSystem: '<S5>/BLUE_LED' */
  matlabCodegenHandle_matlab_p02k(&HeartCode_DW.obj_m1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
