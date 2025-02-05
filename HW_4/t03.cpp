// Результат роботи коду: 1.378796700


#include <iostream>
#include <iomanip>

double inline f(double x) {
    return pow(x, 3) + x + 1;
}

double realBinSearch() {
    double l = 0l;
    double r = 10l;
    while (r - l > 1e-9) {
        double m = (l + r) / 2.0;
        if (f(m) < 5) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return r;
}

int main() {
    double result = realBinSearch();
    std::cout << std::fixed << std::setprecision(9) << result << std::endl << f(result);
}