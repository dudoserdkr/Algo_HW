#include <iostream>

long double foo(int n, double a) {

    long double sum = 1;
    long int var = 1;
    long double var2 = 1;

    for (int i = 1; i <= n; i++) {
        var *= i;
        var2 *= a;
        sum *= var2 / (1 + var);
    }
    return sum;
}

// Тут я привів алгоритм, що еквівалентний співвідношення c) та виконуєтсья за O(n), оскільки маємо вкладений цикл, що виконується за O(n)