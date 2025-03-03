#include <iostream>
#include <vector>

void print(std::vector<int>& arr) {
    for (auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void selectionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int currValue = arr[i];
        int position = i;
        while (position > 0) {
            if (arr[position - 1] > currValue) {
                std::swap(arr[position], arr[position - 1]);
                print(arr);
            }
            else {
                break;
            }
            position--;
        }
    }
}

int main() {
    int n, arrElement;
    std::vector<int> arr;

    std::cin >> n;
    while(n--) {
        std::cin >> arrElement;
        arr.push_back(arrElement);
    }
    selectionSort(arr);
}