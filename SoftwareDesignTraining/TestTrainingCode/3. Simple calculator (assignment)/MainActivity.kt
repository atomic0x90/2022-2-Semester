package com.example.test0929
import android.icu.number.IntegerWidth
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.core.text.isDigitsOnly
import kotlin.math.roundToInt

class MainActivity : AppCompatActivity() {
    lateinit var edit1 : EditText;  lateinit var edit2 : EditText
    lateinit var btnAdd : Button;   lateinit var btnSub : Button
    lateinit var btnMul : Button;   lateinit var btnDiv : Button
    lateinit var btnRma : Button;   lateinit var btnStr : Button
    lateinit var textResult : TextView
    lateinit var num1 : String;    lateinit var num2 : String
    var result : Double? = null
    var resultStr : String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        title = "초간단 계산기"

        edit1 = findViewById<EditText>(R.id.Edit1)
        edit2 = findViewById<EditText>(R.id.Edit2)
        btnAdd = findViewById<Button>(R.id.BtnAdd)
        btnSub = findViewById<Button>(R.id.BtnSub)
        btnMul = findViewById<Button>(R.id.BtnMul)
        btnDiv = findViewById<Button>(R.id.BtnDiv)
        btnRma = findViewById<Button>(R.id.BtnRma)
        btnStr = findViewById<Button>(R.id.BtnStr)

        textResult = findViewById<TextView>(R.id.TextResult)

        btnAdd.setOnClickListener {
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            if(num1.isNullOrBlank() || num2.isNullOrBlank()){
                Toast.makeText(applicationContext,"값을 입력하세요", Toast.LENGTH_SHORT).show()
            }
            else{
                Log.d("tag "," : "+num1.toDoubleOrNull())
                if(num1.toDoubleOrNull() != null && num2.toDoubleOrNull() != null){
                    result = num1.toDouble() + num2.toDouble()
                    textResult.text = "계산 결과 : " + result.toString()
                }
                else{
                    Toast.makeText(applicationContext,"숫자를 입력하세요", Toast.LENGTH_SHORT).show()
                }
            }
        }

        btnSub.setOnClickListener {
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            if(num1.isNullOrBlank() || num2.isNullOrBlank()){
                Toast.makeText(applicationContext,"값을 입력하세요", Toast.LENGTH_SHORT).show()
            }
            else{
                if(num1.toDoubleOrNull() != null && num2.toDoubleOrNull() != null){
                    result = num1.toDouble() - num2.toDouble()
                    textResult.text = "계산 결과 : " + result.toString()
                }
                else{
                    Toast.makeText(applicationContext,"숫자를 입력하세요", Toast.LENGTH_SHORT).show()
                }
            }
        }

        btnMul.setOnClickListener {
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            if(num1.isNullOrBlank() || num2.isNullOrBlank()){
                Toast.makeText(applicationContext,"값을 입력하세요", Toast.LENGTH_SHORT).show()
            }
            else{
                if(num1.toDoubleOrNull() != null && num2.toDoubleOrNull() != null){
                    result = num1.toDouble() * num2.toDouble()
                    textResult.text = "계산 결과 : " + (Math.round(result!!*100000)/100000.0).toString()
                }
                else{
                    Toast.makeText(applicationContext,"숫자를 입력하세요", Toast.LENGTH_SHORT).show()
                }
            }
        }

        btnDiv.setOnClickListener {
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            if(num1.isNullOrBlank() || num2.isNullOrBlank()){
                Toast.makeText(applicationContext,"값을 입력하세요", Toast.LENGTH_SHORT).show()
            }
            else{
                if(num1.toDoubleOrNull() != null && num2.toDoubleOrNull() != null){
                    if(num2.toDouble() != 0.0){
                        result = num1.toDouble() / num2.toDouble()
                        textResult.text = "계산 결과 : " + (Math.round(result!!*100000)/100000.0).toString()
                    }
                    else{
                        Toast.makeText(applicationContext,"0으로 나눌 수 없습니다", Toast.LENGTH_SHORT).show()
                    }
                }
                else{
                    Toast.makeText(applicationContext,"숫자를 입력하세요", Toast.LENGTH_SHORT).show()
                }
            }
        }

        btnRma.setOnClickListener {
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            if(num1.isNullOrBlank() || num2.isNullOrBlank()){
                Toast.makeText(applicationContext,"값을 입력하세요", Toast.LENGTH_SHORT).show()
            }
            else{
                if(num1.toDoubleOrNull() != null && num2.toDoubleOrNull() != null){
                    result = num1.toDouble() % num2.toDouble()
                    textResult.text = "계산 결과 : " + result.toString()
                }
                else{
                    Toast.makeText(applicationContext,"숫자를 입력하세요", Toast.LENGTH_SHORT).show()
                }
            }
        }

        btnStr.setOnClickListener {
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            textResult.text = "계산 결과 : " + num1+num2
        }

    }
}