#include<iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int mayor = -1;
	int cantidad = 0;
	int numero = 0;
	
	for (int i = 1; i<=n;i++) {
		int entrada;
		cout<<"Nota "<<i<<": ";cin>>entrada;
		
		if (entrada>mayor) {
			mayor = entrada;
			cantidad = 1;
			numero = i;
		} else if (entrada == mayor) {
			cantidad++;
			
			
			int cantCifras = 0;
			int t = i;
			while (t>0) {
				cantCifras++;
				t/=10;
			}
			
			for (int j = 1; j<=cantCifras; j++) numero*=10;
			numero+=i;
		}
	}
	
	cout<<"Mayor nota: "<<mayor<<endl;
	cout<<"Numero de veces que ocurre: "<<cantidad<<endl;
	cout<<"Numero formado por sus ubicaciones: "<<numero;
	
	return 0;
}

/*
14
16
12
7
18
9
13
18
5
12
9
18
5
16
12

*/