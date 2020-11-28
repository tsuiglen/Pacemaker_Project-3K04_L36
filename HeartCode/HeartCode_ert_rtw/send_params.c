/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params.c
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

#include "send_params.h"

/* Include model header file for global data */
#include "HeartCode.h"
#include "HeartCode_private.h"

/* Forward declaration for local functions */
static void HeartCode_SystemCore_setup(freedomk64f_SCIWrite_HeartCod_T *obj);
static void HeartCode_SystemCore_release(const freedomk64f_SCIWrite_HeartCod_T
  *obj);
static void HeartCode_SystemCore_delete(const freedomk64f_SCIWrite_HeartCod_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_SCIWrite_HeartCod_T *obj);
static void HeartCode_SystemCore_setup(freedomk64f_SCIWrite_HeartCod_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

static void HeartCode_SystemCore_release(const freedomk64f_SCIWrite_HeartCod_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void HeartCode_SystemCore_delete(const freedomk64f_SCIWrite_HeartCod_T
  *obj)
{
  HeartCode_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_SCIWrite_HeartCod_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    HeartCode_SystemCore_delete(obj);
  }
}

/* System initialize for Simulink Function: '<Root>/COM_OUT' */
void send_params_Init(void)
{
  /* Start for MATLABSystem: '<S2>/Serial Transmit' */
  HeartCode_DW.obj_c.isInitialized = 0;
  HeartCode_DW.obj_c.matlabCodegenIsDeleted = false;
  HeartCode_SystemCore_setup(&HeartCode_DW.obj_c);
}

/* Output and update for Simulink Function: '<Root>/COM_OUT' */
void send_params(void)
{
  uint8_T status;
  uint8_T TxDataLocChar[31];
  uint8_T rtb_TmpSignalConversionAtSerial[31];

  /* SignalConversion generated from: '<S2>/A_Amplitude (mV)' */
  HeartCode_B.in_A_Amplitude = HeartCode_B.in_A_Amplitude_k;

  /* SignalConversion generated from: '<S2>/V_Amplitude (mV)' */
  HeartCode_B.in_V_Amplitude = HeartCode_B.in_V_Amplitude_a;

  /* SignalConversion generated from: '<S2>/A_RefractoryPeriod (ms)' */
  HeartCode_B.in_A_RefractoryPeriod = HeartCode_B.in_A_RefractoryPeriod_n;

  /* SignalConversion generated from: '<S2>/V_RefractoryPeriod (ms)' */
  HeartCode_B.in_V_RefractoryPeriod = HeartCode_B.in_V_RefractoryPeriod_p;

  /* SignalConversion generated from: '<S2>/A_Sens (mV)' */
  HeartCode_B.in_A_Sens = HeartCode_B.in_A_Sens_i;

  /* SignalConversion generated from: '<S2>/V_Sens (mV)' */
  HeartCode_B.in_V_Sens = HeartCode_B.in_V_Sens_e;

  /* SignalConversion generated from: '<S2>/PVARP (ms)' */
  HeartCode_B.in_PVARP = HeartCode_B.in_PVARP_j;

  /* SignalConversion generated from: '<S2>/Fixed_AV_Delay (ms)' */
  HeartCode_B.in_fixedAVDelay = HeartCode_B.in_fixedAVDelay_d;

  /* S-Function (any2byte): '<S2>/Byte Pack' */

  /* Pack: <S2>/Byte Pack */
  (void) memcpy(&HeartCode_B.BytePack[0], &HeartCode_B.in_A_Amplitude,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack1' */

  /* Pack: <S2>/Byte Pack1 */
  (void) memcpy(&HeartCode_B.BytePack1[0], &HeartCode_B.in_V_Amplitude,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack2' */

  /* Pack: <S2>/Byte Pack2 */
  (void) memcpy(&HeartCode_B.BytePack2[0], &HeartCode_B.in_A_RefractoryPeriod,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack3' */

  /* Pack: <S2>/Byte Pack3 */
  (void) memcpy(&HeartCode_B.BytePack3[0], &HeartCode_B.in_V_RefractoryPeriod,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack4' */

  /* Pack: <S2>/Byte Pack4 */
  (void) memcpy(&HeartCode_B.BytePack4[0], &HeartCode_B.in_A_Sens,
                4);

  /* S-Function (any2byte): '<S2>/Byte Pack5' */

  /* Pack: <S2>/Byte Pack5 */
  (void) memcpy(&HeartCode_B.BytePack5[0], &HeartCode_B.in_V_Sens,
                4);

  /* S-Function (any2byte): '<S2>/Byte Pack6' */

  /* Pack: <S2>/Byte Pack6 */
  (void) memcpy(&HeartCode_B.BytePack6[0], &HeartCode_B.in_PVARP,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack7' */

  /* Pack: <S2>/Byte Pack7 */
  (void) memcpy(&HeartCode_B.BytePack7[0], &HeartCode_B.in_fixedAVDelay,
                2);

  /* SignalConversion generated from: '<S2>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<S2>/A_Pulse_Width (ms)'
   *  SignalConversion generated from: '<S2>/Activity_Threshold'
   *  SignalConversion generated from: '<S2>/LRL (ppm)'
   *  SignalConversion generated from: '<S2>/Maximum_Sensor_Rate (ppm)'
   *  SignalConversion generated from: '<S2>/Mode'
   *  SignalConversion generated from: '<S2>/Rate_Smoothing (%)'
   *  SignalConversion generated from: '<S2>/Reaction_Time (sec)'
   *  SignalConversion generated from: '<S2>/Recovery_Time (min)'
   *  SignalConversion generated from: '<S2>/Response_Factor'
   *  SignalConversion generated from: '<S2>/URL (ppm)'
   *  SignalConversion generated from: '<S2>/V_Pulse_Width (ms)'
   */
  rtb_TmpSignalConversionAtSerial[0] = HeartCode_B.in_Mode;
  rtb_TmpSignalConversionAtSerial[1] = HeartCode_B.in_LRL;
  rtb_TmpSignalConversionAtSerial[2] = HeartCode_B.in_URL;
  rtb_TmpSignalConversionAtSerial[5] = HeartCode_B.in_A_Pulse_Width;
  rtb_TmpSignalConversionAtSerial[8] = HeartCode_B.in_V_Pulse_Width;
  rtb_TmpSignalConversionAtSerial[3] = HeartCode_B.BytePack[0];
  rtb_TmpSignalConversionAtSerial[6] = HeartCode_B.BytePack1[0];
  rtb_TmpSignalConversionAtSerial[9] = HeartCode_B.BytePack2[0];
  rtb_TmpSignalConversionAtSerial[11] = HeartCode_B.BytePack3[0];
  rtb_TmpSignalConversionAtSerial[4] = HeartCode_B.BytePack[1];
  rtb_TmpSignalConversionAtSerial[7] = HeartCode_B.BytePack1[1];
  rtb_TmpSignalConversionAtSerial[10] = HeartCode_B.BytePack2[1];
  rtb_TmpSignalConversionAtSerial[12] = HeartCode_B.BytePack3[1];
  rtb_TmpSignalConversionAtSerial[13] = HeartCode_B.BytePack4[0];
  rtb_TmpSignalConversionAtSerial[17] = HeartCode_B.BytePack5[0];
  rtb_TmpSignalConversionAtSerial[14] = HeartCode_B.BytePack4[1];
  rtb_TmpSignalConversionAtSerial[18] = HeartCode_B.BytePack5[1];
  rtb_TmpSignalConversionAtSerial[15] = HeartCode_B.BytePack4[2];
  rtb_TmpSignalConversionAtSerial[19] = HeartCode_B.BytePack5[2];
  rtb_TmpSignalConversionAtSerial[16] = HeartCode_B.BytePack4[3];
  rtb_TmpSignalConversionAtSerial[20] = HeartCode_B.BytePack5[3];
  rtb_TmpSignalConversionAtSerial[21] = HeartCode_B.in_Rate_Smoothing;
  rtb_TmpSignalConversionAtSerial[22] = HeartCode_B.BytePack6[0];
  rtb_TmpSignalConversionAtSerial[24] = HeartCode_B.BytePack7[0];
  rtb_TmpSignalConversionAtSerial[23] = HeartCode_B.BytePack6[1];
  rtb_TmpSignalConversionAtSerial[25] = HeartCode_B.BytePack7[1];
  rtb_TmpSignalConversionAtSerial[26] = HeartCode_B.in_maxSensRate;
  rtb_TmpSignalConversionAtSerial[27] = HeartCode_B.in_ActivityThreshold;
  rtb_TmpSignalConversionAtSerial[28] = HeartCode_B.in_ReactionTime;
  rtb_TmpSignalConversionAtSerial[29] = HeartCode_B.in_ResponseFactor;
  rtb_TmpSignalConversionAtSerial[30] = HeartCode_B.in_RecoveryTime;

  /* MATLABSystem: '<S2>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
           (uint32_T)((size_t)31 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(HeartCode_DW.obj_c.MW_SCIHANDLE, TxDataLocChar, 31U);
  }

  /* End of MATLABSystem: '<S2>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/COM_OUT' */
void send_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S2>/Serial Transmit' */
  matlabCodegenHandle_matlabCodeg(&HeartCode_DW.obj_c);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
