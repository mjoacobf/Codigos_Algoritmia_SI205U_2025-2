#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Ingrese la cantidad de numeros a analizar: ";
    cin >> n;
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        int e;
        cout << "Ingrese el numero " << i << ": ";
        cin >> e;

        if (i % 2 == 1)
        {
            int minimoimpar = 0;
            while (e > 0)
            {
                int cifra = e % 10;
                if (cifra % 2 == 1)
                {
                    if (minimoimpar == 0)
                        minimoimpar = cifra;
                    else if (cifra < minimoimpar)
                        minimoimpar = cifra;
                }
                e /= 10;
            }

            if (minimoimpar != 0)
            {
                res *= 10;
                res += minimoimpar;
            }
        }
        else
        {
            int maximopar = -1;
            while (e > 0)
            {
                int cifra = e % 10;
                if (cifra % 2 == 0)
                {
                    if (maximopar == -1)
                        maximopar = cifra;
                    else if (cifra > maximopar)
                        maximopar = cifra;
                }
                e /= 10;
            }

            if (maximopar != -1)
            {
                res *= 10;
                res += maximopar;
            }
        }
    }

    cout << res;
}