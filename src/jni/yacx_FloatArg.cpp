#include "yacx_FloatArg.h"
#include "Handle.h"
#include "KernelArgJNI.hpp"
#include "Half.hpp"
#include "../../include/yacx/KernelArgs.hpp"

using yacx::KernelArg, jni::KernelArgJNI;

jobject JNICALL Java_yacx_FloatArg_createValue(JNIEnv* env, jclass cls, jfloat jvalue){
	BEGIN_TRY
		cls = getClass(env, "yacx/KernelArg");
		if (cls == NULL) return NULL;

		KernelArgJNI* kernelArgPtr = new KernelArgJNI{&jvalue, sizeof(jfloat), false, false, false};

		return createJNIObject(env, cls, kernelArgPtr);
	END_TRY_R("creating FloatValueArg", NULL)
}

jobject Java_yacx_FloatArg_createInternal (JNIEnv* env, jclass cls, jfloatArray jarray, jboolean jdownload){
    BEGIN_TRY
        CHECK_NULL(jarray, NULL)

        auto arrayPtr = env->GetFloatArrayElements(jarray, NULL);
        auto arrayLength = env->GetArrayLength(jarray);

        CHECK_BIGGER(arrayLength, 0, "illegal array length", NULL)

        KernelArgJNI* kernelArgPtr = new KernelArgJNI{arrayPtr, arrayLength * sizeof(jfloat), jdownload, true, true};

        env->ReleaseFloatArrayElements(jarray, arrayPtr, JNI_ABORT);

        return createJNIObject(env, cls, kernelArgPtr);
    END_TRY_R("creating FloatArg", NULL)
}

jobject Java_yacx_FloatArg_asHalfArg(JNIEnv* env, jobject obj){
    BEGIN_TRY
        auto kernelArgJNIPtr = getHandle<KernelArgJNI>(env, obj);
    	CHECK_NULL(kernelArgJNIPtr, NULL)
        auto kernelArgPtr = kernelArgJNIPtr->kernelArgPtr();
        auto data = kernelArgJNIPtr->getHostData();
        auto dataSize = kernelArgPtr->size();

        jclass cls = getClass(env, "yacx/HalfArg");
		if (cls == NULL) return NULL;

        KernelArgJNI* newkernelArgJNIPtr = new KernelArgJNI{NULL, dataSize/2,
            kernelArgPtr->isDownload(), kernelArgPtr->isCopy(), true};

        convertFtoH(data, kernelArgJNIPtr->getHostData(), dataSize);

		return createJNIObject(env, cls, newkernelArgJNIPtr);
    END_TRY_R("converting FloatArg to HalfArg", NULL)
}

jfloatArray Java_yacx_FloatArg_asFloatArray (JNIEnv* env, jobject obj){
    BEGIN_TRY
        auto kernelArgJNIPtr = getHandle<KernelArgJNI>(env, obj);
    	CHECK_NULL(kernelArgJNIPtr, NULL)
        auto data = kernelArgJNIPtr->getHostData();
        auto dataSize = kernelArgJNIPtr->kernelArgPtr()->size();

        auto res = env->NewFloatArray(dataSize / sizeof(jfloat));

        CHECK_NULL(res, NULL)

        env->SetFloatArrayRegion(res, 0, dataSize / sizeof(jfloat),
                                   reinterpret_cast<const jfloat*>(data));
        return res;
    END_TRY_R("getting FloatArg-content", NULL)
}
