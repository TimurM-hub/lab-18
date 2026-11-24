#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Рекурсивная функция вычисления суммы цифр числа
int sumDigits(int n) {
    if (n < 0) n = -n;       // обрабатываем отрицательные числа
    if (n == 0) return 0;    // базовый случай рекурсии
    return (n % 10) + sumDigits(n / 10); // рекурсивный шаг
}

// Функция проверки делимости на 3
bool isDivisibleBy3(int n) {
    return n % 3 == 0;
}

// Сумма элементов побочной диагонали, делящихся на 3
int sumSecondaryDiagDivBy3(const vector<vector<int>>& matrix) {
    int sum = 0;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        int j = n - 1 - i; // индекс столбца побочной диагонали
        if (isDivisibleBy3(matrix[i][j])) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Замена элементов ниже побочной диагонали на сумму их цифр
void processBelowSecondaryDiag(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j > n - 1) { // условие: ниже побочной диагонали
                matrix[i][j] = sumDigits(matrix[i][j]);
            }
        }
    }
}

// Ввод матрицы
void inputMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    cout << "Введите элементы матрицы " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Вывод матрицы
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер квадратной матрицы (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Размер матрицы должен быть больше 0!\n";
        return 1;
    }

    vector<vector<int>> matrix(n, vector<int>(n));

    inputMatrix(matrix);

    cout << "\n--- Исходная матрица ---\n";
    printMatrix(matrix);

    int sum = sumSecondaryDiagDivBy3(matrix);
    cout << "\nСумма элементов побочной диагонали, делящихся на 3: " << sum << "\n";

    processBelowSecondaryDiag(matrix);

    cout << "\n--- Матрица после преобразований ---\n";
    printMatrix(matrix);

    return 0;
}