from numpy import cos, floor, int64, radians, sin, tan
from sys import stderr, stdout


R = 1
W = 3000
H = 3300
W2 = 1100
H2 = 600
D = 90
E = 200
P = 1


def buildhex(x, dd = 0.0):
    h = x * cos(radians(30))
    foo = [(x * 0.5, h)]
    foo = foo + [(x, 0)] + [(p[0], -p[1]) for p in foo]
    foo = foo + [(-p[0], p[1]) for p in foo]
    foo = foo + [(W2 * 0.5 + dd, h + H2), (W2 * 0.5 + dd, h)]
    foo = foo + [(-W2 * 0.5 + dd, h + H2), (-W2 * 0.5 + dd, h)]
    return foo


def buildoct(x):
    h = x * tan(radians(67.5)) * 0.5
    foo = [(x * 0.5, h), (h, x * 0.5), (W2 * 0.5, h + H2), (W2 * 0.5, h)]
    foo = foo + foo + [(p[0], -p[1]) for p in foo]
    foo = foo + [(-p[0], p[1]) for p in foo]
    return foo


def rotate(s, r):
    return [(cos(r) * p[0] - sin(r) * p[1], sin(r) * p[0] + cos(r) * p[1]) for p in s]


def translate(s, dx, dy):
    return [(p[0] + dx, p[1] + dy) for p in s]


def check(x, d, dd = 0.0, getres = False):
    points = rotate(buildhex(x), radians(d))
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]
    if max(xs) - min(xs) > W or max(ys) - min(ys) > H:
        return False
    dx = max(max(xs) - W * 0.5, -min(xs) - W * 0.5, 0)
    dy = max(max(ys) - H * 0.5, -min(ys) - H * 0.5, 0)
    if dx > E or dy > E:
        return False
    if getres:
        return translate(points, dx, dy)
    else:
        return True


def checkdd(x, d, getres = False):
    for i in range(int64(floor((x - W2 + 1e-14)) * 0.5 / P) + 1):
        dd = i * P
        tmp = check(x, d, -i * P, getres)
        if tmp != False:
            return tmp
        tmp = check(x, d, i * P, getres)
        if tmp != False:
            return tmp
    return False


def binary_search(d, hig = 4096):
    lef, rig = -hig, -W2
    while lef < rig - 1e-6:
        mid = (lef + rig) / 2
        if checkdd(-mid, d):
            rig = mid
        else:
            lef = mid + 1e-2
    stderr.write('done for %.6f degrees.\n' % d)
    return -rig


def main():
    buf = [binary_search(d * R) for d in range(round(D / R))]
    top = max(buf)
    stdout.write('Best: clockwise %.6f degrees, get a = %6f.\n' % (buf.index(top) * R, top))
    '''
    for i in range(len(buf)):
        if round(i * R) % 5 == 0:
            stderr.write('%d -> %6f\n' % (i * R, buf[i]))
    '''
    # candidates = rotate(buildhex(top), radians(-buf.index(top) * R))
    candidates = checkdd(top, -buf.index(top) * R, True)
    # candidates = candidates + [(-W * 0.5, -H * 0.5)]
    # dx, dy = -W * 0.5, -H * 0.5
    # dx = max([p[0] for p in candidates])
    # dy = max([p[1] for p in candidates])
    dx, dy = 0, 0
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
