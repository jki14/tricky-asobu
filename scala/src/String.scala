val foo = Set("Nana","","Daiba")
println(s"Result: ${foo.mkString(",")}")

val bar = s"Hello World".split(' ').reverse.mkString("++")
println(bar)

println({
    val foo = s"nlb-in-Z4I4-abc.xyz.com"
    foo.split('.')(0).split('-').reverse(1)
})

println({
    val foo = s"nlb-in-Z4I4-abc"
    foo.split('.')(0).split('-').reverse(1)
})
