#include<iostream>

using namespace std;

int main() {
	
	int n = 0;
	
	do {
		cout<<"Ingrese la cantidad de notas a analizar (ordenadas): ";cin>>n;
	} while (n <= 0);
	
	int notas[n+1];
	
	for (int i = 0; i<n; i++) {
		int e = -1;
		do {
			cout<<"Ingrese la nota "<<i+1<<" (0-20): "; cin>>e;	
		} while (e < 0 or e > 20);
		
		notas[i] = e;
	}
	
	cout<<"Notas: "<<notas[0];
	for (int i = 1; i<n; i++) {
		cout<<", "<<notas[i];
	}
	cout<<endl;
	
	int nueva = -1;
	do {
		cout<<"Ingrese la nota a agregar en el arreglo (0-20): ";cin>>nueva;
	} while (nueva < 0 or nueva > 20);
	notas[n] = nueva;
	for (int i = 0; i<n; i++) {
		if (notas[i]>nueva) {
			for (int j = n; j>i; j--) {
				notas[j] = notas[j-1];
			}
			notas[i] = nueva;
			break;
		}
		
	}
	
	cout<<"Nuevas notas: "<<notas[0];
	for (int i = 1; i<n+1; i++) {
		cout<<", "<<notas[i];
	}
	cout<<endl;
	
	
	return 0;
}
