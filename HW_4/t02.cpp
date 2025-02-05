#include <iostream>
#include <iomanip>
#include <cmath>

double inline f(double x) {
    return pow(x, 2) + pow(x, 0.5);
}

double realBinSearch(double C) {
    double l = 1.0;
    double r = C;
    double m = 0;
    while (r - l > 1e-10) {
        m = (l + r) / 2.0;
        if (f(m) < C) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return m;
}

int main() {
    double C;
    std::cin >> C;
    double result = realBinSearch(C);
    std::cout << std::fixed << std::setprecision(9) << result << std::endl;
}