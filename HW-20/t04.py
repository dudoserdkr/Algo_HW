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


def lcm(a, b):
    if a == 0 or b == 0:
        return 0
    return a * b // gcd(a, b)


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    m = int(input())

    sg_gcd = SegmentTree(arr, gcd, 0)
    sg_lcm = SegmentTree(arr, lcm, 1)

    for _ in range(m):
        q, l, r = map(int, input().split())
        if q == 1:
            res_gcd = sg_gcd.query(l - 1, r - 1)
            res_lcm = sg_lcm.query(l - 1, r - 1)
            if res_gcd == res_lcm:
                print("draw")
            elif res_gcd < res_lcm:
                print("wins")
            else:
                print("loser")
        elif q == 2:
            sg_gcd.update(l - 1, r)
            sg_lcm.update(l - 1, r)
