from collections import deque


class Node:
    def __init__(self, bribe):
        self.bribe = bribe


class Tree(Node):
    def __init__(self, bribe):
        super().__init__(bribe)
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    @staticmethod
    def bfs(node):
        queue = deque()
        queue.append((node, node.bribe))
        min_bribe = float('inf')
        while queue:
            node, bribe_sum = queue.popleft()
            if node.children:
                for child in node.children:
                    queue.append((child, bribe_sum + child.bribe))
            else:
                if min_bribe > bribe_sum:
                    min_bribe = bribe_sum

        return min_bribe


if __name__ == '__main__':
    n = int(input())
    officials = []
    for i in range(n):
        row = list(map(int, input().split()))
        bribe, K = row[0], row[2::]
        officials.append((Tree(bribe), K))

    for (tree, K) in officials:
        if K:
            for i in K:
                tree.add_child(officials[i-1][0])

    root = officials[0][0]
    print(Tree.bfs(root))