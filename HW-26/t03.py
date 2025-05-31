import heapq, math

class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for _ in range(n + 1)]
    def add(self, u, v, w):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))
    def mst_edges(self):
        n = self.n
        key = [math.inf] * (n + 1)
        parent = [-1] * (n + 1)
        seen = [False] * (n + 1)
        key[1] = 0
        heap = [(0, 1)]
        while heap:
            d, u = heapq.heappop(heap)
            if seen[u]:
                continue
            seen[u] = True
            for v, w in self.adj[u]:
                if not seen[v] and w < key[v]:
                    key[v] = w
                    parent[v] = u
                    heapq.heappush(heap, (w, v))
        s = set()
        for v in range(2, n + 1):
            u = parent[v]
            if u == -1:
                continue
            if u > v:
                u, v = v, u
            s.add((u, v))
        return s


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, m, p, q = map(int, input().split())
        g = Graph(n)
        for _ in range(m):
            u, v, w = map(int, input().split())
            g.add(u, v, w)
        mst = g.mst_edges()
        if p > q:
            p, q = q, p
        print('YES' if (p, q) in mst else 'NO')
