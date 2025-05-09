from functools import lru_cache


def d(a, b):
    dx = a[0] - b[0]
    dy = a[1] - b[1]
    return dx * dx + dy * dy

class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [1 << i for i in range(n)]
        self.full = (1 << n) - 1
        self.best_mask = self.full

    def add_edge(self, u, v):
        self.adj[u] |= 1 << v
        self.adj[v] |= 1 << u

    def init_order(self):
        self.order = sorted(
            range(self.n),
            key=lambda i: self.adj[i].bit_count(),
            reverse=True
        )

    def find_max(self):
        unc = self.full
        greedy = []
        while unc:
            best = max(
                range(self.n),
                key=lambda i: (self.adj[i] & unc).bit_count()
            )
            greedy.append(best)
            unc &= ~self.adj[best]
        best_list = greedy[:]
        max_deg = max(mask.bit_count() for mask in self.adj)
        chosen = [0] * self.n

        @lru_cache(None)
        def dfs(mask, depth):
            nonlocal best_list
            if depth >= len(best_list):
                return
            if mask == self.full:
                best_list = chosen[:depth]
                return
            rem = self.n - mask.bit_count()
            if depth + (rem + max_deg - 1) // max_deg >= len(best_list):
                return
            v = (self.full ^ mask).bit_length() - 1
            cand = [
                i for i in range(self.n)
                if self.adj[i] & (1 << v)
            ]
            cand.sort(
                key=lambda i: (self.adj[i] & ~mask).bit_count(),
                reverse=True
            )
            for i in cand:
                chosen[depth] = i
                dfs(mask | self.adj[i], depth + 1)

        dfs(0, 0)
        mask = 0
        for i in best_list:
            mask |= 1 << i
        self.best_mask = mask

    def bits(self):
        res = []
        for i in range(self.n):
            if self.best_mask & (1 << i):
                res.append(i)
        return res

if __name__ == "__main__":
    n, R = map(int, input().split())
    R2 = R * R
    villages = [
        tuple(map(int, input().split()))
        for _ in range(n)
    ]
    g = Graph(n)
    for i in range(n):
        for j in range(n):
            if i != j and d(villages[i], villages[j]) <= R2:
                g.add_edge(i, j)
    g.init_order()
    g.find_max()
    res = g.bits()
    res.sort()
    print(len(res))
    print(*(i + 1 for i in res))