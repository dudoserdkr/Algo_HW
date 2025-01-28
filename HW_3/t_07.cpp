#include <iostream>
#include <vector>


class Solution {
    int n;
    std::vector<int> Beasts;
    int m;
    std::vector<int> UnknownBeasts;
public:
    Solution(int n, std::vector<int> Beasts, int m, std::vector<int> UnknownBeasts): n(n), Beasts(Beasts), m(m), UnknownBeasts(UnknownBeasts) {}

    int findLastBeast(int Beast) {
        int l = 0;
        int r = this->n;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (this->Beasts[m] <= Beast) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }

    int findFirstBeast(int Beast) {
        int l = 0;
        int r = this->n;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (this->Beasts[m] < Beast) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }

    void printSolution() {
        for (int Beast : this->UnknownBeasts) {
            std::cout << this->findLastBeast(Beast) - this->findFirstBeast(Beast) << std::endl;
        }

    }
};


int main() {
    int n;
    std::cin >> n;

    int i = 0;
    int Beast;
    std::vector<int> Beasts;
    while (i < n) {
        std::cin >> Beast;
        Beasts.push_back(Beast);
        i++;
    }

    int m;
    std::cin >> m;
    std::vector<int> UnknownBeasts;
    i = 0;
    while (i < m) {
        std::cin >> Beast;
        UnknownBeasts.push_back(Beast);
        i++;
    }

    Solution s(n, Beasts, m, UnknownBeasts);
    s.printSolution();
}