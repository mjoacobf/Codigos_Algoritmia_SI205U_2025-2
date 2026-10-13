#include <iostream>

using namespace std;

int main () {

    double sec[3][33][2]={0};
    int cantalumnos[3]={0};

    for (int i=0; i<3; i++) {
        cout << "Ingrese la cantidad de alumnos de la seccion ";
        if (i==0) {
            cout << "U: ";
        }
        if (i==1) {
            cout << "V: ";
        }
        if (i==2) {
            cout << "W: ";
        }
        cin >> cantalumnos[i];

        for (int j=0; j<cantalumnos[i]; j++) {
            
            if (i==0) {
                cout << "Seccion U, alumno " << j+1 << ": " << endl;
            }
            else if (i==1) {
            cout << "Seccion V, alumno " << j+1 << ": " << endl;
            } else {
                cout << "Seccion W, alumno " << j+1 << ": " << endl;
            }
            
            cout << "Ingrese su codigo: ";
            cin >> sec[i][j][0];
            cout << "Ingrese su promedio final: ";
            cin >> sec[i][j][1];
        
        }
    } 

    for (int x=0; x<3; x++) {
        double max1=-1, max2=-1, max3=-1, aux;
        int cod1=-1, cod2=-1, cod3=-1;
        for (int y=0; y<cantalumnos[x]; y++) {
            if (sec[x][y][1]>max1) {
                max3=max2;
                max2=max1;
                max1=sec[x][y][1];
                cod3=cod2;
                cod2=cod1;
                cod1=sec[x][y][0];
            } else if (sec[x][y][1]>max2) {
                max3=max2;
                max2=sec[x][y][1];
                cod3=cod2;
                cod2=sec[x][y][0];
            } else if (sec[x][y][1]>max3) {
                max3=sec[x][y][1];
                cod3=sec[x][y][0];
            }
        }

        if (x==0) {
            cout << "Seccion U: ";
        } 
        if (x==1) {
            cout << "Seccion V: ";
        }
        if (x==2) {
            cout << "Seccion W: ";
        }

        cout << "Puesto 1, codigo " << cod1 << ", nota: " << max1;
        cout << "Puesto 2, codigo " << cod2 << ", nota: " << max2;
        cout << "Puesto 3, codigo " << cod3 << ", nota: " << max3;
    }
}