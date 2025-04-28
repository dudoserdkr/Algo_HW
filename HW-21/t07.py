n,m = [int(d) for d in input().split()]

arr = [0 for _ in range(n)]

for _ in range(m):
    a, b = [int(d) for d in input().split()]
    arr[a-1] += 1
    arr[b-1] += 1

for i in arr:
    print(i)