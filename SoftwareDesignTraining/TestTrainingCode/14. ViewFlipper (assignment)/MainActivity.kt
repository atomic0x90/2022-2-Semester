package com.example.test1031_6_2

import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.ViewFlipper
import androidx.annotation.RequiresApi

class MainActivity : AppCompatActivity() {
    lateinit var btn1 : Button
    lateinit var btn2 : Button
    lateinit var vFlipper : ViewFlipper
    @RequiresApi(Build.VERSION_CODES.Q)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        btn1 = findViewById(R.id.button1)
        btn2 = findViewById(R.id.button2)
        vFlipper = findViewById(R.id.viewFlipper1)

        btn1.setOnClickListener {
            vFlipper.flipInterval = 1000
            vFlipper.startFlipping()
        }
        btn2.setOnClickListener {
            vFlipper.stopFlipping()
        }

    }
}