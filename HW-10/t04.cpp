#include <iostream>
#include <vector>


void print(const std::vector<int>& arr) {
    for (auto & el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

}


bool contains(const std::vector<int>& arr, int n) {
    for (auto& el : arr) {
        if (el == n) {
            return true;
        }
    }
    return false;
}


void printPermutations(std::vector<int> arr, int n, int k) {
    int curr_len = arr.size();

    if (curr_len == k) {
        print(arr);
        return;
    }

    for (int i = 1; i < n + 1; i++) {
        if (!contains(arr, i)) {
            std::vector<int> new_arr = arr;
            new_arr.push_back(i);
            printPermutations(new_arr, n, k);
        }
    }
}


int main() {
    int n, k;
    std::cin >> n >> k;
    printPermutations({}, n, k);
}