
## Промпт 2
Модуль ввода/вывода матрицы. 
Напиши на C++ модуль для работы с матрицами:
Функцию ввода матрицы с клавиатуры (размер передается параметром).
Функцию вывода матрицы на экран в удобном формате.
Функцию создания тестовой матрицы для демонстрации.
Создай заголовочный файл matrix_io.h и файл реализации matrix_io.cpp.

## Ответ AI:

### 1. Заголовочный файл `matrix_io.h`
Здесь мы объявляем функции, чтобы они были доступны в других частях программы.

```cpp
#ifndef MATRIX_IO_H
#define MATRIX_IO_H

// Функция ввода матрицы с клавиатуры.
// Параметры: rows - количество строк, cols - количество столбцов.
// Возвращает указатель на динамически выделенную матрицу.
double** inputMatrix(int rows, int cols);

// Функция вывода матрицы на экран в удобном табличном формате.
// Параметры: matrix - указатель на матрицу, rows - строки, cols - столбцы.
void outputMatrix(double** matrix, int rows, int cols);

// Функция создания тестовой матрицы для демонстрации.
// Заполняет матрицу предсказуемыми значениями.
double** createTestMatrix(int rows, int cols);

// Функция освобождения динамически выделенной памяти под матрицу.
// Обязательна к вызову, чтобы избежать утечек памяти!
void freeMatrix(double** matrix, int rows);

#endif // MATRIX_IO_H
```

### 2. Файл реализации `matrix_io.cpp`
Здесь содержится логика работы функций.

```cpp
#include "matrix_io.h"
#include <iostream>
#include <iomanip> // Для использования setw (выравнивание при выводе)

using namespace std;

// Реализация ввода матрицы
double** inputMatrix(int rows, int cols) {
    // 1. Выделяем память под массив указателей на строки
    double** matrix = new double*[rows];
    
    // 2. Выделяем память под каждую строку (столбцы)
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }

    // 3. Считываем данные с клавиатуры
    cout << "Введите элементы матрицы размером " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    
    return matrix;
}

// Реализация вывода матрицы
void outputMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // setw(12) задает ширину поля вывода для каждого числа,
            // благодаря чему столбцы выравниваются и матрица выглядит аккуратно
            cout << setw(12) << matrix[i][j];
        }
        cout << "\n"; // Перенос строки после каждой строки матрицы
    }
}

// Реализация создания тестовой матрицы
double** createTestMatrix(int rows, int cols) {
    // Выделяем память (аналогично вводу)
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
        
        // Заполняем тестовыми значениями (например, номером элемента по порядку)
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j + 1; 
        }
    }
    return matrix;
}

// Реализация очистки памяти
void freeMatrix(double** matrix, int rows) {
    // Сначала удаляем каждую строку
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    // Затем удаляем сам массив указателей
    delete[] matrix;
}
```

### 3. Главный файл `main.cpp` (для проверки)
Этот файл нужен, чтобы собрать всё воедино и запустить программу.

```cpp
#include <iostream>
#include "matrix_io.h"

int main() {
    setlocale(LANG, "ru_RU.UTF-8"); // Для корректного вывода кириллицы в консоли
    
    int rows = 3, cols = 4;

    cout << "--- Демонстрация тестовой матрицы ---\n";
    // Создаем и выводим тестовую матрицу
    double** testMat = createTestMatrix(rows, cols);
    outputMatrix(testMat, rows, cols);
    // Освобождаем память, так как она больше не нужна
    freeMatrix(testMat, rows); 


    cout << "\n--- Ввод своей матрицы с клавиатуры ---\n";
    // Вводим матрицу с клавиатуры
    double** userMat = inputMatrix(rows, cols);
    
    cout << "\nВы ввели следующую матрицу:\n";
    outputMatrix(userMat, rows, cols);
    
    // Обязательно очищаем память в конце программы!
    freeMatrix(userMat, rows);

    return 0;
}
```

### 💡 Как это скомпилировать и запустить:
Если ты используешь **g++** в терминале (Linux/macOS/Windows с MinGW), команда для компиляции будет выглядеть так:
```bash
g++ main.cpp matrix_io.cpp -o matrix_app
```
*(Обрати внимание: мы передаем компилятору оба `.cpp` файла, чтобы он мог связать их в одну программу).*

Запуск:
```bash
./matrix_app   # (или matrix_app.exe в Windows)
```

### Что дальше?
Обычно в таких лабораторных работах следующим шагом идет **умножение матриц**, **поиск определителя** или **транспонирование**. Если тебе нужно будет написать модуль для математических операций над этими матрицами — обращайся, накидаем!
___
