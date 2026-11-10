#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;

    // Запит розміру масиву у користувача
    cout << "Введіть розмір масиву: ";
    cin >> size;

    // Створення порожнього вектора для цілих чисел
    vector<int> arr;
    int temp;

    // Заповнення вектора значеннями з клавіатури
    for (int i = 0; i < size; i++) {
        cout << "Введіть елемент " << i << ": ";
        cin >> temp;
        arr.push_back(temp); 
    }

    // Підрахунок додатних елементів
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            count++;
        }
    }

    // Виведення результату
    cout << "Кількість додатних елементів у масиві: " << count << endl;

    return 0;
}