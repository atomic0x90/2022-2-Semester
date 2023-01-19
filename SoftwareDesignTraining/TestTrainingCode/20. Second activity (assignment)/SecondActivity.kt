package com.example.test1121_exam_10_03

import android.app.Activity
import android.content.Intent
import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

class SecondActivity: AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_second)

        var inIntent = intent
        var n1 = inIntent.getStringExtra("Num1")
        var n2 = inIntent.getStringExtra("Num2")
        var what = inIntent.getIntExtra("what",1)
        var btn2 = findViewById<Button>(R.id.btn2)

        btn2.setOnClickListener {
            var result:Double = 0.0
            if(what == 1){
                result = n1!!.toDouble() + n2!!.toDouble()
            }
            else if(what == 2){
                result = n1!!.toDouble() - n2!!.toDouble()
            }
            else if(what == 3){
                result = n1!!.toDouble() * n2!!.toDouble()
            }
            else if(what == 4){
                result = n1!!.toDouble() / n2!!.toDouble()
            }

            var outIntent = Intent(applicationContext,MainActivity::class.java)
            outIntent.putExtra("result",result)
            setResult(Activity.RESULT_OK,outIntent)
            finish()
        }
    }
}