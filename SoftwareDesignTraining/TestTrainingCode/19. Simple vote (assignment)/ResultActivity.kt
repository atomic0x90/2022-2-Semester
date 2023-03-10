package com.example.test1119_exam_10_02

import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.LinearLayout
import android.widget.RatingBar
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity


class ResultActivity:AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.result)
        title = "투표 결과"

        var imageId = arrayOf(R.id.riv1, R.id.riv2, R.id.riv3, R.id.riv4, R.id.riv5, R.id.riv6, R.id.riv7, R.id.riv8, R.id.riv9)
        var llId = arrayOf(R.id.ll1,R.id.ll2,R.id.ll3,R.id.ll4,R.id.ll5,R.id.ll6,R.id.ll7,R.id.ll8,R.id.ll9)

        var voteMax = 0
        var checkMax = arrayOfNulls<Int>(9)
        println("Size"+checkMax.size)
        // 앞 화면에서 보낸 투표 결과 값을 받는다.
        var intent = intent
        var voteResult = intent.getIntArrayExtra("VoteCount")
        var imageName = intent.getStringArrayExtra("ImageName")

        // 9개의 TextView, RatingBar 객체배열
        var tv = arrayOfNulls<TextView>(imageName!!.size)
        var rbar = arrayOfNulls<RatingBar>(imageName!!.size)
        var svTv = arrayOfNulls<TextView>(imageName!!.size)

        // 9개의 TextView, RatingBar ID 배열
        var tvID = arrayOf(R.id.tv1, R.id.tv2, R.id.tv3, R.id.tv4, R.id.tv5, R.id.tv6, R.id.tv7, R.id.tv8, R.id.tv9)
        var rbarID = arrayOf(R.id.rbar1, R.id.rbar2, R.id.rbar3, R.id.rbar4, R.id.rbar5, R.id.rbar6, R.id.rbar7, R.id.rbar8, R.id.rbar9)
        var svTvID = arrayOf(R.id.svInTv1,R.id.svInTv2,R.id.svInTv3,R.id.svInTv4,R.id.svInTv5,R.id.svInTv6,R.id.svInTv7,R.id.svInTv8,R.id.svInTv9)

        // TextView, RatingBar 개체 찾기.
        for (i in voteResult!!.indices) {
            tv[i] = findViewById<TextView>(tvID[i])
            svTv[i] = findViewById<TextView>(svTvID[i])
            rbar[i] = findViewById<RatingBar>(rbarID[i])
            checkMax[i] = 0
        }

        // 각 TextVeiw 및 RatingBar에 넘겨 받은 값을 반영.
        for (i in voteResult.indices) {
            svTv[i]!!.setText(imageName[i])
            tv[i]!!.setText(imageName[i])
            rbar[i]!!.setRating(voteResult[i].toFloat())
            if(voteMax == voteResult[i]){
                checkMax[i] = 1
            }
            else if(voteMax < voteResult[i]){
                voteMax = voteResult[i]
                for(j in 0..i) checkMax[j] = 0
                checkMax[i] = 1
            }
        }

        for(i in 0..checkMax.size-1){
            println("checkMax "+checkMax[i]+" "+i+" "+imageId[i])
            var tmp = findViewById<LinearLayout>(llId[i])
            println(tmp)
            if(checkMax[i] == 0) tmp.visibility = View.GONE
            else tmp.visibility = View.VISIBLE
        }

        val metrics = resources.displayMetrics
        var btnReturn = findViewById<Button>(R.id.btnReturn)
        btnReturn.width = metrics.widthPixels
        btnReturn.setOnClickListener {
            finish()
        }

    }
}