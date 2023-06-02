//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Fri Jun  2 20:45:35 2023
// Arguments:
// "-B""macro_default""-W""cpplib:envo_spline,all,version=1.0""-T""link:lib""-d"
// "C:\Users\X_xx\Desktop\LSTM(1)\LSTM\lstm���������ڶ���
// ��գ�\0216lstm������\0216lstm������\envo_spline\f
// or_testing""-v""C:\Users\X_xx\Desktop\LSTM(1)\LSTM\lstm��������
// ���ڶ��棨�գ�\0216lstm������\0216lstm������
// �\envo_spline.m"
//

#ifndef envo_spline_h
#define envo_spline_h 1

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
#ifndef LIB_envo_spline_C_API 
#define LIB_envo_spline_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_envo_spline_C_API 
bool MW_CALL_CONV envo_splineInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_envo_spline_C_API 
bool MW_CALL_CONV envo_splineInitialize(void);

extern LIB_envo_spline_C_API 
void MW_CALL_CONV envo_splineTerminate(void);

extern LIB_envo_spline_C_API 
void MW_CALL_CONV envo_splinePrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_envo_spline_C_API 
bool MW_CALL_CONV mlxEnvo_spline(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_envo_spline
#define PUBLIC_envo_spline_CPP_API __declspec(dllexport)
#else
#define PUBLIC_envo_spline_CPP_API __declspec(dllimport)
#endif

#define LIB_envo_spline_CPP_API PUBLIC_envo_spline_CPP_API

#else

#if !defined(LIB_envo_spline_CPP_API)
#if defined(LIB_envo_spline_C_API)
#define LIB_envo_spline_CPP_API LIB_envo_spline_C_API
#else
#define LIB_envo_spline_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_envo_spline_CPP_API void MW_CALL_CONV envo_spline(int nargout, mwArray& ICP, mwArray& IMWP, mwArray& MWD, const mwArray& datapath, const mwArray& window, const mwArray& degree, const mwArray& fig_savepath, const mwArray& cur_time);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
