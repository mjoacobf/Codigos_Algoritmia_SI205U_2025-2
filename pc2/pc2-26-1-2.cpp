#include <iostream>

using namespace std;

int main () {

    int n;

    do {
        cout << "Ingrese el orden de la matriz (1<N<10): ";
        cin >> n;
    } while (n <= 1 || n >= 10);

    int c[n][n], contfila[n] = {0}, primeruno[n]={11}, indiceoriginal[n], auxnum;
    char etiquetas[n], auxchar;

    for (int i=0; i<n; i++) {
        indiceoriginal[i]=i;
        etiquetas[i]='A'+i;
        for (int j=0; j<n; j++) {
            cout << "Ingrese el valor c[" << i << "][" << j << "]: ";
            cin >> c[i][j];

            if (i==j) {
                c[i][j]=1;
            }

            if (c[i][j]==1) {
                contfila[i]++;
                if (j<primeruno[i]) {
                    primeruno[i]=j;
                }
            }
        }
    }

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1-i; j++) {
            
            bool intercambio=false;
            
            if (contfila[j]<contfila[j+1]) {
                intercambio=true;
            } else if (contfila[j]==contfila[j+1]) {
                if (primeruno[j]>primeruno[j+1]) {
                    intercambio=true;
                } else if (primeruno[j]==primeruno[j+1]) {
                    if (indiceoriginal[j]>indiceoriginal[j+1]) {
                        intercambio=true;
                    }
                }
            }

            if (intercambio) {
                auxnum=contfila[j];
                contfila[j]=contfila[j+1];
                contfila[j+1]=auxnum;

                auxnum=primeruno[j];
                primeruno[j]=primeruno[j+1];
                primeruno[j+1]=auxnum;

                auxnum=indiceoriginal[j];
                indiceoriginal[j]=indiceoriginal[j+1];
                indiceoriginal[j+1]=auxnum;

                auxchar=etiquetas[j];
                etiquetas[j]=etiquetas[j+1];
                etiquetas[j+1]=auxchar;

                for (int k=0; k<n; k++) {
                    auxnum=c[j][k];
                    c[j][k]=c[j+1][k];
                    c[j+1][k]=auxnum;
                }
            }
        }
    }

    int x[n][n];
    cout << "Matriz final:" << endl;
    for (int i=0; i<n; i++) {
        cout << "Fila " << i << ": " << endl;
        for (int j=0; j<n; j++) {
            x[i][j]=c[i][indiceoriginal[j]];

            cout << x[i][j] << " | ";
        }
        cout << endl;
    }

}