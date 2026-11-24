#include <iostream>
#include <iomanip>
#include "../include/matrix_io.h"
#include "../include/matrix_processor.h"

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