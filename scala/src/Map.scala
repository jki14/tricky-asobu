def mss(key: String): String =
    key.reverse

val foo : Seq[String] = Seq(s"Hello", s"World")
val bar = foo.map(mss)

println(bar.reverse.mkString(" "))

var map : Map[String, Set[String]] = Map.empty
map = map + ("CORP" -> Set[String]("X", "A", "Y"))
map = map + ("PROD" -> Set[String]("A", "Z", "Y"))

println(map.mkString("\n"))

var insect : Set[String] = Set("U")
insect ++= map("CORP") & map("PROD")
println(insect.mkString(" "))
