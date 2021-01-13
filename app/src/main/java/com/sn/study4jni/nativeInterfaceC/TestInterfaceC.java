package com.sn.study4jni.nativeInterfaceC;

public class TestInterfaceC {
    static {
        System.loadLibrary("native-lib-c");
    }

    public static native String getStringFromNDK();

    public static native int getInt4Ndk();
}
