c = 'print(\'Hello World\')'

loadstring(c)()

c = load(c)
c()

p = 'print(...)'
loadstring(p)('Hello World')
