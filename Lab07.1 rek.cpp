
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Виділення пам'яті для рядків матриці
void AllocateRows(int** a, const int i,
    const int rowCount, const int colCount);

// Звільнення пам'яті
void DeleteRows(int** a, const int i, const int rowCount);

// Створення матриці
void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High);

// Рекурсивне заповнення матриці
void CreateRecursive(int** a, const int colCount,
    const int total, const int index,
    const int Low, const int High);

// Виведення матриці
void Print(int** a, const int rowCount, const int colCount);

// Рекурсивне виведення матриці
void PrintRecursive(int** a, const int colCount,
    const int total, const int index);

// Сортування рядків
void Sort(int** a, const int rowCount, const int colCount);

// Рекурсивне сортування
void SortRecursive(int** a, const int rowCount,
    const int colCount, const int pass);

void SortPass(int** a, const int colCount,
    const int end, const int j);

// Обмін рядків
void Change(int** a, const int row1, const int row2,
    const int colCount);

// Рекурсивний обмін елементів рядків
void ChangeRecursive(int** a, const int row1, const int row2,
    const int colCount, const int j);

// Обчислення суми та кількості
void Calc(int** a, const int rowCount, const int colCount,
    int& S, int& k);

// Рекурсивне обчислення
void CalcRecursive(int** a, const int colCount,
    const int total, const int index,
    int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = -8;
    const int High = 42;

    const int rowCount = 8;
    const int colCount = 7;

    int** R = new int* [rowCount];

    AllocateRows(R, 0, rowCount, colCount);

    Create(R, rowCount, colCount, Low, High);

    cout << "Initial matrix:" << endl;
    Print(R, rowCount, colCount);

    Sort(R, rowCount, colCount);

    cout << "Sorted matrix:" << endl;
    Print(R, rowCount, colCount);

    int S = 0;
    int k = 0;

    Calc(R, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    cout << "Modified matrix:" << endl;
    Print(R, rowCount, colCount);

    DeleteRows(R, 0, rowCount);
    delete[] R;

    return 0;
}

// Виділення пам'яті для рядків
void AllocateRows(int** a, const int i,
    const int rowCount, const int colCount)
{
    if (i >= rowCount)
        return;

    a[i] = new int[colCount];

    AllocateRows(a, i + 1, rowCount, colCount);
}

// Звільнення пам'яті
void DeleteRows(int** a, const int i, const int rowCount)
{
    if (i >= rowCount)
        return;

    delete[] a[i];

    DeleteRows(a, i + 1, rowCount);
}

// Створення матриці
void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High)
{
    CreateRecursive(a, colCount, rowCount * colCount,
        0, Low, High);
}

// Рекурсивне заповнення матриці
void CreateRecursive(int** a, const int colCount,
    const int total, const int index,
    const int Low, const int High)
{
    if (index >= total)
        return;

    a[index / colCount][index % colCount] =
        Low + rand() % (High - Low + 1);

    CreateRecursive(a, colCount, total, index + 1,
        Low, High);
}

// Виведення матриці
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;

    PrintRecursive(a, colCount, rowCount * colCount, 0);

    cout << endl;
}

// Рекурсивне виведення матриці
void PrintRecursive(int** a, const int colCount,
    const int total, const int index)
{
    if (index >= total)
        return;

    cout << setw(4) << a[index / colCount][index % colCount];

    if (index % colCount == colCount - 1)
        cout << endl;

    PrintRecursive(a, colCount, total, index + 1);
}

// Сортування рядків
void Sort(int** a, const int rowCount, const int colCount)
{
    SortRecursive(a, rowCount, colCount, 0);
}

// Рекурсивне сортування рядків
void SortRecursive(int** a, const int rowCount,
    const int colCount, const int pass)
{
    if (pass >= rowCount - 1)
        return;

    SortPass(a, colCount, rowCount - pass - 1, 0);

    SortRecursive(a, rowCount, colCount, pass + 1);
}

// Один прохід сортування
void SortPass(int** a, const int colCount,
    const int end, const int j)
{
    if (j >= end)
        return;

    if ((a[j][0] < a[j + 1][0]) ||
        (a[j][0] == a[j + 1][0] &&
            a[j][1] < a[j + 1][1]) ||
        (a[j][0] == a[j + 1][0] &&
            a[j][1] == a[j + 1][1] &&
            a[j][2] > a[j + 1][2]))
    {
        Change(a, j, j + 1, colCount);
    }

    SortPass(a, colCount, end, j + 1);
}

// Обмін рядків
void Change(int** a, const int row1, const int row2,
    const int colCount)
{
    ChangeRecursive(a, row1, row2, colCount, 0);
}

// Рекурсивний обмін елементів рядків
void ChangeRecursive(int** a, const int row1, const int row2,
    const int colCount, const int j)
{
    if (j >= colCount)
        return;

    int tmp = a[row1][j];
    a[row1][j] = a[row2][j];
    a[row2][j] = tmp;

    ChangeRecursive(a, row1, row2, colCount, j + 1);
}

// Обчислення суми та кількості
void Calc(int** a, const int rowCount, const int colCount,
    int& S, int& k)
{
    S = 0;
    k = 0;

    CalcRecursive(a, colCount, rowCount * colCount,
        0, S, k);
}

// Рекурсивне обчислення
void CalcRecursive(int** a, const int colCount,
    const int total, const int index,
    int& S, int& k)
{
    if (index >= total)
        return;

    int i = index / colCount;
    int j = index % colCount;

    if (a[i][j] > 0 || i % 2 != 0 || j % 2 != 0)
    {
        S += a[i][j];
        k++;
        a[i][j] = 0;
    }

    CalcRecursive(a, colCount, total, index + 1, S, k);
}
