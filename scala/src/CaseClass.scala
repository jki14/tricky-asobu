case class CaseClass(key: String) {
    require(key != null)
}

val coolKey = CaseClass("cool")
val nullKey = CaseClass(null)
