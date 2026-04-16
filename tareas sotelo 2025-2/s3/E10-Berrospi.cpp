#include<iostream>
using namespace std;

int main() {
	int n = 0;
	int frecuencia[10];
	for (int i = 0; i<10; i++) {
		frecuencia[i] = 0;
	}
	int digitosdiferentes = 0;
	
	do {
		cout<<"Ingrese un numero entero positivo: ";cin>>n;
	} while (n<= 0);
	
	while (n>0) {
		int digito = n%10;
		frecuencia[digito]++;
		n/=10;
	}
	
	for (int i = 0; i<10;i++) {
		if (frecuencia[i] > 0) {
			digitosdiferentes++;
			cout<<"La cifra "<<i<<" se repite "<<frecuencia[i]<<" veces."<<endl;
		}
	}
	
	cout<<"Se tienen "<<digitosdiferentes<<" digitos diferentes en total.";
}
