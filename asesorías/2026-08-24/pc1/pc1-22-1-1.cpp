/*
Diseñe un programa C++, que permita leer un número entero positivo cuyo número de cifras es mayor a 4. Luego
el programa debe modificar el número de tal forma que sus dígitos queden en forma decreciente.
*/

#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "ingrese x: ";
    cin >> x;

    // 4567602 => 7665420

    int res = 0;

    for (int i = 9; i >= 0; i--)
    {
        // buscar si esta la cifra y replicarla
        int t = x;
        while (t > 0)
        {
            int cifra = t % 10;
            if (cifra == i)
            {
                res *= 10;
                res += cifra;
            }
            t /= 10;
        }
    }

    cout << res;

    return 0;
}