from copy import deepcopy


class Graph:
    def __init__(self, n):
        self.n = n  # Vertex count
        self.adj_list = {Vertex: [] for Vertex in range(1, self.n + 1)}
        self.edges = []

    def add_edge(self, u, v):
        self.edges.append((u, v))
        def _add_edge(u, v):
            self.adj_list[u].append(v)
        _add_edge(u, v)
        _add_edge(v, u)

    def remove_edge(self, edges_to_be_removed):
        adj_list = deepcopy(self.adj_list)
        for edge in edges_to_be_removed:
            u, v = self.edges[edge - 1]
            def _remove_edge(u, v):
                adj_list[u].remove(v)
            _remove_edge(u, v)
            _remove_edge(v, u)
        return self.dfs(adj_list, self.n)


    @staticmethod
    def dfs(adj_list, vertex_count):
        visited = set()
        def _dfs(vertex):
            visited.add(vertex)
            for neighbour in adj_list[vertex]:
                if neighbour not in visited:
                    _dfs(neighbour)
        _dfs(1)
        return len(visited) == vertex_count


if __name__ == '__main__':
    with open("input.txt", "r", encoding="utf-8") as file:
        N, M = map(int, file.readline().strip().split())
        g = Graph(N)

        for _ in range(M):
            a, b = map(int, file.readline().strip().split())
            g.add_edge(a, b)

        K = int(file.readline().strip())

        for _ in range(K):
            C = list(map(int, file.readline().strip().split()))
            is_connected = g.remove_edge(C[1:])
            if is_connected:
                print("Connected")
            else:
                print("Disconnected")