def execute(a, b = "b", c: "c", d: "d")
    a.to_s + b.to_s + c.to_s + d.to_s
end

puts execute("A", "B", d: "D")
