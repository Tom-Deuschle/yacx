/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class Program */

#ifndef _Included_Program
#define _Included_Program
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     Program
 * Method:    createInternal
 * Signature: (Ljava/lang/String;Ljava/lang/String;)LProgram;
 */
JNIEXPORT jobject JNICALL Java_Program_createInternal__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     Program
 * Method:    createInternal
 * Signature: (Ljava/lang/String;Ljava/lang/String;LHeaders;)LProgram;
 */
JNIEXPORT jobject JNICALL Java_Program_createInternal__Ljava_lang_String_2Ljava_lang_String_2LHeaders_2
  (JNIEnv *, jclass, jstring, jstring, jobject);

/*
 * Class:     Program
 * Method:    instantiateInternal
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_Program_instantiateInternal
  (JNIEnv *, jobject, jstring);

/*
 * Class:     Program
 * Method:    compile
 * Signature: ()LKernel;
 */
JNIEXPORT jobject JNICALL Java_Program_compile
  (JNIEnv *, jobject);

/*
 * Class:     Program
 * Method:    compileInternal
 * Signature: (LOptions;)LKernel;
 */
JNIEXPORT jobject JNICALL Java_Program_compileInternal
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
