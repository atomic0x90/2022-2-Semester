package com.example.test1124_14_01

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    lateinit var soundIntent: Intent
    lateinit var btnStart: Button
    lateinit var btnStop: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        title = "서비스 테스트 예제"

        soundIntent = Intent(this, MusicService::class.java)
        btnStart = findViewById<Button>(R.id.btnStart)
        btnStop = findViewById<Button>(R.id.btnStop)

        btnStart.setOnClickListener {
            startService(soundIntent)
            //android.util.Log.i("서비스 테스트", "startService()")
            Toast.makeText(this,"startService()",Toast.LENGTH_SHORT).show()
            finish()
        }

        btnStop.setOnClickListener {
            stopService(soundIntent)
            //android.util.Log.i("서비스 테스트", "stopService()")
            Toast.makeText(this,"stopService()",Toast.LENGTH_SHORT).show()
        }
    }
}