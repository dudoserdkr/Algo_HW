#include <iostream>
#include <vector>
#include <sstream>

class Solution {
    int N{};
    std::vector<int> soundsLen;
    int maxLen = 0;

public:
    Solution(int N, std::vector<int> s) : N(N), soundsLen(s) {}

    void solve(std::vector<int> taken_songs = {}, int len = 0, int num = 0) {
        if (this->maxLen == this->N) {
            return;
        }
        if (len > this->N) {
            return;
        }
        if (len > this->maxLen) {
            this->maxLen = len;
        }
        if (num >= this->soundsLen.size()) {
            return;
        }
        this->solve(taken_songs, len, num + 1);
        taken_songs.push_back(this->soundsLen[num]);
        this->solve(taken_songs, len + this->soundsLen[num], num + 1);
    }

    int getMaxLen() {
        return maxLen;
    }
};

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int N, s;
        iss >> N >> s;

        std::vector<int> tracks;
        int track;
        while (iss >> track) {
            tracks.push_back(track);
        }

        Solution sol(N, tracks);
        sol.solve();
        std::cout << "sum:" << sol.getMaxLen() << std::endl;
    }
}