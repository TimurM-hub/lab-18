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