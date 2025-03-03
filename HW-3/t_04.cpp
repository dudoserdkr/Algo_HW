#include <iostream>
#include <vector>
#include <bitset>

class Solution {
    unsigned n;
    unsigned n_size;
    std::vector<unsigned> arr;
public:
    explicit Solution(unsigned n): n(n) {
        this->n_size = log2(n) + 1;
        this->fillArr();
        std::cout << Solution::max(this->arr) << std::endl;
    }

    void fillArr() {
        unsigned q = n;

        while (true) {
            q = cyclicShiftleft(q, this->n_size);
            this->arr.push_back(q);
            if (q == n) {
                break;
            }
        }
    }

    static unsigned cyclicShiftleft(unsigned n, unsigned n_size) {
        std::bitset<32> b(n);
        b <<= 1;
        b[0] = b[n_size];
        b[n_size] = false;
        return b.to_ulong();

    }

    static unsigned max(std::vector<unsigned> arr) {
        unsigned max = 0;

        for (unsigned int i : arr) {
            if (i > max) {
                max = i;
            }
        }
        return max;

    }
};

int main() {
    unsigned n;
    std::cin >> n;
    Solution s(n);

}