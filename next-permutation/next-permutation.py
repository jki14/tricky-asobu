def next_permutation(arr):
    for k in xrange(len(arr)-2, -1, -1):
        if arr[k]<arr[k+1]:
            i = len(arr)-1
            while arr[i]<=arr[k]:
                i -= 1
            arr[k], arr[i] = arr[i], arr[k]
            arr[k+1:] = arr[k+1:][::-1]
            return True
    return False

def main():
    arr = [1, 2, 2, 3, 4]
    while True:
        print arr
        if not next_permutation(arr):
            break

if __name__ == '__main__':
    main()
