val ipRx = """\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}""".r

println(ipRx.pattern.matcher("0.0.0.0").matches())
println(ipRx.pattern.matcher("::").matches())
