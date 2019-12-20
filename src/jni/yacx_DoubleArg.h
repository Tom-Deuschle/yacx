/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class yacx_DoubleArg */

#ifndef _Included_yacx_DoubleArg
#define _Included_yacx_DoubleArg
#ifdef __cplusplus
extern "C" {
#endif
#undef yacx_DoubleArg_SIZE_BYTES
#define yacx_DoubleArg_SIZE_BYTES 8L
/*
 * Class:     yacx_DoubleArg
 * Method:    createValue
 * Signature: (D)Lyacx/KernelArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_DoubleArg_createValue
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     yacx_DoubleArg
 * Method:    create
 * Signature: (Lyacx/DoubleArg;Z)Lyacx/DoubleArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_DoubleArg_create
  (JNIEnv *, jclass, jobject, jboolean);

/*
 * Class:     yacx_DoubleArg
 * Method:    createInternal
 * Signature: ([DZ)Lyacx/DoubleArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_DoubleArg_createInternal
  (JNIEnv *, jclass, jdoubleArray, jboolean);

/*
 * Class:     yacx_DoubleArg
 * Method:    createOutputInternal
 * Signature: (I)Lyacx/DoubleArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_DoubleArg_createOutputInternal
  (JNIEnv *, jclass, jint);

/*
 * Class:     yacx_DoubleArg
 * Method:    asDoubleArray
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_yacx_DoubleArg_asDoubleArray
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif