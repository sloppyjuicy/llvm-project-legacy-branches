/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.36
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */


#ifdef __cplusplus
template<typename T> class SwigValueWrapper {
    T *tt;
public:
    SwigValueWrapper() : tt(0) { }
    SwigValueWrapper(const SwigValueWrapper<T>& rhs) : tt(new T(*rhs.tt)) { }
    SwigValueWrapper(const T& t) : tt(new T(t)) { }
    ~SwigValueWrapper() { delete tt; } 
    SwigValueWrapper& operator=(const T& t) { delete tt; tt = new T(t); return *this; }
    operator T&() const { return *tt; }
    T *operator&() { return tt; }
private:
    SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#if defined(_WIN32) || defined(__CYGWIN32__)
#  define DllExport   __declspec( dllexport )
#  define SWIGSTDCALL __stdcall
#else
#  define DllExport  
#  define SWIGSTDCALL
#endif 


#ifdef __cplusplus
#  include <new>
#endif




/* Support for throwing Ada exceptions from C/C++ */

typedef enum 
{
  SWIG_AdaException,
  SWIG_AdaOutOfMemoryException,
  SWIG_AdaIndexOutOfRangeException,
  SWIG_AdaDivideByZeroException,
  SWIG_AdaArgumentOutOfRangeException,
  SWIG_AdaNullReferenceException
} SWIG_AdaExceptionCodes;


typedef void (SWIGSTDCALL* SWIG_AdaExceptionCallback_t)(const char *);


typedef struct 
{
  SWIG_AdaExceptionCodes code;
  SWIG_AdaExceptionCallback_t callback;
} 
  SWIG_AdaExceptions_t;


static 
SWIG_AdaExceptions_t 
SWIG_ada_exceptions[] = 
{
  { SWIG_AdaException, NULL },
  { SWIG_AdaOutOfMemoryException, NULL },
  { SWIG_AdaIndexOutOfRangeException, NULL },
  { SWIG_AdaDivideByZeroException, NULL },
  { SWIG_AdaArgumentOutOfRangeException, NULL },
  { SWIG_AdaNullReferenceException, NULL } 
};


static 
void 
SWIG_AdaThrowException (SWIG_AdaExceptionCodes code, const char *msg) 
{
  SWIG_AdaExceptionCallback_t callback = SWIG_ada_exceptions[SWIG_AdaException].callback;
  if (code >=0 && (size_t)code < sizeof(SWIG_ada_exceptions)/sizeof(SWIG_AdaExceptions_t)) {
    callback = SWIG_ada_exceptions[code].callback;
  }
  callback(msg);
}



#ifdef __cplusplus
extern "C" 
#endif

DllExport void SWIGSTDCALL SWIGRegisterExceptionCallbacks_LLVM_execution_Engine (SWIG_AdaExceptionCallback_t systemException,
                                                                   SWIG_AdaExceptionCallback_t outOfMemory, 
                                                                   SWIG_AdaExceptionCallback_t indexOutOfRange, 
                                                                   SWIG_AdaExceptionCallback_t divideByZero, 
                                                                   SWIG_AdaExceptionCallback_t argumentOutOfRange,
                                                                   SWIG_AdaExceptionCallback_t nullReference) 
{
  SWIG_ada_exceptions [SWIG_AdaException].callback                   = systemException;
  SWIG_ada_exceptions [SWIG_AdaOutOfMemoryException].callback        = outOfMemory;
  SWIG_ada_exceptions [SWIG_AdaIndexOutOfRangeException].callback    = indexOutOfRange;
  SWIG_ada_exceptions [SWIG_AdaDivideByZeroException].callback       = divideByZero;
  SWIG_ada_exceptions [SWIG_AdaArgumentOutOfRangeException].callback = argumentOutOfRange;
  SWIG_ada_exceptions [SWIG_AdaNullReferenceException].callback      = nullReference;
}


/* Callback for returning strings to Ada without leaking memory */

typedef char * (SWIGSTDCALL* SWIG_AdaStringHelperCallback)(const char *);
static SWIG_AdaStringHelperCallback SWIG_ada_string_callback = NULL;



/* probably obsolete ...
#ifdef __cplusplus
extern "C" 
#endif
DllExport void SWIGSTDCALL SWIGRegisterStringCallback_LLVM_execution_Engine(SWIG_AdaStringHelperCallback callback) {
  SWIG_ada_string_callback = callback;
}
*/



/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_AdaThrowException(SWIG_AdaArgumentOutOfRangeException, msg); return nullreturn; } else


