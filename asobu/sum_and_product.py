def check():
    d = {}
    for x in xrange(1, 10000):
        for y in xrange(x, 10000):
            s = x + y
            p = x * y
            if s not in d:
                d[s] = {}
            if p not in d[s]:
                d[s][p] = (x, y)
            else:
                print 'Error about (%d, %d) (%d, %d)' % (x, y, d[s][p][0], d[s][p][1])

def main():
    check()

if __name__ == '__main__':
    main()
