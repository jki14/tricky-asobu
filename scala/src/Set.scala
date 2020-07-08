val foo = Set('a', 'b')
val bar = Set('b', 'c')

println((foo ++ bar).mkString(" "))
println((foo -- bar).mkString(" "))
println((foo & bar).mkString(" "))
println((foo | bar).mkString(" "))
println((foo &~ bar).mkString(" "))
