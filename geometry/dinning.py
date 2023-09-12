from numpy import cos, radians, sin
from sys import stderr, stdout


def buildlist(x):
    h = x * cos(radians(30))
    y = x * 0.5
    foo = [(400, h + 600), (400, h), (x * 0.5, h)]
    foo = foo + [(x, 0)] + [(p[0], -p[1]) for p in foo]
    foo = foo + [(-p[0], p[1]) for p in foo]
    return foo


def rotate(s, r):
    return [(cos(r) * p[0] - sin(r) * p[1], sin(r) * p[0] + cos(r) * p[1]) for p in s]


def check(x, d, w = 3020, h = 3340):
    points = rotate(buildlist(x), radians(d))
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]
    return max(xs) - min(xs) <= w and max(ys) - min(ys) <= h


def binary_search(d, hig = 4096):
    lef, rig = -hig, 0
    while lef < rig:
        mid = (lef + rig) // 2
        if check(-mid, d):
            rig = mid
        else:
            lef = mid + 1
    return -rig


def main():
    buf = [binary_search(d) for d in range(180)]
    top = max(buf)
    stdout.write('Best: clockwise %d degrees, get a = %d.\n' % (buf.index(top), top))
    for i in range(len(buf)):
        if i % 5 == 0:
            stderr.write('%d -> %d\n' % (i, buf[i]))


if __name__ == '__main__':
    main()
