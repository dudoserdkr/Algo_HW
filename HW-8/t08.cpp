#include <iostream>
#include <vector>
#include <array>

template <typename T>
bool compareTime(const std::array<T, 3>& firstTime, const std::array<T, 3>& secondTime) {
    return firstTime < secondTime;
}


template <typename T>
void selectionSort(std::vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minpos = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (compareTime(arr[j], arr[minpos])) {
                minpos = j;
            }
        }
        std::swap(arr[i], arr[minpos]);
    }
}


int main() {
    int n;
    std::cin >> n;
    int hours = 0, minutes = 0, seconds = 0;
    std::vector<std::array<int, 3>> arr;

    while(n--) {
        std::cin >> hours >> minutes >> seconds;
        arr.push_back({hours, minutes, seconds});
    }

    selectionSort(arr);

    for (auto [hours, minutes, seconds] : arr) {
        std::cout << hours << " " << minutes << " " << seconds << std::endl;
    }

}