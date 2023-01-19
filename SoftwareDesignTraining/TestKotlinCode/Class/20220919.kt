class MyClass(value:Int){
    var value:Int=0
    init{
        this.value=value
    }

}

fun main(){
    var c1 = MyClass(10)
    var c2 = MyClass(20)
    var c3 = MyClass(30)
    //generics

    var myList = ArrayList<MyClass>(3)
    myList.add(c1)
    myList.add(c2)
    myList.add(c3)
    val a={
            list:ArrayList<MyClass> ->
        var sum:Int =0
        for(i in 0 until list.size){
            sum += list[i].value
        }
        sum
    }
/*
    for(i in 0 until myList.size){
        hap += myList[i]
    }
*/
    /*
    val sum:(Int,Int,Int)->Int={no1,no2,no3->no1+no2+no3}
    hap = sum(myList[0],myList[1],myList[2])
*/

    print(a(myList))

}