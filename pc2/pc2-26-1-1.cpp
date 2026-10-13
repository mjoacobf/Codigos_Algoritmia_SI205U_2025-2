#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {

    srand(time(0));

    int n;

    do {
        cout << "Ingrese el orden (par) de la matriz: ";
        cin >> n;
    } while (n%2!=0);

    int x[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            x[i][j]=rand()%100;
        }
    }

    int B[n][n];

    //Analizamos por cada anillo que va desde desde la fila 0 hasta (n/2)-1
    for (int anillo=0; anillo<n/2; anillo++) {
        
        /*Vemos los limites a analizar en una fila/columna, por ejemplo, n=4,
        anillo=0: inicio=0 y final=3, en la fila superior añadimos los valores
        desde B[0][1] hasta B[0][3], en la columna derecha añadimos los valores 
        desde B[1][3] hasta B[3][3], en la fila inferior añadimos los valores
        desde B[3][0] hasta B[3][2], en la columna izquierda añadimos los valores
        desde B[0][0] hasta B[2][0], y luego asi para el siguiente anillo=1*/
        int inicio=anillo, final=n-anillo-1;

        for (int j=inicio; j<final; j++) {
            //Añade los valores de B de la fila superior de la capa (→)
            B[inicio][j+1]=x[inicio][j];
            //Añade los valores de B de la columna derecha de la capa (↓)
            B[j+1][final]=x[j][final];
            //Añade los valores B de la fila inferior de la capa (←)
            B[final][j]=x[final][j+1];
            //Añade los valores B de la columna izquierda de la capa (↑)
            B[j][inicio]=x[j+1][inicio];
        }
    }

    cout << "Matriz x:" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << x[i][j] << " | "; 
        }
        cout << endl;
    }

    cout << "Matriz B:" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << B[i][j] << " | "; 
        }
        cout << endl;
    }
}