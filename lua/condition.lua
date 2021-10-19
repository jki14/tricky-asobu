function func(foo)
    return foo
end

function func2(foo, bar)
    if not foo or (func(bar) and func(bar) >= foo) then
        print(tostring(bar) .. ' >= '.. tostring(foo) .. ' ? YES')
    else
        print(tostring(bar) .. ' >= '.. tostring(foo) .. ' ? NO')
    end
end

func2(nil, nil)
func2(4, nil)
func2(nil, 4)
func2(4, 4)
