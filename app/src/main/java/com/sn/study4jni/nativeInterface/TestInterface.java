package com.sn.study4jni.nativeInterface;

public class TestInterface {
    static {
        System.loadLibrary("native-lib");
    }

    public static native String getStringFromNDK();

    public static native int getInt4Ndk();
}
