def mss(key: String): String =
    key.reverse

val foo : Seq[String] = Seq(s"Hello", s"World")
val bar = foo.map(mss)

println(bar.reverse.mkString(" "))
