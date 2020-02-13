def solution(foo, bar):
    f = lambda foo, bar, p = 0: (str(bar) if '.' in str(bar) else str(bar) + '.') \
        if p == len(foo) else f(foo, bar[foo[p]], p + 1)
    return f(foo, bar)

def main():
    foo = ['x', 'y', 'z']
    bar = {'x': {'y': {'z': 14}}}
    print(solution(foo, bar))

if __name__ == '__main__':
    main()
