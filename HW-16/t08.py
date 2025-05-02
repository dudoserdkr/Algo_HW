import sys
sys.setrecursionlimit(10**7)
from bisect import bisect_left

class Tree:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def compute(self, q, P, powq, ans):
        if not self.children:
            s = [self.val]
            md = float('inf')
        else:
            child_sets = []
            child_md = []
            for ch in self.children:
                sc, mdc = ch.compute(q, P, powq, ans)
                child_sets.append(sc)
                child_md.append(mdc)

            big = max(range(len(self.children)), key=lambda i: len(child_sets[i]))
            s = child_sets[big]
            md = child_md[big]

            for i, sc in enumerate(child_sets):
                if i == big:
                    continue
                if child_md[i] < md:
                    md = child_md[i]
                for x in sc:
                    pos = bisect_left(s, x)
                    if pos > 0 and x - s[pos-1] < md:
                        md = x - s[pos-1]
                    if pos < len(s) and s[pos] - x < md:
                        md = s[pos] - x
                    s.insert(pos, x)

            pos = bisect_left(s, self.val)
            if pos > 0 and self.val - s[pos-1] < md:
                md = self.val - s[pos-1]
            if pos < len(s) and s[pos] - self.val < md:
                md = s[pos] - self.val
            s.insert(pos, self.val)

            ans[0] = (ans[0] + md * powq[self.key]) % P

        return s, md

if __name__ == '__main__':
    q, P = 127, 10**9+7
    n = int(input())
    parents = []
    vals = []
    for _ in range(n):
        p, v = map(int, input().split())
        parents.append(p)
        vals.append(v)

    nodes = [Tree(i, vals[i]) for i in range(n)]
    for i, p in enumerate(parents):
        if p != -1:
            nodes[p].add_child(nodes[i])
        else:
            root = nodes[i]

    powq = [1] * n
    for i in range(1, n):
        powq[i] = powq[i-1] * q % P

    ans = [0]
    root.compute(q, P, powq, ans)
    print(ans[0])