#define protected public
#define private   public

#include "llvm-c/ExecutionEngine.h"



//  struct LLVMCtxt;


#undef protected
#undef private
#ifdef __cplusplus 
extern "C" {
#endif
DllExport void SWIGSTDCALL Ada_LLVMLinkInJIT (
  )
{
  LLVMLinkInJIT();
  
  
}



DllExport void SWIGSTDCALL Ada_LLVMLinkInInterpreter (
  )
{
  LLVMLinkInInterpreter();
  
  
}



DllExport void * SWIGSTDCALL Ada_LLVMCreateGenericValueOfInt (
  void * jarg1
  ,
  
  unsigned long long jarg2
  ,
  
  int jarg3
  )
{
  void * jresult ;
  LLVMTypeRef arg1 = (LLVMTypeRef) 0 ;
  unsigned long long arg2 ;
  int arg3 ;
  LLVMGenericValueRef result;
  
  arg1 = (LLVMTypeRef)jarg1; 
  
  
  arg2 = (unsigned long long) jarg2; 
  
  
  
  arg3 = (int) jarg3; 
  
  
  result = (LLVMGenericValueRef)LLVMCreateGenericValueOfInt(arg1,arg2,arg3);
  jresult = (void *) result;      
  
  
  
  return jresult;
  
}



DllExport void * SWIGSTDCALL Ada_LLVMCreateGenericValueOfPointer (
  void* jarg1
  )
{
  void * jresult ;
  void *arg1 = (void *) 0 ;
  LLVMGenericValueRef result;
  
  arg1 = (void *)jarg1; 
  
  result = (LLVMGenericValueRef)LLVMCreateGenericValueOfPointer(arg1);
  jresult = (void *) result;      
  
  
  
  return jresult;
  
}



DllExport void * SWIGSTDCALL Ada_LLVMCreateGenericValueOfFloat (
  void * jarg1
  ,
  
  double jarg2
  )
{
  void * jresult ;
  LLVMTypeRef arg1 = (LLVMTypeRef) 0 ;
  double arg2 ;
  LLVMGenericValueRef result;
  
  arg1 = (LLVMTypeRef)jarg1; 
  
  
  arg2 = (double) jarg2; 
  
  
  result = (LLVMGenericValueRef)LLVMCreateGenericValueOfFloat(arg1,arg2);
  jresult = (void *) result;      
  
  
  
  return jresult;
  
}



DllExport unsigned int SWIGSTDCALL Ada_LLVMGenericValueIntWidth (
  void * jarg1
  )
{
  unsigned int jresult ;
  LLVMGenericValueRef arg1 = (LLVMGenericValueRef) 0 ;
  unsigned int result;
  
  arg1 = (LLVMGenericValueRef)jarg1; 
  
  result = (unsigned int)LLVMGenericValueIntWidth(arg1);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport unsigned long long SWIGSTDCALL Ada_LLVMGenericValueToInt (
  void * jarg1
  ,
  
  int jarg2
  )
{
  unsigned long long jresult ;
  LLVMGenericValueRef arg1 = (LLVMGenericValueRef) 0 ;
  int arg2 ;
  unsigned long long result;
  
  arg1 = (LLVMGenericValueRef)jarg1; 
  
  
  arg2 = (int) jarg2; 
  
  
  result = (unsigned long long)LLVMGenericValueToInt(arg1,arg2);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport void* SWIGSTDCALL Ada_LLVMGenericValueToPointer (
  void * jarg1
  )
{
  void* jresult ;
  LLVMGenericValueRef arg1 = (LLVMGenericValueRef) 0 ;
  void *result = 0 ;
  
  arg1 = (LLVMGenericValueRef)jarg1; 
  
  result = (void *)LLVMGenericValueToPointer(arg1);
  jresult = (void *) result;      
  
  
  
  return jresult;
  
}



DllExport double SWIGSTDCALL Ada_LLVMGenericValueToFloat (
  void * jarg1
  ,
  
  void * jarg2
  )
{
  double jresult ;
  LLVMTypeRef arg1 = (LLVMTypeRef) 0 ;
  LLVMGenericValueRef arg2 = (LLVMGenericValueRef) 0 ;
  double result;
  
  arg1 = (LLVMTypeRef)jarg1; 
  
  arg2 = (LLVMGenericValueRef)jarg2; 
  
  result = (double)LLVMGenericValueToFloat(arg1,arg2);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport void SWIGSTDCALL Ada_LLVMDisposeGenericValue (
  void * jarg1
  )
{
  LLVMGenericValueRef arg1 = (LLVMGenericValueRef) 0 ;
  
  arg1 = (LLVMGenericValueRef)jarg1; 
  
  LLVMDisposeGenericValue(arg1);
  
  
}



DllExport int SWIGSTDCALL Ada_LLVMCreateExecutionEngine (
  void * jarg1
  ,
  
  void * jarg2
  ,
  
  void * jarg3
  )
{
  int jresult ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleProviderRef arg2 = (LLVMModuleProviderRef) 0 ;
  char **arg3 = (char **) 0 ;
  int result;
  
  arg1 = (LLVMExecutionEngineRef *)jarg1; 
  
  arg2 = (LLVMModuleProviderRef)jarg2; 
  
  arg3 = (char **)jarg3; 
  
  result = (int)LLVMCreateExecutionEngine(arg1,arg2,arg3);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport int SWIGSTDCALL Ada_LLVMCreateInterpreter (
  void * jarg1
  ,
  
  void * jarg2
  ,
  
  void * jarg3
  )
{
  int jresult ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleProviderRef arg2 = (LLVMModuleProviderRef) 0 ;
  char **arg3 = (char **) 0 ;
  int result;
  
  arg1 = (LLVMExecutionEngineRef *)jarg1; 
  
  arg2 = (LLVMModuleProviderRef)jarg2; 
  
  arg3 = (char **)jarg3; 
  
  result = (int)LLVMCreateInterpreter(arg1,arg2,arg3);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport int SWIGSTDCALL Ada_LLVMCreateJITCompiler (
  void * jarg1
  ,
  
  void * jarg2
  ,
  
  unsigned int jarg3
  ,
  
  void * jarg4
  )
{
  int jresult ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleProviderRef arg2 = (LLVMModuleProviderRef) 0 ;
  unsigned int arg3 ;
  char **arg4 = (char **) 0 ;
  int result;
  
  arg1 = (LLVMExecutionEngineRef *)jarg1; 
  
  arg2 = (LLVMModuleProviderRef)jarg2; 
  
  
  arg3 = (unsigned int) jarg3; 
  
  
  arg4 = (char **)jarg4; 
  
  result = (int)LLVMCreateJITCompiler(arg1,arg2,arg3,arg4);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport void SWIGSTDCALL Ada_LLVMDisposeExecutionEngine (
  void * jarg1
  )
{
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  LLVMDisposeExecutionEngine(arg1);
  
  
}



DllExport void SWIGSTDCALL Ada_LLVMRunStaticConstructors (
  void * jarg1
  )
{
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  LLVMRunStaticConstructors(arg1);
  
  
}



DllExport void SWIGSTDCALL Ada_LLVMRunStaticDestructors (
  void * jarg1
  )
{
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  LLVMRunStaticDestructors(arg1);
  
  
}



DllExport int SWIGSTDCALL Ada_LLVMRunFunctionAsMain (
  void * jarg1
  ,
  
  void * jarg2
  ,
  
  unsigned int jarg3
  ,
  
  void * jarg4
  ,
  
  void * jarg5
  )
{
  int jresult ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 = (LLVMValueRef) 0 ;
  unsigned int arg3 ;
  char **arg4 = (char **) 0 ;
  char **arg5 = (char **) 0 ;
  int result;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  arg2 = (LLVMValueRef)jarg2; 
  
  
  arg3 = (unsigned int) jarg3; 
  
  
  arg4 = (char **)jarg4; 
  
  arg5 = (char **)jarg5; 
  
  result = (int)LLVMRunFunctionAsMain(arg1,arg2,arg3,(char const *const *)arg4,(char const *const *)arg5);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport void * SWIGSTDCALL Ada_LLVMRunFunction (
  void * jarg1
  ,
  
  void * jarg2
  ,
  
  unsigned int jarg3
  ,
  
  void * jarg4
  )
{
  void * jresult ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 = (LLVMValueRef) 0 ;
  unsigned int arg3 ;
  LLVMGenericValueRef *arg4 = (LLVMGenericValueRef *) 0 ;
  LLVMGenericValueRef result;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  arg2 = (LLVMValueRef)jarg2; 
  
  
  arg3 = (unsigned int) jarg3; 
  
  
  arg4 = (LLVMGenericValueRef *)jarg4; 
  
  result = (LLVMGenericValueRef)LLVMRunFunction(arg1,arg2,arg3,arg4);
  jresult = (void *) result;      
  
  
  
  return jresult;
  
}



DllExport void SWIGSTDCALL Ada_LLVMFreeMachineCodeForFunction (
  void * jarg1
  ,
  
  void * jarg2
  )
{
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 = (LLVMValueRef) 0 ;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  arg2 = (LLVMValueRef)jarg2; 
  
  LLVMFreeMachineCodeForFunction(arg1,arg2);
  
  
}



DllExport void SWIGSTDCALL Ada_LLVMAddModuleProvider (
  void * jarg1
  ,
  
  void * jarg2
  )
{
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMModuleProviderRef arg2 = (LLVMModuleProviderRef) 0 ;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  arg2 = (LLVMModuleProviderRef)jarg2; 
  
  LLVMAddModuleProvider(arg1,arg2);
  
  
}



DllExport int SWIGSTDCALL Ada_LLVMRemoveModuleProvider (
  void * jarg1
  ,
  
  void * jarg2
  ,
  
  void * jarg3
  ,
  
  void * jarg4
  )
{
  int jresult ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMModuleProviderRef arg2 = (LLVMModuleProviderRef) 0 ;
  LLVMModuleRef *arg3 = (LLVMModuleRef *) 0 ;
  char **arg4 = (char **) 0 ;
  int result;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  arg2 = (LLVMModuleProviderRef)jarg2; 
  
  arg3 = (LLVMModuleRef *)jarg3; 
  
  arg4 = (char **)jarg4; 
  
  result = (int)LLVMRemoveModuleProvider(arg1,arg2,arg3,arg4);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport int SWIGSTDCALL Ada_LLVMFindFunction (
  void * jarg1
  ,
  
  char * jarg2
  ,
  
  void * jarg3
  )
{
  int jresult ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  char *arg2 = (char *) 0 ;
  LLVMValueRef *arg3 = (LLVMValueRef *) 0 ;
  int result;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  arg2 = jarg2; 
  
  arg3 = (LLVMValueRef *)jarg3; 
  
  result = (int)LLVMFindFunction(arg1,(char const *)arg2,arg3);
  jresult = result; 
  
  
  
  return jresult;
  
}



DllExport LLVMTargetDataRef SWIGSTDCALL Ada_LLVMGetExecutionEngineTargetData (
  void * jarg1
  )
{
  LLVMTargetDataRef jresult ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMTargetDataRef result;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  result = LLVMGetExecutionEngineTargetData(arg1);
  
  jresult = result; 
  //jresult = new LLVMTargetDataRef ((LLVMTargetDataRef &) result); 
  
  
  
  
  return jresult;
  
}



DllExport void SWIGSTDCALL Ada_LLVMAddGlobalMapping (
  void * jarg1
  ,
  
  void * jarg2
  ,
  
  void* jarg3
  )
{
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 = (LLVMValueRef) 0 ;
  void *arg3 = (void *) 0 ;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  arg2 = (LLVMValueRef)jarg2; 
  
  arg3 = (void *)jarg3; 
  
  LLVMAddGlobalMapping(arg1,arg2,arg3);
  
  
}



DllExport void* SWIGSTDCALL Ada_LLVMGetPointerToGlobal (
  void * jarg1
  ,
  
  void * jarg2
  )
{
  void* jresult ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 = (LLVMValueRef) 0 ;
  void *result = 0 ;
  
  arg1 = (LLVMExecutionEngineRef)jarg1; 
  
  arg2 = (LLVMValueRef)jarg2; 
  
  result = (void *)LLVMGetPointerToGlobal(arg1,arg2);
  jresult = (void *) result;      
  
  
  
  return jresult;
  
}



#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

