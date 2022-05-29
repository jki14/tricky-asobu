local foo = '[raid%d][arena%d]'
local bar = string.gsub(foo, '%%d', tostring(4))
print(bar)

function sfind(s)
    local p = '^nameplate'
    if string.find(s, p) then
        print(s .. ' true')
    else
        print(s .. ' false')
    end
end

foo = 'nameplate14'
bar = 'xnameplate14'
sfind(foo)
sfind(bar)
