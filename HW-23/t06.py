import sys

sys.setrecursionlimit(10 ** 7)  # Інакше у тесті 19 рантайм ерор.


class Graph:
    def __init__(self, n):
        self.adj_list = {vertex: [] for vertex in range(1, n + 1)}
        self.n = n

    def add_edge(self, u, v):
        if v not in self.adj_list[u]:
            self.adj_list[u].append(v)

    def topological_sort(self):
        state = [0] * (self.n + 1)
        result = []
        has_cycle = [False]

        def _dfs(v):
            if has_cycle[0]:
                return
            state[v] = 1
            for neighbour in self.adj_list[v]:
                if state[neighbour] == 0:
                    _dfs(neighbour)
                elif state[neighbour] == 1:
                    has_cycle[0] = True
                    return
            state[v] = 2
            result.append(v)

        for i in range(1, self.n + 1):
            if state[i] == 0:
                _dfs(i)
                if has_cycle[0]:
                    return [-1]
        return result[::-1]


if __name__ == "__main__":
    n, m = map(int, input().split())
    g = Graph(n)
    for _ in range(m):
        u, v = map(int, input().split())
        g.add_edge(u, v)

    result = g.topological_sort()
    print(*result)