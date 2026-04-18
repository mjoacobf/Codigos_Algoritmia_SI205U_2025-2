#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main() {
	srand(time(NULL));
	
	int f, c, n;
	cout<<"Filas: ";cin>>f;
	cout<<"Columnas: ";cin>>c;
	cout<<"Alumnos: ";cin>>n;
	
	int salon[f][c] = {0};
	
	for (int i = 0; i<f;i++) {
		for (int j = 0; j<c; j++) {
			if (n == 0) break;
			salon[i][j] = 10 + rand()%40;
			n--;
		}
	}
	
	cout<<"La distribucion inicial del salon es: "<<endl;
	for (int i = 0; i<f;i++) {
		for (int j = 0; j<c; j++) {
			cout<<salon[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	
	//Intercambio 1
	for (int i = 0; i<f/2;i++) {
		for (int j = 0; j<c; j++) {
			int t = salon[f-i-1][j];
			salon[f-i-1][j] = salon[i][j];
			salon[i][j] = t;
		}
	}
	
	cout<<"La distribucion 30 minutos despues es: "<<endl;
	for (int i = 0; i<f;i++) {
		for (int j = 0; j<c; j++) {
			cout<<salon[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	//Intercambio 2
	for (int i = 0; i<f;i++) {
		for (int j = 0; j<c/2; j++) {
			int t = salon[i][c-j-1];
			salon[i][c-j-1] = salon[i][j];
			salon[i][j] = t;
		}
	}
	
	cout<<"La distribucion 60 minutos despues es: "<<endl;
	for (int i = 0; i<f;i++) {
		for (int j = 0; j<c; j++) {
			cout<<salon[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}