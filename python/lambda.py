def solution(foo, bar):
    f = lambda foo, bar : (str(bar) if '.' in str(bar) else str(bar) + '.') \
        if not foo else f(foo[1:], bar[foo[0]])
    return f(foo, bar)

def main():
    foo = ['x', 'y', 'z']
    bar = {'x': {'y': {'z': 14}}}
    print(solution(foo, bar))

if __name__ == '__main__':
    main()
