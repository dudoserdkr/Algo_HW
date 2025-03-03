#include <iostream>

double foo(int n, double a) {
    double sum = 1;
    for (int i = 1; i <= n; i++) {
        sum += a;
        a *= a;
    }
    return sum;
}

// Тут я привів алгоритм, що еквівалентний співвідношення c) та виконуєтсья за O(n), оскільки маємо вкладений цикл, що виконується за O(n)