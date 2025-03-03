#include <iostream>
#include <vector>


class QuickSorter {
public:
    void sort(std::vector<long long> &arr) {
        quickSort(arr, 0, arr.size() - 1);
    }
private:
    void quickSort(std::vector<long long> &arr, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(arr, left, right);
            quickSort(arr, left, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, right);
        }
    }
    int partition(std::vector<long long> &arr, int left, int right) {
        long long pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[right]);
        return i + 1;
    }
};

int main() {
    int n;
    std::cin >> n;

    long long number;
    std::vector<long long> arr;
    while(n--) {
        std::cin >> number;
        arr.push_back(number);
    }

    QuickSorter qs;
    qs.sort(arr);

    for (auto& element : arr) {
        std:: cout << element << " ";
    }
}