package com.example.test1121_exam_10_03

import android.app.Activity
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.RadioButton
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    lateinit var edt1:EditText
    lateinit var edt2:EditText
    lateinit var rdb1:RadioButton
    lateinit var rdb2:RadioButton
    lateinit var rdb3:RadioButton
    lateinit var rdb4:RadioButton
    lateinit var btn1: Button
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        edt1 = findViewById(R.id.edt1)
        edt2 = findViewById(R.id.edt2)
        rdb1 = findViewById(R.id.rdbPlus)
        rdb2 = findViewById(R.id.rdbMinus)
        rdb3 = findViewById(R.id.rdbMul)
        rdb4 = findViewById(R.id.rdbDiv)
        btn1 = findViewById(R.id.btn1)

        btn1.setOnClickListener {
            if(edt1.text.toString() != "" && edt2.text.toString() != "" && edt2.text.toString().toDouble() != 0.0){
                var intent = Intent(applicationContext,SecondActivity::class.java)
                intent.putExtra("Num1",edt1.text.toString())
                intent.putExtra("Num2",edt2.text.toString())
                var flag:Boolean = true
                if(rdb1.isChecked) intent.putExtra("what",1)
                else if(rdb2.isChecked) intent.putExtra("what",2)
                else if(rdb3.isChecked) intent.putExtra("what",3)
                else if(rdb4.isChecked) intent.putExtra("what",4)
                else flag = false

                if(flag) startActivityForResult(intent,0)
            }
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        if(resultCode == Activity.RESULT_OK){
            var result = data!!.getDoubleExtra("result",0.0)
            Toast.makeText(applicationContext,"결과: $result",Toast.LENGTH_SHORT).show()
        }
    }
}