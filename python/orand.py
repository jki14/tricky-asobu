from sys import stdout

for x in [True, False]:
    for y in [True, False]:
        for z in [True, False]:
            foo = x or y and z
            stdout.write('%s or %s and %s = %s\n' % (str(x), str(y), str(z), str(foo)))
