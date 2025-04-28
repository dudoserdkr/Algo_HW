from collections import deque


class Graph:
    def __init__(self, n):
        self.adj_list = {vertex: [] for vertex in range(1, n + 1)}
        self.n = n

    def add_edge(self, u, v):
        def _add_edge(u, v):
            if v not in self.adj_list[u]:
                self.adj_list[u].append(v)
        _add_edge(u, v)
        _add_edge(v, u)

    def remove_edge(self, u, v):
        self.adj_list[u].remove(v)

    def modified_bfs(self, fire_sources):
        visited = {v: False for v in range(1, self.n + 1)}
        vertex_distances = [0] * self.n

        queue = deque()
        for fire_source in fire_sources:
            queue.append(
                (fire_source, 0)
            )

        while queue:
            curr_v, curr_d = queue.popleft()
            if not visited[curr_v]:
                visited[curr_v] = True
                vertex_distances[curr_v - 1] = curr_d
            else:
                continue
            for v in self.adj_list[curr_v]:
                if not visited[v]:
                    queue.append(
                        (v, curr_d + 1)
                    )
        return vertex_distances


if __name__ == '__main__':
    n, m = map(int, input().split())
    g = Graph(n)

    for _ in range(m):
        u, v = map(int, input().split())
        g.add_edge(u, v)

    k = int(input())
    fire_sources = list(map(int, input().split()))

    distances = g.modified_bfs(fire_sources)

    max_distance = 0
    max_index = 0
    for i in range(len(distances)):
        if distances[i] > max_distance:
            max_distance = distances[i]
            max_index = i

    print(max_distance)
    print(max_index + 1)