package com.example.test1006_2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.*

class MainActivity : AppCompatActivity() {
    lateinit var checkAgree : CheckBox
    lateinit var text1 : TextView
    lateinit var text2 : TextView
    lateinit var rGroup : RadioGroup
    lateinit var rdoDog :RadioButton
    lateinit var rdoCat : RadioButton
    lateinit var rdoRabbit : RadioButton
    lateinit var btnOK : Button
    lateinit var imgPet : ImageView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        checkAgree = findViewById<CheckBox>(R.id.ChkAgree)
        text1 = findViewById<TextView>(R.id.Text1)
        text2 = findViewById<TextView>(R.id.Text2)
        rGroup = findViewById<RadioGroup>(R.id.Rgroup1)
        rdoDog = findViewById<RadioButton>(R.id.RdoDog)
        rdoCat = findViewById<RadioButton>(R.id.RdoCat)
        rdoRabbit = findViewById<RadioButton>(R.id.RdoRabbit)

        btnOK = findViewById<Button>(R.id.BtnOK)
        imgPet = findViewById<ImageView>(R.id.ImgPet)

        checkAgree.setOnCheckedChangeListener { compoundButton,b ->
            if (/*b*/checkAgree.isChecked) {
                text2.visibility = android.view.View.VISIBLE;
                rGroup.visibility = android.view.View.VISIBLE;
                btnOK.visibility = android.view.View.VISIBLE;
                imgPet.visibility = android.view.View.VISIBLE;
            } else {
                text2.visibility = android.view.View.INVISIBLE;
                rGroup.visibility = android.view.View.INVISIBLE;
                btnOK.visibility = android.view.View.INVISIBLE;
                imgPet.visibility = android.view.View.INVISIBLE;
            }
        }

        btnOK.setOnClickListener {
            when (rGroup.checkedRadioButtonId) {
                R.id.RdoDog -> imgPet.setImageResource(R.drawable.dog)
                R.id.RdoCat -> imgPet.setImageResource(R.drawable.cat)
                R.id.RdoRabbit -> imgPet.setImageResource(R.drawable.rabbit)
                else -> Toast.makeText(applicationContext, "동물 먼저 선택하세요", Toast.LENGTH_SHORT).show()
            }
        }

    }
}