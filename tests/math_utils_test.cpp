#include <iostream>
#include "../include/math_utils.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== Тест sumDigits ===\n";
    std::cout << "sumDigits(123)   = " << sumDigits(123)   << "  (ожидается 6)\n";
    std::cout << "sumDigits(-456)  = " << sumDigits(-456)  << "  (ожидается 15)\n";
    std::cout << "sumDigits(0)     = " << sumDigits(0)     << "  (ожидается 0)\n";
    std::cout << "sumDigits(9009)  = " << sumDigits(9009)  << "  (ожидается 18)\n";

    std::cout << "\n=== Тест isDivisibleBy3 ===\n";
    int testNums[] = {0, 3, 5, -9, 10, 123, 100};
    for (int num : testNums) {
        std::cout << num << " делится на 3? "
                  << (isDivisibleBy3(num) ? "ДА" : "НЕТ") << "\n";
    }

    return 0;
}