/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HeartCode_types.h
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

#ifndef RTW_HEADER_HeartCode_types_h_
#define RTW_HEADER_HeartCode_types_h_
#include "rtwtypes.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S2>/Serial Transmit' */
#include "MW_SVD.h"
#ifndef struct_tag_bvK2L41g8z1P0jzpdjsJhE
#define struct_tag_bvK2L41g8z1P0jzpdjsJhE

struct tag_bvK2L41g8z1P0jzpdjsJhE
{
  int32_T __dummy;
};

#endif                                 /*struct_tag_bvK2L41g8z1P0jzpdjsJhE*/

#ifndef typedef_b_freedomk64f_Hardware_HeartC_T
#define typedef_b_freedomk64f_Hardware_HeartC_T

typedef struct tag_bvK2L41g8z1P0jzpdjsJhE b_freedomk64f_Hardware_HeartC_T;

#endif                               /*typedef_b_freedomk64f_Hardware_HeartC_T*/

#ifndef struct_tag_WltE1qT51p3S2KRQQd2Zd
#define struct_tag_WltE1qT51p3S2KRQQd2Zd

struct tag_WltE1qT51p3S2KRQQd2Zd
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_HeartC_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /*struct_tag_WltE1qT51p3S2KRQQd2Zd*/

#ifndef typedef_freedomk64f_SCIWrite_HeartCod_T
#define typedef_freedomk64f_SCIWrite_HeartCod_T

typedef struct tag_WltE1qT51p3S2KRQQd2Zd freedomk64f_SCIWrite_HeartCod_T;

#endif                               /*typedef_freedomk64f_SCIWrite_HeartCod_T*/

#ifndef struct_tag_79weVYaslRFZRGk3pNTXC
#define struct_tag_79weVYaslRFZRGk3pNTXC

struct tag_79weVYaslRFZRGk3pNTXC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_HeartC_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_79weVYaslRFZRGk3pNTXC*/

#ifndef typedef_freedomk64f_SCIRead_HeartCode_T
#define typedef_freedomk64f_SCIRead_HeartCode_T

typedef struct tag_79weVYaslRFZRGk3pNTXC freedomk64f_SCIRead_HeartCode_T;

#endif                               /*typedef_freedomk64f_SCIRead_HeartCode_T*/

#ifndef struct_tag_gY1zYXXyNHJpvdqiHJr34G
#define struct_tag_gY1zYXXyNHJpvdqiHJr34G

struct tag_gY1zYXXyNHJpvdqiHJr34G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_HeartC_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_gY1zYXXyNHJpvdqiHJr34G*/

#ifndef typedef_freedomk64f_DigitalRead_Heart_T
#define typedef_freedomk64f_DigitalRead_Heart_T

typedef struct tag_gY1zYXXyNHJpvdqiHJr34G freedomk64f_DigitalRead_Heart_T;

#endif                               /*typedef_freedomk64f_DigitalRead_Heart_T*/

#ifndef struct_tag_62aCTDKRGQaAsT8vVipI2D
#define struct_tag_62aCTDKRGQaAsT8vVipI2D

struct tag_62aCTDKRGQaAsT8vVipI2D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_HeartC_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /*struct_tag_62aCTDKRGQaAsT8vVipI2D*/

#ifndef typedef_freedomk64f_DigitalWrite_Hear_T
#define typedef_freedomk64f_DigitalWrite_Hear_T

typedef struct tag_62aCTDKRGQaAsT8vVipI2D freedomk64f_DigitalWrite_Hear_T;

#endif                               /*typedef_freedomk64f_DigitalWrite_Hear_T*/

#ifndef struct_tag_asB9FwAteE1VObOuq1LwyE
#define struct_tag_asB9FwAteE1VObOuq1LwyE

struct tag_asB9FwAteE1VObOuq1LwyE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_HeartC_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /*struct_tag_asB9FwAteE1VObOuq1LwyE*/

#ifndef typedef_freedomk64f_PWMOutput_HeartCo_T
#define typedef_freedomk64f_PWMOutput_HeartCo_T

typedef struct tag_asB9FwAteE1VObOuq1LwyE freedomk64f_PWMOutput_HeartCo_T;

#endif                               /*typedef_freedomk64f_PWMOutput_HeartCo_T*/

/* Parameters (default storage) */
typedef struct P_HeartCode_T_ P_HeartCode_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_HeartCode_T RT_MODEL_HeartCode_T;

#endif                                 /* RTW_HEADER_HeartCode_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
