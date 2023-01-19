package com.example.test1114_09_02

import android.content.Context
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.view.MotionEvent
import android.view.View

class MainActivity : AppCompatActivity() {
    companion object{
        const val LINE = 1
        const val CIRCLE = 2
        const val SQUARE = 3
        var curShape = LINE
        val paint = Paint()

        var startXArray = arrayListOf<Float>()
        var startYArray = arrayListOf<Float>()
        var stopXArray = arrayListOf<Float>()
        var stopYArray = arrayListOf<Float>()
        var shapeArray = arrayListOf<Int>()
        var colorArray = arrayListOf<Int>()
        var colorCheck = 0
    }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        setContentView(MyGraphicView(this))
        title = "간단 그림판"
        paint.color = Color.RED
    }
    private class MyGraphicView(context: Context): View(context){
        var startX = -1
        var startY = -1
        var stopX = -1
        var stopY = -1

        override fun onTouchEvent(event: MotionEvent?): Boolean {

            when(event!!.action){
                MotionEvent.ACTION_DOWN->{
                    startX = event.x.toInt()
                    startY = event.y.toInt()
                    startXArray.add(startX.toFloat())
                    startYArray.add(startY.toFloat())
                    stopX = startX
                    stopY = startY
                }
                MotionEvent.ACTION_MOVE->{
                    stopX = event.x.toInt()
                    stopY = event.y.toInt()

                    this.invalidate()
                }
                MotionEvent.ACTION_UP->{
                    stopX = event.x.toInt()
                    stopY = event.y.toInt()

                    stopXArray.add(stopX.toFloat())
                    stopYArray.add(stopY.toFloat())
                    shapeArray.add(curShape)
                    colorArray.add(colorCheck)

                    this.invalidate()
                }
            }
            this.invalidate()

            return true
        }

        override fun onDraw(canvas: Canvas?) {
            super.onDraw(canvas)

            paint.isAntiAlias = true
            paint.strokeWidth = 5f
            paint.style = Paint.Style.STROKE

            if(colorCheck == 0) paint.color = Color.RED
            else if(colorCheck == 1) paint.color = Color.BLUE
            when(curShape){
                LINE -> canvas!!.drawLine(startX.toFloat(),startY.toFloat(),stopX.toFloat(),stopY.toFloat(),paint)
                CIRCLE->{
                    var radius = Math.sqrt(Math.pow((stopX.toFloat()-startX.toFloat()).toDouble(),2.0)+
                            Math.pow((stopY.toFloat()-startY.toFloat()).toDouble(),2.0))
                    canvas!!.drawCircle(startX.toFloat(),startY.toFloat(),radius.toFloat(),paint)
                }
                SQUARE->{
                    canvas!!.drawRect(startX.toFloat(),startY.toFloat(),stopX.toFloat(),stopY.toFloat(),paint)
                }

            }

            if(stopXArray.size >= 1){
                for(i in 0..stopXArray.size-1){
                    if(colorArray[i] == 0) paint.color = Color.RED
                    else if(colorArray[i] == 1) paint.color = Color.BLUE
                    when(shapeArray[i]){
                        LINE -> canvas!!.drawLine(startXArray[i],startYArray[i],stopXArray[i],stopYArray[i],paint)
                        CIRCLE->{
                            var radius = Math.sqrt(Math.pow((stopXArray[i]-startXArray[i]).toDouble(),2.0)+
                                            Math.pow((stopYArray[i]-startYArray[i]).toDouble(),2.0))
                            canvas!!.drawCircle(startXArray[i],startYArray[i],radius.toFloat(),paint)
                        }
                        SQUARE->{
                            canvas!!.drawRect(startXArray[i],startYArray[i],stopXArray[i],stopYArray[i], paint)
                        }

                    }
                }
            }
        }
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        super.onCreateOptionsMenu(menu)
        menu!!.add(0,1,0,"선 그리기")
        menu!!.add(0,2,0,"원 그리기")
        menu!!.add(0,3,0,"사각형 그리기")
        var sub:Menu = menu!!.addSubMenu(0,4,0,"색상 변경")
        sub!!.add(0,101,0,"빨강")
        sub!!.add(0,102,0,"파랑")
        menu!!.add(0,5,0,"선택 후 화면 클릭 시 마지막 그리기 되돌리기")
        menu!!.add(0,6,0,"선택 후 화면 클릭 시 전체 지우기")
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when(item.itemId){
            1->{
                curShape = LINE
                return true
            }
            2->{
                curShape = CIRCLE
                return true
            }
            3->{
                curShape = SQUARE
                return true
            }
            4->{
                return true
            }
            101->{
                paint.color = Color.RED
                colorCheck = 0
                return true
            }
            102->{
                paint.color = Color.BLUE
                colorCheck = 1
                return true
            }
            5->{
                if(startXArray.size != 0) startXArray.removeLast()
                if(startYArray.size != 0) startYArray.removeLast()
                if(stopXArray.size != 0) stopXArray.removeLast()
                if(stopYArray.size != 0) stopYArray.removeLast()
                if(colorArray.size != 0) colorArray.removeLast()

                return true
            }
            6->{
                startXArray.clear()
                startYArray.clear()
                stopXArray.clear()
                stopYArray.clear()
                colorArray.clear()

                return true
            }
        }
        return super.onOptionsItemSelected(item)
    }
}