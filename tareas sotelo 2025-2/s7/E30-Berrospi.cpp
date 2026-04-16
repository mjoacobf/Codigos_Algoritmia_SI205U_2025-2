#include<iostream>
#include<string>

using namespace std;

int main() {	
	int n = 0;
	
	do {
		cout<<"Ingrese el numero de ciudades: ";cin>>n;
	} while (n<=0);
	getchar();
	struct temperatura {
		string nombre;
		int dif;
	} lista[n], raux;
	
	
	for (int i = 0; i<n; i++) {
		cout<<"Ingrese el nombre de la ciudad "<<i+1<<": ";getline(cin, lista[i].nombre);
		
		int a;
		int b = 99999;
		cout<<"Ingrese la temperatura maxima: ";cin>>a;
		
		do {
			cout<<"Ingrese la temperatura minima: ";cin>>b;
		} while (b > a);
		getchar();
		lista[i].dif = a-b;
	}
	
	for (int i = 0; i<n; i++) {
		for (int j = n-1; j>i; j--) {
			if (lista[i].dif < lista[j].dif) {
				raux = lista[j];
				lista[j] = lista[i];
				lista[i] = raux;
			}
		}
	}
	
	for (int i = 0; i<n; i++) {
		cout<<lista[i].nombre<<"\t\t"<<lista[i].dif<<endl;
	}
	
	return 0;
}
