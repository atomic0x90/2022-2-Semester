package com.example.test1124_14_01

import android.content.Intent
import android.media.MediaPlayer
import android.os.IBinder
import android.widget.Toast

class MusicService  : android.app.Service(){
    lateinit var mp: MediaPlayer

    override fun onBind(p0: Intent?): IBinder? {
        return null
    }

    override fun onStartCommand(intent: Intent?, flags: Int, startId: Int): Int {
        //android.util.Log.i("서비스 테스트", "onStartCommand()")
        Toast.makeText(this,"onStartCommandService()",Toast.LENGTH_SHORT).show()
        mp = MediaPlayer.create(this, R.raw.song1)
        mp.isLooping = true
        mp.start()
        return super.onStartCommand(intent, flags, startId)
    }

    override fun onCreate() {
        //android.util.Log.i("서비스 테스트", "onCreate()")
        Toast.makeText(this,"onCreateService()", Toast.LENGTH_SHORT).show()
        super.onCreate()
    }

    override fun onDestroy() {
        //android.util.Log.i("서비스 테스트", "onDestroy()")
        mp.stop()
        super.onDestroy()
    }

}
