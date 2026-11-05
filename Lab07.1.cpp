
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Створення матриці
void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High);

// Виведення матриці
void Print(int** a, const int rowCount, const int colCount);

// Сортування рядків матриці
void Sort(int** a, const int rowCount, const int colCount);

// Обмін двох рядків матриці
void Change(int** a, const int row1, const int row2,
    const int colCount);

// Обчислення суми та кількості елементів
void Calc(int** a, const int rowCount, const int colCount,
    int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = -8;
    const int High = 42;

    const int rowCount = 8;
    const int colCount = 7;

    int** R = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

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

    for (int i = 0; i < rowCount; i++)
        delete[] R[i];

    delete[] R;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
        {
            if ((a[i1][0] < a[i1 + 1][0]) ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] < a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] == a[i1 + 1][1] &&
                    a[i1][2] > a[i1 + 1][2]))
            {
                Change(a, i1, i1 + 1, colCount);
            }
        }
}

void Change(int** a, const int row1, const int row2,
    const int colCount)
{
    for (int j = 0; j < colCount; j++)
    {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount,
    int& S, int& k)
{
    S = 0;
    k = 0;

    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] > 0 || i % 2 != 0 || j % 2 != 0)
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
        }
}

