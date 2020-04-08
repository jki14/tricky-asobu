val nullx = None: Option[Long]
val nully = None: Option[Long]
var seven = None: Option[Long]

seven = Some(7)

println(7 + nullx.getOrElse(nully.getOrElse(seven.get)))
