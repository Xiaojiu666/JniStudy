//
// Created by 41798 on 2021/1/13.
//

#include "native_lib.h"
#include <jni.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include"android/log.h"

using namespace std;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_sn_study4jni_nativeInterface_TestInterface_getStringFromNDK(JNIEnv *env, jclass clazz) {
    // TODO: implement getStringFromNDK()
    std::string hello = "(*^__^*) 嘻嘻……~Hello from C++ 隔壁老李头";
    __android_log_print(ANDROID_LOG_ERROR,"JNI","nb");
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_sn_study4jni_nativeInterface_TestInterface_getInt4Ndk(JNIEnv *env, jclass clazz) {
    // TODO: implement getInt4Ndk()
    cout << "Hello, world!" << endl;
    printf("Hellow,World");
    return 0;
}

