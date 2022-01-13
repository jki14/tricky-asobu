case class Request(LhsPort: String, RhsPort: String, IpAddress: String, Protocol: String) {
    def isIPv4: Boolean = !IpAddress.contains(":")
}

def isMixedIpPair(mappings: Seq[Request]): Boolean =
    mappings match {
        case Seq(p, q) if p.isIPv4 != q.isIPv4 => true
        case _ => false
    }

def dedupe(groupped: Iterable[Seq[Request]]): Iterable[Request] =
    if (groupped.forall(s => {isMixedIpPair(s)})) {
        groupped.flatten.filter(_.isIPv4)
    } else {
        groupped.flatten
    }

val mappings = Seq(
    Request("80", "49155", "0.0.0.0", "tcp"),
    Request("80", "49155", "::", "tcp"),
    Request("8080", "49166", "0.0.0.0", "tcp"),
    Request("8080", "49166", "::", "tcp")
)

// val groupped: Map[(String, String, String), Seq[Request]] = mappings.groupBy(m => (m.LhsPort, m.RhsPort, m.Protocol))
val groupped = mappings.groupBy(m => (m.LhsPort, m.RhsPort, m.Protocol)).values
println(dedupe(groupped))

val mappingsBad = Seq(
    Request("80", "49155", "0.0.0.0", "tcp"),
    Request("80", "49155", "::", "tcp"),
    Request("8080", "49166", "0.0.0.0", "tcp")
)

println(dedupe(mappingsBad.groupBy(m => (m.LhsPort, m.RhsPort, m.Protocol)).values))

val foo = mappings.groupBy(m => (m.LhsPort, m.RhsPort, m.Protocol)).values match {
    case groupped if groupped.forall(s => s match {
            case Seq(p, q) if p.isIPv4 != q.isIPv4 => true
            case _ => false
        }) => groupped.flatten.filter(_.isIPv4)
    case groupped => groupped.flatten
}
println(foo)

val bar = mappingsBad.groupBy(m => (m.LhsPort, m.RhsPort, m.Protocol)).values match {
    case groupped if groupped.forall(s => s match {
            case Seq(p, q) if p.isIPv4 != q.isIPv4 => true
            case _ => false
        }) => groupped.flatten.filter(_.isIPv4)
    case groupped => groupped.flatten
}
println(bar)
