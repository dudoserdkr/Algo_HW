#include <iostream>
#include <vector>
#include <array>

class Solution {
    int n;
    std::vector<int> bflies;
    int m;
    std::vector<std::array<int, 2>> unknown_blfies;

public:
    Solution(int n, std::vector<int> bflies, int m, std::vector<std::array<int, 2>> unknown_blfies)
        : n(n), bflies(bflies), m(m), unknown_blfies(unknown_blfies) {
        this->findUnknownBflies();
    }

    void findUnknownBflies() {
        int bfly;
        bool isBflyInCollection;
        for (int i = 0; i < this->unknown_blfies.size(); i++) {
            bfly = this->unknown_blfies[i][0];
            isBflyInCollection = this->isBflyUnknown(bfly);
            this->unknown_blfies[i][1] = isBflyInCollection;
        }
    }

    bool isBflyUnknown(int bfly) {
        int l = 0;
        int r = this->n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (this->bflies[m] < bfly) {
                l = m + 1;
            } else if (this->bflies[m] == bfly) {
                return true;
            } else {
                r = m - 1;
            }
        }
        return false;
    }

    void printSolution() {
        int bfly;
        bool isBflyInCollection;
        for (int i = 0; i < this->unknown_blfies.size(); i++) {
            bfly = this->unknown_blfies[i][0];
            isBflyInCollection = this->unknown_blfies[i][1];
            if (isBflyInCollection) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    int i = 0;
    int bfly;
    std::vector<int> bflies;
    while (i < n) {
        std::cin >> bfly;
        bflies.push_back(bfly);
        i++;
    }

    int m;
    std::cin >> m;
    std::vector<std::array<int, 2>> unknown_blfies;
    i = 0;
    while (i < m) {
        std::cin >> bfly;
        unknown_blfies.push_back({bfly, 0});
        i++;
    }

    Solution s(n, bflies, m, unknown_blfies);
    s.printSolution();
}