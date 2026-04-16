#include<iostream>
using namespace std;

int main() {
	
	float sum = 0;
	int n = 0;
	
	do {
		cout<<"Ingrese la cantidad de notas a analizar: ";cin>>n;
	} while (n <= 0);
	
	int notas[n];
	
	for (int i = 0; i<n; i++) {
		int e = -1;
		do {
			cout<<"Ingrese la nota "<<i+1<<" (0-20): "; cin>>e;	
		} while (e < 0 or e > 20);
		
		notas[i] = e;
		sum += e;
	}
	
	float prom = sum/n;
	cout<<"Promedio: "<<prom<<endl;
	cout<<"Notas: "<<notas[0];
	for (int i = 1; i<n; i++) {
		cout<<", "<<notas[i];
	}
	cout<<endl;
	
	for (int i = 0; i<n; i++) {
		if (notas[i]<prom) {
			for (int j = i; j<n; j++) {
				notas[j] = notas[j+1];
			}
			
			n--;
			i = -1;
			
		}
	}
	
	cout<<"Nuevas notas: "<<notas[0];
	for (int i = 1; i<n; i++) {
		cout<<", "<<notas[i];
	}
	cout<<endl;
	
	
	return 0;
}
