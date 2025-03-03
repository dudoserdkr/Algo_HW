#include <iostream>
#include <algorithm>
#include <vector>

// time complexity: O(n + m + n \log n + m \log m + parts \cdot (n + m))

struct Robot {
    int processTime;
    long int availableTime; //Time when robot will be available
    bool operator<(const Robot& other) const {
        if (other.availableTime == availableTime) {
            return other.processTime > processTime;
        }
        return other.availableTime > availableTime;
    }
};

class Solution {
    int parts{}, firstRobotsAmount{}, secondRobotsAmount{};
    std::vector<Robot> firstrobots, secondRobots;

public:
    Solution() {
        std::cin >> parts;
        inputRobots(firstrobots, firstRobotsAmount);
        inputRobots(secondRobots, secondRobotsAmount);
        std::sort(firstrobots.begin(), firstrobots.end());
        std::sort(secondRobots.begin(), secondRobots.end());
    }

//region problem-solution-methods (Main methods for solving problem)
    long int calculateNeededTime() {
        long int maxTime = 0;
        std::vector<long int> eachPartTime(parts, 0);

        robotsNeededTime(firstrobots, eachPartTime, maxTime);
        std::reverse(eachPartTime.begin(), eachPartTime.end());
        robotsNeededTime(secondRobots, eachPartTime, maxTime);

        return maxTime;
    }

    void robotsNeededTime(std::vector<Robot>& robots, std::vector<long int>& eachPartTime, long int& maxTime) const {
        /*
         * This function calculates the processing time for each part handled by robots
         */

        for (int i = 0; i < parts; i ++) {
            Robot robot = robots[0];
            robots.erase(robots.begin());

            eachPartTime[i] += robot.availableTime;
            if (eachPartTime[i] > maxTime) {
                maxTime = eachPartTime[i];
            }

            robot.availableTime += robot.processTime;


            int insertIndex = binarySearch(robots, robot);
            robots.insert(robots.begin() + insertIndex, robot);
        }
    }
//endregion

//region algorithm-methods (helping functions for Main methods)
    static int binarySearch(const std::vector<Robot>& robots, const Robot robot) {
        int l = 0;
        int r = robots.size();
        while (l < r) {
            int m = (l + r) / 2;

            if (robots[m] < robot) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }

    static void inputRobots(std::vector<Robot> &robots, int& robotsAmount) {
        std::cin >> robotsAmount;
        for (int i = 0; i < robotsAmount; i++) {
            int processTime;
            std::cin >> processTime;
            robots.push_back({processTime, processTime});
        }
    }

//endregion
};


int main() {
    Solution s;
    std::cout << s.calculateNeededTime();
}