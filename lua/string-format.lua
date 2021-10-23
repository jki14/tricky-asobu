foo = '[raid%d][arena%d]'
bar = string.gsub(foo, '%%d', tostring(4))
print(bar)
