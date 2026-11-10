#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    // Створення порожнього вектора для цілих чисел
    vector<int> arr;

    // Заповнення вектора 10-ма випадковими числами від -10 до 10
    for (int i = 0; i < 10; i++) {
        int randomNum = rand() % 21 - 10;
        arr.push_back(randomNum);
    }

    // Виведення початкового вектора на екран
    cout << "Початковий масив:\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Підрахунок додатних елементів
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            count++;
        }
    }

    // Виведення результату
    cout << "\nКількість додатних елементів: " << count << endl;

    return 0;
}