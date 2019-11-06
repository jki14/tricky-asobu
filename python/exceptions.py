def solution():
    good = 1024
    sent = 0
    r = 3.14
    try:
        r = good / float(sent)
    except (ZeroDivisionError, ValueError):
        pass
    print(r)

def main():
    solution()
    
if __name__ == '__main__':
    main()
