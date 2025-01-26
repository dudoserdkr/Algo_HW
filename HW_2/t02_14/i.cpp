

long double foo(int n, double m) {
    long double sum = 1;
    long double var = 1;

    for (int i = 1; i <= n; i++) {
        var = 1;
        for (int j = 1; j <= i; j ++) {
            var *= i;
        }
        sum *= 1 / (1 + var);
    }
    return sum;
}

// Тут я привів алгоритм, що еквівалентний співвідношення h) та має цикл в циклі, перший виконується за O(n), другий за O(n) у найгіршому випадку, тому програма виконується за O(n^2)