import heapq, math

class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for _ in range(n + 1)]
    def add(self, u, v, w):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))
    def prim(self, allowed):
        start = next((i for i in range(1, self.n + 1) if allowed[i]), None)
        if start is None:
            return -1
        key = [math.inf] * (self.n + 1)
        seen = [False] * (self.n + 1)
        key[start] = 0
        pq = [(0, start)]
        cost = visited = 0
        need = sum(allowed[1:])
        while pq:
            d, u = heapq.heappop(pq)
            if seen[u]:
                continue
            seen[u] = True
            cost += d
            visited += 1
            for v, w in self.adj[u]:
                if allowed[v] and not seen[v] and w < key[v]:
                    key[v] = w
                    heapq.heappush(pq, (w, v))
        return cost if visited == need else -1

def read_ints_nonempty():
    while True:
        s = input()
        if s.strip():
            return list(map(int, s.split()))

def main():
    n, m, p = map(int, read_ints_nonempty())
    bad = [0] * (n + 1)
    if p:
        for x in read_ints_nonempty():
            bad[x] = 1

    g = Graph(n)
    link = [math.inf] * (n + 1)

    read_edges = 0
    while read_edges < m:
        vals = read_ints_nonempty()
        if len(vals) < 3:
            continue
        x, y, l = vals
        g.add(x, y, l)
        if bad[x] ^ bad[y]:
            if bad[x]:
                link[x] = min(link[x], l)
            else:
                link[y] = min(link[y], l)
        read_edges += 1

    safe = [not b for b in bad]
    safe_cnt = sum(safe[1:])

    if p == 0:
        res = g.prim(safe)
        print(res if res >= 0 else 'impossible')
        return

    if safe_cnt == 0:
        if n == 1:
            print(0)
            return
        if n == 2:
            c = math.inf
            for v, w in g.adj[1]:
                if v == 2:
                    c = min(c, w)
            print(c if c < math.inf else 'impossible')
            return
        print('impossible')
        return

    core = g.prim(safe)
    if core < 0:
        print('impossible')
        return

    total = core
    for i in range(1, n + 1):
        if bad[i]:
            if link[i] == math.inf:
                print('impossible')
                return
            total += link[i]

    print(total)

if __name__ == '__main__':
    main()
