#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Ingrese a: ";
    cin >> a;
    cout << "Ingrese b:";
    cin >> b;

    // 364798, 427

    int copiaA = a;
    int nuevoA = 0;
    int conteo = 1;

    while (copiaA > 0)
    {
        int digito = copiaA % 10;
        bool comun = false;

        int copiaB = b;
        while (copiaB > 0)
        {
            if (copiaB % 10 == digito)
            {
                comun = true;
                break;
            }

            copiaB /= 10;
        }

        if (!comun)
        {
            nuevoA += conteo * digito;
            conteo *= 10;
        }

        copiaA /= 10;
    }

    cout << nuevoA;

    return 0;
}

/*
364798
427


3764972
1675
*/