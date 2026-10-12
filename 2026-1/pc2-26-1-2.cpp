#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Observacion: Uso aleatorios para facilitar el llenado de datos. Atte: Joaquin

int main()
{
    srand(time(NULL));

    int m;
    cin >> m;

    int x[m];
    cout << "Edades:" << endl;
    for (int i = 0; i < m; i++)
    {
        x[i] = 12 + rand() % 10;
        cout << x[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = m - 1; j > i; j--)
        {
            if (x[i] < x[j])
            {
                int t = x[i];
                x[i] = x[j];
                x[j] = t;
            }
        }
    }

    int n = 0;
    do
    {
        n++;
    } while (n * n < m);

    int y[n][n] = {0};

    int i2 = 0;
    int j2 = 0;
    int t = 0;
    int i = 0;
    while (i < m)
    {
        while (i < m and j2 < n - t - 1)
        {
            y[i2][j2] = x[i];
            j2++;
            i++;
        }
        while (i < m and i2 < n - t - 1)
        {
            y[i2][j2] = x[i];
            i2++;
            i++;
        }
        while (i < m and j2 > t)
        {
            y[i2][j2] = x[i];
            i++;
            j2--;
        }
        while (i < m and i2 > t)
        {
            y[i2][j2] = x[i];
            i++;
            i2--;
        }
        i2++;
        j2++;
        t++;
        if (n % 2 == 1 and i2 == n - t - 1)
        {
            y[i2][j2] = x[i];
            break;
        }
    }

    cout << "Matriz final:" << endl;
    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            cout << y[p][q] << " \t";
        }
        cout << endl;
    }
}