
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне заповнення одного рядка матриці
void CreateRow(int* a, const int n, const int Low, const int High, int j)
{
    if (j >= n)
        return;

    a[j] = Low + rand() % (High - Low + 1);

    CreateRow(a, n, Low, High, j + 1);
}

// Рекурсивне заповнення матриці
void CreateRows(int** a, const int n, const int Low, const int High, int i)
{
    if (i >= n)
        return;

    CreateRow(a[i], n, Low, High, 0);

    CreateRows(a, n, Low, High, i + 1);
}

// Рекурсивне виведення одного рядка матриці
void PrintRow(int* a, const int n, int j)
{
    if (j >= n)
        return;

    cout << setw(4) << a[j];

    PrintRow(a, n, j + 1);
}

// Рекурсивне виведення матриці
void PrintRows(int** a, const int n, int i)
{
    if (i >= n)
        return;

    PrintRow(a[i], n, 0);
    cout << endl;

    PrintRows(a, n, i + 1);
}

// Рекурсивний пошук мінімального елемента побічної діагоналі
void SearchMinSecondaryDiagonal(int** a, const int n,
    int i, int& minElement)
{
    if (i >= n)
        return;

    int j = n - 1 - i;

    if (a[i][j] < minElement)
        minElement = a[i][j];

    SearchMinSecondaryDiagonal(a, n, i + 1, minElement);
}

int main()
{
    srand((unsigned)time(NULL));

    int Low = -40;
    int High = 40;
    int n;

    cout << "n = ";
    cin >> n;

    if (n <= 0)
        return 1;

    int** a = new int* [n];

    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    CreateRows(a, n, Low, High, 0);

    cout << "Matrix:" << endl;
    PrintRows(a, n, 0);

    int minElement = a[0][n - 1];

    SearchMinSecondaryDiagonal(a, n, 1, minElement);

    cout << "Minimum element of secondary diagonal = "
        << minElement << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}
