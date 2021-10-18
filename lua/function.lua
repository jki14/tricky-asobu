function func(x, y, z)
    print('x = ' .. tostring(x))
    print('y = ' .. tostring(y))
    print('z = ' .. tostring(z))
    print('\n')
end

--[[
function func(x)
    print('x = ' .. tostring(x))
    print('\n')
end
]]--

func(1, 2, 3)
func(1, 2)
func(1)
