#include <iostream>
using namespace std;

int main()
{
    int mcd;

    int n;
    cout << "Ingrese la cantidad de numeros a analizar: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int e;
        cout << "Ingrese el numero " << i << ": ";
        cin >> e;

        if (i == 1)
            mcd = e;
        else
        {
            while (mcd != e)
            {
                if (mcd > e)
                {
                    mcd = mcd - e;
                }
                else
                {
                    e = e - mcd;
                }
            }
        }
    }

    cout << "El MCD es " << mcd << endl;
    cout << "Los factores primos de " << mcd << " son: ";

    for (int val = 1; val <= mcd; val++)
    {
        if (mcd % val == 0)
        {
            bool esPrimo = true;
            if (val < 2)
                esPrimo = false;
            for (int k = 2; k < val; k++)
            {
                if (val % k == 0)
                {
                    esPrimo = false;
                    break;
                }
            }

            if (esPrimo)
                cout << val << " ";
        }
    }
}