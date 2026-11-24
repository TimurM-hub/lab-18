#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "../include/matrix_io.h"
#include "../include/math_utils.h"
#include "../include/matrix_processor.h"

// Вспомогательная функция для ввода int-матрицы с клавиатуры
int** inputIntMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    std::cout << "Введите элементы матрицы размером " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
    
    return matrix;
}

// Вспомогательная функция для вывода int-матрицы
void outputIntMatrix(const int* const* matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(8) << matrix[i][j];
        }
        std::cout << "\n";
    }
}

// Освобождение памяти под int-матрицу
void freeIntMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Функция безопасного ввода целого числа с проверкой
int safeInputInt(const std::string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        std::cout << prompt;
        
        // Проверяем, что ввод корректный
        if (std::cin >> value) {
            // Проверяем диапазон
            if (value >= minVal && value <= maxVal) {
                // Очищаем остаток строки (если пользователь ввел что-то после числа)
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            } else {
                std::cout << "Ошибка: число должно быть в диапазоне от " 
                          << minVal << " до " << maxVal << "\n";
            }
        } else {
            // Если ввод некорректный (не число)
            std::cout << "Ошибка: введите целое число\n";
            // Очищаем буфер ввода
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    
    std::cout << "========================================\n";
    std::cout << "  Обработка квадратной матрицы\n";
    std::cout << "========================================\n\n";
    
    // Запрос размера матрицы с проверкой
    const int MAX_SIZE = 10;
    int size = safeInputInt("Введите размер квадратной матрицы (1-" + 
                            std::to_string(MAX_SIZE) + "): ", 1, MAX_SIZE);
    
    std::cout << "\n";
    
    // Ввод матрицы
    std::cout << "----------------------------------------\n";
    std::cout << "Ввод матрицы\n";
    std::cout << "----------------------------------------\n";
    int** matrix = inputIntMatrix(size, size);
    
    // Вывод исходной матрицы
    std::cout << "\n----------------------------------------\n";
    std::cout << "Исходная матрица:\n";
    std::cout << "----------------------------------------\n";
    outputIntMatrix(matrix, size, size);
    
    // Вычисление суммы элементов побочной диагонали, делимых на 3
    std::cout << "\n----------------------------------------\n";
    std::cout << "Анализ побочной диагонали\n";
    std::cout << "----------------------------------------\n";
    
    // Выводим элементы побочной диагонали для наглядности
    std::cout << "Элементы побочной диагонали: ";
    for (int i = 0; i < size; ++i) {
        int j = size - 1 - i;
        std::cout << matrix[i][j];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "\n";
    
    const int sum = sumSideDiagonalDivBy3(matrix, size);
    std::cout << "Сумма элементов побочной диагонали, делимых на 3: " << sum << "\n";
    
    // Замена элементов ниже побочной диагонали
    std::cout << "\n----------------------------------------\n";
    std::cout << "Преобразование матрицы\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Замена элементов ниже побочной диагонали на сумму их цифр...\n";
    replaceBelowSideDiagonal(matrix, size);
    
    // Вывод измененной матрицы
    std::cout << "\n----------------------------------------\n";
    std::cout << "Измененная матрица:\n";
    std::cout << "----------------------------------------\n";
    outputIntMatrix(matrix, size, size);
    
    // Освобождение памяти
    freeIntMatrix(matrix, size);
    
    std::cout << "\n========================================\n";
    std::cout << "  Работа завершена успешно!\n";
    std::cout << "========================================\n";
    
    return 0;
}