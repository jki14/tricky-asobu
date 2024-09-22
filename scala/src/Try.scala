import scala.util.Try

object Try {
    def strLen(s: String): Try[Long] = Try {
        s.length.toLong
    }

    def getConfigLen(configRaw: Option[String]): Option[Long] =
        for {
            config <- configRaw
            len <- strLen(config).toOption
        } yield len

    def main(args: Array[String]): Unit = {
        val configRawSome: Option[String] = Some("configured")
        println(configRawSome)
        println(getConfigLen(configRawSome))

        val configRawNull: Option[String] = Some(null)
        println(configRawNull)
        println(getConfigLen(configRawNull))

        val configRawNone: Option[String] = None
        println(configRawNone)
        println(getConfigLen(configRawNone))
    }
}
