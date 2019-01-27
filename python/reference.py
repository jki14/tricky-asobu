def update(arr, x):
    arr[-1] = -1
    x -= 1

def main():
    arr = [0 for i in xrange(8)]
    x = 8
    update(arr, x)
    print arr
    print x

if __name__ == '__main__':
    main()
