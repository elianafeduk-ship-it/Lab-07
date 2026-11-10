
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Формування матриці
void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Виведення матриці
void Print(int** a, const int n)
{
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

// Пошук мінімального елемента побічної діагоналі
int SearchMinSecondaryDiagonal(int** a, const int n)
{
    int minElement = a[0][n - 1];

    for (int i = 1; i < n; i++)
    {
        int j = n - 1 - i;

        if (a[i][j] < minElement)
            minElement = a[i][j];
    }

    return minElement;
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

    Create(a, n, Low, High);

    cout << "Matrix:" << endl;
    Print(a, n);

    int minElement = SearchMinSecondaryDiagonal(a, n);

    cout << "Minimum element of secondary diagonal = "
        << minElement << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}

