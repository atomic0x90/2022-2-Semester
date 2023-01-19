package com.example.pretest1013_1

import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val params = LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT,
            LinearLayout.LayoutParams.MATCH_PARENT
        )

        val baseLayout = LinearLayout(this)
        baseLayout.orientation = LinearLayout.VERTICAL
        baseLayout.setBackgroundColor(Color.rgb(0,100,0))
        setContentView(baseLayout,params)

        var btn = Button(this)
        btn.text = "버튼입니다"
        btn.setBackgroundColor(Color.MAGENTA)
        baseLayout.addView(btn)

        btn.setOnClickListener{
            Toast.makeText(applicationContext,"button click",Toast.LENGTH_SHORT).show()
        }

        var editText = EditText(this)
        var btn2 = Button(this)
        var textView = TextView(this)

        baseLayout.addView(editText)
        baseLayout.addView(btn2)
        baseLayout.addView(textView)

        btn2.text = "btn2"
        btn2.setBackgroundColor(Color.YELLOW)
        btn2.setOnClickListener{
            textView.setText(editText.text)
        }
    }
}