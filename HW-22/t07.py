from collections import deque


class Graph:
    def __init__(self, n):
        self.adj_list = {vertex: [] for vertex in range(1, n + 1)}
        self.n = n

    def add_edge(self, u, v):
        if v not in self.adj_list[u]:
            self.adj_list[u].append(v)

    def remove_edge(self, u, v):
        self.adj_list[u].remove(v)

    def modified_bfs(self, start):
        visited = {v: False for v in range(1, self.n + 1)}
        vertex_distances = [-1] * self.n
        queue = deque()
        queue.append(
            (start, 0)
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
    n, start = map(int, input().split())
    g = Graph(n)

    for i in range(1, n + 1):
        row = list(map(int, input().split()))
        for j in range(0, n):
            if row[j] == 1:
                g.add_edge(i, j + 1)

    distances = g.modified_bfs(start)
    print(*distances)