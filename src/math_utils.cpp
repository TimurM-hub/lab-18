#include "../include/math_utils.h"
#include <cmath>   // для std::abs

// Рекурсивная сумма цифр
int sumDigits(int n) {
    // Берём модуль числа, чтобы корректно работать с отрицательными
    n = std::abs(n);

    // Базовый случай рекурсии: число стало 0 — больше цифр нет
    if (n == 0) {
        return 0;
    }

    // Рекурсивный шаг:
    // n % 10 — последняя цифра
    // n / 10 — число без последней цифры
    return (n % 10) + sumDigits(n / 10);
}

// Проверка делимости на 3
bool isDivisibleBy3(int n) {
    return (n % 3) == 0;
}