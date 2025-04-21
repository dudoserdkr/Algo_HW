#include <iostream>
#include <vector>
#include <queue>

class Merger {
public:
    long long mergeAll(std::vector<int>& nums) {
        std::priority_queue<long long, std::vector<long long>, std::greater<>> pq(nums.begin(), nums.end());
        long long total = 0;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            total += a + b;
            pq.push(a + b);
        }
        return total;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    Merger merger;
    std::cout << merger.mergeAll(nums) << "\n";
}