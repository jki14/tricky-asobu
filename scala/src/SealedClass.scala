sealed class Request

final case class Delete(key: String) extends Request
final case class Insert(key: String, value: String) extends Request
final case class Select(key: String) extends Request
