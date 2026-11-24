#include <iostream>
#include "../include/matrix_io.h"
using namespace std; 
int main() {
    setlocale(LC_ALL, "rus"); // Для корректного вывода кириллицы в консоли
    
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