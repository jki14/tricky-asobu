math.randomseed(os.time())

local foo = tonumber('1' .. string.format('%09d', math.random(100000000, 129999999)))
local bar = string.format('%09d', math.random(1, 99))

print('foo = ' .. foo)
print('bar = ' .. bar)
