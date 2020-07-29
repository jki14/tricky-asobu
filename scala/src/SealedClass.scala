sealed class Request

final case class Delete(key: String) extends Request
final case class Insert(key: String, value: String) extends Request
final case class Select(key: String) extends Request

val request: Request = Insert("key", "value")
request match {
    case Delete(key) => println(s"- $key")
    case Insert(key, _) => println(s"+ $key")
    case _ => println("Not Implemented")
}
