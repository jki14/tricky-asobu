import time

def main():
    foo = '2019-12-04 21:10:03'
    foo = time.strptime(foo, '%Y-%m-%d %H:%M:%S')
    foo = time.mktime(foo)
    bar = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(foo))
    print(bar)

if __name__ == '__main__':
    main()
