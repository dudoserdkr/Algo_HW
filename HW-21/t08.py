arr = []
n, m = [int(d) for d in input().split()]

for _ in range(m):
    a, b = [int(d) for d in input().split()]
    arr.append([a,b])

is_multi = False
new_arr = []

for a in arr:
    if a in new_arr:
        is_multi = True
        break
    else:
        new_arr.append(a)

if is_multi:
    print("YES")
else:
    print("NO")