function calc(bracket, rating)
  if(rating == nil or rating == 0 or rating == '') then
    return ''
  end
  local result = 0
  result = 356 + (1157/(1+(1675*2.71828^(-0.00412*rating))))
  if bracket == "2v2" then
    result = result * 0.76
  elseif bracket == "3v3" then
    result = result * 0.88
  else
    result = result
  end
  return math.floor( result + 0.5)
end

print(calc('5v5', 2300))
print(calc('3v3', 2300))
print(calc('2v2', 2300))
