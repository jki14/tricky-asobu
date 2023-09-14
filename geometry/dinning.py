from numpy import cos, radians, sin, tan
from sys import stderr, stdout


R = 0.01
W = 800
H = 600


def buildhex(x):
    h = x * cos(radians(30))
    foo = [(W * 0.5, h + H), (W * 0.5, h), (x * 0.5, h)]
    foo = foo + [(x, 0)] + [(p[0], -p[1]) for p in foo]
    foo = foo + [(-p[0], p[1]) for p in foo]
    foo = foo + [(0, h), (0, h + H)]
    return foo


def buildoct(x):
    h = x * tan(radians(67.5)) * 0.5
    foo = [(x * 0.5, h), (h, x * 0.5), (W * 0.5, h + H), (W * 0.5, h)]
    foo = foo + foo + [(p[0], -p[1]) for p in foo]
    foo = foo + [(-p[0], p[1]) for p in foo]
    return foo


def rotate(s, r):
    return [(cos(r) * p[0] - sin(r) * p[1], sin(r) * p[0] + cos(r) * p[1]) for p in s]


def check(x, d, w = 3020, h = 3340):
    points = rotate(buildhex(x), radians(d))
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]
    return max(xs) - min(xs) < w and max(ys) - min(ys) < h


def binary_search(d, hig = 4096):
    lef, rig = -hig, 0
    while lef < rig - 1e-6:
        mid = (lef + rig) / 2
        if check(-mid, d):
            rig = mid
        else:
            lef = mid + 1e-2
    return -rig


def main():
    buf = [binary_search(d * R) for d in range(round(90 / R))]
    top = max(buf)
    stdout.write('Best: clockwise %.6f degrees, get a = %6f.\n' % (buf.index(top) * R, top))
    '''
    for i in range(len(buf)):
        if round(i * R) % 5 == 0:
            stderr.write('%d -> %6f\n' % (i * R, buf[i]))
    '''
    candidates = rotate(buildhex(top), radians(-buf.index(top) * R))
    candidates = candidates + [(-1510, -1670)]
    dx, dy = 1510, 1670
    # dx = max([p[0] for p in candidates])
    # dy = max([p[1] for p in candidates])
    for p in candidates:
        stderr.write('%.6f, %.6f\n' % (p[0] - dx, p[1] - dy))
        # stderr.write('%d, %d\n' % (round(p[0] - dx), round(p[1] - dy)))
    stderr.flush()

    hexagon = lambda x: x * x * sin(radians(60)) * 3
    stderr.write('hexagon size: %.6f\n' % hexagon(top))
    # octagon = lambda x: x * x * tan(radians(67.5)) * 2
    # stderr.write('octagon size: %.6f\n' % octagon(top))


if __name__ == '__main__':
    main()
