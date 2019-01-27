class InverseFunction:
    
    def __init__(self):
        self.func = None

    def set_function(self, func):
        self.func = func

    def forward_exec(self, x):
        return self.func(x)

    def backward_exec(self, y):
        rig = 0
        while (self.func(rig) < y):
            rig = rig * 2 + 1
        lef = rig / 2 + 1
        while lef < rig:
            mid = (lef + rig) / 2
            if self.func(mid) >= y:
                rig = mid
            else:
                lef = mid + 1
        if lef == 0 or self.func(lef) - y < y - self.func(lef - 1):
            return lef
        else:
            return lef - 1

def square(x):
    return x * x

def main():
    inverseFunction = InverseFunction()
    inverseFunction.set_function(square)
    print inverseFunction.forward_exec(2)
    print inverseFunction.backward_exec(10)

if __name__ == '__main__':
    main()
