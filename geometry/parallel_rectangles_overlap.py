class Point2d:
    def __init__(self, x = 0, y = 0):
        if isinstance(x, (int, long, float)) and isinstance(y, (int, long, float)):
            self.x = x
            self.y = y
        else:
            raise ValueError

class Rectangle2d:
    def __init__(self, *args):
        if len(args)==2 and isinstance(args[0], Point2d) and isinstance(args[1], Point2d):
            self.bottomLeft = args[0]
            self.topRight = args[1]
            if self.bottomLeft.x>self.topRight.x or self.bottomLeft.y>self.topRight.y:
                raise ValueError
        elif len(args)==4 and isinstance(args[0], (int, long, float)) and isinstance(args[1], (int, long, float)) and isinstance(args[2], (int, long, float)) and isinstance(args[3], (int, long, float)):
            self.bottomLeft = Point2d(min(args[0], args[2]), min(args[1], args[3]))
            self.topRight = Point2d(max(args[0], args[2]), max(args[1], args[3]))
        else:
            raise ValueError

def overlaped(lhs, rhs):
    if isinstance(lhs, Rectangle2d) and isinstance(rhs, Rectangle2d):
        if lhs.bottomLeft.x>=rhs.topRight.x or lhs.bottomLeft.y>=rhs.topRight.y:
            return False
        if lhs.topRight.x<=rhs.bottomLeft.x or lhs.topRight.y<=rhs.bottomLeft.y:
            return False
        return True
    else:
        raise ValueError

def main():
    print overlaped(Rectangle2d(1, 3, 4, 1), Rectangle2d(2, 2, 3, 0))
    print overlaped(Rectangle2d(1, 3, 2, 1), Rectangle2d(2, 2, 3, 0))

if __name__ == '__main__':
    main()
