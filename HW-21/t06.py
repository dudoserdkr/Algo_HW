n, m = [int(d) for d in input().split()]

graph = {}
for i in range(1, n + 1):
    graph[i] = [0, 0]

for _ in range(m):
    left, right = [int(d) for d in input().split()]

    graph[left] = [1 + graph[left][0], graph[left][1]]
    graph[right] = [graph[right][0], 1 + graph[right][1]]

for i in range(1, n + 1):
    i, j = graph[i][::-1]
    print(i, j)