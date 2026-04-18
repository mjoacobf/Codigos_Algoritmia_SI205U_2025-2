//PC3 25-1 2

#include<iostream>
using namespace std;

float hallarSuma(char x[]) {
	int i = 0;
	float suma = 0.0;
	while (x[i]!='\0') {
		while (x[i]!='\0' and !((x[i]>='0' and x[i]<='9') or x[i]=='.' or x[i]==',')) i++;
		
		float numero = 0.0;
		
		while (x[i]!='\0' and x[i]>='0' and x[i]<='9') {
			int cifra = x[i]-'0';
			numero*=10;
			numero+=cifra;
			i++;
		}
		
		if (x[i]!='\0' and (x[i]==',' or x[i]=='.')) {
			float exponente = 1;
			i++;
			while (x[i]!='\0' and x[i]>='0' and x[i]<='9') {
				int cifra = x[i]-'0';
				exponente*=0.1;
				cifra*=exponente;
				numero+=cifra;
				i++;
			}
		}
		i++;
		suma+=numero;
	}
	
	return suma;
}

int main() {
	char x[200];
	cin.getline(x,200);
	
	int i = 0;
	float suma = 0.0;
	
	int cantidadEnteros = 0;
	int cantidadReales = 0;
	
	while (x[i]!='\0') {
		while (x[i]!='\0' and !((x[i]>='0' and x[i]<='9') or x[i]=='.' or x[i]==',')) i++;
		
		float numero = 0.0;
		int tipo = 0; //0 si no existe, 1 es entero, 2 si es real
		
		while (x[i]!='\0' and x[i]>='0' and x[i]<='9') {
			tipo = 1;
			float cifra = (x[i]-'0')*1.0;
			numero*=10;
			numero+=cifra;
			i++;
		}
		
		if (x[i]!='\0' and (x[i]==',' or x[i]=='.')) {
			float exponente = 1;
			i++;
			while (x[i]!='\0' and x[i]>='0' and x[i]<='9') {
				tipo = 2;
				float cifra = (x[i]-'0')*1.0;
				exponente*=0.1;
				cifra*=exponente;
				numero+=cifra;
				i++;
			}
		}
		
		if (tipo == 1) cantidadEnteros++;
		if (tipo == 2) cantidadReales++;
		
		i++;
		suma+=numero;
	}
	
	cout<<suma<<endl;
	cout<<"Cantidad de enteros: "<<cantidadEnteros<<endl;
	cout<<"Cantidad de reales: "<<cantidadReales<<endl;
	
	return 0;
}