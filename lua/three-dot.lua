function f(a, b, ...)
    print('---')
    print(a or 'nil')
    print(b or 'nil')
    -- foo = table.pack(...)
    foo = {...}
    bar = '['
    for i = 1, #foo do
        if string.len(bar) > 1 then
            bar = bar .. ', '
        end
        bar = bar .. foo[i] or 'nil'
    end
    bar = bar .. ']'
    print('select(1, ...) = ' .. (select(1, ...) or 'nil'))
    print(bar)
end

f('a')
f('a', 'b')
f('a', 'b', 'c')
f('a', 'b', 'c', 'd')
