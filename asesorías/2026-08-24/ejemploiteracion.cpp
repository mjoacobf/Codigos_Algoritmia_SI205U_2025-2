// Recibir n numeros enteros y determinar el maximo valor par
// y el minimo impar. NO USAR ARREGLOS, LIBRERIAS NI FUNCIONES.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Ingrese n: ";
    cin >> n;

    int maximopar = -1;
    int minimoimpar = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Ingrese el numero: ";
        cin >> x;
        if (x % 2 == 0)
        {
            if (maximopar == -1)
                maximopar = x;
            else if (x > maximopar)
                maximopar = x;
        }
        else
        {
            if (minimoimpar == 0)
                minimoimpar = x;
            else if (x < minimoimpar)
                minimoimpar = x;
        }
    }

    if (maximopar == -1)
    {
        cout << "No se ingreso ningun valor par." << endl;
    }
    else
        cout << "Maximo valor par: " << maximopar << endl;
    if (minimoimpar == 0)
    {
        cout << "No se ingreso ningun valor impar." << endl;
    }
    else
        cout << "Minimo vavlor impar: " << minimoimpar << endl;

    return 0;
}