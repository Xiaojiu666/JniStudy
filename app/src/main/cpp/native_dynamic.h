#ifndef NDK_CORE_H
#define NDK_CORE_H

#define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))

#include <jni.h>
#include <stdlib.h>

__BEGIN_DECLS

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved);


__END_DECLS

#endif //TEXT_HELLO_H