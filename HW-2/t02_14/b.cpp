#include <iostream>

int foo(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

// Тут я привів алгоритм, що еквівалентний співвідношення b) та виконуєтсья за O(n), оскільки маємо вкладений цикл, що виконується за O(n)