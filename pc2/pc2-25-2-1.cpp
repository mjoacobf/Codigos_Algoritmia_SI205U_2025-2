#include <iostream>

using namespace std;

int main () {

    int bandera[3][30][11]={{0}};
    int cantalumnos[3]={0};

    for (int i=0; i<3; i++) {
        cout << "--Seccion " << i+1 << "--" << endl;
        
        do {
            cout << "Ingrese la cantidad de alumnos de la seccion " << i+1 << ": ";
            cin >> cantalumnos[i];
        } while (cantalumnos[i]<=0 || cantalumnos[i]>30);

        for (int j=0; j<cantalumnos[i]; j++) {
            do {
                cout << "Ingrese el codigo del alumno " << j+1 << " (3 digitos): ";
                cin >> bandera[i][j][0];
            } while (bandera[i][j][0]<100 || bandera[i][j][0]>999);

            do {
                cout << "Ingrese la cantidad de notas a ingresar: ";
                cin >> bandera[i][j][9];
            } while (bandera[i][j][9]<=0 || bandera[i][j][9]>8);

            for (int k=1; k<=bandera[i][j][9]; k++) {
                do {
                    cout << "Ingrese la nota " << k << " (0-20): ";
                    cin >> bandera[i][j][k];
                } while (bandera[i][j][k]<0 || bandera[i][j][k]>20);
                bandera[i][j][10]=bandera[i][j][10]+bandera[i][j][k];
            }
        }
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<cantalumnos[i]; j++) {
            if (bandera[i][j][10]<6*bandera[i][j][9]) {
                for (int x=j; x<cantalumnos[i]-1; x++) {
                    for (int y=0; y<11; y++) {
                        bandera[i][x][y]=bandera[i][x+1][y];
                    }
                }
                cantalumnos[i]--;
                j--;
            } 
        }
    }

    for (int i=0; i<3; i++) {
        cout << "Resultados de la seccion " << i+1 << ":" << endl;
        for (int j=0; j<cantalumnos[i]; j++) {
            cout << "Alumno " << j+1 << ", codigo: " << bandera[i][j][0] << endl;
            cout << "Notas: ";
            for (int k=1; k<=bandera[i][j][9]; k++) {
                cout << bandera[i][j][k] << " | ";
            } cout << endl;
            cout << "Promedio final: " << double(bandera[i][j][10])/bandera[i][j][9] << endl;
        }
    }
}