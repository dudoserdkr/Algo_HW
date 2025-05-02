class Node:
    def __init__(self, color, index):
        self.children = []
        self.colors = set()
        self.color = color
        self.index = index

    def add_children(self, node):
        self.children.append(node)

    def set_info(self, color, idx):
        self.color = color
        self.index = idx


class Tree:
    def __init__(self, n):
        self.nodes = [None] * (n + 1)
        self.root = None
        self.result = [0] * (n + 1)

    def add_node(self, idx, parent_idx, color):
        if self.nodes[idx] is None:
            self.nodes[idx] = Node(color, idx)
        else:
            self.nodes[idx].set_info(color, idx)

        if parent_idx == 0:
            self.root = self.nodes[idx]
        else:
            if self.nodes[parent_idx] is None:
                self.nodes[parent_idx] = Node(0, parent_idx)
            self.nodes[parent_idx].add_children(self.nodes[idx])

    def _dfs(self, node):
        color_set = {node.color}
        for child in node.children:
            color_set |= self._dfs(child)
        self.result[node.index] = len(color_set)
        return color_set

    def calc_result(self):
        if self.root:
            self._dfs(self.root)
        print(*self.result[1::])


if __name__ == '__main__':
    n = int(input())
    tree = Tree(n)
    for i in range(1, n + 1):
        p, c = map(int, input().split())
        tree.add_node(i, p, c)
    tree.calc_result()