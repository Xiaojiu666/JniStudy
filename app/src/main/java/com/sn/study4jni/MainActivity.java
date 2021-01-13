package com.sn.study4jni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.sn.study4jni.R;
import com.sn.study4jni.nativeInterface.TestInterface;
import com.sn.study4jni.nativeInterfaceC.TestInterfaceC;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String text = TestInterface.getStringFromNDK();
//        String textC = TestInterfaceC.getStringFromNDK();
        Log.i(TAG, "text : " + text);
//        Log.i(TAG, "textC :" + textC);
        ((TextView) findViewById(R.id.tv)).setText(text);
    }
}