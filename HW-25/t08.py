import sys


class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = []

    def add_edge(self, u, v, w):
        self.edges.append((u - 1, v - 1, w))

    def bellman_ford(self, start):
        INF = 30000
        dist = [INF] * self.n
        dist[start - 1] = 0
        for _ in range(self.n - 1):
            updated = False
            for u, v, w in self.edges:
                if dist[u] != INF and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    updated = True
            if not updated:
                break
        return dist


def main():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    n = int(data[0])
    m = int(data[1])
    g = Graph(n)
    i = 2
    for _ in range(m):
        g.add_edge(int(data[i]), int(data[i + 1]), int(data[i + 2]))
        i += 3
    print(*g.bellman_ford(1))


if __name__ == '__main__':
    main()
