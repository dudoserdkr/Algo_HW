

if __name__ == '__main__':
    a = int(input())
    b = int(input())

    arr = []

    while (a > 0):
        arr.append(a % b)
        a //= b

    for i in range(len(arr) - 1, -1, -1):
        digit = arr[i]

        if digit > 9:
            print(f"[{digit}]", end="")
        else:
            print(digit, end="")