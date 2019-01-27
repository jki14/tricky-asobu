from math import log

def trie_worst_space(c, n, l, s):
    if c == 0:
        return -1
    if s == 0:
        if l == 0:
            return -1
        if n == 0:
            return c ** l
        foo = 0
        cur = n
        for level in xrange(l, -1, -1):
            if log(cur * 1.0) / log(c * 1.0) > level - 1.0:
                cur = min(cur, c ** level)
            foo += cur
        return foo
    else:
        foo = 1
        cur = 1
        for level in xrange(1, l + 1):
            cur = cur * c
            if n > 0:
                cur = min(cur, n)
            foo += cur
            if foo > s:
                return s
        return foo

def main():
    while True:
        try:
            c, n, l, s = [int(i) for i in raw_input('c, n, l, s\n').strip().split()]
            print(trie_worst_space(c, n, l ,s))
        except (EOFError, TypeError, ValueError):
            break

if __name__ == '__main__':
    main()
