package com.example.test1006_4_4
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.*

class MainActivity : AppCompatActivity() {
    lateinit var checkAgree : Switch
    lateinit var text1 : TextView
    lateinit var text2 : TextView
    lateinit var rGroup : RadioGroup
    lateinit var rdoOreo :RadioButton
    lateinit var rdoPie : RadioButton
    lateinit var rdoQ : RadioButton
    lateinit var img : ImageView
    lateinit var exitButton : Button
    lateinit var reButton : Button
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        checkAgree = findViewById<Switch>(R.id.SwitchCheck)
        text1 = findViewById<TextView>(R.id.Text1)
        text2 = findViewById<TextView>(R.id.Text2)
        rGroup = findViewById<RadioGroup>(R.id.Rgroup1)
        rdoOreo = findViewById<RadioButton>(R.id.RdoOreo)
        rdoPie = findViewById<RadioButton>(R.id.RdoPie)
        rdoQ = findViewById<RadioButton>(R.id.RdoQ)

        img = findViewById<ImageView>(R.id.ImgPet)

        exitButton = findViewById<Button>(R.id.button1)
        reButton = findViewById<Button>(R.id.button2)

        checkAgree.setOnCheckedChangeListener { compoundButton,b ->
            if (b/*checkAgree.isChecked == true*/) {
                text2.visibility = android.view.View.VISIBLE;
                rGroup.visibility = android.view.View.VISIBLE;
                img.visibility = android.view.View.VISIBLE;
                exitButton.visibility = android.view.View.VISIBLE
                reButton.visibility = android.view.View.VISIBLE
            } else {
                text2.visibility = android.view.View.INVISIBLE;
                rGroup.visibility = android.view.View.INVISIBLE;
                img.visibility = android.view.View.INVISIBLE;
                exitButton.visibility = android.view.View.INVISIBLE
                reButton.visibility = android.view.View.INVISIBLE
            }
        }

        rdoOreo.setOnClickListener {
            img.setImageResource(R.drawable.oreo)
            img.visibility = android.view.View.VISIBLE
        }

        rdoPie.setOnClickListener {
            img.setImageResource(R.drawable.pie)
            img.visibility = android.view.View.VISIBLE
        }

        rdoQ.setOnClickListener {
            img.setImageResource(R.drawable.q10)
            img.visibility = android.view.View.VISIBLE
        }

        exitButton.setOnClickListener {
            moveTaskToBack(true);						// 태스크를 백그라운드로 이동
            finishAndRemoveTask();						// 액티비티 종료 + 태스크 리스트에서 지우기
            android.os.Process.killProcess(android.os.Process.myPid());	// 앱 프로세스 종료
        }

        reButton.setOnClickListener {
            img.setImageResource(0)
            rGroup.clearCheck()
            checkAgree.toggle()
        }
    }
}