class Graph:
    def __init__(self, n):
        self.adj_list = {Vertex: [] for Vertex in range(1, n + 1)}
        self.n = n

    def add_edge(self, u, v):
        def _add_edge(u, v):
            if v not in self.adj_list[u]:
                self.adj_list[u].append(v)

        _add_edge(u, v)
        _add_edge(v, u)

    def _dfs(self, start, visited):
        component = []
        stack = [start]

        while stack:
            vertex = stack.pop()
            if vertex not in visited:
                visited.add(vertex)
                component.append(vertex)
                for neighbour in self.adj_list[vertex]:
                    if neighbour not in visited:
                        stack.append(neighbour)
        return component

    def find_connected_components(self):
        visited = set()
        connected_components = []

        for vertex in range(1, self.n + 1):
            if vertex not in visited:
                component = self._dfs(vertex, visited=visited)
                connected_components.append(component)
        return connected_components


if __name__ == "__main__":
    n, m = map(int, input().split())
    graph = Graph(n)

    for _ in range(m):
        u, v = map(int, input().split())
        graph.add_edge(u, v)

    components = graph.find_connected_components()
    print(len(components))
    for component in components:
        print(len(component))
        print(" ".join(map(str, component)))
