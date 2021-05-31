function main()
    for k = 0, 26 do
        --[[
        local r = (k / 9) / 3.0
        local g = ((k % 9) / 3) / 3.0
        local b = (k % 3) / 3.0
        --]]
        local r = math.floor(k / 9) / 3.0
        local g = math.floor((k % 9) / 3) / 3.0
        local b = (k % 3) / 3.0
        r = math.floor(r * 255 + 0.5)
        g = math.floor(g * 255 + 0.5)
        b = math.floor(b * 255 + 0.5)
        local foo = string.format('(%d, %d, %d)', r, g, b)
        foo = foo .. string.rep(' ', 16 - string.len(foo))
        foo = foo .. '# ' .. tostring(k)
        print(foo)
    end
end

main()
