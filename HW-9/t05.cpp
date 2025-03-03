#include <iostream>
#include <vector>


struct Robot {
    long long mainId;
    long long secondaryId;
    int index;
};

class MergeSorter {
public:
    void sort(std::vector<Robot>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
    }
private:
    void mergeSort(std::vector<Robot>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    void merge(std::vector<Robot>& arr, int left, int mid, int right) {
        std::vector<Robot> leftPart(arr.begin() + left, arr.begin() + mid + 1);
        std::vector<Robot> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);
        int i = 0, j = 0, k = left;
        while (i < (int)leftPart.size() && j < (int)rightPart.size()) {
            if (leftPart[i].mainId < rightPart[j].mainId) {
                arr[k++] = leftPart[i++];
            } else if (leftPart[i].mainId > rightPart[j].mainId) {
                arr[k++] = rightPart[j++];
            } else {
                if (leftPart[i].index < rightPart[j].index) {
                    arr[k++] = leftPart[i++];
                } else {
                    arr[k++] = rightPart[j++];
                }
            }
        }
        while (i < (int)leftPart.size()) {
            arr[k++] = leftPart[i++];
        }
        while (j < (int)rightPart.size()) {
            arr[k++] = rightPart[j++];
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Robot> robots(n);
    for (int i = 0; i < n; i++) {
        std::cin >> robots[i].mainId >> robots[i].secondaryId;
        robots[i].index = i;
    }
    MergeSorter sorter;
    sorter.sort(robots);

    for (auto &r : robots) {
        std::cout << r.mainId << " " << r.secondaryId << "\n";
    }
}