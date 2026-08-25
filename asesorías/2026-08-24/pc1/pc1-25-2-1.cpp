/*
Diseñe un programa que permita leer un número enteros positivo cuyo número de cifras es mayor a 3. Luego
el programa debe presentar la mediana de los dígitos de dicho número.
*/

/*
    ARTIFICIO: REDONDEAR UN NUMERO:
    int a, b;
    float prom = (a+b)*0.5; //3.5

    float t = prom + 0.5;

    int redondeado = t;


    prom: 3.5 => t = 4.0 => redondeado = 4
    prom: 4.0 => t = 4.5 => redondeado = 4
    prom: 3.7 => t = 4.2 => redondeado = 4
    prom: 4.2 => t = 4.7 => redondeado = 4

*/

#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "ingrese x: ";
    cin >> x;

    int cantidadCifras = 0;
    // 4567071
    // ordenamiento
    int ordenado = 0;
    for (int i = 0; i <= 9; i++)
    {
        int t = x;
        while (t > 0)
        {
            int cifra = t % 10;
            if (cifra == i)
            {
                ordenado *= 10;
                ordenado += cifra;
                cantidadCifras++;
            }

            t /= 10;
        }
    }

    // 0145677 => 145677

    // 6 cif:
    // 123488

    // 2 cif:
    // 12

    //(cantidadCifras/2)-1

    int mediana = 0;

    if (cantidadCifras % 2 == 1)
    {
        for (int _ = 1; _ <= cantidadCifras / 2; _++)
            ordenado /= 10;
        mediana = ordenado % 10;
    }
    else
    {
        for (int _ = 1; _ <= (cantidadCifras / 2) - 1; _++)
            ordenado /= 10;
        int a = ordenado % 10;
        ordenado /= 10;
        int b = ordenado % 10;

        float prom = (a + b) * 0.5;
        float t = prom + 0.5;
        mediana = t;
    }

    cout << mediana;
    return 0;
}