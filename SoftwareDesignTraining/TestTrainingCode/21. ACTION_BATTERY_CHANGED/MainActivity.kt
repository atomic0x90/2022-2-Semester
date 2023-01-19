package com.example.test1128_exam_14_2

import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.os.BatteryManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.EditText
import android.widget.ImageView
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    lateinit var ivBattery: ImageView
    lateinit var edtBattery: EditText

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        title = "배터리 상태 체크"

        ivBattery = findViewById<ImageView>(R.id.ivBattery)
        edtBattery = findViewById<EditText>(R.id.edtBattery)

    }

    var br: BroadcastReceiver = object : BroadcastReceiver() {
        override fun onReceive(context: Context, intent: Intent) {
            var action = intent.action
            if (action == Intent.ACTION_BATTERY_CHANGED) {
                var remain = intent.getIntExtra(BatteryManager.EXTRA_LEVEL, 0)
                edtBattery.setText("현재 충전량 : $remain\n")

                if (remain >= 90)
                    ivBattery.setImageResource(R.drawable.battery_100)
                else if (remain >= 70)
                    ivBattery.setImageResource(R.drawable.battery_80)
                else if (remain >= 50)
                    ivBattery.setImageResource(R.drawable.battery_60)
                else if (remain >= 10)
                    ivBattery.setImageResource(R.drawable.battery_20)
                else
                    ivBattery.setImageResource(R.drawable.battery_0)

                var plug = intent.getIntExtra(BatteryManager.EXTRA_PLUGGED, 0)
                when (plug) {
                    0 -> {
                        edtBattery.append("전원 연결 : 안됨")
                        Toast.makeText(applicationContext,"배터리 상태: 배터리 충전 중 아님",Toast.LENGTH_SHORT).show()
                    }
                    BatteryManager.BATTERY_PLUGGED_AC -> {
                        edtBattery.append("전원 연결 : 어댑터 연결됨")
                        Toast.makeText(applicationContext,"배터리 상태: 배터리 충전 중",Toast.LENGTH_SHORT).show()
                    }
                    BatteryManager.BATTERY_PLUGGED_USB -> {
                        edtBattery.append("전원 연결 : USB 연결됨")
                        Toast.makeText(applicationContext,"배터리 상태: 배터리 충전 중",Toast.LENGTH_SHORT).show()
                    }
                }
            }
        }
    }
    override fun onPause() {
        super.onPause()
        unregisterReceiver(br)
    }

    override fun onResume() {
        super.onResume()
        var iFilter = IntentFilter()
        iFilter.addAction(Intent.ACTION_BATTERY_CHANGED)
        registerReceiver(br, iFilter)
    }
}
