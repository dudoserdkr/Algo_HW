#include <iostream>
#include <vector>

class HeapValidator {
public:
    bool isHeap(const std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[i] > arr[left]) return false;
            if (right < n && arr[i] > arr[right]) return false;
        }
        return true;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    HeapValidator validator;
    std::cout << (validator.isHeap(arr) ? "YES" : "NO") << "\n";
}