#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {

    srand(time(0));
    int n;
    cout << "Ingrese el numero de numeros aleatorios: ";
    cin >> n;

    int orden=4*n;
    int x[orden];

    for (int i=0; i<orden; i++) {
        x[i]=rand()%10;
        cout << x[i];
    }

    cout << endl;

    for (int i=0; i<10; i++) {
        int distancia=0, suma=0, cont=0;
        
        for (int j=0; j<orden; j++) {
            distancia ++;
            if (x[j]==i) {
                suma=suma+distancia;
                distancia=0;
                cont++;
            }
        }
        
        if (cont!=0) {
            cout << "Promedio del numero " << i << ": " << float(suma)/cont << endl;
        } else {
            cout << "El numero " << i << " no aparece en el arreglo" << endl;
        }
    }

}