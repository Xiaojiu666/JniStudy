package com.sn.study4jni;

public class LogNativeInterface {
    static {
        System.loadLibrary("native-lib");
    }

    public static native String logWrite();

}
