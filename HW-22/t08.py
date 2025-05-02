from collections import deque


class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_vertex(self, u):
        if u not in self.adj_list:
            self.adj_list[u] = []

    def add_edge(self, u, v):
        if u == v:
            return
        self.add_vertex(u)
        self.add_vertex(v)
        def _add_edge(u, v):
            if v not in self.adj_list[u]:
                self.adj_list[u].append(v)
        _add_edge(u, v)
        _add_edge(v, u)

    def bfs(self, start, finish):
        visited = {v: False for v in self.adj_list.keys()}
        parent = {v: None for v in self.adj_list.keys()}

        queue = deque()
        queue.append(
            start
        )
        visited[start] = True

        while queue:
            curr_v = queue.popleft()

            for v in self.adj_list[curr_v]:
                if not visited[v]:
                    visited[v] = True
                    queue.append(v)
                    parent[v] = curr_v
                    if v == finish:
                        return parent

        return None

    def rebuild_path(self, start, finish):
        parent = self.bfs(start, finish)
        if parent is None:
            print(-1)
            return

        path = []

        current = finish
        while current is not None:
            path.append(current)
            current = parent[current]

        path.reverse()

        for v in path:
            print(v)


class NumberEditor:
    @staticmethod
    def increase_first_digit(n: int) -> int:
        if n < 9000:
            return n + 1000
        return n

    @staticmethod
    def decrease_last_digit(n: int) -> int:
        if n % 10 != 1:
            return n - 1
        return n

    @staticmethod
    def move_right(n: int) -> int:
        return (n % 10) * 1000 + (n // 10)

    @staticmethod
    def move_left(n: int) -> int:
        return (n % 1000) * 10 + (n // 1000)

    @staticmethod
    def methods():
        return [
            NumberEditor.increase_first_digit,
            NumberEditor.decrease_last_digit,
            NumberEditor.move_left,
            NumberEditor.move_right
        ]


class VertexGenerator:
    def __init__(self, graph, start, finish):
        self.graph = graph
        self.start = start
        self.finish = finish
        self.visited = set()


    def generate_numbers(self, start):
        queue = deque()
        queue.append(start)
        visited = set()
        visited.add(start)

        while queue:
            n = queue.popleft()
            for method in NumberEditor.methods():
                new_n = method(n)
                if new_n not in visited:
                    visited.add(new_n)
                    self.graph.add_edge(n, new_n)
                    queue.append(new_n)


if __name__ == '__main__':
    start = int(input())
    finish = int(input())
    g = Graph()
    vg = VertexGenerator(g, start, finish)
    vg.generate_numbers(start)

    g.rebuild_path(start, finish)