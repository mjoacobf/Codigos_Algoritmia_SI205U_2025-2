#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int e = 0;
	float sum = 0;
	int n = 0;
	int inferiores = 0;
	do {
		cout<<"Ingrese el numero de notas a ingresar: ";cin>>n;	
	} while (n <= 0);
	int notas[n];
	for (int i = 0; i<n; i++) {
		e = -1;
		do {
			cout<<"Ingrese la nota "<<i+1<<" (0-20): ";cin>>e;
		} while (e < 0 or e > 20);
		notas[i] = e;
		sum += e;
	}
	
	float prom = sum/n;
	
	for (int i = 0; i<n; i++) {
		if (notas[i] < prom) {
			inferiores++;
		}
	}
	
	cout<<inferiores<<" notas son menores que el promedio ("<<prom<<")."<<endl;
}
