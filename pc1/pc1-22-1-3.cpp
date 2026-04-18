#include<iostream>
using namespace std;

int main() {
	int n;
	cout<<"Ingrese la cantidad de numeros a analizar: ";cin>>n;
	int resultado = 0;
	//int contador = 1;
	for (int i = 1; i<=n; i++) {
		int entrada;
		cout<<"Ingrese el numero "<<i<<": ";cin>>entrada;
		
		if (i%2==1) {
			int minimoImpar = 10; //10 nunca va a pasar
			int t = entrada;
			while (t>0) {
				int cifra = t%10;
				if (cifra%2==1 and cifra < minimoImpar) {
					minimoImpar = cifra;
				}
				t/=10;
			}
			
			if (minimoImpar != 10) {
				resultado*=10;
				resultado+=minimoImpar;
			}
		} else {
			int maximoPar = -1; //-1 es imposible
			int t = entrada;
			while (t>0) {
				int cifra = t%10;
				if (cifra%2==0 and cifra > maximoPar) {
					maximoPar = cifra;
				}
				t/=10;
			}
			
			if (maximoPar!=-1) {
				resultado*=10;
				resultado+=maximoPar;
			}
		}
		
		
		
	}
	
	cout<<resultado;
	
	return 0;
}

/*
5
5036
1234
22682
361
8075
*/