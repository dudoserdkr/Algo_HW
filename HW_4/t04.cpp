// Результат роботи коду: 2.278862660


#include <iostream>
#include <iomanip>
#include <math.h>

double inline f(double x) {
    return sin(x) - x / 3;
}

double realBinSearch() {
    double l = 1.6l;
    double r = 3l;

    while (r - l > 1e-11) {
        double m = (l + r) / 2.0;
        if (f(m) > 0) {
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