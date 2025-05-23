import heapq
from typing import List, Tuple


class Graph:
    def __init__(self, n: int):
        self.adj_list = {v: [] for v in range(1, n + 1)}
        self.n = n

    def add_edge(self, u: int, v: int, w: int) -> None:
        self.adj_list[u].append((v, w))

    def dijkstra(self, start: int, finish: int) -> int:
        INF = float('inf')
        distances: List[float] = [INF] * self.n
        distances[start - 1] = 0

        pq: List[Tuple[int, int]] = []
        heapq.heappush(pq, (0, start))

        while pq:
            curr_d, u = heapq.heappop(pq)
            if curr_d > distances[u - 1]:
                continue
            if u == finish:
                break
            for v, w in self.adj_list[u]:
                if distances[u - 1] + w < distances[v - 1]:
                    distances[v - 1] = distances[u - 1] + w
                    heapq.heappush(pq, (distances[v - 1], v))

        return -1 if distances[finish - 1] == INF else int(distances[finish - 1])


if __name__ == '__main__':
    n, s, f = map(int, input().split())
    g = Graph(n)

    for i in range(1, n + 1):
        row = list(map(int, input().split()))
        for j, w in enumerate(row, start=1):
            if w != -1 and i != j:
                g.add_edge(i, j, w)

    answer = g.dijkstra(s, f)
    print(answer)
