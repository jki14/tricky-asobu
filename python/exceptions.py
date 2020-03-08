def solution():
    good = 1024
    sent = 0
    r = 3.14
    try:
        r = good / float(sent)
    except (ZeroDivisionError, ValueError):
        pass
    print(r)


def constructed_error():
    raise ValueError('Test Error Message.')


def default_error():
    foo = int('32x1')


def main():
    solution()
    try:
        default_error()
    except ValueError as e:
        print(str(e))
    try:
        constructed_error()
    except ValueError as e:
        print(str(e))



if __name__ == '__main__':
    main()
