#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    cin >> n;

    int x[n][n];

    cout << "Matriz original:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i][j] = 1 + rand() % 99;
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

    int y[n][n];

    int nanillos = n / 2;
    for (int t = 0; t < nanillos; t++)
    {
        y[t][t] = x[t + 1][t];
        // arriba
        for (int i = t + 1; i < n - t; i++)
        {
            y[t][i] = x[t][i - 1];
        }
        // derecha
        for (int i = t + 1; i < n - t; i++)
        {
            y[i][n - t - 1] = x[i - 1][n - t - 1];
        }
        // abajo
        for (int i = n - t - 2; i >= t; i--)
        {
            y[n - t - 1][i] = x[n - t - 1][i + 1];
        }
        // izquierda
        for (int i = n - t - 2; i >= t; i--)
        {
            y[i][t] = x[i + 1][t];
        }
    }

    cout << "Matriz rotada:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << y[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}