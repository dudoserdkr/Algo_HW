#include <iostream>

long double foo(int n) {
    long double sum = 1;
    long int var = 1;
    for (int i = 1; i <= n; i++) {
        var *= i;
        sum *= 1 / (1 + var);
    }
    return sum;
}

// Тут я привів алгоритм, що еквівалентний співвідношення c) та виконуєтсья за O(n), оскільки маємо вкладений цикл, що виконується за O(n)