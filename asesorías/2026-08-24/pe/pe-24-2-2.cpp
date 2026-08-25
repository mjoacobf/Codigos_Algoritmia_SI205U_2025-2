/*Desarrolla un programa en C++ que calcule el promedio de un conjunto de
números positivos ingresados por el usuario. El programa debe detenerse
cuando el usuario ingrese un número negativo.*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int suma = 0;

    int numero;
    do
    {
        cin >> numero;
        if (numero < 0)
            break;
        suma += numero; // suma = suma + numero
        n++;
    } while (numero >= 0);

    float promedio = suma * 1.0 / n;

    cout << promedio;
}