/*
Crear un programa que permita recibir dos números en base 2, de tres cifras cada uno, y luego sin realizar la
conversión a base 10 y si emplear arreglos nos presente el producto de dichos números en el sistema binario.
Ejemplo:
Si lo números ingresados son 111 y 101
Entonces el producto es 100011
*/

#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Ingrese el primer numero binario: ";
    cin >> num1; // 101 110 001 000 111
    cout << "Ingrese el segundo numero binario: ";
    cin >> num2;

    int b0 = num2 % 10;
    int b1 = (num2 / 10) % 10;
    int b2 = (num2 / 100) % 10;

    int pp0 = b0 * num1;
    int pp1 = b1 * num1 * 10;
    int pp2 = b2 * num1 * 100;

    int r = 0;
    int lleva = 0;
    int pos = 1;

    while (pp0 > 0 || pp1 > 0 || pp2 > 0 || lleva > 0)
    {
        int dig0 = pp0 % 10;
        int dig1 = pp1 % 10;
        int dig2 = pp2 % 10;

        int suma = dig0 + dig1 + dig2 + lleva;
        int digito = suma % 2;
        lleva = suma / 2;

        r += digito * pos;
        pos *= 10;

        pp0 /= 10;
        pp1 /= 10;
        pp2 /= 10;
    }

    cout << r;
    return 0;
}