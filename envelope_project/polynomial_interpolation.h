//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Fri Jun  2 20:25:55 2023
// Arguments:
// "-B""macro_default""-W""cpplib:polynomial_interpolation,all,version=1.0""-T""
// link:lib""-d""C:\Users\X_xx\Desktop\LSTM(1)\LSTM\lstm��������
// �ڶ��棨�գ�\0216lstm������\0216lstm������\
// polynomial_interpolation\for_testing""-v""C:\Users\X_xx\Desktop\LSTM(1)\LSTM\
// lstm���������ڶ��棨�գ�\0216lstm������
// \0216lstm������\polynomial_interpolation.m"
//

#ifndef polynomial_interpolation_h
#define polynomial_interpolation_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_polynomial_interpolation_C_API 
#define LIB_polynomial_interpolation_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_polynomial_interpolation_C_API 
bool MW_CALL_CONV polynomial_interpolationInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_polynomial_interpolation_C_API 
bool MW_CALL_CONV polynomial_interpolationInitialize(void);

extern LIB_polynomial_interpolation_C_API 
void MW_CALL_CONV polynomial_interpolationTerminate(void);

extern LIB_polynomial_interpolation_C_API 
void MW_CALL_CONV polynomial_interpolationPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_polynomial_interpolation_C_API 
bool MW_CALL_CONV mlxPolynomial_interpolation(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_polynomial_interpolation
#define PUBLIC_polynomial_interpolation_CPP_API __declspec(dllexport)
#else
#define PUBLIC_polynomial_interpolation_CPP_API __declspec(dllimport)
#endif

#define LIB_polynomial_interpolation_CPP_API PUBLIC_polynomial_interpolation_CPP_API

#else

#if !defined(LIB_polynomial_interpolation_CPP_API)
#if defined(LIB_polynomial_interpolation_C_API)
#define LIB_polynomial_interpolation_CPP_API LIB_polynomial_interpolation_C_API
#else
#define LIB_polynomial_interpolation_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_polynomial_interpolation_CPP_API void MW_CALL_CONV polynomial_interpolation(int nargout, mwArray& ICP, mwArray& IMWP, mwArray& MWD, const mwArray& datapath, const mwArray& window, const mwArray& degree, const mwArray& fig_savepath, const mwArray& cur_time);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
