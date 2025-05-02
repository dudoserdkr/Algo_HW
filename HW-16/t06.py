from collections import deque

class Node:
    def __init__(self, info=None):
        self.info = info

    def empty(self):
        return self.info is None

class Tree(Node):
    def __init__(self, info):
        super().__init__(info)
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def dfs(self):
        def _dfs(node, isFirstPlayersTurn):
            if type(node) == Node:
                return node.info
            if isFirstPlayersTurn:
                max_result = float("-inf")
                for child in node.children:
                    result = _dfs(child, not isFirstPlayersTurn)
                    max_result = max(result, max_result)
                return max_result
            else:
                min_result = float('inf')
                for child in node.children:
                    result = _dfs(child, not isFirstPlayersTurn)
                    min_result = min(result, min_result)
                return min_result

        return _dfs(self, True)


if __name__ == '__main__':
    N = int(input())
    trees = [None] * (N)
    trees[0] = Tree(None)
    for i in range(1, N):
        row = input().split()
        NL, info = row[0], list(map(int, row[1::]))
        if NL == "N":
            tree = Tree(None)
            father_index = info[0]
            trees[father_index - 1].add_child(tree)
            trees[i] = tree
        else:
            father_index, game_result = info
            trees[father_index - 1].add_child(Node(game_result))

    root = trees[0]
    result = root.dfs()
    if result > 0:
        print(f"+{result}")
    else:
        print(result)

