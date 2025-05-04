// Цей розвʼязок проходить на 100%

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

struct Node {
    int first, last;
    int pref, suff, best, len;
};

class SegmentTree {
public:
    explicit SegmentTree(const std::vector<int>& arr) {
        size_ = 1;
        while (size_ < static_cast<int>(arr.size())) {
            size_ <<= 1;
        }
        tree.assign(2 * size_, neutral());
        for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
            tree[size_ + i] = { arr[i], arr[i], 1, 1, 1, 1 };
        }
        for (int pos = size_ - 1; pos >= 1; --pos) {
            tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    void update(int index, int value) {
        int pos = index + size_;
        tree[pos] = { value, value, 1, 1, 1, 1 };
        for (pos /= 2; pos >= 1; pos /= 2) {
            tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    int query(int left, int right) {
        int l = left + size_, r = right + size_;
        Node left_res = neutral(), right_res = neutral();
        while (l <= r) {
            if ((l & 1) == 1) {
                left_res = merge(left_res, tree[l]);
                ++l;
            }
            if ((r & 1) == 0) {
                right_res = merge(tree[r], right_res);
                --r;
            }
            l /= 2; r /= 2;
        }
        return merge(left_res, right_res).best;
    }

private:
    int size_;
    std::vector<Node> tree;

    static Node neutral() {
        return {
            std::numeric_limits<int>::max(),
            std::numeric_limits<int>::min(),
            0, 0, 0, 0
        };
    }

    static Node merge(const Node& a, const Node& b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;
        Node res;
        res.first = a.first;
        res.last  = b.last;
        res.len   = a.len + b.len;
        res.pref  = (a.pref == a.len && a.last <= b.first)
                    ? a.len + b.pref : a.pref;
        res.suff  = (b.suff == b.len && a.last <= b.first)
                    ? b.len + a.suff : b.suff;
        res.best  = std::max(a.best, b.best);
        if (a.last <= b.first) {
            res.best = std::max(res.best, a.suff + b.pref);
        }
        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    SegmentTree st(arr);

    int m;
    std::cin >> m;
    while (m--) {
        int t, x, y;
        std::cin >> t >> x >> y;
        if (t == 1) {
            std::cout << st.query(x - 1, y - 1) << '\n';
        } else {
            st.update(x - 1, y);
        }
    }
}