val nullx = None: Option[Int]
val nully = None: Option[Int]
var seven = None: Option[Int]

seven = Some(7)

val check = (opt: Option[Int]) => opt match {
    case Some(i) =>
        println(s"Found $i")
    case None =>
        println("Not found")
}

check(nullx)
check(seven)

println(7 + nullx.getOrElse(nully.getOrElse(seven.get)))

val fourt :Int = 14
println(nullx)
println(nullx.getOrElse(fourt))
println(seven.getOrElse(fourt))
println(nullx.fold("")(_.toString))
println(seven.fold("")(_.toString))
println(nully.toString)
println(seven.fold(0)(_.toInt))
println(nully.fold(0)(_.toInt))

def inc(x: Int) = x + 1
println(nullx.fold(0)(inc))
println(seven.fold(0)(inc))

val foo = fourt - seven.fold(fourt)(_.toInt)

println(s"${nullx.contains(7)}")
println(s"${seven.contains(7)}")
