#include "KernelArgJNI.hpp"

#include "../../include/yacx/Exception.hpp"
#include <cuda.h>
#include <cstring>
#include <stdio.h>

using jni::KernelArgJNI, yacx::KernelArg;

KernelArgJNI::KernelArgJNI(void* const data, size_t size, bool download, bool copy, bool upload) {
	//Allocating pinned memory
	CUDA_SAFE_CALL(cuMemAllocHost(&_hdata, size));
    if (data)
        std::memcpy(_hdata, data, size);

    kernelArg = new KernelArg{_hdata, size, download, copy, upload};
}

KernelArgJNI::~KernelArgJNI() {
	CUDA_SAFE_CALL(cuMemFreeHost(_hdata));
    delete kernelArg;
}
