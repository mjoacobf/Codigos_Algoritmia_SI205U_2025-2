#include <iostream>
using namespace std;

int main()
{
    int x, y = 0, sum = 0;
    cout << "Ingrese X de 6 cifras: ";
    cin >> x;
    // 172839, pares: 7, 8, 9

    // CONCATENAR NUMEROS:
    /*
        AGREGAR NUMEROS DE IZQUIERDA A DERECHA
        res*=10;
        res+=digito;

        //46728
        //874


        AGREGAR NUMEROS DE DERECHA A IZQUIERDA
        int conteo = 1;
        while (...) {
            int digito...
            res+=conteo*digito;
            conteo*=10;
        }

        //46728
        //478
    */

    int t = x;
    int conteo = 1;
    for (int i = 6; i >= 1; i--)
    {
        if (i % 2 == 0)
        {
            int cifra = t % 10;
            y += conteo * cifra;
            conteo *= 10;
        }
        t /= 10;
    }

    // Analisis cifra por cifra
    while (x > 0)
    {
        int cifra = x % 10;
        if (cifra > 5)
        {
            sum += cifra;
        }
        x /= 10;
    }

    cout << y << endl
         << sum << endl;

    if (y % sum == 0)
    {
        cout << y << " es multiplo de " << sum;
    }
    else
        cout << y << " no es multiplo de " << sum;

    return 0;
}