# Цей розвʼязок проходить тільки на 80%

class SegmentTree:
    def __init__(self, arr):
        n = len(arr)
        self.size = 1 << (n - 1).bit_length()
        self.func = self._merge
        self.neutral = [float('inf'), float('-inf'), 0, 0, 0, 0]
        self.items = [self.neutral[:] for _ in range(2 * self.size)]
        for i, v in enumerate(arr):
            self.items[self.size + i] = [v, v, 1, 1, 1, 1]
        for i in range(self.size - 1, 0, -1):
            self.items[i] = self.func(self.items[2*i], self.items[2*i+1])

    @staticmethod
    def _merge(left, right):
        if left[5] == 0:
            return right[:]
        if right[5] == 0:
            return left[:]
        first = left[0]
        last = right[1]
        length = left[5] + right[5]
        if left[2] == left[5] and left[1] <= right[0]:
            pref = left[5] + right[2]
        else:
            pref = left[2]
        if right[3] == right[5] and left[1] <= right[0]:
            suff = right[5] + left[3]
        else:
            suff = right[3]
        best = max(left[4], right[4])
        if left[1] <= right[0]:
            best = max(best, left[3] + right[2])
        return [first, last, pref, suff, best, length]

    def update(self, pos, value):
        i = pos + self.size
        self.items[i] = [value, value, 1, 1, 1, 1]
        i //= 2
        while i:
            self.items[i] = self.func(self.items[2*i], self.items[2*i+1])
            i //= 2

    def query(self, l, r):
        l += self.size
        r += self.size
        left_res = self.neutral[:]
        right_res = self.neutral[:]
        while l <= r:
            if l & 1:
                left_res = self.func(left_res, self.items[l])
                l += 1
            if not r & 1:
                right_res = self.func(self.items[r], right_res)
                r -= 1
            l //= 2
            r //= 2
        result = self.func(left_res, right_res)
        return result[4]


if __name__ == '__main__':
    n = int(input())
    arr = [int(d) for d in input().split()]
    sg = SegmentTree(arr)
    m = int(input())
    for _ in range(m):
        q, l, r = map(int, input().split())
        if q == 1:
            print(sg.query(l-1, r-1))
        elif q == 2:
            sg.update(l-1, r)