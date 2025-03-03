// Результат роботи коду: 1.000000000


#include <iostream>
#include <iomanip>

double inline f(double x) {
    return pow(x, 3) + 4 * pow(x, 2) + x - 6;
}

double realBinSearch() {
    double l = 0l;
    double r = 2l;
    double m = (l + r) / 2.0;
    while (r != m and m != l) {

        if (f(m) < 0) {
            l = m;
        }
        else {
            r = m;
        }
        m = (l + r) / 2.0;
    }
    return l;
}

int main() {
    double result = realBinSearch();
    std::cout << std::fixed << std::setprecision(9) << result << std::endl << f(result);
}