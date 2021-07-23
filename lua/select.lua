function foo()
    return 'a', 'b', 'c', 'd', 'e'
end

local bar, r = select(2, foo())
print(bar)
print(r)
