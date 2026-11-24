#include "../include/matrix_io.h"
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