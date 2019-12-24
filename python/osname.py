import os

def main():
    print(os.name)
    try:
        input()
    except SyntaxError:
        pass

if __name__ == '__main__':
    main()
