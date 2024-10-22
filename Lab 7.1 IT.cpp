// Lab_7_1.cpp
// < Пазин, Соломія >
// Лабораторна робота № 7.1.ІТ
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 25
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 14;
    int rowCount = 8;
    int colCount = 5;

    // Виділяємо пам'ять для матриці
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // Створюємо і виводимо початкову матрицю
    Create(a, rowCount, colCount, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);

    // Сортуємо матрицю за заданими умовами
    Sort(a, rowCount, colCount);
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    // Рахуємо суму та кількість елементів, які не кратні 4, і замінюємо їх на 0
    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);

    // Виводимо обчислені суму та кількість 
    cout << "S = " << S << " (sum of negative elements not multiples of 4)" << endl;
    cout << "k = " << k << " (count of negative elements not multiples of 4)" << endl;

    // Виводимо модифіковану матрицю після заміни елементів
    cout << "Modified matrix (negative elements not multiples of 4 replaced with 0):" << endl;
    Print(a, rowCount, colCount);

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < rowCount - 1; i0++) {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
            // Сортування за першим стовпцем
            if ((a[i1][0] > a[i1 + 1][0]) ||
                // Якщо перший стовпець однаковий, сортуємо за другим
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] > a[i1 + 1][1]) ||
                // Якщо і другий стовпець однаковий, сортуємо за третім
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] > a[i1 + 1][2])) {
                Change(a, i1, i1 + 1, colCount);
            }
        }
    }
}

void Change(int** a, const int row1, const int row2, const int colCount) {
    int tmp;
    for (int j = 0; j < colCount; j++) {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] < 0 && a[i][j] % 4 != 0) {  // Елемент від'ємний і не кратний 4
                S += a[i][j];
                k++;
                a[i][j] = 0;  // Замінюємо на 0
            }
        }
    }
}
