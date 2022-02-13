local d = {
    [1] = 'one',
    [2] = 'two',
}
d[3] = 'three'

for k, v in pairs(d) do
    print(k .. ' => ' .. v)
end
