#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// Рекурсивная функция вычисления суммы цифр числа.
// Корректно обрабатывает 0 и отрицательные числа.
// Пример: sumDigits(123) = 6, sumDigits(-456) = 15, sumDigits(0) = 0.
int sumDigits(int n);

// Функция проверки делимости числа на 3.
// Возвращает true, если число делится на 3 без остатка.
bool isDivisibleBy3(int n);

#endif // MATH_UTILS_H