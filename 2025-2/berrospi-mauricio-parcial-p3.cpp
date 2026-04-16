#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main() {
	srand(time(NULL));
	
	int m = 0;
	int n = 0;
	int p = 0;
	
	do {
		cout<<"Ingrese el numero de jugadores: ";cin>>m;
	} while (m<=0);
	do {
		cout<<"Ingrese el numero de rondas: ";cin>>n;
	} while (n<=0);
	do {
		cout<<"Ingrese el numero de juegos: "; cin>>p;
	} while (p<=0);
	
	int Puntaje[m][n][p];
	
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			for (int k = 0; k<p; k++) {
				Puntaje[i][j][k] = rand()%21;
			}
		}
	}
	
	cout<<"Puntajes: "<<endl;
	
	for (int i = 0; i<m; i++) {
		cout<<"m = "<<i<<endl;
		for (int j = 0; j<n; j++) {
			for (int k = 0; k<p; k++) {
				cout<<Puntaje[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	//Promedio de cada jugador
	int puntajestotales[m];
	float promedio[m];
	
	int sumatotal = 0;
	
	for (int i = 0; i<m; i++) {
		int s = 0;
		for (int j = 0; j<n; j++) {
			for (int k = 0; k<p; k++) {
				s+=Puntaje[i][j][k];
			}
		}
		puntajestotales[i] = s;
		sumatotal+=s;
		promedio[i] = s*1.0/(n*p); //dado que n*p es la cantidad de partidas que jugo en total
	}
	
	
	float media = sumatotal*1.0/(m*n*p); //dado que m son los jugadores que jugaron n*p partidas
	
	cout<<"Lista de puntajes promedio: "<<endl<<"m\tPuntaje promedio"<<endl;;
	
	for (int i = 0; i<m; i++) {
		cout<<i<<"\t"<<promedio[i]<<endl;
	}
	
	cout<<"Suma total de puntajes: "<<sumatotal<<endl;
	cout<<"Promedio general: "<<media<<endl;
	
	//Determinacion del jugador mas promedio
	float menordif = 21; //nunca será 21 la diferencia, buena forma para empezar la comparativa
	int indicemenor = 0;
	for (int i = 0; i<m; i++) {
		float dif = promedio[i] - media;
		if (dif < 0) dif*=-1;
		
		if (dif < menordif) {
			indicemenor = i;
			menordif = dif;
		}
	}
	
	cout<<"Jugador promedio: m = "<<indicemenor<<", con un puntaje total de "<<puntajestotales[indicemenor]<<" y un promedio de "<<promedio[indicemenor]<<endl;
	int e = -1;
	do {
		cout<<"Ingrese el indice del jugador a consultar por el puntaje total: ";cin>>e;
	} while (e<0 or e>=m);
	
	cout<<"El jugador m = "<<e<<" tiene un puntaje total de "<<puntajestotales[e]<<endl;
	
	return 0;
	
}
