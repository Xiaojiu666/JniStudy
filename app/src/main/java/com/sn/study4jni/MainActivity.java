package com.sn.study4jni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.sn.study4jni.nativeInterface.TestInterface;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String text = TestInterface.getStringFromNDK();
        String text1 =  LogNativeInterface.logWrite();
//        String textC = TestInterfaceC.getStringFromNDK();
//        Log.i(TAG, "text : " + text);
//        Log.i(TAG, "textC :" + textC);
        ((TextView) findViewById(R.id.tv)).setText(text1);
//        new DynamicNative().registerDynamic();
        registerDynamic();
        Log.e(TAG, Nlog.SYS_INFO);
    }

    public native String registerDynamic();
}