#include <iostream>
#include <algorithm>
#include <vector>


class Solution {
    int parts{};
    std::vector<int> firstRobots, secondRobots;

public:
    Solution() {
        std::cin >> parts;
        input_robots(firstRobots);
        input_robots(secondRobots);
    }

    int binarySearchByAnswer() {
        int l = 0;
        int r = std::max(this->firstRobots[firstRobots.size() - 1],
            this->secondRobots[secondRobots.size() - 1]) * this->parts;

        while (l < r) {
            int m = (l + r) / 2;

            if (std::min(partsPerRobotType(m, this->firstRobots), partsPerRobotType(m, this->secondRobots)) > this->parts) {
                r = m - 1;
            }
            else if (std::min(partsPerRobotType(m, this->firstRobots), partsPerRobotType(m, this->secondRobots)) == this->parts) {
                return m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }

    static int partsPerRobotType(const int time, const std::vector<int>& typeRobots) {
        int sum = 0;
        for (int robotTime : typeRobots) {
            sum += time / robotTime;
        }
        return sum;
    }

    static void input_robots(std::vector<int> &robots) {
        int countRobots;
        std::cin >> countRobots;
        while (countRobots--) {
            int time;
            std::cin >> time;
            robots.push_back(time);
        }
    }
};


int main() {
    Solution s;
    std::cout << (s.binarySearchByAnswer());
}