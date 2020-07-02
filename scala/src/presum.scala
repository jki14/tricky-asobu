val foo = Array(1, 2, 3)
val bar = foo.scanLeft(0)(_ + _)
println(bar.mkString(" "))
