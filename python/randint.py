from random import randint

def call(n = 1):
    for i in xrange(n):
        print(randint(0, 15))

def main():
    call(32)

if __name__ == '__main__':
    main()
