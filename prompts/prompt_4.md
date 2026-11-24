## Промпт 4
Напиши на C++ модуль для обработки матрицы:
Функцию поиска суммы элементов побочной диагонали, которые делятся на 3.
Функцию замены элементов ниже побочной диагонали на результат рекурсивного вычисления суммы их цифр.
Создай заголовочный файл matrix_processor.h и файл реализации matrix_processor.cpp.

## Ответ AI:
Отлично! Это логичное продолжение — теперь объединим работу с матрицами и математические функции. Разберём по шагам.

## 📐 Геометрия побочной диагонали

Для квадратной матрицы размером `n × n`:
- **Побочная диагональ**: элементы `[i][j]`, где `i + j == n - 1`
- **Ниже побочной диагонали**: элементы `[i][j]`, где `i + j > n - 1`

Пример для 4×4 (X — побочная диагональ, * — ниже):
```
[0][0]  [0][1]  [0][2]  [0][3]X
[1][0]  [1][1]  [1][2]X [1][3]*
[2][0]  [2][1]X [2][2]* [2][3]*
[3][0]X [3][1]* [3][2]* [3][3]*
```

---

## 1. Заголовочный файл `matrix_processor.h`

```cpp
#ifndef MATRIX_PROCESSOR_H
#define MATRIX_PROCESSOR_H

// Функция вычисления суммы элементов побочной диагонали,
// которые делятся на 3.
// Параметры:
//   matrix - указатель на квадратную матрицу (не модифицируется)
//   size   - размер матрицы (количество строк/столбцов)
// Возвращает: сумму подходящих элементов
int sumSideDiagonalDivBy3(const int* const* matrix, int size);

// Функция замены элементов, расположенных ниже побочной диагонали,
// на результат рекурсивного вычисления суммы их цифр.
// Параметры:
//   matrix - указатель на квадратную матрицу (модифицируется)
//   size   - размер матрицы
void replaceBelowSideDiagonal(int** matrix, int size);

#endif // MATRIX_PROCESSOR_H
```

---

## 2. Файл реализации `matrix_processor.cpp`

```cpp
#include "matrix_processor.h"
#include "math_utils.h"  // для sumDigits

// Сумма элементов побочной диагонали, делящихся на 3
int sumSideDiagonalDivBy3(const int* const* matrix, const int size) {
    int sum = 0;
    
    // Проходим по всем элементам побочной диагонали
    // Для побочной диагонали: j = size - 1 - i
    for (int i = 0; i < size; ++i) {
        const int j = size - 1 - i;
        const int element = matrix[i][j];
        
        // Проверяем делимость на 3
        if (element % 3 == 0) {
            sum += element;
        }
    }
    
    return sum;
}

// Замена элементов ниже побочной диагонали на сумму их цифр
void replaceBelowSideDiagonal(int** matrix, const int size) {
    // Проходим по всем элементам матрицы
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Проверяем, находится ли элемент ниже побочной диагонали
            if (i + j > size - 1) {
                // Заменяем на сумму цифр (используем рекурсивную функцию)
                matrix[i][j] = sumDigits(matrix[i][j]);
            }
        }
    }
}
```

---

## 3. Главный файл `main.cpp` (для проверки)

```cpp
#include <iostream>
#include <iomanip>
#include "matrix_io.h"
#include "matrix_processor.h"

// Вспомогательная функция для вывода матрицы (int версия)
void printIntMatrix(const int* const* matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(6) << matrix[i][j];
        }
        std::cout << "\n";
    }
}

// Функция создания тестовой int-матрицы
int** createTestIntMatrix(int size) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = (i * size + j + 1) * 3; // числа, кратные 3
        }
    }
    return matrix;
}

void freeIntMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    const int SIZE = 4;
    
    std::cout << "=== Исходная матрица ===\n";
    int** matrix = createTestIntMatrix(SIZE);
    printIntMatrix(matrix, SIZE);
    
    std::cout << "\n=== Сумма элементов побочной диагонали, делящихся на 3 ===\n";
    const int sum = sumSideDiagonalDivBy3(matrix, SIZE);
    std::cout << "Сумма: " << sum << "\n";
    
    std::cout << "\n=== Матрица после замены элементов ниже побочной диагонали ===\n";
    replaceBelowSideDiagonal(matrix, SIZE);
    printIntMatrix(matrix, SIZE);
    
    freeIntMatrix(matrix, SIZE);
    
    return 0;
}
```

---

## 📦 Компиляция

```bash
g++ main.cpp matrix_io.cpp math_utils.cpp matrix_processor.cpp -o matrix_app
./matrix_app
```

---

## 🔍 Пример работы

Для тестовой матрицы 4×4 с числами, кратными 3:
```
     3     6     9    12
    15    18    21    24
    27    30    33    36
    39    42    45    48
```

**Побочная диагональ**: 12, 21, 30, 39  
Все делятся на 3, сумма = 12 + 21 + 30 + 39 = **102**

**После замены ниже побочной диагонали**:
- 24 → sumDigits(24) = 6
- 33 → sumDigits(33) = 6
- 36 → sumDigits(36) = 9
- 39 → sumDigits(39) = 12
- 42 → sumDigits(42) = 6
- 45 → sumDigits(45) = 9
- 48 → sumDigits(48) = 12

Результат:
```
     3     6     9    12
    15    18    21     6
    27    30     6     9
    12     6     9    12
```

---


Готово! Теперь у тебя полноценный модуль для обработки матриц. Если нужно добавить ещё операции (транспонирование, умножение, поиск максимума и т.д.) — обращайся!