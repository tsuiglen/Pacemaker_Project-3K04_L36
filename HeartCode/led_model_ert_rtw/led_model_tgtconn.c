/*
 * led_model_tgtconn.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "led_model".
 *
 * Model version              : 1.33
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Sun Nov  1 16:13:22 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#define EXTERN_C
#include <stdio.h>
#include "RTIOStreamTgtAppSvc/RTIOStreamTgtAppSvcCIntrf.h"

extern void initializeCommService( );
extern void terminateCommService();
EXTERN_C void TgtConnBackgroundTask()
{
}

EXTERN_C const char *TgtConnInit(int_T argc, char_T *argv[])
{
  const char *result = NULL;           /* assume success */
  initializeCommService( );
  return(result);
}

EXTERN_C void TgtConnTerm()
{
  terminateCommService();
}

EXTERN_C void TgtConnPreStep(int_T tid)
{
}

EXTERN_C void TgtConnPostStep(int_T tid)
{
}

/* EOF: led_model_tgtconn.c */
