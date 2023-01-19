fun main(args: Array<String>) {
    println("Hello World!")

    // Try adding program arguments via Run/Debug configuration.
    // Learn more about running applications: https://www.jetbrains.com/help/idea/running-applications.html.
    println("Program arguments: ${args.joinToString()}")

    var myCar1 : Car = Car()
    var myTruck : Truck = Truck(300)

    myTruck.speed = 20
    myTruck.upSpeed(140)
    myTruck.color = "red"
    println("배기량"+myTruck.cc)
    println("색상"+myTruck.color)
    println("속도"+myTruck.speed)
    println(Truck.YEAR)

}
open class Car{
    var color : String = ""
    var speed : Int = 0

    open fun upSpeed(value : Int){
        if(speed+value >= 200)
            speed = 200
        else
            speed = speed + value
    }
    fun downSpeed(value : Int){
        if(speed-value <= 0)
            speed = 0
        else
            speed = speed - value
    }
}
class Truck : Car{
    var cc : Int = 0

    constructor(cc : Int){
        this.cc = cc
    }

    companion object{
        const val YEAR : Int = 2023

    }

    override fun upSpeed(value:Int){
        if(speed+value >= 150)
            speed = 150
        else
            speed = speed + value
    }
}