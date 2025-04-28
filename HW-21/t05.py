n = int(input())

count = 0
for _ in range(n):
    row = [int(d) for d in input().split()]

    if sum(row) == 1:
        count += 1

print(count)