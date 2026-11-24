#include "../include/matrix_processor.h"
#include "../include/math_utils.h"  // для sumDigits

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