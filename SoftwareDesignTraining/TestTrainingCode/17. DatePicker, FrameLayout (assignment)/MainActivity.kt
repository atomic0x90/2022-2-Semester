package com.example.ex_6_1

import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.SystemClock
import android.view.View
import android.widget.*
import androidx.annotation.RequiresApi

class MainActivity : AppCompatActivity() {
    lateinit var chronometer : Chronometer
    lateinit var radioGroup : RadioGroup
    lateinit var radioButton1 : Button
    lateinit var radioButton2 : Button
    lateinit var timePicker : TimePicker
    lateinit var datePicker: DatePicker
    lateinit var YMDTtextView : TextView

    @RequiresApi(Build.VERSION_CODES.M)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        chronometer = findViewById(R.id.chronometer)
        radioGroup = findViewById(R.id.radioGroup)
        radioButton1 = findViewById(R.id.radiobutton1)
        radioButton2 = findViewById(R.id.radiobutton2)
        timePicker = findViewById(R.id.timepicker)
        datePicker = findViewById(R.id.datepicker)
        YMDTtextView = findViewById(R.id.textViewYMDT)

        chronometer.setOnClickListener{
            chronometer.setBase(SystemClock.elapsedRealtime())
            radioGroup.visibility = View.VISIBLE
            chronometer.start()
            YMDTtextView.text = "0000년00월00일00시00분 예약됨"
        }
        radioButton1.setOnClickListener {
            datePicker.visibility = View.VISIBLE
            timePicker.visibility = View.GONE
        }
        radioButton2.setOnClickListener {
            datePicker.visibility = View.GONE
            timePicker.visibility = View.VISIBLE
        }

        YMDTtextView.setOnLongClickListener {
            var years:String=""
            var months:String=""
            var dates:String=""
            var hours:String=""
            var mins:String=""
            years = datePicker.year.toString()
            months = (datePicker.month+1).toString()
            dates = datePicker.dayOfMonth.toString()
            hours = timePicker.hour.toString()
            mins = timePicker.minute.toString()
            YMDTtextView.text = years+"년"+months+"월"+dates+"일"+hours+"시"+mins+"분 예약됨"
            chronometer.stop()
            radioGroup.visibility = View.INVISIBLE
            timePicker.visibility = View.GONE
            datePicker.visibility = View.GONE
            radioGroup.clearCheck()
            true
        }
    }
}