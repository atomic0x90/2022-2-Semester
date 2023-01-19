fun main(){
    var var1:Int = 10
    var var2:Float = 10.1f
    var var3:Double = 10.2
    var var4:Char = '안'
    var var5:String = "안드로이드"
    println(var1)
    println(var2)
    println(var3)
    println(var4)
    println(var5)

    var notNull:Int = 1
    var okNull:Int? = null
    var test:Int
    test = 12!!
    println(notNull)
    println(okNull)
    println(test)

    //var ar = Array<Int>(10,{0})
    var ar = Array<Int>(10){0}
    ar[3] = 3
    for(i in ar)
        print(i)

    println("\ntwo")

    var two = Array<IntArray>(3,{IntArray(4){1} })
    for(i in two){
        for(j in i) print(j)
        print("\n")
    }

    var one = ArrayList<Int>(4)
    one.add(1)
    one.add(2)
    println(one.get(0).toString()+one.get(1))

    //var square: (Int)->Int={x -> x*x}
    var square:(Int)->Int = {x->x*x}

    println(square(2))

    var result = callByValue(lambda())
    println(result)

    result = callByName(otherLambda)
    println(result)
/*
    fun sum(x:Int,y:Int) = x+y
    fun funcParam(a:Int,b:Int,c:(Int,Int)->Int):Int{return c(a,b)}
    println(funcParam(3,2,::sum))
*/
    var sum:(x:Int,y:Int)->Int = {x,y->x+y}
    fun funcParam(a:Int,b:Int,c:(Int,Int)->Int):Int{return c(a,b)}
    println(funcParam(3,2,sum))

    val some:(Int)->Unit = {println(it)}
    some(10)


    val res = hofFun({no->no>0})
    println(res())

    var jumsu:Int = 91
    when(jumsu){
        in 90..100 -> println("A")
        60,70,80->println("B")
        else -> println("F")
    }
/*
    var a:Int
    val b:Float = 3.14F
    b = 3.1234
    println(a)
    println(b)*/

    /*
    var f = {x:Int,y:Int->x+y}
    val f2 = {x:Int,y:Int->x+y}
    println(f2(1,2))
    println(f2(3,4))
*/
    println(cal(1,3))
    println(cal(1.5,3.0))

}
fun cal(x:Int,y:Int):Int{return x/y}

fun cal(x:Double,y:Double): Double {return x/y}

fun hofFun(arg:(Int)->Boolean):()->String{
    val result:String = if(arg(10)){"o"}else{"x"}
    return {result}
}

fun callByValue(b:Boolean):Boolean{
    println("A")
    return b
}

val lambda:()->Boolean = {
    println("B");
    false
}

fun callByName(b:()->Boolean):Boolean{
    println("C")
    return b()
}

val otherLambda:()->Boolean={
    println("D")
    true
}