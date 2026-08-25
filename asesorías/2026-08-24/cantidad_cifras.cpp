// Hallar la cantidad de cifras

#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Ingrese x: ";
    cin >> x;

    int cantCifras = 0;
    while (x > 0)
    {
        cantCifras++;
        x /= 10;
    }

    cout << cantCifras;
}