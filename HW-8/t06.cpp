#include <iostream>
#include <string>
#include <vector>


template <typename T>
void print(std::vector<T>& arr) {
    for (T i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void insertionSortWithWhile(std::vector<T>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        T currentValue = arr[i];
        int index = i;
        while (index > 0) {
            if (arr[index - 1] > currentValue) {
                arr[index] = arr[index - 1];
            } else {
                break;
            }
            index--;
        }
        arr[index] = currentValue;
    }
}

template <typename T>
void insertionSort(std::vector<T>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
            }
            else {
                break;
            }
        }
    }
}


int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    insertionSort(arr);

    for (std::string word : arr) {
        std::cout << word << std::endl;
        }
}

