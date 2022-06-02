val booleans = List(false, true)

for (w <- booleans) {
    for (x <- booleans) {
        for (y <- booleans) {
            for (z <- booleans) {
                val foo = w || x && y || z
                println(s"$w || $x && $y || $z = $foo")
            }
        }
    }
}
