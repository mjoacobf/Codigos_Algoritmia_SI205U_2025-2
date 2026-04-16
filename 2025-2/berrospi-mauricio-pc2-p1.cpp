#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main() {
	srand(time(NULL));
	int x[3][30][9] = {0}; //9 porque uno va a ser el codigo y el resto seran las notas. cuando el codigo sea 0 indica que no existe el alumno (fin de la seccion) o fue eliminado por bajo promedio

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<30; j++) {
			for (int k = 0; k<9; k++) {
				if (k == 0) {
					cout<<endl;
					//int cod;
					//cout<<"Ingrese el codigo de un alumno de la seccion "<<i+1<<" (tres cifras, valor fuera de rango indica fin de seccion): ";cin>>cod;
				
				
					int cod = rand()%1000; //puede generar un valor fuera de rango para terminar la seccion o un valor de 100 a 999
					cout<<"Ingrese el codigo de un alumno de la seccion "<<i+1<<" (tres cifras, valor fuera de rango indica fin de seccion): ";cout<<cod<<endl;
					if (cod < 100 or cod>999) {
						k = 9;
						j = 30;
					} else {
						x[i][j][0] = cod;
					}
				} else {
					//int nota;
					//cout<<"Ingrese la nota "<<k<<" del alumno "<<x[i][j][0]<<" de la seccion "<<i+1<<" (0-20, fuera de rango indica NSP): ";cin>>nota;
				
				
					int nota = rand()%31; //para que puedan haber valores fuera de rango que indiquen que no se presento
					cout<<"Ingrese la nota "<<k<<" del alumno "<<x[i][j][0]<<" de la seccion "<<i+1<<" (0-20, fuera de rango indica NSP): ";cout<<nota<<endl;
					if (nota < 0 or nota > 20) {
						x[i][j][k] = 0;
					} else {
						x[i][j][k] = nota;
					}
				}
			}
		}
	}
	
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<30; j++) {
			if (x[i][j][0] != 0) {
				int s = 0;
				for (int k = 1; k<9; k++) {
					s+=x[i][j][k];
				}
				
				float prom = s*1.0/8;
				
				if (prom < 6.0) { //eliminacion:
					for (int j2 = j; j2<29; j2++) {
						for (int k = 0; k<9; k++) {
							x[i][j2][k] = x[i][j2+1][k];
						}
					}
					j--;
				}
			}
		}
	}
	
	//imprimir
	cout<<"Luego de la eliminacion, se tiene: "<<endl;
	for (int i = 0; i<3; i++) {
		cout<<"Seccion "<<i+1<<": "<<endl;
		for (int j = 0; j<30; j++) {
			if (x[i][j][0] != 0) {
				cout<<"Alumno "<<x[i][j][0]<<": ";
				int s = 0;
				for (int k = 1; k<9; k++) {
					s+=x[i][j][k];
					cout<<x[i][j][k]<<" ";
					
				}
				cout<<", promedio: "<<s*1.0/8;
				cout<<endl;
			} else j = 30; //como ya encontro un codigo inexistente (0), simplemente va a considerar que termino la seccion
		}
		cout<<endl;
	}
	
	
	
	
	
	
	return 0;
}
