def countOne(x):
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555)
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
    x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f)
    x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff)
    x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff)
    return x

def getNext(x):
    lowbit = x & (-x)
    fund = x + lowbit
    sup = ((fund ^ x) >> 2) / lowbit
    return fund | sup

def getPrev(x):
    v = ~x
    v = getNext(v)
    return ~v

def main():
    grouped = [[] for i in xrange(30)]
    for i in xrange(10**6):
        cnt = countOne(i)
        grouped[cnt].append(i)
    for row in grouped[1:]:
        length = len(row)
        if length==0:
            continue
        for i in xrange(length-1):
            if getNext(row[i])!=row[i+1]:
                print 'Error getNext(%d)' % (row[i])
            if getPrev(row[i+1])!=row[i]:
                print 'Error getPrev(%d)' % (row[i+1])

if __name__ == '__main__':
    main()
