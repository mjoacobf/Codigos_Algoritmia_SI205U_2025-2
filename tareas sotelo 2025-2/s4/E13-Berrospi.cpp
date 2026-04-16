#include<iostream>
using namespace std;

int main() {
	int n = -1;
	
	do {
		cout<<"Ingrese la cantidad de elementos del arreglo: ";cin>>n;
	} while (n<=0);
	
	int arreglo[n];
	
	for (int i = 0; i<n; i++) {
		int e;
		cout<<"Ingrese el numero "<<i+1<<": ";cin>>e;
		arreglo[i] = e;
	}
	
	for (int i = 0; i<n-1; i++) {
		if (arreglo[i]>arreglo[i+1]) {
			int t = arreglo[i+1];
			arreglo[i+1] = arreglo[i];
			arreglo[i] = t;
			
			i = 0;
		}
	}
	
	
	cout<<"Los elementos ordenados son: ";
	for (int i = 0; i<n;i++) {
		cout<<arreglo[i]<<" ";
	}
	
	
	
	
	
	
	return 0;
}
