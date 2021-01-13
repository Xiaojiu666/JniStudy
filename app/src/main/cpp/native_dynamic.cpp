//
// Created by 41798 on 2021/1/13.
//

#include "native_dynamic.h"

#include <jni.h>
#include <assert.h>
#include"android/log.h"

//#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"TAG","__VA_ARGS__")


extern "C"
JNIEXPORT jstring JNICALL
jniRegisterDynamic(JNIEnv *env, jobject thiz) {
    // TODO: implement registerDynamic()
//    LOGD("jniRegisterDynamic...");
    __android_log_print(ANDROID_LOG_ERROR,"JNI","jniRegisterDynamic");
    return env->NewStringUTF("jniRegisterDynamic");
}


static JNINativeMethod methods[] = {
        {"registerDynamic","()Ljava/lang/String;",(void*)jniRegisterDynamic},
};

jint registerNativeMethods(JNIEnv*env,JNINativeMethod *methods_,const char* clsName,jint methodNum) {
    jclass clz = env->FindClass(clsName);
    if (clz != NULL) {
        if (env->RegisterNatives(clz, methods_, methodNum) < 0) {
            return JNI_ERR;
        }
    }
    return JNI_OK;
}


jint JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv *env = NULL;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        //return JNI_ERR;
//        LOGD("JNI_OnLoad JNI_VERSION_1_6...");
        __android_log_print(ANDROID_LOG_ERROR,"JNI","JNI_VERSION_1_6");
    }
    if(env == NULL){
        if(vm->GetEnv((void **)&env,JNI_VERSION_1_4) != JNI_OK){
//            LOGD("JNI_OnLoad JNI_VERSION_1_4...");
            __android_log_print(ANDROID_LOG_ERROR,"JNI","JNI_VERSION_1_4");
            return JNI_ERR;
        }
    }
    assert(env != NULL);
    if(env){
        if(registerNativeMethods(env,
                                 methods,
                                 "com/sn/study4jni/MainActivity",
                                 sizeof(methods)/sizeof(methods[0])) != JNI_OK){
//            LOGD("JNI_OnLoad registerNativeMethods...sizeof(methods) = %d",sizeof(methods));
            __android_log_print(ANDROID_LOG_ERROR,"JNI","nb");
            return JNI_ERR;
        }
    }
    return JNI_VERSION_1_6;
}


void JNI_OnUnload(JavaVM* vm, void* reserved){
    JNIEnv *env = NULL;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        return;
    }
    assert(env != NULL);
    jclass clz = env->FindClass("com/sn/study4jni/MainActivity");
    if(env){
        env->UnregisterNatives(clz);
    }
    return;
}