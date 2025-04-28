from collections import deque


class Graph:
    def __init__(self, n):
        self.adj_list = {vertex: [] for vertex in range(1, n + 1)}

    def add_edge(self, u, v):
        if v not in self.adj_list[u]:
            self.adj_list[u].append(v)

    def remove_edge(self, u, v):
        self.adj_list[u].remove(v)

    def modified_bfs(self, start, finish, max_len):
        count = 0

        queue = deque()
        queue.append(
            ([], start, 0)
        )
        while queue:
            visited_vertexes, curr_v, curr_len = queue.popleft()

            if curr_len <= max_len and curr_v == finish:
                count += 1
                continue

            elif curr_len == max_len and curr_v != finish:
                continue

            for v in self.adj_list[curr_v]:
                if v not in visited_vertexes:
                    queue.append(
                        (visited_vertexes + [curr_v], v, curr_len + 1)
                    )

        return count


if __name__ == '__main__':
    n, k, a, b, d = [int(d) for d in input().split()]
    g = Graph(n)

    for _ in range(k):
        u, v = map(int, input().split())
        g.add_edge(u, v)

    count = g.modified_bfs(a, b, d)
    print(count)