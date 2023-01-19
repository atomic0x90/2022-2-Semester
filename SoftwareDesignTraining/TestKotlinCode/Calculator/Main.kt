fun main(args: Array<String>) {
    val sum = {x:Int,y:Int->x+y}
    val sub = {x:Int,y:Int->x-y}
    val mul = {x:Int,y:Int->x*y}
    val div = {x:Int,y:Int->x/y}

    calculator(12,12,sum)
    calculator(12,12,sub)
    calculator(12,12,mul)
    calculator(12,12,div)

}

fun calculator(a:Int,b:Int,op:(Int,Int)->Int){
    println("result is : $a, $b "+op(a,b))
}