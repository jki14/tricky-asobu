val nullx = None: Option[Long]
val nully = None: Option[Long]
var seven = None: Option[Long]

seven = Some(7)

println(7 + nullx.getOrElse(nully.getOrElse(seven.get)))

val fourt :Int = 14
println(nullx.getOrElse(fourt))
println(seven.getOrElse(fourt))
println(nullx.fold("")(_.toString))
println(seven.fold("")(_.toString))
println(nully.toString)

val foo = fourt - seven.fold(fourt)(_.toInt)
