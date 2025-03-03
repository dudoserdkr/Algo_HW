#include <iostream>
#include <sstream>
#include <vector>


class Solution {
    int n, a, b;
    std::vector<int> arr;
public:
    Solution(int n, std::vector<int> arr, int a, int b): n(n), a(a), b(b), arr(arr) {}

    int findValueInArray() {
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (a <= this->arr[i] && this->arr[i] <= b) {
                counter++;
            }
        }
        return counter;
    }
};

int main() {
    int n;
    while (std::cin >> n) {
        std::vector<int> arr;
        while(n--) {
            int p;
            std::cin >> p;
            arr.push_back(p);
        }
        int a, b;
        std::cin >> a >> b;
        Solution s(arr.size(), arr, a, b);
        std::cout << s.findValueInArray() << std::endl;
    }
}