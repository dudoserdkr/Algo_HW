#include <iostream>
#include <vector>
#include <algorithm>

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& data) {
        n = data.size();
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
        for (int i = 0; i < n; i++) {
            tree[size + i] = data[i];
        }
        for (int i = size - 1; i > 0; i--) {
            tree[i] = std::max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int query(int l, int r) {
        l += size;
        r += size;
        int res = 0;
        while (l <= r) {
            if (l & 1) {
                res = std::max(res, tree[l]);
                l++;
            }
            if (!(r & 1)) {
                res = std::max(res, tree[r]);
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

private:
    int n;
    int size;
    std::vector<int> tree;
};

long long countSubarraysAtMost(const std::vector<int>& a, int T) {
    long long cnt = 0;
    long long curLen = 0;
    for (int x : a) {
        if (x <= T) {
            curLen++;
        } else {
            curLen = 0;
        }
        cnt += curLen;
    }
    return cnt;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    SegmentTree tree(a);
    long long result = countSubarraysAtMost(a, k) - countSubarraysAtMost(a, k - 1);
    std::cout << result << "\n";
    return 0;
}