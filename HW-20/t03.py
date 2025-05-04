class SegmentTree:
    def __init__(self, arr, func=lambda x, y: x + y, neutral_element=0):
        k = len(arr)
        self.func = func
        self.size = 1<<(k-1).bit_length()
        self.items = [neutral_element] * (2*self.size)
        self.neutral_element = neutral_element

        for i in range(k):
            self.items[i + self.size] = arr[i]

        for i in range(self.size - 1, 0, -1):
            self.items[i] = func(self.items[2*i], self.items[2*i + 1])

    def update(self, pos, x):
        pos += self.size
        self.items[pos] = x

        i = pos // 2
        while i > 0:
            self.items[i] = self.func(self.items[2*i], self.items[2*i + 1])
            i //= 2

    def query(self, l, r):
        l += self.size
        r += self.size

        res = self.neutral_element

        while l <= r:
            if l % 2 == 1:
                res = self.func(res, self.items[l])
            if r % 2 == 0:
                res = self.func(res, self.items[r])
            l = (l + 1) // 2
            r = (r - 1) // 2
        return res

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    m = int(input())

    sg = SegmentTree(arr, gcd, 0)
    for _ in range(m):
        q, l, r = map(int, input().split())
        l -= 1
        r -= 1
        if q == 1:ты
            print(sg.query(l, r))
        elif q == 2:
            sg.update(l, r + 1)