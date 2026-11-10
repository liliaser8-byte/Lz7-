#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;

    cout << "Введіть кількість рядків матриці: ";
    cin >> rows;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> cols;

    // 1. Створення двовимірного масиву за допомогою std::vector
    // Одразу виділяємо необхідний розмір: rows рядків по cols елементів
    vector<vector<int>> matrix(rows, vector<int>(cols));

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

    // Звільнення пам'яті не потрібне, оскільки деструктор std::vector зробить це автоматично

    return 0;
}