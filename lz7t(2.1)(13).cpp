#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    cout << "Введіть кількість рядків матриці: ";
    cin >> rows;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> cols;

    // 1. Динамічне виділення пам'яті для матриці за допомогою new
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    int min_element;

    // 2. Введення елементів та одночасний пошук мінімального елемента
    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
            
            // Ініціалізуємо мінімум першим введеним елементом
            if (i == 0 && j == 0) {
                min_element = matrix[i][j];
            } 
            // Порівнюємо поточний елемент з мінімальним
            else if (matrix[i][j] < min_element) {
                min_element = matrix[i][j];
            }
        }
    }

    cout << "\nМінімальний елемент: " << min_element << "\n\n";

    // 3. Домноження всіх елементів на мінімальний та виведення результату
    cout << "Результуюча матриця:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] *= min_element;
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    // 4. Звільнення динамічної пам'яті
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i]; // Звільняємо кожен рядок
    }
    delete[] matrix; // Звільняємо масив вказівників

    return 0;
}