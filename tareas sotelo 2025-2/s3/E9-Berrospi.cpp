#include<iostream>
using namespace std;

int main(){
	int frecuencia[21];
	for (int i = 0; i<21; i++) {
		frecuencia[i] = 0;
	}
	int n = 0;
	
	do {
		cout<<"Ingrese la cantidad de notas por analizar: ";cin>>n;
	} while (n <= 0);
	
	for (int i = 0; i < n; i++) {
		int nota = -1;
		do {
			cout<<"Ingrese la nota "<<i+1<<" (0-20): ";cin>>nota;
		} while (nota < 0 or nota > 20);
		
		frecuencia[nota]++;
	}
	
	for (int i = 0; i<21; i++) {
		if (frecuencia[i] > 0) {
			cout<<"La nota "<<i<<" se repite "<<frecuencia[i]<<" veces."<<endl;
		}
	}
	return 0;
}
