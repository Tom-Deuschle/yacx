#include "ShortArg.h"
#include "Handle.h"
#include "KernelArgJNI.hpp"
#include "../../include/yacx/KernelArgs.hpp"

using yacx::KernelArg, jni::KernelArgJNI;

jobject JNICALL Java_ShortArg_createValue(JNIEnv* env, jclass cls, jshort jvalue){
	BEGIN_TRY
		cls = getClass(env, "KernelArg");
		if (cls == NULL) return NULL;

		KernelArgJNI* kernelArgPtr = new KernelArgJNI{&jvalue, sizeof(jshort), false, false, false};

		return createJNIObject(env, cls, kernelArgPtr);
	END_TRY("creating ShortValueArg")
}

jobject Java_ShortArg_createInternal (JNIEnv* env, jclass cls, jshortArray jarray, jboolean jdownload){
    BEGIN_TRY
        CHECK_NULL(jarray, NULL)

        auto arrayPtr = env->GetShortArrayElements(jarray, NULL);
        auto arrayLength = env->GetArrayLength(jarray);

        CHECK_BIGGER(arrayLength, 0, "illegal array length", NULL)

        KernelArgJNI* kernelArgPtr = new KernelArgJNI{arrayPtr, arrayLength * sizeof(jshort), jdownload, true, true};

        env->ReleaseShortArrayElements(jarray, arrayPtr, JNI_ABORT);

        return createJNIObject(env, cls, kernelArgPtr);
    END_TRY("creating ShortArg")
}

jobject Java_ShortArg_createOutputInternal (JNIEnv* env, jclass cls, jint jarrayLength){
    BEGIN_TRY
        CHECK_BIGGER(jarrayLength, 0, "illegal array length", NULL)

        KernelArgJNI* kernelArgPtr = new KernelArgJNI{NULL, static_cast<size_t> (jarrayLength) * sizeof(jshort), true, false, true};

    	return createJNIObject(env, cls, kernelArgPtr);
    END_TRY("creating ShortArg")
}

jshortArray Java_ShortArg_asShortArray (JNIEnv* env, jobject obj){
    BEGIN_TRY
        auto kernelArgJNIPtr = getHandle<KernelArgJNI>(env, obj);
    	CHECK_NULL(kernelArgJNIPtr, NULL)
        auto data = kernelArgJNIPtr->getHostData();
        auto dataSize = kernelArgJNIPtr->kernelArgPtr()->size();

        auto res = env->NewShortArray(dataSize / sizeof(jshort));

        CHECK_NULL(res, NULL)

        env->SetShortArrayRegion(res, 0, dataSize / sizeof(jshort),
                                   reinterpret_cast<const jshort*>(data));
        return res;
    END_TRY("getting ShortArg-content")
}

