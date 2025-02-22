#include <iostream>
#include <vector>

void swapIntegers(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^  b;
}

int bubbleSort(std::vector<int>& arr) {
    size_t n = arr.size();
    int counter = 0;

    for (size_t i = n-1; i > 0; i--) {
        bool sorted = true;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                counter++;
                swapIntegers(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
        if (sorted) {
            break;
        }
    }
    return counter;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr;
    while(n--) {
        int number;
        std::cin >> number;
        arr.push_back(number);
    }
    std::cout << bubbleSort(arr);
}
