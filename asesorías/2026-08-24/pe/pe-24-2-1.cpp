/*
Desarrolle un programa en C++ que solicite ingresar tres números positivos
para que sean ordenados de menor a mayor. Debe solicitarse ingresar los
números hasta que el usuario decida, además debe comprobarse que el
número ingresado debe ser positivo de no ser así debe solicitar otro.
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    do
    {
        cout << "Ingrese el primer numero: ";
        cin >> a;
    } while (a <= 0);

    do
    {
        cout << "Ingrese el segundo numero: ";
        cin >> b;
    } while (b <= 0);

    do
    {
        cout << "Ingrese el tercer numero: ";
        cin >> c;
    } while (c <= 0);

    while (!(a <= b and b <= c))
    {
        if (a > b)
        {
            // algoritmo para intercambiar valores
            int t = a;
            a = b;
            b = t;
        }
        else if (b > c)
        {
            int t = b;
            b = c;
            c = t;
        }
    }

    cout << a << " " << b << " " << c;
}